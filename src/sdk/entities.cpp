#include "entities.h"

#include <array>
#include <vector>

#include "globals.h"
#include "memory.h"
#include "offsets.h"

namespace
{
	constexpr uint32_t MAX_ENTITIES = 0x8000;
	constexpr uint32_t MAX_PLAYERS = 64;

	// written by the feature thread, read by the render thread - single bytes, no locking needed
	std::array<volatile entities::Category, MAX_ENTITIES> table{ };
	std::vector<uint32_t> marked;
}

uintptr_t entities::get( uint32_t index )
{
	index &= 0x7FFF;

	uintptr_t list = 0;
	if ( !memory::read( globals::client + offsets::dwEntityList, list ) || !list )
		return 0;

	uintptr_t bucket = 0;
	if ( !memory::read( list + offsets::manual::entityListBuckets + sizeof( uintptr_t ) * ( index >> 9 ), bucket ) || !bucket )
		return 0;

	uintptr_t entity = 0;
	memory::read( bucket + offsets::manual::entityIdentitySize * ( index & 0x1FF ), entity );
	return entity;
}

void entities::update( )
{
	std::vector<std::pair<uint32_t, Category>> current;
	current.reserve( MAX_PLAYERS );

	uint8_t localTeam = 0;
	for ( uint32_t i = 1; i <= MAX_PLAYERS; ++i )
	{
		const uintptr_t controller = get( i );
		if ( !controller )
			continue;

		uint32_t pawnHandle = 0;
		if ( !memory::read( controller + offsets::m_hPlayerPawn, pawnHandle ) || pawnHandle == 0xFFFFFFFF )
			continue;

		const uintptr_t pawn = get( pawnHandle );
		if ( !pawn )
			continue;

		int health = 0;
		uint8_t lifeState = 1, team = 0;
		bool isLocal = false;
		memory::read( pawn + offsets::m_iHealth, health );
		memory::read( pawn + offsets::m_lifeState, lifeState );
		memory::read( pawn + offsets::m_iTeamNum, team );
		memory::read( controller + offsets::m_bIsLocalPlayerController, isLocal );

		if ( health <= 0 || lifeState != 0 )
			continue;

		if ( isLocal )
			localTeam = team;

		// store team for now, resolve enemy/teammate once the local team is known
		current.emplace_back( pawnHandle & 0x7FFF, isLocal ? Category::Local : static_cast< Category >( team ) );
	}

	for ( auto& [index, category] : current )
	{
		if ( category == Category::Local )
			continue;
		const uint8_t team = static_cast< uint8_t >( category );
		category = ( team == localTeam ) ? Category::Teammate : Category::Enemy;
	}

	// clear stale entries first, then write the new ones (no flicker for players that stay)
	for ( const uint32_t index : marked )
	{
		bool stillThere = false;
		for ( const auto& entry : current )
			stillThere |= entry.first == index;
		if ( !stillThere )
			table[ index ] = Category::None;
	}

	marked.clear( );
	for ( const auto& [index, category] : current )
	{
		table[ index ] = category;
		marked.push_back( index );
	}
}

entities::Category entities::categoryOf( uint32_t index )
{
	return table[ index & 0x7FFF ];
}
