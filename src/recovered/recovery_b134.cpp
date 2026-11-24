#include "recovered/recovery_b134.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b134 {
namespace {
constexpr std::uint32_t global_count_va = 0x00a288b0u;
constexpr std::uint32_t allocation_bytes = 0x18u;
}

// Exact successful stores from VA 0x6eb946..0x6eb960. The selected
// signed-count <= 0 branch at 0x6eb970..0x6eb976 skips the list walk and its
// indirect [vtable+8] call. This is a bounded structural object contract;
// 0x78579c remains an opaque original word, not a recovered class name.
std::uint32_t fun_006eb930(Memory& m, const Inputs&, Heap& heap) {
    const auto object = heap.allocate(allocation_bytes); // original 0x36d957 -> 0x36df82
    if (object != 0) {
        heap.w32(object + 0x04u, 0u);
        heap.w32(object + 0x08u, 0u);
        heap.w8(object + 0x0cu, 1u);
        heap.w8(object + 0x0du, 0u);
        heap.w32(object + 0x00u, 0x0078579cu);
        heap.w32(object + 0x14u, 10u);
        heap.w32(object + 0x10u, 0u);
    }

    // The original takes JLE at VA 0x6eb976 for any signed count <=0.
    // Positive counts require the live global list and a real vtable target;
    // that dispatch is expressly outside this contract.
    if (static_cast<std::int32_t>(m.r32(global_count_va)) > 0)
        throw std::domain_error("0x2eb930 bounded route requires signed global count <= 0");

    // With count <=0 the original returns the saved allocation in full EAX;
    // its null-allocation branch returns zero without field stores.
    return object;
}
}
