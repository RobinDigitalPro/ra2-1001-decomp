#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b888 {
using global_b26::Inputs;
using global_b26::Memory;

// Private draft for the finite 0x168310 borrowed-old-array growth route.
// It is not registered in the recovered-function tables or build system.
std::uint32_t fun_00568310(Memory&, const Inputs&,
                           ra2::platform::ordinary_heap::Heap&);
}
