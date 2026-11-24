#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include "platform/x87_state.hpp"
namespace ra2::platform::window1555 {
using U=std::uint32_t;
inline void need(bool ok,const char*m){if(!ok)throw std::runtime_error(m);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
struct Fs{U head{};std::uint16_t selector{};bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event{U kind{},hwnd{},arg0{},arg1{},arg2{},arg3{},result{};x87::Image before{},after{};};
inline std::vector<Event>&events(){static std::vector<Event>v;return v;}
inline void verify_imports(){auto h=GetModuleHandleA("USER32.dll");need(h&&GetProcAddress(h,"GetDlgItem")==reinterpret_cast<FARPROC>(&::GetDlgItem)&&GetProcAddress(h,"SendMessageA")==reinterpret_cast<FARPROC>(&::SendMessageA),"1555 authentic USER32 import pin");}
inline void record(Event e){need(x87::same_numeric(e.before,e.after),"1555 USER32 physical FP86/all80 changed");events().push_back(e);}
inline HWND WINAPI get(HWND parent,int id){Event e{};e.kind=0;e.hwnd=ptr(parent);e.arg0=U(id);e.before=x87::capture_host();HWND r=::GetDlgItem(parent,id);e.after=x87::capture_host();e.result=ptr(r);record(e);return r;}
inline LRESULT WINAPI send(HWND child,UINT msg,WPARAM wp,LPARAM lp){Event e{};e.kind=1;e.hwnd=ptr(child);e.arg0=msg;e.arg1=U(wp);e.arg2=U(lp);e.before=x87::capture_host();LRESULT r=::SendMessageA(child,msg,wp,lp);e.after=x87::capture_host();e.result=U(r);record(e);return r;}
template<class F>inline auto guest(x87::Image&image,F call){auto host=x87::capture_host();x87::restore_host(image);auto result=call();image=x87::capture_host();x87::restore_host(host);return result;}
template<class M>inline void bind(M&m){m.w32(0x78549c,ptr(reinterpret_cast<void*>(&get)));m.w32(0x7854a0,ptr(reinterpret_cast<void*>(&send)));}
struct Fixture{HWND parent{},child{};DWORD thread=GetCurrentThreadId();
 Fixture(){auto inst=GetModuleHandleA(nullptr);parent=CreateWindowExA(0,"STATIC","",WS_POPUP,100,100,320,220,nullptr,nullptr,inst,nullptr);need(parent&&IsWindow(parent),"1555 real hidden STATIC parent");child=CreateWindowExA(WS_EX_CLIENTEDGE,"LISTBOX","",WS_CHILD|WS_VSCROLL|LBS_NOTIFY,10,12,240,120,parent,reinterpret_cast<HMENU>(0x65e),inst,nullptr);need(child&&IsWindow(child)&&GetDlgCtrlID(child)==0x65e&&GetParent(child)==parent&&GetWindowThreadProcessId(child,nullptr)==thread,"1555 genuine owned standard LISTBOX child");}
 void populate(){need(::SendMessageA(child,LB_RESETCONTENT,0,0)==0,"1555 actual fixture reset");for(const char*s:{"alpha","bravo","charlie"})need(::SendMessageA(child,LB_ADDSTRING,0,reinterpret_cast<LPARAM>(s))>=0,"1555 actual fixture insert");need(::SendMessageA(child,LB_SETCURSEL,1,0)==1,"1555 actual fixture select index 1");need(::SendMessageA(child,LB_GETCOUNT,0,0)==3&&::SendMessageA(child,LB_GETCURSEL,0,0)==1,"1555 exact initial UI state");}
 void arm(){auto host=x87::capture_host();need(IsWindow(parent)&&IsWindow(child)&&GetParent(child)==parent,"1555 live owned pair");populate();events().clear();events().reserve(3);x87::restore_host(host);}
 void close(){need(parent&&child&&IsWindow(parent)&&IsWindow(child),"1555 owned pair cleanup precondition");need(DestroyWindow(child)!=FALSE&&IsWindow(child)==FALSE,"1555 LISTBOX cleanup");child=nullptr;need(DestroyWindow(parent)!=FALSE&&IsWindow(parent)==FALSE,"1555 parent cleanup");parent=nullptr;}
 ~Fixture(){if(child)DestroyWindow(child);if(parent)DestroyWindow(parent);}
};
}
