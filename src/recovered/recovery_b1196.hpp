#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1196 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Api:b979::FileApi{using Seek=DWORD(WINAPI*)(HANDLE,LONG,PLONG,DWORD);Seek seek=&::SetFilePointer;};
struct Observation{unsigned allocations=0,frees=0,insertions=0,removals=0,sorts=0,ui_updates=0,key_copies=0,value_reads=0,theme_assignments=0,substituted_callbacks=0;};
unsigned run(Memory&,Inputs&,Heap&,Api&,unsigned root,unsigned arena_base,Observation&);
}
