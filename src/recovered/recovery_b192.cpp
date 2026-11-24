#include "recovery_b192.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b192 {
std::uint32_t fun_0072c9f0(Memory& m, const Inputs&) {
    // Original VA 0x72C9F0 loads this DWORD before its first conditional.
    // The route is defined only for the null-handle branch.
    if (m.r32(0x00b0de5cu) != 0u)
        throw std::domain_error("Block192 models only the null-state reset branch");

    // VA 0x72CA01, 0x72CA08, and 0x72CA0E.  The first store is a WORD,
    // preserving the adjacent halfword at B0DC22.
    m.w16(0x00b0dc20u, 0u);
    m.w32(0x00b0de64u, 0u);
    m.w32(0x00b0de68u, 0u);
    return 0u; // EAX remains the initial null value through the epilogue.
}
} // namespace ra2::recovered::recovery_b192
