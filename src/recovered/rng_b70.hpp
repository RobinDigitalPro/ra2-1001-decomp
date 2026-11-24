#pragma once
#include "recovered/floating_b61_memory.hpp"

namespace ra2::recovered::rng_b70 {
using Memory=global_b26::Memory;
using B70Inputs = ra2::recovered::floating_b61::Inputs;
std::uint32_t fun_0062fe40(Memory&, const B70Inputs&);
std::uint32_t fun_00404b90(Memory&, const B70Inputs&);
std::uint32_t fun_005a0cc0(Memory&, const B70Inputs&);
std::uint32_t fun_00668ca0(Memory&, const B70Inputs&);
std::uint32_t fun_00668d50(Memory&, const B70Inputs&);
std::uint32_t fun_006e2940(Memory&, const B70Inputs&);
}
