#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1060{
using b979::Memory;using b979::Inputs;using b979::Heap;using ra2::platform::x87::State;
unsigned run(Memory&,const Inputs&,Heap&,State&,unsigned);
unsigned fun_00637510(Memory&,const Inputs&);
unsigned fun_00637c30(Memory&,const Inputs&);
unsigned fun_00639a90(Memory&,const Inputs&,Heap&);
}
