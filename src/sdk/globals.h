#pragma once
#include <atomic>
#include <cstdint>

namespace globals
{
	inline uintptr_t client = 0;          // client.dll base
	inline std::atomic_bool running = true;
	inline std::atomic_bool menuOpen = true;
}
