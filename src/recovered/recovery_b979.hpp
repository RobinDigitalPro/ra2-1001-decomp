#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include "platform/file_heap_adapter249.hpp"
namespace ra2::recovered::b979 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;
using FileApi=ra2::platform::file_heap249::FileApi;
class Heap:public ra2::platform::ordinary_heap::Heap{public:virtual std::uint32_t allocate_reader()=0;virtual void free_reader(std::uint32_t)=0;};
std::uint32_t run(Memory&,const Inputs&,Heap&,FileApi&,std::uint32_t root_rva);
std::uint32_t fun_0072dc70(Memory&,const Inputs&,Heap&,FileApi&);
std::uint32_t fun_0072def0(Memory&,const Inputs&,Heap&,FileApi&);
}
