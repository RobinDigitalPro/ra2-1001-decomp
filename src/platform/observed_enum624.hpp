#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::enum624 {
// This boundary invokes the actual x86 Kernel32 export on the fixture's
// backing counter. It checks every pointer, order and returned count.
class References {
 using Operation=LONG(WINAPI*)(volatile LONG*);
 std::array<volatile LONG*,10> counters_{};
 std::array<LONG,10> initial_{};
 unsigned guest_,first_,expected_,count_,calls_=0;
 Operation increment_;
 inline static References* active_=nullptr;
 static void need(bool ok,const char*s){if(!ok)throw std::runtime_error(s);}
public:
 References(std::uint8_t*backing,unsigned guest,unsigned first,unsigned expected,unsigned count):guest_(guest),first_(first),expected_(expected),count_(count){
  static_assert(sizeof(void*)==4,"Original COM ABI requires x86");
  need(count<=10&&first+expected<=count,"624 bounded reference array");
  increment_=reinterpret_cast<Operation>(GetProcAddress(GetModuleHandleW(L"kernel32.dll"),"InterlockedIncrement"));need(increment_!=nullptr,"624 real Kernel32 export");
  for(unsigned k=0;k<count;++k){counters_[k]=reinterpret_cast<volatile LONG*>(backing+0x8000+k*0x100+0x14);initial_[k]=*counters_[k];need(initial_[k]>0&&initial_[k]<100000,"624 nonterminal real counters");}
 }
 ~References(){if(active_==this)active_=nullptr;}
 void begin(){need(!active_,"624 no nested observer");for(unsigned k=0;k<count_;++k)need(*counters_[k]==initial_[k],"624 exact reference prestate");calls_=0;active_=this;}
 void finish(){need(active_==this&&calls_==expected_,"624 complete AddRef sequence");for(unsigned k=0;k<count_;++k)need(*counters_[k]==initial_[k]+LONG(k>=first_&&k<first_+expected_),"624 complete counter image");active_=nullptr;}
 static LONG WINAPI increment(volatile LONG*p){need(active_&&active_->calls_<active_->expected_,"624 unexpected AddRef");auto&a=*active_;const unsigned k=a.first_+a.calls_;need(p==a.counters_[k],"624 actual counter pointer/order");const LONG result=a.increment_(p);need(result==a.initial_[k]+1,"624 actual atomic result");++a.calls_;return result;}
 static unsigned guest_call(unsigned address){need(active_,"624 missing observer");const unsigned k=active_->first_+active_->calls_;need(k<active_->count_&&address==active_->guest_+0x8000+k*0x100+0x14,"624 translated counter pointer/order");return unsigned(increment(active_->counters_[k]));}
 static unsigned address(){return unsigned(reinterpret_cast<std::uintptr_t>(&increment));}
 template<class Memory>void bind(Memory&m){m.w32(0x7851bc,address());}
};
}
