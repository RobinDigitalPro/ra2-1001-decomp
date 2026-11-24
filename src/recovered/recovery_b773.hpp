#pragma once

#include "recovered/global_b26_memory.hpp"
#include "recovered/floating_b61_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <cstdint>
#include <vector>

namespace ra2::heap773_draft {

using U = std::uint32_t;
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// Positive existing-key route for original RVA 0x10df90 only.
std::uint32_t fun_0050df90(Memory&, Inputs&, Heap&);

struct Entry {
    U rva, size, return_mask;
    U (*recovered)(Memory&, Inputs&, Heap&);
    void (*prepare)(Memory&, ra2::recovered::global_b26::Inputs&, unsigned, U, Heap&);
    std::vector<U> pages;
    U stack_mask;
};
const std::vector<Entry>& entries();
U heap_request(unsigned);
U verify(Memory&, const Inputs& before, const Inputs& after, unsigned n,
         U arena, U object, Heap&);
void normalize_published(Memory&, const Inputs&, unsigned, U arena, Heap&);

} // namespace ra2::heap773_draft
