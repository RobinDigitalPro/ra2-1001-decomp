#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include "platform/x87_state.hpp"
namespace ra2::platform::window1542 {
using U=std::uint32_t;
inline void need(bool ok,const char* m){if(!ok)throw std::runtime_error(m);}
inline U ptr(const void* p){return U(reinterpret_cast<std::uintptr_t>(p));}
struct Fs{U head{};std::uint16_t selector{};bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event{U kind{},hwnd{},arg0{},arg1{},arg2{},arg3{},result{};x87::Image before{},after{};};
inline std::vector<Event>& events(){static std::vector<Event> v;return v;}
inline void verify_imports(){auto h=GetModuleHandleA("USER32.dll");need(h&&GetProcAddress(h,"GetDlgItem")==reinterpret_cast<FARPROC>(&::GetDlgItem)&&GetProcAddress(h,"SetWindowPos")==reinterpret_cast<FARPROC>(&::SetWindowPos)&&GetProcAddress(h,"SendMessageA")==reinterpret_cast<FARPROC>(&::SendMessageA),"1542 actual USER32 identities");}
inline void record(Event e){need(x87::same_numeric(e.before,e.after),"1542 actual API physical FP86/all80 changed");events().push_back(e);}
inline HWND WINAPI get(HWND parent,int id){Event e{};e.kind=0;e.hwnd=ptr(parent);e.arg0=U(id);e.before=x87::capture_host();HWND r=::GetDlgItem(parent,id);e.after=x87::capture_host();e.result=ptr(r);record(e);return r;}
inline BOOL WINAPI set(HWND child,HWND after,int x,int y,int w,int h,UINT flags){Event e{};e.kind=1;e.hwnd=ptr(child);e.arg0=ptr(after);e.arg1=U(x);e.arg2=U(y);e.arg3=flags;e.before=x87::capture_host();BOOL r=::SetWindowPos(child,after,x,y,w,h,flags);e.after=x87::capture_host();e.result=U(r);need(w==-1&&h==-1,"1542 exact unchanged size");record(e);return r;}
inline LRESULT WINAPI send(HWND child,UINT msg,WPARAM wp,LPARAM lp){Event e{};e.kind=2;e.hwnd=ptr(child);e.arg0=msg;e.arg1=U(wp);e.arg2=U(lp);e.before=x87::capture_host();LRESULT r=::SendMessageA(child,msg,wp,lp);e.after=x87::capture_host();e.result=U(r);record(e);return r;}
template<class F>inline auto guest(x87::Image& image,F call){auto host=x87::capture_host();x87::restore_host(image);auto result=call();image=x87::capture_host();x87::restore_host(host);return result;}
template<class M>inline void bind(M&m){m.w32(0x78549c,ptr(reinterpret_cast<void*>(&get)));m.w32(0x7853d0,ptr(reinterpret_cast<void*>(&set)));m.w32(0x7854a0,ptr(reinterpret_cast<void*>(&send)));}
struct Fixture{
 HWND parent{},child{};DWORD thread=GetCurrentThreadId();
 Fixture(){auto inst=GetModuleHandleA(nullptr);parent=CreateWindowExA(0,"STATIC","",WS_POPUP,100,100,300,200,nullptr,nullptr,inst,nullptr);need(parent&&IsWindow(parent),"1542 owned hidden STATIC parent");child=CreateWindowExA(0,"STATIC","",WS_CHILD,17,23,80,20,parent,reinterpret_cast<HMENU>(0x71a),inst,nullptr);need(child&&IsWindow(child)&&GetDlgCtrlID(child)==0x71a&&GetParent(child)==parent&&GetWindowThreadProcessId(child,nullptr)==thread,"1542 owned hidden STATIC child");}
 void arm(){auto host=x87::capture_host();need(IsWindow(parent)&&IsWindow(child)&&GetParent(child)==parent,"1542 live owned pair");need(::SetWindowPos(child,nullptr,17,23,80,20,SWP_NOZORDER|SWP_NOACTIVATE)!=FALSE,"1542 genuine rearm");events().clear();events().reserve(4);x87::restore_host(host);}
 POINT position()const{RECT r{};need(GetWindowRect(child,&r)!=FALSE,"1542 child rect");POINT p{r.left,r.top};SetLastError(0);auto changed=MapWindowPoints(HWND_DESKTOP,parent,&p,1);need(changed!=0||GetLastError()==0,"1542 parent coordinates");need(r.right-r.left==80&&r.bottom-r.top==20,"1542 child size preserved");return p;}
 void verify(U width,U height){need(events().size()==4,"1542 exact four API calls");auto&v=events();U x=width>800?(width-800)/2:0,y=height>600?(height-600)/2:0;need(v[0].kind==0&&v[0].hwnd==ptr(parent)&&v[0].arg0==0x71a&&v[0].result==ptr(child),"1542 GetDlgItem trace");need(v[1].kind==1&&v[1].hwnd==ptr(child)&&v[1].arg0==0&&v[1].arg1==x&&v[1].arg2==y&&v[1].arg3==0xd&&v[1].result!=0,"1542 SetWindowPos trace");need(v[2].kind==2&&v[2].hwnd==ptr(child)&&v[2].arg0==0x4e3&&v[2].arg1==1&&v[2].arg2==0,"1542 first actual message");need(v[3].kind==2&&v[3].hwnd==ptr(child)&&v[3].arg0==0x4e4&&v[3].arg1==0&&v[3].arg2==(width==640?0x7c66bc:0x7c66b4),"1542 second actual message");auto p=position();need(p.x==LONG(x)&&p.y==LONG(y)&&IsWindow(parent)&&IsWindow(child)&&GetParent(child)==parent&&GetDlgCtrlID(child)==0x71a,"1542 actual geometry/ownership");}
 void close(){need(parent&&child&&IsWindow(parent)&&IsWindow(child),"1542 exact pair before cleanup");need(DestroyWindow(child)!=FALSE&&IsWindow(child)==FALSE,"1542 child cleanup");child=nullptr;need(DestroyWindow(parent)!=FALSE&&IsWindow(parent)==FALSE,"1542 parent cleanup");parent=nullptr;}
 ~Fixture(){if(child)DestroyWindow(child);if(parent)DestroyWindow(parent);}
};
}
