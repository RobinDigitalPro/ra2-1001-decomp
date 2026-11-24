#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b842 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;

// Finite threshold-zero serializer route: real ordinary-heap allocations,
// the cached SpecialFlags receiver, and thirteen absent literal keys.
std::uint32_t fun_00680b30(Memory&,const Inputs&,Heap&);
}
