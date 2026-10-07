

#pragma once

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

#include <cstddef>
#include <cstdint>
#include <utility>

using int8 = std::int8_t;
using int16 = std::int16_t;
using int32 = std::int32_t;
using int64 = std::int64_t;
using uint8 = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;
using float32 = float;
using float64 = double;

using GameTime_t = float;
using GameTick_t = std::int32_t;

using PulseSymbol_t = std::uint64_t;
using PulseDocNodeID_t = std::uint32_t;
using PulseRuntimeChunkIndex_t = std::int32_t;
using PulseRegisterMap_t = std::uint64_t;
using WorldGroupId_t = std::uint32_t;
using ChangeAccessorFieldPathIndex_t = std::int32_t;

template <typename T>
using CHandle = std::uint32_t;

template <typename T>
using CStrongHandle = std::uint64_t;

template <typename T, typename A = void*>
class CUtlVector {
public:
    T* m_pElements;
    int m_Size;
    int m_Capacity;
};

template <typename T>
class CUtlLeanVector {
public:
    T* m_pElements;
    int m_Size;
};

template <typename T, int N>
class CUtlVectorFixedGrowable {
public:
    T m_Elements[N];
    int m_Size;
};

template <typename K, typename V, typename L = void*>
class CUtlOrderedMap {
public:
    std::uint8_t m_Data[64];
};

template <typename K, typename V = K, typename H = void*, typename E = void*>
class CUtlHashtable {
public:
    std::uint8_t m_Data[64];
};

template <typename T>
class CAnimNetVar {
public:
    T m_Value;
};

template <typename T>
class CAnimValue {
public:
    T m_Value;
};

template <typename T, typename A = void*>
class CUtlVectorEmbeddedNetworkVar {
public:
    T* m_pElements;
    int m_Size;
    int m_Capacity;
};

template <typename T>
using C_UtlVectorEmbeddedNetworkVar = CUtlVectorEmbeddedNetworkVar<T>;

template <typename T, typename A = void*>
class CNetworkUtlVectorBase {
public:
    T* m_pElements;
    int m_Size;
};

template <typename T>
using C_NetworkUtlVectorBase = CNetworkUtlVectorBase<T>;

class CNetworkVarChainer {
public:
    std::uint8_t m_Data[64];
};

class CUtlString {
public:
    const char* m_pString;
};

class CUtlSymbolLarge {
public:
    std::uint64_t m_Id;
};

class CUtlBinaryBlock {
public:
    void* m_pData;
    int m_Size;
};

class CBufferString {
public:
    char m_buffer[256];
};

template <typename T>
class CVariantBase {
};

template <typename T>
class CAnimScriptParam {
};

template <typename T>
class CResourcePointer {
};

template <typename T>
class CResourceArray {
};

class Attribute_t {
public:
    std::uint8_t m_Data[16];
};

class CUtlSymbol {
public:
    std::uint32_t m_Id;
};

class CUtlStringTokenWithStorage {
public:
    std::uint64_t m_Id;
};

class CResourceString {
public:
    const char* m_pString;
};

class KeyValues {
public:
    void* m_pData;
};

class CEntityNameString {
public:
    const char* m_pString;
};

class CEntityKeyValues {
public:
    void* m_pData;
};

class IPhysicsJoint {
public:
    void* m_pData;
};

class CBaseAnimGraphDestructibleParts_GraphController {
public:
    std::uint8_t m_Data[8];
};

class CEntityAttributeTable {
public:
    std::uint8_t m_Data[8];
};

class CNetworkTransmitComponent {
public:
    std::uint8_t m_Data[8];
};

class thinkfunc_t {
public:
    std::uint8_t m_Data[8];
};

class CNetworkVelocityVector {
public:
    std::uint8_t m_Data[8];
};

class CParticleProperty {
public:
    std::uint8_t m_Data[8];
};

