#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstring>
#include <stdexcept>
#include "platform/x87_state.hpp"
namespace ra2::platform::critical1481 {
using U=std::uint32_t;namespace fp=ra2::platform::x87;
inline constexpr U address=0x822170u;
inline void need(bool ok,const char*s){if(!ok)throw std::runtime_error(s);}
inline U pointer(const void*p){return U(reinterpret_cast<std::uintptr_t>(p));}
inline U fshead(){U x;asm volatile("movl %%fs:0,%0":"=r"(x));return x;}
inline U fsselector(){unsigned short x;asm volatile("movw %%fs,%0":"=r"(x));return x;}
inline CRITICAL_SECTION*lock(){static_assert(sizeof(CRITICAL_SECTION)==24&&sizeof(void*)==4);return reinterpret_cast<CRITICAL_SECTION*>(std::uintptr_t(address));}
using Raw=std::array<std::uint8_t,24>;
inline Raw bytes(){Raw r{};std::memcpy(r.data(),lock(),r.size());return r;}
struct Event{U kind{},argument{},fs_before{},fs_after{},selector_before{},selector_after{};Raw before{},after{};fp::Image numeric_before{},numeric_after{};};
class Observer {
 using Fn=void(WINAPI*)(LPCRITICAL_SECTION);Fn enter_,leave_;U thread_{};Raw baseline_{};std::array<Event,2>events_{};U count_{};bool active_{};
 inline static Observer*current_{};
 void unowned()const{need(lock()->RecursionCount==0&&lock()->OwningThread==nullptr,"1481 actualCS unowned");}
 void owned()const{need(lock()->RecursionCount==1&&pointer(lock()->OwningThread)==thread_,"1481 actualCS sole-thread ownership");}
 static Fn api(const char*name){auto p=GetProcAddress(GetModuleHandleA("kernel32.dll"),name);need(p!=nullptr,"1481 realKernel32 CS API");return reinterpret_cast<Fn>(p);}
 void call(U kind,U arg){
  need(current_==this&&active_&&arg==address&&count_==kind-1u,"1481 exactCS argument/eventorder");
  Event e;e.kind=kind;e.argument=arg;e.numeric_before=fp::capture_host();fp::restore_host(e.numeric_before);e.before=bytes();e.fs_before=fshead();e.selector_before=fsselector();
  if(kind==1u){unowned();enter_(lock());}else{owned();leave_(lock());}
  e.numeric_after=fp::capture_host();fp::restore_host(e.numeric_after);e.after=bytes();e.fs_after=fshead();e.selector_after=fsselector();
  if(kind==1u)owned();else unowned();events_[count_++]=e;
  //Preserve the actual API result's numeric state across observation bookkeeping.
  fp::restore_host(e.numeric_after);
 }
public:
 Observer():enter_(api("EnterCriticalSection")),leave_(api("LeaveCriticalSection")),thread_(GetCurrentThreadId()){
  need(current_==nullptr,"1481 oneactual fixedlock owner");InitializeCriticalSection(lock());unowned();baseline_=bytes();
 }
 ~Observer(){if(current_==this)current_=nullptr;if(!active_&&lock()->RecursionCount==0)DeleteCriticalSection(lock());}
 Observer(const Observer&)=delete;Observer&operator=(const Observer&)=delete;
 void begin(){need(!active_&&!current_,"1481 observation notnested");unowned();need(bytes()==baseline_,"1481 full24entrystate retained");count_=0;events_={};active_=true;current_=this;}
 void finish(){need(current_==this&&active_&&count_==2,"1481 exactlyEnterthenLeave");unowned();need(bytes()==baseline_,"1481 full24exitstate unchanged");active_=false;current_=nullptr;}
 void enter(U p){call(1,p);}void leave(U p){call(2,p);}
 const std::array<Event,2>&events()const{return events_;}const Raw&baseline()const{return baseline_;}U thread()const{return thread_;}
 U real_enter()const{return pointer(reinterpret_cast<const void*>(enter_));}U real_leave()const{return pointer(reinterpret_cast<const void*>(leave_));}
 static void WINAPI enter_thunk(LPCRITICAL_SECTION p){need(current_!=nullptr,"1481 observedactualEnter context");current_->enter(pointer(p));}
 static void WINAPI leave_thunk(LPCRITICAL_SECTION p){need(current_!=nullptr,"1481 observedactualLeave context");current_->leave(pointer(p));}
};
inline void verify(const std::array<Event,2>&e,const fp::Image&input,const Raw&baseline,U thread){
 for(U k=0;k<2;++k){need(e[k].kind==k+1&&e[k].argument==address,"1481 exactrealCS trace");need(e[k].fs_before==e[k].fs_after&&e[k].selector_before==e[k].selector_after,"1481 actualAPI FSretained");need(fp::same_numeric(e[k].numeric_before,input)&&fp::same_numeric(e[k].numeric_after,input),"1481 actualAPI all80/CW/SW/TOP/tags");}
 need(e[0].before==baseline&&e[1].after==baseline&&e[0].after==e[1].before,"1481 exact24byte CS statechain");
 U recursion=0,owner=0;std::memcpy(&recursion,e[0].after.data()+8,4);std::memcpy(&owner,e[0].after.data()+12,4);need(recursion==1&&owner==thread,"1481 rawCS acquiredstate");
}
}
