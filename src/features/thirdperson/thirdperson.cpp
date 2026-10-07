#include "thirdperson.hpp"
#include "../../core/main.hpp"
#include "../../sdk/valve/classes/c_view_setup.hpp"
#include "../../sdk/valve/interfaces/vtables/i_csgo_input.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../../ui/menu/elements/bind.h"
#include <cmath>

void c_thirdperson::override_view(c_view_setup* view_setup) {
	if (!view_setup)
		return;

	if (!g_cfg || !g_cfg->visuals.m_thirdperson)
		return;

	if (!g_ctx || !g_ctx->m_local_pawn)
		return;

	if (!g_interfaces || !g_interfaces->m_csgo_input)
		return;

	bool thirdperson_active = true;
	if (auto it = UI::g_binds.find("thirdperson"); it != UI::g_binds.end() && it->second.mode != UI::BindMode::AlwaysOn)
		thirdperson_active = UI::IsBindActive("thirdperson");

	if (!thirdperson_active)
		return;

	auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);

	vec3_t eye{};
	if (auto* node = local_pawn->m_scene_node())
		eye = node->m_abs_origin();
	if (!eye.is_valid() || eye.is_zero())
		eye = local_pawn->get_eye_pos();
	const vec3_t view_offset = *reinterpret_cast<vec3_t*>(reinterpret_cast<std::uintptr_t>(local_pawn) + 0xF60); // @sdk schema:C_BaseModelEntity::m_vecViewOffset
	if (view_offset.is_valid() && !view_offset.is_zero())
		eye += view_offset;

	const vec3_t angles = g_interfaces->m_csgo_input->get_view_angles();
	constexpr float deg2rad = 3.14159265f / 180.0f;
	const float sp = std::sinf(angles.x * deg2rad);
	const float cp = std::cosf(angles.x * deg2rad);
	const float sy = std::sinf(angles.y * deg2rad);
	const float cy = std::cosf(angles.y * deg2rad);
	const vec3_t forward{ cp * cy, cp * sy, -sp };

	view_setup->m_origin = eye - forward * g_cfg->visuals.m_thirdperson_distance;
}
