#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b906 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
std::uint32_t fun_00644540(Memory&,const Inputs&,std::uint32_t entry_esp);
}
