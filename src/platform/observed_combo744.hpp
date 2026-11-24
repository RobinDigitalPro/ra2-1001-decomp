#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::combo744 {
// Own hidden standard controls. Every observed message is forwarded to User32.
class Combo {
 inline static Combo*active_{};
 HWND parent_{};std::array<HWND,3>child_{};unsigned root_,seed_,calls_{};
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
public:
 static unsigned configured(unsigned n,unsigned k){return 0x12340000u+0x100u*(1+k)+(n%251u);}
 static unsigned datum(unsigned root,unsigned n,unsigned k){
  if(root==0x278060)return k==2&&(n&1u)?n%3u:0x35120000u+0x100u*k+(n%251u)+3u;
  return k==2&&(n&1u)?0x69870000u+(n%251u):configured(n,k);
 }
 unsigned id(unsigned k)const{return root_==0x278060?0x51b+k:0x416+k;}
 unsigned selected(unsigned k)const{return (seed_+k)%4;}
 unsigned item(unsigned k,unsigned j)const{return j==selected(k)?datum(root_,seed_,k):0x45ac0000u+(k<<12)+(j<<8)+seed_%251;}
 Combo(unsigned n,unsigned root):root_(root),seed_(n){
  need(root==0x278060||root==0x1c4c60,"744 root");
  parent_=CreateWindowExA(0,"STATIC","",WS_OVERLAPPED,0,0,64,64,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(parent_,"744 hiddenparent");
  for(unsigned k=0;k<3;++k){child_[k]=CreateWindowExA(0,"COMBOBOX","",WS_CHILD|CBS_DROPDOWNLIST,0,0,32,32,parent_,reinterpret_cast<HMENU>(std::uintptr_t(id(k))),GetModuleHandleW(nullptr),nullptr);need(child_[k],"744 hiddencombo");for(unsigned j=0;j<4;++j){need(SendMessageA(child_[k],CB_ADDSTRING,0,reinterpret_cast<LPARAM>("entry"))==j,"744 additem");need(SendMessageA(child_[k],CB_SETITEMDATA,j,item(k,j))!=CB_ERR,"744 itemdata");}need(SendMessageA(child_[k],CB_SETCURSEL,selected(k),0)==selected(k),"744 selection");}verify();
 }
 ~Combo(){if(active_==this)active_=nullptr;if(parent_)DestroyWindow(parent_);}
 unsigned handle()const{return unsigned(reinterpret_cast<std::uintptr_t>(parent_));}
 void verify()const{need(IsWindow(parent_)&&!IsWindowVisible(parent_),"744 hiddenparentlive");for(unsigned k=0;k<3;++k){need(IsWindow(child_[k])&&!IsWindowVisible(child_[k])&&GetDlgItem(parent_,id(k))==child_[k],"744 hiddenchildidentity");need(SendMessageA(child_[k],CB_GETCOUNT,0,0)==4&&SendMessageA(child_[k],CB_GETCURSEL,0,0)==selected(k),"744 unchangedselection");for(unsigned j=0;j<4;++j)need(unsigned(SendMessageA(child_[k],CB_GETITEMDATA,j,0))==item(k,j),"744 unchangeditemdata");}}
 void begin(){need(!active_,"744 activeobserver");calls_=0;active_=this;}
 void finish(){need(active_==this&&calls_==6,"744 sixactualmessages");active_=nullptr;verify();}
 static LRESULT WINAPI send(HWND h,int id,UINT message,WPARAM w,LPARAM l){need(active_&&calls_ok(),"744 activecall");unsigned c=active_->calls_++,k=c/2;need(h==active_->parent_&&unsigned(id)==active_->id(k)&&l==0,"744 handle/id");need(c%2?(message==CB_GETITEMDATA&&w==active_->selected(k)):(message==CB_GETCURSEL&&w==0),"744 messageorder");auto v=::SendDlgItemMessageA(h,id,message,w,l);need(unsigned(v)==(c%2?datum(active_->root_,active_->seed_,k):active_->selected(k)),"744 genuineAPIresult");return v;}
 static bool calls_ok(){return active_->calls_<6;}
 template<class M,class I>void bind(M&m,I&i){m.w32(0x785484,unsigned(reinterpret_cast<std::uintptr_t>(&send)));if(root_==0x278060){m.w32(0xaa4904,handle());i.cx=5;}else{i.cx=handle();i.dx=5;}}
};
}
