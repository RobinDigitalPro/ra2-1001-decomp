#include "recovery_b596.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b596{
// RVA303DA0; reached raw304010,12D0A0 and actualCRT allocation.
std::uint32_t fun_00703da0(Memory& m,const Inputs& i,Heap& heap) {
    const auto self=i.cx, vec=self+0x0cu;
    auto dirty=m.r32(self+8u);
    if(dirty!=0xffffffffu) {
        if(dirty>=m.r32(self))throw std::runtime_error("B596 fixture dirty index exceeds old logical length");
        const auto old=m.r32(self+0x10u), bit=dirty;
        const auto byte_address=old+(bit>>3u);
        const auto mask=std::uint8_t(1u<<(bit&7u));
        auto v=m.r8(byte_address);
        if(m.r8(self+4u))v|=mask;else v&=std::uint8_t(~mask);
        m.w8(byte_address,v);
        m.w32(self+8u,0xffffffffu);
    }
    const auto requested_bits=i.arg[0];
    if(requested_bits==0 || requested_bits>=m.r32(self))
        throw std::runtime_error("B596 bounded route requires a nonzero shrink");
    const auto new_bytes=(requested_bits+7u)>>3u;
    if(new_bytes!=3u || m.r32(vec+8u)!=3u || m.r8(vec+0x0du)!=0u)
        throw std::runtime_error("B596 fixture escaped one-allocation borrowed 3-byte shrink");

    // Exact 304010 positive route: null replacement argument forces the real
    // CRT allocator, then the byte loop copies min(new_bytes, old_bytes).
    m.w8(vec+0x0cu,0u);
    const auto replacement=heap.allocate(new_bytes);
    if(!replacement)throw std::runtime_error("B596 request-3 allocation failed");
    const auto count=std::min(new_bytes,m.r32(vec+8u));
    const auto prior=m.r32(vec+4u);
    for(std::uint32_t k=0;k<count;++k)heap.w8(replacement+k,static_cast<std::uint8_t>(m.r8(prior+k)));
    m.w32(vec+4u,replacement); m.w32(vec+8u,new_bytes);
    m.w8(vec+0x0cu,1u); m.w8(vec+0x0du,1u);

    m.w32(self,requested_bits);
    i.arg[0]=1u; // original MOV [ESP+0x10],EAX writes entry stack word zero
    return i.arg[0];
}

}
