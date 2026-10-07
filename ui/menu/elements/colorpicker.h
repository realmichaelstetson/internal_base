#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
#include <string>
#include <cmath>
namespace UI {
namespace _cp {
    inline ImGuiID open_id = 0;
    inline ImVec2  open_pos = {};
    inline ImVec4* editing_color = nullptr;
    inline float   hue = 0.0f;
    inline float   sat = 1.0f;
    inline float   val = 1.0f;
    inline float   alpha = 1.0f;
    inline ImVec2  menu_pos_when_opened = {};
    inline bool    dragging_inside = false;
    inline int     dragging_part = 0;
    inline int     open_frame = -1;
    inline ImGuiID changed_id = 0;
    inline bool    changed_pending = false;
    inline constexpr float picker_w = 220.0f;
    inline constexpr float picker_h = 220.0f;

    inline void Close() {
        open_id = 0;
        editing_color = nullptr;
        dragging_inside = false;
        dragging_part = 0;
        open_frame = -1;
    }

    inline void MarkChanged() {
        changed_id = open_id;
        changed_pending = true;
    }

    inline bool ConsumeChanged(ImGuiID id) {
        if (!changed_pending || changed_id != id)
            return false;

        changed_pending = false;
        changed_id = 0;
        return true;
    }

    inline void ClampOpenPos(float pw, float ph) {
        ImGuiIO& io = ImGui::GetIO();
        if (io.DisplaySize.x <= 0.0f || io.DisplaySize.y <= 0.0f)
            return;

        const float margin = 4.0f;
        open_pos.x = ImClamp(open_pos.x, margin, ImMax(margin, io.DisplaySize.x - pw - margin));
        open_pos.y = ImClamp(open_pos.y, margin, ImMax(margin, io.DisplaySize.y - ph - margin));
    }

    inline ImVec2 ClampedOpenPos(float pw, float ph) {
        ImVec2 out = open_pos;
        ImGuiIO& io = ImGui::GetIO();
        if (io.DisplaySize.x <= 0.0f || io.DisplaySize.y <= 0.0f)
            return out;

        const float margin = 4.0f;
        out.x = ImClamp(out.x, margin, ImMax(margin, io.DisplaySize.x - pw - margin));
        out.y = ImClamp(out.y, margin, ImMax(margin, io.DisplaySize.y - ph - margin));
        return out;
    }

