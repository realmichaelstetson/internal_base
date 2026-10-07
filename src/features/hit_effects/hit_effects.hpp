#pragma once

#include "../../sdk/typedefs/vec_t.hpp"

#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_set>
#include <vector>

// Spawns a native game particle at the world position of a hit / kill on an
// enemy. The game-event hook (any thread) only enqueues positions via queue();
// the actual particle API is driven from tick(), which runs on the render
// thread (the context where native particle creation is known to be safe).
class c_hit_effects {
public:
	// Called from the FireEventClientSide hook. Thread-safe; only records the
	// world position + kind, never touches the particle API.
	void queue(const vec3_t& pos, bool is_kill);

	// Called once per frame from the present hook. Drains the pending queue,
	// spawns particles, and reaps expired ones.
	void tick();

	// Destroy every live particle (round transitions / shutdown).
	void clear();

	// Warm ("precache") the non-blood preset paths so spawning them later from
	// the present hook never triggers a fatal in-frame manifest load. MUST be
	// called only from a non-frame context -- FrameStageNotify stage 7. Idempotent
	// and retry-safe: skips already-warmed paths and no-ops entirely once every
	// risky path is resident, so it is called every frame until the particle
	// manager is ready (it is not, immediately after LevelInit on the first map).
	void precache();

	// Re-arm warming for a new map (LevelInit). Clears the warmed set so the next
	// precache() passes re-warm the risky paths for the freshly loaded level.
	void rearm();

private:
	struct pending_t {
		vec3_t pos{};
		bool   is_kill = false;
	};

	struct active_t {
		unsigned int  index = 0;
		std::uint64_t expire_ms = 0;
	};

	std::mutex                      m_mutex;
	std::vector<pending_t>          m_pending;          // cross-thread inbox (guarded)
	bool                            m_clear_requested = false; // guarded; honoured in tick()
	std::unordered_set<std::string> m_warmed;           // precached risky paths (guarded)
	bool                            m_warm_done = false; // all risky paths warmed (guarded)
	std::vector<active_t>           m_active;           // render-thread only
};

inline const auto g_hit_effects = std::make_unique<c_hit_effects>();
