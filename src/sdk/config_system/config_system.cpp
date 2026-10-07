#include "config_system.hpp"
#include "../../config.hpp"
#include "../../utils/utils.hpp"
#include "../../features/skin_changer/skin_changer.hpp"
#include "../../features/glove_changer/glove_changer.hpp"
#include "../includes/xor.hpp"
#include "../console/console.hpp"
#include <algorithm>
#include <iomanip>

void c_config_system::push_item(bool* pointer, const std::string& category, const std::string& name, bool default_value) {
    m_booleans.push_back({ pointer, category, name, default_value });
}

void c_config_system::push_item(int* pointer, const std::string& category, const std::string& name, int default_value) {
    m_ints.push_back({ pointer, category, name, default_value });
}

void c_config_system::push_item(float* pointer, const std::string& category, const std::string& name, float default_value) {
    m_floats.push_back({ pointer, category, name, default_value });
}

void c_config_system::push_item(std::string* pointer, const std::string& category, const std::string& name, const std::string& default_value) {
    m_strings.push_back({ pointer, category, name, default_value });
}

void c_config_system::push_char_array(char* pointer, size_t size, const std::string& category, const std::string& name) {
    m_char_arrays.push_back({ pointer, size, category, name });
}

void c_config_system::setup_values() {
    if (m_values_setup)
        return;

    std::filesystem::create_directories(m_config_path);

    push_item(&g_cfg->knife_changer.m_enabled, "knife_changer", "enabled", false);
    push_item(&g_cfg->knife_changer.m_knife, "knife_changer", "knife", 0);
    push_item(&g_cfg->knife_changer.m_paint_kit, "knife_changer", "paint_kit", 0);
    push_item(&g_cfg->knife_changer.m_wear, "knife_changer", "wear", 0.0001f);
    push_item(&g_cfg->knife_changer.m_seed, "knife_changer", "seed", 0);
    push_char_array(g_cfg->knife_changer.m_custom_name, sizeof(g_cfg->knife_changer.m_custom_name), "knife_changer", "custom_name");
    push_item(&g_cfg->knife_changer.m_paint_color, "knife_changer", "paint_color", false);
    for (int i = 0; i < 4; ++i) {
        const std::string prefix = "paint_color_" + std::to_string(i);
        push_item(&g_cfg->knife_changer.m_paint_colors[i].x, "knife_changer", prefix + "_r", 1.0f);
        push_item(&g_cfg->knife_changer.m_paint_colors[i].y, "knife_changer", prefix + "_g", 1.0f);
        push_item(&g_cfg->knife_changer.m_paint_colors[i].z, "knife_changer", prefix + "_b", 1.0f);
        push_item(&g_cfg->knife_changer.m_paint_colors[i].w, "knife_changer", prefix + "_a", 1.0f);
    }

    push_item(&g_cfg->glove_changer.m_enabled, "glove_changer", "enabled", false);
    push_item(&g_cfg->glove_changer.m_glove, "glove_changer", "glove", 0);
    push_item(&g_cfg->glove_changer.m_paint_kit, "glove_changer", "paint_kit", 0);
    push_item(&g_cfg->glove_changer.m_wear, "glove_changer", "wear", 0.0001f);
    push_item(&g_cfg->glove_changer.m_seed, "glove_changer", "seed", 0);
    push_item(&g_cfg->glove_changer.m_paint_color, "glove_changer", "paint_color", false);
    for (int i = 0; i < 8; ++i) {
        const std::string prefix = "paint_color_" + std::to_string(i);
        push_item(&g_cfg->glove_changer.m_paint_colors[i].x, "glove_changer", prefix + "_r", 1.0f);
        push_item(&g_cfg->glove_changer.m_paint_colors[i].y, "glove_changer", prefix + "_g", 1.0f);
        push_item(&g_cfg->glove_changer.m_paint_colors[i].z, "glove_changer", prefix + "_b", 1.0f);
        push_item(&g_cfg->glove_changer.m_paint_colors[i].w, "glove_changer", prefix + "_a", 1.0f);
    }

    push_item(&g_cfg->skin_changer.m_enabled, "skin_changer", "enabled", false);
    push_item(&g_cfg->skin_changer.m_selected_weapon, "skin_changer", "selected_weapon", 0);

    for (int i = 0; i < 100; i++) {
        std::string prefix = "weapon_" + std::to_string(i);
        push_item(&g_cfg->skin_changer.weapon_skins[i].paint_kit, "skin_changer", prefix + "_paint_kit", 0);
        push_item(&g_cfg->skin_changer.weapon_skins[i].wear, "skin_changer", prefix + "_wear", 0.0001f);
        push_item(&g_cfg->skin_changer.weapon_skins[i].seed, "skin_changer", prefix + "_seed", 0);
        push_char_array(g_cfg->skin_changer.weapon_skins[i].custom_name, sizeof(g_cfg->skin_changer.weapon_skins[i].custom_name), "skin_changer", prefix + "_custom_name");
        push_item(&g_cfg->skin_changer.weapon_skins[i].paint_color, "skin_changer", prefix + "_paint_color", false);
        for (int j = 0; j < 4; ++j) {
            const std::string color_prefix = prefix + "_paint_color_" + std::to_string(j);
            push_item(&g_cfg->skin_changer.weapon_skins[i].paint_colors[j].x, "skin_changer", color_prefix + "_r", 1.0f);
            push_item(&g_cfg->skin_changer.weapon_skins[i].paint_colors[j].y, "skin_changer", color_prefix + "_g", 1.0f);
            push_item(&g_cfg->skin_changer.weapon_skins[i].paint_colors[j].z, "skin_changer", color_prefix + "_b", 1.0f);
            push_item(&g_cfg->skin_changer.weapon_skins[i].paint_colors[j].w, "skin_changer", color_prefix + "_a", 1.0f);
        }
    }

    push_item(&g_cfg->agent_changer.m_enabled, "agent_changer", "enabled", false);
    push_item(&g_cfg->agent_changer.m_selected_t_agent, "agent_changer", "selected_t_agent", 0);
    push_item(&g_cfg->agent_changer.m_selected_ct_agent, "agent_changer", "selected_ct_agent", 0);

    push_item(&g_cfg->model_changer.m_enabled, "model_changer", "enabled", false);
    push_item(&g_cfg->model_changer.m_selected_model, "model_changer", "selected_model", 0);

    push_item(&g_cfg->viewmodel.m_enabled, "viewmodel", "enabled", false);
    push_item(&g_cfg->viewmodel.m_position_enabled, "viewmodel", "position_enabled", false);
    push_item(&g_cfg->viewmodel.m_fov, "viewmodel", "fov", 68.0f);
    push_item(&g_cfg->viewmodel.m_offset_x, "viewmodel", "offset_x", 0.0f);
    push_item(&g_cfg->viewmodel.m_offset_y, "viewmodel", "offset_y", 0.0f);
    push_item(&g_cfg->viewmodel.m_offset_z, "viewmodel", "offset_z", 0.0f);

    push_item(&g_cfg->fov_changer.m_enabled, "fov_changer", "enabled", false);
    push_item(&g_cfg->fov_changer.m_fov, "fov_changer", "fov", 90.0f);

    for (int g = 0; g < c_config::aim_t::group_count; ++g) {
        auto& grp = g_cfg->aim.m_groups[g];
        const std::string p = "group" + std::to_string(g) + "_";
        push_item(&grp.m_override_shared, "aim", p + "override_shared", false);
        push_item(&grp.m_aimbot, "aim", p + "aimbot", false);
        push_item(&grp.m_triggerbot, "aim", p + "triggerbot", false);
        push_item(&grp.m_magnet, "aim", p + "magnet", false);
        push_item(&grp.m_penetration, "aim", p + "penetration", false);
        push_item(&grp.m_hitbox, "aim", p + "hitbox", 0);
        push_item(&grp.m_trigger_hitbox, "aim", p + "trigger_hitbox", 0);
        push_item(&grp.m_recoil_control, "aim", p + "recoil_control", false);
        push_item(&grp.m_fov, "aim", p + "fov", 3.0f);
        push_item(&grp.m_smooth, "aim", p + "smooth", 35.0f);
        push_item(&grp.m_seed_prediction, "aim", p + "seed_prediction", false);
        push_item(&grp.m_trigger_delay, "aim", p + "trigger_delay", 0.0f);
        push_item(&grp.m_hitchance, "aim", p + "hitchance", 0.0f);
    }
    push_item(&g_cfg->aim.m_weapon_group, "aim", "weapon_group", 0);
    push_item(&g_cfg->aim.m_aimbot_key, "aim", "aimbot_key", "M1");
    push_item(&g_cfg->aim.m_aimbot_mode, "aim", "aimbot_mode", 1);
    push_item(&g_cfg->aim.m_triggerbot_key, "aim", "triggerbot_key", "ALT");
    push_item(&g_cfg->aim.m_triggerbot_mode, "aim", "triggerbot_mode", 1);
    push_item(&g_cfg->aim.m_penetration_key, "aim", "penetration_key", "ALT");
    push_item(&g_cfg->aim.m_penetration_mode, "aim", "penetration_mode", 1);
    push_item(&g_cfg->aim.m_visualize_aimbot_fov, "aim", "visualize_aimbot_fov", false);
    push_item(&g_cfg->aim.m_visualize_aimbot_fov_color.x, "aim", "visualize_aimbot_fov_color_r", 1.0f);
    push_item(&g_cfg->aim.m_visualize_aimbot_fov_color.y, "aim", "visualize_aimbot_fov_color_g", 1.0f);
    push_item(&g_cfg->aim.m_visualize_aimbot_fov_color.z, "aim", "visualize_aimbot_fov_color_b", 1.0f);
    push_item(&g_cfg->aim.m_visualize_aimbot_fov_color.w, "aim", "visualize_aimbot_fov_color_a", 0.5f);
    push_item(&g_cfg->aim.m_visibility_check, "aim", "visibility_check", false);
    push_item(&g_cfg->aim.m_auto_scope, "aim", "auto_scope", false);
    push_item(&g_cfg->aim.m_auto_stop, "aim", "auto_stop", false);

    push_item(&g_cfg->menu.m_toggle_menu_key, "menu", "toggle_menu_key", "INS");
    push_item(&g_cfg->menu.m_menu_color.x, "menu", "menu_color_r", 1.0f);
    push_item(&g_cfg->menu.m_menu_color.y, "menu", "menu_color_g", 0.714f);
    push_item(&g_cfg->menu.m_menu_color.z, "menu", "menu_color_b", 0.973f);
    push_item(&g_cfg->menu.m_menu_color.w, "menu", "menu_color_a", 1.0f);
    push_item(&g_cfg->menu.m_weather, "menu", "weather", 0);
    push_item(&g_cfg->menu.m_theme, "menu", "theme", 0);

    push_item(&g_cfg->indicators.m_keybinds, "indicators", "keybinds", false);
    push_item(&g_cfg->indicators.m_binds_x, "indicators", "binds_x", -1.0f);
    push_item(&g_cfg->indicators.m_binds_y, "indicators", "binds_y", -1.0f);
    push_item(&g_cfg->indicators.m_spectators, "indicators", "spectators", false);
    push_item(&g_cfg->indicators.m_watermark, "indicators", "watermark", false);
    push_item(&g_cfg->indicators.m_watermark_elements, "indicators", "watermark_elements", 0xF);
    push_item(&g_cfg->indicators.m_spotify, "indicators", "spotify", false);
    push_item(&g_cfg->indicators.m_watermark_col.x, "indicators", "watermark_col_r", 0.686f);
    push_item(&g_cfg->indicators.m_watermark_col.y, "indicators", "watermark_col_g", 0.392f);
    push_item(&g_cfg->indicators.m_watermark_col.z, "indicators", "watermark_col_b", 0.784f);
    push_item(&g_cfg->indicators.m_watermark_col.w, "indicators", "watermark_col_a", 1.0f);
    push_item(&g_cfg->indicators.m_velocity_display, "indicators", "velocity_display", false);
    push_item(&g_cfg->indicators.m_velocity_display_col1.x, "indicators", "velocity_display_col1_r", 1.0f);
    push_item(&g_cfg->indicators.m_velocity_display_col1.y, "indicators", "velocity_display_col1_g", 0.3f);
    push_item(&g_cfg->indicators.m_velocity_display_col1.z, "indicators", "velocity_display_col1_b", 0.3f);
    push_item(&g_cfg->indicators.m_velocity_display_col1.w, "indicators", "velocity_display_col1_a", 1.0f);
    push_item(&g_cfg->indicators.m_velocity_display_col2.x, "indicators", "velocity_display_col2_r", 1.0f);
    push_item(&g_cfg->indicators.m_velocity_display_col2.y, "indicators", "velocity_display_col2_g", 0.7f);
    push_item(&g_cfg->indicators.m_velocity_display_col2.z, "indicators", "velocity_display_col2_b", 0.2f);
    push_item(&g_cfg->indicators.m_velocity_display_col2.w, "indicators", "velocity_display_col2_a", 1.0f);
    push_item(&g_cfg->indicators.m_velocity_display_col3.x, "indicators", "velocity_display_col3_r", 0.2f);
    push_item(&g_cfg->indicators.m_velocity_display_col3.y, "indicators", "velocity_display_col3_g", 1.0f);
    push_item(&g_cfg->indicators.m_velocity_display_col3.z, "indicators", "velocity_display_col3_b", 0.2f);
    push_item(&g_cfg->indicators.m_velocity_display_col3.w, "indicators", "velocity_display_col3_a", 1.0f);
    push_item(&g_cfg->indicators.m_keystrokes, "indicators", "keystrokes", false);
    push_item(&g_cfg->indicators.m_velocity_graph, "indicators", "velocity_graph", false);
    push_item(&g_cfg->indicators.m_velocity_graph_col.x, "indicators", "velocity_graph_col_r", 0.4f);
    push_item(&g_cfg->indicators.m_velocity_graph_col.y, "indicators", "velocity_graph_col_g", 0.7f);
    push_item(&g_cfg->indicators.m_velocity_graph_col.z, "indicators", "velocity_graph_col_b", 1.0f);
    push_item(&g_cfg->indicators.m_velocity_graph_col.w, "indicators", "velocity_graph_col_a", 1.0f);
    push_item(&g_cfg->indicators.m_jump_stats, "indicators", "jump_stats", false);
    push_item(&g_cfg->indicators.m_movement_trails, "indicators", "movement_trails", false);
    push_item(&g_cfg->indicators.m_movement_trails_col.x, "indicators", "movement_trails_col_r", 0.4f);
    push_item(&g_cfg->indicators.m_movement_trails_col.y, "indicators", "movement_trails_col_g", 0.7f);
    push_item(&g_cfg->indicators.m_movement_trails_col.z, "indicators", "movement_trails_col_b", 1.0f);
    push_item(&g_cfg->indicators.m_movement_trails_col.w, "indicators", "movement_trails_col_a", 1.0f);
    push_item(&g_cfg->indicators.m_ind_offset, "indicators", "ind_offset", 67.0f);

    push_item(&g_cfg->visuals.m_enemy_esp, "visuals", "enemy_esp", false);
    push_item(&g_cfg->visuals.m_box, "visuals", "box", true);
    push_item(&g_cfg->visuals.m_box_type, "visuals", "box_type", 1);
    push_item(&g_cfg->visuals.m_corner_length, "visuals", "corner_length", 0.25f);
    push_item(&g_cfg->visuals.m_name, "visuals", "name", true);
    push_item(&g_cfg->visuals.m_weapon, "visuals", "weapon", false);
    push_item(&g_cfg->visuals.m_weapon_type, "visuals", "weapon_type", 1);
    push_item(&g_cfg->visuals.m_health_bar, "visuals", "health_bar", true);
    push_item(&g_cfg->visuals.m_health_type, "visuals", "health_type", 6);
    push_item(&g_cfg->visuals.m_skeleton, "visuals", "skeleton", false);
    push_item(&g_cfg->visuals.m_ammo, "visuals", "ammo", false);
    push_item(&g_cfg->visuals.m_ammo_type, "visuals", "ammo_type", 6);
    push_item(&g_cfg->visuals.m_flags, "visuals", "flags", false);
    push_item(&g_cfg->visuals.m_flags_type, "visuals", "flags_type", 0);
    push_item(&g_cfg->visuals.m_enemy_glow, "visuals", "enemy_glow", false);
    push_item(&g_cfg->visuals.m_box_color.x, "visuals", "box_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_box_color.y, "visuals", "box_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_box_color.z, "visuals", "box_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_box_color.w, "visuals", "box_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_name_color.x, "visuals", "name_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_name_color.y, "visuals", "name_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_name_color.z, "visuals", "name_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_name_color.w, "visuals", "name_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_weapon_color.x, "visuals", "weapon_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_weapon_color.y, "visuals", "weapon_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_weapon_color.z, "visuals", "weapon_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_weapon_color.w, "visuals", "weapon_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_health_low_color.x, "visuals", "health_low_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_health_low_color.y, "visuals", "health_low_color_g", 0.4f);
    push_item(&g_cfg->visuals.m_health_low_color.z, "visuals", "health_low_color_b", 0.7f);
    push_item(&g_cfg->visuals.m_health_low_color.w, "visuals", "health_low_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_health_high_color.x, "visuals", "health_high_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_health_high_color.y, "visuals", "health_high_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_health_high_color.z, "visuals", "health_high_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_health_high_color.w, "visuals", "health_high_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_skeleton_color.x, "visuals", "skeleton_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_skeleton_color.y, "visuals", "skeleton_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_skeleton_color.z, "visuals", "skeleton_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_skeleton_color.w, "visuals", "skeleton_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_ammo_low_color.x, "visuals", "ammo_low_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_ammo_low_color.y, "visuals", "ammo_low_color_g", 0.4f);
    push_item(&g_cfg->visuals.m_ammo_low_color.z, "visuals", "ammo_low_color_b", 0.4f);
    push_item(&g_cfg->visuals.m_ammo_low_color.w, "visuals", "ammo_low_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_ammo_high_color.x, "visuals", "ammo_high_color_r", 0.4f);
    push_item(&g_cfg->visuals.m_ammo_high_color.y, "visuals", "ammo_high_color_g", 0.8f);
    push_item(&g_cfg->visuals.m_ammo_high_color.z, "visuals", "ammo_high_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_ammo_high_color.w, "visuals", "ammo_high_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_flags_color.x, "visuals", "flags_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_flags_color.y, "visuals", "flags_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_flags_color.z, "visuals", "flags_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_flags_color.w, "visuals", "flags_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_enemy_glow_color.x, "visuals", "enemy_glow_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_enemy_glow_color.y, "visuals", "enemy_glow_color_g", 0.25f);
    push_item(&g_cfg->visuals.m_enemy_glow_color.z, "visuals", "enemy_glow_color_b", 0.35f);
    push_item(&g_cfg->visuals.m_enemy_glow_color.w, "visuals", "enemy_glow_color_a", 1.0f);

    push_item(&g_cfg->visuals.m_teammate_box, "visuals", "teammate_box", false);
    push_item(&g_cfg->visuals.m_teammate_name, "visuals", "teammate_name", false);
    push_item(&g_cfg->visuals.m_teammate_weapon, "visuals", "teammate_weapon", false);
    push_item(&g_cfg->visuals.m_teammate_health_bar, "visuals", "teammate_health_bar", false);
    push_item(&g_cfg->visuals.m_teammate_skeleton, "visuals", "teammate_skeleton", false);
    push_item(&g_cfg->visuals.m_teammate_box_color.x, "visuals", "teammate_box_color_r", 0.3f);
    push_item(&g_cfg->visuals.m_teammate_box_color.y, "visuals", "teammate_box_color_g", 0.9f);
    push_item(&g_cfg->visuals.m_teammate_box_color.z, "visuals", "teammate_box_color_b", 0.3f);
    push_item(&g_cfg->visuals.m_teammate_box_color.w, "visuals", "teammate_box_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_name_color.x, "visuals", "teammate_name_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_name_color.y, "visuals", "teammate_name_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_name_color.z, "visuals", "teammate_name_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_name_color.w, "visuals", "teammate_name_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_health_low_color.x, "visuals", "teammate_health_low_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_health_low_color.y, "visuals", "teammate_health_low_color_g", 0.0f);
    push_item(&g_cfg->visuals.m_teammate_health_low_color.z, "visuals", "teammate_health_low_color_b", 0.0f);
    push_item(&g_cfg->visuals.m_teammate_health_low_color.w, "visuals", "teammate_health_low_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_health_high_color.x, "visuals", "teammate_health_high_color_r", 0.0f);
    push_item(&g_cfg->visuals.m_teammate_health_high_color.y, "visuals", "teammate_health_high_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_health_high_color.z, "visuals", "teammate_health_high_color_b", 0.0f);
    push_item(&g_cfg->visuals.m_teammate_health_high_color.w, "visuals", "teammate_health_high_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_skeleton_color.x, "visuals", "teammate_skeleton_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_skeleton_color.y, "visuals", "teammate_skeleton_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_skeleton_color.z, "visuals", "teammate_skeleton_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_skeleton_color.w, "visuals", "teammate_skeleton_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_weapon_color.x, "visuals", "teammate_weapon_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_weapon_color.y, "visuals", "teammate_weapon_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_weapon_color.z, "visuals", "teammate_weapon_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_weapon_color.w, "visuals", "teammate_weapon_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_teammate_corner_length, "visuals", "teammate_corner_length", 0.25f);
    push_item(&g_cfg->visuals.m_teammate_health_type, "visuals", "teammate_health_type", 0);
    push_item(&g_cfg->visuals.m_teammate_weapon_type, "visuals", "teammate_weapon_type", 0);

    push_item(&g_cfg->visuals.m_weapon_drops, "visuals", "weapon_drops", false);
    push_item(&g_cfg->visuals.m_weapon_drops_type, "visuals", "weapon_drops_type", 0);
    push_item(&g_cfg->visuals.m_weapon_drops_color.x, "visuals", "weapon_drops_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_weapon_drops_color.y, "visuals", "weapon_drops_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_weapon_drops_color.z, "visuals", "weapon_drops_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_weapon_drops_color.w, "visuals", "weapon_drops_color_a", 1.0f);

    push_item(&g_cfg->visuals.m_bomb_esp, "visuals", "bomb_esp", false);
    push_item(&g_cfg->visuals.m_bomb_esp_type, "visuals", "bomb_esp_type", 0);
    push_item(&g_cfg->visuals.m_bomb_esp_color.x, "visuals", "bomb_esp_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_bomb_esp_color.y, "visuals", "bomb_esp_color_g", 0.3f);
    push_item(&g_cfg->visuals.m_bomb_esp_color.z, "visuals", "bomb_esp_color_b", 0.3f);
    push_item(&g_cfg->visuals.m_bomb_esp_color.w, "visuals", "bomb_esp_color_a", 1.0f);

    push_item(&g_cfg->visuals.m_smoke_color, "visuals", "smoke_color", false);
    push_item(&g_cfg->visuals.m_smoke_color_t.x, "visuals", "smoke_color_t_r", 1.0f);
    push_item(&g_cfg->visuals.m_smoke_color_t.y, "visuals", "smoke_color_t_g", 0.35f);
    push_item(&g_cfg->visuals.m_smoke_color_t.z, "visuals", "smoke_color_t_b", 0.25f);
    push_item(&g_cfg->visuals.m_smoke_color_t.w, "visuals", "smoke_color_t_a", 1.0f);
    push_item(&g_cfg->visuals.m_smoke_color_ct.x, "visuals", "smoke_color_ct_r", 0.25f);
    push_item(&g_cfg->visuals.m_smoke_color_ct.y, "visuals", "smoke_color_ct_g", 0.55f);
    push_item(&g_cfg->visuals.m_smoke_color_ct.z, "visuals", "smoke_color_ct_b", 1.0f);
    push_item(&g_cfg->visuals.m_smoke_color_ct.w, "visuals", "smoke_color_ct_a", 1.0f);
    push_item(&g_cfg->visuals.m_grenade_trajectory, "visuals", "grenade_trajectory", false);
    push_item(&g_cfg->visuals.m_grenade_trajectory_color.x, "visuals", "grenade_trajectory_color_r", 0.35f);
    push_item(&g_cfg->visuals.m_grenade_trajectory_color.y, "visuals", "grenade_trajectory_color_g", 0.85f);
    push_item(&g_cfg->visuals.m_grenade_trajectory_color.z, "visuals", "grenade_trajectory_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_grenade_trajectory_color.w, "visuals", "grenade_trajectory_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_grenade_trajectory_end_color.x, "visuals", "grenade_trajectory_end_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_grenade_trajectory_end_color.y, "visuals", "grenade_trajectory_end_color_g", 0.35f);
    push_item(&g_cfg->visuals.m_grenade_trajectory_end_color.z, "visuals", "grenade_trajectory_end_color_b", 0.35f);
    push_item(&g_cfg->visuals.m_grenade_trajectory_end_color.w, "visuals", "grenade_trajectory_end_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_grenades, "visuals", "grenades", false);
    push_item(&g_cfg->visuals.m_grenades_type, "visuals", "grenades_type", 0);
    push_item(&g_cfg->visuals.m_grenades_color.x, "visuals", "grenades_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_grenades_color.y, "visuals", "grenades_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_grenades_color.z, "visuals", "grenades_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_grenades_color.w, "visuals", "grenades_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_grenade_trails, "visuals", "grenade_trails", false);

    push_item(&g_cfg->visuals.m_glow, "visuals", "glow", false);
    push_item(&g_cfg->visuals.m_glow_color.x, "visuals", "glow_color_r", 0.4f);
    push_item(&g_cfg->visuals.m_glow_color.y, "visuals", "glow_color_g", 0.8f);
    push_item(&g_cfg->visuals.m_glow_color.z, "visuals", "glow_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_glow_color.w, "visuals", "glow_color_a", 1.0f);
    // Chams targets. Enemy (index 0) keeps its original flat keys ("chams_*") for
    // backward compatibility; the other targets get a prefixed key set.
    {
        const char* chams_prefix[c_config::visuals_t::chams_target_count] = {
            "chams", "teammate_chams", "arms_chams", "viewmodel_chams"
        };
        for (int t = 0; t < c_config::visuals_t::chams_target_count; ++t) {
            auto& tgt = g_cfg->visuals.m_chams_targets[t];
            const std::string p = chams_prefix[t];
            push_item(&tgt.m_visible, "visuals", p + "_visible", tgt.m_visible);
            push_item(&tgt.m_visible_material, "visuals", p + "_visible_material", tgt.m_visible_material);
            push_item(&tgt.m_visible_color.x, "visuals", p + "_visible_color_r", tgt.m_visible_color.x);
            push_item(&tgt.m_visible_color.y, "visuals", p + "_visible_color_g", tgt.m_visible_color.y);
            push_item(&tgt.m_visible_color.z, "visuals", p + "_visible_color_b", tgt.m_visible_color.z);
            push_item(&tgt.m_visible_color.w, "visuals", p + "_visible_color_a", tgt.m_visible_color.w);
            push_item(&tgt.m_occluded, "visuals", p + "_occluded", tgt.m_occluded);
            push_item(&tgt.m_occluded_material, "visuals", p + "_occluded_material", tgt.m_occluded_material);
            push_item(&tgt.m_occluded_color.x, "visuals", p + "_occluded_color_r", tgt.m_occluded_color.x);
            push_item(&tgt.m_occluded_color.y, "visuals", p + "_occluded_color_g", tgt.m_occluded_color.y);
            push_item(&tgt.m_occluded_color.z, "visuals", p + "_occluded_color_b", tgt.m_occluded_color.z);
            push_item(&tgt.m_occluded_color.w, "visuals", p + "_occluded_color_a", tgt.m_occluded_color.w);
        }
    }

    push_item(&g_cfg->visuals.m_thirdperson, "visuals", "thirdperson", false);
    push_item(&g_cfg->visuals.m_thirdperson_distance, "visuals", "thirdperson_distance", 110.0f);
    push_item(&g_cfg->visuals.m_thirdperson_key, "visuals", "thirdperson_key", "");
    push_item(&g_cfg->visuals.m_thirdperson_mode, "visuals", "thirdperson_mode", 0);

    push_item(&g_cfg->visuals.m_world_effects, "visuals", "world_effects", false);
    push_item(&g_cfg->visuals.m_world_effects_type, "visuals", "world_effects_type", 0);
    push_item(&g_cfg->visuals.m_world_effects_density, "visuals", "world_effects_density", 50.0f);

    push_item(&g_cfg->visuals.m_world_modulation.m_enable_wall, "visuals", "world_modulation_enable_wall", false);
    push_item(&g_cfg->visuals.m_world_modulation.m_enable_lighting, "visuals", "world_modulation_enable_lighting", false);
    push_item(&g_cfg->visuals.m_world_modulation.m_enable_exposure, "visuals", "world_modulation_enable_exposure", false);
    push_item(&g_cfg->visuals.m_world_modulation.m_wall.x, "visuals", "world_modulation_wall_r", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_wall.y, "visuals", "world_modulation_wall_g", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_wall.z, "visuals", "world_modulation_wall_b", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_wall.w, "visuals", "world_modulation_wall_a", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_lighting.x, "visuals", "world_modulation_lighting_r", 0.35f);
    push_item(&g_cfg->visuals.m_world_modulation.m_lighting.y, "visuals", "world_modulation_lighting_g", 0.35f);
    push_item(&g_cfg->visuals.m_world_modulation.m_lighting.z, "visuals", "world_modulation_lighting_b", 0.52f);
    push_item(&g_cfg->visuals.m_world_modulation.m_lighting.w, "visuals", "world_modulation_lighting_a", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_exposure, "visuals", "world_modulation_exposure", 0.20f);
    push_item(&g_cfg->visuals.m_world_modulation.m_enable_custom_fog, "visuals", "world_modulation_enable_custom_fog", false);
    push_item(&g_cfg->visuals.m_world_modulation.m_fog_color.x, "visuals", "world_modulation_fog_color_r", 0.58f);
    push_item(&g_cfg->visuals.m_world_modulation.m_fog_color.y, "visuals", "world_modulation_fog_color_g", 0.62f);
    push_item(&g_cfg->visuals.m_world_modulation.m_fog_color.z, "visuals", "world_modulation_fog_color_b", 0.85f);
    push_item(&g_cfg->visuals.m_world_modulation.m_fog_color.w, "visuals", "world_modulation_fog_color_a", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_fog_start, "visuals", "world_modulation_fog_start", 100.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_fog_falloff, "visuals", "world_modulation_fog_falloff", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_enable_sky, "visuals", "world_modulation_enable_sky", false);
    push_item(&g_cfg->visuals.m_world_modulation.m_sky_index, "visuals", "world_modulation_sky_index", 0);
    push_item(&g_cfg->visuals.m_world_modulation.m_sky_color.x, "visuals", "world_modulation_sky_color_r", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_sky_color.y, "visuals", "world_modulation_sky_color_g", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_sky_color.z, "visuals", "world_modulation_sky_color_b", 1.0f);
    push_item(&g_cfg->visuals.m_world_modulation.m_sky_color.w, "visuals", "world_modulation_sky_color_a", 1.0f);

    push_item(&g_cfg->movement.m_bhop, "movement", "bhop", false);
    push_item(&g_cfg->movement.m_autostrafe, "movement", "autostrafe", true);
    push_item(&g_cfg->movement.m_jump_bug, "movement", "jump_bug", false);
    push_item(&g_cfg->movement.m_jump_bug_key, "movement", "jump_bug_key", "M4");
    push_item(&g_cfg->movement.m_jump_bug_mode, "movement", "jump_bug_mode", 1);
    push_item(&g_cfg->movement.m_edge_jump, "movement", "edge_jump", false);
    push_item(&g_cfg->movement.m_edge_jump_key, "movement", "edge_jump_key", "");
    push_item(&g_cfg->movement.m_edge_jump_mode, "movement", "edge_jump_mode", 1);

    push_item(&g_cfg->misc.m_hit_logs, "misc", "hit_logs", true);
    push_item(&g_cfg->misc.m_hit_logs_type, "misc", "hit_logs_type", 0);
    push_item(&g_cfg->misc.m_hitmarker, "misc", "hitmarker", false);
    push_item(&g_cfg->misc.m_sounds, "misc", "sounds", true);
    push_item(&g_cfg->misc.m_sounds_type, "misc", "sounds_type", 0);
    push_item(&g_cfg->misc.m_sounds_volume, "misc", "sounds_volume", 30.0f);
    push_item(&g_cfg->misc.m_scope_overlay, "misc", "scope_overlay", false);
    push_item(&g_cfg->misc.m_scope_type, "misc", "scope_type", 1);
    push_item(&g_cfg->misc.m_scope_gap, "misc", "scope_gap", 40.0f);
    push_item(&g_cfg->misc.m_scope_length, "misc", "scope_length", 100.0f);
    push_item(&g_cfg->misc.m_scope_col_inside.x, "misc", "scope_col_inside_r", 1.0f);
    push_item(&g_cfg->misc.m_scope_col_inside.y, "misc", "scope_col_inside_g", 1.0f);
    push_item(&g_cfg->misc.m_scope_col_inside.z, "misc", "scope_col_inside_b", 1.0f);
    push_item(&g_cfg->misc.m_scope_col_inside.w, "misc", "scope_col_inside_a", 1.0f);
    push_item(&g_cfg->misc.m_scope_col_outside.x, "misc", "scope_col_outside_r", 1.0f);
    push_item(&g_cfg->misc.m_scope_col_outside.y, "misc", "scope_col_outside_g", 1.0f);
    push_item(&g_cfg->misc.m_scope_col_outside.z, "misc", "scope_col_outside_b", 1.0f);
    push_item(&g_cfg->misc.m_scope_col_outside.w, "misc", "scope_col_outside_a", 1.0f);
    push_item(&g_cfg->misc.m_remove_visual_recoil, "misc", "remove_visual_recoil", false);


	push_item(&g_cfg->removals.m_effects, "removals", "effects", 0);
	push_item(&g_cfg->removals.m_fullbright, "removals", "fullbright", false);
    push_item(&g_cfg->removals.m_flash, "removals", "flash", false);

    m_values_setup = true;
    refresh();
}

void c_config_system::save(const std::string& name) {
    if (name.empty())
        return;

    setup_values();

    try {
        std::filesystem::create_directories(m_config_path);
    }
    catch (const std::exception& e) {
        (void)e;
        LOG_ERROR(xorstr_("[config] failed to create directory: %s"), e.what());
        return;
    }

    std::string path = m_config_path + name + ".clr";

    json data;

    try {

        for (auto& item : m_booleans) {
            if (item.pointer)
                data[item.category][item.name] = *item.pointer;
        }

        for (auto& item : m_ints) {
            if (item.pointer)
                data[item.category][item.name] = *item.pointer;
        }

        for (auto& item : m_floats) {
            if (item.pointer)
                data[item.category][item.name] = *item.pointer;
        }

        for (auto& item : m_strings) {
            if (item.pointer)
                data[item.category][item.name] = *item.pointer;
        }

        for (auto& item : m_char_arrays) {
            if (item.pointer && item.size > 0)
                data[item.category][item.name] = std::string(item.pointer);
        }
    }
    catch (const std::exception& e) {
        (void)e;
        LOG_ERROR(xorstr_("[config] failed to serialize data: %s"), e.what());
        return;
    }

    try {
        std::ofstream file(path);
        if (file.is_open()) {
            file << std::setw(4) << data << std::endl;
            file.close();
        }
        else {
            LOG_ERROR(xorstr_("[config] failed to open for writing: %s"), path.c_str());
            return;
        }
    }
    catch (const std::exception& e) {
        (void)e;
        LOG_ERROR(xorstr_("[config] failed to write file: %s"), e.what());
        return;
    }

    refresh();
}

void c_config_system::load(const std::string& name) {
    if (name.empty())
        return;

    setup_values();

    std::string path = m_config_path + name + ".clr";

    if (!std::filesystem::exists(path))
        return;

    std::ifstream file(path);
    if (!file.is_open())
        return;

    json data;
    try {
        file >> data;
    }
    catch (const std::exception& e) {
        (void)e;
        LOG_ERROR(xorstr_("[config] failed to parse %s: %s"), name.c_str(), e.what());
        file.close();
        return;
    }
    file.close();

    for (auto& item : m_booleans) {
        if (data.contains(item.category) && data[item.category].contains(item.name)) {
            auto& val = data[item.category][item.name];
            if (val.is_boolean())
                *item.pointer = val.get<bool>();
        }
    }

    for (auto& item : m_ints) {
        if (data.contains(item.category) && data[item.category].contains(item.name)) {
            auto& val = data[item.category][item.name];
            if (val.is_number_integer())
                *item.pointer = val.get<int>();
        }
    }

    for (auto& item : m_floats) {
        if (data.contains(item.category) && data[item.category].contains(item.name)) {
            auto& val = data[item.category][item.name];
            if (val.is_number())
                *item.pointer = val.get<float>();
        }
    }

    for (auto& item : m_strings) {
        if (data.contains(item.category) && data[item.category].contains(item.name)) {
            auto& val = data[item.category][item.name];
            if (val.is_string())
                *item.pointer = val.get<std::string>();
        }
    }

    for (auto& item : m_char_arrays) {
        if (data.contains(item.category) && data[item.category].contains(item.name)) {
            auto& val = data[item.category][item.name];
            if (val.is_string()) {
                std::string value = val.get<std::string>();
                strncpy_s(item.pointer, item.size, value.c_str(), _TRUNCATE);
            }
        }
    }

    g_skin_changer->request_update();
    g_glove_changer->request_update(true);
}

void c_config_system::remove(const std::string& name) {
    if (name.empty())
        return;

    setup_values();

    std::filesystem::create_directories(m_config_path);

    std::string path = m_config_path + name + ".clr";

    if (std::filesystem::exists(path))
        std::filesystem::remove(path);

    refresh();
}

void c_config_system::reset() {
    setup_values();

    for (auto& item : m_booleans)
        *item.pointer = item.default_value;

    for (auto& item : m_ints)
        *item.pointer = item.default_value;

    for (auto& item : m_floats)
        *item.pointer = item.default_value;

    for (auto& item : m_strings)
        *item.pointer = item.default_value;

    for (auto& item : m_char_arrays) {
        if (item.pointer && item.size > 0)
            memset(item.pointer, 0, item.size);
    }
}

void c_config_system::refresh() {
    m_config_files.clear();

    std::filesystem::create_directories(m_config_path);

    if (!std::filesystem::exists(m_config_path))
        return;

    for (const auto& entry : std::filesystem::directory_iterator(m_config_path)) {
        if (!entry.is_regular_file())
            continue;

        if (entry.path().extension() != ".clr")
            continue;

        std::string filename = entry.path().stem().string();
        m_config_files.push_back(filename);
    }

    std::sort(m_config_files.begin(), m_config_files.end());
}
