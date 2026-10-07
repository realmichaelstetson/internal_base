#pragma once

#include "../schema/schema.hpp"
#include "../../typedefs/c_handle.hpp"

struct c_byte_color {
	std::uint8_t r, g, b, a;
};

#include "c_cs_player_pawn.hpp"

class c_env_sky : public c_base_entity {
public:
	// The sky material handles are CStrongHandle<InfoForResourceTypeIMaterial2> --
	// pointer-sized fields that hold the material-resource pointer directly. Writing
	// the pointer returned by create_custom_material() into them swaps the skybox.
	SCHEMA(m_sky_material, void*, "C_EnvSky", "m_hSkyMaterial");
	SCHEMA(m_sky_material_lighting_only, void*, "C_EnvSky", "m_hSkyMaterialLightingOnly");
	SCHEMA(m_tint_color, c_byte_color, "C_EnvSky", "m_vTintColor");
	SCHEMA(m_tint_color_lighting_only, c_byte_color, "C_EnvSky", "m_vTintColorLightingOnly");
	SCHEMA(m_brightness_scale, float, "C_EnvSky", "m_flBrightnessScale");
	SCHEMA(m_fog_type, int, "C_EnvSky", "m_nFogType");
	SCHEMA(m_enabled, bool, "C_EnvSky", "m_bEnabled");
};
