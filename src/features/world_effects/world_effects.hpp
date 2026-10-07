#pragma once

#include "../../sdk/typedefs/vec_t.hpp"

#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_set>

// Persistent ambient world particles (snow / stars / ashes) that follow the
// local player around the map. Unlike hit effects, the particle is created once
// and kept alive; its position + density control points are refreshed every
// frame from the present hook.
//
// The particle resources are custom .vpcf_c files. They are embedded in the DLL
// and written into csgo/bin/ on level load, so the feature works on any machine
// without the user installing anything.
//
// Threading: update()/destroy run on the render thread (present). warm_tick()
// and on_level_change() run on the game thread (FrameStageNotify / LevelInit) and
// only touch the guarded warmed-set + flags. The reset flag is honoured inside
// update(), so the render thread is the only one that touches the live indices.
class c_world_effects {
public:
	// Per-frame driver, called from the present hook. Resolves the local origin,
	// (re)creates the effect on type change, and updates position + density.
	void update();

	// Called from LevelInit. Extracts the embedded particle resources to disk
	// (once) and re-arms warming for the new map. Safe to call unconditionally.
	void on_level_change();

	// Called every frame from FrameStageNotify (stage 7) -- a resource-safe context
	// OUTSIDE the render frame. Performs the one-time synchronous manifest load
	// (block-load) for the custom resources once the particle manager is ready,
	// retrying across frames. Doing this in the present hook is a fatal engine
	// error; LevelInit alone was too early to reliably warm. No-op once warmed.
	void warm_tick();

private:
	bool resolve_local_origin(vec3_t& out) const;
	void create_for_type(int type, const std::unordered_set<std::string>& warmed);
	void destroy_all();
	void ensure_assets();   // write embedded .vpcf_c into csgo/bin/ if missing

	unsigned int m_first = 0;          // primary particle index (render thread)
	unsigned int m_second = 0;         // secondary (ashes uses two) (render thread)
	int          m_type = -1;          // currently created type (render thread)
	int          m_next_retry_frame = 0;
	bool         m_initialized = false;

	std::mutex                      m_mutex;
	std::unordered_set<std::string> m_warmed;             // resident resources (guarded)
	bool                            m_warm_pending = false;    // (re)warm needed (guarded)
	int                             m_warm_attempts = 0;       // stage-7 warm passes this map (guarded)
	bool                            m_reset_requested = false; // map change (guarded)
	bool                            m_assets_written = false;  // extract-once guard (guarded)
};

inline const auto g_world_effects = std::make_unique<c_world_effects>();
