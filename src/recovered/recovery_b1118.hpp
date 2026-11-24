#pragma once
#define NOMINMAX
#include <windows.h>
#include <ole2.h>
#include <array>
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1118 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;
struct Api {using Create=HRESULT(WINAPI*)(REFCLSID,LPUNKNOWN,DWORD,REFIID,LPVOID*);using Run=HRESULT(WINAPI*)(LPUNKNOWN);using Atomic=LONG(WINAPI*)(volatile LONG*);Create create{};Run run{};Atomic increment{},decrement{};};
struct Context{Memory& memory;Heap& heap;Api& api;};
class Activation{Context*prior{};public:explicit Activation(Context&);~Activation();Activation(const Activation&)=delete;};
// Model source callback tables only; native uses original GAME tables.
// Order: factory; object BASE0; object BASE4; object BASE18.
std::array<unsigned,4> vtable_addresses();
unsigned construct_factory(Context&); // actual heap.allocate(8), vptr modeltable, ref4=0.
unsigned run(Memory&,const Inputs&,Api&); // Root1B650 only; CoCreate/OleRun actual API.
}
