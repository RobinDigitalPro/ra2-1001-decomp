#pragma once
#include "recovered/recovery_b1427.hpp"
#include "platform/ordinary_heap979.hpp"
#include <array>
#include <vector>
#include <string>
#include <stdexcept>
namespace ra2::recovered::b1427::ui {
using U=std::uint32_t;using Adapter=ra2::recovered::b979::HeapAdapter;
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
template<class T>inline U addr(T p){return U(reinterpret_cast<std::uintptr_t>(p));}
inline bool candidate_message(U m){return m==0x4cd||m==0x19a||m==0x18b||m==0x1a1;}
struct Value{U raw=0,ordinal=0,offset=0;bool owned=false;bool operator==(const Value&o)const{return owned==o.owned&&(owned?(ordinal==o.ordinal&&offset==o.offset):raw==o.raw);}};
struct Event{U kind,h,message,w,provider;Value l,result;std::array<LONG,4>rect{};bool operator==(const Event&o)const{return kind==o.kind&&h==o.h&&message==o.message&&w==o.w&&provider==o.provider&&l==o.l&&result==o.result&&rect==o.rect;}};
struct Message{U hwnd,message,w;Value l;bool operator==(const Message&o)const{return hwnd==o.hwnd&&message==o.message&&w==o.w&&l==o.l;}};
class Windows;inline Windows*active=nullptr;
inline LRESULT WINAPI send(HWND,UINT,WPARAM,LPARAM);inline HWND WINAPI parent(HWND);inline BOOL WINAPI rect(HWND,LPRECT);inline BOOL WINAPI client(HWND,LPRECT);inline BOOL WINAPI screen(HWND,LPPOINT);inline LRESULT WINAPI call(WNDPROC,HWND,UINT,WPARAM,LPARAM);
class Windows {
 HWND parent_{},listbox_{};WNDPROC os_{};HHOOK hook_{};bool original_=false,installed_=false;Memory*m_=nullptr;Adapter*h_=nullptr;
 std::vector<leaf::Memory*>spans_;std::vector<Event>events_;std::vector<Message>messages_;
 static LRESULT CALLBACK hook(int code,WPARAM w,LPARAM l){if(code>=0&&active){const auto*p=reinterpret_cast<const CWPSTRUCT*>(l);auto&c=*active;need(p->hwnd==c.listbox_&&candidate_message(p->message),"1427 unexpected actual synchronous window callback");c.messages_.push_back({ptr(p->hwnd),p->message,U(p->wParam),{U(p->lParam)}});}return CallNextHookEx(nullptr,code,w,l);}
public:
 Windows(){parent_=CreateWindowExA(0,"STATIC","1427 hidden",WS_POPUP,10,10,240,180,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(parent_,"1427 real hidden parent");listbox_=CreateWindowExA(0,"LISTBOX","",WS_CHILD|LBS_NOINTEGRALHEIGHT,8,8,160,140,parent_,reinterpret_cast<HMENU>(0x744),GetModuleHandleW(nullptr),nullptr);need(listbox_,"1427 genuine initiallyempty ListBox");os_=reinterpret_cast<WNDPROC>(GetWindowLongPtrA(listbox_,GWLP_WNDPROC));need(os_,"1427 actual OS proc preread");}
 ~Windows(){if(hook_)UnhookWindowsHookEx(hook_);if(installed_)SetWindowLongPtrA(listbox_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_));if(active==this)active=nullptr;if(listbox_)DestroyWindow(listbox_);if(parent_)DestroyWindow(parent_);}
 HWND parent()const{return parent_;}HWND listbox()const{return listbox_;}WNDPROC os()const{return os_;}bool original()const{return original_;}Memory&memory(){need(m_,"1427 active memory");return*m_;}Adapter&heap(){need(h_,"1427 active heap");return*h_;}
 void add_span(leaf::Memory&p){spans_.push_back(&p);}const void*host(U p,U size)const{for(auto*s:spans_)if(p>=s->base()&&std::uint64_t(p)+size<=std::uint64_t(s->base())+s->size())return s->host_view(p,size);throw std::domain_error("1427 missing mapped real OS text span");}
 Value owner(U p,U size){const auto q=heap().identify(p,size);return{p,q.ordinal,q.offset,true};}
 void record(Event e){events_.push_back(e);}const auto&events()const{return events_;}const auto&messages()const{return messages_;}
 void bind(Memory&m){m.w32(0x7854a0,addr(&send));m.w32(0x785500,addr(&ui::parent));m.w32(0x785398,addr(&rect));m.w32(0x7854b8,addr(&client));m.w32(0x7854ac,addr(&screen));m.w32(0x7854c0,addr(&call));}
 void begin(Memory&m,Adapter&h,bool original){need(!active&&!installed_&&!hook_,"1427 exclusive provider");m_=&m;h_=&h;original_=original;events_.clear();messages_.clear();events_.reserve(512);messages_.reserve(64);active=this;need(GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(os_),"1427 exact oldproc before install");const auto target=original?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;const auto old=SetWindowLongPtrA(listbox_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(target));need(old!=0,"1427 authoritative SetWindowLong oldproc");os_=reinterpret_cast<WNDPROC>(old);installed_=true;need(GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(target),"1427 actual installed proc");const U node=m.r32(m.r32(0xa5b1e8)+(ptr(listbox_)&127)*4);need(node&&m.r32(node)==ptr(listbox_),"1427 original oldproc registry");m.w32(node+4,addr(os_));hook_=SetWindowsHookExA(WH_CALLWNDPROC,&hook,nullptr,GetCurrentThreadId());need(hook_,"1427 transparent actual message observer");}
 void end(){need(active==this&&hook_&&installed_,"1427 paired observer end");need(UnhookWindowsHookEx(hook_)!=FALSE,"1427 unhook observer");hook_=nullptr;const auto target=original_?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;need(GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(target),"1427 proc remained installed");need(SetWindowLongPtrA(listbox_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_))==reinterpret_cast<LONG_PTR>(target),"1427 restore real proc before teardown");installed_=false;active=nullptr;m_=nullptr;h_=nullptr;}
 void verify_structure()const{char name[32]{};need(IsWindow(parent_)&&IsWindow(listbox_)&&!IsWindowVisible(parent_)&&!IsWindowVisible(listbox_)&&GetParent(listbox_)==parent_&&GetDlgItem(parent_,0x744)==listbox_,"1427 real hidden relations");need(GetClassNameA(listbox_,name,32)&&lstrcmpiA(name,"LISTBOX")==0&&GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(os_),"1427 genuine restored ListBox class/proc");}
 void verify_empty()const{verify_structure();need(SendMessageA(listbox_,LB_GETCOUNT,0,0)==0&&SendMessageA(listbox_,LB_GETCURSEL,0,0)==LB_ERR,"1427 actual empty OS rows");}
 void verify_populated(U,const std::array<U,3>&owners)const{verify_structure();static const char*texts[]{"Intro","Sov01","All01"};need(SendMessageA(listbox_,LB_GETCOUNT,0,0)==3&&SendMessageA(listbox_,LB_GETCURSEL,0,0)==LB_ERR,"1427 three real unselected rows");for(U k=0;k<3;++k){char text[32]{};need(SendMessageA(listbox_,LB_GETTEXT,k,reinterpret_cast<LPARAM>(text))==5&&std::string(text)==texts[k],"1427 exact real ListBox text");need(U(SendMessageA(listbox_,LB_GETITEMDATA,k,0))==owners[k],"1427 exact OS itemdata owner correspondence");}}
 void clear_fixture(){need(!installed_&&!active,"1427 postproof OS cleanup");SendMessageA(listbox_,LB_RESETCONTENT,0,0);ValidateRect(listbox_,nullptr);verify_empty();}
};
inline Windows&context(){need(active,"1427 active provider");return*active;}
inline LRESULT WINAPI send(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(h==c.listbox()&&candidate_message(msg),"1427 reviewed original SendMessage");const auto r=::SendMessageA(h,msg,w,l);Value rv{U(r)};if(msg==0x19a&&U(r)!=0xffffffffu&&r!=0)rv=c.owner(U(r),32);c.record({2,ptr(h),msg,U(w),0,{U(l)},rv,{}});return r;}
inline HWND WINAPI parent(HWND h){auto&c=context();need(h==c.listbox(),"1427 actual GetParent input");const auto r=::GetParent(h);need(r==c.parent(),"1427 genuine parent result");c.record({10,ptr(h),0,0,0,{},{ptr(r)},{}});return r;}
inline BOOL WINAPI rect(HWND h,LPRECT p){auto&c=context();need(h==c.listbox()&&p,"1427 rectangle input");const auto r=::GetWindowRect(h,p);c.record({3,ptr(h),0,0,0,{},{U(r)},{p->left,p->top,p->right,p->bottom}});return r;}
inline BOOL WINAPI client(HWND h,LPRECT p){auto&c=context();need((h==c.listbox()||h==c.parent())&&p,"1427 client input");const auto r=::GetClientRect(h,p);c.record({4,ptr(h),0,0,0,{},{U(r)},{p->left,p->top,p->right,p->bottom}});return r;}
inline BOOL WINAPI screen(HWND h,LPPOINT p){auto&c=context();need(h==c.parent()&&p,"1427 screen input");const auto r=::ClientToScreen(h,p);c.record({5,ptr(h),0,0,0,{},{U(r)},{p->x,p->y,0,0}});return r;}
inline LRESULT WINAPI call(WNDPROC p,HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(h==c.listbox(),"1427 actual callback HWND");const bool handler=p==(c.original()?reinterpret_cast<WNDPROC>(0x5ee640):&listbox_window_proc);need(handler||p==c.os(),"1427 genuine selected or captured OS procedure");Value lp{U(l)};LPARAM actual=l;if(handler)need(candidate_message(msg),"1427 reviewed selected message");else{need(msg==0x180||msg==0x19a||msg==0x199||msg==0x18b||msg==0x1a1,"1427 reviewed oldproc message");if(msg==0x180){need(U(l)>=0xaa8dec&&U(l)<0xaaadec,"1427 actual rotating narrow buffer");U n=0;while(c.memory().r8(U(l)+n)){need(n<5,"1427 exact short labels");++n;}need(n==5,"1427 five actual label characters");actual=reinterpret_cast<LPARAM>(c.host(U(l),n+1));}if(msg==0x19a)lp=c.owner(U(l),32);}
 const auto r=::CallWindowProcA(p,h,msg,w,actual);Value rv{U(r)};if((!handler&&msg==0x199&&U(r)!=0xffffffffu&&r!=0)||(handler&&msg==0x19a&&U(r)!=0xffffffffu&&r!=0))rv=c.owner(U(r),32);c.record({6,ptr(h),msg,U(w),handler?1u:2u,lp,rv,{}});return r;}
}
