#include "recovered/recovery_b1693.hpp"
#include "recovered/leaf_b15_b.hpp"
#include "recovered/recovery_b453.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b1693 {
namespace {
constexpr U private_rect=0xffff0000u; //Source-local numeric span; never public state.
struct Range {U base,size;};
void need(bool v){if(!v)throw std::domain_error("133E50 supplied32x24 positive Surface fill");}
void valid(Range r){need(r.base&&r.size&&std::uint64_t(r.base)+r.size<=0x100000000ull);}
void disjoint(Range a,Range b){valid(a);valid(b);need(std::uint64_t(a.base)+a.size<=b.base||std::uint64_t(b.base)+b.size<=a.base);}
U color(Memory&m){
 const U a=m.r8(0xa9e361u),b=m.r8(0xa9e362u),c=m.r8(0xa9e363u);
 const U x=(a>>(m.r8(0x83b2ecu)&31u))<<(m.r32(0x83b2e8u)&31u);
 const U y=(c>>(m.r8(0x83b2f4u)&31u))<<(m.r32(0x83b2f0u)&31u);
 const U z=(b>>(m.r8(0x83b2fcu)&31u))<<(m.r32(0x83b2f8u)&31u);
 return x|y|z; //Actual32-bit shifts/OR; no low16 normalization.
}
void checked_owner(Heap&h,leaf::Memory&v,U address,U extent,const Projection&p){
 need(v.base()==address&&v.size()==extent);
 const Range r{address,extent};valid(r);
 disjoint(r,{p.self,0x60u});disjoint(r,{p.borrowed,0x2421u});
 disjoint(r,{0x400000u,0x728000u});disjoint(r,{private_rect,16u});
 for(U k=0;k<extent;++k)need(v.r8(address+k)==h.r8(address+k));
 //Byte agreement is a guard, not proof of physical alias: provider must prove it.
}
}

Projection preflight(U root,Memory&m,const Inputs&i){
 need(root==0x133e50u);Projection p{};p.self=i.cx;p.caller=i.arg;
 valid({p.self,0x60u});
 for(U k=0;k<0x60u;++k)(void)m.r8(p.self+k);
 need(m.r32(0x83a710u)==32u&&m.r32(0x83a714u)==24u);
 need(m.r32(0x798bfcu)==640u&&m.r32(0xa255c8u)==0u);
 need(m.r32(0x83b2e8u)==11u&&m.r8(0x83b2ecu)==3u);
 need(m.r32(0x83b2f0u)==5u&&m.r8(0x83b2f4u)==2u);
 need(m.r32(0x83b2f8u)==0u&&m.r8(0x83b2fcu)==3u);
 p.color=color(m);need(p.color<=0xffffu);
 p.borrowed=m.r32(0xa255c0u);valid({p.borrowed,0x2421u});
 for(U k=0;k<0x2421u;++k)(void)m.r8(p.borrowed+k);
 need(m.r8(p.borrowed+0x2420u)==0u);
 disjoint({p.self,0x60u},{p.borrowed,0x2421u});
 for(const Range r:std::array<Range,2>{{{p.self,0x60u},{p.borrowed,0x2421u}}}){
  disjoint(r,{0x400000u,0x728000u});disjoint(r,{private_rect,16u});
 }
 need(m.r32(0x785f08u)==0x75fd00u);
 need(m.r32(0x785ef8u+0x5cu)==0x411370u&&m.r32(0x785ef8u+0x60u)==0x4112f0u);
 need(m.r32(0x785ef8u+0x70u)==0x4113b0u&&m.r32(0x785ef8u+0x74u)==0x4113c0u&&m.r32(0x785ef8u+0x78u)==0x411290u);
 need(m.r32(0x785f74u)==0x4112c0u);
 //Check Source-local span collision outside the guest boundary. No public write.
 std::array<std::uint8_t,16> bytes{};leaf::Memory rect(bytes.data(),private_rect,16u);
 Memory local=m;local.add(rect);
 return p;
}

U run(U root,Memory&m,const Inputs&i,Heap&h,const Projection&p){
 need(root==0x133e50u&&i.cx==p.self&&i.arg==p.caller);
 const U width=m.r32(0x83a710u),height=m.r32(0x83a714u);
 need(width==32u&&height==24u);
 const U header=h.allocate(32u);need(header!=0u);
 auto&hv=h.owner_span(header,32u);checked_owner(h,hv,header,32u,p);
 leaf::Inputs dimensions{};dimensions.cx=header;dimensions.arg[0]=width;dimensions.arg[1]=height;
 need(leaf::fun_0049eac0(hv,dimensions)==header); //unchanged accepted25-byte helper.
 const U count=(width*height)<<1u;need(count==1536u);
 hv.w32(header+0x0cu,0u);hv.w32(header,0x785f8cu);hv.w32(header+0x10u,2u);
 //Exact positive438140 field/ownership semantics; real allocation replaces its
 //legacy controlled AX/DX callback. No synthetic volatileDX result is created.
 hv.w32(header+0x14u,0u);hv.w32(header+0x18u,count);hv.w8(header+0x1cu,0u);
 const U pixels=h.allocate(count);need(pixels!=0u&&(pixels&3u)==0u);
 auto&pv=h.owner_span(pixels,count);checked_owner(h,pv,pixels,count,p);
 disjoint({header,32u},{pixels,count});
 hv.w32(header+0x14u,pixels);hv.w8(header+0x1cu,1u);
 hv.w32(header,0x785ef8u);m.w32(p.self+0x5cu,header);
 const U packed=color(m);need(packed==p.color&&packed<=0xffffu);
 std::array<std::uint8_t,16> bytes{};leaf::Memory rect(bytes.data(),private_rect,16u);
 rect.w32(private_rect,0u);rect.w32(private_rect+4u,0u);
 rect.w32(private_rect+8u,width);rect.w32(private_rect+12u,height);
 Memory local=m;local.add(hv);local.add(pv);local.add(rect);
 surface_b453::Inputs fill{};fill.cx=header;
 fill.arg[0]=private_rect;fill.arg[1]=private_rect;fill.arg[2]=packed;
 const auto child_before=fill.arg;
 need(surface_b453::fun_0075fd00(local,fill)==1u); //actual normal lockdepth0.
 need(fill.arg[0]==24u&&fill.arg[1]==64u&&fill.arg[2]==0u);
 for(U k=3u;k<16u;++k)need(fill.arg[k]==child_before[k]);
 need(m.r32(0xa255c8u)==0u&&width!=m.r32(0x798bfcu));
 const U borrowed=m.r32(0xa255c0u); //533F77 overwrites FULL EAX.
 need(borrowed==p.borrowed&&m.r8(borrowed+0x2420u)==0u);
 need(i.arg==p.caller);
 return borrowed; //RET0 abstract result; never low-byte0 or fixed success1.
}
}
