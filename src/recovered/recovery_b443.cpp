#include "recovered/recovery_b443.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b443 {
namespace {
void need(bool ok,const char* text){if(!ok)throw std::domain_error(text);}

// Exact reached BuildingClass +0x80 callback path: vtable +80 is 0x6b6910
// (MOV EAX,[ECX]; JMP [EAX+84]); its +84 target 0x4538b0 returns [ECX+418].
std::uint32_t building_property(Memory& m,std::uint32_t object){
 const auto vtable=m.r32(object);
 need(vtable==0x00787bbcu,"B443 requires constructor-proven BuildingClass vptr");
 need(m.r32(vtable+0x80u)==0x006b6910u,"B443 requires original +80 slot target");
 need(m.r32(vtable+0x84u)==0x004538b0u,"B443 requires original BuildingClass property getter");
 return m.r32(object+0x418u);
}
}

std::uint32_t fun_006bd8e0(Memory& m,const Inputs& i){
 const auto object=i.cx;
 const auto property=building_property(m,object);
 need(property!=0u,"B443 positive timer route needs initialized property state");
 const auto count=m.r32(object+0x254u);
 const auto threshold=m.r32(property+0x5acu);
 if(static_cast<std::int32_t>(count)>=static_cast<std::int32_t>(threshold))return threshold;
 if(static_cast<std::int32_t>(count)<static_cast<std::int32_t>(threshold)&&count==0u){
  const auto direct=m.r32(property+0x5bcu);
  if(direct!=0xffffffffu){
   const auto timer=object+0x194u;
   m.w32(timer,m.r32(0x00a2896cu));
   m.w32(timer+4u,i.stack_minus8);
   m.w32(timer+8u,direct);
   return direct;
  }
 }
 const auto divisor=m.r32(property+0x3a8u);
 const auto factor=divisor==0u?1u:static_cast<std::uint32_t>(
     static_cast<std::int32_t>(count)/static_cast<std::int32_t>(divisor));
 const auto delay=m.r32(property+0x5b8u)+m.r32(property+0x5c0u)*factor*factor;
 const auto timer=object+0x194u;
 m.w32(timer,m.r32(0x00a2896cu));
 m.w32(timer+4u,i.stack_minus8);
 m.w32(timer+8u,delay);
 return delay;
}
}
