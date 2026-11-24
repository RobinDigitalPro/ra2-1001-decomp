#include "recovered/recovery_b396.hpp"
#include "recovered/allocation_wrappers.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b396 {
namespace {
std::uint32_t release(std::uint32_t p, void* context) {
    return static_cast<Heap*>(context)->release(p);
}
}

std::uint32_t fun_006e7740(Memory& m, const Inputs&, Heap& heap) {
    if(m.r8(0xaa8bf8)!=1||m.r8(0xaa8ca4)!=1||m.r8(0xaa8ca5)!=1||m.r8(0xaa8ca6)!=1||!m.r32(0xaa8bb0)||!m.r32(0xaa8b94)||!m.r32(0xaa8bac)||!m.r32(0xaa8bf0)||m.r32(0xaa8bf4))
        throw std::domain_error("B396 only covers all four live slots and flags, ready1, final-object null");

    m.w8(0x00aa8bf8u, 0u);
    ra2::recovered::AllocationWrapperOperations ops{nullptr, release, &heap};

    std::uint32_t eax = 0u;
    const auto first_flag = m.r8(0x00aa8ca4u);
    if (first_flag != 0u) {
        eax = ra2::recovered::fun_0076d67b(m.r32(0x00aa8bb0u), ops);
        m.w8(0x00aa8ca4u, 0u);
    }
    m.w32(0x00aa8bb0u, 0u);

    const auto second_flag = m.r8(0x00aa8ca5u);
    if (second_flag != 0u) {
        eax = ra2::recovered::fun_0076d67b(m.r32(0x00aa8b94u), ops);
        m.w8(0x00aa8ca5u, 0u);
    }
    m.w32(0x00aa8b94u, 0u);

    const auto third_flag = m.r8(0x00aa8ca6u);
    if (third_flag != 0u) {
        eax = ra2::recovered::fun_0076d67b(m.r32(0x00aa8bacu), ops);
        m.w8(0x00aa8ca6u, 0u);
    }
    m.w32(0x00aa8bacu, 0u);

    const auto fourth = m.r32(0x00aa8bf0u);
    if (fourth != 0u) {
        eax = ra2::recovered::fun_0076d67b(fourth, ops);
        m.w32(0x00aa8bf0u, 0u);
    }

    // The review fixture fixes the final-object slot at zero. The optional
    // virtual call through that object's first vtable slot remains excluded.
    if (m.r32(0x00aa8bf4u) != 0u)
        throw std::domain_error("cleanup396 excludes nonnull final object dispatch");
    return eax;
}
}
