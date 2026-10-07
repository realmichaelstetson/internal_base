#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
#include <cstring>
namespace UI {
namespace _ti {
    inline ImGuiID focused_id = 0;
}
// block_chars: optional set of ASCII characters that are silently rejected as
// the user types (e.g. characters that are illegal in Windows file names).
inline bool TextInput(const char* id, char* buf, int buf_size, float w, float h = 23.0f, const char* placeholder = "...", const char* block_chars = nullptr) {
    ImDrawList* dl    = ImGui::GetWindowDrawList();
    ImVec2      pos   = ImGui::GetCursorScreenPos();
    ImGuiID     my_id = ImGui::GetID(id);
    ImVec2      p1    = ImVec2(pos.x + w, pos.y + h);
    ImGui::InvisibleButton(id, ImVec2(w, h));
    bool hov     = ImGui::IsItemHovered();
    bool clicked = ImGui::IsItemClicked() && !UI::IsOpenColorPickerBlocking();
    if (clicked)
        _ti::focused_id = my_id;
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !hov && _ti::focused_id == my_id && !UI::IsOpenColorPickerBlocking())
        _ti::focused_id = 0;
    bool focused = (_ti::focused_id == my_id);
    bool changed = false;
    if (focused) {
        ImGuiIO& io = ImGui::GetIO();
        io.WantCaptureKeyboard = true;
        io.WantTextInput = true;
        int len = (int)strlen(buf);
        if (ImGui::IsKeyPressed(ImGuiKey_Backspace) && len > 0) {
            buf[--len] = '\0';
            changed = true;
        }
        for (int i = 0; i < io.InputQueueCharacters.Size; i++) {
            ImWchar c = io.InputQueueCharacters[i];
            if (c < 32 || c == 127 || len >= buf_size - 1) continue;
            if (block_chars && c < 0x80 && std::strchr(block_chars, (char)c)) continue;
            if (c < 0x80) {
                buf[len++] = (char)c;
            } else if (c < 0x800 && len + 1 < buf_size - 1) {
                buf[len++] = (char)(0xC0 | (c >> 6));
                buf[len++] = (char)(0x80 | (c & 0x3F));
            } else if (c < 0x10000 && len + 2 < buf_size - 1) {
                buf[len++] = (char)(0xE0 | (c >> 12));
                buf[len++] = (char)(0x80 | ((c >> 6) & 0x3F));
                buf[len++] = (char)(0x80 | (c & 0x3F));
            }
            buf[len]   = '\0';
            changed    = true;
        }
        if (changed) io.InputQueueCharacters.resize(0);
    }
    dl->AddRectFilled(pos, p1, Colors::InputBg, 0.0f);
    ImU32 bord = focused ? Colors::Accent : Colors::CbBorder;
    dl->AddRect(pos, p1, bord, 0.0f, 0, 1.0f);
    int   len  = (int)strlen(buf);
    float ty   = pos.y + (h - ImGui::GetTextLineHeight()) * 0.5f;
    const ImVec2 text_clip_min(pos.x + 4.0f, pos.y);
    const ImVec2 text_clip_max(p1.x - 4.0f, p1.y);
    dl->PushClipRect(text_clip_min, text_clip_max, true);
    if (len > 0)
        dl->AddText(ImVec2(pos.x + 6.0f, ty), Colors::Text, buf);
    else if (!focused)
        dl->AddText(ImVec2(pos.x + 6.0f, ty), Colors::TextDim, placeholder ? placeholder : "...");
    if (focused && (int)(ImGui::GetTime() * 2.0) % 2 == 0) {
        ImVec2 ts = ImGui::CalcTextSize(buf, buf + len);
        float  cx = pos.x + 6.0f + ts.x + 1.0f;
        dl->AddLine(ImVec2(cx, ty), ImVec2(cx, ty + ImGui::GetTextLineHeight()),
                    Colors::Text, 1.0f);
    }
    dl->PopClipRect();
    return changed;
}
}
