#include "recovered/buffer_b73.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
namespace {
constexpr std::uint64_t address_end = 0x100000000ull;
[[noreturn]] void outside(const char* what) { throw std::domain_error(what); }

void require_span(std::uint32_t p, std::uint64_t bytes, const char* what) {
    if (!p || std::uint64_t(p) + bytes > address_end) outside(what);
}

// The direct supplied-buffer branch shared by the selected vector bodies.
// The branch guards intentionally exclude allocation, ownership release,
// zero-count virtual dispatch, and partial source/destination overlap.
std::uint32_t resize_copy(Memory& m, const Inputs& i, unsigned stride,
                          bool clamp_high_water, bool count_residue,
                          bool overwrite_count_argument) {
    const auto object = i.cx;
    const auto count = i.arg[0];
    const auto destination = i.arg[1];
    if (s32(count) <= 0 || count > 512u || !destination)
        outside("Block73 supplied-buffer route requires count 1..512 and non-null storage");
    require_span(object, 0x14u, "Block73 descriptor wraps address space");
    require_span(destination, std::uint64_t(count) * stride, "Block73 destination wraps address space");
    const auto old_pointer = m.r32(object + 4u);
    const auto old_count = m.r32(object + 8u);
    if (old_pointer && m.r8(object + 0x0du) != 0u)
        outside("Block73 owned-buffer release branch excluded");
    if (old_pointer && (s32(old_count) < 0 || old_count > 512u))
        outside("Block73 old count outside bounded contract");
    const auto copied = old_pointer ? std::min(count, old_count) : 0u;
    const std::uint64_t dst0 = destination, dst1 = dst0 + std::uint64_t(count) * stride;
    const std::uint64_t src0 = old_pointer, src1 = src0 + std::uint64_t(copied) * stride;
    const std::uint64_t obj0 = object, obj1 = obj0 + 0x14u;
    if ((dst0 < obj1 && obj0 < dst1) ||
        (old_pointer && copied && (src1 > address_end || (src0 < obj1 && obj0 < src1))))
        outside("Block73 descriptor overlap or wrapping source excluded");
    if (old_pointer && copied && old_pointer != destination && dst0 < src1 && src0 < dst1)
        outside("Block73 partial source/destination overlap excluded");

    // MOV [this+0xc],0 then the success flag is observable even if the old
    // and new pointers alias. Copying is forward and each record is dwordwise.
    m.w8(object + 0x0cu, 0u);
    m.w8(object + 0x0cu, 1u);
    for (std::uint32_t n = 0; n < copied; ++n)
        for (unsigned d = 0; d < stride; d += 4u)
            m.w32(destination + n * stride + d, m.r32(old_pointer + n * stride + d));
    m.w32(object + 4u, destination);
    m.w32(object + 8u, count);
    m.w8(object + 0x0du, 0u);
    if (clamp_high_water && s32(count) < s32(m.r32(object + 0x10u)))
        m.w32(object + 0x10u, count);
    if (overwrite_count_argument) i.arg[0] = count - 1u;
    return count_residue ? ((count & 0xffffff00u) | 1u) : 1u;
}

void require_init(std::uint32_t count, std::uint32_t storage,
                  std::uint32_t stride, std::uint32_t prefix,
                  std::uint32_t limit = 128u) {
    if (!count || count > limit || !storage)
        outside("Block73 initializer requires bounded positive count and supplied storage");
    require_span(storage, std::uint64_t(prefix) + std::uint64_t(count) * stride,
                 "Block73 supplied array wraps address space");
}

// Concrete accepted leaf effects used by the tagged and record initializers.
void initialize_tagged_entry(Memory& m, std::uint32_t p, std::uint32_t tag) {
    m.w32(p + 4u, 0u);       // accepted 0x630a80 helper effect
    m.w32(p, 0x793cccu);     // accepted 0x630a80 tag, overwritten by caller
    m.w32(p, tag);           // caller's subsequent immediate store
}
void initialize_zero_word(Memory& m, std::uint32_t p) {
    m.w32(p, 0u); // accepted 0x759250 helper
}
void initialize_zero_byte(Memory& m, std::uint32_t p) {
    m.w8(p, 0u); // accepted 0xe07c0 helper
}

std::uint32_t make_3byte(Memory& m, const Inputs& i) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,0x788a54u);
    if (!n) return c;
    require_init(n,p,3u,0u,32u);
    for(std::uint32_t j=0;j<n;++j){m.w8(p+3u*j,0);m.w8(p+3u*j+1u,0);m.w8(p+3u*j+2u,0);}
    m.w32(c+4u,p);return c;
}

