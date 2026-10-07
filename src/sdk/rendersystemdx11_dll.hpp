

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::rendersystemdx11 {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class RsDepthStencilStateDesc_t;
    class SheetSequenceIntegerId_t;
    class RsBlendStateDesc_t;
    class VsInputSignatureElement_t;
    class RsRasterizerStateDesc_t;
    class RsStencilStateDesc_t;
    class VsInputSignature_t;
    class RenderInputLayoutField_t;

    enum class RenderPrimitiveType_t : std::uint32_t {
        RENDER_PRIM_POINTS = 0x0,
        RENDER_PRIM_LINES = 0x1,
        RENDER_PRIM_LINES_WITH_ADJACENCY = 0x2,
        RENDER_PRIM_LINE_STRIP = 0x3,
        RENDER_PRIM_LINE_STRIP_WITH_ADJACENCY = 0x4,
        RENDER_PRIM_TRIANGLES = 0x5,
        RENDER_PRIM_TRIANGLES_WITH_ADJACENCY = 0x6,
        RENDER_PRIM_TRIANGLE_STRIP = 0x7,
        RENDER_PRIM_TRIANGLE_STRIP_WITH_ADJACENCY = 0x8,
        RENDER_PRIM_INSTANCED_QUADS = 0x9,
        RENDER_PRIM_HETEROGENOUS = 0xA,
        RENDER_PRIM_COMPUTE_SHADER = 0xB,
        RENDER_PRIM_MESH_SHADER = 0xC,
        RENDER_PRIM_TYPE_COUNT = 0xD,
    };

    enum class RenderBufferFlags_t : std::uint32_t {
        RENDER_BUFFER_USAGE_NONE = 0x0,
        RENDER_BUFFER_USAGE_VERTEX_BUFFER = 0x1,
        RENDER_BUFFER_USAGE_INDEX_BUFFER = 0x2,
        RENDER_BUFFER_USAGE_SHADER_RESOURCE = 0x4,
        RENDER_BUFFER_USAGE_UNORDERED_ACCESS = 0x8,
        RENDER_BUFFER_BYTEADDRESS_BUFFER = 0x10,
        RENDER_BUFFER_STRUCTURED_BUFFER = 0x20,
        RENDER_BUFFER_UAV_DRAW_INDIRECT_ARGS = 0x100,
        RENDER_BUFFER_ACCELERATION_STRUCTURE = 0x200,
        RENDER_BUFFER_SHADER_BINDING_TABLE = 0x400,
        RENDER_BUFFER_POOL_ALLOCATED = 0x800,
        RENDER_BUFFER_USAGE_CONDITIONAL_RENDERING = 0x1000,
        RENDER_BUFFER_IMMOVABLE_ALLOCATION = 0x2000,
    };

    enum class RsCullMode_t : std::uint8_t {
        RS_CULL_NONE = 0x0,
        RS_CULL_BACK = 0x1,
        RS_CULL_FRONT = 0x2,
    };

    enum class RsComparison_t : std::uint8_t {
        RS_CMP_NEVER = 0x0,
        RS_CMP_LESS = 0x1,
        RS_CMP_EQUAL = 0x2,
        RS_CMP_LESS_EQUAL = 0x3,
        RS_CMP_GREATER = 0x4,
        RS_CMP_NOT_EQUAL = 0x5,
        RS_CMP_GREATER_EQUAL = 0x6,
        RS_CMP_ALWAYS = 0x7,
    };

    enum class RsFillMode_t : std::uint8_t {
        RS_FILL_SOLID = 0x0,
        RS_FILL_WIREFRAME = 0x1,
    };

    enum class RenderMultisampleType_t : std::int8_t {
        RENDER_MULTISAMPLE_INVALID = -1,
        RENDER_MULTISAMPLE_NONE = 0x0,
        RENDER_MULTISAMPLE_2X = 0x1,
        RENDER_MULTISAMPLE_4X = 0x2,
        RENDER_MULTISAMPLE_6X = 0x3,
        RENDER_MULTISAMPLE_8X = 0x4,
        RENDER_MULTISAMPLE_16X = 0x5,
        RENDER_MULTISAMPLE_TYPE_COUNT = 0x6,
    };

    enum class InputLayoutVariation_t : std::uint8_t {
        INPUT_LAYOUT_VARIATION_DEFAULT = 0x0,
        INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID = 0x1,
        INPUT_LAYOUT_VARIATION_STREAM1_INSTANCEID_MORPH_VERT_ID = 0x2,
        INPUT_LAYOUT_VARIATION_MAX = 0x3,
    };

    enum class RenderSlotType_t : std::int8_t {
        RENDER_SLOT_INVALID = -1,
        RENDER_SLOT_PER_VERTEX = 0x0,
        RENDER_SLOT_PER_INSTANCE = 0x1,
    };

    class RenderInputLayoutField_t {
    public:
        SCHEMA_FIELD(char                            , m_pSemanticName                                 , 0x0)
        SCHEMA_FIELD(std::int8_t                     , m_nSemanticIndex                                , 0x20)
        SCHEMA_FIELD(std::int16_t                    , m_nOffset                                       , 0x28)
        SCHEMA_FIELD(std::int8_t                     , m_nSlot                                         , 0x2A)
        SCHEMA_FIELD(RenderSlotType_t                , m_nSlotType                                     , 0x2B)
        SCHEMA_FIELD(char                            , m_szShaderSemantic                              , 0x2C)
    };

    class VsInputSignature_t {
    public:
        SCHEMA_FIELD(CUtlVector<VsInputSignatureElement_t>, m_elems                                         , 0x0)
        SCHEMA_FIELD(CUtlVector<VsInputSignatureElement_t>, m_depth_elems                                   , 0x18)
    };

    class RsStencilStateDesc_t {
    public:

        SCHEMA_FIELD(std::uint8_t                    , m_nStencilReadMask                              , 0x4)
        SCHEMA_FIELD(std::uint8_t                    , m_nStencilWriteMask                             , 0x5)
    };

    class RsBlendStateDesc_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_srcBlendBits                                  , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_destBlendBits                                 , 0x4)
        SCHEMA_FIELD(std::uint32_t                   , m_srcBlendAlphaBits                             , 0x8)
        SCHEMA_FIELD(std::uint32_t                   , m_destBlendAlphaBits                            , 0xC)
        SCHEMA_FIELD(std::uint32_t                   , m_renderTargetWriteMaskBits                     , 0x10)

        SCHEMA_FIELD(std::uint32_t                   , m_blendOpAlphaBits                              , 0x18)
        SCHEMA_FIELD(std::uint8_t                    , m_blendEnableBits                               , 0x1C)
        SCHEMA_FIELD(std::uint8_t                    , m_srgbWriteEnableBits                           , 0x1D)
    };

    class SheetSequenceIntegerId_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_Value                                         , 0x0)
    };

    class RsDepthStencilStateDesc_t {
    public:

        SCHEMA_FIELD(RsComparison_t                  , m_depthFunc                                     , 0x1)
        SCHEMA_FIELD(RsStencilStateDesc_t            , m_stencilState                                  , 0x2)
    };

    class VsInputSignatureElement_t {
    public:
        SCHEMA_FIELD(char                            , m_pName                                         , 0x0)
        SCHEMA_FIELD(char                            , m_pSemantic                                     , 0x40)
        SCHEMA_FIELD(char                            , m_pD3DSemanticName                              , 0x80)
        SCHEMA_FIELD(std::int32_t                    , m_nD3DSemanticIndex                             , 0xC0)
    };

    class RsRasterizerStateDesc_t {
    public:
        SCHEMA_FIELD(RsFillMode_t                    , m_nFillMode                                     , 0x0)
        SCHEMA_FIELD(RsCullMode_t                    , m_nCullMode                                     , 0x1)
        SCHEMA_FIELD(bool                            , m_bDepthClipEnable                              , 0x2)
        SCHEMA_FIELD(bool                            , m_bMultisampleEnable                            , 0x3)
        SCHEMA_FIELD(std::int32_t                    , m_nDepthBias                                    , 0x4)
        SCHEMA_FIELD(float                           , m_flDepthBiasClamp                              , 0x8)
        SCHEMA_FIELD(float                           , m_flSlopeScaledDepthBias                        , 0xC)
    };

}
