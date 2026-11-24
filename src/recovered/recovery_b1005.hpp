#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1005 {
using Memory=ra2::recovered::b979::Memory;using Inputs=ra2::recovered::b979::Inputs;using Heap=ra2::recovered::b979::Heap;using FileApi=ra2::recovered::b979::FileApi;
struct Fixture{unsigned receiver,source_holder,source_chars,filename=0;};
struct FileState{unsigned vptr=0x7856a0u,mode=1,extent=0xffffffffu,handle=0xffffffffu,name=0,buffer=0,buffer_size=0,position=0;unsigned char owner=1,buffer_owned=0;};
struct Observation{FileState file{};unsigned parser=0,final_filename_free_bool=0;};
Fixture prepare_common(Memory&,Inputs&,unsigned arena_base);
Fixture prepare_model(Memory&,Heap&,Inputs&,unsigned arena_base);
unsigned run(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
void cleanup(Memory&,Heap&,const Fixture&,unsigned parser);
unsigned fun_005b42e0(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&,Observation&);
}
