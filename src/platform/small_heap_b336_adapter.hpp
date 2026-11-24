#pragma once

#include "platform/small_crt_heap_algorithm.hpp"
#include <cstdint>

// Private Block 336 adapter transitions. This file is staged for parent
// integration; it does not alter the shared small-heap adapter.
namespace ra2::platform::small_crt_heap::b336 {

// Second small allocation: request 8 after request 14/15 has been released
// through 0x3733a8 and recorded as the current empty chunk.
std::uint32_t allocate_eight_from_tracked_empty_chunk(
    X86Memory&, std::uint32_t request, std::uint32_t entry_esp);

// The first 14/15-byte compressed temporary rounds to the same 0x20 span as
// the accepted final-live class-1 route in empty173.
void release_first_class1_temporary(X86Memory&, std::uint32_t user,
                                    std::uint32_t request);

// Release the request-8, span-0x10 block. It coalesces with the residual
// class-63 extent on the left and records chunk zero as empty.
void release_second_class0_temporary(X86Memory&, std::uint32_t user);

} // namespace ra2::platform::small_crt_heap::b336