enum class TakeDamageFlags_t : std::uint64_t {};
enum class EntityPlatformTypes_t : std::uint8_t {};
enum class MoveCollide_t : std::uint8_t {};
enum class MoveType_t : std::uint8_t {};
enum class BloodType : std::int32_t {};

struct PulseCursorID_t {
    std::uint32_t m_Id;
};

struct ParticleParamID_t {
    std::uint32_t m_Id;
};

enum class PhysInterfaceId_t : std::uint32_t {};

enum class CCSPlayerAnimationState_MoveType_t : std::uint8_t {};
enum class CCSPlayerAnimationState_GroundMoveState_t : std::uint8_t {};
enum class CCSPlayerAnimationState_Direction_t : std::uint8_t {};
enum class CCSPlayerAnimationState_AirAction_t : std::uint8_t {};

struct fltx4 {
    std::uint32_t v[4];
};

struct RotationVector {
    float x, y, z;
};

struct RadianEuler {
    float x, y, z;
};

struct DegreeEuler {
    float x, y, z;
};

template <typename T>
class CSmartPtr {
public:
    T* m_pData;
};

template <typename T>
class CRelativeArray {
public:
    std::int32_t m_nOffset;
    std::int32_t m_nCount;
};

template <typename T, int N>
class CUtlLeanVectorFixedGrowable {
public:
    T m_Elements[N];
    int m_Size;
    int m_Capacity;
};

struct Vector {
    float x, y, z;
};

struct Vector2D {
    float x, y;
};

struct Vector4D {
    float x, y, z, w;
};

struct QAngle {
    float x, y, z;
};

struct Quaternion {
    float x, y, z, w;
};

struct matrix3x4_t {
    float m[3][4];
};

struct matrix3x4a_t {
    float m[3][4];
};

struct Color {
    std::uint8_t r, g, b, a;
};

struct AABB_t {
    Vector m_vMinBounds;
    Vector m_vMaxBounds;
};

struct CRenderBufferBinding {
    std::uint64_t m_hBuffer;
    std::uint32_t m_nBindOffsetBytes;
};

class CGlobalSymbol {
public:
    std::uint64_t m_Id;
};

class CColorGradient {
public:
    std::uint8_t m_Data[64];
};

class CPiecewiseCurve {
public:
    std::uint8_t m_Data[64];
};

class KeyValues3 {
public:
    void* m_pData;
};

struct CMaterialDrawDescriptor {
    std::uint8_t m_Data[128];
};

struct CMeshletDescriptor {
    std::uint8_t m_Data[64];
};

struct RTProxyDrawDescriptor_t {
    std::uint8_t m_Data[64];
};

class InfoForResourceTypeIPulseGraphDef {};
class InfoForResourceTypeCModel {};
class InfoForResourceTypeCRenderMesh {};
class InfoForResourceTypeCCompositeMaterialKit {};
class InfoForResourceTypeCCompositeMaterial {};
class InfoForResourceTypeCNmSkeleton {};
class InfoForResourceTypeIMaterial2 {};
class InfoForResourceTypeIParticleSystemDefinition {};
class InfoForResourceTypeIParticleSnapshot {};
class InfoForResourceTypeCNmGraphDefinition {};
class InfoForResourceTypeCNmClip {};
class InfoForResourceTypeCEntityLump {};
class InfoForResourceTypeCChoreoSceneResource {};
class InfoForResourceTypeCPostProcessingResource {};

using CStrongHandleVoid = std::uint64_t;

template <typename T>
class CStrongHandleCopyable {
public:
    std::uint64_t m_hHandle;
};

template <typename T>
class CWeakHandle {
public:
    std::uint64_t m_hHandle;
};

template <typename T>
class CResourceNameTyped {
public:
    std::uint64_t m_nHashCode;
};

using QuaternionStorage = Quaternion;
using VectorWS = Vector;
using VectorAligned = Vector;

