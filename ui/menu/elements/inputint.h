#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
namespace UI {
namespace _ii {
    inline ImGuiID focused_id = 0;
    inline std::unordered_map<ImGuiID, std::string> buffers;
}
inline bool InputInt(const char* id, int* value, float w, float h = 23.0f) {
    ImDrawList* dl    = ImGui::GetWindowDrawList();
    ImVec2      pos   = ImGui::GetCursorScreenPos();
    ImGuiID     my_id = ImGui::GetID(id);
    ImVec2      p1    = ImVec2(pos.x + w, pos.y + h);
    ImGui::InvisibleButton(id, ImVec2(w, h));
    bool hov     = ImGui::IsItemHovered();
    bool clicked = ImGui::IsItemClicked() && !UI::IsOpenColorPickerBlocking();
    auto& buf = _ii::buffers[my_id];
    if (clicked) {
        if (_ii::focused_id != my_id)
            buf = std::to_string(*value);
        _ii::focused_id = my_id;
    }
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !hov && _ii::focused_id == my_id && !UI::IsOpenColorPickerBlocking()) {
        *value = atoi(buf.c_str());
        _ii::focused_id = 0;
    }
    bool focused = (_ii::focused_id == my_id);
    bool changed = false;
    if (focused) {
        ImGuiIO& io = ImGui::GetIO();
        io.WantCaptureKeyboard = true;
        io.WantTextInput = true;
        if (ImGui::IsKeyPressed(ImGuiKey_Backspace) && !buf.empty()) {
            buf.pop_back();
            changed = true;
        }
        if (ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter)) {
            *value = atoi(buf.c_str());
            _ii::focused_id = 0;
            changed = true;
        }
        for (int i = 0; i < io.InputQueueCharacters.Size; i++) {
            ImWchar c = io.InputQueueCharacters[i];
            if (buf.size() >= 31) continue;
            if (c == '-' && buf.empty()) {
                buf += (char)c;
                changed = true;
            } else if (c >= '0' && c <= '9') {
                buf += (char)c;
                changed = true;
            }
        }
        if (changed) {
            io.InputQueueCharacters.resize(0);
            if (!buf.empty())
                *value = atoi(buf.c_str());
        }
    }
    dl->AddRectFilled(pos, p1, Colors::InputBg, 0.0f);
    ImU32 bord = focused ? Colors::Accent : Colors::CbBorder;
    dl->AddRect(pos, p1, bord, 0.0f, 0, 1.0f);
    const char* display = focused ? buf.c_str() : "";
    std::string display_str;
    if (!focused) {
        display_str = std::to_string(*value);
        display = display_str.c_str();
    }
    float ty = pos.y + (h - ImGui::GetTextLineHeight()) * 0.5f;
    dl->PushClipRect(ImVec2(pos.x + 4.0f, pos.y), ImVec2(p1.x - 4.0f, p1.y), true);
    dl->AddText(ImVec2(pos.x + 6.0f, ty), Colors::Text, display);
    if (focused && (int)(ImGui::GetTime() * 2.0) % 2 == 0) {
        ImVec2 ts = ImGui::CalcTextSize(display);
        float  cx = pos.x + 6.0f + ts.x + 1.0f;
        dl->AddLine(ImVec2(cx, ty), ImVec2(cx, ty + ImGui::GetTextLineHeight()),
                    Colors::Text, 1.0f);
    }
    if (_ii::buffers.size() > 64)
        _ii::buffers.clear();
    dl->PopClipRect();
    return changed;
}
}
