#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/x87_state.hpp"
#include <windows.h>
namespace ra2::recovered::b1719 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::x87::State;
// Platform providers reached through the original IAT slots.
struct Api{
 SIZE_T(WINAPI*query)(LPCVOID,PMEMORY_BASIC_INFORMATION,SIZE_T);   // 0x7850D8 VirtualQuery
 BOOL(WINAPI*protect)(LPVOID,SIZE_T,DWORD,PDWORD);                  // 0x7850F8 VirtualProtect
 DWORD(WINAPI*last_error)();                                        // 0x7851F4 GetLastError
 HANDLE(WINAPI*process)();                                          // 0x785194 GetCurrentProcess
 BOOL(WINAPI*flush)(HANDLE,LPCVOID,SIZE_T);                         // 0x7850F4 FlushInstructionCache
};
// Original RVA 0xBA900 (VA 0x4BA900, 189 bytes, RET 0): clears the first dword of the
// code at 0x4BA0F0 by temporarily giving its memory region PAGE_WRITECOPY, then sets
// PAGE_EXECUTE on the same region and flushes the instruction cache.
unsigned run(Memory&,const Inputs&,State&,const Api&);
}
