#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1071 {
using b979::Memory;using b979::Inputs;using b979::Heap;using ra2::platform::x87::State;
unsigned fun_00410a60(Memory&,const Inputs&,Heap&);
unsigned fun_007614c0(Memory&,const Inputs&,Heap&);
unsigned run(Memory&,const Inputs&,Heap&,State&,unsigned);
}
