#include "teammate_esp.hpp"
#include "../../config.hpp"
#include "../../sdk/verified_features.hpp"
#include "../../sdk/offsets.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"
#pragma warning(disable : 4324)
#pragma warning(disable : 4505)
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/signatures/signatures.hpp"
#include "../../../ui/menu/menu.hpp"
#include "../../../ui/assets/weapon_icons.hpp"
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include "pixel_font.hpp"
#include <cstring>
#include <cstdint>

namespace {
	template <typename T>
	T read(std::uintptr_t address) {
		if (!address)
			return {};
		__try {
			return *reinterpret_cast<T*>(address);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return {};
		}
	}

	template <typename T>
	void write(std::uintptr_t address, const T& value) {
		if (!address)
			return;
		__try {
			*reinterpret_cast<T*>(address) = value;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	static bool is_in_active_game() {
		if (!g_ctx || !g_ctx->m_local_pawn || !g_ctx->m_local_controller)
			return false;

		auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
		if (!local_pawn)
			return false;

		__try {
			const int team = local_pawn->m_team_num();
			if (team != 2 && team != 3)
				return false;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}

		return true;
	}

	static int pack_color(const ImVec4& color) {
		const auto r = static_cast<int>(std::clamp(color.x, 0.0f, 1.0f) * 255.0f);
		const auto g = static_cast<int>(std::clamp(color.y, 0.0f, 1.0f) * 255.0f);
		const auto b = static_cast<int>(std::clamp(color.z, 0.0f, 1.0f) * 255.0f);
		const auto a = static_cast<int>(std::clamp(color.w, 0.0f, 1.0f) * 255.0f);
		return r | (g << 8) | (b << 16) | (a << 24);
	}

	static void apply_enemy_glow(c_cs_player_pawn* pawn, bool enabled) {
		if (!pawn)
			return;

		constexpr std::uintptr_t glow_offset = 0xDE8; // @sdk schema:C_BaseModelEntity::m_Glow
		constexpr std::uintptr_t glow_color_offset = 0x40; // @sdk schema:CGlowProperty::m_glowColorOverride
		constexpr std::uintptr_t glow_type_offset = 0x30; // @sdk schema:CGlowProperty::m_iGlowType
		constexpr std::uintptr_t flashing_offset = 0x44; // @sdk schema:CGlowProperty::m_bFlashing
		constexpr std::uintptr_t eligible_offset = 0x50; // @sdk schema:CGlowProperty::m_bEligibleForScreenHighlight
		constexpr std::uintptr_t glowing_offset = 0x51; // @sdk schema:CGlowProperty::m_bGlowing
		const auto glow = reinterpret_cast<std::uintptr_t>(pawn) + glow_offset;
		using on_glow_type_changed_t = __int64(__fastcall*)(void*);
		static auto on_glow_type_changed = reinterpret_cast<on_glow_type_changed_t>(
			SIG("CGlowProperty_OnGlowTypeChanged")
		);

		const auto old_color = read<int>(glow + glow_color_offset);
		const auto old_type = read<int>(glow + glow_type_offset);
		const auto old_glowing = read<bool>(glow + glowing_offset);
		const auto old_eligible = read<bool>(glow + eligible_offset);

		if (!enabled) {
			if (old_glowing || old_type != 0 || old_eligible) {
				write<bool>(glow + glowing_offset, false);
				write<bool>(glow + eligible_offset, false);
				write<int>(glow + glow_type_offset, 0);
				if (on_glow_type_changed)
					on_glow_type_changed(reinterpret_cast<void*>(glow));
			}
			return;
		}

		const auto& color = g_cfg->visuals.m_enemy_glow_color;
		const int packed_color = pack_color(color);
		const bool changed = old_color != packed_color || old_type != 3 || !old_glowing || !old_eligible;

		write<int>(glow + glow_color_offset, packed_color);
		write<bool>(glow + flashing_offset, false);
		write<bool>(glow + eligible_offset, true);
		write<int>(glow + glow_type_offset, 3);
		write<bool>(glow + glowing_offset, true);

		if (changed && on_glow_type_changed)
			on_glow_type_changed(reinterpret_cast<void*>(glow));
	}

	static bool is_valid_identity(c_entity_identity* identity, bool require_safe_to_modify = false) {
		if (!identity)
			return false;

		__try {
			if (!identity->is_valid())
				return false;
			return !require_safe_to_modify || identity->is_safe_to_modify();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}
	}

	static c_base_entity* get_base_entity_safe(int index) {
		if (!g_interfaces || !g_interfaces->m_entity_system)
			return nullptr;

		__try {
			return g_interfaces->m_entity_system->get_base_entity(index);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	static int get_entity_scan_limit(int fallback = 1024) {
		if (!g_interfaces || !g_interfaces->m_entity_system)
			return fallback;

		__try {
			const int highest = g_interfaces->m_entity_system->get_highest_entity_index();
			if (highest >= fallback && highest <= ENT_MAX_NETWORKED_ENTRY)
				return highest;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}

		return fallback;
	}

	static bool is_smoke_projectile(c_base_entity* entity) {
		if (!entity)
			return false;

		__try {
			if (const char* designer_name = entity->get_designer_name())
				if (std::strcmp(designer_name, "smokegrenade_projectile") == 0)
					return true;

			if (const char* class_name = entity->get_class_name())
				return std::strcmp(class_name, "C_SmokeGrenadeProjectile") == 0;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}

		return false;
	}

	static int get_entity_team_safe(c_base_entity* entity) {
		if (!entity)
			return 0;

		__try {
			auto owner_handle = entity->m_owner_entity();
			if (owner_handle.is_valid()) {
				if (auto* owner = get_base_entity_safe(owner_handle.get_entry_index()))
					return owner->m_team_num();
			}

			return entity->m_team_num();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return 0;
		}
	}

	static void set_smoke_color_safe(c_base_entity* entity, const ImVec4& color) {
		if (!entity)
			return;

		static std::uint32_t smoke_color_offset = 0;
		static bool offset_initialized = false;
		if (!offset_initialized) {
			smoke_color_offset = schema_get_offset("client.dll", "C_SmokeGrenadeProjectile", "m_vSmokeColor");
			if (!smoke_color_offset)
				smoke_color_offset = 0x136C; // @sdk schema:C_SmokeGrenadeProjectile::m_vSmokeColor
			offset_initialized = true;
		}

		if (!smoke_color_offset)
			return;

		__try {
			auto* smoke_color = reinterpret_cast<vec3_t*>(reinterpret_cast<std::uintptr_t>(entity) + smoke_color_offset);
			smoke_color->x = color.x * 255.0f;
			smoke_color->y = color.y * 255.0f;
			smoke_color->z = color.z * 255.0f;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	static void apply_smoke_colors() {
		if (!g_cfg->visuals.m_smoke_color)
			return;

		const int scan_limit = get_entity_scan_limit();
		for (int i = 1; i <= scan_limit; ++i) {
			auto* entity = get_base_entity_safe(i);
			if (!entity || !is_smoke_projectile(entity))
				continue;

			const int team = get_entity_team_safe(entity);
			const auto& color = team == 2 ? g_cfg->visuals.m_smoke_color_t : g_cfg->visuals.m_smoke_color_ct;
			set_smoke_color_safe(entity, color);
		}
	}

	bool world_to_screen(const vec3_t& in, ImVec2& out);

	namespace grenade_prediction {
		constexpr uint64_t contents_solid = 0x00000001;
		constexpr uint64_t contents_hitboxes = 0x00000002;
		constexpr uint64_t contents_sky = 0x00000008;
		constexpr uint64_t contents_window = 0x00001000;
		constexpr uint64_t contents_passbullets = 0x00002000;
		constexpr uint64_t contents_player = 0x00040000;
		constexpr uint64_t contents_npc = 0x00080000;
		constexpr uint64_t contents_debris = 0x00100000;
		constexpr uint64_t mask_shot = contents_solid | contents_hitboxes | contents_window |
			contents_passbullets | contents_player | contents_npc | contents_debris;
		constexpr uint64_t mask_grenade = (mask_shot & ~contents_window) | contents_sky;
		constexpr float visible_fraction = 0.97f;
		constexpr float sim_dt = 1.0f / 64.0f;
		constexpr int max_ticks = 1024;
		constexpr int ticks_per_point = 4;
		constexpr float gravity = 320.0f;
		constexpr float elasticity = 0.45f;
		constexpr float stop_speed_sq = 2036.0f;
		constexpr float molotov_max_slope_z = 0.8660254f;
		constexpr float steep_bounce_normal_z = 0.7f;
		constexpr float steep_bounce_speed_sq = 96000.0f;
		constexpr float grenade_hull_radius = 2.0f;

		enum class kind {
			flashbang,
			he,
			smoke,
			decoy,
			molotov,
			incendiary
		};

		struct trace_array_element_t { char data[0x30]; };
		struct bullet_modulate_entry_t {
			float start_frac;
			float end_frac;
			float damage;
			int max_secondary_traces;
			uint16_t surf_start;
			uint16_t surf_end;
			uint8_t flags;
			uint8_t pad[3];
		};
		struct bullet_mod_array_t {
			int size;
			char pad4[4];
			bullet_modulate_entry_t* data;
			char pad16[8];
		};
		struct alignas(16) trace_data_t {
			char pad0[24];
			trace_array_element_t arr[0x80];
			char pad_post_arr[8];
			bullet_mod_array_t mod_array;
			bullet_modulate_entry_t mod_inline[8];
			vec3_t tail_start;
			vec3_t tail_end;
			char pad_tail[12];
		};
		struct alignas(16) trace_filter_t {
			char data[164];
		};
		struct c_game_trace_t {
			void* surface;
			void* hit_entity;
			void* hitbox_data;
			char pad1[0x10];
			uint32_t contents;
			char pad2[0x4C];
			vec3_t start_pos;
			vec3_t end_pos;
			vec3_t normal;
			vec3_t pos;
			char pad3[4];
			float fraction;
			char pad_tail[0x58];
		};

		using init_trace_data_t = void(__fastcall*)(trace_data_t*);
		using init_trace_info_t = void(__fastcall*)(c_game_trace_t*);
		using init_trace_filter_t = void*(__fastcall*)(trace_filter_t*, uintptr_t, uint64_t, int, int);
		using create_trace_t = bool(__fastcall*)(trace_data_t*, vec3_t, vec3_t, trace_filter_t*, int, bool);
		using get_trace_info_t = void(__fastcall*)(trace_data_t*, c_game_trace_t*, float, void*);

		struct trace_result {
			float fraction = 1.0f;
			vec3_t end_pos{};
			vec3_t normal{};
			bool hit = false;
		};

		struct trajectory {
			std::vector<vec3_t> points;
			std::vector<vec3_t> bounces;
			vec3_t end_pos{};
			bool valid = false;
		};

		struct trace_functions {
			init_trace_data_t init_trace_data = nullptr;
			init_trace_info_t init_trace_info = nullptr;
			init_trace_filter_t init_filter = nullptr;
			create_trace_t create_trace = nullptr;
			get_trace_info_t get_trace_info = nullptr;
			bool tried = false;
		};

		trace_functions& funcs() {
			static trace_functions f;
			if (f.tried)
				return f;

			f.tried = true;
			f.init_trace_data = reinterpret_cast<init_trace_data_t>(
				g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 79 ? 33 F6 C7 47"));
			f.init_trace_info = reinterpret_cast<init_trace_info_t>(
				g_opcodes->scan("client.dll", "40 55 41 55 41 57 48 83 EC 30"));
			f.init_filter = reinterpret_cast<init_trace_filter_t>(
				g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24"));
			f.create_trace = reinterpret_cast<create_trace_t>(
				g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 50 F2 0F 10 02"));
			f.get_trace_info = reinterpret_cast<get_trace_info_t>(
				g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC 80 00 00 00 48 8B E9 0F 29 74 24 70 48 8B CA 49 8B F9 0F 28 F2 48 8B DA"));
			return f;
		}

		bool available() {
			auto& f = funcs();
			return f.init_trace_data && f.init_trace_info && f.init_filter && f.create_trace && f.get_trace_info;
		}

		vec3_t approx_normal_from_direction(const vec3_t& direction) {
			const float ax = std::fabs(direction.x);
			const float ay = std::fabs(direction.y);
			const float az = std::fabs(direction.z);
			if (az >= ax && az >= ay)
				return direction.z <= 0.0f ? vec3_t(0.0f, 0.0f, 1.0f) : vec3_t(0.0f, 0.0f, -1.0f);
			if (ax >= ay)
				return direction.x >= 0.0f ? vec3_t(-1.0f, 0.0f, 0.0f) : vec3_t(1.0f, 0.0f, 0.0f);
			return direction.y >= 0.0f ? vec3_t(0.0f, -1.0f, 0.0f) : vec3_t(0.0f, 1.0f, 0.0f);
		}

		bool trace_grenade(const vec3_t& start, const vec3_t& end, uintptr_t skip_pawn, trace_result& out) {
			auto& f = funcs();
			if (!available()) {
				out = { 1.0f, end, {}, false };
				return false;
			}

			__try {
				trace_data_t td{};
				trace_filter_t filter{};
				c_game_trace_t trace{};

				f.init_trace_data(&td);
				f.init_filter(&filter, skip_pawn, mask_grenade, 4, 7);

				const vec3_t delta = end - start;
				f.create_trace(&td, start, delta, &filter, 4, true);
				f.init_trace_info(&trace);

				if (td.mod_array.size > 0 && td.mod_array.data) {
					auto* entry = &td.mod_array.data[0];
					const uint16_t surf_idx = entry->surf_end & 0x7FFF;
					if (surf_idx < 0x80) {
						f.get_trace_info(&td, &trace, entry->start_frac, &td.arr[surf_idx]);
					}
					else {
						trace.fraction = 1.0f;
						trace.end_pos = end;
					}
				}
				else {
					trace.fraction = 1.0f;
					trace.end_pos = end;
				}

				const vec3_t segment = end - start;
				const float fraction = std::clamp(trace.fraction, 0.0f, 1.0f);
				vec3_t normal = trace.normal;
				if (normal.length_sqr() <= 1.0e-6f && segment.length_sqr() > 1.0e-6f)
					normal = approx_normal_from_direction(segment);

				out = { fraction, trace.end_pos, normal, fraction < visible_fraction };
				return true;
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				out = { 1.0f, end, {}, false };
				return false;
			}
		}

		trace_result trace_grenade_hull(const vec3_t& start, const vec3_t& end, uintptr_t skip_pawn) {
			trace_result center{};
			trace_grenade(start, end, skip_pawn, center);

			const vec3_t segment = end - start;
			const float seg_len = segment.length();
			if (seg_len <= 1.0e-3f)
				return center;

			float best_frac = center.fraction;
			vec3_t best_normal = center.normal;
			bool best_hit = center.hit;

			const vec3_t dir = segment / seg_len;
			const vec3_t helper = std::fabs(dir.z) < 0.9f ? vec3_t(0.0f, 0.0f, 1.0f) : vec3_t(1.0f, 0.0f, 0.0f);
			const vec3_t perp1_raw = dir.cross(helper);
			const float perp1_len = perp1_raw.length();
			if (perp1_len <= 1.0e-3f)
				return center;

			const vec3_t perp1 = perp1_raw / perp1_len;
			const vec3_t perp2 = dir.cross(perp1);
			const std::array<vec3_t, 4> offsets = {
				perp1 * grenade_hull_radius,
				perp1 * -grenade_hull_radius,
				perp2 * grenade_hull_radius,
				perp2 * -grenade_hull_radius
			};

			for (const auto& offset : offsets) {
				trace_result tr{};
				if (trace_grenade(start + offset, end + offset, skip_pawn, tr) && tr.fraction < best_frac) {
					best_frac = tr.fraction;
					best_normal = tr.normal;
					best_hit = tr.hit;
				}
			}

			return { best_frac, start + segment * best_frac, best_normal, best_hit };
		}

		vec3_t clip_velocity(const vec3_t& velocity, const vec3_t& normal, float overbounce) {
			const float backoff = velocity.dot(normal) * overbounce;
			vec3_t out(
				velocity.x - normal.x * backoff,
				velocity.y - normal.y * backoff,
				velocity.z - normal.z * backoff
			);
			if (std::fabs(out.x) < 0.1f) out.x = 0.0f;
			if (std::fabs(out.y) < 0.1f) out.y = 0.0f;
			if (std::fabs(out.z) < 0.1f) out.z = 0.0f;
			return out;
		}

		bool should_detonate(kind type, const vec3_t& vel, int tick) {
			switch (type) {
			case kind::smoke:
			case kind::decoy: {
				constexpr int check_ticks = 12;
				const float threshold = type == kind::smoke ? 0.1f : 0.2f;
				return vel.length_2d() < threshold && (tick % check_ticks) == 0;
			}
			case kind::molotov:
			case kind::incendiary:
				return static_cast<float>(tick) * sim_dt > 2.0f;
			case kind::flashbang:
			case kind::he:

				return static_cast<float>(tick - 8) * sim_dt > 1.5f;
			}
			return false;
		}

		bool resolve_collision(const trace_result& trace, vec3_t& pos, vec3_t& vel, kind type, uintptr_t skip_pawn) {
			if ((type == kind::molotov || type == kind::incendiary) &&
				(trace.normal.z >= molotov_max_slope_z || vel.length_sqr() < stop_speed_sq)) {
				vel = {};
				return true;
			}

			vec3_t new_vel = clip_velocity(vel, trace.normal, 2.0f) * elasticity;
			if (trace.normal.z > steep_bounce_normal_z) {
				const float speed_sq = new_vel.length_sqr();
				if (speed_sq > steep_bounce_speed_sq) {
					const float speed = std::sqrt(speed_sq);
					const float l = new_vel.dot(trace.normal) / speed;
					if (l > 0.5f)
						new_vel *= 1.5f - l;
				}

				if (new_vel.length_sqr() < stop_speed_sq) {
					vel = {};
					return false;
				}
			}

			vel = new_vel;
			const float remaining = 1.0f - trace.fraction;
			if (remaining > 0.0f) {
				const vec3_t post_end = pos + new_vel * (remaining * sim_dt);
				trace_result post{};
				trace_grenade(pos, post_end, skip_pawn, post);
				pos = post.end_pos;
			}

			return false;
		}

		bool step(vec3_t& pos, vec3_t& vel, kind type, uintptr_t skip_pawn, bool& hit) {
			const float new_vz = vel.z - gravity * sim_dt;
			const vec3_t move_vec(vel.x * sim_dt, vel.y * sim_dt, (vel.z + new_vz) * 0.5f * sim_dt);
			vel.z = new_vz;

			const vec3_t trace_end = pos + move_vec;
			const trace_result trace = trace_grenade_hull(pos, trace_end, skip_pawn);
			pos = trace.end_pos;
			hit = trace.hit;

			if (trace.hit)
				return resolve_collision(trace, pos, vel, type, skip_pawn);
			return false;
		}

		trajectory simulate(vec3_t start, vec3_t velocity, kind type, uintptr_t skip_pawn) {
			trajectory out;
			out.points.reserve(max_ticks / ticks_per_point);

			vec3_t pos = start;
			vec3_t vel = velocity;
			int bounce_count = 0;
			int tick_timer = 0;

			for (int tick = 0; tick < max_ticks; ++tick) {
				if (tick_timer == 0)
					out.points.push_back(pos);

				bool hit = false;
				const bool impact_detonate = step(pos, vel, type, skip_pawn, hit);
				if (hit) {
					++bounce_count;
					out.bounces.push_back(pos);
				}

				const bool velocity_stopped =
					std::fabs(vel.x) < 45.0f && std::fabs(vel.y) < 45.0f && vel.length_sqr() < stop_speed_sq;

				if (impact_detonate || should_detonate(type, vel, tick) || bounce_count > 20 || velocity_stopped) {
					out.end_pos = pos;
					out.valid = true;
					break;
				}

				if (hit || ++tick_timer >= ticks_per_point)
					tick_timer = 0;
			}

			if (out.valid && !out.points.empty() && (out.points.back() - out.end_pos).length_sqr() > 1.0f)
				out.points.push_back(out.end_pos);
			return out;
		}

		bool kind_from_def_index(uint16_t def_index, kind& out) {
			switch (def_index) {
			case WEAPON_FLASHBANG: out = kind::flashbang; return true;
			case WEAPON_HEGRENADE: out = kind::he; return true;
			case WEAPON_SMOKE: out = kind::smoke; return true;
			case WEAPON_MOLOTOV: out = kind::molotov; return true;
			case WEAPON_DECOY: out = kind::decoy; return true;
			case WEAPON_INCDENDIARY: out = kind::incendiary; return true;
			default: return false;
			}
		}

		bool kind_from_projectile(c_base_entity* entity, kind& out) {
			if (!entity)
				return false;

			__try {
				const char* designer_name = entity->get_designer_name();
				const char* class_name = entity->get_class_name();
				const auto contains = [](const char* text, const char* needle) {
					return text && std::strstr(text, needle) != nullptr;
				};

				const bool is_projectile =
					contains(designer_name, "_projectile") || contains(class_name, "Projectile");
				if (!is_projectile)
					return false;

				if (contains(designer_name, "flashbang") || contains(class_name, "Flashbang") || contains(class_name, "FlashbangProjectile")) { out = kind::flashbang; return true; }
				if (contains(designer_name, "hegrenade") || contains(class_name, "HEGrenade") || contains(class_name, "HEGrenadeProjectile")) { out = kind::he; return true; }
				if (contains(designer_name, "smokegrenade") || contains(class_name, "SmokeGrenade") || contains(class_name, "SmokeGrenadeProjectile")) { out = kind::smoke; return true; }
				if (contains(designer_name, "decoy") || contains(class_name, "Decoy") || contains(class_name, "DecoyProjectile")) { out = kind::decoy; return true; }
				if (contains(designer_name, "molotov") || contains(class_name, "Molotov") || contains(class_name, "MolotovProjectile")) { out = kind::molotov; return true; }
				if (contains(designer_name, "incendiary") || contains(class_name, "Incendiary") || contains(class_name, "IncendiaryProjectile")) { out = kind::incendiary; return true; }
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				return false;
			}
			return false;
		}

		float grenade_throw_speed(uint16_t def_index) {
			return (def_index == WEAPON_MOLOTOV || def_index == WEAPON_INCDENDIARY) ? 700.0f : 750.0f;
		}

		vec3_t forward_from_angles(vec3_t angles) {
			const float pitch = angles.x * (3.14159265358979323846f / 180.0f);
			const float yaw = angles.y * (3.14159265358979323846f / 180.0f);
			const float cp = std::cos(pitch);
			return vec3_t(cp * std::cos(yaw), cp * std::sin(yaw), -std::sin(pitch));
		}

		vec3_t compute_initial_velocity(vec3_t angles, float base_velocity, float throw_strength) {
			const float strength = std::fabs(throw_strength - 0.5f) < 0.1f ? 0.5f : throw_strength;
			angles.x -= (90.0f - std::fabs(angles.x)) * 10.0f / 90.0f;
			const float throw_velocity = std::clamp(base_velocity * 0.9f, 15.0f, 750.0f);
			const float throw_speed = (strength * 0.7f + 0.3f) * throw_velocity;
			return forward_from_angles(angles) * throw_speed;
		}

		vec3_t eye_position(c_cs_player_pawn* pawn) {
			if (!pawn)
				return {};

			vec3_t origin{};
			if (auto* node = pawn->m_scene_node())
				origin = node->m_abs_origin();
			if (!origin.is_valid() || origin.is_zero())
				origin = pawn->get_eye_pos();

			constexpr uintptr_t view_offset = 0xF60; // @sdk schema:C_BaseModelEntity::m_vecViewOffset
			const vec3_t offset = read<vec3_t>(reinterpret_cast<uintptr_t>(pawn) + view_offset);
			if (offset.is_valid() && !offset.is_zero())
				return origin + offset;

			return origin;
		}

		float weapon_throw_velocity(c_base_player_weapon* weapon, uint16_t def_index) {
			static const uint32_t offset = []() {
				uint32_t off = schema_get_offset("CCSWeaponBaseVData", "m_flThrowVelocity");
				return off;
			}();
			if (weapon) {
				if (offset) {
					if (auto* data = weapon->get_weapon_data()) {
						const float value = read<float>(reinterpret_cast<uintptr_t>(data) + offset);
						if (std::isfinite(value) && value > 0.0f)
							return value;
					}
				}
			}
			return grenade_throw_speed(def_index);
		}

		void draw_trajectory(ImDrawList* draw_list, const trajectory& traj, ImU32 color, ImU32 end_color) {
			if (!draw_list || traj.points.size() < 2)
				return;

			ImVec2 prev_screen{};
			bool prev_valid = world_to_screen(traj.points.front(), prev_screen);
			for (size_t i = 1; i < traj.points.size(); ++i) {
				ImVec2 cur_screen{};
				const bool cur_valid = world_to_screen(traj.points[i], cur_screen);
				if (prev_valid && cur_valid) {
					draw_list->AddLine(prev_screen, cur_screen, IM_COL32(0, 0, 0, 180), 3.0f);
					draw_list->AddLine(prev_screen, cur_screen, color, 1.6f);
				}
				prev_screen = cur_screen;
				prev_valid = cur_valid;
			}

			for (const auto& bounce : traj.bounces) {
				ImVec2 screen{};
				if (world_to_screen(bounce, screen)) {
					draw_list->AddCircleFilled(screen, 3.0f, IM_COL32(0, 0, 0, 190), 12);
					draw_list->AddCircleFilled(screen, 2.0f, color, 12);
				}
			}

			ImVec2 end_screen{};
			if (traj.valid && world_to_screen(traj.end_pos, end_screen)) {
				draw_list->AddCircle(end_screen, 5.0f, IM_COL32(0, 0, 0, 190), 18, 2.0f);
				draw_list->AddCircle(end_screen, 4.0f, end_color, 18, 1.5f);
			}
		}

		void draw_held(c_cs_player_pawn* local_pawn, ImDrawList* draw_list, ImU32 color, ImU32 end_color) {
			if (!local_pawn || !g_interfaces || !g_interfaces->m_csgo_input)
				return;

			auto* weapon = local_pawn->get_active_weapon();
			if (!weapon)
				return;

			uint16_t def_index = 0;
			if (auto* attr_mgr = weapon->m_attribute_manager())
				if (auto* item = attr_mgr->m_item())
					def_index = item->m_definition_index();

			kind type{};
			if (!kind_from_def_index(def_index, type))
				return;

			auto* grenade = reinterpret_cast<c_base_cs_grenade*>(weapon);
			if (!grenade || !grenade->m_held_by_player())
				return;

			if (!grenade->m_pin_pulled())
				return;

			const float throw_strength = std::clamp(grenade->m_throw_strength(), 0.0f, 1.0f);
			const vec3_t angles = g_interfaces->m_csgo_input->get_view_angles();
			const vec3_t forward = forward_from_angles(angles);
			const vec3_t start = eye_position(local_pawn) + forward * 16.0f + vec3_t(0.0f, 0.0f, throw_strength * 12.0f - 12.0f);
			const vec3_t velocity = compute_initial_velocity(angles, weapon_throw_velocity(weapon, def_index), throw_strength) +
				local_pawn->m_vec_abs_velocity() * 1.25f;

			draw_trajectory(draw_list, simulate(start, velocity, type, reinterpret_cast<uintptr_t>(local_pawn)), color, end_color);
		}

		void draw_projectiles(c_cs_player_pawn* local_pawn, ImDrawList* draw_list, ImU32 color, ImU32 end_color) {
			if (!local_pawn)
				return;

			const int scan_limit = get_entity_scan_limit();
			for (int i = 1; i <= scan_limit; ++i) {
				auto* entity = get_base_entity_safe(i);
				if (!entity)
					continue;

				kind type{};
				if (!kind_from_projectile(entity, type))
					continue;

				auto* node = entity->m_scene_node();
				if (!node)
					continue;

				const vec3_t origin = node->m_abs_origin();
				const vec3_t velocity = entity->m_vec_abs_velocity();
				if (!origin.is_valid())
					continue;

				draw_trajectory(draw_list, simulate(origin, velocity, type, reinterpret_cast<uintptr_t>(local_pawn)), color, end_color);
			}
		}
	}

	float* get_view_matrix() {
		static const auto view_matrix = reinterpret_cast<float*>(
			g_opcodes->scan_absolute(
				g_modules->m_modules.client_dll.get_name(),
				"48 8D 0D ? ? ? ? 48 89 44 24 ? 48 89 4C 24 ? 4C 8D 0D",
				0x3
			)
		);
		return view_matrix;
	}

	bool world_to_screen(const vec3_t& in, ImVec2& out) {
		float* matrix = get_view_matrix();
		if (!matrix)
			return false;
		const float w = matrix[12] * in.x + matrix[13] * in.y + matrix[14] * in.z + matrix[15];
		if (w < 0.0001f)
			return false;
		const float x = matrix[0] * in.x + matrix[1] * in.y + matrix[2] * in.z + matrix[3];
		const float y = matrix[4] * in.x + matrix[5] * in.y + matrix[6] * in.z + matrix[7];
		const ImVec2 display = ImGui::GetIO().DisplaySize;
		out.x = (display.x * 0.5f) + ((x / w) * display.x * 0.5f);
		out.y = (display.y * 0.5f) - ((y / w) * display.y * 0.5f);
		return std::isfinite(out.x) && std::isfinite(out.y);
	}

	static std::string to_lower_case(const std::string& str) {
		if (str.empty())
			return str;

		bool ascii_only = true;
		bool has_upper = false;
		for (const unsigned char c : str) {
			if (c >= 0x80) {
				ascii_only = false;
				break;
			}
			if (c >= 'A' && c <= 'Z')
				has_upper = true;
		}

		if (ascii_only) {
			if (!has_upper)
				return str;

			std::string result = str;
			for (char& c : result)
				if (c >= 'A' && c <= 'Z')
					c = static_cast<char>(c + 32);
			return result;
		}

		const auto size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
		std::wstring wstr(size, 0);
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size);
		CharLowerW(&wstr[0]);
		const auto size2 = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
		std::string result(size2 - 1, 0);
		WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &result[0], size2, nullptr, nullptr);
		return result;
	}

	static bool copy_c_string(char* out, std::size_t out_size, const char* str, std::size_t* out_len) {
		if (!out || out_size == 0 || !str || !out_len)
			return false;

		*out_len = 0;
		out[0] = '\0';
		const std::size_t capped_len = out_size - 1;
		__try {
			for (; *out_len < capped_len && str[*out_len] != '\0'; ++(*out_len))
				out[*out_len] = str[*out_len];
			out[*out_len] = '\0';
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			*out_len = 0;
			out[0] = '\0';
			return false;
		}

		return true;
	}

	static std::string read_c_string(const char* str) {
		if (!str)
			return {};

		char buffer[128] = {};
		std::size_t len = 0;
		if (!copy_c_string(buffer, sizeof(buffer), str, &len))
			return {};
		return std::string(buffer, len);
	}

	static std::string normalize_weapon_name(std::string name) {
		if (name.empty())
			return {};

		name = to_lower_case(name);
		const char* prefixes[] = {
			"weapon_",
			"item_",
			"c_",
		};

		for (auto prefix : prefixes) {
			const std::size_t len = std::strlen(prefix);
			if (name.rfind(prefix, 0) == 0) {
				name.erase(0, len);
				break;
			}
		}

		return name;
	}

	static std::string get_weapon_key(c_base_player_weapon* weapon) {
		if (!weapon)
			return {};

		if (auto* weapon_data = weapon->get_weapon_data()) {
			auto key = normalize_weapon_name(read_c_string(weapon_data->m_name()));
			if (!key.empty())
				return key;
		}

		if (auto* attr_mgr = weapon->m_attribute_manager()) {
			auto* item = attr_mgr->m_item();
			if (item) {
				if (auto* static_data = item->get_static_data()) {
					auto key = normalize_weapon_name(read_c_string(static_data->get_simple_weapon_name()));
					if (!key.empty())
						return key;

					key = normalize_weapon_name(read_c_string(static_data->get_weapon_name()));
					if (!key.empty())
						return key;
				}
			}
		}

		return {};
	}

	static const char* get_weapon_text(const std::string& weapon_key) {
		auto it = weapon_icons::display_table.find(weapon_key);
		if (it != weapon_icons::display_table.end() && it->second && it->second[0] != '\0')
			return it->second;
		return weapon_key.c_str();
	}

	static const char* get_weapon_icon(const std::string& weapon_key) {
		auto it = weapon_icons::icon_table.find(weapon_key);
		if (it != weapon_icons::icon_table.end() && !it->second.empty())
			return it->second.c_str();
		return nullptr;
	}

	static const char* get_class_name_safe(c_base_entity* entity) {
		__try {
			return entity ? entity->get_class_name() : nullptr;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	static uint16_t get_weapon_definition_index(c_base_player_weapon* weapon) {
		if (!weapon)
			return 0;

		__try {
			if (auto* attr_mgr = weapon->m_attribute_manager()) {
				if (auto* econ_view = attr_mgr->m_item())
					return econ_view->m_definition_index();
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}

		return 0;
	}

	static bool is_c4_weapon(c_base_player_weapon* weapon, c_base_entity* entity, const char* designer_name) {
		(void)designer_name;
		constexpr uint16_t c4_definition_index = 49;
		if (get_weapon_definition_index(weapon) == c4_definition_index)
			return true;

		__try {
			const char* class_name = entity ? entity->get_class_name() : nullptr;
			return class_name && std::strcmp(class_name, "C_C4") == 0;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}
	}

	static bool is_planted_c4_entity(c_base_entity* entity, const char* designer_name) {
		if (designer_name && std::strcmp(designer_name, "planted_c4") == 0)
			return true;

		__try {
			const char* class_name = entity ? entity->get_class_name() : nullptr;
			return class_name && std::strcmp(class_name, "C_PlantedC4") == 0;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}
	}

	static bool is_grenade_weapon(c_base_player_weapon* weapon, const char* designer_name) {
		switch (get_weapon_definition_index(weapon)) {
		case WEAPON_FLASHBANG:
		case WEAPON_HEGRENADE:
		case WEAPON_SMOKE:
		case WEAPON_MOLOTOV:
		case WEAPON_DECOY:
		case WEAPON_INCDENDIARY:
			return true;
		default:
			break;
		}

		return designer_name &&
			(std::strstr(designer_name, "flashbang") || std::strstr(designer_name, "hegrenade") ||
			 std::strstr(designer_name, "smokegrenade") || std::strstr(designer_name, "molotov") ||
			 std::strstr(designer_name, "decoy") || std::strstr(designer_name, "incgrenade") ||
			 std::strstr(designer_name, "incendiary"));
	}

	static bool is_grenade_weapon_entity(c_base_entity* entity, const char* designer_name) {
		if (designer_name &&
			(std::strstr(designer_name, "flashbang") || std::strstr(designer_name, "hegrenade") ||
			 std::strstr(designer_name, "smokegrenade") || std::strstr(designer_name, "molotov") ||
			 std::strstr(designer_name, "decoy") || std::strstr(designer_name, "incgrenade") ||
			 std::strstr(designer_name, "incendiary"))) {
			return !std::strstr(designer_name, "projectile");
		}

		__try {
			const char* class_name = entity ? entity->get_class_name() : nullptr;
			if (!class_name || std::strstr(class_name, "Projectile"))
				return false;

			return std::strstr(class_name, "Flashbang") || std::strstr(class_name, "HEGrenade") ||
				std::strstr(class_name, "SmokeGrenade") || std::strstr(class_name, "Molotov") ||
				std::strstr(class_name, "Decoy") || std::strstr(class_name, "Incendiary");
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}
	}

	static std::string get_grenade_weapon_key(c_base_player_weapon* weapon, c_base_entity* entity, const char* designer_name) {
		switch (get_weapon_definition_index(weapon)) {
		case WEAPON_FLASHBANG: return "flashbang";
		case WEAPON_HEGRENADE: return "hegrenade";
		case WEAPON_SMOKE: return "smokegrenade";
		case WEAPON_MOLOTOV: return "molotov";
		case WEAPON_DECOY: return "decoy";
		case WEAPON_INCDENDIARY: return "incgrenade";
		default:
			break;
		}

		const char* text = designer_name;
		if (!text || !text[0])
			text = get_class_name_safe(entity);

		if (!text)
			return {};

		if (std::strstr(text, "flashbang") || std::strstr(text, "Flashbang")) return "flashbang";
		if (std::strstr(text, "hegrenade") || std::strstr(text, "HEGrenade")) return "hegrenade";
		if (std::strstr(text, "smokegrenade") || std::strstr(text, "SmokeGrenade")) return "smokegrenade";
		if (std::strstr(text, "molotov") || std::strstr(text, "Molotov")) return "molotov";
		if (std::strstr(text, "decoy") || std::strstr(text, "Decoy")) return "decoy";
		if (std::strstr(text, "incgrenade") || std::strstr(text, "incendiary") || std::strstr(text, "Incendiary")) return "incgrenade";
		return {};
	}

	static bool is_weapon_entity_name(c_base_entity* entity, const char* designer_name) {
		if (designer_name && std::strstr(designer_name, "weapon_"))
			return true;
		if (is_grenade_weapon_entity(entity, designer_name))
			return true;

		__try {
			const char* class_name = entity ? entity->get_class_name() : nullptr;
			if (!class_name || std::strstr(class_name, "Projectile"))
				return false;

			return std::strcmp(class_name, "C_Flashbang") == 0 ||
				std::strcmp(class_name, "C_HEGrenade") == 0 ||
				std::strcmp(class_name, "C_SmokeGrenade") == 0 ||
				std::strcmp(class_name, "C_MolotovGrenade") == 0 ||
				std::strcmp(class_name, "C_DecoyGrenade") == 0 ||
				std::strcmp(class_name, "C_IncendiaryGrenade") == 0 ||
				std::strcmp(class_name, "C_C4") == 0;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}
	}

	static bool is_weapon_in_player_inventory(c_base_player_weapon* weapon) {
		if (!weapon || !g_interfaces || !g_interfaces->m_entity_system)
			return false;

		__try {
			if (g_ctx && g_ctx->m_local_pawn) {
				auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
				if (local_pawn->get_active_weapon() == weapon)
					return true;

				if (auto* weapon_services = local_pawn->m_weapon_services()) {
					auto& weapons = weapon_services->my_weapons();
					if (weapons.m_elements && weapons.m_size > 0 && weapons.m_size <= 64) {
						for (unsigned int j = 0; j < weapons.m_size; ++j) {
							const auto weapon_handle = weapons.m_elements[j];
							if (!weapon_handle.is_valid())
								continue;

							if (get_base_entity_safe(weapon_handle.get_entry_index()) == weapon)
								return true;
						}
					}
				}
			}

			for (int i = 1; i <= 64; ++i) {
				auto* entity = get_base_entity_safe(i);
				if (!entity || !entity->is_player_controller())
					continue;

				auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
				const auto pawn_handle = controller->m_pawn();
				if (!pawn_handle.is_valid())
					continue;

				auto* pawn = reinterpret_cast<c_cs_player_pawn*>(get_base_entity_safe(pawn_handle.get_entry_index()));
				if (!pawn)
					continue;

				if (pawn->get_active_weapon() == weapon)
					return true;

				auto* weapon_services = pawn->m_weapon_services();
				if (!weapon_services)
					continue;

				auto& weapons = weapon_services->my_weapons();
				if (!weapons.m_elements || weapons.m_size == 0 || weapons.m_size > 64)
					continue;

				for (unsigned int j = 0; j < weapons.m_size; ++j) {
					const auto weapon_handle = weapons.m_elements[j];
					if (!weapon_handle.is_valid())
						continue;

					if (get_base_entity_safe(weapon_handle.get_entry_index()) == weapon)
						return true;
				}
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}

		return false;
	}

	static bool is_dropped_weapon(c_base_player_weapon* weapon, const char* designer_name, bool grenade_weapon_entity = false) {
		if (!weapon)
			return false;
		(void)designer_name;
		(void)grenade_weapon_entity;

		if (is_weapon_in_player_inventory(weapon))
			return false;

		__try {
			const auto owner_handle = weapon->m_owner_entity();
			if (owner_handle.is_valid())
				return false;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return false;
		}

		return true;
	}

	static void draw_centered_text(ImDrawList* draw_list, ImFont* font, float font_size, const ImVec2& pos, ImU32 color, const char* text) {
		if (!text || text[0] == '\0')
			return;

		const auto text_size = font->CalcTextSizeA(font_size, FLT_MAX, 0.0f, text);
		const auto x = floorf(pos.x - text_size.x * 0.5f);
		const auto y = floorf(pos.y);
		draw_list->AddText(font, font_size, ImVec2(x + 1.0f, y + 1.0f), IM_COL32(0, 0, 0, 255), text);
		draw_list->AddText(font, font_size, ImVec2(x, y), color, text);
	}

	static unsigned int utf8_first_codepoint(const char* text) {
		if (!text || !text[0])
			return 0;

		const unsigned char b0 = static_cast<unsigned char>(text[0]);
		if (b0 < 0x80)
			return b0;
		if ((b0 & 0xE0) == 0xC0)
			return ((b0 & 0x1F) << 6) | (static_cast<unsigned char>(text[1]) & 0x3F);
		if ((b0 & 0xF0) == 0xE0)
			return ((b0 & 0x0F) << 12) | ((static_cast<unsigned char>(text[1]) & 0x3F) << 6) | (static_cast<unsigned char>(text[2]) & 0x3F);
		if ((b0 & 0xF8) == 0xF0)
			return ((b0 & 0x07) << 18) | ((static_cast<unsigned char>(text[1]) & 0x3F) << 12) | ((static_cast<unsigned char>(text[2]) & 0x3F) << 6) | (static_cast<unsigned char>(text[3]) & 0x3F);
		return 0;
	}

	static void draw_centered_icon(ImDrawList* draw_list, ImFont* font, float font_size, const ImVec2& pos, ImU32 color, const char* icon) {
		if (!font || !icon || icon[0] == '\0')
			return;

		const auto codepoint = utf8_first_codepoint(icon);
		const ImFontGlyph* glyph = codepoint ? font->FindGlyph(static_cast<ImWchar>(codepoint)) : nullptr;
		if (!glyph) {
			draw_centered_text(draw_list, font, font_size, pos, color, icon);
			return;
		}

		const float scale = font_size / font->FontSize;
		const float x = floorf(pos.x - ((glyph->X0 + glyph->X1) * scale) * 0.5f);
		const float y = floorf(pos.y);
		draw_list->AddText(font, font_size, ImVec2(x + 1.0f, y + 1.0f), IM_COL32(0, 0, 0, 255), icon);
		draw_list->AddText(font, font_size, ImVec2(x, y), color, icon);
	}

	static const pixel_font_5x5::glyph_t* pixel_glyph(char c) {
		const char lower = (c >= 'A' && c <= 'Z') ? static_cast<char>(c + 32) : c;
		const auto& g = pixel_font_5x5::glyphs[static_cast<unsigned char>(lower)];
		return g.width > 0 ? &g : nullptr;
	}

	static void draw_pixel_text(ImDrawList* draw_list, const ImVec2& pos, ImU32 color, const char* text) {
		float x = pos.x;
		float y = pos.y;
		const float pixel_size = 1.0f;
		const float char_spacing = 1.0f;
		const ImU32 outline = IM_COL32(0, 0, 0, 255);

		for (const char* c = text; *c != '\0'; ++c) {
			const auto* glyph_ptr = pixel_glyph(*c);
			if (!glyph_ptr) {
				x += 4.0f + char_spacing;
				continue;
			}

			const auto& glyph = *glyph_ptr;
			const auto pixel_at = [&](int px, int py) {
				return (glyph.rows[py] >> (glyph.width - 1 - px)) & 1;
			};

			for (int py = 0; py < glyph.height; ++py) {
				for (int px = 0; px < glyph.width; ++px) {
					if (pixel_at(px, py)) {
						float px_x = x + px * pixel_size;
						float px_y = y + py * pixel_size;

						for (int dy = -1; dy <= 1; ++dy) {
							for (int dx = -1; dx <= 1; ++dx) {
								if (dx == 0 && dy == 0) continue;
								int nx = px + dx;
								int ny = py + dy;
								bool is_empty = (nx < 0 || nx >= glyph.width ||
								                ny < 0 || ny >= glyph.height ||
								                !pixel_at(nx, ny));
								if (is_empty) {
									draw_list->AddRectFilled(
										ImVec2(px_x + dx * pixel_size, px_y + dy * pixel_size),
										ImVec2(px_x + dx * pixel_size + pixel_size, px_y + dy * pixel_size + pixel_size),
										outline
									);
								}
							}
						}
					}
				}
			}

			for (int py = 0; py < glyph.height; ++py) {
				for (int px = 0; px < glyph.width; ++px) {
					if (pixel_at(px, py)) {
						draw_list->AddRectFilled(
							ImVec2(x + px * pixel_size, y + py * pixel_size),
							ImVec2(x + px * pixel_size + pixel_size, y + py * pixel_size + pixel_size),
							color
						);
					}
				}
			}

			x += glyph.width * pixel_size + char_spacing;
		}
	}

	static ImVec2 calc_pixel_text_size(const char* text) {
		float width = 0.0f;
		const float pixel_size = 1.0f;
		const float char_spacing = 1.0f;

		for (const char* c = text; *c != '\0'; ++c) {
			const auto* glyph = pixel_glyph(*c);
			if (glyph) {
				width += glyph->width * pixel_size + char_spacing;
			} else {
				width += 4.0f + char_spacing;
			}
		}

		return ImVec2(width, 5.0f * pixel_size);
	}

	static float get_pixel_font_height() {
		return 5.0f;
	}

	static void draw_small_text(ImDrawList* draw_list, const ImVec2& pos, ImU32 color, const char* text) {
		draw_pixel_text(draw_list, pos, color, text);
	}

	static bool draw_bomb_world_esp(ImDrawList* draw_list, const vec3_t& bomb_origin, const vec3_t& local_origin, float remaining = -1.0f) {
		if (!draw_list || !g_cfg || !bomb_origin.is_valid())
			return false;

		ImVec2 screen_pos{};
		if (!world_to_screen(bomb_origin, screen_pos))
			return false;

		const ImU32 color = ImGui::ColorConvertFloat4ToU32(g_cfg->visuals.m_bomb_esp_color);
		float y_offset = 0.0f;

		if (g_cfg->visuals.m_bomb_esp_type & (1 << 0)) {
			if (auto* icon = get_weapon_icon("c4")) {
				if (g_menu) {
					if (auto* icon_font = g_menu->get_weapon_icon_font()) {
						draw_centered_icon(draw_list, icon_font, icon_font->FontSize, ImVec2(screen_pos.x, screen_pos.y + y_offset), color, icon);
						y_offset += icon_font->FontSize + 2.0f;
					}
				}
			}
		}

		if (g_cfg->visuals.m_bomb_esp_type & (1 << 1)) {
			const auto text_size = calc_pixel_text_size("c4");
			const auto text_x = floorf(screen_pos.x - text_size.x * 0.5f);
			draw_small_text(draw_list, ImVec2(text_x, screen_pos.y + y_offset), color, "c4");
			y_offset += get_pixel_font_height() + 2.0f;
		}

		if ((g_cfg->visuals.m_bomb_esp_type & (1 << 2)) && std::isfinite(remaining) && remaining > 0.0f) {
			char timer_text[64];
			snprintf(timer_text, sizeof(timer_text), "%.1fs", remaining);
			const auto text_size = calc_pixel_text_size(timer_text);
			const auto text_x = floorf(screen_pos.x - text_size.x * 0.5f);
			draw_small_text(draw_list, ImVec2(text_x, screen_pos.y + y_offset), color, timer_text);
			y_offset += get_pixel_font_height() + 2.0f;
		}

		if ((g_cfg->visuals.m_bomb_esp_type & (1 << 3)) && local_origin.is_valid()) {
			const float distance = sqrtf(
				(bomb_origin.x - local_origin.x) * (bomb_origin.x - local_origin.x) +
				(bomb_origin.y - local_origin.y) * (bomb_origin.y - local_origin.y) +
				(bomb_origin.z - local_origin.z) * (bomb_origin.z - local_origin.z)
			) * 0.0254f;
			char buf[32];
			snprintf(buf, sizeof(buf), "%.0fm", distance);
			const auto text_size = calc_pixel_text_size(buf);
			const auto text_x = floorf(screen_pos.x - text_size.x * 0.5f);
			draw_small_text(draw_list, ImVec2(text_x, screen_pos.y + y_offset), color, buf);
		}

		return true;
	}

	static bool draw_planted_c4_from_address(ImDrawList* draw_list, uintptr_t planted_c4, c_cs_player_pawn* local_pawn, const vec3_t& local_origin) {
		if (!planted_c4 || !draw_list || !local_pawn)
			return false;

		const auto* entity = reinterpret_cast<c_base_entity*>(planted_c4);
		if (!is_planted_c4_entity(const_cast<c_base_entity*>(entity), nullptr))
			return false;

		constexpr uintptr_t m_bBombTicking = 0x1288; // @sdk schema:C_PlantedC4::m_bBombTicking
		constexpr uintptr_t m_flC4Blow = 0x12B8; // @sdk schema:C_PlantedC4::m_flC4Blow
		constexpr uintptr_t m_pGameSceneNode = 0x330; // @sdk schema:C_BaseEntity::m_pGameSceneNode
		constexpr uintptr_t m_vecAbsOrigin = 0xC8; // @sdk schema:CGameSceneNode::m_vecAbsOrigin
		constexpr uintptr_t m_flSimulationTime = 0x3B8; // @sdk schema:C_BaseEntity::m_flSimulationTime

		const bool is_ticking = read<bool>(planted_c4 + m_bBombTicking);
		if (!is_ticking)
			return false;

		const uintptr_t scene_node = read<uintptr_t>(planted_c4 + m_pGameSceneNode);
		if (!scene_node)
			return false;

		const vec3_t origin = read<vec3_t>(scene_node + m_vecAbsOrigin);
		if (!origin.is_valid())
			return false;

		float remaining = -1.0f;
		if (is_ticking) {
			const float c4_blow_time = read<float>(planted_c4 + m_flC4Blow);
			const float current_time = read<float>(reinterpret_cast<uintptr_t>(local_pawn) + m_flSimulationTime);
			const float candidate = c4_blow_time - current_time;
			if (std::isfinite(candidate) && candidate > 0.0f && candidate < 120.0f)
				remaining = candidate;
		}

		return draw_bomb_world_esp(draw_list, origin, local_origin, remaining);
	}

	static const char* get_grenade_name(grenade_prediction::kind type) {
		switch (type) {
		case grenade_prediction::kind::flashbang: return "flashbang";
		case grenade_prediction::kind::he: return "he grenade";
		case grenade_prediction::kind::smoke: return "smoke";
		case grenade_prediction::kind::decoy: return "decoy";
		case grenade_prediction::kind::molotov: return "molotov";
		case grenade_prediction::kind::incendiary: return "incendiary";
		default: return "grenade";
		}
	}

	static const char* get_grenade_icon_key(grenade_prediction::kind type) {
		switch (type) {
		case grenade_prediction::kind::flashbang: return "flashbang";
		case grenade_prediction::kind::he: return "hegrenade";
		case grenade_prediction::kind::smoke: return "smokegrenade";
		case grenade_prediction::kind::molotov: return "molotov";
		case grenade_prediction::kind::decoy: return "decoy";
		case grenade_prediction::kind::incendiary: return "incgrenade";
		default: return "";
		}
	}

	static bool is_grenade_held_by_player(c_base_entity* entity) {
		__try {
			auto* grenade_weapon = reinterpret_cast<c_base_cs_grenade*>(entity);
			if (grenade_weapon && grenade_weapon->m_held_by_player())
				return true;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {

			return false;
		}
		return false;
	}

	static void draw_grenade_esp(c_cs_player_pawn* local_pawn, ImDrawList* draw_list, ImU32 color, const vec3_t& local_pos) {
		if (!local_pawn || !draw_list || !g_cfg)
			return;

		const bool need_distance = (g_cfg->visuals.m_grenades_type & (1 << 2)) != 0;
		const bool valid_local_pos = local_pos.is_valid();

		const int scan_limit = get_entity_scan_limit();
		for (int i = 1; i <= scan_limit; ++i) {
			auto* entity = get_base_entity_safe(i);
			if (!entity)
				continue;

			auto* identity = entity->m_entity();
			if (!is_valid_identity(identity))
				continue;

			grenade_prediction::kind type{};
			if (!grenade_prediction::kind_from_projectile(entity, type))
				continue;

			auto* node = entity->m_scene_node();
			if (!node)
				continue;

			const vec3_t origin = node->m_abs_origin();
			if (!origin.is_valid())
				continue;

			ImVec2 screen_pos{};
			if (!world_to_screen(origin, screen_pos))
				continue;

			float y_offset = 0.0f;

			if (g_cfg->visuals.m_grenades_type & (1 << 0)) {
				const char* icon_key = get_grenade_icon_key(type);
				if (icon_key && icon_key[0]) {
					if (auto* icon = get_weapon_icon(icon_key)) {
						if (auto* icon_font = g_menu->get_weapon_icon_font()) {
							draw_centered_icon(draw_list, icon_font, icon_font->FontSize, ImVec2(screen_pos.x, screen_pos.y + y_offset), color, icon);
							y_offset += icon_font->FontSize + 2.0f;
						}
					}
				}
			}

			if (g_cfg->visuals.m_grenades_type & (1 << 1)) {
				const char* name = get_grenade_name(type);
				if (name && name[0]) {
					const auto text_size = calc_pixel_text_size(name);
					const auto text_x = floorf(screen_pos.x - text_size.x * 0.5f);
					draw_small_text(draw_list, ImVec2(text_x, screen_pos.y + y_offset), color, name);
					y_offset += get_pixel_font_height() + 2.0f;
				}
			}

			if (need_distance && valid_local_pos) {
				const float distance = sqrtf(
					(origin.x - local_pos.x) * (origin.x - local_pos.x) +
					(origin.y - local_pos.y) * (origin.y - local_pos.y) +
					(origin.z - local_pos.z) * (origin.z - local_pos.z)
				) * 0.0254f;
				char buf[32];
				snprintf(buf, sizeof(buf), "%.0fm", distance);
				const auto text_size = calc_pixel_text_size(buf);
				const auto text_x = floorf(screen_pos.x - text_size.x * 0.5f);
				draw_small_text(draw_list, ImVec2(text_x, screen_pos.y + y_offset), color, buf);
				y_offset += get_pixel_font_height() + 2.0f;
			}

			if (g_cfg->visuals.m_grenades_type & (1 << 3)) {

				constexpr uintptr_t m_flSpawnTime = 0x12E8; // @sdk schema:C_BaseCSGrenadeProjectile::m_flSpawnTime
				constexpr uintptr_t m_flDetonateTime = 0x1270; // @sdk schema:C_BaseGrenade::m_flDetonateTime
				constexpr uintptr_t m_flSimulationTime = 0x3B8; // @sdk schema:C_BaseEntity::m_flSimulationTime

				float spawn_time = read<float>(reinterpret_cast<uintptr_t>(entity) + m_flSpawnTime);
				float detonate_time = read<float>(reinterpret_cast<uintptr_t>(entity) + m_flDetonateTime);
				float current_time = read<float>(reinterpret_cast<uintptr_t>(entity) + m_flSimulationTime);

				float time_remaining = 0.0f;

				if (detonate_time > 0.0f && current_time > 0.0f) {
					time_remaining = detonate_time - current_time;
				} else if (spawn_time > 0.0f && current_time > 0.0f) {

					float elapsed = current_time - spawn_time;
					switch (type) {
						case grenade_prediction::kind::he:
						case grenade_prediction::kind::flashbang:
							time_remaining = 1.5f - elapsed;
							break;
						case grenade_prediction::kind::smoke:
							time_remaining = 18.0f - elapsed;
							break;
						case grenade_prediction::kind::molotov:
						case grenade_prediction::kind::incendiary:
							time_remaining = 7.0f - elapsed;
							break;
						case grenade_prediction::kind::decoy:
							time_remaining = 15.0f - elapsed;
							break;
					}
				}

				if (time_remaining > 0.0f) {
					char buf[32];
					snprintf(buf, sizeof(buf), "%.1fs", time_remaining);
					const auto text_size = calc_pixel_text_size(buf);
					const auto text_x = floorf(screen_pos.x - text_size.x * 0.5f);
					draw_small_text(draw_list, ImVec2(text_x, screen_pos.y + y_offset), color, buf);
					y_offset += get_pixel_font_height() + 2.0f;
				}
			}
		}
	}

	static ImVec2 calc_small_text_size(const char* text) {
		return calc_pixel_text_size(text);
	}

	static float get_small_font_size() {
		return get_pixel_font_height();
	}

	static void draw_health_bar(ImDrawList* draw_list, int health, float animated_health, const ImVec2& box_min, const ImVec2& box_max, bool is_teammate = false) {
		if (is_teammate) {
			if (!g_cfg->visuals.m_teammate_health_bar)
				return;
		} else {
			if (!g_cfg->visuals.m_health_bar)
				return;
		}
		if (health <= 0 || animated_health <= 0.0f)
			return;

		const auto anim_clamped = (std::min)(animated_health, 100.0f);
		const auto frac = anim_clamped / 100.0f;
		const auto box_h = box_max.y - box_min.y;
		const float fill_h = box_h * frac;
		const float bar_x = box_min.x - 5.0f;
		const float bar_y = box_max.y - fill_h;

		int health_type = is_teammate ? g_cfg->visuals.m_teammate_health_type : g_cfg->visuals.m_health_type;
		bool show_bar = (health_type & (1 << 1)) != 0;
		bool show_gradient = (health_type & (1 << 2)) != 0;
		bool show_text = (health_type & (1 << 0)) != 0;

		if (show_bar) {
			const auto outline = IM_COL32(0, 0, 0, 180);
			draw_list->AddRectFilled(ImVec2(bar_x - 1.0f, box_min.y - 1.0f), ImVec2(bar_x + 3.0f, box_max.y + 1.0f), outline);

			if (show_gradient) {
				const auto& low = is_teammate ? g_cfg->visuals.m_teammate_health_low_color : g_cfg->visuals.m_health_low_color;
				const auto& high = is_teammate ? g_cfg->visuals.m_teammate_health_high_color : g_cfg->visuals.m_health_high_color;
				const float t = frac;
				const ImVec4 top_color(
					low.x + (high.x - low.x) * t,
					low.y + (high.y - low.y) * t,
					low.z + (high.z - low.z) * t,
					low.w + (high.w - low.w) * t
				);

				draw_list->AddRectFilledMultiColor(
					ImVec2(bar_x, bar_y),
					ImVec2(bar_x + 2.0f, box_max.y),
					ImGui::ColorConvertFloat4ToU32(top_color),
					ImGui::ColorConvertFloat4ToU32(top_color),
					ImGui::ColorConvertFloat4ToU32(low),
					ImGui::ColorConvertFloat4ToU32(low)
				);
			} else {
				const auto& high_color = is_teammate ? g_cfg->visuals.m_teammate_health_high_color : g_cfg->visuals.m_health_high_color;
				const auto bar_color = ImGui::ColorConvertFloat4ToU32(high_color);
				draw_list->AddRectFilled(ImVec2(bar_x, bar_y), ImVec2(bar_x + 2.0f, box_max.y), bar_color);
			}

		if (show_text && health < 100) {
			char buf[16];
			snprintf(buf, sizeof(buf), "%d", health);
			const auto text_size = calc_small_text_size(buf);
			const auto text_x = floorf(bar_x - text_size.x * 0.5f + 1.0f);
			const auto text_y = floorf(bar_y - text_size.y - 1.0f);
			draw_small_text(draw_list, ImVec2(text_x, text_y), IM_COL32(255, 255, 255, 255), buf);
		}
	} else if (show_text && health < 100) {
		char buf[16];
		snprintf(buf, sizeof(buf), "%d", health);
		const auto text_size = calc_small_text_size(buf);
		const auto text_x = floorf(box_min.x - 5.0f - text_size.x - 2.0f);
		const auto text_y = floorf(box_min.y - 2.0f);
		draw_small_text(draw_list, ImVec2(text_x, text_y), IM_COL32(255, 255, 255, 255), buf);
	}
	}

	static bool get_bone_position(c_cs_player_pawn* pawn, int bone, vec3_t& out) {
		if (!pawn || bone < 0)
			return false;

		auto* scene_node = pawn->m_scene_node();
		if (!scene_node)
			return false;

		const auto node = reinterpret_cast<std::uintptr_t>(scene_node);
		const auto bone_array = read<std::uintptr_t>(
			node + cs2::verified::ESP::CSkeletonInstance__m_modelState + 0x80
		);
		if (!bone_array)
			return false;

		const auto bone_data = read<c_bone_data>(bone_array + sizeof(c_bone_data) * bone);
		if (!bone_data.m_pos.is_valid() || bone_data.m_pos.is_zero())
			return false;

		out = bone_data.m_pos;
		return true;
	}

	static void draw_skeleton(ImDrawList* draw_list, c_cs_player_pawn* pawn, const ImVec2& box_min, const ImVec2& box_max, bool is_teammate = false) {
		if (is_teammate) {
			if (!g_cfg->visuals.m_teammate_skeleton || !pawn)
				return;
		} else {
			if (!g_cfg->visuals.m_skeleton || !pawn)
				return;
		}

		__try {
			auto find_bone = [&](const char* name) -> int {
				if (!name || !name[0])
					return -1;

				__try {
					const int index = pawn->get_bone_index(name);
					return index >= 0 && index < 128 ? index : -1;
				}
				__except (EXCEPTION_EXECUTE_HANDLER) {
					return -1;
				}
			};

			const int pelvis = find_bone("pelvis");
			const int spine0 = find_bone("spine_0");
			const int spine1 = find_bone("spine_1");
			const int spine2 = find_bone("spine_2");
			const int spine3 = find_bone("spine_3");
			const int neck = find_bone("neck_0");
			const int head = find_bone("head_0");
			const int l_upper_arm = find_bone("arm_upper_L");
			const int l_lower_arm = find_bone("arm_lower_L");
			const int l_hand = find_bone("hand_L");
			const int r_upper_arm = find_bone("arm_upper_R");
			const int r_lower_arm = find_bone("arm_lower_R");
			const int r_hand = find_bone("hand_R");
			const int l_upper_leg = find_bone("leg_upper_L");
			const int l_lower_leg = find_bone("leg_lower_L");
			const int l_ankle = find_bone("ankle_L");
			const int r_upper_leg = find_bone("leg_upper_R");
			const int r_lower_leg = find_bone("leg_lower_R");
			const int r_ankle = find_bone("ankle_R");

			const std::pair<int, int> bone_pairs[] = {
				{ head, neck },
				{ neck, spine3 },
				{ spine3, spine2 },
				{ spine2, spine1 },
				{ spine1, spine0 },
				{ spine0, pelvis },
				{ spine3, l_upper_arm },
				{ l_upper_arm, l_lower_arm },
				{ l_lower_arm, l_hand },
				{ spine3, r_upper_arm },
				{ r_upper_arm, r_lower_arm },
				{ r_lower_arm, r_hand },
				{ pelvis, l_upper_leg },
				{ l_upper_leg, l_lower_leg },
				{ l_lower_leg, l_ankle },
				{ pelvis, r_upper_leg },
				{ r_upper_leg, r_lower_leg },
				{ r_lower_leg, r_ankle }
			};

			const auto& skeleton_color_vec = is_teammate ? g_cfg->visuals.m_teammate_skeleton_color : g_cfg->visuals.m_skeleton_color;
			const ImU32 color = ImGui::ColorConvertFloat4ToU32(skeleton_color_vec);
			const float box_h = (std::max)(1.0f, box_max.y - box_min.y);
			const float max_segment_len = box_h * 0.48f;
			const float min_x = box_min.x - box_h * 0.35f;
			const float max_x = box_max.x + box_h * 0.35f;
			const float min_y = box_min.y - box_h * 0.08f;
			const float max_y = box_max.y + box_h * 0.08f;

			for (const auto& pair : bone_pairs) {
				if (pair.first < 0 || pair.second < 0)
					continue;

				vec3_t a_world, b_world;
				if (!get_bone_position(pawn, pair.first, a_world) || !get_bone_position(pawn, pair.second, b_world))
					continue;

				ImVec2 a_screen, b_screen;
				if (!world_to_screen(a_world, a_screen) || !world_to_screen(b_world, b_screen))
					continue;

				if (a_screen.x < min_x || a_screen.x > max_x || a_screen.y < min_y || a_screen.y > max_y ||
					b_screen.x < min_x || b_screen.x > max_x || b_screen.y < min_y || b_screen.y > max_y)
					continue;

				const float dx = a_screen.x - b_screen.x;
				const float dy = a_screen.y - b_screen.y;
				if ((dx * dx + dy * dy) > max_segment_len * max_segment_len)
					continue;

				draw_list->AddLine(a_screen, b_screen, color, 1.0f);
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	static void draw_name(ImDrawList* draw_list, const char* name, const ImVec2& box_min, const ImVec2& box_max) {
		if (!g_cfg->visuals.m_name || !name || name[0] == '\0')
			return;
		auto player_name = to_lower_case(std::string(name));
		if (player_name.empty())
			return;
		auto* font = ImGui::GetFont();
		const auto font_size = ImGui::GetFontSize();
		const auto text_size = font->CalcTextSizeA(font_size, FLT_MAX, 0.0f, player_name.c_str());
		const auto x = floorf(box_min.x + (box_max.x - box_min.x - text_size.x) * 0.5f);
		const auto y = floorf(box_min.y - text_size.y - 2.0f);
		ImU32 name_color = ImGui::ColorConvertFloat4ToU32(g_cfg->visuals.m_name_color);
		draw_list->AddText(font, font_size, ImVec2(x + 1.0f, y + 1.0f), IM_COL32(0, 0, 0, 255), player_name.c_str());
		draw_list->AddText(font, font_size, ImVec2(x, y), name_color, player_name.c_str());
	}

	static float draw_weapon(ImDrawList* draw_list, c_cs_player_pawn* pawn, const ImVec2& box_min, const ImVec2& box_max, float offset_y, bool is_teammate = false) {
		if (is_teammate) {
			if (!g_cfg->visuals.m_teammate_weapon || !pawn)
				return 0.0f;
		} else {
			if (!g_cfg->visuals.m_weapon || !pawn)
				return 0.0f;
		}

		auto* weapon = pawn->get_active_weapon();
		const auto weapon_key = get_weapon_key(weapon);
		if (weapon_key.empty())
			return 0.0f;

		int weapon_type = is_teammate ? g_cfg->visuals.m_teammate_weapon_type : g_cfg->visuals.m_weapon_type;
		const auto& weapon_color_vec = is_teammate ? g_cfg->visuals.m_teammate_weapon_color : g_cfg->visuals.m_weapon_color;
		const ImU32 weapon_color = ImGui::ColorConvertFloat4ToU32(weapon_color_vec);
		const auto x = box_min.x + (box_max.x - box_min.x) * 0.5f;
		auto y = box_max.y + offset_y;
		float total_height = 0.0f;

		bool show_text = (weapon_type & (1 << 0)) != 0;
		bool show_icon = (weapon_type & (1 << 1)) != 0;

		if (show_icon) {
			if (auto* icon = get_weapon_icon(weapon_key)) {
				if (auto* icon_font = g_menu->get_weapon_icon_font()) {
					draw_centered_icon(draw_list, icon_font, icon_font->FontSize, ImVec2(x, y), weapon_color, icon);
					total_height += icon_font->FontSize;
					if (show_text) {
						y += icon_font->FontSize + 2.0f;
						total_height += 2.0f;
					}
				}
			}
		}

		if (show_text) {
			const std::string text = to_lower_case(get_weapon_text(weapon_key));
			const auto text_size = calc_pixel_text_size(text.c_str());
			const auto text_x = floorf(x - text_size.x * 0.5f);
			draw_small_text(draw_list, ImVec2(text_x, y), weapon_color, text.c_str());
			total_height += get_pixel_font_height();
		}

		return total_height;
	}

	static void draw_corners(ImDrawList* dl, const ImVec2& box_min, const ImVec2& box_max, const ImU32 color, const ImU32 outline_color, float corner_length) {
		const float x1 = box_min.x;
		const float y1 = box_min.y;
		const float x2 = box_max.x;
		const float y2 = box_max.y;
		const float width = (std::max)(1.0f, x2 - x1);
		const float height = (std::max)(1.0f, y2 - y1);
		const float t = std::clamp(corner_length, 0.005f, 0.5f);
		if (t >= 0.5f) {
			dl->AddRect(ImVec2(x1 - 1.0f, y1 - 1.0f), ImVec2(x2 + 1.0f, y2 + 1.0f), outline_color);
			dl->AddRect(ImVec2(x1 + 1.0f, y1 + 1.0f), ImVec2(x2 - 1.0f, y2 - 1.0f), outline_color);
			dl->AddRect(ImVec2(x1, y1), ImVec2(x2, y2), color);
			return;
		}

		const float len = (std::min)(width, height) * t;
		const float h_len = len;
		const float v_len = len;

		dl->AddRectFilled(ImVec2(x1 - 1.0f, y1 - 1.0f), ImVec2(x1 + 1.0f + h_len, y1), outline_color);
		dl->AddRectFilled(ImVec2(x1 - 1.0f, y1 - 1.0f), ImVec2(x1, y1 + 1.0f + v_len), outline_color);
		dl->AddRectFilled(ImVec2(x1 + 1.0f, y1 + 1.0f), ImVec2(x1 + 1.0f + h_len, y1 + 2.0f), outline_color);
		dl->AddRectFilled(ImVec2(x1 + 1.0f, y1 + 1.0f), ImVec2(x1 + 2.0f, y1 + 1.0f + v_len), outline_color);
		dl->AddRectFilled(ImVec2(x1, y1), ImVec2(x1 + 1.0f + h_len, y1 + 1.0f), color);
		dl->AddRectFilled(ImVec2(x1, y1), ImVec2(x1 + 1.0f, y1 + 1.0f + v_len), color);

		dl->AddRectFilled(ImVec2(x2 - h_len, y1 - 1.0f), ImVec2(x2 + 2.0f, y1), outline_color);
		dl->AddRectFilled(ImVec2(x2 + 1.0f, y1 - 1.0f), ImVec2(x2 + 2.0f, y1 + 1.0f + v_len), outline_color);
		dl->AddRectFilled(ImVec2(x2 - h_len, y1 + 1.0f), ImVec2(x2, y1 + 2.0f), outline_color);
		dl->AddRectFilled(ImVec2(x2 - 1.0f, y1 + 1.0f), ImVec2(x2, y1 + 1.0f + v_len), outline_color);
		dl->AddRectFilled(ImVec2(x2 - h_len, y1), ImVec2(x2 + 1.0f, y1 + 1.0f), color);
		dl->AddRectFilled(ImVec2(x2, y1), ImVec2(x2 + 1.0f, y1 + 1.0f + v_len), color);

		dl->AddRectFilled(ImVec2(x1 - 1.0f, y2 + 1.0f), ImVec2(x1 + 1.0f + h_len, y2 + 2.0f), outline_color);
		dl->AddRectFilled(ImVec2(x1 - 1.0f, y2 - v_len), ImVec2(x1, y2 + 2.0f), outline_color);
		dl->AddRectFilled(ImVec2(x1 + 1.0f, y2 - 1.0f), ImVec2(x1 + 1.0f + h_len, y2), outline_color);
		dl->AddRectFilled(ImVec2(x1 + 1.0f, y2 - v_len), ImVec2(x1 + 2.0f, y2), outline_color);
		dl->AddRectFilled(ImVec2(x1, y2), ImVec2(x1 + 1.0f + h_len, y2 + 1.0f), color);
		dl->AddRectFilled(ImVec2(x1, y2 - v_len), ImVec2(x1 + 1.0f, y2 + 1.0f), color);

		dl->AddRectFilled(ImVec2(x2 - h_len, y2 + 1.0f), ImVec2(x2 + 2.0f, y2 + 2.0f), outline_color);
		dl->AddRectFilled(ImVec2(x2 + 1.0f, y2 - v_len), ImVec2(x2 + 2.0f, y2 + 2.0f), outline_color);
		dl->AddRectFilled(ImVec2(x2 - h_len, y2 - 1.0f), ImVec2(x2, y2), outline_color);
		dl->AddRectFilled(ImVec2(x2 - 1.0f, y2 - v_len), ImVec2(x2, y2), outline_color);
		dl->AddRectFilled(ImVec2(x2 - h_len, y2), ImVec2(x2 + 1.0f, y2 + 1.0f), color);
		dl->AddRectFilled(ImVec2(x2, y2 - v_len), ImVec2(x2 + 1.0f, y2 + 1.0f), color);
	}

	static void draw_box(ImDrawList* draw_list, const ImVec2& box_min, const ImVec2& box_max, bool is_teammate = false) {
		if (is_teammate) {
			if (!g_cfg->visuals.m_teammate_box)
				return;
		} else {
			if (!g_cfg->visuals.m_box)
				return;
		}
		const auto& box_color_vec = is_teammate ? g_cfg->visuals.m_teammate_box_color : g_cfg->visuals.m_box_color;
		ImU32 box_color = ImGui::ColorConvertFloat4ToU32(box_color_vec);
		ImU32 outline = IM_COL32(0, 0, 0, 180);
		const float corner_length = is_teammate ? g_cfg->visuals.m_teammate_corner_length : g_cfg->visuals.m_corner_length;
		draw_corners(draw_list, box_min, box_max, box_color, outline, std::clamp(corner_length, 0.005f, 0.5f));
	}

	static ImU32 glow_color(float alpha_scale) {
		const auto& color = g_cfg->visuals.m_enemy_glow_color;
		const int r = static_cast<int>(std::clamp(color.x, 0.0f, 1.0f) * 255.0f);
		const int g = static_cast<int>(std::clamp(color.y, 0.0f, 1.0f) * 255.0f);
		const int b = static_cast<int>(std::clamp(color.z, 0.0f, 1.0f) * 255.0f);
		const int a = static_cast<int>(std::clamp(color.w * alpha_scale, 0.0f, 1.0f) * 255.0f);
		return IM_COL32(r, g, b, a);
	}

	static float cross(const ImVec2& origin, const ImVec2& a, const ImVec2& b) {
		return (a.x - origin.x) * (b.y - origin.y) - (a.y - origin.y) * (b.x - origin.x);
	}

	static std::vector<ImVec2> convex_hull(std::vector<ImVec2> points) {
		if (points.size() < 3)
			return {};

		std::sort(points.begin(), points.end(), [](const ImVec2& a, const ImVec2& b) {
			return a.x < b.x || (a.x == b.x && a.y < b.y);
		});

		std::vector<ImVec2> hull;
		hull.reserve(points.size() * 2);

		for (const auto& point : points) {
			while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), point) <= 0.0f)
				hull.pop_back();
			hull.push_back(point);
		}

		const auto lower_size = hull.size();
		for (int i = static_cast<int>(points.size()) - 2; i >= 0; --i) {
			const auto& point = points[i];
			while (hull.size() > lower_size && cross(hull[hull.size() - 2], hull.back(), point) <= 0.0f)
				hull.pop_back();
			hull.push_back(point);
		}

		if (!hull.empty())
			hull.pop_back();

		return hull;
	}

	static void draw_scaled_polyline(ImDrawList* draw_list, const std::vector<ImVec2>& hull, const ImVec2& center, float scale, ImU32 color, float thickness) {
		if (hull.size() < 3)
			return;

		std::vector<ImVec2> scaled;
		scaled.reserve(hull.size());

		for (const auto& point : hull) {
			scaled.emplace_back(
				center.x + (point.x - center.x) * scale,
				center.y + (point.y - center.y) * scale
			);
		}

		draw_list->AddPolyline(scaled.data(), static_cast<int>(scaled.size()), color, ImDrawFlags_Closed, thickness);
	}

	static void draw_enemy_glow(ImDrawList* draw_list, c_cs_player_pawn* pawn, const ImVec2& box_min, const ImVec2& box_max) {
		if (!g_cfg->visuals.m_enemy_glow || !pawn)
			return;

		auto find_bone = [&](const char* name) -> int {
			if (!name || !name[0])
				return -1;

			__try {
				const int index = pawn->get_bone_index(name);
				return index >= 0 && index < 128 ? index : -1;
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				return -1;
			}
		};

			const float box_h = (std::max)(1.0f, box_max.y - box_min.y);
			const float torso = std::clamp(box_h * 0.065f, 5.0f, 18.0f);
			const float limb = std::clamp(box_h * 0.045f, 3.5f, 12.0f);
			const float head_radius = std::clamp(box_h * 0.070f, 5.0f, 18.0f);
			std::vector<ImVec2> points;
			points.reserve(80);

			auto add_bone_shape = [&](const char* name, float radius_x, float radius_y) {
				const int bone = find_bone(name);
				if (bone < 0)
					return;

				vec3_t world;
				if (!get_bone_position(pawn, bone, world))
					return;

				ImVec2 screen;
				if (!world_to_screen(world, screen))
					return;

				points.emplace_back(screen.x - radius_x, screen.y);
				points.emplace_back(screen.x + radius_x, screen.y);
				points.emplace_back(screen.x, screen.y - radius_y);
				points.emplace_back(screen.x, screen.y + radius_y);
				points.emplace_back(screen.x - radius_x * 0.65f, screen.y - radius_y * 0.65f);
				points.emplace_back(screen.x + radius_x * 0.65f, screen.y - radius_y * 0.65f);
				points.emplace_back(screen.x - radius_x * 0.65f, screen.y + radius_y * 0.65f);
				points.emplace_back(screen.x + radius_x * 0.65f, screen.y + radius_y * 0.65f);
			};

			add_bone_shape("head_0", head_radius * 1.05f, head_radius * 1.20f);
			add_bone_shape("neck_0", torso * 0.85f, torso * 0.80f);
			add_bone_shape("spine_3", torso * 1.55f, torso);
			add_bone_shape("spine_2", torso * 1.45f, torso);
			add_bone_shape("spine_1", torso * 1.25f, torso);
			add_bone_shape("spine_0", torso * 1.05f, torso);
			add_bone_shape("pelvis", torso * 1.45f, torso * 0.95f);
			add_bone_shape("arm_upper_L", limb, limb);
			add_bone_shape("arm_lower_L", limb, limb);
			add_bone_shape("hand_L", limb * 1.15f, limb * 1.10f);
			add_bone_shape("arm_upper_R", limb, limb);
			add_bone_shape("arm_lower_R", limb, limb);
			add_bone_shape("hand_R", limb * 1.15f, limb * 1.10f);
			add_bone_shape("leg_upper_L", limb * 1.25f, limb * 1.15f);
			add_bone_shape("leg_lower_L", limb, limb * 1.20f);
			add_bone_shape("ankle_L", limb * 1.15f, limb * 0.90f);
			add_bone_shape("leg_upper_R", limb * 1.25f, limb * 1.15f);
			add_bone_shape("leg_lower_R", limb, limb * 1.20f);
			add_bone_shape("ankle_R", limb * 1.15f, limb * 0.90f);

			auto hull = convex_hull(points);
			if (hull.size() < 3)
				return;

			ImVec2 center(0.0f, 0.0f);
			for (const auto& point : hull) {
				center.x += point.x;
				center.y += point.y;
			}
			center.x /= static_cast<float>(hull.size());
			center.y /= static_cast<float>(hull.size());

			std::vector<ImVec2> fill_poly;
			fill_poly.reserve(hull.size());
			for (const auto& point : hull) {
				fill_poly.emplace_back(
					center.x + (point.x - center.x) * 1.015f,
					center.y + (point.y - center.y) * 1.015f
				);
			}

			draw_list->AddConvexPolyFilled(fill_poly.data(), static_cast<int>(fill_poly.size()), glow_color(0.055f));
			draw_scaled_polyline(draw_list, hull, center, 1.130f, glow_color(0.055f), 12.0f);
		draw_scaled_polyline(draw_list, hull, center, 1.090f, glow_color(0.090f), 8.0f);
		draw_scaled_polyline(draw_list, hull, center, 1.055f, glow_color(0.150f), 5.0f);
		draw_scaled_polyline(draw_list, hull, center, 1.020f, glow_color(0.270f), 2.0f);
	}

	union cvar_value_t {
		bool b_value;
		float fl_value;
		int i_value;
		const char* sz_value;
	};

	struct convar_t {
		const char* name;
		cvar_value_t* default_value;
		std::uint8_t pad_0010[0x10];
		const char* description;
		std::uint32_t type;
		std::uint32_t registered;
		std::uint32_t flags;
		std::uint8_t pad_0034[0x24];
		cvar_value_t value;
	};

	static void* engine_cvar() {
		static void* cvar = []() -> void* {
			HMODULE tier0 = GetModuleHandleA("tier0.dll");
			if (!tier0)
				return nullptr;

			using create_interface_t = void* (*)(const char*, int*);
			auto create_interface = reinterpret_cast<create_interface_t>(GetProcAddress(tier0, "CreateInterface"));
			if (!create_interface)
				return nullptr;

			return create_interface("VEngineCvar007", nullptr);
		}();

		return cvar;
	}

	static convar_t* find_cvar(const char* name) {
		if (!name)
			return nullptr;

		using get_first_iterator_t = void(__fastcall*)(void*, std::uint64_t*);
		using get_next_iterator_t = void(__fastcall*)(void*, std::uint64_t*, std::uint64_t);
		using find_by_index_t = convar_t* (__fastcall*)(void*, std::uint64_t);

		static auto get_first_iterator = reinterpret_cast<get_first_iterator_t>(
			g_opcodes->scan("tier0.dll", "48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC ? 48 8B F2 48 8D B9")
		);
		static auto get_next_iterator = reinterpret_cast<get_next_iterator_t>(
			g_opcodes->scan("tier0.dll", "40 53 55 56 41 56 41 57 48 83 EC ? 49 8B D8 48 8D B1 ? ? ? ? 4C 8B F2 48 8B E9 FF 15 ? ? ? ? 8B D0 39 46 ? 75 ? 66 FF 46 ? EB ? 8B 06 90 85 C0 75 ? B9 ? ? ? ? F0 0F B1 0E 75 ? 66 C7 46 ? ? ? 89 56 ? EB ? 48 8B CE E8 ? ? ? ? 41 BF ? ? ? ? 48 89 7C 24 ? 4C 89 6C 24 ? 66 41 3B DF 74 ? 41 BD ? ? ? ? 66 44 85 6D")
		);
		static auto find_by_index = reinterpret_cast<find_by_index_t>(
			g_opcodes->scan("tier0.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B DA 48 8D B9 ? ? ? ? 48 8B F1 FF 15 ? ? ? ? 8B D0 39 47 ? 75 ? 66 FF 47 ? EB ? 8B 07 90 85 C0 75 ? B9 ? ? ? ? F0 0F B1 0F 75 ? 66 C7 47 ? ? ? 89 57 ? EB ? 48 8B CF E8 ? ? ? ? BA")
		);

		auto* cvar = engine_cvar();
		if (!cvar || !get_first_iterator || !get_next_iterator || !find_by_index)
			return nullptr;

		std::uint64_t index = 0;
		get_first_iterator(cvar, &index);

		while (index != 0xFFFFFFFFull) {
			auto* var = find_by_index(cvar, index);
			if (var && var->name && std::strcmp(var->name, name) == 0)
				return var;

			get_next_iterator(cvar, &index, index);
		}

		return nullptr;
	}

	static void set_cvar_float(const char* name, float value) {
		static convar_t* sv_grenade_trajectory_prac_trailtime = nullptr;

		convar_t** target = nullptr;
		if (std::strcmp(name, "sv_grenade_trajectory_prac_trailtime") == 0)
			target = &sv_grenade_trajectory_prac_trailtime;

		if (!target)
			return;

		if (!*target)
			*target = find_cvar(name);

		if (!*target)
			return;

		__try {
			(*target)->value.fl_value = value;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	static void apply_grenade_trails() {
		set_cvar_float("sv_grenade_trajectory_prac_trailtime", g_cfg->visuals.m_grenade_trails ? 5.0f : 0.0f);
	}

}

void teammate_esp::draw() {
	if (!g_interfaces || !g_interfaces->m_entity_system || !g_cfg)
		return;

	auto& t = g_cfg->visuals;
	const bool draw_teammate_esp =
		t.m_teammate_box || t.m_teammate_health_bar || t.m_teammate_skeleton ||
		t.m_teammate_name || t.m_teammate_weapon;

	if (!draw_teammate_esp)
		return;

	auto* local_controller = reinterpret_cast<c_cs_player_controller*>(
		g_interfaces->m_entity_system->get_local_controller()
	);
	if (!local_controller)
		return;

	const auto local_pawn_handle = local_controller->m_pawn();
	if (!local_pawn_handle.is_valid())
		return;

	auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(
		g_interfaces->m_entity_system->get_base_entity(local_pawn_handle.get_entry_index())
	);
	if (!local_pawn)
		return;

	const auto draw_list = ImGui::GetBackgroundDrawList();
	const auto local_team = local_pawn->m_team_num();

	vec3_t local_origin{};
	const auto local_scene_node = local_pawn->m_scene_node();
	if (local_scene_node) {
		local_origin = local_scene_node->m_abs_origin();
	}
	if (!local_origin.is_valid())
		local_origin = local_pawn->get_eye_pos();

	__try {
		for (int i = 1; i <= 64; ++i) {
			__try {
				auto* entity = get_base_entity_safe(i);
				if (!entity)
					continue;

				auto* identity = entity->m_entity();
				if (!is_valid_identity(identity))
					continue;

				if (!entity->is_player_controller())
					continue;

				auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
				if (controller == local_controller)
					continue;

				const auto pawn_handle = controller->m_pawn();
				if (!pawn_handle.is_valid())
					continue;

				auto* pawn = reinterpret_cast<c_cs_player_pawn*>(
					get_base_entity_safe(pawn_handle.get_entry_index())
				);
				if (!pawn || pawn == local_pawn)
					continue;

				auto* pawn_identity = pawn->m_entity();
				if (!is_valid_identity(pawn_identity))
					continue;

				const auto health = pawn->m_health();
				if (health <= 0)
					continue;

				if (pawn->m_team_num() != local_team)
					continue;

				static float health_anim[65] = { 0 };
				auto& anim_hp = health_anim[i];
				const float target_hp = static_cast<float>(health);
				if (anim_hp <= 0.0f || target_hp > anim_hp)
					anim_hp = target_hp;
				else
					anim_hp += (target_hp - anim_hp) * 0.1f;

				const auto scene_node = pawn->m_scene_node();
				const auto collision = pawn->m_collision();
				if (!scene_node || !collision)
					continue;

				const auto& origin = scene_node->m_abs_origin();

				const auto height = collision->m_maxs().z - collision->m_mins().z;
				auto top_world = origin;
				top_world.z += height;

				ImVec2 screen_top, screen_bottom;
				if (!world_to_screen(top_world, screen_top) || !world_to_screen(origin, screen_bottom))
					continue;

				const ImVec2 display_size = ImGui::GetIO().DisplaySize;
				if (screen_top.x < -100.0f || screen_top.x > display_size.x + 100.0f ||
				    screen_top.y < -100.0f || screen_top.y > display_size.y + 100.0f ||
				    screen_bottom.x < -100.0f || screen_bottom.x > display_size.x + 100.0f ||
				    screen_bottom.y < -100.0f || screen_bottom.y > display_size.y + 100.0f)
					continue;

				const auto box_height = screen_bottom.y - screen_top.y;
				const auto box_width = box_height * 0.5f;
				const auto box_min = ImVec2(floorf(screen_top.x - box_width * 0.5f), floorf(screen_top.y));
				const auto box_max = ImVec2(floorf(box_min.x + box_width), floorf(box_min.y + box_height));

				if (draw_teammate_esp) {
					if (t.m_teammate_box)
						draw_box(draw_list, box_min, box_max, true);
					if (t.m_teammate_health_bar)
						draw_health_bar(draw_list, health, anim_hp, box_min, box_max, true);
					if (t.m_teammate_skeleton)
						draw_skeleton(draw_list, pawn, box_min, box_max, true);
					if (t.m_teammate_name)
						draw_name(draw_list, controller->m_player_name(), box_min, box_max);

					float offset_y = 2.0f;
					if (t.m_teammate_weapon)
						draw_weapon(draw_list, pawn, box_min, box_max, offset_y, true);
				}
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				continue;
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return;
	}
}
