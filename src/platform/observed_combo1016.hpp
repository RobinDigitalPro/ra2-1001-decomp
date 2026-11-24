#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>
namespace ra2::recovered::b1016::ui {
inline void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
inline unsigned pointer(const void*p){static_assert(sizeof(void*)==4u);return unsigned(reinterpret_cast<std::uintptr_t>(p));}
inline unsigned mix(unsigned x){x^=x>>16;x*=0x7feb352du;x^=x>>15;x*=0x846ca68bu;return x^(x>>16);}
inline unsigned combo_id(unsigned k){constexpr unsigned ids[]={0x6a1,0x510,0x513,0x51e,0x514,0x51f,0x520,0x521};need(k<8u,"1016 mappedordinal");return ids[k];}
struct Case{unsigned root,n,seed;};
inline Case native_case(unsigned root,unsigned n){return {root,n,0x10160000u^mix(n)};}
inline Case assurance_case(unsigned root,unsigned n){auto c=native_case(root,700u+n);c.seed^=0xa55a1016u;return c;}
inline unsigned ordinal(const Case&c){return c.n%8u;}
inline unsigned item(const Case&c,unsigned k,unsigned j){constexpr unsigned selectors[]={0xfffffffeu,0u,1u,2u,3u,4u,5u,6u,7u,8u};return selectors[(c.n+3u*k+7u*j)%10u];}
inline bool override_global(const Case&c){return c.root==0xd10b0u&&c.n%4u==0u;}
inline unsigned requested(const Case&c){return override_global(c)?0xfffffffeu:c.n%5u==4u?9u:item(c,ordinal(c),(c.n/8u)%4u);}
inline unsigned global_requested(const Case&c){return override_global(c)?0x11223344u:requested(c);}
inline int match(const Case&c){for(unsigned j=0;j<4u;++j)if(item(c,ordinal(c),j)==requested(c))return int(j);return -1;}
inline unsigned initial(const Case&c,unsigned k){if(c.root!=0xd0c50u&&k==ordinal(c)&&match(c)>=0)return unsigned(match(c)+1)%4u;return (c.n+2u*k)%4u;}
inline unsigned selected(const Case&c,unsigned k){return c.root!=0xd0c50u&&k==ordinal(c)&&match(c)>=0?unsigned(match(c)):initial(c,k);}
inline unsigned selector(const Case&c){return item(c,ordinal(c),selected(c,ordinal(c)));}
inline unsigned resource_index(const Case&c){const auto v=selector(c);return v==0xfffffffeu?0u:v+1u;}
inline bool visible(const Case&c,unsigned k){return ((c.n/8u+k)&1u)!=0u;}
enum class Kind:unsigned{get=1,show,send,invalidate};
struct Event{Kind kind{};unsigned hwnd=0,id=0,message=0,w=0,l=0,result=0,after=0;std::array<LONG,4>rect{};bool operator==(const Event&o)const{return kind==o.kind&&hwnd==o.hwnd&&id==o.id&&message==o.message&&w==o.w&&l==o.l&&result==o.result&&after==o.after&&rect==o.rect;}};
class Windows;
inline Windows*active=nullptr;inline std::vector<Event>events;
inline HWND WINAPI get(HWND,int);inline BOOL WINAPI show(HWND,int);inline LRESULT WINAPI send(HWND,int,UINT,WPARAM,LPARAM);inline BOOL WINAPI invalidate(HWND,const RECT*,BOOL);
class Windows {
 HWND parent_{};std::array<HWND,8>combos_{},previews_{};std::array<LONG_PTR,8>combo_procs_{},preview_procs_{};std::array<LONG,8>combo_styles_{},preview_styles_{};Case c_;unsigned hide_result_=0,show_result_=0,invalidate_result_=0,invalid_after_=0;std::array<LONG,4>invalid_rect_{};mutable unsigned record_=0,resource_=0;
 public:
 explicit Windows(const Case&c):c_(c){parent_=CreateWindowExA(0,"STATIC","1016 hidden parent",WS_POPUP,-700,-500,600,400,nullptr,nullptr,GetModuleHandleW(nullptr),nullptr);need(parent_&&!IsWindowVisible(parent_),"1016 genuinehiddenparent");for(unsigned k=0;k<8u;++k){combos_[k]=CreateWindowExA(0,"COMBOBOX","",WS_CHILD|CBS_DROPDOWNLIST|(visible(c,k)?WS_VISIBLE:0u),8,int(k*30u),120,120,parent_,reinterpret_cast<HMENU>(std::uintptr_t(combo_id(k))),GetModuleHandleW(nullptr),nullptr);previews_[k]=CreateWindowExA(0,"STATIC","preview",WS_CHILD,300,int(k*30u),32,24,parent_,reinterpret_cast<HMENU>(std::uintptr_t(0x6dau+k)),GetModuleHandleW(nullptr),nullptr);need(combos_[k]&&previews_[k],"1016 genuinestandardcomboandpreview");combo_procs_[k]=GetWindowLongPtrA(combos_[k],GWLP_WNDPROC);preview_procs_[k]=GetWindowLongPtrA(previews_[k],GWLP_WNDPROC);combo_styles_[k]=GetWindowLongA(combos_[k],GWL_STYLE);preview_styles_[k]=GetWindowLongA(previews_[k],GWL_STYLE);for(unsigned j=0;j<4u;++j){const auto label=std::string("entry")+char('0'+j);need(::SendMessageA(combos_[k],CB_ADDSTRING,0,reinterpret_cast<LPARAM>(label.c_str()))==j,"1016 actualinsertfourstrings");need(::SendMessageA(combos_[k],CB_SETITEMDATA,j,LPARAM(std::int32_t(item(c,k,j))))!=CB_ERR,"1016 actualfourDWORDitemdata");}need(::SendMessageA(combos_[k],CB_SETCURSEL,initial(c,k),0)==initial(c,k),"1016 actualinitialselection");}
  if(c.root!=0xd0c50u){const auto target=combo();hide_result_=unsigned(::ShowWindow(target,SW_HIDE));if(hide_result_)show_result_=unsigned(::ShowWindow(target,SW_SHOW));::ShowWindow(target,visible(c,ordinal(c))?SW_SHOW:SW_HIDE);}
  ::ValidateRect(preview(),nullptr);invalidate_result_=unsigned(::InvalidateRect(preview(),nullptr,TRUE));need(invalidate_result_!=0u,"1016 positiveactualInvalidateRectprobe");RECT r{};invalid_after_=unsigned(::GetUpdateRect(preview(),&r,FALSE));if(invalid_after_)invalid_rect_={r.left,r.top,r.right,r.bottom};reset();verify(false);
 }
 ~Windows(){if(active==this)active=nullptr;if(parent_)DestroyWindow(parent_);}
 Windows(const Windows&)=delete;
 HWND parent()const{return parent_;}HWND combo()const{return combos_[ordinal(c_)];}HWND preview()const{return previews_[ordinal(c_)];}unsigned hide_result()const{return hide_result_;}unsigned final_eax()const{return invalidate_result_;}
 void observe_record(unsigned record,unsigned resource)const{record_=record;resource_=resource;}
 void before_invalidate(HWND h,const RECT*r,BOOL erase)const{need(record_&&h==preview()&&r==nullptr&&erase==TRUE,"1016 exactpreview/nullrect/TRUEinvalidation");const auto word=[&](unsigned off){unsigned value=0;std::memcpy(&value,reinterpret_cast<const void*>(std::uintptr_t(record_+off)),4u);return value;};need(word(0)==pointer(preview())&&word(0x74u)==2u&&word(0x18u)==resource_,"1016 recordkey/twoexactstoresalreadyvisibleBEFOREactualInvalidateRect");}
 unsigned expected_events()const{return c_.root==0xd0c50u?4u:2u+1u+(match(c_)>=0?unsigned(match(c_)+1):4u)+(match(c_)>=0?1u:0u)+(hide_result_?1u:0u)+1u+2u+1u;}
 void reset(){need(!active,"1016 resetoutsideobservation");for(unsigned k=0;k<8u;++k){::ShowWindow(combos_[k],visible(c_,k)?SW_SHOW:SW_HIDE);need(::SendMessageA(combos_[k],CB_SETCURSEL,initial(c_,k),0)==initial(c_,k),"1016 genuineoutsidecallselectionreset");need(::ValidateRect(combos_[k],nullptr)!=FALSE&&::ValidateRect(previews_[k],nullptr)!=FALSE,"1016 clearactualupdateregions");}}
 void verify(bool changed)const{need(IsWindow(parent_)&&!IsWindowVisible(parent_),"1016 hiddenparentlifetime");for(unsigned k=0;k<8u;++k){char a[32]{},b[32]{};need(GetClassNameA(combos_[k],a,32)>0&&lstrcmpiA(a,"COMBOBOX")==0&&GetClassNameA(previews_[k],b,32)>0&&lstrcmpiA(b,"STATIC")==0,"1016 actualstandardclasses");need(GetDlgItem(parent_,combo_id(k))==combos_[k]&&GetDlgItem(parent_,int(0x6dau+k))==previews_[k]&&GetParent(combos_[k])==parent_&&GetParent(previews_[k])==parent_&&GetWindowLongPtrA(combos_[k],GWLP_WNDPROC)==combo_procs_[k]&&GetWindowLongPtrA(previews_[k],GWLP_WNDPROC)==preview_procs_[k],"1016 genuinehandle/parent/unmodifiedstandardWndProcs");need(!IsWindowVisible(combos_[k])&&!IsWindowVisible(previews_[k]),"1016 childrenremainactuallyhidden");LONG style=combo_styles_[k];if(changed&&c_.root!=0xd0c50u&&k==ordinal(c_)){style&=~LONG(WS_VISIBLE);if(hide_result_)style|=WS_VISIBLE;}need(GetWindowLongA(combos_[k],GWL_STYLE)==style&&GetWindowLongA(previews_[k],GWL_STYLE)==preview_styles_[k],"1016 fullcontrolstyles/visibilityrestore");need(::SendMessageA(combos_[k],CB_GETCOUNT,0,0)==4&&::SendMessageA(combos_[k],CB_GETCURSEL,0,0)==(changed?selected(c_,k):initial(c_,k)),"1016 exactcount/independentfinalselection");for(unsigned j=0;j<4u;++j){char text[32]{};const auto expected=std::string("entry")+char('0'+j);need(unsigned(::SendMessageA(combos_[k],CB_GETITEMDATA,j,0))==item(c_,k,j)&&::SendMessageA(combos_[k],CB_GETLBTEXT,j,reinterpret_cast<LPARAM>(text))==expected.size()&&expected==text,"1016 everyunchangeditemdataandtext");}RECT r{};const auto dirty=unsigned(::GetUpdateRect(previews_[k],&r,FALSE));need(dirty==(changed&&k==ordinal(c_)?invalid_after_:0u),"1016 independentlyexpectedactualpreviewupdatestate");if(dirty)need(std::array<LONG,4>{r.left,r.top,r.right,r.bottom}==invalid_rect_,"1016 completeactualpreviewupdaterect");}}
 void begin(){need(!active,"1016 exclusiveobserver");events.clear();events.reserve(32);active=this;}
 void finish(){need(active==this,"1016 matchingobserver");active=nullptr;need(events==expected_trace(),"1016 independentexactAPItraceparameters/order/fullresults");verify(true);}
 std::vector<Event>expected_trace()const{std::vector<Event>v;const auto add=[&](Kind kind,unsigned hwnd,unsigned id,unsigned message,unsigned w,unsigned l,unsigned result){Event e{};e.kind=kind;e.hwnd=hwnd;e.id=id;e.message=message;e.w=w;e.l=l;e.result=result;v.push_back(e);};const unsigned h=pointer(parent_),id=combo_id(ordinal(c_));if(c_.root!=0xd0c50u){add(Kind::get,h,id,0,0,0,pointer(combo()));add(Kind::show,pointer(combo()),0,0,SW_HIDE,0,hide_result_);add(Kind::send,h,id,CB_GETCOUNT,0,0,4);const unsigned stop=match(c_)>=0?unsigned(match(c_)+1):4u;for(unsigned j=0;j<stop;++j)add(Kind::send,h,id,CB_GETITEMDATA,j,0,item(c_,ordinal(c_),j));if(match(c_)>=0)add(Kind::send,h,id,CB_SETCURSEL,unsigned(match(c_)),0,unsigned(match(c_)));if(hide_result_)add(Kind::show,pointer(combo()),0,0,SW_SHOW,0,show_result_);}add(Kind::get,h,0x6dau+ordinal(c_),0,0,0,pointer(preview()));add(Kind::send,h,id,CB_GETCURSEL,0,0,selected(c_,ordinal(c_)));add(Kind::send,h,id,CB_GETITEMDATA,selected(c_,ordinal(c_)),0,selector(c_));add(Kind::invalidate,pointer(preview()),0,0,TRUE,0,invalidate_result_);v.back().after=invalid_after_;v.back().rect=invalid_rect_;need(v.size()==expected_events(),"1016 independenttracecountarithmetic");return v;}
};
inline void observer_need(){if(!active){std::fprintf(stderr,"1016 API outsideactivecandidate\n");ExitProcess(10);}}
inline HWND WINAPI get(HWND h,int id){observer_need();const auto r=::GetDlgItem(h,id);const auto error=GetLastError();Event e{};e.kind=Kind::get;e.hwnd=pointer(h);e.id=unsigned(id);e.result=pointer(r);events.push_back(e);SetLastError(error);return r;}
inline BOOL WINAPI show(HWND h,int command){observer_need();const auto r=::ShowWindow(h,command);const auto error=GetLastError();Event e{};e.kind=Kind::show;e.hwnd=pointer(h);e.w=unsigned(command);e.result=unsigned(r);events.push_back(e);SetLastError(error);return r;}
inline LRESULT WINAPI send(HWND h,int id,UINT message,WPARAM w,LPARAM l){observer_need();const auto r=::SendDlgItemMessageA(h,id,message,w,l);const auto error=GetLastError();Event e{};e.kind=Kind::send;e.hwnd=pointer(h);e.id=unsigned(id);e.message=message;e.w=unsigned(w);e.l=unsigned(l);e.result=unsigned(r);events.push_back(e);SetLastError(error);return r;}
inline BOOL WINAPI invalidate(HWND h,const RECT*r,BOOL erase){observer_need();active->before_invalidate(h,r,erase);const auto result=::InvalidateRect(h,r,erase);const auto error=GetLastError();Event e{};e.kind=Kind::invalidate;e.hwnd=pointer(h);e.w=unsigned(erase);e.l=pointer(r);e.result=unsigned(result);RECT dirty{};e.after=unsigned(::GetUpdateRect(h,&dirty,FALSE));if(e.after)e.rect={dirty.left,dirty.top,dirty.right,dirty.bottom};events.push_back(e);SetLastError(error);return result;}
template<class F>inline unsigned address(F f){return unsigned(reinterpret_cast<std::uintptr_t>(f));}
}
