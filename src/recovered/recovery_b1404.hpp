#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1404 {
using floating_b61::Memory;using floating_b61::Inputs;
// Typed helpers are uncounted fixture/provider adapters, not extra recovered roots.
std::uint64_t initialize_clock(Memory&);
std::uint64_t current_time(Memory&);
std::uint32_t fun_0070a760(Memory&,const Inputs&);
}
