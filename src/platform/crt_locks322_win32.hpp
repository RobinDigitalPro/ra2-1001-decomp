#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b322.hpp"
#include <stdexcept>
namespace ra2::platform {
class CrtLocks322 final:public recovered::recovery_b322::Locks {
 recovered::global_b26::Memory& m;
 void call(unsigned slot,unsigned iat){
  if(slot!=2&&slot!=28)throw std::domain_error("322 exact lock slots");
  const auto p=m.r32(0x817278+4*slot),f=m.r32(iat);
  if(!p||!f)throw std::domain_error("322 initialized lock and real import required");
  reinterpret_cast<void(WINAPI*)(LPCRITICAL_SECTION)>(std::uintptr_t(f))(reinterpret_cast<LPCRITICAL_SECTION>(std::uintptr_t(p)));
 }
public:
 explicit CrtLocks322(recovered::global_b26::Memory& memory):m(memory){}
 void enter(unsigned s)override{call(s,0x7851dc);}
 void leave(unsigned s)override{call(s,0x7851e0);}
};
}
