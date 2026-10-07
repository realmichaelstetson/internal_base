#pragma once

#include "../../sdk/valve/interfaces/vtables/i_csgo_input.hpp"

namespace movement_input {
	inline void set_button_state(c_user_cmd* cmd, std::uint64_t button, c_in_button_state::e_button_state state) {
		if (!cmd)
			return;

		cmd->m_button_state.set_button_state(button, state);

		auto* base_cmd = cmd->get_base_cmd();
		if (!base_cmd)
			return;

		auto* buttons = base_cmd->mutable_buttons_pb();
		if (!buttons)
			return;

		auto sync_mask = [button](std::uint64_t mask, bool enabled) {
			return enabled ? (mask | button) : (mask & ~button);
		};

		buttons->set_buttonstate1(sync_mask(buttons->buttonstate1(), (cmd->m_button_state.m_button_state & button) != 0));
		buttons->set_buttonstate2(sync_mask(buttons->buttonstate2(), (cmd->m_button_state.m_button_state2 & button) != 0));
		buttons->set_buttonstate3(sync_mask(buttons->buttonstate3(), (cmd->m_button_state.m_button_state3 & button) != 0));
	}

	inline void set_button(c_user_cmd* cmd, std::uint64_t button, bool down) {
		set_button_state(
			cmd,
			button,
			down ? c_in_button_state::IN_BUTTON_DOWN : c_in_button_state::IN_BUTTON_UP
		);
	}

	inline void press_button(c_user_cmd* cmd, std::uint64_t button) {
		set_button_state(cmd, button, c_in_button_state::IN_BUTTON_UP_DOWN);
	}

	inline void release_button(c_user_cmd* cmd, std::uint64_t button) {
		set_button_state(cmd, button, c_in_button_state::IN_BUTTON_DOWN_UP);
	}
}
