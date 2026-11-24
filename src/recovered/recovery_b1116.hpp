#pragma once
#define NOMINMAX
#include <windows.h>
#include <ole2.h>
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1116{using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Api{using Create=HRESULT(WINAPI*)(REFCLSID,LPUNKNOWN,DWORD,REFIID,LPVOID*);using Run=HRESULT(WINAPI*)(LPUNKNOWN);Create create=nullptr;Run run=nullptr;};
unsigned run(Memory&,const Inputs&,Api&);}
