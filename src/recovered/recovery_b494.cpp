#include "recovered/recovery_b494.hpp"
#include "recovered/recovery_b487.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b494 {
namespace {
using U=std::uint32_t;
U select(Memory&m,U xy,bool upper){
 const int x=std::int16_t(m.r16(xy)),y=std::int16_t(m.r16(xy+2));
 const U table=m.r32(0x81a958),off=upper?0x140:0x12c,bit=upper?2:8;
 auto cell=[&](int xx,int yy){
  if(xx<1||xx>510||yy<1||yy>510)throw std::domain_error("494 initialized interior grid");
  const U p=m.r32(table+4*U(xx+512*yy));if(!p)throw std::domain_error("494 populated neighbors");return p;
 };
 const U center=m.r32(cell(x,y)+off);
 if(!(center&bit))return center&(upper?3:24)?0xffffffffu:0xfffffffeu;
 constexpr int dx[]={-1,0,1,-1,1,-1,0,1},dy[]={-1,-1,-1,0,0,1,1,1};
 constexpr U flag[]={64,128,1,32,2,16,8,4};U mask=0;
 for(unsigned k=0;k<8;++k)if(!(m.r8(cell(x+dx[k],y+dy[k])+off)&bit))mask|=flag[k];
 return U(std::int32_t(std::int8_t(m.r8(0x797264+mask))));
}
U frame(U v){return v==0xfffffffeu?15:v==0xffffffffu?0:v;}
}
std::uint32_t fun_00475120(Memory&m,const Inputs&i){
 const U self=i.cx,pos=i.arg[0],clip=i.arg[1];auto nested=i;
 U a=select(m,self+36,false);m.w8(self+0x120,a);
 nested.arg[0]=pos;nested.arg[1]=clip;nested.arg[2]=frame(a);
 recovery_b487::fun_00473e60(m,nested);
 U b=select(m,self+36,true);m.w8(self+0x121,b);
 if((m.r32(m.r32(0xa255c0))&0x1000)&&!m.r8(m.r32(0xa1e0e4)+0x13d)){
  nested.arg[0]=pos;nested.arg[1]=clip;nested.arg[2]=frame(b);
  return recovery_b487::fun_00474110(m,nested);
 }
 return b;
}
}
