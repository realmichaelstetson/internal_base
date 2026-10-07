#pragma once
// Synchronous debug log + crash reporter.
//
// Every line goes straight to the console AND to
//   %USERPROFILE%\Documents\celerity\debug.log
// (flushed per line, so the file survives a CS2 crash).
//
// When the game hits an access violation / illegal instruction / etc. the
// exception handler writes a crash report: exception address as module+offset,
// what memory was touched, registers, the init step / hook that was running
// and a call stack.
//
//   DBG_INFO("resolved %s -> %s", name, dbg::addr(ptr).s);
//   DBG_WARN(...); DBG_ERR(...); DBG_OK(...);
//   DBG_HOOK("FrameStageNotify");   // first line of a hook: logs the first call + tags the thread

#include <Windows.h>
#include <DbgHelp.h>
#include <intrin.h>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstring>

namespace dbg {

inline HANDLE g_file = INVALID_HANDLE_VALUE;
inline bool g_console = false;
inline LARGE_INTEGER g_start{}, g_freq{};
inline char g_path[MAX_PATH] = {};
inline const char* g_entry_via = "?";                    // which of the three entry paths fired first
inline const char* g_init_step = "dll attach";            // last init step (any thread)
inline const char* t_stage = nullptr;                       // last hook / signature entered (any thread)
inline bool g_initialized = false;
inline HMODULE g_self = nullptr;
inline std::uintptr_t g_self_size = 0;
inline HANDLE g_sym_process = nullptr;   // dbghelp session (our own handle, not the game's)
inline PVOID g_veh = nullptr;
inline LPTOP_LEVEL_EXCEPTION_FILTER g_prev_filter = nullptr;

// Keeps lines from interleaving. Deliberately a raw spinlock and not std::mutex:
// this logger runs from an init_seg(lib) initialiser, before the normal globals
// (and before libprotobuf's initialisers, which is where a manual-mapped build
// dies), so it must not depend on anything the C++ runtime constructs for us.
// A zero-initialised LONG lives in .data and is valid from the first instruction.
inline volatile LONG g_print_lock = 0;
inline DWORD g_print_owner = 0;
inline LONG g_print_depth = 0;

inline bool print_lock_acquire(DWORD timeout_ms) {
	const DWORD me = GetCurrentThreadId();
	if (g_print_owner == me) {          // recursive: already ours
		++g_print_depth;
		return true;
	}
	for (const auto deadline = GetTickCount64() + timeout_ms;;) {
		if (!InterlockedCompareExchange(&g_print_lock, 1, 0)) {
			g_print_owner = me;
			g_print_depth = 1;
			return true;
		}
		if (GetTickCount64() >= deadline)
			return false;               // a crash can hit while another thread holds it
		Sleep(1);
	}
}

inline void print_lock_release() {
	if (--g_print_depth > 0)
		return;
	g_print_owner = 0;
	InterlockedExchange(&g_print_lock, 0);
}

// ---------------------------------------------------------------- memory helpers

inline bool readable(const void* p, std::size_t n = 1) {
	if (!p)
		return false;
	MEMORY_BASIC_INFORMATION mbi{};
	auto cur = reinterpret_cast<std::uintptr_t>(p);
	const auto end = cur + n;
	while (cur < end) {
		if (!VirtualQuery(reinterpret_cast<void*>(cur), &mbi, sizeof(mbi)))
			return false;
		if (mbi.State != MEM_COMMIT || (mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD)))
			return false;
		cur = reinterpret_cast<std::uintptr_t>(mbi.BaseAddress) + mbi.RegionSize;
	}
	return true;
}

inline bool executable(const void* p) {
	MEMORY_BASIC_INFORMATION mbi{};
	if (!p || !VirtualQuery(p, &mbi, sizeof(mbi)) || mbi.State != MEM_COMMIT)
		return false;
	return (mbi.Protect & (PAGE_EXECUTE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) != 0;
}

inline HMODULE module_of(const void* p) {
	HMODULE mod = nullptr;
	if (!p || !GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
	                             reinterpret_cast<LPCSTR>(p), &mod))
		return nullptr;
	return mod;
}

inline const char* module_name(HMODULE mod, char* buf, DWORD size) {
	if (!mod || !GetModuleFileNameA(mod, buf, size))
		return "?";
	const char* slash = std::strrchr(buf, '\\');
	return slash ? slash + 1 : buf;
}

