#include "recovered/recovery_b1602.hpp"
#include "recovered/leaf_state.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1602{namespace{void need(bool v){if(!v)throw std::domain_error("B1602 finite paired wrapper cleanup");}}
U fun_004226d0(Memory&m,const Inputs&i){const U self=i.cx,type=m.r32(self+0xb0);need(self&&m.r32(self)==0x787084&&m.r32(0x787084+0x11c)==0x421500&&m.r8(self+0x76)!=0&&m.r8(self+0x178)!=0&&m.r32(type+0x268)!=0&&m.r32(0x8192f8)!=0);
struct Span{U a,n;};std::array<Span,13> spans{};U used=0;auto add=[&](U a,U n){need(a&&std::uint64_t(a)+n<=0x100000000ull);for(U k=0;k<used;++k)need(std::uint64_t(a)+n<=spans[k].a||std::uint64_t(spans[k].a)+spans[k].n<=a);need(used<spans.size());spans[used++]={a,n};(void)m.r8(a);(void)m.r8(a+n-1);};add(self,0x1a8);add(type,0x400);add(0x787000,4096);add(0x819000,4096);
// Both wrapper owner protocols are validated before either material cleanup.
for(U j=0;j<2;++j){const U w=self+0x180+j*0x14,o=m.r32(w),n=m.r32(o+0xa8);need(o&&m.r32(w+0xc)==0x8192ec&&m.r32(w+8)==m.r32(o+0x24)&&m.r32(w+4)==m.r32(o+0x138)&&!(m.r8(o+0x18)&1)&&m.r32(o+0xb0)==0&&n>=1&&n<=4);add(o,0x300);for(U k=0;k<n;++k)add(m.r32(o+0x28+4*k),0x10);}
// Real normal-addresspoint11C thunk passes2; actual5CC7F0 self76 guard
// has no public writes. Its AL return is overwritten by this root.
// Reuse the accepted B85 positive wrapper algorithm and its real leaf1F90
// adapter; B85's unrelated functions need no link-time dependencies here.
for(U j=0;j<2;++j){const U w=self+0x180+j*0x14,o=m.r32(w),count=m.r32(o+0xa8);
 for(U k=0;k<count;++k){const U record=m.r32(o+0x28+4*k);std::array<std::uint8_t,16> bytes{};leaf::Memory local(bytes.data(),0x1000,16);local.w32(0x100c,m.r32(record+0xc));leaf::Inputs child{};child.cx=0x1000;(void)leaf::fun_00401f90(local,child);m.w32(record+0xc,local.r32(0x100c));m.w32(o+0x28+4*k,0);}
 m.w32(o+0xa8,0);m.w32(o+0x1c,4);m.w32(o+0x138,0);m.w32(o+0x278,0);m.w32(o+0x18,m.r32(o+0x18)|1u);m.w32(w,0);m.w32(w+8,0);
}
return (m.r32(type+0x268)&0xffffff00u)|m.r8(self+0x178);
}}
