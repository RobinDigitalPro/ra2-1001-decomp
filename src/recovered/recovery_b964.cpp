#include "recovered/recovery_b964.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b964 {
using U=std::uint32_t;
namespace {
constexpr U table=0x0079a20c, index_slot=0x00724f20, advance_slot=0x00724fd0;
U c_string(Memory& m,U object) {
    if(!object) throw std::domain_error("B964 null string object excluded");
    const U p=m.r32(object);
    if(!p) throw std::domain_error("B964 null string data excluded");
    U n=0;
    while(n<31 && m.r8(p+n)!=0) {
        if(m.r8(p+n)>0x7f) throw std::domain_error("B964 non-ASCII excluded");
        ++n;
    }
    if(n==31) throw std::domain_error("B964 string exceeds bound");
    return p;
}
bool equal_ascii(Memory& m,U a,U b) {
    for(U n=0;n<=31;++n) {
        const U x=m.r8(a+n),y=m.r8(b+n);
        if(x!=y)return false;
        if(x==0)return true;
    }
    throw std::domain_error("B964 unterminated string");
}
}
U fun_00724a50(Memory& m,const Inputs& i) {
    const U container=i.cx+0x494u, query_object=i.arg[0];
    const U query=c_string(m,query_object);
    // The original local iterator copies this exact pinned vtable and stores
    // container plus index 0. Resolve both reachable slots from original data.
    if(m.r32(table+4)!=index_slot || m.r32(table+8)!=advance_slot)
        throw std::domain_error("B964 original iterator vtable mismatch");
    const U count=m.r32(container+0x10),items=m.r32(container+4);
    if(count>8)throw std::domain_error("B964 item count exceeds fixture bound");
    for(U index=0;index<count;++index) {
        const U item_object=m.r32(items+index*4u);
        const U item=c_string(m,item_object);
        if(!equal_ascii(m,query,item)) return container;
    }
    return 0;
}
}