// our dll, also when the injector manual-maps it (then GetModuleHandleEx can't see it)
inline bool in_self(const void* p) {
	const auto a = reinterpret_cast<std::uintptr_t>(p), b = reinterpret_cast<std::uintptr_t>(g_self);
	return g_self && a >= b && a < b + g_self_size;
}

inline bool symbolize(const void* p, char* out, std::size_t n);
inline void log(const char* level, const char* color, const char* fmt, ...);
#define DBG_LOG_RAW(level, msg) ::dbg::log(level, "\x1b[38;2;150;150;150m", "%s", msg)

// "00007FF8ADB95B20 (client.dll+0xB65B20)"
inline void describe(const void* p, char* out, std::size_t n) {
	char path[MAX_PATH];
	if (in_self(p)) {
		char sym[256];
		const auto off = static_cast<unsigned long long>(reinterpret_cast<std::uintptr_t>(p) - reinterpret_cast<std::uintptr_t>(g_self));
		if (symbolize(p, sym, sizeof(sym)))
			_snprintf_s(out, n, _TRUNCATE, "%p (celerity+0x%llX %s)", p, off, sym);
		else
			_snprintf_s(out, n, _TRUNCATE, "%p (celerity+0x%llX)", p, off);
	} else if (HMODULE mod = module_of(p)) {
		_snprintf_s(out, n, _TRUNCATE, "%p (%s+0x%llX)", p, module_name(mod, path, MAX_PATH),
		            static_cast<unsigned long long>(reinterpret_cast<std::uintptr_t>(p) - reinterpret_cast<std::uintptr_t>(mod)));
	} else {
		_snprintf_s(out, n, _TRUNCATE, "%p", p);
	}
}

struct addr {
	char s[400];
	explicit addr(const void* p) { describe(p, s, sizeof(s)); }
	explicit addr(std::uintptr_t p) { describe(reinterpret_cast<const void*>(p), s, sizeof(s)); }
};

// "48 89 5C 24 08 ..." or "<unreadable>"
struct bytes {
	char s[3 * 32 + 16];
	bytes(const void* p, int n) {
		if (n > 32)
			n = 32;
		if (!readable(p, n)) {
			strcpy_s(s, "<unreadable>");
			return;
		}
		char* w = s;
		for (int i = 0; i < n; ++i, w += 3)
			_snprintf_s(w, 4, _TRUNCATE, "%02X ", static_cast<const unsigned char*>(p)[i]);
		if (n)
			w[-1] = '\0';
		else
			s[0] = '\0';
	}
};

// object whose first qword is a vtable living inside `mod`
inline bool looks_like_object(const void* obj, HMODULE mod) {
	if (!readable(obj, sizeof(void*)))
		return false;
	void* vtable = *static_cast<void* const*>(obj);
	if (!readable(vtable, sizeof(void*)) || (mod && module_of(vtable) != mod))
		return false;
	void* first = *static_cast<void* const*>(vtable);
	return executable(first);
}

// ---------------------------------------------------------------- symbols (function + line from the .pdb)

using SymInitialize_t = BOOL(WINAPI*)(HANDLE, PCSTR, BOOL);
using SymSetOptions_t = DWORD(WINAPI*)(DWORD);
using SymLoadModuleEx_t = DWORD64(WINAPI*)(HANDLE, HANDLE, PCSTR, PCSTR, DWORD64, DWORD, PMODLOAD_DATA, DWORD);
using SymFromAddr_t = BOOL(WINAPI*)(HANDLE, DWORD64, PDWORD64, PSYMBOL_INFO);
using SymGetLineFromAddr64_t = BOOL(WINAPI*)(HANDLE, DWORD64, PDWORD, PIMAGEHLP_LINE64);
inline SymFromAddr_t g_sym_from_addr = nullptr;
inline SymGetLineFromAddr64_t g_sym_get_line = nullptr;

