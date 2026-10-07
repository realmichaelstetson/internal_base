#pragma once
#include <cstdint>
#include <memory>

class c_user_cmd;

class c_autostrafe {
public:
    void run(c_user_cmd* cmd);
};

inline const auto g_autostrafe = std::make_unique<c_autostrafe>();
