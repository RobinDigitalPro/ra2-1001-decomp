#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b1413.hpp"
#include <array>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>
namespace ra2::recovered::b1413::ui {
inline void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
inline unsigned ptr(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
template<class T>inline unsigned addr(T f){return unsigned(reinterpret_cast<std::uintptr_t>(f));}
struct Event {unsigned kind,h,message,w,l,result,provider;std::array<LONG,4>value{};bool operator==(const Event&o)const{return kind==o.kind&&h==o.h&&message==o.message&&w==o.w&&l==o.l&&result==o.result&&provider==o.provider&&value==o.value;}};
struct Message {unsigned hwnd,message,w,l;bool operator==(const Message&o)const{return hwnd==o.hwnd&&message==o.message&&w==o.w&&l==o.l;}};
class Windows;
inline Windows* active=nullptr;
inline HWND WINAPI get(HWND,int);inline LRESULT WINAPI send(HWND,UINT,WPARAM,LPARAM);
inline BOOL WINAPI rect(HWND,LPRECT);inline BOOL WINAPI client(HWND,LPRECT);inline BOOL WINAPI screen(HWND,LPPOINT);
inline LRESULT WINAPI call(WNDPROC,HWND,UINT,WPARAM,LPARAM);
class Windows {
 HWND parent_{},combo_{};WNDPROC os_{};HHOOK hook_{};bool original_{},installed_{};Memory* memory_{};Heap*heap_{};
 unsigned chosen_{};std::vector<Event> events_;std::vector<Message> messages_;
 static LRESULT CALLBACK hook(int code,WPARAM w,LPARAM l){if(code>=0&&active){const auto*p=reinterpret_cast<const CWPSTRUCT*>(l);active->messages_.push_back({ptr(p->hwnd),p->message,unsigned(p->wParam),unsigned(p->lParam)});}return CallNextHookEx(nullptr,code,w,l);}
 public:
 explicit Windows(unsigned chosen):chosen_(chosen){
  need(chosen<8,"1413 valid cachedselection");
  parent_=CreateWindowExA(0,"STATIC","1413 hidden",WS_POPUP,10,10,240,160,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);
  need(parent_!=nullptr,"1413 real hidden parent");
  combo_=CreateWindowExA(0,"COMBOBOX","",WS_CHILD|CBS_DROPDOWNLIST,8,8,120,120,parent_,reinterpret_cast<HMENU>(0x405),GetModuleHandleW(nullptr),nullptr);
  need(combo_!=nullptr,"1413 real system ComboBox");os_=reinterpret_cast<WNDPROC>(GetWindowLongPtrA(combo_,GWLP_WNDPROC));need(os_!=nullptr,"1413 captured genuine OS proc");
  for(unsigned k=0;k<8;++k){const std::string s="item"+std::to_string(k);need(SendMessageA(combo_,CB_ADDSTRING,0,reinterpret_cast<LPARAM>(s.c_str()))==k,"1413 real populated OS entries");}
  need(SendMessageA(combo_,CB_SETCURSEL,chosen_,0)==chosen_,"1413 real OS selected entry");
 }
 ~Windows(){if(hook_){UnhookWindowsHookEx(hook_);hook_=nullptr;}if(installed_){SetWindowLongPtrA(combo_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_));installed_=false;}if(active==this)active=nullptr;if(combo_)DestroyWindow(combo_);if(parent_)DestroyWindow(parent_);}
 HWND parent()const{return parent_;}HWND combo()const{return combo_;}WNDPROC os()const{return os_;}unsigned selected()const{return chosen_;}
 Memory&memory()const{need(memory_!=nullptr,"1413 active memory");return *memory_;}Heap&heap()const{need(heap_!=nullptr,"1413 active genuine heap");return *heap_;}
 bool original()const{return original_;}
 void record(Event e){events_.push_back(e);}
 const std::vector<Event>&events()const{return events_;}const std::vector<Message>&messages()const{return messages_;}
 void bind(Memory&m){m.w32(0x78549cu,addr(&get));m.w32(0x7854a0u,addr(&send));m.w32(0x785398u,addr(&rect));m.w32(0x7854b8u,addr(&client));m.w32(0x7854acu,addr(&screen));m.w32(0x7854c0u,addr(&call));}
 void begin(Memory&m,Heap&h,bool original){
  need(!active&&!hook_,"1413 exclusive observer");memory_=&m;heap_=&h;original_=original;active=this;events_.clear();messages_.clear();events_.reserve(64);messages_.reserve(16);
  const auto target=original?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;
  need(GetWindowLongPtrA(combo_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(os_),"1413 original OS procedure before subclass");
  const auto old=SetWindowLongPtrA(combo_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(target));need(old!=0,"1413 actual installer captured old procedure");os_=reinterpret_cast<WNDPROC>(old);installed_=true;need(GetWindowLongPtrA(combo_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(target),"1413 installed procedure identity");
  const unsigned node=m.r32(m.r32(0xa5b1e8u)+(ptr(combo_)&127u)*4u);need(node&&m.r32(node)==ptr(combo_),"1413 producer oldproc record");m.w32(node+4u,addr(os_));
  active=this;hook_=SetWindowsHookExA(WH_CALLWNDPROC,&hook,nullptr,GetCurrentThreadId());need(hook_!=nullptr,"1413 real transparent message observer");
 }
 void end(){
  need(active==this&&hook_,"1413 matching finish");need(UnhookWindowsHookEx(hook_)!=FALSE,"1413 remove observer");hook_=nullptr;
  const auto target=original_?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;
  need(GetWindowLongPtrA(combo_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(target),"1413 callback identity remained installed");
  need(SetWindowLongPtrA(combo_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_))==reinterpret_cast<LONG_PTR>(target),"1413 restore genuine OS procedure before fixture teardown");installed_=false;active=nullptr;memory_=nullptr;heap_=nullptr;
 }
 void verify()const{
  char klass[32]{};need(IsWindow(parent_)&&IsWindow(combo_)&&!IsWindowVisible(parent_)&&!IsWindowVisible(combo_)&&GetParent(combo_)==parent_&&GetDlgItem(parent_,0x405)==combo_,"1413 genuine live hidden HWND relationships");
  need(GetClassNameA(combo_,klass,32)>0&&lstrcmpiA(klass,"COMBOBOX")==0&&GetWindowLongPtrA(combo_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(os_),"1413 actual class/unmodified captured OSproc after unhook");
  need(SendMessageA(combo_,CB_GETCOUNT,0,0)==8&&SendMessageA(combo_,CB_GETCURSEL,0,0)==chosen_,"1413 actual nonempty OS selection stable");
  for(unsigned k=0;k<8;++k){char s[32]{};const auto expected="item"+std::to_string(k);need(SendMessageA(combo_,CB_GETLBTEXT,k,reinterpret_cast<LPARAM>(s))==expected.size()&&s==expected,"1413 every OS item text unchanged");}
 }
 unsigned provider_result(unsigned color)const{return unsigned(CallWindowProcA(os_,combo_,0x498,0,LPARAM(color)));}
};
inline Windows&context(){need(active!=nullptr,"1413 actual API/callback requires active fixture");return *active;}
inline HWND WINAPI get(HWND h,int id){auto&c=context();need(h==c.parent()&&id==0x405,"1413 original GetDlgItem args");const auto r=::GetDlgItem(h,id);c.record({1,ptr(h),0,unsigned(id),0,ptr(r),0,{}});return r;}
inline LRESULT WINAPI send(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(h==c.combo()&&(msg==0x147u||msg==0x498u)&&w==0,"1413 exact root messages");const auto r=::SendMessageA(h,msg,w,l);c.record({2,ptr(h),msg,unsigned(w),unsigned(l),unsigned(r),0,{}});return r;}
inline BOOL WINAPI rect(HWND h,LPRECT p){auto&c=context();need(h==c.combo()&&p,"1413 genuine combo rectangle args");const auto r=::GetWindowRect(h,p);c.record({3,ptr(h),0,0,0,unsigned(r),0,{p->left,p->top,p->right,p->bottom}});return r;}
inline BOOL WINAPI client(HWND h,LPRECT p){auto&c=context();need((h==c.combo()||h==c.parent())&&p,"1413 genuine client rectangle args");const auto r=::GetClientRect(h,p);c.record({4,ptr(h),0,0,0,unsigned(r),0,{p->left,p->top,p->right,p->bottom}});return r;}
inline BOOL WINAPI screen(HWND h,LPPOINT p){auto&c=context();need(h==c.parent()&&p,"1413 genuine parent coordinate conversion args");const auto r=::ClientToScreen(h,p);c.record({5,ptr(h),0,0,0,unsigned(r),0,{p->x,p->y,0,0}});return r;}
inline LRESULT WINAPI call(WNDPROC p,HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(h==c.combo()&&(msg==0x147u||msg==0x498u),"1413 exact callback invocation");const bool handler=p==(c.original()?reinterpret_cast<WNDPROC>(0x5ecc60):&combo_window_proc);need(handler||p==c.os(),"1413 genuine selected/old OS procedure");const auto r=::CallWindowProcA(p,h,msg,w,l);c.record({6,ptr(h),msg,unsigned(w),unsigned(l),unsigned(r),handler?1u:2u,{}});return r;}
}
