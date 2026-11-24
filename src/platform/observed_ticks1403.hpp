#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include "recovered/global_b26_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::ticks1403 {
// B1378 observer extended only for B1403's two genuine WinMM events.
// No supplied clock value, clock emulation or change to the shared observer.
class Tick {
 using Memory=ra2::recovered::global_b26::Memory;
 inline static Tick* active_{};
 Memory* memory_{};std::uint32_t self_{},serialized620_{};
 unsigned calls_{};std::array<std::uint32_t,2> raw_{};
 static void need(bool b,const char* message){if(!b)throw std::runtime_error(message);}
 using Clock=DWORD(WINAPI*)();
 static Clock api(){
  static auto module=LoadLibraryW(L"winmm.dll");need(module!=nullptr,"1403 real WinMM module");
  static auto function=reinterpret_cast<Clock>(GetProcAddress(module,"timeGetTime"));
  need(function!=nullptr,"1403 real timeGetTime export");return function;
 }
 void phase()const{
  need(memory_!=nullptr&&calls_<2,"1403 exactly two actual clock calls");
  const auto& m=*memory_;
  need(m.r32(self_+0x614u)==0xffffffffu,"1403 clock order requires serialized paused timer");
  need(m.r8(self_+0x218u)==0u&&m.r32(self_+0x21cu)==0u&&m.r32(self_+0x220u)==103u,
       "1403 first actual clock follows real RNG reseed");
  if(calls_==0u)need(m.r32(self_+0x620u)==serialized620_,"1403 first clock precedes620 publication");
  else{
   need(m.r32(self_+0x620u)==(raw_[0]>>4u)&&m.r32(self_+0x628u)==0u,
        "1403 second clock follows first clock publication");
   need(m.r32(self_+0x7d4u)==0x82208cu&&m.r32(self_+0x2264u)==0u&&
        m.r32(self_+0x2280u)==0u&&m.r32(self_+0x229cu)==0u,
        "1403 second clock follows exact empty reconstruction");
  }
 }
public:
 Tick(){static_assert(sizeof(void*)==4,"original x86 IAT pointer width");}
 ~Tick(){if(active_==this)active_=nullptr;}
 Tick(const Tick&)=delete;Tick& operator=(const Tick&)=delete;
 void begin(Memory& m,std::uint32_t self,std::uint32_t serialized620){
  need(active_==nullptr,"1403 observer already active");memory_=&m;self_=self;serialized620_=serialized620;calls_=0;raw_={};active_=this;
 }
 static DWORD WINAPI get(){
  need(active_!=nullptr,"1403 observer not active");active_->phase();
  const DWORD value=api()();active_->raw_[active_->calls_++]=value;return value;
 }
 static unsigned address(){return unsigned(reinterpret_cast<std::uintptr_t>(&get));}
 template<class M>void bind(M& m){m.w32(0x785524u,address());}
 std::array<std::uint32_t,2> finish(Memory& m,std::uint32_t self){
  need(active_==this&&calls_==2u&&memory_==&m&&self_==self,"1403 exact two-event observer identity");
  need(m.r32(self+0x620u)==(raw_[0]>>4u),"1403 first timestamp differs from own real API result");
  need(m.r32(self+0x614u)==(raw_[1]>>4u),"1403 resumed timestamp differs from own real API result");
  active_=nullptr;return raw_;
 }
};
}
