#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>
#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <iomanip>

namespace fs = std::filesystem;

struct SectionInfo {
    std::string name;
    uint32_t virtual_size;
    uint32_t virtual_address;
    uint32_t raw_size;
    uint32_t raw_offset;
};

struct FunctionRange {
    uint32_t begin_rva;
    uint32_t end_rva;
};

class PeModule {
public:
    std::string file_path;
    std::string module_name;
    std::vector<uint8_t> buffer;
    std::vector<SectionInfo> sections;
    const SectionInfo* text_sec = nullptr;
    const SectionInfo* rdata_sec = nullptr;
    const SectionInfo* pdata_sec = nullptr;
    std::vector<FunctionRange> pdata_functions;

    bool load(const std::string& path) {
        file_path = path;
        module_name = fs::path(path).filename().string();
        std::transform(module_name.begin(), module_name.end(), module_name.begin(), ::tolower);

        std::ifstream file(path, std::ios::binary | std::ios::ate);
        if (!file.is_open())
            return false;

        const auto size = file.tellg();
        file.seekg(0, std::ios::beg);
        buffer.resize(size);
        file.read(reinterpret_cast<char*>(buffer.data()), size);

        return parse();
    }

    uint32_t rva_to_offset(uint32_t rva) const {
        for (const auto& sec : sections) {
            uint32_t max_size = (std::max)(sec.virtual_size, sec.raw_size);
            if (rva >= sec.virtual_address && rva < sec.virtual_address + max_size)
                return sec.raw_offset + (rva - sec.virtual_address);
        }
        return 0;
    }

    uint32_t offset_to_rva(uint32_t off) const {
        for (const auto& sec : sections) {
            if (off >= sec.raw_offset && off < sec.raw_offset + sec.raw_size)
                return sec.virtual_address + (off - sec.raw_offset);
        }
        return 0;
    }

    bool find_function_bounds(uint32_t rva, uint32_t& out_begin, uint32_t& out_end) const {
        if (pdata_functions.empty())
            return false;

        auto it = std::upper_bound(pdata_functions.begin(), pdata_functions.end(), rva,
            [](uint32_t val, const FunctionRange& fn) {
                return val < fn.begin_rva;
            });

        if (it != pdata_functions.begin()) {
            --it;
            if (rva >= it->begin_rva && rva < it->end_rva) {
                out_begin = it->begin_rva;
                out_end = it->end_rva;
                return true;
            }
        }
        return false;
    }

    std::vector<uint32_t> find_string(const std::string& term) const {
        std::vector<uint32_t> results;
        if (term.empty() || buffer.empty())
            return results;

        const uint8_t* p = buffer.data();
        const size_t len = term.size();
        const size_t total = buffer.size();

        for (size_t i = 0; i + len <= total; ++i) {
            if (std::memcmp(p + i, term.data(), len) == 0) {
                results.push_back(static_cast<uint32_t>(i));
            }
        }
        return results;
    }

    std::vector<uint32_t> find_rip_xrefs(uint32_t target_rva) const {
        std::vector<uint32_t> xrefs;
        if (!text_sec)
            return xrefs;

        const uint8_t* p = buffer.data();
        const uint32_t start_off = text_sec->raw_offset;
        const uint32_t end_off = start_off + text_sec->raw_size;
        const uint32_t text_vrva = text_sec->virtual_address;

        if (end_off <= 7)
            return xrefs;

        for (uint32_t off = start_off; off + 4 <= end_off; ++off) {
            int32_t disp = *reinterpret_cast<const int32_t*>(p + off);
            uint32_t inst_end_rva = text_vrva + (off + 4 - start_off);
            if (inst_end_rva + disp == target_rva) {
                uint32_t inst_rva = inst_end_rva - 4;
                xrefs.push_back(inst_rva);
            }
        }
        return xrefs;
    }

private:
    bool parse() {
        if (buffer.size() < sizeof(IMAGE_DOS_HEADER))
            return false;

        auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(buffer.data());
        if (dos->e_magic != IMAGE_DOS_SIGNATURE)
            return false;

        if (buffer.size() < dos->e_lfanew + sizeof(IMAGE_NT_HEADERS64))
            return false;

        auto nt = reinterpret_cast<const IMAGE_NT_HEADERS64*>(buffer.data() + dos->e_lfanew);
        if (nt->Signature != IMAGE_NT_SIGNATURE || nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR64_MAGIC)
            return false;

        const auto num_sec = nt->FileHeader.NumberOfSections;
        auto sec_ptr = reinterpret_cast<const IMAGE_SECTION_HEADER*>(
            buffer.data() + dos->e_lfanew + sizeof(IMAGE_NT_HEADERS64));

        for (WORD i = 0; i < num_sec; ++i) {
            char name_buf[9]{};
            std::memcpy(name_buf, sec_ptr[i].Name, 8);
            SectionInfo info;
            info.name = name_buf;
            info.virtual_size = sec_ptr[i].Misc.VirtualSize;
            info.virtual_address = sec_ptr[i].VirtualAddress;
            info.raw_size = sec_ptr[i].SizeOfRawData;
            info.raw_offset = sec_ptr[i].PointerToRawData;
            sections.push_back(info);
        }

        for (const auto& sec : sections) {
            if (sec.name == ".text") text_sec = &sec;
            else if (sec.name == ".rdata") rdata_sec = &sec;
            else if (sec.name == ".pdata") pdata_sec = &sec;
        }

        // Parse .pdata for fast x64 function lookups
        auto& pdata_dir = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION];
        if (pdata_dir.VirtualAddress && pdata_dir.Size) {
            uint32_t pdata_file_off = rva_to_offset(pdata_dir.VirtualAddress);
            if (pdata_file_off && pdata_file_off + pdata_dir.Size <= buffer.size()) {
                auto rf = reinterpret_cast<const IMAGE_RUNTIME_FUNCTION_ENTRY*>(buffer.data() + pdata_file_off);
                size_t count = pdata_dir.Size / sizeof(IMAGE_RUNTIME_FUNCTION_ENTRY);
                pdata_functions.reserve(count);
                for (size_t i = 0; i < count; ++i) {
                    pdata_functions.push_back({ rf[i].BeginAddress, rf[i].EndAddress });
                }
            }
        }
        return true;
    }
};

