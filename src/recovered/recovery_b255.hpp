#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>
namespace ra2::recovered::recovery42_vectors {
using Memory=ra2::recovered::global_b26::Memory; using Inputs=ra2::recovered::global_b26::Inputs; using Heap=ra2::platform::ordinary_heap::Heap;
std::uint32_t rva_000c2220(Memory&,const Inputs&,Heap&);
std::uint32_t rva_000f8160(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0011dca0(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0018bf50(Memory&,const Inputs&,Heap&);
std::uint32_t rva_002260d0(Memory&,const Inputs&,Heap&);
std::uint32_t rva_002ced30(Memory&,const Inputs&,Heap&);
}
