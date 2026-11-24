#pragma once
#include "platform/crt_slots1000.hpp"
namespace ra2::platform::crt_open1007 {
struct Api:crt_slots1000::Api{using Create=HANDLE(WINAPI*)(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);Create create_file_a=&::CreateFileA;};
}
