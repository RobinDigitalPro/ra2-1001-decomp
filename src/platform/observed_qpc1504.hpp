#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::qpc1504 {
using U=std::uint32_t;using Q=std::uint64_t;
struct Event{U api_return{};Q raw{};};
// A new explicit sixcounter observer. No modification of qpc1404 modes/guards.
class Six {
 inline static Six* active_{};std::array<Event,6> events_{};U calls_{};
 using Api=BOOL(WINAPI*)(LARGE_INTEGER*);
 static void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
 static Api api(){static auto p=[](){auto m=GetModuleHandleW(L"kernel32.dll");need(m!=nullptr,"1504 actual kernel32");auto f=reinterpret_cast<Api>(GetProcAddress(m,"QueryPerformanceCounter"));need(f!=nullptr,"1504 actual QPC export");return f;}();return p;}
public:
 Six(){static_assert(sizeof(void*)==4,"1504 original x86 IAT");(void)api();}
 ~Six(){if(active_==this)active_=nullptr;}
 Six(const Six&)=delete;Six&operator=(const Six&)=delete;
 void begin(){need(active_==nullptr,"1504 observer already active");events_={};calls_=0;active_=this;}
 static BOOL WINAPI counter(LARGE_INTEGER*out){need(active_&&out&&active_->calls_<6,"1504 exactly six actual counters, no duplicate");const BOOL result=api()(out);active_->events_[active_->calls_++]={U(result),Q(out->QuadPart)};return result;}
 static U address(){return U(reinterpret_cast<std::uintptr_t>(&counter));}
 template<class Memory>void bind(Memory&m){m.w32(0x7851c8,address());}
 static Q quotient(const Event&e,Q d){need(e.api_return!=0&&e.raw>0&&(e.raw>>63)==0&&d>0&&(d>>63)==0,"1504 actual successful positive QPC/divisor");return e.raw/d;}
 template<class Memory,class Heap>std::array<Event,6>finish(Memory&m,const Heap&h,U owner,Q divisor){
  need(active_==this&&calls_==6,"1504 six actual QPC outputs required");active_=nullptr;
  need(m.r32(0x819898)==0x4092e0&&m.r32(0x7851c8)==address(),"1504 original provider/IAT retained");const Q stored=Q(m.r32(0x819878))|(Q(m.r32(0x81987c))<<32);need(stored==divisor,"1504 real QPF divisor retained");
  constexpr U offsets[]{0xf0,0x118,0x140,0x28,0x50,0x78};for(U k=0;k<6;++k){const Q value=Q(h.r32(owner+offsets[k]))|(Q(h.r32(owner+offsets[k]+4))<<32);need(value==quotient(events_[k],divisor),"1504 own stored64bit quotient matches own actual QPC");}return events_;
 }
};
}
