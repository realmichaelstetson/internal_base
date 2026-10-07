#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
namespace UI {
inline bool Button(const char* label, float w = 140.0f, float h = 23.0f) {
    ImDrawList* dl  = ImGui::GetWindowDrawList();
    ImVec2      pos = ImGui::GetCursorScreenPos();
    ImVec2      p1  = ImVec2(pos.x + w, pos.y + h);
    ImGui::InvisibleButton(label, ImVec2(w, h));
    bool held    = ImGui::IsItemActive();
    bool clicked = ImGui::IsItemClicked() && !UI::IsOpenColorPickerBlocking();
    ImU32 col_top, col_bot;
    if (held) {
        col_top = Colors::ButtonHeldTop;
        col_bot = Colors::ButtonHeldBot;
    } else {
        col_top = Colors::ButtonBgTop;
        col_bot = Colors::ButtonBgBot;
    }
    dl->AddRectFilled(pos, p1, col_top, 0.0f);
    dl->AddRectFilledMultiColor(pos, p1, col_top, col_top, col_bot, col_bot);
    dl->AddRect(pos, p1, Colors::ButtonBorder, 0.0f, 0, 1.0f);
    ImVec2 ts = ImGui::CalcTextSize(label);
    float  tx = pos.x + (w - ts.x) * 0.5f;
    float  ty = pos.y + (h - ts.y) * 0.5f;
    dl->PushClipRect(ImVec2(pos.x + 4.0f, pos.y), ImVec2(p1.x - 4.0f, p1.y), true);
    dl->AddText(ImVec2(tx, ty), Colors::Text, label);
    dl->PopClipRect();
    return clicked;
}
}
