#include "recovery_b462.hpp"
#include "recovery_b277.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b462 {
namespace {
using U=std::uint32_t;
void clear(Memory&m,U p){for(U off:{0u,0x28u,0x50u})m.w32(p+off,m.r32(p+off)&~2u);}
void initialize(Memory&m,U p){
 if(m.r32(0x819898)!=0)throw std::domain_error("462 absent original timer-provider route");
 for(U k=0;k<3;++k){
  const U at=p+0x28*k,v=(k==0?0x4000u:k==1?100u:0x2000u)<<16;
  const bool changed=m.r32(at+4)!=v;
  m.w32(at,1u|(changed?2u:0u));m.w32(at+4,v);m.w32(at+8,v);
  // Original7030 writes timestamp0 through actual92d0 null-provider branch.
  m.w32(at+0x18,0);m.w32(at+0x1c,0);
  // Original1000 subsequently calls70d0 with interval1000 and limit0.
  m.w32(at+0x10,1000);m.w32(at+0x14,0);
  m.w32(at+0xc,((k==1?10u:0x4000u)<<16)/1000);
 }
}
}
std::uint32_t fun_00402220(Memory&m,const Inputs&i){
 const U receiver=i.cx,owner=m.r32(receiver+0xac),destination=receiver+0xd8;
 initialize(m,destination);
 auto compose=[&](U source){global_b26::Inputs call{};call.cx=destination;call.dx=source;return recovery_b277::fun_004010c0(m,call);};
 U result=compose(receiver+0x10);clear(m,receiver+0x10);
 U source=m.r32(receiver+0x90);
 if(source){result=compose(source);clear(m,source);}
 for(U off:{0x94u,0x98u,0x9cu})if((source=m.r32(receiver+off)))result=compose(source);
 result=compose(owner+0x68);
 if((source=m.r32(owner+0xe8)))result=compose(source);
 return result;
}
}
