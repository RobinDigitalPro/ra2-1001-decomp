#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
#include <windows.h>
namespace ra2::recovered::b1715 {
using b979::Memory;using b979::Inputs;using b979::Heap;using ra2::platform::x87::State;
using Close=BOOL(WINAPI*)(HANDLE);
using Destroy=void(WINAPI*)(LPCRITICAL_SECTION);
// Original RVA 0x336640 (VA 0x736640, 496 bytes, RET 0): online-subsystem teardown,
// the inverse of producer 0x736950. Close/Destroy are the CloseHandle (IAT 0x7851D4)
// and DeleteCriticalSection (reached through accepted 0x751EA0) platform providers.
unsigned run(Memory&,const Inputs&,Heap&,State&,Close,Destroy);
}
