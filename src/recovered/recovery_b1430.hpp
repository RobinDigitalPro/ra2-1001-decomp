#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1430 {
using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
using Heap=ra2::platform::ordinary_heap::Heap;
unsigned configure_crt(Memory&,const Inputs&);
unsigned fun_004d18c0(Memory&,const Inputs&,Heap&);
unsigned fun_004d1e00(Memory&,const Inputs&,Heap&);
LRESULT CALLBACK common_window_proc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK combo_window_proc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK generic_window_proc(HWND,UINT,WPARAM,LPARAM);
INT_PTR CALLBACK dialog_proc(HWND,UINT,WPARAM,LPARAM);
}
