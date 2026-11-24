#include "recovery_b1712.hpp"
namespace ra2::delivery::query1cbf20 {
using U=unsigned;using ra2::delivery::query51090::detail::need;
void preflight(Memory&m,unsigned self){
    need(m.r8(0xa285a8u)!=0&&m.r8(0xa283c4u)!=0||m.r32(0xa283c4u)!=0);
    need(m.r32(self)==0x7992b8u&&m.r8(self+0x76u)!=0&&m.r8(self+0x74u)==0&&m.r8(self+0x7du)==0);
    const U type=m.r32(self+0xecu);need(type==0||m.r32(type)==0x7994d0u);
    const U map=m.r32(0x821cacu);if(map)(void)m.r8(map+0xd7du);
}
Result run(Memory&m,unsigned entry,unsigned char*storage,unsigned size,const NativeState&i,const fp::Image&incoming){
    need(entry>=0x1b0u&&entry<=0xffffffbbu&&size==500u);
    need(reinterpret_cast<std::uintptr_t>(storage)==std::uintptr_t(entry-0x1b0u));
    State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.bx=i.bx;s.bp=i.bp;s.si=i.si;s.di=i.di;
    s.arithmetic_flags=i.flags;s.fp.image=incoming;
    Frame f{entry,entry,m.r32(entry)};
    s.arithmetic_flags=ra2::delivery::placement1cbf20::root(m,s,f,i.flags);
    Result r{s.ax,s,{}};for(unsigned k=0;k<16;++k)r.words[k]=m.r32(entry+4u+4u*k);
    return r;
}
}
