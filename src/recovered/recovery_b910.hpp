#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b910 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;

// Supported bounded route: writable 0x400-byte owner, distinct from the heap;
// actual nonfailing ordinary-heap allocations; actual raw tick supplied by the
// native observer. No original class name or general constructor contract.
std::uint32_t fun_00726080(Memory&,const Inputs&,Heap&,std::uint32_t observed_tick);
}
