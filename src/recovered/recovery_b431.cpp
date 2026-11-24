#include "recovery_b431.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b431 {
static unsigned descriptor(Memory&m,unsigned fd){if(fd<3||fd>=m.r32(0xb10e00))throw std::runtime_error("B431 descriptor contract");auto d=m.r32(0xb10d00+4*(fd/32))+36*(fd%32);if(!(m.r8(d+4)&1)||m.r32(d)==0xffffffff)throw std::runtime_error("B431 open descriptor");return d;}
unsigned fun_00776691(Memory&m,const Inputs&i,FileOps&o){auto d=descriptor(m,i.arg[0]);if(!o.close(m.r32(d)))throw std::runtime_error("B431 CloseHandle success required");m.w32(d,0xffffffff);m.w8(d+4,0);return 0;}
unsigned fun_00776c91(Memory&m,const Inputs&i,FileOps&o){auto d=descriptor(m,i.arg[0]);if(!m.r32(d+8))throw std::runtime_error("B431 initialized lock required");o.enter(d+12);bool ok=o.flush(m.r32(d));o.leave(d+12);if(!ok)throw std::runtime_error("B431 FlushFileBuffers success required");return 0;}
}
