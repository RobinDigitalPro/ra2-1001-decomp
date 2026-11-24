#include "recovery_b363.hpp"

#include "global_b26_memory.hpp"
#include "leaf_b56_b.hpp"
#include "leaf_memory.hpp"
#include "recovery_b359.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b363 {
namespace {
using U = std::uint32_t;

void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}
}

// Finite positive route through the original 0x97770 wrapper shape: actual
// three-byte converter semantics, RGB565 packing globals, then the already
// reviewed original 0x97610 A-glyph route.
U fun_00497770(Memory& m, const Inputs& i) {
    require(i.cx != 0u && i.dx != 0u, "B363 requires output receiver and UTF-16 text");
    require(i.arg[5] == 0u, "B363 covers flags zero");
    require(m.r16(i.dx) == 'A' && m.r16(i.dx + 2u) == 0u,
            "B363 covers the one-character UTF-16 route");
    require(m.r32(0x83b2e8u) == 11u && m.r32(0x83b2ecu) == 3u &&
            m.r32(0x83b2f0u) == 0u && m.r32(0x83b2f4u) == 3u &&
            m.r32(0x83b2f8u) == 5u && m.r32(0x83b2fcu) == 2u,
            "B363 requires the original RGB565 packing state");

    // Original 0x97770 passes ECX=arg3+0x308 and an output pointer that aliases
    // its caller's arg3 stack word. The portable adapter gives accepted
    // 0x4fe550 a private, equivalent three-byte source and output span, then
    // applies its exact three-byte caller-word mutation below.
    const U source = i.arg[3] + 0x308u;
    require(source >= i.arg[3], "B363 color pointer does not wrap");
    std::array<std::uint8_t, 16> conversion{};
    constexpr U conversion_base = 0x50000000u;
    ra2::recovered::leaf::Memory conversion_memory(conversion.data(), conversion_base,
                                                   static_cast<U>(conversion.size()));
    for (U k = 0; k < 3u; ++k) conversion_memory.w8(conversion_base + k, m.r8(source + k));
    ra2::recovered::leaf::Inputs conversion_input{};
    conversion_input.cx = conversion_base;
    conversion_input.arg[0] = conversion_base + 8u;
    const U converted_ptr = ra2::recovered::leaf::fun_004fe550(conversion_memory, conversion_input);
    require(converted_ptr == conversion_base + 8u,
            "B363 converter returns its three-byte stack output");
    const U c0 = conversion_memory.r8(converted_ptr);
    const U c1 = conversion_memory.r8(converted_ptr + 1u);
    const U c2 = conversion_memory.r8(converted_ptr + 2u);

    const U packed = (((c0 >> 3u) << 11u) |
                      ((c1 >> 2u) << 5u) |
                      (c2 >> 3u));
    // 0x4fe550 writes bytes [0..2] of the wrapper's caller arg3 output pointer.
    i.arg[3] = (i.arg[3] & 0xff000000u) | c0 | (c1 << 8u) | (c2 << 16u);

    std::array<std::uint8_t,8> output_bytes{};
    constexpr U private_result=0x7d000000u;
    leaf::Memory output_span(output_bytes.data(),private_result,8u);
    Memory child_memory=m;child_memory.add(output_span);
    Inputs child{};
    child.cx = private_result;
    child.dx = i.dx;
    child.arithmetic_flags = i.arithmetic_flags;
    child.arg[0] = i.arg[0];
    child.arg[1] = i.arg[1];
    child.arg[2] = i.arg[2];
    child.arg[3] = packed;
    child.arg[4] = i.arg[4];
    child.arg[5] = i.arg[5];
    child.arg[6] = i.arg[6];
    for (U k = 7u; k < child.arg.size(); ++k) child.arg[k] = 0x97770000u + k;

    const U child_eax = ra2::recovered::recovery_b359::fun_00497610(child_memory, child);
    require(child_eax == private_result, "B363 child returns the private output pair");
    const U x = child_memory.r32(private_result);
    const U y = child_memory.r32(private_result + 4u);
    m.w32(i.cx, x);
    m.w32(i.cx + 4u, y);
    return i.cx;
}
}
