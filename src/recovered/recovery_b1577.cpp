#include "recovered/recovery_b1577.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1577 {
namespace {using U=std::uint32_t;void need(bool ok){if(!ok)throw std::domain_error("B1577 finite Unit timer numeric query");}
U rng(Memory&m,U g,U lo,U hi){need(lo==0&&hi==2&&m.r8(g)==0);const U span=hi-lo;U bit=31;while(bit>0&&!(span&(1u<<bit)))--bit;const U mask=bit==31?0xffffffffu:((1u<<(bit+1))-1u);U draw;do{const U a=m.r32(g+4),b=m.r32(g+8);need(a<250&&b<250);const U raw=m.r32(g+12+4*a)^m.r32(g+12+4*b);m.w32(g+12+4*a,raw);m.w32(g+4,a+1<250?a+1:0);m.w32(g+8,b+1<250?b+1:0);draw=raw&mask;}while(draw>span);return lo+draw;}}
static U unit_type(Memory&m,U self){need(m.r32(self)==0x798c88u);return m.r32(self+0x5ac);}
static U unit_kind(Memory&m,U self){need(m.r32(self)==0x798c88u);return 1u;} // Actual accepted6FEE90 whole leaf.
std::uint32_t run(Memory&m,const Inputs&i){const U s=i.cx;need(m.r32(s)==0x798c88u&&m.r32(s+0x228)!=0&&m.r32(s+0x98)==0);const U type=unit_type(m,s);need(type!=0&&m.r8(type+0x360)==0);const auto& before=i.fp.image;const U top=(before.word(4)>>11)&7;need(before.word(0)==0x0e7f&&before.word(4)==(top<<11)&&before.word(8)==0xffff);const U descriptor=0xa28000u+(m.r32(s+0x98)<<5);const auto rate=floating_b61::read64(m,descriptor+0x10),factor=floating_b61::read64(m,0x786608);need(rate==0x3ff0000000000000ull&&factor==0x408c200000000000ull&&m.r32(0x7c3a04)==0x0e7f);
i.fp.load64(rate);i.fp.multiply64(factor);const auto cw=i.fp.control();need(cw==m.r16(0x7c3a04));const auto converted=i.fp.pop_integer64();need(unit_kind(m,s)!=15u);
// Actual selected timer reads include the frame even for sentinel/zero duration.
const U start=m.r32(s+0x244),duration=m.r32(s+0x24c),frame=m.r32(0xa2896c);need(start==0xffffffffu&&duration==0);U remaining=duration;if(start!=0xffffffffu){const U elapsed=frame-start;if(global_b26::s32(elapsed)>=global_b26::s32(duration))remaining=0;else remaining=duration-elapsed;}need(remaining==0);
const U second_type=unit_type(m,s);need(second_type!=0&&m.r8(second_type+0x5cf)==0);const U scenario=m.r32(0xa255c0);need(scenario!=0);return static_cast<U>(converted)+rng(m,scenario+0x218,0,2);
}
}
