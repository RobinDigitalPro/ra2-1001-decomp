#pragma once

#include "recovered/global_b26_memory.hpp"

#include <cstdint>

namespace ra2::recovered::recovery_b326 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;

// Finite positive branch of original RVA 0x7f0f0. ECX is the positive
// selector, EDX is the raw receiver, and arg[0] is the first stack argument.
// The route requires one eight-unit range, the non-random mode byte, and a
// global object whose +0x1408 value differs from the receiver. It returns one
// of two pointers through the raw table at receiver+0x108 and RETs 8 bytes.
std::uint32_t fun_0047f0f0(Memory&, const Inputs&);
}
