#include "fog_handler.hpp"

#include "../../sdk/valve/classes/c_gradient_fog.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"
#include "../../sdk/valve/interfaces/vtables/i_entity_system.hpp"
#include "../../sdk/vfunc/vfunc.hpp"
#include "../../config.hpp"

#include <algorithm>

void c_fog_handler::fog_controller() {
	const auto& wm = g_cfg->visuals.m_world_modulation;

	if (!wm.m_enable_custom_fog) {
		remove_fog();
		return;
	}

	const ImVec4& color = wm.m_fog_color;
	const float start = wm.m_fog_start;
	const float end = wm.m_fog_end;
	const float falloff = wm.m_fog_falloff;

	const bool changed =
		m_last_start != start ||
		m_last_end != end ||
		m_last_falloff != falloff ||
		m_last_color[0] != color.x ||
		m_last_color[1] != color.y ||
		m_last_color[2] != color.z ||
		m_last_color[3] != color.w;

	if (changed)
		remove_fog();

	if (!m_gradient_fog)
		m_gradient_fog = g_interfaces->m_entity_system->create_entity_by_class_name("env_gradient_fog");

	if (m_gradient_fog) {
		auto fog = reinterpret_cast<c_gradient_fog*>(m_gradient_fog);
		fog->m_is_enabled() = true;
		fog->m_fog_start_distance() = start;
		fog->m_fog_end_distance() = end;
		fog->m_fog_strength() = 1.f;
		fog->m_fog_falloff_exponent() = falloff;
		fog->m_fog_max_opacity() = color.w;
		fog->m_fog_color().r = static_cast<std::uint8_t>(std::clamp(color.x, 0.0f, 1.0f) * 255.0f + 0.5f);
		fog->m_fog_color().g = static_cast<std::uint8_t>(std::clamp(color.y, 0.0f, 1.0f) * 255.0f + 0.5f);
		fog->m_fog_color().b = static_cast<std::uint8_t>(std::clamp(color.z, 0.0f, 1.0f) * 255.0f + 0.5f);
		fog->m_fog_color().a = static_cast<std::uint8_t>(std::clamp(color.w, 0.0f, 1.0f) * 255.0f + 0.5f);

		vmt::call_virtual<void>(m_gradient_fog, 10, 0x1);

		m_last_start = start;
		m_last_end = end;
		m_last_falloff = falloff;
		m_last_color[0] = color.x;
		m_last_color[1] = color.y;
		m_last_color[2] = color.z;
		m_last_color[3] = color.w;
	}
}

void c_fog_handler::remove_fog() {
	if (m_gradient_fog) {
		m_gradient_fog->remove();
		m_gradient_fog = nullptr;
	}
}
