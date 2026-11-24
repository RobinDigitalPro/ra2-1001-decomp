#pragma once
#include "recovered/recovery_b566_machine.hpp"
#include "recovered/recovery_b1655_formatter.hpp"
namespace ra2::recovered::b1655 {
using Memory=global_b26::Memory;using State=recovery_b566::State;namespace fp=platform::x87;
struct Api:b1655_formatter::Api{
 virtual unsigned set_rect_address()const=0;
 virtual unsigned set_rect(unsigned output,unsigned left,unsigned top,unsigned right,unsigned bottom,fp::State&)=0;
};
struct NativeState{unsigned ax,cx,dx,bx,bp,si,di,flags;};
struct Result{unsigned eax;State state;std::array<unsigned,16>words;};
Result run(Memory&,Api&,unsigned entry,unsigned char*storage,unsigned size,const NativeState&,const fp::Image&);
}
