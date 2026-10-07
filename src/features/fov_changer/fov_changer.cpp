#include "fov_changer.hpp"
#include "../../core/main.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include <cmath>

namespace fov_changer {
    bool should_override_world_fov() {
        if (!g_cfg || !g_cfg->fov_changer.m_enabled || !g_ctx || !valid_ptr(g_ctx->m_local_pawn))
            return false;

        auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
        __try {
            return local_pawn->is_alive() && !local_pawn->m_scoped();
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            return false;
        }
    }

    std::uint32_t get_world_fov_value() {
        const float fov = g_cfg ? g_cfg->fov_changer.m_fov : 90.0f;
        return static_cast<std::uint32_t>(std::lround(std::clamp(fov, 1.0f, 180.0f)));
    }
}
