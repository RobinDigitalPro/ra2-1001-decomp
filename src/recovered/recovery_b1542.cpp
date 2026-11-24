#include "recovered/recovery_b1542.hpp"
#include "platform/observed_window1542.hpp"
namespace ra2::recovered::b1542 {
std::uint32_t fun_00510a40(Memory&m,const Inputs&i){
 using namespace platform::window1542;
 need(m.r32(0x78549c)==ptr(reinterpret_cast<void*>(&get))&&m.r32(0x7853d0)==ptr(reinterpret_cast<void*>(&set))&&m.r32(0x7854a0)==ptr(reinterpret_cast<void*>(&send)),"1542 authenticated actual USER32 forwarders");
 auto parent=reinterpret_cast<HWND>(std::uintptr_t(i.cx));
 HWND child=guest(i.fp.image,[&]{return get(parent,0x71a);});
 if(!child)return 0;
 auto width=std::int32_t(m.r32(0x83a710)),height=std::int32_t(m.r32(0x83a714));
 need(width>=640&&width<=1600&&height>=480&&height<=1080,"1542 bounded declared numeric domain");
 int x=width>800?(width-800)/2:0,y=height>600?(height-600)/2:0;
 guest(i.fp.image,[&]{return set(child,nullptr,x,y,-1,-1,0xd);});
 guest(i.fp.image,[&]{return send(child,0x4e3,1,0);});
 return U(guest(i.fp.image,[&]{return send(child,0x4e4,0,width==640?0x7c66bc:0x7c66b4);}));
}
}
