#pragma once
#include <cstdint>

namespace fov_changer {
    bool should_override_world_fov();
    std::uint32_t get_world_fov_value();
}
