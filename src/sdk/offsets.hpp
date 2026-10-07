

#pragma once

#include <cstddef>
#include <cstdint>

namespace cs2::offsets {

    namespace animationsystem {
        constexpr uintptr_t AnimationSystemUtils_ptr = 0x812170;
    }

    namespace client {
        constexpr uintptr_t GlobalVariables_ptr = 0x20AF5F0;
        constexpr uintptr_t GameRules_ptr = 0x23C5D28;
        constexpr uintptr_t GameEntitySystemPtr = 0x2571230;
        constexpr uintptr_t ParticleManager_ptr = 0x202FA08;
        constexpr uintptr_t CSGOInput_ptr = 0x23DBC80;
        constexpr uintptr_t ClientMode_ptr = 0x233D8E0;
        constexpr uintptr_t ViewRender_ptr = 0x23CB898;
        constexpr uintptr_t VPhys2World_ptr = 0x202F740;
        constexpr uintptr_t GetBBox_ptr = 0x23C5D28;
        constexpr uintptr_t GetInstanceS = 0x22B95A0;
        constexpr uintptr_t GlowManager_ptr = 0x23C2A58;
        constexpr uintptr_t Sensitivity_ptr = 0x23C3578;
        constexpr uintptr_t EntityList_ptr = 0x2571230;
        constexpr uintptr_t ViewMatrix_addr = 0x23CB830;
        constexpr uintptr_t PlantedC4Alt_ptr = 0x2390A18;
        constexpr uintptr_t GameRulesAlt_addr = 0x23C5D28;
        constexpr uintptr_t Prediction_ptr = 0x23C6170;
        constexpr uintptr_t WeaponC4_ptr = 0x233EF10;
        constexpr uintptr_t LocalPlayerController_ptr = 0x23A0F30;
        constexpr uintptr_t global_vars_v2 = 0x20AF5F0;
        constexpr uintptr_t local_controller = 0x23A0F30;
        constexpr uintptr_t entity_list_ptr = 0x2571230;
        constexpr uintptr_t view_matrix_ptr = 0x23CB830;
        constexpr uintptr_t planted_c4_ptr = 0x2390A18;
        constexpr uintptr_t CSGOInput_resolved = 0x23DBC80;
        constexpr uintptr_t CInputPtrGlobal = 0x23DBC80;
        constexpr uintptr_t MainMenuPanelPointer = 0x238D458;
        constexpr uintptr_t HudPanelPointer = 0x239A2A0;
        constexpr uintptr_t GlobalVarsPointer = 0x20AF5F0;
        constexpr uintptr_t TransformTranslate3dVMT = 0x1AF1888;
        constexpr uintptr_t TransformScale3dVMT = 0x1AFA140;
        constexpr uintptr_t WorldToProjectionMatrixPointer = 0x23CB830;
        constexpr uintptr_t ViewToProjectionMatrixPointer = 0x2330AA0;
        constexpr uintptr_t ManageGlowSceneObjectPointer = 0xADC1A0;
        constexpr uintptr_t SetSceneObjectAttributeFloat4 = 0x173D10;
        constexpr uintptr_t PointerToClientMode = 0x233D8E0;
        constexpr uintptr_t CvarPointer = 0x25419E8;
        constexpr uintptr_t GetAbsOriginFunction = 0x20DA10;
        constexpr uintptr_t EntitySystemPointer = 0x2571230;
        constexpr uintptr_t GameRulesPointer = 0x23C5D28;
        constexpr uintptr_t SetImageFunctionPointer = 0x16701E0;
        constexpr uintptr_t ImagePanelConstructorPointer = 0x166D0E0;
        constexpr uintptr_t LabelPanelConstructorPointer = 0x163C8F0;
        constexpr uintptr_t SetLabelTextFunctionPointer = 0x1647D30;
        constexpr uintptr_t UiEnginePointer = 0x24E81F0;
        constexpr uintptr_t PlantedC4sPointer = 0x2390A18;
        constexpr uintptr_t GetBombsiteACenter = 0x84D250;
        constexpr uintptr_t GetBombsiteBCenter = 0x84D2B0;
        constexpr uintptr_t SliderSetValueFunction = 0x9DDB90;
        constexpr uintptr_t TextEntrySetTextFunction = 0x166A110;
        constexpr uintptr_t SetItemItemIdFunction = 0xDA0D50;
    }

    namespace engine2 {
        constexpr uintptr_t BuildNumber_addr = 0x60F594;
        constexpr uintptr_t NetworkGameClient_ptr = 0x90D4B0;
        constexpr uintptr_t WindowWidth_addr = 0x9118D8;
        constexpr uintptr_t WindowHeight_addr = 0x9118DC;
        constexpr uintptr_t Engine_PVSManager_ptr = 0x6123F0;
    }

