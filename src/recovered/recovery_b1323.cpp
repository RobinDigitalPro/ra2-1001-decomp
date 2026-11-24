#include "recovery_b1323.hpp"
#include "recovered/recovery_b1322.hpp"
#include <stdexcept>
namespace ra2::recovered::b1323 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
// Exact accepted 557280 integer iterator, expressed against composite spans.
// It returns *old_cursor after updating state, including the terminating call.
U next(Memory&m,U r){
 const U old=m.r32(r+0x114u),count=m.r32(r+0x110u);
 if(count){m.w32(r+0x108u,m.r32(r+0x108u)+1u);m.w32(r+0x10cu,m.r32(r+0x10cu)-1u);m.w32(r+0x110u,count-1u);m.w32(r+0x114u,old-0x7fcu);}
 else{
  const U a=m.r32(r+0x108u),b=m.r32(r+0x10cu),width=m.r32(r+0xf0u);U x=b,y=a,length=width;
  if(((b-width+a-1u)&1u)!=0u){++y;--length;}else{++x;length-=2u;}
  m.w32(r+0x108u,x);m.w32(r+0x10cu,y);m.w32(r+0x110u,length);m.w32(r+0x114u,m.r32(r+0x138u)+4u*(512u*y+x));
 }return m.r32(old);
}
void increment(Memory&m,U cell){
 // Actual47C4A0: old -1 is normalized, increment clamped, bit20 set only
 // when the old count is nonpositive and the resulting count is positive.
 const auto old=std::int32_t(m.r32(cell+0x130u));if(old==-1)m.w32(cell+0x130u,0u);
 U value=m.r32(cell+0x130u)+1u;m.w32(cell+0x130u,value);
 const U limit=m.r32(cell+0x134u);if(std::int32_t(value)>std::int32_t(limit)){value=limit;m.w32(cell+0x130u,value);}
 if(old<=0&&std::int32_t(value)>0)m.w32(cell+0x140u,m.r32(cell+0x140u)|0x20u);
}
U redraw(Memory&m,U r){
 need(m.r32(r)==0x785954u&&m.r32(0x78598cu)==0x4e0030u,"1323 constructor-proven actual Map+38");
 const U manager=m.r32(0x821cacu);if(manager)m.w8(manager+0xd7du,1u);
 if(m.r32(r+0xcu)!=2u)m.w32(r+0xcu,2u);
 // Actual4E0030 preserves EAX2 while557AB0 increments the global byte.
 m.w8(0x81a820u+0x1154u,m.r8(0x81a820u+0x1154u)+1u);return 2u;
}
U run(Memory&m,const Inputs&i,bool counter){
 const U r=i.cx;need(r==0x81a820u&&m.r32(r+0xf0u)==2u,"1323 exact finite global Map iterator");
 m.w32(r+0x108u,1u);m.w32(r+0x10cu,2u);m.w32(r+0x110u,1u);m.w32(r+0x114u,m.r32(r+0x138u)+0x1004u);
 U visits=0;
 for(U cell=next(m,r);cell;cell=next(m,r)){
  need(visits++<2u,"1323 finite two-cell iterator");if(counter)increment(m,cell);
  if(!counter||std::int32_t(m.r32(cell+0x130u))>=0){m.w32(cell+0x12cu,m.r32(cell+0x12cu)&0xffffffe7u);m.w32(cell+0x140u,m.r32(cell+0x140u)&0xfffffffcu);}
 }
 need(visits==2u,"1323 positive two-cell traversal");
 // New dependency-only49DE40 empty-registry route: entryEAX=0, JLE,
 // POP EBP, RET8. Both actual caller arguments are zero; no actor callback.
 need(m.r32(0x83a8e8u)==0u,"1323 actual empty actor registry");
 const U house=m.r32(0xa1e0e4u);need(house,"1323 nonnull current house");m.w8(house+0x188u,0u);
 Inputs fill=i;fill.cx=0x81a820u;(void)b1322::fun_0062b6b0(m,fill);i.fp=fill.fp;
 return redraw(m,r);
}
}
U fun_00556dc0(Memory&m,const Inputs&i){return run(m,i,false);}
U fun_00556e60(Memory&m,const Inputs&i){return run(m,i,true);}
}
