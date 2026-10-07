#include "../../src/core/main.hpp"
#include "menu.hpp"
#include "../assets/SFProText-Semibold.hpp"
#include "../assets/sfpro-bold.hpp"
#include "../../src/sdk/includes/imgui/imgui.h"
#include "../../src/sdk/includes/imgui/imgui_internal.h"
#include "elements/elements.h"
#include "../../src/features/shared/item_schema.hpp"
#include "../../src/features/shared/vtex_parser.hpp"
#include "../../src/features/skin_changer/skin_changer.hpp"
#include "../../src/features/glove_changer/glove_changer.hpp"
#include "../../src/features/model_changer/model_changer.hpp"
#include "../../src/features/chams/chams_material.hpp"
#include "../../src/sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../src/sdk/valve/classes/game_enums.hpp"
#include "../../src/sdk/config_system/config_system.hpp"
#include "../../src/sdk/offsets.hpp"
#include "../assets/obs_icons.hpp"
#include "../assets/esp_font_5x5.hpp"
#include "../assets/FontAwesome.h"
#include "../assets/fontawesome_binary.hpp"


#include "../../src/directx/directx.hpp"
#include "../../ui/assets/blur.hpp"

#include "../../src/features/sounds/hit_sound.hpp"
#include "../../src/config.hpp"
#include <windows.h>
#include <tlhelp32.h>
#include <shellapi.h>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <filesystem>
#include <atomic>
#include <vector>
#include <string>
#include <unordered_map>

static const float MENU_W    = 525.0f;
static const float MENU_H    = 500.0f;
static const float TAB_H     = 26.0f;
static const float TITLE_H   = 26.0f;
static const float SIDEBAR_W = 180.0f;
static const float PADDING   = 26.0f;
static const float L_W       = 225.0f;
static const float GAP       = 26.0f;
static const float R_X       = PADDING + L_W + GAP;
static const float R_W       = MENU_W - R_X - PADDING;
static const float BOX_PAD   = 16.0f;
static const float COLOR_PICKER_STEP = 25.0f;
State s;
float g_menu_alpha = 1.0f;
float g_sidebar_blur_x = 0.0f;
float g_sidebar_blur_y = 0.0f;
float g_sidebar_blur_w = 0.0f;
float g_sidebar_blur_h = 0.0f;
static const char* k_hitboxes[]  = { "head", "neck", "chest", "stomach", "pelvis" };
static const char* k_group_names[] = { "shared", "pistols", "rifles", "snipers", "smg", "shotguns", "heavy" };
static const char* k_tabs[]      = { "visuals", "skins", "world", "misc", "config" };
static const char* k_visuals_subtabs[] = { "enemy", "friendly", "extra" };

static std::vector<std::string> s_cfg_list;
static int                      s_cfg_sel   = -1;
static char                     s_cfg_input[64] = {};
static char                     s_cfg_search[64] = {};
static bool                     s_cfg_dirty = true;
static float                    s_cfg_refresh_timer = 0.0f;
static float                    s_cfg_scroll_y = 0.0f;
static bool                     s_skip_skin_sync_to_config = false;
static bool                     s_menu_synced_from_config = false;
static bool                     s_aim_synced_from_config = false;
static bool                     s_movement_synced_from_config = false;
static bool                     s_indicators_synced_from_config = false;
static bool                     s_visuals_synced_from_config = false;
static bool                     s_menu_target_open = true;
static float                    g_binds_window_x = -1.0f;
static float                    g_binds_window_y = -1.0f;
static bool                     g_binds_window_dragging = false;
static ImVec2                   g_binds_drag_offset;
static bool                     g_menu_dragging = false;
static ImVec2                   g_menu_drag_offset;
static float                    g_watermark_x = -1.0f;
static float                    g_watermark_y = -1.0f;
static bool                     g_watermark_dragging = false;
static ImVec2                   g_watermark_drag_offset;

// Exposed to hooks.cpp so it can apply background blur before new_frame().
float g_watermark_blur_x = 0.0f;
float g_watermark_blur_y = 0.0f;
float g_watermark_blur_w = 0.0f;
float g_watermark_blur_h = 0.0f;

static float                    g_spotify_x = -1.0f;
static float                    g_spotify_y = -1.0f;
static bool                     g_spotify_dragging = false;
static ImVec2                   g_spotify_drag_offset;
static bool                     s_models_dragging = false;
static float                    s_models_drag_start_y = 0.0f;
static float                    s_models_drag_scroll = 0.0f;
static bool                     s_skin_dragging = false;
static float                    s_skin_drag_start_y = 0.0f;
static float                    s_skin_drag_scroll = 0.0f;
// Separate, draggable skin-preview window (skins tab only). Position is
// remembered for the session; -1 means "not yet placed" (defaults next to menu).
static bool                     s_skin_preview_dragging = false;
static float                    s_skin_preview_x = -1.0f;
static float                    s_skin_preview_y = -1.0f;
static ImVec2                   s_skin_preview_drag_off = ImVec2(0.0f, 0.0f);
static bool                     s_esp_dragging = false;
static float                    s_esp_drag_start_y = 0.0f;
static float                    s_esp_drag_scroll = 0.0f;
static bool                     s_move_dragging = false;
static float                    s_move_drag_start_y = 0.0f;
static float                    s_move_drag_scroll = 0.0f;
static bool                     s_misc_dragging = false;
static float                    s_misc_drag_start_y = 0.0f;
static float                    s_misc_drag_scroll = 0.0f;
static float                    s_env_scroll_y = 0.0f;
static bool                     s_env_dragging = false;
static float                    s_env_drag_start_y = 0.0f;
static float                    s_env_drag_scroll = 0.0f;
static float                    s_friend_scroll_y = 0.0f;
static bool                     s_friend_dragging = false;
static float                    s_friend_drag_start_y = 0.0f;
static float                    s_friend_drag_scroll = 0.0f;
static float                    s_tchams_scroll_y = 0.0f;
static bool                     s_tchams_dragging = false;
static float                    s_tchams_drag_start_y = 0.0f;
static float                    s_tchams_drag_scroll = 0.0f;
// --- smooth scrolling ------------------------------------------------------
// Each scroll box keeps an animated "current" value (s_*_scroll_y) that eases
// toward a per-box target. Wheel input nudges the target; the thumb drag sets
// it directly. ScrollEase() must be called once per frame per box.
static std::unordered_map<const float*, float> g_scroll_targets;
static inline float& ScrollTarget(float& cur) {
    auto it = g_scroll_targets.find(&cur);
    if (it == g_scroll_targets.end())
        it = g_scroll_targets.emplace(&cur, cur).first;
    return it->second;
}
static inline void ScrollEase(float& cur, float max_scroll) {
    float& tgt = ScrollTarget(cur);
    tgt = ImClamp(tgt, 0.0f, max_scroll);
    float dt = ImGui::GetIO().DeltaTime;
    if (dt <= 0.0f) { cur = tgt; return; }
    float a = 1.0f - expf(-dt * 16.0f);
    cur += (tgt - cur) * a;
    if (fabsf(tgt - cur) < 0.5f) cur = tgt;
}

static std::vector<float>       g_velocity_history;
static const int                MAX_VELOCITY_SAMPLES = 300;
static float                    g_spectators_x = -1.0f;
static float                    g_spectators_y = -1.0f;
static bool                     g_spectators_dragging = false;
static ImVec2                   g_spectators_drag_offset;
static float                    g_last_jump_distance = 0.0f;
static int                      g_last_jump_strafes = 0;
static float                    g_last_jump_sync = 0.0f;
static bool                     g_was_on_ground = true;
static vec3_t                   g_jump_start_pos;
static int                      g_current_strafes = 0;
static int                      g_good_strafes = 0;
static float                    g_last_yaw = 0.0f;

struct TrailPoint {
    vec3_t pos;
    std::chrono::steady_clock::time_point time;
};
static std::vector<TrailPoint>  g_trail_positions;
static constexpr float          TRAIL_DURATION = 3.0f;

static float* trail_view_matrix() {
    static const auto view_matrix = reinterpret_cast<float*>(
        g_opcodes->scan_absolute(
            g_modules->m_modules.client_dll.get_name(),
            "48 8D 0D ? ? ? ? 48 89 44 24 ? 48 89 4C 24 ? 4C 8D 0D",
            0x3
        )
    );
    return view_matrix;
}

static bool trail_world_to_screen(const vec3_t& in, ImVec2& out) {
    float* matrix = trail_view_matrix();
    if (!matrix) return false;
    const float w = matrix[12] * in.x + matrix[13] * in.y + matrix[14] * in.z + matrix[15];
    if (w < 0.0001f) return false;
    const float x = matrix[0] * in.x + matrix[1] * in.y + matrix[2] * in.z + matrix[3];
    const float y = matrix[4] * in.x + matrix[5] * in.y + matrix[6] * in.z + matrix[7];
    const ImVec2 display = ImGui::GetIO().DisplaySize;
    out.x = (display.x * 0.5f) + ((x / w) * display.x * 0.5f);
    out.y = (display.y * 0.5f) - ((y / w) * display.y * 0.5f);
    return std::isfinite(out.x) && std::isfinite(out.y);
}

static const char* k_cfg_dir = "C:\\celerity\\configs\\";

static void ApplyTheme() {
    if (s.menu_theme == 1) {
        Colors::Bg           = IM_COL32(9,   9,   14,  255);
        Colors::TitleBg      = IM_COL32(7,   7,   12,  255);
        Colors::Text         = IM_COL32(145, 148, 160, 255);
        Colors::TextBright   = IM_COL32(225, 228, 240, 255);
        Colors::TextDim      = IM_COL32(110, 115, 130, 255);
        Colors::TextBind     = IM_COL32(110, 115, 130, 255);
        Colors::Section      = IM_COL32(75,  78,  95,  255);
        Colors::CbBg         = IM_COL32(16,  16,  24,  255);
        Colors::CbBorder     = IM_COL32(48,  50,  65,  255);
        Colors::SliderTrack  = IM_COL32(24,  25,  34,  255);
        Colors::DropdownBg   = IM_COL32(14,  15,  22,  255);
        Colors::DropdownBord = IM_COL32(46,  48,  62,  255);
        Colors::Divider      = IM_COL32(42,  44,  58,  255);
        Colors::TabBg        = IM_COL32(6,   6,   12,  255);
        Colors::ColHdr       = IM_COL32(145, 148, 160, 255);
        Colors::ColHdrLine   = IM_COL32(20,  22,  30,  255);
        Colors::SectionBg    = IM_COL32(9,   9,   14,  255);
        Colors::SectionBorder = IM_COL32(20,  22,  30,  255);
        Colors::MenuBg       = IM_COL32(5,   5,   10,  255);
        Colors::MenuTitleGradTop = IM_COL32(28, 28, 38, 255);
        Colors::MenuTitleGradBot = IM_COL32(5,   5,   10, 255);
        Colors::MenuTitleText = IM_COL32(255, 255, 255, 255);
        Colors::BoxBorder     = IM_COL32(24,  26,  34,  255);
        Colors::BoxInnerBorder = IM_COL32(0,   0,   5,   255);
        Colors::SideStrip     = IM_COL32(24,  26,  34,  255);
        Colors::ListBg        = IM_COL32(14,  15,  22,  255);
        Colors::ScrollbarTrack = IM_COL32(24, 26,  34,  255);
        Colors::ScrollbarGrab  = IM_COL32(36,  38,  50,  255);
        Colors::ScrollbarGrabHover = IM_COL32(36,  38,  50,  255);
        Colors::ScrollbarGrabActive = IM_COL32(36,  38,  50,  255);
        Colors::InputBg      = IM_COL32(14,  15,  22,  255);
        Colors::ButtonBgTop  = IM_COL32(22,  24,  32,  255);
        Colors::ButtonBgBot  = IM_COL32(14,  15,  22,  255);
        Colors::BindBg       = IM_COL32(9,   9,   16,  255);
        Colors::ButtonHeldTop = IM_COL32(14,  15,  22,  255);
        Colors::ButtonHeldBot = IM_COL32(8,   8,   14,  255);
        Colors::ButtonBorder  = IM_COL32(0,   0,   4,   255);
        Colors::DropdownGradTop = IM_COL32(22, 24,  32,  255);
        Colors::DropdownGradBot = IM_COL32(14, 15,  22,  255);
        Colors::CheckboxBg    = IM_COL32(20,  22,  30,  255);
        Colors::SliderValueBg = IM_COL32(28,  30,  40,  255);
        Colors::BindItemBg    = IM_COL32(20,  22,  30,  255);
        Colors::BindItemText  = IM_COL32(138, 140, 158, 255);
        Colors::TabSeparator  = IM_COL32(60,  62,  80,  90);
    } else if (s.menu_theme == 2) {
        Colors::Bg           = IM_COL32(0,   0,   0,   255);
        Colors::TitleBg      = IM_COL32(0,   0,   0,   255);
        Colors::Text         = IM_COL32(160, 160, 160, 255);
        Colors::TextBright   = IM_COL32(240, 240, 240, 255);
        Colors::TextDim      = IM_COL32(100, 100, 100, 255);
        Colors::TextBind     = IM_COL32(100, 100, 100, 255);
        Colors::Section      = IM_COL32(70,  70,  70,  255);
        Colors::CbBg         = IM_COL32(10,  10,  10,  255);
        Colors::CbBorder     = IM_COL32(40,  40,  40,  255);
        Colors::SliderTrack  = IM_COL32(15,  15,  15,  255);
        Colors::DropdownBg   = IM_COL32(8,   8,   8,   255);
        Colors::DropdownBord = IM_COL32(35,  35,  35,  255);
        Colors::Divider      = IM_COL32(30,  30,  30,  255);
        Colors::TabBg        = IM_COL32(0,   0,   0,   255);
        Colors::ColHdr       = IM_COL32(150, 150, 150, 255);
        Colors::ColHdrLine   = IM_COL32(15,  15,  15,  255);
        Colors::SectionBg    = IM_COL32(0,   0,   0,   255);
        Colors::SectionBorder = IM_COL32(15, 15,  15,  255);
        Colors::MenuBg       = IM_COL32(0,   0,   0,   255);
        Colors::MenuTitleGradTop = IM_COL32(20, 20, 20, 255);
        Colors::MenuTitleGradBot = IM_COL32(0,   0,   0, 255);
        Colors::MenuTitleText = IM_COL32(255, 255, 255, 255);
        Colors::BoxBorder     = IM_COL32(15,  15,  15,  255);
        Colors::BoxInnerBorder = IM_COL32(0,   0,   0,   255);
        Colors::SideStrip     = IM_COL32(15,  15,  15,  255);
        Colors::ListBg        = IM_COL32(8,   8,   8,   255);
        Colors::ScrollbarTrack = IM_COL32(10, 10,  10,  255);
        Colors::ScrollbarGrab  = IM_COL32(30,  30,  30,  255);
        Colors::ScrollbarGrabHover = IM_COL32(40,  40,  40,  255);
        Colors::ScrollbarGrabActive = IM_COL32(40,  40,  40,  255);
        Colors::InputBg      = IM_COL32(6,   6,   6,   255);
        Colors::ButtonBgTop  = IM_COL32(15,  15,  15,  255);
        Colors::ButtonBgBot  = IM_COL32(8,   8,   8,   255);
        Colors::BindBg       = IM_COL32(0,   0,   0,   255);
        Colors::ButtonHeldTop = IM_COL32(10,  10,  10,  255);
        Colors::ButtonHeldBot = IM_COL32(4,   4,   4,   255);
        Colors::ButtonBorder  = IM_COL32(0,   0,   0,   255);
        Colors::DropdownGradTop = IM_COL32(15, 15,  15,  255);
        Colors::DropdownGradBot = IM_COL32(8,  8,   8,   255);
        Colors::CheckboxBg    = IM_COL32(10,  10,  10,  255);
        Colors::SliderValueBg = IM_COL32(15,  15,  15,  255);
        Colors::BindItemBg    = IM_COL32(10,  10,  10,  255);
        Colors::BindItemText  = IM_COL32(140, 140, 140, 255);
        Colors::TabSeparator  = IM_COL32(30,  30,  30,  90);
    } else {
        Colors::Bg           = IM_COL32(18,  18,  18,  255);
        Colors::TitleBg      = IM_COL32(18,  18,  18,  255);
        Colors::Text         = IM_COL32(205, 205, 205, 255);
        Colors::TextBright   = IM_COL32(245, 245, 245, 255);
        Colors::TextDim      = IM_COL32(110, 110, 116, 255);
        Colors::TextBind     = IM_COL32(150, 150, 150, 255);
        Colors::Section      = IM_COL32(235, 235, 235, 255);
        Colors::CbBg         = IM_COL32(24,  24,  24,  255);
        Colors::CbBorder     = IM_COL32(42,  42,  42,  255);
        Colors::SliderTrack  = IM_COL32(45,  45,  45,  255);
        Colors::DropdownBg   = IM_COL32(30,  30,  30,  255);
        Colors::DropdownBord = IM_COL32(47,  47,  47,  255);
        Colors::Divider      = IM_COL32(43,  43,  43,  255);
        Colors::TabBg        = IM_COL32(17,  17,  17,  255);
        Colors::ColHdr       = IM_COL32(245, 245, 245, 255);
        Colors::ColHdrLine   = IM_COL32(42,  42,  42,  255);
        Colors::SectionBg    = IM_COL32(25,  25,  25,  255);
        Colors::SectionBorder = IM_COL32(41, 41,  41,  255);
        Colors::MenuBg       = IM_COL32(18,  18,  18,   255);
        Colors::MenuTitleGradTop = IM_COL32(18, 18, 18, 255);
        Colors::MenuTitleGradBot = IM_COL32(18, 18, 18, 255);
        Colors::MenuTitleText = IM_COL32(255, 255, 255, 255);
        Colors::BoxBorder     = IM_COL32(42, 42, 42, 255);
        Colors::BoxInnerBorder = IM_COL32(26, 26, 26, 255);
        Colors::SideStrip     = IM_COL32(43, 43, 43, 255);
        Colors::ListBg        = IM_COL32(25,  25,  25,  255);
        Colors::ScrollbarTrack = IM_COL32(34, 34, 34, 255);
        Colors::ScrollbarGrab  = IM_COL32(75, 75, 75, 255);
        Colors::ScrollbarGrabHover = IM_COL32(95, 95, 95, 255);
        Colors::ScrollbarGrabActive = IM_COL32(120, 120, 120, 255);
        Colors::InputBg      = IM_COL32(30,  30,  30,  255);
        Colors::ButtonBgTop  = IM_COL32(34,  34,  34,  255);
        Colors::ButtonBgBot  = IM_COL32(30,  30,  30,  255);
        Colors::BindBg       = IM_COL32(25,  25,  25,  255);
        Colors::ButtonHeldTop = IM_COL32(42,  42,  42,  255);
        Colors::ButtonHeldBot = IM_COL32(34,  34,  34,  255);
        Colors::ButtonBorder  = IM_COL32(45,  45,  45,  255);
        Colors::DropdownGradTop = IM_COL32(34,  34,  34,  255);
        Colors::DropdownGradBot = IM_COL32(30,  30,  30,  255);
        Colors::CheckboxBg    = IM_COL32(245, 245, 245, 255);
        Colors::SliderValueBg = IM_COL32(245, 245, 245, 255);
        Colors::BindItemBg    = IM_COL32(30,  30,  30,  255);
        Colors::BindItemText  = IM_COL32(170, 170, 175, 255);
        Colors::TabSeparator = IM_COL32(44,  44,  44,  130);
    }
}

static void SyncMenuFromConfig() {
    s.toggle_menu = true;
    s.menu_color = g_cfg->menu.m_menu_color;
    s.menu_weather = g_cfg->menu.m_weather;
    s.menu_theme = g_cfg->menu.m_theme;

    UI::InitBind("toggle_menu", "INS");
    auto& bind = UI::g_binds["toggle_menu"];
    bind.key = g_cfg->menu.m_toggle_menu_key.empty() ? "INS" : g_cfg->menu.m_toggle_menu_key;
    bind.mode = UI::BindMode::Toggle;
}

static void SyncMenuToConfig() {
    s.toggle_menu = true;
    g_cfg->menu.m_menu_color = s.menu_color;
    g_cfg->menu.m_weather = s.menu_weather;
    g_cfg->menu.m_theme = s.menu_theme;

    UI::InitBind("toggle_menu", "INS");
    auto& bind = UI::g_binds["toggle_menu"];
    g_cfg->menu.m_toggle_menu_key = bind.key.empty() ? "INS" : bind.key;
    bind.mode = UI::BindMode::Toggle;
}

static void SyncIndicatorsFromConfig() {
    s.ind_keybinds = g_cfg->indicators.m_keybinds;
    g_binds_window_x = g_cfg->indicators.m_binds_x;
    g_binds_window_y = g_cfg->indicators.m_binds_y;
    s.ind_spectators = g_cfg->indicators.m_spectators;
    s.ind_watermark = g_cfg->indicators.m_watermark;
    s.watermark_elements = g_cfg->indicators.m_watermark_elements;
    s.ind_spotify = g_cfg->indicators.m_spotify;
    s.watermark_col = g_cfg->indicators.m_watermark_col;
    s.vel_display = g_cfg->indicators.m_velocity_display;
    s.vel_display_col1 = g_cfg->indicators.m_velocity_display_col1;
    s.vel_display_col2 = g_cfg->indicators.m_velocity_display_col2;
    s.vel_display_col3 = g_cfg->indicators.m_velocity_display_col3;
    s.keystrokes = g_cfg->indicators.m_keystrokes;
    s.vel_graph = g_cfg->indicators.m_velocity_graph;
    s.vel_graph_col = g_cfg->indicators.m_velocity_graph_col;
    s.jump_stats = g_cfg->indicators.m_jump_stats;
    s.movement_trails = g_cfg->indicators.m_movement_trails;
    s.movement_trails_col = g_cfg->indicators.m_movement_trails_col;
    s.ind_offset = g_cfg->indicators.m_ind_offset;
}

static void SyncIndicatorsToConfig() {
    g_cfg->indicators.m_keybinds = s.ind_keybinds;
    g_cfg->indicators.m_binds_x = g_binds_window_x;
    g_cfg->indicators.m_binds_y = g_binds_window_y;
    g_cfg->indicators.m_spectators = s.ind_spectators;
    g_cfg->indicators.m_watermark = s.ind_watermark;
    g_cfg->indicators.m_watermark_elements = s.watermark_elements;
    g_cfg->indicators.m_spotify = s.ind_spotify;
    g_cfg->indicators.m_watermark_col = s.watermark_col;
    g_cfg->indicators.m_velocity_display = s.vel_display;
    g_cfg->indicators.m_velocity_display_col1 = s.vel_display_col1;
    g_cfg->indicators.m_velocity_display_col2 = s.vel_display_col2;
    g_cfg->indicators.m_velocity_display_col3 = s.vel_display_col3;
    g_cfg->indicators.m_keystrokes = s.keystrokes;
    g_cfg->indicators.m_velocity_graph = s.vel_graph;
    g_cfg->indicators.m_velocity_graph_col = s.vel_graph_col;
    g_cfg->indicators.m_jump_stats = s.jump_stats;
    g_cfg->indicators.m_movement_trails = s.movement_trails;
    g_cfg->indicators.m_movement_trails_col = s.movement_trails_col;
    g_cfg->indicators.m_ind_offset = s.ind_offset;
}

static UI::BindMode BindModeFromInt(int mode) {
    if (mode == (int)UI::BindMode::AlwaysOn) return UI::BindMode::AlwaysOn;
    if (mode == (int)UI::BindMode::Toggle) return UI::BindMode::Toggle;
    return UI::BindMode::Hold;
}

// Which weapon group the aim-tab mirror (State s) currently reflects. Used to
// detect when the user switches groups via the dropdown so we can flush edits to
// the old group before loading the newly selected one.
static int s_active_aim_group = 0;

static int ClampAimGroup(int g) {
    if (g < 0 || g >= c_config::aim_t::group_count)
        return 0;
    return g;
}

static void LoadAimGroupIntoState(int g) {
    const auto& grp = g_cfg->aim.m_groups[ClampAimGroup(g)];
    s.aimbot = grp.m_aimbot;
    s.triggerbot = grp.m_triggerbot;
    s.magnet = grp.m_magnet;
    s.penetration = grp.m_penetration;
    s.override_shared = grp.m_override_shared;
    s.hitbox_sel = grp.m_hitbox;
    s.trigger_hitbox_sel = grp.m_trigger_hitbox;
    s.recoil_ctrl = grp.m_recoil_control;
    s.fov = grp.m_fov;
    s.smooth = grp.m_smooth;
    s.seed_pred = grp.m_seed_prediction;
    s.delay = grp.m_trigger_delay;
    s.hitchance = grp.m_hitchance;
}

static void StoreStateIntoAimGroup(int g) {
    auto& grp = g_cfg->aim.m_groups[ClampAimGroup(g)];
    grp.m_aimbot = s.aimbot;
    grp.m_triggerbot = s.triggerbot;
    grp.m_magnet = s.magnet;
    grp.m_penetration = s.penetration;
    grp.m_override_shared = s.override_shared;
    grp.m_hitbox = s.hitbox_sel;
    grp.m_trigger_hitbox = s.trigger_hitbox_sel;
    grp.m_recoil_control = s.recoil_ctrl;
    grp.m_fov = s.fov;
    grp.m_smooth = s.smooth;
    grp.m_seed_prediction = s.seed_pred;
    grp.m_trigger_delay = s.delay;
    grp.m_hitchance = s.hitchance;
}

static void SyncAimFromConfig() {
    s_active_aim_group = ClampAimGroup(g_cfg->aim.m_weapon_group);
    s.weapon_sel = s_active_aim_group;
    LoadAimGroupIntoState(s_active_aim_group);
    s.auto_scope = g_cfg->aim.m_auto_scope;
    s.auto_stop = g_cfg->aim.m_auto_stop;
    s.visualize_aimbot_fov = g_cfg->aim.m_visualize_aimbot_fov;
    s.visualize_aimbot_fov_color = g_cfg->aim.m_visualize_aimbot_fov_color;

    UI::InitBind("aimbot", "");
    UI::InitBind("triggerbot", "");
    UI::InitBind("penetration", "");
    UI::g_binds["aimbot"].key = g_cfg->aim.m_aimbot_key;
    UI::g_binds["aimbot"].mode = BindModeFromInt(g_cfg->aim.m_aimbot_mode);
    UI::g_binds["triggerbot"].key = g_cfg->aim.m_triggerbot_key;
    UI::g_binds["triggerbot"].mode = BindModeFromInt(g_cfg->aim.m_triggerbot_mode);
    UI::g_binds["penetration"].key = g_cfg->aim.m_penetration_key;
    UI::g_binds["penetration"].mode = BindModeFromInt(g_cfg->aim.m_penetration_mode);
}

static void SyncAimToConfig() {
    const int sel = ClampAimGroup(s.weapon_sel);
    if (sel != s_active_aim_group) {
        // User picked a different group this frame: flush the edits that belong
        // to the previously active group, then swap the mirror to the new one.
        StoreStateIntoAimGroup(s_active_aim_group);
        s_active_aim_group = sel;
        LoadAimGroupIntoState(sel);
    } else {
        StoreStateIntoAimGroup(s_active_aim_group);
    }
    s.weapon_sel = s_active_aim_group;
    g_cfg->aim.m_weapon_group = s_active_aim_group;
    g_cfg->aim.m_auto_scope = s.auto_scope;
    g_cfg->aim.m_auto_stop = s.auto_stop;
    g_cfg->aim.m_visualize_aimbot_fov = s.visualize_aimbot_fov;
    g_cfg->aim.m_visualize_aimbot_fov_color = s.visualize_aimbot_fov_color;

    UI::InitBind("aimbot", "");
    UI::InitBind("triggerbot", "");
    UI::InitBind("penetration", "");
    g_cfg->aim.m_aimbot_key = UI::g_binds["aimbot"].key;
    g_cfg->aim.m_aimbot_mode = (int)UI::g_binds["aimbot"].mode;
    g_cfg->aim.m_triggerbot_key = UI::g_binds["triggerbot"].key;
    g_cfg->aim.m_triggerbot_mode = (int)UI::g_binds["triggerbot"].mode;
    g_cfg->aim.m_penetration_key = UI::g_binds["penetration"].key;
    g_cfg->aim.m_penetration_mode = (int)UI::g_binds["penetration"].mode;
}

static void SyncMovementFromConfig() {
    UI::InitBind("jump_bug", "");
    auto& bind = UI::g_binds["jump_bug"];
    bind.key = g_cfg->movement.m_jump_bug_key;
    bind.mode = BindModeFromInt(g_cfg->movement.m_jump_bug_mode);

    UI::InitBind("edge_jump", "");
    auto& edge_bind = UI::g_binds["edge_jump"];
    edge_bind.key = g_cfg->movement.m_edge_jump_key;
    edge_bind.mode = BindModeFromInt(g_cfg->movement.m_edge_jump_mode);
}

static void SyncMovementToConfig() {
    UI::InitBind("jump_bug", "");
    auto& bind = UI::g_binds["jump_bug"];
    const std::string key = bind.key;
    const int mode = (int)bind.mode;
    if (g_cfg->movement.m_jump_bug_key != key)
        g_cfg->movement.m_jump_bug_key = key;
    if (g_cfg->movement.m_jump_bug_mode != mode)
        g_cfg->movement.m_jump_bug_mode = mode;

    UI::InitBind("edge_jump", "");
    auto& edge_bind = UI::g_binds["edge_jump"];
    const std::string edge_key = edge_bind.key;
    const int edge_mode = (int)edge_bind.mode;
    if (g_cfg->movement.m_edge_jump_key != edge_key)
        g_cfg->movement.m_edge_jump_key = edge_key;
    if (g_cfg->movement.m_edge_jump_mode != edge_mode)
        g_cfg->movement.m_edge_jump_mode = edge_mode;
}

static void SyncVisualsFromConfig() {
    UI::InitBind("thirdperson", "");
    auto& bind = UI::g_binds["thirdperson"];
    bind.key = g_cfg->visuals.m_thirdperson_key;
    bind.mode = BindModeFromInt(g_cfg->visuals.m_thirdperson_mode);
}

