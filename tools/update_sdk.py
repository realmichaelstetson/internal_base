#!/usr/bin/env python3
"""
Auto-updater for offsets / signatures / SDK headers.

1. Remembers the dump the code currently matches in .sdk_prev/include
2. Runs cs2-sdk.exe (CS2 must be running) and waits until it finishes
3. Compares the previous dump with the new one and updates the project:
   - src/sdk/*_dll.hpp, cs2sdk_macros.hpp       (regenerated from schemas)
   - src/sdk/offsets.hpp/.json, buttons.hpp/.json
   - src/sdk/interfaces_sdk.hpp, vtables.hpp/.json, verified_features.*
   - src/sdk/valve/signatures/signatures.cpp
   - every other file in src/ (features, hooks, ...):
       * hex offsets named like a dump entry  (dwViewAngles = 0x..., m_iHealth = 0x...,
         C_CSPlayerPawn__m_iShotsFired = 0x...)
       * client.dll RVAs that only one dump entry had
       * pattern strings ("48 8B ? ...") that match a pattern from the previous dump
       * lines tagged with a `// @sdk ...` comment (see below)

Tagging hardcoded values (for names the script cannot guess):
    constexpr std::uintptr_t glow_offset = 0xDD8; // @sdk schema:C_BaseModelEntity::m_Glow
    read<vec3_t>(pawn + 0xE70); // @sdk schema:C_BaseModelEntity::m_vecViewOffset
    constexpr auto x = 0x2578160; // @sdk offset:client::dwCSGOInput
    constexpr auto y = 0x2231FD0; // @sdk button:attack
    scan("client.dll", "48 89 5C ..."); // @sdk pattern:client::TraceShape
  schema refs default to client.dll; use schema:server::CBaseEntity::m_iHealth for others.

Usage (from the repo root or anywhere):
    python tools/update_sdk.py              run cs2-sdk.exe and update everything
    python tools/update_sdk.py --skip-dump  only update the code (use the include/ already there)
    python tools/update_sdk.py --dry-run    show what would change, write nothing
"""

import argparse
import json
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / 'src'
SDK = SRC / 'sdk'
CONFIG = Path(__file__).resolve().parent / 'sdk_update_config.json'

# folders / files inside src/ that are never touched by the generic pass
SKIP_PARTS = {'includes'}
SKIP_SUFFIX = ('.pb.cc', '.pb.h')
SOURCE_EXT = {'.cpp', '.hpp', '.h', '.c', '.cc', '.hh', '.inl'}

HEX = re.compile(r'0[xX][0-9A-Fa-f]+')
PATTERN_LIT = re.compile(r'"((?:[0-9A-Fa-f]{2}|\?\??)(?: (?:[0-9A-Fa-f]{2}|\?\??)){3,})"')
SIG_ENTRY = re.compile(r'\{ "([^"]+)", "([^"]+)", "([^"]*)"sv, signature_resolve_kind::(\w+), (-?\d+), (-?\d+) \}')
TAG = re.compile(r'//\s*@sdk\s+(schema|offset|button|pattern):(\S+)')
NAMED_HEX = re.compile(r'\b([A-Za-z_]\w*)\s*(?:=|,)\s*(0[xX][0-9A-Fa-f]+)\b')

report = []


def log(msg):
    report.append(msg)
    print(msg)


def hexs(v):
    return '0x%X' % v


def norm_pattern(p):
    return ' '.join('?' if t in ('?', '??') else t.upper() for t in p.split())


# --------------------------------------------------------------------------- files

class SrcFile:
    """Keeps BOM and line endings exactly as they were."""

    def __init__(self, path):
        self.path = path
        raw = path.read_bytes()
        self.bom = raw.startswith(b'\xef\xbb\xbf')
        self.text = raw[3 if self.bom else 0:].decode('utf-8', errors='surrogateescape')
        self.orig = self.text

    @property
    def changed(self):
        return self.text != self.orig

    def save(self, dry):
        if not self.changed or dry:
            return
        data = self.text.encode('utf-8', errors='surrogateescape')
        self.path.write_bytes((b'\xef\xbb\xbf' if self.bom else b'') + data)


def read_text(path):
    return path.read_text(encoding='utf-8-sig')


def write_file(path, text, dry, bom=None):
    if bom is None:
        bom = path.exists() and path.read_bytes().startswith(b'\xef\xbb\xbf')
    data = ('﻿' if bom else '') + text
    if path.exists() and path.read_text(encoding='utf-8', errors='surrogateescape') == data:
        return False
    if not dry:
        path.write_text(data, encoding='utf-8', newline='')
    return True


