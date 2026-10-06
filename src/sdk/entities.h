#pragma once
#include <cstdint>

namespace entities
{
	enum class Category : uint8_t
	{
		None,
		Enemy,
		Teammate,
		Local,
	};

	// Resolves an entity index (handle & 0x7FFF) to its C_BaseEntity*.
	uintptr_t get( uint32_t index );

	// Rebuilds the pawn -> category table. Called from the feature thread.
	void update( );

	// Category of an alive player pawn, or None.
	Category categoryOf( uint32_t index );
}
