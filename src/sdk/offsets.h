#pragma once
#include <cstddef>

// Offsets are taken from https://github.com/a2x/cs2-dumper
// They change with almost every CS2 update - refresh them after each patch.
// Last updated: cs2-dumper 2026-10-06, game build 14189
namespace offsets
{
	// buttons.hpp
	constexpr std::ptrdiff_t jump = 0x22324E0;

	// offsets.hpp
	constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x2562808;

	// client_dll.hpp (C_BaseEntity)
	constexpr std::ptrdiff_t m_fFlags = 0x3F4;
}
