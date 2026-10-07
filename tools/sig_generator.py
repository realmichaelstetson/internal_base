#!/usr/bin/env python3
"""
CS2 Signature Generator for kolembahook
Generates constexpr signature_entry_t entries by name, string, offset, or symbol.
"""

import os
import sys
import struct
import re
import bisect
from pathlib import Path

DEFAULT_CS2_PATHS = [
    r"C:\Program Files (x86)\Steam\steamapps\common\Counter-Strike Global Offensive\game\csgo\bin\win64",
    r"C:\Program Files (x86)\Steam\steamapps\common\Counter-Strike Global Offensive\game\bin\win64",
    r"D:\Steam\steamapps\common\Counter-Strike Global Offensive\game\csgo\bin\win64",
    r"D:\Steam\steamapps\common\Counter-Strike Global Offensive\game\bin\win64",
]

class PeModule:
    def __init__(self, file_path: str):
        self.file_path = file_path
        self.module_name = os.path.basename(file_path).lower()
        with open(file_path, "rb") as f:
            self.data = f.read()

        self.sections = []
        self.text_sec = None
        self.rdata_sec = None
        self.pdata_sec = None
        self.pdata_functions = [] # list of (begin_rva, end_rva)
        self.pdata_begins = []

        self._parse_pe()

    def _parse_pe(self):
        e_lfanew = struct.unpack_from("<I", self.data, 0x3C)[0]
        self.e_lfanew = e_lfanew
        magic = struct.unpack_from("<H", self.data, e_lfanew + 24)[0]
        self.is_64bit = (magic == 0x20B)

        num_sections = struct.unpack_from("<H", self.data, e_lfanew + 6)[0]
        opt_hdr_size = struct.unpack_from("<H", self.data, e_lfanew + 20)[0]
        sec_table_offset = e_lfanew + 24 + opt_hdr_size

        for i in range(num_sections):
            sec_offset = sec_table_offset + i * 40
            name_raw = self.data[sec_offset:sec_offset+8].rstrip(b"\x00")
            name = name_raw.decode(errors="ignore")
            vsize, vrva, rsize, roff = struct.unpack_from("<IIII", self.data, sec_offset + 8)
            sec_dict = {
                "name": name,
                "vsize": vsize,
                "vrva": vrva,
                "rsize": rsize,
                "roff": roff,
            }
            self.sections.append(sec_dict)
            if name == ".text":
                self.text_sec = sec_dict
            elif name == ".rdata":
                self.rdata_sec = sec_dict
            elif name == ".pdata":
                self.pdata_sec = sec_dict

        # Parse Exception directory (.pdata)
        if self.is_64bit:
            pdata_dir_off = e_lfanew + 136 + 3 * 8
            pdata_rva, pdata_size = struct.unpack_from("<II", self.data, pdata_dir_off)
            pdata_file_off = self.rva_to_offset(pdata_rva)
            if pdata_file_off:
                num_entries = pdata_size // 12
                for i in range(num_entries):
                    b_rva, e_rva, _ = struct.unpack_from("<III", self.data, pdata_file_off + i * 12)
                    self.pdata_functions.append((b_rva, e_rva))
                    self.pdata_begins.append(b_rva)

    def rva_to_offset(self, rva: int):
        for sec in self.sections:
            if sec["vrva"] <= rva < sec["vrva"] + max(sec["vsize"], sec["rsize"]):
                return sec["roff"] + (rva - sec["vrva"])
        return None

    def offset_to_rva(self, offset: int):
        for sec in self.sections:
            if sec["roff"] <= offset < sec["roff"] + sec["rsize"]:
                return sec["vrva"] + (offset - sec["roff"])
        return None

    def find_function_for_rva(self, rva: int):
        if not self.pdata_begins:
            return None, None
        idx = bisect.bisect_right(self.pdata_begins, rva) - 1
        if 0 <= idx < len(self.pdata_functions):
            b_rva, e_rva = self.pdata_functions[idx]
            if b_rva <= rva < e_rva:
                return b_rva, e_rva
        return None, None

    def search_string(self, string_term: str):
        term_bytes = string_term.encode("utf-8")
        results = []
        pos = 0
        while True:
            idx = self.data.find(term_bytes, pos)
            if idx == -1:
                break
            results.append(idx)
            pos = idx + 1
        return results

    def find_rip_xrefs(self, target_rva: int):
        if not self.text_sec:
            return []
        refs = []
        t_off = self.text_sec["roff"]
        t_size = self.text_sec["rsize"]
        t_vrva = self.text_sec["vrva"]

        data = self.data
        end_scan = t_off + t_size - 7
        for off in range(t_off, end_scan):
            # Check 4-byte displacement
            disp = struct.unpack_from("<i", data, off)[0]
            # In RIP-relative, the instruction ends after the 4 displacement bytes:
            inst_end_rva = t_vrva + (off + 4 - t_off)
            if inst_end_rva + disp == target_rva:
                inst_start_off = off - 3  # typical 3-byte prefix (e.g. 48 8D 0D)
                refs.append((inst_start_off, inst_end_rva - 4))
        return refs


