#pragma once

// Bounded UTF16 hexadecimal insertion with the exact class-1 temporary release.
#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b156 {
using Memory = global_b26::Memory;
using Inputs = global_b26::Inputs;
using Heap = ra2::platform::small_crt_heap::Heap;

// ECX receiver, args section/key/UTF-16 value; original RET 0xc.
// The finite route requires exactly one nonzero code unit in [1,15].
std::uint32_t fun_0050e140(Memory&, const Inputs&, Heap&);
}
