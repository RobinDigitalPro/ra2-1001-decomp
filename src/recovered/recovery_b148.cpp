#include "recovered/recovery_b148.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b148 {
std::uint32_t fun_00452b20(Memory&m,const Inputs&i){
 const auto root=i.cx,candidate=i.arg[0],type=m.r32(root+0x418),context=m.r32(candidate+0x5a8),owner=m.r32(root+0x1b4);
 if(m.r32(root)!=0x787bbc||m.r32(candidate)!=0x787bbc||m.r8(type+0x121e)==0)throw std::domain_error("148 concrete vptr/enabled type contract");
 if(m.r8(context+0xc08)){
  if(m.r32(candidate+0x1b4)!=owner||m.r32(root+0x564)==m.r32(type+0x1220))throw std::domain_error("148 ratio-path owner/scalar contract");
  if(m.r32(0x787c40)!=0x4538b0)throw std::domain_error("148 actual root getter slot");
  // Original 1ccc40 stores a double numerator, invokes the genuine getter,
  // divides by its +a0 integer and compares the actual threshold double.
  auto&fp=i.fp;const auto numerator=m.r32(root+0x6c);fp.load_integer32(numerator);const auto saved=fp.pop64();
  const auto returned=m.r32(root+0x418);fp.load_integer32(m.r32(returned+0xa0));
  ra2::platform::x87_scalar_b46::reverse_divide64(fp,saved);
  fp.compare_pop64(floating_b61::read64(m,m.r32(0x821b88)+0x1370));
  const bool helper=(fp.status()&0x4100)!=0&&floating_b61::s32(numerator)>0;
  if(helper)return 0;
  const auto property=m.r32(candidate+0x234);return (property&0xffffff00u)|(property==0?1u:0u);
 }
 if(!m.r8(context+0xc09)||m.r32(0x787bf8)!=0x6bca10)throw std::domain_error("148 concrete candidate getter route");
 // Original e4c20 invokes actual6bca10 then performs these owner/type checks.
 const auto other=m.r32(candidate+0x1b4);unsigned result;
 if(!other)throw std::domain_error("148 nonnull candidate owner required");
 if(other==owner)result=(other&0xffffff00u)|1u;
 else{
  const auto other_type=m.r32(other+0x30),own_type=m.r32(owner+0x30);
  if(other_type==own_type)result=(other_type&0xffffff00u)|1u;
  else if(other_type==0xffffffff)result=0xffffff00u;
  else{const auto mask=m.r32(owner+0x5674);result=(mask&0xffffff00u)|((mask&(1u<<(other_type&31)))?1u:0u);}
 }
 if(result&255)return result&0xffffff00u;
 const auto scalar=m.r32(root+0x564);return (scalar&0xffffff00u)|(scalar==0?0u:1u);
}
}
