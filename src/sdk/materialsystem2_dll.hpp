

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::materialsystem2 {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class MaterialParam_t;
    class MaterialParamVector_t;
    class MaterialParamString_t;
    class PostProcessingResource_t;
    class MaterialParamInt_t;
    class PostProcessingVignetteParameters_t;
    class PostProcessingLocalContrastParameters_t;
    class PostProcessingTonemapParameters_t;
    class PostProcessingFogScatteringParameters_t;
    class MaterialParamBuffer_t;
    class MaterialResourceData_t;
    class PostProcessingBloomParameters_t;
    class MaterialParamFloat_t;
    class MaterialParamTexture_t;

    enum class VertJustification_e : std::uint32_t {
        VERT_JUSTIFICATION_TOP = 0x0,
        VERT_JUSTIFICATION_CENTER = 0x1,
        VERT_JUSTIFICATION_BOTTOM = 0x2,
        VERT_JUSTIFICATION_NONE = 0x3,
    };

    enum class LayoutPositionType_e : std::uint32_t {
        LAYOUTPOSITIONTYPE_VIEWPORT_RELATIVE = 0x0,
        LAYOUTPOSITIONTYPE_FRACTIONAL = 0x1,
        LAYOUTPOSITIONTYPE_NONE = 0x2,
    };

    enum class ViewFadeMode_t : std::uint32_t {
        VIEW_FADE_CONSTANT_COLOR = 0x0,
        VIEW_FADE_MODULATE = 0x1,
        VIEW_FADE_MOD2X = 0x2,
    };

    enum class BloomBlendMode_t : std::uint32_t {
        BLOOM_BLEND_ADD = 0x0,
        BLOOM_BLEND_SCREEN = 0x1,
        BLOOM_BLEND_BLUR = 0x2,
    };

    enum class HorizJustification_e : std::uint32_t {
        HORIZ_JUSTIFICATION_LEFT = 0x0,
        HORIZ_JUSTIFICATION_CENTER = 0x1,
        HORIZ_JUSTIFICATION_RIGHT = 0x2,
        HORIZ_JUSTIFICATION_NONE = 0x3,
    };

    class MaterialParamVector_t {
    public:
        SCHEMA_FIELD(::Vector4D                      , m_value                                         , 0x8)
    };

    class PostProcessingTonemapParameters_t {
    public:
        SCHEMA_FIELD(float                           , m_flExposureBias                                , 0x0)
        SCHEMA_FIELD(float                           , m_flShoulderStrength                            , 0x4)
        SCHEMA_FIELD(float                           , m_flLinearStrength                              , 0x8)
        SCHEMA_FIELD(float                           , m_flLinearAngle                                 , 0xC)
        SCHEMA_FIELD(float                           , m_flToeStrength                                 , 0x10)
        SCHEMA_FIELD(float                           , m_flToeNum                                      , 0x14)
        SCHEMA_FIELD(float                           , m_flToeDenom                                    , 0x18)
        SCHEMA_FIELD(float                           , m_flWhitePoint                                  , 0x1C)
        SCHEMA_FIELD(float                           , m_flLuminanceSource                             , 0x20)
        SCHEMA_FIELD(float                           , m_flExposureBiasShadows                         , 0x24)
        SCHEMA_FIELD(float                           , m_flExposureBiasHighlights                      , 0x28)
        SCHEMA_FIELD(float                           , m_flMinShadowLum                                , 0x2C)
        SCHEMA_FIELD(float                           , m_flMaxShadowLum                                , 0x30)
        SCHEMA_FIELD(float                           , m_flMinHighlightLum                             , 0x34)
        SCHEMA_FIELD(float                           , m_flMaxHighlightLum                             , 0x38)
    };

    class MaterialParamBuffer_t {
    public:
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_value                                         , 0x8)
    };

    class PostProcessingBloomParameters_t {
    public:
        SCHEMA_FIELD(BloomBlendMode_t                , m_blendMode                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flBloomStrength                               , 0x4)
        SCHEMA_FIELD(float                           , m_flScreenBloomStrength                         , 0x8)
        SCHEMA_FIELD(float                           , m_flBlurBloomStrength                           , 0xC)
        SCHEMA_FIELD(float                           , m_flBloomThreshold                              , 0x10)
        SCHEMA_FIELD(float                           , m_flBloomThresholdWidth                         , 0x14)
        SCHEMA_FIELD(float                           , m_flSkyboxBloomStrength                         , 0x18)
        SCHEMA_FIELD(float                           , m_flBloomStartValue                             , 0x1C)
        SCHEMA_FIELD(float                           , m_flComputeBloomStrength                        , 0x20)
        SCHEMA_FIELD(float                           , m_flComputeBloomThreshold                       , 0x24)
        SCHEMA_FIELD(float                           , m_flComputeBloomRadius                          , 0x28)
        SCHEMA_FIELD(float                           , m_flComputeBloomEffectsScale                    , 0x2C)
        SCHEMA_FIELD(float                           , m_flComputeBloomLensDirtStrength                , 0x30)
        SCHEMA_FIELD(float                           , m_flComputeBloomLensDirtBlackLevel              , 0x34)
        SCHEMA_FIELD(float                           , m_flBlurWeight                                  , 0x38)
        SCHEMA_FIELD(::Vector                        , m_vBlurTint                                     , 0x4C)
    };

    class MaterialParamInt_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nValue                                        , 0x8)
    };

    class MaterialParamFloat_t {
    public:
        SCHEMA_FIELD(float                           , m_flValue                                       , 0x8)
    };

    class MaterialParamTexture_t {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pValue                                        , 0x8)
    };

    class PostProcessingLocalContrastParameters_t {
    public:
        SCHEMA_FIELD(float                           , m_flLocalContrastStrength                       , 0x0)
        SCHEMA_FIELD(float                           , m_flLocalContrastEdgeStrength                   , 0x4)
        SCHEMA_FIELD(float                           , m_flLocalContrastVignetteStart                  , 0x8)
        SCHEMA_FIELD(float                           , m_flLocalContrastVignetteEnd                    , 0xC)
        SCHEMA_FIELD(float                           , m_flLocalContrastVignetteBlur                   , 0x10)
    };

    class MaterialResourceData_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_materialName                                  , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_shaderName                                    , 0x8)
        SCHEMA_FIELD(CUtlVector<MaterialParamInt_t>  , m_intParams                                     , 0x10)
        SCHEMA_FIELD(CUtlVector<MaterialParamFloat_t>, m_floatParams                                   , 0x28)
        SCHEMA_FIELD(CUtlVector<MaterialParamVector_t>, m_vectorParams                                  , 0x40)
        SCHEMA_FIELD(CUtlVector<MaterialParamTexture_t>, m_textureParams                                 , 0x58)
        SCHEMA_FIELD(CUtlVector<MaterialParamBuffer_t>, m_dynamicParams                                 , 0x70)
        SCHEMA_FIELD(CUtlVector<MaterialParamBuffer_t>, m_dynamicTextureParams                          , 0x88)
        SCHEMA_FIELD(CUtlVector<MaterialParamInt_t>  , m_intAttributes                                 , 0xA0)
        SCHEMA_FIELD(CUtlVector<MaterialParamFloat_t>, m_floatAttributes                               , 0xB8)
        SCHEMA_FIELD(CUtlVector<MaterialParamVector_t>, m_vectorAttributes                              , 0xD0)
        SCHEMA_FIELD(CUtlVector<MaterialParamTexture_t>, m_textureAttributes                             , 0xE8)
        SCHEMA_FIELD(CUtlVector<MaterialParamString_t>, m_stringAttributes                              , 0x100)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_renderAttributesUsed                          , 0x118)
    };

    class MaterialParamString_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_value                                         , 0x8)
    };

    class PostProcessingFogScatteringParameters_t {
    public:
        SCHEMA_FIELD(float                           , m_fRadius                                       , 0x0)
        SCHEMA_FIELD(float                           , m_fScale                                        , 0x4)
        SCHEMA_FIELD(float                           , m_fCubemapScale                                 , 0x8)
        SCHEMA_FIELD(float                           , m_fVolumetricScale                              , 0xC)
        SCHEMA_FIELD(float                           , m_fGradientScale                                , 0x10)
    };

    class PostProcessingResource_t {
    public:
        SCHEMA_FIELD(bool                            , m_bHasTonemapParams                             , 0x0)
        SCHEMA_FIELD(PostProcessingTonemapParameters_t, m_toneMapParams                                 , 0x4)
        SCHEMA_FIELD(bool                            , m_bHasBloomParams                               , 0x40)
        SCHEMA_FIELD(PostProcessingBloomParameters_t , m_bloomParams                                   , 0x44)
        SCHEMA_FIELD(bool                            , m_bHasVignetteParams                            , 0xCC)
        SCHEMA_FIELD(PostProcessingVignetteParameters_t, m_vignetteParams                                , 0xD0)
        SCHEMA_FIELD(bool                            , m_bHasLocalContrastParams                       , 0xF4)
        SCHEMA_FIELD(PostProcessingLocalContrastParameters_t, m_localConstrastParams                          , 0xF8)
        SCHEMA_FIELD(std::int32_t                    , m_nColorCorrectionVolumeDim                     , 0x10C)
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_colorCorrectionVolumeData                     , 0x110)
        SCHEMA_FIELD(bool                            , m_bHasColorCorrection                           , 0x120)
        SCHEMA_FIELD(bool                            , m_bHasFogScatteringParams                       , 0x121)
        SCHEMA_FIELD(PostProcessingFogScatteringParameters_t, m_fogScatteringParams                           , 0x124)
    };

    class MaterialParam_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_name                                          , 0x0)
    };

    class PostProcessingVignetteParameters_t {
    public:
        SCHEMA_FIELD(float                           , m_flVignetteStrength                            , 0x0)
        SCHEMA_FIELD(::Vector2D                      , m_vCenter                                       , 0x4)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0xC)
        SCHEMA_FIELD(float                           , m_flRoundness                                   , 0x10)
        SCHEMA_FIELD(float                           , m_flFeather                                     , 0x14)
        SCHEMA_FIELD(::Vector                        , m_vColorTint                                    , 0x18)
    };

}
