#include "recovery_b1280.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1280 {
std::uint32_t fun_00427110(Memory&m,const Inputs&i){
 const auto classification=i.arg[3];
 if(classification>7u||classification==2u||(i.arg[2]&255u)!=0u)
  throw std::domain_error("1280 non2 classification and disabled corner-cost domain");
 // Both pointer-array heads are genuine inputs read by the original prologue.
 (void)m.r32(i.arg[0]);const auto cell=m.r32(i.arg[1]);
 if(m.r32(cell+0x140u)&0x40000u)throw std::domain_error("1280 ordinary cell cost domain");
 i.fp.load32(m.r32(0x7ba04cu+4u*classification));
 i.arg[3]=i.fp.pop32();
 i.fp.load32(i.arg[3]);
 return classification&0xffffff00u;
}
}
