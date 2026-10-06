#pragma once
#include <cstddef>

// Offsets are taken from https://github.com/a2x/cs2-dumper
// They change with almost every CS2 update - refresh them after each patch.
namespace offsets
{
	// buttons.hpp
	constexpr std::ptrdiff_t jump = 0x20BA010;

	// offsets.hpp
	constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x23CCC08;

	// client_dll.hpp (C_BaseEntity)
	constexpr std::ptrdiff_t m_fFlags = 0x3F4;
}
