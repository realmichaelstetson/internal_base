#include <Windows.h>
#include <thread>

#include "core/config.h"
#include "core/hooks.h"
#include "features/bhop.h"
#include "features/chams.h"
#include "sdk/entities.h"
#include "sdk/globals.h"

namespace
{
	DWORD WINAPI mainThread( LPVOID instance )
	{
		// wait until the game has loaded client.dll
		while ( !( globals::client = reinterpret_cast< uintptr_t >( GetModuleHandleA( "client.dll" ) ) ) )
			Sleep( 200 );

		if ( !hooks::init( ) )
		{
			MessageBoxA( nullptr, "Failed to hook DirectX 11.\nMake sure the game runs with the DX11 renderer.", "cs2 internal", MB_ICONERROR );
			hooks::shutdown( );
			FreeLibraryAndExitThread( static_cast< HMODULE >( instance ), 0 );
		}

		if ( hooks::chamsHooked( ) )
			features::chams::init( );

		// feature loop - runs on its own thread like the original bhop
		ULONGLONG lastEntityUpdate = 0;
		while ( globals::running )
		{
			if ( GetAsyncKeyState( config::unloadKey ) & 1 )
				globals::running = false;

			// refresh who is an enemy / teammate for the chams
			if ( GetTickCount64( ) - lastEntityUpdate >= 10 )
			{
				entities::update( );
				lastEntityUpdate = GetTickCount64( );
			}

			features::bhop::run( );
			Sleep( 1 );
		}

		hooks::shutdown( );
		FreeLibraryAndExitThread( static_cast< HMODULE >( instance ), 0 );
	}
}

BOOL APIENTRY DllMain( HMODULE instance, DWORD reason, LPVOID )
{
	if ( reason == DLL_PROCESS_ATTACH )
	{
		DisableThreadLibraryCalls( instance );

		if ( const HANDLE thread = CreateThread( nullptr, 0, mainThread, instance, 0, nullptr ) )
			CloseHandle( thread );
	}

	return TRUE;
}
