#include "recovered/recovery_b1321.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/recovery_b369.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <initializer_list>
#include <stdexcept>
namespace ra2::recovered::b1321 {
namespace {
using U=std::uint32_t;using S=floating_b39::State;
constexpr U base=0x7d600000u,T=base+0x8000u,call_sp=base+0x4000u,ret=0x13579bdfu,map=0x81a820u;
void need(bool yes,const char*why){if(!yes)throw std::domain_error(why);}
floating_b39::Function helper(U r){for(const auto&e:floating_b39::entries_a())if(e.rva==r)return e.function;for(const auto&e:floating_b39::entries_b())if(e.rva==r)return e.function;throw std::runtime_error("B1321 numeric dependency");}
void call(Memory&m,S&s,U r,std::initializer_list<U>args={}){m.w32(call_sp,ret);U p=call_sp+4u;for(U v:args){m.w32(p,v);p+=4u;}floating_b39::Frame f{};f.entry_sp=f.return_sp=f.sp=call_sp;f.outer_return=ret;helper(r)(m,s,f,{});need(f.sp==call_sp+4u+4u*U(args.size()),"B1321 actual numeric RET");}
U pack(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16u);}
int sx(U x){return std::int16_t(x);}
int div256(U v){return static_cast<std::int32_t>(v)/256;}
U lookup(Memory&m,U xy,bool bounded){const int index=sx(xy)+512*sx(xy>>16u);const U limit=bounded?m.r32(map+0x13cu):0x40000u;
 if(index>=0&&U(index)<limit){const U p=m.r32(m.r32(map+0x138u)+4u*U(index));if(p)return p;}
 m.w32(0xa57634u,xy);return 0xa57610u;}
bool valid(Memory&m,int x,int y){const int f0=static_cast<std::int32_t>(m.r32(map+0xf0u)),f4=static_cast<std::int32_t>(m.r32(map+0xf4u));return x+y>f0&&x-y<f0&&y-x<f0&&x+y<=f0+2*f4;}
void inverse(Memory&m,S&s,U self,U rect,U out){
 const U x=m.r32(rect)+m.r32(self+0xb0u)-m.r32(0x821970u),y=m.r32(rect+4u)+m.r32(self+0xb4u)-m.r32(0x821974u);
 // Both original437510 call sites FILD Y then X and store each as float.
 s.fp.load_integer32(y);const U yf=s.fp.pop32();s.fp.load_integer32(x);const U xf=s.fp.pop32();
 m.w32(T+0x2cu,xf);m.w32(T+0x30u,yf);m.w32(T+0x34u,0u);
 s.dx=self+0xde4u;s.cx=T+0x44u;call(m,s,0x18e180u,{T+0x2cu});
 for(U k=0;k<3u;++k)m.w32(T+0x2cu+4u*k,m.r32(s.ax+4u*k));
 s.fp.load32(m.r32(T+0x2cu));call(m,s,0x36aa50u);const U wx=s.ax;
 s.fp.load32(m.r32(T+0x30u));call(m,s,0x36aa50u);const U wy=s.ax;
 // Actual41B630 writes a root-local integerXYZ; Z literal0.
 m.w32(out,wx);m.w32(out+4u,wy);m.w32(out+8u,0u);
}
}
U fun_0069d880(Memory&outer,const Inputs&i){
 const U self=i.cx,rect=i.arg[0],clip=i.arg[1];
 need(outer.r32(rect)==0u&&outer.r32(rect+4u)==0u&&outer.r32(rect+8u)==1u&&outer.r32(rect+12u)==1u,"B1321 positive one-pixel input rectangle");
 for(U k=0;k<4u;++k)need(outer.r32(clip+4u*k)==outer.r32(rect+4u*k),"B1321 matching one-pixel clip");
 need(outer.r32(self+0xb0u)==0u&&outer.r32(self+0xb4u)==30u&&outer.r32(map+0xf0u)==1u&&outer.r32(map+0xf4u)==1u,"B1321 finite viewport and one-valid-cell map");
 std::array<std::uint8_t,0x10000> bytes{};leaf::Memory local(bytes.data(),base,U(bytes.size()));Memory m=outer;m.add(local);S s{};s.fp=i.fp;
 inverse(m,s,self,rect,T+0x38u);
 const int first_x=div256(m.r32(T+0x38u)),first_y=div256(m.r32(T+0x3cu));
 // First42AD30 result overwrites outerarg0. The original rectangle remains
 // available in EDI; the independent second transform still reads it.
 i.arg[0]=pack(first_x-2,first_y);
 inverse(m,s,self,rect,T+0x20u);
 for(U k=0;k<3u;++k)m.w32(T+0x38u+4u*k,m.r32(T+0x20u+4u*k));
 const U initial=lookup(m,pack(div256(m.r32(T+0x38u)),div256(m.r32(T+0x3cu))),true);
 const U origin=m.r32(initial+0x24u);const int start_x=sx(origin)-2,start_y=sx(origin>>16u)+3;
 const int rows=static_cast<std::int32_t>(m.r32(rect+12u))/15+20,columns=static_cast<std::int32_t>(m.r32(rect+8u))/60+7;
 need(start_x==-2&&start_y==3&&rows==20&&columns==7,"B1321 actual inverse/map-derived scan bounds");
 for(int row=0;row<rows;++row){
   const int rx=start_x+row/2,ry=start_y+(row+1)/2;i.arg[1]=pack(rx,ry);i.arg[0]=i.arg[1];
   for(int column=0;column<columns;++column){
     const int x=sx(i.arg[0]),y=sx(i.arg[0]>>16u);
     if(valid(m,x,y)){
       const U wx=U(div256(U(x)*256u+128u))*256u,wy=U(div256(U(y)*256u+128u))*256u;
       m.w32(T+0x44u,wx);m.w32(T+0x48u,wy);m.w32(T+0x4cu,0u);
       floating_b61::Inputs projection{};projection.cx=self;projection.arg[0]=T+0x44u;projection.arg[1]=T+0x2cu;projection.fp=s.fp;
       numeric_b88::fun_00698010(m,projection);s.fp=projection.fp;
       m.w32(T+0x2cu,m.r32(T+0x2cu)-30u);
       const U cell=lookup(m,i.arg[0],false);
       need(x==1&&y==1&&m.r32(T+0x2cu)==U(-30)&&m.r32(T+0x30u)==0u,"B1321 actual projectedB369point");
       Inputs child=i;child.cx=cell;child.arg[0]=T+0x2cu;child.arg[1]=clip;child.fp=s.fp;
       recovery_b369::fun_004751d0(m,child);s.fp=child.fp;
     }
     i.arg[0]=pack(x+1,y-1);
   }
 }
 i.fp=s.fp;return 0u; // final original inner counter DEC leaves full EAX0
}
U fun_00698f10(Memory&m,const Inputs&i){
 need((i.arg[2]&255u)==0u&&m.r32(i.cx+0xe0u)==0u&&m.r32(0xaa60c8u)==0u,"B1321 positive rectangle-only outer dispatcher");
 const U first=i.arg[0],second=i.arg[1];
 need(m.r32(first+8u)==1u&&m.r32(first+12u)==1u&&static_cast<std::int32_t>(m.r32(second+8u))<=0,"B1321 exactly one positive outer rectangle");
 Inputs child=i;child.arg[0]=first;child.arg[1]=first;
 fun_0069d880(m,child);i.fp=child.fp;
 // Child's rewritten arguments occupy its pushed call frame. The outer
 // conditional arg2 counter is never written when self+E0 is zero.
 return m.r32(0xaa60c8u);
}
}
