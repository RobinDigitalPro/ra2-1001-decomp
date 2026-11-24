#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1026 {
using Memory=ra2::recovered::b979::Memory;using Inputs=ra2::recovered::b979::Inputs;
struct Api{HANDLE(WINAPI*standard)(DWORD);BOOL(WINAPI*write)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);};
unsigned fun_00779f6f(Memory&,Inputs&,Api&);
}
