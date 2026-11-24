#include "recovered/recovery_b392.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b392 {
namespace {
std::uint32_t byte_length(const Heap& h,std::uint32_t p) {
    std::uint32_t n=0;
    while(h.r8(p+n)!=0u) ++n;
    return n;
}
std::uint32_t wide_length(const Heap& h,std::uint32_t p) {
    std::uint32_t n=0;
    while(h.r8(p+n*2u)!=0u || h.r8(p+n*2u+1u)!=0u) ++n;
    return n;
}
bool byte_in_set(const Memory& m,std::uint32_t set,std::uint32_t ch) {
    for(std::uint32_t p=set;;++p) {
        const auto v=m.r8(p);
        if(v==0u) return false;
        if(v==(ch&0xffu)) return true;
    }
}
bool wide_in_set(const Memory& m,std::uint32_t set,std::uint32_t ch) {
    for(std::uint32_t p=set;;p+=2u) {
        const auto v=m.r16(p);
        if(v==0u) return false;
        if(v==(ch&0xffffu)) return true;
    }
}
std::uint32_t allocate(Heap& h,std::uint32_t bytes) {
    const auto p=h.allocate(bytes);
    if(!p) throw std::runtime_error("B392 ordinary HeapAlloc failed; success-only positive route");
    return p;
}
void release(Heap& h,std::uint32_t p) {
    if(h.release(p)!=1u) throw std::runtime_error("B392 actual HeapFree failed");
}
void copy_bytes(Heap& h,std::uint32_t d,std::uint32_t s,std::uint32_t n) {
    for(std::uint32_t k=0;k<n;++k) h.w8(d+k,h.r8(s+k));
}
void copy_wide(Heap& h,std::uint32_t d,std::uint32_t s,std::uint32_t units) {
    for(std::uint32_t k=0;k<units;++k) {
        h.w8(d+2u*k,h.r8(s+2u*k));
        h.w8(d+2u*k+1u,h.r8(s+2u*k+1u));
    }
}
}

// Original VA 0x75ab40. Positive route: a nonempty byte token is extracted
// between the first non-set character at/after arg0 and the next set member.
std::uint32_t fun_0075ab40(Memory& m,const Inputs& i,Heap& h) {
    const auto source_slot=i.cx;
    const auto out_slot=i.arg[2];
    const auto index=i.arg[0];
    const auto set=i.arg[1];
    if(static_cast<std::int32_t>(index)<0) return 0xffffffffu;
    const auto source=m.r32(source_slot);
    const auto length=source?byte_length(h,source):0u;
    if(index>=length) return 0xffffffffu;

    auto first=index;
    while(first<length&&byte_in_set(m,set,h.r8(source+first))) ++first;
    if(first>=length) return 0xffffffffu;
    auto end=first;
    while(end<length&&!byte_in_set(m,set,h.r8(source+end))) ++end;
    if(end>=length) return 0xffffffffu;
    const auto token_length=end-first;
    i.arg[0]=first;i.arg[1]=end-1u;

    const auto prior=m.r32(out_slot);
    if(prior) release(h,prior);
    m.w32(out_slot,0u);

    // The original first copies the full suffix through its NUL to this
    // temporary before extracting the token into the next allocation.
    const auto suffix_bytes=length-first+1u;
    auto suffix=allocate(h,suffix_bytes);
    m.w32(out_slot,suffix);
    copy_bytes(h,suffix,source+first,suffix_bytes);

    const auto token_bytes=token_length+1u;
    const auto token=allocate(h,token_bytes);
    h.w8(token,0u);
    copy_bytes(h,token,suffix,token_length);
    h.w8(token+token_length,0u);
    release(h,m.r32(out_slot));
    m.w32(out_slot,0u);

    const auto result=allocate(h,token_bytes);
    m.w32(out_slot,result);
    h.w8(result,0u);
    copy_bytes(h,result,token,token_bytes);
    release(h,token);
    // Original overwrote callerarg1 with end-1 before loading it here.
    return end;
}

// Original VA 0x75c690. Positive route: skip delimiter-set code units,
// then extract the following nonempty UTF-16 token through the next member.
std::uint32_t fun_0075c690(Memory& m,const Inputs& i,Heap& h) {
    const auto source_slot=i.cx;
    const auto index=i.arg[0];
    const auto set=i.arg[1];
    const auto out_slot=i.arg[2];
    if(static_cast<std::int32_t>(index)<0) return 0xffffffffu;
    const auto source=m.r32(source_slot);
    const auto length=source?wide_length(h,source):0u;
    if(index>=length) return 0xffffffffu;

    auto first=index;
    while(first<length&&wide_in_set(m,set,
          h.r8(source+first*2u)|(h.r8(source+first*2u+1u)<<8u))) ++first;
    if(first>=length) return 0xffffffffu;
    auto end=first;
    while(end<length&&!wide_in_set(m,set,
          h.r8(source+end*2u)|(h.r8(source+end*2u+1u)<<8u))) ++end;
    if(end>=length) return 0xffffffffu;
    const auto token_units=end-first;
    i.arg[0]=end-1u;

    const auto prior=m.r32(out_slot);
    if(prior) release(h,prior);
    m.w32(out_slot,0u);

    const auto suffix_units=length-first+1u;
    const auto suffix_bytes=suffix_units*2u;
    auto suffix=allocate(h,suffix_bytes);
    m.w32(out_slot,suffix);
    copy_wide(h,suffix,source+first*2u,suffix_units);

    const auto token_bytes=(token_units+1u)*2u;
    auto token=allocate(h,token_bytes);
    h.w8(token,0u);h.w8(token+1u,0u);
    copy_wide(h,token,suffix,token_units);
    h.w8(token+token_units*2u,0u);h.w8(token+token_units*2u+1u,0u);
    release(h,m.r32(out_slot));
    m.w32(out_slot,0u);

    auto result=allocate(h,token_bytes);
    m.w32(out_slot,result);
    h.w8(result,0u);h.w8(result+1u,0u);
    copy_wide(h,result,token,token_units+1u);
    release(h,token);
    // Original overwrote callerarg0 with end-1 before loading it here.
    return end;
}
}
