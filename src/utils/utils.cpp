#include "../core/main.hpp"

std::vector<int> c_opcodes::ida_to_bytes(const char* pattern)
{
    std::vector<int> bytes = std::vector<int>{};
    char* start = const_cast<char*>(pattern);
    char* end = const_cast<char*>(pattern) + strlen(pattern);

    for (char* current = start; current < end; ++current) {
        if (*current == '?') {
            ++current;

            if (*current == '?')
                ++current;

            bytes.push_back(-1);
        }
        else {
            bytes.push_back(strtoul(current, &current, 16));
        }
    }

    return bytes;
}

uint8_t* c_opcodes::scan(const char* module_name, const char* pattern) {
    void* module_handle = WINCALL(GetModuleHandle)(module_name);
    if (module_handle == nullptr)
        return nullptr;

    PIMAGE_DOS_HEADER dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(module_handle);
    PIMAGE_NT_HEADERS nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<uint8_t*>(module_handle) + dos_header->e_lfanew);

    auto size_of_image = nt_headers->OptionalHeader.SizeOfImage;
    auto pattern_bytes = ida_to_bytes(pattern);
    auto scan_bytes = reinterpret_cast<uint8_t*>(module_handle);

    auto pattern_size = pattern_bytes.size();
    auto pattern_data = pattern_bytes.data();

    for (unsigned int i = 0; i < size_of_image - pattern_size; i++) {
        bool found = true;

        for (unsigned int j = 0; j < pattern_size; ++j) {
            if (pattern_data[j] == -1)
                continue;

            if (scan_bytes[i + j] != pattern_data[j]) {
                found = false;
                break;
            }
        }

        if (found)
            return &scan_bytes[i];
    }
    LOG_ERROR("failed to find pattern: %s", pattern);
    return nullptr;
}

uint8_t* c_opcodes::scan_absolute(const char* module_name, const char* pattern) {
    uint8_t* address = scan(module_name, pattern);
    if (address == nullptr)
        return nullptr;

    return get_absolute_address(address);
}

uint8_t* c_opcodes::scan_absolute(const char* module_name, const char* pattern, int pre_offset) {
    uint8_t* address = scan(module_name, pattern);
    if (address == nullptr)
        return nullptr;

    return get_absolute_address(address, pre_offset);
}

uint8_t* c_opcodes::scan_absolute(const char* module_name, const char* pattern, int pre_offset, int post_offset) {
    uint8_t* address = scan(module_name, pattern);
    if (address == nullptr)
        return nullptr;

    return get_absolute_address(address, pre_offset, post_offset);
}

uint8_t* c_opcodes::get_absolute_address(unsigned char* address, int pre_offset, int post_offset) {
    address += pre_offset;
    address += *reinterpret_cast<std::int32_t*>(address) + 0x4;
    address += post_offset;

    return address;
}

uint8_t* c_opcodes::get_absolute_address(unsigned char* address, int pre_offset) {
    return get_absolute_address(address, pre_offset, 0);
}

uint8_t* c_opcodes::get_absolute_address(unsigned char* address) {
    return get_absolute_address(address, 0, 0);
}
