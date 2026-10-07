#pragma once
#pragma warning(disable : 4324)

// Thin wrapper around the game's client-side ray trace. The struct layouts and
// signature scans are lifted verbatim from the triggerbot's original local
// `vis_trace` helper so behaviour is identical; they are shared here so other
// features (e.g. bhop landing prediction) can trace the world too.
//
// IMPORTANT: the struct layouts below are alignment-sensitive and were reversed
// against a specific client.dll build. Do not reorder or repad without
// re-verifying against the game.

#include "../../sdk/typedefs/vec_t.hpp"
#include "../../utils/utils.hpp"

#include <Windows.h>
#include <cstdint>

namespace world_trace {

	// Standard CS2 visibility/solid content mask (CONTENTS_SOLID | ...). Solid
	// world geometry -- walls and floors -- is included, which is all the
	// callers here need.
	constexpr uint64_t MASK_SOLID = 0x2014003;

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

	inline fns_t& get() {
		static fns_t f;
		if (f.tried) return f;
		f.tried = true;
		f.init_data   = reinterpret_cast<fn_init_data>(
			g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 79 ? 33 F6 C7 47"));
		f.init_info   = reinterpret_cast<fn_init_info>(
			g_opcodes->scan("client.dll", "40 55 41 55 41 57 48 83 EC 30"));
		f.init_filter = reinterpret_cast<fn_init_filter>(
			g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24"));
		f.create      = reinterpret_cast<fn_create>(
			g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 50 F2 0F 10 02"));
		f.get_info    = reinterpret_cast<fn_get_info>(
			g_opcodes->scan("client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC 80 00 00 00 48 8B E9 0F 29 74 24 70 48 8B CA 49 8B F9 0F 28 F2 48 8B DA"));
		return f;
	}

	// Result of a raw trace: hit fraction plus the surface normal at the hit.
	// Defaults describe "nothing hit" (fraction 1.0, zero normal).
	struct trace_result_t {
		float  fraction = 1.0f;
		vec3_t normal{ 0.0f, 0.0f, 0.0f };
	};

	// Raw trace: cast a ray from `from` along `delta` (a full displacement
	// vector). Returns the hit fraction in [0,1] (1.0 means nothing was hit or
	// the trace functions could not be resolved) together with the hit normal.
	inline trace_result_t trace(const vec3_t& from, const vec3_t& delta, uintptr_t skip_pawn, uint64_t mask = MASK_SOLID) {
		trace_result_t result;

		auto& f = get();
		if (!f.init_data || !f.init_info || !f.init_filter || !f.create || !f.get_info)
			return result;

		__try {
			trace_data_t   td{};
			trace_filter_t filter{};
			c_game_trace_t tr{};

			f.init_data(&td);
			f.init_filter(&filter, skip_pawn, mask, 4, 7);
			f.create(&td, from, delta, &filter, 4, true);
			f.init_info(&tr);

			if (td.mod_array.size > 0 && td.mod_array.data) {
				auto* entry = static_cast<char*>(td.mod_array.data);

				float start_frac = *reinterpret_cast<float*>(entry + 0);
				uint16_t surf_end = *reinterpret_cast<uint16_t*>(entry + 14);
				const uint16_t surf_idx = surf_end & 0x7FFF;
				if (surf_idx < 0x80) {
					f.get_info(&td, &tr, start_frac, &td.arr[surf_idx]);
					result.fraction = tr.fraction;
					result.normal = tr.normal;
				}
			}

			return result;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return trace_result_t{};
		}
	}

	// Convenience wrapper: same as `trace` but returns only the hit fraction.
	inline float trace_fraction(const vec3_t& from, const vec3_t& delta, uintptr_t skip_pawn, uint64_t mask = MASK_SOLID) {
		return trace(from, delta, skip_pawn, mask).fraction;
	}

	// Visibility helper (kept identical to the old triggerbot behaviour): the
	// path from `from` to `to` is considered clear when at least 94% of it is
	// unobstructed.
	inline bool is_visible(const vec3_t& from, const vec3_t& to, uintptr_t skip_pawn) {
		return trace_fraction(from, to - from, skip_pawn, MASK_SOLID) >= 0.94f;
	}

	// Straight-down distance from `feet` to the nearest solid floor, capped at
	// `max_dist`. Returns `max_dist` when no floor is found within range.
	inline float distance_to_ground(const vec3_t& feet, uintptr_t skip_pawn, float max_dist = 128.0f) {
		const vec3_t delta(0.0f, 0.0f, -max_dist);
		return trace_fraction(feet, delta, skip_pawn, MASK_SOLID) * max_dist;
	}

}
