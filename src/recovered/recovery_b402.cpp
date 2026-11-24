#include "recovered/recovery_b402.hpp"
#include "recovered/allocation_wrappers.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b402 {
namespace {
std::uint32_t release(std::uint32_t p, void* context) {
    return static_cast<Heap*>(context)->release(p);
}
}

std::uint32_t fun_004281e0(Memory& m, const Inputs& in, Heap& heap) {
    const auto self = in.cx;
    const ra2::recovered::AllocationWrapperOperations ops{nullptr, release, &heap};
    std::uint32_t eax = 0;

    // The reviewed route has two distinct parent blocks, each owning one
    // heap child at +8. The original releases child before parent.
    for (const auto parent_offset : {0x14u, 0x68u}) {
        const auto parent = m.r32(self + parent_offset);
        if (!parent) throw std::domain_error("cleanup402 requires both parent allocations");
        const auto child = heap.r32(parent + 8u);
        if (!child) throw std::domain_error("cleanup402 requires both child allocations");
        eax = ra2::recovered::fun_0076d67b(child, ops);
        eax = ra2::recovered::fun_0076d67b(parent, ops);
        m.w32(self + parent_offset, 0u);
    }

    for (const auto offset : {0x10u, 0x0cu, 0x18u, 0x1cu, 0x24u, 0x20u}) {
        const auto pointer = m.r32(self + offset);
        if (!pointer) throw std::domain_error("cleanup402 requires all direct blocks");
        eax = ra2::recovered::fun_0076d67b(pointer, ops);
        m.w32(self + offset, 0u);
    }

    for (const auto offset : {0x40u, 0x4cu, 0x58u, 0x44u, 0x50u, 0x5cu,
                              0x48u, 0x54u, 0x60u}) {
        const auto pointer = m.r32(self + offset);
        if (!pointer) throw std::domain_error("cleanup402 requires all loop blocks");
        eax = ra2::recovered::fun_0076d67b(pointer, ops);
        m.w32(self + offset, 0u);
    }

    // Deliberately preserve the freed pointer at +0x64; the native oracle
    // compares its allocation identity, not its process-specific address.
    const auto dangling = m.r32(self + 0x64u);
    if (!dangling) throw std::domain_error("cleanup402 requires final dangling block");
    eax = ra2::recovered::fun_0076d67b(dangling, ops);

    // Three embedded vector-like records are reinitialized even as their
    // owned blocks are released. Their vptr word is a stored original value.
    for (const auto object_offset : {0xa4u, 0x8cu, 0x74u}) {
        m.w32(self + object_offset, 0x7874fcu);
        const auto pointer = m.r32(self + object_offset + 4u);
        const auto flag = m.r8(self + object_offset + 0x0du);
        if (!pointer || flag == 0u)
            throw std::domain_error("cleanup402 requires three owned vector blocks");
        eax = ra2::recovered::fun_0076d67b(pointer, ops);
        m.w32(self + object_offset + 4u, 0u);
        m.w8(self + object_offset + 0x0du, 0u);
        m.w32(self + object_offset + 8u, 0u);
    }
    return eax;
}
}
