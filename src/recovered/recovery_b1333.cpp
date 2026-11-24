#include "recovery_b1333.hpp"
#include <stdexcept>
namespace ra2::recovered::b1333 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
void slot(Memory&m,U actor,U offset,U target){
 need(m.r32(actor)==0x78612cu&&m.r32(0x78612cu+offset)==target,"1333 original actor provider");
}
// Actual4F47F0 with runtimeA255C8=0: the full EAX is0 or1 here.
U owner_visible(Memory&m,U house){
 need(m.r32(0xa255c8u)==0u,"1333 finite owner mode");
 return (m.r8(house+0x134u)||m.r8(house+0x135u))?1u:0u;
}
// Actual491AF0, existing positive in-capacity entry. No resize provider reached.
U indexed_value(Memory&m,U house,U index){
 const U vector=house+0x5420u;
 need(index==0u&&m.r32(vector+8u)==1u,"1333 initialized index0 capacity1");
 const U data=m.r32(vector+4u);need(data,"1333 valid borrowed vector data");
 return m.r32(data+4u*index);
}
U actor_type(Memory&m,U actor){
 slot(m,actor,0x80u,0x6b6910u);slot(m,actor,0x84u,0x41b600u);
 return m.r32(actor+0x5acu); // Actual6B6910 tail-dispatch then41B600.
}
U guarded_action(Memory&m,U actor,U flags,U a1,U a2){
 // Actual6BBB60 prefix. The three child arguments are not read on this route.
 (void)flags;(void)a1;(void)a2;
 m.w32(0xa28824u,m.r32(0xa28824u)+1u);
 const U type=actor_type(m,actor);
 need(m.r8(type+0xaecu)!=0u&&owner_visible(m,m.r32(actor+0x1b4u)),"1333 real AEC/owner guarded return");
 return 0u; // Original6BBBA8..6BBBB1 epilogue, after the real counter write.
}
U child_c8020(Memory&m,U actor,U flags,U a1,U a2){
 if(m.r8(actor+0x578u))flags=(flags&0xfffffffdu)|1u;
 const U eax=guarded_action(m,actor,flags,a1,a2);
 if(m.r8(actor+0x578u)&&eax==0u)m.w8(actor+0x578u,std::uint8_t(eax));
 return eax;
}
U building_query(Memory&m,U actor,U kind,U&private_out){
 slot(m,actor,0x4b4u,0x4cd330u);slot(m,actor,0x4b0u,0x4cd360u);
 // Actual4CD330 initializes its own private result before the4CD360 call.
 need(private_out==0xffffffffu,"1333 authentic initialized search scratch");
 const U house=m.r32(actor+0x1b4u),index=m.r32(kind+0xb90u);
 need(indexed_value(m,house,index)>0u,"1333 positive house availability");
 need(m.r32(house+0x78u)==0u,"1333 actual finite empty building registry");
 return 0u; // Actual4CD50C, EDI was initialized to0; no private_out read/write.
}
void assign_mission(Memory&m,U actor,U requested,U immediate){
 slot(m,actor,0x1d0u,0x41b160u);
 need(m.r32(actor+0x98u)==0u&&requested==10u&&immediate==0u,"1333 actual adapter forwards mission10,0");
 // Actual591AB0: current0 differs from10, so the two persistent writes occur.
 m.w32(actor+0xa0u,requested);m.w8(actor+0xa4u,0u);
 // Actual second argument0 bypasses1E8/1D4; no callback seam.
}
}
U fun_006fb620(Memory&m,const Inputs&i){
 const U actor=i.cx,house=m.r32(actor+0x1b4u);
 need(owner_visible(m,house)==1u,"1333 visible owner");
 const U type=m.r32(actor+0x5acu);need(m.r8(type+0xbaau)==0u,"1333 type permits action");
 need((i.arg[0]&0x1b978u)!=0u&&m.r8(actor+0x578u)!=0u,"1333 positive flag-clear action route");
 return child_c8020(m,actor,i.arg[0],i.arg[1],i.arg[2]);
}
U fun_006f9790(Memory&m,const Inputs&i){
 const U actor=i.cx,rules=m.r32(0x821b88u),kind=m.r32(rules+0x778u);
 U private_out=0xffffffffu;const U found=building_query(m,actor,kind,private_out);
 m.w8(actor+0x5bau,0u);need(found==0u,"1333 no building found");
 need(indexed_value(m,m.r32(actor+0x1b4u),m.r32(kind+0xb90u))!=0u,"1333 no414 callback");
 need(m.r32(actor+0x98u)==0u,"1333 duration record0");
 const U record=0xa28000u+(m.r32(actor+0x98u)<<5u); // Actual591ED0.
 auto fp=i.fp;fp.load64(floating_b61::read64(m,record+0x10u));
 fp.multiply64(floating_b61::read64(m,0x786608u));
 const auto cw=std::uint16_t(m.r32(0x7c3a04u));if(fp.control()!=cw)fp.load_control(cw);
 const U eax=U(fp.pop_integer64());i.fp=fp;return eax;
}
U fun_006f90c0(Memory&m,const Inputs&i){
 const U actor=i.cx,type=m.r32(actor+0x5acu),house=m.r32(actor+0x1b4u);
 need(m.r8(type+0xba6u)==0u&&m.r8(type+0xba7u)!=0u,"1333 real BA7 route");
 need(owner_visible(m,house)==0u&&m.r32(type+0x3bcu)==1u,"1333 nonvisible owner with one kind");
 const U kind=m.r32(m.r32(type+0x3b0u));
 need(std::int32_t(indexed_value(m,house,m.r32(kind+0xb90u)))>0,"1333 first positive kind");
 assign_mission(m,actor,10u,0u);return 1u;
}
}
