#include "recovered/buffer_b84.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::buffer_b84 {
namespace {
using global_b26::s32;
constexpr std::uint64_t address_end = 0x100000000ull;
[[noreturn]] void outside(const char* message) { throw std::domain_error(message); }
void span(std::uint32_t p, std::uint64_t n, const char* message) {
    if (!p || std::uint64_t(p) + n > address_end) outside(message);
}
bool overlaps(std::uint64_t a, std::uint64_t an, std::uint64_t b, std::uint64_t bn) {
    return a < b + bn && b < a + an;
}
void disjoint(std::uint32_t a, std::uint64_t an, std::uint32_t b, std::uint64_t bn,
              const char* message) {
    if (overlaps(a, an, b, bn)) outside(message);
}
void descriptor(std::uint32_t p, std::uint32_t bytes = 0x14u) {
    span(p, bytes, "Block84 descriptor span wraps or is null");
}

// The resize bodies share their broad control flow, but their instruction-level
// initialization footprints differ. `zero_words` lists only full DWORD stores;
// `zero_bytes` lists only byte stores. Copy remains after initialization.
std::uint32_t resize(Memory& m, const Inputs& in, std::uint32_t stride,
                     const std::uint32_t* zero_words, unsigned word_count,
                     const std::uint32_t* zero_bytes, unsigned byte_count,
                     bool count_prefix, bool low_byte_result, std::uint32_t bound) {
    const auto c=in.cx, n=in.arg[0], raw=in.arg[1];
    if (!n || n > bound || !raw) outside("Block84 resize requires bounded positive count and supplied buffer");
    descriptor(c);
    const auto base=count_prefix ? raw+4u : raw;
    const std::uint64_t bytes=std::uint64_t(n)*stride;
    span(raw, bytes+(count_prefix?4u:0u), "Block84 resize storage wraps");
    disjoint(c,0x14u,raw,bytes+(count_prefix?4u:0u),"Block84 resize buffer overlaps descriptor");
    const auto old=m.r32(c+4u), old_count=m.r32(c+8u);
    if (!old || m.r8(c+0x0du)!=0u) outside("Block84 resize requires borrowed non-null old storage");
    if (s32(old_count)<0 || old_count>bound || old_count!=n) outside("Block84 resize requires equal bounded old and new counts");
    const auto copied=old ? std::min(n,old_count) : 0u;
    if (old && copied) {
        span(old,std::uint64_t(copied)*stride,"Block84 old source wraps");
        disjoint(c,0x14u,old,std::uint64_t(copied)*stride,"Block84 old source overlaps descriptor");
        disjoint(old,std::uint64_t(copied)*stride,base,bytes,
                 "Block84 source/destination overlap excluded");
    }
    m.w8(c+0x0cu,0u);
    if (count_prefix) m.w32(raw,n);
    for (std::uint32_t j=0;j<n;++j) {
        const auto q=base+j*stride;
        for (unsigned k=0;k<word_count;++k) m.w32(q+zero_words[k],0u);
        for (unsigned k=0;k<byte_count;++k) m.w8(q+zero_bytes[k],0u);
    }
    m.w8(c+0x0cu,1u);
    for (std::uint32_t j=0;j<copied;++j) {
        if (stride==3u) {
            m.w16(base+j*stride,m.r16(old+j*stride));
            m.w8(base+j*stride+2u,m.r8(old+j*stride+2u));
        } else {
            for (std::uint32_t d=0;d<stride;d+=4u) m.w32(base+j*stride+d,m.r32(old+j*stride+d));
        }
    }
    m.w32(c+4u,base);m.w32(c+8u,n);
    if (s32(n)<s32(m.r32(c+0x10u)))m.w32(c+0x10u,n);
    m.w8(c+0x0du,0u);
    return low_byte_result ? ((n&0xffffff00u)|1u) : 1u;
}

void init_header(Memory& m, std::uint32_t c, std::uint32_t n,
                 std::uint32_t tag, std::uint32_t descriptor_size=0x14u) {
    descriptor(c,descriptor_size);
    m.w32(c+4u,0u);m.w32(c+8u,n);m.w8(c+0x0cu,1u);m.w8(c+0x0du,0u);m.w32(c,tag);
}
void supplied(Memory& m, std::uint32_t c, std::uint32_t n, std::uint32_t p,
              std::uint32_t bytes, std::uint32_t descriptor_size=0x14u) {
    span(p,bytes,"Block84 caller-supplied storage wraps or is null");
    disjoint(c,descriptor_size,p,bytes,"Block84 caller storage overlaps descriptor");
}
std::uint32_t init_16_counted(Memory& m,const Inputs& i) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(!n||n>8u||!p)outside("Block84 0xc2190 requires count 1..8 and supplied storage");
    init_header(m,c,n,0x78c1d0u);supplied(m,c,n,p,std::uint64_t(n)*16u);
    for(std::uint32_t j=0;j<n;++j){const auto q=p+j*16u;m.w32(q,0);m.w32(q+4u,0);m.w8(q+8u,0);m.w32(q+12u,0);}
    m.w32(c+4u,p);return c;
}
std::uint32_t init_3byte_tail(Memory& m,const Inputs& i,std::uint32_t initial_tag,
                              std::uint32_t final_tag,std::uint32_t count_limit,
                              std::uint32_t desc_size) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(!n||n>count_limit||!p)outside("Block84 three-byte initializer requires bounded supplied storage");
    init_header(m,c,n,initial_tag,desc_size);supplied(m,c,n,p,std::uint64_t(n)*3u,desc_size);
    for(std::uint32_t j=0;j<n;++j){const auto q=p+j*3u;m.w8(q,0);m.w8(q+1u,0);m.w8(q+2u,0);}
    m.w32(c+4u,p);
    if(final_tag){m.w32(c,final_tag);m.w32(c+0x14u,10u);m.w32(c+0x10u,0u);}
    return c;
}
std::uint32_t init_8_partial(Memory& m,const Inputs& i,std::uint32_t tag,
                             std::uint32_t max_count) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(!n||n>max_count||!p)outside("Block84 partial 8-byte initializer requires bounded supplied storage");
    init_header(m,c,n,tag);supplied(m,c,n,p,std::uint64_t(n)*8u);
    for(std::uint32_t j=0;j<n;++j){const auto q=p+j*8u;m.w32(q,0);m.w8(q+4u,0);}
    m.w32(c+4u,p);return c;
}
std::uint32_t init_16_sentinel(Memory& m,const Inputs& i) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(n>32u)outside("Block84 0x169980 count bound exceeded");
    init_header(m,c,n,0x7909f8u);
    if(n){supplied(m,c,n,p,std::uint64_t(n)*16u);for(std::uint32_t j=0;j<n;++j){const auto q=p+j*16u;
        m.w16(q,0);m.w16(q+2u,0);m.w16(q+4u,0);m.w16(q+6u,0);m.w8(q+8u,0);m.w32(q+12u,0xffffffffu);}}
    if(n&&p)m.w32(c+4u,p);return c;
}
std::uint32_t init_8_full(Memory& m,const Inputs& i) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(n>32u)outside("Block84 0x295820 count bound exceeded");
    init_header(m,c,n,0x797224u);
    if(n){supplied(m,c,n,p,std::uint64_t(n)*8u);for(std::uint32_t j=0;j<n;++j){const auto q=p+j*8u;m.w32(q,0);m.w32(q+4u,0);}}
    if(n&&p)m.w32(c+4u,p);return c;
}
} // namespace

