#include "recovered/recovery_b1324.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/numeric_b80.hpp"
#include "recovered/recovery_b494.hpp"
#include "recovered/leaf_b56_c.hpp"
#include <array>
#include <initializer_list>
#include <stdexcept>
namespace ra2::recovered::b1324 {
namespace {
using U=std::uint32_t;using S=floating_b39::State;
constexpr U base=0x7d700000u,T=base+0x8000u,call_sp=base+0x4000u,ret=0x13579bdfu,map=0x81a820u;
void need(bool yes,const char*why){if(!yes)throw std::domain_error(why);}
floating_b39::Function helper(U r){for(const auto&e:floating_b39::entries_a())if(e.rva==r)return e.function;for(const auto&e:floating_b39::entries_b())if(e.rva==r)return e.function;throw std::runtime_error("B1324 numeric dependency");}
void call(Memory&m,S&s,U r,std::initializer_list<U>args={}){m.w32(call_sp,ret);U p=call_sp+4u;for(U v:args){m.w32(p,v);p+=4u;}floating_b39::Frame f{};f.entry_sp=f.return_sp=f.sp=call_sp;f.outer_return=ret;helper(r)(m,s,f,{});need(f.sp==call_sp+4u+4u*U(args.size()),"B1324 actual numeric RET");}
U pack(int x,int y){return U(std::uint16_t(x))|(U(std::uint16_t(y))<<16u);}
int sx(U x){return std::int16_t(x);}
int div256(U x){return static_cast<std::int32_t>(x)/256;}
U lookup(Memory&m,U xy,bool bounded){const int index=sx(xy)+512*sx(xy>>16u);const U limit=bounded?m.r32(map+0x13cu):0x40000u;
 if(index>=0&&U(index)<limit){const U p=m.r32(m.r32(map+0x138u)+4u*U(index));if(p)return p;}m.w32(0xa57634u,xy);return 0xa57610u;}
bool valid(Memory&m,int x,int y){const int f0=static_cast<std::int32_t>(m.r32(map+0xf0u)),f4=static_cast<std::int32_t>(m.r32(map+0xf4u));return x+y>f0&&x-y<f0&&y-x<f0&&x+y<=f0+2*f4;}
void copy(Memory&m,U out,U from,U n){for(U k=0;k<n;++k)m.w32(out+4u*k,m.r32(from+4u*k));}
void clip(Memory&m,leaf::Memory&local,U out,U first,U second){
 // The accepted leaf adapter requires one contiguous span. Copy its two
 // read-only, disjoint inputs into adapter temporaries; output stays at the
 // exact root-local slot, and accumulator arguments are the original NULLs.
 for(U k=0;k<4u;++k){local.w32(base+0x1000u+4u*k,m.r32(first+4u*k));local.w32(base+0x1020u+4u*k,m.r32(second+4u*k));}
 leaf::Inputs c{};c.cx=out;c.dx=base+0x1000u;c.arg[0]=base+0x1020u;leaf::fun_0041fdf0(local,c);
}
}
U fun_0069ce60(Memory&outer,const Inputs&i){
 const U self=i.cx,rect=i.arg[0];
 need(outer.r32(rect)==8u&&outer.r32(rect+4u)==6u&&outer.r32(rect+8u)==4u&&outer.r32(rect+12u)==3u,"B1324 positive input rectangle");
 need(outer.r32(self+0xb0u)==U(-38)&&outer.r32(self+0xb4u)==474u&&outer.r32(map+0xf0u)==1u&&outer.r32(map+0xf4u)==16u,"B1324 finite inverse/map contract");
 need(outer.r32(0xb0de50u)!=0u&&outer.r32(0x8249a0u)==0u,"B1324 active pixel scan and valid empty final object list");
 std::array<std::uint8_t,0x10000>bytes{};leaf::Memory local(bytes.data(),base,U(bytes.size()));Memory m=outer;m.add(local);S s{};s.fp=i.fp;
 const U x=m.r32(rect)+m.r32(self+0xb0u)-m.r32(0x821970u),y=m.r32(rect+4u)+m.r32(self+0xb4u)-m.r32(0x821974u);
 s.fp.load_integer32(y);const U yf=s.fp.pop32();s.fp.load_integer32(x);const U xf=s.fp.pop32();
 m.w32(T+0x34u,xf);m.w32(T+0x38u,yf);m.w32(T+0x3cu,0u);
 s.dx=self+0xde4u;s.cx=T+0x58u;call(m,s,0x18e180u,{T+0x34u});copy(m,T+0x34u,s.ax,3u);
 s.fp.load32(m.r32(T+0x34u));call(m,s,0x36aa50u);const U wx=s.ax;
 s.fp.load32(m.r32(T+0x38u));call(m,s,0x36aa50u);const U wy=s.ax;
 m.w32(T+0x4cu,static_cast<std::int32_t>(wx)<0?0u:wx);m.w32(T+0x50u,static_cast<std::int32_t>(wy)<0?0u:wy);m.w32(T+0x54u,0u);
 const U initial=lookup(m,pack(div256(m.r32(T+0x4cu)),div256(m.r32(T+0x50u))),true),xy=m.r32(initial+0x24u);
 const int start_x=sx(xy)-2,start_y=sx(xy>>16u),rows=static_cast<std::int32_t>(m.r32(rect+12u))/15+17,columns=static_cast<std::int32_t>(m.r32(rect+8u))/60+4;
 need(start_x==14&&start_y==17&&rows==17&&columns==4,"B1324 actual inverse/populated-cell scan bounds");
 for(int row=0;row<rows;++row){
  const int rx=start_x+row/2,ry=start_y+(row+1)/2;m.w32(T+0x10u,pack(rx,ry));
  for(int column=0;column<columns;++column){
   const int cx=sx(m.r32(T+0x10u)),cy=sx(m.r32(T+0x10u)>>16u);
   if(valid(m,cx,cy)){
    const U cell=lookup(m,m.r32(T+0x10u),false);
    m.w32(T+0x74u,U(div256(U(cx)*256u+128u))*256u);m.w32(T+0x78u,U(div256(U(cy)*256u+128u))*256u);m.w32(T+0x7cu,0u);copy(m,T+0x58u,T+0x74u,3u);
    Inputs projected{};projected.cx=self;projected.arg[0]=T+0x34u;projected.arg[1]=T+0x58u;projected.fp=s.fp;
    const U p=numeric_b80::fun_00697de0(m,projected);s.fp=projected.fp;copy(m,T+0x14u,p,2u);
    m.w32(T+0x64u,m.r32(self+0xb0u));m.w32(T+0x68u,m.r32(self+0xb4u));
    // Exact 6A1EA0: in-place pair subtraction before root's X -= 30.
    m.w32(T+0x14u,m.r32(T+0x14u)-m.r32(T+0x64u));m.w32(T+0x18u,m.r32(T+0x18u)-m.r32(T+0x68u));m.w32(T+0x14u,m.r32(T+0x14u)-30u);
    m.w32(T+0xa0u,m.r32(T+0x14u));m.w32(T+0xa4u,m.r32(T+0x18u)+m.r32(0x821974u));m.w32(T+0xa8u,60u);m.w32(T+0xacu,30u);
    clip(m,local,T+0xb0u,T+0xa0u,rect);copy(m,T+0x80u,T+0xb0u,4u);
    clip(m,local,T+0xc0u,0x821970u,T+0x80u);copy(m,T+0x90u,T+0xc0u,4u);
    if(static_cast<std::int32_t>(m.r32(T+0x98u))>0&&static_cast<std::int32_t>(m.r32(T+0x9cu))>0){
     m.w32(T+0x6cu,m.r32(T+0x14u)+m.r32(0x821970u));m.w32(T+0x70u,m.r32(T+0x18u)+m.r32(0x821974u));
     need(cx==16&&cy==16&&m.r32(T+0x6cu)==8u&&m.r32(T+0x70u)==6u,"B1324 actual positive B494 point");
     Inputs child=i;child.cx=cell;child.arg[0]=T+0x6cu;child.arg[1]=T+0x90u;child.fp=s.fp;recovery_b494::fun_00475120(m,child);s.fp=child.fp;
    }
   }
   m.w32(T+0x10u,pack(cx+1,cy-1));
  }
 }
 // Original41F5E0 reads actual8249A0=0, branches to its epilogue, and
 // leaves that complete loaded EAX0. This support route is not a new root.
 i.fp=s.fp;return m.r32(0x8249a0u);
}
U fun_00699530(Memory&m,const Inputs&i){
 need(m.r32(i.cx+0xe0u)==0u&&(i.arg[3]&255u)==0u&&m.r32(0xaa60c8u)==0u,"B1324 rectangle-only outer dispatcher");
 need(m.r32(i.arg[0]+8u)==4u&&m.r32(i.arg[0]+12u)==3u&&static_cast<std::int32_t>(m.r32(i.arg[1]+8u))<=0,"B1324 one positive outer rectangle");
 Inputs child=i;fun_0069ce60(m,child);i.fp=child.fp;
 i.arg[3]=0u;return m.r32(0xaa60c8u); // 699663 unconditional caller-word spill
}
}
