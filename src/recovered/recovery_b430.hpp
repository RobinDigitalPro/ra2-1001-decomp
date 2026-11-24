#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace ra2::recovery_b430 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::global_b26::Inputs;

// The private model is deliberately limited to the observed fixed 320-byte
// operation and the original positive 12-byte allocation route.
template<class Heap>
std::uint32_t fun_005c22e0(Memory& m,const Inputs&,Heap& heap) {
    constexpr std::uint32_t begin=0x00a579b8u;
    constexpr std::uint32_t tail=0x00a579f8u;
    std::uint8_t saved[256];
    for(unsigned i=0;i<sizeof(saved);++i) saved[i]=m.r8(tail+i);
    for(unsigned i=0;i<sizeof(saved);++i) m.w8(tail+i,0);
    std::uint32_t sum=0;
    for(unsigned i=0;i<80;++i) {
        const auto word=m.r32(begin+4u*i);
        sum=static_cast<std::uint32_t>((sum<<1)|(sum>>31));
        sum+=word;
    }
    const auto result=heap.allocate(12);
    static constexpr char digits[]="0123456789ABCDEF";
    for(unsigned i=0;i<8;++i) heap.w8(result+i,static_cast<std::uint8_t>(digits[(sum>>(28u-4u*i))&15u]));
    heap.w8(result+8,0);
    for(unsigned i=0;i<sizeof(saved);++i) m.w8(tail+i,saved[i]);
    return result;
}
}