# --------------------------------------------------------------------------- dump model

class Dump:
    def __init__(self, root):
        self.root = Path(root)
        if not (self.root / 'offsets' / 'offsets.json').exists():
            raise SystemExit(f'[!] {self.root} does not look like a cs2-sdk include/ folder')
        self.build = self._build()
        self.offsets = {}      # (module, name) -> int      module = 'client', 'engine2', ...
        self.offsets_json = json.loads(read_text(self.root / 'offsets' / 'offsets.json'))
        self.buttons = {}      # name -> int
        self.patterns = {}     # (module, name) -> dict
        self.pattern_alias = {}
        self.schema = {}       # (module, class, field) -> int
        self.bases = {}        # (module, class) -> (module, class)
        self.verified = {}     # (class, field) -> int
        self._load_offsets()
        self._load_buttons()
        self._load_patterns()
        self._load_schemas()
        self._load_verified()

    def _build(self):
        m = re.search(r'CS2_BUILD = (\d+)', read_text(self.root / 'cs2.hpp')) if (self.root / 'cs2.hpp').exists() else None
        if m:
            return int(m.group(1))
        return json.loads(read_text(self.root / 'manifest.json')).get('build_number')

    def _load_offsets(self):
        for mod, vals in self.offsets_json.items():
            for k, v in vals.items():
                self.offsets[(mod[:-4], k)] = int(v, 16)
        hpp = self.root / 'offsets' / 'offsets.hpp'
        if hpp.exists():
            for m in re.finditer(r'namespace (\w+) \{(.*?)\n    \}', read_text(hpp), re.S):
                for n, v in re.findall(r'(\w+) = (0x[0-9A-Fa-f]+);', m.group(2)):
                    self.offsets.setdefault((m.group(1), n), int(v, 16))
        allj = self.root / 'offsets' / 'offsets_all.json'
        if allj.exists():
            for mod, ents in json.loads(read_text(allj))['modules'].items():
                for e in ents:
                    for n in {e['name'], e.get('hpp_name') or e['name']}:
                        self.offsets.setdefault((mod[:-4], n), int(e['rva'], 16))
        self.interfaces = {}
        if allj.exists():
            for mod, ents in json.loads(read_text(allj))['modules'].items():
                self.interfaces[mod[:-4]] = sorted({(e['name'], e['rva']) for e in ents if e['kind'] == 'interface'},
                                                   key=lambda x: (x[0].lower(), x[0]))

    def _load_buttons(self):
        p = self.root / 'buttons.json'
        if p.exists():
            for k, v in json.loads(read_text(p)).get('client.dll', {}).items():
                self.buttons[k] = int(v) if isinstance(v, int) else int(v, 16)

    def _load_patterns(self):
        p = self.root / 'patterns' / 'patterns.json'
        if not p.exists():
            return
        for e in json.loads(read_text(p))['patterns']:
            key = (e['module'][:-4], e['name'])
            self.patterns[key] = e
            for a in e.get('aliases') or []:
                self.pattern_alias.setdefault((e['module'][:-4], a), key)

    def _load_schemas(self):
        files = sorted((self.root / 'schemas').glob('*_dll.hpp'))
        files.sort(key=lambda f: f.name != 'client_dll.hpp')
        for f in files:
            mod = f.name[:-8]
            for cm in re.finditer(r'\n    (?:class|struct) (\w+)([^{\n;]*)\{(.*?)\n    \};', read_text(f), re.S):
                key = (mod, cm.group(1))
                if key in self.bases:
                    continue
                b = re.search(r'public\s+(?:::(\w+)::)?(\w+)', cm.group(2))
                self.bases[key] = ((b.group(1) or mod), b.group(2)) if b else None
                for fm in re.finditer(r'SCHEMA_FIELD\((.*?),\s*(\w+)\s*,\s*(0x[0-9A-Fa-f]+)\)', cm.group(3)):
                    self.schema[(mod, cm.group(1), fm.group(2))] = int(fm.group(3), 16)

    def _load_verified(self):
        p = self.root / 'verified_features.json'
        if not p.exists():
            return

        def walk(o):
            if isinstance(o, dict):
                if {'class', 'field', 'offset'} <= o.keys() and isinstance(o['offset'], str):
                    fld = re.sub(r'\W', '', o['field'].split(' ')[0])
                    try:
                        self.verified.setdefault((o['class'], fld), int(o['offset'], 16))
                    except ValueError:
                        pass
                for v in o.values():
                    walk(v)
            elif isinstance(o, list):
                for v in o:
                    walk(v)
        walk(json.loads(read_text(p)))

    # --- lookups
    def field(self, cls, fld, mod='client'):
        """Schema field with inheritance inside the same module, then verified_features."""
        key, seen = (mod, cls), set()
        while key and key[0] == mod and key not in seen:
            seen.add(key)
            if (key[0], key[1], fld) in self.schema:
                return self.schema[(key[0], key[1], fld)]
            key = self.bases.get(key)
        return self.verified.get((cls, fld))

    def pattern(self, mod, name):
        key = (mod, name)
        if key in self.patterns:
            return self.patterns[key]
        key = self.pattern_alias.get(key)
        return self.patterns.get(key) if key else None


