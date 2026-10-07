#include "../core/main.hpp"
#include "../directx/directx.hpp"
#include "../../ui/menu/menu.hpp"
#include "../../ui/menu/elements/bind.h"
#include "../features/shared/item_schema.hpp"
#include "../features/skin_changer/skin_changer.hpp"
#include "../features/glove_changer/glove_changer.hpp"
#include "../features/visuals/visuals.hpp"
#include "../features/visuals/teammate_esp.hpp"
#include "../features/visuals/world.hpp"
#include "../features/visuals/fog_handler.hpp"

#include "../features/sounds/hit_sound.hpp"
#include "../features/glow/glow.hpp"
#include "../features/bhop/bhop.hpp"
#include "../features/autostrafe/autostrafe.hpp"
#include "../features/jump_bug/jump_bug.hpp"
#include "../features/aim/aim.hpp"
#include "../features/mini_jump/mini_jump.hpp"
#include "../features/edge_jump/edge_jump.hpp"
#include "../features/world_effects/world_effects.hpp"
#include "../features/chams/chams.hpp"
#include "../features/chams/chams_material.hpp"
#include "../features/jump_stats/jump_stats.hpp"
#include "../features/thirdperson/thirdperson.hpp"
#include "../features/fov_changer/fov_changer.hpp"

#include "../features/viewmodel_changer/viewmodel_changer.hpp"
#include "../features/removals/removals.hpp"
#include "../features/motion_blur/motion_blur.hpp"
#include "../../ui/assets/blur.hpp"

#include "../sdk/valve/interfaces/vtables/i_mem_alloc.hpp"
#include "../sdk/valve/classes/c_view_setup.hpp"
#include "../sdk/valve/classes/c_post_processing.hpp"
#include "../sdk/valve/classes/c_scene_light_obj.hpp"
#include "../sdk/valve/classes/c_scene_object.hpp"

#include "../sdk/verified_features.hpp"
#include "../sdk/valve/interfaces/vtables/i_csgo_input.hpp"
#include "../sdk/valve/interfaces/vtables/i_game_event.hpp"
#include "../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../sdk/includes/hash.hpp"
#include <mmsystem.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <string>
#include <chrono>
#include <unordered_map>

using namespace hooks;

namespace event_hashes {
	constexpr uint32_t round_start = fnv1a::hash_32("round_start");
	constexpr uint32_t round_end = fnv1a::hash_32("round_end");
	constexpr uint32_t round_officially_ended = fnv1a::hash_32("round_officially_ended");
	constexpr uint32_t cs_win_panel_round = fnv1a::hash_32("cs_win_panel_round");
	constexpr uint32_t item_purchase = fnv1a::hash_32("item_purchase");
	constexpr uint32_t player_team = fnv1a::hash_32("player_team");
	constexpr uint32_t player_spawn = fnv1a::hash_32("player_spawn");
	constexpr uint32_t player_death = fnv1a::hash_32("player_death");
	constexpr uint32_t player_disconnect = fnv1a::hash_32("player_disconnect");
	constexpr uint32_t player_hurt = fnv1a::hash_32("player_hurt");
}

