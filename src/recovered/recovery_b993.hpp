#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b993 {
using Memory=ra2::recovered::b979::Memory;
using Inputs=ra2::recovered::b979::Inputs;
using Heap=ra2::recovered::b979::Heap;
struct FileApi:ra2::recovered::b979::FileApi {using WriteFileProc=BOOL(WINAPI*)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);WriteFileProc write_file=&::WriteFile;};
struct Observation{std::uint32_t final_filename_free_bool=0;};
std::uint32_t run(Memory&,const Inputs&,Heap&,FileApi&,std::uint32_t,Observation* =nullptr);
std::uint32_t fun_0072d960(Memory&,const Inputs&,Heap&,FileApi&);
std::uint32_t fun_0072ddb0(Memory&,const Inputs&,Heap&,FileApi&);
std::uint32_t fun_0072e030(Memory&,const Inputs&,Heap&,FileApi&);
}
