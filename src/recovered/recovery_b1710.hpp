#pragma once
#include "recovered/recovery_b705_machine.hpp"
namespace ra2::delivery::query2ccac0 {
using Memory=ra2::recovered::recovery_b705::Memory;
using State=ra2::recovered::recovery_b705::State;
using Frame=ra2::recovered::recovery_b705::Frame;
using Operations=ra2::recovered::recovery_b705::Operations;
namespace fp=ra2::platform::x87;
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
// Caller pre-registers real owned500B storage [R-1B0,R+44) before entry.
Result run(Memory&,unsigned entry,unsigned char*storage,unsigned size,const NativeState&,const fp::Image&);
}
