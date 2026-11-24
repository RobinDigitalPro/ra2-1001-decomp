#include "recovered/recovery_b257.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b257 {
using namespace ra2::recovered::recovery42_strings;
namespace {
void require(bool ok, const char* why) { if (!ok) throw std::domain_error(why); }

std::uint32_t low8(std::uint32_t value, std::uint32_t al) {
    return (value & 0xffffff00u) | (al & 0xffu);
}
std::uint32_t low16(std::uint32_t value, std::uint32_t ax) {
    return (value & 0xffff0000u) | (ax & 0xffffu);
}

void check_flags_and_nonalias(const Inputs& i, std::uint32_t object,
                              std::uint32_t old, std::uint32_t fresh) {
    require((i.arithmetic_flags & 0x400u) == 0, "contract requires DF clear");
    require(object && old && fresh && old != fresh && object != old && object != fresh,
            "contract requires nonnull, disjoint fixture regions");
}

std::uint32_t grow_vector(Memory& m, const Inputs& i, Heap& h,
                          std::uint32_t expected_count, std::uint32_t stride) {
    const auto object=i.cx;
    const auto count=m.r32(object), capacity=m.r32(object+4u), old=m.r32(object+8u);
    require(object && count==capacity && count>=expected_count,
            "growth requires a full vector in its selected finite range");
    if (stride==4u) require(count<=400u, "dword growth count exceeds contract");
    else if (stride==24u) require(count<=80u, "record growth count exceeds contract");
    else throw std::logic_error("unsupported draft stride");
    require(old && (i.arithmetic_flags&0x400u)==0, "growth requires live old data and DF clear");
    const std::uint64_t old_bytes=std::uint64_t(count)*stride;
    const std::uint64_t new_bytes=old_bytes*2u;
    require(old_bytes>1016u && new_bytes<=0xffffffe0ull,
            "growth requests must remain in ordinary-heap bounded domain");
    const auto fresh=h.allocate(static_cast<std::uint32_t>(new_bytes));
    require(fresh!=0, "success-only growth route requires allocation success");
    check_flags_and_nonalias(i,object,old,fresh);
    for(std::uint32_t n=0;n<new_bytes;++n) h.w8(fresh+n,0);
    for(std::uint32_t n=0;n<old_bytes;++n) h.w8(fresh+n,h.r8(old+n));
    const auto free_eax=h.release(old);
    m.w32(object+4u,count*2u);
    m.w32(object+8u,fresh);
    return low8(free_eax,1u); // Original writes AL only after actual free.
}

std::uint32_t wide_len_heap(Heap& h, std::uint32_t p, std::uint32_t units) {
    require(p && !(p&1u), "UTF-16 heap string must be nonnull and aligned");
    for(std::uint32_t n=0;n<units;++n)
        require(h.r8(p+2*n) || h.r8(p+2*n+1), "unexpected early UTF-16 NUL");
    require(h.r8(p+2*units)==0 && h.r8(p+2*units+1)==0,
            "UTF-16 terminator outside contracted extent");
    return units;
}
std::uint32_t wide_len_memory(Memory& m, std::uint32_t p, std::uint32_t units) {
    require(p && !(p&1u), "UTF-16 memory string must be nonnull and aligned");
    for(std::uint32_t n=0;n<units;++n) require(m.r16(p+2*n)!=0,"unexpected early UTF-16 NUL");
    require(m.r16(p+2*units)==0,"UTF-16 terminator outside contracted extent");
    return units;
}
std::uint32_t byte_len_heap(Heap& h, std::uint32_t p, std::uint32_t bytes) {
    require(p!=0,"heap byte string must be nonnull");
    for(std::uint32_t n=0;n<bytes;++n) require(h.r8(p+n)!=0,"unexpected early byte NUL");
    require(h.r8(p+bytes)==0,"byte terminator outside contracted extent");
    return bytes;
}
std::uint32_t byte_len_memory(Memory& m, std::uint32_t p, std::uint32_t bytes) {
    require(p!=0,"memory byte string must be nonnull");
    for(std::uint32_t n=0;n<bytes;++n) require(m.r8(p+n)!=0,"unexpected early byte NUL");
    require(m.r8(p+bytes)==0,"byte terminator outside contracted extent");
    return bytes;
}
void put16(Heap& h, std::uint32_t p, std::uint32_t v) {
    h.w8(p,v&255u); h.w8(p+1u,(v>>8)&255u);
}
}

std::uint32_t rva_001f9470(Memory& m,const Inputs& i,Heap& h) {
    return grow_vector(m,i,h,43u,24u);
}

std::uint32_t rva_001f9500(Memory& m,const Inputs& i,Heap& h) {
    const auto object=i.cx;
    const auto count=m.r32(object), capacity=m.r32(object+4u), old=m.r32(object+8u);
    require(object && capacity>=86u && capacity<=160u && count>0u &&
            count<=capacity/3u && old && !(i.arithmetic_flags&0x400u),
            "shrink requires the bounded positive 24-byte vector route");
    const auto next=capacity/2u;
    const auto old_bytes=capacity*24u;
    const auto copy_bytes=count*24u;
    const auto request=next*24u;
    require(old_bytes>1016u && request>1016u && next>=43u,
            "shrink old and new storage must use ordinary-heap route");
    const auto fresh=h.allocate(request);
    require(fresh!=0,"success-only shrink requires allocation success");
    check_flags_and_nonalias(i,object,old,fresh);
    for(std::uint32_t n=0;n<copy_bytes;++n) h.w8(fresh+n,h.r8(old+n));
    const auto free_eax=h.release(old);
    m.w32(object+8u,fresh);
    m.w32(object+4u,next);
    return low8(free_eax,1u);
}

}
