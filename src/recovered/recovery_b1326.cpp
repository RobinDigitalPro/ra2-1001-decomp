#include "recovery_b1326.hpp"
#include "recovered/recovery_b1322.hpp"
#include <stdexcept>
namespace ra2::recovered::b1326 {
namespace {
using U=std::uint32_t;
constexpr U map=0x81a820u;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
// Actual 557280: state advances even when the old cursor contains null.
U next(Memory&m,U r){
 const U old=m.r32(r+0x114u),count=m.r32(r+0x110u);
 if(count){m.w32(r+0x108u,m.r32(r+0x108u)+1u);m.w32(r+0x10cu,m.r32(r+0x10cu)-1u);m.w32(r+0x110u,count-1u);m.w32(r+0x114u,old-0x7fcu);}
 else{const U a=m.r32(r+0x108u),b=m.r32(r+0x10cu),width=m.r32(r+0xf0u);U x=b,y=a,length=width;
  if(((b-width+a-1u)&1u)!=0u){++y;--length;}else{++x;length-=2u;}
  m.w32(r+0x108u,x);m.w32(r+0x10cu,y);m.w32(r+0x110u,length);m.w32(r+0x114u,m.r32(r+0x138u)+4u*(512u*y+x));}
 return m.r32(old);
}
void begin(Memory&m,U r){
 const U width=m.r32(r+0xf0u);need(width==2u,"1326 finite width2 iterator");
 m.w32(r+0x108u,1u);m.w32(r+0x10cu,width);m.w32(r+0x110u,width-1u);m.w32(r+0x114u,m.r32(r+0x138u)+(width<<11u)+4u);
}
U empty_registry(Memory&m,U eax){
 // Both actual49DD30/49DBA0 load count into EBX, then RET8.
 // On count0 they preserve incoming full EAX and numeric FP state.
 need(m.r32(0xa28870u)==0u,"1326 empty registry dependency route");return eax;
}
U redraw(Memory&m,U r,U mode,bool via_vtable){
 if(via_vtable)need(m.r32(r)==0x785954u&&m.r32(0x78598cu)==0x4e0030u,"1326 original Map+38 provider");
 const U manager=m.r32(0x821cacu);if(manager)m.w8(manager+0xd7du,1u);
 if(mode){if(m.r32(r+0xcu)!=2u)m.w32(r+0xcu,mode);m.w8(map+0x1154u,m.r8(map+0x1154u)+1u);}
 return mode;
}
void fill(Memory&m,const Inputs&i){Inputs child=i;child.cx=map;(void)b1322::fun_0062b6b0(m,child);i.fp=child.fp;}
U transition(Memory&m,const Inputs&i,bool show){
 const U r=show?map:i.cx;need(r==map,"1326 global Map receiver");
 U house=m.r32(0xa1e0e4u);need(house,"1326 current house");
 if(show)need(m.r8(house+0x188u)==0u,"1326 positive reveal transition");
 (void)empty_registry(m,show?house:i.ax);
 if(show){house=m.r32(0xa1e0e4u);m.w8(house+0x188u,1u);}
 begin(m,r);U visits=0u;
 for(U cell=next(m,r);cell;cell=next(m,r)){
  need(visits++<2u,"1326 two-cell positive traversal");
  const U flags=m.r32(cell+0x12cu),state=m.r32(cell+0x140u);
  m.w32(cell+0x12cu,show?flags|0x18u:flags&0xffffffe7u);
  m.w32(cell+0x130u,show?0u:1u);m.w32(cell+0x134u,0u);
  m.w32(cell+0x140u,show?state|3u:state&0xfffffffcu);
 }
 need(visits==2u,"1326 expected two real cells");(void)empty_registry(m,0u);
 if(!show)m.w8(m.r32(0xa1e0e4u)+0x188u,0u);
 fill(m,i);return redraw(m,r,2u,!show);
}
}
U fun_00556d00(Memory&m,const Inputs&i){return transition(m,i,false);}
U fun_00556f10(Memory&m,const Inputs&i){return transition(m,i,true);}
U fun_00556fe0(Memory&m,const Inputs&i){
 const U house=m.r32(0xa1e0e4u);need(house&&m.r8(house+0x188u)==0u,"1326 positive sparse reveal");
 m.w8(house+0x188u,1u);begin(m,map);
 need(next(m,map)==0u,"1326 sparse iterator skips actual49A150 loop");
 fill(m,i);return redraw(m,map,1u,false);
}
}
