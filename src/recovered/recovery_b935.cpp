#include "recovered/recovery_b935.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b935 {
std::uint32_t fun_00402330(Memory& m, const Inputs& i) {
    const std::uint32_t owner = i.cx;
    if (m.r32(owner + 0xa8u) != 0u)
        throw std::domain_error("B935 bounded clear route requires owner+0xa8 == 0");
    if (m.r32(owner + 0xb4u) != 0u)
        throw std::domain_error("B935 bounded clear route requires owner+0xb4 == 0");
    if (m.r32(owner + 0x168u) == 0u)
        throw std::domain_error("B935 bounded positive route requires nonzero owner+0x168");

    // Original JZ at 0x40233c selects 0x4023b0; after the store, the zero
    // checks at 0x4023c2 and 0x4023d0 skip both indirect calls.
    m.w32(owner + 0x168u, 0u);
    return 0u;
}
}
