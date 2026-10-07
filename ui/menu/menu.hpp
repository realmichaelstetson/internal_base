#pragma once
#include "../sdk/includes/imgui/imgui.h"
#include <memory>
#include <string>

extern float g_menu_alpha;
extern float g_sidebar_blur_x;
extern float g_sidebar_blur_y;
extern float g_sidebar_blur_w;
extern float g_sidebar_blur_h;
extern float g_watermark_blur_x;
extern float g_watermark_blur_y;
extern float g_watermark_blur_w;
extern float g_watermark_blur_h;

struct State {
    bool  aimbot          = false;
    bool  triggerbot      = false;
    bool  magnet          = false;
    bool  penetration     = false;
    bool  override_shared = false;
    int   hitbox_sel      = 0;
    int   trigger_hitbox_sel = 0;
    int   weapon_sel      = 0;
    bool  recoil_ctrl     = false;
    float fov             = 90.0f;
    float smooth          = 0.0f;
    bool  seed_pred       = false;
    float delay           = 0.0f;
    float hitchance       = 0.0f;
	bool  auto_scope                  = false;
	bool  auto_stop                   = false;
	bool  visualize_aimbot_fov        = false;
    ImVec4 visualize_aimbot_fov_color = ImVec4(1.0f, 1.0f, 1.0f, 0.5f);
    int   active_tab      = 0;
    int   visuals_subtab  = 0;
    bool   null_strafe      = false;
    bool   mousespeed_lim   = false;
    bool   ind_keybinds     = false;
    bool   ind_spectators   = false;
    bool   ind_watermark    = false;
    int    watermark_elements = 0xF;  // bit 0=name, 1=fps, 2=ping, 3=time
    bool   ind_spotify      = false;
    ImVec4 watermark_col    = ImVec4(0.686f, 0.392f, 0.784f, 1.0f);
    bool   vel_display      = false;
    ImVec4 vel_display_col1 = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);
    ImVec4 vel_display_col2 = ImVec4(1.0f, 0.7f, 0.2f, 1.0f);
    ImVec4 vel_display_col3 = ImVec4(0.2f, 1.0f, 0.2f, 1.0f);
    bool   keystrokes         = false;
    bool   vel_graph        = false;
    ImVec4 vel_graph_col    = ImVec4(0.4f, 0.7f, 1.0f, 1.0f);
    bool   jump_stats       = false;
    bool   movement_trails  = false;
    ImVec4 movement_trails_col = ImVec4(0.4f, 0.7f, 1.0f, 1.0f);
    float  ind_offset       = 67.0f;
    bool   toggle_menu      = false;
    ImVec4 menu_color       = ImVec4(0.686f, 0.392f, 0.784f, 1.0f);
    int    menu_weather     = 0;
    int    menu_theme       = 0;
    struct {
        bool enabled = false;
        int selected_weapon = 0;
        struct weapon_config_t {
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
        weapon_config_t weapon_configs[100];
    } skin_changer;
    struct {
        bool enabled = false;
        int selected_t_agent = 0;
        int selected_ct_agent = 0;
    } agent_changer;
    struct {
        bool enabled = false;
        int selected_knife = 0;
        int selected_skin = 0;
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
    } knife_changer;
    struct {
        bool enabled = false;
        bool position_enabled = false;
        float fov = 68.0f;
        float offset_x = 0.0f;
        float offset_y = 0.0f;
        float offset_z = 0.0f;
    } viewmodel_changer;
    struct {
        bool enabled = false;
        float fov = 90.0f;
    } fov_changer;
};
extern State s;
namespace Menu {
    inline bool g_open = true;
    void Render();
    void RenderSpectators();
    void RenderBinds();
    void RenderWatermark();
    void RenderSpotify();
    void RenderVelocityDisplay();
    void RenderKeystrokes();
    void RenderVelocityGraph();
    void RenderMovementTrail();
    void RenderWeatherEffects();
    void AddHitMarker(int hitgroup);
    void RenderHitMarkers();
    float GetWatermarkHeight();
}

class c_menu {
    float m_dpi_scale = 1.0f;
    ImFont* m_weapon_icon_font = nullptr;
    ImFont* m_esp_small_font = nullptr;
    ImFont* m_menu_bold_font = nullptr;
    ImFont* m_menu_title_font = nullptr;
    ImFont* m_sidebar_title_font = nullptr;
    ImFont* m_loading_title_font = nullptr;
    ImFont* m_loading_status_font = nullptr;
    ImFont* m_vel_text_font = nullptr;
    ImFont* m_keystrokes_font = nullptr;
public:
    bool m_opened = true;

    void draw();
    void on_create_move();
    void rebuild_fonts(float scale);

	bool is_open() const { return m_opened; }
    float get_dpi_scale() const { return m_dpi_scale; }
    void set_dpi_scale(float scale) { m_dpi_scale = scale; }
    ImFont* get_weapon_icon_font() const { return m_weapon_icon_font; }
    ImFont* get_esp_small_font() const { return m_esp_small_font; }
    ImFont* get_menu_bold_font() const { return m_menu_bold_font; }
    ImFont* get_menu_title_font() const { return m_menu_title_font; }
    ImFont* get_sidebar_title_font() const { return m_sidebar_title_font; }
    ImFont* get_loading_title_font() const { return m_loading_title_font; }
    ImFont* get_loading_status_font() const { return m_loading_status_font; }
    ImFont* get_vel_text_font() const { return m_vel_text_font; }
    ImFont* get_keystrokes_font() const { return m_keystrokes_font; }

};

inline const auto g_menu = std::make_unique<c_menu>();
