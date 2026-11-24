#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b997 {
using Memory=ra2::recovered::b979::Memory;using Inputs=ra2::recovered::b979::Inputs;using Heap=ra2::recovered::b979::Heap;
struct FileApi:ra2::recovered::b979::FileApi{using WriteFileProc=BOOL(WINAPI*)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);WriteFileProc write_file=&::WriteFile;};
struct EntryState{std::uint32_t entry_esp;};
struct Observation{std::uint32_t input_filename_free_bool=0,output_filename_free_bool=0;};
std::uint32_t run(Memory&,const Inputs&,Heap&,FileApi&,EntryState,Observation* =nullptr);
std::uint32_t fun_0071b380(Memory&,const Inputs&,Heap&,FileApi&,EntryState);
}
