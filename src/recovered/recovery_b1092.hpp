#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1092 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::x87::State;
unsigned run(Memory&,const Inputs&,State&,unsigned);
}
