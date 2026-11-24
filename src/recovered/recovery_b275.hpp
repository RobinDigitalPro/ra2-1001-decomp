#pragma once

#include "platform/ordinary_heap.hpp"
#include "recovered/global_b26_memory.hpp"

#include <cstdint>

// Finite positive-route draft for original RVA 0x37a4d2.  This is an
// instruction-shaped guest-memory model, not a recovered class declaration
// or a claim about a source-level calling convention.
namespace ra2::recovered::recovery_b275 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using OrdinaryHeap = ra2::platform::ordinary_heap::Heap;

// Inputs.arg[0] is the first stack word at the original entry boundary.  The
// ordinary route requires a nonnull receiver whose 43 fields are distinct,
// live bases returned by the same ordinary heap used by OrdinaryHeap::release.
std::uint32_t fun_0077a4d2(Memory&, const Inputs&, OrdinaryHeap&);
} // namespace ra2::recovered::recovery_b275
