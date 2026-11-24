#pragma once
#define NOMINMAX
#include <windows.h>
#include "platform/x87_state.hpp"
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::controls1632 {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
struct Fs {U head{};std::uint16_t selector{};bool operator==(const Fs&o)const{return head==o.head&&selector==o.selector;}};
inline Fs fs(){Fs v;asm volatile("movl %%fs:0,%0;movw %%fs,%1":"=r"(v.head),"=r"(v.selector));return v;}
struct Event {U kind{},hwnd{},id{},message{},w{},l{},result{},error_before{},error_after{},callbacks_before{},callbacks_after{};fp::Image before{},after{};Fs fs_before{},fs_after{};};
struct Result {U count{},selector_count{},callbacks{};std::array<Event,32>events{};};
class Trace {
 inline static Trace*active_=nullptr;
 HWND parent_{};std::array<HWND,4>controls_{};std::array<LONG_PTR,4>procedures_{};volatile const U*callbacks_{};Result result_{};
 static void need(bool v,const char*s){if(!v)throw std::runtime_error(s);}
 static Trace&get_active(){need(active_,"1632 active owned-controls trace");return *active_;}
 U index(HWND h)const{for(U k=0;k<4;++k)if(h==controls_[k])return k;throw std::runtime_error("1632 unowned target HWND");}
 Event&enter(U kind,HWND h,U id,U msg,U w,U l){need(result_.count<result_.events.size()&&*callbacks_==0,"1632 bounded trace and ZERO parent callbacks");auto&e=result_.events[result_.count++];e={};e.kind=kind;e.hwnd=ptr(h);e.id=id;e.message=msg;e.w=w;e.l=l;e.callbacks_before=*callbacks_;e.error_before=::GetLastError();e.fs_before=fs();e.before=fp::capture_host();return e;}
 void leave(Event&e,U result){e.after=fp::capture_host();e.error_after=::GetLastError();e.fs_after=fs();e.result=result;e.callbacks_after=*callbacks_;need(e.callbacks_after==0&&e.fs_before==e.fs_after,"1632 ZERO parent callbacks/fullFS preservation");}
public:
 // The fixture owns this exact original258 template instance and must prove
 // no GAME subclass was installed; stored procedures are unchanged witnesses.
 Trace(HWND parent,const std::array<HWND,4>&controls,volatile const U*parent_callbacks):parent_(parent),controls_(controls),callbacks_(parent_callbacks){need(parent_&&callbacks_,"1632 owned parent/counter");for(U k=0;k<4;++k)procedures_[k]=GetWindowLongPtrA(controls_[k],GWLP_WNDPROC);}
 HWND parent()const{return parent_;}HWND control(U k)const{need(k<4,"1632 exact four controls");return controls_[k];}
 void verify_owned()const{DWORD parent_pid=0;char parent_class[32]{};need(IsWindow(parent_)&&GetWindowThreadProcessId(parent_,&parent_pid)==GetCurrentThreadId()&&parent_pid==GetCurrentProcessId()&&GetClassNameA(parent_,parent_class,32)&&lstrcmpiA(parent_class,"#32770")==0,"1632 genuine owned same-thread dialog parent");constexpr U ids[]{0x51d,0x6e1,0x521,0x528};for(U k=0;k<4;++k){DWORD pid=0;char cls[32]{};need(IsWindow(controls_[k])&&GetParent(controls_[k])==parent_&&GetDlgCtrlID(controls_[k])==int(ids[k])&&GetWindowThreadProcessId(controls_[k],&pid)==GetCurrentThreadId()&&pid==GetCurrentProcessId(),"1632 genuine owned same-thread resource258 controls");need(GetClassNameA(controls_[k],cls,32)&&lstrcmpiA(cls,k==1?"STATIC":"COMBOBOX")==0&&GetWindowLongPtrA(controls_[k],GWLP_WNDPROC)==procedures_[k]&&procedures_[k],"1632 exact classes/unchanged genuine OS procedures");for(U j=0;j<k;++j)need(controls_[k]!=controls_[j],"1632 distinct controls");}}
 void begin(){need(!active_&&*callbacks_==0,"1632 exclusive trace and reset diagnostic counter outside target");verify_owned();for(auto h:controls_)need((U(GetWindowLongA(h,GWL_STYLE))&WS_VISIBLE)!=0,"1632 genuine initially visible child styles");need(!IsWindowEnabled(controls_[2])&&!IsWindowEnabled(controls_[3]),"1632 genuine disabled country/palette prestate");result_={};active_=this;}
 Result finish(){need(active_==this&&*callbacks_==0&&result_.selector_count>=1&&result_.selector_count<=4&&result_.count==result_.selector_count+15u,"1632 complete exact target API count/ZERO callbacks");active_=nullptr;result_.callbacks=*callbacks_;return result_;}
 const Result&observations()const{return result_;}
 static Trace&context(){return get_active();}
 static HWND WINAPI get(HWND parent,int id){auto&c=get_active();need(parent==c.parent_,"1632 exact GetDlgItem parent");constexpr U ids[]{0x51d,0x6e1,0x521,0x528};U k=4;for(U n=0;n<4;++n)if(U(id)==ids[n])k=n;need(k<4,"1632 exact GetDlgItem ID");auto&e=c.enter(1,parent,U(id),0,0,0);const HWND out=::GetDlgItem(parent,id);c.leave(e,ptr(out));need(out==c.controls_[k],"1632 actual control identity");return out;}
 static LRESULT WINAPI send_dialog(HWND parent,int id,UINT msg,WPARAM w,LPARAM l){auto&c=get_active();need(parent==c.parent_&&id==0x51d&&l==0&&((msg==CB_GETCOUNT||msg==CB_GETCURSEL)?w==0:msg==CB_GETITEMDATA&&U(w)<4u),"1632 exact real selector queries");auto&e=c.enter(2,parent,U(id),msg,U(w),U(l));const LRESULT out=::SendDlgItemMessageA(parent,id,msg,w,l);c.leave(e,U(out));if(msg==CB_GETCOUNT){need(out>=1&&out<=4,"1632 real nonempty selector");c.result_.selector_count=U(out);}return out;}
 static BOOL WINAPI enable(HWND h,BOOL value){auto&c=get_active();const U k=c.index(h);need((k==2||k==3)&&value==TRUE,"1632 exact real enable TRUE");auto&e=c.enter(3,h,0,0,U(value),0);const BOOL out=::EnableWindow(h,value);c.leave(e,U(out));return out;}
 static BOOL WINAPI show(HWND h,int command){auto&c=get_active();(void)c.index(h);need(command==SW_HIDE,"1632 exact hide on four owned controls");auto&e=c.enter(4,h,0,0,U(command),0);const BOOL out=::ShowWindow(h,command);c.leave(e,U(out));return out;}
 static void bind(ra2::recovered::global_b26::Memory&m){m.w32(0x78549c,U(reinterpret_cast<std::uintptr_t>(&get)));m.w32(0x785484,U(reinterpret_cast<std::uintptr_t>(&send_dialog)));m.w32(0x785490,U(reinterpret_cast<std::uintptr_t>(&enable)));m.w32(0x785498,U(reinterpret_cast<std::uintptr_t>(&show)));}
 ~Trace(){if(active_==this)active_=nullptr;}
};
}
