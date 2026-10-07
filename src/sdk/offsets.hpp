

#pragma once

#include <cstddef>
#include <cstdint>

namespace cs2::offsets {

    namespace animationsystem {
        constexpr uintptr_t AnimationSystemUtils_ptr = 0x83F6B8;
    }

    namespace client {
        constexpr uintptr_t GlobalVariables_ptr = 0x222DE98;
        constexpr uintptr_t GameRules_ptr = 0x255EE50;
        constexpr uintptr_t GameEntitySystemPtr = 0x2717828;
        constexpr uintptr_t ParticleManager_ptr = 0x22252E8;
        constexpr uintptr_t CSGOInput_ptr = 0x2578160;
        constexpr uintptr_t ClientMode_ptr = 0x2575EC0;
        constexpr uintptr_t ViewRender_ptr = 0x2568968;
        constexpr uintptr_t VPhys2World_ptr = 0x202F740; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t GetBBox_ptr = 0x255EE50;
        constexpr uintptr_t GetInstanceS = 0x22B95A0; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t GlowManager_ptr = 0x255EE60;
        constexpr uintptr_t Sensitivity_ptr = 0x255F998;
        constexpr uintptr_t EntityList_ptr = 0x2717828;
        constexpr uintptr_t ViewMatrix_addr = 0x2567FA0;
        constexpr uintptr_t PlantedC4Alt_ptr = 0x24CA930;
        constexpr uintptr_t GameRulesAlt_addr = 0x255EE50;
        constexpr uintptr_t Prediction_ptr = 0x2562710;
        constexpr uintptr_t WeaponC4_ptr = 0x24C6AF0;
        constexpr uintptr_t LocalPlayerController_ptr = 0x253A068;
        constexpr uintptr_t global_vars_v2 = 0x222DE98;
        constexpr uintptr_t local_controller = 0x253A068;
        constexpr uintptr_t entity_list_ptr = 0x2717828;
        constexpr uintptr_t view_matrix_ptr = 0x2567FA0;
        constexpr uintptr_t planted_c4_ptr = 0x24CA930;
        constexpr uintptr_t CSGOInput_resolved = 0x2578160;
        constexpr uintptr_t CInputPtrGlobal = 0x223A320;
        constexpr uintptr_t MainMenuPanelPointer = 0x25C6558;
        constexpr uintptr_t HudPanelPointer = 0x25D2F78;
        constexpr uintptr_t GlobalVarsPointer = 0x222DE98;
        constexpr uintptr_t TransformTranslate3dVMT = 0x1CBCD90;
        constexpr uintptr_t TransformScale3dVMT = 0x1CBCDD0;
        constexpr uintptr_t WorldToProjectionMatrixPointer = 0x2567FA0;
        constexpr uintptr_t ViewToProjectionMatrixPointer = 0x2567F60;
        constexpr uintptr_t ManageGlowSceneObjectPointer = 0xB77DC0;
        constexpr uintptr_t SetSceneObjectAttributeFloat4 = 0x16AB80;
        constexpr uintptr_t PointerToClientMode = 0x2575EC0;
        constexpr uintptr_t CvarPointer = 0x2799C78;
        constexpr uintptr_t GetAbsOriginFunction = 0x2197E0;
        constexpr uintptr_t EntitySystemPointer = 0x2717828;
        constexpr uintptr_t GameRulesPointer = 0x255EE50;
        constexpr uintptr_t SetImageFunctionPointer = 0x16701E0; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t ImagePanelConstructorPointer = 0x166D0E0; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t LabelPanelConstructorPointer = 0x163C8F0; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t SetLabelTextFunctionPointer = 0x1647D30; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t UiEnginePointer = 0x2730E60;
        constexpr uintptr_t PlantedC4sPointer = 0x24CA930;
        constexpr uintptr_t GetBombsiteACenter = 0x8CCE70;
        constexpr uintptr_t GetBombsiteBCenter = 0x8CCED0;
        constexpr uintptr_t SliderSetValueFunction = 0x9DDB90; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t TextEntrySetTextFunction = 0x166A110; // not in cs2-sdk dump, old value (needs manual update)
        constexpr uintptr_t SetItemItemIdFunction = 0xE5A9F0;
    }

    namespace engine2 {
        constexpr uintptr_t BuildNumber_addr = 0x61CFE8;
        constexpr uintptr_t NetworkGameClient_ptr = 0x91AFC0;
        constexpr uintptr_t WindowWidth_addr = 0x91F330;
        constexpr uintptr_t WindowHeight_addr = 0x91F334;
        constexpr uintptr_t Engine_PVSManager_ptr = 0x6236A0;
    }

