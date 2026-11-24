#include "recovery_b269.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b269 {
namespace {
void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}

std::uint32_t zlen_memory(Memory& m,std::uint32_t p,std::uint32_t limit){
    require(p!=0,"source pointer must be nonnull");
    for(std::uint32_t n=0;n<limit;++n)if(m.r8(p+n)==0)return n;
    throw std::domain_error("source string terminator outside finite route");
}
std::uint32_t zlen_heap(Heap& h,std::uint32_t p,std::uint32_t limit){
    require(p!=0,"owned source pointer must be nonnull");
    for(std::uint32_t n=0;n<limit;++n)if(h.r8(p+n)==0)return n;
    throw std::domain_error("heap string terminator outside finite route");
}
void ensure_disjoint(std::uint32_t receiver,std::uint32_t output,
                     std::uint32_t old,std::uint32_t source,std::uint32_t fresh){
    require(receiver&&output&&old&&source&&fresh,"route requires nonnull pointers");
    require(receiver!=output&&receiver!=old&&receiver!=source&&receiver!=fresh&&
            output!=old&&output!=source&&output!=fresh&&old!=source&&old!=fresh&&
            source!=fresh,"finite route excludes aliased cells and strings");
}

// Direct translation of the positive composition path in 0x7599d0..0x759afc:
// clone the current receiver bytes, append arg1, release that temporary, clear
// and publish a cloned result through arg0, release the combined temporary.
std::uint32_t compose(Memory& m,const Inputs& i,Heap& h,std::uint32_t source){
    const auto receiver=i.cx;
    const auto output=i.arg[0];
    require(receiver&&output&&source,"receiver/output/source must be nonnull");
    require((i.arithmetic_flags&0x400u)==0,"contract requires direction flag clear");
    const auto old=m.r32(receiver);
    require(old!=0,"finite positive route requires a nonnull current receiver string");
    const auto old_length=zlen_heap(h,old,4096u);
    const auto source_length=zlen_memory(m,source,4096u);
    const std::uint64_t prefix_bytes=std::uint64_t(old_length)+1u;
    const std::uint64_t combined_bytes=std::uint64_t(old_length)+source_length+1u;
    require(prefix_bytes>1016u&&combined_bytes>1016u&&combined_bytes<=0xffffffe0ull,
            "all composition allocations must stay on bounded ordinary-heap route");

    auto prefix=h.allocate(static_cast<std::uint32_t>(prefix_bytes));
    require(prefix!=0,"success-only prefix allocation required");
    ensure_disjoint(receiver,output,old,source,prefix);
    for(std::uint32_t n=0;n<prefix_bytes;++n)h.w8(prefix+n,h.r8(old+n));

    auto joined=h.allocate(static_cast<std::uint32_t>(combined_bytes));
    require(joined!=0,"success-only concatenation allocation required");
    ensure_disjoint(receiver,output,old,source,joined);
    require(joined!=prefix,"separate live allocation identities required");
    for(std::uint32_t n=0;n<old_length;++n)h.w8(joined+n,h.r8(prefix+n));
    for(std::uint32_t n=0;n<=source_length;++n)h.w8(joined+old_length+n,m.r8(source+n));
    require(h.release(prefix)!=0,"actual prefix free must succeed");

    // The original clears [arg0] before allocating/copying the final clone.
    m.w32(output,0u);
    auto result=h.allocate(static_cast<std::uint32_t>(combined_bytes));
    require(result!=0,"success-only result allocation required");
    ensure_disjoint(receiver,output,old,source,result);
    require(result!=joined,"separate live allocation identities required");
    m.w32(output,result);
    for(std::uint32_t n=0;n<combined_bytes;++n)h.w8(result+n,h.r8(joined+n));
    require(h.release(joined)!=0,"actual joined-buffer free must succeed");
    return output;
}
}

std::uint32_t rva_003599d0(Memory& m,const Inputs& i,Heap& h){
    return compose(m,i,h,i.arg[1]);
}

std::uint32_t rva_00359b00(Memory& m,const Inputs& i,Heap& h){
    const auto holder=i.arg[1];
    require(holder!=0,"finite route requires a nonnull source-holder cell");
    auto source=m.r32(holder);
    if(source==0)source=0x8248a4u; // Exact original selected literal bytes below.
    require(i.arg[1]==holder,"entry holder address unexpectedly changed");
    i.arg[1]=source;
    return compose(m,i,h,source);
}
}

