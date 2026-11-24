#include "global_b62_a.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::global_b26 {
namespace {
// Accepted 0x2e6bc0: the two source loads precede either destination store,
// preserving the original pair-copy behavior when the spans overlap.
inline std::uint32_t copy_pair(Memory& m, std::uint32_t dst, std::uint32_t src) {
    const auto first=m.r32(src), second=m.r32(src+4u);
    m.w32(dst,first); m.w32(dst+4u,second);
    return dst;
}

// Accepted 0x13b1a0 instruction sequence, in its original write order.
inline std::uint32_t initialize_state(Memory& m, std::uint32_t object) {
    const std::uint32_t eax=object;
    const std::uint32_t ecx=0, dl=1;
    m.w32(eax+8u,ecx); m.w32(eax+0x0cu,ecx);
    m.w8(eax+0x10u,dl); m.w8(eax+0x11u,dl);
    m.w32(eax+0x14u,ecx);
    m.w32(eax,0x0078e3b4u); m.w32(eax+4u,0x0078e2ecu);
    return eax;
}

inline std::uint32_t rewritten_index(std::uint32_t value) {
    auto eax=value&0x800000ffu;
    if(eax&0x80000000u) {
        --eax;
        eax|=0xffffff00u;
        ++eax;
    }
    return eax;
}
inline std::uint32_t rgb_address(std::uint32_t base,std::uint32_t signed_index) {
    const auto signed_value=s32(signed_index);
    return base+static_cast<std::uint32_t>(signed_value*3);
}

// Accepted 0x234310 integer channel blend; exact CDQ/sign-byte rounding and
// byte-write order. The caller's destination here is its three-byte stack local.
inline void blend_rgb(Memory& m, std::array<std::uint8_t,3>& dst,
                      std::uint32_t source, std::uint32_t weight) {
    const auto w=weight&255u;
    auto channel=[&](unsigned k,std::uint32_t old) {
        const auto src=m.r8(source+k);
        const auto product=std::int32_t(src)-std::int32_t(old);
        const auto scaled=product*std::int32_t(w);
        const auto sign_adjust=(scaled<0)?255u:0u;
        const auto q=sar(std::uint32_t(scaled)+sign_adjust,8);
        return std::uint8_t(old+q);
    };
    const auto old0=std::uint32_t(dst[0]);
    const auto new0=channel(0,old0);
    const auto old1=std::uint32_t(dst[1]); // MOV BL,[ECX+1] precedes store byte 0.
    dst[0]=new0;
    const auto new1=channel(1,old1);
    const auto old2=std::uint32_t(dst[2]); // MOV BL,[ECX+2] precedes store byte 1.
    dst[1]=new1;
    dst[2]=channel(2,old2);
}

// Accepted 0x2343a0 score: 2*|r| + 4*|g| + 3*|b|, with original channel
// access order and no writes.
inline std::uint32_t rgb_distance(Memory& m,std::uint32_t lhs,
                                 const std::array<std::uint8_t,3>& rhs) {
    const std::uint32_t l0=m.r8(lhs), r0=rhs[0];
    const std::uint32_t l1=m.r8(lhs+1u), r1=rhs[1];
    const std::uint32_t l2=m.r8(lhs+2u), r2=rhs[2];
    const auto d0=l0>r0?l0-r0:r0-l0;
    const auto d1=l1>r1?l1-r1:r1-l1;
    const auto d2=l2>r2?l2-r2:r2-l2;
    return d2*3u+d0*2u+d1*4u;
}
}

// Original RVA 0x133d10. Pair-copy helper 0x2e6bc0 reads both dwords before
// writes; the temporary is kept local so output/source aliases remain safe.
std::uint32_t fun_00533d10(Memory& m,const Inputs& i) {
    const auto object=i.cx, output=i.arg[0];
    if(m.r32(0x00a255c8u)==0u) {
        auto edx=m.r32(object+0x28u), ecx=m.r32(object+0x2cu);
        if(m.r32(0x0083a710u)==m.r32(0x00798bfcu)) edx+=0x54u;
        else edx+=0xa4u;
        ecx+=7u;
        m.w32(output,edx); m.w32(output+4u,ecx);
        return output;
    }

    // CALL 0x2e6bc0 with ECX=ESP+4 and EDX=object+0x18; that stack cell is
    // represented by two raw locals, but both loads still precede the writes.
    const auto local_first=m.r32(object+0x18u);
    const auto local_second=m.r32(object+0x1cu);
    auto edx=local_first;
    const auto esi=m.r32(0x00798bfcu);
    auto ecx=local_second;
    const auto eax=m.r32(0x0083a710u);
    if(eax==esi) { edx+=0x0cu; ecx+=0x100u; }
    else { edx+=0x10u; ecx+=0x141u; }
    m.w32(output,edx); m.w32(output+4u,ecx);
    return output;
}

