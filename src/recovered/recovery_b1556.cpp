#include "recovered/recovery_b1556.hpp"
#include "platform/observed_window1556.hpp"
namespace ra2::recovered::b1556 {
std::uint32_t fun_006064e0(Memory&m,const Inputs&i){
 using namespace platform::window1556;
 need(m.r32(0x78549c)==ptr(reinterpret_cast<void*>(&get))&&m.r32(0x7854a0)==ptr(reinterpret_cast<void*>(&send)),"1556 authenticated actual USER32 forwarders");
 const U self=i.cx;const U settings=m.r32(self+8);const HWND parent=reinterpret_cast<HWND>(std::uintptr_t(m.r32(self)));
 auto child=guest(i.fp.image,[&]{return get(parent,0x5e5);});
 guest(i.fp.image,[&]{return send(child,0x4b2,0,LPARAM(settings+0x70));});
 child=guest(i.fp.image,[&]{return get(parent,0x5df);});
 guest(i.fp.image,[&]{return send(child,0x4b4,0,LPARAM(settings+0x9a));});
 const bool use_input=m.r32(settings)!=0&&m.r32(settings+4)!=0xffffffffu&&m.r32(settings+8)!=0xffffffffu;
 const U source=use_input?settings:0xa27df4u;
 for(U k=0;k<0x1c;++k)m.w32(self+0x0c+k*4u,m.r32(source+k*4u));
 const U check_flag=use_input?1u:0u;
 child=guest(i.fp.image,[&]{return get(parent,0x664);});
 if(child)guest(i.fp.image,[&]{return send(child,BM_SETCHECK,check_flag,0);});
 child=guest(i.fp.image,[&]{return get(parent,0x663);});
 return child?U(guest(i.fp.image,[&]{return send(child,BM_SETCHECK,check_flag?0u:1u,0);})):0u;
}
}
