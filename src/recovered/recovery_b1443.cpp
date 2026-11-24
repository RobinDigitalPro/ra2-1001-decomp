#include "recovered/recovery_b1443.hpp"
#include <stdexcept>
namespace ra2::recovered::b1443 {
std::uint32_t fun_004a4d80(Memory&m,const Inputs&i){
 const auto child=i.cx+0xb0u;
 if(i.arg[2]!=child||m.r32(i.cx)!=0x78b5e4u||m.r32(child)!=0x790624u||m.r32(0x790624u+0x9cu)!=0x538680u)
  throw std::domain_error("1443 authentic selected-list notification");
 // Actual538680 reads selected index/count and returns the selected pointer.
 const auto selected=m.r32(child+0x16cu),count=m.r32(child+0x44u);
 if(selected!=0u||count!=2u)throw std::domain_error("1443 populated selection domain");
 const auto source=m.r32(m.r32(child+0x38u)+4u*selected),dest=m.r32(i.cx+0x34u),capacity=m.r32(i.cx+0x38u);
 if(capacity!=64u||source==0u)throw std::domain_error("1443 bounded nonnull text");
 // The pre-getter PUSH remains the third argument to actual76EF62 (RET0).
 // Its strncpy loop copies the NUL then zero-fills the remaining capacity.
 bool ended=false;
 for(std::uint32_t k=0;k<capacity;++k){
  const auto unit=ended?std::uint16_t(0):m.r16(source+2u*k);
  m.w16(dest+2u*k,unit);if(unit==0u)ended=true;
 }
 if(!ended)throw std::domain_error("1443 short terminated source domain");
 if(m.r32(0x78b5e4u+0x48u)!=0x4cf180u)throw std::domain_error("1443 original dirty provider");
 m.w8(i.cx+0x1cu,1u); // exact4CF180; length3C is not recomputed by original.
 const auto result=m.r32(i.cx+0x24u)|0x8000u;
 m.w32(i.arg[1],result);return result;
}
}