def name_variants(n):
    base = n
    if base.startswith('PointerTo'):
        base = base[len('PointerTo'):]
    for suf in ('FunctionPointer', '_resolved', 'Pointer', 'Function', '_addr', '_ptr', 'Ptr', 'Alt', '_v2'):
        if base.endswith(suf):
            base = base[:-len(suf)]
    out = []
    for b in {n, base, base.rstrip('_')}:
        if not b:
            continue
        out += [b, 'dw' + b, 'p' + b, 'p' + b[0].upper() + b[1:], b[0].upper() + b[1:]]
        if b.startswith('dw'):
            out += [b[2:], 'p' + b[2:]]
    return out


# --------------------------------------------------------------------------- resolver

class Resolver:
    def __init__(self, old, new, config):
        self.old, self.new, self.cfg = old, new, config
        # unique old value -> new value maps for RVAs (client.dll and friends)
        self.rva_map = {}
        multi = {}
        for (mod, n), v in old.offsets.items():
            if (mod, n) in new.offsets:
                multi.setdefault(v, set()).add(new.offsets[(mod, n)])
        for n, v in old.buttons.items():
            if n in new.buttons:
                multi.setdefault(v, set()).add(new.buttons[n])
        for v, s in multi.items():
            # only values that clearly look like an RVA (not masks / flags / small offsets)
            if len(s) == 1 and v >= 0x100000 and v % 4 == 0 and v & 0xFFFF:
                self.rva_map[v] = next(iter(s))
        # old pattern text -> (module, name, variant)
        self.pat_map = {}
        for key, e in old.patterns.items():
            for variant in ('pattern', 'pattern_synth'):
                if e.get(variant):
                    self.pat_map.setdefault(norm_pattern(e[variant]), []).append((key, variant))

    def named_offset(self, name, value):
        """name + old value must agree with the previous dump."""
        for v in name_variants(name):
            for (mod, n), ov in self.old.offsets.items():
                if n == v and ov == value and (mod, n) in self.new.offsets:
                    return self.new.offsets[(mod, n)], f'offset {mod}::{n}'
        if name in self.old.buttons and self.old.buttons[name] == value and name in self.new.buttons:
            return self.new.buttons[name], f'button {name}'
        return None

    def named_field(self, name, value):
        # Class__field or Class__field__extra
        if '__' in name:
            cls, _, rest = name.partition('__')
            fld = rest.split('__')[0]
            for mod in ('client', 'server'):
                ov = self.old.field(cls, fld, mod)
                if ov == value:
                    nv = self.new.field(cls, fld, mod)
                    if nv is not None:
                        return nv, f'schema {cls}::{fld}'
        # bare m_field: every old client class with that field + value must map to one new value
        m = re.search(r'(m_\w+)$', name)
        if m:
            fld = m.group(1)
            outs = set()
            for (mod, cls, f), ov in self.old.schema.items():
                if mod == 'client' and f == fld and ov == value:
                    nv = self.new.field(cls, fld)
                    if nv is not None:
                        outs.add(nv)
            if len(outs) == 1:
                return outs.pop(), f'schema *::{fld}'
        return None

    def tag(self, kind, ref):
        n = self.new
        if kind == 'schema':
            parts = ref.split('::')
            mod = parts[0] if len(parts) == 3 else 'client'
            cls, fld = parts[-2], parts[-1]
            v = n.field(cls, fld, mod)
            return (v, f'schema {cls}::{fld}') if v is not None else None
        if kind == 'offset':
            mod, _, name = ref.rpartition('::')
            for v in name_variants(name):
                for (m, k), val in n.offsets.items():
                    if k == v and (not mod or m == mod.replace('_dll', '').replace('.dll', '')):
                        return val, f'offset {m}::{k}'
            return None
        if kind == 'button':
            return (n.buttons[ref], f'button {ref}') if ref in n.buttons else None
        return None


