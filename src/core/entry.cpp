#include "main.hpp"
#include "../sdk/valve/interfaces/vtables/i_mem_alloc.hpp"
#include "../directx/directx.hpp"
#include "../features/shared/item_schema.hpp"
#include "../features/skin_changer/skin_changer.hpp"
#include "../features/glove_changer/glove_changer.hpp"
#include "../features/jump_bug/jump_bug.hpp"
#include "../sdk/config_system/config_system.hpp"
#include "../sdk/valve/schema/schema.hpp"
#include <stdexcept>
#include <shellapi.h>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

namespace {
void sync_init_progress(int current, const char* status) {
    g_init_progress.current = current + 1;
    g_init_progress.status = status;
}

void configure_feature_dependencies() {
    auto* diag = diagnostics::g_diagnostics.get();
    if (!diag)
        return;

    auto module_ok = [&](const char* name) {
        const auto it = diag->modules().find(name);
        return it != diag->modules().end() && it->second;
    };
    auto iface_ok = [&](const char* name) {
        const auto it = diag->interfaces().find(name);
        return it != diag->interfaces().end() && it->second;
    };
    auto sig_ok = [&](const char* module_name, const char* name) {
        const std::string key = std::string(module_name) + "!" + name;
        const auto it = diag->signatures().find(key);
        return it != diag->signatures().end() && it->second;
    };
    auto hook_ok = [&](const char* name) {
        const auto it = diag->hooks().find(name);
        return it != diag->hooks().end() && it->second;
    };

    diag->define_feature("visuals");
    diag->set_feature_dependency("visuals", "interface", "EntitySystem", true, iface_ok("EntitySystem"));
    diag->set_feature_dependency("visuals", "signature", "client.dll!view_matrix_ptr", true, sig_ok("client.dll", "view_matrix_ptr"));
    diag->finalize_feature("visuals");

    diag->define_feature("aim");
    diag->set_feature_dependency("aim", "interface", "CCSGOInput", true, iface_ok("CCSGOInput"));
    diag->set_feature_dependency("aim", "interface", "EntitySystem", true, iface_ok("EntitySystem"));
    diag->finalize_feature("aim");

    diag->define_feature("movement");
    diag->set_feature_dependency("movement", "interface", "CCSGOInput", true, iface_ok("CCSGOInput"));
    diag->finalize_feature("movement");

    diag->define_feature("skin_changer");
    diag->set_feature_dependency("skin_changer", "interface", "Source2Client002", true, iface_ok("Source2Client002"));
    diag->set_feature_dependency("skin_changer", "signature", "client.dll!ApplyEconCustomization", true, sig_ok("client.dll", "ApplyEconCustomization"));
    diag->set_feature_dependency("skin_changer", "signature", "client.dll!RegenerateWeaponSkin", true, sig_ok("client.dll", "RegenerateWeaponSkin"));
    diag->finalize_feature("skin_changer");

    diag->define_feature("glove_changer");
    diag->set_feature_dependency("glove_changer", "interface", "Source2Client002", true, iface_ok("Source2Client002"));
    diag->finalize_feature("glove_changer");


}
}

void destroy(HMODULE h_module) {
    DBG_INFO("[unload] END pressed, unloading");
    if (g_jump_bug)
        g_jump_bug->shutdown();

    g_hooks->destroy();
    DBG_INFO("[unload] hooks removed");
    logger::shutdown();
    dbg::shutdown();

    FreeLibraryAndExitThread(h_module, 0);
}

