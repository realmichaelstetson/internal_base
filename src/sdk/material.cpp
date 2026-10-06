#include "material.h"

#include <Windows.h>
#include <cstdint>
#include <cstdlib>

#include "offsets.h"
#include "pattern.h"

namespace
{
	struct KV3ID
	{
		const char* name;
		uint64_t unk0;
		uint64_t unk1;
	};

	// KeyValues3 is ~0x110 bytes, but the game writes before the object too - give it room
	constexpr size_t KV3_PADDING = 0x100;
	constexpr size_t KV3_SIZE = 0x110;

	using LoadKV3Fn = bool( __fastcall* )( void* kv, void* error, const char* buffer, const KV3ID* id, const char* unk, unsigned int flags );
	using CreateMaterialFn = void( __fastcall* )( void* system, void** out, const char* name, void* kv, int unk0, int unk1 );

	LoadKV3Fn loadKV3 = nullptr;
	CreateMaterialFn createMaterial = nullptr;
}

bool material::init( )
{
	if ( const HMODULE tier0 = GetModuleHandleA( "tier0.dll" ) )
		loadKV3 = reinterpret_cast< LoadKV3Fn >( GetProcAddress( tier0, patterns::loadKV3 ) );

	createMaterial = reinterpret_cast< CreateMaterialFn >( pattern::find( "materialsystem2.dll", patterns::createMaterial ) );

	return loadKV3 && createMaterial;
}

void* material::create( const char* name, const char* kv3 )
{
	if ( !loadKV3 || !createMaterial )
		return nullptr;

	// intentionally leaked - the material keeps referencing it
	auto buffer = static_cast< uint8_t* >( calloc( 1, KV3_PADDING + KV3_SIZE ) );
	if ( !buffer )
		return nullptr;
	void* kv = buffer + KV3_PADDING;

	const KV3ID id{ "generic", 0x469806E97412167CULL, 0xE73790B53EE6F2AFULL };
	if ( !loadKV3( kv, nullptr, kv3, &id, nullptr, 0 ) )
		return nullptr;

	// the out value is a resource binding whose first field is the CMaterial2*
	void* binding = nullptr;
	createMaterial( nullptr, &binding, name, kv, 0, 1 );
	return binding;
}
