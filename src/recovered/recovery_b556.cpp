#include "recovery_b556.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b556{
std::uint32_t fun_0070a480(Memory&m,const Inputs&i,Heap&h){
 //70A480-70A4DF: validate registry/index and explicit positive kind/payload.
 if(!m.r32(0xab83dc)||i.cx!=0||m.r32(0xab83c0)!=1||m.r32(0xab82f8)||m.r32(0xab83d4)||i.dx!=3||i.arg[0]==0xffffffffu)throw std::domain_error("556 bounded indexed kind3");
 const auto record=m.r32(m.r32(0xab83b4));
 if(!record||m.r32(0xab83c8))throw std::domain_error("556 record/standalone list");
 //70A680 search calls4072F0 on six list sentinels. Its exact empty condition
 // compares the head pointer with that head's third word, not with the list.
 for(unsigned head:{0xab8310,0xab8384,0xab8378,0xab836c,0xab8360,0xab82e8}){
  const auto p=m.r32(head);if(p!=head||m.r32(p+8)!=p)throw std::domain_error("556 expected initialized empty sentinel");
 }
 Inputs node=i;node.cx=record;
 const auto previous=recovery_b544::fun_0070a590(m,node,h);
 //70A760 guard is after the real append and preserves upper24 EAX bits.
 if(m.r8(0xa2894c)!=1)throw std::domain_error("556 inactive notification bound");
 return (previous&0xffffff00u)|1u;
}}
