#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::recovery_b874 {
using U=std::uint32_t;using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct LocaleOps {void*context;int(*ansi)(void*,U,U,char*,int);int(*wide)(void*,U,U,std::uint16_t*,int);};
U fun_0077a939(Memory&,const Inputs&,platform::ordinary_heap::Heap&,const LocaleOps&);
}
