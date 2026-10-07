#include "vtex_parser.hpp"
#include "../../sdk/valve/interfaces/vtables/i_file_system.hpp"
#include "../../sdk/includes/stb/stb_image.h"

#include <cstring>
#include <algorithm>

namespace vtex_parser {
	enum class vtex_format : uint8_t {
		UNKNOWN   = 0,
		DXT1      = 1,
		DXT5      = 2,
		I8        = 3,
		RGBA8     = 4,
		PNG_RGBA8 = 16,
		BGRA8     = 28
	};

	enum class vtex_extra_data : uint32_t {
		UNKNOWN             = 0,
		FALLBACK_BITS       = 1,
		SHEET               = 2,
		METADATA            = 3,
		COMPRESSED_MIP_SIZE = 4,
		CUBEMAP_RADIANCE_SH = 5
	};

	struct vtex_header {
		uint16_t    version;
		uint16_t    flags;
		uint32_t    reflectivity[4];
		uint16_t    width;
		uint16_t    height;
		uint16_t    depth;
		vtex_format format;
		uint8_t     mip_count;
		uint32_t    picmip0_res;
		uint32_t    extra_data_offset;
		uint32_t    extra_data_count;
	};

	struct memstream {
		char* data;
		int   pos;

		memstream(char* d) : data(d), pos(0) {}

		void seekg(int offset) { pos += offset; }

		template <typename T = char>
		memstream& read(T* v, int n) {
			std::memcpy(v, data + pos, n * sizeof(T));
			pos += sizeof(T) * n;
			return *this;
		}

		template <typename T>
		memstream& operator>>(T& val) {
			std::memcpy(&val, data + pos, sizeof(T));
			pos += sizeof(T);
			return *this;
		}
	};

	// Minimal LZ4 block decompressor (no framing). Source 2 stores each mip as
	// an independent LZ4 block; compressed_mips[i] holds the compressed byte
	// count. Returns bytes written, or -1 on malformed input.
	static int lz4_block_decompress(const uint8_t* src, int src_len, uint8_t* dst, int dst_cap) {
		const uint8_t* s     = src;
		const uint8_t* s_end = src + src_len;
		uint8_t*       d     = dst;
		uint8_t*       d_end = dst + dst_cap;

		while (s < s_end) {
			const uint8_t token = *s++;

			int lit = token >> 4;
			if (lit == 15) {
				uint8_t b;
				do { if (s >= s_end) return -1; b = *s++; lit += b; } while (b == 255);
			}

			if (lit) {
				if (s + lit > s_end || d + lit > d_end) return -1;
				std::memcpy(d, s, lit);
				d += lit; s += lit;
			}

			if (s >= s_end) break; // literals ran to end of block: done

			if (s + 2 > s_end) return -1;
			const int offset = (int)(s[0] | (s[1] << 8));
			s += 2;
			if (offset == 0) return -1;

			int match = token & 0xF;
			if (match == 15) {
				uint8_t b;
				do { if (s >= s_end) return -1; b = *s++; match += b; } while (b == 255);
			}
			match += 4; // minmatch

			const uint8_t* m = d - offset;
			if (m < dst || d + match > d_end) return -1;
			for (int i = 0; i < match; i++) *d++ = *m++; // byte copy: handles overlap
		}
		return (int)(d - dst);
	}

	static int mip_level_size(int size, uint32_t level) {
		size >>= (int)level;
		return std::max(size, 1);
	}

	static int calculate_buffer_size_for_mip_level(uint32_t mip_level, uint32_t width, uint32_t height) {
		const auto bytes_per_pixel = 4;
		const auto width_  = mip_level_size(width, mip_level);
		const auto height_ = mip_level_size(height, mip_level);
		return width_ * height_ * 1 * bytes_per_pixel;
	}

	static int skip_mipmaps(int desired_mip_level, int num_mip_levels, int width, int height, int* compressed_mips) {
		if (num_mip_levels < 2)
			return 0;

		int size_ = 0;
		for (int j = num_mip_levels - 1; j > desired_mip_level; j--) {
			int size = calculate_buffer_size_for_mip_level(j, width, height);
			if (compressed_mips) {
				int compressed_size = compressed_mips[j];
				if (size > compressed_size)
					size = compressed_size;
			}
			size_ += size;
		}
		return size_;
	}

