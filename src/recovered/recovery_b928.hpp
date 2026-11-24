#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b928 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;
// Model for the finite, nonzero, masked-exception route only. The original
// entry uses a saved-control-word prefix before its continuation address.
std::uint32_t fun_00773039(Memory&, const Inputs&);
}
