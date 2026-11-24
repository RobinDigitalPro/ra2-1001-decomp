#include "recovered/recovery_b150.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_004f47f0(Memory&,const Inputs&);}
namespace ra2::recovered::recovery_b150 {
std::uint32_t fun_006b7ab0(Memory&m,const Inputs&i){
 const auto target=i.arg[0],receiver=i.cx;
 if(!target||m.r32(0xa1e0e4)!=0||m.r32(0xa255c8)!=0||m.r8(receiver+0x374)!=0)throw std::domain_error("150 finite initialglobal positive route");
 // 6b7ae0 is reached before either helper, not only after them.
 m.w8(receiver+0x374,1);
 // Actual1cc8c0 XOR EAX; TEST pushedP; SETNZ AL; RET4.
 const auto nonnull=target!=0?1u:0u;
 if(!nonnull)return 0;
 global_b26::Inputs helper=i;helper.cx=target;
 const auto result=global_b26::fun_004f47f0(m,helper);
 if(result!=1)throw std::domain_error("150 helperfalse reachesexcludedvirtual call");
 m.w8(receiver+0x374,1);return (result&0xffffff00u)|1u;
}
}
