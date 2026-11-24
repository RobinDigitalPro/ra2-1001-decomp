#pragma once

#include "recovered/leaf_memory.hpp"
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b852 {
using Memory = leaf::Memory;
using Inputs = global_b26::Inputs;

// Bounded instruction-compatible list mutation/free sequence only. No source
// class identity, destructor, or ownership layout is claimed.
std::uint32_t fun_00401b00(Memory&, const Inputs&,
                           ra2::platform::ordinary_heap::Heap&);
}
