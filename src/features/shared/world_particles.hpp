#pragma once

// Thin wrapper around the game's native particle manager. The function
// prototypes and call sequence are lifted verbatim from a known-working
// implementation and were reversed against the same client.dll build the
// signature database targets, so behaviour is identical.
//
// Sequence:
//   mgr   = GetGameParticleManager();
//   index = CreateParticle(mgr, &index, path, PATTACH_WORLDORIGIN, 0,0,0,0);
//   SetParticleSettings(mgr, index, CP_POSITION, &vec3, 0);   // control point 0
//   DestroyParticle(mgr, index, true, true);
//
// IMPORTANT: the index is written to the out-parameter (arg 2), NOT the
// return value. Every call is wrapped in __try/__except so a stale signature
// degrades to a no-op instead of crashing the game.

#include "../../sdk/typedefs/vec_t.hpp"
#include "../../sdk/valve/signatures/signatures.hpp"

#include <Windows.h>
#include <cstdint>
#include <mutex>

namespace world_particles {

	// ParticleAttachment_t::PATTACH_WORLDORIGIN -- control point 0 is a raw
	// world-space position (which is exactly what we set below).
	constexpr int PATTACH_WORLDORIGIN = 8;
	// Control point index whose position we drive.
	constexpr int CP_POSITION = 0;

	// GetGameParticleManager resolves to the global that holds the manager pointer
	using create_fn  = int*  (__fastcall*)(void*, unsigned int*, const char*, int, std::int64_t, std::int64_t, std::int64_t, int);
	using setvec_fn  = bool  (__fastcall*)(void*, unsigned int, int, void*, int);
	using destroy_fn = void  (__fastcall*)(void*, unsigned int, bool, bool);

	struct fns_t {
		void** mgr_global = nullptr;
		create_fn  create  = nullptr;
		setvec_fn  setvec  = nullptr;
		destroy_fn destroy = nullptr;
	};

	inline fns_t& get() {
		static fns_t f;
		static std::once_flag flag;
		std::call_once(flag, [&]() {
			f.mgr_global = reinterpret_cast<void**>(SIG("GetGameParticleManager"));
			f.create  = reinterpret_cast<create_fn>(SIG("CreateParticle"));
			f.setvec  = reinterpret_cast<setvec_fn>(SIG("SetParticleSettings"));
			f.destroy = reinterpret_cast<destroy_fn>(SIG("DestroyParticle"));
		});
		return f;
	}

	inline bool available() {
		auto& f = get();
		return f.mgr_global && f.create && f.setvec && f.destroy;
	}

	inline void* manager() {
		auto& f = get();
		if (!f.mgr_global)
			return nullptr;
		__try {
			return *f.mgr_global;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	// Spawn a world-space particle. Returns the particle index (0 == failure).
	inline unsigned int spawn(const char* path) {
		auto& f = get();
		if (!path || !available())
			return 0;

		void* mgr = manager();
		if (!mgr)
			return 0;

		__try {
			unsigned int index = 0;
			f.create(mgr, &index, path, PATTACH_WORLDORIGIN, 0, 0, 0, 0);
			return index;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return 0;
		}
	}

	// Move a control point of an existing particle to a world position.
	inline void set_control(unsigned int index, int control_point, const vec3_t& pos) {
		auto& f = get();
		if (!index || !available())
			return;

		void* mgr = manager();
		if (!mgr)
			return;

		struct { float x, y, z; } data{ pos.x, pos.y, pos.z };
		__try {
			f.setvec(mgr, index, control_point, &data, 0);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	inline void destroy(unsigned int index) {
		auto& f = get();
		if (!index || !available())
			return;

		void* mgr = manager();
		if (!mgr)
			return;

		__try {
			f.destroy(mgr, index, true, true);
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {}
	}

	// Force the resource for `path` resident by spawning then immediately
	// destroying one instance. The very first spawn of an unloaded resource
	// triggers a synchronous manifest load (CResourceSystem::BlockUntilManifest-
	// Loaded); doing that inside a frame update is a FATAL engine error that
	// SEH cannot catch. So warm() MUST be called from a non-frame context --
	// level init -- where the block-load is legal. Afterwards the resource stays
	// cached and spawning it from the present hook no longer block-loads.
	// Returns true if the particle was created (i.e. the path is a valid,
	// now-resident resource).
	inline bool warm(const char* path) {
		const unsigned int index = spawn(path);
		if (!index)
			return false;
		destroy(index);
		return true;
	}

}
