

#pragma once
#include "cs2sdk_macros.hpp"

namespace cs2::sdk::vphysics2 {

    inline constexpr std::uint32_t CS2_BUILD = 14160;

    class RnSphereDesc_t;
    class RnSoftbodyParticle_t;
    class RnHullDesc_t;
    class RnCapsuleDesc_t;
    class PhysFeModelDesc_t;
    class RnMeshDesc_t;
    class RnSoftbodySpring_t;
    class RnSoftbodyCapsule_t;
    class vphysics_save_cphysicsbody_t;
    class FeBuildBoxRigid_t;
    class CFeIndexedJiggleBone;
    class IPhysAggregateInstance;
    class FeBandBendLimit_t;
    class FeTaperedCapsuleStretch_t;
    class constraint_axislimit_t;
    class FeSimdRodConstraintAnim_t;
    class FeSimdRodConstraint_t;
    class IPhysicsParticleRope;
    class constraint_hingeparams_t;
    class IPhysicsBodyList;
    class FeBuildSphereRigid_t;
    class FeSimdAnimStrayRadius_t;
    class RnTriangle_t;
    class FeProxyVertexMap_t;
    class FeNodeIntegrator_t;
    class RnCapsule_t;
    class CFeNamedJiggleBone;
    class FeAntiTunnelProbeBuild_t;
    class RnBodyDesc_t;
    class OldFeEdge_t;
    class FeFollowNode_t;
    class RnMesh_t;
    class VertexPositionNormal_t;
    class IPhysicsRagdollControl;
    class FeBuildSDFRigid_t;
    class RnBlendVertex_t;
    class CFeMorphLayer;
    class FeCtrlSoftOffset_t;
    class FeVertexMapDesc_t;
    class FeTaperedCapsuleRigid_t;
    class FeAnimStrayRadius_t;
    class IPhysicsJoint;
    class FeEdgeDesc_t;
    class FeNodeStrayBox_t;
    class FeNodeReverseOffset_t;
    class RnPlane_t;
    class FeSDFRigid_t;
    class CFeJiggleBone;
    class CRegionSVM;
    class FeWorldCollisionParams_t;
    class CGenericShapeProxy;
    class RnNode_t;
    class FeFitMatrix_t;
    class FeSimdQuad_t;
    class FeSimdSpringIntegrator_t;
    class FeSimdNodeBase_t;
    class FeQuad_t;
    class FeHingeLimit_t;
    class RnWing_t;
    class FeWeightedNode_t;
    class CollisionDetailLayerInfo_t;
    class FeEffectDesc_t;
    class FeSpringIntegrator_t;
    class FourVectors2D;
    class FeKelagerBend2_t;
    class CastSphereSATParams_t;
    class vphysics_save_ragdoll_control_t;
    class FeRigidColliderIndices_t;
    class FeCollisionPlane_t;
    class FeStiffHingeBuild_t;
    class FeBoxRigid_t;
    class FeMorphLayerDepr_t;
    class FeCtrlOffset_t;
    class IPhysicsPlayerController;
    class FeNodeBase_t;
    class FeVertexMapBuild_t;
    class CFeVertexMapBuildArray;
    class FeTri_t;
    class RnHull_t;
    class FeModelSelfCollisionLayer_t;
    class FeAntiTunnelGroupBuild_t;
    class CovMatrix3;
    class PhysicsParticleId_t;
    class RnVertex_t;
    class IPhysicsMotionController;
    class Dop26_t;
    class FeDynKinLink_t;
    class RnFace_t;
    class FeCtrlOsOffset_t;
    class FeAntiTunnelProbe_t;
    class FeSourceEdge_t;
    class FeTwistConstraint_t;
    class FeNodeWindBase_t;
    class FeAxialEdgeBend_t;
    class FourCovMatrices3;
    class constraint_breakableparams_t;
    class FeSphereRigid_t;
    class CollisionDetailLayerInfo_t_Name_t;
    class FeBuildTaperedCapsuleRigid_t;
    class IPhysicsBody;
    class FeSoftParent_t;
    class RnShapeDesc_t;
    class FeTreeChildren_t;
    class FeRodConstraint_t;
    class FeFitWeight_t;
    class RnHalfEdge_t;
    class FeSimdTri_t;
    class VertexPositionColor_t;
    class FeFitInfluence_t;
    class FeHingeLimitBuild_t;

    enum class JointMotion_t : std::uint32_t {
        JOINT_MOTION_FREE = 0x0,
        JOINT_MOTION_LOCKED = 0x1,
        JOINT_MOTION_COUNT = 0x2,
    };

    enum class JointAxis_t : std::uint32_t {
        JOINT_AXIS_X = 0x0,
        JOINT_AXIS_Y = 0x1,
        JOINT_AXIS_Z = 0x2,
        JOINT_AXIS_COUNT = 0x3,
    };

    enum class DynamicContinuousContactBehavior_t : std::uint8_t {
        DYNAMIC_CONTINUOUS_ALLOW_IF_REQUESTED_BY_OTHER_BODY = 0x0,
        DYNAMIC_CONTINUOUS_ALWAYS = 0x1,
        DYNAMIC_CONTINUOUS_NEVER = 0x2,
    };

    enum class PhysInterfaceId_t : std::uint32_t {
        PIID_UNKNOWN = 0x0,
        PIID_IPHYSICSBODY = 0x1,
        PIID_IPHYSAGGREGATE = 0x2,
        PIID_IPHYSICSJOINT = 0x3,
        PIID_IPHYSICSMOTIONCONTROLLER = 0x4,
        PIID_IPHYSICSPARTICLEROPE = 0x5,
        PIID_IPHYSICSRAGDOLLCONTROL = 0x6,
        PIID_NUM_TYPES = 0x7,
    };

    enum class PhysGenericShapeType_t : std::uint8_t {
        GENERIC_SHAPE_POINT = 0x0,
        GENERIC_SHAPE_SPHERE = 0x1,
        GENERIC_SHAPE_AABB = 0x2,
        GENERIC_SHAPE_CAPSULE = 0x3,
        GENERIC_SHAPE_HULL = 0x4,
    };

