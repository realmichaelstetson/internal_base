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
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>

namespace trace_ns {
	struct alignas(16) trace_data_t {
		char pad0[24];
		struct { char data[0x30]; } arr[0x80];
		char pad_post_arr[8];
		struct { int size; char pad4[4]; void* data; char pad16[8]; } mod_array;
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
		void* surface; void* hit_entity; void* hitbox_data;
		char pad1[0x10]; uint32_t contents; char pad2[0x4C];
		vec3_t start_pos; vec3_t end_pos; vec3_t normal; vec3_t pos;
		char pad3[4]; float fraction; char pad_tail[0x58];
	};
	using fn_init_data   = void(__fastcall*)(trace_data_t*);
	using fn_init_info   = void(__fastcall*)(c_game_trace_t*);
	using fn_init_filter = void*(__fastcall*)(trace_filter_t*, uintptr_t, uint64_t, int, int);
	using fn_create      = bool(__fastcall*)(trace_data_t*, vec3_t, vec3_t, trace_filter_t*, int, bool);
	using fn_get_info    = void(__fastcall*)(trace_data_t*, c_game_trace_t*, float, void*);
	struct fns_t {
		fn_init_data init_data = nullptr; fn_init_info init_info = nullptr;
		fn_init_filter init_filter = nullptr; fn_create create = nullptr;
		fn_get_info get_info = nullptr; bool tried = false;
	};
	fns_t& get() {
		static fns_t f;
		if (f.tried) return f;
		f.tried = true;
		f.init_data   = reinterpret_cast<fn_init_data>(g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 79 ? 33 F6 C7 47"));
		f.init_info   = reinterpret_cast<fn_init_info>(g_opcodes->scan("client.dll", "40 55 41 55 41 57 48 83 EC 30"));
		f.init_filter = reinterpret_cast<fn_init_filter>(g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24"));
		f.create      = reinterpret_cast<fn_create>(             // TraceCreate
			g_opcodes->scan("client.dll", "48 8B C4 56 57 41 56 41 57 48 83 EC ? 0F B7 F2 4D 8B F9 41 0F B7 F8 4C 8B F1"));
		f.get_info    = reinterpret_cast<fn_get_info>(            // TraceGetInfo
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
				if (surf_idx < 0x80) f.get_info(&td, &trace, start_frac, &td.arr[surf_idx]);
				else trace.fraction = 1.0f;
			} else { trace.fraction = 1.0f; }
			return trace.fraction >= 0.94f;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) { return true; }
	}
}

namespace {
	constexpr float k_pi = 3.14159265358979323846f;
	constexpr std::ptrdiff_t k_view_offset = 0xE70;

	constexpr std::ptrdiff_t k_player_pawn_handle = 0x90C;
	constexpr std::ptrdiff_t k_id_ent_index = cs2::verified::Triggerbot__Seeded_::C_CSPlayerPawn__m_iIDEntIndex;

	// Settings for the weapon group of the player's currently held weapon.
	// Set at the start of each aim run so the helper functions below read the
	// correct per-group values.
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

	vec3_t get_eye_position(c_cs_player_pawn* pawn);
	vec3_t get_bone_position_fast(c_cs_player_pawn* pawn, int bone);

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

	std::vector<int> selected_bones() {
		std::vector<int> bones;
		const int mask = active_aim_group().m_hitbox;

		if (mask == 0) {
			bones.push_back(6);
			return bones;
		}

		if (mask & (1 << 0)) bones.push_back(6);
		if (mask & (1 << 1)) bones.push_back(5);
		if (mask & (1 << 2)) bones.push_back(4);
		if (mask & (1 << 3)) bones.push_back(3);
		if (mask & (1 << 4)) bones.push_back(2);

		return bones;
	}

