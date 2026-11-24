#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>
namespace ra2::recovered::recovery42_vectors {
using Memory=ra2::recovered::global_b26::Memory; using Inputs=ra2::recovered::global_b26::Inputs; using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t rva_000fa910(Memory&,const Inputs&,Heap&);
std::uint32_t rva_000fa9a0(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0010ac20(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0024b610(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0024b6a0(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0024b7c0(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0024b850(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0024b970(Memory&,const Inputs&,Heap&);
std::uint32_t rva_002d4f50(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0018a980(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0018aaa0(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0006ca20(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0006c7f0(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0018bcd0(Memory&,const Inputs&,Heap&);
}