// best effort; call from a normal thread (not DllMain)
inline void init_symbols() {
	char dll_path[MAX_PATH] = {};
	if (!g_self || !GetModuleFileNameA(g_self, dll_path, MAX_PATH)) {
		DBG_LOG_RAW("info", "symbols: dll path unknown (manual mapped?), crash reports will show offsets only");
		return;
	}
	HMODULE dbghelp = LoadLibraryA("dbghelp.dll");
	if (!dbghelp)
		return;
	auto sym_init = reinterpret_cast<SymInitialize_t>(GetProcAddress(dbghelp, "SymInitialize"));
	auto sym_opts = reinterpret_cast<SymSetOptions_t>(GetProcAddress(dbghelp, "SymSetOptions"));
	auto sym_load = reinterpret_cast<SymLoadModuleEx_t>(GetProcAddress(dbghelp, "SymLoadModuleEx"));
	g_sym_from_addr = reinterpret_cast<SymFromAddr_t>(GetProcAddress(dbghelp, "SymFromAddr"));
	g_sym_get_line = reinterpret_cast<SymGetLineFromAddr64_t>(GetProcAddress(dbghelp, "SymGetLineFromAddr64"));
	if (!sym_init || !sym_opts || !sym_load || !g_sym_from_addr)
		return;

	char dir[MAX_PATH];
	strcpy_s(dir, dll_path);
	if (char* slash = std::strrchr(dir, '\\'))
		*slash = '\0';

	HANDLE h = nullptr;
	DuplicateHandle(GetCurrentProcess(), GetCurrentProcess(), GetCurrentProcess(), &h, 0, FALSE, DUPLICATE_SAME_ACCESS);
	if (!h)
		return;
	sym_opts(SYMOPT_UNDNAME | SYMOPT_LOAD_LINES | SYMOPT_FAIL_CRITICAL_ERRORS);
	if (!sym_init(h, dir, FALSE)) {
		CloseHandle(h);
		return;
	}
	if (!sym_load(h, nullptr, dll_path, nullptr, reinterpret_cast<DWORD64>(g_self), static_cast<DWORD>(g_self_size), nullptr, 0)
		&& GetLastError() != ERROR_SUCCESS) {
		DBG_LOG_RAW("warn", "symbols: could not load the .pdb next to the dll, crash reports will show offsets only");
		CloseHandle(h);
		return;
	}
	g_sym_process = h;
	DBG_LOG_RAW("info", "symbols loaded from .pdb next to the dll");
}

inline bool symbolize(const void* p, char* out, std::size_t n) {
	if (!g_sym_process || !g_sym_from_addr)
		return false;
	alignas(SYMBOL_INFO) char buf[sizeof(SYMBOL_INFO) + 256] = {};
	auto* sym = reinterpret_cast<SYMBOL_INFO*>(buf);
	sym->SizeOfStruct = sizeof(SYMBOL_INFO);
	sym->MaxNameLen = 255;
	DWORD64 disp = 0;
	if (!g_sym_from_addr(g_sym_process, reinterpret_cast<DWORD64>(p), &disp, sym))
		return false;
	IMAGEHLP_LINE64 line{};
	line.SizeOfStruct = sizeof(line);
	DWORD line_disp = 0;
	if (g_sym_get_line && g_sym_get_line(g_sym_process, reinterpret_cast<DWORD64>(p), &line_disp, &line) && line.FileName) {
		const char* file = std::strrchr(line.FileName, '\\');
		_snprintf_s(out, n, _TRUNCATE, "%s+0x%llX %s:%lu", sym->Name, static_cast<unsigned long long>(disp),
		            file ? file + 1 : line.FileName, line.LineNumber);
	} else {
		_snprintf_s(out, n, _TRUNCATE, "%s+0x%llX", sym->Name, static_cast<unsigned long long>(disp));
	}
	return true;
}

// ---------------------------------------------------------------- output

inline void write_out(const char* s, int len, const char* color, bool to_console) {
	OutputDebugStringA(s);          // also visible in DebugView
	OutputDebugStringA("\n");
	if (g_file != INVALID_HANDLE_VALUE) {
		DWORD w = 0;
		WriteFile(g_file, s, static_cast<DWORD>(len), &w, nullptr);
		WriteFile(g_file, "\r\n", 2, &w, nullptr);
	}
	if (g_console && to_console) {
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		if (out && out != INVALID_HANDLE_VALUE) {
			DWORD w = 0;
			WriteFile(out, color, static_cast<DWORD>(std::strlen(color)), &w, nullptr);
			WriteFile(out, s, static_cast<DWORD>(len), &w, nullptr);
			WriteFile(out, "\x1b[0m\n", 5, &w, nullptr);
		}
	}
}

