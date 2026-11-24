#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b129 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

std::uint32_t fun_004f6430(Memory&, const Inputs&, Heap&); // RVA 0xf6430
std::uint32_t fun_004faa30(Memory&, const Inputs&, Heap&); // RVA 0xfaa30
std::uint32_t fun_005a2ed0(Memory&, const Inputs&, Heap&); // RVA 0x1a2ed0
std::uint32_t fun_0064b730(Memory&, const Inputs&, Heap&); // RVA 0x24b730
std::uint32_t fun_0064b8e0(Memory&, const Inputs&, Heap&); // RVA 0x24b8e0
}
