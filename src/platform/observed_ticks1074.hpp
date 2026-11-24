#pragma once
#define NOMINMAX
#include <windows.h>
#include <mmsystem.h>
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::ticks1074{
// Clone of accepted1064 actual API observer, fixed to this route's three calls.
// No supplied/common clock or replacement return enters either candidate.
class Tick{inline static Tick*active_{};std::array<unsigned,3>values_{};unsigned count_{};static void need(bool v){if(!v)throw std::domain_error("1074 actual three-clock observation");}
public:~Tick(){if(active_==this)active_=nullptr;}void begin(){need(!active_);count_=0u;active_=this;}
 static DWORD WINAPI get(){need(active_&&active_->count_<3u);const auto value=::timeGetTime();active_->values_[active_->count_++]=value;return value;}
 std::array<unsigned,3>finish(){need(active_==this&&count_==3u);active_=nullptr;return values_;}
 template<class Memory>void bind(Memory&m){static_assert(sizeof(void*)==4u);const auto api=GetProcAddress(GetModuleHandleA("WINMM.dll"),"timeGetTime");need(api&&m.r32(0x785524u)==unsigned(reinterpret_cast<std::uintptr_t>(api)));m.w32(0x785524u,unsigned(reinterpret_cast<std::uintptr_t>(&get)));}
};
}
