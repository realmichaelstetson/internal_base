#include "world_effects.hpp"

#include "../../config.hpp"
#include "../../core/main.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../shared/world_particles.hpp"
#include "world_particle_assets.hpp"

#include <Windows.h>
#include <algorithm>
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <system_error>
#include <vector>

namespace {
	// Custom authored particle resources. They are authored to read control point
	// 2 as a density value (stock CS2 particles ignore that CP). The engine resolves
	// "bin/<name>.vpcf" to csgo/bin/<name>.vpcf_c; ensure_assets() guarantees the
	// compiled file is present there. Index = preset.
	constexpr const char* k_snow    = "bin/falling_snow1.vpcf";
	constexpr const char* k_stars   = "bin/nomove_stars.vpcf";
	constexpr const char* k_ember_a = "bin/falling_ember1.vpcf";
	constexpr const char* k_ember_b = "bin/falling_ember2.vpcf";

	// Control point indices the authored particles read.
	constexpr int CP_POSITION = 0;
	constexpr int CP_DENSITY  = 2;

	// Embedded resource -> on-disk filename under csgo/bin/. Names must match the
	// k_* paths above (minus the "bin/" prefix, plus the "_c" compiled suffix).
	struct embedded_asset_t {
		const char*          filename;
		const unsigned char* data;
		std::size_t          size;
	};
	constexpr embedded_asset_t k_embedded_assets[] = {
		{ "falling_snow1.vpcf_c",  world_particle_assets::falling_snow1,  sizeof(world_particle_assets::falling_snow1)  },
		{ "nomove_stars.vpcf_c",   world_particle_assets::nomove_stars,   sizeof(world_particle_assets::nomove_stars)   },
		{ "falling_ember1.vpcf_c", world_particle_assets::falling_ember1, sizeof(world_particle_assets::falling_ember1) },
		{ "falling_ember2.vpcf_c", world_particle_assets::falling_ember2, sizeof(world_particle_assets::falling_ember2) },
	};

	// Resolve <game>/csgo/bin from the running executable. The injected DLL lives in
	// cs2.exe, whose path is ...\game\bin\win64\cs2.exe, so csgo/bin is three levels
	// up + "csgo/bin". Returns an empty path if resolution fails.
	std::filesystem::path resolve_csgo_bin() {
		wchar_t buffer[MAX_PATH];
		const DWORD len = GetModuleFileNameW(nullptr, buffer, MAX_PATH);
		if (len == 0 || len >= MAX_PATH)
			return {};

		std::error_code ec;
		std::filesystem::path exe(buffer);                          // ...\game\bin\win64\cs2.exe
		std::filesystem::path game = exe.parent_path()              // ...\game\bin\win64
		                                .parent_path()              // ...\game\bin
		                                .parent_path();             // ...\game
		if (game.empty())
			return {};

		std::filesystem::path bin = game / "csgo" / "bin";
		// Sanity: the parent "csgo" content root should exist for a real install.
		if (!std::filesystem::exists(game / "csgo", ec))
			return {};
		return bin;
	}
}

bool c_world_effects::resolve_local_origin(vec3_t& out) const {
	if (!g_ctx || !g_ctx->m_local_pawn)
		return false;

	__try {
		auto* pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);

		// Only run while we are an alive player on a real team -- avoids spawning
		// at a stale/zero origin during warmup, spectate or respawn.
		const int team = pawn->m_team_num();
		if (pawn->m_health() <= 0 || (team != 2 && team != 3))
			return false;

		vec3_t origin{};
		if (auto* node = pawn->m_scene_node())
			origin = node->m_abs_origin();
		if (!origin.is_valid())
			origin = pawn->get_eye_pos();

		if (!origin.is_valid())
			return false;

		out = origin;
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}
}

void c_world_effects::destroy_all() {
	world_particles::destroy(m_first);
	world_particles::destroy(m_second);
	m_first = 0;
	m_second = 0;
	m_initialized = false;
	m_type = -1;
}

void c_world_effects::create_for_type(int type, const std::unordered_set<std::string>& warmed) {
	m_first = 0;
	m_second = 0;

	// Only spawn a path that warm_tick() has already made resident; spawning an
	// unwarmed (and possibly unloaded) resource inside the frame would block-load
	// and fatally crash. An absent file simply stays unwarmed -> no-op.
	const auto allow = [&](const char* p) { return warmed.find(p) != warmed.end(); };

	switch (type) {
	case 0: // snow
		if (allow(k_snow))
			m_first = world_particles::spawn(k_snow);
		break;
	case 1: // stars
		if (allow(k_stars))
			m_first = world_particles::spawn(k_stars);
		break;
	case 2: // ashes (two layers)
		if (allow(k_ember_a))
			m_first = world_particles::spawn(k_ember_a);
		if (allow(k_ember_b))
			m_second = world_particles::spawn(k_ember_b);
		break;
	default:
		break;
	}

	m_type = type;
	m_initialized = (m_first != 0 || m_second != 0);
}

