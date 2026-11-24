#pragma once
#include "recovered/recovery_b705_machine.hpp"

// Private selected-route preparation. No compiled or native qualification yet.
namespace ra2::delivery::query51090 {
using Memory=ra2::recovered::recovery_b705::Memory;
using State=ra2::recovered::recovery_b705::State;
using Frame=ra2::recovered::recovery_b705::Frame;
namespace fp=ra2::platform::x87;
struct NativeState { unsigned ax,cx,dx,bx,bp,si,di,flags; };
struct Result { unsigned eax;State state;std::array<unsigned,16> words; };
// Run outside the guest boundary, with live, defined, disjoint borrowed views.
void preflight(Memory&,unsigned self);
// Caller pre-registers actual owned stack [R-1B0,R+44); no stack initialization.
Result run(Memory&,unsigned entry,unsigned char*storage,unsigned size,
           const NativeState&,const fp::Image&);
}
