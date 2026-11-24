#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1646 {
using Memory=global_b26::Memory;
using State=recovery_b566::State;
namespace fp=platform::x87;
// Finite A92D0 recovery. The caller supplies bounded, genuinely owned Source
// execution-frame storage. Native qualification uses its current own stack;
// synthetic assurance uses an owned frame. Full EAX is never normalized.
struct Api{
 virtual ~Api()=default;
 virtual unsigned surface_for(unsigned receiver)const=0;
 virtual unsigned is_lost(unsigned surface,fp::State&)=0;
 virtual unsigned interlocked(bool increment,unsigned address,fp::State&)=0;
 virtual unsigned set_rect_address()const=0;
 virtual unsigned set_rect(unsigned output,unsigned left,unsigned top,unsigned right,unsigned bottom,fp::State&)=0;
};
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
Result run(Memory&world,Api&api,unsigned main,unsigned source,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming);
}
