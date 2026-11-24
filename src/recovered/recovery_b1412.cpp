#include "recovered/recovery_b1412.hpp"
#include "platform/observed_mutex1412.hpp"
#include <stdexcept>
namespace ra2::recovered::b1412 {
namespace {using U=std::uint32_t; void need(bool v,const char*m){if(!v)throw std::domain_error(m);}}
U fun_0075ed40(Memory&m,const Inputs&i){
 const U self=i.cx;
 need(m.r32(self)==0x79aa04u,"1412 final cursor vtable");
 need(m.r32(0xb10400u)==1u,"1412 existing state gate");
 need(m.r32(self+0x1cu)==0u&&m.r32(self+0x20u)==0u,"1412 zero stored coordinates");
 need(m.r32(self+0x14u)!=0u&&m.r32(self+0x18u)!=0u,"1412 positive prior cursor values");
 const U surface=m.r32(self+0x24u);need(surface&&m.r32(surface)==0x785ef8u,"1412 genuine surface object");
 need(m.r32(surface+4u)==1u&&m.r32(surface+8u)==1u&&m.r32(surface+16u)==2u&&m.r32(surface+20u)!=0u,"1412 genuine one-pixel surface header/pixel span");
 need(m.r32(0x785f60u)==0x411280u,"1412 actual surface slot +68");
 auto h=reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(0xb103f8u)));
 need(ra2::platform::mutex1412::Mutex::wait(h,10000u)==WAIT_OBJECT_0,"1412 outer real mutex acquire");
 need(m.r32(0xa39eecu)==2u,"1412 accepted predicate positive state");
 const U surface_result_al=1u;need(surface_result_al==1u,"1412 pinned actual positive surface method");
 need(ra2::platform::mutex1412::Mutex::wait(h,10000u)==WAIT_OBJECT_0,"1412 inner recursive real mutex acquire");
 const U cursor_hidden_first=m.r8(self+0x10u);need(cursor_hidden_first==0u,"1412 first original cursor read");
 m.w32(self+0x14u,0u);m.w32(self+0x18u,0u);
 const U cursor_hidden_second=m.r8(self+0x10u);need(cursor_hidden_second==0u,"1412 second original cursor read");
 const U inner_release=ra2::platform::mutex1412::Mutex::release(h);
 (void)inner_release;
 m.w8(0xb10400u,0u);
 const U outer_release=ra2::platform::mutex1412::Mutex::release(h);
 return outer_release;
}
}

