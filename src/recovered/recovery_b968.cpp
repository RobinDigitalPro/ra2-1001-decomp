#include "recovery_b968.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b968 {
using U=std::uint32_t;
U fun_0062dff0(Memory& m,const Inputs& i) {
    // Exact bounded success edge: arg0==2 and nonnull target is already in
    // the receiver's +0xCC pointer array. The original returns immediately
    // on the first equal entry, before helper 0x40DC20 or vtable slot +0x17C.
    if(i.arg[0]!=2u || !i.arg[2])
        throw std::domain_error("B968 only supports arg0=2 and nonnull existing target");
    const U array=m.r32(i.cx+0xccu), count=m.r32(i.cx+0xd0u);
    if(!array || count==0 || count>32)
        throw std::domain_error("B968 array/count outside bounded fixture");
    for(U n=0;n<count;++n)
        if(m.r32(array+4u*n)==i.arg[2]) return 1u;
    throw std::domain_error("B968 target absent; insertion and dispatch paths excluded");
}
}
