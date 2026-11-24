#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::platform::locale153 {
// Real Kernel32 exports operate on the backing storage of the declared
// original counter. The observed finite route excludes concurrent locale changes.
class Counter {
 using Operation=LONG(WINAPI*)(volatile LONG*);
 volatile LONG* counter_{};
 Operation increment_{},decrement_{};
 std::vector<LONG> events_;
 unsigned pairs_{};
 inline static Counter* active_{};
 static void require(bool x,const char*s){if(!x)throw std::runtime_error(s);}
public:
 explicit Counter(volatile LONG*p):counter_(p){
  static_assert(sizeof(void*)==4,"original x86 IAT width");
  const auto module=GetModuleHandleW(L"kernel32.dll");require(module!=nullptr,"Kernel32 not loaded");
  increment_=reinterpret_cast<Operation>(GetProcAddress(module,"InterlockedIncrement"));
  decrement_=reinterpret_cast<Operation>(GetProcAddress(module,"InterlockedDecrement"));
  require(increment_&&decrement_&&p&&((reinterpret_cast<std::uintptr_t>(p)&3)==0),"missing atomic exports or unaligned counter");
 }
 ~Counter(){if(active_==this)active_=nullptr;}
 void begin(unsigned pairs){require(!active_&&*counter_==0&&pairs>=1&&pairs<=2,"invalid fresh locale-counter state");pairs_=pairs;events_.clear();active_=this;}
 static LONG WINAPI increment(volatile LONG*p){
  require(active_&&p==active_->counter_&&active_->events_.size()%2==0,"unexpected atomic increment pointer/order");
  const auto result=active_->increment_(p);require(result==1,"actual atomic increment result");active_->events_.push_back(result);return result;
 }
 static LONG WINAPI decrement(volatile LONG*p){
  require(active_&&p==active_->counter_&&active_->events_.size()%2==1,"unexpected atomic decrement pointer/order");
  const auto result=active_->decrement_(p);require(result==0,"actual atomic decrement result");active_->events_.push_back(result);return result;
 }
 static void enter(){require(active_!=nullptr,"locale observer absent");increment(active_->counter_);}
 static void leave(){require(active_!=nullptr,"locale observer absent");decrement(active_->counter_);}
 void finish(){require(active_==this&&events_.size()==2*pairs_&&*counter_==0,"locale atomic pairs/counter mismatch");active_=nullptr;}
 unsigned observed_pairs()const{return unsigned(events_.size()/2);}
 template<class Memory>void bind(Memory&m){
  require(m.r32(0xb10e24)==unsigned(*counter_),"counter backing storage mismatch");
  m.w32(0x7851bc,unsigned(reinterpret_cast<std::uintptr_t>(&increment)));
  m.w32(0x7851c0,unsigned(reinterpret_cast<std::uintptr_t>(&decrement)));
 }
};
}
