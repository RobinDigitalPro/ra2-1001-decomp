#include "recovered/recovery_b1446.hpp"
#include <stdexcept>
namespace ra2::recovered::b1446 {
namespace {
// Exact local adapter for the accepted 0x62FDE0 leaf on this Memory type.
// The leaf's 81 original bytes and accepted evidence remain separately pinned.
std::uint32_t leaf_0062fde0(Memory& m, std::uint32_t state) {
    if (m.r8(state) != 0u) return 0u;
    const auto i = m.r32(state + 4u);
    const auto j = m.r32(state + 8u);
    if (i >= 250u || j >= 250u)
        throw std::domain_error("1446 finite seeded RNG cursor domain");
    const auto table = state + 12u;
    const auto left = m.r32(table + 4u * i);
    const auto right = m.r32(table + 4u * j);
    m.w32(table + 4u * i, left ^ right);
    const auto result = m.r32(table + 4u * i);
    const auto next_i = i + 1u;
    const auto next_j = j + 1u;
    m.w32(state + 4u, next_i >= 250u ? 0u : next_i);
    m.w32(state + 8u, next_j >= 250u ? 0u : next_j);
    return result;
}
}
std::uint32_t fun_00624770(Memory& m, const Inputs&) {
    // The selected original path is the PE initial byte A9DE44 == 0.
    if (m.r8(0x00a9de44u) != 0u)
        throw std::domain_error("1446 supports the original default flag route only");
    const auto owner = m.r32(0x00a255c0u);
    if (owner == 0u)
        throw std::domain_error("1446 requires the constructor-produced owner pointer");
    if (m.r8(owner + 0x218u) != 0u)
        throw std::domain_error("1446 requires the constructor-seeded enabled RNG state");
    const auto result = leaf_0062fde0(m, owner + 0x218u);
    m.w32(0x00a93838u, result);
    return result;
}
}
