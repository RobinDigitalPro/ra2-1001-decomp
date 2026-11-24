#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b979.hpp"
#include <vector>
namespace ra2::recovered::b1028 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;
struct Api {using Kill=BOOL(WINAPI*)(HWND,UINT_PTR);Kill kill=&::KillTimer;};
struct Fixture {unsigned receiver=0;std::vector<unsigned>owners;};
void attach(Memory&,Heap&,unsigned root,const Fixture&,unsigned rows);
Fixture prepare(Memory&,Inputs&,Heap&,unsigned base,unsigned root,unsigned seed,unsigned window,unsigned rows,const std::vector<unsigned>&requests);
unsigned run(Memory&,const Inputs&,Heap&,Api&,unsigned root,const Fixture&);
}
