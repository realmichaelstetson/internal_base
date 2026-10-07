#pragma once
#include "../../../src/sdk/includes/imgui/imgui.h"
#include "../../../src/sdk/includes/imgui/imgui_internal.h"
#include "colors.h"
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
namespace UI {
namespace _dd {
    inline ImGuiID      open_id    = 0;
    inline int          open_frame = -1;
    inline ImVec2       open_pos   = {};
    inline float        open_w     = 0.f;
    inline const char** items      = nullptr;
    inline const ImU32* item_cols  = nullptr;
    inline int          count      = 0;
    inline int*         selected   = nullptr;
    inline int*         flags      = nullptr;
    inline int          disabled_mask = 0;
    inline bool         multi      = false;
    inline ImGuiID      changed_id = 0;
    inline bool         changed_pending = false;
    inline float        scroll_y   = 0.0f;
    inline float        scroll_target = 0.0f;
    inline float        open_anim  = 0.0f;
    inline bool         closing    = false;
    inline bool         dragging_scroll = false;
    inline float        drag_start_y    = 0.0f;
    inline float        drag_start_scroll = 0.0f;
    inline constexpr float item_h  = 18.0f;
    inline constexpr float max_popup_h = 220.0f;

    inline bool         searchable = false;
    inline char         search_buf[64] = {};
    inline int          search_len = 0;
    inline std::vector<int> filtered;
    inline constexpr float search_h = 22.0f;

    inline int UTF8Decode(const char*& str) {
        if (!str || !*str) return 0;
        unsigned char c0 = (unsigned char)*str;
        if (c0 < 0x80)                       { str += 1; return c0; }
        if ((c0 & 0xE0) == 0xC0 && str[1])     { int v = ((c0 & 0x1F) << 6) | ((unsigned char)str[1] & 0x3F); str += 2; return v; }
        if ((c0 & 0xF0) == 0xE0 && str[1] && str[2]) { int v = ((c0 & 0x0F) << 12) | (((unsigned char)str[1] & 0x3F) << 6) | ((unsigned char)str[2] & 0x3F); str += 3; return v; }
        str += 1;
        return c0;
    }
    inline int UTF8Encode(int cp, char* out) {
        if (cp < 0x80)       { out[0] = (char)cp; return 1; }
        if (cp < 0x800)      { out[0] = (char)(0xC0 | (cp >> 6)); out[1] = (char)(0x80 | (cp & 0x3F)); return 2; }
        if (cp < 0x10000)    { out[0] = (char)(0xE0 | (cp >> 12)); out[1] = (char)(0x80 | ((cp >> 6) & 0x3F)); out[2] = (char)(0x80 | (cp & 0x3F)); return 3; }
        out[0] = (char)(0xF0 | (cp >> 18)); out[1] = (char)(0x80 | ((cp >> 12) & 0x3F)); out[2] = (char)(0x80 | ((cp >> 6) & 0x3F)); out[3] = (char)(0x80 | (cp & 0x3F));
        return 4;
    }
    inline int ToLowerCP(int cp) {
        if (cp >= 0x41 && cp <= 0x5A) return cp + 32;
        if (cp >= 0xC0 && cp <= 0xD6) return cp + 32;
        if (cp >= 0xD8 && cp <= 0xDE) return cp + 32;
        if (cp >= 0x0410 && cp <= 0x042F) return cp + 32;
        if (cp == 0x0401) return 0x0451;
        return cp;
    }

    inline bool ContainsCI(const char* hay, const char* needle) {
        if (!needle || !needle[0]) return true;
        if (!hay) return false;
        for (const char* hp = hay; *hp; ) {
            const char* a = hp;
            const char* b = needle;
            bool matched = true;
            while (*a && *b) {
                int ca = UTF8Decode(a);
                int cb = UTF8Decode(b);
                if (ToLowerCP(ca) != ToLowerCP(cb)) { matched = false; break; }
            }
            if (matched && !*b) return true;
            UTF8Decode(hp);
        }
        return false;
    }

    inline void RebuildFiltered() {
        filtered.clear();
        if (!items || count <= 0) return;
        filtered.reserve(count);
        for (int i = 0; i < count; i++)
            if (search_len == 0 || ContainsCI(items[i], search_buf))
                filtered.push_back(i);
    }

