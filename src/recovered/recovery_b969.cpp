#include "recovered/recovery_b969.hpp"
#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include "platform/ole_stream951.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b969 {
using U=std::uint32_t;
namespace ole=ra2::platform::ole_stream951;
void read_exact(IStream*s,void*p,ULONG n){if(s->Read(p,n,nullptr)!=S_OK)throw std::domain_error("B969 successful complete IStream Read only");}
void insert_first(Memory&m,U slot){const U value=m.r32(slot);if(!value)return;const U count=m.r32(0xaa5384u),cap=m.r32(0xaa537cu),data=m.r32(0xaa5378u);if(count>=cap)throw std::domain_error("B969 preallocated first registry");m.w32(0xaa5384u,count+1u);m.w32(data+8u*count,value);m.w32(data+8u*count+4u,slot);m.w32(slot,0u);}
void insert_heap(Memory&m,Heap&h,U slot){const U value=h.r32(slot);if(!value)return;const U count=m.r32(0xaa5384u),cap=m.r32(0xaa537cu),data=m.r32(0xaa5378u);if(count>=cap)throw std::domain_error("969 preallocated registry");m.w32(0xaa5384u,count+1);m.w32(data+8*count,value);m.w32(data+8*count+4,slot);h.w32(slot,0);}
void insert_second(Memory&m,U id,U receiver){const U count=m.r32(0xaa539cu),cap=m.r32(0xaa5394u),data=m.r32(0xaa5390u);if(count>=cap)throw std::domain_error("B969 preallocated second registry");m.w32(data+8u*count,id);m.w32(data+8u*count+4u,receiver);m.w32(0xaa539cu,count+1u);}
void initialize_embedded(Memory&m,U p){m.w32(p,0);m.w32(p+4u,0);m.w32(p+8u,0);m.w32(p+0xcu,0x008192ecu);}
U fun_0062e200(Memory&m,const Inputs&i,Heap&h){
    const U receiver=i.arg[0],stream=i.arg[1];
    if(!receiver||!stream||i.cx!=receiver)throw std::domain_error("B969 ECX receiver and nonnull IStream args required");
    if(m.r32(receiver)!=0x007938a8u||m.r32(0x007938a8u+0x30u)!=0x004b85d0u)
        throw std::domain_error("B969 original constructor/table +0x30 provenance mismatch");
    if(m.r32(0x007857fcu+8u)!=0x0040b8b0u)throw std::domain_error("B969 original vector slot +8 provenance mismatch");
    if(stream!=ole::Stream::current().address())throw std::domain_error("969 genuine stream");
    auto*s=reinterpret_cast<IStream*>(std::uintptr_t(stream));
    U id=0;read_exact(s,&i.arg[1],4u);id=i.arg[1];
    // B969 composes the already recovered 0x1CCDF0/0x10120 route: register
    // {serialized ID, receiver}, register four nonzero receiver slots, apply
    // the exact embedded-field initializer, then clear receiver+0x94.
    insert_second(m,id,receiver);
    // 0x10120 dispatches receiver vtable slot +0x30 (pinned target returns
    // EAX=0), then performs the original successful zero-byte IStream Read.
    read_exact(s,reinterpret_cast<void*>(std::uintptr_t(receiver)),0u);
    for(const U off:{0x30u,0x34u,0x38u,0x18u})insert_first(m,receiver+off);
    initialize_embedded(m,receiver+0x3cu);initialize_embedded(m,receiver+0x50u);m.w32(receiver+0x94u,0);
    m.w32(receiver+0xc8u,0x007857fcu);m.w32(receiver+0xccu,0);m.w32(receiver+0xd0u,0);m.w8(receiver+0xd4u,1);m.w8(receiver+0xd5u,0);
    U count=0;read_exact(s,&i.arg[1],4u);count=i.arg[1];if(count<1u||count>8u)throw std::domain_error("B969 count outside 1..8 contract");
    const U bytes=count*4u,allocation=h.allocate(bytes);if(!allocation)throw std::domain_error("B969 successful ordinary-heap allocation only");
    m.w32(receiver+0xccu,allocation);m.w32(receiver+0xd0u,count);m.w8(receiver+0xd5u,1);
    for(U n=0;n<count;++n){read_exact(s,&i.arg[0],4u);h.w32(allocation+4u*n,i.arg[0]);}
    for(U n=0;n<count;++n)insert_heap(m,h,allocation+4u*n);
    return 0u;
}
}
