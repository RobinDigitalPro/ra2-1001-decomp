#include "recovery_b275.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b275 {
namespace {
// Exact PUSH [ESI+disp] order from 0x77a4df through 0x77a65d.  The first
// field is +4; +0 is seventh, and +0x1c follows +0x34.
constexpr std::array<std::uint32_t, 43> free_order{{
    0x04,0x08,0x0c,0x10,0x14,0x18,0x00,0x20,0x24,0x28,0x2c,0x30,0x34,0x1c,
    0x38,0x3c,0x40,0x44,0x48,0x4c,0x50,0x54,0x58,0x5c,0x60,0x64,0x68,0x6c,
    0x70,0x74,0x78,0x7c,0x80,0x84,0x88,0x8c,0x90,0x94,0x98,0x9c,0xa0,0xa4,0xa8
}};
}

std::uint32_t fun_0077a4d2(Memory& memory, const Inputs& inputs, OrdinaryHeap& heap) {
    const auto receiver = inputs.arg[0];
    auto eax = inputs.ax;
    if (receiver == 0) throw std::domain_error("275 requires nonnull owned-field receiver");

    // Finite accepted route: every field is a distinct live ordinary-heap base.
    for (const auto offset : free_order) {
        const auto pointer = memory.r32(receiver + offset);
        if (pointer == 0) throw std::domain_error("275 requires43 distinct nonnull owned bases");
        eax = heap.release(pointer);
    }
    return eax;
}
} // namespace ra2::recovered::recovery_b275
