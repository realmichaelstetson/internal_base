#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
#include <cstdio>
#include <cmath>
#include <string>
namespace UI {

inline bool SliderFloat(const char* label, float* v, float vmin, float vmax,
                        const char* suffix = "", const char* fmt = "%.0f",
                        float col_w = -1.f) {
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 pos = ImGui::GetCursorScreenPos();
    float avail = (col_w > 0.f) ? col_w : ImGui::GetContentRegionAvail().x;

    const float lh = ImGui::GetTextLineHeight();
    const float track_h = 5.0f;
    const float track_r = 25.0f;
    const float knob_w_base = 18.0f;
    const float knob_h_base = 12.0f;
    const float knob_r = 20.0f;
    const float pad = 4.0f;
    const float spacing = 6.0f;

    const char* label_end = ImGui::FindRenderedTextEnd(label);
    const bool has_label = label_end > label;

    char buf[32], full[48];
    snprintf(buf, sizeof(buf), fmt, *v);
    snprintf(full, sizeof(full), "%s%s", buf, suffix);
    ImVec2 vs = ImGui::CalcTextSize(full);

    float label_w = 0.0f;
    if (has_label)
        label_w = ImGui::CalcTextSize(label, label_end).x;

    float row1_h = lh;
    float track_y = pos.y + row1_h + spacing;
    float total_h = row1_h + spacing + track_h + pad;

    if (has_label) {
        ImU32 lc = (*v > vmin) ? Colors::TextBright : Colors::Text;
        dl->AddText(ImVec2(pos.x, pos.y + (row1_h - lh) * 0.5f), lc, label, label_end);
    }

    dl->AddText(ImVec2(pos.x + avail - vs.x, pos.y + (row1_h - vs.y) * 0.5f),
                Colors::TextBright, full);

    const float knob_safe_pad = knob_w_base * 0.5f + 1.0f;
    float track_left = pos.x + knob_safe_pad;
    float track_right = pos.x + avail - knob_safe_pad;
    float tw = ImMax(track_right - track_left, 20.0f);

    std::string id = std::string("##sl") + label;
    ImGui::SetCursorScreenPos(ImVec2(track_left, track_y - knob_h_base * 0.575f));
    ImGui::InvisibleButton(id.c_str(), ImVec2(tw, knob_h_base * 1.15f + track_h));
    bool held = ImGui::IsItemActive() && !UI::IsOpenColorPickerBlocking();
    bool changed = false;

    if (held) {
        float mx = ImGui::GetIO().MousePos.x;
        float t = ImClamp((mx - track_left) / tw, 0.0f, 1.0f);
        float nv = vmin + t * (vmax - vmin);
        if (fabsf(nv - *v) > 1e-5f) { *v = nv; changed = true; }
    }

    float t = (vmax > vmin) ? ImClamp((*v - vmin) / (vmax - vmin), 0.0f, 1.0f) : 0.0f;

    ImVec2 t0 = ImVec2(track_left, track_y);
    ImVec2 t1 = ImVec2(track_left + tw, track_y + track_h);
    dl->AddRectFilled(t0, t1, Colors::SliderTrack, track_r);

    if (t > 0.001f) {
        ImVec2 f0 = t0;
        ImVec2 f1 = ImVec2(t0.x + t * tw, t1.y);
        dl->PushClipRect(f0, f1, true);
        dl->AddRectFilled(t0, t1, IM_COL32(245, 245, 245, 255), track_r);
        dl->PopClipRect();
    }

    float knob_x = track_left + t * tw;
    float knob_y = track_y + track_h * 0.5f;
    static float knob_scale = 1.0f;
    float knob_target = held ? 1.15f : 1.0f;
    knob_scale += (knob_target - knob_scale) * ImMin(1.0f, ImGui::GetIO().DeltaTime * 12.0f);
    float kw = knob_w_base * knob_scale;
    float kh = knob_h_base * knob_scale;
    ImVec2 k0 = ImVec2(knob_x - kw * 0.5f, knob_y - kh * 0.5f);
    ImVec2 k1 = ImVec2(knob_x + kw * 0.5f, knob_y + kh * 0.5f);
    ImU32 knob_col = held ? IM_COL32(255, 255, 255, 255) : IM_COL32(230, 230, 230, 255);
    dl->AddRectFilled(k0, k1, knob_col, knob_r);
    dl->AddRect(k0, k1, IM_COL32(0, 0, 0, 40), knob_r, 0, 1.0f);

    ImGui::SetCursorScreenPos(ImVec2(pos.x, pos.y + total_h));
    return changed;
}
}
