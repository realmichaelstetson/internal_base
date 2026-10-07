#pragma once

#include "../../typedefs/vec_t.hpp"

class c_view_setup {
public:
    char pad1[0x450];
    float flOrthoLeft;
    float flOrthoTop;
    float flOrthoRight;
    float flOrthoBottom;
    char pad2[0x38];
    float m_world_fov;
    float m_viewmodel_fov;
    vec3_t m_origin;
    char pad3[0xC];
    vec3_t m_view_angle;
    char pad4[0x14];
    float m_aspect_ratio;
    char pad5[0x79];
    unsigned char m_some_flags;
};
