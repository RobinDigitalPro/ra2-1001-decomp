#include "recovered/recovery_b1176.hpp"
#include <stdexcept>
namespace ra2::recovered::b1176 {
unsigned run(Memory&m,const Inputs&i,State&,Destroy destroy){const unsigned p=i.arg[0];
 if(p!=0xb0e7e8u||m.r32(p)!=0x84u||m.r32(p+0x10u)||m.r32(p+0x18u)||m.r32(p+0x80u)||!destroy)throw std::domain_error("1176 actual initialized module without auxiliary owners");
 for(unsigned off:{0x1cu,0x34u,0x4cu})destroy(reinterpret_cast<LPCRITICAL_SECTION>(std::uintptr_t(p+off)));
 return 0u;
}}
