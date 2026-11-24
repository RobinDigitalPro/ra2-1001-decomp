#include "recovered/recovery_b1467.hpp"
#include "recovered/recovery_b1369.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/state_b93.hpp"
#include <stdexcept>
namespace ra2::recovered::b1467 {
namespace {
using U=std::uint32_t;
using GInputs=ra2::recovered::global_b26::Inputs;
void need(bool ok,const char* what){if(!ok)throw std::domain_error(what);}
GInputs registers(U ecx,U edx=0){GInputs x{};x.cx=ecx;x.dx=edx;return x;}
// Exact selected effects of original 0x4071F0 (9 bytes): circular 3-DWORD head.
void init_head(Memory&m,U p){m.w32(p,p);m.w32(p+4u,p);m.w32(p+8u,p);}
// Original 0x401080 performs these three actual 0x4070F0 calls.
void update_three(Memory&m,U p){
 (void)state_b93::fun_004070f0(m,registers(p));
 (void)state_b93::fun_004070f0(m,registers(p+0x28u));
 (void)state_b93::fun_004070f0(m,registers(p+0x50u));
}
// Exact finite effects of the reached 0x407380 doubly-linked unlink route.
void unlink_node(Memory&m,U node){
 const U next=m.r32(node),prev=m.r32(node+4u);
 m.w32(prev,next);
 const U next_again=m.r32(node),prev_again=m.r32(node+4u);
 m.w32(next_again+4u,prev_again);m.w32(node,node);m.w32(node+4u,node);
}
// Exact reached path of 0x407460, where the object payload begins at header+8.
void return_payload(Memory&m,U pool_cell,U payload){
 const U header=payload-8u,old=m.r32(pool_cell);m.w32(header,old);m.w32(pool_cell,header);
}
}
U fun_004041b0(Memory&m,const Inputs&i){
 (void)i;
 need(m.r32(0x8192f8u)!=0u&&m.r32(0x81930cu)==0u,"B1467 original entry gates");
 constexpr U sentinel=0x8191e0u;
 U node=m.r32(sentinel);
 need(node!=sentinel&&m.r32(node)==sentinel&&m.r32(node+4u)==sentinel,
      "B1467 one borrowed payload in original circular list");
 const U epoch=m.r32(0x819304u)+1u;
 m.w32(0x81930cu,1u);m.w32(0x819304u,epoch);
 do{
  const U next=m.r32(node),descriptor=m.r32(node+0x24u);
  need(descriptor!=0u,"B1467 produced descriptor pointer");
  if(m.r32(descriptor+0x98u)!=epoch){
   init_head(m,descriptor+0x8cu);m.w32(descriptor+0x44u,0u);m.w32(descriptor+0x98u,epoch);
  }
  update_three(m,node+0xb8u);
  need(m.r32(node+0x1cu)==4u,"B1467 original pending state4 node");
  node=next;
 }while(node!=sentinel);
 node=m.r32(sentinel);
 do{
  Inputs child=i;child.cx=node;
  (void)b1369::fun_004055d0(m,child);
  node=m.r32(node);
 }while(node!=sentinel);
 for(U outer=0;outer<7u;++outer)
  for(U inner=0;inner<10u;++inner)
   init_head(m,0x818e98u+(outer*10u+inner)*12u);
 m.w32(0x819308u,m.r32(0x819308u)+1u);
 node=m.r32(sentinel);
 do{
  const U next=m.r32(node),flags=m.r8(node+0x18u);
  need(m.r32(node+0xb0u)==0u&&(flags&1u)!=0u,"B1467 original state4 completion cleanup route");
  unlink_node(m,node);m.w32(node+0x138u,0u);
  need((flags&0x80u)==0u,"B1467 real pool-return branch, no virtual destructor");
  return_payload(m,m.r32(0x819300u),node);
  const U active=m.r32(0x8192e4u);need(active>0u,"B1467 active count is positive before decrement");
  m.w32(0x8192e4u,active-1u);node=next;
 }while(node!=sentinel);
 need(m.r32(0x81921cu)==0x40000000u&&m.r32(0x819220u)!=0x40000000u,
      "B1467 global timer unequal old target/current selected route");
 const U timer=0x819218u,flags=m.r32(timer);
 m.w32(timer,flags&~1u);m.w32(timer+8u,0x40000000u);
 update_three(m,timer);
 m.w32(0x81930cu,0u);
 return 0u;
}
}
