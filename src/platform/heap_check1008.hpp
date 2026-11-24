#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
namespace ra2::platform::heap_check1008 {
struct Api{using BadWrite=BOOL(WINAPI*)(VOID*,UINT_PTR);BadWrite is_bad_write_ptr=&::IsBadWritePtr;};
}
