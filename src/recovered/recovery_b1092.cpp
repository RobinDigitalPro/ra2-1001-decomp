#include "recovered/recovery_b1092.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1092 {namespace {
void need(bool v){if(!v)throw std::domain_error("1092 distinct frame update with authentic unchanged bounds and clamp");}
int s16(unsigned x){return x&0x8000u?static_cast<int>(x)-65536:static_cast<int>(x);}
std::array<unsigned,4>bounds(Memory&m,unsigned receiver){
 const auto shp=m.r32(receiver+0x1cu),frame=m.r32(receiver+0x28u);const auto count=static_cast<unsigned>(s16(m.r16(shp+6u)));need(count>=3u&&count<=7u);
 std::array<unsigned,4>r{};
 if(frame<count){const auto h=shp+8u+24u*frame;for(unsigned k=0;k<4u;++k)r[k]=static_cast<unsigned>(s16(m.r16(h+2u*k)));}
 else for(unsigned k=0;k<4u;++k)r[k]=m.r32(0xa59420u+4u*k);
 r[0]+=m.r32(receiver+4u);r[1]+=m.r32(receiver+8u);
 if(m.r32(receiver+0x38u)&0x200u){r[0]-=static_cast<unsigned>(s16(m.r16(shp+2u))/2);r[1]-=static_cast<unsigned>(s16(m.r16(shp+4u))/2);}
 return r;
}
}
unsigned run(Memory&m,const Inputs&i,State&,unsigned root){
 need(root==0x1a9340u&&m.r32(i.cx)==0x791d38u&&m.r32(0x791d50u)==0x5a98e0u);
 const auto old=m.r32(i.cx+0x28u);need(old==0u&&i.arg[0]!=old);const auto before=bounds(m,i.cx);
 m.w32(i.cx+0x28u,i.arg[0]);need(bounds(m,i.cx)==before); // Changed-bounds blit remains conditional.
 const auto shp=m.r32(i.cx+0x1cu);auto eax=static_cast<unsigned>(s16(m.r16(shp+6u)));
 if(m.r32(i.cx+0x28u)>=eax){--eax;m.w32(i.cx+0x28u,eax);}return eax;
}
}