static void SyncVisualsToConfig() {
    UI::InitBind("thirdperson", "");
    auto& bind = UI::g_binds["thirdperson"];
    const std::string key = bind.key;
    const int mode = (int)bind.mode;
    if (g_cfg->visuals.m_thirdperson_key != key)
        g_cfg->visuals.m_thirdperson_key = key;
    if (g_cfg->visuals.m_thirdperson_mode != mode)
        g_cfg->visuals.m_thirdperson_mode = mode;
}

// Unused functions - kept for potential future use
/*
static std::string NormalizeBindName(std::string name) {
    if (name == "LeftAlt" || name == "RightAlt") name = "ALT";
    else if (name == "LeftCtrl" || name == "RightCtrl") name = "CTRL";
    else if (name == "LeftShift" || name == "RightShift") name = "SHIFT";
    else if (name == "LeftSuper" || name == "RightSuper") name = "WIN";
    else if (name == "MouseLeft") name = "M1";
    else if (name == "MouseRight") name = "M2";
    else if (name == "MouseMiddle") name = "M3";
    else {
        for (auto& c : name) c = (char)toupper((unsigned char)c);
        if (name == "INSERT") name = "INS";
        else if (name == "DELETE") name = "DEL";
    }
    return name;
}

static unsigned int VirtualKeyFromBindName(std::string key) {
    key = NormalizeBindName(key);
    if (key == "DEL") return VK_DELETE;
    if (key == "INS") return VK_INSERT;
    if (key == "ALT") return VK_MENU;
    if (key == "CTRL") return VK_CONTROL;
    if (key == "SHIFT") return VK_SHIFT;
    if (key == "WIN") return VK_LWIN;
    if (key.size() == 1) {
        char c = key[0];
        if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return static_cast<unsigned int>(c);
    }
    if (key.size() >= 2 && key[0] == 'F') {
        int n = atoi(key.c_str() + 1);
        if (n >= 1 && n <= 24)
            return VK_F1 + static_cast<unsigned int>(n - 1);
    }
    if (key == "SPACE") return VK_SPACE;
    if (key == "TAB") return VK_TAB;
    if (key == "ENTER") return VK_RETURN;
    if (key == "BACKSPACE") return VK_BACK;
    if (key == "HOME") return VK_HOME;
    if (key == "END") return VK_END;
    if (key == "PAGEUP") return VK_PRIOR;
    if (key == "PAGEDOWN") return VK_NEXT;
    return 0;
}
*/

static void DrawMenuBindRow(ImDrawList* dl, const ImVec2& wpos, float text_x, float bind_x, float y, float width, float line_h) {
    auto S = [&](float sx, float sy) { return ImVec2(wpos.x + sx, wpos.y + sy); };
    UI::InitBind("toggle_menu", "INS");
    auto& bind = UI::g_binds["toggle_menu"];
    bind.mode = UI::BindMode::Toggle;

    dl->AddText(S(text_x, y + floorf((20.0f - line_h) * 0.5f)), Colors::Text, "toggle menu");

    const bool waiting = UI::IsBindWaiting("toggle_menu");
    const char* display = UI::GetBindDisplay("toggle_menu");
    ImVec2 text_size = ImGui::CalcTextSize(display);
    const float bx = bind_x + width - text_size.x;

    ImGui::SetCursorScreenPos(S(bx - 5.0f, y - 1.0f));
    ImGui::InvisibleButton("##menu_toggle_bind", ImVec2(text_size.x + 10.0f, 22.0f));
    if (ImGui::IsItemClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking()) {
        if (waiting)
            bind.waiting = false;
        else
            UI::StartBindWaiting("toggle_menu");
    }

    ImU32 color = waiting ? Colors::Accent : Colors::TextBind;
    dl->AddText(S(bx, y + floorf((20.0f - line_h) * 0.5f)), color, display);
}

static void CfgEnsureDir() {
    CreateDirectoryA(k_cfg_dir, nullptr);
}
static void CfgScan() {
    std::string prev;
    if (s_cfg_sel >= 0 && s_cfg_sel < (int)s_cfg_list.size())
        prev = s_cfg_list[s_cfg_sel];
    g_config_system->refresh();
    s_cfg_list = g_config_system->get_config_files();
    s_cfg_sel   = -1;
    s_cfg_dirty = false;
    if (!prev.empty()) {
        for (int i = 0; i < (int)s_cfg_list.size(); i++) {
            if (s_cfg_list[i] == prev) { s_cfg_sel = i; break; }
        }
    }
}
static std::string CfgNormalizeName(std::string name) {
    auto is_space = [](unsigned char c) { return std::isspace(c) != 0; };
    name.erase(name.begin(), std::find_if(name.begin(), name.end(), [&](unsigned char c) { return !is_space(c); }));
    name.erase(std::find_if(name.rbegin(), name.rend(), [&](unsigned char c) { return !is_space(c); }).base(), name.end());

    std::string lower = name;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return (char)std::tolower(c); });
    if (lower.size() > 4 && lower.rfind(".clr") == lower.size() - 4)
        name.erase(name.size() - 4);

    for (char& c : name) {
        const unsigned char uc = (unsigned char)c;
        if (uc < 32 || std::strchr("<>:\"/\\|?*", c))
            c = '_';
    }

    name.erase(name.begin(), std::find_if(name.begin(), name.end(), [&](unsigned char c) { return !is_space(c); }));
    name.erase(std::find_if(name.rbegin(), name.rend(), [&](unsigned char c) { return !is_space(c); }).base(), name.end());
    if (name == "." || name == "..")
        name.clear();
    if (name.size() > 48)
        name.resize(48);
    return name;
}
static bool CfgNameExists(const std::string& name) {
    return std::find(s_cfg_list.begin(), s_cfg_list.end(), name) != s_cfg_list.end();
}
static void SyncSkinsToConfig();
static void CfgCreate() {
    if (s_cfg_input[0] == '\0') return;
    CfgEnsureDir();
    std::string name = CfgNormalizeName(s_cfg_input);
    if (name.empty()) {
        return;
    }
    if (CfgNameExists(name)) {
        return;
    }
    SyncSkinsToConfig();
    SyncMenuToConfig();
    SyncAimToConfig();
    SyncMovementToConfig();
    SyncVisualsToConfig();
    SyncIndicatorsToConfig();
    g_config_system->save(name);
    CfgScan();
    for (int i = 0; i < (int)s_cfg_list.size(); i++) {
        if (s_cfg_list[i] == name) { s_cfg_sel = i; break; }
    }
    if (s_cfg_sel >= 0)
        g_config_system->m_selected_config = s_cfg_list[s_cfg_sel];
    s_cfg_input[0] = '\0';
}
static void CfgSave() {
    if (s_cfg_sel < 0 || s_cfg_sel >= (int)s_cfg_list.size()) return;
    g_config_system->m_selected_config = s_cfg_list[s_cfg_sel];
    SyncSkinsToConfig();
    SyncMenuToConfig();
    SyncAimToConfig();
    SyncMovementToConfig();
    SyncVisualsToConfig();
    SyncIndicatorsToConfig();
    g_config_system->save(g_config_system->m_selected_config);
    CfgScan();
}
static void CfgLoad() {
    if (s_cfg_sel < 0 || s_cfg_sel >= (int)s_cfg_list.size()) return;
    g_config_system->m_selected_config = s_cfg_list[s_cfg_sel];
    g_config_system->load(g_config_system->m_selected_config);
    SyncMenuFromConfig();
    SyncAimFromConfig();
    SyncMovementFromConfig();
    SyncVisualsFromConfig();
    SyncIndicatorsFromConfig();
    s_skip_skin_sync_to_config = true;
}
static void CfgOpenDir() {
    CfgEnsureDir();
    ShellExecuteA(nullptr, "open", k_cfg_dir, nullptr, nullptr, SW_SHOW);
}
static void CfgDelete() {
    if (s_cfg_sel < 0 || s_cfg_sel >= (int)s_cfg_list.size()) return;
    std::string cfg_name = s_cfg_list[s_cfg_sel];
    std::string cfg_path = std::string(k_cfg_dir) + cfg_name + ".json";
    if (DeleteFileA(cfg_path.c_str())) {
        s_cfg_sel = -1;
        g_config_system->m_selected_config = "";
        CfgScan();
    }
}

// Unused function - kept for potential future use
/*
static bool dropdown(const char* id, int* selected, const char* const* items, int count, float width, const ImU32* item_colors = nullptr) {
    ImGui::PushID(id);
    bool ret = UI::Dropdown("##dropdown", selected, const_cast<const char**>(items), count, width, item_colors);
    ImGui::PopID();
    return ret;
}
*/
// Resolves and caches the panorama econ preview texture for a given item
// definition + paint kit. Mirrors the vtex path built in item_schema.cpp.
// Returns nullptr for the default skin (id 0) or when the asset is missing.
static ID3D11ShaderResourceView* GetSkinPreviewTexture(uint16_t def_index, int paint_kit_id,
                                                       int* out_w = nullptr, int* out_h = nullptr) {
    struct cache_entry_t { ID3D11ShaderResourceView* srv; int w; int h; };
    static std::unordered_map<uint64_t, cache_entry_t> cache;

    if (out_w) *out_w = 0;
    if (out_h) *out_h = 0;

    if (def_index == 0 || paint_kit_id <= 0)
        return nullptr;

    const uint64_t key = ((uint64_t)def_index << 32) | (uint32_t)paint_kit_id;
    auto it = cache.find(key);
    if (it != cache.end()) {
        if (out_w) *out_w = it->second.w;
        if (out_h) *out_h = it->second.h;
        return it->second.srv;
    }

    int tex_w = 0, tex_h = 0;

    auto build = [&]() -> ID3D11ShaderResourceView* {
        if (!g_interfaces || !g_interfaces->m_source2_client || !g_interfaces->m_file_system)
            return nullptr;

        auto* item_system = g_interfaces->m_source2_client->get_econ_item_system();
        if (!item_system)
            return nullptr;
        auto* schema = item_system->get_econ_item_schema();
        if (!schema)
            return nullptr;

        // The sorted item-definition map is NOT keyed by definition index
        // (find_by_key compares m_key, which is a sort key), so scan by
        // m_definition_index -- exactly like item_schema::build_paint_kits_for_item.
        c_econ_item_definition* item_def = nullptr;
        auto& item_map = schema->get_sorted_item_definition_map();
        for (int i = 0; i < item_map.count(); i++) {
            auto& node = item_map.element(i);
            if (node.m_value && node.m_value->m_definition_index == def_index) {
                item_def = node.m_value;
                break;
            }
        }
        if (!item_def)
            return nullptr;

        // The paint-kit map's find_by_key() compares m_key (an internal sort
        // key), NOT the paint-kit id -- so scan by m_value->m_id, exactly like
        // item_schema::build_paint_kits_for_item. Using find_by_key here
        // silently returns null and the preview falls back to "default".
        c_paint_kit* paint_kit = nullptr;
        auto& kit_map = schema->get_paint_kits();
        for (int i = 0; i < kit_map.count(); i++) {
            auto& node = kit_map.element(i);
            if (node.m_value && node.m_value->m_id == paint_kit_id) {
                paint_kit = node.m_value;
                break;
            }
        }
        if (!paint_kit || !paint_kit->m_name)
            return nullptr;

        // get_item_name() (0x260) is the simple asset name used to build the
        // vtex path -- identical to item_schema::build_paint_kits_for_item and
        // to yougey's SIMPLE_WEAPON_NAME (also 0x260). Do NOT use
        // get_simple_weapon_name() (0x230) here; that is a different field.
        const char* simple_name = item_def->get_item_name();
        if (!simple_name || simple_name[0] == '\0')
            return nullptr;

        std::string path = "panorama/images/econ/default_generated/" +
            std::string(simple_name) + "_" + paint_kit->m_name + "_light_png.vtex_c";

        if (!g_interfaces->m_file_system->exists(path.c_str(), "GAME"))
            return nullptr;

        auto vtex = vtex_parser::load(path, g_interfaces->m_file_system);
        if (vtex.data.empty() || vtex.w <= 0 || vtex.h <= 0)
            return nullptr;

        tex_w = vtex.w;
        tex_h = vtex.h;

        ID3D11Device* device = g_directx ? g_directx->get_device() : nullptr;
        if (!device)
            return nullptr;

        D3D11_TEXTURE2D_DESC desc = {};
        desc.Width = vtex.w;
        desc.Height = vtex.h;
        desc.MipLevels = 1;
        desc.ArraySize = 1;
        desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        desc.SampleDesc.Count = 1;
        desc.Usage = D3D11_USAGE_DEFAULT;
        desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

        D3D11_SUBRESOURCE_DATA sub = {};
        sub.pSysMem = vtex.data.data();
        sub.SysMemPitch = desc.Width * 4;

        ID3D11Texture2D* texture = nullptr;
        if (FAILED(device->CreateTexture2D(&desc, &sub, &texture)) || !texture)
            return nullptr;

        D3D11_SHADER_RESOURCE_VIEW_DESC srv_desc = {};
        srv_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        srv_desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
        srv_desc.Texture2D.MipLevels = 1;

        ID3D11ShaderResourceView* out = nullptr;
        device->CreateShaderResourceView(texture, &srv_desc, &out);
        texture->Release();
        return out;
    };

    ID3D11ShaderResourceView* srv = build();
    if (!srv) { tex_w = 0; tex_h = 0; }
    cache[key] = { srv, tex_w, tex_h }; // cache nullptr too, so misses aren't retried every frame
    if (out_w) *out_w = tex_w;
    if (out_h) *out_h = tex_h;
    return srv;
}

static void DrawBox(ImDrawList* dl, ImVec2 wpos,
                    float lx, float box_top, float box_bottom, float w,
                    const char* label, ImU32 label_col) {
    auto S_local = [&](float x, float y) { return ImVec2(wpos.x + x, wpos.y + y); };
    ImVec2 ts  = ImGui::CalcTextSize(label);
    float  tx  = lx + (w - ts.x) * 0.5f;
    float  ty  = box_top + 10.0f;

    ImU32 border_color = Colors::BoxBorder;
    dl->AddRect(S_local(lx, box_top), S_local(lx + w, box_bottom), border_color, 9.0f, ImDrawFlags_RoundCornersAll, 1.0f);
    dl->AddText(S_local(tx, ty), label_col, label);
}

// Unused function - kept for potential future use
/*
static void DrawInnerSep(ImDrawList* dl, ImVec2 wpos,
                         float lx, float ly, float w, const char* label) {
    auto S_local = [&](float x, float y) { return ImVec2(wpos.x + x, wpos.y + y); };
    float  lh  = ImGui::GetTextLineHeight();
    float  gap = 5.0f;
    ImVec2 ts  = ImGui::CalcTextSize(label);
    float  tx  = lx + (w - ts.x) * 0.5f;
    float  ty  = ly - lh * 0.5f;
    dl->AddLine(S_local(lx, ly), S_local(tx - gap, ly), Colors::SectionBorder, 1.0f);
    dl->AddLine(S_local(tx + ts.x + gap, ly), S_local(lx + w, ly), Colors::SectionBorder, 1.0f);
    dl->AddText(S_local(tx, ty), Colors::Section, label);
}
*/

static ImU32 GetRarityColorU32(int rarity) {
    switch (rarity) {
    case 0: return ImGui::ColorConvertFloat4ToU32(ImVec4(0.75f, 0.75f, 0.78f, 1.0f));
    case 1: return ImGui::ColorConvertFloat4ToU32(ImVec4(0.30f, 0.60f, 0.87f, 1.0f));
    case 2: return ImGui::ColorConvertFloat4ToU32(ImVec4(0.15f, 0.40f, 0.79f, 1.0f));
    case 3: return ImGui::ColorConvertFloat4ToU32(ImVec4(0.48f, 0.22f, 0.74f, 1.0f));
    case 4: return ImGui::ColorConvertFloat4ToU32(ImVec4(0.78f, 0.18f, 0.74f, 1.0f));
    case 5: return ImGui::ColorConvertFloat4ToU32(ImVec4(0.93f, 0.25f, 0.25f, 1.0f));
    case 6: return ImGui::ColorConvertFloat4ToU32(ImVec4(0.93f, 0.70f, 0.18f, 1.0f));
    default: return Colors::Text;
    }
}

static void BuildPaintKitRarityColors(uint16_t def_index, std::vector<ImU32>& out) {
    out.clear();

    g_item_schema->ensure_paint_kits_for_item(def_index);
    auto it = g_item_schema->item_paint_kits.find(def_index);
    if (it == g_item_schema->item_paint_kits.end())
        return;

    bool is_knife = (def_index >= 500 && def_index <= 526);
    bool is_glove = (def_index >= 5027 && def_index <= 5036);

    out.reserve(it->second.size());
    for (const auto& kit : it->second) {
        int rarity = kit.rarity;

        if ((is_knife || is_glove) && kit.id != 0)
            rarity = 5;

        if (kit.name.find("howl") != std::string::npos)
            rarity = 6;

        out.push_back(GetRarityColorU32(rarity));
    }
}

static void BuildAgentRarityColors(const std::vector<item_info_t>& agents, std::vector<ImU32>& out) {
    out.clear();
    out.reserve(agents.size());

    for (const auto& agent : agents) {
        int rarity = agent.rarity;
        if (rarity == 6)
            rarity = 5;
        out.push_back(GetRarityColorU32(rarity));
    }
}

static bool PaintColorRow(const char* id, ImVec4* colors, int count, float right_edge) {
    bool changed = false;
    for (int i = count - 1; i >= 0; --i) {
        char picker_id[256];
        snprintf(picker_id, sizeof(picker_id), "##%s_%d", id, i);
        ImGui::SetCursorPos(ImGui::GetCursorPos());
        changed |= UI::ColorPicker(picker_id, &colors[i], right_edge, COLOR_PICKER_STEP * (float)(count - 1 - i));
    }
    return changed;
}

static bool CopyPaintColors(ImVec4* dst, const ImVec4* src, int count) {
    bool changed = false;
    for (int i = 0; i < count; ++i) {
        if (dst[i].x != src[i].x || dst[i].y != src[i].y || dst[i].z != src[i].z || dst[i].w != src[i].w) {
            dst[i] = src[i];
            changed = true;
        }
    }
    return changed;
}

static void SyncSkinsFromConfig() {
    s.knife_changer.enabled = g_cfg->knife_changer.m_enabled;
    s.knife_changer.selected_knife = g_cfg->knife_changer.m_knife;
    s.knife_changer.selected_skin = g_cfg->knife_changer.m_paint_kit;
    s.knife_changer.wear = g_cfg->knife_changer.m_wear;
    s.knife_changer.seed = g_cfg->knife_changer.m_seed;
    strcpy_s(s.knife_changer.custom_name, g_cfg->knife_changer.m_custom_name);
    s.knife_changer.paint_color = g_cfg->knife_changer.m_paint_color;
    CopyPaintColors(s.knife_changer.paint_colors, g_cfg->knife_changer.m_paint_colors, 4);

    s.skin_changer.enabled = g_cfg->skin_changer.m_enabled;
    s.skin_changer.selected_weapon = g_cfg->skin_changer.m_selected_weapon;
    for (int i = 0; i < 100; ++i) {
        s.skin_changer.weapon_configs[i].paint_kit = g_cfg->skin_changer.weapon_skins[i].paint_kit;
        s.skin_changer.weapon_configs[i].wear = g_cfg->skin_changer.weapon_skins[i].wear;
        s.skin_changer.weapon_configs[i].seed = g_cfg->skin_changer.weapon_skins[i].seed;
        s.skin_changer.weapon_configs[i].paint_color = g_cfg->skin_changer.weapon_skins[i].paint_color;
        CopyPaintColors(s.skin_changer.weapon_configs[i].paint_colors, g_cfg->skin_changer.weapon_skins[i].paint_colors, 4);
        strcpy_s(s.skin_changer.weapon_configs[i].custom_name,
            sizeof(s.skin_changer.weapon_configs[i].custom_name),
            g_cfg->skin_changer.weapon_skins[i].custom_name
        );
    }

    s.agent_changer.enabled = g_cfg->agent_changer.m_enabled;
    s.agent_changer.selected_t_agent = g_cfg->agent_changer.m_selected_t_agent;
    s.agent_changer.selected_ct_agent = g_cfg->agent_changer.m_selected_ct_agent;

    s.viewmodel_changer.enabled = g_cfg->viewmodel.m_enabled;
    s.viewmodel_changer.position_enabled = g_cfg->viewmodel.m_position_enabled;
    s.viewmodel_changer.fov = g_cfg->viewmodel.m_fov;
    s.viewmodel_changer.offset_x = g_cfg->viewmodel.m_offset_x;
    s.viewmodel_changer.offset_y = g_cfg->viewmodel.m_offset_y;
    s.viewmodel_changer.offset_z = g_cfg->viewmodel.m_offset_z;

    s.fov_changer.enabled = g_cfg->fov_changer.m_enabled;
    s.fov_changer.fov = g_cfg->fov_changer.m_fov;
}

static void SyncSkinsToConfig() {
    bool skin_changed = false;
    bool glove_changed = false;

    auto copy_string = [](char* dst, size_t dst_size, const char* src) {
        if (std::strncmp(dst, src, dst_size) != 0) {
            strncpy_s(dst, dst_size, src, _TRUNCATE);
            dst[dst_size - 1] = '\0';
            return true;
        }
        return false;
    };

    if (g_cfg->knife_changer.m_enabled != s.knife_changer.enabled) { g_cfg->knife_changer.m_enabled = s.knife_changer.enabled; skin_changed = true; }
    if (g_cfg->knife_changer.m_knife != s.knife_changer.selected_knife) { g_cfg->knife_changer.m_knife = s.knife_changer.selected_knife; g_cfg->knife_changer.m_paint_kit = 0; s.knife_changer.selected_skin = 0; skin_changed = true; }
    if (g_cfg->knife_changer.m_paint_kit != s.knife_changer.selected_skin) { g_cfg->knife_changer.m_paint_kit = s.knife_changer.selected_skin; skin_changed = true; }
    if (g_cfg->knife_changer.m_wear != s.knife_changer.wear) { g_cfg->knife_changer.m_wear = s.knife_changer.wear; skin_changed = true; }
    if (g_cfg->knife_changer.m_seed != s.knife_changer.seed) { g_cfg->knife_changer.m_seed = s.knife_changer.seed; skin_changed = true; }
    if (copy_string(g_cfg->knife_changer.m_custom_name, sizeof(g_cfg->knife_changer.m_custom_name), s.knife_changer.custom_name)) skin_changed = true;
    if (g_cfg->knife_changer.m_paint_color != s.knife_changer.paint_color) { g_cfg->knife_changer.m_paint_color = s.knife_changer.paint_color; skin_changed = true; }
    if (CopyPaintColors(g_cfg->knife_changer.m_paint_colors, s.knife_changer.paint_colors, 4)) skin_changed = true;

    if (g_cfg->skin_changer.m_enabled != s.skin_changer.enabled) { g_cfg->skin_changer.m_enabled = s.skin_changer.enabled; skin_changed = true; }
    if (g_cfg->skin_changer.m_selected_weapon != s.skin_changer.selected_weapon) { g_cfg->skin_changer.m_selected_weapon = s.skin_changer.selected_weapon; skin_changed = true; }
    for (int i = 0; i < 100; ++i) {
        auto& dst = g_cfg->skin_changer.weapon_skins[i];
        auto& src = s.skin_changer.weapon_configs[i];
        if (dst.paint_kit != src.paint_kit) { dst.paint_kit = src.paint_kit; skin_changed = true; }
        if (dst.wear != src.wear) { dst.wear = src.wear; skin_changed = true; }
        if (dst.seed != src.seed) { dst.seed = src.seed; skin_changed = true; }
        if (dst.paint_color != src.paint_color) { dst.paint_color = src.paint_color; skin_changed = true; }
        if (CopyPaintColors(dst.paint_colors, src.paint_colors, 4)) skin_changed = true;
        if (copy_string(dst.custom_name, sizeof(dst.custom_name), src.custom_name)) skin_changed = true;
    }

    if (g_cfg->agent_changer.m_enabled != s.agent_changer.enabled) { g_cfg->agent_changer.m_enabled = s.agent_changer.enabled; skin_changed = true; }
    if (g_cfg->agent_changer.m_selected_t_agent != s.agent_changer.selected_t_agent) { g_cfg->agent_changer.m_selected_t_agent = s.agent_changer.selected_t_agent; skin_changed = true; }
    if (g_cfg->agent_changer.m_selected_ct_agent != s.agent_changer.selected_ct_agent) { g_cfg->agent_changer.m_selected_ct_agent = s.agent_changer.selected_ct_agent; skin_changed = true; }

    if (g_cfg->fov_changer.m_enabled != s.fov_changer.enabled) g_cfg->fov_changer.m_enabled = s.fov_changer.enabled;
    if (g_cfg->fov_changer.m_fov != s.fov_changer.fov) g_cfg->fov_changer.m_fov = s.fov_changer.fov;

    if (g_cfg->viewmodel.m_enabled != s.viewmodel_changer.enabled) g_cfg->viewmodel.m_enabled = s.viewmodel_changer.enabled;
    if (g_cfg->viewmodel.m_position_enabled != s.viewmodel_changer.position_enabled) g_cfg->viewmodel.m_position_enabled = s.viewmodel_changer.position_enabled;
    if (g_cfg->viewmodel.m_fov != s.viewmodel_changer.fov) g_cfg->viewmodel.m_fov = s.viewmodel_changer.fov;
    if (g_cfg->viewmodel.m_offset_x != s.viewmodel_changer.offset_x) g_cfg->viewmodel.m_offset_x = s.viewmodel_changer.offset_x;
    if (g_cfg->viewmodel.m_offset_y != s.viewmodel_changer.offset_y) g_cfg->viewmodel.m_offset_y = s.viewmodel_changer.offset_y;
    if (g_cfg->viewmodel.m_offset_z != s.viewmodel_changer.offset_z) g_cfg->viewmodel.m_offset_z = s.viewmodel_changer.offset_z;

    if (skin_changed)
        g_skin_changer->request_update();
    if (glove_changed)
        g_glove_changer->request_update(true);
}

static bool IsInActiveGameForIndicators() {
    if (!g_ctx || !g_ctx->m_local_pawn || !g_ctx->m_local_controller)
        return false;

    auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
    if (!local_pawn)
        return false;

    __try {
        const int team = local_pawn->m_team_num();
        if (team != 2 && team != 3)
            return false;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }

    return true;
}

static c_cs_player_pawn* GetLocalPawnForIndicators() {
    if (!IsInActiveGameForIndicators())
        return nullptr;

    return reinterpret_cast<c_cs_player_pawn*>(g_ctx ? g_ctx->m_local_pawn : nullptr);
}

static const char* GetCs2PersonaNameForWatermark() {
    static char cached_name[64] = "player";
    static ULONGLONG next_update_ms = 0;

    const ULONGLONG now_ms = GetTickCount64();
    if (now_ms < next_update_ms)
        return cached_name;

    next_update_ms = now_ms + 1000;

    HMODULE steam_api = GetModuleHandleA("steam_api64.dll");
    if (!steam_api)
        return cached_name;

    using get_steam_friends_fn = void* (__cdecl*)();
    using get_persona_name_fn = const char* (__cdecl*)(void*);

    auto get_persona_name = reinterpret_cast<get_persona_name_fn>(
        GetProcAddress(steam_api, "SteamAPI_ISteamFriends_GetPersonaName"));
    if (!get_persona_name)
        return cached_name;

    const char* versions[] = {
        "SteamAPI_SteamFriends_v018",
        "SteamAPI_SteamFriends_v017",
        "SteamAPI_SteamFriends_v016"
    };

    for (const char* version : versions) {
        auto get_steam_friends = reinterpret_cast<get_steam_friends_fn>(GetProcAddress(steam_api, version));
        if (!get_steam_friends)
            continue;

        void* steam_friends = get_steam_friends();
        if (!steam_friends)
            continue;

        const char* persona_name = get_persona_name(steam_friends);
        if (persona_name && persona_name[0] != '\0') {
            strncpy_s(cached_name, persona_name, _TRUNCATE);
            break;
        }
    }

    return cached_name;
}

static bool HandleOverlayDrag(float& x, float& y, bool& dragging, ImVec2& drag_offset, float w, float h) {
    ImGuiIO& io = ImGui::GetIO();
    ImVec2 mouse_pos = io.MousePos;
    const bool mouse_in_box = mouse_pos.x >= x && mouse_pos.x <= x + w &&
                              mouse_pos.y >= y && mouse_pos.y <= y + h;

    if (mouse_in_box && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && Menu::g_open && !UI::IsOpenColorPickerBlocking()) {
        dragging = true;
        drag_offset = ImVec2(mouse_pos.x - x, mouse_pos.y - y);
    }

    if (!dragging)
        return false;

    if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
        x = ImClamp(mouse_pos.x - drag_offset.x, 0.0f, io.DisplaySize.x - w);
        y = ImClamp(mouse_pos.y - drag_offset.y, 0.0f, io.DisplaySize.y - h);
        return true;
    }

    dragging = false;
    return false;
}

static bool IsBindFeatureEnabled(const std::string& id) {
    if (id == "toggle_menu")
        return true;

    if (id == "aimbot")
        return g_cfg->aim.any_group_has(&c_config::aim_t::group_t::m_aimbot);
    if (id == "triggerbot")
        return g_cfg->aim.any_group_has(&c_config::aim_t::group_t::m_triggerbot);
    if (id == "penetration")
        return g_cfg->aim.any_group_has(&c_config::aim_t::group_t::m_penetration);
    if (id == "jump_bug")
        return g_cfg->movement.m_jump_bug;
    if (id == "edge_jump")
        return g_cfg->movement.m_edge_jump;

    if (id == "mini_jump")
        return g_cfg->movement.m_mini_jump;
    if (id == "null_strafe")
        return s.null_strafe;
    if (id == "mousespeed_lim")
        return s.mousespeed_lim;

    return true;
}

struct spectator_row_t {
    std::string spectator;
    std::string target;
    bool watching_local = false;
};

static const char* GetControllerPlayerName(c_cs_player_controller* controller) {
    if (!controller)
        return "";

    __try {
        const char* name = controller->m_player_name();
        return name ? name : "";
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return "";
    }
}

static c_base_entity* GetBaseEntitySafe(int index) {
    if (!g_interfaces || !g_interfaces->m_entity_system)
        return nullptr;

    __try {
        return reinterpret_cast<c_base_entity*>(
            g_interfaces->m_entity_system->get_base_entity(index)
        );
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return nullptr;
    }
}

