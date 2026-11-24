#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1051 {
using b979::Memory;using b979::Inputs;using b979::Heap;using ra2::platform::x87::State;
unsigned run(Memory&,const Inputs&,Heap&,State&,unsigned);
unsigned fun_006b25c0(Memory&,const Inputs&);
unsigned fun_006b2890(Memory&,const Inputs&);
unsigned fun_006b7720(Memory&,const Inputs&,Heap&);
unsigned fun_006cfec0(Memory&,const Inputs&,Heap&);
}
