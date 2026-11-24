#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
#include <vector>
namespace ra2::platform::mutex1412 {
class Mutex {
 HANDLE h_{}; unsigned depth_{}; std::vector<unsigned> events_; inline static Mutex* active_{};
 static void require(bool b,const char*m){if(!b)throw std::runtime_error(m);}
public:
 Mutex(){static_assert(sizeof(void*)==4);h_=CreateMutexW(nullptr,FALSE,nullptr);require(h_!=nullptr,"mutex creation");}
 Mutex(const Mutex&)=delete; Mutex& operator=(const Mutex&)=delete;
 ~Mutex(){if(active_==this)active_=nullptr;while(depth_){ReleaseMutex(h_);--depth_;}if(h_)CloseHandle(h_);}
 unsigned address()const{return unsigned(reinterpret_cast<std::uintptr_t>(h_));}
 void begin(){require(!active_&&!depth_,"observer already active");active_=this;events_.clear();}
 void finish(){require(active_==this&&!depth_&&events_==std::vector<unsigned>{10000,WAIT_OBJECT_0,10000,WAIT_OBJECT_0,1,1},"mutex sequence/result");active_=nullptr;SetLastError(ERROR_SUCCESS);require(::ReleaseMutex(h_)==FALSE&&GetLastError()==ERROR_NOT_OWNER,"retained mutex ownership");}
 static DWORD WINAPI wait(HANDLE h,DWORD ms){require(active_&&h==active_->h_&&active_->depth_<2&&ms==10000,"unexpected wait");const DWORD r=::WaitForSingleObject(h,ms);require(r==WAIT_OBJECT_0,"fresh recursive mutex wait failed");++active_->depth_;active_->events_.push_back(ms);active_->events_.push_back(r);return r;}
 static BOOL WINAPI release(HANDLE h){require(active_&&h==active_->h_&&active_->depth_&&active_->events_.size()>=4,"unexpected release");BOOL r=::ReleaseMutex(h);require(r!=FALSE,"real release failed");--active_->depth_;active_->events_.push_back(r);return r;}
 template<class M>void bind(M&m){m.w32(0xb103f8u,address());m.w32(0x7851d0u,unsigned(reinterpret_cast<std::uintptr_t>(&wait)));m.w32(0x785190u,unsigned(reinterpret_cast<std::uintptr_t>(&release)));}
};
}
