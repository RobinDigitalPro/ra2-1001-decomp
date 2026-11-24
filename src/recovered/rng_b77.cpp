#include "rng_b77.hpp"
#include "rng_b70.hpp"
#include <stdexcept>

namespace ra2::recovered::global_b26 {
// Original RVA22fd30. All arithmetic is the original modulo-32 arithmetic;
// SAR is explicit, including the unusual signed half-word recombination.
std::uint32_t fun_0062fd30(Memory& m,const Inputs& in) {
    m.w32(in.cx+4,0);m.w32(in.cx+8,103);
    for(std::uint32_t index=0;index<250;++index){
        auto value=index,previous=in.arg[0];
        for(unsigned r=0;r<4;++r){
            const auto old=value;
            const auto mixed=m.r32(0x7d8244+4*r)^value;
            const auto high=sar(mixed,16),low=mixed&0xffffu;
            const auto square=~(high*high)+low*low;
            const auto halves=sar(square,16)|(square<<16);
            value=((halves^m.r32(0x7d8294+4*r))+high*low)^previous;
            previous=old;
        }
        m.w32(in.cx+12+4*index,value);
    }
    m.w8(in.cx,0);return in.cx;
}

// Original RVA234860, the eight-bit append route before the 2048-bit refresh.
// The excluded hash refresh has no placeholder or synthetic helper result.
std::uint32_t fun_00634860(Memory& m,const Inputs& in) {
    auto cursor=m.r32(in.cx+12);
    if(cursor>2039)throw std::domain_error("Block77 byte append crosses deferred hash refresh");
    auto byte=in.arg[0]&255u;
    for(unsigned k=0;k<8;++k){
        if(byte&1u){const auto at=in.cx+20+((cursor>>3)&255u);m.w8(at,m.r8(at)^(1u<<(cursor&7u)));}
        m.w32(in.cx+12,++cursor);
        byte=((byte>>1)|(byte&0x80u))&255u;
        in.arg[0]=(in.arg[0]&0xffffff00u)|byte;
    }
    return 0;
}

// Original RVA1757e0. Calls the accepted real bounded RNG implementation;
// the caller itself contains no floating-point operations.
std::uint32_t fun_005757e0(Memory& m,const Inputs& in) {
    const auto index=in.arg[0];
    if(index>4)throw std::domain_error("Block77 table index outside five-row domain");
    const auto at=4*index;
    auto draw=[&](std::uint32_t lo,std::uint32_t hi){
        floating_b61::Inputs call;call.cx=0x821558;call.arg[0]=lo;call.arg[1]=hi;
        return rng_b70::fun_0062fe40(m,call);
    };
    m.w32(in.cx+0x4c,draw(m.r32(0x7cb630+at),m.r32(0x7cb644+at)));
    m.w32(in.cx+0x44,draw(m.r32(0x7cb694+at),m.r32(0x7cb6a8+at)));
    m.w32(in.cx+0x60,draw(m.r32(0xa5866c+at),m.r32(0x7cb680+at)));
    m.w32(in.cx+0x6c,draw(m.r32(0xa58644+at),m.r32(0x7cb658+at)));
    m.w32(in.cx+0x70,draw(m.r32(0x7cb608+at),m.r32(0x7cb61c+at)));
    m.w32(in.cx+0x54,m.r32(in.cx+0x40)*20u);
    m.w32(in.cx+0x58,draw(0,100));
    auto lo=s32(m.r32(m.r32(0xa57c08)+at));
    auto hi=s32(m.r32(m.r32(0xa57c24)+at));
    lo=lo<0?0:lo>100?100:lo;hi=hi<0?0:hi>100?100:hi;
    if(lo>hi)lo=hi;
    m.w32(in.cx+0x5c,draw(std::uint32_t(lo),std::uint32_t(hi)));
    const auto result=draw(0,65535);m.w32(in.cx+0x74,result);return result;
}
}
