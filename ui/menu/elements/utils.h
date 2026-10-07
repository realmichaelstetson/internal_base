#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "colors.h"
namespace UI {
inline void DrawGradientLine(ImDrawList* dl, float x, float y, float width,
                              float height = 1.0f, ImU32 col = Colors::Accent) {
    ImU32 zero = IM_COL32(0, 0, 0, 0);
    float cx1  = x + width * 0.3f;
    float cx2  = x + width * 0.7f;
    dl->AddRectFilledMultiColor(ImVec2(x,   y), ImVec2(cx1,        y + height), zero, col,  col,  zero);
    dl->AddRectFilledMultiColor(ImVec2(cx1,  y), ImVec2(cx2,        y + height), col,  col,  col,  col);
    dl->AddRectFilledMultiColor(ImVec2(cx2,  y), ImVec2(x + width, y + height), col,  zero, zero, col);
}
}
