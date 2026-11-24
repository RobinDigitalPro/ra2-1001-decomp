#pragma once
#include "recovered/leaf_b16_a.hpp"
namespace ra2::recovered::recovery_b311_helpers {
using leaf::Memory;using leaf::Inputs;
inline std::uint32_t fun_00430df0(Memory& m,const Inputs& in){
    const auto src=in.cx;std::uint32_t out=in.dx;const auto units=in.arg[0];
    m.w8(out,m.r8(src)&1u);
    if(units==0){m.w16(out-2,0);return 0;}
    std::uint32_t src_bit=0,out_bits=0,units_done=0,input_units=0;bool zero_word=false;
    while(units_done<units){
        ++input_units;
        ++src_bit;
        if(input_units%7u==0)++src_bit;
        const auto bit=(m.r8(src+src_bit/8u)&(1u<<(src_bit%8u)))?1u:0u;
        const auto dst_byte=input_units/8u;
        const auto dst_bit=input_units%8u;
        if(dst_bit==0)m.w8(out+dst_byte,0);
        if(bit)m.w8(out+dst_byte,m.r8(out+dst_byte)|(1u<<dst_bit));
        ++out_bits;
        if(out_bits%16u==0){
            ++units_done;
            if(m.r16(out+out_bits/8u-2u)==0){zero_word=true;break;}
        }
    }
    if(!zero_word)m.w16(out+units*2u-2u,0);
    return units_done;
}
inline std::uint32_t fun_0076efc9(Memory& m,const Inputs& i) {
    auto dst=i.arg[0],src=i.arg[1];for(;;){const auto v=m.r16(src);m.w16(dst,v);dst+=2;src+=2;if(v==0)break;}return i.arg[0];
}
inline std::uint32_t fun_0076ef45(const std::uint16_t* text) {
    std::uint32_t length = 0;
    while (text[length] != 0) ++length;
    return length;
}
}
