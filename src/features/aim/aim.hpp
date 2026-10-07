#pragma once

#include "../../config.hpp"

#include <memory>

class c_user_cmd;
class i_csgo_input;
class c_cs_player_pawn;

class c_aim {
public:
	void run(i_csgo_input* input, c_user_cmd* cmd);

private:
	void run_aimbot(i_csgo_input* input, c_user_cmd* cmd, c_cs_player_pawn* local);
	void run_triggerbot(i_csgo_input* input, c_user_cmd* cmd, c_cs_player_pawn* local);

	unsigned long long m_next_trigger_time = 0;
	std::uintptr_t m_trigger_target = 0;
	float m_last_trigger_delay = -1.0f;
	bool m_trigger_was_down = false;
	bool m_auto_scope_active = false;

};

inline const auto g_aim = std::make_unique<c_aim>();
