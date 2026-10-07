#include "world.hpp"

#include "../../sdk/valve/classes/c_post_processing.hpp"
#include "../../sdk/valve/classes/c_scene_light_obj.hpp"
#include "../../config.hpp"

#include <algorithm>

void c_world::exposure(c_post_processing_volume* post_processing) {
	if (!post_processing)
		return;

	const auto& wm = g_cfg->visuals.m_world_modulation;

	if (!wm.m_enable_exposure)
		return;

	float exp = wm.m_exposure;

	post_processing->m_exposure_control() = true;
	post_processing->m_fade_speed_down() = 0.0f;
	post_processing->m_fade_speed_up() = 0.0f;
	post_processing->m_min() = exp;
	post_processing->m_max() = exp;
}

void c_world::lighting(c_scene_light_object* light) {
	if (!light)
		return;

	const auto& wm = g_cfg->visuals.m_world_modulation;

	if (!wm.m_enable_lighting) {
		auto it = m_light_originals.find(light);
		if (it != m_light_originals.end()) {
			light->m_color_r = it->second.r;
			light->m_color_g = it->second.g;
			light->m_color_b = it->second.b;
			light->m_color_a = it->second.a;
			m_light_originals.erase(it);
		}
		return;
	}

	if (m_light_originals.find(light) == m_light_originals.end())
		m_light_originals[light] = { light->m_color_r, light->m_color_g, light->m_color_b, light->m_color_a };

	light->m_color_r = std::clamp(wm.m_lighting.x, 0.0f, 1.0f);
	light->m_color_g = std::clamp(wm.m_lighting.y, 0.0f, 1.0f);
	light->m_color_b = std::clamp(wm.m_lighting.z, 0.0f, 1.0f);
	light->m_color_a = std::clamp(wm.m_lighting.w, 0.0f, 1.0f);
}

void c_world::reset() {
	m_light_originals.clear();
}

void c_world::aggregate_scene(c_base_scene_data* scene, int count, c_material_2* material) {
	(void)material;
	if (!scene || count <= 0)
		return;

	const auto& wm = g_cfg->visuals.m_world_modulation;

	if (!wm.m_enable_wall)
		return;

	auto to_u8 = [](float v) { return static_cast<std::uint8_t>(std::clamp(v, 0.0f, 1.0f) * 255.0f + 0.5f); };

	std::uint8_t r = to_u8(wm.m_wall.x);
	std::uint8_t g = to_u8(wm.m_wall.y);
	std::uint8_t b = to_u8(wm.m_wall.z);

	for (int i = 0; i < count; ++i) {
		auto* sc = &scene[i];
		sc->r = r;
		sc->g = g;
		sc->b = b;
		sc->a = 255;
	}
}
