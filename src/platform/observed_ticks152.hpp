#pragma once
#define NOMINMAX
#include <windows.h>
#include <mmsystem.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::ticks152 {
// Records actual OS return values. No supplied clock value or replacement
// result enters either original or recovered execution.
class Tick {
 inline static Tick* active_{};
 unsigned calls_{},value_{};
 static void require(bool x,const char*s){if(!x)throw std::runtime_error(s);}
public:
 Tick(){static_assert(sizeof(void*)==4,"original x86 IAT width");}
 ~Tick(){if(active_==this)active_=nullptr;}
 void begin(){require(!active_,"tick observer already active");calls_=0;active_=this;}
 static DWORD WINAPI get(){
  require(active_&&active_->calls_==0,"unexpected/multiple timeGetTime calls");
  const auto result=::timeGetTime();active_->value_=result;++active_->calls_;return result;
 }
 template<class Memory>unsigned finish(Memory&m,unsigned address){
  require(active_==this&&calls_==1,"missing actual timeGetTime call");active_=nullptr;
  require(m.r32(address)==value_,"stored timestamp differs from observed actual API result");return value_;
 }
 unsigned finish(){
  require(active_==this&&calls_==1,"missing actual timeGetTime call");active_=nullptr;return value_;
 }
 template<class Memory>void bind(Memory&m){m.w32(0x785524,unsigned(reinterpret_cast<std::uintptr_t>(&get)));}
};
}
