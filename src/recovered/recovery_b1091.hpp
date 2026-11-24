#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1091 {
using b979::Memory;using b979::Inputs;using b979::Heap;using ra2::platform::x87::State;
unsigned run(Memory&,const Inputs&,Heap&,State&,unsigned);
unsigned fun_0065a640(Memory&,const Inputs&,Heap&,State&);
unsigned fun_0065a9a0(Memory&,const Inputs&,Heap&,State&);
}
