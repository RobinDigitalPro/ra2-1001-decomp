#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b116 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

std::uint32_t fun_005fa520(Memory&, const Inputs&, Heap&);
std::uint32_t fun_005fa5b0(Memory&, const Inputs&, Heap&);
std::uint32_t fun_00759570(Memory&, const Inputs&, Heap&);
}
