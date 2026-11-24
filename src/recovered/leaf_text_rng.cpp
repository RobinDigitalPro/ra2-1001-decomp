#include "leaf_text_rng.hpp"

namespace ra2::recovered::leaf {
// RVA 0x36d828: ordered byte exchange, including overlap and identical pointers.
std::uint32_t fun_0076d828(Memory& m, const Inputs& in) {
    auto a=in.arg[0], b=in.arg[1];
    if(a!=b) for(std::uint32_t n=in.arg[2]; n; --n) {
        const auto from_b=m.r8(b), from_a=m.r8(a);
        m.w8(a++,from_b); m.w8(b++,from_a);
    }
    return a;
}
// RVA 0x374ea6: the original also reads the byte at the limit.
std::uint32_t fun_00774ea6(Memory& m, const Inputs& in) {
    std::uint32_t n=0;
    while(n<in.arg[1] && m.r8(in.arg[0]+n)!=0) ++n;
    const auto terminal=m.r8(in.arg[0]+n);
    return terminal==0 ? n : in.arg[1];
}
// RVA 0x36f113: unsigned 16-bit code units, normalized signed comparison.
std::uint32_t fun_0076f113(Memory& m, const Inputs& in) {
    auto a=in.arg[0], b=in.arg[1];
    for(;;a+=2,b+=2) {
        const auto x=m.r16(a), y=m.r16(b);
        if(x!=y) return x<y ? 0xffffffffu : 1u;
        if(y==0) return 0;
    }
}
// RVA 0x36ef05: the terminator participates in the backwards search.
std::uint32_t fun_0076ef05(Memory& m, const Inputs& in) {
    auto p=in.arg[0]; while(m.r16(p)) p+=2;
    for(;;p-=2) {
        if(m.r16(p)==(in.arg[1]&0xffffu)) return p;
        if(p==in.arg[0]) return 0;
    }
}
// RVA 0x370e09: first source unit found in a zero-terminated set.
std::uint32_t fun_00770e09(Memory& m, const Inputs& in) {
    for(auto p=in.arg[0];m.r16(p);p+=2)
        for(auto q=in.arg[1];m.r16(q);q+=2)
            if(m.r16(p)==m.r16(q)) return p;
    return 0;
}
// RVA 0x2eed60: -1 means unlimited; destination is always terminated.
// No return value is defined for all original paths.
std::uint32_t fun_006eed60(Memory& m, const Inputs& in) {
    auto d=in.cx,s=in.dx,n=in.arg[0],c=m.r8(s);
    while(c && n) {
        m.w16(d,c);d+=2;++s;
        if(n!=0xffffffffu) --n;
        c=m.r8(s);
    }
    m.w16(d,0);return 0;
}
// RVA 0x2eed90: truncates each nonzero 16-bit unit to its low byte.
std::uint32_t fun_006eed90(Memory& m, const Inputs& in) {
    auto d=in.cx,s=in.dx,n=in.arg[0];
    while(m.r16(s) && n) {
        const auto c=m.r8(s);s+=2;m.w8(d++,c);
        if(n!=0xffffffffu) --n;
    }
    m.w8(d,0);return 0;
}
// RVA 0x35a040: only AL is the character result.
std::uint32_t fun_0075a040(Memory& m, const Inputs& in) {
    const auto p=m.r32(in.cx);std::uint32_t n=0;
    while(m.r8(p+n)) ++n;
    return in.arg[0]<n ? m.r8(p+in.arg[0]) : 0;
}
// RVA 0x22fde0: coherent 250-word state with two cursor indices.
std::uint32_t fun_0062fde0(Memory& m, const Inputs& in) {
    if(m.r8(in.cx)) return 0;
    auto i=m.r32(in.cx+4),j=m.r32(in.cx+8);
    m.w32(in.cx+12+4*i,m.r32(in.cx+12+4*i)^m.r32(in.cx+12+4*j));
    i=m.r32(in.cx+4);j=m.r32(in.cx+8);
    const auto result=m.r32(in.cx+12+4*i);
    ++i;++j;m.w32(in.cx+4,i);m.w32(in.cx+8,j);
    if(s32(i)>=250) m.w32(in.cx+4,0);
    if(s32(j)>=250) m.w32(in.cx+8,0);
    return result;
}
// RVA 0x1306f0: valid head/tail indices are in [0,255]. Full ring retains state.
std::uint32_t fun_005306f0(Memory& m, const Inputs& in) {
    const auto tail=m.r32(in.cx+0x318),next=(tail+1)&255u;
    if(next==m.r32(in.cx+0x314)) return 0;
    m.w16(in.cx+0x114+2*tail,in.arg[0]);m.w32(in.cx+0x318,next);
    return 1;
}
}