# --------------------------------------------------------------------------- passes

def first_wild(pat):
    t = pat.split()
    for i in range(len(t) - 3):
        if t[i:i + 4] == ['?'] * 4:
            return i
    return 0


def pattern_matches(pat, data):
    a, b = pat.split(), data.split()
    return all(x == '?' or x == y for x, y in zip(a, b))


def best_new_pattern(e):
    """(pattern, kind) for a dump entry; raw patterns that do not start at the function use the synth one."""
    pat, kind = norm_pattern(e['pattern']), e['resolve']
    if kind == 'raw' and e.get('bytes') and e.get('pattern_synth') and not pattern_matches(pat, norm_pattern(e['bytes'])):
        pat = norm_pattern(e['pattern_synth'])
    return pat, kind


def norm_name(s):
    return re.sub(r'[^a-z0-9]', '', s.lower())


def find_pattern_by_name(dump, mod, name, aliases):
    if name in aliases:
        ref = aliases[name]
        m, _, n = ref.rpartition('::')
        e = dump.pattern((m or mod).replace('.dll', ''), n)
        if e:
            return e
    e = dump.pattern(mod, name)
    if e:
        return e
    want = norm_name(name)
    for (m, n), e in dump.patterns.items():
        if m == mod and norm_name(n) == want:
            return e
    for (m, n), key in dump.pattern_alias.items():
        if m == mod and norm_name(n) == want:
            return dump.patterns[key]
    return None


def update_signatures(f, res, stats):
    old, new, aliases = res.old, res.new, res.cfg.get('signature_aliases', {})

    def repl(m):
        name, mod_dll, pat, kind, ro, eo = m.groups()
        mod = mod_dll[:-4]
        e, npat = None, None
        # 1) same pattern as in the previous dump -> follow that dump entry (same variant)
        for (key, variant) in res.pat_map.get(norm_pattern(pat), []):
            if key[0] == mod or key[1] == name:
                e = new.patterns.get(key)
                if e and e.get(variant):
                    npat = norm_pattern(e[variant])
                    nkind = e['resolve'] if variant == 'pattern' else 'raw'
                    if variant == 'pattern' and nkind != res.old.patterns[key]['resolve'] and e.get('pattern_synth') \
                            and res.old.patterns[key]['resolve'] == 'raw':
                        npat, nkind = norm_pattern(e['pattern_synth']), 'raw'
                    break
                e = None
        # 2) by name / alias
        if e is None:
            e = find_pattern_by_name(new, mod, name, aliases)
            if e and name in aliases:
                mod_dll = e['module']
        if e is None:
            stats['sig_missing'].append(f'{mod_dll}!{name}')
            return m.group(0)
        if npat is None:
            npat, nkind = best_new_pattern(e)
        nro = 0 if nkind == 'raw' else first_wild(npat)
        out = f'{{ "{name}", "{mod_dll}", "{npat}"sv, signature_resolve_kind::{nkind}, {nro}, {eo if nkind == kind else 0} }}'
        if out != m.group(0):
            stats['sig_updated'].append(f'{mod_dll}!{name} -> {e["name"]}')
        return out

    f.text = SIG_ENTRY.sub(repl, f.text)


