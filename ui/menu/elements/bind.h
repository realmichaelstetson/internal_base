#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colorpicker.h"
#include <string>
#include <unordered_map>
#include <cctype>

namespace {
	int vk_from_bind_name(const std::string& key) {
		if (key == "M1") return VK_LBUTTON;
		if (key == "M2") return VK_RBUTTON;
		if (key == "M3") return VK_MBUTTON;
		if (key == "M4") return VK_XBUTTON1;
		if (key == "M5") return VK_XBUTTON2;
		if (key == "ALT") return VK_MENU;
		if (key == "CTRL") return VK_CONTROL;
		if (key == "SHIFT") return VK_SHIFT;
		if (key == "WIN") return VK_LWIN;
		if (key == "DEL") return VK_DELETE;
		if (key == "INS") return VK_INSERT;
		if (key == "SPACE") return VK_SPACE;
		if (key == "TAB") return VK_TAB;
		if (key == "ENTER") return VK_RETURN;
		if (key == "BACKSPACE") return VK_BACK;
		if (key == "HOME") return VK_HOME;
		if (key == "END") return VK_END;
		if (key == "PGUP") return VK_PRIOR;
		if (key == "PGDN") return VK_NEXT;
		if (key.size() == 1 && ((key[0] >= 'A' && key[0] <= 'Z') || (key[0] >= '0' && key[0] <= '9')))
			return key[0];
		if (key.size() >= 2 && key[0] == 'F') {
			int n = std::atoi(key.c_str() + 1);
			if (n >= 1 && n <= 24) return VK_F1 + n - 1;
		}
		return 0;
	}

	bool is_key_down_native(const std::string& key) {
		int vk = vk_from_bind_name(key);
		return vk != 0 && (GetAsyncKeyState(vk) & 0x8000) != 0;
	}

	bool& key_prev_state(const std::string& key) {
		static std::unordered_map<std::string, bool> prev;
		return prev[key];
	}

