#pragma once

#include "../schema/schema.hpp"
#include "../../typedefs/c_handle.hpp"

class c_player_camera_service {
public:
	SCHEMA(m_active_post_processing, c_base_handle, "CPlayer_CameraServices", "m_hActivePostProcessingVolume");
};
