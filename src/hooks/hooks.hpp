#pragma once

class c_hook {
	void* m_function = nullptr;
	void* m_detour = nullptr;
	void* m_trampoline = nullptr;
	bool m_enabled = false;
public:
	bool hook(void* target, void* dtr) {
		if (!target || !dtr) {
			LOG_ERROR(xorstr_("[c_hook] invalid hook target=%p detour=%p"), target, dtr);
			return false;
		}

		m_function = target;
		m_detour = dtr;

		MH_STATUS create_status = MH_CreateHook(m_function, m_detour, &m_trampoline);
		if (create_status != MH_OK) {
			LOG_ERROR(xorstr_("[c_hook] MH_CreateHook failed: %d (%s) at %s"), create_status, MH_StatusToString(create_status), dbg::addr(target).s);
			return false;
		}

		MH_STATUS enable_status = MH_EnableHook(m_function);
		if (enable_status != MH_OK) {
			LOG_ERROR(xorstr_("[c_hook] MH_EnableHook failed: %d (%s) at %s"), enable_status, MH_StatusToString(enable_status), dbg::addr(target).s);
			return false;
		}

		m_enabled = true;
		return true;
	}

	bool hook(uintptr_t target, void* dtr) {
		return hook((void*)target, dtr);
	}

	template <typename tOriginal>
	tOriginal get_original() {
		return reinterpret_cast<tOriginal>(m_trampoline);
	}

	void unhook() {
		if (!m_enabled || !m_function)
			return;

		MH_DisableHook(m_function);
		m_enabled = false;
	}
};

enum e_frame_stage {
	FRAME_UNDEFINED = -1,
	FRAME_START,
	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,
	FRAME_RENDER_START,
	FRAME_RENDER_END
};

class i_csgo_input;
class c_user_cmd;
class c_mesh_data;
class c_animatable_scene_object_desc;
class c_scene_animatable_object;
class c_mesh_primitive_output_buffer;

namespace hooks {
	namespace create_move {
		inline c_hook m_create_move;
		void __fastcall hk_create_move(i_csgo_input* rcx, int slot, bool active);
	}

	namespace process_input {
		inline c_hook m_process_input;
		bool __fastcall hk_process_input(i_csgo_input* input, int slot, c_user_cmd* cmd);
	}

	namespace mouse_input_enabled {
		inline c_hook m_mouse_input_enabled;
		bool __fastcall hk_mouse_input_enabled(void* rcx);
	}

	namespace enable_cursor {
		inline c_hook m_enable_cursor;
		inline bool m_enable_cursor_input = true;
		void* __fastcall hk_enable_cursor(void* rcx, bool active);
	}

	namespace frame_stage_notify {
		inline c_hook m_frame_stage_notify;
		void hk_frame_stage_notify(void* source_to_client, int stage);
	}

	namespace fire_event_client_side {
		inline c_hook m_fire_event_client_side;
		bool __fastcall hk_fire_event_client_side(void* p_game_event_manager, void* p_game_event);
	}

	namespace level_init {
		inline c_hook m_level_init;
		__int64 __fastcall hk_level_init(void* rcx, void* rdx);
	}

	namespace present {
		inline c_hook m_present;
		HRESULT hk_present(IDXGISwapChain* swap_chain, unsigned int sync_interval, unsigned int flags);
	}

	namespace resize_buffers {
		inline c_hook m_resize_buffers;
		HRESULT hk_resize_buffers(IDXGISwapChain* swap_chain, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags);
	}

	namespace create_swap_chain {
		inline c_hook m_create_swap_chain;
		HRESULT __stdcall hk_create_swap_chain(IDXGIFactory* factory, IUnknown* device, DXGI_SWAP_CHAIN_DESC* desc, IDXGISwapChain** swap_chain);
	}

	namespace get_viewmodel_offsets {
		inline c_hook m_get_viewmodel_offsets;
		void __fastcall hk_get_viewmodel_offsets(uintptr_t viewmodel, float* out_offsets, float* out_fov);
	}

	namespace get_world_fov {
		inline c_hook m_get_world_fov;
		float __fastcall hk_get_world_fov(uintptr_t rcx);
	}

	namespace override_view {
		inline c_hook m_override_view;
		void __fastcall hk_override_view(void* client_mode, void* view_setup);
	}

	namespace build_legacy_weapon_skin_material {
		inline c_hook m_build_legacy_weapon_skin_material;
		void __fastcall hk_build_legacy_weapon_skin_material(void* weapon, bool force);
	}

	namespace build_modern_weapon_skin_material {
		inline c_hook m_build_modern_weapon_skin_material;
		void __fastcall hk_build_modern_weapon_skin_material(void* weapon, void* a2, void* a3, int a4, char a5, char a6, void* a7);
	}

	namespace glow_should_glow {
		inline c_hook m_should_glow;
		bool __fastcall hk_should_glow(void* glow_property);
	}

	namespace glow_apply_glow {
		inline c_hook m_apply_glow;
		void __fastcall hk_apply_glow(void* glow_property, void* glow_object);
	}

	namespace composite_material_input {
		inline c_hook m_add_to_tail;
		void __fastcall hk_add_to_tail(void* vector, const void* input);
	}

	namespace draw_skybox_array {
		inline c_hook m_draw_skybox_array;
		void* __fastcall hk_draw_skybox_array(void* a1, void* a2, void* draw_primitive, int count, void* a5, void* a6, void* a7);
	}

	namespace update_post_processing {
		inline c_hook m_update_post_processing;
		void __fastcall hk_update_post_processing(void* a1, void* a2);
	}

	namespace draw_aggregate_scene_object {
		inline c_hook m_draw_aggregate_scene_object;
		void __fastcall hk_draw_aggregate_scene_object(void* a1, void* a2, void* a3, int a4, int a5, void* a6, void* a7);
	}

	namespace draw_light_scene {
		inline c_hook m_draw_light_scene;
		void* __fastcall hk_draw_light_scene(void* a1, void* a2, __int64 a3);
	}

	namespace draw_aggregate_sceneobject_array {
		inline c_hook m_draw_aggregate_sceneobject_array;
		std::int64_t __fastcall hk_draw_aggregate_sceneobject_array(void* a1, void* a2, void* a3);
	}

	namespace draw_scope {
		inline c_hook m_draw_scope;
		void __fastcall hk_draw_scope(__int64 a1, __int64 a2);
	}

	namespace smoke_volume_draw_array {
		inline c_hook m_smoke_volume_draw_array;
		void* __fastcall hk_smoke_volume_draw_array(void* a1, void* a2, int a3, int a4, void* a5, void* a6, void* a7, void* a8, void* a9, void* a10);
	}

	namespace first_person_legs {
		inline c_hook m_first_person_legs;
		void* __fastcall hk_first_person_legs(void* a1, void* a2, void* a3, void* a4, void* a5);
	}

		namespace generate_primitives {
		inline c_hook m_generate_primitives;
		void* __fastcall hk_generate_primitives(c_animatable_scene_object_desc* desc, c_scene_animatable_object* object, void* a3, c_mesh_primitive_output_buffer* render_buf);
	}



}

class c_hooks {
public:
	bool initialize();
	void destroy();
};

inline const auto g_hooks = std::make_unique<c_hooks>();