    namespace filesystem_stdio {
        constexpr uintptr_t FullFileSystem_ptr = 0x2143D0;
    }

    namespace inputsystem {
        constexpr uintptr_t InputSystem_ptr = 0x46BC0;
        constexpr uintptr_t InputSystemSvc_ptr = 0x46BC0;
    }

    namespace matchmaking {
        constexpr uintptr_t GameTypes_ptr = 0x1B0FD0;
    }

    namespace networksystem {
        constexpr uintptr_t NetworkSystem_ptr = 0x2911A0;
    }

    namespace panorama {
        constexpr uintptr_t SetPanelStylePropertyFunctionPointer = 0x188AA0; // not in cs2-sdk dump, old value (needs manual update)
    }

    namespace particles {
        constexpr uintptr_t GetParticleManager = 0x5FD890;
    }

    namespace rendersystemdx11 {
        constexpr uintptr_t RenderDeviceMgr_ptr = 0x4342F0;
    }

    namespace scenesystem {
        constexpr uintptr_t SceneSystem_ptr = 0x91FB20;
        constexpr uintptr_t SceneSystemPointer = 0x91FB20;
    }

    namespace schemasystem {
        constexpr uintptr_t SchemaSystem_ptr = 0x76710;
    }

    namespace soundsystem {
        constexpr uintptr_t SoundSystem_ptr = 0x535350;
        constexpr uintptr_t SoundChannelsPointer = 0x657C68;
    }

    namespace tier0 {
        constexpr uintptr_t CVar_ptr = 0x3AC670;
    }
}

namespace cs2_dumper {
    namespace offsets {

        namespace client_dll {
            constexpr std::ptrdiff_t dwCSGOInput = 0x2578160;
            constexpr std::ptrdiff_t dwEntityList = 0x2717828;
            constexpr std::ptrdiff_t dwGameEntitySystem = 0x2717828;
            constexpr std::ptrdiff_t dwGameEntitySystem_highestEntityIndex = 0x2120;
            constexpr std::ptrdiff_t dwGameRules = 0x255EE50;
            constexpr std::ptrdiff_t dwGlobalVars = 0x222DE98;
            constexpr std::ptrdiff_t dwGlowManager = 0x255EE60;
            constexpr std::ptrdiff_t dwLocalPlayerController = 0x253A068;
            constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x2562808;
            constexpr std::ptrdiff_t dwPlantedC4 = 0x24CA930;
            constexpr std::ptrdiff_t dwPrediction = 0x2562710;
            constexpr std::ptrdiff_t dwSensitivity = 0x255F998;
            constexpr std::ptrdiff_t dwSensitivity_sensitivity = 0x58;
            constexpr std::ptrdiff_t dwViewAngles = 0x25787E8;
            constexpr std::ptrdiff_t dwViewMatrix = 0x2567FA0;
            constexpr std::ptrdiff_t dwViewRender = 0x2568968;
            constexpr std::ptrdiff_t dwWeaponC4 = 0x24C6AF0;
        }

        namespace engine2_dll {
            constexpr std::ptrdiff_t dwBuildNumber = 0x61CFE8;
            constexpr std::ptrdiff_t dwNetworkGameClient = 0x91AFC0;
            constexpr std::ptrdiff_t dwNetworkGameClient_clientTickCount = 0x398;
            constexpr std::ptrdiff_t dwNetworkGameClient_deltaTick = 0x24C;
            constexpr std::ptrdiff_t dwNetworkGameClient_isBackgroundMap = 0x2C143F;
            constexpr std::ptrdiff_t dwNetworkGameClient_localPlayer = 0xF8;
            constexpr std::ptrdiff_t dwNetworkGameClient_maxClients = 0x240;
            constexpr std::ptrdiff_t dwNetworkGameClient_serverTickCount = 0x24C;
            constexpr std::ptrdiff_t dwNetworkGameClient_signOnState = 0x230;
            constexpr std::ptrdiff_t dwWindowHeight = 0x91F334;
            constexpr std::ptrdiff_t dwWindowWidth = 0x91F330;
        }

        namespace inputsystem_dll {
            constexpr std::ptrdiff_t dwInputSystem = 0x46BC0;
        }

        namespace matchmaking_dll {
            constexpr std::ptrdiff_t dwGameTypes = 0x1B0FD0;
        }

        namespace soundsystem_dll {
            constexpr std::ptrdiff_t dwSoundSystem = 0x535350;
            constexpr std::ptrdiff_t dwSoundSystem_engineViewData = 0x6C;
        }
    }
}