struct SearchResult {
    std::string name;
    std::string module_name;
    std::string pattern;
    uint32_t rva = 0;
    uint32_t file_offset = 0;
    std::string resolve_kind = "raw";
    int rel_offset = 0;
    int extra_offset = 0;
    std::string detail;
};

class SignatureTool {
public:
    std::unordered_map<std::string, PeModule> modules;
    std::unordered_map<std::string, std::pair<std::string, uint32_t>> offsets_db;
    std::unordered_map<std::string, SearchResult> existing_sigs;
    std::vector<std::string> existing_sigs_order;
    std::string project_dir;

    SignatureTool(const std::string& proj_dir) : project_dir(proj_dir) {
        init_modules();
        load_offsets();
        load_existing_signatures();
    }

    void init_modules() {
        const std::vector<std::string> search_dirs = {
            "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Counter-Strike Global Offensive\\game\\csgo\\bin\\win64",
            "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Counter-Strike Global Offensive\\game\\bin\\win64",
            "D:\\Steam\\steamapps\\common\\Counter-Strike Global Offensive\\game\\csgo\\bin\\win64",
            "D:\\Steam\\steamapps\\common\\Counter-Strike Global Offensive\\game\\bin\\win64"
        };

        for (const auto& dir : search_dirs) {
            if (!fs::exists(dir))
                continue;

            for (const auto& entry : fs::directory_iterator(dir)) {
                if (entry.is_regular_file() && entry.path().extension() == ".dll") {
                    std::string fname = entry.path().filename().string();
                    std::string lower = fname;
                    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                    if (modules.find(lower) == modules.end()) {
                        PeModule mod;
                        if (mod.load(entry.path().string())) {
                            modules[lower] = std::move(mod);
                        }
                    }
                }
            }
        }
    }

    void load_offsets() {
        std::vector<std::string> files = {
            project_dir + "\\offsets.h",
            project_dir + "\\src\\sdk\\offsets.hpp"
        };

        for (const auto& fpath : files) {
            std::ifstream f(fpath);
            if (!f.is_open()) continue;

            std::string line;
            std::string curr_mod = "client.dll";
            while (std::getline(f, line)) {
                if (line.find("namespace ") != std::string::npos) {
                    if (line.find("client") != std::string::npos) curr_mod = "client.dll";
                    else if (line.find("engine2") != std::string::npos) curr_mod = "engine2.dll";
                    else if (line.find("scenesystem") != std::string::npos) curr_mod = "scenesystem.dll";
                    else if (line.find("materialsystem2") != std::string::npos) curr_mod = "materialsystem2.dll";
                }
                else if (line.find("uintptr_t") != std::string::npos || line.find("ptrdiff_t") != std::string::npos) {
                    auto eq_pos = line.find('=');
                    auto semi_pos = line.find(';');
                    if (eq_pos != std::string::npos && semi_pos != std::string::npos) {
                        std::string left = line.substr(0, eq_pos);
                        std::string right = line.substr(eq_pos + 1, semi_pos - eq_pos - 1);
                        
                        std::stringstream ss(left);
                        std::string kw1, kw2, name;
                        ss >> kw1 >> kw2 >> name;
                        if (name.empty()) name = kw2;

                        uint32_t val = 0;
                        try {
                            val = static_cast<uint32_t>(std::stoul(right, nullptr, 0));
                            if (!name.empty() && val != 0) {
                                offsets_db[name] = { curr_mod, val };
                            }
                        } catch (...) {}
                    }
                }
            }
        }
    }

