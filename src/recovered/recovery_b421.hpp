#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovery_b421 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
std::uint32_t fun_006e05a0(Memory&,const Inputs&);
std::uint32_t fun_00430180(Memory&,const Inputs&);
}
