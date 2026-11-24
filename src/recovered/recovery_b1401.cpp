#include "recovery_b1401.hpp"
#include <stdexcept>
namespace ra2::recovered::b1401 {
std::uint32_t fun_004df1c0(Memory&m,const Inputs&i){
 // The five null-state string objects are valid 759250-produced values.
 for(unsigned k=4;k<9;++k)if(m.r32(i.arg[k])!=0)throw std::domain_error("B1401 optional strings must be null-state");
 const auto self=i.cx;
 // Exact base constructor 4DF7B0, then root rectangle/owner initialization.
 m.w32(self+4,i.arg[0]);m.w8(self+8,0);m.w8(self+9,1);
 m.w32(self+12,0);m.w32(self,0x78dbd0);
 m.w32(self+0x10,i.arg[1]);
 for(unsigned k=0;k<4;++k)m.w32(self+0x14+4*k,m.r32(i.arg[3]+4*k));
 m.w32(self+0x24,0);m.w32(self+0x28,0);m.w32(self+0x2c,0);m.w32(self+0x30,0);
 // 759250 constructs self34. 759570(null,null) leaves that state intact.
 m.w32(self+0x34,0);m.w32(self,0x78dbb4);
 return self;
}
}
