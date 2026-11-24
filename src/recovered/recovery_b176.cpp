#include "recovered/recovery_b176.hpp"
#include "recovered/numeric_b88.hpp"
#include <cstdint>
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b176 {
using namespace ra2::recovered::floating_b61;

// Finite root route: the supplied registration list is empty with one free
// slot, so the original 0x298660 loop and indirect reallocator are bypassed.
// Root locals use an isolated temporary address span;
// the original native frame is transient and is not part of persistent state.
// The block176 adapter binds Inputs::stack_minus8 to a controlled raw entry-EBP
// sentinel because the original nested stack frame leaks its upper 24 bits.
std::uint32_t fun_0047a0e0(Memory& m, const Inputs& i) {
    const auto object = i.cx;
    const auto x = sx16(m.r16(object + 0x24u));
    const auto y = sx16(m.r16(object + 0x26u));
    const auto round_cell = [](std::uint32_t signed_word) {
        auto biased = signed_word * 0x100u + 0x80u;
        if (s32(biased) < 0) biased += 0xffu;
        return sar(biased, 8u) << 8u;
    };

    // Match the root's sign-corrected +0x80 then SAR/SHL sequence.
    Memory local=m;
    std::array<unsigned char,64> bytes{};
    leaf::Memory span(bytes.data(),0x7c000000u,bytes.size());local.add(span);
    constexpr auto scratch = 0x7c000000u;
    const auto input = scratch;
    const auto output = scratch + 0x20u;
    local.w32(input, round_cell(x));
    local.w32(input + 4u, round_cell(y));
    local.w32(input + 8u, 0u);

    Inputs projection = i;
    projection.cx = m.r32(0x00821cacu);
    projection.arg[0] = input;
    projection.arg[1] = output;
    (void)ra2::recovered::numeric_b88::fun_00698010(local, projection);
    i.fp = projection.fp;
    const auto projected_x = local.r32(output);
    const auto projected_y = local.r32(output + 4u);

    const auto subtype = sx8(m.r8(object + 0x11bu));
    const auto rect_x = projected_x - 0x1eu;
    const auto rect_y = projected_y + m.r32(0x00821974u) - 15u * subtype - 0x0fu;
    const auto base = m.r32(0x00aa60bcu);
    const auto count = m.r32(0x00aa60c8u);
    const auto append_limit = m.r32(0x00aa60c0u);
    if (count != 0u || append_limit != 1u)
        throw std::runtime_error("Block176 is bounded to an empty list with one append slot");

    const auto record = base + count * 20u;
    m.w32(0x00aa60c8u, count + 1u);
    m.w32(record, rect_x);
    m.w32(record + 4u, rect_y);
    m.w32(record + 8u, 0x3cu);
    m.w32(record + 12u, 0x1eu);
    // The root flag supplies only AL at the call frame. The high bytes are
    // stale stack data: the prior 0x298010 prologue left the root's saved EBP
    // at this same address, and the 0x298660 byte store changes only byte 0.
    m.w32(record + 16u, i.stack_minus8 & 0xffffff00u);
    // Original empty-list append leaves EAX = 5*count (zero here); the root
    // returns without modifying it.
    return 0u;
}
}

