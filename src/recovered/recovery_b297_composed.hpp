#pragma once
#include "global_b26_memory.hpp"
namespace ra2::recovered::recovery_b297 {
using global_b26::s32;constexpr unsigned ones=0xffffffffu,G=0xffffffffu;
// Exact accepted composition isolated from construct_b101.cpp / preallocated_b66.cpp.
inline std::uint32_t base_ff10(Memory& m,std::uint32_t c){
    m.w32(c+8,0x785e44);m.w32(c+0xc,0x785e3c);
    m.w32(c+0x18,0);m.w32(c+0x1c,0);m.w8(c+0x20,0);
    const auto flags=m.r8(c+0x14)&0xf8u;
    m.w32(c+0x10,G);m.w32(c,0x785dd8);m.w32(c+4,0x785dbc);
    m.w32(c+8,0x785db4);m.w32(c+0xc,0x785dac);m.w8(c+0x14,flags);
    return c;
}
inline void init_ff10(Memory&m,unsigned c){(void)base_ff10(m,c);}
inline void append_one(Memory& m,std::uint32_t count_at,std::uint32_t capacity_at,
                std::uint32_t table_at,std::uint32_t object,const char* why) {
    const auto count=m.r32(count_at),capacity=m.r32(capacity_at);
    if(s32(count)<0 || s32(capacity)<0 || s32(count)>=s32(capacity))
        throw std::domain_error(why);
    m.w32(count_at,count+1u);
    m.w32(m.r32(table_at)+count*4u,object);
}
inline void call_5bf0(Memory&m,unsigned c){m.w32(c+12,0x8192ec);m.w32(c,0);m.w32(c+4,0);m.w32(c+8,0);}
inline std::uint32_t fun_005ca970(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);m.w32(c+0x24,0);m.w32(c+0x28,0);m.w32(c+0x2c,0);m.w32(c+0x6c,0xff);m.w32(c+0x70,0xff);
    m.w8(c+0x76,1);m.w8(c+0x7d,1);m.w8(c+0x85,1);m.w32(c+0x30,0);m.w32(c+0x34,0);m.w32(c+0x38,0);m.w32(c+0x64,ones);m.w8(c+0x68,0);m.w8(c+0x74,0);m.w8(c+0x75,0);m.w8(c+0x77,0);m.w8(c+0x78,0);m.w8(c+0x79,0);m.w8(c+0x7a,0);m.w8(c+0x7b,0);m.w8(c+0x7c,0);m.w32(c+0x80,ones);m.w8(c+0x84,0);
    m.w32(c+0x88,m.r32(0x00a5aa68u));m.w32(c+0x8c,m.r32(0x00a5aa6cu));m.w32(c+0x90,m.r32(0x00a5aa70u));m.w32(c+0x94,0);
    m.w32(c,0x00792458u);m.w32(c+4,0x0079243cu);m.w32(c+8,0x00792434u);m.w32(c+0xc,0x0079242cu);call_5bf0(m,c+0x3c);call_5bf0(m,c+0x50);
    append_one(m,0x00a27fc8u,0x00a27fc0u,0x00a27fbcu,c,"Block101 0x1ca970 registry one growth excluded");
    append_one(m,0x00aa8878u,0x00aa8870u,0x00aa886cu,c,"Block101 0x1ca970 registry two growth excluded");
    append_one(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c,"Block101 0x1ca970 registry three growth excluded");
    append_one(m,0x00aa8770u,0x00aa8768u,0x00aa8764u,c,"Block101 0x1ca970 registry four growth excluded");
    m.w8(c+0x14,m.r8(c+0x14)|2u);return c;
}
}
