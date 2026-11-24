#include "global_b58_a.hpp"

namespace ra2::recovered::global_b26 {
namespace {
constexpr std::uint32_t crc_table = 0x007c0634u;
constexpr std::uint32_t global_mode = 0x00a2876cu;
constexpr std::uint32_t global_width = 0x0083a710u;
constexpr std::uint32_t global_height = 0x0083a714u;
constexpr std::uint32_t rect_gate = 0x00a255c8u;

std::uint32_t hash_four(Memory& m, std::uint32_t seed, std::uint32_t word) {
    std::uint32_t crc = ~seed;
    for (unsigned n=0; n<4; ++n) {
        const std::uint32_t byte = (word >> (n*8u)) & 0xffu;
        const std::uint32_t index = (crc & 0xffu) ^ byte;
        crc = (crc >> 8) ^ m.r32(crc_table + index*4u);
    }
    return ~crc;
}

std::uint32_t low_byte(std::uint32_t eax, std::uint32_t value) {
    return (eax & 0xffffff00u) | (value & 0xffu);
}

std::uint32_t signed_half_toward_zero(std::uint32_t value) {
    const std::uint32_t sign = (value & 0x80000000u) ? 0xffffffffu : 0u;
    return sar(value - sign, 1);
}
}

// RVA 0x93bd0. Consume one byte into the pending word. The original CRC table
// is read directly at VA 0x7c0634; the fixture must map the original data page.
std::uint32_t fun_00493bd0(Memory& m, const Inputs& i) {
    const std::uint32_t state=i.cx;
    std::uint32_t pending=m.r32(state+4u);
    if (pending==0u) m.w32(state+8u,0u);
    m.w8(state+8u+pending,i.arg[0]&0xffu);
    ++pending;
    m.w32(state+4u,pending);
    if (pending!=4u) return pending;

    m.w8(state+12u,m.r8(state+4u));
    const std::uint32_t scratch=m.r32(state+8u);
    i.arg[0]=scratch;
    const std::uint32_t hash=hash_four(m,m.r32(state),scratch);
    m.w32(state,hash);
    m.w32(state+4u,0u);
    return hash;
}

// RVA 0x93c60. Same stream transition, with a nonzero input byte normalized
// to one before it enters the pending four-byte word.
std::uint32_t fun_00493c60(Memory& m, const Inputs& i) {
    const std::uint32_t state=i.cx;
    std::uint32_t pending=m.r32(state+4u);
    if (pending==0u) m.w32(state+8u,0u);
    const std::uint32_t value=(i.arg[0]&0xffu)!=0u ? 1u : 0u;
    m.w8(state+8u+pending,value);
    ++pending;
    m.w32(state+4u,pending);
    if (pending!=4u) return pending;

    m.w8(state+12u,m.r8(state+4u));
    const std::uint32_t scratch=m.r32(state+8u);
    i.arg[0]=scratch;
    const std::uint32_t hash=hash_four(m,m.r32(state),scratch);
    m.w32(state,hash);
    m.w32(state+4u,0u);
    return hash;
}

// RVA 0x136780. Preserve the original clamp passes and quantization order;
// pointers may alias, so each pass rereads memory after earlier writes.
std::uint32_t fun_00536780(Memory& m, const Inputs& i) {
    const std::uint32_t a=i.cx, b=i.dx, c=i.arg[0];
    std::uint32_t value=m.r32(a); if(s32(value)>=1000) m.w32(a,1000u);
    value=m.r32(b); if(s32(value)>=1000) m.w32(b,1000u);
    value=m.r32(c); if(s32(value)>=1000) m.w32(c,1000u);

    value=m.r32(a); if(s32(value)<=0) m.w32(a,0u);
    value=m.r32(b); if(s32(value)<=0) m.w32(b,0u);
    value=m.r32(c); if(s32(value)<=0) m.w32(c,0u);

    const std::uint32_t mode=m.r32(global_mode);
    const std::uint32_t mask=mode==0u?0xffffff80u:mode==1u?0xffffffc0u:
                             mode==2u?0xffffffe0u:0xffffffffu;
    if(mode<=2u){
        m.w32(a,m.r32(a)&mask);
        m.w32(b,m.r32(b)&mask);
        m.w32(c,m.r32(c)&mask);
    }
    return c;
}

// RVA 0x153fc0. Mode-gated identifier membership. MOV AL/XOR AL only change
// the low byte, so every path preserves its actual upper EAX source.
std::uint32_t fun_00553fc0(Memory& m, const Inputs& i) {
    const std::uint32_t record=i.arg[0];
    std::uint32_t eax=i.ax;
    std::uint32_t gate_byte;
    if(i.dx==2u){
        eax=m.r32(0x00a55c60u); gate_byte=4u;
        if(i.cx==eax && m.r8(record+0x11au)==gate_byte) return low_byte(eax,1u);
        if(i.cx==m.r32(0x00a3a8c0u) && m.r8(record+0x11au)==gate_byte) return low_byte(eax,1u);
        eax=m.r32(0x00a547b4u);
    } else if(i.dx==4u){
        eax=m.r32(0x00a55c48u); gate_byte=2u;
        if(i.cx==eax && m.r8(record+0x11au)==gate_byte) return low_byte(eax,1u);
        if(i.cx==m.r32(0x00a3afc8u) && m.r8(record+0x11au)==gate_byte) return low_byte(eax,1u);
        eax=m.r32(0x00a3aab0u);
    } else {
        return low_byte(eax,0u);
    }

    if(i.cx==eax) return low_byte(eax,m.r8(record+0x11au)==gate_byte?1u:0u);
    if(i.cx==eax+3u) return low_byte(eax,m.r8(record+0x11au)==gate_byte?1u:0u);
    if(i.cx==eax+1u) return low_byte(eax,m.r8(record+0x11au)==gate_byte?1u:0u);
    eax+=2u;
    if(i.cx!=eax) return low_byte(eax,0u);
    return low_byte(eax,m.r8(record+0x11au)==gate_byte?1u:0u);
}

// RVA 0x157d70. Range endpoints and the mode gates below mirror the ordered
// original checks. AL updates retain the EAX base/end reached on that path.
std::uint32_t fun_00557d70(Memory& m, const Inputs& i) {
    const std::uint32_t candidate=i.cx, mode=i.dx;
    std::uint32_t eax=m.r32(0x00a3aaa8u);
    if(s32(candidate)>=s32(eax)){
        eax+=0x28u;
        if(s32(candidate)<s32(eax)) return low_byte(eax,1u);
    }

    eax=m.r32(0x00a3a1bcu);
    if(s32(candidate)>=s32(eax)){
        const std::uint32_t end=eax+4u;
        if(s32(candidate)<s32(end)){
            if(candidate==eax) return low_byte(eax,(mode==0u||mode==4u)?0u:1u);
            eax+=3u;
            if(candidate!=eax) return low_byte(eax,1u);
            return low_byte(eax,(mode==0u||mode==4u)?0u:1u);
        }
    }

    eax=m.r32(0x00a54b90u);
    if(s32(candidate)>=s32(eax)){
        const std::uint32_t end=eax+4u;
        if(s32(candidate)<s32(end)){
            if(candidate==eax) return low_byte(eax,(mode==1u||mode==3u)?0u:1u);
            eax+=3u;
            if(candidate!=eax) return low_byte(eax,1u);
            return low_byte(eax,(mode==1u||mode==3u)?0u:1u);
        }
    }

    eax=m.r32(0x00a3aad8u);
    if(s32(candidate)>=s32(eax)){
        const std::uint32_t end=eax+4u;
        if(s32(candidate)<s32(end)){
            if(candidate==eax) return low_byte(eax,(mode==0u||mode==1u)?0u:1u);
            eax+=3u;
            if(candidate!=eax) return low_byte(eax,1u);
            return low_byte(eax,(mode==0u||mode==1u)?0u:1u);
        }
    }

    eax=m.r32(0x00a3ab28u);
    if(s32(candidate)>=s32(eax)){
        const std::uint32_t end=eax+4u;
        if(s32(candidate)<s32(end)){
            if(candidate==eax) return low_byte(eax,(mode==2u||mode==3u)?0u:1u);
            eax+=3u;
            if(candidate!=eax) return low_byte(eax,1u);
            return low_byte(eax,(mode==2u||mode==3u)?0u:1u);
        }
    }

    eax=m.r32(0x00a55938u);
    if(s32(candidate)<s32(eax)) return low_byte(eax,0u);
    eax+=0x14u;
    if(s32(candidate)>=s32(eax)) return low_byte(eax,0u);
    return low_byte(eax,1u);
}

// RVA 0x133c40. Global dimensions/modes are observed in the original order;
// only the fields written by the selected branch are touched.
std::uint32_t fun_00533c40(Memory& m, const Inputs& i) {
    const std::uint32_t out=i.cx;
    const std::uint32_t height=m.r32(global_width);
    const bool special=(height==0x280u);
    const std::uint32_t offset=m.r32(special?0x00798bfcu:0x00798c00u);
    const std::uint32_t gate=m.r32(rect_gate);
    std::uint32_t origin;
    if(gate==0u){
        origin=m.r32(special?0x00798c08u:0x00798c0cu);
        const std::uint32_t left=origin-0x50u;
        const std::uint32_t horizontal=(height-offset)-((height-offset)&0x80000000u?0xffffffffu:0u);
        std::uint32_t vertical=m.r32(global_height)-left-0x50u;
        vertical=signed_half_toward_zero(vertical);
        m.w32(out+0x10u,offset);
        m.w32(out+0x20u,offset);
        m.w32(out+0x0cu,vertical);
        const std::uint32_t lower=vertical+0x28u;
        const std::uint32_t half=sar(horizontal,1);
        m.w32(out+0x30u,offset);
        m.w32(out+0x08u,half);
        m.w32(out+0x18u,half);
        m.w32(out+0x1cu,lower);
        m.w32(out+0x28u,half);
        m.w32(out+0x24u,left);
        m.w32(out+0x14u,0x28u);
        const std::uint32_t bottom=lower+left;
        m.w32(out+0x2cu,bottom);
        m.w32(out+0x34u,0x28u);
        return bottom;
    }

    origin=m.r32(special?0x00798c08u:0x00798c0cu);
    const std::uint32_t vertical=signed_half_toward_zero(m.r32(global_height)-origin);
    m.w32(out+0x20u,offset);
    m.w32(out+0x24u,origin);
    m.w32(out+0x1cu,vertical);
    const std::uint32_t horizontal=signed_half_toward_zero(height-offset);
    m.w32(out+0x18u,horizontal);
    return horizontal;
}

}
