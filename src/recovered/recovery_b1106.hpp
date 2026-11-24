#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
namespace ra2::recovered::b1106{using global_b26::Memory;using global_b26::Inputs;using b979::Heap;using ra2::platform::x87::State;struct Api{decltype(&GetEnvironmentStringsW)get;decltype(&WideCharToMultiByte)convert;decltype(&FreeEnvironmentStringsW)release;};unsigned run(Memory&,const Inputs&,Heap&,State&,const Api&);}
