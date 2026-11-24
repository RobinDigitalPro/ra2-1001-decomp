#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1462 {
using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;
unsigned configure_crt(Memory&,const Inputs&);
unsigned fun_005bd930(Memory&,const Inputs&,Heap&);
void prepare_dc(Memory&,const Inputs&,Heap&);
unsigned fun_005bdab0(Memory&,const Inputs&,Heap&);
LRESULT CALLBACK common_window_proc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK listbox_window_proc(HWND,UINT,WPARAM,LPARAM);
}