class CAnimParamHandle {
public:
    std::uint16_t m_Index;
};

class CAnimInputDamping {
public:
    float m_flSpeedFunction;
    float m_flSpeedScale;
};

class CTransform {
public:
    Vector m_vPosition;
    Quaternion m_orientation;
};

class CNmTarget {
public:
    std::uint8_t m_Data[48];
};

class CParticleNamedValueRef {
public:
    std::uint8_t m_Data[64];
};

class CPulseValueFullType {
public:
    std::uint8_t m_Data[24];
};

class CPulse_Variable {
public:
    std::uint8_t m_Data[32];
};

class CPulse_PublicOutput {
public:
    std::uint8_t m_Data[32];
};

class CPulse_Constant {
public:
    std::uint8_t m_Data[32];
};

class CPulse_DomainValue {
public:
    std::uint8_t m_Data[32];
};

class CPulse_Chunk {
public:
    std::uint8_t m_Data[64];
};

class CPulseCell_Base {
public:
    std::uint8_t m_Data[64];
};

class CPulse_InvokeBinding {
public:
    std::uint8_t m_Data[64];
};

class CPulse_CallInfo {
public:
    std::uint8_t m_Data[64];
};

class CPulse_BlackboardReference {
public:
    std::uint8_t m_Data[64];
};

class CPulse_OutputConnection {
public:
    std::uint8_t m_Data[64];
};

class CPulse_OutflowConnection {
public:
    std::uint8_t m_Data[72];
};

class CPulse_ResumePoint {
public:
    std::uint8_t m_Data[72];
};

class CPulseRuntimeMethodArg {
public:
    std::uint8_t m_Data[32];
};

using PulseRuntimeCellIndex_t = std::int32_t;
using PulseRuntimeBlackboardReferenceIndex_t = std::int16_t;
using PulseRuntimeOutputIndex_t = std::int32_t;
using PulseRuntimeVarIndex_t = std::int32_t;
using MeshDrawPrimitiveFlags_t = std::uint32_t;
using VertexAlbedoFormat_t = std::uint8_t;
using AnimParamID = std::uint32_t;
using AnimNodeID = std::uint32_t;
using ParticleModelType_t = std::uint32_t;
using PulseMethodCallMode_t = std::uint32_t;
using NmIKBlendMode_t = std::uint32_t;
using AnimValueSource = std::uint32_t;
using OrientationWarpMode_t = std::uint32_t;
using OrientationWarpTargetOffsetMode_t = std::uint32_t;
using OrientationWarpRootMotionSource_t = std::uint32_t;
using fieldtype_t = std::uint32_t;
using ParticleAttributeIndex_t = std::int32_t;
using ParticleIndex_t = std::int32_t;

class SceneEventId_t {
public:
    std::uint32_t m_nSceneEventId;
};

class SndOpEventGuid_t {
public:
    std::uint64_t m_nGuid;
};