inline void vlog(const char* level, const char* color, bool to_console, const char* fmt, va_list ap) {
	char buf[1536];
	LARGE_INTEGER now{};
	QueryPerformanceCounter(&now);
	const double t = g_freq.QuadPart ? double(now.QuadPart - g_start.QuadPart) / double(g_freq.QuadPart) : 0.0;
	int n = _snprintf_s(buf, sizeof(buf), _TRUNCATE, "[%8.3f][T%05lu][%s] ", t, GetCurrentThreadId(), level);
	if (n < 0)
		n = 0;
	int m = _vsnprintf_s(buf + n, sizeof(buf) - n, _TRUNCATE, fmt, ap);
	int len = (m < 0) ? static_cast<int>(std::strlen(buf)) : n + m;

	// never block forever (a crash can happen while another thread holds the lock)
	const bool locked = print_lock_acquire(1000);
	write_out(buf, len, color, to_console);
	if (locked)
		print_lock_release();
}

inline void log(const char* level, const char* color, const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vlog(level, color, true, fmt, ap);
	va_end(ap);
}

// file only (used by LOG_ERROR, which the console already shows as a notice)
inline void log_file(const char* level, const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vlog(level, "", false, fmt, ap);
	va_end(ap);
}

#define DBG_INFO(fmt, ...) ::dbg::log("info", "\x1b[38;2;150;150;150m", fmt, ##__VA_ARGS__)
#define DBG_OK(fmt, ...)   ::dbg::log(" ok ", "\x1b[38;2;90;220;120m", fmt, ##__VA_ARGS__)
#define DBG_WARN(fmt, ...) ::dbg::log("warn", "\x1b[38;2;255;200;60m", fmt, ##__VA_ARGS__)
#define DBG_ERR(fmt, ...)  ::dbg::log("ERR ", "\x1b[38;2;255;80;80m", fmt, ##__VA_ARGS__)

// first statement of a hook detour: tags the thread and logs the first call
#define DBG_HOOK(name) \
	do { \
		::dbg::t_stage = "hook " name; \
		static volatile LONG _dbg_hook_seen = 0; \
		if (!_dbg_hook_seen && !InterlockedExchange(&_dbg_hook_seen, 1)) \
			DBG_INFO("[hook] first call: %s", name); \
	} while (0)

// ---------------------------------------------------------------- crash report

inline const char* exception_name(DWORD code) {
	switch (code) {
	case EXCEPTION_ACCESS_VIOLATION: return "ACCESS_VIOLATION";
	case EXCEPTION_ILLEGAL_INSTRUCTION: return "ILLEGAL_INSTRUCTION";
	case EXCEPTION_PRIV_INSTRUCTION: return "PRIVILEGED_INSTRUCTION";
	case EXCEPTION_STACK_OVERFLOW: return "STACK_OVERFLOW";
	case EXCEPTION_INT_DIVIDE_BY_ZERO: return "INT_DIVIDE_BY_ZERO";
	case EXCEPTION_IN_PAGE_ERROR: return "IN_PAGE_ERROR";
	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED: return "ARRAY_BOUNDS_EXCEEDED";
	case 0xC0000374: return "HEAP_CORRUPTION";
	case 0xC0000409: return "STACK_BUFFER_OVERRUN (/GS or __fastfail)";
	default: return nullptr;
	}
}

