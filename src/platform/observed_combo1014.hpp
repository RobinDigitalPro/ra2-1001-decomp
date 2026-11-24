#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::combo1014 {
inline void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
class Combo {inline static Combo*active=nullptr;HWND parent{};std::array<HWND,21>children{};std::array<LONG_PTR,21>procedures{};unsigned seed,count=0;
public:
static unsigned configured(unsigned n,unsigned k){return 0x105a0000u+(n%251u)*16u+k;}
static unsigned id(unsigned k){constexpr unsigned mid[]{0x510,0x513,0x51e,0x514,0x51f,0x520,0x521};return k%3==0?0x412+k/3:k%3==1?mid[k/3]:0x522+k/3;}
static unsigned selected(unsigned n,unsigned k){return (n+k)%4u;}
static unsigned selected_data(unsigned n,unsigned k){if(k%3==0){unsigned category=(n+k/3)%6u;return category<5?configured(n,category):0x205a0000u+(n%251u)*16u+k;}return 0x35410000u+(n%251u)*128u+k;}
static unsigned item(unsigned n,unsigned k,unsigned j){return j==selected(n,k)?selected_data(n,k):0x45410000u+(n%251u)*512u+16*k+j;}
explicit Combo(unsigned n):seed(n){need(!active,"1014 no active observed call");parent=CreateWindowExA(0,"STATIC","",WS_OVERLAPPED,0,0,64,64,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(parent,"1014 genuine hidden parent");for(unsigned k=0;k<21;++k){children[k]=CreateWindowExA(0,"COMBOBOX","",WS_CHILD|CBS_DROPDOWNLIST,0,0,32,32,parent,reinterpret_cast<HMENU>(std::uintptr_t(id(k))),GetModuleHandleW(nullptr),nullptr);need(children[k],"1014 genuine standard ComboBox");procedures[k]=GetWindowLongPtrA(children[k],GWLP_WNDPROC);for(unsigned j=0;j<4;++j){need(SendMessageA(children[k],CB_ADDSTRING,0,reinterpret_cast<LPARAM>("entry"))==j,"1014 insert actual item");need(SendMessageA(children[k],CB_SETITEMDATA,j,item(n,k,j))!=CB_ERR,"1014 actual item datum");}need(SendMessageA(children[k],CB_SETCURSEL,selected(n,k),0)==selected(n,k),"1014 actual selected item");}verify();}
~Combo(){if(active==this)active=nullptr;if(parent)DestroyWindow(parent);}
unsigned handle()const{return unsigned(reinterpret_cast<std::uintptr_t>(parent));}
void verify()const{need(IsWindow(parent)&&!IsWindowVisible(parent),"1014 hidden parent lifetime");for(unsigned k=0;k<21;++k){char cls[32]{};need(GetClassNameA(children[k],cls,32)>0&&lstrcmpiA(cls,"COMBOBOX")==0,"1014 actual standard class");need(IsWindow(children[k])&&!IsWindowVisible(children[k])&&GetDlgItem(parent,id(k))==children[k]&&GetWindowLongPtrA(children[k],GWLP_WNDPROC)==procedures[k],"1014 exact hidden child and unchanged standard procedure");need(SendMessageA(children[k],CB_GETCOUNT,0,0)==4&&SendMessageA(children[k],CB_GETCURSEL,0,0)==selected(seed,k),"1014 unchanged count/selection");for(unsigned j=0;j<4;++j)need(unsigned(SendMessageA(children[k],CB_GETITEMDATA,j,0))==item(seed,k,j),"1014 every real item unchanged");}}
void begin(){need(!active,"1014 observer exclusive");active=this;count=0;}void finish(){need(active==this&&count==42,"1014 exactly42 actual messages");active=nullptr;verify();}
static LRESULT WINAPI send(HWND h,int child,UINT message,WPARAM w,LPARAM l){need(active&&active->count<42,"1014 observed real call");auto&c=*active;unsigned call=c.count++,k=call/2;need(h==c.parent&&unsigned(child)==id(k)&&l==0,"1014 exact real handle/id/lparam");need(call%2?(message==CB_GETITEMDATA&&w==selected(c.seed,k)):(message==CB_GETCURSEL&&w==0),"1014 exact message order/input");auto result=::SendDlgItemMessageA(h,child,message,w,l);need(unsigned(result)==(call%2?selected_data(c.seed,k):selected(c.seed,k)),"1014 actual return equals independent prepared control");return result;}
template<class M,class I>void bind(M&m,I&i){m.w32(0x785484,unsigned(reinterpret_cast<std::uintptr_t>(&send)));i.cx=handle();}
};}