	int selected_bone() {

		const int mask = active_aim_group().m_hitbox;
		if (mask == 0 || (mask & (1 << 0))) return 6;
		if (mask & (1 << 1)) return 5;
		if (mask & (1 << 2)) return 4;
		if (mask & (1 << 3)) return 3;
		if (mask & (1 << 4)) return 2;
		return 6;
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

	bool aim_bind_active(const std::string& key, int mode, bool ui_fallback) {
		if (mode == static_cast<int>(UI::BindMode::Toggle))
			return ui_fallback;
		return is_button_down(key);
	}

	bool hold_bind_active(const std::string& key) {
		return is_button_down(key.empty() ? "ALT" : key);
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

	void set_attack2(c_user_cmd* cmd, bool down) {
		const auto base = client_base();
		if (base)
			write_ptr<std::uint32_t>(base + cs2_dumper::buttons::attack2, down ? 65537u : 256u);

		if (!cmd)
			return;

		cmd->m_button_state.set_button_state(
			IN_ATTACK2,
			down ? c_in_button_state::IN_BUTTON_UP_DOWN : c_in_button_state::IN_BUTTON_DOWN_UP
		);
	}

	void apply_auto_stop(c_user_cmd* cmd) {
		if (!cmd) return;
		if (auto* base = cmd->get_base_cmd()) {
			base->set_forwardmove(0.0f);
			base->set_leftmove(0.0f);
			base->set_upmove(0.0f);
		}
		cmd->m_button_state.set_button_state(IN_FORWARD, c_in_button_state::IN_BUTTON_UP);
		cmd->m_button_state.set_button_state(IN_BACK, c_in_button_state::IN_BUTTON_UP);
		cmd->m_button_state.set_button_state(IN_MOVELEFT, c_in_button_state::IN_BUTTON_UP);
		cmd->m_button_state.set_button_state(IN_MOVERIGHT, c_in_button_state::IN_BUTTON_UP);
	}

	bool is_scoped_weapon(c_base_player_weapon* weapon) {
		if (!weapon) return false;
		if (auto* data = weapon->get_weapon_data())
			return data->m_weapon_type() == WEAPONTYPE_SNIPER_RIFLE;
		return false;
	}

	bool is_weapon_scoped(c_base_player_weapon* weapon) {
		if (!weapon) return false;
		auto* cs_weapon = reinterpret_cast<c_cs_weapon_base*>(weapon);
		return cs_weapon->m_zoom_level() > 0;
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

	bool hitchance_pass(c_base_player_weapon* weapon) {
		if (!weapon || active_aim_group().m_hitchance <= 0.0f)
			return true;

		auto* cs_wpn = reinterpret_cast<c_cs_weapon_base*>(weapon);
		cs_wpn->update_accuracy_penalty();
		const float spread = cs_wpn->get_spread();
		const float inaccuracy = cs_wpn->get_inaccuracy();
		const float score = std::clamp(100.0f - (spread + inaccuracy) * 1600.0f, 0.0f, 100.0f);
		return score >= active_aim_group().m_hitchance;
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
				if (v < 1) v = 1;
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
				auto part_len = 64 - index;
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
			for (int i = 0; i < 16; ++i)
				w[i] = static_cast<std::uint32_t>(block[i * 4]) << 24 |
					static_cast<std::uint32_t>(block[i * 4 + 1]) << 16 |
					static_cast<std::uint32_t>(block[i * 4 + 2]) << 8 |
					static_cast<std::uint32_t>(block[i * 4 + 3]);
			for (int i = 16; i < 80; ++i)
				w[i] = rotl(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
			auto a = m_state[0], b = m_state[1], c = m_state[2], d = m_state[3], e = m_state[4];
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
				auto temp = rotl(a, 5) + f + e + k + w[i];
				e = d; d = c; c = rotl(b, 30); b = a; a = temp;
			}
			m_state[0] += a; m_state[1] += b; m_state[2] += c;
			m_state[3] += d; m_state[4] += e;
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

		if (item_def_idx == revolver_id && num_bullets == 1) {
			inac_r = 1.0f - (inac_r * inac_r);
		}
		else if (item_def_idx == negev_id && recoil_index < 3.0f) {
			auto v = inac_r; auto c = 3;
			do { --c; v *= v; } while (static_cast<float>(c) > recoil_index);
			inac_r = 1.0f - v;
		}

		inac_r *= inaccuracy;

		auto spr_r = rng.random_float(0.0f, 1.0f);
		auto spr_a = rng.random_float(0.0f, two_pi);

		if (item_def_idx == revolver_id && num_bullets == 1) {
			spr_r = 1.0f - (spr_r * spr_r);
		}
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

	bool normal_trigger_pass(c_cs_player_pawn* local, c_base_player_weapon* weapon,
		c_cs_player_pawn* target, i_csgo_input* input,
		const vec3_t& trigger_pos = {}, int trigger_bone = 6)
	{
		if (!local || !weapon || !target || !input)
			return false;

		if (!hitchance_pass(weapon))
			return false;

		const vec3_t eye = get_eye_position(local);
		vec3_t target_pos = trigger_pos;
		if (!target_pos.is_valid() || target_pos.is_zero())
			target_pos = get_bone_position_fast(target, selected_bone());
		if (!target_pos.is_valid() || target_pos.is_zero()) {
			if (auto* node = target->m_scene_node())
				target_pos = node->m_abs_origin() + vec3_t(0.0f, 0.0f, 64.0f);
		}
		if (!eye.is_valid() || !target_pos.is_valid() || eye.is_zero() || target_pos.is_zero())
			return false;

		const float distance = (target_pos - eye).length();
		if (distance <= 1.0f)
			return false;

		vec3_t view = input->get_view_angles();
		if (!view.is_valid())
			view = input->view_angles;
		if (!view.is_valid())
			view = read_ptr<vec3_t>(client_base() + cs2_dumper::offsets::client_dll::dwViewAngles);
		if (!view.is_valid())
			return false;
		view = normalize_angles(view);

		const auto punch_service = read_ptr<std::uintptr_t>(
			reinterpret_cast<std::uintptr_t>(local) + cs2::verified::Triggerbot__Seeded_::C_CSPlayerPawn__m_pAimPunchServices
		);

		vec3_t aim_punch{};
		if (punch_service)
			aim_punch = read_ptr<vec3_t>(punch_service + 0x40);

		const vec3_t view_with_punch = view + aim_punch;

		const float hit_radius_units = trigger_bone == 6 ? 4.5f : 7.5f;

		if (!trace_ns::is_visible(eye, target_pos, reinterpret_cast<std::uintptr_t>(local)))
			return false;

		const float hit_radius_deg = std::atan2f(hit_radius_units * 1.5f, distance) * (180.0f / k_pi);
		return angle_distance(view_with_punch, calc_angle(eye, target_pos)) <= hit_radius_deg;
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
		if (!pawn || bone < 0)
			return {};
		__try {
			auto* node = pawn->m_scene_node();
			if (!node) return {};
			const auto node_addr = reinterpret_cast<std::uintptr_t>(node);
			constexpr auto k_bone_array = 0x80;
			const auto bone_array = read_ptr<std::uintptr_t>(
				node_addr + cs2::verified::ESP::CSkeletonInstance__m_modelState + k_bone_array);
			if (bone_array) {
				struct bone_entry_t { float x, y, z, scale; float qx, qy, qz, qw; };
				const auto e = read_ptr<bone_entry_t>(bone_array + sizeof(bone_entry_t) * bone);
				vec3_t pos(e.x, e.y, e.z);
				if (pos.is_valid() && !pos.is_zero()) return pos;
			}
			return pawn->get_bone_position(bone);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) { return {}; }
	}

	vec3_t get_head_hitbox_center(c_cs_player_pawn* pawn) {
		if (!pawn)
			return {};
		__try {
			auto* node = pawn->m_scene_node();
			if (!node) return {};
			const auto node_addr = reinterpret_cast<std::uintptr_t>(node);
			constexpr auto model_state_offset = cs2::verified::ESP::CSkeletonInstance__m_modelState;
			constexpr auto k_bone_array = 0x80;
			const auto bone_array = read_ptr<std::uintptr_t>(
				node_addr + model_state_offset + k_bone_array);
			if (!bone_array)
				return get_bone_position_fast(pawn, 6);

			struct bone_entry_t { float x, y, z, scale; float qx, qy, qz, qw; };
			auto* head_bone = reinterpret_cast<bone_entry_t*>(bone_array + sizeof(bone_entry_t) * 6);
			vec3_t bone_pos(head_bone->x, head_bone->y, head_bone->z);
			if (!bone_pos.is_valid() || bone_pos.is_zero())
				return get_bone_position_fast(pawn, 6);

			auto* hitbox_set = pawn->get_hitbox_set(0);
			if (!hitbox_set)
				return bone_pos;
			auto* head_hitbox = hitbox_set->get_hitbox(HITBOX_HEAD);
			if (!head_hitbox)
				return bone_pos;

			vec3_t center_local = (head_hitbox->m_vec_min + head_hitbox->m_vec_max) * 0.5f;

			c_transform tf;
			tf.m_position = vec4_t(bone_pos.x, bone_pos.y, bone_pos.z, 0.0f);
			tf.m_rotation = vec4_t(head_bone->qx, head_bone->qy, head_bone->qz, head_bone->qw);
			matrix3x4_t mat;
			tf.to_matrix(mat);
			return mat.transform(center_local);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return get_bone_position_fast(pawn, 6);
		}
	}

	void set_cmd_angles(i_csgo_input* input, c_user_cmd* cmd, const vec3_t& angles, bool visible) {
		if (input) { vec3_t out = angles; input->set_view_angles(out); }
	}

	bool is_enemy_pawn(c_cs_player_pawn* local, c_cs_player_pawn* pawn) {
		return pawn && pawn != local && pawn->is_alive() && pawn->m_team_num() != local->m_team_num();
	}

	vec3_t g_smooth_last_delta{};
	bool g_smooth_initialized = false;

	bool has_visible_enemy_in_fov(c_cs_player_pawn* local, const vec3_t& view, float fov) {
		if (!local) return false;

		const vec3_t eye = get_eye_position(local);
		if (!eye.is_valid() || eye.is_zero()) return false;

		for (int i = 1; i <= 64; ++i) {
			__try {
				auto* entity = get_base_entity_safe(i);
				if (!entity || !entity->is_player_controller())
					continue;

				auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
				if (controller == g_ctx->m_local_controller)
					continue;

				auto* ent = pawn_from_controller(controller);
				if (!ent || !is_enemy_pawn(local, ent))
					continue;

				if (g_cfg->aim.m_visibility_check) {
					const vec3_t enemy_eye = get_eye_position(ent);
					if (!enemy_eye.is_valid() || enemy_eye.is_zero())
						continue;
					if (!trace_ns::is_visible(eye, enemy_eye, reinterpret_cast<uintptr_t>(local)))
						continue;
				}

				vec3_t target_pos = get_bone_position_fast(ent, 6);
				if (!target_pos.is_valid() || target_pos.is_zero()) {
					if (auto* node = ent->m_scene_node())
						target_pos = node->m_abs_origin() + vec3_t(0.0f, 0.0f, 64.0f);
				}
				if (!target_pos.is_valid() || target_pos.is_zero())
					continue;

				const float dist = angle_distance(view, calc_angle(eye, target_pos));
				if (dist <= fov)
					return true;
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {}
		}
		return false;
	}

}

void c_aim::run_aimbot(i_csgo_input* input, c_user_cmd* cmd, c_cs_player_pawn* local) {
	if (!local || !input || !cmd)
		return;

	const auto& group = resolve_aim_group(local);
	g_active_aim_group = &group;

	const bool aim_on = group.m_aimbot &&
		bind_active(g_cfg->aim.m_aimbot_key, g_cfg->aim.m_aimbot_mode, UI::IsBindActive("aimbot"));

	if (!aim_on)
		return;

	vec3_t eye = get_eye_position(local);
	if (!eye.is_valid() || eye.is_zero())
		return;

	vec3_t view = input->get_view_angles();
	if (!view.is_valid())
		view = input ? input->view_angles : vec3_t{};
	if (!view.is_valid())
		view = read_ptr<vec3_t>(client_base() + cs2_dumper::offsets::client_dll::dwViewAngles);
	view = normalize_angles(view);

	c_cs_player_pawn* best_target = nullptr;
	vec3_t best_angle;
	float best_fov = std::clamp(group.m_fov, 0.0f, 90.0f);

	const int hitbox_mask = group.m_hitbox;
	int target_bones[5];
	int bone_count = 0;

	if (hitbox_mask == 0) {
		target_bones[bone_count++] = 6;
	} else {
		if (hitbox_mask & (1 << 0)) target_bones[bone_count++] = 6;
		if (hitbox_mask & (1 << 1)) target_bones[bone_count++] = 5;
		if (hitbox_mask & (1 << 2)) target_bones[bone_count++] = 4;
		if (hitbox_mask & (1 << 3)) target_bones[bone_count++] = 3;
		if (hitbox_mask & (1 << 4)) target_bones[bone_count++] = 2;
	}

	for (int i = 1; i <= 64; ++i) {
		__try {
			auto* entity = get_base_entity_safe(i);
			if (!entity || !entity->is_player_controller())
				continue;

			auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
			if (controller == g_ctx->m_local_controller)
				continue;

			auto* ent = pawn_from_controller(controller);
			if (!ent || ent == local || !ent->is_alive())
				continue;
			if (ent->m_team_num() == local->m_team_num())
				continue;

			if (g_cfg->aim.m_visibility_check) {
				const vec3_t enemy_eye = get_eye_position(ent);
				if (!enemy_eye.is_valid() || enemy_eye.is_zero())
					continue;

				const bool is_visible = trace_ns::is_visible(eye, enemy_eye, reinterpret_cast<uintptr_t>(local));

				if (!is_visible)
					continue;
			}

			for (int b = 0; b < bone_count; ++b) {
				int bone_id = target_bones[b];
				vec3_t target_pos;
				if (bone_id == 6)
					target_pos = get_head_hitbox_center(ent);
				else
					target_pos = get_bone_position_fast(ent, bone_id);
				if (!target_pos.is_valid() || target_pos.is_zero()) {
					if (auto* node = ent->m_scene_node())
						target_pos = node->m_abs_origin() + vec3_t(0.0f, 0.0f, 64.0f);
				}
				if (!target_pos.is_valid() || target_pos.is_zero())
					continue;

				const bool is_visible = trace_ns::is_visible(eye, target_pos, reinterpret_cast<uintptr_t>(local));

				if (!is_visible)
					continue;

				vec3_t aim_angle = calc_angle(eye, target_pos);
				const float fov = angle_distance(view, aim_angle);
				if (fov <= best_fov) {
					best_fov = fov;
					best_angle = aim_angle;
					best_target = ent;
				}
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	if (!best_target)
		return;

	if (group.m_recoil_control) {
		const int shots = read_ptr<int>(
			reinterpret_cast<std::uintptr_t>(local) + cs2::verified::Aimbot::C_CSPlayerPawn__m_iShotsFired
		);
		if (shots > 1) {
			const auto punch_service = read_ptr<std::uintptr_t>(
				reinterpret_cast<std::uintptr_t>(local) + cs2::verified::Aimbot::C_CSPlayerPawn__m_pAimPunchServices
			);
			if (punch_service) {
				const vec3_t punch = read_ptr<vec3_t>(punch_service + 0x40);
				if (punch.is_valid()) {
					best_angle.x -= punch.x * 2.0f;
					best_angle.y -= punch.y * 2.0f;
				}
			}
		}
	}

	vec3_t out = best_angle;
	const float smooth = std::clamp(group.m_smooth, 0.0f, 100.0f);
	if (smooth > 0.0f) {
		vec3_t delta = normalize_angles(best_angle - view);
		const float delta_length = std::sqrt(delta.x * delta.x + delta.y * delta.y);

		const float smooth_factor = smooth / 100.0f;

		const float speed_factor = 0.9f - (smooth_factor * 0.8f);

		const float distance_factor = std::clamp(delta_length / 20.0f, 0.5f, 1.0f);

		const float final_factor = speed_factor * distance_factor;

		delta = delta * final_factor;
		out = normalize_angles(view + delta);

		g_smooth_last_delta = delta;
		g_smooth_initialized = true;
	} else {

		g_smooth_last_delta = {};
		g_smooth_initialized = false;
	}

	out = normalize_angles(out);

	write_ptr<vec3_t>(client_base() + cs2_dumper::offsets::client_dll::dwViewAngles, out);
	set_cmd_angles(input, cmd, out, true);
}

void c_aim::run(i_csgo_input* input, c_user_cmd* cmd) {
	if (!input || !g_cfg || !g_interfaces || !g_interfaces->m_entity_system)
		return;

	auto* local = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
	if (!local || local->m_health() <= 0) {
		if (m_trigger_was_down)
			set_attack(cmd, false);
		m_trigger_was_down = false;
		m_next_trigger_time = 0;
		m_trigger_target = 0;
		m_last_trigger_delay = -1.0f;
		m_auto_scope_active = false;
		return;
	}

	auto* weapon = local->get_active_weapon();
	const auto& group = resolve_aim_group(local);
	g_active_aim_group = &group;

	if (g_cfg->aim.m_auto_stop && cmd && weapon) {
		const bool weapon_ready = can_fire(local, weapon);
		const bool large_delay = active_aim_group().m_trigger_delay >= 30.0f;
		if (weapon_ready) {
			vec3_t view = input->get_view_angles();
			if (!view.is_valid())
				view = input ? input->view_angles : vec3_t{};
			if (!view.is_valid())
				view = read_ptr<vec3_t>(client_base() + cs2_dumper::offsets::client_dll::dwViewAngles);
			if (view.is_valid() && has_visible_enemy_in_fov(local, normalize_angles(view), std::clamp(group.m_fov, 0.0f, 90.0f)) && (large_delay || !hitchance_pass(weapon)))
				apply_auto_stop(cmd);
		}
	}

	if (g_cfg->aim.m_auto_scope && cmd && weapon && is_scoped_weapon(weapon)) {
		if (!is_weapon_scoped(weapon)) {
			vec3_t view = input->get_view_angles();
			if (!view.is_valid())
				view = input ? input->view_angles : vec3_t{};
			if (!view.is_valid())
				view = read_ptr<vec3_t>(client_base() + cs2_dumper::offsets::client_dll::dwViewAngles);
			if (view.is_valid() && has_visible_enemy_in_fov(local, normalize_angles(view), std::clamp(group.m_fov, 0.0f, 90.0f))) {
				set_attack2(cmd, true);
				m_auto_scope_active = true;
				return;
			}
		}
	} else {
		m_auto_scope_active = false;
	}

	run_aimbot(input, cmd, local);
	run_triggerbot(input, cmd, local);
}
