#include "recovery_b267.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b267 {
std::uint32_t fun_00588140(Memory& m,const Inputs& i,Heap& h) {
    m.w32(i.cx+8,0); m.w32(i.cx,4);
    const auto p=h.allocate(32);
    if(!p)throw std::domain_error("188140 bounded successful first32 allocation");
    for(unsigned k=0;k<4;++k){h.w32(p+k*8,0);h.w32(p+k*8+4,0xffffffffu);}
    m.w32(i.cx+4,p);
    for(unsigned k=0;k<4;++k){
        h.w32(p+k*8,m.r32(i.arg[k]));
        h.w32(p+k*8+4,m.r32(i.arg[k]+4));
    }
    return i.cx;
}
}
