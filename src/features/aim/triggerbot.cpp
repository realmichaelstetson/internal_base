#include "aim.hpp"

#include "../../core/main.hpp"
#pragma warning(disable : 4324)
#include "../../../ui/menu/elements/bind.h"
#include "../../sdk/buttons.hpp"
#include "../../sdk/offsets.hpp"
#include "../../sdk/verified_features.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"
#include "../../sdk/valve/interfaces/vtables/i_csgo_input.hpp"

#include <Windows.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <random>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
	constexpr float k_pi = 3.14159265358979323846f;
	constexpr std::ptrdiff_t k_view_offset = 0xE70;

	constexpr std::ptrdiff_t k_player_pawn_handle = 0x90C;
	constexpr std::ptrdiff_t k_id_ent_index = cs2::verified::Triggerbot__Seeded_::C_CSPlayerPawn__m_iIDEntIndex;

	// Settings for the weapon group of the player's currently held weapon.
	// Set at the start of run_triggerbot so the helpers below read per-group values.
	const c_config::aim_t::group_t* g_active_aim_group = nullptr;

	const c_config::aim_t::group_t& active_aim_group() {
		return g_active_aim_group ? *g_active_aim_group
			: g_cfg->aim.m_groups[c_config::aim_t::group_shared];
	}

	int weapon_group_from_type(int weapon_type) {
		switch (weapon_type) {
		case WEAPONTYPE_PISTOL:        return c_config::aim_t::group_pistols;
		case WEAPONTYPE_RIFLE:         return c_config::aim_t::group_rifles;
		case WEAPONTYPE_SNIPER_RIFLE:  return c_config::aim_t::group_snipers;
		case WEAPONTYPE_SUBMACHINEGUN: return c_config::aim_t::group_smg;
		case WEAPONTYPE_SHOTGUN:       return c_config::aim_t::group_shotguns;
		case WEAPONTYPE_MACHINEGUN:    return c_config::aim_t::group_heavy;
		default:                       return c_config::aim_t::group_shared;
		}
	}

	const c_config::aim_t::group_t& resolve_aim_group(c_cs_player_pawn* local) {
		int group = c_config::aim_t::group_shared;
		if (local) {
			if (auto* weapon = local->get_active_weapon()) {
				if (auto* data = weapon->get_weapon_data())
					group = weapon_group_from_type(data->m_weapon_type());
			}
		}
		return g_cfg->aim.group_for(group);
	}

	template <typename T>
	T read_ptr(std::uintptr_t address) {
		if (!address)
			return T{};

		__try {
			return *reinterpret_cast<T*>(address);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return T{};
		}
	}

	template <typename T>
	void write_ptr(std::uintptr_t address, const T& value) {
		if (!address)
			return;

		__try {
			*reinterpret_cast<T*>(address) = value;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	std::uintptr_t client_base() {
		return g_modules ? g_modules->m_modules.client_dll.get() : 0;
	}

	float normalize_yaw(float yaw) {
		while (yaw > 180.0f) yaw -= 360.0f;
		while (yaw < -180.0f) yaw += 360.0f;
		return yaw;
	}

	vec3_t normalize_angles(vec3_t ang) {
		ang.x = std::clamp(ang.x, -89.0f, 89.0f);
		ang.y = normalize_yaw(ang.y);
		ang.z = 0.0f;
		return ang;
	}

	vec3_t get_effective_view_angles(i_csgo_input* input, c_user_cmd* cmd) {
		if (cmd) {
			if (auto* base = cmd->get_base_cmd(); base && base->has_viewangles()) {
				return normalize_angles(vec3_t(base->viewangles().x(), base->viewangles().y(), 0.0f));
			}
		}
		vec3_t view = input ? input->get_view_angles() : vec3_t{};
		if (!view.is_valid() && input)
			view = input->view_angles;
		if (!view.is_valid())
			view = read_ptr<vec3_t>(client_base() + cs2_dumper::offsets::client_dll::dwViewAngles);
		if (!view.is_valid())
			return {};
		return normalize_angles(view);
	}

	namespace vis_trace {
		struct alignas(16) trace_data_t {
			char pad0[24];
			struct { char data[0x30]; } arr[0x80];
			char pad_post_arr[8];
			struct {
				int size; char pad4[4];
				void* data; char pad16[8];
			} mod_array;
			struct {
				float start_frac; float end_frac; float damage;
				int max_secondary_traces;
				uint16_t surf_start; uint16_t surf_end;
				uint8_t flags; uint8_t pad[3];
			} mod_inline[8];
			vec3_t tail_start;
			vec3_t tail_end;
			char pad_tail[12];
		};
		struct alignas(16) trace_filter_t { char data[164]; };
		struct c_game_trace_t {
			void* surface;
			void* hit_entity;
			void* hitbox_data;
			char  pad1[0x10];
			uint32_t contents;
			char  pad2[0x4C];
			vec3_t start_pos;
			vec3_t end_pos;
			vec3_t normal;
			vec3_t pos;
			char  pad3[4];
			float fraction;
			char  pad_tail[0x58];
		};

		using fn_init_data   = void(__fastcall*)(trace_data_t*);
		using fn_init_info   = void(__fastcall*)(c_game_trace_t*);
		using fn_init_filter = void*(__fastcall*)(trace_filter_t*, uintptr_t, uint64_t, int, int);
		using fn_create      = bool(__fastcall*)(trace_data_t*, vec3_t, vec3_t, trace_filter_t*, int, bool);
		using fn_get_info    = void(__fastcall*)(trace_data_t*, c_game_trace_t*, float, void*);

		struct fns_t {
			fn_init_data   init_data   = nullptr;
			fn_init_info   init_info   = nullptr;
			fn_init_filter init_filter = nullptr;
			fn_create      create      = nullptr;
			fn_get_info    get_info    = nullptr;
			bool           tried       = false;
		};

		fns_t& get() {
			static fns_t f;
			if (f.tried) return f;
			f.tried = true;
			f.init_data   = reinterpret_cast<fn_init_data>(
				g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 79 ? 33 F6 C7 47"));
			f.init_info   = reinterpret_cast<fn_init_info>(
				g_opcodes->scan("client.dll", "40 55 41 55 41 57 48 83 EC 30"));
			f.init_filter = reinterpret_cast<fn_init_filter>(
				g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24"));
			f.create      = reinterpret_cast<fn_create>(           // TraceCreate
				g_opcodes->scan("client.dll", "48 8B C4 56 57 41 56 41 57 48 83 EC ? 0F B7 F2 4D 8B F9 41 0F B7 F8 4C 8B F1"));
			f.get_info    = reinterpret_cast<fn_get_info>(          // TraceGetInfo
				g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC 80 00 00 00 48 8B E9 0F 29 74 24 70 48 8B CA 49 8B F9 0F 28 F2 48 8B DA"));
			return f;
		}

		bool is_visible(const vec3_t& from, const vec3_t& to, uintptr_t skip_pawn) {
			auto& f = get();
			if (!f.init_data || !f.init_info || !f.init_filter || !f.create || !f.get_info)
				return false;

			__try {
				constexpr uint64_t MASK_VISIBLE = 0x2014003;

				trace_data_t  td{};
				trace_filter_t filter{};
				c_game_trace_t trace{};

				f.init_data(&td);
				f.init_filter(&filter, skip_pawn, MASK_VISIBLE, 4, 7);

				const vec3_t delta = to - from;
				f.create(&td, from, delta, &filter, 4, true);
				f.init_info(&trace);

				if (td.mod_array.size > 0 && td.mod_array.data) {
					auto* entry = static_cast<char*>(td.mod_array.data);

					float start_frac = *reinterpret_cast<float*>(entry + 0);
					uint16_t surf_end = *reinterpret_cast<uint16_t*>(entry + 14);
					const uint16_t surf_idx = surf_end & 0x7FFF;
					if (surf_idx < 0x80)
						f.get_info(&td, &trace, start_frac, &td.arr[surf_idx]);
					else
						trace.fraction = 1.0f;
				} else {
					trace.fraction = 1.0f;
				}

				return trace.fraction >= 0.94f;
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				return true;
			}
		}
	}

	vec3_t calc_angle(const vec3_t& src, const vec3_t& dst) {
		const vec3_t delta = dst - src;
		const float hyp = std::sqrt(delta.x * delta.x + delta.y * delta.y);
		return normalize_angles(vec3_t(
			std::atan2f(-delta.z, hyp) * (180.0f / k_pi),
			std::atan2f(delta.y, delta.x) * (180.0f / k_pi),
			0.0f
		));
	}

	float angle_distance(const vec3_t& a, const vec3_t& b) {
		const vec3_t d = normalize_angles(vec3_t(a.x - b.x, a.y - b.y, 0.0f));
		return std::sqrt(d.x * d.x + d.y * d.y);
	}

	void angle_vectors(const vec3_t& angles, vec3_t* forward, vec3_t* right = nullptr, vec3_t* up = nullptr) {
		constexpr auto deg2rad = k_pi / 180.0f;
		const float sp = std::sinf(angles.x * deg2rad);
		const float cp = std::cosf(angles.x * deg2rad);
		const float sy = std::sinf(angles.y * deg2rad);
		const float cy = std::cosf(angles.y * deg2rad);

		if (forward)
			*forward = vec3_t{ cp * cy, cp * sy, -sp };
		if (right)
			*right = vec3_t{ -sy, cy, 0.0f };
		if (up)
			*up = vec3_t{ sp * cy, sp * sy, cp };
	}

	std::string normalize_bind_name(std::string key) {
		for (auto& c : key)
			c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
		if (key == "MOUSELEFT" || key == "MOUSE1") key = "M1";
		else if (key == "MOUSERIGHT" || key == "MOUSE2") key = "M2";
		else if (key == "MOUSEMIDDLE" || key == "MOUSE3") key = "M3";
		else if (key == "LEFTALT" || key == "RIGHTALT") key = "ALT";
		else if (key == "LEFTCTRL" || key == "RIGHTCTRL") key = "CTRL";
		else if (key == "LEFTSHIFT" || key == "RIGHTSHIFT") key = "SHIFT";
		else if (key == "DELETE") key = "DEL";
		else if (key == "INSERT") key = "INS";
		return key;
	}

	bool is_button_down(std::string key) {
		key = normalize_bind_name(key);
		if (key == "M1") return (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
		if (key == "M2") return (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;
		if (key == "M3") return (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0;
		if (key == "M4") return (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) != 0;
		if (key == "M5") return (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) != 0;
		if (key == "ALT") return (GetAsyncKeyState(VK_MENU) & 0x8000) != 0;
		if (key == "CTRL") return (GetAsyncKeyState(VK_CONTROL) & 0x8000) != 0;
		if (key == "SHIFT") return (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
		if (key == "SPACE") return (GetAsyncKeyState(VK_SPACE) & 0x8000) != 0;
		if (key == "DEL") return (GetAsyncKeyState(VK_DELETE) & 0x8000) != 0;
		if (key == "INS") return (GetAsyncKeyState(VK_INSERT) & 0x8000) != 0;
		if (key == "TAB") return (GetAsyncKeyState(VK_TAB) & 0x8000) != 0;
		if (key.size() == 1) return (GetAsyncKeyState(static_cast<int>(key[0])) & 0x8000) != 0;
		if (key.size() >= 2 && key[0] == 'F') {
			const int n = std::atoi(key.c_str() + 1);
			if (n >= 1 && n <= 24)
				return (GetAsyncKeyState(VK_F1 + n - 1) & 0x8000) != 0;
		}
		return false;
	}

	bool bind_active(const std::string& key, int mode, bool ui_fallback) {
		if (mode == static_cast<int>(UI::BindMode::AlwaysOn))
			return true;
		if (mode == static_cast<int>(UI::BindMode::Toggle))
			return ui_fallback;
		return is_button_down(key) || ui_fallback;
	}

	void set_attack(c_user_cmd* cmd, bool down) {
		const auto base = client_base();
		if (base)
			write_ptr<std::uint32_t>(base + cs2_dumper::buttons::attack, down ? 65537u : 256u);

		if (!cmd)
			return;

		cmd->m_button_state.set_button_state(
			IN_ATTACK,
			down ? c_in_button_state::IN_BUTTON_UP_DOWN : c_in_button_state::IN_BUTTON_DOWN_UP
		);
	}

	c_base_entity* get_base_entity_safe(int index) {
		if (!g_interfaces || !g_interfaces->m_entity_system)
			return nullptr;

		__try {
			return g_interfaces->m_entity_system->get_base_entity(index);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	c_cs_player_pawn* pawn_from_controller(c_cs_player_controller* controller) {
		if (!controller)
			return nullptr;

		c_base_handle handle = controller->m_pawn();
		if (!handle.is_valid())
			handle = read_ptr<c_base_handle>(reinterpret_cast<std::uintptr_t>(controller) + k_player_pawn_handle);
		if (!handle.is_valid())
			return nullptr;

		return reinterpret_cast<c_cs_player_pawn*>(get_base_entity_safe(handle.get_entry_index()));
	}

	vec3_t get_eye_position(c_cs_player_pawn* pawn) {
		if (!pawn)
			return {};

		vec3_t origin;
		if (auto* node = pawn->m_scene_node())
			origin = node->m_abs_origin();
		if (!origin.is_valid() || origin.is_zero())
			origin = pawn->get_eye_pos();

		const vec3_t view_offset = read_ptr<vec3_t>(reinterpret_cast<std::uintptr_t>(pawn) + k_view_offset);
		if (view_offset.is_valid() && !view_offset.is_zero())
			return origin + view_offset;

		return origin;
	}

	vec3_t get_bone_position_fast(c_cs_player_pawn* pawn, int bone) {
		if (!pawn) return {};
		return pawn->get_bone_position(bone);
	}

	bool is_enemy_pawn(c_cs_player_pawn* local, c_cs_player_pawn* pawn) {
		return pawn && pawn != local && pawn->is_alive() && pawn->m_team_num() != local->m_team_num();
	}

	c_cs_player_pawn* resolve_crosshair_pawn(int crosshair_id) {
		if (crosshair_id <= 0)
			return nullptr;

		auto* entity = get_base_entity_safe(crosshair_id & ENT_ENTRY_MASK);
		if (!entity)
			return nullptr;

		if (entity->is_player_controller())
			return pawn_from_controller(reinterpret_cast<c_cs_player_controller*>(entity));

		return reinterpret_cast<c_cs_player_pawn*>(entity);
	}

	bool can_fire(c_cs_player_pawn* local, c_base_player_weapon* weapon) {
		if (!local || !weapon)
			return false;
		if (local->m_health() <= 0 || local->is_throwing())
			return false;
		if (local->m_move_type() == MOVETYPE_LADDER || local->m_move_type() == MOVETYPE_NOCLIP)
			return false;
		if (weapon->m_clip1() <= 0 || weapon->m_in_reload())
			return false;

		const auto base = reinterpret_cast<std::uintptr_t>(local);
		if (read_ptr<bool>(base + cs2::verified::Aimbot::C_CSPlayerPawn__m_bWaitForNoAttack))
			return false;
		if (read_ptr<bool>(base + cs2::verified::Aimbot::C_CSPlayerPawn__m_bIsDefusing))
			return false;
		if (read_ptr<bool>(base + cs2::verified::Aimbot::C_CSPlayerPawn__m_bIsGrabbingHostage))
			return false;

		auto* controller = reinterpret_cast<c_cs_player_controller*>(g_ctx->m_local_controller);
		if (controller && weapon->m_next_primary_attack() > static_cast<int>(controller->m_tick_base()) + 1)
			return false;

		return true;
	}

	bool get_named_bone_position(c_cs_player_pawn* pawn, const char* name, vec3_t& out, int& bone_index) {
		if (!pawn || !name)
			return false;

		bone_index = pawn->get_bone_index(name);
		if (bone_index < 0 || bone_index >= 128)
			return false;

		out = get_bone_position_fast(pawn, bone_index);
		return out.is_valid() && !out.is_zero();
	}

	bool ray_hits_capsule(const vec3_t& ray_origin, const vec3_t& ray_dir,
		const vec3_t& capsule_start, const vec3_t& capsule_end, float radius)
	{
		const vec3_t capsule_vec = capsule_end - capsule_start;
		const float capsule_length = capsule_vec.length();

		if (capsule_length < 0.001f) {
			const vec3_t to_center = capsule_start - ray_origin;
			const float projection = to_center.dot(ray_dir);
			if (projection < 0.0f)
				return false;

			const vec3_t closest = ray_origin + ray_dir * projection;
			return (closest - capsule_start).length_sqr() <= radius * radius;
		}

		const vec3_t capsule_dir = capsule_vec / capsule_length;
		const vec3_t w = ray_origin - capsule_start;

		const float a = ray_dir.dot(ray_dir);
		const float b = ray_dir.dot(capsule_dir);
		const float c = capsule_dir.dot(capsule_dir);
		const float d = ray_dir.dot(w);
		const float e = capsule_dir.dot(w);
		const float denom = a * c - b * b;

		float s_val = 0.0f;
		float t = 0.0f;
		if (std::abs(denom) < 0.0001f) {
			s_val = 0.0f;
			t = (b > c) ? (d / b) : (e / c);
		}
		else {
			s_val = (b * e - c * d) / denom;
			t = (a * e - b * d) / denom;
		}

		t = std::clamp(t, 0.0f, capsule_length);
		if (s_val < 0.0f)
			return false;

		const vec3_t point_on_capsule = capsule_start + capsule_dir * t;
		const vec3_t point_on_ray = ray_origin + ray_dir * s_val;
		return (point_on_ray - point_on_capsule).length_sqr() <= radius * radius;
	}

	struct capsule_def_t {
		const char* a;
		const char* b;
		float radius;
	};

	std::vector<capsule_def_t> selected_capsules() {
		std::vector<capsule_def_t> capsules;
		const int mask = active_aim_group().m_trigger_hitbox;

		if (mask == 0) {
			capsules.push_back({ "head_0", "head_0", 2.65f });
			capsules.push_back({ "head_0", "neck_0", 1.75f });
			return capsules;
		}

		if (mask & (1 << 0)) {
			capsules.push_back({ "head_0", "head_0", 2.65f });
			capsules.push_back({ "head_0", "neck_0", 1.75f });
		}
		if (mask & (1 << 1)) {
			capsules.push_back({ "neck_0", "spine_3", 3.10f });
		}
		if (mask & (1 << 2)) {
			capsules.push_back({ "spine_3", "spine_2", 3.85f });
			capsules.push_back({ "spine_2", "spine_1", 4.10f });
			capsules.push_back({ "spine_1", "spine_0", 4.10f });
		}
		if (mask & (1 << 3)) {
			capsules.push_back({ "spine_0", "pelvis", 4.30f });
		}
		if (mask & (1 << 4)) {
			capsules.push_back({ "pelvis", "leg_upper_L", 3.10f });
			capsules.push_back({ "pelvis", "leg_upper_R", 3.10f });
		}

		return capsules;
	}

	struct trigger_target_t {
		c_cs_player_pawn* pawn = nullptr;
		float fov = 1000.0f;
	};

	bool test_capsules(c_cs_player_pawn* pawn, const vec3_t& ray_origin, const vec3_t& ray_dir) {

		constexpr float radius_scale = 1.0f;

		for (const auto& cap : selected_capsules()) {
			vec3_t a;
			vec3_t b;
			int bone_a = -1;
			int bone_b = -1;
			if (!get_named_bone_position(pawn, cap.a, a, bone_a))
				continue;
			if (!get_named_bone_position(pawn, cap.b, b, bone_b))
				continue;

			if (ray_hits_capsule(ray_origin, ray_dir, a, b, cap.radius * radius_scale))
				return true;
		}

		return false;
	}

	trigger_target_t find_ray_target(c_cs_player_pawn* local, i_csgo_input* input, const vec3_t& ray_origin, const vec3_t& ray_dir) {
		trigger_target_t result{};
		if (!local || !input)
			return result;

		vec3_t view = input->get_view_angles();
		if (!view.is_valid())
			view = input->view_angles;
		if (!view.is_valid())
			view = read_ptr<vec3_t>(client_base() + cs2_dumper::offsets::client_dll::dwViewAngles);
		if (!view.is_valid())
			return result;
		view = normalize_angles(view);

		auto test_pawn = [&](c_cs_player_pawn* pawn, bool use_visibility_check = false) {
			if (!is_enemy_pawn(local, pawn))
				return;

			if (use_visibility_check && g_cfg->aim.m_visibility_check) {
				const vec3_t enemy_eye = get_eye_position(pawn);
				if (!enemy_eye.is_valid() || enemy_eye.is_zero())
					return;

				const uintptr_t skip = reinterpret_cast<uintptr_t>(local);
				const bool is_visible = vis_trace::is_visible(ray_origin, enemy_eye, skip);

				if (!is_visible)
					return;
			}

			bool capsule_hit = test_capsules(pawn, ray_origin, ray_dir);

			if (!capsule_hit)
				return;

			vec3_t target_pos = get_eye_position(pawn);
			if (!target_pos.is_valid() || target_pos.is_zero()) {
				if (auto* node = pawn->m_scene_node())
					target_pos = node->m_abs_origin() + vec3_t(0.0f, 0.0f, 64.0f);
			}

			const float fov = target_pos.is_valid() && !target_pos.is_zero()
				? angle_distance(view, calc_angle(ray_origin, target_pos))
				: 0.0f;
			if (fov < result.fov) {
				result.fov = fov;
				result.pawn = pawn;
			}
		};

		if (auto* target = resolve_crosshair_pawn(read_ptr<int>(reinterpret_cast<std::uintptr_t>(local) + k_id_ent_index)))
			test_pawn(target, false);
		if (auto* target = resolve_crosshair_pawn(input->target_entity_index))
			test_pawn(target, false);

		for (int i = 1; i <= 64; ++i) {
			__try {
				auto* entity = get_base_entity_safe(i);
				if (!entity || !entity->is_player_controller())
					continue;

				auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
				if (controller == g_ctx->m_local_controller)
					continue;

				test_pawn(pawn_from_controller(controller), true);
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {}
		}

		return result;
	}

	class valve_rng {
	public:
		void seed(int seed_val) {
			m_state = -std::abs(seed_val);
			m_index = 0;
			m_seeded = false;
		}

		int generate() {
			if (!m_seeded) {
				auto v = -m_state;
				if (v < 1)
					v = 1;

				for (int j = 39; j >= 0; --j) {
					v = lcg(v);
					if (j < 32)
						m_table[j] = v;
				}

				m_state = v;
				m_index = m_table[0];
				m_seeded = true;
			}

			m_state = lcg(m_state);
			const auto idx = m_index / 0x4000000;
			m_index = m_table[idx];
			m_table[idx] = m_state;
			return m_index;
		}

		float random_float(float min = 0.0f, float max = 1.0f) {
			const auto raw = generate();
			const auto norm = std::fminf(0.99999988f, static_cast<float>(raw) * 4.6566129e-10f);
			return min + norm * (max - min);
		}

	private:
		static int lcg(int state) {
			const auto k = state / 127773;
			auto result = 16807 * (state - k * 127773) - 2836 * k;
			if (result < 0)
				result += 2147483647;
			return result;
		}

		int m_state{ 0 };
		int m_index{ 0 };
		int m_table[32]{};
		bool m_seeded{ false };
	};

	class sha1 {
	public:
		void reset() {
			m_state[0] = 0x67452301;
			m_state[1] = 0xEFCDAB89;
			m_state[2] = 0x98BADCFE;
			m_state[3] = 0x10325476;
			m_state[4] = 0xC3D2E1F0;
			m_count = 0;
		}

		void update(const void* data, std::size_t len) {
			const auto* bytes = static_cast<const std::uint8_t*>(data);
			auto index = static_cast<std::size_t>(m_count & 63);
			m_count += len;
			std::size_t i{ 0 };

			if (index) {
				const auto part_len = 64 - index;
				if (len >= part_len) {
					std::memcpy(m_buffer + index, bytes, part_len);
					transform(m_buffer);
					i = part_len;
				}
				else {
					std::memcpy(m_buffer + index, bytes, len);
					return;
				}
			}

			for (; i + 64 <= len; i += 64)
				transform(bytes + i);
			if (i < len)
				std::memcpy(m_buffer, bytes + i, len - i);
		}

		void final() {
			std::uint8_t padding[64]{};
			padding[0] = 0x80;
			auto index = static_cast<std::size_t>(m_count & 63);
			auto pad_len = (index < 56) ? (56 - index) : (120 - index);
			auto bit_count = m_count * 8;
			update(padding, pad_len);

			std::uint8_t bits[8]{};
			for (int i = 0; i < 8; ++i)
				bits[7 - i] = static_cast<std::uint8_t>(bit_count >> (i * 8));
			update(bits, 8);

			for (int i = 0; i < 5; ++i) {
				m_digest[i * 4 + 0] = static_cast<std::uint8_t>(m_state[i] >> 24);
				m_digest[i * 4 + 1] = static_cast<std::uint8_t>(m_state[i] >> 16);
				m_digest[i * 4 + 2] = static_cast<std::uint8_t>(m_state[i] >> 8);
				m_digest[i * 4 + 3] = static_cast<std::uint8_t>(m_state[i]);
			}
		}

		std::uint32_t get_first_uint32() const {
			std::uint32_t result;
			std::memcpy(&result, m_digest, sizeof(result));
			return result;
		}

	private:
		static std::uint32_t rotl(std::uint32_t v, int n) {
			return (v << n) | (v >> (32 - n));
		}

		void transform(const std::uint8_t* block) {
			std::uint32_t w[80]{};
			for (int i = 0; i < 16; ++i) {
				w[i] = static_cast<std::uint32_t>(block[i * 4]) << 24 |
					static_cast<std::uint32_t>(block[i * 4 + 1]) << 16 |
					static_cast<std::uint32_t>(block[i * 4 + 2]) << 8 |
					static_cast<std::uint32_t>(block[i * 4 + 3]);
			}
			for (int i = 16; i < 80; ++i)
				w[i] = rotl(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);

			auto a = m_state[0];
			auto b = m_state[1];
			auto c = m_state[2];
			auto d = m_state[3];
			auto e = m_state[4];

			for (int i = 0; i < 80; ++i) {
				std::uint32_t f, k;
				if (i < 20) {
					f = (b & c) | ((~b) & d);
					k = 0x5A827999;
				}
				else if (i < 40) {
					f = b ^ c ^ d;
					k = 0x6ED9EBA1;
				}
				else if (i < 60) {
					f = (b & c) | (b & d) | (c & d);
					k = 0x8F1BBCDC;
				}
				else {
					f = b ^ c ^ d;
					k = 0xCA62C1D6;
				}

				const auto temp = rotl(a, 5) + f + e + k + w[i];
				e = d;
				d = c;
				c = rotl(b, 30);
				b = a;
				a = temp;
			}

			m_state[0] += a;
			m_state[1] += b;
			m_state[2] += c;
			m_state[3] += d;
			m_state[4] += e;
		}

		std::uint32_t m_state[5]{};
		std::uint64_t m_count{ 0 };
		std::uint8_t m_buffer[64]{};
		std::uint8_t m_digest[20]{};
	};

	float normalize_angle(float a) {
		return a - std::floorf(a * 0.0027777778f + 0.5f) * 360.0f;
	}

	float quantize_angle(float a) {
		return std::floorf(normalize_angle(a) * 2.0f) * 0.5f;
	}

	std::uint32_t get_spread_seed(const vec3_t& angles, int tick) {
		struct {
			float pitch;
			float yaw;
			int player_render_tick;
		} buffer{};

		buffer.pitch = quantize_angle(angles.x);
		buffer.yaw = quantize_angle(angles.y);
		buffer.player_render_tick = tick;

		sha1 hash;
		hash.reset();
		hash.update(&buffer, 12);
		hash.final();
		return hash.get_first_uint32();
	}

	struct spread_vec_t {
		float x;
		float y;
	};

	spread_vec_t calculate_spread(int seed, float inaccuracy, float spread, float recoil_index, int item_def_idx, int num_bullets) {
		constexpr std::uint16_t revolver_id = 64;
		constexpr std::uint16_t negev_id = 28;
		constexpr auto two_pi = 2.0f * k_pi;

		valve_rng rng;
		rng.seed(seed);

		auto inac_r = rng.random_float(0.0f, 1.0f);
		auto inac_a = rng.random_float(0.0f, two_pi);
		if (item_def_idx == revolver_id && num_bullets == 1)
			inac_r = 1.0f - (inac_r * inac_r);
		else if (item_def_idx == negev_id && recoil_index < 3.0f) {
			auto v = inac_r; auto c = 3;
			do { --c; v *= v; } while (static_cast<float>(c) > recoil_index);
			inac_r = 1.0f - v;
		}
		inac_r *= inaccuracy;

		auto spr_r = rng.random_float(0.0f, 1.0f);
		auto spr_a = rng.random_float(0.0f, two_pi);
		if (item_def_idx == revolver_id && num_bullets == 1)
			spr_r = 1.0f - (spr_r * spr_r);
		else if (item_def_idx == negev_id && recoil_index < 3.0f) {
			auto v = spr_r; auto c = 3;
			do { --c; v *= v; } while (static_cast<float>(c) > recoil_index);
			spr_r = 1.0f - v;
		}
		spr_r *= spread;

		return {
			std::cosf(spr_a) * spr_r + std::cosf(inac_a) * inac_r,
			std::sinf(spr_a) * spr_r + std::sinf(inac_a) * inac_r
		};
	}

	bool build_seed_ray(c_cs_player_pawn* local, c_base_player_weapon* weapon, i_csgo_input* input, c_user_cmd* cmd,
		int tick_offset, vec3_t& ray_origin, vec3_t& ray_dir)
	{
		if (!local || !weapon || !input)
			return false;

		auto* cs_weapon = reinterpret_cast<c_cs_weapon_base*>(weapon);
		cs_weapon->update_accuracy_penalty();

		const float spread = cs_weapon->get_spread();
		const float inaccuracy = cs_weapon->get_inaccuracy();
		if (!std::isfinite(spread) || !std::isfinite(inaccuracy))
			return false;

		const auto weapon_addr = reinterpret_cast<std::uintptr_t>(weapon);
		float recoil_index = read_ptr<float>(weapon_addr + cs2::verified::Aimbot::C_CSWeaponBase__m_flRecoilIndex);
		if (!std::isfinite(recoil_index))
			recoil_index = 0.0f;

		const int item_def_idx = static_cast<int>(read_ptr<std::uint16_t>(
			weapon_addr + cs2::verified::ESP::C_BasePlayerWeapon__m_iItemDefinitionIndex
		));

		int num_bullets = 1;
		if (auto* weapon_data = weapon->get_weapon_data())
			num_bullets = (std::max)(1, weapon_data->m_bullets());

		vec3_t view = get_effective_view_angles(input, cmd);
		if (!view.is_valid())
			return false;

		const auto punch_service = read_ptr<std::uintptr_t>(
			reinterpret_cast<std::uintptr_t>(local) + cs2::verified::Triggerbot__Seeded_::C_CSPlayerPawn__m_pAimPunchServices
		);
		vec3_t aim_punch{};
		if (punch_service)
			aim_punch = read_ptr<vec3_t>(punch_service + 0x40);

		vec3_t forward;
		vec3_t right;
		vec3_t up;
		angle_vectors(normalize_angles(view + aim_punch), &forward, &right, &up);

		auto* controller = reinterpret_cast<c_cs_player_controller*>(g_ctx->m_local_controller);
		const int tick = controller ? static_cast<int>(controller->m_tick_base()) : 0;

		vec3_t quantized_view;
		quantized_view.x = quantize_angle(view.x);
		quantized_view.y = quantize_angle(view.y);
		quantized_view.z = 0.0f;

		const std::uint32_t seed = get_spread_seed(quantized_view, tick + tick_offset);
		const auto spread_offset = calculate_spread(seed + 1, inaccuracy, spread, recoil_index, item_def_idx, num_bullets);

		ray_dir = (forward + right * -spread_offset.x + up * spread_offset.y).normalize();
		if (!ray_dir.is_valid() || ray_dir.is_zero())
			return false;

		const vec3_t velocity = read_ptr<vec3_t>(
			reinterpret_cast<std::uintptr_t>(local) + cs2::verified::Aimbot::C_BaseEntity__m_vecVelocity
		);
		constexpr float tick_interval = 1.0f / 64.0f;
		ray_origin = get_eye_position(local) + velocity * ((std::max)(0, tick_offset) * tick_interval);
		return ray_origin.is_valid() && !ray_origin.is_zero();
	}

	bool seed_hits_target(c_cs_player_pawn* local, c_base_player_weapon* weapon, i_csgo_input* input, c_user_cmd* cmd, c_cs_player_pawn* target) {
		if (!local || !weapon || !input || !target)
			return false;

		vec3_t origin;
		vec3_t dir;
		if (!build_seed_ray(local, weapon, input, cmd, 0, origin, dir))
			return false;

		return test_capsules(target, origin, dir);
	}

	bool hitchance_pass(c_cs_player_pawn* local, c_base_player_weapon* weapon,
		i_csgo_input* input, c_user_cmd* cmd, c_cs_player_pawn* target)
	{
		(void)local; (void)input; (void)cmd; (void)target;
		if (!weapon || active_aim_group().m_hitchance <= 0.0f)
			return true;

		auto* cs_weapon = reinterpret_cast<c_cs_weapon_base*>(weapon);
		cs_weapon->update_accuracy_penalty();

		const float spread = cs_weapon->get_spread();
		const float inaccuracy = cs_weapon->get_inaccuracy();
		if (!std::isfinite(spread) || !std::isfinite(inaccuracy))
			return false;

		const float score = std::clamp(100.0f - (spread + inaccuracy) * 1600.0f, 0.0f, 100.0f);
		return score >= active_aim_group().m_hitchance;
	}

}

void c_aim::run_triggerbot(i_csgo_input* input, c_user_cmd* cmd, c_cs_player_pawn* local) {
	if (!local || !input || !cmd)
		return;

	auto release_attack = [&]() {
		if (m_trigger_was_down)
			set_attack(cmd, false);
		m_trigger_was_down = false;
	};

	auto reset_trigger = [&]() {
		release_attack();
		m_next_trigger_time = 0;
		m_trigger_target = 0;
		m_last_trigger_delay = -1.0f;
	};

	const auto& t_group = resolve_aim_group(local);
	g_active_aim_group = &t_group;

	const bool trigger_on = t_group.m_triggerbot &&
		bind_active(g_cfg->aim.m_triggerbot_key, g_cfg->aim.m_triggerbot_mode, UI::IsBindActive("triggerbot"));

	if (!trigger_on) {
		reset_trigger();
		return;
	}

	auto* weapon = local->get_active_weapon();
	if (!can_fire(local, weapon)) {
		reset_trigger();
		return;
	}

	vec3_t eye = get_eye_position(local);
	if (!eye.is_valid() || eye.is_zero()) {
		reset_trigger();
		return;
	}

	vec3_t view = get_effective_view_angles(input, cmd);
	if (!view.is_valid()) {
		reset_trigger();
		return;
	}

	const bool seed_mode = t_group.m_seed_prediction;
	trigger_target_t target_info{};

	if (seed_mode) {

		vec3_t seed_origin;
		vec3_t seed_dir;
		if (!build_seed_ray(local, weapon, input, cmd, 0, seed_origin, seed_dir)) {
			reset_trigger();
			return;
		}

		target_info = find_ray_target(local, input, seed_origin, seed_dir);
		if (!target_info.pawn) {
			reset_trigger();
			return;
		}

	}
	else {
		vec3_t ray_dir;
		angle_vectors(view, &ray_dir);
		ray_dir = ray_dir.normalize();
		if (!ray_dir.is_valid() || ray_dir.is_zero()) {
			reset_trigger();
			return;
		}

		target_info = find_ray_target(local, input, eye, ray_dir);
		if (!target_info.pawn) {
			reset_trigger();
			return;
		}

		if (!hitchance_pass(local, weapon, input, cmd, target_info.pawn)) {
			reset_trigger();
			return;
		}
	}

	auto* target = target_info.pawn;
	if (!is_enemy_pawn(local, target)) {
		reset_trigger();
		return;
	}

	const auto now = GetTickCount64();
	const float delay_value = seed_mode ? 0.0f : (std::max)(0.0f, t_group.m_trigger_delay);
	long long delay = static_cast<long long>(delay_value);
	if (delay > 10) {
		static std::mt19937 rng(static_cast<unsigned int>(now & 0xFFFFFFFF));
		static std::uniform_int_distribution<int> dist(-5, 5);
		delay += dist(rng);
	}
	const auto target_id = reinterpret_cast<std::uintptr_t>(target);

	if (m_trigger_target != target_id || m_last_trigger_delay != delay_value || m_next_trigger_time == 0) {
		m_trigger_target = target_id;
		m_last_trigger_delay = delay_value;
		m_next_trigger_time = now + delay;
		release_attack();
	}

	if (now >= m_next_trigger_time) {

		if (seed_mode && weapon) {
			auto* ctrl = reinterpret_cast<c_cs_player_controller*>(g_ctx->m_local_controller);
			const int tick = ctrl ? static_cast<int>(ctrl->m_tick_base()) : 0;

			auto* cs_weapon = reinterpret_cast<c_cs_weapon_base*>(weapon);
			cs_weapon->update_accuracy_penalty();

			const float spread = cs_weapon->get_spread();
			const float inaccuracy = cs_weapon->get_inaccuracy();

			if (std::isfinite(spread) && std::isfinite(inaccuracy)) {
				const auto wa = reinterpret_cast<std::uintptr_t>(weapon);
				float recoil_index = read_ptr<float>(wa + cs2::verified::Aimbot::C_CSWeaponBase__m_flRecoilIndex);
				if (!std::isfinite(recoil_index)) recoil_index = 0.0f;

				const int item_def_idx = static_cast<int>(read_ptr<std::uint16_t>(
					wa + cs2::verified::ESP::C_BasePlayerWeapon__m_iItemDefinitionIndex
				));

				int num_bullets = 1;
				if (auto* wd = weapon->get_weapon_data())
					num_bullets = (std::max)(1, wd->m_bullets());

				const auto punch_service = read_ptr<std::uintptr_t>(
					reinterpret_cast<std::uintptr_t>(local) + cs2::verified::Triggerbot__Seeded_::C_CSPlayerPawn__m_pAimPunchServices
				);
				vec3_t aim_punch{};
				if (punch_service)
					aim_punch = read_ptr<vec3_t>(punch_service + 0x40);

				vec3_t quantized_view;
				quantized_view.x = quantize_angle(view.x);
				quantized_view.y = quantize_angle(view.y);
				quantized_view.z = 0.0f;

				const std::uint32_t seed = get_spread_seed(quantized_view, tick);
				const auto sv = calculate_spread(seed + 1, inaccuracy, spread, recoil_index, item_def_idx, num_bullets);

				vec3_t target_pos;
				if (target) {
					target_pos = get_eye_position(target);
					if (!target_pos.is_valid() || target_pos.is_zero()) {
						if (auto* node = target->m_scene_node())
							target_pos = node->m_abs_origin() + vec3_t(0.0f, 0.0f, 64.0f);
					}
				}

				if (target_pos.is_valid() && !target_pos.is_zero()) {

					const vec3_t desired_dir = (target_pos - eye).normalize();

					vec3_t forward_punch, right_punch, up_punch;
					angle_vectors(normalize_angles(view + aim_punch), &forward_punch, &right_punch, &up_punch);

					const vec3_t compensated_dir = (desired_dir + right_punch * sv.x + up_punch * -sv.y).normalize();

					const float hyp = std::sqrtf(compensated_dir.x * compensated_dir.x + compensated_dir.y * compensated_dir.y);
					float comp_pitch = std::atan2f(-compensated_dir.z, hyp) * (180.0f / k_pi);
					float comp_yaw = std::atan2f(compensated_dir.y, compensated_dir.x) * (180.0f / k_pi);

					vec3_t final_angles = normalize_angles(vec3_t(comp_pitch, comp_yaw, 0.0f) - aim_punch);

					if (input) { vec3_t out = final_angles; input->set_view_angles(out); }
				}
			}
		}
		set_attack(cmd, true);
		m_trigger_was_down = true;
	}
	else {
		release_attack();
	}
}
