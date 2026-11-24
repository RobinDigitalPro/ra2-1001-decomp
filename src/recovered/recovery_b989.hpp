#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b989 {
using Memory=ra2::recovered::b979::Memory;
using Inputs=ra2::recovered::b979::Inputs;
using Heap=ra2::recovered::b979::Heap;
using FileApi=ra2::recovered::b979::FileApi;
std::uint32_t run(Memory&,const Inputs&,Heap&,FileApi&,std::uint32_t root_rva=0x32d870u);
std::uint32_t fun_0072d870(Memory&,const Inputs&,Heap&,FileApi&);
}
