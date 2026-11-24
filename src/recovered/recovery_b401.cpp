#include "recovered/recovery_b401.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b401 {
// RVA2ea3f0: sixteen unconditional frees, clearing each corresponding global.
std::uint32_t fun_006ea3f0(Memory&m,const Inputs&,Heap&heap){
 std::uint32_t eax=0;
 for(unsigned n=0;n<16;++n){const auto slot=0xaa8c64u+4*n;const auto p=m.r32(slot);
  if(!p)throw std::domain_error("B401 covers sixteen distinct nonnull ordinary-heap slots");
  eax=heap.release(p);m.w32(slot,0);
 }return eax;
}}
