#include "recovered/recovery_b1557.hpp"
#include "platform/observed_window1557.hpp"
namespace ra2::recovered::b1557 {
std::uint32_t fun_00615040(Memory&m,const Inputs&i){
 using namespace platform::window1557;
 need(m.r32(i.cx)==0u,"1557 declared no-renderer projection");
 need(m.r32(0x7853f8u)==ptr(reinterpret_cast<void*>(&validate)),"1557 authentic ValidateRect forwarder");
 return U(guest(i.fp.image,[&]{return validate(reinterpret_cast<HWND>(std::uintptr_t(i.arg[0])),nullptr);}));
}
}
