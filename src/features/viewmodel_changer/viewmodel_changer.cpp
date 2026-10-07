#include "viewmodel_changer.hpp"
#include "../../core/main.hpp"

namespace viewmodel_changer {
    void apply(uintptr_t viewmodel, float* out_offsets, float* out_fov) {
        (void)viewmodel;
        if (!g_cfg)
            return;

        if (g_cfg->viewmodel.m_enabled && out_fov)
            *out_fov = g_cfg->viewmodel.m_fov;

        if (g_cfg->viewmodel.m_position_enabled && out_offsets) {
            out_offsets[0] += g_cfg->viewmodel.m_offset_x;
            out_offsets[1] += g_cfg->viewmodel.m_offset_y;
            out_offsets[2] += g_cfg->viewmodel.m_offset_z;
        }
    }
}
