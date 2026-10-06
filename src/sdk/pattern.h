#pragma once
#include <cstdint>

namespace pattern
{
	// Scans a loaded module for an IDA-style pattern ("48 8B ?? 05"). Returns 0 if not found.
	uintptr_t find( const char* module, const char* signature );
}
