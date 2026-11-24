#pragma once
#include "platform/peek1494.hpp"
#include <vector>
namespace ra2::platform::queue1533 {
using namespace peek1494;
struct Fs{U head{};std::uint16_t selector{};bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event{U kind{},flags{},result{};Raw message{};x87::Image before{},after{};};
inline std::vector<Event>& events(){static std::vector<Event> v;return v;}
inline MSG& queued_input(){static MSG v{};return v;}
inline void reset(const MSG& input){events().clear();events().reserve(5);queued_input()=input;}
inline void verify_imports(){auto h=GetModuleHandleA("USER32.dll");need(h&&GetProcAddress(h,"PeekMessageA")==reinterpret_cast<FARPROC>(&::PeekMessageA)&&GetProcAddress(h,"TranslateMessage")==reinterpret_cast<FARPROC>(&::TranslateMessage)&&GetProcAddress(h,"DispatchMessageA")==reinterpret_cast<FARPROC>(&::DispatchMessageA),"1533 actual USER32 import identity");}
inline BOOL WINAPI peek(LPMSG m,HWND h,UINT lo,UINT hi,UINT flags){need(!h&&!lo&&!hi,"1533 exact filter0/window0");Event e{};e.kind=0;e.flags=flags;e.before=x87::capture_host();x87::restore_host(e.before);BOOL r=::PeekMessageA(m,h,lo,hi,flags);e.after=x87::capture_host();x87::restore_host(e.after);e.result=U(r);e.message=raw(*m);events().push_back(e);x87::restore_host(e.after);return r;}
inline BOOL WINAPI translate(const MSG* m){Event e{};e.kind=1;e.message=raw(*m);e.before=x87::capture_host();x87::restore_host(e.before);BOOL r=::TranslateMessage(m);e.after=x87::capture_host();x87::restore_host(e.after);e.result=U(r);events().push_back(e);x87::restore_host(e.after);return r;}
inline LRESULT WINAPI dispatch(const MSG* m){Event e{};e.kind=2;e.message=raw(*m);e.before=x87::capture_host();x87::restore_host(e.before);LRESULT r=::DispatchMessageA(m);e.after=x87::capture_host();x87::restore_host(e.after);e.result=U(r);events().push_back(e);x87::restore_host(e.after);return r;}
template<class F>inline auto guest(x87::Image& image,F call){auto host=x87::capture_host();x87::restore_host(image);auto result=call();image=x87::capture_host();x87::restore_host(host);return result;}
template<class M>inline void bind(M&m){m.w32(0x785464,ptr(reinterpret_cast<void*>(&peek)));m.w32(0x7854b0,ptr(reinterpret_cast<void*>(&translate)));m.w32(0x7854b4,ptr(reinterpret_cast<void*>(&dispatch)));}
inline void verify_trace(){const auto&v=events();need(v.size()==5&&v[0].kind==0&&v[0].flags==0&&v[0].result&&v[1].kind==0&&v[1].flags==1&&v[1].result&&v[2].kind==1&&v[3].kind==2&&v[4].kind==0&&v[4].flags==0&&!v[4].result,"1533 exact fiveAPI sequence");for(U k=0;k<4;++k)need(v[k].message==raw(queued_input()),"1533 raw28 equals this side actualinput");}
inline void consumed(Fixture& f){MSG m{};need(!::PeekMessageA(&m,nullptr,0,0,PM_NOREMOVE),"1533 final realqueueempty");char text[4]{};need(GetWindowTextA(f.window,text,4)==1&&text[0]==char(f.character)&&text[1]==0,"1533 actual EDIT insertion");f.queued=false;}
}
