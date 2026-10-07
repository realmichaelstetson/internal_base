#include "bhop.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/interfaces/vtables/i_csgo_input.hpp"
#include "../../sdk/valve/signatures/signatures.hpp"
#include "../shared/input_buttons.hpp"
#include "../shared/world_trace.hpp"
#include "../../../ui/menu/menu.hpp"
#include <Windows.h>
#include <algorithm>
#include <cmath>
#include <cstdint>

c_subtick_move_step* c_bhop::create_subtick_step(CBaseUserCmdPB* base) {
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

void c_bhop::set_subtick_button(c_subtick_move_step* step, uint64_t button, bool pressed, float when) {
	if (!step)
		return;

	step->n_button = button;
	step->n_has_bits |= 1u;
	step->b_pressed = pressed;
	step->n_has_bits |= 2u;
	step->fl_when = std::clamp(when, 0.0f, 1.0f);
	step->n_has_bits |= 4u;
}

void c_bhop::run(c_user_cmd* cmd) {
	if (!cmd)
		return;

	auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
	if (!local_pawn || local_pawn->m_health() <= 0)
		return;

	if (!g_cfg->movement.m_bhop)
		return;

	const bool menu_capturing = g_menu && g_menu->m_opened;
	const bool holding_jump = (cmd->m_button_state.m_button_state & IN_JUMP) != 0
		|| (!menu_capturing && (GetAsyncKeyState(VK_SPACE) & 0x8000) != 0);

	if (!holding_jump)
		return;

	const int move_type = local_pawn->m_move_type();
	if (move_type == MOVETYPE_LADDER || move_type == MOVETYPE_NOCLIP || move_type == MOVETYPE_OBSERVER)
		return;

	const bool on_ground = (local_pawn->m_flags() & FL_ONGROUND) != 0;

	// Пуленепробиваемый автобхоп. Никакого предсказания приземления и субтиков —
	// именно они изредка давали осечку (тик, где нет ни on_ground, ни near_landing,
	// проскакивал без прыжка).
	//
	// На земле: press_button = IN_BUTTON_UP_DOWN каждый наземный тик — выставляет
	// и state1 (зажато), и state2 (фронт нажатия). Сервер прыгает именно по фронту
	// state2, и так как фронт переиздаётся КАЖДЫЙ наземный тик, пробел никогда не
	// выглядит "зажатым" через границу тика → залипнуть не может.
	// В воздухе: отпускаем, чтобы следующее приземление дало свежий фронт.
	if (on_ground)
		movement_input::press_button(cmd, IN_JUMP);
	else
		movement_input::set_button(cmd, IN_JUMP, false);
}