uintptr_t __stdcall start_address(const HMODULE h_module) {
    DBG_INFO("[init] init thread started");
    char user_name[64];
    DWORD user_name_len = sizeof(user_name);
    if (GetUserNameA(user_name, &user_name_len) && strcmp(user_name, "geroooooxik") == 0)
        g_is_dev_build = true;

    char docs_path[MAX_PATH], marker_path[MAX_PATH];
    if (GetEnvironmentVariableA("USERPROFILE", docs_path, sizeof(docs_path))) {
        PathAppendA(docs_path, "Documents\\celerity");
        strcpy_s(marker_path, docs_path);
        PathAppendA(marker_path, "initialized.txt");

        if (GetFileAttributesA(marker_path) == INVALID_FILE_ATTRIBUTES) {
            CreateDirectoryA(docs_path, nullptr);
            HANDLE f = CreateFileA(marker_path, GENERIC_WRITE, 0, nullptr, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (f != INVALID_HANDLE_VALUE) {
                DWORD written;
                WriteFile(f, "true", 4, &written, nullptr);
                CloseHandle(f);
            }
            ShellExecuteA(nullptr, nullptr, "https://t.me/blgcy", nullptr, nullptr, SW_SHOW);
        }
    }
    try {
        logger::initialize();
        DBG_INFO("[init] console ready - dll built " __DATE__ " " __TIME__ " - full log in %s", dbg::g_path[0] ? dbg::g_path : "<could not create log file>");
        dbg::init_symbols();
        diagnostics::g_diagnostics->initialize();
        int init_index = 0;

        auto run_step = [&](const char* name, bool required, const char* status, auto&& fn) {
            diagnostics::g_diagnostics->begin_step(name, required);
            sync_init_progress(init_index, status);
            dbg::g_init_step = name;
            DBG_INFO("[init] >> %s%s", name, required ? " (required)" : "");
            const ULONGLONG step_start = GetTickCount64();
            bool success = false;
            std::string detail;
            try {
                success = fn(detail);
            } catch (const std::exception& e) {
                detail = e.what();
                success = false;
            }
            const auto step_ms = static_cast<unsigned long long>(GetTickCount64() - step_start);
            if (success)
                DBG_OK("[init] << %s ok (%llu ms) %s", name, step_ms, detail.c_str());
            else if (required)
                DBG_ERR("[init] << %s FAILED (%llu ms) %s", name, step_ms, detail.c_str());
            else
                DBG_WARN("[init] << %s failed, continuing (%llu ms) %s", name, step_ms, detail.c_str());
            diagnostics::g_diagnostics->finish_step(name, success, detail);
            ++init_index;
            if (required && !success)
                throw std::runtime_error(detail.empty() ? std::string("step failed: ") + name : detail);
        };

        run_step("modules", true, "initializing modules...", [&](std::string& detail) {
            const bool ok = g_modules->m_modules.initialize();
            detail = ok ? "required modules loaded" : "failed to initialize modules";
            logger::init_status("modules", ok);
            return ok;
        });

        run_step("interfaces", true, "initializing interfaces...", [&](std::string& detail) {
            const bool ok = g_interfaces->initialize();
            detail = ok ? "required interfaces resolved" : "failed to initialize interfaces";
            logger::init_status("interfaces", ok);
            return ok;
        });

        run_step("schema offsets", false, "verifying schema offsets...", [&](std::string& detail) {
            schema_verify_known_offsets();
            detail = "schema offsets verified";
            return true;
        });

        run_step("signature verification", false, "verifying signatures...", [&](std::string& detail) {
            g_signatures->verify_all();
            const auto& verification = diagnostics::g_diagnostics->signature_verification();
            detail = std::to_string(verification.resolved) + "/" + std::to_string(verification.total) + " resolved";
            logger::init_status("signatures", verification.required_missing == 0);
            return verification.required_missing == 0;
        });

        run_step("directx bootstrap", false, "initializing directx...", [&](std::string& detail) {
            const bool ok = g_directx->initialize();
            detail = ok ? "swap-chain hooks located" : "overlay hooks unavailable";
            logger::init_status("swapchain", ok);
            return ok;
        });

        run_step("hooks", true, "installing hooks...", [&](std::string& detail) {
            const bool ok = g_hooks->initialize();
            detail = ok ? "required hooks installed" : "failed to initialize hooks";
            logger::init_status("hooks", ok);
            return ok;
        });

        run_step("item schema", false, "loading item schema...", [&](std::string& detail) {
            g_item_schema->initialize();
            const bool ok = g_item_schema->is_initialized();
            detail = ok ? "item schema ready" : "item schema unavailable";
            logger::init_status("item schema", ok);
            return ok;
        });

        run_step("config system", true, "setting up config system...", [&](std::string& detail) {
            g_config_system->setup_values();
            detail = "config system ready";
            return true;
        });

        run_step("skin changer", false, "initializing skin changer...", [&](std::string& detail) {
            g_skin_changer->initialize();
            const bool ok = g_skin_changer->is_initialized();
            detail = ok ? "skin changer ready" : "skin changer deferred";
            logger::init_status("skinchanger", ok);
            return ok;
        });

        run_step("movement", false, "initializing movement...", [&](std::string& detail) {
            g_jump_bug->initialize();
            detail = "movement services ready";
            return true;
        });

        configure_feature_dependencies();

        dbg::g_init_step = "running (init finished)";
        DBG_OK("[init] all steps done - if CS2 crashes now, look for the last [hook] line and the crash report");

        g_init_progress.current = g_init_progress.total;
        g_init_progress.status = "ready";
        g_init_progress.done = true;

        while (!GetAsyncKeyState(VK_END)) {
            Sleep(100);
        }

        destroy(h_module);
    }
    catch (const std::exception& e) {
        DBG_ERR("[init] startup failed in step '%s': %s", dbg::g_init_step, e.what());
        printf("  [startup] failed: %s\n", e.what());
        MessageBoxA(NULL, e.what(), "Exception", MB_OK | MB_ICONERROR);
        logger::shutdown();
        dbg::shutdown();
        FreeLibraryAndExitThread(h_module, 0);
    }
    catch (...) {
        DBG_ERR("[init] startup failed in step '%s': unknown exception", dbg::g_init_step);
        printf("  [startup] failed: unknown exception\n");
        MessageBoxA(NULL, "Unknown exception occurred", "Exception", MB_OK | MB_ICONERROR);
        logger::shutdown();
        dbg::shutdown();
        FreeLibraryAndExitThread(h_module, 0);
    }
}

BOOL APIENTRY DllMain(HMODULE h_module, DWORD ul_reason_for_call, LPVOID lp_reserved) {
    (void)lp_reserved;
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        dbg::init(h_module);
        DBG_INFO("[attach] DllMain attach, InitMemAlloc...");
        InitMemAlloc();
        DBG_INFO("[attach] InitMemAlloc done, starting init thread");
        DisableThreadLibraryCalls(h_module);

        HANDLE thread = CreateThread(nullptr, 0,
                                     reinterpret_cast<LPTHREAD_START_ROUTINE>(start_address),
                                     h_module, 0, nullptr);

        if (thread != nullptr && thread != INVALID_HANDLE_VALUE) {
            CloseHandle(thread);
            return TRUE;
        }

        DBG_ERR("[attach] CreateThread failed: %lu", GetLastError());
        return FALSE;
    }

    if (ul_reason_for_call == DLL_PROCESS_DETACH)
        DBG_INFO("[detach] %s", lp_reserved ? "CS2 process is exiting" : "dll unloaded");

    return TRUE;
}