    namespace filesystem_stdio {
        constexpr uintptr_t FullFileSystem_ptr = 0x2157A0;
    }

    namespace inputsystem {
        constexpr uintptr_t InputSystem_ptr = 0x45BA0;
        constexpr uintptr_t InputSystemSvc_ptr = 0x45BA0;
    }

    namespace matchmaking {
        constexpr uintptr_t GameTypes_ptr = 0x1ADF80;
    }

    namespace networksystem {
        constexpr uintptr_t NetworkSystem_ptr = 0x286E50;
    }

    namespace panorama {
        constexpr uintptr_t SetPanelStylePropertyFunctionPointer = 0x188AA0;
    }

    namespace particles {
        constexpr uintptr_t GetParticleManager = 0x579590;
    }

    namespace rendersystemdx11 {
        constexpr uintptr_t RenderDeviceMgr_ptr = 0x42B530;
    }

    namespace scenesystem {
        constexpr uintptr_t SceneSystem_ptr = 0x8DB490;
        constexpr uintptr_t SceneSystemPointer = 0x8DB490;
    }

    namespace schemasystem {
        constexpr uintptr_t SchemaSystem_ptr = 0x76800;
    }

    namespace soundsystem {
        constexpr uintptr_t SoundSystem_ptr = 0x54B5D0;
        constexpr uintptr_t SoundChannelsPointer = 0x630030;
    }

    namespace tier0 {
        constexpr uintptr_t CVar_ptr = 0x3A93B0;
    }
}

namespace cs2_dumper {
    namespace offsets {

        namespace client_dll {
            constexpr std::ptrdiff_t dwCSGOInput = 0x23DBC80;
            constexpr std::ptrdiff_t dwEntityList = 0x2571230;
            constexpr std::ptrdiff_t dwGameEntitySystem = 0x2571230;
            constexpr std::ptrdiff_t dwGameEntitySystem_highestEntityIndex = 0x2090;
            constexpr std::ptrdiff_t dwGameRules = 0x23C5D28;
            constexpr std::ptrdiff_t dwGlobalVars = 0x20AF5F0;
            constexpr std::ptrdiff_t dwGlowManager = 0x23C2A58;
            constexpr std::ptrdiff_t dwLocalPlayerController = 0x23A0F30;
            constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x23C6268;
            constexpr std::ptrdiff_t dwPlantedC4 = 0x2390A18;
            constexpr std::ptrdiff_t dwPrediction = 0x23C6170;
            constexpr std::ptrdiff_t dwSensitivity = 0x23C3578;
            constexpr std::ptrdiff_t dwSensitivity_sensitivity = 0x58;
            constexpr std::ptrdiff_t dwViewAngles = 0x23DC308;
            constexpr std::ptrdiff_t dwViewMatrix = 0x23CB830;
            constexpr std::ptrdiff_t dwViewRender = 0x23CB898;
            constexpr std::ptrdiff_t dwWeaponC4 = 0x233EF10;
        }

        namespace engine2_dll {
            constexpr std::ptrdiff_t dwBuildNumber = 0x60F594;
            constexpr std::ptrdiff_t dwNetworkGameClient = 0x90D4B0;
            constexpr std::ptrdiff_t dwNetworkGameClient_clientTickCount = 0x378;
            constexpr std::ptrdiff_t dwNetworkGameClient_deltaTick = 0x24C;
            constexpr std::ptrdiff_t dwNetworkGameClient_isBackgroundMap = 0x2C141F;
            constexpr std::ptrdiff_t dwNetworkGameClient_localPlayer = 0xF8;
            constexpr std::ptrdiff_t dwNetworkGameClient_maxClients = 0x240;
            constexpr std::ptrdiff_t dwNetworkGameClient_serverTickCount = 0x24C;
            constexpr std::ptrdiff_t dwNetworkGameClient_signOnState = 0x230;
            constexpr std::ptrdiff_t dwWindowHeight = 0x9118DC;
            constexpr std::ptrdiff_t dwWindowWidth = 0x9118D8;
        }

        namespace inputsystem_dll {
            constexpr std::ptrdiff_t dwInputSystem = 0x45BA0;
        }

        namespace matchmaking_dll {
            constexpr std::ptrdiff_t dwGameTypes = 0x1ADF80;
        }

        namespace soundsystem_dll {
            constexpr std::ptrdiff_t dwSoundSystem = 0x54B5D0;
            constexpr std::ptrdiff_t dwSoundSystem_engineViewData = 0x7C;
        }
    }
}
