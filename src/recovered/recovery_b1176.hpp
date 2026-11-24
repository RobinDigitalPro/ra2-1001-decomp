#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
#include <windows.h>
namespace ra2::recovered::b1176 {using global_b26::Memory;using global_b26::Inputs;using ra2::platform::x87::State;using Destroy=void(WINAPI*)(LPCRITICAL_SECTION);unsigned run(Memory&,const Inputs&,State&,Destroy);}
