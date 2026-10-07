

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::host {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class EmptyTestScript;
    class CAnimScriptBase;

    class EmptyTestScript {
    public:
        SCHEMA_FIELD(CAnimScriptParam<float32>       , m_hTest                                         , 0x10)
    };

    class CAnimScriptBase {
    public:
        SCHEMA_FIELD(bool                            , m_bIsValid                                      , 0x8)
    };

}