std::uint32_t make_counted_zero_second(Memory& m,const Inputs& i,std::uint32_t tag) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,tag);
    if (!n) return c;
    require_init(n,p,8u,4u);
    m.w32(p,n);
    for(std::uint32_t j=0;j<n;++j) m.w32(p+4u+j*8u+4u,0);
    m.w32(c+4u,p+4u);m.w32(c,0x78c7fcu);m.w32(c+0x14u,10u);m.w32(c+0x10u,0u);return c;
}

std::uint32_t make_tagged(Memory& m,const Inputs& i,std::uint32_t tag,
                          std::uint32_t descriptor_tag,std::uint32_t limit=128u) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,descriptor_tag);
    if (!n) return c;
    require_init(n,p,8u,4u,limit);
    m.w32(p,n);
    for(std::uint32_t j=0;j<n;++j) initialize_tagged_entry(m,p+4u+j*8u,tag);
    m.w32(c+4u,p+4u);return c;
}
std::uint32_t make_tagged_preserving_first(Memory& m,const Inputs& i) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,0x78dfacu);
    if(!n)return c;
    require_init(n,p,8u,4u);m.w32(p,n);
    for(std::uint32_t j=0;j<n;++j)m.w32(p+8u+j*8u,0u);
    m.w32(c+4u,p+4u);return c;
}

std::uint32_t make_fixed8(Memory& m,const Inputs& i,std::uint32_t tag,
                          bool counted,bool full_dword_zero) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,tag);
    if (!n) return c;
    require_init(n,p,8u,counted?4u:0u,32u);
    const auto base=counted?p+4u:p;
    if(counted)m.w32(p,n);
    for(std::uint32_t j=0;j<n;++j){const auto q=base+j*8u;
        m.w32(q,0u);m.w8(q+4u,0u);
        if(full_dword_zero){m.w8(q+5u,0u);m.w8(q+6u,0u);m.w8(q+7u,0u);}}
    m.w32(c+4u,base);
    return c;
}

std::uint32_t make_12byte(Memory& m,const Inputs& i) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,0x790af8u);
    if(!n)return c;
    require_init(n,p,12u,4u);
    for(std::uint32_t j=0;j<n;++j){const auto q=p+4u+j*12u;m.w32(q,0);m.w8(q+4u,0);}
    m.w32(c+4u,p);return c;
}

std::uint32_t make_104byte(Memory& m,const Inputs& i,bool tail) {
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,0x792b98u);
    if(n){require_init(n,p,0x104u,0u,64u);
        for(std::uint32_t j=0;j<n;++j)initialize_zero_byte(m,p+j*0x104u);
        m.w32(c+4u,p);}
    if(tail){m.w32(c,0x792b38u);m.w32(c+0x14u,10u);m.w32(c+0x10u,0u);}
    return c;
}
} // namespace

