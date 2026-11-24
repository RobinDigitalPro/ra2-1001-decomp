#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::b1022 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Api {
 using Info=BOOL(WINAPI*)(HANDLE,LPBY_HANDLE_FILE_INFORMATION);
 using ToDos=BOOL(WINAPI*)(const FILETIME*,LPWORD,LPWORD);
 using FromDos=BOOL(WINAPI*)(WORD,WORD,LPFILETIME);
 using Set=BOOL(WINAPI*)(HANDLE,const FILETIME*,const FILETIME*,const FILETIME*);
 Info info=&::GetFileInformationByHandle;ToDos to_dos=&::FileTimeToDosDateTime;
 FromDos from_dos=&::DosDateTimeToFileTime;Set set=&::SetFileTime;
};
struct Observation {BY_HANDLE_FILE_INFORMATION info{};FILETIME converted{};WORD date=0,time=0;};
unsigned run(Memory&,const Inputs&,Api&,unsigned root,Observation&);
}
