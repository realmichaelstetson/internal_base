#pragma once

#include <memory>

class c_base_entity;
class c_gradient_fog;

class c_fog_handler {
public:
	void fog_controller();
	void remove_fog();

private:
	c_base_entity* m_gradient_fog = nullptr;

	float m_last_start = 0.f;
	float m_last_end = 0.f;
	float m_last_falloff = 0.f;
	float m_last_color[4] = {};
};

inline const auto g_fog_handler = std::make_unique<c_fog_handler>();
