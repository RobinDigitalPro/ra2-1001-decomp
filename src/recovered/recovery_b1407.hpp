#pragma once

#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b1407 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

std::uint32_t configure_crt(Memory&, const Inputs&);
std::uint32_t fun_004b2140(Memory&, const Inputs&, Heap&);
}
