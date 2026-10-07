#include "autostrafe.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/interfaces/vtables/i_csgo_input.hpp"
#include "../shared/input_buttons.hpp"
#include <algorithm>
#include <cmath>

void c_autostrafe::run(c_user_cmd* cmd) {
    if (!cmd || !g_cfg || !g_cfg->movement.m_autostrafe)
        return;

    auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
    if (!local_pawn || local_pawn->m_health() <= 0)
        return;

    if (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
        return;

    if (local_pawn->m_flags() & FL_ONGROUND)
        return;

    auto* base = cmd->get_base_cmd();
    if (!base)
        return;

    int mouse_delta = base->has_mousedx() ? base->mousedx() : 0;
    if (mouse_delta == 0 && g_interfaces && g_interfaces->m_csgo_input)
        mouse_delta = g_interfaces->m_csgo_input->mouse_delta_x;

    float left_move = 0.0f;

    if (mouse_delta > 1) {
        left_move = -1.0f;
    } else if (mouse_delta < -1) {
        left_move = 1.0f;
    } else {
        left_move = (cmd->m_command_number % 2 == 0) ? 1.0f : -1.0f;
    }

    base->set_forwardmove(0.0f);
    base->set_leftmove(left_move);

    if (g_interfaces && g_interfaces->m_csgo_input) {
        g_interfaces->m_csgo_input->forward_move = 0.0f;
        g_interfaces->m_csgo_input->left_move = left_move;
    }

    movement_input::set_button(cmd, IN_MOVELEFT, false);
    movement_input::set_button(cmd, IN_MOVERIGHT, false);

    if (left_move > 0.0f) {
        movement_input::set_button(cmd, IN_MOVELEFT, true);
    } else if (left_move < 0.0f) {
        movement_input::set_button(cmd, IN_MOVERIGHT, true);
    }
}
