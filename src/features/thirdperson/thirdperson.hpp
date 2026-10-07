#pragma once
#include "../../config.hpp"

class c_view_setup;
class c_thirdperson {
public:
	void override_view(c_view_setup* view_setup);
};

inline const auto g_thirdperson = std::make_unique<c_thirdperson>();
