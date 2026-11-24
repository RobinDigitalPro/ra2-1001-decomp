#include "recovered/recovery_b1559.hpp"
#include "platform/observed_window1559.hpp"
namespace ra2::recovered::b1559 {
namespace {
using U=std::uint32_t;
// Exact selected branch of original76EF45: UTF16 word count, through NUL.
U length16(Memory&m,U p){U n=0;while(m.r16(p+n*2u)!=0)++n;return n;}
// Exact selected C-locale branch of original782826. No locale API/heap path.
void uppercase16(Memory&m,U p){using platform::window1559::need;need(m.r32(0xb10530u)==0,"1559 original C-locale selector");for(U a=p;;a+=2u){const auto c=m.r16(a);if(!c)break;if(c>=0x61u&&c<=0x7au)m.w16(a,std::uint16_t(c-0x20u));}}
}
std::uint32_t fun_00606380(Memory&m,const Inputs&i){
 using namespace platform::window1559;
 need(m.r32(0x78549c)==ptr(reinterpret_cast<void*>(&get))&&m.r32(0x7854a0)==ptr(reinterpret_cast<void*>(&send)),"1559 authentic USER32 forwarders");
 const U self=i.cx,settings=m.r32(self+8);const auto parent=reinterpret_cast<HWND>(std::uintptr_t(m.r32(self)));
 auto child=guest(i.fp.image,[&]{return get(parent,0x5e5);});need(child!=nullptr,"1559 owned first child");
 guest(i.fp.image,[&]{return send(child,0x4b3,0x15,LPARAM(settings+0x70));});
 need(length16(m,settings+0x70)>0,"1559 nonempty UTF16 name finite route");uppercase16(m,settings+0x70);
 // Original4068F0 is one-byte RET; diagnostic argument pointers are unread.
 child=guest(i.fp.image,[&]{return get(parent,0x5df);});need(child!=nullptr,"1559 owned second child");
 guest(i.fp.image,[&]{return send(child,0x4b5,0x15,LPARAM(settings+0x9a));});
 child=guest(i.fp.image,[&]{return get(parent,0x664);});need(child!=nullptr,"1559 owned checkbox");
 const U eax=U(guest(i.fp.image,[&]{return send(child,BM_GETCHECK,0,0);}));need(eax==1u,"1559 checked-only full LRESULT1 contract");
 for(U k=0;k<28;++k)m.w32(settings+k*4u,m.r32(self+0x0c+k*4u));
 // Tail loads ECX/EDX from settings and calls4068F0 RET. EAX stays full1.
 return eax;
}
}
