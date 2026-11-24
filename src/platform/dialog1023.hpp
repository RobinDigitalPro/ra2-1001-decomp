#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>
namespace ra2::recovered::b1023::ui {
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
template<class T>inline unsigned address(T p){static_assert(sizeof(void*)==4);return unsigned(reinterpret_cast<std::uintptr_t>(p));}
enum class Kind:unsigned{stock=1,user,control};
struct Event{Kind kind{};unsigned object=0,index=0,result=0;bool operator==(const Event&o)const{return kind==o.kind&&object==o.object&&index==o.index&&result==o.result;}};
class Windows;
inline Windows*active=nullptr;inline std::vector<Event>events;
inline HGDIOBJ WINAPI stock(int);
inline LONG WINAPI user(HWND,int);
inline int WINAPI control(HWND);
class Windows {
 HWND dialog_{},button_{};HDC dc_{};HGDIOBJ brush_{};
 LONG dialog_proc_=0,button_proc_=0,dialog_style_=0,button_style_=0;DWORD class_proc_=0;
 std::array<unsigned char,DLGWINDOWEXTRA>extra_{};LOGBRUSH brush_data_{};
 std::array<unsigned,9>dc_state_{};RECT dialog_rect_{},button_rect_{};
 unsigned context_=0,root_=0;
 std::array<unsigned char,DLGWINDOWEXTRA>extra()const{std::array<unsigned char,DLGWINDOWEXTRA>v{};for(unsigned k=0;k+4u<=v.size();k+=4u){const LONG n=GetWindowLongA(dialog_,int(k));std::memcpy(v.data()+k,&n,4u);}if(v.size()%4u){const WORD n=GetWindowWord(dialog_,int(v.size()-2u));std::memcpy(v.data()+v.size()-2u,&n,2u);}return v;}
 std::array<unsigned,9>dc_state()const{return {unsigned(GetMapMode(dc_)),GetTextColor(dc_),GetBkColor(dc_),GetTextAlign(dc_),unsigned(GetBkMode(dc_)),address(GetCurrentObject(dc_,OBJ_BRUSH)),address(GetCurrentObject(dc_,OBJ_PEN)),address(GetCurrentObject(dc_,OBJ_FONT)),address(GetCurrentObject(dc_,OBJ_BITMAP))};}
 public:
 Windows(){
  // Optional NULL DLGPROC: genuine USER32 default dialog procedure only.
  // Standard DLGTEMPLATE header is18 bytes, followed by three empty WORD arrays.
  alignas(DWORD) std::array<WORD,12>t{};const DWORD style=WS_POPUP|DS_MODALFRAME;std::memcpy(t.data(),&style,4u);t[7]=120u;t[8]=80u;
  dialog_=CreateDialogIndirectParamA(GetModuleHandleW(nullptr),reinterpret_cast<const DLGTEMPLATE*>(t.data()),nullptr,nullptr,0);
  need(dialog_&&!IsWindowVisible(dialog_),"1023 genuine hidden default modeless dialog");
  button_=CreateWindowExA(0,"BUTTON","command423",WS_CHILD|BS_PUSHBUTTON,4,4,80,20,dialog_,reinterpret_cast<HMENU>(std::uintptr_t(0x423u)),GetModuleHandleW(nullptr),nullptr);
  need(button_&&GetDlgItem(dialog_,0x423)==button_&&GetDlgCtrlID(button_)==0x423,"1023 genuine BUTTON423");
  dialog_proc_=GetWindowLongA(dialog_,GWL_WNDPROC);button_proc_=GetWindowLongA(button_,GWL_WNDPROC);class_proc_=GetClassLongA(dialog_,GCL_WNDPROC);
  need(dialog_proc_&&button_proc_&&class_proc_&&GetClassLongA(dialog_,GCW_ATOM)==32770u&&GetClassLongA(dialog_,GCL_CBWNDEXTRA)>=DLGWINDOWEXTRA&&GetWindowLongA(dialog_,DWL_DLGPROC)==0,"1023 system32770 authentic unchanged procedure and no app DLGPROC");
  dialog_style_=GetWindowLongA(dialog_,GWL_STYLE);button_style_=GetWindowLongA(button_,GWL_STYLE);
  need(GetWindowRect(dialog_,&dialog_rect_)&&GetWindowRect(button_,&button_rect_),"1023 real window geometry");
  dc_=CreateCompatibleDC(nullptr);need(dc_,"1023 genuine owned memory DC");dc_state_=dc_state();
  brush_=GetStockObject(BLACK_BRUSH);need(brush_&&GetObjectType(brush_)==OBJ_BRUSH&&GetObjectA(brush_,sizeof(brush_data_),&brush_data_)==sizeof(brush_data_)&&brush_data_.lbStyle==BS_SOLID&&brush_data_.lbColor==RGB(0,0,0),"1023 genuine borrowed BLACK_BRUSH full LOGBRUSH");
 }
 ~Windows(){if(active==this)active=nullptr;if(dc_)DeleteDC(dc_);if(dialog_)DestroyWindow(dialog_);/* borrowed stock brush is never deleted */}
 Windows(const Windows&)=delete;
 HWND dialog()const{return dialog_;}HWND button()const{return button_;}HDC dc()const{return dc_;}unsigned brush()const{return address(brush_);}unsigned context()const{return context_;}
 void reset(unsigned context,unsigned root){need(!active,"1023 setup outside observations");context_=context;root_=root;SetLastError(ERROR_SUCCESS);const LONG prior=SetWindowLongA(dialog_,8,LONG(context));need(prior!=0||GetLastError()==ERROR_SUCCESS,"1023 genuine DWL_USER assignment");need(unsigned(GetWindowLongA(dialog_,8))==context,"1023 actual dialog userdata roundtrip");extra_=extra();verify();}
 void verify()const{char a[40]{},b[40]{};need(IsWindow(dialog_)&&IsWindow(button_)&&!IsWindowVisible(dialog_)&&!IsWindowVisible(button_)&&GetClassNameA(dialog_,a,40)>0&&std::strcmp(a,"#32770")==0&&GetClassNameA(button_,b,40)>0&&lstrcmpiA(b,"BUTTON")==0,"1023 complete actual standard window identity/lifetime");need(GetWindowLongA(dialog_,GWL_WNDPROC)==dialog_proc_&&GetWindowLongA(button_,GWL_WNDPROC)==button_proc_&&GetClassLongA(dialog_,GCL_WNDPROC)==class_proc_&&GetClassLongA(dialog_,GCW_ATOM)==32770u&&GetWindowLongA(dialog_,DWL_DLGPROC)==0,"1023 no subclass or fabricated dialog callback");need(GetParent(button_)==dialog_&&GetDlgItem(dialog_,0x423)==button_&&GetDlgCtrlID(button_)==0x423&&GetWindowLongA(dialog_,GWL_STYLE)==dialog_style_&&GetWindowLongA(button_,GWL_STYLE)==button_style_&&extra()==extra_,"1023 exact unchanged dialog extra bytes/controls/styles");RECT a_rect{},b_rect{};need(GetWindowRect(dialog_,&a_rect)&&GetWindowRect(button_,&b_rect)&&std::memcmp(&a_rect,&dialog_rect_,sizeof(RECT))==0&&std::memcmp(&b_rect,&button_rect_,sizeof(RECT))==0,"1023 unchanged actual geometry");char title[32]{};need(GetWindowTextA(button_,title,32)==10&&std::strcmp(title,"command423")==0,"1023 unchanged button title");LOGBRUSH now{};need(GetStockObject(BLACK_BRUSH)==brush_&&GetObjectType(brush_)==OBJ_BRUSH&&GetObjectA(brush_,sizeof(now),&now)==sizeof(now)&&std::memcmp(&now,&brush_data_,sizeof(now))==0&&dc_state()==dc_state_,"1023 same real stock brush/complete LOGBRUSH and preserved DC attributes");}
 void begin(){need(!active&&context_,"1023 exclusive live provider");verify();events.clear();events.reserve(4);active=this;}
 std::vector<Event>expected()const{if(root_==0x1f77c0u)return {{Kind::stock,0u,4u,brush()}};if(root_==0x232810u)return {{Kind::control,address(button_),0u,0x423u},{Kind::user,address(dialog_),8u,context_}};return {{Kind::user,address(dialog_),8u,context_}};}
 void finish(){need(active==this,"1023 matching provider end");active=nullptr;need(events==expected(),"1023 independent exact API event order/arguments/full actual results");verify();}
};
inline void observed(){need(active,"1023 API only within candidate observation");}
inline HGDIOBJ WINAPI stock(int n){observed();const auto r=::GetStockObject(n);const auto error=GetLastError();events.push_back({Kind::stock,0u,unsigned(n),address(r)});SetLastError(error);return r;}
inline LONG WINAPI user(HWND w,int n){observed();const auto r=::GetWindowLongA(w,n);const auto error=GetLastError();events.push_back({Kind::user,address(w),unsigned(n),unsigned(r)});SetLastError(error);return r;}
inline int WINAPI control(HWND w){observed();const auto r=::GetDlgCtrlID(w);const auto error=GetLastError();events.push_back({Kind::control,address(w),0u,unsigned(r)});SetLastError(error);return r;}
}
