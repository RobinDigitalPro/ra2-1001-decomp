#include "recovery_b326.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b326 {
namespace {
void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

std::uint32_t fun_0047f0f0(Memory& memory, const Inputs& input) {
    // These preconditions retain the exact branch through 0x47f19a and
    // 0x47f1eb while keeping all unrelated helper/RNG paths out of scope.
    need(input.cx != 0u && input.cx <= 255u,
         "B326 finite route requires a positive selector no greater than 255");
    need(input.dx != 0u && input.arg[0] != 2u,
         "B326 requires nonnull receiver and first stack argument other than 2");

    const auto global = memory.r32(0x00821b88u);
    need(global != 0u, "B326 requires the observed global-object pointer");
    need(memory.r32(global + 0x1408u) != input.dx,
         "B326 finite route requires the global +0x1408 receiver comparison to differ");

    const auto count = memory.r32(input.dx + 0x114u);
    need(count == 8u,
         "B326 finite route is bounded to the observed eight-unit selector range");
    need(memory.r8(input.dx + 0x152u) == 0u,
         "B326 finite route requires the original non-random mode byte to be zero");

    // Original 0x47f1eb..0x47f215 computes 25*count-1, clamps a
    // nonnegative signed selector, then uses signed IMUL-high / SAR / sign
    // adjustment to divide by 25 and loads that exact raw table cell.
    const auto upper = count * 25u - 1u;
    const auto clamped = input.cx < upper ? input.cx : upper;
    auto quotient = global_b26::sar(
        global_b26::imul_high(clamped, 0x51eb851fu), 3u);
    quotient += quotient >> 31;
    const auto table = memory.r32(input.dx + 0x108u);
    need(table != 0u && quotient <= 7u,
         "B326 raw table must contain the selected one of eight bounded cells");
    return memory.r32(table + quotient * 4u);
}
}
