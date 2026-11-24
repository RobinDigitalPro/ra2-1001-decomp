#include "recovered/recovery_b1371.hpp"
#include "recovered/rng_b70.hpp"
#include <stdexcept>

namespace ra2::recovered::b1371 {
namespace {
using U=std::uint32_t;
// Original 6036AF FCOM m64 does not pop. This elementary platform adapter
// uses the same explicit guest/host boundary as x87::State; no game bytes run.
void compare64(ra2::platform::x87::State& state,std::uint64_t operand){
    state.require_masked();ra2::platform::x87::Image host;
    asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfcoml %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]"
        : [host]"=m"(host.bytes),[guest]"+m"(state.image.bytes)
        : [operand]"m"(operand)
        : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
U draw(Memory& m,U state){
    Inputs nested{};nested.cx=state;nested.arg[0]=0;nested.arg[1]=0x7ffffffe;
    return rng_b70::fun_0062fe40(m,nested);
}
void contract(Memory& m,const Inputs& i){
    const U self=i.cx,count=m.r32(self+0xdc),value=m.r32(self+0xe0),descriptor=m.r32(self+0x98);
    const U state=m.r32(0xa255c0)+0x218,p=m.r32(state+4),q=m.r32(state+8);
    const auto cw=i.fp.image.word(0);
    if(count<2||count>32||value<17||value>41||m.r32(self+0xb8)!=0||m.r32(self+0xac)!=0||
       floating_b61::read64(m,descriptor+0x2c8)!=0||m.r8(state)!=0||p>=250||q!=(p+1)%250||
       i.fp.image.word(8)!=0xffff||(i.fp.image.word(4)&0x3800)!=0||
       (cw&0xf0ff)!=0x007f||(cw&0x0300)==0x0100)
        throw std::domain_error("B1371 requires bounded active countdown, empty childlist, zero threshold, enabled adjacent-index RNG and empty masked x87");
    const U x=m.r32(state+12+4*p)^m.r32(state+12+4*q);
    const U y=m.r32(state+12+4*q)^m.r32(state+12+4*((q+1)%250));
    const U first=x&0x7fffffff,second=y&0x7fffffff;
    if(first!=0x20000000||(second!=0x20000000&&second!=0x40000000&&second!=0x60000000)||
       floating_b61::read64(m,0x787280)!=0x3e00000000400000ull||
       floating_b61::read64(m,0x788d50)!=0x3fd3333333333333ull||
       floating_b61::read64(m,0x787270)!=0x3fe3333333333333ull)
        throw std::domain_error("B1371 requires reviewed finite two-draw state and authentic original literals");
}
}

// RVA 203250: active non-spawning update. Genuine B70 RNG is composed twice;
// original x87 instruction order, comparisons and integer clamps are retained.
std::uint32_t fun_00603250(Memory& m,const Inputs& i){
    contract(m,i);
    const U self=i.cx;
    const U first=draw(m,m.r32(0xa255c0)+0x218);
    // The original aligned private frame produces [T+1C] before FILD.
    i.fp.load_integer32(first);
    i.fp.multiply64(floating_b61::read64(m,0x787280));
    i.fp.compare_pop64(floating_b61::read64(m,m.r32(self+0x98)+0x2c8));
    if((i.fp.status()&0x4100)!=0)
        throw std::domain_error("B1371 positive first fraction must select original non-spawning branch");
    const U remaining=m.r32(self+0xdc)-1;
    m.w32(self+0xdc,remaining);
    const U second=draw(m,m.r32(0xa255c0)+0x218);
    // Second produced local [T+20], not an outer caller word.
    i.fp.load_integer32(second);
    i.fp.multiply64(floating_b61::read64(m,0x787280));
    compare64(i.fp,floating_b61::read64(m,0x788d50));
    if((i.fp.status()&0x0100)!=0){
        const U value=m.r32(self+0xe0)-3;
        i.fp.pop_st0();
        m.w32(self+0xe0,global_b26::s32(value)>17?value:17);
    }else{
        i.fp.compare_pop64(floating_b61::read64(m,0x787270));
        if((i.fp.status()&0x0100)!=0){
            const U value=m.r32(self+0xe0)+3;
            m.w32(self+0xe0,global_b26::s32(value)<41?value:41);
        }
    }
    // Full EAX is overwritten at 6036F9; B8=0 bypasses both child loops.
    return m.r32(self+0xb8);
}
}
