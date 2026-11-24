#pragma once
#include "recovered/recovery_b1430.hpp"
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1631 {
using Memory=b1430::Memory;using Inputs=b1430::Inputs;using Heap=b1430::Heap;
using RootHeap=b979::Heap;
// Existing model_prep implementation is an unchanged separate build input.
unsigned fun_004d1bb0_minus2(Memory&,const Inputs&,Heap&);
unsigned fun_004d1310_minus2(Memory&,const Inputs&,RootHeap&);
unsigned fun_005c41a0(Memory&,const Inputs&,RootHeap&);
}
