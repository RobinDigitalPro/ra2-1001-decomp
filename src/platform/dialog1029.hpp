#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b1029.hpp"
#include "platform/combo1029.hpp"
#include <array>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <vector>
#include <stdexcept>
namespace ra2::recovered::b1029::ui {
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
template<class T>inline unsigned address(T p){static_assert(sizeof(void*)==4u);return unsigned(reinterpret_cast<std::uintptr_t>(p));}
inline bool preview(const Case&c){return c.root==0x278120u||c.root==0x279440u;}
inline unsigned command(const Case&c){if(c.root==0xcf7e0u){constexpr unsigned t[]={0x52cu,0x52du,0x686u};return t[c.n%3u];}if(c.root==0x33be50u){constexpr unsigned t[]={0x629u,0x66cu,0x6dfu,0x6e0u,0x71eu};return t[c.n%5u];}if(c.root==0x1749c0u)return 0x5c0u;return combo_ui::combo_id(combo_ui::ordinal(c));}
inline unsigned wparam(const Case&c){const unsigned id=command(c);return id|((c.root==0xcf7e0u&&id!=0x686u?0u:(c.n*701u)&65535u)<<16u);}
inline unsigned context_offset(const Case&c){return 0x8000u+((c.n*73u)&0xffcu);}
inline constexpr unsigned button_ids[]={0x629,0x66c,0x6df,0x6e0,0x71e,0x52c,0x52d,0x686,0x5c0};
inline unsigned button_index(unsigned id){for(unsigned k=0;k<std::size(button_ids);++k)if(button_ids[k]==id)return k;throw std::domain_error("1029 actual fixture button ID");}
inline unsigned initial_check(const Case&c,unsigned id){unsigned v=(c.n+id)&1u;if(c.root!=0x33be50u)return v;const unsigned cmd=command(c),bit=(c.n/5u)%2u;if(cmd==0x629u||cmd==0x66cu){if(id==cmd)return bit;if(id==(cmd==0x629u?0x66cu:0x629u))return 1u;}if(cmd==0x6dfu||cmd==0x6e0u){if(id==cmd)return 0u;if(id==(cmd==0x6dfu?0x6e0u:0x6dfu))return bit;}if(cmd==0x71eu&&id==cmd)return (c.n/5u)%3u;return v;}
inline unsigned final_check(const Case&c,unsigned id){unsigned v=initial_check(c,id);if(c.root!=0x33be50u)return v;const unsigned cmd=command(c);if(cmd==0x629u||cmd==0x66cu){const unsigned other=cmd==0x629u?0x66cu:0x629u;if(initial_check(c,cmd)==1u&&id==other)return 0u;}if(cmd==0x6dfu||cmd==0x6e0u){const unsigned other=cmd==0x6dfu?0x6e0u:0x6dfu;if(initial_check(c,other)){if(id==other)return 0u;}else if(id==cmd)return 1u;}return v;}
enum class Kind:unsigned{user=1,send,send_dialog,checked,check};
struct Event{Kind kind{};unsigned hwnd=0,id=0,message=0,w=0,l=0,result=0;bool operator==(const Event&o)const{return kind==o.kind&&hwnd==o.hwnd&&id==o.id&&message==o.message&&w==o.w&&l==o.l&&result==o.result;}};
class Windows;
inline Windows*active=nullptr;inline std::vector<Event>events;
inline LONG WINAPI user(HWND,int);inline LRESULT WINAPI send(HWND,UINT,WPARAM,LPARAM);inline LRESULT WINAPI send_dialog(HWND,int,UINT,WPARAM,LPARAM);inline UINT WINAPI checked(HWND,int);inline BOOL WINAPI check(HWND,int,UINT);
class Windows {
 HWND dialog_{};std::array<HWND,9>buttons_{};std::array<LONG,9>procedures_{},styles_{},exstyles_{};std::array<RECT,9>rects_{};
 LONG dialog_proc_=0,dialog_style_=0,dialog_exstyle_=0;DWORD class_proc_=0;RECT dialog_rect_{};
 std::array<unsigned char,DLGWINDOWEXTRA>extra_{};Case c_{};unsigned context_=0,set_result_=0,check_result_=0;
 std::array<unsigned char,DLGWINDOWEXTRA>extra()const{std::array<unsigned char,DLGWINDOWEXTRA>v{};for(unsigned k=0;k+4u<=v.size();k+=4u){const LONG n=::GetWindowLongA(dialog_,int(k));std::memcpy(v.data()+k,&n,4u);}const WORD tail=::GetWindowWord(dialog_,DLGWINDOWEXTRA-2);std::memcpy(v.data()+DLGWINDOWEXTRA-2,&tail,2u);return v;}
 public:
 explicit Windows(const Case&c):c_(c){alignas(DWORD)std::array<WORD,12>t{};const DWORD style=WS_POPUP|DS_MODALFRAME;std::memcpy(t.data(),&style,4u);t[7]=600u;t[8]=420u;dialog_=::CreateDialogIndirectParamA(GetModuleHandleW(nullptr),reinterpret_cast<const DLGTEMPLATE*>(t.data()),nullptr,nullptr,0);need(dialog_&&!IsWindowVisible(dialog_),"1029 actual default system dialog");dialog_proc_=::GetWindowLongA(dialog_,GWL_WNDPROC);class_proc_=::GetClassLongA(dialog_,GCL_WNDPROC);dialog_style_=::GetWindowLongA(dialog_,GWL_STYLE);dialog_exstyle_=::GetWindowLongA(dialog_,GWL_EXSTYLE);need(dialog_proc_&&class_proc_&&GetClassLongA(dialog_,GCW_ATOM)==32770u&&GetClassLongA(dialog_,GCL_CBWNDEXTRA)>=DLGWINDOWEXTRA&&GetWindowLongA(dialog_,DWL_DLGPROC)==0&&GetWindowRect(dialog_,&dialog_rect_),"1029 authentic unmodified system dialog procedures/geometry");
  for(unsigned k=0;k<(preview(c_)?0u:unsigned(buttons_.size()));++k){buttons_[k]=::CreateWindowExA(0,"BUTTON","1029 check",WS_CHILD|(button_ids[k]==0x71eu?BS_3STATE:BS_CHECKBOX),450,int(25u*k),100,22,dialog_,reinterpret_cast<HMENU>(std::uintptr_t(button_ids[k])),GetModuleHandleW(nullptr),nullptr);need(buttons_[k]&&GetDlgItem(dialog_,int(button_ids[k]))==buttons_[k],"1029 actual standard buttons");procedures_[k]=GetWindowLongA(buttons_[k],GWL_WNDPROC);styles_[k]=GetWindowLongA(buttons_[k],GWL_STYLE);exstyles_[k]=GetWindowLongA(buttons_[k],GWL_EXSTYLE);need(procedures_[k]&&GetWindowRect(buttons_[k],&rects_[k]),"1029 button procedure/geometry");}}
 ~Windows(){if(active==this)active=nullptr;if(dialog_)DestroyWindow(dialog_);}Windows(const Windows&)=delete;
 HWND dialog()const{return dialog_;}HWND button(unsigned id)const{return buttons_[button_index(id)];}unsigned context()const{return context_;}
 void reset(const Case&c,unsigned context){need(!active,"1029 reset outside observations");c_=c;context_=context;SetLastError(ERROR_SUCCESS);const LONG prior=SetWindowLongA(dialog_,8,LONG(context));need(prior!=0||GetLastError()==ERROR_SUCCESS,"1029 successful actual DWL_USER assignment");need(unsigned(GetWindowLongA(dialog_,8))==context,"1029 live actual context readback");
  // Probe every non-data BOOL/LRESULT against the same genuine fixture, then
  // restore all state before either candidate. No assumed API success integer.
  if(!preview(c_)){
  const unsigned cmd=command(c_),other=cmd==0x629u?0x66cu:0x629u;set_result_=unsigned(::SendDlgItemMessageA(dialog_,int(other),BM_SETCHECK,BST_UNCHECKED,0));const unsigned radio_other=cmd==0x6dfu?0x6e0u:0x6dfu;const bool radio=cmd==0x6dfu||cmd==0x6e0u;const unsigned check_id=radio?(initial_check(c_,radio_other)?radio_other:cmd):0x629u,check_value=radio&&!initial_check(c_,radio_other)?BST_CHECKED:BST_UNCHECKED;check_result_=unsigned(::CheckDlgButton(dialog_,int(check_id),check_value));need(check_result_!=0u,"1029 successful real CheckDlgButton probe with exact target/value");
  for(unsigned k=0;k<(preview(c_)?0u:unsigned(buttons_.size()));++k){::SendMessageA(buttons_[k],BM_SETCHECK,initial_check(c_,button_ids[k]),0);::ValidateRect(buttons_[k],nullptr);}}
  ::ValidateRect(dialog_,nullptr);extra_=extra();verify(false);}
 void verify(bool changed)const{
  // Enumerate direct children using genuine USER32 links: prove both the exact
  // family and uniqueness, rather than relying on ambiguous GetDlgItem lookup.
  std::vector<unsigned>actual_ids,expected_ids;for(HWND h=::GetWindow(dialog_,GW_CHILD);h;h=::GetWindow(h,GW_HWNDNEXT)){need(::GetParent(h)==dialog_,"1029 direct-child ownership");actual_ids.push_back(unsigned(::GetDlgCtrlID(h)));}
  if(preview(c_)){for(unsigned k=0;k<8u;++k){expected_ids.push_back(combo_ui::combo_id(k));expected_ids.push_back(0x6dau+k);}}else expected_ids.assign(std::begin(button_ids),std::end(button_ids));
  std::sort(actual_ids.begin(),actual_ids.end());std::sort(expected_ids.begin(),expected_ids.end());need(actual_ids==expected_ids&&std::adjacent_find(actual_ids.begin(),actual_ids.end())==actual_ids.end(),"1029 exact root-specific direct-child family and unique original IDs");
  char name[32]{};need(IsWindow(dialog_)&&!IsWindowVisible(dialog_)&&GetClassNameA(dialog_,name,32)>0&&std::strcmp(name,"#32770")==0&&GetWindowLongA(dialog_,GWL_WNDPROC)==dialog_proc_&&GetClassLongA(dialog_,GCL_WNDPROC)==class_proc_&&GetClassLongA(dialog_,GCW_ATOM)==32770u&&GetWindowLongA(dialog_,DWL_DLGPROC)==0&&extra()==extra_&&GetWindowLongA(dialog_,GWL_STYLE)==dialog_style_&&GetWindowLongA(dialog_,GWL_EXSTYLE)==dialog_exstyle_,"1029 complete preserved real dialog identity/styles/30 extra bytes");RECT rect{};need(GetWindowRect(dialog_,&rect)&&std::memcmp(&rect,&dialog_rect_,sizeof(rect))==0,"1029 dialog geometry preserved");for(unsigned k=0;k<(preview(c_)?0u:unsigned(buttons_.size()));++k){const HWND h=buttons_[k];char cls[32]{},title[32]{};need(IsWindow(h)&&!IsWindowVisible(h)&&GetParent(h)==dialog_&&GetDlgItem(dialog_,int(button_ids[k]))==h&&GetDlgCtrlID(h)==int(button_ids[k])&&GetClassNameA(h,cls,32)>0&&lstrcmpiA(cls,"BUTTON")==0&&GetWindowTextA(h,title,32)==10&&std::strcmp(title,"1029 check")==0&&GetWindowLongA(h,GWL_WNDPROC)==procedures_[k]&&GetWindowLongA(h,GWL_STYLE)==styles_[k]&&GetWindowLongA(h,GWL_EXSTYLE)==exstyles_[k],"1029 full real button identity/unchanged procedure/styles/text");need(GetWindowRect(h,&rect)&&std::memcmp(&rect,&rects_[k],sizeof(rect))==0&&unsigned(::SendMessageA(h,BM_GETCHECK,0,0))==(changed?final_check(c_,button_ids[k]):initial_check(c_,button_ids[k])),"1029 every actual button geometry/independent final checked state");}}
 std::vector<Event>expected()const{std::vector<Event>v;const auto add=[&](Kind k,unsigned hwnd,unsigned id,unsigned msg,unsigned w,unsigned l,unsigned result){v.push_back({k,hwnd,id,msg,w,l,result});};add(Kind::user,address(dialog_),8u,0,0,0,context_);if(c_.root!=0x33be50u)return v;const unsigned cmd=command(c_);if(cmd==0x629u||cmd==0x66cu){add(Kind::send_dialog,address(dialog_),cmd,BM_GETCHECK,0,0,initial_check(c_,cmd));if(initial_check(c_,cmd)==1u)add(Kind::send_dialog,address(dialog_),cmd==0x629u?0x66cu:0x629u,BM_SETCHECK,0,0,set_result_);}else if(cmd==0x6dfu||cmd==0x6e0u){const unsigned other=cmd==0x6dfu?0x6e0u:0x6dfu;add(Kind::checked,address(dialog_),other,0,0,0,initial_check(c_,other));add(Kind::check,address(dialog_),initial_check(c_,other)?other:cmd,0,initial_check(c_,other)?0u:1u,0,check_result_);}else add(Kind::send,address(button(cmd)),0,BM_GETCHECK,0,0,initial_check(c_,cmd));return v;}
 void begin(){need(!active&&context_,"1029 exclusive live dialog observer");events.clear();events.reserve(8);active=this;}
 void finish(){need(active==this,"1029 matching observer");active=nullptr;need(events==expected(),"1029 exact independent API order/arguments/full genuine results");verify(true);}
 bool preview_route()const{return preview(c_);}
};
inline void observed(){need(active,"1029 API inside active real provider");}
inline LONG WINAPI user(HWND h,int n){observed();const auto r=::GetWindowLongA(h,n);const auto err=GetLastError();events.push_back({Kind::user,address(h),unsigned(n),0,0,0,unsigned(r)});SetLastError(err);return r;}
inline LRESULT WINAPI send(HWND h,UINT msg,WPARAM w,LPARAM l){observed();const auto r=::SendMessageA(h,msg,w,l);const auto err=GetLastError();events.push_back({Kind::send,address(h),0,unsigned(msg),unsigned(w),unsigned(l),unsigned(r)});SetLastError(err);return r;}
inline LRESULT WINAPI send_dialog(HWND h,int id,UINT msg,WPARAM w,LPARAM l){observed();if(active->preview_route())return combo_ui::send(h,id,msg,w,l);const auto r=::SendDlgItemMessageA(h,id,msg,w,l);const auto err=GetLastError();events.push_back({Kind::send_dialog,address(h),unsigned(id),unsigned(msg),unsigned(w),unsigned(l),unsigned(r)});SetLastError(err);return r;}
inline UINT WINAPI checked(HWND h,int id){observed();const auto r=::IsDlgButtonChecked(h,id);const auto err=GetLastError();events.push_back({Kind::checked,address(h),unsigned(id),0,0,0,unsigned(r)});SetLastError(err);return r;}
inline BOOL WINAPI check(HWND h,int id,UINT value){observed();const auto r=::CheckDlgButton(h,id,value);const auto err=GetLastError();events.push_back({Kind::check,address(h),unsigned(id),0,unsigned(value),0,unsigned(r)});SetLastError(err);return r;}
}