def generic_pass(f, res, stats, is_generated_sdk):
    lines = f.text.split('\n')
    for i, line in enumerate(lines):
        rel = f'{f.path.relative_to(REPO).as_posix()}:{i + 1}'
        t = TAG.search(line)
        if t:
            kind, ref = t.groups()
            code = line[:t.start()]
            if kind == 'pattern':
                mod, _, name = ref.rpartition('::')
                e = res.new.pattern((mod or 'client').replace('.dll', '').replace('_dll', ''), name)
                pm = PATTERN_LIT.search(code)
                if not e or not pm:
                    stats['tag_failed'].append(f'{rel} @sdk {kind}:{ref}')
                    continue
                npat, nkind = best_new_pattern(e)
                if nkind != 'raw':
                    if e.get('pattern_synth'):
                        npat = norm_pattern(e['pattern_synth'])
                    else:
                        stats['tag_failed'].append(f'{rel} @sdk {kind}:{ref} (dump pattern is {nkind}, not a function start)')
                        continue
                if norm_pattern(pm.group(1)) != npat:
                    code = code[:pm.start(1)] + npat + code[pm.end(1):]
                    stats['tagged'].append(f'{rel} {ref}')
                lines[i] = code + line[t.start():]
                continue
            r = res.tag(kind, ref)
            hm = HEX.search(code)
            if not r or not hm:
                stats['tag_failed'].append(f'{rel} @sdk {kind}:{ref}')
                continue
            if int(hm.group(0), 16) != r[0]:
                code = code[:hm.start()] + hexs(r[0]) + code[hm.end():]
                stats['tagged'].append(f'{rel} {ref} -> {hexs(r[0])}')
            lines[i] = code + line[t.start():]
            continue

        if line.lstrip().startswith('//'):
            continue

        # pattern literals outside signatures.cpp entries
        if 'signature_resolve_kind::' not in line:
            def prepl(m):
                cands = res.pat_map.get(norm_pattern(m.group(1)))
                if not cands:
                    return m.group(0)
                keys = {k for k, _ in cands}
                if len(keys) != 1:
                    return m.group(0)
                key, variant = cands[0]
                e = res.new.patterns.get(key)
                if not e or not e.get(variant):
                    stats['pat_lost'].append(f'{rel} {key[1]}')
                    return m.group(0)
                if e['resolve'] != res.old.patterns[key]['resolve'] and variant == 'pattern':
                    if e.get('pattern_synth') and res.old.patterns[key]['resolve'] == 'raw':
                        variant = 'pattern_synth'
                    else:
                        stats['pat_lost'].append(f'{rel} {key[1]} (resolve kind changed)')
                        return m.group(0)
                npat = norm_pattern(e[variant])
                if npat != norm_pattern(m.group(1)):
                    stats['pat_updated'].append(f'{rel} {key[1]}')
                    return f'"{npat}"'
                return m.group(0)
            line = PATTERN_LIT.sub(prepl, line)

        # named hex constants
        def hrepl(m):
            name, lit = m.group(1), m.group(2)
            val = int(lit, 16)
            r = res.named_offset(name, val) or res.named_field(name, val)
            if r is None and val in res.rva_map and not is_generated_sdk:
                r = (res.rva_map[val], 'rva')
            if r is None or r[0] == val:
                return m.group(0)
            stats['hex'].append(f'{rel} {name}: {lit} -> {hexs(r[0])} ({r[1]})')
            return m.group(0)[:m.start(2) - m.start(0)] + hexs(r[0])
        line = NAMED_HEX.sub(hrepl, line)

        # bare RVAs, e.g. client_base + 0x2578160
        if not is_generated_sdk:
            def rrepl(m):
                val = int(m.group(0), 16)
                if val in res.rva_map and res.rva_map[val] != val:
                    stats['hex'].append(f'{rel} {m.group(0)} -> {hexs(res.rva_map[val])} (rva)')
                    return hexs(res.rva_map[val])
                return m.group(0)
            line = re.sub(r'(?<=\+ )0[xX][0-9A-Fa-f]{6,}\b', rrepl, line)
        lines[i] = line
    f.text = '\n'.join(lines)


# --------------------------------------------------------------------------- generated sdk files

def regen_schemas(new, dry):
    mods = sorted(p.name[:-8] for p in (new.root / 'schemas').glob('*_dll.hpp'))

    def fix(text):
        text = re.sub(r'(?<![\w:])::sdk::', '::cs2::sdk::', text)
        text = re.sub(r'(?<![\w:])::(' + '|'.join(mods) + r')::', r'::cs2::sdk::\1::', text)
        return re.sub(r'^namespace (' + '|'.join(mods + ['sdk']) + r') \{',
                      lambda m: 'namespace cs2::sdk {' if m.group(1) == 'sdk' else f'namespace cs2::sdk::{m.group(1)} {{',
                      text, flags=re.M)

    changed = []
    if write_file(SDK / 'cs2sdk_macros.hpp', fix(read_text(new.root / 'macros.hpp')), dry, bom=True):
        changed.append('cs2sdk_macros.hpp')
    for m in mods:
        t = read_text(new.root / 'schemas' / f'{m}_dll.hpp').replace('#include "../macros.hpp"', '#include "cs2sdk_macros.hpp"')
        t = fix(t)
        if m == 'client':
            t = t.replace('namespace cs2::sdk::client {\n', f'namespace cs2::sdk::client {{\n\n    inline constexpr std::uint32_t CS2_BUILD = {new.build};\n', 1)
        if write_file(SDK / f'{m}_dll.hpp', t, dry, bom=False):
            changed.append(f'{m}_dll.hpp')
    return changed


