#pragma once
#include <cstdint>
#include <array>

namespace pixel_font_5x5 {
    struct glyph_t {
        uint8_t width;
        uint8_t height;
        uint8_t rows[6];
    };

    namespace detail {
        constexpr auto make_table() {
            std::array<glyph_t, 128> table{};
            auto set = [&](char c, uint8_t w, uint8_t h,
                           uint8_t r0, uint8_t r1, uint8_t r2, uint8_t r3, uint8_t r4, uint8_t r5 = 0) {
                auto& g = table[static_cast<unsigned char>(c)];
                g.width = w;
                g.height = h;
                g.rows[0] = r0;
                g.rows[1] = r1;
                g.rows[2] = r2;
                g.rows[3] = r3;
                g.rows[4] = r4;
                g.rows[5] = r5;
            };
            set('0', 3,5, 2,5,5,5,2);
            set('1', 2,5, 1,3,1,1,1);
            set('2', 3,5, 6,1,2,4,7);
            set('3', 3,5, 6,1,2,1,6);
            set('4', 3,5, 1,3,5,7,1);
            set('5', 3,5, 7,4,7,1,6);
            set('6', 3,5, 2,4,6,5,2);
            set('7', 3,5, 7,1,2,2,2);
            set('8', 3,5, 2,5,2,5,2);
            set('9', 3,5, 2,5,7,1,2);
            set('a', 4,5, 6,6,9,15,9);
            set('b', 4,5, 14,9,14,9,14);
            set('c', 4,5, 7,8,8,8,7);
            set('d', 4,5, 14,9,9,9,14);
            set('e', 3,5, 7,4,6,4,7);
            set('f', 3,5, 7,4,6,4,4);
            set('g', 4,5, 7,8,11,9,7);
            set('h', 4,5, 9,9,15,9,9);
            set('i', 1,5, 1,1,1,1,1);
            set('j', 4,5, 1,1,1,9,6);
            set('k', 4,5, 9,10,12,10,9);
            set('l', 3,5, 4,4,4,4,7);
            set('m', 5,5, 17,27,21,17,17);
            set('n', 4,5, 9,13,11,9,9);
            set('o', 4,5, 6,9,9,9,6);
            set('p', 4,5, 14,9,14,8,8);
            set('r', 4,5, 14,9,14,10,9);
            set('s', 4,5, 7,8,6,1,14);
            set('t', 3,5, 7,2,2,2,2);
            set('u', 4,5, 9,9,9,9,6);
            set('v', 4,5, 9,9,9,6,0);
            set('w', 5,5, 17,17,21,27,17);
            set('x', 3,5, 5,5,2,5,5);
            set('y', 3,5, 5,5,2,2,2);
            set('z', 3,5, 7,1,2,4,7);
            set(' ', 3,5, 0,0,0,0,0);
            set('$', 3,6, 2,7,6,3,7,2);
            set('/', 3,5, 1,1,2,4,4);
            set('.', 3,5, 0,0,0,0,2);
            set('q', 4,5, 6,9,9,11,7);
            set('(', 3,5, 2,4,4,4,2);
            set(')', 3,5, 2,1,1,1,2);
            set('-', 2,5, 0,0,3,0,0);
            set(':', 3,5, 0,2,0,2,0);
            set('!', 3,5, 2,2,2,0,2);
            return table;
        }
    }

    inline constexpr auto glyphs = detail::make_table();
}
