#pragma once

#include <vector>
#include <cstdint>
#include <string_view>

class i_file_system;

// Minimal Source 2 .vtex_c reader for the panorama econ "*_png.vtex_c"
// skin/glove/agent icons used by the skin preview. Decodes the PNG_RGBA8
// sub-format (via stb) plus raw and LZ4-mip-compressed BGRA8/RGBA8 (which is
// what most econ icons actually are, despite the "_png" asset name). DXT and
// other formats return empty.
namespace vtex_parser {
	struct vtex_data {
		std::vector<uint8_t> data; // tightly packed RGBA8, w*h*4 bytes
		int w = 0;
		int h = 0;
	};

	vtex_data load(std::string_view filename, i_file_system* file_system);
}
