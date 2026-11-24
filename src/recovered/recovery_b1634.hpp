#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1634 {
using U=std::uint32_t;using Memory=global_b26::Memory;using Inputs=floating_b61::Inputs;
struct Api{HWND main_window{};decltype(&::InvalidateRect)invalidate=&::InvalidateRect;};
U fun_0072bfc0(Memory&,const Inputs&,Api&);
}
