#include "recovered/recovery_b1513.hpp"
#include "recovered/numeric_b88.hpp"
#include <array>
#include <algorithm>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1513 {
namespace {
using U=std::uint32_t;using S=std::int32_t;
std::array<U,2> projected_point(Memory& m,const Inputs& outer,U receiver) {
    // Actual41B270 invokes original slot48=5CD4D0. Both original local
    // triples are fully produced; nothing escapes these private locals.
    const std::array<U,3> xyz{m.r32(receiver+0x88u),m.r32(receiver+0x8cu),m.r32(receiver+0x90u)};
    if(S(xyz[0])<-16 || S(xyz[0])>16 || S(xyz[1])<-16 || S(xyz[1])>16 || (xyz[2]!=0u && xyz[2]!=728u))
        throw std::domain_error("B1513 requires accepted298010 coordinate domain");
    std::array<std::uint8_t,20> local_bytes{};
    constexpr U local_base=0xf0000000u;
    ra2::recovered::leaf::Memory local_span(local_bytes.data(),local_base,U(local_bytes.size()));
    auto local_memory=m;local_memory.add(local_span);
    for(U k=0;k<3u;++k)local_memory.w32(local_base+4u*k,xyz[k]);
    Inputs nested=outer;nested.cx=m.r32(0x00821cacu);nested.arg[0]=local_base;nested.arg[1]=local_base+12u;
    // A8 RET4 leaves the second scratch pointer as projection arg1.
    // 298010's raw arg0 flag overwrite belongs only to this nested frame.
    const auto status=ra2::recovered::numeric_b88::fun_00698010(local_memory,nested);
    outer.fp.image=nested.fp.image;
    if((status&255u)==0u)throw std::domain_error("B1513 excludes projectionfalse type-dispatch route");
    return {local_memory.r32(local_base+12u),local_memory.r32(local_base+16u)};
}
}
static std::uint32_t clipped_visible(Memory& m,const Inputs& i) {
    const U receiver=i.cx;
    if(m.r32(receiver)!=0x00798c88u || m.r8(0x00a28953u)!=0u || m.r32(0x00b0de50u)==0u || m.r8(receiver+0x75u)!=1u || m.r8(receiver+0x76u)!=0u)
        throw std::domain_error("B1513 requires authenticated positive gate");
    m.w8(receiver+0x75u,0u); // Actual005CBBB0 before A8/projection.
    auto point=projected_point(m,i,receiver);
    const U rect=i.arg[0];
    const S rx=S(m.r32(rect)),ry=S(m.r32(rect+4u)),rw=S(m.r32(rect+8u)),rh=S(m.r32(rect+12u));
    const S vx=S(m.r32(0x00821970u)),vy=S(m.r32(0x00821974u)),vw=S(m.r32(0x00821978u)),vh=S(m.r32(0x0082197cu));
    if(rw<=0 || rh<=0 || vw<=0 || vh<=0)
        throw std::domain_error("B1513 requires positive rectangle extents");
    // With ESP=entryS-30, original[ESP+38] is outerarg1.
    i.arg[1]=U(rx);
    const S x=std::max(rx,vx),y=std::max(ry,vy);
    const S w=std::min(rx+rw,vx+vw)-x;
    if(w<=0)throw std::domain_error("B1513 excludes empty width");
    const S bottom=ry+rh;i.arg[1]=U(bottom); // Actual005CBCDA.
    const S h=std::min(bottom,vy+vh)-y;
    if(h<=0)throw std::domain_error("B1513 excludes empty height");
    m.w32(rect,U(x));m.w32(rect+4u,U(y));m.w32(rect+8u,U(w));m.w32(rect+12u,U(h));
    if(x>vx)point[0]+=U(vx-x);
    if(y>vy)point[1]+=U(vy-y);
    // Actual derived10C=006F5AF0: initialized-cache path, actual1A0
    // fully produces its own nestedarg0 coordinate word, then64(0,0).
    if((m.r8(0x00ab7eecu)&1u)==0u || m.r8(receiver+0x59eu)!=0u || m.r8(receiver+0x37cu)!=0u || m.r32(receiver+0x564u)!=0u)
        throw std::domain_error("B1513 excludes lazyinit/later64 dispatch");
    const U produced_draw_arg0=(U(S(m.r32(receiver+0x88u))/256)&0xffffu)|((U(S(m.r32(receiver+0x8cu))/256)&0xffffu)<<16u);
    (void)produced_draw_arg0; // Actual1A0 writes only the nested10C arg0.
    // Actual64=004C8BA0 with564zero forwards006C4930. Actual80 is
    // 006B6910 tail84=006F9C70, returning constructorarg0 atreceiver5AC.
    const U type=m.r32(receiver+0x5acu);
    if(m.r8(type+0xaa6u)==0u || m.r8(receiver+0x372u)!=0u || m.r8(0x00a28953u)!=0u)
        throw std::domain_error("B1513 requires actual visual-guard return5");
    // The real helper MOV EAX,5 / RET8 reaches derived10C's RET8;
    // then 1CBB70 MOV AL,1 produces fullEAX1.
    return 1u;
}
std::uint32_t fun_006f3fd0(Memory& m,const Inputs& i) {
    const U receiver=i.cx;
    if(m.r32(receiver)!=0x00798c88u)
        throw std::domain_error("B1513 requires constructor-pinned798C88 receiver");
    if(m.r8(receiver+0x370u)!=0u) {
        // Actual0062E3C0 indexzero lookup, type6getter and missiongetter.
        const U child=m.r32(m.r32(receiver+0xccu));
        if(m.r32(child)!=0x00787bbcu || m.r32(child+0x98u)!=16u)
            throw std::domain_error("B1513 requires authentic type6/mission16 child; no unknown upperEAX");
        const U a=m.r8(child+0x2c0u),b=m.r8(child+0x2c1u);
        // Original four accepted AL predicates. Mission16 gives upperEAX0;
        // each leaf changes onlyAL and wrapperXORAL yields fullEAX0.
        if(a!=0u && b!=0u)return 0u;
        if(a!=0u && b==0u)return 0u;
        if(a==0u && b==1u)return 0u;
        if(a==0u && b==0u)return 0u;
        throw std::domain_error("B1513 excludes childpredicate fallthrough");
    }
    // Original wrapper pushes new copies: helperarg1scratch is not outerarg1.
    Inputs nested=i;nested.arg[0]=i.arg[0];nested.arg[1]=i.arg[1];nested.arg[2]=0u;
    const U result=clipped_visible(m,nested);i.fp.image=nested.fp.image;
    return result;
}

}