    inline void ClearSearch() {
        search_len = 0;
        search_buf[0] = '\0';
        filtered.clear();
    }

    inline int VisibleCount() {
        return searchable ? (int)filtered.size() : ImMax(count, 0);
    }

    inline int OrigIndex(int v) {
        if (!searchable) return v;
        return (v >= 0 && v < (int)filtered.size()) ? filtered[v] : 0;
    }

    inline float ContentHeight() {
        float min_h = (searchable && VisibleCount() == 0) ? 100.0f : 4.0f;
        return ImMax(min_h, (float)ImMax(VisibleCount(), 0) * item_h + 4.0f);
    }

    inline float OpenHeight() {
        return ImMin(ContentHeight(), max_popup_h);
    }

    inline float PopupHeight() {
        return OpenHeight() + (searchable ? search_h : 0.0f);
    }

    inline const char* ItemText(int idx) {
        return (items && idx >= 0 && idx < count && items[idx]) ? items[idx] : "";
    }

    inline void Close() {
        open_id = 0;
        open_frame = -1;
        items = nullptr;
        item_cols = nullptr;
        count = 0;
        selected = nullptr;
        flags = nullptr;
        disabled_mask = 0;
        multi = false;
        scroll_y = 0.0f;
        scroll_target = 0.0f;
        open_anim = 0.0f;
        closing = false;
        dragging_scroll = false;
        searchable = false;
        ClearSearch();
    }