class SignatureGenerator:
    def __init__(self, project_root: str):
        self.project_root = project_root
        self.modules = {} # name -> PeModule
        self.offsets_db = {} # name -> (module, rva)
        self.signatures_db = {} # name -> entry dict

        self._find_cs2_dlls()
        self._load_offsets()
        self._load_signatures()

    def _find_cs2_dlls(self):
        found_dlls = {}
        for base_path in DEFAULT_CS2_PATHS:
            if os.path.exists(base_path):
                for f in os.listdir(base_path):
                    if f.lower().endswith(".dll") and f.lower() not in found_dlls:
                        found_dlls[f.lower()] = os.path.join(base_path, f)

        for name, path in found_dlls.items():
            try:
                self.modules[name] = PeModule(path)
            except Exception as e:
                pass

    def get_module(self, name: str) -> PeModule:
        name = name.lower()
        if not name.endswith(".dll"):
            name += ".dll"
        return self.modules.get(name)

    def _load_offsets(self):
        # Read offsets.h
        offsets_h = os.path.join(self.project_root, "offsets.h")
        if os.path.exists(offsets_h):
            with open(offsets_h, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()
            curr_mod = "client.dll"
            for line in content.splitlines():
                line = line.strip()
                if "namespace " in line:
                    ns = line.split("namespace ")[-1].strip("{ ")
                    if ns in ["client", "engine2", "scenesystem", "materialsystem2", "inputsystem"]:
                        curr_mod = ns + ".dll"
                elif "inline uintptr_t" in line and "=" in line:
                    parts = line.replace("inline uintptr_t", "").split("=")
                    name = parts[0].strip()
                    val_str = parts[1].split(";")[0].strip()
                    try:
                        val = int(val_str, 16) if "0x" in val_str else int(val_str)
                        self.offsets_db[name] = (curr_mod, val)
                    except:
                        pass

        # Read src/sdk/offsets.hpp
        offsets_hpp = os.path.join(self.project_root, "src", "sdk", "offsets.hpp")
        if os.path.exists(offsets_hpp):
            with open(offsets_hpp, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()
            curr_mod = "client.dll"
            for line in content.splitlines():
                line = line.strip()
                if "namespace " in line and "_dll" in line:
                    curr_mod = line.split("namespace ")[-1].replace("_dll", ".dll").strip("{ ")
                elif "constexpr std::ptrdiff_t" in line and "=" in line:
                    parts = line.replace("constexpr std::ptrdiff_t", "").split("=")
                    name = parts[0].strip()
                    val_str = parts[1].split(";")[0].strip()
                    try:
                        val = int(val_str, 16) if "0x" in val_str else int(val_str)
                        self.offsets_db[name] = (curr_mod, val)
                    except:
                        pass

    def _load_signatures(self):
        sig_cpp = os.path.join(self.project_root, "src", "sdk", "valve", "signatures", "signatures.cpp")
        if not os.path.exists(sig_cpp):
            return
        with open(sig_cpp, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()

        pattern = re.compile(r'\{\s*"([^"]+)",\s*"([^"]+)",\s*"([^"]+)"sv,\s*signature_resolve_kind::(\w+),\s*(-?\d+),\s*(-?\w+)\s*\}')
        for match in pattern.finditer(content):
            name, module_name, pattern_str, resolve, rel_off, extra_off = match.groups()
            self.signatures_db[name] = {
                "name": name,
                "module_name": module_name,
                "pattern": pattern_str,
                "resolve": resolve,
                "rel_off": int(rel_off),
                "extra_off": int(extra_off, 0),
            }

    def generate_pattern(self, module: PeModule, file_offset: int, max_len: int = 64):
        """
        Takes raw bytes from file_offset and wildcards variable parts,
        lengthening until unique in .text.
        """
        data = module.data
        text_sec = module.text_sec
        if not text_sec:
            return None, 0, "No .text section found"

        t_data = data[text_sec["roff"]:text_sec["roff"] + text_sec["rsize"]]
        tokens = []

        i = 0
        while i < max_len:
            pos = file_offset + i
            if pos >= len(data):
                break

            b = data[pos]

            # Check 5-byte CALL rel32 / JMP rel32 (E8 / E9)
            if b in (0xE8, 0xE9):
                tokens.append(f"{b:02X}")
                tokens.extend(["?", "?", "?", "?"])
                i += 5
                continue

            # Check 6-byte 0F 80..8F Jcc rel32
            if b == 0x0F and pos + 1 < len(data) and 0x80 <= data[pos+1] <= 0x8F:
                tokens.append(f"{b:02X}")
                tokens.append(f"{data[pos+1]:02X}")
                tokens.extend(["?", "?", "?", "?"])
                i += 6
                continue

            # Check sub rsp, imm8: 48 83 EC xx -> 48 83 EC ?
            if b == 0x48 and pos + 3 < len(data) and data[pos+1] == 0x83 and data[pos+2] == 0xEC:
                tokens.extend(["48", "83", "EC", "?"])
                i += 4
                continue

            # Check sub rsp, imm32: 48 81 EC xx xx xx xx -> 48 81 EC ? ? ? ?
            if b == 0x48 and pos + 6 < len(data) and data[pos+1] == 0x81 and data[pos+2] == 0xEC:
                tokens.extend(["48", "81", "EC", "?", "?", "?", "?"])
                i += 7
                continue

            # Check mov [rsp+imm8], reg: 48 89 xx 24 yy
            if b == 0x48 and pos + 4 < len(data) and data[pos+1] == 0x89 and data[pos+3] == 0x24:
                tokens.extend(["48", "89", f"{data[pos+2]:02X}", "24", "?"])
                i += 5
                continue

            # Check lea rbp, [rsp+imm32]: 48 8D AC 24 xx xx xx xx
            if b == 0x48 and pos + 7 < len(data) and data[pos+1] == 0x8D and data[pos+2] == 0xAC and data[pos+3] == 0x24:
                tokens.extend(["48", "8D", "AC", "24", "?", "?", "?", "?"])
                i += 8
                continue

            # Check RIP-relative: (REX)? (opcode) ModR/M where (modrm & 0xC7 == 0x05)
            # Example: 48 8B 05 xx xx xx xx / 48 8D 0D xx xx xx xx
            idx_after_rex = pos
            if 0x40 <= b <= 0x4F:
                idx_after_rex = pos + 1

            if idx_after_rex < len(data):
                op = data[idx_after_rex]
                modrm_idx = idx_after_rex + 1

                # 2-byte opcode 0F xx
                if op == 0x0F and modrm_idx < len(data):
                    modrm_idx += 1

                if modrm_idx < len(data):
                    modrm = data[modrm_idx]
                    if (modrm & 0xC7) == 0x05: # RIP relative!
                        inst_len = (modrm_idx - pos) + 1 + 4
                        if pos + inst_len <= len(data):
                            for k in range(pos, modrm_idx + 1):
                                tokens.append(f"{data[k]:02X}")
                            tokens.extend(["?", "?", "?", "?"])
                            i += inst_len
                            continue

            # Default: single byte
            tokens.append(f"{b:02X}")
            i += 1

            # Check if current tokens are already unique in .text
            if len(tokens) >= 12:
                pat_str = " ".join(tokens)
                matches = self.count_matches(t_data, pat_str)
                if matches == 1:
                    while tokens and tokens[-1] == "?":
                        tokens.pop()
                    return " ".join(tokens), 1, "Unique"

        while tokens and tokens[-1] == "?":
            tokens.pop()
        pat_str = " ".join(tokens)
        matches = self.count_matches(t_data, pat_str)
        return pat_str, matches, ("Unique" if matches == 1 else f"Multiple matches ({matches})")

    def count_matches(self, data: bytes, pattern_str: str) -> int:
        regex_parts = []
        for t in pattern_str.split():
            if t == "?":
                regex_parts.append(b".")
            else:
                regex_parts.append(re.escape(bytes([int(t, 16)])))
        rx = re.compile(b"".join(regex_parts), re.DOTALL)
        return len(rx.findall(data))

    def find_target(self, query: str):
        query_strip = query.strip()

        # 1. Hex offset directly
        if query_strip.lower().startswith("0x"):
            try:
                rva = int(query_strip, 16)
                client = self.get_module("client.dll")
                if client:
                    off = client.rva_to_offset(rva)
                    if off:
                        return [{
                            "source": "hex_rva",
                            "name": f"sub_{rva:X}",
                            "module": client,
                            "rva": rva,
                            "file_offset": off,
                            "detail": f"Direct RVA 0x{rva:X}"
                        }]
            except:
                pass

        # 2. Known offsets database (offsets.h)
        results = []
        for name, (mod_name, rva) in self.offsets_db.items():
            if query_strip.lower() == name.lower() or query_strip.lower() in name.lower():
                mod = self.get_module(mod_name)
                if mod:
                    off = mod.rva_to_offset(rva)
                    if off:
                        results.append({
                            "source": "offsets.h",
                            "name": name,
                            "module": mod,
                            "rva": rva,
                            "file_offset": off,
                            "detail": f"From offsets.h [{mod_name} + 0x{rva:X}]"
                        })

        # 3. Known signatures database (signatures.cpp)
        for name, entry in self.signatures_db.items():
            if query_strip.lower() == name.lower() or query_strip.lower() in name.lower():
                mod = self.get_module(entry["module_name"])
                if mod and mod.text_sec:
                    t_data = mod.data[mod.text_sec["roff"]:mod.text_sec["roff"] + mod.text_sec["rsize"]]
                    regex_parts = []
                    for t in entry["pattern"].split():
                        if t == "?":
                            regex_parts.append(b".")
                        else:
                            regex_parts.append(re.escape(bytes([int(t, 16)])))
                    rx = re.compile(b"".join(regex_parts), re.DOTALL)
                    m = rx.search(t_data)
                    if m:
                        file_off = mod.text_sec["roff"] + m.start()
                        rva = mod.offset_to_rva(file_off)
                        results.append({
                            "source": "signatures.cpp",
                            "name": name,
                            "module": mod,
                            "rva": rva,
                            "file_offset": file_off,
                            "resolve": entry["resolve"],
                            "rel_off": entry["rel_off"],
                            "extra_off": entry["extra_off"],
                            "detail": f"Existing signature in signatures.cpp (Found at 0x{rva:X})"
                        })

        # 4. String search in modules
        search_mods = ["client.dll", "engine2.dll", "scenesystem.dll", "tier0.dll", "materialsystem2.dll"]
        for mod_name in search_mods:
            mod = self.get_module(mod_name)
            if not mod:
                continue
            str_offsets = mod.search_string(query_strip)
            for s_off in str_offsets[:5]:
                s_rva = mod.offset_to_rva(s_off)
                if not s_rva:
                    continue
                xrefs = mod.find_rip_xrefs(s_rva)
                for x_off, x_rva in xrefs[:3]:
                    fn_start_rva, fn_end_rva = mod.find_function_for_rva(x_rva)
                    if fn_start_rva:
                        fn_file_off = mod.rva_to_offset(fn_start_rva)
                        results.append({
                            "source": "string_xref",
                            "name": query_strip,
                            "module": mod,
                            "rva": fn_start_rva,
                            "file_offset": fn_file_off,
                            "detail": f"String '{query_strip}' at 0x{s_rva:X} referenced at 0x{x_rva:X} (Function 0x{fn_start_rva:X})"
                        })

        return results


def main():
    print("=" * 70)
    print("      CS2 Pattern & Signature Entry Generator for kolembahook")
    print("=" * 70)

    project_root = r"c:\Users\barte\Desktop\kolembahook"
    gen = SignatureGenerator(project_root)

    print(f"[+] Loaded {len(gen.modules)} CS2 DLL modules from disk.")
    print(f"[+] Loaded {len(gen.offsets_db)} offsets from offsets.h / offsets.hpp.")
    print(f"[+] Loaded {len(gen.signatures_db)} existing signatures from signatures.cpp.")
    print("-" * 70)
    print("You can search by:")
    print("  * Function or variable name (e.g. SetModel, LevelInit, SetSceneObjectAttributeFloat4)")
    print("  * String present in CS2 code (e.g. Pause_t, FrameStageNotify, TraceShape)")
    print("  * Direct RVA address (e.g. 0x934CA0 or 0x170350)")
    print("Type 'exit' or press Ctrl+C to quit.")
    print("-" * 70)

    if len(sys.argv) > 1:
        queries = [" ".join(sys.argv[1:])]
        is_cli_arg = True
    else:
        is_cli_arg = False

    while True:
        try:
            if not is_cli_arg:
                query = input("\nEnter name / query: ").strip()
            else:
                query = queries.pop(0)
        except (KeyboardInterrupt, EOFError):
            print("\nExiting.")
            break

        if not query or query.lower() in ("exit", "quit", "q"):
            break

        matches = gen.find_target(query)
        if not matches:
            print(f"[-] No matches found for '{query}'.")
            if is_cli_arg:
                break
            continue

        print(f"\n[+] Found {len(matches)} potential targets:")
        for idx, m in enumerate(matches):
            print(f"  [{idx + 1}] {m['name']} ({m['module'].module_name}) -> RVA: 0x{m['rva']:X} | {m['detail']}")

        chosen = matches[0]
        if len(matches) > 1 and not is_cli_arg:
            choice = input(f"Select item (1-{len(matches)}) [default: 1]: ").strip()
            if choice.isdigit() and 1 <= int(choice) <= len(matches):
                chosen = matches[int(choice) - 1]

        mod = chosen["module"]
        off = chosen["file_offset"]
        name = chosen["name"]

        print(f"\n[*] Generating pattern for '{name}' at 0x{chosen['rva']:X} in {mod.module_name}...")
        pattern, match_count, status = gen.generate_pattern(mod, off)

        resolve_kind = chosen.get("resolve", "raw")
        rel_off = chosen.get("rel_off", 0)
        extra_off = chosen.get("extra_off", 0)

        print("\n" + "=" * 70)
        print(f"  Status:  {status} ({match_count} match in .text)")
        print(f"  RVA:     0x{chosen['rva']:X}")
        print(f"  Pattern: {pattern}")
        print("=" * 70)
        print("\n--> Gotowa linijka do signatures.cpp:")
        entry_code = f'\t{{ "{name}", "{mod.module_name}", "{pattern}"sv, signature_resolve_kind::{resolve_kind}, {rel_off}, {extra_off} }},'
        print(entry_code)
        print("=" * 70)

        if is_cli_arg:
            break

if __name__ == "__main__":
    main()
