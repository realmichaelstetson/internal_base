#include "debug_log.hpp"

extern "C" IMAGE_DOS_HEADER __ImageBase;

// Three entry points, earliest first. Whichever runs first starts the log; the
// others are no-ops. The first log line names the one that won, which says how
// far the dll actually got before it died.
//
//   1. TLS callback  - .CRT$XLB sorts before the CRT's own __dyn_tls_init in
//                      .CRT$XLC, so this is the very first code of ours to run,
//                      ahead of every static initialiser and ahead of DllMain.
//                      It only fires if the injector calls TLS callbacks at all.
//   2. static init   - init_seg(lib) runs before the normal global constructors,
//                      libprotobuf's descriptor registration included.
//   3. DllMain       - see entry.cpp.
//
// If no log file appears at all, none of the three ran: the image is not being
// executed (wrong / stale dll), or it dies in the loader before reaching us.

static void NTAPI tls_startup(PVOID, DWORD reason, PVOID) {
	if (reason == DLL_PROCESS_ATTACH)
		dbg::init_from(reinterpret_cast<HMODULE>(&__ImageBase), "TLS callback");
}

#pragma comment(linker, "/INCLUDE:_tls_used")
#pragma comment(linker, "/INCLUDE:p_celerity_tls_cb")
#pragma const_seg(".CRT$XLB")
extern "C" const PIMAGE_TLS_CALLBACK p_celerity_tls_cb = tls_startup;
#pragma const_seg()

#pragma warning(disable : 4073 4075)
#pragma init_seg(lib)

namespace {
struct early_init_t {
	early_init_t() {
		dbg::init_from(reinterpret_cast<HMODULE>(&__ImageBase), "static init");
	}
};
early_init_t g_early_init;
}
