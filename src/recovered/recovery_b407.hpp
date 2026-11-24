#pragma once
#include "global_b26_memory.hpp"
namespace ra2::recovered::recovery_b407 {
using global_b26::Memory;using global_b26::Inputs;
struct FileOps {
 virtual ~FileOps()=default;
 virtual void enter(unsigned)=0;virtual void leave(unsigned)=0;
 virtual unsigned seek(unsigned,unsigned,unsigned)=0;
 virtual bool read(unsigned,unsigned,unsigned,unsigned&)=0;
 virtual bool write(unsigned,unsigned,unsigned,unsigned&)=0;
 virtual bool truncate(unsigned)=0;
};
unsigned fun_00774404(Memory&,const Inputs&,FileOps&);
unsigned fun_0077497a(Memory&,const Inputs&,FileOps&);
unsigned fun_0077f302(Memory&,const Inputs&,FileOps&);
unsigned fun_00782ac8(Memory&,const Inputs&,FileOps&);
}
