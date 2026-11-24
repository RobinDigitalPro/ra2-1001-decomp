#include "recovery_b375.hpp"

#include "global_b26_memory.hpp"
#include "leaf_b56_b.hpp"
#include "leaf_memory.hpp"
#include "recovered/text_b86.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_006eee20(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b375 {
namespace {
using U = std::uint32_t;
void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

}

U fun_00617710(Memory& m, const Inputs& input) {
    const auto& i = input.regs;
    const U x = i.arg[0], y = i.arg[1], format = i.arg[2], color_desc = i.arg[3];
    const U width_override = i.arg[4];
    require(input.entry_esp >= 0x1000u && (input.entry_esp & 3u) == 0,
            "B375 requires a nonwrapping symbolic root entry ESP");
    require(x == 2u && y == 2u && width_override == 2u,
            "B375 covers x=y=2 and width override 2");
    require(m.r16(format) == 'A' && m.r16(format + 2u) == 0u,
            "B375 covers exactly UTF-16 L'A'");
    require(m.r32(0x836d30u) != 0u && m.r32(0x821c94u) == m.r32(0x836d18u),
            "B375 requires the supplied original font and surface globals");

    // The root's SUB ESP,38 frame and three saved registers leave a private
    // result pair at entryESP-38, clip at -30, and UTF-16 temporary at -20.
    // This symbolic stack span is private: only its final pair is observed by
    // the root's caller, and that pair is copied nowhere into the public arena.
    constexpr U stack_size = 0x1000u;
    const U stack_base = input.entry_esp - stack_size;
    std::array<std::uint8_t, stack_size> stack_bytes{};
    ra2::recovered::leaf::Memory stack_span(stack_bytes.data(), stack_base, stack_size);
    Memory local = m;
    local.add(stack_span);
    const U result = input.entry_esp - 0x38u;
    const U clip = input.entry_esp - 0x30u;
    const U wide_text = input.entry_esp - 0x20u;

    // 0x7c6294 is the original one-byte W string. The accepted helper writes
    // each result into its real eight-slot UTF-16 ring; the root calls it 15
    // times and copies each returned word into its own private buffer.
    require(m.r8(0x7c6294u) == 'W' && m.r8(0x7c6295u) == 0u,
            "B375 requires the pinned original W constant");
    for (U k = 0; k < 15u; ++k) {
        global_b26::Inputs widen{};
        widen.cx = 0x7c6294u;
        const U ring = global_b26::fun_006eee20(local, widen);
        const U ch = local.r16(ring);
        require(ch == 'W', "B375 W ring helper returned another character");
        local.w16(wide_text + 2u * k, ch);
    }
    local.w16(wide_text + 30u, 0u);

    // The original 0x431550 wrapper measures this 15-W string through the
    // accepted 0x431370 metrics routine. The caller supplied width 2, so the
    // computed width 30 is deliberately superseded before rendering.
    const U width_out=input.entry_esp-0x10u, height_out=input.entry_esp-0x0cu;
    global_b26::Inputs metrics{};
    metrics.cx=m.r32(0x836d30u);
    metrics.arg[0]=wide_text; metrics.arg[1]=width_out; metrics.arg[2]=height_out;
    (void)text_b86::fun_00431370(local,metrics);
    require(local.r32(width_out) == 30u && local.r32(height_out) == 2u,
            "B375 requires the pinned 15-W metrics result and font height");

    const U font = m.r32(0x836d30u), surface = m.r32(0x836d18u);
    const U desc = m.r32(font + 4u);
    const U glyph_table = m.r32(desc + 0x18u);
    const U glyph_data = m.r32(desc + 0x1cu);
    require(m.r16(glyph_table + 'A' * 2u) == 1u &&
            m.r16(glyph_table + 'W' * 2u) == 1u &&
            m.r32(desc + 0x14u) == 3u && m.r32(desc + 8u) == 2u &&
            m.r8(glyph_data) == 2u && m.r8(glyph_data + 1u) == 0xc0u &&
            m.r8(glyph_data + 2u) == 0x80u,
            "B375 requires the supplied parsed A/W-to-one-glyph font graph");

    // 0x97920 converts the caller's RGB triplet with accepted 0x4fe550 and
    // packs the three results using the six supplied RGB565 mask globals.
    const U source = color_desc + 0x308u;
    require(source >= color_desc, "B375 color descriptor wraps");
    // Keep the helper's three source bytes in a private, equivalent span.
    // leaf::Memory is a single-span adapter; the output is in the same
    // contiguous local allocation as the source for the exact helper call.
    std::array<std::uint8_t, 16> conversion{};
    constexpr U conversion_base = 0x7d430000u;
    for (U k = 0; k < 3u; ++k)
        conversion[k] = static_cast<std::uint8_t>(m.r8(source + k));
    ra2::recovered::leaf::Memory conversion_span(conversion.data(), conversion_base, 16u);
    ra2::recovered::leaf::Inputs convert{};
    convert.cx = conversion_base;
    convert.arg[0] = conversion_base + 8u;
    (void)ra2::recovered::leaf::fun_004fe550(conversion_span, convert);
    const U c0 = conversion_span.r8(conversion_base + 8u);
    const U c1 = conversion_span.r8(conversion_base + 9u);
    const U c2 = conversion_span.r8(conversion_base + 10u);
    const U packed = (((c0 >> 3u) << 11u) |
                      ((c1 >> 2u) << 5u) | (c2 >> 3u));

    const U height = local.r32(height_out);
    local.w32(clip, 0u); local.w32(clip + 4u, 0u);
    local.w32(clip + 8u, x + width_override);
    local.w32(clip + 12u, y + height);
    const U root_x = local.r32(clip) + x;
    const U root_y = local.r32(clip + 4u) + y;
    require(root_x == 2u && root_y == 2u && local.r32(clip + 8u) == 4u &&
            local.r32(clip + 12u) == 4u,
            "B375 requires the reviewed 4x4 root clip and (2,2) origin");

    // 0x97610 sees flags 0x19 with AH clear. Therefore the alignment,
    // background, and special vcall branches are excluded; the real ordinary
    // A-glyph path uses the same accepted descriptor, setter and 16-bit-surface
    // effects as B359, with the root-computed clip/point pair above.
    m.w8(font + 0x41u, 1u);
    m.w32(font + 0x30u, local.r32(clip)); m.w32(font + 0x34u, local.r32(clip + 4u));
    m.w32(font + 0x38u, local.r32(clip + 8u)); m.w32(font + 0x3cu, local.r32(clip + 12u));
    m.w16(font + 0x24u, packed); m.w32(font + 0x20u, root_x);
    m.w32(surface + 0x0cu, m.r32(surface + 0x0cu) + 1u);
    m.w32(font + 0x0cu, m.r32(surface + 0x14u));
    m.w32(font + 0x10u, 8u);
    for (U row = 0; row < 2u; ++row) {
        const U mask = m.r8(glyph_data + 1u + row);
        for (U col = 0; col < 2u; ++col) {
            const U px = root_x + col, py = root_y + row;
            if (px >= local.r32(clip) && px < local.r32(clip + 8u) &&
                py >= local.r32(clip + 4u) && py < local.r32(clip + 12u) &&
                ((mask >> (7u - col)) & 1u))
                m.w16(m.r32(surface + 0x14u) + 2u * (py * 8u + px), packed);
        }
    }
    m.w32(font + 0x0cu, 0u); m.w32(font + 0x10u, 0u);
    m.w32(surface + 0x0cu, m.r32(surface + 0x0cu) - 1u);
    local.w32(result, root_x); local.w32(result + 4u, root_y);
    return result;
}
}
