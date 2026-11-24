#pragma once
#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::recovery_b393 {
using Memory = floating_b61::Memory;
using Inputs = floating_b61::Inputs;
using Function = floating_b61::Function;

// Draft positive, present-section routes only. These are composition models;
// they do not declare original class types or layouts.
std::uint32_t fun_00591c30(Memory&, const Inputs&);
std::uint32_t fun_00642740(Memory&, const Inputs&);
}
