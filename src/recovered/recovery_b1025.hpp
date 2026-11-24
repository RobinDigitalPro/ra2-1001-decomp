#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b979.hpp"
#include <array>
namespace ra2::recovered::b1025 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using FileApi=b979::FileApi;
struct Api:FileApi{using Size=DWORD(WINAPI*)(HANDLE,LPDWORD);using Seek=DWORD(WINAPI*)(HANDLE,LONG,PLONG,DWORD);Size size=&::GetFileSize;Seek seek=&::SetFilePointer;};
struct Observation {std::array<unsigned char,100>file{};unsigned name=0,payload=0,final_free=0;DWORD bytes_read=0;};
void prepare(Memory&,Inputs&,unsigned base,unsigned root,unsigned length,unsigned offset);
unsigned run(Memory&,const Inputs&,Heap&,Api&,unsigned root,Observation&);
void cleanup(Memory&,const Inputs&,Heap&,unsigned root,Observation&);
}
