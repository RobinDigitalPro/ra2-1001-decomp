#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstring>
#include <cstdint>
#include <stdexcept>
#include "platform/x87_state.hpp"
namespace ra2::platform::peek1494 {
using U=std::uint32_t;using Raw=std::array<std::uint8_t,28>;
static_assert(sizeof(void*)==4&&sizeof(MSG)==28,"1494 genuinex86 MSG28 no padding");
inline void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
inline Raw raw(const MSG&m){Raw a;std::memcpy(a.data(),&m,28);return a;}
struct Fixture {
 HWND window{};bool queued{};MSG input{};U character{};DWORD thread=GetCurrentThreadId();
 Fixture(){window=CreateWindowExA(0,"EDIT","",WS_OVERLAPPED|ES_AUTOHSCROLL,0,0,200,32,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(window&&IsWindow(window)&&GetWindowThreadProcessId(window,nullptr)==thread,"1494 owned actualstandardEDIT");MSG m{};for(U k=0;k<64;++k){if(!::PeekMessageA(&m,nullptr,0,0,PM_REMOVE))return;need(m.hwnd==window,"1494 noforeignsetupmessage");TranslateMessage(&m);DispatchMessageA(&m);}throw std::runtime_error("1494 finite64 setupdrain");}
 void begin(U n){need(!queued&&window&&IsWindow(window),"1494 nonnested owned queue");MSG m{};need(::PeekMessageA(&m,nullptr,0,0,PM_NOREMOVE)==FALSE,"1494 emptythreadqueue beforeproducer");need(SetWindowTextA(window,"")!=FALSE,"1494 actualEDIT reset");need(::PeekMessageA(&m,nullptr,0,0,PM_NOREMOVE)==FALSE,"1494 reset createsnoqueuedmessages");character='A'+n%26;need(PostMessageA(window,WM_CHAR,character,1)!=FALSE,"1494 actualinteger WM_CHAR producer");need(::PeekMessageA(&input,nullptr,0,0,PM_NOREMOVE)!=FALSE&&input.hwnd==window&&input.message==WM_CHAR&&input.wParam==character&&input.lParam==1,"1494 actualqueued wholeMSG input");queued=true;}
 void unchanged(){need(queued&&IsWindow(window),"1494 livequeuedowner");MSG m{};need(::PeekMessageA(&m,nullptr,0,0,PM_NOREMOVE)!=FALSE&&raw(m)==raw(input),"1494 exactlysame queued raw28/time/point");char text[4]{};need(GetWindowTextA(window,text,4)==0&&text[0]==0,"1494 PM_NOREMOVE doesnotconsume ordispatch");}
 void finish(){unchanged();MSG m{};need(::PeekMessageA(&m,nullptr,0,0,PM_REMOVE)!=FALSE&&raw(m)==raw(input),"1494 consume exactsame actualmessage afterboth");TranslateMessage(&m);DispatchMessageA(&m);char text[4]{};need(GetWindowTextA(window,text,4)==1&&text[0]==char(character)&&text[1]==0,"1494 realEDIT defaultproc insertscharacter");queued=false;need(::PeekMessageA(&m,nullptr,0,0,PM_NOREMOVE)==FALSE,"1494 targetqueueempty aftersinglecharacter");}
 void close(){need(!queued,"1494 noqueuedmessage atcleanup");if(window){need(IsWindow(window)&&GetWindowThreadProcessId(window,nullptr)==thread,"1494 exactownedcleanup");need(DestroyWindow(window)!=FALSE,"1494 actualDestroyWindow");need(IsWindow(window)==FALSE,"1494 destroyedownedwindowverified");window=nullptr;}}
 ~Fixture(){if(window)DestroyWindow(window);}
};
struct Event{U output{},result{};Raw before{},after{};ra2::platform::x87::Image fp_before{},fp_after{};};
class Observer {
 using Peek=BOOL(WINAPI*)(LPMSG,HWND,UINT,UINT,UINT);Peek actual_=::PeekMessageA;U expected_{};bool active_{},called_{};inline static Observer*current_{};
public:
 Event event{};
 void begin(U p){need(!active_&&!current_&&p,"1494 nonnested realAPI observer");expected_=p;event={};active_=true;called_=false;current_=this;}
 void finish(const MSG&input){need(active_&&current_==this&&called_,"1494 exactlyone actualPeek call");need(event.result!=0&&event.after==raw(input),"1494 complete28 actualqueuedmessage production");need(ra2::platform::x87::same_numeric(event.fp_before,event.fp_after),"1494 actualPeek leaf numeric80 preserved");current_=nullptr;active_=false;}
 static BOOL WINAPI peek(LPMSG p,HWND h,UINT low,UINT high,UINT flags){need(current_&&current_->active_,"1494 activeactualPeek");auto&o=*current_;need(!o.called_&&ptr(p)==o.expected_&&!h&&!low&&!high&&!flags,"1494 exactactualAPI visibleoutputaddress/arguments");o.called_=true;o.event.output=ptr(p);std::memcpy(o.event.before.data(),p,28);o.event.fp_before=ra2::platform::x87::capture_host();ra2::platform::x87::restore_host(o.event.fp_before);const BOOL result=o.actual_(p,h,low,high,flags);o.event.fp_after=ra2::platform::x87::capture_host();ra2::platform::x87::restore_host(o.event.fp_after);o.event.result=U(result);std::memcpy(o.event.after.data(),p,28);return result;}
 template<class M>void bind(M&m){m.w32(0x785464,ptr(reinterpret_cast<void*>(&peek)));}
};
}