std::uint32_t fun_0046d530(Memory&m,const Inputs&i){constexpr std::uint32_t b[]={0,1,2};return resize(m,i,3,nullptr,0,b,3,false,true,512u);}
std::uint32_t fun_004c1fa0(Memory&m,const Inputs&i){constexpr std::uint32_t w[]={0,4,12};constexpr std::uint32_t b[]={8};return resize(m,i,16,w,3,b,1,false,true,512u);}
std::uint32_t fun_004c2190(Memory&m,const Inputs&i){return init_16_counted(m,i);}
std::uint32_t fun_004ce400(Memory&m,const Inputs&i){constexpr std::uint32_t w[]={4};return resize(m,i,8,w,1,nullptr,0,true,true,512u);}
std::uint32_t fun_004f6770(Memory&m,const Inputs&i){
    const auto c=i.cx,source=i.arg[0],index=i.arg[1];descriptor(c,0x18u);
    const auto data=m.r32(c+4u),capacity=m.r32(c+8u),length=m.r32(c+0x10u);
    if(!data||!capacity||!length||length>8u||length>=capacity||
       s32(index)!=s32(length-1u))
        outside("Block84 0xf6770 only supports the direct append route");
    span(data,std::uint64_t(length+1u)*16u,"Block84 append destination wraps");span(source,16u,"Block84 append source wraps");
    disjoint(c,0x18u,data,std::uint64_t(length+1u)*16u,"Block84 append array overlaps descriptor");
    disjoint(source,16u,data,std::uint64_t(length+1u)*16u,"Block84 append source overlaps array");
    for(unsigned d=0;d<16;d+=4)m.w32(data+length*16u+d,m.r32(source+d));
    m.w32(c+0x10u,length+1u);return 1u;
}
std::uint32_t fun_004f6d40(Memory&m,const Inputs&i){constexpr std::uint32_t w[]={0};constexpr std::uint32_t b[]={4};return resize(m,i,8,w,1,b,1,false,true,512u);}
std::uint32_t fun_004f7fe0(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];if(!n||n>4096u||!p)outside("Block84 0xf7fe0 requires 1..4096 supplied records");
    init_header(m,c,n,0x78de84u);supplied(m,c,n,p,std::uint64_t(n)*8u);
    for(std::uint32_t j=0;j<n;++j){m.w32(p+j*8u,0);m.w32(p+j*8u+4u,0);}m.w32(c+4u,p);return c;
}
std::uint32_t fun_00568120(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],target=i.arg[1];if(!n||n>32u||!target)outside("Block84 0x168120 requires positive count and supplied target");
    descriptor(c);supplied(m,c,n,target,std::uint64_t(n)*16u);const auto old=m.r32(c+4u),old_count=m.r32(c+8u);
    if(s32(old_count)<0||old_count>32u||m.r8(c+0x0du)!=0u)outside("Block84 0x168120 borrowed-source contract violated");
    if(!old&&old_count!=0u)outside("Block84 0x168120 null source requires zero old count");
    const auto copied=old?std::min(n,old_count):0u;
    if(old&&copied){span(old,std::uint64_t(copied)*16u,"Block84 0x168120 old source wraps");disjoint(c,0x14u,old,std::uint64_t(copied)*16u,"Block84 source overlaps descriptor");disjoint(old,std::uint64_t(copied)*16u,target,std::uint64_t(n)*16u,"Block84 source/target overlap excluded");}
    m.w8(c+0x0cu,0u);
    // The call at 0x568190 receives ECX=record+4 and two literal zero stack
    // arguments. Accepted 0x2ad30 writes two zero halfwords at that address.
    for(std::uint32_t j=0;j<n;++j){const auto q=target+j*16u;m.w16(q,0);m.w16(q+2u,0);m.w16(q+4u,0);m.w16(q+6u,0);m.w8(q+8u,0);m.w32(q+12u,0xffffffffu);}
    m.w8(c+0x0cu,1u);
    for(std::uint32_t j=0;j<copied;++j)for(unsigned d=0;d<16;d+=4)m.w32(target+j*16u+d,m.r32(old+j*16u+d));
    m.w32(c+4u,target);m.w32(c+8u,n);if(s32(n)<s32(m.r32(c+0x10u)))m.w32(c+0x10u,n);m.w8(c+0x0du,0u);return (n&0xffffff00u)|1u;
}
std::uint32_t fun_00569840(Memory&m,const Inputs&i){return init_8_partial(m,i,0x78576cu,32u);}
std::uint32_t fun_00569980(Memory&m,const Inputs&i){return init_16_sentinel(m,i);}
std::uint32_t fun_005fcdd0(Memory&m,const Inputs&i){return init_3byte_tail(m,i,0x792bb8u,0x792b18u,16u,0x18u);}
std::uint32_t fun_005fd030(Memory&m,const Inputs&i){constexpr std::uint32_t b[]={0,1,2};return resize(m,i,3,nullptr,0,b,3,false,true,512u);}
std::uint32_t fun_005fd980(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];if(n>32u)outside("Block84 0x1fd980 count bound exceeded");init_header(m,c,n,0x792bb8u);
    if(n){if(!p)outside("Block84 0x1fd980 positive count requires supplied storage");supplied(m,c,n,p,std::uint64_t(n)*3u);for(std::uint32_t j=0;j<n;++j){const auto q=p+j*3u;m.w8(q,0);m.w8(q+1u,0);m.w8(q+2u,0);}m.w32(c+4u,p);}return c;
}
std::uint32_t fun_00619b30(Memory&m,const Inputs&i){return init_3byte_tail(m,i,0x788a54u,0x7935c4u,32u,0x18u);}
std::uint32_t fun_0062c6b0(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];if(!n||n>32u||!p)outside("Block84 0x22c6b0 requires bounded supplied storage");
    init_header(m,c,n,0x7937e4u,0x18u);supplied(m,c,n,p,std::uint64_t(n)*16u,0x18u);
    for(std::uint32_t j=0;j<n;++j){const auto q=p+j*16u;m.w32(q,0);m.w32(q+4u,0);m.w32(q+8u,0);}
    m.w32(c+4u,p);m.w32(c,0x7937c4u);m.w32(c+0x14u,10u);m.w32(c+0x10u,0u);return c;
}
std::uint32_t fun_00695820(Memory&m,const Inputs&i){return init_8_full(m,i);}
std::uint32_t fun_0071a700(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];if(!n||n>32u||!p)outside("Block84 0x31a700 requires bounded supplied storage");
    init_header(m,c,n,0x799e3cu,0x10u);supplied(m,c,n,p,4u+std::uint64_t(n)*12u,0x10u);m.w32(p,n);
    for(std::uint32_t j=0;j<n;++j){const auto q=p+4u+j*12u;m.w32(q,0);m.w32(q+4u,0);m.w32(q+8u,0);}m.w32(c+4u,p+4u);return c;
}
} // namespace ra2::recovered::buffer_b84