def regen_interfaces(new, dry):
    path = SDK / 'interfaces_sdk.hpp'
    old_text = read_text(path) if path.exists() else ''
    old_mods = {}
    for m in re.finditer(r'namespace (\w+)_dll \{(.*?)\n    \}', old_text, re.S):
        old_mods[m.group(1)] = re.findall(r'void\* (\w+)\(std::uintptr_t module_base\) noexcept \{ return reinterpret_cast<void\*>\(module_base \+ (0x[0-9A-Fa-f]+)\); \}', m.group(2))
    mods = dict(new.interfaces)
    for k, v in old_mods.items():
        if k not in mods or not mods[k]:
            mods[k] = v       # module not in the dump (steamclient64, vstdlib) -> keep
    L = ['', '#pragma once', '', '#include <cstdint>', '',
         f'namespace cs2::ifaces {{ inline constexpr std::uint32_t CS2_BUILD = {new.build}; }}', '', 'namespace cs2::ifaces {', '']
    for k in sorted(mods):
        if not mods[k]:
            continue
        L.append(f'    namespace {k}_dll {{')
        for n, rva in mods[k]:
            L.append(f'        inline void* {n}(std::uintptr_t module_base) noexcept {{ return reinterpret_cast<void*>(module_base + {rva}); }}')
        L += ['    }', '']
    L.append('}')
    return write_file(path, '\n'.join(L) + '\n', dry, bom=True)


def regen_vtables(new, dry):
    src = new.root / 'interfaces' / 'vtables.json'
    if not src.exists():
        return False
    newv = json.loads(read_text(src))['modules']
    jpath = SDK / 'vtables.json'
    old = json.loads(read_text(jpath)) if jpath.exists() else {}

    def norm(s):
        return re.sub(r'[^a-z0-9]', '', s.split('::')[-1].lower())

    out = {}
    for mod in list(newv) + [m for m in old if m not in newv]:
        if mod not in newv:
            out[mod] = old[mod]
            continue
        out[mod] = {}
        for iface, info in newv[mod].items():
            methods = [{'index': x['index'], 'module': x['module'], 'name': x['name'] or f"method_{x['index']}",
                        'rva': hexs(x['rva'])} for x in info['methods']]
            by_idx = {x['index']: x for x in methods}
            old_named = [om for om in old.get(mod, {}).get(iface, {}).get('methods', []) if not om['name'].startswith('method_')]
            taken = {norm(om['name']) for om in old_named}
            for om in old_named:
                same = [x for x in methods if norm(x['name']) == norm(om['name'])]
                if same:
                    same[0]['name'] = om['name']      # keep the project's spelling
                    continue
                hit = [x for x in methods if not x['name'].startswith('method_') and norm(x['name']) not in taken
                       and (norm(x['name']) in norm(om['name']) or norm(om['name']) in norm(x['name']))]
                if hit:
                    hit[0]['name'] = om['name']
                elif om['index'] in by_idx and by_idx[om['index']]['name'].startswith('method_'):
                    by_idx[om['index']]['name'] = om['name']
            out[mod][iface] = {'method_count': len(methods), 'methods': methods, 'rtti_class': info['rtti_class'],
                               'vtable_module': info['vtable_module'], 'vtable_rva': hexs(info['vtable_rva'])}
    c1 = write_file(jpath, json.dumps(out, indent=2) + '\n', dry, bom=False)

    L = ['', '', '#pragma once', '#include <cstddef>', '#include <cstdint>', '',
         f'namespace cs2::vtables {{ inline constexpr std::uint32_t CS2_BUILD = {new.build}; }}', '', 'namespace cs2::vtables {', '']
    for mod, ifaces in out.items():
        L += [f'    namespace {mod.replace(".dll", "_dll")} {{', '']
        for info in ifaces.values():
            L.append(f'        namespace {info["rtti_class"]} {{')
            for x in info['methods']:
                L.append(f'            inline constexpr std::ptrdiff_t {x["name"].replace("::", "__"):<48} = {x["index"]:>4};')
            L += ['        }', '']
        L += ['    }', '']
    L.append('}')
    c2 = write_file(SDK / 'vtables.hpp', '\n'.join(L) + '\n', dry, bom=True)
    return c1 or c2


