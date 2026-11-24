#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b915 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::floating_b61::Inputs;
std::uint32_t fun_00708490(Memory&,const Inputs&,std::uint32_t entry_esp);
}