// walk the stack with the unwind tables; separate function because of __try
inline int walk_stack(CONTEXT ctx, void** frames, int max) {
	int n = 0;
	__try {
		while (n < max && ctx.Rip) {
			frames[n++] = reinterpret_cast<void*>(ctx.Rip);
			DWORD64 image_base = 0;
			PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(ctx.Rip, &image_base, nullptr);
			if (!fn) {
				if (!readable(reinterpret_cast<void*>(ctx.Rsp), 8))
					break;
				ctx.Rip = *reinterpret_cast<DWORD64*>(ctx.Rsp);
				ctx.Rsp += 8;
			} else {
				PVOID handler_data = nullptr;
				DWORD64 establisher = 0;
				RtlVirtualUnwind(UNW_FLAG_NHANDLER, image_base, ctx.Rip, fn, &ctx, &handler_data, &establisher, nullptr);
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {}
	return n;
}

inline void crash_report(EXCEPTION_POINTERS* ep, const char* kind) {
	const auto* rec = ep->ExceptionRecord;
	const auto* c = ep->ContextRecord;
	const char* name = exception_name(rec->ExceptionCode);

	DBG_ERR("==================== %s ====================", kind);
	DBG_ERR("exception : %s (0x%08lX)", name ? name : "?", rec->ExceptionCode);
	DBG_ERR("address   : %s%s", addr(rec->ExceptionAddress).s,
	        in_self(rec->ExceptionAddress) ? "   <-- inside OUR dll" : "");
	if (rec->ExceptionCode == EXCEPTION_ACCESS_VIOLATION && rec->NumberParameters >= 2) {
		const auto op = rec->ExceptionInformation[0];
		DBG_ERR("access    : %s %s", op == 0 ? "READ from" : op == 1 ? "WRITE to" : "EXECUTE at",
		        addr(rec->ExceptionInformation[1]).s);
	}
	DBG_ERR("thread    : %lu   init step: %s   last hook/signature entered: %s", GetCurrentThreadId(),
	        g_init_step ? g_init_step : "-", t_stage ? t_stage : "-");
	DBG_ERR("code      : %s", bytes(rec->ExceptionAddress, 16).s);
	DBG_ERR("RAX %016llX RBX %016llX RCX %016llX RDX %016llX", c->Rax, c->Rbx, c->Rcx, c->Rdx);
	DBG_ERR("RSI %016llX RDI %016llX RBP %016llX RSP %016llX", c->Rsi, c->Rdi, c->Rbp, c->Rsp);
	DBG_ERR("R8  %016llX R9  %016llX R10 %016llX R11 %016llX", c->R8, c->R9, c->R10, c->R11);
	DBG_ERR("R12 %016llX R13 %016llX R14 %016llX R15 %016llX", c->R12, c->R13, c->R14, c->R15);

	void* frames[24];
	const int n = walk_stack(*c, frames, 24);
	DBG_ERR("call stack:");
	for (int i = 0; i < n; ++i)
		DBG_ERR("  #%02d %s%s", i, addr(frames[i]).s, in_self(frames[i]) ? "   <-- ours" : "");
	// raw scan: code pointers lying on the stack (helps when the walk above stops early)
	DBG_ERR("code pointers on the stack:");
	int shown = 0;
	const auto* sp = reinterpret_cast<const std::uintptr_t*>(c->Rsp);
	for (int i = 0; i < 512 && shown < 16; ++i) {
		if (!readable(sp + i, sizeof(std::uintptr_t)))
			break;
		const void* v = reinterpret_cast<const void*>(sp[i]);
		if (reinterpret_cast<std::uintptr_t>(v) > 0x10000 && executable(v) && (in_self(v) || module_of(v))) {
			DBG_ERR("  [rsp+0x%03X] %s%s", i * 8, addr(v).s, in_self(v) ? "   <-- ours" : "");
			++shown;
		}
	}
	DBG_ERR("log file: %s", g_path);
	DBG_ERR("=============================================================");
}

inline LONG CALLBACK vectored_handler(EXCEPTION_POINTERS* ep) {
	const DWORD code = ep->ExceptionRecord->ExceptionCode;
	if (!exception_name(code))
		return EXCEPTION_CONTINUE_SEARCH;

	static volatile LONG in_handler = 0;     // no thread_local: breaks manual-mapped dlls
	if (InterlockedExchange(&in_handler, 1))
		return EXCEPTION_CONTINUE_SEARCH;

	// report every faulting address once; CS2 and our __try blocks raise handled
	// exceptions too, so only the LAST report before the game dies is the crash
	static void* seen[256];
	static volatile LONG seen_count = 0;
	void* where = ep->ExceptionRecord->ExceptionAddress;
	bool known = false;
	const LONG cnt = seen_count;
	for (LONG i = 0; i < cnt && i < 256; ++i)
		if (seen[i] == where) {
			known = true;
			break;
		}
	if (!known) {
		const LONG slot = InterlockedIncrement(&seen_count) - 1;
		if (slot < 256) {
			seen[slot] = where;
			crash_report(ep, "EXCEPTION (if CS2 closes now, this is the crash)");
		}
	}
	InterlockedExchange(&in_handler, 0);
	return EXCEPTION_CONTINUE_SEARCH;
}

inline LONG WINAPI unhandled_filter(EXCEPTION_POINTERS* ep) {
	crash_report(ep, "FATAL UNHANDLED EXCEPTION - CS2 IS CRASHING");
	return g_prev_filter ? g_prev_filter(ep) : EXCEPTION_CONTINUE_SEARCH;
}

// ---------------------------------------------------------------- manual map repair

// TEB->ThreadLocalStoragePointer (x64 TEB offset 0x58). The loader fills this in
// per thread; a manual mapper that ignores the TLS directory does not.
inline void** tls_array() {
	return reinterpret_cast<void**>(__readgsqword(0x58));
}

// x64 unwinding is table driven: RtlLookupFunctionEntry finds a module's .pdata
// through the loader's list. A manual-mapped image is not in that list, so the
// first `throw` (entry.cpp is full of try/catch) cannot be unwound and the
// process is killed outright, with nothing printed anywhere. Registering our own
// exception directory fixes that. Only done when nobody registered us already.
inline bool register_exception_table(HMODULE self) {
	if (!self || !readable(self, sizeof(IMAGE_DOS_HEADER)))
		return false;
	const auto base = reinterpret_cast<std::uintptr_t>(self);
	const auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(self);
	if (dos->e_magic != IMAGE_DOS_SIGNATURE)
		return false;
	const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(base + dos->e_lfanew);
	if (!readable(nt, sizeof(*nt)) || nt->Signature != IMAGE_NT_SIGNATURE)
		return false;
	const auto& dir = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION];
	if (!dir.VirtualAddress || dir.Size < sizeof(RUNTIME_FUNCTION))
		return false;

	// probe with an address we know is inside our own code
	DWORD64 image_base = 0;
	if (RtlLookupFunctionEntry(reinterpret_cast<DWORD64>(&register_exception_table), &image_base, nullptr))
		return false;                       // already covered, don't add a duplicate

	auto* table = reinterpret_cast<PRUNTIME_FUNCTION>(base + dir.VirtualAddress);
	const DWORD count = dir.Size / sizeof(RUNTIME_FUNCTION);
	return RtlAddFunctionTable(table, count, base) != FALSE;
}

// Reports exactly what the injector did or did not do about our TLS block.
inline void report_tls(HMODULE self) {
	if (!self || !readable(self, sizeof(IMAGE_DOS_HEADER)))
		return;
	const auto base = reinterpret_cast<std::uintptr_t>(self);
	const auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(self);
	const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(base + dos->e_lfanew);
	if (!readable(nt, sizeof(*nt)) || nt->Signature != IMAGE_NT_SIGNATURE)
		return;
	const auto& dir = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS];
	if (!dir.VirtualAddress || !dir.Size) {
		DBG_OK("tls       : image has no TLS directory - nothing to set up");
		return;
	}

	const auto* tls = reinterpret_cast<const IMAGE_TLS_DIRECTORY64*>(base + dir.VirtualAddress);
	if (!readable(tls, sizeof(*tls)))
		return;
	const auto tmpl = static_cast<unsigned long long>(tls->EndAddressOfRawData - tls->StartAddressOfRawData);
	DBG_INFO("tls       : directory present, %llu + %lu bytes per thread, index stored at %p",
	         tmpl, tls->SizeOfZeroFill, reinterpret_cast<void*>(tls->AddressOfIndex));

	const auto* idx_ptr = reinterpret_cast<const DWORD*>(tls->AddressOfIndex);
	if (!readable(idx_ptr, sizeof(DWORD)))
		return;
	const DWORD idx = *idx_ptr;
	void** arr = tls_array();
	// a garbage index must not turn this report into the crash it is diagnosing
	void* block = (arr && idx < 4096 && readable(arr + idx, sizeof(void*))) ? arr[idx] : nullptr;
	DBG_INFO("tls       : _tls_index = %lu, TEB slot = %p", idx, block);

	if (module_of(self)) {
		DBG_OK("tls       : loaded by the Windows loader, TLS is set up for us");
		return;
	}
	if (idx == 0) {
		// index 0 is whoever got TLS first - the exe, never us
		DBG_ERR("=============================================================");
		DBG_ERR("TLS WAS NOT SET UP BY YOUR INJECTOR");
		DBG_ERR("_tls_index is still 0, so every thread_local in this dll reads and writes");
		DBG_ERR("CS2's own TLS block, and the TLS callback that constructs them never ran.");
		DBG_ERR("This dll has no thread_local of its own (built with /Zc:threadSafeInit-);");
		DBG_ERR("the TLS directory comes from libprotobuf.lib, whose static initialisers");
		DBG_ERR("run before DllMain - which is why nothing is printed before the crash.");
		DBG_ERR("Fix: inject with a manual mapper that handles TLS (LdrpHandleTlsData /");
		DBG_ERR("'TLS support' option), or inject with LoadLibrary.");
		DBG_ERR("=============================================================");
		return;
	}
	if (!block)
		DBG_ERR("tls       : _tls_index = %lu but this thread has no TLS block - thread_local will fault", idx);
	else
		DBG_OK("tls       : injector set up TLS (index %lu, block %p)", idx, block);
}

// ---------------------------------------------------------------- setup

inline HANDLE open_log(const char* dir) {
	CreateDirectoryA(dir, nullptr);
	_snprintf_s(g_path, sizeof(g_path), _TRUNCATE, "%s\\debug.log", dir);
	return CreateFileA(g_path, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS,
	                   FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, nullptr);
}

// `via` names how we got here: TLS callback (earliest), static init, or DllMain.
// Whichever runs first wins; the rest are no-ops. If the log says anything other
// than "TLS callback", the injector does not call TLS callbacks.
inline void init_from(HMODULE self, const char* via) {
	if (g_initialized)
		return;
	g_initialized = true;
	g_entry_via = via;
	g_self = self;
	if (self && readable(self, sizeof(IMAGE_DOS_HEADER))) {
		const auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(self);
		const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(reinterpret_cast<const char*>(self) + dos->e_lfanew);
		if (dos->e_magic == IMAGE_DOS_SIGNATURE && readable(nt, sizeof(*nt)) && nt->Signature == IMAGE_NT_SIGNATURE)
			g_self_size = nt->OptionalHeader.SizeOfImage;
	}
	QueryPerformanceFrequency(&g_freq);
	QueryPerformanceCounter(&g_start);

	// Documents\celerity\debug.log, or %TEMP%\celerity\debug.log if that fails
	char dir[MAX_PATH];
	if (GetEnvironmentVariableA("USERPROFILE", dir, sizeof(dir))) {
		strcat_s(dir, "\\Documents\\celerity");
		g_file = open_log(dir);
	}
	if (g_file == INVALID_HANDLE_VALUE && GetTempPathA(sizeof(dir), dir)) {
		strcat_s(dir, "celerity");
		g_file = open_log(dir);
	}
	if (g_file == INVALID_HANDLE_VALUE)
		g_path[0] = '\0';

	g_veh = AddVectoredExceptionHandler(1, vectored_handler);
	g_prev_filter = SetUnhandledExceptionFilter(unhandled_filter);

	char path[MAX_PATH];
	DBG_INFO("debug log started from %s - dll built " __DATE__ " " __TIME__, g_entry_via);
	DBG_INFO("log file: %s", g_path[0] ? g_path : "<could not create>");
	DBG_INFO("our dll: %s base %p size 0x%llX%s", module_name(self, path, MAX_PATH), static_cast<void*>(self),
	         static_cast<unsigned long long>(g_self_size), module_of(self) ? "" : " (manual mapped)");

	DBG_INFO("crash handler %s", g_veh ? "installed" : "FAILED to install");

	// Things a manual-mapped dll has to sort out for itself, in this order:
	// unwinding first, so a later throw produces a message instead of a silent exit.
	if (register_exception_table(self))
		DBG_OK("unwind    : registered our own .pdata (manual map: nobody else did)");
	else
		DBG_INFO("unwind    : exception table already resolvable");
	report_tls(self);
}

inline void init(HMODULE self) {
	init_from(self, "DllMain");
}

inline void set_console(bool on) {
	g_console = on;
}

inline void shutdown() {
	if (g_veh) {
		RemoveVectoredExceptionHandler(g_veh);
		g_veh = nullptr;
	}
	if (g_prev_filter) {
		SetUnhandledExceptionFilter(g_prev_filter);
		g_prev_filter = nullptr;
	}
	g_console = false;
	if (g_file != INVALID_HANDLE_VALUE) {
		CloseHandle(g_file);
		g_file = INVALID_HANDLE_VALUE;
	}
}

} // namespace dbg