static void apply_game_cursor_state(bool menu_open) {
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = false;
	io.WantCaptureMouse = menu_open;
	io.WantCaptureKeyboard = menu_open && ImGui::GetActiveID() != 0;

	auto original = hooks::enable_cursor::m_enable_cursor.get_original<decltype(&hooks::enable_cursor::hk_enable_cursor)>();
	if (!original || !g_interfaces || !g_interfaces->m_input_system)
		return;

	static bool saved_input = true;

	if (menu_open) {
		saved_input = hooks::enable_cursor::m_enable_cursor_input;
		while (ShowCursor(TRUE) < 0) {}
		SetCursor(LoadCursorA(nullptr, IDC_ARROW));
		ClipCursor(nullptr);
		__try {
			original(g_interfaces->m_input_system, false);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	} else {
		const bool requested = saved_input;
		if (requested) {
			while (ShowCursor(TRUE) < 0) {}
			SetCursor(LoadCursorA(nullptr, IDC_ARROW));
		} else {
			while (ShowCursor(FALSE) >= 0) {}
		}
		ClipCursor(nullptr);
		__try {
			original(g_interfaces->m_input_system, requested);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}
}

static bool draw_loading_overlay() {
	ImGuiIO& io = ImGui::GetIO();
	ImDrawList* dl = ImGui::GetBackgroundDrawList();

	static float overlay_alpha = 0.0f;
	if (!g_init_progress.done) {
		overlay_alpha = 1.0f;
	} else {
		overlay_alpha -= io.DeltaTime * 2.8f;
		if (overlay_alpha < 0.0f)
			overlay_alpha = 0.0f;
	}

	if (overlay_alpha <= 0.0f && g_init_progress.done)
		return false;

	ImFont* font = ImGui::GetFont();
	if (!font)
		return false;
	const float font_size = font->FontSize;

	char text[64]{};
	snprintf(text, sizeof(text), "initialization: %d/%d",
	         std::clamp(g_init_progress.current, 0, g_init_progress.total),
	         (std::max)(g_init_progress.total, 0));

	ImVec2 text_size = font->CalcTextSizeA(font_size, FLT_MAX, 0.0f, text);
	const float padding_x = 7.0f;
	const float box_w = std::floor(text_size.x + padding_x * 2.0f);
	const float box_h = 20.0f;
	const float line_h = 2.0f;

	float bx = io.DisplaySize.x - box_w - 20.0f;
	float by = 20.0f;

	ImU32 bg = IM_COL32(17, 18, 22, (int)(128.0f * overlay_alpha));
	dl->AddRectFilled(ImVec2(bx, by), ImVec2(bx + box_w, by + box_h), bg);

	ImVec4 accent = g_cfg ? g_cfg->menu.m_menu_color : ImVec4(1.0f, 0.714f, 0.973f, 1.0f);
	accent.w = overlay_alpha;
	const ImU32 accent_full = ImGui::ColorConvertFloat4ToU32(accent);
	const ImU32 accent_clear = ImGui::ColorConvertFloat4ToU32(ImVec4(accent.x, accent.y, accent.z, 0.0f));
	dl->AddRectFilledMultiColor(ImVec2(bx, by), ImVec2(bx + box_w * 0.5f, by + line_h),
	                            accent_clear, accent_full, accent_full, accent_clear);
	dl->AddRectFilledMultiColor(ImVec2(bx + box_w * 0.5f, by), ImVec2(bx + box_w, by + line_h),
	                            accent_full, accent_clear, accent_clear, accent_full);

	float text_x = bx + std::floor((box_w - text_size.x) * 0.5f);
	float text_y = by + std::floor((box_h - text_size.y) * 0.5f);
	dl->AddText(font, font_size, ImVec2(text_x, text_y),
	            IM_COL32(245, 247, 250, (int)(255.0f * overlay_alpha)), text);
	return true;
}

inline uint32_t hash_event_name(const char* str) {
	uint32_t hash = fnv1a::val_32_const;
	while (*str) {
		hash = (hash ^ static_cast<uint8_t>(*str)) * fnv1a::prime_32_const;
		str++;
	}
	return hash;
}

inline bool try_hash_event_name(const char* str, uint32_t& out_hash) {
	if (!str)
		return false;

	__try {
		out_hash = hash_event_name(str);
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		out_hash = 0;
		return false;
	}
}

inline void* get_local_controller_safe() {
	if (g_ctx && g_ctx->m_local_controller)
		return g_ctx->m_local_controller;

	if (!g_interfaces || !g_interfaces->m_entity_system)
		return nullptr;

	__try {
		return g_interfaces->m_entity_system->get_local_controller();
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return nullptr;
	}
}

inline bool is_local_controller(void* controller) {
	return controller && controller == get_local_controller_safe();
}

inline bool is_event_controller_local(void* p_game_event, const char* token_name) {
	if (!p_game_event || !token_name || !i_game_event::get_player_controller)
		return false;

	i_game_event::CUtlStringToken token(token_name);
	token.pad = 0xFFFFFFFF;

	void* event_controller = nullptr;
	__try {
		event_controller = i_game_event::get_player_controller(p_game_event, &token);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}

	return event_controller && event_controller == get_local_controller_safe();
}

namespace custom_paint {
	struct raw_vector_t {
		void* elements;
		int size;
		int capacity;
	};

	enum { LOOSE_VAR_COLOR4 = 9 };

	struct CompositeMaterialInputLooseVariable_t {
		char* m_strName;
		std::uint8_t pad_008[0x38];
		std::int32_t m_nVariableType;
		std::uint8_t pad_044[0x48];
		std::uint32_t m_cValueColor4;
		std::uint8_t pad_090[0x288 - 0x90];
	};

	static_assert(offsetof(CompositeMaterialInputLooseVariable_t, m_nVariableType) == 0x40);
	static_assert(offsetof(CompositeMaterialInputLooseVariable_t, m_cValueColor4) == 0x8C);
	static_assert(sizeof(CompositeMaterialInputLooseVariable_t) == 0x288);

	using append_fn = void(__fastcall*)(void*, const CompositeMaterialInputLooseVariable_t*);

	struct vector_state_t {
		bool glove_material = false;
		bool weapon_colors_appended = false;
		bool glove_colors_appended = false;
		uint16_t weapon_def_index = 0;
	};

	std::unordered_map<void*, vector_state_t> g_vector_states;
	thread_local uint16_t g_weapon_material_def_index = 0;
	thread_local int g_weapon_material_depth = 0;

	void reset_cached_vectors() {
		g_vector_states.clear();
	}

	uint16_t read_weapon_def_index(void* weapon) {
		if (!valid_ptr(weapon))
			return 0;

		__try {
			auto* econ = reinterpret_cast<c_econ_entity*>(weapon);
			auto* attr_mgr = econ->m_attribute_manager();
			if (!valid_ptr(attr_mgr))
				return 0;

			auto* item = attr_mgr->m_item();
			if (!valid_ptr(item))
				return 0;

			return item->m_definition_index();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return 0;
		}
	}

	uint16_t push_weapon_context(void* weapon) {
		const uint16_t previous = g_weapon_material_def_index;
		g_weapon_material_def_index = read_weapon_def_index(weapon);
		++g_weapon_material_depth;
		return previous;
	}

	void pop_weapon_context(uint16_t previous_def_index) {
		if (g_weapon_material_depth > 0)
			--g_weapon_material_depth;

		g_weapon_material_def_index = previous_def_index;
	}

	uint16_t current_weapon_context_def_index() {
		return g_weapon_material_depth > 0 ? g_weapon_material_def_index : 0;
	}

	char* tier0_dup(const char* str) {
		if (!str)
			return nullptr;

		using alloc_fn = void* (__fastcall*)(std::size_t);
		static auto alloc = reinterpret_cast<alloc_fn>(
			GetProcAddress(GetModuleHandleA("tier0.dll"), "MemAlloc_AllocFunc"));
		if (!alloc)
			return nullptr;

		const std::size_t len = std::strlen(str) + 1;
		auto* out = static_cast<char*>(alloc(len));
		if (!out)
			return nullptr;

		std::memcpy(out, str, len);
		return out;
	}

	const ImVec4* weapon_colors_for_def_index(uint16_t def_index, int& count) {
		count = 0;
		if (!g_cfg || def_index == 0)
			return nullptr;

		const bool is_knife = def_index == WEAPON_KNIFE || def_index == WEAPON_KNIFE_T || (def_index >= 500 && def_index <= 526);
		if (is_knife && g_cfg->knife_changer.m_enabled && g_cfg->knife_changer.m_paint_color) {
			count = 4;
			return g_cfg->knife_changer.m_paint_colors;
		}

		const int config_index = c_config::skin_changer_t::get_config_index(def_index);
		if (config_index > 0) {
			auto& skin = g_cfg->skin_changer.weapon_skins[config_index];
			if (skin.paint_color) {
				count = 4;
				return skin.paint_colors;
			}
		}

		return nullptr;
	}

	uint16_t active_weapon_paint_def_index() {
		int count = 0;
		const uint16_t def_index = current_weapon_context_def_index();
		if (weapon_colors_for_def_index(def_index, count))
			return def_index;

		return 0;
	}

	const ImVec4* active_weapon_colors(int& count, uint16_t def_index = 0) {
		if (def_index == 0)
			def_index = active_weapon_paint_def_index();

		return weapon_colors_for_def_index(def_index, count);
	}

	const ImVec4* active_glove_colors(int& count) {
		count = 0;
		if (!g_cfg || !g_cfg->glove_changer.m_enabled || !g_cfg->glove_changer.m_paint_color)
			return nullptr;

		count = 8;
		return g_cfg->glove_changer.m_paint_colors;
	}

	std::uint32_t pack_color4(const ImVec4& color) {
		auto to_u8 = [](float value) {
			const float clamped = std::clamp(value, 0.0f, 1.0f);
			return static_cast<std::uint32_t>(clamped * 255.0f + 0.5f);
		};

		const std::uint32_t r = to_u8(color.x);
		const std::uint32_t g = to_u8(color.y);
		const std::uint32_t b = to_u8(color.z);
		const std::uint32_t a = to_u8(color.w);
		return r | (g << 8) | (b << 16) | (a << 24);
	}

	const char* safe_name(const CompositeMaterialInputLooseVariable_t* var) {
		if (!var)
			return nullptr;

		__try {
			return var->m_strName;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	bool safe_equals(const char* lhs, const char* rhs) {
		if (!lhs || !rhs)
			return false;

		__try {
			return std::strcmp(lhs, rhs) == 0;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}
	}

	int color_trigger_index(const char* name) {
		if (!name)
			return -1;

		__try {
			if (std::strncmp(name, "g_vColor", 8) != 0)
				return -1;

			const char index_char = name[8];
			if (index_char < '0' || index_char > '3' || name[9] != '\0')
				return -1;

			return index_char - '0';
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return -1;
		}
	}

	int glove_color_trigger_index(const char* name) {
		if (!name)
			return -1;

		__try {
			constexpr const char* top_prefix = "g_vGloveColorTop";
			constexpr const char* bottom_prefix = "g_vGloveColorBottom";
			constexpr std::size_t top_len = 16;
			constexpr std::size_t bottom_len = 19;

			if (std::strncmp(name, top_prefix, top_len) == 0) {
				const char index_char = name[top_len];
				if (index_char >= '0' && index_char <= '3' && name[top_len + 1] == '\0')
					return index_char - '0';
				if (index_char >= '1' && index_char <= '4' && name[top_len + 1] == '\0')
					return index_char - '1';
			}

			if (std::strncmp(name, bottom_prefix, bottom_len) == 0) {
				const char index_char = name[bottom_len];
				if (index_char >= '0' && index_char <= '3' && name[bottom_len + 1] == '\0')
					return 4 + (index_char - '0');
				if (index_char >= '1' && index_char <= '4' && name[bottom_len + 1] == '\0')
					return 4 + (index_char - '1');
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return -1;
		}

		return -1;
	}

	void append_color_var(void* vector, append_fn append, const char* name, const ImVec4& color) {
		if (!vector || !append || !name)
			return;

		CompositeMaterialInputLooseVariable_t var{};
		var.m_strName = tier0_dup(name);
		if (!var.m_strName)
			return;

		var.m_nVariableType = LOOSE_VAR_COLOR4;
		var.m_cValueColor4 = pack_color4(color);
		append(vector, &var);
		GameFree(var.m_strName);
	}

	void append_weapon_colors(void* vector, append_fn append, const ImVec4* colors, int color_count) {
		if (!vector || !append || !colors || color_count <= 0)
			return;

		const int count = (std::min)(color_count, 4);
		for (int i = 0; i < count; ++i) {
			char name[16];
			snprintf(name, sizeof(name), "g_vColor%d", i);
			append_color_var(vector, append, name, colors[i]);
		}
	}

	void append_glove_colors(void* vector, append_fn append, const ImVec4* colors, int color_count) {
		if (!vector || !append || !colors || color_count <= 0)
			return;

		const int primary_count = (std::min)(color_count, 4);
		for (int i = 0; i < primary_count; ++i) {
			char name[16];
			snprintf(name, sizeof(name), "g_vColor%d", i);
			append_color_var(vector, append, name, colors[i]);
		}

		const int pair_count = (std::min)(color_count, 8);
		for (int i = 0; i < pair_count && i < 4; ++i) {
			char name[32];
			snprintf(name, sizeof(name), "g_vGloveColorTop%d", i);
			append_color_var(vector, append, name, colors[i]);
		}

		for (int i = 4; i < pair_count; ++i) {
			char name[32];
			snprintf(name, sizeof(name), "g_vGloveColorBottom%d", i - 4);
			append_color_var(vector, append, name, colors[i]);
		}
	}

	void 	maybe_append_config_colors(void* vector, append_fn append, vector_state_t& state, bool use_glove_colors) {
		if (use_glove_colors) {
			if (state.glove_colors_appended)
				return;

			int color_count = 0;
			const ImVec4* colors = active_glove_colors(color_count);
			if (!colors || color_count <= 0)
				return;

			append_glove_colors(vector, append, colors, color_count);
			state.glove_colors_appended = true;
			return;
		}

		if (state.weapon_colors_appended)
			return;

		const uint16_t current_def_index = active_weapon_paint_def_index();
		if (current_def_index == 0) {
			state.weapon_def_index = 0;
			state.weapon_colors_appended = false;
			return;
		}

		if (state.weapon_def_index != current_def_index) {
			state.weapon_def_index = current_def_index;
			state.weapon_colors_appended = false;
		}

		int color_count = 0;
		const ImVec4* colors = active_weapon_colors(color_count, state.weapon_def_index);
		if (!colors || color_count <= 0)
			return;

		append_weapon_colors(vector, append, colors, color_count);
		state.weapon_colors_appended = true;
	}

	void append_loose_variable(void* vector, const CompositeMaterialInputLooseVariable_t* input, append_fn append) {
		if (!vector || !input || !append)
			return;

		__try {
			auto* raw_vector = reinterpret_cast<raw_vector_t*>(vector);
			if (raw_vector->size <= 0) {
				g_vector_states[vector] = {};

				if (g_vector_states.size() > 256)
					g_vector_states.clear();
			}

			auto& state = g_vector_states[vector];
			const char* name = safe_name(input);

			if (safe_equals(name, "g_nRandomSeedAlt")) {
				state.glove_material = true;
				append(vector, input);
				maybe_append_config_colors(vector, append, state, true);
				return;
			}

			int color_index = glove_color_trigger_index(name);
			if (color_index >= 0)
				state.glove_material = true;
			else
				color_index = color_trigger_index(name);

			if (safe_equals(name, "g_nRandomSeed")) {
				append(vector, input);
				if (state.weapon_def_index == 0)
					state.weapon_def_index = active_weapon_paint_def_index();
				maybe_append_config_colors(vector, append, state, false);
				return;
			}

			if (color_index < 0) {
				append(vector, input);
				return;
			}

			int color_count = 0;
			if (!state.glove_material) {
				const uint16_t current_def_index = active_weapon_paint_def_index();
				if (current_def_index == 0) {
					append(vector, input);
					return;
				}

				if (state.weapon_def_index != current_def_index) {
					state.weapon_def_index = current_def_index;
					state.weapon_colors_appended = false;
				}
			}

			const ImVec4* colors = state.glove_material ? active_glove_colors(color_count) : active_weapon_colors(color_count, state.weapon_def_index);
			if (!colors || color_index >= color_count) {
				append(vector, input);
				return;
			}

			CompositeMaterialInputLooseVariable_t replaced = *input;
			replaced.m_strName = tier0_dup(name);
			if (!replaced.m_strName) {
				append(vector, input);
				return;
			}

			replaced.m_nVariableType = LOOSE_VAR_COLOR4;
			replaced.m_cValueColor4 = pack_color4(colors[color_index]);
			append(vector, &replaced);
			GameFree(replaced.m_strName);
			maybe_append_config_colors(vector, append, state, state.glove_material);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			append(vector, input);
		}
	}
}

namespace knife_db {
	struct entry { std::uint16_t def; const char* full; };
	inline constexpr entry kSkinKnives[] = {
		{500, "weapon_bayonet"},                {503, "weapon_knife_css"},
		{505, "weapon_knife_flip"},             {506, "weapon_knife_gut"},
		{507, "weapon_knife_karambit"},         {508, "weapon_knife_m9_bayonet"},
		{509, "weapon_knife_tactical"},         {512, "weapon_knife_falchion"},
		{514, "weapon_knife_survival_bowie"},   {515, "weapon_knife_butterfly"},
		{516, "weapon_knife_push"},             {517, "weapon_knife_cord"},
		{518, "weapon_knife_canis"},            {519, "weapon_knife_ursus"},
		{520, "weapon_knife_gypsy_jackknife"},  {521, "weapon_knife_outdoor"},
		{522, "weapon_knife_stiletto"},         {523, "weapon_knife_widowmaker"},
		{525, "weapon_knife_skeleton"},         {526, "weapon_knife_kukri"},
	};

	inline const char* lookup(std::uint16_t def) {
		for (auto& e : kSkinKnives)
			if (e.def == def) return e.full;
		return nullptr;
	}

	inline bool matches(const char* name) {
		if (!name || !*name) return false;
		if (std::strncmp(name, "weapon_", 7) == 0) name += 7;
		if (std::strcmp(name, "knife") == 0 || std::strcmp(name, "knife_t") == 0)
			return true;
		for (auto& e : kSkinKnives)
			if (std::strcmp(name, e.full + 7) == 0) return true;
		return false;
	}
}

static const char* get_knife_weapon_name(int knife_index) {
	if (knife_index <= 0
		|| !g_item_schema->is_initialized()
		|| knife_index >= (int)g_item_schema->knives.size())
		return nullptr;
	return knife_db::lookup(g_item_schema->knives[knife_index].definition_index);
}

static bool feature_enabled(const char* name) {
	return diagnostics::g_diagnostics->is_feature_available(name);
}

void __fastcall hooks::get_viewmodel_offsets::hk_get_viewmodel_offsets(uintptr_t viewmodel, float* out_offsets, float* out_fov) {
	auto original = m_get_viewmodel_offsets.get_original<decltype(&hk_get_viewmodel_offsets)>();
	if (!original)
		return;

	original(viewmodel, out_offsets, out_fov);
	viewmodel_changer::apply(viewmodel, out_offsets, out_fov);
}

float __fastcall hooks::get_world_fov::hk_get_world_fov(uintptr_t rcx) {
	auto original = m_get_world_fov.get_original<decltype(&hk_get_world_fov)>();

	if (fov_changer::should_override_world_fov())
		return static_cast<float>(fov_changer::get_world_fov_value());

	if (original)
		return original(rcx);

	return 90.0f;
}

void __fastcall hooks::override_view::hk_override_view(void* client_mode, void* view_setup_ptr) {
	auto original = m_override_view.get_original<decltype(&hk_override_view)>();
	if (!original)
		return;

	original(client_mode, view_setup_ptr);

	auto* view_setup = static_cast<c_view_setup*>(view_setup_ptr);
	if (!view_setup)
		return;

	removals::override_view(view_setup);
	g_thirdperson->override_view(view_setup);
}

void __fastcall hooks::build_legacy_weapon_skin_material::hk_build_legacy_weapon_skin_material(void* weapon, bool force) {
	auto original = m_build_legacy_weapon_skin_material.get_original<decltype(&hk_build_legacy_weapon_skin_material)>();
	if (!original)
		return;

	const uint16_t previous_def_index = custom_paint::push_weapon_context(weapon);
	__try {
		original(weapon, force);
	}
	__finally {
		custom_paint::pop_weapon_context(previous_def_index);
	}
}

void __fastcall hooks::build_modern_weapon_skin_material::hk_build_modern_weapon_skin_material(void* weapon, void* a2, void* a3, int a4, char a5, char a6, void* a7) {
	auto original = m_build_modern_weapon_skin_material.get_original<decltype(&hk_build_modern_weapon_skin_material)>();
	if (!original)
		return;

	const uint16_t previous_def_index = custom_paint::push_weapon_context(weapon);
	__try {
		original(weapon, a2, a3, a4, a5, a6, a7);
	}
	__finally {
		custom_paint::pop_weapon_context(previous_def_index);
	}
}

void __fastcall hooks::composite_material_input::hk_add_to_tail(void* vector, const void* input) {
	auto original = m_add_to_tail.get_original<decltype(&hk_add_to_tail)>();
	if (!original)
		return;

	custom_paint::append_loose_variable(
		vector,
		reinterpret_cast<const custom_paint::CompositeMaterialInputLooseVariable_t*>(input),
		reinterpret_cast<custom_paint::append_fn>(original));
}

bool c_hooks::initialize() {
	const MH_STATUS mh_status = MH_Initialize();
	if (mh_status != MH_OK && mh_status != MH_ERROR_ALREADY_INITIALIZED) {
		LOG_ERROR(xorstr_("[hooks] MH_Initialize failed: %d"), mh_status);
		return false;
	}

	if (!g_interfaces || !g_interfaces->m_csgo_input || !g_interfaces->m_input_system) {
		LOG_ERROR(xorstr_("[hooks] required interfaces are missing"));
		return false;
	}

	bool required_ok = true;
	auto hook_required = [&required_ok](c_hook& hook, void* target, void* detour, const char* name) {
		const bool ok = hook.hook(target, detour);
		diagnostics::g_diagnostics->mark_hook(name, ok, true);
		if (!ok) {
			LOG_ERROR(xorstr_("[hooks] required hook failed: %s"), name);
			required_ok = false;
		}
	};

	auto hook_optional = [](c_hook& hook, void* target, void* detour, const char* name) {
		if (!target) {
			diagnostics::g_diagnostics->mark_hook(name, false, false);
			LOG_ERROR(xorstr_("[hooks] optional hook target missing: %s"), name);
			return;
		}

		const bool ok = hook.hook(target, detour);
		diagnostics::g_diagnostics->mark_hook(name, ok, false);
		if (!ok)
			LOG_ERROR(xorstr_("[hooks] optional hook failed: %s"), name);
	};

	hook_required(create_move::m_create_move, vmt::get_v_method(g_interfaces->m_csgo_input, 5), create_move::hk_create_move, "CreateMove");
	hook_optional(process_input::m_process_input,
		SIG("CCSGOInput::ProcessInput"),
		process_input::hk_process_input,
		"ProcessInput");
	hook_required(mouse_input_enabled::m_mouse_input_enabled, vmt::get_v_method(g_interfaces->m_csgo_input, 23), mouse_input_enabled::hk_mouse_input_enabled, "MouseInputEnabled");
	hook_required(enable_cursor::m_enable_cursor, vmt::get_v_method(g_interfaces->m_input_system, 76), enable_cursor::hk_enable_cursor, "EnableCursor");

	if (!required_ok)
		return false;

	hook_required(frame_stage_notify::m_frame_stage_notify,
		SIG("FrameStageNotify"),
		frame_stage_notify::hk_frame_stage_notify,
		"FrameStageNotify"
	);

	{
		i_game_event::get_name = reinterpret_cast<i_game_event::GetNameFn>(SIG("GameEvent::GetName"));
		i_game_event::get_string = reinterpret_cast<i_game_event::GetStringFn>(SIG("GameEvent::GetString"));
		i_game_event::set_string = reinterpret_cast<i_game_event::SetStringFn>(SIG("GameEvent::SetString"));
		i_game_event::get_player_controller = reinterpret_cast<i_game_event::GetPlayerControllerFn>(SIG("GameEvent::GetPlayerController"));
	}

	hook_required(fire_event_client_side::m_fire_event_client_side,
		SIG("FireEventClientSide"),
		fire_event_client_side::hk_fire_event_client_side,
		"FireEventClientSide"
	);

	hook_required(level_init::m_level_init,
		SIG("LevelInit"),
		level_init::hk_level_init,
		"LevelInit"
	);

	if (!required_ok)
		return false;

	hook_optional(present::m_present, g_directx->m_present_address, present::hk_present, "Present");
	hook_optional(resize_buffers::m_resize_buffers, g_directx->m_resize_buffers_address, resize_buffers::hk_resize_buffers, "ResizeBuffers");
	hook_optional(create_swap_chain::m_create_swap_chain, g_directx->m_create_swap_chain_address, create_swap_chain::hk_create_swap_chain, "CreateSwapChain");

	hook_optional(get_viewmodel_offsets::m_get_viewmodel_offsets, SIG("GetViewModelOffsets"), get_viewmodel_offsets::hk_get_viewmodel_offsets, "GetViewModelOffsets");
	hook_optional(get_world_fov::m_get_world_fov, SIG("GetWorldFovResolver"), get_world_fov::hk_get_world_fov, "GetWorldFovResolver");
	hook_optional(override_view::m_override_view, SIG("OverrideView"), override_view::hk_override_view, "OverrideView");
	hook_optional(build_legacy_weapon_skin_material::m_build_legacy_weapon_skin_material,
		SIG("C_EconEntity_BuildLegacyWeaponSkinMaterial"),
		build_legacy_weapon_skin_material::hk_build_legacy_weapon_skin_material,
		"C_EconEntityBuildLegacyWeaponSkinMaterial");
	hook_optional(build_modern_weapon_skin_material::m_build_modern_weapon_skin_material,
		SIG("C_EconEntity_BuildModernWeaponSkinMaterial"),
		build_modern_weapon_skin_material::hk_build_modern_weapon_skin_material,
		"C_EconEntityBuildModernWeaponSkinMaterial");

	hook_optional(glow_should_glow::m_should_glow, SIG("GlowManagerShouldGlow"), glow_should_glow::hk_should_glow, "GlowManagerShouldGlow");
	hook_optional(glow_apply_glow::m_apply_glow, SIG("GlowManagerApplyGlow"), glow_apply_glow::hk_apply_glow, "GlowManagerApplyGlow");
	hook_optional(composite_material_input::m_add_to_tail,
		SIG("CompositeMaterialInputLooseVariable_AddToTail"),
		composite_material_input::hk_add_to_tail,
		"CompositeMaterialInputLooseVariableAddToTail");

	hook_optional(draw_skybox_array::m_draw_skybox_array,
		SIG("DrawSkyboxArray"),
		draw_skybox_array::hk_draw_skybox_array,
		"DrawSkyboxArray");

	hook_optional(draw_scope::m_draw_scope,
		SIG("DrawScope"),
		draw_scope::hk_draw_scope,
		"DrawScope");

	hook_optional(smoke_volume_draw_array::m_smoke_volume_draw_array,
		SIG("SmokeVolumeDrawArray"),
		smoke_volume_draw_array::hk_smoke_volume_draw_array,
		"SmokeVolumeDrawArray");

	hook_optional(first_person_legs::m_first_person_legs,
		SIG("FirstPersonLegs"),
		first_person_legs::hk_first_person_legs,
		"FirstPersonLegs");

	hook_optional(update_post_processing::m_update_post_processing,
		SIG("UpdatePostProcessing"),
		update_post_processing::hk_update_post_processing,
		"UpdatePostProcessing");

	hook_optional(draw_aggregate_scene_object::m_draw_aggregate_scene_object,
		SIG("DrawAggregateSceneObject"),
		draw_aggregate_scene_object::hk_draw_aggregate_scene_object,
		"DrawAggregateSceneObject");

	hook_optional(draw_light_scene::m_draw_light_scene,
		SIG("DrawLightScene"),
		draw_light_scene::hk_draw_light_scene,
		"DrawLightScene");

	hook_optional(draw_aggregate_sceneobject_array::m_draw_aggregate_sceneobject_array,
		SIG("DrawAggregateSceneObjectArray"),
		draw_aggregate_sceneobject_array::hk_draw_aggregate_sceneobject_array,
		"DrawAggregateSceneObjectArray");

	// GeneratePrimitives lives at index 4 of the AnimatableSceneObjectDesc's vtable.
	// Resolve it the same way the known-working reference does, rather than via a raw
	// byte signature: the signature-named function is a DIFFERENT symbol from the
	// desc's virtual method, so its argument convention would not match our
	// (desc, object, a3, render_buf) prototype -- the passthrough (chams-off) path
	// still works because we forward the args verbatim, but as soon as we treat arg #4
	// as the output buffer it points at garbage and corrupts memory. The vtable slot is
	// the exact function whose prototype this hook was written against.
	void* animatable_desc = g_interfaces->m_scene_system
		? g_interfaces->m_scene_system->get_scene_object_desc(xorstr_("AnimatableSceneObjectDesc"))
		: nullptr;
	hook_optional(generate_primitives::m_generate_primitives,
		animatable_desc ? vmt::get_v_method(animatable_desc, 4) : nullptr,
		generate_primitives::hk_generate_primitives,
		"CSceneAnimatableObject::GeneratePrimitives");

	return true;
}

void c_hooks::destroy() {
	if (g_menu->m_opened) {
		ImGui::GetIO().MouseDrawCursor = false;
		ShowCursor(TRUE);

		auto original = enable_cursor::m_enable_cursor.get_original<decltype(&enable_cursor::hk_enable_cursor)>();
		if (original) {
			__try {
				original(g_interfaces->m_input_system, enable_cursor::m_enable_cursor_input);
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {}
		}
	}

	g_menu->m_opened = true;

	present::m_present.unhook();
	resize_buffers::m_resize_buffers.unhook();
	create_swap_chain::m_create_swap_chain.unhook();
	get_viewmodel_offsets::m_get_viewmodel_offsets.unhook();
	get_world_fov::m_get_world_fov.unhook();
	override_view::m_override_view.unhook();
	build_legacy_weapon_skin_material::m_build_legacy_weapon_skin_material.unhook();
	build_modern_weapon_skin_material::m_build_modern_weapon_skin_material.unhook();
	glow_should_glow::m_should_glow.unhook();
	glow_apply_glow::m_apply_glow.unhook();

	composite_material_input::m_add_to_tail.unhook();

	draw_skybox_array::m_draw_skybox_array.unhook();
	draw_scope::m_draw_scope.unhook();
	smoke_volume_draw_array::m_smoke_volume_draw_array.unhook();
	first_person_legs::m_first_person_legs.unhook();
	update_post_processing::m_update_post_processing.unhook();
	draw_aggregate_scene_object::m_draw_aggregate_scene_object.unhook();
	draw_light_scene::m_draw_light_scene.unhook();
	draw_aggregate_sceneobject_array::m_draw_aggregate_sceneobject_array.unhook();
	generate_primitives::m_generate_primitives.unhook();

	Sleep(200);

	process_input::m_process_input.unhook();
	create_move::m_create_move.unhook();
	mouse_input_enabled::m_mouse_input_enabled.unhook();
	enable_cursor::m_enable_cursor.unhook();
	frame_stage_notify::m_frame_stage_notify.unhook();
	fire_event_client_side::m_fire_event_client_side.unhook();
	level_init::m_level_init.unhook();

	Sleep(100);

	g_directx->uninitialize();

	MH_Uninitialize();
}

bool __fastcall hooks::mouse_input_enabled::hk_mouse_input_enabled(void* ptr) {
	auto original = m_mouse_input_enabled.get_original<decltype(&hk_mouse_input_enabled)>();
	if (!original)
		return true;
	const bool menu_captures_input = g_menu && g_menu->m_opened && g_init_progress.done;
	return menu_captures_input ? false : original(ptr);
}

bool __fastcall hooks::process_input::hk_process_input(i_csgo_input* input, int slot, c_user_cmd* cmd) {
	auto original = m_process_input.get_original<decltype(&hk_process_input)>();
	if (!original)
		return false;

	if (g_ctx && g_interfaces && g_interfaces->m_entity_system) {
		__try {
			g_ctx->m_local_pawn = g_interfaces->m_entity_system->get_local_pawn();
			g_ctx->m_local_controller = g_interfaces->m_entity_system->get_local_controller();
			g_ctx->m_user_cmd = cmd;
			if (!cmd) LOG_ERROR(xorstr_("[process_input] cmd is null!"));
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			g_ctx->m_local_pawn = nullptr;
			g_ctx->m_local_controller = nullptr;
			g_ctx->m_user_cmd = nullptr;
		}
	}

	return original(input, slot, cmd);
}

void* __fastcall hooks::enable_cursor::hk_enable_cursor(void* rcx, bool active) {
	auto original = m_enable_cursor.get_original<decltype(&hk_enable_cursor)>();
	if (!original)
		return nullptr;

	m_enable_cursor_input = active;
	if (g_menu && g_menu->m_opened && g_init_progress.done)
		active = false;

	return original(rcx, active);
}

void __fastcall hooks::create_move::hk_create_move(i_csgo_input* rcx, int slot, bool active) {
	auto original = m_create_move.get_original<decltype(&hk_create_move)>();
	if (!original)
		return;

	if (!g_ctx || !g_interfaces || !g_interfaces->m_entity_system || !rcx)
	{
		original(rcx, slot, active);
		return;
	}

	__try {
		g_ctx->m_local_pawn = g_interfaces->m_entity_system->get_local_pawn();
		g_ctx->m_local_controller = g_interfaces->m_entity_system->get_local_controller();
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		g_ctx->m_local_pawn = nullptr;
		g_ctx->m_local_controller = nullptr;
		original(rcx, slot, active);
		return;
	}

	original(rcx, slot, active);

	if (!g_ctx->m_local_controller)
		return;

	if (!g_ctx->m_user_cmd)
	{
		LOG_ERROR(xorstr_("[create_move] m_user_cmd is null (process_input probably didn't fire)"));
		return;
	}

	if (g_aim && feature_enabled("aim")) {
		__try {
			g_aim->run(rcx, g_ctx->m_user_cmd);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	const bool jump_bug_active = feature_enabled("movement") && g_jump_bug && g_jump_bug->run(g_ctx->m_user_cmd);
	if (!jump_bug_active && feature_enabled("movement") && g_bhop) {
		__try {
			g_bhop->run(g_ctx->m_user_cmd);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}
	if (feature_enabled("movement") && g_autostrafe) {
		__try {
			g_autostrafe->run(g_ctx->m_user_cmd);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}
	if (feature_enabled("movement") && g_mini_jump) {
		__try {
			g_mini_jump->run(g_ctx->m_user_cmd);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}
	if (feature_enabled("movement") && g_edge_jump) {
		__try {
			g_edge_jump->run(g_ctx->m_user_cmd);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	if (g_cfg && g_cfg->indicators.m_jump_stats) {
		__try {
			g_jump_stats->run();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	if (g_menu)
		g_menu->on_create_move();

}

void hooks::frame_stage_notify::hk_frame_stage_notify(void* source_to_client, int stage) {
	auto original = m_frame_stage_notify.get_original<decltype(&hk_frame_stage_notify)>();

	if (g_interfaces && g_interfaces->m_entity_system) {

		__try {
			auto* temp_pawn = g_interfaces->m_entity_system->get_local_pawn();
			auto* temp_controller = g_interfaces->m_entity_system->get_local_controller();

			if (g_ctx && valid_ptr(temp_pawn))
				g_ctx->m_local_pawn = temp_pawn;
			else if (g_ctx)
				g_ctx->m_local_pawn = nullptr;

			if (g_ctx && valid_ptr(temp_controller))
				g_ctx->m_local_controller = temp_controller;
			else if (g_ctx)
				g_ctx->m_local_controller = nullptr;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {

			if (g_ctx) {
				g_ctx->m_local_pawn = nullptr;
				g_ctx->m_local_controller = nullptr;
			}
		}
	}

	if (stage == 7) {
		// Warm the custom world-effect particle resources here -- a resource-safe
		// context outside the render frame. Retries every frame until the particle
		// manager is ready, so the effect appears on the first map load without a
		// rejoin. No-op once warmed.
		if (g_world_effects) {
			__try {
				g_world_effects->warm_tick();
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {}
		}

		// Warm the risky hit-effect particles (sparks/explosion) in the same
		// resource-safe context, retried each frame until the particle manager is
		// ready. Idempotent + no-op once warmed. Gated on the feature being enabled
		// so nothing is spawned when hit effects are off; enabling mid-map warms
		// within a frame.
		__try {
			g_fog_handler->fog_controller();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
		}

		if (g_ctx && g_ctx->m_local_pawn && g_ctx->m_local_controller) {
			__try {
				if (g_skin_changer && feature_enabled("skin_changer"))
					g_skin_changer->run(stage);
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				if (g_skin_changer)
					g_skin_changer->should_update = false;
			}

			__try {
				if (g_glove_changer && feature_enabled("glove_changer"))
					g_glove_changer->run(stage);
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				if (g_glove_changer) {
					g_glove_changer->should_update = false;
					g_glove_changer->round_start_delay_frames = 0;
				}
			}

			__try {
				removals::run();
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
			}
		}
	}

	if (original)
		original(source_to_client, stage);

}

__int64 __fastcall hooks::level_init::hk_level_init(void* rcx, void* rdx) {
	auto original = m_level_init.get_original<decltype(&hk_level_init)>();
	if (!original)
		return 0;

	if (!rcx || !rdx) {
		g_fog_handler->remove_fog();
		if (g_world)
			g_world->reset();

		if (g_skin_changer)
			g_skin_changer->should_update = false;

		if (g_glove_changer) {
			g_glove_changer->should_update = false;
			g_glove_changer->round_start_delay_frames = 0;
		}

		if (g_ctx) {
			g_ctx->m_local_pawn = nullptr;
			g_ctx->m_local_controller = nullptr;
		}
		return original(rcx, rdx);
	}

	if (!g_cfg)
		return original(rcx, rdx);

	custom_paint::reset_cached_vectors();

	if (g_world)
		g_world->reset();

	if (g_cfg) g_hit_sound->warm_async(g_cfg->misc.m_sounds_type);

	if (feature_enabled("skin_changer") && g_skin_changer && (g_cfg->knife_changer.m_enabled || g_cfg->skin_changer.m_enabled || g_cfg->agent_changer.m_enabled || g_cfg->model_changer.m_enabled)) {
		g_skin_changer->request_update();
	}

	if (feature_enabled("glove_changer") && g_glove_changer && g_cfg->glove_changer.m_enabled) {
		g_glove_changer->should_update = true;
	}

	const auto level_init_ret = original(rcx, rdx);

	// Re-arm hit-effect warming for the new map. The actual block-load is retried
	// from FrameStageNotify (stage 7) until the particle manager is ready -- warming
	// here at LevelInit alone was too early on the first map load (the manager is not
	// yet live), so sparks/explosion silently never warmed and were skipped in tick()
	// while blood (always resident) kept working. Blood needs no warming.
	// World effects: extract the embedded particle resources to disk (once) and
	// re-arm warming for the new map. Called unconditionally so the files are always
	// present; the actual block-load is retried from FrameStageNotify (stage 7)
	// until the particle manager is ready -- warming here alone was too early on the
	// first map load (it only worked after a rejoin).
	if (g_world_effects) {
		__try {
			g_world_effects->on_level_change();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	return level_init_ret;
}

static const char* hitgroup_name(int hitgroup) {
	switch (hitgroup) {
		case 1: return "head";
		case 2: return "chest";
		case 3: return "stomach";
		case 4: return "left arm";
		case 5: return "right arm";
		case 6: return "left leg";
		case 7: return "right leg";
		default: return "body";
	}
}

static void send_chat_message(const char* message) {
	if (!message || !message[0])
		return;

	using SendChatMessageFn = std::int64_t(__fastcall*)(void*, const char*, unsigned int, std::uint8_t*);
	static auto fn_send_chat = reinterpret_cast<SendChatMessageFn>(SIG("SendMessageClient"));
	if (!fn_send_chat)
		return;

	const auto hud_ptr = c_hud::find_hud_element("CCSGO_HudVoiceStatus");
	if (!hud_ptr || hud_ptr == 32)
		return;

	std::uint8_t flags[2] = { 1, 0 };
	fn_send_chat(reinterpret_cast<void*>(hud_ptr - 32), message, 0xFFFFFFFF, flags);
}

void try_send_chat_safe(const char* message) {
	__try {
		send_chat_message(message);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {}
}

static const char* get_player_name(void* controller) {
	if (!controller)
		return "unknown";
	return reinterpret_cast<const char*>(static_cast<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(controller) + cs2::verified::ESP::CCSPlayerController__m_iszPlayerName));
}

static const char* get_team_color_hex(void* controller) {
	if (!controller)
		return "#c4c4c4";

	uint8_t team = 0;
	__try {
		team = *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(controller) + cs2::verified::ESP::C_BaseEntity__m_iTeamNum);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return "#c4c4c4";
	}

	switch (team) {
		case 2: return "#ffd494";
		case 3: return "#85acfa";
		default: return "#c4c4c4";
	}
}

static void* try_get_event_controller(void* p_game_event, i_game_event::CUtlStringToken* token) {
	__try {
		return i_game_event::get_player_controller(p_game_event, token);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return nullptr;
	}
}

static std::int64_t(__fastcall* fn_get_int64)(void*, const char*) = reinterpret_cast<std::int64_t(__fastcall*)(void*, const char*)>(SIG("GameEvent_GetInt64"));

static bool try_read_hurt_values(void* p_game_event, std::int64_t& dmg_health, std::int64_t& hitgroup, std::int64_t& health) {
	if (!fn_get_int64)
		return false;
	__try {
		dmg_health = fn_get_int64(p_game_event, "dmg_health");
		hitgroup = fn_get_int64(p_game_event, "hitgroup");
		health = fn_get_int64(p_game_event, "health");
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}
}

// Resolve a player controller (as delivered by a game event) to its pawn's
// world origin, lifted by z_offset. Used to position hit/kill particles.
static bool get_controller_world_pos(void* controller_ptr, float z_offset, vec3_t& out) {
	if (!controller_ptr || !g_interfaces || !g_interfaces->m_entity_system)
		return false;

	__try {
		auto* controller = reinterpret_cast<c_cs_player_controller*>(controller_ptr);
		const auto handle = controller->m_pawn();
		if (!handle.is_valid())
			return false;

		auto* pawn = g_interfaces->m_entity_system->get_base_entity<c_cs_player_pawn>(handle.get_entry_index());
		if (!pawn)
			return false;

		auto* node = pawn->m_scene_node();
		if (!node)
			return false;

		vec3_t origin = node->m_abs_origin();
		origin.z += z_offset;
		out = origin;
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}
}

static void handle_player_hurt(void* p_game_event) {
	if (!g_cfg || !g_ctx || !i_game_event::get_player_controller)
		return;

	i_game_event::CUtlStringToken attacker_token("attacker");
	attacker_token.pad = 0xFFFFFFFF;
	i_game_event::CUtlStringToken userid_token("userid");
	userid_token.pad = 0xFFFFFFFF;

	void* attacker_controller = try_get_event_controller(p_game_event, &attacker_token);
	void* victim_controller = try_get_event_controller(p_game_event, &userid_token);

	if (!attacker_controller || !victim_controller)
		return;

	const bool we_attacked = is_local_controller(attacker_controller);

	if (!we_attacked && !is_local_controller(victim_controller))
		return;

	std::int64_t dmg_health = 0;
	std::int64_t hitgroup_val = 0;
	std::int64_t health = 0;

	if (!try_read_hurt_values(p_game_event, dmg_health, hitgroup_val, health))
		return;

	if (dmg_health <= 0 || hitgroup_val < 0)
		return;

	if (we_attacked && g_cfg) {
		g_hit_sound->play(g_cfg->misc.m_sounds_type);
		Menu::AddHitMarker((int)hitgroup_val);
	}

	if (!g_cfg->misc.m_hit_logs)
		return;

	char message[256];
	char menu_col_hex[8];
	ImVec4 mc = g_cfg->menu.m_menu_color;
	sprintf_s(menu_col_hex, "#%02x%02x%02x", (int)(mc.x * 255.0f), (int)(mc.y * 255.0f), (int)(mc.z * 255.0f));

	if (g_cfg->misc.m_hit_logs_type == 0) {
		if (we_attacked) {
			const char* victim_name = get_player_name(victim_controller);
			const char* team_col = get_team_color_hex(victim_controller);
			sprintf_s(message, "<font color=\"%s\"> celerity </font><font color=\"#c4c4c4\">| hit player <font color=\"%s\">%s</font> in the %s for %lld damage (%lld hp remaining)</font>",
				menu_col_hex, team_col, victim_name, hitgroup_name((int)hitgroup_val), dmg_health, health > 0 ? health : 0);
		} else {
			const char* attacker_name = get_player_name(attacker_controller);
			const char* team_col = get_team_color_hex(attacker_controller);
			sprintf_s(message, "<font color=\"%s\"> celerity </font><font color=\"#c4c4c4\">| harmed by player <font color=\"%s\">%s</font> in the %s for %lld hp</font>",
				menu_col_hex, team_col, attacker_name, hitgroup_name((int)hitgroup_val), dmg_health);
		}
	} else {
		if (we_attacked) {
			const char* victim_name = get_player_name(victim_controller);
			const char* team_col = get_team_color_hex(victim_controller);
			sprintf_s(message, "[<font color=\"#FF0000\">Meme</font><font color=\"#FFFFFF\">Sense</font>] Hit <font color=\"%s\">%s</font><font color=\"#c4c4c4\"> in the %s for %lld damage (%lld health remaining)",
				team_col, victim_name, hitgroup_name((int)hitgroup_val), dmg_health, health > 0 ? health : 0);
		} else {
			const char* attacker_name = get_player_name(attacker_controller);
			const char* team_col = get_team_color_hex(attacker_controller);
			sprintf_s(message, "[<font color=\"#FF0000\">Meme</font><font color=\"#FFFFFF\">Sense</font>] Hit by <font color=\"%s\">%s</font><font color=\"#c4c4c4\"> in the %s for %lld damage",
				team_col, attacker_name, hitgroup_name((int)hitgroup_val), dmg_health);
		}
	}

	try_send_chat_safe(message);
}

bool __fastcall hooks::fire_event_client_side::hk_fire_event_client_side(void* p_game_event_manager, void* p_game_event) {
	auto original = m_fire_event_client_side.get_original<decltype(&hk_fire_event_client_side)>();
	if (!original)
		return false;

	if (!p_game_event || !i_game_event::get_name || !g_cfg)
		return original(p_game_event_manager, p_game_event);

	const char* event_name = nullptr;
	__try {
		event_name = i_game_event::get_name(p_game_event);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return original(p_game_event_manager, p_game_event);
	}
	if (!event_name)
		return original(p_game_event_manager, p_game_event);

	uint32_t event_hash = 0;
	if (!try_hash_event_name(event_name, event_hash))
		return original(p_game_event_manager, p_game_event);

	if (event_hash == event_hashes::round_start)
	{
		custom_paint::reset_cached_vectors();

		g_hit_sound->warm_async(g_cfg->misc.m_sounds_type);

		if (g_glove_changer)
			g_glove_changer->round_start_delay_frames = 15;

		if (g_skin_changer)
			g_skin_changer->request_update();
		if (g_glove_changer)
			g_glove_changer->should_update = true;

		return original(p_game_event_manager, p_game_event);
	}

	if (event_hash == event_hashes::round_end ||
		event_hash == event_hashes::round_officially_ended ||
		event_hash == event_hashes::cs_win_panel_round)
	{
		custom_paint::reset_cached_vectors();

		if (g_ctx) {
			g_ctx->m_local_pawn = nullptr;
			g_ctx->m_local_controller = nullptr;
		}
		return original(p_game_event_manager, p_game_event);
	}

	if (event_hash == event_hashes::player_team || event_hash == event_hashes::player_spawn)
	{
		if (!is_event_controller_local(p_game_event, "userid"))
			return original(p_game_event_manager, p_game_event);

		custom_paint::reset_cached_vectors();

		if (g_glove_changer)
			g_glove_changer->round_start_delay_frames = 15;

		if (g_ctx) {
			g_ctx->m_local_pawn = nullptr;
			g_ctx->m_local_controller = nullptr;
		}

		if (g_glove_changer)
			g_glove_changer->should_update = false;

		return original(p_game_event_manager, p_game_event);
	}

	if (event_hash == event_hashes::item_purchase)
	{

		if (g_ctx && g_ctx->m_local_controller && i_game_event::get_player_controller)
		{
			i_game_event::CUtlStringToken userid_token("userid");
			userid_token.pad = 0xFFFFFFFF;

			void* purchaser_controller = nullptr;
			__try {
				purchaser_controller = i_game_event::get_player_controller(p_game_event, &userid_token);
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				return original(p_game_event_manager, p_game_event);
			}

			if (purchaser_controller == g_ctx->m_local_controller)
			{
				custom_paint::reset_cached_vectors();

				if (feature_enabled("skin_changer") && g_skin_changer && (g_cfg->knife_changer.m_enabled || g_cfg->skin_changer.m_enabled || g_cfg->agent_changer.m_enabled || g_cfg->model_changer.m_enabled))
					g_skin_changer->request_update();
			}
		}
		return original(p_game_event_manager, p_game_event);
	}

	if (event_hash == event_hashes::player_disconnect)
	{
		return original(p_game_event_manager, p_game_event);
	}

	if (event_hash == event_hashes::player_hurt)
	{
		handle_player_hurt(p_game_event);
		return original(p_game_event_manager, p_game_event);
	}

	if (event_hash != event_hashes::player_death)
		return original(p_game_event_manager, p_game_event);

	if (g_cfg && g_cfg->knife_changer.m_enabled) {
		if (!g_ctx || !g_ctx->m_local_controller || !i_game_event::get_player_controller)
			return original(p_game_event_manager, p_game_event);

		i_game_event::CUtlStringToken attacker_token("attacker");
		attacker_token.pad = 0xFFFFFFFF;

		void* attacker_controller = nullptr;
		__try {
			attacker_controller = i_game_event::get_player_controller(p_game_event, &attacker_token);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return original(p_game_event_manager, p_game_event);
		}

		if (attacker_controller != g_ctx->m_local_controller)
			return original(p_game_event_manager, p_game_event);

		i_game_event::CUtlStringToken weapon_token("weapon");
		weapon_token.pad = 0xFFFFFFFF;

		const char* weapon_name = nullptr;
		__try {
			weapon_name = i_game_event::get_string(p_game_event, &weapon_token, nullptr);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return original(p_game_event_manager, p_game_event);
		}

		if (!valid_ptr(weapon_name))
			return original(p_game_event_manager, p_game_event);

		const bool is_knife = knife_db::matches(weapon_name);

		if (is_knife && g_cfg->knife_changer.m_knife != 0) {
			const char* new_weapon_name = get_knife_weapon_name(g_cfg->knife_changer.m_knife);
			if (new_weapon_name) {
				i_game_event::CUtlStringToken set_token("weapon");
				set_token.pad = 0xFFFFFFFF;
				i_game_event::set_string(p_game_event, &set_token, new_weapon_name, 0);
			}
		}
	}

	return original(p_game_event_manager, p_game_event);
}

HRESULT hooks::present::hk_present(IDXGISwapChain* swap_chain, unsigned int sync_interval, unsigned int flags) {
	auto original = m_present.get_original<decltype(&hk_present)>();
	if (!original)
		return S_OK;

	if (g_directx && swap_chain) {
		__try {
			g_directx->start_frame(swap_chain);

			if (feature_enabled("glow")) {
				glow::update();
			}

			auto* device_context = g_directx->get_device_context();
			auto* render_target = g_directx->get_render_target();
			if (device_context && render_target) {
				device_context->OMSetRenderTargets(1, &render_target, nullptr);

				if (g_cfg && g_cfg->visuals.m_motion_blur.m_enabled && g_motion_blur) {
					__try {
						if (!g_motion_blur->is_initialized()) {
							auto* device = g_directx->get_device();
							if (device) {
								g_motion_blur->initialize(device, device_context, swap_chain);
							}
						}
						if (g_motion_blur->is_initialized()) {
							g_motion_blur->render(swap_chain, g_cfg->visuals.m_motion_blur.m_strength);
						}
					}
					__except (EXCEPTION_EXECUTE_HANDLER) {}
				}

				if (g_blur && !g_blur->is_initialized()) {
					__try {
						auto* device = g_directx->get_device();
						if (device)
							g_blur->initialize(device, device_context);
					}
					__except (EXCEPTION_EXECUTE_HANDLER) {}
				}

				if (g_blur && g_blur->is_initialized() && g_menu && g_menu->m_opened) {
					__try {
						g_blur->apply_blur(g_sidebar_blur_x, g_sidebar_blur_y,
							g_sidebar_blur_w, g_sidebar_blur_h, 6.0f, 0.0f);
					}
					__except (EXCEPTION_EXECUTE_HANDLER) {}
				}

				// Watermark background blur (applied before new_frame so the blurred
				// region is composited underneath the ImGui overlay layer).
				if (g_blur && g_blur->is_initialized() && s.ind_watermark &&
					g_watermark_blur_w > 0.0f && g_watermark_blur_h > 0.0f) {
					__try {
						g_blur->apply_blur(g_watermark_blur_x, g_watermark_blur_y,
							g_watermark_blur_w, g_watermark_blur_h, 2.0f, 6.0f);
					}
					__except (EXCEPTION_EXECUTE_HANDLER) {}
				}

				g_directx->new_frame();

				if (!g_init_progress.done) {
					draw_loading_overlay();
				} else {

					visuals::visualize_aimbot_fov();

					if (feature_enabled("visuals")) {
						visuals::draw();
						teammate_esp::draw();
						visuals::draw_world();
					}

					if (g_world_effects) {
						__try {
							g_world_effects->update();
						}
						__except (EXCEPTION_EXECUTE_HANDLER) {}
					}

					// Build the chams materials once, here in the present hook -- a
					// frame-safe context where the material system is ready. No-op
					// after the first success; safe to call every frame.
					if (g_chams) {
						__try {
							g_chams->ensure_init();
							g_chams->refresh_targets();
						}
						__except (EXCEPTION_EXECUTE_HANDLER) {}
					}

				if (g_menu) {
						static bool last_menu_open = false;
						const bool menu_captures_input = g_menu->m_opened && g_init_progress.done;
						if (last_menu_open != menu_captures_input) {
							apply_game_cursor_state(menu_captures_input);
							last_menu_open = menu_captures_input;
						}
						ImGuiIO& menu_io = ImGui::GetIO();
						menu_io.MouseDrawCursor = false;
						menu_io.WantCaptureMouse = menu_captures_input;
						menu_io.WantCaptureKeyboard = menu_captures_input && ImGui::GetActiveID() != 0;
						if (g_init_progress.done) {
							Menu::RenderWeatherEffects();
							Menu::RenderSpectators();
							Menu::RenderBinds();
							Menu::RenderWatermark();
							Menu::RenderSpotify();
							Menu::RenderVelocityDisplay();
							Menu::RenderKeystrokes();
							Menu::RenderVelocityGraph();
							Menu::RenderMovementTrail();
							Menu::RenderHitMarkers();
							g_menu->draw();
						}
					}
					draw_loading_overlay();
				}
				g_directx->end_frame();
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	return original(swap_chain, sync_interval, flags);
}

HRESULT hooks::resize_buffers::hk_resize_buffers(IDXGISwapChain* swap_chain, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags) {
	auto original = m_resize_buffers.get_original<decltype(&hk_resize_buffers)>();
	if (!original)
		return DXGI_ERROR_INVALID_CALL;

	if (g_directx) {
		__try {
			g_directx->destroy_render_target();
			g_directx->cleanup_imgui();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	HRESULT result = original(swap_chain, buffer_count, width, height, new_format, swap_chain_flags);

	if (SUCCEEDED(result) && g_directx) {
		__try {
			g_directx->create_render_target();
			g_directx->reinitialize_imgui();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	if (g_motion_blur) {
		__try {
			g_motion_blur->cleanup();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	return result;
}

HRESULT __stdcall hooks::create_swap_chain::hk_create_swap_chain(IDXGIFactory* factory, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swap_chain) {
	auto original = m_create_swap_chain.get_original<decltype(&hk_create_swap_chain)>();
	if (!original)
		return DXGI_ERROR_INVALID_CALL;

	if (g_directx) {
		__try {
			g_directx->destroy_render_target();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}
	return original(factory, device, desc, swap_chain);
}

void* __fastcall hooks::draw_skybox_array::hk_draw_skybox_array(void* a1, void* a2, void* draw_primitive, int count, void* a5, void* a6, void* a7) {
	static auto original = m_draw_skybox_array.get_original<decltype(&hk_draw_skybox_array)>();
	if (!original)
		return nullptr;

	static bool saved_original = false;
	static c_draw_primitive_sky* cached_object = nullptr;
	static float original_r = 0.0f, original_g = 0.0f, original_b = 0.0f;

	if (g_cfg) {
		if (auto object = *reinterpret_cast<c_draw_primitive_sky**>(reinterpret_cast<char*>(draw_primitive) + 0x18)) {
			const auto& wm = g_cfg->visuals.m_world_modulation;

			if (wm.m_enable_sky) {
				if (!saved_original || cached_object != object) {
					original_r = object->m_sky_color_r;
					original_g = object->m_sky_color_g;
					original_b = object->m_sky_color_b;
					cached_object = object;
					saved_original = true;
				}

				const auto& col = wm.m_sky_color;
				object->m_sky_color_r = col.x;
				object->m_sky_color_g = col.y;
				object->m_sky_color_b = col.z;
			}
			else if (saved_original && cached_object == object) {
				object->m_sky_color_r = original_r;
				object->m_sky_color_g = original_g;
				object->m_sky_color_b = original_b;
				saved_original = false;
				cached_object = nullptr;
			}
		}
	}

	return original(a1, a2, draw_primitive, count, a5, a6, a7);
}

void __fastcall hooks::draw_scope::hk_draw_scope(__int64 a1, __int64 a2) {
	static auto original = m_draw_scope.get_original<decltype(&hk_draw_scope)>();
	if (!original)
		return;

	if (g_cfg && ((g_cfg->removals.m_effects & (1 << 7)) || g_cfg->misc.m_scope_overlay))
		return;

	original(a1, a2);
}

void* __fastcall hooks::smoke_volume_draw_array::hk_smoke_volume_draw_array(void* a1, void* a2, int a3, int a4, void* a5, void* a6, void* a7, void* a8, void* a9, void* a10) {
	static auto original = m_smoke_volume_draw_array.get_original<decltype(&hk_smoke_volume_draw_array)>();
	if (!original)
		return nullptr;

	if (g_cfg && (g_cfg->removals.m_effects & (1 << 8)))
		return nullptr;

	return original(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

void* __fastcall hooks::first_person_legs::hk_first_person_legs(void* a1, void* a2, void* a3, void* a4, void* a5) {
	static auto original = m_first_person_legs.get_original<decltype(&hk_first_person_legs)>();
	if (!original)
		return nullptr;

	if (g_cfg && (g_cfg->removals.m_effects & (1 << 9)))
		return nullptr;

	return original(a1, a2, a3, a4, a5);
}

void __fastcall hooks::update_post_processing::hk_update_post_processing(void* a1, void* a2) {
	static auto original = m_update_post_processing.get_original<decltype(&hk_update_post_processing)>();
	if (!original)
		return;

	original(a1, a2);

	g_world->exposure(reinterpret_cast<c_post_processing_volume*>(a2));
}

void __fastcall hooks::draw_aggregate_scene_object::hk_draw_aggregate_scene_object(void* a1, void* a2, void* a3, int a4, int a5, void* a6, void* a7) {
	static auto original = m_draw_aggregate_scene_object.get_original<decltype(&hk_draw_aggregate_scene_object)>();
	if (!original)
		return;

	auto* scene_data = static_cast<c_base_scene_data*>(a3);
	if (scene_data && scene_data->m_material) {
		g_world->aggregate_scene(scene_data, a4, scene_data->m_material);
	}

	original(a1, a2, a3, a4, a5, a6, a7);
}

void* __fastcall hooks::draw_light_scene::hk_draw_light_scene(void* a1, void* a2, __int64 a3) {
	static auto original = m_draw_light_scene.get_original<decltype(&hk_draw_light_scene)>();
	if (!original)
		return nullptr;

	g_world->lighting(static_cast<c_scene_light_object*>(a2));

	return original(a1, a2, a3);
}

std::int64_t __fastcall hooks::draw_aggregate_sceneobject_array::hk_draw_aggregate_sceneobject_array(void* a1, void* a2, void* a3) {
	static auto original = m_draw_aggregate_sceneobject_array.get_original<decltype(&hk_draw_aggregate_sceneobject_array)>();
	if (!original)
		return 0;

	std::int64_t result = original(a1, a2, a3);

	auto arr = static_cast<c_aggregate_object_arr*>(a3);
	if (!arr->data || arr->data->nIndex == -1 || arr->data->nCount == 0)
		return result;

	if (!g_interfaces->m_scene_system->data || !g_interfaces->m_scene_system->data->lightData)
		return result;

	const auto& wm = g_cfg->visuals.m_world_modulation;
	if (!wm.m_enable_wall)
		return result;

	auto to_u8 = [](float v) { return static_cast<std::uint8_t>(std::clamp(v, 0.0f, 1.0f) * 255.0f + 0.5f); };

	c_material_color_no_alpha col;
	col.r = to_u8(wm.m_wall.x);
	col.g = to_u8(wm.m_wall.y);
	col.b = to_u8(wm.m_wall.z);

	for (int i = 0; i < arr->data->nCount; i++) {
		int index = (arr->data->nIndex + i) << 5;
		*reinterpret_cast<c_material_color_no_alpha*>(
			reinterpret_cast<std::uintptr_t>(g_interfaces->m_scene_system->data->lightData) + index
		) = col;
	}

	return result;
}

void* __fastcall hooks::generate_primitives::hk_generate_primitives(c_animatable_scene_object_desc* desc, c_scene_animatable_object* object, void* a3, c_mesh_primitive_output_buffer* render_buf) {
	static auto original = m_generate_primitives.get_original<decltype(&hk_generate_primitives)>();
	if (!original)
		return nullptr;

	// Chams overrides the material of the primitives generated for a target object.
	// on_generate_primitives calls `original` itself (to populate render_buf) and then
	// swaps the material/colour on the newly-added primitives; if it handled the object
	// it returns true and we must NOT call original again. Everything else generates
	// normally. on_generate_primitives is fully SEH-guarded internally, so no __try is
	// needed here (an outer __try would trip C2712 once the callee is inlined).
	bool handled = false;
	if (g_chams && object && render_buf)
		handled = g_chams->on_generate_primitives(desc, object, a3, render_buf, original);

	if (handled)
		return nullptr;

	return original(desc, object, a3, render_buf);
}


