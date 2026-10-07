#pragma once

#include <memory>
#include <unordered_map>

class c_post_processing_volume;
class c_scene_light_object;
class c_base_scene_data;
class c_material_2;

class c_world {
public:
	struct light_backup_t { float r, g, b, a; };

	void exposure(c_post_processing_volume* post_processing);
	void lighting(c_scene_light_object* light);
	void aggregate_scene(c_base_scene_data* scene, int count, c_material_2* material);
	void reset();

private:
	std::unordered_map<c_scene_light_object*, light_backup_t> m_light_originals;
};

inline const auto g_world = std::make_unique<c_world>();
