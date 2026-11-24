#include "recovered/recovery_b1334.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/numeric_b80.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/leaf_b56_c.hpp"
#include "recovered/recovery_b612.hpp"
#include "recovered/recovery_b220.hpp"
#include "recovered/recovery_b514.hpp"
#include <array>
#include <initializer_list>
#include <stdexcept>
namespace ra2::recovered::b1334 {
namespace {
using U=std::uint32_t;using S=floating_b39::State;
constexpr U base=0x7d900000u,T=base+0x8000u,call_sp=base+0x4000u,ret=0x13579bdfu,map=0x81a820u;
void need(bool yes,const char*why){if(!yes)throw std::domain_error(why);}
floating_b39::Function helper(U r){for(const auto&e:floating_b39::entries_a())if(e.rva==r)return e.function;for(const auto&e:floating_b39::entries_b())if(e.rva==r)return e.function;throw std::runtime_error("1334 numeric dependency");}
void call(Memory&m,S&s,U r,std::initializer_list<U>args={}){m.w32(call_sp,ret);U p=call_sp+4u;for(U v:args){m.w32(p,v);p+=4u;}floating_b39::Frame f{};f.entry_sp=f.return_sp=f.sp=call_sp;f.outer_return=ret;helper(r)(m,s,f,{});need(f.sp==call_sp+4u+4u*U(args.size()),"1334 actual numeric RET");}
U pack(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16u);}
int sx(U x){return std::int16_t(x);}
int div256(U x){return std::int32_t(x)/256;}
U lookup(Memory&m,U xy,bool bounded){const int index=sx(xy)+512*sx(xy>>16u);const U limit=bounded?m.r32(map+0x13cu):0x40000u;
 need(index>=0&&U(index)<limit,"1334 finite real lookup index");const U p=m.r32(m.r32(map+0x138u)+4u*U(index));need(p,"1334 actual populated cell, no fallback");return p;}
bool valid(Memory&m,int x,int y){const int f0=std::int32_t(m.r32(map+0xf0u)),f4=std::int32_t(m.r32(map+0xf4u));return x+y>f0&&x-y<f0&&y-x<f0&&x+y<=f0+2*f4;}
void copy(Memory&m,U out,U from,U n){for(U k=0;k<n;++k)m.w32(out+4u*k,m.r32(from+4u*k));}
void clip(Memory&m,leaf::Memory&local,U out,U first,U second){
 for(U k=0;k<4u;++k){local.w32(base+0x1000u+4u*k,m.r32(first+4u*k));local.w32(base+0x1020u+4u*k,m.r32(second+4u*k));}
 leaf::Inputs c{};c.cx=out;c.dx=base+0x1000u;c.arg[0]=base+0x1020u;leaf::fun_0041fdf0(local,c);
}
U draw_a7(Memory&m,const Inputs&i){
 // Caller-specific74430 extension of B785: registered A7 is ordinary for
 //75040/5D46D0. Its separate745C0 exclusion must not suppress this pass.
 const U owner=i.cx,index=m.r32(owner+0x44u),type=m.r32(m.r32(0xa1e11cu)+4u*index),source=m.r32(type+0xa4u);
 need(index==0xa7u&&m.r32(type+0x264u)==index,"1334 real registered A7 index");
 need(m.r32(type)==0x7929c8u&&m.r32(0x792a64u)==0x5d57d0u&&source&&m.r32(owner+0x34u),"1334 actual cached source provider/context");
 need(m.r8(type+0x279u)==0u&&m.r8(type+0x278u)==0u&&m.r8(type+0x27au)==1u&&m.r32(type+0x268u)==0u&&(m.r8(owner+0x140u)&0x80u)==0u,"1334 ordinary A7 renderer path");
 const int height=std::int8_t(m.r8(owner+0x11bu));need(height==-1&&m.r16(source+6u)==1u,"1334 true frame0 depth13");
 const U point=i.arg[0],rect=i.arg[1];
 //5D46D0 returns(0,-12);75040 adds(30,viewportY-15*height+15).
 m.w32(T+0x200u,m.r32(point)+30u-m.r32(rect));
 m.w32(T+0x204u,m.r32(point+4u)+m.r32(0x821974u)+3u-U(15*height)-m.r32(rect+4u));
 i.arg[0]&=0xffffff00u;Inputs child{};child.cx=m.r32(0x821c9cu);child.dx=m.r32(owner+0x34u);
 child.arg={source,0u,T+0x200u,rect,0x4601u,0u,U(-2-15*height),0u,1000u,0u,0u,0u,0u,0u,0u,0u};child.fp=i.fp;
 const U eax=recovery_b514::fun_0049ebd0(m,child);i.fp=child.fp;return eax;
}
}
U fun_0069c990(Memory&outer,const Inputs&i){
 const U self=i.cx,rect=i.arg[0];
 need(outer.r32(rect)==0u&&outer.r32(rect+4u)==0u&&outer.r32(rect+8u)==1u&&outer.r32(rect+12u)==1u,"1334 positive input rectangle");
 need(outer.r32(self+0xb0u)==0u&&outer.r32(self+0xb4u)==138u&&outer.r32(map+0xf0u)==1u&&outer.r32(map+0xf4u)==4u,"1334 finite inverse/map contract");
 std::array<std::uint8_t,0x10000>bytes{};leaf::Memory local(bytes.data(),base,U(bytes.size()));Memory m=outer;m.add(local);S s{};s.fp=i.fp;
 const U x=m.r32(rect)+m.r32(self+0xb0u)-m.r32(0x821970u),y=m.r32(rect+4u)+m.r32(self+0xb4u)-m.r32(0x821974u);
 // Actual69C9D4 FILD X then Y, unlike the related437510 call order.
 s.fp.load_integer32(x);m.w32(T+0x3cu,s.fp.pop32());s.fp.load_integer32(y);m.w32(T+0x40u,s.fp.pop32());m.w32(T+0x44u,0u);
 s.dx=self+0xde4u;s.cx=T+0x48u;call(m,s,0x18e180u,{T+0x3cu});copy(m,T+0x3cu,s.ax,3u);
 s.fp.load32(m.r32(T+0x3cu));call(m,s,0x36aa50u);const U wx=s.ax;
 s.fp.load32(m.r32(T+0x40u));call(m,s,0x36aa50u);const U wy=s.ax;
 m.w32(T+0x78u,std::int32_t(wx)<0?0u:wx);m.w32(T+0x7cu,std::int32_t(wy)<0?0u:wy);m.w32(T+0x80u,0u);
 const U first=lookup(m,pack(div256(m.r32(T+0x78u)),div256(m.r32(T+0x7cu))),true),xy=m.r32(first+0x24u);
 const int start_x=sx(xy)-4,start_y=sx(xy>>16u)-2,last_row=std::int32_t(m.r32(rect+12u))/15+21,columns=std::int32_t(m.r32(rect+8u))/60+4;
 need(start_x==0&&start_y==2&&last_row==21&&columns==4,"1334 original inverse/populated scan origin");
 clip(m,local,T+0x90u,0x821970u,rect);copy(m,T+0x64u,T+0x90u,4u);
 for(unsigned pass=0;pass<2u;++pass)for(int row=last_row;row>=0;--row){
  const int rx=start_x+row/2,ry=start_y+(row+1)/2;
  for(int column=0;column<columns;++column){const int cx=rx+column,cy=ry-column;
   if(!valid(m,cx,cy))continue;
   const U cell=lookup(m,pack(cx,cy),false);if(m.r32(cell+0x44u)==0xffffffffu)continue;
   Inputs bounds{};bounds.cx=cell;bounds.arg[0]=T+0xa0u;bounds.fp=s.fp;
   const U bp=pass?recovery_b220::fun_00474d00(m,bounds):recovery_b612::fun_00474ab0(m,bounds);s.fp=bounds.fp;copy(m,T+0x54u,bp,4u);
   clip(m,local,T+0xb0u,T+0x64u,T+0x54u);
   if(std::int32_t(m.r32(T+0xb8u))<=0||std::int32_t(m.r32(T+0xbcu))<=0)continue;
   m.w32(T+0x48u,U(div256(U(cx)*256u+128u))*256u);m.w32(T+0x4cu,U(div256(U(cy)*256u+128u))*256u);m.w32(T+0x50u,0u);
   Inputs projection{};projection.cx=self;projection.fp=s.fp;
   if(!pass){projection.arg[0]=T+0x3cu;projection.arg[1]=T+0x48u;const U out=numeric_b80::fun_00697de0(m,projection);copy(m,T+0x30u,out,2u);m.w32(T+0x30u,m.r32(T+0x30u)-m.r32(self+0xb0u)-30u);m.w32(T+0x34u,m.r32(T+0x34u)-m.r32(self+0xb4u));}
   else {projection.arg[0]=T+0x48u;projection.arg[1]=T+0x30u;numeric_b88::fun_00698010(m,projection);m.w32(T+0x30u,m.r32(T+0x30u)-30u);}
   s.fp=projection.fp;
   need(cx==4&&cy==4&&m.r32(T+0x30u)==U(-30)&&m.r32(T+0x34u)==U(-18),"1334 actual target projected point");
   if(!pass){need(m.r32(cell+0x44u)==0xa7u,"1334 original745C0 A7 exclusion");/* Actual745C0 returns its loaded EAXA7; root ignores it. */}
   else {Inputs child{};child.cx=cell;child.arg[0]=T+0x30u;child.arg[1]=T+0x64u;child.fp=s.fp;(void)draw_a7(m,child);s.fp=child.fp;}
  }
 }
 i.fp=s.fp;return 0u; // Actual final second-pass column countdown ends EAX0.
}
U fun_00699160(Memory&m,const Inputs&i){
 need((i.arg[2]&255u)==0u&&m.r32(i.cx+0xe0u)==0u&&m.r32(0xaa60c8u)==0u,"1334 rectangle-only real outer dispatcher");
 need(std::int32_t(m.r32(i.arg[1]+8u))<=0,"1334 legitimate empty second rectangle");
 Inputs child=i;fun_0069c990(m,child);i.fp=child.fp;return m.r32(0xaa60c8u);
}
}
