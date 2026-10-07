#pragma once

#include "../../config.hpp"

class c_user_cmd;

class c_jump_bug {
public:
	void initialize();
	void shutdown();
	bool run(c_user_cmd* cmd);

private:
	void reset();
	bool bind_active();

	bool m_bind_was_down = false;
	bool m_toggle_active = false;
};

inline const auto g_jump_bug = std::make_unique<c_jump_bug>();
