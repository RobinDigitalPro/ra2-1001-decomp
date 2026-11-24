#include "recovery_b1339.hpp"
#include "recovered/recovery_b1329.hpp"
#include "recovered/recovery_b220.hpp"
#include "recovered/recovery_b612.hpp"
#include "recovered/recovery_b349.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/leaf_b56_c.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1339 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void clear_empty(Memory&m,U p){
 need(m.r32(p)==0x7875a0u&&m.r32(0x7875acu)==0x42cc10u,"1339 actual vector clear provider");
 need(m.r32(p+4u)==0u&&m.r32(p+8u)==0u&&m.r32(p+16u)==0u,"1339 constructor-empty vector");
 m.w32(p+16u,0u);m.w8(p+13u,0u);m.w32(p+8u,0u);
}
}
std::uint32_t fun_006a6b20(Memory&memory,const Inputs&i){
 need(memory.r32(0xa28870u)==0u,"1339 no registered actor-damage loop");
 const auto point=i.arg[3];need(memory.r32(point)==0x00050005u&&memory.r32(0xaa78b8u)!=0x00050005u,"1339 selected cell differs from excluded marker");
 Inputs nested=i;nested.cx=0x81a820u;nested.arg[0]=point;
 need(b1329::fun_00565e80(memory,nested)==0u,"1339 first positive triple dispatch");i.fp=nested.fp;
 constexpr U p=0x7c200000u;std::array<std::uint8_t,256> bytes{};leaf::Memory local(bytes.data(),p,U(bytes.size()));Memory m=memory;m.add(local);
 const auto cell=m.r32(m.r32(0x81a958u)+4u*(512u*5u+5u));
 // Subsequent actual165E80 calls dispatch the postmutation5D category to
 //55ACE0. Its two geometry calls precede CMP5D,53 and theAL0 exit.
 for(unsigned k=0;k<3u;++k){
  clear_empty(m,0x81a8f0u);need(m.r32(cell+0x44u)==0x5du,"1339 genuine postmutation5D");
  Inputs q{};q.cx=cell;q.arg[0]=p;q.fp=i.fp;(void)recovery_b220::fun_00474d00(m,q);
  q.arg[0]=p+16u;(void)recovery_b612::fun_00474ab0(m,q);i.fp=q.fp;
  // Original rectangle union is private and unused by the below53 guard.
  leaf::Inputs u{};u.cx=p+32u;u.dx=p+16u;u.arg[0]=p;(void)leaf::fun_0045ec50(local,u);
  clear_empty(m,0x81a8f0u);
 }
 need(m.r32(0xaa7900u)==0u,"1339 finite zero view height");
 local.w32(p+64u,1408u);local.w32(p+68u,1408u);local.w32(p+72u,0u);
 Inputs project{};project.cx=m.r32(0x821cacu);project.arg[0]=p+64u;project.arg[1]=p+80u;project.fp=i.fp;
 (void)numeric_b88::fun_00698010(m,project);i.fp=project.fp;
 const U dirty=m.r32(0xaa60bcu);
 need(m.r32(0xaa60c8u)==1u&&m.r32(0xaa60c0u)==1u&&m.r8(dirty+16u)==0u,"1339 real first child dirty entry");
 local.w32(p+96u,local.r32(p+80u)-128u);local.w32(p+100u,local.r32(p+84u)-128u);local.w32(p+104u,256u);local.w32(p+108u,256u);
 for(U k=0;k<4u;++k)local.w32(p+112u+4u*k,m.r32(dirty+4u*k));
 leaf::Inputs clip{};clip.cx=p+128u;clip.dx=p+96u;clip.arg[0]=p+112u;
 (void)leaf::fun_0041fdf0(local,clip);
 for(U k=0;k<4u;++k)need(local.r32(p+128u+4u*k)==local.r32(p+112u+4u*k),"1339 actual intersection contains old dirty rectangle");
 // Actual698817..698890 removes the sole contained old record. No following
 // record is moved; capacity1 remains owned, and the new record reuses it.
 m.w32(0xaa60c8u,m.r32(0xaa60c8u)-1u);
 global_b26::Inputs append{};for(U k=0;k<4u;++k)append.arg[k]=local.r32(p+96u+4u*k);
 append.arg[4]=0u;
 // RootEBP=outerarg2.698010 saves it at rootT-1C, the later collector's
 // flagsDWORD. Only lowbyte is initialized, leaving authentic high24.
 append.stack_minus8=i.arg[2];return recovery_b349::fun_00698660(m,append);
}
}
