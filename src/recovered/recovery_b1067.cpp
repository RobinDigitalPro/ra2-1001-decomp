#include "recovered/recovery_b1067.hpp"
#include "recovered/recovery_b1065.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1067 {
namespace {
void need(bool x){if(!x)throw std::domain_error("1067 outside bounded positive ambient/existing-record domain");}
struct Ambient{std::array<unsigned,8>v;};
Ambient compute(Memory&m,const Inputs&i){
 const auto p=i.cx;need((m.r16(p+0x24u)||m.r16(p+0x26u))&&(m.r16(p+0x24u)!=65535u||m.r16(p+0x26u)!=65535u));need(m.r32(0xa56458u)==0u);
 const auto config=m.r32(0xa255c0u);need(config!=0u);Ambient a{};a.v[0]=65536u;
 for(unsigned k=0;k<4u;++k){const auto off=k?0x22b0u+4u*k:0x22acu;const auto value=m.r32(config+off);need(value>=1u&&value<=200u);a.v[k?4u+k:2u]=value*10u;}
 const unsigned weather=m.r8(0xa39574u)?1u:m.r32(0xa3957cu)==1u?2u:0u;const unsigned offsets[]{0x22c0u,0x22d8u,0x22f0u};const auto offset=m.r32(config+offsets[weather]),step=m.r32(config+offsets[weather]+4u);need(offset<=1000u&&step<=100u);const auto height=std::int32_t(std::int8_t(m.r8(p+0x11bu)));need(height>=0&&height<=15);
 const auto base=a.v[2];a.v[2]=std::min(2000, std::int32_t(base)+height*std::int32_t(step)-std::int32_t(offset));a.v[3]=a.v[2];a.v[4]=base+(unsigned(height)+4u)*step-offset;
 // Model-local frame for the unchanged accepted numeric helper. These five
 // initialized scalars are C++ locals, not original caller or arena storage.
 std::array<std::uint8_t,20>bytes{};leaf::Memory local(bytes.data(),0x10000u,unsigned(bytes.size()));auto call_memory=m;call_memory.add(local);
 Inputs call{};call.fp=i.fp;call.cx=0x10000u;call.dx=0x10004u;for(unsigned k=0;k<3u;++k)call.arg[k]=0x10008u+4u*k;
 call_memory.w32(call.cx,a.v[0]);call_memory.w32(call.dx,a.v[3]);for(unsigned k=0;k<3u;++k)call_memory.w32(call.arg[k],a.v[5u+k]);numeric_b80::fun_005365a0(call_memory,call);i.fp=call.fp;
 a.v[0]=call_memory.r32(call.cx);a.v[3]=call_memory.r32(call.dx);for(unsigned k=0;k<3u;++k)a.v[5u+k]=call_memory.r32(0x10008u+4u*k);
 a.v[4]=global_b26::sar(a.v[4]*a.v[0],16u);for(unsigned k=2;k<5u;++k)a.v[k]=unsigned(std::max(0,std::min(2000,global_b26::s32(a.v[k]))));return a;
}
unsigned quantize(unsigned x,unsigned mode){return std::min(1000u,x)&(mode==0u?0xffffff80u:mode==1u?0xffffffc0u:0xffffffe0u);}
}
std::uint32_t fun_00479040(Memory&m,const Inputs&i){const auto a=compute(m,i);for(unsigned k=0;k<8u;++k)m.w32(i.arg[k],a.v[k]);return a.v[4];}
std::uint32_t fun_00478f10(Memory&m,const Inputs&i){
 const auto pointers=i.arg;const auto a=compute(m,i);for(unsigned k=0;k<5u;++k)m.w32(pointers[k+1u],a.v[k]);i.arg[4]=a.v[7];i.arg[5]=a.v[6];const auto mode=m.r32(0xa2876cu);need(mode<=2u);const auto current=m.r32(i.cx+0x34u);
 if(current){for(unsigned k=0;k<3u;++k)i.arg[k+1u]=quantize(a.v[k+5u],mode);if(m.r32(current+0x198u)==i.arg[1]&&m.r32(current+0x19cu)==i.arg[2]&&m.r32(current+0x1a0u)==i.arg[3]){m.w32(pointers[0],current);return m.r32(current+0x1a0u);}}
 b1065::Inputs call{};call.cx=a.v[5];call.dx=a.v[6];call.arg[0]=a.v[7];const auto record=b1065::fun_005277f0(m,call);m.w32(pointers[0],record);return record;
}
}
