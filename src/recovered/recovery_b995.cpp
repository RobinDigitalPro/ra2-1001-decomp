#include "recovered/recovery_b995.hpp"
#include <stdexcept>

namespace b995_test {
namespace {
void need(bool ok,const char* what){if(!ok)throw std::runtime_error(what);}
}

// RVA 0x135660. The first collection is required to be the genuine empty
// original BSS state, so its optional virtual destructors are not reached.
std::uint32_t fun_00535660(Memory& m,const Inputs&,Heap& h){
    need(m.r32(0x00a56458u)==0u,"B995 first collection must be original empty BSS");
    m.w8(0x007ca268u,0u);
    std::uint32_t count=m.r32(0x00a56488u);
    need(count>=1u&&count<=4u,"B995 second collection count must be 1..4");
    const std::uint32_t array=m.r32(0x00a5647cu);
    need(array!=0u,"B995 owned-buffer queue must be present");
    while(count){
        const std::uint32_t p=m.r32(array);
        need(p!=0u,"B995 queue entries must be owned buffers");
        (void)h.release(p); // Original discards this result and returns EAX=0.
        count=m.r32(0x00a56488u);
        need(count>0u,"B995 queue count changed unexpectedly during HeapFree");
        --count;
        m.w32(0x00a56488u,count);
        for(std::uint32_t j=0;j<count;++j)m.w32(array+j*4u,m.r32(array+(j+1u)*4u));
    }
    m.w8(0x007ca268u,1u);
    return 0u;
}

// RVA 0x2E7CF0. All five buffer ownership flags are set and each pointer is
// a distinct live ordinary-heap allocation. The optional object at +0xC is
// kept at its genuine original BSS null value, avoiding an unresolved vcall.
std::uint32_t fun_006e7cf0(Memory& m,const Inputs&,Heap& h){
    need(m.r32(0x00aa8c0cu)==0u,"B995 optional object must retain original BSS null");
    const std::uint32_t flags[4]={0x00aa8cb8u,0x00aa8cb9u,0x00aa8cbau,0x00aa8cbbu};
    const std::uint32_t fields[4]={0x00aa8bb4u,0x00aa8b28u,0x00aa8ba0u,0x00aa8b44u};
    std::uint32_t eax=0u;
    for(unsigned k=0;k<4;++k){
        need(m.r8(flags[k])!=0u,"B995 all four conditional ownership flags must be set");
        if(k)m.w32(fields[k-1u],0u);
        const std::uint32_t p=m.r32(fields[k]);need(p!=0u,"B995 conditional owned buffer missing");
        eax=h.release(p);m.w8(flags[k],0u);
    }
    const std::uint32_t last=m.r32(0x00aa8c08u);
    need(last!=0u,"B995 unconditional owned buffer missing");
    m.w32(fields[3],0u);
    eax=h.release(last);
    m.w32(0x00aa8c08u,0u);
    return eax;
}
}
