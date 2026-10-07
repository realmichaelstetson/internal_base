#pragma once
#include "embedded_hit_sound.hpp"
#include "embedded_bell_sound.hpp"
#include "embedded_neverlose_sound.hpp"
#include "embedded_bubble_sound.hpp"
#include "embedded_metal_sound.hpp"
#include "embedded_rust_headshot_sound.hpp"
#include "embedded_agpa2_sound.hpp"
#include <cstdint>
#include <vector>
#include <mutex>
#include <Windows.h>
#include <mmsystem.h>
#include <memory>

struct hit_sound_playback_t {
	WAVEFORMATEX format{};
	std::vector<std::uint8_t> samples;
};

class c_hit_sound {
public:
	void warm_async(int type);
	void play(int type);
	bool get_cache(hit_sound_playback_t& playback, int type);

	volatile LONG m_warm_state = 0;
	int m_warm_type = 0;

private:
	struct cache_t {
		WAVEFORMATEX format{};
		std::vector<std::uint8_t> samples;
		bool parsed = false;
		bool valid = false;
		int type = -1;
	};

	std::mutex m_mutex;
	cache_t m_cache;
	volatile LONG64 m_last_start_ms = 0;

	static std::uint16_t read_le16(const std::uint8_t* data);
	static std::uint32_t read_le32(const std::uint8_t* data);
	static bool is_supported_format(const WAVEFORMATEX& format);
	bool parse_cache(cache_t& cache, int type);
	bool make_playback(float volume, hit_sound_playback_t& playback, int type);
	bool should_skip_simultaneous();
};

inline auto g_hit_sound = std::make_unique<c_hit_sound>();
