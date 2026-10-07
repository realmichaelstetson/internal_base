#include "hit_sound.hpp"
#include "../../config.hpp"
#include <Windows.h>
#include <mmsystem.h>
#include <algorithm>
#include <cmath>
#include <cstring>

#pragma comment(lib, "winmm.lib")

std::uint16_t c_hit_sound::read_le16(const std::uint8_t* data) {
    return static_cast<std::uint16_t>(data[0] | (data[1] << 8));
}

std::uint32_t c_hit_sound::read_le32(const std::uint8_t* data) {
    return static_cast<std::uint32_t>(data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24));
}

bool c_hit_sound::is_supported_format(const WAVEFORMATEX& format) {
    if (format.wFormatTag == WAVE_FORMAT_PCM)
        return format.wBitsPerSample == 8 || format.wBitsPerSample == 16 || format.wBitsPerSample == 32;
    constexpr WORD WAVE_FORMAT_IEEE_FLOAT_LOCAL = 0x0003;
    return format.wFormatTag == WAVE_FORMAT_IEEE_FLOAT_LOCAL && format.wBitsPerSample == 32;
}

struct hit_sound_entry_t {
    const unsigned char* data;
    std::uint64_t size;
};

static hit_sound_entry_t get_sound_data(int type) {
    switch (type) {
    case 1:
        return { hitsound::g_bell_wav_data, hitsound::g_bell_wav_size };
    case 2:
        return { hitsound::g_neverlose_wav_data, hitsound::g_neverlose_wav_size };
    case 3:
        return { hitsound::g_bubble_wav_data, hitsound::g_bubble_wav_size };
    case 4:
        return { hitsound::g_metal_wav_data, hitsound::g_metal_wav_size };
    case 5:
        return { hitsound::g_rust_headshot_wav_data, hitsound::g_rust_headshot_wav_size };
    case 6:
        return { hitsound::g_agpa2_wav_data, hitsound::g_agpa2_wav_size };
    default:
        return { hitsound::g_hit_wav_data, hitsound::g_hit_wav_size };
    }
}

bool c_hit_sound::parse_cache(cache_t& cache, int type) {
    auto entry = get_sound_data(type);
    const auto* wav = entry.data;
    const std::size_t wav_size = static_cast<std::size_t>(entry.size);

    if (!wav || wav_size < 44 || std::memcmp(wav, "RIFF", 4) != 0 || std::memcmp(wav + 8, "WAVE", 4) != 0)
        return false;

    WAVEFORMATEX format{};
    const std::uint8_t* sample_data = nullptr;
    std::uint32_t sample_size = 0;

    for (std::size_t offset = 12; offset + 8 <= wav_size;) {
        const auto* chunk = wav + offset;
        const std::uint32_t chunk_size = read_le32(chunk + 4);
        const std::size_t data_offset = offset + 8;
        const std::size_t next_offset = data_offset + chunk_size + (chunk_size & 1);

        if (data_offset + chunk_size > wav_size)
            break;

        if (std::memcmp(chunk, "fmt ", 4) == 0 && chunk_size >= 16) {
            format.wFormatTag = read_le16(wav + data_offset);
            format.nChannels = read_le16(wav + data_offset + 2);
            format.nSamplesPerSec = read_le32(wav + data_offset + 4);
            format.nAvgBytesPerSec = read_le32(wav + data_offset + 8);
            format.nBlockAlign = read_le16(wav + data_offset + 12);
            format.wBitsPerSample = read_le16(wav + data_offset + 14);
            format.cbSize = 0;
        }
        else if (std::memcmp(chunk, "data", 4) == 0) {
            sample_data = wav + data_offset;
            sample_size = chunk_size;
        }

        offset = next_offset;
    }

    if (format.nChannels == 0 || format.nSamplesPerSec == 0 || format.nBlockAlign == 0 ||
        !sample_data || sample_size == 0 || !is_supported_format(format))
        return false;

    cache.format = format;
    cache.samples.assign(sample_data, sample_data + sample_size);
    return true;
}

bool c_hit_sound::get_cache(hit_sound_playback_t& playback, int type) {
    std::lock_guard<std::mutex> lock(m_mutex);

    if (!m_cache.parsed || m_cache.type != type) {
        m_cache.parsed = false;
        m_cache.valid = parse_cache(m_cache, type);
        m_cache.type = type;
        m_cache.parsed = true;
    }

    if (!m_cache.valid)
        return false;

    playback.format = m_cache.format;
    playback.samples = m_cache.samples;
    return true;
}

