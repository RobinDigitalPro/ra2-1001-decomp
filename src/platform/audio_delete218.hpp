#pragma once
#define NOMINMAX
#include <windows.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform::audio218 {
// Translate only the fixed guest lock address; initialize/delete a real OS lock.
class Lock {
 CRITICAL_SECTION host_{};bool live_=true;unsigned deletes_=0;
 inline static Lock* active_=nullptr;
 static void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
 static unsigned address(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
public:
 Lock(){static_assert(sizeof(void*)==4,"218 x86 import");::InitializeCriticalSection(&host_);need(host_.RecursionCount==0&&host_.OwningThread==nullptr,"218 initial ownership");}
 Lock(const Lock&)=delete;Lock&operator=(const Lock&)=delete;
 ~Lock(){if(active_==this)active_=nullptr;if(live_)::DeleteCriticalSection(&host_);}
 void begin(){need(!active_&&live_&&!deletes_,"218 invalid lock lifetime");active_=this;}
 void finish(){need(active_==this&&!live_&&deletes_==1,"218 missing real deletion");active_=nullptr;}
 static void WINAPI erase(LPCRITICAL_SECTION guest){
  need(active_&&address(guest)==0x8198d0&&active_->live_&&!active_->deletes_,"218 guest or repeated delete");
  need(active_->host_.RecursionCount==0&&active_->host_.OwningThread==nullptr,"218 deleting owned lock");
  ::DeleteCriticalSection(&active_->host_);active_->live_=false;++active_->deletes_;
 }
 template<class Memory>void bind(Memory&m){m.w32(0x7851d8,address(reinterpret_cast<const void*>(&erase)));}
 static void delete_guest(unsigned guest){erase(reinterpret_cast<LPCRITICAL_SECTION>(std::uintptr_t(guest)));}
};
}
