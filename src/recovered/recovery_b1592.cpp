#include "recovered/recovery_b1592.hpp"
#include "recovered/recovery_b701.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1592 {namespace {
void need(bool value){if(!value)throw std::domain_error("B1592 finite genuine frame remainder query");}
struct Span{U address,size;};
void disjoint(Memory&m,const std::array<Span,10>&spans){for(U j=0;j<spans.size();++j){const auto&s=spans[j];need(s.address&&s.size&&std::uint64_t(s.address)+s.size<=0x100000000ull);if(j+1<spans.size()){(void)m.r8(s.address);(void)m.r8(s.address+s.size-1);}for(U k=0;k<j;++k)need(std::uint64_t(s.address)+s.size<=spans[k].address||std::uint64_t(spans[k].address)+spans[k].size<=s.address);}}
}
U fun_004ff850(Memory&m,const Inputs&i){const U self=i.cx;need(self&&m.r32(self)==0x78e540);const U type=m.r32(self+0x5a8),owner=m.r32(self+0x1b4),current=m.r32(0xa1e0e4);need(type&&owner&&current);const U table=m.r32(type+0xb98);need(table);disjoint(m,{{{self,0x5b0},{type,0xb9c},{owner,0x136},{current,0x34},{table,64},{0x78e000,4096},{0xa1e000,4096},{0xa25000,4096},{0xa28000,4096},{0x7d000000,0x8000}}});
 need(m.r32(0x78e540+0x3d4)==0x6ce250&&m.r32(0x78e540+0xc0)==0x41b410);const U index=m.r32(self+0x5ac),counter=m.r32(self+0xe0);need(index<4&&counter<=0x7fffffffu&&m.r8(type+0xb44)==0);need(m.r32(self+0x184)==0xffffffffu&&m.r32(self+0x18c)==0&&m.r8(self+0x170)==1&&m.r32(self+0x174)==0&&m.r8(owner+0x134)==1&&m.r8(owner+0x135)==1&&m.r32(0xa255c8)==0&&m.r32(0xa2896c)<=7);
 Inputs child=i;child.cx=self;child.arg[0]=current;const U enabled=recovery_b701::fun_006ce250(m,child);i.fp=child.fp;need((enabled&255u)==1); // Actual unchanged callee, not a modeled predicate result.
 const U record=table+16*index,first=m.r32(record),frames=m.r32(record+4);need(first>0&&first<=0x100000&&frames>=1&&frames<=31&&m.r32(record+8)==0);const auto quotient_remainder=global_b26::s32(counter)%global_b26::s32(frames);return first+U(quotient_remainder);
}
}
