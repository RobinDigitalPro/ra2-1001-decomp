#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1311 {
using Memory=floating_b61::Memory;
using Inputs=floating_b61::Inputs;
std::uint32_t run(std::uint32_t root,Memory&,const Inputs&);
std::uint32_t fun_0055cab0(Memory&,const Inputs&);
std::uint32_t fun_0055cfe0(Memory&,const Inputs&);
std::uint32_t fun_0055d4c0(Memory&,const Inputs&);
std::uint32_t fun_0055da00(Memory&,const Inputs&);
}
