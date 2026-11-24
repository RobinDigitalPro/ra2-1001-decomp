#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b999 {
using Memory=ra2::recovered::b979::Memory;using Inputs=ra2::recovered::b979::Inputs;using Heap=ra2::recovered::b979::Heap;using FileApi=ra2::recovered::b979::FileApi;
struct Fixture{std::uint32_t root,receiver,file,pipe,filename;};
Fixture prepare(Memory&,Heap&,Inputs&,std::uint32_t root,std::uint32_t arena_base);
std::uint32_t run(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&);
void cleanup(Memory&,Heap&,FileApi&,const Fixture&);
std::uint32_t fun_004692d0(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&);
std::uint32_t fun_00469400(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&);
std::uint32_t fun_0050b080(Memory&,const Inputs&,Heap&,FileApi&,const Fixture&);
}