    void load_existing_signatures() {
        std::string path = project_dir + "\\src\\sdk\\valve\\signatures\\signatures.cpp";
        std::ifstream f(path);
        if (!f.is_open()) return;

        std::string line;
        while (std::getline(f, line)) {
            auto first_quote = line.find('"');
            if (first_quote == std::string::npos) continue;
            auto second_quote = line.find('"', first_quote + 1);
            if (second_quote == std::string::npos) continue;
            std::string name = line.substr(first_quote + 1, second_quote - first_quote - 1);

            auto third_quote = line.find('"', second_quote + 1);
            if (third_quote == std::string::npos) continue;
            auto fourth_quote = line.find('"', third_quote + 1);
            if (fourth_quote == std::string::npos) continue;
            std::string mod = line.substr(third_quote + 1, fourth_quote - third_quote - 1);

            auto fifth_quote = line.find('"', fourth_quote + 1);
            if (fifth_quote == std::string::npos) continue;
            auto sixth_quote = line.find('"', fifth_quote + 1);
            if (sixth_quote == std::string::npos) continue;
            std::string pattern = line.substr(fifth_quote + 1, sixth_quote - fifth_quote - 1);

            SearchResult res;
            res.name = name;
            res.module_name = mod;
            res.pattern = pattern;
            if (line.find("rel32") != std::string::npos) res.resolve_kind = "rel32";
            else if (line.find("riprel") != std::string::npos) res.resolve_kind = "riprel";
            else res.resolve_kind = "raw";

            auto comma1 = line.find(',', sixth_quote);
            if (comma1 != std::string::npos) {
                auto comma2 = line.find(',', comma1 + 1);
                if (comma2 != std::string::npos) {
                    auto comma3 = line.find(',', comma2 + 1);
                    if (comma3 != std::string::npos) {
                        try {
                            res.rel_offset = std::stoi(line.substr(comma2 + 1, comma3 - comma2 - 1));
                            res.extra_offset = std::stoi(line.substr(comma3 + 1));
                        } catch (...) {}
                    }
                }
            }

            existing_sigs_order.push_back(name);
            existing_sigs[name] = res;
        }
    }

    std::vector<int> parse_pattern(const std::string& pat_str) const {
        std::vector<int> bytes;
        std::stringstream ss(pat_str);
        std::string token;
        while (ss >> token) {
            if (token == "?" || token == "??") {
                bytes.push_back(-1);
            } else {
                try {
                    bytes.push_back(std::stoi(token, nullptr, 16));
                } catch (...) {
                    bytes.push_back(-1);
                }
            }
        }
        return bytes;
    }

    uint32_t find_pattern_offset(const PeModule& mod, const std::vector<int>& pattern_bytes) const {
        if (!mod.text_sec) return 0;
        const uint8_t* p = mod.buffer.data() + mod.text_sec->raw_offset;
        const size_t total = mod.text_sec->raw_size;
        const size_t pat_len = pattern_bytes.size();
        if (pat_len == 0 || pat_len > total) return 0;

        const size_t end = total - pat_len;
        for (size_t i = 0; i <= end; ++i) {
            bool found = true;
            for (size_t j = 0; j < pat_len; ++j) {
                if (pattern_bytes[j] != -1 && p[i + j] != static_cast<uint8_t>(pattern_bytes[j])) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return mod.text_sec->raw_offset + static_cast<uint32_t>(i);
            }
        }
        return 0;
    }

    std::vector<SearchResult> search(const std::string& query) {
        std::vector<SearchResult> results;
        std::string q = query;
        std::transform(q.begin(), q.end(), q.begin(), ::tolower);

        // 1. Direct hex RVA (e.g. 0x934CA0)
        if (q.rfind("0x", 0) == 0) {
            try {
                uint32_t rva = static_cast<uint32_t>(std::stoul(q, nullptr, 16));
                auto it = modules.find("client.dll");
                if (it != modules.end()) {
                    uint32_t off = it->second.rva_to_offset(rva);
                    if (off) {
                        results.push_back({ "sub_" + query, "client.dll", "", rva, off, "raw", 0, 0, "Direct RVA input" });
                        return results;
                    }
                }
            } catch (...) {}
        }

        // 2. Search in offsets database
        for (const auto& [name, mod_pair] : offsets_db) {
            std::string lower_name = name;
            std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
            if (lower_name.find(q) != std::string::npos) {
                auto it = modules.find(mod_pair.first);
                if (it != modules.end()) {
                    uint32_t off = it->second.rva_to_offset(mod_pair.second);
                    if (off) {
                        results.push_back({ name, mod_pair.first, "", mod_pair.second, off, "raw", 0, 0,
                            "Found in offsets.h (" + mod_pair.first + ")" });
                    }
                }
            }
        }

        // 3. Search in existing signatures
        for (const auto& [name, sig] : existing_sigs) {
            std::string lower_name = name;
            std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
            if (lower_name.find(q) != std::string::npos) {
                auto it = modules.find(sig.module_name);
                if (it != modules.end()) {
                    auto pat_bytes = parse_pattern(sig.pattern);
                    uint32_t foff = find_pattern_offset(it->second, pat_bytes);
                    if (foff) {
                        uint32_t rva = it->second.offset_to_rva(foff);
                        results.push_back({ name, sig.module_name, sig.pattern, rva, foff, sig.resolve_kind, sig.rel_offset, sig.extra_offset,
                            "Existing signature in signatures.cpp (Found at 0x" + to_hex(rva) + ")" });
                    }
                }
            }
        }

        // 4. Search strings across client.dll & engine2.dll
        const std::vector<std::string> search_mods = { "client.dll", "engine2.dll", "scenesystem.dll", "tier0.dll" };
        for (const auto& mname : search_mods) {
            auto it = modules.find(mname);
            if (it == modules.end()) continue;

            auto hits = it->second.find_string(query);
            for (auto s_off : hits) {
                uint32_t s_rva = it->second.offset_to_rva(s_off);
                auto xrefs = it->second.find_rip_xrefs(s_rva);
                for (auto xrva : xrefs) {
                    uint32_t b_rva, e_rva;
                    if (it->second.find_function_bounds(xrva, b_rva, e_rva)) {
                        uint32_t off = it->second.rva_to_offset(b_rva);
                        results.push_back({ query, mname, "", b_rva, off, "raw", 0, 0,
                            "String '" + query + "' referenced at 0x" + to_hex(xrva) });
                    }
                }
            }
        }

        return results;
    }