class CNetworkViewOffsetVector {
public:
    Vector m_vecOffset;
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

enum class RenderMode_t : std::uint8_t {
    kRenderNormal = 0x0,
    kRenderTransAlpha = 0x1,
    kRenderNone = 0x2,
    kRenderModeCount = 0x3,
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

enum class DecalRtEncoding_t : std::uint8_t {
    DECAL_RT_ENCODING_NONE = 0x0,
    DECAL_RT_ENCODING_NORMAL = 0x1,
    DECAL_RT_ENCODING_EMISSIVE = 0x2,
};

enum class PointOrientGoalDirectionType_t : std::uint32_t {};
enum class PointOrientConstraint_t : std::uint32_t {};
enum class ValueRemapperInputType_t : std::uint32_t {};
enum class ValueRemapperOutputType_t : std::uint32_t {};
enum class ValueRemapperHapticsType_t : std::uint32_t {};
enum class ValueRemapperMomentumType_t : std::uint32_t {};
enum class ValueRemapperRatchetType_t : std::uint32_t {};
enum class PlayerConnectedState : std::uint32_t {};
enum class EntityDisolveType_t : std::uint32_t {};
enum class GrenadeType_t : std::uint32_t {};
enum class BeamType_t : std::uint32_t {};
enum class BeamClipStyle_t : std::uint32_t {};

template <int N>
class CBitVec {
public:
    std::uint32_t m_Data[(N + 31) / 32];
};

class CSoundPatch;
enum class C_BaseCombatCharacter_WaterWakeMode_t : std::uint32_t {};
enum class DamageTypes_t : std::uint32_t {};
enum class WeaponGameplayAnimState : std::uint32_t {};
enum class CSWeaponMode : std::uint32_t {};
enum class DoorState_t : std::uint32_t {};
enum class CSPlayerBlockingUseAction_t : std::uint32_t {};
class CParticleCollectionFloatInput;
class CPerParticleFloatInput;
class CParticleCollectionVecInput;
enum class ParticleColorBlendType_t : std::uint32_t {};
class CPerParticleVecInput;
class CParticleRemapFloatInput;
enum class ParticleSetMethod_t : std::uint32_t {};
class CParticleCollectionRendererFloatInput;
class CParticleCollectionRendererVecInput;
enum class ParticleNamedValueSource_t : std::uint32_t {};
enum class ParticleDirectionNoiseType_t : std::uint32_t {};
enum class AnimationType_t : std::uint32_t {};
enum class IChoreoServices_ScriptState_t : std::uint32_t {};
enum class IChoreoServices_ChoreoState_t : std::uint32_t {};
class CGenericShapeProxy;
template <int N> class CTypedBitVec;
using BASEPTR = void*;
using ENTITYFUNCPTR = void*;
using USEPTR = void*;
enum class ScriptedMoveTo_t : std::uint32_t {};
enum class SharedMovementGait_t : std::uint32_t {};
enum class ScriptedHeldWeaponBehavior_t : std::uint32_t {};
enum class ESceneViewDebugOverlaysListenerDataType_t : std::uint32_t {};
enum class soundlevel_t : std::uint32_t {};
class CVariantDefaultAllocator;
enum class CFuncMover_Move_t : std::uint32_t {};
enum class CFuncMover_OrientationUpdate_t : std::uint32_t {};
enum class CFuncMover_TransitionToPathNodeAction_t : std::uint32_t {};
enum class CFuncMover_FollowEntityDirection_t : std::uint32_t {};
enum class CFuncMover_FollowConstraint_t : std::uint32_t {};
enum class CFuncRotator_Rotate_t : std::uint32_t {};
class IPhysicsBody;
enum class CLogicBranchList_LogicBranchListenerLastState_t : std::uint32_t {};
enum class INavObstacle_NavObstacleType_t : std::uint32_t {};
class constraint_hingeparams_t;
enum class JointMotion_t : std::uint32_t {};
enum class DynamicContinuousContactBehavior_t : std::uint32_t {};
enum class CPhysicsProp_CrateType_t : std::uint32_t {};
class InfoForResourceTypeCVoiceContainerBase;
class InfoForResourceTypeCVMixListResource;
template<typename T> class CSteamAudioMovableBakedData;
class IPLCompressedEnergyFields;
class IPLProbeBatch;
class IPLScene;
class IPLStaticMesh;
class FourVectors;
class FourQuaternions;
template<typename T> class SphereBase_t;
class CUtlVectorSIMDPaddedVector;
enum class ParticleColorBlendMode_t : std::uint32_t {};
class CParticleTransformInput;
class CParticleVariableRef;
class CParticleModelInput;

class CAnimGraphControllerManager;
class CAnimGraphControllerBase;
class IPhysicsRagdollControl;
class SceneRequestHandle_t;
class SceneOpportunityHandle_t;
class CCSPlayerAnimationState;
using HSCRIPT = void*;

enum class PointTemplateClientOnlyEntityBehavior_t : std::uint32_t {};
enum class PointTemplateOwnerSpawnGroupType_t : std::uint32_t {};
enum class QuestProgress_Reason : std::uint32_t {};
enum class PointWorldTextJustifyHorizontal_t : std::uint32_t {};
enum class PointWorldTextJustifyVertical_t : std::uint32_t {};
enum class PointWorldTextReorientMode_t : std::uint32_t {};

class CMotionTransform {
public:
    Vector m_vPosition;
    Quaternion m_qOrientation;
    float m_flScale;
};

class RenderInputLayoutField_t {
public:
    std::uint8_t m_Data[32];
};

class CAnimVariant {
public:
    std::uint8_t m_Data[32];
};

class CGlobalSymbolCaseSensitive {
public:
    std::uint64_t m_Id;
};

class InfoForResourceTypeCTextureBase {
public:
    std::uint8_t m_Data[8];
};

class InfoForResourceTypeCAnimData {
public:
    std::uint8_t m_Data[8];
};

class RnSphereDesc_t {
public:
    std::uint8_t m_Data[32];
};

class RnCapsuleDesc_t {
public:
    std::uint8_t m_Data[32];
};

class RnHullDesc_t {
public:
    std::uint8_t m_Data[64];
};

class RnMeshDesc_t {
public:
    std::uint8_t m_Data[64];
};

class RnSoftbodyParticle_t {
public:
    std::uint8_t m_Data[32];
};

class RnSoftbodySpring_t {
public:
    std::uint8_t m_Data[16];
};

class RnSoftbodyCapsule_t {
public:
    std::uint8_t m_Data[32];
};

class CNmVectorInfoNode_Info_t {
public:
    std::uint8_t m_Data[4];
};

class CNmFloatAngleMathNode_Operation_t {
public:
    std::uint8_t m_Data[4];
};

class CNmFloatMathNode_Operator_t {
public:
    std::uint8_t m_Data[4];
};

class CNmTargetInfoNode_Info_t {
public:
    std::uint8_t m_Data[4];
};

class CSplitScreenSlot {
public:
    std::uint8_t m_Data[8];
};

class CUtlStringToken {
public:
    std::uint32_t m_nHashCode;
};

class CResourceName {
public:
    std::uint64_t m_nHashCode;
};

class CNmTimeConditionNode_ComparisonType_t {
public:
    std::uint8_t m_Data[4];
};

class CNmTimeConditionNode_Operator_t {
public:
    std::uint8_t m_Data[4];
};

class CNmSyncEventIndexConditionNode_TriggerMode_t {
public:
    std::uint8_t m_Data[4];
};

class CModelAnimNameWithDeltas {
public:
    std::uint8_t m_Data[32];
};

class CNmParticleEvent_Type_t {
public:
    std::uint8_t m_Data[4];
};

class CNmStateNode_TimedEvent_t_Comparison_t {
public:
    std::uint8_t m_Data[4];
};

class CKV3MemberNameWithStorage {
public:
    std::uint8_t m_Data[64];
};

class CRotation {
public:
    std::uint8_t m_Data[4];
};

class InfoForResourceTypeCPhysAggregateData {
public:
    std::uint8_t m_Data[8];
};

class InfoForResourceTypeCAnimationGroup {
public:
    std::uint8_t m_Data[8];
};

class InfoForResourceTypeCSequenceGroupData {
public:
    std::uint8_t m_Data[8];
};

class CRangeFloat {
public:
    float m_flMin;
    float m_flMax;
};

class Range_t {
public:
    float m_flMin;
    float m_flMax;
};

struct PackedAABB_t {
    std::uint32_t m_nPackedMin;
    std::uint32_t m_nPackedMax;
};

struct CEntityIndex {
    std::int32_t m_Value;
};

struct PhysFeModelDesc_t {
    std::uint8_t m_Data[128];
};

enum class RenderPrimitiveType_t : std::uint32_t {
    RENDER_PRIM_TRIANGLES = 0,
    RENDER_PRIM_POINTS = 1,
    RENDER_PRIM_LINES = 2,
    RENDER_PRIM_TRIANGLE_STRIP = 3,
};

class CKV3MemberNameSet {
public:
    std::uint8_t m_Data[32];
};

class IParticleCollection {
public:
    virtual ~IParticleCollection() = default;
    std::uint8_t m_Data[128];
};

template <typename T>
class CCompressor {
public:
    std::uint8_t m_Data[64];
};

using CNmSoundEvent_Position_t = std::uint8_t;
using CNmRootMotionData_SamplingMode_t = std::uint8_t;
using CNmFloatComparisonNode_Comparison_t = std::uint8_t;
using CNmIDComparisonNode_Comparison_t = std::uint8_t;
using CNmTargetWarpNode_TargetUpdateRule_t = std::uint8_t;
using CNmFloatAngleMathNode_Operator_t = std::uint8_t;
using CNmFloatMathNode_Operation_t = std::uint8_t;
using CNmTimeConditionNode_Comparison_t = std::uint8_t;
using CNmSyncEventIndexConditionNode_Comparison_t = std::uint8_t;
using CNmStateNode_Comparison_t = std::uint8_t;
using CNmCurrentSyncEventNode_Mode_t = std::uint8_t;
using CNmCurrentSyncEventNode_InfoType_t = std::uint8_t;
using CNmVectorInfoNode_Component_t = std::uint8_t;
using CNmTargetInfoNode_Info_e = std::uint32_t;
using CNmParticleEvent_Mode_t = std::uint32_t;
using CNmTransitionNode_Flags_t = std::uint8_t;
using CNmEventTargetEntity_t = std::uint32_t;
using CNmRootMotionOverrideNode_Flags_t = std::uint8_t;
using MedalRank_t = std::uint32_t;

class CPlayerPawnComponent {
public:
    std::uint8_t m_Data[8];
};

class CPlayerControllerComponent {
public:
    std::uint8_t m_Data[8];
};

class CEntityIOOutput {
public:
    std::uint8_t m_Data[64];
};

template <typename T>
class CEntityOutputTemplate {
public:
    std::uint8_t m_Data[64];
};

struct PointCameraSettings_t {
    std::uint8_t m_Data[64];
};

struct C4LightEffect_t {
    std::uint8_t m_Data[32];
};

struct CSPlayerState {
    std::uint8_t m_Data[32];
};

using PerformanceMode_t = std::uint32_t;

using BreakableContentsType_t = std::uint32_t;

using ParticleAttachment_t = std::uint32_t;

using PrecipitationFilter_t = std::uint32_t;

using ObserverInterpState_t = std::uint32_t;

using HSequence = std::uint32_t;

using AnimLoopMode_t = std::uint32_t;

class CInButtonState {
public:
    std::uint64_t m_pnButtons[3];
};

using AnimationAlgorithm_t = std::uint32_t;

using ExternalAnimGraphHandle_t = std::uint32_t;

class CNetworkedQuantizedFloat {
public:
    float m_flValue;
};

using SequenceFinishNotifyState_t = std::uint32_t;

using ResourceId_t = std::uint64_t;

class CSkeletonAnimationController {
public:
    std::uint8_t m_Data[128];
};

class CNmGraphInstance {
public:
    std::uint8_t m_Data[256];
};

struct ExternalAnimGraph_t {
    std::uint8_t m_Data[64];
};

class IPhysicsMotionController {
public:
    virtual ~IPhysicsMotionController() = default;
    std::uint8_t m_Data[64];
};

struct filter_t {
    std::uint8_t m_Data[32];
};

struct SoundeventPathCornerPairNetworked_t {
    std::uint8_t m_Data[32];
};

using ModelConfigHandle_t = std::uint32_t;

using SolidType_t = std::uint8_t;

using SurroundingBoundsType_t = std::uint8_t;

enum class ShardSolid_t : std::uint8_t {
    SHARD_SOLID = 0x0,
    SHARD_DEBRIS = 0x1,
};

enum class FixAngleSet_t : std::uint8_t {
    None = 0x0,
    Absolute = 0x1,
    Relative = 0x2,
};

template <typename T>
class CAnimGraph2ParamOptionalRef {
public:
    std::uint8_t m_Data[24];
};

class CAnimGraph2ParamAutoResetOptionalRef {
public:
    std::uint8_t m_Data[24];
};

using attributeprovidertypes_t = std::uint32_t;
using ENPCBehaviorOverride_t = std::uint32_t;
using InteractionPriority_t = std::uint32_t;
using CSWeaponType = std::uint32_t;
using CSWeaponCategory = std::uint32_t;
using gear_slot_t = std::uint32_t;
using loadout_slot_t = std::uint32_t;
using CSWeaponSilencerType = std::uint32_t;

class CFiringModeFloat {
public:
    float m_flValues[2];
};

class CFiringModeInt {
public:
    std::int32_t m_nValues[2];
};

class CSkillFloat {
public:
    float m_flValue;
};

class CTransformWS {
public:
    Vector m_vPosition;
    Quaternion m_qOrientation;
};

class CNetworkOriginCellCoordQuantizedVector {
public:
    std::uint16_t m_cellX;
    std::uint16_t m_cellY;
    std::uint16_t m_cellZ;
    std::uint16_t m_nOutsideWorld;
    Vector m_vecX;
    Vector m_vecY;
    Vector m_vecZ;
};

class CEntityHandle {
public:
    std::uint32_t m_Index;
};

class CPlayerSlot {
public:
    std::int32_t m_Value;
};

class IPhysAggregateInstance {
public:
    virtual ~IPhysAggregateInstance() = default;
    std::uint8_t m_Data[64];
};

enum class ObserverMode_t : std::uint32_t {
    OBS_MODE_NONE = 0,
    OBS_MODE_FIXED = 1,
    OBS_MODE_IN_EYE = 2,
    OBS_MODE_CHASE = 3,
    OBS_MODE_ROAMING = 4,
};

class CSoundEventName {
public:
    std::uint8_t m_Data[32];
};

using AttachmentHandle_t = std::uint16_t;

enum class TimelineCompression_t : std::uint32_t {
    TIMELINE_COMPRESSION_SUM = 0,
    TIMELINE_COMPRESSION_COUNT_PER_INTERVAL = 1,
    TIMELINE_COMPRESSION_AVERAGE = 2,
    TIMELINE_COMPRESSION_AVERAGE_BLEND = 3,
    TIMELINE_COMPRESSION_TOTAL = 4,
};

enum class EKillTypes_t : std::uint32_t {
    KILL_NONE = 0,
    KILL_DEFAULT = 1,
    KILL_HEADSHOT = 2,
    KILL_BLAST = 3,
    KILL_BURN = 4,
    KILL_SLASH = 5,
};

enum class WeaponSound_t : std::uint32_t {
    WEAPON_SOUND_EMPTY = 0,
    WEAPON_SOUND_SINGLE_SHOT = 1,
    WEAPON_SOUND_SINGLE_SHOT_NPC = 2,
    WEAPON_SOUND_DOUBLE_SHOT = 3,
    WEAPON_SOUND_DOUBLE_SHOT_NPC = 4,
    WEAPON_SOUND_BURST = 5,
    WEAPON_SOUND_RELOAD = 6,
    WEAPON_SOUND_RELOAD_NPC = 7,
    WEAPON_SOUND_MELEE_MISS = 8,
    WEAPON_SOUND_MELEE_HIT = 9,
    WEAPON_SOUND_MELEE_HIT_WORLD = 10,
    WEAPON_SOUND_SPECIAL1 = 11,
    WEAPON_SOUND_SPECIAL2 = 12,
    WEAPON_SOUND_SPECIAL3 = 13,
    WEAPON_SOUND_TAUNT = 14,
    WEAPON_SOUND_DEPLOY = 15,
};

class CAttachmentNameSymbolWithStorage {
public:
    std::uint8_t m_Data[64];
};

enum class ItemFlagTypes_t : std::uint32_t {
    ITEM_FLAG_NONE = 0,
    ITEM_FLAG_CAN_SELECT_WITH_USE = 1,
    ITEM_FLAG_NOAUTORELOAD = 2,
    ITEM_FLAG_NOAUTOSWITCHEMPTY = 4,
    ITEM_FLAG_LIMITINWORLD = 8,
    ITEM_FLAG_EXHAUSTIBLE = 16,
    ITEM_FLAG_DOHITLOCATIONDMG = 32,
    ITEM_FLAG_NOAMMOPICKUPS = 64,
    ITEM_FLAG_NOITEMPICKUP = 128,
};

using AmmoIndex_t = std::int32_t;

enum class RumbleEffect_t : std::uint32_t {
    RUMBLE_INVALID = 0xFFFFFFFF,
    RUMBLE_STOP_ALL = 0,
    RUMBLE_PISTOL = 1,
    RUMBLE_357 = 2,
    RUMBLE_SMG1 = 3,
    RUMBLE_AR2 = 4,
    RUMBLE_SHOTGUN_SINGLE = 5,
    RUMBLE_SHOTGUN_DOUBLE = 6,
    RUMBLE_AR2_ALT_FIRE = 7,
    RUMBLE_RPG_MISSILE = 8,
    RUMBLE_CROWBAR_SWING = 9,
    RUMBLE_AIRBOAT_GUN = 10,
    RUMBLE_JEEP_ENGINE_LOOP = 11,
    RUMBLE_FLAT_LEFT = 12,
    RUMBLE_FLAT_RIGHT = 13,
    RUMBLE_FLAT_BOTH = 14,
    RUMBLE_DMG_LOW = 15,
    RUMBLE_DMG_MED = 16,
    RUMBLE_DMG_HIGH = 17,
    RUMBLE_FALL_LONG = 18,
    RUMBLE_FALL_SHORT = 19,
    RUMBLE_PHYSCANNON_OPEN = 20,
    RUMBLE_PHYSCANNON_PUNT = 21,
    RUMBLE_PHYSCANNON_LOW = 22,
    RUMBLE_PHYSCANNON_MEDIUM = 23,
    RUMBLE_PHYSCANNON_HIGH = 24,
};

namespace cs2::sdk {

    template <typename T>
    struct const_field_type {
        using type = const T&;
    };

    template <typename T>
    struct const_field_type<T*> {
        using type = T* const&;
    };

    template <typename T>
    inline T& field_ref(void* base, std::ptrdiff_t off) noexcept {
        return *reinterpret_cast<T*>(reinterpret_cast<std::byte*>(base) + off);
    }

    template <typename T>
    inline typename const_field_type<T>::type field_ref(const void* base, std::ptrdiff_t off) noexcept {
        return *reinterpret_cast<T*>(const_cast<std::byte*>(reinterpret_cast<const std::byte*>(base)) + off);
    }

}

#define SCHEMA_FIELD(TYPE, NAME, OFFSET)                                           \
    inline TYPE&       NAME()       noexcept { return ::cs2::sdk::field_ref<TYPE>(this, (OFFSET)); } \
    inline auto        NAME() const noexcept -> decltype(::cs2::sdk::field_ref<TYPE>(this, (OFFSET))) { return ::cs2::sdk::field_ref<TYPE>(this, (OFFSET)); }

#define SCHEMA_PAD(NAME, SIZE) std::byte NAME[(SIZE)]