void c_world_effects::update() {
	if (!g_cfg || !world_particles::available())
		return;

	// Feature off: tear down anything live and bail.
	if (!g_cfg->visuals.m_world_effects) {
		if (m_initialized)
			destroy_all();
		return;
	}

	// Pull the warmed snapshot + any pending map-change reset under the lock.
	std::unordered_set<std::string> warmed;
	bool reset = false;
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		warmed = m_warmed;
		reset = m_reset_requested;
		m_reset_requested = false;
	}

	// On a map change the old particle manager is gone, so the cached indices are
	// stale -- drop them WITHOUT calling destroy (that manager no longer exists).
	if (reset) {
		m_first = 0;
		m_second = 0;
		m_initialized = false;
		m_type = -1;
		m_next_retry_frame = 0;   // recreate immediately now that warming is done
	}

	vec3_t origin{};
	if (!resolve_local_origin(origin))
		return;

	const int type = std::clamp(g_cfg->visuals.m_world_effects_type, 0, 2);

	// Type switched in the menu -> rebuild on the current (live) manager.
	if (m_initialized && m_type != type)
		destroy_all();

	if (!m_initialized) {
		if (ImGui::GetFrameCount() < m_next_retry_frame)
			return;

		create_for_type(type, warmed);
		if (!m_initialized) {
			// Nothing warmed/creatable (files missing) -- back off so we are not
			// retrying every frame.
			m_next_retry_frame = ImGui::GetFrameCount() + 120;
			return;
		}
	}

	const float density = std::clamp(g_cfg->visuals.m_world_effects_density, 0.0f, 100.0f) * 10.0f;
	const vec3_t density_cp{ density, 0.0f, 0.0f };

	world_particles::set_control(m_first, CP_POSITION, origin);
	world_particles::set_control(m_first, CP_DENSITY, density_cp);
	world_particles::set_control(m_second, CP_POSITION, origin);
	world_particles::set_control(m_second, CP_DENSITY, density_cp);
}

void c_world_effects::ensure_assets() {
	// Write the embedded compiled particle resources into csgo/bin/ once per
	// process, so the engine can resolve them on any machine. Existing files are
	// never overwritten (a user may have supplied their own).
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (m_assets_written)
			return;
		m_assets_written = true;   // set up-front; a failed write is not retried
	}

	const std::filesystem::path bin = resolve_csgo_bin();
	if (bin.empty())
		return;

	std::error_code ec;
	std::filesystem::create_directories(bin, ec);

	for (const auto& asset : k_embedded_assets) {
		const std::filesystem::path path = bin / asset.filename;
		if (std::filesystem::exists(path, ec))
			continue;

		std::ofstream file(path, std::ios::binary | std::ios::trunc);
		if (file)
			file.write(reinterpret_cast<const char*>(asset.data),
			           static_cast<std::streamsize>(asset.size));
	}
}

void c_world_effects::on_level_change() {
	// Files must be on disk before the first warm attempt; do it here (idempotent).
	ensure_assets();

	// A new map means a new particle manager: the old warmed state is stale and the
	// live indices must be dropped. Re-arm warming so warm_tick() reloads for the
	// new map once its manager is ready.
	std::lock_guard<std::mutex> lock(m_mutex);
	m_warmed.clear();
	m_warm_pending = true;
	m_warm_attempts = 0;
	m_reset_requested = true;
}

void c_world_effects::warm_tick() {
	if (!g_cfg)
		return;
	if (!world_particles::available())
		return;

	// Snapshot which resources still need warming (under the lock).
	constexpr const char* k_all_paths[] = { k_snow, k_stars, k_ember_a, k_ember_b };
	constexpr int         k_path_count  = 4;
	// ~10 s of stage-7 passes: bounds retries so a genuinely missing/corrupt file
	// cannot spin the block-load forever.
	constexpr int         k_max_attempts = 600;

	std::vector<const char*> todo;
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if (!m_warm_pending)
			return;
		for (const char* path : k_all_paths)
			if (m_warmed.find(path) == m_warmed.end())
				todo.push_back(path);
	}

	// Nothing left to warm -- we're done.
	if (todo.empty()) {
		std::lock_guard<std::mutex> lock(m_mutex);
		m_warm_pending = false;
		return;
	}

	// Force each outstanding resource resident via a spawn+destroy. This is the
	// synchronous manifest load; it is legal HERE (FrameStageNotify, outside the
	// render frame) but fatal in the present hook. On the first map load the manager
	// is not ready so warm() returns false -- retry next frame.
	//
	// Crucially we keep retrying until EVERY resource is resident, not just one: the
	// manager can briefly be "partially ready" (some paths warm, others do not), and
	// stopping there would leave the selected effect gated out for the whole map --
	// the old intermittent failure.
	std::vector<std::string> just_warmed;
	for (const char* path : todo) {
		if (world_particles::warm(path))
			just_warmed.emplace_back(path);
	}

	std::lock_guard<std::mutex> lock(m_mutex);
	for (auto& p : just_warmed)
		m_warmed.insert(std::move(p));
	if (!just_warmed.empty()) {
		m_reset_requested = true;   // rebuild the live particle on the ready manager
		m_warm_attempts = 0;        // made progress -- reset the retry clock
	}

	// Done only once all resources are resident; otherwise keep retrying (bounded).
	if (static_cast<int>(m_warmed.size()) >= k_path_count || ++m_warm_attempts >= k_max_attempts)
		m_warm_pending = false;
}