	vtex_data load(std::string_view filename, i_file_system* file_system) {
		vtex_data result;

		if (!file_system)
			return result;

		auto handle = file_system->open(filename.data(), "r", "GAME");
		if (!handle)
			return result;

		const int size = (int)file_system->size(handle);
		if (size <= 0) {
			file_system->close(handle);
			return result;
		}

		std::vector<char> image(size);
		file_system->read(image.data(), size, handle);
		file_system->close(handle);

		if (image.empty())
			return result;

		// locate the "DATA" resource block header offset.
		int hdr_pos = 0;
		for (int i = 0; i + 8 <= (int)image.size(); i++) {
			if (*(uint32_t*)(image.data() + i) == 0x41544144) { // 'DATA'
				hdr_pos = *(uint32_t*)(image.data() + i + 4) + i + 4;
				break;
			}
		}

		if (hdr_pos <= 0 || hdr_pos + (int)sizeof(vtex_header) > (int)image.size())
			return result;

		memstream s(image.data());
		s.pos = hdr_pos;

		vtex_header hdr;
		s >> hdr;

		std::vector<int> compressed_mips;
		auto actual_width  = hdr.width;
		auto actual_height = hdr.height;
		uint32_t mips = 0;
		int extra_data_size = 0;

		if (hdr.extra_data_count > 0) {
			s.seekg(hdr.extra_data_offset - 8);

			for (uint32_t i = 0; i < hdr.extra_data_count; i++) {
				vtex_extra_data type{};
				int offset = 0, size_data = 0;
				s >> type >> offset >> size_data;
				offset -= 8;

				extra_data_size += size_data;

				const auto prev_offset = s.pos;
				s.pos += offset;

				if (type == vtex_extra_data::METADATA) {
					s.pos += 2;
					uint16_t nw, nh;
					s >> nw >> nh;
					if (nw > 0 && nh > 0 && actual_width >= nw && actual_height >= nh) {
						actual_width  = nw;
						actual_height = nh;
					}
				} else if (type == vtex_extra_data::COMPRESSED_MIP_SIZE) {
					uint32_t int1, mips_offset;
					s >> int1 >> mips_offset >> mips;

					compressed_mips.resize(mips);
					s.pos += mips_offset - 8;

					for (uint32_t mip = 0; mip < mips; mip++)
						s >> compressed_mips[mip];
				}

				s.pos = prev_offset;
			}
		}

		s.pos += extra_data_size;

		int* mips_ptr = compressed_mips.empty() ? nullptr : compressed_mips.data();
		// NOTE: pass actual_width for BOTH width and height, exactly like the
		// proven-working yougey decoder. This looks like a bug but it is what the
		// reference does; the resulting byte offset is what lands on the embedded
		// PNG. Do NOT "fix" this to actual_height.
		s.pos += skip_mipmaps(0, mips, actual_width, actual_width, mips_ptr);

		result.w = actual_width;
		result.h = actual_height;

		// Econ icons: despite the "_png" asset name, the compiled vtex is often
		// raw BGRA8 (28) / RGBA8 (4), NOT an embedded PNG -- and usually LZ4
		// mip-compressed. Do NOT trust s.pos here: skip_mipmaps() is tuned for
		// the PNG path (it passes actual_width for BOTH dims) and lands in the
		// wrong place for this format. Instead anchor on the END of the file:
		// mips are stored smallest-first, so mip 0 (full-res) is the LAST block,
		// and its on-disk length is compressed_mips[0] (or the full uncompressed
		// size when the COMPRESSED_MIP_SIZE block is absent / stored verbatim).
		if (hdr.format == vtex_format::BGRA8 || hdr.format == vtex_format::RGBA8) {
			const int px   = actual_width * actual_height;
			const int need = px * 4;
			if (need <= 0)
				return result;

			const int mip0len = (!compressed_mips.empty() && compressed_mips[0] > 0)
			                  ? compressed_mips[0] : need;

			if (mip0len > (int)image.size())
				return result;

			// mip 0 sits at the very end of the file.
			const uint8_t* src = (const uint8_t*)image.data() + ((int)image.size() - mip0len);

			std::vector<uint8_t> raw;
			if (mip0len == need) {
				raw.assign(src, src + need); // stored uncompressed
			} else {
				raw.resize((size_t)need);
				if (lz4_block_decompress(src, mip0len, raw.data(), need) != need)
					return result;
			}

			result.data.resize((size_t)need);
			if (hdr.format == vtex_format::BGRA8) {
				for (int i = 0; i < px; i++) {
					result.data[i * 4 + 0] = raw[i * 4 + 2]; // R <- B
					result.data[i * 4 + 1] = raw[i * 4 + 1]; // G
					result.data[i * 4 + 2] = raw[i * 4 + 0]; // B <- R
					result.data[i * 4 + 3] = raw[i * 4 + 3]; // A
				}
			} else {
				std::memcpy(result.data.data(), raw.data(), (size_t)need);
			}
			return result;
		}

		// only the panorama econ PNG variant is decoded via stb.
		if (hdr.format != vtex_format::PNG_RGBA8)
			return result;

		auto input_data = s.pos + s.data;
		auto data_size  = (int)image.size() - s.pos;
		if (data_size <= 0)
			return result;

		int x{}, y{}, comp{};
		stbi_set_flip_vertically_on_load(0);
		stbi_uc* png = stbi_load_from_memory((stbi_uc*)input_data, data_size, &x, &y, &comp, 4);
		if (!png)
			return result;

		result.w = x;
		result.h = y;
		result.data.resize((size_t)x * y * 4);
		std::memcpy(result.data.data(), png, (size_t)x * y * 4);
		stbi_image_free(png);

		return result;
	}
}
