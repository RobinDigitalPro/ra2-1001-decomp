#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include <array>
namespace ra2::recovered::b1017 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Api {
 using Create=HANDLE(WINAPI*)(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);
 using Read=BOOL(WINAPI*)(HANDLE,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);
 using Close=BOOL(WINAPI*)(HANDLE);
 Create create=&::CreateFileA;Read read=&::ReadFile;Close close=&::CloseHandle;
};
struct Observation {std::array<unsigned char,16>header{};unsigned opened=0;};
unsigned run(Memory&,const Inputs&,Api&,unsigned root,Observation&);
}
