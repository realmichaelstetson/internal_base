#pragma once

#include "../../valve/classes/c_cs_player_pawn.hpp"

struct c_fog_material_color {
	std::uint8_t r, g, b, a;
};

class c_gradient_fog : public c_base_entity {
public:
	SCHEMA(m_is_enabled, bool, "C_GradientFog", "m_bIsEnabled");
	SCHEMA(m_fog_start_distance, float, "C_GradientFog", "m_flFogStartDistance");
	SCHEMA(m_fog_end_distance, float, "C_GradientFog", "m_flFogEndDistance");
	SCHEMA(m_fog_strength, float, "C_GradientFog", "m_flFogStrength");
	SCHEMA(m_fog_falloff_exponent, float, "C_GradientFog", "m_flFogFalloffExponent");
	SCHEMA(m_fog_max_opacity, float, "C_GradientFog", "m_flFogMaxOpacity");
	SCHEMA(m_fog_color, c_fog_material_color, "C_GradientFog", "m_fogColor");
};
