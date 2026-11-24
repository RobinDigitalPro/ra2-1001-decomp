#pragma once
#include "recovered/recovery_b1025.hpp"
namespace ra2::recovered::b1113{using Memory=b979::Memory;using Inputs=b979::Inputs;
struct Api:b1025::Api{using Write=BOOL(WINAPI*)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);using Invalidate=BOOL(WINAPI*)(HWND,const RECT*,BOOL);Write write=&::WriteFile;Invalidate invalidate=&::InvalidateRect;};
struct Observation{std::array<unsigned char,128>header{};std::array<unsigned char,768>palette{};unsigned char byte{};DWORD got{};};
unsigned run(Memory&,const Inputs&,Api&,Observation&,unsigned root);}
