#include "chams.hpp"
#include "chams_material.hpp"

#include "../../config.hpp"
#include "../../core/main.hpp"
#include "../../sdk/typedefs/c_handle.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <utility>

namespace {
	// --- Embedded KV3 (.vmat) material definitions --------------------------------
	// "flat" = unlit single-tone; "glow" = self-illuminated. The "occluded" variants
	// add F_DISABLE_Z_BUFFERING so the model renders through walls.

	constexpr const char* k_flat_visible = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_unlitgeneric.vfx"

	F_PAINT_VERTEX_COLORS = 1
	F_TRANSLUCENT = 1
	F_BLEND_MODE = 1

	g_vColorTint = [1, 1, 1, 1]

	TextureAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tNormal = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tTintMask = resource:"materials/default/default_mask_tga_fde710a5.vtex"
})";

	constexpr const char* k_flat_occluded = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_unlitgeneric.vfx"

	F_PAINT_VERTEX_COLORS = 1
	F_TRANSLUCENT = 1
	F_BLEND_MODE = 1
	F_DISABLE_Z_BUFFERING = 1

	g_vColorTint = [1, 1, 1, 1]

	TextureAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tNormal = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tTintMask = resource:"materials/default/default_mask_tga_fde710a5.vtex"
})";

	constexpr const char* k_glow_visible = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_complex.vfx"

	F_SELF_ILLUM = 1
	F_PAINT_VERTEX_COLORS = 1

	g_vColorTint = [ 1.000000, 1.000000, 1.000000, 1.000000 ]
	g_flSelfIllumScale = [ 3.000000, 3.000000, 3.000000, 3.000000 ]
	g_flSelfIllumBrightness = [ 3.000000, 3.000000, 3.000000, 3.000000 ]
	g_vSelfIllumTint = [ 10.000000, 10.000000, 10.000000, 10.000000 ]

	g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tNormal = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tSelfIllumMask = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	TextureAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
})";

	constexpr const char* k_glow_occluded = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_complex.vfx"

	F_SELF_ILLUM = 1
	F_PAINT_VERTEX_COLORS = 1
	F_TRANSLUCENT = 1
	F_DISABLE_Z_BUFFERING = 1

	g_vColorTint = [ 1.000000, 1.000000, 1.000000, 1.000000 ]
	g_flSelfIllumScale = [ 3.000000, 3.000000, 3.000000, 3.000000 ]
	g_flSelfIllumBrightness = [ 3.000000, 3.000000, 3.000000, 3.000000 ]
	g_vSelfIllumTint = [ 10.000000, 10.000000, 10.000000, 10.000000 ]

	g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tNormal = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tSelfIllumMask = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	TextureAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
})";

	// "ghost" = fresnel-based translucent overlay with additive blending via csgo_effects.
	constexpr const char* k_ghost_visible = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_effects.vfx"

	g_tColor = resource:"materials/dev/primary_white_color_tga_21186c76.vtex"
	g_tNormal = resource:"materials/default/default_normal_tga_7652cb.vtex"
	g_tMask1 = resource:"materials/default/default_mask_tga_344101f8.vtex"
	g_tMask2 = resource:"materials/default/default_mask_tga_344101f8.vtex"
	g_tMask3 = resource:"materials/default/default_mask_tga_344101f8.vtex"

	g_flOpacityScale = 0.45
	g_flFresnelExponent = 0.75
	g_flFresnelFalloff = 1
	g_flFresnelMax = 0.0
	g_flFresnelMin = 1

	F_ADDITIVE_BLEND = 1
	F_BLEND_MODE = 0
	F_TRANSLUCENT = 1
	F_IGNOREZ = 0
	F_DISABLE_Z_WRITE = 0
	F_DISABLE_Z_BUFFERING = 0
	F_RENDER_BACKFACES = 1

	g_vColorTint = [1.0, 1.0, 1.0, 0.0]
})";

	constexpr const char* k_ghost_occluded = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_effects.vfx"

	g_tColor = resource:"materials/dev/primary_white_color_tga_21186c76.vtex"
	g_tNormal = resource:"materials/default/default_normal_tga_7652cb.vtex"
	g_tMask1 = resource:"materials/default/default_mask_tga_344101f8.vtex"
	g_tMask2 = resource:"materials/default/default_mask_tga_344101f8.vtex"
	g_tMask3 = resource:"materials/default/default_mask_tga_344101f8.vtex"

	g_flOpacityScale = 0.45
	g_flFresnelExponent = 0.75
	g_flFresnelFalloff = 1
	g_flFresnelMax = 0.0
	g_flFresnelMin = 1

	F_ADDITIVE_BLEND = 1
	F_BLEND_MODE = 0
	F_TRANSLUCENT = 1
	F_IGNOREZ = 1
	F_DISABLE_Z_WRITE = 1
	F_DISABLE_Z_BUFFERING = 1
	F_RENDER_BACKFACES = 1

	g_vColorTint = [1.0, 1.0, 1.0, 0.0]
})";

	// "textured" = fully lit PBR surface via csgo_complex: keeps normal scene lighting on
	// the model, vertex-colour tinted. Enhanced with better lighting parameters while
	// using only safe default textures that are guaranteed to load. Translucent with
	// proper blending for high-quality rendering. Depth-tested.
	constexpr const char* k_textured_visible = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_complex.vfx"

	F_PAINT_VERTEX_COLORS = 1
	F_TRANSLUCENT = 1
	F_BLEND_MODE = 1
	F_SPECULAR = 1
	F_METALNESS_TEXTURE = 0

	g_vColorTint = [ 1.000000, 1.000000, 1.000000, 1.000000 ]
	g_flMetalness = 0.000000
	g_flRoughness = 0.250000
	g_flRoughnessScaleFactor = 0.400000
	g_flSpecularScale = 3.000000
	g_flSpecularExponent = 128.000000
	g_flOpacityScale = 1.000000

	g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tNormal = resource:"materials/default/default_normal_tga_7be61377.vtex"
	TextureAmbientOcclusion = resource:"materials/default/default_ao_tga_559f1ac6.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_ao_tga_559f1ac6.vtex"
})";

	constexpr const char* k_textured_occluded = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_complex.vfx"

	F_PAINT_VERTEX_COLORS = 1
	F_TRANSLUCENT = 1
	F_BLEND_MODE = 1
	F_SPECULAR = 1
	F_METALNESS_TEXTURE = 0
	F_DISABLE_Z_BUFFERING = 1

	g_vColorTint = [ 1.000000, 1.000000, 1.000000, 1.000000 ]
	g_flMetalness = 0.000000
	g_flRoughness = 0.250000
	g_flRoughnessScaleFactor = 0.400000
	g_flSpecularScale = 3.000000
	g_flSpecularExponent = 128.000000
	g_flOpacityScale = 1.000000

	g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
	g_tNormal = resource:"materials/default/default_normal_tga_7be61377.vtex"
	TextureAmbientOcclusion = resource:"materials/default/default_ao_tga_559f1ac6.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_ao_tga_559f1ac6.vtex"
})";

	// "metallic" = chrome that reflects the baked environment cubemap of the surrounding
	// scene (sky, walls, ambient). The engine does NOT render real-time reflections of
	// live players/props onto models -- this reflects the static scene capture at the
	// model's location, the standard "chrome chams" look.
	//
	// Recipe (from a known-working reference):
	//   * Full metal via the g_flMetalness=1 scalar (no metalness texture needed).
	//   * The mirror sharpness comes from the SPECIFIC normal map default_normal_1b833b2a
	//     -- a flat normal whose alpha yields near-zero roughness. (The other stock normal
	//     default_normal_7be61377 has a rough alpha and only ever gives glossy metal; that
	//     was the whole reason earlier attempts could not reach a clean mirror.)
	//   * g_tColor = the dev primary_white texture (bright white base -> clean chrome).
	//   * F_DISABLE_Z_PREPASS + F_DISABLE_Z_WRITE + F_BLEND_MODE for correct layering.
	//   * F_PAINT_VERTEX_COLORS=1 is our addition (not in the reference) so the menu colour
	//     tint still applies through prim->m_color like the other styles.
	// The occluded variant adds F_DISABLE_Z_BUFFERING to draw through walls.
	constexpr const char* k_metallic_visible = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_complex.vfx"

	F_PAINT_VERTEX_COLORS = 1
	F_TRANSLUCENT = 1
	F_DISABLE_Z_PREPASS = 1
	F_DISABLE_Z_WRITE = 1
	F_BLEND_MODE = 1
	F_RENDER_BACKFACES = 0

	g_vColorTint = [ 1.0, 1.0, 1.0, 1.0 ]
	g_bFogEnabled = 0
	g_flMetalness = 1.000
	g_flModelTintAmount = 1.000
	g_nScaleTexCoordUByModelScaleAxis = 0
	g_nScaleTexCoordVByModelScaleAxis = 0
	g_nTextureAddressModeU = 0
	g_nTextureAddressModeV = 0
	g_flTexCoordRotation = 0.000

	g_tColor = resource:"materials/dev/primary_white_color_tga_21186c76.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_ao_tga_559f1ac6.vtex"
	g_tNormal = resource:"materials/default/default_normal_tga_1b833b2a.vtex"
})";

	constexpr const char* k_metallic_occluded = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "csgo_complex.vfx"

	F_PAINT_VERTEX_COLORS = 1
	F_TRANSLUCENT = 1
	F_DISABLE_Z_BUFFERING = 1
	F_DISABLE_Z_PREPASS = 1
	F_DISABLE_Z_WRITE = 1
	F_BLEND_MODE = 1
	F_RENDER_BACKFACES = 0

	g_vColorTint = [ 1.0, 1.0, 1.0, 1.0 ]
	g_bFogEnabled = 0
	g_flMetalness = 1.000
	g_flModelTintAmount = 1.000
	g_nScaleTexCoordUByModelScaleAxis = 0
	g_nScaleTexCoordVByModelScaleAxis = 0
	g_nTextureAddressModeU = 0
	g_nTextureAddressModeV = 0
	g_flTexCoordRotation = 0.000

	g_tColor = resource:"materials/dev/primary_white_color_tga_21186c76.vtex"
	g_tAmbientOcclusion = resource:"materials/default/default_ao_tga_559f1ac6.vtex"
	g_tNormal = resource:"materials/default/default_normal_tga_1b833b2a.vtex"
})";

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

	// Entry index (handle slot) of an entity, or -1. Used to key the target map by a
	// stable slot instead of the churny C++ pointer, so first-person arm/viewmodel
	// meshes match even when their owner pointer is reallocated between frames.
	// Pointer/int locals only inside the __try (C2712-safe). Marked noinline so /O2
	// cannot fold this __try into refresh_targets, which owns unwinding objects
	// (std::mutex/unordered_map) -- see [[chams-c2712-seh-object-unwinding]].
	__declspec(noinline) int entry_index_of(c_entity_instance* e) {
		__try {
			if (!e)
				return -1;
			const c_base_handle handle = e->get_handle();
			return handle.is_valid() ? handle.get_entry_index() : -1;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return -1;
		}
	}

	// TEMPORARY DEBUG: designer name of an owner (reads entity identity + offset, NOT
	// the broken class-binding vfunc). Pointer/int locals only -> SEH-safe.
	__declspec(noinline) const char* designer_name_safe(const void* e) {
		__try {
			auto* inst = reinterpret_cast<c_entity_instance*>(const_cast<void*>(e));
			return inst ? inst->get_designer_name() : nullptr;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	// Resolve controller index `i` to its pawn, returning it only if it is an alive
	// enemy of `local`. Pointer/int locals only -> safe to wrap in SEH (no C2712).
	c_cs_player_pawn* resolve_enemy_pawn(int i, c_cs_player_pawn* local) {
		__try {
			auto* entity = get_base_entity_safe(i);
			if (!entity || !entity->is_player_controller())
				return nullptr;

			auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
			const c_base_handle pawn_handle = controller->m_pawn();
			if (!pawn_handle.is_valid())
				return nullptr;

			auto* pawn = reinterpret_cast<c_cs_player_pawn*>(get_base_entity_safe(pawn_handle.get_entry_index()));
			if (!pawn || pawn->m_health() <= 0)
				return nullptr;
			if (pawn->m_team_num() == local->m_team_num())
				return nullptr;   // enemies only

			return pawn;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	// Resolve controller index `i` to its pawn, returning it only if it is an alive
	// teammate of `local` (and not `local` itself). Pointer/int locals only.
	c_cs_player_pawn* resolve_teammate_pawn(int i, c_cs_player_pawn* local) {
		__try {
			auto* entity = get_base_entity_safe(i);
			if (!entity || !entity->is_player_controller())
				return nullptr;

			auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
			const c_base_handle pawn_handle = controller->m_pawn();
			if (!pawn_handle.is_valid())
				return nullptr;

			auto* pawn = reinterpret_cast<c_cs_player_pawn*>(get_base_entity_safe(pawn_handle.get_entry_index()));
			if (!pawn || pawn->m_health() <= 0)
				return nullptr;
			if (pawn == local)
				return nullptr;   // not ourselves
			if (pawn->m_team_num() != local->m_team_num())
				return nullptr;   // teammates only

			return pawn;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	// Resolve the local player's first-person arms entity (C_CS2HudModelArms) from
	// its handle. Pointer/int locals only -> SEH-safe.
	c_base_entity* resolve_arms_entity(c_cs_player_pawn* local) {
		__try {
			const c_base_handle arms_handle = local->m_hud_model_arms();
			if (!arms_handle.is_valid())
				return nullptr;
			return get_base_entity_safe(arms_handle.get_entry_index());
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return nullptr;
		}
	}

	// Collect the owning entity of every scene node in `entity`'s scene-node subtree
	// (depth-first, bounded). While moving, the first-person body/arms meshes are
	// submitted under intermediate nodes of the local hierarchy whose owner is neither
	// the arms entity nor the local pawn -- walking the whole subtree captures them so
	// the arms stop flashing their real material. Pointer/int locals only + a fixed
	// stack -> no unwinding object shares a frame with the __try (C2712-safe).
	int collect_entity_subtree_owners(c_base_entity* entity, const void** out, int max) {
		int n = 0;
		__try {
			auto* root = entity->m_scene_node();
			if (!root)
				return 0;

			c_game_scene_node* stack[256];
			int sp = 0;
			stack[sp++] = root;

			// Dedup by entry-index instead of pointer, since the pointer can churn between
			// frames (exactly what causes the flicker). A handle's entry_index is stable
			// across C++ object reallocation. We keep a parallel array of seen indices.
			int seen_indices[256];
			int seen_count = 0;

			// Traverse the WHOLE subtree; `n < max` must NOT gate the traversal itself,
			// only the writes. A pawn/arms hierarchy has many bone/attachment nodes that
			// all share one owner, so we dedup: `out` holds DISTINCT owners. Without this
			// the array saturated with duplicate pawn pointers and the descent was cut
			// off before reaching the weapon-viewmodel's deeper child nodes (different
			// owners) -- those meshes were the ones flashing their real material, worst
			// while moving (animation exposes more nodes -> earlier cutoff).
			while (sp > 0) {
				c_game_scene_node* node = stack[--sp];
				for (auto* sn = node; sn; sn = sn->m_next_sibling()) {
					if (auto* owner = sn->m_owner()) {
						// Dedup by entry_index -- stable key across pointer churn.
						const c_base_handle h = owner->get_handle();
						if (h.is_valid()) {
							const int idx = h.get_entry_index();
							bool seen = false;
							for (int i = 0; i < seen_count; ++i) {
								if (seen_indices[i] == idx) {
									seen = true;
									break;
								}
							}
							if (!seen) {
								if (n < max)
									out[n++] = static_cast<const void*>(owner);
								if (seen_count < 256)
									seen_indices[seen_count++] = idx;
							}
						}
					}
					if (auto* child = sn->m_child()) {
						if (sp < 256)
							stack[sp++] = child;
					}
				}
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return n;
		}
		return n;
	}

	std::uint8_t to_u8(float v) {
		return static_cast<std::uint8_t>(std::clamp(v, 0.0f, 1.0f) * 255.0f + 0.5f);
	}

	void apply_color(c_mesh_primitive* prim, const ImVec4& c) {
		prim->m_color.r = to_u8(c.x);
		prim->m_color.g = to_u8(c.y);
		prim->m_color.b = to_u8(c.z);
		prim->m_color.a = to_u8(c.w);
	}
}

void c_chams::ensure_init() {
	if (m_initialized)
		return;

	// Build all four materials up-front. A style that fails to build stays null and
	// is simply skipped in on_generate_primitives (no crash, no effect for that style).
	m_visible[style_flat]  = create_custom_material("materials/celerity/chams_flat_visible.vmat",  k_flat_visible);
	m_occluded[style_flat] = create_custom_material("materials/celerity/chams_flat_occluded.vmat", k_flat_occluded);
	m_visible[style_glow]  = create_custom_material("materials/celerity/chams_glow_visible.vmat",  k_glow_visible);
	m_occluded[style_glow] = create_custom_material("materials/celerity/chams_glow_occluded.vmat", k_glow_occluded);
	m_visible[style_ghost]  = create_custom_material("materials/celerity/chams_ghost_visible.vmat",  k_ghost_visible);
	m_occluded[style_ghost] = create_custom_material("materials/celerity/chams_ghost_occluded.vmat", k_ghost_occluded);
	m_visible[style_textured]  = create_custom_material("materials/celerity/chams_textured_visible.vmat",  k_textured_visible);
	m_occluded[style_textured] = create_custom_material("materials/celerity/chams_textured_occluded.vmat", k_textured_occluded);
	m_visible[style_metallic]  = create_custom_material("materials/celerity/chams_metallic_visible.vmat",  k_metallic_visible);
	m_occluded[style_metallic] = create_custom_material("materials/celerity/chams_metallic_occluded.vmat", k_metallic_occluded);
	// Consider ourselves initialised once at least one material exists, so we do not
	// keep hammering create_material every present frame if a variant fails.
		for (int st = 0; st < style_count; ++st) {
		if (m_visible[st] || m_occluded[st]) {
			m_initialized = true;
			break;
		}
	}
}

void c_chams::refresh_targets() {
	// Resolve the current target pointers into a local list (no SEH in this function,
	// so containers are legal here). Each resolve helper is SEH-guarded and only ever
	// returns pointers, so no unwinding object shares a frame with a __try.
	struct resolved_ref { const void* ptr; int index; int target; };
	resolved_ref resolved[256];
	int resolved_count = 0;
	const auto push = [&](const void* p, int t) {
		if (p && resolved_count < static_cast<int>(std::size(resolved))) {
			const int idx = entry_index_of(reinterpret_cast<c_entity_instance*>(const_cast<void*>(p)));
			resolved[resolved_count++] = { p, idx, t };
		}
	};

	if (g_ctx && g_ctx->m_local_pawn && g_interfaces && g_interfaces->m_entity_system) {
		auto* local = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);

		// Players: each controller resolves to either an enemy or a teammate pawn.
		for (int i = 1; i <= 64; ++i) {
			if (auto* pawn = resolve_enemy_pawn(i, local))
				push(pawn, target_enemy);
			else if (auto* mate = resolve_teammate_pawn(i, local))
				push(mate, target_teammate);
		}

		// Local first-person / own model -> arms. The arms meshes are submitted under
		// different nodes of the local hierarchy depending on movement state, so map
		// the whole local-pawn scene subtree (plus the pawn itself) to the arms target.
		// This is the catch-all that stops the arms flashing their real material while
		// moving. Weapon-viewmodel entities are re-mapped to their own target below.
		const void* local_owners[64] = {};
		const int local_count = collect_entity_subtree_owners(local, local_owners, 64);
		for (int k = 0; k < local_count; ++k)
			push(local_owners[k], target_arms);
		push(static_cast<const void*>(local), target_arms);

		// Arms entity + the entire weapon-viewmodel subtree. Deep-walk the arms scene
		// subtree (not just its direct children) so the weapon's moving parts and
		// attachments -- submitted under grandchild nodes of the viewmodel node -- are
		// captured too; those descendants were the meshes still flashing their real
		// material after the single-level walk. Pushed as viewmodel FIRST, then the arms
		// entity itself as arms LAST, so the later upsert wins and the arm meshes keep
		// the arms colour independent of the gun.
		if (auto* arms = resolve_arms_entity(local)) {
			const void* vm_owners[64] = {};
			const int vm_count = collect_entity_subtree_owners(arms, vm_owners, 64);
			for (int k = 0; k < vm_count; ++k)
				push(vm_owners[k], target_viewmodel);

			push(static_cast<const void*>(arms), target_arms);
		}
	}

	// Merge with a TTL instead of hard-swapping: age out existing entries, then
	// (re)insert everything resolved this frame with a fresh TTL. A target that
	// missed resolution on a single frame survives k_target_ttl frames before it is
	// dropped, which is what prevents the real-material flicker (worst on the local
	// arms/viewmodel, whose handles churn far more than enemy pawns).
	// AGGRESSIVE REFRESH: if an entity is re-resolved, reset its TTL to max instead
	// of just keeping the old one. This bridges animation-driven scene-graph churn
	// where moving/strafing causes nodes to temporarily disappear from traversal.

	std::lock_guard<std::mutex> lock(m_targets_mutex);
	
	// First, age out stale entries (decrement TTL, erase if expired)
	for (auto it = m_targets.begin(); it != m_targets.end(); ) {
		if (--it->second.ttl <= 0)
			it = m_targets.erase(it);
		else
			++it;
	}
	for (auto it = m_target_indices.begin(); it != m_target_indices.end(); ) {
		if (--it->second.ttl <= 0)
			it = m_target_indices.erase(it);
		else
			++it;
	}
	
	// Then insert/update everything resolved this frame with FRESH TTL
	for (int k = 0; k < resolved_count; ++k) {
		// Upsert: if already exists, this resets TTL to max (aggressive refresh)
		m_targets[resolved[k].ptr] = { resolved[k].target, k_target_ttl };
		// Also key by handle slot: on_generate_primitives resolves the object's m_owner
		// as a handle, and the slot is identical across pointer reallocation -- this is
		// what stops the arms/viewmodel flashing their real material between frames.
		if (resolved[k].index >= 0)
			m_target_indices[resolved[k].index] = { resolved[k].target, k_target_ttl };
	}
}

int c_chams::classify(const void* entity, int entry_index) {
	std::lock_guard<std::mutex> lock(m_targets_mutex);
	if (entity) {
		auto it = m_targets.find(entity);
		if (it != m_targets.end())
			return it->second.target;
	}
	// Fall back to the handle-slot map: first-person meshes whose owner pointer churns
	// still match here because their entry index is stable across frames.
	if (entry_index >= 0) {
		auto it = m_target_indices.find(entry_index);
		if (it != m_target_indices.end())
			return it->second.target;
	}
	return -1;
}

bool c_chams::on_generate_primitives(c_animatable_scene_object_desc* desc, c_scene_animatable_object* object,
                                     void* a3, c_mesh_primitive_output_buffer* render_buf, generate_primitives_fn original) {
	if (!g_cfg || !m_initialized || !object || !render_buf || !original)
		return false;

	// Early-out if no target has any pass enabled, so we skip owner resolution
	// entirely on the common (chams-off) path.
	bool any_enabled = false;
	for (int t = 0; t < target_count; ++t) {
		const auto& ct = g_cfg->visuals.m_chams_targets[t];
		if (ct.m_visible || ct.m_occluded) {
			any_enabled = true;
			break;
		}
	}
	if (!any_enabled)
		return false;

	// Resolve the owning entity of this object directly from the object argument --
	// this is the whole point of the GeneratePrimitives approach: one stable owner per
	// animatable object, no per-mesh-part pointer churn. Pointer/int locals only inside
	// the __try (C2712-safe).
	const void* owner_entity = nullptr;
	int owner_index = -1;
	__try {
		const c_base_handle handle = *reinterpret_cast<c_base_handle*>(&object->m_owner);
		if (handle.is_valid()) {
			owner_index = handle.get_entry_index();
			if (auto* entity = get_base_entity_safe(owner_index))
				owner_entity = entity;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}

	// Only override objects owned by a known target (map built in refresh_targets).
	const int target = classify(owner_entity, owner_index);
	if (target < 0)
		return false;

	const auto& ct = g_cfg->visuals.m_chams_targets[target];
	const bool visible  = ct.m_visible;
	const bool occluded = ct.m_occluded;
	if (!visible && !occluded)
		return false;

	const int vis_style = std::clamp(ct.m_visible_material, 0, static_cast<int>(style_count) - 1);
	const int occ_style = std::clamp(ct.m_occluded_material, 0, static_cast<int>(style_count) - 1);

	// Apply a chosen material + colour to every primitive appended to render_buf by a
	// fresh call to `original`. Each call to `original` regenerates the object's mesh
	// primitives and appends them to the buffer, so we snapshot the count before the
	// call and only touch the ones added by it. Pointer/int locals only -> SEH-safe.
	const auto emit_pass = [&](c_material_2* material, const ImVec4& color) {
		if (!material)
			return;
		const int prev = render_buf->m_arr_size;
		original(desc, object, a3, render_buf);
		for (int i = prev; i < render_buf->m_arr_size; ++i) {
			c_mesh_primitive* prim = render_buf->get_primitive(i);
			if (!prim)
				continue;
			prim->m_material  = material;
			prim->m_material2 = material;
			apply_color(prim, color);
		}
	};

	bool drew = false;
	__try {
		// Occluded pass first (through walls), then the depth-tested visible pass.
		if (occluded && m_occluded[occ_style]) {
			auto c = ct.m_occluded_color;
			emit_pass(m_occluded[occ_style], c);
			drew = true;
		}
		if (visible && m_visible[vis_style]) {
			auto c = ct.m_visible_color;
			emit_pass(m_visible[vis_style], c);
			drew = true;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return false;
	}

	return drew;
}
