#include "recovery_b507.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b507 {
namespace {
using U=std::uint32_t;
using floating_b61::sx16;
using floating_b61::sx8;
using floating_b61::s32;
inline U al(U v,U b){return (v&0xffffff00u)|(b&0xffu);}

// Exact reached 0x157530 predicate for the finite, nonoverflowing fixture.
bool in_map(Memory&m,U cell){
 const U x=sx16(m.r16(cell+0x24)), y=sx16(m.r16(cell+0x26));
 U off=0;
 if(m.r8(cell+0x11b)!=0) off=sx8(m.r8(cell+0x11b));
 const U f0=m.r32(0x81a910), f8=m.r32(0x81a918), fc=m.r32(0x81a91c);
 const U f100=m.r32(0x81a920), f104=m.r32(0x81a924), sum=x+y;
 const U lower=f0+fc*2u+off;
 if(s32(lower)>=s32(sum))return false;
 const U upper=f0+(f104+fc)*2u+2u+off;
 if(s32(upper)<s32(sum))return false;
 const U horizontal=(f100+f8)*2u-f0;
 if(s32(x-y)>=s32(horizontal))return false;
 const U vertical=f0-f8*2u;
 return s32(y-x)<s32(vertical);
}

U type15(Memory&m,U node){
 const U vt=m.r32(node);
 if(vt!=0x78e540u || m.r32(vt+0x2cu)!=0x508c50u)
  throw std::domain_error("B507 requires constructor-proven 78e540 / 508c50 type getter");
 // Pinned target bytes: MOV EAX,15; RET.
 return 15u;
}
}

U fun_0047be00(Memory&m,const Inputs&i){
 const U c=i.cx;
 if(!in_map(m,c))throw std::domain_error("B507 draft excludes the out-of-map AL-only return route");
 U eax=m.r32(c+0x38);
 const U count=m.r32(0xa28920u);
 if(s32(eax)>=0 && eax<count){
  const U type=m.r32(m.r32(0xa28914u)+eax*4u);
  eax=al(eax,m.r8(type+0x2d5u));
  if((eax&0xffu)==0)return al(eax,0);
 }
 eax=al(eax,m.r8(c+0x11cu));
 if(eax&0xffu)return al(eax,0);
 eax=m.r32(c+0x140u);
 if(((eax>>8)&5u)!=0)return al(eax,0);
 eax=al(eax,m.r8(0xa285a8u));
 if((eax&0xffu)==0)return al(eax,1);

 U node=m.r32(c+0xe4u);
 while(node){
  eax=type15(m,node);
  if(eax==6u){if(node)return al(eax,0);}
  node=m.r32(node+0x30u);
 }
 eax=al(eax,m.r8(0xa285a8u));
 if((eax&0xffu)==0)return al(eax,1);
 node=m.r32(c+0xe4u);
 while(node){
  eax=type15(m,node);
  if(eax==36u){if(node)return al(eax,0);}
  node=m.r32(node+0x30u);
 }
 return al(eax,1);
}
}
