#include "recovered/recovery_b1099.hpp"
#include <stdexcept>
namespace ra2::recovered::b1099 {
unsigned run(Memory&m,const Inputs&i,State&,Init initialize){
 const auto p=i.arg[0],context=i.arg[2];
 if(p!=0xb0e7e8u||i.arg[1]!=0u||!initialize)throw std::domain_error("1099 actual static context/null callback table");
 m.w32(p+0x10u,i.arg[1]);m.w32(p+8u,context);m.w32(p+12u,context);m.w32(p+4u,context);m.w32(p+0x14u,0u);m.w32(p+0x18u,0u);
 for(unsigned off:{0x1cu,0x34u,0x4cu})initialize(reinterpret_cast<LPCRITICAL_SECTION>(std::uintptr_t(p+off)));
 m.w32(p+0x68u,0u);m.w8(p+0x6cu,1u);m.w32(p+0x74u,0u);m.w32(p+0x7cu,0u);m.w32(p+0x78u,0u);m.w32(p+0x80u,0u);return 0u;
}
}
