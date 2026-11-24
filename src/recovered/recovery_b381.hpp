#pragma once
#include "floating_b61_memory.hpp"
namespace ra2::recovered::recovery_b381 {
using floating_b61::Memory;using floating_b61::Inputs;
// Positive sorted-index route, decimal quarter steps and optional trailing %.
// Caller words 0..3 are scratch in the original, and ST0 carries the value.
std::uint32_t fun_0050d7f0(Memory&,const Inputs&);
}
