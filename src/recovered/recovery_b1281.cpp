#include "recovery_b1281.hpp"
#include "crt_b83.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1281 { namespace {
void need(bool value,const char*what){if(!value)throw std::domain_error(what);}
unsigned civilian(Memory&m){
 need(m.r32(0x84e4f0u)==1u&&m.r32(0xb10530u)==0u,"1281 one ASCII Side registry");
 const auto entry=m.r32(m.r32(0x84e4e4u));
 global_b26::Inputs call;call.arg[0]=entry+0x24u;call.arg[1]=0x7b9ac0u;
 need(crt_b83::fun_0076d860(m,call)==0u,"1281 Civilian lookup match");return 0u;
}
}
std::uint32_t fun_0041cef0(Memory&m,const Inputs&i){
 need(m.r32(i.cx)==0x786780u&&m.r32(0xa1a5d8u)==2u,"1281 bounded trigger and House registry");
 const auto array=m.r32(0xa1a5ccu);unsigned selected=0;
 for(unsigned k=0;k<2u;++k){const auto h=m.r32(array+k*4u);const auto side=civilian(m);
  if(m.r32(m.r32(h+0x34u)+0xbcu)==side)selected=h;
 }
 need(selected!=0u,"1281 at least one Civilian-parent House");
 // Original logging target4068F0 is a single RET, without observable work.
 const auto type=m.r32(i.cx+0xd8u);need(type!=0u,"1281 nonnull descriptor");
 const auto vt=m.r32(type);
 need(vt==0x7881f8u&&m.r32(vt+0x40u)==0x45e990u&&m.r32(vt+0x2cu)==0x45e970u,"1281 authentic BuildingType targets");
 const auto index=m.r32(type+0xb90u);need(index==0u,"1281 prepopulated index zero");
 const auto counter=selected+0x5460u;
 need(m.r32(counter)==0x7895acu&&m.r32(counter+8u)==11u,"1281 in-range counter projection");
 const auto value=m.r32(m.r32(counter+4u)+4u*index);
 need(value>255u&&value<0x80000000u,"1281 positive counter high bits");
 const auto threshold=global_b26::s32(m.r32(i.cx+0xe4u));
 const auto signed_value=global_b26::s32(value);bool result=false;
 switch(m.r32(i.cx+0xe8u)){
 case 0:result=signed_value<threshold;break;case 1:result=signed_value<=threshold;break;
 case 2:result=signed_value==threshold;break;case 3:result=signed_value>=threshold;break;
 case 4:result=signed_value>threshold;break;case 5:result=signed_value!=threshold;break;
 default:throw std::domain_error("1281 six signed conditions");}
 return (value&0xffffff00u)|unsigned(result);
}
}
