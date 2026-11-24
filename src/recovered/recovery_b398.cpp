#include "recovery_b398.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b398 {
namespace {
void vector(Memory&m,std::uint32_t p,std::uint32_t vt){
 m.w32(p,vt);m.w32(p+4,0);m.w32(p+8,0);m.w8(p+12,1);m.w8(p+13,0);m.w32(p+16,0);m.w32(p+20,10);
}
}
std::uint32_t fun_00544ef0(Memory&m,const Inputs&i){
 const auto p=i.cx;
 m.w8(p+0x10,0);m.w32(p+0x14,0);
 vector(m,p+0x4c,0x7909d8);
 for(unsigned n=0;n<3;++n)vector(m,p+0x88+24*n,0x7909b8);
 vector(m,p+0xd0,0x7875a0);m.w32(p+0x134,0x790998);
 for(unsigned n=0;n<256;++n){m.w16(p+0x160+16*n,0);m.w16(p+0x162+16*n,0);}
 vector(m,p+0x1158,0x7875a0);m.w32(p,0x79091c);
 for(unsigned n=0;n<12;++n)m.w32(p+0x18+4*n,0);
 for(unsigned n=0;n<3;++n)m.w32(p+0x7c+4*n,0);
 for(unsigned n=0;n<3;++n){const auto v=p+0x88+24*n;
  if(m.r32(m.r32(v)+12)!=0x567930||m.r32(v+4)||m.r8(v+13))throw std::domain_error("B398 requires authentic567930 empty vector cleanup");
  // Exact reached branch of original567930 after literal zero initialization.
  m.w32(v+16,0);m.w8(v+13,0);m.w32(v+8,0);m.w32(p+0x7c+4*n,0);
 }m.w32(p+0x14,0);return p;
}}
