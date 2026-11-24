#include "recovery_b1290.hpp"
#include "recovered/recovery_b517.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b1290 {
std::uint32_t fun_006c46a0(Memory&m,const Inputs&i){
 auto need=[](bool q,const char*s){if(!q)throw std::domain_error(s);};
 need(m.r32(i.cx)==0x787bbcu&&m.r32(0x787c3cu)==0x6b6910u&&m.r32(0x787c40u)==0x4538b0u,"1290 real type dispatch");
 const auto type=m.r32(i.cx+0x418u),speed=m.r32(type+0x5a4u);
 need((speed==1u||speed==4u)&&m.r32(type+0x500u)==0xffffffffu&&m.r8(i.cx+0x79u)==0u,"1290 selector1 unzoned ground route");
 const auto source=i.arg[1]?i.arg[1]:i.cx;
 need(m.r32(source)==0x787bbcu&&m.r32(0x787c04u)==0x443e10u,"1290 real coordinate target");
 const auto source_type=m.r32(source+0x418u);
 need(m.r32(source_type+0xc78u)==0u&&m.r32(0x7bac60u)==1u&&m.r32(0x7bac08u)==1u,"1290 original index0 dimensions");
 //443E10 adds dimension*128-128; both immutable dimensions are1 here.
 const auto x=std::int32_t(m.r32(source+0x88u))/256,y=std::int32_t(m.r32(source+0x8cu))/256;
 (void)m.r32(source+0x90u);
 need(x>=64&&x<=67&&y>=64&&y<=67,"1290 finite viable map coordinates");
 std::array<std::uint8_t,64> scratch{};
 leaf::Memory local(scratch.data(),0xf2100000u,scratch.size());Memory view=m;view.add(local);
 const auto coords=0xf2100000u,out=0xf2100010u,zero=0xf2100020u;
 local.w16(coords,x);local.w16(coords+2u,y);local.w32(zero,0u);
 Inputs search=i;search.cx=0x81a820u;search.arg.fill(0u);
 search.arg[0]=out;search.arg[1]=coords;search.arg[2]=1u;search.arg[3]=search.arg[4]=0xffffffffu;
 search.arg[6]=search.arg[7]=search.arg[11]=1u;search.arg[12]=zero;
 (void)recovery_b517::fun_0054d770(view,search);i.fp=search.fp;
 m.w32(i.arg[0],local.r32(out));i.arg[1]=0u;return i.arg[0];
}
}
