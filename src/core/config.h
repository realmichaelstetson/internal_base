#pragma once
#include <atomic>
#include <Windows.h>

// Everything the menu can change.
// Bhop values are atomics because the bhop runs on its own thread; chams are only read on the render thread.
namespace config
{
	inline constexpr int menuKey = VK_INSERT;
	inline constexpr int unloadKey = VK_END;

	namespace bhop
	{
		inline std::atomic_bool enabled = true;
		inline std::atomic_int key = VK_SPACE;
		inline std::atomic_int releaseDelay = 1; // ms between +jump and -jump
	}

	namespace chams
	{
		enum Material : int
		{
			Flat,
			Textured,
			Metallic,
			Glow,
			Illuminate,
			Ghost,
			Original, // keep the game texture, only tint it (visible layer only)
			MaterialCount
		};

		inline constexpr const char* materialNames[ MaterialCount ] = {
			"Flat", "Textured", "Metallic", "Glow", "Illuminate", "Ghost", "Original (tint)"
		};

		struct Layer
		{
			bool enabled = false;
			int material = Flat;
			float color[ 4 ] = { 1.f, 1.f, 1.f, 1.f };
			bool rainbow = false; // cycle hue over time
			bool pulse = false;   // breathe alpha over time
		};

		struct Group
		{
			Layer visible;   // drawn where the model is visible
			Layer hidden;    // drawn through walls (ignore-z)
			Layer overlay;   // extra pass on top (glow, illuminate...)
			bool overlayThroughWalls = false;
		};

		enum Target : int
		{
			Enemies,
			Teammates,
			LocalPlayer,
			Weapons,
			Viewmodel,
			TargetCount
		};

		inline constexpr const char* targetNames[ TargetCount ] = { "Enemies", "Teammates", "Local player", "Weapons", "Viewmodel" };

		inline bool enabled = true;
		inline Group groups[ TargetCount ] = {
			// enemies: purple visible, red through walls
			{ { true, Textured, { 0.66f, 0.33f, 0.97f, 1.f } }, { true, Flat, { 0.94f, 0.27f, 0.27f, 0.85f } }, { false, Glow, { 1.f, 1.f, 1.f, 0.6f } } },
			{ { false, Textured, { 0.13f, 0.77f, 0.37f, 1.f } }, { false, Flat, { 0.06f, 0.73f, 0.51f, 0.6f } }, { false, Glow, { 1.f, 1.f, 1.f, 0.6f } } },
			{ { false, Glow, { 0.38f, 0.65f, 0.98f, 0.8f } }, { }, { false, Glow, { 1.f, 1.f, 1.f, 0.6f } } },
			{ { false, Illuminate, { 0.98f, 0.8f, 0.08f, 1.f } }, { false, Flat, { 0.98f, 0.8f, 0.08f, 0.6f } }, { false, Glow, { 1.f, 1.f, 1.f, 0.6f } } },
			{ { false, Metallic, { 0.9f, 0.9f, 0.95f, 1.f } }, { }, { false, Glow, { 0.66f, 0.33f, 0.97f, 0.7f } } },
		};
	}
}
