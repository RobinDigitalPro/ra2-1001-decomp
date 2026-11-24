#include "recovery_b465.hpp"
#include "platform/current_crt_thread.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b465 {
std::uint32_t fun_00778cbc(Memory&m,const Inputs&i){
 if(i.arg[0]<1||i.arg[0]>3||(i.arg[8]&0x3f)!=0x3f)
  throw std::domain_error("465 masked floating error types 1..3");
 // The original name search has hit and miss routes. The actual linked
 // matherr implementation on the hit route is XOR EAX,EAX; RET.
 bool found=false;
 for(unsigned p=0x817a28;p<0x817b00;p+=8)if(m.r32(p)==i.arg[1]){found=m.r32(p+4)!=0;break;}
 (void)found;
 i.fp.load_control(std::uint16_t(i.arg[8]));
 const auto error=ra2::platform::current_crt_thread(m.r32(0x817778))+8;
 m.w32(error,i.arg[0]==1?33:34);
 i.fp.load64(std::uint64_t(i.arg[6])|(std::uint64_t(i.arg[7])<<32));
 return error;
}
}
