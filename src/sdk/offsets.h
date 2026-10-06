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
	constexpr std::ptrdiff_t dwEntityList = 0x2717828;

	// client_dll.hpp
	constexpr std::ptrdiff_t m_fFlags = 0x3F4;                    // C_BaseEntity
	constexpr std::ptrdiff_t m_iHealth = 0x34C;                   // C_BaseEntity
	constexpr std::ptrdiff_t m_lifeState = 0x354;                 // C_BaseEntity
	constexpr std::ptrdiff_t m_iTeamNum = 0x3E7;                  // C_BaseEntity
	constexpr std::ptrdiff_t m_hOwnerEntity = 0x520;              // C_BaseEntity
	constexpr std::ptrdiff_t m_bIsLocalPlayerController = 0x790;  // CBasePlayerController
	constexpr std::ptrdiff_t m_hPlayerPawn = 0x92C;               // CCSPlayerController
}

// Not covered by cs2-dumper - reversed by hand (scenesystem.dll / CGameEntitySystem).
namespace offsets::manual
{
	constexpr std::ptrdiff_t entityListBuckets = 0x10;  // CGameEntitySystem -> CEntityIdentity* buckets[64]
	constexpr std::ptrdiff_t entityIdentitySize = 0x70; // sizeof(CEntityIdentity)
	constexpr std::ptrdiff_t sceneObjectOwner = 0xB8;   // CSceneObject::m_hOwner
}

// IDA-style signatures - from https://cspatterns.dev/cpp (last updated 24/09/2026)
namespace patterns
{
	// scenesystem.dll - CANIMATABLESCENEOBJECTDESCRENDER (renders player/weapon models)
	constexpr const char* drawObject = "48 8B C4 48 89 50 ? 48 89 48 ? 53 56";

	// materialsystem2.dll - CREATEMATERIAL
	constexpr const char* createMaterial = "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 8B F2";

	// tier0.dll export - LOADKV3_PROC_ADDRESS
	constexpr const char* loadKV3 = "?LoadKV3@@YA_NPEAVKeyValues3@@PEAVCUtlString@@PEBDAEBUKV3ID_t@@2I@Z";
}