// Original RVA 0x9f360: accepted 0x13b1a0 state initialization followed by
// the caller's address/data-field stores in their original order.
std::uint32_t fun_0049f360(Memory& m,const Inputs& i) {
    const auto object=i.cx;
    (void)initialize_state(m,object);
    const std::uint32_t eax=0;
    auto edx=object+0x34u;
    m.w32(object+0x1cu,eax); m.w32(object+0x20u,eax);
    auto ecx=m.r32(0x00a2896cu);
    m.w32(object+0x2cu,eax); m.w32(object+0x24u,ecx); m.w32(object+0x30u,eax);
    ecx=m.r32(0x0083acc8u); m.w32(edx,ecx);
    ecx=m.r32(0x0083acccu); m.w32(edx+4u,ecx);
    ecx=m.r32(0x0083acd0u); m.w32(edx+8u,ecx);
    ecx=m.r32(0x0083acc8u); edx=object+0x40u; m.w32(object+0x40u,ecx);
    ecx=m.r32(0x0083acccu); m.w32(edx+4u,ecx);
    ecx=m.r32(0x0083acd0u); m.w32(object+0x50u,eax); m.w32(object+0x4cu,eax); m.w32(edx+8u,ecx);
    ecx=0xffffffffu;
    m.w32(object+0x54u,eax); m.w32(object+0x58u,ecx); m.w32(object+0x5cu,ecx);
    for(unsigned off=0x60u;off<=0x64u;++off)m.w8(object+off,0);
    m.w8(object+0x65u,1); m.w32(object+0x68u,eax);
    m.w32(object,0x0078b594u); m.w32(object+4u,0x0078b4ccu); m.w32(object+0x18u,0x0078b4a8u);
    return object;
}

// Original RVA 0x26af80: parallel state-initializer wrapper with its own
// global triplet and original vtable/function pointer constants.
std::uint32_t fun_0066af80(Memory& m,const Inputs& i) {
    const auto object=i.cx;
    (void)initialize_state(m,object);
    const std::uint32_t eax=0;
    auto edx=object+0x34u;
    m.w32(object+0x1cu,eax); m.w32(object+0x20u,eax);
    auto ecx=m.r32(0x00a2896cu);
    m.w32(object+0x2cu,eax); m.w32(object+0x24u,ecx); m.w32(object+0x30u,eax);
    ecx=m.r32(0x00aa0cc8u); m.w32(edx,ecx);
    ecx=m.r32(0x00aa0cccu); m.w32(edx+4u,ecx);
    ecx=m.r32(0x00aa0cd0u); m.w32(edx+8u,ecx);
    ecx=m.r32(0x00aa0cc8u); edx=object+0x40u; m.w32(object+0x40u,ecx);
    ecx=m.r32(0x00aa0cccu); m.w32(edx+4u,ecx);
    ecx=m.r32(0x00aa0cd0u); m.w32(object+0x50u,eax); m.w32(object+0x4cu,eax); m.w32(edx+8u,ecx);
    ecx=0xffffffffu;
    m.w32(object+0x54u,eax); m.w32(object+0x58u,ecx); m.w32(object+0x5cu,ecx);
    for(unsigned off=0x60u;off<=0x64u;++off)m.w8(object+off,0);
    m.w8(object+0x65u,1); m.w32(object+0x68u,eax);
    m.w32(object,0x007960acu); m.w32(object+4u,0x00795fe4u); m.w32(object+0x18u,0x00795fc0u);
    return object;
}

// Original RVA 0xb2e70. Calls are expanded from accepted 0x234310 and
// 0x2343a0 using a local RGB stack object. EDI is the palette, EDX the output
// byte stream, arg[0] the signed source-index byte, and arg[1] the blend weight.
std::uint32_t fun_004b2e70(Memory& m,const Inputs& i) {
    const auto palette=i.cx, output=i.dx;
    if(output==0u)return 0u; // original null-output exit preserves EDX in EAX
    const auto source_index=rewritten_index(i.arg[0]);
    const auto weight=i.arg[1]&255u;
    for(std::uint32_t n=0;n<256u;++n) {
        if(n==0u) { m.w8(output+n,0); continue; }
        if(n>0xf0u) { m.w8(output+n,n); continue; }

        const auto current=rgb_address(palette,rewritten_index(n));
        std::array<std::uint8_t,3> color{};
        const auto first=m.r16(current);
        color[0]=std::uint8_t(first); color[1]=std::uint8_t(first>>8);
        color[2]=std::uint8_t(m.r8(current+2u));
        const auto source=rgb_address(palette,source_index);
        blend_rgb(m,color,source,weight);

        std::uint32_t best_index=0xffffffffu,best_score=0;
        for(std::uint32_t candidate=0xf0u;candidate<0xffu;++candidate) {
            const auto address=rgb_address(palette,rewritten_index(candidate));
            const auto score=rgb_distance(m,address,color);
            if(best_index==0xffffffffu||score<best_score) {
                best_index=candidate; best_score=score;
            }
        }
        m.w8(output+n,best_index);
    }
    return output;
}
}