    int count_pattern_matches(const PeModule& mod, const std::vector<int>& pattern_bytes) {
        if (!mod.text_sec) return 0;
        const uint8_t* p = mod.buffer.data() + mod.text_sec->raw_offset;
        const size_t total = mod.text_sec->raw_size;
        const size_t pat_len = pattern_bytes.size();
        if (pat_len == 0 || pat_len > total) return 0;

        int matches = 0;
        const size_t end = total - pat_len;

        for (size_t i = 0; i <= end; ++i) {
            bool found = true;
            for (size_t j = 0; j < pat_len; ++j) {
                if (pattern_bytes[j] != -1 && p[i + j] != static_cast<uint8_t>(pattern_bytes[j])) {
                    found = false;
                    break;
                }
            }
            if (found) {
                ++matches;
                if (matches > 5) break; // fast exit if non-unique
            }
        }
        return matches;
    }

    std::pair<std::string, int> generate_pattern(const PeModule& mod, uint32_t file_offset, size_t max_bytes = 64) {
        const uint8_t* data = mod.buffer.data();
        const size_t total_size = mod.buffer.size();

        std::vector<std::string> tokens;
        std::vector<int> byte_pattern;

        size_t i = 0;
        while (i < max_bytes && (file_offset + i < total_size)) {
            size_t pos = file_offset + i;
            uint8_t b = data[pos];

            // CALL / JMP rel32: E8 / E9 xx xx xx xx -> E8 ? ? ? ?
            if (b == 0xE8 || b == 0xE9) {
                tokens.push_back(to_hex_byte(b));
                byte_pattern.push_back(b);
                for (int k = 0; k < 4; ++k) {
                    tokens.push_back("?");
                    byte_pattern.push_back(-1);
                }
                i += 5;
                continue;
            }

            // Jcc rel32: 0F 80..8F xx xx xx xx -> 0F 8x ? ? ? ?
            if (b == 0x0F && pos + 1 < total_size && data[pos + 1] >= 0x80 && data[pos + 1] <= 0x8F) {
                tokens.push_back("0F");
                tokens.push_back(to_hex_byte(data[pos + 1]));
                byte_pattern.push_back(0x0F);
                byte_pattern.push_back(data[pos + 1]);
                for (int k = 0; k < 4; ++k) {
                    tokens.push_back("?");
                    byte_pattern.push_back(-1);
                }
                i += 6;
                continue;
            }

            // mov eax, imm32 followed by call chkstk: B8 xx xx xx xx E8 yy yy yy yy
            if (b == 0xB8 && pos + 9 < total_size && data[pos + 5] == 0xE8) {
                tokens.push_back("B8");
                byte_pattern.push_back(0xB8);
                for (int k = 0; k < 4; ++k) {
                    tokens.push_back("?");
                    byte_pattern.push_back(-1);
                }
                tokens.push_back("E8");
                byte_pattern.push_back(0xE8);
                for (int k = 0; k < 4; ++k) {
                    tokens.push_back("?");
                    byte_pattern.push_back(-1);
                }
                i += 10;
                continue;
            }

            // sub rsp, imm8: 48 83 EC xx -> 48 83 EC ?
            if (b == 0x48 && pos + 3 < total_size && data[pos + 1] == 0x83 && data[pos + 2] == 0xEC) {
                tokens.push_back("48"); tokens.push_back("83"); tokens.push_back("EC"); tokens.push_back("?");
                byte_pattern.push_back(0x48); byte_pattern.push_back(0x83); byte_pattern.push_back(0xEC); byte_pattern.push_back(-1);
                i += 4;
                continue;
            }

            // sub rsp, imm32: 48 81 EC xx xx xx xx -> 48 81 EC ? ? ? ?
            if (b == 0x48 && pos + 6 < total_size && data[pos + 1] == 0x81 && data[pos + 2] == 0xEC) {
                tokens.push_back("48"); tokens.push_back("81"); tokens.push_back("EC");
                byte_pattern.push_back(0x48); byte_pattern.push_back(0x81); byte_pattern.push_back(0xEC);
                for (int k = 0; k < 4; ++k) {
                    tokens.push_back("?");
                    byte_pattern.push_back(-1);
                }
                i += 7;
                continue;
            }

            // mov [rsp+imm8], reg: 48 89 xx 24 yy -> 48 89 xx 24 ?
            if (b == 0x48 && pos + 4 < total_size && data[pos + 1] == 0x89 && data[pos + 3] == 0x24) {
                tokens.push_back("48"); tokens.push_back("89"); tokens.push_back(to_hex_byte(data[pos + 2]));
                tokens.push_back("24"); tokens.push_back("?");
                byte_pattern.push_back(0x48); byte_pattern.push_back(0x89); byte_pattern.push_back(data[pos + 2]);
                byte_pattern.push_back(0x24); byte_pattern.push_back(-1);
                i += 5;
                continue;
            }

            // lea rbp, [rsp+imm32]: 48 8D AC 24 xx xx xx xx -> 48 8D AC 24 ? ? ? ?
            if (b == 0x48 && pos + 7 < total_size && data[pos + 1] == 0x8D && data[pos + 2] == 0xAC && data[pos + 3] == 0x24) {
                tokens.push_back("48"); tokens.push_back("8D"); tokens.push_back("AC"); tokens.push_back("24");
                byte_pattern.push_back(0x48); byte_pattern.push_back(0x8D); byte_pattern.push_back(0xAC); byte_pattern.push_back(0x24);
                for (int k = 0; k < 4; ++k) {
                    tokens.push_back("?");
                    byte_pattern.push_back(-1);
                }
                i += 8;
                continue;
            }

            // RIP-relative addressing: (REX)? (opcode) ModR/M where (modrm & 0xC7 == 0x05)
            size_t idx_after_rex = pos;
            if (b >= 0x40 && b <= 0x4F) {
                idx_after_rex = pos + 1;
            }

            if (idx_after_rex < total_size) {
                uint8_t op = data[idx_after_rex];
                size_t modrm_idx = idx_after_rex + 1;
                if (op == 0x0F && modrm_idx < total_size) {
                    modrm_idx++;
                }
                if (modrm_idx < total_size) {
                    uint8_t modrm = data[modrm_idx];
                    if ((modrm & 0xC7) == 0x05) { // RIP relative!
                        size_t inst_len = (modrm_idx - pos) + 1 + 4;
                        if (pos + inst_len <= total_size) {
                            for (size_t k = pos; k <= modrm_idx; ++k) {
                                tokens.push_back(to_hex_byte(data[k]));
                                byte_pattern.push_back(data[k]);
                            }
                            for (int k = 0; k < 4; ++k) {
                                tokens.push_back("?");
                                byte_pattern.push_back(-1);
                            }
                            i += inst_len;
                            continue;
                        }
                    }
                }
            }

            // Default byte
            tokens.push_back(to_hex_byte(b));
            byte_pattern.push_back(b);
            i += 1;

            // Check uniqueness in .text (minimum 16 bytes)
            if (tokens.size() >= 16) {
                int matches = count_pattern_matches(mod, byte_pattern);
                if (matches == 1) {
                    while (!tokens.empty() && tokens.back() == "?") {
                        tokens.pop_back();
                    }
                    return { join_tokens(tokens), 1 };
                }
            }
        }

        while (!tokens.empty() && tokens.back() == "?") {
            tokens.pop_back();
        }
        int final_matches = count_pattern_matches(mod, byte_pattern);
        return { join_tokens(tokens), final_matches };
    }

