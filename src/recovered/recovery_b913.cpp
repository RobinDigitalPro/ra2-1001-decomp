#include "recovered/recovery_b913.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b913{using U=std::uint32_t;
U fun_00636cf0(Memory&m,const Inputs&i){const U player=m.r32(0xa1e0e4),controller=m.r32(0xa27f14);if(m.r32(0xa27f20)!=0xffffffffu||m.r32(0xa255c8)!=4||!player||controller==0xffffffffu||controller!=m.r32(player+0x30))throw std::domain_error("913 local controller gate");const U count=m.r32(i.cx+0x10),table=m.r32(i.cx+4);if(!count||count>8||!table)throw std::domain_error("913 positive bounded vector");U result=0xffffffffu;bool found=false;for(U k=0;k<count;++k){const U p=m.r32(table+4*k);if(!p)throw std::domain_error("913 valid row");if(m.r8(p+0x27)&&!m.r8(p+0x25)){const U id=m.r8(p);result=id<128?id:id|0xffffff00u;m.w8(p+0x25,1);found=true;}}if(!found)throw std::domain_error("913 positive selection");return result;}
}
