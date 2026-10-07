

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::networksystem {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class ChangeAccessorFieldPathIndex_t;

    class ChangeAccessorFieldPathIndex_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Value                                         , 0x0)
    };

}
