#pragma once
#define NOMINMAX
#include <windows.h>
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::ticks636 {
class Tick {
 inline static Tick* active_{};
 std::array<std::uint32_t,2> values_{};unsigned calls_{};
 static void need(bool x,const char*s){if(!x)throw std::runtime_error(s);}
 using Clock=DWORD(WINAPI*)();
 static Clock api(){static auto module=LoadLibraryW(L"winmm.dll");need(module,"636 WinMM load");static auto fn=reinterpret_cast<Clock>(GetProcAddress(module,"timeGetTime"));need(fn,"636 actual clock export");return fn;}
public:
 ~Tick(){if(active_==this)active_=nullptr;}
 void begin(){need(!active_,"636 observer already active");calls_=0;active_=this;}
 static DWORD WINAPI get(){need(active_&&active_->calls_<2,"636 unexpected clock call");const auto v=api()();active_->values_[active_->calls_++]=v;return v;}
 static unsigned address(){return unsigned(reinterpret_cast<std::uintptr_t>(&get));}
 template<class M>void bind(M&m){m.w32(0x785524,address());}
 template<class M>std::array<std::uint32_t,2> finish(M&m,unsigned p){need(active_==this&&calls_==2,"636 exactly two actual calls required");active_=nullptr;need(m.r32(p+0x14fc)==(values_[0]>>4)&&m.r32(p+0x151c)==(values_[1]>>4),"636 stored clock fields disagree with own actual observations");return values_;}
};
}