    inline bool IsMouseBlockingOpenPicker() {
        if (open_id == 0)
            return false;

        ImVec2 p0 = ClampedOpenPos(picker_w, picker_h);
        ImVec2 p1 = ImVec2(p0.x + picker_w, p0.y + picker_h);
        ImVec2 mouse = ImGui::GetIO().MousePos;
        return dragging_inside || dragging_part != 0 ||
               (mouse.x >= p0.x - 5.0f && mouse.x <= p1.x + 5.0f &&
                mouse.y >= p0.y - 5.0f && mouse.y <= p1.y + 5.0f);
    }
}
inline bool IsOpenColorPickerBlocking() {
    return _cp::IsMouseBlockingOpenPicker();
}
inline bool ColorPicker(const char* label, ImVec4* color, float right_edge, float offset_from_right = 0.0f) {
    if (!color)
        return false;
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 cursor_pos = ImGui::GetCursorScreenPos();
    const float pw = 20.0f;
    const float ph = 20.0f;
    const float row_h = 28.0f;
    float pos_x = right_edge - pw - offset_from_right - 8.0f;
    ImVec2 pos = ImVec2(pos_x, cursor_pos.y + (row_h - ph) * 0.5f);
    ImVec2 hit_pos = ImVec2(pos.x - 3.0f, pos.y - 3.0f);
    ImGui::SetCursorScreenPos(hit_pos);
    ImGui::InvisibleButton(label, ImVec2(pw + 6.0f, ph + 6.0f));
    bool clicked = ImGui::IsItemClicked(ImGuiMouseButton_Left) && !IsOpenColorPickerBlocking();
    ImGuiID my_id = ImGui::GetID(label);
    bool changed = _cp::ConsumeChanged(my_id);
    if (clicked && color) {
        if (_cp::open_id == my_id) {
        } else {
            _cp::open_id = my_id;
            _cp::open_pos = ImVec2(pos.x + pw * 0.5f, pos.y + ph * 0.5f);
            _cp::editing_color = color;
            ImGuiWindow* root = ImGui::GetCurrentWindowRead()->RootWindow;
            _cp::menu_pos_when_opened = root ? root->Pos : ImGui::GetWindowPos();
            _cp::open_frame = ImGui::GetFrameCount();
            ImGui::ColorConvertRGBtoHSV(color->x, color->y, color->z, _cp::hue, _cp::sat, _cp::val);
            _cp::alpha = color->w;
        }
    }
    if (_cp::open_id == my_id && _cp::editing_color == color) {
        _cp::open_pos = ImVec2(pos.x + pw * 0.5f, pos.y + ph * 0.5f);

        ImGuiWindowFlags capture_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                                         ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
                                         ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground;

        ImVec2 clamped_pos = _cp::ClampedOpenPos(_cp::picker_w, _cp::picker_h);

        ImGui::SetNextWindowPos(clamped_pos);
        ImGui::SetNextWindowSize(ImVec2(_cp::picker_w, _cp::picker_h));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::Begin((std::string("##cp_capture_") + label).c_str(), nullptr, capture_flags);
        ImGui::InvisibleButton("##capture", ImVec2(_cp::picker_w, _cp::picker_h));
        if (ImGui::IsItemHovered())
            ImGui::GetIO().WantCaptureMouse = true;
        ImGui::End();
        ImGui::PopStyleVar();
    }

    ImVec2 p1 = ImVec2(pos.x + pw, pos.y + ph);
    ImVec4 draw_color = color ? *color : ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImU32 col = ImGui::ColorConvertFloat4ToU32(draw_color);
    dl->AddRectFilled(pos, ImVec2(p1.x + 1, p1.y + 1), Colors::InputBg, 5.0f);
    dl->AddRectFilled(pos, p1, col, 5.0f);
    dl->AddRect(pos, p1, Colors::InputBg, 5.0f, 0, 1.0f);
    ImGui::SetCursorScreenPos(ImVec2(cursor_pos.x, cursor_pos.y));
    return changed;
}
inline void RenderOpenColorPicker() {
    if (_cp::open_id == 0) return;
    if (_cp::editing_color == nullptr) {
        _cp::Close();
        return;
    }
    ImGuiWindow* current_window = ImGui::GetCurrentWindowRead();
    ImGuiWindow* root = current_window ? current_window->RootWindow : nullptr;
    ImVec2 current_menu_pos = root ? root->Pos : ImGui::GetWindowPos();
    if (fabsf(current_menu_pos.x - _cp::menu_pos_when_opened.x) > 0.1f ||
        fabsf(current_menu_pos.y - _cp::menu_pos_when_opened.y) > 0.1f) {
        _cp::Close();
        return;
    }
    ImDrawList* fdl = ImGui::GetForegroundDrawList();
    const float sv_size = 180.0f;
    const float hue_w = 14.0f;
    const float alpha_h = 14.0f;
    const float gap = 8.0f;
    _cp::ClampOpenPos(_cp::picker_w, _cp::picker_h);
    ImVec2 p0 = _cp::open_pos;
    ImVec2 p1 = ImVec2(p0.x + _cp::picker_w, p0.y + _cp::picker_h);
    ImVec2 mouse = ImGui::GetIO().MousePos;
    bool mouse_down = ImGui::IsMouseDown(ImGuiMouseButton_Left);
    bool mouse_clicked = ImGui::IsMouseClicked(ImGuiMouseButton_Left);
    bool inside_picker = (mouse.x >= p0.x - 5.0f && mouse.x <= p1.x + 5.0f &&
                          mouse.y >= p0.y - 5.0f && mouse.y <= p1.y + 5.0f);

    if (!mouse_down) {
        _cp::dragging_inside = false;
        _cp::dragging_part = 0;
    }

    if (inside_picker || _cp::dragging_inside || _cp::dragging_part != 0) {
        ImGui::GetIO().WantCaptureMouse = true;
    }

    ImGuiWindowFlags capture_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                                     ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
                                     ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground |
                                     ImGuiWindowFlags_NoNav;
    ImGui::SetNextWindowPos(p0);
    ImGui::SetNextWindowSize(ImVec2(_cp::picker_w, _cp::picker_h));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin("##cp_active_capture", nullptr, capture_flags);
    ImGui::InvisibleButton("##capture", ImVec2(_cp::picker_w, _cp::picker_h));
    if (ImGui::IsItemHovered())
        ImGui::GetIO().WantCaptureMouse = true;
    ImGui::End();
    ImGui::PopStyleVar();

    if (mouse_clicked && !inside_picker && !_cp::dragging_inside && _cp::dragging_part == 0 && ImGui::GetFrameCount() > _cp::open_frame) {
        _cp::Close();
        return;
    }
    fdl->AddRectFilled(ImVec2(p0.x + 2, p0.y + 2), ImVec2(p1.x + 2, p1.y + 2),
                       IM_COL32(0, 0, 0, 60), 4.0f);
    fdl->AddRectFilled(p0, p1, Colors::Bg, 4.0f);
    fdl->AddRect(p0, p1, IM_COL32(22, 22, 22, 255), 4.0f, 0, 1.5f);
    ImVec2 sv_pos = ImVec2(p0.x + 10.0f, p0.y + 10.0f);
    ImVec2 sv_end = ImVec2(sv_pos.x + sv_size, sv_pos.y + sv_size);
    ImVec4 hue_col;
    ImGui::ColorConvertHSVtoRGB(_cp::hue, 1.0f, 1.0f, hue_col.x, hue_col.y, hue_col.z);
    ImU32 hue_u32 = ImGui::ColorConvertFloat4ToU32(ImVec4(hue_col.x, hue_col.y, hue_col.z, 1.0f));
    fdl->AddRectFilledMultiColor(sv_pos, sv_end,
        IM_COL32(255, 255, 255, 255), hue_u32,
        hue_u32, IM_COL32(0, 0, 0, 255));
    fdl->AddRectFilledMultiColor(sv_pos, sv_end,
        IM_COL32(0, 0, 0, 0), IM_COL32(0, 0, 0, 0),
        IM_COL32(0, 0, 0, 255), IM_COL32(0, 0, 0, 255));
    bool sv_hov = (mouse.x >= sv_pos.x && mouse.x <= sv_end.x &&
                   mouse.y >= sv_pos.y && mouse.y <= sv_end.y);
    if (mouse_clicked && sv_hov) {
        _cp::dragging_inside = true;
        _cp::dragging_part = 1;
    }
    if ((sv_hov && mouse_down) || _cp::dragging_part == 1) {
        _cp::sat = ImClamp((mouse.x - sv_pos.x) / sv_size, 0.0f, 1.0f);
        _cp::val = 1.0f - ImClamp((mouse.y - sv_pos.y) / sv_size, 0.0f, 1.0f);
        if (_cp::editing_color != nullptr) {
            ImGui::ColorConvertHSVtoRGB(_cp::hue, _cp::sat, _cp::val,
                _cp::editing_color->x, _cp::editing_color->y, _cp::editing_color->z);
            _cp::editing_color->w = _cp::alpha;
            _cp::MarkChanged();
        }
    }
    float cursor_x = sv_pos.x + _cp::sat * sv_size;
    float cursor_y = sv_pos.y + (1.0f - _cp::val) * sv_size;
    fdl->AddCircleFilled(ImVec2(cursor_x, cursor_y), 4.0f, IM_COL32(255, 255, 255, 255), 12);
    fdl->AddCircle(ImVec2(cursor_x, cursor_y), 4.0f, IM_COL32(0, 0, 0, 255), 12, 1.5f);
    ImVec2 hue_pos = ImVec2(sv_end.x + gap, sv_pos.y);
    ImVec2 hue_end = ImVec2(hue_pos.x + hue_w, sv_end.y);
    for (int i = 0; i < 6; i++) {
        float y0 = hue_pos.y + (sv_size / 6.0f) * i;
        float y1 = hue_pos.y + (sv_size / 6.0f) * (i + 1);
        ImVec4 c0, c1;
        ImGui::ColorConvertHSVtoRGB(i / 6.0f, 1.0f, 1.0f, c0.x, c0.y, c0.z);
        ImGui::ColorConvertHSVtoRGB((i + 1) / 6.0f, 1.0f, 1.0f, c1.x, c1.y, c1.z);
        ImU32 col0 = ImGui::ColorConvertFloat4ToU32(ImVec4(c0.x, c0.y, c0.z, 1.0f));
        ImU32 col1 = ImGui::ColorConvertFloat4ToU32(ImVec4(c1.x, c1.y, c1.z, 1.0f));
        fdl->AddRectFilledMultiColor(
            ImVec2(hue_pos.x, y0), ImVec2(hue_end.x, y1),
            col0, col0, col1, col1);
    }
    bool hue_hov = (mouse.x >= hue_pos.x && mouse.x <= hue_end.x &&
                    mouse.y >= hue_pos.y && mouse.y <= hue_end.y);
    if (mouse_clicked && hue_hov) {
        _cp::dragging_inside = true;
        _cp::dragging_part = 2;
    }
    if ((hue_hov && mouse_down) || _cp::dragging_part == 2) {
        _cp::hue = ImClamp((mouse.y - hue_pos.y) / sv_size, 0.0f, 1.0f);
        if (_cp::editing_color != nullptr) {
            ImGui::ColorConvertHSVtoRGB(_cp::hue, _cp::sat, _cp::val,
                _cp::editing_color->x, _cp::editing_color->y, _cp::editing_color->z);
            _cp::editing_color->w = _cp::alpha;
            _cp::MarkChanged();
        }
    }
    float hue_cursor_y = hue_pos.y + _cp::hue * sv_size;
    fdl->AddRectFilled(
        ImVec2(hue_pos.x - 2, hue_cursor_y - 2),
        ImVec2(hue_end.x + 2, hue_cursor_y + 2),
        IM_COL32(255, 255, 255, 255), 1.0f);
    fdl->AddRect(
        ImVec2(hue_pos.x - 2, hue_cursor_y - 2),
        ImVec2(hue_end.x + 2, hue_cursor_y + 2),
        IM_COL32(0, 0, 0, 255), 1.0f, 0, 1.5f);
    ImVec2 alpha_pos = ImVec2(sv_pos.x, sv_end.y + gap);
    ImVec2 alpha_end = ImVec2(sv_end.x, alpha_pos.y + alpha_h);
    ImVec4 current_rgb;
    ImGui::ColorConvertHSVtoRGB(_cp::hue, _cp::sat, _cp::val, current_rgb.x, current_rgb.y, current_rgb.z);
    ImU32 col_opaque = ImGui::ColorConvertFloat4ToU32(ImVec4(current_rgb.x, current_rgb.y, current_rgb.z, 1.0f));
    ImU32 col_transparent = ImGui::ColorConvertFloat4ToU32(ImVec4(current_rgb.x, current_rgb.y, current_rgb.z, 0.0f));
    fdl->AddRectFilledMultiColor(alpha_pos, alpha_end,
        col_transparent, col_opaque,
        col_opaque, col_transparent);
    bool alpha_hov = (mouse.x >= alpha_pos.x && mouse.x <= alpha_end.x &&
                      mouse.y >= alpha_pos.y && mouse.y <= alpha_end.y);
    const float alpha_w = alpha_end.x - alpha_pos.x;
    if (mouse_clicked && alpha_hov) {
        _cp::dragging_inside = true;
        _cp::dragging_part = 3;
    }
    if ((alpha_hov && mouse_down) || _cp::dragging_part == 3) {
        _cp::alpha = ImClamp((mouse.x - alpha_pos.x) / alpha_w, 0.0f, 1.0f);
        if (_cp::editing_color != nullptr) {
            _cp::editing_color->w = _cp::alpha;
            _cp::MarkChanged();
        }
    }
    float alpha_cursor_x = alpha_pos.x + _cp::alpha * alpha_w;
    fdl->AddRectFilled(
        ImVec2(alpha_cursor_x - 2, alpha_pos.y - 2),
        ImVec2(alpha_cursor_x + 2, alpha_end.y + 2),
        IM_COL32(255, 255, 255, 255), 1.0f);
    fdl->AddRect(
        ImVec2(alpha_cursor_x - 2, alpha_pos.y - 2),
        ImVec2(alpha_cursor_x + 2, alpha_end.y + 2),
        IM_COL32(0, 0, 0, 255), 1.0f, 0, 1.5f);
}
}
