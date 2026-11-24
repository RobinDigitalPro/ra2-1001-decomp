#include "recovered/recovery_b1673.hpp"
#include <stdexcept>
namespace ra2::recovered::b1673 {
std::uint32_t fun_00482310(Memory&m,const Inputs&i){
 // Finite recognized mode1/bit0clear contract. No callback or object identity
 // is attached to either public numeric selector; concurrent mutation excluded.
 if(m.r32(0xa255c8u)!=1u||(m.r8(0xa27decu)&1u)!=0u)
  throw std::domain_error("1673 selected mode1/flag-bit0-clear domain");
 (void)b1468::fun_00406ea0(m,i); // Unchanged material positive coordinator.
 // Actual outer482321 load,48233D branch and48234A test occur AFTER child.
 const auto mode=m.r32(0xa255c8u);
 if(mode!=1u||(m.r8(0xa27decu)&1u)!=0u)
  throw std::domain_error("1673 selector changed during serial coordinator");
 return mode & 0xffffff00u; // 482436 XOR AL,AL clears loaded mode1 to full EAX0; RET0.
}
}
