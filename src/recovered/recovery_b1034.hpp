#pragma once
#include "recovered/recovery_b979.hpp"
#include <string>
namespace ra2::recovered::b1034 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using FileApi=b979::FileApi;
struct Fixture {unsigned root,receiver,output;};
struct FileState {unsigned vptr=0x7856a0u,mode=1,extent=0xffffffffu,handle=0xffffffffu,name=0,buffer=0,buffer_size=0,position=0;unsigned char owner=1,buffer_owned=0;};
struct Observation {FileState file{};unsigned final_filename_free_bool=0,positive_key_reads=0,default_key_reads=0;};
Fixture prepare(Memory&,Inputs&,unsigned root,unsigned arena_base,const std::string&first,const std::string&second);
unsigned run(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
unsigned fun_0048f9d0(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
unsigned fun_0048fc50(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
unsigned fun_005c0690(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
}
