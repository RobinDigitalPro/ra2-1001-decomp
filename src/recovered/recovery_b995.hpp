#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace b995_test {
using ra2::recovered::global_b26::Memory;
using ra2::recovered::global_b26::Inputs;
using ra2::platform::ordinary_heap::Heap;

// Bounded, prepared-state models for the two disjoint cleanup routines.
std::uint32_t fun_00535660(Memory&, const Inputs&, Heap&);
std::uint32_t fun_006e7cf0(Memory&, const Inputs&, Heap&);
}
