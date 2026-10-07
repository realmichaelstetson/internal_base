

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::particles {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class CPulseCell_WaitForCursorsWithTag;
    class CPulseCell_Base;
    class CPulse_ResumePoint;
    class CPulseCell_PickBestOutflowSelector;
    class CParticleBindingRealPulse;
    class CPulseCell_WaitForObservable;
    class CPulse_OutflowConnection;
    class CPulseGraphDef;
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
    class CBasePulseGraphInstance;
    class CPulseCell_Inflow_GraphHook;
    class SignatureOutflow_Resume;
    class CPulseCell_Inflow_BaseEntrypoint;
    class CPulseCell_WaitForCursorsWithTagBase;
    class CPulse_InvokeBinding;
    class CPulseCell_IntervalTimer;
    class CPulseTestScriptLib;
    class CPulseCell_BaseLerp;
    class CPulseCell_Value_Curve;
    class CPulseCell_Inflow_EventHandler;
    class CPulseCell_BaseFlow;
    class CPulseCell_Outflow_CycleShuffled_InstanceState_t;
    class CPulseCell_BaseLerp_CursorState_t;
    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t;
    class CPulseArraylib;
    class SignatureOutflow_Continue;
    class CPulseCell_Timeline;
    class CPulseCell_Inflow_EntOutputHandler;
    class CPulseCell_Outflow_CycleOrdered_InstanceState_t;
    class CParticleCollectionBindingInstance;
    class CPulseCell_LimitCount_InstanceState_t;
    class CPulseCell_Step_DebugLog;
    class CPulseCell_BaseYieldingInflow;
    class PulseNodeDynamicOutflows_t;
    class CPulseCell_IsRequirementValid_Criteria_t;
    class CPulseCell_Inflow_ObservableVariableListener;
    class CPulseCell_Outflow_CycleOrdered;
    class PulseSelectorOutflowList_t;
    class CPulseCell_Inflow_Wait;
    class CPulseCell_Outflow_CycleShuffled;
    class CPulseCell_Inflow_Method;
    class CPulseCell_BaseValue;
    class CPulseCell_BooleanSwitchState;
    class CPulseCell_Inflow_Yield;
    class CPulseMathlib;
    class CPulseCell_Unknown;
    class CPulseCell_Outflow_CycleRandom;
    class CPulseCell_Step_PublicOutput;
    class CPulse_BlackboardReference;
    class CPulseCell_Value_RandomInt;
    class CPulse_CallInfo;
    class CPulseCell_InlineNodeSkipSelector;
    class CPulseCell_LimitCount;
    class CPulseCell_Step_CallExternalMethod;
    class PulseObservableBoolExpression_t;
    class CPulseCell_LimitCount_Criteria_t;
    class CPulseCell_CursorQueue;
    class CPulseCell_Value_RandomFloat;
    class CPulseExecCursor;
    class IParticleCollection;
    class ParticleAttributeIndex_t;
    class C_OP_RemapGravityToVector;
    class C_OP_Decay;
    class C_OP_RenderDeferredLight;
    class C_OP_RemapSpeedtoCP;
    class C_OP_RemapTransformToVelocity;
    class CollisionGroupContext_t;
    class CParticleFunctionPreEmission;
    class C_OP_FadeOutSimple;
    class C_OP_SpringToVectorConstraint;
    class C_OP_RenderRopes;
    class C_INIT_StatusEffectCitadel;
    class C_OP_RenderSound;
    class CParticleVisibilityInputs;
    class C_OP_SetControlPointsToParticle;
    class C_OP_RemapCPVelocityToVector;
    class C_OP_PointVectorAtNextParticle;
    class ParticlePreviewBodyGroup_t;
    class C_OP_OscillateScalarSimple;
    class C_INIT_StatusEffect;
    class C_INIT_RtEnvCull;
    class C_OP_ConstrainDistance;
    class C_INIT_RandomVector;
    class C_INIT_InitialVelocityNoise;
    class ParticleChildrenInfo_t;
    class C_OP_RemapScalarOnceTimed;
    class C_INIT_RandomNamedModelSequence;
    class C_OP_PlaneCull;
    class C_INIT_VelocityRandom;
    class C_OP_ModelDampenMovement;
    class C_OP_TwistAroundAxis;
    class C_OP_TeleportBeam;
    class C_OP_RemapExternalWindToCP;
    class CBaseRendererSource2;
    class CSpinUpdateBase;
    class C_OP_OrientTo2dDirection;
    class C_OP_RemapDotProductToCP;
    class C_INIT_RemapParticleCountToNamedModelElementScalar;
    class C_OP_RenderTrails;
    class C_OP_SetControlPointPositionToTimeOfDayValue;
    class C_OP_DecayMaintainCount;
    class C_INIT_RandomModelSequence;
    class C_OP_ExternalGameImpulseForce;
    class C_OP_RemapAverageHitboxSpeedtoCP;
    class C_INIT_RandomAlpha;
    class C_OP_NormalizeVector;
    class C_OP_FadeInSimple;
    class C_OP_RepeatedTriggerChildGroup;
    class C_OP_RemapVelocityToVector;
    class C_INIT_SetHitboxToClosest;
    class C_INIT_RingWave;
    class C_INIT_RandomTrailLength;
    class C_OP_RemapScalar;
    class C_OP_DistanceBetweenTransforms;
    class C_OP_DecayOffscreen;
    class C_INIT_CreateSequentialPath;
    class C_OP_EndCapTimedDecay;
    class C_OP_RemapDistanceToLineSegmentBase;
    class C_OP_ContinuousEmitter;
    class C_OP_OscillateVectorSimple;
    class C_INIT_SequenceLifeTime;
    class C_INIT_MoveBetweenPoints;
    class C_OP_SetUserEvent;
    class C_OP_QuantizeFloat;
    class C_OP_BasicMovement;
    class C_INIT_RandomNamedModelElement;
    class C_INIT_InitFromParentKilled;
    class C_OP_Callback;
    class CParticleFunction;
    class C_OP_GlobalLight;
    class C_INIT_OffsetVectorToVector;
    class C_OP_SetPerChildControlPointFromAttribute;
    class C_OP_SetParentControlPointsToChildCP;
    class C_OP_BoxConstraint;
    class C_INIT_CreatePhyllotaxis;
    class C_OP_AttractToControlPoint;
    class C_INIT_RandomLifeTime;
    class C_INIT_RemapParticleCountToNamedModelSequenceScalar;
    class C_INIT_VelocityRadialRandom;
    class C_INIT_RandomRadius;
    class C_OP_Orient2DRelToCP;
    class TextureControls_t;
    class ControlPointReference_t;
    class C_OP_SetControlPointToVectorExpression;
    class C_OP_LightningSnapshotGenerator;
    class C_OP_RemapNamedModelMeshGroupOnceTimed;
    class C_INIT_RemapQAnglesToRotation;
    class C_INIT_PositionWarp;
    class C_OP_SetControlPointFieldToScalarExpression;
    class C_OP_CreateParticleSystemRenderer;
    class CParticleFunctionForce;
    class C_INIT_RandomVectorComponent;
    class C_OP_InheritFromParentParticles;
    class C_INIT_SetVectorAttributeToVectorExpression;
    class C_OP_RemapTransformVisibilityToVector;
    class C_OP_DirectionBetweenVecsToVec;
    class C_OP_MovementLoopInsideSphere;
    class C_OP_RenderSimpleModelCollection;
    class C_OP_QuantizeCPComponent;
    class C_OP_PlayEndCapWhenFinished;
    class C_INIT_InitFloatCollection;
    class CPathParameters;
    class C_OP_RemapScalarEndCap;
    class C_INIT_CreateFromPlaneCache;
    class C_OP_LazyCullCompareFloat;
    class C_OP_ControlPointToRadialScreenSpace;
    class C_OP_SpinUpdate;
    class C_INIT_NormalOffset;
    class C_OP_RemapDistanceToLineSegmentToVector;
    class C_OP_RenderAsModels;
    class C_INIT_CreationNoise;
    class C_OP_Spin;
    class C_OP_GameLiquidSpill;
    class C_OP_InstantaneousEmitter;
    class C_OP_ConstrainLineLength;
    class C_INIT_LifespanFromVelocity;
    class CBaseTrailRenderer;
    class C_INIT_VelocityFromCP;
    class C_OP_SetControlPointOrientation;
    class C_OP_MovementSkinnedPositionFromCPSnapshot;
    class C_OP_MultiSegmentDisplaySnapshotGenerator;
    class C_OP_OscillateVector;
    class C_OP_PositionLock;
    class C_OP_RenderVRHapticEvent;
    class C_OP_SetControlPointToImpactPoint;
    class C_OP_InterpolateRadius;
    class C_OP_ReinitializeScalarEndCap;
    class C_OP_TurbulenceForce;
    class C_OP_RemapNamedModelElementOnceTimed;
    class C_OP_SetControlPointToPlayer;
    class C_OP_EndCapTimedFreeze;
    class C_OP_RenderGpuImplicit;
    class C_OP_SetRandomControlPointPosition;
    class C_OP_RenderVolumetricEmitter;
    class C_OP_RemapTransformVisibilityToScalar;
    class C_OP_RemapControlPointDirectionToVector;
    class C_OP_ScreenSpacePositionOfTarget;
    class CParticleFunctionOperator;
    class C_OP_DragRelativeToPlane;
    class C_OP_SetCPtoVector;
    class C_INIT_RandomYaw;
    class C_OP_SnapshotRigidSkinToBones;
    class C_OP_SetSingleControlPointPosition;
    class C_INIT_DistanceToNeighborCull;
    class C_OP_RemapCPtoScalar;
    class CParticleFunctionRenderer;
    class CParticleSystemDefinition;
    class C_OP_RemapNamedModelMeshGroupEndCap;
    class C_OP_PercentageBetweenTransformsVector;
    class C_OP_RenderScreenVelocityRotate;
    class C_OP_UpdateLightSource;
    class C_INIT_CreateWithinBox;
    class C_OP_ChooseRandomChildrenInGroup;
    class C_OP_ControlpointLight;
    class C_OP_VectorFieldSnapshot;
    class C_OP_CylindricalDistanceToTransform;
    class C_INIT_PositionPlaceOnGround;
    class C_INIT_RandomScalar;
    class C_OP_RenderPostProcessing;
    class C_OP_WorldTraceConstraint;
    class C_OP_RenderBlobs;
    class C_OP_OscillateScalar;
    class C_OP_FadeOut;
    class C_OP_WaterImpulseRenderer;
    class C_INIT_RandomSequence;
    class C_OP_RampScalarSplineSimple;
    class C_INIT_DistanceCull;
    class C_OP_CollideWithParentParticles;
    class C_INIT_InitFromVectorFieldSnapshot;
    class C_OP_SetVectorAttributeToVectorExpression;
    class C_INIT_AddVectorToVector;
    class C_INIT_RemapInitialVisibilityScalar;
    class C_OP_RemapTransformOrientationToYaw;
    class C_OP_RenderStatusEffect;
    class C_OP_RandomForce;
    class C_OP_RemapParticleCountOnScalarEndCap;
    class ParticlePreviewState_t;
    class C_OP_LocalAccelerationForce;
    class C_OP_ModelCull;
    class C_OP_SetFloat;
    class C_INIT_RemapTransformToVector;
    class C_OP_ScreenSpaceDistanceToEdge;
    class C_OP_RemapDistanceToLineSegmentToScalar;
    class C_OP_RemapVectortoCP;
    class C_OP_SetFromCPSnapshot;
    class C_OP_DistanceBetweenCPsToCP;
    class C_OP_SetControlPointToHand;
    class C_OP_ConstrainDistanceToPath;
    class C_OP_DistanceCull;
    class C_INIT_CreateAlongPath;
    class C_OP_GameDecalRenderer;
    class C_OP_SetControlPointsToModelParticles;
    class C_OP_ColorInterpolateRandom;
    class C_INIT_RemapNamedModelSequenceToScalar;
    class C_OP_RenderLights;
    class C_OP_DecayClampCount;
    class CRandomNumberGeneratorParameters;
    class C_INIT_ColorLitPerParticle;
    class C_OP_RenderPoints;
    class C_INIT_SetAttributeToScalarExpression;
    class C_INIT_CreateOnGrid;
    class C_OP_RampCPLinearRandom;
    class C_OP_VelocityMatchingForce;
    class C_INIT_RandomAlphaWindowThreshold;
    class C_INIT_CreateOnModelAtHeight;
    class C_OP_ModelSurfaceSnapshotGenerator;
    class C_OP_RestartAfterDuration;
    class C_OP_RenderClothForce;
    class C_OP_RemapVisibilityScalar;
    class C_INIT_CreateSequentialPathV2;
    class VecInputMaterialVariable_t;
    class C_INIT_RemapInitialDirectionToTransformToVector;
    class C_OP_LockToSavedSequentialPathV2;
    class C_OP_NormalLock;
    class C_INIT_RemapTransformOrientationToRotations;
    class C_OP_Cull;
    class C_INIT_RandomYawFlip;
    class SequenceWeightedList_t;
    class C_OP_ReadFromNeighboringParticle;
    class C_OP_RenderText;
    class C_OP_LerpToInitialPosition;
    class C_INIT_RandomRotation;
    class C_OP_LerpEndCapVector;
    class C_OP_VelocityDecay;
    class C_OP_SetCPOrientationToPointAtCP;
    class C_OP_LockToPointList;
    class C_OP_MovementPlaceOnGround;
    class C_OP_SetCPOrientationToDirection;
    class C_OP_RemapCrossProductOfTwoVectorsToVector;
    class C_OP_RemapTransformOrientationToRotations;
    class C_INIT_RandomRotationSpeed;
    class C_OP_InheritFromParentParticlesV2;
    class C_INIT_RandomSecondSequence;
    class C_OP_SetFloatCollection;
    class PointDefinition_t;
    class C_OP_SetControlPointPositionToRandomActiveCP;
    class C_OP_Diffusion;
    class C_INIT_AgeNoise;
    class C_OP_RemapVectorComponentToScalar;
    class CGeneralRandomRotation;
    class C_OP_DistanceBetweenVecs;
    class C_OP_DampenToCP;
    class C_OP_CalculateVectorAttribute;
    class C_OP_LockToBone;
    class C_OP_RemapNamedModelBodyPartOnceTimed;
    class C_OP_ScreenSpaceRotateTowardTarget;
    class C_OP_MovementMaintainOffset;
    class C_INIT_CreateWithinCapsuleTransform;
    class C_OP_SetVec;
    class C_INIT_CreateFromParentParticles;
    class C_INIT_CheckParticleForWater;
    class C_INIT_RandomNamedModelBodyPart;
    class C_OP_RenderOmni2Light;
    class C_OP_ConnectParentParticleToNearest;
    class CPAssignment_t;
    class C_INIT_RemapParticleCountToNamedModelBodyPartScalar;
    class C_INIT_InitSkinnedPositionFromCPSnapshot;
    class C_OP_LagCompensation;
    class C_OP_CollideWithSelf;
    class C_OP_Noise;
    class C_OP_FadeAndKillForTracers;
    class C_OP_ColorAdjustHSL;
    class CParticleMassCalculationParameters;
    class C_OP_SequenceFromModel;
    class C_OP_AlphaDecay;
    class C_OP_RemapDensityGradientToVectorAttribute;
    class C_INIT_InitVec;
    class C_INIT_SetHitboxToModel;
    class C_OP_MovementMoveAlongSkinnedCPSnapshot;
    class C_OP_LerpScalar;
    class C_INIT_InitialRepulsionVelocity;
    class C_OP_ClampScalar;
    class C_OP_SetControlPointToHMD;
    class C_OP_DifferencePreviousParticle;
    class C_OP_SetControlPointFieldFromVectorExpression;
    class C_OP_PercentageBetweenTransforms;
    class C_INIT_PlaneCull;
    class C_OP_RemapNamedModelSequenceEndCap;
    class C_INIT_InitFromCPSnapshot;
    class C_OP_RenderCables;
    class C_INIT_InheritVelocity;
    class C_OP_SetControlPointToWaterSurface;
    class C_INIT_PositionOffset;
    class C_INIT_NormalAlignToCP;
    class C_OP_ShapeMatchingConstraint;
    class C_OP_SetChildControlPoints;
    class C_OP_ChladniWave;
    class C_OP_RemapDirectionToCPToVector;
    class C_OP_DriveCPFromGlobalSoundFloat;
    class C_INIT_ScreenSpacePositionOfTarget;
    class C_OP_RtEnvCull;
    class C_OP_PinParticleToCP;
    class C_OP_RemapCPtoVector;
    class C_INIT_CreateParticleImpulse;
    class C_OP_DensityForce;
    class C_INIT_CreateInEpitrochoid;
    class C_OP_ConstrainDistanceToUserSpecifiedPath;
    class C_OP_SetControlPointPositions;
    class C_OP_SetFloatAttributeToVectorExpression;
    class C_OP_MovementRotateParticleAroundAxis;
    class C_OP_IntraParticleForce;
    class C_INIT_InitFloat;
    class C_INIT_CreateOnModel;
    class C_OP_InheritFromPeerSystem;
    class C_OP_PerParticleForce;
    class C_INIT_RandomNamedModelMeshGroup;
    class C_OP_RenderProjected;
    class C_OP_MaxVelocity;
    class C_INIT_VelocityFromNormal;
    class C_OP_MaintainEmitter;
    class C_INIT_PositionOffsetToCP;
    class C_INIT_RemapInitialTransformDirectionToRotation;
    class C_OP_FadeAndKill;
    class C_OP_ColorInterpolate;
    class C_OP_RampScalarSpline;
    class C_OP_RemapNamedModelSequenceOnceTimed;
    class C_OP_SetControlPointFromObjectScale;
    class C_OP_MaintainSequentialPath;
    class C_OP_RemapNamedModelBodyPartEndCap;
    class C_OP_StopAfterCPDuration;
    class CGeneralSpin;
    class C_OP_LockToSavedSequentialPath;
    class C_INIT_RemapNamedModelElementToScalar;
    class C_OP_ClampVector;
    class C_OP_RenderStatusEffectCitadel;
    class IParticleSystemDefinition;
    class C_OP_WindForce;
    class C_OP_SetVariable;
    class C_OP_RenderStandardLight;
    class C_OP_DistanceToTransform;
    class C_OP_RemapControlPointOrientationToRotation;
    class C_OP_SetControlPointToCenter;
    class C_OP_RemapAverageScalarValuetoCP;
    class C_OP_RemapDotProductToScalar;
    class C_OP_RemapCPtoCP;
    class C_OP_SetControlPointRotation;
    class C_OP_CurlNoiseForce;
    class C_INIT_Orient2DRelToCP;
    class C_OP_SetSimulationRate;
    class C_OP_FadeIn;
    class C_OP_RenderScreenShake;
    class C_OP_RemapBoundingVolumetoCP;
    class C_OP_HSVShiftToCP;
    class C_OP_RemapVectorToRotations;
    class C_INIT_GlobalScale;
    class C_INIT_RadiusFromCPObject;
    class C_INIT_InitialVelocityFromHitbox;
    class C_OP_LerpVector;
    class C_OP_SetControlPointFieldToWater;
    class TextureGroup_t;
    class C_OP_TimeVaryingForce;
    class C_OP_SetCPOrientationToGroundNormal;
    class C_OP_SnapshotSkinToBones;
    class C_INIT_CreateWithinSphereTransform;
    class C_OP_RadiusDecay;
    class C_INIT_RemapNamedModelBodyPartToScalar;
    class C_INIT_RemapScalarToVector;
    class C_INIT_InitialSequenceFromModel;
    class C_OP_NoiseEmitter;
    class CParticleFunctionInitializer;
    class C_OP_SelectivelyEnableChildren;
    class ModelReference_t;
    class C_OP_PlanarConstraint;
    class C_INIT_CreateFromCPs;
    class C_OP_LockPoints;
    class C_INIT_CreateSpiralSphere;
    class C_OP_CPVelocityForce;
    class C_OP_RemapNamedModelElementEndCap;
    class C_INIT_ScaleVelocity;
    class C_OP_MoveToHitbox;
    class C_OP_PinRopeSegmentParticleToParent;
    class C_INIT_PointList;
    class C_OP_LerpToOtherAttribute;
    class C_INIT_RandomColor;
    class C_OP_SetGravityToCP;
    class C_INIT_RemapParticleCountToScalar;
    class C_INIT_InheritFromParentParticles;
    class C_OP_RampScalarLinearSimple;
    class C_INIT_ChaoticAttractor;
    class C_OP_MovementRigidAttachToCP;
    class C_OP_RenderFlattenGrass;
    class C_OP_RenderLightBeam;
    class C_OP_EnableChildrenFromParentParticleCount;
    class C_INIT_DistanceToCPInit;
    class CReplicationParameters;
    class C_OP_EndCapDecay;
    class C_OP_ForceBasedOnDistanceToPlane;
    class C_OP_RemapDensityToVector;
    class ParticleControlPointConfiguration_t;
    class C_INIT_SetRigidAttachment;
    class MaterialVariable_t;
    class CParticleFunctionConstraint;
    class C_OP_RemapSpeed;
    class C_OP_RenderModels;
    class C_OP_RenderClientPhysicsImpulse;
    class CParticleFunctionEmitter;
    class C_INIT_RemapNamedModelMeshGroupToScalar;
    class C_OP_SetControlPointOrientationToCPVelocity;
    class C_OP_RopeSpringConstraint;
    class C_INIT_PositionWarpScalar;
    class C_OP_ForceControlPointStub;
    class C_OP_VectorNoise;
    class C_OP_RemapParticleCountToScalar;
    class C_INIT_QuantizeFloat;
    class C_OP_RemapModelVolumetoCP;
    class C_OP_SetToCP;
    class ParticleControlPointDriver_t;
    class C_OP_ParentVortices;
    class C_OP_SetControlPointToCPVelocity;
    class C_OP_ClientPhysics;
    class C_OP_SpinYaw;
    class PointDefinitionWithTimeValues_t;
    class RenderProjectedMaterial_t;
    class C_INIT_SetFloatAttributeToVectorExpression;
    class C_OP_ExternalWindForce;
    class C_INIT_ModelCull;
    class C_OP_RenderSprites;
    class C_OP_PercentageBetweenTransformLerpCPs;
    class C_OP_SetPerChildControlPoint;
    class C_OP_RenderTreeShake;
    class C_OP_WorldCollideConstraint;
    class C_OP_SetAttributeToScalarExpression;
    class C_OP_CycleScalar;
    class C_OP_RenderMaterialProxy;
    class FloatInputMaterialVariable_t;
    class C_OP_RampScalarLinear;
    class C_OP_RotateVector;
    class C_INIT_InitVecCollection;
    class C_INIT_RemapParticleCountToNamedModelMeshGroupScalar;
    class C_INIT_SequenceFromCP;
    class C_OP_CPOffsetToPercentageBetweenCPs;
    class C_OP_LerpEndCapScalar;

    enum class PulseBestOutflowRules_t : std::uint32_t {
        SORT_BY_NUMBER_OF_VALID_CRITERIA = 0x0,
        SORT_BY_OUTFLOW_INDEX = 0x1,
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

    enum class Detail2Combo_t : std::int32_t {
        DETAIL_2_COMBO_UNINITIALIZED = -1,
        DETAIL_2_COMBO_OFF = 0x0,
        DETAIL_2_COMBO_ADD = 0x1,
        DETAIL_2_COMBO_ADD_SELF_ILLUM = 0x2,
        DETAIL_2_COMBO_MOD2X = 0x3,
        DETAIL_2_COMBO_MUL = 0x4,
        DETAIL_2_COMBO_CROSSFADE = 0x5,
    };

    enum class MissingParentInheritBehavior_t : std::int32_t {
        MISSING_PARENT_DO_NOTHING = -1,
        MISSING_PARENT_KILL = 0x0,
        MISSING_PARENT_FIND_NEW = 0x1,
        MISSING_PARENT_SAME_INDEX = 0x2,
    };

    enum class ParticleTraceMissBehavior_t : std::uint32_t {
        PARTICLE_TRACE_MISS_BEHAVIOR_NONE = 0x0,
        PARTICLE_TRACE_MISS_BEHAVIOR_KILL = 0x1,
        PARTICLE_TRACE_MISS_BEHAVIOR_TRACE_END = 0x2,
    };

    enum class PFuncVisualizationType_t : std::uint32_t {
        PFUNC_VISUALIZATION_SPHERE_WIREFRAME = 0x0,
        PFUNC_VISUALIZATION_SPHERE_SOLID = 0x1,
        PFUNC_VISUALIZATION_BOX = 0x2,
        PFUNC_VISUALIZATION_RING = 0x3,
        PFUNC_VISUALIZATION_PLANE = 0x4,
        PFUNC_VISUALIZATION_LINE = 0x5,
        PFUNC_VISUALIZATION_CYLINDER = 0x6,
    };

    enum class ParticleVRHandChoiceList_t : std::uint32_t {
        PARTICLE_VRHAND_LEFT = 0x0,
        PARTICLE_VRHAND_RIGHT = 0x1,
        PARTICLE_VRHAND_CP = 0x2,
        PARTICLE_VRHAND_CP_OBJECT = 0x3,
    };

    enum class ParticleReplicationMode_t : std::uint32_t {
        PARTICLE_REPLICATIONMODE_NONE = 0x0,
        PARTICLE_REPLICATIONMODE_REPLICATE_FOR_EACH_PARENT_PARTICLE = 0x1,
    };

    enum class ParticleEntityPos_t : std::uint32_t {
        PARTICLE_ABS_ORIGIN = 0x0,
        PARTICLE_WORLDSPACE_CENTER = 0x1,
        PARTICLE_EYES = 0x2,
    };

    enum class ParticleFanType_t : std::uint32_t {
        PARTICLE_FAN_TYPE_FAN = 0x0,
        PARTICLE_FAN_TYPE_ROTOR_WASH = 0x1,
        PARTICLE_FAN_TYPE_RADIAL = 0x2,
    };

    enum class PetGroundType_t : std::uint32_t {
        PET_GROUND_NONE = 0x0,
        PET_GROUND_GRID = 0x1,
        PET_GROUND_PLANE = 0x2,
    };

    enum class InheritableBoolType_t : std::uint32_t {
        INHERITABLE_BOOL_INHERIT = 0x0,
        INHERITABLE_BOOL_FALSE = 0x1,
        INHERITABLE_BOOL_TRUE = 0x2,
    };

    enum class ParticlePostProcessPriorityGroup_t : std::uint32_t {
        PARTICLE_POST_PROCESS_PRIORITY_LEVEL_VOLUME = 0x0,
        PARTICLE_POST_PROCESS_PRIORITY_LEVEL_OVERRIDE = 0x1,
        PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_EFFECT = 0x2,
        PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_STATE_LOW = 0x3,
        PARTICLE_POST_PROCESS_PRIORITY_GAMEPLAY_STATE_HIGH = 0x4,
        PARTICLE_POST_PROCESS_PRIORITY_GLOBAL_UI = 0x5,
    };

    enum class ParticleCollisionGroup_t : std::uint32_t {
        PARTICLE_COLLISION_GROUP_DEFAULT = 0x4,
        PARTICLE_COLLISION_GROUP_DEBRIS = 0x5,
        PARTICLE_COLLISION_GROUP_INTERACTIVE = 0x7,
        PARTICLE_COLLISION_GROUP_PLAYER = 0x8,
        PARTICLE_COLLISION_GROUP_VEHICLE = 0xA,
        PARTICLE_COLLISION_GROUP_NPC = 0xC,
        PARTICLE_COLLISION_GROUP_PROPS = 0x18,
    };

    enum class DetailCombo_t : std::uint32_t {
        DETAIL_COMBO_OFF = 0x0,
        DETAIL_COMBO_ADD = 0x1,
        DETAIL_COMBO_ADD_SELF_ILLUM = 0x2,
        DETAIL_COMBO_MOD2X = 0x3,
    };

    enum class ScalarExpressionType_t : std::int32_t {
        SCALAR_EXPRESSION_UNINITIALIZED = -1,
        SCALAR_EXPRESSION_ADD = 0x0,
        SCALAR_EXPRESSION_SUBTRACT = 0x1,
        SCALAR_EXPRESSION_MUL = 0x2,
        SCALAR_EXPRESSION_DIVIDE = 0x3,
        SCALAR_EXPRESSION_INPUT_1 = 0x4,
        SCALAR_EXPRESSION_MIN = 0x5,
        SCALAR_EXPRESSION_MAX = 0x6,
        SCALAR_EXPRESSION_MOD = 0x7,
        SCALAR_EXPRESSION_EQUAL = 0x8,
        SCALAR_EXPRESSION_GT = 0x9,
        SCALAR_EXPRESSION_LT = 0xA,
    };

    enum class SpriteCardPerParticleScale_t : std::uint32_t {
        SPRITECARD_TEXTURE_PP_SCALE_NONE = 0x0,
        SPRITECARD_TEXTURE_PP_SCALE_PARTICLE_AGE = 0x1,
        SPRITECARD_TEXTURE_PP_SCALE_ANIMATION_FRAME = 0x2,
        SPRITECARD_TEXTURE_PP_SCALE_SHADER_EXTRA_DATA1 = 0x3,
        SPRITECARD_TEXTURE_PP_SCALE_SHADER_EXTRA_DATA2 = 0x4,
        SPRITECARD_TEXTURE_PP_SCALE_PARTICLE_ALPHA = 0x5,
        SPRITECARD_TEXTURE_PP_SCALE_SHADER_RADIUS = 0x6,
        SPRITECARD_TEXTURE_PP_SCALE_ROLL = 0x7,
        SPRITECARD_TEXTURE_PP_SCALE_YAW = 0x8,
        SPRITECARD_TEXTURE_PP_SCALE_PITCH = 0x9,
        SPRITECARD_TEXTURE_PP_SCALE_RANDOM = 0xA,
        SPRITECARD_TEXTURE_PP_SCALE_NEG_RANDOM = 0xB,
        SPRITECARD_TEXTURE_PP_SCALE_RANDOM_TIME = 0xC,
        SPRITECARD_TEXTURE_PP_SCALE_NEG_RANDOM_TIME = 0xD,
    };

    enum class BlurFilterType_t : std::uint32_t {
        BLURFILTER_GAUSSIAN = 0x0,
        BLURFILTER_BOX = 0x1,
    };

    enum class StandardLightingAttenuationStyle_t : std::uint32_t {
        LIGHT_STYLE_OLD = 0x0,
        LIGHT_STYLE_NEW = 0x1,
    };

    enum class ParticleParentSetMode_t : std::uint32_t {
        PARTICLE_SET_PARENT_NO = 0x0,
        PARTICLE_SET_PARENT_IMMEDIATE = 0x1,
        PARTICLE_SET_PARENT_ROOT = 0x2,
    };

    enum class ParticleLightingQuality_t : std::int32_t {
        PARTICLE_LIGHTING_PER_PARTICLE = 0x0,
        PARTICLE_LIGHTING_PER_VERTEX = 0x1,
        PARTICLE_LIGHTING_PER_PIXEL = -1,
        PARTICLE_LIGHTING_OVERRIDE_POSITION = 0x2,
        PARTICLE_LIGHTING_OVERRIDE_COLOR = 0x3,
        PARTICLE_LIGHTING_ADD_EXTRA_LIGHT = 0x4,
    };

    enum class ParticleVolumetricSmokeCreationType_t : std::uint32_t {
        PARTICLE_VOLUMETRIC_SMOKE_TYPE_CONTINUOUS = 0x0,
        PARTICLE_VOLUMETRIC_SMOKE_TYPE_IMPULSE = 0x1,
    };

    enum class SetStatisticExpressionType_t : std::int32_t {
        SET_EXPRESSION_UNINITIALIZED = -1,
        SET_EXPRESSION_SUM = 0x0,
        SET_EXPRESSION_MEAN = 0x1,
        SET_EXPRESSION_MEDIAN = 0x2,
        SET_EXPRESSION_MODE = 0x3,
        SET_EXPRESSION_STANDARD_DEVIATION = 0x4,
        SET_EXPRESSION_MIN = 0x5,
        SET_EXPRESSION_MAX = 0x6,
    };

    enum class EventTypeSelection_t : std::uint32_t {
        PARTICLE_EVENT_TYPE_MASK_NONE = 0x0,
        PARTICLE_EVENT_TYPE_MASK_SPAWNED = 0x1,
        PARTICLE_EVENT_TYPE_MASK_KILLED = 0x2,
        PARTICLE_EVENT_TYPE_MASK_COLLISION = 0x4,
        PARTICLE_EVENT_TYPE_MASK_FIRST_COLLISION = 0x8,
        PARTICLE_EVENT_TYPE_MASK_COLLISION_STOPPED = 0x10,
        PARTICLE_EVENT_TYPE_MASK_KILLED_ON_COLLISION = 0x20,
        PARTICLE_EVENT_TYPE_MASK_USER_1 = 0x40,
        PARTICLE_EVENT_TYPE_MASK_USER_2 = 0x80,
        PARTICLE_EVENT_TYPE_MASK_USER_3 = 0x100,
        PARTICLE_EVENT_TYPE_MASK_USER_4 = 0x200,
    };

    enum class ParticleMassMode_t : std::uint32_t {
        PARTICLE_MASSMODE_RADIUS_CUBED = 0x0,
        PARTICLE_MASSMODE_RADIUS_SQUARED = 0x2,
    };

    enum class ParticleHitboxBiasType_t : std::uint32_t {
        PARTICLE_HITBOX_BIAS_ENTITY = 0x0,
        PARTICLE_HITBOX_BIAS_HITBOX = 0x1,
    };

    enum class ParticleControlPointAxis_t : std::uint32_t {
        PARTICLE_CP_AXIS_X = 0x0,
        PARTICLE_CP_AXIS_Y = 0x1,
        PARTICLE_CP_AXIS_Z = 0x2,
        PARTICLE_CP_AXIS_NEGATIVE_X = 0x3,
        PARTICLE_CP_AXIS_NEGATIVE_Y = 0x4,
        PARTICLE_CP_AXIS_NEGATIVE_Z = 0x5,
    };

    enum class ParticlePinDistance_t : std::int32_t {
        PARTICLE_PIN_DISTANCE_NONE = -1,
        PARTICLE_PIN_DISTANCE_NEIGHBOR = 0x0,
        PARTICLE_PIN_DISTANCE_FARTHEST = 0x1,
        PARTICLE_PIN_DISTANCE_FIRST = 0x2,
        PARTICLE_PIN_DISTANCE_LAST = 0x3,
        PARTICLE_PIN_DISTANCE_CENTER = 0x5,
        PARTICLE_PIN_DISTANCE_CP = 0x6,
        PARTICLE_PIN_DISTANCE_CP_PAIR_EITHER = 0x7,
        PARTICLE_PIN_DISTANCE_CP_PAIR_BOTH = 0x8,
        PARTICLE_PIN_SPEED = 0x9,
        PARTICLE_PIN_COLLECTION_AGE = 0xA,
        PARTICLE_PIN_FLOAT_VALUE = 0xB,
    };

    enum class VectorFloatExpressionType_t : std::int32_t {
        VECTOR_FLOAT_EXPRESSION_UNINITIALIZED = -1,
        VECTOR_FLOAT_EXPRESSION_DOTPRODUCT = 0x0,
        VECTOR_FLOAT_EXPRESSION_DISTANCE = 0x1,
        VECTOR_FLOAT_EXPRESSION_DISTANCESQR = 0x2,
        VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTH = 0x3,
        VECTOR_FLOAT_EXPRESSION_INPUT1_LENGTHSQR = 0x4,
        VECTOR_FLOAT_EXPRESSION_INPUT1_NOISE = 0x5,
    };

    enum class ParticleFogType_t : std::uint32_t {
        PARTICLE_FOG_GAME_DEFAULT = 0x0,
        PARTICLE_FOG_ENABLED = 0x1,
        PARTICLE_FOG_DISABLED = 0x2,
    };

    enum class VectorExpressionType_t : std::int32_t {
        VECTOR_EXPRESSION_UNINITIALIZED = -1,
        VECTOR_EXPRESSION_ADD = 0x0,
        VECTOR_EXPRESSION_SUBTRACT = 0x1,
        VECTOR_EXPRESSION_MUL = 0x2,
        VECTOR_EXPRESSION_DIVIDE = 0x3,
        VECTOR_EXPRESSION_INPUT_1 = 0x4,
        VECTOR_EXPRESSION_MIN = 0x5,
        VECTOR_EXPRESSION_MAX = 0x6,
        VECTOR_EXPRESSION_CROSSPRODUCT = 0x7,
        VECTOR_EXPRESSION_LERP = 0x8,
    };

    enum class ParticleMultiSegmentInputSelection_t : std::uint32_t {
        PARTICLE_MULTISEGMENT_SELECTION_FLOAT = 0x0,
        PARTICLE_MULTISEGMENT_SELECTION_STRING = 0x1,
    };

    enum class ParticleRotationLockType_t : std::uint32_t {
        PARTICLE_ROTATION_LOCK_NONE = 0x0,
        PARTICLE_ROTATION_LOCK_ROTATIONS = 0x1,
        PARTICLE_ROTATION_LOCK_NORMAL = 0x2,
    };

    enum class HitboxLerpType_t : std::uint32_t {
        HITBOX_LERP_LIFETIME = 0x0,
        HITBOX_LERP_CONSTANT = 0x1,
    };

    enum class ParticleAttrBoxFlags_t : std::uint32_t {
        PARTICLE_ATTR_BOX_FLAGS_NONE = 0x0,
        PARTICLE_ATTR_BOX_FLAGS_WATER = 0x1,
        PARTICLE_ATTR_BOX_FLAGS_ON_FIRE = 0x2,
        PARTICLE_ATTR_BOX_FLAGS_ELECTRIFIED = 0x4,
        PARTICLE_ATTR_BOX_FLAGS_ASLEEP = 0x8,
        PARTICLE_ATTR_BOX_FLAGS_FROZEN = 0x10,
        PARTICLE_ATTR_BOX_FLAGS_TIMED_DECAY = 0x20,
    };

    enum class ParticleTopology_t : std::uint32_t {
        PARTICLE_TOPOLOGY_POINTS = 0x0,
        PARTICLE_TOPOLOGY_LINES = 0x1,
        PARTICLE_TOPOLOGY_TRIS = 0x2,
        PARTICLE_TOPOLOGY_QUADS = 0x3,
        PARTICLE_TOPOLOGY_CUBES = 0x4,
    };

    enum class ParticleLightBehaviorChoiceList_t : std::uint32_t {
        PARTICLE_LIGHT_BEHAVIOR_FOLLOW_DIRECTION = 0x0,
        PARTICLE_LIGHT_BEHAVIOR_ROPE = 0x1,
        PARTICLE_LIGHT_BEHAVIOR_TRAILS = 0x2,
    };

    enum class ModelHitboxType_t : std::uint32_t {
        MODEL_HITBOX_TYPE_STANDARD = 0x0,
        MODEL_HITBOX_TYPE_RAW_BONES = 0x1,
        MODEL_HITBOX_TYPE_RENDERBOUNDS = 0x2,
        MODEL_HITBOX_TYPE_SNAPSHOT = 0x3,
    };

    enum class ParticleMultiSegmentCountSelection_t : std::uint32_t {
        PARTICLE_MULTISEGMENT_SEG_COUNT_7 = 0x7,
        PARTICLE_MULTISEGMENT_SEG_COUNT_14 = 0xE,
        PARTICLE_MULTISEGMENT_SEG_COUNT_16 = 0x10,
    };

    enum class ParticleOrientationType_t : std::uint32_t {
        PARTICLE_ORIENTATION_NONE = 0x0,
        PARTICLE_ORIENTATION_VELOCITY = 0x1,
        PARTICLE_ORIENTATION_NORMAL = 0x2,
        PARTICLE_ORIENTATION_ROTATION = 0x4,
    };

    enum class ParticleTraceSet_t : std::uint32_t {
        PARTICLE_TRACE_SET_ALL = 0x0,
        PARTICLE_TRACE_SET_STATIC = 0x1,
        PARTICLE_TRACE_SET_STATIC_AND_KEYFRAMED = 0x2,
        PARTICLE_TRACE_SET_DYNAMIC = 0x3,
    };

    enum class ParticleTextureLayerBlendType_t : std::uint32_t {
        SPRITECARD_TEXTURE_BLEND_MULTIPLY = 0x0,
        SPRITECARD_TEXTURE_BLEND_MOD2X = 0x1,
        SPRITECARD_TEXTURE_BLEND_REPLACE = 0x2,
        SPRITECARD_TEXTURE_BLEND_ADD = 0x3,
        SPRITECARD_TEXTURE_BLEND_SUBTRACT = 0x4,
        SPRITECARD_TEXTURE_BLEND_AVERAGE = 0x5,
        SPRITECARD_TEXTURE_BLEND_LUMINANCE = 0x6,
    };

    enum class ParticleSelection_t : std::uint32_t {
        PARTICLE_SELECTION_FIRST = 0x0,
        PARTICLE_SELECTION_LAST = 0x1,
        PARTICLE_SELECTION_NUMBER = 0x2,
    };

    enum class ParticleToolsState_t : std::int32_t {
        PARTICLE_TOOLS_STATE_ALWAYS_ON = -1,
        PARTICLE_TOOLS_STATE_TOOLS_ONLY = 0x0,
        PARTICLE_TOOLS_STATE_GAME_ONLY = 0x1,
    };

    enum class SnapshotIndexType_t : std::uint32_t {
        SNAPSHOT_INDEX_INCREMENT = 0x0,
        SNAPSHOT_INDEX_DIRECT = 0x1,
    };

    enum class ParticleOutputBlendMode_t : std::uint32_t {
        PARTICLE_OUTPUT_BLEND_MODE_ALPHA = 0x0,
        PARTICLE_OUTPUT_BLEND_MODE_ADD = 0x1,
        PARTICLE_OUTPUT_BLEND_MODE_BLEND_ADD = 0x2,
        PARTICLE_OUTPUT_BLEND_MODE_HALF_BLEND_ADD = 0x3,
        PARTICLE_OUTPUT_BLEND_MODE_NEG_HALF_BLEND_ADD = 0x4,
        PARTICLE_OUTPUT_BLEND_MODE_MOD2X = 0x5,
        PARTICLE_OUTPUT_BLEND_MODE_LIGHTEN = 0x6,
    };

    enum class ParticleLightnintBranchBehavior_t : std::uint32_t {
        PARTICLE_LIGHTNING_BRANCH_CURRENT_DIR = 0x0,
        PARTICLE_LIGHTNING_BRANCH_ENDPOINT_DIR = 0x1,
    };

    enum class MaterialProxyType_t : std::uint32_t {
        MATERIAL_PROXY_STATUS_EFFECT = 0x0,
        MATERIAL_PROXY_TINT = 0x1,
    };

    enum class ParticleDepthFeatheringMode_t : std::uint32_t {
        PARTICLE_DEPTH_FEATHERING_OFF = 0x0,
        PARTICLE_DEPTH_FEATHERING_ON_OPTIONAL = 0x1,
        PARTICLE_DEPTH_FEATHERING_ON_REQUIRED = 0x2,
    };

    enum class ParticleLightUnitChoiceList_t : std::uint32_t {
        PARTICLE_LIGHT_UNIT_CANDELAS = 0x0,
        PARTICLE_LIGHT_UNIT_LUMENS = 0x1,
    };

    enum class ParticleMultiSegmentSpecialCharacter_t : std::int32_t {
        PARTICLE_MULTISEGMENT_SPECIAL_NONE = -1,
        PARTICLE_MULTISEGMENT_SPECIAL_DECIMAL = 0x0,
        PARTICLE_MULTISEGMENT_SPECIAL_COLON = 0x1,
        PARTICLE_MULTISEGMENT_SPECIAL_DEGREES = 0x2,
    };

    enum class ParticleFalloffFunction_t : std::uint32_t {
        PARTICLE_FALLOFF_CONSTANT = 0x0,
        PARTICLE_FALLOFF_LINEAR = 0x1,
        PARTICLE_FALLOFF_EXPONENTIAL = 0x2,
    };

    enum class ParticleSequenceCropOverride_t : std::int32_t {
        PARTICLE_SEQUENCE_CROP_OVERRIDE_DEFAULT = -1,
        PARTICLE_SEQUENCE_CROP_OVERRIDE_FORCE_OFF = 0x0,
        PARTICLE_SEQUENCE_CROP_OVERRIDE_FORCE_ON = 0x1,
    };

    enum class ParticleDetailLevel_t : std::uint32_t {
        PARTICLEDETAIL_LOW = 0x0,
        PARTICLEDETAIL_MEDIUM = 0x1,
        PARTICLEDETAIL_HIGH = 0x2,
        PARTICLEDETAIL_ULTRA = 0x3,
    };

    enum class BBoxVolumeType_t : std::uint32_t {
        BBOX_VOLUME = 0x0,
        BBOX_DIMENSIONS = 0x1,
        BBOX_MINS_MAXS = 0x2,
        BBOX_RADIUS = 0x3,
    };

    enum class SpriteCardTextureType_t : std::uint32_t {
        SPRITECARD_TEXTURE_DIFFUSE = 0x0,
        SPRITECARD_TEXTURE_ZOOM = 0x1,
        SPRITECARD_TEXTURE_1D_COLOR_LOOKUP = 0x2,
        SPRITECARD_TEXTURE_UVDISTORTION = 0x3,
        SPRITECARD_TEXTURE_UVDISTORTION_ZOOM = 0x4,
        SPRITECARD_TEXTURE_NORMALMAP = 0x5,
        SPRITECARD_TEXTURE_ANIMMOTIONVEC = 0x6,
        SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_A = 0x7,
        SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_B = 0x8,
        SPRITECARD_TEXTURE_SPHERICAL_HARMONICS_C = 0x9,
        SPRITECARD_TEXTURE_DEPTH = 0xA,
        SPRITECARD_TEXTURE_ILLUMINATION_GRADIENT = 0xB,
    };

    enum class ParticleAlphaReferenceType_t : std::uint32_t {
        PARTICLE_ALPHA_REFERENCE_ALPHA_ALPHA = 0x0,
        PARTICLE_ALPHA_REFERENCE_OPAQUE_ALPHA = 0x1,
        PARTICLE_ALPHA_REFERENCE_ALPHA_OPAQUE = 0x2,
        PARTICLE_ALPHA_REFERENCE_OPAQUE_OPAQUE = 0x3,
    };

    enum class SpriteCardTextureChannel_t : std::uint32_t {
        SPRITECARD_TEXTURE_CHANNEL_MIX_RGB = 0x0,
        SPRITECARD_TEXTURE_CHANNEL_MIX_RGBA = 0x1,
        SPRITECARD_TEXTURE_CHANNEL_MIX_A = 0x2,
        SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_A = 0x3,
        SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_ALPHAMASK = 0x4,
        SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_RGBMASK = 0x5,
        SPRITECARD_TEXTURE_CHANNEL_MIX_RGBA_RGBALPHA = 0x6,
        SPRITECARD_TEXTURE_CHANNEL_MIX_A_RGBALPHA = 0x7,
        SPRITECARD_TEXTURE_CHANNEL_MIX_RGB_A_RGBALPHA = 0x8,
        SPRITECARD_TEXTURE_CHANNEL_MIX_R = 0x9,
        SPRITECARD_TEXTURE_CHANNEL_MIX_G = 0xA,
        SPRITECARD_TEXTURE_CHANNEL_MIX_B = 0xB,
        SPRITECARD_TEXTURE_CHANNEL_MIX_RALPHA = 0xC,
        SPRITECARD_TEXTURE_CHANNEL_MIX_GALPHA = 0xD,
        SPRITECARD_TEXTURE_CHANNEL_MIX_BALPHA = 0xE,
    };

    enum class ParticleVolumetricSmokeType_t : std::uint32_t {
        PARTICLE_VOLUMETRIC_SMOKE_TYPE_EMISSION = 0x0,
        PARTICLE_VOLUMETRIC_SMOKE_TYPE_SINK = 0x1,
        PARTICLE_VOLUMETRIC_SMOKE_TYPE_REPEL = 0x2,
    };

    enum class RenderModelSubModelFieldType_t : std::uint32_t {
        SUBMODEL_AS_BODYGROUP_SUBMODEL = 0x0,
        SUBMODEL_AS_MESHGROUP_INDEX = 0x1,
        SUBMODEL_AS_MESHGROUP_MASK = 0x2,
        SUBMODEL_IGNORED_USE_MODEL_DEFAULT_MESHGROUP_MASK = 0x3,
    };

    enum class ParticleHitboxDataSelection_t : std::uint32_t {
        PARTICLE_HITBOX_AVERAGE_SPEED = 0x0,
        PARTICLE_HITBOX_COUNT = 0x1,
    };

    enum class ParticleOrientationChoiceList_t : std::uint32_t {
        PARTICLE_ORIENTATION_SCREEN_ALIGNED = 0x0,
        PARTICLE_ORIENTATION_SCREEN_Z_ALIGNED = 0x1,
        PARTICLE_ORIENTATION_WORLD_Z_ALIGNED = 0x2,
        PARTICLE_ORIENTATION_ALIGN_TO_PARTICLE_NORMAL = 0x3,
        PARTICLE_ORIENTATION_SCREENALIGN_TO_PARTICLE_NORMAL = 0x4,
        PARTICLE_ORIENTATION_FULL_3AXIS_ROTATION = 0x5,
    };

    enum class ParticleCollisionMode_t : std::int32_t {
        COLLISION_MODE_PER_PARTICLE_TRACE = 0x3,
        COLLISION_MODE_USE_NEAREST_TRACE = 0x2,
        COLLISION_MODE_PER_FRAME_PLANESET = 0x1,
        COLLISION_MODE_INITIAL_TRACE_DOWN = 0x0,
        COLLISION_MODE_DISABLED = -1,
    };

    enum class ParticleSortingChoiceList_t : std::uint32_t {
        PARTICLE_SORTING_NEAREST = 0x0,
        PARTICLE_SORTING_CREATION_TIME = 0x1,
    };

    enum class ParticleEndcapMode_t : std::int32_t {
        PARTICLE_ENDCAP_ALWAYS_ON = -1,
        PARTICLE_ENDCAP_ENDCAP_OFF = 0x0,
        PARTICLE_ENDCAP_ENDCAP_ON = 0x1,
    };

    enum class ClosestPointTestType_t : std::uint32_t {
        PARTICLE_CLOSEST_TYPE_BOX = 0x0,
        PARTICLE_CLOSEST_TYPE_CAPSULE = 0x1,
        PARTICLE_CLOSEST_TYPE_HYBRID = 0x2,
    };

    enum class ParticleImpulseType_t : std::uint32_t {
        IMPULSE_TYPE_NONE = 0x0,
        IMPULSE_TYPE_GENERIC = 0x1,
        IMPULSE_TYPE_ROPE = 0x2,
        IMPULSE_TYPE_EXPLOSION = 0x4,
        IMPULSE_TYPE_EXPLOSION_UNDERWATER = 0x8,
        IMPULSE_TYPE_PARTICLE_SYSTEM = 0x10,
    };

    enum class ParticleLiquidContents_t : std::uint32_t {
        PARTICLE_LIQUID_NONE = 0x0,
        PARTICLE_LIQUID_OIL = 0x1,
        PARTICLE_LIQUID_WATER = 0x2,
    };

    enum class SpriteCardShaderType_t : std::uint32_t {
        SPRITECARD_SHADER_BASE = 0x0,
        SPRITECARD_SHADER_CUSTOM = 0x1,
    };

    enum class ParticleOmni2LightTypeChoiceList_t : std::uint32_t {
        PARTICLE_OMNI2_LIGHT_TYPE_POINT = 0x0,
        PARTICLE_OMNI2_LIGHT_TYPE_SPHERE = 0x1,
    };

    enum class ParticleLightFogLightingMode_t : std::uint32_t {
        PARTICLE_LIGHT_FOG_LIGHTING_MODE_NONE = 0x0,
        PARTICLE_LIGHT_FOG_LIGHTING_MODE_DYNAMIC = 0x2,
        PARTICLE_LIGHT_FOG_LIGHTING_MODE_DYNAMIC_NOSHADOWS = 0x4,
    };

    enum class ParticleLightTypeChoiceList_t : std::uint32_t {
        PARTICLE_LIGHT_TYPE_POINT = 0x0,
        PARTICLE_LIGHT_TYPE_SPOT = 0x1,
        PARTICLE_LIGHT_TYPE_FX = 0x2,
        PARTICLE_LIGHT_TYPE_CAPSULE = 0x3,
    };

    enum class ParticleOrientationSetMode_t : std::int32_t {
        PARTICLE_ORIENTATION_SET_NONE = -1,
        PARTICLE_ORIENTATION_SET_FROM_VELOCITY = 0x0,
        PARTICLE_ORIENTATION_SET_FROM_NORMAL = 0x1,
        PARTICLE_ORIENTATION_SET_FROM_ROTATIONS = 0x2,
    };

    enum class ParticleCollisionMask_t : std::int64_t {
        PARTICLE_MASK_ALL = -1,
        PARTICLE_MASK_SOLID = 0xC3001,
        PARTICLE_MASK_WATER = 0x18000,
        PARTICLE_MASK_SOLID_WATER = 0xDB001,
        PARTICLE_MASK_SHOT = 0x1C1003,
        PARTICLE_MASK_SHOT_BRUSHONLY = 0x101001,
        PARTICLE_MASK_SHOT_HULL = 0x1C3001,
        PARTICLE_MASK_OPAQUE = 0x80,
        PARTICLE_MASK_DEFAULTPLAYERSOLID = 0xC3011,
        PARTICLE_MASK_NPCSOLID = 0xC3021,
    };

    enum class TextureRepetitionMode_t : std::uint32_t {
        TEXTURE_REPETITION_PARTICLE = 0x0,
        TEXTURE_REPETITION_PATH = 0x1,
    };

    class C_OP_OscillateVectorSimple {
    public:
        SCHEMA_FIELD(::Vector                        , m_Rate                                          , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_Frequency                                     , 0x1E4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x1F0)
        SCHEMA_FIELD(float                           , m_flOscMult                                     , 0x1F4)
        SCHEMA_FIELD(float                           , m_flOscAdd                                      , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bOffset                                       , 0x1FC)
    };

    class CPulseCell_BaseYieldingInflow {
    public:
    };

    class C_OP_RenderMaterialProxy {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nMaterialControlPoint                         , 0x228)
        SCHEMA_FIELD(MaterialProxyType_t             , m_nProxyType                                    , 0x22C)
        SCHEMA_FIELD(CUtlVector<MaterialVariable_t>  , m_MaterialVars                                  , 0x230)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hOverrideMaterial                             , 0x248)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMaterialOverrideEnabled                     , 0x250)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorScale                                 , 0x3C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flAlpha                                       , 0xA78)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0xBE8)
    };

    class C_OP_EnableChildrenFromParentParticleCount {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstChild                                   , 0x1E4)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nNumChildrenToEnable                          , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bDisableChildren                              , 0x358)
        SCHEMA_FIELD(bool                            , m_bPlayEndcapOnStop                             , 0x359)
        SCHEMA_FIELD(bool                            , m_bDestroyImmediately                           , 0x35A)
    };

    class C_INIT_RandomTrailLength {
    public:
        SCHEMA_FIELD(float                           , m_flMinLength                                   , 0x1E0)
        SCHEMA_FIELD(float                           , m_flMaxLength                                   , 0x1E4)
        SCHEMA_FIELD(float                           , m_flLengthRandExponent                          , 0x1E8)
    };

    class C_INIT_RemapTransformToVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vInputMin                                     , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vInputMax                                     , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vOutputMin                                    , 0x1FC)
        SCHEMA_FIELD(::Vector                        , m_vOutputMax                                    , 0x208)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x218)
        SCHEMA_FIELD(CParticleTransformInput         , m_LocalSpaceTransform                           , 0x280)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x2E8)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x2EC)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x2F0)
        SCHEMA_FIELD(bool                            , m_bOffset                                       , 0x2F4)
        SCHEMA_FIELD(bool                            , m_bAccelerate                                   , 0x2F5)
        SCHEMA_FIELD(float                           , m_flRemapBias                                   , 0x2F8)
    };

    class CPulseCell_Inflow_Yield {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_UnyieldResume                                 , 0x48)
    };

    class C_OP_RampScalarLinearSimple {
    public:
        SCHEMA_FIELD(float                           , m_Rate                                          , 0x1D8)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x1DC)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x210)
    };

    class C_OP_RenderVRHapticEvent {
    public:
        SCHEMA_FIELD(ParticleVRHandChoiceList_t      , m_nHand                                         , 0x228)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputHandCP                                 , 0x22C)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputField                                  , 0x230)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flAmplitude                                   , 0x238)
    };

    class C_OP_RenderTreeShake {
    public:
        SCHEMA_FIELD(float                           , m_flPeakStrength                                , 0x228)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nPeakStrengthFieldOverride                    , 0x22C)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x230)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nRadiusFieldOverride                          , 0x234)
        SCHEMA_FIELD(float                           , m_flShakeDuration                               , 0x238)
        SCHEMA_FIELD(float                           , m_flTransitionTime                              , 0x23C)
        SCHEMA_FIELD(float                           , m_flTwistAmount                                 , 0x240)
        SCHEMA_FIELD(float                           , m_flRadialAmount                                , 0x244)
        SCHEMA_FIELD(float                           , m_flControlPointOrientationAmount               , 0x248)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointForLinearDirection               , 0x24C)
    };

    class C_OP_PercentageBetweenTransformsVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMin                                  , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMax                                  , 0x1F0)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformStart                                , 0x200)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformEnd                                  , 0x268)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x2D0)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x2D4)
        SCHEMA_FIELD(bool                            , m_bRadialCheck                                  , 0x2D5)
    };

    class CPulseCell_IntervalTimer_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
        SCHEMA_FIELD(float                           , m_flWaitInterval                                , 0x8)
        SCHEMA_FIELD(float                           , m_flWaitIntervalHigh                            , 0xC)
        SCHEMA_FIELD(bool                            , m_bCompleteOnNextWake                           , 0x10)
    };

    class C_INIT_ColorLitPerParticle {
    public:
        SCHEMA_FIELD(::Color                         , m_ColorMin                                      , 0x1F8)
        SCHEMA_FIELD(::Color                         , m_ColorMax                                      , 0x1FC)
        SCHEMA_FIELD(::Color                         , m_TintMin                                       , 0x200)
        SCHEMA_FIELD(::Color                         , m_TintMax                                       , 0x204)
        SCHEMA_FIELD(float                           , m_flTintPerc                                    , 0x208)
        SCHEMA_FIELD(ParticleColorBlendMode_t        , m_nTintBlendMode                                , 0x20C)
        SCHEMA_FIELD(float                           , m_flLightAmplification                          , 0x210)
    };

    class C_OP_FadeAndKillForTracers {
    public:
        SCHEMA_FIELD(float                           , m_flStartFadeInTime                             , 0x1D8)
        SCHEMA_FIELD(float                           , m_flEndFadeInTime                               , 0x1DC)
        SCHEMA_FIELD(float                           , m_flStartFadeOutTime                            , 0x1E0)
        SCHEMA_FIELD(float                           , m_flEndFadeOutTime                              , 0x1E4)
        SCHEMA_FIELD(float                           , m_flStartAlpha                                  , 0x1E8)
        SCHEMA_FIELD(float                           , m_flEndAlpha                                    , 0x1EC)
    };

    class C_INIT_CreateInEpitrochoid {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nComponent1                                   , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent2                                   , 0x1E4)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flParticleDensity                             , 0x250)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOffset                                      , 0x3C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadius1                                     , 0x530)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadius2                                     , 0x6A0)
        SCHEMA_FIELD(bool                            , m_bUseCount                                     , 0x810)
        SCHEMA_FIELD(bool                            , m_bUseLocalCoords                               , 0x811)
        SCHEMA_FIELD(bool                            , m_bOffsetExistingPos                            , 0x812)
    };

    class ParticleControlPointDriver_t {
    public:
        SCHEMA_FIELD(ParticleParamID_t               , m_iControlPoint                                 , 0x0)
        SCHEMA_FIELD(ParticleAttachment_t            , m_iAttachType                                   , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_attachmentName                                , 0x18)
        SCHEMA_FIELD(::Vector                        , m_vecOffset                                     , 0x20)
        SCHEMA_FIELD(::QAngle                        , m_angOffset                                     , 0x2C)
        SCHEMA_FIELD(::CUtlString                    , m_entityName                                    , 0x38)
    };

    class C_OP_RampScalarSpline {
    public:
        SCHEMA_FIELD(float                           , m_RateMin                                       , 0x1D8)
        SCHEMA_FIELD(float                           , m_RateMax                                       , 0x1DC)
        SCHEMA_FIELD(float                           , m_flStartTime_min                               , 0x1E0)
        SCHEMA_FIELD(float                           , m_flStartTime_max                               , 0x1E4)
        SCHEMA_FIELD(float                           , m_flEndTime_min                                 , 0x1E8)
        SCHEMA_FIELD(float                           , m_flEndTime_max                                 , 0x1EC)
        SCHEMA_FIELD(float                           , m_flBias                                        , 0x1F0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x220)
        SCHEMA_FIELD(bool                            , m_bProportionalOp                               , 0x224)
        SCHEMA_FIELD(bool                            , m_bEaseOut                                      , 0x225)
    };

    class C_INIT_RemapParticleCountToNamedModelBodyPartScalar {
    public:
    };

    class C_OP_RemapDotProductToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInputCP1                                     , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nInputCP2                                     , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutVectorField                               , 0x1EC)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInputMin                                    , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInputMax                                    , 0x360)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOutputMin                                   , 0x4D0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOutputMax                                   , 0x640)
    };

    class C_OP_RemapAverageScalarValuetoCP {
    public:
        SCHEMA_FIELD(SetStatisticExpressionType_t    , m_nExpression                                   , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDecimalPlaces                               , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointNumber                        , 0x358)
        SCHEMA_FIELD(std::int32_t                    , m_nOutVectorField                               , 0x35C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x360)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x368)
    };

    class C_OP_RenderClothForce {
    public:
    };

    class C_INIT_RandomVector {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecMin                                        , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecMax                                        , 0x1EC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1F8)
        SCHEMA_FIELD(CRandomNumberGeneratorParameters, m_randomnessParameters                          , 0x1FC)
    };

    class CParticleSystemDefinition {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nBehaviorVersion                              , 0x8)
        SCHEMA_FIELD(CUtlVector<CParticleFunctionPreEmission*>, m_PreEmissionOperators                          , 0x10)
        SCHEMA_FIELD(CUtlVector<CParticleFunctionEmitter*>, m_Emitters                                      , 0x28)
        SCHEMA_FIELD(CUtlVector<CParticleFunctionInitializer*>, m_Initializers                                  , 0x40)
        SCHEMA_FIELD(CUtlVector<CParticleFunctionOperator*>, m_Operators                                     , 0x58)
        SCHEMA_FIELD(CUtlVector<CParticleFunctionForce*>, m_ForceGenerators                               , 0x70)
        SCHEMA_FIELD(CUtlVector<CParticleFunctionConstraint*>, m_Constraints                                   , 0x88)
        SCHEMA_FIELD(CUtlVector<CParticleFunctionRenderer*>, m_Renderers                                     , 0xA0)
        SCHEMA_FIELD(CUtlVector<ParticleChildrenInfo_t>, m_Children                                      , 0xB8)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstMultipleOverride_BackwardCompat         , 0x178)
        SCHEMA_FIELD(std::int32_t                    , m_nInitialParticles                             , 0x258)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxParticles                                 , 0x25C)
        SCHEMA_FIELD(std::int32_t                    , m_nGroupID                                      , 0x260)
        SCHEMA_FIELD(::Vector                        , m_BoundingBoxMin                                , 0x264)
        SCHEMA_FIELD(::Vector                        , m_BoundingBoxMax                                , 0x270)
        SCHEMA_FIELD(float                           , m_flDepthSortBias                               , 0x27C)
        SCHEMA_FIELD(std::int32_t                    , m_nSortOverridePositionCP                       , 0x280)
        SCHEMA_FIELD(bool                            , m_bInfiniteBounds                               , 0x284)
        SCHEMA_FIELD(bool                            , m_bEnableNamedValues                            , 0x285)
        SCHEMA_FIELD(::CUtlString                    , m_NamedValueDomain                              , 0x288)
        SCHEMA_FIELD(CUtlVector<ParticleNamedValueSource_t*>, m_NamedValueLocals                              , 0x290)
        SCHEMA_FIELD(::Color                         , m_ConstantColor                                 , 0x2A8)
        SCHEMA_FIELD(::Vector                        , m_ConstantNormal                                , 0x2AC)
        SCHEMA_FIELD(float                           , m_flConstantRadius                              , 0x2B8)
        SCHEMA_FIELD(float                           , m_flConstantRotation                            , 0x2BC)
        SCHEMA_FIELD(float                           , m_flConstantRotationSpeed                       , 0x2C0)
        SCHEMA_FIELD(float                           , m_flConstantLifespan                            , 0x2C4)
        SCHEMA_FIELD(std::int32_t                    , m_nConstantSequenceNumber                       , 0x2C8)
        SCHEMA_FIELD(std::int32_t                    , m_nConstantSequenceNumber1                      , 0x2CC)
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPoint                         , 0x2D0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSnapshot>, m_hSnapshot                                     , 0x2D8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_pszCullReplacementName                        , 0x2E0)
        SCHEMA_FIELD(float                           , m_flCullRadius                                  , 0x2E8)
        SCHEMA_FIELD(float                           , m_flCullFillCost                                , 0x2EC)
        SCHEMA_FIELD(std::int32_t                    , m_nCullControlPoint                             , 0x2F0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_hFallback                                     , 0x2F8)
        SCHEMA_FIELD(std::int32_t                    , m_nFallbackMaxCount                             , 0x300)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_hLowViolenceDef                               , 0x308)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_hReferenceReplacement                         , 0x310)
        SCHEMA_FIELD(float                           , m_flPreSimulationTime                           , 0x318)
        SCHEMA_FIELD(float                           , m_flStopSimulationAfterTime                     , 0x31C)
        SCHEMA_FIELD(float                           , m_flMaximumTimeStep                             , 0x320)
        SCHEMA_FIELD(float                           , m_flMaximumSimTime                              , 0x324)
        SCHEMA_FIELD(float                           , m_flMinimumSimTime                              , 0x328)
        SCHEMA_FIELD(float                           , m_flMinimumTimeStep                             , 0x32C)
        SCHEMA_FIELD(std::int32_t                    , m_nMinimumFrames                                , 0x330)
        SCHEMA_FIELD(bool                            , m_bIsGPUParticleSystem                          , 0x334)
        SCHEMA_FIELD(std::int32_t                    , m_nMinCPULevel                                  , 0x338)
        SCHEMA_FIELD(std::int32_t                    , m_nMinGPULevel                                  , 0x33C)
        SCHEMA_FIELD(float                           , m_flNoDrawTimeToGoToSleep                       , 0x340)
        SCHEMA_FIELD(float                           , m_flMaxDrawDistance                             , 0x344)
        SCHEMA_FIELD(float                           , m_flStartFadeDistance                           , 0x348)
        SCHEMA_FIELD(float                           , m_flMaxCreationDistance                         , 0x34C)
        SCHEMA_FIELD(std::int32_t                    , m_nAggregationMinAvailableParticles             , 0x350)
        SCHEMA_FIELD(float                           , m_flAggregateRadius                             , 0x354)
        SCHEMA_FIELD(bool                            , m_bShouldBatch                                  , 0x358)
        SCHEMA_FIELD(bool                            , m_bShouldHitboxesFallbackToRenderBounds         , 0x359)
        SCHEMA_FIELD(bool                            , m_bShouldHitboxesFallbackToSnapshot             , 0x35A)
        SCHEMA_FIELD(bool                            , m_bShouldHitboxesFallbackToCollisionHulls       , 0x35B)
        SCHEMA_FIELD(InheritableBoolType_t           , m_nViewModelEffect                              , 0x35C)
        SCHEMA_FIELD(bool                            , m_bScreenSpaceEffect                            , 0x360)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pszTargetLayerID                              , 0x368)
        SCHEMA_FIELD(std::int32_t                    , m_nSkipRenderControlPoint                       , 0x370)
        SCHEMA_FIELD(std::int32_t                    , m_nAllowRenderControlPoint                      , 0x374)
        SCHEMA_FIELD(bool                            , m_bShouldSort                                   , 0x378)
        SCHEMA_FIELD(CUtlVector<ParticleControlPointConfiguration_t>, m_controlPointConfigurations                    , 0x3C0)
    };

    class CPulseCell_IsRequirementValid_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bIsValid                                      , 0x0)
    };

    class C_INIT_RandomLifeTime {
    public:
        SCHEMA_FIELD(float                           , m_fLifetimeMin                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_fLifetimeMax                                  , 0x1E4)
        SCHEMA_FIELD(float                           , m_fLifetimeRandExponent                         , 0x1E8)
    };

    class CBaseTrailRenderer {
    public:
        SCHEMA_FIELD(ParticleOrientationChoiceList_t , m_nOrientationType                              , 0x2DF0)
        SCHEMA_FIELD(std::int32_t                    , m_nOrientationControlPoint                      , 0x2DF4)
        SCHEMA_FIELD(float                           , m_flMinSize                                     , 0x2DF8)
        SCHEMA_FIELD(float                           , m_flMaxSize                                     , 0x2DFC)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flStartFadeSize                               , 0x2E00)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flEndFadeSize                                 , 0x2F70)
        SCHEMA_FIELD(bool                            , m_bClampV                                       , 0x30E0)
    };

    class C_OP_ColorInterpolateRandom {
    public:
        SCHEMA_FIELD(::Color                         , m_ColorFadeMin                                  , 0x1D8)
        SCHEMA_FIELD(::Color                         , m_ColorFadeMax                                  , 0x1F4)
        SCHEMA_FIELD(float                           , m_flFadeStartTime                               , 0x204)
        SCHEMA_FIELD(float                           , m_flFadeEndTime                                 , 0x208)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x20C)
        SCHEMA_FIELD(bool                            , m_bEaseInOut                                    , 0x210)
    };

    class PointDefinition_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x0)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0x4)
        SCHEMA_FIELD(::Vector                        , m_vOffset                                       , 0x8)
    };

    class CPulseCell_FireCursors {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outflows                                      , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class C_OP_NormalizeVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1DC)
    };

    class C_OP_LightningSnapshotGenerator {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPSnapshot                                   , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPStartPnt                                   , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nCPEndPnt                                     , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flSegments                                    , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOffset                                      , 0x360)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOffsetDecay                                 , 0x4D0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRecalcRate                                  , 0x640)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flUVScale                                     , 0x7B0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flUVOffset                                    , 0x920)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flSplitRate                                   , 0xA90)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBranchTwist                                 , 0xC00)
        SCHEMA_FIELD(ParticleLightnintBranchBehavior_t, m_nBranchBehavior                               , 0xD70)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadiusStart                                 , 0xD78)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadiusEnd                                   , 0xEE8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDedicatedPool                               , 0x1058)
    };

    class C_OP_LocalAccelerationForce {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleCP                                      , 0x1EC)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecAccel                                      , 0x1F0)
    };

    class C_INIT_LifespanFromVelocity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecComponentScale                             , 0x1E0)
        SCHEMA_FIELD(float                           , m_flTraceOffset                                 , 0x1EC)
        SCHEMA_FIELD(float                           , m_flMaxTraceLength                              , 0x1F0)
        SCHEMA_FIELD(float                           , m_flTraceTolerance                              , 0x1F4)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxPlanes                                    , 0x1F8)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x200)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x280)
        SCHEMA_FIELD(bool                            , m_bIncludeWater                                 , 0x290)
    };

    class C_OP_DirectionBetweenVecsToVec {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPoint1                                     , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPoint2                                     , 0x898)
    };

    class C_INIT_CreationNoise {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bAbsVal                                       , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bAbsValInv                                    , 0x1E5)
        SCHEMA_FIELD(float                           , m_flOffset                                      , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F0)
        SCHEMA_FIELD(float                           , m_flNoiseScale                                  , 0x1F4)
        SCHEMA_FIELD(float                           , m_flNoiseScaleLoc                               , 0x1F8)
        SCHEMA_FIELD(::Vector                        , m_vecOffsetLoc                                  , 0x1FC)
        SCHEMA_FIELD(float                           , m_flWorldTimeScale                              , 0x208)
    };

    class C_OP_SetCPOrientationToPointAtCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInputCP                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x1E4)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInterpolation                               , 0x1E8)
        SCHEMA_FIELD(bool                            , m_b2DOrientation                                , 0x358)
        SCHEMA_FIELD(bool                            , m_bAvoidSingularity                             , 0x359)
        SCHEMA_FIELD(bool                            , m_bPointAway                                    , 0x35A)
    };

    class C_OP_SetControlPointToWaterSurface {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSourceCP                                     , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nDestCP                                       , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nFlowCP                                       , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nActiveCP                                     , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nActiveCPField                                , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRetestRate                                  , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bAdaptiveThreshold                            , 0x368)
    };

    class C_OP_PerParticleForce {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flForceScale                                  , 0x1E8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vForce                                        , 0x358)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0xA10)
    };

    class C_OP_WaterImpulseRenderer {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPos                                        , 0x228)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadius                                      , 0x8E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMagnitude                                   , 0xA50)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flShape                                       , 0xBC0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flWindSpeed                                   , 0xD30)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flWobble                                      , 0xEA0)
        SCHEMA_FIELD(bool                            , m_bIsRadialWind                                 , 0x1010)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nEventType                                    , 0x1014)
    };

    class CPulseCell_Step_PublicOutput {
    public:
        SCHEMA_FIELD(PulseRuntimeOutputIndex_t       , m_OutputIndex                                   , 0x48)
    };

    class C_OP_GameDecalRenderer {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_sDecalGroupName                               , 0x228)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nEventType                                    , 0x230)
        SCHEMA_FIELD(ParticleCollisionMask_t         , m_nInteractionMask                              , 0x238)
        SCHEMA_FIELD(ParticleCollisionGroup_t        , m_nCollisionGroup                               , 0x240)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecStartPos                                   , 0x248)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecEndPos                                     , 0x900)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flTraceBloat                                  , 0xFB8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flDecalSize                                   , 0x1128)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_nDecalGroupIndex                              , 0x1298)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flDecalRotation                               , 0x1408)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vModulationColor                              , 0x1578)
        SCHEMA_FIELD(bool                            , m_bUseGameDefaultDecalSize                      , 0x1C30)
        SCHEMA_FIELD(bool                            , m_bRandomDecalRotation                          , 0x1C31)
        SCHEMA_FIELD(bool                            , m_bRandomlySelectDecalInGroup                   , 0x1C32)
        SCHEMA_FIELD(bool                            , m_bNoDecalsOnOwner                              , 0x1C33)
        SCHEMA_FIELD(bool                            , m_bVisualizeTraces                              , 0x1C34)
    };

    class C_OP_RenderPostProcessing {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flPostProcessStrength                         , 0x228)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCPostProcessingResource>, m_hPostTexture                                  , 0x398)
        SCHEMA_FIELD(ParticlePostProcessPriorityGroup_t, m_nPriority                                     , 0x3A0)
    };

    class C_OP_SetVectorAttributeToVectorExpression {
    public:
        SCHEMA_FIELD(VectorExpressionType_t          , m_nExpression                                   , 0x1D8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput1                                       , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput2                                       , 0x898)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLerp                                        , 0xF50)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x10C0)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x10C4)
        SCHEMA_FIELD(bool                            , m_bNormalizedOutput                             , 0x10C8)
    };

    class C_OP_RemapParticleCountOnScalarEndCap {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nInputMin                                     , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nInputMax                                     , 0x1E0)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bBackwards                                    , 0x1EC)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1F0)
    };

    class C_INIT_SetHitboxToClosest {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nDesiredHitbox                                , 0x1E4)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecHitBoxScale                                , 0x1E8)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x8A0)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x920)
        SCHEMA_FIELD(bool                            , m_bUseClosestPointOnHitbox                      , 0x921)
        SCHEMA_FIELD(ClosestPointTestType_t          , m_nTestType                                     , 0x924)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flHybridRatio                                 , 0x928)
        SCHEMA_FIELD(bool                            , m_bUpdatePosition                               , 0xA98)
    };

    class C_OP_ExternalWindForce {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecSamplePosition                             , 0x1E8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecScale                                      , 0x8A0)
        SCHEMA_FIELD(bool                            , m_bSampleWind                                   , 0xF58)
        SCHEMA_FIELD(bool                            , m_bSampleWater                                  , 0xF59)
        SCHEMA_FIELD(bool                            , m_bDampenNearWaterPlane                         , 0xF5A)
        SCHEMA_FIELD(bool                            , m_bSampleGravity                                , 0xF5B)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecGravityForce                               , 0xF60)
        SCHEMA_FIELD(bool                            , m_bUseBasicMovementGravity                      , 0x1618)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLocalGravityScale                           , 0x1620)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLocalBuoyancyScale                          , 0x1790)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecBuoyancyForce                              , 0x1900)
    };

    class C_INIT_RemapTransformOrientationToRotations {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecRotation                                   , 0x248)
        SCHEMA_FIELD(bool                            , m_bUseQuat                                      , 0x254)
        SCHEMA_FIELD(bool                            , m_bWriteNormal                                  , 0x255)
    };

    class CPulseCell_Step_DebugLog {
    public:
    };

    class CPulseCell_Inflow_GraphHook {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_HookName                                      , 0x80)
    };

    class C_OP_CreateParticleSystemRenderer {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_hEffect                                       , 0x228)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nEventType                                    , 0x230)
        SCHEMA_FIELD(CUtlLeanVector<CPAssignment_t>  , m_vecCPs                                        , 0x238)
        SCHEMA_FIELD(::CUtlString                    , m_szParticleConfig                              , 0x248)
        SCHEMA_FIELD(CPerParticleVecInput            , m_AggregationPos                                , 0x250)
    };

    class IParticleSystemDefinition {
    public:
    };

    class CParticleFunctionPreEmission {
    public:
        SCHEMA_FIELD(bool                            , m_bRunOnce                                      , 0x1D8)
    };

    class C_OP_RenderPoints {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0x228)
    };

    class C_OP_DistanceBetweenTransforms {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformStart                                , 0x1E0)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformEnd                                  , 0x248)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMin                                    , 0x2B0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMax                                    , 0x420)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMin                                   , 0x590)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMax                                   , 0x700)
        SCHEMA_FIELD(float                           , m_flMaxTraceLength                              , 0x870)
        SCHEMA_FIELD(float                           , m_flLOSScale                                    , 0x874)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x878)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x8F8)
        SCHEMA_FIELD(bool                            , m_bLOS                                          , 0x8FC)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x900)
    };

    class C_OP_SetControlPointToVectorExpression {
    public:
        SCHEMA_FIELD(VectorExpressionType_t          , m_nExpression                                   , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x1E4)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vInput1                                       , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vInput2                                       , 0x8A0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLerp                                        , 0xF58)
        SCHEMA_FIELD(bool                            , m_bNormalizedOutput                             , 0x10C8)
    };

    class C_OP_RenderScreenVelocityRotate {
    public:
        SCHEMA_FIELD(float                           , m_flRotateRateDegrees                           , 0x228)
        SCHEMA_FIELD(float                           , m_flForwardDegrees                              , 0x22C)
    };

    class C_OP_RemapDensityToVector {
    public:
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flDensityMin                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_flDensityMax                                  , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMin                                  , 0x1E8)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMax                                  , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bUseParentDensity                             , 0x200)
        SCHEMA_FIELD(std::int32_t                    , m_nVoxelGridResolution                          , 0x204)
    };

    class C_OP_LerpEndCapScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flOutput                                      , 0x1DC)
        SCHEMA_FIELD(float                           , m_flLerpTime                                    , 0x1E0)
    };

    class C_INIT_CreateFromParentParticles {
    public:
        SCHEMA_FIELD(float                           , m_flVelocityScale                               , 0x1E0)
        SCHEMA_FIELD(float                           , m_flIncrement                                   , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bRandomDistribution                           , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bSubFrame                                     , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bSetRopeSegmentID                             , 0x1F1)
    };

    class C_OP_SetControlPointFieldToScalarExpression {
    public:
        SCHEMA_FIELD(ScalarExpressionType_t          , m_nExpression                                   , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInput1                                      , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInput2                                      , 0x358)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x638)
        SCHEMA_FIELD(std::int32_t                    , m_nOutVectorField                               , 0x63C)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInterpolation                               , 0x640)
    };

    class C_OP_SetControlPointRotation {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecRotAxis                                    , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRotRate                                     , 0x898)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0xA08)
        SCHEMA_FIELD(std::int32_t                    , m_nLocalCP                                      , 0xA0C)
    };

    class C_OP_RemapDensityGradientToVectorAttribute {
    public:
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
    };

    class C_OP_QuantizeCPComponent {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInputValue                                  , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutput                                     , 0x350)
        SCHEMA_FIELD(std::int32_t                    , m_nOutVectorField                               , 0x354)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flQuantizeValue                               , 0x358)
    };

    class C_INIT_CreateWithinSphereTransform {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fRadiusMin                                    , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fRadiusMax                                    , 0x350)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecDistanceBias                               , 0x4C0)
        SCHEMA_FIELD(::Vector                        , m_vecDistanceBiasAbs                            , 0xB78)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0xB88)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMin                                     , 0xBF0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMax                                     , 0xD60)
        SCHEMA_FIELD(float                           , m_fSpeedRandExp                                 , 0xED0)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0xED4)
        SCHEMA_FIELD(CPerParticleVecInput            , m_LocalCoordinateSystemSpeedMin                 , 0xED8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_LocalCoordinateSystemSpeedMax                 , 0x1590)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1C48)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldVelocity                                , 0x1C4C)
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

    class C_INIT_SequenceLifeTime {
    public:
        SCHEMA_FIELD(float                           , m_flFramerate                                   , 0x1E0)
    };

    class C_OP_ContinuousEmitter {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flEmissionDuration                            , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flStartTime                                   , 0x350)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flEmitRate                                    , 0x4C0)
        SCHEMA_FIELD(float                           , m_flEmissionScale                               , 0x630)
        SCHEMA_FIELD(float                           , m_flScalePerParentParticle                      , 0x634)
        SCHEMA_FIELD(bool                            , m_bInitFromKilledParentParticles                , 0x638)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nEventType                                    , 0x63C)
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPoint                         , 0x640)
        SCHEMA_FIELD(::CUtlString                    , m_strSnapshotSubset                             , 0x648)
        SCHEMA_FIELD(std::int32_t                    , m_nLimitPerUpdate                               , 0x650)
        SCHEMA_FIELD(bool                            , m_bForceEmitOnFirstUpdate                       , 0x654)
        SCHEMA_FIELD(bool                            , m_bForceEmitOnLastUpdate                        , 0x655)
    };

    class C_OP_RenderTrails {
    public:
        SCHEMA_FIELD(bool                            , m_bEnableFadingAndClamping                      , 0x30E8)
        SCHEMA_FIELD(float                           , m_flStartFadeDot                                , 0x30EC)
        SCHEMA_FIELD(float                           , m_flEndFadeDot                                  , 0x30F0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nPrevPntSource                                , 0x30F4)
        SCHEMA_FIELD(float                           , m_flMaxLength                                   , 0x30F8)
        SCHEMA_FIELD(float                           , m_flMinLength                                   , 0x30FC)
        SCHEMA_FIELD(bool                            , m_bIgnoreDT                                     , 0x3100)
        SCHEMA_FIELD(float                           , m_flConstrainRadiusToLengthRatio                , 0x3104)
        SCHEMA_FIELD(float                           , m_flLengthScale                                 , 0x3108)
        SCHEMA_FIELD(float                           , m_flLengthFadeInTime                            , 0x310C)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadiusHeadTaper                             , 0x3110)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecHeadColorScale                             , 0x3280)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flHeadAlphaScale                              , 0x3938)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadiusTaper                                 , 0x3AA8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecTailColorScale                             , 0x3C18)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flTailAlphaScale                              , 0x42D0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nHorizCropField                               , 0x4440)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nVertCropField                                , 0x4444)
        SCHEMA_FIELD(float                           , m_flForwardShift                                , 0x4448)
        SCHEMA_FIELD(bool                            , m_bFlipUVBasedOnPitchYaw                        , 0x444C)
    };

    class C_OP_ParentVortices {
    public:
        SCHEMA_FIELD(float                           , m_flForceScale                                  , 0x1E8)
        SCHEMA_FIELD(::Vector                        , m_vecTwistAxis                                  , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bFlipBasedOnYaw                               , 0x1F8)
    };

    class CPulseCell_BaseLerp {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
    };

    class C_OP_ChooseRandomChildrenInGroup {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flNumberOfChildren                            , 0x1E8)
    };

    class C_OP_LockToPointList {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CUtlVector<PointDefinition_t>   , m_pointList                                     , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bPlaceAlongPath                               , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bClosedLoop                                   , 0x1F9)
        SCHEMA_FIELD(std::int32_t                    , m_nNumPointsAlongPath                           , 0x1FC)
    };

    class PulseSelectorOutflowList_t {
    public:
        SCHEMA_FIELD(CUtlVector<OutflowWithRequirements_t>, m_Outflows                                      , 0x0)
    };

    class C_INIT_SetVectorAttributeToVectorExpression {
    public:
        SCHEMA_FIELD(VectorExpressionType_t          , m_nExpression                                   , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput1                                       , 0x1E8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput2                                       , 0x8A0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLerp                                        , 0xF58)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x10C8)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x10CC)
        SCHEMA_FIELD(bool                            , m_bNormalizedOutput                             , 0x10D0)
    };

    class C_OP_RenderSound {
    public:
        SCHEMA_FIELD(float                           , m_flDurationScale                               , 0x228)
        SCHEMA_FIELD(float                           , m_flSndLvlScale                                 , 0x22C)
        SCHEMA_FIELD(float                           , m_flPitchScale                                  , 0x230)
        SCHEMA_FIELD(float                           , m_flVolumeScale                                 , 0x234)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nSndLvlField                                  , 0x238)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nDurationField                                , 0x23C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nPitchField                                   , 0x240)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nVolumeField                                  , 0x244)
        SCHEMA_FIELD(std::int32_t                    , m_nChannel                                      , 0x248)
        SCHEMA_FIELD(std::int32_t                    , m_nCPReference                                  , 0x24C)
        SCHEMA_FIELD(char                            , m_pszSoundName                                  , 0x250)
        SCHEMA_FIELD(bool                            , m_bSuppressStopSoundEvent                       , 0x350)
    };

    class CPulseCell_Outflow_CycleOrdered {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class C_OP_PercentageBetweenTransforms {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E0)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1E8)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformStart                                , 0x1F0)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformEnd                                  , 0x258)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x2C0)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x2C4)
        SCHEMA_FIELD(bool                            , m_bRadialCheck                                  , 0x2C5)
    };

    class CPulseCell_Outflow_CycleRandom {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class C_INIT_RemapParticleCountToNamedModelSequenceScalar {
    public:
    };

    class TextureControls_t {
    public:
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFinalTextureScaleU                          , 0x0)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFinalTextureScaleV                          , 0x170)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFinalTextureOffsetU                         , 0x2E0)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFinalTextureOffsetV                         , 0x450)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFinalTextureUVRotation                      , 0x5C0)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flZoomScale                                   , 0x730)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flDistortion                                  , 0x8A0)
        SCHEMA_FIELD(bool                            , m_bRandomizeOffsets                             , 0xA10)
        SCHEMA_FIELD(bool                            , m_bClampUVs                                     , 0xA11)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleBlend                             , 0xA14)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleScale                             , 0xA18)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleOffsetU                           , 0xA1C)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleOffsetV                           , 0xA20)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleRotation                          , 0xA24)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleZoom                              , 0xA28)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleDistortion                        , 0xA2C)
    };

    class C_OP_RemapDotProductToScalar {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInputCP1                                     , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nInputCP2                                     , 0x1DC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bUseParticleVelocity                          , 0x1F4)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x1FC)
        SCHEMA_FIELD(bool                            , m_bUseParticleNormal                            , 0x1FD)
    };

    class C_OP_IntraParticleForce {
    public:
        SCHEMA_FIELD(float                           , m_flAttractionMinDistance                       , 0x1E8)
        SCHEMA_FIELD(float                           , m_flAttractionMaxDistance                       , 0x1EC)
        SCHEMA_FIELD(float                           , m_flAttractionMaxStrength                       , 0x1F0)
        SCHEMA_FIELD(float                           , m_flRepulsionMinDistance                        , 0x1F4)
        SCHEMA_FIELD(float                           , m_flRepulsionMaxDistance                        , 0x1F8)
        SCHEMA_FIELD(float                           , m_flRepulsionMaxStrength                        , 0x1FC)
        SCHEMA_FIELD(bool                            , m_bUseAABB                                      , 0x200)
    };

    class CPulseCell_WaitForCursorsWithTag {
    public:
        SCHEMA_FIELD(bool                            , m_bTagSelfWhenComplete                          , 0x98)
        SCHEMA_FIELD(PulseCursorCancelPriority_t     , m_nDesiredKillPriority                          , 0x9C)
    };

    class CGeneralRandomRotation {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_flDegrees                                     , 0x1E4)
        SCHEMA_FIELD(float                           , m_flDegreesMin                                  , 0x1E8)
        SCHEMA_FIELD(float                           , m_flDegreesMax                                  , 0x1EC)
        SCHEMA_FIELD(float                           , m_flRotationRandExponent                        , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bRandomlyFlipDirection                        , 0x1F4)
    };

    class C_INIT_CreateWithinBox {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecMin                                        , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecMax                                        , 0x898)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0xF50)
        SCHEMA_FIELD(bool                            , m_bLocalSpace                                   , 0xF54)
        SCHEMA_FIELD(CRandomNumberGeneratorParameters, m_randomnessParameters                          , 0xF58)
        SCHEMA_FIELD(bool                            , m_bUseNewCode                                   , 0xF60)
    };

    class C_OP_EndCapTimedFreeze {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flFreezeTime                                  , 0x1D8)
    };

    class C_OP_RenderSprites {
    public:
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_nSequenceOverride                             , 0x2DF0)
        SCHEMA_FIELD(bool                            , m_bSequenceNumbersAreRawSequenceIndices         , 0x2F60)
        SCHEMA_FIELD(ParticleOrientationChoiceList_t , m_nOrientationType                              , 0x2F64)
        SCHEMA_FIELD(std::int32_t                    , m_nOrientationControlPoint                      , 0x2F68)
        SCHEMA_FIELD(bool                            , m_bUseYawWithNormalAligned                      , 0x2F6C)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flMinSize                                     , 0x2F70)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flMaxSize                                     , 0x30E0)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flAlphaAdjustWithSizeAdjust                   , 0x3250)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flStartFadeSize                               , 0x33C0)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flEndFadeSize                                 , 0x3530)
        SCHEMA_FIELD(float                           , m_flStartFadeDot                                , 0x36A0)
        SCHEMA_FIELD(float                           , m_flEndFadeDot                                  , 0x36A4)
        SCHEMA_FIELD(bool                            , m_bDistanceAlpha                                , 0x36A8)
        SCHEMA_FIELD(bool                            , m_bSoftEdges                                    , 0x36A9)
        SCHEMA_FIELD(float                           , m_flEdgeSoftnessStart                           , 0x36AC)
        SCHEMA_FIELD(float                           , m_flEdgeSoftnessEnd                             , 0x36B0)
        SCHEMA_FIELD(bool                            , m_bOutline                                      , 0x36B4)
        SCHEMA_FIELD(::Color                         , m_OutlineColor                                  , 0x36B5)
        SCHEMA_FIELD(std::int32_t                    , m_nOutlineAlpha                                 , 0x36BC)
        SCHEMA_FIELD(float                           , m_flOutlineStart0                               , 0x36C0)
        SCHEMA_FIELD(float                           , m_flOutlineStart1                               , 0x36C4)
        SCHEMA_FIELD(float                           , m_flOutlineEnd0                                 , 0x36C8)
        SCHEMA_FIELD(float                           , m_flOutlineEnd1                                 , 0x36CC)
        SCHEMA_FIELD(ParticleLightingQuality_t       , m_nLightingMode                                 , 0x36D0)
        SCHEMA_FIELD(CParticleCollectionRendererVecInput, m_vecLightingOverride                           , 0x36D8)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flLightingTessellation                        , 0x3D90)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flLightingDirectionality                      , 0x3F00)
        SCHEMA_FIELD(bool                            , m_bParticleShadows                              , 0x4070)
        SCHEMA_FIELD(float                           , m_flShadowDensity                               , 0x4074)
        SCHEMA_FIELD(CReplicationParameters          , m_replicationParameters                         , 0x4078)
    };

    class C_OP_SetFromCPSnapshot {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(::CUtlString                    , m_strSnapshotSubset                             , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttributeToRead                              , 0x1E8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttributeToWrite                             , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nLocalSpaceCP                                 , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bRandom                                       , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bReverse                                      , 0x1F5)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0x1F8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nSnapShotStartPoint                           , 0x200)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nSnapShotIncrement                            , 0x370)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x4E0)
        SCHEMA_FIELD(bool                            , m_bSubSample                                    , 0x650)
        SCHEMA_FIELD(bool                            , m_bPrev                                         , 0x651)
    };

    class C_OP_QuantizeFloat {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputValue                                    , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x348)
    };

    class SignatureOutflow_Resume {
    public:
    };

    class C_INIT_CreateParticleImpulse {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputRadius                                   , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputMagnitude                                , 0x350)
        SCHEMA_FIELD(ParticleFalloffFunction_t       , m_nFalloffFunction                              , 0x4C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputFalloffExp                               , 0x4C8)
        SCHEMA_FIELD(ParticleImpulseType_t           , m_nImpulseType                                  , 0x638)
    };

    class C_OP_InheritFromParentParticles {
    public:
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nIncrement                                    , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bRandomDistribution                           , 0x1E4)
    };

    class C_INIT_RandomRotationSpeed {
    public:
    };

    class C_INIT_RemapInitialTransformDirectionToRotation {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x248)
        SCHEMA_FIELD(float                           , m_flOffsetRot                                   , 0x24C)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent                                    , 0x250)
    };

    class C_OP_SetFloatCollection {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_InputValue                                    , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x348)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x34C)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_Lerp                                          , 0x350)
    };

    class C_OP_SpinYaw {
    public:
    };

    class C_OP_RemapScalarOnceTimed {
    public:
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1DC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F0)
        SCHEMA_FIELD(float                           , m_flRemapTime                                   , 0x1F4)
    };

    class C_OP_RemapExternalWindToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutput                                     , 0x1E4)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecScale                                      , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bSetMagnitude                                 , 0x8A0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutVectorField                               , 0x8A4)
    };

    class CPulseCell_Base {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nEditorNodeID                                 , 0x8)
    };

    class C_OP_RenderLights {
    public:
        SCHEMA_FIELD(float                           , m_flAnimationRate                               , 0x230)
        SCHEMA_FIELD(AnimationType_t                 , m_nAnimationType                                , 0x234)
        SCHEMA_FIELD(bool                            , m_bAnimateInFPS                                 , 0x238)
        SCHEMA_FIELD(float                           , m_flMinSize                                     , 0x23C)
        SCHEMA_FIELD(float                           , m_flMaxSize                                     , 0x240)
        SCHEMA_FIELD(float                           , m_flStartFadeSize                               , 0x244)
        SCHEMA_FIELD(float                           , m_flEndFadeSize                                 , 0x248)
    };

    class C_OP_InterpolateRadius {
    public:
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x1D8)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x1DC)
        SCHEMA_FIELD(float                           , m_flStartScale                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_flEndScale                                    , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bEaseInAndOut                                 , 0x1E8)
        SCHEMA_FIELD(float                           , m_flBias                                        , 0x1EC)
    };

    class C_INIT_PositionPlaceOnGround {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOffset                                      , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMaxTraceLength                              , 0x350)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecTraceDir                                   , 0x4C0)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0xB78)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0xBF8)
        SCHEMA_FIELD(ParticleTraceMissBehavior_t     , m_nTraceMissBehavior                            , 0xC08)
        SCHEMA_FIELD(bool                            , m_bIncludeWater                                 , 0xC0C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttribute                                    , 0xC10)
        SCHEMA_FIELD(bool                            , m_bSetPXYZOnly                                  , 0xC14)
        SCHEMA_FIELD(bool                            , m_bSetNormal                                    , 0xC15)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nGroundNormalAttribute                        , 0xC18)
        SCHEMA_FIELD(bool                            , m_bOffsetonColOnly                              , 0xC1C)
        SCHEMA_FIELD(float                           , m_flOffsetByRadiusFactor                        , 0xC20)
        SCHEMA_FIELD(std::int32_t                    , m_nPreserveOffsetCP                             , 0xC24)
        SCHEMA_FIELD(std::int32_t                    , m_nIgnoreCP                                     , 0xC28)
    };

    class C_OP_RenderScreenShake {
    public:
        SCHEMA_FIELD(float                           , m_flDurationScale                               , 0x228)
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x22C)
        SCHEMA_FIELD(float                           , m_flFrequencyScale                              , 0x230)
        SCHEMA_FIELD(float                           , m_flAmplitudeScale                              , 0x234)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nRadiusField                                  , 0x238)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nDurationField                                , 0x23C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFrequencyField                               , 0x240)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAmplitudeField                               , 0x244)
        SCHEMA_FIELD(std::int32_t                    , m_nFilterCP                                     , 0x248)
    };

    class C_OP_ExternalGameImpulseForce {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flForceScale                                  , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bRopes                                        , 0x358)
        SCHEMA_FIELD(bool                            , m_bRopesZOnly                                   , 0x359)
        SCHEMA_FIELD(bool                            , m_bExplosions                                   , 0x35A)
        SCHEMA_FIELD(bool                            , m_bParticles                                    , 0x35B)
    };

    class CPulseCell_LimitCount {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nLimitCount                                   , 0x48)
    };

    class CPulseCell_Inflow_EventHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_EventName                                     , 0x80)
    };

    class C_OP_RepeatedTriggerChildGroup {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flClusterRefireTime                           , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flClusterSize                                 , 0x358)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flClusterCooldown                             , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bLimitChildCount                              , 0x638)
    };

    class C_OP_RemapVelocityToVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0x1E0)
    };

    class CSpinUpdateBase {
    public:
    };

    class C_OP_ChladniWave {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMin                                    , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMax                                    , 0x350)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMin                                   , 0x4C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMax                                   , 0x630)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecWaveLength                                 , 0x7A0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecHarmonics                                  , 0xE58)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1510)
        SCHEMA_FIELD(std::int32_t                    , m_nLocalSpaceControlPoint                       , 0x1514)
        SCHEMA_FIELD(bool                            , m_b3D                                           , 0x1518)
    };

    class C_OP_SetGravityToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPInput                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutput                                     , 0x1E4)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flScale                                       , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bSetPosition                                  , 0x358)
        SCHEMA_FIELD(bool                            , m_bSetOrientation                               , 0x359)
        SCHEMA_FIELD(bool                            , m_bSetZDown                                     , 0x35A)
    };

    class C_OP_SetControlPointOrientation {
    public:
        SCHEMA_FIELD(bool                            , m_bUseWorldLocation                             , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bRandomize                                    , 0x1E2)
        SCHEMA_FIELD(bool                            , m_bSetOnce                                      , 0x1E3)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nHeadLocation                                 , 0x1E8)
        SCHEMA_FIELD(::QAngle                        , m_vecRotation                                   , 0x1EC)
        SCHEMA_FIELD(::QAngle                        , m_vecRotationB                                  , 0x1F8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInterpolation                               , 0x208)
    };

    class C_INIT_InitialVelocityNoise {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecAbsVal                                     , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecAbsValInv                                  , 0x1EC)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecOffsetLoc                                  , 0x1F8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOffset                                      , 0x8B0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecOutputMin                                  , 0xA20)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecOutputMax                                  , 0x10D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flNoiseScale                                  , 0x1790)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flNoiseScaleLoc                               , 0x1900)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1A70)
        SCHEMA_FIELD(bool                            , m_bIgnoreDt                                     , 0x1AD8)
    };

    class C_OP_FadeInSimple {
    public:
        SCHEMA_FIELD(float                           , m_flFadeInTime                                  , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
    };

    class C_OP_ModelSurfaceSnapshotGenerator {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPSnapshot                                   , 0x1E0)
        SCHEMA_FIELD(CParticleModelInput             , m_modelInput                                    , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRecalcRate                                  , 0x248)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flUSpacing                                    , 0x3B8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flVSpacing                                    , 0x528)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flSurfaceOffset                               , 0x698)
        SCHEMA_FIELD(bool                            , m_bSetNormal                                    , 0x808)
        SCHEMA_FIELD(bool                            , m_bSetUp                                        , 0x809)
        SCHEMA_FIELD(bool                            , m_bSetGravity                                   , 0x80A)
        SCHEMA_FIELD(bool                            , m_bSetUV                                        , 0x80B)
    };

    class C_INIT_ScaleVelocity {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecScale                                      , 0x1E0)
    };

    class C_INIT_CreateSequentialPath {
    public:
        SCHEMA_FIELD(float                           , m_fMaxDistance                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_flNumToAssign                                 , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bLoop                                         , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bCPPairs                                      , 0x1E9)
        SCHEMA_FIELD(bool                            , m_bSaveOffset                                   , 0x1EA)
        SCHEMA_FIELD(CPathParameters                 , m_PathParams                                    , 0x1F0)
    };

    class SignatureOutflow_Continue {
    public:
    };

    class C_OP_BasicMovement {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_Gravity                                       , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_fDrag                                         , 0x890)
        SCHEMA_FIELD(CParticleMassCalculationParameters, m_massControls                                  , 0xA00)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxConstraintPasses                          , 0xE58)
        SCHEMA_FIELD(bool                            , m_bUseNewCode                                   , 0xE5C)
    };

    class CParticleFunctionInitializer {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nAssociatedEmitterIndex                       , 0x1D8)
    };

    class CParticleCollectionBindingInstance {
    public:
    };

    class C_OP_SetControlPointToPlayer {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecCP1Pos                                     , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bOrientToEyes                                 , 0x1F0)
        SCHEMA_FIELD(ParticleEntityPos_t             , m_nPosition                                     , 0x1F4)
    };

    class C_OP_RemapParticleCountToScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nInputMin                                     , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nInputMax                                     , 0x350)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOutputMin                                   , 0x4C0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOutputMax                                   , 0x630)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x7A0)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x7A4)
    };

    class C_OP_SetControlPointToCPVelocity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPInput                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutputVel                                  , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutputMag                                  , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nCPField                                      , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecComparisonVelocity                         , 0x1F8)
    };

    class C_OP_RemapControlPointDirectionToVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
    };

    class C_OP_OrientTo2dDirection {
    public:
        SCHEMA_FIELD(float                           , m_flRotOffset                                   , 0x1D8)
        SCHEMA_FIELD(float                           , m_flSpinStrength                                , 0x1DC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
    };

    class C_OP_Noise {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1DC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1E0)
        SCHEMA_FIELD(float                           , m_fl4NoiseScale                                 , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bAdditive                                     , 0x1E8)
        SCHEMA_FIELD(float                           , m_flNoiseAnimationTimeScale                     , 0x1EC)
    };

    class C_OP_ClientPhysics {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strPhysicsType                                , 0x228)
        SCHEMA_FIELD(bool                            , m_bStartAsleep                                  , 0x230)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flPlayerWakeRadius                            , 0x238)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flVehicleWakeRadius                           , 0x3A8)
        SCHEMA_FIELD(bool                            , m_bUseHighQualitySimulation                     , 0x518)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxParticleCount                             , 0x51C)
        SCHEMA_FIELD(bool                            , m_bRespectExclusionVolumes                      , 0x520)
        SCHEMA_FIELD(bool                            , m_bKillParticles                                , 0x521)
        SCHEMA_FIELD(bool                            , m_bDeleteSim                                    , 0x522)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x524)
        SCHEMA_FIELD(std::int32_t                    , m_nForcedSimId                                  , 0x528)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0x52C)
        SCHEMA_FIELD(ParticleAttrBoxFlags_t          , m_nForcedStatusEffects                          , 0x530)
    };

    class CPulseCell_BaseFlow {
    public:
    };

    class C_OP_RemapNamedModelElementEndCap {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x1D8)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_inNames                                       , 0x1E0)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_outNames                                      , 0x1F8)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_fallbackNames                                 , 0x210)
        SCHEMA_FIELD(bool                            , m_bModelFromRenderer                            , 0x228)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x22C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x230)
    };

    class VecInputMaterialVariable_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strVariable                                   , 0x0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecInput                                      , 0x8)
    };

    class C_OP_PlaneCull {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nPlaneControlPoint                            , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecPlaneDirection                             , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bLocalSpace                                   , 0x898)
        SCHEMA_FIELD(float                           , m_flPlaneOffset                                 , 0x89C)
    };

    class C_OP_SetFloatAttributeToVectorExpression {
    public:
        SCHEMA_FIELD(VectorFloatExpressionType_t     , m_nExpression                                   , 0x1D8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput1                                       , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput2                                       , 0x898)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0xF50)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x10C0)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x10C4)
    };

    class C_INIT_RtEnvCull {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecTestDir                                    , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecTestNormal                                 , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bUseVelocity                                  , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bCullOnMiss                                   , 0x1F9)
        SCHEMA_FIELD(bool                            , m_bLifeAdjust                                   , 0x1FA)
        SCHEMA_FIELD(char                            , m_RtEnvName                                     , 0x1FB)
        SCHEMA_FIELD(std::int32_t                    , m_nRTEnvCP                                      , 0x27C)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent                                    , 0x280)
    };

    class CReplicationParameters {
    public:
        SCHEMA_FIELD(ParticleReplicationMode_t       , m_nReplicationMode                              , 0x0)
        SCHEMA_FIELD(bool                            , m_bScaleChildParticleRadii                      , 0x4)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMinRandomRadiusScale                        , 0x8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMaxRandomRadiusScale                        , 0x178)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vMinRandomDisplacement                        , 0x2E8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vMaxRandomDisplacement                        , 0x9A0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flModellingScale                              , 0x1058)
    };

    class C_INIT_DistanceCull {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDistance                                    , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bCullInside                                   , 0x358)
    };

    class CPulseCell_BaseState {
    public:
    };

    class C_OP_MovementRotateParticleAroundAxis {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecRotAxis                                    , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRotRate                                     , 0x890)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0xA00)
        SCHEMA_FIELD(bool                            , m_bLocalSpace                                   , 0xA68)
    };

    class C_OP_RenderDeferredLight {
    public:
        SCHEMA_FIELD(bool                            , m_bUseAlphaTestWindow                           , 0x228)
        SCHEMA_FIELD(bool                            , m_bUseTexture                                   , 0x229)
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x22C)
        SCHEMA_FIELD(float                           , m_flAlphaScale                                  , 0x230)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAlpha2Field                                  , 0x234)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorScale                                 , 0x238)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0x8F0)
        SCHEMA_FIELD(float                           , m_flLightDistance                               , 0x8F4)
        SCHEMA_FIELD(float                           , m_flStartFalloff                                , 0x8F8)
        SCHEMA_FIELD(float                           , m_flDistanceFalloff                             , 0x8FC)
        SCHEMA_FIELD(float                           , m_flSpotFoV                                     , 0x900)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAlphaTestPointField                          , 0x904)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAlphaTestRangeField                          , 0x908)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAlphaTestSharpnessField                      , 0x90C)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hTexture                                      , 0x910)
        SCHEMA_FIELD(std::int32_t                    , m_nHSVShiftControlPoint                         , 0x918)
    };

    class CPulseCell_Outflow_CycleShuffled {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class C_OP_SetParentControlPointsToChildCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nChildControlPoint                            , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nNumControlPoints                             , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstSourcePoint                             , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bSetOrientation                               , 0x1F0)
    };

    class C_OP_RemapControlPointOrientationToRotation {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flOffsetRot                                   , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent                                    , 0x1E4)
    };

    class CParticleFunctionForce {
    public:
    };

    class CPulseCell_CursorQueue {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToRunParallel                  , 0x98)
    };

    class ParticlePreviewBodyGroup_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_bodyGroupName                                 , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nValue                                        , 0x8)
    };

    class C_INIT_CreateFromPlaneCache {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecOffsetMin                                  , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecOffsetMax                                  , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bUseNormal                                    , 0x1F9)
    };

    class CPulseCell_Value_RandomInt {
    public:
    };

    class C_INIT_VelocityRandom {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMin                                     , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMax                                     , 0x358)
        SCHEMA_FIELD(CPerParticleVecInput            , m_LocalCoordinateSystemSpeedMin                 , 0x4C8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_LocalCoordinateSystemSpeedMax                 , 0xB80)
        SCHEMA_FIELD(bool                            , m_bIgnoreDT                                     , 0x1238)
        SCHEMA_FIELD(CRandomNumberGeneratorParameters, m_randomnessParameters                          , 0x123C)
    };

    class CPulseTestScriptLib {
    public:
    };

    class C_OP_SnapshotSkinToBones {
    public:
        SCHEMA_FIELD(bool                            , m_bTransformNormals                             , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bTransformRadii                               , 0x1D9)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1DC)
        SCHEMA_FIELD(float                           , m_flLifeTimeFadeStart                           , 0x1E0)
        SCHEMA_FIELD(float                           , m_flLifeTimeFadeEnd                             , 0x1E4)
        SCHEMA_FIELD(float                           , m_flJumpThreshold                               , 0x1E8)
        SCHEMA_FIELD(float                           , m_flPrevPosScale                                , 0x1EC)
    };

    class C_OP_RenderLightBeam {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nMaxAllowed                                   , 0x228)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vColorBlend                                   , 0x230)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0x8E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBrightnessLumensPerMeter                    , 0x8F0)
        SCHEMA_FIELD(bool                            , m_bCastShadows                                  , 0xA60)
        SCHEMA_FIELD(bool                            , m_bDynamicBounce                                , 0xA61)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBounceScale                                 , 0xA68)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flSkirt                                       , 0xBD8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRange                                       , 0xD48)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flThickness                                   , 0xEB8)
    };

    class C_OP_RemapNamedModelElementOnceTimed {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x1D8)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_inNames                                       , 0x1E0)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_outNames                                      , 0x1F8)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_fallbackNames                                 , 0x210)
        SCHEMA_FIELD(bool                            , m_bModelFromRenderer                            , 0x228)
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0x229)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x22C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x230)
        SCHEMA_FIELD(float                           , m_flRemapTime                                   , 0x234)
    };

    class C_OP_RotateVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecRotAxisMin                                 , 0x1DC)
        SCHEMA_FIELD(::Vector                        , m_vecRotAxisMax                                 , 0x1E8)
        SCHEMA_FIELD(float                           , m_flRotRateMin                                  , 0x1F4)
        SCHEMA_FIELD(float                           , m_flRotRateMax                                  , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0x1FC)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flScale                                       , 0x200)
    };

    class C_INIT_InitFromVectorFieldSnapshot {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nLocalSpaceCP                                 , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nWeightUpdateCP                               , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bUseVerticalVelocity                          , 0x1EC)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecScale                                      , 0x1F0)
    };

    class C_OP_RenderModels {
    public:
        SCHEMA_FIELD(bool                            , m_bOnlyRenderInEffectsBloomPass                 , 0x228)
        SCHEMA_FIELD(bool                            , m_bOnlyRenderInEffectsWaterPass                 , 0x229)
        SCHEMA_FIELD(bool                            , m_bUseMixedResolutionRendering                  , 0x22A)
        SCHEMA_FIELD(bool                            , m_bOnlyRenderInEffecsGameOverlay                , 0x22B)
        SCHEMA_FIELD(CUtlVector<ModelReference_t>    , m_ModelList                                     , 0x230)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nBodyGroupField                               , 0x248)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nSubModelField                                , 0x24C)
        SCHEMA_FIELD(bool                            , m_bIgnoreNormal                                 , 0x250)
        SCHEMA_FIELD(bool                            , m_bOrientZ                                      , 0x251)
        SCHEMA_FIELD(bool                            , m_bCenterOffset                                 , 0x252)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecLocalOffset                                , 0x258)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecLocalRotation                              , 0x910)
        SCHEMA_FIELD(bool                            , m_bIgnoreRadius                                 , 0xFC8)
        SCHEMA_FIELD(std::int32_t                    , m_nModelScaleCP                                 , 0xFCC)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecComponentScale                             , 0xFD0)
        SCHEMA_FIELD(bool                            , m_bLocalScale                                   , 0x1688)
        SCHEMA_FIELD(std::int32_t                    , m_nSizeCullBloat                                , 0x168C)
        SCHEMA_FIELD(bool                            , m_bAnimated                                     , 0x1690)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flAnimationRate                               , 0x1698)
        SCHEMA_FIELD(bool                            , m_bScaleAnimationRate                           , 0x1808)
        SCHEMA_FIELD(bool                            , m_bForceLoopingAnimation                        , 0x1809)
        SCHEMA_FIELD(bool                            , m_bResetAnimOnStop                              , 0x180A)
        SCHEMA_FIELD(bool                            , m_bManualAnimFrame                              , 0x180B)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAnimationScaleField                          , 0x180C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAnimationField                               , 0x1810)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nManualFrameField                             , 0x1814)
        SCHEMA_FIELD(char                            , m_ActivityName                                  , 0x1818)
        SCHEMA_FIELD(char                            , m_SequenceName                                  , 0x1918)
        SCHEMA_FIELD(bool                            , m_bEnableClothSimulation                        , 0x1A18)
        SCHEMA_FIELD(bool                            , m_bDisableClothGroundCollision                  , 0x1A19)
        SCHEMA_FIELD(char                            , m_ClothEffectName                               , 0x1A1A)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hOverrideMaterial                             , 0x1A60)
        SCHEMA_FIELD(bool                            , m_bOverrideTranslucentMaterials                 , 0x1A68)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_nSkin                                         , 0x1A70)
        SCHEMA_FIELD(CUtlVector<MaterialVariable_t>  , m_MaterialVars                                  , 0x1BE0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRenderFilter                                , 0x1BF8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flManualModelSelection                        , 0x1D68)
        SCHEMA_FIELD(CParticleModelInput             , m_modelInput                                    , 0x1ED8)
        SCHEMA_FIELD(std::int32_t                    , m_nLOD                                          , 0x1F38)
        SCHEMA_FIELD(char                            , m_EconSlotName                                  , 0x1F3C)
        SCHEMA_FIELD(bool                            , m_bOriginalModel                                , 0x203C)
        SCHEMA_FIELD(bool                            , m_bSuppressTint                                 , 0x203D)
        SCHEMA_FIELD(RenderModelSubModelFieldType_t  , m_nSubModelFieldType                            , 0x2040)
        SCHEMA_FIELD(bool                            , m_bDisableShadows                               , 0x2044)
        SCHEMA_FIELD(bool                            , m_bDisableDepthPrepass                          , 0x2045)
        SCHEMA_FIELD(bool                            , m_bAcceptsDecals                                , 0x2046)
        SCHEMA_FIELD(bool                            , m_bForceDrawInterlevedWithSiblings              , 0x2047)
        SCHEMA_FIELD(bool                            , m_bDoNotDrawInParticlePass                      , 0x2048)
        SCHEMA_FIELD(bool                            , m_bAllowApproximateTransforms                   , 0x2049)
        SCHEMA_FIELD(char                            , m_szRenderAttribute                             , 0x204A)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadiusScale                                 , 0x2150)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flAlphaScale                                  , 0x22C0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRollScale                                   , 0x2430)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAlpha2Field                                  , 0x25A0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorScale                                 , 0x25A8)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0x2C60)
    };

    class C_OP_DifferencePreviousParticle {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1EC)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bSetPreviousParticle                          , 0x1F5)
    };

    class C_INIT_RemapParticleCountToScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nInputMin                                     , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nInputMax                                     , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPoint                            , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPointField                       , 0x1F0)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1F4)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F8)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1FC)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x200)
        SCHEMA_FIELD(bool                            , m_bInvert                                       , 0x201)
        SCHEMA_FIELD(bool                            , m_bWrap                                         , 0x202)
        SCHEMA_FIELD(float                           , m_flRemapBias                                   , 0x204)
    };

    class C_OP_RemapVectorToRotations {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecInput                                      , 0x1D8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecRotation                                   , 0x890)
    };

    class CPulseCell_Value_Gradient {
    public:
        SCHEMA_FIELD(CColorGradient                  , m_Gradient                                      , 0x48)
    };

    class C_OP_ConstrainLineLength {
    public:
        SCHEMA_FIELD(float                           , m_flMinDistance                                 , 0x1D8)
        SCHEMA_FIELD(float                           , m_flMaxDistance                                 , 0x1DC)
    };

    class C_OP_OscillateVector {
    public:
        SCHEMA_FIELD(::Vector                        , m_RateMin                                       , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_RateMax                                       , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_FrequencyMin                                  , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_FrequencyMax                                  , 0x1FC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x208)
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0x20C)
        SCHEMA_FIELD(bool                            , m_bProportionalOp                               , 0x20D)
        SCHEMA_FIELD(bool                            , m_bOffset                                       , 0x20E)
        SCHEMA_FIELD(float                           , m_flStartTime_min                               , 0x210)
        SCHEMA_FIELD(float                           , m_flStartTime_max                               , 0x214)
        SCHEMA_FIELD(float                           , m_flEndTime_min                                 , 0x218)
        SCHEMA_FIELD(float                           , m_flEndTime_max                                 , 0x21C)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOscMult                                     , 0x220)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOscAdd                                      , 0x390)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRateScale                                   , 0x500)
    };

    class C_INIT_GlobalScale {
    public:
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPointNumber                      , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bScaleRadius                                  , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bScalePosition                                , 0x1ED)
        SCHEMA_FIELD(bool                            , m_bScaleVelocity                                , 0x1EE)
    };

    class C_INIT_SetHitboxToModel {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nForceInModel                                 , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bEvenDistribution                             , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nDesiredHitbox                                , 0x1EC)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecHitBoxScale                                , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vecDirectionBias                              , 0x8A8)
        SCHEMA_FIELD(bool                            , m_bMaintainHitbox                               , 0x8B4)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x8B5)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x8B6)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flShellSize                                   , 0x938)
    };

    class C_OP_LerpToInitialPosition {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nCacheField                                   , 0x350)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flScale                                       , 0x358)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecScale                                      , 0x4C8)
    };

    class C_OP_MovementSkinnedPositionFromCPSnapshot {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPointNumber                   , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bRandom                                       , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bSetNormal                                    , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bSetRadius                                    , 0x1E9)
        SCHEMA_FIELD(SnapshotIndexType_t             , m_nIndexType                                    , 0x1EC)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flReadIndex                                   , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flIncrement                                   , 0x360)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nFullLoopIncrement                            , 0x4D0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nSnapShotStartPoint                           , 0x640)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x7B0)
    };

    class C_OP_StopAfterCPDuration {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDuration                                    , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bDestroyImmediately                           , 0x350)
        SCHEMA_FIELD(bool                            , m_bPlayEndCap                                   , 0x351)
    };

    class C_INIT_InitFloat {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputValue                                    , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x350)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x354)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputStrength                                 , 0x358)
    };

    class C_OP_RopeSpringConstraint {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRestLength                                  , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMinDistance                                 , 0x348)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMaxDistance                                 , 0x4B8)
        SCHEMA_FIELD(float                           , m_flAdjustmentScale                             , 0x628)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInitialRestingLength                        , 0x630)
    };

    class C_OP_ReinitializeScalarEndCap {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1DC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1E0)
    };

    class C_OP_SetRandomControlPointPosition {
    public:
        SCHEMA_FIELD(bool                            , m_bUseWorldLocation                             , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bOrient                                       , 0x1E1)
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nHeadLocation                                 , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flReRandomRate                                , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vecCPMinPos                                   , 0x360)
        SCHEMA_FIELD(::Vector                        , m_vecCPMaxPos                                   , 0x36C)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInterpolation                               , 0x378)
    };

    class C_INIT_Orient2DRelToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E4)
        SCHEMA_FIELD(float                           , m_flRotOffset                                   , 0x1E8)
    };

    class C_INIT_RandomRadius {
    public:
        SCHEMA_FIELD(float                           , m_flRadiusMin                                   , 0x1E0)
        SCHEMA_FIELD(float                           , m_flRadiusMax                                   , 0x1E4)
        SCHEMA_FIELD(float                           , m_flRadiusRandExponent                          , 0x1E8)
    };

    class C_OP_InstantaneousEmitter {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nParticlesToEmit                              , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flStartTime                                   , 0x350)
        SCHEMA_FIELD(float                           , m_flInitFromKilledParentParticles               , 0x4C0)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nEventType                                    , 0x4C4)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flParentParticleScale                         , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxEmittedPerFrame                           , 0x638)
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPoint                         , 0x63C)
        SCHEMA_FIELD(::CUtlString                    , m_strSnapshotSubset                             , 0x640)
    };

    class CParticleFunctionOperator {
    public:
    };

    class C_OP_SetAttributeToScalarExpression {
    public:
        SCHEMA_FIELD(ScalarExpressionType_t          , m_nExpression                                   , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInput1                                      , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInput2                                      , 0x350)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x4C0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x630)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x634)
    };

    class C_OP_RemapCPVelocityToVector {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0x1E4)
    };

    class C_OP_AlphaDecay {
    public:
        SCHEMA_FIELD(float                           , m_flMinAlpha                                    , 0x1D8)
    };

    class C_INIT_ModelCull {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bBoundBox                                     , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bCullOutside                                  , 0x1E5)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x1E6)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x1E7)
    };

    class C_OP_RenderOmni2Light {
    public:
        SCHEMA_FIELD(ParticleOmni2LightTypeChoiceList_t, m_nLightType                                    , 0x228)
        SCHEMA_FIELD(std::uint16_t                   , m_nMaxAllowed                                   , 0x22C)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vColorBlend                                   , 0x230)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0x8E8)
        SCHEMA_FIELD(ParticleLightUnitChoiceList_t   , m_nBrightnessUnit                               , 0x8EC)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flBrightnessLumens                            , 0x8F0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flBrightnessCandelas                          , 0xA60)
        SCHEMA_FIELD(bool                            , m_bCastShadows                                  , 0xBD0)
        SCHEMA_FIELD(bool                            , m_bDynamicBounce                                , 0xBD1)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBounceScale                                 , 0xBD8)
        SCHEMA_FIELD(bool                            , m_bFog                                          , 0xD48)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flFogScale                                    , 0xD50)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLuminaireRadius                             , 0xEC0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flSkirt                                       , 0x1030)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRange                                       , 0x11A0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInnerConeAngle                              , 0x1310)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOuterConeAngle                              , 0x1480)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hLightCookie                                  , 0x15F0)
        SCHEMA_FIELD(bool                            , m_bSphericalCookie                              , 0x15F8)
    };

    class C_OP_RemapCPtoVector {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPInput                                      , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nLocalSpaceCP                                 , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vInputMin                                     , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vInputMax                                     , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vOutputMin                                    , 0x1FC)
        SCHEMA_FIELD(::Vector                        , m_vOutputMax                                    , 0x208)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x214)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x218)
        SCHEMA_FIELD(float                           , m_flInterpRate                                  , 0x21C)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x220)
        SCHEMA_FIELD(bool                            , m_bOffset                                       , 0x224)
        SCHEMA_FIELD(bool                            , m_bAccelerate                                   , 0x225)
    };

    class C_OP_HSVShiftToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nColorCP                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nColorGemEnableCP                             , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x1E8)
        SCHEMA_FIELD(::Color                         , m_DefaultHSVColor                               , 0x1EC)
    };

    class CPulseCell_Value_Curve {
    public:
        SCHEMA_FIELD(CPiecewiseCurve                 , m_Curve                                         , 0x48)
    };

    class C_INIT_DistanceToCPInit {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMin                                    , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMax                                    , 0x358)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMin                                   , 0x4C8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMax                                   , 0x638)
        SCHEMA_FIELD(std::int32_t                    , m_nStartCP                                      , 0x7A8)
        SCHEMA_FIELD(bool                            , m_bLOS                                          , 0x7AC)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x7AD)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x830)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMaxTraceLength                              , 0x838)
        SCHEMA_FIELD(float                           , m_flLOSScale                                    , 0x9A8)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x9AC)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x9B0)
        SCHEMA_FIELD(::Vector                        , m_vecDistanceScale                              , 0x9B4)
        SCHEMA_FIELD(float                           , m_flRemapBias                                   , 0x9C0)
    };

    class C_OP_ClampScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMin                                   , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMax                                   , 0x350)
    };

    class C_INIT_StatusEffectCitadel {
    public:
        SCHEMA_FIELD(float                           , m_flSFXColorWarpAmount                          , 0x1E0)
        SCHEMA_FIELD(float                           , m_flSFXNormalAmount                             , 0x1E4)
        SCHEMA_FIELD(float                           , m_flSFXMetalnessAmount                          , 0x1E8)
        SCHEMA_FIELD(float                           , m_flSFXRoughnessAmount                          , 0x1EC)
        SCHEMA_FIELD(float                           , m_flSFXSelfIllumAmount                          , 0x1F0)
        SCHEMA_FIELD(float                           , m_flSFXSScale                                   , 0x1F4)
        SCHEMA_FIELD(float                           , m_flSFXSScrollX                                 , 0x1F8)
        SCHEMA_FIELD(float                           , m_flSFXSScrollY                                 , 0x1FC)
        SCHEMA_FIELD(float                           , m_flSFXSScrollZ                                 , 0x200)
        SCHEMA_FIELD(float                           , m_flSFXSOffsetX                                 , 0x204)
        SCHEMA_FIELD(float                           , m_flSFXSOffsetY                                 , 0x208)
        SCHEMA_FIELD(float                           , m_flSFXSOffsetZ                                 , 0x20C)
        SCHEMA_FIELD(DetailCombo_t                   , m_nDetailCombo                                  , 0x210)
        SCHEMA_FIELD(float                           , m_flSFXSDetailAmount                            , 0x214)
        SCHEMA_FIELD(float                           , m_flSFXSDetailScale                             , 0x218)
        SCHEMA_FIELD(float                           , m_flSFXSDetailScrollX                           , 0x21C)
        SCHEMA_FIELD(float                           , m_flSFXSDetailScrollY                           , 0x220)
        SCHEMA_FIELD(float                           , m_flSFXSDetailScrollZ                           , 0x224)
        SCHEMA_FIELD(float                           , m_flSFXSUseModelUVs                             , 0x228)
    };

    class C_OP_SequenceFromModel {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutputAnim                              , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F0)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1F4)
    };

    class C_INIT_PointList {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(CUtlVector<PointDefinition_t>   , m_pointList                                     , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bPlaceAlongPath                               , 0x200)
        SCHEMA_FIELD(bool                            , m_bClosedLoop                                   , 0x201)
        SCHEMA_FIELD(std::int32_t                    , m_nNumPointsAlongPath                           , 0x204)
    };

    class C_OP_SetControlPointFieldFromVectorExpression {
    public:
        SCHEMA_FIELD(VectorFloatExpressionType_t     , m_nExpression                                   , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecInput1                                     , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecInput2                                     , 0x8A0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLerp                                        , 0xF58)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x10C8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x1238)
        SCHEMA_FIELD(std::int32_t                    , m_nOutVectorField                               , 0x123C)
    };

    class C_OP_ControlpointLight {
    public:
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint1                                , 0x660)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint2                                , 0x664)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint3                                , 0x668)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint4                                , 0x66C)
        SCHEMA_FIELD(::Vector                        , m_vecCPOffset1                                  , 0x670)
        SCHEMA_FIELD(::Vector                        , m_vecCPOffset2                                  , 0x67C)
        SCHEMA_FIELD(::Vector                        , m_vecCPOffset3                                  , 0x688)
        SCHEMA_FIELD(::Vector                        , m_vecCPOffset4                                  , 0x694)
        SCHEMA_FIELD(float                           , m_LightFiftyDist1                               , 0x6A0)
        SCHEMA_FIELD(float                           , m_LightZeroDist1                                , 0x6A4)
        SCHEMA_FIELD(float                           , m_LightFiftyDist2                               , 0x6A8)
        SCHEMA_FIELD(float                           , m_LightZeroDist2                                , 0x6AC)
        SCHEMA_FIELD(float                           , m_LightFiftyDist3                               , 0x6B0)
        SCHEMA_FIELD(float                           , m_LightZeroDist3                                , 0x6B4)
        SCHEMA_FIELD(float                           , m_LightFiftyDist4                               , 0x6B8)
        SCHEMA_FIELD(float                           , m_LightZeroDist4                                , 0x6BC)
        SCHEMA_FIELD(::Color                         , m_LightColor1                                   , 0x6C0)
        SCHEMA_FIELD(::Color                         , m_LightColor2                                   , 0x6C4)
        SCHEMA_FIELD(::Color                         , m_LightColor3                                   , 0x6C8)
        SCHEMA_FIELD(::Color                         , m_LightColor4                                   , 0x6CC)
        SCHEMA_FIELD(bool                            , m_bLightType1                                   , 0x6D0)
        SCHEMA_FIELD(bool                            , m_bLightType2                                   , 0x6D1)
        SCHEMA_FIELD(bool                            , m_bLightType3                                   , 0x6D2)
        SCHEMA_FIELD(bool                            , m_bLightType4                                   , 0x6D3)
        SCHEMA_FIELD(bool                            , m_bLightDynamic1                                , 0x6D4)
        SCHEMA_FIELD(bool                            , m_bLightDynamic2                                , 0x6D5)
        SCHEMA_FIELD(bool                            , m_bLightDynamic3                                , 0x6D6)
        SCHEMA_FIELD(bool                            , m_bLightDynamic4                                , 0x6D7)
        SCHEMA_FIELD(bool                            , m_bUseNormal                                    , 0x6D8)
        SCHEMA_FIELD(bool                            , m_bUseHLambert                                  , 0x6D9)
        SCHEMA_FIELD(bool                            , m_bClampLowerRange                              , 0x6DE)
        SCHEMA_FIELD(bool                            , m_bClampUpperRange                              , 0x6DF)
    };

    class C_INIT_CreateSpiralSphere {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flDensity                                     , 0x248)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInitialRadius                               , 0x3B8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInitialSpeedMin                             , 0x528)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInitialSpeedMax                             , 0x698)
        SCHEMA_FIELD(bool                            , m_bUseParticleCount                             , 0x808)
    };

    class C_OP_ConnectParentParticleToNearest {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nFirstControlPoint                            , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nSecondControlPoint                           , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bUseRadius                                    , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadiusScale                                 , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flParentRadiusScale                           , 0x358)
    };

    class C_OP_SetToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecOffset                                     , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bOffsetLocal                                  , 0x1E8)
    };

    class C_OP_SetPerChildControlPointFromAttribute {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstControlPoint                            , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nNumControlPoints                             , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nParticleIncrement                            , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstSourcePoint                             , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bNumBasedOnParticleCount                      , 0x1EC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttributeToRead                              , 0x1F0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPField                                      , 0x1F4)
    };

    class C_OP_RenderBlobs {
    public:
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_cubeWidth                                     , 0x228)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_cutoffRadius                                  , 0x398)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_renderRadius                                  , 0x508)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexCountKb                                , 0x678)
        SCHEMA_FIELD(std::uint32_t                   , m_nIndexCountKb                                 , 0x67C)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleCP                                      , 0x680)
        SCHEMA_FIELD(CUtlVector<MaterialVariable_t>  , m_MaterialVars                                  , 0x688)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0x6B8)
    };

    class C_OP_CycleScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nDestField                                    , 0x1D8)
        SCHEMA_FIELD(float                           , m_flStartValue                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flEndValue                                    , 0x1E0)
        SCHEMA_FIELD(float                           , m_flCycleTime                                   , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bDoNotRepeatCycle                             , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bSynchronizeParticles                         , 0x1E9)
        SCHEMA_FIELD(std::int32_t                    , m_nCPScale                                      , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nCPFieldMin                                   , 0x1F0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPFieldMax                                   , 0x1F4)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1F8)
    };

    class C_OP_PinRopeSegmentParticleToParent {
    public:
        SCHEMA_FIELD(ParticleSelection_t             , m_nParticleSelection                            , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nParticleNumber                               , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x350)
    };

    class ParticleControlPointConfiguration_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_name                                          , 0x0)
        SCHEMA_FIELD(CUtlVector<ParticleControlPointDriver_t>, m_drivers                                       , 0x8)
        SCHEMA_FIELD(ParticlePreviewState_t          , m_previewState                                  , 0x20)
    };

    class C_OP_PlayEndCapWhenFinished {
    public:
        SCHEMA_FIELD(bool                            , m_bFireOnEmissionEnd                            , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bIncludeChildren                              , 0x1E1)
    };

    class C_OP_RemapTransformOrientationToRotations {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecRotation                                   , 0x240)
        SCHEMA_FIELD(bool                            , m_bUseQuat                                      , 0x24C)
        SCHEMA_FIELD(bool                            , m_bWriteNormal                                  , 0x24D)
    };

    class C_OP_ReadFromNeighboringParticle {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nIncrement                                    , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_DistanceCheck                                 , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x358)
    };

    class C_OP_Callback {
    public:
    };

    class C_OP_LerpEndCapVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecOutput                                     , 0x1DC)
        SCHEMA_FIELD(float                           , m_flLerpTime                                    , 0x1E8)
    };

    class ParticleChildrenInfo_t {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_ChildRef                                      , 0x0)
        SCHEMA_FIELD(float                           , m_flDelay                                       , 0x8)
        SCHEMA_FIELD(bool                            , m_bEndCap                                       , 0xC)
        SCHEMA_FIELD(bool                            , m_bDisableChild                                 , 0xD)
        SCHEMA_FIELD(ParticleDetailLevel_t           , m_nDetailLevel                                  , 0x10)
    };

    class C_OP_RampCPLinearRandom {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointNumber                        , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecRateMin                                    , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecRateMax                                    , 0x1F0)
    };

    class C_OP_SpinUpdate {
    public:
    };

    class CPulseCell_IsRequirementValid {
    public:
    };

    class C_OP_RemapTransformVisibilityToScalar {
    public:
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1D8)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x248)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x24C)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x250)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x254)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x258)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x25C)
    };

    class TextureGroup_t {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x0)
        SCHEMA_FIELD(bool                            , m_bReplaceTextureWithGradient                   , 0x1)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hTexture                                      , 0x8)
        SCHEMA_FIELD(CColorGradient                  , m_Gradient                                      , 0x10)
        SCHEMA_FIELD(SpriteCardTextureType_t         , m_nTextureType                                  , 0x28)
        SCHEMA_FIELD(SpriteCardTextureChannel_t      , m_nTextureChannels                              , 0x2C)
        SCHEMA_FIELD(ParticleTextureLayerBlendType_t , m_nTextureBlendMode                             , 0x30)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flTextureBlend                                , 0x38)
        SCHEMA_FIELD(TextureControls_t               , m_TextureControls                               , 0x1A8)
    };

    class CPulseCell_Outflow_CycleShuffled_InstanceState_t {
    public:
        using _Type0 = CUtlVectorFixedGrowable<uint8,8>;
        SCHEMA_FIELD(_Type0                          , m_Shuffle                                       , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nNextShuffle                                  , 0x20)
    };

    class C_OP_RenderStatusEffect {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureColorWarp                             , 0x228)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureDetail2                               , 0x230)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureDiffuseWarp                           , 0x238)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureFresnelColorWarp                      , 0x240)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureFresnelWarp                           , 0x248)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureSpecularWarp                          , 0x250)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureEnvMap                                , 0x258)
    };

    class C_OP_DistanceBetweenVecs {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPoint1                                     , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPoint2                                     , 0x898)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMin                                    , 0xF50)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMax                                    , 0x10C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMin                                   , 0x1230)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMax                                   , 0x13A0)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1510)
        SCHEMA_FIELD(bool                            , m_bDeltaTime                                    , 0x1514)
    };

    class C_OP_MovementMaintainOffset {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecOffset                                     , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bRadiusScale                                  , 0x1E8)
    };

    class C_OP_RemapCPtoCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInputControlPoint                            , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputControlPoint                           , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nInputField                                   , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputField                                  , 0x1EC)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1F0)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1F4)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1F8)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1FC)
        SCHEMA_FIELD(bool                            , m_bDerivative                                   , 0x200)
        SCHEMA_FIELD(float                           , m_flInterpRate                                  , 0x204)
    };

    class C_OP_Cull {
    public:
        SCHEMA_FIELD(float                           , m_flCullPerc                                    , 0x1D8)
        SCHEMA_FIELD(float                           , m_flCullStart                                   , 0x1DC)
        SCHEMA_FIELD(float                           , m_flCullEnd                                     , 0x1E0)
        SCHEMA_FIELD(float                           , m_flCullExp                                     , 0x1E4)
    };

    class C_INIT_CreateWithinCapsuleTransform {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fRadiusMin                                    , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fRadiusMax                                    , 0x350)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fHeight                                       , 0x4C0)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x630)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMin                                     , 0x698)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMax                                     , 0x808)
        SCHEMA_FIELD(float                           , m_fSpeedRandExp                                 , 0x978)
        SCHEMA_FIELD(CPerParticleVecInput            , m_LocalCoordinateSystemSpeedMin                 , 0x980)
        SCHEMA_FIELD(CPerParticleVecInput            , m_LocalCoordinateSystemSpeedMax                 , 0x1038)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x16F0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldVelocity                                , 0x16F4)
    };

    class C_OP_RampScalarSplineSimple {
    public:
        SCHEMA_FIELD(float                           , m_Rate                                          , 0x1D8)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x1DC)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x210)
        SCHEMA_FIELD(bool                            , m_bEaseOut                                      , 0x214)
    };

    class C_OP_RemapDistanceToLineSegmentToScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1F0)
        SCHEMA_FIELD(float                           , m_flMinOutputValue                              , 0x1F4)
        SCHEMA_FIELD(float                           , m_flMaxOutputValue                              , 0x1F8)
    };

    class CPulseCell_Inflow_Wait {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
    };

    class C_OP_RenderStandardLight {
    public:
        SCHEMA_FIELD(ParticleLightTypeChoiceList_t   , m_nLightType                                    , 0x228)
        SCHEMA_FIELD(std::uint16_t                   , m_nMaxAllowed                                   , 0x22C)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorScale                                 , 0x230)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0x8E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flIntensity                                   , 0x8F0)
        SCHEMA_FIELD(bool                            , m_bCastShadows                                  , 0xA60)
        SCHEMA_FIELD(bool                            , m_bDynamicBounce                                , 0xA61)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBounceScale                                 , 0xA68)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flTheta                                       , 0xBD8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flPhi                                         , 0xD48)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadiusMultiplier                            , 0xEB8)
        SCHEMA_FIELD(StandardLightingAttenuationStyle_t, m_nAttenuationStyle                             , 0x1028)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flFalloffLinearity                            , 0x1030)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flFiftyPercentFalloff                         , 0x11A0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flZeroPercentFalloff                          , 0x1310)
        SCHEMA_FIELD(bool                            , m_bRenderDiffuse                                , 0x1480)
        SCHEMA_FIELD(bool                            , m_bRenderSpecular                               , 0x1481)
        SCHEMA_FIELD(::CUtlString                    , m_lightCookie                                   , 0x1488)
        SCHEMA_FIELD(std::int32_t                    , m_nPriority                                     , 0x1490)
        SCHEMA_FIELD(ParticleLightFogLightingMode_t  , m_nFogLightingMode                              , 0x1494)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFogContribution                             , 0x1498)
        SCHEMA_FIELD(ParticleLightBehaviorChoiceList_t, m_nCapsuleLightBehavior                         , 0x1608)
        SCHEMA_FIELD(float                           , m_flCapsuleLength                               , 0x160C)
        SCHEMA_FIELD(bool                            , m_bReverseOrder                                 , 0x1610)
        SCHEMA_FIELD(bool                            , m_bClosedLoop                                   , 0x1611)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nPrevPntSource                                , 0x1614)
        SCHEMA_FIELD(float                           , m_flMaxLength                                   , 0x1618)
        SCHEMA_FIELD(float                           , m_flMinLength                                   , 0x161C)
        SCHEMA_FIELD(bool                            , m_bIgnoreDT                                     , 0x1620)
        SCHEMA_FIELD(float                           , m_flConstrainRadiusToLengthRatio                , 0x1624)
        SCHEMA_FIELD(float                           , m_flLengthScale                                 , 0x1628)
        SCHEMA_FIELD(float                           , m_flLengthFadeInTime                            , 0x162C)
    };

    class C_INIT_RemapInitialVisibilityScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1F0)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F4)
    };

    class C_INIT_CreateOnGrid {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nXCount                                       , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nYCount                                       , 0x350)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nZCount                                       , 0x4C0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nXSpacing                                     , 0x630)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nYSpacing                                     , 0x7A0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nZSpacing                                     , 0x910)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0xA80)
        SCHEMA_FIELD(bool                            , m_bLocalSpace                                   , 0xA84)
        SCHEMA_FIELD(bool                            , m_bCenter                                       , 0xA85)
        SCHEMA_FIELD(bool                            , m_bHollow                                       , 0xA86)
    };

    class C_OP_OscillateScalar {
    public:
        SCHEMA_FIELD(float                           , m_RateMin                                       , 0x1D8)
        SCHEMA_FIELD(float                           , m_RateMax                                       , 0x1DC)
        SCHEMA_FIELD(float                           , m_FrequencyMin                                  , 0x1E0)
        SCHEMA_FIELD(float                           , m_FrequencyMax                                  , 0x1E4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bProportionalOp                               , 0x1ED)
        SCHEMA_FIELD(float                           , m_flStartTime_min                               , 0x1F0)
        SCHEMA_FIELD(float                           , m_flStartTime_max                               , 0x1F4)
        SCHEMA_FIELD(float                           , m_flEndTime_min                                 , 0x1F8)
        SCHEMA_FIELD(float                           , m_flEndTime_max                                 , 0x1FC)
        SCHEMA_FIELD(float                           , m_flOscMult                                     , 0x200)
        SCHEMA_FIELD(float                           , m_flOscAdd                                      , 0x204)
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

    class C_OP_RemapVectortoCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointNumber                        , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nParticleNumber                               , 0x1E0)
    };

    class C_OP_ScreenSpaceDistanceToEdge {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMaxDistFromEdge                             , 0x1E0)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x350)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x4C0)
    };

    class C_OP_SetControlPointsToModelParticles {
    public:
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x1D8)
        SCHEMA_FIELD(char                            , m_AttachmentName                                , 0x258)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstControlPoint                            , 0x2D8)
        SCHEMA_FIELD(std::int32_t                    , m_nNumControlPoints                             , 0x2DC)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstSourcePoint                             , 0x2E0)
        SCHEMA_FIELD(bool                            , m_bSkin                                         , 0x2E4)
        SCHEMA_FIELD(bool                            , m_bAttachment                                   , 0x2E5)
    };

    class C_OP_RenderStatusEffectCitadel {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureColorWarp                             , 0x228)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureNormal                                , 0x230)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureMetalness                             , 0x238)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureRoughness                             , 0x240)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureSelfIllum                             , 0x248)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_pTextureDetail                                , 0x250)
    };

    class CPulse_OutflowConnection {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutflowName                             , 0x0)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nDestChunk                                    , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nInstruction                                  , 0x14)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_OutflowRegisterMap                            , 0x18)
    };

    class C_INIT_RemapQAnglesToRotation {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
    };

    class C_INIT_CreateOnModelAtHeight {
    public:
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bForceZ                                       , 0x1E1)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nHeightCP                                     , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bUseWaterHeight                               , 0x1EC)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDesiredHeight                               , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecHitBoxScale                                , 0x360)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecDirectionBias                              , 0xA18)
        SCHEMA_FIELD(ParticleHitboxBiasType_t        , m_nBiasType                                     , 0x10D0)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0x10D4)
        SCHEMA_FIELD(bool                            , m_bPreferMovingBoxes                            , 0x10D5)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x10D6)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flHitboxVelocityScale                         , 0x1158)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMaxBoneVelocity                             , 0x12C8)
    };

    class C_OP_RampScalarLinear {
    public:
        SCHEMA_FIELD(float                           , m_RateMin                                       , 0x1D8)
        SCHEMA_FIELD(float                           , m_RateMax                                       , 0x1DC)
        SCHEMA_FIELD(float                           , m_flStartTime_min                               , 0x1E0)
        SCHEMA_FIELD(float                           , m_flStartTime_max                               , 0x1E4)
        SCHEMA_FIELD(float                           , m_flEndTime_min                                 , 0x1E8)
        SCHEMA_FIELD(float                           , m_flEndTime_max                                 , 0x1EC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x210)
        SCHEMA_FIELD(bool                            , m_bProportionalOp                               , 0x214)
    };

    class C_OP_CPVelocityForce {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flScale                                       , 0x1F0)
    };

    class C_OP_AttractToControlPoint {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecComponentScale                             , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fForceAmount                                  , 0x1F8)
        SCHEMA_FIELD(float                           , m_fFalloffPower                                 , 0x368)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x370)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fForceAmountMin                               , 0x3D8)
        SCHEMA_FIELD(bool                            , m_bApplyMinForce                                , 0x548)
    };

    class C_INIT_CreateOnModel {
    public:
        SCHEMA_FIELD(CParticleModelInput             , m_modelInput                                    , 0x1E0)
        SCHEMA_FIELD(CParticleTransformInput         , m_transformInput                                , 0x240)
        SCHEMA_FIELD(std::int32_t                    , m_nForceInModel                                 , 0x2A8)
        SCHEMA_FIELD(bool                            , m_bScaleToVolume                                , 0x2AC)
        SCHEMA_FIELD(bool                            , m_bEvenDistribution                             , 0x2AD)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nDesiredHitbox                                , 0x2B0)
        SCHEMA_FIELD(std::int32_t                    , m_nHitboxValueFromControlPointIndex             , 0x420)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecHitBoxScale                                , 0x428)
        SCHEMA_FIELD(float                           , m_flBoneVelocity                                , 0xAE0)
        SCHEMA_FIELD(float                           , m_flMaxBoneVelocity                             , 0xAE4)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecDirectionBias                              , 0xAE8)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x11A0)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0x1220)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x1221)
        SCHEMA_FIELD(bool                            , m_bUseMesh                                      , 0x1222)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flShellSize                                   , 0x1228)
    };

    class C_OP_RandomForce {
    public:
        SCHEMA_FIELD(::Vector                        , m_MinForce                                      , 0x1E8)
        SCHEMA_FIELD(::Vector                        , m_MaxForce                                      , 0x1F4)
    };

    class C_OP_RemapNamedModelMeshGroupOnceTimed {
    public:
    };

    class C_INIT_RemapNamedModelMeshGroupToScalar {
    public:
    };

    class CParticleVisibilityInputs {
    public:
        SCHEMA_FIELD(float                           , m_flCameraBias                                  , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPin                                         , 0x4)
        SCHEMA_FIELD(float                           , m_flProxyRadius                                 , 0x8)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0xC)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x10)
        SCHEMA_FIELD(float                           , m_flInputPixelVisFade                           , 0x14)
        SCHEMA_FIELD(float                           , m_flNoPixelVisibilityFallback                   , 0x18)
        SCHEMA_FIELD(float                           , m_flDistanceInputMin                            , 0x1C)
        SCHEMA_FIELD(float                           , m_flDistanceInputMax                            , 0x20)
        SCHEMA_FIELD(float                           , m_flDotInputMin                                 , 0x24)
        SCHEMA_FIELD(float                           , m_flDotInputMax                                 , 0x28)
        SCHEMA_FIELD(bool                            , m_bDotCPAngles                                  , 0x2C)
        SCHEMA_FIELD(bool                            , m_bDotCameraAngles                              , 0x2D)
        SCHEMA_FIELD(float                           , m_flAlphaScaleMin                               , 0x30)
        SCHEMA_FIELD(float                           , m_flAlphaScaleMax                               , 0x34)
        SCHEMA_FIELD(float                           , m_flRadiusScaleMin                              , 0x38)
        SCHEMA_FIELD(float                           , m_flRadiusScaleMax                              , 0x3C)
        SCHEMA_FIELD(float                           , m_flRadiusScaleFOVBase                          , 0x40)
        SCHEMA_FIELD(bool                            , m_bRightEye                                     , 0x44)
    };

    class CPulse_InvokeBinding {
    public:
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_FuncName                                      , 0x30)
        SCHEMA_FIELD(PulseRuntimeCellIndex_t         , m_nCellIndex                                    , 0x40)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nSrcChunk                                     , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_nSrcInstruction                               , 0x48)
    };

    class C_INIT_RadiusFromCPObject {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x1E0)
    };

    class C_OP_MultiSegmentDisplaySnapshotGenerator {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPSnapshot                                   , 0x1E0)
        SCHEMA_FIELD(ParticleMultiSegmentCountSelection_t, m_nSegCount                                     , 0x1E4)
        SCHEMA_FIELD(ParticleMultiSegmentInputSelection_t, m_nInputType                                    , 0x1E8)
        SCHEMA_FIELD(::CUtlString                    , m_strDefaultString                              , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flValue                                       , 0x1F8)
        SCHEMA_FIELD(CUtlVector<ParticleMultiSegmentSpecialCharacter_t>, m_SpecialCharList                               , 0x368)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorUnlit                                 , 0x380)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorLit                                   , 0xA38)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadius                                      , 0x10F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flSpacing                                     , 0x1260)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMinCount                                    , 0x13D0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMaxCount                                    , 0x1540)
        SCHEMA_FIELD(bool                            , m_bPrependEmpty                                 , 0x16B0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDigitsAfterDecimal                          , 0x16B8)
    };

    class C_OP_TimeVaryingForce {
    public:
        SCHEMA_FIELD(float                           , m_flStartLerpTime                               , 0x1E8)
        SCHEMA_FIELD(::Vector                        , m_StartingForce                                 , 0x1EC)
        SCHEMA_FIELD(float                           , m_flEndLerpTime                                 , 0x1F8)
        SCHEMA_FIELD(::Vector                        , m_EndingForce                                   , 0x1FC)
    };

    class C_INIT_RandomAlphaWindowThreshold {
    public:
        SCHEMA_FIELD(float                           , m_flMin                                         , 0x1E0)
        SCHEMA_FIELD(float                           , m_flMax                                         , 0x1E4)
        SCHEMA_FIELD(float                           , m_flExponent                                    , 0x1E8)
    };

    class C_OP_NoiseEmitter {
    public:
        SCHEMA_FIELD(float                           , m_flEmissionDuration                            , 0x1E0)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x1E4)
        SCHEMA_FIELD(float                           , m_flEmissionScale                               , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPoint                            , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPointField                       , 0x1F0)
        SCHEMA_FIELD(std::int32_t                    , m_nWorldNoisePoint                              , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bAbsVal                                       , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bAbsValInv                                    , 0x1F9)
        SCHEMA_FIELD(float                           , m_flOffset                                      , 0x1FC)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x200)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x204)
        SCHEMA_FIELD(float                           , m_flNoiseScale                                  , 0x208)
        SCHEMA_FIELD(float                           , m_flWorldNoiseScale                             , 0x20C)
        SCHEMA_FIELD(::Vector                        , m_vecOffsetLoc                                  , 0x210)
        SCHEMA_FIELD(float                           , m_flWorldTimeScale                              , 0x21C)
    };

    class C_INIT_PositionOffset {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_OffsetMin                                     , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_OffsetMax                                     , 0x898)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0xF50)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0xFB8)
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0xFB9)
        SCHEMA_FIELD(CRandomNumberGeneratorParameters, m_randomnessParameters                          , 0xFBC)
    };

    class C_INIT_RandomRotation {
    public:
    };

    class C_OP_FadeIn {
    public:
        SCHEMA_FIELD(float                           , m_flFadeInTimeMin                               , 0x1D8)
        SCHEMA_FIELD(float                           , m_flFadeInTimeMax                               , 0x1DC)
        SCHEMA_FIELD(float                           , m_flFadeInTimeExp                               , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0x1E4)
    };

    class C_OP_LazyCullCompareFloat {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flComparsion1                                 , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flComparsion2                                 , 0x348)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flCullTime                                    , 0x4B8)
    };

    class CPulse_BlackboardReference {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIPulseGraphDef>, m_hBlackboardResource                           , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_BlackboardResource                            , 0x8)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nNodeID                                       , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , m_NodeName                                      , 0x20)
    };

    class CParticleFunction {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOpStrength                                  , 0x8)
        SCHEMA_FIELD(ParticleEndcapMode_t            , m_nOpEndCapState                                , 0x178)
        SCHEMA_FIELD(ParticleToolsState_t            , m_nToolsState                                   , 0x17C)
        SCHEMA_FIELD(float                           , m_flOpStartFadeInTime                           , 0x180)
        SCHEMA_FIELD(float                           , m_flOpEndFadeInTime                             , 0x184)
        SCHEMA_FIELD(float                           , m_flOpStartFadeOutTime                          , 0x188)
        SCHEMA_FIELD(float                           , m_flOpEndFadeOutTime                            , 0x18C)
        SCHEMA_FIELD(float                           , m_flOpFadeOscillatePeriod                       , 0x190)
        SCHEMA_FIELD(bool                            , m_bNormalizeToStopTime                          , 0x194)
        SCHEMA_FIELD(float                           , m_flOpTimeOffsetMin                             , 0x198)
        SCHEMA_FIELD(float                           , m_flOpTimeOffsetMax                             , 0x19C)
        SCHEMA_FIELD(std::int32_t                    , m_nOpTimeOffsetSeed                             , 0x1A0)
        SCHEMA_FIELD(std::int32_t                    , m_nOpTimeScaleSeed                              , 0x1A4)
        SCHEMA_FIELD(float                           , m_flOpTimeScaleMin                              , 0x1A8)
        SCHEMA_FIELD(float                           , m_flOpTimeScaleMax                              , 0x1AC)
        SCHEMA_FIELD(bool                            , m_bDisableOperator                              , 0x1B2)
        SCHEMA_FIELD(::CUtlString                    , m_Notes                                         , 0x1B8)
    };

    class C_OP_GameLiquidSpill {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flLiquidContentsField                         , 0x228)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flExpirationTime                              , 0x398)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAmountAttribute                              , 0x508)
    };

    class C_OP_SetControlPointPositions {
    public:
        SCHEMA_FIELD(bool                            , m_bUseWorldLocation                             , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bOrient                                       , 0x1E1)
        SCHEMA_FIELD(bool                            , m_bSetOnce                                      , 0x1E2)
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nCP2                                          , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nCP3                                          , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nCP4                                          , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vecCP1Pos                                     , 0x1F4)
        SCHEMA_FIELD(::Vector                        , m_vecCP2Pos                                     , 0x200)
        SCHEMA_FIELD(::Vector                        , m_vecCP3Pos                                     , 0x20C)
        SCHEMA_FIELD(::Vector                        , m_vecCP4Pos                                     , 0x218)
        SCHEMA_FIELD(std::int32_t                    , m_nHeadLocation                                 , 0x224)
    };

    class C_OP_SetControlPointOrientationToCPVelocity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPInput                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutput                                     , 0x1E4)
    };

    class C_INIT_InitFromCPSnapshot {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(::CUtlString                    , m_strSnapshotSubset                             , 0x1E8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttributeToRead                              , 0x1F0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttributeToWrite                             , 0x1F4)
        SCHEMA_FIELD(std::int32_t                    , m_nLocalSpaceCP                                 , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bRandom                                       , 0x1FC)
        SCHEMA_FIELD(bool                            , m_bReverse                                      , 0x1FD)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nSnapShotIncrement                            , 0x200)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_nManualSnapshotIndex                          , 0x370)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0x4E0)
        SCHEMA_FIELD(bool                            , m_bLocalSpaceAngles                             , 0x4E4)
    };

    class C_OP_RemapCrossProductOfTwoVectorsToVector {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_InputVec1                                     , 0x1D8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_InputVec2                                     , 0x890)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0xF48)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0xF4C)
    };

    class CPulseCursorFuncs {
    public:
    };

    class CPulseExecCursor {
    public:
    };

    class C_INIT_SetAttributeToScalarExpression {
    public:
        SCHEMA_FIELD(ScalarExpressionType_t          , m_nExpression                                   , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInput1                                      , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInput2                                      , 0x358)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x4C8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x638)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x63C)
    };

    class CPulseCell_IntervalTimer {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_Completed                                     , 0x48)
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_OnInterval                                    , 0x90)
    };

    class C_OP_RemapNamedModelBodyPartEndCap {
    public:
    };

    class C_OP_DecayMaintainCount {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nParticlesToMaintain                          , 0x1D8)
        SCHEMA_FIELD(float                           , m_flDecayDelay                                  , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPoint                         , 0x1E0)
        SCHEMA_FIELD(::CUtlString                    , m_strSnapshotSubset                             , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bLifespanDecay                                , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flScale                                       , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bKillNewest                                   , 0x368)
    };

    class C_OP_RemapVisibilityScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1EC)
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x1F0)
    };

    class CPulseCell_Inflow_BaseEntrypoint {
    public:
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_EntryChunk                                    , 0x48)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x50)
    };

    class C_OP_SetControlPointToImpactPoint {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPOut                                        , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPIn                                         , 0x1E4)
        SCHEMA_FIELD(float                           , m_flUpdateRate                                  , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flTraceLength                                 , 0x1F0)
        SCHEMA_FIELD(float                           , m_flStartOffset                                 , 0x360)
        SCHEMA_FIELD(float                           , m_flOffset                                      , 0x364)
        SCHEMA_FIELD(::Vector                        , m_vecTraceDir                                   , 0x368)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x374)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x3F4)
        SCHEMA_FIELD(bool                            , m_bSetToEndpoint                                , 0x3F8)
        SCHEMA_FIELD(bool                            , m_bTraceToClosestSurface                        , 0x3F9)
        SCHEMA_FIELD(bool                            , m_bIncludeWater                                 , 0x3FA)
    };

    class C_OP_BoxConstraint {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecMin                                        , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecMax                                        , 0x890)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0xF48)
        SCHEMA_FIELD(bool                            , m_bLocalSpace                                   , 0xF4C)
        SCHEMA_FIELD(bool                            , m_bAccountForRadius                             , 0xF4D)
    };

    class C_OP_SetCPtoVector {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPInput                                      , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
    };

    class C_OP_ClampVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecOutputMin                                  , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecOutputMax                                  , 0x898)
    };

    class C_OP_LagCompensation {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nDesiredVelocityCP                            , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nLatencyCP                                    , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nLatencyCPField                               , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nDesiredVelocityCPField                       , 0x1E4)
    };

    class C_OP_RemapVectorComponentToScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent                                    , 0x1E0)
    };

    class C_OP_SetFloat {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputValue                                    , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x348)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x34C)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_Lerp                                          , 0x350)
    };

    class C_OP_RenderText {
    public:
        SCHEMA_FIELD(::Color                         , m_OutlineColor                                  , 0x228)
        SCHEMA_FIELD(::CUtlString                    , m_DefaultText                                   , 0x230)
    };

    class C_OP_RenderGpuImplicit {
    public:
        SCHEMA_FIELD(bool                            , m_bUsePerParticleRadius                         , 0x228)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexCountKb                                , 0x22C)
        SCHEMA_FIELD(std::uint32_t                   , m_nIndexCountKb                                 , 0x230)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_fGridSize                                     , 0x238)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_fRadiusScale                                  , 0x3A8)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_fIsosurfaceThreshold                          , 0x518)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleCP                                      , 0x688)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0x690)
    };

    class C_OP_MovementPlaceOnGround {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOffset                                      , 0x1D8)
        SCHEMA_FIELD(float                           , m_flMaxTraceLength                              , 0x348)
        SCHEMA_FIELD(float                           , m_flTolerance                                   , 0x34C)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecTraceDir                                   , 0x350)
        SCHEMA_FIELD(float                           , m_flTraceOffset                                 , 0xA08)
        SCHEMA_FIELD(float                           , m_flLerpRate                                    , 0xA0C)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0xA10)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0xA90)
        SCHEMA_FIELD(std::int32_t                    , m_nRefCP1                                       , 0xA94)
        SCHEMA_FIELD(std::int32_t                    , m_nRefCP2                                       , 0xA98)
        SCHEMA_FIELD(std::int32_t                    , m_nLerpCP                                       , 0xA9C)
        SCHEMA_FIELD(ParticleTraceMissBehavior_t     , m_nTraceMissBehavior                            , 0xAA8)
        SCHEMA_FIELD(bool                            , m_bIncludeShotHull                              , 0xAAC)
        SCHEMA_FIELD(bool                            , m_bIncludeWater                                 , 0xAAD)
        SCHEMA_FIELD(bool                            , m_bSetNormal                                    , 0xAB0)
        SCHEMA_FIELD(bool                            , m_bScaleOffset                                  , 0xAB1)
        SCHEMA_FIELD(std::int32_t                    , m_nPreserveOffsetCP                             , 0xAB4)
        SCHEMA_FIELD(std::int32_t                    , m_nIgnoreCP                                     , 0xAB8)
    };

    class C_INIT_RandomNamedModelBodyPart {
    public:
    };

    class CPAssignment_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPNumber                                     , 0x0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_Pos                                           , 0x8)
        SCHEMA_FIELD(ParticleOrientationSetMode_t    , m_nOrientationMode                              , 0x6C0)
    };

    class CParticleBindingRealPulse {
    public:
    };

    class C_OP_SetSingleControlPointPosition {
    public:
        SCHEMA_FIELD(bool                            , m_bSetOnce                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E4)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecCP1Pos                                     , 0x1E8)
        SCHEMA_FIELD(CParticleTransformInput         , m_transformInput                                , 0x8A0)
    };

    class CPulseArraylib {
    public:
    };

    class PulseNodeDynamicOutflows_t_DynamicOutflow_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_OutflowID                                     , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x8)
    };

    class C_OP_EndCapDecay {
    public:
    };

    class CGeneralSpin {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSpinRateDegrees                              , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nSpinRateMinDegrees                           , 0x1DC)
        SCHEMA_FIELD(float                           , m_fSpinRateStopTime                             , 0x1E4)
    };

    class C_OP_SetSimulationRate {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flSimulationScale                             , 0x1E0)
    };

    class C_OP_RemapCPtoScalar {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPInput                                      , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nField                                        , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F0)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x1F4)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x1F8)
        SCHEMA_FIELD(float                           , m_flInterpRate                                  , 0x1FC)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x200)
    };

    class C_OP_TeleportBeam {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPPosition                                   , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nCPVelocity                                   , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nCPMisc                                       , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPColor                                      , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nCPInvalidColor                               , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nCPExtraArcData                               , 0x1EC)
        SCHEMA_FIELD(::Vector                        , m_vGravity                                      , 0x1F0)
        SCHEMA_FIELD(float                           , m_flArcMaxDuration                              , 0x1FC)
        SCHEMA_FIELD(float                           , m_flSegmentBreak                                , 0x200)
        SCHEMA_FIELD(float                           , m_flArcSpeed                                    , 0x204)
        SCHEMA_FIELD(float                           , m_flAlpha                                       , 0x208)
    };

    class C_OP_PercentageBetweenTransformLerpCPs {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E0)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformStart                                , 0x1E8)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformEnd                                  , 0x250)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputStartCP                                , 0x2B8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputStartField                             , 0x2BC)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputEndCP                                  , 0x2C0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputEndField                               , 0x2C4)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x2C8)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x2CC)
        SCHEMA_FIELD(bool                            , m_bRadialCheck                                  , 0x2CD)
    };

    class C_INIT_SetRigidAttachment {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1E4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bLocalSpace                                   , 0x1EC)
    };

    class CPulseCell_Inflow_Method {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x80)
        SCHEMA_FIELD(::CUtlString                    , m_Description                                   , 0x90)
        SCHEMA_FIELD(bool                            , m_bIsPublic                                     , 0x98)
        SCHEMA_FIELD(CPulseValueFullType             , m_ReturnType                                    , 0xA0)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_Args                                          , 0xB8)
    };

    class C_OP_CollideWithParentParticles {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flParentRadiusScale                           , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadiusScale                                 , 0x348)
    };

    class C_INIT_RemapInitialDirectionToTransformToVector {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x248)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x24C)
        SCHEMA_FIELD(float                           , m_flOffsetRot                                   , 0x250)
        SCHEMA_FIELD(::Vector                        , m_vecOffsetAxis                                 , 0x254)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0x260)
    };

    class C_OP_SetControlPointToHMD {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecCP1Pos                                     , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bOrientToHMD                                  , 0x1F0)
    };

    class C_OP_WorldCollideConstraint {
    public:
    };

    class C_OP_MovementLoopInsideSphere {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDistance                                    , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecScale                                      , 0x350)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nDistSqrAttr                                  , 0xA08)
    };

    class C_OP_ForceBasedOnDistanceToPlane {
    public:
        SCHEMA_FIELD(float                           , m_flMinDist                                     , 0x1E8)
        SCHEMA_FIELD(::Vector                        , m_vecForceAtMinDist                             , 0x1EC)
        SCHEMA_FIELD(float                           , m_flMaxDist                                     , 0x1F8)
        SCHEMA_FIELD(::Vector                        , m_vecForceAtMaxDist                             , 0x1FC)
        SCHEMA_FIELD(::Vector                        , m_vecPlaneNormal                                , 0x208)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x214)
        SCHEMA_FIELD(float                           , m_flExponent                                    , 0x218)
    };

    class C_INIT_AddVectorToVector {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecScale                                      , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1EC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vOffsetMin                                    , 0x1F4)
        SCHEMA_FIELD(::Vector                        , m_vOffsetMax                                    , 0x200)
        SCHEMA_FIELD(CRandomNumberGeneratorParameters, m_randomnessParameters                          , 0x20C)
    };

    class C_OP_PinParticleToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecOffset                                     , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bOffsetLocal                                  , 0x898)
        SCHEMA_FIELD(ParticleSelection_t             , m_nParticleSelection                            , 0x89C)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nParticleNumber                               , 0x8A0)
        SCHEMA_FIELD(ParticlePinDistance_t           , m_nPinBreakType                                 , 0xA10)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBreakDistance                               , 0xA18)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBreakSpeed                                  , 0xB88)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flAge                                         , 0xCF8)
        SCHEMA_FIELD(std::int32_t                    , m_nBreakControlPointNumber                      , 0xE68)
        SCHEMA_FIELD(std::int32_t                    , m_nBreakControlPointNumber2                     , 0xE6C)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flBreakValue                                  , 0xE70)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0xFE0)
        SCHEMA_FIELD(bool                            , m_bRetainInitialVelocity                        , 0x1150)
    };

    class C_OP_ScreenSpaceRotateTowardTarget {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecTargetPosition                             , 0x1D8)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x890)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0xA00)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flScreenEdgeAlignmentDistance                 , 0xA08)
    };

    class CPulseCell_InlineNodeSkipSelector {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nFlowNodeID                                   , 0x48)
        SCHEMA_FIELD(bool                            , m_bAnd                                          , 0x4C)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_PassOutflow                                   , 0x50)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_FailOutflow                                   , 0x68)
    };

    class C_OP_ScreenSpacePositionOfTarget {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecTargetPosition                             , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bOututBehindness                              , 0x890)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nBehindFieldOutput                            , 0x894)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flBehindOutputRemap                           , 0x898)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nBehindSetMethod                              , 0xA08)
    };

    class C_INIT_InheritVelocity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(float                           , m_flVelocityScale                               , 0x1E4)
    };

    class C_OP_SelectivelyEnableChildren {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nChildGroupID                                 , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nFirstChild                                   , 0x350)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nNumChildrenToEnable                          , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bPlayEndcapOnStop                             , 0x630)
        SCHEMA_FIELD(bool                            , m_bDestroyImmediately                           , 0x631)
    };

    class CParticleMassCalculationParameters {
    public:
        SCHEMA_FIELD(ParticleMassMode_t              , m_nMassMode                                     , 0x0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadius                                      , 0x8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flNominalRadius                               , 0x178)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flScale                                       , 0x2E8)
    };

    class CPulseCell_BaseLerp_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
    };

    class CPulseCell_BooleanSwitchState {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Always                                        , 0xC0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenTrue                                      , 0x108)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenFalse                                     , 0x150)
    };

    class C_OP_InheritFromPeerSystem {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nIncrement                                    , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nGroupID                                      , 0x1E4)
    };

    class C_OP_WindForce {
    public:
        SCHEMA_FIELD(::Vector                        , m_vForce                                        , 0x1E8)
    };

    class C_OP_RenderAsModels {
    public:
        SCHEMA_FIELD(CUtlVector<ModelReference_t>    , m_ModelList                                     , 0x228)
        SCHEMA_FIELD(float                           , m_flModelScale                                  , 0x244)
        SCHEMA_FIELD(bool                            , m_bFitToModelSize                               , 0x248)
        SCHEMA_FIELD(bool                            , m_bNonUniformScaling                            , 0x249)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nXAxisScalingAttribute                        , 0x24C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nYAxisScalingAttribute                        , 0x250)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nZAxisScalingAttribute                        , 0x254)
        SCHEMA_FIELD(std::int32_t                    , m_nSizeCullBloat                                , 0x258)
    };

    class C_INIT_InitVecCollection {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_InputValue                                    , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x898)
    };

    class C_INIT_NormalOffset {
    public:
        SCHEMA_FIELD(::Vector                        , m_OffsetMin                                     , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_OffsetMax                                     , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0x1FC)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0x1FD)
    };

    class C_OP_RemapTransformToVelocity {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1D8)
    };

    class C_INIT_RandomScalar {
    public:
        SCHEMA_FIELD(float                           , m_flMin                                         , 0x1E0)
        SCHEMA_FIELD(float                           , m_flMax                                         , 0x1E4)
        SCHEMA_FIELD(float                           , m_flExponent                                    , 0x1E8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1EC)
    };

    class C_OP_Spin {
    public:
    };

    class C_OP_DecayClampCount {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nCount                                        , 0x1D8)
    };

    class C_INIT_RemapNamedModelBodyPartToScalar {
    public:
    };

    class C_OP_MaintainEmitter {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nParticlesToMaintain                          , 0x1E0)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x350)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flEmissionDuration                            , 0x358)
        SCHEMA_FIELD(float                           , m_flEmissionRate                                , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPoint                         , 0x4CC)
        SCHEMA_FIELD(::CUtlString                    , m_strSnapshotSubset                             , 0x4D0)
        SCHEMA_FIELD(bool                            , m_bEmitInstantaneously                          , 0x4D8)
        SCHEMA_FIELD(bool                            , m_bFinalEmitOnStop                              , 0x4D9)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flScale                                       , 0x4E0)
    };

    class C_OP_DriveCPFromGlobalSoundFloat {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nOutputControlPoint                           , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputField                                  , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1F0)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F4)
        SCHEMA_FIELD(::CUtlString                    , m_StackName                                     , 0x1F8)
        SCHEMA_FIELD(::CUtlString                    , m_OperatorName                                  , 0x200)
        SCHEMA_FIELD(::CUtlString                    , m_FieldName                                     , 0x208)
    };

    class CPulseCell_Step_CallExternalMethod {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x48)
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardIndex                              , 0x58)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_ExpectedArgs                                  , 0x60)
        SCHEMA_FIELD(PulseMethodCallMode_t           , m_nAsyncCallMode                                , 0x70)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x78)
    };

    class C_OP_RemapNamedModelSequenceOnceTimed {
    public:
    };

    class C_OP_SetControlPointPositionToTimeOfDayValue {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(char                            , m_pszTimeOfDayParameter                         , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecDefaultValue                               , 0x264)
    };

    class C_OP_LerpScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutput                                      , 0x1E0)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x350)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x354)
    };

    class PointDefinitionWithTimeValues_t {
    public:
        SCHEMA_FIELD(float                           , m_flTimeDuration                                , 0x14)
    };

    class C_OP_RemapDistanceToLineSegmentToVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vMinOutputValue                               , 0x1F4)
        SCHEMA_FIELD(::Vector                        , m_vMaxOutputValue                               , 0x200)
    };

    class C_INIT_InitSkinnedPositionFromCPSnapshot {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPointNumber                   , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bRandom                                       , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bRigid                                        , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bSetNormal                                    , 0x1F1)
        SCHEMA_FIELD(bool                            , m_bIgnoreDt                                     , 0x1F2)
        SCHEMA_FIELD(float                           , m_flMinNormalVelocity                           , 0x1F4)
        SCHEMA_FIELD(float                           , m_flMaxNormalVelocity                           , 0x1F8)
        SCHEMA_FIELD(SnapshotIndexType_t             , m_nIndexType                                    , 0x1FC)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flReadIndex                                   , 0x200)
        SCHEMA_FIELD(float                           , m_flIncrement                                   , 0x370)
        SCHEMA_FIELD(std::int32_t                    , m_nFullLoopIncrement                            , 0x374)
        SCHEMA_FIELD(std::int32_t                    , m_nSnapShotStartPoint                           , 0x378)
        SCHEMA_FIELD(float                           , m_flBoneVelocity                                , 0x37C)
        SCHEMA_FIELD(float                           , m_flBoneVelocityMax                             , 0x380)
        SCHEMA_FIELD(bool                            , m_bCopyColor                                    , 0x384)
        SCHEMA_FIELD(bool                            , m_bCopyAlpha                                    , 0x385)
        SCHEMA_FIELD(bool                            , m_bSetRadius                                    , 0x386)
    };

    class CParticleFunctionEmitter {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nEmitterIndex                                 , 0x1D8)
    };

    class C_OP_RemapNamedModelBodyPartOnceTimed {
    public:
    };

    class C_OP_RemapScalarEndCap {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1EC)
    };

    class C_INIT_RandomYawFlip {
    public:
        SCHEMA_FIELD(float                           , m_flPercent                                     , 0x1E0)
    };

    class C_OP_RemapTransformVisibilityToVector {
    public:
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1D8)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x248)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x24C)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x250)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMin                                  , 0x254)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMax                                  , 0x260)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x26C)
    };

    class C_OP_VelocityDecay {
    public:
        SCHEMA_FIELD(float                           , m_flMinVelocity                                 , 0x1D8)
    };

    class C_OP_SetCPOrientationToDirection {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInputControlPoint                            , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputControlPoint                           , 0x1DC)
    };

    class CPulseCell_Unknown {
    public:
        SCHEMA_FIELD(KeyValues3                      , m_UnknownKeys                                   , 0x48)
    };

    class C_OP_SetControlPointsToParticle {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstControlPoint                            , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nNumControlPoints                             , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstSourcePoint                             , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bReverse                                      , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bSetOrientation                               , 0x1E9)
        SCHEMA_FIELD(ParticleOrientationSetMode_t    , m_nOrientationMode                              , 0x1EC)
        SCHEMA_FIELD(ParticleParentSetMode_t         , m_nSetParent                                    , 0x1F0)
    };

    class C_INIT_VelocityFromCP {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_velocityInput                                 , 0x1E0)
        SCHEMA_FIELD(CParticleTransformInput         , m_transformInput                                , 0x898)
        SCHEMA_FIELD(float                           , m_flVelocityScale                               , 0x900)
        SCHEMA_FIELD(bool                            , m_bDirectionOnly                                , 0x904)
    };

    class C_OP_RemapSpeedtoCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInControlPointNumber                         , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointNumber                        , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nField                                        , 0x1E8)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1EC)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1F0)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1F4)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bUseDeltaV                                    , 0x1FC)
    };

    class C_INIT_RandomSequence {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSequenceMin                                  , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nSequenceMax                                  , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bShuffle                                      , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bLinear                                       , 0x1E9)
        SCHEMA_FIELD(CUtlVector<SequenceWeightedList_t>, m_WeightedList                                  , 0x1F0)
    };

    class C_OP_SetControlPointFromObjectScale {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPInput                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutput                                     , 0x1E4)
    };

    class C_INIT_RemapScalarToVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1EC)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMin                                  , 0x1F0)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMax                                  , 0x1FC)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x208)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x20C)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x210)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x214)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0x218)
        SCHEMA_FIELD(float                           , m_flRemapBias                                   , 0x21C)
    };

    class C_INIT_PlaneCull {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDistance                                    , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bCullInside                                   , 0x358)
    };

    class C_OP_ForceControlPointStub {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_ControlPoint                                  , 0x1E0)
    };

    class C_INIT_NormalAlignToCP {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_transformInput                                , 0x1E0)
        SCHEMA_FIELD(ParticleControlPointAxis_t      , m_nControlPointAxis                             , 0x248)
    };

    class CPulseCell_BaseValue {
    public:
    };

    class C_OP_FadeAndKill {
    public:
        SCHEMA_FIELD(float                           , m_flStartFadeInTime                             , 0x1D8)
        SCHEMA_FIELD(float                           , m_flEndFadeInTime                               , 0x1DC)
        SCHEMA_FIELD(float                           , m_flStartFadeOutTime                            , 0x1E0)
        SCHEMA_FIELD(float                           , m_flEndFadeOutTime                              , 0x1E4)
        SCHEMA_FIELD(float                           , m_flStartAlpha                                  , 0x1E8)
        SCHEMA_FIELD(float                           , m_flEndAlpha                                    , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bForcePreserveParticleOrder                   , 0x1F0)
    };

    class C_INIT_SequenceFromCP {
    public:
        SCHEMA_FIELD(bool                            , m_bKillUnused                                   , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bRadiusScale                                  , 0x1E1)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecOffset                                     , 0x1E8)
    };

    class CollisionGroupContext_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCollisionGroupNumber                         , 0x0)
    };

    class C_OP_VectorFieldSnapshot {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttributeToWrite                             , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nLocalSpaceCP                                 , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x1E8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecScale                                      , 0x358)
        SCHEMA_FIELD(float                           , m_flBoundaryDampening                           , 0xA10)
        SCHEMA_FIELD(bool                            , m_bSetVelocity                                  , 0xA14)
        SCHEMA_FIELD(bool                            , m_bLockToSurface                                , 0xA15)
        SCHEMA_FIELD(float                           , m_flGridSpacing                                 , 0xA18)
    };

    class C_OP_ColorAdjustHSL {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flHueAdjust                                   , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flSaturationAdjust                            , 0x348)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLightnessAdjust                             , 0x4B8)
    };

    class CPulseCell_Inflow_EntOutputHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceEntity                                  , 0x80)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutput                                  , 0x90)
        SCHEMA_FIELD(CPulseValueFullType             , m_ExpectedParamType                             , 0xA0)
    };

    class C_OP_ShapeMatchingConstraint {
    public:
        SCHEMA_FIELD(float                           , m_flShapeRestorationTime                        , 0x1D8)
    };

    class C_OP_SetPerChildControlPoint {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstControlPoint                            , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nNumControlPoints                             , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nParticleIncrement                            , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nFirstSourcePoint                             , 0x358)
        SCHEMA_FIELD(bool                            , m_bSetOrientation                               , 0x4C8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOrientationField                             , 0x4CC)
        SCHEMA_FIELD(bool                            , m_bNumBasedOnParticleCount                      , 0x4D0)
    };

    class C_INIT_VelocityFromNormal {
    public:
        SCHEMA_FIELD(float                           , m_fSpeedMin                                     , 0x1E0)
        SCHEMA_FIELD(float                           , m_fSpeedMax                                     , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bIgnoreDt                                     , 0x1E8)
    };

    class C_OP_InheritFromParentParticlesV2 {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flScale                                       , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x348)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_nIncrement                                    , 0x350)
        SCHEMA_FIELD(bool                            , m_bSubSample                                    , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bRandomDistribution                           , 0x4C1)
        SCHEMA_FIELD(bool                            , m_bReverse                                      , 0x4C2)
        SCHEMA_FIELD(MissingParentInheritBehavior_t  , m_nMissingParentBehavior                        , 0x4C4)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x4C8)
    };

    class C_OP_MovementRigidAttachToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPoint                            , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleCPField                                 , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1E4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bOffsetLocal                                  , 0x1EC)
    };

    class ParticlePreviewState_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_previewModel                                  , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nModSpecificData                              , 0x8)
        SCHEMA_FIELD(PetGroundType_t                 , m_groundType                                    , 0xC)
        SCHEMA_FIELD(::CUtlString                    , m_sequenceName                                  , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nFireParticleOnSequenceFrame                  , 0x18)
        SCHEMA_FIELD(::CUtlString                    , m_hitboxSetName                                 , 0x20)
        SCHEMA_FIELD(::CUtlString                    , m_materialGroupName                             , 0x28)
        SCHEMA_FIELD(CUtlVector<ParticlePreviewBodyGroup_t>, m_vecBodyGroups                                 , 0x30)
        SCHEMA_FIELD(float                           , m_flPlaybackSpeed                               , 0x48)
        SCHEMA_FIELD(float                           , m_flParticleSimulationRate                      , 0x4C)
        SCHEMA_FIELD(bool                            , m_bShouldDrawHitboxes                           , 0x50)
        SCHEMA_FIELD(bool                            , m_bShouldDrawAttachments                        , 0x51)
        SCHEMA_FIELD(bool                            , m_bShouldDrawAttachmentNames                    , 0x52)
        SCHEMA_FIELD(bool                            , m_bShouldDrawControlPointAxes                   , 0x53)
        SCHEMA_FIELD(bool                            , m_bAnimationNonLooping                          , 0x54)
        SCHEMA_FIELD(bool                            , m_bSequenceNameIsAnimClipPath                   , 0x55)
        SCHEMA_FIELD(::Vector                        , m_vecPreviewGravity                             , 0x58)
    };

    class C_OP_RemapScalar {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bOldCode                                      , 0x1F0)
    };

    class C_INIT_InitialRepulsionVelocity {
    public:
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x1E0)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x260)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMin                                  , 0x264)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMax                                  , 0x270)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x27C)
        SCHEMA_FIELD(bool                            , m_bPerParticle                                  , 0x280)
        SCHEMA_FIELD(bool                            , m_bTranslate                                    , 0x281)
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0x282)
        SCHEMA_FIELD(float                           , m_flTraceLength                                 , 0x284)
        SCHEMA_FIELD(bool                            , m_bPerParticleTR                                , 0x288)
        SCHEMA_FIELD(bool                            , m_bInherit                                      , 0x289)
        SCHEMA_FIELD(std::int32_t                    , m_nChildCP                                      , 0x28C)
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x290)
    };

    class C_OP_RemapAverageHitboxSpeedtoCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nInControlPointNumber                         , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointNumber                        , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nField                                        , 0x1E8)
        SCHEMA_FIELD(ParticleHitboxDataSelection_t   , m_nHitboxDataType                               , 0x1EC)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInputMin                                    , 0x1F0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInputMax                                    , 0x360)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOutputMin                                   , 0x4D0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOutputMax                                   , 0x640)
        SCHEMA_FIELD(std::int32_t                    , m_nHeightControlPointNumber                     , 0x7B0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecComparisonVelocity                         , 0x7B8)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0xE70)
    };

    class FloatInputMaterialVariable_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strVariable                                   , 0x0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flInput                                       , 0x8)
    };

    class C_OP_LockPoints {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nMinCol                                       , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxCol                                       , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nMinRow                                       , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxRow                                       , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x1E8)
        SCHEMA_FIELD(float                           , m_flBlendValue                                  , 0x1EC)
    };

    class C_INIT_SetFloatAttributeToVectorExpression {
    public:
        SCHEMA_FIELD(VectorFloatExpressionType_t     , m_nExpression                                   , 0x1E0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput1                                       , 0x1E8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput2                                       , 0x8A0)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0xF58)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x10C8)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x10CC)
    };

    class CPulseCell_Inflow_ObservableVariableListener {
    public:
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardReference                          , 0x80)
        SCHEMA_FIELD(bool                            , m_bSelfReference                                , 0x82)
    };

    class ParticleAttributeIndex_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Value                                         , 0x0)
    };

    class C_INIT_MoveBetweenPoints {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flSpeedMin                                    , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flSpeedMax                                    , 0x350)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flEndSpread                                   , 0x4C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flStartOffset                                 , 0x630)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flEndOffset                                   , 0x7A0)
        SCHEMA_FIELD(std::int32_t                    , m_nEndControlPointNumber                        , 0x910)
        SCHEMA_FIELD(bool                            , m_bTrailBias                                    , 0x914)
    };

    class C_OP_ConstrainDistance {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_fMinDistance                                  , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_fMaxDistance                                  , 0x348)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x4B8)
        SCHEMA_FIELD(::Vector                        , m_CenterOffset                                  , 0x4BC)
        SCHEMA_FIELD(bool                            , m_bGlobalCenter                                 , 0x4C8)
    };

    class C_OP_CalculateVectorAttribute {
    public:
        SCHEMA_FIELD(::Vector                        , m_vStartValue                                   , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput1                                  , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputScale1                                 , 0x1E8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput2                                  , 0x1EC)
        SCHEMA_FIELD(float                           , m_flInputScale2                                 , 0x1F0)
        SCHEMA_FIELD(ControlPointReference_t         , m_nControlPointInput1                           , 0x1F4)
        SCHEMA_FIELD(float                           , m_flControlPointScale1                          , 0x208)
        SCHEMA_FIELD(ControlPointReference_t         , m_nControlPointInput2                           , 0x20C)
        SCHEMA_FIELD(float                           , m_flControlPointScale2                          , 0x220)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x224)
        SCHEMA_FIELD(::Vector                        , m_vFinalOutputScale                             , 0x228)
    };

    class C_OP_LockToBone {
    public:
        SCHEMA_FIELD(CParticleModelInput             , m_modelInput                                    , 0x1D8)
        SCHEMA_FIELD(CParticleTransformInput         , m_transformInput                                , 0x238)
        SCHEMA_FIELD(float                           , m_flLifeTimeFadeStart                           , 0x2A0)
        SCHEMA_FIELD(float                           , m_flLifeTimeFadeEnd                             , 0x2A4)
        SCHEMA_FIELD(float                           , m_flJumpThreshold                               , 0x2A8)
        SCHEMA_FIELD(float                           , m_flPrevPosScale                                , 0x2AC)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x2B0)
        SCHEMA_FIELD(bool                            , m_bRigid                                        , 0x330)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x331)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x334)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutputPrev                              , 0x338)
        SCHEMA_FIELD(ParticleRotationLockType_t      , m_nRotationSetType                              , 0x33C)
        SCHEMA_FIELD(bool                            , m_bRigidRotationLock                            , 0x340)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecRotation                                   , 0x348)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRotLerp                                     , 0xA00)
    };

    class C_OP_RenderVolumetricEmitter {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strChannelType                                , 0x228)
        SCHEMA_FIELD(ParticleVolumetricSmokeType_t   , m_nType                                         , 0x230)
        SCHEMA_FIELD(ParticleVolumetricSmokeCreationType_t, m_nCreationType                                 , 0x234)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nEventType                                    , 0x238)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPos                                        , 0x240)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecVelocity                                   , 0x8F8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadius                                      , 0xFB0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flDensity                                     , 0x1120)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flTemperature                                 , 0x1290)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMagnitude                                   , 0x1400)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flKillRadius                                  , 0x1570)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flFalloff                                     , 0x16E0)
    };

    class C_INIT_RandomNamedModelMeshGroup {
    public:
    };

    class C_OP_RemapBoundingVolumetoCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointNumber                        , 0x1E0)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1E4)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1EC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F0)
    };

    class C_OP_NormalLock {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
    };

    class C_INIT_RandomColor {
    public:
        SCHEMA_FIELD(::Color                         , m_ColorMin                                      , 0x1FC)
        SCHEMA_FIELD(::Color                         , m_ColorMax                                      , 0x200)
        SCHEMA_FIELD(::Color                         , m_TintMin                                       , 0x204)
        SCHEMA_FIELD(::Color                         , m_TintMax                                       , 0x208)
        SCHEMA_FIELD(float                           , m_flTintPerc                                    , 0x20C)
        SCHEMA_FIELD(float                           , m_flUpdateThreshold                             , 0x210)
        SCHEMA_FIELD(std::int32_t                    , m_nTintCP                                       , 0x214)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x218)
        SCHEMA_FIELD(ParticleColorBlendMode_t        , m_nTintBlendMode                                , 0x21C)
        SCHEMA_FIELD(float                           , m_flLightAmplification                          , 0x220)
    };

    class C_OP_PositionLock {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1D8)
        SCHEMA_FIELD(float                           , m_flStartTime_min                               , 0x240)
        SCHEMA_FIELD(float                           , m_flStartTime_max                               , 0x244)
        SCHEMA_FIELD(float                           , m_flStartTime_exp                               , 0x248)
        SCHEMA_FIELD(float                           , m_flEndTime_min                                 , 0x24C)
        SCHEMA_FIELD(float                           , m_flEndTime_max                                 , 0x250)
        SCHEMA_FIELD(float                           , m_flEndTime_exp                                 , 0x254)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x258)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRangeBias                                   , 0x260)
        SCHEMA_FIELD(float                           , m_flJumpThreshold                               , 0x3D0)
        SCHEMA_FIELD(float                           , m_flPrevPosScale                                , 0x3D4)
        SCHEMA_FIELD(bool                            , m_bLockRot                                      , 0x3D8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecScale                                      , 0x3E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0xA98)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutputPrev                              , 0xA9C)
    };

    class C_OP_RemapModelVolumetoCP {
    public:
        SCHEMA_FIELD(BBoxVolumeType_t                , m_nBBoxType                                     , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nInControlPointNumber                         , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointNumber                        , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutControlPointMaxNumber                     , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nField                                        , 0x1F0)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1F4)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1F8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1FC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x200)
        SCHEMA_FIELD(bool                            , m_bBBoxOnly                                     , 0x204)
        SCHEMA_FIELD(bool                            , m_bCubeRoot                                     , 0x205)
    };

    class C_OP_Orient2DRelToCP {
    public:
        SCHEMA_FIELD(float                           , m_flRotOffset                                   , 0x1D8)
        SCHEMA_FIELD(float                           , m_flSpinStrength                                , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E4)
    };

    class C_OP_EndCapTimedDecay {
    public:
        SCHEMA_FIELD(float                           , m_flDecayTime                                   , 0x1D8)
    };

    class C_INIT_PositionWarp {
    public:
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecWarpMin                                    , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecWarpMax                                    , 0x898)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPointNumber                      , 0xF50)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0xF54)
        SCHEMA_FIELD(std::int32_t                    , m_nRadiusComponent                              , 0xF58)
        SCHEMA_FIELD(float                           , m_flWarpTime                                    , 0xF5C)
        SCHEMA_FIELD(float                           , m_flWarpStartTime                               , 0xF60)
        SCHEMA_FIELD(float                           , m_flPrevPosScale                                , 0xF64)
        SCHEMA_FIELD(bool                            , m_bInvertWarp                                   , 0xF68)
        SCHEMA_FIELD(bool                            , m_bUseCount                                     , 0xF69)
    };

    class C_OP_LerpVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecOutput                                     , 0x1DC)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x1E8)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x1EC)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1F0)
    };

    class C_INIT_QuantizeFloat {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputValue                                    , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x350)
    };

    class C_OP_FadeOutSimple {
    public:
        SCHEMA_FIELD(float                           , m_flFadeOutTime                                 , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
    };

    class C_OP_CurlNoiseForce {
    public:
        SCHEMA_FIELD(ParticleDirectionNoiseType_t    , m_nNoiseType                                    , 0x1E8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecNoiseFreq                                  , 0x1F0)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecNoiseScale                                 , 0x8A8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecOffset                                     , 0xF60)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecOffsetRate                                 , 0x1618)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flWorleySeed                                  , 0x1CD0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flWorleyJitter                                , 0x1E40)
    };

    class C_OP_LerpToOtherAttribute {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInputFrom                               , 0x348)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x34C)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x350)
    };

    class CPulseCell_PickBestOutflowSelector {
    public:
        SCHEMA_FIELD(PulseBestOutflowRules_t         , m_nCheckType                                    , 0x48)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_OutflowList                                   , 0x50)
    };

    class CPulseCell_Timeline_TimelineEvent_t {
    public:
        SCHEMA_FIELD(float                           , m_flTimeFromPrevious                            , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EventOutflow                                  , 0x8)
    };

    class C_INIT_RandomModelSequence {
    public:
        SCHEMA_FIELD(char                            , m_ActivityName                                  , 0x1E0)
        SCHEMA_FIELD(char                            , m_SequenceName                                  , 0x2E0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x3E0)
    };

    class C_INIT_RandomSecondSequence {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSequenceMin                                  , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nSequenceMax                                  , 0x1E4)
    };

    class CParticleFunctionConstraint {
    public:
    };

    class C_OP_ConstrainDistanceToPath {
    public:
        SCHEMA_FIELD(float                           , m_fMinDistance                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flMaxDistance0                                , 0x1DC)
        SCHEMA_FIELD(float                           , m_flMaxDistanceMid                              , 0x1E0)
        SCHEMA_FIELD(float                           , m_flMaxDistance1                                , 0x1E4)
        SCHEMA_FIELD(CPathParameters                 , m_PathParameters                                , 0x1F0)
        SCHEMA_FIELD(float                           , m_flTravelTime                                  , 0x230)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldScale                                   , 0x234)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nManualTField                                 , 0x238)
    };

    class CPulseCell_LimitCount_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bLimitCountPasses                             , 0x0)
    };

    class C_OP_CollideWithSelf {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadiusScale                                 , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMinimumSpeed                                , 0x348)
    };

    class C_OP_RenderClientPhysicsImpulse {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadius                                      , 0x228)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMagnitude                                   , 0x398)
        SCHEMA_FIELD(std::int32_t                    , m_nSimIdFilter                                  , 0x508)
    };

    class C_OP_TwistAroundAxis {
    public:
        SCHEMA_FIELD(float                           , m_fForceAmount                                  , 0x1E8)
        SCHEMA_FIELD(::Vector                        , m_TwistAxis                                     , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bLocalSpace                                   , 0x1F8)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1FC)
    };

    class PulseObservableBoolExpression_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EvaluateConnection                            , 0x0)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeVarIndex_t>, m_DependentObservableVars                       , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeBlackboardReferenceIndex_t>, m_DependentObservableBlackboardReferences       , 0x60)
    };

    class C_INIT_RandomNamedModelElement {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x1E0)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_names                                         , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bShuffle                                      , 0x200)
        SCHEMA_FIELD(bool                            , m_bLinear                                       , 0x201)
        SCHEMA_FIELD(bool                            , m_bModelFromRenderer                            , 0x202)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x204)
    };

    class C_INIT_CreateFromCPs {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nIncrement                                    , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nMinCP                                        , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxCP                                        , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nDynamicCPCount                               , 0x1F0)
    };

    class C_OP_SetChildControlPoints {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstControlPoint                            , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nNumControlPoints                             , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_nFirstSourcePoint                             , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bReverse                                      , 0x358)
        SCHEMA_FIELD(bool                            , m_bSetOrientation                               , 0x359)
        SCHEMA_FIELD(ParticleOrientationType_t       , m_nOrientation                                  , 0x35C)
    };

    class RenderProjectedMaterial_t {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0x0)
    };

    class C_INIT_StatusEffect {
    public:
        SCHEMA_FIELD(Detail2Combo_t                  , m_nDetail2Combo                                 , 0x1E0)
        SCHEMA_FIELD(float                           , m_flDetail2Rotation                             , 0x1E4)
        SCHEMA_FIELD(float                           , m_flDetail2Scale                                , 0x1E8)
        SCHEMA_FIELD(float                           , m_flDetail2BlendFactor                          , 0x1EC)
        SCHEMA_FIELD(float                           , m_flColorWarpIntensity                          , 0x1F0)
        SCHEMA_FIELD(float                           , m_flDiffuseWarpBlendToFull                      , 0x1F4)
        SCHEMA_FIELD(float                           , m_flEnvMapIntensity                             , 0x1F8)
        SCHEMA_FIELD(float                           , m_flAmbientScale                                , 0x1FC)
        SCHEMA_FIELD(::Color                         , m_specularColor                                 , 0x200)
        SCHEMA_FIELD(float                           , m_flSpecularScale                               , 0x204)
        SCHEMA_FIELD(float                           , m_flSpecularExponent                            , 0x208)
        SCHEMA_FIELD(float                           , m_flSpecularExponentBlendToFull                 , 0x20C)
        SCHEMA_FIELD(float                           , m_flSpecularBlendToFull                         , 0x210)
        SCHEMA_FIELD(::Color                         , m_rimLightColor                                 , 0x214)
        SCHEMA_FIELD(float                           , m_flRimLightScale                               , 0x218)
        SCHEMA_FIELD(float                           , m_flReflectionsTintByBaseBlendToNone            , 0x21C)
        SCHEMA_FIELD(float                           , m_flMetalnessBlendToFull                        , 0x220)
        SCHEMA_FIELD(float                           , m_flSelfIllumBlendToFull                        , 0x224)
    };

    class C_OP_ModelDampenMovement {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bBoundBox                                     , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bOutside                                      , 0x1DD)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x1DE)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x1DF)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPosOffset                                  , 0x260)
        SCHEMA_FIELD(float                           , m_fDrag                                         , 0x918)
    };

    class CParticleFunctionRenderer {
    public:
        SCHEMA_FIELD(CParticleVisibilityInputs       , VisibilityInputs                                , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bCannotBeRefracted                            , 0x220)
        SCHEMA_FIELD(bool                            , m_bSkipRenderingOnMobile                        , 0x221)
    };

    class C_INIT_RemapParticleCountToNamedModelElementScalar {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x210)
        SCHEMA_FIELD(::CUtlString                    , m_outputMinName                                 , 0x218)
        SCHEMA_FIELD(::CUtlString                    , m_outputMaxName                                 , 0x220)
        SCHEMA_FIELD(bool                            , m_bModelFromRenderer                            , 0x228)
    };

    class C_OP_SetControlPointToHand {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nHand                                         , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecCP1Pos                                     , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bOrientToHand                                 , 0x1F4)
    };

    class C_OP_ColorInterpolate {
    public:
        SCHEMA_FIELD(::Color                         , m_ColorFade                                     , 0x1D8)
        SCHEMA_FIELD(float                           , m_flFadeStartTime                               , 0x1E8)
        SCHEMA_FIELD(float                           , m_flFadeEndTime                                 , 0x1EC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bEaseInOut                                    , 0x1F4)
    };

    class C_INIT_ChaoticAttractor {
    public:
        SCHEMA_FIELD(float                           , m_flAParm                                       , 0x1E0)
        SCHEMA_FIELD(float                           , m_flBParm                                       , 0x1E4)
        SCHEMA_FIELD(float                           , m_flCParm                                       , 0x1E8)
        SCHEMA_FIELD(float                           , m_flDParm                                       , 0x1EC)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1F0)
        SCHEMA_FIELD(float                           , m_flSpeedMin                                    , 0x1F4)
        SCHEMA_FIELD(float                           , m_flSpeedMax                                    , 0x1F8)
        SCHEMA_FIELD(std::int32_t                    , m_nBaseCP                                       , 0x1FC)
        SCHEMA_FIELD(bool                            , m_bUniformSpeed                                 , 0x200)
    };

    class C_OP_RemapGravityToVector {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vInput1                                       , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x890)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x894)
        SCHEMA_FIELD(bool                            , m_bNormalizedOutput                             , 0x898)
    };

    class C_INIT_InitFloatCollection {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_InputValue                                    , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x350)
    };

    class C_INIT_CheckParticleForWater {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadius                                      , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x350)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flOutputRemap                                 , 0x358)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x4C8)
    };

    class C_OP_ConstrainDistanceToUserSpecifiedPath {
    public:
        SCHEMA_FIELD(float                           , m_fMinDistance                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flMaxDistance                                 , 0x1DC)
        SCHEMA_FIELD(float                           , m_flTimeScale                                   , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bLoopedPath                                   , 0x1E4)
        SCHEMA_FIELD(CUtlVector<PointDefinitionWithTimeValues_t>, m_pointList                                     , 0x1E8)
    };

    class C_OP_TurbulenceForce {
    public:
        SCHEMA_FIELD(float                           , m_flNoiseCoordScale0                            , 0x1E8)
        SCHEMA_FIELD(float                           , m_flNoiseCoordScale1                            , 0x1EC)
        SCHEMA_FIELD(float                           , m_flNoiseCoordScale2                            , 0x1F0)
        SCHEMA_FIELD(float                           , m_flNoiseCoordScale3                            , 0x1F4)
        SCHEMA_FIELD(::Vector                        , m_vecNoiseAmount0                               , 0x1F8)
        SCHEMA_FIELD(::Vector                        , m_vecNoiseAmount1                               , 0x204)
        SCHEMA_FIELD(::Vector                        , m_vecNoiseAmount2                               , 0x210)
        SCHEMA_FIELD(::Vector                        , m_vecNoiseAmount3                               , 0x21C)
    };

    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_TagName                                       , 0x0)
    };

    class C_OP_DensityForce {
    public:
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x1E8)
        SCHEMA_FIELD(float                           , m_flForceScale                                  , 0x1EC)
        SCHEMA_FIELD(float                           , m_flTargetDensity                               , 0x1F0)
    };

    class C_OP_SpringToVectorConstraint {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRestLength                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMinDistance                                 , 0x348)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMaxDistance                                 , 0x4B8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRestingLength                               , 0x628)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecAnchorVector                               , 0x798)
    };

    class C_INIT_InitialSequenceFromModel {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutputAnim                              , 0x1E8)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1EC)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1F0)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1F4)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1F8)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1FC)
    };

    class C_OP_SnapshotRigidSkinToBones {
    public:
        SCHEMA_FIELD(bool                            , m_bTransformNormals                             , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bTransformRadii                               , 0x1D9)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1DC)
    };

    class C_OP_SetControlPointToCenter {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecCP1Pos                                     , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bUseAvgParticlePos                            , 0x1F0)
        SCHEMA_FIELD(ParticleParentSetMode_t         , m_nSetParent                                    , 0x1F4)
    };

    class C_OP_MoveToHitbox {
    public:
        SCHEMA_FIELD(CParticleModelInput             , m_modelInput                                    , 0x1D8)
        SCHEMA_FIELD(CParticleTransformInput         , m_transformInput                                , 0x238)
        SCHEMA_FIELD(float                           , m_flLifeTimeLerpStart                           , 0x2A4)
        SCHEMA_FIELD(float                           , m_flLifeTimeLerpEnd                             , 0x2A8)
        SCHEMA_FIELD(float                           , m_flPrevPosScale                                , 0x2AC)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x2B0)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x330)
        SCHEMA_FIELD(HitboxLerpType_t                , m_nLerpType                                     , 0x334)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x338)
    };

    class C_OP_SetControlPointFieldToWater {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSourceCP                                     , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nDestCP                                       , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nCPField                                      , 0x1E8)
    };

    class C_INIT_AgeNoise {
    public:
        SCHEMA_FIELD(bool                            , m_bAbsVal                                       , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bAbsValInv                                    , 0x1E1)
        SCHEMA_FIELD(float                           , m_flOffset                                      , 0x1E4)
        SCHEMA_FIELD(float                           , m_flAgeMin                                      , 0x1E8)
        SCHEMA_FIELD(float                           , m_flAgeMax                                      , 0x1EC)
        SCHEMA_FIELD(float                           , m_flNoiseScale                                  , 0x1F0)
        SCHEMA_FIELD(float                           , m_flNoiseScaleLoc                               , 0x1F4)
        SCHEMA_FIELD(::Vector                        , m_vecOffsetLoc                                  , 0x1F8)
    };

    class CPulseCell_Outflow_CycleOrdered_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNextIndex                                    , 0x0)
    };

    class C_OP_RemapDistanceToLineSegmentBase {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP0                                          , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1DC)
        SCHEMA_FIELD(float                           , m_flMinInputValue                               , 0x1E0)
        SCHEMA_FIELD(float                           , m_flMaxInputValue                               , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bInfiniteLine                                 , 0x1E8)
    };

    class C_INIT_CreateSequentialPathV2 {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fMaxDistance                                  , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flNumToAssign                                 , 0x350)
        SCHEMA_FIELD(bool                            , m_bLoop                                         , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bCPPairs                                      , 0x4C1)
        SCHEMA_FIELD(bool                            , m_bSaveOffset                                   , 0x4C2)
        SCHEMA_FIELD(CPathParameters                 , m_PathParams                                    , 0x4D0)
    };

    class C_OP_VectorNoise {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMin                                  , 0x1DC)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMax                                  , 0x1E8)
        SCHEMA_FIELD(float                           , m_fl4NoiseScale                                 , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bAdditive                                     , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bOffset                                       , 0x1F9)
        SCHEMA_FIELD(float                           , m_flNoiseAnimationTimeScale                     , 0x1FC)
    };

    class C_OP_RenderCables {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadiusScale                                 , 0x228)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flAlphaScale                                  , 0x398)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorScale                                 , 0x508)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0xBC0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0xBC8)
        SCHEMA_FIELD(TextureRepetitionMode_t         , m_nTextureRepetitionMode                        , 0xBD0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flTextureRepeatsPerSegment                    , 0xBD8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flTextureRepeatsCircumference                 , 0xD48)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flColorMapOffsetV                             , 0xEB8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flColorMapOffsetU                             , 0x1028)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flNormalMapOffsetV                            , 0x1198)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flNormalMapOffsetU                            , 0x1308)
        SCHEMA_FIELD(bool                            , m_bDrawCableCaps                                , 0x1478)
        SCHEMA_FIELD(float                           , m_flCapRoundness                                , 0x147C)
        SCHEMA_FIELD(float                           , m_flCapOffsetAmount                             , 0x1480)
        SCHEMA_FIELD(float                           , m_flTessScale                                   , 0x1484)
        SCHEMA_FIELD(std::int32_t                    , m_nMinTesselation                               , 0x1488)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxTesselation                               , 0x148C)
        SCHEMA_FIELD(std::int32_t                    , m_nRoundness                                    , 0x1490)
        SCHEMA_FIELD(bool                            , m_nForceRoundnessFixed                          , 0x1494)
        SCHEMA_FIELD(CParticleTransformInput         , m_LightingTransform                             , 0x1498)
        SCHEMA_FIELD(CUtlLeanVector<FloatInputMaterialVariable_t>, m_MaterialFloatVars                             , 0x1500)
        SCHEMA_FIELD(CUtlLeanVector<VecInputMaterialVariable_t>, m_MaterialVecVars                               , 0x1520)
    };

    class C_OP_MaintainSequentialPath {
    public:
        SCHEMA_FIELD(float                           , m_fMaxDistance                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flNumToAssign                                 , 0x1DC)
        SCHEMA_FIELD(float                           , m_flCohesionStrength                            , 0x1E0)
        SCHEMA_FIELD(float                           , m_flTolerance                                   , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bLoop                                         , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bUseParticleCount                             , 0x1E9)
        SCHEMA_FIELD(CPathParameters                 , m_PathParams                                    , 0x1F0)
    };

    class CPulseCell_LimitCount_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentCount                                 , 0x0)
    };

    class C_INIT_InitVec {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_InputValue                                    , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x898)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x89C)
        SCHEMA_FIELD(bool                            , m_bNormalizedOutput                             , 0x8A0)
        SCHEMA_FIELD(bool                            , m_bWritePreviousPosition                        , 0x8A1)
    };

    class C_OP_RtEnvCull {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecTestDir                                    , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecTestNormal                                 , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bCullOnMiss                                   , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bStickInsteadOfCull                           , 0x1F1)
        SCHEMA_FIELD(char                            , m_RtEnvName                                     , 0x1F2)
        SCHEMA_FIELD(std::int32_t                    , m_nRTEnvCP                                      , 0x274)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent                                    , 0x278)
    };

    class C_OP_MaxVelocity {
    public:
        SCHEMA_FIELD(float                           , m_flMaxVelocity                                 , 0x1D8)
        SCHEMA_FIELD(float                           , m_flMinVelocity                                 , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nOverrideCP                                   , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nOverrideCPField                              , 0x1E4)
    };

    class C_INIT_InheritFromParentParticles {
    public:
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nIncrement                                    , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bRandomDistribution                           , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0x1F0)
    };

    class C_OP_RemapDirectionToCPToVector {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1E0)
        SCHEMA_FIELD(float                           , m_flOffsetRot                                   , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecOffsetAxis                                 , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bNormalize                                    , 0x1F4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldStrength                                , 0x1F8)
    };

    class C_OP_RenderRopes {
    public:
        SCHEMA_FIELD(bool                            , m_bEnableFadingAndClamping                      , 0x2DF0)
        SCHEMA_FIELD(float                           , m_flMinSize                                     , 0x2DF4)
        SCHEMA_FIELD(float                           , m_flMaxSize                                     , 0x2DF8)
        SCHEMA_FIELD(float                           , m_flStartFadeSize                               , 0x2DFC)
        SCHEMA_FIELD(float                           , m_flEndFadeSize                                 , 0x2E00)
        SCHEMA_FIELD(float                           , m_flStartFadeDot                                , 0x2E04)
        SCHEMA_FIELD(float                           , m_flEndFadeDot                                  , 0x2E08)
        SCHEMA_FIELD(float                           , m_flRadiusTaper                                 , 0x2E0C)
        SCHEMA_FIELD(std::int32_t                    , m_nMinTesselation                               , 0x2E10)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxTesselation                               , 0x2E14)
        SCHEMA_FIELD(float                           , m_flTessScale                                   , 0x2E18)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flTextureVWorldSize                           , 0x2E20)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flTextureVScrollRate                          , 0x2F90)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flTextureVOffset                              , 0x3100)
        SCHEMA_FIELD(std::int32_t                    , m_nTextureVParamsCP                             , 0x3270)
        SCHEMA_FIELD(bool                            , m_bClampV                                       , 0x3274)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleCP1                                     , 0x3278)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleCP2                                     , 0x327C)
        SCHEMA_FIELD(float                           , m_flScaleVSizeByControlPointDistance            , 0x3280)
        SCHEMA_FIELD(float                           , m_flScaleVScrollByControlPointDistance          , 0x3284)
        SCHEMA_FIELD(float                           , m_flScaleVOffsetByControlPointDistance          , 0x3288)
        SCHEMA_FIELD(bool                            , m_bUseScalarForTextureCoordinate                , 0x328D)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nScalarFieldForTextureCoordinate              , 0x3290)
        SCHEMA_FIELD(float                           , m_flScalarAttributeTextureCoordScale            , 0x3294)
        SCHEMA_FIELD(bool                            , m_bReverseOrder                                 , 0x3298)
        SCHEMA_FIELD(bool                            , m_bClosedLoop                                   , 0x3299)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nSplitField                                   , 0x329C)
        SCHEMA_FIELD(bool                            , m_bSortBySegmentID                              , 0x32A0)
        SCHEMA_FIELD(ParticleOrientationChoiceList_t , m_nOrientationType                              , 0x32A4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nVectorFieldForOrientation                    , 0x32A8)
        SCHEMA_FIELD(bool                            , m_bDrawAsOpaque                                 , 0x32AC)
        SCHEMA_FIELD(bool                            , m_bGenerateNormals                              , 0x32AD)
    };

    class C_INIT_CreateAlongPath {
    public:
        SCHEMA_FIELD(float                           , m_fMaxDistance                                  , 0x1E0)
        SCHEMA_FIELD(CPathParameters                 , m_PathParams                                    , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bUseRandomCPs                                 , 0x230)
        SCHEMA_FIELD(::Vector                        , m_vEndOffset                                    , 0x234)
        SCHEMA_FIELD(bool                            , m_bSaveOffset                                   , 0x240)
    };

    class CBasePulseGraphInstance {
    public:
    };

    class C_INIT_RandomNamedModelSequence {
    public:
    };

    class C_INIT_InitFromParentKilled {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttributeToCopy                              , 0x1E0)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nEventType                                    , 0x1E4)
    };

    class C_OP_GlobalLight {
    public:
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bClampLowerRange                              , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bClampUpperRange                              , 0x1DD)
    };

    class ControlPointReference_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_controlPointNameString                        , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vOffsetFromControlPoint                       , 0x4)
        SCHEMA_FIELD(bool                            , m_bOffsetInLocalSpace                           , 0x10)
    };

    class C_OP_CylindricalDistanceToTransform {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMin                                    , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMax                                    , 0x350)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMin                                   , 0x4C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMax                                   , 0x630)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformStart                                , 0x7A0)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformEnd                                  , 0x808)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x870)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x874)
        SCHEMA_FIELD(bool                            , m_bAdditive                                     , 0x875)
        SCHEMA_FIELD(bool                            , m_bCapsule                                      , 0x876)
    };

    class C_OP_Decay {
    public:
        SCHEMA_FIELD(bool                            , m_bRopeDecay                                    , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bForcePreserveParticleOrder                   , 0x1D9)
    };

    class C_OP_RemapTransformOrientationToYaw {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x240)
        SCHEMA_FIELD(float                           , m_flRotOffset                                   , 0x244)
        SCHEMA_FIELD(float                           , m_flSpinStrength                                , 0x248)
    };

    class C_OP_VelocityMatchingForce {
    public:
        SCHEMA_FIELD(float                           , m_flDirScale                                    , 0x1D8)
        SCHEMA_FIELD(float                           , m_flSpdScale                                    , 0x1DC)
        SCHEMA_FIELD(float                           , m_flNeighborDistance                            , 0x1E0)
        SCHEMA_FIELD(float                           , m_flFacingStrength                              , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bUseAABB                                      , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nCPBroadcast                                  , 0x1EC)
    };

    class C_INIT_RingWave {
    public:
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformInput                                , 0x1E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flParticlesPerOrbit                           , 0x248)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInitialRadius                               , 0x3B8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flThickness                                   , 0x528)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInitialSpeedMin                             , 0x698)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInitialSpeedMax                             , 0x808)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRoll                                        , 0x978)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flPitch                                       , 0xAE8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flYaw                                         , 0xC58)
        SCHEMA_FIELD(bool                            , m_bEvenDistribution                             , 0xDC8)
        SCHEMA_FIELD(bool                            , m_bXYVelocityOnly                               , 0xDC9)
    };

    class C_OP_MovementMoveAlongSkinnedCPSnapshot {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(std::int32_t                    , m_nSnapshotControlPointNumber                   , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bSetNormal                                    , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bSetRadius                                    , 0x1E1)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x1E8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flTValue                                      , 0x358)
    };

    class C_OP_DistanceToTransform {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMin                                    , 0x1E0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInputMax                                    , 0x350)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMin                                   , 0x4C0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flOutputMax                                   , 0x630)
        SCHEMA_FIELD(CParticleTransformInput         , m_TransformStart                                , 0x7A0)
        SCHEMA_FIELD(bool                            , m_bLOS                                          , 0x808)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x809)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x88C)
        SCHEMA_FIELD(float                           , m_flMaxTraceLength                              , 0x890)
        SCHEMA_FIELD(float                           , m_flLOSScale                                    , 0x894)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x898)
        SCHEMA_FIELD(bool                            , m_bActiveRange                                  , 0x89C)
        SCHEMA_FIELD(bool                            , m_bAdditive                                     , 0x89D)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecComponentScale                             , 0x8A0)
    };

    class C_INIT_PositionWarpScalar {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecWarpMin                                    , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecWarpMax                                    , 0x1EC)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_InputValue                                    , 0x1F8)
        SCHEMA_FIELD(float                           , m_flPrevPosScale                                , 0x368)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleControlPointNumber                      , 0x36C)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x370)
    };

    class CPulse_ResumePoint {
    public:
    };

    class C_OP_SetControlPointPositionToRandomActiveCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP1                                          , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nHeadLocationMin                              , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nHeadLocationMax                              , 0x1E8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flResetRate                                   , 0x1F0)
    };

    class C_OP_PlanarConstraint {
    public:
        SCHEMA_FIELD(::Vector                        , m_PointOnPlane                                  , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_PlaneNormal                                   , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1F0)
        SCHEMA_FIELD(bool                            , m_bGlobalOrigin                                 , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bGlobalNormal                                 , 0x1F5)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadiusScale                                 , 0x1F8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flMaximumDistanceToCP                         , 0x368)
        SCHEMA_FIELD(bool                            , m_bUseOldCode                                   , 0x4D8)
    };

    class IParticleCollection {
    public:
    };

    class C_OP_LockToSavedSequentialPathV2 {
    public:
        SCHEMA_FIELD(float                           , m_flFadeStart                                   , 0x1D8)
        SCHEMA_FIELD(float                           , m_flFadeEnd                                     , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bCPPairs                                      , 0x1E0)
        SCHEMA_FIELD(CPathParameters                 , m_PathParams                                    , 0x1F0)
    };

    class C_OP_Diffusion {
    public:
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nVoxelGridResolution                          , 0x1E0)
    };

    class C_OP_RemapNamedModelSequenceEndCap {
    public:
    };

    class C_INIT_CreatePhyllotaxis {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleCP                                      , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent                                    , 0x1E8)
        SCHEMA_FIELD(float                           , m_fRadCentCore                                  , 0x1EC)
        SCHEMA_FIELD(float                           , m_fRadPerPoint                                  , 0x1F0)
        SCHEMA_FIELD(float                           , m_fRadPerPointTo                                , 0x1F4)
        SCHEMA_FIELD(float                           , m_fpointAngle                                   , 0x1F8)
        SCHEMA_FIELD(float                           , m_fsizeOverall                                  , 0x1FC)
        SCHEMA_FIELD(float                           , m_fRadBias                                      , 0x200)
        SCHEMA_FIELD(float                           , m_fMinRad                                       , 0x204)
        SCHEMA_FIELD(float                           , m_fDistBias                                     , 0x208)
        SCHEMA_FIELD(bool                            , m_bUseLocalCoords                               , 0x20C)
        SCHEMA_FIELD(bool                            , m_bUseWithContEmit                              , 0x20D)
        SCHEMA_FIELD(bool                            , m_bUseOrigRadius                                , 0x20E)
    };

    class C_OP_SetCPOrientationToGroundNormal {
    public:
        SCHEMA_FIELD(float                           , m_flInterpRate                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flMaxTraceLength                              , 0x1DC)
        SCHEMA_FIELD(float                           , m_flTolerance                                   , 0x1E0)
        SCHEMA_FIELD(float                           , m_flTraceOffset                                 , 0x1E4)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x1E8)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x268)
        SCHEMA_FIELD(std::int32_t                    , m_nInputCP                                      , 0x26C)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x270)
        SCHEMA_FIELD(bool                            , m_bIncludeWater                                 , 0x280)
    };

    class C_INIT_RemapParticleCountToNamedModelMeshGroupScalar {
    public:
    };

    class C_OP_RemapNamedModelMeshGroupEndCap {
    public:
    };

    class C_OP_ControlPointToRadialScreenSpace {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCPIn                                         , 0x1E0)
        SCHEMA_FIELD(::Vector                        , m_vecCP1Pos                                     , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOut                                        , 0x1F0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPOutField                                   , 0x1F4)
        SCHEMA_FIELD(std::int32_t                    , m_nCPSSPosOut                                   , 0x1F8)
    };

    class C_INIT_RandomYaw {
    public:
    };

    class C_OP_DecayOffscreen {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flOffscreenTime                               , 0x1D8)
    };

    class C_OP_WorldTraceConstraint {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecCpOffset                                   , 0x1DC)
        SCHEMA_FIELD(ParticleCollisionMode_t         , m_nCollisionMode                                , 0x1E8)
        SCHEMA_FIELD(ParticleCollisionMode_t         , m_nCollisionModeMin                             , 0x1EC)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x1F0)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bWorldOnly                                    , 0x274)
        SCHEMA_FIELD(bool                            , m_bBrushOnly                                    , 0x275)
        SCHEMA_FIELD(bool                            , m_bIncludeWater                                 , 0x276)
        SCHEMA_FIELD(std::int32_t                    , m_nIgnoreCP                                     , 0x278)
        SCHEMA_FIELD(float                           , m_flCpMovementTolerance                         , 0x27C)
        SCHEMA_FIELD(float                           , m_flRetestRate                                  , 0x280)
        SCHEMA_FIELD(float                           , m_flTraceTolerance                              , 0x284)
        SCHEMA_FIELD(float                           , m_flCollisionConfirmationSpeed                  , 0x288)
        SCHEMA_FIELD(float                           , m_nMaxTracesPerFrame                            , 0x28C)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRadiusScale                                 , 0x290)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flBounceAmount                                , 0x400)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flSlideAmount                                 , 0x570)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRandomDirScale                              , 0x6E0)
        SCHEMA_FIELD(bool                            , m_bDecayBounce                                  , 0x850)
        SCHEMA_FIELD(bool                            , m_bKillonContact                                , 0x851)
        SCHEMA_FIELD(float                           , m_flMinSpeed                                    , 0x854)
        SCHEMA_FIELD(bool                            , m_bSetNormal                                    , 0x858)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nStickOnCollisionField                        , 0x85C)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flStopSpeed                                   , 0x860)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nEntityStickDataField                         , 0x9D0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nEntityStickNormalField                       , 0x9D4)
    };

    class C_OP_DampenToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x1DC)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x1E0)
    };

    class C_OP_OscillateScalarSimple {
    public:
        SCHEMA_FIELD(float                           , m_Rate                                          , 0x1D8)
        SCHEMA_FIELD(float                           , m_Frequency                                     , 0x1DC)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nField                                        , 0x1E0)
        SCHEMA_FIELD(float                           , m_flOscMult                                     , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOscAdd                                      , 0x1E8)
    };

    class C_OP_RestartAfterDuration {
    public:
        SCHEMA_FIELD(float                           , m_flDurationMin                                 , 0x1D8)
        SCHEMA_FIELD(float                           , m_flDurationMax                                 , 0x1DC)
        SCHEMA_FIELD(std::int32_t                    , m_nCP                                           , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCPField                                      , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nChildGroupID                                 , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bOnlyChildren                                 , 0x1EC)
    };

    class PulseNodeDynamicOutflows_t {
    public:
        SCHEMA_FIELD(CUtlVector<PulseNodeDynamicOutflows_t_DynamicOutflow_t>, m_Outflows                                      , 0x0)
    };

    class C_OP_SetVariable {
    public:
        SCHEMA_FIELD(CParticleVariableRef            , m_variableReference                             , 0x1E0)
        SCHEMA_FIELD(CParticleTransformInput         , m_transformInput                                , 0x230)
        SCHEMA_FIELD(::Vector                        , m_positionOffset                                , 0x298)
        SCHEMA_FIELD(::QAngle                        , m_rotationOffset                                , 0x2A4)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecInput                                      , 0x2B0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_floatInput                                    , 0x968)
    };

    class C_INIT_RemapNamedModelSequenceToScalar {
    public:
    };

    class C_OP_RenderFlattenGrass {
    public:
        SCHEMA_FIELD(float                           , m_flFlattenStrength                             , 0x228)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nStrengthFieldOverride                        , 0x22C)
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x230)
    };

    class CPulseCell_WaitForCursorsWithTagBase {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToWait                         , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WaitComplete                                  , 0x50)
    };

    class C_OP_LockToSavedSequentialPath {
    public:
        SCHEMA_FIELD(float                           , m_flFadeStart                                   , 0x1DC)
        SCHEMA_FIELD(float                           , m_flFadeEnd                                     , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bCPPairs                                      , 0x1E4)
        SCHEMA_FIELD(CPathParameters                 , m_PathParams                                    , 0x1F0)
    };

    class MaterialVariable_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strVariable                                   , 0x0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nVariableField                                , 0x8)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0xC)
    };

    class CPulseCell_WaitForObservable {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnTrue                                        , 0xC0)
    };

    class C_INIT_VelocityRadialRandom {
    public:
        SCHEMA_FIELD(bool                            , m_bPerParticleCenter                            , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E4)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecPosition                                   , 0x1E8)
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecFwd                                        , 0x8A0)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMin                                     , 0xF58)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fSpeedMax                                     , 0x10C8)
        SCHEMA_FIELD(::Vector                        , m_vecLocalCoordinateSystemSpeedScale            , 0x1238)
        SCHEMA_FIELD(bool                            , m_bIgnoreDelta                                  , 0x1245)
    };

    class C_OP_ModelCull {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1D8)
        SCHEMA_FIELD(bool                            , m_bBoundBox                                     , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bCullOutside                                  , 0x1DD)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x1DE)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x1DF)
    };

    class C_OP_RenderSimpleModelCollection {
    public:
        SCHEMA_FIELD(bool                            , m_bCenterOffset                                 , 0x228)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x230)
        SCHEMA_FIELD(CParticleModelInput             , m_modelInput                                    , 0x238)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_fSizeCullScale                                , 0x298)
        SCHEMA_FIELD(bool                            , m_bDisableShadows                               , 0x408)
        SCHEMA_FIELD(bool                            , m_bDisableMotionBlur                            , 0x409)
        SCHEMA_FIELD(bool                            , m_bAcceptsDecals                                , 0x40A)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_fDrawFilter                                   , 0x410)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAngularVelocityField                         , 0x580)
    };

    class C_INIT_OffsetVectorToVector {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x1E0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E4)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMin                                  , 0x1E8)
        SCHEMA_FIELD(::Vector                        , m_vecOutputMax                                  , 0x1F4)
        SCHEMA_FIELD(CRandomNumberGeneratorParameters, m_randomnessParameters                          , 0x200)
    };

    class CBaseRendererSource2 {
    public:
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flRadiusScale                                 , 0x228)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flAlphaScale                                  , 0x398)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flRollScale                                   , 0x508)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAlpha2Field                                  , 0x678)
        SCHEMA_FIELD(CParticleCollectionRendererVecInput, m_vecColorScale                                 , 0x680)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0xD38)
        SCHEMA_FIELD(SpriteCardShaderType_t          , m_nShaderType                                   , 0xD3C)
        SCHEMA_FIELD(::CUtlString                    , m_strShaderOverride                             , 0xD40)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flCenterXOffset                               , 0xD48)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flCenterYOffset                               , 0xEB8)
        SCHEMA_FIELD(float                           , m_flBumpStrength                                , 0x1028)
        SCHEMA_FIELD(ParticleSequenceCropOverride_t  , m_nCropTextureOverride                          , 0x102C)
        SCHEMA_FIELD(CUtlLeanVector<TextureGroup_t>  , m_vecTexturesInput                              , 0x1030)
        SCHEMA_FIELD(float                           , m_flAnimationRate                               , 0x1040)
        SCHEMA_FIELD(AnimationType_t                 , m_nAnimationType                                , 0x1044)
        SCHEMA_FIELD(bool                            , m_bAnimateInFPS                                 , 0x1048)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flMotionVectorScaleU                          , 0x1050)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flMotionVectorScaleV                          , 0x11C0)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flSelfIllumAmount                             , 0x1330)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flDiffuseAmount                               , 0x14A0)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flDiffuseClamp                                , 0x1610)
        SCHEMA_FIELD(std::int32_t                    , m_nLightingControlPoint                         , 0x1780)
        SCHEMA_FIELD(ParticleOutputBlendMode_t       , m_nOutputBlendMode                              , 0x1784)
        SCHEMA_FIELD(bool                            , m_bGammaCorrectVertexColors                     , 0x1788)
        SCHEMA_FIELD(bool                            , m_bSaturateColorPreAlphaBlend                   , 0x1789)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flAddSelfAmount                               , 0x1790)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flDesaturation                                , 0x1900)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flOverbrightFactor                            , 0x1A70)
        SCHEMA_FIELD(std::int32_t                    , m_nHSVShiftControlPoint                         , 0x1BE0)
        SCHEMA_FIELD(ParticleFogType_t               , m_nFogType                                      , 0x1BE4)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFogAmount                                   , 0x1BE8)
        SCHEMA_FIELD(bool                            , m_bTintByFOW                                    , 0x1D58)
        SCHEMA_FIELD(bool                            , m_bTintByGlobalLight                            , 0x1D59)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleAlphaReference                    , 0x1D5C)
        SCHEMA_FIELD(SpriteCardPerParticleScale_t    , m_nPerParticleAlphaRefWindow                    , 0x1D60)
        SCHEMA_FIELD(ParticleAlphaReferenceType_t    , m_nAlphaReferenceType                           , 0x1D64)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flAlphaReferenceSoftness                      , 0x1D68)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flSourceAlphaValueToMapToZero                 , 0x1ED8)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flSourceAlphaValueToMapToOne                  , 0x2048)
        SCHEMA_FIELD(bool                            , m_bRefract                                      , 0x21B8)
        SCHEMA_FIELD(bool                            , m_bRefractSolid                                 , 0x21B9)
        SCHEMA_FIELD(bool                            , m_bRefract2Passes                               , 0x21BA)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flRefractAmount                               , 0x21C0)
        SCHEMA_FIELD(std::int32_t                    , m_nRefractBlurRadius                            , 0x2330)
        SCHEMA_FIELD(BlurFilterType_t                , m_nRefractBlurType                              , 0x2334)
        SCHEMA_FIELD(bool                            , m_bOnlyRenderInEffectsBloomPass                 , 0x2338)
        SCHEMA_FIELD(bool                            , m_bOnlyRenderInEffectsWaterPass                 , 0x2339)
        SCHEMA_FIELD(bool                            , m_bUseMixedResolutionRendering                  , 0x233A)
        SCHEMA_FIELD(bool                            , m_bOnlyRenderInEffecsGameOverlay                , 0x233B)
        SCHEMA_FIELD(char                            , m_stencilTestID                                 , 0x233C)
        SCHEMA_FIELD(bool                            , m_bStencilTestExclude                           , 0x23BC)
        SCHEMA_FIELD(char                            , m_stencilWriteID                                , 0x23BD)
        SCHEMA_FIELD(bool                            , m_bWriteStencilOnDepthPass                      , 0x243D)
        SCHEMA_FIELD(bool                            , m_bWriteStencilOnDepthFail                      , 0x243E)
        SCHEMA_FIELD(bool                            , m_bReverseZBuffering                            , 0x243F)
        SCHEMA_FIELD(bool                            , m_bDisableZBuffering                            , 0x2440)
        SCHEMA_FIELD(ParticleDepthFeatheringMode_t   , m_nFeatheringMode                               , 0x2444)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFeatheringMinDist                           , 0x2448)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFeatheringMaxDist                           , 0x25B8)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFeatheringFilter                            , 0x2728)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flFeatheringDepthMapFilter                    , 0x2898)
        SCHEMA_FIELD(CParticleCollectionRendererFloatInput, m_flDepthBias                                   , 0x2A08)
        SCHEMA_FIELD(ParticleSortingChoiceList_t     , m_nSortMethod                                   , 0x2B78)
        SCHEMA_FIELD(bool                            , m_bBlendFramesSeq0                              , 0x2B7C)
        SCHEMA_FIELD(bool                            , m_bMaxLuminanceBlendingSequence0                , 0x2B7D)
    };

    class C_OP_DragRelativeToPlane {
    public:
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDragAtPlane                                 , 0x1D8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flFalloff                                     , 0x348)
        SCHEMA_FIELD(bool                            , m_bDirectional                                  , 0x4B8)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecPlaneNormal                                , 0x4C0)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0xB78)
    };

    class C_INIT_RandomVectorComponent {
    public:
        SCHEMA_FIELD(float                           , m_flMin                                         , 0x1E0)
        SCHEMA_FIELD(float                           , m_flMax                                         , 0x1E4)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nComponent                                    , 0x1EC)
    };

    class CPathParameters {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nStartControlPointNumber                      , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nEndControlPointNumber                        , 0x4)
        SCHEMA_FIELD(std::int32_t                    , m_nBulgeControl                                 , 0x8)
        SCHEMA_FIELD(float                           , m_flBulge                                       , 0xC)
        SCHEMA_FIELD(float                           , m_flMidPoint                                    , 0x10)
        SCHEMA_FIELD(::Vector                        , m_vStartPointOffset                             , 0x14)
        SCHEMA_FIELD(::Vector                        , m_vMidPointOffset                               , 0x20)
        SCHEMA_FIELD(::Vector                        , m_vEndOffset                                    , 0x2C)
    };

    class C_INIT_PositionOffsetToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumberStart                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumberEnd                        , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bLocalCoords                                  , 0x1E8)
    };

    class C_OP_SetUserEvent {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInput                                       , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flRisingEdge                                  , 0x348)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nRisingEventType                              , 0x4B8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flFallingEdge                                 , 0x4C0)
        SCHEMA_FIELD(EventTypeSelection_t            , m_nFallingEventType                             , 0x630)
    };

    class CPulseMathlib {
    public:
    };

    class C_OP_CPOffsetToPercentageBetweenCPs {
    public:
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1D8)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputBias                                   , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nStartCP                                      , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nEndCP                                        , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nOffsetCP                                     , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_nOuputCP                                      , 0x1F0)
        SCHEMA_FIELD(std::int32_t                    , m_nInputCP                                      , 0x1F4)
        SCHEMA_FIELD(bool                            , m_bRadialCheck                                  , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bScaleOffset                                  , 0x1F9)
        SCHEMA_FIELD(::Vector                        , m_vecOffset                                     , 0x1FC)
    };

    class OutflowWithRequirements_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x0)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_DestinationFlowNodeID                         , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseDocNodeID_t>    , m_RequirementNodeIDs                            , 0x50)
        SCHEMA_FIELD(CUtlVector<int32>               , m_nCursorStateBlockIndex                        , 0x68)
    };

    class C_OP_SetVec {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_InputValue                                    , 0x1D8)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nOutputField                                  , 0x890)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x894)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_Lerp                                          , 0x898)
        SCHEMA_FIELD(bool                            , m_bNormalizedOutput                             , 0xA08)
    };

    class C_OP_RenderProjected {
    public:
        SCHEMA_FIELD(bool                            , m_bProjectCharacter                             , 0x228)
        SCHEMA_FIELD(bool                            , m_bProjectWorld                                 , 0x229)
        SCHEMA_FIELD(bool                            , m_bProjectWater                                 , 0x22A)
        SCHEMA_FIELD(bool                            , m_bFlipHorizontal                               , 0x22B)
        SCHEMA_FIELD(bool                            , m_bEnableProjectedDepthControls                 , 0x22C)
        SCHEMA_FIELD(float                           , m_flMinProjectionDepth                          , 0x230)
        SCHEMA_FIELD(float                           , m_flMaxProjectionDepth                          , 0x234)
        SCHEMA_FIELD(CUtlVector<RenderProjectedMaterial_t>, m_vecProjectedMaterials                         , 0x238)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flMaterialSelection                           , 0x250)
        SCHEMA_FIELD(float                           , m_flAnimationTimeScale                          , 0x3C0)
        SCHEMA_FIELD(bool                            , m_bOrientToNormal                               , 0x3C4)
        SCHEMA_FIELD(CUtlVector<MaterialVariable_t>  , m_MaterialVars                                  , 0x3C8)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRadiusScale                                 , 0x3E0)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flAlphaScale                                  , 0x550)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flRollScale                                   , 0x6C0)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAlpha2Field                                  , 0x830)
        SCHEMA_FIELD(CParticleCollectionVecInput     , m_vecColorScale                                 , 0x838)
        SCHEMA_FIELD(ParticleColorBlendType_t        , m_nColorBlendType                               , 0xEF0)
    };

    class C_OP_FadeOut {
    public:
        SCHEMA_FIELD(float                           , m_flFadeOutTimeMin                              , 0x1D8)
        SCHEMA_FIELD(float                           , m_flFadeOutTimeMax                              , 0x1DC)
        SCHEMA_FIELD(float                           , m_flFadeOutTimeExp                              , 0x1E0)
        SCHEMA_FIELD(float                           , m_flFadeBias                                    , 0x1E4)
        SCHEMA_FIELD(bool                            , m_bProportional                                 , 0x220)
        SCHEMA_FIELD(bool                            , m_bEaseInAndOut                                 , 0x221)
    };

    class C_OP_RadiusDecay {
    public:
        SCHEMA_FIELD(float                           , m_flMinRadius                                   , 0x1D8)
    };

    class C_INIT_RandomAlpha {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nAlphaMin                                     , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nAlphaMax                                     , 0x1E8)
        SCHEMA_FIELD(float                           , m_flAlphaRandExponent                           , 0x1F4)
    };

    class C_INIT_RemapNamedModelElementToScalar {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x1E0)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_names                                         , 0x1E8)
        SCHEMA_FIELD(CUtlVector<float32>             , m_values                                        , 0x200)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldInput                                   , 0x218)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x21C)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x220)
        SCHEMA_FIELD(bool                            , m_bModelFromRenderer                            , 0x224)
    };

    class ModelReference_t {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_model                                         , 0x0)
        SCHEMA_FIELD(float                           , m_flRelativeProbabilityOfSpawn                  , 0x8)
    };

    class C_OP_UpdateLightSource {
    public:
        SCHEMA_FIELD(::Color                         , m_vColorTint                                    , 0x1D8)
        SCHEMA_FIELD(float                           , m_flBrightnessScale                             , 0x1DC)
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x1E0)
        SCHEMA_FIELD(float                           , m_flMinimumLightingRadius                       , 0x1E4)
        SCHEMA_FIELD(float                           , m_flMaximumLightingRadius                       , 0x1E8)
        SCHEMA_FIELD(float                           , m_flPositionDampingConstant                     , 0x1EC)
    };

    class C_INIT_DistanceToNeighborCull {
    public:
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flDistance                                    , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bIncludeRadii                                 , 0x350)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flLifespanOverlap                             , 0x358)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldModify                                  , 0x4C8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flModify                                      , 0x4D0)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x640)
        SCHEMA_FIELD(bool                            , m_bUseNeighbor                                  , 0x644)
    };

    class C_OP_PointVectorAtNextParticle {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(CPerParticleFloatInput          , m_flInterpolation                               , 0x1E0)
    };

    class CPulseCell_Value_RandomFloat {
    public:
    };

    class CRandomNumberGeneratorParameters {
    public:
        SCHEMA_FIELD(bool                            , m_bDistributeEvenly                             , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nSeed                                         , 0x4)
    };

    class C_OP_DistanceCull {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nControlPoint                                 , 0x1D8)
        SCHEMA_FIELD(::Vector                        , m_vecPointOffset                                , 0x1DC)
        SCHEMA_FIELD(CParticleCollectionFloatInput   , m_flDistance                                    , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bCullInside                                   , 0x358)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nAttribute                                    , 0x35C)
    };

    class C_OP_DistanceBetweenCPsToCP {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nStartCP                                      , 0x1E0)
        SCHEMA_FIELD(std::int32_t                    , m_nEndCP                                        , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCP                                     , 0x1E8)
        SCHEMA_FIELD(std::int32_t                    , m_nOutputCPField                                , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bSetOnce                                      , 0x1F0)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1F4)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1F8)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1FC)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x200)
        SCHEMA_FIELD(float                           , m_flMaxTraceLength                              , 0x204)
        SCHEMA_FIELD(float                           , m_flLOSScale                                    , 0x208)
        SCHEMA_FIELD(bool                            , m_bLOS                                          , 0x20C)
        SCHEMA_FIELD(char                            , m_CollisionGroupName                            , 0x20D)
        SCHEMA_FIELD(ParticleTraceSet_t              , m_nTraceSet                                     , 0x290)
        SCHEMA_FIELD(ParticleParentSetMode_t         , m_nSetParent                                    , 0x294)
    };

    class C_INIT_ScreenSpacePositionOfTarget {
    public:
        SCHEMA_FIELD(CPerParticleVecInput            , m_vecTargetPosition                             , 0x1E0)
        SCHEMA_FIELD(bool                            , m_bOututBehindness                              , 0x898)
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nBehindFieldOutput                            , 0x89C)
        SCHEMA_FIELD(CParticleRemapFloatInput        , m_flBehindOutputRemap                           , 0x8A0)
    };

    class C_INIT_InitialVelocityFromHitbox {
    public:
        SCHEMA_FIELD(float                           , m_flVelocityMin                                 , 0x1E0)
        SCHEMA_FIELD(float                           , m_flVelocityMax                                 , 0x1E4)
        SCHEMA_FIELD(std::int32_t                    , m_nControlPointNumber                           , 0x1E8)
        SCHEMA_FIELD(char                            , m_HitboxSetName                                 , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bUseBones                                     , 0x26C)
    };

    class CPulseCell_Timeline {
    public:
        SCHEMA_FIELD(CUtlVector<CPulseCell_Timeline_TimelineEvent_t>, m_TimelineEvents                                , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class C_OP_RemapSpeed {
    public:
        SCHEMA_FIELD(ParticleAttributeIndex_t        , m_nFieldOutput                                  , 0x1D8)
        SCHEMA_FIELD(float                           , m_flInputMin                                    , 0x1DC)
        SCHEMA_FIELD(float                           , m_flInputMax                                    , 0x1E0)
        SCHEMA_FIELD(float                           , m_flOutputMin                                   , 0x1E4)
        SCHEMA_FIELD(float                           , m_flOutputMax                                   , 0x1E8)
        SCHEMA_FIELD(ParticleSetMethod_t             , m_nSetMethod                                    , 0x1EC)
        SCHEMA_FIELD(bool                            , m_bIgnoreDelta                                  , 0x1F0)
    };

    class SequenceWeightedList_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSequence                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flRelativeWeight                              , 0x4)
    };

    class CPulseCell_BaseRequirement {
    public:
    };

}
