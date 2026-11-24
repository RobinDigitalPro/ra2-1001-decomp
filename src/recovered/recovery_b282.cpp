#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

namespace ra2::recovered::recovery_b282 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = platform::small_crt_heap::Heap;

// Static transcription draft for RVA 0x281450 / VA 0x681450. Integration
// requires Heap::allocate(512) to dispatch to the separately reviewed
// fresh512_uppermask_class32_v1 protocol, not to ordinary heap allocation.
std::uint32_t fun_00681450(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver = i.cx;
    std::uint32_t eax = 0x9999999au;
    const std::uint32_t edx = 0;
    m.w32(receiver + 0x20u, eax);
    m.w32(receiver + 0x28u, eax);
    eax = 0x80u;
    m.w32(receiver + 0x24u, 0x3fc99999u);
    m.w32(receiver + 0x2cu, 0x3fe99999u);
    m.w32(receiver + 0x30u, eax);
    m.w32(receiver + 0x10u, eax);
    m.w32(receiver + 0x08u, eax);
    m.w32(receiver + 0x0cu, edx);

    // The original SHR/INC loop reduces EDI=128 to zero in eight steps.
    std::uint32_t ecx = edx;
    std::uint32_t edi = eax;
    do { ++ecx; edi >>= 1u; } while (edi != 0u);
    --ecx;
    m.w32(receiver + 0x0cu, ecx);
    m.w32(receiver + 0x10u, edi);
    eax = 1u << ecx;
    m.w32(receiver + 0x0cu, ecx);
    m.w32(receiver + 0x04u, edx);
    m.w8(receiver + 0x14u, static_cast<std::uint8_t>(edx));
    m.w32(receiver + 0x08u, eax);
    const auto bytes = eax << 2u;

    const auto user = heap.allocate(bytes);
    m.w32(receiver, user);
    for (std::uint32_t k = 0; k != (bytes >> 2u); ++k)
        heap.w32(user + k * 4u, 0u);
    m.w32(receiver + 0x18u, 0x006814e0u);
    return receiver;
}
} // namespace ra2::recovered::recovery_b282
