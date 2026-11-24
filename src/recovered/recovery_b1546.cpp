#include "recovered/recovery_b1546.hpp"
#include <stdexcept>
namespace ra2::recovered::b1546 {
std::uint32_t fun_00745730(Memory&m,const Inputs&,Heap&h){
 const auto count=m.r32(0xb0fcb0u);
 const auto holders=m.r32(0xb0fcb8u);
 if(count!=1u||!holders||m.r32(0xb0e390u)!=0u)
  throw std::domain_error("1546 requires one owned holder and empty source queue");
 const auto p=m.r32(holders);
 if(!p)throw std::domain_error("1546 requires one nonnull owned holder");
 h.release(p); // Actual 759320 -> 76D67B -> 76DF28, real ordinary HeapFree.
 m.w32(holders,0u);
 m.w32(0xb0fcb0u,0u);
 // Actual 745580 sees count zero and returns before provider dispatch.
 return 0u;
}
}
