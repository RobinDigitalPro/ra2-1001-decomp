#define NOMINMAX
#include <windows.h>
#include <objidl.h>
#include "recovered/recovery_b976.hpp"
#include "platform/ole_stream951.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b976{
namespace {
using U=std::uint32_t;void need(bool b,const char*s){if(!b)throw std::runtime_error(s);}
void read(IStream*s,void*p,unsigned n){need(s->Read(p,n,nullptr)==S_OK,"976 complete successful actual Read");}
U truncation(Memory&m,const Inputs&i){const auto wanted=std::uint16_t(m.r32(0x7c3a04u));if(i.fp.control()!=wanted)i.fp.load_control(wanted);return U(i.fp.pop_integer64());}
void construct(Memory&m,const Inputs&i,Heap&h,U p){
 // B107/ B71 numeric composition, restricted here to packedcell(0,0), scale1,
 // and small exact integers. Actual36AA50 leaves the truncation CW installed.
 const auto config=m.r32(0x821b88u),ticks=m.r32(0xa2896cu);
 h.w32(p,0xffffffffu);h.w32(p+0x10u,0x3f490fdbu);h.w32(p+0x14u,m.r32(config+0x8cu));h.w32(p+0x18u,0u);h.w32(p+0x1cu,m.r32(config+0x80u));h.w32(p+0x20u,0u);h.w32(p+0x24u,ticks);h.w32(p+0x2cu,0u);h.w32(p+0x30u,ticks);h.w32(p+0x38u,0u);h.w8(p+0x3cu,1u);h.w8(p+0x3du,1u);
 const U scale=m.r32(0x81bca4u),origin_x=m.r32(0x81bcb8u),origin_y=m.r32(0x81bcbcu);need(scale==0x3f800000u,"976 finite projection scale1");
 i.fp.load_integer32(m.r32(0x81bcacu));i.fp.multiply32(scale);ra2::platform::x87_extended::add_integer32(i.fp,origin_x);const auto projected_x=truncation(m,i);
 i.fp.load_integer32(0u-m.r32(0x81bcb4u));i.fp.multiply32(scale);ra2::platform::x87_extended::add_integer32(i.fp,origin_y);const auto projected_y=truncation(m,i);
 const auto x=projected_x+(projected_x==origin_x-1u?1u:0u)-origin_x,y=projected_y-origin_y;
 h.w32(p+4u,x);h.w32(p+8u,y);const auto distance=std::max({std::int32_t(x),std::int32_t(y),std::int32_t(m.r32(0x81bcc0u)-x),std::int32_t(m.r32(0x81bcc4u)-y)});i.fp.load_integer32(U(distance));h.w32(p+0xcu,i.fp.pop32());
 m.w32(0xa9e2e0u,0u);const auto count=m.r32(0xa9e318u);need(count<m.r32(0xa9e310u),"976 preallocated global registration vector");m.w32(0xa9e318u,count+1u);m.w32(m.r32(0xa9e30cu)+4u*count,p);
}
}
U fun_006338a0(Memory&m,const Inputs&i,Heap&h){need(i.cx==ra2::platform::ole_stream951::Stream::current().address(),"976 genuine ECX IStream");need(m.r32(0xa9e318u)==0u&&m.r32(0xa9e310u)==8u,"976 empty preallocated collection");auto*s=reinterpret_cast<IStream*>(std::uintptr_t(i.cx));U count=0;read(s,&count,4u);need(count>=1u&&count<=4u,"976 count1..4");for(unsigned j=0;j<count;++j){const auto p=h.allocate(64u);need(p!=0u,"976 actual successful allocation");construct(m,i,h,p);read(s,reinterpret_cast<void*>(std::uintptr_t(p)),64u);}U tail=0;read(s,&tail,4u);m.w32(0xa9e2e0u,tail);return 1u;}
}
