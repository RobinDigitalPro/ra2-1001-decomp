#include "recovered/indirect_b31_memory.hpp"
#include <array>
#include <cstdint>

namespace ra2::recovered::indirect_b31 {
namespace {
std::uint32_t caller_arg(const Memory& m,const Frame& f,unsigned i){return m.r32(f.entry_sp+4u+4u*i);}
void push_reg(Memory&m,Frame&f,std::uint32_t v){f.push(m,v);}
void pop_reg(const Memory&m,Frame&f,std::uint32_t&v){v=m.r32(f.sp);f.sp+=4u;}
std::uint32_t target_ind(const Memory&m,std::uint32_t obj,std::uint32_t slot){return m.r32(m.r32(obj)+slot);}
std::uint32_t target_abs(const Memory&m,std::uint32_t slot){return m.r32(slot);}

void fn_18c0(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.di); const auto obj=s.cx; const auto p=m.r32(obj+0x118u); s.di=obj; s.cx=p;
 if(!p){s.ax=0;pop_reg(m,f,s.di);finish(m,s,f,4);return;}
 s.ax=caller_arg(m,f,0); push_reg(m,f,s.si); s.si=m.r32(obj+0x11cu);
 if(s32(s.ax)>s32(s.si))s.ax=s.si;
 // The load from the object capacity precedes the nonpositive short exit.
 if(s32(s.ax)<=0)s.ax=0;
 else {const auto iface=m.r32(p); s.si=iface; push_reg(m,f,s.ax); push_reg(m,f,s.dx);
   invoke(m,s,f,o,m.r32(iface+0x24u)); if(s32(s.ax)<0)s.ax=0;}
 s.cx=m.r32(obj+0x11cu); pop_reg(m,f,s.si); s.cx-=s.ax; m.w32(obj+0x11cu,s.cx);
 pop_reg(m,f,s.di); finish(m,s,f,4);
}
void fn_1910(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si); const auto obj=s.cx; s.si=obj; const auto p=m.r32(obj+0x110u); s.cx=p;
 m.w32(obj+0x118u,0);
 if(p){const auto v=m.r32(p);s.ax=v; push_reg(m,f,1); invoke(m,s,f,o,m.r32(v)); m.w32(obj+0x110u,0);}
 pop_reg(m,f,s.si); finish(m,s,f,0);
}
void fn_a860(Memory&m,State&s,Frame&f,const Operations&o){
 s.ax=m.r32(0x8198f0u); if(s.ax){s.cx=m.r32(s.ax); push_reg(m,f,s.ax); invoke(m,s,f,o,m.r32(s.cx+0x48u));}
 finish(m,s,f,0);
}
void fn_10180(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si); s.si=caller_arg(m,f,1);
 if(!s.si){s.ax=0x80004003u;pop_reg(m,f,s.si);finish(m,s,f,8);return;}
 const auto receiver=caller_arg(m,f,0); s.cx=receiver; const auto v=m.r32(receiver); s.ax=v;
 invoke(m,s,f,o,m.r32(v+0x30u)); s.ax+=4u; m.w32(s.si,s.ax); m.w32(s.si+4u,0); s.ax=0;
 pop_reg(m,f,s.si); finish(m,s,f,8);
}
void fn_10bd0(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si); const auto obj=s.cx; s.si=obj; const auto p=m.r32(obj+0x14u); s.cx=p;
 if(p){const auto v=m.r32(p); s.ax=v; push_reg(m,f,1); invoke(m,s,f,o,m.r32(v));}
 m.w32(obj+0x14u,0); pop_reg(m,f,s.si); finish(m,s,f,0);
}
void fn_11050(Memory&m,State&s,Frame&f,const Operations&o){
 const auto old=f.sp; f.sp-=16u; const auto obj=s.cx;
 s.dx=m.r32(obj+0x2cu); m.w32(f.sp+12u,s.dx); s.ax=0;
 s.dx=m.r32(f.sp+20u)&0xffffu; m.w32(f.sp,0);m.w32(f.sp+4u,0);
 s.ax=m.r32(obj+0x28u); s.cx=m.r32(obj+0x14u); m.w32(f.sp+8u,s.ax);
 const auto iface=m.r32(s.cx);s.ax=iface;push_reg(m,f,s.dx);s.dx=f.sp+4u;push_reg(m,f,s.dx);
 invoke(m,s,f,o,m.r32(iface+0x14u)); f.sp+=16u;
 if(f.sp!=old)throw std::runtime_error("B31 0x11050 stack balance"); finish(m,s,f,4);
}
void fn_132e0(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);const auto p=caller_arg(m,f,0);s.si=p;s.cx=p;s.ax=m.r32(p);
 invoke(m,s,f,o,m.r32(s.ax+0x1a4u));s.ax=m.r32(s.ax+0xe0u);
 s.ax=(s.ax!=0&&s.ax!=s.si)?with_al(s.ax,1):with_al(s.ax,0);
 pop_reg(m,f,s.si);finish(m,s,f,4);
}
void fn_134e0(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.cx);const auto obj=s.cx; s.ax=m.r32(obj+0x2590u);
 if(!s.ax){pop_reg(m,f,s.cx);finish(m,s,f,0);return;}
 s.ax=m.r32(obj+0x2584u); push_reg(m,f,s.si);s.si=obj+0x2580u;
 s.cx=f.sp+4u;s.dx=m.r32(s.ax);push_reg(m,f,s.cx);s.ax=m.r32(s.si);s.cx=s.si;
 m.w32(f.sp+8u,s.dx);invoke(m,s,f,o,m.r32(s.ax+0x10u));
 if(s.ax!=0xffffffffu){s.cx=m.r32(s.si+0x10u);if(s32(s.ax)<s32(s.cx)){
   --s.cx; m.w32(s.si+0x10u,s.cx);
   if(s32(s.ax)<s32(s.cx)){
     do{s.cx=m.r32(s.si+4u);++s.ax;s.dx=m.r32(s.cx+s.ax*4u);
        m.w32(s.cx+s.ax*4u-4u,s.dx);s.cx=m.r32(s.si+0x10u);}while(s32(s.ax)<s32(s.cx));
   }
 }}
 s.ax=m.r32(f.sp+4u);pop_reg(m,f,s.si);pop_reg(m,f,s.cx);finish(m,s,f,0);
}
void fn_139f0(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=s.cx;if(!s.si){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,0);return;}
 s.ax=m.r32(s.si);s.cx=s.si;invoke(m,s,f,o,m.r32(s.ax+0x2cu));
 const auto is15=s.ax==15u;s.ax=is15?0xffffffffu:0u;s.ax &= s.si;
 if(!s.ax){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,0);return;}
 s.cx=m.r32(s.ax+0x5a8u);s.dx=(s.dx&0xffffff00u)|m.r8(s.cx+0xc0fu);
 if((s.dx&0xffu)==0){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,0);return;}
 s.cx=(s.cx&0xffffff00u)|m.r8(s.ax+0x5c1u);pop_reg(m,f,s.si);s.ax=with_al(s.ax,(s.cx&0xffu)==0?1u:0u);finish(m,s,f,0);
}
void fn_26d20(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=caller_arg(m,f,1);if(!s.si){s.ax=0x80004003u;pop_reg(m,f,s.si);finish(m,s,f,8);return;}
 push_reg(m,f,0x7ba028u);invoke(m,s,f,o,target_abs(m,0x785360u));m.w32(s.si,s.ax);s.ax=0;pop_reg(m,f,s.si);finish(m,s,f,8);
}
void fn_26d50(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=caller_arg(m,f,1);if(!s.si){s.ax=0x80004003u;pop_reg(m,f,s.si);finish(m,s,f,8);return;}
 push_reg(m,f,0x7ba044u);invoke(m,s,f,o,target_abs(m,0x785360u));m.w32(s.si,s.ax);s.ax=0;pop_reg(m,f,s.si);finish(m,s,f,8);
}
void fn_364b0(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);const auto obj=s.cx;s.si=obj;auto count=m.r32(obj+0x10u),cap=m.r32(obj+8u);
 s.cx=cap;s.ax=count;
 if(s32(count)>=s32(cap)){
   auto flag=m.r8(obj+0xdu);s.ax=with_al(s.ax,flag);if(!flag&&cap!=0)goto done;
   auto growth=m.r32(obj+0x14u);s.ax=growth;if(s32(growth)<=0)goto done;
   auto v=m.r32(obj);s.dx=v;s.ax=growth+cap;push_reg(m,f,0);push_reg(m,f,s.ax);s.cx=obj;
   invoke(m,s,f,o,m.r32(v+8u));if((s.ax&0xffu)==0)goto done;
 }
 {auto i=m.r32(obj+0x10u),data=m.r32(obj+4u);s.ax=i;s.dx=data;s.cx=i+1u;m.w32(obj+0x10u,s.cx);
  s.cx=caller_arg(m,f,0);m.w32(data+i*4u,s.cx);}
 done:pop_reg(m,f,s.si);finish(m,s,f,4);
}
void fn_36500(Memory&m,State&s,Frame&f,const Operations&o){
 const auto base=s.cx; s.ax=m.r32(base+0x28u);push_reg(m,f,s.si);s.si=base+0x18u;
 auto count=m.r32(base+0x20u);s.cx=count;if(s32(s.ax)>=s32(count)){
   auto flag=m.r8(s.si+0xdu);s.ax=with_al(s.ax,flag);if(!flag&&count!=0)goto done;
   auto growth=m.r32(s.si+0x14u);s.ax=growth;if(s32(growth)<=0)goto done;
   auto v=m.r32(s.si);s.dx=v;s.ax=growth+count;push_reg(m,f,0);push_reg(m,f,s.ax);s.cx=s.si;
   invoke(m,s,f,o,m.r32(v+8u));if((s.ax&0xffu)==0)goto done;
 }
 {auto i=m.r32(s.si+0x10u),data=m.r32(s.si+4u);s.ax=i;s.dx=data;s.cx=i+1u;m.w32(s.si+0x10u,s.cx);
  s.cx=caller_arg(m,f,0);m.w32(data+i*4u,s.cx);}
 done:pop_reg(m,f,s.si);finish(m,s,f,4);
}
void fn_49ac0(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=s.cx;s.ax=m.r32(s.si);invoke(m,s,f,o,m.r32(s.ax+0x1bcu));
 if((s.ax&0xffu)!=0){s.ax=0;pop_reg(m,f,s.si);finish(m,s,f,0);return;}
 if(m.r8(s.si+0x530u)==0){s.ax=0;pop_reg(m,f,s.si);finish(m,s,f,0);return;}
 s.cx=m.r32(s.si+0x418u);s.dx=with_al(s.dx,m.r8(s.si+0x539u));s.ax=m.r32(s.cx+0xc6cu);
 if((s.dx&0xffu)!=0)s.ax+=m.r32(s.cx+0xc74u);
 s.cx=with_al(s.cx,m.r8(s.si+0x5c6u));
 if((s.cx&0xffu)==0){pop_reg(m,f,s.si);finish(m,s,f,0);return;}
 s.dx=s.si+0x4c0u;s.si=3;
 do{ s.cx=m.r32(s.dx);if(s.cx)s.ax+=m.r32(s.cx+0xc6cu);s.dx+=4u;--s.si;}while(s.si!=0);
 pop_reg(m,f,s.si);finish(m,s,f,0);
}
void fn_4cfc0(Memory&m,State&s,Frame&f,const Operations&o){
 s.ax=caller_arg(m,f,0);push_reg(m,f,s.bx);push_reg(m,f,s.si);const auto obj=s.cx;s.si=obj;s.bx=s.ax;
 if(s.ax==15u){auto v=m.r32(obj);s.ax=v;push_reg(m,f,0);push_reg(m,f,0);invoke(m,s,f,o,m.r32(v+0x64u));if(s.ax==5u)s.bx=16u;}
 s.cx=obj+0x454u;s.si=0x12u;
 do{s.ax=m.r32(s.cx);if(s.ax)m.w8(s.ax+0x158u,s.bx);s.cx+=4u;--s.si;}while(s.si);
 pop_reg(m,f,s.si);pop_reg(m,f,s.bx);finish(m,s,f,4);
}
void fn_67e00(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);const auto obj=s.cx;s.si=obj;auto p=m.r32(obj+0x24u);s.ax=p;
 if(p){m.w32(p+0x234u,0);s.cx=m.r32(obj+0x24u);s.dx=m.r32(obj+0x28u);push_reg(m,f,1);
   auto v=m.r32(s.cx);s.ax=v;push_reg(m,f,s.dx);invoke(m,s,f,o,m.r32(v+0x378u));m.w32(obj+0x24u,0);m.w32(obj+0x28u,0);}
 pop_reg(m,f,s.si);finish(m,s,f,0);
}
void fn_68c20(Memory&m,State&s,Frame&f,const Operations&o){
 const auto old=f.sp;f.sp-=8u;s.ax=m.r32(0x7bd078u);s.cx=f.sp;push_reg(m,f,s.ax);m.w32(f.sp+4u,0x788868u);
 invoke(m,s,f,o,target_abs(m,0x788868u));f.sp+=8u;if(f.sp!=old)throw std::runtime_error("B31 0x68c20 stack balance");finish(m,s,f,12);
}
void fn_70070(Memory&m,State&s,Frame&f,const Operations&o){
 s.ax=m.r32(0x7bd76cu);if(s.ax!=0xffffffffu){push_reg(m,f,s.ax);invoke(m,s,f,o,target_abs(m,0x7852f8u));m.w32(0x7bd76cu,0xffffffffu);}finish(m,s,f,0);
}
void fn_7a060(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=s.cx;s.ax=m.r32(s.si+0x3cu);if(s.ax)m.w32(s.ax+0x2cu,m.r32(s.ax+0x2cu)-1u);
 s.ax=caller_arg(m,f,0);m.w32(s.si+0x3cu,s.ax);if(!s.ax)goto done;
 s.ax=m.r32(0x81b980u);s.cx=m.r32(0x81b988u);
 if(s32(s.cx)>=s32(s.ax)){
  const auto flag=m.r8(0x81b985u);s.cx=with_al(s.cx,flag);
  if(!flag&&s.ax!=0)goto ref;
  if(flag||s.ax==0){s.cx=m.r32(0x81b98cu);if(s32(s.cx)<=0)goto ref;s.cx+=s.ax;s.ax=m.r32(0x81b978u);push_reg(m,f,0);push_reg(m,f,s.cx);s.cx=0x81b978u;invoke(m,s,f,o,m.r32(s.ax+8u));if(!(s.ax&0xffu))goto ref;}
 }
 s.cx=m.r32(0x81b988u);s.dx=m.r32(0x81b97cu);s.ax=s.cx;++s.cx;m.w32(0x81b988u,s.cx);s.cx=m.r32(s.si+0x24u);m.w32(s.dx+s.ax*4u,s.cx);
 ref:s.si=m.r32(s.si+0x3cu);m.w32(s.si+0x2cu,m.r32(s.si+0x2cu)+1u);
 done:pop_reg(m,f,s.si);finish(m,s,f,4);
}
void fn_80dc0(Memory&m,State&s,Frame&f,const Operations&o){
 s.dx=(s.dx&0xfffff7ffu);s.ax=s.dx;const auto ah=(s.dx>>8)&0xffu;s.ax=(s.ax&0xffff00ffu)|((ah&0xe8u)<<8);
 if(s.dx==s.ax){s.ax=with_al(s.ax,1);finish(m,s,f,0);return;}
 auto p=m.r32(s.cx);s.ax=p;push_reg(m,f,s.dx);invoke(m,s,f,o,m.r32(p+0x14u));s.ax=((s.ax&0xffu)==0)?1u:0u;finish(m,s,f,0);
}
void grow_index(Memory&m,State&s,Frame&f,const Operations&o,std::uint32_t obj,std::uint32_t n,bool inc,bool mutate=true,bool final_data_cx=true){
 push_reg(m,f,s.bx);s.bx=caller_arg(m,f,0);push_reg(m,f,s.si);s.si=obj;push_reg(m,f,s.di);auto cap=m.r32(obj+8u);s.di=cap;
 if(s32(s.bx)>=s32(cap)){
  auto v=m.r32(obj);s.ax=v;s.cx=s.bx+10u;push_reg(m,f,0);push_reg(m,f,s.cx);s.cx=obj;invoke(m,s,f,o,m.r32(v+8u));
  if(!(s.ax&0xffu)){s.ax=0;pop_reg(m,f,s.di);pop_reg(m,f,s.si);pop_reg(m,f,s.bx);finish(m,s,f,4);return;}
  auto capacity=m.r32(obj+8u);s.cx=capacity;s.ax=s.di;
  if(s32(s.ax)<s32(capacity)){s.dx=m.r32(obj+4u);do{++s.ax;m.w32(s.dx+s.ax*4u-4u,0);s.cx=m.r32(obj+8u);}while(s32(s.ax)<s32(s.cx));}
 }
 s.ax=m.r32(obj+4u);pop_reg(m,f,s.di);if(mutate){auto at=m.r32(s.ax+s.bx*4u);m.w32(s.ax+s.bx*4u,inc?at+1u:at-1u);}if(final_data_cx)s.cx=m.r32(obj+4u);s.ax=m.r32(m.r32(obj+4u)+s.bx*4u);
 pop_reg(m,f,s.si);pop_reg(m,f,s.bx);finish(m,s,f,4);
}
void fn_91a30(Memory&m,State&s,Frame&f,const Operations&o){grow_index(m,s,f,o,s.cx,0,true,true);}
void fn_91a90(Memory&m,State&s,Frame&f,const Operations&o){grow_index(m,s,f,o,s.cx,0,false,true);}
void fn_91af0(Memory&m,State&s,Frame&f,const Operations&o){grow_index(m,s,f,o,s.cx,0,false,false,false);}
void fn_92850(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=s.cx;auto src=caller_arg(m,f,0),dst=s.si+4u;
 // MOV instructions read each source just before its corresponding store.
 for(unsigned i=0;i<4;++i){auto v=m.r32(src+4u*i);m.w32(dst+4u*i,v);}
 s.ax=caller_arg(m,f,1);s.cx=0;m.w32(s.si+0x18u,s.ax);m.w32(s.si+0x14u,0);m.w32(s.si+0x20u,0);m.w32(s.si+0x24u,0);m.w8(s.si+0x28u,1);m.w8(s.si+0x29u,0);m.w32(s.si+0x1cu,0x78961cu);m.w32(s.si+0x30u,10u);m.w32(s.si+0x2cu,0);m.w32(s.si,0x78963cu);
 s.dx=m.r32(s.ax);push_reg(m,f,s.ax);invoke(m,s,f,o,m.r32(s.dx+4u));s.ax=s.si;pop_reg(m,f,s.si);finish(m,s,f,8);
}
void fn_9e500(Memory&m,State&s,Frame&f,const Operations&o){s.ax=m.r32(0xb0de54u);if(s.ax){push_reg(m,f,s.ax);invoke(m,s,f,o,target_abs(m,0x78545cu));m.w32(0xb0de54u,0);}finish(m,s,f,0);}
void fn_9f790(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=caller_arg(m,f,0);s.cx=m.r32(s.si-0x14u);s.ax=s.si-0x14u;push_reg(m,f,s.ax);invoke(m,s,f,o,m.r32(s.cx+0x10u));
 if(!(s.ax&0xffu)){s.ax=m.r32(s.si+0x50u);if(s.ax&&m.r8(s.si+0x4du)){s.ax=with_al(s.ax,1);pop_reg(m,f,s.si);finish(m,s,f,4);return;}}
 s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,4);
}
void fn_a4d60(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=s.cx;s.ax=with_al(s.ax,m.r8(s.si+0x48u));if((s.ax&0xffu)!=0){s.ax=m.r32(s.si+0xb0u);s.cx=s.si+0xb0u;invoke(m,s,f,o,m.r32(s.ax+0x24u));m.w8(s.si+0x48u,0);}pop_reg(m,f,s.si);finish(m,s,f,0);}
void fn_a4eb0(Memory&m,State&s,Frame&f,const Operations&o){fn_a4d60(m,s,f,o);}
void fn_a60d0(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=caller_arg(m,f,0);s.cx=m.r32(s.si-0x14u);s.ax=s.si-0x14u;push_reg(m,f,s.ax);invoke(m,s,f,o,m.r32(s.cx+0x10u));if(!(s.ax&0xffu)&&m.r32(s.si+0x14u))s.ax=with_al(s.ax,1);else s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,4);}
void fn_aabf0(Memory&m,State&s,Frame&f,const Operations&o){s.ax=m.r32(s.cx+0x1cu);if(s.ax){s.cx=m.r32(s.ax);push_reg(m,f,s.ax);invoke(m,s,f,o,m.r32(s.cx+0x60u));s.ax=(s.ax==0x887601c2u)?1u:0u;}else s.ax=0;finish(m,s,f,0);}
void fn_b2290(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=caller_arg(m,f,0);push_reg(m,f,s.di);s.di=s.cx;if(s.si){s.ax=m.r32(s.si);s.cx=s.si;invoke(m,s,f,o,m.r32(s.ax+0x2cu));if(s.ax==1u){s.ax=with_al(s.ax,m.r8(s.si+0x7du));if((s.ax&0xffu)!=0){s.ax=with_al(s.ax,m.r8(s.si+0x76u));if((s.ax&0xffu)==0){s.cx=caller_arg(m,f,1);m.w32(s.di+0x20u,s.si);m.w32(s.di+0x24u,s.cx);}}}}pop_reg(m,f,s.di);pop_reg(m,f,s.si);finish(m,s,f,8);}
void fn_b9a60(Memory&m,State&s,Frame&f,const Operations&o){
 s.ax=m.r32(s.cx+0x3cu);push_reg(m,f,s.si);s.si=s.cx+0x3cu;s.cx=f.sp+8u;push_reg(m,f,s.cx);s.cx=s.si;invoke(m,s,f,o,m.r32(s.ax+0x10u));
 // The sentinel branch bypasses the count load and therefore keeps callback ECX.
 if(s.ax==0xffffffffu){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,4);return;}
 auto count=m.r32(s.si+0x10u);s.cx=count;
 if(s32(s.ax)>=s32(count)){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,4);return;}
 --count;s.cx=count;m.w32(s.si+0x10u,count);
 if(s32(s.ax)<s32(count)){
   do{s.cx=m.r32(s.si+4u);++s.ax;s.dx=m.r32(s.cx+s.ax*4u);
      m.w32(s.cx+s.ax*4u-4u,s.dx);s.cx=m.r32(s.si+0x10u);}while(s32(s.ax)<s32(s.cx));
 }
 s.ax=with_al(s.ax,1);pop_reg(m,f,s.si);finish(m,s,f,4);
}
void fn_b9ab0(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.bx);s.bx=caller_arg(m,f,0);push_reg(m,f,s.si);s.si=s.cx;push_reg(m,f,s.di);s.di=0;auto p=m.r32(s.si+0x54u);s.cx=p;if(p){s.ax=m.r32(p);invoke(m,s,f,o,m.r32(s.ax+0x80u));if(s.ax==s.bx)s.di=1;}auto n=m.r32(s.si+0x4cu);if(s32(n)>0){p=m.r32(s.si+0x40u);while(n--){if(m.r32(p)==s.bx)++s.di;p+=4u;}}s.ax=s.di;pop_reg(m,f,s.di);pop_reg(m,f,s.si);pop_reg(m,f,s.bx);finish(m,s,f,4);}
void fn_bbec0(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=caller_arg(m,f,0);push_reg(m,f,s.di);push_reg(m,f,s.si);s.ax=m.r32(s.si);invoke(m,s,f,o,m.r32(s.ax+0x10u));const bool success=(s.ax&0xffu)!=0;auto out=caller_arg(m,f,1);s.ax=out;if(success){s.cx=m.r32(s.si+0x18u);s.dx=m.r32(s.si+0x1cu);s.si=m.r32(s.si+0x20u);m.w32(out,s.cx);m.w32(out+4u,s.dx);m.w32(out+8u,s.si);}else{s.cx=m.r32(0x84e128u);s.dx=m.r32(0x84e12cu);s.si=m.r32(0x84e130u);m.w32(out,s.cx);m.w32(out+4u,s.dx);m.w32(out+8u,s.si);}pop_reg(m,f,s.di);pop_reg(m,f,s.si);finish(m,s,f,8);}
void fn_bf030(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=s.cx;auto b=m.r8(s.si+0x51u);if(b){s.ax=with_al(s.ax,0);goto done;}b=m.r8(s.si+0x50u);if(!b){s.ax=with_al(s.ax,1);goto done;}s.cx=m.r32(s.si+0xcu);s.ax=m.r32(s.cx);invoke(m,s,f,o,m.r32(s.ax+0x1b0u));s.cx=s.ax;s.ax=m.r32(s.si+0x38u);s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;s.ax=global_b27::sar(s.ax-s.dx,1); if(s32(s.cx)<s32(s.ax))s.ax=with_al(s.ax,0);else s.ax=with_al(s.ax,1);done:pop_reg(m,f,s.si);finish(m,s,f,0);}
void fn_c1b70(Memory&m,State&s,Frame&f,const Operations&o){if(m.r32(s.cx+0x30u)==6u){s.ax=m.r32(s.cx+0x60u);push_reg(m,f,0);s.cx=m.r32(s.ax);s.dx=m.r32(s.cx);invoke(m,s,f,o,m.r32(s.dx+0x90u));}else s.ax=0;finish(m,s,f,0);}
void grow_pair(Memory&m,State&s,Frame&f,const Operations&o){
 push_reg(m,f,s.si);s.si=s.cx;auto cap=m.r32(s.si+8u),idx=m.r32(s.si+0x10u);s.cx=cap;s.ax=idx;
 if(s32(idx)>=s32(cap)){
   auto v=m.r32(s.si);auto flag=m.r8(s.si+0xdu);s.ax=with_al(s.ax,flag);
   if(!flag&&cap!=0){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,4);return;}
   auto growth=m.r32(s.si+0x14u);s.ax=growth;if(s32(s.ax)<=0){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,4);return;}
   s.ax+=cap;s.dx=v;push_reg(m,f,0);push_reg(m,f,s.ax);s.cx=s.si;invoke(m,s,f,o,m.r32(v+8u));
   if(!(s.ax&0xffu)){s.ax=with_al(s.ax,0);pop_reg(m,f,s.si);finish(m,s,f,4);return;}
 }
 s.ax=m.r32(s.si+0x10u);s.dx=m.r32(s.si+4u);s.cx=s.ax+1u;m.w32(s.si+0x10u,s.cx);
 s.cx=caller_arg(m,f,0);s.si=m.r32(s.cx);m.w32(s.dx+s.ax*8u,s.si);s.cx=m.r32(s.cx+4u);
 pop_reg(m,f,s.si);m.w32(s.dx+s.ax*8u+4u,s.cx);s.ax=with_al(s.ax,1);finish(m,s,f,4);
}
void fn_ce530(Memory&m,State&s,Frame&f,const Operations&o){grow_pair(m,s,f,o);}
void fn_f78f0(Memory&m,State&s,Frame&f,const Operations&o){grow_pair(m,s,f,o);}
void fn_cee00(Memory&m,State&s,Frame&f,const Operations&o){s.ax=caller_arg(m,f,0);if(s.ax){s.dx=m.r32(s.cx);push_reg(m,f,s.ax);m.w8(s.cx+0x1cu,1);invoke(m,s,f,o,m.r32(s.dx+0x78u));s.ax=1;}else s.ax=0;finish(m,s,f,8);}
void fn_cf_bf0(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=s.cx;invoke(m,s,f,o,target_abs(m,0x785524u));s.cx=m.r32(s.si);pop_reg(m,f,s.si);if(s.ax>s.cx)s.ax-=s.cx;else s.ax=s.ax-s.cx-1u;finish(m,s,f,0);}
void fn_cfc30(Memory&m,State&s,Frame&f,const Operations&o){invoke(m,s,f,o,target_abs(m,0x785524u));s.cx=m.r32(0x84e3a4u);if(s.ax<=s.cx)s.ax=s.ax-s.cx-1u;else s.ax-=s.cx;s.cx=s.ax*3u;const auto product=std::uint64_t(s.cx)*0x51eb851full;s.dx=std::uint32_t(product>>32);s.ax=s.dx>>4;finish(m,s,f,0);}
void fn_cfd10(Memory&m,State&s,Frame&f,const Operations&o){s.ax=caller_arg(m,f,0);s.dx=m.r32(s.cx+0x30u);if(s.ax!=s.dx){m.w32(s.cx+0x30u,s.ax);s.ax=m.r32(s.cx);invoke(m,s,f,o,m.r32(s.ax+0x48u));s.ax=1;}else s.ax=0;finish(m,s,f,4);}
void fn_cfd30(Memory&m,State&s,Frame&f,const Operations&o){s.ax=caller_arg(m,f,0);s.dx=m.r32(s.cx+0x30u);if(s32(s.ax)<0)s.ax=0;else if(s32(s.ax)>s32(s.dx))s.ax=s.dx;if(s.ax!=m.r32(s.cx+0x34u)){m.w32(s.cx+0x34u,s.ax);auto p=m.r32(s.cx);s.ax=p;invoke(m,s,f,o,m.r32(p+0x48u));s.ax=1;}else s.ax=0;finish(m,s,f,4);}
void fn_df7f0(Memory&m,State&s,Frame&f,const Operations&o){auto v=caller_arg(m,f,0);s.ax=v;s.dx=(s.dx&0xffffff00u)|m.r8(s.cx+8u);if((v&0xffu)!=(s.dx&0xffu)){auto p=m.r32(s.cx);s.dx=p;push_reg(m,f,v);m.w8(s.cx+8u,v);invoke(m,s,f,o,m.r32(p+0x10u));}finish(m,s,f,4);}
void fn_e4c20_impl(Memory&m,State&s,Frame&f,const Operations&o,bool extra){push_reg(m,f,s.si);s.si=s.cx;auto obj=caller_arg(m,f,0);s.cx=obj;if(!obj){s.ax=with_al(s.ax,0);goto done;}if(extra&&(m.r8(obj+0x14u)&2u)==0){s.ax=with_al(s.ax,0);goto done;}s.ax=m.r32(obj);invoke(m,s,f,o,m.r32(s.ax+0x3cu));if(!s.ax){s.ax=with_al(s.ax,0);goto done;}if(s.ax==s.si){s.ax=with_al(s.ax,1);goto done;}s.ax=m.r32(s.ax+0x30u);s.cx=m.r32(s.si+0x30u);if(s.ax==s.cx){s.ax=with_al(s.ax,1);goto done;}if(s.ax==0xffffffffu){s.ax=with_al(s.ax,0);goto done;}s.dx=1;s.cx=s.ax;{auto mask=m.r32(s.si+0x5674u);pop_reg(m,f,s.si);s.dx<<=(s.cx&31u);s.ax=with_al(mask,(s.dx&mask)!=0);finish(m,s,f,4);return;}done:pop_reg(m,f,s.si);finish(m,s,f,4);}
void fn_e4c20(Memory&m,State&s,Frame&f,const Operations&o){fn_e4c20_impl(m,s,f,o,false);}
void fn_e4c80(Memory&m,State&s,Frame&f,const Operations&o){fn_e4c20_impl(m,s,f,o,true);}
void fn_1207b0(Memory&m,State&s,Frame&f,const Operations&o){
 s.dx=caller_arg(m,f,1);push_reg(m,f,s.si);s.si=s.cx;s.cx=caller_arg(m,f,0);s.ax=s.si;m.w32(s.ax,s.cx);s.cx=caller_arg(m,f,2);m.w32(s.ax+4u,s.dx);s.dx=0;m.w32(s.si+0xcu,0);m.w32(s.si+0x10u,0);m.w32(s.ax+8u,s.cx);
 s.ax=m.r32(0xa39bd0u);const auto count=m.r32(0xa39bd8u);bool append=s32(count)<s32(s.ax);
 if(!append){const auto flag=m.r8(0xa39bd5u);if(flag!=(s.dx&0xffu)||s.ax==s.dx){
   s.cx=m.r32(0xa39bdcu);if(s32(s.cx)>s32(s.dx)){s.cx+=s.ax;push_reg(m,f,s.dx);s.dx=m.r32(0xa39bc8u);push_reg(m,f,s.cx);s.cx=0xa39bc8u;invoke(m,s,f,o,m.r32(s.dx+8u));append=(s.ax&0xffu)!=0;}
 }}
 if(append){s.cx=m.r32(0xa39bd8u);s.ax=s.cx;++s.cx;m.w32(0xa39bd8u,s.cx);s.cx=m.r32(0xa39bccu);m.w32(s.cx+s.ax*4u,s.si);}
 s.ax=s.si;pop_reg(m,f,s.si);finish(m,s,f,12);
}
void fn_122910_impl(Memory&m,State&s,Frame&f,const Operations&o,std::uint32_t slot){s.ax=m.r32(0xa39eecu);if(!s.ax){push_reg(m,f,s.cx);invoke(m,s,f,o,target_abs(m,slot));}else{s.cx&=0xffu;s.ax=with_ax(s.ax,m.r16(0xa39c10u+s.cx*2u));}finish(m,s,f,0);}
void fn_122910(Memory&m,State&s,Frame&f,const Operations&o){fn_122910_impl(m,s,f,o,0x7853acu);}
void fn_122930(Memory&m,State&s,Frame&f,const Operations&o){fn_122910_impl(m,s,f,o,0x7853b4u);}
void fn_122a00(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=s.cx;s.cx=m.r32(0x821f90u);s.ax=1;if(s.cx){s.ax=m.r32(s.cx);invoke(m,s,f,o,m.r32(s.ax+0x34u));}--s.ax;if(s.ax==0){auto p=caller_arg(m,f,0);s.cx=m.r32(p+0x12u);s.ax=p+0x16u;m.w32(s.si,s.cx);s.si+=4u;s.dx=m.r32(s.ax);m.w32(s.si,s.dx);s.ax=with_ax(s.ax,m.r16(s.ax+4u));m.w16(s.si+4u,s.ax);}else if(--s.ax==0){s.ax=s.si+4u;s.cx=0;s.dx=s.ax;m.w32(s.dx,s.cx);m.w16(s.dx+4u,0);s.cx=caller_arg(m,f,0);s.dx=m.r32(s.cx);m.w32(s.ax,s.dx);m.w32(s.si,0);}pop_reg(m,f,s.si);finish(m,s,f,4);}
void fn_1230b0(Memory&m,State&s,Frame&f,const Operations&o){s.cx=m.r32(0x821f90u);if(s.cx){s.ax=m.r32(s.cx);invoke(m,s,f,o,m.r32(s.ax+0x20u));}m.w32(0xa3a04cu,0);s.ax=1;finish(m,s,f,0);}
void fn_1245e0_impl(Memory&m,State&s,Frame&f,const Operations&o,std::uint32_t off){auto obj=s.cx;if(!m.r8(obj+4u)||!m.r8(obj+5u)){s.ax=0;finish(m,s,f,16);return;}auto a3=caller_arg(m,f,3);s.dx=a3;f.push(m,s.dx);auto a2=caller_arg(m,f,2);s.dx=a2;f.push(m,s.dx);auto a1=caller_arg(m,f,1);s.dx=a1;f.push(m,s.dx);auto a0=caller_arg(m,f,0);s.dx=a0;f.push(m,s.dx);s.cx=m.r32(obj+off);s.ax=m.r32(s.cx);invoke(m,s,f,o,m.r32(s.ax+0x34u));finish(m,s,f,16);}
void fn_1245e0(Memory&m,State&s,Frame&f,const Operations&o){fn_1245e0_impl(m,s,f,o,0x48u);}
void fn_124690(Memory&m,State&s,Frame&f,const Operations&o){fn_1245e0_impl(m,s,f,o,0x4cu);}
void fn_124c90(Memory&m,State&s,Frame&f,const Operations&o){push_reg(m,f,s.si);s.si=s.cx;s.cx=caller_arg(m,f,0);s.ax=m.r32(s.si);push_reg(m,f,s.cx);s.cx=s.si;invoke(m,s,f,o,m.r32(s.ax+0x18u));if(s.ax!=0xffffffffu&&s32(s.ax)<s32(m.r32(s.si+0x44u))){s.dx=m.r32(s.si+s.ax*4u+0x28u);s.ax=caller_arg(m,f,1);s.dx+=0x4cu;s.cx=m.r32(s.ax);m.w32(s.dx,s.cx);s.cx=m.r32(s.ax+4u);m.w32(s.dx+4u,s.cx);s.ax=with_ax(s.ax,m.r16(s.ax+8u));m.w16(s.dx+8u,s.ax);}pop_reg(m,f,s.si);finish(m,s,f,8);}

} // namespace
const std::array<Entry,54>& entries_a(){static const std::array<Entry,54> e{{
 {0x18c0,fn_18c0},{0x1910,fn_1910},{0xa860,fn_a860},{0x10180,fn_10180},{0x10bd0,fn_10bd0},
 {0x11050,fn_11050},{0x132e0,fn_132e0},{0x134e0,fn_134e0},{0x139f0,fn_139f0},
 {0x26d20,fn_26d20},{0x26d50,fn_26d50},{0x364b0,fn_364b0},{0x36500,fn_36500},{0x49ac0,fn_49ac0},
 {0x4cfc0,fn_4cfc0},{0x67e00,fn_67e00},{0x68c20,fn_68c20},{0x70070,fn_70070}
 ,{0x7a060,fn_7a060},{0x80dc0,fn_80dc0},{0x91a30,fn_91a30},{0x91a90,fn_91a90},{0x91af0,fn_91af0},
 {0x92850,fn_92850},{0x9e500,fn_9e500},{0x9f790,fn_9f790},{0xa4d60,fn_a4d60},{0xa4eb0,fn_a4eb0},
 {0xa60d0,fn_a60d0},{0xaabf0,fn_aabf0},{0xb2290,fn_b2290},{0xb9a60,fn_b9a60},{0xb9ab0,fn_b9ab0},
 {0xbbec0,fn_bbec0},{0xbf030,fn_bf030},{0xc1b70,fn_c1b70},{0xce530,fn_ce530},{0xcee00,fn_cee00},
 {0xcfbf0,fn_cf_bf0},{0xcfc30,fn_cfc30},{0xcfd10,fn_cfd10},{0xcfd30,fn_cfd30},{0xdf7f0,fn_df7f0},
 {0xe4c20,fn_e4c20},{0xe4c80,fn_e4c80},{0xf78f0,fn_f78f0},{0x1207b0,fn_1207b0},
 {0x122910,fn_122910},{0x122930,fn_122930},{0x122a00,fn_122a00},{0x1230b0,fn_1230b0},
 {0x1245e0,fn_1245e0},{0x124690,fn_124690},{0x124c90,fn_124c90}
}};return e;}
} // namespace ra2::recovered::indirect_b31
