#include "recovered/recovery_b932.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b932 {
std::uint32_t fun_0044C2C0(Memory& m, const Inputs& i) {
    const std::uint32_t owner=i.cx;
    const std::uint32_t table=m.r32(owner);
    const std::uint32_t type=m.r32(owner+0x418u);
    const std::uint32_t config=m.r32(0x821b88u);
    if(table!=0x787bbcu || m.r32(table+0x84u)!=0x4538b0u || !type || !config)
        throw std::domain_error("HF authentic getter route");
    const std::uint32_t denominator=m.r32(type+0xa0u);
    if(!denominator || denominator>0x7fffffffu || m.r32(owner+0x6cu)==denominator)
        throw std::domain_error("HF bounded positive health update");
    if(m.r8(owner+0x5b6u)!=0 || m.r32(owner+0x268u)!=0)
        throw std::domain_error("HF cleanup/virtual dispatch excluded");
    for(std::uint32_t off=0x454u;off<=0x498u;off+=4u)
        if(m.r32(owner+off)!=0) throw std::domain_error("HF empty tracked slots required");
    if(m.r32(type+0x119cu)!=static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(m.r8(owner+0x5c6u)))))
        throw std::domain_error("HF equal signed status sentinel required");
    if(type==m.r32(config+0x78cu))
        throw std::domain_error("HF section-name update path excluded");

    for(std::uint32_t off:{0xda0u,0xde4u,0xe28u,0xe6cu})if(m.r8(type+off))throw std::domain_error("932 empty optional name buffers");
    m.w32(owner+0x6cu,denominator);
    const std::uint64_t threshold=std::uint64_t(m.r32(config+0x1368u)) |
                                  (std::uint64_t(m.r32(config+0x136cu))<<32u);
    i.fp.load_integer32(denominator);
    const std::uint64_t numerator=i.fp.pop64();
    i.fp.load_integer32(denominator);
    ra2::platform::x87_scalar_b46::reverse_divide64(i.fp,numerator);
    i.fp.compare_pop64(threshold);
    // Both comparison outcomes converge because owner+0x268 is null.
    m.w8(owner+0x75u,1u);
    // Each null slot computes the next name pointer in EAX; the last is type+E6C.
    return (type+0xe6cu)&0xffffff00u;
}
}
