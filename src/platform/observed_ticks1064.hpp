#pragma once
#define NOMINMAX
#include <windows.h>
#include <mmsystem.h>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::platform::ticks1064 {
// Actual timeGetTime forwarder. Each stored timestamp is proven against its
// own observed OS return before that field alone is normalized for comparison.
class Tick {
 inline static Tick* active_{};
 std::vector<unsigned> values_;
 static void need(bool x){if(!x)throw std::runtime_error("1064 actual clock provenance");}
public:
 ~Tick(){if(active_==this)active_=nullptr;}
 void begin(){need(!active_);values_.clear();active_=this;}
 static DWORD WINAPI get(){need(active_);const auto v=::timeGetTime();active_->values_.push_back(v);return v;}
 template<class Memory>void bind(Memory&m){static_assert(sizeof(void*)==4);m.w32(0x785524u,unsigned(reinterpret_cast<std::uintptr_t>(&get)));}
 template<class Memory>unsigned finish(Memory&m,const std::vector<unsigned>&addresses){need(active_==this&&values_.size()==addresses.size());active_=nullptr;for(unsigned j=0;j<addresses.size();++j)need(m.r32(addresses[j])==values_[j]);for(auto a:addresses)m.w32(a,0u);return unsigned(values_.size());}
};
}
