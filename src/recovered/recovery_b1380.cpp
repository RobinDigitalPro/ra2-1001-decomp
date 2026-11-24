#include "recovery_b1380.hpp"
#include "recovered/recovery_b338.hpp"
#include "recovered/recovery_b565.hpp"
#include "recovered/numeric_b88.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1380 {
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
    need(m.r32(0xa5e208u)==0u,"B1380 real ordinary actor color without pending selection owner");
    return m.r8(actor+0x77u)?selected:ordinary;
}
}

U fun_00611450(Memory& original,const Inputs& i){
    std::array<std::uint8_t,0x200> bytes{};constexpr U base=0x7a480000u;
    leaf::Memory local(bytes.data(),base,bytes.size());Memory m=original;m.add(local);
    const U self=i.cx,xyz=original_608d60(m,self,base,base+0x60u,i);
    for(U k=0;k<3u;++k)m.w32(base+0x18u+4u*k,m.r32(xyz+4u*k));
    original_608380(m,base+0x18u,base+0x2cu,base+0x80u,i);
    need(m.r32(self+0x10u)==1u,"B1380 real primary descriptor");
    const U record=m.r32(m.r32(self+4u)),descriptor=m.r32(record+4u);
    for(U k=0;k<111u;++k)m.w8(base+0xc0u+k,m.r8(descriptor+k));
    const U category=m.r8(base+0xccu);need(category!=11u&&category!=29u,"B1380 ordinary descriptor");
    original_611a60(m,m.r32(record)); // Actual ordinary palette calculation is still performed.
    need(m.r32(self+0x30u)==0u&&m.r32(self+0xa8u)==0u,"B1380 bounded empty secondary loops");
    // Actual60A1B0's warm prefix returns the existing cached color.
    const U cached=m.r32(self+0xb4u);need(cached!=0xffffffffu,"B1380 genuine warm color");
    Inputs fill{};fill.cx=self;fill.arg[0]=cached;fill.fp=i.fp;
    const U result=recovery_b565::fun_00609e10(m,fill);i.fp=fill.fp;return result;
}
namespace {
U owner_equal(Memory& m,U self){
    const U actor=m.r32(m.r32(m.r32(self+4u))),owner=m.r32(actor+0x1b4u),other=m.r32(0xa1e0e4u);
    need(other!=0u&&owner==other,"B1380 actual4E4BE0 same-owner branch");
    return (owner&0xffffff00u)|1u;
}
U fill_unclipped_format1(Memory& m,U surface,U clip,U rect,U color){
    // Finite actual75FD00 path: real surface rectangle, two intersections,
    // pitch/point/lock callbacks, six raster rows, then actual unlock.
    need(m.r32(surface)==0x785ef8u,"B1380 genuine surface vptr");
    const U width=m.r32(surface+4u),height=m.r32(surface+8u);
    need(m.r32(clip)==0u&&m.r32(clip+4u)==0u&&m.r32(clip+8u)==width&&m.r32(clip+12u)==height,"B1380 full unclipped viewport");
    const U x=m.r32(rect),y=m.r32(rect+4u),w=m.r32(rect+8u),h=m.r32(rect+12u);
    need(w==6u&&h==6u&&x<=width-w&&y<=height-h,"B1380 positive contained rectangle");
    need(m.r32(surface+16u)==1u,"B1380 originalformat1 callback");
    const U pitch=width,locks=m.r32(surface+12u),pixels=m.r32(surface+20u);
    m.w32(surface+12u,locks+1u); // Actual411370: increment count before format and pitch queries.
    const U first=pixels+x+y*pitch;need(first!=0u,"B1380 successful borrowed pixel lock");
    for(U row=0;row<h;++row)for(U col=0;col<w;++col)m.w8(first+row*pitch+col,std::uint8_t(color));
    m.w32(surface+12u,m.r32(surface+12u)-1u); // Actual4112F0.
    return (m.r32(surface+12u)&0xffffff00u)|1u;
}
}
U fun_0060fad0(Memory& original,const Inputs& i){
    std::array<std::uint8_t,0x200> bytes{};constexpr U base=0x7a490000u;
    leaf::Memory local(bytes.data(),base,bytes.size());Memory m=original;m.add(local);
    need(m.r32(0xa5e198u)==1u&&m.r32(0xa28870u)==0u,"B1380 single nonempty registry and empty third list");
    const U self=m.r32(m.r32(0xa5e18cu));owner_equal(m,self);
    Inputs child{};child.cx=self;child.fp=i.fp;fun_00611450(m,child);i.fp=child.fp;
    owner_equal(m,self);const U color=m.r32(self+0xb4u);need(color!=0xffffffffu,"B1380 warm caller color");
    // Actual6E7010 viewport, including its sidebar mode rule.
    const U clip=base+0x120u;
    m.w32(clip,(m.r8(0xa28770u)||m.r8(0xa28953u))?0u:168u);m.w32(clip+4u,0u);
    m.w32(clip+8u,m.r32(0x821988u)-168u);m.w32(clip+12u,m.r32(0x82198cu)-32u);
    const U xyz=original_608d60(m,self,base,base+0x60u,i);
    for(U k=0;k<3u;++k)m.w32(base+0x18u+4u*k,m.r32(xyz+4u*k));
    original_608380(m,base+0x18u,base+0x2cu,base+0x80u,i);
    // Actual608EB0 centered8x8 rectangle followed by the caller's one-pixel inset.
    const U rect=base+0x140u;m.w32(rect,m.r32(base+0x2cu)-3u);m.w32(rect+4u,m.r32(base+0x30u)-3u);m.w32(rect+8u,6u);m.w32(rect+12u,6u);
    return fill_unclipped_format1(m,m.r32(0x821ca4u),clip,rect,color);
}
}
