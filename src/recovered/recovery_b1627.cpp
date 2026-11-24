#include "recovered/recovery_b1627.hpp"
#include <stdexcept>
namespace ra2::recovered::b1627 {
std::uint32_t fun_004821e0(Memory&m,const Inputs&i){
 // Finite recognized mode1/bit0clear contract. No callback or object identity
 // is attached to either public numeric selector; concurrent mutation excluded.
 if(m.r32(0xa255c8u)!=1u||(m.r8(0xa27decu)&1u)!=0u)
  throw std::domain_error("1627 selected mode1/flag-bit0-clear domain");
 (void)b1468::fun_00406ea0(m,i); // Unchanged material positive coordinator.
 // Actual outer4821F1 load,48220D branch and48221A test occur AFTER child.
 const auto mode=m.r32(0xa255c8u);
 if(mode!=1u||(m.r8(0xa27decu)&1u)!=0u)
  throw std::domain_error("1627 selector changed during serial coordinator");
 return mode; // TEST/epilogue do not alter this full EAX1; original RET0.
}
}
