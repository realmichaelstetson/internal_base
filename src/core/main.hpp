#pragma once

#include "../config.hpp"

#include <Windows.h>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <dxgi.h>
#include <d3d11.h>

#ifdef _DEBUG
#define WINCALL(func) func
#else
#define WINCALL(func) LI_FN(func).cached()
#endif

#include "../sdk/includes/lazy_importer.hpp"
#include "../sdk/includes/xor.hpp"
#include "../sdk/includes/hash.hpp"
#include "../sdk/includes/minhook/MinHook.h"
#include "../sdk/includes/imgui/imgui.h"
#include "../sdk/includes/imgui/imgui_impl_dx11.h"
#include "../sdk/includes/imgui/imgui_impl_win32.h"
#include "../sdk/console/console.hpp"
#include "../sdk/diagnostics/diagnostics.hpp"
#include "../sdk/typedefs/vec_t.hpp"
#include "../sdk/vfunc/vfunc.hpp"
#include "../utils/utils.hpp"
#include "../sdk/valve/modules/modules.hpp"
#include "../sdk/offsets.hpp"
#include "../sdk/valve/signatures/signatures.hpp"
#include "../sdk/valve/interfaces/interfaces.hpp"
#include "../sdk/valve/schema/schema.hpp"
#include "../../ui/menu/menu.hpp"
#include "../hooks/hooks.hpp"

class c_user_cmd;
struct globals_t {
	c_user_cmd* m_user_cmd = nullptr;
	void* m_local_pawn = nullptr;
	void* m_local_controller = nullptr;
};

inline const auto g_ctx = std::make_unique<globals_t>();

struct InitProgress {
	int current = 0;
	int total = 9;
	bool done = false;
	const char* status = "starting...";
};

inline InitProgress g_init_progress;
inline bool g_is_dev_build = false;
