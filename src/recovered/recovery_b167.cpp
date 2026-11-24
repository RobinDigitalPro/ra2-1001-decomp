#include "recovered/recovery_b167.hpp"
#include "recovered/rng_b70.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b167 {
std::uint32_t fun_006e2a00(Memory&m,const Inputs&i){
 if(!m.r8(i.cx+0x40)||m.r8(i.cx+0x2c)||!(i.arg[2]&255)||!(i.arg[3]&255))throw std::domain_error("167 forced timer-reset route required");
 auto node=m.r32(m.r32(i.cx+0x24)+0xac);unsigned count=0;
 while(node){if(++count>8||m.r32(node+0x2c)!=13)throw std::domain_error("167 bounded type13 chain required");node=m.r32(node+0x28);}
 if(!count)throw std::domain_error("167 nonempty timer chain required");
 const auto result=rng_b70::fun_006e2940(m,i);
 return (result&0xffffff00u)|1u;
}
}
