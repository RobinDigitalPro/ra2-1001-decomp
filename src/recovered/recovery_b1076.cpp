#include "recovered/recovery_b1076.hpp"
#include "recovered/recovery_b1072.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1076{
namespace{
using U=std::uint32_t;using I=std::int32_t;
void need(bool b){if(!b)throw std::domain_error("1076 outside populated south bridge approach and mode4 interval");}
U step(U p,I dy){return(p&65535u)|(U(std::uint16_t((p>>16u)+dy))<<16u);}
U cell(Memory&m,U p){const I x=std::int16_t(p),y=std::int16_t(p>>16u),index=512*y+x;need(index>=0&&index<0x40000);const auto c=m.r32(m.r32(0x81a958u)+4u*U(index));need(c!=0u);return c;}
U run(Memory&m,const Inputs&i,bool diamond){
 const auto origin=m.r32(i.arg[0]),north=step(origin,-1);need(m.r32(0x839da0u)==0xffff0000u&&m.r32(0x839db0u)==0x10000u);
 const auto flags=m.r32(cell(m,north)+0x140u);need((flags&0x500u)==0x400u&&(flags&0x800u)!=0u);
 U point=north,count=0u;
 do{point=step(point,1);if(!(m.r32(cell(m,point)+0x140u)&0x400u))break;need(++count<4u);}while(true);
 point=step(point,-2);need(count==2u&&point==origin);const I x=std::int16_t(point),y=std::int16_t(point>>16u);
 if(diamond){const I w=I(m.r32(0x81a910u)),h=I(m.r32(0x81a914u));need(x+y>w&&x-y<w&&y-x<w&&x+y<=w+2*h);}
 else{const I left=I(m.r32(i.cx+0x120u)),top=I(m.r32(i.cx+0x124u));need(x>=left&&x<=left+I(m.r32(i.cx+0x128u))&&y>=top&&y<=top+I(m.r32(i.cx+0x12cu)));}
 const auto c=cell(m,point);need(m.r32(m.r32(i.cx+0x138u)+4u*U(512*y+x))!=0u);
 const auto kind=m.r32(c+0x38u)-m.r32(diamond?0xa3a8b0u:0xa547a0u)+1u;need(U(kind-m.r32(0xa3aab0u))<4u&&m.r8(c+0x11au)==7u);
 // The caller owns both initialized locals. Neither local address escapes.
 std::array<std::uint8_t,32>bytes{};leaf::Memory local(bytes.data(),0x30000u,U(bytes.size()));auto memory=m;memory.add(local);memory.w32(0x30000u,point);for(U k=0;k<4u;++k)memory.w32(0x30010u+4u*k,m.r32(0xa56e48u+4u*k));
 Inputs call=i;call.arg[0]=0x30000u;call.arg[1]=4u;call.arg[2]=0x30010u;
 const auto result=diamond?b1072::fun_00555450(memory,call):b1072::fun_00550490(memory,call);need((result&255u)==0u);i.fp=call.fp;
 i.arg[0]=point; // Both originals reuse their incoming pointer argument word.
 return result;
}
}
U fun_00550a00(Memory&m,const Inputs&i){return run(m,i,false);}
U fun_005559c0(Memory&m,const Inputs&i){return run(m,i,true);}
}
