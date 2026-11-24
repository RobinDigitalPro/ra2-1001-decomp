#include "recovered/recovery_b259.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b259 {
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

static std::uint32_t append_bytes(Memory& m,const Inputs& i,Heap& h,
                                  std::uint32_t source,bool update_arg) {
    const auto receiver=i.cx;
    require(receiver && source && !(i.arithmetic_flags&0x400u),
            "append requires receiver, source and DF clear");
    const auto old=m.r32(receiver);
    require(old && old!=source,"append route requires a live owned old string and distinct source");
    byte_len_heap(h,old,1017u); byte_len_memory(m,source,1017u);
    constexpr std::uint32_t request=2035u;
    const auto fresh=h.allocate(request);
    require(fresh!=0,"success-only append requires allocation success");
    m.w32(receiver,fresh); // original publishes before either copy
    for(std::uint32_t n=0;n<=1017u;++n) h.w8(fresh+n,h.r8(old+n));
    for(std::uint32_t n=0;n<=1017u;++n) h.w8(fresh+1017u+n,m.r8(source+n));
    if(update_arg) i.arg[0]=source;
    const auto free_eax=h.release(old);
    return low8(free_eax,1u);
}

std::uint32_t rva_00359640(Memory& m,const Inputs& i,Heap& h) {
    return append_bytes(m,i,h,i.arg[0],false); // AL=1; RET 4
}

std::uint32_t rva_00359850(Memory& m,const Inputs& i,Heap& h) {
    (void)append_bytes(m,i,h,i.arg[0],false);
    return i.cx; // full EAX=receiver; RET 4
}

std::uint32_t rva_00359900(Memory& m,const Inputs& i,Heap& h) {
    const auto source_cell=i.arg[0];
    require(source_cell!=0,"append source holder must be nonnull");
    const auto source=m.r32(source_cell);
    i.arg[0]=source; // Original writes caller arg0 at VA 0x75991a, before scanning.
    const auto result=append_bytes(m,i,h,source,false);
    (void)result;
    return i.cx; // full EAX=receiver; RET 4
}

}
