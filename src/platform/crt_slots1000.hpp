#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
namespace ra2::platform::crt_slots1000 {
struct Api {
 using Lock=void(WINAPI*)(LPCRITICAL_SECTION);
 using FileType=DWORD(WINAPI*)(HANDLE);
 Lock enter=&::EnterCriticalSection,leave=&::LeaveCriticalSection;
 FileType file_type=&::GetFileType;
};
}
