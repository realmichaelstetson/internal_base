#include "pattern.h"

#include <Windows.h>
#include <vector>

namespace
{
	std::vector<int> parse( const char* signature )
	{
		std::vector<int> bytes;
		for ( const char* c = signature; *c; )
		{
			if ( *c == ' ' )
			{
				++c;
				continue;
			}

			if ( *c == '?' )
			{
				bytes.push_back( -1 );
				while ( *c == '?' )
					++c;
				continue;
			}

			bytes.push_back( static_cast< int >( strtoul( c, const_cast< char** >( &c ), 16 ) ) );
		}
		return bytes;
	}
}

uintptr_t pattern::find( const char* module, const char* signature )
{
	const auto base = reinterpret_cast< uint8_t* >( GetModuleHandleA( module ) );
	if ( !base )
		return 0;

	const auto dos = reinterpret_cast< IMAGE_DOS_HEADER* >( base );
	const auto nt = reinterpret_cast< IMAGE_NT_HEADERS* >( base + dos->e_lfanew );
	const size_t size = nt->OptionalHeader.SizeOfImage;

	const std::vector<int> bytes = parse( signature );
	const size_t count = bytes.size( );
	if ( !count || count > size )
		return 0;

	for ( size_t i = 0; i < size - count; ++i )
	{
		bool found = true;
		for ( size_t j = 0; j < count; ++j )
		{
			if ( bytes[ j ] != -1 && base[ i + j ] != bytes[ j ] )
			{
				found = false;
				break;
			}
		}

		if ( found )
			return reinterpret_cast< uintptr_t >( base + i );
	}

	return 0;
}
