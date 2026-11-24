#pragma once
#include <array>
#include <cstdint>
#include "recovered/global_b26_memory.hpp"
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1664 {
using Memory=global_b26::Memory;using State=recovery_b566::State;using Frame=recovery_b566::Frame;namespace fp=ra2::platform::x87;
struct Operations{void*window_context=nullptr;unsigned set_rect_target=0;unsigned(*set_rect)(void*,Memory&,unsigned actual_target,unsigned child_entry,fp::State&)=nullptr;};
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
Result run(Memory&,unsigned entry,unsigned char*storage,unsigned size,const NativeState&,const fp::Image&,const Operations&);
}
