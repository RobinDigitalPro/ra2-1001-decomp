#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::recovery_b399 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;
using Function = floating_b61::Function;
// Bounded present-key registry lookup and present-section record update.
// Miss construction, absent section/key, and other state shapes are excluded.
std::uint32_t fun_0046a620(Memory&, const Inputs&);
std::uint32_t fun_0070ada0(Memory&, const Inputs&);
}
