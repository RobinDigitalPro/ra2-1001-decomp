#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b1480.hpp"
#include "platform/x87_state.hpp"
#include "platform/combo1430_resource.hpp"
#include <array>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cstdio>
namespace ra2::recovered::b1480::ui {
using U=unsigned;namespace fp=ra2::platform::x87;
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
template<class T>inline U addr(T p){return U(reinterpret_cast<std::uintptr_t>(p));}
inline U fs_head(){U x;asm volatile("movl %%fs:0,%0":"=r"(x));return x;}
inline U fs_selector(){unsigned short x;asm volatile("movw %%fs,%0":"=r"(x));return x;}
struct Event {U kind,h,message,w,l,result,provider;std::array<LONG,4> value{};fp::Image before{},after{};bool operator==(const Event&o)const{return kind==o.kind&&h==o.h&&message==o.message&&w==o.w&&l==o.l&&result==o.result&&provider==o.provider&&value==o.value&&fp::same_numeric(before,o.before)&&fp::same_numeric(after,o.after);}};
struct Message {U hwnd,message,w,l;bool operator==(const Message&o)const{return hwnd==o.hwnd&&message==o.message&&w==o.w&&l==o.l;}};
struct Installation {U hwnd,before,returned,installed;};
class Windows;inline Windows*active=nullptr;inline const char*phase="creation";
inline LRESULT WINAPI send(HWND,int,UINT,WPARAM,LPARAM);
inline BOOL WINAPI rect(HWND,LPRECT);inline BOOL WINAPI client(HWND,LPRECT);inline BOOL WINAPI screen(HWND,LPPOINT);inline BOOL WINAPI invalidate(HWND,const RECT*,BOOL);
inline LRESULT WINAPI call(WNDPROC,HWND,UINT,WPARAM,LPARAM);
class Windows {
 HWND outer_{},parent_{};std::array<HWND,4>child_{};std::array<WNDPROC,4>os_{};HHOOK hook_{};bool original_{},installed_{};Memory*memory_{};Heap*heap_{};
 std::vector<Event>events_;std::vector<Message>messages_;std::vector<Installation>installation_;std::vector<Message>parent_messages_;
 static bool initial_zero(U m){if(m==0x111||m==0x114||m==0x115||m==0x497||m==0x49b||m>0x49b)return false;if(m>=2&&m<=0x84)return original_low_zero[m-2];return true;}
 static INT_PTR CALLBACK parent_proc(HWND h,UINT m,WPARAM w,LPARAM l){if(!initial_zero(m))std::fprintf(stderr,"BUTTON1480_PARENT_REJECT phase=%s active=%u hwnd=%08x msg=%08x w=%08x l=%08x\n",phase,active?1u:0u,ptr(h),m,U(w),U(l));need(initial_zero(m),"1480 unclosed original5BA220 parent message");if(active)active->parent_messages_.push_back({ptr(h),m,U(w),U(l)});return 0;}
 static LRESULT CALLBACK hook(int code,WPARAM w,LPARAM l){if(code>=0&&active){const auto*p=reinterpret_cast<const CWPSTRUCT*>(l);active->messages_.push_back({ptr(p->hwnd),p->message,U(p->wParam),U(p->lParam)});}return CallNextHookEx(nullptr,code,w,l);}
 public:
 static constexpr std::array<U,4>ids{0x54d,0x3e8,0x69a,0x69d};static constexpr std::array<U,4>globals{0xa255f1,0xa25670,0xa255f3,0xa255f4};
 explicit Windows(const char*game){std::ifstream f(game,std::ios::binary);need(bool(f),"1480 actual original resource file");std::vector<unsigned char>b(resource_size);f.seekg(resource_offset);f.read(reinterpret_cast<char*>(b.data()),b.size());need(std::size_t(f.gcount())==b.size(),"1480 complete resource188");outer_=CreateWindowExA(0,"STATIC","1480 hidden owner",WS_OVERLAPPED,0,0,640,480,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);need(outer_!=nullptr,"1480 real outer HWND");parent_=CreateDialogIndirectParamA(GetModuleHandleA(nullptr),reinterpret_cast<const DLGTEMPLATE*>(b.data()),outer_,&parent_proc,0);need(parent_&&!IsWindowVisible(parent_),"1480 actual hidden resource188 parent");
  for(U k=0;k<4;++k){child_[k]=GetDlgItem(parent_,ids[k]);need(child_[k]!=nullptr,"1480 genuine resource Button");os_[k]=reinterpret_cast<WNDPROC>(GetWindowLongPtrA(child_[k],GWLP_WNDPROC));need(os_[k]!=nullptr,"1480 initial observed OSproc");}verify();
 }
 ~Windows(){phase="fixture_destroy";if(hook_)UnhookWindowsHookEx(hook_);if(installed_)for(U k=0;k<4;++k)SetWindowLongPtrA(child_[k],GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_[k]));if(active==this)active=nullptr;if(parent_){SetWindowLongPtrA(parent_,DWLP_DLGPROC,0);DestroyWindow(parent_);}if(outer_)DestroyWindow(outer_);}
 HWND parent()const{return parent_;}HWND child(U k)const{need(k<4,"1480 child index");return child_[k];}WNDPROC os(U k)const{return os_[k];}
 U index(HWND h)const{for(U k=0;k<4;++k)if(child_[k]==h)return k;throw std::domain_error("1480 unknown genuine child");}U index_id(U id)const{for(U k=0;k<4;++k)if(ids[k]==id)return k;throw std::domain_error("1480 unknown selected ID");}
 Memory&memory()const{need(memory_!=nullptr,"1480 active memory");return*memory_;}Heap&heap()const{need(heap_!=nullptr,"1480 actual heap");return*heap_;}bool original()const{return original_;}
 void record(Event e){events_.push_back(e);}const auto&events()const{return events_;}const auto&messages()const{return messages_;}const auto&installations()const{return installation_;}const auto&parent_messages()const{return parent_messages_;}
 void clear_events(){phase="observed_message";events_.clear();messages_.clear();parent_messages_.clear();}
 void bind(Memory&m){m.w32(0x785484,addr(&send));m.w32(0x785398,addr(&rect));m.w32(0x7854b8,addr(&client));m.w32(0x7854ac,addr(&screen));m.w32(0x785494,addr(&invalidate));m.w32(0x7854c0,addr(&call));}
 void begin(Memory&m,Heap&h,bool original){need(!active&&!hook_&&!installed_,"1480 exclusive active observer");memory_=&m;heap_=&h;original_=original;active=this;events_.reserve(64);messages_.reserve(32);parent_messages_.reserve(16);clear_events();installation_.clear();const auto target=original?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;
  for(U k=0;k<4;++k){const U before=U(GetWindowLongPtrA(child_[k],GWLP_WNDPROC));need(before==addr(os_[k]),"1480 actual stable OSproc before subclass");const auto old=SetWindowLongPtrA(child_[k],GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(target));need(old,"1480 real SetWindowLong return");os_[k]=reinterpret_cast<WNDPROC>(old);const U after=U(GetWindowLongPtrA(child_[k],GWLP_WNDPROC));need(after==addr(target),"1480 exact installed proc");installation_.push_back({ptr(child_[k]),before,U(old),after});
   U node=m.r32(m.r32(0xa5b1e8)+(ptr(child_[k])&127)*4),steps=0;while(node&&m.r32(node)!=ptr(child_[k])){need(++steps<4,"1480 oldproc collision chain");node=m.r32(node+8);}need(node!=0,"1480 produced oldproc node");m.w32(node+4,addr(os_[k]));}
  installed_=true;hook_=SetWindowsHookExA(WH_CALLWNDPROC,&hook,nullptr,GetCurrentThreadId());need(hook_!=nullptr,"1480 transparent real message observer");
 }
 void end(){need(active==this&&hook_&&installed_,"1480 matching observation finish");need(UnhookWindowsHookEx(hook_)!=FALSE,"1480 remove hook");hook_=nullptr;const auto target=original_?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;
  for(U k=0;k<4;++k){need(U(GetWindowLongPtrA(child_[k],GWLP_WNDPROC))==addr(target),"1480 subclass identity stable");need(U(SetWindowLongPtrA(child_[k],GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_[k])))==addr(target),"1480 restore actual original OSproc");}installed_=false;active=nullptr;memory_=nullptr;heap_=nullptr;
 }
 void close(){need(!active&&!hook_&&!installed_&&parent_&&outer_,"1480 cleanup outside all target/provider observations");verify();phase="fixture_destroy_without_projection";const auto before=fp::capture_host();const U fs=fs_head(),selector=fs_selector();
  need(U(SetWindowLongPtrA(parent_,DWLP_DLGPROC,0))==addr(&parent_proc),"1480 remove temporary original-branch projection before OS cleanup");const HWND parent=parent_,outer=outer_;need(DestroyWindow(parent)!=FALSE&&!IsWindow(parent),"1480 actual parent/control destruction");parent_=nullptr;need(DestroyWindow(outer)!=FALSE&&!IsWindow(outer),"1480 actual outer destruction");outer_=nullptr;
  need(fp::same_numeric(before,fp::capture_host())&&fs_head()==fs&&fs_selector()==selector,"1480 genuine separate cleanup full80/FS");
 }
 void verify()const{need(IsWindow(parent_)&&!IsWindowVisible(parent_)&&GetParent(parent_)==outer_,"1480 genuine hidden resource parent topology");for(U k=0;k<4;++k){char klass[32]{};need(IsWindow(child_[k])&&!IsWindowVisible(child_[k])&&GetParent(child_[k])==parent_&&GetDlgItem(parent_,ids[k])==child_[k],"1480 actual four child identities");need(GetClassNameA(child_[k],klass,32)>0&&lstrcmpiA(klass,"Button")==0,"1480 actual Button class");need(U(GetWindowLongA(child_[k],GWL_STYLE))==(k==1?0x50000403u:0x50000003u),"1480 exact untouched resource styles");if(!installed_)need(U(GetWindowLongPtrA(child_[k],GWLP_WNDPROC))==addr(os_[k]),"1480 raw actual OSproc identity");}}
};
inline Windows&context(){need(active!=nullptr,"1480 active real API/callback fixture");return*active;}
inline LRESULT WINAPI send(HWND h,int id,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(h==c.parent()&&c.index_id(U(id))<4&&(msg==0xf0||msg==0xf1)&&l==0&&(msg==0xf0?w==0:w<=1),"1480 exact real dialog message");const auto pre=fp::capture_host();const auto r=::SendDlgItemMessageA(h,id,msg,w,l);const auto post=fp::capture_host();c.record({1,ptr(h),msg,U(w),U(l),U(r),U(id),{},pre,post});return r;}
inline BOOL WINAPI rect(HWND h,LPRECT p){auto&c=context();need(c.index(h)<4&&p,"1480 actual child rect");const auto pre=fp::capture_host();const auto r=::GetWindowRect(h,p);const auto post=fp::capture_host();c.record({2,ptr(h),0,0,0,U(r),0,{p->left,p->top,p->right,p->bottom},pre,post});return r;}
inline BOOL WINAPI client(HWND h,LPRECT p){auto&c=context();need((h==c.parent()||c.index(h)<4)&&p,"1480 actual client rect");const auto pre=fp::capture_host();const auto r=::GetClientRect(h,p);const auto post=fp::capture_host();c.record({3,ptr(h),0,0,0,U(r),0,{p->left,p->top,p->right,p->bottom},pre,post});return r;}
inline BOOL WINAPI screen(HWND h,LPPOINT p){auto&c=context();need(h==c.parent()&&p,"1480 actual parent coordinate transform");const auto pre=fp::capture_host();const auto r=::ClientToScreen(h,p);const auto post=fp::capture_host();c.record({4,ptr(h),0,0,0,U(r),0,{p->x,p->y,0,0},pre,post});return r;}
inline LRESULT WINAPI call(WNDPROC p,HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(c.index(h)<4&&p==(c.original()?reinterpret_cast<WNDPROC>(0x5ebdb0):&button_window_proc)&&(msg==0xf0||msg==0xf1),"1480 actual selected Button callback");const auto pre=fp::capture_host();const auto r=::CallWindowProcA(p,h,msg,w,l);const auto post=fp::capture_host();c.record({5,ptr(h),msg,U(w),U(l),U(r),1,{},pre,post});return r;}
inline BOOL WINAPI invalidate(HWND h,const RECT*p,BOOL erase){auto&c=context();need(c.index(h)<4&&p==nullptr&&erase==FALSE,"1480 original F1 invalidation");const auto pre=fp::capture_host();const auto r=::InvalidateRect(h,p,erase);const auto post=fp::capture_host();c.record({6,ptr(h),0,0,0,U(r),0,{},pre,post});return r;}
}
