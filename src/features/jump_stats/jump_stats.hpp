#pragma once
#include "../../config.hpp"
#include <cstdint>
#include <memory>

void try_send_chat_safe(const char* message);

class c_jump_stats {
public:
    void run();
};

inline const auto g_jump_stats = std::make_unique<c_jump_stats>();
