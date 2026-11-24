#include "recovery_b405.hpp"
#include "recovered/allocation_wrappers.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b405 {
namespace {
std::uint32_t release(std::uint32_t p, void* context) {
    return static_cast<Heap*>(context)->release(p);
}
constexpr std::array<std::uint32_t, 16> slots{
    0xaa8b00u, 0xaa8b7cu, 0xaa8b74u, 0xaa8b38u,
    0xaa8b9cu, 0xaa8af8u, 0xaa8b40u, 0xaa8b48u,
    0xaa8b90u, 0xaa8b08u, 0xaa8b54u, 0xaa8b34u,
    0xaa8b30u, 0xaa8b58u, 0xaa8b64u, 0xaa8b68u,
};
constexpr std::uint32_t first_flag = 0xaa8cc6u;
}

std::uint32_t fun_006ea140(Memory& m, const Inputs&, Heap& heap) {
    const ra2::recovered::AllocationWrapperOperations ops{nullptr, release, &heap};
    std::uint32_t eax = 0u;
    for (unsigned k = 0; k < slots.size(); ++k) {
        // The original reads each next flag before clearing the previous slot.
        const auto flag = m.r8(first_flag + k);
        if (k != 0u)
            m.w32(slots[k - 1u], 0u);
        if (flag == 0u)
            throw std::domain_error("B405 draft covers only sixteen set ownership flags");
        const auto pointer = m.r32(slots[k]);
        if (pointer == 0u)
            throw std::domain_error("B405 draft requires sixteen nonnull heap blocks");
        eax = ra2::recovered::fun_0076d67b(pointer, ops);
        m.w8(first_flag + k, 0u);
    }
    m.w32(slots.back(), 0u);
    return eax;
}
}
