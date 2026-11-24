#include "recovered/recovery_b1072.hpp"
#include "recovered/recovery_b508.hpp"
#include "recovered/numeric_b88.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1072 {
namespace {
using U=std::uint32_t;using I=std::int32_t;
void need(bool v){if(!v)throw std::domain_error("1072 outside positive south interval and attached-tag contract");}
U add(U a,U b){return U(std::uint16_t(a+b))|(U(std::uint16_t((a>>16)+(b>>16)))<<16);}
U cell(Memory&m,U point){const I x=std::int16_t(point),y=std::int16_t(point>>16);const I k=512*y+x;need(k>=0&&k<0x40000);const auto p=m.r32(m.r32(0x81a958u)+4u*U(k));need(p!=0u);return p;}
struct Point{I x,y;};
Point project(Memory&m,const Inputs&i,U point,U height){
 // Initialized private model temporaries represent the two original stack
 // structs. Their addresses do not escape this composition.
 std::array<std::uint8_t,32> bytes{};leaf::Memory scratch(bytes.data(),0x10000u,U(bytes.size()));Memory local=m;local.add(scratch);
 local.w32(0x10000u,U(I(std::int16_t(point))*256+128));local.w32(0x10004u,U(I(std::int16_t(point>>16))*256+128));local.w32(0x10008u,height);
 Inputs call=i;call.cx=m.r32(0x821cacu);call.arg[0]=0x10000u;call.arg[1]=0x10010u;
 numeric_b88::fun_00698010(local,call);i.fp=call.fp;
 return{I(local.r32(0x10010u)),I(local.r32(0x10014u))};
}
void extend_rectangle(Memory&m,U out,Point a,Point b){
 const I left=std::min(a.x,b.x)-64,top=std::min(a.y,b.y)-64;
 I width=(a.x>=b.x?a.x-b.x:b.x-a.x)+128,height=(a.y>=b.y?a.y-b.y:b.y-a.y)+128;
 I x=left,y=top;
 if(I(m.r32(out+8u))>0&&I(m.r32(out+12u))>0){
  x=I(m.r32(out));y=I(m.r32(out+4u));I oldw=I(m.r32(out+8u)),oldh=I(m.r32(out+12u));
  if(x>left){oldw+=x-left;x=left;}if(y>top){oldh+=y-top;y=top;}
  if(x+oldw<left+width)oldw=left+width-x+1;
  if(y+oldh<top+height)oldh=top+height-y+1;
  width=oldw;height=oldh;
 }
 m.w32(out,U(x));m.w32(out+4u,U(y));m.w32(out+8u,U(width));m.w32(out+12u,U(height));
}
U run(Memory&m,const Inputs&i,U base_global){
 need(i.arg[1]==4u&&i.arg[2]!=0u);
 const auto origin=cell(m,m.r32(i.arg[0])),start=m.r32(origin+0x24u),step=m.r32(0x839db0u);need(step==0x10000u);
 const auto first=add(start,step);auto end=first;U length=1u;
 for(;;){
  const auto c=cell(m,end),kind=m.r32(c+0x38u)-m.r32(base_global)+1u,group=m.r32(0xa3aab0u);
  if(m.r8(c+0x11au)==2u&&(kind==m.r32(0xa55c48u)||kind==m.r32(0xa3afc8u)||U(kind-group)<4u))break;
  need(++length<30u);end=add(end,step);
 }
 const U z=U(I(std::int8_t(m.r8(origin+0x11bu))))*m.r32(0xa57848u);
 const auto a=project(m,i,start,z),b=project(m,i,end,z);extend_rectangle(m,i.arg[2],a,b);
 // Exact selected path: the first clear bit starts one genuine interval-tag
 // visit; all subsequent cells have bit7 set, so no recursive repair occurs.
 bool previous_clear=false,visited=false;U last_set=0xffffffffu,point=start;
 for(U n=0u;n<length;++n){
  const auto c=cell(m,point);const bool set=(m.r32(c+0x140u)&0x80u)!=0u;
  if(set&&previous_clear)last_set=m.r32(c+0x24u);
  need(set||previous_clear||last_set==0xffffffffu);
  previous_clear=!set;
  if(previous_clear&&!visited){Inputs call=i;call.arg[0]=first;call.arg[1]=end;recovery_b508::fun_00555130(m,call);i.fp=call.fp;visited=true;}
  point=add(m.r32(c+0x24u),step);
 }
 need(visited);return length&0xffffff00u; // original final XOR AL,AL
}
}
std::uint32_t fun_00550490(Memory&m,const Inputs&i){return run(m,i,0xa547a0u);}
std::uint32_t fun_00555450(Memory&m,const Inputs&i){return run(m,i,0xa3a8b0u);}
}
