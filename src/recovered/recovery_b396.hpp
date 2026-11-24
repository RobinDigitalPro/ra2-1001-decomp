#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b396 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

// Bounded all-live four-slot cleanup route at original RVA 0x2e7740.
std::uint32_t fun_006e7740(Memory&, const Inputs&, Heap&);
}
