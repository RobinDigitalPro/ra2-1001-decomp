#pragma once
#include "recovered/recovery_b979.hpp"
#include <array>
#include <string>
#include <vector>
namespace ra2::recovered::b1003 {
using Memory=ra2::recovered::b979::Memory;using Inputs=ra2::recovered::b979::Inputs;using Heap=ra2::recovered::b979::Heap;
struct FileApi:ra2::recovered::b979::FileApi{using WriteFileProc=BOOL(WINAPI*)(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);WriteFileProc write_file=&::WriteFile;};
inline constexpr unsigned parser=0x821a80u;inline constexpr std::array<unsigned,5>globals{{0xb0e7c0u,0xb0fcecu,0xb0fcbcu,0xb0eca8u,0xb0fb0cu}};inline constexpr std::array<unsigned,5>key_literals{{0x7e6d54u,0x7e6d40u,0x7e6d34u,0x7e6d28u,0x7e6d20u}};
struct Fixture{unsigned section,section_name,key_table,section_table;std::array<unsigned,5>old_nodes;};
struct RawFileState{unsigned vptr=0x793c84u,mode=0,start=0,extent=0xffffffffu,handle=0xffffffffu,name=0x7c69c4u,stamps=0u;unsigned char owner=0;};
struct Observation{std::vector<std::string>chunks;RawFileState raw_file{};unsigned written=0,destructor_full_eax=0;};
Fixture prepare(Memory&,Heap&,const std::array<unsigned,5>&old_values,const std::array<unsigned,5>&new_values);
unsigned run(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
void cleanup(Memory&,Heap&,const Fixture&);
unsigned fun_00731930(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
}
