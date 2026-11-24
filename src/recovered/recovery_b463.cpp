#include "recovery_b463.hpp"
#include "recovery_b124.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b463 {
std::uint32_t fun_007797ce(Memory&m,const Inputs&i){
 const auto seconds=m.r32(i.arg[0]);
 if(m.r32(0xb107d0)==0||m.r32(0x818574)!=0||seconds<=259200||seconds>=0x7ffc0b7f)
  throw std::domain_error("463 initialized timezone, no DST, nonboundary epoch");
 const auto local=seconds-m.r32(0x818570);
 if(local>0x7fffffffu)throw std::domain_error("463 nonnegative adjusted epoch");
 // The original spills the adjusted epoch into its first caller argument.
 i.arg[0]=local;
 std::array<std::uint8_t,4>bytes{};leaf::Memory span(bytes.data(),0x5f300000,4);
 Memory scoped=m;scoped.add(span);scoped.w32(span.base(),local);
 Inputs call=i;call.arg[0]=span.base();
 return recovery_b124::fun_0077f427(scoped,call);
}
}
