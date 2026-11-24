#include "recovery_b1329.hpp"
#include "recovery_b1316.hpp"
#include <stdexcept>
namespace ra2::recovered::b1329 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// Original42CC10, the authentic7875A0+C slot, on the constructor-empty
// vector. Pointer/capacity/count stay zero; no allocation or free is reached.
unsigned clear_empty(Memory&m,unsigned p){
 need(m.r32(p)==0x7875a0u&&m.r32(0x7875acu)==0x42cc10u,"1329 original vector clear slot");
 need(m.r32(p+4u)==0u&&m.r32(p+8u)==0u&&m.r32(p+16u)==0u,"1329 empty embedded vector");
 m.w32(p+16u,0u);m.w8(p+13u,0u);m.w32(p+8u,0u);return 0u;
}
}
std::uint32_t fun_00565e80(Memory&m,const Inputs&i){
 const unsigned v=i.cx+0xd0u;clear_empty(m,v);
 need(m.r32(i.arg[0])==0x00050005u,"1329 populated coordinate5,5");
 const auto cell=m.r32(m.r32(0x81a958u)+4u*(512u*5u+5u));
 need(cell!=0u,"1329 real cell");const auto cat=m.r32(cell+0x44u);
 need(cat==0x5cu||cat==0xdfu,"1329 proven category families");
 Inputs nested=i;
 const unsigned flag=cat==0x5cu?b1316::fun_0055aa90(m,nested):b1316::fun_0055bba0(m,nested);
 i.fp=nested.fp;
 need(m.r32(v+16u)==0u,"1329 no queued coordinates after finite child");
 const auto eax=clear_empty(m,v);return (eax&0xffffff00u)|(flag&255u);
}
}
