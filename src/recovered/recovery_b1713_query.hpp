#pragma once
// PRIVATE (batch unallocated): carrier-facing API of the 0x363380 domain-A Source. No x87 in the guest code: the incoming FP image passes through unchanged.
#include "recovered/numeric_b105_machine.hpp"
namespace ra2::delivery::query363380 {
using Memory=ra2::recovered::numeric_b105::Memory;using State=ra2::recovered::numeric_b105::State;using Frame=ra2::recovered::numeric_b105::Frame;
namespace fp=ra2::platform::x87;
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16> words;};
void preflight(Memory&,unsigned dispatcher,unsigned timestamp);   // domain A input guards
Result run(Memory&,unsigned entry,unsigned char*storage,unsigned size,const NativeState&,const fp::Image&);
}
