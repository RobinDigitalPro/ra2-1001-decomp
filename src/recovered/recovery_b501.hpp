#pragma once
#include "floating_b61_memory.hpp"
#include "recovered/floating_b39_memory.hpp"
namespace ra2::recovered::transform501 {
using Memory=ra2::recovered::floating_b39::Memory;
using State=ra2::recovered::floating_b39::State;
using Frame=ra2::recovered::floating_b39::Frame;
void fun_00697af0(Memory&,State&,Frame&);
std::uint32_t run(Memory&,const floating_b61::Inputs&);
}
