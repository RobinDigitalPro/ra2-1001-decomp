#include "recovered/recovery_b1338.hpp"
#include "recovered/numeric_b105.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/leaf_b56_c.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1338 {
namespace {
using U=std::uint32_t;using floating_b61::s32;using floating_b61::sar;
void need(bool v,const char*why){if(!v)throw std::domain_error(why);}
void slot(Memory&m,U self,U off,U target){need(m.r32(self)==0x785ef8u&&m.r32(0x785ef8u+off)==target,"B1338 genuine software vtable");}
U format(Memory&m,U s){slot(m,s,0x70u,0x4113b0u);return m.r32(s+0x10u);}
U pitch(Memory&m,U s){slot(m,s,0x74u,0x4113c0u);slot(m,s,0x7cu,0x4112c0u);return m.r32(s+4u)*m.r32(s+0x10u);}
U lock(Memory&m,U s,U x,U y){slot(m,s,0x5cu,0x411370u);m.w32(s+12u,m.r32(s+12u)+1u);
 const U pixels=m.r32(s+20u),dx=format(m,s)*x;return pixels+dx+pitch(m,s)*y;}
U unlock(Memory&m,U s){slot(m,s,0x60u,0x4112f0u);const U count=m.r32(s+12u)-1u;m.w32(s+12u,count);return (count&0xffffff00u)|1u;}
U rectangle(Memory&m,U s,U out){slot(m,s,0x78u,0x411290u);m.w32(out,0u);m.w32(out+4u,0u);m.w32(out+8u,m.r32(s+4u));m.w32(out+12u,m.r32(s+8u));return out;}
// Actual761C80 and411230 have identical bodies; their original byte pins
// remain separate. The returned pointer is derived from a genuine lock.
U ring_pointer(Memory&m,U r,U x,U y){const U s=m.r32(r+20u);U p=lock(m,s,x,y);unlock(m,s);p+=m.r32(r+16u);if(p>=m.r32(r+28u))p-=m.r32(r+32u);return p;}
void wrap(Memory&m,U r,U&p){if(p>=m.r32(r+28u))p-=m.r32(r+32u);}
U channel(Memory&m,U pixel,U shift,U expand){return ((pixel>>(m.r32(shift)&31u))<<(m.r32(expand)&31u))&255u;}
U blend_channel(Memory&m,U old,U incoming,U alpha,U aux,U expand,U shift){
 U v=sar(old*(256u-alpha),8u)+incoming;v=sar(v*aux,7u);v=sar(v,m.r32(expand));return v<<(m.r32(shift)&31u);}
U height(Memory&m,ra2::platform::x87::State&fp,U z,U sp){
 floating_b39::State s{};s.cx=z;s.fp=fp;constexpr U ret=0x13579bdfu;m.w32(sp,ret);
 floating_b39::Frame f{};f.entry_sp=f.return_sp=f.sp=sp;f.outer_return=ret;
 floating_b39::Function fn=nullptr;for(const auto&e:floating_callers_b40::entries_a())if(e.rva==0x297fb0u)fn=e.function;
 need(fn!=nullptr,"B1338 closed original697FB0 helper");fn(m,s,f,{});need(f.sp==sp+4u,"B1338 actual height RET");fp=s.fp;return s.ax;
}
bool sentinel(Memory&m,U p){return m.r32(p)==m.r32(0xa56578u)&&m.r32(p+4u)==m.r32(0xa5657cu)&&m.r32(p+8u)==m.r32(0xa56580u);}
}
U fun_004ae6d0(Memory&outer,const Inputs&i){
 const U self=i.cx,rect=i.arg[0],p0=i.arg[1],p1=i.arg[2],color=i.arg[3],alpha=i.arg[4];
 need(alpha>=248u&&alpha<=254u&&i.arg[5]==U(-2)&&i.arg[6]==U(-2),"B1338 finite positive alpha/depth route");
 need(i.fp.image.word(8)==0xffffu&&(i.fp.image.word(4)&0x3800u)==0u,"B1338 clipper requires eight free x87 registers");
 need(outer.r32(self+4u)==4u&&outer.r32(self+8u)==4u&&outer.r32(self+16u)==2u&&outer.r32(self+12u)==0u,"B1338 borrowed four-by-four software surface");
 constexpr U base=0x7d900000u,T=base+0x8000u;
 std::array<std::uint8_t,0x10000> bytes{};leaf::Memory local(bytes.data(),base,U(bytes.size()));Memory m=outer;m.add(local);
 rectangle(m,self,T+0x4cu);
 // Original41FDF0 reads disjoint immutable caller and surface rectangles.
 // Relocating only those input records gives its contiguous leaf interface
 // the same bytes and alias relation; its output is in this private frame.
 for(U k=0;k<4u;++k)m.w32(T+0x100u+4u*k,m.r32(rect+4u*k));
 leaf::Inputs intersection{};intersection.cx=T+0x3cu;intersection.dx=T+0x100u;intersection.arg[0]=T+0x4cu;
 leaf::fun_0041fdf0(local,intersection);
 for(U k=0;k<4u;++k)m.w32(T+0x6cu+4u*k,m.r32(T+0x3cu+4u*k));
 need(m.r32(T+0x6cu)==0u&&m.r32(T+0x70u)==0u&&m.r32(T+0x74u)==2u&&m.r32(T+0x78u)==2u,"B1338 positive actual intersection");
 U x0=m.r32(p0)+m.r32(T+0x6cu),y0=m.r32(p0+4u)+m.r32(T+0x70u);
 U x1=m.r32(p1)+m.r32(T+0x6cu),y1=m.r32(p1+4u)+m.r32(T+0x70u);
 need(x0==0u&&y0==0u&&x1==1u&&y1==1u,"B1338 finite interior diagonal");
 m.w32(T+0x5cu,x0);m.w32(T+0x60u,y0);m.w32(T+0x64u,x1);m.w32(T+0x68u,y1);
 Inputs clip{};clip.cx=T+0x5cu;clip.dx=T+0x64u;clip.arg[0]=T+0x6cu;clip.fp=i.fp;
 need((numeric_b105::fun_00760f60(m,clip)&255u)!=0u,"B1338 genuine positive clipper");i.fp=clip.fp;
 need(m.r32(T+0x5cu)==x0&&m.r32(T+0x60u)==y0&&m.r32(T+0x64u)==x1&&m.r32(T+0x68u)==y1,"B1338 unchanged endpoints exclude distance interpolation");
 i.arg[1]=i.arg[5];i.arg[2]=i.arg[6];
 format(m,self);i.arg[5]=lock(m,self,x0,y0);
 const U depth=m.r32(0x821facu),aux=m.r32(0x8198f4u);need(depth!=0u&&aux!=0u,"B1338 actual ring owners");
 U dp=ring_pointer(m,depth,x0,y0-m.r32(depth+4u));U ap=ring_pointer(m,aux,x0,y0-m.r32(aux+4u));
 // MOV AX replaces only the low half of the produced auxiliary pointer.
 U z=(ap&0xffff0000u)|((m.r16(depth+36u)+m.r16(depth+4u))&65535u);
 z=z-y0-m.r32(T+0x70u)+i.arg[1];i.arg[6]=z;i.arg[0]=m.r32(depth+40u);
 need(i.arg[5]!=0u&&i.arg[0]==4u,"B1338 valid destination and ring row stride");
 const U red=sar(m.r8(color)*alpha,8u),green=sar(m.r8(color+1u)*alpha,8u),blue=sar(m.r8(color+2u)*alpha,8u);
 const U dx=x1-x0,dy=y1-y0;const U delta=i.arg[2]-i.arg[1];
 i.arg[4]=dy;i.arg[1]=delta;const U row_pitch=pitch(m,self);
 need(s32(dy)>0&&s32(delta)==0&&s32(dx)<=s32(dy),"B1338 actual Y-major branch");
 i.arg[1]=2u*dx;i.arg[4]=2u*dy;i.arg[2]=2u*delta;
 i.arg[3]=i.arg[1]-dy;U depth_error=i.arg[2]-dy,pixel_offset=0u,remaining=dy;
 do{
  const U coverage=m.r16(ap);
  if((i.arg[6]&65535u)<m.r16(dp)&&coverage){
   const U pixel=m.r16(i.arg[5]+pixel_offset);
   const U r=channel(m,pixel,0x83b2e8u,0x83b2ecu),g=channel(m,pixel,0x83b2f8u,0x83b2fcu),b=channel(m,pixel,0x83b2f0u,0x83b2f4u);
   // Original Y-major order is blue, green, red; every SAR and byte cut
   // is retained before RGB565 recombination.
   U value=blend_channel(m,b,blue,alpha,coverage,0x83b2f4u,0x83b2f0u);
   value|=blend_channel(m,g,green,alpha,coverage,0x83b2fcu,0x83b2f8u);
   value|=blend_channel(m,r,red,alpha,coverage,0x83b2ecu,0x83b2e8u);
   m.w16(i.arg[5]+pixel_offset,value);
  }
  if(s32(i.arg[3])>0){dp+=2u;pixel_offset+=2u;wrap(m,depth,dp);ap+=2u;wrap(m,aux,ap);i.arg[3]-=i.arg[4];}
  if(s32(depth_error)>0){i.arg[6]+=1u;depth_error-=i.arg[4];}
  i.arg[3]+=i.arg[1];depth_error+=i.arg[2];i.arg[5]+=row_pitch;
  dp+=2u*i.arg[0];wrap(m,depth,dp);ap+=2u*i.arg[0];i.arg[6]-=1u;wrap(m,aux,ap);
 }while(--remaining);
 const U eax=unlock(m,self);return (eax&0xffffff00u)|1u;
}
U fun_005377a0(Memory&outer,const Inputs&i){
 constexpr U base=0x7da00000u,T=base+0x8000u,sp=base+0x4000u;
 std::array<std::uint8_t,0x10000> bytes{};leaf::Memory local(bytes.data(),base,U(bytes.size()));Memory m=outer;m.add(local);
 const U self=i.cx;U eax=m.r32(self+12u)+1u,index=eax;if(s32(index)>=32)index=0u;
 U first=self+16u*eax;need(!sentinel(m,first),"B1338 original nonempty ring first coordinate");
 ++index;U second=self+16u*index;eax=m.r32(first+12u);need(eax!=0u,"B1338 live first ring sample");
 unsigned lines=0;
 for(;;){
  need(!sentinel(m,second),"B1338 original second coordinate");
  Inputs project{};project.cx=m.r32(0x821cacu);project.arg[0]=first;project.arg[1]=T+0x1cu;project.fp=i.fp;
  numeric_b88::fun_00698010(m,project);i.fp=project.fp;
  project.arg[0]=second;project.arg[1]=T+0x14u;project.fp=i.fp;numeric_b88::fun_00698010(m,project);i.fp=project.fp;
  const U z0=U(-2)-height(m,i.fp,m.r32(first+8u),sp),z1=U(-2)-height(m,i.fp,m.r32(second+8u),sp);
  Inputs line{};line.cx=m.r32(0x821ca4u);line.arg[0]=0x821970u;line.arg[1]=T+0x1cu;line.arg[2]=T+0x14u;
  line.arg[3]=self;line.arg[4]=m.r32(first+12u);line.arg[5]=z0;line.arg[6]=z1;line.fp=i.fp;
  fun_004ae6d0(m,line);i.fp=line.fp;++lines;
  eax=index;if(s32(eax)>=32)eax=0u;if(eax==m.r32(self+12u))break;
  index=eax+1u;first=second;second=self+16u*index;eax=m.r32(first+12u);if(!eax)break;
  need(lines<2u,"B1338 finite produced one-segment ring");
 }
 need(lines==1u&&eax==0u,"B1338 authentic next-slot-age termination");return eax;
}
}
