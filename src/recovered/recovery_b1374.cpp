#include "recovery_b1374.hpp"
#include "recovered/recovery_b338.hpp"
#include "recovered/recovery_b566.hpp"
#include "recovered/numeric_b88.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1374 {
namespace {
using U=std::uint32_t;
void need(bool b,const char* text){if(!b)throw std::domain_error(text);}
U original_608d60(Memory& m,U self,U out,U temporary,const Inputs& parent){
    Inputs call{};call.cx=temporary;call.dx=m.r32(m.r32(m.r32(self+4u))+4u);call.fp=parent.fp;
    const U p=recovery_b338::fun_00608560(m,call);parent.fp=call.fp;
    const U x=m.r32(p),y=m.r32(p+4u),z=m.r32(p+8u);
    m.w32(out,x);m.w32(out+4u,y);m.w32(out+8u,z);return out;
}
U original_608380(Memory& m,U point,U out,U temporary,const Inputs& parent){
    Inputs call{};call.cx=m.r32(0x821cacu);call.arg[0]=point;call.arg[1]=temporary;call.fp=parent.fp;
    numeric_b88::fun_00698010(m,call);parent.fp=call.fp;
    m.w32(out,m.r32(temporary)+m.r32(0x821970u));m.w32(out+4u,m.r32(temporary+4u)+m.r32(0x821974u));return out;
}
U original_611a60(Memory& m,U actor){
    const U rs=m.r32(0x83b2e8u),rr=m.r32(0x83b2ecu)&255u,bs=m.r32(0x83b2f0u),br=m.r32(0x83b2f4u)&255u,gs=m.r32(0x83b2f8u),gr=m.r32(0x83b2fcu)&255u;
    auto packed=[&](U p){return ((U(m.r8(p))>>(rr&31u))<<(rs&31u))|((U(m.r8(p+1u))>>(gr&31u))<<(gs&31u))|((U(m.r8(p+2u))>>(br&31u))<<(bs&31u));};
    const U ordinary=packed(0xa9e361u);if(!actor)return ordinary;
    const U selected=packed(0xa9e369u);
    need(m.r32(0xa5e208u)==0u,"B1374 real ordinary actor color without pending selection owner");
    return m.r8(actor+0x77u)?selected:ordinary;
}
}
U fun_00611000(Memory& original,const Inputs& i){
    // This root owns its111-byte descriptor copy and all helper argument/output locals.
    std::array<std::uint8_t,0x200> bytes{};constexpr U base=0x7a440000u;
    leaf::Memory local(bytes.data(),base,bytes.size());Memory m=original;m.add(local);
    const U self=i.cx,xyz=original_608d60(m,self,base,base+0x60u,i);
    for(U k=0;k<3u;++k)m.w32(base+0x18u+4u*k,m.r32(xyz+4u*k));
    original_608380(m,base+0x18u,base+0x2cu,base+0x80u,i);
    need(floating_b61::s32(m.r32(self+0x10u))>0,"B1374 real nonempty primary descriptor list");
    const U first=m.r32(m.r32(self+4u)),descriptor=m.r32(first+4u);
    for(U k=0;k<111u;++k)m.w8(base+0xc0u+k,m.r8(descriptor+k));
    const U category=m.r8(base+0xccu);need(category!=11u&&category!=29u,"B1374 ordinary descriptor category");
    // Actual608C70(self,0) dereferences the genuine first entry's actor member.
    const U actor=m.r32(m.r32(m.r32(self+4u))),color=original_611a60(m,actor);
    need(m.r32(self+0x30u)==0u&&m.r32(self+0xa8u)==0u,"B1374 empty secondary/selected-object loops");
    Inputs outline{};outline.cx=self;outline.arg[0]=color;outline.fp=i.fp;
    const U result=recovery_b566::fun_00609cd0(m,outline);i.fp=outline.fp;return result;
}
}
