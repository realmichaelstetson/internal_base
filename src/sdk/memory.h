#pragma once
#include <Windows.h>
#include <cstdint>

namespace memory
{
	// Reads a value without crashing the game if the address is bad.
	template <typename T>
	inline bool read( uintptr_t address, T& out )
	{
		if ( !address )
			return false;

#ifdef _MSC_VER
		__try
		{
			out = *reinterpret_cast< T* >( address );
			return true;
		}
		__except ( EXCEPTION_EXECUTE_HANDLER )
		{
			return false;
		}
#else
		out = *reinterpret_cast< T* >( address );
		return true;
#endif
	}

	template <typename T>
	inline void write( uintptr_t address, const T& value )
	{
		if ( address )
			*reinterpret_cast< T* >( address ) = value;
	}
}
