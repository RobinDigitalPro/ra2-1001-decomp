#include "recovery_b1227.hpp"
#include "recovered/numeric_b105.hpp"
#include <stdexcept>
namespace ra2::recovered::b1227 {namespace {
void need(bool x){if(!x)throw std::domain_error("1227 finite actual DirectDraw diagonal");}
void clip(Memory&m,unsigned x,unsigned y,unsigned length,Observation&o){
 std::array<unsigned char,32>bytes{};constexpr unsigned a=0xf2200000u;
 leaf::Memory local(bytes.data(),a,bytes.size());Memory work=m;work.add(local);
 for(unsigned k=0;k<8u;++k)work.w32(a+4u*k,std::array<unsigned,8>{x,y,x+length,y+length,0u,0u,16u,12u}[k]);
 floating_b61::Inputs i{};i.cx=a;i.dx=a+8u;i.arg[0]=a+16u;i.fp.image=platform::x87::capture_host();
 need((numeric_b105::fun_00760f60(work,i)&255u)==1u);
 need(work.r32(a)==x&&work.r32(a+4u)==y&&work.r32(a+8u)==x+length&&work.r32(a+12u)==y+length);
 platform::x87::restore_host(i.fp.image);++o.clips;
}
}
unsigned run(Memory&m,const Inputs&i,Api&api,Observation&o){
 const unsigned surface=m.r32(0x821ca4u),offset=i.cx,color=i.dx,x=i.arg[0],y=i.arg[1],length=i.arg[2]-x;
 need(offset<=2u&&length>=1u&&length<=4u&&i.arg[3]==y+length&&i.arg[4]==0u&&x+offset+length<16u&&y+length<12u);
 need(m.r32(0x821970u)==0u&&m.r32(0x821974u)==0u&&m.r32(0x821978u)==16u&&m.r32(0x82197cu)==12u&&m.r32(surface)==0x78bbe4u);
 // Equal deltas select the X-offset leg; both actual clipping calls retain endpoints.
 i.arg[0]+=offset;i.arg[2]+=offset;clip(m,x+offset,y,length,o);clip(m,x+offset,y,length,o);
 Inputs lock{};lock.cx=surface;lock.arg[0]=x+offset;lock.arg[1]=y;b1198::Observation got;
 const unsigned pixels=b1198::run(m,lock,api,0xaa990u,got);o.api_calls+=got.calls;
 need(m.r32(surface+0x10u)==4u);const unsigned pitch=m.r32(m.r32(surface+0x20u)+0x10u);need(pitch==64u);
 // Original75F50A equal-delta branch writes length steps, excludes the far endpoint,
 // and uses WORD stores for every format other than one byte. Keep that exact behavior.
 for(unsigned j=0;j<length;++j){m.w16(pixels+j*(pitch+2u),color);++o.pixels;}
 Inputs unlock{};unlock.cx=surface;b1198::Observation freed;const unsigned result=b1198::run(m,unlock,api,0xaab50u,freed);o.api_calls+=freed.calls;
 need(result==1u);return result;
}
}
