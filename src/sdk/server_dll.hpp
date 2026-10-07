

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::server {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class CWeaponNOVA;
    class CPointWorldText;
    class CAmbientGeneric;
    class CEnvEntityMaker;
    class CPulseGraphInstance_GameBlackboard;
    class CPointEntity;
    class CFilterEnemy;
    class CCSGO_WingmanIntroCounterTerroristPosition;
    class CPulseCell_WaitForCursorsWithTag;
    class CFuncTrackAuto;
    class CScriptedSequence;
    class CFogTrigger;
    class CInfoTeleportDestination;
    class CPointBroadcastClientCommand;
    class CCSPlayer_PingServices;
    class CHEGrenade;
    class CPhysicsSpring;
    class CEnvMuzzleFlash;
    class CEconItemAttribute;
    class CBaseTriggerAPI;
    class CWeaponRevolver;
    class CFuncTrainControls;
    class CBtActionCombatPositioning;
    class CFuncRetakeBarrier;
    class CTriggerBuoyancy;
    class CTonemapController2Alias_env_tonemap_controller2;
    class CPathTrack;
    class CCSGO_EndOfMatchLineupEndpoint;
    class CPulseCell_Base;
    class CTriggerProximity;
    class CTankTrainAI;
    class CGameText;
    class CGameEnd;
    class CInfoDeathmatchSpawn;
    class CCSPlayerController_InventoryServices;
    class CCSPlayerModernJump;
    class CPulse_ResumePoint;
    class CTriggerFan;
    class CPhysHingeAlias_phys_hinge_local;
    class CLogicCase;
    class CPulseCell_Outflow_PlayVOLine;
    class CInfoGameEventProxy;
    class CTestPulseIOComponent_DerivedAPI;
    class CWeaponBizon;
    class CGamePlayerZone;
    class CBaseToggle;
    class CPulseServerCursor;
    class CPulseCell_PlaySequence;
    class CInferno;
    class CTouchExpansionComponent;
    class CPulseCell_Outflow_PlaySceneBase;
    class CPulseCell_LerpCameraSettings;
    class CWeaponSCAR20;
    class CFuncInteractionLayerClip;
    class CCSObserver_UseServices;
    class CTriggerDetectBulletFire;
    class CCSPlayer_UseServices;
    class CWeaponAWP;
    class CPulseCell_PickBestOutflowSelector;
    class CInfoFan;
    class CGameRules;
    class CFish;
    class CCSBot;
    class CHandleTest;
    class CLogicNPCCounter;
    class CCSPlayer_RadioServices;
    class CWeaponSG556;
    class CRagdollConstraint;
    class CFuncVehicleClip;
    class CDEagle;
    class CWeaponFamas;
    class CEnvSplash;
    class CPointCameraVFOV;
    class CCSGO_WingmanIntroTerroristPosition;
    class CTestPulseIOAPI;
    class CCSWeaponBaseShotgun;
    class CPrecipitationVData;
    class CFuncMoveLinear;
    class CPhysMotorAPI;
    class CPulseCell_WaitForObservable;
    class CScriptItem;
    class CDynamicPropAlias_prop_dynamic_override;
    class CBaseTrigger;
    class CPointPush;
    class CPulseCell_Step_EntFire;
    class CCSObserver_ObserverServices;
    class CPlayerPing;
    class CHitboxComponent;
    class CRopeKeyframe;
    class CSmokeGrenade;
    class CBaseCombatCharacter;
    class ServerAuthoritativeWeaponSlot_t;
    class CPathQueryComponent;
    class CLogicRelay;
    class SequenceHistory_t;
    class CPlayer_ItemServices;
    class CPulse_OutflowConnection;
    class CTestPulseIO;
    class CWeaponUMP45;
    class CGamePlayerEquip;
    class CPointEntityFinder;
    class CPulseGraphDef;
    class CKnife;
    class CLogicPlayerProxy;
    class CCSGO_TeamIntroCharacterPosition;
    class CBasePlayerControllerAPI;
    class CHostageRescueZoneShim;
    class CSimpleMarkupVolumeTagged;
    class CEnvSoundscapeAlias_snd_soundscape;
    class CCSPlayer_HostageServices;
    class CRenderComponent;
    class CWaterBullet;
    class CTriggerSoundscape;
    class CPulseCell_Outflow_PlayVOLine_CursorState_t;
    class CPointTeleportAPI;
    class CHostageExpresserShim;
    class CPointChildModifier;
    class CCSPlayerLegacyJump;
    class CWeaponHKP2000;
    class CShatterGlassShardPhysics;
    class CPathParticleRope;
    class CCredits;
    class CWeaponFiveSeven;
    class CFishPool;
    class CPlayer_MovementServices;
    class CRagdollPropAlias_physics_prop_ragdoll;
    class CBreakableProp;
    class CLightEntity;
    class CInfoDynamicShadowHintBox;
    class CBaseAnimGraphController;
    class AnimGraph2SerializedPoseRecipeSlot_t;
    class CBuoyancyHelper;
    class COrnamentProp;
    class CCSPlayer_CameraServices;
    class CModelPointEntity;
    class CRectLight;
    class CFilterMultiple;
    class CCSPlayerResource;
    class CPulseCell_FireCursors;
    class CFuncNavBlocker;
    class CMoverPathNode;
    class CEnvSoundscape;
    class CFuncBrush;
    class CBodyComponentPoint;
    class CPhysBox;
    class CSoundEventAABBEntity;
    class CItemSoda;
    class CPulseCell_Timeline_TimelineEvent_t;
    class COmniLight;
    class CTriggerVolume;
    class CBtNodeCondition;
    class CPulseCell_IntervalTimer_CursorState_t;
    class CPulseCell_BaseRequirement;
    class CEnvExplosion;
    class CPulseCell_BaseState;
    class OutflowWithRequirements_t;
    class CTestPulseIO_ThreeStringArgs_t;
    class CPulseCell_IsRequirementValid;
    class CFootstepControl;
    class CCSPlayer_ItemServices;
    class CPulseCell_Value_Gradient;
    class CParticleSystem;
    class CTriggerBrush;
    class IntervalTimer;
    class audioparams_t;
    class CSoundAreaEntityBase;
    class CWeaponM4A1Silencer;
    class CTimeline;
    class CPulseCursorFuncs;
    class CTestPulseIO_FloatStringArgs_t;
    class CountdownTimer;
    class PulseNodeDynamicOutflows_t_DynamicOutflow_t;
    class CItemAssaultSuit;
    class CBeam;
    class CLogicEventListener;
    class CCSGO_TeamSelectTerroristPosition;
    class CInfoData;
    class CWeaponNegev;
    class CWeaponElite;
    class CBasePlayerPawn;
    class WeaponPurchaseCount_t;
    class CBasePulseGraphInstance;
    class FilterHealth;
    class CCSSprite;
    class CMathColorBlend;
    class CShower;
    class CPulseCell_Inflow_GraphHook;
    class CScriptNavBlocker;
    class CEntityBlocker;
    class SignatureOutflow_Resume;
    class CPathSimpleAPI;
    class CCSObserverPawn;
    class CTriggerActiveWeaponDetect;
    class CFuncLadderAlias_func_useableladder;
    class CSpriteOriented;
    class CPointServerCommand;
    class shard_model_desc_t;
    class CPlayerSprayDecal;
    class CFuncWater;
    class CCSGameModeRules;
    class CPointPrefabAPI;
    class CPulseCell_Outflow_PlayVCD_VCDRequirementInfo_t;
    class CEconEntity;
    class CTankTargetChange;
    class CCSPlayer_WaterServices;
    class CLogicDistanceCheck;
    class CEnvCombinedLightProbeVolume;
    class ViewAngleServerChange_t;
    class CLogicDistanceAutosave;
    class CLogicBranch;
    class CPulseCell_Outflow_ScriptedSequence;
    class CFuncTrackChange;
    class CFuncTrackTrain;
    class CEnvInstructorHint;
    class CEnvWind;
    class CSoundEventPathCornerEntity;
    class CCSPlayerBase_CameraServices;
    class CPulseCell_Inflow_BaseEntrypoint;
    class CDynamicNavConnectionsVolume;
    class CConstraintAnchor;
    class CPulseCell_WaitForCursorsWithTagBase;
    class CCSPlayerPawn;
    class CEnvLightProbeVolume;
    class SpawnPoint;
    class CFuncMoverAPI;
    class CGameSceneNode;
    class CWeaponM249;
    class CRopeKeyframeAlias_move_rope;
    class CPulseServerFuncs_Sounds;
    class CPulsePhysicsConstraintsFuncs;
    class CPlayer_ObserverServices;
    class CCashStack;
    class CLogicScript;
    class CAttributeManager_cached_attribute_float_t;
    class CPulseGraphInstance_ServerEntity;
    class CSceneEntityAlias_logic_choreographed_scene;
    class CRagdollManager;
    class CPostProcessingVolume;
    class CPointProximitySensor;
    class CPulse_InvokeBinding;
    class CTriggerLook;
    class CPulseCell_Outflow_PlayVCD;
    class CMultiplayRules;
    class CMolotovGrenade;
    class CPhysTorque;
    class CMultiSource;
    class CBaseCSGrenade;
    class CLogicAuto;
    class CPhysicsWire;
    class CFuncIllusionary;
    class CInfoDynamicShadowHint;
    class CMarkupVolume;
    class CPathNode;
    class CCSGO_TeamSelectCounterTerroristPosition;
    class CTriggerRemove;
    class CLogicGameEventListener;
    class CServerOnlyModelEntity;
    class CPulseCell_IntervalTimer;
    class CMarkupVolumeTagged_Nav;
    class CInfoPlayerTerrorist;
    class CLogicAutosave;
    class CCSGO_TeamIntroTerroristPosition;
    class CPulseTestScriptLib;
    class CSingleplayRules;
    class CEnvWindShared;
    class CPointPrefab;
    class CPulseCell_BaseLerp;
    class CEnvInstructorVRHint;
    class CCSGameRulesProxy;
    class CPrecipitation;
    class CCommentaryViewPosition;
    class CEnvGlobal;
    class CLogicNPCCounterOBB;
    class CPlatTrigger;
    class CSceneEntity;
    class CChoreoInfoTarget;
    class CTonemapController2;
    class CMapSharedEnvironment;
    class CTakeDamageResultAPI;
    class CNetworkedSequenceOperation;
    class CPhysMagnet;
    class CEntityInstance;
    class CGameGibManager;
    class CHandleDummy;
    class CFuncWallToggle;
    class CCSPlayer_BulletServices;
    class CSkyCamera;
    class CCSGO_EndOfMatchLineupEnd;
    class CPlayer_AutoaimServices;
    class CItemDefuserAlias_item_defuser;
    class CPathCornerCrash;
    class CPhysPulley;
    class CCSPetPlacement;
    class CWeaponMP5SD;
    class CWeaponBaseItem;
    class CCommentaryAuto;
    class CPulseCell_Outflow_ListenForEntityOutput_CursorState_t;
    class ActiveModelConfig_t;
    class CWeaponUSPSilencer;
    class CSoundStackSave;
    class CPulseCell_Value_Curve;
    class CWeaponMag7;
    class CLogicMeasureMovement;
    class CC4;
    class CHostageCarriableProp;
    class CDynamicPropAlias_cable_dynamic;
    class CCSObserver_CameraServices;
    class CEnvDetailController;
    class CCSPlayerPawnBase;
    class CEnvSoundscapeProxy;
    class CPulseCell_Inflow_EventHandler;
    class CCSPointScriptEntity;
    class CPulseCell_BaseFlow;
    class CBombTarget;
    class CRuleEntity;
    class CPhysThruster;
    class CInfoPlayerStart;
    class CEntityFlame;
    class CSkeletonInstance;
    class CEntityComponent;
    class CBasePlatTrain;
    class CPointTeleport;
    class CTriggerGameEvent;
    class CMessageEntity;
    class CEnvEntityIgniter;
    class CPulseCell_Outflow_CycleShuffled_InstanceState_t;
    class CPulseCell_BaseLerp_CursorState_t;
    class CMarkupVolumeTagged_NavGame;
    class CMultiLightProxy;
    class CWeaponM4A1;
    class CTriggerHostageReset;
    class CPulseAnimFuncs;
    class CEconWearable;
    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t;
    class CPulseArraylib;
    class CWeaponMAC10;
    class CFuncLadder;
    class CFogController;
    class CPointTemplateAPI;
    class CItem;
    class CTriggerPush;
    class CBaseProp;
    class CInfoOffscreenPanoramaTexture;
    class CPointAngularVelocitySensor;
    class CPlayerVisibility;
    class CPulseCell_Step_FollowEntity;
    class CFlashbang;
    class CBasePlayerWeapon;
    class CCSWeaponBaseVData;
    class CPhysForce;
    class CAttributeManager;
    class SignatureOutflow_Continue;
    class CInfoTarget;
    class CPlayer_CameraServices;
    class CPulseCell_Timeline;
    class CPulseCell_Inflow_EntOutputHandler;
    class CPulseFuncs_GameParticleManager;
    class CScenePayloadVData;
    class CFilterAttributeInt;
    class CKeepUpright;
    class CPointTemplate;
    class CEnvVolumetricFogController;
    class CBot;
    class CPulseCell_Step_SetAnimGraphParam;
    class CPlayer_FlashlightServices;
    class CCSPlayerController;
    class CPhysLength;
    class CTeam;
    class CLogicNPCCounterAABB;
    class CPulseCell_Outflow_CycleOrdered_InstanceState_t;
    class CChicken;
    class CPhysicsPropRespawnable;
    class CEnvBeam;
    class CLightSpotEntity;
    class CWeaponSawedoff;
    class CTonemapTrigger;
    class CEnvShake;
    class CCSPlayer_MovementServices;
    class SellbackPurchaseEntry_t;
    class CTestPulseIO_EntityNameStringArgs_t;
    class CTriggerCallback;
    class CSoundOpvarSetAutoRoomEntity;
    class CPulseCell_Outflow_ListenForEntityOutput;
    class CPushable;
    class CRotatorTarget;
    class CPhysicsEntitySolver;
    class CLogicCollisionPair;
    class CTestEffect;
    class CPulseCell_Outflow_ScriptedSequence_CursorState_t;
    class CPropDoorRotating;
    class CEnvParticleGlow;
    class CMathRemap;
    class CSoundOpvarSetOBBWindEntity;
    class PhysicsRagdollPose_t;
    class CPropDataComponent;
    class CScriptTriggerOnce;
    class CLightOrthoEntity;
    class CInfoInstructorHintHostageRescueZone;
    class CPulseCell_LimitCount_InstanceState_t;
    class CTriggerTeleport;
    class CFuncWall;
    class CBtActionAim;
    class CCSGO_TeamPreviewCharacterPosition;
    class CGameRulesProxy;
    class CInfoLadderDismount;
    class CPulseServerFuncs;
    class CMessage;
    class CPointVelocitySensor;
    class CCS2PawnGraphController;
    class EngineCountdownTimer;
    class CBaseModelEntityAPI;
    class CScriptTriggerMultiple;
    class CHostage;
    class CEnvSpark;
    class CCSPlayerController_DamageServices;
    class CEnvCombinedLightProbeVolumeAlias_func_combined_light_probe_volume;
    class CBaseModelEntity_OnDamageLevelChangedArgs_t;
    class CFilterLOS;
    class CPointOrient;
    class sky3dparams_t;
    class CWeaponP250;
    class CDestructiblePartsComponent;
    class CChangeLevel;
    class CBaseButton;
    class CPulseCell_SoundEventStart;
    class CPulseCell_Step_DebugLog;
    class CItem_Healthshot;
    class CBaseGrenade;
    class CColorCorrectionVolume;
    class CCSPlayerController_ActionTrackingServices;
    class CBodyComponentBaseAnimGraph;
    class CPulseCell_BaseYieldingInflow;
    class PulseNodeDynamicOutflows_t;
    class CFogVolume;
    class CFuncRotating;
    class CTimerEntity;
    class CBtActionMoveTo;
    class CPlayer_MovementServices_Humanoid;
    class CBaseEntityAPI;
    class CPulseCell_IsRequirementValid_Criteria_t;
    class CWeaponG3SG1;
    class CTriggerOnce;
    class CSMatchStats_t;
    class EntityRenderAttribute_t;
    class CPulseCell_Inflow_ObservableVariableListener;
    class CFuncMonitor;
    class CInfoVisibilityBox;
    class CGunTarget;
    class CSoundEventConeEntity;
    class CSoundOpvarSetOBBEntity;
    class CFilterMultipleAPI;
    class CDecoyProjectile;
    class CPrecipitationBlocker;
    class CSoundOpvarSetPathCornerEntity;
    class CPointClientCommand;
    class CHostageRescueZone;
    class CWorld;
    class CPathMoverEntitySpawner;
    class CModelState;
    class CPulseCell_LerpCameraSettings_CursorState_t;
    class CPulseCell_Outflow_CycleOrdered;
    class CWeaponGlock;
    class CHEGrenadeProjectile;
    class CTriggerGravity;
    class CCollisionProperty;
    class CWeaponGalilAR;
    class CFilterMassGreater;
    class CWeaponMP7;
    class CCSWeaponBaseGun;
    class CEnableMotionFixup;
    class CLogicActiveAutosave;
    class CMathCounter;
    class CCSGameModeRules_ArmsRace;
    class CAttributeContainer;
    class CCSPlace;
    class PulseSelectorOutflowList_t;
    class CFilterContext;
    class CLightEnvironmentEntity;
    class CEnvDecal;
    class CEnvVolumetricFogVolume;
    class CServerOnlyEntity;
    class CPulseCell_PlaySequence_CursorState_t;
    class CBodyComponentSkeletonInstance;
    class CItemGeneric;
    class CPointValueRemapper;
    class CBtNodeConditionInactive;
    class CCSGO_TeamIntroCounterTerroristPosition;
    class CRagdollProp;
    class CScriptComponent;
    class CFuncTrain;
    class CAI_ChangeHintGroup;
    class CCSPlayer_BuyServices;
    class CWeaponAug;
    class CPhysHinge;
    class CBuyZone;
    class CInfoChoreoAnchor;
    class DestructiblePartDamageRequestAPI;
    class CWeaponSSG08;
    class CLogicRelayAPI;
    class CInfoWorldLayer;
    class CBodyComponentBaseModelEntity;
    class CLogicProximity;
    class CPointGiveAmmo;
    class CCSGO_EndOfMatchLineupStart;
    class FilterDamageType;
    class CPointCamera;
    class CAttributeList;
    class CPulseCell_Inflow_Wait;
    class CFilterProximity;
    class CCS2WeaponGraphController;
    class CEffectData;
    class CEntityDissolve;
    class CCSGameRules;
    class CPulseCell_Outflow_CycleShuffled;
    class CBaseCSGrenadeProjectile;
    class CPhysConstraint;
    class CLogicAchievement;
    class CCSPlayerController_InventoryServices_NetworkedLoadoutSlot_t;
    class CLightComponent;
    class CCSWeaponBase;
    class CPointClientUIDialog;
    class CLogicLineToEntity;
    class CSoundAreaEntitySphere;
    class CCSPlayer_ActionTrackingServices;
    class CTestPulseIOComponent_API;
    class CPhysicalButton;
    class CInfoSpawnGroupLoadUnload;
    class CSoundAreaEntityOrientedBox;
    class CCSObserver_MovementServices;
    class CPulseCell_Outflow_ListenForAnimgraphTag;
    class CBodyComponent;
    class CPulseCell_Inflow_Method;
    class CDecoyGrenade;
    class CEconItemView;
    class CIncendiaryGrenade;
    class CBaseDMStart;
    class CBaseModelEntity;
    class fogplayerparams_t;
    class CGlowProperty;
    class CInstancedSceneEntity;
    class CPulseCell_BaseValue;
    class CCitadelSoundOpvarSetOBB;
    class CSoundEventParameter;
    class CPlayer_WaterServices;
    class CPulseCell_BooleanSwitchState;
    class CRotButton;
    class CEnvViewPunch;
    class CDamageRecord;
    class VPhysicsCollisionAttribute_t;
    class CItemKevlar;
    class CFuncShatterglass;
    class CNavWalkable;
    class CPlantedC4;
    class CEnvSoundscapeProxyAlias_snd_soundscape_proxy;
    class CVoteController;
    class CPulseCell_Inflow_Yield;
    class CPulseMathlib;
    class CPhysImpact;
    class CBaseEntity;
    class CPlayer_UseServices;
    class CGameSceneNodeHandle;
    class CMarkupVolumeWithRef;
    class CCSGO_TeamSelectCharacterPosition;
    class CPulseCell_Unknown;
    class CFuncPlatRot;
    class CRagdollMagnet;
    class CInfoInstructorHintTarget;
    class CSpriteAlias_env_glow;
    class CFireCrackerBlast;
    class CSpotlightEnd;
    class CEnvSky;
    class CInfoSpawnGroupLandmark;
    class CPointAngleSensor;
    class CEnvWindController;
    class CSPerRoundStats_t;
    class CGenericConstraint;
    class CPulseCell_Outflow_CycleRandom;
    class CPulseCell_Step_PublicOutput;
    class CEnvLaser;
    class CSoundOpvarSetEntity;
    class CEnvBeverage;
    class CPhysMotor;
    class CLogicGameEvent;
    class CPhysicsPropMultiplayer;
    class CPhysExplosion;
    class CSplineConstraint;
    class CLogicCompare;
    class CCSGameModeRules_Noop;
    class CPulse_BlackboardReference;
    class CFuncTankTrain;
    class CPointClientUIWorldPanel;
    class CSoundEventSphereEntity;
    class CCSPlayerController_InGameMoneyServices;
    class CCSPlayer_AimPunchServices;
    class CRuleBrushEntity;
    class CMapVetoPickController;
    class CFuncPropRespawnZone;
    class CFilterModel;
    class CWeaponP90;
    class CNavSpaceInfo;
    class CPhysSlideConstraint;
    class CPulseGameBlackboard;
    class CSoundEventEntityAlias_snd_event_point;
    class CChoreoComponent;
    class CPulseCell_Value_RandomInt;
    class CPointGamestatsCounter;
    class CTextureBasedAnimatable;
    class CSprite;
    class CBaseMoveBehavior;
    class CDynamicLight;
    class CWeaponTaser;
    class CEnvCubemapBox;
    class CRotDoor;
    class CPathMover;
    class CFuncVPhysicsClip;
    class CPhysFixed;
    class CLogicNavigation;
    class CPathSimple;
    class CPathParticleRopeAlias_path_particle_rope_clientside;
    class CCSPointPulseAPI;
    class CEnvWindVolume;
    class CFuncElectrifiedVolume;
    class CCSMinimapBoundary;
    class EntitySpottedState_t;
    class fogparams_t;
    class CSoundEventOBBEntity;
    class CFlashbangProjectile;
    class CTriggerMultiple;
    class CPhysBallSocket;
    class CDebugHistory;
    class CSoundOpvarSetPointBase;
    class CExplosionTypeData;
    class CPathKeyFrame;
    class CWeaponCZ75a;
    class CScriptTriggerPush;
    class CRevertSaved;
    class CTriggerBombReset;
    class CTriggerHurt;
    class CCSPlayer_WeaponServices;
    class CRetakeGameRules;
    class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable;
    class CInfoInstructorHintBombTargetA;
    class CTeamplayRules;
    class CScriptTriggerHurt;
    class CCSGO_WingmanIntroCharacterPosition;
    class CWeaponMP9;
    class CTriggerDetectExplosion;
    class CFilterName;
    class CSmokeGrenadeProjectile;
    class CBlood;
    class CCSTeam;
    class CRulePointEntity;
    class CPulse_CallInfo;
    class CFuncMoveLinearAlias_momentary_door;
    class CBaseAnimGraph;
    class CEnvCubemapFog;
    class CPulseCell_InlineNodeSkipSelector;
    class CBaseDoor;
    class CServerOnlyPointEntity;
    class CGameMoney;
    class CEnvHudHint;
    class CNullEntity;
    class CLogicalEntity;
    class CItemDefuser;
    class CItemGenericTriggerHelper;
    class CPlayer_WeaponServices;
    class CRagdollPropAttached;
    class CItemDogtags;
    class CFuncPlat;
    class CBarnLight;
    class CInstructorEventEntity;
    class CWeaponTec9;
    class CPathCorner;
    class CTriggerSndSosOpvar;
    class CPulseCell_LimitCount;
    class CPulseCell_Step_CallExternalMethod;
    class CPointCommentaryNode;
    class CMomentaryRotButton;
    class CSceneListManager;
    class CEnvTilt;
    class CEnvSoundscapeTriggerable;
    class CFuncMover;
    class CPhysicsProp;
    class CFuncNavObstruction;
    class CPhysWheelConstraint;
    class CSkyboxReference;
    class CPointPulse;
    class CMolotovProjectile;
    class CFilterClass;
    class CTriggerToggleSave;
    class CPathWithDynamicNodes;
    class CColorCorrection;
    class CPropDoorRotatingBreakable;
    class CLightDirectionalEntity;
    class CBaseClientUIEntity;
    class CBreakable;
    class CInfoLandmark;
    class CBaseFilter;
    class WeaponPurchaseTracker_t;
    class CPulseCell_Outflow_PlaySceneBase_CursorState_t;
    class PulseObservableBoolExpression_t;
    class CMapInfo;
    class CGradientFog;
    class CSoundOpvarSetAABBEntity;
    class CPulseCell_Outflow_PlaySequence;
    class CPointClientUIWorldTextPanel;
    class CEntityIdentity;
    class CPulseCell_LimitCount_Criteria_t;
    class CFuncRotator;
    class CSoundEventEntity;
    class CInfoPlayerCounterterrorist;
    class CEnvFade;
    class CBasePlayerVData;
    class CTriggerImpact;
    class CCSGameModeRules_Deathmatch;
    class CTestPulseIO_EntityHandleIntArgs_t;
    class CPulseCell_CursorQueue;
    class CPulseCell_Value_RandomFloat;
    class CPulseExecCursor;
    class CBasePropDoor;
    class CLogicBranchList;
    class CBtActionParachutePositioning;
    class CAK47;
    class CDynamicProp;
    class CHostageAlias_info_hostage_spawn;
    class CFilterTeam;
    class CFuncConveyor;
    class CTriggerPhysics;
    class CInfoInstructorHintBombTargetB;
    class CFuncTimescale;
    class CBasePlayerWeaponVData;
    class CInfoInteraction;
    class CSoundOpvarSetPointEntity;
    class CInfoTargetServerOnly;
    class CServerRagdollTrigger;
    class CDynamicPropAlias_dynamic_prop;
    class CMarkupVolumeTagged;
    class CInfoParticleTarget;
    class CEnvCubemap;
    class CCSPlayer_DamageReactServices;
    class CWeaponXM1014;
    class CTriggerLerpObject;
    class CPhysicsPropOverride;
    class CTriggerSave;
    class CPointHurt;
    class CBasePlayerController;
    class CRangeFloat;
    class CDestructiblePart;
    class CAnimEventQueueListener;
    class PhysBlockHeader_t;
    class RelationshipOverride_t;
    class AutoRoomDoorwayPairs_t;
    class NavHull_t;
    class CDebugSnapshotData_t;
    class CRemapFloat;
    class CHintMessage;
    class ParticleNode_t;
    class CFootstepTableHandle;
    class CDecalGroupVData;
    class CNmSnapWeaponTask;
    class CPlayerControllerComponent;
    class CResponseQueue;
    class CodeGenAABB_t;
    class CScriptUniformRandomStream;
    class lerpdata_t;
    class WrappedPhysicsJoint_t;
    class SimpleConstraintSoundProfile;
    class CSimpleSimTimer;
    class AI_BaseNPCAnimGraph_DebugSnapshotData_t;
    class CPhysicsBodyGameMarkupData;
    class SoundCommand_t;
    class modifiedconvars_t;
    class CTestPulseIOComponent_Derived;
    class SAVE_HEADER;
    class CSkillDamage;
    class DebugSnapshotBaseStructuredData_t;
    class AI_DefaultNPC_DebugSnapshotData_t_PathQuery_t;
    class AI_Motor_DebugSnapshotData_t;
    class CFloatExponentialMovingAverage;
    class physics_save_sphere_t;
    class GAME_HEADER;
    class CAnimEventListenerBase;
    class AI_BaseNPC_DebugSnapshotData_t;
    class CDebugDrawHistoryData;
    class CNmEventConsumer;
    class CNetworkViewOffsetVector;
    class AmmoIndex_t;
    class SceneRequestTargetMapPair_t;
    class CDestructiblePartsSystemData;
    class CRopeOverlapHit;
    class ResponseContext_t;
    class CNavVolumeSphericalShell;
    class CPlayerPawnComponent;
    class AI_Navigator_DebugSnapshotData_t;
    class CDecalInstance;
    class CGameScriptedMoveData;
    class CSkeletonAnimationController;
    class CNavVolumeMarkupVolume;
    class CResponseCriteriaSet;
    class CAI_Expresser;
    class IChoreoServices;
    class CNmEventConsumerAttributes;
    class CStopwatch;
    class ResponseParams;
    class SPAWNGROUP_HEADER;
    class globalentity_t;
    class SceneInterestTags_t;
    class ConstraintSoundInfo;
    class CPhysicsBodyGameMarkup;
    class PointCameraSettings_t;
    class DebugDrawBoneTransforms_t;
    class CVectorMovingAverage;
    class AI_MotorGroundAnimgraph_DebugSnapshotData_t;
    class CSoundEnvelope;
    class dynpitchvol_base_t;
    class CStopwatchBase;
    class SceneRequestHandle_t;
    class CNavVolumeVector;
    class NavGravity_t;
    class PulseScriptedSequenceData_t;
    class RotatorQueueEntry_t;
    class CBaseAnimGraphDestructibleParts_GraphController;
    class ExternalAnimGraphHandle_t;
    class CPhysicsShake;
    class CInfoChoreoAnchorPosition;
    class VelocitySampler;
    class CTakeDamageResult;
    class SceneEventId_t;
    class ExternalAnimGraph_t;
    class CCommentarySystem;
    class ResponseFollowup;
    class AmmoTypeInfo_t;
    class CNetworkTransmitComponent;
    class CPathQueryUtil;
    class RagdollCreationParams_t;
    class CRelativeTransform;
    class CRangeInt;
    class CWorldCompositionChunkReferenceElement_t;
    class CRandStopwatch;
    class CMovementStatsProperty;
    class CGameChoreoServices;
    class PhysObjectHeader_t;
    class CSimpleStopwatch;
    class CShatterGlassShard;
    class ragdollelement_t;
    class CGameScriptedMoveDef_t;
    class CNetworkOriginCellCoordQuantizedVector;
    class CBaseAnimGraphVariationUserData;
    class DynamicVolumeDef_t;
    class CNetworkOriginQuantizedVector;
    class magnetted_objects_t;
    class CHintMessageQueue;
    class CSkillInt;
    class thinkfunc_t;
    class CNavHullPresetVData;
    class CSkillFloat;
    class WaterWheelFrictionScale_t;
    class ragdollhierarchyjoint_t;
    class CSceneEventInfo;
    class SoundeventPathCornerPairNetworked_t;
    class CSoundPatch;
    class CSceneOpportunity;
    class CCS2ChickenGraphController;
    class levellist_t;
    class locksound_t;
    class DecalGroupOption_t;
    class CBtNode;
    class CAnimGraphControllerManager;
    class CFiringModeFloat;
    class CCopyRecipientFilter;
    class CFloatMovingAverage;
    class FuncMoverMovementSummary_t;
    class CSmoothFunc;
    class IHasAttributes;
    class ragdoll_t;
    class HullFlags_t;
    class ISkeletonAnimationController;
    class RotatorHistoryEntry_t;
    class GameAmmoTypeInfo_t;
    class CMotorController;
    class CSimTimer;
    class CBaseIssue;
    class SummaryTakeDamageInfo_t;
    class INavObstacle;
    class CSceneRequest;
    class entitytable_t;
    class SceneOpportunityActor_t;
    class CRR_Response;
    class CVectorExponentialMovingAverage;
    class CNmAimCSNode_CDefinition;
    class CConstantForceController;
    class WaterWheelDrag_t;
    class CTakeDamageInfo;
    class CRandSimTimer;
    class CBtNodeComposite;
    class CRelativeLocation;
    class Extent;
    class sndopvarlatchdata_t;
    class PrecipitationFilter_t;
    class IEconItemInterface;
    class PathMoverEntitySpawn;
    class CMultiplayer_Expresser;
    class CNavVolume;
    class QuestProgress;
    class CNmAimCSTask;
    class ParticleIndex_t;
    class CAI_ExpresserWithFollowup;
    class CTakeDamageSummaryScopeGuard;
    class CIronSightController;
    class CNmEventConsumerSound;
    class CNmEventConsumerLegacy;
    class DestructiblePartDamageRequest_t;
    class CInButtonState;
    class CNmEventConsumerParticle;
    class CNavHullVData;
    class AI_DefaultNPC_DebugSnapshotData_t;
    class CNmSnapWeaponNode_CDefinition;
    class SoundOpvarTraceResult_t;
    class CAnimEventListener;
    class CNavVolumeCalculatedVector;
    class CFiringModeInt;
    class CBtNodeDecorator;
    class CSAdditionalPerRoundStats_t;
    class CEmptyGraphController;
    class ModelConfigHandle_t;
    class CEntitySubclassVDataBase;
    class CBreakableStageHelper;
    class AI_MotorGroundAnimgraph_DebugSnapshotData_t_Event_t;
    class CNavVolumeBreadthFirstSearch;
    class SceneOpportunityHandle_t;
    class dynpitchvol_t;
    class CSAdditionalMatchStats_t;
    class AI_Navigator_DebugSnapshotData_t_Waypoint_t;
    class CSceneCriteria;
    class CTestPulseIOComponent;
    class IRagdoll;
    class CCSPlayerAnimationState;
    class hudtextparms_t;
    class CAnimGraphControllerBase;
    class CNetworkVelocityVector;
    class CDestructiblePart_DamageLevel;
    class CNavVolumeAll;
    class CNavVolumeSphere;
    class Relationship_t;

    enum class CLogicBranchList_e : std::uint32_t {
        LOGIC_BRANCH_LISTENER_NOT_INIT = 0x0,
        LOGIC_BRANCH_LISTENER_ALL_TRUE = 0x1,
        LOGIC_BRANCH_LISTENER_ALL_FALSE = 0x2,
        LOGIC_BRANCH_LISTENER_MIXED = 0x3,
    };

    enum class CFuncMover_e : std::uint32_t {
        MOVE_LOOP = 0x0,
        MOVE_OSCILLATE = 0x1,
        MOVE_STOP_AT_END = 0x2,
    };

    enum class CFuncRotator_e : std::uint32_t {
        ROTATE_LOOP = 0x0,
        ROTATE_OSCILLATE = 0x1,
        ROTATE_STOP_AT_END = 0x2,
        ROTATE_LOOK_AT_TARGET = 0x3,
        ROTATE_LOOK_AT_TARGET_ONLY_YAW = 0x4,
        ROTATE_RETURN_TO_INITIAL_ORIENTATION = 0x5,
    };

    enum class PulseBestOutflowRules_t : std::uint32_t {
        SORT_BY_NUMBER_OF_VALID_CRITERIA = 0x0,
        SORT_BY_OUTFLOW_INDEX = 0x1,
    };

    enum class CPhysicsProp_e : std::uint32_t {
        CRATE_SPECIFIC_ITEM = 0x0,
        CRATE_TYPE_COUNT = 0x1,
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

    enum class CFuncMover_e2 : std::uint32_t {
        FOLLOW_CONSTRAINT_DISTANCE = 0x0,
        FOLLOW_CONSTRAINT_SPRING = 0x1,
        FOLLOW_CONSTRAINT_RATIO = 0x2,
    };

    enum class CFuncMover_e3 : std::uint32_t {
        FOLLOW_ENTITY_BIDIRECTIONAL = 0x0,
        FOLLOW_ENTITY_FORWARD = 0x1,
        FOLLOW_ENTITY_REVERSE = 0x2,
    };

    enum class CFuncMover_e4 : std::uint32_t {
        TRANSITION_TO_PATH_NODE_ACTION_NONE = 0x0,
        TRANSITION_TO_PATH_NODE_ACTION_START_FORWARD = 0x1,
        TRANSITION_TO_PATH_NODE_ACTION_START_REVERSE = 0x2,
        TRANSITION_TO_PATH_NODE_TRANSITIONING = 0x3,
    };

    enum class CFuncMover_e5 : std::uint32_t {
        ORIENTATION_FORWARD_PATH = 0x0,
        ORIENTATION_FORWARD_PATH_AND_FIXED_PITCH = 0x1,
        ORIENTATION_FORWARD_PATH_AND_UP_CONTROL_POINT = 0x2,
        ORIENTATION_MATCH_CONTROL_POINT = 0x3,
        ORIENTATION_FIXED = 0x4,
        ORIENTATION_FACE_PLAYER = 0x5,
        ORIENTATION_FORWARD_MOVEMENT_DIRECTION = 0x6,
        ORIENTATION_FORWARD_MOVEMENT_DIRECTION_AND_UP_CONTROL_POINT = 0x7,
        ORIENTATION_FACE_ENTITY = 0x8,
    };

    enum class PropDoorRotatingOpenDirection_e : std::uint32_t {
        DOOR_ROTATING_OPEN_BOTH_WAYS = 0x0,
        DOOR_ROTATING_OPEN_FORWARD = 0x1,
        DOOR_ROTATING_OPEN_BACKWARD = 0x2,
    };

    enum class PulseCollisionGroup_t : std::uint32_t {
        DEFAULT = 0x0,
    };

    enum class SceneOnPlayerDeath_t : std::uint32_t {
        SCENE_ONPLAYERDEATH_DO_NOTHING = 0x0,
        SCENE_ONPLAYERDEATH_CANCEL = 0x1,
    };

    enum class LessonPanelLayoutFileTypes_t : std::uint32_t {
        LAYOUT_HAND_DEFAULT = 0x0,
        LAYOUT_WORLD_DEFAULT = 0x1,
        LAYOUT_CUSTOM = 0x2,
    };

    enum class TimelineCompression_t : std::uint32_t {
        TIMELINE_COMPRESSION_SUM = 0x0,
        TIMELINE_COMPRESSION_COUNT_PER_INTERVAL = 0x1,
        TIMELINE_COMPRESSION_AVERAGE = 0x2,
        TIMELINE_COMPRESSION_AVERAGE_BLEND = 0x3,
        TIMELINE_COMPRESSION_TOTAL = 0x4,
    };

    enum class SubclassVDataChangeType_t : std::uint32_t {
        SUBCLASS_VDATA_CREATED = 0x0,
        SUBCLASS_VDATA_SUBCLASS_CHANGED = 0x1,
        SUBCLASS_VDATA_RELOADED = 0x2,
    };

    enum class C4LightEffect_t : std::uint32_t {
        eLightEffectNone = 0x0,
        eLightEffectDropped = 0x1,
        eLightEffectThirdPersonHeld = 0x2,
    };

    enum class StanceType_t : std::int32_t {
        STANCE_CURRENT = -1,
        STANCE_DEFAULT = 0x0,
        STANCE_CROUCHING = 0x1,
        STANCE_PRONE = 0x2,
        NUM_STANCES = 0x3,
    };

    enum class Explosions : std::uint32_t {
        expRandom = 0x0,
        expDirected = 0x1,
        expUsePrecise = 0x2,
    };

    enum class PreviewCharacterMode : std::int32_t {
        INVALID = -1,
        DIORAMA = 0x0,
        MAIN_MENU = 0x1,
        BUY_MENU = 0x2,
        TEAM_SELECT = 0x3,
        END_OF_MATCH = 0x4,
        INVENTORY_INSPECT = 0x5,
        WALKING = 0x6,
        TEAM_INTRO = 0x7,
        WINGMAN_INTRO = 0x8,
        BANNER = 0x9,
    };

    enum class ObserverInterpState_t : std::uint32_t {
        OBSERVER_INTERP_NONE = 0x0,
        OBSERVER_INTERP_STARTING = 0x1,
        OBSERVER_INTERP_TRAVELING = 0x2,
        OBSERVER_INTERP_SETTLING = 0x3,
    };

    enum class WorldTextPanelOrientation_t : std::uint32_t {
        WORLDTEXT_ORIENTATION_DEFAULT = 0x0,
        WORLDTEXT_ORIENTATION_FACEUSER = 0x1,
        WORLDTEXT_ORIENTATION_FACEUSER_UPRIGHT = 0x2,
    };

    enum class EDestructibleParts_DestroyParameterFlags : std::uint32_t {
        None = 0x0,
        GenerateBreakpieces = 0x1,
        SetBodyGroupAndCollisionState = 0x2,
        EnableFlinches = 0x4,
        ForceDamageApply = 0x8,
        IgnoreKillEntityFlag = 0x10,
        IgnoreHealthCheck = 0x20,
        Default = 0x7,
    };

    enum class WorldTextPanelHorizontalAlign_t : std::uint32_t {
        WORLDTEXT_HORIZONTAL_ALIGN_LEFT = 0x0,
        WORLDTEXT_HORIZONTAL_ALIGN_CENTER = 0x1,
        WORLDTEXT_HORIZONTAL_ALIGN_RIGHT = 0x2,
    };

    enum class SequenceFinishNotifyState_t : std::uint8_t {
        eDoNotNotify = 0x0,
        eNotifyWhenFinished = 0x1,
        eNotifyTriggered = 0x2,
    };

    enum class SoundEventStartType_t : std::uint32_t {
        SOUNDEVENT_START_PLAYER = 0x0,
        SOUNDEVENT_START_WORLD = 0x1,
        SOUNDEVENT_START_ENTITY = 0x2,
    };

    enum class soundcommands_t : std::uint32_t {
        SOUNDCTRL_CHANGE_VOLUME = 0x0,
        SOUNDCTRL_CHANGE_PITCH = 0x1,
        SOUNDCTRL_STOP = 0x2,
        SOUNDCTRL_DESTROY = 0x3,
        SOUNDCTRL_FADEOUT = 0x4,
    };

    enum class AnimGraphDebugDrawType_t : std::uint32_t {
        None = 0x0,
        WsPosition = 0x1,
        MsPosition = 0x2,
        WsDirection = 0x3,
        MsDirection = 0x4,
    };

    enum class TrainOrientationType_t : std::uint32_t {
        TrainOrientation_Fixed = 0x0,
        TrainOrientation_AtPathTracks = 0x1,
        TrainOrientation_LinearBlend = 0x2,
        TrainOrientation_EaseInEaseOut = 0x3,
    };

    enum class CInfoChoreoLocatorShapeType_t : std::uint32_t {
        POINT = 0x0,
        LINE = 0x1,
        COUNT = 0x2,
        NONE = 0x3,
    };

    enum class CSWeaponCategory : std::uint32_t {
        WEAPONCATEGORY_OTHER = 0x0,
        WEAPONCATEGORY_MELEE = 0x1,
        WEAPONCATEGORY_SECONDARY = 0x2,
        WEAPONCATEGORY_SMG = 0x3,
        WEAPONCATEGORY_RIFLE = 0x4,
        WEAPONCATEGORY_HEAVY = 0x5,
        WEAPONCATEGORY_COUNT = 0x6,
    };

    enum class BeginDeathLifeStateTransition_t : std::uint8_t {
        TRANSITION_TO_LIFESTATE_DYING = 0x0,
        TRANSITION_TO_LIFESTATE_DEAD = 0x1,
    };

    enum class PointOrientGoalDirectionType_t : std::uint32_t {
        eAbsOrigin = 0x0,
        eCenter = 0x1,
        eHead = 0x2,
        eForward = 0x3,
        eEyesForward = 0x4,
    };

    enum class ItemFlagTypes_t : std::uint8_t {
        ITEM_FLAG_NONE = 0x0,
        ITEM_FLAG_CAN_SELECT_WITHOUT_AMMO = 0x1,
        ITEM_FLAG_NOAUTORELOAD = 0x2,
        ITEM_FLAG_NOAUTOSWITCHEMPTY = 0x4,
        ITEM_FLAG_LIMITINWORLD = 0x8,
        ITEM_FLAG_EXHAUSTIBLE = 0x10,
        ITEM_FLAG_DOHITLOCATIONDMG = 0x20,
        ITEM_FLAG_NOAMMOPICKUPS = 0x40,
        ITEM_FLAG_NOITEMPICKUP = 0x80,
    };

    enum class SurroundingBoundsType_t : std::uint8_t {
        USE_OBB_COLLISION_BOUNDS = 0x0,
        USE_BEST_COLLISION_BOUNDS = 0x1,
        USE_HITBOXES = 0x2,
        USE_SPECIFIED_BOUNDS = 0x3,
        USE_GAME_CODE = 0x4,
        USE_ROTATION_EXPANDED_BOUNDS = 0x5,
        USE_ROTATION_EXPANDED_ORIENTED_BOUNDS = 0x6,
        USE_COLLISION_BOUNDS_NEVER_VPHYSICS = 0x7,
        USE_ROTATION_EXPANDED_SEQUENCE_BOUNDS = 0x8,
        SURROUNDING_TYPE_BIT_COUNT = 0x3,
    };

    enum class LifeState_t : std::uint32_t {
        LIFE_ALIVE = 0x0,
        LIFE_DYING = 0x1,
        LIFE_DEAD = 0x2,
        LIFE_RESPAWNABLE = 0x3,
        LIFE_RESPAWNING = 0x4,
        NUM_LIFESTATES = 0x5,
    };

    enum class PointOrientConstraint_t : std::uint32_t {
        eNone = 0x0,
        ePreserveUpAxis = 0x1,
    };

    enum class NPCFollowFormation_t : std::int32_t {
        Default = -1,
        CloseCircle = 0x0,
        WideCircle = 0x1,
        MediumCircle = 0x5,
        Sidekick = 0x6,
    };

    enum class GLOBALESTATE : std::uint8_t {
        GLOBAL_OFF = 0x0,
        GLOBAL_ON = 0x1,
        GLOBAL_DEAD = 0x2,
    };

    enum class AnimationAlgorithm_t : std::int8_t {
        eInvalid = -1,
        eNone = 0x0,
        eSequence = 0x1,
        eAnimGraph2 = 0x2,
        eAnimGraph2Secondary = 0x3,
        eCount = 0x4,
    };

    enum class CSWeaponMode : std::uint32_t {
        Primary_Mode = 0x0,
        Secondary_Mode = 0x1,
        WeaponMode_MAX = 0x2,
    };

    enum class OnFrame : std::uint8_t {
        ONFRAME_UNKNOWN = 0x0,
        ONFRAME_TRUE = 0x1,
        ONFRAME_FALSE = 0x2,
    };

    enum class Materials : std::uint32_t {
        matGlass = 0x0,
        matWood = 0x1,
        matMetal = 0x2,
        matFlesh = 0x3,
        matCinderBlock = 0x4,
        matCeilingTile = 0x5,
        matComputer = 0x6,
        matUnbreakableGlass = 0x7,
        matRocks = 0x8,
        matWeb = 0x9,
        matNone = 0xA,
        matLastMaterial = 0xB,
    };

    enum class BloodType : std::int32_t {
        None = -1,
        ColorRed = 0x0,
        ColorYellow = 0x1,
        ColorGreen = 0x2,
        ColorRedLVL2 = 0x3,
        ColorRedLVL3 = 0x4,
        ColorRedLVL4 = 0x5,
        ColorRedLVL5 = 0x6,
        ColorRedLVL6 = 0x7,
    };

    enum class NavScope_t : std::uint8_t {
        eGround = 0x0,
        eAir = 0x1,
        eCount = 0x2,
        eFirst = 0x0,
        eInvalid = 0xFF,
    };

    enum class BreakableContentsType_t : std::uint32_t {
        BC_DEFAULT = 0x0,
        BC_EMPTY = 0x1,
        BC_PROP_GROUP_OVERRIDE = 0x2,
        BC_PARTICLE_SYSTEM_OVERRIDE = 0x3,
    };

    enum class AnimLoopMode_t : std::int32_t {
        ANIM_LOOP_MODE_INVALID = -1,
        ANIM_LOOP_MODE_NOT_LOOPING = 0x0,
        ANIM_LOOP_MODE_LOOPING = 0x1,
        ANIM_LOOP_MODE_USE_SEQUENCE_SETTINGS = 0x2,
        ANIM_LOOP_MODE_COUNT = 0x3,
    };

    enum class Class_T : std::uint32_t {
        CLASS_NONE = 0x0,
        CLASS_PLAYER = 0x1,
        CLASS_PLAYER_ALLY = 0x2,
        CLASS_C4_FOR_RADAR = 0x3,
        CLASS_FOOT_CONTACT_SHADOW = 0x4,
        CLASS_WEAPON = 0x5,
        CLASS_WATER_SPLASHER = 0x6,
        CLASS_HUDMODEL_WEAPON = 0x7,
        CLASS_HUDMODEL_ARMS = 0x8,
        CLASS_HUDMODEL_ADDON = 0x9,
        CLASS_WORLDMODEL_GLOVES = 0xA,
        CLASS_DOOR = 0xB,
        CLASS_PLANTED_C4 = 0xC,
        NUM_CLASSIFY_CLASSES = 0xD,
    };

    enum class filter_t : std::uint32_t {
        FILTER_AND = 0x0,
        FILTER_OR = 0x1,
    };

    enum class CSWeaponSilencerType : std::uint32_t {
        WEAPONSILENCER_NONE = 0x0,
        WEAPONSILENCER_DETACHABLE = 0x1,
        WEAPONSILENCER_INTEGRATED = 0x2,
    };

    enum class EProceduralRagdollWeightIndexPropagationMethod : std::uint32_t {
        Bone = 0x0,
        BoneAndChildren = 0x1,
    };

    enum class GameAnimEventIndex_t : std::uint32_t {
        AE_EMPTY = 0x0,
        AE_CL_PLAYSOUND = 0x1,
        AE_CL_PLAYSOUND_ATTACHMENT = 0x2,
        AE_CL_PLAYSOUND_POSITION = 0x3,
        AE_SV_PLAYSOUND = 0x4,
        AE_CL_STOPSOUND = 0x5,
        AE_CL_PLAYSOUND_LOOPING = 0x6,
        AE_CL_CREATE_PARTICLE_EFFECT = 0x7,
        AE_CL_STOP_PARTICLE_EFFECT = 0x8,
        AE_CL_CREATE_PARTICLE_EFFECT_CFG = 0x9,
        AE_SV_CREATE_PARTICLE_EFFECT_CFG = 0xA,
        AE_SV_STOP_PARTICLE_EFFECT = 0xB,
        AE_FOOTSTEP = 0xC,
        AE_CL_STOP_RAGDOLL_CONTROL = 0xD,
        AE_CL_ENABLE_BODYGROUP = 0xE,
        AE_CL_DISABLE_BODYGROUP = 0xF,
        AE_BODYGROUP_SET_VALUE = 0x10,
        AE_WEAPON_PERFORM_ATTACK = 0x11,
        AE_FIRE_INPUT = 0x12,
        AE_CL_CLOTH_ATTR = 0x13,
        AE_CL_CLOTH_GROUND_OFFSET = 0x14,
        AE_CL_CLOTH_STIFFEN = 0x15,
        AE_CL_CLOTH_EFFECT = 0x16,
        AE_CL_CREATE_ANIM_SCOPE_PROP = 0x17,
        AE_SV_IKLOCK = 0x18,
        AE_PULSE_GRAPH = 0x19,
        AE_DISABLE_PLATFORM = 0x1A,
        AE_ENABLE_PLATFORM_PLAYER_FOLLOWS_YAW = 0x1B,
        AE_ENABLE_PLATFORM_PLAYER_IGNORES_YAW = 0x1C,
        AE_DESTRUCTIBLE_PART_DESTROY = 0x1D,
        AE_CL_WEAPON_TRANSITION_INTO_HAND = 0x1E,
        AE_SV_ATTACH_SILENCER_COMPLETE = 0x1F,
        AE_SV_DETACH_SILENCER_COMPLETE = 0x20,
        AE_CL_EJECT_MAG = 0x21,
        AE_WPN_COMPLETE_RELOAD = 0x22,
        AE_WPN_HEALTHSHOT_INJECT = 0x23,
        AE_GRENADE_THROW_COMPLETE = 0x24,
    };

    enum class FixAngleSet_t : std::uint8_t {
        None = 0x0,
        Absolute = 0x1,
        Relative = 0x2,
    };

    enum class IChoreoServices_e : std::uint32_t {
        SCRIPT_PLAYING = 0x0,
        SCRIPT_WAIT = 0x1,
        SCRIPT_POST_IDLE = 0x2,
        SCRIPT_CLEANUP = 0x3,
        SCRIPT_MOVE_TO_MARK = 0x4,
    };

    enum class Touch_t : std::uint32_t {
        touch_none = 0x0,
        touch_player_only = 0x1,
        touch_npc_only = 0x2,
        touch_player_or_npc = 0x3,
        touch_player_or_npc_or_physicsprop = 0x4,
    };

    enum class CCSPlayerAnimationState_e : std::uint8_t {
        None = 0x0,
        Ground = 0x1,
        Air = 0x2,
        Ladder = 0x3,
    };

    enum class TrainVelocityType_t : std::uint32_t {
        TrainVelocity_Instantaneous = 0x0,
        TrainVelocity_LinearBlend = 0x1,
        TrainVelocity_EaseInEaseOut = 0x2,
    };

    enum class CSWeaponType : std::uint32_t {
        WEAPONTYPE_KNIFE = 0x0,
        WEAPONTYPE_PISTOL = 0x1,
        WEAPONTYPE_SUBMACHINEGUN = 0x2,
        WEAPONTYPE_RIFLE = 0x3,
        WEAPONTYPE_SHOTGUN = 0x4,
        WEAPONTYPE_SNIPER_RIFLE = 0x5,
        WEAPONTYPE_MACHINEGUN = 0x6,
        WEAPONTYPE_C4 = 0x7,
        WEAPONTYPE_TASER = 0x8,
        WEAPONTYPE_GRENADE = 0x9,
        WEAPONTYPE_EQUIPMENT = 0xA,
        WEAPONTYPE_STACKABLEITEM = 0xB,
        WEAPONTYPE_UNKNOWN = 0xC,
    };

    enum class NavScopeFlags_t : std::uint8_t {
        eGround = 0x1,
        eAir = 0x2,
        eAll = 0x3,
        eNone = 0x0,
    };

    enum class EntFinderMethod_t : std::uint32_t {
        ENT_FIND_METHOD_NEAREST = 0x0,
        ENT_FIND_METHOD_FARTHEST = 0x1,
        ENT_FIND_METHOD_RANDOM = 0x2,
    };

    enum class TestInputOutputCombinationsEnum_t : std::uint32_t {
        ZERO = 0x0,
        ONE = 0x1,
        TWO = 0x2,
    };

    enum class FuncMoverMovementSummaryFlags_t : std::uint32_t {
        eNone = 0x0,
        eMovementBegin = 0x1,
        eStopBegin = 0x2,
        eStopComplete = 0x4,
        eReversing = 0x8,
        eEventsDispatched = 0x10,
    };

    enum class PropDoorRotatingSpawnPos_t : std::uint32_t {
        DOOR_SPAWN_CLOSED = 0x0,
        DOOR_SPAWN_OPEN_FORWARD = 0x1,
        DOOR_SPAWN_OPEN_BACK = 0x2,
        DOOR_SPAWN_AJAR = 0x3,
    };

    enum class ShardSolid_t : std::uint8_t {
        SHARD_SOLID = 0x0,
        SHARD_DEBRIS = 0x1,
    };

    enum class EntityPlatformTypes_t : std::uint8_t {
        ENTITY_NOT_PLATFORM = 0x0,
        ENTITY_PLATFORM_PLAYER_FOLLOWS_YAW = 0x1,
        ENTITY_PLATFORM_PLAYER_IGNORES_YAW = 0x2,
    };

    enum class PulseNPCCondition_t : std::uint32_t {
        COND_SEE_PLAYER = 0x1,
        COND_LOST_PLAYER = 0x2,
        COND_HEAR_PLAYER = 0x3,
        COND_PLAYER_PUSHING = 0x4,
        COND_NO_PRIMARY_AMMO = 0x5,
    };

    enum class RenderMode_t : std::uint8_t {
        kRenderNormal = 0x0,
        kRenderTransAlpha = 0x1,
        kRenderNone = 0x2,
        kRenderModeCount = 0x3,
    };

    enum class ForcedCrouchState_t : std::uint32_t {
        FORCEDCROUCH_NONE = 0x0,
        FORCEDCROUCH_CROUCHED = 0x1,
        FORCEDCROUCH_UNCROUCHED = 0x2,
    };

    enum class PerformanceMode_t : std::uint32_t {
        PM_NORMAL = 0x0,
        PM_NO_GIBS = 0x1,
    };

    enum class TOGGLE_STATE : std::uint32_t {
        TS_AT_TOP = 0x0,
        TS_AT_BOTTOM = 0x1,
        TS_GOING_UP = 0x2,
        TS_GOING_DOWN = 0x3,
        DOOR_OPEN = 0x0,
        DOOR_CLOSED = 0x1,
        DOOR_OPENING = 0x2,
        DOOR_CLOSING = 0x3,
    };

    enum class loadout_slot_t : std::int32_t {
        LOADOUT_SLOT_PROMOTED = -2,
        LOADOUT_SLOT_INVALID = -1,
        LOADOUT_SLOT_MELEE = 0x0,
        LOADOUT_SLOT_C4 = 0x1,
        LOADOUT_SLOT_FIRST_AUTO_BUY_WEAPON = 0x0,
        LOADOUT_SLOT_LAST_AUTO_BUY_WEAPON = 0x1,
        LOADOUT_SLOT_SECONDARY0 = 0x2,
        LOADOUT_SLOT_SECONDARY1 = 0x3,
        LOADOUT_SLOT_SECONDARY2 = 0x4,
        LOADOUT_SLOT_SECONDARY3 = 0x5,
        LOADOUT_SLOT_SECONDARY4 = 0x6,
        LOADOUT_SLOT_SECONDARY5 = 0x7,
        LOADOUT_SLOT_SMG0 = 0x8,
        LOADOUT_SLOT_SMG1 = 0x9,
        LOADOUT_SLOT_SMG2 = 0xA,
        LOADOUT_SLOT_SMG3 = 0xB,
        LOADOUT_SLOT_SMG4 = 0xC,
        LOADOUT_SLOT_SMG5 = 0xD,
        LOADOUT_SLOT_RIFLE0 = 0xE,
        LOADOUT_SLOT_RIFLE1 = 0xF,
        LOADOUT_SLOT_RIFLE2 = 0x10,
        LOADOUT_SLOT_RIFLE3 = 0x11,
        LOADOUT_SLOT_RIFLE4 = 0x12,
        LOADOUT_SLOT_RIFLE5 = 0x13,
        LOADOUT_SLOT_HEAVY0 = 0x14,
        LOADOUT_SLOT_HEAVY1 = 0x15,
        LOADOUT_SLOT_HEAVY2 = 0x16,
        LOADOUT_SLOT_HEAVY3 = 0x17,
        LOADOUT_SLOT_HEAVY4 = 0x18,
        LOADOUT_SLOT_HEAVY5 = 0x19,
        LOADOUT_SLOT_FIRST_WHEEL_WEAPON = 0x2,
        LOADOUT_SLOT_LAST_WHEEL_WEAPON = 0x19,
        LOADOUT_SLOT_FIRST_PRIMARY_WEAPON = 0x8,
        LOADOUT_SLOT_LAST_PRIMARY_WEAPON = 0x19,
        LOADOUT_SLOT_FIRST_WHEEL_GRENADE = 0x1A,
        LOADOUT_SLOT_GRENADE0 = 0x1A,
        LOADOUT_SLOT_GRENADE1 = 0x1B,
        LOADOUT_SLOT_GRENADE2 = 0x1C,
        LOADOUT_SLOT_GRENADE3 = 0x1D,
        LOADOUT_SLOT_GRENADE4 = 0x1E,
        LOADOUT_SLOT_GRENADE5 = 0x1F,
        LOADOUT_SLOT_LAST_WHEEL_GRENADE = 0x1F,
        LOADOUT_SLOT_EQUIPMENT0 = 0x20,
        LOADOUT_SLOT_EQUIPMENT1 = 0x21,
        LOADOUT_SLOT_EQUIPMENT2 = 0x22,
        LOADOUT_SLOT_EQUIPMENT3 = 0x23,
        LOADOUT_SLOT_EQUIPMENT4 = 0x24,
        LOADOUT_SLOT_EQUIPMENT5 = 0x25,
        LOADOUT_SLOT_FIRST_WHEEL_EQUIPMENT = 0x20,
        LOADOUT_SLOT_LAST_WHEEL_EQUIPMENT = 0x25,
        LOADOUT_SLOT_CLOTHING_CUSTOMPLAYER = 0x26,
        LOADOUT_SLOT_CLOTHING_CUSTOMHEAD = 0x27,
        LOADOUT_SLOT_CLOTHING_FACEMASK = 0x28,
        LOADOUT_SLOT_CLOTHING_HANDS = 0x29,
        LOADOUT_SLOT_FIRST_COSMETIC = 0x29,
        LOADOUT_SLOT_LAST_COSMETIC = 0x29,
        LOADOUT_SLOT_CLOTHING_EYEWEAR = 0x2A,
        LOADOUT_SLOT_CLOTHING_HAT = 0x2B,
        LOADOUT_SLOT_CLOTHING_LOWERBODY = 0x2C,
        LOADOUT_SLOT_CLOTHING_TORSO = 0x2D,
        LOADOUT_SLOT_CLOTHING_APPEARANCE = 0x2E,
        LOADOUT_SLOT_MISC0 = 0x2F,
        LOADOUT_SLOT_MISC1 = 0x30,
        LOADOUT_SLOT_MISC2 = 0x31,
        LOADOUT_SLOT_MISC3 = 0x32,
        LOADOUT_SLOT_MISC4 = 0x33,
        LOADOUT_SLOT_MISC5 = 0x34,
        LOADOUT_SLOT_MISC6 = 0x35,
        LOADOUT_SLOT_MUSICKIT = 0x36,
        LOADOUT_SLOT_FLAIR0 = 0x37,
        LOADOUT_SLOT_SPRAY0 = 0x38,
        LOADOUT_SLOT_FIRST_ALL_CHARACTER = 0x36,
        LOADOUT_SLOT_LAST_ALL_CHARACTER = 0x38,
        LOADOUT_SLOT_COUNT = 0x39,
    };

    enum class EDestructiblePartDamagePassThroughType : std::uint32_t {
        Normal = 0x0,
        Absorb = 0x1,
        InvincibleAbsorb = 0x2,
        InvinciblePassthrough = 0x3,
    };

    enum class NavAttributeEnum : std::uint64_t {
        NAV_MESH_AVOID = 0x80,
        NAV_MESH_STAIRS = 0x1000,
        NAV_MESH_NON_ZUP = 0x8000,
        NAV_MESH_CROUCH_HEIGHT = 0x10000,
        NAV_MESH_NON_ZUP_TRANSITION = 0x20000,
        NAV_MESH_CRAWL_HEIGHT = 0x40000,
        NAV_MESH_CROUCH = 0x10000,
        NAV_MESH_JUMP = 0x2,
        NAV_MESH_NO_JUMP = 0x8,
        NAV_MESH_STOP = 0x10,
        NAV_MESH_RUN = 0x20,
        NAV_MESH_WALK = 0x40,
        NAV_MESH_TRANSIENT = 0x100,
        NAV_MESH_DONT_HIDE = 0x200,
        NAV_MESH_STAND = 0x400,
        NAV_MESH_NO_HOSTAGES = 0x800,
        NAV_MESH_NO_MERGE = 0x2000,
        NAV_MESH_OBSTACLE_TOP = 0x4000,
        NAV_ATTR_FIRST_GAME_INDEX = 0x13,
        NAV_ATTR_LAST_INDEX = 0x3F,
    };

    enum class MoveLinearAuthoredPos_t : std::uint32_t {
        MOVELINEAR_AUTHORED_AT_START_POSITION = 0x0,
        MOVELINEAR_AUTHORED_AT_OPEN_POSITION = 0x1,
        MOVELINEAR_AUTHORED_AT_CLOSED_POSITION = 0x2,
    };

    enum class InteractionPassive_t : std::uint32_t {
        INTERACT_PASSIVE_NONE = 0x0,
        INTERACT_PASSIVE_LOOKAT = 0x1,
        INTERACT_PASSIVE_SPEAK = 0x2,
    };

    enum class ValueRemapperMomentumType_t : std::uint32_t {
        MomentumType_None = 0x0,
        MomentumType_Friction = 0x1,
        MomentumType_SpringTowardSnapValue = 0x2,
        MomentumType_SpringAwayFromSnapValue = 0x3,
    };

    enum class Hull_t : std::uint32_t {
        HULL_HUMAN = 0x0,
        HULL_SMALL_CENTERED = 0x1,
        HULL_WIDE_HUMAN = 0x2,
        HULL_TINY = 0x3,
        HULL_MEDIUM = 0x4,
        HULL_TINY_CENTERED = 0x5,
        HULL_LARGE = 0x6,
        HULL_LARGE_CENTERED = 0x7,
        HULL_MEDIUM_TALL = 0x8,
        HULL_SMALL = 0x9,
        NUM_HULLS = 0xA,
        HULL_NONE = 0xB,
    };

    enum class ExternalAnimGraphInactiveBehavior_t : std::uint8_t {
        eNone = 0x0,
        eUnbind = 0x1,
        eUnbindAndDelete = 0x2,
    };

    enum class BodySectionAuthority_t : std::uint32_t {
        eNone = 0x0,
        eLowerBody = 0x1,
        eUpperBody = 0x2,
        eFullBody = 0x3,
    };

    enum class ESceneRequestState_t : std::uint32_t {
        INACTIVE = 0x0,
        ACTIVE = 0x1,
        FINISHED = 0x2,
        FAILED = 0x3,
    };

    enum class CCSPlayerAnimationState_e2 : std::uint8_t {
        None = 0x0,
        Idle = 0x1,
        Start = 0x2,
        Move = 0x3,
        TurnOnSpot = 0x4,
        TurnOnSpotLoop = 0x5,
        PlantAndTurn = 0x6,
    };

    enum class PreviewWeaponState : std::uint32_t {
        DROPPED = 0x0,
        HOLSTERED = 0x1,
        DEPLOYED = 0x2,
        PLANTED = 0x3,
        INSPECT = 0x4,
        ICON = 0x5,
    };

    enum class EInButtonState : std::uint32_t {
        IN_BUTTON_UP = 0x0,
        IN_BUTTON_DOWN = 0x1,
        IN_BUTTON_DOWN_UP = 0x2,
        IN_BUTTON_UP_DOWN = 0x3,
        IN_BUTTON_UP_DOWN_UP = 0x4,
        IN_BUTTON_DOWN_UP_DOWN = 0x5,
        IN_BUTTON_DOWN_UP_DOWN_UP = 0x6,
        IN_BUTTON_UP_DOWN_UP_DOWN = 0x7,
        IN_BUTTON_STATE_COUNT = 0x8,
    };

    enum class BeamClipStyle_t : std::uint32_t {
        kNOCLIP = 0x0,
        kGEOCLIP = 0x1,
        kMODELCLIP = 0x2,
        kBEAMCLIPSTYLE_NUMBITS = 0x2,
    };

    enum class WeaponAttackType_t : std::int32_t {
        eInvalid = -1,
        ePrimary = 0x0,
        eSecondary = 0x1,
        eCount = 0x2,
    };

    enum class CDebugOverlayFilterTextType_t : std::uint32_t {
        FILTER_TEXT_NONE = 0x0,
        MATCH = 0x1,
        HIERARCHY = 0x2,
        COUNT = 0x3,
    };

    enum class CSPlayerBlockingUseAction_t : std::uint32_t {
        k_CSPlayerBlockingUseAction_None = 0x0,
        k_CSPlayerBlockingUseAction_DefusingDefault = 0x1,
        k_CSPlayerBlockingUseAction_DefusingWithKit = 0x2,
        k_CSPlayerBlockingUseAction_HostageGrabbing = 0x3,
        k_CSPlayerBlockingUseAction_HostageDropping = 0x4,
        k_CSPlayerBlockingUseAction_MapLongUseEntity_Pickup = 0x5,
        k_CSPlayerBlockingUseAction_MapLongUseEntity_Place = 0x6,
        k_CSPlayerBlockingUseAction_MaxCount = 0x7,
    };

    enum class ShatterDamageCause : std::uint8_t {
        SHATTERDAMAGE_BULLET = 0x0,
        SHATTERDAMAGE_MELEE = 0x1,
        SHATTERDAMAGE_THROWN = 0x2,
        SHATTERDAMAGE_SCRIPT = 0x3,
        SHATTERDAMAGE_EXPLOSIVE = 0x4,
    };

    enum class ScriptedOnDeath_t : std::int32_t {
        SS_ONDEATH_NOT_APPLICABLE = -1,
        SS_ONDEATH_UNDEFINED = 0x0,
        SS_ONDEATH_RAGDOLL = 0x1,
        SS_ONDEATH_ANIMATED_DEATH = 0x2,
    };

    enum class CSWeaponNameID : std::uint32_t {
        WEAPONID_GLOCK = 0x0,
        WEAPONID_HKP2000 = 0x1,
        WEAPONID_CZ75A = 0x2,
        WEAPONID_ELITE = 0x3,
        WEAPONID_DEAGLE = 0x4,
        WEAPONID_FIVESEVEN = 0x5,
        WEAPONID_P250 = 0x6,
        WEAPONID_REVOLVER = 0x7,
        WEAPONID_TEC9 = 0x8,
        WEAPONID_USP_SILENCER = 0x9,
        WEAPONID_AK47 = 0xA,
        WEAPONID_M4A1 = 0xB,
        WEAPONID_M4A1_SILENCER = 0xC,
        WEAPONID_FAMAS = 0xD,
        WEAPONID_GALILAR = 0xE,
        WEAPONID_AUG = 0xF,
        WEAPONID_SG556 = 0x10,
        WEAPONID_BIZON = 0x11,
        WEAPONID_MAC10 = 0x12,
        WEAPONID_MP5SD = 0x13,
        WEAPONID_MP7 = 0x14,
        WEAPONID_MP9 = 0x15,
        WEAPONID_P90 = 0x16,
        WEAPONID_UMP45 = 0x17,
        WEAPONID_MAG7 = 0x18,
        WEAPONID_NOVA = 0x19,
        WEAPONID_SAWEDOFF = 0x1A,
        WEAPONID_XM1014 = 0x1B,
        WEAPONID_AWP = 0x1C,
        WEAPONID_SSG08 = 0x1D,
        WEAPONID_G3SG1 = 0x1E,
        WEAPONID_SCAR20 = 0x1F,
        WEAPONID_M249 = 0x20,
        WEAPONID_NEGEV = 0x21,
        WEAPONID_TASER = 0x22,
        WEAPONID_DECOY = 0x23,
        WEAPONID_FLASHBANG = 0x24,
        WEAPONID_HEGRENADE = 0x25,
        WEAPONID_INCGRENADE = 0x26,
        WEAPONID_MOLOTOV = 0x27,
        WEAPONID_SMOKEGRENADE = 0x28,
        WEAPONID_C4 = 0x29,
        WEAPONID_HEALTHSHOT = 0x2A,
        WEAPONID_KNIFE = 0x2B,
        WEAPONID_KNIFE_T = 0x2C,
        WEAPONID_KNIFE_CSS = 0x2D,
        WEAPONID_KNIFE_FLIP = 0x2E,
        WEAPONID_KNIFE_GUT = 0x2F,
        WEAPONID_KNIFE_KARAMBIT = 0x30,
        WEAPONID_BAYONET = 0x31,
        WEAPONID_KNIFE_M9_BAYONET = 0x32,
        WEAPONID_KNIFE_TACTICAL = 0x33,
        WEAPONID_KNIFE_FALCHION = 0x34,
        WEAPONID_KNIFE_SURVIVAL_BOWIE = 0x35,
        WEAPONID_KNIFE_BUTTERFLY = 0x36,
        WEAPONID_KNIFE_PUSH = 0x37,
        WEAPONID_KNIFE_CORD = 0x38,
        WEAPONID_KNIFE_CANIS = 0x39,
        WEAPONID_KNIFE_URSUS = 0x3A,
        WEAPONID_KNIFE_GYPSY_JACKKNIFE = 0x3B,
        WEAPONID_KNIFE_OUTDOOR = 0x3C,
        WEAPONID_KNIFE_STILETTO = 0x3D,
        WEAPONID_KNIFE_WIDOWMAKER = 0x3E,
        WEAPONID_KNIFE_SKELETON = 0x3F,
        WEAPONID_KNIFE_KUKRI = 0x40,
        WEAPONID_UNKNOWN = 0x41,
    };

    enum class ChoreoLookAtSpeed_t : std::int32_t {
        eInvalid = -1,
        eSlow = 0x0,
        eMedium = 0x1,
        eFast = 0x2,
    };

    enum class gear_slot_t : std::int32_t {
        GEAR_SLOT_INVALID = -1,
        GEAR_SLOT_RIFLE = 0x0,
        GEAR_SLOT_PISTOL = 0x1,
        GEAR_SLOT_KNIFE = 0x2,
        GEAR_SLOT_GRENADES = 0x3,
        GEAR_SLOT_C4 = 0x4,
        GEAR_SLOT_RESERVED_SLOT6 = 0x5,
        GEAR_SLOT_RESERVED_SLOT7 = 0x6,
        GEAR_SLOT_RESERVED_SLOT8 = 0x7,
        GEAR_SLOT_RESERVED_SLOT9 = 0x8,
        GEAR_SLOT_RESERVED_SLOT10 = 0x9,
        GEAR_SLOT_RESERVED_SLOT11 = 0xA,
        GEAR_SLOT_BOOSTS = 0xB,
        GEAR_SLOT_UTILITY = 0xC,
        GEAR_SLOT_COUNT = 0xD,
        GEAR_SLOT_FIRST = 0x0,
        GEAR_SLOT_LAST = 0xC,
    };

    enum class CSPlayerState : std::uint32_t {
        STATE_ACTIVE = 0x0,
        STATE_WELCOME = 0x1,
        STATE_PICKINGTEAM = 0x2,
        STATE_PICKINGCLASS = 0x3,
        STATE_DEATH_ANIM = 0x4,
        STATE_DEATH_WAIT_FOR_KEY = 0x5,
        STATE_OBSERVER_MODE = 0x6,
        STATE_GUNGAME_RESPAWN = 0x7,
        STATE_DORMANT = 0x8,
        NUM_PLAYER_STATES = 0x9,
    };

    enum class ScriptedConflictResponse_t : std::uint32_t {
        SS_CONFLICT_ENQUEUE = 0x0,
        SS_CONFLICT_INTERRUPT = 0x1,
    };

    enum class WaterLevel_t : std::uint8_t {
        WL_NotInWater = 0x0,
        WL_Feet = 0x1,
        WL_Knees = 0x2,
        WL_Waist = 0x3,
        WL_Chest = 0x4,
        WL_FullyUnderwater = 0x5,
        WL_Count = 0x6,
    };

    enum class WorldTextPanelVerticalAlign_t : std::uint32_t {
        WORLDTEXT_VERTICAL_ALIGN_TOP = 0x0,
        WORLDTEXT_VERTICAL_ALIGN_CENTER = 0x1,
        WORLDTEXT_VERTICAL_ALIGN_BOTTOM = 0x2,
    };

    enum class RelativeLocationType_t : std::uint8_t {
        WORLD_SPACE_POSITION = 0x0,
        RELATIVE_TO_ENTITY_IN_LOCAL_SPACE = 0x1,
        RELATIVE_TO_ENTITY_YAW_ONLY = 0x2,
        RELATIVE_TO_ENTITY_IN_WORLD_SPACE = 0x3,
    };

    enum class AmmoPosition_t : std::int32_t {
        AMMO_POSITION_INVALID = -1,
        AMMO_POSITION_PRIMARY = 0x0,
        AMMO_POSITION_SECONDARY = 0x1,
        AMMO_POSITION_COUNT = 0x2,
    };

    enum class CDebugOverlayFilterType_t : std::int32_t {
        NONE = 0x0,
        TEXT = 0x1,
        ENTITY = 0x2,
        COUNT = 0x3,
        TACTICAL_SEARCH = 0x4,
        AI_SCHEDULE = 0x5,
        AI_TASK = 0x6,
        AI_EVENT = 0x7,
        AI_PATHFINDING = 0x8,
        END_SIM_HISTORY_TYPES = 0x9,
        COMBINED = -1,
    };

    enum class ENPCBehaviorOverride_t : std::uint32_t {
        eKeepExisting = 0x0,
        eTakeOver = 0x1,
    };

    enum class PreviewEOMCelebration : std::int32_t {
        INVALID = -1,
        WALKUP = 0x0,
        PUNCHING = 0x1,
        SWAGGER = 0x2,
        DROPDOWN = 0x3,
        STRETCH = 0x4,
        SWAT_FEMALE = 0x5,
        MASK_F = 0x6,
        GUERILLA = 0x7,
        GUERILLA02 = 0x8,
        GENDARMERIE = 0x9,
        SCUBA_FEMALE = 0xA,
        SCUBA_MALE = 0xB,
        AVA_DEFEAT = 0xC,
        GENDARMERIE_DEFEAT = 0xD,
        MAE_DEFEAT = 0xE,
        RICKSAW_DEFEAT = 0xF,
        SCUBA_FEMALE_DEFEAT = 0x10,
        SCUBA_MALE_DEFEAT = 0x11,
        CRASSWATER_DEFEAT = 0x12,
        DARRYL_DEFEAT = 0x13,
        DOCTOR_DEFEAT = 0x14,
        MUHLIK_DEFEAT = 0x15,
        VYPA_DEFEAT = 0x16,
    };

    enum class EntityDisolveType_t : std::int32_t {
        ENTITY_DISSOLVE_INVALID = -1,
        ENTITY_DISSOLVE_NORMAL = 0x0,
        ENTITY_DISSOLVE_ELECTRICAL = 0x1,
        ENTITY_DISSOLVE_ELECTRICAL_LIGHT = 0x2,
        ENTITY_DISSOLVE_CORE = 0x3,
    };

    enum class SaveRestoreTableFlags_t : std::uint32_t {
        FENTTABLE_NONE = 0x0,
        FENTTABLE_PLAYER = 0x80000000,
        FENTTABLE_REMOVED = 0x40000000,
        FENTTABLE_MOVEABLE = 0x20000000,
        FENTTABLE_GLOBAL = 0x10000000,
        FENTTABLE_PLAYERCHILD = 0x8000000,
        LEVELMASK_BIT_0 = 0x1,
        LEVELMASK_BIT_1 = 0x2,
        LEVELMASK_BIT_2 = 0x4,
        LEVELMASK_BIT_3 = 0x8,
        LEVELMASK_BIT_4 = 0x10,
        LEVELMASK_BIT_5 = 0x20,
        LEVELMASK_BIT_6 = 0x40,
        LEVELMASK_BIT_7 = 0x80,
        LEVELMASK_BIT_8 = 0x100,
        LEVELMASK_BIT_9 = 0x200,
        LEVELMASK_BIT_10 = 0x400,
        LEVELMASK_BIT_11 = 0x800,
        LEVELMASK_BIT_12 = 0x1000,
        LEVELMASK_BIT_13 = 0x2000,
        LEVELMASK_BIT_14 = 0x4000,
        LEVELMASK_BIT_15 = 0x8000,
    };

    enum class InputBitMask_t : std::int64_t {
        IN_NONE = 0x0,
        IN_ALL = -1,
        IN_ATTACK = 0x1,
        IN_JUMP = 0x2,
        IN_DUCK = 0x4,
        IN_FORWARD = 0x8,
        IN_BACK = 0x10,
        IN_USE = 0x20,
        IN_TURNLEFT = 0x80,
        IN_TURNRIGHT = 0x100,
        IN_MOVELEFT = 0x200,
        IN_MOVERIGHT = 0x400,
        IN_ATTACK2 = 0x800,
        IN_RELOAD = 0x2000,
        IN_SPEED = 0x10000,
        IN_JOYAUTOSPRINT = 0x20000,
        IN_FIRST_MOD_SPECIFIC_BIT = 0x100000000,
        IN_USEORRELOAD = 0x100000000,
        IN_SCORE = 0x200000000,
        IN_ZOOM = 0x400000000,
        IN_LOOK_AT_WEAPON = 0x800000000,
    };

    enum class HitGroup_t : std::int32_t {
        HITGROUP_INVALID = -1,
        HITGROUP_GENERIC = 0x0,
        HITGROUP_HEAD = 0x1,
        HITGROUP_CHEST = 0x2,
        HITGROUP_STOMACH = 0x3,
        HITGROUP_LEFTARM = 0x4,
        HITGROUP_RIGHTARM = 0x5,
        HITGROUP_LEFTLEG = 0x6,
        HITGROUP_RIGHTLEG = 0x7,
        HITGROUP_NECK = 0x8,
        HITGROUP_UNUSED = 0x9,
        HITGROUP_GEAR = 0xA,
        HITGROUP_SPECIAL = 0xB,
        HITGROUP_COUNT = 0xC,
    };

    enum class ChickenActivity : std::uint32_t {
        IDLE = 0x0,
        SQUAT = 0x1,
        WALK = 0x2,
        RUN = 0x3,
        GLIDE = 0x4,
        LAND = 0x5,
        PANIC = 0x6,
        TRICK = 0x7,
        TURN_IN_PLACE = 0x8,
        FEED = 0x9,
        SLEEP = 0xA,
    };

    enum class PointWorldTextReorientMode_t : std::uint32_t {
        POINT_WORLD_TEXT_REORIENT_NONE = 0x0,
        POINT_WORLD_TEXT_REORIENT_AROUND_UP = 0x1,
    };

    enum class DebugOverlayBits_t : std::uint64_t {
        OVERLAY_TEXT_BIT = 0x1,
        OVERLAY_NAME_BIT = 0x2,
        OVERLAY_BBOX_BIT = 0x4,
        OVERLAY_PIVOT_BIT = 0x8,
        OVERLAY_MESSAGE_BIT = 0x10,
        OVERLAY_ABSBOX_BIT = 0x20,
        OVERLAY_RBOX_BIT = 0x40,
        OVERLAY_SHOW_BLOCKSLOS = 0x80,
        OVERLAY_ATTACHMENTS_BIT = 0x100,
        OVERLAY_INTERPOLATED_ATTACHMENTS_BIT = 0x200,
        OVERLAY_INTERPOLATED_PIVOT_BIT = 0x400,
        OVERLAY_SKELETON_BIT = 0x800,
        OVERLAY_INTERPOLATED_SKELETON_BIT = 0x1000,
        OVERLAY_TRIGGER_BOUNDS_BIT = 0x2000,
        OVERLAY_HITBOX_BIT = 0x4000,
        OVERLAY_INTERPOLATED_HITBOX_BIT = 0x8000,
        OVERLAY_AUTOAIM_BIT = 0x10000,
        OVERLAY_NPC_SELECTED_BIT = 0x20000,
        OVERLAY_JOINT_INFO_BIT = 0x40000,
        OVERLAY_NPC_ROUTE_BIT = 0x80000,
        OVERLAY_VISIBILITY_TRACES_BIT = 0x100000,
        OVERLAY_NPC_ENEMIES_BIT = 0x400000,
        OVERLAY_NPC_CONDITIONS_BIT = 0x800000,
        OVERLAY_NPC_COMBAT_BIT = 0x1000000,
        OVERLAY_NPC_TASK_BIT = 0x2000000,
        OVERLAY_NPC_BODYLOCATIONS = 0x4000000,
        OVERLAY_NPC_VIEWCONE_BIT = 0x8000000,
        OVERLAY_NPC_KILL_BIT = 0x10000000,
        OVERLAY_BUDDHA_MODE = 0x40000000,
        OVERLAY_NPC_STEERING_REGULATIONS = 0x80000000,
        OVERLAY_NPC_TASK_TEXT_BIT = 0x100000000,
        OVERLAY_PROP_DEBUG = 0x200000000,
        OVERLAY_NPC_RELATION_BIT = 0x400000000,
        OVERLAY_VIEWOFFSET = 0x800000000,
        OVERLAY_VCOLLIDE_WIREFRAME_BIT = 0x1000000000,
        OVERLAY_NPC_SCRIPTED_COMMANDS_BIT = 0x2000000000,
        OVERLAY_ACTORNAME_BIT = 0x4000000000,
        OVERLAY_NPC_CONDITIONS_TEXT_BIT = 0x8000000000,
        OVERLAY_NPC_ABILITY_RANGE_DEBUG_BIT = 0x10000000000,
        OVERLAY_MINIMAL_TEXT = 0x20000000000,
    };

    enum class AmmoFlags_t : std::uint32_t {
        AMMO_FORCE_DROP_IF_CARRIED = 0x1,
        AMMO_RESERVE_STAYS_WITH_WEAPON = 0x2,
        AMMO_FLAG_MAX = 0x2,
    };

    enum class DecalFlags_t : std::uint32_t {
        eNone = 0x0,
        eCannotClear = 0x1,
        eDecalProjectToBackfaces = 0x2,
        eAll = 0xFFFFFFFF,
        eAllButCannotClear = 0xFFFFFFFE,
    };

    enum class HierarchyType_t : std::uint32_t {
        HIERARCHY_NONE = 0x0,
        HIERARCHY_BONE_MERGE = 0x1,
        HIERARCHY_ATTACHMENT = 0x2,
        HIERARCHY_ABSORIGIN = 0x3,
        HIERARCHY_BONE = 0x4,
        HIERARCHY_TYPE_COUNT = 0x5,
    };

    enum class doorCheck_e : std::uint32_t {
        DOOR_CHECK_FORWARD = 0x0,
        DOOR_CHECK_BACKWARD = 0x1,
        DOOR_CHECK_FULL = 0x2,
    };

    enum class BeamType_t : std::uint32_t {
        BEAM_INVALID = 0x0,
        BEAM_POINTS = 0x1,
        BEAM_ENTPOINT = 0x2,
        BEAM_ENTS = 0x3,
        BEAM_HOSE = 0x4,
        BEAM_SPLINE = 0x5,
        BEAM_LASER = 0x6,
    };

    enum class EntitySubclassScope_t : std::int32_t {
        SUBCLASS_SCOPE_NONE = -1,
        SUBCLASS_SCOPE_PRECIPITATION = 0x0,
        SUBCLASS_SCOPE_PLAYER_WEAPONS = 0x1,
        SUBCLASS_SCOPE_COUNT = 0x2,
    };

    enum class PointTemplateClientOnlyEntityBehavior_t : std::uint32_t {
        CREATE_FOR_CURRENTLY_CONNECTED_CLIENTS_ONLY = 0x0,
        CREATE_FOR_CLIENTS_WHO_CONNECT_LATER = 0x1,
    };

    enum class CDebugOverlayCombinedTypes_t : std::uint32_t {
        ALL = 0x0,
        ANY = 0x1,
        COUNT = 0x2,
    };

    enum class ShatterGlassStressType : std::uint8_t {
        SHATTERGLASS_BLUNT = 0x0,
        SHATTERGLASS_BALLISTIC = 0x1,
        SHATTERGLASS_PULSE = 0x2,
        SHATTERGLASS_EXPLOSIVE = 0x3,
    };

    enum class TrackOrientationType_t : std::uint32_t {
        TrackOrientation_Fixed = 0x0,
        TrackOrientation_FacePath = 0x1,
        TrackOrientation_FacePathAngles = 0x2,
    };

    enum class WeaponSwitchReason_t : std::uint32_t {
        eDrawn = 0x0,
        eEquipped = 0x1,
        eUserInitiatedSwitchToLast = 0x2,
        eUserInitiatedUIKeyPress = 0x3,
        eUserInitiatedSwitchHands = 0x4,
    };

    enum class ValueRemapperRatchetType_t : std::uint32_t {
        RatchetType_Absolute = 0x0,
        RatchetType_EachEngage = 0x1,
    };

    enum class NavDirType : std::uint32_t {
        NORTH = 0x0,
        EAST = 0x1,
        SOUTH = 0x2,
        WEST = 0x3,
        NUM_NAV_DIR_TYPE_DIRECTIONS = 0x4,
    };

    enum class CRR_Response_e : std::uint32_t {
        MAX_RESPONSE_NAME = 0xC0,
        MAX_RULE_NAME = 0x80,
    };

    enum class MoveMountingAmount_t : std::uint32_t {
        MOVE_MOUNT_NONE = 0x0,
        MOVE_MOUNT_LOW = 0x1,
        MOVE_MOUNT_HIGH = 0x2,
        MOVE_MOUNT_MAXCOUNT = 0x3,
    };

    enum class HoverPoseFlags_t : std::uint8_t {
        eNone = 0x0,
        ePosition = 0x1,
        eAngles = 0x2,
    };

    enum class RenderFx_t : std::uint8_t {
        kRenderFxNone = 0x0,
        kRenderFxPulseSlow = 0x1,
        kRenderFxPulseFast = 0x2,
        kRenderFxPulseSlowWide = 0x3,
        kRenderFxPulseFastWide = 0x4,
        kRenderFxFadeSlow = 0x5,
        kRenderFxFadeFast = 0x6,
        kRenderFxSolidSlow = 0x7,
        kRenderFxSolidFast = 0x8,
        kRenderFxStrobeSlow = 0x9,
        kRenderFxStrobeFast = 0xA,
        kRenderFxStrobeFaster = 0xB,
        kRenderFxFlickerSlow = 0xC,
        kRenderFxFlickerFast = 0xD,
        kRenderFxFadeOut = 0xE,
        kRenderFxFadeIn = 0xF,
        kRenderFxPulseFastWider = 0x10,
        kRenderFxMax = 0x11,
    };

    enum class vote_create_failed_t : std::uint32_t {
        VOTE_FAILED_GENERIC = 0x0,
        VOTE_FAILED_TRANSITIONING_PLAYERS = 0x1,
        VOTE_FAILED_RATE_EXCEEDED = 0x2,
        VOTE_FAILED_YES_MUST_EXCEED_NO = 0x3,
        VOTE_FAILED_QUORUM_FAILURE = 0x4,
        VOTE_FAILED_ISSUE_DISABLED = 0x5,
        VOTE_FAILED_MAP_NOT_FOUND = 0x6,
        VOTE_FAILED_MAP_NAME_REQUIRED = 0x7,
        VOTE_FAILED_FAILED_RECENTLY = 0x8,
        VOTE_FAILED_TEAM_CANT_CALL = 0x9,
        VOTE_FAILED_WAITINGFORPLAYERS = 0xA,
        VOTE_FAILED_PLAYERNOTFOUND = 0xB,
        VOTE_FAILED_CANNOT_KICK_ADMIN = 0xC,
        VOTE_FAILED_SCRAMBLE_IN_PROGRESS = 0xD,
        VOTE_FAILED_SPECTATOR = 0xE,
        VOTE_FAILED_FAILED_RECENT_KICK = 0xF,
        VOTE_FAILED_FAILED_RECENT_CHANGEMAP = 0x10,
        VOTE_FAILED_FAILED_RECENT_SWAPTEAMS = 0x11,
        VOTE_FAILED_FAILED_RECENT_SCRAMBLETEAMS = 0x12,
        VOTE_FAILED_FAILED_RECENT_RESTART = 0x13,
        VOTE_FAILED_SWAP_IN_PROGRESS = 0x14,
        VOTE_FAILED_DISABLED = 0x15,
        VOTE_FAILED_NEXTLEVEL_SET = 0x16,
        VOTE_FAILED_TOO_EARLY_SURRENDER = 0x17,
        VOTE_FAILED_MATCH_PAUSED = 0x18,
        VOTE_FAILED_MATCH_NOT_PAUSED = 0x19,
        VOTE_FAILED_NOT_IN_WARMUP = 0x1A,
        VOTE_FAILED_NOT_10_PLAYERS = 0x1B,
        VOTE_FAILED_TIMEOUT_ACTIVE = 0x1C,
        VOTE_FAILED_TIMEOUT_INACTIVE = 0x1D,
        VOTE_FAILED_TIMEOUT_EXHAUSTED = 0x1E,
        VOTE_FAILED_CANT_ROUND_END = 0x1F,
        VOTE_FAILED_REMATCH = 0x20,
        VOTE_FAILED_CONTINUE = 0x21,
        VOTE_FAILED_MAX = 0x22,
    };

    enum class RumbleEffect_t : std::int32_t {
        RUMBLE_INVALID = -1,
        RUMBLE_STOP_ALL = 0x0,
        RUMBLE_PISTOL = 0x1,
        RUMBLE_357 = 0x2,
        RUMBLE_SMG1 = 0x3,
        RUMBLE_AR2 = 0x4,
        RUMBLE_SHOTGUN_SINGLE = 0x5,
        RUMBLE_SHOTGUN_DOUBLE = 0x6,
        RUMBLE_AR2_ALT_FIRE = 0x7,
        RUMBLE_RPG_MISSILE = 0x8,
        RUMBLE_CROWBAR_SWING = 0x9,
        RUMBLE_AIRBOAT_GUN = 0xA,
        RUMBLE_JEEP_ENGINE_LOOP = 0xB,
        RUMBLE_FLAT_LEFT = 0xC,
        RUMBLE_FLAT_RIGHT = 0xD,
        RUMBLE_FLAT_BOTH = 0xE,
        RUMBLE_DMG_LOW = 0xF,
        RUMBLE_DMG_MED = 0x10,
        RUMBLE_DMG_HIGH = 0x11,
        RUMBLE_FALL_LONG = 0x12,
        RUMBLE_FALL_SHORT = 0x13,
        RUMBLE_PHYSCANNON_OPEN = 0x14,
        RUMBLE_PHYSCANNON_PUNT = 0x15,
        RUMBLE_PHYSCANNON_LOW = 0x16,
        RUMBLE_PHYSCANNON_MEDIUM = 0x17,
        RUMBLE_PHYSCANNON_HIGH = 0x18,
        NUM_RUMBLE_EFFECTS = 0x19,
    };

    enum class LatchDirtyPermission_t : std::uint32_t {
        LATCH_DIRTY_DISALLOW = 0x0,
        LATCH_DIRTY_SERVER_CONTROLLED = 0x1,
        LATCH_DIRTY_CLIENT_SIMULATED = 0x2,
        LATCH_DIRTY_PREDICTION = 0x3,
        LATCH_DIRTY_FRAMESIMULATE = 0x4,
        LATCH_DIRTY_PARTICLE_SIMULATE = 0x5,
    };

    enum class DoorState_t : std::uint32_t {
        DOOR_STATE_CLOSED = 0x0,
        DOOR_STATE_OPENING = 0x1,
        DOOR_STATE_OPEN = 0x2,
        DOOR_STATE_CLOSING = 0x3,
        DOOR_STATE_AJAR = 0x4,
    };

    enum class ChoreoLookAtMode_t : std::int32_t {
        eInvalid = -1,
        eChest = 0x0,
        eHead = 0x1,
        eEyesOnly = 0x2,
    };

    enum class ChatIgnoreType_t : std::uint32_t {
        CHAT_IGNORE_NONE = 0x0,
        CHAT_IGNORE_ALL = 0x1,
        CHAT_IGNORE_TEAM = 0x2,
    };

    enum class PlayerConnectedState : std::int32_t {
        NeverConnected = -1,
        Connected = 0x0,
        Connecting = 0x1,
        Reconnecting = 0x2,
        Disconnecting = 0x3,
        Disconnected = 0x4,
        Reserved = 0x5,
    };

    enum class PreviewCharacterBannerAnimation : std::int32_t {
        INVALID = -1,
        IDLE_OFFSCREEN = 0x0,
        BANNER_AWP_ACE_GUN = 0x1,
        BANNER_AWP_ACE_A = 0x2,
        BANNER_AWP_ACE_B = 0x3,
        BANNER_AWP_ACE_C = 0x4,
        BANNER_AWP_ACE_D = 0x5,
        BANNER_AWP_ACE_E = 0x6,
        BANNER_PISTOL3SHOT = 0x7,
        BANNER_3SHOT_A = 0x8,
        BANNER_3SHOT_B = 0x9,
        BANNER_3SHOT_C = 0xA,
        BANNER_PISTOL4SHOT = 0xB,
        BANNER_4SHOT_A = 0xC,
        BANNER_4SHOT_B = 0xD,
        BANNER_4SHOT_C = 0xE,
        BANNER_4SHOT_D = 0xF,
        CELEBRATE_STRETCH_NOWEAP_IDLE0 = 0x10,
        BANNER_BOMB_PLANT = 0x11,
        BANNER_BOMB_DEFUSAL_VER = 0x12,
        BANNER_FIRE = 0x13,
        BANNER_BOMB_BLAST_TOSS = 0x14,
        BANNER_BOMB_BLAST01 = 0x15,
        BANNER_BOMB_BLAST02 = 0x16,
        BANNER_BOMB_BLAST03 = 0x17,
        BANNER_CELEBRATE_01 = 0x18,
        BANNER_CELEBRATE_02 = 0x19,
        BANNER_CELEBRATE_03 = 0x1A,
        BANNER_CELEBRATE_04 = 0x1B,
    };

    enum class navproperties_t : std::uint32_t {
        NAV_IGNORE = 0x1,
    };

    enum class EntityEffects_t : std::uint16_t {
        DEPRICATED_EF_NOINTERP = 0x8,
        EF_NOSHADOW = 0x10,
        EF_NODRAW = 0x20,
        EF_NORECEIVESHADOW = 0x40,
        EF_PARENT_ANIMATES = 0x200,
        EF_NODRAW_BUT_TRANSMIT = 0x400,
        EF_MAX_BITS = 0xA,
    };

    enum class ChoreoExternalAnimgraphControlState_t : std::uint32_t {
        eNone = 0x0,
        eBegin = 0x1,
        eLooping = 0x2,
        eExit = 0x3,
        eAbort = 0x4,
        eCount = 0x5,
    };

    enum class SolidType_t : std::uint8_t {
        SOLID_NONE = 0x0,
        SOLID_BSP = 0x1,
        SOLID_BBOX = 0x2,
        SOLID_OBB = 0x3,
        SOLID_SPHERE = 0x4,
        SOLID_POINT = 0x5,
        SOLID_VPHYSICS = 0x6,
        SOLID_CAPSULE = 0x7,
        SOLID_LAST = 0x8,
    };

    enum class DamageTypes_t : std::uint32_t {
        DMG_GENERIC = 0x0,
        DMG_CRUSH = 0x1,
        DMG_BULLET = 0x2,
        DMG_SLASH = 0x4,
        DMG_BURN = 0x8,
        DMG_VEHICLE = 0x10,
        DMG_FALL = 0x20,
        DMG_BLAST = 0x40,
        DMG_CLUB = 0x80,
        DMG_SHOCK = 0x100,
        DMG_SONIC = 0x200,
        DMG_ENERGYBEAM = 0x400,
        DMG_BUCKSHOT = 0x800,
        DMG_BLAST_SURFACE = 0x1000,
        DMG_DISSOLVE = 0x2000,
        DMG_DROWN = 0x4000,
        DMG_POISON = 0x8000,
        DMG_RADIATION = 0x10000,
        DMG_DROWNRECOVER = 0x20000,
        DMG_ACID = 0x40000,
        DMG_LASTGENERICFLAG = 0x40000,
        DMG_HEADSHOT = 0x80000,
    };

    enum class PointWorldTextJustifyVertical_t : std::uint32_t {
        POINT_WORLD_TEXT_JUSTIFY_VERTICAL_BOTTOM = 0x0,
        POINT_WORLD_TEXT_JUSTIFY_VERTICAL_CENTER = 0x1,
        POINT_WORLD_TEXT_JUSTIFY_VERTICAL_TOP = 0x2,
    };

    enum class attributeprovidertypes_t : std::uint32_t {
        PROVIDER_GENERIC = 0x0,
        PROVIDER_WEAPON = 0x1,
    };

    enum class MoveCollide_t : std::uint8_t {
        MOVECOLLIDE_DEFAULT = 0x0,
        MOVECOLLIDE_FLY_BOUNCE = 0x1,
        MOVECOLLIDE_FLY_CUSTOM = 0x2,
        MOVECOLLIDE_FLY_SLIDE = 0x3,
        MOVECOLLIDE_COUNT = 0x4,
        MOVECOLLIDE_MAX_BITS = 0x3,
    };

    enum class IChoreoServices_e2 : std::uint32_t {
        STATE_PRE_SCRIPT = 0x0,
        STATE_WAIT_FOR_SCRIPT = 0x1,
        STATE_WALK_TO_MARK = 0x2,
        STATE_SYNCHRONIZE_SCRIPT = 0x3,
        STATE_PLAY_SCRIPT = 0x4,
        STATE_PLAY_SCRIPT_POST_IDLE = 0x5,
        STATE_PLAY_SCRIPT_POST_IDLE_DONE = 0x6,
    };

    enum class ValueRemapperOutputType_t : std::uint32_t {
        OutputType_AnimationCycle = 0x0,
        OutputType_RotationX = 0x1,
        OutputType_RotationY = 0x2,
        OutputType_RotationZ = 0x3,
    };

    enum class INavObstacle_e : std::int32_t {
        NAV_OBSTACLE_TYPE_INVALID = -1,
        NAV_OBSTACLE_TYPE_NONE = 0x0,
        NAV_OBSTACLE_TYPE_AVOID = 0x1,
        NAV_OBSTACLE_TYPE_CONN = 0x2,
        NAV_OBSTACLE_TYPE_BLOCK = 0x3,
    };

    enum class PointTemplateOwnerSpawnGroupType_t : std::uint32_t {
        INSERT_INTO_POINT_TEMPLATE_SPAWN_GROUP = 0x0,
        INSERT_INTO_CURRENTLY_ACTIVE_SPAWN_GROUP = 0x1,
        INSERT_INTO_NEWLY_CREATED_SPAWN_GROUP = 0x2,
    };

    enum class EContributionScoreFlag_t : std::uint8_t {
        k_EContributionScoreFlag_Default = 0x0,
        k_EContributionScoreFlag_Objective = 0x1,
        k_EContributionScoreFlag_Bullets = 0x2,
    };

    enum class CCSPlayerAnimationState_e3 : std::uint8_t {
        None = 0x0,
        N = 0x1,
        NE = 0x2,
        E = 0x3,
        SE = 0x4,
        S = 0x5,
        SW = 0x6,
        W = 0x7,
        NW = 0x8,
    };

    enum class eSplinePushType : std::uint32_t {
        k_eSplinePushAlong = 0x0,
        k_eSplinePushAway = 0x1,
        k_eSplinePushTowards = 0x2,
    };

    enum class WeaponGameplayAnimState : std::uint16_t {
        WPN_ANIMSTATE_UNINITIALIZED = 0x0,
        WPN_ANIMSTATE_DROPPED = 0x1,
        WPN_ANIMSTATE_HOLSTERED = 0xA,
        WPN_ANIMSTATE_DEPLOY = 0xB,
        WPN_ANIMSTATE_IDLE = 0x32,
        WPN_ANIMSTATE_SHOOT_PRIMARY = 0x64,
        WPN_ANIMSTATE_SHOOT_SECONDARY = 0x65,
        WPN_ANIMSTATE_SHOOT_DRYFIRE = 0x66,
        WPN_ANIMSTATE_CHARGE = 0x67,
        WPN_ANIMSTATE_GRENADE_PULL_PIN = 0xC8,
        WPN_ANIMSTATE_GRENADE_READY = 0xC9,
        WPN_ANIMSTATE_GRENADE_THROW = 0xCA,
        WPN_ANIMSTATE_C4_PLANT = 0x12C,
        WPN_ANIMSTATE_HEALTHSHOT_INJECT = 0x190,
        WPN_ANIMSTATE_KNIFE_PRIMARY_HIT = 0x1F4,
        WPN_ANIMSTATE_KNIFE_PRIMARY_MISS = 0x1F5,
        WPN_ANIMSTATE_KNIFE_SECONDARY_HIT = 0x1F6,
        WPN_ANIMSTATE_KNIFE_SECONDARY_MISS = 0x1F7,
        WPN_ANIMSTATE_KNIFE_PRIMARY_STAB = 0x1F8,
        WPN_ANIMSTATE_KNIFE_SECONDARY_STAB = 0x1F9,
        WPN_ANIMSTATE_SILENCER_APPLY = 0x258,
        WPN_ANIMSTATE_SILENCER_REMOVE = 0x259,
        WPN_ANIMSTATE_RELOAD = 0x320,
        WPN_ANIMSTATE_RELOAD_OUTRO = 0x321,
        WPN_ANIMSTATE_INSPECT = 0x3E8,
        WPN_ANIMSTATE_INSPECT_OUTRO = 0x3E9,
        WPN_ANIMSTATE_INVENTORY_UI_TUMBLE = 0x5DC,
        WPN_ANIMSTATE_INVENTORY_UI_KEYCHAIN_APPLY = 0x5DD,
        WPN_ANIMSTATE_END_VALID = 0x7D0,
    };

    enum class EDestructiblePartRadiusDamageApplyType : std::uint32_t {
        ScaleByExplosionRadius = 0x0,
        PrioritizeClosestPart = 0x1,
    };

    enum class EntityDistanceMode_t : std::uint32_t {
        eOriginToOrigin = 0x0,
        eCenterToCenter = 0x1,
        eAxisToAxis = 0x2,
    };

    enum class PulseTraceContents_t : std::uint32_t {
        STATIC_LEVEL = 0x0,
        SOLID = 0x1,
    };

    enum class PointWorldTextJustifyHorizontal_t : std::uint32_t {
        POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_LEFT = 0x0,
        POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_CENTER = 0x1,
        POINT_WORLD_TEXT_JUSTIFY_HORIZONTAL_RIGHT = 0x2,
    };

    enum class ShakeCommand_t : std::uint32_t {
        SHAKE_START = 0x0,
        SHAKE_STOP = 0x1,
        SHAKE_AMPLITUDE = 0x2,
        SHAKE_FREQUENCY = 0x3,
        SHAKE_START_RUMBLEONLY = 0x4,
        SHAKE_START_NORUMBLE = 0x5,
        SHAKE_DURATION = 0x6,
    };

    enum class Flags_t : std::uint32_t {
        FL_ONGROUND = 0x1,
        FL_DUCKING = 0x2,
        FL_WATERJUMP = 0x4,
        FL_BOT = 0x10,
        FL_FROZEN = 0x20,
        FL_ATCONTROLS = 0x40,
        FL_CLIENT = 0x80,
        FL_FAKECLIENT = 0x100,
        FL_FLY = 0x400,
        FL_SUPPRESS_SAVE = 0x800,
        FL_IN_VEHICLE = 0x1000,
        FL_GODMODE = 0x4000,
        FL_NOTARGET = 0x8000,
        FL_AIMTARGET = 0x10000,
        FL_GRENADE = 0x100000,
        FL_DONTTOUCH = 0x400000,
        FL_BASEVELOCITY = 0x800000,
        FL_CONVEYOR = 0x1000000,
        FL_OBJECT = 0x2000000,
        FL_ONFIRE = 0x8000000,
        FL_DISSOLVING = 0x10000000,
        FL_TRANSRAGDOLL = 0x20000000,
        FL_UNBLOCKABLE_BY_PLAYER = 0x40000000,
    };

    enum class TRAIN_CODE : std::uint32_t {
        TRAIN_SAFE = 0x0,
        TRAIN_BLOCKING = 0x1,
        TRAIN_FOLLOWING = 0x2,
    };

    enum class DestructiblePartDestructionDeathBehavior_t : std::uint32_t {
        eDoNotKill = 0x0,
        eKill = 0x1,
        eGib = 0x2,
        eRemove = 0x3,
    };

    enum class BrushSolidities_e : std::uint32_t {
        BRUSHSOLID_TOGGLE = 0x0,
        BRUSHSOLID_NEVER = 0x1,
        BRUSHSOLID_ALWAYS = 0x2,
    };

    enum class InteractionPriority_t : std::uint32_t {
        INTERACT_PRIORITY_NONE = 0x0,
        INTERACT_PRIORITY_PASSIVE = 0x1,
        INTERACT_PRIORITY_LOW = 0x2,
        INTERACT_PRIORITY_MED = 0x3,
        INTERACT_PRIORITY_HIGH = 0x4,
    };

    enum class QuestProgress_e : std::uint32_t {
        QUEST_NONINITIALIZED = 0x0,
        QUEST_OK = 0x1,
        QUEST_NOT_ENOUGH_PLAYERS = 0x2,
        QUEST_WARMUP = 0x3,
        QUEST_NOT_CONNECTED_TO_STEAM = 0x4,
        QUEST_NONOFFICIAL_SERVER = 0x5,
        QUEST_NO_ENTITLEMENT = 0x6,
        QUEST_NO_QUEST = 0x7,
        QUEST_PLAYER_IS_BOT = 0x8,
        QUEST_WRONG_MAP = 0x9,
        QUEST_WRONG_MODE = 0xA,
        QUEST_NOT_SYNCED_WITH_SERVER = 0xB,
        QUEST_REASON_MAX = 0xC,
    };

    enum class ModifyDamageReturn_t : std::uint32_t {
        CONTINUE_TO_APPLY_DAMAGE = 0x0,
        ABORT_DO_NOT_APPLY_DAMAGE = 0x1,
    };

    enum class ShadowType_t : std::uint32_t {
        SHADOWS_NONE = 0x0,
        SHADOWS_SIMPLE = 0x1,
    };

    enum class GrenadeType_t : std::uint32_t {
        GRENADE_TYPE_EXPLOSIVE = 0x0,
        GRENADE_TYPE_FLASH = 0x1,
        GRENADE_TYPE_FIRE = 0x2,
        GRENADE_TYPE_DECOY = 0x3,
        GRENADE_TYPE_SMOKE = 0x4,
        GRENADE_TYPE_TOTAL = 0x5,
    };

    enum class ValueRemapperInputType_t : std::uint32_t {
        InputType_PlayerShootPosition = 0x0,
        InputType_PlayerShootPositionAroundAxis = 0x1,
    };

    enum class EKillTypes_t : std::uint8_t {
        KILL_NONE = 0x0,
        KILL_DEFAULT = 0x1,
        KILL_HEADSHOT = 0x2,
        KILL_BLAST = 0x3,
        KILL_BURN = 0x4,
        KILL_SLASH = 0x5,
        KILL_SHOCK = 0x6,
        KILLTYPE_COUNT = 0x7,
    };

    enum class WeaponSound_t : std::uint32_t {
        WEAPON_SOUND_EMPTY = 0x0,
        WEAPON_SOUND_SECONDARY_EMPTY = 0x1,
        WEAPON_SOUND_SINGLE = 0x2,
        WEAPON_SOUND_SECONDARY_ATTACK = 0x3,
        WEAPON_SOUND_MELEE_MISS = 0x4,
        WEAPON_SOUND_MELEE_HIT = 0x5,
        WEAPON_SOUND_MELEE_HIT_WORLD = 0x6,
        WEAPON_SOUND_MELEE_HIT_PLAYER = 0x7,
        WEAPON_SOUND_MELEE_HIT_NPC = 0x8,
        WEAPON_SOUND_SPECIAL1 = 0x9,
        WEAPON_SOUND_SPECIAL2 = 0xA,
        WEAPON_SOUND_SPECIAL3 = 0xB,
        WEAPON_SOUND_NEARLYEMPTY = 0xC,
        WEAPON_SOUND_IMPACT = 0xD,
        WEAPON_SOUND_REFLECT = 0xE,
        WEAPON_SOUND_SECONDARY_IMPACT = 0xF,
        WEAPON_SOUND_SECONDARY_REFLECT = 0x10,
        WEAPON_SOUND_RELOAD = 0x11,
        WEAPON_SOUND_SINGLE_ACCURATE = 0x12,
        WEAPON_SOUND_ZOOM_IN = 0x13,
        WEAPON_SOUND_ZOOM_OUT = 0x14,
        WEAPON_SOUND_MOUSE_PRESSED = 0x15,
        WEAPON_SOUND_DROP = 0x16,
        WEAPON_SOUND_RADIO_USE = 0x17,
        WEAPON_SOUND_NUM_TYPES = 0x18,
    };

    enum class TakeDamageFlags_t : std::uint64_t {
        DFLAG_NONE = 0x0,
        DFLAG_SUPPRESS_HEALTH_CHANGES = 0x1,
        DFLAG_SUPPRESS_PHYSICS_FORCE = 0x2,
        DFLAG_SUPPRESS_EFFECTS = 0x4,
        DFLAG_PREVENT_DEATH = 0x8,
        DFLAG_FORCE_DEATH = 0x10,
        DFLAG_ALWAYS_GIB = 0x20,
        DFLAG_NEVER_GIB = 0x40,
        DFLAG_REMOVE_NO_RAGDOLL = 0x80,
        DFLAG_SUPPRESS_DAMAGE_MODIFICATION = 0x100,
        DFLAG_ALWAYS_FIRE_DAMAGE_EVENTS = 0x200,
        DFLAG_RADIUS_DMG = 0x400,
        DFLAG_FORCEREDUCEARMOR_DMG = 0x800,
        DFLAG_SUPPRESS_INTERRUPT_FLINCH = 0x1000,
        DFLAG_IGNORE_DESTRUCTIBLE_PARTS = 0x2000,
        DFLAG_SUPPRESS_BREAKABLES = 0x4000,
        DFLAG_FORCE_PHYSICS_FORCE = 0x8000,
        DFLAG_SUPPRESS_SCREENSPACE_DAMAGE_FX = 0x10000,
        DFLAG_ALLOW_NON_AUTHORITATIVE = 0x20000,
        DMG_LASTDFLAG = 0x20000,
        DFLAG_IGNORE_ARMOR = 0x40000,
        DFLAG_SUPPRESS_UTILREMOVE = 0x80000,
    };

    enum class ValueRemapperHapticsType_t : std::uint32_t {
        HaticsType_Default = 0x0,
        HaticsType_None = 0x1,
    };

    enum class Disposition_t : std::uint32_t {
        D_ER = 0x0,
        D_HT = 0x1,
        D_FR = 0x2,
        D_LI = 0x3,
        D_NU = 0x4,
        D_ERROR = 0x0,
        D_HATE = 0x1,
        D_FEAR = 0x2,
        D_LIKE = 0x3,
        D_NEUTRAL = 0x4,
    };

    enum class RotatorTargetSpace_t : std::uint32_t {
        ROTATOR_TARGET_WORLDSPACE = 0x0,
        ROTATOR_TARGET_LOCALSPACE = 0x1,
    };

    enum class CanPlaySequence_t : std::uint32_t {
        CANNOT_PLAY = 0x0,
        CAN_PLAY_NOW = 0x1,
        CAN_PLAY_ENQUEUED = 0x2,
    };

    enum class CCSPlayerAnimationState_e4 : std::uint8_t {
        None = 0x0,
        Jump = 0x1,
        StartFall = 0x2,
        Land = 0x3,
    };

    enum class MedalRank_t : std::uint32_t {
        MEDAL_RANK_NONE = 0x0,
        MEDAL_RANK_BRONZE = 0x1,
        MEDAL_RANK_SILVER = 0x2,
        MEDAL_RANK_GOLD = 0x3,
        MEDAL_RANK_COUNT = 0x4,
    };

    enum class ObserverMode_t : std::uint32_t {
        OBS_MODE_NONE = 0x0,
        OBS_MODE_FIXED = 0x1,
        OBS_MODE_IN_EYE = 0x2,
        OBS_MODE_CHASE = 0x3,
        OBS_MODE_ROAMING = 0x4,
        NUM_OBSERVER_MODES = 0x5,
    };

    enum class FuncDoorSpawnPos_t : std::uint32_t {
        FUNC_DOOR_SPAWN_CLOSED = 0x0,
        FUNC_DOOR_SPAWN_OPEN = 0x1,
    };

    enum class EOverrideBlockLOS_t : std::uint32_t {
        BLOCK_LOS_DEFAULT = 0x0,
        BLOCK_LOS_FORCE_FALSE = 0x1,
        BLOCK_LOS_FORCE_TRUE = 0x2,
    };

    enum class EntityAttachmentType_t : std::uint32_t {
        eAbsOrigin = 0x0,
        eCenter = 0x1,
        eEyes = 0x2,
        eAttachment = 0x3,
    };

    enum class MoveType_t : std::uint8_t {
        MOVETYPE_NONE = 0x0,
        MOVETYPE_OBSOLETE = 0x1,
        MOVETYPE_WALK = 0x2,
        MOVETYPE_FLY = 0x3,
        MOVETYPE_FLYGRAVITY = 0x4,
        MOVETYPE_VPHYSICS = 0x5,
        MOVETYPE_PUSH = 0x6,
        MOVETYPE_NOCLIP = 0x7,
        MOVETYPE_OBSERVER = 0x8,
        MOVETYPE_LADDER = 0x9,
        MOVETYPE_CUSTOM = 0xA,
        MOVETYPE_LAST = 0xB,
        MOVETYPE_INVALID = 0xB,
        MOVETYPE_MAX_BITS = 0x5,
    };

    class CFilterMultipleAPI {
    public:
    };

    class IChoreoServices {
    public:
    };

    class CPhysicsBodyGameMarkup {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_TargetBody                                    , 0x0)
        SCHEMA_FIELD(CGlobalSymbol                   , m_Tag                                           , 0x8)
    };

    class CPhysicsBodyGameMarkupData {
    public:
        using _Type0 = CUtlOrderedMap<CUtlString,CPhysicsBodyGameMarkup>;
        SCHEMA_FIELD(_Type0                          , m_PhysicsBodyMarkupByBoneName                   , 0x0)
    };

    class CPulseCell_LimitCount_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentCount                                 , 0x0)
    };

    class CSmoothFunc {
    public:
        SCHEMA_FIELD(float                           , m_flSmoothAmplitude                             , 0x8)
        SCHEMA_FIELD(float                           , m_flSmoothBias                                  , 0xC)
        SCHEMA_FIELD(float                           , m_flSmoothDuration                              , 0x10)
        SCHEMA_FIELD(float                           , m_flSmoothRemainingTime                         , 0x14)
        SCHEMA_FIELD(std::int32_t                    , m_nSmoothDir                                    , 0x18)
    };

    class CSceneCriteria {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOwner                                        , 0x0)
        SCHEMA_FIELD(InteractionPriority_t           , m_ePriority                                     , 0x4)
        SCHEMA_FIELD(SceneInterestTags_t             , m_InterestReqTags                               , 0x8)
        SCHEMA_FIELD(SceneInterestTags_t             , m_InterestOptTags                               , 0x20)
    };

    class CNavVolumeSphere {
    public:
        SCHEMA_FIELD(VectorWS                        , m_vCenter                                       , 0x78)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x84)
    };

    class CInfoChoreoAnchorPosition {
    public:
        SCHEMA_FIELD(::Vector                        , m_vOrigin                                       , 0x0)
        SCHEMA_FIELD(::QAngle                        , m_qAngles                                       , 0xC)
        SCHEMA_FIELD(::Vector                        , m_vExtentsMin                                   , 0x18)
        SCHEMA_FIELD(::Vector                        , m_vExtentsMax                                   , 0x24)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x30)
        SCHEMA_FIELD(CInfoChoreoLocatorShapeType_t   , m_nShapeType                                    , 0x34)
    };

    class CTestPulseIO_EntityHandleIntArgs_t {
    public:
        SCHEMA_FIELD(CEntityHandle                   , handleA                                         , 0x0)
        SCHEMA_FIELD(std::int32_t                    , valueB                                          , 0x4)
    };

    class ExternalAnimGraph_t {
    public:
        SCHEMA_FIELD(ExternalAnimGraphHandle_t       , m_hExtGraphHandle                               , 0x0)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sExternalGraphSlotID                          , 0x8)
        SCHEMA_FIELD(CStrongHandleCopyable<InfoForResourceTypeCNmGraphDefinition>, m_hGraphDefinition                              , 0x10)
        SCHEMA_FIELD(CHandle<CBaseAnimGraph>         , m_hExternalGraphOwner                           , 0x18)
        SCHEMA_FIELD(ExternalAnimGraphInactiveBehavior_t, m_nInactiveBehavior                             , 0x30)
    };

    class CPulseCell_Outflow_CycleRandom {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class CNetworkViewOffsetVector {
    public:
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecX                                          , 0x10)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecY                                          , 0x18)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecZ                                          , 0x20)
    };

    class CBaseEntityAPI {
    public:
    };

    class CPulseCell_Step_SetAnimGraphParam {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_ParamName                                     , 0x48)
    };

    class CPulseCell_Inflow_Method {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x80)
        SCHEMA_FIELD(::CUtlString                    , m_Description                                   , 0x90)
        SCHEMA_FIELD(bool                            , m_bIsPublic                                     , 0x98)
        SCHEMA_FIELD(CPulseValueFullType             , m_ReturnType                                    , 0xA0)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_Args                                          , 0xB8)
    };

    class CPulseCell_Outflow_CycleShuffled_InstanceState_t {
    public:
        using _Type0 = CUtlVectorFixedGrowable<uint8,8>;
        SCHEMA_FIELD(_Type0                          , m_Shuffle                                       , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nNextShuffle                                  , 0x20)
    };

    class HullFlags_t {
    public:
        SCHEMA_FIELD(bool                            , m_bHull_Human                                   , 0x0)
        SCHEMA_FIELD(bool                            , m_bHull_SmallCentered                           , 0x1)
        SCHEMA_FIELD(bool                            , m_bHull_WideHuman                               , 0x2)
        SCHEMA_FIELD(bool                            , m_bHull_Tiny                                    , 0x3)
        SCHEMA_FIELD(bool                            , m_bHull_Medium                                  , 0x4)
        SCHEMA_FIELD(bool                            , m_bHull_TinyCentered                            , 0x5)
        SCHEMA_FIELD(bool                            , m_bHull_Large                                   , 0x6)
        SCHEMA_FIELD(bool                            , m_bHull_LargeCentered                           , 0x7)
        SCHEMA_FIELD(bool                            , m_bHull_MediumTall                              , 0x8)
        SCHEMA_FIELD(bool                            , m_bHull_Small                                   , 0x9)
    };

    class CEntitySubclassVDataBase {
    public:
    };

    class CSoundPatch {
    public:
        SCHEMA_FIELD(CSoundEnvelope                  , m_pitch                                         , 0x8)
        SCHEMA_FIELD(CSoundEnvelope                  , m_volume                                        , 0x18)
        SCHEMA_FIELD(float                           , m_shutdownTime                                  , 0x3C)
        SCHEMA_FIELD(float                           , m_flLastTime                                    , 0x40)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundScriptName                            , 0x48)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEnt                                          , 0x50)
        SCHEMA_FIELD(CEntityIndex                    , m_soundEntityIndex                              , 0x54)
        SCHEMA_FIELD(VectorWS                        , m_soundOrigin                                   , 0x58)
        SCHEMA_FIELD(std::int32_t                    , m_isPlaying                                     , 0x64)
        SCHEMA_FIELD(CCopyRecipientFilter            , m_Filter                                        , 0x68)
        SCHEMA_FIELD(float                           , m_flCloseCaptionDuration                        , 0xA0)
        SCHEMA_FIELD(bool                            , m_bUpdatedSoundOrigin                           , 0xA4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszClassName                                  , 0xA8)
    };

    class CShatterGlassShard {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_hShardHandle                                  , 0x8)
        SCHEMA_FIELD(CUtlVector<Vector2D>            , m_vecPanelVertices                              , 0x10)
        SCHEMA_FIELD(::Vector2D                      , m_vLocalPanelSpaceOrigin                        , 0x28)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0x30)
        SCHEMA_FIELD(CHandle<CShatterGlassShardPhysics>, m_hPhysicsEntity                                , 0x38)
        SCHEMA_FIELD(CHandle<CFuncShatterglass>      , m_hParentPanel                                  , 0x3C)
        SCHEMA_FIELD(std::uint32_t                   , m_hParentShard                                  , 0x40)
        SCHEMA_FIELD(ShatterGlassStressType          , m_ShatterStressType                             , 0x44)
        SCHEMA_FIELD(::Vector                        , m_vecStressVelocity                             , 0x48)
        SCHEMA_FIELD(bool                            , m_bCreatedModel                                 , 0x54)
        SCHEMA_FIELD(float                           , m_flLongestEdge                                 , 0x58)
        SCHEMA_FIELD(float                           , m_flShortestEdge                                , 0x5C)
        SCHEMA_FIELD(float                           , m_flLongestAcross                               , 0x60)
        SCHEMA_FIELD(float                           , m_flShortestAcross                              , 0x64)
        SCHEMA_FIELD(float                           , m_flSumOfAllEdges                               , 0x68)
        SCHEMA_FIELD(float                           , m_flArea                                        , 0x6C)
        SCHEMA_FIELD(OnFrame                         , m_nOnFrameEdge                                  , 0x70)
        SCHEMA_FIELD(std::int32_t                    , m_nSubShardGeneration                           , 0x74)
        SCHEMA_FIELD(::Vector2D                      , m_vecAverageVertPosition                        , 0x78)
        SCHEMA_FIELD(bool                            , m_bAverageVertPositionIsValid                   , 0x80)
        SCHEMA_FIELD(::Vector2D                      , m_vecPanelSpaceStressPositionA                  , 0x84)
        SCHEMA_FIELD(::Vector2D                      , m_vecPanelSpaceStressPositionB                  , 0x8C)
        SCHEMA_FIELD(bool                            , m_bStressPositionAIsValid                       , 0x94)
        SCHEMA_FIELD(bool                            , m_bStressPositionBIsValid                       , 0x95)
        SCHEMA_FIELD(bool                            , m_bFlaggedForRemoval                            , 0x96)
        SCHEMA_FIELD(::GameTime_t                    , m_flPhysicsEntitySpawnedAtTime                  , 0x98)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntityHittingMe                              , 0x9C)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_vecNeighbors                                  , 0xA0)
    };

    class CPulseServerCursor {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hActivator                                    , 0xE8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hCaller                                       , 0xEC)
    };

    class AmmoTypeInfo_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nMaxCarry                                     , 0x10)
        SCHEMA_FIELD(CRangeInt                       , m_nSplashSize                                   , 0x1C)
        SCHEMA_FIELD(AmmoFlags_t                     , m_nFlags                                        , 0x24)
        SCHEMA_FIELD(float                           , m_flMass                                        , 0x28)
        SCHEMA_FIELD(CRangeFloat                     , m_flSpeed                                       , 0x2C)
    };

    class CPrecipitationVData {
    public:
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIParticleSystemDefinition>>, m_szParticlePrecipitationEffect                 , 0x28)
        SCHEMA_FIELD(float                           , m_flInnerDistance                               , 0x108)
        SCHEMA_FIELD(ParticleAttachment_t            , m_nAttachType                                   , 0x10C)
        SCHEMA_FIELD(bool                            , m_bBatchSameVolumeType                          , 0x110)
        SCHEMA_FIELD(std::int32_t                    , m_nRTEnvCP                                      , 0x114)
        SCHEMA_FIELD(std::int32_t                    , m_nRTEnvCPComponent                             , 0x118)
        SCHEMA_FIELD(::CUtlString                    , m_szModifier                                    , 0x120)
        SCHEMA_FIELD(std::int32_t                    , m_nUseSnapshotFromSurfaceGraph                  , 0x128)
        SCHEMA_FIELD(PrecipitationFilter_t           , m_snapshotFilter                                , 0x12C)
    };

    class CRetakeGameRules {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nMatchSeed                                    , 0x138)
        SCHEMA_FIELD(bool                            , m_bBlockersPresent                              , 0x13C)
        SCHEMA_FIELD(bool                            , m_bRoundInProgress                              , 0x13D)
        SCHEMA_FIELD(std::int32_t                    , m_iFirstSecondHalfRound                         , 0x140)
        SCHEMA_FIELD(std::int32_t                    , m_iBombSite                                     , 0x144)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hBombPlanter                                  , 0x148)
    };

    class CAI_ExpresserWithFollowup {
    public:
    };

    class CPulseCell_Inflow_EntOutputHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceEntity                                  , 0x80)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutput                                  , 0x90)
        SCHEMA_FIELD(CPulseValueFullType             , m_ExpectedParamType                             , 0xA0)
    };

    class CSceneOpportunity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOwner                                        , 0x0)
        SCHEMA_FIELD(SceneOpportunityHandle_t        , m_uHandle                                       , 0x4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strInteractVDataName                          , 0x8)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x10)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x11)
        SCHEMA_FIELD(InteractionPriority_t           , m_ePriority                                     , 0x14)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x18)
        SCHEMA_FIELD(SceneInterestTags_t             , m_LocalInterestReqTags                          , 0x20)
        SCHEMA_FIELD(SceneInterestTags_t             , m_LocalInterestOptTags                          , 0x38)
        SCHEMA_FIELD(float                           , m_flOwnerFOV                                    , 0x50)
        SCHEMA_FIELD(CUtlVector<SceneOpportunityActor_t>, m_ActorList                                     , 0x58)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLookTarget                                   , 0x70)
        SCHEMA_FIELD(float                           , m_flDuration                                    , 0x74)
        SCHEMA_FIELD(::GameTime_t                    , m_tStartTime                                    , 0x78)
        SCHEMA_FIELD(float                           , m_flCooldown                                    , 0x7C)
        SCHEMA_FIELD(::GameTime_t                    , m_tCooldownTime                                 , 0x80)
        SCHEMA_FIELD(std::int32_t                    , m_nRepeatCount                                  , 0x84)
        SCHEMA_FIELD(bool                            , m_bDisableOnExit                                , 0x88)
    };

    class CSceneEventInfo {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iLayer                                        , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_iPriority                                     , 0x4)
        SCHEMA_FIELD(HSequence                       , m_hSequence                                     , 0x8)
        SCHEMA_FIELD(float                           , m_flWeight                                      , 0xC)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCNmClip>, m_hAnimClip                                     , 0x10)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sAnimClipSlot                                 , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sAnimClipSlotWeight                           , 0x20)
        SCHEMA_FIELD(bool                            , m_bHasArrived                                   , 0x28)
        SCHEMA_FIELD(std::int32_t                    , m_nType                                         , 0x2C)
        SCHEMA_FIELD(::GameTime_t                    , m_flNext                                        , 0x30)
        SCHEMA_FIELD(bool                            , m_bIsGesture                                    , 0x34)
        SCHEMA_FIELD(bool                            , m_bShouldRemove                                 , 0x35)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget                                       , 0x5C)
        SCHEMA_FIELD(SceneEventId_t                  , m_nSceneEventId                                 , 0x60)
        SCHEMA_FIELD(bool                            , m_bClientSide                                   , 0x64)
        SCHEMA_FIELD(bool                            , m_bStarted                                      , 0x65)
    };

    class CGameSceneNode {
    public:
        SCHEMA_FIELD(CTransformWS                    , m_nodeToWorld                                   , 0x10)
        SCHEMA_FIELD(CEntityInstance*                , m_pOwner                                        , 0x30)
        SCHEMA_FIELD(CGameSceneNode*                 , m_pParent                                       , 0x38)
        SCHEMA_FIELD(CGameSceneNode*                 , m_pChild                                        , 0x40)
        SCHEMA_FIELD(CGameSceneNode*                 , m_pNextSibling                                  , 0x48)
        SCHEMA_FIELD(CGameSceneNodeHandle            , m_hParent                                       , 0x70)
        SCHEMA_FIELD(CNetworkOriginCellCoordQuantizedVector, m_vecOrigin                                     , 0x80)
        SCHEMA_FIELD(::QAngle                        , m_angRotation                                   , 0xB8)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0xC4)
        SCHEMA_FIELD(VectorWS                        , m_vecAbsOrigin                                  , 0xC8)
        SCHEMA_FIELD(::QAngle                        , m_angAbsRotation                                , 0xD4)
        SCHEMA_FIELD(float                           , m_flAbsScale                                    , 0xE0)
        SCHEMA_FIELD(std::int16_t                    , m_nParentAttachmentOrBone                       , 0xE4)
        SCHEMA_FIELD(bool                            , m_bDebugAbsOriginChanges                        , 0xE6)
        SCHEMA_FIELD(bool                            , m_bDormant                                      , 0xE7)
        SCHEMA_FIELD(bool                            , m_bForceParentToBeNetworked                     , 0xE8)

        SCHEMA_FIELD(std::uint8_t                    , m_nHierarchicalDepth                            , 0xEB)
        SCHEMA_FIELD(std::uint8_t                    , m_nHierarchyType                                , 0xEC)
        SCHEMA_FIELD(std::uint8_t                    , m_nDoNotSetAnimTimeInInvalidatePhysicsCount     , 0xED)
        SCHEMA_FIELD(CUtlStringToken                 , m_name                                          , 0xF0)
        SCHEMA_FIELD(CUtlStringToken                 , m_hierarchyAttachName                           , 0x104)
        SCHEMA_FIELD(float                           , m_flClientLocalScale                            , 0x108)
        SCHEMA_FIELD(::Vector                        , m_vRenderOrigin                                 , 0x10C)
    };

    class CSimpleSimTimer {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flNext                                        , 0x0)
        SCHEMA_FIELD(::WorldGroupId_t                , m_nWorldGroupId                                 , 0x4)
    };

    class CPulseTestScriptLib {
    public:
    };

    class CCSGameModeRules_Deathmatch {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flDMBonusStartTime                            , 0x30)
        SCHEMA_FIELD(float                           , m_flDMBonusTimeLength                           , 0x34)
        SCHEMA_FIELD(::CUtlString                    , m_sDMBonusWeapon                                , 0x38)
    };

    class ResponseContext_t {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszName                                       , 0x0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszValue                                      , 0x8)
        SCHEMA_FIELD(::GameTime_t                    , m_fExpirationTime                               , 0x10)
    };

    class DestructiblePartDamageRequest_t {
    public:
        SCHEMA_FIELD(HitGroup_t                      , m_nHitGroup                                     , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nDamageLevel                                  , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , m_nDesiredHealth                                , 0x8)
        SCHEMA_FIELD(EDestructibleParts_DestroyParameterFlags, m_nDestroyFlags                                 , 0xC)
        SCHEMA_FIELD(DamageTypes_t                   , m_nDamageType                                   , 0x10)
        SCHEMA_FIELD(float                           , m_flBreakDamage                                 , 0x14)
        SCHEMA_FIELD(float                           , m_flBreakDamageRadius                           , 0x18)
        SCHEMA_FIELD(VectorWS                        , m_vWsBreakDamageOrigin                          , 0x1C)
        SCHEMA_FIELD(::Vector                        , m_vWsBreakDamageForce                           , 0x28)
    };

    class CGameScriptedMoveData {
    public:
        SCHEMA_FIELD(::Vector                        , m_vAccumulatedRootMotion                        , 0x0)
        SCHEMA_FIELD(::QAngle                        , m_angAccumulatedRootMotionRotation              , 0xC)
        SCHEMA_FIELD(VectorWS                        , m_vSrc                                          , 0x18)
        SCHEMA_FIELD(::QAngle                        , m_angSrc                                        , 0x24)
        SCHEMA_FIELD(::QAngle                        , m_angCurrent                                    , 0x30)
        SCHEMA_FIELD(float                           , m_flLockedSpeed                                 , 0x3C)
        SCHEMA_FIELD(float                           , m_flAngRate                                     , 0x40)
        SCHEMA_FIELD(float                           , m_flDuration                                    , 0x44)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x48)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4C)
        SCHEMA_FIELD(bool                            , m_bTeleportOnEnd                                , 0x4D)
        SCHEMA_FIELD(bool                            , m_bIgnoreRotation                               , 0x4E)
        SCHEMA_FIELD(bool                            , m_bSuccess                                      , 0x4F)
        SCHEMA_FIELD(ForcedCrouchState_t             , m_nForcedCrouchState                            , 0x50)
        SCHEMA_FIELD(bool                            , m_bIgnoreCollisions                             , 0x54)
        SCHEMA_FIELD(::Vector                        , m_vDest                                         , 0x58)
        SCHEMA_FIELD(::QAngle                        , m_angDst                                        , 0x64)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hDestEntity                                   , 0x70)
    };

    class CNmEventConsumerParticle {
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

    class CNmSnapWeaponNode_CDefinition {
    public:
        SCHEMA_FIELD(std::int16_t                    , m_nFlashedAmountNodeIdx                         , 0x18)
        SCHEMA_FIELD(std::int16_t                    , m_nWeaponCategoryNodeIdx                        , 0x1A)
        SCHEMA_FIELD(std::int16_t                    , m_nWeaponTypeNodeIdx                            , 0x1C)
    };

    class CFloatExponentialMovingAverage {
    public:
    };

    class CCSPlayerModernJump {
    public:
        SCHEMA_FIELD(::GameTick_t                    , m_nLastActualJumpPressTick                      , 0x10)
        SCHEMA_FIELD(float                           , m_flLastActualJumpPressFrac                     , 0x14)
        SCHEMA_FIELD(::GameTick_t                    , m_nLastUsableJumpPressTick                      , 0x18)
        SCHEMA_FIELD(float                           , m_flLastUsableJumpPressFrac                     , 0x1C)
        SCHEMA_FIELD(::GameTick_t                    , m_nLastLandedTick                               , 0x20)
        SCHEMA_FIELD(float                           , m_flLastLandedFrac                              , 0x24)
        SCHEMA_FIELD(float                           , m_flLastLandedVelocityX                         , 0x28)
        SCHEMA_FIELD(float                           , m_flLastLandedVelocityY                         , 0x2C)
        SCHEMA_FIELD(float                           , m_flLastLandedVelocityZ                         , 0x30)
    };

    class CPathSimpleAPI {
    public:
    };

    class CDebugSnapshotData_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_text                                          , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_dataType                                      , 0x8)
        SCHEMA_FIELD(std::uint32_t                   , m_userFlags                                     , 0xC)
        SCHEMA_FIELD(std::uint32_t                   , m_userData                                      , 0x10)
        SCHEMA_FIELD(VectorWS                        , m_userVector                                    , 0x14)
        SCHEMA_FIELD(CTransformWS                    , m_userTransform                                 , 0x20)
        SCHEMA_FIELD(CGenericShapeProxy              , m_userShape                                     , 0x40)
        SCHEMA_FIELD(::Color                         , m_drawColor                                     , 0xD8)
        SCHEMA_FIELD(CUtlVector<CDebugDrawHistoryData*>, m_vecDebugOverlayData                           , 0xE0)
        SCHEMA_FIELD(DebugSnapshotBaseStructuredData_t*, m_pStructuredData                               , 0xF8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x100)
        SCHEMA_FIELD(::CUtlString                    , m_sEntityName                                   , 0x108)
        SCHEMA_FIELD(CEntityIndex                    , m_nEntityIndex                                  , 0x110)
        SCHEMA_FIELD(CUtlLeanVector<CDebugSnapshotData_t>, m_children                                      , 0x120)
    };

    class SummaryTakeDamageInfo_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , nSummarisedCount                                , 0x0)
        SCHEMA_FIELD(CTakeDamageInfo                 , info                                            , 0x8)
        SCHEMA_FIELD(CTakeDamageResult               , result                                          , 0x120)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , hTarget                                         , 0x170)
    };

    class CPulseCell_Outflow_CycleShuffled {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class CRangeInt {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_pValue                                        , 0x0)
    };

    class VPhysicsCollisionAttribute_t {
    public:
        SCHEMA_FIELD(std::uint64_t                   , m_nInteractsAs                                  , 0x8)
        SCHEMA_FIELD(std::uint64_t                   , m_nInteractsWith                                , 0x10)
        SCHEMA_FIELD(std::uint64_t                   , m_nInteractsExclude                             , 0x18)
        SCHEMA_FIELD(std::uint32_t                   , m_nEntityId                                     , 0x20)
        SCHEMA_FIELD(std::uint32_t                   , m_nOwnerId                                      , 0x24)
        SCHEMA_FIELD(std::uint16_t                   , m_nHierarchyId                                  , 0x28)
        SCHEMA_FIELD(std::uint16_t                   , m_nDetailLayerMask                              , 0x2A)
        SCHEMA_FIELD(std::uint8_t                    , m_nDetailLayerMaskType                          , 0x2C)
        SCHEMA_FIELD(std::uint8_t                    , m_nTargetDetailLayer                            , 0x2D)
        SCHEMA_FIELD(std::uint8_t                    , m_nCollisionGroup                               , 0x2E)
        SCHEMA_FIELD(std::uint8_t                    , m_nCollisionFunctionMask                        , 0x2F)
    };

    class ExternalAnimGraphHandle_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_Value                                         , 0x0)
    };

    class CGameSceneNodeHandle {
    public:
        SCHEMA_FIELD(CEntityHandle                   , m_hOwner                                        , 0x8)
        SCHEMA_FIELD(CUtlStringToken                 , m_name                                          , 0xC)
    };

    class CTakeDamageResultAPI {
    public:
    };

    class CPulseCell_Outflow_CycleOrdered_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNextIndex                                    , 0x0)
    };

    class CTakeDamageInfo {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecDamageForce                                , 0x8)
        SCHEMA_FIELD(VectorWS                        , m_vecDamagePosition                             , 0x14)
        SCHEMA_FIELD(VectorWS                        , m_vecReportedPosition                           , 0x20)
        SCHEMA_FIELD(::Vector                        , m_vecDamageDirection                            , 0x2C)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hInflictor                                    , 0x38)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAttacker                                     , 0x3C)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAbility                                      , 0x40)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0x44)
        SCHEMA_FIELD(float                           , m_flTotalledDamage                              , 0x48)
        SCHEMA_FIELD(DamageTypes_t                   , m_bitsDamageType                                , 0x4C)
        SCHEMA_FIELD(std::int32_t                    , m_iDamageCustom                                 , 0x50)
        SCHEMA_FIELD(AmmoIndex_t                     , m_iAmmoType                                     , 0x54)
        SCHEMA_FIELD(float                           , m_flOriginalDamage                              , 0x60)
        SCHEMA_FIELD(bool                            , m_bShouldBleed                                  , 0x64)
        SCHEMA_FIELD(bool                            , m_bShouldSpark                                  , 0x65)
        SCHEMA_FIELD(TakeDamageFlags_t               , m_nDamageFlags                                  , 0x70)
        SCHEMA_FIELD(HitGroup_t                      , m_iHitGroupId                                   , 0x78)
        SCHEMA_FIELD(std::int32_t                    , m_nNumObjectsPenetrated                         , 0x7C)
        SCHEMA_FIELD(float                           , m_flFriendlyFireDamageReductionRatio            , 0x80)
        SCHEMA_FIELD(bool                            , m_bStoppedBullet                                , 0x84)
        SCHEMA_FIELD(CUtlLeanVector<DestructiblePartDamageRequest_t>, m_DestructibleHitGroupRequests                  , 0x100)
        SCHEMA_FIELD(bool                            , m_bInTakeDamageFlow                             , 0x110)
    };

    class CPulseCell_Value_Gradient {
    public:
        SCHEMA_FIELD(CColorGradient                  , m_Gradient                                      , 0x48)
    };

    class CConstantForceController {
    public:
        SCHEMA_FIELD(::Vector                        , m_linear                                        , 0xC)
        SCHEMA_FIELD(RotationVector                  , m_angular                                       , 0x18)
        SCHEMA_FIELD(::Vector                        , m_linearSave                                    , 0x24)
        SCHEMA_FIELD(RotationVector                  , m_angularSave                                   , 0x30)
    };

    class CNetworkOriginCellCoordQuantizedVector {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_cellX                                         , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , m_cellY                                         , 0x12)
        SCHEMA_FIELD(std::uint16_t                   , m_cellZ                                         , 0x14)
        SCHEMA_FIELD(std::uint16_t                   , m_nOutsideWorld                                 , 0x16)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecX                                          , 0x18)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecY                                          , 0x20)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecZ                                          , 0x28)
    };

    class CBaseIssue {
    public:
        SCHEMA_FIELD(char                            , m_szTypeString                                  , 0x20)
        SCHEMA_FIELD(char                            , m_szDetailsString                               , 0x60)
        SCHEMA_FIELD(std::int32_t                    , m_iNumYesVotes                                  , 0x164)
        SCHEMA_FIELD(std::int32_t                    , m_iNumNoVotes                                   , 0x168)
        SCHEMA_FIELD(std::int32_t                    , m_iNumPotentialVotes                            , 0x16C)
        SCHEMA_FIELD(CVoteController*                , m_pVoteController                               , 0x170)
    };

    class SoundeventPathCornerPairNetworked_t {
    public:
        SCHEMA_FIELD(VectorWS                        , vP1                                             , 0x0)
        SCHEMA_FIELD(VectorWS                        , vP2                                             , 0xC)
        SCHEMA_FIELD(float                           , flPathLengthSqr                                 , 0x18)
        SCHEMA_FIELD(float                           , flP1Pct                                         , 0x1C)
        SCHEMA_FIELD(float                           , flP2Pct                                         , 0x20)
    };

    class CPulseCell_Value_RandomInt {
    public:
    };

    class PulseSelectorOutflowList_t {
    public:
        SCHEMA_FIELD(CUtlVector<OutflowWithRequirements_t>, m_Outflows                                      , 0x0)
    };

    class SceneEventId_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_Value                                         , 0x0)
    };

    class AI_MotorGroundAnimgraph_DebugSnapshotData_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , state                                           , 0x8)
        SCHEMA_FIELD(bool                            , b_has_path                                      , 0x10)
        SCHEMA_FIELD(float                           , f_remaining_ground_path_length                  , 0x14)
        SCHEMA_FIELD(float                           , f_current_speed                                 , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , move_type                                       , 0x20)
        SCHEMA_FIELD(float                           , f_move_heading_actual                           , 0x28)
        SCHEMA_FIELD(float                           , f_move_heading_desired                          , 0x2C)
        SCHEMA_FIELD(float                           , f_current_lean                                  , 0x30)
        SCHEMA_FIELD(float                           , f_target_lean                                   , 0x34)
        SCHEMA_FIELD(CUtlVector<AI_MotorGroundAnimgraph_DebugSnapshotData_t_Event_t>, vec_events                                      , 0x38)
    };

    class DebugSnapshotBaseStructuredData_t {
    public:
    };

    class CPulseGraphInstance_GameBlackboard {
    public:
    };

    class physics_save_sphere_t {
    public:
        SCHEMA_FIELD(float                           , radius                                          , 0x0)
    };

    class CBaseAnimGraphVariationUserData {
    public:
    };

    class CNavHullVData {
    public:
        SCHEMA_FIELD(bool                            , m_bAgentEnabled                                 , 0x0)
        SCHEMA_FIELD(float                           , m_agentRadius                                   , 0x4)
        SCHEMA_FIELD(float                           , m_agentHeight                                   , 0x8)
        SCHEMA_FIELD(bool                            , m_agentShortHeightEnabled                       , 0xC)
        SCHEMA_FIELD(float                           , m_agentShortHeight                              , 0x10)
        SCHEMA_FIELD(bool                            , m_agentCrawlEnabled                             , 0x14)
        SCHEMA_FIELD(float                           , m_agentCrawlHeight                              , 0x18)
        SCHEMA_FIELD(float                           , m_agentMaxClimb                                 , 0x1C)
        SCHEMA_FIELD(std::int32_t                    , m_agentMaxSlope                                 , 0x20)
        SCHEMA_FIELD(float                           , m_agentMaxJumpDownDist                          , 0x24)
        SCHEMA_FIELD(float                           , m_agentMaxJumpHorizDistBase                     , 0x28)
        SCHEMA_FIELD(float                           , m_agentMaxJumpUpDist                            , 0x2C)
        SCHEMA_FIELD(std::int32_t                    , m_agentBorderErosion                            , 0x30)
        SCHEMA_FIELD(bool                            , m_flowMapGenerationEnabled                      , 0x34)
        SCHEMA_FIELD(float                           , m_flowMapNodeMaxRadius                          , 0x38)
    };

    class CRopeOverlapHit {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x0)
        SCHEMA_FIELD(CUtlVector<int32>               , m_vecOverlappingLinks                           , 0x8)
    };

    class CTimeline {
    public:
        SCHEMA_FIELD(float                           , m_flValues                                      , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nValueCounts                                  , 0x110)
        SCHEMA_FIELD(std::int32_t                    , m_nBucketCount                                  , 0x210)
        SCHEMA_FIELD(float                           , m_flInterval                                    , 0x214)
        SCHEMA_FIELD(float                           , m_flFinalValue                                  , 0x218)
        SCHEMA_FIELD(TimelineCompression_t           , m_nCompressionType                              , 0x21C)
        SCHEMA_FIELD(bool                            , m_bStopped                                      , 0x220)
    };

    class IRagdoll {
    public:
    };

    class AI_MotorGroundAnimgraph_DebugSnapshotData_t_Event_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , description                                     , 0x0)
        SCHEMA_FIELD(VectorWS                        , location                                        , 0x8)
    };

    class CFloatMovingAverage {
    public:
    };

    class CNavVolumeBreadthFirstSearch {
    public:
        SCHEMA_FIELD(VectorWS                        , m_vStartPos                                     , 0xA8)
        SCHEMA_FIELD(float                           , m_flSearchDist                                  , 0xB4)
    };

    class CNmEventConsumerLegacy {
    public:
    };

    class SceneOpportunityHandle_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Value                                         , 0x0)
    };

    class SAVE_HEADER {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_saveId                                        , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_version                                       , 0x4)
        SCHEMA_FIELD(std::int32_t                    , m_nConnectionCount                              , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nMapVersion                                   , 0xC)
        SCHEMA_FIELD(::CUtlString                    , m_sSpawnGroupName                               , 0x10)
        SCHEMA_FIELD(matrix3x4a_t                    , m_vecWorldOffset                                , 0x20)
        SCHEMA_FIELD(float                           , m_flSaveTime                                    , 0x50)
    };

    class CPulseCell_Outflow_PlayVCD {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCChoreoSceneResource>, m_hChoreoScene                                  , 0xF0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_OnPaused                                      , 0xF8)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_OnResumed                                     , 0x140)
        SCHEMA_FIELD(CUtlVector<CPulseCell_Outflow_PlayVCD_VCDRequirementInfo_t>, m_OutRequirements                               , 0x188)
    };

    class CPulseCell_Inflow_BaseEntrypoint {
    public:
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_EntryChunk                                    , 0x48)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x50)
    };

    class SceneRequestTargetMapPair_t {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_actorName                                     , 0x0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_targetName                                    , 0x8)
    };

    class CBtNode {
    public:
    };

    class CPulseCell_Outflow_ListenForEntityOutput {
    public:
        SCHEMA_FIELD(SignatureOutflow_Resume         , m_OnFired                                       , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0x90)
        SCHEMA_FIELD(CGlobalSymbol                   , m_strEntityOutput                               , 0xD8)
        SCHEMA_FIELD(::CUtlString                    , m_strEntityOutputParam                          , 0xE0)
        SCHEMA_FIELD(bool                            , m_bListenUntilCanceled                          , 0xE8)
    };

    class CHintMessage {
    public:
        SCHEMA_FIELD(char*                           , m_hintString                                    , 0x0)
        SCHEMA_FIELD(CUtlVector<char*>               , m_args                                          , 0x8)
        SCHEMA_FIELD(float                           , m_duration                                      , 0x20)
    };

    class CCSGameModeRules {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
    };

    class sndopvarlatchdata_t {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStack                                      , 0x8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOperator                                   , 0x10)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOpvar                                      , 0x18)
        SCHEMA_FIELD(float                           , m_flVal                                         , 0x20)
        SCHEMA_FIELD(::Vector                        , m_vPos                                          , 0x24)
    };

    class CLogicRelayAPI {
    public:
    };

    class CTakeDamageSummaryScopeGuard {
    public:
        SCHEMA_FIELD(CUtlVector<SummaryTakeDamageInfo_t*>, m_vecSummaries                                  , 0x8)
    };

    class AI_DefaultNPC_DebugSnapshotData_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , s_npc_current_ability                           , 0x8)
        SCHEMA_FIELD(CGlobalSymbol                   , s_npc_tactic_current                            , 0x10)
        SCHEMA_FIELD(CGlobalSymbol                   , s_npc_tactic_phase                              , 0x18)
        SCHEMA_FIELD(CUtlVector<CGlobalSymbol>       , tactic_interrupt_conditions                     , 0x20)
        SCHEMA_FIELD(::CUtlString                    , s_npc_current_movement                          , 0x38)
        SCHEMA_FIELD(AI_DefaultNPC_DebugSnapshotData_t_PathQuery_t, path_query_schedule                             , 0x40)
        SCHEMA_FIELD(AI_DefaultNPC_DebugSnapshotData_t_PathQuery_t, path_query_tactic                               , 0x68)
        SCHEMA_FIELD(CUtlVector<AI_DefaultNPC_DebugSnapshotData_t_PathQuery_t>, path_queries_speculative                        , 0x90)
    };

    class CNavVolumeCalculatedVector {
    public:
    };

    class magnetted_objects_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , hEntity                                         , 0x8)
    };

    class RagdollCreationParams_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vForce                                        , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nForceBone                                    , 0xC)
        SCHEMA_FIELD(bool                            , m_bForceCurrentWorldTransform                   , 0x10)
        SCHEMA_FIELD(bool                            , m_bUseLRURetirement                             , 0x11)
        SCHEMA_FIELD(std::int32_t                    , m_nHealthToGrant                                , 0x14)
    };

    class CMultiplayer_Expresser {
    public:
        SCHEMA_FIELD(bool                            , m_bAllowMultipleScenes                          , 0xA0)
    };

    class QuestProgress {
    public:
    };

    class ResponseParams {
    public:
        SCHEMA_FIELD(std::int16_t                    , odds                                            , 0x10)
        SCHEMA_FIELD(std::int16_t                    , flags                                           , 0x12)
        SCHEMA_FIELD(ResponseFollowup*               , m_pFollowup                                     , 0x18)
    };

    class locksound_t {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , sLockedSound                                    , 0x8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , sUnlockedSound                                  , 0x10)
        SCHEMA_FIELD(::GameTime_t                    , flwaitSound                                     , 0x18)
    };

    class SPAWNGROUP_HEADER {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sGroupName                                    , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_sEntityLumpName                               , 0x8)
        SCHEMA_FIELD(matrix3x4a_t                    , m_vecWorldOffset                                , 0x10)
        SCHEMA_FIELD(bool                            , m_bClientSpawnGroup                             , 0x40)
        SCHEMA_FIELD(bool                            , m_bSuppressAllEntities                          , 0x41)
    };

    class CPulseCell_BaseState {
    public:
    };

    class RotatorQueueEntry_t {
    public:
        SCHEMA_FIELD(::Quaternion                    , qTarget                                         , 0x0)
        SCHEMA_FIELD(RotatorTargetSpace_t            , eSpace                                          , 0x10)
    };

    class CPulseCell_Inflow_GraphHook {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_HookName                                      , 0x80)
    };

    class CExplosionTypeData {
    public:
        SCHEMA_FIELD(CSoundEventName                 , m_SoundName                                     , 0x0)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIParticleSystemDefinition>>, m_ParticleEffect                                , 0x10)
        SCHEMA_FIELD(bool                            , m_bIsIncindiary                                 , 0xF0)
        SCHEMA_FIELD(bool                            , m_bHasForces                                    , 0xF1)
        SCHEMA_FIELD(CGlobalSymbol                   , m_DecalType                                     , 0xF8)
    };

    class CBasePlayerControllerAPI {
    public:
    };

    class ModelConfigHandle_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_Value                                         , 0x0)
    };

    class CChoreoComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
        SCHEMA_FIELD(CHandle<CBaseModelEntity>       , m_hOwner                                        , 0x30)
        SCHEMA_FIELD(SceneEventId_t                  , m_nNextSceneEventId                             , 0x68)
        SCHEMA_FIELD(bool                            , m_bUpdateLayerPriorities                        , 0x6C)
        SCHEMA_FIELD(::GameTime_t                    , m_flAllowResponsesEndTime                       , 0x70)
    };

    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_TagName                                       , 0x0)
    };

    class CPulseCell_Outflow_PlaySequence {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_ParamSequenceName                             , 0xF0)
    };

    class CRelativeTransform {
    public:
        SCHEMA_FIELD(bool                            , m_bTransformIsWorldSpace                        , 0x0)
        SCHEMA_FIELD(CTransform                      , m_transform                                     , 0x10)
        SCHEMA_FIELD(CTransformWS                    , m_transformWS                                   , 0x30)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x50)
    };

    class CNmEventConsumerAttributes {
    public:
    };

    class CPulseCell_Outflow_PlaySceneBase_CursorState_t {
    public:
        using _Type0 = CUtlHashtable<PulseCursorID_t,int32>;
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_sceneInstance                                 , 0x0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_mainActor                                     , 0x4)
        SCHEMA_FIELD(_Type0                          , m_cursorIDToEventID                             , 0x8)
    };

    class CBaseModelEntityAPI {
    public:
    };

    class CNmAimCSNode_CDefinition {
    public:
        SCHEMA_FIELD(std::int16_t                    , m_nVerticalAngleNodeIdx                         , 0x18)
        SCHEMA_FIELD(std::int16_t                    , m_nHorizontalAngleNodeIdx                       , 0x1A)
        SCHEMA_FIELD(std::int16_t                    , m_nWeaponCategoryNodeIdx                        , 0x1C)
        SCHEMA_FIELD(std::int16_t                    , m_nWeaponTypeNodeIdx                            , 0x1E)
        SCHEMA_FIELD(std::int16_t                    , m_nWeaponActionNodeIdx                          , 0x20)
        SCHEMA_FIELD(std::int16_t                    , m_nWeaponDropNodeIdx                            , 0x22)
        SCHEMA_FIELD(std::int16_t                    , m_nIsDefusingNodeIdx                            , 0x24)
        SCHEMA_FIELD(std::int16_t                    , m_nCrouchWeightNodeIdx                          , 0x26)
        SCHEMA_FIELD(float                           , m_flHandIKBlendInTimeSeconds                    , 0x28)
        SCHEMA_FIELD(float                           , m_flActionBlendTimeSeconds                      , 0x2C)
        SCHEMA_FIELD(float                           , m_flPlantingBlendTimeSeconds                    , 0x30)
    };

    class CBtActionParachutePositioning {
    public:
        SCHEMA_FIELD(CountdownTimer                  , m_ActionTimer                                   , 0x58)
    };

    class PathMoverEntitySpawn {
    public:
        SCHEMA_FIELD(CHandle<CFuncMover>             , hMover                                          , 0x0)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, vecOtherEntities                                , 0x8)
    };

    class CPulseServerFuncs_Sounds {
    public:
    };

    class ParticleNode_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x0)
        SCHEMA_FIELD(ParticleIndex_t                 , m_iIndex                                        , 0x4)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x8)
        SCHEMA_FIELD(float                           , m_flGrowthDuration                              , 0xC)
        SCHEMA_FIELD(::Vector                        , m_vecGrowthOrigin                               , 0x10)
        SCHEMA_FIELD(float                           , m_flEndcapTime                                  , 0x1C)
        SCHEMA_FIELD(bool                            , m_bMarkedForDelete                              , 0x20)
    };

    class lerpdata_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEnt                                          , 0x0)
        SCHEMA_FIELD(MoveType_t                      , m_MoveType                                      , 0x4)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x8)
        SCHEMA_FIELD(::Vector                        , m_vecStartOrigin                                , 0xC)
        SCHEMA_FIELD(::Quaternion                    , m_qStartRot                                     , 0x20)
        SCHEMA_FIELD(ParticleIndex_t                 , m_nFXIndex                                      , 0x30)
    };

    class CCSGameRules {
    public:
        SCHEMA_FIELD(bool                            , m_bFreezePeriod                                 , 0xD8)
        SCHEMA_FIELD(bool                            , m_bWarmupPeriod                                 , 0xD9)
        SCHEMA_FIELD(::GameTime_t                    , m_fWarmupPeriodEnd                              , 0xDC)
        SCHEMA_FIELD(::GameTime_t                    , m_fWarmupPeriodStart                            , 0xE0)
        SCHEMA_FIELD(bool                            , m_bTerroristTimeOutActive                       , 0xE4)
        SCHEMA_FIELD(bool                            , m_bCTTimeOutActive                              , 0xE5)
        SCHEMA_FIELD(float                           , m_flTerroristTimeOutRemaining                   , 0xE8)
        SCHEMA_FIELD(float                           , m_flCTTimeOutRemaining                          , 0xEC)
        SCHEMA_FIELD(std::int32_t                    , m_nTerroristTimeOuts                            , 0xF0)
        SCHEMA_FIELD(std::int32_t                    , m_nCTTimeOuts                                   , 0xF4)
        SCHEMA_FIELD(bool                            , m_bTechnicalTimeOut                             , 0xF8)
        SCHEMA_FIELD(bool                            , m_bMatchWaitingForResume                        , 0xF9)
        SCHEMA_FIELD(std::int32_t                    , m_iFreezeTime                                   , 0xFC)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundTime                                    , 0x100)
        SCHEMA_FIELD(float                           , m_fMatchStartTime                               , 0x104)
        SCHEMA_FIELD(::GameTime_t                    , m_fRoundStartTime                               , 0x108)
        SCHEMA_FIELD(::GameTime_t                    , m_flRestartRoundTime                            , 0x10C)
        SCHEMA_FIELD(bool                            , m_bGameRestart                                  , 0x110)
        SCHEMA_FIELD(float                           , m_flGameStartTime                               , 0x114)
        SCHEMA_FIELD(float                           , m_timeUntilNextPhaseStarts                      , 0x118)
        SCHEMA_FIELD(std::int32_t                    , m_gamePhase                                     , 0x11C)
        SCHEMA_FIELD(std::int32_t                    , m_totalRoundsPlayed                             , 0x120)
        SCHEMA_FIELD(std::int32_t                    , m_nRoundsPlayedThisPhase                        , 0x124)
        SCHEMA_FIELD(std::int32_t                    , m_nOvertimePlaying                              , 0x128)
        SCHEMA_FIELD(std::int32_t                    , m_iHostagesRemaining                            , 0x12C)
        SCHEMA_FIELD(bool                            , m_bAnyHostageReached                            , 0x130)
        SCHEMA_FIELD(bool                            , m_bMapHasBombTarget                             , 0x131)
        SCHEMA_FIELD(bool                            , m_bMapHasRescueZone                             , 0x132)
        SCHEMA_FIELD(bool                            , m_bMapHasBuyZone                                , 0x133)
        SCHEMA_FIELD(bool                            , m_bIsQueuedMatchmaking                          , 0x134)
        SCHEMA_FIELD(std::int32_t                    , m_nQueuedMatchmakingMode                        , 0x138)
        SCHEMA_FIELD(bool                            , m_bIsValveDS                                    , 0x13C)
        SCHEMA_FIELD(bool                            , m_bLogoMap                                      , 0x13D)
        SCHEMA_FIELD(bool                            , m_bPlayAllStepSoundsOnServer                    , 0x13E)
        SCHEMA_FIELD(std::int32_t                    , m_iSpectatorSlotCount                           , 0x140)
        SCHEMA_FIELD(std::int32_t                    , m_MatchDevice                                   , 0x144)
        SCHEMA_FIELD(bool                            , m_bHasMatchStarted                              , 0x148)
        SCHEMA_FIELD(std::int32_t                    , m_nNextMapInMapgroup                            , 0x14C)
        SCHEMA_FIELD(char                            , m_szTournamentEventName                         , 0x150)
        SCHEMA_FIELD(char                            , m_szTournamentEventStage                        , 0x350)
        SCHEMA_FIELD(char                            , m_szMatchStatTxt                                , 0x550)
        SCHEMA_FIELD(char                            , m_szTournamentPredictionsTxt                    , 0x750)
        SCHEMA_FIELD(std::int32_t                    , m_nTournamentPredictionsPct                     , 0x950)
        SCHEMA_FIELD(::GameTime_t                    , m_flCMMItemDropRevealStartTime                  , 0x954)
        SCHEMA_FIELD(::GameTime_t                    , m_flCMMItemDropRevealEndTime                    , 0x958)
        SCHEMA_FIELD(bool                            , m_bIsDroppingItems                              , 0x95C)
        SCHEMA_FIELD(bool                            , m_bIsQuestEligible                              , 0x95D)
        SCHEMA_FIELD(bool                            , m_bIsHltvActive                                 , 0x95E)
        SCHEMA_FIELD(bool                            , m_bBombPlanted                                  , 0x95F)
        SCHEMA_FIELD(std::uint16_t                   , m_arrProhibitedItemIndices                      , 0x960)
        SCHEMA_FIELD(std::uint32_t                   , m_arrTournamentActiveCasterAccounts             , 0xA28)
        SCHEMA_FIELD(std::int32_t                    , m_numBestOfMaps                                 , 0xA38)
        SCHEMA_FIELD(std::int32_t                    , m_nHalloweenMaskListSeed                        , 0xA3C)
        SCHEMA_FIELD(bool                            , m_bBombDropped                                  , 0xA40)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundWinStatus                               , 0xA44)
        SCHEMA_FIELD(std::int32_t                    , m_eRoundWinReason                               , 0xA48)
        SCHEMA_FIELD(bool                            , m_bTCantBuy                                     , 0xA4C)
        SCHEMA_FIELD(bool                            , m_bCTCantBuy                                    , 0xA4D)
        SCHEMA_FIELD(std::int32_t                    , m_iMatchStats_RoundResults                      , 0xA50)
        SCHEMA_FIELD(std::int32_t                    , m_iMatchStats_PlayersAlive_CT                   , 0xAC8)
        SCHEMA_FIELD(std::int32_t                    , m_iMatchStats_PlayersAlive_T                    , 0xB40)
        SCHEMA_FIELD(float                           , m_TeamRespawnWaveTimes                          , 0xBB8)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextRespawnWave                             , 0xC38)
        SCHEMA_FIELD(::Vector                        , m_vMinimapMins                                  , 0xCB8)
        SCHEMA_FIELD(::Vector                        , m_vMinimapMaxs                                  , 0xCC4)
        SCHEMA_FIELD(float                           , m_MinimapVerticalSectionHeights                 , 0xCD0)
        SCHEMA_FIELD(std::uint64_t                   , m_ullLocalMatchID                               , 0xCF0)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchMapGroupVoteTypes                    , 0xCF8)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchMapGroupVoteOptions                  , 0xD20)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchMapVoteWinner                        , 0xD48)
        SCHEMA_FIELD(std::int32_t                    , m_iNumConsecutiveCTLoses                        , 0xD4C)
        SCHEMA_FIELD(std::int32_t                    , m_iNumConsecutiveTerroristLoses                 , 0xD50)
        SCHEMA_FIELD(bool                            , m_bHasHostageBeenTouched                        , 0xD70)
        SCHEMA_FIELD(::GameTime_t                    , m_flIntermissionStartTime                       , 0xD74)
        SCHEMA_FIELD(::GameTime_t                    , m_flIntermissionEndTime                         , 0xD78)
        SCHEMA_FIELD(bool                            , m_bLevelInitialized                             , 0xD7C)
        SCHEMA_FIELD(std::int32_t                    , m_iTotalRoundsPlayed                            , 0xD80)
        SCHEMA_FIELD(std::int32_t                    , m_iUnBalancedRounds                             , 0xD84)
        SCHEMA_FIELD(bool                            , m_endMatchOnRoundReset                          , 0xD88)
        SCHEMA_FIELD(bool                            , m_endMatchOnThink                               , 0xD89)
        SCHEMA_FIELD(std::int32_t                    , m_iNumTerrorist                                 , 0xD8C)
        SCHEMA_FIELD(std::int32_t                    , m_iNumCT                                        , 0xD90)
        SCHEMA_FIELD(std::int32_t                    , m_iNumSpawnableTerrorist                        , 0xD94)
        SCHEMA_FIELD(std::int32_t                    , m_iNumSpawnableCT                               , 0xD98)
        SCHEMA_FIELD(CUtlVector<int32>               , m_arrSelectedHostageSpawnIndices                , 0xDA0)
        SCHEMA_FIELD(std::int32_t                    , m_nSpawnPointsRandomSeed                        , 0xDB8)
        SCHEMA_FIELD(bool                            , m_bFirstConnected                               , 0xDBC)
        SCHEMA_FIELD(bool                            , m_bCompleteReset                                , 0xDBD)
        SCHEMA_FIELD(bool                            , m_bPickNewTeamsOnReset                          , 0xDBE)
        SCHEMA_FIELD(bool                            , m_bScrambleTeamsOnRestart                       , 0xDBF)
        SCHEMA_FIELD(bool                            , m_bSwapTeamsOnRestart                           , 0xDC0)
        SCHEMA_FIELD(CUtlVector<int32>               , m_nEndMatchTiedVotes                            , 0xDC8)
        SCHEMA_FIELD(bool                            , m_bNeedToAskPlayersForContinueVote              , 0xDE4)
        SCHEMA_FIELD(std::uint32_t                   , m_numQueuedMatchmakingAccounts                  , 0xDE8)
        SCHEMA_FIELD(float                           , m_fAvgPlayerRank                                , 0xDEC)
        SCHEMA_FIELD(char*                           , m_pQueuedMatchmakingReservationString           , 0xDF0)
        SCHEMA_FIELD(std::uint32_t                   , m_numTotalTournamentDrops                       , 0xDF8)
        SCHEMA_FIELD(std::uint32_t                   , m_numSpectatorsCountMax                         , 0xDFC)
        SCHEMA_FIELD(std::uint32_t                   , m_numSpectatorsCountMaxTV                       , 0xE00)
        SCHEMA_FIELD(std::uint32_t                   , m_numSpectatorsCountMaxLnk                      , 0xE04)
        SCHEMA_FIELD(std::int32_t                    , m_nCTsAliveAtFreezetimeEnd                      , 0xE10)
        SCHEMA_FIELD(std::int32_t                    , m_nTerroristsAliveAtFreezetimeEnd               , 0xE14)
        SCHEMA_FIELD(bool                            , m_bForceTeamChangeSilent                        , 0xE18)
        SCHEMA_FIELD(bool                            , m_bLoadingRoundBackupData                       , 0xE19)
        SCHEMA_FIELD(std::int32_t                    , m_nMatchInfoShowType                            , 0xE50)
        SCHEMA_FIELD(float                           , m_flMatchInfoDecidedTime                        , 0xE54)
        SCHEMA_FIELD(std::int32_t                    , mTeamDMLastWinningTeamNumber                    , 0xE70)
        SCHEMA_FIELD(float                           , mTeamDMLastThinkTime                            , 0xE74)
        SCHEMA_FIELD(float                           , m_flTeamDMLastAnnouncementTime                  , 0xE78)
        SCHEMA_FIELD(std::int32_t                    , m_iAccountTerrorist                             , 0xE7C)
        SCHEMA_FIELD(std::int32_t                    , m_iAccountCT                                    , 0xE80)
        SCHEMA_FIELD(std::int32_t                    , m_iSpawnPointCount_Terrorist                    , 0xE84)
        SCHEMA_FIELD(std::int32_t                    , m_iSpawnPointCount_CT                           , 0xE88)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxNumTerrorists                             , 0xE8C)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxNumCTs                                    , 0xE90)
        SCHEMA_FIELD(std::int32_t                    , m_iLoserBonusMostRecentTeam                     , 0xE94)
        SCHEMA_FIELD(float                           , m_tmNextPeriodicThink                           , 0xE98)
        SCHEMA_FIELD(bool                            , m_bVoiceWonMatchBragFired                       , 0xE9C)
        SCHEMA_FIELD(float                           , m_fWarmupNextChatNoticeTime                     , 0xEA0)
        SCHEMA_FIELD(std::int32_t                    , m_iHostagesRescued                              , 0xEA8)
        SCHEMA_FIELD(std::int32_t                    , m_iHostagesTouched                              , 0xEAC)
        SCHEMA_FIELD(float                           , m_flNextHostageAnnouncement                     , 0xEB0)
        SCHEMA_FIELD(bool                            , m_bNoTerroristsKilled                           , 0xEB4)
        SCHEMA_FIELD(bool                            , m_bNoCTsKilled                                  , 0xEB5)
        SCHEMA_FIELD(bool                            , m_bNoEnemiesKilled                              , 0xEB6)
        SCHEMA_FIELD(bool                            , m_bCanDonateWeapons                             , 0xEB7)
        SCHEMA_FIELD(float                           , m_firstKillTime                                 , 0xEBC)
        SCHEMA_FIELD(float                           , m_firstBloodTime                                , 0xEC4)
        SCHEMA_FIELD(bool                            , m_hostageWasInjured                             , 0xEE0)
        SCHEMA_FIELD(bool                            , m_hostageWasKilled                              , 0xEE1)
        SCHEMA_FIELD(bool                            , m_bVoteCalled                                   , 0xEF0)
        SCHEMA_FIELD(bool                            , m_bServerVoteOnReset                            , 0xEF1)
        SCHEMA_FIELD(float                           , m_flVoteCheckThrottle                           , 0xEF4)
        SCHEMA_FIELD(bool                            , m_bBuyTimeEnded                                 , 0xEF8)
        SCHEMA_FIELD(std::int32_t                    , m_nLastFreezeEndBeep                            , 0xEFC)
        SCHEMA_FIELD(bool                            , m_bTargetBombed                                 , 0xF00)
        SCHEMA_FIELD(bool                            , m_bBombDefused                                  , 0xF01)
        SCHEMA_FIELD(bool                            , m_bMapHasBombZone                               , 0xF02)
        SCHEMA_FIELD(::Vector                        , m_vecMainCTSpawnPos                             , 0xF50)
        SCHEMA_FIELD(CUtlVector<CHandle<SpawnPoint>> , m_CTSpawnPointsMasterList                       , 0xF60)
        SCHEMA_FIELD(CUtlVector<CHandle<SpawnPoint>> , m_TerroristSpawnPointsMasterList                , 0xF78)
        SCHEMA_FIELD(bool                            , m_bRespawningAllRespawnablePlayers              , 0xF90)
        SCHEMA_FIELD(std::int32_t                    , m_iNextCTSpawnPoint                             , 0xF94)
        SCHEMA_FIELD(float                           , m_flCTSpawnPointUsedTime                        , 0xF98)
        SCHEMA_FIELD(std::int32_t                    , m_iNextTerroristSpawnPoint                      , 0xF9C)
        SCHEMA_FIELD(float                           , m_flTerroristSpawnPointUsedTime                 , 0xFA0)
        SCHEMA_FIELD(CUtlVector<CHandle<SpawnPoint>> , m_CTSpawnPoints                                 , 0xFA8)
        SCHEMA_FIELD(CUtlVector<CHandle<SpawnPoint>> , m_TerroristSpawnPoints                          , 0xFC0)
        SCHEMA_FIELD(bool                            , m_bIsUnreservedGameServer                       , 0xFD8)
        SCHEMA_FIELD(float                           , m_fAutobalanceDisplayTime                       , 0xFDC)
        SCHEMA_FIELD(bool                            , m_bAllowWeaponSwitch                            , 0x1018)
        SCHEMA_FIELD(bool                            , m_bRoundTimeWarningTriggered                    , 0x1019)
        SCHEMA_FIELD(::GameTime_t                    , m_phaseChangeAnnouncementTime                   , 0x101C)
        SCHEMA_FIELD(float                           , m_fNextUpdateTeamClanNamesTime                  , 0x1020)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastThinkTime                               , 0x1024)
        SCHEMA_FIELD(float                           , m_fAccumulatedRoundOffDamage                    , 0x1028)
        SCHEMA_FIELD(std::int32_t                    , m_nShorthandedBonusLastEvalRound                , 0x102C)
        SCHEMA_FIELD(std::int32_t                    , m_nMatchAbortedEarlyReason                      , 0x1078)
        SCHEMA_FIELD(bool                            , m_bHasTriggeredRoundStartMusic                  , 0x107C)
        SCHEMA_FIELD(bool                            , m_bSwitchingTeamsAtRoundReset                   , 0x107D)
        SCHEMA_FIELD(CCSGameModeRules*               , m_pGameModeRules                                , 0x1098)
        SCHEMA_FIELD(KeyValues3                      , m_BtGlobalBlackboard                            , 0x10A0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hPlayerResource                               , 0x1138)
        SCHEMA_FIELD(CRetakeGameRules                , m_RetakeRules                                   , 0x1140)
        SCHEMA_FIELD(CUtlVector<int32>               , m_arrTeamUniqueKillWeaponsMatch                 , 0x1330)
        SCHEMA_FIELD(bool                            , m_bTeamLastKillUsedUniqueWeaponMatch            , 0x1390)
        SCHEMA_FIELD(std::uint8_t                    , m_nMatchEndCount                                , 0x13B8)
        SCHEMA_FIELD(std::int32_t                    , m_nTTeamIntroVariant                            , 0x13BC)
        SCHEMA_FIELD(std::int32_t                    , m_nCTTeamIntroVariant                           , 0x13C0)
        SCHEMA_FIELD(bool                            , m_bTeamIntroPeriod                              , 0x13C4)
        SCHEMA_FIELD(::GameTime_t                    , m_fTeamIntroPeriodEnd                           , 0x13C8)
        SCHEMA_FIELD(bool                            , m_bPlayedTeamIntroVO                            , 0x13CC)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndWinnerTeam                           , 0x13D0)
        SCHEMA_FIELD(std::int32_t                    , m_eRoundEndReason                               , 0x13D4)
        SCHEMA_FIELD(bool                            , m_bRoundEndShowTimerDefend                      , 0x13D8)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndTimerTime                            , 0x13DC)
        SCHEMA_FIELD(::CUtlString                    , m_sRoundEndFunFactToken                         , 0x13E0)
        SCHEMA_FIELD(CPlayerSlot                     , m_iRoundEndFunFactPlayerSlot                    , 0x13E8)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndFunFactData1                         , 0x13EC)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndFunFactData2                         , 0x13F0)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndFunFactData3                         , 0x13F4)
        SCHEMA_FIELD(::CUtlString                    , m_sRoundEndMessage                              , 0x13F8)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndPlayerCount                          , 0x1400)
        SCHEMA_FIELD(bool                            , m_bRoundEndNoMusic                              , 0x1404)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndLegacy                               , 0x1408)
        SCHEMA_FIELD(std::uint8_t                    , m_nRoundEndCount                                , 0x140C)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundStartRoundNumber                        , 0x1410)
        SCHEMA_FIELD(std::uint8_t                    , m_nRoundStartCount                              , 0x1414)
        SCHEMA_FIELD(double                          , m_flLastPerfSampleTime                          , 0x5420)
    };

    class CPulseCell_Value_RandomFloat {
    public:
    };

    class CEntityInstance {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPrivateVScripts                            , 0x8)
        SCHEMA_FIELD(CEntityIdentity*                , m_pEntity                                       , 0x10)
        SCHEMA_FIELD(CScriptComponent*               , m_CScriptComponent                              , 0x28)
    };

    class CTestPulseIO_FloatStringArgs_t {
    public:
        SCHEMA_FIELD(float                           , flOutFloat                                      , 0x0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , strOutString                                    , 0x8)
    };

    class EntitySpottedState_t {
    public:
        SCHEMA_FIELD(bool                            , m_bSpotted                                      , 0x8)
        SCHEMA_FIELD(std::uint32_t                   , m_bSpottedByMask                                , 0xC)
    };

    class SoundCommand_t {
    public:
        SCHEMA_FIELD(float                           , m_time                                          , 0x8)
        SCHEMA_FIELD(float                           , m_deltaTime                                     , 0xC)
        SCHEMA_FIELD(soundcommands_t                 , m_command                                       , 0x10)
        SCHEMA_FIELD(float                           , m_value                                         , 0x14)
    };

    class CCSGameModeRules_ArmsRace {
    public:
        SCHEMA_FIELD(CNetworkUtlVectorBase<CUtlString>, m_WeaponSequence                                , 0x30)
    };

    class CFiringModeInt {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nValues                                       , 0x0)
    };

    class CPulseCell_Inflow_EventHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_EventName                                     , 0x80)
    };

    class CAttributeList {
    public:
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<CEconItemAttribute>, m_Attributes                                    , 0x8)
        SCHEMA_FIELD(CAttributeManager*              , m_pManager                                      , 0x70)
    };

    class CCollisionProperty {
    public:
        SCHEMA_FIELD(VPhysicsCollisionAttribute_t    , m_collisionAttribute                            , 0x10)
        SCHEMA_FIELD(::Vector                        , m_vecMins                                       , 0x40)
        SCHEMA_FIELD(::Vector                        , m_vecMaxs                                       , 0x4C)
        SCHEMA_FIELD(std::uint8_t                    , m_usSolidFlags                                  , 0x5A)
        SCHEMA_FIELD(SolidType_t                     , m_nSolidType                                    , 0x5B)
        SCHEMA_FIELD(std::uint8_t                    , m_triggerBloat                                  , 0x5C)
        SCHEMA_FIELD(SurroundingBoundsType_t         , m_nSurroundType                                 , 0x5D)
        SCHEMA_FIELD(std::uint8_t                    , m_CollisionGroup                                , 0x5E)
        SCHEMA_FIELD(std::uint8_t                    , m_nEnablePhysics                                , 0x5F)
        SCHEMA_FIELD(float                           , m_flBoundingRadius                              , 0x60)
        SCHEMA_FIELD(::Vector                        , m_vecSpecifiedSurroundingMins                   , 0x64)
        SCHEMA_FIELD(::Vector                        , m_vecSpecifiedSurroundingMaxs                   , 0x70)
        SCHEMA_FIELD(::Vector                        , m_vecSurroundingMaxs                            , 0x7C)
        SCHEMA_FIELD(::Vector                        , m_vecSurroundingMins                            , 0x88)
        SCHEMA_FIELD(::Vector                        , m_vCapsuleCenter1                               , 0x94)
        SCHEMA_FIELD(::Vector                        , m_vCapsuleCenter2                               , 0xA0)
        SCHEMA_FIELD(float                           , m_flCapsuleRadius                               , 0xAC)
    };

    class CTestPulseIOAPI {
    public:
    };

    class CCommentarySystem {
    public:
        SCHEMA_FIELD(bool                            , m_bCommentaryEnabledMidGame                     , 0x12)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextTeleportTime                            , 0x14)
        SCHEMA_FIELD(std::int32_t                    , m_iTeleportStage                                , 0x18)
        SCHEMA_FIELD(bool                            , m_bCheatState                                   , 0x1C)
        SCHEMA_FIELD(bool                            , m_bIsFirstSpawnGroupToLoad                      , 0x1D)
        SCHEMA_FIELD(CUtlVector<modifiedconvars_t>   , m_ModifiedConvars                               , 0x20)
        SCHEMA_FIELD(CHandle<CPointCommentaryNode>   , m_hCurrentNode                                  , 0x38)
        SCHEMA_FIELD(CHandle<CPointCommentaryNode>   , m_hActiveCommentaryNode                         , 0x3C)
        SCHEMA_FIELD(CHandle<CPointCommentaryNode>   , m_hLastCommentaryNode                           , 0x40)
        SCHEMA_FIELD(CUtlVector<CHandle<CPointCommentaryNode>>, m_vecNodes                                      , 0x48)
    };

    class ISkeletonAnimationController {
    public:
    };

    class sky3dparams_t {
    public:
        SCHEMA_FIELD(std::int16_t                    , scale                                           , 0x8)
        SCHEMA_FIELD(::Vector                        , origin                                          , 0xC)
        SCHEMA_FIELD(bool                            , bClip3DSkyBoxNearToWorldFar                     , 0x18)
        SCHEMA_FIELD(float                           , flClip3DSkyBoxNearToWorldFarOffset              , 0x1C)
        SCHEMA_FIELD(fogparams_t                     , fog                                             , 0x20)
        SCHEMA_FIELD(::WorldGroupId_t                , m_nWorldGroupID                                 , 0x88)
    };

    class CodeGenAABB_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMinBounds                                    , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vMaxBounds                                    , 0xC)
    };

    class PrecipitationFilter_t {
    public:
        SCHEMA_FIELD(float                           , m_flMaxRadius                                   , 0x0)
    };

    class CPulsePhysicsConstraintsFuncs {
    public:
    };

    class CSimpleStopwatch {
    public:
    };

    class CResponseCriteriaSet {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNumPrefixedContexts                          , 0x30)
        SCHEMA_FIELD(bool                            , m_bOverrideOnAppend                             , 0x34)
    };

    class CPulseCell_BaseValue {
    public:
    };

    class CBtActionCombatPositioning {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_szSensorInputKey                              , 0x68)
        SCHEMA_FIELD(::CUtlString                    , m_szIsAttackingKey                              , 0x80)
        SCHEMA_FIELD(CountdownTimer                  , m_ActionTimer                                   , 0x88)
        SCHEMA_FIELD(bool                            , m_bCrouching                                    , 0xA0)
    };

    class Relationship_t {
    public:
        SCHEMA_FIELD(Disposition_t                   , disposition                                     , 0x0)
        SCHEMA_FIELD(std::int32_t                    , priority                                        , 0x4)
    };

    class ParticleIndex_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Value                                         , 0x0)
    };

    class CPulseCell_LerpCameraSettings {
    public:
        SCHEMA_FIELD(float                           , m_flSeconds                                     , 0x90)
        SCHEMA_FIELD(PointCameraSettings_t           , m_Start                                         , 0x94)
        SCHEMA_FIELD(PointCameraSettings_t           , m_End                                           , 0xA4)
    };

    class WrappedPhysicsJoint_t {
    public:
        SCHEMA_FIELD(IPhysicsJoint*                  , m_pJoint                                        , 0x0)
    };

    class ResponseFollowup {
    public:
        SCHEMA_FIELD(char*                           , followup_concept                                , 0x0)
        SCHEMA_FIELD(char*                           , followup_contexts                               , 0x8)
        SCHEMA_FIELD(float                           , followup_delay                                  , 0x10)
        SCHEMA_FIELD(char*                           , followup_target                                 , 0x14)
        SCHEMA_FIELD(char*                           , followup_entityiotarget                         , 0x1C)
        SCHEMA_FIELD(char*                           , followup_entityioinput                          , 0x24)
        SCHEMA_FIELD(float                           , followup_entityiodelay                          , 0x2C)
        SCHEMA_FIELD(bool                            , bFired                                          , 0x30)
    };

    class CFiringModeFloat {
    public:
        SCHEMA_FIELD(float                           , m_flValues                                      , 0x0)
    };

    class CCSGameModeRules_Noop {
    public:
    };

    class shard_model_desc_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nModelID                                      , 0x8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterialBase                                 , 0x10)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterialDamageOverlay                        , 0x18)
        SCHEMA_FIELD(ShardSolid_t                    , m_solid                                         , 0x20)
        SCHEMA_FIELD(::Vector2D                      , m_vecPanelSize                                  , 0x24)
        SCHEMA_FIELD(::Vector2D                      , m_vecStressPositionA                            , 0x2C)
        SCHEMA_FIELD(::Vector2D                      , m_vecStressPositionB                            , 0x34)
        SCHEMA_FIELD(CNetworkUtlVectorBase<Vector2D> , m_vecPanelVertices                              , 0x40)
        SCHEMA_FIELD(CNetworkUtlVectorBase<Vector4D> , m_vInitialPanelVertices                         , 0x58)
        SCHEMA_FIELD(float                           , m_flGlassHalfThickness                          , 0x70)
        SCHEMA_FIELD(bool                            , m_bHasParent                                    , 0x74)
        SCHEMA_FIELD(bool                            , m_bParentFrozen                                 , 0x75)
        SCHEMA_FIELD(CUtlStringToken                 , m_SurfacePropStringToken                        , 0x78)
    };

    class CBaseModelEntity_OnDamageLevelChangedArgs_t {
    public:
        SCHEMA_FIELD(HitGroup_t                      , nHitGroup                                       , 0x0)
        SCHEMA_FIELD(std::int32_t                    , nDamageLevel                                    , 0x4)
        SCHEMA_FIELD(std::int32_t                    , nDamageLevelsRemaining                          , 0x8)
        SCHEMA_FIELD(std::int32_t                    , nPrevDamageLevel                                , 0xC)
    };

    class AI_Navigator_DebugSnapshotData_t_Waypoint_t {
    public:
        SCHEMA_FIELD(VectorWS                        , position                                        , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , nav_type                                        , 0xC)
        SCHEMA_FIELD(std::uint32_t                   , flags                                           , 0x10)
    };

    class CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
    };

    class CPulseCell_PlaySequence_CursorState_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseAnimGraph>         , m_hTarget                                       , 0x0)
    };

    class CEconItemAttribute {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_iAttributeDefinitionIndex                     , 0x30)
        SCHEMA_FIELD(float                           , m_flValue                                       , 0x34)
        SCHEMA_FIELD(float                           , m_flInitialValue                                , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nRefundableCurrency                           , 0x3C)
        SCHEMA_FIELD(bool                            , m_bSetBonus                                     , 0x40)
    };

    class CTeamplayRules {
    public:
    };

    class CGameChoreoServices {
    public:
        SCHEMA_FIELD(CHandle<CBaseModelEntity>       , m_hOwner                                        , 0x8)
        SCHEMA_FIELD(CHandle<CScriptedSequence>      , m_hScriptedSequence                             , 0xC)
        SCHEMA_FIELD(IChoreoServices_ScriptState_t   , m_scriptState                                   , 0x10)
        SCHEMA_FIELD(IChoreoServices_ChoreoState_t   , m_choreoState                                   , 0x14)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeStartedState                            , 0x18)
    };

    class ActiveModelConfig_t {
    public:
        SCHEMA_FIELD(ModelConfigHandle_t             , m_Handle                                        , 0x30)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_Name                                          , 0x38)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBaseModelEntity>>, m_AssociatedEntities                            , 0x40)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CUtlSymbolLarge>, m_AssociatedEntityNames                         , 0x58)
    };

    class CTestPulseIO_EntityNameStringArgs_t {
    public:
        SCHEMA_FIELD(CEntityNameString               , nameA                                           , 0x0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , strValueB                                       , 0x8)
    };

    class audioparams_t {
    public:
        SCHEMA_FIELD(::Vector                        , localSound                                      , 0x8)
        SCHEMA_FIELD(std::int32_t                    , soundscapeIndex                                 , 0x68)
        SCHEMA_FIELD(std::uint8_t                    , localBits                                       , 0x6C)
        SCHEMA_FIELD(std::int32_t                    , soundscapeEntityListIndex                       , 0x70)
        SCHEMA_FIELD(std::uint32_t                   , soundEventHash                                  , 0x74)
    };

    class CEntityComponent {
    public:
    };

    class CPulseCell_BaseLerp_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
    };

    class CBtNodeCondition {
    public:
        SCHEMA_FIELD(bool                            , m_bNegated                                      , 0x58)
    };

    class fogplayerparams_t {
    public:
        SCHEMA_FIELD(CHandle<CFogController>         , m_hCtrl                                         , 0x8)
        SCHEMA_FIELD(float                           , m_flTransitionTime                              , 0xC)
        SCHEMA_FIELD(::Color                         , m_OldColor                                      , 0x10)
        SCHEMA_FIELD(float                           , m_flOldStart                                    , 0x14)
        SCHEMA_FIELD(float                           , m_flOldEnd                                      , 0x18)
        SCHEMA_FIELD(float                           , m_flOldMaxDensity                               , 0x1C)
        SCHEMA_FIELD(float                           , m_flOldHDRColorScale                            , 0x20)
        SCHEMA_FIELD(float                           , m_flOldFarZ                                     , 0x24)
        SCHEMA_FIELD(::Color                         , m_NewColor                                      , 0x28)
        SCHEMA_FIELD(float                           , m_flNewStart                                    , 0x2C)
        SCHEMA_FIELD(float                           , m_flNewEnd                                      , 0x30)
        SCHEMA_FIELD(float                           , m_flNewMaxDensity                               , 0x34)
        SCHEMA_FIELD(float                           , m_flNewHDRColorScale                            , 0x38)
        SCHEMA_FIELD(float                           , m_flNewFarZ                                     , 0x3C)
    };

    class CAnimEventQueueListener {
    public:
    };

    class hudtextparms_t {
    public:
        SCHEMA_FIELD(::Color                         , color1                                          , 0x0)
        SCHEMA_FIELD(::Color                         , color2                                          , 0x4)
        SCHEMA_FIELD(std::uint8_t                    , effect                                          , 0x8)
        SCHEMA_FIELD(std::uint8_t                    , channel                                         , 0x9)
        SCHEMA_FIELD(float                           , x                                               , 0xC)
        SCHEMA_FIELD(float                           , y                                               , 0x10)
    };

    class ragdollelement_t {
    public:
        SCHEMA_FIELD(::Vector                        , originParentSpace                               , 0x0)
        SCHEMA_FIELD(std::int32_t                    , parentIndex                                     , 0x20)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x24)
        SCHEMA_FIELD(std::int32_t                    , m_nHeight                                       , 0x28)
    };

    class CCSWeaponBaseVData {
    public:
        SCHEMA_FIELD(CSWeaponType                    , m_WeaponType                                    , 0x520)
        SCHEMA_FIELD(CSWeaponCategory                , m_WeaponCategory                                , 0x524)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCNmSkeleton>>, m_szAnimSkeleton                                , 0x528)
        SCHEMA_FIELD(::Vector                        , m_vecMuzzlePos0                                 , 0x608)
        SCHEMA_FIELD(::Vector                        , m_vecMuzzlePos1                                 , 0x614)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIParticleSystemDefinition>>, m_szTracerParticle                              , 0x620)
        SCHEMA_FIELD(gear_slot_t                     , m_GearSlot                                      , 0x700)
        SCHEMA_FIELD(std::int32_t                    , m_GearSlotPosition                              , 0x704)
        SCHEMA_FIELD(loadout_slot_t                  , m_DefaultLoadoutSlot                            , 0x708)
        SCHEMA_FIELD(std::int32_t                    , m_nPrice                                        , 0x70C)
        SCHEMA_FIELD(std::int32_t                    , m_nKillAward                                    , 0x710)
        SCHEMA_FIELD(std::int32_t                    , m_nPrimaryReserveAmmoMax                        , 0x714)
        SCHEMA_FIELD(std::int32_t                    , m_nSecondaryReserveAmmoMax                      , 0x718)
        SCHEMA_FIELD(bool                            , m_bMeleeWeapon                                  , 0x71C)
        SCHEMA_FIELD(bool                            , m_bHasBurstMode                                 , 0x71D)
        SCHEMA_FIELD(bool                            , m_bIsRevolver                                   , 0x71E)
        SCHEMA_FIELD(bool                            , m_bCannotShootUnderwater                        , 0x71F)
        SCHEMA_FIELD(CGlobalSymbol                   , m_szName                                        , 0x720)
        SCHEMA_FIELD(CSWeaponSilencerType            , m_eSilencerType                                 , 0x728)
        SCHEMA_FIELD(std::int32_t                    , m_nCrosshairMinDistance                         , 0x72C)
        SCHEMA_FIELD(std::int32_t                    , m_nCrosshairDeltaDistance                       , 0x730)
        SCHEMA_FIELD(bool                            , m_bIsFullAuto                                   , 0x734)
        SCHEMA_FIELD(std::int32_t                    , m_nNumBullets                                   , 0x738)
        SCHEMA_FIELD(bool                            , m_bReloadsSingleShells                          , 0x73C)
        SCHEMA_FIELD(CFiringModeFloat                , m_flCycleTime                                   , 0x740)
        SCHEMA_FIELD(float                           , m_flCycleTimeWhenInBurstMode                    , 0x748)
        SCHEMA_FIELD(float                           , m_flTimeBetweenBurstShots                       , 0x74C)
        SCHEMA_FIELD(CFiringModeFloat                , m_flMaxSpeed                                    , 0x750)
        SCHEMA_FIELD(CFiringModeFloat                , m_flSpread                                      , 0x758)
        SCHEMA_FIELD(CFiringModeFloat                , m_flInaccuracyCrouch                            , 0x760)
        SCHEMA_FIELD(CFiringModeFloat                , m_flInaccuracyStand                             , 0x768)
        SCHEMA_FIELD(CFiringModeFloat                , m_flInaccuracyJump                              , 0x770)
        SCHEMA_FIELD(CFiringModeFloat                , m_flInaccuracyLand                              , 0x778)
        SCHEMA_FIELD(CFiringModeFloat                , m_flInaccuracyLadder                            , 0x780)
        SCHEMA_FIELD(CFiringModeFloat                , m_flInaccuracyFire                              , 0x788)
        SCHEMA_FIELD(CFiringModeFloat                , m_flInaccuracyMove                              , 0x790)
        SCHEMA_FIELD(CFiringModeFloat                , m_flRecoilAngle                                 , 0x798)
        SCHEMA_FIELD(CFiringModeFloat                , m_flRecoilAngleVariance                         , 0x7A0)
        SCHEMA_FIELD(CFiringModeFloat                , m_flRecoilMagnitude                             , 0x7A8)
        SCHEMA_FIELD(CFiringModeFloat                , m_flRecoilMagnitudeVariance                     , 0x7B0)
        SCHEMA_FIELD(CFiringModeInt                  , m_nTracerFrequency                              , 0x7B8)
        SCHEMA_FIELD(float                           , m_flInaccuracyJumpInitial                       , 0x7C0)
        SCHEMA_FIELD(float                           , m_flInaccuracyJumpApex                          , 0x7C4)
        SCHEMA_FIELD(float                           , m_flInaccuracyReload                            , 0x7C8)
        SCHEMA_FIELD(float                           , m_flDeployDuration                              , 0x7CC)
        SCHEMA_FIELD(float                           , m_flDisallowAttackAfterReloadStartDuration      , 0x7D0)
        SCHEMA_FIELD(std::int32_t                    , m_nBurstShotCount                               , 0x7D4)
        SCHEMA_FIELD(bool                            , m_bAllowBurstHolster                            , 0x7D8)
        SCHEMA_FIELD(std::int32_t                    , m_nRecoilSeed                                   , 0x7DC)
        SCHEMA_FIELD(std::int32_t                    , m_nSpreadSeed                                   , 0x7E0)
        SCHEMA_FIELD(float                           , m_flAttackMovespeedFactor                       , 0x7E4)
        SCHEMA_FIELD(float                           , m_flInaccuracyPitchShift                        , 0x7E8)
        SCHEMA_FIELD(float                           , m_flInaccuracyAltSoundThreshold                 , 0x7EC)
        SCHEMA_FIELD(::CUtlString                    , m_szUseRadioSubtitle                            , 0x7F0)
        SCHEMA_FIELD(bool                            , m_bUnzoomsAfterShot                             , 0x7F8)
        SCHEMA_FIELD(bool                            , m_bHideViewModelWhenZoomed                      , 0x7F9)
        SCHEMA_FIELD(std::int32_t                    , m_nZoomLevels                                   , 0x7FC)
        SCHEMA_FIELD(std::int32_t                    , m_nZoomFOV1                                     , 0x800)
        SCHEMA_FIELD(std::int32_t                    , m_nZoomFOV2                                     , 0x804)
        SCHEMA_FIELD(float                           , m_flZoomTime0                                   , 0x808)
        SCHEMA_FIELD(float                           , m_flZoomTime1                                   , 0x80C)
        SCHEMA_FIELD(float                           , m_flZoomTime2                                   , 0x810)
        SCHEMA_FIELD(float                           , m_flIronSightPullUpSpeed                        , 0x814)
        SCHEMA_FIELD(float                           , m_flIronSightPutDownSpeed                       , 0x818)
        SCHEMA_FIELD(float                           , m_flIronSightFOV                                , 0x81C)
        SCHEMA_FIELD(float                           , m_flIronSightPivotForward                       , 0x820)
        SCHEMA_FIELD(float                           , m_flIronSightLooseness                          , 0x824)
        SCHEMA_FIELD(std::int32_t                    , m_nDamage                                       , 0x828)
        SCHEMA_FIELD(float                           , m_flHeadshotMultiplier                          , 0x82C)
        SCHEMA_FIELD(float                           , m_flArmorRatio                                  , 0x830)
        SCHEMA_FIELD(float                           , m_flPenetration                                 , 0x834)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x838)
        SCHEMA_FIELD(float                           , m_flRangeModifier                               , 0x83C)
        SCHEMA_FIELD(float                           , m_flFlinchVelocityModifierLarge                 , 0x840)
        SCHEMA_FIELD(float                           , m_flFlinchVelocityModifierSmall                 , 0x844)
        SCHEMA_FIELD(float                           , m_flRecoveryTimeCrouch                          , 0x848)
        SCHEMA_FIELD(float                           , m_flRecoveryTimeStand                           , 0x84C)
        SCHEMA_FIELD(float                           , m_flRecoveryTimeCrouchFinal                     , 0x850)
        SCHEMA_FIELD(float                           , m_flRecoveryTimeStandFinal                      , 0x854)
        SCHEMA_FIELD(std::int32_t                    , m_nRecoveryTransitionStartBullet                , 0x858)
        SCHEMA_FIELD(std::int32_t                    , m_nRecoveryTransitionEndBullet                  , 0x85C)
        SCHEMA_FIELD(float                           , m_flThrowVelocity                               , 0x860)
        SCHEMA_FIELD(::Vector                        , m_vSmokeColor                                   , 0x864)
        SCHEMA_FIELD(CGlobalSymbol                   , m_szAnimClass                                   , 0x870)
    };

    class CPulseServerFuncs {
    public:
    };

    class CAnimEventListener {
    public:
    };

    class CPulseCell_BaseYieldingInflow {
    public:
    };

    class CPulseCell_Base {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nEditorNodeID                                 , 0x8)
    };

    class CScriptUniformRandomStream {
    public:
        SCHEMA_FIELD(HSCRIPT                         , m_hScriptScope                                  , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nInitialSeed                                  , 0x9C)
    };

    class CAnimEventListenerBase {
    public:
    };

    class CBreakableStageHelper {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentStage                                 , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nStageCount                                   , 0xC)
    };

    class CCSPointPulseAPI {
    public:
    };

    class PhysicsRagdollPose_t {
    public:
        SCHEMA_FIELD(CNetworkUtlVectorBase<CTransform>, m_Transforms                                    , 0x8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOwner                                        , 0x20)
        SCHEMA_FIELD(bool                            , m_bSetFromDebugHistory                          , 0x24)
    };

    class CResponseQueue {
    public:
        SCHEMA_FIELD(CUtlVector<CAI_Expresser*>      , m_ExpresserTargets                              , 0x38)
    };

    class CDestructiblePart_DamageLevel {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sName                                         , 0x0)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sBreakablePieceName                           , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nBodyGroupValue                               , 0x10)
        SCHEMA_FIELD(CSkillInt                       , m_nHealth                                       , 0x14)
        SCHEMA_FIELD(float                           , m_flCriticalDamagePercent                       , 0x24)
        SCHEMA_FIELD(EDestructiblePartDamagePassThroughType, m_nDamagePassthroughType                        , 0x28)
        SCHEMA_FIELD(DestructiblePartDestructionDeathBehavior_t, m_nDestructionDeathBehavior                     , 0x2C)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sCustomDeathHandshake                         , 0x30)
        SCHEMA_FIELD(bool                            , m_bShouldDestroyOnDeath                         , 0x38)
        SCHEMA_FIELD(CRangeFloat                     , m_flDeathDestroyTime                            , 0x3C)
    };

    class CSkillFloat {
    public:
        SCHEMA_FIELD(float                           , m_pValue                                        , 0x0)
    };

    class CPulseGraphInstance_ServerEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOwner                                        , 0x1A8)
        SCHEMA_FIELD(bool                            , m_bActivated                                    , 0x1AC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sNameFixupStaticPrefix                        , 0x1B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sNameFixupParent                              , 0x1B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sNameFixupLocal                               , 0x1C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sProceduralWorldNameForRelays                 , 0x1C8)
    };

    class CPulseCell_LimitCount_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bLimitCountPasses                             , 0x0)
    };

    class CRemapFloat {
    public:
        SCHEMA_FIELD(float                           , m_pValue                                        , 0x0)
    };

    class CNavVolume {
    public:
    };

    class AutoRoomDoorwayPairs_t {
    public:
        SCHEMA_FIELD(::Vector                        , vP1                                             , 0x0)
        SCHEMA_FIELD(::Vector                        , vP2                                             , 0xC)
    };

    class CPulseCell_Outflow_PlayVOLine_CursorState_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_sceneInstance                                 , 0x0)
    };

    class CPulseCell_Step_DebugLog {
    public:
    };

    class CPulseCell_WaitForObservable {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnTrue                                        , 0xC0)
    };

    class SellbackPurchaseEntry_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_unDefIdx                                      , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_nCost                                         , 0x34)
        SCHEMA_FIELD(std::int32_t                    , m_nPrevArmor                                    , 0x38)
        SCHEMA_FIELD(bool                            , m_bPrevHelmet                                   , 0x3C)
        SCHEMA_FIELD(CEntityHandle                   , m_hItem                                         , 0x40)
    };

    class CCSPlayerLegacyJump {
    public:
        SCHEMA_FIELD(bool                            , m_bOldJumpPressed                               , 0x10)
        SCHEMA_FIELD(float                           , m_flJumpPressedTime                             , 0x14)
    };

    class CDamageRecord {
    public:
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_PlayerDamager                                 , 0x30)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_PlayerRecipient                               , 0x34)
        SCHEMA_FIELD(CHandle<CCSPlayerController>    , m_hPlayerControllerDamager                      , 0x38)
        SCHEMA_FIELD(CHandle<CCSPlayerController>    , m_hPlayerControllerRecipient                    , 0x3C)
        SCHEMA_FIELD(::CUtlString                    , m_szPlayerDamagerName                           , 0x40)
        SCHEMA_FIELD(::CUtlString                    , m_szPlayerRecipientName                         , 0x48)
        SCHEMA_FIELD(std::uint64_t                   , m_DamagerXuid                                   , 0x50)
        SCHEMA_FIELD(std::uint64_t                   , m_RecipientXuid                                 , 0x58)
        SCHEMA_FIELD(float                           , m_flBulletsDamage                               , 0x60)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0x64)
        SCHEMA_FIELD(float                           , m_flActualHealthRemoved                         , 0x68)
        SCHEMA_FIELD(std::int32_t                    , m_iNumHits                                      , 0x6C)
        SCHEMA_FIELD(std::int32_t                    , m_iLastBulletUpdate                             , 0x70)
        SCHEMA_FIELD(bool                            , m_bIsOtherEnemy                                 , 0x74)
        SCHEMA_FIELD(EKillTypes_t                    , m_killType                                      , 0x75)
    };

    class ServerAuthoritativeWeaponSlot_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , unClass                                         , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , unSlot                                          , 0x32)
        SCHEMA_FIELD(std::uint16_t                   , unItemDefIdx                                    , 0x34)
    };

    class CountdownTimer {
    public:
        SCHEMA_FIELD(float                           , m_duration                                      , 0x8)
        SCHEMA_FIELD(::GameTime_t                    , m_timestamp                                     , 0xC)
        SCHEMA_FIELD(float                           , m_timescale                                     , 0x10)
        SCHEMA_FIELD(::WorldGroupId_t                , m_nWorldGroupId                                 , 0x14)
    };

    class CPulseCell_BooleanSwitchState {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Always                                        , 0xC0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenTrue                                      , 0x108)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenFalse                                     , 0x150)
    };

    class CSceneRequest {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szPayloadVDataName                            , 0x0)
        SCHEMA_FIELD(SceneRequestHandle_t            , m_uHandle                                       , 0x8)
        SCHEMA_FIELD(ESceneRequestState_t            , m_state                                         , 0xC)
        SCHEMA_FIELD(ENPCBehaviorOverride_t          , m_nNPCBehaviorOverride                          , 0x10)
        SCHEMA_FIELD(CUtlVector<SceneRequestTargetMapPair_t>, m_vecActorMap                                   , 0x18)
        SCHEMA_FIELD(CUtlVector<SceneRequestTargetMapPair_t>, m_vecAnchorMap                                  , 0x30)
        SCHEMA_FIELD(CUtlVector<SceneRequestTargetMapPair_t>, m_vecGraphMap                                   , 0x48)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOwner                                        , 0x60)
        SCHEMA_FIELD(KeyValues3                      , m_nameMapKV3                                    , 0x68)
    };

    class Extent {
    public:
        SCHEMA_FIELD(VectorWS                        , lo                                              , 0x0)
        SCHEMA_FIELD(VectorWS                        , hi                                              , 0xC)
    };

    class CBasePlayerVData {
    public:
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCModel>>, m_sModelName                                    , 0x28)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCModel>>, m_sModelNameAg2Override                         , 0x108)
        SCHEMA_FIELD(CSkillFloat                     , m_flHeadDamageMultiplier                        , 0x1E8)
        SCHEMA_FIELD(CSkillFloat                     , m_flChestDamageMultiplier                       , 0x1F8)
        SCHEMA_FIELD(CSkillFloat                     , m_flStomachDamageMultiplier                     , 0x208)
        SCHEMA_FIELD(CSkillFloat                     , m_flArmDamageMultiplier                         , 0x218)
        SCHEMA_FIELD(CSkillFloat                     , m_flLegDamageMultiplier                         , 0x228)
        SCHEMA_FIELD(float                           , m_flHoldBreathTime                              , 0x238)
        SCHEMA_FIELD(float                           , m_flDrowningDamageInterval                      , 0x23C)
        SCHEMA_FIELD(std::int32_t                    , m_nDrowningDamageInitial                        , 0x240)
        SCHEMA_FIELD(std::int32_t                    , m_nDrowningDamageMax                            , 0x244)
        SCHEMA_FIELD(std::int32_t                    , m_nWaterSpeed                                   , 0x248)
        SCHEMA_FIELD(float                           , m_flUseRange                                    , 0x24C)
        SCHEMA_FIELD(float                           , m_flUseAngleTolerance                           , 0x250)
        SCHEMA_FIELD(float                           , m_flCrouchTime                                  , 0x254)
    };

    class PhysBlockHeader_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , nSaved                                          , 0x0)
        SCHEMA_FIELD(std::uint64_t                   , pWorldObject                                    , 0x8)
    };

    class PulseNodeDynamicOutflows_t {
    public:
        SCHEMA_FIELD(CUtlVector<PulseNodeDynamicOutflows_t_DynamicOutflow_t>, m_Outflows                                      , 0x0)
    };

    class IEconItemInterface {
    public:
    };

    class CNmAimCSTask {
    public:
    };

    class CGameRules {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
        SCHEMA_FIELD(char                            , m_szQuestName                                   , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_nQuestPhase                                   , 0xB0)
        SCHEMA_FIELD(std::uint32_t                   , m_nLastMatchTime                                , 0xB4)
        SCHEMA_FIELD(std::uint64_t                   , m_nLastMatchTime_MatchID64                      , 0xB8)
        SCHEMA_FIELD(std::int32_t                    , m_nTotalPausedTicks                             , 0xC0)
        SCHEMA_FIELD(std::int32_t                    , m_nPauseStartTick                               , 0xC4)
        SCHEMA_FIELD(bool                            , m_bGamePaused                                   , 0xC8)
    };

    class CBaseAnimGraphDestructibleParts_GraphController {
    public:
    };

    class CNetworkedSequenceOperation {
    public:
        SCHEMA_FIELD(HSequence                       , m_hSequence                                     , 0x8)
        SCHEMA_FIELD(float                           , m_flPrevCycle                                   , 0xC)
        SCHEMA_FIELD(float                           , m_flCycle                                       , 0x10)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_flWeight                                      , 0x14)
        SCHEMA_FIELD(bool                            , m_bSequenceChangeNetworked                      , 0x1C)
        SCHEMA_FIELD(bool                            , m_bDiscontinuity                                , 0x1D)
        SCHEMA_FIELD(float                           , m_flPrevCycleFromDiscontinuity                  , 0x20)
        SCHEMA_FIELD(float                           , m_flPrevCycleForAnimEventDetection              , 0x24)
    };

    class CBtActionAim {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_szSensorInputKey                              , 0x68)
        SCHEMA_FIELD(::CUtlString                    , m_szAimReadyKey                                 , 0x80)
        SCHEMA_FIELD(float                           , m_flZoomCooldownTimestamp                       , 0x88)
        SCHEMA_FIELD(bool                            , m_bDoneAiming                                   , 0x8C)
        SCHEMA_FIELD(float                           , m_flLerpStartTime                               , 0x90)
        SCHEMA_FIELD(float                           , m_flNextLookTargetLerpTime                      , 0x94)
        SCHEMA_FIELD(float                           , m_flPenaltyReductionRatio                       , 0x98)
        SCHEMA_FIELD(::QAngle                        , m_NextLookTarget                                , 0x9C)
        SCHEMA_FIELD(CountdownTimer                  , m_AimTimer                                      , 0xA8)
        SCHEMA_FIELD(CountdownTimer                  , m_SniperHoldTimer                               , 0xC0)
        SCHEMA_FIELD(CountdownTimer                  , m_FocusIntervalTimer                            , 0xD8)
        SCHEMA_FIELD(bool                            , m_bAcquired                                     , 0xF0)
    };

    class CPulseCell_BaseLerp {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
    };

    class CPulseCell_Step_FollowEntity {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_ParamBoneOrAttachName                         , 0x48)
        SCHEMA_FIELD(::CUtlString                    , m_ParamBoneOrAttachNameChild                    , 0x50)
    };

    class PointCameraSettings_t {
    public:
        SCHEMA_FIELD(float                           , m_flNearBlurryDistance                          , 0x0)
        SCHEMA_FIELD(float                           , m_flNearCrispDistance                           , 0x4)
        SCHEMA_FIELD(float                           , m_flFarCrispDistance                            , 0x8)
        SCHEMA_FIELD(float                           , m_flFarBlurryDistance                           , 0xC)
    };

    class CBuoyancyHelper {
    public:
        SCHEMA_FIELD(IPhysicsMotionController*       , m_pController                                   , 0x8)
        SCHEMA_FIELD(CUtlStringToken                 , m_nFluidType                                    , 0x18)
        SCHEMA_FIELD(float                           , m_flFluidDensity                                , 0x1C)
        SCHEMA_FIELD(float                           , m_flNeutrallyBuoyantGravity                     , 0x20)
        SCHEMA_FIELD(float                           , m_flNeutrallyBuoyantLinearDamping               , 0x24)
        SCHEMA_FIELD(float                           , m_flNeutrallyBuoyantAngularDamping              , 0x28)
        SCHEMA_FIELD(bool                            , m_bNeutrallyBuoyant                             , 0x2C)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecFractionOfWheelSubmergedForWheelFriction   , 0x30)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecWheelFrictionScales                        , 0x48)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecFractionOfWheelSubmergedForWheelDrag       , 0x60)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecWheelDrag                                  , 0x78)
    };

    class SignatureOutflow_Continue {
    public:
    };

    class CBtNodeComposite {
    public:
    };

    class CMultiplayRules {
    public:
    };

    class CDebugDrawHistoryData {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x0)
        SCHEMA_FIELD(ESceneViewDebugOverlaysListenerDataType_t, m_etype                                         , 0x4)
        SCHEMA_FIELD(CUtlLeanVector<Vector4D>        , m_vectors                                       , 0x8)
        SCHEMA_FIELD(CUtlLeanVector<Color>           , m_colors                                        , 0x18)
        SCHEMA_FIELD(CUtlLeanVector<float32>         , m_dimensions                                    , 0x28)
        SCHEMA_FIELD(CUtlLeanVector<float64>         , m_times                                         , 0x38)
        SCHEMA_FIELD(CUtlLeanVector<uint64>          , m_uint64s                                       , 0x48)
        SCHEMA_FIELD(CUtlLeanVector<bool>            , m_bools                                         , 0x58)
        SCHEMA_FIELD(CUtlLeanVector<CUtlString>      , m_strings                                       , 0x68)
    };

    class CPulseCell_IsRequirementValid {
    public:
    };

    class ragdollhierarchyjoint_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , parentIndex                                     , 0x0)
        SCHEMA_FIELD(std::int32_t                    , childIndex                                      , 0x4)
    };

    class CPulseCell_LerpCameraSettings_CursorState_t {
    public:
        SCHEMA_FIELD(CHandle<CPointCamera>           , m_hCamera                                       , 0x8)
        SCHEMA_FIELD(PointCameraSettings_t           , m_OverlaidStart                                 , 0xC)
        SCHEMA_FIELD(PointCameraSettings_t           , m_OverlaidEnd                                   , 0x1C)
    };

    class CRangeFloat {
    public:
        SCHEMA_FIELD(float                           , m_pValue                                        , 0x0)
    };

    class DecalGroupOption_t {
    public:
        SCHEMA_FIELD(CStrongHandleCopyable<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0x0)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sSequenceName                                 , 0x8)
        SCHEMA_FIELD(float                           , m_flProbability                                 , 0x10)
        SCHEMA_FIELD(bool                            , m_bEnableAngleBetweenNormalAndGravityRange      , 0x14)
        SCHEMA_FIELD(float                           , m_flMinAngleBetweenNormalAndGravity             , 0x18)
        SCHEMA_FIELD(float                           , m_flMaxAngleBetweenNormalAndGravity             , 0x1C)
    };

    class CNetworkVelocityVector {
    public:
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecX                                          , 0x10)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecY                                          , 0x18)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecZ                                          , 0x20)
    };

    class CPulse_ResumePoint {
    public:
    };

    class CAI_Expresser {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flStopTalkTime                                , 0x60)
        SCHEMA_FIELD(::GameTime_t                    , m_flStopTalkTimeWithoutDelay                    , 0x64)
        SCHEMA_FIELD(::GameTime_t                    , m_flQueuedSpeechTime                            , 0x68)
        SCHEMA_FIELD(::GameTime_t                    , m_flBlockedTalkTime                             , 0x6C)
        SCHEMA_FIELD(std::int32_t                    , m_voicePitch                                    , 0x70)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastTimeAcceptedSpeak                       , 0x74)
        SCHEMA_FIELD(bool                            , m_bAllowSpeakingInterrupts                      , 0x78)
        SCHEMA_FIELD(bool                            , m_bConsiderSceneInvolvementAsSpeech             , 0x79)
        SCHEMA_FIELD(bool                            , m_bSceneEntityDisabled                          , 0x7A)
        SCHEMA_FIELD(std::int32_t                    , m_nLastSpokenPriority                           , 0x7C)
        SCHEMA_FIELD(CBaseModelEntity*               , m_pOuter                                        , 0x98)
    };

    class CBtNodeDecorator {
    public:
    };

    class AnimGraph2SerializedPoseRecipeSlot_t {
    public:
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_topology                                      , 0x30)
    };

    class CPulseCell_WaitForCursorsWithTagBase {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToWait                         , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WaitComplete                                  , 0x50)
    };

    class CSkillInt {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_pValue                                        , 0x0)
    };

    class CAttributeManager {
    public:
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_Providers                                     , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_iReapplyProvisionParity                       , 0x20)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOuter                                        , 0x24)
        SCHEMA_FIELD(bool                            , m_bPreventLoopback                              , 0x28)
        SCHEMA_FIELD(attributeprovidertypes_t        , m_ProviderType                                  , 0x2C)
        SCHEMA_FIELD(CUtlVector<CAttributeManager_cached_attribute_float_t>, m_CachedResults                                 , 0x30)
    };

    class CSAdditionalPerRoundStats_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_numChickensKilled                             , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_killsWhileBlind                               , 0x4)
        SCHEMA_FIELD(std::int32_t                    , m_bombCarrierkills                              , 0x8)
        SCHEMA_FIELD(float                           , m_flBurnDamageInflicted                         , 0xC)
        SCHEMA_FIELD(float                           , m_flBlastDamageInflicted                        , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_iDinks                                        , 0x14)
        SCHEMA_FIELD(bool                            , m_bFreshStartThisRound                          , 0x18)
        SCHEMA_FIELD(bool                            , m_bBombPlantedAndAlive                          , 0x19)
        SCHEMA_FIELD(std::int32_t                    , m_nDefuseStarts                                 , 0x1C)
        SCHEMA_FIELD(std::int32_t                    , m_nHostagePickUps                               , 0x20)
        SCHEMA_FIELD(std::int32_t                    , m_numTeammatesFlashed                           , 0x24)
        SCHEMA_FIELD(::CUtlString                    , m_strAnnotationsWorkshopId                      , 0x28)
    };

    class CBtNodeConditionInactive {
    public:
        SCHEMA_FIELD(float                           , m_flRoundStartThresholdSeconds                  , 0x78)
        SCHEMA_FIELD(float                           , m_flSensorInactivityThresholdSeconds            , 0x7C)
        SCHEMA_FIELD(CountdownTimer                  , m_SensorInactivityTimer                         , 0x80)
    };

    class CSAdditionalMatchStats_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_numRoundsSurvivedStreak                       , 0xF8)
        SCHEMA_FIELD(std::int32_t                    , m_maxNumRoundsSurvivedStreak                    , 0xFC)
        SCHEMA_FIELD(std::int32_t                    , m_numRoundsSurvivedTotal                        , 0x100)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundsWonWithoutPurchase                     , 0x104)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundsWonWithoutPurchaseTotal                , 0x108)
        SCHEMA_FIELD(std::int32_t                    , m_numFirstKills                                 , 0x10C)
        SCHEMA_FIELD(std::int32_t                    , m_numClutchKills                                , 0x110)
        SCHEMA_FIELD(std::int32_t                    , m_numPistolKills                                , 0x114)
        SCHEMA_FIELD(std::int32_t                    , m_numSniperKills                                , 0x118)
        SCHEMA_FIELD(std::int32_t                    , m_iNumSuicides                                  , 0x11C)
        SCHEMA_FIELD(std::int32_t                    , m_iNumTeamKills                                 , 0x120)
        SCHEMA_FIELD(float                           , m_flTeamDamage                                  , 0x124)
    };

    class AI_DefaultNPC_DebugSnapshotData_t_PathQuery_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_sInitialQueryName                             , 0x0)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sCurrentQueryName                             , 0x8)
        SCHEMA_FIELD(CGlobalSymbol                   , m_nMode                                         , 0x10)
        SCHEMA_FIELD(CGlobalSymbol                   , m_nType                                         , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , m_nState                                        , 0x20)
    };

    class CGameScriptedMoveDef_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vDestOffset                                   , 0x0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hDestEntity                                   , 0xC)
        SCHEMA_FIELD(::QAngle                        , m_angDest                                       , 0x10)
        SCHEMA_FIELD(float                           , m_flDuration                                    , 0x1C)
        SCHEMA_FIELD(float                           , m_flAngRate                                     , 0x20)
        SCHEMA_FIELD(float                           , m_flMoveSpeed                                   , 0x24)
        SCHEMA_FIELD(bool                            , m_bAimDisabled                                  , 0x28)
        SCHEMA_FIELD(bool                            , m_bIgnoreRotation                               , 0x29)
        SCHEMA_FIELD(ForcedCrouchState_t             , m_nForcedCrouchState                            , 0x2C)
    };

    class CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
    };

    class CNavVolumeAll {
    public:
    };

    class CSingleplayRules {
    public:
        SCHEMA_FIELD(bool                            , m_bSinglePlayerGameEnding                       , 0xD0)
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

    class CVectorExponentialMovingAverage {
    public:
    };

    class CPulseCell_InlineNodeSkipSelector {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nFlowNodeID                                   , 0x48)
        SCHEMA_FIELD(bool                            , m_bAnd                                          , 0x4C)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_PassOutflow                                   , 0x50)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_FailOutflow                                   , 0x68)
    };

    class CPhysicsShake {
    public:
        SCHEMA_FIELD(::Vector                        , m_force                                         , 0x8)
    };

    class CFootstepTableHandle {
    public:
    };

    class PulseScriptedSequenceData_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nActorID                                      , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_szPreIdleSequence                             , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_szEntrySequence                               , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_szSequence                                    , 0x18)
        SCHEMA_FIELD(::CUtlString                    , m_szExitSequence                                , 0x20)
        SCHEMA_FIELD(ScriptedMoveTo_t                , m_nMoveTo                                       , 0x28)
        SCHEMA_FIELD(SharedMovementGait_t            , m_nMoveToGait                                   , 0x2C)
        SCHEMA_FIELD(ScriptedHeldWeaponBehavior_t    , m_nHeldWeaponBehavior                           , 0x30)
        SCHEMA_FIELD(bool                            , m_bLoopPreIdleSequence                          , 0x34)
        SCHEMA_FIELD(bool                            , m_bLoopActionSequence                           , 0x35)
        SCHEMA_FIELD(bool                            , m_bLoopPostIdleSequence                         , 0x36)
        SCHEMA_FIELD(bool                            , m_bIgnoreLookAt                                 , 0x37)
    };

    class CCSPlayerController_InventoryServices_NetworkedLoadoutSlot_t {
    public:
        SCHEMA_FIELD(CEconItemView*                  , pItem                                           , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , team                                            , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , slot                                            , 0xA)
    };

    class SignatureOutflow_Resume {
    public:
    };

    class CTakeDamageResult {
    public:
        SCHEMA_FIELD(CTakeDamageInfo*                , m_pOriginatingInfo                              , 0x0)
        SCHEMA_FIELD(CUtlLeanVector<DestructiblePartDamageRequest_t>, m_DestructibleHitGroupRequests                  , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nHealthLost                                   , 0x18)
        SCHEMA_FIELD(std::int32_t                    , m_nHealthBefore                                 , 0x1C)
        SCHEMA_FIELD(float                           , m_flDamageDealt                                 , 0x20)
        SCHEMA_FIELD(float                           , m_flPreModifiedDamage                           , 0x24)
        SCHEMA_FIELD(std::int32_t                    , m_nTotalledHealthLost                           , 0x28)
        SCHEMA_FIELD(float                           , m_flTotalledDamageDealt                         , 0x2C)
        SCHEMA_FIELD(float                           , m_flTotalledPreModifiedDamage                   , 0x30)
        SCHEMA_FIELD(float                           , m_flNewDamageAccumulatorValue                   , 0x34)
        SCHEMA_FIELD(TakeDamageFlags_t               , m_nDamageFlags                                  , 0x38)
        SCHEMA_FIELD(bool                            , m_bWasDamageSuppressed                          , 0x40)
        SCHEMA_FIELD(bool                            , m_bSuppressFlinch                               , 0x41)
        SCHEMA_FIELD(HitGroup_t                      , m_nOverrideFlinchHitGroup                       , 0x44)
    };

    class IHasAttributes {
    public:
    };

    class CPulseCell_Step_EntFire {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_Input                                         , 0x48)
    };

    class CBtActionMoveTo {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_szDestinationInputKey                         , 0x60)
        SCHEMA_FIELD(::CUtlString                    , m_szHidingSpotInputKey                          , 0x68)
        SCHEMA_FIELD(::CUtlString                    , m_szThreatInputKey                              , 0x70)
        SCHEMA_FIELD(::Vector                        , m_vecDestination                                , 0x78)
        SCHEMA_FIELD(bool                            , m_bAutoLookAdjust                               , 0x84)
        SCHEMA_FIELD(bool                            , m_bComputePath                                  , 0x85)
        SCHEMA_FIELD(float                           , m_flDamagingAreasPenaltyCost                    , 0x88)
        SCHEMA_FIELD(CountdownTimer                  , m_CheckApproximateCornersTimer                  , 0x90)
        SCHEMA_FIELD(CountdownTimer                  , m_CheckHighPriorityItem                         , 0xA8)
        SCHEMA_FIELD(CountdownTimer                  , m_RepathTimer                                   , 0xC0)
        SCHEMA_FIELD(float                           , m_flArrivalEpsilon                              , 0xD8)
        SCHEMA_FIELD(float                           , m_flAdditionalArrivalEpsilon2D                  , 0xDC)
        SCHEMA_FIELD(float                           , m_flHidingSpotCheckDistanceThreshold            , 0xE0)
        SCHEMA_FIELD(float                           , m_flNearestAreaDistanceThreshold                , 0xE4)
    };

    class CSPerRoundStats_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iKills                                        , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_iDeaths                                       , 0x34)
        SCHEMA_FIELD(std::int32_t                    , m_iAssists                                      , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_iDamage                                       , 0x3C)
        SCHEMA_FIELD(std::int32_t                    , m_iEquipmentValue                               , 0x40)
        SCHEMA_FIELD(std::int32_t                    , m_iMoneySaved                                   , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_iKillReward                                   , 0x48)
        SCHEMA_FIELD(std::int32_t                    , m_iLiveTime                                     , 0x4C)
        SCHEMA_FIELD(std::int32_t                    , m_iHeadShotKills                                , 0x50)
        SCHEMA_FIELD(std::int32_t                    , m_iObjective                                    , 0x54)
        SCHEMA_FIELD(std::int32_t                    , m_iCashEarned                                   , 0x58)
        SCHEMA_FIELD(std::int32_t                    , m_iUtilityDamage                                , 0x5C)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemiesFlashed                               , 0x60)
    };

    class CPulseMathlib {
    public:
    };

    class CPulseExecCursor {
    public:
    };

    class CPulseCell_Value_Curve {
    public:
        SCHEMA_FIELD(CPiecewiseCurve                 , m_Curve                                         , 0x48)
    };

    class PulseObservableBoolExpression_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EvaluateConnection                            , 0x0)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeVarIndex_t>, m_DependentObservableVars                       , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeBlackboardReferenceIndex_t>, m_DependentObservableBlackboardReferences       , 0x60)
    };

    class ConstraintSoundInfo {
    public:
        SCHEMA_FIELD(VelocitySampler                 , m_vSampler                                      , 0x8)
        SCHEMA_FIELD(SimpleConstraintSoundProfile    , m_soundProfile                                  , 0x20)
        SCHEMA_FIELD(::Vector                        , m_forwardAxis                                   , 0x40)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTravelSoundFwd                             , 0x50)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTravelSoundBack                            , 0x58)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszReversalSoundSmall                         , 0x78)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszReversalSoundMedium                        , 0x80)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszReversalSoundLarge                         , 0x88)
        SCHEMA_FIELD(bool                            , m_bPlayTravelSound                              , 0x90)
        SCHEMA_FIELD(bool                            , m_bPlayReversalSound                            , 0x91)
    };

    class CPulseArraylib {
    public:
    };

    class RotatorHistoryEntry_t {
    public:
        SCHEMA_FIELD(::Quaternion                    , qInvChange                                      , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , flTimeRotationStart                             , 0x10)
    };

    class thinkfunc_t {
    public:
        SCHEMA_FIELD(BASEPTR                         , m_think                                         , 0x0)
        SCHEMA_FIELD(HSCRIPT                         , m_hFn                                           , 0x8)
        SCHEMA_FIELD(CUtlStringToken                 , m_nContext                                      , 0x10)
        SCHEMA_FIELD(::GameTick_t                    , m_nNextThinkTick                                , 0x14)
        SCHEMA_FIELD(::GameTick_t                    , m_nLastThinkTick                                , 0x18)
    };

    class CPulseCell_Inflow_Wait {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
    };

    class CPulseCell_IntervalTimer {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_Completed                                     , 0x48)
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_OnInterval                                    , 0x90)
    };

    class CPulseCell_LimitCount {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nLimitCount                                   , 0x48)
    };

    class AI_BaseNPC_DebugSnapshotData_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , npc_state                                       , 0x8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , current_enemy                                   , 0x10)
        SCHEMA_FIELD(::CUtlString                    , s_current_schedule                              , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , s_current_task                                  , 0x20)
        SCHEMA_FIELD(::CUtlString                    , s_schedule_interrupt_reason                     , 0x28)
        SCHEMA_FIELD(::CUtlString                    , s_schedule_fail_reason                          , 0x30)
        SCHEMA_FIELD(CUtlVector<CGlobalSymbol>       , conditions                                      , 0x38)
        SCHEMA_FIELD(CUtlVector<CGlobalSymbol>       , anim_events                                     , 0x50)
        SCHEMA_FIELD(CGlobalSymbol                   , e_action_body_section                           , 0x68)
        SCHEMA_FIELD(CGlobalSymbol                   , e_movement_body_section                         , 0x70)
    };

    class AI_BaseNPCAnimGraph_DebugSnapshotData_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , e_action_desired                                , 0x8)
        SCHEMA_FIELD(bool                            , b_action_restart                                , 0x10)
        SCHEMA_FIELD(CGlobalSymbol                   , e_movement_type_desired                         , 0x18)
        SCHEMA_FIELD(bool                            , b_movement_type_restart                         , 0x20)
    };

    class CFuncMoverAPI {
    public:
    };

    class CPulseCell_Timeline {
    public:
        SCHEMA_FIELD(CUtlVector<CPulseCell_Timeline_TimelineEvent_t>, m_TimelineEvents                                , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class CCSPlayerAnimationState {
    public:
        SCHEMA_FIELD(CCSPlayerAnimationState_MoveType_t, m_currentMoveType                               , 0x18)
        SCHEMA_FIELD(CCSPlayerAnimationState_GroundMoveState_t, m_groundMoveState                               , 0x19)
        SCHEMA_FIELD(CCSPlayerAnimationState_Direction_t, m_groundActionDirection                         , 0x1A)
        SCHEMA_FIELD(CCSPlayerAnimationState_AirAction_t, m_airAction                                     , 0x1B)
        SCHEMA_FIELD(bool                            , m_bWasOnGroundLastUpdate                        , 0x1C)
        SCHEMA_FIELD(bool                            , m_bWasStationaryLastUpdate                      , 0x1D)
        SCHEMA_FIELD(::GameTick_t                    , m_actionStartTick                               , 0x20)
        SCHEMA_FIELD(::GameTick_t                    , m_staticAimTimerStartTick                       , 0x24)
        SCHEMA_FIELD(::GameTick_t                    , m_plantAndTurnStartTick                         , 0x28)
        SCHEMA_FIELD(float                           , m_flTurnOnSpotAngle                             , 0x2C)
        SCHEMA_FIELD(float                           , m_flPreviousAimYaw                              , 0x30)
        SCHEMA_FIELD(float                           , m_flPreviousHorizontalSpeed                     , 0x34)
        SCHEMA_FIELD(float                           , m_flFootIKOffsetLeft                            , 0x38)
        SCHEMA_FIELD(float                           , m_flFootIKOffsetRight                           , 0x3C)
        SCHEMA_FIELD(float                           , m_flWeaponDropPercentageDueToMovement           , 0x40)
        SCHEMA_FIELD(float                           , m_flWeaponDropSmoothDampVelocity                , 0x44)
    };

    class CIronSightController {
    public:
        SCHEMA_FIELD(bool                            , m_bIronSightAvailable                           , 0x8)
        SCHEMA_FIELD(float                           , m_flIronSightAmount                             , 0xC)
        SCHEMA_FIELD(float                           , m_flIronSightAmountGained                       , 0x10)
        SCHEMA_FIELD(float                           , m_flIronSightAmountBiased                       , 0x14)
    };

    class EngineCountdownTimer {
    public:
        SCHEMA_FIELD(float                           , m_duration                                      , 0x8)
        SCHEMA_FIELD(float                           , m_timestamp                                     , 0xC)
        SCHEMA_FIELD(float                           , m_timescale                                     , 0x10)
    };

    class GAME_HEADER {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sComment                                      , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nSpawnGroupCount                              , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_sLandmark                                     , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_sRequiredAddons                               , 0x18)
    };

    class SceneOpportunityActor_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseModelEntity>       , m_hActor                                        , 0x0)
        SCHEMA_FIELD(bool                            , m_bDynamicActor                                 , 0x4)
        SCHEMA_FIELD(bool                            , m_bAnchor                                       , 0x5)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strActorName                                  , 0x8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strEntityName                                 , 0x10)
        SCHEMA_FIELD(SceneInterestTags_t             , m_InterestTags                                  , 0x18)
    };

    class CNetworkOriginQuantizedVector {
    public:
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecX                                          , 0x10)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecY                                          , 0x18)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_vecZ                                          , 0x20)
    };

    class CBasePulseGraphInstance {
    public:
    };

    class CPulseCell_CursorQueue {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToRunParallel                  , 0x98)
    };

    class WeaponPurchaseCount_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nItemDefIndex                                 , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , m_nCount                                        , 0x32)
    };

    class DynamicVolumeDef_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_source                                        , 0x0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_target                                        , 0x4)
        SCHEMA_FIELD(std::int32_t                    , m_nHullIdx                                      , 0x8)
        SCHEMA_FIELD(::Vector                        , m_vSourceAnchorPos                              , 0xC)
        SCHEMA_FIELD(::Vector                        , m_vTargetAnchorPos                              , 0x18)
        SCHEMA_FIELD(std::uint32_t                   , m_nAreaSrc                                      , 0x24)
        SCHEMA_FIELD(std::uint32_t                   , m_nAreaDst                                      , 0x28)
        SCHEMA_FIELD(bool                            , m_bAttached                                     , 0x2C)
    };

    class CTestPulseIOComponent_Derived {
    public:
    };

    class CPulseCell_Outflow_PlayVOLine {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x48)
    };

    class CPulseCell_Step_PublicOutput {
    public:
        SCHEMA_FIELD(PulseRuntimeOutputIndex_t       , m_OutputIndex                                   , 0x48)
    };

    class CPulseCell_Unknown {
    public:
        SCHEMA_FIELD(KeyValues3                      , m_UnknownKeys                                   , 0x48)
    };

    class CDecalGroupVData {
    public:
        SCHEMA_FIELD(CUtlVector<DecalGroupOption_t>  , m_vecOptions                                    , 0x0)
        SCHEMA_FIELD(float                           , m_flTotalProbability                            , 0x18)
    };

    class IntervalTimer {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_timestamp                                     , 0x8)
        SCHEMA_FIELD(::WorldGroupId_t                , m_nWorldGroupId                                 , 0xC)
    };

    class CPulseCell_Outflow_ListenForEntityOutput_CursorState_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_entity                                        , 0x0)
    };

    class SequenceHistory_t {
    public:
        SCHEMA_FIELD(HSequence                       , m_hSequence                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_flSeqStartTime                                , 0x4)
        SCHEMA_FIELD(float                           , m_flSeqFixedCycle                               , 0x8)
        SCHEMA_FIELD(AnimLoopMode_t                  , m_nSeqLoopMode                                  , 0xC)
        SCHEMA_FIELD(float                           , m_flPlaybackRate                                , 0x10)
        SCHEMA_FIELD(float                           , m_flCyclesPerSecond                             , 0x14)
    };

    class NavGravity_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vGravity                                      , 0x0)
        SCHEMA_FIELD(bool                            , m_bDefault                                      , 0xC)
    };

    class CTestPulseIOComponent_DerivedAPI {
    public:
    };

    class CPulseCell_FireCursors {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outflows                                      , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class CNavVolumeMarkupVolume {
    public:
    };

    class CPulse_BlackboardReference {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIPulseGraphDef>, m_hBlackboardResource                           , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_BlackboardResource                            , 0x8)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nNodeID                                       , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , m_NodeName                                      , 0x20)
    };

    class FuncMoverMovementSummary_t {
    public:
        SCHEMA_FIELD(float                           , flStartT                                        , 0x0)
        SCHEMA_FIELD(float                           , flEndT                                          , 0x4)
        SCHEMA_FIELD(std::int32_t                    , nStartNodeIndex                                 , 0x8)
        SCHEMA_FIELD(std::int32_t                    , nStopNodeIndex                                  , 0xC)
        SCHEMA_FIELD(std::int32_t                    , nMovementMode                                   , 0x10)
        SCHEMA_FIELD(FuncMoverMovementSummaryFlags_t , nFlags                                          , 0x14)
        SCHEMA_FIELD(::GameTick_t                    , nTick                                           , 0x18)
        SCHEMA_FIELD(CHandle<CPathMover>             , hPathMover                                      , 0x1C)
    };

    class CPulseCell_BaseFlow {
    public:
    };

    class CPulseCell_SoundEventStart {
    public:
        SCHEMA_FIELD(SoundEventStartType_t           , m_Type                                          , 0x48)
    };

    class CTestPulseIOComponent_API {
    public:
    };

    class CSoundEnvelope {
    public:
        SCHEMA_FIELD(float                           , m_current                                       , 0x0)
        SCHEMA_FIELD(float                           , m_target                                        , 0x4)
        SCHEMA_FIELD(float                           , m_rate                                          , 0x8)
        SCHEMA_FIELD(bool                            , m_forceupdate                                   , 0xC)
    };

    class CGlowProperty {
    public:
        SCHEMA_FIELD(::Vector                        , m_fGlowColor                                    , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_iGlowType                                     , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_iGlowTeam                                     , 0x34)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRange                                    , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRangeMin                                 , 0x3C)
        SCHEMA_FIELD(::Color                         , m_glowColorOverride                             , 0x40)
        SCHEMA_FIELD(bool                            , m_bFlashing                                     , 0x44)
        SCHEMA_FIELD(float                           , m_flGlowTime                                    , 0x48)
        SCHEMA_FIELD(float                           , m_flGlowStartTime                               , 0x4C)
        SCHEMA_FIELD(bool                            , m_bEligibleForScreenHighlight                   , 0x50)
        SCHEMA_FIELD(bool                            , m_bGlowing                                      , 0x51)
    };

    class CBaseEntity {
    public:
        SCHEMA_FIELD(CBodyComponent*                 , m_CBodyComponent                                , 0x30)
        SCHEMA_FIELD(CNetworkTransmitComponent       , m_NetworkTransmitComponent                      , 0x38)
        SCHEMA_FIELD(CUtlVector<thinkfunc_t>         , m_aThinkFunctions                               , 0x248)
        SCHEMA_FIELD(std::int32_t                    , m_iCurrentThinkContext                          , 0x260)
        SCHEMA_FIELD(::GameTick_t                    , m_nLastThinkTick                                , 0x264)
        SCHEMA_FIELD(bool                            , m_bDisabledContextThinks                        , 0x268)
        SCHEMA_FIELD(CTypedBitVec<64>                , m_isSteadyState                                 , 0x278)
        SCHEMA_FIELD(float                           , m_lastNetworkChange                             , 0x280)
        SCHEMA_FIELD(BASEPTR                         , m_think                                         , 0x288)
        SCHEMA_FIELD(CUtlVector<ResponseContext_t>   , m_ResponseContexts                              , 0x290)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszResponseContext                            , 0x2A8)
        SCHEMA_FIELD(ENTITYFUNCPTR                   , m_pfnTouch                                      , 0x2B0)
        SCHEMA_FIELD(USEPTR                          , m_pfnUse                                        , 0x2B8)
        SCHEMA_FIELD(ENTITYFUNCPTR                   , m_pfnBlocked                                    , 0x2C0)
        SCHEMA_FIELD(BASEPTR                         , m_pfnMoveDone                                   , 0x2C8)
        SCHEMA_FIELD(std::int32_t                    , m_iHealth                                       , 0x2D0)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxHealth                                    , 0x2D4)
        SCHEMA_FIELD(std::uint8_t                    , m_lifeState                                     , 0x2D8)
        SCHEMA_FIELD(float                           , m_flDamageAccumulator                           , 0x2DC)
        SCHEMA_FIELD(bool                            , m_bTakesDamage                                  , 0x2E0)
        SCHEMA_FIELD(TakeDamageFlags_t               , m_nTakeDamageFlags                              , 0x2E8)
        SCHEMA_FIELD(EntityPlatformTypes_t           , m_nPlatformType                                 , 0x2F0)
        SCHEMA_FIELD(MoveCollide_t                   , m_MoveCollide                                   , 0x2F2)
        SCHEMA_FIELD(MoveType_t                      , m_MoveType                                      , 0x2F3)
        SCHEMA_FIELD(MoveType_t                      , m_nPreviouslySetMoveType                        , 0x2F4)
        SCHEMA_FIELD(MoveType_t                      , m_nActualMoveType                               , 0x2F5)
        SCHEMA_FIELD(std::uint8_t                    , m_nWaterTouch                                   , 0x2F6)
        SCHEMA_FIELD(std::uint8_t                    , m_nSlimeTouch                                   , 0x2F7)
        SCHEMA_FIELD(bool                            , m_bRestoreInHierarchy                           , 0x2F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_target                                        , 0x300)
        SCHEMA_FIELD(CHandle<CBaseFilter>            , m_hDamageFilter                                 , 0x308)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszDamageFilterName                           , 0x310)
        SCHEMA_FIELD(float                           , m_flMoveDoneTime                                , 0x318)
        SCHEMA_FIELD(CUtlStringToken                 , m_nSubclassID                                   , 0x31C)
        SCHEMA_FIELD(float                           , m_flAnimTime                                    , 0x328)
        SCHEMA_FIELD(float                           , m_flSimulationTime                              , 0x32C)
        SCHEMA_FIELD(::GameTime_t                    , m_flCreateTime                                  , 0x330)
        SCHEMA_FIELD(bool                            , m_bClientSideRagdoll                            , 0x334)
        SCHEMA_FIELD(std::uint8_t                    , m_ubInterpolationFrame                          , 0x335)
        SCHEMA_FIELD(VectorWS                        , m_vPrevVPhysicsUpdatePos                        , 0x338)
        SCHEMA_FIELD(std::uint8_t                    , m_iTeamNum                                      , 0x344)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iGlobalname                                   , 0x348)
        SCHEMA_FIELD(std::int32_t                    , m_iSentToClients                                , 0x350)
        SCHEMA_FIELD(float                           , m_flSpeed                                       , 0x354)
        SCHEMA_FIELD(::CUtlString                    , m_sUniqueHammerID                               , 0x358)
        SCHEMA_FIELD(std::uint32_t                   , m_spawnflags                                    , 0x360)
        SCHEMA_FIELD(::GameTick_t                    , m_nNextThinkTick                                , 0x364)
        SCHEMA_FIELD(std::int32_t                    , m_nSimulationTick                               , 0x368)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnKilled                                      , 0x370)
        SCHEMA_FIELD(std::uint32_t                   , m_fFlags                                        , 0x388)
        SCHEMA_FIELD(::Vector                        , m_vecAbsVelocity                                , 0x38C)
        SCHEMA_FIELD(CNetworkVelocityVector          , m_vecVelocity                                   , 0x398)
        SCHEMA_FIELD(::Vector                        , m_vecBaseVelocity                               , 0x3C8)
        SCHEMA_FIELD(std::int32_t                    , m_nPushEnumCount                                , 0x3D4)
        SCHEMA_FIELD(CCollisionProperty*             , m_pCollision                                    , 0x3D8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEffectEntity                                 , 0x3E0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOwnerEntity                                  , 0x3E4)
        SCHEMA_FIELD(std::uint32_t                   , m_fEffects                                      , 0x3E8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hGroundEntity                                 , 0x3EC)
        SCHEMA_FIELD(std::int32_t                    , m_nGroundBodyIndex                              , 0x3F0)
        SCHEMA_FIELD(float                           , m_flFriction                                    , 0x3F4)
        SCHEMA_FIELD(float                           , m_flElasticity                                  , 0x3F8)
        SCHEMA_FIELD(float                           , m_flGravityScale                                , 0x3FC)
        SCHEMA_FIELD(float                           , m_flTimeScale                                   , 0x400)
        SCHEMA_FIELD(float                           , m_flWaterLevel                                  , 0x404)
        SCHEMA_FIELD(bool                            , m_bGravityDisabled                              , 0x408)
        SCHEMA_FIELD(bool                            , m_bAnimatedEveryTick                            , 0x409)
        SCHEMA_FIELD(float                           , m_flActualGravityScale                          , 0x40C)
        SCHEMA_FIELD(bool                            , m_bGravityActuallyDisabled                      , 0x410)
        SCHEMA_FIELD(bool                            , m_bDisableLowViolence                           , 0x411)
        SCHEMA_FIELD(std::uint8_t                    , m_nWaterType                                    , 0x412)
        SCHEMA_FIELD(std::int32_t                    , m_iEFlags                                       , 0x414)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUser1                                       , 0x418)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUser2                                       , 0x430)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUser3                                       , 0x448)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUser4                                       , 0x460)
        SCHEMA_FIELD(std::int32_t                    , m_iInitialTeamNum                               , 0x478)
        SCHEMA_FIELD(::GameTime_t                    , m_flNavIgnoreUntilTime                          , 0x47C)
        SCHEMA_FIELD(::QAngle                        , m_vecAngVelocity                                , 0x480)
        SCHEMA_FIELD(bool                            , m_bNetworkQuantizeOriginAndAngles               , 0x48C)
        SCHEMA_FIELD(bool                            , m_bLagCompensate                                , 0x48D)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_pBlocker                                      , 0x490)
        SCHEMA_FIELD(float                           , m_flLocalTime                                   , 0x494)
        SCHEMA_FIELD(float                           , m_flVPhysicsUpdateLocalTime                     , 0x498)
        SCHEMA_FIELD(BloodType                       , m_nBloodType                                    , 0x49C)
        SCHEMA_FIELD(CPulseGraphInstance_ServerEntity*, m_pPulseGraphInstance                           , 0x4A0)
    };

    class CMotorController {
    public:
        SCHEMA_FIELD(float                           , m_speed                                         , 0x8)
        SCHEMA_FIELD(float                           , m_maxTorque                                     , 0xC)
        SCHEMA_FIELD(VectorWS                        , m_axis                                          , 0x10)
        SCHEMA_FIELD(float                           , m_inertiaFactor                                 , 0x1C)
    };

    class CMovementStatsProperty {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nUseCounter                                   , 0x10)
        SCHEMA_FIELD(CVectorExponentialMovingAverage , m_emaMovementDirection                          , 0x14)
    };

    class SimpleConstraintSoundProfile {
    public:
        SCHEMA_FIELD(float                           , m_flKeyPointMinSoundThreshold                   , 0x8)
        SCHEMA_FIELD(float                           , m_flKeyPointMaxSoundThreshold                   , 0xC)
        SCHEMA_FIELD(float                           , m_reversalSoundThresholdSmall                   , 0x10)
        SCHEMA_FIELD(float                           , m_reversalSoundThresholdMedium                  , 0x14)
        SCHEMA_FIELD(float                           , m_reversalSoundThresholdLarge                   , 0x18)
    };

    class CEconItemView {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_iItemDefinitionIndex                          , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_iEntityQuality                                , 0x3C)
        SCHEMA_FIELD(std::uint32_t                   , m_iEntityLevel                                  , 0x40)
        SCHEMA_FIELD(std::uint64_t                   , m_iItemID                                       , 0x48)
        SCHEMA_FIELD(std::uint32_t                   , m_iItemIDHigh                                   , 0x50)
        SCHEMA_FIELD(std::uint32_t                   , m_iItemIDLow                                    , 0x54)
        SCHEMA_FIELD(std::uint32_t                   , m_iAccountID                                    , 0x58)
        SCHEMA_FIELD(std::uint32_t                   , m_iInventoryPosition                            , 0x5C)
        SCHEMA_FIELD(bool                            , m_bInitialized                                  , 0x68)
        SCHEMA_FIELD(CAttributeList                  , m_AttributeList                                 , 0x70)
        SCHEMA_FIELD(CAttributeList                  , m_NetworkedDynamicAttributes                    , 0xE8)
        SCHEMA_FIELD(char                            , m_szCustomName                                  , 0x160)
        SCHEMA_FIELD(char                            , m_szCustomNameOverride                          , 0x201)
    };

    class CPulseCell_BaseRequirement {
    public:
    };

    class CPulseCell_Outflow_PlaySceneBase {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0x90)
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Triggers                                      , 0xD8)
    };

    class CScenePayloadVData {
    public:
        SCHEMA_FIELD(ENPCBehaviorOverride_t          , m_eNPCBehavior                                  , 0x0)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIPulseGraphDef>>, m_sPulseFile                                    , 0x8)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCChoreoSceneResource>>, m_sSceneFile                                    , 0xE8)
        SCHEMA_FIELD(InteractionPriority_t           , m_ePriority                                     , 0x1C8)
    };

    class CRR_Response {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_Type                                          , 0x0)
        SCHEMA_FIELD(char                            , m_szResponseName                                , 0x1)
        SCHEMA_FIELD(char                            , m_szMatchingRule                                , 0xC1)
        SCHEMA_FIELD(ResponseParams                  , m_Params                                        , 0x160)
        SCHEMA_FIELD(float                           , m_fMatchScore                                   , 0x180)
        SCHEMA_FIELD(bool                            , m_bAnyMatchingRulesInCooldown                   , 0x184)
        SCHEMA_FIELD(char*                           , m_szSpeakerContext                              , 0x188)
        SCHEMA_FIELD(char*                           , m_szWorldContext                                , 0x190)
        SCHEMA_FIELD(ResponseFollowup                , m_Followup                                      , 0x198)
        SCHEMA_FIELD(CUtlSymbol                      , m_recipientFilter                               , 0x1CA)
    };

    class WaterWheelFrictionScale_t {
    public:
        SCHEMA_FIELD(float                           , m_flFractionOfWheelSubmerged                    , 0x0)
        SCHEMA_FIELD(float                           , m_flFrictionScale                               , 0x4)
    };

    class OutflowWithRequirements_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x0)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_DestinationFlowNodeID                         , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseDocNodeID_t>    , m_RequirementNodeIDs                            , 0x50)
        SCHEMA_FIELD(CUtlVector<int32>               , m_nCursorStateBlockIndex                        , 0x68)
    };

    class CPathQueryUtil {
    public:
        SCHEMA_FIELD(CTransform                      , m_PathToEntityTransform                         , 0x10)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_vecPathSamplePositions                        , 0x30)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecPathSampleParameters                       , 0x48)
        SCHEMA_FIELD(CUtlVector<float32>             , m_vecPathSampleDistances                        , 0x60)
        SCHEMA_FIELD(bool                            , m_bIsClosedLoop                                 , 0x78)
    };

    class CPulseCell_PickBestOutflowSelector {
    public:
        SCHEMA_FIELD(PulseBestOutflowRules_t         , m_nCheckType                                    , 0x48)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_OutflowList                                   , 0x50)
    };

    class CDecalInstance {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_sDecalGroup                                   , 0x0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0x8)
        SCHEMA_FIELD(CUtlStringToken                 , m_sSequenceName                                 , 0x10)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x14)
        SCHEMA_FIELD(std::int32_t                    , m_nBoneIndex                                    , 0x18)
        SCHEMA_FIELD(std::int32_t                    , m_nTriangleIndex                                , 0x1C)
        SCHEMA_FIELD(::Vector                        , m_vPositionLS                                   , 0x20)
        SCHEMA_FIELD(::Vector                        , m_vPositionOS                                   , 0x2C)
        SCHEMA_FIELD(::Vector                        , m_vNormalLS                                     , 0x38)
        SCHEMA_FIELD(::Vector                        , m_vSAxisLS                                      , 0x44)
        SCHEMA_FIELD(DecalFlags_t                    , m_nFlags                                        , 0x50)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0x54)
        SCHEMA_FIELD(float                           , m_flWidth                                       , 0x58)
        SCHEMA_FIELD(float                           , m_flHeight                                      , 0x5C)
        SCHEMA_FIELD(float                           , m_flDepth                                       , 0x60)
        SCHEMA_FIELD(CTransformWS                    , m_transform                                     , 0x70)
        SCHEMA_FIELD(float                           , m_flAnimationScale                              , 0x90)
        SCHEMA_FIELD(float                           , m_flAnimationStartTime                          , 0x94)
        SCHEMA_FIELD(::GameTime_t                    , m_flPlaceTime                                   , 0x98)
        SCHEMA_FIELD(float                           , m_flFadeStartTime                               , 0x9C)
        SCHEMA_FIELD(float                           , m_flFadeDuration                                , 0xA0)
        SCHEMA_FIELD(float                           , m_flLightingOriginOffset                        , 0xA4)
        SCHEMA_FIELD(float                           , m_flBoundingRadiusSqr                           , 0xB0)
        SCHEMA_FIELD(std::int16_t                    , m_nSequenceIndex                                , 0xB4)
        SCHEMA_FIELD(bool                            , m_bIsAdjacent                                   , 0xB6)
        SCHEMA_FIELD(bool                            , m_bDoDecalLightmapping                          , 0xB7)
    };

    class dynpitchvol_base_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , preset                                          , 0x0)
        SCHEMA_FIELD(std::int32_t                    , pitchrun                                        , 0x4)
        SCHEMA_FIELD(std::int32_t                    , pitchstart                                      , 0x8)
        SCHEMA_FIELD(std::int32_t                    , spinup                                          , 0xC)
        SCHEMA_FIELD(std::int32_t                    , spindown                                        , 0x10)
        SCHEMA_FIELD(std::int32_t                    , volrun                                          , 0x14)
        SCHEMA_FIELD(std::int32_t                    , volstart                                        , 0x18)
        SCHEMA_FIELD(std::int32_t                    , fadein                                          , 0x1C)
        SCHEMA_FIELD(std::int32_t                    , fadeout                                         , 0x20)
        SCHEMA_FIELD(std::int32_t                    , lfotype                                         , 0x24)
        SCHEMA_FIELD(std::int32_t                    , lforate                                         , 0x28)
        SCHEMA_FIELD(std::int32_t                    , lfomodpitch                                     , 0x2C)
        SCHEMA_FIELD(std::int32_t                    , lfomodvol                                       , 0x30)
        SCHEMA_FIELD(std::int32_t                    , cspinup                                         , 0x34)
        SCHEMA_FIELD(std::int32_t                    , cspincount                                      , 0x38)
        SCHEMA_FIELD(std::int32_t                    , pitch                                           , 0x3C)
        SCHEMA_FIELD(std::int32_t                    , spinupsav                                       , 0x40)
        SCHEMA_FIELD(std::int32_t                    , spindownsav                                     , 0x44)
        SCHEMA_FIELD(std::int32_t                    , pitchfrac                                       , 0x48)
        SCHEMA_FIELD(std::int32_t                    , vol                                             , 0x4C)
        SCHEMA_FIELD(std::int32_t                    , fadeinsav                                       , 0x50)
        SCHEMA_FIELD(std::int32_t                    , fadeoutsav                                      , 0x54)
        SCHEMA_FIELD(std::int32_t                    , volfrac                                         , 0x58)
        SCHEMA_FIELD(std::int32_t                    , lfofrac                                         , 0x5C)
        SCHEMA_FIELD(std::int32_t                    , lfomult                                         , 0x60)
    };

    class CDestructiblePartsComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x0)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_vecDamageTakenByHitGroup                      , 0x48)
        SCHEMA_FIELD(CHandle<CBaseModelEntity>       , m_hOwner                                        , 0x60)
        SCHEMA_FIELD(CBaseAnimGraphDestructibleParts_GraphController*, m_pAnimGraphDestructibleGraphController         , 0x68)
    };

    class CDestructiblePartsSystemData {
    public:
        using _Type0 = CUtlOrderedMap<HitGroup_t,CDestructiblePart>;
        SCHEMA_FIELD(_Type0                          , m_PartsDataByHitGroup                           , 0x0)
        SCHEMA_FIELD(CRangeInt                       , m_nMinMaxNumberHitGroupsToDestroyWhenGibbing    , 0x28)
    };

    class CEffectData {
    public:
        SCHEMA_FIELD(VectorWS                        , m_vOrigin                                       , 0x8)
        SCHEMA_FIELD(VectorWS                        , m_vStart                                        , 0x14)
        SCHEMA_FIELD(::Vector                        , m_vNormal                                       , 0x20)
        SCHEMA_FIELD(::QAngle                        , m_vAngles                                       , 0x2C)
        SCHEMA_FIELD(CEntityHandle                   , m_hEntity                                       , 0x38)
        SCHEMA_FIELD(CEntityHandle                   , m_hOtherEntity                                  , 0x3C)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x40)
        SCHEMA_FIELD(float                           , m_flMagnitude                                   , 0x44)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x48)
        SCHEMA_FIELD(CUtlStringToken                 , m_nSurfaceProp                                  , 0x4C)
        SCHEMA_FIELD(CWeakHandle<InfoForResourceTypeIParticleSystemDefinition>, m_nEffectIndex                                  , 0x50)
        SCHEMA_FIELD(std::uint32_t                   , m_nDamageType                                   , 0x58)
        SCHEMA_FIELD(std::uint8_t                    , m_nPenetrate                                    , 0x5C)
        SCHEMA_FIELD(std::uint16_t                   , m_nMaterial                                     , 0x5E)
        SCHEMA_FIELD(std::int16_t                    , m_nHitBox                                       , 0x60)
        SCHEMA_FIELD(std::uint8_t                    , m_nColor                                        , 0x62)
        SCHEMA_FIELD(std::uint8_t                    , m_fFlags                                        , 0x63)
        SCHEMA_FIELD(AttachmentHandle_t              , m_nAttachmentIndex                              , 0x64)
        SCHEMA_FIELD(CUtlStringToken                 , m_nAttachmentName                               , 0x68)
        SCHEMA_FIELD(std::uint16_t                   , m_iEffectName                                   , 0x6C)
    };

    class CNmEventConsumer {
    public:
    };

    class CVectorMovingAverage {
    public:
    };

    class VelocitySampler {
    public:
        SCHEMA_FIELD(::Vector                        , m_prevSample                                    , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_fPrevSampleTime                               , 0xC)
        SCHEMA_FIELD(float                           , m_fIdealSampleRate                              , 0x10)
    };

    class CPulseFuncs_GameParticleManager {
    public:
    };

    class CPointTemplateAPI {
    public:
    };

    class AI_Motor_DebugSnapshotData_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , current_movement_gait_set                       , 0x8)
        SCHEMA_FIELD(CGlobalSymbol                   , current_movement_gait                           , 0x10)
        SCHEMA_FIELD(CGlobalSymbol                   , movement_setting_id                             , 0x18)
    };

    class CEnvWindShared {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x8)
        SCHEMA_FIELD(std::uint32_t                   , m_iWindSeed                                     , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , m_iMinWind                                      , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , m_iMaxWind                                      , 0x12)
        SCHEMA_FIELD(std::int32_t                    , m_windRadius                                    , 0x14)
        SCHEMA_FIELD(std::uint16_t                   , m_iMinGust                                      , 0x18)
        SCHEMA_FIELD(std::uint16_t                   , m_iMaxGust                                      , 0x1A)
        SCHEMA_FIELD(float                           , m_flMinGustDelay                                , 0x1C)
        SCHEMA_FIELD(float                           , m_flMaxGustDelay                                , 0x20)
        SCHEMA_FIELD(float                           , m_flGustDuration                                , 0x24)
        SCHEMA_FIELD(std::uint16_t                   , m_iGustDirChange                                , 0x28)
        SCHEMA_FIELD(std::uint16_t                   , m_iInitialWindDir                               , 0x2A)
        SCHEMA_FIELD(float                           , m_flInitialWindSpeed                            , 0x2C)
        SCHEMA_FIELD(VectorWS                        , m_location                                      , 0x30)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnGustStart                                   , 0x40)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnGustEnd                                     , 0x58)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntOwner                                     , 0x70)
    };

    class CPulseAnimFuncs {
    public:
    };

    class CModelState {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCModel>, m_hModel                                        , 0xA0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_ModelName                                     , 0xA8)
        SCHEMA_FIELD(IPhysAggregateInstance*         , m_pVPhysicsAggregate                            , 0xE0)
        SCHEMA_FIELD(float                           , m_flRootBoneOffset_x                            , 0xE8)
        SCHEMA_FIELD(float                           , m_flRootBoneOffset_y                            , 0xEC)
        SCHEMA_FIELD(float                           , m_flRootBoneOffset_z                            , 0xF0)
        SCHEMA_FIELD(std::uint8_t                    , m_nRootBoneOffsetResetSerialNumber              , 0xF4)
        SCHEMA_FIELD(bool                            , m_bClientClothCreationSuppressed                , 0xF5)
        SCHEMA_FIELD(std::uint8_t                    , m_nAnimStateNoInterpSerialNumber                , 0x1A0)
        SCHEMA_FIELD(std::uint64_t                   , m_MeshGroupMask                                 , 0x1A8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<int32>    , m_nBodyGroupChoices                             , 0x1F8)
        SCHEMA_FIELD(std::int8_t                     , m_nIdealMotionType                              , 0x242)
        SCHEMA_FIELD(std::int8_t                     , m_nForceLOD                                     , 0x243)
        SCHEMA_FIELD(std::int8_t                     , m_nClothUpdateFlags                             , 0x244)
    };

    class levellist_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sMapName                                      , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_sLandmarkName                                 , 0x8)
        SCHEMA_FIELD(CEntityHandle                   , m_hEntLandmark                                  , 0x10)
        SCHEMA_FIELD(::Vector                        , m_vecLandmarkOrigin                             , 0x14)
        SCHEMA_FIELD(::QAngle                        , m_vecLandmarkAngles                             , 0x20)
    };

    class SceneInterestTags_t {
    public:
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_Tags                                          , 0x0)
    };

    class CPulseCell_WaitForCursorsWithTag {
    public:
        SCHEMA_FIELD(bool                            , m_bTagSelfWhenComplete                          , 0x98)
        SCHEMA_FIELD(PulseCursorCancelPriority_t     , m_nDesiredKillPriority                          , 0x9C)
    };

    class CBot {
    public:
        SCHEMA_FIELD(CCSPlayerController*            , m_pController                                   , 0x10)
        SCHEMA_FIELD(CCSPlayerPawn*                  , m_pPlayer                                       , 0x18)
        SCHEMA_FIELD(bool                            , m_bHasSpawned                                   , 0x20)
        SCHEMA_FIELD(std::uint32_t                   , m_id                                            , 0x24)
        SCHEMA_FIELD(bool                            , m_isRunning                                     , 0xC0)
        SCHEMA_FIELD(bool                            , m_isCrouching                                   , 0xC1)
        SCHEMA_FIELD(float                           , m_forwardSpeed                                  , 0xC4)
        SCHEMA_FIELD(float                           , m_leftSpeed                                     , 0xC8)
        SCHEMA_FIELD(float                           , m_verticalSpeed                                 , 0xCC)
        SCHEMA_FIELD(std::uint64_t                   , m_buttonFlags                                   , 0xD0)
        SCHEMA_FIELD(float                           , m_jumpTimestamp                                 , 0xD8)
        SCHEMA_FIELD(::Vector                        , m_viewForward                                   , 0xDC)
        SCHEMA_FIELD(std::int32_t                    , m_postureStackIndex                             , 0xF8)
    };

    class WeaponPurchaseTracker_t {
    public:
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<WeaponPurchaseCount_t>, m_weaponPurchases                               , 0x8)
    };

    class modifiedconvars_t {
    public:
        SCHEMA_FIELD(char                            , pszConvar                                       , 0x0)
        SCHEMA_FIELD(char                            , pszCurrentValue                                 , 0x80)
        SCHEMA_FIELD(char                            , pszOrgValue                                     , 0x100)
    };

    class SceneRequestHandle_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Value                                         , 0x0)
    };

    class WaterWheelDrag_t {
    public:
        SCHEMA_FIELD(float                           , m_flFractionOfWheelSubmerged                    , 0x0)
        SCHEMA_FIELD(float                           , m_flWheelDrag                                   , 0x4)
    };

    class CSkeletonAnimationController {
    public:
        SCHEMA_FIELD(CSkeletonInstance*              , m_pSkeletonInstance                             , 0x8)
    };

    class CEmptyGraphController {
    public:
    };

    class CTestPulseIO_ThreeStringArgs_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , strArg1                                         , 0x0)
        SCHEMA_FIELD(::CUtlString                    , strArg2                                         , 0x8)
        SCHEMA_FIELD(::CUtlString                    , strArg3                                         , 0x10)
    };

    class CPulseCell_IntervalTimer_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
        SCHEMA_FIELD(float                           , m_flWaitInterval                                , 0x8)
        SCHEMA_FIELD(float                           , m_flWaitIntervalHigh                            , 0xC)
        SCHEMA_FIELD(bool                            , m_bCompleteOnNextWake                           , 0x10)
    };

    class CSkillDamage {
    public:
        SCHEMA_FIELD(CSkillFloat                     , m_flDamage                                      , 0x0)
        SCHEMA_FIELD(float                           , m_flNPCDamageScalarVsNPC                        , 0x10)
        SCHEMA_FIELD(float                           , m_flPhysicsForceDamage                          , 0x14)
    };

    class CTestPulseIOComponent {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_ComponentData                                 , 0x8)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlSymbolLarge>, m_OnComponentTestFunc                           , 0x10)
    };

    class NavHull_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nHullIdx                                      , 0x0)
    };

    class CCopyRecipientFilter {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Flags                                         , 0x8)
        SCHEMA_FIELD(CUtlVector<CPlayerSlot>         , m_Recipients                                    , 0x10)
        SCHEMA_FIELD(CPlayerSlot                     , m_slotPlayerExcludedDueToPrediction             , 0x30)
    };

    class GameAmmoTypeInfo_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nBuySize                                      , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nCost                                         , 0x3C)
    };

    class CPulseCell_Inflow_ObservableVariableListener {
    public:
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardReference                          , 0x80)
        SCHEMA_FIELD(bool                            , m_bSelfReference                                , 0x82)
    };

    class CAttributeManager_cached_attribute_float_t {
    public:
        SCHEMA_FIELD(float                           , flIn                                            , 0x0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , iAttribHook                                     , 0x8)
        SCHEMA_FIELD(float                           , flOut                                           , 0x10)
    };

    class CPointPrefabAPI {
    public:
    };

    class ViewAngleServerChange_t {
    public:
        SCHEMA_FIELD(FixAngleSet_t                   , nType                                           , 0x30)
        SCHEMA_FIELD(::QAngle                        , qAngle                                          , 0x34)
        SCHEMA_FIELD(std::uint32_t                   , nIndex                                          , 0x40)
    };

    class AI_Navigator_DebugSnapshotData_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , s_npc_nav_authority                             , 0x8)
        SCHEMA_FIELD(CGlobalSymbol                   , s_goal_nav_search_id                            , 0x10)
        SCHEMA_FIELD(::CUtlString                    , s_goal_source_location                          , 0x18)
        SCHEMA_FIELD(VectorWS                        , goal_actual_pos                                 , 0x20)
        SCHEMA_FIELD(VectorWS                        , goal_base_pos                                   , 0x2C)
        SCHEMA_FIELD(CUtlVector<AI_Navigator_DebugSnapshotData_t_Waypoint_t>, waypoints                                       , 0x38)
    };

    class CNavHullPresetVData {
    public:
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_vecNavHulls                                   , 0x0)
    };

    class CPulseCell_Outflow_PlayVCD_VCDRequirementInfo_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nEventID                                      , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Outflow                                       , 0x8)
    };

    class CDestructiblePart {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_DebugName                                     , 0x0)
        SCHEMA_FIELD(HitGroup_t                      , m_nHitGroup                                     , 0x8)
        SCHEMA_FIELD(bool                            , m_bDisableHitGroupWhenDestroyed                 , 0xC)
        SCHEMA_FIELD(CUtlVector<HitGroup_t>          , m_nOtherHitgroupsToDestroyWhenFullyDestructed   , 0x10)
        SCHEMA_FIELD(bool                            , m_bOnlyDestroyWhenGibbing                       , 0x28)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sBodyGroupName                                , 0x30)
        SCHEMA_FIELD(CUtlVector<CDestructiblePart_DamageLevel>, m_DamageLevels                                  , 0x38)
    };

    class CNavVolumeVector {
    public:
        SCHEMA_FIELD(bool                            , m_bHasBeenPreFiltered                           , 0x80)
    };

    class DestructiblePartDamageRequestAPI {
    public:
    };

    class CPulseCell_Outflow_ListenForAnimgraphTag {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnStart                                       , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnEnd                                         , 0x90)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xD8)
        SCHEMA_FIELD(CGlobalSymbol                   , m_TagName                                       , 0x120)
    };

    class CCS2PawnGraphController {
    public:
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bIsDefusing                                   , 0x588)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_moveType                                      , 0x5A0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_moveDirectionID                               , 0x5B8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flMoveSpeedX                                  , 0x5D0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flMoveSpeedY                                  , 0x5E8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flMoveSpeedHorizontal                         , 0x600)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flPreviousMoveSpeedHorizontal                 , 0x618)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flCrouchAmount                                , 0x630)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bIsWalking                                    , 0x648)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flWeaponDropAmount                            , 0x660)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_groundAction                                  , 0x678)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_groundActionDirectionID                       , 0x690)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flGroundTurnAngleOrVelocity                   , 0x6A8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flLadderCycle                                 , 0x6C0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flLadderYaw                                   , 0x6D8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flLadderYawBackwards                          , 0x6F0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_airAction                                     , 0x708)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flAirHeightAboveGround                        , 0x720)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CNmTarget>, m_leftFootTarget                                , 0x738)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CNmTarget>, m_rightFootTarget                               , 0x750)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flFlashedAmount                               , 0x768)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flAimPitchAngle                               , 0x780)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flAimYawAngle                                 , 0x798)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_flinchHead                                    , 0x7B0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_flinchHeadRestart                             , 0x7C8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_flinchBody                                    , 0x7E0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_flinchBodyRestart                             , 0x7F8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_flinchIsOnFire                                , 0x810)
    };

    class SoundOpvarTraceResult_t {
    public:
        SCHEMA_FIELD(::Vector                        , vPos                                            , 0x0)
        SCHEMA_FIELD(bool                            , bDidHit                                         , 0xC)
        SCHEMA_FIELD(float                           , flDistSqrToCenter                               , 0x10)
    };

    class CCS2ChickenGraphController {
    public:
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_action                                        , 0x88)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_actionSubtype                                 , 0xA0)
        SCHEMA_FIELD(CAnimGraph2ParamAutoResetOptionalRef, m_bActionReset                                  , 0xB8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_idleVariation                                 , 0xD8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_runVariation                                  , 0xF0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_panicVariation                                , 0x108)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_squatVariation                                , 0x120)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bInWater                                      , 0x138)
        SCHEMA_FIELD(bool                            , m_bHasActionCompletedEvent                      , 0x150)
        SCHEMA_FIELD(bool                            , m_bWaitingForCompletedEvent                     , 0x151)
    };

    class AmmoIndex_t {
    public:
        SCHEMA_FIELD(std::int8_t                     , m_Value                                         , 0x0)
    };

    class CNmEventConsumerSound {
    public:
    };

    class CPulseCell_Outflow_ScriptedSequence {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_szSyncGroup                                   , 0x48)
        SCHEMA_FIELD(std::int32_t                    , m_nExpectedNumSequencesInSyncGroup              , 0x50)
        SCHEMA_FIELD(bool                            , m_bEnsureOnNavmeshOnFinish                      , 0x54)
        SCHEMA_FIELD(bool                            , m_bDontTeleportAtEnd                            , 0x55)
        SCHEMA_FIELD(bool                            , m_bDisallowInterrupts                           , 0x56)
        SCHEMA_FIELD(PulseScriptedSequenceData_t     , m_scriptedSequenceDataMain                      , 0x58)
        SCHEMA_FIELD(CUtlVector<PulseScriptedSequenceData_t>, m_vecAdditionalActors                           , 0x90)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0xA8)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xF0)
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Triggers                                      , 0x138)
    };

    class ragdoll_t {
    public:
        SCHEMA_FIELD(CUtlVector<ragdollelement_t>    , list                                            , 0x0)
        SCHEMA_FIELD(CUtlVector<ragdollhierarchyjoint_t>, hierarchyJoints                                 , 0x18)
        SCHEMA_FIELD(CUtlVector<int32>               , boneIndex                                       , 0x30)
        SCHEMA_FIELD(bool                            , allowStretch                                    , 0x48)
        SCHEMA_FIELD(bool                            , unused                                          , 0x49)
    };

    class entitytable_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , id                                              , 0x0)
        SCHEMA_FIELD(CEntityIndex                    , edictindex                                      , 0x4)
        SCHEMA_FIELD(CEntityIndex                    , saveentityindex                                 , 0x8)
        SCHEMA_FIELD(bool                            , bWasSaved                                       , 0x14)
        SCHEMA_FIELD(SaveRestoreTableFlags_t         , flags                                           , 0x18)
        SCHEMA_FIELD(::CUtlSymbolLarge               , classname                                       , 0x20)
        SCHEMA_FIELD(::CUtlSymbolLarge               , globalname                                      , 0x28)
        SCHEMA_FIELD(::CUtlSymbolLarge               , entityname                                      , 0x30)
        SCHEMA_FIELD(::Vector                        , landmarkModelSpace                              , 0x38)
        SCHEMA_FIELD(CEntityKeyValues*               , m_pPrecacheEntityKeys                           , 0x48)
    };

    class CBaseTriggerAPI {
    public:
    };

    class CPulseCursorFuncs {
    public:
    };

    class INavObstacle {
    public:
        SCHEMA_FIELD(std::uint64_t                   , m_nId                                           , 0x8)
    };

    class CAnimGraphControllerBase {
    public:
        SCHEMA_FIELD(ExternalAnimGraphHandle_t       , m_hExternalGraph                                , 0x10)
    };

    class PulseNodeDynamicOutflows_t_DynamicOutflow_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_OutflowID                                     , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x8)
    };

    class CPulseCell_Outflow_CycleOrdered {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class DebugDrawBoneTransforms_t {
    public:
        using _Type0 = CUtlVectorFixedGrowable<CTransform,128>;
        SCHEMA_FIELD(_Type0                          , vecBones                                        , 0x10)
    };

    class CPulse_InvokeBinding {
    public:
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_FuncName                                      , 0x30)
        SCHEMA_FIELD(PulseRuntimeCellIndex_t         , m_nCellIndex                                    , 0x40)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nSrcChunk                                     , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_nSrcInstruction                               , 0x48)
    };

    class CSMatchStats_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iEnemy5Ks                                     , 0x68)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemy4Ks                                     , 0x6C)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemy3Ks                                     , 0x70)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemyKnifeKills                              , 0x74)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemyTaserKills                              , 0x78)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemy2Ks                                     , 0x7C)
        SCHEMA_FIELD(std::int32_t                    , m_iUtility_Count                                , 0x80)
        SCHEMA_FIELD(std::int32_t                    , m_iUtility_Successes                            , 0x84)
        SCHEMA_FIELD(std::int32_t                    , m_iUtility_Enemies                              , 0x88)
        SCHEMA_FIELD(std::int32_t                    , m_iFlash_Count                                  , 0x8C)
        SCHEMA_FIELD(std::int32_t                    , m_iFlash_Successes                              , 0x90)
        SCHEMA_FIELD(float                           , m_flHealthPointsRemovedTotal                    , 0x94)
        SCHEMA_FIELD(float                           , m_flHealthPointsDealtTotal                      , 0x98)
        SCHEMA_FIELD(std::int32_t                    , m_nShotsFiredTotal                              , 0x9C)
        SCHEMA_FIELD(std::int32_t                    , m_nShotsOnTargetTotal                           , 0xA0)
        SCHEMA_FIELD(std::int32_t                    , m_i1v1Count                                     , 0xA4)
        SCHEMA_FIELD(std::int32_t                    , m_i1v1Wins                                      , 0xA8)
        SCHEMA_FIELD(std::int32_t                    , m_i1v2Count                                     , 0xAC)
        SCHEMA_FIELD(std::int32_t                    , m_i1v2Wins                                      , 0xB0)
        SCHEMA_FIELD(std::int32_t                    , m_iEntryCount                                   , 0xB4)
        SCHEMA_FIELD(std::int32_t                    , m_iEntryWins                                    , 0xB8)
    };

    class CPulseCell_Inflow_Yield {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_UnyieldResume                                 , 0x48)
    };

    class CPulseCell_PlaySequence {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_SequenceName                                  , 0x48)
        SCHEMA_FIELD(PulseNodeDynamicOutflows_t      , m_PulseAnimEvents                               , 0x50)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class fogparams_t {
    public:
        SCHEMA_FIELD(::Vector                        , dirPrimary                                      , 0x8)
        SCHEMA_FIELD(::Color                         , colorPrimary                                    , 0x14)
        SCHEMA_FIELD(::Color                         , colorSecondary                                  , 0x18)
        SCHEMA_FIELD(::Color                         , colorPrimaryLerpTo                              , 0x1C)
        SCHEMA_FIELD(::Color                         , colorSecondaryLerpTo                            , 0x20)
        SCHEMA_FIELD(float                           , start                                           , 0x24)
        SCHEMA_FIELD(float                           , end                                             , 0x28)
        SCHEMA_FIELD(float                           , farz                                            , 0x2C)
        SCHEMA_FIELD(float                           , maxdensity                                      , 0x30)
        SCHEMA_FIELD(float                           , exponent                                        , 0x34)
        SCHEMA_FIELD(float                           , HDRColorScale                                   , 0x38)
        SCHEMA_FIELD(float                           , skyboxFogFactor                                 , 0x3C)
        SCHEMA_FIELD(float                           , skyboxFogFactorLerpTo                           , 0x40)
        SCHEMA_FIELD(float                           , startLerpTo                                     , 0x44)
        SCHEMA_FIELD(float                           , endLerpTo                                       , 0x48)
        SCHEMA_FIELD(float                           , maxdensityLerpTo                                , 0x4C)
        SCHEMA_FIELD(::GameTime_t                    , lerptime                                        , 0x50)
        SCHEMA_FIELD(float                           , duration                                        , 0x54)
        SCHEMA_FIELD(float                           , blendtobackground                               , 0x58)
        SCHEMA_FIELD(float                           , scattering                                      , 0x5C)
        SCHEMA_FIELD(float                           , locallightscale                                 , 0x60)
        SCHEMA_FIELD(bool                            , enable                                          , 0x64)
        SCHEMA_FIELD(bool                            , blend                                           , 0x65)
        SCHEMA_FIELD(bool                            , m_bPadding2                                     , 0x66)
        SCHEMA_FIELD(bool                            , m_bPadding                                      , 0x67)
    };

    class CBasePlayerWeaponVData {
    public:
        using _Type0 = CUtlOrderedMap<WeaponSound_t,CSoundEventName>;
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCModel>>, m_szWorldModel                                  , 0x28)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCModel>>, m_szWorldModelAg2Override                       , 0x108)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCModel>>, m_sToolsOnlyOwnerModelName                      , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bBuiltRightHanded                             , 0x2C8)
        SCHEMA_FIELD(bool                            , m_bAllowFlipping                                , 0x2C9)
        SCHEMA_FIELD(CAttachmentNameSymbolWithStorage, m_sMuzzleAttachment                             , 0x2D0)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIParticleSystemDefinition>>, m_szMuzzleFlashParticle                         , 0x2F0)
        SCHEMA_FIELD(::CUtlString                    , m_szMuzzleFlashParticleConfig                   , 0x3D0)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIParticleSystemDefinition>>, m_szBarrelSmokeParticle                         , 0x3D8)
        SCHEMA_FIELD(std::uint8_t                    , m_nMuzzleSmokeShotThreshold                     , 0x4B8)
        SCHEMA_FIELD(float                           , m_flMuzzleSmokeTimeout                          , 0x4BC)
        SCHEMA_FIELD(float                           , m_flMuzzleSmokeDecrementRate                    , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bGenerateMuzzleLight                          , 0x4C4)
        SCHEMA_FIELD(bool                            , m_bLinkedCooldowns                              , 0x4C5)
        SCHEMA_FIELD(ItemFlagTypes_t                 , m_iFlags                                        , 0x4C6)
        SCHEMA_FIELD(std::int32_t                    , m_iWeight                                       , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bAutoSwitchTo                                 , 0x4CC)
        SCHEMA_FIELD(bool                            , m_bAutoSwitchFrom                               , 0x4CD)
        SCHEMA_FIELD(AmmoIndex_t                     , m_nPrimaryAmmoType                              , 0x4CE)
        SCHEMA_FIELD(AmmoIndex_t                     , m_nSecondaryAmmoType                            , 0x4CF)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxClip1                                     , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxClip2                                     , 0x4D4)
        SCHEMA_FIELD(std::int32_t                    , m_iDefaultClip1                                 , 0x4D8)
        SCHEMA_FIELD(std::int32_t                    , m_iDefaultClip2                                 , 0x4DC)
        SCHEMA_FIELD(bool                            , m_bReserveAmmoAsClips                           , 0x4E0)
        SCHEMA_FIELD(bool                            , m_bTreatAsSingleClip                            , 0x4E1)
        SCHEMA_FIELD(bool                            , m_bKeepLoadedAmmo                               , 0x4E2)
        SCHEMA_FIELD(RumbleEffect_t                  , m_iRumbleEffect                                 , 0x4E4)
        SCHEMA_FIELD(float                           , m_flDropSpeed                                   , 0x4E8)
        SCHEMA_FIELD(std::int32_t                    , m_iSlot                                         , 0x4EC)
        SCHEMA_FIELD(std::int32_t                    , m_iPosition                                     , 0x4F0)
        SCHEMA_FIELD(_Type0                          , m_aShootSounds                                  , 0x4F8)
    };

    class CRelativeLocation {
    public:
        SCHEMA_FIELD(RelativeLocationType_t          , m_Type                                          , 0x18)
        SCHEMA_FIELD(::Vector                        , m_vRelativeOffset                               , 0x1C)
        SCHEMA_FIELD(VectorWS                        , m_vWorldSpacePos                                , 0x28)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x34)
    };

    class PhysObjectHeader_t {
    public:
        SCHEMA_FIELD(PhysInterfaceId_t               , type                                            , 0x0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , hEntity                                         , 0x4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , fieldName                                       , 0x8)
        SCHEMA_FIELD(std::int32_t                    , nObjects                                        , 0x10)
        SCHEMA_FIELD(::CUtlSymbolLarge               , modelName                                       , 0x18)
        SCHEMA_FIELD(::AABB_t                        , bbox                                            , 0x20)
        SCHEMA_FIELD(physics_save_sphere_t           , sphere                                          , 0x38)
        SCHEMA_FIELD(std::int32_t                    , iCollide                                        , 0x3C)
    };

    class CNmSnapWeaponTask {
    public:
    };

    class CHintMessageQueue {
    public:
        SCHEMA_FIELD(float                           , m_tmMessageEnd                                  , 0x0)
        SCHEMA_FIELD(CUtlVector<CHintMessage*>       , m_messages                                      , 0x8)
        SCHEMA_FIELD(CBasePlayerController*          , m_pPlayerController                             , 0x20)
    };

    class CInButtonState {
    public:
        SCHEMA_FIELD(std::uint64_t                   , m_pButtonStates                                 , 0x8)
    };

    class CNavVolumeSphericalShell {
    public:
        SCHEMA_FIELD(float                           , m_flRadiusInner                                 , 0x88)
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

    class CCS2WeaponGraphController {
    public:
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_action                                        , 0x88)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bActionReset                                  , 0xA0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flWeaponActionSpeedScale                      , 0xB8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_weaponCategory                                , 0xD0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_weaponType                                    , 0xE8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_weaponExtraInfo                               , 0x100)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flWeaponAmmo                                  , 0x118)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flWeaponAmmoMax                               , 0x130)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flWeaponAmmoReserve                           , 0x148)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bWeaponIsSilenced                             , 0x160)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flWeaponIronsightAmount                       , 0x178)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bIsUsingLegacyModel                           , 0x190)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_idleVariation                                 , 0x1A8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_deployVariation                               , 0x1C0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_attackType                                    , 0x1D8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_attackThrowStrength                           , 0x1F0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flAttackVariation                             , 0x208)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_inspectVariation                              , 0x220)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_inspectExtraInfo                              , 0x238)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_reloadStage                                   , 0x250)
    };

    class CPulseCell_Step_CallExternalMethod {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x48)
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardIndex                              , 0x58)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_ExpectedArgs                                  , 0x60)
        SCHEMA_FIELD(PulseMethodCallMode_t           , m_nAsyncCallMode                                , 0x70)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x78)
    };

    class CAnimGraphControllerManager {
    public:
        SCHEMA_FIELD(CUtlVector<CAnimGraphControllerBase*>, m_controllers                                   , 0x0)
        SCHEMA_FIELD(bool                            , m_bGraphBindingsCreated                         , 0xA8)
    };

    class CWorldCompositionChunkReferenceElement_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strMapToLoad                                  , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_strLandmarkName                               , 0x8)
    };

    class CPulse_OutflowConnection {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutflowName                             , 0x0)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nDestChunk                                    , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nInstruction                                  , 0x14)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_OutflowRegisterMap                            , 0x18)
    };

    class CNetworkTransmitComponent {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_nTransmitStateOwnedCounter                    , 0x184)
    };

    class globalentity_t {
    public:
        SCHEMA_FIELD(CUtlSymbol                      , name                                            , 0x0)
        SCHEMA_FIELD(CUtlSymbol                      , levelName                                       , 0x2)
        SCHEMA_FIELD(GLOBALESTATE                    , state                                           , 0x4)
        SCHEMA_FIELD(std::int32_t                    , counter                                         , 0x8)
    };

    class CPulseCell_Timeline_TimelineEvent_t {
    public:
        SCHEMA_FIELD(float                           , m_flTimeFromPrevious                            , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EventOutflow                                  , 0x8)
    };

    class CPulseCell_Outflow_ScriptedSequence_CursorState_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_scriptedSequence                              , 0x0)
    };

    class CPulseCell_IsRequirementValid_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bIsValid                                      , 0x0)
    };

    class CPhysMotorAPI {
    public:
    };

    class EntityRenderAttribute_t {
    public:
        SCHEMA_FIELD(CUtlStringToken                 , m_ID                                            , 0x30)
        SCHEMA_FIELD(::Vector4D                      , m_Values                                        , 0x34)
    };

    class CPointTeleportAPI {
    public:
    };

    class CSkeletonInstance : public CGameSceneNode {
    public:
        SCHEMA_FIELD(CModelState                     , m_modelState                                    , 0x130)
        SCHEMA_FIELD(bool                            , m_bUseParentRenderBounds                        , 0x380)
        SCHEMA_FIELD(bool                            , m_bDisableSolidCollisionsForHierarchy           , 0x381)

        SCHEMA_FIELD(CUtlStringToken                 , m_materialGroup                                 , 0x384)
        SCHEMA_FIELD(std::uint8_t                    , m_nHitboxSet                                    , 0x388)
        SCHEMA_FIELD(bool                            , m_bForceServerConstraintsEnabled                , 0x3E4)
    };

    class CStopwatchBase : public CSimpleSimTimer {
    public:
        SCHEMA_FIELD(bool                            , m_fIsRunning                                    , 0x8)
    };

    class CSimTimer : public CSimpleSimTimer {
    public:
        SCHEMA_FIELD(float                           , m_flInterval                                    , 0x8)
    };

    class CRandSimTimer : public CSimpleSimTimer {
    public:
        SCHEMA_FIELD(float                           , m_flMinInterval                                 , 0x8)
        SCHEMA_FIELD(float                           , m_flMaxInterval                                 , 0xC)
    };

    class RelationshipOverride_t : public Relationship_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , entity                                          , 0x8)
        SCHEMA_FIELD(Class_T                         , classType                                       , 0xC)
    };

    class CCSPlayerController_InventoryServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_unMusicID                                     , 0x40)
        SCHEMA_FIELD(MedalRank_t                     , m_rank                                          , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicLevel                       , 0x5C)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicCommendsLeader              , 0x60)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicCommendsTeacher             , 0x64)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicCommendsFriendly            , 0x68)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataXpTrailLevel                      , 0x6C)
        SCHEMA_FIELD(std::uint32_t                   , m_unEquippedPlayerSprayIDs                      , 0xF48)
        SCHEMA_FIELD(std::uint64_t                   , m_unCurrentLoadoutHash                          , 0xF50)
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<ServerAuthoritativeWeaponSlot_t>, m_vecServerAuthoritativeWeaponSlots             , 0xF58)
    };

    class CCSPlayerController_DamageServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSendUpdate                                   , 0x40)
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<CDamageRecord>, m_DamageList                                    , 0x48)
    };

    class CCSPlayerController_ActionTrackingServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<CSPerRoundStats_t>, m_perRoundStats                                 , 0x40)
        SCHEMA_FIELD(CSMatchStats_t                  , m_matchStats                                    , 0xC8)
        SCHEMA_FIELD(std::int32_t                    , m_iNumRoundKills                                , 0x188)
        SCHEMA_FIELD(std::int32_t                    , m_iNumRoundKillsHeadshots                       , 0x18C)
        SCHEMA_FIELD(float                           , m_flTotalRoundDamageDealt                       , 0x190)
    };

    class CCSPlayerController_InGameMoneyServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(bool                            , m_bReceivesMoneyNextRound                       , 0x40)
        SCHEMA_FIELD(std::int32_t                    , m_iMoneyEarnedForNextRound                      , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_iAccount                                      , 0x48)
        SCHEMA_FIELD(std::int32_t                    , m_iStartAccount                                 , 0x4C)
        SCHEMA_FIELD(std::int32_t                    , m_iTotalCashSpent                               , 0x50)
        SCHEMA_FIELD(std::int32_t                    , m_iCashSpentThisRound                           , 0x54)
    };

    class CTouchExpansionComponent : public CEntityComponent {
    public:
    };

    class CHitboxComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(float                           , m_flBoundsExpandRadius                          , 0x14)
    };

    class CPathQueryComponent : public CEntityComponent {
    public:
    };

    class CRenderComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x10)
        SCHEMA_FIELD(bool                            , m_bIsRenderingWithViewModels                    , 0x50)
        SCHEMA_FIELD(std::uint32_t                   , m_nSplitscreenFlags                             , 0x54)
        SCHEMA_FIELD(bool                            , m_bEnableRendering                              , 0x58)
        SCHEMA_FIELD(bool                            , m_bInterpolationReadyToDraw                     , 0xA8)
    };

    class CPropDataComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(float                           , m_flDmgModBullet                                , 0x10)
        SCHEMA_FIELD(float                           , m_flDmgModClub                                  , 0x14)
        SCHEMA_FIELD(float                           , m_flDmgModExplosive                             , 0x18)
        SCHEMA_FIELD(float                           , m_flDmgModFire                                  , 0x1C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPhysicsDamageTableName                     , 0x20)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszBasePropData                               , 0x28)
        SCHEMA_FIELD(std::int32_t                    , m_nInteractions                                 , 0x30)
        SCHEMA_FIELD(bool                            , m_bSpawnMotionDisabled                          , 0x34)
        SCHEMA_FIELD(std::int32_t                    , m_nDisableTakePhysicsDamageSpawnFlag            , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nMotionDisabledSpawnFlag                      , 0x3C)
    };

    class CScriptComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_scriptClassName                               , 0x30)
    };

    class CLightComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x38)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0x75)
        SCHEMA_FIELD(::Color                         , m_SecondaryColor                                , 0x79)
        SCHEMA_FIELD(float                           , m_flBrightness                                  , 0x80)
        SCHEMA_FIELD(float                           , m_flBrightnessScale                             , 0x84)
        SCHEMA_FIELD(float                           , m_flBrightnessMult                              , 0x88)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x8C)
        SCHEMA_FIELD(float                           , m_flFalloff                                     , 0x90)
        SCHEMA_FIELD(float                           , m_flAttenuation0                                , 0x94)
        SCHEMA_FIELD(float                           , m_flAttenuation1                                , 0x98)
        SCHEMA_FIELD(float                           , m_flAttenuation2                                , 0x9C)
        SCHEMA_FIELD(float                           , m_flTheta                                       , 0xA0)
        SCHEMA_FIELD(float                           , m_flPhi                                         , 0xA4)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hLightCookie                                  , 0xA8)
        SCHEMA_FIELD(std::int32_t                    , m_nCascades                                     , 0xB0)
        SCHEMA_FIELD(std::int32_t                    , m_nCastShadows                                  , 0xB4)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowWidth                                  , 0xB8)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowHeight                                 , 0xBC)
        SCHEMA_FIELD(bool                            , m_bRenderDiffuse                                , 0xC0)
        SCHEMA_FIELD(std::int32_t                    , m_nRenderSpecular                               , 0xC4)
        SCHEMA_FIELD(bool                            , m_bRenderTransmissive                           , 0xC8)
        SCHEMA_FIELD(float                           , m_flOrthoLightWidth                             , 0xCC)
        SCHEMA_FIELD(float                           , m_flOrthoLightHeight                            , 0xD0)
        SCHEMA_FIELD(std::int32_t                    , m_nStyle                                        , 0xD4)
        SCHEMA_FIELD(::CUtlString                    , m_Pattern                                       , 0xD8)
        SCHEMA_FIELD(std::int32_t                    , m_nCascadeRenderStaticObjects                   , 0xE0)
        SCHEMA_FIELD(float                           , m_flShadowCascadeCrossFade                      , 0xE4)
        SCHEMA_FIELD(float                           , m_flShadowCascadeDistanceFade                   , 0xE8)
        SCHEMA_FIELD(float                           , m_flShadowCascadeDistance0                      , 0xEC)
        SCHEMA_FIELD(float                           , m_flShadowCascadeDistance1                      , 0xF0)
        SCHEMA_FIELD(float                           , m_flShadowCascadeDistance2                      , 0xF4)
        SCHEMA_FIELD(float                           , m_flShadowCascadeDistance3                      , 0xF8)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowCascadeResolution0                     , 0xFC)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowCascadeResolution1                     , 0x100)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowCascadeResolution2                     , 0x104)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowCascadeResolution3                     , 0x108)
        SCHEMA_FIELD(bool                            , m_bUsesBakedShadowing                           , 0x10C)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowPriority                               , 0x110)
        SCHEMA_FIELD(std::int32_t                    , m_nBakedShadowIndex                             , 0x114)
        SCHEMA_FIELD(std::int32_t                    , m_nLightPathUniqueId                            , 0x118)
        SCHEMA_FIELD(std::int32_t                    , m_nLightMapUniqueId                             , 0x11C)
        SCHEMA_FIELD(bool                            , m_bRenderToCubemaps                             , 0x120)
        SCHEMA_FIELD(bool                            , m_bAllowSSTGeneration                           , 0x121)
        SCHEMA_FIELD(std::int32_t                    , m_nDirectLight                                  , 0x124)
        SCHEMA_FIELD(std::int32_t                    , m_nBounceLight                                  , 0x128)
        SCHEMA_FIELD(float                           , m_flBounceScale                                 , 0x12C)
        SCHEMA_FIELD(float                           , m_flFadeMinDist                                 , 0x130)
        SCHEMA_FIELD(float                           , m_flFadeMaxDist                                 , 0x134)
        SCHEMA_FIELD(float                           , m_flShadowFadeMinDist                           , 0x138)
        SCHEMA_FIELD(float                           , m_flShadowFadeMaxDist                           , 0x13C)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x140)
        SCHEMA_FIELD(bool                            , m_bFlicker                                      , 0x141)
        SCHEMA_FIELD(bool                            , m_bPrecomputedFieldsValid                       , 0x142)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedBoundsMins                        , 0x144)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedBoundsMaxs                        , 0x150)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin                         , 0x15C)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles                         , 0x168)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent                         , 0x174)
        SCHEMA_FIELD(float                           , m_flPrecomputedMaxRange                         , 0x180)
        SCHEMA_FIELD(std::int32_t                    , m_nFogLightingMode                              , 0x184)
        SCHEMA_FIELD(float                           , m_flFogContributionStength                      , 0x188)
        SCHEMA_FIELD(float                           , m_flNearClipPlane                               , 0x18C)
        SCHEMA_FIELD(::Color                         , m_SkyColor                                      , 0x190)
        SCHEMA_FIELD(float                           , m_flSkyIntensity                                , 0x194)
        SCHEMA_FIELD(::Color                         , m_SkyAmbientBounce                              , 0x198)
        SCHEMA_FIELD(bool                            , m_bUseSecondaryColor                            , 0x19C)
        SCHEMA_FIELD(bool                            , m_bMixedShadows                                 , 0x19D)
        SCHEMA_FIELD(::GameTime_t                    , m_flLightStyleStartTime                         , 0x1A0)
        SCHEMA_FIELD(float                           , m_flCapsuleLength                               , 0x1A4)
        SCHEMA_FIELD(float                           , m_flMinRoughness                                , 0x1A8)
        SCHEMA_FIELD(bool                            , m_bPvsModifyEntity                              , 0x1B8)
    };

    class CBodyComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(CGameSceneNode*                 , m_pSceneNode                                    , 0x8)
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x48)
    };

    class CAttributeContainer : public CAttributeManager {
    public:
        SCHEMA_FIELD(CEconItemView                   , m_Item                                          , 0x50)
    };

    class CCSPlayer_PingServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flPlayerPingTokens                            , 0x48)
        SCHEMA_FIELD(CHandle<CPlayerPing>            , m_hPlayerPing                                   , 0x5C)
    };

    class CCSPlayer_RadioServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flGotHostageTalkTimer                         , 0x48)
        SCHEMA_FIELD(::GameTime_t                    , m_flDefusingTalkTimer                           , 0x4C)
        SCHEMA_FIELD(::GameTime_t                    , m_flC4PlantTalkTimer                            , 0x50)
        SCHEMA_FIELD(::GameTime_t                    , m_flRadioTokenSlots                             , 0x54)
        SCHEMA_FIELD(bool                            , m_bIgnoreRadio                                  , 0x60)
    };

    class CPlayer_ItemServices : public CPlayerPawnComponent {
    public:
    };

    class CCSPlayer_HostageServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hCarriedHostage                               , 0x48)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hCarriedHostageProp                           , 0x4C)
    };

    class CPlayer_MovementServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nImpulse                                      , 0x48)
        SCHEMA_FIELD(CInButtonState                  , m_nButtons                                      , 0x50)
        SCHEMA_FIELD(std::uint64_t                   , m_nQueuedButtonDownMask                         , 0x70)
        SCHEMA_FIELD(std::uint64_t                   , m_nQueuedButtonChangeMask                       , 0x78)
        SCHEMA_FIELD(std::uint64_t                   , m_nButtonDoublePressed                          , 0x80)
        SCHEMA_FIELD(std::uint32_t                   , m_pButtonPressedCmdNumber                       , 0x88)
        SCHEMA_FIELD(std::uint32_t                   , m_nLastCommandNumberProcessed                   , 0x188)
        SCHEMA_FIELD(std::uint64_t                   , m_nToggleButtonDownMask                         , 0x190)
        SCHEMA_FIELD(float                           , m_flCmdForwardMove                              , 0x1A0)
        SCHEMA_FIELD(float                           , m_flCmdLeftMove                                 , 0x1A4)
        SCHEMA_FIELD(float                           , m_flCmdUpMove                                   , 0x1A8)
        SCHEMA_FIELD(float                           , m_flMaxspeed                                    , 0x1AC)
        SCHEMA_FIELD(float                           , m_arrForceSubtickMoveWhen                       , 0x1B0)
        SCHEMA_FIELD(float                           , m_flForwardMove                                 , 0x1C0)
        SCHEMA_FIELD(float                           , m_flLeftMove                                    , 0x1C4)
        SCHEMA_FIELD(float                           , m_flUpMove                                      , 0x1C8)
        SCHEMA_FIELD(::Vector                        , m_vecLastMovementImpulses                       , 0x1CC)
        SCHEMA_FIELD(::QAngle                        , m_vecOldViewAngles                              , 0x240)
    };

    class CPlayer_ObserverServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_iObserverMode                                 , 0x48)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hObserverTarget                               , 0x4C)
        SCHEMA_FIELD(ObserverMode_t                  , m_iObserverLastMode                             , 0x50)
        SCHEMA_FIELD(bool                            , m_bForcedObserverMode                           , 0x54)
    };

    class CCSPlayer_BulletServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_totalHitsOnServer                             , 0x48)
    };

    class CPlayer_AutoaimServices : public CPlayerPawnComponent {
    public:
    };

    class CPlayer_CameraServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(::QAngle                        , m_vecCsViewPunchAngle                           , 0x48)
        SCHEMA_FIELD(::GameTick_t                    , m_nCsViewPunchAngleTick                         , 0x54)
        SCHEMA_FIELD(float                           , m_flCsViewPunchAngleTickRatio                   , 0x58)
        SCHEMA_FIELD(fogplayerparams_t               , m_PlayerFog                                     , 0x60)
        SCHEMA_FIELD(CHandle<CColorCorrection>       , m_hColorCorrectionCtrl                          , 0xA0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hViewEntity                                   , 0xA4)
        SCHEMA_FIELD(CHandle<CTonemapController2>    , m_hTonemapController                            , 0xA8)
        SCHEMA_FIELD(audioparams_t                   , m_audio                                         , 0xB0)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CPostProcessingVolume>>, m_PostProcessingVolumes                         , 0x128)
        SCHEMA_FIELD(float                           , m_flOldPlayerZ                                  , 0x140)
        SCHEMA_FIELD(float                           , m_flOldPlayerViewOffsetZ                        , 0x144)
        SCHEMA_FIELD(CUtlVector<CHandle<CEnvSoundscapeTriggerable>>, m_hTriggerSoundscapeList                        , 0x160)
    };

    class CPlayer_FlashlightServices : public CPlayerPawnComponent {
    public:
    };

    class CCSPlayer_BuyServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<SellbackPurchaseEntry_t>, m_vecSellbackPurchaseEntries                    , 0xD0)
    };

    class CCSPlayer_ActionTrackingServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CHandle<CBasePlayerWeapon>      , m_hLastWeaponBeforeC4AutoSwitch                 , 0x1F8)
        SCHEMA_FIELD(bool                            , m_bIsRescuing                                   , 0x224)
        SCHEMA_FIELD(WeaponPurchaseTracker_t         , m_weaponPurchasesThisMatch                      , 0x228)
        SCHEMA_FIELD(WeaponPurchaseTracker_t         , m_weaponPurchasesThisRound                      , 0x298)
    };

    class CPlayer_WaterServices : public CPlayerPawnComponent {
    public:
    };

    class CPlayer_UseServices : public CPlayerPawnComponent {
    public:
    };

    class CCSPlayer_AimPunchServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(::GameTick_t                    , m_predictableBaseTick                           , 0x48)
        SCHEMA_FIELD(float                           , m_predictableBaseTickInterpAmount               , 0x4C)
        SCHEMA_FIELD(::QAngle                        , m_predictableBaseAngle                          , 0x50)
        SCHEMA_FIELD(::QAngle                        , m_predictableBaseAngleVel                       , 0x5C)
        SCHEMA_FIELD(::GameTick_t                    , m_unpredictableBaseTick                         , 0xA0)
        SCHEMA_FIELD(::QAngle                        , m_unpredictableBaseAngle                        , 0xA4)
    };

    class CPlayer_WeaponServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBasePlayerWeapon>>, m_hMyWeapons                                    , 0x48)
        SCHEMA_FIELD(CHandle<CBasePlayerWeapon>      , m_hActiveWeapon                                 , 0x60)
        SCHEMA_FIELD(CHandle<CBasePlayerWeapon>      , m_hLastWeapon                                   , 0x64)
        SCHEMA_FIELD(std::uint16_t                   , m_iAmmo                                         , 0x68)
        SCHEMA_FIELD(bool                            , m_bPreventWeaponPickup                          , 0xA8)
    };

    class CCSPlayer_DamageReactServices : public CPlayerPawnComponent {
    public:
    };

    class CPointEntity : public CBaseEntity {
    public:
    };

    class CScriptedSequence : public CBaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEntry                                      , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPreIdle                                    , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPlay                                       , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPostIdle                                   , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszModifierToAddOnPlay                        , 0x4C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszNextScript                                 , 0x4D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEntity                                     , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSyncGroup                                  , 0x4E0)
        SCHEMA_FIELD(ScriptedMoveTo_t                , m_nMoveTo                                       , 0x4E8)
        SCHEMA_FIELD(SharedMovementGait_t            , m_nMoveToGait                                   , 0x4EC)
        SCHEMA_FIELD(ScriptedHeldWeaponBehavior_t    , m_nHeldWeaponBehavior                           , 0x4F0)
        SCHEMA_FIELD(ForcedCrouchState_t             , m_nForcedCrouchState                            , 0x4F4)
        SCHEMA_FIELD(bool                            , m_bIsPlayingPreIdle                             , 0x4F8)
        SCHEMA_FIELD(bool                            , m_bIsPlayingEntry                               , 0x4F9)
        SCHEMA_FIELD(bool                            , m_bIsPlayingAction                              , 0x4FA)
        SCHEMA_FIELD(bool                            , m_bIsPlayingPostIdle                            , 0x4FB)
        SCHEMA_FIELD(bool                            , m_bDontRotateOther                              , 0x4FC)
        SCHEMA_FIELD(bool                            , m_bIsRepeatable                                 , 0x4FD)
        SCHEMA_FIELD(bool                            , m_bShouldLeaveCorpse                            , 0x4FE)
        SCHEMA_FIELD(bool                            , m_bStartOnSpawn                                 , 0x4FF)
        SCHEMA_FIELD(bool                            , m_bDisallowInterrupts                           , 0x500)
        SCHEMA_FIELD(bool                            , m_bCanOverrideNPCState                          , 0x501)
        SCHEMA_FIELD(bool                            , m_bDontTeleportAtEnd                            , 0x502)
        SCHEMA_FIELD(bool                            , m_bHighPriority                                 , 0x503)
        SCHEMA_FIELD(bool                            , m_bHideDebugComplaints                          , 0x504)
        SCHEMA_FIELD(bool                            , m_bContinueOnDeath                              , 0x505)
        SCHEMA_FIELD(bool                            , m_bLoopPreIdleSequence                          , 0x506)
        SCHEMA_FIELD(bool                            , m_bLoopActionSequence                           , 0x507)
        SCHEMA_FIELD(bool                            , m_bLoopPostIdleSequence                         , 0x508)
        SCHEMA_FIELD(bool                            , m_bSynchPostIdles                               , 0x509)
        SCHEMA_FIELD(bool                            , m_bIgnoreLookAt                                 , 0x50A)
        SCHEMA_FIELD(bool                            , m_bIgnoreGravity                                , 0x50B)
        SCHEMA_FIELD(bool                            , m_bDisableNPCCollisions                         , 0x50C)
        SCHEMA_FIELD(bool                            , m_bKeepAnimgraphLockedPost                      , 0x50D)
        SCHEMA_FIELD(bool                            , m_bDontAddModifiers                             , 0x50E)
        SCHEMA_FIELD(bool                            , m_bDisableAimingWhileMoving                     , 0x50F)
        SCHEMA_FIELD(bool                            , m_bIgnoreRotation                               , 0x510)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x514)
        SCHEMA_FIELD(float                           , m_flRepeat                                      , 0x518)
        SCHEMA_FIELD(float                           , m_flPlayAnimFadeInTime                          , 0x51C)
        SCHEMA_FIELD(float                           , m_flMoveInterpTime                              , 0x520)
        SCHEMA_FIELD(float                           , m_flAngRate                                     , 0x524)
        SCHEMA_FIELD(float                           , m_flMoveSpeed                                   , 0x528)
        SCHEMA_FIELD(bool                            , m_bWaitUntilMoveCompletesToStartAnimation       , 0x52C)
        SCHEMA_FIELD(std::int32_t                    , m_nNotReadySequenceCount                        , 0x530)
        SCHEMA_FIELD(::GameTime_t                    , m_startTime                                     , 0x534)
        SCHEMA_FIELD(bool                            , m_bWaitForBeginSequence                         , 0x538)
        SCHEMA_FIELD(std::int32_t                    , m_saved_effects                                 , 0x53C)
        SCHEMA_FIELD(std::int32_t                    , m_savedFlags                                    , 0x540)
        SCHEMA_FIELD(std::int32_t                    , m_savedCollisionGroup                           , 0x544)
        SCHEMA_FIELD(bool                            , m_bInterruptable                                , 0x548)
        SCHEMA_FIELD(bool                            , m_sequenceStarted                               , 0x549)
        SCHEMA_FIELD(bool                            , m_bPositionRelativeToOtherEntity                , 0x54A)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetEnt                                    , 0x54C)
        SCHEMA_FIELD(CHandle<CScriptedSequence>      , m_hNextCine                                     , 0x550)
        SCHEMA_FIELD(bool                            , m_bThinking                                     , 0x554)
        SCHEMA_FIELD(bool                            , m_bInitiatedSelfDelete                          , 0x555)
        SCHEMA_FIELD(bool                            , m_bIsTeleportingDueToMoveTo                     , 0x556)
        SCHEMA_FIELD(bool                            , m_bAllowCustomInterruptConditions               , 0x557)
        SCHEMA_FIELD(CHandle<CBaseAnimGraph>         , m_hForcedTarget                                 , 0x558)
        SCHEMA_FIELD(bool                            , m_bDontCancelOtherSequences                     , 0x55C)
        SCHEMA_FIELD(bool                            , m_bForceSynch                                   , 0x55D)
        SCHEMA_FIELD(bool                            , m_bPreventUpdateYawOnFinish                     , 0x55E)
        SCHEMA_FIELD(bool                            , m_bEnsureOnNavmeshOnFinish                      , 0x55F)
        SCHEMA_FIELD(ScriptedOnDeath_t               , m_onDeathBehavior                               , 0x560)
        SCHEMA_FIELD(ScriptedConflictResponse_t      , m_ConflictResponse                              , 0x564)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBeginSequence                               , 0x568)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnActionStartOrLoop                           , 0x580)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEndSequence                                 , 0x598)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPostIdleEndSequence                         , 0x5B0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCancelSequence                              , 0x5C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCancelFailedSequence                        , 0x5E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnScriptEvent                                 , 0x5F8)
        SCHEMA_FIELD(CTransform                      , m_matOtherToMain                                , 0x6C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hInteractionMainEntity                        , 0x6E0)
        SCHEMA_FIELD(std::int32_t                    , m_iPlayerDeathBehavior                          , 0x6E4)
        SCHEMA_FIELD(bool                            , m_bSkipFadeIn                                   , 0x6E8)
    };

    class CPhysicsSpring : public CBaseEntity {
    public:
        SCHEMA_FIELD(IPhysicsJoint*                  , m_pSpringJoint                                  , 0x4A8)
        SCHEMA_FIELD(float                           , m_flFrequency                                   , 0x4B0)
        SCHEMA_FIELD(float                           , m_flDampingRatio                                , 0x4B4)
        SCHEMA_FIELD(float                           , m_flRestLength                                  , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttachStart                               , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttachEnd                                 , 0x4C8)
        SCHEMA_FIELD(VectorWS                        , m_start                                         , 0x4D0)
        SCHEMA_FIELD(VectorWS                        , m_end                                           , 0x4DC)
        SCHEMA_FIELD(std::uint32_t                   , m_teleportTick                                  , 0x4E8)
    };

    class CCSGO_EndOfMatchLineupEndpoint : public CBaseEntity {
    public:
    };

    class CHandleTest : public CBaseEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_Handle                                        , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bSendHandle                                   , 0x4AC)
    };

    class CLogicNPCCounter : public CBaseEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMinCountAll                                 , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMaxCountAll                                 , 0x4C0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnFactorAll                                   , 0x4D8)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnMinPlayerDistAll                            , 0x4F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMinCount_1                                  , 0x518)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMaxCount_1                                  , 0x530)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnFactor_1                                    , 0x548)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnMinPlayerDist_1                             , 0x568)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMinCount_2                                  , 0x588)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMaxCount_2                                  , 0x5A0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnFactor_2                                    , 0x5B8)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnMinPlayerDist_2                             , 0x5D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMinCount_3                                  , 0x5F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMaxCount_3                                  , 0x610)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnFactor_3                                    , 0x628)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnMinPlayerDist_3                             , 0x648)
        SCHEMA_FIELD(CEntityHandle                   , m_hSource                                       , 0x668)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSourceEntityName                           , 0x670)
        SCHEMA_FIELD(float                           , m_flDistanceMax                                 , 0x678)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x67C)
        SCHEMA_FIELD(std::int32_t                    , m_nMinCountAll                                  , 0x680)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxCountAll                                  , 0x684)
        SCHEMA_FIELD(std::int32_t                    , m_nMinFactorAll                                 , 0x688)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxFactorAll                                 , 0x68C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszNPCClassname_1                             , 0x698)
        SCHEMA_FIELD(std::int32_t                    , m_nNPCState_1                                   , 0x6A0)
        SCHEMA_FIELD(bool                            , m_bInvertState_1                                , 0x6A4)
        SCHEMA_FIELD(std::int32_t                    , m_nMinCount_1                                   , 0x6A8)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxCount_1                                   , 0x6AC)
        SCHEMA_FIELD(std::int32_t                    , m_nMinFactor_1                                  , 0x6B0)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxFactor_1                                  , 0x6B4)
        SCHEMA_FIELD(float                           , m_flDefaultDist_1                               , 0x6BC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszNPCClassname_2                             , 0x6C0)
        SCHEMA_FIELD(std::int32_t                    , m_nNPCState_2                                   , 0x6C8)
        SCHEMA_FIELD(bool                            , m_bInvertState_2                                , 0x6CC)
        SCHEMA_FIELD(std::int32_t                    , m_nMinCount_2                                   , 0x6D0)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxCount_2                                   , 0x6D4)
        SCHEMA_FIELD(std::int32_t                    , m_nMinFactor_2                                  , 0x6D8)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxFactor_2                                  , 0x6DC)
        SCHEMA_FIELD(float                           , m_flDefaultDist_2                               , 0x6E4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszNPCClassname_3                             , 0x6E8)
        SCHEMA_FIELD(std::int32_t                    , m_nNPCState_3                                   , 0x6F0)
        SCHEMA_FIELD(bool                            , m_bInvertState_3                                , 0x6F4)
        SCHEMA_FIELD(std::int32_t                    , m_nMinCount_3                                   , 0x6F8)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxCount_3                                   , 0x6FC)
        SCHEMA_FIELD(std::int32_t                    , m_nMinFactor_3                                  , 0x700)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxFactor_3                                  , 0x704)
        SCHEMA_FIELD(float                           , m_flDefaultDist_3                               , 0x70C)
    };

    class CPlayerPing : public CBaseEntity {
    public:
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hPlayer                                       , 0x4B0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hPingedEntity                                 , 0x4B4)
        SCHEMA_FIELD(std::int32_t                    , m_iType                                         , 0x4B8)
        SCHEMA_FIELD(bool                            , m_bUrgent                                       , 0x4BC)
        SCHEMA_FIELD(char                            , m_szPlaceName                                   , 0x4BD)
    };

    class CPointEntityFinder : public CBaseEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntity                                       , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x4B0)
        SCHEMA_FIELD(CHandle<CBaseFilter>            , m_hFilter                                       , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iRefName                                      , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hReference                                    , 0x4C8)
        SCHEMA_FIELD(EntFinderMethod_t               , m_FindMethod                                    , 0x4CC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFoundEntity                                 , 0x4D0)
    };

    class CPathParticleRope : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bStartActive                                  , 0x4B0)
        SCHEMA_FIELD(float                           , m_flMaxSimulationTime                           , 0x4B4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEffectName                                 , 0x4B8)
        SCHEMA_FIELD(CUtlVector<CUtlSymbolLarge>     , m_PathNodes_Name                                , 0x4C0)
        SCHEMA_FIELD(float                           , m_flParticleSpacing                             , 0x4D8)
        SCHEMA_FIELD(float                           , m_flSlack                                       , 0x4DC)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4E0)
        SCHEMA_FIELD(::Color                         , m_ColorTint                                     , 0x4E4)
        SCHEMA_FIELD(std::int32_t                    , m_nEffectState                                  , 0x4E8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_iEffectIndex                                  , 0x4F0)
        SCHEMA_FIELD(CNetworkUtlVectorBase<Vector>   , m_PathNodes_Position                            , 0x4F8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<Vector>   , m_PathNodes_TangentIn                           , 0x510)
        SCHEMA_FIELD(CNetworkUtlVectorBase<Vector>   , m_PathNodes_TangentOut                          , 0x528)
        SCHEMA_FIELD(CNetworkUtlVectorBase<Vector>   , m_PathNodes_Color                               , 0x540)
        SCHEMA_FIELD(CNetworkUtlVectorBase<bool>     , m_PathNodes_PinEnabled                          , 0x558)
        SCHEMA_FIELD(CNetworkUtlVectorBase<float32>  , m_PathNodes_RadiusScale                         , 0x570)
    };

    class CFishPool : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_fishCount                                     , 0x4B8)
        SCHEMA_FIELD(float                           , m_maxRange                                      , 0x4BC)
        SCHEMA_FIELD(float                           , m_swimDepth                                     , 0x4C0)
        SCHEMA_FIELD(float                           , m_waterLevel                                    , 0x4C4)
        SCHEMA_FIELD(bool                            , m_isDormant                                     , 0x4C8)
        SCHEMA_FIELD(CUtlVector<CHandle<CFish>>      , m_fishes                                        , 0x4D0)
        SCHEMA_FIELD(CountdownTimer                  , m_visTimer                                      , 0x4E8)
    };

    class CCSPlayerResource : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bHostageAlive                                 , 0x4A8)
        SCHEMA_FIELD(bool                            , m_isHostageFollowingSomeone                     , 0x4B4)
        SCHEMA_FIELD(CEntityIndex                    , m_iHostageEntityIDs                             , 0x4C0)
        SCHEMA_FIELD(::Vector                        , m_bombsiteCenterA                               , 0x4F0)
        SCHEMA_FIELD(::Vector                        , m_bombsiteCenterB                               , 0x4FC)
        SCHEMA_FIELD(std::int32_t                    , m_hostageRescueX                                , 0x508)
        SCHEMA_FIELD(std::int32_t                    , m_hostageRescueY                                , 0x518)
        SCHEMA_FIELD(std::int32_t                    , m_hostageRescueZ                                , 0x528)
        SCHEMA_FIELD(bool                            , m_bEndMatchNextMapAllVoted                      , 0x538)
        SCHEMA_FIELD(bool                            , m_foundGoalPositions                            , 0x539)
    };

    class CEnvSoundscape : public CBaseEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlay                                        , 0x4A8)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_soundEventName                                , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bOverrideWithEvent                            , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_soundscapeIndex                               , 0x4D4)
        SCHEMA_FIELD(std::int32_t                    , m_soundscapeEntityListId                        , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_positionNames                                 , 0x4E0)
        SCHEMA_FIELD(CHandle<CEnvSoundscape>         , m_hProxySoundscape                              , 0x520)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x524)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_soundscapeName                                , 0x528)
        SCHEMA_FIELD(std::uint32_t                   , m_soundEventHash                                , 0x530)
    };

    class CSoundAreaEntityBase : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundAreaType                              , 0x4B0)
        SCHEMA_FIELD(::Vector                        , m_vPos                                          , 0x4B8)
    };

    class CEnvCombinedLightProbeVolume : public CBaseEntity {
    public:
        SCHEMA_FIELD(::Color                         , m_Entity_Color                                  , 0x1520)
        SCHEMA_FIELD(float                           , m_Entity_flBrightness                           , 0x1524)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hCubemapTexture                        , 0x1528)
        SCHEMA_FIELD(bool                            , m_Entity_bCustomCubemapTexture                  , 0x1530)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_AmbientCube         , 0x1538)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SDF                 , 0x1540)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_DC              , 0x1548)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_R               , 0x1550)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_G               , 0x1558)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_B               , 0x1560)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightIndicesTexture   , 0x1568)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightScalarsTexture   , 0x1570)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightShadowsTexture   , 0x1578)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMins                               , 0x1580)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMaxs                               , 0x158C)
        SCHEMA_FIELD(bool                            , m_Entity_bMoveable                              , 0x1598)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nHandshake                             , 0x159C)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nEnvCubeMapArrayIndex                  , 0x15A0)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nPriority                              , 0x15A4)
        SCHEMA_FIELD(bool                            , m_Entity_bStartDisabled                         , 0x15A8)
        SCHEMA_FIELD(float                           , m_Entity_flEdgeFadeDist                         , 0x15AC)
        SCHEMA_FIELD(::Vector                        , m_Entity_vEdgeFadeDists                         , 0x15B0)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeX                       , 0x15BC)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeY                       , 0x15C0)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeZ                       , 0x15C4)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasX                      , 0x15C8)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasY                      , 0x15CC)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasZ                      , 0x15D0)
        SCHEMA_FIELD(bool                            , m_Entity_bEnabled                               , 0x15E9)
    };

    class CEnvWind : public CBaseEntity {
    public:
        SCHEMA_FIELD(CEnvWindShared                  , m_EnvWindShared                                 , 0x4A8)
    };

    class CEnvLightProbeVolume : public CBaseEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_AmbientCube         , 0x14A0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SDF                 , 0x14A8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_DC              , 0x14B0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_R               , 0x14B8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_G               , 0x14C0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_B               , 0x14C8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightIndicesTexture   , 0x14D0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightScalarsTexture   , 0x14D8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightShadowsTexture   , 0x14E0)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMins                               , 0x14E8)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMaxs                               , 0x14F4)
        SCHEMA_FIELD(bool                            , m_Entity_bMoveable                              , 0x1500)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nHandshake                             , 0x1504)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nPriority                              , 0x1508)
        SCHEMA_FIELD(bool                            , m_Entity_bStartDisabled                         , 0x150C)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeX                       , 0x1510)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeY                       , 0x1514)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeZ                       , 0x1518)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasX                      , 0x151C)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasY                      , 0x1520)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasZ                      , 0x1524)
        SCHEMA_FIELD(bool                            , m_Entity_bEnabled                               , 0x1531)
    };

    class CRagdollManager : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int8_t                     , m_iCurrentMaxRagdollCount                       , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxRagdollCount                              , 0x4AC)
        SCHEMA_FIELD(bool                            , m_bSaveImportant                                , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bCanTakeDamage                                , 0x4B1)
    };

    class CLogicAuto : public CBaseEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMapSpawn                                    , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDemoMapSpawn                                , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnNewGame                                     , 0x4D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLoadGame                                    , 0x4F0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMapTransition                               , 0x508)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBackgroundMap                               , 0x520)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMultiNewMap                                 , 0x538)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMultiNewRound                               , 0x550)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnVREnabled                                   , 0x568)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnVRNotEnabled                                , 0x580)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_globalstate                                   , 0x598)
    };

    class CPhysicsWire : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nDensity                                      , 0x4A8)
    };

    class CTonemapController2 : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flAutoExposureMin                             , 0x4A8)
        SCHEMA_FIELD(float                           , m_flAutoExposureMax                             , 0x4AC)
        SCHEMA_FIELD(float                           , m_flExposureAdaptationSpeedUp                   , 0x4B0)
        SCHEMA_FIELD(float                           , m_flExposureAdaptationSpeedDown                 , 0x4B4)
        SCHEMA_FIELD(float                           , m_flTonemapEVSmoothingRange                     , 0x4B8)
    };

    class CGameGibManager : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bAllowNewGibs                                 , 0x4C0)
        SCHEMA_FIELD(std::int32_t                    , m_iCurrentMaxPieces                             , 0x4C4)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxPieces                                    , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_iLastFrame                                    , 0x4CC)
    };

    class CHandleDummy : public CBaseEntity {
    public:
    };

    class CSkyCamera : public CBaseEntity {
    public:
        SCHEMA_FIELD(sky3dparams_t                   , m_skyboxData                                    , 0x4A8)
        SCHEMA_FIELD(CUtlStringToken                 , m_skyboxSlotToken                               , 0x538)
        SCHEMA_FIELD(bool                            , m_bUseAngles                                    , 0x53C)
        SCHEMA_FIELD(CSkyCamera*                     , m_pNext                                         , 0x540)
    };

    class CCSPetPlacement : public CBaseEntity {
    public:
    };

    class CCommentaryAuto : public CBaseEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCommentaryNewGame                           , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCommentaryMidGame                           , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCommentaryMultiplayerSpawn                  , 0x4D8)
    };

    class CEnvDetailController : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flFadeStartDist                               , 0x4A8)
        SCHEMA_FIELD(float                           , m_flFadeEndDist                                 , 0x4AC)
    };

    class CCSPointScriptEntity : public CBaseEntity {
    public:
    };

    class CEntityFlame : public CBaseEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntAttached                                  , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bCheapEffect                                  , 0x4AC)
        SCHEMA_FIELD(float                           , m_flSize                                        , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bUseHitboxes                                  , 0x4B4)
        SCHEMA_FIELD(std::int32_t                    , m_iNumHitboxFires                               , 0x4B8)
        SCHEMA_FIELD(float                           , m_flHitboxFireScale                             , 0x4BC)
        SCHEMA_FIELD(::GameTime_t                    , m_flLifetime                                    , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAttacker                                     , 0x4C4)
        SCHEMA_FIELD(float                           , m_flDirectDamagePerSecond                       , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_iCustomDamageType                             , 0x4CC)
    };

    class CEnvEntityIgniter : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flLifetime                                    , 0x4A8)
    };

    class CFogController : public CBaseEntity {
    public:
        SCHEMA_FIELD(fogparams_t                     , m_fog                                           , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bUseAngles                                    , 0x510)
        SCHEMA_FIELD(std::int32_t                    , m_iChangedVariables                             , 0x514)
    };

    class CPlayerVisibility : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flVisibilityStrength                          , 0x4A8)
        SCHEMA_FIELD(float                           , m_flFogDistanceMultiplier                       , 0x4AC)
        SCHEMA_FIELD(float                           , m_flFogMaxDensityMultiplier                     , 0x4B0)
        SCHEMA_FIELD(float                           , m_flFadeTime                                    , 0x4B4)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4B8)
        SCHEMA_FIELD(bool                            , m_bIsEnabled                                    , 0x4B9)
    };

    class CEnvVolumetricFogController : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flScattering                                  , 0x4A8)
        SCHEMA_FIELD(::Color                         , m_TintColor                                     , 0x4AC)
        SCHEMA_FIELD(float                           , m_flAnisotropy                                  , 0x4B0)
        SCHEMA_FIELD(float                           , m_flFadeSpeed                                   , 0x4B4)
        SCHEMA_FIELD(float                           , m_flDrawDistance                                , 0x4B8)
        SCHEMA_FIELD(float                           , m_flFadeInStart                                 , 0x4BC)
        SCHEMA_FIELD(float                           , m_flFadeInEnd                                   , 0x4C0)
        SCHEMA_FIELD(float                           , m_flIndirectStrength                            , 0x4C4)
        SCHEMA_FIELD(std::int32_t                    , m_nVolumeDepth                                  , 0x4C8)
        SCHEMA_FIELD(float                           , m_fFirstVolumeSliceThickness                    , 0x4CC)
        SCHEMA_FIELD(std::int32_t                    , m_nIndirectTextureDimX                          , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_nIndirectTextureDimY                          , 0x4D4)
        SCHEMA_FIELD(std::int32_t                    , m_nIndirectTextureDimZ                          , 0x4D8)
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x4DC)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x4E8)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4F4)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartAnisoTime                              , 0x4F8)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartScatterTime                            , 0x4FC)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartDrawDistanceTime                       , 0x500)
        SCHEMA_FIELD(float                           , m_flStartAnisotropy                             , 0x504)
        SCHEMA_FIELD(float                           , m_flStartScattering                             , 0x508)
        SCHEMA_FIELD(float                           , m_flStartDrawDistance                           , 0x50C)
        SCHEMA_FIELD(float                           , m_flDefaultAnisotropy                           , 0x510)
        SCHEMA_FIELD(float                           , m_flDefaultScattering                           , 0x514)
        SCHEMA_FIELD(float                           , m_flDefaultDrawDistance                         , 0x518)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x51C)
        SCHEMA_FIELD(bool                            , m_bEnableIndirect                               , 0x51D)
        SCHEMA_FIELD(bool                            , m_bIsMaster                                     , 0x51E)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hFogIndirectTexture                           , 0x520)
        SCHEMA_FIELD(std::int32_t                    , m_nForceRefreshCount                            , 0x528)
        SCHEMA_FIELD(float                           , m_fNoiseSpeed                                   , 0x52C)
        SCHEMA_FIELD(float                           , m_fNoiseStrength                                , 0x530)
        SCHEMA_FIELD(::Vector                        , m_vNoiseScale                                   , 0x534)
        SCHEMA_FIELD(float                           , m_fWindSpeed                                    , 0x540)
        SCHEMA_FIELD(::Vector                        , m_vWindDirection                                , 0x544)
        SCHEMA_FIELD(bool                            , m_bFirstTime                                    , 0x550)
    };

    class CTeam : public CBaseEntity {
    public:
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBasePlayerController>>, m_aPlayerControllers                            , 0x4A8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBasePlayerPawn>>, m_aPlayers                                      , 0x4C0)
        SCHEMA_FIELD(std::int32_t                    , m_iScore                                        , 0x4D8)
        SCHEMA_FIELD(char                            , m_szTeamname                                    , 0x4DC)
    };

    class CTestEffect : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iLoop                                         , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_iBeam                                         , 0x4AC)
        SCHEMA_FIELD(CHandle<CBeam>                  , m_pBeam                                         , 0x4B0)
        SCHEMA_FIELD(::GameTime_t                    , m_flBeamTime                                    , 0x510)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x570)
    };

    class CCSGO_TeamPreviewCharacterPosition : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nVariant                                      , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_nRandom                                       , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_nOrdinal                                      , 0x4B0)
        SCHEMA_FIELD(::CUtlString                    , m_sWeaponName                                   , 0x4B8)
        SCHEMA_FIELD(std::uint64_t                   , m_xuid                                          , 0x4C0)
        SCHEMA_FIELD(CEconItemView                   , m_agentItem                                     , 0x4C8)
        SCHEMA_FIELD(CEconItemView                   , m_glovesItem                                    , 0x770)
        SCHEMA_FIELD(CEconItemView                   , m_weaponItem                                    , 0xA18)
    };

    class CGameRulesProxy : public CBaseEntity {
    public:
    };

    class CInfoLadderDismount : public CBaseEntity {
    public:
    };

    class CPointOrient : public CBaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpawnTargetName                            , 0x4A8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget                                       , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4B4)
        SCHEMA_FIELD(PointOrientGoalDirectionType_t  , m_nGoalDirection                                , 0x4B8)
        SCHEMA_FIELD(PointOrientConstraint_t         , m_nConstraint                                   , 0x4BC)
        SCHEMA_FIELD(float                           , m_flMaxTurnRate                                 , 0x4C0)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastGameTime                                , 0x4C4)
    };

    class CInfoVisibilityBox : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nMode                                         , 0x4AC)
        SCHEMA_FIELD(::Vector                        , m_vBoxSize                                      , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4BC)
    };

    class CEnableMotionFixup : public CBaseEntity {
    public:
    };

    class CEnvVolumetricFogVolume : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4A8)
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x4AC)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x4B8)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4C4)
        SCHEMA_FIELD(bool                            , m_bIndirectUseLPVs                              , 0x4C5)
        SCHEMA_FIELD(float                           , m_flStrength                                    , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_nFalloffShape                                 , 0x4CC)
        SCHEMA_FIELD(float                           , m_flFalloffExponent                             , 0x4D0)
        SCHEMA_FIELD(float                           , m_flHeightFogDepth                              , 0x4D4)
        SCHEMA_FIELD(float                           , m_fHeightFogEdgeWidth                           , 0x4D8)
        SCHEMA_FIELD(float                           , m_fIndirectLightStrength                        , 0x4DC)
        SCHEMA_FIELD(float                           , m_fSunLightStrength                             , 0x4E0)
        SCHEMA_FIELD(float                           , m_fNoiseStrength                                , 0x4E4)
        SCHEMA_FIELD(::Color                         , m_TintColor                                     , 0x4E8)
        SCHEMA_FIELD(bool                            , m_bOverrideTintColor                            , 0x4EC)
        SCHEMA_FIELD(bool                            , m_bOverrideIndirectLightStrength                , 0x4ED)
        SCHEMA_FIELD(bool                            , m_bOverrideSunLightStrength                     , 0x4EE)
        SCHEMA_FIELD(bool                            , m_bOverrideNoiseStrength                        , 0x4EF)
    };

    class CServerOnlyEntity : public CBaseEntity {
    public:
    };

    class CPointValueRemapper : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bUpdateOnClient                               , 0x4A9)
        SCHEMA_FIELD(ValueRemapperInputType_t        , m_nInputType                                    , 0x4AC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszRemapLineStartName                         , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszRemapLineEndName                           , 0x4B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hRemapLineStart                               , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hRemapLineEnd                                 , 0x4C4)
        SCHEMA_FIELD(float                           , m_flMaximumChangePerSecond                      , 0x4C8)
        SCHEMA_FIELD(float                           , m_flDisengageDistance                           , 0x4CC)
        SCHEMA_FIELD(float                           , m_flEngageDistance                              , 0x4D0)
        SCHEMA_FIELD(bool                            , m_bRequiresUseKey                               , 0x4D4)
        SCHEMA_FIELD(ValueRemapperOutputType_t       , m_nOutputType                                   , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOutputEntityName                           , 0x4E0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOutputEntity2Name                          , 0x4E8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOutputEntity3Name                          , 0x4F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOutputEntity4Name                          , 0x4F8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBaseEntity>>, m_hOutputEntities                               , 0x500)
        SCHEMA_FIELD(ValueRemapperHapticsType_t      , m_nHapticsType                                  , 0x518)
        SCHEMA_FIELD(ValueRemapperMomentumType_t     , m_nMomentumType                                 , 0x51C)
        SCHEMA_FIELD(float                           , m_flMomentumModifier                            , 0x520)
        SCHEMA_FIELD(float                           , m_flSnapValue                                   , 0x524)
        SCHEMA_FIELD(float                           , m_flCurrentMomentum                             , 0x528)
        SCHEMA_FIELD(ValueRemapperRatchetType_t      , m_nRatchetType                                  , 0x52C)
        SCHEMA_FIELD(float                           , m_flRatchetOffset                               , 0x530)
        SCHEMA_FIELD(float                           , m_flInputOffset                                 , 0x534)
        SCHEMA_FIELD(bool                            , m_bEngaged                                      , 0x538)
        SCHEMA_FIELD(bool                            , m_bFirstUpdate                                  , 0x539)
        SCHEMA_FIELD(float                           , m_flPreviousValue                               , 0x53C)
        SCHEMA_FIELD(::GameTime_t                    , m_flPreviousUpdateTickTime                      , 0x540)
        SCHEMA_FIELD(::Vector                        , m_vecPreviousTestPoint                          , 0x544)
        SCHEMA_FIELD(CHandle<CBasePlayerPawn>        , m_hUsingPlayer                                  , 0x550)
        SCHEMA_FIELD(float                           , m_flCustomOutputValue                           , 0x554)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundEngage                                , 0x558)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundDisengage                             , 0x560)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundReachedValueZero                      , 0x568)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundReachedValueOne                       , 0x570)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundMovingLoop                            , 0x578)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_Position                                      , 0x598)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_PositionDelta                                 , 0x5B8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnReachedValueZero                            , 0x5D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnReachedValueOne                             , 0x5F0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnReachedValueCustom                          , 0x608)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEngage                                      , 0x620)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDisengage                                   , 0x638)
    };

    class CAI_ChangeHintGroup : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iSearchType                                   , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strSearchName                                 , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strNewHintGroup                               , 0x4B8)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4C0)
    };

    class CInfoWorldLayer : public CBaseEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputOnEntitiesSpawned                      , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_worldName                                     , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_layerName                                     , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bWorldLayerVisible                            , 0x4D0)
        SCHEMA_FIELD(bool                            , m_bEntitiesSpawned                              , 0x4D1)
        SCHEMA_FIELD(bool                            , m_bCreateAsChildSpawnGroup                      , 0x4D2)
        SCHEMA_FIELD(std::uint32_t                   , m_hLayerSpawnGroup                              , 0x4D4)
    };

    class CPointCamera : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_FOV                                           , 0x4A8)
        SCHEMA_FIELD(float                           , m_Resolution                                    , 0x4AC)
        SCHEMA_FIELD(bool                            , m_bFogEnable                                    , 0x4B0)
        SCHEMA_FIELD(::Color                         , m_FogColor                                      , 0x4B1)
        SCHEMA_FIELD(float                           , m_flFogStart                                    , 0x4B8)
        SCHEMA_FIELD(float                           , m_flFogEnd                                      , 0x4BC)
        SCHEMA_FIELD(float                           , m_flFogMaxDensity                               , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4C4)
        SCHEMA_FIELD(bool                            , m_bUseScreenAspectRatio                         , 0x4C5)
        SCHEMA_FIELD(float                           , m_flAspectRatio                                 , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bNoSky                                        , 0x4CC)
        SCHEMA_FIELD(float                           , m_fBrightness                                   , 0x4D0)
        SCHEMA_FIELD(float                           , m_flZFar                                        , 0x4D4)
        SCHEMA_FIELD(float                           , m_flZNear                                       , 0x4D8)
        SCHEMA_FIELD(bool                            , m_bCanHLTVUse                                   , 0x4DC)
        SCHEMA_FIELD(bool                            , m_bAlignWithParent                              , 0x4DD)
        SCHEMA_FIELD(bool                            , m_bDofEnabled                                   , 0x4DE)
        SCHEMA_FIELD(float                           , m_flDofNearBlurry                               , 0x4E0)
        SCHEMA_FIELD(float                           , m_flDofNearCrisp                                , 0x4E4)
        SCHEMA_FIELD(float                           , m_flDofFarCrisp                                 , 0x4E8)
        SCHEMA_FIELD(float                           , m_flDofFarBlurry                                , 0x4EC)
        SCHEMA_FIELD(float                           , m_flDofTiltToGround                             , 0x4F0)
        SCHEMA_FIELD(float                           , m_TargetFOV                                     , 0x4F4)
        SCHEMA_FIELD(float                           , m_DegreesPerSecond                              , 0x4F8)
        SCHEMA_FIELD(bool                            , m_bIsOn                                         , 0x4FC)
        SCHEMA_FIELD(CPointCamera*                   , m_pNext                                         , 0x500)
    };

    class CBaseModelEntity : public CBaseEntity {
    public:
        using _Type0 = CUtlOrderedMap<CGlobalSymbol,int32>;
        SCHEMA_FIELD(CRenderComponent*               , m_CRenderComponent                              , 0x4A8)
        SCHEMA_FIELD(CHitboxComponent                , m_CHitboxComponent                              , 0x4B0)
        SCHEMA_FIELD(CChoreoComponent*               , m_pChoreoComponent                              , 0x4C8)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed0      , 0x4D0)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed1      , 0x4D4)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed2      , 0x4D8)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed3      , 0x4DC)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed4      , 0x4E0)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed0_PartIndex, 0x4E4)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed1_PartIndex, 0x4E8)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed2_PartIndex, 0x4EC)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed3_PartIndex, 0x4F0)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed4_PartIndex, 0x4F4)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed0_GenerateBreakpieces, 0x4F8)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed1_GenerateBreakpieces, 0x4F9)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed2_GenerateBreakpieces, 0x4FA)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed3_GenerateBreakpieces, 0x4FB)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed4_GenerateBreakpieces, 0x4FC)
        SCHEMA_FIELD(CDestructiblePartsComponent*    , m_pDestructiblePartsSystemComponent             , 0x500)
        SCHEMA_FIELD(CEntityOutputTemplate<CBaseModelEntity_OnDamageLevelChangedArgs_t>, m_OnDestructibleHitGroupDamageLevelChanged      , 0x508)
        SCHEMA_FIELD(::GameTime_t                    , m_flDissolveStartTime                           , 0x530)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnIgnite                                      , 0x538)
        SCHEMA_FIELD(RenderMode_t                    , m_nRenderMode                                   , 0x550)
        SCHEMA_FIELD(RenderFx_t                      , m_nRenderFX                                     , 0x551)
        SCHEMA_FIELD(bool                            , m_bAllowFadeInView                              , 0x552)
        SCHEMA_FIELD(::Color                         , m_clrRender                                     , 0x570)
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<EntityRenderAttribute_t>, m_vecRenderAttributes                           , 0x578)
        SCHEMA_FIELD(bool                            , m_bRenderToCubemaps                             , 0x5E0)
        SCHEMA_FIELD(bool                            , m_bNoInterpolate                                , 0x5E1)
        SCHEMA_FIELD(CCollisionProperty              , m_Collision                                     , 0x5E8)
        SCHEMA_FIELD(CGlowProperty                   , m_Glow                                          , 0x698)
        SCHEMA_FIELD(float                           , m_flGlowBackfaceMult                            , 0x6F0)
        SCHEMA_FIELD(float                           , m_fadeMinDist                                   , 0x6F4)
        SCHEMA_FIELD(float                           , m_fadeMaxDist                                   , 0x6F8)
        SCHEMA_FIELD(float                           , m_flFadeScale                                   , 0x6FC)
        SCHEMA_FIELD(float                           , m_flShadowStrength                              , 0x700)
        SCHEMA_FIELD(std::uint8_t                    , m_nObjectCulling                                , 0x704)
        SCHEMA_FIELD(_Type0                          , m_bodyGroupChoices                              , 0x708)
        SCHEMA_FIELD(CNetworkViewOffsetVector        , m_vecViewOffset                                 , 0x730)
        SCHEMA_FIELD(std::uint32_t                   , m_bvDisabledHitGroups                           , 0x760)
    };

    class CCitadelSoundOpvarSetOBB : public CBaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStackName                                  , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOperatorName                               , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOpvarName                                  , 0x4B8)
        SCHEMA_FIELD(::Vector                        , m_vDistanceInnerMins                            , 0x4C0)
        SCHEMA_FIELD(::Vector                        , m_vDistanceInnerMaxs                            , 0x4CC)
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMins                            , 0x4D8)
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMaxs                            , 0x4E4)
        SCHEMA_FIELD(std::int32_t                    , m_nAABBDirection                                , 0x4F0)
    };

    class CSoundEventParameter : public CBaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszParamName                                  , 0x4C0)
        SCHEMA_FIELD(float                           , m_flFloatValue                                  , 0x4C8)
    };

    class CVoteController : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iActiveIssueIndex                             , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_iOnlyTeamToVote                               , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_nVoteOptionCount                              , 0x4B0)
        SCHEMA_FIELD(std::int32_t                    , m_nPotentialVotes                               , 0x4C4)
        SCHEMA_FIELD(bool                            , m_bIsYesNoVote                                  , 0x4C8)
        SCHEMA_FIELD(CountdownTimer                  , m_acceptingVotesTimer                           , 0x4D0)
        SCHEMA_FIELD(CountdownTimer                  , m_executeCommandTimer                           , 0x4E8)
        SCHEMA_FIELD(CountdownTimer                  , m_resetVoteTimer                                , 0x500)
        SCHEMA_FIELD(std::int32_t                    , m_nVotesCast                                    , 0x518)
        SCHEMA_FIELD(CPlayerSlot                     , m_playerHoldingVote                             , 0x618)
        SCHEMA_FIELD(CPlayerSlot                     , m_playerOverrideForVote                         , 0x61C)
        SCHEMA_FIELD(std::int32_t                    , m_nHighestCountIndex                            , 0x620)
        SCHEMA_FIELD(CUtlVector<CBaseIssue*>         , m_potentialIssues                               , 0x628)
        SCHEMA_FIELD(CUtlVector<char*>               , m_VoteOptions                                   , 0x640)
    };

    class CEnvWindController : public CBaseEntity {
    public:
        SCHEMA_FIELD(CEnvWindShared                  , m_EnvWindShared                                 , 0x4A8)
        SCHEMA_FIELD(float                           , m_fDirectionVariation                           , 0x5D8)
        SCHEMA_FIELD(float                           , m_fSpeedVariation                               , 0x5DC)
        SCHEMA_FIELD(float                           , m_fTurbulence                                   , 0x5E0)
        SCHEMA_FIELD(float                           , m_fVolumeHalfExtentXY                           , 0x5E4)
        SCHEMA_FIELD(float                           , m_fVolumeHalfExtentZ                            , 0x5E8)
        SCHEMA_FIELD(std::int32_t                    , m_nVolumeResolutionXY                           , 0x5EC)
        SCHEMA_FIELD(std::int32_t                    , m_nVolumeResolutionZ                            , 0x5F0)
        SCHEMA_FIELD(std::int32_t                    , m_nClipmapLevels                                , 0x5F4)
        SCHEMA_FIELD(bool                            , m_bIsMaster                                     , 0x5F8)
        SCHEMA_FIELD(bool                            , m_bFirstTime                                    , 0x5F9)
    };

    class CSoundOpvarSetEntity : public CBaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStackName                                  , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOperatorName                               , 0x4C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOpvarName                                  , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_nOpvarType                                    , 0x4D8)
        SCHEMA_FIELD(std::int32_t                    , m_nOpvarIndex                                   , 0x4DC)
        SCHEMA_FIELD(float                           , m_flOpvarValue                                  , 0x4E0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_OpvarValueString                              , 0x4E8)
        SCHEMA_FIELD(bool                            , m_bSetOnSpawn                                   , 0x4F0)
    };

    class CEnvBeverage : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_CanInDispenser                                , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_nBeverageType                                 , 0x4AC)
    };

    class CMapVetoPickController : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bPlayedIntroVcd                               , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bNeedToPlayFiveSecondsRemaining               , 0x4A9)
        SCHEMA_FIELD(double                          , m_dblPreMatchDraftSequenceTime                  , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bPreMatchDraftStateChanged                    , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_nDraftType                                    , 0x4D4)
        SCHEMA_FIELD(std::int32_t                    , m_nTeamWinningCoinToss                          , 0x4D8)
        SCHEMA_FIELD(std::int32_t                    , m_nTeamWithFirstChoice                          , 0x4DC)
        SCHEMA_FIELD(std::int32_t                    , m_nVoteMapIdsList                               , 0x5DC)
        SCHEMA_FIELD(std::int32_t                    , m_nAccountIDs                                   , 0x5F8)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId0                                       , 0x6F8)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId1                                       , 0x7F8)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId2                                       , 0x8F8)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId3                                       , 0x9F8)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId4                                       , 0xAF8)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId5                                       , 0xBF8)
        SCHEMA_FIELD(std::int32_t                    , m_nStartingSide0                                , 0xCF8)
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentPhase                                 , 0xDF8)
        SCHEMA_FIELD(std::int32_t                    , m_nPhaseStartTick                               , 0xDFC)
        SCHEMA_FIELD(std::int32_t                    , m_nPhaseDurationTicks                           , 0xE00)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlSymbolLarge>, m_OnMapVetoed                                   , 0xE08)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlSymbolLarge>, m_OnMapPicked                                   , 0xE28)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_OnSidesPicked                                 , 0xE48)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_OnNewPhaseStarted                             , 0xE68)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_OnLevelTransition                             , 0xE88)
    };

    class CFuncPropRespawnZone : public CBaseEntity {
    public:
    };

    class CPulseGameBlackboard : public CBaseEntity {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strGraphName                                  , 0x4B0)
        SCHEMA_FIELD(::CUtlString                    , m_strStateBlob                                  , 0x4B8)
    };

    class CPathSimple : public CBaseEntity {
    public:
        SCHEMA_FIELD(CPathQueryComponent             , m_CPathQueryComponent                           , 0x4B0)
        SCHEMA_FIELD(::CUtlString                    , m_pathString                                    , 0x5A0)
        SCHEMA_FIELD(bool                            , m_bClosedLoop                                   , 0x5A8)
    };

    class CEnvWindVolume : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4A8)
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x4AC)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x4B8)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4C4)
        SCHEMA_FIELD(std::int32_t                    , m_nShape                                        , 0x4C8)
        SCHEMA_FIELD(float                           , m_fWindSpeedMultiplier                          , 0x4CC)
        SCHEMA_FIELD(float                           , m_fWindTurbulenceMultiplier                     , 0x4D0)
        SCHEMA_FIELD(float                           , m_fWindSpeedVariationMultiplier                 , 0x4D4)
        SCHEMA_FIELD(float                           , m_fWindDirectionVariationMultiplier             , 0x4D8)
    };

    class CCSMinimapBoundary : public CBaseEntity {
    public:
    };

    class CDebugHistory : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNpcEvents                                    , 0x3E84E8)
    };

    class CSoundOpvarSetPointBase : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(CEntityHandle                   , m_hSource                                       , 0x4AC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSourceEntityName                           , 0x4C8)
        SCHEMA_FIELD(::Vector                        , m_vLastPosition                                 , 0x520)
        SCHEMA_FIELD(float                           , m_flRefreshTime                                 , 0x52C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStackName                                  , 0x530)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOperatorName                               , 0x538)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOpvarName                                  , 0x540)
        SCHEMA_FIELD(std::int32_t                    , m_iOpvarIndex                                   , 0x548)
        SCHEMA_FIELD(bool                            , m_bUseAutoCompare                               , 0x54C)
        SCHEMA_FIELD(bool                            , m_bFastRefresh                                  , 0x54D)
    };

    class CEnvCubemapFog : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flEndDistance                                 , 0x4A8)
        SCHEMA_FIELD(float                           , m_flStartDistance                               , 0x4AC)
        SCHEMA_FIELD(float                           , m_flFogFalloffExponent                          , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bHeightFogEnabled                             , 0x4B4)
        SCHEMA_FIELD(float                           , m_flFogHeightWidth                              , 0x4B8)
        SCHEMA_FIELD(float                           , m_flFogHeightEnd                                , 0x4BC)
        SCHEMA_FIELD(float                           , m_flFogHeightStart                              , 0x4C0)
        SCHEMA_FIELD(float                           , m_flFogHeightExponent                           , 0x4C4)
        SCHEMA_FIELD(float                           , m_flLODBias                                     , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4CC)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4CD)
        SCHEMA_FIELD(float                           , m_flFogMaxOpacity                               , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_nCubemapSourceType                            , 0x4D4)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSkyMaterial                                  , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSkyEntity                                  , 0x4E0)
        SCHEMA_FIELD(std::int32_t                    , m_nHeightFogType                                , 0x4E8)
        SCHEMA_FIELD(std::int32_t                    , m_nFogHeightBlendMode                           , 0x4EC)
        SCHEMA_FIELD(std::int32_t                    , m_nFogHeightCoordinateSpace                     , 0x4F0)
        SCHEMA_FIELD(std::int32_t                    , m_nDistanceFogType                              , 0x4F4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_DistanceFogCurveString                        , 0x4F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_HeightFogCurveString                          , 0x500)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hFogCubemapTexture                            , 0x598)
        SCHEMA_FIELD(bool                            , m_bHasHeightFogEnd                              , 0x5A0)
        SCHEMA_FIELD(bool                            , m_bFirstTime                                    , 0x5A1)
    };

    class CNullEntity : public CBaseEntity {
    public:
    };

    class CSkyboxReference : public CBaseEntity {
    public:
        SCHEMA_FIELD(::WorldGroupId_t                , m_worldGroupId                                  , 0x4A8)
        SCHEMA_FIELD(CHandle<CSkyCamera>             , m_hSkyCamera                                    , 0x4AC)
    };

    class CPointPulse : public CBaseEntity {
    public:
    };

    class CColorCorrection : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flFadeInDuration                              , 0x4A8)
        SCHEMA_FIELD(float                           , m_flFadeOutDuration                             , 0x4AC)
        SCHEMA_FIELD(float                           , m_flStartFadeInWeight                           , 0x4B0)
        SCHEMA_FIELD(float                           , m_flStartFadeOutWeight                          , 0x4B4)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeStartFadeIn                             , 0x4B8)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeStartFadeOut                            , 0x4BC)
        SCHEMA_FIELD(float                           , m_flMaxWeight                                   , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4C4)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4C5)
        SCHEMA_FIELD(bool                            , m_bMaster                                       , 0x4C6)
        SCHEMA_FIELD(bool                            , m_bClientSide                                   , 0x4C7)
        SCHEMA_FIELD(bool                            , m_bExclusive                                    , 0x4C8)
        SCHEMA_FIELD(float                           , m_MinFalloff                                    , 0x4CC)
        SCHEMA_FIELD(float                           , m_MaxFalloff                                    , 0x4D0)
        SCHEMA_FIELD(float                           , m_flCurWeight                                   , 0x4D4)
        SCHEMA_FIELD(char                            , m_netlookupFilename                             , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_lookupFilename                                , 0x6D8)
    };

    class CGradientFog : public CBaseEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hGradientFogTexture                           , 0x4A8)
        SCHEMA_FIELD(float                           , m_flFogStartDistance                            , 0x4B0)
        SCHEMA_FIELD(float                           , m_flFogEndDistance                              , 0x4B4)
        SCHEMA_FIELD(bool                            , m_bHeightFogEnabled                             , 0x4B8)
        SCHEMA_FIELD(float                           , m_flFogStartHeight                              , 0x4BC)
        SCHEMA_FIELD(float                           , m_flFogEndHeight                                , 0x4C0)
        SCHEMA_FIELD(float                           , m_flFarZ                                        , 0x4C4)
        SCHEMA_FIELD(float                           , m_flFogMaxOpacity                               , 0x4C8)
        SCHEMA_FIELD(float                           , m_flFogFalloffExponent                          , 0x4CC)
        SCHEMA_FIELD(float                           , m_flFogVerticalExponent                         , 0x4D0)
        SCHEMA_FIELD(::Color                         , m_fogColor                                      , 0x4D4)
        SCHEMA_FIELD(float                           , m_flFogStrength                                 , 0x4D8)
        SCHEMA_FIELD(float                           , m_flFadeTime                                    , 0x4DC)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4E0)
        SCHEMA_FIELD(bool                            , m_bIsEnabled                                    , 0x4E1)
        SCHEMA_FIELD(bool                            , m_bGradientFogNeedsTextures                     , 0x4E2)
    };

    class CSoundEventEntity : public CBaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bStartOnSpawn                                 , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bToLocalPlayer                                , 0x4A9)
        SCHEMA_FIELD(bool                            , m_bStopOnNew                                    , 0x4AA)
        SCHEMA_FIELD(bool                            , m_bSaveRestore                                  , 0x4AB)
        SCHEMA_FIELD(bool                            , m_bSavedIsPlaying                               , 0x4AC)
        SCHEMA_FIELD(float                           , m_flSavedElapsedTime                            , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSourceEntityName                           , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszAttachmentName                             , 0x4C0)
        SCHEMA_FIELD(CEntityOutputTemplate<SndOpEventGuid_t>, m_onGUIDChanged                                 , 0x4C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_onSoundFinished                               , 0x4F8)
        SCHEMA_FIELD(float                           , m_flClientCullRadius                            , 0x510)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundName                                  , 0x540)
        SCHEMA_FIELD(CEntityHandle                   , m_hSource                                       , 0x55C)
        SCHEMA_FIELD(std::int32_t                    , m_nEntityIndexSelection                         , 0x560)
    };

    class CFuncTimescale : public CBaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flDesiredTimescale                            , 0x4A8)
        SCHEMA_FIELD(float                           , m_flAcceleration                                , 0x4AC)
        SCHEMA_FIELD(float                           , m_flMinBlendRate                                , 0x4B0)
        SCHEMA_FIELD(float                           , m_flBlendDeltaMultiplier                        , 0x4B4)
        SCHEMA_FIELD(bool                            , m_isStarted                                     , 0x4B8)
    };

    class CEnvCubemap : public CBaseEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hCubemapTexture                        , 0x528)
        SCHEMA_FIELD(bool                            , m_Entity_bCustomCubemapTexture                  , 0x530)
        SCHEMA_FIELD(float                           , m_Entity_flInfluenceRadius                      , 0x534)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxProjectMins                        , 0x538)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxProjectMaxs                        , 0x544)
        SCHEMA_FIELD(bool                            , m_Entity_bMoveable                              , 0x550)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nHandshake                             , 0x554)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nEnvCubeMapArrayIndex                  , 0x558)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nPriority                              , 0x55C)
        SCHEMA_FIELD(float                           , m_Entity_flEdgeFadeDist                         , 0x560)
        SCHEMA_FIELD(::Vector                        , m_Entity_vEdgeFadeDists                         , 0x564)
        SCHEMA_FIELD(float                           , m_Entity_flDiffuseScale                         , 0x570)
        SCHEMA_FIELD(bool                            , m_Entity_bStartDisabled                         , 0x574)
        SCHEMA_FIELD(bool                            , m_Entity_bDefaultEnvMap                         , 0x575)
        SCHEMA_FIELD(bool                            , m_Entity_bDefaultSpecEnvMap                     , 0x576)
        SCHEMA_FIELD(bool                            , m_Entity_bIndoorCubeMap                         , 0x577)
        SCHEMA_FIELD(bool                            , m_Entity_bCopyDiffuseFromDefaultCubemap         , 0x578)
        SCHEMA_FIELD(bool                            , m_Entity_bEnabled                               , 0x588)
    };

    class CBasePlayerController : public CBaseEntity {
    public:
        SCHEMA_FIELD(std::uint64_t                   , m_nInButtonsWhichAreToggles                     , 0x4B0)
        SCHEMA_FIELD(std::uint32_t                   , m_nTickBase                                     , 0x4B8)
        SCHEMA_FIELD(CHandle<CBasePlayerPawn>        , m_hPawn                                         , 0x4E0)
        SCHEMA_FIELD(bool                            , m_bKnownTeamMismatch                            , 0x4E4)
        SCHEMA_FIELD(CSplitScreenSlot                , m_nSplitScreenSlot                              , 0x4E8)
        SCHEMA_FIELD(CHandle<CBasePlayerController>  , m_hSplitOwner                                   , 0x4EC)
        SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerController>>, m_hSplitScreenPlayers                           , 0x4F0)
        SCHEMA_FIELD(bool                            , m_bIsHLTV                                       , 0x508)
        SCHEMA_FIELD(PlayerConnectedState            , m_iConnected                                    , 0x50C)
        SCHEMA_FIELD(PlayerConnectedState            , m_iMostConnected                                , 0x510)
        SCHEMA_FIELD(char                            , m_iszPlayerName                                 , 0x514)
        SCHEMA_FIELD(::CUtlString                    , m_szNetworkIDString                             , 0x598)
        SCHEMA_FIELD(float                           , m_fLerpTime                                     , 0x5A0)
        SCHEMA_FIELD(bool                            , m_bLagCompensation                              , 0x5A4)
        SCHEMA_FIELD(bool                            , m_bPredict                                      , 0x5A5)
        SCHEMA_FIELD(bool                            , m_bIsLowViolence                                , 0x5AC)
        SCHEMA_FIELD(bool                            , m_bGamePaused                                   , 0x5AD)
        SCHEMA_FIELD(ChatIgnoreType_t                , m_iIgnoreGlobalChat                             , 0x6E8)
        SCHEMA_FIELD(float                           , m_flLastPlayerTalkTime                          , 0x6EC)
        SCHEMA_FIELD(float                           , m_flLastEntitySteadyState                       , 0x6F0)
        SCHEMA_FIELD(std::int32_t                    , m_nAvailableEntitySteadyState                   , 0x6F4)
        SCHEMA_FIELD(bool                            , m_bHasAnySteadyStateEnts                        , 0x6F8)
        SCHEMA_FIELD(std::uint64_t                   , m_steamID                                       , 0x708)
        SCHEMA_FIELD(bool                            , m_bNoClipEnabled                                , 0x710)
        SCHEMA_FIELD(std::uint32_t                   , m_iDesiredFOV                                   , 0x714)
    };

    class dynpitchvol_t : public dynpitchvol_base_t {
    public:
    };

    class CCSBot : public CBot {
    public:
        SCHEMA_FIELD(VectorWS                        , m_eyePosition                                   , 0x108)
        SCHEMA_FIELD(char                            , m_name                                          , 0x114)
        SCHEMA_FIELD(float                           , m_combatRange                                   , 0x154)
        SCHEMA_FIELD(bool                            , m_isRogue                                       , 0x158)
        SCHEMA_FIELD(CountdownTimer                  , m_rogueTimer                                    , 0x160)
        SCHEMA_FIELD(bool                            , m_diedLastRound                                 , 0x17C)
        SCHEMA_FIELD(float                           , m_safeTime                                      , 0x180)
        SCHEMA_FIELD(bool                            , m_wasSafe                                       , 0x184)
        SCHEMA_FIELD(bool                            , m_blindFire                                     , 0x18C)
        SCHEMA_FIELD(CountdownTimer                  , m_surpriseTimer                                 , 0x190)
        SCHEMA_FIELD(bool                            , m_bAllowActive                                  , 0x1A8)
        SCHEMA_FIELD(bool                            , m_isFollowing                                   , 0x1A9)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_leader                                        , 0x1AC)
        SCHEMA_FIELD(float                           , m_followTimestamp                               , 0x1B0)
        SCHEMA_FIELD(float                           , m_allowAutoFollowTime                           , 0x1B4)
        SCHEMA_FIELD(CountdownTimer                  , m_hurryTimer                                    , 0x1B8)
        SCHEMA_FIELD(CountdownTimer                  , m_alertTimer                                    , 0x1D0)
        SCHEMA_FIELD(CountdownTimer                  , m_sneakTimer                                    , 0x1E8)
        SCHEMA_FIELD(CountdownTimer                  , m_panicTimer                                    , 0x200)
        SCHEMA_FIELD(float                           , m_stateTimestamp                                , 0x5A8)
        SCHEMA_FIELD(bool                            , m_isAttacking                                   , 0x5AC)
        SCHEMA_FIELD(bool                            , m_isOpeningDoor                                 , 0x5AD)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_taskEntity                                    , 0x5B4)
        SCHEMA_FIELD(VectorWS                        , m_goalPosition                                  , 0x5C4)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_goalEntity                                    , 0x5D0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_avoid                                         , 0x5D4)
        SCHEMA_FIELD(float                           , m_avoidTimestamp                                , 0x5D8)
        SCHEMA_FIELD(bool                            , m_isStopping                                    , 0x5DC)
        SCHEMA_FIELD(bool                            , m_hasVisitedEnemySpawn                          , 0x5DD)
        SCHEMA_FIELD(IntervalTimer                   , m_stillTimer                                    , 0x5E0)
        SCHEMA_FIELD(bool                            , m_bEyeAnglesUnderPathFinderControl              , 0x5F0)
        SCHEMA_FIELD(std::int32_t                    , m_pathIndex                                     , 0x4EF0)
        SCHEMA_FIELD(::GameTime_t                    , m_areaEnteredTimestamp                          , 0x4EF4)
        SCHEMA_FIELD(CountdownTimer                  , m_repathTimer                                   , 0x4EF8)
        SCHEMA_FIELD(CountdownTimer                  , m_avoidFriendTimer                              , 0x4F10)
        SCHEMA_FIELD(bool                            , m_isFriendInTheWay                              , 0x4F28)
        SCHEMA_FIELD(CountdownTimer                  , m_politeTimer                                   , 0x4F30)
        SCHEMA_FIELD(bool                            , m_isWaitingBehindFriend                         , 0x4F48)
        SCHEMA_FIELD(float                           , m_pathLadderEnd                                 , 0x4F74)
        SCHEMA_FIELD(CountdownTimer                  , m_mustRunTimer                                  , 0x4FC0)
        SCHEMA_FIELD(CountdownTimer                  , m_waitTimer                                     , 0x4FD8)
        SCHEMA_FIELD(CountdownTimer                  , m_updateTravelDistanceTimer                     , 0x4FF0)
        SCHEMA_FIELD(float                           , m_playerTravelDistance                          , 0x5008)
        SCHEMA_FIELD(std::uint8_t                    , m_travelDistancePhase                           , 0x5108)
        SCHEMA_FIELD(std::uint8_t                    , m_hostageEscortCount                            , 0x52A0)
        SCHEMA_FIELD(float                           , m_hostageEscortCountTimestamp                   , 0x52A4)
        SCHEMA_FIELD(std::int32_t                    , m_desiredTeam                                   , 0x52A8)
        SCHEMA_FIELD(bool                            , m_hasJoined                                     , 0x52AC)
        SCHEMA_FIELD(bool                            , m_isWaitingForHostage                           , 0x52AD)
        SCHEMA_FIELD(CountdownTimer                  , m_inhibitWaitingForHostageTimer                 , 0x52B0)
        SCHEMA_FIELD(CountdownTimer                  , m_waitForHostageTimer                           , 0x52C8)
        SCHEMA_FIELD(::Vector                        , m_noisePosition                                 , 0x52E0)
        SCHEMA_FIELD(float                           , m_noiseTravelDistance                           , 0x52EC)
        SCHEMA_FIELD(float                           , m_noiseTimestamp                                , 0x52F0)
        SCHEMA_FIELD(CCSPlayerPawn*                  , m_noiseSource                                   , 0x52F8)
        SCHEMA_FIELD(CountdownTimer                  , m_noiseBendTimer                                , 0x5310)
        SCHEMA_FIELD(::Vector                        , m_bentNoisePosition                             , 0x5328)
        SCHEMA_FIELD(bool                            , m_bendNoisePositionValid                        , 0x5334)
        SCHEMA_FIELD(float                           , m_lookAroundStateTimestamp                      , 0x5338)
        SCHEMA_FIELD(float                           , m_lookAheadAngle                                , 0x533C)
        SCHEMA_FIELD(float                           , m_lookUpAngle                                   , 0x5340)
        SCHEMA_FIELD(float                           , m_forwardAngle                                  , 0x5344)
        SCHEMA_FIELD(float                           , m_inhibitLookAroundTimestamp                    , 0x5348)
        SCHEMA_FIELD(::Vector                        , m_lookAtSpot                                    , 0x5350)
        SCHEMA_FIELD(float                           , m_lookAtSpotDuration                            , 0x5360)
        SCHEMA_FIELD(float                           , m_lookAtSpotTimestamp                           , 0x5364)
        SCHEMA_FIELD(float                           , m_lookAtSpotAngleTolerance                      , 0x5368)
        SCHEMA_FIELD(bool                            , m_lookAtSpotClearIfClose                        , 0x536C)
        SCHEMA_FIELD(bool                            , m_lookAtSpotAttack                              , 0x536D)
        SCHEMA_FIELD(char*                           , m_lookAtDesc                                    , 0x5370)
        SCHEMA_FIELD(float                           , m_peripheralTimestamp                           , 0x5378)
        SCHEMA_FIELD(std::uint8_t                    , m_approachPointCount                            , 0x5500)
        SCHEMA_FIELD(::Vector                        , m_approachPointViewPosition                     , 0x5504)
        SCHEMA_FIELD(IntervalTimer                   , m_viewSteadyTimer                               , 0x5510)
        SCHEMA_FIELD(CountdownTimer                  , m_tossGrenadeTimer                              , 0x5528)
        SCHEMA_FIELD(CountdownTimer                  , m_isAvoidingGrenade                             , 0x5548)
        SCHEMA_FIELD(float                           , m_spotCheckTimestamp                            , 0x5568)
        SCHEMA_FIELD(std::int32_t                    , m_checkedHidingSpotCount                        , 0x5970)
        SCHEMA_FIELD(float                           , m_lookPitch                                     , 0x5974)
        SCHEMA_FIELD(float                           , m_lookPitchVel                                  , 0x5978)
        SCHEMA_FIELD(float                           , m_lookYaw                                       , 0x597C)
        SCHEMA_FIELD(float                           , m_lookYawVel                                    , 0x5980)
        SCHEMA_FIELD(::Vector                        , m_targetSpot                                    , 0x5984)
        SCHEMA_FIELD(::Vector                        , m_targetSpotVelocity                            , 0x5990)
        SCHEMA_FIELD(::Vector                        , m_targetSpotPredicted                           , 0x599C)
        SCHEMA_FIELD(::QAngle                        , m_aimError                                      , 0x59A8)
        SCHEMA_FIELD(::QAngle                        , m_aimGoal                                       , 0x59B4)
        SCHEMA_FIELD(::GameTime_t                    , m_targetSpotTime                                , 0x59C0)
        SCHEMA_FIELD(float                           , m_aimFocus                                      , 0x59C4)
        SCHEMA_FIELD(float                           , m_aimFocusInterval                              , 0x59C8)
        SCHEMA_FIELD(::GameTime_t                    , m_aimFocusNextUpdate                            , 0x59CC)
        SCHEMA_FIELD(CountdownTimer                  , m_ignoreEnemiesTimer                            , 0x59D8)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_enemy                                         , 0x59F0)
        SCHEMA_FIELD(bool                            , m_isEnemyVisible                                , 0x59F4)
        SCHEMA_FIELD(std::uint8_t                    , m_visibleEnemyParts                             , 0x59F5)
        SCHEMA_FIELD(::Vector                        , m_lastEnemyPosition                             , 0x59F8)
        SCHEMA_FIELD(float                           , m_lastSawEnemyTimestamp                         , 0x5A04)
        SCHEMA_FIELD(float                           , m_firstSawEnemyTimestamp                        , 0x5A08)
        SCHEMA_FIELD(float                           , m_currentEnemyAcquireTimestamp                  , 0x5A0C)
        SCHEMA_FIELD(float                           , m_enemyDeathTimestamp                           , 0x5A10)
        SCHEMA_FIELD(float                           , m_friendDeathTimestamp                          , 0x5A14)
        SCHEMA_FIELD(bool                            , m_isLastEnemyDead                               , 0x5A18)
        SCHEMA_FIELD(std::int32_t                    , m_nearbyEnemyCount                              , 0x5A1C)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_bomber                                        , 0x5C28)
        SCHEMA_FIELD(std::int32_t                    , m_nearbyFriendCount                             , 0x5C2C)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_closestVisibleFriend                          , 0x5C30)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_closestVisibleHumanFriend                     , 0x5C34)
        SCHEMA_FIELD(IntervalTimer                   , m_attentionInterval                             , 0x5C38)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_attacker                                      , 0x5C48)
        SCHEMA_FIELD(float                           , m_attackedTimestamp                             , 0x5C4C)
        SCHEMA_FIELD(IntervalTimer                   , m_burnedByFlamesTimer                           , 0x5C50)
        SCHEMA_FIELD(std::int32_t                    , m_lastVictimID                                  , 0x5C60)
        SCHEMA_FIELD(bool                            , m_isAimingAtEnemy                               , 0x5C64)
        SCHEMA_FIELD(bool                            , m_isRapidFiring                                 , 0x5C65)
        SCHEMA_FIELD(IntervalTimer                   , m_equipTimer                                    , 0x5C68)
        SCHEMA_FIELD(CountdownTimer                  , m_zoomTimer                                     , 0x5C78)
        SCHEMA_FIELD(::GameTime_t                    , m_fireWeaponTimestamp                           , 0x5C90)
        SCHEMA_FIELD(CountdownTimer                  , m_lookForWeaponsOnGroundTimer                   , 0x5C98)
        SCHEMA_FIELD(bool                            , m_bIsSleeping                                   , 0x5CB0)
        SCHEMA_FIELD(bool                            , m_isEnemySniperVisible                          , 0x5CB1)
        SCHEMA_FIELD(CountdownTimer                  , m_sawEnemySniperTimer                           , 0x5CB8)
        SCHEMA_FIELD(std::uint8_t                    , m_enemyQueueIndex                               , 0x5D70)
        SCHEMA_FIELD(std::uint8_t                    , m_enemyQueueCount                               , 0x5D71)
        SCHEMA_FIELD(std::uint8_t                    , m_enemyQueueAttendIndex                         , 0x5D72)
        SCHEMA_FIELD(bool                            , m_isStuck                                       , 0x5D73)
        SCHEMA_FIELD(::GameTime_t                    , m_stuckTimestamp                                , 0x5D74)
        SCHEMA_FIELD(::Vector                        , m_stuckSpot                                     , 0x5D78)
        SCHEMA_FIELD(CountdownTimer                  , m_wiggleTimer                                   , 0x5D88)
        SCHEMA_FIELD(CountdownTimer                  , m_stuckJumpTimer                                , 0x5DA0)
        SCHEMA_FIELD(::GameTime_t                    , m_nextCleanupCheckTimestamp                     , 0x5DB8)
        SCHEMA_FIELD(float                           , m_avgVel                                        , 0x5DBC)
        SCHEMA_FIELD(std::int32_t                    , m_avgVelIndex                                   , 0x5DE4)
        SCHEMA_FIELD(std::int32_t                    , m_avgVelCount                                   , 0x5DE8)
        SCHEMA_FIELD(::Vector                        , m_lastOrigin                                    , 0x5DEC)
        SCHEMA_FIELD(float                           , m_lastRadioRecievedTimestamp                    , 0x5DFC)
        SCHEMA_FIELD(float                           , m_lastRadioSentTimestamp                        , 0x5E00)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_radioSubject                                  , 0x5E04)
        SCHEMA_FIELD(::Vector                        , m_radioPosition                                 , 0x5E08)
        SCHEMA_FIELD(float                           , m_voiceEndTimestamp                             , 0x5E14)
        SCHEMA_FIELD(std::int32_t                    , m_lastValidReactionQueueFrame                   , 0x5E20)
    };

    class CBaseAnimGraphController : public CSkeletonAnimationController {
    public:
        SCHEMA_FIELD(AnimationAlgorithm_t            , m_nAnimationAlgorithm                           , 0x18)
        SCHEMA_FIELD(ExternalAnimGraphHandle_t       , m_nNextExternalGraphHandle                      , 0x1C)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CGlobalSymbol>, m_vecSecondarySkeletonSlotIDs                   , 0x20)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBaseAnimGraph>>, m_vecSecondarySkeletons                         , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nSecondarySkeletonMasterCount                 , 0x50)
        SCHEMA_FIELD(float                           , m_flSoundSyncTime                               , 0x54)
        SCHEMA_FIELD(std::uint32_t                   , m_nActiveIKChainMask                            , 0x58)
        SCHEMA_FIELD(HSequence                       , m_hSequence                                     , 0x5C)
        SCHEMA_FIELD(::GameTime_t                    , m_flSeqStartTime                                , 0x60)
        SCHEMA_FIELD(float                           , m_flSeqFixedCycle                               , 0x64)
        SCHEMA_FIELD(AnimLoopMode_t                  , m_nAnimLoopMode                                 , 0x68)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_flPlaybackRate                                , 0x6C)
        SCHEMA_FIELD(SequenceFinishNotifyState_t     , m_nNotifyState                                  , 0x78)
        SCHEMA_FIELD(bool                            , m_bNetworkedAnimationInputsChanged              , 0x79)
        SCHEMA_FIELD(bool                            , m_bNetworkedSequenceChanged                     , 0x7A)
        SCHEMA_FIELD(bool                            , m_bLastUpdateSkipped                            , 0x7B)
        SCHEMA_FIELD(bool                            , m_bSequenceFinished                             , 0x7C)
        SCHEMA_FIELD(::GameTick_t                    , m_nPrevAnimUpdateTick                           , 0x80)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCNmGraphDefinition>, m_hGraphDefinitionAG2                           , 0x320)
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<AnimGraph2SerializedPoseRecipeSlot_t>, m_SerializePoseRecipeAG2Slots                   , 0x328)
        SCHEMA_FIELD(CNetworkUtlVectorBase<uint8>    , m_SerializePoseRecipeAG2Dynamic                 , 0x390)
        SCHEMA_FIELD(std::uint32_t                   , m_nSerializePoseRecipeAG2ActiveSlot             , 0x3A8)
        SCHEMA_FIELD(std::int32_t                    , m_nSerializePoseRecipeVersionAG2                , 0x3AC)
        SCHEMA_FIELD(std::int32_t                    , m_nServerGraphInstanceIteration                 , 0x3C0)
        SCHEMA_FIELD(std::int32_t                    , m_nServerSerializationContextIteration          , 0x3C4)
        SCHEMA_FIELD(ResourceId_t                    , m_primaryGraphId                                , 0x3C8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<ResourceId_t>, m_vecExternalGraphIds                           , 0x3D0)
        SCHEMA_FIELD(CNetworkUtlVectorBase<ResourceId_t>, m_vecExternalClipIds                            , 0x3E8)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sAnimGraph2Identifier                         , 0x400)
        SCHEMA_FIELD(CNmGraphInstance*               , m_pGraphInstanceAG2                             , 0x408)
        SCHEMA_FIELD(CUtlVector<ExternalAnimGraph_t> , m_vecExternalGraphs                             , 0x620)
    };

    class CStopwatch : public CStopwatchBase {
    public:
        SCHEMA_FIELD(float                           , m_flInterval                                    , 0xC)
    };

    class CRandStopwatch : public CStopwatchBase {
    public:
        SCHEMA_FIELD(float                           , m_flMinInterval                                 , 0xC)
        SCHEMA_FIELD(float                           , m_flMaxInterval                                 , 0x10)
    };

    class CBodyComponentPoint : public CBodyComponent {
    public:
        SCHEMA_FIELD(CGameSceneNode                  , m_sceneNode                                     , 0x80)
    };

    class CBodyComponentSkeletonInstance : public CBodyComponent {
    public:
        SCHEMA_FIELD(CSkeletonInstance               , m_skeletonInstance                              , 0x80)
    };

    class CCSPlayer_ItemServices : public CPlayer_ItemServices {
    public:
        SCHEMA_FIELD(bool                            , m_bHasDefuser                                   , 0x48)
        SCHEMA_FIELD(bool                            , m_bHasHelmet                                    , 0x49)
    };

    class CPlayer_MovementServices_Humanoid : public CPlayer_MovementServices {
    public:
        SCHEMA_FIELD(float                           , m_flStepSoundTime                               , 0x258)
        SCHEMA_FIELD(float                           , m_flFallVelocity                                , 0x25C)
        SCHEMA_FIELD(::Vector                        , m_groundNormal                                  , 0x260)
        SCHEMA_FIELD(float                           , m_flSurfaceFriction                             , 0x26C)
        SCHEMA_FIELD(CUtlStringToken                 , m_surfaceProps                                  , 0x270)
        SCHEMA_FIELD(std::int32_t                    , m_nStepside                                     , 0x280)
        SCHEMA_FIELD(::Vector                        , m_vecSmoothedVelocity                           , 0x284)
    };

    class CCSObserver_MovementServices : public CPlayer_MovementServices {
    public:
    };

    class CCSObserver_ObserverServices : public CPlayer_ObserverServices {
    public:
    };

    class CCSPlayerBase_CameraServices : public CPlayer_CameraServices {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_iFOV                                          , 0x178)
        SCHEMA_FIELD(std::uint32_t                   , m_iFOVStart                                     , 0x17C)
        SCHEMA_FIELD(::GameTime_t                    , m_flFOVTime                                     , 0x180)
        SCHEMA_FIELD(float                           , m_flFOVRate                                     , 0x184)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hZoomOwner                                    , 0x188)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hTriggerFogList                               , 0x190)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLastFogTrigger                               , 0x1A8)
    };

    class CCSPlayer_WaterServices : public CPlayer_WaterServices {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_NextDrownDamageTime                           , 0x48)
        SCHEMA_FIELD(std::int32_t                    , m_nDrownDmgRate                                 , 0x4C)
        SCHEMA_FIELD(::GameTime_t                    , m_AirFinishedTime                               , 0x50)
        SCHEMA_FIELD(float                           , m_flWaterJumpTime                               , 0x54)
        SCHEMA_FIELD(::Vector                        , m_vecWaterJumpVel                               , 0x58)
        SCHEMA_FIELD(float                           , m_flSwimSoundTime                               , 0x64)
    };

    class CCSObserver_UseServices : public CPlayer_UseServices {
    public:
    };

    class CCSPlayer_UseServices : public CPlayer_UseServices {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLastKnownUseEntity                           , 0x48)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastUseTimeStamp                            , 0x4C)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeLastUsedWindow                          , 0x50)
    };

    class CCSPlayer_WeaponServices : public CPlayer_WeaponServices {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flNextAttack                                  , 0xC0)
        SCHEMA_FIELD(CHandle<CBasePlayerWeapon>      , m_hSavedWeapon                                  , 0xC4)
        SCHEMA_FIELD(std::int32_t                    , m_nTimeToMelee                                  , 0xC8)
        SCHEMA_FIELD(std::int32_t                    , m_nTimeToSecondary                              , 0xCC)
        SCHEMA_FIELD(std::int32_t                    , m_nTimeToPrimary                                , 0xD0)
        SCHEMA_FIELD(std::int32_t                    , m_nTimeToSniperRifle                            , 0xD4)
        SCHEMA_FIELD(bool                            , m_bIsBeingGivenItem                             , 0xD8)
        SCHEMA_FIELD(bool                            , m_bIsPickingUpItemWithUse                       , 0xD9)
        SCHEMA_FIELD(bool                            , m_bPickedUpWeapon                               , 0xDA)
        SCHEMA_FIELD(bool                            , m_bDisableAutoDeploy                            , 0xDB)
        SCHEMA_FIELD(bool                            , m_bIsPickingUpGroundWeapon                      , 0xDC)
        SCHEMA_FIELD(CNetworkUtlVectorBase<uint8>    , m_networkAnimTiming                             , 0x1860)
        SCHEMA_FIELD(bool                            , m_bBlockInspectUntilNextGraphUpdate             , 0x1878)
    };

    class CAmbientGeneric : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_radius                                        , 0x4A8)
        SCHEMA_FIELD(float                           , m_flMaxRadius                                   , 0x4AC)
        SCHEMA_FIELD(soundlevel_t                    , m_iSoundLevel                                   , 0x4B0)
        SCHEMA_FIELD(dynpitchvol_t                   , m_dpv                                           , 0x4B4)
        SCHEMA_FIELD(bool                            , m_fActive                                       , 0x518)
        SCHEMA_FIELD(bool                            , m_fLooping                                      , 0x519)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSound                                      , 0x520)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sSourceEntName                                , 0x528)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hSoundSource                                  , 0x530)
        SCHEMA_FIELD(CEntityIndex                    , m_nSoundSourceEntIndex                          , 0x534)
    };

    class CEnvEntityMaker : public CPointEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecEntityMins                                 , 0x4A8)
        SCHEMA_FIELD(::Vector                        , m_vecEntityMaxs                                 , 0x4B4)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hCurrentInstance                              , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hCurrentBlocker                               , 0x4C4)
        SCHEMA_FIELD(::Vector                        , m_vecBlockerOrigin                              , 0x4C8)
        SCHEMA_FIELD(::QAngle                        , m_angPostSpawnDirection                         , 0x4D4)
        SCHEMA_FIELD(float                           , m_flPostSpawnDirectionVariance                  , 0x4E0)
        SCHEMA_FIELD(float                           , m_flPostSpawnSpeed                              , 0x4E4)
        SCHEMA_FIELD(bool                            , m_bPostSpawnUseAngles                           , 0x4E8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTemplate                                   , 0x4F0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputOnSpawned                              , 0x4F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputOnFailedSpawn                          , 0x510)
    };

    class CInfoTeleportDestination : public CPointEntity {
    public:
    };

    class CPointBroadcastClientCommand : public CPointEntity {
    public:
    };

    class CEnvMuzzleFlash : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszParentAttachment                           , 0x4B0)
    };

    class CPathTrack : public CPointEntity {
    public:
        SCHEMA_FIELD(CHandle<CPathTrack>             , m_pnext                                         , 0x4A8)
        SCHEMA_FIELD(CHandle<CPathTrack>             , m_pprevious                                     , 0x4AC)
        SCHEMA_FIELD(CHandle<CPathTrack>             , m_paltpath                                      , 0x4B0)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4B4)
        SCHEMA_FIELD(float                           , m_length                                        , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_altName                                       , 0x4C0)
        SCHEMA_FIELD(std::int32_t                    , m_nIterVal                                      , 0x4C8)
        SCHEMA_FIELD(TrackOrientationType_t          , m_eOrientationType                              , 0x4CC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPass                                        , 0x4D0)
    };

    class CTankTrainAI : public CPointEntity {
    public:
        SCHEMA_FIELD(CHandle<CFuncTrackTrain>        , m_hTrain                                        , 0x4A8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetEntity                                 , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_soundPlaying                                  , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_startSoundName                                , 0x4C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_engineSoundName                               , 0x4D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_movementSoundName                             , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_targetEntityName                              , 0x4E0)
    };

    class CInfoGameEventProxy : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEventName                                  , 0x4A8)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x4B0)
    };

    class CInfoFan : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_fFanForceMaxRadius                            , 0x4E8)
        SCHEMA_FIELD(float                           , m_fFanForceMinRadius                            , 0x4EC)
        SCHEMA_FIELD(float                           , m_flCurveDistRange                              , 0x4F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_FanForceCurveString                           , 0x4F8)
    };

    class CEnvSplash : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x4A8)
    };

    class CPointPush : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4A8)
        SCHEMA_FIELD(float                           , m_flMagnitude                                   , 0x4AC)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4B0)
        SCHEMA_FIELD(float                           , m_flInnerRadius                                 , 0x4B4)
        SCHEMA_FIELD(float                           , m_flConeOfInfluence                             , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszFilterName                                 , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseFilter>            , m_hFilter                                       , 0x4C8)
    };

    class CPointChildModifier : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bOrphanInsteadOfDeletingChildrenOnRemove      , 0x4A8)
    };

    class CCredits : public CPointEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCreditsDone                                 , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bRolledOutroCredits                           , 0x4C0)
        SCHEMA_FIELD(float                           , m_flLogoLength                                  , 0x4C4)
    };

    class CPointServerCommand : public CPointEntity {
    public:
    };

    class CTankTargetChange : public CPointEntity {
    public:
        SCHEMA_FIELD(CVariantBase<CVariantDefaultAllocator>, m_newTarget                                     , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_newTargetName                                 , 0x4B8)
    };

    class CEnvInstructorHint : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszName                                       , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszReplace_Key                                , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszHintTargetEntity                           , 0x4B8)
        SCHEMA_FIELD(std::int32_t                    , m_iTimeout                                      , 0x4C0)
        SCHEMA_FIELD(std::int32_t                    , m_iDisplayLimit                                 , 0x4C4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszIcon_Onscreen                              , 0x4C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszIcon_Offscreen                             , 0x4D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszCaption                                    , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszActivatorCaption                           , 0x4E0)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0x4E8)
        SCHEMA_FIELD(float                           , m_fIconOffset                                   , 0x4EC)
        SCHEMA_FIELD(float                           , m_fRange                                        , 0x4F0)
        SCHEMA_FIELD(std::uint8_t                    , m_iPulseOption                                  , 0x4F4)
        SCHEMA_FIELD(std::uint8_t                    , m_iAlphaOption                                  , 0x4F5)
        SCHEMA_FIELD(std::uint8_t                    , m_iShakeOption                                  , 0x4F6)
        SCHEMA_FIELD(bool                            , m_bStatic                                       , 0x4F7)
        SCHEMA_FIELD(bool                            , m_bNoOffscreen                                  , 0x4F8)
        SCHEMA_FIELD(bool                            , m_bForceCaption                                 , 0x4F9)
        SCHEMA_FIELD(std::int32_t                    , m_iInstanceType                                 , 0x4FC)
        SCHEMA_FIELD(bool                            , m_bSuppressRest                                 , 0x500)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszBinding                                    , 0x508)
        SCHEMA_FIELD(bool                            , m_bAllowNoDrawTarget                            , 0x510)
        SCHEMA_FIELD(bool                            , m_bAutoStart                                    , 0x511)
        SCHEMA_FIELD(bool                            , m_bLocalPlayerOnly                              , 0x512)
    };

    class CLogicScript : public CPointEntity {
    public:
    };

    class CPointProximitySensor : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetEntity                                 , 0x4AC)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_Distance                                      , 0x4B0)
    };

    class CInfoDynamicShadowHint : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_nImportance                                   , 0x4B0)
        SCHEMA_FIELD(std::int32_t                    , m_nLightChoice                                  , 0x4B4)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLight                                        , 0x4B8)
    };

    class CPathNode : public CPointEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vInTangentLocal                               , 0x4A8)
        SCHEMA_FIELD(::Vector                        , m_vOutTangentLocal                              , 0x4B4)
        SCHEMA_FIELD(::CUtlString                    , m_strParentPathUniqueID                         , 0x4C0)
        SCHEMA_FIELD(::CUtlString                    , m_strPathNodeParameter                          , 0x4C8)
        SCHEMA_FIELD(CTransform                      , m_xWSPrevParent                                 , 0x4D0)
        SCHEMA_FIELD(CHandle<CPathWithDynamicNodes>  , m_hPath                                         , 0x4F0)
    };

    class CEnvInstructorVRHint : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszName                                       , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszHintTargetEntity                           , 0x4B0)
        SCHEMA_FIELD(std::int32_t                    , m_iTimeout                                      , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszCaption                                    , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStartSound                                 , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_iLayoutFileType                               , 0x4D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszCustomLayoutFile                           , 0x4D8)
        SCHEMA_FIELD(std::int32_t                    , m_iAttachType                                   , 0x4E0)
        SCHEMA_FIELD(float                           , m_flHeightOffset                                , 0x4E4)
    };

    class CSceneEntity : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSceneFile                                  , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget1                                    , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget2                                    , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget3                                    , 0x4C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget4                                    , 0x4D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget5                                    , 0x4D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget6                                    , 0x4E0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget7                                    , 0x4E8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTarget8                                    , 0x4F0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget1                                      , 0x4F8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget2                                      , 0x4FC)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget3                                      , 0x500)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget4                                      , 0x504)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget5                                      , 0x508)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget6                                      , 0x50C)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget7                                      , 0x510)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget8                                      , 0x514)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLocatorOrigin                                , 0x518)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sTargetAttachment                             , 0x520)
        SCHEMA_FIELD(bool                            , m_bIsPlayingBack                                , 0x528)
        SCHEMA_FIELD(bool                            , m_bPaused                                       , 0x529)
        SCHEMA_FIELD(bool                            , m_bMultiplayer                                  , 0x52A)
        SCHEMA_FIELD(bool                            , m_bAutogenerated                                , 0x52B)
        SCHEMA_FIELD(bool                            , m_bAllRequirementsComplete                      , 0x52C)
        SCHEMA_FIELD(float                           , m_flForceClientTime                             , 0x530)
        SCHEMA_FIELD(float                           , m_flCurrentTime                                 , 0x534)
        SCHEMA_FIELD(float                           , m_flFrameTime                                   , 0x538)
        SCHEMA_FIELD(bool                            , m_bCancelAtNextInterrupt                        , 0x53C)
        SCHEMA_FIELD(float                           , m_fPitch                                        , 0x540)
        SCHEMA_FIELD(bool                            , m_bAutomated                                    , 0x544)
        SCHEMA_FIELD(std::int32_t                    , m_nAutomatedAction                              , 0x548)
        SCHEMA_FIELD(float                           , m_flAutomationDelay                             , 0x54C)
        SCHEMA_FIELD(float                           , m_flAutomationTime                              , 0x550)
        SCHEMA_FIELD(std::int32_t                    , m_nSpeechPriority                               , 0x554)
        SCHEMA_FIELD(bool                            , m_bPausedViaInput                               , 0x558)
        SCHEMA_FIELD(bool                            , m_bPauseAtNextInterrupt                         , 0x559)
        SCHEMA_FIELD(bool                            , m_bWaitingForActor                              , 0x55A)
        SCHEMA_FIELD(bool                            , m_bWaitingForInterrupt                          , 0x55B)
        SCHEMA_FIELD(bool                            , m_bInterruptedActorsScenes                      , 0x55C)
        SCHEMA_FIELD(bool                            , m_bTakeOverNPCBehavior                          , 0x55D)
        SCHEMA_FIELD(bool                            , m_bBreakOnNonIdle                               , 0x55E)
        SCHEMA_FIELD(bool                            , m_bSceneFinished                                , 0x55F)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBaseModelEntity>>, m_hActorList                                    , 0x560)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hRemoveActorList                              , 0x578)
        SCHEMA_FIELD(std::uint16_t                   , m_nSceneStringIndex                             , 0x5C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStart                                       , 0x5C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCompletion                                  , 0x5E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCanceled                                    , 0x5F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPaused                                      , 0x610)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnResumed                                     , 0x628)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPulseRequirement                            , 0x640)
        SCHEMA_FIELD(CHandle<CSceneEntity>           , m_hInterruptScene                               , 0x758)
        SCHEMA_FIELD(std::int32_t                    , m_nInterruptCount                               , 0x75C)
        SCHEMA_FIELD(bool                            , m_bSceneMissing                                 , 0x760)
        SCHEMA_FIELD(bool                            , m_bInterrupted                                  , 0x761)
        SCHEMA_FIELD(bool                            , m_bCompletedEarly                               , 0x762)
        SCHEMA_FIELD(bool                            , m_bInterruptSceneFinished                       , 0x763)
        SCHEMA_FIELD(bool                            , m_bRestoring                                    , 0x764)
        SCHEMA_FIELD(CUtlVector<CHandle<CSceneEntity>>, m_hNotifySceneCompletion                        , 0x768)
        SCHEMA_FIELD(CUtlVector<CHandle<CSceneListManager>>, m_hListManagers                                 , 0x780)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundName                                  , 0x798)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSequenceName                               , 0x7A0)
        SCHEMA_FIELD(CHandle<CBaseModelEntity>       , m_hActor                                        , 0x7A8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hActivator                                    , 0x7AC)
        SCHEMA_FIELD(std::int32_t                    , m_BusyActor                                     , 0x7B0)
        SCHEMA_FIELD(SceneOnPlayerDeath_t            , m_iPlayerDeathBehavior                          , 0x7B4)
    };

    class CChoreoInfoTarget : public CPointEntity {
    public:
    };

    class CInfoPlayerStart : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bIsMaster                                     , 0x4A9)
        SCHEMA_FIELD(CGlobalSymbol                   , m_pPawnSubclass                                 , 0x4B0)
    };

    class CMessageEntity : public CPointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_radius                                        , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_messageText                                   , 0x4B0)
        SCHEMA_FIELD(bool                            , m_drawText                                      , 0x4B8)
        SCHEMA_FIELD(bool                            , m_bDeveloperOnly                                , 0x4B9)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4BA)
    };

    class CInfoOffscreenPanoramaTexture : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_nResolutionX                                  , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_nResolutionY                                  , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szPanelType                                   , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szLayoutFileName                              , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_RenderAttrName                                , 0x4C8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBaseModelEntity>>, m_TargetEntities                                , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_nTargetChangeCount                            , 0x4E8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CUtlSymbolLarge>, m_vecCSSClasses                                 , 0x4F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szTargetsName                                 , 0x508)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseModelEntity>>, m_AdditionalTargetEntities                      , 0x510)
    };

    class CPointAngularVelocitySensor : public CPointEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetEntity                                 , 0x4A8)
        SCHEMA_FIELD(float                           , m_flThreshold                                   , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_nLastCompareResult                            , 0x4B0)
        SCHEMA_FIELD(std::int32_t                    , m_nLastFireResult                               , 0x4B4)
        SCHEMA_FIELD(::GameTime_t                    , m_flFireTime                                    , 0x4B8)
        SCHEMA_FIELD(float                           , m_flFireInterval                                , 0x4BC)
        SCHEMA_FIELD(float                           , m_flLastAngVelocity                             , 0x4C0)
        SCHEMA_FIELD(::QAngle                        , m_lastOrientation                               , 0x4C4)
        SCHEMA_FIELD(VectorWS                        , m_vecAxis                                       , 0x4D0)
        SCHEMA_FIELD(bool                            , m_bUseHelper                                    , 0x4DC)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_AngularVelocity                               , 0x4E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLessThan                                    , 0x500)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLessThanOrEqualTo                           , 0x518)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnGreaterThan                                 , 0x530)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnGreaterThanOrEqualTo                        , 0x548)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEqualTo                                     , 0x560)
    };

    class CPhysForce : public CPointEntity {
    public:
        SCHEMA_FIELD(IPhysicsMotionController*       , m_pController                                   , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttach                                    , 0x4B0)
        SCHEMA_FIELD(float                           , m_force                                         , 0x4B8)
        SCHEMA_FIELD(float                           , m_forceTime                                     , 0x4BC)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_attachedObject                                , 0x4C0)
        SCHEMA_FIELD(bool                            , m_wasRestored                                   , 0x4C4)
        SCHEMA_FIELD(CConstantForceController        , m_integrator                                    , 0x4C8)
    };

    class CInfoTarget : public CPointEntity {
    public:
    };

    class CKeepUpright : public CPointEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_worldGoalAxis                                 , 0x4B0)
        SCHEMA_FIELD(::Vector                        , m_localTestAxis                                 , 0x4BC)
        SCHEMA_FIELD(IPhysicsMotionController*       , m_pController                                   , 0x4C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttach                                    , 0x4D0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_attachedObject                                , 0x4D8)
        SCHEMA_FIELD(float                           , m_angularLimit                                  , 0x4DC)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x4E0)
        SCHEMA_FIELD(bool                            , m_bDampAllRotation                              , 0x4E1)
    };

    class CEnvShake : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_limitToEntity                                 , 0x4A8)
        SCHEMA_FIELD(float                           , m_Amplitude                                     , 0x4B0)
        SCHEMA_FIELD(float                           , m_Frequency                                     , 0x4B4)
        SCHEMA_FIELD(float                           , m_Duration                                      , 0x4B8)
        SCHEMA_FIELD(float                           , m_Radius                                        , 0x4BC)
        SCHEMA_FIELD(::GameTime_t                    , m_stopTime                                      , 0x4C0)
        SCHEMA_FIELD(::GameTime_t                    , m_nextShake                                     , 0x4C4)
        SCHEMA_FIELD(float                           , m_currentAmp                                    , 0x4C8)
        SCHEMA_FIELD(::Vector                        , m_maxForce                                      , 0x4CC)
        SCHEMA_FIELD(IPhysicsMotionController*       , m_pShakeController                              , 0x4D8)
        SCHEMA_FIELD(CPhysicsShake                   , m_shakeCallback                                 , 0x4E0)
    };

    class CRotatorTarget : public CPointEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnArrivedAt                                   , 0x4A8)
        SCHEMA_FIELD(RotatorTargetSpace_t            , m_eSpace                                        , 0x4C0)
    };

    class CInfoInstructorHintHostageRescueZone : public CPointEntity {
    public:
    };

    class CMessage : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszMessage                                    , 0x4A8)
        SCHEMA_FIELD(float                           , m_MessageVolume                                 , 0x4B0)
        SCHEMA_FIELD(std::int32_t                    , m_MessageAttenuation                            , 0x4B4)
        SCHEMA_FIELD(float                           , m_Radius                                        , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sNoise                                        , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnShowMessage                                 , 0x4C8)
    };

    class CPointVelocitySensor : public CPointEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetEntity                                 , 0x4A8)
        SCHEMA_FIELD(::Vector                        , m_vecAxis                                       , 0x4AC)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4B8)
        SCHEMA_FIELD(float                           , m_fPrevVelocity                                 , 0x4BC)
        SCHEMA_FIELD(float                           , m_flAvgInterval                                 , 0x4C0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_Velocity                                      , 0x4C8)
    };

    class CEnvSpark : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_flDelay                                       , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_nMagnitude                                    , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_nTrailLength                                  , 0x4B0)
        SCHEMA_FIELD(std::int32_t                    , m_nType                                         , 0x4B4)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnSpark                                       , 0x4B8)
    };

    class CPointClientCommand : public CPointEntity {
    public:
    };

    class CInfoChoreoAnchor : public CPointEntity {
    public:
        SCHEMA_FIELD(CUtlVector<CInfoChoreoAnchorPosition>, m_vecTargetEntries                              , 0x4A8)
        SCHEMA_FIELD(CUtlVector<CInfoChoreoAnchorPosition>, m_vecTargetWarps                                , 0x4C0)
    };

    class CLogicProximity : public CPointEntity {
    public:
    };

    class CPointGiveAmmo : public CPointEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_pActivator                                    , 0x4A8)
    };

    class CBaseDMStart : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_Master                                        , 0x4A8)
    };

    class CEnvViewPunch : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4A8)
        SCHEMA_FIELD(::QAngle                        , m_angViewPunch                                  , 0x4AC)
    };

    class CNavWalkable : public CPointEntity {
    public:
    };

    class CPhysImpact : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_damage                                        , 0x4A8)
        SCHEMA_FIELD(float                           , m_distance                                      , 0x4AC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_directionEntityName                           , 0x4B0)
    };

    class CRagdollMagnet : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(float                           , m_radius                                        , 0x4AC)
        SCHEMA_FIELD(float                           , m_force                                         , 0x4B0)
        SCHEMA_FIELD(VectorWS                        , m_axis                                          , 0x4B4)
    };

    class CInfoInstructorHintTarget : public CPointEntity {
    public:
    };

    class CInfoSpawnGroupLandmark : public CPointEntity {
    public:
    };

    class CPointAngleSensor : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nLookAtName                                   , 0x4B0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetEntity                                 , 0x4B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLookAtEntity                                 , 0x4BC)
        SCHEMA_FIELD(float                           , m_flDuration                                    , 0x4C0)
        SCHEMA_FIELD(float                           , m_flDotTolerance                                , 0x4C4)
        SCHEMA_FIELD(::GameTime_t                    , m_flFacingTime                                  , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bFired                                        , 0x4CC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFacingLookat                                , 0x4D0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnNotFacingLookat                             , 0x4E8)
        SCHEMA_FIELD(CEntityOutputTemplate<Vector>   , m_TargetDir                                     , 0x500)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_FacingPercentage                              , 0x528)
    };

    class CPhysExplosion : public CPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bExplodeOnSpawn                               , 0x4A8)
        SCHEMA_FIELD(float                           , m_flMagnitude                                   , 0x4AC)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0x4B0)
        SCHEMA_FIELD(float                           , m_radius                                        , 0x4B4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_targetEntityName                              , 0x4B8)
        SCHEMA_FIELD(float                           , m_flInnerRadius                                 , 0x4C0)
        SCHEMA_FIELD(float                           , m_flPushScale                                   , 0x4C4)
        SCHEMA_FIELD(bool                            , m_bConvertToDebrisWhenPossible                  , 0x4C8)
        SCHEMA_FIELD(bool                            , m_bAffectInvulnerableEnts                       , 0x4C9)
        SCHEMA_FIELD(bool                            , m_bDisablePushClamp                             , 0x4CA)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPushedPlayer                                , 0x4D0)
    };

    class CNavSpaceInfo : public CPointEntity {
    public:
    };

    class CPointGamestatsCounter : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strStatisticName                              , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4B0)
    };

    class CInfoInstructorHintBombTargetA : public CPointEntity {
    public:
    };

    class CBlood : public CPointEntity {
    public:
        SCHEMA_FIELD(::QAngle                        , m_vecSprayAngles                                , 0x4A8)
        SCHEMA_FIELD(::Vector                        , m_vecSprayDir                                   , 0x4B4)
        SCHEMA_FIELD(float                           , m_flAmount                                      , 0x4C0)
        SCHEMA_FIELD(BloodType                       , m_Color                                         , 0x4C4)
    };

    class CEnvHudHint : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszMessage                                    , 0x4A8)
    };

    class CInstructorEventEntity : public CPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszName                                       , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszHintTargetEntity                           , 0x4B0)
        SCHEMA_FIELD(CHandle<CBasePlayerPawn>        , m_hTargetPlayer                                 , 0x4B8)
    };

    class CPathCorner : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_flWait                                        , 0x4A8)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4AC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPass                                        , 0x4B0)
    };

    class CEnvTilt : public CPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_Duration                                      , 0x4A8)
        SCHEMA_FIELD(float                           , m_Radius                                        , 0x4AC)
        SCHEMA_FIELD(float                           , m_TiltTime                                      , 0x4B0)
        SCHEMA_FIELD(::GameTime_t                    , m_stopTime                                      , 0x4B4)
    };

    class CInfoLandmark : public CPointEntity {
    public:
    };

    class CMapInfo : public CPointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iBuyingStatus                                 , 0x4A8)
        SCHEMA_FIELD(float                           , m_flBombRadius                                  , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_iPetPopulation                                , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bUseNormalSpawnsForDM                         , 0x4B4)
        SCHEMA_FIELD(bool                            , m_bDisableAutoGeneratedDMSpawns                 , 0x4B5)
        SCHEMA_FIELD(float                           , m_flBotMaxVisionDistance                        , 0x4B8)
        SCHEMA_FIELD(std::int32_t                    , m_iHostageCount                                 , 0x4BC)
        SCHEMA_FIELD(bool                            , m_bFadePlayerVisibilityFarZ                     , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bRainTraceToSkyEnabled                        , 0x4C1)
        SCHEMA_FIELD(bool                            , m_bGPUCullSkybox                                , 0x4C2)
        SCHEMA_FIELD(float                           , m_flEnvRainStrength                             , 0x4C4)
        SCHEMA_FIELD(float                           , m_flEnvPuddleRippleStrength                     , 0x4C8)
        SCHEMA_FIELD(float                           , m_flEnvPuddleRippleDirection                    , 0x4CC)
        SCHEMA_FIELD(float                           , m_flEnvWetnessCoverage                          , 0x4D0)
        SCHEMA_FIELD(float                           , m_flEnvWetnessDryingAmount                      , 0x4D4)
    };

    class CInfoInstructorHintBombTargetB : public CPointEntity {
    public:
    };

    class CInfoInteraction : public CPointEntity {
    public:
        SCHEMA_FIELD(SceneRequestHandle_t            , m_hSceneRequest                                 , 0x4A8)
        SCHEMA_FIELD(SceneOpportunityHandle_t        , m_hSceneOpportunity                             , 0x4AC)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4B1)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strSceneVDataName                             , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strPulseVDataName                             , 0x4C0)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4E8)
        SCHEMA_FIELD(float                           , m_flOwnerFOV                                    , 0x4EC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strLocalInterestReqTags                       , 0x4F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strLocalInterestOptTags                       , 0x4F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strLookTarget                                 , 0x500)
        SCHEMA_FIELD(float                           , m_flDuration                                    , 0x508)
        SCHEMA_FIELD(float                           , m_flCooldown                                    , 0x50C)
        SCHEMA_FIELD(std::int32_t                    , m_nRepeatCount                                  , 0x510)
        SCHEMA_FIELD(bool                            , m_bDisableOnExit                                , 0x514)
    };

    class CInfoParticleTarget : public CPointEntity {
    public:
    };

    class CPointHurt : public CPointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nDamage                                       , 0x4A8)
        SCHEMA_FIELD(DamageTypes_t                   , m_bitsDamageType                                , 0x4AC)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4B0)
        SCHEMA_FIELD(float                           , m_flDelay                                       , 0x4B4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strTarget                                     , 0x4B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_pActivator                                    , 0x4C0)
    };

    class CCSGO_EndOfMatchLineupEnd : public CCSGO_EndOfMatchLineupEndpoint {
    public:
    };

    class CCSGO_EndOfMatchLineupStart : public CCSGO_EndOfMatchLineupEndpoint {
    public:
    };

    class CLogicNPCCounterAABB : public CLogicNPCCounter {
    public:
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMins                            , 0x728)
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMaxs                            , 0x734)
        SCHEMA_FIELD(::Vector                        , m_vOuterMins                                    , 0x740)
        SCHEMA_FIELD(::Vector                        , m_vOuterMaxs                                    , 0x74C)
    };

    class CPathParticleRopeAlias_path_particle_rope_clientside : public CPathParticleRope {
    public:
    };

    class CEnvSoundscapeAlias_snd_soundscape : public CEnvSoundscape {
    public:
    };

    class CEnvSoundscapeProxy : public CEnvSoundscape {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_MainSoundscapeName                            , 0x538)
    };

    class CEnvSoundscapeTriggerable : public CEnvSoundscape {
    public:
    };

    class CSoundAreaEntitySphere : public CSoundAreaEntityBase {
    public:
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4C8)
    };

    class CSoundAreaEntityOrientedBox : public CSoundAreaEntityBase {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMin                                          , 0x4C8)
        SCHEMA_FIELD(::Vector                        , m_vMax                                          , 0x4D4)
    };

    class CEnvCombinedLightProbeVolumeAlias_func_combined_light_probe_volume : public CEnvCombinedLightProbeVolume {
    public:
    };

    class CTonemapController2Alias_env_tonemap_controller2 : public CTonemapController2 {
    public:
    };

    class CCSTeam : public CTeam {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nLastRecievedShorthandedRoundBonus            , 0x560)
        SCHEMA_FIELD(std::int32_t                    , m_nShorthandedRoundBonusStartRound              , 0x564)
        SCHEMA_FIELD(bool                            , m_bSurrendered                                  , 0x568)
        SCHEMA_FIELD(char                            , m_szTeamMatchStat                               , 0x569)
        SCHEMA_FIELD(std::int32_t                    , m_numMapVictories                               , 0x76C)
        SCHEMA_FIELD(std::int32_t                    , m_scoreFirstHalf                                , 0x770)
        SCHEMA_FIELD(std::int32_t                    , m_scoreSecondHalf                               , 0x774)
        SCHEMA_FIELD(std::int32_t                    , m_scoreOvertime                                 , 0x778)
        SCHEMA_FIELD(char                            , m_szClanTeamname                                , 0x77C)
        SCHEMA_FIELD(std::uint32_t                   , m_iClanID                                       , 0x800)
        SCHEMA_FIELD(char                            , m_szTeamFlagImage                               , 0x804)
        SCHEMA_FIELD(char                            , m_szTeamLogoImage                               , 0x80C)
        SCHEMA_FIELD(float                           , m_flNextResourceTime                            , 0x814)
        SCHEMA_FIELD(std::int32_t                    , m_iLastUpdateSentAt                             , 0x818)
    };

    class CCSGO_TeamIntroCharacterPosition : public CCSGO_TeamPreviewCharacterPosition {
    public:
    };

    class CCSGO_TeamSelectCharacterPosition : public CCSGO_TeamPreviewCharacterPosition {
    public:
    };

    class CCSGameRulesProxy : public CGameRulesProxy {
    public:
        SCHEMA_FIELD(CCSGameRules*                   , m_pGameRules                                    , 0x4A8)
    };

    class CInfoData : public CServerOnlyEntity {
    public:
    };

    class CServerOnlyPointEntity : public CServerOnlyEntity {
    public:
    };

    class CLogicalEntity : public CServerOnlyEntity {
    public:
    };

    class CPointCameraVFOV : public CPointCamera {
    public:
        SCHEMA_FIELD(float                           , m_flVerticalFOV                                 , 0x508)
    };

    class CFuncTrainControls : public CBaseModelEntity {
    public:
    };

    class CBaseToggle : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(TOGGLE_STATE                    , m_toggle_state                                  , 0x768)
        SCHEMA_FIELD(float                           , m_flMoveDistance                                , 0x76C)
        SCHEMA_FIELD(float                           , m_flWait                                        , 0x770)
        SCHEMA_FIELD(float                           , m_flLip                                         , 0x774)
        SCHEMA_FIELD(bool                            , m_bAlwaysFireBlockedOutputs                     , 0x778)
        SCHEMA_FIELD(::Vector                        , m_vecPosition1                                  , 0x77C)
        SCHEMA_FIELD(::Vector                        , m_vecPosition2                                  , 0x788)
        SCHEMA_FIELD(::QAngle                        , m_vecMoveAng                                    , 0x794)
        SCHEMA_FIELD(::QAngle                        , m_vecAngle1                                     , 0x7A0)
        SCHEMA_FIELD(::QAngle                        , m_vecAngle2                                     , 0x7AC)
        SCHEMA_FIELD(float                           , m_flHeight                                      , 0x7B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hActivator                                    , 0x7BC)
        SCHEMA_FIELD(::Vector                        , m_vecFinalDest                                  , 0x7C0)
        SCHEMA_FIELD(::QAngle                        , m_vecFinalAngle                                 , 0x7CC)
        SCHEMA_FIELD(std::int32_t                    , m_movementType                                  , 0x7D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sMaster                                       , 0x7E0)
    };

    class CInferno : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_firePositions                                 , 0x768)
        SCHEMA_FIELD(::Vector                        , m_fireParentPositions                           , 0xA68)
        SCHEMA_FIELD(bool                            , m_bFireIsBurning                                , 0xD68)
        SCHEMA_FIELD(::Vector                        , m_BurnNormal                                    , 0xDA8)
        SCHEMA_FIELD(std::int32_t                    , m_fireCount                                     , 0x10A8)
        SCHEMA_FIELD(std::int32_t                    , m_nInfernoType                                  , 0x10AC)
        SCHEMA_FIELD(std::int32_t                    , m_nFireEffectTickBegin                          , 0x10B0)
        SCHEMA_FIELD(float                           , m_nFireLifetime                                 , 0x10B4)
        SCHEMA_FIELD(bool                            , m_bInPostEffectTime                             , 0x10B8)
        SCHEMA_FIELD(bool                            , m_bWasCreatedInSmoke                            , 0x10B9)
        SCHEMA_FIELD(Extent                          , m_extent                                        , 0x12C0)
        SCHEMA_FIELD(CountdownTimer                  , m_damageTimer                                   , 0x12D8)
        SCHEMA_FIELD(CountdownTimer                  , m_damageRampTimer                               , 0x12F0)
        SCHEMA_FIELD(::Vector                        , m_splashVelocity                                , 0x1308)
        SCHEMA_FIELD(::Vector                        , m_InitialSplashVelocity                         , 0x1314)
        SCHEMA_FIELD(::Vector                        , m_startPos                                      , 0x1320)
        SCHEMA_FIELD(::Vector                        , m_vecOriginalSpawnLocation                      , 0x132C)
        SCHEMA_FIELD(IntervalTimer                   , m_activeTimer                                   , 0x1338)
        SCHEMA_FIELD(std::int32_t                    , m_fireSpawnOffset                               , 0x1348)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxFlames                                    , 0x134C)
        SCHEMA_FIELD(std::int32_t                    , m_nSpreadCount                                  , 0x1350)
        SCHEMA_FIELD(CountdownTimer                  , m_BookkeepingTimer                              , 0x1358)
        SCHEMA_FIELD(CountdownTimer                  , m_NextSpreadTimer                               , 0x1370)
        SCHEMA_FIELD(std::uint16_t                   , m_nSourceItemDefIndex                           , 0x1388)
    };

    class CFuncInteractionLayerClip : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x768)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszInteractsAs                                , 0x770)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszInteractsWith                              , 0x778)
    };

    class CFuncVehicleClip : public CBaseModelEntity {
    public:
    };

    class CRopeKeyframe : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_RopeFlags                                     , 0x770)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iNextLinkName                                 , 0x778)
        SCHEMA_FIELD(std::int16_t                    , m_Slack                                         , 0x780)
        SCHEMA_FIELD(float                           , m_Width                                         , 0x784)
        SCHEMA_FIELD(float                           , m_TextureScale                                  , 0x788)
        SCHEMA_FIELD(std::uint8_t                    , m_nSegments                                     , 0x78C)
        SCHEMA_FIELD(bool                            , m_bConstrainBetweenEndpoints                    , 0x78D)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strRopeMaterialModel                          , 0x790)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_iRopeMaterialModelIndex                       , 0x798)
        SCHEMA_FIELD(std::uint8_t                    , m_Subdiv                                        , 0x7A0)
        SCHEMA_FIELD(std::uint8_t                    , m_nChangeCount                                  , 0x7A1)
        SCHEMA_FIELD(std::int16_t                    , m_RopeLength                                    , 0x7A2)
        SCHEMA_FIELD(std::uint8_t                    , m_fLockedPoints                                 , 0x7A4)
        SCHEMA_FIELD(bool                            , m_bCreatedFromMapFile                           , 0x7A5)
        SCHEMA_FIELD(float                           , m_flScrollSpeed                                 , 0x7A8)
        SCHEMA_FIELD(bool                            , m_bStartPointValid                              , 0x7AC)
        SCHEMA_FIELD(bool                            , m_bEndPointValid                                , 0x7AD)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hStartPoint                                   , 0x7B0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEndPoint                                     , 0x7B4)
        SCHEMA_FIELD(AttachmentHandle_t              , m_iStartAttachment                              , 0x7B8)
        SCHEMA_FIELD(AttachmentHandle_t              , m_iEndAttachment                                , 0x7B9)
    };

    class CLightEntity : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CLightComponent*                , m_CLightComponent                               , 0x768)
    };

    class CModelPointEntity : public CBaseModelEntity {
    public:
    };

    class CFuncNavBlocker : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x770)
        SCHEMA_FIELD(std::int32_t                    , m_nBlockedTeamNumber                            , 0x774)
    };

    class CFuncBrush : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(BrushSolidities_e               , m_iSolidity                                     , 0x768)
        SCHEMA_FIELD(std::int32_t                    , m_iDisabled                                     , 0x76C)
        SCHEMA_FIELD(bool                            , m_bSolidBsp                                     , 0x770)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszExcludedClass                              , 0x778)
        SCHEMA_FIELD(bool                            , m_bInvertExclusion                              , 0x780)
        SCHEMA_FIELD(bool                            , m_bScriptedMovement                             , 0x781)
    };

    class CTriggerVolume : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x768)
        SCHEMA_FIELD(CHandle<CBaseFilter>            , m_hFilter                                       , 0x770)
    };

    class CParticleSystem : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(char                            , m_szSnapshotFileName                            , 0x768)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x968)
        SCHEMA_FIELD(bool                            , m_bFrozen                                       , 0x969)
        SCHEMA_FIELD(float                           , m_flFreezeTransitionDuration                    , 0x96C)
        SCHEMA_FIELD(std::int32_t                    , m_nStopType                                     , 0x970)
        SCHEMA_FIELD(bool                            , m_bAnimateDuringGameplayPause                   , 0x974)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_iEffectIndex                                  , 0x978)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x980)
        SCHEMA_FIELD(float                           , m_flPreSimTime                                  , 0x984)
        SCHEMA_FIELD(::Vector                        , m_vServerControlPoints                          , 0x988)
        SCHEMA_FIELD(std::uint8_t                    , m_iServerControlPointAssignments                , 0x9B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hControlPointEnts                             , 0x9BC)
        SCHEMA_FIELD(bool                            , m_bNoSave                                       , 0xABC)
        SCHEMA_FIELD(bool                            , m_bNoFreeze                                     , 0xABD)
        SCHEMA_FIELD(bool                            , m_bNoRamp                                       , 0xABE)
        SCHEMA_FIELD(bool                            , m_bStartActive                                  , 0xABF)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEffectName                                 , 0xAC0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszControlPointNames                          , 0xAC8)
        SCHEMA_FIELD(std::int32_t                    , m_nDataCP                                       , 0xCC8)
        SCHEMA_FIELD(::Vector                        , m_vecDataCPValue                                , 0xCCC)
        SCHEMA_FIELD(std::int32_t                    , m_nTintCP                                       , 0xCD8)
        SCHEMA_FIELD(::Color                         , m_clrTint                                       , 0xCDC)
    };

    class CTriggerBrush : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartTouch                                  , 0x768)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEndTouch                                    , 0x780)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUse                                         , 0x798)
        SCHEMA_FIELD(std::int32_t                    , m_iInputFilter                                  , 0x7B0)
        SCHEMA_FIELD(std::int32_t                    , m_iDontMessageParent                            , 0x7B4)
    };

    class CBeam : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(float                           , m_flFrameRate                                   , 0x768)
        SCHEMA_FIELD(float                           , m_flHDRColorScale                               , 0x76C)
        SCHEMA_FIELD(::GameTime_t                    , m_flFireTime                                    , 0x770)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0x774)
        SCHEMA_FIELD(std::uint8_t                    , m_nNumBeamEnts                                  , 0x778)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hBaseMaterial                                 , 0x780)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_nHaloIndex                                    , 0x788)
        SCHEMA_FIELD(BeamType_t                      , m_nBeamType                                     , 0x790)
        SCHEMA_FIELD(std::uint32_t                   , m_nBeamFlags                                    , 0x794)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAttachEntity                                 , 0x798)
        SCHEMA_FIELD(AttachmentHandle_t              , m_nAttachIndex                                  , 0x7C0)
        SCHEMA_FIELD(float                           , m_fWidth                                        , 0x7CC)
        SCHEMA_FIELD(float                           , m_fEndWidth                                     , 0x7D0)
        SCHEMA_FIELD(float                           , m_fFadeLength                                   , 0x7D4)
        SCHEMA_FIELD(float                           , m_fHaloScale                                    , 0x7D8)
        SCHEMA_FIELD(float                           , m_fAmplitude                                    , 0x7DC)
        SCHEMA_FIELD(float                           , m_fStartFrame                                   , 0x7E0)
        SCHEMA_FIELD(float                           , m_fSpeed                                        , 0x7E4)
        SCHEMA_FIELD(float                           , m_flFrame                                       , 0x7E8)
        SCHEMA_FIELD(BeamClipStyle_t                 , m_nClipStyle                                    , 0x7EC)
        SCHEMA_FIELD(bool                            , m_bTurnedOff                                    , 0x7F0)
        SCHEMA_FIELD(VectorWS                        , m_vecEndPos                                     , 0x7F4)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEndEntity                                    , 0x800)
        SCHEMA_FIELD(std::int32_t                    , m_nDissolveType                                 , 0x804)
    };

    class CEntityBlocker : public CBaseModelEntity {
    public:
    };

    class CFuncWater : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CBuoyancyHelper                 , m_BuoyancyHelper                                , 0x768)
    };

    class CFuncTrackTrain : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CHandle<CPathTrack>             , m_ppath                                         , 0x768)
        SCHEMA_FIELD(float                           , m_length                                        , 0x76C)
        SCHEMA_FIELD(::Vector                        , m_vPosPrev                                      , 0x770)
        SCHEMA_FIELD(::QAngle                        , m_angPrev                                       , 0x77C)
        SCHEMA_FIELD(::Vector                        , m_controlMins                                   , 0x788)
        SCHEMA_FIELD(::Vector                        , m_controlMaxs                                   , 0x794)
        SCHEMA_FIELD(::Vector                        , m_lastBlockPos                                  , 0x7A0)
        SCHEMA_FIELD(std::int32_t                    , m_lastBlockTick                                 , 0x7AC)
        SCHEMA_FIELD(float                           , m_flVolume                                      , 0x7B0)
        SCHEMA_FIELD(float                           , m_flBank                                        , 0x7B4)
        SCHEMA_FIELD(float                           , m_oldSpeed                                      , 0x7B8)
        SCHEMA_FIELD(float                           , m_flBlockDamage                                 , 0x7BC)
        SCHEMA_FIELD(float                           , m_height                                        , 0x7C0)
        SCHEMA_FIELD(float                           , m_maxSpeed                                      , 0x7C4)
        SCHEMA_FIELD(float                           , m_dir                                           , 0x7C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundMove                                  , 0x7D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundMovePing                              , 0x7D8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundStart                                 , 0x7E0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundStop                                  , 0x7E8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strPathTarget                                 , 0x7F0)
        SCHEMA_FIELD(float                           , m_flMoveSoundMinDuration                        , 0x7F8)
        SCHEMA_FIELD(float                           , m_flMoveSoundMaxDuration                        , 0x7FC)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextMoveSoundTime                           , 0x800)
        SCHEMA_FIELD(float                           , m_flMoveSoundMinPitch                           , 0x804)
        SCHEMA_FIELD(float                           , m_flMoveSoundMaxPitch                           , 0x808)
        SCHEMA_FIELD(TrainOrientationType_t          , m_eOrientationType                              , 0x80C)
        SCHEMA_FIELD(TrainVelocityType_t             , m_eVelocityType                                 , 0x810)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStart                                       , 0x828)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnNext                                        , 0x840)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnArrivedAtDestinationNode                    , 0x858)
        SCHEMA_FIELD(bool                            , m_bManualSpeedChanges                           , 0x870)
        SCHEMA_FIELD(float                           , m_flDesiredSpeed                                , 0x874)
        SCHEMA_FIELD(::GameTime_t                    , m_flSpeedChangeTime                             , 0x878)
        SCHEMA_FIELD(float                           , m_flAccelSpeed                                  , 0x87C)
        SCHEMA_FIELD(float                           , m_flDecelSpeed                                  , 0x880)
        SCHEMA_FIELD(bool                            , m_bAccelToSpeed                                 , 0x884)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextMPSoundTime                             , 0x888)
    };

    class CCashStack : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCashStackValue                               , 0x768)
    };

    class CFuncIllusionary : public CBaseModelEntity {
    public:
    };

    class CMarkupVolume : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x768)
    };

    class CServerOnlyModelEntity : public CBaseModelEntity {
    public:
    };

    class CPlatTrigger : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CHandle<CFuncPlat>              , m_pPlatform                                     , 0x768)
    };

    class CRuleEntity : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszMaster                                     , 0x768)
    };

    class CFuncLadder : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecLadderDir                                  , 0x768)
        SCHEMA_FIELD(CUtlVector<CHandle<CInfoLadderDismount>>, m_Dismounts                                     , 0x778)
        SCHEMA_FIELD(::Vector                        , m_vecLocalTop                                   , 0x790)
        SCHEMA_FIELD(VectorWS                        , m_vecPlayerMountPositionTop                     , 0x79C)
        SCHEMA_FIELD(VectorWS                        , m_vecPlayerMountPositionBottom                  , 0x7A8)
        SCHEMA_FIELD(float                           , m_flAutoRideSpeed                               , 0x7B4)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x7B8)
        SCHEMA_FIELD(bool                            , m_bFakeLadder                                   , 0x7B9)
        SCHEMA_FIELD(bool                            , m_bHasSlack                                     , 0x7BA)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_surfacePropName                               , 0x7C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerGotOnLadder                           , 0x7C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerGotOffLadder                          , 0x7E0)
    };

    class CFuncWall : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nState                                        , 0x768)
    };

    class CFuncRotating : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStopped                                     , 0x768)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStarted                                     , 0x780)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnReachedStart                                , 0x798)
        SCHEMA_FIELD(RotationVector                  , m_localRotationVector                           , 0x7B0)
        SCHEMA_FIELD(float                           , m_flFanFriction                                 , 0x7BC)
        SCHEMA_FIELD(float                           , m_flAttenuation                                 , 0x7C0)
        SCHEMA_FIELD(float                           , m_flVolume                                      , 0x7C4)
        SCHEMA_FIELD(float                           , m_flTargetSpeed                                 , 0x7C8)
        SCHEMA_FIELD(float                           , m_flMaxSpeed                                    , 0x7CC)
        SCHEMA_FIELD(float                           , m_flBlockDamage                                 , 0x7D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_NoiseRunning                                  , 0x7D8)
        SCHEMA_FIELD(bool                            , m_bReversed                                     , 0x7E0)
        SCHEMA_FIELD(bool                            , m_bAccelDecel                                   , 0x7E1)
        SCHEMA_FIELD(::QAngle                        , m_prevLocalAngles                               , 0x7F8)
        SCHEMA_FIELD(::QAngle                        , m_angStart                                      , 0x804)
        SCHEMA_FIELD(bool                            , m_bStopAtStartPos                               , 0x810)
        SCHEMA_FIELD(::Vector                        , m_vecClientOrigin                               , 0x814)
        SCHEMA_FIELD(::QAngle                        , m_vecClientAngles                               , 0x820)
    };

    class CPrecipitationBlocker : public CBaseModelEntity {
    public:
    };

    class CWorld : public CBaseModelEntity {
    public:
    };

    class CEnvDecal : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hDecalMaterial                                , 0x768)
        SCHEMA_FIELD(float                           , m_flWidth                                       , 0x770)
        SCHEMA_FIELD(float                           , m_flHeight                                      , 0x774)
        SCHEMA_FIELD(float                           , m_flDepth                                       , 0x778)
        SCHEMA_FIELD(std::uint32_t                   , m_nRenderOrder                                  , 0x77C)
        SCHEMA_FIELD(bool                            , m_bProjectOnWorld                               , 0x780)
        SCHEMA_FIELD(bool                            , m_bProjectOnCharacters                          , 0x781)
        SCHEMA_FIELD(bool                            , m_bProjectOnWater                               , 0x782)
        SCHEMA_FIELD(float                           , m_flDepthSortBias                               , 0x784)
    };

    class CEntityDissolve : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(float                           , m_flFadeInStart                                 , 0x768)
        SCHEMA_FIELD(float                           , m_flFadeInLength                                , 0x76C)
        SCHEMA_FIELD(float                           , m_flFadeOutModelStart                           , 0x770)
        SCHEMA_FIELD(float                           , m_flFadeOutModelLength                          , 0x774)
        SCHEMA_FIELD(float                           , m_flFadeOutStart                                , 0x778)
        SCHEMA_FIELD(float                           , m_flFadeOutLength                               , 0x77C)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x780)
        SCHEMA_FIELD(EntityDisolveType_t             , m_nDissolveType                                 , 0x784)
        SCHEMA_FIELD(::Vector                        , m_vDissolverOrigin                              , 0x788)
        SCHEMA_FIELD(std::uint32_t                   , m_nMagnitude                                    , 0x794)
    };

    class CFuncShatterglass : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(::matrix3x4_t                   , m_matPanelTransform                             , 0x768)
        SCHEMA_FIELD(::matrix3x4_t                   , m_matPanelTransformWsTemp                       , 0x798)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_vecShatterGlassShards                         , 0x7C8)
        SCHEMA_FIELD(::Vector2D                      , m_PanelSize                                     , 0x7E0)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastShatterSoundEmitTime                    , 0x7E8)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastCleanupTime                             , 0x7EC)
        SCHEMA_FIELD(::GameTime_t                    , m_flInitAtTime                                  , 0x7F0)
        SCHEMA_FIELD(float                           , m_flGlassThickness                              , 0x7F4)
        SCHEMA_FIELD(float                           , m_flSpawnInvulnerability                        , 0x7F8)
        SCHEMA_FIELD(bool                            , m_bBreakSilent                                  , 0x7FC)
        SCHEMA_FIELD(bool                            , m_bBreakShardless                               , 0x7FD)
        SCHEMA_FIELD(bool                            , m_bBroken                                       , 0x7FE)
        SCHEMA_FIELD(bool                            , m_bGlassNavIgnore                               , 0x7FF)
        SCHEMA_FIELD(bool                            , m_bGlassInFrame                                 , 0x800)
        SCHEMA_FIELD(bool                            , m_bStartBroken                                  , 0x801)
        SCHEMA_FIELD(std::uint8_t                    , m_iInitialDamageType                            , 0x802)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szDamagePositioningEntityName01               , 0x808)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szDamagePositioningEntityName02               , 0x810)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szDamagePositioningEntityName03               , 0x818)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szDamagePositioningEntityName04               , 0x820)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_vInitialDamagePositions                       , 0x828)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_vExtraDamagePositions                         , 0x840)
        SCHEMA_FIELD(CUtlVector<Vector4D>            , m_vInitialPanelVertices                         , 0x858)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBroken                                      , 0x870)
        SCHEMA_FIELD(std::uint8_t                    , m_iSurfaceType                                  , 0x888)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterialDamageBase                           , 0x890)
    };

    class CSpotlightEnd : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(float                           , m_flLightScale                                  , 0x768)
        SCHEMA_FIELD(float                           , m_Radius                                        , 0x76C)
        SCHEMA_FIELD(::Vector                        , m_vSpotlightDir                                 , 0x770)
        SCHEMA_FIELD(VectorWS                        , m_vSpotlightOrg                                 , 0x77C)
    };

    class CEnvSky : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSkyMaterial                                  , 0x768)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSkyMaterialLightingOnly                      , 0x770)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x778)
        SCHEMA_FIELD(::Color                         , m_vTintColor                                    , 0x779)
        SCHEMA_FIELD(::Color                         , m_vTintColorLightingOnly                        , 0x77D)
        SCHEMA_FIELD(float                           , m_flBrightnessScale                             , 0x784)
        SCHEMA_FIELD(std::int32_t                    , m_nFogType                                      , 0x788)
        SCHEMA_FIELD(float                           , m_flFogMinStart                                 , 0x78C)
        SCHEMA_FIELD(float                           , m_flFogMinEnd                                   , 0x790)
        SCHEMA_FIELD(float                           , m_flFogMaxStart                                 , 0x794)
        SCHEMA_FIELD(float                           , m_flFogMaxEnd                                   , 0x798)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x79C)
    };

    class CTextureBasedAnimatable : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bLoop                                         , 0x768)
        SCHEMA_FIELD(float                           , m_flFPS                                         , 0x76C)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hPositionKeys                                 , 0x770)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hRotationKeys                                 , 0x778)
        SCHEMA_FIELD(::Vector                        , m_vAnimationBoundsMin                           , 0x780)
        SCHEMA_FIELD(::Vector                        , m_vAnimationBoundsMax                           , 0x78C)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x798)
        SCHEMA_FIELD(float                           , m_flStartFrame                                  , 0x79C)
    };

    class CSprite : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSpriteMaterial                               , 0x768)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAttachedToEntity                             , 0x770)
        SCHEMA_FIELD(AttachmentHandle_t              , m_nAttachment                                   , 0x774)
        SCHEMA_FIELD(float                           , m_flSpriteFramerate                             , 0x778)
        SCHEMA_FIELD(float                           , m_flFrame                                       , 0x77C)
        SCHEMA_FIELD(::GameTime_t                    , m_flDieTime                                     , 0x780)
        SCHEMA_FIELD(std::uint32_t                   , m_nBrightness                                   , 0x790)
        SCHEMA_FIELD(float                           , m_flBrightnessDuration                          , 0x794)
        SCHEMA_FIELD(float                           , m_flSpriteScale                                 , 0x798)
        SCHEMA_FIELD(float                           , m_flScaleDuration                               , 0x79C)
        SCHEMA_FIELD(bool                            , m_bWorldSpaceScale                              , 0x7A0)
        SCHEMA_FIELD(float                           , m_flGlowProxySize                               , 0x7A4)
        SCHEMA_FIELD(float                           , m_flHDRColorScale                               , 0x7A8)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastTime                                    , 0x7AC)
        SCHEMA_FIELD(float                           , m_flMaxFrame                                    , 0x7B0)
        SCHEMA_FIELD(float                           , m_flStartScale                                  , 0x7B4)
        SCHEMA_FIELD(float                           , m_flDestScale                                   , 0x7B8)
        SCHEMA_FIELD(::GameTime_t                    , m_flScaleTimeStart                              , 0x7BC)
        SCHEMA_FIELD(std::int32_t                    , m_nStartBrightness                              , 0x7C0)
        SCHEMA_FIELD(std::int32_t                    , m_nDestBrightness                               , 0x7C4)
        SCHEMA_FIELD(::GameTime_t                    , m_flBrightnessTimeStart                         , 0x7C8)
        SCHEMA_FIELD(std::int32_t                    , m_nSpriteWidth                                  , 0x7CC)
        SCHEMA_FIELD(std::int32_t                    , m_nSpriteHeight                                 , 0x7D0)
    };

    class CDynamicLight : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_ActualFlags                                   , 0x768)
        SCHEMA_FIELD(std::uint8_t                    , m_Flags                                         , 0x769)
        SCHEMA_FIELD(std::uint8_t                    , m_LightStyle                                    , 0x76A)
        SCHEMA_FIELD(bool                            , m_On                                            , 0x76B)
        SCHEMA_FIELD(float                           , m_Radius                                        , 0x76C)
        SCHEMA_FIELD(std::int32_t                    , m_Exponent                                      , 0x770)
        SCHEMA_FIELD(float                           , m_InnerAngle                                    , 0x774)
        SCHEMA_FIELD(float                           , m_OuterAngle                                    , 0x778)
        SCHEMA_FIELD(float                           , m_SpotRadius                                    , 0x77C)
    };

    class CFuncVPhysicsClip : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x768)
    };

    class CBaseAnimGraph : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CAnimGraphControllerManager     , m_graphControllerManager                        , 0x768)
        SCHEMA_FIELD(CAnimGraphControllerBase*       , m_pMainGraphController                          , 0x818)
        SCHEMA_FIELD(bool                            , m_bInitiallyPopulateInterpHistory               , 0x820)
        SCHEMA_FIELD(IChoreoServices*                , m_pChoreoServices                               , 0x828)
        SCHEMA_FIELD(bool                            , m_bAnimGraphUpdateEnabled                       , 0x830)
        SCHEMA_FIELD(bool                            , m_bAnimationUpdateScheduled                     , 0x831)
        SCHEMA_FIELD(::Vector                        , m_vecForce                                      , 0x834)
        SCHEMA_FIELD(std::int32_t                    , m_nForceBone                                    , 0x840)
        SCHEMA_FIELD(IPhysicsRagdollControl*         , m_pRagdollControl                               , 0x850)
        SCHEMA_FIELD(PhysicsRagdollPose_t            , m_RagdollPose                                   , 0x858)
        SCHEMA_FIELD(bool                            , m_bRagdollEnabled                               , 0x880)
        SCHEMA_FIELD(bool                            , m_bRagdollClientSide                            , 0x881)
        SCHEMA_FIELD(CTransform                      , m_xParentedRagdollRootInEntitySpace             , 0x890)
    };

    class CItemGenericTriggerHelper : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CHandle<CItemGeneric>           , m_hParentItem                                   , 0x768)
    };

    class CBarnLight : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x768)
        SCHEMA_FIELD(std::int32_t                    , m_nColorMode                                    , 0x76C)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0x770)
        SCHEMA_FIELD(float                           , m_flColorTemperature                            , 0x774)
        SCHEMA_FIELD(float                           , m_flBrightness                                  , 0x778)
        SCHEMA_FIELD(float                           , m_flBrightnessScale                             , 0x77C)
        SCHEMA_FIELD(std::int32_t                    , m_nDirectLight                                  , 0x780)
        SCHEMA_FIELD(std::int32_t                    , m_nBakedShadowIndex                             , 0x784)
        SCHEMA_FIELD(std::int32_t                    , m_nLightPathUniqueId                            , 0x788)
        SCHEMA_FIELD(std::int32_t                    , m_nLightMapUniqueId                             , 0x78C)
        SCHEMA_FIELD(std::int32_t                    , m_nLuminaireShape                               , 0x790)
        SCHEMA_FIELD(float                           , m_flLuminaireSize                               , 0x794)
        SCHEMA_FIELD(float                           , m_flLuminaireAnisotropy                         , 0x798)
        SCHEMA_FIELD(::CUtlString                    , m_LightStyleString                              , 0x7A0)
        SCHEMA_FIELD(::GameTime_t                    , m_flLightStyleStartTime                         , 0x7A8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CUtlString>, m_QueuedLightStyleStrings                       , 0x7B0)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CUtlString>, m_LightStyleEvents                              , 0x7C8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBaseModelEntity>>, m_LightStyleTargets                             , 0x7E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_StyleEvent                                    , 0x7F8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hLightCookie                                  , 0x878)
        SCHEMA_FIELD(float                           , m_flShape                                       , 0x880)
        SCHEMA_FIELD(float                           , m_flSoftX                                       , 0x884)
        SCHEMA_FIELD(float                           , m_flSoftY                                       , 0x888)
        SCHEMA_FIELD(float                           , m_flSkirt                                       , 0x88C)
        SCHEMA_FIELD(float                           , m_flSkirtNear                                   , 0x890)
        SCHEMA_FIELD(::Vector                        , m_vSizeParams                                   , 0x894)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x8A0)
        SCHEMA_FIELD(::Vector                        , m_vShear                                        , 0x8A4)
        SCHEMA_FIELD(std::int32_t                    , m_nBakeSpecularToCubemaps                       , 0x8B0)
        SCHEMA_FIELD(::Vector                        , m_vBakeSpecularToCubemapsSize                   , 0x8B4)
        SCHEMA_FIELD(float                           , m_flBakeSpecularToCubemapsScale                 , 0x8C0)
        SCHEMA_FIELD(std::int32_t                    , m_nCastShadows                                  , 0x8C4)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowMapSize                                , 0x8C8)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowPriority                               , 0x8CC)
        SCHEMA_FIELD(bool                            , m_bContactShadow                                , 0x8D0)
        SCHEMA_FIELD(bool                            , m_bForceShadowsEnabled                          , 0x8D1)
        SCHEMA_FIELD(std::int32_t                    , m_nBounceLight                                  , 0x8D4)
        SCHEMA_FIELD(float                           , m_flBounceScale                                 , 0x8D8)
        SCHEMA_FIELD(float                           , m_flMinRoughness                                , 0x8DC)
        SCHEMA_FIELD(::Vector                        , m_vAlternateColor                               , 0x8E0)
        SCHEMA_FIELD(float                           , m_fAlternateColorBrightness                     , 0x8EC)
        SCHEMA_FIELD(std::int32_t                    , m_nFog                                          , 0x8F0)
        SCHEMA_FIELD(float                           , m_flFogStrength                                 , 0x8F4)
        SCHEMA_FIELD(std::int32_t                    , m_nFogShadows                                   , 0x8F8)
        SCHEMA_FIELD(float                           , m_flFogScale                                    , 0x8FC)
        SCHEMA_FIELD(float                           , m_flFadeSizeStart                               , 0x900)
        SCHEMA_FIELD(float                           , m_flFadeSizeEnd                                 , 0x904)
        SCHEMA_FIELD(float                           , m_flShadowFadeSizeStart                         , 0x908)
        SCHEMA_FIELD(float                           , m_flShadowFadeSizeEnd                           , 0x90C)
        SCHEMA_FIELD(bool                            , m_bPrecomputedFieldsValid                       , 0x910)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedBoundsMins                        , 0x914)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedBoundsMaxs                        , 0x920)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin                         , 0x92C)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles                         , 0x938)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent                         , 0x944)
        SCHEMA_FIELD(std::int32_t                    , m_nPrecomputedSubFrusta                         , 0x950)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin0                        , 0x954)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles0                        , 0x960)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent0                        , 0x96C)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin1                        , 0x978)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles1                        , 0x984)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent1                        , 0x990)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin2                        , 0x99C)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles2                        , 0x9A8)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent2                        , 0x9B4)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin3                        , 0x9C0)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles3                        , 0x9CC)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent3                        , 0x9D8)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin4                        , 0x9E4)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles4                        , 0x9F0)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent4                        , 0x9FC)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin5                        , 0xA08)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles5                        , 0xA14)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent5                        , 0xA20)
        SCHEMA_FIELD(bool                            , m_bPvsModifyEntity                              , 0xA2C)
        SCHEMA_FIELD(bool                            , m_bTransmitAlways                               , 0xA2D)
        SCHEMA_FIELD(CNetworkUtlVectorBase<uint16>   , m_VisClusters                                   , 0xA30)
    };

    class CFuncMover : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPathName                                   , 0x768)
        SCHEMA_FIELD(CHandle<CPathMover>             , m_hPathMover                                    , 0x770)
        SCHEMA_FIELD(CHandle<CPathMover>             , m_hPrevPathMover                                , 0x774)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPathNodeStart                              , 0x778)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPathNodeEnd                                , 0x780)
        SCHEMA_FIELD(bool                            , m_bIgnoreEndNode                                , 0x788)
        SCHEMA_FIELD(CFuncMover_Move_t               , m_eMoveType                                     , 0x78C)
        SCHEMA_FIELD(bool                            , m_bIsReversing                                  , 0x790)
        SCHEMA_FIELD(float                           , m_flStartSpeed                                  , 0x794)
        SCHEMA_FIELD(float                           , m_flPathLocation                                , 0x798)
        SCHEMA_FIELD(float                           , m_flT                                           , 0x79C)
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentNodeIndex                             , 0x7A0)
        SCHEMA_FIELD(std::int32_t                    , m_nPreviousNodeIndex                            , 0x7A4)
        SCHEMA_FIELD(SolidType_t                     , m_eSolidType                                    , 0x7A8)
        SCHEMA_FIELD(bool                            , m_bIsMoving                                     , 0x7A9)
        SCHEMA_FIELD(float                           , m_flTimeToReachMaxSpeed                         , 0x7AC)
        SCHEMA_FIELD(float                           , m_flDistanceToReachMaxSpeed                     , 0x7B0)
        SCHEMA_FIELD(float                           , m_flTimeToReachZeroSpeed                        , 0x7B4)
        SCHEMA_FIELD(float                           , m_flComputedDistanceToReachMaxSpeed             , 0x7B8)
        SCHEMA_FIELD(float                           , m_flComputedDistanceToReachZeroSpeed            , 0x7BC)
        SCHEMA_FIELD(float                           , m_flStartCurveScale                             , 0x7C0)
        SCHEMA_FIELD(float                           , m_flStopCurveScale                              , 0x7C4)
        SCHEMA_FIELD(float                           , m_flDistanceToReachZeroSpeed                    , 0x7C8)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeMovementStart                           , 0x7CC)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeMovementStop                            , 0x7D0)
        SCHEMA_FIELD(CHandle<CMoverPathNode>         , m_hStopAtNode                                   , 0x7D4)
        SCHEMA_FIELD(float                           , m_flPathLocationToBeginStop                     , 0x7D8)
        SCHEMA_FIELD(float                           , m_flPathLocationStart                           , 0x7DC)
        SCHEMA_FIELD(float                           , m_flBeginStopT                                  , 0x7E0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStartForwardSound                          , 0x7E8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLoopForwardSound                           , 0x7F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStopForwardSound                           , 0x7F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStartReverseSound                          , 0x800)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLoopReverseSound                           , 0x808)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStopReverseSound                           , 0x810)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszArriveAtDestinationSound                   , 0x818)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMovementEnd                                 , 0x838)
        SCHEMA_FIELD(bool                            , m_bStartAtClosestPoint                          , 0x850)
        SCHEMA_FIELD(bool                            , m_bStartAtEnd                                   , 0x851)
        SCHEMA_FIELD(bool                            , m_bStartFollowingClosestMover                   , 0x852)
        SCHEMA_FIELD(CFuncMover_OrientationUpdate_t  , m_eOrientationUpdate                            , 0x854)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeStartOrientationChange                  , 0x858)
        SCHEMA_FIELD(float                           , m_flTimeToBlendToNewOrientation                 , 0x85C)
        SCHEMA_FIELD(float                           , m_flDurationBlendToNewOrientationRan            , 0x860)
        SCHEMA_FIELD(bool                            , m_bCreateMovableNavMesh                         , 0x864)
        SCHEMA_FIELD(bool                            , m_bAllowMovableNavMeshDockingOnEntireEntity     , 0x865)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnNodePassed                                  , 0x868)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOrientationMatchEntityName                 , 0x888)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOrientationMatchEntity                       , 0x890)
        SCHEMA_FIELD(float                           , m_flTimeToTraverseToNextNode                    , 0x894)
        SCHEMA_FIELD(::Vector                        , m_vLerpToNewPosStartInPathEntitySpace           , 0x898)
        SCHEMA_FIELD(::Vector                        , m_vLerpToNewPosEndInPathEntitySpace             , 0x8A4)
        SCHEMA_FIELD(float                           , m_flLerpToPositionT                             , 0x8B0)
        SCHEMA_FIELD(float                           , m_flLerpToPositionDeltaT                        , 0x8B4)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLerpToPositionComplete                      , 0x8B8)
        SCHEMA_FIELD(bool                            , m_bIsPaused                                     , 0x8D0)
        SCHEMA_FIELD(CFuncMover_TransitionToPathNodeAction_t, m_eTransitionedToPathNodeAction                 , 0x8D4)
        SCHEMA_FIELD(::Quaternion                    , m_qTransitionSourceOrientation                  , 0x8E0)
        SCHEMA_FIELD(std::int32_t                    , m_nDelayedTeleportToNode                        , 0x8F0)
        SCHEMA_FIELD(bool                            , m_bIsImGuiLogging                               , 0x8F4)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hFollowEntity                                 , 0x8F8)
        SCHEMA_FIELD(float                           , m_flFollowDistance                              , 0x8FC)
        SCHEMA_FIELD(float                           , m_flFollowMinimumSpeed                          , 0x900)
        SCHEMA_FIELD(float                           , m_flCurFollowEntityT                            , 0x904)
        SCHEMA_FIELD(float                           , m_flCurFollowSpeed                              , 0x908)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strOrientationFaceEntityName                  , 0x910)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOrientationFaceEntity                        , 0x918)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStart                                       , 0x920)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartForward                                , 0x938)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartReverse                                , 0x950)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStop                                        , 0x968)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStopped                                     , 0x980)
        SCHEMA_FIELD(bool                            , m_bNextNodeReturnsCurrent                       , 0x998)
        SCHEMA_FIELD(bool                            , m_bStartedMoving                                , 0x999)
        SCHEMA_FIELD(CFuncMover_FollowEntityDirection_t, m_eFollowEntityDirection                        , 0x9B8)
        SCHEMA_FIELD(CHandle<CFuncMover>             , m_hFollowMover                                  , 0x9BC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszFollowMoverEntityName                      , 0x9C0)
        SCHEMA_FIELD(float                           , m_flFollowMoverDistance                         , 0x9C8)
        SCHEMA_FIELD(float                           , m_flFollowMoverRatio                            , 0x9CC)
        SCHEMA_FIELD(float                           , m_flFollowMoverCalculatedDistance               , 0x9D0)
        SCHEMA_FIELD(float                           , m_flFollowMoverSpringStrength                   , 0x9D4)
        SCHEMA_FIELD(std::int32_t                    , m_nFollowMoverConstraintPriority                , 0x9D8)
        SCHEMA_FIELD(bool                            , m_bFollowConstraintsInitialized                 , 0x9DC)
        SCHEMA_FIELD(CFuncMover_FollowConstraint_t   , m_eFollowConstraint                             , 0x9E0)
        SCHEMA_FIELD(float                           , m_flFollowMoverSpeed                            , 0x9E4)
        SCHEMA_FIELD(float                           , m_flFollowMoverVelocity                         , 0x9E8)
        SCHEMA_FIELD(::GameTick_t                    , m_nTickMovementRan                              , 0x9EC)
        SCHEMA_FIELD(FuncMoverMovementSummary_t      , m_movementSummary                               , 0x9F0)
        SCHEMA_FIELD(bool                            , m_bStopFromBeginStopTarget                      , 0xA10)
        SCHEMA_FIELD(bool                            , m_bQueueStop                                    , 0xA11)
        SCHEMA_FIELD(bool                            , m_bQueueStopMoving                              , 0xA12)
    };

    class CFuncNavObstruction : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x780)
        SCHEMA_FIELD(bool                            , m_bUseAsyncObstacleUpdate                       , 0x781)
    };

    class CBaseClientUIEntity : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x768)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_DialogXMLName                                 , 0x770)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_PanelClassName                                , 0x778)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_PanelID                                       , 0x780)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput0                                 , 0x788)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput1                                 , 0x7A8)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput2                                 , 0x7C8)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput3                                 , 0x7E8)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput4                                 , 0x808)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput5                                 , 0x828)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput6                                 , 0x848)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput7                                 , 0x868)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput8                                 , 0x888)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_CustomOutput9                                 , 0x8A8)
    };

    class CBreakable : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CPropDataComponent              , m_CPropDataComponent                            , 0x770)
        SCHEMA_FIELD(Materials                       , m_Material                                      , 0x7B0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hBreaker                                      , 0x7B4)
        SCHEMA_FIELD(Explosions                      , m_Explosion                                     , 0x7B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpawnObject                                , 0x7C0)
        SCHEMA_FIELD(float                           , m_flPressureDelay                               , 0x7C8)
        SCHEMA_FIELD(std::int32_t                    , m_iMinHealthDmg                                 , 0x7CC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPropData                                   , 0x7D0)
        SCHEMA_FIELD(float                           , m_impactEnergyScale                             , 0x7D8)
        SCHEMA_FIELD(EOverrideBlockLOS_t             , m_nOverrideBlockLOS                             , 0x7DC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartDeath                                  , 0x7E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBreak                                       , 0x7F8)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnHealthChanged                               , 0x810)
        SCHEMA_FIELD(PerformanceMode_t               , m_PerformanceMode                               , 0x830)
        SCHEMA_FIELD(CHandle<CBasePlayerPawn>        , m_hPhysicsAttacker                              , 0x834)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastPhysicsInfluenceTime                    , 0x838)
    };

    class CFuncRotator : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hRotatorTarget                                , 0x768)
        SCHEMA_FIELD(bool                            , m_bIsRotating                                   , 0x76C)
        SCHEMA_FIELD(bool                            , m_bIsReversing                                  , 0x76D)
        SCHEMA_FIELD(float                           , m_flTimeToReachMaxSpeed                         , 0x770)
        SCHEMA_FIELD(float                           , m_flTimeToReachZeroSpeed                        , 0x774)
        SCHEMA_FIELD(float                           , m_flDistanceAlongArcTraveled                    , 0x778)
        SCHEMA_FIELD(float                           , m_flTimeToWaitOscillate                         , 0x77C)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeRotationStart                           , 0x780)
        SCHEMA_FIELD(::Quaternion                    , m_qLSPrevChange                                 , 0x790)
        SCHEMA_FIELD(::Quaternion                    , m_qWSPrev                                       , 0x7A0)
        SCHEMA_FIELD(::Quaternion                    , m_qWSInit                                       , 0x7B0)
        SCHEMA_FIELD(::Quaternion                    , m_qLSInit                                       , 0x7C0)
        SCHEMA_FIELD(::Quaternion                    , m_qLSOrientation                                , 0x7D0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnRotationStarted                             , 0x7E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnRotationCompleted                           , 0x7F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOscillate                                   , 0x810)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOscillateStartArrive                        , 0x828)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOscillateStartDepart                        , 0x840)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOscillateEndArrive                          , 0x858)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOscillateEndDepart                          , 0x870)
        SCHEMA_FIELD(bool                            , m_bOscillateDepart                              , 0x888)
        SCHEMA_FIELD(std::int32_t                    , m_nOscillateCount                               , 0x88C)
        SCHEMA_FIELD(CFuncRotator_Rotate_t           , m_eRotateType                                   , 0x890)
        SCHEMA_FIELD(CFuncRotator_Rotate_t           , m_ePrevRotateType                               , 0x894)
        SCHEMA_FIELD(bool                            , m_bHasTargetOverride                            , 0x898)
        SCHEMA_FIELD(::Quaternion                    , m_qOrientationOverride                          , 0x8A0)
        SCHEMA_FIELD(RotatorTargetSpace_t            , m_eSpaceOverride                                , 0x8B0)
        SCHEMA_FIELD(::QAngle                        , m_qAngularVelocity                              , 0x8B4)
        SCHEMA_FIELD(::Vector                        , m_vLookAtForcedUp                               , 0x8C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strRotatorTarget                              , 0x8D0)
        SCHEMA_FIELD(bool                            , m_bRecordHistory                                , 0x8D8)
        SCHEMA_FIELD(CUtlVector<RotatorHistoryEntry_t>, m_vecRotatorHistory                             , 0x8E0)
        SCHEMA_FIELD(bool                            , m_bReturningToPreviousOrientation               , 0x8F8)
        SCHEMA_FIELD(CUtlVector<RotatorQueueEntry_t> , m_vecRotatorQueue                               , 0x900)
        SCHEMA_FIELD(CUtlVector<RotatorHistoryEntry_t>, m_vecRotatorQueueHistory                        , 0x918)
        SCHEMA_FIELD(SolidType_t                     , m_eSolidType                                    , 0x930)
        SCHEMA_FIELD(CHandle<CFuncMover>             , m_hSpeedFromMover                               , 0x934)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpeedFromMover                             , 0x938)
        SCHEMA_FIELD(float                           , m_flSpeedScale                                  , 0x940)
        SCHEMA_FIELD(float                           , m_flMinYawRotation                              , 0x944)
        SCHEMA_FIELD(float                           , m_flMaxYawRotation                              , 0x948)
    };

    class CFuncConveyor : public CBaseModelEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szConveyorModels                              , 0x768)
        SCHEMA_FIELD(float                           , m_flTransitionDurationSeconds                   , 0x770)
        SCHEMA_FIELD(::QAngle                        , m_angMoveEntitySpace                            , 0x774)
        SCHEMA_FIELD(::Vector                        , m_vecMoveDirEntitySpace                         , 0x780)
        SCHEMA_FIELD(float                           , m_flTargetSpeed                                 , 0x78C)
        SCHEMA_FIELD(::GameTick_t                    , m_nTransitionStartTick                          , 0x790)
        SCHEMA_FIELD(std::int32_t                    , m_nTransitionDurationTicks                      , 0x794)
        SCHEMA_FIELD(float                           , m_flTransitionStartSpeed                        , 0x798)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CBaseEntity>>, m_hConveyorModels                               , 0x7A0)
    };

    class CPathWithDynamicNodes : public CPathSimple {
    public:
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CPathNode>>, m_vecPathNodes                                  , 0x5B0)
        SCHEMA_FIELD(CTransform                      , m_xInitialPathWorldToLocal                      , 0x5D0)
    };

    class CSoundOpvarSetOBBWindEntity : public CSoundOpvarSetPointBase {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMins                                         , 0x550)
        SCHEMA_FIELD(::Vector                        , m_vMaxs                                         , 0x55C)
        SCHEMA_FIELD(::Vector                        , m_vDistanceMins                                 , 0x568)
        SCHEMA_FIELD(::Vector                        , m_vDistanceMaxs                                 , 0x574)
        SCHEMA_FIELD(float                           , m_flWindMin                                     , 0x580)
        SCHEMA_FIELD(float                           , m_flWindMax                                     , 0x584)
        SCHEMA_FIELD(float                           , m_flWindMapMin                                  , 0x588)
        SCHEMA_FIELD(float                           , m_flWindMapMax                                  , 0x58C)
    };

    class CSoundOpvarSetPointEntity : public CSoundOpvarSetPointBase {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEnter                                       , 0x550)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnExit                                        , 0x568)
        SCHEMA_FIELD(bool                            , m_bAutoDisable                                  , 0x580)
        SCHEMA_FIELD(float                           , m_flDistanceMin                                 , 0x5C4)
        SCHEMA_FIELD(float                           , m_flDistanceMax                                 , 0x5C8)
        SCHEMA_FIELD(float                           , m_flDistanceMapMin                              , 0x5CC)
        SCHEMA_FIELD(float                           , m_flDistanceMapMax                              , 0x5D0)
        SCHEMA_FIELD(float                           , m_flOcclusionRadius                             , 0x5D4)
        SCHEMA_FIELD(float                           , m_flOcclusionMin                                , 0x5D8)
        SCHEMA_FIELD(float                           , m_flOcclusionMax                                , 0x5DC)
        SCHEMA_FIELD(float                           , m_flValSetOnDisable                             , 0x5E0)
        SCHEMA_FIELD(bool                            , m_bSetValueOnDisable                            , 0x5E4)
        SCHEMA_FIELD(bool                            , m_bReloading                                    , 0x5E5)
        SCHEMA_FIELD(std::int32_t                    , m_nSimulationMode                               , 0x5E8)
        SCHEMA_FIELD(std::int32_t                    , m_nVisibilitySamples                            , 0x5EC)
        SCHEMA_FIELD(::Vector                        , m_vDynamicProxyPoint                            , 0x5F0)
        SCHEMA_FIELD(float                           , m_flDynamicMaximumOcclusion                     , 0x5FC)
        SCHEMA_FIELD(CEntityHandle                   , m_hDynamicEntity                                , 0x600)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszDynamicEntityName                          , 0x608)
        SCHEMA_FIELD(float                           , m_flPathingDistanceNormFactor                   , 0x610)
        SCHEMA_FIELD(::Vector                        , m_vPathingSourcePos                             , 0x614)
        SCHEMA_FIELD(::Vector                        , m_vPathingListenerPos                           , 0x620)
        SCHEMA_FIELD(::Vector                        , m_vPathingDirection                             , 0x62C)
        SCHEMA_FIELD(std::int32_t                    , m_nPathingSourceIndex                           , 0x638)
    };

    class CSoundEventAABBEntity : public CSoundEventEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMins                                         , 0x568)
        SCHEMA_FIELD(::Vector                        , m_vMaxs                                         , 0x574)
    };

    class CSoundEventPathCornerEntity : public CSoundEventEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPathCorner                                 , 0x568)
        SCHEMA_FIELD(std::int32_t                    , m_iCountMax                                     , 0x570)
        SCHEMA_FIELD(float                           , m_flDistanceMax                                 , 0x574)
        SCHEMA_FIELD(float                           , m_flDistMaxSqr                                  , 0x578)
        SCHEMA_FIELD(float                           , m_flDotProductMax                               , 0x57C)
        SCHEMA_FIELD(bool                            , m_bPlaying                                      , 0x580)
        SCHEMA_FIELD(CNetworkUtlVectorBase<SoundeventPathCornerPairNetworked_t>, m_vecCornerPairsNetworked                       , 0x5A8)
    };

    class CSoundEventConeEntity : public CSoundEventEntity {
    public:
        SCHEMA_FIELD(float                           , m_flEmitterAngle                                , 0x568)
        SCHEMA_FIELD(float                           , m_flSweetSpotAngle                              , 0x56C)
        SCHEMA_FIELD(float                           , m_flAttenMin                                    , 0x570)
        SCHEMA_FIELD(float                           , m_flAttenMax                                    , 0x574)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszParameterName                              , 0x578)
    };

    class CSoundEventSphereEntity : public CSoundEventEntity {
    public:
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x568)
    };

    class CSoundEventEntityAlias_snd_event_point : public CSoundEventEntity {
    public:
    };

    class CSoundEventOBBEntity : public CSoundEventEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMins                                         , 0x568)
        SCHEMA_FIELD(::Vector                        , m_vMaxs                                         , 0x574)
    };

    class CEnvCubemapBox : public CEnvCubemap {
    public:
    };

    class CCSPlayerController : public CBasePlayerController {
    public:
        SCHEMA_FIELD(CCSPlayerController_InGameMoneyServices*, m_pInGameMoneyServices                          , 0x7E0)
        SCHEMA_FIELD(CCSPlayerController_InventoryServices*, m_pInventoryServices                            , 0x7E8)
        SCHEMA_FIELD(CCSPlayerController_ActionTrackingServices*, m_pActionTrackingServices                       , 0x7F0)
        SCHEMA_FIELD(CCSPlayerController_DamageServices*, m_pDamageServices                               , 0x7F8)
        SCHEMA_FIELD(std::uint32_t                   , m_iPing                                         , 0x800)
        SCHEMA_FIELD(bool                            , m_bHasCommunicationAbuseMute                    , 0x804)
        SCHEMA_FIELD(std::uint32_t                   , m_uiCommunicationMuteFlags                      , 0x808)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szCrosshairCodes                              , 0x810)
        SCHEMA_FIELD(std::uint8_t                    , m_iPendingTeamNum                               , 0x818)
        SCHEMA_FIELD(::GameTime_t                    , m_flForceTeamTime                               , 0x81C)
        SCHEMA_FIELD(std::int32_t                    , m_iCompTeammateColor                            , 0x820)
        SCHEMA_FIELD(bool                            , m_bEverPlayedOnTeam                             , 0x824)
        SCHEMA_FIELD(bool                            , m_bAttemptedToGetColor                          , 0x825)
        SCHEMA_FIELD(std::int32_t                    , m_iTeammatePreferredColor                       , 0x828)
        SCHEMA_FIELD(bool                            , m_bTeamChanged                                  , 0x82C)
        SCHEMA_FIELD(bool                            , m_bInSwitchTeam                                 , 0x82D)
        SCHEMA_FIELD(bool                            , m_bHasSeenJoinGame                              , 0x82E)
        SCHEMA_FIELD(bool                            , m_bJustBecameSpectator                          , 0x82F)
        SCHEMA_FIELD(bool                            , m_bSwitchTeamsOnNextRoundReset                  , 0x830)
        SCHEMA_FIELD(bool                            , m_bRemoveAllItemsOnNextRoundReset               , 0x831)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastJoinTeamTime                            , 0x834)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szClan                                        , 0x838)
        SCHEMA_FIELD(std::int32_t                    , m_iCoachingTeam                                 , 0x840)
        SCHEMA_FIELD(std::uint64_t                   , m_nPlayerDominated                              , 0x848)
        SCHEMA_FIELD(std::uint64_t                   , m_nPlayerDominatingMe                           , 0x850)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRanking                           , 0x858)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveWins                              , 0x85C)
        SCHEMA_FIELD(std::int8_t                     , m_iCompetitiveRankType                          , 0x860)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRankingPredicted_Win              , 0x864)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRankingPredicted_Loss             , 0x868)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRankingPredicted_Tie              , 0x86C)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchNextMapVote                          , 0x870)
        SCHEMA_FIELD(std::uint16_t                   , m_unActiveQuestId                               , 0x874)
        SCHEMA_FIELD(std::uint32_t                   , m_rtActiveMissionPeriod                         , 0x878)
        SCHEMA_FIELD(QuestProgress_Reason            , m_nQuestProgressReason                          , 0x87C)
        SCHEMA_FIELD(std::uint32_t                   , m_unPlayerTvControlFlags                        , 0x880)
        SCHEMA_FIELD(std::int32_t                    , m_iDraftIndex                                   , 0x8B0)
        SCHEMA_FIELD(std::uint32_t                   , m_msQueuedModeDisconnectionTimestamp            , 0x8B4)
        SCHEMA_FIELD(std::uint32_t                   , m_uiAbandonRecordedReason                       , 0x8B8)
        SCHEMA_FIELD(std::uint32_t                   , m_eNetworkDisconnectionReason                   , 0x8BC)
        SCHEMA_FIELD(bool                            , m_bCannotBeKicked                               , 0x8C0)
        SCHEMA_FIELD(bool                            , m_bEverFullyConnected                           , 0x8C1)
        SCHEMA_FIELD(bool                            , m_bAbandonAllowsSurrender                       , 0x8C2)
        SCHEMA_FIELD(bool                            , m_bAbandonOffersInstantSurrender                , 0x8C3)
        SCHEMA_FIELD(bool                            , m_bDisconnection1MinWarningPrinted              , 0x8C4)
        SCHEMA_FIELD(bool                            , m_bScoreReported                                , 0x8C5)
        SCHEMA_FIELD(std::int32_t                    , m_nDisconnectionTick                            , 0x8C8)
        SCHEMA_FIELD(bool                            , m_bControllingBot                               , 0x8D8)
        SCHEMA_FIELD(bool                            , m_bHasControlledBotThisRound                    , 0x8D9)
        SCHEMA_FIELD(bool                            , m_bHasBeenControlledByPlayerThisRound           , 0x8DA)
        SCHEMA_FIELD(std::int32_t                    , m_nBotsControlledThisRound                      , 0x8DC)
        SCHEMA_FIELD(bool                            , m_bCanControlObservedBot                        , 0x8E0)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hPlayerPawn                                   , 0x8E4)
        SCHEMA_FIELD(CHandle<CCSObserverPawn>        , m_hObserverPawn                                 , 0x8E8)
        SCHEMA_FIELD(std::int32_t                    , m_DesiredObserverMode                           , 0x8EC)
        SCHEMA_FIELD(CEntityHandle                   , m_hDesiredObserverTarget                        , 0x8F0)
        SCHEMA_FIELD(bool                            , m_bPawnIsAlive                                  , 0x8F4)
        SCHEMA_FIELD(std::uint32_t                   , m_iPawnHealth                                   , 0x8F8)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnArmor                                    , 0x8FC)
        SCHEMA_FIELD(bool                            , m_bPawnHasDefuser                               , 0x900)
        SCHEMA_FIELD(bool                            , m_bPawnHasHelmet                                , 0x901)
        SCHEMA_FIELD(std::uint16_t                   , m_nPawnCharacterDefIndex                        , 0x902)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnLifetimeStart                            , 0x904)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnLifetimeEnd                              , 0x908)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnBotDifficulty                            , 0x90C)
        SCHEMA_FIELD(CHandle<CCSPlayerController>    , m_hOriginalControllerOfCurrentPawn              , 0x910)
        SCHEMA_FIELD(std::int32_t                    , m_iScore                                        , 0x914)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundScore                                   , 0x918)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundsWon                                    , 0x91C)
        SCHEMA_FIELD(std::uint8_t                    , m_recentKillQueue                               , 0x920)
        SCHEMA_FIELD(std::uint8_t                    , m_nFirstKill                                    , 0x928)
        SCHEMA_FIELD(std::uint8_t                    , m_nKillCount                                    , 0x929)
        SCHEMA_FIELD(bool                            , m_bMvpNoMusic                                   , 0x92A)
        SCHEMA_FIELD(std::int32_t                    , m_eMvpReason                                    , 0x92C)
        SCHEMA_FIELD(std::int32_t                    , m_iMusicKitID                                   , 0x930)
        SCHEMA_FIELD(std::int32_t                    , m_iMusicKitMVPs                                 , 0x934)
        SCHEMA_FIELD(std::int32_t                    , m_iMVPs                                         , 0x938)
        SCHEMA_FIELD(std::int32_t                    , m_nUpdateCounter                                , 0x93C)
        SCHEMA_FIELD(float                           , m_flSmoothedPing                                , 0x940)
        SCHEMA_FIELD(IntervalTimer                   , m_lastHeldVoteTimer                             , 0x948)
        SCHEMA_FIELD(bool                            , m_bShowHints                                    , 0x960)
        SCHEMA_FIELD(std::int32_t                    , m_iNextTimeCheck                                , 0x964)
        SCHEMA_FIELD(bool                            , m_bJustDidTeamKill                              , 0x968)
        SCHEMA_FIELD(bool                            , m_bPunishForTeamKill                            , 0x969)
        SCHEMA_FIELD(bool                            , m_bGaveTeamDamageWarning                        , 0x96A)
        SCHEMA_FIELD(bool                            , m_bGaveTeamDamageWarningThisRound               , 0x96B)
        SCHEMA_FIELD(double                          , m_dblLastReceivedPacketPlatFloatTime            , 0x970)
        SCHEMA_FIELD(::GameTime_t                    , m_LastTeamDamageWarningTime                     , 0x978)
        SCHEMA_FIELD(::GameTime_t                    , m_LastTimePlayerWasDisconnectedForPawnsRemove   , 0x97C)
        SCHEMA_FIELD(std::uint32_t                   , m_nSuspiciousHitCount                           , 0x980)
        SCHEMA_FIELD(std::uint32_t                   , m_nNonSuspiciousHitStreak                       , 0x984)
        SCHEMA_FIELD(bool                            , m_bFireBulletsSeedSynchronized                  , 0xA29)
    };

    class CBodyComponentBaseAnimGraph : public CBodyComponentSkeletonInstance {
    public:
        SCHEMA_FIELD(CBaseAnimGraphController        , m_animationController                           , 0x4A0)
    };

    class CBodyComponentBaseModelEntity : public CBodyComponentSkeletonInstance {
    public:
    };

    class CCSPlayer_MovementServices : public CPlayer_MovementServices_Humanoid {
    public:
        SCHEMA_FIELD(CCSPlayerAnimationState         , m_AnimationState                                , 0x310)
        SCHEMA_FIELD(bool                            , m_bUsingGroundTopologyOffset                    , 0x3F0)
        SCHEMA_FIELD(float                           , m_flUsingGroundTopologyOffsetTransitionSmoothing, 0x3F4)
        SCHEMA_FIELD(::Vector                        , m_vecLadderNormal                               , 0x3F8)
        SCHEMA_FIELD(std::int32_t                    , m_nLadderSurfacePropIndex                       , 0x404)
        SCHEMA_FIELD(bool                            , m_bDucked                                       , 0x408)
        SCHEMA_FIELD(float                           , m_flDuckAmount                                  , 0x40C)
        SCHEMA_FIELD(float                           , m_flDuckSpeed                                   , 0x410)
        SCHEMA_FIELD(bool                            , m_bDuckOverride                                 , 0x414)
        SCHEMA_FIELD(bool                            , m_bDesiresDuck                                  , 0x415)
        SCHEMA_FIELD(bool                            , m_bDucking                                      , 0x416)
        SCHEMA_FIELD(float                           , m_flDuckRootOffset                              , 0x418)
        SCHEMA_FIELD(float                           , m_flDuckViewOffset                              , 0x41C)
        SCHEMA_FIELD(float                           , m_flLastDuckTime                                , 0x420)
        SCHEMA_FIELD(float                           , m_flBombPlantViewOffset                         , 0x424)
        SCHEMA_FIELD(::Vector2D                      , m_vecLastPositionAtFullCrouchSpeed              , 0x430)
        SCHEMA_FIELD(bool                            , m_duckUntilOnGround                             , 0x438)
        SCHEMA_FIELD(bool                            , m_bHasWalkMovedSinceLastJump                    , 0x439)
        SCHEMA_FIELD(bool                            , m_bInStuckTest                                  , 0x43A)
        SCHEMA_FIELD(std::int32_t                    , m_nTraceCount                                   , 0x648)
        SCHEMA_FIELD(std::int32_t                    , m_StuckLast                                     , 0x64C)
        SCHEMA_FIELD(bool                            , m_bSpeedCropped                                 , 0x650)
        SCHEMA_FIELD(std::int32_t                    , m_nOldWaterLevel                                , 0x654)
        SCHEMA_FIELD(float                           , m_flWaterEntryTime                              , 0x658)
        SCHEMA_FIELD(::Vector                        , m_vecForward                                    , 0x65C)
        SCHEMA_FIELD(::Vector                        , m_vecLeft                                       , 0x668)
        SCHEMA_FIELD(::Vector                        , m_vecUp                                         , 0x674)
        SCHEMA_FIELD(std::int32_t                    , m_nGameCodeHasMovedPlayerAfterCommand           , 0x680)
        SCHEMA_FIELD(bool                            , m_bMadeFootstepNoise                            , 0x684)
        SCHEMA_FIELD(std::int32_t                    , m_iFootsteps                                    , 0x688)
        SCHEMA_FIELD(::GameTime_t                    , m_fStashGrenadeParameterWhen                    , 0x68C)
        SCHEMA_FIELD(std::uint64_t                   , m_nButtonDownMaskPrev                           , 0x690)
        SCHEMA_FIELD(bool                            , m_bUseFrictionStashedSpeed                      , 0x698)
        SCHEMA_FIELD(float                           , m_flUseFrictionStashedSpeedUntilFrac            , 0x69C)
        SCHEMA_FIELD(float                           , m_flFrictionStashedSpeed                        , 0x6A0)
        SCHEMA_FIELD(float                           , m_flStamina                                     , 0x6A4)
        SCHEMA_FIELD(float                           , m_flHeightAtJumpStart                           , 0x6A8)
        SCHEMA_FIELD(float                           , m_flMaxJumpHeightThisJump                       , 0x6AC)
        SCHEMA_FIELD(float                           , m_flMaxJumpHeightLastJump                       , 0x6B0)
        SCHEMA_FIELD(float                           , m_flStaminaAtJumpStart                          , 0x6B4)
        SCHEMA_FIELD(float                           , m_flVelMulAtJumpStart                           , 0x6B8)
        SCHEMA_FIELD(float                           , m_flAccumulatedJumpError                        , 0x6BC)
        SCHEMA_FIELD(CCSPlayerLegacyJump             , m_LegacyJump                                    , 0x6C0)
        SCHEMA_FIELD(CCSPlayerModernJump             , m_ModernJump                                    , 0x6D8)
        SCHEMA_FIELD(::GameTick_t                    , m_nLastJumpTick                                 , 0x710)
        SCHEMA_FIELD(float                           , m_flLastJumpFrac                                , 0x714)
        SCHEMA_FIELD(float                           , m_flLastJumpVelocityZ                           , 0x718)
        SCHEMA_FIELD(bool                            , m_bJumpApexPending                              , 0x71C)
        SCHEMA_FIELD(float                           , m_flTicksSinceLastSurfingDetected               , 0x720)
        SCHEMA_FIELD(bool                            , m_bWasSurfing                                   , 0x724)
        SCHEMA_FIELD(::Vector2D                      , m_vecWalkWishVel                                , 0x7B4)
        SCHEMA_FIELD(bool                            , m_bHasEverProcessedCommand                      , 0xFE0)
    };

    class CCSPlayer_CameraServices : public CCSPlayerBase_CameraServices {
    public:
    };

    class CCSObserver_CameraServices : public CCSPlayerBase_CameraServices {
    public:
    };

    class CInfoDynamicShadowHintBox : public CInfoDynamicShadowHint {
    public:
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x4C0)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x4CC)
    };

    class CMoverPathNode : public CPathNode {
    public:
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnStartFromOrInSegment                        , 0x500)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnStoppedAtOrInSegment                        , 0x520)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnPassThrough                                 , 0x540)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnPassThroughForward                          , 0x560)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnPassThroughReverse                          , 0x580)
    };

    class CSceneEntityAlias_logic_choreographed_scene : public CSceneEntity {
    public:
    };

    class CInstancedSceneEntity : public CSceneEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOwner                                        , 0x7C0)
        SCHEMA_FIELD(bool                            , m_bHadOwner                                     , 0x7C4)
        SCHEMA_FIELD(float                           , m_flPostSpeakDelay                              , 0x7C8)
        SCHEMA_FIELD(float                           , m_flPreDelay                                    , 0x7CC)
        SCHEMA_FIELD(bool                            , m_bIsBackground                                 , 0x7D0)
        SCHEMA_FIELD(bool                            , m_bRemoveOnCompletion                           , 0x7D1)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget                                       , 0x7D4)
    };

    class CPhysTorque : public CPhysForce {
    public:
        SCHEMA_FIELD(VectorWS                        , m_axis                                          , 0x508)
    };

    class CPhysThruster : public CPhysForce {
    public:
        SCHEMA_FIELD(::Vector                        , m_localOrigin                                   , 0x508)
    };

    class CPathCornerCrash : public CPathCorner {
    public:
    };

    class CLogicNPCCounterOBB : public CLogicNPCCounterAABB {
    public:
    };

    class CEnvSoundscapeProxyAlias_snd_soundscape_proxy : public CEnvSoundscapeProxy {
    public:
    };

    class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable : public CEnvSoundscapeTriggerable {
    public:
    };

    class CCSGO_TeamIntroTerroristPosition : public CCSGO_TeamIntroCharacterPosition {
    public:
    };

    class CCSGO_TeamIntroCounterTerroristPosition : public CCSGO_TeamIntroCharacterPosition {
    public:
    };

    class CCSGO_WingmanIntroCharacterPosition : public CCSGO_TeamIntroCharacterPosition {
    public:
    };

    class CCSGO_TeamSelectTerroristPosition : public CCSGO_TeamSelectCharacterPosition {
    public:
    };

    class CCSGO_TeamSelectCounterTerroristPosition : public CCSGO_TeamSelectCharacterPosition {
    public:
    };

    class SpawnPoint : public CServerOnlyPointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iPriority                                     , 0x4A8)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_nType                                         , 0x4B0)
    };

    class CPointPrefab : public CServerOnlyPointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_targetMapName                                 , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_forceWorldGroupID                             , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_associatedRelayTargetName                     , 0x4B8)
        SCHEMA_FIELD(bool                            , m_fixupNames                                    , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bLoadDynamic                                  , 0x4C1)
        SCHEMA_FIELD(CHandle<CPointPrefab>           , m_associatedRelayEntity                         , 0x4C4)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_ProceduralRelaySources                        , 0x4C8)
    };

    class CPointTeleport : public CServerOnlyPointEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vSaveOrigin                                   , 0x4A8)
        SCHEMA_FIELD(::QAngle                        , m_vSaveAngles                                   , 0x4B4)
        SCHEMA_FIELD(bool                            , m_bTeleportParentedEntities                     , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bTeleportUseCurrentAngle                      , 0x4C1)
    };

    class CInfoTargetServerOnly : public CServerOnlyPointEntity {
    public:
    };

    class CLogicCase : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nCase                                         , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_nShuffleCases                                 , 0x5A8)
        SCHEMA_FIELD(std::int32_t                    , m_nLastShuffleCase                              , 0x5AC)
        SCHEMA_FIELD(std::uint8_t                    , m_uchShuffleCaseMap                             , 0x5B0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCase                                        , 0x5D0)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnDefault                                     , 0x8D0)
    };

    class CLogicRelay : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnSpawn                                       , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTrigger                                     , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4D8)
        SCHEMA_FIELD(bool                            , m_bWaitForRefire                                , 0x4D9)
        SCHEMA_FIELD(bool                            , m_bTriggerOnce                                  , 0x4DA)
        SCHEMA_FIELD(bool                            , m_bFastRetrigger                                , 0x4DB)
        SCHEMA_FIELD(bool                            , m_bPassthoughCaller                             , 0x4DC)
    };

    class CTestPulseIO : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnVariantVoid                                 , 0x4A8)
        SCHEMA_FIELD(CEntityOutputTemplate<bool>     , m_OnVariantBool                                 , 0x4C0)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_OnVariantInt                                  , 0x4E0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnVariantFloat                                , 0x500)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlSymbolLarge>, m_OnVariantString                               , 0x520)
        SCHEMA_FIELD(CEntityOutputTemplate<Color>    , m_OnVariantColor                                , 0x540)
        SCHEMA_FIELD(CEntityOutputTemplate<Vector>   , m_OnVariantVector                               , 0x560)
        SCHEMA_FIELD(bool                            , m_bAllowEmptyInputs                             , 0x588)
        SCHEMA_FIELD(CTestPulseIOComponent_Derived   , m_TestComponent                                 , 0x590)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnInternalTestVoid                            , 0x5C0)
        SCHEMA_FIELD(CEntityOutputTemplate<bool>     , m_OnInternalTestBool                            , 0x5D8)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_OnInternalTestInt                             , 0x5F8)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnInternalTestFloat                           , 0x618)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlSymbolLarge>, m_OnInternalTestString                          , 0x638)
        SCHEMA_FIELD(CEntityOutputTemplate<Color>    , m_OnInternalTestColor                           , 0x658)
        SCHEMA_FIELD(CEntityOutputTemplate<Vector>   , m_OnInternalTestVector                          , 0x678)
        SCHEMA_FIELD(CEntityOutputTemplate<CEntityNameString>, m_OnInternalTestEntityName                      , 0x6A0)
        SCHEMA_FIELD(CEntityOutputTemplate<CHandle<CBaseEntity>>, m_OnInternalTestEntityHandle                    , 0x6C0)
        SCHEMA_FIELD(CEntityOutputTemplate<TestInputOutputCombinationsEnum_t>, m_OnInternalTestSchemaEnum                      , 0x6E0)
        SCHEMA_FIELD(CEntityOutputTemplate<CTestPulseIO_FloatStringArgs_t>, m_OnInternalTestFloatString                     , 0x700)
        SCHEMA_FIELD(CEntityOutputTemplate<CTestPulseIO_EntityNameStringArgs_t>, m_OnInternalTestEntityNameString                , 0x728)
        SCHEMA_FIELD(CEntityOutputTemplate<CTestPulseIO_EntityHandleIntArgs_t>, m_OnInternalTestEntityHandleInt                 , 0x750)
        SCHEMA_FIELD(CEntityOutputTemplate<CTestPulseIO_ThreeStringArgs_t>, m_OnInternalTestStringStringString              , 0x770)
    };

    class CLogicPlayerProxy : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_PlayerHasAmmo                                 , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_PlayerHasNoAmmo                               , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_PlayerDied                                    , 0x4D8)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_RequestedPlayerHealth                         , 0x4F0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hPlayer                                       , 0x510)
    };

    class CLogicEventListener : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strEventName                                  , 0x4B8)
        SCHEMA_FIELD(bool                            , m_bIsEnabled                                    , 0x4C0)
        SCHEMA_FIELD(std::int32_t                    , m_nTeam                                         , 0x4C4)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlString>, m_OnEventFired                                  , 0x4C8)
    };

    class CMathColorBlend : public CLogicalEntity {
    public:
        SCHEMA_FIELD(float                           , m_flInMin                                       , 0x4A8)
        SCHEMA_FIELD(float                           , m_flInMax                                       , 0x4AC)
        SCHEMA_FIELD(::Color                         , m_OutColor1                                     , 0x4B0)
        SCHEMA_FIELD(::Color                         , m_OutColor2                                     , 0x4B4)
        SCHEMA_FIELD(CEntityOutputTemplate<Color>    , m_OutValue                                      , 0x4B8)
    };

    class CLogicDistanceCheck : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEntityA                                    , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEntityB                                    , 0x4B0)
        SCHEMA_FIELD(float                           , m_flZone1Distance                               , 0x4B8)
        SCHEMA_FIELD(float                           , m_flZone2Distance                               , 0x4BC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_InZone1                                       , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_InZone2                                       , 0x4D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_InZone3                                       , 0x4F0)
    };

    class CLogicDistanceAutosave : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTargetEntity                               , 0x4A8)
        SCHEMA_FIELD(float                           , m_flDistanceToPlayer                            , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bForceNewLevelUnit                            , 0x4B4)
        SCHEMA_FIELD(bool                            , m_bCheckCough                                   , 0x4B5)
        SCHEMA_FIELD(bool                            , m_bThinkDangerous                               , 0x4B6)
        SCHEMA_FIELD(float                           , m_flDangerousTime                               , 0x4B8)
    };

    class CLogicBranch : public CLogicalEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bInValue                                      , 0x4A8)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_Listeners                                     , 0x4B0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTrue                                        , 0x4C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFalse                                       , 0x4E0)
    };

    class CMultiSource : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_rgEntities                                    , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_rgTriggered                                   , 0x528)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTrigger                                     , 0x5A8)
        SCHEMA_FIELD(std::int32_t                    , m_iTotal                                        , 0x5C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_globalstate                                   , 0x5C8)
    };

    class CLogicGameEventListener : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEventFired                                  , 0x4B8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszGameEventName                              , 0x4D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszGameEventItem                              , 0x4D8)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4E0)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x4E1)
    };

    class CLogicAutosave : public CLogicalEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bForceNewLevelUnit                            , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_minHitPoints                                  , 0x4AC)
        SCHEMA_FIELD(std::int32_t                    , m_minHitPointsToCommit                          , 0x4B0)
    };

    class CEnvGlobal : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_outCounter                                    , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_globalstate                                   , 0x4C8)
        SCHEMA_FIELD(std::int32_t                    , m_triggermode                                   , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_initialstate                                  , 0x4D4)
        SCHEMA_FIELD(std::int32_t                    , m_counter                                       , 0x4D8)
    };

    class CMapSharedEnvironment : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_targetMapName                                 , 0x4A8)
    };

    class CSoundStackSave : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStackName                                  , 0x4A8)
    };

    class CLogicMeasureMovement : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strMeasureTarget                              , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strMeasureReference                           , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strTargetReference                            , 0x4B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hMeasureTarget                                , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hMeasureReference                             , 0x4C4)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTarget                                       , 0x4C8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetReference                              , 0x4CC)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x4D0)
        SCHEMA_FIELD(std::int32_t                    , m_nMeasureType                                  , 0x4D4)
    };

    class CMultiLightProxy : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLightNameFilter                            , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLightClassFilter                           , 0x4B0)
        SCHEMA_FIELD(float                           , m_flLightRadiusFilter                           , 0x4B8)
        SCHEMA_FIELD(float                           , m_flBrightnessDelta                             , 0x4BC)
        SCHEMA_FIELD(bool                            , m_bPerformScreenFade                            , 0x4C0)
        SCHEMA_FIELD(float                           , m_flTargetBrightnessMultiplier                  , 0x4C4)
        SCHEMA_FIELD(float                           , m_flCurrentBrightnessMultiplier                 , 0x4C8)
        SCHEMA_FIELD(CUtlVector<CHandle<CLightEntity>>, m_vecLights                                     , 0x4D0)
    };

    class CPointTemplate : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszWorldName                                  , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSource2EntityLumpName                      , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEntityFilterName                           , 0x4B8)
        SCHEMA_FIELD(float                           , m_flTimeoutInterval                             , 0x4C0)
        SCHEMA_FIELD(bool                            , m_bAsynchronouslySpawnEntities                  , 0x4C4)
        SCHEMA_FIELD(PointTemplateClientOnlyEntityBehavior_t, m_clientOnlyEntityBehavior                      , 0x4C8)
        SCHEMA_FIELD(PointTemplateOwnerSpawnGroupType_t, m_ownerSpawnGroupType                           , 0x4CC)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_createdSpawnGroupHandles                      , 0x4D0)
        SCHEMA_FIELD(CUtlVector<CEntityHandle>       , m_SpawnedEntityHandles                          , 0x4E8)
        SCHEMA_FIELD(HSCRIPT                         , m_ScriptSpawnCallback                           , 0x500)
        SCHEMA_FIELD(HSCRIPT                         , m_ScriptCallbackScope                           , 0x508)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlVector<CEntityHandle>>, m_OnEntitySpawned                               , 0x510)
    };

    class CPhysicsEntitySolver : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hMovingEntity                                 , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hPhysicsBlocker                               , 0x4C4)
        SCHEMA_FIELD(float                           , m_separationDuration                            , 0x4C8)
        SCHEMA_FIELD(::GameTime_t                    , m_cancelTime                                    , 0x4CC)
    };

    class CLogicCollisionPair : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttach1                                   , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttach2                                   , 0x4B0)
        SCHEMA_FIELD(bool                            , m_includeHierarchy                              , 0x4B8)
        SCHEMA_FIELD(bool                            , m_supportMultipleEntitiesWithSameName           , 0x4B9)
        SCHEMA_FIELD(bool                            , m_disabled                                      , 0x4BA)
        SCHEMA_FIELD(bool                            , m_succeeded                                     , 0x4BB)
    };

    class CMathRemap : public CLogicalEntity {
    public:
        SCHEMA_FIELD(float                           , m_flInMin                                       , 0x4A8)
        SCHEMA_FIELD(float                           , m_flInMax                                       , 0x4AC)
        SCHEMA_FIELD(float                           , m_flOut1                                        , 0x4B0)
        SCHEMA_FIELD(float                           , m_flOut2                                        , 0x4B4)
        SCHEMA_FIELD(float                           , m_flOldInValue                                  , 0x4B8)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x4BC)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OutValue                                      , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnRoseAboveMin                                , 0x4E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnRoseAboveMax                                , 0x4F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFellBelowMin                                , 0x510)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFellBelowMax                                , 0x528)
    };

    class CTimerEntity : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTimer                                       , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTimerHigh                                   , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTimerLow                                    , 0x4D8)
        SCHEMA_FIELD(std::int32_t                    , m_iDisabled                                     , 0x4F0)
        SCHEMA_FIELD(float                           , m_flInitialDelay                                , 0x4F4)
        SCHEMA_FIELD(float                           , m_flRefireTime                                  , 0x4F8)
        SCHEMA_FIELD(bool                            , m_bUpDownState                                  , 0x4FC)
        SCHEMA_FIELD(std::int32_t                    , m_iUseRandomTime                                , 0x500)
        SCHEMA_FIELD(bool                            , m_bPauseAfterFiring                             , 0x504)
        SCHEMA_FIELD(float                           , m_flLowerRandomBound                            , 0x508)
        SCHEMA_FIELD(float                           , m_flUpperRandomBound                            , 0x50C)
        SCHEMA_FIELD(float                           , m_flRemainingTime                               , 0x510)
        SCHEMA_FIELD(bool                            , m_bPaused                                       , 0x514)
    };

    class CPathMoverEntitySpawner : public CLogicalEntity {
    public:
        using _Type0 = CUtlHashtable<CHandle<CFuncMover>,PathMoverEntitySpawn>;
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szSpawnTemplates                              , 0x4A8)
        SCHEMA_FIELD(std::int32_t                    , m_nSpawnIndex                                   , 0x4C8)
        SCHEMA_FIELD(CHandle<CPathMover>             , m_hPathMover                                    , 0x4CC)
        SCHEMA_FIELD(float                           , m_flSpawnFrequencySeconds                       , 0x4D0)
        SCHEMA_FIELD(float                           , m_flSpawnFrequencyDistToNearestMover            , 0x4D4)
        SCHEMA_FIELD(_Type0                          , m_mapSpawnedMoverTemplates                      , 0x4D8)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxActive                                    , 0x4F8)
        SCHEMA_FIELD(std::int32_t                    , m_nSpawnNum                                     , 0x4FC)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastSpawnTime                               , 0x500)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x504)
        SCHEMA_FIELD(bool                            , m_bDestroyMoverOnArrivedAtEnd                   , 0x505)
        SCHEMA_FIELD(CUtlVector<CHandle<CFuncMover>> , m_vecQueuedRemovals                             , 0x508)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTemplateSpawned                             , 0x520)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTemplateGroupSpawned                        , 0x538)
    };

    class CMathCounter : public CLogicalEntity {
    public:
        SCHEMA_FIELD(float                           , m_flMin                                         , 0x4A8)
        SCHEMA_FIELD(float                           , m_flMax                                         , 0x4AC)
        SCHEMA_FIELD(bool                            , m_bHitMin                                       , 0x4B0)
        SCHEMA_FIELD(bool                            , m_bHitMax                                       , 0x4B1)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4B2)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OutValue                                      , 0x4B8)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnGetValue                                    , 0x4D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnHitMin                                      , 0x4F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnHitMax                                      , 0x510)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnChangedFromMin                              , 0x528)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnChangedFromMax                              , 0x540)
    };

    class CPhysConstraint : public CLogicalEntity {
    public:
        SCHEMA_FIELD(IPhysicsJoint*                  , m_hJoint                                        , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttach1                                   , 0x4B0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttach2                                   , 0x4B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAttach1                                      , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAttach2                                      , 0x4C4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttachment1                               , 0x4C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttachment2                               , 0x4D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_breakSound                                    , 0x4D8)
        SCHEMA_FIELD(float                           , m_forceLimit                                    , 0x4E0)
        SCHEMA_FIELD(float                           , m_torqueLimit                                   , 0x4E4)
        SCHEMA_FIELD(float                           , m_minTeleportDistance                           , 0x4E8)
        SCHEMA_FIELD(bool                            , m_bSnapObjectPositions                          , 0x4EC)
        SCHEMA_FIELD(bool                            , m_bTreatEntity1AsInfiniteMass                   , 0x4ED)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBreak                                       , 0x4F0)
    };

    class CLogicAchievement : public CLogicalEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszAchievementEventID                         , 0x4B0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFired                                       , 0x4B8)
    };

    class CLogicLineToEntity : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityOutputTemplate<Vector>   , m_Line                                          , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SourceName                                    , 0x4D0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_StartEntity                                   , 0x4D8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_EndEntity                                     , 0x4DC)
    };

    class CInfoSpawnGroupLoadUnload : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnSpawnGroupLoadStarted                       , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnSpawnGroupLoadFinished                      , 0x4C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnSpawnGroupUnloadStarted                     , 0x4D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnSpawnGroupUnloadFinished                    , 0x4F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpawnGroupName                             , 0x508)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpawnGroupFilterName                       , 0x510)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLandmarkName                               , 0x518)
        SCHEMA_FIELD(::CUtlString                    , m_sFixedSpawnGroupName                          , 0x520)
        SCHEMA_FIELD(float                           , m_flTimeoutInterval                             , 0x528)
        SCHEMA_FIELD(bool                            , m_bAutoActivate                                 , 0x52C)
        SCHEMA_FIELD(bool                            , m_bUnloadingStarted                             , 0x52D)
        SCHEMA_FIELD(bool                            , m_bQueueActiveSpawnGroupChange                  , 0x52E)
        SCHEMA_FIELD(bool                            , m_bQueueFinishLoading                           , 0x52F)
    };

    class CPhysMotor : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAttach                                    , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nameAnchor                                    , 0x4B0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAttachedObject                               , 0x4B8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hAnchorObject                                 , 0x4BC)
        SCHEMA_FIELD(float                           , m_spinUp                                        , 0x4C0)
        SCHEMA_FIELD(float                           , m_spinDown                                      , 0x4C4)
        SCHEMA_FIELD(float                           , m_flMotorFriction                               , 0x4C8)
        SCHEMA_FIELD(float                           , m_additionalAcceleration                        , 0x4CC)
        SCHEMA_FIELD(float                           , m_angularAcceleration                           , 0x4D0)
        SCHEMA_FIELD(float                           , m_flTorqueScale                                 , 0x4D4)
        SCHEMA_FIELD(float                           , m_flTargetSpeed                                 , 0x4D8)
        SCHEMA_FIELD(float                           , m_flSpeedWhenSpinUpOrSpinDownStarted            , 0x4DC)
        SCHEMA_FIELD(IPhysicsBody*                   , m_pFixedWorldBody                               , 0x4E0)
        SCHEMA_FIELD(IPhysicsJoint*                  , m_pMotorJoint                                   , 0x4E8)
        SCHEMA_FIELD(CMotorController                , m_motor                                         , 0x4F0)
    };

    class CLogicGameEvent : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEventName                                  , 0x4A8)
    };

    class CLogicCompare : public CLogicalEntity {
    public:
        SCHEMA_FIELD(float                           , m_flInValue                                     , 0x4A8)
        SCHEMA_FIELD(float                           , m_flCompareValue                                , 0x4AC)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnLessThan                                    , 0x4B0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnEqualTo                                     , 0x4D0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnNotEqualTo                                  , 0x4F0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnGreaterThan                                 , 0x510)
    };

    class CLogicNavigation : public CLogicalEntity {
    public:
        SCHEMA_FIELD(bool                            , m_isOn                                          , 0x4B0)
        SCHEMA_FIELD(navproperties_t                 , m_navProperty                                   , 0x4B4)
    };

    class CPathKeyFrame : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_Origin                                        , 0x4A8)
        SCHEMA_FIELD(::QAngle                        , m_Angles                                        , 0x4B4)
        SCHEMA_FIELD(::Quaternion                    , m_qAngle                                        , 0x4C0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iNextKey                                      , 0x4D0)
        SCHEMA_FIELD(float                           , m_flNextTime                                    , 0x4D8)
        SCHEMA_FIELD(CHandle<CPathKeyFrame>          , m_pNextKey                                      , 0x4DC)
        SCHEMA_FIELD(CHandle<CPathKeyFrame>          , m_pPrevKey                                      , 0x4E0)
        SCHEMA_FIELD(float                           , m_flMoveSpeed                                   , 0x4E4)
    };

    class CSceneListManager : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CUtlVector<CHandle<CSceneListManager>>, m_hListManagers                                 , 0x4A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszScenes                                     , 0x4C0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hScenes                                       , 0x540)
    };

    class CBaseFilter : public CLogicalEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bNegated                                      , 0x4A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPass                                        , 0x4B0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFail                                        , 0x4C8)
    };

    class CEnvFade : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::Color                         , m_fadeColor                                     , 0x4A8)
        SCHEMA_FIELD(float                           , m_Duration                                      , 0x4AC)
        SCHEMA_FIELD(float                           , m_HoldDuration                                  , 0x4B0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBeginFade                                   , 0x4B8)
    };

    class CLogicBranchList : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_nLogicBranchNames                             , 0x4A8)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_LogicBranchList                               , 0x528)
        SCHEMA_FIELD(CLogicBranchList_LogicBranchListenerLastState_t, m_eLastState                                    , 0x540)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAllTrue                                     , 0x548)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAllFalse                                    , 0x560)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMixed                                       , 0x578)
    };

    class CFuncMoveLinear : public CBaseToggle {
    public:
        SCHEMA_FIELD(MoveLinearAuthoredPos_t         , m_authoredPosition                              , 0x7E8)
        SCHEMA_FIELD(::QAngle                        , m_angMoveEntitySpace                            , 0x7EC)
        SCHEMA_FIELD(::Vector                        , m_vecMoveDirParentSpace                         , 0x7F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_soundStart                                    , 0x808)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_soundStop                                     , 0x810)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_currentSound                                  , 0x818)
        SCHEMA_FIELD(float                           , m_flBlockDamage                                 , 0x820)
        SCHEMA_FIELD(float                           , m_flStartPosition                               , 0x824)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyOpen                                   , 0x830)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyClosed                                 , 0x848)
        SCHEMA_FIELD(bool                            , m_bCreateMovableNavMesh                         , 0x860)
        SCHEMA_FIELD(bool                            , m_bAllowMovableNavMeshDockingOnEntireEntity     , 0x861)
        SCHEMA_FIELD(bool                            , m_bCreateNavObstacle                            , 0x862)
    };

    class CBaseTrigger : public CBaseToggle {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartTouch                                  , 0x7E8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartTouchAll                               , 0x800)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEndTouch                                    , 0x818)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEndTouchAll                                 , 0x830)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTouching                                    , 0x848)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTouchingEachEntity                          , 0x860)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnNotTouching                                 , 0x878)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hTouchingEntities                             , 0x890)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x8A8)
        SCHEMA_FIELD(CHandle<CBaseFilter>            , m_hFilter                                       , 0x8B0)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x8B4)
        SCHEMA_FIELD(bool                            , m_bUseAsyncQueries                              , 0x8C0)
    };

    class CBasePlatTrain : public CBaseToggle {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_NoiseMoving                                   , 0x7E8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_NoiseArrived                                  , 0x7F0)
        SCHEMA_FIELD(float                           , m_volume                                        , 0x800)
        SCHEMA_FIELD(float                           , m_flTWidth                                      , 0x804)
        SCHEMA_FIELD(float                           , m_flTLength                                     , 0x808)
    };

    class CBaseButton : public CBaseToggle {
    public:
        SCHEMA_FIELD(::QAngle                        , m_angMoveEntitySpace                            , 0x7E8)
        SCHEMA_FIELD(bool                            , m_fStayPushed                                   , 0x7F4)
        SCHEMA_FIELD(bool                            , m_fRotating                                     , 0x7F5)
        SCHEMA_FIELD(locksound_t                     , m_ls                                            , 0x7F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sUseSound                                     , 0x818)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sLockedSound                                  , 0x820)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sUnlockedSound                                , 0x828)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sOverrideAnticipationName                     , 0x830)
        SCHEMA_FIELD(bool                            , m_bLocked                                       , 0x838)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x839)
        SCHEMA_FIELD(::GameTime_t                    , m_flUseLockedTime                               , 0x83C)
        SCHEMA_FIELD(bool                            , m_bSolidBsp                                     , 0x840)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDamaged                                     , 0x848)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPressed                                     , 0x860)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUseLocked                                   , 0x878)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnIn                                          , 0x890)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOut                                         , 0x8A8)
        SCHEMA_FIELD(std::int32_t                    , m_nState                                        , 0x8C0)
        SCHEMA_FIELD(CEntityHandle                   , m_hConstraint                                   , 0x8C4)
        SCHEMA_FIELD(CEntityHandle                   , m_hConstraintParent                             , 0x8C8)
        SCHEMA_FIELD(bool                            , m_bForceNpcExclude                              , 0x8CC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sGlowEntity                                   , 0x8D0)
        SCHEMA_FIELD(CHandle<CBaseModelEntity>       , m_glowEntity                                    , 0x8D8)
        SCHEMA_FIELD(bool                            , m_usable                                        , 0x8DC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szDisplayText                                 , 0x8E0)
    };

    class CGunTarget : public CBaseToggle {
    public:
        SCHEMA_FIELD(bool                            , m_on                                            , 0x7E8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetEnt                                    , 0x7EC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDeath                                       , 0x7F0)
    };

    class CBaseDoor : public CBaseToggle {
    public:
        SCHEMA_FIELD(::QAngle                        , m_angMoveEntitySpace                            , 0x7F8)
        SCHEMA_FIELD(::Vector                        , m_vecMoveDirParentSpace                         , 0x804)
        SCHEMA_FIELD(locksound_t                     , m_ls                                            , 0x810)
        SCHEMA_FIELD(bool                            , m_bForceClosed                                  , 0x830)
        SCHEMA_FIELD(bool                            , m_bDoorGroup                                    , 0x831)
        SCHEMA_FIELD(bool                            , m_bLocked                                       , 0x832)
        SCHEMA_FIELD(bool                            , m_bIgnoreDebris                                 , 0x833)
        SCHEMA_FIELD(bool                            , m_bNoNPCs                                       , 0x834)
        SCHEMA_FIELD(FuncDoorSpawnPos_t              , m_eSpawnPosition                                , 0x838)
        SCHEMA_FIELD(float                           , m_flBlockDamage                                 , 0x83C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_NoiseMoving                                   , 0x840)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_NoiseArrived                                  , 0x848)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_NoiseMovingClosed                             , 0x850)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_NoiseArrivedClosed                            , 0x858)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_ChainTarget                                   , 0x860)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBlockedClosing                              , 0x868)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBlockedOpening                              , 0x880)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUnblockedClosing                            , 0x898)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUnblockedOpening                            , 0x8B0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyClosed                                 , 0x8C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyOpen                                   , 0x8E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnClose                                       , 0x8F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOpen                                        , 0x910)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLockedUse                                   , 0x928)
        SCHEMA_FIELD(bool                            , m_bLoopMoveSound                                , 0x940)
        SCHEMA_FIELD(bool                            , m_bCreateNavObstacle                            , 0x960)
        SCHEMA_FIELD(bool                            , m_isChaining                                    , 0x961)
        SCHEMA_FIELD(bool                            , m_bIsUsable                                     , 0x962)
    };

    class CFireCrackerBlast : public CInferno {
    public:
    };

    class CRopeKeyframeAlias_move_rope : public CRopeKeyframe {
    public:
    };

    class CLightSpotEntity : public CLightEntity {
    public:
    };

    class CLightOrthoEntity : public CLightEntity {
    public:
    };

    class CLightDirectionalEntity : public CLightEntity {
    public:
    };

    class CPointWorldText : public CModelPointEntity {
    public:
        SCHEMA_FIELD(char                            , m_messageText                                   , 0x768)
        SCHEMA_FIELD(char                            , m_FontName                                      , 0x968)
        SCHEMA_FIELD(char                            , m_BackgroundMaterialName                        , 0x9A8)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x9E8)
        SCHEMA_FIELD(bool                            , m_bFullbright                                   , 0x9E9)
        SCHEMA_FIELD(float                           , m_flWorldUnitsPerPx                             , 0x9EC)
        SCHEMA_FIELD(float                           , m_flFontSize                                    , 0x9F0)
        SCHEMA_FIELD(float                           , m_flDepthOffset                                 , 0x9F4)
        SCHEMA_FIELD(bool                            , m_bDrawBackground                               , 0x9F8)
        SCHEMA_FIELD(float                           , m_flBackgroundBorderWidth                       , 0x9FC)
        SCHEMA_FIELD(float                           , m_flBackgroundBorderHeight                      , 0xA00)
        SCHEMA_FIELD(float                           , m_flBackgroundWorldToUV                         , 0xA04)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0xA08)
        SCHEMA_FIELD(PointWorldTextJustifyHorizontal_t, m_nJustifyHorizontal                            , 0xA0C)
        SCHEMA_FIELD(PointWorldTextJustifyVertical_t , m_nJustifyVertical                              , 0xA10)
        SCHEMA_FIELD(PointWorldTextReorientMode_t    , m_nReorientMode                                 , 0xA14)
    };

    class CEnvExplosion : public CModelPointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iMagnitude                                    , 0x768)
        SCHEMA_FIELD(float                           , m_flPlayerDamage                                , 0x76C)
        SCHEMA_FIELD(std::int32_t                    , m_iRadiusOverride                               , 0x770)
        SCHEMA_FIELD(float                           , m_flInnerRadius                                 , 0x774)
        SCHEMA_FIELD(float                           , m_flDamageForce                                 , 0x778)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hInflictor                                    , 0x77C)
        SCHEMA_FIELD(DamageTypes_t                   , m_iCustomDamageType                             , 0x780)
        SCHEMA_FIELD(bool                            , m_bCreateDebris                                 , 0x784)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszCustomEffectName                           , 0x790)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszCustomSoundName                            , 0x798)
        SCHEMA_FIELD(bool                            , m_bSuppressParticleImpulse                      , 0x7A0)
        SCHEMA_FIELD(Class_T                         , m_iClassIgnore                                  , 0x7A4)
        SCHEMA_FIELD(Class_T                         , m_iClassIgnore2                                 , 0x7A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEntityIgnoreName                           , 0x7B0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntityIgnore                                 , 0x7B8)
    };

    class CShower : public CModelPointEntity {
    public:
    };

    class CPlayerSprayDecal : public CModelPointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nUniqueID                                     , 0x768)
        SCHEMA_FIELD(std::uint32_t                   , m_unAccountID                                   , 0x76C)
        SCHEMA_FIELD(std::uint32_t                   , m_unTraceID                                     , 0x770)
        SCHEMA_FIELD(std::uint32_t                   , m_rtGcTime                                      , 0x774)
        SCHEMA_FIELD(::Vector                        , m_vecEndPos                                     , 0x778)
        SCHEMA_FIELD(::Vector                        , m_vecStart                                      , 0x784)
        SCHEMA_FIELD(::Vector                        , m_vecLeft                                       , 0x790)
        SCHEMA_FIELD(::Vector                        , m_vecNormal                                     , 0x79C)
        SCHEMA_FIELD(std::int32_t                    , m_nPlayer                                       , 0x7A8)
        SCHEMA_FIELD(std::int32_t                    , m_nEntity                                       , 0x7AC)
        SCHEMA_FIELD(std::int32_t                    , m_nHitbox                                       , 0x7B0)
        SCHEMA_FIELD(float                           , m_flCreationTime                                , 0x7B4)
        SCHEMA_FIELD(std::int32_t                    , m_nTintID                                       , 0x7B8)
        SCHEMA_FIELD(std::uint8_t                    , m_nVersion                                      , 0x7BC)
        SCHEMA_FIELD(std::uint8_t                    , m_ubSignature                                   , 0x7BD)
    };

    class CRevertSaved : public CModelPointEntity {
    public:
        SCHEMA_FIELD(float                           , m_loadTime                                      , 0x768)
        SCHEMA_FIELD(float                           , m_Duration                                      , 0x76C)
        SCHEMA_FIELD(float                           , m_HoldTime                                      , 0x770)
    };

    class CScriptNavBlocker : public CFuncNavBlocker {
    public:
        SCHEMA_FIELD(::Vector                        , m_vExtent                                       , 0x780)
    };

    class CFuncMonitor : public CFuncBrush {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_targetCamera                                  , 0x788)
        SCHEMA_FIELD(std::int32_t                    , m_nResolutionEnum                               , 0x790)
        SCHEMA_FIELD(bool                            , m_bRenderShadows                                , 0x794)
        SCHEMA_FIELD(bool                            , m_bUseUniqueColorTarget                         , 0x795)
        SCHEMA_FIELD(::CUtlString                    , m_brushModelName                                , 0x798)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hTargetCamera                                 , 0x7A0)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x7A4)
        SCHEMA_FIELD(bool                            , m_bDraw3DSkybox                                 , 0x7A5)
        SCHEMA_FIELD(bool                            , m_bStartEnabled                                 , 0x7A6)
    };

    class CFuncElectrifiedVolume : public CFuncBrush {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_EffectName                                    , 0x788)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_EffectInterpenetrateName                      , 0x790)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_EffectZapName                                 , 0x798)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEffectSource                               , 0x7A0)
    };

    class CEnvParticleGlow : public CParticleSystem {
    public:
        SCHEMA_FIELD(float                           , m_flAlphaScale                                  , 0xCE0)
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0xCE4)
        SCHEMA_FIELD(float                           , m_flSelfIllumScale                              , 0xCE8)
        SCHEMA_FIELD(::Color                         , m_ColorTint                                     , 0xCEC)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hTextureOverride                              , 0xCF0)
    };

    class CEnvBeam : public CBeam {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_active                                        , 0x808)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_spriteTexture                                 , 0x810)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStartEntity                                , 0x818)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEndEntity                                  , 0x820)
        SCHEMA_FIELD(float                           , m_life                                          , 0x828)
        SCHEMA_FIELD(float                           , m_boltWidth                                     , 0x82C)
        SCHEMA_FIELD(float                           , m_noiseAmplitude                                , 0x830)
        SCHEMA_FIELD(std::int32_t                    , m_speed                                         , 0x834)
        SCHEMA_FIELD(float                           , m_restrike                                      , 0x838)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpriteName                                 , 0x840)
        SCHEMA_FIELD(std::int32_t                    , m_frameStart                                    , 0x848)
        SCHEMA_FIELD(VectorWS                        , m_vEndPointWorld                                , 0x84C)
        SCHEMA_FIELD(::Vector                        , m_vEndPointRelative                             , 0x858)
        SCHEMA_FIELD(float                           , m_radius                                        , 0x864)
        SCHEMA_FIELD(Touch_t                         , m_TouchType                                     , 0x868)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x870)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hFilter                                       , 0x878)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszDecal                                      , 0x880)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTouchedByEntity                             , 0x888)
    };

    class CEnvLaser : public CBeam {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLaserTarget                                , 0x808)
        SCHEMA_FIELD(CHandle<CSprite>                , m_pSprite                                       , 0x810)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpriteName                                 , 0x818)
        SCHEMA_FIELD(::Vector                        , m_firePosition                                  , 0x820)
        SCHEMA_FIELD(float                           , m_flStartFrame                                  , 0x82C)
    };

    class CFuncTankTrain : public CFuncTrackTrain {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDeath                                       , 0x890)
    };

    class CMarkupVolumeTagged : public CMarkupVolume {
    public:
        SCHEMA_FIELD(CUtlVector<CGlobalSymbol>       , m_GroupNames                                    , 0x770)
        SCHEMA_FIELD(CUtlVector<CGlobalSymbol>       , m_Tags                                          , 0x788)
        SCHEMA_FIELD(bool                            , m_bIsGroup                                      , 0x7A0)
        SCHEMA_FIELD(bool                            , m_bGroupByPrefab                                , 0x7A1)
        SCHEMA_FIELD(bool                            , m_bGroupByVolume                                , 0x7A2)
        SCHEMA_FIELD(bool                            , m_bGroupOtherGroups                             , 0x7A3)
        SCHEMA_FIELD(bool                            , m_bIsInGroup                                    , 0x7A4)
    };

    class CFogVolume : public CServerOnlyModelEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_fogName                                       , 0x768)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_postProcessName                               , 0x770)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_colorCorrectionName                           , 0x778)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x788)
        SCHEMA_FIELD(bool                            , m_bInFogVolumesList                             , 0x789)
    };

    class CCSPlace : public CServerOnlyModelEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_name                                          , 0x780)
    };

    class CRuleBrushEntity : public CRuleEntity {
    public:
    };

    class CRulePointEntity : public CRuleEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_Score                                         , 0x770)
    };

    class CFuncLadderAlias_func_useableladder : public CFuncLadder {
    public:
    };

    class CFuncWallToggle : public CFuncWall {
    public:
    };

    class CCSSprite : public CSprite {
    public:
    };

    class CSpriteOriented : public CSprite {
    public:
    };

    class CCommentaryViewPosition : public CSprite {
    public:
    };

    class CSpriteAlias_env_glow : public CSprite {
    public:
    };

    class CFish : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(CHandle<CFishPool>              , m_pool                                          , 0x940)
        SCHEMA_FIELD(std::uint32_t                   , m_id                                            , 0x944)
        SCHEMA_FIELD(float                           , m_x                                             , 0x948)
        SCHEMA_FIELD(float                           , m_y                                             , 0x94C)
        SCHEMA_FIELD(float                           , m_z                                             , 0x950)
        SCHEMA_FIELD(float                           , m_angle                                         , 0x954)
        SCHEMA_FIELD(float                           , m_angleChange                                   , 0x958)
        SCHEMA_FIELD(::Vector                        , m_forward                                       , 0x95C)
        SCHEMA_FIELD(::Vector                        , m_perp                                          , 0x968)
        SCHEMA_FIELD(::Vector                        , m_poolOrigin                                    , 0x974)
        SCHEMA_FIELD(float                           , m_waterLevel                                    , 0x980)
        SCHEMA_FIELD(float                           , m_speed                                         , 0x984)
        SCHEMA_FIELD(float                           , m_desiredSpeed                                  , 0x988)
        SCHEMA_FIELD(float                           , m_calmSpeed                                     , 0x98C)
        SCHEMA_FIELD(float                           , m_panicSpeed                                    , 0x990)
        SCHEMA_FIELD(float                           , m_avoidRange                                    , 0x994)
        SCHEMA_FIELD(CountdownTimer                  , m_turnTimer                                     , 0x998)
        SCHEMA_FIELD(bool                            , m_turnClockwise                                 , 0x9B0)
        SCHEMA_FIELD(CountdownTimer                  , m_goTimer                                       , 0x9B8)
        SCHEMA_FIELD(CountdownTimer                  , m_moveTimer                                     , 0x9D0)
        SCHEMA_FIELD(CountdownTimer                  , m_panicTimer                                    , 0x9E8)
        SCHEMA_FIELD(CountdownTimer                  , m_disperseTimer                                 , 0xA00)
        SCHEMA_FIELD(CountdownTimer                  , m_proximityTimer                                , 0xA18)
        SCHEMA_FIELD(CUtlVector<CFish*>              , m_visible                                       , 0xA30)
    };

    class CBaseCombatCharacter : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bForceServerRagdoll                           , 0x940)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CHandle<CEconWearable>>, m_hMyWearables                                  , 0x948)
        SCHEMA_FIELD(float                           , m_impactEnergyScale                             , 0x960)
        SCHEMA_FIELD(bool                            , m_bApplyStressDamage                            , 0x964)
        SCHEMA_FIELD(bool                            , m_bDeathEventsDispatched                        , 0x965)
        SCHEMA_FIELD(CUtlVector<RelationshipOverride_t>*, m_pVecRelationships                             , 0x9A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strRelationships                              , 0x9B0)
        SCHEMA_FIELD(Hull_t                          , m_eHull                                         , 0x9B8)
        SCHEMA_FIELD(std::uint32_t                   , m_nNavHullIdx                                   , 0x9BC)
        SCHEMA_FIELD(CMovementStatsProperty          , m_movementStats                                 , 0x9C0)
    };

    class CWaterBullet : public CBaseAnimGraph {
    public:
    };

    class CItemSoda : public CBaseAnimGraph {
    public:
    };

    class CEconEntity : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(CAttributeContainer             , m_AttributeManager                              , 0x958)
        SCHEMA_FIELD(std::uint32_t                   , m_OriginalOwnerXuidLow                          , 0xC50)
        SCHEMA_FIELD(std::uint32_t                   , m_OriginalOwnerXuidHigh                         , 0xC54)
        SCHEMA_FIELD(std::int32_t                    , m_nFallbackPaintKit                             , 0xC58)
        SCHEMA_FIELD(std::int32_t                    , m_nFallbackSeed                                 , 0xC5C)
        SCHEMA_FIELD(float                           , m_flFallbackWear                                , 0xC60)
        SCHEMA_FIELD(std::int32_t                    , m_nFallbackStatTrak                             , 0xC64)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hOldProvidee                                  , 0xC68)
        SCHEMA_FIELD(std::int32_t                    , m_iOldOwnerClass                                , 0xC6C)
    };

    class CConstraintAnchor : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(float                           , m_massScale                                     , 0x940)
    };

    class CPhysMagnet : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMagnetAttach                                , 0x940)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMagnetDetach                                , 0x958)
        SCHEMA_FIELD(float                           , m_massScale                                     , 0x970)
        SCHEMA_FIELD(float                           , m_forceLimit                                    , 0x974)
        SCHEMA_FIELD(float                           , m_torqueLimit                                   , 0x978)
        SCHEMA_FIELD(CUtlVector<magnetted_objects_t> , m_MagnettedEntities                             , 0x980)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x998)
        SCHEMA_FIELD(bool                            , m_bHasHitSomething                              , 0x999)
        SCHEMA_FIELD(float                           , m_flTotalMass                                   , 0x99C)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x9A0)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextSuckTime                                , 0x9A4)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxObjectsAttached                           , 0x9A8)
    };

    class CHostageCarriableProp : public CBaseAnimGraph {
    public:
    };

    class CItem : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerTouch                                 , 0x948)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerPickup                                , 0x960)
        SCHEMA_FIELD(bool                            , m_bActivateWhenAtRest                           , 0x978)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnCacheInteraction                            , 0x980)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnGlovePulled                                 , 0x998)
        SCHEMA_FIELD(VectorWS                        , m_vOriginalSpawnOrigin                          , 0x9B0)
        SCHEMA_FIELD(::QAngle                        , m_vOriginalSpawnAngles                          , 0x9BC)
        SCHEMA_FIELD(bool                            , m_bPhysStartAsleep                              , 0x9C8)
    };

    class CBaseProp : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bModelOverrodeBlockLOS                        , 0x940)
        SCHEMA_FIELD(std::int32_t                    , m_iShapeType                                    , 0x944)
        SCHEMA_FIELD(bool                            , m_bConformToCollisionBounds                     , 0x948)
        SCHEMA_FIELD(CTransform                      , m_mPreferredCatchTransform                      , 0x950)
    };

    class CBaseGrenade : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerPickup                                , 0x948)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnExplode                                     , 0x960)
        SCHEMA_FIELD(bool                            , m_bHasWarnedAI                                  , 0x978)
        SCHEMA_FIELD(bool                            , m_bIsSmokeGrenade                               , 0x979)
        SCHEMA_FIELD(bool                            , m_bIsLive                                       , 0x97A)
        SCHEMA_FIELD(float                           , m_DmgRadius                                     , 0x97C)
        SCHEMA_FIELD(::GameTime_t                    , m_flDetonateTime                                , 0x980)
        SCHEMA_FIELD(float                           , m_flWarnAITime                                  , 0x984)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0x988)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszBounceSound                                , 0x990)
        SCHEMA_FIELD(::CUtlString                    , m_ExplosionSound                                , 0x998)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hThrower                                      , 0x9A0)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextAttack                                  , 0x9B8)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hOriginalThrower                              , 0x9BC)
    };

    class CRagdollProp : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(ragdoll_t                       , m_ragdoll                                       , 0x950)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x9A0)
        SCHEMA_FIELD(CNetworkUtlVectorBase<bool>     , m_ragEnabled                                    , 0x9A8)
        SCHEMA_FIELD(CNetworkUtlVectorBase<Vector>   , m_ragPos                                        , 0x9C0)
        SCHEMA_FIELD(CNetworkUtlVectorBase<QAngle>   , m_ragAngles                                     , 0x9D8)
        SCHEMA_FIELD(std::uint32_t                   , m_lastUpdateTickCount                           , 0x9F0)
        SCHEMA_FIELD(bool                            , m_allAsleep                                     , 0x9F4)
        SCHEMA_FIELD(bool                            , m_bFirstCollisionAfterLaunch                    , 0x9F5)
        SCHEMA_FIELD(INavObstacle_NavObstacleType_t  , m_nNavObstacleType                              , 0x9F8)
        SCHEMA_FIELD(bool                            , m_bUpdateNavWhenMoving                          , 0x9FC)
        SCHEMA_FIELD(bool                            , m_bForceNavObstacleCut                          , 0x9FD)
        SCHEMA_FIELD(bool                            , m_bAttachedToReferenceFrame                     , 0x9FE)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hDamageEntity                                 , 0xA00)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hKiller                                       , 0xA04)
        SCHEMA_FIELD(CHandle<CBasePlayerPawn>        , m_hPhysicsAttacker                              , 0xA08)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastPhysicsInfluenceTime                    , 0xA0C)
        SCHEMA_FIELD(::GameTime_t                    , m_flFadeOutStartTime                            , 0xA10)
        SCHEMA_FIELD(float                           , m_flFadeTime                                    , 0xA14)
        SCHEMA_FIELD(VectorWS                        , m_vecLastOrigin                                 , 0xA18)
        SCHEMA_FIELD(::GameTime_t                    , m_flAwakeTime                                   , 0xA24)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastOriginChangeTime                        , 0xA28)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strOriginClassName                            , 0xA30)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strSourceClassName                            , 0xA38)
        SCHEMA_FIELD(bool                            , m_bHasBeenPhysgunned                            , 0xA40)
        SCHEMA_FIELD(bool                            , m_bAllowStretch                                 , 0xA41)
        SCHEMA_FIELD(float                           , m_flBlendWeight                                 , 0xA44)
        SCHEMA_FIELD(float                           , m_flDefaultFadeScale                            , 0xA48)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_ragdollMins                                   , 0xA50)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_ragdollMaxs                                   , 0xA68)
        SCHEMA_FIELD(bool                            , m_bShouldDeleteActivationRecord                 , 0xA80)
        SCHEMA_FIELD(CUtlVector<INavObstacle*>       , m_vecNavObstacles                               , 0xA98)
    };

    class CPlantedC4 : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bBombTicking                                  , 0x948)
        SCHEMA_FIELD(::GameTime_t                    , m_flC4Blow                                      , 0x94C)
        SCHEMA_FIELD(std::int32_t                    , m_nBombSite                                     , 0x950)
        SCHEMA_FIELD(std::int32_t                    , m_nSourceSoundscapeHash                         , 0x954)
        SCHEMA_FIELD(bool                            , m_bAbortDetonationBecauseWorldIsFrozen          , 0x958)
        SCHEMA_FIELD(CAttributeContainer             , m_AttributeManager                              , 0x960)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBombDefused                                 , 0xC58)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBombBeginDefuse                             , 0xC70)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBombDefuseAborted                           , 0xC88)
        SCHEMA_FIELD(bool                            , m_bCannotBeDefused                              , 0xCA0)
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0xCA8)
        SCHEMA_FIELD(std::int32_t                    , m_nSpotRules                                    , 0xCC0)
        SCHEMA_FIELD(bool                            , m_bHasExploded                                  , 0xCC4)
        SCHEMA_FIELD(bool                            , m_bBombDefused                                  , 0xCC5)
        SCHEMA_FIELD(bool                            , m_bTrainingPlacedByPlayer                       , 0xCC6)
        SCHEMA_FIELD(float                           , m_flTimerLength                                 , 0xCC8)
        SCHEMA_FIELD(bool                            , m_bBeingDefused                                 , 0xCCC)
        SCHEMA_FIELD(::GameTime_t                    , m_fLastDefuseTime                               , 0xCD4)
        SCHEMA_FIELD(float                           , m_flDefuseLength                                , 0xCDC)
        SCHEMA_FIELD(::GameTime_t                    , m_flDefuseCountDown                             , 0xCE0)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hBombDefuser                                  , 0xCE4)
        SCHEMA_FIELD(std::int32_t                    , m_iProgressBarTime                              , 0xCE8)
        SCHEMA_FIELD(bool                            , m_bVoiceAlertFired                              , 0xCEC)
        SCHEMA_FIELD(bool                            , m_bVoiceAlertPlayed                             , 0xCED)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextBotBeepTime                             , 0xCF4)
        SCHEMA_FIELD(::QAngle                        , m_angCatchUpToPlayerEye                         , 0xCFC)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastSpinDetectionTime                       , 0xD08)
    };

    class CPointCommentaryNode : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPreCommands                                , 0x940)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPostCommands                               , 0x948)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszCommentaryFile                             , 0x950)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszViewTarget                                 , 0x958)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hViewTarget                                   , 0x960)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hViewTargetAngles                             , 0x964)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszViewPosition                               , 0x968)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hViewPosition                                 , 0x970)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hViewPositionMover                            , 0x974)
        SCHEMA_FIELD(bool                            , m_bPreventMovement                              , 0x978)
        SCHEMA_FIELD(bool                            , m_bUnderCrosshair                               , 0x979)
        SCHEMA_FIELD(bool                            , m_bUnstoppable                                  , 0x97A)
        SCHEMA_FIELD(::GameTime_t                    , m_flFinishedTime                                , 0x97C)
        SCHEMA_FIELD(::Vector                        , m_vecFinishOrigin                               , 0x980)
        SCHEMA_FIELD(::QAngle                        , m_vecOriginalAngles                             , 0x98C)
        SCHEMA_FIELD(::QAngle                        , m_vecFinishAngles                               , 0x998)
        SCHEMA_FIELD(bool                            , m_bPreventChangesWhileMoving                    , 0x9A4)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x9A5)
        SCHEMA_FIELD(VectorWS                        , m_vecTeleportOrigin                             , 0x9A8)
        SCHEMA_FIELD(::GameTime_t                    , m_flAbortedPlaybackAt                           , 0x9B4)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOnCommentaryStarted                          , 0x9B8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOnCommentaryStopped                          , 0x9D0)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x9E8)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x9EC)
        SCHEMA_FIELD(float                           , m_flStartTimeInCommentary                       , 0x9F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTitle                                      , 0x9F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpeakers                                   , 0xA00)
        SCHEMA_FIELD(std::int32_t                    , m_iNodeNumber                                   , 0xA08)
        SCHEMA_FIELD(std::int32_t                    , m_iNodeNumberMax                                , 0xA0C)
        SCHEMA_FIELD(bool                            , m_bListenedTo                                   , 0xA10)
    };

    class CRectLight : public CBarnLight {
    public:
        SCHEMA_FIELD(bool                            , m_bShowLight                                    , 0xA50)
    };

    class COmniLight : public CBarnLight {
    public:
        SCHEMA_FIELD(float                           , m_flInnerAngle                                  , 0xA50)
        SCHEMA_FIELD(float                           , m_flOuterAngle                                  , 0xA54)
        SCHEMA_FIELD(bool                            , m_bShowLight                                    , 0xA58)
    };

    class CPointClientUIDialog : public CBaseClientUIEntity {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hActivator                                    , 0x8C8)
        SCHEMA_FIELD(bool                            , m_bStartEnabled                                 , 0x8CC)
    };

    class CPointClientUIWorldPanel : public CBaseClientUIEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bIgnoreInput                                  , 0x8C8)
        SCHEMA_FIELD(bool                            , m_bLit                                          , 0x8C9)
        SCHEMA_FIELD(bool                            , m_bFollowPlayerAcrossTeleport                   , 0x8CA)
        SCHEMA_FIELD(float                           , m_flWidth                                       , 0x8CC)
        SCHEMA_FIELD(float                           , m_flHeight                                      , 0x8D0)
        SCHEMA_FIELD(float                           , m_flDPI                                         , 0x8D4)
        SCHEMA_FIELD(float                           , m_flInteractDistance                            , 0x8D8)
        SCHEMA_FIELD(float                           , m_flDepthOffset                                 , 0x8DC)
        SCHEMA_FIELD(std::uint32_t                   , m_unOwnerContext                                , 0x8E0)
        SCHEMA_FIELD(std::uint32_t                   , m_unHorizontalAlign                             , 0x8E4)
        SCHEMA_FIELD(std::uint32_t                   , m_unVerticalAlign                               , 0x8E8)
        SCHEMA_FIELD(std::uint32_t                   , m_unOrientation                                 , 0x8EC)
        SCHEMA_FIELD(bool                            , m_bAllowInteractionFromAllSceneWorlds           , 0x8F0)
        SCHEMA_FIELD(CNetworkUtlVectorBase<CUtlSymbolLarge>, m_vecCSSClasses                                 , 0x8F8)
        SCHEMA_FIELD(bool                            , m_bOpaque                                       , 0x910)
        SCHEMA_FIELD(bool                            , m_bNoDepth                                      , 0x911)
        SCHEMA_FIELD(bool                            , m_bVisibleWhenParentNoDraw                      , 0x912)
        SCHEMA_FIELD(bool                            , m_bRenderBackface                               , 0x913)
        SCHEMA_FIELD(bool                            , m_bUseOffScreenIndicator                        , 0x914)
        SCHEMA_FIELD(bool                            , m_bExcludeFromSaveGames                         , 0x915)
        SCHEMA_FIELD(bool                            , m_bGrabbable                                    , 0x916)
        SCHEMA_FIELD(bool                            , m_bOnlyRenderToTexture                          , 0x917)
        SCHEMA_FIELD(bool                            , m_bDisableMipGen                                , 0x918)
        SCHEMA_FIELD(std::int32_t                    , m_nExplicitImageLayout                          , 0x91C)
    };

    class CPhysBox : public CBreakable {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_damageType                                    , 0x840)
        SCHEMA_FIELD(std::int32_t                    , m_damageToEnableMotion                          , 0x844)
        SCHEMA_FIELD(float                           , m_flForceToEnableMotion                         , 0x848)
        SCHEMA_FIELD(::Vector                        , m_vHoverPosePosition                            , 0x84C)
        SCHEMA_FIELD(::QAngle                        , m_angHoverPoseAngles                            , 0x858)
        SCHEMA_FIELD(bool                            , m_bNotSolidToWorld                              , 0x864)
        SCHEMA_FIELD(bool                            , m_bEnableUseOutput                              , 0x865)
        SCHEMA_FIELD(HoverPoseFlags_t                , m_nHoverPoseFlags                               , 0x866)
        SCHEMA_FIELD(float                           , m_flTouchOutputPerEntityDelay                   , 0x868)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDamaged                                     , 0x870)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAwakened                                    , 0x888)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMotionEnabled                               , 0x8A0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerUse                                   , 0x8B8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartTouch                                  , 0x8D0)
        SCHEMA_FIELD(CHandle<CBasePlayerPawn>        , m_hCarryingPlayer                               , 0x8E8)
    };

    class CPushable : public CBreakable {
    public:
    };

    class CPathMover : public CPathWithDynamicNodes {
    public:
        SCHEMA_FIELD(CUtlVector<CHandle<CFuncMover>> , m_vecMovers                                     , 0x5F0)
        SCHEMA_FIELD(CHandle<CPathMoverEntitySpawner>, m_hMoverSpawner                                 , 0x608)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszMoverSpawnerName                           , 0x610)
    };

    class CSoundOpvarSetAutoRoomEntity : public CSoundOpvarSetPointEntity {
    public:
        SCHEMA_FIELD(CUtlVector<SoundOpvarTraceResult_t>, m_traceResults                                  , 0x640)
        SCHEMA_FIELD(CUtlVector<AutoRoomDoorwayPairs_t>, m_doorwayPairs                                  , 0x658)
        SCHEMA_FIELD(float                           , m_flSize                                        , 0x670)
        SCHEMA_FIELD(float                           , m_flHeightTolerance                             , 0x674)
        SCHEMA_FIELD(float                           , m_flSizeSqr                                     , 0x678)
    };

    class CSoundOpvarSetPathCornerEntity : public CSoundOpvarSetPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bUseParentedPath                              , 0x658)
        SCHEMA_FIELD(float                           , m_flDistMinSqr                                  , 0x65C)
        SCHEMA_FIELD(float                           , m_flDistMaxSqr                                  , 0x660)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPathCornerEntityName                       , 0x668)
    };

    class CSoundOpvarSetAABBEntity : public CSoundOpvarSetPointEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vDistanceInnerMins                            , 0x640)
        SCHEMA_FIELD(::Vector                        , m_vDistanceInnerMaxs                            , 0x64C)
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMins                            , 0x658)
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMaxs                            , 0x664)
        SCHEMA_FIELD(std::int32_t                    , m_nAABBDirection                                , 0x670)
        SCHEMA_FIELD(::Vector                        , m_vInnerMins                                    , 0x674)
        SCHEMA_FIELD(::Vector                        , m_vInnerMaxs                                    , 0x680)
        SCHEMA_FIELD(::Vector                        , m_vOuterMins                                    , 0x68C)
        SCHEMA_FIELD(::Vector                        , m_vOuterMaxs                                    , 0x698)
    };

    class CCSGO_WingmanIntroCounterTerroristPosition : public CCSGO_WingmanIntroCharacterPosition {
    public:
    };

    class CCSGO_WingmanIntroTerroristPosition : public CCSGO_WingmanIntroCharacterPosition {
    public:
    };

    class CInfoDeathmatchSpawn : public SpawnPoint {
    public:
    };

    class CInfoPlayerTerrorist : public SpawnPoint {
    public:
    };

    class CInfoPlayerCounterterrorist : public SpawnPoint {
    public:
    };

    class CLogicActiveAutosave : public CLogicAutosave {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_TriggerHitPoints                              , 0x4B8)
        SCHEMA_FIELD(float                           , m_flTimeToTrigger                               , 0x4BC)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x4C0)
        SCHEMA_FIELD(float                           , m_flDangerousTime                               , 0x4C4)
    };

    class CRagdollConstraint : public CPhysConstraint {
    public:
        SCHEMA_FIELD(float                           , m_xmin                                          , 0x508)
        SCHEMA_FIELD(float                           , m_xmax                                          , 0x50C)
        SCHEMA_FIELD(float                           , m_ymin                                          , 0x510)
        SCHEMA_FIELD(float                           , m_ymax                                          , 0x514)
        SCHEMA_FIELD(float                           , m_zmin                                          , 0x518)
        SCHEMA_FIELD(float                           , m_zmax                                          , 0x51C)
        SCHEMA_FIELD(float                           , m_xfriction                                     , 0x520)
        SCHEMA_FIELD(float                           , m_yfriction                                     , 0x524)
        SCHEMA_FIELD(float                           , m_zfriction                                     , 0x528)
    };

    class CPhysPulley : public CPhysConstraint {
    public:
        SCHEMA_FIELD(VectorWS                        , m_position2                                     , 0x508)
        SCHEMA_FIELD(::Vector                        , m_offset                                        , 0x514)
        SCHEMA_FIELD(float                           , m_addLength                                     , 0x52C)
        SCHEMA_FIELD(float                           , m_gearRatio                                     , 0x530)
    };

    class CPhysLength : public CPhysConstraint {
    public:
        SCHEMA_FIELD(::Vector                        , m_offset                                        , 0x508)
        SCHEMA_FIELD(VectorWS                        , m_vecAttach                                     , 0x520)
        SCHEMA_FIELD(float                           , m_addLength                                     , 0x52C)
        SCHEMA_FIELD(float                           , m_minLength                                     , 0x530)
        SCHEMA_FIELD(float                           , m_totalLength                                   , 0x534)
    };

    class CPhysHinge : public CPhysConstraint {
    public:
        SCHEMA_FIELD(ConstraintSoundInfo             , m_soundInfo                                     , 0x510)
        SCHEMA_FIELD(CEntityIOOutput                 , m_NotifyMinLimitReached                         , 0x5A8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_NotifyMaxLimitReached                         , 0x5C0)
        SCHEMA_FIELD(bool                            , m_bAtMinLimit                                   , 0x5D8)
        SCHEMA_FIELD(bool                            , m_bAtMaxLimit                                   , 0x5D9)
        SCHEMA_FIELD(constraint_hingeparams_t        , m_hinge                                         , 0x5DC)
        SCHEMA_FIELD(float                           , m_hingeFriction                                 , 0x61C)
        SCHEMA_FIELD(float                           , m_systemLoadScale                               , 0x620)
        SCHEMA_FIELD(bool                            , m_bIsAxisLocal                                  , 0x624)
        SCHEMA_FIELD(float                           , m_flMinRotation                                 , 0x628)
        SCHEMA_FIELD(float                           , m_flMaxRotation                                 , 0x62C)
        SCHEMA_FIELD(float                           , m_flInitialRotation                             , 0x630)
        SCHEMA_FIELD(float                           , m_flMotorFrequency                              , 0x634)
        SCHEMA_FIELD(float                           , m_flMotorDampingRatio                           , 0x638)
        SCHEMA_FIELD(float                           , m_flAngleSpeed                                  , 0x63C)
        SCHEMA_FIELD(float                           , m_flAngleSpeedThreshold                         , 0x640)
        SCHEMA_FIELD(float                           , m_flLimitsDebugVisRotation                      , 0x644)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartMoving                                 , 0x648)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStopMoving                                  , 0x660)
    };

    class CGenericConstraint : public CPhysConstraint {
    public:
        SCHEMA_FIELD(bool                            , m_bPlaceAnchorsAtConstraintTransform            , 0x510)
        SCHEMA_FIELD(JointMotion_t                   , m_nLinearMotionX                                , 0x514)
        SCHEMA_FIELD(JointMotion_t                   , m_nLinearMotionY                                , 0x518)
        SCHEMA_FIELD(JointMotion_t                   , m_nLinearMotionZ                                , 0x51C)
        SCHEMA_FIELD(float                           , m_flLinearFrequencyX                            , 0x520)
        SCHEMA_FIELD(float                           , m_flLinearFrequencyY                            , 0x524)
        SCHEMA_FIELD(float                           , m_flLinearFrequencyZ                            , 0x528)
        SCHEMA_FIELD(float                           , m_flLinearDampingRatioX                         , 0x52C)
        SCHEMA_FIELD(float                           , m_flLinearDampingRatioY                         , 0x530)
        SCHEMA_FIELD(float                           , m_flLinearDampingRatioZ                         , 0x534)
        SCHEMA_FIELD(float                           , m_flMaxLinearImpulseX                           , 0x538)
        SCHEMA_FIELD(float                           , m_flMaxLinearImpulseY                           , 0x53C)
        SCHEMA_FIELD(float                           , m_flMaxLinearImpulseZ                           , 0x540)
        SCHEMA_FIELD(float                           , m_flBreakAfterTimeX                             , 0x544)
        SCHEMA_FIELD(float                           , m_flBreakAfterTimeY                             , 0x548)
        SCHEMA_FIELD(float                           , m_flBreakAfterTimeZ                             , 0x54C)
        SCHEMA_FIELD(::GameTime_t                    , m_flBreakAfterTimeStartTimeX                    , 0x550)
        SCHEMA_FIELD(::GameTime_t                    , m_flBreakAfterTimeStartTimeY                    , 0x554)
        SCHEMA_FIELD(::GameTime_t                    , m_flBreakAfterTimeStartTimeZ                    , 0x558)
        SCHEMA_FIELD(float                           , m_flBreakAfterTimeThresholdX                    , 0x55C)
        SCHEMA_FIELD(float                           , m_flBreakAfterTimeThresholdY                    , 0x560)
        SCHEMA_FIELD(float                           , m_flBreakAfterTimeThresholdZ                    , 0x564)
        SCHEMA_FIELD(float                           , m_flNotifyForceX                                , 0x568)
        SCHEMA_FIELD(float                           , m_flNotifyForceY                                , 0x56C)
        SCHEMA_FIELD(float                           , m_flNotifyForceZ                                , 0x570)
        SCHEMA_FIELD(float                           , m_flNotifyForceMinTimeX                         , 0x574)
        SCHEMA_FIELD(float                           , m_flNotifyForceMinTimeY                         , 0x578)
        SCHEMA_FIELD(float                           , m_flNotifyForceMinTimeZ                         , 0x57C)
        SCHEMA_FIELD(::GameTime_t                    , m_flNotifyForceLastTimeX                        , 0x580)
        SCHEMA_FIELD(::GameTime_t                    , m_flNotifyForceLastTimeY                        , 0x584)
        SCHEMA_FIELD(::GameTime_t                    , m_flNotifyForceLastTimeZ                        , 0x588)
        SCHEMA_FIELD(bool                            , m_bAxisNotifiedX                                , 0x58C)
        SCHEMA_FIELD(bool                            , m_bAxisNotifiedY                                , 0x58D)
        SCHEMA_FIELD(bool                            , m_bAxisNotifiedZ                                , 0x58E)
        SCHEMA_FIELD(JointMotion_t                   , m_nAngularMotionX                               , 0x590)
        SCHEMA_FIELD(JointMotion_t                   , m_nAngularMotionY                               , 0x594)
        SCHEMA_FIELD(JointMotion_t                   , m_nAngularMotionZ                               , 0x598)
        SCHEMA_FIELD(float                           , m_flAngularFrequencyX                           , 0x59C)
        SCHEMA_FIELD(float                           , m_flAngularFrequencyY                           , 0x5A0)
        SCHEMA_FIELD(float                           , m_flAngularFrequencyZ                           , 0x5A4)
        SCHEMA_FIELD(float                           , m_flAngularDampingRatioX                        , 0x5A8)
        SCHEMA_FIELD(float                           , m_flAngularDampingRatioY                        , 0x5AC)
        SCHEMA_FIELD(float                           , m_flAngularDampingRatioZ                        , 0x5B0)
        SCHEMA_FIELD(float                           , m_flMaxAngularImpulseX                          , 0x5B4)
        SCHEMA_FIELD(float                           , m_flMaxAngularImpulseY                          , 0x5B8)
        SCHEMA_FIELD(float                           , m_flMaxAngularImpulseZ                          , 0x5BC)
        SCHEMA_FIELD(CEntityIOOutput                 , m_NotifyForceReachedX                           , 0x5C0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_NotifyForceReachedY                           , 0x5D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_NotifyForceReachedZ                           , 0x5F0)
    };

    class CSplineConstraint : public CPhysConstraint {
    public:
        SCHEMA_FIELD(::Vector                        , m_vAnchorOffsetRestore                          , 0x558)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hSplineEntity                                 , 0x564)
        SCHEMA_FIELD(IPhysicsBody*                   , m_pSplineBody                                   , 0x568)
        SCHEMA_FIELD(bool                            , m_bEnableLateralConstraint                      , 0x570)
        SCHEMA_FIELD(bool                            , m_bEnableVerticalConstraint                     , 0x571)
        SCHEMA_FIELD(bool                            , m_bEnableAngularConstraint                      , 0x572)
        SCHEMA_FIELD(bool                            , m_bEnableLimit                                  , 0x573)
        SCHEMA_FIELD(bool                            , m_bFireEventsOnPath                             , 0x574)
        SCHEMA_FIELD(float                           , m_flLinearFrequency                             , 0x578)
        SCHEMA_FIELD(float                           , m_flLinarDampingRatio                           , 0x57C)
        SCHEMA_FIELD(float                           , m_flJointFriction                               , 0x580)
        SCHEMA_FIELD(float                           , m_flTransitionTime                              , 0x584)
        SCHEMA_FIELD(VectorWS                        , m_vPreSolveAnchorPos                            , 0x598)
        SCHEMA_FIELD(::GameTime_t                    , m_StartTransitionTime                           , 0x5A4)
        SCHEMA_FIELD(::Vector                        , m_vTangentSpaceAnchorAtTransitionStart          , 0x5A8)
    };

    class CPhysSlideConstraint : public CPhysConstraint {
    public:
        SCHEMA_FIELD(VectorWS                        , m_axisEnd                                       , 0x510)
        SCHEMA_FIELD(float                           , m_slideFriction                                 , 0x51C)
        SCHEMA_FIELD(float                           , m_systemLoadScale                               , 0x520)
        SCHEMA_FIELD(float                           , m_initialOffset                                 , 0x524)
        SCHEMA_FIELD(bool                            , m_bEnableLinearConstraint                       , 0x528)
        SCHEMA_FIELD(bool                            , m_bEnableAngularConstraint                      , 0x529)
        SCHEMA_FIELD(float                           , m_flMotorFrequency                              , 0x52C)
        SCHEMA_FIELD(float                           , m_flMotorDampingRatio                           , 0x530)
        SCHEMA_FIELD(bool                            , m_bUseEntityPivot                               , 0x534)
        SCHEMA_FIELD(ConstraintSoundInfo             , m_soundInfo                                     , 0x538)
    };

    class CPhysFixed : public CPhysConstraint {
    public:
        SCHEMA_FIELD(float                           , m_flLinearFrequency                             , 0x508)
        SCHEMA_FIELD(float                           , m_flLinearDampingRatio                          , 0x50C)
        SCHEMA_FIELD(float                           , m_flAngularFrequency                            , 0x510)
        SCHEMA_FIELD(float                           , m_flAngularDampingRatio                         , 0x514)
        SCHEMA_FIELD(bool                            , m_bEnableLinearConstraint                       , 0x518)
        SCHEMA_FIELD(bool                            , m_bEnableAngularConstraint                      , 0x519)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sBoneName1                                    , 0x520)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sBoneName2                                    , 0x528)
    };

    class CPhysBallSocket : public CPhysConstraint {
    public:
        SCHEMA_FIELD(float                           , m_flJointFriction                               , 0x508)
        SCHEMA_FIELD(bool                            , m_bEnableSwingLimit                             , 0x50C)
        SCHEMA_FIELD(float                           , m_flSwingLimit                                  , 0x510)
        SCHEMA_FIELD(bool                            , m_bEnableTwistLimit                             , 0x514)
        SCHEMA_FIELD(float                           , m_flMinTwistAngle                               , 0x518)
        SCHEMA_FIELD(float                           , m_flMaxTwistAngle                               , 0x51C)
    };

    class CPhysWheelConstraint : public CPhysConstraint {
    public:
        SCHEMA_FIELD(float                           , m_flSuspensionFrequency                         , 0x508)
        SCHEMA_FIELD(float                           , m_flSuspensionDampingRatio                      , 0x50C)
        SCHEMA_FIELD(float                           , m_flSuspensionHeightOffset                      , 0x510)
        SCHEMA_FIELD(bool                            , m_bEnableSuspensionLimit                        , 0x514)
        SCHEMA_FIELD(float                           , m_flMinSuspensionOffset                         , 0x518)
        SCHEMA_FIELD(float                           , m_flMaxSuspensionOffset                         , 0x51C)
        SCHEMA_FIELD(bool                            , m_bEnableSteeringLimit                          , 0x520)
        SCHEMA_FIELD(float                           , m_flMinSteeringAngle                            , 0x524)
        SCHEMA_FIELD(float                           , m_flMaxSteeringAngle                            , 0x528)
        SCHEMA_FIELD(float                           , m_flSteeringAxisFriction                        , 0x52C)
        SCHEMA_FIELD(float                           , m_flSpinAxisFriction                            , 0x530)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hSteeringMimicsEntity                         , 0x534)
    };

    class CBaseMoveBehavior : public CPathKeyFrame {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iPositionInterpolator                         , 0x4F0)
        SCHEMA_FIELD(std::int32_t                    , m_iRotationInterpolator                         , 0x4F4)
        SCHEMA_FIELD(float                           , m_flAnimStartTime                               , 0x4F8)
        SCHEMA_FIELD(float                           , m_flAnimEndTime                                 , 0x4FC)
        SCHEMA_FIELD(float                           , m_flAverageSpeedAcrossFrame                     , 0x500)
        SCHEMA_FIELD(CHandle<CPathKeyFrame>          , m_pCurrentKeyFrame                              , 0x504)
        SCHEMA_FIELD(CHandle<CPathKeyFrame>          , m_pTargetKeyFrame                               , 0x508)
        SCHEMA_FIELD(CHandle<CPathKeyFrame>          , m_pPreKeyFrame                                  , 0x50C)
        SCHEMA_FIELD(CHandle<CPathKeyFrame>          , m_pPostKeyFrame                                 , 0x510)
        SCHEMA_FIELD(float                           , m_flTimeIntoFrame                               , 0x514)
        SCHEMA_FIELD(std::int32_t                    , m_iDirection                                    , 0x518)
    };

    class CFilterEnemy : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEnemyName                                  , 0x4E0)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4E8)
        SCHEMA_FIELD(float                           , m_flOuterRadius                                 , 0x4EC)
        SCHEMA_FIELD(std::int32_t                    , m_nMaxSquadmatesPerEnemy                        , 0x4F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPlayerName                                 , 0x4F8)
    };

    class CFilterMultiple : public CBaseFilter {
    public:
        SCHEMA_FIELD(filter_t                        , m_nFilterType                                   , 0x4E0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x4E8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hFilter                                       , 0x538)
    };

    class FilterHealth : public CBaseFilter {
    public:
        SCHEMA_FIELD(bool                            , m_bAdrenalineActive                             , 0x4E0)
        SCHEMA_FIELD(std::int32_t                    , m_iHealthMin                                    , 0x4E4)
        SCHEMA_FIELD(std::int32_t                    , m_iHealthMax                                    , 0x4E8)
    };

    class CFilterAttributeInt : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sAttributeName                                , 0x4E0)
    };

    class CFilterLOS : public CBaseFilter {
    public:
    };

    class CFilterMassGreater : public CBaseFilter {
    public:
        SCHEMA_FIELD(float                           , m_fFilterMass                                   , 0x4E0)
    };

    class CFilterContext : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterContext                                , 0x4E0)
    };

    class FilterDamageType : public CBaseFilter {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iDamageType                                   , 0x4E0)
    };

    class CFilterProximity : public CBaseFilter {
    public:
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x4E0)
    };

    class CFilterModel : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterModel                                  , 0x4E0)
    };

    class CFilterName : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x4E0)
    };

    class CFilterClass : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterClass                                  , 0x4E0)
    };

    class CFilterTeam : public CBaseFilter {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iFilterTeam                                   , 0x4E0)
    };

    class CFuncMoveLinearAlias_momentary_door : public CFuncMoveLinear {
    public:
    };

    class CFogTrigger : public CBaseTrigger {
    public:
        SCHEMA_FIELD(fogparams_t                     , m_fog                                           , 0x8C8)
    };

    class CTriggerBuoyancy : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CBuoyancyHelper                 , m_BuoyancyHelper                                , 0x8C8)
        SCHEMA_FIELD(float                           , m_flFluidDensity                                , 0x9E0)
    };

    class CTriggerProximity : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hMeasureTarget                                , 0x8C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszMeasureTarget                              , 0x8D0)
        SCHEMA_FIELD(float                           , m_fRadius                                       , 0x8D8)
        SCHEMA_FIELD(std::int32_t                    , m_nTouchers                                     , 0x8DC)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_NearestEntityDistance                         , 0x8E0)
    };

    class CTriggerFan : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::Vector                        , m_vFanOriginOffset                              , 0x8C8)
        SCHEMA_FIELD(::Vector                        , m_vDirection                                    , 0x8D4)
        SCHEMA_FIELD(bool                            , m_bPushTowardsInfoTarget                        , 0x8E0)
        SCHEMA_FIELD(bool                            , m_bPushAwayFromInfoTarget                       , 0x8E1)
        SCHEMA_FIELD(::Quaternion                    , m_qNoiseDelta                                   , 0x8F0)
        SCHEMA_FIELD(CHandle<CInfoFan>               , m_hInfoFan                                      , 0x900)
        SCHEMA_FIELD(float                           , m_flForce                                       , 0x904)
        SCHEMA_FIELD(bool                            , m_bFalloff                                      , 0x908)
        SCHEMA_FIELD(CountdownTimer                  , m_RampTimer                                     , 0x910)
        SCHEMA_FIELD(VectorWS                        , m_vFanOriginWS                                  , 0x928)
        SCHEMA_FIELD(::Vector                        , m_vFanOriginLS                                  , 0x934)
        SCHEMA_FIELD(::Vector                        , m_vFanEndLS                                     , 0x940)
        SCHEMA_FIELD(::Vector                        , m_vNoiseDirectionTarget                         , 0x94C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszInfoFan                                    , 0x958)
        SCHEMA_FIELD(float                           , m_flRopeForceScale                              , 0x960)
        SCHEMA_FIELD(float                           , m_flParticleForceScale                          , 0x964)
        SCHEMA_FIELD(float                           , m_flPlayerForce                                 , 0x968)
        SCHEMA_FIELD(bool                            , m_bPlayerWindblock                              , 0x96C)
        SCHEMA_FIELD(float                           , m_flNPCForce                                    , 0x970)
        SCHEMA_FIELD(float                           , m_flRampTime                                    , 0x974)
        SCHEMA_FIELD(float                           , m_fNoiseDegrees                                 , 0x978)
        SCHEMA_FIELD(float                           , m_fNoiseSpeed                                   , 0x97C)
        SCHEMA_FIELD(bool                            , m_bPushPlayer                                   , 0x980)
        SCHEMA_FIELD(bool                            , m_bRampDown                                     , 0x981)
        SCHEMA_FIELD(std::int32_t                    , m_nManagerFanIdx                                , 0x984)
    };

    class CTriggerDetectBulletFire : public CBaseTrigger {
    public:
        SCHEMA_FIELD(bool                            , m_bPlayerFireOnly                               , 0x8C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDetectedBulletFire                          , 0x8D0)
    };

    class CHostageRescueZoneShim : public CBaseTrigger {
    public:
    };

    class CTriggerSoundscape : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CHandle<CEnvSoundscapeTriggerable>, m_hSoundscape                                   , 0x8C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundscapeName                                , 0x8D0)
        SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerPawn>>, m_spectators                                    , 0x8D8)
    };

    class CFootstepControl : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_source                                        , 0x8C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_destination                                   , 0x8D0)
    };

    class CTriggerActiveWeaponDetect : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTouchedActiveWeapon                         , 0x8C8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszWeaponClassName                            , 0x8E0)
    };

    class CPostProcessingVolume : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCPostProcessingResource>, m_hPostSettings                                 , 0x8D8)
        SCHEMA_FIELD(float                           , m_flFadeDuration                                , 0x8E0)
        SCHEMA_FIELD(float                           , m_flMinLogExposure                              , 0x8E4)
        SCHEMA_FIELD(float                           , m_flMaxLogExposure                              , 0x8E8)
        SCHEMA_FIELD(float                           , m_flMinExposure                                 , 0x8EC)
        SCHEMA_FIELD(float                           , m_flMaxExposure                                 , 0x8F0)
        SCHEMA_FIELD(float                           , m_flExposureCompensation                        , 0x8F4)
        SCHEMA_FIELD(float                           , m_flExposureFadeSpeedUp                         , 0x8F8)
        SCHEMA_FIELD(float                           , m_flExposureFadeSpeedDown                       , 0x8FC)
        SCHEMA_FIELD(float                           , m_flTonemapEVSmoothingRange                     , 0x900)
        SCHEMA_FIELD(bool                            , m_bMaster                                       , 0x904)
        SCHEMA_FIELD(bool                            , m_bExposureControl                              , 0x905)
    };

    class CTriggerRemove : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnRemove                                      , 0x8C8)
    };

    class CPrecipitation : public CBaseTrigger {
    public:
    };

    class CBombTarget : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBombExplode                                 , 0x8C8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBombPlanted                                 , 0x8E0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBombDefused                                 , 0x8F8)
        SCHEMA_FIELD(bool                            , m_bIsBombSiteB                                  , 0x910)
        SCHEMA_FIELD(bool                            , m_bIsHeistBombTarget                            , 0x911)
        SCHEMA_FIELD(bool                            , m_bBombPlantedHere                              , 0x912)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szMountTarget                                 , 0x918)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hInstructorHint                               , 0x920)
        SCHEMA_FIELD(std::int32_t                    , m_nBombSiteDesignation                          , 0x924)
    };

    class CTriggerGameEvent : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strStartTouchEventName                        , 0x8C8)
        SCHEMA_FIELD(::CUtlString                    , m_strEndTouchEventName                          , 0x8D0)
        SCHEMA_FIELD(::CUtlString                    , m_strTriggerID                                  , 0x8D8)
    };

    class CTriggerHostageReset : public CBaseTrigger {
    public:
    };

    class CTriggerPush : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::QAngle                        , m_angPushEntitySpace                            , 0x8C8)
        SCHEMA_FIELD(::Vector                        , m_vecPushDirEntitySpace                         , 0x8D4)
        SCHEMA_FIELD(bool                            , m_bTriggerOnStartTouch                          , 0x8E0)
        SCHEMA_FIELD(bool                            , m_bUsePathSimple                                , 0x8E1)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPathSimpleName                             , 0x8E8)
        SCHEMA_FIELD(CHandle<CPathSimple>            , m_PathSimple                                    , 0x8F0)
        SCHEMA_FIELD(std::uint32_t                   , m_splinePushType                                , 0x8F4)
    };

    class CTonemapTrigger : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_tonemapControllerName                         , 0x8C8)
        SCHEMA_FIELD(CEntityHandle                   , m_hTonemapController                            , 0x8D0)
    };

    class CTriggerCallback : public CBaseTrigger {
    public:
    };

    class CTriggerTeleport : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iLandmark                                     , 0x8C8)
        SCHEMA_FIELD(bool                            , m_bUseLandmarkAngles                            , 0x8D0)
        SCHEMA_FIELD(bool                            , m_bMirrorPlayer                                 , 0x8D1)
        SCHEMA_FIELD(bool                            , m_bCheckDestIfClearForPlayer                    , 0x8D2)
    };

    class CChangeLevel : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sMapName                                      , 0x8C8)
        SCHEMA_FIELD(::CUtlString                    , m_sLandmarkName                                 , 0x8D0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnChangeLevel                                 , 0x8D8)
        SCHEMA_FIELD(bool                            , m_bTouched                                      , 0x8F0)
        SCHEMA_FIELD(bool                            , m_bNoTouch                                      , 0x8F1)
        SCHEMA_FIELD(bool                            , m_bNewChapter                                   , 0x8F2)
        SCHEMA_FIELD(bool                            , m_bOnChangeLevelFired                           , 0x8F3)
    };

    class CColorCorrectionVolume : public CBaseTrigger {
    public:
        SCHEMA_FIELD(float                           , m_MaxWeight                                     , 0x8C8)
        SCHEMA_FIELD(float                           , m_FadeDuration                                  , 0x8CC)
        SCHEMA_FIELD(float                           , m_Weight                                        , 0x8D0)
        SCHEMA_FIELD(char                            , m_lookupFilename                                , 0x8D4)
        SCHEMA_FIELD(float                           , m_LastEnterWeight                               , 0xAD4)
        SCHEMA_FIELD(::GameTime_t                    , m_LastEnterTime                                 , 0xAD8)
        SCHEMA_FIELD(float                           , m_LastExitWeight                                , 0xADC)
        SCHEMA_FIELD(::GameTime_t                    , m_LastExitTime                                  , 0xAE0)
    };

    class CTriggerGravity : public CBaseTrigger {
    public:
    };

    class CBuyZone : public CBaseTrigger {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_LegacyTeamNum                                 , 0x8C8)
    };

    class CTriggerMultiple : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTrigger                                     , 0x8C8)
    };

    class CTriggerBombReset : public CBaseTrigger {
    public:
    };

    class CTriggerHurt : public CBaseTrigger {
    public:
        SCHEMA_FIELD(float                           , m_flOriginalDamage                              , 0x8C8)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0x8CC)
        SCHEMA_FIELD(float                           , m_flDamageCap                                   , 0x8D0)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastDmgTime                                 , 0x8D4)
        SCHEMA_FIELD(float                           , m_flForgivenessDelay                            , 0x8D8)
        SCHEMA_FIELD(DamageTypes_t                   , m_bitsDamageInflict                             , 0x8DC)
        SCHEMA_FIELD(std::int32_t                    , m_damageModel                                   , 0x8E0)
        SCHEMA_FIELD(bool                            , m_bNoDmgForce                                   , 0x8E4)
        SCHEMA_FIELD(::Vector                        , m_vDamageForce                                  , 0x8E8)
        SCHEMA_FIELD(bool                            , m_thinkAlways                                   , 0x8F4)
        SCHEMA_FIELD(float                           , m_hurtThinkPeriod                               , 0x8F8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnHurt                                        , 0x900)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnHurtPlayer                                  , 0x918)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hurtEntities                                  , 0x930)
    };

    class CTriggerDetectExplosion : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDetectedExplosion                           , 0x8F0)
    };

    class CTriggerSndSosOpvar : public CBaseTrigger {
    public:
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_hTouchingPlayers                              , 0x8C8)
        SCHEMA_FIELD(::Vector                        , m_flPosition                                    , 0x8E0)
        SCHEMA_FIELD(float                           , m_flCenterSize                                  , 0x8EC)
        SCHEMA_FIELD(float                           , m_flMinVal                                      , 0x8F0)
        SCHEMA_FIELD(float                           , m_flMaxVal                                      , 0x8F4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_opvarName                                     , 0x8F8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_stackName                                     , 0x900)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_operatorName                                  , 0x908)
        SCHEMA_FIELD(bool                            , m_bVolIs2D                                      , 0x910)
        SCHEMA_FIELD(char                            , m_opvarNameChar                                 , 0x911)
        SCHEMA_FIELD(char                            , m_stackNameChar                                 , 0xA11)
        SCHEMA_FIELD(char                            , m_operatorNameChar                              , 0xB11)
        SCHEMA_FIELD(::Vector                        , m_VecNormPos                                    , 0xC14)
        SCHEMA_FIELD(float                           , m_flNormCenterSize                              , 0xC20)
    };

    class CTriggerToggleSave : public CBaseTrigger {
    public:
    };

    class CTriggerPhysics : public CBaseTrigger {
    public:
        SCHEMA_FIELD(IPhysicsMotionController*       , m_pController                                   , 0x8D0)
        SCHEMA_FIELD(float                           , m_gravityScale                                  , 0x8D8)
        SCHEMA_FIELD(float                           , m_linearLimit                                   , 0x8DC)
        SCHEMA_FIELD(float                           , m_linearDamping                                 , 0x8E0)
        SCHEMA_FIELD(float                           , m_angularLimit                                  , 0x8E4)
        SCHEMA_FIELD(float                           , m_angularDamping                                , 0x8E8)
        SCHEMA_FIELD(float                           , m_linearForce                                   , 0x8EC)
        SCHEMA_FIELD(float                           , m_flFrequency                                   , 0x8F0)
        SCHEMA_FIELD(float                           , m_flDampingRatio                                , 0x8F4)
        SCHEMA_FIELD(::Vector                        , m_vecLinearForcePointAt                         , 0x8F8)
        SCHEMA_FIELD(bool                            , m_bCollapseToForcePoint                         , 0x904)
        SCHEMA_FIELD(::Vector                        , m_vecLinearForcePointAtWorld                    , 0x908)
        SCHEMA_FIELD(::Vector                        , m_vecLinearForceDirection                       , 0x914)
        SCHEMA_FIELD(bool                            , m_bConvertToDebrisWhenPossible                  , 0x920)
    };

    class CServerRagdollTrigger : public CBaseTrigger {
    public:
    };

    class CTriggerLerpObject : public CBaseTrigger {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLerpTarget                                 , 0x8C8)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLerpTarget                                   , 0x8D0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLerpTargetAttachment                       , 0x8D8)
        SCHEMA_FIELD(AttachmentHandle_t              , m_hLerpTargetAttachment                         , 0x8E0)
        SCHEMA_FIELD(float                           , m_flLerpDuration                                , 0x8E4)
        SCHEMA_FIELD(bool                            , m_bAttachedEntityWasParented                    , 0x8E8)
        SCHEMA_FIELD(bool                            , m_bLerpRestoreMoveType                          , 0x8E9)
        SCHEMA_FIELD(bool                            , m_bSingleLerpObject                             , 0x8EA)
        SCHEMA_FIELD(CUtlVector<lerpdata_t>          , m_vecLerpingObjects                             , 0x8F0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLerpEffect                                 , 0x908)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLerpSound                                  , 0x910)
        SCHEMA_FIELD(bool                            , m_bAttachTouchingObject                         , 0x918)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEntityToWaitForDisconnect                    , 0x91C)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLerpStarted                                 , 0x920)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLerpFinished                                , 0x938)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDetached                                    , 0x950)
    };

    class CTriggerSave : public CBaseTrigger {
    public:
        SCHEMA_FIELD(bool                            , m_bForceNewLevelUnit                            , 0x8C8)
        SCHEMA_FIELD(float                           , m_fDangerousTimer                               , 0x8CC)
        SCHEMA_FIELD(std::int32_t                    , m_minHitPoints                                  , 0x8D0)
    };

    class CFuncTrain : public CBasePlatTrain {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hCurrentTarget                                , 0x810)
        SCHEMA_FIELD(bool                            , m_activated                                     , 0x814)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hEnemy                                        , 0x818)
        SCHEMA_FIELD(float                           , m_flBlockDamage                                 , 0x81C)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextBlockTime                               , 0x820)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszLastTarget                                 , 0x828)
    };

    class CFuncPlat : public CBasePlatTrain {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sNoise                                        , 0x810)
    };

    class CPhysicalButton : public CBaseButton {
    public:
    };

    class CRotButton : public CBaseButton {
    public:
    };

    class CRotDoor : public CBaseDoor {
    public:
        SCHEMA_FIELD(bool                            , m_bSolidBsp                                     , 0x968)
    };

    class CLightEnvironmentEntity : public CLightDirectionalEntity {
    public:
    };

    class CSimpleMarkupVolumeTagged : public CMarkupVolumeTagged {
    public:
    };

    class CMarkupVolumeTagged_Nav : public CMarkupVolumeTagged {
    public:
        SCHEMA_FIELD(NavScopeFlags_t                 , m_nScopes                                       , 0x7A8)
    };

    class CMarkupVolumeWithRef : public CMarkupVolumeTagged {
    public:
        SCHEMA_FIELD(bool                            , m_bUseRef                                       , 0x7B0)
        SCHEMA_FIELD(::Vector                        , m_vRefPosEntitySpace                            , 0x7B4)
        SCHEMA_FIELD(VectorWS                        , m_vRefPosWorldSpace                             , 0x7C0)
        SCHEMA_FIELD(float                           , m_flRefDot                                      , 0x7CC)
    };

    class CGamePlayerZone : public CRuleBrushEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerInZone                                , 0x770)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerOutZone                               , 0x788)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_PlayersInCount                                , 0x7A0)
        SCHEMA_FIELD(CEntityOutputTemplate<int32>    , m_PlayersOutCount                               , 0x7C0)
    };

    class CGameText : public CRulePointEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszMessage                                    , 0x778)
        SCHEMA_FIELD(hudtextparms_t                  , m_textParms                                     , 0x780)
    };

    class CGameEnd : public CRulePointEntity {
    public:
    };

    class CGamePlayerEquip : public CRulePointEntity {
    public:
    };

    class CGameMoney : public CRulePointEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMoneySpent                                  , 0x778)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnMoneySpentFail                              , 0x790)
        SCHEMA_FIELD(std::int32_t                    , m_nMoney                                        , 0x7A8)
        SCHEMA_FIELD(::CUtlString                    , m_strAwardText                                  , 0x7B0)
    };

    class CHostageExpresserShim : public CBaseCombatCharacter {
    public:
        SCHEMA_FIELD(CAI_Expresser*                  , m_pExpresser                                    , 0xA00)
    };

    class CBasePlayerPawn : public CBaseCombatCharacter {
    public:
        SCHEMA_FIELD(CPlayer_WeaponServices*         , m_pWeaponServices                               , 0xA00)
        SCHEMA_FIELD(CPlayer_ItemServices*           , m_pItemServices                                 , 0xA08)
        SCHEMA_FIELD(CPlayer_AutoaimServices*        , m_pAutoaimServices                              , 0xA10)
        SCHEMA_FIELD(CPlayer_ObserverServices*       , m_pObserverServices                             , 0xA18)
        SCHEMA_FIELD(CPlayer_WaterServices*          , m_pWaterServices                                , 0xA20)
        SCHEMA_FIELD(CPlayer_UseServices*            , m_pUseServices                                  , 0xA28)
        SCHEMA_FIELD(CPlayer_FlashlightServices*     , m_pFlashlightServices                           , 0xA30)
        SCHEMA_FIELD(CPlayer_CameraServices*         , m_pCameraServices                               , 0xA38)
        SCHEMA_FIELD(CPlayer_MovementServices*       , m_pMovementServices                             , 0xA40)
        SCHEMA_FIELD(CUtlVectorEmbeddedNetworkVar<ViewAngleServerChange_t>, m_ServerViewAngleChanges                        , 0xA50)
        SCHEMA_FIELD(::QAngle                        , v_angle                                         , 0xAB8)
        SCHEMA_FIELD(::QAngle                        , v_anglePrevious                                 , 0xAC4)
        SCHEMA_FIELD(std::uint32_t                   , m_iHideHUD                                      , 0xAD0)
        SCHEMA_FIELD(sky3dparams_t                   , m_skybox3d                                      , 0xAD8)
        SCHEMA_FIELD(::GameTime_t                    , m_fTimeLastHurt                                 , 0xB68)
        SCHEMA_FIELD(::GameTime_t                    , m_flDeathTime                                   , 0xB6C)
        SCHEMA_FIELD(::GameTime_t                    , m_fNextSuicideTime                              , 0xB70)
        SCHEMA_FIELD(bool                            , m_fInitHUD                                      , 0xB74)
        SCHEMA_FIELD(CAI_Expresser*                  , m_pExpresser                                    , 0xB78)
        SCHEMA_FIELD(CHandle<CBasePlayerController>  , m_hController                                   , 0xB80)
        SCHEMA_FIELD(CHandle<CBasePlayerController>  , m_hDefaultController                            , 0xB84)
        SCHEMA_FIELD(float                           , m_fHltvReplayDelay                              , 0xB8C)
        SCHEMA_FIELD(float                           , m_fHltvReplayEnd                                , 0xB90)
        SCHEMA_FIELD(CEntityIndex                    , m_iHltvReplayEntity                             , 0xB94)
        SCHEMA_FIELD(CUtlVector<sndopvarlatchdata_t> , m_sndOpvarLatchData                             , 0xB98)
    };

    class CEconWearable : public CEconEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nForceSkin                                    , 0xC70)
        SCHEMA_FIELD(bool                            , m_bAlwaysAllow                                  , 0xC74)
    };

    class CBasePlayerWeapon : public CEconEntity {
    public:
        SCHEMA_FIELD(::GameTick_t                    , m_nNextPrimaryAttackTick                        , 0xC70)
        SCHEMA_FIELD(float                           , m_flNextPrimaryAttackTickRatio                  , 0xC74)
        SCHEMA_FIELD(::GameTick_t                    , m_nNextSecondaryAttackTick                      , 0xC78)
        SCHEMA_FIELD(float                           , m_flNextSecondaryAttackTickRatio                , 0xC7C)
        SCHEMA_FIELD(std::int32_t                    , m_iClip1                                        , 0xC80)
        SCHEMA_FIELD(std::int32_t                    , m_iClip2                                        , 0xC84)
        SCHEMA_FIELD(std::int32_t                    , m_pReserveAmmo                                  , 0xC88)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerUse                                   , 0xC90)
    };

    class CScriptItem : public CItem {
    public:
        SCHEMA_FIELD(MoveType_t                      , m_MoveTypeOverride                              , 0x9E0)
    };

    class CItemAssaultSuit : public CItem {
    public:
    };

    class CItemGeneric : public CItem {
    public:
        SCHEMA_FIELD(bool                            , m_bHasTriggerRadius                             , 0x9F4)
        SCHEMA_FIELD(bool                            , m_bHasPickupRadius                              , 0x9F5)
        SCHEMA_FIELD(float                           , m_flPickupRadiusSqr                             , 0x9F8)
        SCHEMA_FIELD(float                           , m_flTriggerRadiusSqr                            , 0x9FC)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastPickupCheck                             , 0xA00)
        SCHEMA_FIELD(bool                            , m_bPlayerCounterListenerAdded                   , 0xA04)
        SCHEMA_FIELD(bool                            , m_bPlayerInTriggerRadius                        , 0xA05)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_hSpawnParticleEffect                          , 0xA08)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pAmbientSoundEffect                           , 0xA10)
        SCHEMA_FIELD(bool                            , m_bAutoStartAmbientSound                        , 0xA18)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pSpawnScriptFunction                          , 0xA20)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_hPickupParticleEffect                         , 0xA28)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pPickupSoundEffect                            , 0xA30)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pPickupScriptFunction                         , 0xA38)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_hTimeoutParticleEffect                        , 0xA40)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pTimeoutSoundEffect                           , 0xA48)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pTimeoutScriptFunction                        , 0xA50)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pPickupFilterName                             , 0xA58)
        SCHEMA_FIELD(CHandle<CBaseFilter>            , m_hPickupFilter                                 , 0xA60)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPickup                                      , 0xA68)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTimeout                                     , 0xA80)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTriggerStartTouch                           , 0xA98)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTriggerTouch                                , 0xAB0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTriggerEndTouch                             , 0xAC8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pAllowPickupScriptFunction                    , 0xAE0)
        SCHEMA_FIELD(float                           , m_flPickupRadius                                , 0xAE8)
        SCHEMA_FIELD(float                           , m_flTriggerRadius                               , 0xAEC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_pTriggerSoundEffect                           , 0xAF0)
        SCHEMA_FIELD(bool                            , m_bGlowWhenInTrigger                            , 0xAF8)
        SCHEMA_FIELD(::Color                         , m_glowColor                                     , 0xAF9)
        SCHEMA_FIELD(bool                            , m_bUseable                                      , 0xAFD)
        SCHEMA_FIELD(CHandle<CItemGenericTriggerHelper>, m_hTriggerHelper                                , 0xB00)
    };

    class CItemKevlar : public CItem {
    public:
    };

    class CItemDefuser : public CItem {
    public:
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0x9E0)
        SCHEMA_FIELD(std::int32_t                    , m_nSpotRules                                    , 0x9F8)
    };

    class CItemDogtags : public CItem {
    public:
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_OwningPlayer                                  , 0x9E0)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_KillingPlayer                                 , 0x9E4)
    };

    class CBreakableProp : public CBaseProp {
    public:
        SCHEMA_FIELD(CPropDataComponent              , m_CPropDataComponent                            , 0x978)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartDeath                                  , 0x9B8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBreak                                       , 0x9D0)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnHealthChanged                               , 0x9E8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTakeDamage                                  , 0xA08)
        SCHEMA_FIELD(float                           , m_impactEnergyScale                             , 0xA20)
        SCHEMA_FIELD(std::int32_t                    , m_iMinHealthDmg                                 , 0xA24)
        SCHEMA_FIELD(::QAngle                        , m_preferredCarryAngles                          , 0xA28)
        SCHEMA_FIELD(float                           , m_flPressureDelay                               , 0xA34)
        SCHEMA_FIELD(float                           , m_flDefBurstScale                               , 0xA38)
        SCHEMA_FIELD(::Vector                        , m_vDefBurstOffset                               , 0xA3C)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hBreaker                                      , 0xA48)
        SCHEMA_FIELD(PerformanceMode_t               , m_PerformanceMode                               , 0xA4C)
        SCHEMA_FIELD(::GameTime_t                    , m_flPreventDamageBeforeTime                     , 0xA50)
        SCHEMA_FIELD(BreakableContentsType_t         , m_BreakableContentsType                         , 0xA54)
        SCHEMA_FIELD(::CUtlString                    , m_strBreakableContentsPropGroupOverride         , 0xA58)
        SCHEMA_FIELD(::CUtlString                    , m_strBreakableContentsParticleOverride          , 0xA60)
        SCHEMA_FIELD(bool                            , m_bHasBreakPiecesOrCommands                     , 0xA68)
        SCHEMA_FIELD(float                           , m_explodeDamage                                 , 0xA6C)
        SCHEMA_FIELD(float                           , m_explodeRadius                                 , 0xA70)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sExplosionType                                , 0xA78)
        SCHEMA_FIELD(float                           , m_explosionDelay                                , 0xA80)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionBuildupSound                         , 0xA88)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionCustomEffect                         , 0xA90)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionCustomSound                          , 0xA98)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionModifier                             , 0xAA0)
        SCHEMA_FIELD(CHandle<CBasePlayerPawn>        , m_hPhysicsAttacker                              , 0xAA8)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastPhysicsInfluenceTime                    , 0xAAC)
        SCHEMA_FIELD(float                           , m_flDefaultFadeScale                            , 0xAB0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLastAttacker                                 , 0xAB4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPuntSound                                  , 0xAB8)
        SCHEMA_FIELD(bool                            , m_bUsePuntSound                                 , 0xAC0)
        SCHEMA_FIELD(bool                            , m_bOriginalBlockLOS                             , 0xAC1)
    };

    class CBaseCSGrenadeProjectile : public CBaseGrenade {
    public:
        SCHEMA_FIELD(::Vector                        , m_vInitialPosition                              , 0x9C0)
        SCHEMA_FIELD(::Vector                        , m_vInitialVelocity                              , 0x9CC)
        SCHEMA_FIELD(std::int32_t                    , m_nBounces                                      , 0x9D8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_nExplodeEffectIndex                           , 0x9E0)
        SCHEMA_FIELD(std::int32_t                    , m_nExplodeEffectTickBegin                       , 0x9E8)
        SCHEMA_FIELD(::Vector                        , m_vecExplodeEffectOrigin                        , 0x9EC)
        SCHEMA_FIELD(::GameTime_t                    , m_flSpawnTime                                   , 0x9F8)
        SCHEMA_FIELD(std::uint8_t                    , m_unOGSExtraFlags                               , 0x9FC)
        SCHEMA_FIELD(bool                            , m_bDetonationRecorded                           , 0x9FD)
        SCHEMA_FIELD(std::uint16_t                   , m_nItemIndex                                    , 0x9FE)
        SCHEMA_FIELD(::Vector                        , m_vecOriginalSpawnLocation                      , 0xA00)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastBounceSoundTime                         , 0xA0C)
        SCHEMA_FIELD(RotationVector                  , m_vecGrenadeSpin                                , 0xA10)
        SCHEMA_FIELD(::Vector                        , m_vecLastHitSurfaceNormal                       , 0xA1C)
        SCHEMA_FIELD(std::int32_t                    , m_nTicksAtZeroVelocity                          , 0xA28)
        SCHEMA_FIELD(bool                            , m_bHasEverHitEnemy                              , 0xA2C)
    };

    class CRagdollPropAlias_physics_prop_ragdoll : public CRagdollProp {
    public:
    };

    class CRagdollPropAttached : public CRagdollProp {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_boneIndexAttached                             , 0xAB0)
        SCHEMA_FIELD(std::uint32_t                   , m_ragdollAttachedObjectIndex                    , 0xAB4)
        SCHEMA_FIELD(::Vector                        , m_attachmentPointBoneSpace                      , 0xAB8)
        SCHEMA_FIELD(::Vector                        , m_attachmentPointRagdollSpace                   , 0xAC4)
        SCHEMA_FIELD(bool                            , m_bShouldDetach                                 , 0xAD0)
        SCHEMA_FIELD(bool                            , m_bShouldDeleteAttachedActivationRecord         , 0xAE0)
    };

    class CPointClientUIWorldTextPanel : public CPointClientUIWorldPanel {
    public:
        SCHEMA_FIELD(char                            , m_messageText                                   , 0x920)
    };

    class CSoundOpvarSetOBBEntity : public CSoundOpvarSetAABBEntity {
    public:
    };

    class CPhysHingeAlias_phys_hinge_local : public CPhysHinge {
    public:
    };

    class CHostageRescueZone : public CHostageRescueZoneShim {
    public:
    };

    class CScriptTriggerPush : public CTriggerPush {
    public:
        SCHEMA_FIELD(::Vector                        , m_vExtent                                       , 0x8F8)
    };

    class CDynamicNavConnectionsVolume : public CTriggerMultiple {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszConnectionTarget                           , 0x8E0)
        SCHEMA_FIELD(CUtlVector<DynamicVolumeDef_t>  , m_vecConnections                                , 0x8E8)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sTransitionType                               , 0x900)
        SCHEMA_FIELD(bool                            , m_bConnectionsEnabled                           , 0x908)
        SCHEMA_FIELD(float                           , m_flTargetAreaSearchRadius                      , 0x90C)
        SCHEMA_FIELD(float                           , m_flUpdateDistance                              , 0x910)
        SCHEMA_FIELD(float                           , m_flMaxConnectionDistance                       , 0x914)
    };

    class CScriptTriggerMultiple : public CTriggerMultiple {
    public:
        SCHEMA_FIELD(::Vector                        , m_vExtent                                       , 0x8E0)
    };

    class CTriggerOnce : public CTriggerMultiple {
    public:
    };

    class CTriggerImpact : public CTriggerMultiple {
    public:
        SCHEMA_FIELD(float                           , m_flMagnitude                                   , 0x8E0)
        SCHEMA_FIELD(float                           , m_flNoise                                       , 0x8E4)
        SCHEMA_FIELD(float                           , m_flViewkick                                    , 0x8E8)
        SCHEMA_FIELD(CEntityOutputTemplate<Vector>   , m_pOutputForce                                  , 0x8F0)
    };

    class CScriptTriggerHurt : public CTriggerHurt {
    public:
        SCHEMA_FIELD(::Vector                        , m_vExtent                                       , 0x950)
    };

    class CFuncPlatRot : public CFuncPlat {
    public:
        SCHEMA_FIELD(::QAngle                        , m_end                                           , 0x818)
        SCHEMA_FIELD(::QAngle                        , m_start                                         , 0x824)
    };

    class CMomentaryRotButton : public CRotButton {
    public:
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_Position                                      , 0x8E8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUnpressed                                   , 0x908)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyOpen                                   , 0x920)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyClosed                                 , 0x938)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnReachedPosition                             , 0x950)
        SCHEMA_FIELD(std::int32_t                    , m_lastUsed                                      , 0x968)
        SCHEMA_FIELD(::QAngle                        , m_start                                         , 0x96C)
        SCHEMA_FIELD(::QAngle                        , m_end                                           , 0x978)
        SCHEMA_FIELD(float                           , m_IdealYaw                                      , 0x984)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sNoise                                        , 0x988)
        SCHEMA_FIELD(bool                            , m_bUpdateTarget                                 , 0x990)
        SCHEMA_FIELD(std::int32_t                    , m_direction                                     , 0x994)
        SCHEMA_FIELD(float                           , m_returnSpeed                                   , 0x998)
        SCHEMA_FIELD(float                           , m_flStartPosition                               , 0x99C)
    };

    class CMarkupVolumeTagged_NavGame : public CMarkupVolumeWithRef {
    public:
        SCHEMA_FIELD(NavScopeFlags_t                 , m_nScopes                                       , 0x7D0)
        SCHEMA_FIELD(bool                            , m_bFloodFillAttribute                           , 0x7D1)
        SCHEMA_FIELD(bool                            , m_bSplitNavSpace                                , 0x7D2)
    };

    class CHostage : public CHostageExpresserShim {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnHostageBeginGrab                            , 0xA28)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFirstPickedUp                               , 0xA40)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnDroppedNotRescued                           , 0xA58)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnRescued                                     , 0xA70)
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0xA88)
        SCHEMA_FIELD(std::int32_t                    , m_nSpotRules                                    , 0xAA0)
        SCHEMA_FIELD(std::uint32_t                   , m_uiHostageSpawnExclusionGroupMask              , 0xAA4)
        SCHEMA_FIELD(std::uint32_t                   , m_nHostageSpawnRandomFactor                     , 0xAA8)
        SCHEMA_FIELD(bool                            , m_bRemove                                       , 0xAAC)
        SCHEMA_FIELD(::Vector                        , m_vel                                           , 0xAB0)
        SCHEMA_FIELD(bool                            , m_isRescued                                     , 0xABC)
        SCHEMA_FIELD(bool                            , m_jumpedThisFrame                               , 0xABD)
        SCHEMA_FIELD(std::int32_t                    , m_nHostageState                                 , 0xAC0)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_leader                                        , 0xAC4)
        SCHEMA_FIELD(CHandle<CCSPlayerPawnBase>      , m_lastLeader                                    , 0xAC8)
        SCHEMA_FIELD(CountdownTimer                  , m_reuseTimer                                    , 0xAD0)
        SCHEMA_FIELD(bool                            , m_hasBeenUsed                                   , 0xAE8)
        SCHEMA_FIELD(::Vector                        , m_accel                                         , 0xAEC)
        SCHEMA_FIELD(bool                            , m_isRunning                                     , 0xAF8)
        SCHEMA_FIELD(bool                            , m_isCrouching                                   , 0xAF9)
        SCHEMA_FIELD(CountdownTimer                  , m_jumpTimer                                     , 0xB00)
        SCHEMA_FIELD(bool                            , m_isWaitingForLeader                            , 0xB18)
        SCHEMA_FIELD(CountdownTimer                  , m_repathTimer                                   , 0x2B28)
        SCHEMA_FIELD(CountdownTimer                  , m_inhibitDoorTimer                              , 0x2B40)
        SCHEMA_FIELD(CountdownTimer                  , m_inhibitObstacleAvoidanceTimer                 , 0x2BD0)
        SCHEMA_FIELD(CountdownTimer                  , m_wiggleTimer                                   , 0x2BF0)
        SCHEMA_FIELD(bool                            , m_isAdjusted                                    , 0x2C0C)
        SCHEMA_FIELD(bool                            , m_bHandsHaveBeenCut                             , 0x2C0D)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hHostageGrabber                               , 0x2C10)
        SCHEMA_FIELD(::GameTime_t                    , m_fLastGrabTime                                 , 0x2C14)
        SCHEMA_FIELD(::Vector                        , m_vecPositionWhenStartedDroppingToGround        , 0x2C18)
        SCHEMA_FIELD(::Vector                        , m_vecGrabbedPos                                 , 0x2C24)
        SCHEMA_FIELD(::GameTime_t                    , m_flRescueStartTime                             , 0x2C30)
        SCHEMA_FIELD(::GameTime_t                    , m_flGrabSuccessTime                             , 0x2C34)
        SCHEMA_FIELD(::GameTime_t                    , m_flDropStartTime                               , 0x2C38)
        SCHEMA_FIELD(std::int32_t                    , m_nApproachRewardPayouts                        , 0x2C3C)
        SCHEMA_FIELD(std::int32_t                    , m_nPickupEventCount                             , 0x2C40)
        SCHEMA_FIELD(::Vector                        , m_vecSpawnGroundPos                             , 0x2C44)
        SCHEMA_FIELD(VectorWS                        , m_vecHostageResetPosition                       , 0x2C7C)
    };

    class CCSPlayerPawnBase : public CBasePlayerPawn {
    public:
        SCHEMA_FIELD(CTouchExpansionComponent        , m_CTouchExpansionComponent                      , 0xBC0)
        SCHEMA_FIELD(CCSPlayer_PingServices*         , m_pPingServices                                 , 0xC10)
        SCHEMA_FIELD(::GameTime_t                    , m_blindUntilTime                                , 0xC18)
        SCHEMA_FIELD(::GameTime_t                    , m_blindStartTime                                , 0xC1C)
        SCHEMA_FIELD(CSPlayerState                   , m_iPlayerState                                  , 0xC20)
        SCHEMA_FIELD(bool                            , m_bRespawning                                   , 0xCD0)
        SCHEMA_FIELD(bool                            , m_bHasMovedSinceSpawn                           , 0xCD1)
        SCHEMA_FIELD(std::int32_t                    , m_iNumSpawns                                    , 0xCD4)
        SCHEMA_FIELD(float                           , m_flIdleTimeSinceLastAction                     , 0xCDC)
        SCHEMA_FIELD(float                           , m_fNextRadarUpdateTime                          , 0xCE0)
        SCHEMA_FIELD(float                           , m_flFlashDuration                               , 0xCE4)
        SCHEMA_FIELD(float                           , m_flFlashMaxAlpha                               , 0xCE8)
        SCHEMA_FIELD(float                           , m_flProgressBarStartTime                        , 0xCEC)
        SCHEMA_FIELD(std::int32_t                    , m_iProgressBarDuration                          , 0xCF0)
        SCHEMA_FIELD(CHandle<CCSPlayerController>    , m_hOriginalController                           , 0xCF4)
    };

    class CCSWeaponBase : public CBasePlayerWeapon {
    public:
        SCHEMA_FIELD(bool                            , m_bRemoveable                                   , 0xCB8)
        SCHEMA_FIELD(bool                            , m_bPlayerAmmoStockOnPickup                      , 0xCB9)
        SCHEMA_FIELD(bool                            , m_bRequireUseToTouch                            , 0xCBA)
        SCHEMA_FIELD(WeaponGameplayAnimState         , m_iWeaponGameplayAnimState                      , 0xCBC)
        SCHEMA_FIELD(::GameTime_t                    , m_flWeaponGameplayAnimStateTimestamp            , 0xCC0)
        SCHEMA_FIELD(::GameTime_t                    , m_flInspectCancelCompleteTime                   , 0xCC4)
        SCHEMA_FIELD(bool                            , m_bInspectPending                               , 0xCC8)
        SCHEMA_FIELD(bool                            , m_bInspectShouldLoop                            , 0xCC9)
        SCHEMA_FIELD(std::int32_t                    , m_nLastEmptySoundCmdNum                         , 0xCF4)
        SCHEMA_FIELD(bool                            , m_bFireOnEmpty                                  , 0xD10)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerPickup                                , 0xD18)
        SCHEMA_FIELD(CSWeaponMode                    , m_weaponMode                                    , 0xD30)
        SCHEMA_FIELD(float                           , m_flTurningInaccuracyDelta                      , 0xD34)
        SCHEMA_FIELD(::Vector                        , m_vecTurningInaccuracyEyeDirLast                , 0xD38)
        SCHEMA_FIELD(float                           , m_flTurningInaccuracy                           , 0xD44)
        SCHEMA_FIELD(float                           , m_fAccuracyPenalty                              , 0xD48)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastAccuracyUpdateTime                      , 0xD4C)
        SCHEMA_FIELD(float                           , m_fAccuracySmoothedForZoom                      , 0xD50)
        SCHEMA_FIELD(std::int32_t                    , m_iRecoilIndex                                  , 0xD54)
        SCHEMA_FIELD(float                           , m_flRecoilIndex                                 , 0xD58)
        SCHEMA_FIELD(bool                            , m_bBurstMode                                    , 0xD5C)
        SCHEMA_FIELD(::GameTick_t                    , m_nPostponeFireReadyTicks                       , 0xD60)
        SCHEMA_FIELD(float                           , m_flPostponeFireReadyFrac                       , 0xD64)
        SCHEMA_FIELD(bool                            , m_bInReload                                     , 0xD68)
        SCHEMA_FIELD(::GameTick_t                    , m_nDeployTick                                   , 0xD6C)
        SCHEMA_FIELD(::GameTime_t                    , m_flDroppedAtTime                               , 0xD70)
        SCHEMA_FIELD(bool                            , m_bIsHauledBack                                 , 0xD78)
        SCHEMA_FIELD(bool                            , m_bSilencerOn                                   , 0xD79)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeSilencerSwitchComplete                  , 0xD7C)
        SCHEMA_FIELD(float                           , m_flWeaponActionPlaybackRate                    , 0xD80)
        SCHEMA_FIELD(std::int32_t                    , m_iOriginalTeamNumber                           , 0xD84)
        SCHEMA_FIELD(std::int32_t                    , m_iMostRecentTeamNumber                         , 0xD88)
        SCHEMA_FIELD(bool                            , m_bDroppedNearBuyZone                           , 0xD8C)
        SCHEMA_FIELD(float                           , m_flNextAttackRenderTimeOffset                  , 0xD90)
        SCHEMA_FIELD(bool                            , m_bCanBePickedUp                                , 0xDA8)
        SCHEMA_FIELD(bool                            , m_bUseCanOverrideNextOwnerTouchTime             , 0xDA9)
        SCHEMA_FIELD(::GameTime_t                    , m_nextOwnerTouchTime                            , 0xDAC)
        SCHEMA_FIELD(::GameTime_t                    , m_nextPrevOwnerTouchTime                        , 0xDB0)
        SCHEMA_FIELD(::GameTime_t                    , m_nextPrevOwnerUseTime                          , 0xDB8)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_hPrevOwner                                    , 0xDBC)
        SCHEMA_FIELD(::GameTick_t                    , m_nDropTick                                     , 0xDC0)
        SCHEMA_FIELD(bool                            , m_bWasActiveWeaponWhenDropped                   , 0xDC4)
        SCHEMA_FIELD(bool                            , m_donated                                       , 0xDE4)
        SCHEMA_FIELD(::GameTime_t                    , m_fLastShotTime                                 , 0xDE8)
        SCHEMA_FIELD(bool                            , m_bWasOwnedByCT                                 , 0xDEC)
        SCHEMA_FIELD(bool                            , m_bWasOwnedByTerrorist                          , 0xDED)
        SCHEMA_FIELD(std::int32_t                    , m_numRemoveUnownedWeaponThink                   , 0xDF0)
        SCHEMA_FIELD(CIronSightController            , m_IronSightController                           , 0xE50)
        SCHEMA_FIELD(std::int32_t                    , m_iIronSightMode                                , 0xE68)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastLOSTraceFailureTime                     , 0xE6C)
        SCHEMA_FIELD(float                           , m_flWatTickOffset                               , 0xE70)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastShakeTime                               , 0xE80)
    };

    class CItemDefuserAlias_item_defuser : public CItemDefuser {
    public:
    };

    class CPhysicsProp : public CBreakableProp {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_MotionEnabled                                 , 0xAE0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAwakened                                    , 0xAF8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAwake                                       , 0xB10)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAsleep                                      , 0xB28)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerUse                                   , 0xB40)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOutOfWorld                                  , 0xB58)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerPickup                                , 0xB70)
        SCHEMA_FIELD(bool                            , m_bForceNavIgnore                               , 0xB88)
        SCHEMA_FIELD(bool                            , m_bNoNavmeshBlocker                             , 0xB89)
        SCHEMA_FIELD(bool                            , m_bForceNpcExclude                              , 0xB8A)
        SCHEMA_FIELD(float                           , m_massScale                                     , 0xB8C)
        SCHEMA_FIELD(float                           , m_buoyancyScale                                 , 0xB90)
        SCHEMA_FIELD(std::int32_t                    , m_damageType                                    , 0xB94)
        SCHEMA_FIELD(std::int32_t                    , m_damageToEnableMotion                          , 0xB98)
        SCHEMA_FIELD(float                           , m_flForceToEnableMotion                         , 0xB9C)
        SCHEMA_FIELD(bool                            , m_bThrownByPlayer                               , 0xBA0)
        SCHEMA_FIELD(bool                            , m_bDroppedByPlayer                              , 0xBA1)
        SCHEMA_FIELD(bool                            , m_bTouchedByPlayer                              , 0xBA2)
        SCHEMA_FIELD(bool                            , m_bFirstCollisionAfterLaunch                    , 0xBA3)
        SCHEMA_FIELD(bool                            , m_bHasBeenAwakened                              , 0xBA4)
        SCHEMA_FIELD(bool                            , m_bIsOverrideProp                               , 0xBA5)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastBurn                                    , 0xBA8)
        SCHEMA_FIELD(DynamicContinuousContactBehavior_t, m_nDynamicContinuousContactBehavior             , 0xBAC)
        SCHEMA_FIELD(::GameTime_t                    , m_fNextCheckDisableMotionContactsTime           , 0xBB0)
        SCHEMA_FIELD(std::int32_t                    , m_iInitialGlowState                             , 0xBB4)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRange                                    , 0xBB8)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRangeMin                                 , 0xBBC)
        SCHEMA_FIELD(::Color                         , m_glowColor                                     , 0xBC0)
        SCHEMA_FIELD(bool                            , m_bShouldAutoConvertBackFromDebris              , 0xBC4)
        SCHEMA_FIELD(bool                            , m_bMuteImpactEffects                            , 0xBC5)
        SCHEMA_FIELD(INavObstacle_NavObstacleType_t  , m_nNavObstacleType                              , 0xBC8)
        SCHEMA_FIELD(bool                            , m_bUpdateNavWhenMoving                          , 0xBCC)
        SCHEMA_FIELD(bool                            , m_bForceNavObstacleCut                          , 0xBCD)
        SCHEMA_FIELD(bool                            , m_bAllowObstacleConvexHullMerging               , 0xBCE)
        SCHEMA_FIELD(bool                            , m_bAcceptDamageFromHeldObjects                  , 0xBCF)
        SCHEMA_FIELD(bool                            , m_bEnableUseOutput                              , 0xBD0)
        SCHEMA_FIELD(CPhysicsProp_CrateType_t        , m_CrateType                                     , 0xBD4)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strItemClass                                  , 0xBD8)
        SCHEMA_FIELD(std::int32_t                    , m_nItemCount                                    , 0xBF8)
        SCHEMA_FIELD(bool                            , m_bRemovableForAmmoBalancing                    , 0xC08)
        SCHEMA_FIELD(bool                            , m_bAwake                                        , 0xC09)
        SCHEMA_FIELD(bool                            , m_bAttachedToReferenceFrame                     , 0xC0A)
    };

    class CDynamicProp : public CBreakableProp {
    public:
        SCHEMA_FIELD(bool                            , m_bCreateNavObstacle                            , 0xAD8)
        SCHEMA_FIELD(bool                            , m_bNavObstacleUpdatesOverridden                 , 0xAD9)
        SCHEMA_FIELD(bool                            , m_bUseHitboxesForRenderBox                      , 0xADA)
        SCHEMA_FIELD(bool                            , m_bUseAnimGraph                                 , 0xADB)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputAnimBegun                              , 0xAE0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputAnimOver                               , 0xAF8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputAnimLoopCycleOver                      , 0xB10)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAnimReachedStart                            , 0xB28)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAnimReachedEnd                              , 0xB40)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszIdleAnim                                   , 0xB58)
        SCHEMA_FIELD(AnimLoopMode_t                  , m_nIdleAnimLoopMode                             , 0xB60)
        SCHEMA_FIELD(bool                            , m_bRandomizeCycle                               , 0xB64)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0xB65)
        SCHEMA_FIELD(bool                            , m_bFiredStartEndOutput                          , 0xB66)
        SCHEMA_FIELD(bool                            , m_bForceNpcExclude                              , 0xB67)
        SCHEMA_FIELD(bool                            , m_bCreateNonSolid                               , 0xB68)
        SCHEMA_FIELD(bool                            , m_bIsOverrideProp                               , 0xB69)
        SCHEMA_FIELD(std::int32_t                    , m_iInitialGlowState                             , 0xB6C)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRange                                    , 0xB70)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRangeMin                                 , 0xB74)
        SCHEMA_FIELD(::Color                         , m_glowColor                                     , 0xB78)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowTeam                                     , 0xB7C)
    };

    class CDecoyProjectile : public CBaseCSGrenadeProjectile {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nDecoyShotTick                                , 0xA48)
        SCHEMA_FIELD(std::int32_t                    , m_shotsRemaining                                , 0xA4C)
        SCHEMA_FIELD(::GameTime_t                    , m_fExpireTime                                   , 0xA50)
        SCHEMA_FIELD(std::uint16_t                   , m_decoyWeaponDefIndex                           , 0xA60)
    };

    class CHEGrenadeProjectile : public CBaseCSGrenadeProjectile {
    public:
    };

    class CFlashbangProjectile : public CBaseCSGrenadeProjectile {
    public:
        SCHEMA_FIELD(float                           , m_flTimeToDetonate                              , 0xA30)
        SCHEMA_FIELD(std::uint8_t                    , m_numOpponentsHit                               , 0xA34)
        SCHEMA_FIELD(std::uint8_t                    , m_numTeammatesHit                               , 0xA35)
    };

    class CSmokeGrenadeProjectile : public CBaseCSGrenadeProjectile {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSmokeEffectTickBegin                         , 0xA58)
        SCHEMA_FIELD(bool                            , m_bDidSmokeEffect                               , 0xA5C)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0xA60)
        SCHEMA_FIELD(::Vector                        , m_vSmokeColor                                   , 0xA64)
        SCHEMA_FIELD(::Vector                        , m_vSmokeDetonationPos                           , 0xA70)
        SCHEMA_FIELD(CNetworkUtlVectorBase<uint8>    , m_VoxelFrameData                                , 0xA80)
        SCHEMA_FIELD(std::int32_t                    , m_nVoxelFrameDataSize                           , 0xA98)
        SCHEMA_FIELD(std::int32_t                    , m_nVoxelUpdate                                  , 0xA9C)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastBounce                                  , 0xAA0)
        SCHEMA_FIELD(::GameTime_t                    , m_fllastSimulationTime                          , 0xAA4)
        SCHEMA_FIELD(bool                            , m_bExplodeFromInferno                           , 0x2D28)
        SCHEMA_FIELD(bool                            , m_bDidGroundScorch                              , 0x2D29)
    };

    class CMolotovProjectile : public CBaseCSGrenadeProjectile {
    public:
        SCHEMA_FIELD(bool                            , m_bIsIncGrenade                                 , 0xA30)
        SCHEMA_FIELD(bool                            , m_bDetonated                                    , 0xA48)
        SCHEMA_FIELD(IntervalTimer                   , m_stillTimer                                    , 0xA50)
    };

    class CTriggerLook : public CTriggerOnce {
    public:
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hLookTarget                                   , 0x8E0)
        SCHEMA_FIELD(float                           , m_flFieldOfView                                 , 0x8E4)
        SCHEMA_FIELD(float                           , m_flLookTime                                    , 0x8E8)
        SCHEMA_FIELD(float                           , m_flLookTimeTotal                               , 0x8EC)
        SCHEMA_FIELD(::GameTime_t                    , m_flLookTimeLast                                , 0x8F0)
        SCHEMA_FIELD(float                           , m_flTimeoutDuration                             , 0x8F4)
        SCHEMA_FIELD(bool                            , m_bTimeoutFired                                 , 0x8F8)
        SCHEMA_FIELD(bool                            , m_bIsLooking                                    , 0x8F9)
        SCHEMA_FIELD(bool                            , m_b2DFOV                                        , 0x8FA)
        SCHEMA_FIELD(bool                            , m_bUseVelocity                                  , 0x8FB)
        SCHEMA_FIELD(bool                            , m_bTestOcclusion                                , 0x8FC)
        SCHEMA_FIELD(bool                            , m_bTestAllVisibleOcclusion                      , 0x8FD)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTimeout                                     , 0x900)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartLook                                   , 0x918)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEndLook                                     , 0x930)
    };

    class CScriptTriggerOnce : public CTriggerOnce {
    public:
        SCHEMA_FIELD(::Vector                        , m_vExtent                                       , 0x8E0)
    };

    class CFuncTrackChange : public CFuncPlatRot {
    public:
        SCHEMA_FIELD(CHandle<CPathTrack>             , m_trackTop                                      , 0x830)
        SCHEMA_FIELD(CHandle<CPathTrack>             , m_trackBottom                                   , 0x834)
        SCHEMA_FIELD(CHandle<CFuncTrackTrain>        , m_train                                         , 0x838)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_trackTopName                                  , 0x840)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_trackBottomName                               , 0x848)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_trainName                                     , 0x850)
        SCHEMA_FIELD(TRAIN_CODE                      , m_code                                          , 0x858)
        SCHEMA_FIELD(std::int32_t                    , m_targetState                                   , 0x85C)
        SCHEMA_FIELD(std::int32_t                    , m_use                                           , 0x860)
    };

    class CHostageAlias_info_hostage_spawn : public CHostage {
    public:
    };

    class CCSObserverPawn : public CCSPlayerPawnBase {
    public:
    };

    class CCSPlayerPawn : public CCSPlayerPawnBase {
    public:
        SCHEMA_FIELD(CCSPlayer_BulletServices*       , m_pBulletServices                               , 0xD08)
        SCHEMA_FIELD(CCSPlayer_HostageServices*      , m_pHostageServices                              , 0xD10)
        SCHEMA_FIELD(CCSPlayer_BuyServices*          , m_pBuyServices                                  , 0xD18)
        SCHEMA_FIELD(CCSPlayer_ActionTrackingServices*, m_pActionTrackingServices                       , 0xD20)
        SCHEMA_FIELD(CCSPlayer_AimPunchServices*     , m_pAimPunchServices                             , 0xD28)
        SCHEMA_FIELD(CCSPlayer_RadioServices*        , m_pRadioServices                                , 0xD30)
        SCHEMA_FIELD(CCSPlayer_DamageReactServices*  , m_pDamageReactServices                          , 0xD38)
        SCHEMA_FIELD(std::uint16_t                   , m_nCharacterDefIndex                            , 0xD40)
        SCHEMA_FIELD(bool                            , m_bHasFemaleVoice                               , 0xD42)
        SCHEMA_FIELD(::CUtlString                    , m_strVOPrefix                                   , 0xD48)
        SCHEMA_FIELD(char                            , m_szLastPlaceName                               , 0xD50)
        SCHEMA_FIELD(bool                            , m_bInHostageResetZone                           , 0xE40)
        SCHEMA_FIELD(bool                            , m_bInBuyZone                                    , 0xE41)
        SCHEMA_FIELD(CUtlVector<CHandle<CBaseEntity>>, m_TouchingBuyZones                              , 0xE48)
        SCHEMA_FIELD(bool                            , m_bWasInBuyZone                                 , 0xE60)
        SCHEMA_FIELD(bool                            , m_bInHostageRescueZone                          , 0xE61)
        SCHEMA_FIELD(bool                            , m_bInBombZone                                   , 0xE62)
        SCHEMA_FIELD(bool                            , m_bWasInHostageRescueZone                       , 0xE63)
        SCHEMA_FIELD(std::int32_t                    , m_iRetakesOffering                              , 0xE64)
        SCHEMA_FIELD(std::int32_t                    , m_iRetakesOfferingCard                          , 0xE68)
        SCHEMA_FIELD(bool                            , m_bRetakesHasDefuseKit                          , 0xE6C)
        SCHEMA_FIELD(bool                            , m_bRetakesMVPLastRound                          , 0xE6D)
        SCHEMA_FIELD(std::int32_t                    , m_iRetakesMVPBoostItem                          , 0xE70)
        SCHEMA_FIELD(loadout_slot_t                  , m_RetakesMVPBoostExtraUtility                   , 0xE74)
        SCHEMA_FIELD(::GameTime_t                    , m_flHealthShotBoostExpirationTime               , 0xE78)
        SCHEMA_FIELD(float                           , m_flLandingTimeSeconds                          , 0xE7C)
        SCHEMA_FIELD(bool                            , m_bIsBuyMenuOpen                                , 0xE80)
        SCHEMA_FIELD(::GameTime_t                    , m_lastLandTime                                  , 0xEB8)
        SCHEMA_FIELD(bool                            , m_bOnGroundLastTick                             , 0xEBC)
        SCHEMA_FIELD(std::int32_t                    , m_iPlayerLocked                                 , 0xEC0)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeOfLastInjury                            , 0xEC8)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextSprayDecalTime                          , 0xECC)
        SCHEMA_FIELD(bool                            , m_bNextSprayDecalTimeExpedited                  , 0xED0)
        SCHEMA_FIELD(std::int32_t                    , m_nRagdollDamageBone                            , 0xED4)
        SCHEMA_FIELD(::Vector                        , m_vRagdollDamageForce                           , 0xED8)
        SCHEMA_FIELD(::Vector                        , m_vRagdollDamagePosition                        , 0xEE4)
        SCHEMA_FIELD(char                            , m_szRagdollDamageWeaponName                     , 0xEF0)
        SCHEMA_FIELD(bool                            , m_bRagdollDamageHeadshot                        , 0xF30)
        SCHEMA_FIELD(::Vector                        , m_vRagdollServerOrigin                          , 0xF34)
        SCHEMA_FIELD(CEconItemView                   , m_EconGloves                                    , 0xF40)
        SCHEMA_FIELD(std::uint8_t                    , m_nEconGlovesChanged                            , 0x11E8)
        SCHEMA_FIELD(::QAngle                        , m_qDeathEyeAngles                               , 0x11EC)
        SCHEMA_FIELD(bool                            , m_bLeftHanded                                   , 0x11F8)
        SCHEMA_FIELD(::GameTime_t                    , m_fSwitchedHandednessTime                       , 0x11FC)
        SCHEMA_FIELD(float                           , m_flViewmodelOffsetX                            , 0x1200)
        SCHEMA_FIELD(float                           , m_flViewmodelOffsetY                            , 0x1204)
        SCHEMA_FIELD(float                           , m_flViewmodelOffsetZ                            , 0x1208)
        SCHEMA_FIELD(float                           , m_flViewmodelFOV                                , 0x120C)
        SCHEMA_FIELD(bool                            , m_bIsWalking                                    , 0x1210)
        SCHEMA_FIELD(float                           , m_fLastGivenDefuserTime                         , 0x1214)
        SCHEMA_FIELD(float                           , m_fLastGivenBombTime                            , 0x1218)
        SCHEMA_FIELD(float                           , m_flDealtDamageToEnemyMostRecentTimestamp       , 0x121C)
        SCHEMA_FIELD(std::uint32_t                   , m_iDisplayHistoryBits                           , 0x1220)
        SCHEMA_FIELD(float                           , m_flLastAttackedTeammate                        , 0x1224)
        SCHEMA_FIELD(::GameTime_t                    , m_allowAutoFollowTime                           , 0x1228)
        SCHEMA_FIELD(bool                            , m_bResetArmorNextSpawn                          , 0x122C)
        SCHEMA_FIELD(CEntityIndex                    , m_nLastKillerIndex                              , 0x1230)
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0x1238)
        SCHEMA_FIELD(std::int32_t                    , m_nSpotRules                                    , 0x1250)
        SCHEMA_FIELD(bool                            , m_bIsScoped                                     , 0x1254)
        SCHEMA_FIELD(bool                            , m_bResumeZoom                                   , 0x1255)
        SCHEMA_FIELD(bool                            , m_bIsDefusing                                   , 0x1256)
        SCHEMA_FIELD(bool                            , m_bIsGrabbingHostage                            , 0x1257)
        SCHEMA_FIELD(CSPlayerBlockingUseAction_t     , m_iBlockingUseActionInProgress                  , 0x1258)
        SCHEMA_FIELD(::GameTime_t                    , m_flEmitSoundTime                               , 0x125C)
        SCHEMA_FIELD(bool                            , m_bInNoDefuseArea                               , 0x1260)
        SCHEMA_FIELD(CEntityIndex                    , m_iBombSiteIndex                                , 0x1264)
        SCHEMA_FIELD(std::int32_t                    , m_nWhichBombZone                                , 0x1268)
        SCHEMA_FIELD(bool                            , m_bInBombZoneTrigger                            , 0x126C)
        SCHEMA_FIELD(bool                            , m_bWasInBombZoneTrigger                         , 0x126D)
        SCHEMA_FIELD(std::int32_t                    , m_iShotsFired                                   , 0x1270)
        SCHEMA_FIELD(float                           , m_flFlinchStack                                 , 0x1274)
        SCHEMA_FIELD(float                           , m_flVelocityModifier                            , 0x1278)
        SCHEMA_FIELD(::Vector                        , m_vecTotalBulletForce                           , 0x127C)
        SCHEMA_FIELD(bool                            , m_bWaitForNoAttack                              , 0x1288)
        SCHEMA_FIELD(float                           , m_ignoreLadderJumpTime                          , 0x128C)
        SCHEMA_FIELD(bool                            , m_bKilledByHeadshot                             , 0x1290)
        SCHEMA_FIELD(std::int32_t                    , m_LastHitBox                                    , 0x1294)
        SCHEMA_FIELD(CCSBot*                         , m_pBot                                          , 0x1298)
        SCHEMA_FIELD(bool                            , m_bBotAllowActive                               , 0x12A0)
        SCHEMA_FIELD(std::int32_t                    , m_nLastPickupPriority                           , 0x12A4)
        SCHEMA_FIELD(float                           , m_flLastPickupPriorityTime                      , 0x12A8)
        SCHEMA_FIELD(std::int32_t                    , m_ArmorValue                                    , 0x12AC)
        SCHEMA_FIELD(std::uint16_t                   , m_unCurrentEquipmentValue                       , 0x12B0)
        SCHEMA_FIELD(std::uint16_t                   , m_unRoundStartEquipmentValue                    , 0x12B2)
        SCHEMA_FIELD(std::uint16_t                   , m_unFreezetimeEndEquipmentValue                 , 0x12B4)
        SCHEMA_FIELD(std::int32_t                    , m_iLastWeaponFireUsercmd                        , 0x12B8)
        SCHEMA_FIELD(bool                            , m_bIsSpawning                                   , 0x12BC)
        SCHEMA_FIELD(std::int32_t                    , m_iDeathFlags                                   , 0x12C8)
        SCHEMA_FIELD(bool                            , m_bHasDeathInfo                                 , 0x12CC)
        SCHEMA_FIELD(float                           , m_flDeathInfoTime                               , 0x12D0)
        SCHEMA_FIELD(::Vector                        , m_vecDeathInfoOrigin                            , 0x12D4)
        SCHEMA_FIELD(std::uint32_t                   , m_vecPlayerPatchEconIndices                     , 0x12E0)
        SCHEMA_FIELD(::Color                         , m_GunGameImmunityColor                          , 0x12F4)
        SCHEMA_FIELD(::GameTime_t                    , m_grenadeParameterStashTime                     , 0x12F8)
        SCHEMA_FIELD(bool                            , m_bGrenadeParametersStashed                     , 0x12FC)
        SCHEMA_FIELD(::QAngle                        , m_angStashedShootAngles                         , 0x1300)
        SCHEMA_FIELD(::Vector                        , m_vecStashedGrenadeThrowPosition                , 0x130C)
        SCHEMA_FIELD(::Vector                        , m_vecStashedVelocity                            , 0x1318)
        SCHEMA_FIELD(::QAngle                        , m_angShootAngleHistory                          , 0x1324)
        SCHEMA_FIELD(::Vector                        , m_vecThrowPositionHistory                       , 0x133C)
        SCHEMA_FIELD(::Vector                        , m_vecVelocityHistory                            , 0x1354)
        SCHEMA_FIELD(bool                            , m_bCommittingSuicideOnTeamChange                , 0x1378)
        SCHEMA_FIELD(bool                            , m_wasNotKilledNaturally                         , 0x1379)
        SCHEMA_FIELD(::GameTime_t                    , m_fImmuneToGunGameDamageTime                    , 0x137C)
        SCHEMA_FIELD(bool                            , m_bGunGameImmunity                              , 0x1380)
        SCHEMA_FIELD(float                           , m_fMolotovDamageTime                            , 0x1384)
        SCHEMA_FIELD(::QAngle                        , m_angEyeAngles                                  , 0x1388)
    };

    class CCSWeaponBaseShotgun : public CCSWeaponBase {
    public:
    };

    class CKnife : public CCSWeaponBase {
    public:
        SCHEMA_FIELD(bool                            , m_bFirstAttack                                  , 0x1030)
    };

    class CBaseCSGrenade : public CCSWeaponBase {
    public:
        SCHEMA_FIELD(bool                            , m_bRedraw                                       , 0x1030)
        SCHEMA_FIELD(bool                            , m_bIsHeldByPlayer                               , 0x1031)
        SCHEMA_FIELD(bool                            , m_bPinPulled                                    , 0x1032)
        SCHEMA_FIELD(bool                            , m_bJumpThrow                                    , 0x1033)
        SCHEMA_FIELD(bool                            , m_bThrowAnimating                               , 0x1034)
        SCHEMA_FIELD(::GameTime_t                    , m_fThrowTime                                    , 0x1038)
        SCHEMA_FIELD(float                           , m_flThrowStrength                               , 0x103C)
        SCHEMA_FIELD(::GameTime_t                    , m_fDropTime                                     , 0x1040)
        SCHEMA_FIELD(::GameTime_t                    , m_fPinPullTime                                  , 0x1044)
        SCHEMA_FIELD(bool                            , m_bJustPulledPin                                , 0x1048)
        SCHEMA_FIELD(::GameTick_t                    , m_nNextHoldTick                                 , 0x104C)
        SCHEMA_FIELD(float                           , m_flNextHoldFrac                                , 0x1050)
        SCHEMA_FIELD(CHandle<CCSWeaponBase>          , m_hSwitchToWeaponAfterThrow                     , 0x1054)
    };

    class CWeaponBaseItem : public CCSWeaponBase {
    public:
        SCHEMA_FIELD(bool                            , m_bSequenceInProgress                           , 0x1030)
        SCHEMA_FIELD(bool                            , m_bRedraw                                       , 0x1031)
    };

    class CC4 : public CCSWeaponBase {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecLastValidPlayerHeldPosition                , 0x1060)
        SCHEMA_FIELD(::Vector                        , m_vecLastValidDroppedPosition                   , 0x106C)
        SCHEMA_FIELD(bool                            , m_bDoValidDroppedPositionCheck                  , 0x1078)
        SCHEMA_FIELD(bool                            , m_bStartedArming                                , 0x1079)
        SCHEMA_FIELD(::GameTime_t                    , m_fArmedTime                                    , 0x107C)
        SCHEMA_FIELD(bool                            , m_bBombPlacedAnimation                          , 0x1080)
        SCHEMA_FIELD(bool                            , m_bIsPlantingViaUse                             , 0x1081)
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0x1088)
        SCHEMA_FIELD(std::int32_t                    , m_nSpotRules                                    , 0x10A0)
        SCHEMA_FIELD(bool                            , m_bPlayedArmingBeeps                            , 0x10A4)
        SCHEMA_FIELD(bool                            , m_bBombPlanted                                  , 0x10AB)
    };

    class CCSWeaponBaseGun : public CCSWeaponBase {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_zoomLevel                                     , 0x1030)
        SCHEMA_FIELD(std::int32_t                    , m_iBurstShotsRemaining                          , 0x1034)
        SCHEMA_FIELD(std::int32_t                    , m_silencedModelIndex                            , 0x1040)
        SCHEMA_FIELD(bool                            , m_inPrecache                                    , 0x1044)
        SCHEMA_FIELD(bool                            , m_bNeedsBoltAction                              , 0x1045)
        SCHEMA_FIELD(std::int32_t                    , m_nRevolverCylinderIdx                          , 0x1048)
        SCHEMA_FIELD(bool                            , m_bSkillReloadAvailable                         , 0x104C)
        SCHEMA_FIELD(bool                            , m_bSkillReloadLiftedReloadKey                   , 0x104D)
        SCHEMA_FIELD(bool                            , m_bSkillBoltInterruptAvailable                  , 0x104E)
        SCHEMA_FIELD(bool                            , m_bSkillBoltLiftedFireKey                       , 0x104F)
    };

    class CShatterGlassShardPhysics : public CPhysicsProp {
    public:
        SCHEMA_FIELD(bool                            , m_bDebris                                       , 0xC10)
        SCHEMA_FIELD(std::uint32_t                   , m_hParentShard                                  , 0xC14)
        SCHEMA_FIELD(shard_model_desc_t              , m_ShardDesc                                     , 0xC18)
    };

    class CPhysicsPropRespawnable : public CPhysicsProp {
    public:
        SCHEMA_FIELD(VectorWS                        , m_vOriginalSpawnOrigin                          , 0xC10)
        SCHEMA_FIELD(::QAngle                        , m_vOriginalSpawnAngles                          , 0xC1C)
        SCHEMA_FIELD(::Vector                        , m_vOriginalMins                                 , 0xC28)
        SCHEMA_FIELD(::Vector                        , m_vOriginalMaxs                                 , 0xC34)
        SCHEMA_FIELD(float                           , m_flRespawnDuration                             , 0xC40)
    };

    class CPhysicsPropMultiplayer : public CPhysicsProp {
    public:
    };

    class CPhysicsPropOverride : public CPhysicsProp {
    public:
    };

    class CFuncRetakeBarrier : public CDynamicProp {
    public:
    };

    class CDynamicPropAlias_prop_dynamic_override : public CDynamicProp {
    public:
    };

    class COrnamentProp : public CDynamicProp {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_initialOwner                                  , 0xB80)
    };

    class CDynamicPropAlias_cable_dynamic : public CDynamicProp {
    public:
    };

    class CChicken : public CDynamicProp {
    public:
        SCHEMA_FIELD(CAttributeContainer             , m_AttributeManager                              , 0xBA0)
        SCHEMA_FIELD(CountdownTimer                  , m_updateTimer                                   , 0xE98)
        SCHEMA_FIELD(::Vector                        , m_stuckAnchor                                   , 0xEB0)
        SCHEMA_FIELD(CountdownTimer                  , m_stuckTimer                                    , 0xEC0)
        SCHEMA_FIELD(CountdownTimer                  , m_collisionStuckTimer                           , 0xED8)
        SCHEMA_FIELD(bool                            , m_isOnGround                                    , 0xEF0)
        SCHEMA_FIELD(::Vector                        , m_vFallVelocity                                 , 0xEF4)
        SCHEMA_FIELD(ChickenActivity                 , m_desiredActivity                               , 0xF00)
        SCHEMA_FIELD(ChickenActivity                 , m_currentActivity                               , 0xF04)
        SCHEMA_FIELD(CountdownTimer                  , m_activityTimer                                 , 0xF08)
        SCHEMA_FIELD(float                           , m_turnRate                                      , 0xF20)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_fleeFrom                                      , 0xF24)
        SCHEMA_FIELD(CountdownTimer                  , m_moveRateThrottleTimer                         , 0xF28)
        SCHEMA_FIELD(CountdownTimer                  , m_startleTimer                                  , 0xF40)
        SCHEMA_FIELD(CountdownTimer                  , m_vocalizeTimer                                 , 0xF58)
        SCHEMA_FIELD(::GameTime_t                    , m_flWhenZombified                               , 0xF70)
        SCHEMA_FIELD(bool                            , m_jumpedThisFrame                               , 0xF74)
        SCHEMA_FIELD(CHandle<CCSPlayerPawn>          , m_leader                                        , 0xF78)
        SCHEMA_FIELD(CountdownTimer                  , m_reuseTimer                                    , 0xF90)
        SCHEMA_FIELD(bool                            , m_hasBeenUsed                                   , 0xFA8)
        SCHEMA_FIELD(CountdownTimer                  , m_jumpTimer                                     , 0xFB0)
        SCHEMA_FIELD(float                           , m_flLastJumpTime                                , 0xFC8)
        SCHEMA_FIELD(bool                            , m_bInJump                                       , 0xFCC)
        SCHEMA_FIELD(CountdownTimer                  , m_repathTimer                                   , 0x2FD8)
        SCHEMA_FIELD(::Vector                        , m_vecPathGoal                                   , 0x3070)
        SCHEMA_FIELD(::GameTime_t                    , m_flActiveFollowStartTime                       , 0x307C)
        SCHEMA_FIELD(CountdownTimer                  , m_followMinuteTimer                             , 0x3080)
        SCHEMA_FIELD(CountdownTimer                  , m_BlockDirectionTimer                           , 0x30A0)
    };

    class CBasePropDoor : public CDynamicProp {
    public:
        SCHEMA_FIELD(float                           , m_flAutoReturnDelay                             , 0xB90)
        SCHEMA_FIELD(CUtlVector<CHandle<CBasePropDoor>>, m_hDoorList                                     , 0xB98)
        SCHEMA_FIELD(std::int32_t                    , m_nHardwareType                                 , 0xBB0)
        SCHEMA_FIELD(bool                            , m_bNeedsHardware                                , 0xBB4)
        SCHEMA_FIELD(DoorState_t                     , m_eDoorState                                    , 0xBB8)
        SCHEMA_FIELD(bool                            , m_bLocked                                       , 0xBBC)
        SCHEMA_FIELD(bool                            , m_bNoNPCs                                       , 0xBBD)
        SCHEMA_FIELD(::Vector                        , m_closedPosition                                , 0xBC0)
        SCHEMA_FIELD(::QAngle                        , m_closedAngles                                  , 0xBCC)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hBlocker                                      , 0xBD8)
        SCHEMA_FIELD(bool                            , m_bFirstBlocked                                 , 0xBDC)
        SCHEMA_FIELD(locksound_t                     , m_ls                                            , 0xBE0)
        SCHEMA_FIELD(bool                            , m_bForceClosed                                  , 0xC00)
        SCHEMA_FIELD(VectorWS                        , m_vecLatchWorldPosition                         , 0xC04)
        SCHEMA_FIELD(CHandle<CBaseEntity>            , m_hActivator                                    , 0xC10)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundMoving                                   , 0xC28)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundOpen                                     , 0xC30)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundClose                                    , 0xC38)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundLock                                     , 0xC40)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundUnlock                                   , 0xC48)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundLatch                                    , 0xC50)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundPound                                    , 0xC58)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundJiggle                                   , 0xC60)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SoundLockedAnim                               , 0xC68)
        SCHEMA_FIELD(std::int32_t                    , m_numCloseAttempts                              , 0xC70)
        SCHEMA_FIELD(CUtlStringToken                 , m_nPhysicsMaterial                              , 0xC74)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_SlaveName                                     , 0xC78)
        SCHEMA_FIELD(CHandle<CBasePropDoor>          , m_hMaster                                       , 0xC80)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBlockedClosing                              , 0xC88)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBlockedOpening                              , 0xCA0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUnblockedClosing                            , 0xCB8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnUnblockedOpening                            , 0xCD0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyClosed                                 , 0xCE8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFullyOpen                                   , 0xD00)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnClose                                       , 0xD18)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnOpen                                        , 0xD30)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnLockedUse                                   , 0xD48)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAjarOpen                                    , 0xD60)
    };

    class CDynamicPropAlias_dynamic_prop : public CDynamicProp {
    public:
    };

    class CFuncTrackAuto : public CFuncTrackChange {
    public:
    };

    class CWeaponNOVA : public CCSWeaponBaseShotgun {
    public:
    };

    class CWeaponSawedoff : public CCSWeaponBaseShotgun {
    public:
    };

    class CWeaponXM1014 : public CCSWeaponBaseShotgun {
    public:
    };

    class CHEGrenade : public CBaseCSGrenade {
    public:
    };

    class CSmokeGrenade : public CBaseCSGrenade {
    public:
    };

    class CMolotovGrenade : public CBaseCSGrenade {
    public:
    };

    class CFlashbang : public CBaseCSGrenade {
    public:
    };

    class CDecoyGrenade : public CBaseCSGrenade {
    public:
    };

    class CItem_Healthshot : public CWeaponBaseItem {
    public:
    };

    class CWeaponRevolver : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponBizon : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponSCAR20 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponAWP : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponSG556 : public CCSWeaponBaseGun {
    public:
    };

    class CDEagle : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponFamas : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponUMP45 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponHKP2000 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponFiveSeven : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponM4A1Silencer : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponNegev : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponElite : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponM249 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponMP5SD : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponUSPSilencer : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponMag7 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponM4A1 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponMAC10 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponP250 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponG3SG1 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponGlock : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponGalilAR : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponMP7 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponAug : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponSSG08 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponP90 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponTaser : public CCSWeaponBaseGun {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_fFireTime                                     , 0x1050)
        SCHEMA_FIELD(std::int32_t                    , m_nLastAttackTick                               , 0x1054)
    };

    class CWeaponCZ75a : public CCSWeaponBaseGun {
    public:
        SCHEMA_FIELD(bool                            , m_bMagazineRemoved                              , 0x1050)
    };

    class CWeaponMP9 : public CCSWeaponBaseGun {
    public:
    };

    class CWeaponTec9 : public CCSWeaponBaseGun {
    public:
    };

    class CAK47 : public CCSWeaponBaseGun {
    public:
    };

    class CPropDoorRotating : public CBasePropDoor {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecAxis                                       , 0xD80)
        SCHEMA_FIELD(float                           , m_flDistance                                    , 0xD8C)
        SCHEMA_FIELD(PropDoorRotatingSpawnPos_t      , m_eSpawnPosition                                , 0xD90)
        SCHEMA_FIELD(PropDoorRotatingOpenDirection_e , m_eOpenDirection                                , 0xD94)
        SCHEMA_FIELD(PropDoorRotatingOpenDirection_e , m_eCurrentOpenDirection                         , 0xD98)
        SCHEMA_FIELD(doorCheck_e                     , m_eDefaultCheckDirection                        , 0xD9C)
        SCHEMA_FIELD(float                           , m_flAjarAngle                                   , 0xDA0)
        SCHEMA_FIELD(::QAngle                        , m_angRotationAjarDeprecated                     , 0xDA4)
        SCHEMA_FIELD(::QAngle                        , m_angRotationClosed                             , 0xDB0)
        SCHEMA_FIELD(::QAngle                        , m_angRotationOpenForward                        , 0xDBC)
        SCHEMA_FIELD(::QAngle                        , m_angRotationOpenBack                           , 0xDC8)
        SCHEMA_FIELD(::QAngle                        , m_angGoal                                       , 0xDD4)
        SCHEMA_FIELD(::Vector                        , m_vecForwardBoundsMin                           , 0xDE0)
        SCHEMA_FIELD(::Vector                        , m_vecForwardBoundsMax                           , 0xDEC)
        SCHEMA_FIELD(::Vector                        , m_vecBackBoundsMin                              , 0xDF8)
        SCHEMA_FIELD(::Vector                        , m_vecBackBoundsMax                              , 0xE04)
        SCHEMA_FIELD(bool                            , m_bAjarDoorShouldntAlwaysOpen                   , 0xE10)
        SCHEMA_FIELD(CHandle<CEntityBlocker>         , m_hEntityBlocker                                , 0xE14)
    };

    class CIncendiaryGrenade : public CMolotovGrenade {
    public:
    };

    class CPropDoorRotatingBreakable : public CPropDoorRotating {
    public:
        SCHEMA_FIELD(bool                            , m_bBreakable                                    , 0xE20)
        SCHEMA_FIELD(bool                            , m_isAbleToCloseAreaPortals                      , 0xE21)
        SCHEMA_FIELD(std::int32_t                    , m_currentDamageState                            , 0xE24)
        SCHEMA_FIELD(CUtlVector<CUtlSymbolLarge>     , m_damageStates                                  , 0xE28)
    };

    class CEconItem {
    public:
        SCHEMA_FIELD(std::uint64_t                   , m_ulID                                          , 0x10)
        SCHEMA_FIELD(std::uint64_t                   , m_ulOriginalID                                  , 0x18)
        SCHEMA_FIELD(void*                           , m_pCustomData                                   , 0x20)
        SCHEMA_FIELD(std::uint32_t                   , m_unAccountID                                   , 0x28)
        SCHEMA_FIELD(std::uint32_t                   , m_unInventory                                   , 0x2C)
        SCHEMA_FIELD(std::uint16_t                   , m_unDefIndex                                    , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , m_nQuality                                      , 0x32)
        SCHEMA_FIELD(std::uint16_t                   , m_nRarity                                       , 0x32)
        SCHEMA_FIELD(std::uint16_t                   , m_iItemSet                                      , 0x34)
        SCHEMA_FIELD(bool                            , m_bSOUpdateFrame                                , 0x38)
        SCHEMA_FIELD(std::uint32_t                   , m_unFlags                                       , 0x3C)
    };

}
