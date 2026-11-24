#include "recovered/recovery_b258.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b258 {
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

std::uint32_t rva_0035b510(Memory& m,const Inputs& i,Heap& h) {
    const auto receiver=i.cx, source_cell=i.arg[0];
    require(receiver && source_cell && receiver!=source_cell && !(i.arithmetic_flags&0x400u),
            "assignment requires receiver, source holder, and DF clear");
    const auto source=m.r32(source_cell);
    require(source && source!=source_cell && source!=receiver,
            "assignment requires a nonnull source resolved from the holder");
    const auto old=m.r32(receiver);
    require(old && old!=source,"assignment requires an owned old allocation distinct from source");
    wide_len_heap(h,old,508u); wide_len_memory(m,source,508u);
    require((h.r8(old)|(h.r8(old+1u)<<8))==u'A' && m.r16(source)==u'B',
            "finite assignment case requires old first unit A and source first unit B");
    const auto free_eax=h.release(old); // actual BOOL/EAX; original ignores it here
    (void)free_eax;
    m.w32(receiver,0u);
    constexpr std::uint32_t bytes=1018u;
    const auto fresh=h.allocate(bytes);
    require(fresh!=0,"success-only assignment requires allocation success");
    m.w32(receiver,fresh);
    put16(h,fresh,0u); // original initializes an empty destination before copy
    for(std::uint32_t n=0;n<=508u;++n) put16(h,fresh+2u*n,m.r16(source+2u*n));
    return receiver; // full EAX=ECX; RET 4
}

std::uint32_t rva_0035b9c0(Memory& m,const Inputs& i,Heap& h) {
    const auto receiver=i.cx, start=i.arg[0], remove=i.arg[1];
    require(receiver && remove==2u && start>=1u && start<=1016u &&
            !(i.arithmetic_flags&0x400u), "remove-span requires start 1..1016, count 2, DF clear");
    const auto old=m.r32(receiver);
    require(old!=0,"remove-span requires an owned old UTF-16 allocation");
    wide_len_heap(h,old,1020u);
    constexpr std::uint32_t new_units=1018u;
    constexpr std::uint32_t request=2038u;
    const auto fresh=h.allocate(request);
    require(fresh!=0,"success-only remove-span requires allocation success");
    put16(h,old+2u*start,0u);
    put16(h,old+2u*(start+remove-1u),0u);
    for(std::uint32_t n=0;n<start;++n) put16(h,fresh+2u*n,
        h.r8(old+2u*n)|(h.r8(old+2u*n+1u)<<8));
    for(std::uint32_t n=start;n<new_units;++n) {
        const auto source_index=n+remove;
        put16(h,fresh+2u*n,h.r8(old+2u*source_index)|(h.r8(old+2u*source_index+1u)<<8));
    }
    put16(h,fresh+2u*new_units,0u);
    const auto free_eax=h.release(old);
    m.w32(receiver,fresh);
    return low16(free_eax,1u); // MOV AX,1 preserves actual EAX upper 16 bits; RET 8
}

}