def regen_dumper_offsets(f, new):
    """cs2_dumper::offsets section of offsets.hpp straight from offsets.json."""
    if 'namespace cs2_dumper' not in f.text:
        return
    head, _, _ = f.text.partition('namespace cs2_dumper')
    nl = '\r\n' if '\r\n' in f.text else '\n'
    L = ['namespace cs2_dumper {', '    namespace offsets {', '']
    for mod, vals in new.offsets_json.items():
        L.append(f'        namespace {mod.replace(".dll", "_dll")} {{')
        for k, v in vals.items():
            L.append(f'            constexpr std::ptrdiff_t {k} = {hexs(int(v, 16))};')
        L += ['        }', '']
    L[-1:] = ['    }', '}', '']
    f.text = head + nl.join(L)


# --------------------------------------------------------------------------- dumper

def manifest_text(inc):
    try:
        return (inc / 'manifest.json').read_text(encoding='utf-8-sig')
    except OSError:
        return None


def wait_dumper(args, inc, stamp, timeout):
    """Waits for cs2-sdk.exe. If it keeps running after the dump is written
    (e.g. 'press any key'), it is closed once manifest.json has been stable for 15s."""
    proc = subprocess.Popen(args, cwd=REPO, stdin=subprocess.DEVNULL)
    start = time.time()
    last, stable_since = None, None
    while proc.poll() is None:
        time.sleep(1)
        cur = manifest_text(inc)
        if cur and cur != stamp:
            if cur != last:
                last, stable_since = cur, time.time()
            elif time.time() - stable_since > 15:
                log('[*] dump written, cs2-sdk.exe still open - closing it')
                proc.terminate()
                return None
        if time.time() - start > timeout:
            proc.kill()
            raise SystemExit(f'[!] cs2-sdk.exe did not finish within {timeout}s')
    return proc.returncode


def run_dumper(exe, prev_dir, timeout, extra):
    inc = REPO / 'include'
    # .sdk_prev/include = the dump the code currently matches (kept in sync after every update)
    if inc.exists() and not prev_dir.exists():
        shutil.copytree(inc, prev_dir)
        log(f'[*] previous dump backed up to {prev_dir.relative_to(REPO)}')
    stamp = (inc / 'manifest.json').read_text(encoding='utf-8-sig') if (inc / 'manifest.json').exists() else None

    args = [str(exe), '--output', str(inc)]
    if prev_dir.exists():
        args += ['--previous', str(prev_dir)]
    args += extra
    log(f'[*] running: {" ".join(args)}')
    log('[*] waiting for cs2-sdk to finish (CS2 must be running)...')
    code = wait_dumper(args, inc, stamp, timeout)
    if code not in (0, None):
        log(f'[!] cs2-sdk.exe exited with code {code}, retrying without arguments')
        code = wait_dumper([str(exe)], inc, stamp, timeout)
        if code not in (0, None):
            raise SystemExit(f'[!] cs2-sdk.exe failed (exit code {code})')
    if not (inc / 'manifest.json').exists():
        raise SystemExit('[!] cs2-sdk.exe finished but include/manifest.json was not written')
    if stamp is not None and (inc / 'manifest.json').read_text(encoding='utf-8-sig') == stamp:
        raise SystemExit('[!] include/manifest.json did not change - the dump did not run (is CS2 open?)')


def print_dump_status(new):
    p = new.root / 'status.json'
    if not p.exists():
        return
    st = json.loads(read_text(p))
    log(f'[*] dump: build {st.get("build_number")}, patch {st.get("patch_version")}, checks ok={st.get("ok")}')
    for c in st.get('checks', []):
        if c.get('status') != 'pass':
            log(f'    [{c["status"]}] {c["name"]}: {c.get("detail")}')


# --------------------------------------------------------------------------- main

