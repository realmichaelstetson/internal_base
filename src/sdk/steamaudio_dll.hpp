

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::steamaudio {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class SteamAudioReverbClusteringSettings_t;
    class SteamAudioCustomDataDimensionsSettings_t;
    class SteamAudioPathSettings_t;
    class CSteamAudioAmbisonicsField;
    class CSteamAudioBakedPathingData;
    class SteamAudioReverbSettings_t;
    class CSteamAudioProbeData;
    class SteamAudioReverbCompressionSettings_t;
    class CSteamAudioBakedMaterialsData;
    class CSteamAudioBakedOcclusionData;
    class CSteamAudioBakedReverbData;
    class CSteamAudioProbeLineSegment;
    class SteamAudioCustomDataOcclusionSettings_t;
    class CSteamAudioBakedDimensionsData;
    class CSteamAudioSceneData;
    class CSteamAudioProbeGrid;
    class CSteamAudioCompressedReverb;

    class SteamAudioCustomDataOcclusionSettings_t {
    public:
        SCHEMA_FIELD(bool                            , m_bEnablePathing                                , 0x0)
        SCHEMA_FIELD(bool                            , m_bEnableReflections                            , 0x1)
        SCHEMA_FIELD(std::int32_t                    , m_nReflectionRays                               , 0x4)
        SCHEMA_FIELD(std::int32_t                    , m_nReflectionBounces                            , 0x8)
    };

    class CSteamAudioBakedDimensionsData {
    public:
        SCHEMA_FIELD(SteamAudioCustomDataDimensionsSettings_t, m_settings                                      , 0x0)
        SCHEMA_FIELD(CSteamAudioProbeData            , m_probes                                        , 0x18)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecInOut                                      , 0x20)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecSize                                       , 0x38)
        SCHEMA_FIELD(CUtlVector<CSteamAudioAmbisonicsField>, m_vecOutsideField                               , 0x50)
        SCHEMA_FIELD(CUtlVector<CSteamAudioAmbisonicsField>, m_vecInsideSmallSizeField                       , 0x68)
        SCHEMA_FIELD(CSteamAudioMovableBakedData<CSteamAudioBakedDimensionsData>, m_movables                                      , 0x80)
    };

    class CSteamAudioBakedPathingData {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nBands                                        , 0x0)
        SCHEMA_FIELD(CSteamAudioProbeData            , m_probes                                        , 0x8)
        SCHEMA_FIELD(CSteamAudioMovableBakedData<CSteamAudioBakedPathingData>, m_movables                                      , 0x10)
    };

    class SteamAudioCustomDataDimensionsSettings_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nAmbisonicsOrderOutsideField                  , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nAmbisonicsOrderInsideSizeField               , 0x4)
        SCHEMA_FIELD(float                           , m_flOutsideThreshold                            , 0x8)
        SCHEMA_FIELD(float                           , m_flSizeThreshold                               , 0xC)
        SCHEMA_FIELD(float                           , m_flInsideThreshold                             , 0x10)
    };

    class CSteamAudioCompressedReverb {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChannels                                     , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nBands                                        , 0x4)
        SCHEMA_FIELD(std::int32_t                    , m_nBins                                         , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nProbes                                       , 0xC)
        SCHEMA_FIELD(CUtlVector<int32>               , m_vecNumSingularValues                          , 0x10)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecDictionary                                 , 0x28)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecCompressedData                             , 0x40)
        SCHEMA_FIELD(IPLCompressedEnergyFields       , m_pCompressedData                               , 0x58)
    };

    class CSteamAudioBakedReverbData {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nBands                                        , 0x0)
        SCHEMA_FIELD(CSteamAudioSceneData            , m_scene                                         , 0x8)
        SCHEMA_FIELD(CSteamAudioProbeData            , m_probes                                        , 0x18)
        SCHEMA_FIELD(CSteamAudioProbeGrid            , m_grid                                          , 0x20)
        SCHEMA_FIELD(SteamAudioReverbSettings_t      , m_reverbSettings                                , 0x78)
        SCHEMA_FIELD(SteamAudioReverbClusteringSettings_t, m_reverbClusteringSettings                      , 0x8C)
        SCHEMA_FIELD(SteamAudioReverbCompressionSettings_t, m_reverbCompressionSettings                     , 0x98)
        SCHEMA_FIELD(CSteamAudioProbeData            , m_clusteredProbes                               , 0xA0)
        SCHEMA_FIELD(CUtlVector<int16>               , m_vecClusterForProbe                            , 0xA8)
        SCHEMA_FIELD(CSteamAudioCompressedReverb     , m_compressedData                                , 0xC0)
        SCHEMA_FIELD(CSteamAudioCompressedReverb     , m_compressedClusteredData                       , 0x120)
        SCHEMA_FIELD(CSteamAudioMovableBakedData<CSteamAudioBakedReverbData>, m_movables                                      , 0x180)
    };

    class CSteamAudioSceneData {
    public:
        SCHEMA_FIELD(IPLScene                        , m_pScene                                        , 0x0)
        SCHEMA_FIELD(IPLStaticMesh                   , m_pStaticMesh                                   , 0x8)
    };

    class CSteamAudioProbeLineSegment {
    public:
        SCHEMA_FIELD(::Vector                        , m_vStart                                        , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vEnd                                          , 0xC)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecIntervals                                  , 0x18)
        SCHEMA_FIELD(CUtlVector<int32>               , m_vecProbeIndices                               , 0x30)
    };

    class SteamAudioPathSettings_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNumVisSamples                                , 0x0)
        SCHEMA_FIELD(float                           , m_flProbeVisRadius                              , 0x4)
        SCHEMA_FIELD(float                           , m_flProbeVisThreshold                           , 0x8)
        SCHEMA_FIELD(float                           , m_flProbePathRange                              , 0xC)
    };

    class CSteamAudioBakedOcclusionData {
    public:
        SCHEMA_FIELD(SteamAudioCustomDataOcclusionSettings_t, m_settings                                      , 0x0)
        SCHEMA_FIELD(CSteamAudioProbeData            , m_probes                                        , 0x10)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecPathingRatio                               , 0x18)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecPathingDeviation                           , 0x30)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecReflectionRatio                            , 0x48)
    };

    class SteamAudioReverbCompressionSettings_t {
    public:
        SCHEMA_FIELD(bool                            , m_bEnableCompression                            , 0x0)
        SCHEMA_FIELD(float                           , m_flQuality                                     , 0x4)
    };

    class CSteamAudioProbeGrid {
    public:
        SCHEMA_FIELD(::AABB_t                        , m_aabb                                          , 0x0)
        SCHEMA_FIELD(float                           , m_flSpacing                                     , 0x18)
        SCHEMA_FIELD(std::int32_t                    , m_nx                                            , 0x1C)
        SCHEMA_FIELD(std::int32_t                    , m_ny                                            , 0x20)
        SCHEMA_FIELD(std::int32_t                    , m_nz                                            , 0x24)
        SCHEMA_FIELD(CUtlVector<CSteamAudioProbeLineSegment>, m_vecLineSegments                               , 0x28)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_vecProbes                                     , 0x40)
    };

    class CSteamAudioProbeData {
    public:
        SCHEMA_FIELD(IPLProbeBatch                   , m_pProbeBatch                                   , 0x0)
    };

    class CSteamAudioAmbisonicsField {
    public:
        SCHEMA_FIELD(CUtlVector<float32>             , m_field                                         , 0x0)
    };

    class SteamAudioReverbClusteringSettings_t {
    public:
        SCHEMA_FIELD(bool                            , m_bEnableClustering                             , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nCubeMapResolution                            , 0x4)
        SCHEMA_FIELD(float                           , m_flDepthThreshold                              , 0x8)
    };

    class SteamAudioReverbSettings_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNumRays                                      , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nNumBounces                                   , 0x4)
        SCHEMA_FIELD(float                           , m_flIRDuration                                  , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nAmbisonicsOrder                              , 0xC)
        SCHEMA_FIELD(bool                            , m_bExportScene                                  , 0x10)
    };

    class CSteamAudioBakedMaterialsData {
    public:
        SCHEMA_FIELD(CSteamAudioProbeData            , m_probes                                        , 0x0)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_vecMaterialTokens                             , 0x8)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecMaterialWeights                            , 0x20)
    };

}
