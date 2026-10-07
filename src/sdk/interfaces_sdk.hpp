
#pragma once

#include <cstdint>

namespace cs2::ifaces { inline constexpr std::uint32_t CS2_BUILD = 14189; }

namespace cs2::ifaces {

    namespace animationsystem_dll {
        inline void* AnimationSystem_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x8375F8); }
        inline void* AnimationSystemUtils_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x83F6D8); }
    }

    namespace client_dll {
        inline void* ClientBugBugServic001_Client(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x22317E0); }
        inline void* ClientToolsInfo_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x22317B0); }
        inline void* EmptyWorldService001_Client(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x2215220); }
        inline void* GameClientExports001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x222E458); }
        inline void* LegacyGameUI001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x223E0E0); }
        inline void* Source2Client002(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x255C3A0); }
        inline void* Source2ClientConfig001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x24B92B0); }
        inline void* Source2ClientPrediction001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x2562710); }
        inline void* Source2ClientUI001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x223C960); }
    }

    namespace engine2_dll {
        inline void* BenchmarkService001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x622C80); }
        inline void* BugBugService001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x622D80); }
        inline void* BugService001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x8DB7F0); }
        inline void* ClientServerEngineLoopService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91CE30); }
        inline void* ClientServerSharedHandleSystem001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91C440); }
        inline void* EngineGameUI001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6206E0); }
        inline void* EngineServiceMgr001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91C700); }
        inline void* GameEventSystemClientV001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91C9E0); }
        inline void* GameEventSystemServerV001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91CB10); }
        inline void* GameResourceServiceClientV001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x622DC0); }
        inline void* GameResourceServiceServerV001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x622E20); }
        inline void* GameUIService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x8DBC40); }
        inline void* HostStateMgr001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x623540); }
        inline void* INETSUPPORT_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x61BC30); }
        inline void* InputService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x8DBF20); }
        inline void* KeyValueCache001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6235F0); }
        inline void* MapListService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91AD90); }
        inline void* NetworkClientService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91AF20); }
        inline void* NetworkP2PService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91B260); }
        inline void* NetworkServerService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91B410); }
        inline void* NetworkService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x622F90); }
        inline void* RenderService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91B680); }
        inline void* ScreenshotService001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91B940); }
        inline void* SimpleEngineLoopService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x623650); }
        inline void* SoundService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x622FD0); }
        inline void* Source2EngineToClient001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x61FFF0); }
        inline void* Source2EngineToClientStringTable001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x620050); }
        inline void* Source2EngineToServer001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6200C8); }
        inline void* Source2EngineToServerStringTable001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6200F0); }
        inline void* SplitScreenService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6232B0); }
        inline void* StatsService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91BC80); }
        inline void* ToolService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6233B0); }
        inline void* VENGINE_GAMEUIFUNCS_VERSION005(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x620770); }
        inline void* VProfService_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6233F0); }
    }

    namespace filesystem_stdio_dll {
        inline void* VAsyncFileSystem2_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x214610); }
        inline void* VFileSystem017(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x2143D0); }
    }

    namespace host_dll {
        inline void* DebugDrawQueueManager001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x13FF70); }
        inline void* GameModelInfo001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x13FFB0); }
        inline void* GameSystem2HostHook(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x13FFF0); }
        inline void* HostUtils001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x14F900); }
        inline void* PredictionDiffManager001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x140100); }
        inline void* SaveRestoreDataVersion001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x140230); }
        inline void* SinglePlayerSharedMemory001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x140260); }
        inline void* Source2Host001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1402D0); }
    }

    namespace imemanager_dll {
        inline void* IMEManager001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x37AA0); }
    }

    namespace inputsystem_dll {
        inline void* InputStackSystemVersion001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x44E90); }
        inline void* InputSystemVersion001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x46BC0); }
    }

    namespace localize_dll {
        inline void* Localize_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x59120); }
    }

    namespace matchmaking_dll {
        inline void* GameTypes001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1B0FD0); }
        inline void* MATCHFRAMEWORK_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1B90A0); }
    }

    namespace materialsystem2_dll {
        inline void* FontManager_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1638E0); }
        inline void* MaterialUtils_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x14BD30); }
        inline void* PostProcessingSystem_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x14BC60); }
        inline void* TextLayout_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x14BCC0); }
        inline void* VMaterialSystem2_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x163530); }
    }

    namespace meshsystem_dll {
        inline void* MeshSystem001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x180AB0); }
    }

    namespace navsystem_dll {
        inline void* NavSystem001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x12C000); }
    }

    namespace networksystem_dll {
        inline void* FlattenedSerializersVersion001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x277A50); }
        inline void* NetworkMessagesVersion001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x2A3F30); }
        inline void* NetworkSystemVersion001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x2911A0); }
        inline void* SerializedEntitiesVersion001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x291290); }
    }

    namespace panorama_dll {
        inline void* PanoramaUIEngine001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x5895F0); }
    }

    namespace panorama_text_pango_dll {
        inline void* PanoramaTextServices001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x2BA9D0); }
    }

    namespace panoramauiclient_dll {
        inline void* PanoramaUIClient001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x270710); }
    }

    namespace particles_dll {
        inline void* ParticleSystemMgr003(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x65AEB0); }
    }

    namespace pulse_system_dll {
        inline void* IPulseSystem_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x238120); }
    }

    namespace rendersystemdx11_dll {
        inline void* RenderDeviceMgr001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x4342F0); }
        inline void* RenderUtils_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x434BD0); }
        inline void* VRenderDeviceMgrBackdoor001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x434390); }
    }

    namespace resourcesystem_dll {
        inline void* ResourceSystem013(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x892B0); }
    }

    namespace scenefilecache_dll {
        inline void* ResponseRulesCache001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x11D350); }
        inline void* SceneFileCache002(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x11D478); }
    }

    namespace scenesystem_dll {
        inline void* RenderingPipelines_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x675A00); }
        inline void* SceneSystem_002(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x91FB20); }
        inline void* SceneUtils_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x676760); }
    }

    namespace schemasystem_dll {
        inline void* SchemaSystem_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x76710); }
    }

    namespace server_dll {
        inline void* customnavsystem001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1DA64F0); }
        inline void* EmptyWorldService001_Server(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1E09100); }
        inline void* EntitySubclassUtilsV001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1DB8BC0); }
        inline void* NavGameTest001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1E50DC8); }
        inline void* ServerToolsInfo_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1E2FCB8); }
        inline void* Source2GameClients001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1E2F1E0); }
        inline void* Source2GameDirector001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1F99730); }
        inline void* Source2GameEntities001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1E2F460); }
        inline void* Source2Server001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x1E2F2A0); }
        inline void* Source2ServerConfig001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x2114C98); }
    }

    namespace soundsystem_dll {
        inline void* SoundBugBugService001_Client(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x535BB0); }
        inline void* SoundOpSystem001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x535A90); }
        inline void* SoundOpSystemEdit001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x5359A0); }
        inline void* SoundSystem001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x535350); }
        inline void* VMixEditTool001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x5943D7F); }
    }

    namespace steamaudio_dll {
        inline void* SteamAudio001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x35C1A0); }
    }

    namespace steamclient64_dll {
        inline void* IVALIDATE001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BE0B8); }
        inline void* SteamClient006(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB520); }
        inline void* SteamClient007(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB528); }
        inline void* SteamClient008(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB530); }
        inline void* SteamClient009(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB538); }
        inline void* SteamClient010(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB540); }
        inline void* SteamClient011(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB548); }
        inline void* SteamClient012(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB550); }
        inline void* SteamClient013(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB558); }
        inline void* SteamClient014(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB560); }
        inline void* SteamClient015(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB568); }
        inline void* SteamClient016(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB570); }
        inline void* SteamClient017(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB578); }
        inline void* SteamClient018(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB580); }
        inline void* SteamClient019(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB588); }
        inline void* SteamClient020(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB590); }
        inline void* SteamClient021(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB598); }
        inline void* SteamClient022(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB5A0); }
        inline void* SteamClient023(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16BB5A8); }
        inline void* p2pvoice002(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x14E627F); }
        inline void* p2pvoicesingleton002(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x16960F0); }
    }

    namespace tier0_dll {
        inline void* TestScriptMgr001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x3A1960); }
        inline void* VEngineCvar007(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x3AC670); }
        inline void* VProcessUtils002(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x3A1820); }
        inline void* VStringTokenSystem001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x3D3300); }
    }

    namespace v8system_dll {
        inline void* Source2V8System001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x34790); }
    }

    namespace vphysics2_dll {
        inline void* VPhysics2_Interface_001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x460E60); }
    }

    namespace vscript_dll {
        inline void* VScriptManager010(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x13E430); }
    }

    namespace vstdlib_s64_dll {
        inline void* IVALIDATE001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6F990); }
        inline void* VEngineCvar002(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x6E070); }
    }

    namespace worldrenderer_dll {
        inline void* WorldRendererMgr001(std::uintptr_t module_base) noexcept { return reinterpret_cast<void*>(module_base + 0x236D00); }
    }

}
