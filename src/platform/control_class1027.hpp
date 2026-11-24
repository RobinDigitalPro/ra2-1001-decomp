#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>
namespace ra2::recovered::b1027::ui {
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
template<class T>inline unsigned address(T p){static_assert(sizeof(void*)==4);return unsigned(reinterpret_cast<std::uintptr_t>(p));}
inline constexpr unsigned ids[]={0x694,0x6ec,0x6f4,0x411,0x6d2,0x419};
struct Event{unsigned hwnd,id;bool operator==(const Event&o)const{return hwnd==o.hwnd&&id==o.id;}};
class Windows;
inline Windows*active=nullptr;inline std::vector<Event>events;
inline int WINAPI control_id(HWND);
class Windows {
 HWND parent_{};std::array<HWND,6>buttons_{};std::array<LONG,7>procs_{},styles_{},exstyles_{};std::array<RECT,7>rects_{};
 std::array<LRESULT,6>checks_{},states_{};std::array<unsigned char,DLGWINDOWEXTRA>extra_{};DWORD class_proc_=0;unsigned selected_=0;
 HWND window(unsigned k)const{return k?buttons_.at(k-1u):parent_;}
 std::array<unsigned char,DLGWINDOWEXTRA>extra()const{std::array<unsigned char,DLGWINDOWEXTRA>v{};for(unsigned k=0;k+4u<=v.size();k+=4u){const LONG n=GetWindowLongA(parent_,int(k));std::memcpy(v.data()+k,&n,4u);}if(v.size()%4u){const WORD n=GetWindowWord(parent_,int(v.size()-2u));std::memcpy(v.data()+v.size()-2u,&n,2u);}return v;}
 public:
 Windows(){alignas(DWORD) std::array<WORD,12>t{};const DWORD style=WS_POPUP|DS_MODALFRAME;std::memcpy(t.data(),&style,4);t[7]=180u;t[8]=120u;parent_=CreateDialogIndirectParamA(GetModuleHandleW(nullptr),reinterpret_cast<const DLGTEMPLATE*>(t.data()),nullptr,nullptr,0);need(parent_&&!IsWindowVisible(parent_),"1027 genuine hidden NULL-DLGPROC default dialog");
  for(unsigned k=0;k<6u;++k){buttons_[k]=CreateWindowExA(0,"BUTTON","classifier",WS_CHILD|BS_PUSHBUTTON,int(4u+85u*(k%2u)),int(4u+28u*(k/2u)),80,20,parent_,reinterpret_cast<HMENU>(std::uintptr_t(ids[k])),GetModuleHandleW(nullptr),nullptr);need(buttons_[k]&&unsigned(GetDlgCtrlID(buttons_[k]))==ids[k],"1027 actual six recognized control IDs");checks_[k]=SendMessageA(buttons_[k],BM_GETCHECK,0,0);states_[k]=SendMessageA(buttons_[k],BM_GETSTATE,0,0);}
  class_proc_=GetClassLongA(parent_,GCL_WNDPROC);need(class_proc_&&GetClassLongA(parent_,GCW_ATOM)==32770u&&GetWindowLongA(parent_,DWL_DLGPROC)==0,"1027 actual unmodified system dialog class");extra_=extra();
  for(unsigned k=0;k<7u;++k){const auto h=window(k);procs_[k]=GetWindowLongA(h,GWL_WNDPROC);styles_[k]=GetWindowLongA(h,GWL_STYLE);exstyles_[k]=GetWindowLongA(h,GWL_EXSTYLE);need(procs_[k]&&GetWindowRect(h,&rects_[k]),"1027 initial complete window attributes");ValidateRect(h,nullptr);}verify();
 }
 ~Windows(){if(active==this)active=nullptr;if(parent_)DestroyWindow(parent_);}
 Windows(const Windows&)=delete;
 HWND parent()const{return parent_;}HWND child()const{return buttons_.at(selected_);}unsigned id()const{return ids[selected_];}
 void select(unsigned k){need(!active&&k<6u,"1027 select outside candidate");selected_=k;verify();}
 void verify()const{need(GetClassLongA(parent_,GCL_WNDPROC)==class_proc_&&GetClassLongA(parent_,GCW_ATOM)==32770u&&GetWindowLongA(parent_,DWL_DLGPROC)==0&&extra()==extra_,"1027 complete unchanged30 dialog extra bytes and system procedures");for(unsigned k=0;k<7u;++k){const auto h=window(k);char cls[40]{},text[40]{};need(IsWindow(h)&&!IsWindowVisible(h)&&GetClassNameA(h,cls,40)>0&&lstrcmpiA(cls,k?"BUTTON":"#32770")==0&&GetWindowLongA(h,GWL_WNDPROC)==procs_[k]&&GetWindowLongA(h,GWL_STYLE)==styles_[k]&&GetWindowLongA(h,GWL_EXSTYLE)==exstyles_[k],"1027 all actual window identities/procedures/styles");RECT r{};need(GetWindowRect(h,&r)&&std::memcmp(&r,&rects_[k],sizeof(r))==0&&!GetUpdateRect(h,&r,FALSE),"1027 complete unchanged geometry/update regions");GetWindowTextA(h,text,40);need(std::strcmp(text,k?"classifier":"")==0,"1027 all unchanged window text");if(k){need(GetParent(h)==parent_&&GetDlgItem(parent_,int(ids[k-1u]))==h&&unsigned(GetDlgCtrlID(h))==ids[k-1u]&&SendMessageA(h,BM_GETCHECK,0,0)==checks_[k-1u]&&SendMessageA(h,BM_GETSTATE,0,0)==states_[k-1u],"1027 independent full six-button ID/parent/check/state map");}}}
 void begin(){need(!active,"1027 exclusive observer");verify();events.clear();events.reserve(2);active=this;}
 void finish(){need(active==this,"1027 matching observation");active=nullptr;need(events==std::vector<Event>{{address(child()),id()}},"1027 exact one actual GetDlgCtrlID call/full result");verify();}
};
inline int WINAPI control_id(HWND h){need(active,"1027 API inside observation only");const auto r=::GetDlgCtrlID(h);const auto error=GetLastError();events.push_back({address(h),unsigned(r)});SetLastError(error);return r;}
}
