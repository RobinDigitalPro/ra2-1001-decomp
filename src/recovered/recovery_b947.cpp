#include "recovered/recovery_b947.hpp"
#include "platform/observed_mutex149.hpp"
namespace ra2::recovered::recovery_b947 {
std::uint32_t fun_0075d500(Memory&m,const Inputs&i){
 if(m.r32(i.cx+0x44)||m.r32(i.cx+0x58)||m.r32(i.cx+0x6c))throw std::domain_error("947 child-free owner contract");
 m.w32(i.cx,0x79aa04);
 auto h=reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(0xb103f8)));
 if(ra2::platform::mutex149::Mutex::wait(h,10000)!=WAIT_OBJECT_0)throw std::domain_error("947 fresh mutex acquisition");
 if(m.r32(0xb103f4)==i.cx)m.w32(0xb103f4,0);
 const auto result=ra2::platform::mutex149::Mutex::release(h);
 m.w32(i.cx,0x79aa50);
 return std::uint32_t(result);
}}
