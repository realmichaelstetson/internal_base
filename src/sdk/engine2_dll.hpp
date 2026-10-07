

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::engine2 {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class CEntityInstance;
    class CEntityComponent;
    class CScriptComponent;
    class CEntityIdentity;
    class EventClientPostSimulate_t;
    class EventSimpleLoopFrameUpdate_t;
    class EventPostAdvanceTick_t;
    class CEntityIOOutput;
    class EventClientSceneSystemThreadStateChange_t;
    class EventClientOutput_t;
    class EventServerPostSimulate_t;
    class CEntityComponentHelper;
    class GameTime_t;
    class EventServerBeginSimulate_t;
    class EntityIOQueuePrioritizedEvent_t;
    class EventServerEndAsyncPostTickWork_t;
    class EventClientAdvanceTick_t;
    class EntInput_t;
    class CNetworkVarChainer;
    class EventClientSimulate_t;
    class EventClientPostOutput_t;
    class GameTick_t;
    class EventClientPollInput_t;
    class EventPreDataUpdate_t;
    class EventClientProcessGameInput_t;
    class EventFrameBoundary_t;
    class EventAppShutdown_t;
    class EventServerPostAdvanceTick_t;
    class EventProfileStorageAvailable_t;
    class EventPostDataUpdate_t;
    class EventClientPreSimulate_t;
    class EventClientPauseSimulate_t;
    class EventClientProcessNetworking_t;
    class CEntityAttributeTable;
    class EventClientPreOutputParallelWithServer_t;
    class EventAdvanceTick_t;
    class EventSplitScreenStateChanged_t;
    class EventClientPostAdvanceTick_t;
    class CVariantDefaultAllocator;
    class EventModInitialized_t;
    class EventClientPreOutput_t;
    class EventClientFrameSimulate_t;
    class EventServerAdvanceTick_t;
    class EventSetTime_t;
    class EventSimulate_t;
    class CEntityKeyValues;
    class EventClientAdvanceNonRenderedFrame_t;
    class EventServerProcessNetworking_t;
    class CEmptyEntityInstance;
    class EntComponentInfo_t;
    class EngineLoopState_t;
    class EventClientPollNetworking_t;
    class EventServerBeginAsyncPostTickWork_t;
    class EventClientProcessInput_t;
    class EventServerEndSimulate_t;
    class EventServerPollNetworking_t;

    enum class EntityDormancyType_t : std::uint32_t {
        ENTITY_NOT_DORMANT = 0x0,
        ENTITY_DORMANT = 0x1,
        ENTITY_SUSPENDED = 0x2,
    };

    enum class EntityIOTargetType_t : std::int32_t {
        ENTITY_IO_TARGET_INVALID = -1,
        ENTITY_IO_TARGET_ENTITYNAME = 0x2,
        ENTITY_IO_TARGET_EHANDLE = 0x6,
        ENTITY_IO_TARGET_ENTITYNAME_OR_CLASSNAME = 0x7,
    };

    class EventSetTime_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nClientOutputFrames                           , 0x28)
        SCHEMA_FIELD(double                          , m_flRealTime                                    , 0x30)
        SCHEMA_FIELD(double                          , m_flRenderTime                                  , 0x38)
        SCHEMA_FIELD(double                          , m_flRenderFrameTime                             , 0x40)
        SCHEMA_FIELD(double                          , m_flRenderFrameTimeUnbounded                    , 0x48)
        SCHEMA_FIELD(double                          , m_flRenderFrameTimeUnscaled                     , 0x50)
        SCHEMA_FIELD(double                          , m_flTickRemainder                               , 0x58)
    };

    class EventClientAdvanceNonRenderedFrame_t {
    public:
    };

    class CEntityAttributeTable {
    public:
        using _Type0 = CUtlOrderedMap<CUtlStringToken,Attribute_t>;
        using _Type1 = CUtlOrderedMap<CUtlStringToken,CUtlString>;
        SCHEMA_FIELD(_Type0                          , m_Attributes                                    , 0x0)
        SCHEMA_FIELD(_Type1                          , m_Names                                         , 0x28)
    };

    class EventClientPollInput_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flRealTime                                    , 0x28)
    };

    class EventClientPreOutputParallelWithServer_t {
    public:
    };

    class EventServerProcessNetworking_t {
    public:
    };

    class CEmptyEntityInstance {
    public:
    };

    class CEntityKeyValues {
    public:
    };

    class EventClientOutput_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flRenderTime                                  , 0x28)
        SCHEMA_FIELD(float                           , m_flRealTime                                    , 0x2C)
        SCHEMA_FIELD(float                           , m_flRenderFrameTimeUnbounded                    , 0x30)
        SCHEMA_FIELD(bool                            , m_bRenderOnly                                   , 0x34)
    };

    class EventPostAdvanceTick_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentTick                                  , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentTickThisFrame                         , 0x34)
        SCHEMA_FIELD(std::int32_t                    , m_nTotalTicksThisFrame                          , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nTotalTicks                                   , 0x3C)
    };

    class EventClientAdvanceTick_t {
    public:
    };

    class EventSplitScreenStateChanged_t {
    public:
    };

    class CVariantDefaultAllocator {
    public:
    };

    class EntComponentInfo_t {
    public:
        SCHEMA_FIELD(char*                           , m_pName                                         , 0x0)
        SCHEMA_FIELD(char*                           , m_pCPPClassname                                 , 0x8)
        SCHEMA_FIELD(char*                           , m_pNetworkDataReferencedDescription             , 0x10)
        SCHEMA_FIELD(char*                           , m_pNetworkDataReferencedPtrPropDescription      , 0x18)
        SCHEMA_FIELD(std::int32_t                    , m_nRuntimeIndex                                 , 0x20)
        SCHEMA_FIELD(std::uint32_t                   , m_nFlags                                        , 0x24)
        SCHEMA_FIELD(CEntityComponentHelper*         , m_pBaseClassComponentHelper                     , 0x60)
    };

    class EventServerBeginAsyncPostTickWork_t {
    public:
        SCHEMA_FIELD(bool                            , m_bIsOncePerFrameAsyncWorkPhase                 , 0x0)
    };

    class EventServerPostAdvanceTick_t {
    public:
        SCHEMA_FIELD(bool                            , m_bLastTickBeforeClientUpdate                   , 0x40)
    };

    class CEntityInstance {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPrivateVScripts                            , 0x8)
        SCHEMA_FIELD(CEntityIdentity*                , m_pEntity                                       , 0x10)
        SCHEMA_FIELD(CScriptComponent*               , m_CScriptComponent                              , 0x28)
    };

    class EventServerBeginSimulate_t {
    public:
    };

    class EventServerEndAsyncPostTickWork_t {
    public:
    };

    class CNetworkVarChainer {
    public:
        SCHEMA_FIELD(::ChangeAccessorFieldPathIndex_t, m_PathIndex                                     , 0x20)
    };

    class EventClientFrameSimulate_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flRealTime                                    , 0x28)
        SCHEMA_FIELD(float                           , m_flFrameTime                                   , 0x2C)
        SCHEMA_FIELD(bool                            , m_bScheduleSendTickPacket                       , 0x30)
    };

    class EngineLoopState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nPlatWindowWidth                              , 0x18)
        SCHEMA_FIELD(std::int32_t                    , m_nPlatWindowHeight                             , 0x1C)
        SCHEMA_FIELD(std::int32_t                    , m_nRenderWidth                                  , 0x20)
        SCHEMA_FIELD(std::int32_t                    , m_nRenderHeight                                 , 0x24)
    };

    class EventAdvanceTick_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentTick                                  , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentTickThisFrame                         , 0x34)
        SCHEMA_FIELD(std::int32_t                    , m_nTotalTicksThisFrame                          , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nTotalTicks                                   , 0x3C)
    };

    class EventClientPostSimulate_t {
    public:
    };

    class EntInput_t {
    public:
    };

    class EventClientPauseSimulate_t {
    public:
    };

    class EventClientProcessNetworking_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nTickCount                                    , 0x0)
    };

    class EventClientPostAdvanceTick_t {
    public:
    };

    class EventProfileStorageAvailable_t {
    public:
        SCHEMA_FIELD(CSplitScreenSlot                , m_nSplitScreenSlot                              , 0x0)
    };

    class EventClientProcessInput_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flRealTime                                    , 0x28)
        SCHEMA_FIELD(float                           , m_flTickInterval                                , 0x2C)
        SCHEMA_FIELD(double                          , m_flTickStartTime                               , 0x30)
    };

    class CEntityComponent {
    public:
    };

    class GameTick_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Value                                         , 0x0)
    };

    class EventPostDataUpdate_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCount                                        , 0x0)
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

    class EventClientPollNetworking_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nTickCount                                    , 0x0)
    };

    class EventServerEndSimulate_t {
    public:
        SCHEMA_FIELD(bool                            , m_bLastTick                                     , 0x0)
    };

    class EventClientProcessGameInput_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flRealTime                                    , 0x28)
        SCHEMA_FIELD(float                           , m_flFrameTime                                   , 0x2C)
    };

    class EventClientPreSimulate_t {
    public:
    };

    class EventServerPollNetworking_t {
    public:
    };

    class GameTime_t {
    public:
        SCHEMA_FIELD(float                           , m_Value                                         , 0x0)
    };

    class EventServerPostSimulate_t {
    public:
        SCHEMA_FIELD(bool                            , m_bLastTickBeforeClientUpdate                   , 0x30)
    };

    class EventClientPostOutput_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(double                          , m_flRenderTime                                  , 0x28)
        SCHEMA_FIELD(float                           , m_flRenderFrameTime                             , 0x30)
        SCHEMA_FIELD(float                           , m_flRenderFrameTimeUnbounded                    , 0x34)
        SCHEMA_FIELD(bool                            , m_bRenderOnly                                   , 0x38)
    };

    class EventSimulate_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(bool                            , m_bFirstTick                                    , 0x28)
        SCHEMA_FIELD(bool                            , m_bLastTick                                     , 0x29)
    };

    class EntityIOQueuePrioritizedEvent_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flFireTime                                    , 0x4)
        SCHEMA_FIELD(EntityIOTargetType_t            , m_targetType                                    , 0x8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pTarget                                       , 0x10)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pTargetInput                                  , 0x18)
        SCHEMA_FIELD(CEntityHandle                   , m_hActivator                                    , 0x20)
        SCHEMA_FIELD(CEntityHandle                   , m_hCaller                                       , 0x24)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputID                                     , 0x28)
        SCHEMA_FIELD(CEntityHandle                   , m_hEntTarget                                    , 0x2C)
        SCHEMA_FIELD(CVariantBase<CVariantDefaultAllocator>, m_variantValue                                  , 0x30)
    };

    class EventSimpleLoopFrameUpdate_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flRealTime                                    , 0x28)
        SCHEMA_FIELD(float                           , m_flFrameTime                                   , 0x2C)
    };

    class CEntityIOOutput {
    public:
    };

    class EventModInitialized_t {
    public:
    };

    class CEntityComponentHelper {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_flags                                         , 0x8)
        SCHEMA_FIELD(EntComponentInfo_t*             , m_pInfo                                         , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nPriority                                     , 0x18)
        SCHEMA_FIELD(CEntityComponentHelper*         , m_pNext                                         , 0x20)
    };

    class EventClientSimulate_t {
    public:
    };

    class EventClientSceneSystemThreadStateChange_t {
    public:
        SCHEMA_FIELD(bool                            , m_bThreadsActive                                , 0x0)
    };

    class EventAppShutdown_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nDummy0                                       , 0x0)
    };

    class EventClientPreOutput_t {
    public:
        SCHEMA_FIELD(EngineLoopState_t               , m_LoopState                                     , 0x0)
        SCHEMA_FIELD(double                          , m_flRenderTime                                  , 0x28)
        SCHEMA_FIELD(double                          , m_flRenderFrameTime                             , 0x30)
        SCHEMA_FIELD(double                          , m_flRenderFrameTimeUnbounded                    , 0x38)
        SCHEMA_FIELD(float                           , m_flRealTime                                    , 0x40)
        SCHEMA_FIELD(bool                            , m_bRenderOnly                                   , 0x44)
    };

    class EventPreDataUpdate_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCount                                        , 0x0)
    };

    class EventServerAdvanceTick_t {
    public:
    };

    class EventFrameBoundary_t {
    public:
        SCHEMA_FIELD(float                           , m_flFrameTime                                   , 0x0)
    };

    class CScriptComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_scriptClassName                               , 0x30)
    };

}
