#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::combo162 {
// Own hidden standard controls. Observation forwards both messages to the
// genuine User32 API; setup and state verification are outside target calls.
class Combo {
 inline static Combo* active_{};
 HWND parent_{},child_{};
 unsigned id_{},count_{},selected_{},seed_{},calls_{};
 static void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
public:
 static unsigned index(unsigned n){return n%8;}
 static unsigned id(unsigned n){return index(n)==0?0x6a2:0x521+index(n);}
 static unsigned item(unsigned n,unsigned k){return (0x9e3779b9u*(n+1))^(0x10204081u*(k+3));}
 explicit Combo(unsigned n):id_(id(n)),count_(1+(n/8)%8),selected_((n/64)%count_),seed_(n){
  static_assert(sizeof(void*)==4,"original x86 handles");
  parent_=CreateWindowExA(0,"STATIC","",WS_OVERLAPPED,0,0,64,64,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);
  need(parent_!=nullptr,"162hidden parent creation failed");
  child_=CreateWindowExA(0,"COMBOBOX","",WS_CHILD|CBS_DROPDOWNLIST,0,0,32,32,parent_,reinterpret_cast<HMENU>(std::uintptr_t(id_)),GetModuleHandleW(nullptr),nullptr);
  if(!child_){DestroyWindow(parent_);parent_=nullptr;throw std::runtime_error("162hidden combo creation failed");}
  for(unsigned k=0;k<count_;++k){need(SendMessageA(child_,CB_ADDSTRING,0,reinterpret_cast<LPARAM>("entry"))==k,"162actual combo insertion index");need(SendMessageA(child_,CB_SETITEMDATA,k,LPARAM(item(n,k)))!=CB_ERR,"162actual combo item data");}
  need(SendMessageA(child_,CB_SETCURSEL,selected_,0)==selected_,"162actual combo selection");
  verify();
 }
 ~Combo(){if(active_==this)active_=nullptr;if(parent_)DestroyWindow(parent_);}
 unsigned handle()const{return unsigned(reinterpret_cast<std::uintptr_t>(parent_));}
 unsigned value()const{return item(seed_,selected_);}
 void verify()const{
  need(IsWindow(parent_)&&IsWindow(child_)&&!IsWindowVisible(parent_)&&!IsWindowVisible(child_),"162owned controls must stay hidden and live");
  need(GetDlgItem(parent_,int(id_))==child_&&SendMessageA(child_,CB_GETCOUNT,0,0)==count_&&SendMessageA(child_,CB_GETCURSEL,0,0)==selected_,"162actual control geometry changed");
  for(unsigned k=0;k<count_;++k)need(unsigned(SendMessageA(child_,CB_GETITEMDATA,k,0))==item(seed_,k),"162actual item state changed");
 }
 void begin(){need(!active_,"162observer active");calls_=0;active_=this;}
 void finish(){need(active_==this&&calls_==2,"162exactly two actual control messages required");active_=nullptr;verify();}
 static LRESULT WINAPI send(HWND h,int id,UINT message,WPARAM w,LPARAM l){
  need(active_&&h==active_->parent_&&unsigned(id)==active_->id_&&l==0,"162message handle/id/lparam provenance");
  const auto call=active_->calls_++;
  need((call==0&&message==CB_GETCURSEL&&w==0)||(call==1&&message==CB_GETITEMDATA&&w==active_->selected_),"162message order/wparam provenance");
  const auto result=::SendDlgItemMessageA(h,id,message,w,l);
  need(unsigned(result)==(call==0?active_->selected_:active_->value()),"162actual OS result differs from prepared control state");return result;
 }
 template<class Memory>void bind(Memory&m){m.w32(0x785484,unsigned(reinterpret_cast<std::uintptr_t>(&send)));}
};
}
