#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::com243 {
// Original COM AddRef/Release cross a real Kernel32 boundary. Guest addresses
// translate to the fixture's owned backing storage; results are never supplied.
class Counter {
 using Operation=LONG(WINAPI*)(volatile LONG*);
 volatile LONG* pointer_;unsigned guest_,calls_=0;LONG initial_;
 Operation increment_,decrement_;
 inline static Counter* active_=nullptr;
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
public:
 Counter(volatile LONG*p,unsigned guest):pointer_(p),guest_(guest),initial_(*p){
  static_assert(sizeof(void*)==4,"COM proof requires original x86 IAT width");
  auto kernel=GetModuleHandleW(L"kernel32.dll");
  increment_=reinterpret_cast<Operation>(GetProcAddress(kernel,"InterlockedIncrement"));
  decrement_=reinterpret_cast<Operation>(GetProcAddress(kernel,"InterlockedDecrement"));
  need(increment_&&decrement_&&initial_>0&&initial_<0x7fffffff,"243 valid owned nonterminal COM reference count");
 }
 ~Counter(){if(active_==this)active_=nullptr;}
 void begin(){need(!active_&&*pointer_==initial_,"243 reference prestate");calls_=0;active_=this;}
 void finish(){need(active_==this&&calls_==2&&*pointer_==initial_,"243 balanced authentic QI reference lifecycle");active_=nullptr;}
 static LONG WINAPI increment(volatile LONG*p){need(active_&&p==active_->pointer_&&active_->calls_++==0,"243 AddRef pointer/order");const auto v=active_->increment_(p);need(v==active_->initial_+1,"243 actual AddRef result");return v;}
 static LONG WINAPI decrement(volatile LONG*p){need(active_&&p==active_->pointer_&&active_->calls_++==1,"243 Release pointer/order");const auto v=active_->decrement_(p);need(v==active_->initial_,"243 actual Release result");return v;}
 static unsigned guest_call(unsigned address,bool add){need(active_&&address==active_->guest_,"243 guest COM refcount pointer");return unsigned(add?increment(active_->pointer_):decrement(active_->pointer_));}
 template<class Memory>void bind(Memory&m){need(m.r32(guest_)==unsigned(*pointer_),"243 guest backing storage");m.w32(0x7851bc,unsigned(reinterpret_cast<std::uintptr_t>(&increment)));m.w32(0x7851c0,unsigned(reinterpret_cast<std::uintptr_t>(&decrement)));}
};
}
