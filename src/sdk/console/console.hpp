#pragma once
#include <Windows.h>
#include <cstdio>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <string>
#include <thread>

#include "debug_log.hpp"

namespace logger {

inline HANDLE g_console = nullptr;

// ---- background printer -----------------------------------------------------
// all the pretty (and slow, Sleep-driven) console output runs on its own thread
// so the real init pipeline never blocks waiting on typewriter animations.
namespace detail {

struct status_msg { std::string name; bool success; bool notice = false; };

inline std::mutex              g_mtx;
inline std::condition_variable g_cv;
inline std::deque<status_msg>  g_queue;
inline std::atomic<bool>       g_running{ false };
inline std::thread             g_thread;

inline void draw_banner() {
    static const char* glyphs[8][6] = {
        { " #### ", "##  ##", "##    ", "##    ", "##  ##", " #### " }, // C
        { "######", "##    ", "##### ", "##    ", "##    ", "######" }, // E
        { "##    ", "##    ", "##    ", "##    ", "##    ", "######" }, // L
        { "######", "##    ", "##### ", "##    ", "##    ", "######" }, // E
        { "##### ", "##  ##", "##### ", "## ## ", "##  ##", "##  ##" }, // R
        { "######", "  ##  ", "  ##  ", "  ##  ", "  ##  ", "######" }, // I
        { "######", "  ##  ", "  ##  ", "  ##  ", "  ##  ", "  ##  " }, // T
        { "##  ##", "##  ##", " #### ", "  ##  ", "  ##  ", "  ##  " }, // Y
    };
    static const char* shades[] = { "\xe2\x96\x91", "\xe2\x96\x92", "\xe2\x96\x93", "\xe2\x96\x88" }; // ░ ▒ ▓ █

    const int H = 6, N = 8, gap = 3, gw = 6;
    printf("\n");

    CONSOLE_SCREEN_BUFFER_INFO sb{};
    GetConsoleScreenBufferInfo(g_console, &sb);
    SHORT top = sb.dwCursorPosition.Y;

    const int pr = 255, pg = 182, pb = 248;      // accent pink (1.0, 0.714, 0.973)
    for (int col = 0; col < N; ++col) {
        for (int r = 0; r < H; ++r) {
            int slant = (H - r) / 2;             // gentle italic
            if (r == H - 1) slant += 1;          // nudge the bottom row forward
            COORD at{ (SHORT)(2 + slant + col * (gw + gap)), (SHORT)(top + r) };
            SetConsoleCursorPosition(g_console, at);
            printf("\x1b[38;2;%d;%d;%dm", pr, pg, pb);
            const char* g = glyphs[col][r];
            for (int c = 0; g[c] != '\0'; ++c)
                fputs(g[c] == '#' ? shades[col / 2] : " ", stdout);
            printf("\x1b[0m");
        }
        fflush(stdout);
        Sleep(45);                               // quick per-letter reveal
    }

    SetConsoleCursorPosition(g_console, COORD{ 0, (SHORT)(top + H + 1) });
}

inline void draw_notice(const status_msg& m) {
    printf("\n");                                // blank line before the warning
    printf("\x1b[38;2;255;80;80m");              // red warning color
    for (const char* p = m.name.c_str(); *p != '\0'; ++p) {
        fputc(*p, stdout);
        fflush(stdout);
        Sleep(6);
    }
    printf("\x1b[0m\n");
}

inline void draw_status(const status_msg& m, int step) {
    const int total = 7;                        // number of init lines
    int g = 90 + (step * 155) / (total - 1);    // 90..245
    if (g > 245) g = 245;

    char line[128];
    _snprintf_s(line, sizeof(line), _TRUNCATE, "  [%s] -> %s",
                m.name.c_str(), m.success ? "initialized successfully" : "failed");

    int r  = m.success ? g / 4 : 220;
    int gg = m.success ? g     : 60;
    int b  = m.success ? g / 4 : 60;

    printf("\x1b[38;2;%d;%d;%dm", r, gg, b);     // set color once for the line
    for (int i = 0; line[i] != '\0'; ++i) {      // typewriter reveal
        fputc(line[i], stdout);
        fflush(stdout);
        Sleep(6);
    }
    printf("\x1b[0m\n");
    Sleep(35);                                   // brief beat between lines
}

inline void printer_loop() {
    {
        std::lock_guard<std::recursive_mutex> print_lock(dbg::print_mutex());
        draw_banner();
    }

    int step = 0;
    while (true) {
        status_msg m;
        {
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [] { return !g_queue.empty() || !g_running.load(); });
            if (g_queue.empty() && !g_running.load())
                break;
            m = std::move(g_queue.front());
            g_queue.pop_front();
        }
        std::lock_guard<std::recursive_mutex> print_lock(dbg::print_mutex());
        if (m.notice)
            draw_notice(m);
        else
            draw_status(m, step++);
    }
}

} // namespace detail

inline void initialize() {
    AllocConsole();
    SetConsoleTitleA("celerity");

    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "w", stderr);

    g_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleOutputCP(CP_UTF8);

    DWORD mode = 0;                                     // enable ANSI truecolor
    GetConsoleMode(g_console, &mode);
    SetConsoleMode(g_console, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    CONSOLE_CURSOR_INFO cursor{};
    cursor.dwSize = 1;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(g_console, &cursor);

    dbg::set_console(true);

    // fire up the printer thread; returns immediately so init never blocks.
    detail::g_running.store(true);
    detail::g_thread = std::thread(detail::printer_loop);
}

inline void shutdown() {
    if (detail::g_running.exchange(false)) {
        detail::g_cv.notify_all();
        if (detail::g_thread.joinable())
            detail::g_thread.join();
    }
    dbg::set_console(false);
    if (g_console) {
        FreeConsole();
        g_console = nullptr;
    }
}

inline void init_status(const char* name, bool success) {
    {
        std::lock_guard<std::mutex> lk(detail::g_mtx);
        detail::g_queue.push_back({ name, success, false });
    }
    detail::g_cv.notify_one();
}

inline void notice(const char* text) {
    {
        std::lock_guard<std::mutex> lk(detail::g_mtx);
        detail::g_queue.push_back({ text, false, true });
    }
    detail::g_cv.notify_one();
}

}

#define LOG(fmt, ...)        ((void)0)
#define LOG_ERROR(fmt, ...)  do { \
    char _log_buf[512]; \
    _snprintf_s(_log_buf, sizeof(_log_buf), _TRUNCATE, (const char*)(fmt), ##__VA_ARGS__); \
    ::dbg::log_file("ERR ", "%s", _log_buf); \
    logger::notice(_log_buf); \
} while(0)
#define LOG_WARNING(fmt, ...) ((void)0)
#define LOG_SUCCESS(fmt, ...) ((void)0)
#define LOG_INFO(fmt, ...)   ((void)0)
