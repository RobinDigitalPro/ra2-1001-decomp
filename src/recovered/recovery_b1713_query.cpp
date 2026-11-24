#include "recovery_b1713_query.hpp"
#include <stdexcept>
namespace ra2::recovered::numeric_b105{void root363380_a(Memory&,State&,Frame&);}
namespace ra2::delivery::query363380 {
static void need(bool v){if(!v)throw std::invalid_argument("363380 domain A selected contract");}
void preflight(Memory& m,unsigned d,unsigned t){
    // domain A: callback pointer is the authentic 0x7122A0, owner [D+0xAC] has [owner+0x508]==-1, exactly one outer item whose message code is 3 and whose single record has timestamp T
    need(m.r32(d+0x48u)==0x7122a0u);const unsigned ow=m.r32(d+0xacu);need(ow!=0u&&m.r32(ow+0x508u)==0xffffffffu);
    need(m.r32(d+0x724u)==1u&&m.r32(d+0x73cu)==0u);const unsigned o1=m.r32(d+0x734u),b1=m.r32(d+0x738u);need(o1&&b1);
    need(m.r32(o1)==3u);need(m.r32(b1)==1u);const unsigned data=m.r32(b1+8u);need(data&&m.r32(data+8u)==t);
}
Result run(Memory& m,unsigned entry,unsigned char* storage,unsigned size,const NativeState& i,const fp::Image& incoming){
    need(entry>=0x1b0u&&entry<=0xffffffbbu&&size==500u);need(reinterpret_cast<std::uintptr_t>(storage)==std::uintptr_t(entry-0x1b0u));
    State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.bx=i.bx;s.bp=i.bp;s.si=i.si;s.di=i.di;s.arithmetic_flags=i.flags;s.fp.image=incoming;
    Frame f{entry,entry,m.r32(entry)};
    ra2::recovered::numeric_b105::root363380_a(m,s,f);
    Result r{s.ax,s,{}};for(unsigned k=0;k<16;++k)r.words[k]=m.r32(entry+4u+4u*k);return r;
}
}