    bool save_or_update_signature(const std::string& name, const std::string& entry_line, std::string& out_msg) {
        std::vector<std::string> candidates = {
            project_dir + "\\src\\sdk\\valve\\signatures\\signatures.cpp",
            ".\\src\\sdk\\valve\\signatures\\signatures.cpp",
            "..\\src\\sdk\\valve\\signatures\\signatures.cpp",
            "src\\sdk\\valve\\signatures\\signatures.cpp"
        };
        std::string sig_path;
        for (const auto& c : candidates) {
            std::error_code ec;
            if (fs::exists(c, ec)) {
                sig_path = fs::canonical(c, ec).string();
                if (!sig_path.empty()) break;
                sig_path = c;
                break;
            }
        }
        if (sig_path.empty()) {
            out_msg = "Nie znaleziono pliku signatures.cpp w zadnej oczekiwanej sciezce!";
            return false;
        }

        std::ifstream in(sig_path, std::ios::binary);
        if (!in.is_open()) {
            out_msg = "Nie mozna otworzyc pliku: " + sig_path;
            return false;
        }

        std::string content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        in.close();

        auto entries_start = content.find("constexpr signature_entry_t entries[]");
        if (entries_start == std::string::npos) {
            out_msg = "Nie znaleziono tablicy 'entries[]' w pliku " + sig_path;
            return false;
        }

        auto entries_end = content.find("};", entries_start);
        if (entries_end == std::string::npos) {
            out_msg = "Nie znaleziono zamkniecia '};' tablicy entries[] w " + sig_path;
            return false;
        }

        std::string target_pattern = "\"" + name + "\"";
        size_t search_pos = entries_start;
        size_t found_entry_pos = std::string::npos;
        while (true) {
            auto pos = content.find(target_pattern, search_pos);
            if (pos == std::string::npos || pos >= entries_end) break;
            found_entry_pos = pos;
            break;
        }

        int target_line_num = 1;
        bool is_update = false;

        if (found_entry_pos != std::string::npos) {
            auto line_start = content.rfind('\n', found_entry_pos);
            if (line_start == std::string::npos || line_start < entries_start) line_start = entries_start;
            else line_start += 1;

            auto line_end = content.find('\n', found_entry_pos);
            if (line_end == std::string::npos || line_end > entries_end) line_end = entries_end;

            for (size_t k = 0; k < line_start; ++k) {
                if (content[k] == '\n') target_line_num++;
            }

            content.replace(line_start, line_end - line_start, entry_line);
            is_update = true;
        } else {
            for (size_t k = 0; k < entries_end; ++k) {
                if (content[k] == '\n') target_line_num++;
            }

            if (entries_end > 0 && content[entries_end - 1] != '\n') {
                content.insert(entries_end, "\n" + entry_line + "\n");
            } else {
                content.insert(entries_end, entry_line + "\n");
            }
            is_update = false;
        }

        std::ofstream out(sig_path, std::ios::binary | std::ios::trunc);
        if (!out.is_open()) {
            out_msg = "Blad zapisu do pliku " + sig_path + " (brak uprawnien lub plik zablokowany)";
            return false;
        }
        out.write(content.data(), content.size());
        out.close();

        if (is_update) {
            out_msg = "Zaktualizowano istniejacy wpis '" + name + "' w linijce " + std::to_string(target_line_num) + " w pliku:\n      " + sig_path;
        } else {
            out_msg = "Dodano nowy wpis '" + name + "' w linijce " + std::to_string(target_line_num) + " w pliku:\n      " + sig_path;
        }
        return true;
    }

