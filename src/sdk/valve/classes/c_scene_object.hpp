#pragma once
#include <cstdint>
#include "c_scene_light_obj.hpp"

class c_scene_animatable_object {
public:
	std::uint8_t pad_0[0x78];
	std::uint32_t m_flags;
	std::uint8_t pad_1[0x44];
	void* m_owner;
	std::uint8_t pad_2[0x88];
};

// Colour as stored inline in a mesh primitive (4 bytes r,g,b,a). This mirrors the
// inline layout used for the DrawObject descriptor and matches the known-working
// GeneratePrimitives reference -- the slot at 0x50 is the colour itself, NOT a pointer.
struct c_mesh_primitive_color {
	std::uint8_t r, g, b, a;
};

class c_mesh_primitive {
public:
	std::uint8_t pad_0[24];                                // 0x00
	c_scene_animatable_object* m_scene_animatable_object;  // 0x18
	c_material_2* m_material;                              // 0x20
	c_material_2* m_material2;                             // 0x28
	std::uint8_t pad_1[32];                                // 0x30
	c_mesh_primitive_color m_color;                       // 0x50 (inline)
	std::uint8_t pad_2[16];                                // 0x54
	// Trailing pad is 16 (NOT 12): the whole struct is the stride get_primitive() uses
	// to index the output buffer, so it must match the game's real primitive size byte
	// for byte, or &array[i] walks off the true primitive for every i > 0. With 8-byte
	// pointer alignment this yields sizeof == 0x68, matching the known-working reference.
	// A too-small stride is why large skeletal meshes (enemy pawns, local arms) crashed
	// while the small weapon viewmodel -- often only primitive 0 -- did not.
};
static_assert(sizeof(c_mesh_primitive) == 0x68, "c_mesh_primitive stride must match the game's real primitive size");

class c_mesh_primitive_output_buffer {
public:
	c_mesh_primitive* m_mesh_primitive_array;
	std::uint8_t pad_0[4];
	int m_arr_size;

	c_mesh_primitive* get_primitive(int index) {
		return &m_mesh_primitive_array[index];
	}
};

class c_animatable_scene_object_desc {
public:
	std::uint8_t pad_0[0x10];
};
