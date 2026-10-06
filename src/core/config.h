#pragma once
#include <atomic>
#include <Windows.h>

// Everything the menu can change. Atomics because features run on their own thread.
namespace config
{
	inline constexpr int menuKey = VK_INSERT;
	inline constexpr int unloadKey = VK_END;

	namespace bhop
	{
		inline std::atomic_bool enabled = true;
		inline std::atomic_int key = VK_SPACE;
		inline std::atomic_int releaseDelay = 1; // ms between +jump and -jump
	}
}