    class FeEdgeDesc_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nEdge                                           , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nSide                                           , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , nVirtElem                                       , 0xC)
    };

    class FeProxyVertexMap_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_Name                                          , 0x0)
        SCHEMA_FIELD(float                           , m_flWeight                                      , 0x8)
    };

    class FeNodeStrayBox_t {
    public:
        SCHEMA_FIELD(::Vector                        , vMin                                            , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , nFlags                                          , 0xC)
        SCHEMA_FIELD(::Vector                        , vMax                                            , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x1C)
    };

    class CRegionSVM {
    public:
        SCHEMA_FIELD(CUtlVector<RnPlane_t>           , m_Planes                                        , 0x0)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_Nodes                                         , 0x18)
    };

    class RnNode_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMin                                          , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nChildren                                     , 0xC)
        SCHEMA_FIELD(::Vector                        , m_vMax                                          , 0x10)
        SCHEMA_FIELD(std::uint32_t                   , m_nTriangleOffset                               , 0x1C)
    };

    class FeSimdNodeBase_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nNodeX0                                         , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , nNodeX1                                         , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , nNodeY0                                         , 0x18)
        SCHEMA_FIELD(std::uint16_t                   , nNodeY1                                         , 0x20)
        SCHEMA_FIELD(std::uint16_t                   , nDummy                                          , 0x28)
        SCHEMA_FIELD(FourQuaternions                 , qAdjust                                         , 0x30)
    };

    class FeHingeLimit_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , nFlags                                          , 0xC)
        SCHEMA_FIELD(float                           , flWeight4                                       , 0x10)
        SCHEMA_FIELD(float                           , flWeight5                                       , 0x14)
        SCHEMA_FIELD(float                           , flAngleCenter                                   , 0x18)
        SCHEMA_FIELD(float                           , flAngleExtents                                  , 0x1C)
    };

    class CastSphereSATParams_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vRayStart                                     , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vRayDelta                                     , 0xC)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x18)
        SCHEMA_FIELD(float                           , m_flMaxFraction                                 , 0x1C)
        SCHEMA_FIELD(float                           , m_flScale                                       , 0x20)
        SCHEMA_FIELD(RnHull_t*                       , m_pHull                                         , 0x28)
    };

    class FeSimdRodConstraint_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(fltx4                           , f4MaxDist                                       , 0x10)
        SCHEMA_FIELD(fltx4                           , f4MinDist                                       , 0x20)
        SCHEMA_FIELD(fltx4                           , f4Weight0                                       , 0x30)
        SCHEMA_FIELD(fltx4                           , f4RelaxationFactor                              , 0x40)
    };

    class FeFitMatrix_t {
    public:
        SCHEMA_FIELD(CTransform                      , bone                                            , 0x0)
        SCHEMA_FIELD(::Vector                        , vCenter                                         , 0x20)
        SCHEMA_FIELD(std::uint16_t                   , nEnd                                            , 0x2C)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x2E)
        SCHEMA_FIELD(std::uint16_t                   , nBeginDynamic                                   , 0x30)
    };

    class constraint_axislimit_t {
    public:
        SCHEMA_FIELD(float                           , flMinRotation                                   , 0x0)
        SCHEMA_FIELD(float                           , flMaxRotation                                   , 0x4)
        SCHEMA_FIELD(float                           , flMotorTargetAngSpeed                           , 0x8)
        SCHEMA_FIELD(float                           , flMotorMaxTorque                                , 0xC)
    };

    class FeBoxRigid_t {
    public:
        SCHEMA_FIELD(CTransform                      , tmFrame2                                        , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x20)
        SCHEMA_FIELD(std::uint16_t                   , nCollisionMask                                  , 0x22)
        SCHEMA_FIELD(::Vector                        , vSize                                           , 0x24)
        SCHEMA_FIELD(std::uint16_t                   , nVertexMapIndex                                 , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , nFlags                                          , 0x32)
    };

    class OldFeEdge_t {
    public:
        SCHEMA_FIELD(float                           , m_flK                                           , 0x0)
        SCHEMA_FIELD(float                           , invA                                            , 0xC)
        SCHEMA_FIELD(float                           , t                                               , 0x10)
        SCHEMA_FIELD(float                           , flThetaRelaxed                                  , 0x14)
        SCHEMA_FIELD(float                           , flThetaFactor                                   , 0x18)
        SCHEMA_FIELD(float                           , c01                                             , 0x1C)
        SCHEMA_FIELD(float                           , c02                                             , 0x20)
        SCHEMA_FIELD(float                           , c03                                             , 0x24)
        SCHEMA_FIELD(float                           , c04                                             , 0x28)
        SCHEMA_FIELD(float                           , flAxialModelDist                                , 0x2C)
        SCHEMA_FIELD(float                           , flAxialModelWeights                             , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , m_nNode                                         , 0x40)
    };

    class FeCtrlOffset_t {
    public:
        SCHEMA_FIELD(::Vector                        , vOffset                                         , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nCtrlParent                                     , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , nCtrlChild                                      , 0xE)
    };

    class CGenericShapeProxy {
    public:
        using _Type0 = CUtlLeanVectorFixedGrowable<Vector,8>;
        SCHEMA_FIELD(_Type0                          , m_verts                                         , 0x30)
    };

    class FeWeightedNode_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nWeight                                         , 0x2)
    };

    class RnSphereDesc_t {
    public:
        SCHEMA_FIELD(SphereBase_t<float32>           , m_Sphere                                        , 0x18)
    };

    class FeVertexMapBuild_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_VertexMapName                                 , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nNameHash                                     , 0x8)
        SCHEMA_FIELD(::Color                         , m_Color                                         , 0xC)
        SCHEMA_FIELD(float                           , m_flVolumetricSolveStrength                     , 0x10)
        SCHEMA_FIELD(std::int32_t                    , m_nScaleSourceNode                              , 0x14)
        SCHEMA_FIELD(CUtlVector<float32>             , m_Weights                                       , 0x18)
    };

    class IPhysicsBodyList {
    public:
    };

    class CFeVertexMapBuildArray {
    public:
        SCHEMA_FIELD(CUtlVector<FeVertexMapBuild_t*> , m_Array                                         , 0x0)
    };

    class RnFace_t {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_nEdge                                         , 0x0)
    };

    class CFeNamedJiggleBone {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_strParentBone                                 , 0x0)
        SCHEMA_FIELD(CTransform                      , m_transform                                     , 0x10)
        SCHEMA_FIELD(std::uint32_t                   , m_nJiggleParent                                 , 0x30)
        SCHEMA_FIELD(CFeJiggleBone                   , m_jiggleBone                                    , 0x34)
    };

    class RnCapsule_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vCenter                                       , 0x0)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x18)
    };

    class RnBodyDesc_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sDebugName                                    , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vPosition                                     , 0x8)
        SCHEMA_FIELD(QuaternionStorage               , m_qOrientation                                  , 0x14)
        SCHEMA_FIELD(::Vector                        , m_vLinearVelocity                               , 0x24)
        SCHEMA_FIELD(::Vector                        , m_vAngularVelocity                              , 0x30)
        SCHEMA_FIELD(::Vector                        , m_vLocalMassCenter                              , 0x3C)
        SCHEMA_FIELD(::Vector                        , m_LocalInertiaInv                               , 0x48)
        SCHEMA_FIELD(float                           , m_flMassInv                                     , 0x6C)
        SCHEMA_FIELD(float                           , m_flGameMass                                    , 0x70)
        SCHEMA_FIELD(float                           , m_flMassScaleInv                                , 0x74)
        SCHEMA_FIELD(float                           , m_flInertiaScaleInv                             , 0x78)
        SCHEMA_FIELD(float                           , m_flLinearDamping                               , 0x7C)
        SCHEMA_FIELD(float                           , m_flAngularDamping                              , 0x80)
        SCHEMA_FIELD(float                           , m_flLinearDragScale                             , 0x84)
        SCHEMA_FIELD(float                           , m_flAngularDragScale                            , 0x88)
        SCHEMA_FIELD(float                           , m_flLinearFluidDragScale                        , 0x8C)
        SCHEMA_FIELD(float                           , m_flAngularFluidDragScale                       , 0x90)
        SCHEMA_FIELD(::Vector                        , m_vLastAwakeForceAccum                          , 0x94)
        SCHEMA_FIELD(::Vector                        , m_vLastAwakeTorqueAccum                         , 0xA0)
        SCHEMA_FIELD(float                           , m_flBuoyancyScale                               , 0xAC)
        SCHEMA_FIELD(float                           , m_flGravityScale                                , 0xB0)
        SCHEMA_FIELD(float                           , m_flTimeScale                                   , 0xB4)
        SCHEMA_FIELD(std::int32_t                    , m_nBodyType                                     , 0xB8)
        SCHEMA_FIELD(std::uint32_t                   , m_nGameIndex                                    , 0xBC)
        SCHEMA_FIELD(std::uint32_t                   , m_nGameFlags                                    , 0xC0)
        SCHEMA_FIELD(std::int8_t                     , m_nMinVelocityIterations                        , 0xC4)
        SCHEMA_FIELD(std::int8_t                     , m_nMinPositionIterations                        , 0xC5)
        SCHEMA_FIELD(std::int8_t                     , m_nMassPriority                                 , 0xC6)
        SCHEMA_FIELD(bool                            , m_bEnabled                                      , 0xC7)
        SCHEMA_FIELD(bool                            , m_bSleeping                                     , 0xC8)
        SCHEMA_FIELD(bool                            , m_bIsContinuousEnabled                          , 0xC9)
        SCHEMA_FIELD(bool                            , m_bDragEnabled                                  , 0xCA)
        SCHEMA_FIELD(::Vector                        , m_vGravity                                      , 0xCC)
        SCHEMA_FIELD(bool                            , m_bSpeculativeEnabled                           , 0xD8)
        SCHEMA_FIELD(bool                            , m_bHasShadowController                          , 0xD9)
        SCHEMA_FIELD(DynamicContinuousContactBehavior_t, m_nDynamicContinuousContactBehavior             , 0xDA)
    };

    class FeAntiTunnelProbe_t {
    public:
        SCHEMA_FIELD(float                           , flWeight                                        , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , nFlags                                          , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , nProbeNode                                      , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , nCount                                          , 0xA)
        SCHEMA_FIELD(std::uint32_t                   , nBegin                                          , 0xC)
        SCHEMA_FIELD(float                           , flActivationDistance                            , 0x10)
        SCHEMA_FIELD(float                           , flCurvatureRadius                               , 0x14)
        SCHEMA_FIELD(float                           , flBias                                          , 0x18)
    };

    class IPhysicsBody {
    public:
    };

    class FeSoftParent_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , nParent                                         , 0x0)
        SCHEMA_FIELD(float                           , flAlpha                                         , 0x4)
    };

    class RnSoftbodyParticle_t {
    public:
        SCHEMA_FIELD(float                           , m_flMassInv                                     , 0x0)
    };

    class CollisionDetailLayerInfo_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_sDescription                                  , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_sFriendlyName                                 , 0x8)
        SCHEMA_FIELD(bool                            , m_bIsQueryOnly                                  , 0x10)
        SCHEMA_FIELD(::CUtlString                    , m_sParentDetailLayer                            , 0x18)
        SCHEMA_FIELD(CUtlVector<CollisionDetailLayerInfo_t_Name_t>, m_vecSubtreeDetailLayers                        , 0x20)
        SCHEMA_FIELD(bool                            , m_bNotPickable                                  , 0x38)
    };

    class FeSDFRigid_t {
    public:
        SCHEMA_FIELD(::Vector                        , vLocalMin                                       , 0x0)
        SCHEMA_FIELD(::Vector                        , vLocalMax                                       , 0xC)
        SCHEMA_FIELD(float                           , flBounciness                                    , 0x18)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x1C)
        SCHEMA_FIELD(std::uint16_t                   , nCollisionMask                                  , 0x1E)
        SCHEMA_FIELD(std::uint16_t                   , nVertexMapIndex                                 , 0x20)
        SCHEMA_FIELD(std::uint16_t                   , nFlags                                          , 0x22)
        SCHEMA_FIELD(CUtlVector<float32>             , m_Distances                                     , 0x28)
        SCHEMA_FIELD(std::int32_t                    , m_nWidth                                        , 0x40)
        SCHEMA_FIELD(std::int32_t                    , m_nHeight                                       , 0x44)
        SCHEMA_FIELD(std::int32_t                    , m_nDepth                                        , 0x48)
    };

    class FeSimdTri_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(fltx4                           , w1                                              , 0x30)
        SCHEMA_FIELD(fltx4                           , w2                                              , 0x40)
        SCHEMA_FIELD(fltx4                           , v1x                                             , 0x50)
        SCHEMA_FIELD(FourVectors2D                   , v2                                              , 0x60)
    };

    class IPhysicsPlayerController {
    public:
    };

    class FeFitInfluence_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , nVertexNode                                     , 0x0)
        SCHEMA_FIELD(float                           , flWeight                                        , 0x4)
        SCHEMA_FIELD(std::uint32_t                   , nMatrixNode                                     , 0x8)
    };

    class FeAnimStrayRadius_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(float                           , flMaxDist                                       , 0x4)
        SCHEMA_FIELD(float                           , flRelaxationFactor                              , 0x8)
    };

    class RnSoftbodyCapsule_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vCenter                                       , 0x0)
        SCHEMA_FIELD(float                           , m_flRadius                                      , 0x18)
        SCHEMA_FIELD(std::uint16_t                   , m_nParticle                                     , 0x1C)
    };

    class FeQuad_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(float                           , flSlack                                         , 0x8)
        SCHEMA_FIELD(::Vector4D                      , vShape                                          , 0xC)
    };

    class FeSimdRodConstraintAnim_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(fltx4                           , f4Weight0                                       , 0x10)
        SCHEMA_FIELD(fltx4                           , f4RelaxationFactor                              , 0x20)
    };

    class PhysicsParticleId_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_Value                                         , 0x0)
    };

    class FeHingeLimitBuild_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , nFlags                                          , 0xC)
        SCHEMA_FIELD(float                           , flLimitCW                                       , 0x10)
        SCHEMA_FIELD(float                           , flLimitCCW                                      , 0x14)
    };

    class RnHullDesc_t {
    public:
        SCHEMA_FIELD(RnHull_t                        , m_Hull                                          , 0x18)
    };

    class IPhysicsRagdollControl {
    public:
    };

    class RnSoftbodySpring_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nParticle                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flLength                                      , 0x4)
    };

    class FeVertexMapDesc_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , sName                                           , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , nNameHash                                       , 0x8)
        SCHEMA_FIELD(std::uint32_t                   , nColor                                          , 0xC)
        SCHEMA_FIELD(std::uint32_t                   , nFlags                                          , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , nVertexBase                                     , 0x14)
        SCHEMA_FIELD(std::uint16_t                   , nVertexCount                                    , 0x16)
        SCHEMA_FIELD(std::uint32_t                   , nMapOffset                                      , 0x18)
        SCHEMA_FIELD(std::uint32_t                   , nNodeListOffset                                 , 0x1C)
        SCHEMA_FIELD(::Vector                        , vCenterOfMass                                   , 0x20)
        SCHEMA_FIELD(float                           , flVolumetricSolveStrength                       , 0x2C)
        SCHEMA_FIELD(std::int16_t                    , nScaleSourceNode                                , 0x30)
        SCHEMA_FIELD(std::uint16_t                   , nNodeListCount                                  , 0x32)
    };

    class FeEffectDesc_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , sName                                           , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , nNameHash                                       , 0x8)
        SCHEMA_FIELD(std::int32_t                    , nType                                           , 0xC)
        SCHEMA_FIELD(KeyValues3                      , m_Params                                        , 0x10)
    };

    class FeSimdAnimStrayRadius_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(fltx4                           , flMaxDist                                       , 0x10)
        SCHEMA_FIELD(fltx4                           , flRelaxationFactor                              , 0x20)
    };

    class VertexPositionColor_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vPosition                                     , 0x0)
    };

    class FeStiffHingeBuild_t {
    public:
        SCHEMA_FIELD(float                           , flMaxAngle                                      , 0x0)
        SCHEMA_FIELD(float                           , flStrength                                      , 0x4)
        SCHEMA_FIELD(float                           , flMotionBias                                    , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x14)
    };

    class FeTaperedCapsuleRigid_t {
    public:
        SCHEMA_FIELD(fltx4                           , vSphere                                         , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x20)
        SCHEMA_FIELD(std::uint16_t                   , nCollisionMask                                  , 0x22)
        SCHEMA_FIELD(std::uint16_t                   , nVertexMapIndex                                 , 0x24)
        SCHEMA_FIELD(std::uint16_t                   , nFlags                                          , 0x26)
    };

    class RnShapeDesc_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nCollisionAttributeIndex                      , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nSurfacePropertyIndex                         , 0x4)
        SCHEMA_FIELD(::CUtlString                    , m_UserFriendlyName                              , 0x8)
        SCHEMA_FIELD(bool                            , m_bUserFriendlyNameSealed                       , 0x10)
        SCHEMA_FIELD(bool                            , m_bUserFriendlyNameLong                         , 0x11)
        SCHEMA_FIELD(std::uint32_t                   , m_nToolMaterialHash                             , 0x14)
    };

    class PhysFeModelDesc_t {
    public:
        SCHEMA_FIELD(CUtlVector<uint32>              , m_CtrlHash                                      , 0x0)
        SCHEMA_FIELD(CUtlVector<CUtlString>          , m_CtrlName                                      , 0x18)
        SCHEMA_FIELD(std::uint32_t                   , m_nStaticNodeFlags                              , 0x30)
        SCHEMA_FIELD(std::uint32_t                   , m_nDynamicNodeFlags                             , 0x34)
        SCHEMA_FIELD(float                           , m_flLocalForce                                  , 0x38)
        SCHEMA_FIELD(float                           , m_flLocalRotation                               , 0x3C)
        SCHEMA_FIELD(std::uint16_t                   , m_nNodeCount                                    , 0x40)
        SCHEMA_FIELD(std::uint16_t                   , m_nStaticNodes                                  , 0x42)
        SCHEMA_FIELD(std::uint16_t                   , m_nRotLockStaticNodes                           , 0x44)
        SCHEMA_FIELD(std::uint16_t                   , m_nFirstPositionDrivenNode                      , 0x46)
        SCHEMA_FIELD(std::uint16_t                   , m_nSimdTriCount1                                , 0x48)
        SCHEMA_FIELD(std::uint16_t                   , m_nSimdTriCount2                                , 0x4A)
        SCHEMA_FIELD(std::uint16_t                   , m_nSimdQuadCount1                               , 0x4C)
        SCHEMA_FIELD(std::uint16_t                   , m_nSimdQuadCount2                               , 0x4E)
        SCHEMA_FIELD(std::uint16_t                   , m_nQuadCount1                                   , 0x50)
        SCHEMA_FIELD(std::uint16_t                   , m_nQuadCount2                                   , 0x52)
        SCHEMA_FIELD(std::uint16_t                   , m_nTreeDepth                                    , 0x54)
        SCHEMA_FIELD(std::uint16_t                   , m_nNodeBaseJiggleboneDependsCount               , 0x56)
        SCHEMA_FIELD(std::uint16_t                   , m_nRopeCount                                    , 0x58)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_Ropes                                         , 0x60)
        SCHEMA_FIELD(CUtlVector<FeNodeBase_t>        , m_NodeBases                                     , 0x78)
        SCHEMA_FIELD(CUtlVector<FeSimdNodeBase_t>    , m_SimdNodeBases                                 , 0x90)
        SCHEMA_FIELD(CUtlVector<FeQuad_t>            , m_Quads                                         , 0xA8)
        SCHEMA_FIELD(CUtlVector<FeSimdQuad_t>        , m_SimdQuads                                     , 0xC0)
        SCHEMA_FIELD(CUtlVector<FeSimdTri_t>         , m_SimdTris                                      , 0xD8)
        SCHEMA_FIELD(CUtlVector<FeSimdRodConstraint_t>, m_SimdRods                                      , 0xF0)
        SCHEMA_FIELD(CUtlVector<FeSimdRodConstraintAnim_t>, m_SimdRodsAnim                                  , 0x108)
        SCHEMA_FIELD(CUtlVector<CTransform>          , m_InitPose                                      , 0x120)
        SCHEMA_FIELD(CUtlVector<FeRodConstraint_t>   , m_Rods                                          , 0x138)
        SCHEMA_FIELD(CUtlVector<FeTwistConstraint_t> , m_Twists                                        , 0x150)
        SCHEMA_FIELD(CUtlVector<FeHingeLimit_t>      , m_HingeLimits                                   , 0x168)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_AntiTunnelBytecode                            , 0x180)
        SCHEMA_FIELD(CUtlVector<FeDynKinLink_t>      , m_DynKinLinks                                   , 0x198)
        SCHEMA_FIELD(CUtlVector<FeAntiTunnelProbe_t> , m_AntiTunnelProbes                              , 0x1B0)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_AntiTunnelTargetNodes                         , 0x1C8)
        SCHEMA_FIELD(CUtlVector<FeNodeStrayBox_t>    , m_NodeStrayBoxes                                , 0x1E0)
        SCHEMA_FIELD(CUtlVector<FeAxialEdgeBend_t>   , m_AxialEdges                                    , 0x1F8)
        SCHEMA_FIELD(CUtlVector<float32>             , m_NodeInvMasses                                 , 0x210)
        SCHEMA_FIELD(CUtlVector<FeCtrlOffset_t>      , m_CtrlOffsets                                   , 0x228)
        SCHEMA_FIELD(CUtlVector<FeCtrlOsOffset_t>    , m_CtrlOsOffsets                                 , 0x240)
        SCHEMA_FIELD(CUtlVector<FeFollowNode_t>      , m_FollowNodes                                   , 0x258)
        SCHEMA_FIELD(CUtlVector<FeCollisionPlane_t>  , m_CollisionPlanes                               , 0x270)
        SCHEMA_FIELD(CUtlVector<FeNodeIntegrator_t>  , m_NodeIntegrator                                , 0x288)
        SCHEMA_FIELD(CUtlVector<FeSpringIntegrator_t>, m_SpringIntegrator                              , 0x2A0)
        SCHEMA_FIELD(CUtlVector<FeSimdSpringIntegrator_t>, m_SimdSpringIntegrator                          , 0x2B8)
        SCHEMA_FIELD(CUtlVector<FeWorldCollisionParams_t>, m_WorldCollisionParams                          , 0x2D0)
        SCHEMA_FIELD(CUtlVector<float32>             , m_LegacyStretchForce                            , 0x2E8)
        SCHEMA_FIELD(CUtlVector<float32>             , m_NodeCollisionRadii                            , 0x300)
        SCHEMA_FIELD(CUtlVector<float32>             , m_DynNodeFriction                               , 0x318)
        SCHEMA_FIELD(CUtlVector<float32>             , m_LocalRotation                                 , 0x330)
        SCHEMA_FIELD(CUtlVector<float32>             , m_LocalForce                                    , 0x348)
        SCHEMA_FIELD(CUtlVector<FeTaperedCapsuleStretch_t>, m_TaperedCapsuleStretches                       , 0x360)
        SCHEMA_FIELD(CUtlVector<FeTaperedCapsuleRigid_t>, m_TaperedCapsuleRigids                          , 0x378)
        SCHEMA_FIELD(CUtlVector<FeSphereRigid_t>     , m_SphereRigids                                  , 0x390)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_WorldCollisionNodes                           , 0x3A8)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_TreeParents                                   , 0x3C0)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_TreeCollisionMasks                            , 0x3D8)
        SCHEMA_FIELD(CUtlVector<FeTreeChildren_t>    , m_TreeChildren                                  , 0x3F0)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_FreeNodes                                     , 0x408)
        SCHEMA_FIELD(CUtlVector<FeFitMatrix_t>       , m_FitMatrices                                   , 0x420)
        SCHEMA_FIELD(CUtlVector<FeFitWeight_t>       , m_FitWeights                                    , 0x438)
        SCHEMA_FIELD(CUtlVector<FeNodeReverseOffset_t>, m_ReverseOffsets                                , 0x450)
        SCHEMA_FIELD(CUtlVector<FeAnimStrayRadius_t> , m_AnimStrayRadii                                , 0x468)
        SCHEMA_FIELD(CUtlVector<FeSimdAnimStrayRadius_t>, m_SimdAnimStrayRadii                            , 0x480)
        SCHEMA_FIELD(CUtlVector<FeKelagerBend2_t>    , m_KelagerBends                                  , 0x498)
        SCHEMA_FIELD(CUtlVector<FeCtrlSoftOffset_t>  , m_CtrlSoftOffsets                               , 0x4B0)
        SCHEMA_FIELD(CUtlVector<CFeIndexedJiggleBone>, m_JiggleBones                                   , 0x4C8)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_SourceElems                                   , 0x4E0)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_GoalDampedSpringIntegrators                   , 0x4F8)
        SCHEMA_FIELD(CUtlVector<FeTri_t>             , m_Tris                                          , 0x510)
        SCHEMA_FIELD(std::uint16_t                   , m_nTriCount1                                    , 0x528)
        SCHEMA_FIELD(std::uint16_t                   , m_nTriCount2                                    , 0x52A)
        SCHEMA_FIELD(std::uint8_t                    , m_nReservedUint8                                , 0x52C)
        SCHEMA_FIELD(std::uint8_t                    , m_nExtraPressureIterations                      , 0x52D)
        SCHEMA_FIELD(std::uint8_t                    , m_nExtraGoalIterations                          , 0x52E)
        SCHEMA_FIELD(std::uint8_t                    , m_nExtraIterations                              , 0x52F)
        SCHEMA_FIELD(CUtlVector<FeSDFRigid_t>        , m_SDFRigids                                     , 0x530)
        SCHEMA_FIELD(CUtlVector<FeBoxRigid_t>        , m_BoxRigids                                     , 0x548)
        SCHEMA_FIELD(CUtlVector<uint8>               , m_DynNodeVertexSet                              , 0x560)
        SCHEMA_FIELD(CUtlVector<uint32>              , m_VertexSetNames                                , 0x578)
        SCHEMA_FIELD(CUtlVector<FeRigidColliderIndices_t>, m_RigidColliderPriorities                       , 0x590)
        SCHEMA_FIELD(CUtlVector<FeMorphLayerDepr_t>  , m_MorphLayers                                   , 0x5A8)
        SCHEMA_FIELD(CUtlVector<uint8>               , m_MorphSetData                                  , 0x5C0)
        SCHEMA_FIELD(CUtlVector<FeVertexMapDesc_t>   , m_VertexMaps                                    , 0x5D8)
        SCHEMA_FIELD(CUtlVector<uint8>               , m_VertexMapValues                               , 0x5F0)
        SCHEMA_FIELD(CUtlVector<FeEffectDesc_t>      , m_Effects                                       , 0x608)
        SCHEMA_FIELD(CUtlVector<FeCtrlOffset_t>      , m_LockToParent                                  , 0x620)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_LockToGoal                                    , 0x638)
        SCHEMA_FIELD(CUtlVector<int16>               , m_SkelParents                                   , 0x650)
        SCHEMA_FIELD(CUtlVector<FeNodeWindBase_t>    , m_DynNodeWindBases                              , 0x668)
        SCHEMA_FIELD(CUtlVector<FeModelSelfCollisionLayer_t>, m_SelfCollisionLayers                           , 0x680)
        SCHEMA_FIELD(float                           , m_flInternalPressure                            , 0x698)
        SCHEMA_FIELD(float                           , m_flDefaultTimeDilation                         , 0x69C)
        SCHEMA_FIELD(float                           , m_flWindage                                     , 0x6A0)
        SCHEMA_FIELD(float                           , m_flWindDrag                                    , 0x6A4)
        SCHEMA_FIELD(float                           , m_flDefaultSurfaceStretch                       , 0x6A8)
        SCHEMA_FIELD(float                           , m_flDefaultThreadStretch                        , 0x6AC)
        SCHEMA_FIELD(float                           , m_flDefaultGravityScale                         , 0x6B0)
        SCHEMA_FIELD(float                           , m_flDefaultVelAirDrag                           , 0x6B4)
        SCHEMA_FIELD(float                           , m_flDefaultExpAirDrag                           , 0x6B8)
        SCHEMA_FIELD(float                           , m_flDefaultVelQuadAirDrag                       , 0x6BC)
        SCHEMA_FIELD(float                           , m_flDefaultExpQuadAirDrag                       , 0x6C0)
        SCHEMA_FIELD(float                           , m_flRodVelocitySmoothRate                       , 0x6C4)
        SCHEMA_FIELD(float                           , m_flQuadVelocitySmoothRate                      , 0x6C8)
        SCHEMA_FIELD(float                           , m_flAddWorldCollisionRadius                     , 0x6CC)
        SCHEMA_FIELD(float                           , m_flDefaultVolumetricSolveAmount                , 0x6D0)
        SCHEMA_FIELD(float                           , m_flMotionSmoothCDT                             , 0x6D4)
        SCHEMA_FIELD(float                           , m_flLocalDrag1                                  , 0x6D8)
        SCHEMA_FIELD(std::uint16_t                   , m_nRodVelocitySmoothIterations                  , 0x6DC)
        SCHEMA_FIELD(std::uint16_t                   , m_nQuadVelocitySmoothIterations                 , 0x6DE)
    };

    class CFeJiggleBone {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nFlags                                        , 0x0)
        SCHEMA_FIELD(float                           , m_flLength                                      , 0x4)
        SCHEMA_FIELD(float                           , m_flTipMass                                     , 0x8)
        SCHEMA_FIELD(float                           , m_flYawStiffness                                , 0xC)
        SCHEMA_FIELD(float                           , m_flYawDamping                                  , 0x10)
        SCHEMA_FIELD(float                           , m_flPitchStiffness                              , 0x14)
        SCHEMA_FIELD(float                           , m_flPitchDamping                                , 0x18)
        SCHEMA_FIELD(float                           , m_flAlongStiffness                              , 0x1C)
        SCHEMA_FIELD(float                           , m_flAlongDamping                                , 0x20)
        SCHEMA_FIELD(float                           , m_flAngleLimit                                  , 0x24)
        SCHEMA_FIELD(float                           , m_flMinYaw                                      , 0x28)
        SCHEMA_FIELD(float                           , m_flMaxYaw                                      , 0x2C)
        SCHEMA_FIELD(float                           , m_flYawFriction                                 , 0x30)
        SCHEMA_FIELD(float                           , m_flYawBounce                                   , 0x34)
        SCHEMA_FIELD(float                           , m_flMinPitch                                    , 0x38)
        SCHEMA_FIELD(float                           , m_flMaxPitch                                    , 0x3C)
        SCHEMA_FIELD(float                           , m_flPitchFriction                               , 0x40)
        SCHEMA_FIELD(float                           , m_flPitchBounce                                 , 0x44)
        SCHEMA_FIELD(float                           , m_flBaseMass                                    , 0x48)
        SCHEMA_FIELD(float                           , m_flBaseStiffness                               , 0x4C)
        SCHEMA_FIELD(float                           , m_flBaseDamping                                 , 0x50)
        SCHEMA_FIELD(float                           , m_flBaseMinLeft                                 , 0x54)
        SCHEMA_FIELD(float                           , m_flBaseMaxLeft                                 , 0x58)
        SCHEMA_FIELD(float                           , m_flBaseLeftFriction                            , 0x5C)
        SCHEMA_FIELD(float                           , m_flBaseMinUp                                   , 0x60)
        SCHEMA_FIELD(float                           , m_flBaseMaxUp                                   , 0x64)
        SCHEMA_FIELD(float                           , m_flBaseUpFriction                              , 0x68)
        SCHEMA_FIELD(float                           , m_flBaseMinForward                              , 0x6C)
        SCHEMA_FIELD(float                           , m_flBaseMaxForward                              , 0x70)
        SCHEMA_FIELD(float                           , m_flBaseForwardFriction                         , 0x74)
        SCHEMA_FIELD(float                           , m_flRadius0                                     , 0x78)
        SCHEMA_FIELD(float                           , m_flRadius1                                     , 0x7C)
        SCHEMA_FIELD(::Vector                        , m_vPoint0                                       , 0x80)
        SCHEMA_FIELD(::Vector                        , m_vPoint1                                       , 0x8C)
        SCHEMA_FIELD(std::uint16_t                   , m_nCollisionMask                                , 0x98)
    };

    class FeSimdQuad_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(fltx4                           , f4Slack                                         , 0x20)
        SCHEMA_FIELD(FourVectors                     , vShape                                          , 0x30)
        SCHEMA_FIELD(fltx4                           , f4Weights                                       , 0xF0)
    };

    class VertexPositionNormal_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vPosition                                     , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vNormal                                       , 0xC)
    };

    class constraint_hingeparams_t {
    public:
        SCHEMA_FIELD(::Vector                        , worldPosition                                   , 0x0)
        SCHEMA_FIELD(::Vector                        , worldAxisDirection                              , 0xC)
        SCHEMA_FIELD(constraint_axislimit_t          , hingeAxis                                       , 0x18)
        SCHEMA_FIELD(constraint_breakableparams_t    , constraint                                      , 0x28)
    };

    class vphysics_save_cphysicsbody_t {
    public:
        SCHEMA_FIELD(std::uint64_t                   , m_nOldPointer                                   , 0xE0)
    };

    class CFeMorphLayer {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_Name                                          , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nNameHash                                     , 0x8)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_Nodes                                         , 0x10)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_InitPos                                       , 0x28)
        SCHEMA_FIELD(CUtlVector<float32>             , m_Gravity                                       , 0x40)
        SCHEMA_FIELD(CUtlVector<float32>             , m_GoalStrength                                  , 0x58)
        SCHEMA_FIELD(CUtlVector<float32>             , m_GoalDamping                                   , 0x70)
    };

    class CFeIndexedJiggleBone {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nNode                                         , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nJiggleParent                                 , 0x4)
        SCHEMA_FIELD(CFeJiggleBone                   , m_jiggleBone                                    , 0x8)
    };

    class FeNodeReverseOffset_t {
    public:
        SCHEMA_FIELD(::Vector                        , vOffset                                         , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nBoneCtrl                                       , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , nTargetNode                                     , 0xE)
    };

    class FeBuildSphereRigid_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nPriority                                     , 0x20)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexMapHash                                , 0x24)
        SCHEMA_FIELD(std::uint32_t                   , m_nAntitunnelGroupBits                          , 0x28)
    };

    class FeNodeIntegrator_t {
    public:
        SCHEMA_FIELD(float                           , flPointDamping                                  , 0x0)
        SCHEMA_FIELD(float                           , flAnimationForceAttraction                      , 0x4)
        SCHEMA_FIELD(float                           , flAnimationVertexAttraction                     , 0x8)
        SCHEMA_FIELD(float                           , flGravity                                       , 0xC)
    };

    class FeWorldCollisionParams_t {
    public:
        SCHEMA_FIELD(float                           , flWorldFriction                                 , 0x0)
        SCHEMA_FIELD(float                           , flGroundFriction                                , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , nListBegin                                      , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , nListEnd                                        , 0xA)
    };

    class FeCollisionPlane_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nCtrlParent                                     , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nChildNode                                      , 0x2)
        SCHEMA_FIELD(RnPlane_t                       , m_Plane                                         , 0x4)
        SCHEMA_FIELD(float                           , flStrength                                      , 0x14)
    };

    class FeTri_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(float                           , w1                                              , 0x8)
        SCHEMA_FIELD(float                           , w2                                              , 0xC)
        SCHEMA_FIELD(float                           , v1x                                             , 0x10)
        SCHEMA_FIELD(::Vector2D                      , v2                                              , 0x14)
    };

    class RnHull_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vCentroid                                     , 0x0)
        SCHEMA_FIELD(float                           , m_flMaxAngularRadius                            , 0xC)
        SCHEMA_FIELD(::AABB_t                        , m_Bounds                                        , 0x10)
        SCHEMA_FIELD(::Vector                        , m_vOrthographicAreas                            , 0x28)
        SCHEMA_FIELD(::matrix3x4_t                   , m_MassProperties                                , 0x34)
        SCHEMA_FIELD(float                           , m_flVolume                                      , 0x64)
        SCHEMA_FIELD(float                           , m_flSurfaceArea                                 , 0x68)
        SCHEMA_FIELD(CUtlVector<RnVertex_t>          , m_Vertices                                      , 0x70)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_VertexPositions                               , 0x88)
        SCHEMA_FIELD(CUtlVector<RnHalfEdge_t>        , m_Edges                                         , 0xA0)
        SCHEMA_FIELD(CUtlVector<RnFace_t>            , m_Faces                                         , 0xB8)
        SCHEMA_FIELD(CUtlVector<RnPlane_t>           , m_FacePlanes                                    , 0xD0)
        SCHEMA_FIELD(std::uint32_t                   , m_nFlags                                        , 0xE8)
        SCHEMA_FIELD(CRegionSVM*                     , m_pRegionSVM                                    , 0xF0)
    };

    class IPhysicsMotionController {
    public:
    };

    class FeDynKinLink_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nParent                                       , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , m_nChild                                        , 0x2)
    };

    class FeSpringIntegrator_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(float                           , flSpringRestLength                              , 0x4)
        SCHEMA_FIELD(float                           , flSpringConstant                                , 0x8)
        SCHEMA_FIELD(float                           , flSpringDamping                                 , 0xC)
        SCHEMA_FIELD(float                           , flNodeWeight0                                   , 0x10)
    };

    class vphysics_save_ragdoll_control_t {
    public:
        SCHEMA_FIELD(float                           , m_flMinSpringFrequency                          , 0x0)
        SCHEMA_FIELD(float                           , m_flMaxSpringFrequency                          , 0x4)
        SCHEMA_FIELD(float                           , m_flMaxStretch                                  , 0x8)
        SCHEMA_FIELD(bool                            , m_bSolidCollisionAtZeroWeight                   , 0xC)
        SCHEMA_FIELD(bool                            , m_bRequiresDynamicBodies                        , 0xD)
        SCHEMA_FIELD(bool                            , m_bIgnoreTeleport                               , 0xE)
        SCHEMA_FIELD(::Vector                        , m_vLinearVelocityAccumulator                    , 0x10)
        SCHEMA_FIELD(RotationVector                  , m_vAngularVelocityAccumulator                   , 0x1C)
        SCHEMA_FIELD(::Vector                        , m_vForceAccumulator                             , 0x28)
        SCHEMA_FIELD(std::int32_t                    , m_nBodyCount                                    , 0x34)
    };

    class FeCtrlOsOffset_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nCtrlParent                                     , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nCtrlChild                                      , 0x2)
    };

    class FeCtrlSoftOffset_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nCtrlParent                                     , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nCtrlChild                                      , 0x2)
        SCHEMA_FIELD(::Vector                        , vOffset                                         , 0x4)
        SCHEMA_FIELD(float                           , flAlpha                                         , 0x10)
    };

    class FeSimdSpringIntegrator_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(fltx4                           , flSpringRestLength                              , 0x10)
        SCHEMA_FIELD(fltx4                           , flSpringConstant                                , 0x20)
        SCHEMA_FIELD(fltx4                           , flSpringDamping                                 , 0x30)
        SCHEMA_FIELD(fltx4                           , flNodeWeight0                                   , 0x40)
    };

    class FeBuildBoxRigid_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nPriority                                     , 0x40)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexMapHash                                , 0x44)
        SCHEMA_FIELD(std::uint32_t                   , m_nAntitunnelGroupBits                          , 0x48)
    };

    class FeKelagerBend2_t {
    public:
        SCHEMA_FIELD(float                           , flWeight                                        , 0x0)
        SCHEMA_FIELD(float                           , flHeight0                                       , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , nReserved                                       , 0x16)
    };

    class FeAxialEdgeBend_t {
    public:
        SCHEMA_FIELD(float                           , te                                              , 0x0)
        SCHEMA_FIELD(float                           , tv                                              , 0x4)
        SCHEMA_FIELD(float                           , flDist                                          , 0x8)
        SCHEMA_FIELD(float                           , flWeight                                        , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x1C)
    };

    class RnMeshDesc_t {
    public:
        SCHEMA_FIELD(RnMesh_t                        , m_Mesh                                          , 0x18)
    };

    class FourCovMatrices3 {
    public:
        SCHEMA_FIELD(FourVectors                     , m_vDiag                                         , 0x0)
        SCHEMA_FIELD(fltx4                           , m_flXY                                          , 0x30)
        SCHEMA_FIELD(fltx4                           , m_flXZ                                          , 0x40)
        SCHEMA_FIELD(fltx4                           , m_flYZ                                          , 0x50)
    };

    class FeSphereRigid_t {
    public:
        SCHEMA_FIELD(fltx4                           , vSphere                                         , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , nCollisionMask                                  , 0x12)
        SCHEMA_FIELD(std::uint16_t                   , nVertexMapIndex                                 , 0x14)
        SCHEMA_FIELD(std::uint16_t                   , nFlags                                          , 0x16)
    };

    class FeTreeChildren_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nChild                                          , 0x0)
    };

    class RnTriangle_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nIndex                                        , 0x0)
    };

    class FeFitWeight_t {
    public:
        SCHEMA_FIELD(float                           , flWeight                                        , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , nDummy                                          , 0x6)
    };

    class RnVertex_t {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_nEdge                                         , 0x0)
    };

    class Dop26_t {
    public:
        SCHEMA_FIELD(float                           , m_flSupport                                     , 0x0)
    };

    class RnMesh_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vMin                                          , 0x0)
        SCHEMA_FIELD(::Vector                        , m_vMax                                          , 0xC)
        SCHEMA_FIELD(CUtlVector<RnNode_t>            , m_Nodes                                         , 0x18)
        SCHEMA_FIELD(CUtlVectorSIMDPaddedVector      , m_Vertices                                      , 0x30)
        SCHEMA_FIELD(CUtlVector<RnTriangle_t>        , m_Triangles                                     , 0x48)
        SCHEMA_FIELD(CUtlVector<RnWing_t>            , m_Wings                                         , 0x60)
        SCHEMA_FIELD(CUtlVector<uint8>               , m_TriangleEdgeFlags                             , 0x78)
        SCHEMA_FIELD(CUtlVector<uint8>               , m_Materials                                     , 0x90)
        SCHEMA_FIELD(::Vector                        , m_vOrthographicAreas                            , 0xA8)
        SCHEMA_FIELD(std::uint32_t                   , m_nFlags                                        , 0xB4)
        SCHEMA_FIELD(std::uint32_t                   , m_nDebugFlags                                   , 0xB8)
    };

    class constraint_breakableparams_t {
    public:
        SCHEMA_FIELD(float                           , strength                                        , 0x0)
        SCHEMA_FIELD(float                           , forceLimit                                      , 0x4)
        SCHEMA_FIELD(float                           , torqueLimit                                     , 0x8)
        SCHEMA_FIELD(float                           , bodyMassScale                                   , 0xC)
        SCHEMA_FIELD(bool                            , isActive                                        , 0x14)
    };

    class IPhysicsParticleRope {
    public:
    };

    class FeTwistConstraint_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNodeOrient                                     , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nNodeEnd                                        , 0x2)
        SCHEMA_FIELD(float                           , flTwistRelax                                    , 0x4)
        SCHEMA_FIELD(float                           , flSwingRelax                                    , 0x8)
    };

    class RnPlane_t {
    public:
        SCHEMA_FIELD(::Vector                        , m_vNormal                                       , 0x0)
        SCHEMA_FIELD(float                           , m_flOffset                                      , 0xC)
    };

    class FeFollowNode_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nParentNode                                     , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nChildNode                                      , 0x2)
        SCHEMA_FIELD(float                           , flWeight                                        , 0x4)
    };

    class FourVectors2D {
    public:
        SCHEMA_FIELD(fltx4                           , x                                               , 0x0)
        SCHEMA_FIELD(fltx4                           , y                                               , 0x10)
    };

    class RnWing_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nIndex                                        , 0x0)
    };

    class FeMorphLayerDepr_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_Name                                          , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nNameHash                                     , 0x8)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_Nodes                                         , 0x10)
        SCHEMA_FIELD(CUtlVector<Vector>              , m_InitPos                                       , 0x28)
        SCHEMA_FIELD(CUtlVector<float32>             , m_Gravity                                       , 0x40)
        SCHEMA_FIELD(CUtlVector<float32>             , m_GoalStrength                                  , 0x58)
        SCHEMA_FIELD(CUtlVector<float32>             , m_GoalDamping                                   , 0x70)
        SCHEMA_FIELD(std::uint32_t                   , m_nFlags                                        , 0x88)
    };

    class FeBuildSDFRigid_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nPriority                                     , 0x50)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexMapHash                                , 0x54)
        SCHEMA_FIELD(std::uint32_t                   , m_nAntitunnelGroupBits                          , 0x58)
    };

    class RnBlendVertex_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nWeight0                                      , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , m_nIndex0                                       , 0x2)
        SCHEMA_FIELD(std::uint16_t                   , m_nWeight1                                      , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , m_nIndex1                                       , 0x6)
        SCHEMA_FIELD(std::uint16_t                   , m_nWeight2                                      , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , m_nIndex2                                       , 0xA)
        SCHEMA_FIELD(std::uint16_t                   , m_nFlags                                        , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , m_nTargetIndex                                  , 0xE)
    };

    class IPhysicsJoint {
    public:
    };

    class FeModelSelfCollisionLayer_t {
    public:
        SCHEMA_FIELD(::CUtlString                    , m_Name                                          , 0x0)
        SCHEMA_FIELD(CUtlVector<uint16>              , m_Nodes                                         , 0x8)
        SCHEMA_FIELD(float                           , m_flParentReaction                              , 0x20)
        SCHEMA_FIELD(std::uint32_t                   , m_nFlags                                        , 0x24)
        SCHEMA_FIELD(std::uint32_t                   , m_nEndIdx                                       , 0x28)
    };

    class FeSourceEdge_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
    };

    class CovMatrix3 {
    public:
        SCHEMA_FIELD(::Vector                        , m_vDiag                                         , 0x0)
        SCHEMA_FIELD(float                           , m_flXY                                          , 0xC)
        SCHEMA_FIELD(float                           , m_flXZ                                          , 0x10)
        SCHEMA_FIELD(float                           , m_flYZ                                          , 0x14)
    };

    class FeNodeBase_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nDummy                                          , 0x2)
        SCHEMA_FIELD(std::uint16_t                   , nNodeX0                                         , 0x8)
        SCHEMA_FIELD(std::uint16_t                   , nNodeX1                                         , 0xA)
        SCHEMA_FIELD(std::uint16_t                   , nNodeY0                                         , 0xC)
        SCHEMA_FIELD(std::uint16_t                   , nNodeY1                                         , 0xE)
        SCHEMA_FIELD(QuaternionStorage               , qAdjust                                         , 0x10)
    };

    class CollisionDetailLayerInfo_t_Name_t {
    public:
        SCHEMA_FIELD(CUtlStringToken                 , m_nNameToken                                    , 0x0)
        SCHEMA_FIELD(::CUtlString                    , m_sNameString                                   , 0x8)
    };

    class FeBuildTaperedCapsuleRigid_t {
    public:
        SCHEMA_FIELD(std::int32_t                    , m_nPriority                                     , 0x30)
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexMapHash                                , 0x34)
        SCHEMA_FIELD(std::uint32_t                   , m_nAntitunnelGroupBits                          , 0x38)
    };

    class FeRigidColliderIndices_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , m_nTaperedCapsuleRigidIndex                     , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , m_nSphereRigidIndex                             , 0x2)
        SCHEMA_FIELD(std::uint16_t                   , m_nBoxRigidIndex                                , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , m_nSDFRigidIndex                                , 0x6)
        SCHEMA_FIELD(std::uint16_t                   , m_nCollisionPlaneIndex                          , 0x8)
    };

    class FeAntiTunnelGroupBuild_t {
    public:
        SCHEMA_FIELD(std::uint32_t                   , m_nVertexMapHash                                , 0x0)
        SCHEMA_FIELD(std::uint32_t                   , m_nCollisionMask                                , 0x4)
    };

    class RnHalfEdge_t {
    public:
        SCHEMA_FIELD(std::uint8_t                    , m_nNext                                         , 0x0)
        SCHEMA_FIELD(std::uint8_t                    , m_nTwin                                         , 0x1)
        SCHEMA_FIELD(std::uint8_t                    , m_nOrigin                                       , 0x2)
        SCHEMA_FIELD(std::uint8_t                    , m_nFace                                         , 0x3)
    };

    class FeAntiTunnelProbeBuild_t {
    public:
        SCHEMA_FIELD(float                           , flWeight                                        , 0x0)
        SCHEMA_FIELD(float                           , flActivationDistance                            , 0x4)
        SCHEMA_FIELD(float                           , flBias                                          , 0x8)
        SCHEMA_FIELD(float                           , flCurvature                                     , 0xC)
        SCHEMA_FIELD(std::uint32_t                   , nFlags                                          , 0x10)
        SCHEMA_FIELD(std::uint16_t                   , nProbeNode                                      , 0x14)
        SCHEMA_FIELD(CUtlVector<uint16>              , targetNodes                                     , 0x18)
    };

    class RnCapsuleDesc_t {
    public:
        SCHEMA_FIELD(RnCapsule_t                     , m_Capsule                                       , 0x18)
    };

    class FeNodeWindBase_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNodeX0                                         , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nNodeX1                                         , 0x2)
        SCHEMA_FIELD(std::uint16_t                   , nNodeY0                                         , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , nNodeY1                                         , 0x6)
    };

    class IPhysAggregateInstance {
    public:
        SCHEMA_FIELD(void*                           , m_pSkeleton                                     , 0x8)
        SCHEMA_FIELD(bool                            , m_bIsAxisAligned                                , 0x10)
    };

    class FeRodConstraint_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(float                           , flMaxDist                                       , 0x4)
        SCHEMA_FIELD(float                           , flMinDist                                       , 0x8)
        SCHEMA_FIELD(float                           , flWeight0                                       , 0xC)
        SCHEMA_FIELD(float                           , flRelaxationFactor                              , 0x10)
    };

    class FeTaperedCapsuleStretch_t {
    public:
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x0)
        SCHEMA_FIELD(std::uint16_t                   , nCollisionMask                                  , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , nDummy                                          , 0x6)
        SCHEMA_FIELD(float                           , flRadius                                        , 0x8)
    };

    class FeBandBendLimit_t {
    public:
        SCHEMA_FIELD(float                           , flDistMin                                       , 0x0)
        SCHEMA_FIELD(float                           , flDistMax                                       , 0x4)
        SCHEMA_FIELD(std::uint16_t                   , nNode                                           , 0x8)
    };

}
