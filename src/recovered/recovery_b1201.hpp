#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1201 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=platform::ordinary_heap::Heap;
struct Api{decltype(&::SendMessageA)send=&::SendMessageA;decltype(&::CallWindowProcA)call=&::CallWindowProcA;decltype(&::GetWindowRect)window=&::GetWindowRect;decltype(&::GetClientRect)client=&::GetClientRect;decltype(&::ClientToScreen)screen=&::ClientToScreen;};
struct Observation{unsigned allocations=0,frees=0,insertions=0,removals=0,sorts=0,ui_updates=0,key_copies=0,text_readbacks=0,text_publications=0,hash_callbacks=0;};
WNDPROC generic_proc();WNDPROC static_proc();
unsigned run(Memory&,Inputs&,Heap&,Api&,unsigned root,unsigned arena_base,Observation&);
}
