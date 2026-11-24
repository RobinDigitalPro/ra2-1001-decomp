#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::platform::mutex149 {
// A process-local test/platform boundary. Every observed operation forwards to
// Kernel32; it never supplies a replacement wait/release result.
class Mutex {
    HANDLE handle_{};
    bool held_{};
    std::vector<unsigned> events_;
    inline static Mutex* active_{};
    static void require(bool v,const char*message){if(!v)throw std::runtime_error(message);}
public:
    Mutex(){static_assert(sizeof(void*)==4,"original x86 handle width");handle_=CreateMutexW(nullptr,FALSE,nullptr);require(handle_!=nullptr,"real mutex creation failed");}
    Mutex(const Mutex&)=delete;
    Mutex&operator=(const Mutex&)=delete;
    ~Mutex(){if(active_==this)active_=nullptr;if(held_)ReleaseMutex(handle_);if(handle_)CloseHandle(handle_);}
    unsigned address()const{return unsigned(reinterpret_cast<std::uintptr_t>(handle_));}
    void begin(){require(!active_&&!held_,"mutex already observed/owned");events_.clear();active_=this;}
    void finish(){
        require(active_==this&&!held_&&events_==std::vector<unsigned>{0x2710,WAIT_OBJECT_0,1},"real mutex event order/result mismatch");
        active_=nullptr;
        // Outside the candidate, prove the one acquire/release pair left no
        // recursive ownership behind. A release by a non-owner must fail.
        SetLastError(ERROR_SUCCESS);
        require(::ReleaseMutex(handle_)==FALSE&&GetLastError()==ERROR_NOT_OWNER,"candidate retained mutex ownership");
    }
    static DWORD WINAPI wait(HANDLE handle,DWORD milliseconds){
        require(active_&&handle==active_->handle_&&!active_->held_&&active_->events_.empty()&&milliseconds==0x2710,"unexpected mutex wait arguments/order");
        const auto result=::WaitForSingleObject(handle,milliseconds);
        require(result==WAIT_OBJECT_0,"real mutex wait did not acquire fresh mutex");
        active_->held_=true;active_->events_={milliseconds,result};return result;
    }
    static BOOL WINAPI release(HANDLE handle){
        require(active_&&handle==active_->handle_&&active_->held_&&active_->events_.size()==2,"unexpected mutex release arguments/order");
        const auto result=::ReleaseMutex(handle);require(result!=FALSE,"real mutex release failed");
        active_->held_=false;active_->events_.push_back(1);return result;
    }
    template<class Memory>void bind(Memory&m){
        m.w32(0xb103f8,address());
        m.w32(0x7851d0,unsigned(reinterpret_cast<std::uintptr_t>(&wait)));
        m.w32(0x785190,unsigned(reinterpret_cast<std::uintptr_t>(&release)));
    }
};
}
