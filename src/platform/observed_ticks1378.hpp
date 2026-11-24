#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::ticks1378 {
// A strict observer of the real WinMM export, never a supplied clock result.
class Tick {
 inline static Tick* active_{};
 unsigned calls_{};std::uint32_t raw_{};
 static void need(bool b,const char* message){if(!b)throw std::runtime_error(message);}
 using Clock=DWORD(WINAPI*)();
 static Clock api(){
  static auto module=LoadLibraryW(L"winmm.dll");need(module!=nullptr,"1378 real WinMM module");
  static auto function=reinterpret_cast<Clock>(GetProcAddress(module,"timeGetTime"));
  need(function!=nullptr,"1378 real timeGetTime export");return function;
 }
public:
 Tick(){static_assert(sizeof(void*)==4,"original x86 IAT pointer width");}
 ~Tick(){if(active_==this)active_=nullptr;}
 Tick(const Tick&)=delete;Tick& operator=(const Tick&)=delete;
 void begin(){need(active_==nullptr,"1378 observer already active");calls_=0;raw_=0;active_=this;}
 static DWORD WINAPI get(){
  need(active_!=nullptr&&active_->calls_==0,"1378 exactly one actual clock call required");
  const DWORD value=api()();active_->raw_=value;++active_->calls_;return value;
 }
 static unsigned address(){return unsigned(reinterpret_cast<std::uintptr_t>(&get));}
 template<class Memory>void bind(Memory& m){m.w32(0x785524u,address());}
 template<class Memory>std::uint32_t finish(Memory& m,unsigned self){
  need(active_==this&&calls_==1,"1378 missing actual clock call");
  need(m.r32(self+0x10u)==(raw_>>4u),"1378 published timestamp differs from its own actual clock result");
  active_=nullptr;return raw_;
 }
};
}
