#pragma once
#include "recovered/recovery_b215_machine.hpp"
namespace ra2::recovered::b1668 {
using Memory=global_b26::Memory;using State=recovery_b215::State;using Frame=recovery_b215::Frame;namespace fp=ra2::platform::x87;
struct NativeState{std::uint32_t ax,cx,dx,bx,bp,si,di,flags;};
struct Result{std::uint32_t eax;State state;std::array<std::uint32_t,16>words;};
Result run(Memory&,std::uint32_t,unsigned char*,unsigned,const NativeState&,const fp::Image&);
}
