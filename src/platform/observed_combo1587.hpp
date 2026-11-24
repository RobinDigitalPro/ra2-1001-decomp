#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <cstdio>
#include <stdexcept>
#include <vector>
#include "platform/x87_state.hpp"
namespace ra2::platform::combo1587 {
using U=std::uint32_t;
inline void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
struct Fs{U head{};std::uint16_t selector{};bool operator==(const Fs&v)const{return head==v.head&&selector==v.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event{U hwnd{},msg{},wparam{},lparam{},result{};x87::Image before{},after{};Fs fs_before{},fs_after{};};
inline std::vector<Event>&events(){static std::vector<Event>v;return v;}
inline HWND&owned_combo(){static HWND h{};return h;}
inline void verify_imports(){auto h=GetModuleHandleA("USER32.dll");need(h&&GetProcAddress(h,"SendMessageA")==reinterpret_cast<FARPROC>(&::SendMessageA),"1587 real USER32 SendMessageA import");}
inline LRESULT WINAPI send(HWND h,UINT msg,WPARAM wp,LPARAM lp){need(h==owned_combo()&&h,"1587 owned receiver only");need((msg==0x146&&wp==0&&lp==0)||(msg==0x144&&wp<4&&lp==0),"1587 selected actual messages");Event e{};e.hwnd=ptr(h);e.msg=msg;e.wparam=U(wp);e.lparam=U(lp);e.fs_before=fs();e.before=x87::capture_host();const LRESULT r=::SendMessageA(h,msg,wp,lp);e.after=x87::capture_host();e.fs_after=fs();e.result=U(r);need(x87::same_numeric(e.before,e.after),"1587 API physicalFP86/all80 identity");need(e.fs_before==e.fs_after,"1587 API FS head/selector");events().push_back(e);return r;}
template<class F>inline auto guest(x87::Image&image,F f){const auto host=x87::capture_host();x87::restore_host(image);try{auto result=f();image=x87::capture_host();x87::restore_host(host);need(x87::same_numeric(host,x87::capture_host()),"1587 guest hostFP restoration");return result;}catch(...){x87::restore_host(host);throw;}}
inline U clear(HWND h,x87::Image&image){return guest(image,[&]()->U{const LRESULT n=send(h,0x146,0,0);need(n>=1&&n<=4,"1587 genuine positive count1..4");for(LRESULT k=n-1;k>=0;--k)need(send(h,0x144,WPARAM(k),0)==k,"1587 actual reverse-delete result");return 0;});}
template<class M>inline void bind(M&m){verify_imports();m.w32(0x7854a0u,ptr(reinterpret_cast<void*>(&send)));}
struct Fixture{HWND parent{},combo{};DWORD thread=GetCurrentThreadId();RECT parent_rect{},combo_rect{};LONG parent_style{},combo_style{};
 Fixture(){need(!owned_combo(),"1587 one owned fixture");const auto host=x87::capture_host();try{verify_imports();parent=CreateWindowExA(WS_EX_TOOLWINDOW|WS_EX_NOACTIVATE,"STATIC","owned recovery combo",WS_POPUP,0,0,320,160,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);need(parent!=nullptr,"1587 hidden parent creation");combo=CreateWindowExA(0,"COMBOBOX","",WS_CHILD|CBS_DROPDOWNLIST|CBS_HASSTRINGS,0,0,240,120,parent,reinterpret_cast<HMENU>(73),GetModuleHandleA(nullptr),nullptr);need(combo&&IsChild(parent,combo),"1587 real ComboBox creation");parent_style=GetWindowLongA(parent,GWL_STYLE);combo_style=GetWindowLongA(combo,GWL_STYLE);need(GetWindowRect(parent,&parent_rect)&&GetWindowRect(combo,&combo_rect),"1587 initial actual rectangles");owned_combo()=combo;stable();x87::restore_host(host);}catch(...){if(combo)DestroyWindow(combo);if(parent)DestroyWindow(parent);owned_combo()=nullptr;x87::restore_host(host);throw;}}
 void stable()const{char pc[32]{},cc[32]{};RECT pr{},cr{};need(parent&&combo&&IsWindow(parent)&&IsWindow(combo)&&GetParent(combo)==parent&&IsChild(parent,combo),"1587 live owned hierarchy");need(GetWindowThreadProcessId(parent,nullptr)==thread&&GetWindowThreadProcessId(combo,nullptr)==thread,"1587 own window thread");need(GetClassNameA(parent,pc,32)&&GetClassNameA(combo,cc,32)&&lstrcmpiA(pc,"STATIC")==0&&lstrcmpiA(cc,"COMBOBOX")==0,"1587 built-in classes");need(!IsWindowVisible(parent)&&!IsWindowVisible(combo),"1587 remain hidden");need(GetWindowLongA(parent,GWL_STYLE)==parent_style&&GetWindowLongA(combo,GWL_STYLE)==combo_style&&(combo_style&(CBS_DROPDOWNLIST|CBS_HASSTRINGS))==(CBS_DROPDOWNLIST|CBS_HASSTRINGS),"1587 exact stable styles");need(GetWindowRect(parent,&pr)&&GetWindowRect(combo,&cr)&&EqualRect(&pr,&parent_rect)&&EqualRect(&cr,&combo_rect),"1587 stable actual rectangles");}
 void check_empty(){const auto host=x87::capture_host();try{stable();need(::SendMessageA(combo,CB_GETCOUNT,0,0)==0&&::SendMessageA(combo,CB_GETCURSEL,0,0)==CB_ERR,"1587 exact empty relevant poststate");x87::restore_host(host);}catch(...){x87::restore_host(host);throw;}}
 void arm(unsigned n){const auto host=x87::capture_host();try{check_empty();const unsigned count=1+n%4;for(unsigned j=0;j<count;++j){char text[32];std::snprintf(text,sizeof(text),"owned item %u",j);need(::SendMessageA(combo,CB_ADDSTRING,0,reinterpret_cast<LPARAM>(text))==j,"1587 actual item insertion");need(::SendMessageA(combo,CB_SETITEMDATA,j,0x100+j)!=CB_ERR,"1587 genuine itemdata");}need(::SendMessageA(combo,CB_SETCURSEL,count-1,0)==count-1&&::SendMessageA(combo,CB_GETCOUNT,0,0)==count&&::SendMessageA(combo,CB_GETCURSEL,0,0)==count-1,"1587 exact populated selection/count");for(unsigned j=0;j<count;++j){char text[32]{},expected[32]{};std::snprintf(expected,sizeof(expected),"owned item %u",j);need(::SendMessageA(combo,CB_GETLBTEXTLEN,j,0)<32&&::SendMessageA(combo,CB_GETLBTEXT,j,reinterpret_cast<LPARAM>(text))>=0&&lstrcmpA(text,expected)==0&&::SendMessageA(combo,CB_GETITEMDATA,j,0)==0x100+j,"1587 actual strings/data");}stable();events().clear();events().reserve(5);x87::restore_host(host);}catch(...){x87::restore_host(host);throw;}}
 void close(){const auto host=x87::capture_host();check_empty();const HWND c=combo,p=parent;need(DestroyWindow(c)&&!IsWindow(c),"1587 own combo destruction");combo=nullptr;owned_combo()=nullptr;need(DestroyWindow(p)&&!IsWindow(p),"1587 own parent destruction");parent=nullptr;x87::restore_host(host);}
 ~Fixture(){if(combo)DestroyWindow(combo);if(parent)DestroyWindow(parent);if(owned_combo()==combo)owned_combo()=nullptr;}
};
}