std::uint32_t fun_0040b9f0(Memory&m,const Inputs&i){return resize_copy(m,i,4u,true,true,false);}
std::uint32_t fun_0042d050(Memory&m,const Inputs&i){return resize_copy(m,i,4u,true,true,true);}
std::uint32_t fun_0045eac0(Memory&m,const Inputs&i){return resize_copy(m,i,12u,false,false,false);}
std::uint32_t fun_0046d890(Memory&m,const Inputs&i){return make_3byte(m,i);}
std::uint32_t fun_004ce2f0(Memory&m,const Inputs&i){return make_counted_zero_second(m,i,0x78c7d4u);}
std::uint32_t fun_004f6a10(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(!n||n>512u||!p)outside("Block73 0xf6a10 requires positive supplied array");
    require_span(c,0x14u,"Block73 0xf6a10 descriptor wraps");
    require_init(n,p,8u,0u,512u);const auto old=m.r32(c+4u),old_count=m.r32(c+8u);
    if(!old)outside("Block73 0xf6a10 selected route requires non-null old storage");
    if(old && m.r8(c+0x0du)!=0u)outside("Block73 0xf6a10 owned release branch excluded");
    if(old && (s32(old_count)<0||old_count>512u))outside("Block73 0xf6a10 old count outside bound");
    if(old && old_count!=n)outside("Block73 0xf6a10 selected route requires equal positive counts");
    require_span(old,std::uint64_t(n)*8u,"Block73 0xf6a10 old array wraps");
    if(old&&std::uint64_t(old)<std::uint64_t(p)+std::uint64_t(n)*8u&&std::uint64_t(p)<std::uint64_t(old)+std::uint64_t(std::min(n,old_count))*8u)
        outside("Block73 0xf6a10 partial array overlap excluded");
    m.w8(c+0x0cu,0);
    for(std::uint32_t j=0;j<n;++j){m.w32(p+j*8u,0);m.w32(p+j*8u+4u,0);}
    for(std::uint32_t j=0;j<(old?std::min(n,old_count):0u);++j){m.w32(p+j*8u,m.r32(old+j*8u));m.w32(p+j*8u+4u,m.r32(old+j*8u+4u));}
    m.w8(c+0x0cu,1);m.w32(c+4u,p);m.w32(c+8u,n);m.w8(c+0x0du,0);
    if(s32(n)<s32(m.r32(c+0x10u)))m.w32(c+0x10u,n);
    return n&0xffffff00u|1u;
}
std::uint32_t fun_004f8080(Memory&m,const Inputs&i){return make_fixed8(m,i,0x78dea4u,false,false);}
std::uint32_t fun_004f8270(Memory&m,const Inputs&i){return make_tagged_preserving_first(m,i);}
std::uint32_t fun_004fadd0(Memory&m,const Inputs&i){
    const auto c=i.cx;
    // Compose the byte-verified 0x13b1a0 and 0x0b8660 effects in observed order.
    m.w32(c+8u,0);m.w32(c+0x0cu,0);m.w8(c+0x10u,1);m.w8(c+0x11u,1);m.w32(c+0x14u,0);m.w32(c,0x78e3b4u);m.w32(c+4u,0x78e2ecu);
    m.w32(c+0x18u,m.r32(0x00a28cc0u));m.w32(c+0x1cu,m.r32(0x00a28cc4u));m.w32(c+0x20u,m.r32(0x00a28cc8u));
    m.w32(c+0x24u,m.r32(0x00a28cc0u));m.w32(c+0x28u,m.r32(0x00a28cc4u));m.w32(c+0x2cu,m.r32(0x00a28cc8u));
    // 0x0b8660 is called with arg0=0; its concrete effects are the two
    // halfword clears and timestamp/global field stores shown by its accepted body.
    m.w16(c+0x30u,0);m.w16(c+0x34u,0);m.w32(c+0x38u,m.r32(0x00a2896cu));m.w32(c+0x40u,0);m.w16(c+0x44u,0);m.w16(c+0x44u,0);
    for(const auto o:{0x48u,0x50u,0x58u,0x60u,0x4cu,0x54u,0x64u,0x6cu})m.w32(c+o,0);
    m.w32(c+0x5cu,0x3ff00000u);m.w8(c+0x68u,0);m.w8(c+0x70u,0);m.w32(c,0x78e2b4u);m.w32(c+4u,0x78e1ecu);return c;
}
std::uint32_t fun_00567cd0(Memory&m,const Inputs&i){const auto c=make_fixed8(m,i,0x78576cu,false,false);m.w32(c,0x790ab8u);m.w32(c+0x14u,10u);m.w32(c+0x10u,0u);return c;}
std::uint32_t fun_00569c40(Memory&m,const Inputs&i){return make_12byte(m,i);}
std::uint32_t fun_0058b3a0(Memory&m,const Inputs&i){return resize_copy(m,i,16u,false,false,false);}
std::uint32_t fun_0058b900(Memory&m,const Inputs&i){return resize_copy(m,i,8u,true,true,false);}
std::uint32_t fun_005ae6e0(Memory&m,const Inputs&i){return resize_copy(m,i,8u,true,true,true);}
std::uint32_t fun_005fd690(Memory&m,const Inputs&i){return make_104byte(m,i,true);}
std::uint32_t fun_005fda60(Memory&m,const Inputs&i){return make_104byte(m,i,false);}
std::uint32_t fun_0066a470(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];m.w32(c+4u,0);m.w32(c+8u,n);m.w8(c+0x0cu,1);m.w8(c+0x0du,0);m.w32(c,0x7944ecu);
    if(!n)return c;require_init(n,p,4u,4u,32u);m.w32(p,n);for(std::uint32_t j=0;j<n;++j)initialize_zero_word(m,p+4u+j*4u);m.w32(c+4u,p+4u);return c;
}
std::uint32_t fun_006b5cb0(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(!n||n>512u||!p)outside("Block73 0x2b5cb0 requires positive supplied count and storage");
    require_span(c,0x14u,"Block73 0x2b5cb0 descriptor wraps");
    require_init(n,p,8u,4u,512u);const auto old=m.r32(c+4u),old_count=m.r32(c+8u);
    if(!old||m.r8(c+0x0du)!=0u||s32(old_count)<0||old_count>512u)
        outside("Block73 0x2b5cb0 requires non-owned old vector and bounded old count");
    if(old_count!=n)outside("Block73 0x2b5cb0 selected route requires equal positive counts");
    require_span(old,std::uint64_t(n)*8u,"Block73 0x2b5cb0 old array wraps");
    const auto copied=n,data=p+4u;
    if(std::uint64_t(old)<std::uint64_t(p)+4u+std::uint64_t(n)*8u&&std::uint64_t(p)<std::uint64_t(old)+std::uint64_t(copied)*8u)
        outside("Block73 0x2b5cb0 overlapping vectors excluded");
    m.w8(c+0x0cu,0);m.w32(p,n);
    for(std::uint32_t j=0;j<n;++j)m.w32(data+j*8u+4u,0);
    for(std::uint32_t j=0;j<copied;++j){m.w32(data+j*8u,m.r32(old+j*8u));m.w32(data+j*8u+4u,m.r32(old+j*8u+4u));}
    m.w8(c+0x0cu,1);m.w32(c+4u,data);m.w32(c+8u,n);m.w8(c+0x0du,0);
    if(s32(n)<s32(m.r32(c+0x10u)))m.w32(c+0x10u,n);
    return (n&0xffffff00u)|1u;
}
std::uint32_t fun_0071b960(Memory&m,const Inputs&i){
    const auto c=i.cx,n=i.arg[0],p=i.arg[1];
    if(!n||n>512u||!p)outside("Block73 0x31b960 requires positive bounded count and supplied storage");
    require_span(c,0x14u,"Block73 0x31b960 descriptor wraps");
    require_init(n,p,8u,4u,512u);const auto old=m.r32(c+4u),old_count=m.r32(c+8u);
    if(!old||old_count!=n||m.r8(c+0x0du)!=0u)
        outside("Block73 0x31b960 requires equal positive counts and borrowed old vector");
    const auto data=p+4u;
    require_span(old,std::uint64_t(n)*8u,"Block73 0x31b960 old array wraps");
    if(std::uint64_t(old)<std::uint64_t(p)+4u+std::uint64_t(n)*8u&&std::uint64_t(p)<std::uint64_t(old)+std::uint64_t(n)*8u)
        outside("Block73 0x31b960 old/new vectors must be disjoint");
    m.w8(c+0x0cu,0);m.w32(p,n);
    for(std::uint32_t j=0;j<n;++j){
        const auto dst=data+j*8u,src=old+j*8u,payload=m.r32(src+4u);
        if(!payload)outside("Block73 0x31b960 requires non-null payload references");
        require_span(payload,8u,"Block73 payload object wraps address space");
        initialize_tagged_entry(m,dst,0x799e7cu);
        // Accepted 0x630ad0: destination was initialized to null, so this
        // increments the incoming object's +4 count and stores its pointer.
        m.w32(payload+4u,m.r32(payload+4u)+1u);m.w32(dst+4u,payload);
    }
    m.w8(c+0x0cu,1);m.w32(c+4u,data);m.w32(c+8u,n);m.w8(c+0x0du,0);
    if(s32(n)<s32(m.r32(c+0x10u)))m.w32(c+0x10u,n);
    return (n&0xffffff00u)|1u;
}
std::uint32_t fun_0071bc00(Memory&m,const Inputs&i){return make_tagged(m,i,0x799e7cu,0x799ec4u);}
std::uint32_t fun_007206d0(Memory&m,const Inputs&i){return make_tagged(m,i,0x79a10cu,0x79a0ccu,32u);}
} // namespace ra2::recovered::global_b26
