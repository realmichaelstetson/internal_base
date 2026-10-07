

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::resourcesystem {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class InfoForResourceTypeCResponseRulesList;
    class InfoForResourceTypeCDotaItemDefinitionResource;
    class InfoForResourceTypeCMorphSetData;
    class InfoForResourceTypeCVSoundStackScriptList;
    class PackedAABB_t;
    class InfoForResourceTypeCVPhysXSurfacePropertiesList;
    class InfoForResourceTypeManifestTestResource_t;
    class ConstantInfo_t;
    class FuseFunctionIndex_t;
    class InfoForResourceTypeCGcExportableExternalData;
    class InfoForResourceTypeIAnimGraphModelBinding;
    class InfoForResourceTypeCJavaScriptResource;
    class CFuseSymbolTable;
    class InfoForResourceTypeCRenderMesh;
    class InfoForResourceTypeCVoxelVisibility;
    class InfoForResourceTypeCPhysAggregateData;
    class InfoForResourceTypeCNmClip;
    class InfoForResourceTypeWorld_t;
    class InfoForResourceTypeProceduralTestResource_t;
    class AABB_t;
    class InfoForResourceTypeCPostProcessingResource;
    class VariableInfo_t;
    class InfoForResourceTypeIParticleSnapshot;
    class FourQuaternions;
    class InfoForResourceTypeCPanoramaLayout;
    class InfoForResourceTypeCTypeScriptResource;
    class InfoForResourceTypeCChoreoSceneResource;
    class InfoForResourceTypeCNmSkeleton;
    class InfoForResourceTypeCTestResourceData;
    class InfoForResourceTypeCAnimationGroup;
    class InfoForResourceTypeCVSoundEventScriptList;
    class InfoForResourceTypeCVoiceContainerBase;
    class InfoForResourceTypeCPanoramaStyle;
    class InfoForResourceTypeCWorldNode;
    class InfoForResourceTypeCSurfaceGraph;
    class InfoForResourceTypeCCSGOEconItem;
    class InfoForResourceTypeCNmGraphDefinition;
    class InfoForResourceTypeCSmartProp;
    class CFuseProgram;
    class InfoForResourceTypeCCompositeMaterialKit;
    class InfoForResourceTypeCVMixListResource;
    class InfoForResourceTypeCAnimData;
    class InfoForResourceTypeIMaterial2;
    class InfoForResourceTypeIVectorGraphic;
    class InfoForResourceTypeCPanoramaDynamicImages;
    class InfoForResourceTypeIPulseGraphDef;
    class InfoForResourceTypeCVDataItemDefs;
    class FunctionInfo_t;
    class InfoForResourceTypeCVDataResource;
    class InfoForResourceTypeCModel;
    class InfoForResourceTypeCDOTANovelsList;
    class InfoForResourceTypeCTextureBase;
    class FuseVariableIndex_t;
    class InfoForResourceTypeIParticleSystemDefinition;
    class InfoForResourceTypeCSequenceGroupData;
    class ManifestTestResource_t;
    class InfoForResourceTypeCEntityLump;
    class InfoForResourceTypeCDOTAPatchNotesList;

    enum class FuseVariableType_t : std::uint8_t {
        INVALID = 0x0,
        BOOL = 0x1,
        INT8 = 0x2,
        INT16 = 0x3,
        INT32 = 0x4,
        UINT8 = 0x5,
        UINT16 = 0x6,
        UINT32 = 0x7,
        FLOAT32 = 0x8,
    };

    enum class FuseVariableAccess_t : std::uint8_t {
        WRITABLE = 0x0,
        READ_ONLY = 0x1,
    };

    class InfoForResourceTypeWorld_t {
    public:
    };

    class InfoForResourceTypeCChoreoSceneResource {
    public:
    };

    class InfoForResourceTypeCVoiceContainerBase {
    public:
    };

    class InfoForResourceTypeCTestResourceData {
    public:
    };

    class InfoForResourceTypeCWorldNode {
    public:
    };

    class InfoForResourceTypeCSurfaceGraph {
    public:
    };

    class InfoForResourceTypeCPanoramaLayout {
    public:
    };

    class InfoForResourceTypeCNmClip {
    public:
    };

    class InfoForResourceTypeProceduralTestResource_t {
    public:
    };

    class InfoForResourceTypeCAnimData {
    public:
    };

    class AABB_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMinBounds                                    , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vMaxBounds                                    , 0xC)
    };

    class FunctionInfo_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_name                                          , 0x8)
        SCHEMA_FIELD(CUtlStringToken                 , m_nameToken                                     , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nParamCount                                   , 0x14)
        SCHEMA_FIELD(FuseFunctionIndex_t             , m_nIndex                                        , 0x18)
        SCHEMA_FIELD(bool                            , m_bIsPure                                       , 0x1A)
    };

    class InfoForResourceTypeCVPhysXSurfacePropertiesList {
    public:
    };

    class InfoForResourceTypeCDOTAPatchNotesList {
    public:
    };

    class InfoForResourceTypeCGcExportableExternalData {
    public:
    };

    class InfoForResourceTypeCVoxelVisibility {
    public:
    };

    class InfoForResourceTypeCCSGOEconItem {
    public:
    };

    class InfoForResourceTypeIVectorGraphic {
    public:
    };

    class InfoForResourceTypeCMorphSetData {
    public:
    };

    class InfoForResourceTypeIAnimGraphModelBinding {
    public:
    };

    class PackedAABB_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nPackedMin                                    , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nPackedMax                                    , 0x4)
    };

    class InfoForResourceTypeIPulseGraphDef {
    public:
    };

    class InfoForResourceTypeCModel {
    public:
    };

    class FourQuaternions {
    public:
        SCHEMA_FIELD(fltx4                           , x                                               , 0x0)
        SCHEMA_FIELD(fltx4                           , y                                               , 0x10)
        SCHEMA_FIELD(fltx4                           , z                                               , 0x20)
        SCHEMA_FIELD(fltx4                           , w                                               , 0x30)
    };

    class InfoForResourceTypeCVMixListResource {
    public:
    };

    class InfoForResourceTypeCVDataResource {
    public:
    };

    class InfoForResourceTypeCNmSkeleton {
    public:
    };

    class InfoForResourceTypeCEntityLump {
    public:
    };

    class InfoForResourceTypeCSmartProp {
    public:
    };

    class InfoForResourceTypeCDOTANovelsList {
    public:
    };

    class InfoForResourceTypeIParticleSnapshot {
    public:
    };

    class InfoForResourceTypeCAnimationGroup {
    public:
    };

    class CFuseProgram {
    public:
        SCHEMA_FIELD(CUtlVector<uint8>               , m_programBuffer                                 , 0x0)
        SCHEMA_FIELD(CUtlVector<FuseVariableIndex_t> , m_variablesRead                                 , 0x18)
        SCHEMA_FIELD(CUtlVector<FuseVariableIndex_t> , m_variablesWritten                              , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxTempVarsUsed                              , 0x48)
    };

    class InfoForResourceTypeCTextureBase {
    public:
    };

    class FuseVariableIndex_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_Value                                         , 0x0)
    };

    class InfoForResourceTypeCVSoundStackScriptList {
    public:
    };

    class InfoForResourceTypeCSequenceGroupData {
    public:
    };

    class InfoForResourceTypeCCompositeMaterialKit {
    public:
    };

    class InfoForResourceTypeCJavaScriptResource {
    public:
    };

    class InfoForResourceTypeCPanoramaDynamicImages {
    public:
    };

    class CFuseSymbolTable {
    public:
        using _Type0 = CUtlHashtable<CUtlStringToken,int32>;
        using _Type1 = CUtlHashtable<CUtlStringToken,int32>;
        using _Type2 = CUtlHashtable<CUtlStringToken,int32>;
        SCHEMA_FIELD(CUtlVector<ConstantInfo_t>      , m_constants                                     , 0x0)
        SCHEMA_FIELD(CUtlVector<VariableInfo_t>      , m_variables                                     , 0x18)
        SCHEMA_FIELD(CUtlVector<FunctionInfo_t>      , m_functions                                     , 0x30)
        SCHEMA_FIELD(_Type0                          , m_constantMap                                   , 0x48)
        SCHEMA_FIELD(_Type1                          , m_variableMap                                   , 0x68)
        SCHEMA_FIELD(_Type2                          , m_functionMap                                   , 0x88)
    };

    class InfoForResourceTypeIMaterial2 {
    public:
    };

    class InfoForResourceTypeCVSoundEventScriptList {
    public:
    };

    class InfoForResourceTypeCNmGraphDefinition {
    public:
    };

    class InfoForResourceTypeIParticleSystemDefinition {
    public:
    };

    class ConstantInfo_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_name                                          , 0x0)
        SCHEMA_FIELD(CUtlStringToken                 , m_nameToken                                     , 0x8)
        SCHEMA_FIELD(float                           , m_flValue                                       , 0xC)
    };

    class InfoForResourceTypeCDotaItemDefinitionResource {
    public:
    };

    class InfoForResourceTypeManifestTestResource_t {
    public:
    };

    class InfoForResourceTypeCRenderMesh {
    public:
    };

    class InfoForResourceTypeCPostProcessingResource {
    public:
    };

    class VariableInfo_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_name                                          , 0x0)
        SCHEMA_FIELD(CUtlStringToken                 , m_nameToken                                     , 0x8)
        SCHEMA_FIELD(FuseVariableIndex_t             , m_nIndex                                        , 0xC)
        SCHEMA_FIELD(std::uint8_t                    , m_nNumComponents                                , 0xE)
        SCHEMA_FIELD(FuseVariableType_t              , m_eVarType                                      , 0xF)
        SCHEMA_FIELD(FuseVariableAccess_t            , m_eAccess                                       , 0x10)
    };

    class InfoForResourceTypeCTypeScriptResource {
    public:
    };

    class InfoForResourceTypeCVDataItemDefs {
    public:
    };

    class ManifestTestResource_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_name                                          , 0x0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeManifestTestResource_t>, m_child                                         , 0x8)
    };

    class FuseFunctionIndex_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_Value                                         , 0x0)
    };

    class InfoForResourceTypeCPhysAggregateData {
    public:
    };

    class InfoForResourceTypeCPanoramaStyle {
    public:
    };

    class InfoForResourceTypeCResponseRulesList {
    public:
    };

}
