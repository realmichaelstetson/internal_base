#pragma once
#include "../../config.hpp"
#include <cstdint>
#include <memory>

class c_user_cmd;

class c_edge_jump {
public:
    void run(c_user_cmd* cmd);

private:
    bool bind_active();

    bool m_was_on_ground = false;
    bool m_bind_was_down = false;
    bool m_toggle_active = false;
};

inline const auto g_edge_jump = std::make_unique<c_edge_jump>();
