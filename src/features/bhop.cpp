#include "bhop.h"

#include "../core/config.h"
#include "../sdk/globals.h"
#include "../sdk/memory.h"
#include "../sdk/offsets.h"

namespace
{
	// Values CS2 stores in the button struct
	constexpr int JUMP_PRESS = 65537;
	constexpr int JUMP_RELEASE = 256;
	constexpr int FL_ONGROUND = 1 << 0;
}

void features::bhop::run( )
{
	if ( !config::bhop::enabled || !globals::client )
		return;

	// don't jump while clicking around in the menu
	if ( globals::menuOpen )
		return;

	if ( !( GetAsyncKeyState( config::bhop::key ) & 0x8000 ) )
		return;

	uintptr_t localPlayer = 0;
	if ( !memory::read( globals::client + offsets::dwLocalPlayerPawn, localPlayer ) || !localPlayer )
		return;

	int flags = 0;
	if ( !memory::read( localPlayer + offsets::m_fFlags, flags ) )
		return;

	if ( !( flags & FL_ONGROUND ) )
		return;

	// jump
	memory::write( globals::client + offsets::jump, JUMP_PRESS );
	Sleep( config::bhop::releaseDelay );
	// tell cs2 we released jump even though the key is still held
	memory::write( globals::client + offsets::jump, JUMP_RELEASE );
}
