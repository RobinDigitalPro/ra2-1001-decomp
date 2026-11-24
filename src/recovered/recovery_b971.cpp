#include "recovered/recovery_b971.hpp"
#include "platform/observed_ime971.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b971 {
std::uint32_t fun_0072cb80(Memory&m,const Inputs&i){
 const auto msg=i.dx;if(msg!=0x10d&&msg!=0x10e&&msg!=0x10f&&msg!=0x281)throw std::domain_error("971 message outside bounded routes");
 if(m.r32(0xb0de5c)!=0)throw std::domain_error("971 composition extraction excluded");
 if(msg!=0x281){m.w16(0xb0dc20,0);m.w32(0xb0de64,0);m.w32(0xb0de68,0);}
 if(msg==0x10d){m.w16(0xb0d9f4,0);m.w32(0xb0de6c,1);}else if(msg==0x10e)m.w32(0xb0de6c,0);
 const auto result=ra2::platform::ime971::forward(reinterpret_cast<HWND>(std::uintptr_t(i.cx)),msg,i.arg[0],LPARAM(i.arg[1]));m.w32(0xb0de70,std::uint32_t(result));return 1;
}
}
