

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::worldrenderer {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class CEntityInstance;
    class CEntityComponent;
    class CScriptComponent;
    class CEntityIdentity;
    class RTProxyInstanceInfo_t;
    class AggregateVertexAlbedoStreamOnDiskData_t;
    class SceneObject_t;
    class AggregateLODSetup_t;
    class ExtraVertexStreamOverride_t;
    class ClutterTile_t;
    class AggregateSceneObject_t;
    class NodeData_t;
    class VMapResourceData_t;
    class AggregateInstanceStreamOnDiskData_t;
    class RTProxyBLAS_t;
    class ClutterSceneObject_t;
    class WorldBuilderParams_t;
    class PermEntityLumpData_t;
    class WorldNode_t;
    class BaseSceneObjectOverride_t;
    class EntityIOConnectionData_t;
    class BakedLightingInfo_t;
    class VoxelVisBlockOffset_t;
    class InfoForResourceTypeVMapResourceData_t;
    class WorldNodeOnDiskBufferData_t;
    class AggregateMeshInfo_t;
    class World_t;
    class BakedLightingInfo_t_BakedShadowAssignment_t;
    class MaterialOverride_t;
    class AggregateRTProxySceneObject_t;
    class EntityKeyValueData_t;
    class CVoxelVisibility;

    enum class RTProxyInstanceFlags_t : std::uint8_t {
        RTPROXY_INSTANCE_FLAG_NONE = 0x0,
        RTPROXY_INSTANCE_UNIQUE_MESH = 0x1,
    };

    enum class ObjectTypeFlags_t : std::uint32_t {
        OBJECT_TYPE_NONE = 0x0,
        OBJECT_TYPE_MODEL = 0x8,
        OBJECT_TYPE_BLOCK_LIGHT = 0x10,
        OBJECT_TYPE_NO_SHADOWS = 0x20,
        OBJECT_TYPE_WORLDSPACE_TEXURE_BLEND = 0x40,
        OBJECT_TYPE_DISABLED_IN_LOW_QUALITY = 0x80,
        OBJECT_TYPE_RENDER_WITH_DYNAMIC = 0x200,
        OBJECT_TYPE_RENDER_TO_CUBEMAPS = 0x400,
        OBJECT_TYPE_MODEL_HAS_LODS = 0x800,
        OBJECT_TYPE_OVERLAY = 0x2000,
        OBJECT_TYPE_PRECOMPUTED_VISMEMBERS = 0x4000,
        OBJECT_TYPE_STATIC_CUBE_MAP = 0x8000,
        OBJECT_TYPE_DISABLE_VIS_CULLING = 0x10000,
        OBJECT_TYPE_BAKED_GEOMETRY = 0x20000,
        OBJECT_TYPE_NEEDS_DYNAMIC_SHADOWS = 0x40000,
        OBJECT_TYPE_HAS_AGGREGATE_RTPROXY = 0x80000,
    };

    enum class AggregateInstanceStream_t : std::uint8_t {
        AGGREGATE_INSTANCE_STREAM_NONE = 0x0,
        AGGREGATE_INSTANCE_STREAM_LIGHTMAPUV_UNORM16 = 0x1,
        AGGREGATE_INSTANCE_STREAM_VERTEXTINT_UNORM8 = 0x2,
        AGGREGATE_INSTANCE_STREAM_VERTEXBLEND_UNORM8 = 0x4,
    };

    class World_t {
    public:
        SCHEMA_FIELD(WorldBuilderParams_t            , m_builderParams                                 , 0x0)
        SCHEMA_FIELD(CUtlVector<NodeData_t>          , m_worldNodes                                    , 0x60)
        SCHEMA_FIELD(BakedLightingInfo_t             , m_worldLightingInfo                             , 0x78)
        SCHEMA_FIELD(CUtlVector<CStrongHandleCopyable<InfoForResourceTypeCEntityLump>>, m_entityLumps                                   , 0xC0)
    };

    class BaseSceneObjectOverride_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nSceneObjectIndex                             , 0x0)
    };

    class RTProxyInstanceInfo_t {
    public:
        SCHEMA_FIELD(RTProxyInstanceFlags_t          , m_nFlags                                        , 0x0)
        SCHEMA_FIELD(VertexAlbedoFormat_t            , m_albedoFormat                                  , 0x1)
        SCHEMA_FIELD(std::uint16_t                   , m_nBLASCount                                    , 0x2)
        SCHEMA_FIELD(std::uint32_t                   , m_nBLASIndex                                    , 0x4)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexAlbedoByteOffset                       , 0x8)
        SCHEMA_FIELD(::matrix3x4_t                   , m_mWorldFromLocal                               , 0xC)
    };

    class AggregateVertexAlbedoStreamOnDiskData_t {
    public:
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_BufferData                                    , 0x0)
    };

    class ClutterSceneObject_t {
    public:
        SCHEMA_FIELD(::AABB_t                        , m_Bounds                                        , 0x0)
        SCHEMA_FIELD(ObjectTypeFlags_t               , m_flags                                         , 0x18)
        SCHEMA_FIELD(std::int16_t                    , m_nLayer                                        , 0x1C)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_instancePositions                             , 0x20)
        SCHEMA_FIELD(CUtlVector<float32>             , m_instanceScales                                , 0x50)
        SCHEMA_FIELD(CUtlVector<Color>               , m_instanceTintSrgb                              , 0x68)
        SCHEMA_FIELD(CUtlVector<ClutterTile_t>       , m_tiles                                         , 0x80)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_renderableModel                               , 0x98)
        SCHEMA_FIELD(CUtlStringToken                 , m_materialGroup                                 , 0xA0)
        SCHEMA_FIELD(float                           , m_flBeginCullSize                               , 0xA4)
        SCHEMA_FIELD(float                           , m_flEndCullSize                                 , 0xA8)
    };

    class EntityIOConnectionData_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_outputName                                    , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_targetType                                    , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_targetName                                    , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_inputName                                     , 0x18)
        SCHEMA_FIELD(::CUtlString                    , m_overrideParam                                 , 0x20)
        SCHEMA_FIELD(float                           , m_flDelay                                       , 0x28)
        SCHEMA_FIELD(std::int32_t                    , m_nTimesToFire                                  , 0x2C)
        SCHEMA_FIELD(KeyValues3                      , m_paramMap                                      , 0x30)
    };

    class SceneObject_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nObjectID                                     , 0x0)
        SCHEMA_FIELD(::Vector4D                      , m_vTransform                                    , 0x4)
        SCHEMA_FIELD(float                           , m_flFadeStartDistance                           , 0x34)
        SCHEMA_FIELD(float                           , m_flFadeEndDistance                             , 0x38)
        SCHEMA_FIELD(::Vector4D                      , m_vTintColor                                    , 0x3C)
        SCHEMA_FIELD(::CUtlString                    , m_skin                                          , 0x50)
        SCHEMA_FIELD(ObjectTypeFlags_t               , m_nObjectTypeFlags                              , 0x58)
        SCHEMA_FIELD(::Vector                        , m_vLightingOrigin                               , 0x5C)
        SCHEMA_FIELD(std::int16_t                    , m_nOverlayRenderOrder                           , 0x68)
        SCHEMA_FIELD(std::int16_t                    , m_nLODOverride                                  , 0x6A)
        SCHEMA_FIELD(std::int32_t                    , m_nCubeMapPrecomputedHandshake                  , 0x6C)
        SCHEMA_FIELD(std::int32_t                    , m_nLightProbeVolumePrecomputedHandshake         , 0x70)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_renderableModel                               , 0x78)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCRenderMesh>, m_renderable                                    , 0x80)
    };

    class NodeData_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nParent                                       , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vOrigin                                       , 0x4)
        SCHEMA_FIELD(::Vector                        , m_vMinBounds                                    , 0x10)
        SCHEMA_FIELD(::Vector                        , m_vMaxBounds                                    , 0x1C)
        SCHEMA_FIELD(float                           , m_flMinimumDistance                             , 0x28)
        SCHEMA_FIELD(CUtlVector<int32>               , m_ChildNodeIndices                              , 0x30)
        SCHEMA_FIELD(::CUtlString                    , m_worldNodePrefix                               , 0x48)
    };

    class AggregateInstanceStreamOnDiskData_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_DecodedSize                                   , 0x0)
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_BufferData                                    , 0x8)
    };

    class VoxelVisBlockOffset_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nOffset                                       , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nElementCount                                 , 0x4)
    };

    class InfoForResourceTypeVMapResourceData_t {
    public:
    };

    class CEntityComponent {
    public:
    };

    class AggregateSceneObject_t {
    public:
        SCHEMA_FIELD(ObjectTypeFlags_t               , m_allFlags                                      , 0x0)
        SCHEMA_FIELD(ObjectTypeFlags_t               , m_anyFlags                                      , 0x4)
        SCHEMA_FIELD(std::int16_t                    , m_nLayer                                        , 0x8)
        SCHEMA_FIELD(std::int16_t                    , m_instanceStream                                , 0xA)
        SCHEMA_FIELD(std::int16_t                    , m_vertexAlbedoStream                            , 0xC)
        SCHEMA_FIELD(CUtlVector<AggregateMeshInfo_t> , m_aggregateMeshes                               , 0x10)
        SCHEMA_FIELD(CUtlVector<AggregateLODSetup_t> , m_lodSetups                                     , 0x28)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_visClusterMembership                          , 0x40)
        SCHEMA_FIELD(CUtlVector<matrix3x4_t>         , m_fragmentTransforms                            , 0x58)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_renderableModel                               , 0x70)
    };

    class RTProxyBLAS_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nFirstIndex                                   , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nIndexCount                                   , 0x4)
        SCHEMA_FIELD(std::uint32_t                   , m_nVBByteOffset                                 , 0x8)
        SCHEMA_FIELD(std::uint32_t                   , m_nBaseVertex                                   , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , m_nVertexCount                                  , 0x10)
        SCHEMA_FIELD(VertexAlbedoFormat_t            , m_albedoFormat                                  , 0x12)
        SCHEMA_FIELD(::AABB_t                        , m_boundLs                                       , 0x14)
        SCHEMA_FIELD(::Vector                        , m_vVertexOriginLs                               , 0x2C)
        SCHEMA_FIELD(::Vector                        , m_vVertexExtentLs                               , 0x38)
    };

    class AggregateMeshInfo_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nVisClusterMemberOffset                       , 0x0)
        SCHEMA_FIELD(std::uint8_t                    , m_nVisClusterMemberCount                        , 0x4)
        SCHEMA_FIELD(bool                            , m_bHasTransform                                 , 0x5)
        SCHEMA_FIELD(std::uint8_t                    , m_nLODGroupMask                                 , 0x6)
        SCHEMA_FIELD(std::int16_t                    , m_nDrawCallIndex                                , 0x8)
        SCHEMA_FIELD(std::int16_t                    , m_nLODSetupIndex                                , 0xA)
        SCHEMA_FIELD(::Color                         , m_vTintColor                                    , 0xC)
        SCHEMA_FIELD(ObjectTypeFlags_t               , m_objectFlags                                   , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nLightProbeVolumePrecomputedHandshake         , 0x14)
        SCHEMA_FIELD(std::uint32_t                   , m_nInstanceStreamOffset                         , 0x18)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexAlbedoStreamOffset                     , 0x1C)
        SCHEMA_FIELD(AggregateInstanceStream_t       , m_instanceStreams                               , 0x20)
    };

    class MaterialOverride_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nSubSceneObject                               , 0x4)
        SCHEMA_FIELD(std::uint32_t                   , m_nDrawCallIndex                                , 0x8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_pMaterial                                     , 0x10)
        SCHEMA_FIELD(::Vector                        , m_vLinearTintColor                              , 0x18)
    };

    class BakedLightingInfo_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nLightmapVersionNumber                        , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nLightmapGameVersionNumber                    , 0x4)
        SCHEMA_FIELD(::Vector2D                      , m_vLightmapUvScale                              , 0x8)
        SCHEMA_FIELD(bool                            , m_bHasLightmaps                                 , 0x10)
        SCHEMA_FIELD(bool                            , m_bBakedShadowsGamma20                          , 0x11)
        SCHEMA_FIELD(bool                            , m_bCompressionEnabled                           , 0x12)
        SCHEMA_FIELD(bool                            , m_bSHLightmaps                                  , 0x13)
        SCHEMA_FIELD(std::uint8_t                    , m_nChartPackIterations                          , 0x14)
        SCHEMA_FIELD(std::uint8_t                    , m_nVradQuality                                  , 0x15)
        SCHEMA_FIELD(CUtlVector<CStrongHandle<InfoForResourceTypeCTextureBase>>, m_lightMaps                                     , 0x18)
        SCHEMA_FIELD(CUtlVector<BakedLightingInfo_t_BakedShadowAssignment_t>, m_bakedShadows                                  , 0x30)
    };

    class AggregateRTProxySceneObject_t {
    public:
        SCHEMA_FIELD(std::int16_t                    , m_nLayer                                        , 0x0)
        SCHEMA_FIELD(CUtlVector<RTProxyBLAS_t>       , m_BLASes                                        , 0x8)
        SCHEMA_FIELD(CUtlVector<RTProxyInstanceInfo_t>, m_Instances                                     , 0x20)
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_VBData                                        , 0x38)
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_IBData                                        , 0x48)
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_InstanceAlbedoData                            , 0x58)
    };

    class CEntityIdentity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nameStringTableIndex                          , 0x14)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_name                                          , 0x18)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_designerName                                  , 0x20)
        SCHEMA_FIELD(std::uint32_t                   , m_flags                                         , 0x30)
        SCHEMA_FIELD(::WorldGroupId_t                , m_worldGroupId                                  , 0x38)
        SCHEMA_FIELD(std::uint32_t                   , m_fDataObjectTypes                              , 0x3C)
        SCHEMA_FIELD(::ChangeAccessorFieldPathIndex_t, m_PathIndex                                     , 0x40)
        SCHEMA_FIELD(CEntityAttributeTable*          , m_pAttributes                                   , 0x48)
        SCHEMA_FIELD(CEntityIdentity*                , m_pPrev                                         , 0x50)
        SCHEMA_FIELD(CEntityIdentity*                , m_pNext                                         , 0x58)
        SCHEMA_FIELD(CEntityIdentity*                , m_pPrevByClass                                  , 0x60)
        SCHEMA_FIELD(CEntityIdentity*                , m_pNextByClass                                  , 0x68)
    };

    class VMapResourceData_t {
    public:
    };

    class AggregateLODSetup_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vLODOrigin                                    , 0x0)
        SCHEMA_FIELD(float                           , m_fMaxObjectScale                               , 0xC)
        SCHEMA_FIELD(CUtlVector<float32>             , m_fSwitchDistances                              , 0x10)
    };

    class PermEntityLumpData_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_name                                          , 0x8)
        SCHEMA_FIELD(CUtlVector<CStrongHandleCopyable<InfoForResourceTypeCEntityLump>>, m_childLumps                                    , 0x10)
        SCHEMA_FIELD(CUtlLeanVector<EntityKeyValueData_t>, m_entityKeyValues                               , 0x28)
    };

    class EntityKeyValueData_t {
    public:
        SCHEMA_FIELD(CUtlVector<EntityIOConnectionData_t>, m_connections                                   , 0x8)
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_keyValuesData                                 , 0x20)
    };

    class WorldNodeOnDiskBufferData_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nElementCount                                 , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nElementSizeInBytes                           , 0x4)
        SCHEMA_FIELD(CUtlVector<RenderInputLayoutField_t>, m_inputLayoutFields                             , 0x8)
        SCHEMA_FIELD(CUtlVector<uint8>               , m_pData                                         , 0x20)
    };

    class ExtraVertexStreamOverride_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nSubSceneObject                               , 0x4)
        SCHEMA_FIELD(std::uint32_t                   , m_nDrawCallIndex                                , 0x8)
        SCHEMA_FIELD(MeshDrawPrimitiveFlags_t        , m_nAdditionalMeshDrawPrimitiveFlags             , 0xC)
        SCHEMA_FIELD(::CRenderBufferBinding          , m_extraBufferBinding                            , 0x10)
    };

    class CVoxelVisibility {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nBaseClusterCount                             , 0x40)
        SCHEMA_FIELD(std::uint32_t                   , m_nPVSBytesPerCluster                           , 0x44)
        SCHEMA_FIELD(::Vector                        , m_vMinBounds                                    , 0x48)
        SCHEMA_FIELD(::Vector                        , m_vMaxBounds                                    , 0x54)
        SCHEMA_FIELD(float                           , m_flGridSize                                    , 0x60)
        SCHEMA_FIELD(std::uint32_t                   , m_nSkyVisibilityCluster                         , 0x64)
        SCHEMA_FIELD(std::uint32_t                   , m_nSunVisibilityCluster                         , 0x68)
        SCHEMA_FIELD(VoxelVisBlockOffset_t           , m_NodeBlock                                     , 0x6C)
        SCHEMA_FIELD(VoxelVisBlockOffset_t           , m_RegionBlock                                   , 0x74)
        SCHEMA_FIELD(VoxelVisBlockOffset_t           , m_EnclosedClusterListBlock                      , 0x7C)
        SCHEMA_FIELD(VoxelVisBlockOffset_t           , m_EnclosedClustersBlock                         , 0x84)
        SCHEMA_FIELD(VoxelVisBlockOffset_t           , m_MasksBlock                                    , 0x8C)
        SCHEMA_FIELD(VoxelVisBlockOffset_t           , m_nVisBlocks                                    , 0x94)
    };

    class ClutterTile_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nFirstInstance                                , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nLastInstance                                 , 0x4)
        SCHEMA_FIELD(::AABB_t                        , m_BoundsWs                                      , 0x8)
    };

    class WorldBuilderParams_t {
    public:
        SCHEMA_FIELD(float                           , m_flMinDrawVolumeSize                           , 0x0)
        SCHEMA_FIELD(bool                            , m_bBuildBakedLighting                           , 0x4)
        SCHEMA_FIELD(bool                            , m_bAggregateInstanceStreams                     , 0x5)
        SCHEMA_FIELD(BakedLightingInfo_t             , m_bakedLightingInfo                             , 0x8)
        SCHEMA_FIELD(std::uint64_t                   , m_nCompileTimestamp                             , 0x50)
        SCHEMA_FIELD(std::uint64_t                   , m_nCompileFingerprint                           , 0x58)
    };

    class BakedLightingInfo_t_BakedShadowAssignment_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nLightHash                                    , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nMapHash                                      , 0x4)
        SCHEMA_FIELD(std::int8_t                     , m_nShadowChannel                                , 0x8)
    };

    class WorldNode_t {
    public:
        SCHEMA_FIELD(CUtlVector<SceneObject_t>       , m_sceneObjects                                  , 0x0)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_visClusterMembership                          , 0x18)
        SCHEMA_FIELD(CUtlVector<AggregateSceneObject_t>, m_aggregateSceneObjects                         , 0x30)
        SCHEMA_FIELD(CUtlVector<ClutterSceneObject_t>, m_clutterSceneObjects                           , 0x48)
        SCHEMA_FIELD(CUtlVector<AggregateRTProxySceneObject_t>, m_rtProxies                                     , 0x60)
        SCHEMA_FIELD(CUtlVector<ExtraVertexStreamOverride_t>, m_extraVertexStreamOverrides                    , 0x78)
        SCHEMA_FIELD(CUtlVector<MaterialOverride_t>  , m_materialOverrides                             , 0x90)
        SCHEMA_FIELD(CUtlVector<WorldNodeOnDiskBufferData_t>, m_extraVertexStreams                            , 0xA8)
        SCHEMA_FIELD(CUtlVector<AggregateInstanceStreamOnDiskData_t>, m_aggregateInstanceStreams                      , 0xC0)
        SCHEMA_FIELD(CUtlVector<AggregateVertexAlbedoStreamOnDiskData_t>, m_vertexAlbedoStreams                           , 0xD8)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_layerNames                                    , 0xF0)
        SCHEMA_FIELD(CUtlVector<uint8>               , m_sceneObjectLayerIndices                       , 0x108)
        SCHEMA_FIELD(::CUtlString                    , m_grassFileName                                 , 0x120)
        SCHEMA_FIELD(BakedLightingInfo_t             , m_nodeLightingInfo                              , 0x128)
        SCHEMA_FIELD(bool                            , m_bHasBakedGeometryFlag                         , 0x170)
    };

    class CEntityInstance {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPrivateVScripts                            , 0x8)
        SCHEMA_FIELD(CEntityIdentity*                , m_pEntity                                       , 0x10)
        SCHEMA_FIELD(CScriptComponent*               , m_CScriptComponent                              , 0x28)
    };

    class CScriptComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_scriptClassName                               , 0x30)
    };

}
