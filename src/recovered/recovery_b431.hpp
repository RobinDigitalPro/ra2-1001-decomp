#pragma once
#include "global_b26_memory.hpp"
namespace ra2::recovered::recovery_b431 {
using global_b26::Memory; using global_b26::Inputs;
struct FileOps {virtual ~FileOps()=default;virtual bool close(unsigned)=0;virtual bool flush(unsigned)=0;virtual void enter(unsigned)=0;virtual void leave(unsigned)=0;};
unsigned fun_00776691(Memory&,const Inputs&,FileOps&);
unsigned fun_00776c91(Memory&,const Inputs&,FileOps&);
}
