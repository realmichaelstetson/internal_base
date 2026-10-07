#include "edge_jump.hpp"
#include "../../core/main.hpp"
#include "../../../ui/menu/elements/bind.h"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/signatures/signatures.hpp"
#include "../../utils/utils.hpp"
#include "../shared/input_buttons.hpp"
#include "../shared/world_trace.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <string>

namespace {
    // --- bind key parsing (same scheme as jump_bug) ---------------------------
    std::string normalize_bind_name(std::string key) {
        for (auto& c : key)
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        if (key == "MOUSE1") key = "M1";
        else if (key == "MOUSE2") key = "M2";
        else if (key == "MOUSE3") key = "M3";
        else if (key == "MOUSE4") key = "M4";
        else if (key == "MOUSE5") key = "M5";
        else if (key == "DELETE") key = "DEL";
        else if (key == "INSERT") key = "INS";
        return key;
    }

    int virtual_key_from_bind(std::string key) {
        key = normalize_bind_name(key);
        if (key == "M1") return VK_LBUTTON;
        if (key == "M2") return VK_RBUTTON;
        if (key == "M3") return VK_MBUTTON;
        if (key == "M4") return VK_XBUTTON1;
        if (key == "M5") return VK_XBUTTON2;
        if (key == "ALT") return VK_MENU;
        if (key == "CTRL") return VK_CONTROL;
        if (key == "SHIFT") return VK_SHIFT;
        if (key == "WIN") return VK_LWIN;
        if (key == "DEL") return VK_DELETE;
        if (key == "INS") return VK_INSERT;
        if (key == "SPACE") return VK_SPACE;
        if (key == "TAB") return VK_TAB;
        if (key == "ENTER") return VK_RETURN;
        if (key == "BACKSPACE") return VK_BACK;
        if (key == "HOME") return VK_HOME;
        if (key == "END") return VK_END;
        if (key == "PAGEUP") return VK_PRIOR;
        if (key == "PAGEDOWN") return VK_NEXT;
        if (key.size() == 1 && ((key[0] >= 'A' && key[0] <= 'Z') || (key[0] >= '0' && key[0] <= '9')))
            return key[0];
        if (key.size() >= 2 && key[0] == 'F') {
            const int n = std::atoi(key.c_str() + 1);
            if (n >= 1 && n <= 24)
                return VK_F1 + n - 1;
        }
        return 0;
    }

    bool is_key_down(const std::string& key) {
        const int vk = virtual_key_from_bind(key);
        return vk != 0 && (GetAsyncKeyState(vk) & 0x8000) != 0;
    }

    bool get_origin(c_cs_player_pawn* pawn, vec3_t& origin) {
        __try {
            auto* node = pawn->m_scene_node();
            if (!node)
                return false;
            origin = node->m_abs_origin();
            return true;
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            return false;
        }
    }
}

bool c_edge_jump::bind_active() {
    if (!g_cfg)
        return false;

    const std::string& key = g_cfg->movement.m_edge_jump_key;
    const int mode = g_cfg->movement.m_edge_jump_mode;

    // No key bound -> behave as always on, like a plain toggle feature.
    if (key.empty())
        return true;

    const bool down = is_key_down(key);

    if (mode == static_cast<int>(UI::BindMode::Toggle)) {
        if (down && !m_bind_was_down)
            m_toggle_active = !m_toggle_active;
        m_bind_was_down = down;
        return m_toggle_active;
    }

    m_bind_was_down = down;
    if (mode == static_cast<int>(UI::BindMode::AlwaysOn))
        return true;

    return down;
}

void c_edge_jump::run(c_user_cmd* cmd) {
    if (!cmd || !g_cfg || !g_cfg->movement.m_edge_jump) {
        m_was_on_ground = false;
        m_bind_was_down = false;
        m_toggle_active = false;
        return;
    }

    if (!bind_active()) {
        m_was_on_ground = false;
        return;
    }

    auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
    if (!local_pawn || local_pawn->m_health() <= 0) {
        m_was_on_ground = false;
        return;
    }

    const int move_type = local_pawn->m_move_type();
    if (move_type == MOVETYPE_LADDER || move_type == MOVETYPE_NOCLIP) {
        m_was_on_ground = false;
        return;
    }

    const int flags = local_pawn->m_flags();
    const bool on_ground = (flags & FL_ONGROUND) != 0;
    m_was_on_ground = on_ground;

    // Edge jump only makes sense while still grounded: the server applies +jump
    // only when FL_ONGROUND is set, so we must fire BEFORE we leave the ledge.
    if (!on_ground)
        return;

    const vec3_t velocity = local_pawn->m_vec_abs_velocity();
    const float horiz_speed = velocity.length_2d();
    if (horiz_speed < 5.0f)
        return; // standing still: nothing to walk off

    vec3_t origin{};
    if (!get_origin(local_pawn, origin))
        return;

    // Look a little ahead in the movement direction (~2 ticks of travel),
    // then probe straight down: if there is no ground beneath that point we
    // are about to step off a ledge -> jump now while still on the ground.
    const vec3_t forward = vec3_t(velocity.x, velocity.y, 0.0f).normalize();
    const float look = std::clamp(horiz_speed * (1.0f / 64.0f) * 2.0f, 8.0f, 24.0f);

    constexpr float k_up = 2.0f;          // start slightly above the feet
    constexpr float k_drop_check = 30.0f; // ledge if no floor within this drop

    const vec3_t ahead = origin + forward * look;
    const vec3_t start = vec3_t(ahead.x, ahead.y, ahead.z + k_up);
    const vec3_t delta = vec3_t(0.0f, 0.0f, -(k_up + k_drop_check));

    // Probe straight down through solid world geometry via the shared trace.
    const float frac = world_trace::trace_fraction(
        start, delta, reinterpret_cast<uintptr_t>(local_pawn));

    // frac == 1 -> ray reached the bottom without hitting anything -> ledge ahead.
    if (frac >= 0.999f)
        movement_input::press_button(cmd, IN_JUMP);
}
