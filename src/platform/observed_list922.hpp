#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::list922{
class List{inline static List*active_{};HWND parent_{},child_{};unsigned seed_,count_,calls_=0;static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
public:
static unsigned count(unsigned n){return 1+n%8;}static unsigned target(unsigned n){return 0x12340000u+n*257u;}
static unsigned item(unsigned n,unsigned k){const unsigned c=count(n);bool match=n%3==0?k==((n/8)%c):n%3==1?(k%2==n%2):false;return match?target(n):target(n)+1+k;}
unsigned chosen()const{unsigned v=0;for(unsigned k=0;k<count_;++k)if(item(seed_,k)==target(seed_))v=k;return v;}
explicit List(unsigned n):seed_(n),count_(count(n)){parent_=CreateWindowExA(0,"STATIC","",WS_OVERLAPPED,0,0,64,256,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(parent_!=nullptr,"922 hiddenparent");child_=CreateWindowExA(0,"LISTBOX","",WS_CHILD,0,0,32,256,parent_,reinterpret_cast<HMENU>(0x553),GetModuleHandleW(nullptr),nullptr);need(child_!=nullptr,"922 hiddenlist");auto rowheight=SendMessageA(child_,LB_GETITEMHEIGHT,0,0);need(rowheight>0&&SetWindowPos(child_,nullptr,0,0,64,int(rowheight),SWP_NOACTIVATE|SWP_NOZORDER),"922 onevisible row geometry");for(unsigned k=0;k<count_;++k){need(SendMessageA(child_,LB_ADDSTRING,0,reinterpret_cast<LPARAM>("entry"))==k,"922 additem");need(SendMessageA(child_,LB_SETITEMDATA,k,LPARAM(item(n,k)))!=LB_ERR,"922 setdata");}}
~List(){if(active_==this)active_=nullptr;if(parent_)DestroyWindow(parent_);}
unsigned handle()const{return unsigned(reinterpret_cast<std::uintptr_t>(parent_));}
void verify()const{need(IsWindow(child_)&&!IsWindowVisible(parent_)&&!IsWindowVisible(child_),"922 hiddenownedcontrols");need(GetDlgItem(parent_,0x553)==child_&&SendMessageA(child_,LB_GETCOUNT,0,0)==count_,"922 controlidentity/count");need(SendMessageA(child_,LB_GETCURSEL,0,0)==chosen()&&SendMessageA(child_,LB_GETTOPINDEX,0,0)==chosen(),"922 selection/top row");for(unsigned k=0;k<count_;++k)need(unsigned(SendMessageA(child_,LB_GETITEMDATA,k,0))==item(seed_,k),"922 itemdatapreserved");}
void begin(){need(!active_,"922 activeobserver");need(SendMessageA(child_,LB_SETCURSEL,count_-1,0)!=LB_ERR,"922 resetselection");calls_=0;active_=this;}
void finish(){need(active_==this&&calls_==count_+3,"922 exactmessagecount");active_=nullptr;verify();}
static LRESULT WINAPI send(HWND h,int id,UINT msg,WPARAM w,LPARAM l){auto*a=active_;need(a&&h==a->parent_&&id==0x553&&l==0,"922 messagehandle/id/lparam");unsigned k=a->calls_++;need((k==0&&msg==LB_GETCOUNT&&w==0)||(k>=1&&k<=a->count_&&msg==LB_GETITEMDATA&&w==k-1)||(k==a->count_+1&&msg==LB_SETCURSEL&&w==a->chosen())||(k==a->count_+2&&msg==LB_SETTOPINDEX&&w==a->chosen()),"922 messageorder/arguments");auto result=::SendDlgItemMessageA(h,id,msg,w,l);if(k==0)need(result==a->count_,"922 actualcount");else if(k<=a->count_)need(unsigned(result)==item(a->seed_,k-1),"922 actualdata");else if(k==a->count_+1)need(unsigned(result)==a->chosen(),"922 actualselection success");else need(result==0,"922 actualtoprow success");return result;}
template<class M>void bind(M&m){m.w32(0x785484,unsigned(reinterpret_cast<std::uintptr_t>(&send)));}
};}