    void update_all_signatures() {
        std::cout << "\n======================================================================\n";
        std::cout << "        Rozpoczynam automatyczna aktualizacje wszystkich sygnatur\n";
        std::cout << "======================================================================\n";

        int total = 0;
        int updated = 0;
        int kept = 0;
        int failed = 0;

        for (const auto& name : existing_sigs_order) {
            total++;
            const auto& sig = existing_sigs[name];
            std::cout << "[" << total << "/" << existing_sigs_order.size() << "] " 
                      << name << " (" << sig.module_name << ")... ";

            std::string mod_lower = sig.module_name;
            std::transform(mod_lower.begin(), mod_lower.end(), mod_lower.begin(), ::tolower);

            auto it = modules.find(mod_lower);
            if (it == modules.end()) {
                std::cout << "[BRAK MODULU " << sig.module_name << "]\n";
                failed++;
                continue;
            }

            // Find current location
            auto pat_bytes = parse_pattern(sig.pattern);
            uint32_t foff = find_pattern_offset(it->second, pat_bytes);
            if (foff == 0) {
                // Try fallback search by name or offset
                auto fallback = search(name);
                for (const auto& fb : fallback) {
                    if (fb.module_name == sig.module_name && fb.file_offset != 0) {
                        foff = fb.file_offset;
                        break;
                    }
                }
            }

            if (foff == 0) {
                std::cout << "[NIE ZNALEZIONO W DLL]\n";
                failed++;
                continue;
            }

            uint32_t rva = it->second.offset_to_rva(foff);
            auto [new_pat, match_count] = generate_pattern(it->second, foff, 72);

            std::string final_resolve = sig.resolve_kind;
            int final_rel = sig.rel_offset;
            int final_extra = sig.extra_offset;

            // Auto-detect riprel/rel32 if it was raw but starts with relative instruction
            if (final_resolve == "raw" && new_pat.size() >= 14) {
                if (new_pat.rfind("E8 ?", 0) == 0 || new_pat.rfind("E9 ?", 0) == 0) {
                    final_resolve = "rel32";
                    final_rel = 1;
                } else if (new_pat.rfind("48 8B 05 ?", 0) == 0 || new_pat.rfind("48 8B 0D ?", 0) == 0 ||
                           new_pat.rfind("48 8D 05 ?", 0) == 0 || new_pat.rfind("48 8D 0D ?", 0) == 0 ||
                           new_pat.rfind("48 8D 15 ?", 0) == 0) {
                    final_resolve = "riprel";
                    final_rel = 3;
                }
            }

            if (match_count == 1) {
                std::string new_line = "\t{ \"" + name + "\", \"" + sig.module_name + "\", \"" 
                    + new_pat + "\"sv, signature_resolve_kind::" + final_resolve + ", " 
                    + std::to_string(final_rel) + ", " + std::to_string(final_extra) + " },";

                std::string msg;
                if (save_or_update_signature(name, new_line, msg)) {
                    std::cout << "[OK: 1 MATCH] RVA: 0x" << std::hex << std::uppercase << rva << std::dec << "\n";
                    updated++;
                } else {
                    std::cout << "[BLAD ZAPISU]\n";
                    failed++;
                }
            } else {
                std::cout << "[POMINIETO: " << match_count << " matches]\n";
                kept++;
            }
        }

        std::cout << "\n======================================================================\n";
        std::cout << "Podsumowanie aktualizacji:\n";
        std::cout << "  * Lacznie:               " << total << "\n";
        std::cout << "  * Zaktualizowano (100%): " << updated << "\n";
        std::cout << "  * Pozostawiono:          " << kept << "\n";
        std::cout << "  * Niepowodzenia:         " << failed << "\n";
        std::cout << "======================================================================\n";
    }

private:
    static std::string to_hex_byte(uint8_t b) {
        std::stringstream ss;
        ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
        return ss.str();
    }

