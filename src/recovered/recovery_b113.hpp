#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>
#include "platform/ordinary_heap.hpp"

// Bounded original-RVA interface. The implementation requires the parent's
// real ordinary-heap adapter, not synthetic allocation/free return values.
namespace ra2::recovered::recovery_b113 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

using Heap=ra2::platform::ordinary_heap::Heap;

// RVAs 0x1fcc00, 0x1fa110 and 0x353bc0 (VAs 0x5fcc00, 0x5fa110,
// and 0x753bc0 respectively). These declarations are finite contracts.
std::uint32_t fun_005fcc00(Memory&, const Inputs&, Heap&);
std::uint32_t fun_005fa110(Memory&, const Inputs&, Heap&);
std::uint32_t fun_00753bc0(Memory&, const Inputs&, Heap&);
} // namespace ra2::recovered::recovery_b113
