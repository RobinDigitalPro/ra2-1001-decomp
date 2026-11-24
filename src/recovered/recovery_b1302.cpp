#include "recovery_b1302.hpp"
#include "recovered/recovery_b110.hpp"
#include "recovered/leaf_memory.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1302 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
constexpr U kVptr=0x0078612cu,kMap=0x0081a820u,kTableGlobal=0x0084e4fcu;
constexpr U kCurrent=0x0084e230u,kRoute=0x00a255c8u,kFallback=0x00a57610u;
int16_t sx16(U x){return static_cast<int16_t>(x&0xffffu);}
U pack(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16u);}
U round_full(U fixed){const auto s=static_cast<std::int32_t>(fixed);return U((s+(s<0?255:0))>>8);}
U round_coord(U fixed){return round_full(fixed)&0xffffu;}
U current_pair(Memory&m,U self){need(m.r32(self)==kVptr&&m.r32(kVptr+0x48u)==0x005cd4d0u,"B1302 original +48 coordinate slot");const U x=round_coord(m.r32(self+0x88u)),y=round_coord(m.r32(self+0x8cu));return (x&0xffffu)|((y&0xffffu)<<16u);}
U map_cell(Memory&m,U p){const int x=sx16(p),y=sx16(p>>16u);const std::int64_t idx=std::int64_t(y)*512+x;if(idx<0||idx>=0x40000){m.w32(0x00a57634u,p);return kFallback;}const U table=m.r32(kMap+0x138u);need(table!=0,"B1302 borrowed map table");const U cell=m.r32(table+4u*U(idx));if(!cell){m.w32(0x00a57634u,p);return kFallback;}return cell;}
void require_map_accept(Memory&m,U p){const int x=sx16(p),y=sx16(p>>16u);need(x==4&&y==4,"B1302 finite initial 0x557450 point (4,4)");const std::int64_t idx=std::int64_t(y)*512+x;need(idx>=0&&idx<0x40000,"B1302 0x557450 signed grid bounds");const U table=m.r32(kMap+0x138u);need(table!=0,"B1302 0x557450 map table");const U cell=m.r32(table+4u*U(idx));need(cell!=0,"B1302 0x557450 selected nonnull map cell");const int lo=static_cast<std::int8_t>(m.r8(cell+0x11bu));const int flag=m.r8(cell+0x11cu);need(flag==0&&lo==0,"B1302 0x557450 branch bypasses cell-bound correction with signed cell fields zero");const int f0=static_cast<int>(m.r32(kMap+0xf0u)),f4=static_cast<int>(m.r32(kMap+0xf4u)),f8=static_cast<int>(m.r32(kMap+0xf8u)),fc=static_cast<int>(m.r32(kMap+0xfcu)),f100=static_cast<int>(m.r32(kMap+0x100u)),f104=static_cast<int>(m.r32(kMap+0x104u));need(f0==1&&f4==0&&f8==0&&fc==0&&f100==10&&f104==9,"B1302 exact borrowed row-limit fixture for 0x557450");const int sum=x+y,delta=x-y,reverse=y-x;need(sum>=f0+2*fc+4,"B1302 original 557450 lower diagonal arm");need(sum>f0+2*(f4+fc)+lo,"B1302 original 557450 first upper diagonal arm");need(sum<=f0+2*(f104+fc)+2+lo,"B1302 original 557450 second upper diagonal arm");need(delta<2*(f100+f8)-f0,"B1302 original 557450 x-minus-y arm");need(reverse<f0-2*f8,"B1302 original 557450 y-minus-x arm");}
U projected_pair(Memory&m,U self){const int index=static_cast<std::int8_t>(m.r8(self+0x574u));need(index>=0,"B1302 finite nonnegative +574 0x4CA2F0 branch");const U types=m.r32(kTableGlobal);need(types!=0,"B1302 explicit borrowed 0x84E4FC type table");const U record=m.r32(types+4u*U(index));need(record!=0,"B1302 borrowed selected projection record");const U fixed=m.r32(record+0x28u);const int x=sx16(fixed),y=sx16(fixed>>16u);return pack(x,y);}
// Calls accepted 0x54CC50 using caller-provided local pair addresses.
U query_map_at(Memory&m,const Inputs&i,U projected_ptr,U input_ptr,U b8result,U type){recovery_b110::Inputs q{};q.cx=kMap;q.arg[0]=projected_ptr;q.arg[1]=input_ptr;q.arg[2]=type;q.arg[3]=b8result;q.fp=i.fp;const U r=recovery_b110::fun_0054cc50(m,q);i.fp=q.fp;return r;}
U cbe(Memory&m,const Inputs&i){const U self=i.cx,point=i.arg[0];need(m.r32(self)==kVptr,"B1302 CBE receiver vptr");need(m.r32(kVptr+0x4cu)==0x004ca2f0u&&m.r32(kVptr+0x80u)==0x006b6910u&&m.r32(kVptr+0x84u)==0x0041b600u&&m.r32(kVptr+0xb8u)==0x004cc0b0u&&m.r32(kVptr+0x194u)==0x00418e00u,"B1302 actual reached receiver slots");need(sx16(i.arg[1])==0&&sx16(i.arg[2])==0,"B1302 bounded zero-offset CBE route");need(m.r32(0x00a255c8u)!=0,"B1302 borrowed live map flag skips projection helpers");need(m.r32(self+0x4c4u)==0,"B1302 receiver bypasses 6AFFE0/557530 in +194");const U packed=m.r32(point);require_map_accept(m,packed); // exact positive 0x557450 cell/bounds route; no side effects on this nonfallback branch
// 0x4CA2F0 output from the original nonnegative-index branch, converted back to signed integer coordinates.
const U p=projected_pair(m,self);std::uint8_t bytes[20]{};leaf::Memory pairs(bytes,0x7d200000u,20u);Memory view=m;view.add(pairs);view.w32(0x7d200000u,p);view.w32(0x7d200010u,packed);
// Original 0x4CC0B0 preserves caller EAX high bits and clears AL for +574>=0.
const U b8=(m.r32(self)&0xffffff00u);
const U typeptr=m.r32(self+0x5acu);need(typeptr!=0,"B1302 original 6B6910->41B600 typed receiver field");const U type=m.r32(typeptr+0x500u);need(type==7u,"B1302 accepted B1298 type-7 positive query domain");
const U query=query_map_at(view,i,0x7d200000u,0x7d200010u,b8,type);need((query&0xffu)==1u,"B1302 accepted 54CC50 positive region query");
const U cell=map_cell(m,packed);need(cell!=kFallback,"B1302 current point resolves to a genuine borrowed map cell");need(m.r32(cell+0xe4u)==0u,"B1302 418E00 skips object relationship branches");need(m.r32(cell+0xecu)==0xbu&&m.r8(cell+0x11eu)>=0x30u,"B1302 4CBE60 final tile class predicate");
// 418E00 passes literal type 4 to 478360; that exact original fast arm returns AL=1.
// A255C8!=0 then branches to XOR EAX,EAX at 418EFA, so the callback's full EAX is 0.
need(m.r32(kRoute)!=0,"B1302 original 418E00 successful-zero return route");
m.w32(point,packed);i.arg[0]=packed;i.arg[1]=p;i.arg[2]=p;return 1u;}
U cbd(Memory&m,const Inputs&i){const U self=i.cx,out=i.arg[0];need(m.r32(self)==kVptr,"B1302 CBD receiver vptr");const U p=current_pair(m,self);std::uint8_t bytes[4]{};leaf::Memory pair(bytes,0x7d210000u,4u);Memory view=m;view.add(pair);view.w32(0x7d210000u,p);Inputs nested=i;nested.arg[0]=0x7d210000u;nested.arg[1]=0;nested.arg[2]=0;const U ok=cbe(view,nested);i.fp=nested.fp;if((ok&0xffu)==0u)throw std::domain_error("B1302 finite CBD packet covers first CBE60 positive branch only");const U result=view.r32(0x7d210000u);m.w32(out,result);return out;}
U cc(Memory&m,const Inputs&i){const U self=i.cx;need(m.r32(self)==kVptr,"B1302 CC receiver vptr");need(m.r32(self+0x494u)==0u,"B1302 CC enabled path");std::uint8_t bytes[4]{};leaf::Memory out(bytes,0x7d220000u,4u);Memory view=m;view.add(out);Inputs nested=i;nested.arg[0]=0x7d220000u;nested.arg[1]=i.arg[0];const U ptr=cbd(view,nested);i.fp=nested.fp;const U found=view.r32(ptr);i.arg[0]=found;need(!(std::uint16_t(found)==m.r16(kCurrent)&&std::uint16_t(found>>16u)==m.r16(kCurrent+2u)),"B1302 CC positive result differs from global sentinel");const U current=current_pair(m,self);need(found==current,"B1302 CC returned coordinate equals real +48 current coordinate");return (round_full(m.r32(self+0x8cu))&0xffffff00u)|1u;}
}
std::uint32_t run(std::uint32_t root,Memory&m,const Inputs&i){switch(root){case 0xcbe60u:return cbe(m,i);case 0xcbd00u:return cbd(m,i);case 0xcc000u:return cc(m,i);default:throw std::domain_error("B1302 root outside packet");}}
}

