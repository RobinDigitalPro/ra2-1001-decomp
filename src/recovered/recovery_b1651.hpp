#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1651 {
using Memory=global_b26::Memory;using State=recovery_b566::State;namespace fp=platform::x87;
// Finite software gradient curve. Clock remains abstract; synthetic assurance
// uses only a modeled target and does not claim real WinMM behavior.
struct Api {virtual ~Api()=default;virtual unsigned clock_target()const=0;virtual unsigned clock(fp::State&)=0;};
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
Result run(Memory&world,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming,Api&api);
}
