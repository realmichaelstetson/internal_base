

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::client {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    enum class InputButton : std::uint64_t {
        attack = 0x204F990,
        attack2 = 0x204FA20,
        back = 0x204FC60,
        duck = 0x204FF30,
        forward = 0x204FBD0,
        jump = 0x204FEA0,
        left = 0x204FCF0,
        lookatweapon = 0x233FB20,
        reload = 0x204F900,
        right = 0x204FD80,
        showscores = 0x233FA00,
        sprint = 0x204F870,
        turnleft = 0x204FAB0,
        turnright = 0x204FB40,
        use = 0x204FE10,
        zoom = 0x233FA90,
    };

    class C_CSGO_TeamIntroCharacterPosition;
    class C_FireCrackerBlast;
    class CCSGO_WingmanIntroCounterTerroristPosition;
    class CPulseCell_WaitForCursorsWithTag;
    class C_SceneEntity_QueuedEvents_t;
    class CCSPlayer_PingServices;
    class CEconItemAttribute;
    class CBaseTriggerAPI;
    class CFuncRetakeBarrier;
    class C_EnvWindShared;
    class C_SkyCamera;
    class CPulseCell_Base;
    class C_FuncRotating;
    class C_SoundOpvarSetPointBase;
    class C_EnvCubemapFog;
    class C_CSGO_TeamSelectTerroristPosition;
    class C_EnvParticleGlow;
    class CCS_PortraitWorldCallbackHandler;
    class CCSPlayerController_InventoryServices;
    class CCSPlayerModernJump;
    class C_EconEntity_AttachedModelData_t;
    class CPulse_ResumePoint;
    class CTriggerFan;
    class C_HostageCarriableProp;
    class C_BulletHitModel;
    class C_FuncElectrifiedVolume;
    class C_MapVetoPickController;
    class C_EnvVolumetricFogVolume;
    class C_CSGO_EndOfMatchCharacterPosition;
    class CPulseCell_PlaySequence;
    class C_BaseEntityAPI;
    class C_BarnLight;
    class CPulseCell_LerpCameraSettings;
    class CPointOffScreenIndicatorUi;
    class CCSObserver_UseServices;
    class C_PostProcessingVolume;
    class CCSPlayer_UseServices;
    class C_BaseModelEntity_Emphasized_Phoneme;
    class C_CSGO_CounterTerroristWingmanIntroCamera;
    class CPulseCell_PickBestOutflowSelector;
    class CInfoFan;
    class C_VoteController;
    class C_C4;
    class C_CSPlayerPawnBase;
    class C_BreakableProp;
    class CCSGO_WingmanIntroTerroristPosition;
    class CPrecipitationVData;
    class C_RetakeGameRules;
    class CPulseCell_WaitForObservable;
    class C_SoundAreaEntitySphere;
    class CPulseCell_Step_EntFire;
    class C_WeaponAWP;
    class C_BaseButton;
    class CCSObserver_ObserverServices;
    class CHitboxComponent;
    class ServerAuthoritativeWeaponSlot_t;
    class C_CSMinimapBoundary;
    class CPathQueryComponent;
    class C_Precipitation;
    class CLogicRelay;
    class SequenceHistory_t;
    class CPlayer_ItemServices;
    class CPulse_OutflowConnection;
    class C_WeaponUMP45;
    class C_WeaponG3SG1;
    class C_SpotlightEnd;
    class C_Fish;
    class C_WeaponFamas;
    class C_EnvVolumetricFogController;
    class CPulseGraphDef;
    class C_EnvDetailController;
    class C_EnvWindVolume;
    class CBasePlayerControllerAPI;
    class CHostageRescueZoneShim;
    class CEnvSoundscapeAlias_snd_soundscape;
    class CCSPlayer_HostageServices;
    class C_GameRulesProxy;
    class CRenderComponent;
    class C_Team;
    class C_PathParticleRopeAlias_path_particle_rope_clientside;
    class CPointChildModifier;
    class CCSPlayerLegacyJump;
    class C_WeaponNOVA;
    class C_CS2HudModelAddon;
    class C_DEagle;
    class C_TriggerMultiple;
    class C_CSGO_TeamPreviewCamera;
    class C_ColorCorrectionVolume;
    class CPlayer_MovementServices;
    class CInfoDynamicShadowHintBox;
    class CBaseAnimGraphController;
    class C_ColorCorrection;
    class AnimGraph2SerializedPoseRecipeSlot_t;
    class CBuoyancyHelper;
    class C_PhysBox;
    class CCSPlayer_CameraServices;
    class CFilterMultiple;
    class CPulseCell_FireCursors;
    class CEnvSoundscape;
    class C_SoundEventEntityAlias_snd_event_point;
    class C_FogController;
    class C_SoundOpvarSetOBBWindEntity;
    class C_MolotovGrenade;
    class C_NetTestBaseCombatCharacter;
    class CBodyComponentPoint;
    class C_WeaponM4A1Silencer;
    class C_EconItemView;
    class CPulseCell_Timeline_TimelineEvent_t;
    class CPulseCell_IntervalTimer_CursorState_t;
    class CPulseCell_BaseRequirement;
    class CPulseCell_BaseState;
    class OutflowWithRequirements_t;
    class CPulseCell_IsRequirementValid;
    class C_SoundEventPathCornerEntity;
    class C_InfoVisibilityBox;
    class CCSPlayer_ItemServices;
    class CPulseCell_Value_Gradient;
    class IntervalTimer;
    class audioparams_t;
    class C_PathParticleRope;
    class C_DecoyProjectile;
    class C_AttributeContainer;
    class C_CSWeaponBase;
    class CTimeline;
    class CPulseCursorFuncs;
    class C_TonemapController2;
    class CountdownTimer;
    class PulseNodeDynamicOutflows_t_DynamicOutflow_t;
    class C_WeaponMag7;
    class WeaponPurchaseCount_t;
    class CBasePulseGraphInstance;
    class FilterHealth;
    class C_PointClientUIHUD;
    class CPulseCell_Inflow_GraphHook;
    class SignatureOutflow_Resume;
    class CPathSimpleAPI;
    class C_InfoLadderDismount;
    class C_PointCommentaryNode;
    class CSpriteOriented;
    class shard_model_desc_t;
    class C_KeychainModule;
    class CFuncWater;
    class CCSPlayer_GlowServices;
    class CCSGameModeRules;
    class C_Flashbang;
    class C_PointClientUIWorldTextPanel;
    class CCSPlayer_WaterServices;
    class C_CSObserverPawn;
    class ViewAngleServerChange_t;
    class C_FuncLadder;
    class C_WeaponMP5SD;
    class C_World;
    class C_CSGO_TeamSelectCounterTerroristPosition;
    class C_WeaponGalilAR;
    class CCSPlayerBase_CameraServices;
    class C_TeamplayRules;
    class CPulseCell_Inflow_BaseEntrypoint;
    class C_WeaponSG556;
    class C_CSPlayerPawn;
    class C_CSGO_TeamIntroTerroristPosition;
    class CPulseCell_WaitForCursorsWithTagBase;
    class C_Hostage;
    class C_fogplayerparams_t;
    class CGameSceneNode;
    class CPlayer_ObserverServices;
    class CCashStack;
    class C_SoundAreaEntityBase;
    class C_PlayerVisibility;
    class CAttributeManager_cached_attribute_float_t;
    class C_BasePlayerWeapon;
    class CRagdollManager;
    class C_HEGrenade;
    class C_EnvSky;
    class CPulse_InvokeBinding;
    class C_EnvWindController;
    class C_GameRules;
    class C_WeaponMAC10;
    class C_CSGO_MapPreviewCameraPath;
    class C_PointWorldText;
    class C_RopeKeyframe;
    class C_BaseToggle;
    class C_EnvCubemapBox;
    class C_EnvCombinedLightProbeVolumeAlias_func_combined_light_probe_volume;
    class C_RopeKeyframe_CPhysicsDelegate;
    class CInfoDynamicShadowHint;
    class CPathNode;
    class C_FuncMoveLinear;
    class CServerOnlyModelEntity;
    class C_CSGO_TeamSelectCamera;
    class CPulseCell_IntervalTimer;
    class C_WeaponXM1014;
    class C_WorldModelGloves;
    class C_PhysicsPropMultiplayer;
    class C_SoundEventOBBEntity;
    class CPulseTestScriptLib;
    class CPulseCell_BaseLerp;
    class C_WeaponAug;
    class C_BasePropDoor;
    class CChoreoInfoTarget;
    class CTakeDamageResultAPI;
    class CNetworkedSequenceOperation;
    class C_Item_Healthshot;
    class CEntityInstance;
    class C_BaseModelEntity;
    class CCSPlayer_BulletServices;
    class C_SoundOpvarSetAutoRoomEntity;
    class C_EnvCombinedLightProbeVolume;
    class CCSGO_EndOfMatchLineupEnd;
    class C_MultiplayRules;
    class CPlayer_AutoaimServices;
    class C_LightDirectionalEntity;
    class C_BaseEntity;
    class ActiveModelConfig_t;
    class C_WeaponSSG08;
    class CPulseCell_Value_Curve;
    class C_Chicken;
    class C_BasePlayerPawn;
    class C_SoundOpvarSetAABBEntity;
    class C_WeaponBizon;
    class C_StattrakModule;
    class CCSObserver_CameraServices;
    class CEnvSoundscapeProxy;
    class C_SoundEventEntity;
    class CPulseCell_Inflow_EventHandler;
    class C_LightOrthoEntity;
    class CPulseCell_BaseFlow;
    class CBombTarget;
    class C_Knife;
    class C_CSGO_TerroristWingmanIntroCamera;
    class CSkeletonInstance;
    class CEntityComponent;
    class C_ItemDogtags;
    class C_LateUpdatedAnimating;
    class CPulseCell_Outflow_CycleShuffled_InstanceState_t;
    class CPulseCell_BaseLerp_CursorState_t;
    class CPulseAnimFuncs;
    class C_BaseClientUIEntity;
    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t;
    class CPulseArraylib;
    class C_WeaponUSPSilencer;
    class C_MolotovProjectile;
    class C_TriggerLerpObject;
    class CPointTemplateAPI;
    class C_WeaponRevolver;
    class C_WeaponElite;
    class C_DynamicPropAlias_cable_dynamic;
    class CBaseProp;
    class CInfoOffscreenPanoramaTexture;
    class CCSWeaponBaseVData;
    class CAttributeManager;
    class SignatureOutflow_Continue;
    class CInfoTarget;
    class CPlayer_CameraServices;
    class CPulseCell_Timeline;
    class CPulseCell_Inflow_EntOutputHandler;
    class C_BaseCSGrenade;
    class CScenePayloadVData;
    class CFilterAttributeInt;
    class CPointTemplate;
    class CPlayer_FlashlightServices;
    class CCSPlayerController;
    class C_CSGO_TeamIntroCounterTerroristPosition;
    class C_CSGO_PreviewModel;
    class C_CSGO_TeamSelectCharacterPosition;
    class CPulseCell_Outflow_CycleOrdered_InstanceState_t;
    class C_SoundEventAABBEntity;
    class CCSPlayer_MovementServices;
    class SellbackPurchaseEntry_t;
    class C_TintController;
    class C_WeaponBaseItem;
    class CWaterSplasher;
    class C_FuncBrush;
    class PhysicsRagdollPose_t;
    class CPropDataComponent;
    class CPulseCell_LimitCount_InstanceState_t;
    class C_WeaponCZ75a;
    class C_DynamicLight;
    class CCS2PawnGraphController;
    class EngineCountdownTimer;
    class C_SoundEventSphereEntity;
    class CCSPlayerController_DamageServices;
    class C_CSGO_TeamPreviewModel;
    class C_TonemapController2Alias_env_tonemap_controller2;
    class C_Inferno;
    class CFilterLOS;
    class CPointOrient;
    class C_GlobalLight;
    class C_EnvWindClientside;
    class sky3dparams_t;
    class C_FlashbangProjectile;
    class C_SoundEventConeEntity;
    class CDestructiblePartsComponent;
    class C_WeaponP90;
    class C_EnvWind;
    class C_CSGO_TerroristTeamIntroCamera;
    class CPulseCell_Step_DebugLog;
    class CCSPlayerController_ActionTrackingServices;
    class CBodyComponentBaseAnimGraph;
    class C_CSGO_PreviewModelAlias_csgo_item_previewmodel;
    class C_InfoInstructorHintHostageRescueZone;
    class CPulseCell_BaseYieldingInflow;
    class PulseNodeDynamicOutflows_t;
    class C_TriggerBuoyancy;
    class CPlayer_MovementServices_Humanoid;
    class CPulseCell_IsRequirementValid_Criteria_t;
    class C_WeaponTec9;
    class C_PhysPropClientside;
    class C_BaseDoor;
    class CSMatchStats_t;
    class EntityRenderAttribute_t;
    class CPulseCell_Inflow_ObservableVariableListener;
    class CFilterMultipleAPI;
    class CHostageRescueZone;
    class CModelState;
    class CPulseCell_LerpCameraSettings_CursorState_t;
    class CPulseCell_Outflow_CycleOrdered;
    class C_CSWeaponBaseGun;
    class C_CSGameRulesProxy;
    class CCollisionProperty;
    class C_WeaponP250;
    class C_ShatterGlassShardPhysics;
    class CFilterMassGreater;
    class C_EntityDissolve;
    class C_SoundOpvarSetOBBEntity;
    class CCSGameModeRules_ArmsRace;
    class C_FuncMonitor;
    class C_ClientRagdoll;
    class PulseSelectorOutflowList_t;
    class CPulseCell_PlaySequence_CursorState_t;
    class CBodyComponentSkeletonInstance;
    class C_CS2WeaponModuleBase;
    class C_CSGO_TeamPreviewCharacterPosition;
    class C_SmokeGrenadeProjectile;
    class CScriptComponent;
    class CCSPlayer_BuyServices;
    class C_PortraitWorldCallbackHandler;
    class C_DynamicProp;
    class C_CSTeam;
    class C_CS2HudModelWeapon;
    class C_TextureBasedAnimatable;
    class C_LightEnvironmentEntity;
    class DestructiblePartDamageRequestAPI;
    class CLogicRelayAPI;
    class C_TriggerPhysics;
    class C_PropDoorRotating;
    class C_HandleTest;
    class CInfoWorldLayer;
    class CBodyComponentBaseModelEntity;
    class C_Multimeter;
    class C_BaseTrigger;
    class FilterDamageType;
    class CAttributeList;
    class CPulseCell_Inflow_Wait;
    class CFilterProximity;
    class CCS2WeaponGraphController;
    class CEffectData;
    class C_ParticleSystem;
    class CPulseCell_Outflow_CycleShuffled;
    class C_WeaponSCAR20;
    class C_FuncMover;
    class CCSPlayerController_InventoryServices_NetworkedLoadoutSlot_t;
    class CLightComponent;
    class C_DecoyGrenade;
    class C_WaterBullet;
    class CCSPlayer_ActionTrackingServices;
    class C_EnvCubemap;
    class CCSObserver_MovementServices;
    class CBodyComponent;
    class CPulseCell_Inflow_Method;
    class C_BaseCombatCharacter;
    class CGlowProperty;
    class C_PointClientUIDialog;
    class CPulseCell_BaseValue;
    class C_WeaponHKP2000;
    class C_FootstepControl;
    class CCitadelSoundOpvarSetOBB;
    class C_CSGO_EndOfMatchLineupStart;
    class CPlayer_WaterServices;
    class CPulseCell_BooleanSwitchState;
    class CDamageRecord;
    class VPhysicsCollisionAttribute_t;
    class C_DynamicPropAlias_dynamic_prop;
    class CEnvSoundscapeProxyAlias_snd_soundscape_proxy;
    class C_OmniLight;
    class C_SceneEntity;
    class CPulseCell_Inflow_Yield;
    class CPulseMathlib;
    class C_NametagModule;
    class C_EconEntity;
    class CPlayer_UseServices;
    class C_PointValueRemapper;
    class CGameSceneNodeHandle;
    class CPulseCell_Unknown;
    class C_WeaponMP7;
    class CSPerRoundStats_t;
    class CPulseCell_Outflow_CycleRandom;
    class CPulseCell_Step_PublicOutput;
    class C_CS2HudModelBase;
    class C_CSGameRules;
    class CGrenadeTracer;
    class CCSGameModeRules_Noop;
    class CPulse_BlackboardReference;
    class C_BaseCSGrenadeProjectile;
    class C_GradientFog;
    class CCSPlayerController_InGameMoneyServices;
    class CCSPlayer_AimPunchServices;
    class C_HEGrenadeProjectile;
    class CFilterModel;
    class C_SoundAreaEntityOrientedBox;
    class C_SoundOpvarSetPointEntity;
    class CPulseGameBlackboard;
    class CChoreoComponent;
    class CPulseCell_Value_RandomInt;
    class C_CSWeaponBaseShotgun;
    class C_RagdollPropAttached;
    class C_ModelPointEntity;
    class C_CSGO_PreviewPlayer;
    class C_RectLight;
    class CPathSimple;
    class C_FuncTrackTrain;
    class C_EconWearable;
    class C_EnvDecal;
    class EntitySpottedState_t;
    class fogparams_t;
    class C_WeaponM4A1;
    class C_Item;
    class C_CSPetPlacement;
    class C_Beam;
    class C_EnvLightProbeVolume;
    class CExplosionTypeData;
    class C_FuncConveyor;
    class CCSPlayer_WeaponServices;
    class C_PhysMagnet;
    class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable;
    class C_Breakable;
    class C_PlantedC4;
    class CCSGO_WingmanIntroCharacterPosition;
    class CFilterName;
    class C_RagdollProp;
    class CPulse_CallInfo;
    class C_MapPreviewParticleSystem;
    class CBaseAnimGraph;
    class CPulseCell_InlineNodeSkipSelector;
    class C_LightEntity;
    class C_WeaponM249;
    class C_LocalTempEntity;
    class C_WeaponTaser;
    class C_PointEntity;
    class C_SingleplayRules;
    class CLogicalEntity;
    class C_PrecipitationBlocker;
    class C_CSGO_CounterTerroristTeamIntroCamera;
    class C_SoundOpvarSetPathCornerEntity;
    class CPlayer_WeaponServices;
    class C_WeaponNegev;
    class C_WeaponFiveSeven;
    class C_WeaponSawedoff;
    class C_TriggerVolume;
    class CPulseCell_LimitCount;
    class CPulseCell_Step_CallExternalMethod;
    class C_WeaponMP9;
    class C_DynamicPropAlias_prop_dynamic_override;
    class CEnvSoundscapeTriggerable;
    class C_PlayerPing;
    class C_AK47;
    class C_CSGO_MapPreviewCameraPathNode;
    class C_CSPlayerResource;
    class CSkyboxReference;
    class C_IncendiaryGrenade;
    class CFilterClass;
    class C_PointCameraVFOV;
    class C_PointCamera;
    class CPathWithDynamicNodes;
    class CBaseFilter;
    class WeaponPurchaseTracker_t;
    class PulseObservableBoolExpression_t;
    class CMapInfo;
    class C_CSGO_EndOfMatchCamera;
    class C_BaseGrenade;
    class C_PlayerSprayDecal;
    class CEntityIdentity;
    class CPulseCell_LimitCount_Criteria_t;
    class C_CS2HudModelArms;
    class CBasePlayerVData;
    class C_LightSpotEntity;
    class CCSGameModeRules_Deathmatch;
    class CPulseCell_CursorQueue;
    class CPulseCell_Value_RandomFloat;
    class CPulseExecCursor;
    class C_Sprite;
    class C_CsmFovOverride;
    class C_WeaponGlock;
    class C_PhysicsProp;
    class CFilterTeam;
    class CBasePlayerWeaponVData;
    class CInfoInteraction;
    class C_SmokeGrenade;
    class C_CSGO_PreviewPlayerAlias_csgo_player_previewmodel;
    class CInfoParticleTarget;
    class CCSPlayer_DamageReactServices;
    class C_PointClientUIWorldPanel;
    class C_EntityFlame;
    class CBasePlayerController;
    class C_CSGO_EndOfMatchLineupEndpoint;
    class GeneratedTextureHandle_t;
    class CompositeMaterialInputContainer_t;
    class CompositeMaterialAssemblyProcedure_t;
    class CompositeMaterialInputLooseVariable_t;
    class screenshake_t;
    class CCS2UIPawnGraphController;
    class inv_image_light_barn_t;
    class inv_image_map_t;
    class inv_image_light_fill_t;
    class CInterpolatedValue;
    class inv_image_item_t;
    class TimedEvent;
    class CFlashlightEffect;
    class inv_image_camera_t;
    class CInventoryImageData;
    class inv_image_clearcolor_t;
    class C_CommandContext;
    class CompositeMaterialEditorPoint_t;
    class CPlayerSprayDecalRenderHelper;
    class C_IronSightController;
    class CompMatMutatorCondition_t;
    class inv_image_data_t;
    class CompMatPropertyMutator_t;
    class CCompositeMaterialEditorDoc;
    class CClientAlphaProperty;
    class screenfade_t;
    class CGlobalLightBase;
    class IClientAlphaProperty;
    class inv_image_light_sun_t;
    class CompositeMaterialMatchFilter_t;
    class CompositeMaterial_t;

    enum class C_BaseCombatCharacter_e : std::uint32_t {
        WATER_WAKE_NONE = 0x0,
        WATER_WAKE_IDLE = 0x1,
        WATER_WAKE_WALKING = 0x2,
        WATER_WAKE_RUNNING = 0x3,
        WATER_WAKE_WATER_OVERHEAD = 0x4,
    };

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

    enum class CompositeMaterialInputLooseVariableType_t : std::uint32_t {
        LOOSE_VARIABLE_TYPE_BOOLEAN = 0x0,
        LOOSE_VARIABLE_TYPE_INTEGER1 = 0x1,
        LOOSE_VARIABLE_TYPE_INTEGER2 = 0x2,
        LOOSE_VARIABLE_TYPE_INTEGER3 = 0x3,
        LOOSE_VARIABLE_TYPE_INTEGER4 = 0x4,
        LOOSE_VARIABLE_TYPE_FLOAT1 = 0x5,
        LOOSE_VARIABLE_TYPE_FLOAT2 = 0x6,
        LOOSE_VARIABLE_TYPE_FLOAT3 = 0x7,
        LOOSE_VARIABLE_TYPE_FLOAT4 = 0x8,
        LOOSE_VARIABLE_TYPE_COLOR4 = 0x9,
        LOOSE_VARIABLE_TYPE_STRING = 0xA,
        LOOSE_VARIABLE_TYPE_SYSTEMVAR = 0xB,
        LOOSE_VARIABLE_TYPE_RESOURCE_MATERIAL = 0xC,
        LOOSE_VARIABLE_TYPE_RESOURCE_TEXTURE = 0xD,
        LOOSE_VARIABLE_TYPE_PANORAMA_RENDER = 0xE,
    };

    enum class CompositeMaterialInputTextureType_t : std::uint32_t {
        INPUT_TEXTURE_TYPE_DEFAULT = 0x0,
        INPUT_TEXTURE_TYPE_NORMALMAP = 0x1,
        INPUT_TEXTURE_TYPE_COLOR = 0x2,
        INPUT_TEXTURE_TYPE_MASKS = 0x3,
        INPUT_TEXTURE_TYPE_ROUGHNESS = 0x4,
        INPUT_TEXTURE_TYPE_PEARLESCENCE_MASK = 0x5,
        INPUT_TEXTURE_TYPE_AO = 0x6,
        INPUT_TEXTURE_TYPE_POSITION = 0x7,
    };

    enum class InventoryNodeType_t : std::uint32_t {
        NODE_TYPE_INVALID = 0x0,
        VIRTUAL_NODE_SCHEMA_PREFAB = 0x1,
        VIRTUAL_NODE_SCHEMA_ITEMDEF = 0x2,
        VIRTUAL_NODE_SCHEMA_STICKER = 0x3,
        VIRTUAL_NODE_SCHEMA_KEYCHAIN = 0x4,
        CONCRETE_NODE_SCHEMA_PREFAB = 0x5,
        CONCRETE_NODE_SCHEMA_ITEMDEF = 0x6,
        CONCRETE_NODE_SCHEMA_STICKER = 0x7,
        CONCRETE_NODE_SCHEMA_KEYCHAIN = 0x8,
    };

    enum class CompositeMaterialInputContainerSourceType_t : std::uint32_t {
        CONTAINER_SOURCE_TYPE_TARGET_MATERIAL = 0x0,
        CONTAINER_SOURCE_TYPE_MATERIAL_FROM_TARGET_ATTR = 0x1,
        CONTAINER_SOURCE_TYPE_SPECIFIC_MATERIAL = 0x2,
        CONTAINER_SOURCE_TYPE_LOOSE_VARIABLES = 0x3,
        CONTAINER_SOURCE_TYPE_VARIABLE_FROM_TARGET_ATTR = 0x4,
        CONTAINER_SOURCE_TYPE_TARGET_INSTANCE_MATERIAL = 0x5,
    };

    enum class CompMatPropertyMutatorType_t : std::uint32_t {
        COMP_MAT_PROPERTY_MUTATOR_INIT = 0x0,
        COMP_MAT_PROPERTY_MUTATOR_COPY_MATCHING_KEYS = 0x1,
        COMP_MAT_PROPERTY_MUTATOR_COPY_KEYS_WITH_SUFFIX = 0x2,
        COMP_MAT_PROPERTY_MUTATOR_COPY_PROPERTY = 0x3,
        COMP_MAT_PROPERTY_MUTATOR_SET_VALUE = 0x4,
        COMP_MAT_PROPERTY_MUTATOR_GENERATE_TEXTURE = 0x5,
        COMP_MAT_PROPERTY_MUTATOR_CONDITIONAL_MUTATORS = 0x6,
        COMP_MAT_PROPERTY_MUTATOR_POP_INPUT_QUEUE = 0x7,
        COMP_MAT_PROPERTY_MUTATOR_DRAW_TEXT = 0x8,
        COMP_MAT_PROPERTY_MUTATOR_RANDOM_ROLL_INPUT_VARIABLES = 0x9,
    };

    enum class CompositeMaterialVarSystemVar_t : std::uint32_t {
        COMPMATSYSVAR_COMPOSITETIME = 0x0,
        COMPMATSYSVAR_EMPTY_RESOURCE_SPACER = 0x1,
    };

    enum class CompositeMaterialMatchFilterType_t : std::uint32_t {
        MATCH_FILTER_MATERIAL_ATTRIBUTE_EXISTS = 0x0,
        MATCH_FILTER_MATERIAL_SHADER = 0x1,
        MATCH_FILTER_MATERIAL_NAME_SUBSTR = 0x2,
        MATCH_FILTER_MATERIAL_ATTRIBUTE_EQUALS = 0x3,
        MATCH_FILTER_MATERIAL_PROPERTY_EXISTS = 0x4,
        MATCH_FILTER_MATERIAL_PROPERTY_EQUALS = 0x5,
    };

    enum class CompMatPropertyMutatorConditionType_t : std::uint32_t {
        COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_EXISTS = 0x0,
        COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EXISTS = 0x1,
        COMP_MAT_MUTATOR_CONDITION_INPUT_CONTAINER_VALUE_EQUALS = 0x2,
    };

    class CPulseCell_Step_CallExternalMethod {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x48)
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardIndex                              , 0x58)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_ExpectedArgs                                  , 0x60)
        SCHEMA_FIELD(PulseMethodCallMode_t           , m_nAsyncCallMode                                , 0x70)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x78)
    };

    class CPulseCell_Value_Curve {
    public:
        SCHEMA_FIELD(CPiecewiseCurve                 , m_Curve                                         , 0x48)
    };

    class IClientAlphaProperty {
    public:
    };

    class CPulseCell_Inflow_EntOutputHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceEntity                                  , 0x80)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutput                                  , 0x90)
        SCHEMA_FIELD(CPulseValueFullType             , m_ExpectedParamType                             , 0xA0)
    };

    class CCS2UIPawnGraphController {
    public:
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_nAnimationSeed                                , 0x88)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_characterMode                                 , 0xA0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_nTeamPreviewVariant                           , 0xB8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_nTeamPreviewRandom                            , 0xD0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_nTeamPreviewPosition                          , 0xE8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_endOfMatchCelebration                         , 0x100)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_action                                        , 0x118)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_bannerAnimation                               , 0x130)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_weaponCategory                                , 0x148)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_weaponType                                    , 0x160)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_weaponState                                   , 0x178)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_inspectTurnAngle                              , 0x190)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bCT                                           , 0x1A8)
    };

    class CPulseCell_Outflow_CycleRandom {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class CPlayer_WeaponServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BasePlayerWeapon>>, m_hMyWeapons                                    , 0x48)
        SCHEMA_FIELD(CHandle<C_BasePlayerWeapon>     , m_hActiveWeapon                                 , 0x60)
        SCHEMA_FIELD(CHandle<C_BasePlayerWeapon>     , m_hLastWeapon                                   , 0x64)
        SCHEMA_FIELD(std::uint16_t                   , m_iAmmo                                         , 0x68)
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

    class inv_image_light_fill_t {
    public:
        SCHEMA_FIELD(::Vector                        , color                                           , 0x0)
        SCHEMA_FIELD(::QAngle                        , angle                                           , 0xC)
        SCHEMA_FIELD(float                           , brightness                                      , 0x18)
    };

    class SignatureOutflow_Resume {
    public:
    };

    class CEntityInstance {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszPrivateVScripts                            , 0x8)
        SCHEMA_FIELD(CEntityIdentity*                , m_pEntity                                       , 0x10)
        SCHEMA_FIELD(CScriptComponent*               , m_CScriptComponent                              , 0x28)
    };

    class CPulseCell_Outflow_CycleOrdered {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class CPulseCell_FireCursors {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outflows                                      , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class CFilterMultipleAPI {
    public:
    };

    class CCSPlayer_GlowServices : public CPlayerPawnComponent {
    public:
    };

    class CPulseArraylib {
    public:
    };

    class CompositeMaterialMatchFilter_t {
    public:
        SCHEMA_FIELD(CompositeMaterialMatchFilterType_t, m_nCompositeMaterialMatchFilterType             , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_strMatchFilter                                , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_strMatchValue                                 , 0x10)
        SCHEMA_FIELD(bool                            , m_bPassWhenTrue                                 , 0x18)
    };

    class SellbackPurchaseEntry_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_unDefIdx                                      , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_nCost                                         , 0x34)
        SCHEMA_FIELD(std::int32_t                    , m_nPrevArmor                                    , 0x38)
        SCHEMA_FIELD(bool                            , m_bPrevHelmet                                   , 0x3C)
        SCHEMA_FIELD(CEntityHandle                   , m_hItem                                         , 0x40)
    };

    class PhysicsRagdollPose_t {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CTransform>, m_Transforms                                    , 0x8)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hOwner                                        , 0x20)
        SCHEMA_FIELD(bool                            , m_bSetFromDebugHistory                          , 0x24)
    };

    class CDamageRecord {
    public:
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_PlayerDamager                                 , 0x30)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_PlayerRecipient                               , 0x34)
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
        SCHEMA_FIELD(::Vector                        , m_vecWrappedLocalOrigin                         , 0xE4)
        SCHEMA_FIELD(::QAngle                        , m_angWrappedLocalRotation                       , 0xF0)
        SCHEMA_FIELD(float                           , m_flWrappedScale                                , 0xFC)
        SCHEMA_FIELD(std::int16_t                    , m_nParentAttachmentOrBone                       , 0x100)
        SCHEMA_FIELD(bool                            , m_bDebugAbsOriginChanges                        , 0x102)
        SCHEMA_FIELD(bool                            , m_bDormant                                      , 0x103)
        SCHEMA_FIELD(bool                            , m_bForceParentToBeNetworked                     , 0x104)

        SCHEMA_FIELD(std::uint8_t                    , m_nHierarchicalDepth                            , 0x107)
        SCHEMA_FIELD(std::uint8_t                    , m_nHierarchyType                                , 0x108)
        SCHEMA_FIELD(std::uint8_t                    , m_nDoNotSetAnimTimeInInvalidatePhysicsCount     , 0x109)
        SCHEMA_FIELD(CUtlStringToken                 , m_name                                          , 0x10C)
        SCHEMA_FIELD(CUtlStringToken                 , m_hierarchyAttachName                           , 0x120)
        SCHEMA_FIELD(float                           , m_flClientLocalScale                            , 0x124)
        SCHEMA_FIELD(::Vector                        , m_vRenderOrigin                                 , 0x128)
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
        SCHEMA_FIELD(bool                            , m_bClientClothCreationSuppressed                , 0x110)
        SCHEMA_FIELD(std::uint8_t                    , m_nAnimStateNoInterpSerialNumber                , 0x1C0)
        SCHEMA_FIELD(std::uint64_t                   , m_MeshGroupMask                                 , 0x1C8)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<int32>   , m_nBodyGroupChoices                             , 0x218)
        SCHEMA_FIELD(std::int8_t                     , m_nIdealMotionType                              , 0x262)
        SCHEMA_FIELD(std::int8_t                     , m_nForceLOD                                     , 0x263)
        SCHEMA_FIELD(std::int8_t                     , m_nClothUpdateFlags                             , 0x264)
    };

    class CPulseExecCursor {
    public:
    };

    class inv_image_item_t {
    public:
        SCHEMA_FIELD(::Vector                        , position                                        , 0x0)
        SCHEMA_FIELD(::QAngle                        , angle                                           , 0xC)
        SCHEMA_FIELD(::CUtlString                    , pose_sequence                                   , 0x18)
    };

    class CompMatMutatorCondition_t {
    public:
        SCHEMA_FIELD(CompMatPropertyMutatorConditionType_t, m_nMutatorCondition                             , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_strMutatorConditionContainerName              , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_strMutatorConditionContainerVarName           , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_strMutatorConditionContainerVarValue          , 0x18)
        SCHEMA_FIELD(bool                            , m_bPassWhenTrue                                 , 0x20)
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

    class C_BaseModelEntity_Emphasized_Phoneme {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sClassName                                    , 0x0)
        SCHEMA_FIELD(float                           , m_flAmount                                      , 0x18)
        SCHEMA_FIELD(bool                            , m_bRequired                                     , 0x1C)
        SCHEMA_FIELD(bool                            , m_bBasechecked                                  , 0x1D)
        SCHEMA_FIELD(bool                            , m_bValid                                        , 0x1E)
    };

    class CPlayer_AutoaimServices : public CPlayerPawnComponent {
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

    class C_EconEntity_AttachedModelData_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iModelDisplayFlags                            , 0x0)
    };

    class CInterpolatedValue {
    public:
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0x0)
        SCHEMA_FIELD(float                           , m_flEndTime                                     , 0x4)
        SCHEMA_FIELD(float                           , m_flStartValue                                  , 0x8)
        SCHEMA_FIELD(float                           , m_flEndValue                                    , 0xC)
        SCHEMA_FIELD(std::int32_t                    , m_nInterpType                                   , 0x10)
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

    class CPulseCell_IsRequirementValid {
    public:
    };

    class inv_image_map_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , map_name                                        , 0x0)
        SCHEMA_FIELD(float                           , map_rotation                                    , 0x8)
    };

    class C_BaseEntity {
    public:
        SCHEMA_FIELD(CBodyComponent*                 , m_CBodyComponent                                , 0x30)
        SCHEMA_FIELD(CNetworkTransmitComponent       , m_NetworkTransmitComponent                      , 0x38)
        SCHEMA_FIELD(::GameTick_t                    , m_nLastThinkTick                                , 0x328)
        SCHEMA_FIELD(CGameSceneNode*                 , m_pGameSceneNode                                , 0x330)
        SCHEMA_FIELD(CRenderComponent*               , m_pRenderComponent                              , 0x338)
        SCHEMA_FIELD(CCollisionProperty*             , m_pCollision                                    , 0x340)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxHealth                                    , 0x348)
        SCHEMA_FIELD(std::int32_t                    , m_iHealth                                       , 0x34C)
        SCHEMA_FIELD(float                           , m_flDamageAccumulator                           , 0x350)
        SCHEMA_FIELD(std::uint8_t                    , m_lifeState                                     , 0x354)
        SCHEMA_FIELD(bool                            , m_bTakesDamage                                  , 0x355)
        SCHEMA_FIELD(TakeDamageFlags_t               , m_nTakeDamageFlags                              , 0x358)
        SCHEMA_FIELD(EntityPlatformTypes_t           , m_nPlatformType                                 , 0x360)
        SCHEMA_FIELD(std::uint8_t                    , m_ubInterpolationFrame                          , 0x361)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hSceneObjectController                        , 0x364)
        SCHEMA_FIELD(std::int32_t                    , m_nNoInterpolationTick                          , 0x368)
        SCHEMA_FIELD(std::int32_t                    , m_nVisibilityNoInterpolationTick                , 0x36C)
        SCHEMA_FIELD(float                           , m_flProxyRandomValue                            , 0x370)
        SCHEMA_FIELD(std::int32_t                    , m_iEFlags                                       , 0x374)
        SCHEMA_FIELD(std::uint8_t                    , m_nWaterType                                    , 0x378)
        SCHEMA_FIELD(bool                            , m_bInterpolateEvenWithNoModel                   , 0x379)
        SCHEMA_FIELD(bool                            , m_bPredictionEligible                           , 0x37A)
        SCHEMA_FIELD(bool                            , m_bApplyLayerMatchIDToModel                     , 0x37B)
        SCHEMA_FIELD(CUtlStringToken                 , m_tokLayerMatchID                               , 0x37C)
        SCHEMA_FIELD(CUtlStringToken                 , m_nSubclassID                                   , 0x380)
        SCHEMA_FIELD(std::int32_t                    , m_nSimulationTick                               , 0x390)
        SCHEMA_FIELD(std::int32_t                    , m_iCurrentThinkContext                          , 0x394)
        SCHEMA_FIELD(CUtlVector<thinkfunc_t>         , m_aThinkFunctions                               , 0x398)
        SCHEMA_FIELD(bool                            , m_bDisabledContextThinks                        , 0x3B0)
        SCHEMA_FIELD(float                           , m_flAnimTime                                    , 0x3B4)
        SCHEMA_FIELD(float                           , m_flSimulationTime                              , 0x3B8)
        SCHEMA_FIELD(std::uint8_t                    , m_nSceneObjectOverrideFlags                     , 0x3BC)
        SCHEMA_FIELD(bool                            , m_bHasSuccessfullyInterpolated                  , 0x3BD)
        SCHEMA_FIELD(bool                            , m_bHasAddedVarsToInterpolation                  , 0x3BE)
        SCHEMA_FIELD(bool                            , m_bRenderEvenWhenNotSuccessfullyInterpolated    , 0x3BF)
        SCHEMA_FIELD(std::int32_t                    , m_nInterpolationLatchDirtyFlags                 , 0x3C0)
        SCHEMA_FIELD(std::uint16_t                   , m_ListEntry                                     , 0x3C8)
        SCHEMA_FIELD(::GameTime_t                    , m_flCreateTime                                  , 0x3E0)
        SCHEMA_FIELD(float                           , m_flSpeed                                       , 0x3E4)
        SCHEMA_FIELD(std::uint16_t                   , m_EntClientFlags                                , 0x3E8)
        SCHEMA_FIELD(bool                            , m_bClientSideRagdoll                            , 0x3EA)
        SCHEMA_FIELD(std::uint8_t                    , m_iTeamNum                                      , 0x3EB)
        SCHEMA_FIELD(std::uint32_t                   , m_spawnflags                                    , 0x3EC)
        SCHEMA_FIELD(::GameTick_t                    , m_nNextThinkTick                                , 0x3F0)
        SCHEMA_FIELD(std::uint32_t                   , m_fFlags                                        , 0x3F8)
        SCHEMA_FIELD(::Vector                        , m_vecAbsVelocity                                , 0x3FC)
        SCHEMA_FIELD(CNetworkVelocityVector          , m_vecServerVelocity                             , 0x408)
        SCHEMA_FIELD(CNetworkVelocityVector          , m_vecVelocity                                   , 0x430)
        SCHEMA_FIELD(::Vector                        , m_vecBaseVelocity                               , 0x510)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hEffectEntity                                 , 0x51C)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hOwnerEntity                                  , 0x520)
        SCHEMA_FIELD(MoveCollide_t                   , m_MoveCollide                                   , 0x524)
        SCHEMA_FIELD(MoveType_t                      , m_MoveType                                      , 0x525)
        SCHEMA_FIELD(MoveType_t                      , m_nActualMoveType                               , 0x526)
        SCHEMA_FIELD(float                           , m_flWaterLevel                                  , 0x528)
        SCHEMA_FIELD(std::uint32_t                   , m_fEffects                                      , 0x52C)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hGroundEntity                                 , 0x530)
        SCHEMA_FIELD(std::int32_t                    , m_nGroundBodyIndex                              , 0x534)
        SCHEMA_FIELD(float                           , m_flFriction                                    , 0x538)
        SCHEMA_FIELD(float                           , m_flElasticity                                  , 0x53C)
        SCHEMA_FIELD(float                           , m_flGravityScale                                , 0x540)
        SCHEMA_FIELD(float                           , m_flTimeScale                                   , 0x544)
        SCHEMA_FIELD(bool                            , m_bAnimatedEveryTick                            , 0x548)
        SCHEMA_FIELD(bool                            , m_bGravityDisabled                              , 0x549)
        SCHEMA_FIELD(::GameTime_t                    , m_flNavIgnoreUntilTime                          , 0x54C)
        SCHEMA_FIELD(std::uint16_t                   , m_hThink                                        , 0x550)
        SCHEMA_FIELD(std::uint8_t                    , m_fBBoxVisFlags                                 , 0x560)
        SCHEMA_FIELD(float                           , m_flActualGravityScale                          , 0x564)
        SCHEMA_FIELD(bool                            , m_bGravityActuallyDisabled                      , 0x568)
        SCHEMA_FIELD(bool                            , m_bPredictable                                  , 0x569)
        SCHEMA_FIELD(bool                            , m_bRenderWithViewModels                         , 0x56A)
        SCHEMA_FIELD(std::int32_t                    , m_nFirstPredictableCommand                      , 0x56C)
        SCHEMA_FIELD(std::int32_t                    , m_nLastPredictableCommand                       , 0x570)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hOldMoveParent                                , 0x574)
        SCHEMA_FIELD(CParticleProperty               , m_Particles                                     , 0x578)
        SCHEMA_FIELD(::QAngle                        , m_vecAngVelocity                                , 0x5A8)
        SCHEMA_FIELD(std::int32_t                    , m_DataChangeEventRef                            , 0x5B4)
        SCHEMA_FIELD(CUtlVector<CEntityHandle>       , m_dependencies                                  , 0x5B8)
        SCHEMA_FIELD(std::int32_t                    , m_nCreationTick                                 , 0x5D0)
        SCHEMA_FIELD(bool                            , m_bAnimTimeChanged                              , 0x5E1)
        SCHEMA_FIELD(bool                            , m_bSimulationTimeChanged                        , 0x5E2)
        SCHEMA_FIELD(::CUtlString                    , m_sUniqueHammerID                               , 0x5F0)
        SCHEMA_FIELD(BloodType                       , m_nBloodType                                    , 0x5F8)
    };

    class inv_image_data_t {
    public:
        SCHEMA_FIELD(inv_image_map_t                 , map                                             , 0x0)
        SCHEMA_FIELD(inv_image_item_t                , item                                            , 0x10)
        SCHEMA_FIELD(inv_image_camera_t              , camera                                          , 0x30)
        SCHEMA_FIELD(inv_image_light_sun_t           , lightsun                                        , 0x64)
        SCHEMA_FIELD(inv_image_light_fill_t          , lightfill                                       , 0x80)
        SCHEMA_FIELD(inv_image_light_barn_t          , light0                                          , 0x9C)
        SCHEMA_FIELD(inv_image_light_barn_t          , light1                                          , 0xBC)
        SCHEMA_FIELD(inv_image_clearcolor_t          , clearcolor                                      , 0xDC)
    };

    class CPulseCell_Inflow_EventHandler {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_EventName                                     , 0x80)
    };

    class CPulseCell_Value_RandomFloat {
    public:
    };

    class AnimGraph2SerializedPoseRecipeSlot_t {
    public:
        SCHEMA_FIELD(::CUtlBinaryBlock               , m_topology                                      , 0x30)
    };

    class CPulseCell_Value_RandomInt {
    public:
    };

    class C_CommandContext {
    public:
        SCHEMA_FIELD(bool                            , needsprocessing                                 , 0x0)
        SCHEMA_FIELD(std::int32_t                    , command_number                                  , 0xA0)
    };

    class CPulseCell_Timeline {
    public:
        SCHEMA_FIELD(CUtlVector<CPulseCell_Timeline_TimelineEvent_t>, m_TimelineEvents                                , 0x48)
        SCHEMA_FIELD(bool                            , m_bWaitForChildOutflows                         , 0x60)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class C_SceneEntity_QueuedEvents_t {
    public:
        SCHEMA_FIELD(float                           , starttime                                       , 0x0)
    };

    class screenshake_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , endtime                                         , 0x0)
        SCHEMA_FIELD(float                           , duration                                        , 0x4)
        SCHEMA_FIELD(float                           , amplitude                                       , 0x8)
        SCHEMA_FIELD(float                           , frequency                                       , 0xC)
        SCHEMA_FIELD(::GameTime_t                    , nextShake                                       , 0x10)
        SCHEMA_FIELD(::Vector                        , offset                                          , 0x14)
        SCHEMA_FIELD(float                           , angle                                           , 0x20)
        SCHEMA_FIELD(::Vector                        , direction                                       , 0x28)
        SCHEMA_FIELD(std::uint8_t                    , nShakeType                                      , 0x34)
    };

    class CGameSceneNodeHandle {
    public:
        SCHEMA_FIELD(CEntityHandle                   , m_hOwner                                        , 0x8)
        SCHEMA_FIELD(CUtlStringToken                 , m_name                                          , 0xC)
    };

    class CPulseCell_Step_DebugLog {
    public:
    };

    class CPulseCell_WaitForCursorsWithTag {
    public:
        SCHEMA_FIELD(bool                            , m_bTagSelfWhenComplete                          , 0x98)
        SCHEMA_FIELD(PulseCursorCancelPriority_t     , m_nDesiredKillPriority                          , 0x9C)
    };

    class CPulseCell_PlaySequence_CursorState_t {
    public:
        SCHEMA_FIELD(CHandle<CBaseAnimGraph>         , m_hTarget                                       , 0x0)
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
        SCHEMA_FIELD(C_NetworkUtlVectorBase<Vector2D>, m_vecPanelVertices                              , 0x40)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<Vector4D>, m_vInitialPanelVertices                         , 0x58)
        SCHEMA_FIELD(float                           , m_flGlassHalfThickness                          , 0x70)
        SCHEMA_FIELD(bool                            , m_bHasParent                                    , 0x74)
        SCHEMA_FIELD(bool                            , m_bParentFrozen                                 , 0x75)
        SCHEMA_FIELD(CUtlStringToken                 , m_SurfacePropStringToken                        , 0x78)
    };

    class CPlayer_UseServices : public CPlayerPawnComponent {
    public:
    };

    class WeaponPurchaseTracker_t {
    public:
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<WeaponPurchaseCount_t>, m_weaponPurchases                               , 0x8)
    };

    class CCSPlayer_DamageReactServices : public CPlayerPawnComponent {
    public:
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

    class EntitySpottedState_t {
    public:
        SCHEMA_FIELD(bool                            , m_bSpotted                                      , 0x8)
        SCHEMA_FIELD(std::uint32_t                   , m_bSpottedByMask                                , 0xC)
    };

    class C_RopeKeyframe_CPhysicsDelegate {
    public:
        SCHEMA_FIELD(C_RopeKeyframe*                 , m_pKeyframe                                     , 0x8)
    };

    class CBasePlayerControllerAPI {
    public:
    };

    class CPulseCursorFuncs {
    public:
    };

    class CPulseCell_BaseRequirement {
    public:
    };

    class CCSGameModeRules {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
    };

    class CCSPlayerController_InventoryServices_NetworkedLoadoutSlot_t {
    public:
        SCHEMA_FIELD(C_EconItemView*                 , pItem                                           , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , team                                            , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , slot                                            , 0xA)
    };

    class CPulseCell_BooleanSwitchState {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Always                                        , 0xC0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenTrue                                      , 0x108)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_WhenFalse                                     , 0x150)
    };

    class PulseNodeDynamicOutflows_t_DynamicOutflow_t {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_OutflowID                                     , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x8)
    };

    class CPulseCell_IntervalTimer {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_Completed                                     , 0x48)
        SCHEMA_FIELD(SignatureOutflow_Continue       , m_OnInterval                                    , 0x90)
    };

    class CPlayer_ItemServices : public CPlayerPawnComponent {
    public:
    };

    class OutflowWithRequirements_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_Connection                                    , 0x0)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_DestinationFlowNodeID                         , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseDocNodeID_t>    , m_RequirementNodeIDs                            , 0x50)
        SCHEMA_FIELD(CUtlVector<int32>               , m_nCursorStateBlockIndex                        , 0x68)
    };

    class CCSGameModeRules_Deathmatch {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flDMBonusStartTime                            , 0x30)
        SCHEMA_FIELD(float                           , m_flDMBonusTimeLength                           , 0x34)
        SCHEMA_FIELD(::CUtlString                    , m_sDMBonusWeapon                                , 0x38)
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

    class CPulseCell_LerpCameraSettings_CursorState_t {
    public:
        SCHEMA_FIELD(CHandle<C_PointCamera>          , m_hCamera                                       , 0x8)
        SCHEMA_FIELD(PointCameraSettings_t           , m_OverlaidStart                                 , 0xC)
        SCHEMA_FIELD(PointCameraSettings_t           , m_OverlaidEnd                                   , 0x1C)
    };

    class CPointTemplateAPI {
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

    class CGlobalLightBase {
    public:
        SCHEMA_FIELD(bool                            , m_bSpotLight                                    , 0x10)
        SCHEMA_FIELD(::Vector                        , m_SpotLightOrigin                               , 0x14)
        SCHEMA_FIELD(::QAngle                        , m_SpotLightAngles                               , 0x20)
        SCHEMA_FIELD(::Vector                        , m_ShadowDirection                               , 0x2C)
        SCHEMA_FIELD(::Vector                        , m_AmbientDirection                              , 0x38)
        SCHEMA_FIELD(::Vector                        , m_SpecularDirection                             , 0x44)
        SCHEMA_FIELD(::Vector                        , m_InspectorSpecularDirection                    , 0x50)
        SCHEMA_FIELD(float                           , m_flSpecularPower                               , 0x5C)
        SCHEMA_FIELD(float                           , m_flSpecularIndependence                        , 0x60)
        SCHEMA_FIELD(::Color                         , m_SpecularColor                                 , 0x64)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x68)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x69)
        SCHEMA_FIELD(::Color                         , m_LightColor                                    , 0x6A)
        SCHEMA_FIELD(::Color                         , m_AmbientColor1                                 , 0x6E)
        SCHEMA_FIELD(::Color                         , m_AmbientColor2                                 , 0x72)
        SCHEMA_FIELD(::Color                         , m_AmbientColor3                                 , 0x76)
        SCHEMA_FIELD(float                           , m_flSunDistance                                 , 0x7C)
        SCHEMA_FIELD(float                           , m_flFOV                                         , 0x80)
        SCHEMA_FIELD(float                           , m_flNearZ                                       , 0x84)
        SCHEMA_FIELD(float                           , m_flFarZ                                        , 0x88)
        SCHEMA_FIELD(bool                            , m_bEnableShadows                                , 0x8C)
        SCHEMA_FIELD(bool                            , m_bOldEnableShadows                             , 0x8D)
        SCHEMA_FIELD(bool                            , m_bBackgroundClearNotRequired                   , 0x8E)
        SCHEMA_FIELD(float                           , m_flCloudScale                                  , 0x90)
        SCHEMA_FIELD(float                           , m_flCloud1Speed                                 , 0x94)
        SCHEMA_FIELD(float                           , m_flCloud1Direction                             , 0x98)
        SCHEMA_FIELD(float                           , m_flCloud2Speed                                 , 0x9C)
        SCHEMA_FIELD(float                           , m_flCloud2Direction                             , 0xA0)
        SCHEMA_FIELD(float                           , m_flAmbientScale1                               , 0xB0)
        SCHEMA_FIELD(float                           , m_flAmbientScale2                               , 0xB4)
        SCHEMA_FIELD(float                           , m_flGroundScale                                 , 0xB8)
        SCHEMA_FIELD(float                           , m_flLightScale                                  , 0xBC)
        SCHEMA_FIELD(float                           , m_flFoWDarkness                                 , 0xC0)
        SCHEMA_FIELD(bool                            , m_bEnableSeparateSkyboxFog                      , 0xC4)
        SCHEMA_FIELD(::Vector                        , m_vFowColor                                     , 0xC8)
        SCHEMA_FIELD(::Vector                        , m_ViewOrigin                                    , 0xD4)
        SCHEMA_FIELD(::QAngle                        , m_ViewAngles                                    , 0xE0)
        SCHEMA_FIELD(float                           , m_flViewFoV                                     , 0xEC)
        SCHEMA_FIELD(::Vector                        , m_WorldPoints                                   , 0xF0)
        SCHEMA_FIELD(::Vector2D                      , m_vFogOffsetLayer0                              , 0x4A8)
        SCHEMA_FIELD(::Vector2D                      , m_vFogOffsetLayer1                              , 0x4B0)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hEnvWind                                      , 0x4B8)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hEnvSky                                       , 0x4BC)
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

    class CPulseCell_Outflow_CycleShuffled_InstanceState_t {
    public:
        using _Type0 = CUtlVectorFixedGrowable<uint8,8>;
        SCHEMA_FIELD(_Type0                          , m_Shuffle                                       , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nNextShuffle                                  , 0x20)
    };

    class ServerAuthoritativeWeaponSlot_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , unClass                                         , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , unSlot                                          , 0x32)
        SCHEMA_FIELD(std::uint16_t                   , unItemDefIdx                                    , 0x34)
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

    class CBasePulseGraphInstance {
    public:
    };

    class CPulseCell_WaitForCursorsWithTagBase {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToWait                         , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WaitComplete                                  , 0x50)
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

    class CPlayer_ObserverServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_iObserverMode                                 , 0x48)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hObserverTarget                               , 0x4C)
        SCHEMA_FIELD(ObserverMode_t                  , m_iObserverLastMode                             , 0x50)
        SCHEMA_FIELD(bool                            , m_bForcedObserverMode                           , 0x54)
        SCHEMA_FIELD(float                           , m_flObserverChaseDistance                       , 0x58)
        SCHEMA_FIELD(::GameTime_t                    , m_flObserverChaseDistanceCalcTime               , 0x5C)
    };

    class CompMatPropertyMutator_t {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x0)
        SCHEMA_FIELD(CompMatPropertyMutatorType_t    , m_nMutatorCommandType                           , 0x4)
        SCHEMA_FIELD(::CUtlString                    , m_strInitWith_Container                         , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_strCopyProperty_InputContainerSrc             , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_strCopyProperty_InputContainerProperty        , 0x18)
        SCHEMA_FIELD(::CUtlString                    , m_strCopyProperty_TargetProperty                , 0x20)
        SCHEMA_FIELD(::CUtlString                    , m_strRandomRollInputVars_SeedInputVar           , 0x28)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_vecRandomRollInputVars_InputVarsToRoll        , 0x30)
        SCHEMA_FIELD(::CUtlString                    , m_strCopyMatchingKeys_InputContainerSrc         , 0x48)
        SCHEMA_FIELD(::CUtlString                    , m_strCopyKeysWithSuffix_InputContainerSrc       , 0x50)
        SCHEMA_FIELD(::CUtlString                    , m_strCopyKeysWithSuffix_FindSuffix              , 0x58)
        SCHEMA_FIELD(::CUtlString                    , m_strCopyKeysWithSuffix_ReplaceSuffix           , 0x60)
        SCHEMA_FIELD(CompositeMaterialInputLooseVariable_t, m_nSetValue_Value                               , 0x68)
        SCHEMA_FIELD(::CUtlString                    , m_strGenerateTexture_TargetParam                , 0x2F0)
        SCHEMA_FIELD(::CUtlString                    , m_strGenerateTexture_InitialContainer           , 0x2F8)
        SCHEMA_FIELD(std::int32_t                    , m_nResolution                                   , 0x300)
        SCHEMA_FIELD(bool                            , m_bIsScratchTarget                              , 0x304)
        SCHEMA_FIELD(::CUtlString                    , m_strCompressionFormat                          , 0x308)
        SCHEMA_FIELD(bool                            , m_bSplatDebugInfo                               , 0x310)
        SCHEMA_FIELD(bool                            , m_bCaptureInRenderDoc                           , 0x311)
        SCHEMA_FIELD(CUtlVector<CompMatPropertyMutator_t>, m_vecTexGenInstructions                         , 0x318)
        SCHEMA_FIELD(CUtlVector<CompMatPropertyMutator_t>, m_vecConditionalMutators                        , 0x330)
        SCHEMA_FIELD(::CUtlString                    , m_strPopInputQueue_Container                    , 0x348)
        SCHEMA_FIELD(::CUtlString                    , m_strDrawText_InputContainerSrc                 , 0x350)
        SCHEMA_FIELD(::CUtlString                    , m_strDrawText_InputContainerProperty            , 0x358)
        SCHEMA_FIELD(::Vector2D                      , m_vecDrawText_Position                          , 0x360)
        SCHEMA_FIELD(::Color                         , m_colDrawText_Color                             , 0x368)
        SCHEMA_FIELD(::CUtlString                    , m_strDrawText_Font                              , 0x370)
        SCHEMA_FIELD(CUtlVector<CompMatMutatorCondition_t>, m_vecConditions                                 , 0x378)
    };

    class CPulseCell_Step_PublicOutput {
    public:
        SCHEMA_FIELD(PulseRuntimeOutputIndex_t       , m_OutputIndex                                   , 0x48)
    };

    class CCSGameModeRules_ArmsRace {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CUtlString>, m_WeaponSequence                                , 0x30)
    };

    class CPulseAnimFuncs {
    public:
    };

    class CPulse_BlackboardReference {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIPulseGraphDef>, m_hBlackboardResource                           , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_BlackboardResource                            , 0x8)
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nNodeID                                       , 0x18)
        SCHEMA_FIELD(CGlobalSymbol                   , m_NodeName                                      , 0x20)
    };

    class C_EnvWindShared {
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
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hEntOwner                                     , 0x3C)
    };

    class CPulse_ResumePoint {
    public:
    };

    class CPulse_OutflowConnection {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_SourceOutflowName                             , 0x0)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nDestChunk                                    , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nInstruction                                  , 0x14)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_OutflowRegisterMap                            , 0x18)
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

    class CCSPlayer_PingServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CHandle<C_PlayerPing>           , m_hPlayerPing                                   , 0x48)
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

    class CInventoryImageData {
    public:
        SCHEMA_FIELD(InventoryNodeType_t             , m_nNodeType                                     , 0x0)
        SCHEMA_FIELD(::CUtlString                    , name                                            , 0x8)
        SCHEMA_FIELD(inv_image_data_t                , inventory_image_data                            , 0x10)
    };

    class CDestructiblePartsComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x0)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_vecDamageTakenByHitGroup                      , 0x48)
        SCHEMA_FIELD(CHandle<C_BaseModelEntity>      , m_hOwner                                        , 0x60)
        SCHEMA_FIELD(CBaseAnimGraphDestructibleParts_GraphController*, m_pAnimGraphDestructibleGraphController         , 0x68)
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

    class CTakeDamageResultAPI {
    public:
    };

    class CCSGameModeRules_Noop {
    public:
    };

    class CFlashlightEffect {
    public:
        SCHEMA_FIELD(bool                            , m_bIsOn                                         , 0x10)
        SCHEMA_FIELD(bool                            , m_bMuzzleFlashEnabled                           , 0x20)
        SCHEMA_FIELD(float                           , m_flMuzzleFlashBrightness                       , 0x24)
        SCHEMA_FIELD(::Quaternion                    , m_quatMuzzleFlashOrientation                    , 0x30)
        SCHEMA_FIELD(::Vector                        , m_vecMuzzleFlashOrigin                          , 0x40)
        SCHEMA_FIELD(float                           , m_flFov                                         , 0x4C)
        SCHEMA_FIELD(float                           , m_flFarZ                                        , 0x50)
        SCHEMA_FIELD(float                           , m_flLinearAtten                                 , 0x54)
        SCHEMA_FIELD(bool                            , m_bCastsShadows                                 , 0x58)
        SCHEMA_FIELD(float                           , m_flCurrentPullBackDist                         , 0x5C)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_FlashlightTexture                             , 0x60)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_MuzzleFlashTexture                            , 0x68)
        SCHEMA_FIELD(char                            , m_textureName                                   , 0x70)
    };

    class CPulseCell_Inflow_Wait {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
    };

    class CPulseCell_InlineNodeSkipSelector {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nFlowNodeID                                   , 0x48)
        SCHEMA_FIELD(bool                            , m_bAnd                                          , 0x4C)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_PassOutflow                                   , 0x50)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_FailOutflow                                   , 0x68)
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

    class C_fogplayerparams_t {
    public:
        SCHEMA_FIELD(CHandle<C_FogController>        , m_hCtrl                                         , 0x8)
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

    class CPulseCell_WaitForCursorsWithTagBase_CursorState_t {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_TagName                                       , 0x0)
    };

    class CPlayer_FlashlightServices : public CPlayerPawnComponent {
    public:
    };

    class CExplosionTypeData {
    public:
        SCHEMA_FIELD(CSoundEventName                 , m_SoundName                                     , 0x0)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIParticleSystemDefinition>>, m_ParticleEffect                                , 0x10)
        SCHEMA_FIELD(bool                            , m_bIsIncindiary                                 , 0xF0)
        SCHEMA_FIELD(bool                            , m_bHasForces                                    , 0xF1)
        SCHEMA_FIELD(CGlobalSymbol                   , m_DecalType                                     , 0xF8)
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

    class CPulseCell_WaitForObservable {
    public:
        SCHEMA_FIELD(PulseObservableBoolExpression_t , m_Condition                                     , 0x48)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnTrue                                        , 0xC0)
    };

    class CPulseCell_Inflow_GraphHook {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_HookName                                      , 0x80)
    };

    class inv_image_light_sun_t {
    public:
        SCHEMA_FIELD(::Vector                        , color                                           , 0x0)
        SCHEMA_FIELD(::QAngle                        , angle                                           , 0xC)
        SCHEMA_FIELD(float                           , brightness                                      , 0x18)
    };

    class CPulseCell_BaseLerp_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
    };

    class PulseObservableBoolExpression_t {
    public:
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EvaluateConnection                            , 0x0)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeVarIndex_t>, m_DependentObservableVars                       , 0x48)
        SCHEMA_FIELD(CUtlVector<PulseRuntimeBlackboardReferenceIndex_t>, m_DependentObservableBlackboardReferences       , 0x60)
    };

    class CPulseCell_Inflow_Yield {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_UnyieldResume                                 , 0x48)
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

    class CPulseCell_Inflow_Method {
    public:
        SCHEMA_FIELD(::PulseSymbol_t                 , m_MethodName                                    , 0x80)
        SCHEMA_FIELD(::CUtlString                    , m_Description                                   , 0x90)
        SCHEMA_FIELD(bool                            , m_bIsPublic                                     , 0x98)
        SCHEMA_FIELD(CPulseValueFullType             , m_ReturnType                                    , 0xA0)
        SCHEMA_FIELD(CUtlLeanVector<CPulseRuntimeMethodArg>, m_Args                                          , 0xB8)
    };

    class screenfade_t {
    public:
        SCHEMA_FIELD(float                           , Speed                                           , 0x0)
        SCHEMA_FIELD(float                           , End                                             , 0x4)
        SCHEMA_FIELD(float                           , Reset                                           , 0x8)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0xC)
        SCHEMA_FIELD(std::int32_t                    , Flags                                           , 0x10)
    };

    class CPulseCell_LerpCameraSettings {
    public:
        SCHEMA_FIELD(float                           , m_flSeconds                                     , 0x90)
        SCHEMA_FIELD(PointCameraSettings_t           , m_Start                                         , 0x94)
        SCHEMA_FIELD(PointCameraSettings_t           , m_End                                           , 0xA4)
    };

    class CCSPlayer_HostageServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hCarriedHostage                               , 0x48)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hCarriedHostageProp                           , 0x4C)
    };

    class CLogicRelayAPI {
    public:
    };

    class CPulseCell_PlaySequence {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_SequenceName                                  , 0x48)
        SCHEMA_FIELD(PulseNodeDynamicOutflows_t      , m_PulseAnimEvents                               , 0x50)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnFinished                                    , 0x68)
        SCHEMA_FIELD(CPulse_ResumePoint              , m_OnCanceled                                    , 0xB0)
    };

    class CBaseAnimGraphController : public CSkeletonAnimationController {
    public:
        SCHEMA_FIELD(AnimationAlgorithm_t            , m_nAnimationAlgorithm                           , 0x18)
        SCHEMA_FIELD(ExternalAnimGraphHandle_t       , m_nNextExternalGraphHandle                      , 0x1C)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CGlobalSymbol>, m_vecSecondarySkeletonSlotIDs                   , 0x20)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<CBaseAnimGraph>>, m_vecSecondarySkeletons                         , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nSecondarySkeletonMasterCount                 , 0x50)
        SCHEMA_FIELD(float                           , m_flSoundSyncTime                               , 0x58)
        SCHEMA_FIELD(std::uint32_t                   , m_nActiveIKChainMask                            , 0x5C)
        SCHEMA_FIELD(HSequence                       , m_hSequence                                     , 0xB0)
        SCHEMA_FIELD(::GameTime_t                    , m_flSeqStartTime                                , 0xB4)
        SCHEMA_FIELD(float                           , m_flSeqFixedCycle                               , 0xB8)
        SCHEMA_FIELD(AnimLoopMode_t                  , m_nAnimLoopMode                                 , 0xBC)
        SCHEMA_FIELD(CNetworkedQuantizedFloat        , m_flPlaybackRate                                , 0xC0)
        SCHEMA_FIELD(SequenceFinishNotifyState_t     , m_nNotifyState                                  , 0xCC)
        SCHEMA_FIELD(bool                            , m_bNetworkedAnimationInputsChanged              , 0xCD)
        SCHEMA_FIELD(bool                            , m_bNetworkedSequenceChanged                     , 0xCE)
        SCHEMA_FIELD(bool                            , m_bLastUpdateSkipped                            , 0xCF)
        SCHEMA_FIELD(bool                            , m_bSequenceFinished                             , 0xD0)
        SCHEMA_FIELD(::GameTick_t                    , m_nPrevAnimUpdateTick                           , 0xD4)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCNmGraphDefinition>, m_hGraphDefinitionAG2                           , 0x370)
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<AnimGraph2SerializedPoseRecipeSlot_t>, m_SerializePoseRecipeAG2Slots                   , 0x378)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<uint8>   , m_SerializePoseRecipeAG2Dynamic                 , 0x3E0)
        SCHEMA_FIELD(std::uint32_t                   , m_nSerializePoseRecipeAG2ActiveSlot             , 0x3F8)
        SCHEMA_FIELD(std::int32_t                    , m_nSerializePoseRecipeVersionAG2                , 0x3FC)
        SCHEMA_FIELD(std::int32_t                    , m_nServerGraphInstanceIteration                 , 0x400)
        SCHEMA_FIELD(std::int32_t                    , m_nServerSerializationContextIteration          , 0x404)
        SCHEMA_FIELD(ResourceId_t                    , m_primaryGraphId                                , 0x408)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<ResourceId_t>, m_vecExternalGraphIds                           , 0x410)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<ResourceId_t>, m_vecExternalClipIds                            , 0x428)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sAnimGraph2Identifier                         , 0x440)
        SCHEMA_FIELD(CNmGraphInstance*               , m_pGraphInstanceAG2                             , 0x448)
        SCHEMA_FIELD(CUtlVector<ExternalAnimGraph_t> , m_vecExternalGraphs                             , 0x660)
        SCHEMA_FIELD(AnimationAlgorithm_t            , m_nPrevAnimationAlgorithm                       , 0x689)
    };

    class ViewAngleServerChange_t {
    public:
        SCHEMA_FIELD(FixAngleSet_t                   , nType                                           , 0x30)
        SCHEMA_FIELD(::QAngle                        , qAngle                                          , 0x34)
        SCHEMA_FIELD(std::uint32_t                   , nIndex                                          , 0x40)
    };

    class CCSPlayer_BulletServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_totalHitsOnServer                             , 0x48)
    };

    class CPulseCell_Base {
    public:
        SCHEMA_FIELD(::PulseDocNodeID_t              , m_nEditorNodeID                                 , 0x8)
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

    class CPulseCell_BaseLerp {
    public:
        SCHEMA_FIELD(CPulse_ResumePoint              , m_WakeResume                                    , 0x48)
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

    class CPulseCell_PickBestOutflowSelector {
    public:
        SCHEMA_FIELD(PulseBestOutflowRules_t         , m_nCheckType                                    , 0x48)
        SCHEMA_FIELD(PulseSelectorOutflowList_t      , m_OutflowList                                   , 0x50)
    };

    class C_GameRules {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_nTotalPausedTicks                             , 0x30)
        SCHEMA_FIELD(std::int32_t                    , m_nPauseStartTick                               , 0x34)
        SCHEMA_FIELD(bool                            , m_bGamePaused                                   , 0x38)
    };

    class DestructiblePartDamageRequestAPI {
    public:
    };

    class CCSPlayerController_ActionTrackingServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<CSPerRoundStats_t>, m_perRoundStats                                 , 0x40)
        SCHEMA_FIELD(CSMatchStats_t                  , m_matchStats                                    , 0xA8)
        SCHEMA_FIELD(std::int32_t                    , m_iNumRoundKills                                , 0x128)
        SCHEMA_FIELD(std::int32_t                    , m_iNumRoundKillsHeadshots                       , 0x12C)
        SCHEMA_FIELD(float                           , m_flTotalRoundDamageDealt                       , 0x130)
    };

    class CCSPlayer_ActionTrackingServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(CHandle<C_BasePlayerWeapon>     , m_hLastWeaponBeforeC4AutoSwitch                 , 0x48)
        SCHEMA_FIELD(bool                            , m_bIsRescuing                                   , 0x4C)
        SCHEMA_FIELD(WeaponPurchaseTracker_t         , m_weaponPurchasesThisMatch                      , 0x50)
        SCHEMA_FIELD(WeaponPurchaseTracker_t         , m_weaponPurchasesThisRound                      , 0xC0)
    };

    class C_SingleplayRules {
    public:
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

    class CCS2PawnGraphController {
    public:
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bIsDefusing                                   , 0x2A0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_moveType                                      , 0x2B8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_moveDirectionID                               , 0x2D0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flMoveSpeedX                                  , 0x2E8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flMoveSpeedY                                  , 0x300)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flMoveSpeedHorizontal                         , 0x318)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flPreviousMoveSpeedHorizontal                 , 0x330)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flCrouchAmount                                , 0x348)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_bIsWalking                                    , 0x360)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flWeaponDropAmount                            , 0x378)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_groundAction                                  , 0x390)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_groundActionDirectionID                       , 0x3A8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flGroundTurnAngleOrVelocity                   , 0x3C0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flLadderCycle                                 , 0x3D8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flLadderYaw                                   , 0x3F0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flLadderYawBackwards                          , 0x408)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_airAction                                     , 0x420)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flAirHeightAboveGround                        , 0x438)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CNmTarget>, m_leftFootTarget                                , 0x450)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CNmTarget>, m_rightFootTarget                               , 0x468)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flFlashedAmount                               , 0x480)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flAimPitchAngle                               , 0x498)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<float32>, m_flAimYawAngle                                 , 0x4B0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_flinchHead                                    , 0x4C8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_flinchHeadRestart                             , 0x4E0)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<CGlobalSymbol>, m_flinchBody                                    , 0x4F8)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_flinchBodyRestart                             , 0x510)
        SCHEMA_FIELD(CAnimGraph2ParamOptionalRef<bool>, m_flinchIsOnFire                                , 0x528)
    };

    class C_BulletHitModel {
    public:
        SCHEMA_FIELD(::matrix3x4_t                   , m_matLocal                                      , 0x1158)
        SCHEMA_FIELD(std::int32_t                    , m_iBoneIndex                                    , 0x1188)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hPlayerParent                                 , 0x118C)
        SCHEMA_FIELD(bool                            , m_bIsHit                                        , 0x1190)
        SCHEMA_FIELD(float                           , m_flTimeCreated                                 , 0x1194)
        SCHEMA_FIELD(::Vector                        , m_vecStartPos                                   , 0x1198)
    };

    class TimedEvent {
    public:
        SCHEMA_FIELD(float                           , m_TimeBetweenEvents                             , 0x0)
        SCHEMA_FIELD(float                           , m_fNextEvent                                    , 0x4)
    };

    class C_IronSightController {
    public:
        SCHEMA_FIELD(bool                            , m_bIronSightAvailable                           , 0x10)
        SCHEMA_FIELD(float                           , m_flIronSightAmount                             , 0x14)
        SCHEMA_FIELD(float                           , m_flIronSightAmountGained                       , 0x18)
        SCHEMA_FIELD(float                           , m_flIronSightAmountBiased                       , 0x1C)
        SCHEMA_FIELD(float                           , m_flIronSightAmount_Interpolated                , 0x20)
        SCHEMA_FIELD(float                           , m_flIronSightAmountGained_Interpolated          , 0x24)
        SCHEMA_FIELD(float                           , m_flIronSightAmountBiased_Interpolated          , 0x28)
        SCHEMA_FIELD(float                           , m_flInterpolationLastUpdated                    , 0x2C)
        SCHEMA_FIELD(::QAngle                        , m_angDeltaAverage                               , 0x30)
        SCHEMA_FIELD(::QAngle                        , m_angViewLast                                   , 0x90)
        SCHEMA_FIELD(::Vector2D                      , m_vecDotCoords                                  , 0x9C)
        SCHEMA_FIELD(float                           , m_flFiringInaccuracyExtraWidthMultiplier        , 0xA4)
        SCHEMA_FIELD(float                           , m_flSpeedRatio                                  , 0xA8)
    };

    class C_RetakeGameRules {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nMatchSeed                                    , 0x138)
        SCHEMA_FIELD(bool                            , m_bBlockersPresent                              , 0x13C)
        SCHEMA_FIELD(bool                            , m_bRoundInProgress                              , 0x13D)
        SCHEMA_FIELD(std::int32_t                    , m_iFirstSecondHalfRound                         , 0x140)
        SCHEMA_FIELD(std::int32_t                    , m_iBombSite                                     , 0x144)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hBombPlanter                                  , 0x148)
    };

    class CAttributeManager {
    public:
        SCHEMA_FIELD(CUtlVector<CHandle<C_BaseEntity>>, m_Providers                                     , 0x8)
        SCHEMA_FIELD(std::int32_t                    , m_iReapplyProvisionParity                       , 0x20)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hOuter                                        , 0x24)
        SCHEMA_FIELD(bool                            , m_bPreventLoopback                              , 0x28)
        SCHEMA_FIELD(attributeprovidertypes_t        , m_ProviderType                                  , 0x2C)
        SCHEMA_FIELD(CUtlVector<CAttributeManager_cached_attribute_float_t>, m_CachedResults                                 , 0x30)
    };

    class CPulseCell_LimitCount {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nLimitCount                                   , 0x48)
    };

    class CSMatchStats_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iEnemy5Ks                                     , 0x68)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemy4Ks                                     , 0x6C)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemy3Ks                                     , 0x70)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemyKnifeKills                              , 0x74)
        SCHEMA_FIELD(std::int32_t                    , m_iEnemyTaserKills                              , 0x78)
    };

    class CountdownTimer {
    public:
        SCHEMA_FIELD(float                           , m_duration                                      , 0x8)
        SCHEMA_FIELD(::GameTime_t                    , m_timestamp                                     , 0xC)
        SCHEMA_FIELD(float                           , m_timescale                                     , 0x10)
        SCHEMA_FIELD(::WorldGroupId_t                , m_nWorldGroupId                                 , 0x14)
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

    class CPulseTestScriptLib {
    public:
    };

    class CompositeMaterialInputLooseVariable_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strName                                       , 0x0)
        SCHEMA_FIELD(bool                            , m_bExposeExternally                             , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_strExposedFriendlyName                        , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_strExposedFriendlyGroupName                   , 0x18)
        SCHEMA_FIELD(bool                            , m_bExposedVariableIsFixedRange                  , 0x20)
        SCHEMA_FIELD(::CUtlString                    , m_strExposedVisibleWhenTrue                     , 0x28)
        SCHEMA_FIELD(::CUtlString                    , m_strExposedHiddenWhenTrue                      , 0x30)
        SCHEMA_FIELD(::CUtlString                    , m_strExposedValueList                           , 0x38)
        SCHEMA_FIELD(CompositeMaterialInputLooseVariableType_t, m_nVariableType                                 , 0x40)
        SCHEMA_FIELD(bool                            , m_bValueBoolean                                 , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_nValueIntX                                    , 0x48)
        SCHEMA_FIELD(std::int32_t                    , m_nValueIntY                                    , 0x4C)
        SCHEMA_FIELD(std::int32_t                    , m_nValueIntZ                                    , 0x50)
        SCHEMA_FIELD(std::int32_t                    , m_nValueIntW                                    , 0x54)
        SCHEMA_FIELD(bool                            , m_bHasFloatBounds                               , 0x58)
        SCHEMA_FIELD(float                           , m_flValueFloatX                                 , 0x5C)
        SCHEMA_FIELD(float                           , m_flValueFloatX_Min                             , 0x60)
        SCHEMA_FIELD(float                           , m_flValueFloatX_Max                             , 0x64)
        SCHEMA_FIELD(float                           , m_flValueFloatY                                 , 0x68)
        SCHEMA_FIELD(float                           , m_flValueFloatY_Min                             , 0x6C)
        SCHEMA_FIELD(float                           , m_flValueFloatY_Max                             , 0x70)
        SCHEMA_FIELD(float                           , m_flValueFloatZ                                 , 0x74)
        SCHEMA_FIELD(float                           , m_flValueFloatZ_Min                             , 0x78)
        SCHEMA_FIELD(float                           , m_flValueFloatZ_Max                             , 0x7C)
        SCHEMA_FIELD(float                           , m_flValueFloatW                                 , 0x80)
        SCHEMA_FIELD(float                           , m_flValueFloatW_Min                             , 0x84)
        SCHEMA_FIELD(float                           , m_flValueFloatW_Max                             , 0x88)
        SCHEMA_FIELD(::Color                         , m_cValueColor4                                  , 0x8C)
        SCHEMA_FIELD(CompositeMaterialVarSystemVar_t , m_nValueSystemVar                               , 0x90)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIMaterial2>>, m_strResourceMaterial                           , 0x98)
        SCHEMA_FIELD(::CUtlString                    , m_strTextureContentAssetPath                    , 0x178)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCTextureBase>>, m_strTextureRuntimeResourcePath                 , 0x180)
        SCHEMA_FIELD(::CUtlString                    , m_strTextureCompilationVtexTemplate             , 0x260)
        SCHEMA_FIELD(CompositeMaterialInputTextureType_t, m_nTextureType                                  , 0x268)
        SCHEMA_FIELD(::CUtlString                    , m_strString                                     , 0x270)
        SCHEMA_FIELD(::CUtlString                    , m_strPanoramaPanelPath                          , 0x278)
        SCHEMA_FIELD(std::int32_t                    , m_nPanoramaRenderRes                            , 0x280)
    };

    class CPulseCell_Inflow_ObservableVariableListener {
    public:
        SCHEMA_FIELD(PulseRuntimeBlackboardReferenceIndex_t, m_nBlackboardReference                          , 0x80)
        SCHEMA_FIELD(bool                            , m_bSelfReference                                , 0x82)
    };

    class CPlayer_WaterServices : public CPlayerPawnComponent {
    public:
    };

    class PulseNodeDynamicOutflows_t {
    public:
        SCHEMA_FIELD(CUtlVector<PulseNodeDynamicOutflows_t_DynamicOutflow_t>, m_Outflows                                      , 0x0)
    };

    class CPathSimpleAPI {
    public:
    };

    class CCompositeMaterialEditorDoc {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nVersion                                      , 0x8)
        SCHEMA_FIELD(CUtlVector<CompositeMaterialEditorPoint_t>, m_Points                                        , 0x10)
        SCHEMA_FIELD(KeyValues3                      , m_KVthumbnail                                   , 0x28)
    };

    class CPulseCell_Outflow_CycleShuffled {
    public:
        SCHEMA_FIELD(CUtlVector<CPulse_OutflowConnection>, m_Outputs                                       , 0x48)
    };

    class CCSPlayerController_InGameMoneyServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iAccount                                      , 0x40)
        SCHEMA_FIELD(std::int32_t                    , m_iStartAccount                                 , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_iTotalCashSpent                               , 0x48)
        SCHEMA_FIELD(std::int32_t                    , m_iCashSpentThisRound                           , 0x4C)
    };

    class CompositeMaterialEditorPoint_t {
    public:
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCModel>>, m_ModelName                                     , 0x0)
        SCHEMA_FIELD(std::int32_t                    , m_nSequenceIndex                                , 0xE0)
        SCHEMA_FIELD(float                           , m_flCycle                                       , 0xE4)
        SCHEMA_FIELD(KeyValues3                      , m_KVModelStateChoices                           , 0xE8)
        SCHEMA_FIELD(bool                            , m_bEnableChildModel                             , 0xF8)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCModel>>, m_ChildModelName                                , 0x100)
        SCHEMA_FIELD(CUtlVector<CompositeMaterialAssemblyProcedure_t>, m_vecCompositeMaterialAssemblyProcedures        , 0x1E0)
        SCHEMA_FIELD(CUtlVector<CompositeMaterial_t> , m_vecCompositeMaterials                         , 0x1F8)
    };

    class CPlayer_CameraServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(::QAngle                        , m_vecCsViewPunchAngle                           , 0x48)
        SCHEMA_FIELD(::GameTick_t                    , m_nCsViewPunchAngleTick                         , 0x54)
        SCHEMA_FIELD(float                           , m_flCsViewPunchAngleTickRatio                   , 0x58)
        SCHEMA_FIELD(C_fogplayerparams_t             , m_PlayerFog                                     , 0x60)
        SCHEMA_FIELD(CHandle<C_ColorCorrection>      , m_hColorCorrectionCtrl                          , 0xA0)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hViewEntity                                   , 0xA4)
        SCHEMA_FIELD(CHandle<C_TonemapController2>   , m_hTonemapController                            , 0xA8)
        SCHEMA_FIELD(audioparams_t                   , m_audio                                         , 0xB0)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_PostProcessingVolume>>, m_PostProcessingVolumes                         , 0x128)
        SCHEMA_FIELD(float                           , m_flOldPlayerZ                                  , 0x140)
        SCHEMA_FIELD(float                           , m_flOldPlayerViewOffsetZ                        , 0x144)
        SCHEMA_FIELD(fogparams_t                     , m_CurrentFog                                    , 0x148)
        SCHEMA_FIELD(CHandle<C_FogController>        , m_hOldFogController                             , 0x1B0)
        SCHEMA_FIELD(bool                            , m_bOverrideFogColor                             , 0x1B4)
        SCHEMA_FIELD(::Color                         , m_OverrideFogColor                              , 0x1B9)
        SCHEMA_FIELD(bool                            , m_bOverrideFogStartEnd                          , 0x1CD)
        SCHEMA_FIELD(float                           , m_fOverrideFogStart                             , 0x1D4)
        SCHEMA_FIELD(float                           , m_fOverrideFogEnd                               , 0x1E8)
        SCHEMA_FIELD(CHandle<C_PostProcessingVolume> , m_hActivePostProcessingVolume                   , 0x1FC)
        SCHEMA_FIELD(::QAngle                        , m_angDemoViewAngles                             , 0x200)
    };

    class CPlayerSprayDecalRenderHelper {
    public:
    };

    class CScenePayloadVData {
    public:
        SCHEMA_FIELD(ENPCBehaviorOverride_t          , m_eNPCBehavior                                  , 0x0)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIPulseGraphDef>>, m_sPulseFile                                    , 0x8)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeCChoreoSceneResource>>, m_sSceneFile                                    , 0xE8)
        SCHEMA_FIELD(InteractionPriority_t           , m_ePriority                                     , 0x1C8)
    };

    class CAttributeManager_cached_attribute_float_t {
    public:
        SCHEMA_FIELD(float                           , flIn                                            , 0x0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , iAttribHook                                     , 0x8)
        SCHEMA_FIELD(float                           , flOut                                           , 0x10)
    };

    class PulseSelectorOutflowList_t {
    public:
        SCHEMA_FIELD(CUtlVector<OutflowWithRequirements_t>, m_Outflows                                      , 0x0)
    };

    class CChoreoComponent {
    public:
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x8)
        SCHEMA_FIELD(CHandle<C_BaseModelEntity>      , m_hOwner                                        , 0x30)
        SCHEMA_FIELD(SceneEventId_t                  , m_nNextSceneEventId                             , 0x68)
        SCHEMA_FIELD(::GameTime_t                    , m_flAllowResponsesEndTime                       , 0x6C)
    };

    class C_BaseEntityAPI {
    public:
    };

    class audioparams_t {
    public:
        SCHEMA_FIELD(::Vector                        , localSound                                      , 0x8)
        SCHEMA_FIELD(std::int32_t                    , soundscapeIndex                                 , 0x68)
        SCHEMA_FIELD(std::uint8_t                    , localBits                                       , 0x6C)
        SCHEMA_FIELD(std::int32_t                    , soundscapeEntityListIndex                       , 0x70)
        SCHEMA_FIELD(std::uint32_t                   , soundEventHash                                  , 0x74)
    };

    class CompositeMaterialInputContainer_t {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x0)
        SCHEMA_FIELD(CompositeMaterialInputContainerSourceType_t, m_nCompositeMaterialInputContainerSourceType    , 0x4)
        SCHEMA_FIELD(CResourceNameTyped<CWeakHandle<InfoForResourceTypeIMaterial2>>, m_strSpecificContainerMaterial                  , 0x8)
        SCHEMA_FIELD(::CUtlString                    , m_strAttrName                                   , 0xE8)
        SCHEMA_FIELD(::CUtlString                    , m_strAlias                                      , 0xF0)
        SCHEMA_FIELD(CUtlVector<CompositeMaterialInputLooseVariable_t>, m_vecLooseVariables                             , 0xF8)
        SCHEMA_FIELD(::CUtlString                    , m_strAttrNameForVar                             , 0x110)
        SCHEMA_FIELD(bool                            , m_bExposeExternally                             , 0x118)
    };

    class inv_image_camera_t {
    public:
        SCHEMA_FIELD(::QAngle                        , angle                                           , 0x0)
        SCHEMA_FIELD(float                           , fov                                             , 0xC)
        SCHEMA_FIELD(float                           , znear                                           , 0x10)
        SCHEMA_FIELD(float                           , zfar                                            , 0x14)
        SCHEMA_FIELD(::Vector                        , target                                          , 0x18)
        SCHEMA_FIELD(::Vector                        , target_nudge                                    , 0x24)
        SCHEMA_FIELD(float                           , orbit_distance                                  , 0x30)
    };

    class inv_image_clearcolor_t {
    public:
        SCHEMA_FIELD(::Vector                        , color                                           , 0x0)
    };

    class CPulseCell_Value_Gradient {
    public:
        SCHEMA_FIELD(CColorGradient                  , m_Gradient                                      , 0x48)
    };

    class EntityRenderAttribute_t {
    public:
        SCHEMA_FIELD(CUtlStringToken                 , m_ID                                            , 0x30)
        SCHEMA_FIELD(::Vector4D                      , m_Values                                        , 0x34)
    };

    class CCSPlayerController_DamageServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSendUpdate                                   , 0x40)
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<CDamageRecord>, m_DamageList                                    , 0x48)
    };

    class C_MultiplayRules {
    public:
    };

    class CPulseCell_BaseYieldingInflow {
    public:
    };

    class CPulseCell_LimitCount_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentCount                                 , 0x0)
    };

    class CPulseCell_BaseFlow {
    public:
    };

    class CPulseCell_IntervalTimer_CursorState_t {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_StartTime                                     , 0x0)
        SCHEMA_FIELD(::GameTime_t                    , m_EndTime                                       , 0x4)
        SCHEMA_FIELD(float                           , m_flWaitInterval                                , 0x8)
        SCHEMA_FIELD(float                           , m_flWaitIntervalHigh                            , 0xC)
        SCHEMA_FIELD(bool                            , m_bCompleteOnNextWake                           , 0x10)
    };

    class WeaponPurchaseCount_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nItemDefIndex                                 , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , m_nCount                                        , 0x32)
    };

    class CPulse_InvokeBinding {
    public:
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x0)
        SCHEMA_FIELD(::PulseSymbol_t                 , m_FuncName                                      , 0x30)
        SCHEMA_FIELD(PulseRuntimeCellIndex_t         , m_nCellIndex                                    , 0x40)
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_nSrcChunk                                     , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_nSrcInstruction                               , 0x48)
    };

    class CCSPlayerLegacyJump {
    public:
        SCHEMA_FIELD(bool                            , m_bOldJumpPressed                               , 0x10)
        SCHEMA_FIELD(float                           , m_flJumpPressedTime                             , 0x14)
    };

    class GeneratedTextureHandle_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strBitmapName                                 , 0x0)
    };

    class CPulseCell_BaseValue {
    public:
    };

    class CEconItemAttribute {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_iAttributeDefinitionIndex                     , 0x30)
        SCHEMA_FIELD(float                           , m_flValue                                       , 0x34)
        SCHEMA_FIELD(float                           , m_flInitialValue                                , 0x38)
        SCHEMA_FIELD(std::int32_t                    , m_nRefundableCurrency                           , 0x3C)
        SCHEMA_FIELD(bool                            , m_bSetBonus                                     , 0x40)
    };

    class C_CSGameRules {
    public:
        SCHEMA_FIELD(bool                            , m_bFreezePeriod                                 , 0x40)
        SCHEMA_FIELD(bool                            , m_bWarmupPeriod                                 , 0x41)
        SCHEMA_FIELD(::GameTime_t                    , m_fWarmupPeriodEnd                              , 0x44)
        SCHEMA_FIELD(::GameTime_t                    , m_fWarmupPeriodStart                            , 0x48)
        SCHEMA_FIELD(bool                            , m_bTerroristTimeOutActive                       , 0x4C)
        SCHEMA_FIELD(bool                            , m_bCTTimeOutActive                              , 0x4D)
        SCHEMA_FIELD(float                           , m_flTerroristTimeOutRemaining                   , 0x50)
        SCHEMA_FIELD(float                           , m_flCTTimeOutRemaining                          , 0x54)
        SCHEMA_FIELD(std::int32_t                    , m_nTerroristTimeOuts                            , 0x58)
        SCHEMA_FIELD(std::int32_t                    , m_nCTTimeOuts                                   , 0x5C)
        SCHEMA_FIELD(bool                            , m_bTechnicalTimeOut                             , 0x60)
        SCHEMA_FIELD(bool                            , m_bMatchWaitingForResume                        , 0x61)
        SCHEMA_FIELD(std::int32_t                    , m_iFreezeTime                                   , 0x64)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundTime                                    , 0x68)
        SCHEMA_FIELD(float                           , m_fMatchStartTime                               , 0x6C)
        SCHEMA_FIELD(::GameTime_t                    , m_fRoundStartTime                               , 0x70)
        SCHEMA_FIELD(::GameTime_t                    , m_flRestartRoundTime                            , 0x74)
        SCHEMA_FIELD(bool                            , m_bGameRestart                                  , 0x78)
        SCHEMA_FIELD(float                           , m_flGameStartTime                               , 0x7C)
        SCHEMA_FIELD(float                           , m_timeUntilNextPhaseStarts                      , 0x80)
        SCHEMA_FIELD(std::int32_t                    , m_gamePhase                                     , 0x84)
        SCHEMA_FIELD(std::int32_t                    , m_totalRoundsPlayed                             , 0x88)
        SCHEMA_FIELD(std::int32_t                    , m_nRoundsPlayedThisPhase                        , 0x8C)
        SCHEMA_FIELD(std::int32_t                    , m_nOvertimePlaying                              , 0x90)
        SCHEMA_FIELD(std::int32_t                    , m_iHostagesRemaining                            , 0x94)
        SCHEMA_FIELD(bool                            , m_bAnyHostageReached                            , 0x98)
        SCHEMA_FIELD(bool                            , m_bMapHasBombTarget                             , 0x99)
        SCHEMA_FIELD(bool                            , m_bMapHasRescueZone                             , 0x9A)
        SCHEMA_FIELD(bool                            , m_bMapHasBuyZone                                , 0x9B)
        SCHEMA_FIELD(bool                            , m_bIsQueuedMatchmaking                          , 0x9C)
        SCHEMA_FIELD(std::int32_t                    , m_nQueuedMatchmakingMode                        , 0xA0)
        SCHEMA_FIELD(bool                            , m_bIsValveDS                                    , 0xA4)
        SCHEMA_FIELD(bool                            , m_bLogoMap                                      , 0xA5)
        SCHEMA_FIELD(bool                            , m_bPlayAllStepSoundsOnServer                    , 0xA6)
        SCHEMA_FIELD(std::int32_t                    , m_iSpectatorSlotCount                           , 0xA8)
        SCHEMA_FIELD(std::int32_t                    , m_MatchDevice                                   , 0xAC)
        SCHEMA_FIELD(bool                            , m_bHasMatchStarted                              , 0xB0)
        SCHEMA_FIELD(std::int32_t                    , m_nNextMapInMapgroup                            , 0xB4)
        SCHEMA_FIELD(char                            , m_szTournamentEventName                         , 0xB8)
        SCHEMA_FIELD(char                            , m_szTournamentEventStage                        , 0x2B8)
        SCHEMA_FIELD(char                            , m_szMatchStatTxt                                , 0x4B8)
        SCHEMA_FIELD(char                            , m_szTournamentPredictionsTxt                    , 0x6B8)
        SCHEMA_FIELD(std::int32_t                    , m_nTournamentPredictionsPct                     , 0x8B8)
        SCHEMA_FIELD(::GameTime_t                    , m_flCMMItemDropRevealStartTime                  , 0x8BC)
        SCHEMA_FIELD(::GameTime_t                    , m_flCMMItemDropRevealEndTime                    , 0x8C0)
        SCHEMA_FIELD(bool                            , m_bIsDroppingItems                              , 0x8C4)
        SCHEMA_FIELD(bool                            , m_bIsQuestEligible                              , 0x8C5)
        SCHEMA_FIELD(bool                            , m_bIsHltvActive                                 , 0x8C6)
        SCHEMA_FIELD(bool                            , m_bBombPlanted                                  , 0x8C7)
        SCHEMA_FIELD(std::uint16_t                   , m_arrProhibitedItemIndices                      , 0x8C8)
        SCHEMA_FIELD(std::uint32_t                   , m_arrTournamentActiveCasterAccounts             , 0x990)
        SCHEMA_FIELD(std::int32_t                    , m_numBestOfMaps                                 , 0x9A0)
        SCHEMA_FIELD(std::int32_t                    , m_nHalloweenMaskListSeed                        , 0x9A4)
        SCHEMA_FIELD(bool                            , m_bBombDropped                                  , 0x9A8)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundWinStatus                               , 0x9AC)
        SCHEMA_FIELD(std::int32_t                    , m_eRoundWinReason                               , 0x9B0)
        SCHEMA_FIELD(bool                            , m_bTCantBuy                                     , 0x9B4)
        SCHEMA_FIELD(bool                            , m_bCTCantBuy                                    , 0x9B5)
        SCHEMA_FIELD(std::int32_t                    , m_iMatchStats_RoundResults                      , 0x9B8)
        SCHEMA_FIELD(std::int32_t                    , m_iMatchStats_PlayersAlive_CT                   , 0xA30)
        SCHEMA_FIELD(std::int32_t                    , m_iMatchStats_PlayersAlive_T                    , 0xAA8)
        SCHEMA_FIELD(float                           , m_TeamRespawnWaveTimes                          , 0xB20)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextRespawnWave                             , 0xBA0)
        SCHEMA_FIELD(::Vector                        , m_vMinimapMins                                  , 0xC20)
        SCHEMA_FIELD(::Vector                        , m_vMinimapMaxs                                  , 0xC2C)
        SCHEMA_FIELD(float                           , m_MinimapVerticalSectionHeights                 , 0xC38)
        SCHEMA_FIELD(std::uint64_t                   , m_ullLocalMatchID                               , 0xC58)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchMapGroupVoteTypes                    , 0xC60)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchMapGroupVoteOptions                  , 0xC88)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchMapVoteWinner                        , 0xCB0)
        SCHEMA_FIELD(std::int32_t                    , m_iNumConsecutiveCTLoses                        , 0xCB4)
        SCHEMA_FIELD(std::int32_t                    , m_iNumConsecutiveTerroristLoses                 , 0xCB8)
        SCHEMA_FIELD(std::int32_t                    , m_nMatchAbortedEarlyReason                      , 0xD78)
        SCHEMA_FIELD(bool                            , m_bHasTriggeredRoundStartMusic                  , 0xD7C)
        SCHEMA_FIELD(bool                            , m_bSwitchingTeamsAtRoundReset                   , 0xD7D)
        SCHEMA_FIELD(CCSGameModeRules*               , m_pGameModeRules                                , 0xD98)
        SCHEMA_FIELD(C_RetakeGameRules               , m_RetakeRules                                   , 0xDA0)
        SCHEMA_FIELD(std::uint8_t                    , m_nMatchEndCount                                , 0xEF8)
        SCHEMA_FIELD(std::int32_t                    , m_nTTeamIntroVariant                            , 0xEFC)
        SCHEMA_FIELD(std::int32_t                    , m_nCTTeamIntroVariant                           , 0xF00)
        SCHEMA_FIELD(bool                            , m_bTeamIntroPeriod                              , 0xF04)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndWinnerTeam                           , 0xF08)
        SCHEMA_FIELD(std::int32_t                    , m_eRoundEndReason                               , 0xF0C)
        SCHEMA_FIELD(bool                            , m_bRoundEndShowTimerDefend                      , 0xF10)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndTimerTime                            , 0xF14)
        SCHEMA_FIELD(::CUtlString                    , m_sRoundEndFunFactToken                         , 0xF18)
        SCHEMA_FIELD(CPlayerSlot                     , m_iRoundEndFunFactPlayerSlot                    , 0xF20)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndFunFactData1                         , 0xF24)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndFunFactData2                         , 0xF28)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndFunFactData3                         , 0xF2C)
        SCHEMA_FIELD(::CUtlString                    , m_sRoundEndMessage                              , 0xF30)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndPlayerCount                          , 0xF38)
        SCHEMA_FIELD(bool                            , m_bRoundEndNoMusic                              , 0xF3C)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundEndLegacy                               , 0xF40)
        SCHEMA_FIELD(std::uint8_t                    , m_nRoundEndCount                                , 0xF44)
        SCHEMA_FIELD(std::int32_t                    , m_iRoundStartRoundNumber                        , 0xF48)
        SCHEMA_FIELD(std::uint8_t                    , m_nRoundStartCount                              , 0xF4C)
        SCHEMA_FIELD(double                          , m_flLastPerfSampleTime                          , 0x4F58)
    };

    class CPulseCell_Step_EntFire {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_Input                                         , 0x48)
    };

    class CPulseMathlib {
    public:
    };

    class CPulseCell_LimitCount_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bLimitCountPasses                             , 0x0)
    };

    class SignatureOutflow_Continue {
    public:
    };

    class CAttributeList {
    public:
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<CEconItemAttribute>, m_Attributes                                    , 0x8)
        SCHEMA_FIELD(CAttributeManager*              , m_pManager                                      , 0x70)
    };

    class CPulseCell_IsRequirementValid_Criteria_t {
    public:
        SCHEMA_FIELD(bool                            , m_bIsValid                                      , 0x0)
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

    class CompositeMaterial_t {
    public:
        SCHEMA_FIELD(KeyValues3                      , m_TargetKVs                                     , 0x8)
        SCHEMA_FIELD(KeyValues3                      , m_PreGenerationKVs                              , 0x18)
        SCHEMA_FIELD(KeyValues3                      , m_FinalKVs                                      , 0x58)
        SCHEMA_FIELD(CUtlVector<GeneratedTextureHandle_t>, m_vecGeneratedTextures                          , 0x80)
    };

    class CCSPlayer_BuyServices : public CPlayerPawnComponent {
    public:
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<SellbackPurchaseEntry_t>, m_vecSellbackPurchaseEntries                    , 0x48)
    };

    class ActiveModelConfig_t {
    public:
        SCHEMA_FIELD(ModelConfigHandle_t             , m_Handle                                        , 0x30)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_Name                                          , 0x38)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BaseModelEntity>>, m_AssociatedEntities                            , 0x40)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CUtlSymbolLarge>, m_AssociatedEntityNames                         , 0x58)
    };

    class CPulseCell_Unknown {
    public:
        SCHEMA_FIELD(KeyValues3                      , m_UnknownKeys                                   , 0x48)
    };

    class CEntityComponent {
    public:
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

    class CompositeMaterialAssemblyProcedure_t {
    public:
        SCHEMA_FIELD(CUtlVector<CResourceNameTyped<CWeakHandle<InfoForResourceTypeCCompositeMaterialKit>>>, m_vecCompMatIncludes                            , 0x0)
        SCHEMA_FIELD(CUtlVector<CompositeMaterialMatchFilter_t>, m_vecMatchFilters                               , 0x18)
        SCHEMA_FIELD(CUtlVector<CompositeMaterialInputContainer_t>, m_vecCompositeInputContainers                   , 0x30)
        SCHEMA_FIELD(CUtlVector<CompMatPropertyMutator_t>, m_vecPropertyMutators                           , 0x48)
    };

    class CCSPlayerController_InventoryServices : public CPlayerControllerComponent {
    public:
        SCHEMA_FIELD(CUtlVector<CCSPlayerController_InventoryServices_NetworkedLoadoutSlot_t>, m_vecNetworkableLoadout                         , 0x40)
        SCHEMA_FIELD(std::uint16_t                   , m_unMusicID                                     , 0x58)
        SCHEMA_FIELD(MedalRank_t                     , m_rank                                          , 0x5C)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicLevel                       , 0x74)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicCommendsLeader              , 0x78)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicCommendsTeacher             , 0x7C)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataPublicCommendsFriendly            , 0x80)
        SCHEMA_FIELD(std::int32_t                    , m_nPersonaDataXpTrailLevel                      , 0x84)
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<ServerAuthoritativeWeaponSlot_t>, m_vecServerAuthoritativeWeaponSlots             , 0x88)
    };

    class CPulseCell_Outflow_CycleOrdered_InstanceState_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nNextIndex                                    , 0x0)
    };

    class C_TeamplayRules {
    public:
    };

    class CPulseCell_CursorQueue {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCursorsAllowedToRunParallel                  , 0x98)
    };

    class inv_image_light_barn_t {
    public:
        SCHEMA_FIELD(::Vector                        , color                                           , 0x0)
        SCHEMA_FIELD(::QAngle                        , angle                                           , 0xC)
        SCHEMA_FIELD(float                           , brightness                                      , 0x18)
        SCHEMA_FIELD(float                           , orbit_distance                                  , 0x1C)
    };

    class CPulseCell_Inflow_BaseEntrypoint {
    public:
        SCHEMA_FIELD(::PulseRuntimeChunkIndex_t      , m_EntryChunk                                    , 0x48)
        SCHEMA_FIELD(::PulseRegisterMap_t            , m_RegisterMap                                   , 0x50)
    };

    class CPulseCell_Timeline_TimelineEvent_t {
    public:
        SCHEMA_FIELD(float                           , m_flTimeFromPrevious                            , 0x0)
        SCHEMA_FIELD(CPulse_OutflowConnection        , m_EventOutflow                                  , 0x8)
    };

    class CPulseCell_BaseState {
    public:
    };

    class CBaseTriggerAPI {
    public:
    };

    class IntervalTimer {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_timestamp                                     , 0x8)
        SCHEMA_FIELD(::WorldGroupId_t                , m_nWorldGroupId                                 , 0xC)
    };

    class C_EconItemView {
    public:
        SCHEMA_FIELD(bool                            , m_bInventoryImageRgbaRequested                  , 0x60)
        SCHEMA_FIELD(bool                            , m_bInventoryImageTriedCache                     , 0x61)
        SCHEMA_FIELD(std::int32_t                    , m_nInventoryImageRgbaWidth                      , 0x80)
        SCHEMA_FIELD(std::int32_t                    , m_nInventoryImageRgbaHeight                     , 0x84)
        SCHEMA_FIELD(char                            , m_szCurrentLoadCachedFileName                   , 0x88)
        SCHEMA_FIELD(bool                            , m_bRestoreCustomMaterialAfterPrecache           , 0x1B8)
        SCHEMA_FIELD(std::uint16_t                   , m_iItemDefinitionIndex                          , 0x1BA)
        SCHEMA_FIELD(std::int32_t                    , m_iEntityQuality                                , 0x1BC)
        SCHEMA_FIELD(std::uint32_t                   , m_iEntityLevel                                  , 0x1C0)
        SCHEMA_FIELD(std::uint64_t                   , m_iItemID                                       , 0x1C8)
        SCHEMA_FIELD(std::uint32_t                   , m_iItemIDHigh                                   , 0x1D0)
        SCHEMA_FIELD(std::uint32_t                   , m_iItemIDLow                                    , 0x1D4)
        SCHEMA_FIELD(std::uint32_t                   , m_iAccountID                                    , 0x1D8)
        SCHEMA_FIELD(std::uint32_t                   , m_iInventoryPosition                            , 0x1DC)
        SCHEMA_FIELD(bool                            , m_bInitialized                                  , 0x1E8)
        SCHEMA_FIELD(bool                            , m_bDisallowSOC                                  , 0x1E9)
        SCHEMA_FIELD(bool                            , m_bIsStoreItem                                  , 0x1EA)
        SCHEMA_FIELD(bool                            , m_bIsTradeItem                                  , 0x1EB)
        SCHEMA_FIELD(std::int32_t                    , m_iEntityQuantity                               , 0x1EC)
        SCHEMA_FIELD(std::int32_t                    , m_iRarityOverride                               , 0x1F0)
        SCHEMA_FIELD(std::int32_t                    , m_iQualityOverride                              , 0x1F4)
        SCHEMA_FIELD(std::int32_t                    , m_iOriginOverride                               , 0x1F8)
        SCHEMA_FIELD(std::uint8_t                    , m_ubStyleOverride                               , 0x1FC)
        SCHEMA_FIELD(std::uint8_t                    , m_unClientFlags                                 , 0x1FD)
        SCHEMA_FIELD(CAttributeList                  , m_AttributeList                                 , 0x208)
        SCHEMA_FIELD(CAttributeList                  , m_NetworkedDynamicAttributes                    , 0x280)
        SCHEMA_FIELD(char                            , m_szCustomName                                  , 0x2F8)
        SCHEMA_FIELD(char                            , m_szCustomNameOverride                          , 0x399)
        SCHEMA_FIELD(bool                            , m_bInitializedTags                              , 0x468)
    };

    class EngineCountdownTimer {
    public:
        SCHEMA_FIELD(float                           , m_duration                                      , 0x8)
        SCHEMA_FIELD(float                           , m_timestamp                                     , 0xC)
        SCHEMA_FIELD(float                           , m_timescale                                     , 0x10)
    };

    class CClientAlphaProperty {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nDistFadeStart                                , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , m_nDistFadeEnd                                  , 0x12)

        SCHEMA_FIELD(std::uint8_t                    , m_nAlpha                                        , 0x17)
        SCHEMA_FIELD(float                           , m_flFadeScale                                   , 0x18)
        SCHEMA_FIELD(::GameTime_t                    , m_flRenderFxStartTime                           , 0x1C)
        SCHEMA_FIELD(float                           , m_flRenderFxDuration                            , 0x20)
    };

    class CCSPlayer_WeaponServices : public CPlayer_WeaponServices {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flNextAttack                                  , 0xD0)
        SCHEMA_FIELD(std::uint32_t                   , m_nOldTotalShootPositionHistoryCount            , 0xD4)
        SCHEMA_FIELD(std::uint32_t                   , m_nOldTotalInputHistoryCount                    , 0x370)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<uint8>   , m_networkAnimTiming                             , 0x1588)
        SCHEMA_FIELD(bool                            , m_bBlockInspectUntilNextGraphUpdate             , 0x15A0)
    };

    class CSkeletonInstance : public CGameSceneNode {
    public:
        SCHEMA_FIELD(CModelState                     , m_modelState                                    , 0x150)
        SCHEMA_FIELD(bool                            , m_bUseParentRenderBounds                        , 0x3C0)
        SCHEMA_FIELD(bool                            , m_bDisableSolidCollisionsForHierarchy           , 0x3C1)

        SCHEMA_FIELD(CUtlStringToken                 , m_materialGroup                                 , 0x3C4)
        SCHEMA_FIELD(std::uint8_t                    , m_nHitboxSet                                    , 0x3C8)
    };

    class C_SkyCamera : public C_BaseEntity {
    public:
        SCHEMA_FIELD(sky3dparams_t                   , m_skyboxData                                    , 0x600)
        SCHEMA_FIELD(CUtlStringToken                 , m_skyboxSlotToken                               , 0x690)
        SCHEMA_FIELD(bool                            , m_bUseAngles                                    , 0x694)
        SCHEMA_FIELD(C_SkyCamera*                    , m_pNext                                         , 0x698)
    };

    class C_SoundOpvarSetPointBase : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStackName                                  , 0x600)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOperatorName                               , 0x608)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOpvarName                                  , 0x610)
        SCHEMA_FIELD(std::int32_t                    , m_iOpvarIndex                                   , 0x618)
        SCHEMA_FIELD(bool                            , m_bUseAutoCompare                               , 0x61C)
        SCHEMA_FIELD(bool                            , m_bFastRefresh                                  , 0x61D)
    };

    class C_EnvCubemapFog : public C_BaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flEndDistance                                 , 0x600)
        SCHEMA_FIELD(float                           , m_flStartDistance                               , 0x604)
        SCHEMA_FIELD(float                           , m_flFogFalloffExponent                          , 0x608)
        SCHEMA_FIELD(bool                            , m_bHeightFogEnabled                             , 0x60C)
        SCHEMA_FIELD(float                           , m_flFogHeightWidth                              , 0x610)
        SCHEMA_FIELD(float                           , m_flFogHeightEnd                                , 0x614)
        SCHEMA_FIELD(float                           , m_flFogHeightStart                              , 0x618)
        SCHEMA_FIELD(float                           , m_flFogHeightExponent                           , 0x61C)
        SCHEMA_FIELD(float                           , m_flLODBias                                     , 0x620)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x624)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x625)
        SCHEMA_FIELD(float                           , m_flFogMaxOpacity                               , 0x628)
        SCHEMA_FIELD(std::int32_t                    , m_nCubemapSourceType                            , 0x62C)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSkyMaterial                                  , 0x630)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSkyEntity                                  , 0x638)
        SCHEMA_FIELD(std::int32_t                    , m_nHeightFogType                                , 0x640)
        SCHEMA_FIELD(std::int32_t                    , m_nFogHeightBlendMode                           , 0x644)
        SCHEMA_FIELD(std::int32_t                    , m_nFogHeightCoordinateSpace                     , 0x648)
        SCHEMA_FIELD(std::int32_t                    , m_nDistanceFogType                              , 0x64C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_DistanceFogCurveString                        , 0x650)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_HeightFogCurveString                          , 0x658)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hFogCubemapTexture                            , 0x6F0)
        SCHEMA_FIELD(bool                            , m_bHasHeightFogEnd                              , 0x6F8)
        SCHEMA_FIELD(bool                            , m_bFirstTime                                    , 0x6F9)
    };

    class CCS_PortraitWorldCallbackHandler : public C_BaseEntity {
    public:
    };

    class C_MapVetoPickController : public C_BaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nDraftType                                    , 0x610)
        SCHEMA_FIELD(std::int32_t                    , m_nTeamWinningCoinToss                          , 0x614)
        SCHEMA_FIELD(std::int32_t                    , m_nTeamWithFirstChoice                          , 0x618)
        SCHEMA_FIELD(std::int32_t                    , m_nVoteMapIdsList                               , 0x718)
        SCHEMA_FIELD(std::int32_t                    , m_nAccountIDs                                   , 0x734)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId0                                       , 0x834)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId1                                       , 0x934)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId2                                       , 0xA34)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId3                                       , 0xB34)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId4                                       , 0xC34)
        SCHEMA_FIELD(std::int32_t                    , m_nMapId5                                       , 0xD34)
        SCHEMA_FIELD(std::int32_t                    , m_nStartingSide0                                , 0xE34)
        SCHEMA_FIELD(std::int32_t                    , m_nCurrentPhase                                 , 0xF34)
        SCHEMA_FIELD(std::int32_t                    , m_nPhaseStartTick                               , 0xF38)
        SCHEMA_FIELD(std::int32_t                    , m_nPhaseDurationTicks                           , 0xF3C)
        SCHEMA_FIELD(std::int32_t                    , m_nPostDataUpdateTick                           , 0xF40)
        SCHEMA_FIELD(bool                            , m_bDisabledHud                                  , 0xF44)
    };

    class C_EnvVolumetricFogVolume : public C_BaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x600)
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x604)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x610)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x61C)
        SCHEMA_FIELD(bool                            , m_bIndirectUseLPVs                              , 0x61D)
        SCHEMA_FIELD(float                           , m_flStrength                                    , 0x620)
        SCHEMA_FIELD(std::int32_t                    , m_nFalloffShape                                 , 0x624)
        SCHEMA_FIELD(float                           , m_flFalloffExponent                             , 0x628)
        SCHEMA_FIELD(float                           , m_flHeightFogDepth                              , 0x62C)
        SCHEMA_FIELD(float                           , m_fHeightFogEdgeWidth                           , 0x630)
        SCHEMA_FIELD(float                           , m_fIndirectLightStrength                        , 0x634)
        SCHEMA_FIELD(float                           , m_fSunLightStrength                             , 0x638)
        SCHEMA_FIELD(float                           , m_fNoiseStrength                                , 0x63C)
        SCHEMA_FIELD(::Color                         , m_TintColor                                     , 0x640)
        SCHEMA_FIELD(bool                            , m_bOverrideTintColor                            , 0x644)
        SCHEMA_FIELD(bool                            , m_bOverrideIndirectLightStrength                , 0x645)
        SCHEMA_FIELD(bool                            , m_bOverrideSunLightStrength                     , 0x646)
        SCHEMA_FIELD(bool                            , m_bOverrideNoiseStrength                        , 0x647)
    };

    class C_VoteController : public C_BaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iActiveIssueIndex                             , 0x610)
        SCHEMA_FIELD(std::int32_t                    , m_iOnlyTeamToVote                               , 0x614)
        SCHEMA_FIELD(std::int32_t                    , m_nVoteOptionCount                              , 0x618)
        SCHEMA_FIELD(std::int32_t                    , m_nPotentialVotes                               , 0x62C)
        SCHEMA_FIELD(bool                            , m_bVotesDirty                                   , 0x630)
        SCHEMA_FIELD(bool                            , m_bTypeDirty                                    , 0x631)
        SCHEMA_FIELD(bool                            , m_bIsYesNoVote                                  , 0x632)
    };

    class C_CSMinimapBoundary : public C_BaseEntity {
    public:
    };

    class C_EnvVolumetricFogController : public C_BaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flScattering                                  , 0x600)
        SCHEMA_FIELD(::Color                         , m_TintColor                                     , 0x604)
        SCHEMA_FIELD(float                           , m_flAnisotropy                                  , 0x608)
        SCHEMA_FIELD(float                           , m_flFadeSpeed                                   , 0x60C)
        SCHEMA_FIELD(float                           , m_flDrawDistance                                , 0x610)
        SCHEMA_FIELD(float                           , m_flFadeInStart                                 , 0x614)
        SCHEMA_FIELD(float                           , m_flFadeInEnd                                   , 0x618)
        SCHEMA_FIELD(float                           , m_flIndirectStrength                            , 0x61C)
        SCHEMA_FIELD(std::int32_t                    , m_nVolumeDepth                                  , 0x620)
        SCHEMA_FIELD(float                           , m_fFirstVolumeSliceThickness                    , 0x624)
        SCHEMA_FIELD(std::int32_t                    , m_nIndirectTextureDimX                          , 0x628)
        SCHEMA_FIELD(std::int32_t                    , m_nIndirectTextureDimY                          , 0x62C)
        SCHEMA_FIELD(std::int32_t                    , m_nIndirectTextureDimZ                          , 0x630)
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x634)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x640)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x64C)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartAnisoTime                              , 0x650)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartScatterTime                            , 0x654)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartDrawDistanceTime                       , 0x658)
        SCHEMA_FIELD(float                           , m_flStartAnisotropy                             , 0x65C)
        SCHEMA_FIELD(float                           , m_flStartScattering                             , 0x660)
        SCHEMA_FIELD(float                           , m_flStartDrawDistance                           , 0x664)
        SCHEMA_FIELD(float                           , m_flDefaultAnisotropy                           , 0x668)
        SCHEMA_FIELD(float                           , m_flDefaultScattering                           , 0x66C)
        SCHEMA_FIELD(float                           , m_flDefaultDrawDistance                         , 0x670)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x674)
        SCHEMA_FIELD(bool                            , m_bEnableIndirect                               , 0x675)
        SCHEMA_FIELD(bool                            , m_bIsMaster                                     , 0x676)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hFogIndirectTexture                           , 0x678)
        SCHEMA_FIELD(std::int32_t                    , m_nForceRefreshCount                            , 0x680)
        SCHEMA_FIELD(float                           , m_fNoiseSpeed                                   , 0x684)
        SCHEMA_FIELD(float                           , m_fNoiseStrength                                , 0x688)
        SCHEMA_FIELD(::Vector                        , m_vNoiseScale                                   , 0x68C)
        SCHEMA_FIELD(float                           , m_fWindSpeed                                    , 0x698)
        SCHEMA_FIELD(::Vector                        , m_vWindDirection                                , 0x69C)
        SCHEMA_FIELD(bool                            , m_bFirstTime                                    , 0x6A8)
    };

    class C_EnvDetailController : public C_BaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flFadeStartDist                               , 0x600)
        SCHEMA_FIELD(float                           , m_flFadeEndDist                                 , 0x604)
    };

    class C_EnvWindVolume : public C_BaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x600)
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x604)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x610)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x61C)
        SCHEMA_FIELD(std::int32_t                    , m_nShape                                        , 0x620)
        SCHEMA_FIELD(float                           , m_fWindSpeedMultiplier                          , 0x624)
        SCHEMA_FIELD(float                           , m_fWindTurbulenceMultiplier                     , 0x628)
        SCHEMA_FIELD(float                           , m_fWindSpeedVariationMultiplier                 , 0x62C)
        SCHEMA_FIELD(float                           , m_fWindDirectionVariationMultiplier             , 0x630)
    };

    class C_GameRulesProxy : public C_BaseEntity {
    public:
    };

    class C_Team : public C_BaseEntity {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<CBasePlayerController>>, m_aPlayerControllers                            , 0x600)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BasePlayerPawn>>, m_aPlayers                                      , 0x618)
        SCHEMA_FIELD(std::int32_t                    , m_iScore                                        , 0x630)
        SCHEMA_FIELD(char                            , m_szTeamname                                    , 0x634)
    };

    class C_ColorCorrection : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecOrigin                                     , 0x600)
        SCHEMA_FIELD(float                           , m_MinFalloff                                    , 0x60C)
        SCHEMA_FIELD(float                           , m_MaxFalloff                                    , 0x610)
        SCHEMA_FIELD(float                           , m_flFadeInDuration                              , 0x614)
        SCHEMA_FIELD(float                           , m_flFadeOutDuration                             , 0x618)
        SCHEMA_FIELD(float                           , m_flMaxWeight                                   , 0x61C)
        SCHEMA_FIELD(float                           , m_flCurWeight                                   , 0x620)
        SCHEMA_FIELD(char                            , m_netlookupFilename                             , 0x624)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x824)
        SCHEMA_FIELD(bool                            , m_bMaster                                       , 0x825)
        SCHEMA_FIELD(bool                            , m_bClientSide                                   , 0x826)
        SCHEMA_FIELD(bool                            , m_bExclusive                                    , 0x827)
        SCHEMA_FIELD(bool                            , m_bEnabledOnClient                              , 0x828)
        SCHEMA_FIELD(float                           , m_flCurWeightOnClient                           , 0x82C)
        SCHEMA_FIELD(bool                            , m_bFadingIn                                     , 0x830)
        SCHEMA_FIELD(float                           , m_flFadeStartWeight                             , 0x834)
        SCHEMA_FIELD(float                           , m_flFadeStartTime                               , 0x838)
        SCHEMA_FIELD(float                           , m_flFadeDuration                                , 0x83C)
    };

    class CEnvSoundscape : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlay                                        , 0x600)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x618)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_soundEventName                                , 0x620)
        SCHEMA_FIELD(bool                            , m_bOverrideWithEvent                            , 0x628)
        SCHEMA_FIELD(std::int32_t                    , m_soundscapeIndex                               , 0x62C)
        SCHEMA_FIELD(std::int32_t                    , m_soundscapeEntityListId                        , 0x630)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_positionNames                                 , 0x638)
        SCHEMA_FIELD(CHandle<CEnvSoundscape>         , m_hProxySoundscape                              , 0x678)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x67C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_soundscapeName                                , 0x680)
        SCHEMA_FIELD(std::uint32_t                   , m_soundEventHash                                , 0x688)
    };

    class C_FogController : public C_BaseEntity {
    public:
        SCHEMA_FIELD(fogparams_t                     , m_fog                                           , 0x600)
        SCHEMA_FIELD(bool                            , m_bUseAngles                                    , 0x668)
        SCHEMA_FIELD(std::int32_t                    , m_iChangedVariables                             , 0x66C)
    };

    class C_InfoVisibilityBox : public C_BaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nMode                                         , 0x604)
        SCHEMA_FIELD(::Vector                        , m_vBoxSize                                      , 0x608)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x614)
    };

    class C_PathParticleRope : public C_BaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bStartActive                                  , 0x608)
        SCHEMA_FIELD(float                           , m_flMaxSimulationTime                           , 0x60C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEffectName                                 , 0x610)
        SCHEMA_FIELD(CUtlVector<CUtlSymbolLarge>     , m_PathNodes_Name                                , 0x618)
        SCHEMA_FIELD(float                           , m_flParticleSpacing                             , 0x630)
        SCHEMA_FIELD(float                           , m_flSlack                                       , 0x634)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x638)
        SCHEMA_FIELD(::Color                         , m_ColorTint                                     , 0x63C)
        SCHEMA_FIELD(std::int32_t                    , m_nEffectState                                  , 0x640)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_iEffectIndex                                  , 0x648)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<Vector>  , m_PathNodes_Position                            , 0x650)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<Vector>  , m_PathNodes_TangentIn                           , 0x668)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<Vector>  , m_PathNodes_TangentOut                          , 0x680)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<Vector>  , m_PathNodes_Color                               , 0x698)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<bool>    , m_PathNodes_PinEnabled                          , 0x6B0)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<float32> , m_PathNodes_RadiusScale                         , 0x6C8)
    };

    class C_TonemapController2 : public C_BaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flAutoExposureMin                             , 0x600)
        SCHEMA_FIELD(float                           , m_flAutoExposureMax                             , 0x604)
        SCHEMA_FIELD(float                           , m_flExposureAdaptationSpeedUp                   , 0x608)
        SCHEMA_FIELD(float                           , m_flExposureAdaptationSpeedDown                 , 0x60C)
        SCHEMA_FIELD(float                           , m_flTonemapEVSmoothingRange                     , 0x610)
    };

    class C_InfoLadderDismount : public C_BaseEntity {
    public:
    };

    class C_SoundAreaEntityBase : public C_BaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x600)
        SCHEMA_FIELD(bool                            , m_bWasEnabled                                   , 0x608)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundAreaType                              , 0x610)
        SCHEMA_FIELD(::Vector                        , m_vPos                                          , 0x618)
    };

    class C_PlayerVisibility : public C_BaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flVisibilityStrength                          , 0x600)
        SCHEMA_FIELD(float                           , m_flFogDistanceMultiplier                       , 0x604)
        SCHEMA_FIELD(float                           , m_flFogMaxDensityMultiplier                     , 0x608)
        SCHEMA_FIELD(float                           , m_flFadeTime                                    , 0x60C)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x610)
        SCHEMA_FIELD(bool                            , m_bIsEnabled                                    , 0x611)
    };

    class CRagdollManager : public C_BaseEntity {
    public:
        SCHEMA_FIELD(std::int8_t                     , m_iCurrentMaxRagdollCount                       , 0x600)
    };

    class C_EnvWindController : public C_BaseEntity {
    public:
        SCHEMA_FIELD(C_EnvWindShared                 , m_EnvWindShared                                 , 0x600)
        SCHEMA_FIELD(float                           , m_fDirectionVariation                           , 0x6F8)
        SCHEMA_FIELD(float                           , m_fSpeedVariation                               , 0x6FC)
        SCHEMA_FIELD(float                           , m_fTurbulence                                   , 0x700)
        SCHEMA_FIELD(float                           , m_fVolumeHalfExtentXY                           , 0x704)
        SCHEMA_FIELD(float                           , m_fVolumeHalfExtentZ                            , 0x708)
        SCHEMA_FIELD(std::int32_t                    , m_nVolumeResolutionXY                           , 0x70C)
        SCHEMA_FIELD(std::int32_t                    , m_nVolumeResolutionZ                            , 0x710)
        SCHEMA_FIELD(std::int32_t                    , m_nClipmapLevels                                , 0x714)
        SCHEMA_FIELD(bool                            , m_bIsMaster                                     , 0x718)
        SCHEMA_FIELD(bool                            , m_bFirstTime                                    , 0x719)
    };

    class C_CSGO_MapPreviewCameraPath : public C_BaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_flZFar                                        , 0x600)
        SCHEMA_FIELD(float                           , m_flZNear                                       , 0x604)
        SCHEMA_FIELD(bool                            , m_bLoop                                         , 0x608)
        SCHEMA_FIELD(bool                            , m_bVerticalFOV                                  , 0x609)
        SCHEMA_FIELD(bool                            , m_bConstantSpeed                                , 0x60A)
        SCHEMA_FIELD(float                           , m_flDuration                                    , 0x60C)
        SCHEMA_FIELD(float                           , m_flPathLength                                  , 0x650)
        SCHEMA_FIELD(float                           , m_flPathDuration                                , 0x654)
        SCHEMA_FIELD(bool                            , m_bDofEnabled                                   , 0x66C)
        SCHEMA_FIELD(float                           , m_flDofNearBlurry                               , 0x670)
        SCHEMA_FIELD(float                           , m_flDofNearCrisp                                , 0x674)
        SCHEMA_FIELD(float                           , m_flDofFarCrisp                                 , 0x678)
        SCHEMA_FIELD(float                           , m_flDofFarBlurry                                , 0x67C)
        SCHEMA_FIELD(float                           , m_flDofTiltToGround                             , 0x680)
    };

    class C_BaseModelEntity : public C_BaseEntity {
    public:
        using _Type0 = CUtlOrderedMap<CGlobalSymbol,int32>;
        SCHEMA_FIELD(CRenderComponent*               , m_CRenderComponent                              , 0xAF0)
        SCHEMA_FIELD(CHitboxComponent                , m_CHitboxComponent                              , 0xAF8)
        SCHEMA_FIELD(CChoreoComponent*               , m_pChoreoComponent                              , 0xB10)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed0      , 0xB18)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed1      , 0xB1C)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed2      , 0xB20)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed3      , 0xB24)
        SCHEMA_FIELD(HitGroup_t                      , m_nDestructiblePartInitialStateDestructed4      , 0xB28)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed0_PartIndex, 0xB2C)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed1_PartIndex, 0xB30)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed2_PartIndex, 0xB34)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed3_PartIndex, 0xB38)
        SCHEMA_FIELD(std::int32_t                    , m_nDestructiblePartInitialStateDestructed4_PartIndex, 0xB3C)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed0_GenerateBreakpieces, 0xB40)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed1_GenerateBreakpieces, 0xB41)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed2_GenerateBreakpieces, 0xB42)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed3_GenerateBreakpieces, 0xB43)
        SCHEMA_FIELD(bool                            , m_bDestructiblePartInitialStateDestructed4_GenerateBreakpieces, 0xB44)
        SCHEMA_FIELD(CDestructiblePartsComponent*    , m_pDestructiblePartsSystemComponent             , 0xB48)
        SCHEMA_FIELD(bool                            , m_bInitModelEffects                             , 0xC70)
        SCHEMA_FIELD(bool                            , m_bDoingModelEffects                            , 0xC71)
        SCHEMA_FIELD(std::int32_t                    , m_iOldHealth                                    , 0xC74)
        SCHEMA_FIELD(RenderMode_t                    , m_nRenderMode                                   , 0xC78)
        SCHEMA_FIELD(RenderFx_t                      , m_nRenderFX                                     , 0xC79)
        SCHEMA_FIELD(bool                            , m_bAllowFadeInView                              , 0xC7A)
        SCHEMA_FIELD(::Color                         , m_clrRender                                     , 0xC98)
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<EntityRenderAttribute_t>, m_vecRenderAttributes                           , 0xCA0)
        SCHEMA_FIELD(bool                            , m_bRenderToCubemaps                             , 0xD20)
        SCHEMA_FIELD(bool                            , m_bNoInterpolate                                , 0xD21)
        SCHEMA_FIELD(CCollisionProperty              , m_Collision                                     , 0xD28)
        SCHEMA_FIELD(CGlowProperty                   , m_Glow                                          , 0xDD8)
        SCHEMA_FIELD(float                           , m_flGlowBackfaceMult                            , 0xE30)
        SCHEMA_FIELD(float                           , m_fadeMinDist                                   , 0xE34)
        SCHEMA_FIELD(float                           , m_fadeMaxDist                                   , 0xE38)
        SCHEMA_FIELD(float                           , m_flFadeScale                                   , 0xE3C)
        SCHEMA_FIELD(float                           , m_flShadowStrength                              , 0xE40)
        SCHEMA_FIELD(std::uint8_t                    , m_nObjectCulling                                , 0xE44)
        SCHEMA_FIELD(DecalRtEncoding_t               , m_nRequiredDecalRtEncoding                      , 0xE45)
        SCHEMA_FIELD(_Type0                          , m_bodyGroupChoices                              , 0xE48)
        SCHEMA_FIELD(CNetworkViewOffsetVector        , m_vecViewOffset                                 , 0xE70)
        SCHEMA_FIELD(CClientAlphaProperty*           , m_pClientAlphaProperty                          , 0xF50)
        SCHEMA_FIELD(::Color                         , m_ClientOverrideTint                            , 0xF58)
        SCHEMA_FIELD(bool                            , m_bUseClientOverrideTint                        , 0xF5C)
        SCHEMA_FIELD(std::uint32_t                   , m_bvDisabledHitGroups                           , 0xF98)
    };

    class C_EnvCombinedLightProbeVolume : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::Color                         , m_Entity_Color                                  , 0x1678)
        SCHEMA_FIELD(float                           , m_Entity_flBrightness                           , 0x167C)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hCubemapTexture                        , 0x1680)
        SCHEMA_FIELD(bool                            , m_Entity_bCustomCubemapTexture                  , 0x1688)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_AmbientCube         , 0x1690)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SDF                 , 0x1698)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_DC              , 0x16A0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_R               , 0x16A8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_G               , 0x16B0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_B               , 0x16B8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightIndicesTexture   , 0x16C0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightScalarsTexture   , 0x16C8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightShadowsTexture   , 0x16D0)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMins                               , 0x16D8)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMaxs                               , 0x16E4)
        SCHEMA_FIELD(bool                            , m_Entity_bMoveable                              , 0x16F0)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nHandshake                             , 0x16F4)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nEnvCubeMapArrayIndex                  , 0x16F8)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nPriority                              , 0x16FC)
        SCHEMA_FIELD(bool                            , m_Entity_bStartDisabled                         , 0x1700)
        SCHEMA_FIELD(float                           , m_Entity_flEdgeFadeDist                         , 0x1704)
        SCHEMA_FIELD(::Vector                        , m_Entity_vEdgeFadeDists                         , 0x1708)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeX                       , 0x1714)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeY                       , 0x1718)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeZ                       , 0x171C)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasX                      , 0x1720)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasY                      , 0x1724)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasZ                      , 0x1728)
        SCHEMA_FIELD(bool                            , m_Entity_bEnabled                               , 0x1741)
    };

    class C_SoundEventEntity : public C_BaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bStartOnSpawn                                 , 0x600)
        SCHEMA_FIELD(bool                            , m_bToLocalPlayer                                , 0x601)
        SCHEMA_FIELD(bool                            , m_bStopOnNew                                    , 0x602)
        SCHEMA_FIELD(bool                            , m_bSaveRestore                                  , 0x603)
        SCHEMA_FIELD(bool                            , m_bSavedIsPlaying                               , 0x604)
        SCHEMA_FIELD(float                           , m_flSavedElapsedTime                            , 0x608)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSourceEntityName                           , 0x610)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszAttachmentName                             , 0x618)
        SCHEMA_FIELD(CEntityOutputTemplate<SndOpEventGuid_t>, m_onGUIDChanged                                 , 0x620)
        SCHEMA_FIELD(CEntityIOOutput                 , m_onSoundFinished                               , 0x650)
        SCHEMA_FIELD(float                           , m_flClientCullRadius                            , 0x668)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSoundName                                  , 0x698)
        SCHEMA_FIELD(CEntityHandle                   , m_hSource                                       , 0x6B4)
        SCHEMA_FIELD(std::int32_t                    , m_nEntityIndexSelection                         , 0x6B8)

    };

    class C_TintController : public C_BaseEntity {
    public:
    };

    class CPointOrient : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpawnTargetName                            , 0x600)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hTarget                                       , 0x608)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x60C)
        SCHEMA_FIELD(PointOrientGoalDirectionType_t  , m_nGoalDirection                                , 0x610)
        SCHEMA_FIELD(PointOrientConstraint_t         , m_nConstraint                                   , 0x614)
        SCHEMA_FIELD(float                           , m_flMaxTurnRate                                 , 0x618)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastGameTime                                , 0x61C)
    };

    class C_GlobalLight : public C_BaseEntity {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_WindClothForceHandle                          , 0xAC0)
    };

    class C_EnvWindClientside : public C_BaseEntity {
    public:
        SCHEMA_FIELD(C_EnvWindShared                 , m_EnvWindShared                                 , 0x600)
    };

    class C_EnvWind : public C_BaseEntity {
    public:
        SCHEMA_FIELD(C_EnvWindShared                 , m_EnvWindShared                                 , 0x600)
    };

    class C_CSGO_TeamPreviewCharacterPosition : public C_BaseEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nVariant                                      , 0x600)
        SCHEMA_FIELD(std::int32_t                    , m_nRandom                                       , 0x604)
        SCHEMA_FIELD(std::int32_t                    , m_nOrdinal                                      , 0x608)
        SCHEMA_FIELD(::CUtlString                    , m_sWeaponName                                   , 0x610)
        SCHEMA_FIELD(std::uint64_t                   , m_xuid                                          , 0x618)
        SCHEMA_FIELD(C_EconItemView                  , m_agentItem                                     , 0x620)
        SCHEMA_FIELD(C_EconItemView                  , m_glovesItem                                    , 0xA90)
        SCHEMA_FIELD(C_EconItemView                  , m_weaponItem                                    , 0xF00)
    };

    class C_PortraitWorldCallbackHandler : public C_BaseEntity {
    public:
    };

    class C_HandleTest : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_Handle                                        , 0x600)
        SCHEMA_FIELD(bool                            , m_bSendHandle                                   , 0x604)
    };

    class CInfoWorldLayer : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputOnEntitiesSpawned                      , 0x600)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_worldName                                     , 0x618)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_layerName                                     , 0x620)
        SCHEMA_FIELD(bool                            , m_bWorldLayerVisible                            , 0x628)
        SCHEMA_FIELD(bool                            , m_bEntitiesSpawned                              , 0x629)
        SCHEMA_FIELD(bool                            , m_bCreateAsChildSpawnGroup                      , 0x62A)
        SCHEMA_FIELD(std::uint32_t                   , m_hLayerSpawnGroup                              , 0x62C)
        SCHEMA_FIELD(bool                            , m_bWorldLayerActuallyVisible                    , 0x630)
    };

    class C_EnvCubemap : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hCubemapTexture                        , 0x680)
        SCHEMA_FIELD(bool                            , m_Entity_bCustomCubemapTexture                  , 0x688)
        SCHEMA_FIELD(float                           , m_Entity_flInfluenceRadius                      , 0x68C)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxProjectMins                        , 0x690)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxProjectMaxs                        , 0x69C)
        SCHEMA_FIELD(bool                            , m_Entity_bMoveable                              , 0x6A8)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nHandshake                             , 0x6AC)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nEnvCubeMapArrayIndex                  , 0x6B0)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nPriority                              , 0x6B4)
        SCHEMA_FIELD(float                           , m_Entity_flEdgeFadeDist                         , 0x6B8)
        SCHEMA_FIELD(::Vector                        , m_Entity_vEdgeFadeDists                         , 0x6BC)
        SCHEMA_FIELD(float                           , m_Entity_flDiffuseScale                         , 0x6C8)
        SCHEMA_FIELD(bool                            , m_Entity_bStartDisabled                         , 0x6CC)
        SCHEMA_FIELD(bool                            , m_Entity_bDefaultEnvMap                         , 0x6CD)
        SCHEMA_FIELD(bool                            , m_Entity_bDefaultSpecEnvMap                     , 0x6CE)
        SCHEMA_FIELD(bool                            , m_Entity_bIndoorCubeMap                         , 0x6CF)
        SCHEMA_FIELD(bool                            , m_Entity_bCopyDiffuseFromDefaultCubemap         , 0x6D0)
        SCHEMA_FIELD(bool                            , m_Entity_bEnabled                               , 0x6E0)
    };

    class CCitadelSoundOpvarSetOBB : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszStackName                                  , 0x618)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOperatorName                               , 0x620)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszOpvarName                                  , 0x628)
        SCHEMA_FIELD(::Vector                        , m_vDistanceInnerMins                            , 0x630)
        SCHEMA_FIELD(::Vector                        , m_vDistanceInnerMaxs                            , 0x63C)
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMins                            , 0x648)
        SCHEMA_FIELD(::Vector                        , m_vDistanceOuterMaxs                            , 0x654)
        SCHEMA_FIELD(std::int32_t                    , m_nAABBDirection                                , 0x660)
    };

    class C_PointValueRemapper : public C_BaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x600)
        SCHEMA_FIELD(bool                            , m_bDisabledOld                                  , 0x601)
        SCHEMA_FIELD(bool                            , m_bUpdateOnClient                               , 0x602)
        SCHEMA_FIELD(ValueRemapperInputType_t        , m_nInputType                                    , 0x604)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hRemapLineStart                               , 0x608)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hRemapLineEnd                                 , 0x60C)
        SCHEMA_FIELD(float                           , m_flMaximumChangePerSecond                      , 0x610)
        SCHEMA_FIELD(float                           , m_flDisengageDistance                           , 0x614)
        SCHEMA_FIELD(float                           , m_flEngageDistance                              , 0x618)
        SCHEMA_FIELD(bool                            , m_bRequiresUseKey                               , 0x61C)
        SCHEMA_FIELD(ValueRemapperOutputType_t       , m_nOutputType                                   , 0x620)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BaseEntity>>, m_hOutputEntities                               , 0x628)
        SCHEMA_FIELD(ValueRemapperHapticsType_t      , m_nHapticsType                                  , 0x640)
        SCHEMA_FIELD(ValueRemapperMomentumType_t     , m_nMomentumType                                 , 0x644)
        SCHEMA_FIELD(float                           , m_flMomentumModifier                            , 0x648)
        SCHEMA_FIELD(float                           , m_flSnapValue                                   , 0x64C)
        SCHEMA_FIELD(float                           , m_flCurrentMomentum                             , 0x650)
        SCHEMA_FIELD(ValueRemapperRatchetType_t      , m_nRatchetType                                  , 0x654)
        SCHEMA_FIELD(float                           , m_flRatchetOffset                               , 0x658)
        SCHEMA_FIELD(float                           , m_flInputOffset                                 , 0x65C)
        SCHEMA_FIELD(bool                            , m_bEngaged                                      , 0x660)
        SCHEMA_FIELD(bool                            , m_bFirstUpdate                                  , 0x661)
        SCHEMA_FIELD(float                           , m_flPreviousValue                               , 0x664)
        SCHEMA_FIELD(::GameTime_t                    , m_flPreviousUpdateTickTime                      , 0x668)
        SCHEMA_FIELD(::Vector                        , m_vecPreviousTestPoint                          , 0x66C)
    };

    class C_GradientFog : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hGradientFogTexture                           , 0x600)
        SCHEMA_FIELD(float                           , m_flFogStartDistance                            , 0x608)
        SCHEMA_FIELD(float                           , m_flFogEndDistance                              , 0x60C)
        SCHEMA_FIELD(bool                            , m_bHeightFogEnabled                             , 0x610)
        SCHEMA_FIELD(float                           , m_flFogStartHeight                              , 0x614)
        SCHEMA_FIELD(float                           , m_flFogEndHeight                                , 0x618)
        SCHEMA_FIELD(float                           , m_flFarZ                                        , 0x61C)
        SCHEMA_FIELD(float                           , m_flFogMaxOpacity                               , 0x620)
        SCHEMA_FIELD(float                           , m_flFogFalloffExponent                          , 0x624)
        SCHEMA_FIELD(float                           , m_flFogVerticalExponent                         , 0x628)
        SCHEMA_FIELD(::Color                         , m_fogColor                                      , 0x62C)
        SCHEMA_FIELD(float                           , m_flFogStrength                                 , 0x630)
        SCHEMA_FIELD(float                           , m_flFadeTime                                    , 0x634)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x638)
        SCHEMA_FIELD(bool                            , m_bIsEnabled                                    , 0x639)
        SCHEMA_FIELD(bool                            , m_bGradientFogNeedsTextures                     , 0x63A)
    };

    class CPulseGameBlackboard : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strGraphName                                  , 0x608)
        SCHEMA_FIELD(::CUtlString                    , m_strStateBlob                                  , 0x610)
    };

    class CPathSimple : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CPathQueryComponent             , m_CPathQueryComponent                           , 0x610)
        SCHEMA_FIELD(::CUtlString                    , m_pathString                                    , 0x700)
        SCHEMA_FIELD(bool                            , m_bClosedLoop                                   , 0x708)
    };

    class C_CSPetPlacement : public C_BaseEntity {
    public:
    };

    class C_EnvLightProbeVolume : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_AmbientCube         , 0x15F8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SDF                 , 0x1600)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_DC              , 0x1608)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_R               , 0x1610)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_G               , 0x1618)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeTexture_SH2_B               , 0x1620)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightIndicesTexture   , 0x1628)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightScalarsTexture   , 0x1630)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_Entity_hLightProbeDirectLightShadowsTexture   , 0x1638)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMins                               , 0x1640)
        SCHEMA_FIELD(::Vector                        , m_Entity_vBoxMaxs                               , 0x164C)
        SCHEMA_FIELD(bool                            , m_Entity_bMoveable                              , 0x1658)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nHandshake                             , 0x165C)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nPriority                              , 0x1660)
        SCHEMA_FIELD(bool                            , m_Entity_bStartDisabled                         , 0x1664)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeX                       , 0x1668)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeY                       , 0x166C)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeSizeZ                       , 0x1670)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasX                      , 0x1674)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasY                      , 0x1678)
        SCHEMA_FIELD(std::int32_t                    , m_Entity_nLightProbeAtlasZ                      , 0x167C)
        SCHEMA_FIELD(bool                            , m_Entity_bEnabled                               , 0x1689)
    };

    class C_PointEntity : public C_BaseEntity {
    public:
    };

    class CLogicalEntity : public C_BaseEntity {
    public:
    };

    class C_PlayerPing : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hPlayer                                       , 0x630)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hPingedEntity                                 , 0x634)
        SCHEMA_FIELD(std::int32_t                    , m_iType                                         , 0x638)
        SCHEMA_FIELD(bool                            , m_bUrgent                                       , 0x63C)
        SCHEMA_FIELD(char                            , m_szPlaceName                                   , 0x63D)
    };

    class C_CSGO_MapPreviewCameraPathNode : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szParentPathUniqueID                          , 0x600)
        SCHEMA_FIELD(std::int32_t                    , m_nPathIndex                                    , 0x608)
        SCHEMA_FIELD(::Vector                        , m_vInTangentLocal                               , 0x60C)
        SCHEMA_FIELD(::Vector                        , m_vOutTangentLocal                              , 0x618)
        SCHEMA_FIELD(float                           , m_flFOV                                         , 0x624)
        SCHEMA_FIELD(float                           , m_flCameraSpeed                                 , 0x628)
        SCHEMA_FIELD(float                           , m_flEaseIn                                      , 0x62C)
        SCHEMA_FIELD(float                           , m_flEaseOut                                     , 0x630)
        SCHEMA_FIELD(::Vector                        , m_vInTangentWorld                               , 0x634)
        SCHEMA_FIELD(::Vector                        , m_vOutTangentWorld                              , 0x640)
    };

    class C_CSPlayerResource : public C_BaseEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bHostageAlive                                 , 0x600)
        SCHEMA_FIELD(bool                            , m_isHostageFollowingSomeone                     , 0x60C)
        SCHEMA_FIELD(CEntityIndex                    , m_iHostageEntityIDs                             , 0x618)
        SCHEMA_FIELD(::Vector                        , m_bombsiteCenterA                               , 0x648)
        SCHEMA_FIELD(::Vector                        , m_bombsiteCenterB                               , 0x654)
        SCHEMA_FIELD(std::int32_t                    , m_hostageRescueX                                , 0x660)
        SCHEMA_FIELD(std::int32_t                    , m_hostageRescueY                                , 0x670)
        SCHEMA_FIELD(std::int32_t                    , m_hostageRescueZ                                , 0x680)
        SCHEMA_FIELD(bool                            , m_bEndMatchNextMapAllVoted                      , 0x690)
        SCHEMA_FIELD(bool                            , m_foundGoalPositions                            , 0x691)
    };

    class CSkyboxReference : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::WorldGroupId_t                , m_worldGroupId                                  , 0x600)
        SCHEMA_FIELD(CHandle<C_SkyCamera>            , m_hSkyCamera                                    , 0x604)
    };

    class C_PointCamera : public C_BaseEntity {
    public:
        SCHEMA_FIELD(float                           , m_FOV                                           , 0x600)
        SCHEMA_FIELD(float                           , m_Resolution                                    , 0x604)
        SCHEMA_FIELD(bool                            , m_bFogEnable                                    , 0x608)
        SCHEMA_FIELD(::Color                         , m_FogColor                                      , 0x609)
        SCHEMA_FIELD(float                           , m_flFogStart                                    , 0x610)
        SCHEMA_FIELD(float                           , m_flFogEnd                                      , 0x614)
        SCHEMA_FIELD(float                           , m_flFogMaxDensity                               , 0x618)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x61C)
        SCHEMA_FIELD(bool                            , m_bUseScreenAspectRatio                         , 0x61D)
        SCHEMA_FIELD(float                           , m_flAspectRatio                                 , 0x620)
        SCHEMA_FIELD(bool                            , m_bNoSky                                        , 0x624)
        SCHEMA_FIELD(float                           , m_fBrightness                                   , 0x628)
        SCHEMA_FIELD(float                           , m_flZFar                                        , 0x62C)
        SCHEMA_FIELD(float                           , m_flZNear                                       , 0x630)
        SCHEMA_FIELD(bool                            , m_bCanHLTVUse                                   , 0x634)
        SCHEMA_FIELD(bool                            , m_bAlignWithParent                              , 0x635)
        SCHEMA_FIELD(bool                            , m_bDofEnabled                                   , 0x636)
        SCHEMA_FIELD(float                           , m_flDofNearBlurry                               , 0x638)
        SCHEMA_FIELD(float                           , m_flDofNearCrisp                                , 0x63C)
        SCHEMA_FIELD(float                           , m_flDofFarCrisp                                 , 0x640)
        SCHEMA_FIELD(float                           , m_flDofFarBlurry                                , 0x644)
        SCHEMA_FIELD(float                           , m_flDofTiltToGround                             , 0x648)
        SCHEMA_FIELD(float                           , m_TargetFOV                                     , 0x64C)
        SCHEMA_FIELD(float                           , m_DegreesPerSecond                              , 0x650)
        SCHEMA_FIELD(bool                            , m_bIsOn                                         , 0x654)
        SCHEMA_FIELD(C_PointCamera*                  , m_pNext                                         , 0x658)
    };

    class C_CsmFovOverride : public C_BaseEntity {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_cameraName                                    , 0x600)
        SCHEMA_FIELD(float                           , m_flCsmFovOverrideValue                         , 0x608)
    };

    class C_EntityFlame : public C_BaseEntity {
    public:
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hEntAttached                                  , 0x600)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hOldAttached                                  , 0x628)
        SCHEMA_FIELD(bool                            , m_bCheapEffect                                  , 0x62C)
    };

    class CBasePlayerController : public C_BaseEntity {
    public:
        SCHEMA_FIELD(C_CommandContext                , m_CommandContext                                , 0x608)
        SCHEMA_FIELD(std::uint64_t                   , m_nInButtonsWhichAreToggles                     , 0x6B0)
        SCHEMA_FIELD(std::uint32_t                   , m_nTickBase                                     , 0x6B8)
        SCHEMA_FIELD(CHandle<C_BasePlayerPawn>       , m_hPawn                                         , 0x6BC)
        SCHEMA_FIELD(bool                            , m_bKnownTeamMismatch                            , 0x6C0)
        SCHEMA_FIELD(CHandle<C_BasePlayerPawn>       , m_hPredictedPawn                                , 0x6C4)
        SCHEMA_FIELD(CSplitScreenSlot                , m_nSplitScreenSlot                              , 0x6C8)
        SCHEMA_FIELD(CHandle<CBasePlayerController>  , m_hSplitOwner                                   , 0x6CC)
        SCHEMA_FIELD(CUtlVector<CHandle<CBasePlayerController>>, m_hSplitScreenPlayers                           , 0x6D0)
        SCHEMA_FIELD(bool                            , m_bIsHLTV                                       , 0x6E8)
        SCHEMA_FIELD(PlayerConnectedState            , m_iConnected                                    , 0x6EC)
        SCHEMA_FIELD(PlayerConnectedState            , m_iMostConnected                                , 0x6F0)
        SCHEMA_FIELD(char                            , m_iszPlayerName                                 , 0x6F4)
        SCHEMA_FIELD(std::uint64_t                   , m_steamID                                       , 0x780)
        SCHEMA_FIELD(bool                            , m_bIsLocalPlayerController                      , 0x788)
        SCHEMA_FIELD(bool                            , m_bNoClipEnabled                                , 0x789)
        SCHEMA_FIELD(std::uint32_t                   , m_iDesiredFOV                                   , 0x78C)
    };

    class C_CSGO_EndOfMatchLineupEndpoint : public C_BaseEntity {
    public:
    };

    class CCSObserver_UseServices : public CPlayer_UseServices {
    public:
    };

    class CCSPlayer_UseServices : public CPlayer_UseServices {
    public:
    };

    class CCSPlayer_ItemServices : public CPlayer_ItemServices {
    public:
        SCHEMA_FIELD(bool                            , m_bHasDefuser                                   , 0x48)
        SCHEMA_FIELD(bool                            , m_bHasHelmet                                    , 0x49)
    };

    class CCSObserver_ObserverServices : public CPlayer_ObserverServices {
    public:
        SCHEMA_FIELD(ObserverInterpState_t           , m_obsInterpState                                , 0x64)
    };

    class CPlayer_MovementServices_Humanoid : public CPlayer_MovementServices {
    public:
        SCHEMA_FIELD(float                           , m_flStepSoundTime                               , 0x258)
        SCHEMA_FIELD(float                           , m_flFallVelocity                                , 0x25C)
        SCHEMA_FIELD(::Vector                        , m_groundNormal                                  , 0x260)
        SCHEMA_FIELD(float                           , m_flSurfaceFriction                             , 0x26C)
        SCHEMA_FIELD(CUtlStringToken                 , m_surfaceProps                                  , 0x270)
        SCHEMA_FIELD(std::int32_t                    , m_nStepside                                     , 0x280)
    };

    class CCSObserver_MovementServices : public CPlayer_MovementServices {
    public:
    };

    class C_AttributeContainer : public CAttributeManager {
    public:
        SCHEMA_FIELD(C_EconItemView                  , m_Item                                          , 0x50)
        SCHEMA_FIELD(std::int32_t                    , m_iExternalItemProviderRegisteredToken          , 0x4C0)
        SCHEMA_FIELD(std::uint64_t                   , m_ullRegisteredAsItemID                         , 0x4C8)
    };

    class CCSPlayer_WaterServices : public CPlayer_WaterServices {
    public:
        SCHEMA_FIELD(float                           , m_flWaterJumpTime                               , 0x48)
        SCHEMA_FIELD(::Vector                        , m_vecWaterJumpVel                               , 0x4C)
        SCHEMA_FIELD(float                           , m_flSwimSoundTime                               , 0x58)
    };

    class CCSPlayerBase_CameraServices : public CPlayer_CameraServices {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_iFOV                                          , 0x290)
        SCHEMA_FIELD(std::uint32_t                   , m_iFOVStart                                     , 0x294)
        SCHEMA_FIELD(::GameTime_t                    , m_flFOVTime                                     , 0x298)
        SCHEMA_FIELD(float                           , m_flFOVRate                                     , 0x29C)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hZoomOwner                                    , 0x2A0)
        SCHEMA_FIELD(float                           , m_flLastShotFOV                                 , 0x2A4)
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
    };

    class CBodyComponent : public CEntityComponent {
    public:
        SCHEMA_FIELD(CGameSceneNode*                 , m_pSceneNode                                    , 0x8)
        SCHEMA_FIELD(CNetworkVarChainer              , __m_pChainEntity                                , 0x48)
    };

    class C_SoundOpvarSetOBBWindEntity : public C_SoundOpvarSetPointBase {
    public:
    };

    class C_SoundOpvarSetPointEntity : public C_SoundOpvarSetPointBase {
    public:
    };

    class C_CSGameRulesProxy : public C_GameRulesProxy {
    public:
        SCHEMA_FIELD(C_CSGameRules*                  , m_pGameRules                                    , 0x600)
    };

    class C_CSTeam : public C_Team {
    public:
        SCHEMA_FIELD(char                            , m_szTeamMatchStat                               , 0x6B8)
        SCHEMA_FIELD(std::int32_t                    , m_numMapVictories                               , 0x8B8)
        SCHEMA_FIELD(bool                            , m_bSurrendered                                  , 0x8BC)
        SCHEMA_FIELD(std::int32_t                    , m_scoreFirstHalf                                , 0x8C0)
        SCHEMA_FIELD(std::int32_t                    , m_scoreSecondHalf                               , 0x8C4)
        SCHEMA_FIELD(std::int32_t                    , m_scoreOvertime                                 , 0x8C8)
        SCHEMA_FIELD(char                            , m_szClanTeamname                                , 0x8CC)
        SCHEMA_FIELD(std::uint32_t                   , m_iClanID                                       , 0x950)
        SCHEMA_FIELD(char                            , m_szTeamFlagImage                               , 0x954)
        SCHEMA_FIELD(char                            , m_szTeamLogoImage                               , 0x95C)
    };

    class CEnvSoundscapeAlias_snd_soundscape : public CEnvSoundscape {
    public:
    };

    class CEnvSoundscapeProxy : public CEnvSoundscape {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_MainSoundscapeName                            , 0x690)
    };

    class CEnvSoundscapeTriggerable : public CEnvSoundscape {
    public:
    };

    class C_PathParticleRopeAlias_path_particle_rope_clientside : public C_PathParticleRope {
    public:
    };

    class C_TonemapController2Alias_env_tonemap_controller2 : public C_TonemapController2 {
    public:
    };

    class C_SoundAreaEntitySphere : public C_SoundAreaEntityBase {
    public:
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x628)
    };

    class C_SoundAreaEntityOrientedBox : public C_SoundAreaEntityBase {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMin                                          , 0x628)
        SCHEMA_FIELD(::Vector                        , m_vMax                                          , 0x634)
    };

    class C_CSGO_TeamPreviewCamera : public C_CSGO_MapPreviewCameraPath {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nVariant                                      , 0x688)
    };

    class C_FuncRotating : public C_BaseModelEntity {
    public:
    };

    class C_BarnLight : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0xFA8)
        SCHEMA_FIELD(std::int32_t                    , m_nColorMode                                    , 0xFAC)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0xFB0)
        SCHEMA_FIELD(float                           , m_flColorTemperature                            , 0xFB4)
        SCHEMA_FIELD(float                           , m_flBrightness                                  , 0xFB8)
        SCHEMA_FIELD(float                           , m_flBrightnessScale                             , 0xFBC)
        SCHEMA_FIELD(std::int32_t                    , m_nDirectLight                                  , 0xFC0)
        SCHEMA_FIELD(std::int32_t                    , m_nBakedShadowIndex                             , 0xFC4)
        SCHEMA_FIELD(std::int32_t                    , m_nLightPathUniqueId                            , 0xFC8)
        SCHEMA_FIELD(std::int32_t                    , m_nLightMapUniqueId                             , 0xFCC)
        SCHEMA_FIELD(std::int32_t                    , m_nLuminaireShape                               , 0xFD0)
        SCHEMA_FIELD(float                           , m_flLuminaireSize                               , 0xFD4)
        SCHEMA_FIELD(float                           , m_flLuminaireAnisotropy                         , 0xFD8)
        SCHEMA_FIELD(::CUtlString                    , m_LightStyleString                              , 0xFE0)
        SCHEMA_FIELD(::GameTime_t                    , m_flLightStyleStartTime                         , 0xFE8)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CUtlString>, m_QueuedLightStyleStrings                       , 0xFF0)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CUtlString>, m_LightStyleEvents                              , 0x1008)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BaseModelEntity>>, m_LightStyleTargets                             , 0x1020)
        SCHEMA_FIELD(CEntityIOOutput                 , m_StyleEvent                                    , 0x1038)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hLightCookie                                  , 0x1098)
        SCHEMA_FIELD(float                           , m_flShape                                       , 0x10A0)
        SCHEMA_FIELD(float                           , m_flSoftX                                       , 0x10A4)
        SCHEMA_FIELD(float                           , m_flSoftY                                       , 0x10A8)
        SCHEMA_FIELD(float                           , m_flSkirt                                       , 0x10AC)
        SCHEMA_FIELD(float                           , m_flSkirtNear                                   , 0x10B0)
        SCHEMA_FIELD(::Vector                        , m_vSizeParams                                   , 0x10B4)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x10C0)
        SCHEMA_FIELD(::Vector                        , m_vShear                                        , 0x10C4)
        SCHEMA_FIELD(std::int32_t                    , m_nBakeSpecularToCubemaps                       , 0x10D0)
        SCHEMA_FIELD(::Vector                        , m_vBakeSpecularToCubemapsSize                   , 0x10D4)
        SCHEMA_FIELD(float                           , m_flBakeSpecularToCubemapsScale                 , 0x10E0)
        SCHEMA_FIELD(std::int32_t                    , m_nCastShadows                                  , 0x10E4)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowMapSize                                , 0x10E8)
        SCHEMA_FIELD(std::int32_t                    , m_nShadowPriority                               , 0x10EC)
        SCHEMA_FIELD(bool                            , m_bContactShadow                                , 0x10F0)
        SCHEMA_FIELD(bool                            , m_bForceShadowsEnabled                          , 0x10F1)
        SCHEMA_FIELD(std::int32_t                    , m_nBounceLight                                  , 0x10F4)
        SCHEMA_FIELD(float                           , m_flBounceScale                                 , 0x10F8)
        SCHEMA_FIELD(float                           , m_flMinRoughness                                , 0x10FC)
        SCHEMA_FIELD(::Vector                        , m_vAlternateColor                               , 0x1100)
        SCHEMA_FIELD(float                           , m_fAlternateColorBrightness                     , 0x110C)
        SCHEMA_FIELD(std::int32_t                    , m_nFog                                          , 0x1110)
        SCHEMA_FIELD(float                           , m_flFogStrength                                 , 0x1114)
        SCHEMA_FIELD(std::int32_t                    , m_nFogShadows                                   , 0x1118)
        SCHEMA_FIELD(float                           , m_flFogScale                                    , 0x111C)
        SCHEMA_FIELD(float                           , m_flFadeSizeStart                               , 0x1120)
        SCHEMA_FIELD(float                           , m_flFadeSizeEnd                                 , 0x1124)
        SCHEMA_FIELD(float                           , m_flShadowFadeSizeStart                         , 0x1128)
        SCHEMA_FIELD(float                           , m_flShadowFadeSizeEnd                           , 0x112C)
        SCHEMA_FIELD(bool                            , m_bPrecomputedFieldsValid                       , 0x1130)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedBoundsMins                        , 0x1134)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedBoundsMaxs                        , 0x1140)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin                         , 0x114C)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles                         , 0x1158)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent                         , 0x1164)
        SCHEMA_FIELD(std::int32_t                    , m_nPrecomputedSubFrusta                         , 0x1170)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin0                        , 0x1174)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles0                        , 0x1180)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent0                        , 0x118C)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin1                        , 0x1198)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles1                        , 0x11A4)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent1                        , 0x11B0)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin2                        , 0x11BC)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles2                        , 0x11C8)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent2                        , 0x11D4)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin3                        , 0x11E0)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles3                        , 0x11EC)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent3                        , 0x11F8)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin4                        , 0x1204)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles4                        , 0x1210)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent4                        , 0x121C)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBOrigin5                        , 0x1228)
        SCHEMA_FIELD(::QAngle                        , m_vPrecomputedOBBAngles5                        , 0x1234)
        SCHEMA_FIELD(::Vector                        , m_vPrecomputedOBBExtent5                        , 0x1240)
        SCHEMA_FIELD(bool                            , m_bInitialBoneSetup                             , 0x1290)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<uint16>  , m_VisClusters                                   , 0x1298)
    };

    class C_SpotlightEnd : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(float                           , m_flLightScale                                  , 0xFA8)
        SCHEMA_FIELD(float                           , m_Radius                                        , 0xFAC)
    };

    class CFuncWater : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(CBuoyancyHelper                 , m_BuoyancyHelper                                , 0xFA8)
    };

    class C_FuncLadder : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecLadderDir                                  , 0xFA8)
        SCHEMA_FIELD(CUtlVector<CHandle<C_InfoLadderDismount>>, m_Dismounts                                     , 0xFB8)
        SCHEMA_FIELD(::Vector                        , m_vecLocalTop                                   , 0xFD0)
        SCHEMA_FIELD(VectorWS                        , m_vecPlayerMountPositionTop                     , 0xFDC)
        SCHEMA_FIELD(VectorWS                        , m_vecPlayerMountPositionBottom                  , 0xFE8)
        SCHEMA_FIELD(float                           , m_flAutoRideSpeed                               , 0xFF4)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0xFF8)
        SCHEMA_FIELD(bool                            , m_bFakeLadder                                   , 0xFF9)
        SCHEMA_FIELD(bool                            , m_bHasSlack                                     , 0xFFA)
    };

    class C_World : public C_BaseModelEntity {
    public:
    };

    class CCashStack : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nCashStackValue                               , 0xFA8)
    };

    class C_EnvSky : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSkyMaterial                                  , 0xFA8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSkyMaterialLightingOnly                      , 0xFB0)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0xFB8)
        SCHEMA_FIELD(::Color                         , m_vTintColor                                    , 0xFB9)
        SCHEMA_FIELD(::Color                         , m_vTintColorLightingOnly                        , 0xFBD)
        SCHEMA_FIELD(float                           , m_flBrightnessScale                             , 0xFC4)
        SCHEMA_FIELD(std::int32_t                    , m_nFogType                                      , 0xFC8)
        SCHEMA_FIELD(float                           , m_flFogMinStart                                 , 0xFCC)
        SCHEMA_FIELD(float                           , m_flFogMinEnd                                   , 0xFD0)
        SCHEMA_FIELD(float                           , m_flFogMaxStart                                 , 0xFD4)
        SCHEMA_FIELD(float                           , m_flFogMaxEnd                                   , 0xFD8)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0xFDC)
    };

    class C_RopeKeyframe : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(CBitVec<10>                     , m_LinksTouchingSomething                        , 0xFB0)
        SCHEMA_FIELD(std::int32_t                    , m_nLinksTouchingSomething                       , 0xFB4)
        SCHEMA_FIELD(bool                            , m_bApplyWind                                    , 0xFB8)
        SCHEMA_FIELD(std::int32_t                    , m_fPrevLockedPoints                             , 0xFBC)
        SCHEMA_FIELD(std::int32_t                    , m_iForcePointMoveCounter                        , 0xFC0)
        SCHEMA_FIELD(bool                            , m_bPrevEndPointPos                              , 0xFC4)
        SCHEMA_FIELD(VectorWS                        , m_vPrevEndPointPos                              , 0xFC8)
        SCHEMA_FIELD(float                           , m_flCurScroll                                   , 0xFE0)
        SCHEMA_FIELD(float                           , m_flScrollSpeed                                 , 0xFE4)
        SCHEMA_FIELD(std::uint16_t                   , m_RopeFlags                                     , 0xFE8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_iRopeMaterialModelIndex                       , 0xFF0)
        SCHEMA_FIELD(std::uint8_t                    , m_nSegments                                     , 0x1268)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hStartPoint                                   , 0x126C)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hEndPoint                                     , 0x1270)
        SCHEMA_FIELD(AttachmentHandle_t              , m_iStartAttachment                              , 0x1274)
        SCHEMA_FIELD(AttachmentHandle_t              , m_iEndAttachment                                , 0x1275)
        SCHEMA_FIELD(std::uint8_t                    , m_Subdiv                                        , 0x1276)
        SCHEMA_FIELD(std::int16_t                    , m_RopeLength                                    , 0x1278)
        SCHEMA_FIELD(std::int16_t                    , m_Slack                                         , 0x127A)
        SCHEMA_FIELD(float                           , m_TextureScale                                  , 0x127C)
        SCHEMA_FIELD(std::uint8_t                    , m_fLockedPoints                                 , 0x1280)
        SCHEMA_FIELD(std::uint8_t                    , m_nChangeCount                                  , 0x1281)
        SCHEMA_FIELD(float                           , m_Width                                         , 0x1284)
        SCHEMA_FIELD(C_RopeKeyframe_CPhysicsDelegate , m_PhysicsDelegate                               , 0x1288)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hMaterial                                     , 0x1298)
        SCHEMA_FIELD(std::int32_t                    , m_TextureHeight                                 , 0x12A0)
        SCHEMA_FIELD(::Vector                        , m_vecImpulse                                    , 0x12A4)
        SCHEMA_FIELD(::Vector                        , m_vecPreviousImpulse                            , 0x12B0)
        SCHEMA_FIELD(float                           , m_flCurrentGustTimer                            , 0x12BC)
        SCHEMA_FIELD(float                           , m_flCurrentGustLifetime                         , 0x12C0)
        SCHEMA_FIELD(float                           , m_flTimeToNextGust                              , 0x12C4)
        SCHEMA_FIELD(::Vector                        , m_vWindDir                                      , 0x12C8)
        SCHEMA_FIELD(::Vector                        , m_vColorMod                                     , 0x12D4)
        SCHEMA_FIELD(VectorWS                        , m_vCachedEndPointAttachmentPos                  , 0x12E0)
        SCHEMA_FIELD(::QAngle                        , m_vCachedEndPointAttachmentAngle                , 0x12F8)
        SCHEMA_FIELD(bool                            , m_bConstrainBetweenEndpoints                    , 0x1310)

    };

    class C_BaseToggle : public C_BaseModelEntity {
    public:
    };

    class CServerOnlyModelEntity : public C_BaseModelEntity {
    public:
    };

    class C_BaseClientUIEntity : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0xFB0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_DialogXMLName                                 , 0xFB8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_PanelClassName                                , 0xFC0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_PanelID                                       , 0xFC8)
    };

    class CWaterSplasher : public C_BaseModelEntity {
    public:
    };

    class C_FuncBrush : public C_BaseModelEntity {
    public:
    };

    class C_DynamicLight : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_Flags                                         , 0xFA8)
        SCHEMA_FIELD(std::uint8_t                    , m_LightStyle                                    , 0xFA9)
        SCHEMA_FIELD(float                           , m_Radius                                        , 0xFAC)
        SCHEMA_FIELD(std::int32_t                    , m_Exponent                                      , 0xFB0)
        SCHEMA_FIELD(float                           , m_InnerAngle                                    , 0xFB4)
        SCHEMA_FIELD(float                           , m_OuterAngle                                    , 0xFB8)
        SCHEMA_FIELD(float                           , m_SpotRadius                                    , 0xFBC)
    };

    class C_Inferno : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(ParticleIndex_t                 , m_nfxFireDamageEffect                           , 0xFE8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSnapshot>, m_hInfernoPointsSnapshot                        , 0xFF0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSnapshot>, m_hInfernoFillerPointsSnapshot                  , 0xFF8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSnapshot>, m_hInfernoOutlinePointsSnapshot                 , 0x1000)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSnapshot>, m_hInfernoClimbingOutlinePointsSnapshot         , 0x1008)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSnapshot>, m_hInfernoDecalsSnapshot                        , 0x1010)
        SCHEMA_FIELD(::Vector                        , m_firePositions                                 , 0x1018)
        SCHEMA_FIELD(::Vector                        , m_fireParentPositions                           , 0x1318)
        SCHEMA_FIELD(bool                            , m_bFireIsBurning                                , 0x1618)
        SCHEMA_FIELD(::Vector                        , m_BurnNormal                                    , 0x1658)
        SCHEMA_FIELD(std::int32_t                    , m_fireCount                                     , 0x1958)
        SCHEMA_FIELD(std::int32_t                    , m_nInfernoType                                  , 0x195C)
        SCHEMA_FIELD(float                           , m_nFireLifetime                                 , 0x1960)
        SCHEMA_FIELD(bool                            , m_bInPostEffectTime                             , 0x1964)
        SCHEMA_FIELD(std::int32_t                    , m_lastFireCount                                 , 0x1968)
        SCHEMA_FIELD(std::int32_t                    , m_nFireEffectTickBegin                          , 0x196C)
        SCHEMA_FIELD(std::int32_t                    , m_drawableCount                                 , 0x8570)
        SCHEMA_FIELD(bool                            , m_blosCheck                                     , 0x8574)
        SCHEMA_FIELD(std::int32_t                    , m_nlosperiod                                    , 0x8578)
        SCHEMA_FIELD(float                           , m_maxFireHalfWidth                              , 0x857C)
        SCHEMA_FIELD(float                           , m_maxFireHeight                                 , 0x8580)
        SCHEMA_FIELD(::Vector                        , m_minBounds                                     , 0x8584)
        SCHEMA_FIELD(::Vector                        , m_maxBounds                                     , 0x8590)
        SCHEMA_FIELD(float                           , m_flLastGrassBurnThink                          , 0x859C)
    };

    class C_EntityDissolve : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0xFB0)
        SCHEMA_FIELD(float                           , m_flFadeInStart                                 , 0xFB4)
        SCHEMA_FIELD(float                           , m_flFadeInLength                                , 0xFB8)
        SCHEMA_FIELD(float                           , m_flFadeOutModelStart                           , 0xFBC)
        SCHEMA_FIELD(float                           , m_flFadeOutModelLength                          , 0xFC0)
        SCHEMA_FIELD(float                           , m_flFadeOutStart                                , 0xFC4)
        SCHEMA_FIELD(float                           , m_flFadeOutLength                               , 0xFC8)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextSparkTime                               , 0xFCC)
        SCHEMA_FIELD(EntityDisolveType_t             , m_nDissolveType                                 , 0xFD0)
        SCHEMA_FIELD(::Vector                        , m_vDissolverOrigin                              , 0xFD4)
        SCHEMA_FIELD(std::uint32_t                   , m_nMagnitude                                    , 0xFE0)
        SCHEMA_FIELD(bool                            , m_bCoreExplode                                  , 0xFE4)
        SCHEMA_FIELD(bool                            , m_bLinkedToServerEnt                            , 0xFE5)
    };

    class C_TextureBasedAnimatable : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bLoop                                         , 0xFA8)
        SCHEMA_FIELD(float                           , m_flFPS                                         , 0xFAC)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hPositionKeys                                 , 0xFB0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hRotationKeys                                 , 0xFB8)
        SCHEMA_FIELD(::Vector                        , m_vAnimationBoundsMin                           , 0xFC0)
        SCHEMA_FIELD(::Vector                        , m_vAnimationBoundsMax                           , 0xFCC)
        SCHEMA_FIELD(float                           , m_flStartTime                                   , 0xFD8)
        SCHEMA_FIELD(float                           , m_flStartFrame                                  , 0xFDC)
    };

    class C_ParticleSystem : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(char                            , m_szSnapshotFileName                            , 0xFA8)
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x11A8)
        SCHEMA_FIELD(bool                            , m_bFrozen                                       , 0x11A9)
        SCHEMA_FIELD(float                           , m_flFreezeTransitionDuration                    , 0x11AC)
        SCHEMA_FIELD(std::int32_t                    , m_nStopType                                     , 0x11B0)
        SCHEMA_FIELD(bool                            , m_bAnimateDuringGameplayPause                   , 0x11B4)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_iEffectIndex                                  , 0x11B8)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x11C0)
        SCHEMA_FIELD(float                           , m_flPreSimTime                                  , 0x11C4)
        SCHEMA_FIELD(::Vector                        , m_vServerControlPoints                          , 0x11C8)
        SCHEMA_FIELD(std::uint8_t                    , m_iServerControlPointAssignments                , 0x11F8)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hControlPointEnts                             , 0x11FC)
        SCHEMA_FIELD(bool                            , m_bNoSave                                       , 0x12FC)
        SCHEMA_FIELD(bool                            , m_bNoFreeze                                     , 0x12FD)
        SCHEMA_FIELD(bool                            , m_bNoRamp                                       , 0x12FE)
        SCHEMA_FIELD(bool                            , m_bStartActive                                  , 0x12FF)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEffectName                                 , 0x1300)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszControlPointNames                          , 0x1308)
        SCHEMA_FIELD(std::int32_t                    , m_nDataCP                                       , 0x1508)
        SCHEMA_FIELD(::Vector                        , m_vecDataCPValue                                , 0x150C)
        SCHEMA_FIELD(std::int32_t                    , m_nTintCP                                       , 0x1518)
        SCHEMA_FIELD(::Color                         , m_clrTint                                       , 0x151C)
        SCHEMA_FIELD(bool                            , m_bOldActive                                    , 0x1540)
        SCHEMA_FIELD(bool                            , m_bOldFrozen                                    , 0x1541)
    };

    class CGrenadeTracer : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(float                           , m_flTracerDuration                              , 0xFC0)
        SCHEMA_FIELD(GrenadeType_t                   , m_nType                                         , 0xFC4)
    };

    class C_ModelPointEntity : public C_BaseModelEntity {
    public:
    };

    class C_FuncTrackTrain : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nLongAxis                                     , 0xFA8)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0xFAC)
        SCHEMA_FIELD(float                           , m_flLineLength                                  , 0xFB0)
    };

    class C_EnvDecal : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hDecalMaterial                                , 0xFA8)
        SCHEMA_FIELD(float                           , m_flWidth                                       , 0xFB0)
        SCHEMA_FIELD(float                           , m_flHeight                                      , 0xFB4)
        SCHEMA_FIELD(float                           , m_flDepth                                       , 0xFB8)
        SCHEMA_FIELD(std::uint32_t                   , m_nRenderOrder                                  , 0xFBC)
        SCHEMA_FIELD(bool                            , m_bProjectOnWorld                               , 0xFC0)
        SCHEMA_FIELD(bool                            , m_bProjectOnCharacters                          , 0xFC1)
        SCHEMA_FIELD(bool                            , m_bProjectOnWater                               , 0xFC2)
        SCHEMA_FIELD(float                           , m_flDepthSortBias                               , 0xFC4)
    };

    class C_Beam : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(float                           , m_flFrameRate                                   , 0xFA8)
        SCHEMA_FIELD(float                           , m_flHDRColorScale                               , 0xFAC)
        SCHEMA_FIELD(::GameTime_t                    , m_flFireTime                                    , 0xFB0)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0xFB4)
        SCHEMA_FIELD(std::uint8_t                    , m_nNumBeamEnts                                  , 0xFB8)
        SCHEMA_FIELD(std::int32_t                    , m_queryHandleHalo                               , 0xFBC)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hBaseMaterial                                 , 0xFE0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_nHaloIndex                                    , 0xFE8)
        SCHEMA_FIELD(BeamType_t                      , m_nBeamType                                     , 0xFF0)
        SCHEMA_FIELD(std::uint32_t                   , m_nBeamFlags                                    , 0xFF4)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hAttachEntity                                 , 0xFF8)
        SCHEMA_FIELD(AttachmentHandle_t              , m_nAttachIndex                                  , 0x1020)
        SCHEMA_FIELD(float                           , m_fWidth                                        , 0x102C)
        SCHEMA_FIELD(float                           , m_fEndWidth                                     , 0x1030)
        SCHEMA_FIELD(float                           , m_fFadeLength                                   , 0x1034)
        SCHEMA_FIELD(float                           , m_fHaloScale                                    , 0x1038)
        SCHEMA_FIELD(float                           , m_fAmplitude                                    , 0x103C)
        SCHEMA_FIELD(float                           , m_fStartFrame                                   , 0x1040)
        SCHEMA_FIELD(float                           , m_fSpeed                                        , 0x1044)
        SCHEMA_FIELD(float                           , m_flFrame                                       , 0x1048)
        SCHEMA_FIELD(BeamClipStyle_t                 , m_nClipStyle                                    , 0x104C)
        SCHEMA_FIELD(bool                            , m_bTurnedOff                                    , 0x1050)
        SCHEMA_FIELD(VectorWS                        , m_vecEndPos                                     , 0x1054)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hEndEntity                                    , 0x1060)
    };

    class C_FuncConveyor : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vecMoveDirEntitySpace                         , 0xFB0)
        SCHEMA_FIELD(float                           , m_flTargetSpeed                                 , 0xFBC)
        SCHEMA_FIELD(::GameTick_t                    , m_nTransitionStartTick                          , 0xFC0)
        SCHEMA_FIELD(std::int32_t                    , m_nTransitionDurationTicks                      , 0xFC4)
        SCHEMA_FIELD(float                           , m_flTransitionStartSpeed                        , 0xFC8)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BaseEntity>>, m_hConveyorModels                               , 0xFD0)
        SCHEMA_FIELD(float                           , m_flCurrentConveyorOffset                       , 0xFE8)
        SCHEMA_FIELD(float                           , m_flCurrentConveyorSpeed                        , 0xFEC)
    };

    class C_Breakable : public C_BaseModelEntity {
    public:
    };

    class CBaseAnimGraph : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(CAnimGraphControllerManager     , m_graphControllerManager                        , 0xFA8)
        SCHEMA_FIELD(CAnimGraphControllerBase*       , m_pMainGraphController                          , 0x1058)
        SCHEMA_FIELD(bool                            , m_bInitiallyPopulateInterpHistory               , 0x1060)
        SCHEMA_FIELD(bool                            , m_bSuppressAnimEventSounds                      , 0x1062)
        SCHEMA_FIELD(bool                            , m_bAnimGraphUpdateEnabled                       , 0x1070)
        SCHEMA_FIELD(bool                            , m_bAnimationUpdateScheduled                     , 0x1071)
        SCHEMA_FIELD(::Vector                        , m_vecForce                                      , 0x1074)
        SCHEMA_FIELD(std::int32_t                    , m_nForceBone                                    , 0x1080)
        SCHEMA_FIELD(CBaseAnimGraph*                 , m_pClientsideRagdoll                            , 0x1088)
        SCHEMA_FIELD(bool                            , m_bBuiltRagdoll                                 , 0x1090)
        SCHEMA_FIELD(IPhysicsRagdollControl*         , m_pRagdollControl                               , 0x10A0)
        SCHEMA_FIELD(PhysicsRagdollPose_t            , m_RagdollPose                                   , 0x10A8)
        SCHEMA_FIELD(bool                            , m_bRagdollEnabled                               , 0x10F0)
        SCHEMA_FIELD(bool                            , m_bRagdollClientSide                            , 0x10F1)
        SCHEMA_FIELD(bool                            , m_bHasAnimatedMaterialAttributes                , 0x1100)
    };

    class C_LightEntity : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(CLightComponent*                , m_CLightComponent                               , 0xFA8)
    };

    class C_PrecipitationBlocker : public C_BaseModelEntity {
    public:
    };

    class C_TriggerVolume : public C_BaseModelEntity {
    public:
    };

    class C_Sprite : public C_BaseModelEntity {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIMaterial2>, m_hSpriteMaterial                               , 0xFA8)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hAttachedToEntity                             , 0xFB0)
        SCHEMA_FIELD(AttachmentHandle_t              , m_nAttachment                                   , 0xFB4)
        SCHEMA_FIELD(float                           , m_flSpriteFramerate                             , 0xFB8)
        SCHEMA_FIELD(float                           , m_flFrame                                       , 0xFBC)
        SCHEMA_FIELD(::GameTime_t                    , m_flDieTime                                     , 0xFC0)
        SCHEMA_FIELD(std::uint32_t                   , m_nBrightness                                   , 0xFD0)
        SCHEMA_FIELD(float                           , m_flBrightnessDuration                          , 0xFD4)
        SCHEMA_FIELD(float                           , m_flSpriteScale                                 , 0xFD8)
        SCHEMA_FIELD(float                           , m_flScaleDuration                               , 0xFDC)
        SCHEMA_FIELD(bool                            , m_bWorldSpaceScale                              , 0xFE0)
        SCHEMA_FIELD(float                           , m_flGlowProxySize                               , 0xFE4)
        SCHEMA_FIELD(float                           , m_flHDRColorScale                               , 0xFE8)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastTime                                    , 0xFEC)
        SCHEMA_FIELD(float                           , m_flMaxFrame                                    , 0xFF0)
        SCHEMA_FIELD(float                           , m_flStartScale                                  , 0xFF4)
        SCHEMA_FIELD(float                           , m_flDestScale                                   , 0xFF8)
        SCHEMA_FIELD(::GameTime_t                    , m_flScaleTimeStart                              , 0xFFC)
        SCHEMA_FIELD(std::int32_t                    , m_nStartBrightness                              , 0x1000)
        SCHEMA_FIELD(std::int32_t                    , m_nDestBrightness                               , 0x1004)
        SCHEMA_FIELD(::GameTime_t                    , m_flBrightnessTimeStart                         , 0x1008)
        SCHEMA_FIELD(std::int32_t                    , m_nSpriteWidth                                  , 0x1018)
        SCHEMA_FIELD(std::int32_t                    , m_nSpriteHeight                                 , 0x101C)
    };

    class C_EnvCombinedLightProbeVolumeAlias_func_combined_light_probe_volume : public C_EnvCombinedLightProbeVolume {
    public:
    };

    class C_SoundEventEntityAlias_snd_event_point : public C_SoundEventEntity {
    public:
    };

    class C_SoundEventPathCornerEntity : public C_SoundEventEntity {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<SoundeventPathCornerPairNetworked_t>, m_vecCornerPairsNetworked                       , 0x6C0)
    };

    class C_SoundEventOBBEntity : public C_SoundEventEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMins                                         , 0x6C0)
        SCHEMA_FIELD(::Vector                        , m_vMaxs                                         , 0x6CC)
    };

    class C_SoundEventAABBEntity : public C_SoundEventEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMins                                         , 0x6C0)
        SCHEMA_FIELD(::Vector                        , m_vMaxs                                         , 0x6CC)
    };

    class C_SoundEventSphereEntity : public C_SoundEventEntity {
    public:
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x6C0)
    };

    class C_SoundEventConeEntity : public C_SoundEventEntity {
    public:
        SCHEMA_FIELD(float                           , m_flEmitterAngle                                , 0x6C0)
        SCHEMA_FIELD(float                           , m_flSweetSpotAngle                              , 0x6C4)
        SCHEMA_FIELD(float                           , m_flAttenMin                                    , 0x6C8)
        SCHEMA_FIELD(float                           , m_flAttenMax                                    , 0x6CC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszParameterName                              , 0x6D0)
    };

    class C_CSGO_TeamIntroCharacterPosition : public C_CSGO_TeamPreviewCharacterPosition {
    public:
    };

    class C_CSGO_EndOfMatchCharacterPosition : public C_CSGO_TeamPreviewCharacterPosition {
    public:
    };

    class C_CSGO_TeamSelectCharacterPosition : public C_CSGO_TeamPreviewCharacterPosition {
    public:
    };

    class C_EnvCubemapBox : public C_EnvCubemap {
    public:
    };

    class CPathWithDynamicNodes : public CPathSimple {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<CPathNode>>, m_vecPathNodes                                  , 0x710)
        SCHEMA_FIELD(CTransform                      , m_xInitialPathWorldToLocal                      , 0x730)
    };

    class CInfoFan : public C_PointEntity {
    public:
        SCHEMA_FIELD(float                           , m_fFanForceMaxRadius                            , 0x640)
        SCHEMA_FIELD(float                           , m_fFanForceMinRadius                            , 0x644)
        SCHEMA_FIELD(float                           , m_flCurveDistRange                              , 0x648)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_FanForceCurveString                           , 0x650)
    };

    class CPointChildModifier : public C_PointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bOrphanInsteadOfDeletingChildrenOnRemove      , 0x600)
    };

    class CInfoDynamicShadowHint : public C_PointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x600)
        SCHEMA_FIELD(float                           , m_flRange                                       , 0x604)
        SCHEMA_FIELD(std::int32_t                    , m_nImportance                                   , 0x608)
        SCHEMA_FIELD(std::int32_t                    , m_nLightChoice                                  , 0x60C)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hLight                                        , 0x610)
    };

    class CPathNode : public C_PointEntity {
    public:
        SCHEMA_FIELD(::Vector                        , m_vInTangentLocal                               , 0x600)
        SCHEMA_FIELD(::Vector                        , m_vOutTangentLocal                              , 0x60C)
        SCHEMA_FIELD(::CUtlString                    , m_strParentPathUniqueID                         , 0x618)
        SCHEMA_FIELD(::CUtlString                    , m_strPathNodeParameter                          , 0x620)
        SCHEMA_FIELD(CTransform                      , m_xWSPrevParent                                 , 0x630)
        SCHEMA_FIELD(CHandle<CPathWithDynamicNodes>  , m_hPath                                         , 0x650)
    };

    class CChoreoInfoTarget : public C_PointEntity {
    public:
    };

    class CInfoOffscreenPanoramaTexture : public C_PointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x600)
        SCHEMA_FIELD(std::int32_t                    , m_nResolutionX                                  , 0x604)
        SCHEMA_FIELD(std::int32_t                    , m_nResolutionY                                  , 0x608)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szPanelType                                   , 0x610)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szLayoutFileName                              , 0x618)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_RenderAttrName                                , 0x620)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BaseModelEntity>>, m_TargetEntities                                , 0x628)
        SCHEMA_FIELD(std::int32_t                    , m_nTargetChangeCount                            , 0x640)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CUtlSymbolLarge>, m_vecCSSClasses                                 , 0x648)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szTargetsName                                 , 0x660)
        SCHEMA_FIELD(CUtlVector<CHandle<C_BaseModelEntity>>, m_AdditionalTargetEntities                      , 0x668)
        SCHEMA_FIELD(bool                            , m_bCheckCSSClasses                              , 0x7E0)
    };

    class CInfoTarget : public C_PointEntity {
    public:
    };

    class C_InfoInstructorHintHostageRescueZone : public C_PointEntity {
    public:
    };

    class C_SceneEntity : public C_PointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bIsPlayingBack                                , 0x608)
        SCHEMA_FIELD(bool                            , m_bPaused                                       , 0x609)
        SCHEMA_FIELD(bool                            , m_bMultiplayer                                  , 0x60A)
        SCHEMA_FIELD(bool                            , m_bAutogenerated                                , 0x60B)
        SCHEMA_FIELD(bool                            , m_bAllRequirementsComplete                      , 0x60C)
        SCHEMA_FIELD(float                           , m_flForceClientTime                             , 0x610)
        SCHEMA_FIELD(std::uint16_t                   , m_nSceneStringIndex                             , 0x614)
        SCHEMA_FIELD(bool                            , m_bClientOnly                                   , 0x616)
        SCHEMA_FIELD(CHandle<C_BaseModelEntity>      , m_hOwner                                        , 0x618)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_BaseModelEntity>>, m_hActorList                                    , 0x620)
        SCHEMA_FIELD(bool                            , m_bWasPlaying                                   , 0x638)
        SCHEMA_FIELD(CUtlVector<C_SceneEntity_QueuedEvents_t>, m_QueuedEvents                                  , 0x648)
        SCHEMA_FIELD(float                           , m_flCurrentTime                                 , 0x660)
    };

    class CMapInfo : public C_PointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iBuyingStatus                                 , 0x600)
        SCHEMA_FIELD(float                           , m_flBombRadius                                  , 0x604)
        SCHEMA_FIELD(std::int32_t                    , m_iPetPopulation                                , 0x608)
        SCHEMA_FIELD(bool                            , m_bUseNormalSpawnsForDM                         , 0x60C)
        SCHEMA_FIELD(bool                            , m_bDisableAutoGeneratedDMSpawns                 , 0x60D)
        SCHEMA_FIELD(float                           , m_flBotMaxVisionDistance                        , 0x610)
        SCHEMA_FIELD(std::int32_t                    , m_iHostageCount                                 , 0x614)
        SCHEMA_FIELD(bool                            , m_bFadePlayerVisibilityFarZ                     , 0x618)
        SCHEMA_FIELD(bool                            , m_bRainTraceToSkyEnabled                        , 0x619)
        SCHEMA_FIELD(bool                            , m_bGPUCullSkybox                                , 0x61A)
        SCHEMA_FIELD(float                           , m_flEnvRainStrength                             , 0x61C)
        SCHEMA_FIELD(float                           , m_flEnvPuddleRippleStrength                     , 0x620)
        SCHEMA_FIELD(float                           , m_flEnvPuddleRippleDirection                    , 0x624)
        SCHEMA_FIELD(float                           , m_flEnvWetnessCoverage                          , 0x628)
        SCHEMA_FIELD(float                           , m_flEnvWetnessDryingAmount                      , 0x62C)
    };

    class CInfoInteraction : public C_PointEntity {
    public:
        SCHEMA_FIELD(SceneRequestHandle_t            , m_hSceneRequest                                 , 0x600)
        SCHEMA_FIELD(SceneOpportunityHandle_t        , m_hSceneOpportunity                             , 0x604)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x608)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x609)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strSceneVDataName                             , 0x610)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strPulseVDataName                             , 0x618)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x640)
        SCHEMA_FIELD(float                           , m_flOwnerFOV                                    , 0x644)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strLocalInterestReqTags                       , 0x648)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strLocalInterestOptTags                       , 0x650)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_strLookTarget                                 , 0x658)
        SCHEMA_FIELD(float                           , m_flDuration                                    , 0x660)
        SCHEMA_FIELD(float                           , m_flCooldown                                    , 0x664)
        SCHEMA_FIELD(std::int32_t                    , m_nRepeatCount                                  , 0x668)
        SCHEMA_FIELD(bool                            , m_bDisableOnExit                                , 0x66C)
    };

    class CInfoParticleTarget : public C_PointEntity {
    public:
    };

    class CLogicRelay : public CLogicalEntity {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnSpawn                                       , 0x600)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTrigger                                     , 0x618)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x630)
        SCHEMA_FIELD(bool                            , m_bWaitForRefire                                , 0x631)
        SCHEMA_FIELD(bool                            , m_bTriggerOnce                                  , 0x632)
        SCHEMA_FIELD(bool                            , m_bFastRetrigger                                , 0x633)
        SCHEMA_FIELD(bool                            , m_bPassthoughCaller                             , 0x634)
    };

    class CPointTemplate : public CLogicalEntity {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszWorldName                                  , 0x600)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSource2EntityLumpName                      , 0x608)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszEntityFilterName                           , 0x610)
        SCHEMA_FIELD(float                           , m_flTimeoutInterval                             , 0x618)
        SCHEMA_FIELD(bool                            , m_bAsynchronouslySpawnEntities                  , 0x61C)
        SCHEMA_FIELD(PointTemplateClientOnlyEntityBehavior_t, m_clientOnlyEntityBehavior                      , 0x620)
        SCHEMA_FIELD(PointTemplateOwnerSpawnGroupType_t, m_ownerSpawnGroupType                           , 0x624)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_createdSpawnGroupHandles                      , 0x628)
        SCHEMA_FIELD(CUtlVector<CEntityHandle>       , m_SpawnedEntityHandles                          , 0x640)
        SCHEMA_FIELD(HSCRIPT                         , m_ScriptSpawnCallback                           , 0x658)
        SCHEMA_FIELD(HSCRIPT                         , m_ScriptCallbackScope                           , 0x660)
        SCHEMA_FIELD(CEntityOutputTemplate<CUtlVector<CEntityHandle>>, m_OnEntitySpawned                               , 0x668)
    };

    class CBaseFilter : public CLogicalEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bNegated                                      , 0x600)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPass                                        , 0x608)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnFail                                        , 0x620)
    };

    class C_PointCameraVFOV : public C_PointCamera {
    public:
        SCHEMA_FIELD(float                           , m_flVerticalFOV                                 , 0x660)
    };

    class CCSPlayerController : public CBasePlayerController {
    public:
        SCHEMA_FIELD(CCSPlayerController_InGameMoneyServices*, m_pInGameMoneyServices                          , 0x808)
        SCHEMA_FIELD(CCSPlayerController_InventoryServices*, m_pInventoryServices                            , 0x810)
        SCHEMA_FIELD(CCSPlayerController_ActionTrackingServices*, m_pActionTrackingServices                       , 0x818)
        SCHEMA_FIELD(CCSPlayerController_DamageServices*, m_pDamageServices                               , 0x820)
        SCHEMA_FIELD(std::uint32_t                   , m_iPing                                         , 0x828)
        SCHEMA_FIELD(bool                            , m_bHasCommunicationAbuseMute                    , 0x82C)
        SCHEMA_FIELD(std::uint32_t                   , m_uiCommunicationMuteFlags                      , 0x830)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szCrosshairCodes                              , 0x838)
        SCHEMA_FIELD(std::uint8_t                    , m_iPendingTeamNum                               , 0x840)
        SCHEMA_FIELD(::GameTime_t                    , m_flForceTeamTime                               , 0x844)
        SCHEMA_FIELD(std::int32_t                    , m_iCompTeammateColor                            , 0x848)
        SCHEMA_FIELD(bool                            , m_bEverPlayedOnTeam                             , 0x84C)
        SCHEMA_FIELD(::GameTime_t                    , m_flPreviousForceJoinTeamTime                   , 0x850)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szClan                                        , 0x858)
        SCHEMA_FIELD(::CUtlString                    , m_sSanitizedPlayerName                          , 0x860)
        SCHEMA_FIELD(std::int32_t                    , m_iCoachingTeam                                 , 0x868)
        SCHEMA_FIELD(std::uint64_t                   , m_nPlayerDominated                              , 0x870)
        SCHEMA_FIELD(std::uint64_t                   , m_nPlayerDominatingMe                           , 0x878)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRanking                           , 0x880)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveWins                              , 0x884)
        SCHEMA_FIELD(std::int8_t                     , m_iCompetitiveRankType                          , 0x888)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRankingPredicted_Win              , 0x88C)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRankingPredicted_Loss             , 0x890)
        SCHEMA_FIELD(std::int32_t                    , m_iCompetitiveRankingPredicted_Tie              , 0x894)
        SCHEMA_FIELD(std::int32_t                    , m_nEndMatchNextMapVote                          , 0x898)
        SCHEMA_FIELD(std::uint16_t                   , m_unActiveQuestId                               , 0x89C)
        SCHEMA_FIELD(std::uint32_t                   , m_rtActiveMissionPeriod                         , 0x8A0)
        SCHEMA_FIELD(QuestProgress_Reason            , m_nQuestProgressReason                          , 0x8A4)
        SCHEMA_FIELD(std::uint32_t                   , m_unPlayerTvControlFlags                        , 0x8A8)
        SCHEMA_FIELD(std::int32_t                    , m_iDraftIndex                                   , 0x8D8)
        SCHEMA_FIELD(std::uint32_t                   , m_msQueuedModeDisconnectionTimestamp            , 0x8DC)
        SCHEMA_FIELD(std::uint32_t                   , m_uiAbandonRecordedReason                       , 0x8E0)
        SCHEMA_FIELD(std::uint32_t                   , m_eNetworkDisconnectionReason                   , 0x8E4)
        SCHEMA_FIELD(bool                            , m_bCannotBeKicked                               , 0x8E8)
        SCHEMA_FIELD(bool                            , m_bEverFullyConnected                           , 0x8E9)
        SCHEMA_FIELD(bool                            , m_bAbandonAllowsSurrender                       , 0x8EA)
        SCHEMA_FIELD(bool                            , m_bAbandonOffersInstantSurrender                , 0x8EB)
        SCHEMA_FIELD(bool                            , m_bDisconnection1MinWarningPrinted              , 0x8EC)
        SCHEMA_FIELD(bool                            , m_bScoreReported                                , 0x8ED)
        SCHEMA_FIELD(std::int32_t                    , m_nDisconnectionTick                            , 0x8F0)
        SCHEMA_FIELD(bool                            , m_bControllingBot                               , 0x900)
        SCHEMA_FIELD(bool                            , m_bHasControlledBotThisRound                    , 0x901)
        SCHEMA_FIELD(bool                            , m_bHasBeenControlledByPlayerThisRound           , 0x902)
        SCHEMA_FIELD(std::int32_t                    , m_nBotsControlledThisRound                      , 0x904)
        SCHEMA_FIELD(bool                            , m_bCanControlObservedBot                        , 0x908)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hPlayerPawn                                   , 0x90C)
        SCHEMA_FIELD(CHandle<C_CSObserverPawn>       , m_hObserverPawn                                 , 0x910)
        SCHEMA_FIELD(bool                            , m_bPawnIsAlive                                  , 0x914)
        SCHEMA_FIELD(std::uint32_t                   , m_iPawnHealth                                   , 0x918)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnArmor                                    , 0x91C)
        SCHEMA_FIELD(bool                            , m_bPawnHasDefuser                               , 0x920)
        SCHEMA_FIELD(bool                            , m_bPawnHasHelmet                                , 0x921)
        SCHEMA_FIELD(std::uint16_t                   , m_nPawnCharacterDefIndex                        , 0x922)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnLifetimeStart                            , 0x924)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnLifetimeEnd                              , 0x928)
        SCHEMA_FIELD(std::int32_t                    , m_iPawnBotDifficulty                            , 0x92C)
        SCHEMA_FIELD(CHandle<CCSPlayerController>    , m_hOriginalControllerOfCurrentPawn              , 0x930)
        SCHEMA_FIELD(std::int32_t                    , m_iScore                                        , 0x934)
        SCHEMA_FIELD(std::uint8_t                    , m_recentKillQueue                               , 0x938)
        SCHEMA_FIELD(std::uint8_t                    , m_nFirstKill                                    , 0x940)
        SCHEMA_FIELD(std::uint8_t                    , m_nKillCount                                    , 0x941)
        SCHEMA_FIELD(bool                            , m_bMvpNoMusic                                   , 0x942)
        SCHEMA_FIELD(std::int32_t                    , m_eMvpReason                                    , 0x944)
        SCHEMA_FIELD(std::int32_t                    , m_iMusicKitID                                   , 0x948)
        SCHEMA_FIELD(std::int32_t                    , m_iMusicKitMVPs                                 , 0x94C)
        SCHEMA_FIELD(std::int32_t                    , m_iMVPs                                         , 0x950)
        SCHEMA_FIELD(bool                            , m_bIsPlayerNameDirty                            , 0x954)
        SCHEMA_FIELD(bool                            , m_bFireBulletsSeedSynchronized                  , 0x955)
    };

    class CCSGO_EndOfMatchLineupEnd : public C_CSGO_EndOfMatchLineupEndpoint {
    public:
    };

    class C_CSGO_EndOfMatchLineupStart : public C_CSGO_EndOfMatchLineupEndpoint {
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
        SCHEMA_FIELD(::GameTime_t                    , m_fStashGrenadeParameterWhen                    , 0x684)
        SCHEMA_FIELD(std::uint64_t                   , m_nButtonDownMaskPrev                           , 0x688)
        SCHEMA_FIELD(bool                            , m_bUseFrictionStashedSpeed                      , 0x690)
        SCHEMA_FIELD(float                           , m_flUseFrictionStashedSpeedUntilFrac            , 0x694)
        SCHEMA_FIELD(float                           , m_flFrictionStashedSpeed                        , 0x698)
        SCHEMA_FIELD(float                           , m_flStamina                                     , 0x69C)
        SCHEMA_FIELD(float                           , m_flHeightAtJumpStart                           , 0x6A0)
        SCHEMA_FIELD(float                           , m_flMaxJumpHeightThisJump                       , 0x6A4)
        SCHEMA_FIELD(float                           , m_flMaxJumpHeightLastJump                       , 0x6A8)
        SCHEMA_FIELD(float                           , m_flStaminaAtJumpStart                          , 0x6AC)
        SCHEMA_FIELD(float                           , m_flVelMulAtJumpStart                           , 0x6B0)
        SCHEMA_FIELD(float                           , m_flAccumulatedJumpError                        , 0x6B4)
        SCHEMA_FIELD(CCSPlayerLegacyJump             , m_LegacyJump                                    , 0x6B8)
        SCHEMA_FIELD(CCSPlayerModernJump             , m_ModernJump                                    , 0x6D0)
        SCHEMA_FIELD(::GameTick_t                    , m_nLastJumpTick                                 , 0x708)
        SCHEMA_FIELD(float                           , m_flLastJumpFrac                                , 0x70C)
        SCHEMA_FIELD(float                           , m_flLastJumpVelocityZ                           , 0x710)
        SCHEMA_FIELD(bool                            , m_bJumpApexPending                              , 0x714)
        SCHEMA_FIELD(float                           , m_flTicksSinceLastSurfingDetected               , 0x718)
        SCHEMA_FIELD(bool                            , m_bWasSurfing                                   , 0x71C)
        SCHEMA_FIELD(::Vector2D                      , m_vecWalkWishVel                                , 0x7AC)
        SCHEMA_FIELD(bool                            , m_bHasEverProcessedCommand                      , 0xFD8)
    };

    class CCSPlayer_CameraServices : public CCSPlayerBase_CameraServices {
    public:
        SCHEMA_FIELD(float                           , m_flDeathCamTilt                                , 0x2A8)
        SCHEMA_FIELD(::Vector                        , m_vClientScopeInaccuracy                        , 0x2B0)
    };

    class CCSObserver_CameraServices : public CCSPlayerBase_CameraServices {
    public:
    };

    class CBodyComponentPoint : public CBodyComponent {
    public:
        SCHEMA_FIELD(CGameSceneNode                  , m_sceneNode                                     , 0x80)
    };

    class CBodyComponentSkeletonInstance : public CBodyComponent {
    public:
        SCHEMA_FIELD(CSkeletonInstance               , m_skeletonInstance                              , 0x80)
    };

    class C_SoundOpvarSetAutoRoomEntity : public C_SoundOpvarSetPointEntity {
    public:
    };

    class C_SoundOpvarSetAABBEntity : public C_SoundOpvarSetPointEntity {
    public:
    };

    class C_SoundOpvarSetPathCornerEntity : public C_SoundOpvarSetPointEntity {
    public:
    };

    class CEnvSoundscapeProxyAlias_snd_soundscape_proxy : public CEnvSoundscapeProxy {
    public:
    };

    class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable : public CEnvSoundscapeTriggerable {
    public:
    };

    class C_CSGO_CounterTerroristWingmanIntroCamera : public C_CSGO_TeamPreviewCamera {
    public:
    };

    class C_CSGO_TeamSelectCamera : public C_CSGO_TeamPreviewCamera {
    public:
    };

    class C_CSGO_TerroristWingmanIntroCamera : public C_CSGO_TeamPreviewCamera {
    public:
    };

    class C_CSGO_TerroristTeamIntroCamera : public C_CSGO_TeamPreviewCamera {
    public:
    };

    class C_CSGO_CounterTerroristTeamIntroCamera : public C_CSGO_TeamPreviewCamera {
    public:
    };

    class C_CSGO_EndOfMatchCamera : public C_CSGO_TeamPreviewCamera {
    public:
    };

    class C_OmniLight : public C_BarnLight {
    public:
        SCHEMA_FIELD(float                           , m_flInnerAngle                                  , 0x12B8)
        SCHEMA_FIELD(float                           , m_flOuterAngle                                  , 0x12BC)
        SCHEMA_FIELD(bool                            , m_bShowLight                                    , 0x12C0)
    };

    class C_RectLight : public C_BarnLight {
    public:
        SCHEMA_FIELD(bool                            , m_bShowLight                                    , 0x12B8)
    };

    class C_BaseButton : public C_BaseToggle {
    public:
        SCHEMA_FIELD(CHandle<C_BaseModelEntity>      , m_glowEntity                                    , 0xFA8)
        SCHEMA_FIELD(bool                            , m_usable                                        , 0xFAC)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_szDisplayText                                 , 0xFB0)
    };

    class C_FuncMoveLinear : public C_BaseToggle {
    public:
    };

    class C_BaseDoor : public C_BaseToggle {
    public:
        SCHEMA_FIELD(bool                            , m_bIsUsable                                     , 0xFA8)
    };

    class C_BaseTrigger : public C_BaseToggle {
    public:
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartTouch                                  , 0xFA8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartTouchAll                               , 0xFC0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEndTouch                                    , 0xFD8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnEndTouchAll                                 , 0xFF0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTouching                                    , 0x1008)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTouchingEachEntity                          , 0x1020)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnNotTouching                                 , 0x1038)
        SCHEMA_FIELD(CUtlVector<CHandle<C_BaseEntity>>, m_hTouchingEntities                             , 0x1050)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x1068)
        SCHEMA_FIELD(CHandle<CBaseFilter>            , m_hFilter                                       , 0x1070)
        SCHEMA_FIELD(bool                            , m_bDisabled                                     , 0x1074)
    };

    class C_FuncMover : public C_BaseToggle {
    public:
    };

    class C_PointClientUIHUD : public C_BaseClientUIEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bCheckCSSClasses                              , 0xFE0)
        SCHEMA_FIELD(bool                            , m_bIgnoreInput                                  , 0x1158)
        SCHEMA_FIELD(float                           , m_flWidth                                       , 0x115C)
        SCHEMA_FIELD(float                           , m_flHeight                                      , 0x1160)
        SCHEMA_FIELD(float                           , m_flDPI                                         , 0x1164)
        SCHEMA_FIELD(float                           , m_flInteractDistance                            , 0x1168)
        SCHEMA_FIELD(float                           , m_flDepthOffset                                 , 0x116C)
        SCHEMA_FIELD(std::uint32_t                   , m_unOwnerContext                                , 0x1170)
        SCHEMA_FIELD(std::uint32_t                   , m_unHorizontalAlign                             , 0x1174)
        SCHEMA_FIELD(std::uint32_t                   , m_unVerticalAlign                               , 0x1178)
        SCHEMA_FIELD(std::uint32_t                   , m_unOrientation                                 , 0x117C)
        SCHEMA_FIELD(bool                            , m_bAllowInteractionFromAllSceneWorlds           , 0x1180)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CUtlSymbolLarge>, m_vecCSSClasses                                 , 0x1188)
    };

    class C_PointClientUIDialog : public C_BaseClientUIEntity {
    public:
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hActivator                                    , 0xFD8)
        SCHEMA_FIELD(bool                            , m_bStartEnabled                                 , 0xFDC)
    };

    class C_PointClientUIWorldPanel : public C_BaseClientUIEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bForceRecreateNextUpdate                      , 0xFE0)
        SCHEMA_FIELD(bool                            , m_bMoveViewToPlayerNextThink                    , 0xFE1)
        SCHEMA_FIELD(bool                            , m_bCheckCSSClasses                              , 0xFE2)
        SCHEMA_FIELD(CTransform                      , m_anchorDeltaTransform                          , 0xFF0)
        SCHEMA_FIELD(CPointOffScreenIndicatorUi*     , m_pOffScreenIndicator                           , 0x1180)
        SCHEMA_FIELD(bool                            , m_bIgnoreInput                                  , 0x11A8)
        SCHEMA_FIELD(bool                            , m_bLit                                          , 0x11A9)
        SCHEMA_FIELD(bool                            , m_bFollowPlayerAcrossTeleport                   , 0x11AA)
        SCHEMA_FIELD(float                           , m_flWidth                                       , 0x11AC)
        SCHEMA_FIELD(float                           , m_flHeight                                      , 0x11B0)
        SCHEMA_FIELD(float                           , m_flDPI                                         , 0x11B4)
        SCHEMA_FIELD(float                           , m_flInteractDistance                            , 0x11B8)
        SCHEMA_FIELD(float                           , m_flDepthOffset                                 , 0x11BC)
        SCHEMA_FIELD(std::uint32_t                   , m_unOwnerContext                                , 0x11C0)
        SCHEMA_FIELD(std::uint32_t                   , m_unHorizontalAlign                             , 0x11C4)
        SCHEMA_FIELD(std::uint32_t                   , m_unVerticalAlign                               , 0x11C8)
        SCHEMA_FIELD(std::uint32_t                   , m_unOrientation                                 , 0x11CC)
        SCHEMA_FIELD(bool                            , m_bAllowInteractionFromAllSceneWorlds           , 0x11D0)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CUtlSymbolLarge>, m_vecCSSClasses                                 , 0x11D8)
        SCHEMA_FIELD(bool                            , m_bOpaque                                       , 0x11F0)
        SCHEMA_FIELD(bool                            , m_bNoDepth                                      , 0x11F1)
        SCHEMA_FIELD(bool                            , m_bVisibleWhenParentNoDraw                      , 0x11F2)
        SCHEMA_FIELD(bool                            , m_bRenderBackface                               , 0x11F3)
        SCHEMA_FIELD(bool                            , m_bUseOffScreenIndicator                        , 0x11F4)
        SCHEMA_FIELD(bool                            , m_bExcludeFromSaveGames                         , 0x11F5)
        SCHEMA_FIELD(bool                            , m_bGrabbable                                    , 0x11F6)
        SCHEMA_FIELD(bool                            , m_bOnlyRenderToTexture                          , 0x11F7)
        SCHEMA_FIELD(bool                            , m_bDisableMipGen                                , 0x11F8)
        SCHEMA_FIELD(std::int32_t                    , m_nExplicitImageLayout                          , 0x11FC)
    };

    class C_FuncElectrifiedVolume : public C_FuncBrush {
    public:
        SCHEMA_FIELD(ParticleIndex_t                 , m_nAmbientEffect                                , 0xFA8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_EffectName                                    , 0xFB0)
        SCHEMA_FIELD(bool                            , m_bState                                        , 0xFB8)
    };

    class C_FuncMonitor : public C_FuncBrush {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_targetCamera                                  , 0xFA8)
        SCHEMA_FIELD(std::int32_t                    , m_nResolutionEnum                               , 0xFB0)
        SCHEMA_FIELD(bool                            , m_bRenderShadows                                , 0xFB4)
        SCHEMA_FIELD(bool                            , m_bUseUniqueColorTarget                         , 0xFB5)
        SCHEMA_FIELD(::CUtlString                    , m_brushModelName                                , 0xFB8)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hTargetCamera                                 , 0xFC0)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0xFC4)
        SCHEMA_FIELD(bool                            , m_bDraw3DSkybox                                 , 0xFC5)
    };

    class C_FireCrackerBlast : public C_Inferno {
    public:
    };

    class C_EnvParticleGlow : public C_ParticleSystem {
    public:
        SCHEMA_FIELD(float                           , m_flAlphaScale                                  , 0x1558)
        SCHEMA_FIELD(float                           , m_flRadiusScale                                 , 0x155C)
        SCHEMA_FIELD(float                           , m_flSelfIllumScale                              , 0x1560)
        SCHEMA_FIELD(::Color                         , m_ColorTint                                     , 0x1564)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCTextureBase>, m_hTextureOverride                              , 0x1568)
    };

    class C_MapPreviewParticleSystem : public C_ParticleSystem {
    public:
    };

    class C_PointWorldText : public C_ModelPointEntity {
    public:
        SCHEMA_FIELD(bool                            , m_bForceRecreateNextUpdate                      , 0xFB0)
        SCHEMA_FIELD(std::int32_t                    , m_nTextWidthPx                                  , 0xFC8)
        SCHEMA_FIELD(std::int32_t                    , m_nTextHeightPx                                 , 0xFCC)
        SCHEMA_FIELD(char                            , m_messageText                                   , 0xFD0)
        SCHEMA_FIELD(char                            , m_FontName                                      , 0x11D0)
        SCHEMA_FIELD(char                            , m_BackgroundMaterialName                        , 0x1210)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x1250)
        SCHEMA_FIELD(bool                            , m_bFullbright                                   , 0x1251)
        SCHEMA_FIELD(float                           , m_flWorldUnitsPerPx                             , 0x1254)
        SCHEMA_FIELD(float                           , m_flFontSize                                    , 0x1258)
        SCHEMA_FIELD(float                           , m_flDepthOffset                                 , 0x125C)
        SCHEMA_FIELD(bool                            , m_bDrawBackground                               , 0x1260)
        SCHEMA_FIELD(float                           , m_flBackgroundBorderWidth                       , 0x1264)
        SCHEMA_FIELD(float                           , m_flBackgroundBorderHeight                      , 0x1268)
        SCHEMA_FIELD(float                           , m_flBackgroundWorldToUV                         , 0x126C)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0x1270)
        SCHEMA_FIELD(PointWorldTextJustifyHorizontal_t, m_nJustifyHorizontal                            , 0x1274)
        SCHEMA_FIELD(PointWorldTextJustifyVertical_t , m_nJustifyVertical                              , 0x1278)
        SCHEMA_FIELD(PointWorldTextReorientMode_t    , m_nReorientMode                                 , 0x127C)
    };

    class C_PlayerSprayDecal : public C_ModelPointEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nUniqueID                                     , 0xFA8)
        SCHEMA_FIELD(std::uint32_t                   , m_unAccountID                                   , 0xFAC)
        SCHEMA_FIELD(std::uint32_t                   , m_unTraceID                                     , 0xFB0)
        SCHEMA_FIELD(std::uint32_t                   , m_rtGcTime                                      , 0xFB4)
        SCHEMA_FIELD(::Vector                        , m_vecEndPos                                     , 0xFB8)
        SCHEMA_FIELD(::Vector                        , m_vecStart                                      , 0xFC4)
        SCHEMA_FIELD(::Vector                        , m_vecLeft                                       , 0xFD0)
        SCHEMA_FIELD(::Vector                        , m_vecNormal                                     , 0xFDC)
        SCHEMA_FIELD(std::int32_t                    , m_nPlayer                                       , 0xFE8)
        SCHEMA_FIELD(std::int32_t                    , m_nEntity                                       , 0xFEC)
        SCHEMA_FIELD(std::int32_t                    , m_nHitbox                                       , 0xFF0)
        SCHEMA_FIELD(float                           , m_flCreationTime                                , 0xFF4)
        SCHEMA_FIELD(std::int32_t                    , m_nTintID                                       , 0xFF8)
        SCHEMA_FIELD(std::uint8_t                    , m_nVersion                                      , 0xFFC)
        SCHEMA_FIELD(std::uint8_t                    , m_ubSignature                                   , 0xFFD)
        SCHEMA_FIELD(CPlayerSprayDecalRenderHelper   , m_SprayRenderHelper                             , 0x1088)
    };

    class C_PhysBox : public C_Breakable {
    public:
    };

    class C_HostageCarriableProp : public CBaseAnimGraph {
    public:
    };

    class C_Fish : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(::Vector                        , m_pos                                           , 0x1158)
        SCHEMA_FIELD(::Vector                        , m_vel                                           , 0x1164)
        SCHEMA_FIELD(::QAngle                        , m_angles                                        , 0x1170)
        SCHEMA_FIELD(std::int32_t                    , m_localLifeState                                , 0x117C)
        SCHEMA_FIELD(float                           , m_deathDepth                                    , 0x1180)
        SCHEMA_FIELD(float                           , m_deathAngle                                    , 0x1184)
        SCHEMA_FIELD(float                           , m_buoyancy                                      , 0x1188)
        SCHEMA_FIELD(CountdownTimer                  , m_wiggleTimer                                   , 0x1190)
        SCHEMA_FIELD(float                           , m_wigglePhase                                   , 0x11A8)
        SCHEMA_FIELD(float                           , m_wiggleRate                                    , 0x11AC)
        SCHEMA_FIELD(::Vector                        , m_actualPos                                     , 0x11B0)
        SCHEMA_FIELD(::QAngle                        , m_actualAngles                                  , 0x11BC)
        SCHEMA_FIELD(::Vector                        , m_poolOrigin                                    , 0x11C8)
        SCHEMA_FIELD(float                           , m_waterLevel                                    , 0x11D4)
        SCHEMA_FIELD(bool                            , m_gotUpdate                                     , 0x11D8)
        SCHEMA_FIELD(float                           , m_x                                             , 0x11DC)
        SCHEMA_FIELD(float                           , m_y                                             , 0x11E0)
        SCHEMA_FIELD(float                           , m_z                                             , 0x11E4)
        SCHEMA_FIELD(float                           , m_angle                                         , 0x11E8)
        SCHEMA_FIELD(float                           , m_errorHistory                                  , 0x11EC)
        SCHEMA_FIELD(std::int32_t                    , m_errorHistoryIndex                             , 0x123C)
        SCHEMA_FIELD(std::int32_t                    , m_errorHistoryCount                             , 0x1240)
        SCHEMA_FIELD(float                           , m_averageError                                  , 0x1244)
    };

    class C_PointCommentaryNode : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bActive                                       , 0x1170)
        SCHEMA_FIELD(bool                            , m_bWasActive                                    , 0x1171)
        SCHEMA_FIELD(::GameTime_t                    , m_flEndTime                                     , 0x1174)
        SCHEMA_FIELD(::GameTime_t                    , m_flStartTime                                   , 0x1178)
        SCHEMA_FIELD(float                           , m_flStartTimeInCommentary                       , 0x117C)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszCommentaryFile                             , 0x1180)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszTitle                                      , 0x1188)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszSpeakers                                   , 0x1190)
        SCHEMA_FIELD(std::int32_t                    , m_iNodeNumber                                   , 0x1198)
        SCHEMA_FIELD(std::int32_t                    , m_iNodeNumberMax                                , 0x119C)
        SCHEMA_FIELD(bool                            , m_bListenedTo                                   , 0x11A0)
        SCHEMA_FIELD(CSoundPatch*                    , m_sndCommentary                                 , 0x11A8)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hViewPosition                                 , 0x11B0)
        SCHEMA_FIELD(bool                            , m_bRestartAfterRestore                          , 0x11B4)
    };

    class C_WorldModelGloves : public CBaseAnimGraph {
    public:
    };

    class C_LateUpdatedAnimating : public CBaseAnimGraph {
    public:
    };

    class CBaseProp : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bModelOverrodeBlockLOS                        , 0x1158)
        SCHEMA_FIELD(std::int32_t                    , m_iShapeType                                    , 0x115C)
        SCHEMA_FIELD(bool                            , m_bConformToCollisionBounds                     , 0x1160)
        SCHEMA_FIELD(CTransform                      , m_mPreferredCatchTransform                      , 0x1170)
    };

    class C_CSGO_PreviewModel : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_defaultAnim                                   , 0x1158)
        SCHEMA_FIELD(AnimLoopMode_t                  , m_nDefaultAnimLoopMode                          , 0x1160)
        SCHEMA_FIELD(float                           , m_flInitialModelScale                           , 0x1164)
        SCHEMA_FIELD(::CUtlString                    , m_sInitialWeaponState                           , 0x1168)
    };

    class C_ClientRagdoll : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bFadeOut                                      , 0x1158)
        SCHEMA_FIELD(bool                            , m_bImportant                                    , 0x1159)
        SCHEMA_FIELD(::GameTime_t                    , m_flEffectTime                                  , 0x115C)
        SCHEMA_FIELD(::GameTime_t                    , m_gibDespawnTime                                , 0x1160)
        SCHEMA_FIELD(std::int32_t                    , m_iCurrentFriction                              , 0x1164)
        SCHEMA_FIELD(std::int32_t                    , m_iMinFriction                                  , 0x1168)
        SCHEMA_FIELD(std::int32_t                    , m_iMaxFriction                                  , 0x116C)
        SCHEMA_FIELD(std::int32_t                    , m_iFrictionAnimState                            , 0x1170)
        SCHEMA_FIELD(bool                            , m_bReleaseRagdoll                               , 0x1174)
        SCHEMA_FIELD(AttachmentHandle_t              , m_iEyeAttachment                                , 0x1175)
        SCHEMA_FIELD(bool                            , m_bFadingOut                                    , 0x1176)
        SCHEMA_FIELD(float                           , m_flScaleEnd                                    , 0x1178)
        SCHEMA_FIELD(::GameTime_t                    , m_flScaleTimeStart                              , 0x11A0)
        SCHEMA_FIELD(::GameTime_t                    , m_flScaleTimeEnd                                , 0x11C8)
    };

    class C_CS2WeaponModuleBase : public CBaseAnimGraph {
    public:
    };

    class C_Multimeter : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(CHandle<C_PlantedC4>            , m_hTargetC4                                     , 0x1158)
    };

    class C_WaterBullet : public CBaseAnimGraph {
    public:
    };

    class C_BaseCombatCharacter : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<CHandle<C_EconWearable>>, m_hMyWearables                                  , 0x1158)
        SCHEMA_FIELD(AttachmentHandle_t              , m_leftFootAttachment                            , 0x1170)
        SCHEMA_FIELD(AttachmentHandle_t              , m_rightFootAttachment                           , 0x1171)
        SCHEMA_FIELD(C_BaseCombatCharacter_WaterWakeMode_t, m_nWaterWakeMode                                , 0x1174)
        SCHEMA_FIELD(float                           , m_flWaterWorldZ                                 , 0x1178)
        SCHEMA_FIELD(float                           , m_flWaterNextTraceTime                          , 0x117C)
    };

    class C_EconEntity : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(float                           , m_flFlexDelayTime                               , 0x1168)
        SCHEMA_FIELD(float32*                        , m_flFlexDelayedWeight                           , 0x1170)
        SCHEMA_FIELD(bool                            , m_bAttributesInitialized                        , 0x1178)
        SCHEMA_FIELD(C_AttributeContainer            , m_AttributeManager                              , 0x1180)
        SCHEMA_FIELD(std::uint32_t                   , m_OriginalOwnerXuidLow                          , 0x1650)
        SCHEMA_FIELD(std::uint32_t                   , m_OriginalOwnerXuidHigh                         , 0x1654)
        SCHEMA_FIELD(std::int32_t                    , m_nFallbackPaintKit                             , 0x1658)
        SCHEMA_FIELD(std::int32_t                    , m_nFallbackSeed                                 , 0x165C)
        SCHEMA_FIELD(float                           , m_flFallbackWear                                , 0x1660)
        SCHEMA_FIELD(std::int32_t                    , m_nFallbackStatTrak                             , 0x1664)
        SCHEMA_FIELD(bool                            , m_bClientside                                   , 0x1668)
        SCHEMA_FIELD(bool                            , m_bParticleSystemsCreated                       , 0x1669)
        SCHEMA_FIELD(CUtlVector<int32>               , m_vecAttachedParticles                          , 0x1670)
        SCHEMA_FIELD(CHandle<CBaseAnimGraph>         , m_hViewmodelAttachment                          , 0x1688)
        SCHEMA_FIELD(std::int32_t                    , m_iOldTeam                                      , 0x168C)
        SCHEMA_FIELD(bool                            , m_bAttachmentDirty                              , 0x1690)
        SCHEMA_FIELD(std::int32_t                    , m_nUnloadedModelIndex                           , 0x1694)
        SCHEMA_FIELD(std::int32_t                    , m_iNumOwnerValidationRetries                    , 0x1698)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hOldProvidee                                  , 0x16A8)
        SCHEMA_FIELD(CUtlVector<C_EconEntity_AttachedModelData_t>, m_vecAttachedModels                             , 0x16B0)
    };

    class C_PhysMagnet : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(CUtlVector<int32>               , m_aAttachedObjectsFromServer                    , 0x1158)
        SCHEMA_FIELD(CUtlVector<CHandle<C_BaseEntity>>, m_aAttachedObjects                              , 0x1170)
    };

    class C_PlantedC4 : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bBombTicking                                  , 0x1160)
        SCHEMA_FIELD(std::int32_t                    , m_nBombSite                                     , 0x1164)
        SCHEMA_FIELD(std::int32_t                    , m_nSourceSoundscapeHash                         , 0x1168)
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0x1170)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextGlow                                    , 0x1188)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextBeep                                    , 0x118C)
        SCHEMA_FIELD(::GameTime_t                    , m_flC4Blow                                      , 0x1190)
        SCHEMA_FIELD(bool                            , m_bCannotBeDefused                              , 0x1194)
        SCHEMA_FIELD(bool                            , m_bHasExploded                                  , 0x1195)
        SCHEMA_FIELD(float                           , m_flTimerLength                                 , 0x1198)
        SCHEMA_FIELD(bool                            , m_bBeingDefused                                 , 0x119C)
        SCHEMA_FIELD(float                           , m_bTriggerWarning                               , 0x11A0)
        SCHEMA_FIELD(float                           , m_bExplodeWarning                               , 0x11A4)
        SCHEMA_FIELD(bool                            , m_bC4Activated                                  , 0x11A8)
        SCHEMA_FIELD(bool                            , m_bTenSecWarning                                , 0x11A9)
        SCHEMA_FIELD(float                           , m_flDefuseLength                                , 0x11AC)
        SCHEMA_FIELD(::GameTime_t                    , m_flDefuseCountDown                             , 0x11B0)
        SCHEMA_FIELD(bool                            , m_bBombDefused                                  , 0x11B4)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hBombDefuser                                  , 0x11B8)
        SCHEMA_FIELD(C_AttributeContainer            , m_AttributeManager                              , 0x11C0)
        SCHEMA_FIELD(CHandle<C_Multimeter>           , m_hDefuserMultimeter                            , 0x1690)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextRadarFlashTime                          , 0x1694)
        SCHEMA_FIELD(bool                            , m_bRadarFlash                                   , 0x1698)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_pBombDefuser                                  , 0x169C)
        SCHEMA_FIELD(::GameTime_t                    , m_fLastDefuseTime                               , 0x16A0)
        SCHEMA_FIELD(CBasePlayerController*          , m_pPredictionOwner                              , 0x16A8)
        SCHEMA_FIELD(::Vector                        , m_vecC4ExplodeSpectatePos                       , 0x16B0)
        SCHEMA_FIELD(::QAngle                        , m_vecC4ExplodeSpectateAng                       , 0x16BC)
        SCHEMA_FIELD(float                           , m_flC4ExplodeSpectateDuration                   , 0x16C8)
    };

    class C_RagdollProp : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(C_NetworkUtlVectorBase<bool>    , m_ragEnabled                                    , 0x1158)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<Vector>  , m_ragPos                                        , 0x1170)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<QAngle>  , m_ragAngles                                     , 0x1188)
        SCHEMA_FIELD(float                           , m_flBlendWeight                                 , 0x11A0)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hRagdollSource                                , 0x11A4)
        SCHEMA_FIELD(AttachmentHandle_t              , m_iEyeAttachment                                , 0x11A8)
        SCHEMA_FIELD(float                           , m_flBlendWeightCurrent                          , 0x11AC)
        SCHEMA_FIELD(CUtlVector<int32>               , m_parentPhysicsBoneIndices                      , 0x11B0)
        SCHEMA_FIELD(CUtlVector<int32>               , m_worldSpaceBoneComputationOrder                , 0x11C8)
    };

    class C_LocalTempEntity : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(std::int32_t                    , flags                                           , 0x1158)
        SCHEMA_FIELD(::GameTime_t                    , die                                             , 0x115C)
        SCHEMA_FIELD(float                           , m_flFrameMax                                    , 0x1160)
        SCHEMA_FIELD(float                           , x                                               , 0x1164)
        SCHEMA_FIELD(float                           , y                                               , 0x1168)
        SCHEMA_FIELD(float                           , fadeSpeed                                       , 0x116C)
        SCHEMA_FIELD(float                           , bounceFactor                                    , 0x1170)
        SCHEMA_FIELD(std::int32_t                    , hitSound                                        , 0x1174)
        SCHEMA_FIELD(std::int32_t                    , priority                                        , 0x1178)
        SCHEMA_FIELD(::Vector                        , tentOffset                                      , 0x117C)
        SCHEMA_FIELD(::QAngle                        , m_vecTempEntAngVelocity                         , 0x1188)
        SCHEMA_FIELD(std::int32_t                    , tempent_renderamt                               , 0x1194)
        SCHEMA_FIELD(::Vector                        , m_vecNormal                                     , 0x1198)
        SCHEMA_FIELD(float                           , m_flSpriteScale                                 , 0x11A4)
        SCHEMA_FIELD(std::int32_t                    , m_nFlickerFrame                                 , 0x11A8)
        SCHEMA_FIELD(float                           , m_flFrameRate                                   , 0x11AC)
        SCHEMA_FIELD(float                           , m_flFrame                                       , 0x11B0)
        SCHEMA_FIELD(char*                           , m_pszImpactEffect                               , 0x11B8)
        SCHEMA_FIELD(char*                           , m_pszParticleEffect                             , 0x11C0)
        SCHEMA_FIELD(bool                            , m_bParticleCollision                            , 0x11C8)
        SCHEMA_FIELD(std::int32_t                    , m_iLastCollisionFrame                           , 0x11CC)
        SCHEMA_FIELD(::Vector                        , m_vLastCollisionOrigin                          , 0x11D0)
        SCHEMA_FIELD(::Vector                        , m_vecTempEntVelocity                            , 0x11DC)
        SCHEMA_FIELD(::Vector                        , m_vecPrevAbsOrigin                              , 0x11E8)
        SCHEMA_FIELD(::Vector                        , m_vecTempEntAcceleration                        , 0x11F4)
    };

    class C_BaseGrenade : public CBaseAnimGraph {
    public:
        SCHEMA_FIELD(bool                            , m_bHasWarnedAI                                  , 0x1158)
        SCHEMA_FIELD(bool                            , m_bIsSmokeGrenade                               , 0x1159)
        SCHEMA_FIELD(bool                            , m_bIsLive                                       , 0x115A)
        SCHEMA_FIELD(float                           , m_DmgRadius                                     , 0x115C)
        SCHEMA_FIELD(::GameTime_t                    , m_flDetonateTime                                , 0x1160)
        SCHEMA_FIELD(float                           , m_flWarnAITime                                  , 0x1164)
        SCHEMA_FIELD(float                           , m_flDamage                                      , 0x1168)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszBounceSound                                , 0x1170)
        SCHEMA_FIELD(::CUtlString                    , m_ExplosionSound                                , 0x1178)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hThrower                                      , 0x1180)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextAttack                                  , 0x1198)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hOriginalThrower                              , 0x119C)
    };

    class C_LightDirectionalEntity : public C_LightEntity {
    public:
    };

    class C_LightOrthoEntity : public C_LightEntity {
    public:
    };

    class C_LightSpotEntity : public C_LightEntity {
    public:
    };

    class CSpriteOriented : public C_Sprite {
    public:
    };

    class C_CSGO_TeamIntroTerroristPosition : public C_CSGO_TeamIntroCharacterPosition {
    public:
    };

    class C_CSGO_TeamIntroCounterTerroristPosition : public C_CSGO_TeamIntroCharacterPosition {
    public:
    };

    class CCSGO_WingmanIntroCharacterPosition : public C_CSGO_TeamIntroCharacterPosition {
    public:
    };

    class C_CSGO_TeamSelectTerroristPosition : public C_CSGO_TeamSelectCharacterPosition {
    public:
    };

    class C_CSGO_TeamSelectCounterTerroristPosition : public C_CSGO_TeamSelectCharacterPosition {
    public:
    };

    class CInfoDynamicShadowHintBox : public CInfoDynamicShadowHint {
    public:
        SCHEMA_FIELD(::Vector                        , m_vBoxMins                                      , 0x618)
        SCHEMA_FIELD(::Vector                        , m_vBoxMaxs                                      , 0x624)
    };

    class CFilterMultiple : public CBaseFilter {
    public:
        SCHEMA_FIELD(filter_t                        , m_nFilterType                                   , 0x638)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x640)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hFilter                                       , 0x690)
    };

    class FilterHealth : public CBaseFilter {
    public:
        SCHEMA_FIELD(bool                            , m_bAdrenalineActive                             , 0x638)
        SCHEMA_FIELD(std::int32_t                    , m_iHealthMin                                    , 0x63C)
        SCHEMA_FIELD(std::int32_t                    , m_iHealthMax                                    , 0x640)
    };

    class CFilterAttributeInt : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_sAttributeName                                , 0x638)
    };

    class CFilterLOS : public CBaseFilter {
    public:
    };

    class CFilterMassGreater : public CBaseFilter {
    public:
        SCHEMA_FIELD(float                           , m_fFilterMass                                   , 0x638)
    };

    class FilterDamageType : public CBaseFilter {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iDamageType                                   , 0x638)
    };

    class CFilterProximity : public CBaseFilter {
    public:
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x638)
    };

    class CFilterModel : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterModel                                  , 0x638)
    };

    class CFilterName : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterName                                   , 0x638)
    };

    class CFilterClass : public CBaseFilter {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iFilterClass                                  , 0x638)
    };

    class CFilterTeam : public CBaseFilter {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_iFilterTeam                                   , 0x638)
    };

    class CBodyComponentBaseAnimGraph : public CBodyComponentSkeletonInstance {
    public:
        SCHEMA_FIELD(CBaseAnimGraphController        , m_animationController                           , 0x4E0)
    };

    class CBodyComponentBaseModelEntity : public CBodyComponentSkeletonInstance {
    public:
    };

    class C_SoundOpvarSetOBBEntity : public C_SoundOpvarSetAABBEntity {
    public:
    };

    class CTriggerFan : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(::Vector                        , m_vFanOriginOffset                              , 0x1078)
        SCHEMA_FIELD(::Vector                        , m_vDirection                                    , 0x1084)
        SCHEMA_FIELD(bool                            , m_bPushTowardsInfoTarget                        , 0x1090)
        SCHEMA_FIELD(bool                            , m_bPushAwayFromInfoTarget                       , 0x1091)
        SCHEMA_FIELD(::Quaternion                    , m_qNoiseDelta                                   , 0x10A0)
        SCHEMA_FIELD(CHandle<CInfoFan>               , m_hInfoFan                                      , 0x10B0)
        SCHEMA_FIELD(float                           , m_flForce                                       , 0x10B4)
        SCHEMA_FIELD(bool                            , m_bFalloff                                      , 0x10B8)
        SCHEMA_FIELD(CountdownTimer                  , m_RampTimer                                     , 0x10C0)
    };

    class C_PostProcessingVolume : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeCPostProcessingResource>, m_hPostSettings                                 , 0x1088)
        SCHEMA_FIELD(float                           , m_flFadeDuration                                , 0x1090)
        SCHEMA_FIELD(float                           , m_flMinLogExposure                              , 0x1094)
        SCHEMA_FIELD(float                           , m_flMaxLogExposure                              , 0x1098)
        SCHEMA_FIELD(float                           , m_flMinExposure                                 , 0x109C)
        SCHEMA_FIELD(float                           , m_flMaxExposure                                 , 0x10A0)
        SCHEMA_FIELD(float                           , m_flExposureCompensation                        , 0x10A4)
        SCHEMA_FIELD(float                           , m_flExposureFadeSpeedUp                         , 0x10A8)
        SCHEMA_FIELD(float                           , m_flExposureFadeSpeedDown                       , 0x10AC)
        SCHEMA_FIELD(float                           , m_flTonemapEVSmoothingRange                     , 0x10B0)
        SCHEMA_FIELD(bool                            , m_bMaster                                       , 0x10B4)
        SCHEMA_FIELD(bool                            , m_bExposureControl                              , 0x10B5)
    };

    class C_Precipitation : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(float                           , m_flDensity                                     , 0x1078)
        SCHEMA_FIELD(float                           , m_flParticleInnerDist                           , 0x1088)
        SCHEMA_FIELD(char*                           , m_pParticleDef                                  , 0x1090)
        SCHEMA_FIELD(TimedEvent                      , m_tParticlePrecipTraceTimer                     , 0x109C)
        SCHEMA_FIELD(bool                            , m_bActiveParticlePrecipEmitter                  , 0x10A4)
        SCHEMA_FIELD(bool                            , m_bParticlePrecipInitialized                    , 0x10A5)
        SCHEMA_FIELD(bool                            , m_bHasSimulatedSinceLastSceneObjectUpdate       , 0x10A6)
        SCHEMA_FIELD(std::int32_t                    , m_nAvailableSheetSequencesMaxIndex              , 0x10A8)
    };

    class CHostageRescueZoneShim : public C_BaseTrigger {
    public:
    };

    class C_TriggerMultiple : public C_BaseTrigger {
    public:
    };

    class C_ColorCorrectionVolume : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(float                           , m_LastEnterWeight                               , 0x1078)
        SCHEMA_FIELD(::GameTime_t                    , m_LastEnterTime                                 , 0x107C)
        SCHEMA_FIELD(float                           , m_LastExitWeight                                , 0x1080)
        SCHEMA_FIELD(::GameTime_t                    , m_LastExitTime                                  , 0x1084)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0x1088)
        SCHEMA_FIELD(float                           , m_MaxWeight                                     , 0x108C)
        SCHEMA_FIELD(float                           , m_FadeDuration                                  , 0x1090)
        SCHEMA_FIELD(float                           , m_Weight                                        , 0x1094)
        SCHEMA_FIELD(char                            , m_lookupFilename                                , 0x1098)
    };

    class CBombTarget : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(bool                            , m_bBombPlantedHere                              , 0x1078)
    };

    class C_TriggerLerpObject : public C_BaseTrigger {
    public:
    };

    class C_TriggerBuoyancy : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(CBuoyancyHelper                 , m_BuoyancyHelper                                , 0x1078)
        SCHEMA_FIELD(float                           , m_flFluidDensity                                , 0x1190)
    };

    class C_TriggerPhysics : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(float                           , m_gravityScale                                  , 0x1078)
        SCHEMA_FIELD(float                           , m_linearLimit                                   , 0x107C)
        SCHEMA_FIELD(float                           , m_linearDamping                                 , 0x1080)
        SCHEMA_FIELD(float                           , m_angularLimit                                  , 0x1084)
        SCHEMA_FIELD(float                           , m_angularDamping                                , 0x1088)
        SCHEMA_FIELD(float                           , m_linearForce                                   , 0x108C)
        SCHEMA_FIELD(float                           , m_flFrequency                                   , 0x1090)
        SCHEMA_FIELD(float                           , m_flDampingRatio                                , 0x1094)
        SCHEMA_FIELD(::Vector                        , m_vecLinearForcePointAt                         , 0x1098)
        SCHEMA_FIELD(bool                            , m_bCollapseToForcePoint                         , 0x10A4)
        SCHEMA_FIELD(::Vector                        , m_vecLinearForcePointAtWorld                    , 0x10A8)
        SCHEMA_FIELD(::Vector                        , m_vecLinearForceDirection                       , 0x10B4)
        SCHEMA_FIELD(bool                            , m_bConvertToDebrisWhenPossible                  , 0x10C0)
    };

    class C_FootstepControl : public C_BaseTrigger {
    public:
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_source                                        , 0x1078)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_destination                                   , 0x1080)
    };

    class CPointOffScreenIndicatorUi : public C_PointClientUIWorldPanel {
    public:
        SCHEMA_FIELD(bool                            , m_bBeenEnabled                                  , 0x1200)
        SCHEMA_FIELD(bool                            , m_bHide                                         , 0x1201)
        SCHEMA_FIELD(float                           , m_flSeenTargetTime                              , 0x1204)
        SCHEMA_FIELD(C_PointClientUIWorldPanel*      , m_pTargetPanel                                  , 0x1208)
    };

    class C_PointClientUIWorldTextPanel : public C_PointClientUIWorldPanel {
    public:
        SCHEMA_FIELD(char                            , m_messageText                                   , 0x1200)
    };

    class C_CS2HudModelAddon : public C_LateUpdatedAnimating {
    public:
    };

    class C_CS2HudModelBase : public C_LateUpdatedAnimating {
    public:
    };

    class C_BreakableProp : public CBaseProp {
    public:
        SCHEMA_FIELD(CPropDataComponent              , m_CPropDataComponent                            , 0x1190)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnStartDeath                                  , 0x11D0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnBreak                                       , 0x11E8)
        SCHEMA_FIELD(CEntityOutputTemplate<float32>  , m_OnHealthChanged                               , 0x1200)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnTakeDamage                                  , 0x1220)
        SCHEMA_FIELD(float                           , m_impactEnergyScale                             , 0x1238)
        SCHEMA_FIELD(std::int32_t                    , m_iMinHealthDmg                                 , 0x123C)
        SCHEMA_FIELD(float                           , m_flPressureDelay                               , 0x1240)
        SCHEMA_FIELD(float                           , m_flDefBurstScale                               , 0x1244)
        SCHEMA_FIELD(::Vector                        , m_vDefBurstOffset                               , 0x1248)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hBreaker                                      , 0x1254)
        SCHEMA_FIELD(PerformanceMode_t               , m_PerformanceMode                               , 0x1258)
        SCHEMA_FIELD(::GameTime_t                    , m_flPreventDamageBeforeTime                     , 0x125C)
        SCHEMA_FIELD(BreakableContentsType_t         , m_BreakableContentsType                         , 0x1260)
        SCHEMA_FIELD(::CUtlString                    , m_strBreakableContentsPropGroupOverride         , 0x1268)
        SCHEMA_FIELD(::CUtlString                    , m_strBreakableContentsParticleOverride          , 0x1270)
        SCHEMA_FIELD(bool                            , m_bHasBreakPiecesOrCommands                     , 0x1278)
        SCHEMA_FIELD(float                           , m_explodeDamage                                 , 0x127C)
        SCHEMA_FIELD(float                           , m_explodeRadius                                 , 0x1280)
        SCHEMA_FIELD(CGlobalSymbol                   , m_sExplosionType                                , 0x1288)
        SCHEMA_FIELD(float                           , m_explosionDelay                                , 0x1290)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionBuildupSound                         , 0x1298)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionCustomEffect                         , 0x12A0)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionCustomSound                          , 0x12A8)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_explosionModifier                             , 0x12B0)
        SCHEMA_FIELD(CHandle<C_BasePlayerPawn>       , m_hPhysicsAttacker                              , 0x12B8)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastPhysicsInfluenceTime                    , 0x12BC)
        SCHEMA_FIELD(float                           , m_flDefaultFadeScale                            , 0x12C0)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_hLastAttacker                                 , 0x12C4)
    };

    class C_CSGO_PreviewModelAlias_csgo_item_previewmodel : public C_CSGO_PreviewModel {
    public:
    };

    class C_KeychainModule : public C_CS2WeaponModuleBase {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nKeychainDefID                                , 0x1160)
        SCHEMA_FIELD(std::uint32_t                   , m_nKeychainSeed                                 , 0x1164)
    };

    class C_StattrakModule : public C_CS2WeaponModuleBase {
    public:
        SCHEMA_FIELD(bool                            , m_bKnife                                        , 0x1160)
    };

    class C_NametagModule : public C_CS2WeaponModuleBase {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strNametagString                              , 0x1160)
    };

    class C_NetTestBaseCombatCharacter : public C_BaseCombatCharacter {
    public:
    };

    class C_Hostage : public C_BaseCombatCharacter {
    public:
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0x11E0)
        SCHEMA_FIELD(CHandle<C_BaseEntity>           , m_leader                                        , 0x11F8)
        SCHEMA_FIELD(CountdownTimer                  , m_reuseTimer                                    , 0x1200)
        SCHEMA_FIELD(::Vector                        , m_vel                                           , 0x1218)
        SCHEMA_FIELD(bool                            , m_isRescued                                     , 0x1224)
        SCHEMA_FIELD(bool                            , m_jumpedThisFrame                               , 0x1225)
        SCHEMA_FIELD(std::int32_t                    , m_nHostageState                                 , 0x1228)
        SCHEMA_FIELD(bool                            , m_bHandsHaveBeenCut                             , 0x122C)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hHostageGrabber                               , 0x1230)
        SCHEMA_FIELD(::GameTime_t                    , m_fLastGrabTime                                 , 0x1234)
        SCHEMA_FIELD(::Vector                        , m_vecGrabbedPos                                 , 0x1238)
        SCHEMA_FIELD(::GameTime_t                    , m_flRescueStartTime                             , 0x1244)
        SCHEMA_FIELD(::GameTime_t                    , m_flGrabSuccessTime                             , 0x1248)
        SCHEMA_FIELD(::GameTime_t                    , m_flDropStartTime                               , 0x124C)
        SCHEMA_FIELD(::GameTime_t                    , m_flDeadOrRescuedTime                           , 0x1250)
        SCHEMA_FIELD(CountdownTimer                  , m_blinkTimer                                    , 0x1258)
        SCHEMA_FIELD(::Vector                        , m_lookAt                                        , 0x1270)
        SCHEMA_FIELD(CountdownTimer                  , m_lookAroundTimer                               , 0x1280)
        SCHEMA_FIELD(bool                            , m_isInit                                        , 0x1298)
        SCHEMA_FIELD(AttachmentHandle_t              , m_eyeAttachment                                 , 0x1299)
        SCHEMA_FIELD(AttachmentHandle_t              , m_chestAttachment                               , 0x129A)
        SCHEMA_FIELD(CBasePlayerController*          , m_pPredictionOwner                              , 0x12A0)
        SCHEMA_FIELD(::GameTime_t                    , m_fNewestAlphaThinkTime                         , 0x12A8)
    };

    class C_BasePlayerPawn : public C_BaseCombatCharacter {
    public:
        SCHEMA_FIELD(CPlayer_WeaponServices*         , m_pWeaponServices                               , 0x11E0)
        SCHEMA_FIELD(CPlayer_ItemServices*           , m_pItemServices                                 , 0x11E8)
        SCHEMA_FIELD(CPlayer_AutoaimServices*        , m_pAutoaimServices                              , 0x11F0)
        SCHEMA_FIELD(CPlayer_ObserverServices*       , m_pObserverServices                             , 0x11F8)
        SCHEMA_FIELD(CPlayer_WaterServices*          , m_pWaterServices                                , 0x1200)
        SCHEMA_FIELD(CPlayer_UseServices*            , m_pUseServices                                  , 0x1208)
        SCHEMA_FIELD(CPlayer_FlashlightServices*     , m_pFlashlightServices                           , 0x1210)
        SCHEMA_FIELD(CPlayer_CameraServices*         , m_pCameraServices                               , 0x1218)
        SCHEMA_FIELD(CPlayer_MovementServices*       , m_pMovementServices                             , 0x1220)
        SCHEMA_FIELD(C_UtlVectorEmbeddedNetworkVar<ViewAngleServerChange_t>, m_ServerViewAngleChanges                        , 0x1230)
        SCHEMA_FIELD(::QAngle                        , v_angle                                         , 0x1298)
        SCHEMA_FIELD(::QAngle                        , v_anglePrevious                                 , 0x12A4)
        SCHEMA_FIELD(std::uint32_t                   , m_iHideHUD                                      , 0x12B0)
        SCHEMA_FIELD(sky3dparams_t                   , m_skybox3d                                      , 0x12B8)
        SCHEMA_FIELD(::GameTime_t                    , m_flDeathTime                                   , 0x1348)
        SCHEMA_FIELD(::Vector                        , m_vecPredictionError                            , 0x134C)
        SCHEMA_FIELD(::GameTime_t                    , m_flPredictionErrorTime                         , 0x1358)
        SCHEMA_FIELD(::Vector                        , m_vecLastCameraSetupLocalOrigin                 , 0x1378)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastCameraSetupTime                         , 0x1384)
        SCHEMA_FIELD(float                           , m_flFOVSensitivityAdjust                        , 0x1388)
        SCHEMA_FIELD(float                           , m_flMouseSensitivity                            , 0x138C)
        SCHEMA_FIELD(::Vector                        , m_vOldOrigin                                    , 0x1390)
        SCHEMA_FIELD(float                           , m_flOldSimulationTime                           , 0x139C)
        SCHEMA_FIELD(std::int32_t                    , m_nLastExecutedCommandNumber                    , 0x13A0)
        SCHEMA_FIELD(std::int32_t                    , m_nLastExecutedCommandTick                      , 0x13A4)
        SCHEMA_FIELD(CHandle<CBasePlayerController>  , m_hController                                   , 0x13A8)
        SCHEMA_FIELD(CHandle<CBasePlayerController>  , m_hDefaultController                            , 0x13AC)
        SCHEMA_FIELD(bool                            , m_bIsSwappingToPredictableController            , 0x13B0)
    };

    class C_BasePlayerWeapon : public C_EconEntity {
    public:
        SCHEMA_FIELD(::GameTick_t                    , m_nNextPrimaryAttackTick                        , 0x16C8)
        SCHEMA_FIELD(float                           , m_flNextPrimaryAttackTickRatio                  , 0x16CC)
        SCHEMA_FIELD(::GameTick_t                    , m_nNextSecondaryAttackTick                      , 0x16D0)
        SCHEMA_FIELD(float                           , m_flNextSecondaryAttackTickRatio                , 0x16D4)
        SCHEMA_FIELD(std::int32_t                    , m_iClip1                                        , 0x16D8)
        SCHEMA_FIELD(std::int32_t                    , m_iClip2                                        , 0x16DC)
        SCHEMA_FIELD(std::int32_t                    , m_pReserveAmmo                                  , 0x16E0)
    };

    class C_EconWearable : public C_EconEntity {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nForceSkin                                    , 0x16C8)
        SCHEMA_FIELD(bool                            , m_bAlwaysAllow                                  , 0x16CC)
    };

    class C_Item : public C_EconEntity {
    public:
        SCHEMA_FIELD(char                            , m_pReticleHintTextName                          , 0x16C8)
    };

    class C_RagdollPropAttached : public C_RagdollProp {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_boneIndexAttached                             , 0x11E0)
        SCHEMA_FIELD(std::uint32_t                   , m_ragdollAttachedObjectIndex                    , 0x11E4)
        SCHEMA_FIELD(::Vector                        , m_attachmentPointBoneSpace                      , 0x11E8)
        SCHEMA_FIELD(::Vector                        , m_attachmentPointRagdollSpace                   , 0x11F4)
        SCHEMA_FIELD(::Vector                        , m_vecOffset                                     , 0x1200)
        SCHEMA_FIELD(float                           , m_parentTime                                    , 0x120C)
        SCHEMA_FIELD(bool                            , m_bHasParent                                    , 0x1210)
    };

    class C_BaseCSGrenadeProjectile : public C_BaseGrenade {
    public:
        SCHEMA_FIELD(::Vector                        , m_vInitialPosition                              , 0x11A0)
        SCHEMA_FIELD(::Vector                        , m_vInitialVelocity                              , 0x11AC)
        SCHEMA_FIELD(std::int32_t                    , m_nBounces                                      , 0x11B8)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSystemDefinition>, m_nExplodeEffectIndex                           , 0x11C0)
        SCHEMA_FIELD(std::int32_t                    , m_nExplodeEffectTickBegin                       , 0x11C8)
        SCHEMA_FIELD(::Vector                        , m_vecExplodeEffectOrigin                        , 0x11CC)
        SCHEMA_FIELD(::GameTime_t                    , m_flSpawnTime                                   , 0x11D8)
        SCHEMA_FIELD(::Vector                        , vecLastTrailLinePos                             , 0x11DC)
        SCHEMA_FIELD(::GameTime_t                    , flNextTrailLineTime                             , 0x11E8)
        SCHEMA_FIELD(bool                            , m_bExplodeEffectBegan                           , 0x11EC)
        SCHEMA_FIELD(bool                            , m_bCanCreateGrenadeTrail                        , 0x11ED)
        SCHEMA_FIELD(ParticleIndex_t                 , m_nSnapshotTrajectoryEffectIndex                , 0x11F0)
        SCHEMA_FIELD(CStrongHandle<InfoForResourceTypeIParticleSnapshot>, m_hSnapshotTrajectoryParticleSnapshot           , 0x11F8)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_arrTrajectoryTrailPoints                      , 0x1200)
        SCHEMA_FIELD(CUtlVector<float32>             , m_arrTrajectoryTrailPointCreationTimes          , 0x1218)
        SCHEMA_FIELD(float                           , m_flTrajectoryTrailEffectCreationTime           , 0x1230)
    };

    class C_LightEnvironmentEntity : public C_LightDirectionalEntity {
    public:
    };

    class CCSGO_WingmanIntroCounterTerroristPosition : public CCSGO_WingmanIntroCharacterPosition {
    public:
    };

    class CCSGO_WingmanIntroTerroristPosition : public CCSGO_WingmanIntroCharacterPosition {
    public:
    };

    class CHostageRescueZone : public CHostageRescueZoneShim {
    public:
    };

    class C_CS2HudModelWeapon : public C_CS2HudModelBase {
    public:
    };

    class C_CS2HudModelArms : public C_CS2HudModelBase {
    public:
    };

    class C_PhysPropClientside : public C_BreakableProp {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_flTouchDelta                                  , 0x12D0)
        SCHEMA_FIELD(::GameTime_t                    , m_fDeathTime                                    , 0x12D4)
        SCHEMA_FIELD(VectorWS                        , m_vecDamagePosition                             , 0x12D8)
        SCHEMA_FIELD(::Vector                        , m_vecDamageDirection                            , 0x12E4)
        SCHEMA_FIELD(DamageTypes_t                   , m_nDamageType                                   , 0x12F0)
    };

    class C_DynamicProp : public C_BreakableProp {
    public:
        SCHEMA_FIELD(bool                            , m_bUseHitboxesForRenderBox                      , 0x12D0)
        SCHEMA_FIELD(bool                            , m_bUseAnimGraph                                 , 0x12D1)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputAnimBegun                              , 0x12D8)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputAnimOver                               , 0x12F0)
        SCHEMA_FIELD(CEntityIOOutput                 , m_pOutputAnimLoopCycleOver                      , 0x1308)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAnimReachedStart                            , 0x1320)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnAnimReachedEnd                              , 0x1338)
        SCHEMA_FIELD(::CUtlSymbolLarge               , m_iszIdleAnim                                   , 0x1350)
        SCHEMA_FIELD(AnimLoopMode_t                  , m_nIdleAnimLoopMode                             , 0x1358)
        SCHEMA_FIELD(bool                            , m_bRandomizeCycle                               , 0x135C)
        SCHEMA_FIELD(bool                            , m_bStartDisabled                                , 0x135D)
        SCHEMA_FIELD(bool                            , m_bFiredStartEndOutput                          , 0x135E)
        SCHEMA_FIELD(bool                            , m_bForceNpcExclude                              , 0x135F)
        SCHEMA_FIELD(bool                            , m_bCreateNonSolid                               , 0x1360)
        SCHEMA_FIELD(bool                            , m_bIsOverrideProp                               , 0x1361)
        SCHEMA_FIELD(std::int32_t                    , m_iInitialGlowState                             , 0x1364)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRange                                    , 0x1368)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowRangeMin                                 , 0x136C)
        SCHEMA_FIELD(::Color                         , m_glowColor                                     , 0x1370)
        SCHEMA_FIELD(std::int32_t                    , m_nGlowTeam                                     , 0x1374)
        SCHEMA_FIELD(std::int32_t                    , m_iCachedFrameCount                             , 0x1378)
        SCHEMA_FIELD(::Vector                        , m_vecCachedRenderMins                           , 0x137C)
        SCHEMA_FIELD(::Vector                        , m_vecCachedRenderMaxs                           , 0x1388)
    };

    class C_PhysicsProp : public C_BreakableProp {
    public:
        SCHEMA_FIELD(bool                            , m_bAwake                                        , 0x12D0)
    };

    class C_CSPlayerPawnBase : public C_BasePlayerPawn {
    public:
        SCHEMA_FIELD(CCSPlayer_PingServices*         , m_pPingServices                                 , 0x13C8)
        SCHEMA_FIELD(CSPlayerState                   , m_previousPlayerState                           , 0x13D0)
        SCHEMA_FIELD(CSPlayerState                   , m_iPlayerState                                  , 0x13D4)
        SCHEMA_FIELD(bool                            , m_bHasMovedSinceSpawn                           , 0x13D8)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastSpawnTimeIndex                          , 0x13DC)
        SCHEMA_FIELD(std::int32_t                    , m_iProgressBarDuration                          , 0x13E0)
        SCHEMA_FIELD(float                           , m_flProgressBarStartTime                        , 0x13E4)
        SCHEMA_FIELD(::GameTime_t                    , m_flClientDeathTime                             , 0x13E8)
        SCHEMA_FIELD(float                           , m_flFlashBangTime                               , 0x13EC)
        SCHEMA_FIELD(float                           , m_flFlashScreenshotAlpha                        , 0x13F0)
        SCHEMA_FIELD(float                           , m_flFlashOverlayAlpha                           , 0x13F4)
        SCHEMA_FIELD(bool                            , m_bFlashBuildUp                                 , 0x13F8)
        SCHEMA_FIELD(bool                            , m_bFlashDspHasBeenCleared                       , 0x13F9)
        SCHEMA_FIELD(bool                            , m_bFlashScreenshotHasBeenGrabbed                , 0x13FA)
        SCHEMA_FIELD(float                           , m_flFlashMaxAlpha                               , 0x13FC)
        SCHEMA_FIELD(float                           , m_flFlashDuration                               , 0x1400)
        SCHEMA_FIELD(::GameTime_t                    , m_flClientHealthFadeChangeTimestamp             , 0x1404)
        SCHEMA_FIELD(std::int32_t                    , m_nClientHealthFadeParityValue                  , 0x1408)
        SCHEMA_FIELD(float                           , m_fNextThinkPushAway                            , 0x140C)
        SCHEMA_FIELD(float                           , m_flCurrentMusicStartTime                       , 0x1414)
        SCHEMA_FIELD(float                           , m_flMusicRoundStartTime                         , 0x1418)
        SCHEMA_FIELD(bool                            , m_bDeferStartMusicOnWarmup                      , 0x141C)
        SCHEMA_FIELD(float                           , m_flLastSmokeOverlayAlpha                       , 0x1420)
        SCHEMA_FIELD(float                           , m_flLastSmokeAge                                , 0x1424)
        SCHEMA_FIELD(::Vector                        , m_vLastSmokeOverlayColor                        , 0x1428)
        SCHEMA_FIELD(CHandle<CCSPlayerController>    , m_hOriginalController                           , 0x1450)
    };

    class C_CSWeaponBase : public C_BasePlayerWeapon {
    public:
        SCHEMA_FIELD(WeaponGameplayAnimState         , m_iWeaponGameplayAnimState                      , 0x1758)
        SCHEMA_FIELD(::GameTime_t                    , m_flWeaponGameplayAnimStateTimestamp            , 0x175C)
        SCHEMA_FIELD(::GameTime_t                    , m_flInspectCancelCompleteTime                   , 0x1760)
        SCHEMA_FIELD(bool                            , m_bInspectPending                               , 0x1764)
        SCHEMA_FIELD(bool                            , m_bInspectShouldLoop                            , 0x1765)
        SCHEMA_FIELD(float                           , m_flCrosshairDistance                           , 0x1790)
        SCHEMA_FIELD(std::int32_t                    , m_iAmmoLastCheck                                , 0x1794)
        SCHEMA_FIELD(std::int32_t                    , m_nLastEmptySoundCmdNum                         , 0x1798)
        SCHEMA_FIELD(bool                            , m_bFireOnEmpty                                  , 0x179C)
        SCHEMA_FIELD(CEntityIOOutput                 , m_OnPlayerPickup                                , 0x17A0)
        SCHEMA_FIELD(CSWeaponMode                    , m_weaponMode                                    , 0x17B8)
        SCHEMA_FIELD(float                           , m_flTurningInaccuracyDelta                      , 0x17BC)
        SCHEMA_FIELD(::Vector                        , m_vecTurningInaccuracyEyeDirLast                , 0x17C0)
        SCHEMA_FIELD(float                           , m_flTurningInaccuracy                           , 0x17CC)
        SCHEMA_FIELD(float                           , m_fAccuracyPenalty                              , 0x17D0)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastAccuracyUpdateTime                      , 0x17D4)
        SCHEMA_FIELD(float                           , m_fAccuracySmoothedForZoom                      , 0x17D8)
        SCHEMA_FIELD(std::int32_t                    , m_iRecoilIndex                                  , 0x17DC)
        SCHEMA_FIELD(float                           , m_flRecoilIndex                                 , 0x17E0)
        SCHEMA_FIELD(bool                            , m_bBurstMode                                    , 0x17E4)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastBurstModeChangeTime                     , 0x17E8)
        SCHEMA_FIELD(::GameTick_t                    , m_nPostponeFireReadyTicks                       , 0x17EC)
        SCHEMA_FIELD(float                           , m_flPostponeFireReadyFrac                       , 0x17F0)
        SCHEMA_FIELD(bool                            , m_bInReload                                     , 0x17F4)
        SCHEMA_FIELD(::GameTick_t                    , m_nDeployTick                                   , 0x17F8)
        SCHEMA_FIELD(::GameTime_t                    , m_flDroppedAtTime                               , 0x17FC)
        SCHEMA_FIELD(bool                            , m_bIsHauledBack                                 , 0x1804)
        SCHEMA_FIELD(bool                            , m_bSilencerOn                                   , 0x1805)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeSilencerSwitchComplete                  , 0x1808)
        SCHEMA_FIELD(float                           , m_flWeaponActionPlaybackRate                    , 0x180C)
        SCHEMA_FIELD(std::int32_t                    , m_iOriginalTeamNumber                           , 0x1810)
        SCHEMA_FIELD(std::int32_t                    , m_iMostRecentTeamNumber                         , 0x1814)
        SCHEMA_FIELD(bool                            , m_bDroppedNearBuyZone                           , 0x1818)
        SCHEMA_FIELD(float                           , m_flNextAttackRenderTimeOffset                  , 0x181C)
        SCHEMA_FIELD(bool                            , m_bClearWeaponIdentifyingUGC                    , 0x18B8)
        SCHEMA_FIELD(bool                            , m_bVisualsDataSet                               , 0x18B9)
        SCHEMA_FIELD(bool                            , m_bUIWeapon                                     , 0x18BA)
        SCHEMA_FIELD(std::int32_t                    , m_nCustomEconReloadEventId                      , 0x18BC)
        SCHEMA_FIELD(::GameTime_t                    , m_nextPrevOwnerUseTime                          , 0x18C8)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_hPrevOwner                                    , 0x18CC)
        SCHEMA_FIELD(::GameTick_t                    , m_nDropTick                                     , 0x18D0)
        SCHEMA_FIELD(bool                            , m_bWasActiveWeaponWhenDropped                   , 0x18D4)
        SCHEMA_FIELD(bool                            , m_donated                                       , 0x18F4)
        SCHEMA_FIELD(::GameTime_t                    , m_fLastShotTime                                 , 0x18F8)
        SCHEMA_FIELD(bool                            , m_bWasOwnedByCT                                 , 0x18FC)
        SCHEMA_FIELD(bool                            , m_bWasOwnedByTerrorist                          , 0x18FD)
        SCHEMA_FIELD(float                           , m_flNextClientFireBulletTime                    , 0x1900)
        SCHEMA_FIELD(float                           , m_flNextClientFireBulletTime_Repredict          , 0x1904)
        SCHEMA_FIELD(C_IronSightController           , m_IronSightController                           , 0x1960)
        SCHEMA_FIELD(std::int32_t                    , m_iIronSightMode                                , 0x1A10)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastLOSTraceFailureTime                     , 0x1A88)
        SCHEMA_FIELD(float                           , m_flWatTickOffset                               , 0x1AE8)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastShakeTime                               , 0x1AFC)
    };

    class C_ItemDogtags : public C_Item {
    public:
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_OwningPlayer                                  , 0x17C8)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_KillingPlayer                                 , 0x17CC)
    };

    class C_DecoyProjectile : public C_BaseCSGrenadeProjectile {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nDecoyShotTick                                , 0x1238)
        SCHEMA_FIELD(std::int32_t                    , m_nClientLastKnownDecoyShotTick                 , 0x123C)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeParticleEffectSpawn                     , 0x1260)
    };

    class C_MolotovProjectile : public C_BaseCSGrenadeProjectile {
    public:
        SCHEMA_FIELD(bool                            , m_bIsIncGrenade                                 , 0x1238)
    };

    class C_FlashbangProjectile : public C_BaseCSGrenadeProjectile {
    public:
    };

    class C_SmokeGrenadeProjectile : public C_BaseCSGrenadeProjectile {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nSmokeEffectTickBegin                         , 0x1250)
        SCHEMA_FIELD(bool                            , m_bDidSmokeEffect                               , 0x1254)
        SCHEMA_FIELD(std::int32_t                    , m_nRandomSeed                                   , 0x1258)
        SCHEMA_FIELD(::Vector                        , m_vSmokeColor                                   , 0x125C)
        SCHEMA_FIELD(::Vector                        , m_vSmokeDetonationPos                           , 0x1268)
        SCHEMA_FIELD(C_NetworkUtlVectorBase<uint8>   , m_VoxelFrameData                                , 0x1278)
        SCHEMA_FIELD(std::int32_t                    , m_nVoxelFrameDataSize                           , 0x1290)
        SCHEMA_FIELD(std::int32_t                    , m_nVoxelUpdate                                  , 0x1294)
        SCHEMA_FIELD(bool                            , m_bSmokeVolumeDataReceived                      , 0x1298)
        SCHEMA_FIELD(bool                            , m_bSmokeEffectSpawned                           , 0x1299)
    };

    class C_HEGrenadeProjectile : public C_BaseCSGrenadeProjectile {
    public:
    };

    class CFuncRetakeBarrier : public C_DynamicProp {
    public:
    };

    class C_BasePropDoor : public C_DynamicProp {
    public:
        SCHEMA_FIELD(DoorState_t                     , m_eDoorState                                    , 0x13B0)
        SCHEMA_FIELD(bool                            , m_modelChanged                                  , 0x13B4)
        SCHEMA_FIELD(bool                            , m_bLocked                                       , 0x13B5)
        SCHEMA_FIELD(bool                            , m_bNoNPCs                                       , 0x13B6)
        SCHEMA_FIELD(::Vector                        , m_closedPosition                                , 0x13B8)
        SCHEMA_FIELD(::QAngle                        , m_closedAngles                                  , 0x13C4)
        SCHEMA_FIELD(CHandle<C_BasePropDoor>         , m_hMaster                                       , 0x13D0)
        SCHEMA_FIELD(::Vector                        , m_vWhereToSetLightingOrigin                     , 0x13D4)
    };

    class C_Chicken : public C_DynamicProp {
    public:
        SCHEMA_FIELD(CHandle<CBaseAnimGraph>         , m_hHolidayHatAddon                              , 0x13A8)
        SCHEMA_FIELD(bool                            , m_jumpedThisFrame                               , 0x13AC)
        SCHEMA_FIELD(CHandle<C_CSPlayerPawn>         , m_leader                                        , 0x13B0)
        SCHEMA_FIELD(C_AttributeContainer            , m_AttributeManager                              , 0x13B8)
        SCHEMA_FIELD(bool                            , m_bAttributesInitialized                        , 0x1888)
        SCHEMA_FIELD(ParticleIndex_t                 , m_hWaterWakeParticles                           , 0x188C)
        SCHEMA_FIELD(bool                            , m_bIsPreviewModel                               , 0x1890)
    };

    class C_DynamicPropAlias_cable_dynamic : public C_DynamicProp {
    public:
    };

    class C_DynamicPropAlias_dynamic_prop : public C_DynamicProp {
    public:
    };

    class C_DynamicPropAlias_prop_dynamic_override : public C_DynamicProp {
    public:
    };

    class C_PhysicsPropMultiplayer : public C_PhysicsProp {
    public:
    };

    class C_ShatterGlassShardPhysics : public C_PhysicsProp {
    public:
        SCHEMA_FIELD(shard_model_desc_t              , m_ShardDesc                                     , 0x12E8)
    };

    class C_CSObserverPawn : public C_CSPlayerPawnBase {
    public:
        SCHEMA_FIELD(CEntityHandle                   , m_hDetectParentChange                           , 0x1458)
    };

    class C_CSPlayerPawn : public C_CSPlayerPawnBase {
    public:
        SCHEMA_FIELD(CCSPlayer_BulletServices*       , m_pBulletServices                               , 0x1468)
        SCHEMA_FIELD(CCSPlayer_HostageServices*      , m_pHostageServices                              , 0x1470)
        SCHEMA_FIELD(CCSPlayer_BuyServices*          , m_pBuyServices                                  , 0x1478)
        SCHEMA_FIELD(CCSPlayer_GlowServices*         , m_pGlowServices                                 , 0x1480)
        SCHEMA_FIELD(CCSPlayer_ActionTrackingServices*, m_pActionTrackingServices                       , 0x1488)
        SCHEMA_FIELD(CCSPlayer_AimPunchServices*     , m_pAimPunchServices                             , 0x1490)
        SCHEMA_FIELD(CCSPlayer_DamageReactServices*  , m_pDamageReactServices                          , 0x1498)
        SCHEMA_FIELD(::GameTime_t                    , m_flHealthShotBoostExpirationTime               , 0x14A0)
        SCHEMA_FIELD(::GameTime_t                    , m_flLastFiredWeaponTime                         , 0x14A4)
        SCHEMA_FIELD(bool                            , m_bHasFemaleVoice                               , 0x14A8)
        SCHEMA_FIELD(float                           , m_flLandingTimeSeconds                          , 0x14AC)
        SCHEMA_FIELD(float                           , m_flOldFallVelocity                             , 0x14B0)
        SCHEMA_FIELD(char                            , m_szLastPlaceName                               , 0x14B4)
        SCHEMA_FIELD(bool                            , m_bPrevDefuser                                  , 0x14C6)
        SCHEMA_FIELD(bool                            , m_bPrevHelmet                                   , 0x14C7)
        SCHEMA_FIELD(std::int32_t                    , m_nPrevArmorVal                                 , 0x14C8)
        SCHEMA_FIELD(std::int32_t                    , m_nPrevGrenadeAmmoCount                         , 0x14CC)
        SCHEMA_FIELD(std::uint32_t                   , m_unPreviousWeaponHash                          , 0x14D0)
        SCHEMA_FIELD(std::uint32_t                   , m_unWeaponHash                                  , 0x14D4)
        SCHEMA_FIELD(bool                            , m_bInBuyZone                                    , 0x14D8)
        SCHEMA_FIELD(bool                            , m_bPreviouslyInBuyZone                          , 0x14D9)
        SCHEMA_FIELD(bool                            , m_bInLanding                                    , 0x14DA)
        SCHEMA_FIELD(float                           , m_flLandingStartTime                            , 0x14DC)
        SCHEMA_FIELD(bool                            , m_bInHostageRescueZone                          , 0x14E0)
        SCHEMA_FIELD(bool                            , m_bInBombZone                                   , 0x14E1)
        SCHEMA_FIELD(bool                            , m_bIsBuyMenuOpen                                , 0x14E2)
        SCHEMA_FIELD(::GameTime_t                    , m_flTimeOfLastInjury                            , 0x14E4)
        SCHEMA_FIELD(::GameTime_t                    , m_flNextSprayDecalTime                          , 0x14E8)
        SCHEMA_FIELD(std::int32_t                    , m_iRetakesOffering                              , 0x1640)
        SCHEMA_FIELD(std::int32_t                    , m_iRetakesOfferingCard                          , 0x1644)
        SCHEMA_FIELD(bool                            , m_bRetakesHasDefuseKit                          , 0x1648)
        SCHEMA_FIELD(bool                            , m_bRetakesMVPLastRound                          , 0x1649)
        SCHEMA_FIELD(std::int32_t                    , m_iRetakesMVPBoostItem                          , 0x164C)
        SCHEMA_FIELD(loadout_slot_t                  , m_RetakesMVPBoostExtraUtility                   , 0x1650)
        SCHEMA_FIELD(bool                            , m_bNeedToReApplyGloves                          , 0x1655)
        SCHEMA_FIELD(C_EconItemView                  , m_EconGloves                                    , 0x1658)
        SCHEMA_FIELD(std::uint8_t                    , m_nEconGlovesChanged                            , 0x1AC8)
        SCHEMA_FIELD(bool                            , m_bMustSyncRagdollState                         , 0x1AC9)
        SCHEMA_FIELD(std::int32_t                    , m_nRagdollDamageBone                            , 0x1ACC)
        SCHEMA_FIELD(::Vector                        , m_vRagdollDamageForce                           , 0x1AD0)
        SCHEMA_FIELD(::Vector                        , m_vRagdollDamagePosition                        , 0x1ADC)
        SCHEMA_FIELD(char                            , m_szRagdollDamageWeaponName                     , 0x1AE8)
        SCHEMA_FIELD(bool                            , m_bRagdollDamageHeadshot                        , 0x1B28)
        SCHEMA_FIELD(::Vector                        , m_vRagdollServerOrigin                          , 0x1B2C)
        SCHEMA_FIELD(::GameTime_t                    , m_lastLandTime                                  , 0x1B38)
        SCHEMA_FIELD(bool                            , m_bOnGroundLastTick                             , 0x1B3C)
        SCHEMA_FIELD(CHandle<C_CS2HudModelArms>      , m_hHudModelArms                                 , 0x1B58)
        SCHEMA_FIELD(::QAngle                        , m_qDeathEyeAngles                               , 0x1B5C)
        SCHEMA_FIELD(bool                            , m_bLeftHanded                                   , 0x1B68)
        SCHEMA_FIELD(::GameTime_t                    , m_fSwitchedHandednessTime                       , 0x1B6C)
        SCHEMA_FIELD(float                           , m_flViewmodelOffsetX                            , 0x1B70)
        SCHEMA_FIELD(float                           , m_flViewmodelOffsetY                            , 0x1B74)
        SCHEMA_FIELD(float                           , m_flViewmodelOffsetZ                            , 0x1B78)
        SCHEMA_FIELD(float                           , m_flViewmodelFOV                                , 0x1B7C)
        SCHEMA_FIELD(std::uint32_t                   , m_vecPlayerPatchEconIndices                     , 0x1B80)
        SCHEMA_FIELD(::Color                         , m_GunGameImmunityColor                          , 0x1BC8)
        SCHEMA_FIELD(CUtlVector<C_BulletHitModel*>   , m_vecBulletHitModels                            , 0x1C18)
        SCHEMA_FIELD(bool                            , m_bIsWalking                                    , 0x1C30)
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0x1C38)
        SCHEMA_FIELD(bool                            , m_bIsScoped                                     , 0x1C50)
        SCHEMA_FIELD(bool                            , m_bResumeZoom                                   , 0x1C51)
        SCHEMA_FIELD(bool                            , m_bIsDefusing                                   , 0x1C52)
        SCHEMA_FIELD(bool                            , m_bIsGrabbingHostage                            , 0x1C53)
        SCHEMA_FIELD(CSPlayerBlockingUseAction_t     , m_iBlockingUseActionInProgress                  , 0x1C54)
        SCHEMA_FIELD(::GameTime_t                    , m_flEmitSoundTime                               , 0x1C58)
        SCHEMA_FIELD(bool                            , m_bInNoDefuseArea                               , 0x1C5C)
        SCHEMA_FIELD(std::int32_t                    , m_nWhichBombZone                                , 0x1C60)
        SCHEMA_FIELD(std::int32_t                    , m_iShotsFired                                   , 0x1C64)
        SCHEMA_FIELD(float                           , m_flFlinchStack                                 , 0x1C68)
        SCHEMA_FIELD(float                           , m_flVelocityModifier                            , 0x1C6C)
        SCHEMA_FIELD(bool                            , m_bWaitForNoAttack                              , 0x1C70)
        SCHEMA_FIELD(float                           , m_ignoreLadderJumpTime                          , 0x1C74)
        SCHEMA_FIELD(bool                            , m_bKilledByHeadshot                             , 0x1C79)
        SCHEMA_FIELD(std::int32_t                    , m_ArmorValue                                    , 0x1C7C)
        SCHEMA_FIELD(std::uint16_t                   , m_unCurrentEquipmentValue                       , 0x1C80)
        SCHEMA_FIELD(std::uint16_t                   , m_unRoundStartEquipmentValue                    , 0x1C82)
        SCHEMA_FIELD(std::uint16_t                   , m_unFreezetimeEndEquipmentValue                 , 0x1C84)
        SCHEMA_FIELD(CEntityIndex                    , m_nLastKillerIndex                              , 0x1C88)
        SCHEMA_FIELD(bool                            , m_bOldIsScoped                                  , 0x1C8C)
        SCHEMA_FIELD(bool                            , m_bHasDeathInfo                                 , 0x1C8D)
        SCHEMA_FIELD(float                           , m_flDeathInfoTime                               , 0x1C90)
        SCHEMA_FIELD(::Vector                        , m_vecDeathInfoOrigin                            , 0x1C94)
        SCHEMA_FIELD(::GameTime_t                    , m_grenadeParameterStashTime                     , 0x1CD0)
        SCHEMA_FIELD(bool                            , m_bGrenadeParametersStashed                     , 0x1CD4)
        SCHEMA_FIELD(::QAngle                        , m_angStashedShootAngles                         , 0x1CD8)
        SCHEMA_FIELD(::Vector                        , m_vecStashedGrenadeThrowPosition                , 0x1CE4)
        SCHEMA_FIELD(::Vector                        , m_vecStashedVelocity                            , 0x1CF0)
        SCHEMA_FIELD(::QAngle                        , m_angShootAngleHistory                          , 0x1CFC)
        SCHEMA_FIELD(::Vector                        , m_vecThrowPositionHistory                       , 0x1D14)
        SCHEMA_FIELD(::Vector                        , m_vecVelocityHistory                            , 0x1D2C)
        SCHEMA_FIELD(bool                            , m_bShouldAutobuyDMWeapons                       , 0x3280)
        SCHEMA_FIELD(::GameTime_t                    , m_fImmuneToGunGameDamageTime                    , 0x3284)
        SCHEMA_FIELD(bool                            , m_bGunGameImmunity                              , 0x3288)
        SCHEMA_FIELD(::GameTime_t                    , m_fImmuneToGunGameDamageTimeLast                , 0x328C)
        SCHEMA_FIELD(float                           , m_fMolotovDamageTime                            , 0x3290)
        SCHEMA_FIELD(ParticleIndex_t                 , m_nPlayerInfernoBodyFx                          , 0x32FC)
        SCHEMA_FIELD(::QAngle                        , m_angEyeAngles                                  , 0x3370)
        SCHEMA_FIELD(::GameTime_t                    , m_arrOldEyeAnglesTimes                          , 0x3400)
        SCHEMA_FIELD(::QAngle                        , m_arrOldEyeAngles                               , 0x3410)
        SCHEMA_FIELD(::QAngle                        , m_angEyeAnglesVelocity                          , 0x3440)
        SCHEMA_FIELD(CEntityIndex                    , m_iIDEntIndex                                   , 0x344C)
        SCHEMA_FIELD(CountdownTimer                  , m_delayTargetIDTimer                            , 0x3450)
        SCHEMA_FIELD(CEntityIndex                    , m_iTargetItemEntIdx                             , 0x3468)
        SCHEMA_FIELD(CEntityIndex                    , m_iOldIDEntIndex                                , 0x346C)
        SCHEMA_FIELD(CountdownTimer                  , m_holdTargetIDTimer                             , 0x3470)
    };

    class C_C4 : public C_CSWeaponBase {
    public:
        SCHEMA_FIELD(ParticleIndex_t                 , m_activeLightParticleIndex                      , 0x1CB0)
        SCHEMA_FIELD(C4LightEffect_t                 , m_eActiveLightEffect                            , 0x1CB4)
        SCHEMA_FIELD(bool                            , m_bStartedArming                                , 0x1CB8)
        SCHEMA_FIELD(::GameTime_t                    , m_fArmedTime                                    , 0x1CBC)
        SCHEMA_FIELD(bool                            , m_bBombPlacedAnimation                          , 0x1CC0)
        SCHEMA_FIELD(bool                            , m_bIsPlantingViaUse                             , 0x1CC1)
        SCHEMA_FIELD(EntitySpottedState_t            , m_entitySpottedState                            , 0x1CC8)
        SCHEMA_FIELD(std::int32_t                    , m_nSpotRules                                    , 0x1CE0)
        SCHEMA_FIELD(bool                            , m_bPlayedArmingBeeps                            , 0x1CE4)
        SCHEMA_FIELD(bool                            , m_bBombPlanted                                  , 0x1CEB)
    };

    class C_Knife : public C_CSWeaponBase {
    public:
        SCHEMA_FIELD(bool                            , m_bFirstAttack                                  , 0x1CB0)
    };

    class C_BaseCSGrenade : public C_CSWeaponBase {
    public:
        SCHEMA_FIELD(bool                            , m_bClientPredictDelete                          , 0x1CB0)
        SCHEMA_FIELD(bool                            , m_bRedraw                                       , 0x1CB1)
        SCHEMA_FIELD(bool                            , m_bIsHeldByPlayer                               , 0x1CB2)
        SCHEMA_FIELD(bool                            , m_bPinPulled                                    , 0x1CB3)
        SCHEMA_FIELD(bool                            , m_bJumpThrow                                    , 0x1CB4)
        SCHEMA_FIELD(bool                            , m_bThrowAnimating                               , 0x1CB5)
        SCHEMA_FIELD(::GameTime_t                    , m_fThrowTime                                    , 0x1CB8)
        SCHEMA_FIELD(float                           , m_flThrowStrength                               , 0x1CC0)
        SCHEMA_FIELD(::GameTime_t                    , m_fDropTime                                     , 0x1D38)
        SCHEMA_FIELD(::GameTime_t                    , m_fPinPullTime                                  , 0x1D3C)
        SCHEMA_FIELD(bool                            , m_bJustPulledPin                                , 0x1D40)
        SCHEMA_FIELD(::GameTick_t                    , m_nNextHoldTick                                 , 0x1D44)
        SCHEMA_FIELD(float                           , m_flNextHoldFrac                                , 0x1D48)
        SCHEMA_FIELD(CHandle<C_CSWeaponBase>         , m_hSwitchToWeaponAfterThrow                     , 0x1D4C)
    };

    class C_WeaponBaseItem : public C_CSWeaponBase {
    public:
        SCHEMA_FIELD(bool                            , m_bSequenceInProgress                           , 0x1CB0)
        SCHEMA_FIELD(bool                            , m_bRedraw                                       , 0x1CB1)
    };

    class C_CSWeaponBaseGun : public C_CSWeaponBase {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_zoomLevel                                     , 0x1CB0)
        SCHEMA_FIELD(std::int32_t                    , m_iBurstShotsRemaining                          , 0x1CB4)
        SCHEMA_FIELD(std::int32_t                    , m_iSilencerBodygroup                            , 0x1CB8)
        SCHEMA_FIELD(std::int32_t                    , m_silencedModelIndex                            , 0x1CC8)
        SCHEMA_FIELD(bool                            , m_inPrecache                                    , 0x1CCC)
        SCHEMA_FIELD(bool                            , m_bNeedsBoltAction                              , 0x1CCD)
        SCHEMA_FIELD(std::int32_t                    , m_nRevolverCylinderIdx                          , 0x1CD0)
    };

    class C_CSWeaponBaseShotgun : public C_CSWeaponBase {
    public:
    };

    class C_PropDoorRotating : public C_BasePropDoor {
    public:
    };

    class C_CSGO_PreviewPlayer : public C_CSPlayerPawn {
    public:
        SCHEMA_FIELD(CGlobalSymbol                   , m_animgraphCharacterModeString                  , 0x3490)
        SCHEMA_FIELD(float                           , m_flInitialModelScale                           , 0x3498)
    };

    class C_MolotovGrenade : public C_BaseCSGrenade {
    public:
    };

    class C_Flashbang : public C_BaseCSGrenade {
    public:
    };

    class C_HEGrenade : public C_BaseCSGrenade {
    public:
    };

    class C_DecoyGrenade : public C_BaseCSGrenade {
    public:
    };

    class C_SmokeGrenade : public C_BaseCSGrenade {
    public:
    };

    class C_Item_Healthshot : public C_WeaponBaseItem {
    public:
    };

    class C_WeaponAWP : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponUMP45 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponG3SG1 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponFamas : public C_CSWeaponBaseGun {
    public:
    };

    class C_DEagle : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponM4A1Silencer : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponMag7 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponMP5SD : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponGalilAR : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponSG556 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponMAC10 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponAug : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponSSG08 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponBizon : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponUSPSilencer : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponRevolver : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponElite : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponCZ75a : public C_CSWeaponBaseGun {
    public:
        SCHEMA_FIELD(bool                            , m_bMagazineRemoved                              , 0x1CE0)
    };

    class C_WeaponP90 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponTec9 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponP250 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponSCAR20 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponHKP2000 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponMP7 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponM4A1 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponM249 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponTaser : public C_CSWeaponBaseGun {
    public:
        SCHEMA_FIELD(::GameTime_t                    , m_fFireTime                                     , 0x1CE0)
        SCHEMA_FIELD(std::int32_t                    , m_nLastAttackTick                               , 0x1CE4)
    };

    class C_WeaponNegev : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponFiveSeven : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponMP9 : public C_CSWeaponBaseGun {
    public:
    };

    class C_AK47 : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponGlock : public C_CSWeaponBaseGun {
    public:
    };

    class C_WeaponNOVA : public C_CSWeaponBaseShotgun {
    public:
    };

    class C_WeaponXM1014 : public C_CSWeaponBaseShotgun {
    public:
    };

    class C_WeaponSawedoff : public C_CSWeaponBaseShotgun {
    public:
    };

    class C_CSGO_TeamPreviewModel : public C_CSGO_PreviewPlayer {
    public:
    };

    class C_CSGO_PreviewPlayerAlias_csgo_player_previewmodel : public C_CSGO_PreviewPlayer {
    public:
    };

    class C_IncendiaryGrenade : public C_MolotovGrenade {
    public:
    };

}