static bool IsPlayerControllerSafe(c_base_entity* entity) {
    if (!entity)
        return false;

    __try {
        return entity->is_player_controller();
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static bool IsPlayerPawnSafe(c_base_entity* entity) {
    if (!entity)
        return false;

    __try {
        return entity->is_player_pawn();
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static c_cs_player_controller* GetControllerFromPawn(c_cs_player_pawn* pawn) {
    if (!pawn || !g_interfaces || !g_interfaces->m_entity_system)
        return nullptr;

    __try {
        const auto controller_handle = pawn->m_controller();
        if (!controller_handle.is_valid())
            return nullptr;

        return reinterpret_cast<c_cs_player_controller*>(
            GetBaseEntitySafe(controller_handle.get_entry_index())
        );
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return nullptr;
    }
}

static c_cs_player_controller* FindControllerForPawn(c_cs_player_pawn* pawn, c_cs_player_controller* skip_controller) {
    if (!pawn || !g_interfaces || !g_interfaces->m_entity_system)
        return nullptr;

    int pawn_entry = -1;
    int pawn_handle_value = INVALID_EHANDLE_INDEX;

    __try {
        auto* identity = pawn->m_entity();
        if (identity)
            pawn_entry = identity->get_entry_index();
        pawn_handle_value = pawn->get_handle().to_int();
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return nullptr;
    }

    for (int i = 1; i <= 64; ++i) {
        auto* entity = GetBaseEntitySafe(i);
        if (!IsPlayerControllerSafe(entity))
            continue;

        auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
        if (controller == skip_controller)
            continue;

        __try {
            const auto handle = controller->m_pawn();
            if (!handle.is_valid())
                continue;

            if ((pawn_handle_value != INVALID_EHANDLE_INDEX && handle.to_int() == pawn_handle_value) ||
                (pawn_entry >= 0 && handle.get_entry_index() == pawn_entry)) {
                return controller;
            }
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            continue;
        }
    }

    return nullptr;
}

static c_cs_player_controller* FindControllerForPawnHandle(c_base_handle pawn_handle, c_cs_player_controller* skip_controller) {
    if (!pawn_handle.is_valid() || !g_interfaces || !g_interfaces->m_entity_system)
        return nullptr;

    const int pawn_entry = pawn_handle.get_entry_index();
    const int pawn_handle_value = pawn_handle.to_int();

    for (int i = 1; i <= 64; ++i) {
        auto* entity = GetBaseEntitySafe(i);
        if (!IsPlayerControllerSafe(entity))
            continue;

        auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
        if (controller == skip_controller)
            continue;

        __try {
            const auto handle = controller->m_pawn();
            if (!handle.is_valid())
                continue;

            if (handle.to_int() == pawn_handle_value || handle.get_entry_index() == pawn_entry)
                return controller;
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            continue;
        }
    }

    return nullptr;
}

static bool GetSpectatorLocalContext(c_cs_player_controller*& local_controller, c_cs_player_pawn*& local_pawn) {
    local_controller = nullptr;
    local_pawn = nullptr;
    if (!g_interfaces || !g_interfaces->m_entity_system)
        return false;

    __try {
        local_controller = reinterpret_cast<c_cs_player_controller*>(
            g_interfaces->m_entity_system->get_local_controller()
        );
        if (!local_controller)
            return false;

        const auto local_pawn_handle = local_controller->m_pawn();
        if (local_pawn_handle.is_valid()) {
            local_pawn = reinterpret_cast<c_cs_player_pawn*>(
                GetBaseEntitySafe(local_pawn_handle.get_entry_index())
            );
        }

        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        local_controller = nullptr;
        local_pawn = nullptr;
        return false;
    }
}

static void CopySpectatorText(char* dst, size_t dst_size, const char* src) {
    if (!dst || dst_size == 0)
        return;

    if (!src || src[0] == '\0')
        src = "unknown";

    strncpy_s(dst, dst_size, src, _TRUNCATE);
}

static bool TryBuildSpectatorRow(c_cs_player_controller* controller,
                                 c_cs_player_controller* local_controller,
                                 c_cs_player_pawn* local_pawn,
                                 char* spectator_name,
                                 size_t spectator_name_size,
                                 char* target_name,
                                 size_t target_name_size,
                                 bool& watching_local) {
    if (!controller || !local_controller || !spectator_name || !target_name)
        return false;

    spectator_name[0] = '\0';
    target_name[0] = '\0';
    watching_local = false;

    __try {
        const auto pawn_handle = controller->m_pawn();
        if (!pawn_handle.is_valid())
            return false;

        auto* pawn = reinterpret_cast<c_cs_player_pawn*>(
            GetBaseEntitySafe(pawn_handle.get_entry_index())
        );
        if (!pawn)
            return false;

        auto* observer_services = pawn->m_observer_services();
        if (!observer_services || observer_services->m_observer_mode() == 0)
            return false;

        const auto target_handle = observer_services->m_observer_target();
        if (!target_handle.is_valid())
            return false;

        auto* target_entity = GetBaseEntitySafe(target_handle.get_entry_index());
        if (!target_entity)
            return false;

        auto* target_pawn = IsPlayerPawnSafe(target_entity)
            ? reinterpret_cast<c_cs_player_pawn*>(target_entity)
            : nullptr;
        auto* target_controller = FindControllerForPawnHandle(target_handle, controller);
        if (!target_controller && target_pawn)
            target_controller = GetControllerFromPawn(target_pawn);
        if (!target_controller && target_pawn)
            target_controller = FindControllerForPawn(target_pawn, controller);
        if (!target_controller && IsPlayerControllerSafe(target_entity))
            target_controller = reinterpret_cast<c_cs_player_controller*>(target_entity);

        watching_local = (target_pawn && target_pawn == local_pawn) ||
                         (target_controller && target_controller == local_controller);

        CopySpectatorText(spectator_name, spectator_name_size, GetControllerPlayerName(controller));
        CopySpectatorText(target_name, target_name_size,
                          watching_local ? "you" : GetControllerPlayerName(target_controller));
        return true;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static std::vector<spectator_row_t> CollectSpectators() {
    std::vector<spectator_row_t> rows;

    c_cs_player_controller* local_controller = nullptr;
    c_cs_player_pawn* local_pawn = nullptr;
    if (!GetSpectatorLocalContext(local_controller, local_pawn))
        return rows;

    for (int i = 1; i <= 64; ++i) {
        auto* entity = GetBaseEntitySafe(i);
        if (!IsPlayerControllerSafe(entity))
            continue;

        auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
        if (controller == local_controller)
            continue;

        char spectator_name[64] = {};
        char target_name[64] = {};
        bool watching_local = false;
        if (TryBuildSpectatorRow(controller, local_controller, local_pawn,
                                 spectator_name, sizeof(spectator_name),
                                 target_name, sizeof(target_name),
                                 watching_local)) {
            rows.push_back({ spectator_name, target_name, watching_local });
        }
    }

    std::sort(rows.begin(), rows.end(), [](const spectator_row_t& a, const spectator_row_t& b) {
        return a.spectator < b.spectator;
    });

    return rows;
}

void Menu::RenderSpectators() {
    if (!s.ind_spectators)
        return;

    const auto rows = CollectSpectators();
    if (rows.empty())
        return;

    ImGuiIO& io = ImGui::GetIO();
    const float title_h = 24.0f;
    const float line_h = 1.0f;
    const float padding_x = 8.0f;
    const float row_h = 16.0f;
    float max_text_w = ImGui::CalcTextSize("spectators").x;
    for (const auto& row : rows) {
        std::string text = row.spectator + "->" + row.target;
        float tw = ImGui::CalcTextSize(text.c_str()).x;
        if (tw > max_text_w) max_text_w = tw;
    }
    float window_w = ImMax(150.0f, max_text_w + padding_x * 2.0f + 4.0f);
    const float window_h = title_h + line_h + 6.0f + (int)rows.size() * row_h + 8.0f;

    if (g_spectators_x < 0.0f || g_spectators_y < 0.0f) {
        g_spectators_x = 30.0f;
        g_spectators_y = io.DisplaySize.y * 0.5f;
    }
    else {
        g_spectators_x = ImClamp(g_spectators_x, 0.0f, io.DisplaySize.x - window_w);
        g_spectators_y = ImClamp(g_spectators_y, 0.0f, io.DisplaySize.y - window_h);
    }

    HandleOverlayDrag(g_spectators_x, g_spectators_y, g_spectators_dragging,
                      g_spectators_drag_offset, window_w, window_h);

    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    const ImVec2 box_min(g_spectators_x, g_spectators_y);
    const ImVec2 box_max(g_spectators_x + window_w, g_spectators_y + window_h);
    dl->AddRectFilled(box_min, box_max, Colors::MenuBg);

    const char* title = "spectators";
    const ImVec2 title_size = ImGui::CalcTextSize(title);
    dl->AddText(ImVec2(g_spectators_x + (window_w - title_size.x) * 0.5f,
                       g_spectators_y + (title_h - title_size.y) * 0.5f),
                Colors::MenuTitleText, title);

    ImVec4 accent = s.menu_color;
    accent.w = 1.0f;
    const ImU32 accent_clear = ImGui::ColorConvertFloat4ToU32(ImVec4(accent.x, accent.y, accent.z, 0.0f));
    const ImU32 accent_full = ImGui::ColorConvertFloat4ToU32(accent);
    const float line_y = g_spectators_y + title_h;
    const ImVec2 line_min(g_spectators_x, line_y);
    const ImVec2 line_mid(g_spectators_x + window_w * 0.5f, line_y + line_h);
    const ImVec2 line_max(g_spectators_x + window_w, line_y + line_h);
    dl->AddRectFilledMultiColor(line_min, line_mid, accent_clear, accent_full, accent_full, accent_clear);
    dl->AddRectFilledMultiColor(ImVec2(line_mid.x, line_min.y), line_max, accent_full, accent_clear, accent_clear, accent_full);

    float y = line_y + line_h + 6.0f;
    dl->PushClipRect(ImVec2(g_spectators_x + 2.0f, y - 1.0f),
                     ImVec2(g_spectators_x + window_w - 2.0f, box_max.y - 4.0f), true);
    for (const auto& row : rows) {
        std::string text = row.spectator + "->" + row.target;
        const ImU32 color = row.watching_local
            ? ImGui::ColorConvertFloat4ToU32(s.menu_color)
            : Colors::Text;
        dl->AddText(ImVec2(g_spectators_x + padding_x, y), color, text.c_str());
        y += row_h;
    }
    dl->PopClipRect();
}

void Menu::RenderBinds() {
    if (!s.ind_keybinds)
        return;
    if (!IsInActiveGameForIndicators())
        return;

    std::vector<std::pair<std::string, std::string>> active_binds;
    for (auto& [id, bind] : UI::g_binds) {
        if (bind.key.empty())
            continue;
        if (!IsBindFeatureEnabled(id))
            continue;

        bool is_active = false;
        if (bind.mode == UI::BindMode::Hold)
            is_active = UI::IsBindActive(id.c_str());
        else if (bind.mode == UI::BindMode::Toggle)
            is_active = bind.toggled;

        if (!is_active)
            continue;

        std::string display_name = id;
        if (id == "toggle_menu") display_name = "menu";
        else if (id == "esp_toggle") display_name = "esp";
        else if (id == "penetration") display_name = "autowall";
        else if (id == "edge_jump") display_name = "edge jump";

        active_binds.push_back({ display_name, bind.mode == UI::BindMode::Toggle ? "toggle" : "" });
    }

    if (active_binds.empty())
        return;

    ImGuiIO& io = ImGui::GetIO();
    const float title_h = 24.0f;
    const float line_h = 1.0f;
    const float padding_x = 8.0f;
    const float row_h = 16.0f;
    float max_text_w = ImGui::CalcTextSize("binds").x;
    for (const auto& [name, mode] : active_binds) {
        float tw = ImGui::CalcTextSize(name.c_str()).x;
        if (!mode.empty()) {
            float mw = ImGui::CalcTextSize((" " + mode).c_str()).x;
            tw += mw;
        }
        if (tw > max_text_w) max_text_w = tw;
    }
    float window_w = ImMax(150.0f, max_text_w + padding_x * 2.0f + 4.0f);
    const float window_h = title_h + line_h + 6.0f + (int)active_binds.size() * row_h + 8.0f;

    if (g_binds_window_x < 0.0f || g_binds_window_y < 0.0f) {
        g_binds_window_x = (io.DisplaySize.x - window_w) * 0.5f - 200.0f;
        g_binds_window_y = (io.DisplaySize.y - window_h) * 0.5f - 100.0f;
    }
    else {
        g_binds_window_x = ImClamp(g_binds_window_x, 0.0f, io.DisplaySize.x - window_w);
        g_binds_window_y = ImClamp(g_binds_window_y, 0.0f, io.DisplaySize.y - window_h);
    }

    HandleOverlayDrag(g_binds_window_x, g_binds_window_y, g_binds_window_dragging,
                      g_binds_drag_offset, window_w, window_h);

    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    const ImVec2 box_min(g_binds_window_x, g_binds_window_y);
    const ImVec2 box_max(g_binds_window_x + window_w, g_binds_window_y + window_h);
    dl->AddRectFilled(box_min, box_max, Colors::MenuBg);

    const char* title = "binds";
    const ImVec2 title_size = ImGui::CalcTextSize(title);
    dl->AddText(ImVec2(g_binds_window_x + (window_w - title_size.x) * 0.5f,
                       g_binds_window_y + (title_h - title_size.y) * 0.5f),
                Colors::MenuTitleText, title);

    ImVec4 accent = s.menu_color;
    accent.w = 1.0f;
    const ImU32 accent_clear = ImGui::ColorConvertFloat4ToU32(ImVec4(accent.x, accent.y, accent.z, 0.0f));
    const ImU32 accent_full = ImGui::ColorConvertFloat4ToU32(accent);
    const float line_y = g_binds_window_y + title_h;
    const ImVec2 line_min(g_binds_window_x, line_y);
    const ImVec2 line_mid(g_binds_window_x + window_w * 0.5f, line_y + line_h);
    const ImVec2 line_max(g_binds_window_x + window_w, line_y + line_h);
    dl->AddRectFilledMultiColor(line_min, line_mid, accent_clear, accent_full, accent_full, accent_clear);
    dl->AddRectFilledMultiColor(ImVec2(line_mid.x, line_min.y), line_max, accent_full, accent_clear, accent_clear, accent_full);

    float y = line_y + line_h + 6.0f;
    dl->PushClipRect(ImVec2(g_binds_window_x + 2.0f, y - 1.0f),
                     ImVec2(g_binds_window_x + window_w - 2.0f, box_max.y - 4.0f), true);
    for (const auto& [name, mode] : active_binds) {
        ImU32 color = Colors::Text;
        if (!mode.empty())
            color = ImGui::ColorConvertFloat4ToU32(s.menu_color);
        ImVec2 tp(g_binds_window_x + padding_x, y);
        dl->AddText(ImVec2(tp.x + 1.0f, tp.y + 1.0f), IM_COL32(0, 0, 0, 80), name.c_str());
        dl->AddText(ImVec2(tp.x, tp.y), color, name.c_str());
        y += row_h;
    }
    dl->PopClipRect();
}

void Menu::RenderWatermark() {
    if (!s.ind_watermark)
        return;

    ImGuiIO& io = ImGui::GetIO();

    // ── Collect segment data ────────────────────────────────────────────────
    // Segment 0: cheat name ("NF") — always visible
    // Segment 1: fps  (icon + value)   — bit 1
    // Segment 2: ping (icon + value)   — bit 2
    // Segment 3: time (icon + value)   — bit 3

    const int elems = s.watermark_elements;

    // FPS – update every 2 s to avoid flicker
    static char fps_buf[16]  = "--- fps";
    static double last_fps_t = 0.0;
    if ((elems & (1 << 1)) && (ImGui::GetTime() - last_fps_t >= 2.0)) {
        snprintf(fps_buf, sizeof(fps_buf), "%d fps", (int)io.Framerate);
        last_fps_t = ImGui::GetTime();
    }

    // Ping
    static char ping_buf[16] = "--- ms";
    static double last_ping_t = 0.0;
    if ((elems & (1 << 2)) && (ImGui::GetTime() - last_ping_t >= 1.0)) {
        uint32_t ping = 0;
        if (IsInActiveGameForIndicators()) {
            __try {
                auto* ctrl = reinterpret_cast<c_cs_player_controller*>(g_ctx->m_local_controller);
                if (ctrl) ping = ctrl->m_ping();
            } __except (EXCEPTION_EXECUTE_HANDLER) { ping = 0; }
        }
        if (ping > 999) ping = 0;
        snprintf(ping_buf, sizeof(ping_buf), "%u ms", ping);
        last_ping_t = ImGui::GetTime();
    }

    // Time
    static char time_buf[16] = "--:--";
    static double last_time_t = 0.0;
    if ((elems & (1 << 3)) && (ImGui::GetTime() - last_time_t >= 1.0)) {
        time_t now_t = time(nullptr);
        tm tm_s;
        localtime_s(&tm_s, &now_t);
        strftime(time_buf, sizeof(time_buf), "%H:%M", &tm_s);
        last_time_t = ImGui::GetTime();
    }

    // ── Geometry ────────────────────────────────────────────────────────────
    // Use the bold font for the cheat-name label, regular font for the rest.
    ImFont* bold_font    = g_menu ? g_menu->get_menu_bold_font() : nullptr;
    ImFont* regular_font = ImGui::GetFont();
    if (!bold_font) bold_font = regular_font;

    const float fs_bold = bold_font->FontSize;       // bold label size
    const float fs_reg  = regular_font->FontSize;    // segment text size

    const float pill_h     = 28.0f;                  // total pill height
    const float seg_pad_x  = 11.0f;                  // horizontal padding per segment
    const float icon_gap   = 5.0f;                   // gap between icon and text
    const float corner_r   = 10.0f;                  // rounded corners

    // ── Build segment list ──────────────────────────────────────────────────
    // Each segment: icon (FA glyph, drawn with regular font) + space + text.
    // Segment 0 has no icon (just the bold cheat name).
    struct Segment {
        const char* icon;     // FA UTF-8 string, nullptr for no icon
        const char* text;
        bool        use_bold;
    };

    Segment segs[4];
    int seg_count = 0;

    segs[seg_count++] = { nullptr,           "kolemba", true  };
    if (elems & (1 << 1)) segs[seg_count++] = { ICON_FA_CHART_BAR, fps_buf,  false };
    if (elems & (1 << 2)) segs[seg_count++] = { ICON_FA_WIFI,      ping_buf, false };
    if (elems & (1 << 3)) segs[seg_count++] = { ICON_FA_CLOCK,     time_buf, false };

    // Measure each segment width.
    // Icons are drawn with regular_font (FA is merged into it).
    float seg_widths[4] = {};
    float total_w = 0.0f;
    for (int i = 0; i < seg_count; i++) {
        ImFont* fnt = segs[i].use_bold ? bold_font : regular_font;
        float   fs  = segs[i].use_bold ? fs_bold   : fs_reg;
        float   tw  = fnt->CalcTextSizeA(fs, FLT_MAX, 0.0f, segs[i].text).x;
        float   iw  = segs[i].icon
                        ? regular_font->CalcTextSizeA(fs_reg, FLT_MAX, 0.0f, segs[i].icon).x + icon_gap
                        : 0.0f;
        seg_widths[i] = seg_pad_x * 2.0f + iw + tw;
        total_w += seg_widths[i];
    }
    if (total_w < 100.0f) total_w = 100.0f;
    if (g_watermark_x < 0.0f || g_watermark_y < 0.0f) {
        g_watermark_x = io.DisplaySize.x - total_w - 20.0f;
        g_watermark_y = 20.0f;
    } else {
        g_watermark_x = ImClamp(g_watermark_x, 0.0f, io.DisplaySize.x - total_w);
        g_watermark_y = ImClamp(g_watermark_y, 0.0f, io.DisplaySize.y - pill_h);
    }
    HandleOverlayDrag(g_watermark_x, g_watermark_y, g_watermark_dragging,
                      g_watermark_drag_offset, total_w, pill_h);

    // Publish blur coordinates so hooks.cpp can apply_blur before new_frame()
    g_watermark_blur_x = g_watermark_x;
    g_watermark_blur_y = g_watermark_y;
    g_watermark_blur_w = total_w;
    g_watermark_blur_h = pill_h;

    // ── Draw ─────────────────────────────────────────────────────────────────
    ImDrawList* dl  = ImGui::GetBackgroundDrawList();
    const float px  = g_watermark_x;
    const float py  = g_watermark_y;

    // Background pill — semi-transparent dark fill (blur underneath via hooks.cpp)
    dl->AddRectFilled(ImVec2(px, py), ImVec2(px + total_w, py + pill_h),
                      IM_COL32(20, 20, 24, 180), corner_r);
    // Thin border
    dl->AddRect(ImVec2(px, py), ImVec2(px + total_w, py + pill_h),
                IM_COL32(60, 60, 68, 120), corner_r, 0, 1.0f);

    // Dividers between segments (skip first to avoid drawing inside rounded cap)
    float div_x = px;
    for (int i = 0; i < seg_count; i++) {
        div_x += seg_widths[i];
        if (i < seg_count - 1) {
            dl->AddLine(ImVec2(div_x, py + 5.0f),
                        ImVec2(div_x, py + pill_h - 5.0f),
                        IM_COL32(60, 60, 68, 160), 1.0f);
        }
    }

    // Text content for each segment
    float cursor_x = px;
    const ImU32 icon_col = ImGui::ColorConvertFloat4ToU32(ImVec4(s.menu_color.x, s.menu_color.y, s.menu_color.z, 0.9f));
    for (int i = 0; i < seg_count; i++) {
        ImFont* fnt = segs[i].use_bold ? bold_font : regular_font;
        float   fs  = segs[i].use_bold ? fs_bold   : fs_reg;

        float iw = segs[i].icon
                     ? regular_font->CalcTextSizeA(fs_reg, FLT_MAX, 0.0f, segs[i].icon).x + icon_gap
                     : 0.0f;
        float tw      = fnt->CalcTextSizeA(fs, FLT_MAX, 0.0f, segs[i].text).x;
        float content = iw + tw;
        float cx      = cursor_x + (seg_widths[i] - content) * 0.5f;
        float cy_icon = py + (pill_h - fs_reg) * 0.5f;
        float cy_text = py + (pill_h - fs) * 0.5f;

        // FA icon
        if (segs[i].icon) {
            dl->AddText(regular_font, fs_reg, ImVec2(cx, cy_icon), icon_col, segs[i].icon);
            cx += iw;
        }

        // Label
        ImU32 text_col = segs[i].use_bold
            ? IM_COL32(245, 245, 245, 255)
            : IM_COL32(200, 200, 205, 230);

        dl->AddText(fnt, fs, ImVec2(cx + 1.0f, cy_text + 1.0f), IM_COL32(0, 0, 0, 140), segs[i].text);
        dl->AddText(fnt, fs, ImVec2(cx, cy_text), text_col, segs[i].text);

        cursor_x += seg_widths[i];
    }
}

void Menu::RenderSpotify() {
    if (!s.ind_spotify)
        return;

    static std::string song;
    static float last_poll = 0.0f;
    float now = static_cast<float>(ImGui::GetTime());
    if (now - last_poll > 1.0f) {
        last_poll = now;
        song.clear();
        DWORD spotify_pid = 0;
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (snap != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32W pe = { sizeof(PROCESSENTRY32W) };
            if (Process32FirstW(snap, &pe)) {
                do {
                    if (wcsstr(pe.szExeFile, L"Spotify.exe")) {
                        spotify_pid = pe.th32ProcessID;
                        break;
                    }
                } while (Process32NextW(snap, &pe));
            }
            CloseHandle(snap);
        }
        if (spotify_pid) {
            for (HWND hwnd = GetTopWindow(nullptr); hwnd; hwnd = GetWindow(hwnd, GW_HWNDNEXT)) {
                DWORD pid;
                GetWindowThreadProcessId(hwnd, &pid);
                if (pid != spotify_pid) continue;
                WCHAR title[256];
                GetWindowTextW(hwnd, title, 256);
                std::wstring wt(title);
                if (wt.find(L" - ") != std::wstring::npos) {
                    size_t sep = wt.find(L" - ");
                    std::wstring artist = wt.substr(sep + 3);
                    std::wstring song_name = wt.substr(0, sep);
                    std::wstring display = artist + L" - " + song_name;
                    int len = WideCharToMultiByte(CP_UTF8, 0, display.c_str(), -1, nullptr, 0, nullptr, nullptr);
                    song.resize(len);
                    WideCharToMultiByte(CP_UTF8, 0, display.c_str(), -1, &song[0], len, nullptr, nullptr);
                    song.resize(song.size() - 1);
                    break;
                }
            }
        }
    }

    if (song.empty())
        return;

    ImGuiIO& io = ImGui::GetIO();
    constexpr float scale = 1.1f;
    ImFont* font = ImGui::GetFont();
    const float font_size = font->FontSize;
    ImVec2 text_size = font->CalcTextSizeA(font_size, FLT_MAX, 0.0f, song.c_str());
    const float padding_x = 7.0f * scale;
    float box_w = std::floor(text_size.x + padding_x * 2.0f);
    const float box_h = 20.0f;
    const float line_h = 2.0f * scale;
    if (box_w < 64.0f)
        box_w = 64.0f;
    if (box_w > io.DisplaySize.x - 4.0f)
        box_w = io.DisplaySize.x - 4.0f;

    if (g_spotify_x < 0.0f || g_spotify_y < 0.0f) {
        g_spotify_x = io.DisplaySize.x - box_w - 20.0f;
        g_spotify_y = 44.0f;
    }
    else {
        g_spotify_x = ImClamp(g_spotify_x, 0.0f, io.DisplaySize.x - box_w);
        g_spotify_y = ImClamp(g_spotify_y, 0.0f, io.DisplaySize.y - box_h);
    }

    HandleOverlayDrag(g_spotify_x, g_spotify_y, g_spotify_dragging,
                      g_spotify_drag_offset, box_w, box_h);

    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    ImVec2 box_min(g_spotify_x, g_spotify_y);
    ImVec2 box_max(g_spotify_x + box_w, g_spotify_y + box_h);
    ImVec4 bg_col = ImGui::ColorConvertU32ToFloat4(Colors::MenuBg);
    bg_col.w = 0.5f;
    dl->AddRectFilled(box_min, box_max, ImGui::ColorConvertFloat4ToU32(bg_col));

    ImVec4 accent = s.menu_color;
    accent.w = 1.0f;
    const ImU32 accent_clear = ImGui::ColorConvertFloat4ToU32(ImVec4(accent.x, accent.y, accent.z, 0.0f));
    const ImU32 accent_full = ImGui::ColorConvertFloat4ToU32(accent);
    ImVec2 line_min(g_spotify_x, g_spotify_y);
    ImVec2 line_mid(g_spotify_x + box_w * 0.5f, g_spotify_y + line_h);
    ImVec2 line_max(g_spotify_x + box_w, g_spotify_y + line_h);
    dl->AddRectFilledMultiColor(line_min, line_mid, accent_clear, accent_full, accent_full, accent_clear);
    dl->AddRectFilledMultiColor(ImVec2(line_mid.x, line_min.y), line_max, accent_full, accent_clear, accent_clear, accent_full);

    float text_x = g_spotify_x + std::floor((box_w - text_size.x) * 0.5f);
    float text_y = g_spotify_y + std::floor((box_h - text_size.y) * 0.5f);
    dl->AddText(font, font_size, ImVec2(text_x + scale, text_y + scale), IM_COL32(0, 0, 0, 180), song.c_str());
    dl->AddText(font, font_size, ImVec2(text_x, text_y), Colors::MenuTitleText, song.c_str());
}

static std::pair<double, int> g_hit_markers[32];
static std::atomic<int> g_hit_marker_count{0};

void Menu::AddHitMarker(int hitgroup) {
    int idx = g_hit_marker_count.fetch_add(1, std::memory_order_relaxed);
    if (idx < 32)
        g_hit_markers[idx] = { ImGui::GetTime(), hitgroup };
    else
        g_hit_marker_count.fetch_sub(1, std::memory_order_relaxed);
}

void Menu::RenderHitMarkers() {
    if (!g_cfg->misc.m_hitmarker)
        return;

    int count = g_hit_marker_count.load(std::memory_order_relaxed);
    if (count == 0) return;

    double now = ImGui::GetTime();
    const double duration = 0.4;
    const float len = 7.0f;
    const float spread = 5.0f;
    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    ImVec2 center = ImGui::GetIO().DisplaySize;
    center.x *= 0.5f;
    center.y *= 0.5f;

    int write = 0;
    for (int i = 0; i < count; ++i) {
        double age = now - g_hit_markers[i].first;
        if (age > duration) continue;

        if (i != write)
            g_hit_markers[write] = g_hit_markers[i];
        ++write;

        float t = (float)(age / duration);
        float alpha = 1.0f - t;
        float dist = t * spread;
        bool hs = g_hit_markers[i].second == 1;
        ImU32 color = hs ? IM_COL32(255, 50, 50, (int)(alpha * 255))
                         : IM_COL32(255, 255, 255, (int)(alpha * 200));

        float dirs[4][2] = { {1,1}, {-1,1}, {-1,-1}, {1,-1} };
        for (auto& d : dirs) {
            ImVec2 p1(center.x + d[0] * (len * 0.3f + dist), center.y + d[1] * (len * 0.3f + dist));
            ImVec2 p2(center.x + d[0] * (len + dist), center.y + d[1] * (len + dist));
            dl->AddLine(p1, p2, color, hs ? 2.0f : 1.5f);
        }
    }

    if (write < count)
        g_hit_marker_count.store(write, std::memory_order_relaxed);
}

float Menu::GetWatermarkHeight() {
    if (!s.ind_watermark)
        return 0.0f;

    return 28.0f;
}

void Menu::RenderVelocityDisplay() {
    if (!s.vel_display)
        return;

    auto* local_player = GetLocalPawnForIndicators();
    if (!local_player)
        return;

    vec3_t velocity = local_player->m_vec_velocity();
    float speed_2d = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
    if (!isfinite(speed_2d))
        return;
    ImGuiIO& io = ImGui::GetIO();

    ImVec2 text_size = ImGui::CalcTextSize("999");
    const float padding = 10.0f;
    const float box_w = text_size.x * 2.5f + padding * 2.0f;
    const float box_h = text_size.y * 2.5f + padding * 2.0f;

    float pos_x = (io.DisplaySize.x - box_w) * 0.5f;
    float pos_y = io.DisplaySize.y - box_h - s.ind_offset;

    ImVec4 color = speed_2d < 200.0f ? s.vel_display_col1 :
                   speed_2d < 250.0f ? s.vel_display_col2 : s.vel_display_col3;

    char vel_text[64];
    snprintf(vel_text, sizeof(vel_text), "%.0f", speed_2d);

    ImFont* font = g_menu->get_vel_text_font();
    if (!font)
        font = ImGui::GetFont();
    float font_size = font->FontSize;

    ImVec2 scaled_text_size = font->CalcTextSizeA(font_size, FLT_MAX, -1.0f, vel_text);
    float text_x = pos_x + padding + floorf((box_w - padding * 2.0f - scaled_text_size.x) * 0.5f);
    float text_y = pos_y + padding + floorf((box_h - padding * 2.0f - scaled_text_size.y) * 0.5f);

    ImDrawList* draw = ImGui::GetBackgroundDrawList();
    draw->AddText(font, font_size, ImVec2(text_x + 1.0f, text_y + 1.0f),
        IM_COL32(0, 0, 0, 180), vel_text);
    draw->AddText(font, font_size, ImVec2(text_x, text_y),
        ImGui::ColorConvertFloat4ToU32(color), vel_text);
}

void Menu::RenderKeystrokes() {
    if (!s.keystrokes)
        return;

    ImGuiIO& io = ImGui::GetIO();
    ImDrawList* draw = ImGui::GetBackgroundDrawList();

    struct key_def_t { const char* label; int vk; };

    static const key_def_t row0[] = {
        { "C", VK_CONTROL },
        { "W", 'W' },
        { "J", VK_SPACE },
    };
    static const key_def_t row1[] = {
        { "A", 'A' },
        { "S", 'S' },
        { "D", 'D' },
    };

    const float cell_w = 23.0f;
    const float cell_h = 21.0f;
    const float gap_y = 15.0f;
    const float total_w = cell_w * 3.0f;
    const float total_h = cell_h * 2.0f + gap_y;

    const float base_x = (io.DisplaySize.x - total_w) * 0.5f;
    const float base_y = io.DisplaySize.y - total_h - s.ind_offset - 60.0f;

    ImFont* font = g_menu->get_keystrokes_font();
    if (!font)
        font = g_menu->get_menu_bold_font();
    if (!font)
        font = ImGui::GetFont();
    const float font_size = font->FontSize;
    const ImU32 col_text_press = IM_COL32(255, 255, 255, 255);

    auto draw_key = [&](float cx, float cy, const key_def_t& k) {
        bool pressed = (GetAsyncKeyState(k.vk) & 0x8000) != 0;
        const char* text = pressed ? k.label : "_";

        ImVec2 ts = font->CalcTextSizeA(font_size, FLT_MAX, 0.0f, text);
        float tx = cx + (cell_w - ts.x) * 0.5f;
        float ty = cy + (cell_h - ts.y) * 0.5f;
        draw->AddText(font, font_size, ImVec2(tx + 1.0f, ty + 1.0f), IM_COL32(0, 0, 0, 100), text);
        draw->AddText(font, font_size, ImVec2(tx, ty), col_text_press, text);
    };

    for (int i = 0; i < 3; ++i)
        draw_key(base_x + i * cell_w, base_y, row0[i]);
    for (int i = 0; i < 3; ++i)
        draw_key(base_x + i * cell_w, base_y + cell_h + gap_y, row1[i]);
}

void Menu::RenderVelocityGraph() {
    if (!s.vel_graph)
        return;

    auto* local_player = GetLocalPawnForIndicators();
    if (!local_player)
        return;

    vec3_t velocity = local_player->m_vec_velocity();
    float speed_2d = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
    if (!isfinite(speed_2d))
        return;
    g_velocity_history.push_back(speed_2d);
    if (g_velocity_history.size() > MAX_VELOCITY_SAMPLES)
        g_velocity_history.erase(g_velocity_history.begin());

    ImGuiIO& io = ImGui::GetIO();
    const float graph_w = 400.0f;
    const float graph_h = 100.0f;
    const float padding = 10.0f;
    const float box_w = graph_w + padding * 2.0f;
    const float box_h = graph_h + padding * 2.0f;

    float pos_x = (io.DisplaySize.x - box_w) * 0.5f;
    float pos_y = io.DisplaySize.y - box_h - s.ind_offset - 160.0f;

    if (g_velocity_history.size() <= 1)
        return;

    float max_vel = 400.0f;
    for (float v : g_velocity_history)
        if (v > max_vel) max_vel = v;

    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    ImVec2 graph_min(pos_x + padding, pos_y + padding);
    ImVec2 graph_max(pos_x + box_w - padding, pos_y + box_h - padding);
    ImU32 line_col_base = ImGui::ColorConvertFloat4ToU32(s.vel_graph_col);

    for (size_t i = 1; i < g_velocity_history.size(); i++) {
        float x1 = graph_min.x + (graph_w * (float)(i - 1)) / (float)(MAX_VELOCITY_SAMPLES - 1);
        float x2 = graph_min.x + (graph_w * (float)i) / (float)(MAX_VELOCITY_SAMPLES - 1);
        float y1 = graph_max.y - (graph_h * g_velocity_history[i - 1] / max_vel);
        float y2 = graph_max.y - (graph_h * g_velocity_history[i] / max_vel);

        float t1 = (float)(i - 1) / (float)(MAX_VELOCITY_SAMPLES - 1);
        float t2 = (float)i / (float)(MAX_VELOCITY_SAMPLES - 1);
        float fade1 = (t1 < 0.1f) ? (t1 / 0.1f) : ((t1 > 0.9f) ? ((1.0f - t1) / 0.1f) : 1.0f);
        float fade2 = (t2 < 0.1f) ? (t2 / 0.1f) : ((t2 > 0.9f) ? ((1.0f - t2) / 0.1f) : 1.0f);
        float alpha = (fade1 + fade2) * 0.5f;

        ImVec4 col4 = ImGui::ColorConvertU32ToFloat4(line_col_base);
        col4.w *= alpha;
        ImU32 col = ImGui::ColorConvertFloat4ToU32(col4);

        dl->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), col, 1.0f);
    }
}

void Menu::RenderMovementTrail() {
    if (!s.movement_trails || g_trail_positions.size() < 2)
        return;

    const auto now = std::chrono::steady_clock::now();

    const auto cutoff = now - std::chrono::milliseconds(static_cast<int>(TRAIL_DURATION * 1000.0f));
    size_t valid_count = 0;
    while (valid_count < g_trail_positions.size() && g_trail_positions[valid_count].time < cutoff)
        valid_count++;
    if (valid_count == g_trail_positions.size())
        return;
    if (valid_count > 0)
        g_trail_positions.erase(g_trail_positions.begin(), g_trail_positions.begin() + valid_count);

    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    const ImU32 col_base = ImGui::ColorConvertFloat4ToU32(g_cfg->indicators.m_movement_trails_col);

    ImVec2 prev_screen{};
    bool prev_valid = trail_world_to_screen(g_trail_positions[0].pos, prev_screen);
    for (size_t i = 1; i < g_trail_positions.size(); i++) {
        ImVec2 cur_screen{};
        const bool cur_valid = trail_world_to_screen(g_trail_positions[i].pos, cur_screen);
        if (prev_valid && cur_valid) {
            const float age = std::chrono::duration<float>(now - g_trail_positions[i].time).count();
            const float t = (TRAIL_DURATION - age) / TRAIL_DURATION;
            ImVec4 col4 = ImGui::ColorConvertU32ToFloat4(col_base);
            col4.w *= t;
            ImU32 col = ImGui::ColorConvertFloat4ToU32(col4);
            dl->AddLine(prev_screen, cur_screen, col, 2.0f);
        }
        prev_screen = cur_screen;
        prev_valid = cur_valid;
    }
}

void Menu::RenderWeatherEffects() {
    constexpr int kWeatherNone = 0;
    constexpr int kWeatherSnow = 1;
    constexpr int kWeatherRain = 2;

    static std::vector<ImVec2> positions;
    static std::vector<float> data;
    static int last_weather = 0;
    static bool initialized = false;

    ImGuiIO& io = ImGui::GetIO();
    const int weather = (s.menu_weather >= kWeatherNone && s.menu_weather <= kWeatherRain)
        ? s.menu_weather
        : kWeatherNone;

    if (!Menu::g_open || weather <= kWeatherNone || g_menu_alpha <= 0.0f) {
        if (initialized || !positions.empty() || !data.empty()) {
            positions.clear();
            data.clear();
            initialized = false;
            last_weather = 0;
        }
        return;
    }

    if (last_weather != weather) {
        positions.clear();
        data.clear();
        initialized = false;
        last_weather = weather;
    }

    const ImVec2 screen = io.DisplaySize;
    if (screen.x <= 1.0f || screen.y <= 1.0f)
        return;

    if (!initialized) {
        const int particle_count = weather == kWeatherSnow ? 200 : 400;
        positions.reserve(particle_count);
        data.reserve(particle_count * 5);

        for (int i = 0; i < particle_count; ++i) {
            positions.emplace_back(
                static_cast<float>(rand() % static_cast<int>(screen.x + 300.0f)) - 150.0f,
                static_cast<float>(rand() % static_cast<int>(screen.y + 100.0f)) - 50.0f
            );

            if (weather == kWeatherSnow) {
                data.push_back(30.0f + static_cast<float>(rand() % 40));
                data.push_back(1.5f + static_cast<float>(rand() % 100) * 0.02f);
                data.push_back(static_cast<float>(rand() % 100) * 0.01f);
                data.push_back(0.0f);
                data.push_back(0.0f);
            } else if (weather == kWeatherRain) {

                data.push_back(800.0f + static_cast<float>(rand() % 800));

                data.push_back((static_cast<float>(rand() % 100) - 50.0f) * 0.01f);
                data.push_back(15.0f + static_cast<float>(rand() % 40));
                data.push_back(0.5f + static_cast<float>(rand() % 100) * 0.01f);
                data.push_back(0.5f + static_cast<float>(rand() % 100) * 0.005f);
            }
        }

        initialized = true;
    }

    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    const float dt = ImClamp(io.DeltaTime, 0.0f, 0.05f);
    const int alpha = static_cast<int>(g_menu_alpha * 200.0f);
    const int soft_alpha = static_cast<int>(g_menu_alpha * 55.0f);
    for (size_t i = 0; i < positions.size(); ++i) {
        ImVec2& pos = positions[i];
        float& data0 = data[i * 5];
        float& data1 = data[i * 5 + 1];
        float& data2 = data[i * 5 + 2];
        float& data3 = data[i * 5 + 3];
        float& data4 = data[i * 5 + 4];
        const float speed = data0;
        const float angle = data1;
        const float length = data2;
        const float thickness = data3;
        const float opacity_var = data4;

        if (weather == kWeatherSnow) {
            pos.y += speed * dt;
            pos.x += sinf((pos.y + angle * 100.0f) * 0.01f) * 30.0f * dt;
        } else if (weather == kWeatherRain) {

            const float rain_angle = 0.5f + angle * 0.3f;
            const ImVec2 rain_dir(cosf(rain_angle), sinf(rain_angle));
            pos.x += rain_dir.x * speed * dt;
            pos.y += rain_dir.y * speed * dt;
        }

        if (pos.y > screen.y + 100.0f) {
            pos.y = -100.0f;
            pos.x = static_cast<float>(rand() % static_cast<int>(screen.x + 400.0f)) - 200.0f;
        }
        if (pos.x < -200.0f)
            pos.x = screen.x + 200.0f;
        if (pos.x > screen.x + 200.0f)
            pos.x = -200.0f;

        if (weather == kWeatherSnow) {
            dl->AddCircleFilled(pos, data[i * 5 + 1], IM_COL32(255, 255, 255, alpha));
            dl->AddCircleFilled(pos, data[i * 5 + 1] * 1.5f, IM_COL32(255, 255, 255, soft_alpha));
        } else if (weather == kWeatherRain) {

            const float rain_angle = 0.5f + angle * 0.3f;
            const ImVec2 rain_dir(cosf(rain_angle), sinf(rain_angle));
            const ImVec2 end(pos.x + rain_dir.x * length, pos.y + rain_dir.y * length);

            const int drop_alpha = static_cast<int>(g_menu_alpha * 180.0f * opacity_var);
            dl->AddLine(pos, end, IM_COL32(200, 220, 255, drop_alpha), thickness);

            const ImVec2 trail_end(pos.x - rain_dir.x * length * 0.4f, pos.y - rain_dir.y * length * 0.4f);
            const int trail_alpha = static_cast<int>(g_menu_alpha * 80.0f * opacity_var);
            dl->AddLine(trail_end, pos, IM_COL32(200, 220, 255, trail_alpha), thickness * 0.5f);

            dl->AddCircleFilled(end, thickness * 0.8f, IM_COL32(220, 240, 255, static_cast<int>(g_menu_alpha * 100.0f * opacity_var)));
        }
    }
}

static void RenderBankMenu() {
    static bool first_init = true;
    static float open_anim = 0.0f;
    static bool target_open = true;

    if (!s_menu_synced_from_config) {
        SyncMenuFromConfig();
        s_menu_synced_from_config = true;
    }
    if (!s_aim_synced_from_config) {
        SyncAimFromConfig();
        s_aim_synced_from_config = true;
    }
    if (!s_movement_synced_from_config) {
        SyncMovementFromConfig();
        s_movement_synced_from_config = true;
    }
    if (!s_indicators_synced_from_config) {
        SyncIndicatorsFromConfig();
        s_indicators_synced_from_config = true;
    }
    if (!s_visuals_synced_from_config) {
        SyncVisualsFromConfig();
        s_visuals_synced_from_config = true;
    }

    UI::InitBind("toggle_menu", "INS");
    UI::InitBind("jump_bug", "");
    UI::InitBind("edge_jump", "");
    if (first_init) {
        auto it = UI::g_binds.find("toggle_menu");
        if (it != UI::g_binds.end()) {
            it->second.mode = UI::BindMode::Toggle;
            it->second.toggled = true;
        }
        first_init = false;
        target_open = true;
        open_anim = 0.0f;
    }

    UI::UpdateBindCapture();

    auto menu_bind = UI::g_binds.find("toggle_menu");
    if (menu_bind != UI::g_binds.end() && menu_bind->second.mode == UI::BindMode::Toggle)
        target_open = menu_bind->second.toggled;

    ImGuiIO& io = ImGui::GetIO();
    if (UI::IsOpenColorPickerBlocking())
        io.WantCaptureMouse = true;

    if (target_open) {
        open_anim += io.DeltaTime * 8.0f;
        if (open_anim > 1.0f)
            open_anim = 1.0f;
    } else {
        open_anim -= io.DeltaTime * 8.0f;
        if (open_anim < 0.0f)
            open_anim = 0.0f;
    }

    s_menu_target_open = target_open;
    Menu::g_open = target_open || open_anim > 0.0f;
    g_menu_alpha = open_anim;

    if (open_anim <= 0.0f && !target_open)
        return;

    // Pull skin/knife/agent state from g_cfg into the display state `s`. The
    // skin changer itself reads g_cfg directly, so `s` is only ever needed for
    // the menu UI -- doing this here (instead of every frame in draw()) skips a
    // ~100-weapon struct copy on every frame the menu is closed, i.e. the whole
    // gameplay path. Runs before the UI is drawn and before SyncSkinsToConfig.
    SyncSkinsFromConfig();

    // Menu state is pushed to g_cfg once per frame, after the UI is drawn
    // (see the Sync*ToConfig block at the end of this function). Movement /
    // visuals / indicators used to be synced here as well, duplicating that
    // work every frame; only the menu sync that must happen before ApplyTheme
    // stays here.
    SyncMenuToConfig();

    {
        ImVec4 mc = s.menu_color;
        Colors::Accent      = ImGui::ColorConvertFloat4ToU32(mc);
        ImVec4 hov(ImMin(mc.x * 1.09f, 1.0f), ImMin(mc.y * 1.09f, 1.0f),
                   ImMin(mc.z * 1.09f, 1.0f), mc.w);
        Colors::AccentHover  = ImGui::ColorConvertFloat4ToU32(hov);
        ImVec4 dark(mc.x * 0.32f, mc.y * 0.32f, mc.z * 0.32f, mc.w);
        Colors::AccentDark   = ImGui::ColorConvertFloat4ToU32(dark);
        ImVec4 bh(mc.x * 0.82f, mc.y * 0.82f, mc.z * 0.82f, mc.w);
        Colors::CbBorderHov  = ImGui::ColorConvertFloat4ToU32(bh);
    }
    ApplyTheme();
    static float s_menu_w = MENU_W;
    static float s_menu_h = MENU_H;
    static float s_menu_x = -1.0f;
    static float s_menu_y = -1.0f;
    const float scale_x = s_menu_w / ::MENU_W;
    const float scale_y = s_menu_h / ::MENU_H;
    const float ui_scale = ImClamp(ImMin(scale_x, scale_y), 0.90f, 1.18f);
    const float l_menu_w = s_menu_w;
    const float l_sidebar_w = ::SIDEBAR_W * ui_scale;
    // const float l_title_h = ::TITLE_H * ui_scale;  // Unused
    const float l_padding = ::PADDING * ui_scale;
    const float l_l_w = ::L_W * scale_x;
    const float l_gap = ::GAP * scale_x;
    const float l_r_x = l_padding + l_l_w + l_gap;
    const float l_r_w = l_menu_w - l_r_x - l_padding;
    const float l_box_pad = ::BOX_PAD * ui_scale;
    const float total_w = s_menu_w + l_sidebar_w;
    const float total_h = s_menu_h;
    if (s_menu_x < 0.0f || s_menu_y < 0.0f) {
        s_menu_x = (io.DisplaySize.x - total_w) * 0.5f;
        s_menu_y = (io.DisplaySize.y - total_h) * 0.5f;
    }

    const float drag_area_h = s_menu_h;
    const bool mouse_in_drag_area =
        io.MousePos.x >= s_menu_x && io.MousePos.x <= (s_menu_x + total_w) &&
        io.MousePos.y >= s_menu_y && io.MousePos.y <= (s_menu_y + drag_area_h);

    bool over_custom_scrollbar = false;
    if (s.active_tab == 0 || s.active_tab == 1 || s.active_tab == 2) {
        float sb_x = s_menu_x + l_sidebar_w + l_padding + l_l_w;
        over_custom_scrollbar = io.MousePos.x >= sb_x - 6.0f && io.MousePos.x <= sb_x;
    }
    if (s.active_tab == 1 && !over_custom_scrollbar) {
        float skin_list_w = 140.0f;
        float skin_list_x = l_r_x + (l_r_w - skin_list_w) * 0.5f;
        over_custom_scrollbar = io.MousePos.x >= s_menu_x + l_sidebar_w + skin_list_x + skin_list_w - 6.0f && io.MousePos.x <= s_menu_x + l_sidebar_w + skin_list_x + skin_list_w;
    }

    const bool can_begin_drag =
        mouse_in_drag_area &&
        !ImGui::IsAnyItemHovered() &&
        !ImGui::IsAnyItemActive() &&
        !over_custom_scrollbar;

    if (!ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
        g_menu_dragging = false;
    } else if (!g_menu_dragging && can_begin_drag && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking()) {
        g_menu_dragging = true;
    }

    if (g_menu_dragging && !s_models_dragging && !s_skin_dragging && !s_skin_preview_dragging && !s_esp_dragging && !s_move_dragging && !s_misc_dragging && !s_env_dragging && !s_friend_dragging && !s_tchams_dragging) {
        s_menu_x = ImClamp(s_menu_x + io.MouseDelta.x, 0.0f, io.DisplaySize.x - total_w);
        s_menu_y = ImClamp(s_menu_y + io.MouseDelta.y, 0.0f, io.DisplaySize.y - total_h);
    }

    if (s_models_dragging || s_skin_dragging || s_skin_preview_dragging || s_esp_dragging || s_move_dragging || s_misc_dragging || s_env_dragging || s_friend_dragging || s_tchams_dragging)
        io.WantCaptureMouse = true;

    ImGui::SetNextWindowPos(ImVec2(s_menu_x, s_menu_y));
    ImGui::SetNextWindowSize(ImVec2(total_w, total_h));
    ImGuiWindowFlags wf =
        ImGuiWindowFlags_NoTitleBar        |
        ImGuiWindowFlags_NoResize          |
        ImGuiWindowFlags_NoScrollbar       |
        ImGuiWindowFlags_NoScrollWithMouse |
        ImGuiWindowFlags_NoBackground      |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoMove;

    // Плавная тень позади меню
    {
        ImDrawList* dl_bg = ImGui::GetBackgroundDrawList();
        const float shadow_r = 20.0f;  // радиус скругления как у меню
        const int   shadow_layers = 12;
        const float shadow_spread = 28.0f;
        ImVec2 p0(s_menu_x, s_menu_y);
        ImVec2 p1(s_menu_x + total_w, s_menu_y + total_h);
        for (int i = shadow_layers; i >= 1; i--) {
            float t      = (float)i / (float)shadow_layers;
            float expand = shadow_spread * t;
            float alpha  = open_anim * 0.18f * (1.0f - t) * (1.0f - t);
            ImU32 col    = IM_COL32(0, 0, 0, (int)(alpha * 255.0f));
            dl_bg->AddRectFilled(
                ImVec2(p0.x - expand, p0.y - expand),
                ImVec2(p1.x + expand, p1.y + expand),
                col,
                shadow_r + expand * 0.6f
            );
        }
    }

    ImGui::PushStyleVar(ImGuiStyleVar_Alpha,         open_anim);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing,   ImVec2(0, 0));

    ImGui::Begin("##celerity", nullptr, wf);
    ImGui::PopStyleVar(2); // только WindowPadding + ItemSpacing; Alpha держим до End
    ImDrawList* dl_frame   = ImGui::GetWindowDrawList();
    ImVec2      wpos_frame = ImGui::GetWindowPos();

    // Применяем open_anim к alpha всех DrawList операций через глобальный множитель
    dl_frame->PushClipRect(ImVec2(wpos_frame.x, wpos_frame.y),
                            ImVec2(wpos_frame.x + total_w, wpos_frame.y + total_h), false);

    // Хелпер: применяет open_anim к alpha компоненту цвета
    auto FadeCol = [&](ImU32 col) -> ImU32 {
        int a = (int)(((col >> 24) & 0xFF) * open_anim);
        return (col & 0x00FFFFFF) | ((ImU32)a << 24);
    };

    auto S_frame = [&](float x, float y) { return ImVec2(wpos_frame.x + x, wpos_frame.y + y); };
    const float menu_r = 20.0f;
    {
        const ImU32 sb_col = IM_COL32(8, 8, 10, 160);
        dl_frame->AddRectFilled(wpos_frame, ImVec2(wpos_frame.x + l_sidebar_w, wpos_frame.y + total_h),
            FadeCol(sb_col), menu_r, ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersBottomLeft);
    }
    dl_frame->AddRectFilled(ImVec2(wpos_frame.x + l_sidebar_w, wpos_frame.y),
        ImVec2(wpos_frame.x + total_w, wpos_frame.y + total_h), FadeCol(Colors::MenuBg), menu_r,
        ImDrawFlags_RoundCornersTopRight | ImDrawFlags_RoundCornersBottomRight);
    const float content_x = wpos_frame.x + l_sidebar_w;
    const float side_strip_w = 1.0f;
    const float side_strip_x_offset = 0.0f;
    const float side_strip_top = 0.0f;
    const float side_strip_bottom = s_menu_h;
    const ImU32 side_strip_col = Colors::SideStrip;
    dl_frame->AddRectFilled(ImVec2(content_x + side_strip_x_offset, wpos_frame.y + side_strip_top),
                      ImVec2(content_x + side_strip_x_offset + side_strip_w, wpos_frame.y + side_strip_bottom),
                      FadeCol(side_strip_col), 0.0f);

    const int a = (int)(open_anim * 255.0f);
    if (a > 0) {
    }
    const float lh   = ImGui::GetTextLineHeight();
    {
        const float sb_x = wpos_frame.x;
        const float sb_y = wpos_frame.y;
        const float sb_w = l_sidebar_w;
        const float header_h = 92.0f;
        const float tab_pad = 5.0f;
        const float tab_gap = 5.0f;
        const float tab_h = 26.0f;
        const float tab_start = sb_y + header_h + 0.0f;
        ImVec2 mouse = ImGui::GetIO().MousePos;

        const char* title = "kolemba";
        if (auto* title_font = g_menu ? g_menu->get_sidebar_title_font() : nullptr)
            ImGui::PushFont(title_font);
        ImVec2 title_ts = ImGui::CalcTextSize(title);
        dl_frame->AddText(ImVec2(sb_x + (sb_w - title_ts.x) * 0.5f, sb_y + 44.0f - title_ts.y * 0.5f),
                          Colors::Accent, title);
        if (g_menu && g_menu->get_sidebar_title_font())
            ImGui::PopFont();

        static const char* k_tab_icons[] = {
            ICON_FA_USER_GROUP,
            ICON_FA_PAINTBRUSH,
            ICON_FA_GLOBE,
            ICON_FA_COG,
            ICON_FA_FOLDER,
        };

        struct SidebarGroup {
            const char* label;
            int tab_indices[4];
            int count;
        };

        static const SidebarGroup k_groups[] = {
            { "visuals", { 0,  1,  2, -1 }, 3 },
            { "misc",    { 3, -1, -1, -1 }, 1 },
            { "system",  { 4, -1, -1, -1 }, 1 },
        };

        float t_y = tab_start;
        const float group_label_h = lh + 6.0f;
        const float group_gap = 4.0f;

        for (auto& grp : k_groups) {
            // группа-заголовок
            dl_frame->AddText(ImVec2(sb_x + 14.0f, t_y), Colors::TextDim, grp.label);
            t_y += group_label_h;

            for (int g = 0; g < grp.count; g++) {
                int i = grp.tab_indices[g];
                float t_y0 = t_y;
                float t_y1 = t_y0 + tab_h;
                bool hov = mouse.x >= sb_x && mouse.x <= sb_x + sb_w &&
                           mouse.y >= t_y0 && mouse.y <= t_y1;
                bool active = (i == s.active_tab);
                if (hov && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking())
                    s.active_tab = i;
                if (active || hov) {
                    ImU32 row_col = active ? IM_COL32(36, 36, 36, 200) : IM_COL32(28, 28, 28, 190);
                    dl_frame->AddRectFilled(ImVec2(sb_x + 10.0f, t_y0), ImVec2(sb_x + sb_w - 12.0f, t_y1), row_col, 5.0f);
                }
                ImU32 tc = active ? Colors::TextBright : Colors::TextDim;
                float icon_offset = 20.0f;
                ImU32 ic = active ? Colors::Accent : Colors::AccentDark;
                dl_frame->AddText(ImVec2(sb_x + icon_offset, t_y0 + tab_pad), ic, k_tab_icons[i]);
                dl_frame->AddText(ImVec2(sb_x + icon_offset + ImGui::CalcTextSize(k_tab_icons[i]).x + 6.0f, t_y0 + tab_pad), tc, k_tabs[i]);
                t_y += tab_h + tab_gap;
            }
            t_y += group_gap;
        }
    }
    const float cy   = ImMax(10.0f * ui_scale, ImGui::GetTextLineHeight() * 0.5f + 6.0f * ui_scale);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarSize, 6.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarRounding, 0.0f);
    ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, Colors::ScrollbarTrack);
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab, Colors::ScrollbarGrab);
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered, Colors::ScrollbarGrabHover);
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, Colors::ScrollbarGrabActive);
    ImGui::PushStyleVar(ImGuiStyleVar_GrabMinSize, 4.0f);
    ImGui::SetCursorPos(ImVec2(l_sidebar_w, 0.0f));
    ImGui::BeginChild("##menu_content", ImVec2(s_menu_w, s_menu_h), false,
                      ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    {
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 wpos = ImGui::GetWindowPos();

    ImVec2 clip_min = ImVec2(wpos.x, wpos.y);
    ImVec2 clip_max = ImVec2(wpos.x + s_menu_w, wpos.y + s_menu_h);
    dl->PushClipRect(clip_min, clip_max, true);

    auto S = [&](float x, float y) { return ImVec2(wpos.x + x, wpos.y + y); };
    auto reserve_content_bottom = [&](float bottom_y) {
        ImGui::SetCursorPos(ImVec2(0.0f, bottom_y));
        ImGui::Dummy(ImVec2(1.0f, 1.0f));
    };
    if (s.active_tab == 0) {
        float subtab_y = 4.0f * ui_scale;
        s.visuals_subtab = UI::SubTabBar(k_visuals_subtabs, 3, s.visuals_subtab,
                                         ImVec2(wpos.x, wpos.y + subtab_y), l_padding);
        float content_y = lh + 18.0f * ui_scale;
        ImGui::SetCursorPos(ImVec2(0, content_y));
        if (s.visuals_subtab == 0) {
            static float s_esp_scroll_y = 0.0f;

            const float field_w = l_l_w - l_box_pad * 2;
            float l_sr = wpos.x + l_padding + l_l_w - l_box_pad;
            const float gap2 = 2.0f;

            float esp_avail_h = (s_menu_h) - content_y - 10.0f;
            float esp_box_h = esp_avail_h;
            float esp_box_bottom = content_y + esp_box_h;
            DrawBox(dl, wpos, l_padding, content_y, esp_box_bottom, l_l_w, "enemy esp", Colors::ColHdr);

            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + content_y + l_box_pad + 10.0f));
            ImGui::BeginChild("##esp_scroll", ImVec2(field_w, esp_box_h - l_box_pad * 2 - 10.0f), false,
                ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            ImGui::SetScrollY(s_esp_scroll_y);

            float ly = 0.0f;
            float next_ly;

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("box", &g_cfg->visuals.m_box, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##enemy_box_col", &g_cfg->visuals.m_box_color, l_sr, 0.0f);
            ly = next_ly;

            if (g_cfg->visuals.m_box) {
                g_cfg->visuals.m_corner_length = ImClamp(g_cfg->visuals.m_corner_length, 0.005f, 0.5f);
                float corner_length_pct = g_cfg->visuals.m_corner_length * 200.0f;
                ImGui::SetCursorPos(ImVec2(0, ly));
                if (UI::SliderFloat("##corner_length", &corner_length_pct, 1.0f, 100.0f, "%", "%.0f", field_w))
                    g_cfg->visuals.m_corner_length = corner_length_pct * 0.005f;
                ly = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("name", &g_cfg->visuals.m_name, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##enemy_name_col", &g_cfg->visuals.m_name_color, l_sr, 0.0f);
            ly = next_ly;

            ImGui::SetCursorPos(ImVec2(0, ly));
            bool has_health_bar = (g_cfg->visuals.m_health_type & (1 << 1)) != 0;
            bool has_health_gradient = (g_cfg->visuals.m_health_type & (1 << 2)) != 0;
            bool show_health_colors = has_health_bar || has_health_gradient;
            UI::Checkbox("health", &g_cfg->visuals.m_health_bar, nullptr, nullptr, show_health_colors ? (has_health_gradient ? (field_w - 48.0f) : (field_w - 22.0f)) : field_w);
            next_ly = ImGui::GetCursorPos().y + gap2;
            if (show_health_colors) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                if (has_health_gradient) {
                    UI::ColorPicker("##enemy_health_low_col", &g_cfg->visuals.m_health_low_color, l_sr, COLOR_PICKER_STEP);
                    ImGui::SetCursorPos(ImVec2(0, ly));
                    UI::ColorPicker("##enemy_health_high_col", &g_cfg->visuals.m_health_high_color, l_sr, 0.0f);
                } else {
                    UI::ColorPicker("##enemy_health_high_col", &g_cfg->visuals.m_health_high_color, l_sr, 0.0f);
                }
            }
            ly = next_ly;

            static const char* health_types[] = { "text", "bar", "gradient" };
            if (g_cfg->visuals.m_health_bar) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                UI::MultiSelectDropdown("##health_type", &g_cfg->visuals.m_health_type, health_types, 3, field_w);
                ly = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("skeleton", &g_cfg->visuals.m_skeleton, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##enemy_skeleton_col", &g_cfg->visuals.m_skeleton_color, l_sr, 0.0f);
            ly = next_ly;

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("weapon", &g_cfg->visuals.m_weapon, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##enemy_weapon_col", &g_cfg->visuals.m_weapon_color, l_sr, 0.0f);
            ly = next_ly;

            static const char* weapon_types[] = { "text", "icon" };
            if (g_cfg->visuals.m_weapon) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                UI::MultiSelectDropdown("##weapon_type", &g_cfg->visuals.m_weapon_type, weapon_types, 2, field_w);
                ly = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, ly));
            bool has_ammo_bar = (g_cfg->visuals.m_ammo_type & (1 << 1)) != 0;
            bool has_ammo_gradient = (g_cfg->visuals.m_ammo_type & (1 << 2)) != 0;
            bool show_ammo_colors = has_ammo_bar || has_ammo_gradient;
            UI::Checkbox("ammo", &g_cfg->visuals.m_ammo, nullptr, nullptr, show_ammo_colors ? (has_ammo_gradient ? (field_w - 48.0f) : (field_w - 22.0f)) : field_w);
            next_ly = ImGui::GetCursorPos().y + gap2;
            if (show_ammo_colors) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                if (has_ammo_gradient) {
                    UI::ColorPicker("##enemy_ammo_low_col", &g_cfg->visuals.m_ammo_low_color, l_sr, COLOR_PICKER_STEP);
                    ImGui::SetCursorPos(ImVec2(0, ly));
                    UI::ColorPicker("##enemy_ammo_high_col", &g_cfg->visuals.m_ammo_high_color, l_sr, 0.0f);
                } else {
                    UI::ColorPicker("##enemy_ammo_high_col", &g_cfg->visuals.m_ammo_high_color, l_sr, 0.0f);
                }
            }
            ly = next_ly;

            static const char* ammo_types[] = { "text", "bar", "gradient" };
            if (g_cfg->visuals.m_ammo) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                UI::MultiSelectDropdown("##ammo_type", &g_cfg->visuals.m_ammo_type, ammo_types, 3, field_w);
                ly = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("flags", &g_cfg->visuals.m_flags, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##flags_col", &g_cfg->visuals.m_flags_color, l_sr, 0.0f);
            ly = next_ly;

            static const char* flags_types[] = { "distance", "cash", "armor", "scoped", "bomb" };
            if (g_cfg->visuals.m_flags) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                UI::MultiSelectDropdown("##flags_type", &g_cfg->visuals.m_flags_type, flags_types, 5, field_w);
                ly = ImGui::GetCursorPos().y + gap2;
            }

            float esp_content_h = ly;
            ImGui::SetCursorPos(ImVec2(0, ly));
            ImGui::Dummy(ImVec2(1.0f, 1.0f));
            ImGui::EndChild();

            float esp_view_h = esp_box_h - l_box_pad * 2 - 10.0f;
            float esp_max_scroll = ImMax(0.0f, esp_content_h - esp_view_h);
            ScrollEase(s_esp_scroll_y, esp_max_scroll);
            s_esp_scroll_y = ImClamp(s_esp_scroll_y, 0.0f, esp_max_scroll);

            float esp_box_right = wpos.x + l_padding + l_l_w;
            float esp_scroll_top = wpos.y + content_y;
            float esp_scroll_bottom = wpos.y + content_y + esp_box_h;
            ImVec2 esp_area_min = ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + content_y + l_box_pad + 10.0f);
            ImVec2 esp_area_max = ImVec2(esp_area_min.x + field_w, wpos.y + content_y + esp_box_h - l_box_pad);
            ImVec2 ms = ImGui::GetIO().MousePos;

            if (esp_max_scroll > 0.0f) {
                float track_h = esp_scroll_bottom - esp_scroll_top;
                float thumb_h = ImMax(4.0f, track_h * (esp_view_h / esp_content_h) * 0.4f);
                float thumb_y = esp_scroll_top + (s_esp_scroll_y / esp_max_scroll) * (track_h - thumb_h);

                bool esp_hovered = (ms.x >= esp_area_min.x && ms.x <= esp_area_max.x &&
                    ms.y >= esp_area_min.y && ms.y <= esp_area_max.y);

                bool over_thumb = (ms.x >= esp_box_right - 6.0f && ms.x <= esp_box_right &&
                    ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

                if (!s_esp_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                    s_esp_dragging = true;
                    s_esp_drag_start_y = ms.y;
                    s_esp_drag_scroll = s_esp_scroll_y;
                }
                if (s_esp_dragging) {
                    if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                        float delta = ms.y - s_esp_drag_start_y;
                        float track_diff = track_h - thumb_h;
                        if (track_diff > 0.0001f) {
                            s_esp_scroll_y = ImClamp(s_esp_drag_scroll + delta / track_diff * esp_max_scroll, 0.0f, esp_max_scroll);
                            ScrollTarget(s_esp_scroll_y) = s_esp_scroll_y;
                        }
                        ImGui::GetIO().WantCaptureMouse = true;
                    }
                    else {
                        s_esp_dragging = false;
                    }
                }

                if (esp_hovered && !over_thumb && !s_esp_dragging && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking()) {
                    float& tgt = ScrollTarget(s_esp_scroll_y);
                    tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 40.0f, 0.0f, esp_max_scroll);
                    ImGui::GetIO().WantCaptureMouse = true;
                }

                ImU32 thumb_col = s_esp_dragging ? Colors::Accent : Colors::ScrollbarGrab;

                dl->AddRectFilled(ImVec2(esp_box_right - 6.0f, esp_scroll_top),
                    ImVec2(esp_box_right, esp_scroll_bottom), Colors::ScrollbarTrack, 0.0f);
                dl->AddRectFilled(ImVec2(esp_box_right - 5.0f, thumb_y),
                    ImVec2(esp_box_right - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
            }
            else {
                s_esp_dragging = false;
            }

            float chams_box_top = content_y;
            float ry = chams_box_top + l_box_pad + 10.0f;
            const float r_field_w = l_r_w - l_box_pad * 2;
            float r_sr = wpos.x + l_r_x + l_r_w - l_box_pad;

            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("glow", &g_cfg->visuals.m_glow, nullptr, nullptr, r_field_w - 22.0f);
            float next_glow_ry = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::ColorPicker("##glow_col", &g_cfg->visuals.m_glow_color, r_sr, 0.0f);
            ry = next_glow_ry;

            static const char* chams_materials[] = { "flat", "glow", "ghost", "textured", "metallic" };

            // Enemy chams only -- teammate/arms/viewmodel chams live in the "friendly" subtab.
            auto& enemy_ct = g_cfg->visuals.m_chams_targets[c_config::visuals_t::chams_target_enemy];

            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("visible", &enemy_ct.m_visible, nullptr, nullptr, r_field_w - 22.0f);
            float next_cv_ry = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::ColorPicker("##chams_vis_col", &enemy_ct.m_visible_color, r_sr, 0.0f);
            ry = next_cv_ry;

            if (enemy_ct.m_visible) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::Dropdown("##chams_vis_mat", &enemy_ct.m_visible_material, chams_materials, 5, r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("occluded", &enemy_ct.m_occluded, nullptr, nullptr, r_field_w - 22.0f);
            float next_co_ry = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::ColorPicker("##chams_occ_col", &enemy_ct.m_occluded_color, r_sr, 0.0f);
            ry = next_co_ry;

            if (enemy_ct.m_occluded) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::Dropdown("##chams_occ_mat", &enemy_ct.m_occluded_material, chams_materials, 5, r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }

            float right_total_avail = (s_menu_h) - 10.0f - chams_box_top;
            float chams_box_bottom = chams_box_top + right_total_avail;
            DrawBox(dl, wpos, l_r_x, chams_box_top, chams_box_bottom, l_r_w, "enemy chams", Colors::ColHdr);

            reserve_content_bottom(ImMax(esp_box_bottom, chams_box_bottom));
        }
        else if (s.visuals_subtab == 1) {
            const float field_w = l_l_w - l_box_pad * 2;
            float l_sr = wpos.x + l_padding + l_l_w - l_box_pad;
            const float gap2 = 2.0f;
            float next_ly;

            // Fixed 60/40 vertical split of the left column: friendly ESP (60%) on top,
            // teammate chams (40%) below. Both boxes are fixed-height and scroll on overflow.
            const float l_col_gap = 8.0f;
            float lbox_top = content_y;
            float l_col_bottom = (s_menu_h) - 10.0f;
            float lbox_h = (l_col_bottom - lbox_top - l_col_gap) * 0.6f;
            float lbox_bottom = lbox_top + lbox_h;
            float cbox_top = lbox_bottom + l_col_gap;
            float cbox_bottom = l_col_bottom;
            float cbox_h = cbox_bottom - cbox_top;

            // --- friendly box (fixed 60%, scrollable) ---
            DrawBox(dl, wpos, l_padding, lbox_top, lbox_bottom, l_l_w, "friendly", Colors::ColHdr);

            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + lbox_top + l_box_pad + 10.0f));
            ImGui::BeginChild("##friendly_scroll", ImVec2(field_w, lbox_h - l_box_pad * 2 - 10.0f), false,
                ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            ImGui::SetScrollY(s_friend_scroll_y);

            float ly = 0.0f;

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("box", &g_cfg->visuals.m_teammate_box, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##team_box_col", &g_cfg->visuals.m_teammate_box_color, l_sr, 0.0f);
            ly = next_ly;

            if (g_cfg->visuals.m_teammate_box) {
                g_cfg->visuals.m_teammate_corner_length = ImClamp(g_cfg->visuals.m_teammate_corner_length, 0.005f, 0.5f);
                float corner_length_pct = g_cfg->visuals.m_teammate_corner_length * 200.0f;
                ImGui::SetCursorPos(ImVec2(0, ly));
                if (UI::SliderFloat("##team_corner_length", &corner_length_pct, 1.0f, 100.0f, "%", "%.0f", field_w))
                    g_cfg->visuals.m_teammate_corner_length = corner_length_pct * 0.005f;
                ly = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("name", &g_cfg->visuals.m_teammate_name, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##team_name_col", &g_cfg->visuals.m_teammate_name_color, l_sr, 0.0f);
            ly = next_ly;

            ImGui::SetCursorPos(ImVec2(0, ly));
            bool has_team_health_bar = (g_cfg->visuals.m_teammate_health_type & (1 << 1)) != 0;
            bool has_team_health_gradient = (g_cfg->visuals.m_teammate_health_type & (1 << 2)) != 0;
            bool show_team_health_colors = has_team_health_bar || has_team_health_gradient;
            UI::Checkbox("health", &g_cfg->visuals.m_teammate_health_bar, nullptr, nullptr, show_team_health_colors ? (has_team_health_gradient ? (field_w - 48.0f) : (field_w - 22.0f)) : field_w);
            next_ly = ImGui::GetCursorPos().y + gap2;
            if (show_team_health_colors) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                if (has_team_health_gradient) {
                    UI::ColorPicker("##team_health_low_col", &g_cfg->visuals.m_teammate_health_low_color, l_sr, COLOR_PICKER_STEP);
                    ImGui::SetCursorPos(ImVec2(0, ly));
                    UI::ColorPicker("##team_health_high_col", &g_cfg->visuals.m_teammate_health_high_color, l_sr, 0.0f);
                } else {
                    UI::ColorPicker("##team_health_high_col", &g_cfg->visuals.m_teammate_health_high_color, l_sr, 0.0f);
                }
            }
            ly = next_ly;

            static const char* team_health_types[] = { "text", "bar", "gradient" };
            if (g_cfg->visuals.m_teammate_health_bar) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                UI::MultiSelectDropdown("##team_health_type", &g_cfg->visuals.m_teammate_health_type, team_health_types, 3, field_w);
                ly = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("skeleton", &g_cfg->visuals.m_teammate_skeleton, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##team_skeleton_col", &g_cfg->visuals.m_teammate_skeleton_color, l_sr, 0.0f);
            ly = next_ly;

            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::Checkbox("weapon", &g_cfg->visuals.m_teammate_weapon, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ly));
            UI::ColorPicker("##team_weapon_col", &g_cfg->visuals.m_teammate_weapon_color, l_sr, 0.0f);
            ly = next_ly;

            static const char* team_weapon_types[] = { "text", "icon" };
            if (g_cfg->visuals.m_teammate_weapon) {
                ImGui::SetCursorPos(ImVec2(0, ly));
                UI::MultiSelectDropdown("##team_weapon_type", &g_cfg->visuals.m_teammate_weapon_type, team_weapon_types, 2, field_w);
                ly = ImGui::GetCursorPos().y + gap2;
            }

            float friend_content_h = ly;
            ImGui::SetCursorPos(ImVec2(0, ly));
            ImGui::Dummy(ImVec2(1.0f, 1.0f));
            ImGui::EndChild();

            float friend_view_h = lbox_h - l_box_pad * 2 - 10.0f;
            float friend_max_scroll = ImMax(0.0f, friend_content_h - friend_view_h);
            ScrollEase(s_friend_scroll_y, friend_max_scroll);
            s_friend_scroll_y = ImClamp(s_friend_scroll_y, 0.0f, friend_max_scroll);

            {
                float box_right = wpos.x + l_padding + l_l_w;
                float scroll_top = wpos.y + lbox_top;
                float scroll_bottom = wpos.y + lbox_bottom;
                ImVec2 area_min = ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + lbox_top + l_box_pad + 10.0f);
                ImVec2 area_max = ImVec2(area_min.x + field_w, wpos.y + lbox_bottom - l_box_pad);
                ImVec2 ms = ImGui::GetIO().MousePos;

                if (friend_max_scroll > 0.0f) {
                    float track_h = scroll_bottom - scroll_top;
                    float thumb_h = ImMax(4.0f, track_h * (friend_view_h / friend_content_h) * 0.4f);
                    float thumb_y = scroll_top + (s_friend_scroll_y / friend_max_scroll) * (track_h - thumb_h);

                    bool hovered = (ms.x >= area_min.x && ms.x <= area_max.x && ms.y >= area_min.y && ms.y <= area_max.y);
                    bool over_thumb = (ms.x >= box_right - 6.0f && ms.x <= box_right && ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

                    if (!s_friend_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                        s_friend_dragging = true;
                        s_friend_drag_start_y = ms.y;
                        s_friend_drag_scroll = s_friend_scroll_y;
                    }
                    if (s_friend_dragging) {
                        if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                            float delta = ms.y - s_friend_drag_start_y;
                            float track_diff = track_h - thumb_h;
                            if (track_diff > 0.0001f) {
                                s_friend_scroll_y = ImClamp(s_friend_drag_scroll + delta / track_diff * friend_max_scroll, 0.0f, friend_max_scroll);
                                ScrollTarget(s_friend_scroll_y) = s_friend_scroll_y;
                            }
                            ImGui::GetIO().WantCaptureMouse = true;
                        }
                        else {
                            s_friend_dragging = false;
                        }
                    }

                    if (hovered && !over_thumb && !s_friend_dragging && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking()) {
                        float& tgt = ScrollTarget(s_friend_scroll_y);
                        tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 40.0f, 0.0f, friend_max_scroll);
                        ImGui::GetIO().WantCaptureMouse = true;
                    }

                    ImU32 thumb_col = s_friend_dragging ? Colors::Accent : Colors::ScrollbarGrab;
                    dl->AddRectFilled(ImVec2(box_right - 6.0f, scroll_top), ImVec2(box_right, scroll_bottom), Colors::ScrollbarTrack, 0.0f);
                    dl->AddRectFilled(ImVec2(box_right - 5.0f, thumb_y), ImVec2(box_right - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
                }
                else {
                    s_friend_dragging = false;
                }
            }

            // --- teammate chams box (fixed 40%, scrollable) ---
            static const char* chams_materials[] = { "flat", "glow", "ghost", "textured", "metallic" };
            auto& team_ct = g_cfg->visuals.m_chams_targets[c_config::visuals_t::chams_target_teammate];

            DrawBox(dl, wpos, l_padding, cbox_top, cbox_bottom, l_l_w, "teammate chams", Colors::ColHdr);

            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + cbox_top + l_box_pad + 10.0f));
            ImGui::BeginChild("##tchams_scroll", ImVec2(field_w, cbox_h - l_box_pad * 2 - 10.0f), false,
                ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            ImGui::SetScrollY(s_tchams_scroll_y);

            float cy2 = 0.0f;

            ImGui::SetCursorPos(ImVec2(0, cy2));
            UI::Checkbox("visible", &team_ct.m_visible, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, cy2));
            UI::ColorPicker("##team_chams_vis_col", &team_ct.m_visible_color, l_sr, 0.0f);
            cy2 = next_ly;

            if (team_ct.m_visible) {
                ImGui::SetCursorPos(ImVec2(0, cy2));
                UI::Dropdown("##team_chams_vis_mat", &team_ct.m_visible_material, chams_materials, 5, field_w);
                cy2 = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, cy2));
            UI::Checkbox("occluded", &team_ct.m_occluded, nullptr, nullptr, field_w - 22.0f);
            next_ly = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, cy2));
            UI::ColorPicker("##team_chams_occ_col", &team_ct.m_occluded_color, l_sr, 0.0f);
            cy2 = next_ly;

            if (team_ct.m_occluded) {
                ImGui::SetCursorPos(ImVec2(0, cy2));
                UI::Dropdown("##team_chams_occ_mat", &team_ct.m_occluded_material, chams_materials, 5, field_w);
                cy2 = ImGui::GetCursorPos().y + gap2;
            }

            float tchams_content_h = cy2;
            ImGui::SetCursorPos(ImVec2(0, cy2));
            ImGui::Dummy(ImVec2(1.0f, 1.0f));
            ImGui::EndChild();

            float tchams_view_h = cbox_h - l_box_pad * 2 - 10.0f;
            float tchams_max_scroll = ImMax(0.0f, tchams_content_h - tchams_view_h);
            ScrollEase(s_tchams_scroll_y, tchams_max_scroll);
            s_tchams_scroll_y = ImClamp(s_tchams_scroll_y, 0.0f, tchams_max_scroll);

            {
                float box_right = wpos.x + l_padding + l_l_w;
                float scroll_top = wpos.y + cbox_top;
                float scroll_bottom = wpos.y + cbox_bottom;
                ImVec2 area_min = ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + cbox_top + l_box_pad + 10.0f);
                ImVec2 area_max = ImVec2(area_min.x + field_w, wpos.y + cbox_bottom - l_box_pad);
                ImVec2 ms = ImGui::GetIO().MousePos;

                if (tchams_max_scroll > 0.0f) {
                    float track_h = scroll_bottom - scroll_top;
                    float thumb_h = ImMax(4.0f, track_h * (tchams_view_h / tchams_content_h) * 0.4f);
                    float thumb_y = scroll_top + (s_tchams_scroll_y / tchams_max_scroll) * (track_h - thumb_h);

                    bool hovered = (ms.x >= area_min.x && ms.x <= area_max.x && ms.y >= area_min.y && ms.y <= area_min.y);
                    bool over_thumb = (ms.x >= box_right - 6.0f && ms.x <= box_right && ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

                    if (!s_tchams_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                        s_tchams_dragging = true;
                        s_tchams_drag_start_y = ms.y;
                        s_tchams_drag_scroll = s_tchams_scroll_y;
                    }
                    if (s_tchams_dragging) {
                        if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                            float delta = ms.y - s_tchams_drag_start_y;
                            float track_diff = track_h - thumb_h;
                            if (track_diff > 0.0001f) {
                                s_tchams_scroll_y = ImClamp(s_tchams_drag_scroll + delta / track_diff * tchams_max_scroll, 0.0f, tchams_max_scroll);
                                ScrollTarget(s_tchams_scroll_y) = s_tchams_scroll_y;
                            }
                            ImGui::GetIO().WantCaptureMouse = true;
                        }
                        else {
                            s_tchams_dragging = false;
                        }
                    }

                    if (hovered && !over_thumb && !s_tchams_dragging && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking()) {
                        float& tgt = ScrollTarget(s_tchams_scroll_y);
                        tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 40.0f, 0.0f, tchams_max_scroll);
                        ImGui::GetIO().WantCaptureMouse = true;
                    }

                    ImU32 thumb_col = s_tchams_dragging ? Colors::Accent : Colors::ScrollbarGrab;
                    dl->AddRectFilled(ImVec2(box_right - 6.0f, scroll_top), ImVec2(box_right, scroll_bottom), Colors::ScrollbarTrack, 0.0f);
                    dl->AddRectFilled(ImVec2(box_right - 5.0f, thumb_y), ImVec2(box_right - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
                }
                else {
                    s_tchams_dragging = false;
                }
            }

            // Right column: local arms/viewmodel chams.
            const float r_field_w = l_r_w - l_box_pad * 2;
            float r_sr = wpos.x + l_r_x + l_r_w - l_box_pad;
            float rbox_top = content_y;
            float ry = rbox_top + l_box_pad + 10.0f;

            // Local viewmodel weapon (visible & occluded)
            auto& vm_ct = g_cfg->visuals.m_chams_targets[c_config::visuals_t::chams_target_viewmodel];
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("viewmodel visible", &vm_ct.m_visible, nullptr, nullptr, r_field_w - 22.0f);
            float next_vm_vis = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::ColorPicker("##vm_chams_vis_col", &vm_ct.m_visible_color, r_sr, 0.0f);
            ry = next_vm_vis;
            if (vm_ct.m_visible) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::Dropdown("##vm_chams_vis_mat", &vm_ct.m_visible_material, chams_materials, 5, r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("viewmodel occluded", &vm_ct.m_occluded, nullptr, nullptr, r_field_w - 22.0f);
            float next_vm_occ = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::ColorPicker("##vm_chams_occ_col", &vm_ct.m_occluded_color, r_sr, 0.0f);
            ry = next_vm_occ;
            if (vm_ct.m_occluded) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::Dropdown("##vm_chams_occ_mat", &vm_ct.m_occluded_material, chams_materials, 5, r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }

            // Local arms (visible & occluded)
            auto& arms_ct = g_cfg->visuals.m_chams_targets[c_config::visuals_t::chams_target_arms];
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("arms visible", &arms_ct.m_visible, nullptr, nullptr, r_field_w - 22.0f);
            float next_arms_vis = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::ColorPicker("##arms_chams_vis_col", &arms_ct.m_visible_color, r_sr, 0.0f);
            ry = next_arms_vis;
            if (arms_ct.m_visible) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::Dropdown("##arms_chams_vis_mat", &arms_ct.m_visible_material, chams_materials, 5, r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("arms occluded", &arms_ct.m_occluded, nullptr, nullptr, r_field_w - 22.0f);
            float next_arms_occ = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::ColorPicker("##arms_chams_occ_col", &arms_ct.m_occluded_color, r_sr, 0.0f);
            ry = next_arms_occ;
            if (arms_ct.m_occluded) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::Dropdown("##arms_chams_occ_mat", &arms_ct.m_occluded_material, chams_materials, 5, r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }

            float rbox_bottom = ImMax(ry + l_box_pad, (s_menu_h) - 10.0f);
            DrawBox(dl, wpos, l_r_x, rbox_top, rbox_bottom, l_r_w, "chams", Colors::ColHdr);

            reserve_content_bottom(ImMax(cbox_bottom, rbox_bottom));
        }
        else if (s.visuals_subtab == 2) {
            float lbox_top = content_y;
            float ly = lbox_top + l_box_pad + 10.0f;
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
            UI::Checkbox("thirdperson", &g_cfg->visuals.m_thirdperson, "thirdperson", "", l_l_w - l_box_pad * 2);
            ly = ImGui::GetCursorPos().y;
            if (g_cfg->visuals.m_thirdperson) {
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::SliderFloat("##thirdperson_distance", &g_cfg->visuals.m_thirdperson_distance, 50.0f, 500.0f, "", "%.0f", l_l_w - l_box_pad * 2);
                ly = ImGui::GetCursorPos().y;
            }
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
            UI::Checkbox("override fov", &s.fov_changer.enabled, nullptr, nullptr, l_l_w - l_box_pad * 2);
            ly = ImGui::GetCursorPos().y;
            if (s.fov_changer.enabled) {
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::SliderFloat("##override_fov", &s.fov_changer.fov, 60.0f, 140.0f, "\xC2\xB0", "%.1f", l_l_w - l_box_pad * 2);
                ly = ImGui::GetCursorPos().y;
            }
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
            UI::Checkbox("viewmodel fov", &s.viewmodel_changer.enabled, nullptr, nullptr, l_l_w - l_box_pad * 2);
            ly = ImGui::GetCursorPos().y;
            if (s.viewmodel_changer.enabled) {
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::SliderFloat("##viewmodel_fov", &s.viewmodel_changer.fov, 30.0f, 100.0f, "\xC2\xB0", "%.1f", l_l_w - l_box_pad * 2);
                ly = ImGui::GetCursorPos().y;
            }
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
            UI::Checkbox("override viewmodel position", &s.viewmodel_changer.position_enabled, nullptr, nullptr, l_l_w - l_box_pad * 2);
            ly = ImGui::GetCursorPos().y;
            if (s.viewmodel_changer.position_enabled) {
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::SliderFloat("##viewmodel_offset_x", &s.viewmodel_changer.offset_x, -10.0f, 10.0f, "", "%.2f", l_l_w - l_box_pad * 2);
                ly = ImGui::GetCursorPos().y;
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::SliderFloat("##viewmodel_offset_y", &s.viewmodel_changer.offset_y, -10.0f, 10.0f, "", "%.2f", l_l_w - l_box_pad * 2);
                ly = ImGui::GetCursorPos().y;
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::SliderFloat("##viewmodel_offset_z", &s.viewmodel_changer.offset_z, -10.0f, 10.0f, "", "%.2f", l_l_w - l_box_pad * 2);
                ly = ImGui::GetCursorPos().y;
            }
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
            UI::Checkbox("remove visual punch", &g_cfg->misc.m_remove_visual_recoil, nullptr, nullptr, l_l_w - l_box_pad * 2);
            ly = ImGui::GetCursorPos().y;

            float lbox_bottom = (s_menu_h) - 10.0f;
            DrawBox(dl, wpos, l_padding, lbox_top, lbox_bottom, l_l_w, "view", Colors::ColHdr);

            float rbox_top = content_y;
            float ry = rbox_top + l_box_pad + 10.0f;
            const float r_field_w = l_r_w - l_box_pad * 2;
            float r_sr = wpos.x + l_r_x + l_r_w - l_box_pad;

            bool is_scope_gradient = (g_cfg->misc.m_scope_type == 0);
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            float scope_cb_w = (g_cfg->misc.m_scope_overlay && is_scope_gradient) ? r_field_w - COLOR_PICKER_STEP * 2 : r_field_w;
            UI::Checkbox("scope overlay", &g_cfg->misc.m_scope_overlay, nullptr, nullptr, scope_cb_w);
            float scope_ry_next = ImGui::GetCursorPos().y;
            if (g_cfg->misc.m_scope_overlay && is_scope_gradient) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::ColorPicker("##scope_in", &g_cfg->misc.m_scope_col_inside, r_sr, COLOR_PICKER_STEP);
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::ColorPicker("##scope_out", &g_cfg->misc.m_scope_col_outside, r_sr, 0.0f);
            }
            ry = scope_ry_next;
            if (g_cfg->misc.m_scope_overlay) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                static const char* scope_types[] = { "gradient", "overlay" };
                UI::Dropdown("##scope_type", &g_cfg->misc.m_scope_type, scope_types, 2, r_field_w);
                ry = ImGui::GetCursorPos().y;
            }
            if (g_cfg->misc.m_scope_overlay && is_scope_gradient) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::SliderFloat("gap", &g_cfg->misc.m_scope_gap, 0.0f, 100.0f, "", "%.0f", r_field_w);
                ry = ImGui::GetCursorPos().y;
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                UI::SliderFloat("length", &g_cfg->misc.m_scope_length, 10.0f, 500.0f, "", "%.0f", r_field_w);
                ry = ImGui::GetCursorPos().y;
            }

            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("visualize aimbot fov", &s.visualize_aimbot_fov, nullptr, nullptr, r_field_w - 22.0f);
            UI::ColorPicker("##visualize_aimbot_fov_col", &s.visualize_aimbot_fov_color, r_sr, 0.0f);
            ry = ImGui::GetCursorPos().y;

            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("keybinds", &s.ind_keybinds, nullptr, nullptr, r_field_w - 22.0f);
            ry = ImGui::GetCursorPos().y;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("spectators", &s.ind_spectators, nullptr, nullptr, r_field_w - 22.0f);
            ry = ImGui::GetCursorPos().y;
            ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
            UI::Checkbox("watermark", &s.ind_watermark, nullptr, nullptr, r_field_w - 22.0f);
            ry = ImGui::GetCursorPos().y;
            if (s.ind_watermark) {
                ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
                static const char* k_watermark_elems[] = { "name", "fps", "ping", "time" };
                UI::MultiSelectDropdown("##watermark_elems", &s.watermark_elements, k_watermark_elems, 4, r_field_w);
                ry = ImGui::GetCursorPos().y;
            }

            float rbox_bottom = (s_menu_h) - 10.0f;
            DrawBox(dl, wpos, l_r_x, rbox_top, rbox_bottom, l_r_w, "hud", Colors::ColHdr);

            reserve_content_bottom(ImMax(lbox_bottom, rbox_bottom));
        }
    }
    if (s.active_tab == 2) {
        float content_y = lh + 18.0f * ui_scale;
        float lbox_top = content_y;
        float ly = lbox_top + l_box_pad + 10.0f;
        float next_ly = ly;
        const float field_w = l_l_w - l_box_pad * 2;
        float l_sr = wpos.x + l_padding + l_l_w - l_box_pad;
        const float r_field_w = l_r_w - l_box_pad * 2;
        float r_sr = wpos.x + l_r_x + l_r_w - l_box_pad;
        const float gap2 = 2.0f;

        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
        UI::Checkbox("weapon drops", &g_cfg->visuals.m_weapon_drops, nullptr, nullptr, field_w - 22.0f);
        next_ly = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
        UI::ColorPicker("##weapon_drops_col", &g_cfg->visuals.m_weapon_drops_color, l_sr, 0.0f);
        ly = next_ly;

        static const char* weapon_drops_types[] = { "icon", "text", "ammo", "distance", "glow" };
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
        UI::MultiSelectDropdown("##weapon_drops_type", &g_cfg->visuals.m_weapon_drops_type, weapon_drops_types, 5, field_w);
        ly = ImGui::GetCursorPos().y + gap2;

        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
        UI::Checkbox("bomb", &g_cfg->visuals.m_bomb_esp, nullptr, nullptr, field_w - 22.0f);
        next_ly = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
        UI::ColorPicker("##bomb_esp_col", &g_cfg->visuals.m_bomb_esp_color, l_sr, 0.0f);
        ly = next_ly;

        static const char* bomb_esp_types[] = { "icon", "text", "time", "distance", "glow" };
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
        UI::MultiSelectDropdown("##bomb_esp_type", &g_cfg->visuals.m_bomb_esp_type, bomb_esp_types, 5, field_w);
        ly = ImGui::GetCursorPos().y + gap2;

        float lbox_bottom = ly + l_box_pad;
        DrawBox(dl, wpos, l_padding, lbox_top, lbox_bottom, l_l_w, "entity esp", Colors::ColHdr);

        float gbox_top = lbox_bottom + 10.0f;
        float gy = gbox_top + l_box_pad + 10.0f;
        float next_gy = gy;

        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::Checkbox("grenade trajectory", &g_cfg->visuals.m_grenade_trajectory, nullptr, nullptr, field_w - 48.0f);
        next_gy = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::ColorPicker("##grenade_trajectory_col", &g_cfg->visuals.m_grenade_trajectory_color, l_sr - COLOR_PICKER_STEP, 0.0f);
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::ColorPicker("##grenade_trajectory_end_col", &g_cfg->visuals.m_grenade_trajectory_end_color, l_sr, 0.0f);
        gy = next_gy;

        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::Checkbox("grenade trails", &g_cfg->visuals.m_grenade_trails, nullptr, nullptr, field_w);
        gy = ImGui::GetCursorPos().y + gap2;

        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::Checkbox("smoke color", &g_cfg->visuals.m_smoke_color, nullptr, nullptr, field_w);
        gy = ImGui::GetCursorPos().y + gap2;

        if (g_cfg->visuals.m_smoke_color) {
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
            dl->AddText(S(l_padding + l_box_pad + 22.0f, gy + 2.0f), Colors::Text, "terrorist");
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
            UI::ColorPicker("##smoke_t_col", &g_cfg->visuals.m_smoke_color_t, l_sr, 0.0f);
            gy += ImGui::GetTextLineHeight() + gap2 + 3.0f;

            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
            dl->AddText(S(l_padding + l_box_pad + 22.0f, gy + 2.0f), Colors::Text, "counter-terrorist");
            ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
            UI::ColorPicker("##smoke_ct_col", &g_cfg->visuals.m_smoke_color_ct, l_sr, 0.0f);
            gy += ImGui::GetTextLineHeight() + gap2;
        }

        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::Checkbox("grenades", &g_cfg->visuals.m_grenades, nullptr, nullptr, field_w - 22.0f);
        next_gy = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::ColorPicker("##grenades_col", &g_cfg->visuals.m_grenades_color, l_sr, 0.0f);
        gy = next_gy;

        static const char* grenades_types[] = { "icon", "text", "distance", "timer" };
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, gy));
        UI::MultiSelectDropdown("##grenades_type", &g_cfg->visuals.m_grenades_type, grenades_types, 4, field_w);
        gy = ImGui::GetCursorPos().y + gap2;

        float gbox_bottom = (s_menu_h) - 10.0f;
        DrawBox(dl, wpos, l_padding, gbox_top, gbox_bottom, l_l_w, "grenade esp", Colors::ColHdr);

        float rbox_top = content_y;
        float rbox_bottom = (s_menu_h) - 10.0f;
        float rbox_h = rbox_bottom - rbox_top;

        DrawBox(dl, wpos, l_r_x, rbox_top, rbox_bottom, l_r_w, "environment", Colors::ColHdr);

        ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + rbox_top + l_box_pad + 10.0f));
        ImGui::BeginChild("##env_scroll", ImVec2(r_field_w, rbox_h - l_box_pad * 2 - 10.0f), false,
            ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::SetScrollY(s_env_scroll_y);

        float ry = 0.0f;
        float next_ry = ry;

        {
            constexpr float btn_w = 140.0f;
            float dropdown_x = (r_field_w - ImMin(btn_w, r_field_w)) * 0.5f;
            ImGui::SetCursorPos(ImVec2(dropdown_x, ry));
        }
        ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Section), "removals");
        ry += ImGui::GetTextLineHeight() + 1.0f;
        static const char* removal_effects[] = { "flash", "players", "particles", "world", "hud", "viewmodel", "post-processing", "scope", "smoke", "legs" };

        ImGui::SetCursorPos(ImVec2(0, ry));
        UI::MultiSelectDropdown("##removals_effects", &g_cfg->removals.m_effects, removal_effects, 10, r_field_w);
        ry = ImGui::GetCursorPos().y + gap2;

        ImGui::SetCursorPos(ImVec2(0, ry));
        UI::Checkbox("fullbright", &g_cfg->removals.m_fullbright, nullptr, nullptr, r_field_w);
        ry = ImGui::GetCursorPos().y + gap2;

        {
            auto& wm = g_cfg->visuals.m_world_modulation;

            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::Checkbox("override sky", &wm.m_enable_sky, nullptr, nullptr, r_field_w - 22.0f);
            next_ry = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::ColorPicker("##wm_sky_col", &wm.m_sky_color, r_sr, 0.0f);
            ry = next_ry;

            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::Checkbox("night mode", &wm.m_enable_wall, nullptr, nullptr, r_field_w - 22.0f);
            next_ry = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::ColorPicker("##wm_wall_col", &wm.m_wall, r_sr, 0.0f);
            ry = next_ry;

            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::Checkbox("sunset mode", &wm.m_enable_lighting, nullptr, nullptr, r_field_w - 22.0f);
            next_ry = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::ColorPicker("##wm_lighting_col", &wm.m_lighting, r_sr, 0.0f);
            ry = next_ry;

            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::Checkbox("effects", &g_cfg->visuals.m_world_effects, nullptr, nullptr, r_field_w);
            ry = ImGui::GetCursorPos().y + gap2;
            if (g_cfg->visuals.m_world_effects) {
                ImGui::SetCursorPos(ImVec2(0, ry));
                static const char* k_world_effect_types[] = { "snow", "stars", "ashes" };
                UI::Dropdown("##world_effects_type", &g_cfg->visuals.m_world_effects_type, k_world_effect_types, 3, r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
                ImGui::SetCursorPos(ImVec2(0, ry));
                UI::SliderFloat("density", &g_cfg->visuals.m_world_effects_density, 0.0f, 100.0f, "", "%.0f", r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }

            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::Checkbox("override fog", &wm.m_enable_custom_fog, nullptr, nullptr, r_field_w - 22.0f);
            next_ry = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, ry));
            UI::ColorPicker("##wm_fog_col", &wm.m_fog_color, r_sr, 0.0f);
            ry = next_ry;

            if (wm.m_enable_custom_fog) {
                ImGui::SetCursorPos(ImVec2(0, ry));
                UI::SliderFloat("start", &wm.m_fog_start, 0.0f, 4096.0f, "", "%.0f", r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;

                ImGui::SetCursorPos(ImVec2(0, ry));
                UI::SliderFloat("end", &wm.m_fog_end, 0.0f, 4096.0f, "", "%.0f", r_field_w);
                ry = ImGui::GetCursorPos().y + gap2;
            }
        }

        float env_content_h = ry;
        ImGui::SetCursorPos(ImVec2(0, ry));
        ImGui::Dummy(ImVec2(1.0f, 1.0f));
        ImGui::EndChild();

        float env_view_h = rbox_h - l_box_pad * 2 - 10.0f;
        float env_max_scroll = ImMax(0.0f, env_content_h - env_view_h);
        ScrollEase(s_env_scroll_y, env_max_scroll);
        s_env_scroll_y = ImClamp(s_env_scroll_y, 0.0f, env_max_scroll);

        float env_box_right = wpos.x + l_r_x + l_r_w;
        float env_scroll_top = wpos.y + rbox_top;
        float env_scroll_bottom = wpos.y + rbox_bottom;
        ImVec2 env_area_min = ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + rbox_top + l_box_pad + 10.0f);
        ImVec2 env_area_max = ImVec2(env_area_min.x + r_field_w, wpos.y + rbox_top + rbox_h - l_box_pad);
        ImVec2 ms = ImGui::GetIO().MousePos;

        if (env_max_scroll > 0.0f) {
            float track_h = env_scroll_bottom - env_scroll_top;
            float thumb_h = ImMax(4.0f, track_h * (env_view_h / env_content_h) * 0.4f);
            float thumb_y = env_scroll_top + (s_env_scroll_y / env_max_scroll) * (track_h - thumb_h);

            bool env_hovered = (ms.x >= env_area_min.x && ms.x <= env_area_max.x &&
                ms.y >= env_area_min.y && ms.y <= env_area_max.y);

            bool over_thumb = (ms.x >= env_box_right - 6.0f && ms.x <= env_box_right &&
                ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

            if (!s_env_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                s_env_dragging = true;
                s_env_drag_start_y = ms.y;
                s_env_drag_scroll = s_env_scroll_y;
            }
            if (s_env_dragging) {
                if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                    float delta = ms.y - s_env_drag_start_y;
                    float track_diff = track_h - thumb_h;
                    if (track_diff > 0.0001f) {
                        s_env_scroll_y = ImClamp(s_env_drag_scroll + delta / track_diff * env_max_scroll, 0.0f, env_max_scroll);
                        ScrollTarget(s_env_scroll_y) = s_env_scroll_y;
                    }
                    ImGui::GetIO().WantCaptureMouse = true;
                }
                else {
                    s_env_dragging = false;
                }
            }

            if (env_hovered && !over_thumb && !s_env_dragging && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking()) {
                float& tgt = ScrollTarget(s_env_scroll_y);
                tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 40.0f, 0.0f, env_max_scroll);
                ImGui::GetIO().WantCaptureMouse = true;
            }

            ImU32 thumb_col = s_env_dragging ? Colors::Accent : Colors::ScrollbarGrab;

            dl->AddRectFilled(ImVec2(env_box_right - 6.0f, env_scroll_top),
                ImVec2(env_box_right, env_scroll_bottom), Colors::ScrollbarTrack, 0.0f);
            dl->AddRectFilled(ImVec2(env_box_right - 5.0f, thumb_y),
                ImVec2(env_box_right - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
        }
        else {
            s_env_dragging = false;
        }

        reserve_content_bottom(ImMax(gbox_bottom, rbox_bottom));
    }
    if (false) {

    // Auto-detect weapon group from the weapon in hand. Only updates when the
    // weapon type actually changes, so manual dropdown selection persists.
    {
        static int last_detected = c_config::aim_t::group_shared;
        int detected = c_config::aim_t::group_shared;
        if (g_ctx && g_ctx->m_local_pawn) {
            auto* local = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
            if (auto* weapon = local->get_active_weapon()) {
                if (auto* data = weapon->get_weapon_data()) {
                    switch (data->m_weapon_type()) {
                    case WEAPONTYPE_PISTOL:        detected = c_config::aim_t::group_pistols; break;
                    case WEAPONTYPE_RIFLE:         detected = c_config::aim_t::group_rifles; break;
                    case WEAPONTYPE_SNIPER_RIFLE:  detected = c_config::aim_t::group_snipers; break;
                    case WEAPONTYPE_SUBMACHINEGUN: detected = c_config::aim_t::group_smg; break;
                    case WEAPONTYPE_SHOTGUN:       detected = c_config::aim_t::group_shotguns; break;
                    case WEAPONTYPE_MACHINEGUN:    detected = c_config::aim_t::group_heavy; break;
                    }
                }
            }
        }
        if (detected != last_detected) {
            last_detected = detected;
            s.weapon_sel = detected;
        }
    }

    // ── Weapon-group pill-bar — растянут на всю ширину контента ──────────
    static int s_pistol_sub = 0;
    {
        struct WeaponBtn { const char* icon; bool use_wpn_font; int group; };
        static const WeaponBtn k_wpn_btns[] = {
            { ICON_FA_GLOBE,   false, c_config::aim_t::group_shared  },
            { "\xEE\x80\x89", true,  c_config::aim_t::group_snipers },
            { "\xEE\x80\x87", true,  c_config::aim_t::group_rifles  },
            { "\xEE\x80\x81", true,  c_config::aim_t::group_pistols },
            { "\xEE\x80\x84", true,  c_config::aim_t::group_pistols },
        };
        static const char* k_wpn_tooltips[] = {
            "all weapons", "snipers", "rifles",
            "pistols (deagle / r8)", "pistols (glock / usp / etc)",
        };
        constexpr int k_btn_count = 5;

        auto get_active_btn = [&]() -> int {
            switch (s.weapon_sel) {
            case c_config::aim_t::group_snipers: return 1;
            case c_config::aim_t::group_rifles:  return 2;
            case c_config::aim_t::group_pistols: return (s_pistol_sub == 0) ? 3 : 4;
            default:                             return 0;
            }
        };

        const float bar_pad = l_padding;            // отступ по бокам = тот же что у боксов
        const float bar_w   = s_menu_w - bar_pad * 2.0f;
        const float bar_h   = 36.0f;
        const float bar_r   = bar_h * 0.5f;
        const float bar_x   = bar_pad;              // локальная X (относительно wpos)
        const float bar_y   = cy;                   // прямо у верхнего края контента
        const float pill_pad = 3.0f;
        const float cell_w  = bar_w / (float)k_btn_count;
        const int   active  = get_active_btn();
        ImVec2      mouse   = ImGui::GetIO().MousePos;

        // Плавная анимация подложки
        const float target_x = bar_x + active * cell_w;
        static float s_pill_x = target_x;
        {
            float dt = ImGui::GetIO().DeltaTime;
            float t  = 1.0f - expf(-dt * 20.0f);
            s_pill_x += (target_x - s_pill_x) * t;
            if (fabsf(target_x - s_pill_x) < 0.5f)
                s_pill_x = target_x;
        }

        // Фон бара
        dl->AddRectFilled(
            ImVec2(wpos.x + bar_x,         wpos.y + bar_y),
            ImVec2(wpos.x + bar_x + bar_w, wpos.y + bar_y + bar_h),
            IM_COL32(28, 28, 32, 255), bar_r
        );

        // Активная подложка (анимированная)
        {
            float ax = wpos.x + s_pill_x + pill_pad;
            float ay = wpos.y + bar_y    + pill_pad;
            float aw = cell_w  - pill_pad * 2.0f;
            float ah = bar_h   - pill_pad * 2.0f;
            dl->AddRectFilled(ImVec2(ax, ay), ImVec2(ax + aw, ay + ah),
                              IM_COL32(55, 55, 62, 255), ah * 0.5f);
        }

        for (int i = 0; i < k_btn_count; i++) {
            float cx0 = wpos.x + bar_x + i * cell_w;
            float cy0 = wpos.y + bar_y;
            bool  hov = mouse.x >= cx0 && mouse.x <= cx0 + cell_w &&
                        mouse.y >= cy0 && mouse.y <= cy0 + bar_h;
            bool  act = (i == active);

            // Плавная яркость иконки
            static float s_icon_bright[k_btn_count] = {1.f, 0.f, 0.f, 0.f, 0.f};
            float target_bright = act ? 1.0f : (hov ? 0.6f : 0.35f);
            {
                float dt = ImGui::GetIO().DeltaTime;
                float t  = 1.0f - expf(-dt * 18.0f);
                s_icon_bright[i] += (target_bright - s_icon_bright[i]) * t;
            }
            int bright = (int)(s_icon_bright[i] * 255.0f);

            ImFont* wpn_font = (k_wpn_btns[i].use_wpn_font && g_menu)
                       ? g_menu->get_weapon_icon_font() : nullptr;
            if (wpn_font) ImGui::PushFont(wpn_font);
            ImVec2 isz = ImGui::CalcTextSize(k_wpn_btns[i].icon);
            dl->AddText(wpn_font, wpn_font ? wpn_font->FontSize : ImGui::GetFontSize(),
                ImVec2(cx0 + (cell_w - isz.x) * 0.5f, cy0 + (bar_h - isz.y) * 0.5f),
                IM_COL32(bright, bright, bright, 255), k_wpn_btns[i].icon);
            if (wpn_font) ImGui::PopFont();

            ImGui::SetCursorScreenPos(ImVec2(cx0, cy0));
            ImGui::InvisibleButton(("##wpnb" + std::to_string(i)).c_str(), ImVec2(cell_w, bar_h));
            if (ImGui::IsItemClicked() && !UI::IsOpenColorPickerBlocking()) {
                s.weapon_sel = k_wpn_btns[i].group;
                s_pistol_sub = (i == 4) ? 1 : 0;
            }
        }

        // bar_h = 36.0f, gap = 6.0f
    }
    // ─────────────────────────────────────────────────────────────────────
    const float aim_cy = cy + 36.0f + 6.0f;

    float lbox2_top = aim_cy;
    float aim_avail_h = (s_menu_h) - aim_cy - 10.0f;
    float lbox2_h = aim_avail_h;
    float lbox2_bottom = lbox2_top + lbox2_h;

    const float field_w = l_l_w - l_box_pad * 2;
    const float gap2 = 2.0f;

    DrawBox(dl, wpos, l_padding, lbox2_top, lbox2_bottom, l_l_w, "general", Colors::ColHdr);

    ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + lbox2_top + l_box_pad + 10.0f));
    ImGui::BeginChild("##aim_general_scroll", ImVec2(field_w, lbox2_h - l_box_pad * 2 - 10.0f), false,
        ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

    float child_ly = 0.0f;
    if (s.weapon_sel != c_config::aim_t::group_shared) {
        ImGui::SetCursorPos(ImVec2(0, child_ly));
        UI::Checkbox("override shared", &s.override_shared, nullptr, nullptr, field_w);
        child_ly = ImGui::GetCursorPos().y + gap2;
    }
    ImGui::SetCursorPos(ImVec2(0, child_ly));
    UI::Checkbox("aimbot", &s.aimbot, "aimbot", "", field_w);
    child_ly = ImGui::GetCursorPos().y + gap2;
    const float section_label_x = 22.0f;
    if (auto* bold_font = g_menu ? g_menu->get_menu_bold_font() : nullptr) {
        ImGui::PushFont(bold_font);
        ImGui::SetCursorPos(ImVec2(section_label_x, child_ly));
        ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Section), "hitboxes");
        ImGui::PopFont();
    } else {
        ImGui::SetCursorPos(ImVec2(section_label_x, child_ly));
        ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Section), "hitboxes");
    }
    child_ly = ImGui::GetCursorPos().y + 1.0f;
    ImGui::SetCursorPos(ImVec2(0, child_ly));
    UI::MultiSelectDropdown("##htbx", &s.hitbox_sel, k_hitboxes, 5, field_w);
    child_ly = ImGui::GetCursorPos().y + gap2;
    ImGui::SetCursorPos(ImVec2(0, child_ly));
    UI::Checkbox("triggerbot", &s.triggerbot, "triggerbot", "ALT", field_w);
    child_ly = ImGui::GetCursorPos().y + gap2;
     if (auto* bold_font = g_menu ? g_menu->get_menu_bold_font() : nullptr) {
        ImGui::PushFont(bold_font);
        ImGui::SetCursorPos(ImVec2(section_label_x, child_ly));
        ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Section), "hitgroups");
        ImGui::PopFont();
    } else {
        ImGui::SetCursorPos(ImVec2(section_label_x, child_ly));
        ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Section), "hitgroups");
    }
    child_ly = ImGui::GetCursorPos().y + 1.0f;
    ImGui::SetCursorPos(ImVec2(0, child_ly));
    UI::MultiSelectDropdown("##htgr", &s.trigger_hitbox_sel, k_hitboxes, 5, field_w);
    child_ly = ImGui::GetCursorPos().y + gap2;
    ImGui::SetCursorPos(ImVec2(0, child_ly));
    UI::Checkbox("penetration", &s.penetration, "penetration", "", field_w);
    child_ly = ImGui::GetCursorPos().y + gap2;

    ImGui::SetCursorPos(ImVec2(0, child_ly));
    ImGui::Dummy(ImVec2(1.0f, 1.0f));
    ImGui::EndChild();
    float rbox1_top = aim_cy;
    float ry = rbox1_top + l_box_pad + 10.0f;
    ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
    UI::SliderFloat("field of view", &s.fov, 0.0f, 90.0f, "\xC2\xB0", "%.1f", l_r_w - l_box_pad * 2);
    ry = ImGui::GetCursorPos().y;
    ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
    UI::SliderFloat("smooth", &s.smooth, 0.0f, 100.0f, "%", "%.0f", l_r_w - l_box_pad * 2);
    ry = ImGui::GetCursorPos().y;
    ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
    UI::Checkbox("recoil control", &s.recoil_ctrl, nullptr, nullptr, l_r_w - l_box_pad * 2);
    ry = ImGui::GetCursorPos().y;
    ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
    if (s.weapon_sel == c_config::aim_t::group_snipers)
        UI::Checkbox("auto scope", &s.auto_scope, nullptr, nullptr, l_r_w - l_box_pad * 2);
    ry = ImGui::GetCursorPos().y;
    ImGui::SetCursorPos(ImVec2(l_r_x + l_box_pad, ry));
    UI::Checkbox("auto stop", &s.auto_stop, nullptr, nullptr, l_r_w - l_box_pad * 2);
    ry = ImGui::GetCursorPos().y;
    float rbox1_bottom = aim_cy + aim_avail_h * 0.5f;
    DrawBox(dl, wpos, l_r_x, rbox1_top, rbox1_bottom, l_r_w, "aimbot params", Colors::ColHdr);

    float rbox2_top = rbox1_bottom + 10.0f;
    float rbox2_h = aim_avail_h * 0.5f - 10.0f;
    float rbox2_bottom = rbox2_top + rbox2_h;

    const float r_field_w = l_r_w - l_box_pad * 2;
    const float r_gap2 = 2.0f;

    DrawBox(dl, wpos, l_r_x, rbox2_top, rbox2_bottom, l_r_w, "triggerbot params", Colors::ColHdr);

    ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + rbox2_top + l_box_pad + 10.0f));
    ImGui::BeginChild("##aim_triggerbot_scroll", ImVec2(r_field_w, rbox2_h - l_box_pad * 2 - 10.0f), false,
        ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

    float child_ry = 0.0f;
    ImGui::SetCursorPos(ImVec2(0, child_ry));
    UI::Checkbox("seed prediction", &s.seed_pred, nullptr, nullptr, r_field_w, s.menu_theme == 1 ? IM_COL32(0,0,0,0) : IM_COL32(0xF6, 0xC8, 0x9B, 255), s.menu_theme == 1 ? IM_COL32(0,0,0,0) : IM_COL32(0xB0, 0x96, 0x7D, 255));
    child_ry = ImGui::GetCursorPos().y + r_gap2;
    ImGui::SetCursorPos(ImVec2(0, child_ry));
    UI::SliderFloat("delay", &s.delay, 0.0f, 500.0f, "ms", "%.0f", r_field_w);
    child_ry = ImGui::GetCursorPos().y + r_gap2;
    ImGui::SetCursorPos(ImVec2(0, child_ry));
    UI::SliderFloat("hitchance", &s.hitchance, 0.0f, 100.0f, "%", "%.0f", r_field_w);
    child_ry = ImGui::GetCursorPos().y + r_gap2;
    child_ry = ImGui::GetCursorPos().y + r_gap2;

    ImGui::SetCursorPos(ImVec2(0, child_ry));
    ImGui::Dummy(ImVec2(1.0f, 1.0f));
    ImGui::EndChild();
    }
    if (s.active_tab == 1) {
        const float skin_item_h = 16.0f;
        static float s_skin_scroll_y = 0.0f;
        static float s_models_scroll_y = 0.0f;

        float left_w = l_l_w - l_box_pad * 2;

        float lbox_top = cy;
        float ly = lbox_top + l_box_pad + 10.0f;
        ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
        UI::Checkbox("enabled", &s.skin_changer.enabled, nullptr, nullptr, left_w);
        ly = ImGui::GetCursorPos().y;

        if (g_item_schema->is_initialized()) {
            uint16_t cur_def = g_skin_changer->m_current_weapon_def_index;
            int cfg_idx = c_config::skin_changer_t::get_config_index(cur_def);

            if (cfg_idx > 0) {
                auto& wc = s.skin_changer.weapon_configs[cfg_idx];
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                float wear_pct = wc.wear * 100.0f;
                if (UI::SliderFloat("wear", &wear_pct, 0.0f, 100.0f, "%", "%.0f", left_w))
                    wc.wear = wear_pct * 0.01f;
                ly = ImGui::GetCursorPos().y + 6.0f;
                dl->AddText(ImVec2(wpos.x + l_padding + l_box_pad + 20.0f, wpos.y + ly), Colors::Text, "seed");
                ly += 16.0f;
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad + 20.0f, ly));
                UI::InputInt("seed", &wc.seed, left_w - 40.0f);
                ly = ImGui::GetCursorPos().y;
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::Checkbox("paint color", &wc.paint_color, nullptr, nullptr, left_w - 98.0f);
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                PaintColorRow("weapon_paint_color", wc.paint_colors, 4, wpos.x + l_padding + l_box_pad + left_w);
                ly = ImGui::GetCursorPos().y + 15.0f;
            } else if (s.knife_changer.enabled) {
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                float wear_pct = s.knife_changer.wear * 100.0f;
                if (UI::SliderFloat("wear", &wear_pct, 0.0f, 100.0f, "%", "%.0f", left_w))
                    s.knife_changer.wear = wear_pct * 0.01f;
                ly = ImGui::GetCursorPos().y + 6.0f;
                dl->AddText(ImVec2(wpos.x + l_padding + l_box_pad + 20.0f, wpos.y + ly), Colors::Text, "seed");
                ly += 16.0f;
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad + 20.0f, ly));
                UI::InputInt("seed##knife", &s.knife_changer.seed, left_w - 40.0f);
                ly = ImGui::GetCursorPos().y;
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                UI::Checkbox("paint color", &s.knife_changer.paint_color, nullptr, nullptr, left_w - 98.0f);
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                PaintColorRow("knife_paint_color", s.knife_changer.paint_colors, 4, wpos.x + l_padding + l_box_pad + left_w);
                ly = ImGui::GetCursorPos().y + 15.0f;
            } else if (g_cfg->glove_changer.m_enabled) {
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad, ly));
                float wear_pct = g_cfg->glove_changer.m_wear * 100.0f;
                if (UI::SliderFloat("wear##glove", &wear_pct, 0.0f, 100.0f, "%", "%.0f", left_w))
                    g_cfg->glove_changer.m_wear = wear_pct * 0.01f;
                ly = ImGui::GetCursorPos().y + 6.0f;
                dl->AddText(ImVec2(wpos.x + l_padding + l_box_pad + 20.0f, wpos.y + ly), Colors::Text, "seed");
                ly += 16.0f;
                ImGui::SetCursorPos(ImVec2(l_padding + l_box_pad + 20.0f, ly));
                UI::InputInt("seed##glove", &g_cfg->glove_changer.m_seed, left_w - 40.0f);
                ly = ImGui::GetCursorPos().y;
            }
        }
        float lbox_bottom = ly + l_box_pad + 7.0f;
        DrawBox(dl, wpos, l_padding, lbox_top, lbox_bottom, l_l_w, "skin options", Colors::ColHdr);

        float models_top = lbox_bottom + 8.0f;
        float available_h = (s_menu_h) - models_top - 10.0f;
        float models_child_h = available_h;
        DrawBox(dl, wpos, l_padding, models_top, models_top + models_child_h, l_l_w, "models", Colors::ColHdr);

        ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + models_top + l_box_pad + 10.0f));
        ImGui::BeginChild("##models_scroll", ImVec2(left_w, models_child_h - l_box_pad * 2 - 10.0f), false,
            ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

        ImGui::SetScrollY(s_models_scroll_y);

        float my = 0.0f;
        ImVec2 wpos_m = ImGui::GetWindowPos();

        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("knife", &s.knife_changer.enabled, nullptr, nullptr, left_w);
        my = ImGui::GetCursorPos().y + 2.0f;
        if (s.knife_changer.enabled && g_item_schema->is_initialized()) {
            ImGui::SetCursorPos(ImVec2(0, my));
            if (!g_item_schema->knife_names_cstr.empty()) {
                static std::vector<const char*> kn;
                kn = g_item_schema->knife_names_cstr;
                UI::Dropdown("##knife_model", &s.knife_changer.selected_knife,
                    const_cast<const char**>(kn.data()), (int)kn.size(), left_w, nullptr, true);
            }
            my = ImGui::GetCursorPos().y + 3.0f;
        }

        if (!g_cfg->model_changer.m_enabled || g_cfg->model_changer.m_selected_model <= 0) {
        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("gloves", &g_cfg->glove_changer.m_enabled, nullptr, nullptr, left_w);
        my = ImGui::GetCursorPos().y + 2.0f;
        if (g_cfg->glove_changer.m_enabled && g_item_schema->is_initialized()) {
            ImGui::SetCursorPos(ImVec2(0, my));
            if (!g_item_schema->glove_names_cstr.empty()) {
                static std::vector<const char*> gn;
                gn = g_item_schema->glove_names_cstr;
                if (UI::Dropdown("##glove_model", &g_cfg->glove_changer.m_glove,
                    const_cast<const char**>(gn.data()), (int)gn.size(), left_w, nullptr, true)) {
                    g_cfg->glove_changer.m_paint_kit = 0;
                    g_glove_changer->request_update(true);
                }
            }
            my = ImGui::GetCursorPos().y + 3.0f;
            if (g_cfg->glove_changer.m_glove >= 0 && g_cfg->glove_changer.m_glove < (int)g_item_schema->gloves.size()) {
                uint16_t sg = g_item_schema->gloves[g_cfg->glove_changer.m_glove].definition_index;
                if (sg > 0) {
                    auto& gs = g_item_schema->get_paint_kit_names_for_item(sg);
                    if (!gs.empty()) {
                        if (g_cfg->glove_changer.m_paint_kit < 0 || g_cfg->glove_changer.m_paint_kit >= (int)gs.size())
                            g_cfg->glove_changer.m_paint_kit = 0;
                        ImGui::SetCursorPos(ImVec2(0, my));
                        static std::vector<const char*> gsn;
                        static std::vector<ImU32> gsc;
                        gsn = gs;
                        BuildPaintKitRarityColors(sg, gsc);
                        if (UI::Dropdown("##glove_skin", &g_cfg->glove_changer.m_paint_kit,
                            const_cast<const char**>(gsn.data()), (int)gsn.size(), left_w,
                            gsc.size() == gsn.size() ? gsc.data() : nullptr, true))
                            g_glove_changer->request_update(false);
                        my = ImGui::GetCursorPos().y + 3.0f;
                    }
                }
            }

        }
        }

        if (!g_cfg->model_changer.m_enabled || g_cfg->model_changer.m_selected_model <= 0) {
        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("agent", &s.agent_changer.enabled, nullptr, nullptr, left_w);
        my = ImGui::GetCursorPos().y + 2.0f;
        if (s.agent_changer.enabled && g_item_schema->is_initialized()) {
            ImGui::SetCursorPos(ImVec2(22.0f, my));
            ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Section), "terrorist");
            my = ImGui::GetCursorPos().y + 3.0f;
            ImGui::SetCursorPos(ImVec2(0, my));
            if (!g_item_schema->t_agent_names_cstr.empty()) {
                if (s.agent_changer.selected_t_agent < 0 || s.agent_changer.selected_t_agent >= (int)g_item_schema->t_agent_names_cstr.size())
                    s.agent_changer.selected_t_agent = 0;
                static std::vector<const char*> tan;
                static std::vector<ImU32> tac;
                tan = g_item_schema->t_agent_names_cstr;
                BuildAgentRarityColors(g_item_schema->t_agents, tac);
                UI::Dropdown("##t_agent_select", &s.agent_changer.selected_t_agent,
                    const_cast<const char**>(tan.data()), (int)tan.size(), left_w,
                    tac.size() == tan.size() ? tac.data() : nullptr, true);
            }
            my = ImGui::GetCursorPos().y + 2.0f;
            ImGui::SetCursorPos(ImVec2(22.0f, my));
            ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Section), "counter-terrorist");
            my = ImGui::GetCursorPos().y + 3.0f;
            ImGui::SetCursorPos(ImVec2(0, my));
            if (!g_item_schema->ct_agent_names_cstr.empty()) {
                if (s.agent_changer.selected_ct_agent < 0 || s.agent_changer.selected_ct_agent >= (int)g_item_schema->ct_agent_names_cstr.size())
                    s.agent_changer.selected_ct_agent = 0;
                static std::vector<const char*> can;
                static std::vector<ImU32> cac;
                can = g_item_schema->ct_agent_names_cstr;
                BuildAgentRarityColors(g_item_schema->ct_agents, cac);
                UI::Dropdown("##ct_agent_select", &s.agent_changer.selected_ct_agent,
                    const_cast<const char**>(can.data()), (int)can.size(), left_w,
                    cac.size() == can.size() ? cac.data() : nullptr, true);
            }
            my = ImGui::GetCursorPos().y;
        }
        }

        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("custom model", &g_cfg->model_changer.m_enabled, nullptr, nullptr, left_w);
        my = ImGui::GetCursorPos().y + 2.0f;
        if (g_cfg->model_changer.m_enabled) {
            g_model_changer->initialize();
            static std::vector<const char*> mmn;
            mmn = g_model_changer->model_names();
            if (!mmn.empty()) {
                if (g_cfg->model_changer.m_selected_model < 0 || g_cfg->model_changer.m_selected_model >= (int)mmn.size())
                    g_cfg->model_changer.m_selected_model = 0;
                ImGui::SetCursorPos(ImVec2(0, my));
                UI::Dropdown("##custom_model", &g_cfg->model_changer.m_selected_model,
                    const_cast<const char**>(mmn.data()), (int)mmn.size(), left_w, nullptr, true);
                my = ImGui::GetCursorPos().y + 3.0f;
            }
            ImGui::SetCursorPos(ImVec2(0, my));
            if (UI::Button("refresh models", left_w))
                g_model_changer->refresh();
            my = ImGui::GetCursorPos().y + 3.0f;
        }

        float models_content_h = my;
        ImGui::SetCursorPos(ImVec2(0, my));
        ImGui::Dummy(ImVec2(1.0f, 1.0f));

        ImGui::EndChild();

        float models_view_h = models_child_h - l_box_pad * 2 - 10.0f;
        float models_max_scroll = ImMax(0.0f, models_content_h - models_view_h);
        ScrollEase(s_models_scroll_y, models_max_scroll);
        s_models_scroll_y = ImClamp(s_models_scroll_y, 0.0f, models_max_scroll);

        float models_box_right = wpos.x + l_padding + l_l_w;
        float models_scroll_top = wpos.y + models_top;
        float models_scroll_bottom = wpos.y + models_top + models_child_h;
        ImVec2 models_area_min = ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + models_top + l_box_pad + 10.0f);
        ImVec2 models_area_max = ImVec2(models_area_min.x + left_w, wpos.y + models_top + models_child_h - l_box_pad);
        ImVec2 ms = ImGui::GetIO().MousePos;

        if (models_max_scroll > 0.0f) {
            float track_h = models_scroll_bottom - models_scroll_top;
            float thumb_h = ImMax(4.0f, track_h * (models_view_h / models_content_h) * 0.4f);
            float thumb_y = models_scroll_top + (s_models_scroll_y / models_max_scroll) * (track_h - thumb_h);

            bool models_hovered = (ms.x >= models_area_min.x && ms.x <= models_area_max.x &&
                                   ms.y >= models_area_min.y && ms.y <= models_area_max.y);

            bool over_thumb = (ms.x >= models_box_right - 6.0f && ms.x <= models_box_right &&
                               ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

            if (!s_models_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                s_models_dragging = true;
                s_models_drag_start_y = ms.y;
                s_models_drag_scroll = s_models_scroll_y;
            }
            if (s_models_dragging) {
                    if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                        float delta = ms.y - s_models_drag_start_y;
                        float track_diff = track_h - thumb_h;
                        if (track_diff > 0.0001f) {
                            s_models_scroll_y = ImClamp(s_models_drag_scroll + delta / track_diff * models_max_scroll, 0.0f, models_max_scroll);
                            ScrollTarget(s_models_scroll_y) = s_models_scroll_y;
                        }
                    ImGui::GetIO().WantCaptureMouse = true;
                } else {
                    s_models_dragging = false;
                }
            }

            if (models_hovered && !over_thumb && !s_models_dragging && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking()) {
                float& tgt = ScrollTarget(s_models_scroll_y);
                tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 40.0f, 0.0f, models_max_scroll);
                ImGui::GetIO().WantCaptureMouse = true;
            }

            ImU32 thumb_col = s_models_dragging ? Colors::Accent : Colors::ScrollbarGrab;

            dl->AddRectFilled(ImVec2(models_box_right - 6.0f, models_scroll_top),
                              ImVec2(models_box_right, models_scroll_bottom), Colors::ScrollbarTrack, 0.0f);

            dl->AddRectFilled(ImVec2(models_box_right - 5.0f, thumb_y),
                              ImVec2(models_box_right - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
        } else {
            s_models_dragging = false;
        }

        float left_bottom = models_top + models_child_h;

        float skin_box_x = l_r_x;
        float skin_box_w = l_r_w;
        float skin_box_top = cy;
        float skin_box_h = left_bottom - cy;

        // The preview now lives in a separate floating window (drawn at the end
        // of this tab); the skin list fills the whole right "skin" box.
        float skin_inner_pad = 12.0f;
        float skin_list_w = 140.0f;
        float skin_list_top = skin_box_top + skin_inner_pad;
        float skin_list_h = ImMax(48.0f, (skin_box_top + skin_box_h) - skin_list_top - skin_inner_pad);
        float skin_list_x_centered = l_r_x + (l_r_w - skin_list_w) * 0.5f;
        float skin_list_y_centered = skin_list_top;

        uint16_t skin_def = 0;
        int* skin_sel = nullptr;
        int skin_count = 0;
        std::vector<const char*> skin_names;
        std::vector<ImU32> skin_colors;

        if (g_item_schema->is_initialized()) {
            uint16_t cur_def = g_skin_changer->m_current_weapon_def_index;
            bool is_knife = (cur_def >= 500 && cur_def <= 526);
            if (is_knife && s.knife_changer.enabled) {
                int ki = s.knife_changer.selected_knife;
                if (ki >= 0 && ki < (int)g_item_schema->knives.size()) {
                    skin_def = g_item_schema->knives[ki].definition_index;
                    skin_names = g_item_schema->get_paint_kit_names_for_item(skin_def);
                    BuildPaintKitRarityColors(skin_def, skin_colors);
                    skin_sel = &s.knife_changer.selected_skin;
                    skin_count = (int)skin_names.size();
                }
            } else {
                int cfg_idx = c_config::skin_changer_t::get_config_index(cur_def);
                if (cfg_idx > 0) {
                    skin_def = cur_def;
                    skin_names = g_item_schema->get_paint_kit_names_for_item(skin_def);
                    BuildPaintKitRarityColors(skin_def, skin_colors);
                    skin_sel = &s.skin_changer.weapon_configs[cfg_idx].paint_kit;
                    skin_count = (int)skin_names.size();
                } else if (s.knife_changer.enabled) {

                    int ki = s.knife_changer.selected_knife;
                    if (ki >= 0 && ki < (int)g_item_schema->knives.size()) {
                        skin_def = g_item_schema->knives[ki].definition_index;
                        skin_names = g_item_schema->get_paint_kit_names_for_item(skin_def);
                        BuildPaintKitRarityColors(skin_def, skin_colors);
                        skin_sel = &s.knife_changer.selected_skin;
                        skin_count = (int)skin_names.size();
                    }
                }
            }
        }

        if (skin_sel && skin_count > 0) {
            if (*skin_sel >= skin_count) *skin_sel = 0;
            if (*skin_sel < 0) *skin_sel = 0;
        }

        const float skin_content_h = (float)skin_count * skin_item_h + 2.0f;
        const float skin_max_scroll = ImMax(0.0f, skin_content_h - skin_list_h);
        ScrollEase(s_skin_scroll_y, skin_max_scroll);
        s_skin_scroll_y = ImClamp(s_skin_scroll_y, 0.0f, skin_max_scroll);

        ImVec2 lp = S(skin_list_x_centered, skin_list_y_centered);
        ImVec2 le = ImVec2(lp.x + skin_list_w, lp.y + skin_list_h);
        dl->AddRectFilled(lp, le, Colors::ListBg, 0.0f);
        dl->AddRect(lp, le, Colors::SectionBorder, 0.0f, 0, 1.0f);
        dl->AddRect(ImVec2(lp.x + 1, lp.y + 1), ImVec2(le.x - 1, le.y - 1), Colors::BoxInnerBorder, 0.0f, 0, 1.0f);

        int hov_idx = -1;
        bool lh_b = (ms.x >= lp.x && ms.x <= le.x && ms.y >= lp.y && ms.y <= le.y);

        bool over_scrollbar = (skin_max_scroll > 0.0f && ms.x >= (le.x - 6.0f) && ms.x <= le.x && ms.y >= lp.y && ms.y <= le.y);

        if (lh_b && !over_scrollbar && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking() && skin_max_scroll > 0.0f && ImGui::GetIO().MouseWheel != 0.0f) {
            float& tgt = ScrollTarget(s_skin_scroll_y);
            tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * skin_item_h * 3.0f, 0.0f, skin_max_scroll);
            ImGui::GetIO().WantCaptureMouse = true;
        }

        int first = ImMax(0, (int)(s_skin_scroll_y / skin_item_h));
        int last = ImMin(skin_count, first + (int)(skin_list_h / skin_item_h) + 3);

        dl->PushClipRect(lp, le, true);
        for (int i = first; i < last; i++) {
            ImVec2 ip0 = ImVec2(lp.x + 1, lp.y + 1 + (float)i * skin_item_h - s_skin_scroll_y);
            ImVec2 ip1 = ImVec2(le.x - 1, ip0.y + skin_item_h);
            bool hov_i = (ms.x >= ip0.x && ms.x <= ip1.x && ms.y >= ip0.y && ms.y <= ip1.y && !over_scrollbar);
            bool sel_i = (skin_sel && *skin_sel == i);
            if (hov_i) hov_idx = i;
            float ty = ip0.y + (skin_item_h - lh) * 0.5f;
            if (i < (int)skin_colors.size())
                dl->AddRectFilled(ImVec2(ip0.x + 4.0f, ip0.y + 3.0f),
                                  ImVec2(ip0.x + 7.0f, ip1.y - 3.0f), skin_colors[i], 1.0f);
            ImU32 tc = sel_i ? Colors::Accent : Colors::Text;
            dl->PushClipRect(ImVec2(ip0.x + 11.0f, ip0.y), ImVec2(ip1.x - 4.0f, ip1.y), true);
            dl->AddText(ImVec2(ip0.x + 11.0f, ty), tc, skin_names[i]);
            dl->PopClipRect();
        }
        dl->PopClipRect();

        if (lh_b && !over_scrollbar && hov_idx >= 0 && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && skin_sel && !UI::IsOpenColorPickerBlocking() && !UI::IsOpenDropdownHovered())
            *skin_sel = hov_idx;

        float right_box_bottom = skin_box_top + skin_box_h;
        DrawBox(dl, wpos, skin_box_x, skin_box_top, right_box_bottom, skin_box_w, "skin", Colors::ColHdr);

        if (skin_max_scroll > 0.0f) {
            float track_h = skin_list_h;
            float thumb_h = ImMax(4.0f, track_h * (skin_list_h / skin_content_h) * 0.4f);
            float thumb_y = lp.y + (s_skin_scroll_y / skin_max_scroll) * (track_h - thumb_h);

            bool over_thumb = (ms.x >= le.x - 6.0f && ms.x <= le.x &&
                               ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

            if (!s_skin_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                s_skin_dragging = true;
                s_skin_drag_start_y = ms.y;
                s_skin_drag_scroll = s_skin_scroll_y;
            }
            if (s_skin_dragging) {
                    if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                        float delta = ms.y - s_skin_drag_start_y;
                        float track_diff = track_h - thumb_h;
                        if (track_diff > 0.0001f) {
                            s_skin_scroll_y = ImClamp(s_skin_drag_scroll + delta / track_diff * skin_max_scroll, 0.0f, skin_max_scroll);
                            ScrollTarget(s_skin_scroll_y) = s_skin_scroll_y;
                        }
                    ImGui::GetIO().WantCaptureMouse = true;
                } else {
                    s_skin_dragging = false;
                }
            }

            ImU32 thumb_col = s_skin_dragging ? Colors::Accent : Colors::ScrollbarGrab;

            dl->AddRectFilled(ImVec2(le.x - 6.0f, lp.y),
                              ImVec2(le.x, le.y), Colors::ScrollbarTrack, 0.0f);

            dl->AddRectFilled(ImVec2(le.x - 5.0f, thumb_y),
                              ImVec2(le.x - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
        } else {
            s_skin_dragging = false;
        }

        // ---- Separate, draggable skin-preview window ----
        // Drawn on the foreground list so it floats above (and can be moved out
        // of) the menu. Shows the enlarged icon of the currently selected skin.
        {
            const float pv_w      = 200.0f;
            const float pv_title  = 24.0f;
            const float pv_pad    = 12.0f;
            const float pv_img    = pv_w - pv_pad * 2.0f;
            const float pv_h      = pv_title + pv_img + pv_pad;

            if (s_skin_preview_x < 0.0f || s_skin_preview_y < 0.0f) {
                s_skin_preview_x = s_menu_x + s_menu_w + 12.0f;
                s_skin_preview_y = s_menu_y;
            }
            s_skin_preview_x = ImClamp(s_skin_preview_x, 0.0f, ImMax(0.0f, io.DisplaySize.x - pv_w));
            s_skin_preview_y = ImClamp(s_skin_preview_y, 0.0f, ImMax(0.0f, io.DisplaySize.y - pv_h));

            // snap to main menu window with 5f gap
            {
                const float snap_dist = 10.0f;
                const float gap = 5.0f;
                float pr = s_skin_preview_x + pv_w;
                float pb = s_skin_preview_y + pv_h;
                float mr = s_menu_x + s_menu_w;
                float mb = s_menu_y + s_menu_h;

                if (fabsf(s_skin_preview_x - (mr + gap)) < snap_dist)
                    s_skin_preview_x = mr + gap;
                else if (fabsf(pr - (s_menu_x - gap)) < snap_dist)
                    s_skin_preview_x = s_menu_x - pv_w - gap;

                if (fabsf(s_skin_preview_y - (mb + gap)) < snap_dist)
                    s_skin_preview_y = mb + gap;
                else if (fabsf(pb - (s_menu_y - gap)) < snap_dist)
                    s_skin_preview_y = s_menu_y - pv_h - gap;
            }

            const ImVec2 w0(s_skin_preview_x, s_skin_preview_y);
            const ImVec2 w1(w0.x + pv_w, w0.y + pv_h);
            ImDrawList* fg = ImGui::GetForegroundDrawList();

            fg->AddRectFilled(w0, w1, Colors::MenuBg, 0.0f);
            fg->AddRect(w0, w1, Colors::BoxBorder, 0.0f, 0, 1.0f);
            fg->AddRect(ImVec2(w0.x + 1, w0.y + 1), ImVec2(w1.x - 1, w1.y - 1), Colors::BoxInnerBorder, 0.0f, 0, 1.0f);

            // menu-style title bar with gradient
            fg->AddRectFilled(w0, ImVec2(w1.x, w0.y + pv_title), Colors::MenuBg, 0.0f);
            fg->AddRectFilledMultiColor(w0, ImVec2(w1.x, w0.y + pv_title),
                Colors::MenuTitleGradTop, Colors::MenuTitleGradTop,
                Colors::MenuTitleGradBot, Colors::MenuTitleGradBot);

            // side strips
            {
                const float ss_w = 1.0f;
                const float ss_off = 2.5f;
                float ss_top = w0.y + pv_title;
                fg->AddRectFilled(ImVec2(w0.x + ss_off, ss_top), ImVec2(w0.x + ss_off + ss_w, w1.y), Colors::SideStrip, 0.0f);
                fg->AddRectFilled(ImVec2(w1.x - ss_off - ss_w, ss_top), ImVec2(w1.x - ss_off, ss_top + (w1.y - ss_top)), Colors::SideStrip, 0.0f);
            }

            // title text
            {
                const char* t = "preview";
                ImVec2 ts = ImGui::CalcTextSize(t);
                fg->AddText(ImVec2(w0.x + (pv_w - ts.x) * 0.5f, w0.y + (pv_title - ts.y) * 0.5f), Colors::MenuTitleText, t);
            }

            // image square
            ImVec2 iv0(w0.x + pv_pad, w0.y + pv_title);
            ImVec2 iv1(iv0.x + pv_img, iv0.y + pv_img);
            fg->AddRectFilled(iv0, iv1, Colors::ListBg, 0.0f);
            fg->AddRect(iv0, iv1, Colors::SectionBorder, 0.0f, 0, 1.0f);

            // gradient accent line at the bottom of the title bar (drawn after image
            // square so it overlays cleanly on top of the border)
            UI::DrawGradientLine(fg, w0.x, w0.y + pv_title, pv_w, 1.5f);

            int paint_kit_id = 0;
            if (skin_def != 0 && skin_sel && *skin_sel > 0)
                paint_kit_id = g_item_schema->get_paint_kit_id_for_item(skin_def, *skin_sel);

            int tw = 0, th = 0;
            ID3D11ShaderResourceView* tex = GetSkinPreviewTexture(skin_def, paint_kit_id, &tw, &th);
            if (tex && tw > 0 && th > 0) {
                float avail = pv_img - 10.0f;
                float scale = avail / (float)ImMax(tw, th);
                float iw = tw * scale, ih = th * scale;
                ImVec2 c((iv0.x + iv1.x) * 0.5f, (iv0.y + iv1.y) * 0.5f);
                fg->PushClipRect(ImVec2(iv0.x + 2, iv0.y + 2), ImVec2(iv1.x - 2, iv1.y - 2), true);
                fg->AddImage((ImTextureID)tex, ImVec2(c.x - iw * 0.5f, c.y - ih * 0.5f), ImVec2(c.x + iw * 0.5f, c.y + ih * 0.5f));
                fg->PopClipRect();
            } else {
                const char* msg = "default";
                ImVec2 ts = ImGui::CalcTextSize(msg);
                fg->AddText(ImVec2((iv0.x + iv1.x) * 0.5f - ts.x * 0.5f, (iv0.y + iv1.y) * 0.5f - ts.y * 0.5f), Colors::TextDim, msg);
            }

            // input: capture hover, drag by the title bar
            bool over_win   = (ms.x >= w0.x && ms.x <= w1.x && ms.y >= w0.y && ms.y <= w1.y);
            bool over_title = (ms.x >= w0.x && ms.x <= w1.x && ms.y >= w0.y && ms.y <= w0.y + pv_title);
            if (over_win)
                io.WantCaptureMouse = true;

            const bool other_drag = g_menu_dragging || s_models_dragging || s_skin_dragging;
            if (!ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                s_skin_preview_dragging = false;
            } else if (!s_skin_preview_dragging && over_title && ImGui::IsMouseClicked(ImGuiMouseButton_Left)
                       && !other_drag && !UI::IsOpenColorPickerBlocking() && !UI::IsOpenDropdownHovered()) {
                s_skin_preview_dragging = true;
                s_skin_preview_drag_off = ImVec2(ms.x - w0.x, ms.y - w0.y);
            }
            if (s_skin_preview_dragging) {
                s_skin_preview_x = ms.x - s_skin_preview_drag_off.x;
                s_skin_preview_y = ms.y - s_skin_preview_drag_off.y;
                io.WantCaptureMouse = true;
            }
        }
    }
    if (s.active_tab == 3) {
        const float gap2 = 2.0f;
        static float s_move_scroll_y = 0.0f;

        float mov_field_w = l_l_w - l_box_pad * 2;
        float left_total_avail = (s_menu_h) - cy - 10.0f;
        float left_box_h = (left_total_avail - 8.0f) / 2.0f;
        float mov_box_h = left_box_h;
        float mov_box_bottom = cy + mov_box_h;
        DrawBox(dl, wpos, l_padding, cy, mov_box_bottom, l_l_w, "movement", Colors::ColHdr);

        ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + cy + l_box_pad + 10.0f));
        ImGui::BeginChild("##move_scroll", ImVec2(mov_field_w, mov_box_h - l_box_pad * 2 - 10.0f), false,
            ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::SetScrollY(s_move_scroll_y);

        float ly = 0.0f;
        ImGui::SetCursorPos(ImVec2(0, ly));
        UI::Checkbox("bunny hop", &g_cfg->movement.m_bhop, nullptr, nullptr, mov_field_w);
        ly = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(0, ly));
        UI::Checkbox("autostrafe", &g_cfg->movement.m_autostrafe, nullptr, nullptr, mov_field_w, s.menu_theme == 1 ? IM_COL32(0,0,0,0) : IM_COL32(0xF6, 0xC8, 0x9B, 255), s.menu_theme == 1 ? IM_COL32(0,0,0,0) : IM_COL32(0xB0, 0x96, 0x7D, 255));
        ly = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(0, ly));
        UI::Checkbox("jump bug", &g_cfg->movement.m_jump_bug, "jump_bug", "", mov_field_w);
        ly = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(0, ly));
        UI::Checkbox("mini jump", &g_cfg->movement.m_mini_jump, nullptr, nullptr, mov_field_w);
        ly = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(0, ly));
        UI::Checkbox("edge jump", &g_cfg->movement.m_edge_jump, "edge_jump", "", mov_field_w);
        ly = ImGui::GetCursorPos().y + gap2;
        ImGui::SetCursorPos(ImVec2(0, ly));
        UI::Checkbox("null strafe", &s.null_strafe, "null_strafe", "", mov_field_w);
        ly = ImGui::GetCursorPos().y;

        float mov_content_h = ly;
        ImGui::SetCursorPos(ImVec2(0, ly));
        ImGui::Dummy(ImVec2(1.0f, 1.0f));
        ImGui::EndChild();

        float mov_view_h = mov_box_h - l_box_pad * 2 - 10.0f;
        float mov_max_scroll = ImMax(0.0f, mov_content_h - mov_view_h);
        ScrollEase(s_move_scroll_y, mov_max_scroll);
        s_move_scroll_y = ImClamp(s_move_scroll_y, 0.0f, mov_max_scroll);

        float mov_box_right = wpos.x + l_padding + l_l_w;
        float mov_scroll_top = wpos.y + cy;
        float mov_scroll_bottom = wpos.y + cy + mov_box_h;
        ImVec2 mov_area_min = ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + cy + l_box_pad + 10.0f);
        ImVec2 mov_area_max = ImVec2(mov_area_min.x + mov_field_w, wpos.y + cy + mov_box_h - l_box_pad);
        ImVec2 ms = ImGui::GetIO().MousePos;

        if (mov_max_scroll > 0.0f) {
            float track_h = mov_scroll_bottom - mov_scroll_top;
            float thumb_h = ImMax(4.0f, track_h * (mov_view_h / mov_content_h) * 0.4f);
            float thumb_y = mov_scroll_top + (s_move_scroll_y / mov_max_scroll) * (track_h - thumb_h);

            bool mov_hovered = (ms.x >= mov_area_min.x && ms.x <= mov_area_max.x &&
                ms.y >= mov_area_min.y && ms.y <= mov_area_max.y);

            bool over_thumb = (ms.x >= mov_box_right - 6.0f && ms.x <= mov_box_right &&
                ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

            if (!s_move_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                s_move_dragging = true;
                s_move_drag_start_y = ms.y;
                s_move_drag_scroll = s_move_scroll_y;
            }
            if (s_move_dragging) {
                    if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                        float delta = ms.y - s_move_drag_start_y;
                        float track_diff = track_h - thumb_h;
                        if (track_diff > 0.0001f) {
                            s_move_scroll_y = ImClamp(s_move_drag_scroll + delta / track_diff * mov_max_scroll, 0.0f, mov_max_scroll);
                            ScrollTarget(s_move_scroll_y) = s_move_scroll_y;
                        }
                    ImGui::GetIO().WantCaptureMouse = true;
                }
                else {
                    s_move_dragging = false;
                }
            }

            if (mov_hovered && !over_thumb && !s_move_dragging && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking()) {
                float& tgt = ScrollTarget(s_move_scroll_y);
                tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 40.0f, 0.0f, mov_max_scroll);
                ImGui::GetIO().WantCaptureMouse = true;
            }

            ImU32 thumb_col = s_move_dragging ? Colors::Accent : Colors::ScrollbarGrab;

            dl->AddRectFilled(ImVec2(mov_box_right - 6.0f, mov_scroll_top),
                ImVec2(mov_box_right, mov_scroll_bottom), Colors::ScrollbarTrack, 0.0f);
            dl->AddRectFilled(ImVec2(mov_box_right - 5.0f, thumb_y),
                ImVec2(mov_box_right - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
        }
        else {
            s_move_dragging = false;
        }

        float mbox_top = mov_box_bottom + 8.0f;
        float mbox_h = left_box_h;
        float mbox_bottom = mbox_top + mbox_h;
        DrawBox(dl, wpos, l_padding, mbox_top, mbox_bottom, l_l_w, "miscellaneous", Colors::ColHdr);

        static float s_misc_scroll_y = 0.0f;

        ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + mbox_top + l_box_pad + 10.0f));
        ImGui::BeginChild("##misc_scroll", ImVec2(mov_field_w, mbox_h - l_box_pad * 2 - 10.0f), false,
            ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::SetScrollY(s_misc_scroll_y);

        float my = 0.0f;
        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("hitlogs", &g_cfg->misc.m_hit_logs, nullptr, nullptr, mov_field_w);
        my = ImGui::GetCursorPos().y + gap2;
        if (g_cfg->misc.m_hit_logs) {
            ImGui::SetCursorPos(ImVec2(0, my));
            static const char* k_hit_log_types[] = { "celerity", "Memesense" };
            UI::Dropdown("##hitlogs_type", &g_cfg->misc.m_hit_logs_type, k_hit_log_types, 2, mov_field_w);
            my = ImGui::GetCursorPos().y + gap2;
        }

        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("hitmarker", &g_cfg->misc.m_hitmarker, nullptr, nullptr, mov_field_w);
        my = ImGui::GetCursorPos().y + gap2;

        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("hitsound", &g_cfg->misc.m_sounds, nullptr, nullptr, mov_field_w);
        my = ImGui::GetCursorPos().y + gap2;
        if (g_cfg->misc.m_sounds) {
            ImGui::SetCursorPos(ImVec2(0, my));
            static const char* k_sound_types[] = { "money", "bell", "neverlose", "bubble", "metal", "rust", "sparkle" };
            if (UI::Dropdown("##sound_type", &g_cfg->misc.m_sounds_type, k_sound_types, 7, mov_field_w)) {
                if (g_hit_sound)
                    g_hit_sound->play(g_cfg->misc.m_sounds_type);
            }
            my = ImGui::GetCursorPos().y + gap2;
            ImGui::SetCursorPos(ImVec2(0, my));
            UI::SliderFloat("volume", &g_cfg->misc.m_sounds_volume, 0.0f, 100.0f, "", "%.0f", mov_field_w);
            my = ImGui::GetCursorPos().y + gap2;
        }

        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("motion blur", &g_cfg->visuals.m_motion_blur.m_enabled, nullptr, nullptr, mov_field_w);
        my = ImGui::GetCursorPos().y + gap2;
        if (g_cfg->visuals.m_motion_blur.m_enabled) {
            ImGui::SetCursorPos(ImVec2(0, my));
            UI::SliderFloat("##motion_blur_strength", &g_cfg->visuals.m_motion_blur.m_strength, 0.05f, 1.0f, "", "%.2f", mov_field_w);
            my = ImGui::GetCursorPos().y + gap2;
        }

        ImGui::SetCursorPos(ImVec2(0, my));
        UI::Checkbox("movement trail", &s.movement_trails, nullptr, nullptr, mov_field_w - 22.0f);
        float mt_ry = ImGui::GetCursorPos().y;
        ImGui::SetCursorPos(ImVec2(0, my));
        float m_sr = wpos.x + l_padding + l_l_w - l_box_pad;
        UI::ColorPicker("##mt_col", &s.movement_trails_col, m_sr, 0.0f);
        my = mt_ry + gap2;


        float misc_content_h = my;
        ImGui::SetCursorPos(ImVec2(0, my));
        ImGui::Dummy(ImVec2(1.0f, 1.0f));
        ImGui::EndChild();

        float misc_view_h = mbox_h - l_box_pad * 2 - 10.0f;
        float misc_max_scroll = ImMax(0.0f, misc_content_h - misc_view_h);
        ScrollEase(s_misc_scroll_y, misc_max_scroll);
        s_misc_scroll_y = ImClamp(s_misc_scroll_y, 0.0f, misc_max_scroll);

        float misc_box_right = wpos.x + l_padding + l_l_w;
        float misc_scroll_top = wpos.y + mbox_top;
        float misc_scroll_bottom = wpos.y + mbox_top + mbox_h;
        ImVec2 misc_area_min = ImVec2(wpos.x + l_padding + l_box_pad, wpos.y + mbox_top + l_box_pad + 10.0f);
        ImVec2 misc_area_max = ImVec2(misc_area_min.x + mov_field_w, wpos.y + mbox_top + mbox_h - l_box_pad);

        if (misc_max_scroll > 0.0f) {
            float track_h = misc_scroll_bottom - misc_scroll_top;
            float thumb_h = ImMax(4.0f, track_h * (misc_view_h / misc_content_h) * 0.4f);
            float thumb_y = misc_scroll_top + (s_misc_scroll_y / misc_max_scroll) * (track_h - thumb_h);

            bool misc_hovered = (ms.x >= misc_area_min.x && ms.x <= misc_area_max.x &&
                ms.y >= misc_area_min.y && ms.y <= misc_area_max.y);

            bool over_thumb = (ms.x >= misc_box_right - 6.0f && ms.x <= misc_box_right &&
                ms.y >= thumb_y && ms.y <= thumb_y + thumb_h);

            if (!s_misc_dragging && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && over_thumb && !UI::IsOpenColorPickerBlocking()) {
                s_misc_dragging = true;
                s_misc_drag_start_y = ms.y;
                s_misc_drag_scroll = s_misc_scroll_y;
            }
            if (s_misc_dragging) {
                    if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
                        float delta = ms.y - s_misc_drag_start_y;
                        float track_diff = track_h - thumb_h;
                        if (track_diff > 0.0001f) {
                            s_misc_scroll_y = ImClamp(s_misc_drag_scroll + delta / track_diff * misc_max_scroll, 0.0f, misc_max_scroll);
                            ScrollTarget(s_misc_scroll_y) = s_misc_scroll_y;
                        }
                    ImGui::GetIO().WantCaptureMouse = true;
                }
                else {
                    s_misc_dragging = false;
                }
            }

            if (misc_hovered && !over_thumb && !s_misc_dragging && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking()) {
                float& tgt = ScrollTarget(s_misc_scroll_y);
                tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 40.0f, 0.0f, misc_max_scroll);
                ImGui::GetIO().WantCaptureMouse = true;
            }

            ImU32 thumb_col = s_misc_dragging ? Colors::Accent : Colors::ScrollbarGrab;

            dl->AddRectFilled(ImVec2(misc_box_right - 6.0f, misc_scroll_top),
                ImVec2(misc_box_right, misc_scroll_bottom), Colors::ScrollbarTrack, 0.0f);
            dl->AddRectFilled(ImVec2(misc_box_right - 5.0f, thumb_y),
                ImVec2(misc_box_right - 1.0f, thumb_y + thumb_h), thumb_col, 0.0f);
        }
        else {
            s_misc_dragging = false;
        }

        float r_sr = wpos.x + l_r_x + l_r_w - l_box_pad;
        const float r_col_gap = 8.0f;
        float rbox_top = cy;
        float r_col_bottom = rbox_top + left_total_avail;
        float ind_box_h = (left_total_avail - r_col_gap) * 0.6f;
        float rbox_bottom = rbox_top + ind_box_h;
        float rbox_h = ind_box_h;

        const float r_field_w = l_r_w - l_box_pad * 2;
        const float r_gap2 = 2.0f;

        DrawBox(dl, wpos, l_r_x, rbox_top, rbox_bottom, l_r_w, "indicators", Colors::ColHdr);

        ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + rbox_top + l_box_pad + 10.0f));
        ImGui::BeginChild("##indicators_scroll", ImVec2(r_field_w, rbox_h - l_box_pad * 2 - 10.0f), false,
            ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

        float child_ry = 0.0f;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::SliderFloat("offset", &s.ind_offset, 0.0f, 200.0f, "", "%.0f", r_field_w);
        child_ry = ImGui::GetCursorPos().y + r_gap2 + 3.0f;
        float child_ry_next = 0.0f;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::Checkbox("spotify display", &s.ind_spotify, nullptr, nullptr, r_field_w - 22.0f);
        child_ry_next = ImGui::GetCursorPos().y + r_gap2;
        child_ry = child_ry_next;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::Checkbox("velocity text", &s.vel_display, nullptr, nullptr, r_field_w - 73.0f);
        child_ry_next = ImGui::GetCursorPos().y + r_gap2;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::ColorPicker("##vd_col1", &s.vel_display_col1, r_sr, COLOR_PICKER_STEP * 2.0f);
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::ColorPicker("##vd_col2", &s.vel_display_col2, r_sr, COLOR_PICKER_STEP);
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::ColorPicker("##vd_col3", &s.vel_display_col3, r_sr, 0.0f);
        child_ry = child_ry_next;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::Checkbox("keystrokes", &s.keystrokes, nullptr, nullptr, r_field_w - 22.0f);
        child_ry_next = ImGui::GetCursorPos().y + r_gap2;
        child_ry = child_ry_next;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::Checkbox("velocity graph", &s.vel_graph, nullptr, nullptr, r_field_w - 22.0f);
        child_ry_next = ImGui::GetCursorPos().y;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::ColorPicker("##vg_col", &s.vel_graph_col, r_sr, 0.0f);
        child_ry = child_ry_next;
        child_ry += r_gap2;
        ImGui::SetCursorPos(ImVec2(0, child_ry));
        UI::Checkbox("jump stats", &s.jump_stats, nullptr, nullptr, r_field_w - 22.0f);
        child_ry = ImGui::GetCursorPos().y;
        child_ry += r_gap2;

        ImGui::SetCursorPos(ImVec2(0, child_ry));
        ImGui::Dummy(ImVec2(1.0f, 1.0f));
        ImGui::EndChild();

        // ── menu box ────────────────────────────────────────────────────────
        float mnu_box_top    = rbox_bottom + r_col_gap;
        float mnu_box_bottom = r_col_bottom;
        DrawBox(dl, wpos, l_r_x, mnu_box_top, mnu_box_bottom, l_r_w, "menu", Colors::ColHdr);

        {
            const float menu_color_row_h = ImMax(18.0f, 20.0f * ui_scale);
            const float gap2 = 2.0f;
            float mny = mnu_box_top + l_box_pad + 10.0f;

            // toggle menu bind (uses absolute wpos coords, no BeginChild needed)
            DrawMenuBindRow(dl, wpos, l_r_x + l_box_pad + 15.0f, l_r_x + l_box_pad, mny, r_field_w, lh);
            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + mny));
            ImGui::InvisibleButton("##mnu_bind_spacer", ImVec2(r_field_w, menu_color_row_h));
            mny += menu_color_row_h + 3.0f;

            // menu color
            float mnu_sr_abs = wpos.x + l_r_x + l_r_w - l_box_pad;
            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad + 15.0f, wpos.y + mny + (menu_color_row_h - lh) * 0.5f));
            ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Text), "menu color");
            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + mny));
            UI::ColorPicker("##mnu_col", &s.menu_color, mnu_sr_abs, 0.0f);
            mny += menu_color_row_h + 3.0f;

            // menu effect
            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad + 15.0f, wpos.y + mny + (menu_color_row_h - lh) * 0.5f));
            ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Text), "menu effect");
            mny += menu_color_row_h + 3.0f;
            if (s.menu_weather < 0 || s.menu_weather > 2) s.menu_weather = 0;
            static const char* weather_types_m[] = { "none", "snow", "rain" };
            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + mny));
            UI::Dropdown("##weather_m", &s.menu_weather, weather_types_m, 3, r_field_w);
            mny += ImGui::GetTextLineHeight() + 8.0f + gap2;

            // themes
            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad + 15.0f, wpos.y + mny + (menu_color_row_h - lh) * 0.5f));
            ImGui::TextColored(ImGui::ColorConvertU32ToFloat4(Colors::Text), "themes");
            mny += menu_color_row_h + 3.0f;
            static const char* theme_types_m[] = { "default", "midnight", "oled" };
            ImGui::SetCursorScreenPos(ImVec2(wpos.x + l_r_x + l_box_pad, wpos.y + mny));
            UI::Dropdown("##theme_m", &s.menu_theme, theme_types_m, 3, r_field_w);
        }

        reserve_content_bottom(ImMax(mbox_bottom, mnu_box_bottom));
    }
    if (s.active_tab == 4) {
        s_cfg_refresh_timer += io.DeltaTime;
        if (s_cfg_dirty || s_cfg_refresh_timer >= 2.0f) {
            CfgScan();
            s_cfg_refresh_timer = 0.0f;
        }

        // ─────────────────────────────────────────────────────────────────────
        // full-width config list (spanning both columns)
        // ─────────────────────────────────────────────────────────────────────
        const float full_w = l_l_w + l_gap + l_r_w;
        const float content_x = l_padding;
        float content_y = cy;

        ImFont* g_font = ImGui::GetFont();
        ImFont* g_font_bold = g_menu ? g_menu->get_menu_bold_font() : g_font;

        // search bar
        const float search_h = 32.0f;
        const float search_pad = 8.0f;
        const float icon_size = 16.0f;
        const float top_btn_w = 32.0f;
        const float top_btn_gap = 6.0f;
        
        // Вычисляем ширину search bar с учётом кнопок справа
        const float buttons_total_w = (top_btn_w + top_btn_gap) * 2;
        const float search_bar_w = full_w - buttons_total_w - top_btn_gap;

        ImVec2 search_p0 = S(content_x, content_y);
        ImVec2 search_p1 = ImVec2(search_p0.x + search_bar_w, search_p0.y + search_h);
        dl->AddRectFilled(search_p0, search_p1, IM_COL32(25, 25, 25, 255), 6.0f);

        // search icon
        dl->AddText(g_font, g_font->FontSize,
                    ImVec2(search_p0.x + search_pad + 2.0f, search_p0.y + (search_h - lh) * 0.5f),
                    IM_COL32(120, 120, 120, 255), ICON_FA_SEARCH);

        // search input (working)
        const float search_input_w = search_bar_w - search_pad * 2 - icon_size - 8.0f;
        ImGui::SetCursorScreenPos(ImVec2(search_p0.x + search_pad + icon_size + 8.0f, search_p0.y + (search_h - 22.0f) * 0.5f));
        ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(25, 25, 25, 0));
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(200, 200, 200, 255));
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4.0f, 4.0f));
        ImGui::SetNextItemWidth(search_input_w);
        ImGui::InputTextWithHint("##cfg_search", "Search scripts", s_cfg_search, sizeof(s_cfg_search));
        ImGui::PopStyleVar();
        ImGui::PopStyleColor(2);

        // top buttons (folder, add) - removed refresh
        float btn_x = search_p0.x + full_w - search_pad - top_btn_w;
        ImVec2 add_p0 = ImVec2(btn_x, search_p0.y + (search_h - top_btn_w) * 0.5f);
        ImVec2 add_p1 = ImVec2(add_p0.x + top_btn_w, add_p0.y + top_btn_w);
        ImVec2 mouse = ImGui::GetIO().MousePos;
        bool add_hov = (mouse.x >= add_p0.x && mouse.x <= add_p1.x &&
                        mouse.y >= add_p0.y && mouse.y <= add_p1.y);
        dl->AddRectFilled(add_p0, add_p1, add_hov ? IM_COL32(35, 35, 35, 255) : IM_COL32(25, 25, 25, 255), 6.0f);
        
        // Измеряем реальный размер иконки для центровки
        ImVec2 plus_icon_size = g_font->CalcTextSizeA(g_font->FontSize, FLT_MAX, 0.0f, ICON_FA_PLUS);
        dl->AddText(g_font, g_font->FontSize,
                    ImVec2(add_p0.x + (top_btn_w - plus_icon_size.x) * 0.5f, add_p0.y + (top_btn_w - plus_icon_size.y) * 0.5f),
                    IM_COL32(180, 180, 180, 255), ICON_FA_PLUS);
        ImGui::SetCursorScreenPos(add_p0);
        ImGui::InvisibleButton("##cfg_add", ImVec2(top_btn_w, top_btn_w));
        if (ImGui::IsItemClicked()) {
            // Copy search text to input buffer for config creation
            strncpy_s(s_cfg_input, s_cfg_search, sizeof(s_cfg_input) - 1);
            s_cfg_input[sizeof(s_cfg_input) - 1] = '\0';
            CfgCreate();
            // Clear search after creating
            s_cfg_search[0] = '\0';
        }

        btn_x -= (top_btn_w + top_btn_gap);
        ImVec2 folder_p0 = ImVec2(btn_x, search_p0.y + (search_h - top_btn_w) * 0.5f);
        ImVec2 folder_p1 = ImVec2(folder_p0.x + top_btn_w, folder_p0.y + top_btn_w);
        bool folder_hov = (mouse.x >= folder_p0.x && mouse.x <= folder_p1.x &&
                           mouse.y >= folder_p0.y && mouse.y <= folder_p1.y);
        dl->AddRectFilled(folder_p0, folder_p1, folder_hov ? IM_COL32(35, 35, 35, 255) : IM_COL32(25, 25, 25, 255), 6.0f);
        
        // Измеряем реальный размер иконки для центровки
        ImVec2 link_icon_size = g_font->CalcTextSizeA(g_font->FontSize, FLT_MAX, 0.0f, ICON_FA_LINK);
        dl->AddText(g_font, g_font->FontSize,
                    ImVec2(folder_p0.x + (top_btn_w - link_icon_size.x) * 0.5f, folder_p0.y + (top_btn_w - link_icon_size.y) * 0.5f),
                    IM_COL32(180, 180, 180, 255), ICON_FA_LINK);
        ImGui::SetCursorScreenPos(folder_p0);
        ImGui::InvisibleButton("##cfg_folder", ImVec2(top_btn_w, top_btn_w));
        if (ImGui::IsItemClicked()) CfgOpenDir();

        content_y += search_h + 8.0f;

        // Filter configs based on search
        std::vector<int> filtered_indices;
        std::string search_lower = s_cfg_search;
        std::transform(search_lower.begin(), search_lower.end(), search_lower.begin(), ::tolower);
        
        for (int i = 0; i < (int)s_cfg_list.size(); i++) {
            if (search_lower.empty()) {
                filtered_indices.push_back(i);
            } else {
                std::string cfg_name_lower = s_cfg_list[i];
                std::transform(cfg_name_lower.begin(), cfg_name_lower.end(), cfg_name_lower.begin(), ::tolower);
                if (cfg_name_lower.find(search_lower) != std::string::npos) {
                    filtered_indices.push_back(i);
                }
            }
        }

        // config cards
        const float card_h = 60.0f;
        const float card_gap = 6.0f;
        const float card_pad = 12.0f;
        const float card_icon_size = 36.0f;
        const float card_btn_size = 28.0f;
        const float card_btn_gap = 4.0f;

        float list_h = (s_menu_h) - 10.0f - content_y;
        ImVec2 list_p0 = S(content_x, content_y);
        ImVec2 list_p1 = ImVec2(list_p0.x + full_w, list_p0.y + list_h);

        const float cfg_content_h = (float)filtered_indices.size() * (card_h + card_gap);
        const float cfg_max_scroll = ImMax(0.0f, cfg_content_h - list_h);
        const bool list_hovered = (mouse.x >= list_p0.x && mouse.x <= list_p1.x &&
                                   mouse.y >= list_p0.y && mouse.y <= list_p1.y);
        ScrollEase(s_cfg_scroll_y, cfg_max_scroll);
        s_cfg_scroll_y = ImClamp(s_cfg_scroll_y, 0.0f, cfg_max_scroll);
        if (list_hovered && cfg_max_scroll > 0.0f && ImGui::GetIO().MouseWheel != 0.0f && !UI::IsOpenColorPickerBlocking()) {
            float& tgt = ScrollTarget(s_cfg_scroll_y);
            tgt = ImClamp(tgt - ImGui::GetIO().MouseWheel * 60.0f, 0.0f, cfg_max_scroll);
            ImGui::GetIO().WantCaptureMouse = true;
        }

        dl->PushClipRect(list_p0, list_p1, true);

        int first_cfg = ImMax(0, (int)(s_cfg_scroll_y / (card_h + card_gap)));
        int max_vis = (int)(list_h / (card_h + card_gap)) + 2;
        int last_cfg = ImMin((int)filtered_indices.size(), first_cfg + max_vis);

        for (int idx = first_cfg; idx < last_cfg; idx++) {
            int i = filtered_indices[idx];
            float card_y = list_p0.y + idx * (card_h + card_gap) - s_cfg_scroll_y;
            ImVec2 card_p0 = ImVec2(list_p0.x, card_y);
            ImVec2 card_p1 = ImVec2(list_p1.x, card_y + card_h);

            bool card_hov = (mouse.x >= card_p0.x && mouse.x <= card_p1.x &&
                             mouse.y >= card_p0.y && mouse.y <= card_p1.y);

            // card background
            dl->AddRectFilled(card_p0, card_p1, card_hov ? IM_COL32(30, 30, 30, 255) : IM_COL32(25, 25, 25, 255), 6.0f);

            // icon placeholder (camera icon)
            ImVec2 icon_p0 = ImVec2(card_p0.x + card_pad, card_p0.y + (card_h - card_icon_size) * 0.5f);
            ImVec2 icon_p1 = ImVec2(icon_p0.x + card_icon_size, icon_p0.y + card_icon_size);
            dl->AddRectFilled(icon_p0, icon_p1, IM_COL32(35, 35, 35, 255), 4.0f);
            dl->AddText(g_font, g_font->FontSize * 1.2f,
                        ImVec2(icon_p0.x + (card_icon_size - 14.0f) * 0.5f, icon_p0.y + (card_icon_size - lh * 1.2f) * 0.5f),
                        IM_COL32(100, 100, 100, 255), ICON_FA_CAMERA);

            // config name + modified date
            float text_x = icon_p1.x + 12.0f;
            float name_y = card_p0.y + card_pad + 2.0f;
            dl->AddText(g_font_bold, g_font_bold->FontSize,
                        ImVec2(text_x, name_y),
                        IM_COL32(220, 220, 220, 255), s_cfg_list[i].c_str());

            // Get file modification date
            std::string cfg_path = std::string(k_cfg_dir) + s_cfg_list[i] + ".json";
            char date_str[64] = "Modified: Unknown";
            WIN32_FILE_ATTRIBUTE_DATA fileInfo;
            if (GetFileAttributesExA(cfg_path.c_str(), GetFileExInfoStandard, &fileInfo)) {
                SYSTEMTIME st;
                FileTimeToSystemTime(&fileInfo.ftLastWriteTime, &st);
                snprintf(date_str, sizeof(date_str), "Modified: %02d.%02d.%04d", st.wDay, st.wMonth, st.wYear);
            }

            float date_y = name_y + lh + 4.0f;
            dl->AddText(g_font, g_font->FontSize * 0.9f,
                        ImVec2(text_x, date_y),
                        IM_COL32(100, 100, 100, 255), date_str);

            // action buttons (right side): delete, save, load
            float btn_r = card_p1.x - card_pad;
            const char* btn_icons[] = { ICON_FA_TRASH, ICON_FA_DOWNLOAD, ICON_FA_UPLOAD };
            for (int b = 2; b >= 0; b--) {
                float btn_x = btn_r - card_btn_size;
                ImVec2 btn_p0 = ImVec2(btn_x, card_p0.y + (card_h - card_btn_size) * 0.5f);
                ImVec2 btn_p1 = ImVec2(btn_p0.x + card_btn_size, btn_p0.y + card_btn_size);
                
                bool btn_hov = (mouse.x >= btn_p0.x && mouse.x <= btn_p1.x &&
                                mouse.y >= btn_p0.y && mouse.y <= btn_p1.y);
                
                // Фон кнопки с более выраженным hover эффектом
                ImU32 bg_color = btn_hov ? IM_COL32(55, 55, 60, 255) : IM_COL32(35, 35, 38, 255);
                dl->AddRectFilled(btn_p0, btn_p1, bg_color, 6.0f);
                
                // Измеряем размер иконки для центровки
                ImVec2 icon_size = g_font->CalcTextSizeA(g_font->FontSize, FLT_MAX, 0.0f, btn_icons[b]);
                float icon_x = btn_p0.x + (card_btn_size - icon_size.x) * 0.5f;
                float icon_y = btn_p0.y + (card_btn_size - icon_size.y) * 0.5f;
                
                // Отрисовка иконки серым цветом
                ImU32 icon_color = btn_hov ? IM_COL32(220, 220, 220, 255) : IM_COL32(180, 180, 180, 255);
                dl->AddText(g_font, g_font->FontSize,
                            ImVec2(icon_x, icon_y),
                            icon_color, btn_icons[b]);
                
                ImGui::SetCursorScreenPos(btn_p0);
                char btn_id[32];
                snprintf(btn_id, sizeof(btn_id), "##cfg_btn_%d_%d", i, b);
                ImGui::InvisibleButton(btn_id, ImVec2(card_btn_size, card_btn_size));
                if (ImGui::IsItemClicked()) {
                    s_cfg_sel = i;
                    g_config_system->m_selected_config = s_cfg_list[i];
                    if (b == 2) CfgLoad();        // load
                    else if (b == 1) CfgSave();   // save
                    else if (b == 0) CfgDelete(); // delete
                }
                btn_r = btn_x - card_btn_gap;
            }
        }

        dl->PopClipRect();

        reserve_content_bottom(list_p1.y);
    }

    dl->PopClipRect();
    }
    ImGui::EndChild();
    UI::RenderOpenDropdown();
    UI::RenderOpenColorPicker();
    UI::RenderBindModePopup();
    ImGui::PopStyleColor(4);
    ImGui::PopStyleVar(4); // WindowPadding + ItemSpacing + GrabMinSize + Alpha
    dl_frame->PopClipRect();
    g_sidebar_blur_x = wpos_frame.x;
    g_sidebar_blur_y = wpos_frame.y;
    g_sidebar_blur_w = l_sidebar_w;
    g_sidebar_blur_h = total_h;
    ImGui::End();
    if (s_skip_skin_sync_to_config)
        s_skip_skin_sync_to_config = false;
    else
        SyncSkinsToConfig();
    SyncAimToConfig();
    SyncMovementToConfig();
    SyncVisualsToConfig();
    SyncIndicatorsToConfig();
    ImGui::PopStyleVar();
}

