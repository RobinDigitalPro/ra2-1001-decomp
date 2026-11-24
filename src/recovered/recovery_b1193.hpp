#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1193{
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Api{virtual~Api()=default;virtual unsigned create_draw(unsigned guid,unsigned output,unsigned outer)=0;virtual unsigned normal(unsigned draw,unsigned hwnd,unsigned flags)=0;virtual unsigned create_surface(unsigned draw,unsigned descriptor,unsigned output,unsigned outer)=0;virtual unsigned describe(unsigned surface,unsigned descriptor)=0;};
struct Observation{unsigned allocations=0,provider_calls=0;};
unsigned run(Memory&,const Inputs&,Heap&,Api&,unsigned root,Observation&);
}
