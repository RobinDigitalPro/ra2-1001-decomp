#include "recovery_b310.hpp"
#include <array>
#include <cstdint>
#include <limits>
#include <stdexcept>

namespace ra2::recovered::recovery_b310 {
namespace {
void need(bool ok,const char* message) { if(!ok) throw std::domain_error(message); }
std::uint32_t add(std::uint32_t a,std::uint32_t b) {
    need(a<=std::numeric_limits<std::uint32_t>::max()-b,"B310 address arithmetic wraps");
    return a+b;
}
std::uint32_t length(Memory& m,std::uint32_t p) {
    need(p!=0,"B310 pair strings must be nonnull");
    for(std::uint32_t n=0;n<256u;++n)
        if(m.r8(add(p,n))==0) return n;
    throw std::domain_error("B310 string is longer than bounded 255 bytes");
}
}

// The pinned body reads seven {first, second} pointer columns from the table
// rooted at [0x818690], allocates their combined text size plus 15 bytes, and
// writes ':' before each source. The fixture limits each of the fourteen
// source strings to 73 non-NUL bytes, making the sole malloc request exactly
// 1037 bytes and therefore above the observed 1016-byte small-block boundary.
std::uint32_t rva_0037f6c8(Memory& m,const Inputs& in,Heap& h) {
    (void)in; // Exact original body does not read its entry registers or stack words.
    const auto table=m.r32(0x818690u);
    need(table!=0,"B310 requires a mapped seven-pair table at [0x818690]");
    std::array<std::uint32_t,7> first{},second{},first_len{},second_len{};
    std::uint32_t request=1u;
    for(std::uint32_t n=0;n<7u;++n) {
        first[n]=m.r32(add(table,4u*n));
        second[n]=m.r32(add(table,0x1cu+4u*n));
        need(first[n]&&second[n]&&first[n]!=second[n],"B310 requires distinct nonnull source strings");
        first_len[n]=length(m,first[n]); second_len[n]=length(m,second[n]);
        need(first_len[n]==73u&&second_len[n]==73u,"B310 finite fixture requires fourteen 73-byte strings");
        request=add(request,add(add(first_len[n],second_len[n]),2u));
    }
    need(request==1037u&&request>1016u,"B310 fixture must exercise one ordinary-heap request");
    const auto output=h.allocate(request);
    need(output!=0,"B310 route requires successful original malloc");
    auto cursor=output;
    for(std::uint32_t n=0;n<7u;++n) {
        h.w8(cursor,':'); cursor=add(cursor,1u);
        for(std::uint32_t k=0;k<=first_len[n];++k) {
            const auto c=m.r8(add(first[n],k)); h.w8(cursor,c);
            if(k<first_len[n]) cursor=add(cursor,1u);
        }
        h.w8(cursor,':'); cursor=add(cursor,1u);
        for(std::uint32_t k=0;k<=second_len[n];++k) {
            const auto c=m.r8(add(second[n],k)); h.w8(cursor,c);
            if(k<second_len[n]) cursor=add(cursor,1u);
        }
    }
    h.w8(cursor,0u);
    return output;
}
}
