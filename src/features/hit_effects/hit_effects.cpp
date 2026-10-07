#include "hit_effects.hpp"

#include "../../config.hpp"
#include "../shared/world_particles.hpp"

#include <Windows.h>
#include <algorithm>

namespace {
	// How long a spawned effect is kept before we force-destroy it. Looping
	// particles (snow/ember style) never end on their own, so we cap them;
	// one-shot impacts finish well within this window anyway.
	constexpr std::uint64_t k_lifetime_ms = 2000;

	// Hard cap on queued spawns so a burst (e.g. spraying a wall of enemies)
	// can never grow the inbox without bound.
	constexpr std::size_t k_max_pending = 64;

	// Number of hit-effect presets (indices 0 .. k_type_count-1). Keep in sync with
	// pick_path() below and the menu dropdown (k_hit_effect_types in menu.cpp).
	constexpr int k_type_count = 6;

	// Particle resource paths per preset. Index maps to
	// g_cfg->visuals.m_hit_effects_type. The blood family (type 0) is always
	// resident in a live match, so it can be spawned without precaching. Every
	// other family must be warmed first (see precache()). All paths below are
	// confirmed-real stock CS2 resources (verified against the game VPK).
	const char* pick_path(int type, bool is_kill) {
		switch (type) {
		case 1: // sparks / impact
			return is_kill
				? "particles/explosions_fx/explosion_hegrenade.vpcf"
				: "particles/impact_fx/impacts_basic.vpcf";
		case 2: // explosion
			return is_kill
				? "particles/explosions_fx/explosion_c4_500.vpcf"
				: "particles/explosions_fx/explosion_hegrenade.vpcf";
		case 3: // taser / electric shock
			return is_kill
				? "particles/blood_impact/impact_taser_bodyfx.vpcf"
				: "particles/weapons/cs_weapon_fx/weapon_taser_sparks_impact.vpcf";
		case 4: // fire
			return is_kill
				? "particles/burning_fx/env_fire_medium.vpcf"
				: "particles/burning_fx/env_fire_small.vpcf";
		case 5: // fireworks
			return is_kill
				? "particles/inferno_fx/firework_crate_explosion_01.vpcf"
				: "particles/inferno_fx/firework_crate_ground_sparks_01.vpcf";
		case 0: // blood (default)
		default:
			return is_kill
				? "particles/blood_impact/blood_impact_headshot.vpcf"
				: "particles/blood_impact/blood_impact_basic.vpcf";
		}
	}

	// type 0 (blood) is always precached by the game; every other preset must be
	// warmed before it is safe to spawn inside the frame.
	inline bool is_risky(int type) {
		return type != 0;
	}
}

void c_hit_effects::queue(const vec3_t& pos, bool is_kill) {
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_pending.size() >= k_max_pending)
		return;
	m_pending.push_back({ pos, is_kill });
}

void c_hit_effects::tick() {
	if (!world_particles::available())
		return;

	// Pull everything the event thread handed us, plus any clear request, in a
	// single short critical section. All particle work then happens unlocked,
	// on this (render) thread only.
	std::vector<pending_t> pending;
	bool clear_requested = false;
	std::unordered_set<std::string> warmed;
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		pending.swap(m_pending);
		clear_requested = m_clear_requested;
		m_clear_requested = false;
		// Snapshot the warmed set only when there is work to spawn.
		if (!pending.empty())
			warmed = m_warmed;
	}

	if (clear_requested) {
		for (auto& a : m_active)
			world_particles::destroy(a.index);
		m_active.clear();
		// A pending burst captured before the round reset is now stale.
		pending.clear();
	}

	const std::uint64_t now = static_cast<std::uint64_t>(GetTickCount64());

	for (const auto& p : pending) {
		int type = 0;
		if (g_cfg)
			type = p.is_kill
				? std::clamp(g_cfg->visuals.m_hit_effects_kill_type, 0, k_type_count - 1)
				: std::clamp(g_cfg->visuals.m_hit_effects_type, 0, k_type_count - 1);
		const char* path = pick_path(type, p.is_kill);
		// Risky presets are only spawned once warmed at level init; spawning an
		// unwarmed resource here would block-load mid-frame and fatally crash.
		// Blood is always resident, so it spawns unconditionally (no regression).
		if (is_risky(type) && warmed.find(path) == warmed.end())
			continue;

		const unsigned int index = world_particles::spawn(path);
		if (!index)
			continue;
		world_particles::set_control(index, world_particles::CP_POSITION, p.pos);
		m_active.push_back({ index, now + k_lifetime_ms });
	}

	// Reap expired effects.
	for (std::size_t i = 0; i < m_active.size();) {
		if (now >= m_active[i].expire_ms) {
			world_particles::destroy(m_active[i].index);
			m_active[i] = m_active.back();
			m_active.pop_back();
		} else {
			++i;
		}
	}
}

void c_hit_effects::clear() {
	// Only request the clear; tick() performs the destroys on the render thread.
	std::lock_guard<std::mutex> lock(m_mutex);
	m_pending.clear();
	m_clear_requested = true;
}

void c_hit_effects::precache() {
	if (!world_particles::available())
		return;

	// Snapshot what is already resident; bail entirely once everything is warmed
	// (this runs every frame from stage 7, so the fast path must be cheap).
	std::unordered_set<std::string> already;
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_warm_done)
			return;
		already = m_warmed;
	}

	// Warm every not-yet-resident risky preset (one spawn+destroy each) so a later
	// in-frame spawn finds the resource loaded. warm() blocks on the synchronous
	// manifest load, which is only legal outside the render frame -- hence stage 7,
	// retried each frame because the particle manager is not ready immediately after
	// LevelInit on the first map load. A path that fails to create is left unwarmed
	// and retried next frame (all stays false), so tick() never spawns it blind.
	std::vector<std::string> newly;
	bool all = true;
	for (int type = 1; type <= k_type_count - 1; ++type) {
		for (int k = 0; k <= 1; ++k) {
			const char* path = pick_path(type, k != 0);
			if (already.find(path) != already.end())
				continue;
			if (world_particles::warm(path)) {
				already.insert(path);        // avoid re-warming a shared path this pass
				newly.emplace_back(path);
			} else {
				all = false;                 // not ready yet -- retry next frame
			}
		}
	}

	std::lock_guard<std::mutex> lock(m_mutex);
	for (auto& p : newly)
		m_warmed.insert(std::move(p));
	if (all)
		m_warm_done = true;
}

void c_hit_effects::rearm() {
	std::lock_guard<std::mutex> lock(m_mutex);
	m_warmed.clear();
	m_warm_done = false;
}
