#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
#include "utils.h"
namespace UI {
inline int TabBar(const char** tabs, int count, int current,
                  ImVec2 pos, float width, float height,
                  bool suppress_click = false) {
    if (!tabs || count <= 0)
        return current;

    ImDrawList* fdl   = ImGui::GetWindowDrawList();
    ImVec2      mouse = ImGui::GetIO().MousePos;
    int         result = current;
    UI::DrawGradientLine(fdl, pos.x, pos.y, width, 1.5f);
    float tab_w = width / (float)count;

    const ImU32 separator_col = Colors::TabSeparator;
    const float separator_top = pos.y + 8.0f;
    const float separator_bottom = pos.y + height - 8.0f;

    for (int i = 0; i < count; i++) {
        ImVec2 tp0 = ImVec2(pos.x + (float)i * tab_w, pos.y);
        ImVec2 tp1 = ImVec2(tp0.x + tab_w, pos.y + height);
        bool hov    = (mouse.x >= tp0.x && mouse.x <= tp1.x &&
                       mouse.y >= tp0.y && mouse.y <= tp1.y);
        bool active = (i == current);
        if (!suppress_click && hov && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !UI::IsOpenDropdownHovered() && !UI::IsOpenColorPickerBlocking())
            result = i;
        ImVec2 ts  = ImGui::CalcTextSize(tabs[i]);
        ImVec2 ttp = ImVec2(tp0.x + (tab_w - ts.x) * 0.5f,
                            tp0.y + (height  - ts.y) * 0.5f);
        ImU32 tc = active ? Colors::TextBright : Colors::TextDim;
        fdl->AddText(ttp, tc, tabs[i]);

        if (i + 1 < count) {
            const float sep_x = tp1.x;
            fdl->AddLine(ImVec2(sep_x, separator_top), ImVec2(sep_x, separator_bottom), separator_col, 1.0f);
        }
    }
    return result;
}
}
