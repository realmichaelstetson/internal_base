#include "jump_stats.hpp"
#include "../../core/main.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include <cstdint>
#include <cmath>

static bool   s_was_on_ground = true;
static vec3_t s_jump_start_pos;

void c_jump_stats::run() {
    if (!g_cfg || !g_cfg->indicators.m_jump_stats)
        return;

    auto* pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
    if (!pawn || !pawn->is_alive()) {
        s_was_on_ground = true;
        return;
    }

    const bool on_ground = (pawn->m_flags() & FL_ONGROUND) != 0;
    auto* node = pawn->m_scene_node();
    if (!node) {
        s_was_on_ground = on_ground;
        return;
    }

    if (!s_was_on_ground && on_ground) {
        const vec3_t diff = node->m_abs_origin() - s_jump_start_pos;
        const float dist = diff.length_2d();
        if (dist > 1.0f) {
            char message[256];
            char menu_col_hex[8];
            const ImVec4 mc = g_cfg->menu.m_menu_color;
            sprintf_s(menu_col_hex, "#%02x%02x%02x", (int)(mc.x * 255.0f), (int)(mc.y * 255.0f), (int)(mc.z * 255.0f));
            sprintf_s(message, "<font color=\"%s\"> celerity </font><font color=\"#c4c4c4\">| jump distance: %.0f units</font>",
                menu_col_hex, dist);
            try_send_chat_safe(message);
        }
    } else if (s_was_on_ground && !on_ground) {
        s_jump_start_pos = node->m_abs_origin();
    }
    s_was_on_ground = on_ground;
}
