#pragma once
#include "platform/file_heap_adapter249.hpp"
namespace ra2::platform::writer998 {
struct Api:ra2::platform::file_heap249::FileApi{using Write=BOOL(WINAPI*)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);Write write_file=&::WriteFile;};
}
