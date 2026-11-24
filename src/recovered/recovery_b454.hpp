#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace ra2::recovered::geometry_b454 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
struct Entry { std::uint32_t rva, size, cleanup, return_mask; };
const Entry& entry_14b150();
const Entry& entry_14b330();
std::uint32_t fun_0054b150(Memory&, Inputs&, ra2::platform::ordinary_heap::Heap&);
std::uint32_t fun_0054b330(Memory&, Inputs&, ra2::platform::ordinary_heap::Heap&);
}
