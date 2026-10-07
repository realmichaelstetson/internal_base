#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
#include "bind.h"
#include <unordered_map>
#include <string>

extern float g_menu_alpha;

namespace UI {
inline bool Checkbox(const char* label, bool* v,
                     const char* bind_id        = nullptr,
                     const char* default_bind   = nullptr,
                     float       col_w          = -1.f,
                     ImU32       label_color    = IM_COL32(0, 0, 0, 0),
                     ImU32       label_color_off = IM_COL32(0, 0, 0, 0)) {
    ImDrawList* dl    = ImGui::GetWindowDrawList();
    ImVec2      pos   = ImGui::GetCursorScreenPos();
    float       width = (col_w > 0.f) ? col_w : ImGui::GetContentRegionAvail().x;
    const float row_h = 28.0f;
    const float cb    = 20.0f;
    if (bind_id) UI::InitBind(bind_id, default_bind);
    float bind_w = 0.f;
    if (bind_id) {
        const char* bd = UI::GetBindDisplay(bind_id);
        bind_w = ImGui::CalcTextSize(bd).x + 6.f;
    }
    float cb_row_w = width - bind_w;
    ImGui::SetCursorScreenPos(pos);
    ImGui::InvisibleButton(label, ImVec2(cb_row_w, row_h));
    bool clicked = ImGui::IsItemClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking();
    if (clicked) *v = !(*v);
    
    // Анимация чекбокса
    static std::unordered_map<std::string, float> anim_map;
    std::string anim_key = std::string("cb_") + label;
    float& anim = anim_map[anim_key];
    float target = *v ? 1.0f : 0.0f;
    float speed = 8.0f;
    anim += (target - anim) * ImGui::GetIO().DeltaTime * speed;
    anim = ImClamp(anim, 0.0f, 1.0f);
    
    ImVec2 cp0 = ImVec2(pos.x + 5.0f, pos.y + (row_h - cb) * 0.5f);
    ImVec2 cp1 = ImVec2(cp0.x + cb, cp0.y + cb);
    auto FadeCol = [&](ImU32 col) -> ImU32 {
        int a = (int)(((col >> 24) & 0xFF) * g_menu_alpha);
        return (col & 0x00FFFFFF) | ((ImU32)a << 24);
    };
    
    // Интерполяция цветов на основе анимации
    auto LerpColor = [](ImU32 col1, ImU32 col2, float t) -> ImU32 {
        int r1 = (col1 >> 0)  & 0xFF;
        int g1 = (col1 >> 8)  & 0xFF;
        int b1 = (col1 >> 16) & 0xFF;
        int a1 = (col1 >> 24) & 0xFF;
        int r2 = (col2 >> 0)  & 0xFF;
        int g2 = (col2 >> 8)  & 0xFF;
        int b2 = (col2 >> 16) & 0xFF;
        int a2 = (col2 >> 24) & 0xFF;
        int r = (int)(r1 + (r2 - r1) * t);
        int g = (int)(g1 + (g2 - g1) * t);
        int b = (int)(b1 + (b2 - b1) * t);
        int a = (int)(a1 + (a2 - a1) * t);
        return IM_COL32(r, g, b, a);
    };
    
    // Используем accent color для включенного состояния
    ImVec4 accent_vec = ImGui::ColorConvertU32ToFloat4(Colors::Accent);
    ImU32 accent_color = IM_COL32(
        (int)(accent_vec.x * 255),
        (int)(accent_vec.y * 255),
        (int)(accent_vec.z * 255),
        255
    );
    
    ImU32 box_col = FadeCol(LerpColor(IM_COL32(24, 24, 24, 255), accent_color, anim));
    ImU32 box_border = FadeCol(LerpColor(IM_COL32(38, 38, 38, 255), accent_color, anim));
    dl->AddRectFilled(cp0, cp1, box_col, 5.0f);
    dl->AddRect(cp0, cp1, box_border, 5.0f, 0, 1.0f);
    
    if (anim > 0.01f) {
        // Рисуем иконку FontAwesome CHECK вместо галочки с учетом анимации
        ImFont* font = ImGui::GetFont();
        const char* check_icon = "\xef\x80\x8c"; // ICON_FA_CHECK
        ImVec2 icon_size = font->CalcTextSizeA(font->FontSize * 0.7f, FLT_MAX, 0.0f, check_icon);
        ImVec2 icon_pos = ImVec2(cp0.x + (cb - icon_size.x) * 0.5f, 
                                  cp0.y + (cb - icon_size.y) * 0.5f);
        ImU32 check_color = FadeCol(IM_COL32(255, 255, 255, (int)(255 * anim)));
        dl->AddText(font, font->FontSize * 0.7f, icon_pos, check_color, check_icon);
    }
    float tly = pos.y + (row_h - ImGui::GetTextLineHeight()) * 0.5f;
    ImVec2 text_min = ImVec2(pos.x + cb + 13.0f, tly);
    ImVec2 text_max = ImVec2(pos.x + cb_row_w - 4.0f, pos.y + row_h);
    ImU32 final_color;
    if (label_color != IM_COL32(0, 0, 0, 0) && label_color_off != IM_COL32(0, 0, 0, 0)) {
        final_color = FadeCol(LerpColor(label_color_off, label_color, anim));
    } else if (label_color != IM_COL32(0, 0, 0, 0)) {
        final_color = FadeCol(LerpColor(label_color, Colors::TextBright, anim));
    } else {
        final_color = FadeCol(LerpColor(Colors::Text, Colors::TextBright, anim));
    }
    dl->PushClipRect(text_min, text_max, true);
    dl->AddText(text_min, final_color, label);
    dl->PopClipRect();
    if (bind_id) {
        bool    waiting  = UI::IsBindWaiting(bind_id);
        const char* bd   = UI::GetBindDisplay(bind_id);
        ImVec2  bts      = ImGui::CalcTextSize(bd);
        float   bx       = pos.x + width - bts.x;
        std::string btn_id = std::string("##bnd_") + bind_id;
        ImGui::SetCursorScreenPos(ImVec2(bx - 3.f, pos.y));
        ImGui::InvisibleButton(btn_id.c_str(), ImVec2(bts.x + 6.f, row_h));
        bool bclicked = ImGui::IsItemClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking();
        bool brclicked = ImGui::IsItemClicked(ImGuiMouseButton_Right) && !UI::IsOpenColorPickerBlocking();
        if (bclicked) {
            if (waiting) UI::g_binds[bind_id].waiting = false;
            else         UI::StartBindWaiting(bind_id);
        }
        if (brclicked) {
            UI::_bm::popup_id   = bind_id;
            UI::_bm::popup_pos  = ImVec2(bx - 3.f, pos.y + row_h + 2.0f);
            UI::_bm::popup_open = true;
        }
        static std::unordered_map<std::string, float> pulse;
        float& ph = pulse[bind_id];
        if (waiting) ph = fmodf(ph + ImGui::GetIO().DeltaTime * 3.f, 6.2832f);
        ImVec4 acc4 = ImGui::ColorConvertU32ToFloat4(Colors::Accent);
        ImU32 bc = FadeCol(waiting
            ? ImGui::ColorConvertFloat4ToU32(ImVec4(acc4.x, acc4.y, acc4.z, 0.55f + 0.45f * sinf(ph)))
            : Colors::TextBind);
        dl->AddText(ImVec2(bx, tly), bc, bd);
    }
    ImGui::SetCursorScreenPos(ImVec2(pos.x, pos.y + row_h));
    return clicked;
}
}
