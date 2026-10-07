#include "mini_jump.hpp"
#include "../../core/main.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../shared/input_buttons.hpp"
#include <cstdint>

void c_mini_jump::run(c_user_cmd* cmd) {
    if (!cmd || !g_cfg || !g_cfg->movement.m_mini_jump)
        return;

    auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
    if (!local_pawn || local_pawn->m_health() <= 0)
        return;

    const int move_type = local_pawn->m_move_type();
    if (move_type == MOVETYPE_LADDER || move_type == MOVETYPE_NOCLIP)
        return;

    const int flags = local_pawn->m_flags();
    const bool on_ground = (flags & FL_ONGROUND) != 0;

    if (!on_ground)
        return;

    const bool holding_jump = (GetAsyncKeyState(VK_SPACE) & 0x8000) != 0;
    if (!holding_jump)
        return;

    movement_input::press_button(cmd, IN_DUCK);
}
