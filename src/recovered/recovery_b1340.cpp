#include "recovery_b1340.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::b1340 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
std::uint32_t fun_006fbd80(Memory&m,const Inputs&i){
 using namespace numeric_b88::detail;
 const auto self=i.cx,target=i.arg[0];need(target&&m.r8(m.r32(self+0x5acu)+0xaf3u),"1340 real positive actor gate");
 for(auto actor:{self,target})need(m.r32(actor)==0x78612cu&&m.r32(0x786174u)==0x5cd4d0u,"1340 actual coordinate-copy provider");
 need(m.r32(0x7861acu)==0x6b6910u&&m.r32(0x7861b0u)==0x41b600u,"1340 original chained type provider");
 need(m.r8(m.r32(target+0x5acu)+0x1fdu)!=0u,"1340 eligible target type");
 // The actual5CD4D0 copies actor+88,+8C,+90 into two private XYZ records.
 const auto dx=m.r32(self+0x88u)-m.r32(target+0x88u),dy=m.r32(self+0x8cu)-m.r32(target+0x8cu),dz=m.r32(self+0x90u)-m.r32(target+0x90u);
 need(dx==4u&&dy==0u&&dz==0u,"1340 finite nonzero distance");
 auto&f=i.fp;need(f.image.word(8)==0xffffu&&((f.status()>>11)&7u)==0u,"1340 empty numeric entry");
 f.load_integer32(dy);f.load_integer32(dz);f.load_integer32(dx);
 reg<0xd9c0>(f);reg<0xd8c9>(f);reg<0xd9c2>(f);reg<0xd8cb>(f);reg<0xdec1>(f);
 reg<0xd9c3>(f);reg<0xd8cc>(f);reg<0xdec1>(f);
 const auto squared=f.pop64();f.pop_st0();f.pop_st0();f.pop_st0();
 // Exact originalBA080 LUT approximation and76AA50 conversion, neverFSQRT.
 need(m.r32(0x80013cu)==0u,"1340 original LUT index0");root(m,f,squared);const auto distance=integer(m,f);
 const auto rules=m.r32(0x821b88u),house=m.r32(self+0x1b4u);
 need(distance==4u&&s32(distance)<=s32(m.r32(rules+0x1390u)),"1340 within real range");
 // Both actual4F47F0 evaluations take the two-byte false owner route.
 need(m.r32(0xa255c8u)==0u&&m.r8(house+0x134u)==0u&&m.r8(house+0x135u)==0u,"1340 actual false owner predicate");
 need(m.r32(house+0xc8u)!=2u&&s32(m.r32(house+0x194u))>=s32(m.r32(rules+0x10b0u)),"1340 owner capability gates");
 need(m.r32(0x7861f0u)==0x41b420u&&m.r8(target+0x170u)==0u,"1340 actual target170 AL provider");
 // EAX carries PUSH owner into the actual MOV AL,[target+170]/RET4.
 return (house&0xffffff00u)|1u;
}
}
