#include "recovery_b703.hpp"
#include "platform/small_crt_heap_algorithm.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::heap703_draft {
std::uint32_t fun_007736d3(Memory& m, Inputs& i, Heap& heap) {
    (void)m;
    const auto request = i.arg[0];
    if (request != 156u)
        throw std::domain_error("B703 bounded contract requires the original 156-byte request");

    // This is the standalone body at RVA 0x3736D3, not the 0x76D957 wrapper:
    // it does not enter/leave the CRT lock. The helper preserves the actual
    // writes to [EBP+8] through its explicit entry-stack image.
    constexpr std::uint32_t stack_image = 0x7d100000u;
    heap.w32(stack_image + 4u, request);
    const auto result = ra2::platform::small_crt_heap::fun_007736d3_allocate_first_small_block(
        heap, heap, request, stack_image);
    i.arg[0] = heap.r32(stack_image + 4u);

    // EFLAGS are outside this standalone allocator entry's bounded public
    // contract. The original final CMP/TEST flags depend on address-bearing
    // list state; do not synthesize an arithmetic-flags result here.
    return result;
}
}



