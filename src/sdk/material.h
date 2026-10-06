#pragma once

namespace material
{
	bool init( );

	// Compiles a .vmat (KV3 text) buffer into a CMaterial2.
	// Returns the resource binding (first field = CMaterial2*) or nullptr.
	void* create( const char* name, const char* kv3 );
}
