#include "recovery_b299.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b299 {
namespace {
// Narrow composition of the accepted 0x22fd30 body.  This retains its
// modulo-32 arithmetic and signed-halfword recombination, without linking the
// unrelated RNG entries that share rng_b77.cpp.
std::uint32_t generate_table(Memory& m, std::uint32_t child) {
    m.w32(child + 4u, 0u);
    m.w32(child + 8u, 103u);
    for (std::uint32_t index = 0; index != 250u; ++index) {
        std::uint32_t value = index;
        std::uint32_t previous = 0u;
        for (unsigned round = 0; round != 4u; ++round) {
            const auto old = value;
            const auto mixed = m.r32(0x7d8244u + 4u * round) ^ value;
            const auto high = ra2::recovered::global_b26::sar(mixed, 16u);
            const auto low = mixed & 0xffffu;
            const auto square = ~(high * high) + low * low;
            const auto halves = ra2::recovered::global_b26::sar(square, 16u) | (square << 16u);
            value = ((halves ^ m.r32(0x7d8294u + 4u * round)) + high * low) ^ previous;
            previous = old;
        }
        m.w32(child + 12u + 4u * index, value);
    }
    m.w8(child, 0u);
    return child;
}

// Accepted 0x25a490/0x6cdf0 zero-count outcomes.  Their allocation routes are
// unreachable for this exact input, so no allocator callback is linked.
void initialize_empty_wrapper(ra2::recovered::leaf::Memory& m,
                              std::uint32_t at, std::uint32_t vptr) {
    m.w32(at + 4u, 0u);
    m.w32(at + 8u, 0u);
    m.w8(at + 0x0cu, 1u);
    m.w8(at + 0x0du, 0u);
    m.w32(at + 0x10u, 0u);
    m.w32(at + 0x14u, 10u);
    m.w32(at, vptr);
}
}

std::uint32_t fun_00652810(Memory& m,ra2::recovered::leaf::Memory& object,
                           const Inputs& in,
                           const ClockOperations& clock) {
    const auto c=in.cx;
    if(!clock.time_get_time)
        throw std::domain_error("Block299 requires a live clock adapter");

    generate_table(m,c+0x218u);

    // Exact original behavior: root passes ECX=c+0x624 to 0x28fad0; that
    // helper reads/writes no receiver bytes, returns real timeGetTime EAX>>4,
    // and the root stores it at c+0x620 before zeroing c+0x628.
    m.w32(c+0x620,clock.time_get_time(clock.context)>>4);
    m.w32(c+0x628,0);

    initialize_empty_wrapper(object,c+0x2254u,0x00788a34u);
    initialize_empty_wrapper(object,c+0x2270u,0x007889f4u);
    initialize_empty_wrapper(object,c+0x228cu,0x007889f4u);

    // Preserve the original decision point after the embedded constructors.
    if(m.r8(c+0x7d8)!=0)
        throw std::domain_error("Block299 excludes the nonzero localization branch");
    object.w32(c+0x7d4,0x0082208cu);
    return c;
}
}
