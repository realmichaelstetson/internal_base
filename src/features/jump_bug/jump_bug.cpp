#include "jump_bug.hpp"

#include "../../core/main.hpp"
#include "../../../ui/menu/elements/bind.h"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/signatures/signatures.hpp"
#include "../bhop/bhop.hpp" // c_subtick_move_step
#include "../shared/world_trace.hpp"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <string>

namespace {
	// One server tick at 64 tick.
	constexpr float k_tick_interval = 1.0f / 64.0f;
	// Mirrors sv_standable_normal (default 0.7): a surface counts as ground only
	// if its normal points up enough to stand on. celerity has no convar API.
	constexpr float k_standable_normal = 0.7f;
	// Extra reach added to the per-tick sweep so a floor we contact right at the
	// tick boundary is still caught.
	constexpr float k_sweep_extend = 2.0f;

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

	bool is_bad_move_type(int move_type) {
		return move_type == MOVETYPE_LADDER || move_type == MOVETYPE_NOCLIP;
	}

	// Append a subtick move to the outgoing command via the engine's own
	// QueueForceSubtickMove. This returns the _impl_ of a real protobuf
	// CSubtickMoveStep already placed in the usercmd's subtick_moves repeated
	// field, so filling it here sends the step to the server -- and the game
	// does the (arena-correct) allocation, unlike base->add_subtick_moves()
	// which corrupts the heap on celerity's cmd overlay. Same mechanism bhop
	// uses; kept local so jump_bug is self-contained.
	c_subtick_move_step* queue_subtick(CBaseUserCmdPB* base) {
		if (!base)
			return nullptr;

		using fn_t = c_subtick_move_step* (*)(CBaseUserCmdPB*);
		static fn_t fn = nullptr;
		if (!fn)
			fn = reinterpret_cast<fn_t>(SIG("QueueForceSubtickMove"));
		if (!fn)
			return nullptr;

		__try {
			auto* step = fn(base);
			if (!step || reinterpret_cast<uintptr_t>(step) < 0x10000)
				return nullptr;

			step->n_has_bits = 0;
			step->n_cached_bits = 0;
			step->n_button = 0;
			step->b_pressed = false;
			step->fl_when = 0.0f;
			step->fl_analog_forward_delta = 0.0f;
			step->fl_analog_left_delta = 0.0f;
			return step;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	void set_subtick(c_subtick_move_step* step, uint64_t button, float when, bool pressed) {
		if (!step)
			return;

		step->n_button = button;
		step->n_has_bits |= 1u;
		step->b_pressed = pressed;
		step->n_has_bits |= 2u;
		step->fl_when = std::clamp(when, 0.0f, 1.0f);
		step->n_has_bits |= 4u;
	}
}

void c_jump_bug::initialize() {
	reset();
}

void c_jump_bug::shutdown() {
	reset();
}

void c_jump_bug::reset() {
	m_bind_was_down = false;
	m_toggle_active = false;
}

bool c_jump_bug::bind_active() {
	if (!g_cfg)
		return false;

	const bool down = is_key_down(g_cfg->movement.m_jump_bug_key);
	const int mode = g_cfg->movement.m_jump_bug_mode;

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

bool c_jump_bug::run(c_user_cmd* cmd) {
	if (!cmd || !g_cfg || !g_cfg->movement.m_jump_bug) {
		reset();
		return false;
	}

	if (!bind_active())
		return false;

	auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx ? g_ctx->m_local_pawn : nullptr);
	if (!local_pawn || local_pawn->m_health() <= 0 || is_bad_move_type(local_pawn->m_move_type()))
		return false;

	auto* base = cmd->get_base_cmd();
	if (!base)
		return false;

	auto* node = local_pawn->m_scene_node();
	if (!node)
		return false;

	const vec3_t origin = node->m_abs_origin();
	const vec3_t velocity = local_pawn->m_vec_abs_velocity();
	const auto skip = reinterpret_cast<uintptr_t>(local_pawn);

	// Sweep along this tick's motion (nudged past the boundary) to find the
	// sub-tick moment we contact standable ground. hit.fraction is exactly the
	// `when` the jump must land on. A feet ray stands in for the game's BBox
	// sweep (celerity has no hull trace); for flat landings they coincide.
	vec3_t delta = velocity * k_tick_interval;
	delta.z -= k_sweep_extend;
	const auto hit = world_trace::trace(origin, delta, skip);

	const bool valid_ground =
		hit.fraction > 0.0f && hit.fraction < 1.0f && hit.normal.z >= k_standable_normal;

	const int flags = local_pawn->m_flags();
	const bool on_ground = (flags & FL_ONGROUND) != 0;

	if (!on_ground && !valid_ground)
		return false;

	// The jump MUST fire on the exact contact sub-tick: a whole-tick button is
	// applied at sub-tick 0 while we are still airborne, gets ignored, and the
	// fall lands normally (damage). Sub-tick timing is the whole point.
	const float when = hit.fraction;

	// Duck from the start of the tick, unduck exactly at contact.
	set_subtick(queue_subtick(base), IN_DUCK, 0.0f, true);
	set_subtick(queue_subtick(base), IN_DUCK, when, false);

	// Release-then-press jump at the contact moment -> a clean press edge landing
	// on the ground frame, which fires the jump before the landing is registered.
	set_subtick(queue_subtick(base), IN_JUMP, when, false);
	set_subtick(queue_subtick(base), IN_JUMP, when, true);

	return true;
}
