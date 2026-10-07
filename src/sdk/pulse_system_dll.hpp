

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::pulse_system {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class CPulseCell_Step_TestDomainDestroyFakeEntity;
    class CPulseCell_WaitForCursorsWithTag;
    class CPulseCell_Test_NoInflow;
    class CPulseGraphInstance_TestDomain_FakeEntityOwner;
    class CPulseCell_Base;
    class CPulse_ResumePoint;
    class CTestDomainDerived_Cursor;
    class CPulseCell_PickBestOutflowSelector;
    class CPulseTestFuncs_LibraryA;
    class CPulseCell_WaitForObservable;
    class CPulse_OutflowConnection;
    class CPulseGraphDef;
    class CPulseGraphInstance_TestDomain_UseReadOnlyBlackboardView;
    class CPulseCell_FireCursors;
    class CPulseCell_Timeline_TimelineEvent_t;
    class CPulseCell_IntervalTimer_CursorState_t;
    class CPulseCell_BaseRequirement;
    class CPulseCell_BaseState;
    class OutflowWithRequirements_t;
    class CPulseCell_IsRequirementValid;
    class CPulseCell_Value_Gradient;
    class CPulseCursorFuncs;
    class PulseNodeDynamicOutflows_t_DynamicOutflow_t;
    class CPulseCell_Test_MultiOutflow_WithParams;
    class CBasePulseGraphInstance;
    class CPulseCell_Inflow_GraphHook;
    class SignatureOutflow_Resume;
    class CPulseCell_Test_MultiOutflow_WithParams_Yielding_CursorState_t;
    class CPulseTurtleGraphicsCursor;
    class CPulseCell_TestWaitWithCursorState_CursorState_t;
    class CPulseCell_Inflow_BaseEntrypoint;
    class CPulseCell_Test_MultiInflow_NoDefault;
    class CPulseCell_WaitForCursorsWithTagBase;
    class CPulse_InvokeBinding;
    class CPulseCell_IntervalTimer;
    class CPulseTestScriptLib;
    class CPulseCell_BaseLerp;
    class CPulseCell_Value_TestValue50;
    class CPulseCell_Test_MultiOutflow_WithParams_Yielding;
    class TestComponent_tAPI;
    class CPulseCell_Value_Curve;
    class CPulseCell_Inflow_EventHandler;
    class CPulseCell_BaseFlow;
    class CPulseCell_Step_TestDomainTracepoint;
    class CPulseCell_Outflow_CycleShuffled_InstanceState_t;
    class CPulseCell_BaseLerp_CursorState_t;
    class CPulseGraphInstance_TestDomain_Derived;
    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t;
    class CPulseArraylib;
    class CPulseGraphInstance_TestDomain;
    class SignatureOutflow_Continue;
    class CPulseCell_Timeline;
    class CPulseCell_Inflow_EntOutputHandler;
    class CPulseCell_Outflow_TestExplicitYesNo;
    class CPulseCell_Outflow_TestRandomYesNo;
    class CPulseCell_Outflow_CycleOrdered_InstanceState_t;
    class CPulseCell_LimitCount_InstanceState_t;
    class FakeEntity_tAPI;
    class CPulseCell_Test_MultiInflow_WithDefault;
    class CPulseCell_Step_DebugLog;
    class CPulseCell_BaseYieldingInflow;
    class PulseNodeDynamicOutflows_t;
    class CPulseCell_IsRequirementValid_Criteria_t;
    class CPulseCell_Inflow_ObservableVariableListener;
    class CPulseCell_Outflow_CycleOrdered;
    class PulseSelectorOutflowList_t;
    class CPulseGraphInstance_TurtleGraphics;
    class CPulseCell_Val_TestDomainGetEntityName;
    class CPulseCell_Inflow_Wait;
    class CPulseCell_TestWaitWithCursorState;
    class CPulseCell_Outflow_CycleShuffled;
    class CPulseCell_Inflow_Method;
    class CPulseCell_BaseValue;
    class CPulseCell_BooleanSwitchState;
    class FakeEntityDerivedB_tAPI;
    class CPulseCell_Inflow_Yield;
    class CPulseMathlib;
    class CPulseCell_Unknown;
    class CPulseCell_Outflow_CycleRandom;
    class CPulseCell_Step_PublicOutput;
    class CPulseCell_Val_TestDomainFindEntityByName;
    class CPulse_BlackboardReference;
    class CPulseCell_Value_RandomInt;
    class CPulseCell_Step_TestDomainEntFire;
    class FakeEntityDerivedA_tAPI;
    class CPulseCell_ExampleSelector;
    class CPulse_CallInfo;
    class CPulseCell_InlineNodeSkipSelector;
    class CPulseCell_ExampleCriteria_Criteria_t;
    class CPulseCell_ExampleCriteria;
    class CPulseCell_LimitCount;
    class CPulseCell_Step_CallExternalMethod;
    class PulseObservableBoolExpression_t;
    class CPulseCell_LimitCount_Criteria_t;
    class CPulseCell_Step_TestDomainCreateFakeEntity;
    class CPulseCell_CursorQueue;
    class CPulseCell_Value_RandomFloat;
    class CPulseExecCursor;
    class TestComponent_t;

    enum class PulseBestOutflowRules_t : std::uint32_t {
        SORT_BY_NUMBER_OF_VALID_CRITERIA = 0x0,
        SORT_BY_OUTFLOW_INDEX = 0x1,
    };

    enum class PulseTestEnumShape_t : std::uint32_t {
        CIRCLE = 0x64,
        SQUARE = 0xC8,
        TRIANGLE = 0x12C,
    };

    enum class PulseCursorCancelPriority_t : std::uint32_t {
        None = 0x0,
        CancelOnSucceeded = 0x1,
        SoftCancel = 0x2,
        HardCancel = 0x3,
    };

    enum class PulseMethodCallMode_t : std::uint32_t {
        SYNC_WAIT_FOR_COMPLETION = 0x0,
        ASYNC_FIRE_AND_FORGET = 0x1,
    };

    enum class PulseTestEnumColor_t : std::uint32_t {
        BLACK = 0x0,
        WHITE = 0x1,
        RED = 0x2,
        GREEN = 0x3,
        BLUE = 0x4,
    };

    class CPulseCell_Test_MultiOutflow_WithParams {
    public:
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_Out1                                          , 0x48)
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_Out2                                          , 0x90)
    };

    class CPulseTestScriptLib {
    public:
    };

    class CPulseGraphDef {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_DomainIdentifier                              , 0x8)
        SCHEMA_FIELD(CPulseValueFullType             , m_DomainSubType                                 , 0x18)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_ParentMapName                                 , 0x30)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_ParentXmlName                                 , 0x40)
        SCHEMA_FIELD(CUtlVector<CPulse_Chunk*>       , m_Chunks                                        , 0x50)
        SCHEMA_FIELD(CUtlVector<CPulseCell_Base*>    , m_Cells                                         , 0x68)
        SCHEMA_FIELD(CUtlVector<CPulse_Variable>     , m_Vars                                          , 0x80)
        SCHEMA_FIELD(CUtlVector<CPulse_PublicOutput> , m_PublicOutputs                                 , 0x98)
        SCHEMA_FIELD(CUtlVector<CPulse_InvokeBinding*>, m_InvokeBindings                                , 0xB0)
        SCHEMA_FIELD(CUtlVector<CPulse_CallInfo*>    , m_CallInfos                                     , 0xC8)
        SCHEMA_FIELD(CUtlVector<CPulse_Constant>     , m_Constants                                     , 0xE0)
        SCHEMA_FIELD(CUtlVector<CPulse_DomainValue>  , m_DomainValues                                  , 0xF8)
        SCHEMA_FIELD(CUtlVector<CPulse_BlackboardReference>, m_BlackboardReferences                          , 0x110)
        SCHEMA_FIELD(CUtlVector<CPulse_OutputConnection*>, m_OutputConnections                             , 0x128)
    };

    class CPulseCell_Outflow_CycleShuffled {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class FakeEntityDerivedA_tAPI {
    public:
    };

    class CPulseCell_Inflow_EventHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_EventName                                     , 0x80)
    };

    class CPulseCell_TestWaitWithCursorState {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeCancel                                    , 0x90)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeFail                                      , 0xD8)
    };

    class CPulseCell_Outflow_CycleOrdered {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class CPulseCell_Outflow_CycleOrdered_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNextIndex                                    , 0x0)
    };

    class CPulseCell_Inflow_BaseEntrypoint {
    public:
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_EntryChunk                                    , 0x48)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x50)
    };

    class CPulseTestFuncs_LibraryA {
    public:
    };

    class CPulse_InvokeBinding {
    public:
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_FuncName                                      , 0x30)
        SCHEMA_FIELD(PulseRuntimeCellIndex_t         , m_nCellIndex                                    , 0x40)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nSrcChunk                                     , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_nSrcInstruction                               , 0x48)
    };

    class CPulseCell_IntervalTimer {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_Completed                                     , 0x48)
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_OnInterval                                    , 0x90)
    };

    class CTestDomainDerived_Cursor {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorValueA                                 , 0xD8)
        SCHEMA_FIELD(std::int32_t                    , m_nCursorValueB                                 , 0xDC)
    };

    class CPulseCell_Value_Curve {
    public:
        SCHEMA_FIELD(CPiecewiseCurve                 , m_Curve                                         , 0x48)
    };

    class CPulseCell_BaseState {
    public:
    };

    class CPulseCell_Test_MultiInflow_WithDefault {
    public:
    };

    class SignatureOutflow_Resume {
    public:
    };

    class CPulseCell_Step_PublicOutput {
    public:
        SCHEMA_FIELD(PulseRuntimeOutputIndex_t       , m_OutputIndex                                   , 0x48)
    };

    class CPulseCell_InlineNodeSkipSelector {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nFlowNodeID                                   , 0x48)
        SCHEMA_FIELD(bool                            , m_bAnd                                          , 0x4C)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_PassOutflow                                   , 0x50)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_FailOutflow                                   , 0x68)
    };

    class CPulseCell_LimitCount {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nLimitCount                                   , 0x48)
    };

    class CPulseCell_ExampleCriteria_Criteria_t {
    public:
        SCHEMA_FIELD(float                           , m_flFloatValue1                                 , 0x0)
        SCHEMA_FIELD(float                           , m_flFloatValue2                                 , 0x4)
        SCHEMA_FIELD(bool                            , m_bMyBool                                       , 0x8)
    };

    class PulseObservableBoolExpression_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EvaluateConnection                            , 0x0)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeVarIndex_t>, m_DependentObservableVars                       , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeBlackboardReferenceIndex_t>, m_DependentObservableBlackboardReferences       , 0x60)
    };

    class CPulseCell_Step_TestDomainEntFire {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_Input                                         , 0x48)
    };

    class CPulseCell_ExampleSelector {
    public:
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_OutflowList                                   , 0x48)
    };

    class CPulseCell_BooleanSwitchState {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Always                                        , 0xC0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenTrue                                      , 0x108)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenFalse                                     , 0x150)
    };

    class CPulseExecCursor {
    public:
    };

    class CPulseCell_Inflow_GraphHook {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_HookName                                      , 0x80)
    };

    class CPulseCell_BaseFlow {
    public:
    };

    class CPulseCell_BaseLerp_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
    };

    class CPulseCell_ExampleCriteria {
    public:
    };

    class FakeEntity_tAPI {
    public:
    };

    class CPulseCell_BaseLerp {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
    };

    class CPulseCell_Inflow_ObservableVariableListener {
    public:
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardReference                          , 0x80)
        SCHEMA_FIELD(bool                            , m_bSelfReference                                , 0x82)
    };

    class CPulseCell_Step_TestDomainDestroyFakeEntity {
    public:
    };

    class CPulseGraphInstance_TestDomain {
    public:
        SCHEMA_FIELD(bool                            , m_bIsRunningUnitTests                           , 0x130)
        SCHEMA_FIELD(bool                            , m_bExplicitTimeStepping                         , 0x131)
        SCHEMA_FIELD(bool                            , m_bExpectingToDestroyWithYieldedCursors         , 0x132)
        SCHEMA_FIELD(bool                            , m_bQuietTracepoints                             , 0x133)
        SCHEMA_FIELD(bool                            , m_bExpectingCursorTerminatedDueToMaxInstructions, 0x134)
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsTerminatedDueToMaxInstructions        , 0x138)
        SCHEMA_FIELD(std::int32_t                    , m_nNextValidateIndex                            , 0x13C)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_Tracepoints                                   , 0x140)
        SCHEMA_FIELD(bool                            , m_bTestYesOrNoPath                              , 0x158)
    };

    class CPulseCell_IntervalTimer_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
        SCHEMA_FIELD(float                           , m_flWaitInterval                                , 0x8)
        SCHEMA_FIELD(float                           , m_flWaitIntervalHigh                            , 0xC)
        SCHEMA_FIELD(bool                            , m_bCompleteOnNextWake                           , 0x10)
    };

    class CBasePulseGraphInstance {
    public:
    };

    class CPulseCell_Step_TestDomainTracepoint {
    public:
    };

    class OutflowWithRequirements_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x0)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_DestinationFlowNodeID                         , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseDocNodeID_t>    , m_RequirementNodeIDs                            , 0x50)
        SCHEMA_FIELD(CUtlVector<int32>               , m_nCursorStateBlockIndex                        , 0x68)
    };

    class CPulseCell_Test_MultiOutflow_WithParams_Yielding {
    public:
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_Out1                                          , 0x48)
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_AsyncChild1                                   , 0x90)
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_AsyncChild2                                   , 0xD8)
        SCHEMA_FIELD(SignatureOutflow_Resume         , m_YieldResume1                                  , 0x120)
        SCHEMA_FIELD(SignatureOutflow_Resume         , m_YieldResume2                                  , 0x168)
    };

    class TestComponent_tAPI {
    public:
    };

    class CPulseCell_LimitCount_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentCount                                 , 0x0)
    };

    class CPulseCell_PickBestOutflowSelector {
    public:
        SCHEMA_FIELD(PulseBestOutflowRules_t         , m_nCheckType                                    , 0x48)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_OutflowList                                   , 0x50)
    };

    class CPulseCell_Val_TestDomainGetEntityName {
    public:
    };

    class CPulseCell_TestWaitWithCursorState_CursorState_t {
    public:
        SCHEMA_FIELD(float                           , flWaitValue                                     , 0x0)
        SCHEMA_FIELD(bool                            , bFailOnCancel                                   , 0x4)
    };

    class CPulseCell_Inflow_Method {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x80)
        SCHEMA_FIELD(::CUtlString                    , m_Description                                   , 0x90)
        SCHEMA_FIELD(bool                            , m_bIsPublic                                     , 0x98)
        SCHEMA_FIELD(CPulseValueFullType             , m_ReturnType                                    , 0xA0)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_Args                                          , 0xB8)
    };

    class CPulseCell_Timeline {
    public:
        SCHEMA_FIELD(CUtlVector<CPulseCell_Timeline_TimelineEvent_t>, m_TimelineEvents                                , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class CPulse_OutflowConnection {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutflowName                             , 0x0)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nDestChunk                                    , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nInstruction                                  , 0x14)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_OutflowRegisterMap                            , 0x18)
    };

    class CPulseGraphInstance_TestDomain_UseReadOnlyBlackboardView {
    public:
    };

    class FakeEntityDerivedB_tAPI {
    public:
    };

    class CPulseCell_Step_CallExternalMethod {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x48)
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardIndex                              , 0x58)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_ExpectedArgs                                  , 0x60)
        SCHEMA_FIELD(PulseMethodCallMode_t           , m_nAsyncCallMode                                , 0x70)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x78)
    };

    class CPulseCell_LimitCount_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bLimitCountPasses                             , 0x0)
    };

    class CPulseCell_IsRequirementValid_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bIsValid                                      , 0x0)
    };

    class CPulseCell_FireCursors {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outflows                                      , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class CPulseCell_Value_Gradient {
    public:
        SCHEMA_FIELD(CColorGradient                  , m_Gradient                                      , 0x48)
    };

    class CPulseCell_Outflow_TestExplicitYesNo {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Yes                                           , 0x48)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_No                                            , 0x90)
    };

    class CPulseArraylib {
    public:
    };

    class CPulseGraphInstance_TestDomain_Derived {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInstanceValueX                               , 0x160)
    };

    class CPulseCell_Val_TestDomainFindEntityByName {
    public:
    };

    class CPulseCell_WaitForCursorsWithTag {
    public:
        SCHEMA_FIELD(bool                            , m_bTagSelfWhenComplete                          , 0x98)
        SCHEMA_FIELD(PulseCursorCancelPriority_t     , m_nDesiredKillPriority                          , 0x9C)
    };

    class CPulseCell_WaitForObservable {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnTrue                                        , 0xC0)
    };

    class CPulseCell_BaseRequirement {
    public:
    };

    class CPulseCell_BaseYieldingInflow {
    public:
    };

    class CPulseCell_Inflow_Wait {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
    };

    class CPulse_BlackboardReference {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIPulseGraphDef>, m_hBlackboardResource                           , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_BlackboardResource                            , 0x8)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nNodeID                                       , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , m_NodeName                                      , 0x20)
    };

    class CPulseCell_Outflow_CycleRandom {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class CPulseCell_Value_TestValue50 {
    public:
    };

    class CPulseMathlib {
    public:
    };

    class CPulseCell_Test_NoInflow {
    public:
    };

    class PulseSelectorOutflowList_t {
    public:
        SCHEMA_FIELD(CUtlVector<OutflowWithRequirements_t>, m_Outflows                                      , 0x0)
    };

    class CPulseCell_Step_TestDomainCreateFakeEntity {
    public:
    };

    class CPulseCursorFuncs {
    public:
    };

    class CPulseCell_WaitForCursorsWithTagBase {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToWait                         , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WaitComplete                                  , 0x50)
    };

    class CPulseCell_CursorQueue {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToRunParallel                  , 0x98)
    };

    class CPulseGraphInstance_TurtleGraphics {
    public:
    };

    class CPulse_ResumePoint {
    public:
    };

    class CPulseCell_Outflow_CycleShuffled_InstanceState_t {
    public:
        using _Type0 = CUtlVectorFixedGrowable<uint8,8>;
        SCHEMA_FIELD(_Type0                          , m_Shuffle                                       , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nNextShuffle                                  , 0x20)
    };

    class CPulseCell_Test_MultiOutflow_WithParams_Yielding_CursorState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , nTestStep                                       , 0x0)
    };

    class CPulseCell_Test_MultiInflow_NoDefault {
    public:
    };

    class CPulseCell_Inflow_EntOutputHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceEntity                                  , 0x80)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutput                                  , 0x90)
        SCHEMA_FIELD(CPulseValueFullType             , m_ExpectedParamType                             , 0xA0)
    };

    class CPulse_CallInfo {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_PortName                                      , 0x0)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nEditorNodeID                                 , 0x10)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x18)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_CallMethodID                                  , 0x48)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nSrcChunk                                     , 0x4C)
        SCHEMA_FIELD(std::int32_t                    , m_nSrcInstruction                               , 0x50)
    };

    class CPulseCell_IsRequirementValid {
    public:
    };

    class PulseNodeDynamicOutflows_t {
    public:
        SCHEMA_FIELD(CUtlVector<PulseNodeDynamicOutflows_t_DynamicOutflow_t>, m_Outflows                                      , 0x0)
    };

    class CPulseCell_Timeline_TimelineEvent_t {
    public:
        SCHEMA_FIELD(float                           , m_flTimeFromPrevious                            , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EventOutflow                                  , 0x8)
    };

    class CPulseCell_Outflow_TestRandomYesNo {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Yes                                           , 0x48)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_No                                            , 0x90)
    };

    class CPulseCell_Inflow_Yield {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_UnyieldResume                                 , 0x48)
    };

    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_TagName                                       , 0x0)
    };

    class SignatureOutflow_Continue {
    public:
    };

    class CPulseGraphInstance_TestDomain_FakeEntityOwner {
    public:
    };

    class PulseNodeDynamicOutflows_t_DynamicOutflow_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_OutflowID                                     , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x8)
    };

    class CPulseTurtleGraphicsCursor {
    public:
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0xD8)
        SCHEMA_FIELD(::Vector2D                      , m_vPos                                          , 0xDC)
        SCHEMA_FIELD(float                           , m_flHeadingDeg                                  , 0xE4)
        SCHEMA_FIELD(bool                            , m_bPenUp                                        , 0xE8)
    };

    class CPulseCell_Step_DebugLog {
    public:
    };

    class CPulseCell_BaseValue {
    public:
    };

    class CPulseCell_Unknown {
    public:
        SCHEMA_FIELD(KeyValues3                      , m_UnknownKeys                                   , 0x48)
    };

    class CPulseCell_Base {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nEditorNodeID                                 , 0x8)
    };

    class CPulseCell_Value_RandomInt {
    public:
    };

    class CPulseCell_Value_RandomFloat {
    public:
    };

    class TestComponent_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_ComponentData                                 , 0x8)
    };

}
