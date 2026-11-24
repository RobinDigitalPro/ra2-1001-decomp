#include "recovered/recovery_b1575.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1575 {
namespace {using U=std::uint32_t;void need(bool ok){if(!ok)throw std::domain_error("B1575 finite Building numeric query");}
U rng(Memory&m,U g,U lo,U hi){need(lo==0&&hi==2&&m.r8(g)==0);const U span=hi-lo;U bit=31;while(bit>0&&!(span&(1u<<bit)))--bit;const U mask=bit==31?0xffffffffu:((1u<<(bit+1))-1u);U draw;do{const U a=m.r32(g+4),b=m.r32(g+8);need(a<250&&b<250);const U raw=m.r32(g+12+4*a)^m.r32(g+12+4*b);m.w32(g+12+4*a,raw);m.w32(g+4,a+1<250?a+1:0);m.w32(g+8,b+1<250?b+1:0);draw=raw&mask;}while(draw>span);return lo+draw;}}
std::uint32_t run(Memory&m,const Inputs&i){const U s=i.cx;need(m.r32(s)==0x787bbcu&&m.r32(s+0xa8)==2&&m.r32(s+0x98)==0);const U type=m.r32(s+0x418);need(type!=0&&m.r8(type+0x1352)==1);const auto& before=i.fp.image;const U top=(before.word(4)>>11)&7;need(before.word(0)==0x0e7f&&before.word(4)==(top<<11)&&before.word(8)==0xffff);const U descriptor=0xa28000u+(m.r32(s+0x98)<<5);const auto rate=floating_b61::read64(m,descriptor+0x18);const auto factor=floating_b61::read64(m,0x786608);need(rate==0x3ff0000000000000ull&&factor==0x408c200000000000ull&&m.r32(0x7c3a04)==0x0e7f);const U scenario=m.r32(0xa255c0);need(scenario!=0);
// Actual selected descriptor arithmetic and equal-cached-CW conversion branch.
i.fp.load64(rate);i.fp.multiply64(factor);const auto cw=i.fp.control();need(cw==m.r16(0x7c3a04));const auto converted=i.fp.pop_integer64();return static_cast<U>(converted)+rng(m,scenario+0x218,0,2);
}
}
