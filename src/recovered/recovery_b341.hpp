#pragma once
#include "recovered/global_b26_memory.hpp"
namespace ra2::recovered::recovery_b341 {
using Memory=global_b26::Memory;using Inputs=global_b26::Inputs;
struct Locks {virtual ~Locks()=default;virtual void enter(unsigned)=0;virtual void leave(unsigned)=0;};
unsigned fun_00408f50(Memory&,const Inputs&,Locks&);
}
