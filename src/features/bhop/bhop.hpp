#pragma once
#include "../../config.hpp"

#include <cstdint>

class c_user_cmd;
class CBaseUserCmdPB;

// Internal engine subtick move step (NOT the protobuf CSubtickMoveStep).
// QueueForceSubtickMove allocates and returns one of these.
struct c_subtick_move_step {
    uint32_t n_has_bits;
    uint32_t n_cached_bits;
    uint64_t n_button;
    bool     b_pressed;
    float    fl_when;
    float    fl_analog_forward_delta;
    float    fl_analog_left_delta;
};

class c_bhop {
public:
	void run(c_user_cmd* cmd);

private:
	c_subtick_move_step* create_subtick_step(CBaseUserCmdPB* base);
	void set_subtick_button(c_subtick_move_step* step, uint64_t button, bool pressed, float when);
};

inline const auto g_bhop = std::make_unique<c_bhop>();