def main():
    ap = argparse.ArgumentParser(description='Run cs2-sdk.exe and update offsets / signatures in the project.')
    ap.add_argument('--exe', default=str(REPO / 'cs2-sdk.exe'), help='path to cs2-sdk.exe')
    ap.add_argument('--skip-dump', action='store_true', help='do not run cs2-sdk.exe, only update the code')
    ap.add_argument('--old', help='previous dump folder (default: .sdk_prev/include, or include/ with --skip-dump)')
    ap.add_argument('--new', help='new dump folder (default: include/)')
    ap.add_argument('--dry-run', action='store_true', help='show changes, write nothing')
    ap.add_argument('--timeout', type=int, default=900, help='seconds to wait for cs2-sdk.exe (default 900)')
    ap.add_argument('--dumper-args', default='', help='extra arguments passed to cs2-sdk.exe')
    a = ap.parse_args()

    prev_dir = REPO / '.sdk_prev' / 'include'
    if not a.skip_dump:
        exe = Path(a.exe).resolve()
        if not exe.exists():
            raise SystemExit(f'[!] {exe} not found (use --exe)')
        run_dumper(exe, prev_dir, a.timeout, a.dumper_args.split())

    new_dir = Path(a.new) if a.new else REPO / 'include'
    old_dir = Path(a.old) if a.old else (prev_dir if prev_dir.exists() else new_dir)
    log(f'[*] old dump: {old_dir}')
    log(f'[*] new dump: {new_dir}')
    old, new = Dump(old_dir), Dump(new_dir)
    print_dump_status(new)
    config = json.loads(read_text(CONFIG)) if CONFIG.exists() else {}
    res = Resolver(old, new, config)

    stats = {k: [] for k in ('sig_updated', 'sig_missing', 'hex', 'pat_updated', 'pat_lost', 'tagged', 'tag_failed')}

    # generated headers
    changed = regen_schemas(new, a.dry_run)
    if regen_interfaces(new, a.dry_run):
        changed.append('interfaces_sdk.hpp')
    if regen_vtables(new, a.dry_run):
        changed.append('vtables.hpp/json')
    for src, dst in ((new.root / 'offsets' / 'offsets.json', SDK / 'offsets.json'),
                     (new.root / 'buttons.json', SDK / 'buttons.json'),
                     (new.root / 'verified_features.json', SDK / 'verified_features.json')):
        if src.exists() and write_file(dst, read_text(src), a.dry_run, bom=False):
            changed.append(dst.name)
    regenerated = {SDK / f'{m}_dll.hpp' for m in (p.name[:-8] for p in (new.root / 'schemas').glob('*_dll.hpp'))}
    regenerated |= {SDK / 'cs2sdk_macros.hpp', SDK / 'interfaces_sdk.hpp', SDK / 'vtables.hpp'}

    # every source file in src/
    files_changed = []
    for path in sorted(SRC.rglob('*')):
        if path.suffix not in SOURCE_EXT or path in regenerated:
            continue
        rel_parts = set(path.relative_to(SRC).parts)
        if rel_parts & SKIP_PARTS or path.name.endswith(SKIP_SUFFIX):
            continue
        f = SrcFile(path)
        if path.name == 'offsets.hpp' and path.parent == SDK:
            regen_dumper_offsets(f, new)
        if path.name == 'signatures.cpp':
            update_signatures(f, res, stats)
        generic_pass(f, res, stats, is_generated_sdk=False)
        if old.build and new.build and old.build != new.build:
            f.text = re.sub(r'(CS2_BUILD\s*=\s*)%d\b' % old.build, r'\g<1>%d' % new.build, f.text)
        if f.changed:
            files_changed.append(path.relative_to(REPO).as_posix())
            f.save(a.dry_run)

    # report
    log('')
    log(f'=== {"DRY RUN - " if a.dry_run else ""}build {old.build} -> {new.build} ===')
    log(f'regenerated: {", ".join(changed) or "nothing"}')
    log(f'files updated ({len(files_changed)}): ' + (', '.join(files_changed) or 'none'))
    sections = (('signatures updated', 'sig_updated'), ('offsets updated', 'hex'), ('inline patterns updated', 'pat_updated'),
                ('@sdk tags updated', 'tagged'),
                ('!! signatures NOT in the dump (old pattern kept, check them by hand)', 'sig_missing'),
                ('!! inline patterns the new dump lost', 'pat_lost'), ('!! @sdk tags that could not be resolved', 'tag_failed'))
    for title, key in sections:
        if stats[key]:
            log(f'\n{title} ({len(stats[key])}):')
            for s in stats[key]:
                log('  ' + s)
    if not a.dry_run:
        # the code now matches the new dump -> it becomes the "previous" one for the next update
        if new_dir.resolve() != prev_dir.resolve():
            if prev_dir.exists():
                shutil.rmtree(prev_dir)
            shutil.copytree(new_dir, prev_dir)
        (REPO / 'tools' / 'sdk_update_report.txt').write_text('\n'.join(report) + '\n', encoding='utf-8')
        log('\n[*] report saved to tools/sdk_update_report.txt')


if __name__ == '__main__':
    main()
