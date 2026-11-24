#include "recovered/recovery_b1555.hpp"
#include "platform/observed_window1555.hpp"
namespace ra2::recovered::b1555 {
std::uint32_t fun_006645a0(Memory&m,const Inputs&i){
 using namespace platform::window1555;
 need(m.r32(0x78549c)==ptr(reinterpret_cast<void*>(&get))&&m.r32(0x7854a0)==ptr(reinterpret_cast<void*>(&send)),"1555 authenticated actual USER32 forwarders");
 need(m.r32(0xa27e90)==0,"1555 selected empty-configuration route only");
 const auto object=i.cx;HWND parent=reinterpret_cast<HWND>(std::uintptr_t(m.r32(object)));
 HWND child=guest(i.fp.image,[&]{return get(parent,0x65e);});
 need(child!=nullptr,"1555 genuine child required by selected route");
 auto send_real=[&](UINT msg){return guest(i.fp.image,[&]{return send(child,msg,0,0);});};
 (void)send_real(LB_RESETCONTENT);
 const auto count=send_real(LB_GETCOUNT);
 const std::int32_t next=count?std::int32_t(m.r32(object+0x98)): -1;
 m.w32(object+0x98,U(next));
 return U(m.r32(object+0x98));
}
}
