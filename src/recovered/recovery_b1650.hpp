#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1650 {
using Memory=global_b26::Memory;using State=recovery_b566::State;namespace fp=platform::x87;
// Finite borrowed software palette copy; genuinely owned caller frame, full EAX1.
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming);
}
