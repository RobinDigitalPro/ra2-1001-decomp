#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/x87_state.hpp"
#include <cstdint>
namespace ra2::recovered::b1454 {
using Memory = ra2::recovered::floating_b61::Memory;
using Inputs = ra2::recovered::floating_b61::Inputs;
std::uint32_t fun_0074a8a0(Memory&, const Inputs&);
}