void c_menu::draw() {
    Menu::g_open = m_opened;
    RenderBankMenu();
    m_opened = s_menu_target_open;
}

void c_menu::on_create_move() {
    if (!s.movement_trails)
        return;

    auto* pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
    if (!pawn || !pawn->is_alive()) {
        g_trail_positions.clear();
        return;
    }

    auto* node = pawn->m_scene_node();
    if (!node)
        return;

    g_trail_positions.push_back({node->m_abs_origin(), std::chrono::steady_clock::now()});
}

    void c_menu::rebuild_fonts(float scale) {
        auto& io = ImGui::GetIO();
        io.Fonts->Clear();
        m_weapon_icon_font = nullptr;
        m_esp_small_font = nullptr;
        m_menu_bold_font = nullptr;
        m_menu_title_font = nullptr;
        m_sidebar_title_font = nullptr;
        m_loading_title_font = nullptr;
        m_loading_status_font = nullptr;
        m_vel_text_font = nullptr;
        m_keystrokes_font = nullptr;

        ImFontConfig font_cfg;
        font_cfg.OversampleH = 1;
        font_cfg.OversampleV = 1;
        font_cfg.PixelSnapH = true;
        font_cfg.RasterizerMultiply = 1.0f;

        ImFontConfig loading_font_cfg = font_cfg;
        loading_font_cfg.OversampleH = 4;
        loading_font_cfg.OversampleV = 4;

        ImFontConfig regular_font_cfg = font_cfg;
        regular_font_cfg.FontDataOwnedByAtlas = false;

        auto add_menu_font = [&](float size, ImFontConfig* cfg) -> ImFont* {
            return io.Fonts->AddFontFromMemoryTTF(
                const_cast<unsigned char*>(font_data::SFProText_Semibold),
                font_data::SFProText_Semibold_size,
                size,
                cfg,
                io.Fonts->GetGlyphRangesCyrillic()
            );
        };

        add_menu_font(17.0f * scale, &regular_font_cfg);

        {
            static const ImWchar fa_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
            ImFontConfig fa_cfg;
            fa_cfg.MergeMode = true;
            fa_cfg.PixelSnapH = true;
            fa_cfg.GlyphOffset.y = 0.0f;
            fa_cfg.FontDataOwnedByAtlas = false;
            io.Fonts->AddFontFromMemoryTTF(font_awesome_binary, sizeof(font_awesome_binary), 17.0f * scale * 0.7f, &fa_cfg, fa_ranges);
        }

        ImFontConfig bold_font_cfg = font_cfg;
        bold_font_cfg.FontDataOwnedByAtlas = false;

        ImFontConfig bold_loading_font_cfg = loading_font_cfg;
        bold_loading_font_cfg.FontDataOwnedByAtlas = false;

        m_menu_bold_font = add_menu_font(17.0f * scale, &bold_font_cfg);
        m_menu_title_font = add_menu_font(27.0f * scale, &bold_font_cfg);
        m_loading_status_font = add_menu_font(21.0f * scale, &bold_loading_font_cfg);
        m_loading_title_font = add_menu_font(58.0f * scale, &bold_loading_font_cfg);

        // Загрузка шрифта SF Pro Bold для заголовка в сайдбаре
        ImFontConfig sidebar_title_font_cfg = font_cfg;
        sidebar_title_font_cfg.FontDataOwnedByAtlas = false;
        sidebar_title_font_cfg.OversampleH = 4;
        sidebar_title_font_cfg.OversampleV = 4;
        m_sidebar_title_font = io.Fonts->AddFontFromMemoryTTF(
            const_cast<unsigned char*>(embedded_font),
            embedded_font_size,
            40.0f * scale,
            &sidebar_title_font_cfg,
            io.Fonts->GetGlyphRangesCyrillic()
        );

        ImFontConfig vel_text_cfg;
        vel_text_cfg.OversampleH = 1;
        vel_text_cfg.OversampleV = 1;
        vel_text_cfg.PixelSnapH = true;
        const char* vel_text_paths[] = {
            "C:\\Windows\\Fonts\\segoeuib.ttf",
            "C:\\Windows\\Fonts\\seguisb.ttf",
        };
        m_vel_text_font = nullptr;
        for (auto path : vel_text_paths) {
            if (GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES) {
                m_vel_text_font = io.Fonts->AddFontFromFileTTF(path, 32.0f * scale, &vel_text_cfg);
                break;
            }
        }
        if (!m_vel_text_font)
            m_vel_text_font = m_menu_bold_font;

        {
            ImFontConfig ks_cfg;
            ks_cfg.OversampleH = 3;
            ks_cfg.OversampleV = 3;
            ks_cfg.PixelSnapH = true;
            ks_cfg.FontDataOwnedByAtlas = false;
            m_keystrokes_font = add_menu_font(32.0f * scale, &ks_cfg);
        }

        ImFontConfig icon_config;
        icon_config.FontDataOwnedByAtlas = false;
        icon_config.OversampleH = 1;
        icon_config.OversampleV = 1;
        icon_config.PixelSnapH = true;
        static const ImWchar icon_ranges[] = { 0xE000, 0xE204, 0 };
        m_weapon_icon_font = io.Fonts->AddFontFromMemoryTTF(
            obs_icons::font_data,
            obs_icons::font_size,
            15.0f * scale,
            &icon_config,
            icon_ranges
        );

        ImFontConfig small_config;
        small_config.FontDataOwnedByAtlas = false;
        small_config.OversampleH = 1;
        small_config.OversampleV = 1;
        small_config.PixelSnapH = true;
        small_config.GlyphExtraSpacing.x = 0.0f;
        small_config.GlyphMinAdvanceX = 0.0f;
        small_config.RasterizerMultiply = 1.0f;

        m_esp_small_font = io.Fonts->AddFontFromMemoryTTF(
            esp_font_5x5::font_data,
        esp_font_5x5::font_size,
        8.0f,
        &small_config,
        io.Fonts->GetGlyphRangesDefault()
    );

    io.Fonts->Build();
    ImGui_ImplDX11_InvalidateDeviceObjects();
    ImGui_ImplDX11_CreateDeviceObjects();

    m_dpi_scale = scale;
}
