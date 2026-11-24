#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "recovered/recovery_b519.hpp"

namespace ra2::recovered::recovery_b523 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
using Heap = ra2::recovery_b519::Heap;
std::uint32_t fun_0047f220(Memory&, const Inputs&, Heap&);
}
