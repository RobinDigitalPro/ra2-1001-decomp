#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1497 {
using U=std::uint32_t;using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
using Handler=void(__cdecl*)(int);
U register_handler(Memory&,const Inputs&);
U fun_00778430(Memory&,const Inputs&);
}
