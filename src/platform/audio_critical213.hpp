#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::platform::audio213 {
// The original fixed address denotes a real test-owned OS lock here. Only
// address translation occurs; every enter/leave forwards to Kernel32.
class Lock {
    CRITICAL_SECTION host_{};
    std::vector<unsigned> events_;
    inline static Lock* active_{};
    static void need(bool ok,const char* text){if(!ok)throw std::runtime_error(text);}
    static unsigned address(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
    void unowned()const{need(host_.RecursionCount==0&&host_.OwningThread==nullptr,"audio lock retains ownership");}
public:
    Lock(){static_assert(sizeof(void*)==4,"audio original x86 import width");::InitializeCriticalSection(&host_);unowned();}
    Lock(const Lock&)=delete;Lock&operator=(const Lock&)=delete;
    ~Lock(){if(active_==this)active_=nullptr;while(host_.RecursionCount>0)::LeaveCriticalSection(&host_);::DeleteCriticalSection(&host_);}
    void begin(){need(!active_,"audio lock observation already active");unowned();events_.clear();active_=this;}
    void finish(){need(active_==this&&events_==std::vector<unsigned>{1,2},"audio enter/leave order mismatch");unowned();active_=nullptr;}
    static void WINAPI enter(LPCRITICAL_SECTION guest){
        need(active_&&address(guest)==0x8198d0&&active_->events_.empty(),"audio enter guest address/order mismatch");
        active_->unowned();::EnterCriticalSection(&active_->host_);
        need(active_->host_.RecursionCount==1&&address(active_->host_.OwningThread)==::GetCurrentThreadId(),"audio enter did not acquire real lock");
        active_->events_.push_back(1);
    }
    static void WINAPI leave(LPCRITICAL_SECTION guest){
        need(active_&&address(guest)==0x8198d0&&active_->events_==std::vector<unsigned>{1},"audio leave guest address/order mismatch");
        need(active_->host_.RecursionCount==1&&address(active_->host_.OwningThread)==::GetCurrentThreadId(),"audio leave ownership mismatch");
        ::LeaveCriticalSection(&active_->host_);active_->unowned();active_->events_.push_back(2);
    }
    template<class Memory>void bind(Memory&m){m.w32(0x7851dc,address(reinterpret_cast<const void*>(&enter)));m.w32(0x7851e0,address(reinterpret_cast<const void*>(&leave)));}
};
}
