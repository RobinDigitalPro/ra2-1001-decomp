#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1658 {
using Memory=global_b26::Memory;using State=recovery_b566::State;namespace fp=platform::x87;
// Source-qualified actual ordinary-provider delegates. Native GAME-CRT
// equivalence and finite Root-domain guards remain subject to parent qualification.
struct Operations{
 void*heap_context=nullptr;
 unsigned(*allocate)(void*,Memory&,unsigned,fp::State&)=nullptr;
 unsigned(*release)(void*,Memory&,unsigned,fp::State&)=nullptr;
};
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
Result run(Memory&,unsigned entry,unsigned char*storage,unsigned size,const NativeState&,const fp::Image&,const Operations&);
}
