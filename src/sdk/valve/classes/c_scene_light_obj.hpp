#pragma once

#include <cstdint>

class c_material_2 {
public:
	virtual const char* get_name() = 0;
	virtual const char* get_shared_name() = 0;
};

class c_scene_light_object {
public:
	char pad_0000[0xE4];
	float m_color_r;
	float m_color_g;
	float m_color_b;
	float m_color_a;
};

class c_base_scene_data {
public:
	char pad_0000[24];
	void* m_scene_object;
	c_material_2* m_material;
	c_material_2* m_material2;
	char pad_0030[32];
	std::uint8_t r;
	std::uint8_t g;
	std::uint8_t b;
	std::uint8_t a;
	char pad_0054[20];
};

class c_material_color_no_alpha {
public:
	std::uint8_t r, g, b;
};

class c_aggregate_scene_object_data {
public:
	char pad_0000[0x38];
	c_material_color_no_alpha m_color;
	char pad_003B[9];
};

class c_aggregate_scene_object_govno {
public:
	char pad_0004[4];
	int nCount;
	char pad_0008[0x28];
	int nIndex;
};

class c_aggregate_scene_object {
public:
	char pad_0000[0x120];
	int m_count;
	char pad_0124[4];
	c_aggregate_scene_object_data* m_data;
};

class c_aggregate_object_arr {
public:
	c_aggregate_scene_object* object;
	c_aggregate_scene_object_govno* data;
};

class c_draw_primitive_sky {
public:
	char pad_0000[0xA8];
	// The material the sky pass actually binds. Verified in the real binary:
	// scenesystem.dll!DrawSkyboxArray does `mov rcx, [rdi + 0xA8]` and reads its
	// shader-parameter sub-blocks from there. (The previous 0x110 guess was wrong,
	// which is why swapping it changed nothing.)
	void* m_material;       // 0xA8
	char pad_00B0[0x38];    // 0xB0
	float m_sky_color_r;    // 0xE8  (DrawSkyboxArray: movsd [rdi+0xE8])
	float m_sky_color_g;    // 0xEC
	float m_sky_color_b;    // 0xF0
	char pad_00F4[0xC];     // 0xF4
};
