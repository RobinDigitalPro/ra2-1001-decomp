#include "recovery_b477.hpp"
#include "map_b106.hpp"
#include "recovery_b210.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b477 {
std::uint32_t fun_006a66a0(Memory&m,const Inputs&i){
 auto need=[](bool b){if(!b)throw std::domain_error("477 positive selected-cell update contract");};
 need(m.r8(m.r32(0xa1e0e4)+0x188)==0);
 const auto index=m.r32(i.cx+0x74);need(index<16);
 const auto packed=m.r32(m.r32(0xa255c0)+0x632+4*index);
 const auto x=std::int16_t(packed&0xffff),y=std::int16_t(packed>>16);
 need(x>=0&&x<512&&y>=0&&y<512);
 const auto cell=m.r32(m.r32(0x81a958)+4*(512*unsigned(y)+unsigned(x)));
 need(cell!=0&&m.r8(cell+0x11b)==0&&(m.r32(cell+0x140)&0x500)==0);
 const auto radius=m.r32(m.r32(0x821b88)+0x54c);need(radius==0);
 // Root selects the packed coordinate through actual25A130, then converts
 // it to the middle of the cell. This bounded route has zero height.
 const auto scratch=i.cx+0x6000;std::array<unsigned,3>saved;
 for(unsigned k=0;k<3;++k)saved[k]=m.r32(scratch+4*k);
 m.w32(scratch,256*unsigned(x)+128);m.w32(scratch+4,256*unsigned(y)+128);m.w32(scratch+8,0);
 Inputs q=i;q.cx=0x81a820;q.arg[0]=scratch;q.arg[1]=radius;
 (void)map_b106::fun_00547bb0(m,q);
 for(unsigned k=0;k<3;++k)m.w32(scratch+4*k,saved[k]);
 q.cx=0x81a820;const auto result=recovery_b210::fun_005570f0(m,q);i.fp=q.fp;
 return with_al(result,1);
}
}
