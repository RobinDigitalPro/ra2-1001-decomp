#include "recovered/recovery_b934.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b934 {
std::uint32_t fun_0044c9d0(Memory& m, const Inputs& i) {
    const std::uint32_t owner = i.cx;
    if (m.r8(owner + 0x7du) == 0u)
        throw std::domain_error("B934 bounded route requires nonzero active byte");

    const std::uint32_t token = i.arg[0];
    for (std::uint32_t index = 0; index < 18u; ++index) {
        const std::uint32_t slot = owner + 0x454u + index * 4u;
        if (m.r32(slot) != token)
            continue;

        if(index>=10u)throw std::domain_error("934 index outside0..9");
        m.w32(slot, 0u);
        const std::uint32_t eax = index - 10u;
        // The unsigned JA at 0x44ca0e takes the common epilogue for slots
        // 0..9. Other indices enter the root's out-of-scope jump table.
        if (eax <= 6u)
            throw std::domain_error("B934 contract excludes jump-table indices 10..16");
        return eax;
    }
    throw std::domain_error("B934 bounded route requires a matching slot");
}
}
