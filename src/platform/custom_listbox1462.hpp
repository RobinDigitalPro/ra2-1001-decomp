#pragma once
#include "recovered/recovery_b1462.hpp"
#include "platform/ordinary_heap979.hpp"
#include <array>
#include <vector>
#include <string>
#include <stdexcept>
namespace ra2::recovered::b1462::ui {
using U=std::uint32_t;using Adapter=ra2::recovered::b979::HeapAdapter;
inline void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
inline U ptr(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
template<class T>inline U addr(T p){return U(reinterpret_cast<std::uintptr_t>(p));}
inline bool candidate_message(U m){return m==0x49f||m==0x4a0||m==0x49e||m==0x4cd||m==0x49d||m==0x197||m==0x18b||m==0x1a1;}
struct Value{U raw=0,ordinal=0,offset=0;bool owned=false;bool operator==(const Value&o)const{return owned==o.owned&&(owned?(ordinal==o.ordinal&&offset==o.offset):raw==o.raw);}};
struct Event{U kind,h,message,w,provider;Value l,result;std::array<LONG,4>rect{};bool operator==(const Event&o)const{return kind==o.kind&&h==o.h&&message==o.message&&w==o.w&&provider==o.provider&&l==o.l&&result==o.result&&rect==o.rect;}};
struct Message{U hwnd,message,w;Value l;bool operator==(const Message&o)const{return hwnd==o.hwnd&&message==o.message&&w==o.w&&l==o.l;}};
class Windows;inline Windows*active=nullptr;
inline HGDIOBJ WINAPI stock(int);inline HGDIOBJ WINAPI select(HDC,HGDIOBJ);inline COLORREF WINAPI text(HDC);inline COLORREF WINAPI bk(HDC);inline int WINAPI mode(HDC);inline COLORREF WINAPI settext(HDC,COLORREF);inline COLORREF WINAPI setbk(HDC,COLORREF);inline int WINAPI setmode(HDC,int);inline HDC WINAPI getdc(HWND);inline int WINAPI releasedc(HWND,HDC);
inline LRESULT WINAPI send(HWND,UINT,WPARAM,LPARAM);inline HWND WINAPI parent(HWND);inline BOOL WINAPI rect(HWND,LPRECT);inline BOOL WINAPI client(HWND,LPRECT);inline BOOL WINAPI screen(HWND,LPPOINT);inline LRESULT WINAPI call(WNDPROC,HWND,UINT,WPARAM,LPARAM);
class Windows {
 HWND parent_{},listbox_{};WNDPROC os_{};HHOOK hook_{};bool original_=false,installed_=false;Memory*m_=nullptr;Adapter*h_=nullptr;
 std::vector<leaf::Memory*>spans_;std::vector<Event>events_;std::vector<Message>messages_;
 static LRESULT CALLBACK hook(int code,WPARAM w,LPARAM l){if(code>=0&&active){const auto*p=reinterpret_cast<const CWPSTRUCT*>(l);auto&c=*active;need(p->hwnd==c.listbox_&&candidate_message(p->message),"1462 unexpected actual synchronous window callback");c.messages_.push_back({ptr(p->hwnd),p->message,U(p->wParam),{U(p->lParam)}});}return CallNextHookEx(nullptr,code,w,l);}
public:
 HDC dc=nullptr;
 Windows(bool system_dialog=false){
  if(system_dialog){
   // Match the B1023 real default-dialog fixture: system #32770 class,
   // no application DLGPROC and the resource 234 dialog style.
   alignas(DWORD) std::array<WORD,12> t{};const DWORD style=WS_POPUP|DS_MODALFRAME;std::memcpy(t.data(),&style,4u);t[7]=120u;t[8]=80u;
   parent_=CreateDialogIndirectParamA(GetModuleHandleW(nullptr),reinterpret_cast<const DLGTEMPLATE*>(t.data()),nullptr,nullptr,0);
   need(parent_&&!IsWindowVisible(parent_),"1472 genuine hidden default #32770 parent");
   char cls[32]{};need(GetClassNameA(parent_,cls,32)>0&&std::strcmp(cls,"#32770")==0&&GetClassLongA(parent_,GCW_ATOM)==32770u&&GetClassLongA(parent_,GCL_CBWNDEXTRA)>=DLGWINDOWEXTRA&&GetWindowLongA(parent_,DWL_DLGPROC)==0,"1472 actual standard dialog class/default procedure/extra bytes");
  }else{
   parent_=CreateWindowExA(0,"STATIC","1462 hidden",WS_POPUP,10,10,240,180,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);
   need(parent_,"1462 real hidden parent");
  }
  listbox_=CreateWindowExA(0,"LISTBOX","",WS_CHILD|LBS_NOINTEGRALHEIGHT,8,8,160,140,parent_,reinterpret_cast<HMENU>(0x53f),GetModuleHandleW(nullptr),nullptr);
  need(listbox_,"1462 genuine initiallyempty ListBox");os_=reinterpret_cast<WNDPROC>(GetWindowLongPtrA(listbox_,GWLP_WNDPROC));need(os_,"1462 actual OS proc preread");
 }
 ~Windows(){if(hook_)UnhookWindowsHookEx(hook_);if(installed_)SetWindowLongPtrA(listbox_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_));if(active==this)active=nullptr;if(dc)ReleaseDC(listbox_,dc);if(listbox_)DestroyWindow(listbox_);if(parent_)DestroyWindow(parent_);}
 HWND parent()const{return parent_;}HWND listbox()const{return listbox_;}WNDPROC os()const{return os_;}bool original()const{return original_;}Memory&memory(){need(m_,"1462 active memory");return*m_;}Adapter&heap(){need(h_,"1462 active heap");return*h_;}
 void add_span(leaf::Memory&p){spans_.push_back(&p);}const void*host(U p,U size)const{for(auto*s:spans_)if(p>=s->base()&&std::uint64_t(p)+size<=std::uint64_t(s->base())+s->size())return s->host_view(p,size);throw std::domain_error("1462 missing mapped real OS text span");}
 Value owner(U p,U size){const auto q=heap().identify(p,size);return{p,q.ordinal,q.offset,true};}
 void record(Event e){events_.push_back(e);}const auto&events()const{return events_;}const auto&messages()const{return messages_;}
 void bind(Memory&m){m.w32(0x7854a0,addr(&send));m.w32(0x785500,addr(&ui::parent));m.w32(0x785398,addr(&rect));m.w32(0x7854b8,addr(&client));m.w32(0x7854ac,addr(&screen));m.w32(0x7854c0,addr(&call));m.w32(0x785084,addr(&stock));m.w32(0x785064,addr(&select));m.w32(0x785078,addr(&text));m.w32(0x785088,addr(&bk));m.w32(0x785080,addr(&mode));m.w32(0x785068,addr(&settext));m.w32(0x78506c,addr(&setbk));m.w32(0x78507c,addr(&setmode));m.w32(0x785458,addr(&getdc));m.w32(0x785478,addr(&releasedc));}
 void begin(Memory&m,Adapter&h,bool original){need(!active&&!installed_&&!hook_,"1462 exclusive provider");m_=&m;h_=&h;original_=original;events_.clear();messages_.clear();events_.reserve(512);messages_.reserve(64);active=this;need(GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(os_),"1462 exact oldproc before install");const auto target=original?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;const auto old=SetWindowLongPtrA(listbox_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(target));need(old!=0,"1462 authoritative SetWindowLong oldproc");os_=reinterpret_cast<WNDPROC>(old);installed_=true;need(GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(target),"1462 actual installed proc");const U node=m.r32(m.r32(0xa5b1e8)+(ptr(listbox_)&127)*4);need(node&&m.r32(node)==ptr(listbox_),"1462 original oldproc registry");m.w32(node+4,addr(os_));hook_=SetWindowsHookExA(WH_CALLWNDPROC,&hook,nullptr,GetCurrentThreadId());need(hook_,"1462 transparent actual message observer");}
 void end(){need(active==this&&hook_&&installed_,"1462 paired observer end");need(UnhookWindowsHookEx(hook_)!=FALSE,"1462 unhook observer");hook_=nullptr;const auto target=original_?reinterpret_cast<WNDPROC>(0x5e6550):&common_window_proc;need(GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(target),"1462 proc remained installed");need(SetWindowLongPtrA(listbox_,GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(os_))==reinterpret_cast<LONG_PTR>(target),"1462 restore real proc before teardown");installed_=false;active=nullptr;m_=nullptr;h_=nullptr;}
 void verify_structure()const{char name[32]{};need(IsWindow(parent_)&&IsWindow(listbox_)&&!IsWindowVisible(parent_)&&!IsWindowVisible(listbox_)&&GetParent(listbox_)==parent_&&GetDlgItem(parent_,0x53f)==listbox_,"1462 real hidden relations");need(GetClassNameA(listbox_,name,32)&&lstrcmpiA(name,"LISTBOX")==0&&GetWindowLongPtrA(listbox_,GWLP_WNDPROC)==reinterpret_cast<LONG_PTR>(os_),"1462 genuine restored ListBox class/proc");}
 void verify_empty()const{verify_structure();need(SendMessageA(listbox_,LB_GETCOUNT,0,0)==0&&SendMessageA(listbox_,LB_GETCURSEL,0,0)==LB_ERR,"1462 actual empty OS rows");}
 void verify_populated(U,const std::array<U,1>&owners)const{verify_structure();need(SendMessageA(listbox_,LB_GETCOUNT,0,0)==1&&SendMessageA(listbox_,LB_GETCURSEL,0,0)==LB_ERR,"1462 one real unselected row");char text[32]{};need(SendMessageA(listbox_,LB_GETTEXT,0,reinterpret_cast<LPARAM>(text))==5&&std::string(text)=="XYXYX","1462 genuine nonempty clipped text");need(U(SendMessageA(listbox_,LB_GETITEMDATA,0,0))==owners[0],"1462 raw actual item owner");need(SendMessageA(listbox_,LB_GETTOPINDEX,0,0)==0,"1462 actual zero top index");}
 void clear_fixture(){need(!installed_&&!active,"1462 postproof OS cleanup");SendMessageA(listbox_,LB_RESETCONTENT,0,0);ValidateRect(listbox_,nullptr);verify_empty();}
};
inline Windows&context(){need(active,"1462 active provider");return*active;}
inline LRESULT WINAPI send(HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(h==c.listbox()&&candidate_message(msg),"1462 reviewed original SendMessage");const auto r=::SendMessageA(h,msg,w,l);Value rv{U(r)};c.record({2,ptr(h),msg,U(w),0,{U(l)},rv,{}});return r;}
inline HWND WINAPI parent(HWND h){auto&c=context();need(h==c.listbox(),"1462 actual GetParent input");const auto r=::GetParent(h);need(r==c.parent(),"1462 genuine parent result");c.record({10,ptr(h),0,0,0,{},{ptr(r)},{}});return r;}
inline BOOL WINAPI rect(HWND h,LPRECT p){auto&c=context();need(h==c.listbox()&&p,"1462 rectangle input");const auto r=::GetWindowRect(h,p);c.record({3,ptr(h),0,0,0,{},{U(r)},{p->left,p->top,p->right,p->bottom}});return r;}
inline BOOL WINAPI client(HWND h,LPRECT p){auto&c=context();need((h==c.listbox()||h==c.parent())&&p,"1462 client input");const auto r=::GetClientRect(h,p);c.record({4,ptr(h),0,0,0,{},{U(r)},{p->left,p->top,p->right,p->bottom}});return r;}
inline BOOL WINAPI screen(HWND h,LPPOINT p){auto&c=context();need(h==c.parent()&&p,"1462 screen input");const auto r=::ClientToScreen(h,p);c.record({5,ptr(h),0,0,0,{},{U(r)},{p->x,p->y,0,0}});return r;}
inline LRESULT WINAPI call(WNDPROC p,HWND h,UINT msg,WPARAM w,LPARAM l){auto&c=context();need(h==c.listbox(),"1462 actual callback HWND");const bool handler=p==(c.original()?reinterpret_cast<WNDPROC>(0x5ee640):&listbox_window_proc);need(handler||p==c.os(),"1462 genuine selected or captured OS procedure");Value lp{U(l)};LPARAM actual=l;if(handler)need(candidate_message(msg),"1462 reviewed selected message");else{need(msg==0x180||msg==0x19a||msg==0x49d||msg==0x18b||msg==0x1a1,"1462 reviewed oldproc message");if(msg==0x180){need(U(l)>=0xaa8dec&&U(l)<0xaaadec,"1462 actual rotating narrow buffer");U n=0;while(c.memory().r8(U(l)+n)){need(n<5,"1462 exact short labels");++n;}need(n==5,"1462 five actual label characters");actual=reinterpret_cast<LPARAM>(c.host(U(l),n+1));}if(msg==0x19a)lp=c.owner(U(l),32);}
 const auto r=::CallWindowProcA(p,h,msg,w,actual);Value rv{U(r)};c.record({6,ptr(h),msg,U(w),handler?1u:2u,lp,rv,{}});return r;}
inline void valid_dc(HDC dc){need(dc&&dc==context().dc&&GetObjectType(dc)==OBJ_DC,"1462 real held windowDC");}
inline HGDIOBJ WINAPI stock(int index){need(index==13,"1462 actual stock13");auto r=GetStockObject(index);need(r&&GetObjectType(r)==OBJ_FONT,"1462 genuine stock font");context().record({11,0,0,U(index),0,{},{ptr(r)},{}});return r;}
inline HGDIOBJ WINAPI select(HDC dc,HGDIOBJ object){valid_dc(dc);need(object&&GetObjectType(object)==OBJ_FONT,"1462 valid produced font");auto r=SelectObject(dc,object);need(r&&r!=HGDI_ERROR,"1462 actual font selection");context().record({12,ptr(dc),0,ptr(object),0,{},{ptr(r)},{}});return r;}
inline COLORREF WINAPI text(HDC dc){valid_dc(dc);auto r=GetTextColor(dc);need(r!=CLR_INVALID,"1462 textcolor");context().record({13,ptr(dc),0,0,0,{},{U(r)},{}});return r;}
inline COLORREF WINAPI bk(HDC dc){valid_dc(dc);auto r=GetBkColor(dc);need(r!=CLR_INVALID,"1462 bkcolor");context().record({14,ptr(dc),0,0,0,{},{U(r)},{}});return r;}
inline int WINAPI mode(HDC dc){valid_dc(dc);auto r=GetBkMode(dc);need(r==1||r==2,"1462 real bkmode");context().record({15,ptr(dc),0,0,0,{},{U(r)},{}});return r;}
inline COLORREF WINAPI settext(HDC dc,COLORREF value){valid_dc(dc);auto r=SetTextColor(dc,value);need(r!=CLR_INVALID,"1462 actual restoretext");context().record({16,ptr(dc),0,U(value),0,{},{U(r)},{}});return r;}
inline COLORREF WINAPI setbk(HDC dc,COLORREF value){valid_dc(dc);auto r=SetBkColor(dc,value);need(r!=CLR_INVALID,"1462 actual restorebk");context().record({17,ptr(dc),0,U(value),0,{},{U(r)},{}});return r;}
inline int WINAPI setmode(HDC dc,int value){valid_dc(dc);need(value==1||value==2,"1462 genuine savedbkmode");auto r=SetBkMode(dc,value);need(r==1||r==2,"1462 actual restoremode");context().record({18,ptr(dc),0,U(value),0,{},{U(r)},{}});return r;}
inline std::array<LONG,4>dc_properties(HDC dc){return{LONG(ptr(GetCurrentObject(dc,OBJ_FONT))),LONG(GetTextColor(dc)),LONG(GetBkColor(dc)),LONG(GetBkMode(dc))};}
inline HDC WINAPI getdc(HWND h){auto&c=context();need(h==c.listbox()&&!c.dc,"1462 exact GetDC ownership");auto r=GetDC(h);need(r&&GetObjectType(r)==OBJ_DC,"1462 actual owned windowDC");c.dc=r;c.record({19,ptr(h),0,0,0,{},{ptr(r)},dc_properties(r)});return r;}
inline int WINAPI releasedc(HWND h,HDC dc){auto&c=context();need(h==c.listbox(),"1462 ReleaseDC HWND");valid_dc(dc);const auto properties=dc_properties(dc);auto r=ReleaseDC(h,dc);need(r==1,"1462 observed genuine ReleaseDC BOOL1");c.record({20,ptr(h),0,0,0,{ptr(dc)},{U(r)},properties});c.dc=nullptr;return r;}

}
