

#pragma once

#include <cstdint>

namespace cs2::verified
{

    namespace Entity_tracking__OnAddEntity___OnRemoveEntity_
    {
        constexpr const char* status = "working";
        constexpr std::ptrdiff_t CEntitySystem__m_entityListeners__CUtlVector_ = 0x30;
        constexpr std::ptrdiff_t CEntityIdentity__m_pEntity = 0x0;
        constexpr std::ptrdiff_t CEntityIdentity__m_designerName = 0x20;
    }

    namespace Tracing
    {
        constexpr const char* status = "placeholder";
    }

    namespace ESP
    {
        constexpr const char* status = "working";
        constexpr std::ptrdiff_t C_BaseEntity__m_pGameSceneNode = 0x330;
        constexpr std::ptrdiff_t C_BaseEntity__m_iHealth = 0x34C;
        constexpr std::ptrdiff_t C_BaseEntity__m_lifeState = 0x354;
        constexpr std::ptrdiff_t C_BaseEntity__m_iTeamNum = 0x3EB;
        constexpr std::ptrdiff_t CGameSceneNode__m_vecAbsOrigin = 0xC8;
        constexpr std::ptrdiff_t CSkeletonInstance__m_modelState = 0x140;
        constexpr std::ptrdiff_t CCSPlayerController__m_iszPlayerName = 0x6F4;
        constexpr std::ptrdiff_t CCSPlayerController__m_hPawn = 0x6BC;
        constexpr std::ptrdiff_t CCSPlayerController__m_iCompetitiveRanking = 0x878;
        constexpr std::ptrdiff_t C_CSPlayerPawnBase__m_pWeaponServices = 0x11E0;
        constexpr std::ptrdiff_t C_BasePlayerWeapon__m_iItemDefinitionIndex = 0x1BA;
        constexpr std::ptrdiff_t C_BasePlayerWeapon__m_iClip1 = 0x16D8;
        constexpr std::ptrdiff_t CCSPlayerController_InGameMoneyServices__m_iAccount = 0x40;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_ArmorValue = 0x1C9C;
        constexpr std::ptrdiff_t CCSPlayer_ItemServices__m_bHasHelmet = 0x49;
        constexpr std::ptrdiff_t CCSPlayerController_ActionTrackingServices__m_iKills = 0x30;
        constexpr std::ptrdiff_t CCSPlayerController_ActionTrackingServices__m_iDeaths = 0x34;
        constexpr std::ptrdiff_t EntitySpottedState_t__m_bSpotted = 0x8;
        constexpr std::ptrdiff_t EntitySpottedState_t__m_bSpottedByMask = 0xC;
    }

    namespace FOV_Changer
    {
        constexpr const char* status = "working";
        constexpr std::ptrdiff_t CBasePlayerController__m_iDesiredFOV = 0x784;
        constexpr std::ptrdiff_t CCSPlayer_CameraServices__m_iFOV = 0x290;
        constexpr std::ptrdiff_t CCSPlayer_CameraServices__m_iFOVStart = 0x294;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_pCameraServices = 0x1218;
    }

    namespace Aimbot
    {
        constexpr const char* status = "working";
        constexpr std::ptrdiff_t C_CSGameRules__m_bFreezePeriod = 0x40;
        constexpr std::ptrdiff_t C_CSGameRules__m_bWarmupPeriod = 0x41;
        constexpr std::ptrdiff_t C_CSGameRules__m_bIsValveDS = 0xA4;
        constexpr std::ptrdiff_t C_CSGameRules__m_bHasMatchStarted = 0xB0;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_bWaitForNoAttack = 0x1C68;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_bIsDefusing = 0x1C4A;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_bIsGrabbingHostage = 0x1C4B;
        constexpr std::ptrdiff_t C_BaseEntity__m_MoveType = 0x525;
        constexpr std::ptrdiff_t C_CSWeaponBaseGun__m_zoomLevel = 0x1CB0;
        constexpr std::ptrdiff_t C_CSWeaponBaseGun__m_bNeedsBoltAction = 0x1CCD;
        constexpr std::ptrdiff_t C_CSWeaponBase__m_bInReload = 0x17F4;
        constexpr std::ptrdiff_t C_BasePlayerWeapon__m_iClip1 = 0x16D8;
        constexpr std::ptrdiff_t C_BasePlayerWeapon__m_nNextPrimaryAttackTick = 0x16C8;
        constexpr std::ptrdiff_t CBasePlayerController__m_nTickBase = 0x6B8;
        constexpr std::ptrdiff_t EntitySpottedState_t__m_bSpottedByMask = 0xC;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_iIDEntIndex = 0x33DC;
        constexpr std::ptrdiff_t C_BaseEntity__m_vecVelocity = 0x430;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_pAimPunchServices = 0x1490;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_iShotsFired = 0x1C5C;
        constexpr std::ptrdiff_t C_CSWeaponBase__m_flRecoilIndex = 0x17E0;
    }

    namespace Triggerbot__Seeded_
    {
        constexpr const char* status = "working";
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_iIDEntIndex = 0x33DC;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_iShotsFired = 0x1C5C;
        constexpr std::ptrdiff_t C_CSPlayerPawn__m_pAimPunchServices = 0x1490;
    }

    namespace Skin_Changer
    {
        constexpr const char* status = "working";
        constexpr std::ptrdiff_t C_EconItemView__m_iItemDefinitionIndex = 0x1BA;
        constexpr std::ptrdiff_t C_EconItemView__m_iItemIDLow = 0x1C4;
        constexpr std::ptrdiff_t C_EconItemView__m_iItemIDHigh = 0x1C8;
        constexpr std::ptrdiff_t C_EconItemView__m_iEntityQuality = 0x1C0;
        constexpr std::ptrdiff_t C_EconItemView__m_nFallbackPaintKit = 0x1D0;
        constexpr std::ptrdiff_t C_EconItemView__m_nFallbackSeed = 0x1D4;
        constexpr std::ptrdiff_t C_EconItemView__m_flFallbackWear = 0x1D8;
        constexpr std::ptrdiff_t C_EconItemView__m_nFallbackStatTrak = 0x1DC;
    }

    namespace Knife_Changer
    {
        constexpr const char* status = "working";
        constexpr std::ptrdiff_t C_BasePlayerWeapon__m_nSubclassID = 0x36C;
        constexpr std::ptrdiff_t C_BasePlayerWeapon__m_iItemDefinitionIndex = 0x1BA;
    }

    namespace Glove_Changer
    {
        constexpr const char* status = "placeholder";
    }

}