	bool is_key_pressed_native(const std::string& key) {
		bool down = is_key_down_native(key);
		bool was = key_prev_state(key);
		key_prev_state(key) = down;
		return down && !was;
	}
}
namespace UI {
enum class BindMode { AlwaysOn = 0, Hold = 1, Toggle = 2 };
struct BindEntry {
    std::string key;
    BindMode    mode        = BindMode::AlwaysOn;
    bool        waiting     = false;
    int         start_frame = -1;
    bool        toggled     = false;
};
inline std::unordered_map<std::string, BindEntry> g_binds;
namespace _bm {
    inline std::string  popup_id;
    inline ImVec2       popup_pos;
    inline bool         popup_open = false;
}
inline std::string NormalizeKeyName(std::string name) {
    if (name == "LeftAlt" || name == "RightAlt") name = "ALT";
    else if (name == "LeftCtrl" || name == "RightCtrl") name = "CTRL";
    else if (name == "LeftShift" || name == "RightShift") name = "SHIFT";
    else if (name == "LeftSuper" || name == "RightSuper") name = "WIN";
    else if (name == "MouseLeft") name = "M1";
    else if (name == "MouseRight") name = "M2";
    else if (name == "MouseMiddle") name = "M3";
    else {
        for (auto& c : name) c = (char)toupper((unsigned char)c);
        if (name == "DELETE") name = "DEL";
        else if (name == "INSERT") name = "INS";
        else if (name == "PAGEUP") name = "PGUP";
        else if (name == "PAGEDOWN") name = "PGDN";
    }
    return name;
}
inline void InitBind(const char* id, const char* default_key) {
    if (g_binds.find(id) == g_binds.end())
        g_binds[id] = { default_key ? default_key : "", BindMode::AlwaysOn, false, -1, false };
}
inline bool IsAnyBindWaiting() {
    for (auto& [id, e] : g_binds) if (e.waiting) return true;
    return false;
}
inline bool IsBindWaiting(const char* id) {
    auto it = g_binds.find(id);
    return it != g_binds.end() && it->second.waiting;
}
inline void StartBindWaiting(const char* id) {
    for (auto& [bid, e] : g_binds) e.waiting = false;
    auto it = g_binds.find(id);
    if (it != g_binds.end()) {
        it->second.waiting     = true;
        it->second.start_frame = ImGui::GetFrameCount();
    }
}
inline const char* GetBindDisplay(const char* id) {
    static char buf[64];
    auto it = g_binds.find(id);
    if (it == g_binds.end()) return "[none]";
    if (it->second.waiting)  return "press key";
    if (it->second.key.empty()) return "[none]";
    snprintf(buf, sizeof(buf), "[%s]", it->second.key.c_str());
    return buf;
}
inline ImGuiKey KeyFromBindName(const std::string& key) {
    if (key.empty()) return ImGuiKey_None;
    static std::unordered_map<std::string, ImGuiKey> key_map;
    if (key_map.empty()) {
        for (int i = (int)ImGuiKey_NamedKey_BEGIN; i < (int)ImGuiKey_NamedKey_END; ++i) {
            auto k = (ImGuiKey)i;
            key_map[NormalizeKeyName(ImGui::GetKeyName(k))] = k;
        }
    }
    auto it = key_map.find(key);
    return it != key_map.end() ? it->second : ImGuiKey_None;
}

inline bool IsBindActive(const char* id) {
    auto it = g_binds.find(id);
    if (it == g_binds.end()) return false;
    auto& e = it->second;
    if (e.key.empty()) return false;
    switch (e.mode) {
    case BindMode::AlwaysOn: return true;
    case BindMode::Hold: return is_key_down_native(e.key);
    case BindMode::Toggle: return e.toggled;
    }
    return false;
}
inline void UpdateBindCapture() {
    if (UI::IsOpenColorPickerBlocking())
        return;

    for (auto& [id, e] : g_binds) {
        if (e.mode == BindMode::Toggle && !e.waiting && !e.key.empty()) {
            if (is_key_pressed_native(e.key))
                e.toggled = !e.toggled;
        }
        if (!e.waiting) continue;
        if (ImGui::GetFrameCount() <= e.start_frame + 1) continue;
        ImGuiIO& io = ImGui::GetIO();
        if (ImGui::IsKeyPressed(ImGuiKey_Escape)) { e.key = ""; e.waiting = false; continue; }
        if (io.MouseClicked[0]) { e.key = "M1"; e.waiting = false; continue; }
        if (io.MouseClicked[1]) { e.key = "M2"; e.waiting = false; continue; }
        if (io.MouseClicked[2]) { e.key = "M3"; e.waiting = false; continue; }
        if (io.MouseClicked[3]) { e.key = "M4"; e.waiting = false; continue; }
        if (io.MouseClicked[4]) { e.key = "M5"; e.waiting = false; continue; }
        for (int k = (int)ImGuiKey_NamedKey_BEGIN; k < (int)ImGuiKey_NamedKey_END; ++k) {
            ImGuiKey key = (ImGuiKey)k;
            if (key == ImGuiKey_Escape) continue;
            if (!ImGui::IsKeyPressed(key)) continue;
            e.key     = NormalizeKeyName(ImGui::GetKeyName(key));
            e.waiting = false;
            break;
        }
    }
}
inline void RenderBindModePopup() {
    if (!_bm::popup_open) return;
    ImDrawList* fdl = ImGui::GetForegroundDrawList();
    ImVec2 p0 = _bm::popup_pos;
    const float item_h = 18.0f;
    const float w      = 80.0f;
    ImVec2 p1 = ImVec2(p0.x + w, p0.y + item_h * 3.0f + 4.0f);
    ImVec2 mouse = ImGui::GetIO().MousePos;
    bool inside = (mouse.x >= p0.x && mouse.x <= p1.x && mouse.y >= p0.y && mouse.y <= p1.y);
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !inside && !UI::IsOpenColorPickerBlocking()) {
        _bm::popup_open = false;
        return;
    }
    fdl->AddRectFilled(ImVec2(p0.x + 2, p0.y + 2), ImVec2(p1.x + 2, p1.y + 2), IM_COL32(0, 0, 0, 60), 3.0f);
    fdl->AddRectFilled(p0, p1, Colors::BindBg, 3.0f);
    fdl->AddRect(p0, p1, IM_COL32(30, 28, 36, 255), 3.0f, 0, 1.0f);
    auto& e = g_binds[_bm::popup_id];
    const char* labels[] = { "always on", "hold", "toggle" };
    BindMode    modes[]  = { BindMode::AlwaysOn, BindMode::Hold, BindMode::Toggle };
    for (int i = 0; i < 3; i++) {
        ImVec2 ip0 = ImVec2(p0.x + 1, p0.y + 2.0f + i * item_h);
        ImVec2 ip1 = ImVec2(p1.x - 1, ip0.y + item_h);
        bool hov_i = (mouse.x >= ip0.x && mouse.x <= ip1.x && mouse.y >= ip0.y && mouse.y <= ip1.y);
        bool sel_i = (e.mode == modes[i]);
        if (sel_i) fdl->AddRectFilled(ip0, ip1, Colors::BindItemBg, 2.0f);
        float lh = ImGui::GetTextLineHeight();
        float ty = ip0.y + (item_h - lh) * 0.5f;
        ImU32 tc = sel_i ? Colors::Accent : Colors::BindItemText;
        fdl->AddText(ImVec2(ip0.x + 8.0f, ty), tc, labels[i]);
        if (hov_i && ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking()) {
            e.mode = modes[i];
            _bm::popup_open = false;
        }
    }
}
}
