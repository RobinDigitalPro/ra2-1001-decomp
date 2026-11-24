#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1320 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;
std::uint32_t run(std::uint32_t root, Memory&, const Inputs&);
}
