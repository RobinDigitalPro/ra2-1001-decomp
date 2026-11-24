#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include "platform/x87_state.hpp"
namespace ra2::platform::window1557 {
using U=std::uint32_t;
inline void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
struct Fs{U head{};std::uint16_t selector{};bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event{U kind{},hwnd{},arg0{},arg1{},arg2{},arg3{},result{};x87::Image before{},after{};};
inline std::vector<Event>&events(){static std::vector<Event>v;return v;}
inline void verify_imports(){auto h=GetModuleHandleA("USER32.dll");need(h&&GetProcAddress(h,"ValidateRect")==reinterpret_cast<FARPROC>(&::ValidateRect),"1557 actual USER32 ValidateRect import");}
inline BOOL WINAPI validate(HWND window,const RECT*rectangle){Event e{};e.kind=2;e.hwnd=ptr(window);e.arg0=ptr(rectangle);e.before=x87::capture_host();BOOL r=::ValidateRect(window,rectangle);e.after=x87::capture_host();e.result=U(r);need(x87::same_numeric(e.before,e.after),"1557 API physicalFP86/all80");events().push_back(e);return r;}
template<class F>inline auto guest(x87::Image&image,F f){auto host=x87::capture_host();x87::restore_host(image);auto result=f();image=x87::capture_host();x87::restore_host(host);return result;}
template<class M>inline void bind(M&m){m.w32(0x7853f8u,ptr(reinterpret_cast<void*>(&validate)));}
struct Fixture{HWND parent{};DWORD thread=GetCurrentThreadId();RECT dirty{};
 Fixture(){parent=CreateWindowExA(WS_EX_NOACTIVATE|WS_EX_TOOLWINDOW,"STATIC","",WS_POPUP|WS_VISIBLE,-30000,-30000,320,220,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);need(parent&&IsWindow(parent)&&GetWindowThreadProcessId(parent,nullptr)==thread,"1557 own offscreen noactivate STATIC");}
 void arm(unsigned n){auto host=x87::capture_host();need(IsWindow(parent),"1557 live own window");dirty=RECT{LONG(12+n%7),LONG(14+n%5),LONG(80+n%7),LONG(90+n%5)};RECT seen{};need(::ValidateRect(parent,nullptr)&&::InvalidateRect(parent,&dirty,FALSE),"1557 initialize genuine dirtyregion");need(::GetUpdateRect(parent,&seen,FALSE)&&EqualRect(&seen,&dirty),"1557 exact nonempty initial update region");events().clear();events().reserve(1);x87::restore_host(host);}
 void close(){need(parent&&IsWindow(parent)&&DestroyWindow(parent)&&!IsWindow(parent),"1557 own window cleanup");parent=nullptr;}
 ~Fixture(){if(parent)DestroyWindow(parent);}
};
}
