#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include "src/sdk/includes/imgui/imgui.h"

class c_config {
public:
	struct knife_changer_t {
		bool m_enabled = false;
		int m_knife = -1;
		int m_paint_kit = 0;
		float m_wear = 0.0001f;
		int m_seed = 0;
		char m_custom_name[161] = {};
		bool m_paint_color = false;
		ImVec4 m_paint_colors[4] = {
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f)
		};
	} knife_changer;

	struct glove_changer_t {
		bool m_enabled = false;
		int m_glove = -1;
		int m_paint_kit = 0;
		float m_wear = 0.0001f;
		int m_seed = 0;
		bool m_paint_color = false;
		ImVec4 m_paint_colors[8] = {
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
			ImVec4(1.0f, 1.0f, 1.0f, 1.0f)
		};
	} glove_changer;

	struct skin_changer_t {
		bool m_enabled = false;
		int m_selected_weapon = 0;

		struct weapon_skin_t {
			int paint_kit = 0;
			float wear = 0.0001f;
			int seed = 0;
			char custom_name[161] = {};
			bool paint_color = false;
			ImVec4 paint_colors[4] = {
				ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
				ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
				ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
				ImVec4(1.0f, 1.0f, 1.0f, 1.0f)
			};
		};

		weapon_skin_t weapon_skins[100];

		static int get_config_index(uint16_t def_index) {
			if (def_index >= 1 && def_index <= 70) return def_index;
			return 0;
		}
	} skin_changer;

	struct agent_changer_t {
		bool m_enabled = false;
		int m_selected_t_agent = 0;
		int m_selected_ct_agent = 0;
	} agent_changer;

	struct model_changer_t {
		bool m_enabled = false;
		int m_selected_model = 0;   // index into the runtime-scanned model list (0 = off)
	} model_changer;

	struct viewmodel_t {
		bool m_enabled = false;
		bool m_position_enabled = false;
		float m_fov = 60.0f;
		float m_offset_x = 0.0f;
		float m_offset_y = 0.0f;
		float m_offset_z = 0.0f;
	} viewmodel;

	struct fov_changer_t {
		bool m_enabled = false;
		float m_fov = 90.0f;
	} fov_changer;

	struct aim_t {
		// Per-weapon-group tuning. Every setting the "weapon group" dropdown is
		// supposed to control lives here, so each group can be configured
		// independently instead of sharing one global set of values.
		struct group_t {
			bool m_override_shared = false;   // ignored for the shared group (index 0)
			bool m_aimbot = false;
			bool m_triggerbot = false;
			bool m_magnet = false;
			bool m_penetration = false;
			int m_hitbox = 0;
			int m_trigger_hitbox = 0;
			bool m_recoil_control = false;
			float m_fov = 3.0f;
			float m_smooth = 35.0f;
			bool m_seed_prediction = false;
			float m_trigger_delay = 0.0f;
			float m_hitchance = 0.0f;
		};

		enum e_weapon_group {
			group_shared = 0,
			group_pistols,
			group_rifles,
			group_snipers,
			group_smg,
			group_shotguns,
			group_heavy,
			group_count
		};

		group_t m_groups[group_count];

		// Group currently shown/edited in the menu.
		int m_weapon_group = 0;

		// Resolve the settings that apply to a given weapon group: a non-shared
		// group is only honoured when it opts in via m_override_shared, otherwise
		// the shared group's settings apply.
		const group_t& group_for(int group_index) const {
			if (group_index > group_shared && group_index < group_count &&
				m_groups[group_index].m_override_shared)
				return m_groups[group_index];
			return m_groups[group_shared];
		}

		// True if any group that is actually in use has the given toggle enabled
		// (the shared group always applies; other groups only when overriding).
		bool any_group_has(bool group_t::* field) const {
			if (m_groups[group_shared].*field)
				return true;
			for (int i = group_shared + 1; i < group_count; ++i)
				if (m_groups[i].m_override_shared && m_groups[i].*field)
					return true;
			return false;
		}

		// Global settings, shared across every weapon group.
		std::string m_aimbot_key = "";
		int m_aimbot_mode = 1;
		std::string m_triggerbot_key = "";
		int m_triggerbot_mode = 1;
		std::string m_penetration_key = "";
		int m_penetration_mode = 1;
		bool m_visualize_aimbot_fov = false;
		ImVec4 m_visualize_aimbot_fov_color = ImVec4(1.0f, 1.0f, 1.0f, 0.5f);
		bool m_visibility_check = true;
		bool m_auto_scope = false;
		bool m_auto_stop = false;
	} aim;

	struct menu_t {
		std::string m_toggle_menu_key = "INS";
		ImVec4 m_menu_color = ImVec4(1.0f, 0.714f, 0.973f, 1.0f);
		int m_weather = 0;
		int m_theme = 0;
	} menu;

		struct indicators_t {
		bool m_keybinds = false;
		float m_binds_x = -1.0f;
		float m_binds_y = -1.0f;
		bool m_spectators = false;
		bool m_watermark = false;
		int m_watermark_elements = 0xF;  // bit 0=name, 1=fps, 2=ping, 3=time
		bool m_spotify = false;
		ImVec4 m_watermark_col = ImVec4(0.686f, 0.392f, 0.784f, 1.0f);
		bool m_velocity_display = false;
		ImVec4 m_velocity_display_col1 = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);
		ImVec4 m_velocity_display_col2 = ImVec4(1.0f, 0.7f, 0.2f, 1.0f);
		ImVec4 m_velocity_display_col3 = ImVec4(0.2f, 1.0f, 0.2f, 1.0f);
		bool m_keystrokes = false;
		bool m_velocity_graph = false;
		ImVec4 m_velocity_graph_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		bool m_jump_stats = false;
		bool m_movement_trails = false;
		ImVec4 m_movement_trails_col = ImVec4(0.4f, 0.7f, 1.0f, 1.0f);
		float m_ind_offset = 120.0f;
	} indicators;

	struct visuals_t {
		bool m_enemy_esp = false;
		bool m_box = false;
		int m_box_type = 1;
		float m_corner_length = 0.25f;
		bool m_name = false;
		bool m_weapon = false;
		int m_weapon_type = 1;
		bool m_health_bar = false;
		int m_health_type = 6;
		bool m_skeleton = false;
		bool m_ammo = false;
		int m_ammo_type = 6;
		bool m_flags = false;
		int m_flags_type = 0;
		bool m_enemy_glow = false;
		ImVec4 m_box_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_name_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_weapon_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_health_low_color = ImVec4(1.0f, 0.4f, 0.7f, 1.0f);
		ImVec4 m_health_high_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_skeleton_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_ammo_low_color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f);
		ImVec4 m_ammo_high_color = ImVec4(0.4f, 0.8f, 1.0f, 1.0f);
		ImVec4 m_flags_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_enemy_glow_color = ImVec4(1.0f, 0.25f, 0.35f, 1.0f);

		bool m_teammate_box = false;
		bool m_teammate_name = false;
		bool m_teammate_weapon = false;
		bool m_teammate_health_bar = false;
		bool m_teammate_skeleton = false;
		ImVec4 m_teammate_box_color = ImVec4(0.3f, 0.9f, 0.3f, 1.0f);
		ImVec4 m_teammate_name_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_teammate_health_low_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
		ImVec4 m_teammate_health_high_color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
		ImVec4 m_teammate_skeleton_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_teammate_weapon_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		float m_teammate_corner_length = 0.25f;
		int m_teammate_health_type = 0;
		int m_teammate_weapon_type = 0;

		bool m_weapon_drops = false;
		int m_weapon_drops_type = 0;
		ImVec4 m_weapon_drops_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

		bool m_bomb_esp = false;
		int m_bomb_esp_type = 0;
		ImVec4 m_bomb_esp_color = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);

		bool m_smoke_color = false;
		ImVec4 m_smoke_color_t = ImVec4(1.0f, 0.35f, 0.25f, 1.0f);
		ImVec4 m_smoke_color_ct = ImVec4(0.25f, 0.55f, 1.0f, 1.0f);
		bool m_grenade_trajectory = false;
		ImVec4 m_grenade_trajectory_color = ImVec4(0.35f, 0.85f, 1.0f, 1.0f);
		ImVec4 m_grenade_trajectory_end_color = ImVec4(1.0f, 0.35f, 0.35f, 1.0f);
		bool m_grenades = false;
		int m_grenades_type = 0;
		ImVec4 m_grenades_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		bool m_grenade_trails = false;

		bool m_glow = false;
		ImVec4 m_glow_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

		// Chams targets: independent visible/occluded material + colour per target.
		// Index order: 0 = enemy, 1 = teammate, 2 = arms (local viewmodel hands),
		// 3 = viewmodel (local weapon viewmodel). Material index: 0=flat 1=glow
		// 2=ghost 3=textured 4=metallic.
		struct chams_target_t {
			bool m_visible = false;
			int m_visible_material = 0;
			ImVec4 m_visible_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
			bool m_occluded = false;
			int m_occluded_material = 0;
			ImVec4 m_occluded_color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
		};
		enum { chams_target_enemy = 0, chams_target_teammate, chams_target_arms, chams_target_viewmodel, chams_target_count };
		chams_target_t m_chams_targets[chams_target_count] = {
			// enemy: white visible / red occluded (original defaults)
			{ false, 0, ImVec4(1.0f, 1.0f, 1.0f, 1.0f), false, 0, ImVec4(1.0f, 0.0f, 0.0f, 1.0f) },
			// teammate: green visible / green occluded
			{ false, 0, ImVec4(0.3f, 0.9f, 0.3f, 1.0f), false, 0, ImVec4(0.3f, 0.9f, 0.3f, 1.0f) },
			// arms: white / white
			{ false, 0, ImVec4(1.0f, 1.0f, 1.0f, 1.0f), false, 0, ImVec4(1.0f, 1.0f, 1.0f, 1.0f) },
			// viewmodel: white / white
			{ false, 0, ImVec4(1.0f, 1.0f, 1.0f, 1.0f), false, 0, ImVec4(1.0f, 1.0f, 1.0f, 1.0f) },
		};

		bool m_thirdperson = false;
		float m_thirdperson_distance = 110.0f;
		std::string m_thirdperson_key = "";
		int m_thirdperson_mode = 0;

		struct world_modulation_t {
			bool m_enable_sky = false;
			int  m_sky_index = 0;   // 0 = colour-only (no skybox swap); >0 selects a skybox
			bool m_enable_wall = false;
			bool m_enable_lighting = false;
			bool m_enable_exposure = false;
			bool m_enable_custom_fog = false;
			ImVec4 m_sky_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
			ImVec4 m_wall = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
			ImVec4 m_lighting = ImVec4(0.35f, 0.35f, 0.52f, 1.0f);
			float m_exposure = 0.20f;
			ImVec4 m_fog_color = ImVec4(0.58f, 0.62f, 0.85f, 1.0f);
			float m_fog_start = 100.0f;
			float m_fog_end = 3000.0f;
			float m_fog_falloff = 1.0f;
		} m_world_modulation;

		struct motion_blur_t {
			bool m_enabled = false;
			float m_strength = 0.45f;
		} m_motion_blur;

		bool m_world_effects = false;
		int m_world_effects_type = 0;
		float m_world_effects_density = 50.0f;

	} visuals;

	struct movement_t {
		bool m_bhop = false;
		bool m_autostrafe = false;
		bool m_jump_bug = false;
		std::string m_jump_bug_key = "";
		int m_jump_bug_mode = 1;
		bool m_mini_jump = false;
		bool m_edge_jump = false;
		std::string m_edge_jump_key = "";
		int m_edge_jump_mode = 1;
	} movement;


	struct misc_t {
		bool m_hit_logs = false;
		int m_hit_logs_type = 0;
		bool m_sounds = false;
		int m_sounds_type = 0;
		float m_sounds_volume = 100.0f;
		bool m_scope_overlay = false;
		int m_scope_type = 1;
		float m_scope_gap = 40.0f;
		float m_scope_length = 100.0f;
		ImVec4 m_scope_col_inside = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 m_scope_col_outside = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		bool m_remove_visual_recoil = false;
		bool m_hitmarker = false;
	} misc;

	struct removals_t {
		int m_effects = 0;
		bool m_fullbright = false;
		bool m_flash = false;
	} removals;
};

#define g_cfg g_config
inline const auto g_config = std::make_unique<c_config>();
