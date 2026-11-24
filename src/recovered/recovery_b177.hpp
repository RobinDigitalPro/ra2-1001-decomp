#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b177 {
using global_b26::Inputs;
using global_b26::Memory;

// Bounded one-row, absent-typed-section TaskForces route at original RVA
// 0x2ac240. The only allocation request is 0xd4. Its allocator proof is a
// separate parent-owned extension to the fresh small-CRT request-212 route.
std::uint32_t fun_006ac240(Memory&, const Inputs&,
                           ra2::platform::small_crt_heap::Heap&);

// Normalize only the three proven publications of the new user pointer in a
// copied comparison snapshot: both constructor registry slots and the appended pair.
void normalize_published_refs(Memory&, const ra2::platform::small_crt_heap::Heap&);
}
