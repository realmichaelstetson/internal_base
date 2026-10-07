#pragma once

#include "../../../vfunc/vfunc.hpp"

class i_file_system
{
public:
    bool exists(const char* file_name, const char* path_id)
    {
        return vmt::call_virtual<bool>(this, 21, file_name, path_id);
    }

    void* open(const char* file_name, const char* options, const char* path_id = nullptr)
    {
        return vmt::call_virtual<void*>(this, 13, file_name, options, path_id);
    }

    void close(void* file)
    {
        vmt::call_virtual<void>(this, 14, file);
    }

    unsigned int size(void* file)
    {
        return vmt::call_virtual<unsigned int>(this, 18, file);
    }

    int read(void* output, int size, void* file)
    {
        return vmt::call_virtual<int>(this, 11, output, size, file);
    }
};
