#pragma once
#include "../../config.hpp"
#include <cstdint>
#include <memory>

class c_user_cmd;

class c_mini_jump {
public:
    void run(c_user_cmd* cmd);
};

inline const auto g_mini_jump = std::make_unique<c_mini_jump>();