    static std::string to_hex(uint32_t val) {
        std::stringstream ss;
        ss << std::uppercase << std::hex << val;
        return ss.str();
    }

    static std::string join_tokens(const std::vector<std::string>& tokens) {
        std::string res;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (i > 0) res += " ";
            res += tokens[i];
        }
        return res;
    }
};

int main(int argc, char** argv) {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "======================================================================\n";
    std::cout << "      CS2 Pattern & Signature Entry Generator (Native C++ CLI)\n";
    std::cout << "======================================================================\n";

    std::string proj_dir = "C:\\Users\\barte\\Desktop\\kolembahook";
    SignatureTool tool(proj_dir);

    std::cout << "[+] Loaded " << tool.modules.size() << " CS2 DLL modules from game directory.\n";
    std::cout << "[+] Loaded " << tool.offsets_db.size() << " offsets from offsets.h / offsets.hpp.\n";
    std::cout << "[+] Loaded " << tool.existing_sigs.size() << " existing signatures from signatures.cpp.\n";
    std::cout << "----------------------------------------------------------------------\n";
    std::cout << "Opcje:\n";
    std::cout << "  * Wpisz nazwe funkcji / offset / string / RVA (np. SetModel, LevelInit, 0x934CA0)\n";
    std::cout << "  * Wpisz 'all' lub 'update', aby automatycznie zaktualizowac WSZYSTKIE sygnatury w signatures.cpp!\n";
    std::cout << "  * Wpisz 'exit', aby zakonczyc.\n";
    std::cout << "----------------------------------------------------------------------\n";

    bool single_arg_mode = false;
    std::string initial_query;
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (i > 1) initial_query += " ";
            initial_query += argv[i];
        }
        single_arg_mode = true;
    }

    std::string query;
    while (true) {
        if (single_arg_mode) {
            query = initial_query;
        } else {
            std::cout << "\nEnter name / query: ";
            if (!std::getline(std::cin, query)) {
                break;
            }
        }

        // Strip BOM and whitespace
        while (!query.empty() && (static_cast<unsigned char>(query.front()) <= 0x20 || static_cast<unsigned char>(query.front()) == 0xEF || static_cast<unsigned char>(query.front()) == 0xBB || static_cast<unsigned char>(query.front()) == 0xBF)) {
            query.erase(query.begin());
        }
        while (!query.empty() && static_cast<unsigned char>(query.back()) <= 0x20) {
            query.pop_back();
        }

        if (query.empty() || query == "exit" || query == "quit" || query == "q") {
            break;
        }

        if (query == "all" || query == "update" || query == "update-all" || query == "--update-all" || query == "-u") {
            tool.update_all_signatures();
            if (single_arg_mode) break;
            continue;
        }

        auto results = tool.search(query);
        if (results.empty()) {
            std::cout << "[-] No matches found for '" << query << "'.\n";
            if (single_arg_mode) break;
            continue;
        }

        // Sort exact matches to front
        std::string lower_query = query;
        std::transform(lower_query.begin(), lower_query.end(), lower_query.begin(), ::tolower);
        std::sort(results.begin(), results.end(), [&](const SearchResult& a, const SearchResult& b) {
            std::string la = a.name; std::transform(la.begin(), la.end(), la.begin(), ::tolower);
            std::string lb = b.name; std::transform(lb.begin(), lb.end(), lb.begin(), ::tolower);
            if (la == lower_query && lb != lower_query) return true;
            if (lb == lower_query && la != lower_query) return false;
            return false;
        });

        std::cout << "\n[+] Found " << results.size() << " potential target(s):\n";
        for (size_t i = 0; i < results.size() && i < 10; ++i) {
            std::cout << "  [" << (i + 1) << "] " << results[i].name << " (" << results[i].module_name 
                      << ") -> RVA: 0x" << std::hex << std::uppercase << results[i].rva << std::dec 
                      << " | " << results[i].detail << "\n";
        }

        size_t chosen_idx = 0;
        if (results.size() > 1 && !single_arg_mode) {
            std::cout << "Select item (1-" << (std::min)(results.size(), size_t(10)) << ") [default: 1]: ";
            std::string choice_str;
            std::getline(std::cin, choice_str);
            if (!choice_str.empty()) {
                try {
                    int c = std::stoi(choice_str);
                    if (c >= 1 && c <= static_cast<int>(results.size())) {
                        chosen_idx = c - 1;
                    }
                } catch (...) {}
            }
        }

        const auto& chosen = results[chosen_idx];
        auto it = tool.modules.find(chosen.module_name);
        if (it == tool.modules.end()) {
            std::cout << "[-] Module " << chosen.module_name << " not loaded.\n";
            if (single_arg_mode) break;
            continue;
        }

        bool is_in_text = false;
        if (it->second.text_sec) {
            uint32_t text_start = it->second.text_sec->virtual_address;
            uint32_t text_end = text_start + it->second.text_sec->virtual_size;
            if (chosen.rva >= text_start && chosen.rva < text_end) {
                is_in_text = true;
            }
        }

        uint32_t scan_file_offset = chosen.file_offset;
        uint32_t target_rva = chosen.rva;
        std::string final_resolve = chosen.resolve_kind;
        int final_rel_off = chosen.rel_offset;
        int final_extra_off = chosen.extra_offset;

        if (!is_in_text) {
            std::cout << "[*] Target RVA 0x" << std::hex << chosen.rva 
                      << " is in data section. Resolving RIP-relative code reference in .text...\n" << std::dec;
            auto xrefs = it->second.find_rip_xrefs(chosen.rva);
            if (!xrefs.empty()) {
                uint32_t xrva = xrefs[0];
                target_rva = xrva;
                scan_file_offset = it->second.rva_to_offset(xrva);
                final_resolve = "riprel";
                final_rel_off = 3;
                final_extra_off = 0;
                std::cout << "[+] Found code reference at RVA 0x" << std::hex << std::uppercase << xrva << std::dec << "\n";
            } else {
                std::cout << "[-] No RIP references found to 0x" << std::hex << chosen.rva << std::dec << " in .text.\n";
            }
        }

        std::cout << "\n[*] Generating unique AOB pattern for '" << chosen.name << "' at RVA 0x" 
                  << std::hex << std::uppercase << target_rva << std::dec << "...\n";

        auto [pattern, matches] = tool.generate_pattern(it->second, scan_file_offset);

        std::cout << "\n======================================================================\n";
        if (matches == 1) {
            std::cout << "  Status:  [OK] 100% UNIQUE (1 match in .text)\n";
        } else {
            std::cout << "  Status:  [WARN] " << matches << " matches in .text\n";
        }
        std::cout << "  RVA:     0x" << std::hex << std::uppercase << target_rva << std::dec << "\n";
        std::cout << "  Pattern: " << pattern << "\n";
        std::cout << "======================================================================\n";
        if (final_resolve == "raw" && pattern.size() >= 14) {
            if (pattern.rfind("E8 ?", 0) == 0 || pattern.rfind("E9 ?", 0) == 0) {
                final_resolve = "rel32";
                final_rel_off = 1;
            } else if (pattern.rfind("48 8B 05 ?", 0) == 0 || pattern.rfind("48 8B 0D ?", 0) == 0 ||
                       pattern.rfind("48 8D 05 ?", 0) == 0 || pattern.rfind("48 8D 0D ?", 0) == 0 ||
                       pattern.rfind("48 8D 15 ?", 0) == 0) {
                final_resolve = "riprel";
                final_rel_off = 3;
            }
        }

        std::cout << "\n--> Gotowa linijka do signatures.cpp:\n";
        std::string entry_code = "\t{ \"" + chosen.name + "\", \"" + chosen.module_name + "\", \"" 
                  + pattern + "\"sv, signature_resolve_kind::" + final_resolve + ", " 
                  + std::to_string(final_rel_off) + ", " + std::to_string(final_extra_off) + " },";
        std::cout << entry_code << "\n";
        std::cout << "======================================================================\n";

        if (!single_arg_mode) {
            std::cout << "Zapisac / zaktualizowac w signatures.cpp? (t/N): ";
            std::string append_choice;
            std::getline(std::cin, append_choice);
            if (append_choice == "t" || append_choice == "T" || append_choice == "y" || append_choice == "Y") {
                std::string msg;
                if (tool.save_or_update_signature(chosen.name, entry_code, msg)) {
                    std::cout << "[+] " << msg << "\n";
                } else {
                    std::cout << "[-] " << msg << "\n";
                }
            }
        }

        if (single_arg_mode) {
            break;
        }
    }

    return 0;
}
