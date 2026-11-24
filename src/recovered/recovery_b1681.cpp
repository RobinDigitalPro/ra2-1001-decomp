#include "recovered/recovery_b1681.hpp"
#include <stdexcept>
namespace ra2::recovered::b1681 {
namespace {
void need(bool v){if(!v)throw std::domain_error("16AEF0 finite isolated classified-cell domain");}
unsigned add_point(unsigned a,unsigned b){return ((a+b)&0xffffu)|(((a>>16)+(b>>16))<<16);}
bool inside(unsigned p,int lower,int upper){
    const int x=static_cast<std::int16_t>(p),y=static_cast<std::int16_t>(p>>16);
    return x+y>lower&&x-y<lower&&y-x<lower&&x+y<=upper;
}
void construct(Memory&m,Heap&h,unsigned p,unsigned point,unsigned label,unsigned cell){
    // The mapped lookup and first range classification match the B94 direct
    // constructor domain. Only its actual written fields are initialized.
    const auto table=m.r32(0x81a958u);
    need(m.r32(table+513u*4u)==cell);
    const auto tile=m.r32(cell+0x38u),start=m.r32(0xa547acu);
    need(tile==start&&start<0x7fffffd5u);
    h.w32(p,0);h.w32(p+4,0);h.w32(p+8,label);h.w32(p+12,0);
    h.w32(p+16,static_cast<unsigned>(static_cast<std::int32_t>(static_cast<std::int8_t>(m.r8(cell+0x11bu)))));
    h.w8(p+20,1);h.w32(p+22,point);h.w8(p+26,0);h.w8(p+27,1);
    h.w32(p+28,0);h.w32(p+32,0);h.w8(p+36,0);
    h.w32(p+40,0x7875a0u);h.w32(p+44,0);h.w32(p+48,0);
    h.w8(p+52,1);h.w8(p+53,0);h.w32(p+56,0);h.w32(p+60,100000);
    h.w32(p+64,0);h.w32(p+68,0);h.w32(p+72,0);h.w32(p+76,0);
    m.w32(0xa58640u,label+1u);
    // This selected registry starts empty with sixteen borrowed public slots.
    need(m.r32(0xa57950u)==0&&m.r32(0xa57948u)==16);
    m.w32(0xa57950u,1);m.w32(m.r32(0xa57944u),p);
}
}
unsigned run(Memory&m,const Inputs&i,Heap&h,Observation&o){
    const auto cell=i.cx,point=m.r32(cell+0x24u),label=m.r32(0xa58640u);
    const auto grid=m.r32(0xa5863cu),table=m.r32(0x81a958u);
    need(point==0x10001u&&m.r32(0x836b4cu)==2&&m.r32(0xa58634u)==1&&m.r32(0xa58638u)==2);
    need(grid&&table&&label>=1&&label<0x7ffffffeu&&m.r32(table+513u*4u)==cell);
    need(m.r32(cell+0x38u)==m.r32(0xa547acu)&&m.r32(0xa547acu)<0x7fffffd5u);
    need(m.r32(0xa57950u)==0&&m.r32(0xa57948u)==16&&m.r32(0xa57944u));
    for(unsigned k=0;k<4;++k)need(m.r32(grid+k*80u+56u)==0xffffffffu);
    // This supplied public-data contract retains all32 authentic cold BSS
    // bytes. It does not claim that normal game startup leaves them zero.
    for(unsigned k=0;k<8;++k)need(m.r32(0x839da0u+k*4u)==0);
    // The authentic Root constructs a cold local vector, grows it to50000,
    // seeds one produced point, then consumes it once. No padding is seeded.
    o.point=point;o.label=label;o.frontier=h.allocate(200000u);need(o.frontier);
    h.w32(o.frontier,point);
    m.w32(grid+3u*80u+60u,label);m.w32(grid+3u*80u+56u,label);
    for(unsigned k=0;k<8;++k){
        const auto next=add_point(point,m.r32(0x839da0u+k*4u));
        if(inside(next,1,2)){
            const int x=static_cast<std::int16_t>(next),y=static_cast<std::int16_t>(next>>16);
            const auto r=grid+static_cast<unsigned>(y*2+x)*80u;
            // Authentic cold offsets revisit the point already labelled by
            // this Root. The +38 check skips before another cell lookup.
            need(m.r32(r+56u)!=0xffffffffu||m.r32(r+60u)==label);
        }
    }
    o.processed=1;
    // True classification and workcount1 select the normal record constructor;
    // the random-choice and populated-iterator branches are outside this scope.
    o.record=h.allocate(80u);need(o.record);
    construct(m,h,o.record,point,label,cell);
    // Root overwrites these constructor fields with its actual entry values.
    h.w32(o.record+16u,static_cast<unsigned>(static_cast<std::int32_t>(static_cast<std::int8_t>(m.r8(cell+0x11bu)))));
    h.w8(o.record+20u,1);h.w32(o.record+12u,0);
    o.count=0;
    for(unsigned k=0;k<4;++k){
        const auto r=grid+k*80u;
        if(m.r32(r+56u)==h.r32(o.record+8u)&&m.r32(r)!=0){++o.count;h.w32(o.record+12u,o.count);}
    }
    need(h.release(o.frontier)!=0);
    return o.record;
}
}
