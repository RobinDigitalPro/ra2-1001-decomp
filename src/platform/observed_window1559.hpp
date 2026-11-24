#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>
#include "platform/x87_state.hpp"
namespace ra2::platform::window1559 {
using U=std::uint32_t;
inline void need(bool ok,const char*m){if(!ok)throw std::runtime_error(m);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
struct Fs{U head{};std::uint16_t selector{};bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event{U kind{},hwnd{},arg0{},arg1{},arg2{},arg3{},result{};x87::Image before{},after{};};
inline std::vector<Event>&events(){static std::vector<Event>v;return v;}
inline void verify_imports(){auto h=GetModuleHandleA("USER32.dll");need(h&&GetProcAddress(h,"GetDlgItem")==reinterpret_cast<FARPROC>(&::GetDlgItem)&&GetProcAddress(h,"SendMessageA")==reinterpret_cast<FARPROC>(&::SendMessageA),"1559 authentic USER32 import identities");}
inline void record(Event e){need(x87::same_numeric(e.before,e.after),"1559 actual USER32 physical FP86/all80 changed");events().push_back(e);}
inline HWND WINAPI get(HWND parent,int id){Event e{};e.kind=0;e.hwnd=ptr(parent);e.arg0=U(id);e.before=x87::capture_host();HWND r=::GetDlgItem(parent,id);e.after=x87::capture_host();e.result=ptr(r);record(e);return r;}
inline LRESULT WINAPI send(HWND child,UINT msg,WPARAM wp,LPARAM lp){Event e{};e.kind=1;e.hwnd=ptr(child);e.arg0=msg;e.arg1=U(wp);e.arg2=U(lp);e.before=x87::capture_host();LRESULT r=::SendMessageA(child,msg,wp,lp);e.after=x87::capture_host();e.result=U(r);record(e);return r;}
template<class F>inline auto guest(x87::Image&image,F call){auto host=x87::capture_host();x87::restore_host(image);auto result=call();image=x87::capture_host();x87::restore_host(host);return result;}
template<class M>inline void bind(M&m){m.w32(0x78549c,ptr(reinterpret_cast<void*>(&get)));m.w32(0x7854a0,ptr(reinterpret_cast<void*>(&send)));}
struct Fixture{HWND parent{};std::array<HWND,4>child{};DWORD thread=GetCurrentThreadId();
 Fixture(){auto inst=GetModuleHandleA(nullptr);parent=CreateWindowExA(0,"STATIC","",WS_POPUP,100,100,360,260,nullptr,nullptr,inst,nullptr);need(parent&&IsWindow(parent),"1559 genuine owned parent");child[0]=CreateWindowExA(0,"STATIC","",WS_CHILD|SS_LEFT,8,8,120,24,parent,reinterpret_cast<HMENU>(0x5e5),inst,nullptr);child[1]=CreateWindowExA(0,"STATIC","",WS_CHILD|SS_LEFT,8,38,120,24,parent,reinterpret_cast<HMENU>(0x5df),inst,nullptr);child[2]=CreateWindowExA(0,"BUTTON","choice A",WS_CHILD|BS_CHECKBOX,8,72,150,24,parent,reinterpret_cast<HMENU>(0x664),inst,nullptr);child[3]=CreateWindowExA(0,"BUTTON","choice B",WS_CHILD|BS_CHECKBOX,8,102,150,24,parent,reinterpret_cast<HMENU>(0x663),inst,nullptr);verify();}
 void verify()const{need(IsWindow(parent),"1559 live parent");char cls[32]{};need(::GetClassNameA(parent,cls,32)>0&&lstrcmpiA(cls,"Static")==0,"1559 standard STATIC parent");constexpr int ids[4]={0x5e5,0x5df,0x664,0x663};for(unsigned k=0;k<4;++k){need(child[k]&&IsWindow(child[k])&&GetParent(child[k])==parent&&GetDlgCtrlID(child[k])==ids[k]&&GetWindowThreadProcessId(child[k],nullptr)==thread,"1559 exact owned child identity");char name[32]{};need(::GetClassNameA(child[k],name,32)>0&&lstrcmpiA(name,k<2?"Static":"Button")==0,"1559 standard child class");const auto style=GetWindowLongPtrA(child[k],GWL_STYLE);need((style&WS_CHILD)!=0&&(style&WS_VISIBLE)==0,"1559 hidden owned child style");if(k>=2)need((style&BS_TYPEMASK)==BS_CHECKBOX,"1559 standard BS_CHECKBOX style");}}
 void arm(U initial_a,U initial_b){auto host=x87::capture_host();verify();need(::SendMessageA(child[2],BM_SETCHECK,initial_a,0)==0&&::SendMessageA(child[3],BM_SETCHECK,initial_b,0)==0,"1559 genuine initial button state");need(::SendMessageA(child[2],BM_GETCHECK,0,0)==LRESULT(initial_a)&&::SendMessageA(child[3],BM_GETCHECK,0,0)==LRESULT(initial_b),"1559 opposite initial checkbox states");events().clear();events().reserve(8);x87::restore_host(host);}
 void close(){verify();for(auto&c:child){need(DestroyWindow(c)!=FALSE&&IsWindow(c)==FALSE,"1559 child cleanup");c=nullptr;}need(DestroyWindow(parent)!=FALSE&&IsWindow(parent)==FALSE,"1559 parent cleanup");parent=nullptr;}
 ~Fixture(){for(auto c:child)if(c)DestroyWindow(c);if(parent)DestroyWindow(parent);}
};
}
