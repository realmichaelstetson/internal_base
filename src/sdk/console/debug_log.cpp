#include "debug_log.hpp"

// Start the debug log + crash handler before ANY global constructor of the dll runs
// (init_seg(lib) initializers run before the normal ones), so a crash during static
// initialization or in DllMain is logged too.
extern "C" IMAGE_DOS_HEADER __ImageBase;

#pragma warning(disable : 4073 4075)
#pragma init_seg(lib)

namespace {
struct early_init_t {
	early_init_t() {
		dbg::init(reinterpret_cast<HMODULE>(&__ImageBase));
		DBG_INFO("[attach] 1/3 early init - global constructors of the dll start now");
	}
};
early_init_t g_early_init;
}