bool c_hit_sound::make_playback(float volume, hit_sound_playback_t& playback, int type) {
    if (!get_cache(playback, type))
        return false;

    const float gain = std::clamp(volume, 0.0f, 100.0f) / 42.0f;
    if (gain <= 0.0f)
        return false;

    const WAVEFORMATEX& format = playback.format;
    if (format.wFormatTag == WAVE_FORMAT_PCM && format.wBitsPerSample == 8) {
        for (auto& sample : playback.samples) {
            const int centered = static_cast<int>(sample) - 128;
            const int scaled = static_cast<int>(std::round(centered * gain)) + 128;
            sample = static_cast<std::uint8_t>(std::clamp(scaled, 0, 255));
        }
    }
    else if (format.wFormatTag == WAVE_FORMAT_PCM && format.wBitsPerSample == 16) {
        const std::size_t count = playback.samples.size() / sizeof(std::int16_t);
        auto* samples = reinterpret_cast<std::int16_t*>(playback.samples.data());
        for (std::size_t i = 0; i < count; i++) {
            const int scaled = static_cast<int>(std::round(samples[i] * gain));
            samples[i] = static_cast<std::int16_t>(std::clamp(scaled, -32768, 32767));
        }
    }
    else if (format.wFormatTag == WAVE_FORMAT_PCM && format.wBitsPerSample == 32) {
        const std::size_t count = playback.samples.size() / sizeof(std::int32_t);
        auto* samples = reinterpret_cast<std::int32_t*>(playback.samples.data());
        for (std::size_t i = 0; i < count; i++) {
            const double scaled = static_cast<double>(samples[i]) * gain;
            samples[i] = static_cast<std::int32_t>(std::clamp(scaled, -2147483648.0, 2147483647.0));
        }
    }
    else {
        const std::size_t count = playback.samples.size() / sizeof(float);
        auto* samples = reinterpret_cast<float*>(playback.samples.data());
        for (std::size_t i = 0; i < count; i++)
            samples[i] = std::clamp(samples[i] * gain, -1.0f, 1.0f);
    }

    return true;
}

bool c_hit_sound::should_skip_simultaneous() {
    constexpr LONG64 simultaneous_window_ms = 8;
    const LONG64 now_ms = static_cast<LONG64>(GetTickCount64());

    for (;;) {
        const LONG64 last_ms = InterlockedCompareExchange64(&m_last_start_ms, 0, 0);
        if (now_ms - last_ms <= simultaneous_window_ms)
            return true;

        if (InterlockedCompareExchange64(&m_last_start_ms, now_ms, last_ms) == last_ms)
            return false;

        YieldProcessor();
    }
}

struct play_thread_params_t {
    hit_sound_playback_t playback;
    int type;
};

static DWORD WINAPI play_thread(LPVOID param) {
    auto* args = static_cast<play_thread_params_t*>(param);
    if (!args)
        return 0;

    auto entry = get_sound_data(args->type);

    HWAVEOUT wave_out = nullptr;
    if (waveOutOpen(&wave_out, WAVE_MAPPER, &args->playback.format, 0, 0, CALLBACK_NULL) == MMSYSERR_NOERROR) {
        WAVEHDR header{};
        header.lpData = reinterpret_cast<LPSTR>(args->playback.samples.data());
        header.dwBufferLength = static_cast<DWORD>(args->playback.samples.size());

        if (waveOutPrepareHeader(wave_out, &header, sizeof(header)) == MMSYSERR_NOERROR) {
            if (waveOutWrite(wave_out, &header, sizeof(header)) == MMSYSERR_NOERROR) {
                while (!(header.dwFlags & WHDR_DONE))
                    Sleep(1);
            }
            waveOutUnprepareHeader(wave_out, &header, sizeof(header));
        }
        waveOutClose(wave_out);
    }
    else {
        PlaySoundA(reinterpret_cast<LPCSTR>(entry.data), nullptr, SND_MEMORY | SND_NODEFAULT | SND_SYNC);
    }

    delete args;
    return 0;
}

static DWORD WINAPI warm_thread(LPVOID param) {
    auto* self = static_cast<c_hit_sound*>(param);
    hit_sound_playback_t playback{};
    if (self->get_cache(playback, self->m_warm_type)) {
        HWAVEOUT wave_out = nullptr;
        if (waveOutOpen(&wave_out, WAVE_MAPPER, &playback.format, 0, 0, CALLBACK_NULL) == MMSYSERR_NOERROR)
            waveOutClose(wave_out);
    }
    InterlockedExchange(&self->m_warm_state, 2);
    return 0;
}

void c_hit_sound::warm_async(int type) {
    if (InterlockedCompareExchange(&m_warm_state, 1, 0) != 0)
        return;

    m_warm_type = type;
    HANDLE thread = CreateThread(nullptr, 0, warm_thread, this, 0, nullptr);
    if (thread)
        CloseHandle(thread);
    else
        InterlockedExchange(&m_warm_state, 0);
}

void c_hit_sound::play(int type) {
    if (!g_cfg || !g_cfg->misc.m_sounds || g_cfg->misc.m_sounds_volume <= 0.0f)
        return;

    if (should_skip_simultaneous())
        return;

    auto* args = new play_thread_params_t();
    args->type = type;
    if (!make_playback(g_cfg->misc.m_sounds_volume, args->playback, type)) {
        delete args;
        return;
    }

    HANDLE thread = CreateThread(nullptr, 0, play_thread, args, 0, nullptr);
    if (thread)
        CloseHandle(thread);
    else
        delete args;
}
