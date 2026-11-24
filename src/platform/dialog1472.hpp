#pragma once
#include "platform/listbox_reconnect1469.hpp"
namespace ra2::recovered::b1472::ui {
namespace base=ra2::recovered::b1469::ui;using U=base::U;using Memory=ra2::recovered::global_b26::Memory;using Adapter=ra2::recovered::b979::HeapAdapter;
using base::need;using base::ptr;using base::addr;using base::getdc;using base::send;using base::releasedc;
struct UserEvent{U hwnd=0,index=0,result=0,error=0;bool operator==(const UserEvent&o)const{return hwnd==o.hwnd&&index==o.index&&result==o.result&&error==o.error;}};
inline std::vector<UserEvent> user_events;
class Windows;inline Windows* active=nullptr;
inline LONG WINAPI getwindow(HWND h,int index){const LONG result=::GetWindowLongA(h,index);const DWORD error=GetLastError();user_events.push_back({ptr(h),U(index),U(result),error});SetLastError(error);return result;}
class Windows:public base::Windows{
 HWND command_{};bool dialog_mode_=false;LONG initial_user_=0;DWORD initial_user_error_=0;
public:
 explicit Windows(bool system_dialog=false):base::Windows(system_dialog),dialog_mode_(system_dialog){
  if(dialog_mode_){
   command_=CreateWindowExA(0,"BUTTON","",0x5001000bu,20,10,83,15,parent(),reinterpret_cast<HMENU>(std::uintptr_t(0x640)),GetModuleHandleW(nullptr),nullptr);
   need(command_,"1472 genuine ownerdraw BUTTON 0x640 creation");
   SetLastError(ERROR_SUCCESS);initial_user_=GetWindowLongA(parent(),8);initial_user_error_=GetLastError();
   need(initial_user_==0&&initial_user_error_==ERROR_SUCCESS,"1472 OS-initialized untouched DWL_USER zero/error0");
   verify_dialog_button();
  }
  verify_structure();
 }
 ~Windows(){if(active==this)active=nullptr;if(command_)DestroyWindow(command_);}
 HWND command_button()const{return command_;}bool has_dialog()const{return dialog_mode_;}LONG initial_user()const{return initial_user_;}DWORD initial_user_error()const{return initial_user_error_;}
 void verify_dialog_button()const{need(dialog_mode_&&command_&&IsWindow(parent())&&IsWindow(command_)&&!IsWindowVisible(parent())&&!IsWindowVisible(command_)&&GetParent(command_)==parent()&&GetDlgCtrlID(command_)==0x640,"1472 actual hidden child BUTTON 0x640 relationship/ID");char n[32]{};need(GetClassNameA(command_,n,32)>0&&lstrcmpiA(n,"BUTTON")==0&&DWORD(GetWindowLongA(command_,GWL_STYLE))==0x5001000bu,"1472 exact genuine BUTTON class and resource234 style");need(GetClassNameA(parent(),n,32)>0&&std::strcmp(n,"#32770")==0&&GetClassLongA(parent(),GCW_ATOM)==32770u&&GetClassLongA(parent(),GCL_CBWNDEXTRA)>=DLGWINDOWEXTRA&&GetWindowLongA(parent(),DWL_DLGPROC)==0,"1472 real default #32770 and dialog extra bytes");}
 void begin(Memory&m,Adapter&h,bool original){user_events.clear();base::Windows::begin(m,h,original);active=this;}
 void end(){if(active==this)active=nullptr;base::Windows::end();}
};
} // namespace ra2::recovered::b1472::ui