    inline void BeginClose() {
        if (open_id != 0)
            closing = true;
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

    inline void ClampOpenPos() {
        ImGuiIO& io = ImGui::GetIO();
        if (io.DisplaySize.x <= 0.0f || io.DisplaySize.y <= 0.0f)
            return;
        const float margin = 4.0f;
        const float h = PopupHeight();
        open_w = ImMax(open_w, 20.0f);
        open_pos.x = ImClamp(open_pos.x, margin, ImMax(margin, io.DisplaySize.x - open_w - margin));
        open_pos.y = ImClamp(open_pos.y, margin, ImMax(margin, io.DisplaySize.y - h - margin));
        const float list_h = OpenHeight();
        const float max_s = ImMax(0.0f, ContentHeight() - list_h);
        scroll_y = ImClamp(scroll_y, 0.0f, max_s);
        scroll_target = ImClamp(scroll_target, 0.0f, max_s);
    }
}

inline bool IsOpenDropdownHovered() {
    if (_dd::open_id == 0) return false;
    ImVec2 mouse = ImGui::GetIO().MousePos;
    ImVec2 p0 = _dd::open_pos;
    ImVec2 p1 = ImVec2(p0.x + _dd::open_w, p0.y + _dd::PopupHeight());
    return mouse.x >= p0.x && mouse.x <= p1.x &&
           mouse.y >= p0.y && mouse.y <= p1.y;
}

inline bool Dropdown(const char* label, int* sel, const char** items, int count, float col_w = -1.f, const ImU32* item_cols = nullptr, bool searchable = false) {
    if (!sel || !items || count <= 0) return false;
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 pos = ImGui::GetCursorScreenPos();
    const float h = 24.0f;
    const float container_w = (col_w > 0.f) ? col_w : ImGui::GetContentRegionAvail().x;
    constexpr float btn_w = 140.0f;
    const float w = ImMin(btn_w, container_w);
    const float x_off = (container_w - w) * 0.5f;
    pos.x += x_off;
    const bool valid = (sel && items && count > 0);
    if (valid) *sel = ImClamp(*sel, 0, count - 1);

    ImGui::SetCursorScreenPos(pos);
    ImGui::InvisibleButton(label, ImVec2(w, h));
    bool clicked = ImGui::IsItemClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking();
    ImGuiID my_id = ImGui::GetID(label);
    bool changed = _dd::ConsumeChanged(my_id);
    if (clicked) {
        if (_dd::open_id == my_id && !_dd::closing) {
            _dd::BeginClose();
        } else if (valid) {
            bool reopen = (_dd::open_id == my_id);
            _dd::open_id = my_id;
            _dd::open_frame = ImGui::GetFrameCount();
            _dd::open_pos = ImVec2(pos.x, pos.y + h);
            _dd::open_w = w;
            _dd::items = items;
            _dd::item_cols = item_cols;
            _dd::count = count;
            _dd::selected = sel;
            _dd::flags = nullptr;
            _dd::disabled_mask = 0;
            _dd::multi = false;
            _dd::closing = false;
            _dd::searchable = searchable;
            if (!reopen) {
                _dd::scroll_y = 0.0f;
                _dd::scroll_target = 0.0f;
                _dd::open_anim = 0.0f;
                _dd::ClearSearch();
            }
            _dd::RebuildFiltered();
            _dd::ClampOpenPos();
        }
    }
    bool is_open = (_dd::open_id == my_id);
    if (is_open) {
        _dd::open_pos = ImVec2(pos.x, pos.y + h);
        _dd::open_w = w;
        _dd::items = items;
        _dd::item_cols = item_cols;
        _dd::count = count;
        _dd::selected = sel;
        _dd::flags = nullptr;
        _dd::disabled_mask = 0;
        _dd::multi = false;
        _dd::searchable = searchable;
        if (!valid) _dd::Close();
        else _dd::ClampOpenPos();
        is_open = (_dd::open_id == my_id);
    }

    const float dd_r = 4.0f;
    dl->AddRectFilled(pos, ImVec2(pos.x + w, pos.y + h), Colors::DropdownGradTop, dd_r);
    dl->AddRect(pos, ImVec2(pos.x + w, pos.y + h), Colors::ButtonBorder, dd_r, 0, 1.0f);

    const char* cur = (valid && items[*sel]) ? items[*sel] : "";
    float ty = pos.y + (h - ImGui::GetTextLineHeight()) * 0.5f;
    ImU32 cur_col = Colors::Text;
    dl->PushClipRect(ImVec2(pos.x + 6.0f, pos.y), ImVec2(pos.x + w - 18.0f, pos.y + h), true);
    float tx = pos.x + 8.0f;
    if (valid && item_cols && *sel >= 0 && *sel < count) {
        dl->AddRectFilled(ImVec2(tx, ty + 2.0f), ImVec2(tx + 8.0f, ty + ImGui::GetTextLineHeight() - 2.0f), item_cols[*sel], 2.0f);
        tx += 12.0f;
    }
    dl->AddText(ImVec2(tx, ty), cur_col, cur);
    dl->PopClipRect();

    float ax = pos.x + w - 14.0f;
    float ay = pos.y + h * 0.5f - 1.0f;
    ImU32 tri_col = Colors::TextDim;
    if (is_open) {
        dl->AddLine(ImVec2(ax, ay + 3.0f), ImVec2(ax + 3.0f, ay), tri_col, 1.5f);
        dl->AddLine(ImVec2(ax + 6.0f, ay + 3.0f), ImVec2(ax + 3.0f, ay), tri_col, 1.5f);
    } else {
        dl->AddLine(ImVec2(ax, ay), ImVec2(ax + 3.0f, ay + 3.0f), tri_col, 1.5f);
        dl->AddLine(ImVec2(ax + 6.0f, ay), ImVec2(ax + 3.0f, ay + 3.0f), tri_col, 1.5f);
    }
    ImGui::SetCursorScreenPos(ImVec2(pos.x, pos.y + h + 3.0f));

    if (is_open) {
        float max_cap_w = _dd::open_w;
        if (valid) {
            float mtw = 0.0f;
            for (int i = 0; i < count; i++) {
                float tw = ImGui::CalcTextSize(items[i]).x + 16.0f;
                if (item_cols) tw += 12.0f;
                if (tw > mtw) mtw = tw;
            }
            max_cap_w = ImMax(_dd::open_w, mtw);
        }
        ImGuiWindowFlags flags_w =
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground;
        ImGui::SetNextWindowPos(_dd::open_pos);
        ImGui::SetNextWindowSize(ImVec2(max_cap_w, _dd::PopupHeight()));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
        ImGui::Begin("##celerity_dropdown_capture", nullptr, flags_w);
        ImGui::InvisibleButton("##dropdown_capture", ImVec2(max_cap_w, _dd::PopupHeight()));
        ImGui::End();
        ImGui::PopStyleVar(2);
    }
    return changed;
}

inline bool MultiSelectDropdown(const char* label, int* flags, const char** items, int count, float col_w = -1.f, int disabled_mask = 0) {
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 pos = ImGui::GetCursorScreenPos();
    const float h = 24.0f;
    const float container_w = (col_w > 0.f) ? col_w : ImGui::GetContentRegionAvail().x;
    constexpr float btn_w = 140.0f;
    const float w = ImMin(btn_w, container_w);
    const float x_off = (container_w - w) * 0.5f;
    pos.x += x_off;
    const bool valid = (flags && items && count > 0);
    if (valid && disabled_mask) *flags &= ~disabled_mask;

    ImGui::SetCursorScreenPos(pos);
    ImGui::InvisibleButton(label, ImVec2(w, h));
    bool clicked = ImGui::IsItemClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking();
    ImGuiID my_id = ImGui::GetID(label);
    bool changed = _dd::ConsumeChanged(my_id);
    if (clicked) {
        if (_dd::open_id == my_id && !_dd::closing) {
            _dd::BeginClose();
        } else if (valid) {
            bool reopen = (_dd::open_id == my_id);
            _dd::open_id = my_id;
            _dd::open_frame = ImGui::GetFrameCount();
            _dd::open_pos = ImVec2(pos.x, pos.y + h);
            _dd::open_w = w;
            _dd::items = items;
            _dd::item_cols = nullptr;
            _dd::count = count;
            _dd::selected = nullptr;
            _dd::flags = flags;
            _dd::disabled_mask = disabled_mask;
            _dd::multi = true;
            _dd::closing = false;
            _dd::searchable = false;
            if (!reopen) {
                _dd::scroll_y = 0.0f;
                _dd::scroll_target = 0.0f;
                _dd::open_anim = 0.0f;
                _dd::ClearSearch();
            }
            _dd::ClampOpenPos();
        }
    }
    bool is_open = (_dd::open_id == my_id);
    if (is_open) {
        _dd::open_pos = ImVec2(pos.x, pos.y + h);
        _dd::open_w = w;
        _dd::items = items;
        _dd::item_cols = nullptr;
        _dd::count = count;
        _dd::selected = nullptr;
        _dd::flags = flags;
        _dd::disabled_mask = disabled_mask;
        _dd::multi = true;
        _dd::searchable = false;
        if (!valid) _dd::Close();
        else _dd::ClampOpenPos();
        is_open = (_dd::open_id == my_id);
    }

    const float dd_r = 4.0f;
    dl->AddRectFilled(pos, ImVec2(pos.x + w, pos.y + h), Colors::DropdownGradTop, dd_r);
    dl->AddRect(pos, ImVec2(pos.x + w, pos.y + h), Colors::ButtonBorder, dd_r, 0, 1.0f);

    std::string display_text;
    int selected_count = 0;
    const int max_bits = valid ? ImMin(count, 31) : 0;
    const unsigned int all_mask = (max_bits > 0) ? ((1u << max_bits) - 1u) : 0u;
    const unsigned int enabled_mask = all_mask & ~static_cast<unsigned int>(disabled_mask);
    if (valid && enabled_mask != 0u && (static_cast<unsigned int>(*flags) & enabled_mask) == enabled_mask) {
        display_text = "all";
    } else {
        const int max_show = 2;
        for (int i = 0; valid && i < count; i++) {
            if (i >= 31) break;
            if (*flags & (1 << i)) {
                if (selected_count >= max_show) { display_text += "..."; break; }
                if (selected_count > 0) display_text += ", ";
                display_text += items[i] ? items[i] : "";
                selected_count++;
            }
        }
        if (selected_count == 0) display_text = "-";
    }

    float ty = pos.y + (h - ImGui::GetTextLineHeight()) * 0.5f;
    dl->PushClipRect(ImVec2(pos.x + 6.0f, pos.y), ImVec2(pos.x + w - 18.0f, pos.y + h), true);
    dl->AddText(ImVec2(pos.x + 8.0f, ty), Colors::Text, display_text.c_str());
    dl->PopClipRect();

    float ax = pos.x + w - 14.0f;
    float ay = pos.y + h * 0.5f - 1.0f;
    ImU32 tri_col = Colors::TextDim;
    if (is_open) {
        dl->AddLine(ImVec2(ax, ay + 3.0f), ImVec2(ax + 3.0f, ay), tri_col, 1.5f);
        dl->AddLine(ImVec2(ax + 6.0f, ay + 3.0f), ImVec2(ax + 3.0f, ay), tri_col, 1.5f);
    } else {
        dl->AddLine(ImVec2(ax, ay), ImVec2(ax + 3.0f, ay + 3.0f), tri_col, 1.5f);
        dl->AddLine(ImVec2(ax + 6.0f, ay), ImVec2(ax + 3.0f, ay + 3.0f), tri_col, 1.5f);
    }
    ImGui::SetCursorScreenPos(ImVec2(pos.x, pos.y + h + 3.0f));

    if (is_open) {
        float max_cap_w = _dd::open_w;
        if (valid) {
            float mtw = 0.0f;
            for (int i = 0; i < count; i++) {
                float tw = ImGui::CalcTextSize(items[i]).x + 16.0f;
                if (tw > mtw) mtw = tw;
            }
            max_cap_w = ImMax(_dd::open_w, mtw);
        }
        ImGuiWindowFlags flags_win =
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground;
        ImGui::SetNextWindowPos(_dd::open_pos);
        ImGui::SetNextWindowSize(ImVec2(max_cap_w, _dd::PopupHeight()));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
        ImGui::Begin("##celerity_dropdown_capture", nullptr, flags_win);
        ImGui::InvisibleButton("##dropdown_capture", ImVec2(max_cap_w, _dd::PopupHeight()));
        ImGui::End();
        ImGui::PopStyleVar(2);
    }
    return changed;
}

inline void RenderOpenDropdown() {
    if (_dd::open_id == 0) return;
    if (!_dd::items || _dd::count <= 0 || _dd::open_w <= 0.0f) { _dd::Close(); return; }

    if (_dd::searchable) _dd::RebuildFiltered();
    _dd::ClampOpenPos();

    ImDrawList* fdl = ImGui::GetForegroundDrawList();
    const float dd_r = 4.0f;
    float list_h = _dd::OpenHeight();
    float popup_h = _dd::PopupHeight();
    float content_h = _dd::ContentHeight();

    {
        float dt = ImGui::GetIO().DeltaTime;
        float target = _dd::closing ? 0.0f : 1.0f;
        if (dt > 0.0f) {
            float a = 1.0f - expf(-dt * 20.0f);
            _dd::open_anim += (target - _dd::open_anim) * a;
        } else {
            _dd::open_anim = target;
        }
        if (_dd::closing && _dd::open_anim < 0.01f) { _dd::Close(); return; }
        if (!_dd::closing && _dd::open_anim > 0.999f) _dd::open_anim = 1.0f;
    }
    const bool anim_done = (!_dd::closing && _dd::open_anim >= 0.999f);

    float total = popup_h * _dd::open_anim;
    float max_scroll = ImMax(0.0f, content_h - list_h);
    ImVec2 p0 = _dd::open_pos;
    ImVec2 p1 = ImVec2(p0.x + _dd::open_w, p0.y + total);

    float max_text_w = 0.0f;
    for (int i = 0; i < _dd::count; i++) {
        float tw = ImGui::CalcTextSize(_dd::ItemText(i)).x + 16.0f;
        if (_dd::item_cols) tw += 12.0f;
        if (tw > max_text_w) max_text_w = tw;
    }
    p1.x = p0.x + ImMax(_dd::open_w, max_text_w);

    const float sh = _dd::searchable ? ImMin(_dd::search_h, total) : 0.0f;
    const float total_list = ImMax(0.0f, total - sh);
    const float list_top = p0.y;
    const float list_bottom = p0.y + total_list;

    ImGuiIO& io = ImGui::GetIO();
    ImVec2 mouse = io.MousePos;
    bool inside = (mouse.x >= p0.x && mouse.x <= p1.x && mouse.y >= p0.y && mouse.y <= p1.y);

    if (inside && !_dd::closing) io.WantCaptureMouse = true;

    if (_dd::searchable && !_dd::closing) {
        io.WantCaptureKeyboard = true;
        io.WantTextInput = true;
        bool q_changed = false;
        if (ImGui::IsKeyPressed(ImGuiKey_Backspace) && _dd::search_len > 0) {
            int new_len = _dd::search_len;
            while (new_len > 0 && ((unsigned char)_dd::search_buf[new_len - 1] & 0xC0) == 0x80) new_len--;
            if (new_len > 0) new_len--;
            _dd::search_len = new_len;
            _dd::search_buf[_dd::search_len] = '\0';
            q_changed = true;
        }
        for (int i = 0; i < io.InputQueueCharacters.Size; i++) {
            ImWchar c = io.InputQueueCharacters[i];
            if (c < 32) continue;
            char utf8[4];
            int n = _dd::UTF8Encode(c, utf8);
            if (_dd::search_len + n >= (int)sizeof(_dd::search_buf) - 1) break;
            for (int j = 0; j < n; j++) _dd::search_buf[_dd::search_len++] = utf8[j];
            _dd::search_buf[_dd::search_len] = '\0';
            q_changed = true;
        }
        if (q_changed) {
            io.InputQueueCharacters.resize(0);
            _dd::RebuildFiltered();
            _dd::scroll_y = 0.0f;
            _dd::scroll_target = 0.0f;
            list_h = _dd::OpenHeight();
            content_h = _dd::ContentHeight();
            max_scroll = ImMax(0.0f, content_h - list_h);
        }
    }

    const int vis_count = _dd::VisibleCount();

    if (inside && max_scroll > 0.0f && io.MouseWheel != 0.0f && !_dd::closing && !UI::IsOpenColorPickerBlocking()) {
        _dd::scroll_target = ImClamp(_dd::scroll_target - io.MouseWheel * _dd::item_h * 3.0f, 0.0f, max_scroll);
        io.WantCaptureMouse = true;
    }

    _dd::scroll_target = ImClamp(_dd::scroll_target, 0.0f, max_scroll);
    if (io.DeltaTime > 0.0f) {
        float a = 1.0f - expf(-io.DeltaTime * 16.0f);
        _dd::scroll_y += (_dd::scroll_target - _dd::scroll_y) * a;
        if (fabsf(_dd::scroll_target - _dd::scroll_y) < 0.5f) _dd::scroll_y = _dd::scroll_target;
    } else {
        _dd::scroll_y = _dd::scroll_target;
    }

    fdl->AddRectFilled(p0, p1, Colors::Bg, dd_r);
    fdl->AddRect(p0, p1, Colors::ButtonBorder, dd_r, 0, 1.0f);

    if (_dd::searchable && sh > 6.0f) {
        ImVec2 s0 = ImVec2(p0.x, p1.y - sh);
        ImVec2 s1 = ImVec2(p1.x, p1.y);
        fdl->AddRectFilled(s0, s1, Colors::InputBg, dd_r);
        fdl->AddLine(ImVec2(s0.x, s0.y), ImVec2(s1.x, s0.y), Colors::ButtonBorder, 1.0f);
        float qty = s0.y + (sh - ImGui::GetTextLineHeight()) * 0.5f;
        fdl->PushClipRect(ImVec2(s0.x + 6.0f, s0.y), ImVec2(s1.x - 6.0f, s1.y), true);
        const bool blink = ((int)(ImGui::GetTime() * 2.0) % 2 == 0) && !_dd::closing;
        float text_x = s0.x + 8.0f;
        if (_dd::search_len > 0) {
            fdl->AddText(ImVec2(text_x, qty), Colors::Text, _dd::search_buf);
            if (blink) {
                float cx = text_x + ImGui::CalcTextSize(_dd::search_buf).x + 1.0f;
                fdl->AddLine(ImVec2(cx, qty), ImVec2(cx, qty + ImGui::GetTextLineHeight()), Colors::Text, 1.0f);
            }
        } else {
            fdl->AddText(ImVec2(text_x, qty), Colors::TextDim, "search...");
            if (blink)
                fdl->AddLine(ImVec2(text_x, qty), ImVec2(text_x, qty + ImGui::GetTextLineHeight()), Colors::TextDim, 1.0f);
        }
        fdl->PopClipRect();
    }

    bool on_thumb = false;
    float thumb_x0 = 0, thumb_x1 = 0, thumb_y0 = 0, thumb_y1 = 0;
    if (max_scroll > 0.0f && anim_done) {
        const float track_h = total_list - 4.0f;
        const float thumb_h = ImMax(12.0f, track_h * (list_h / content_h));
        const float thumb_y = list_top + 2.0f + (_dd::scroll_y / max_scroll) * (track_h - thumb_h);
        thumb_x0 = p1.x - 6.0f;
        thumb_x1 = p1.x;
        thumb_y0 = thumb_y;
        thumb_y1 = thumb_y + thumb_h;
        on_thumb = (mouse.x >= thumb_x0 && mouse.x <= thumb_x1 && mouse.y >= thumb_y0 && mouse.y <= thumb_y1);
    }

    const int first = ImMax(0, (int)(_dd::scroll_y / _dd::item_h));
    const int last = ImMin(vis_count, first + (int)(total_list / _dd::item_h) + 3);
    fdl->PushClipRect(ImVec2(p0.x + 1.0f, list_top + 1.0f), ImVec2(p1.x - 1.0f, list_bottom - 1.0f), true);

    if (vis_count == 0) {
        fdl->PopClipRect();
        if (_dd::searchable) {
            const float display_h = ImMax(total_list, 100.0f);
            const float display_top = p1.y - sh - display_h;
            const char* msg = "no results";
            ImVec2 ts = ImGui::CalcTextSize(msg);
            fdl->AddText(ImVec2(p0.x + (p1.x - p0.x - ts.x) * 0.5f, display_top + (display_h - ts.y) * 0.5f), Colors::TextDim, msg);
        }
        return;
    }

    if (_dd::multi && _dd::flags) {
        bool click_any = ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking() && !on_thumb && !_dd::closing && (ImGui::GetFrameCount() > _dd::open_frame);
        for (int v = first; v < last; v++) {
            const int i = _dd::OrigIndex(v);
            ImVec2 ip0 = ImVec2(p0.x + 1.0f, list_top + 2.0f + (float)v * _dd::item_h - _dd::scroll_y);
            ImVec2 ip1 = ImVec2(p1.x - 1.0f, ip0.y + _dd::item_h);
            const bool disabled_i = (i < 31) && ((_dd::disabled_mask & (1 << i)) != 0);
            bool hov_i = (mouse.x >= ip0.x && mouse.x <= ip1.x && mouse.y >= ip0.y && mouse.y <= ip1.y && mouse.y < list_bottom);
            bool sel_i = !disabled_i && (i < 31) && ((*_dd::flags & (1 << i)) != 0);
            float ty = ip0.y + (_dd::item_h - ImGui::GetTextLineHeight()) * 0.5f;
            ImU32 tc = disabled_i ? Colors::TextDim : (sel_i ? Colors::Accent : Colors::Text);
            if (hov_i && !sel_i && !disabled_i)
                fdl->AddRectFilled(ip0, ip1, IM_COL32(255, 255, 255, 10), 0.0f);
            fdl->PushClipRect(ImVec2(ip0.x + 6.0f, ip0.y), ImVec2(ip1.x - 6.0f, ip1.y), true);
            float tx = ip0.x + 8.0f;
            if (sel_i && !disabled_i)
                fdl->AddRectFilled(ImVec2(ip0.x + 2.0f, ip0.y + 4.0f), ImVec2(ip0.x + 4.0f, ip1.y - 4.0f), Colors::Accent, 1.0f);
            fdl->AddText(ImVec2(tx + 4.0f, ty), tc, _dd::ItemText(i));
            fdl->PopClipRect();
            if (hov_i && click_any && i < 31 && !disabled_i) { *_dd::flags ^= (1 << i); _dd::MarkChanged(); }
        }
        fdl->PopClipRect();
        if (click_any && !inside) _dd::BeginClose();
    } else if (_dd::selected) {
        int click_sel = -1;
        bool click_any = ImGui::IsMouseClicked(ImGuiMouseButton_Left) && !UI::IsOpenColorPickerBlocking() && !on_thumb && !_dd::closing && (ImGui::GetFrameCount() > _dd::open_frame);
        for (int v = first; v < last; v++) {
            const int i = _dd::OrigIndex(v);
            ImVec2 ip0 = ImVec2(p0.x + 1.0f, list_top + 2.0f + (float)v * _dd::item_h - _dd::scroll_y);
            ImVec2 ip1 = ImVec2(p1.x - 1.0f, ip0.y + _dd::item_h);
            bool hov_i = (mouse.x >= ip0.x && mouse.x <= ip1.x && mouse.y >= ip0.y && mouse.y <= ip1.y && mouse.y < list_bottom);
            bool sel_i = (*_dd::selected == i);
            float ty = ip0.y + (_dd::item_h - ImGui::GetTextLineHeight()) * 0.5f;
            ImU32 tc = sel_i ? Colors::Accent : Colors::Text;
            if (hov_i && !sel_i)
                fdl->AddRectFilled(ip0, ip1, IM_COL32(255, 255, 255, 10), 0.0f);
            fdl->PushClipRect(ImVec2(ip0.x + 6.0f, ip0.y), ImVec2(ip1.x - 6.0f, ip1.y), true);
            float tx = ip0.x + 8.0f;
            if (sel_i)
                fdl->AddRectFilled(ImVec2(ip0.x + 2.0f, ip0.y + 4.0f), ImVec2(ip0.x + 4.0f, ip1.y - 4.0f), Colors::Accent, 1.0f);
            if (_dd::item_cols) {
                float sq_y = ty + (ImGui::GetTextLineHeight() - 8.0f) * 0.5f;
                fdl->AddRectFilled(ImVec2(tx, sq_y), ImVec2(tx + 8.0f, sq_y + 8.0f), _dd::item_cols[i], 2.0f);
                tx += 12.0f;
            }
            fdl->AddText(ImVec2(tx + 4.0f, ty), tc, _dd::ItemText(i));
            fdl->PopClipRect();
            if (hov_i && click_any) click_sel = i;
        }
        fdl->PopClipRect();
        if (click_sel >= 0) {
            if (*_dd::selected != click_sel) { *_dd::selected = click_sel; _dd::MarkChanged(); }
            _dd::BeginClose();
        }
        if (click_any && !inside) _dd::BeginClose();
    } else {
        fdl->PopClipRect();
        _dd::Close();
        return;
    }

    if (max_scroll > 0.0f && anim_done) {
        const float track_h = total_list - 4.0f;
        const float thumb_h = ImMax(12.0f, track_h * (list_h / content_h));
        const float thumb_y = list_top + 2.0f + (_dd::scroll_y / max_scroll) * (track_h - thumb_h);
        fdl->AddRectFilled(ImVec2(p1.x - 4.0f, list_top + 2.0f), ImVec2(p1.x - 2.0f, list_bottom - 2.0f), IM_COL32(20, 18, 24, 180), 2.0f);
        fdl->AddRectFilled(ImVec2(p1.x - 3.0f, thumb_y), ImVec2(p1.x - 1.0f, thumb_y + thumb_h), Colors::Accent, 2.0f);
        if (!UI::IsOpenColorPickerBlocking()) {
            if (io.MouseClicked[ImGuiMouseButton_Left] && on_thumb) {
                _dd::dragging_scroll = true;
                _dd::drag_start_y = mouse.y;
                _dd::drag_start_scroll = _dd::scroll_y;
            }
            if (_dd::dragging_scroll) {
                if (io.MouseDown[ImGuiMouseButton_Left]) {
                    float dy = mouse.y - _dd::drag_start_y;
                    float scroll_range = track_h - thumb_h;
                    if (scroll_range > 0.0f) {
                        _dd::scroll_y = ImClamp(_dd::drag_start_scroll + (dy / scroll_range) * max_scroll, 0.0f, max_scroll);
                        _dd::scroll_target = _dd::scroll_y;
                    }
                    io.WantCaptureMouse = true;
                } else {
                    _dd::dragging_scroll = false;
                }
            }
        }
    }
}
}
