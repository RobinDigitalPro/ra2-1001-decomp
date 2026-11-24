#include "recovered/recovery_b1573.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::recovery_b1573 {
using U=std::uint32_t;
static void need(bool b){if(!b)throw std::runtime_error("B1573 finite public projection");}
static U kind(Memory&m,U self){need(m.r32(self)==0x798c88);return 1;}// actual Unit kind leaf, used by base path
static U type(Memory&m,U self){return m.r32(self+0x5ac);}// actual 6F9C70 getter
static U rng(Memory&m,U g,U lo,U hi){need(lo==0&&hi==2&&m.r8(g)==0);const U span=hi-lo;U bit=31;while(bit>0&&!(span&(1u<<bit)))--bit;const U mask=~(0xffffffffu<<((bit+1u)&31u));U draw;do{const U a=m.r32(g+4),b=m.r32(g+8);need(a<250&&b<250);draw=m.r32(g+12+4*a)^m.r32(g+12+4*b);m.w32(g+12+4*a,draw);m.w32(g+4,a+1<250?a+1:0);m.w32(g+8,b+1<250?b+1:0);draw&=mask;}while(draw>span);return lo+draw;}
U run(Memory&m,const Inputs&i){const U s=i.cx;need(m.r32(s)==0x798c88);need(m.r8(type(m,s)+0x360)==0);need(m.r8(s+0x57e)==0&&m.r32(s+0x228)==0);for(U off:{0x408u,0x564u,0x488u,0x98u,0x4b4u})need(m.r32(s+off)==0);need(m.r8(s+0x577)==0&&m.r32(s+0x418)==0xffffffffu&&m.r8(s+0x59d)==0);need(m.r32(s+0x468)==0&&m.r32(s+0x46c)==0x3fe00000u);need(i.fp.image.word(0)==0x0e7f&&i.fp.image.word(4)==0&&i.fp.image.word(8)==0xffff);need(m.r32(0x785708)==0&&m.r32(0x78570c)==0x3ff00000u&&m.r32(0x786610)==0&&m.r32(0x786614)==0);need(m.r32(0x786608)==0&&m.r32(0x78660c)==0x408c2000u&&m.r32(0x7c3a04)==0x0e7f);
// Actual 4C6AF0/6C9E60 public zero-provider branches: no optional service dereference.
m.w8(s+0x59d,1);need(kind(m,s)==1);i.fp.load64(0);i.fp.compare_pop64(0x3ff0000000000000ull);(void)i.fp.status();i.fp.load64(0);i.fp.compare_pop64(0);(void)i.fp.status();m.w32(s+0x468,0);m.w32(s+0x46c,0);
// Actual 4CD6A0 +438 returns one; Unit414 changes its own temporary arg1 low byte to zero.
const U has=m.r32(s+0x4b4)!=0xffffffffu;need(has==1);
const U descriptor=0xa28000u+(m.r32(s+0x98)<<5u);const std::uint64_t rate=std::uint64_t(m.r32(descriptor+0x10))|(std::uint64_t(m.r32(descriptor+0x14))<<32);need(rate==0x3ff0000000000000ull);i.fp.load64(rate);i.fp.multiply64(0x408c200000000000ull);const auto cw=i.fp.control();need(cw==m.r32(0x7c3a04));const auto integral=i.fp.pop_integer64();const U scenario=m.r32(0xa255c0);return static_cast<U>(integral)+rng(m,scenario+0x218,0,2);
}
}
