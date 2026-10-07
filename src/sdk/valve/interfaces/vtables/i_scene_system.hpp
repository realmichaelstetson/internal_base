#pragma once

#include <cstdint>

struct scene_system_light_data_t {
    char pad_0000[0x18];
    void* lightData;
};

class c_scene_system {
public:
    char pad_0000[0x2A28];
    scene_system_light_data_t* data;

    void* get_scene_object_desc(const char* desc_name) {
        using fn = void* (__fastcall*)(void*, const char*);
        auto vtable = *reinterpret_cast<void***>(this);
        return reinterpret_cast<fn>(vtable[17])(this, desc_name);
    }
};
