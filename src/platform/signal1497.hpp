#pragma once
#include "recovered/recovery_b1497.hpp"
#include <array>
#include <cstddef>
#include <stdexcept>
extern "C" unsigned signal1497_event_count;
namespace ra2::recovered::b1497::signal {
namespace fp=ra2::platform::x87;
inline void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
inline U address(const void*p){return U(std::uintptr_t(p));}
template<class T>inline U code(T p){return U(std::uintptr_t(p));}
inline U fs_head(){U x;asm volatile("movl %%fs:0,%0":"=r"(x));return x;}
inline U fs_selector(){unsigned short x;asm volatile("movw %%fs,%0":"=r"(x));return x;}
struct Event {U kind,pointer,thread,recursion,owner,lock_count,fs,selector;fp::Image before,after;};
struct alignas(16) Callback {
 std::array<U,8>gpr{};U flags{},return_pc{},argument{},entry_sp{};
 fp::Image before{};U fs{},selector{},slot{},recursion{},owner{},lock_count{},events{};
 fp::Image after{};U after_fs{},after_selector{},count{};
 std::array<U,8>after_gpr{};U after_flags{},exit_sp{};
};
static_assert(offsetof(Callback,before)==48&&offsetof(Callback,fs)==160&&offsetof(Callback,after)==192,"1497 raw assembly layout");
class Context;
inline Context*active=nullptr;
class Context {
 CRITICAL_SECTION cs_{};Memory*memory_{};volatile U*effect_{};U*slot_{};U signal_{},thread_{};
 std::array<Event,4>events_{};U event_count_{};bool entered_{},fault_{};
 static void WINAPI enter_thunk(LPCRITICAL_SECTION p){need(active&&p==&active->cs_,"1497 exact actual lock identity");auto&c=*active;const auto pre=fp::capture_host();const U fs=fs_head(),sel=fs_selector();::EnterCriticalSection(p);const auto post=fp::capture_host();c.record(1,p,pre,post,fs,sel);fp::restore_host(post);}
 static void WINAPI leave_thunk(LPCRITICAL_SECTION p){need(active&&p==&active->cs_,"1497 exact actual unlock identity");auto&c=*active;const auto pre=fp::capture_host();const U fs=fs_head(),sel=fs_selector();::LeaveCriticalSection(p);const auto post=fp::capture_host();c.record(2,p,pre,post,fs,sel);fp::restore_host(post);}
 void record(U kind,LPCRITICAL_SECTION p,const fp::Image&pre,const fp::Image&post,U fs,U sel){
  need(event_count_<4&&fs==fs_head()&&sel==fs_selector(),"1497 bounded real lock/FS events");
  if(kind==1){need(!entered_&&p->RecursionCount==1&&address(p->OwningThread)==thread_,"1497 real critical section owned");entered_=true;}
  else{need(entered_&&p->RecursionCount==0&&p->OwningThread==nullptr&&p->LockCount==-1,"1497 real critical section released");entered_=false;}
  events_[event_count_++]={kind,address(p),thread_,U(p->RecursionCount),address(p->OwningThread),U(p->LockCount),fs,sel,pre,post};signal1497_event_count=event_count_;
 }
public:
 Callback callback{};
 Context(){need(!active,"1497 exclusive real lock context");InitializeCriticalSection(&cs_);thread_=GetCurrentThreadId();}
 ~Context(){if(active==this)active=nullptr;DeleteCriticalSection(&cs_);}
 void begin(Memory&m,volatile U*effect,U*slot,U sig);
 void end(){need(active==this&&!entered_&&event_count_==4&&!fault_&&cs_.RecursionCount==0&&cs_.OwningThread==nullptr&&cs_.LockCount==-1,"1497 complete two actual lock pairs");active=nullptr;}
 void bind(Memory&m){m.w32(0x81727c,address(&cs_));m.w32(0x7851dc,code(&enter_thunk));m.w32(0x7851e0,code(&leave_thunk));}
 void enter(Memory&m){need(&m==memory_&&m.r32(0x81727c)==address(&cs_),"1497 typed same exact slot1");enter_thunk(&cs_);}
 void leave(Memory&m){need(&m==memory_&&m.r32(0x81727c)==address(&cs_),"1497 typed same exact slot1 unlock");leave_thunk(&cs_);}
 bool unowned()const{return !entered_&&cs_.RecursionCount==0&&cs_.OwningThread==nullptr&&cs_.LockCount==-1;}
 U events()const{return event_count_;}const auto&trace()const{return events_;}U sig()const{return signal_;}Memory&memory(){return*memory_;}
 U*slot()const{return slot_;}volatile U*effect()const{return effect_;}CRITICAL_SECTION&critical(){return cs_;}
 void fault(){fault_=true;}
};
inline Context&context(){need(active,"1497 active actual signal context");return*active;}
U handler_address();
}
extern "C" {
extern ra2::recovered::b1497::signal::Callback* signal1497_observation;
extern volatile unsigned*signal1497_effect;
extern unsigned*signal1497_slot;
extern long*signal1497_recursion;
extern void**signal1497_owner;
extern long*signal1497_lock_count;
extern unsigned signal1497_event_count;
void __cdecl signal1497_handler(int);
}
