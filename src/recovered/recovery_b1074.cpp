#include "recovered/recovery_b1074.hpp"
#include "recovered/recovery_b1065.hpp"
#include "platform/observed_ticks1074.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <stdexcept>
namespace ra2::recovered::b1074{
static void need(bool v){if(!v)throw std::domain_error("1074 outside positive forced pending-light update");}
static unsigned time(Memory&m,const Inputs&i){need(m.r32(0x7cc7dcu)!=0xffffffffu&&m.r32(0x81f788u)==0u&&m.r32(0x81f78cu)==0x3ff00000u);const auto value=ra2::platform::ticks1074::Tick::get();ra2::platform::x87_scalar_b46::load_integer64(i.fp,std::uint64_t(value));return value;}
static void mark(Memory&m){const auto screen=m.r32(0x821cacu);if(screen)m.w8(screen+0xd7du,1u);if(m.r32(0x81a82cu)!=2u)m.w32(0x81a82cu,1u);m.w8(0x81b974u,m.r8(0x81b974u)+1u);}
unsigned fun_00535a10(Memory&m,const Inputs&i,Heap&h){need(i.cx==0u&&(i.dx&255u)==1u&&m.r8(0xa564b4u)==0u&&m.r32(0xa564acu)==0u);time(m,i);const auto start=i.fp.pop64();m.w32(0xa564a4u,m.r32(0xa564a4u)+1u);const auto n=m.r32(0xa56488u),array=m.r32(0xa5647cu);need(n>=2u&&n<=4u&&m.r32(0xa564a8u)==0u&&m.r32(0x7ca26cu)==50u);m.w32(0xa564b0u,n);m.w32(0xa564acu,n-1u);
 for(unsigned left=n;left>0u;--left){const auto j=left-1u,p=h.r32(array+4u*j);need(h.r32(p)==0u);const auto xy=h.r32(p+16u),x=xy&65535u,y=xy>>16u;const auto cell=m.r32(m.r32(0x81a958u)+4u*(512u*y+x));need(cell!=0u);std::array<unsigned char,24>bytes{};leaf::Memory local(bytes.data(),0x20000u,unsigned(bytes.size()));auto memory=m;memory.add(local);Inputs call{};call.cx=cell;call.fp=i.fp;for(unsigned k=0;k<6u;++k)call.arg[k]=0x20000u+4u*k;b1067::fun_00478f10(memory,call);i.fp=call.fp;h.w32(p,memory.r32(0x20000u));h.w32(p+4u,memory.r32(0x20004u));for(unsigned k=0;k<4u;++k){const auto v=memory.r32(0x20008u+4u*k);h.w8(p+8u+2u*k,v);h.w8(p+9u+2u*k,v>>8u);}m.w32(0xa564b0u,m.r32(0xa564b0u)-1u);m.w32(0xa564acu,j-1u);}
 m.w8(0xa564b4u,1u);i.fp.load_integer32(0u);const auto budget=i.fp.pop64();time(m,i);i.fp.subtract64(start);i.fp.reverse_subtract64(budget);i.fp.pop_st0();
 for(unsigned j=0;j<n;++j){const auto p=h.r32(array+4u*j),xy=h.r32(p+16u),cell=m.r32(m.r32(0x81a958u)+4u*(512u*(xy>>16u)+(xy&65535u)));b1065::Inputs call{};call.cx=cell;call.arg[0]=h.r32(p);call.arg[1]=h.r32(p+4u);for(unsigned k=0;k<4u;++k)call.arg[k+2u]=h.r8(p+8u+2u*k)|(h.r8(p+9u+2u*k)<<8u);b1065::fun_00478cf0(m,call);need(h.release(p)!=0u);}
 m.w32(0xa56488u,0u);need(m.r8(0xa56485u)==1u&&h.release(array)!=0u);m.w32(0xa5647cu,0u);m.w8(0xa56485u,0u);m.w32(0xa56480u,0u);m.w8(0xa564b4u,0u);mark(m);
 const auto tick=time(m,i);i.fp.subtract64(start);i.fp.reverse_subtract64(budget);ra2::platform::x87_extended::compare64(i.fp,floating_b61::read64(m,0x786610u));const auto status=i.fp.status();unsigned eax=(tick&0xffff0000u)|status;if((status&0x4100u)==0u){eax=m.r32(0xa564a4u);need(eax<=m.r32(0xa564a8u)+m.r32(0x7ca26cu));}i.fp.pop_st0();return eax;
}
}
