#pragma once
#include <array>
#include <cstdint>
#include "recovered/global_b26_memory.hpp"
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::b1662 {
using Memory=global_b26::Memory; using State=recovery_b566::State; using Frame=recovery_b566::Frame; namespace fp=ra2::platform::x87;
struct Operations {
 void* heap_context=nullptr;
 unsigned(*release)(void*,Memory&,unsigned,fp::State&)=nullptr;
};
struct NativeState { std::uint32_t ax,cx,dx,bx,bp,si,di,flags; };
struct Result { std::uint32_t eax; State state; std::array<std::uint32_t,16> words; };
Result run(Memory&,std::uint32_t entry,unsigned char* storage,unsigned size,const NativeState&,const fp::Image&,const Operations&);
}
