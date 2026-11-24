#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1455 {
using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;
unsigned configure_crt(Memory&,const Inputs&);
unsigned populate(Memory&,const Inputs&,Heap&,unsigned text);
unsigned fun_00745eb0(Memory&,const Inputs&,Heap&);
LRESULT CALLBACK common_window_proc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK listbox_window_proc(HWND,UINT,WPARAM,LPARAM);
}
