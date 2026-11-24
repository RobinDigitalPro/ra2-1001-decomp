#include "recovered/recovery_b1476.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/floating_closure_b42_memory.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1476 {
namespace {
using U=std::uint32_t;using FP=platform::x87::State;
using floating_b39::read64;using floating_b39::write64;
namespace ext=platform::x87_extended;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// Existing bodies retain their exact private stack/FP operations. Only these
// eight reviewed entry points are callable; no controlled Operations seam.
U invoke(Memory&m,FP&fp,U rva,U cx,U sp,U continuation){
 floating_b39::Function function=nullptr;
 if(rva==0x1b750u||rva==0x1b7c0u||rva==0xba140u||rva==0xba0f0u){for(const auto&e:floating_callers_b40::entries_a())if(e.rva==rva)function=e.function;}
 else if(rva==0x1b6e0u||rva==0xba270u){for(const auto&e:floating_closure_b42::entries_a())if(e.rva==rva)function=e.function;}
 else if(rva==0xba080u){for(const auto&e:floating_b39::entries_a())if(e.rva==rva)function=e.function;}
 else if(rva==0x36aa50u){for(const auto&e:floating_b39::entries_b())if(e.rva==rva)function=e.function;}
 need(function!=nullptr,"1476 closed original helper");
 m.w32(sp,continuation);floating_b39::State s{};s.cx=cx;s.fp=fp;
 floating_b39::Frame f{};f.entry_sp=f.sp=f.return_sp=sp;f.outer_return=continuation;
 function(m,s,f,{});fp=s.fp;return s.ax;
}
// Exact590F10 consumed full result: absolute signed-WORD difference followed
// by SETGE AL; upper EAX is retained even though the root tests only AL.
U direction_near(Memory&m,U self,U other,U limit){
 const auto d=leaf::s32(leaf::sx16((m.r16(self)-m.r16(other))&0xffffu));
 const auto t=leaf::s32(leaf::sx16(m.r16(limit)));const U a=d<0?U(-d):U(d),b=t<0?U(-t):U(t);
 return(a&0xffffff00u)|U(b>=a);
}
// Exact590ED0 private pointer-half alias. The root observes only the lowWORD;
// nevertheless both the private argument word and full output are retained.
U direction_difference(Memory&m,U self,U out,U other,U arg_slot){
 const U value=(other&0xffff0000u)|((m.r16(self)-m.r16(other))&0xffffu);
 m.w32(arg_slot,value);m.w32(out,value);return out;
}
//41B630/25B stores three supplied DWORDs and returns the output address.
U coordinates(Memory&m,U out,U x,U y,U z){m.w32(out,x);m.w32(out+4u,y);m.w32(out+8u,z);return out;}
}
std::uint32_t fun_00590670(Memory&m,const Inputs&i){
 const U position=i.cx,velocity=i.dx,target=i.arg[0],turn=i.arg[1];auto&fp=i.fp;
 for(U k=0;k<3u;++k)need(m.r32(target+4u*k)==m.r32(0xa58820u+4u*k)&&m.r32(target+4u*k)==0u,"1476 original zero sentinel");
 need(read64(m,velocity)==0x4008000000000000ull&&read64(m,velocity+8u)==0x4010000000000000ull&&read64(m,velocity+16u)==0u&&m.r16(turn)==0u,"1476 finite nonzero velocity/zero turn");
 // B is the original aligned root local base. Every consumed local word is
 // explicitly produced below. Zero backing is not a caller/private-stack
 // input: unknown upper halves in76AA50 are masked before semantic use.
 Memory local=m;std::array<std::uint8_t,2048>bytes{};leaf::Memory scratch(bytes.data(),0x7d400000u,bytes.size());local.add(scratch);
 constexpr U b=0x7d400600u;
 local.w32(b+0x34u,velocity);
 (void)invoke(local,fp,0x1b750u,velocity,b-4u,0x5906c1u);
 write64(local,b-8u,fp.pop64());write64(local,b-16u,read64(local,velocity+16u));
 (void)invoke(local,fp,0xba270u,0u,b-20u,0x5906d4u);
 fp.subtract64(read64(local,0x786630u));fp.multiply64(read64(local,0x786628u));
 const U pitch=invoke(local,fp,0x36aa50u,0u,b-4u,0x5906e8u);
 local.w16(b+0x34u,pitch);local.w32(b+0x10u,local.r32(b+0x34u));local.w16(b+0x14u,0x2000u);
 need((direction_near(local,b+0x10u,b+0x14u,turn)&0xffu)==0u,"1476 no immediate angle snap");
 const U difference=direction_difference(local,b+0x14u,b+0x48u,b+0x10u,b-4u);
 if(leaf::s32(leaf::sx16(local.r16(difference)))<0)local.w16(b+0x10u,local.r16(b+0x10u)-local.r16(turn));
 else local.w16(b+0x10u,local.r16(b+0x10u)+local.r16(turn));
 local.w32(b-4u,b+0x48u);const U angle=invoke(local,fp,0x1b6e0u,velocity,b-8u,0x590755u);
 local.w32(b+0x34u,leaf::sx16(local.r16(angle))-0x3fffu);
 fp.load_integer32(local.r32(b+0x34u));fp.multiply64(read64(local,0x786620u));write64(local,b+0x48u,fp.pop64());
 (void)invoke(local,fp,0x1b7c0u,velocity,b-4u,0x590777u);write64(local,b+0x38u,fp.pop64());
 fp.load64(read64(local,b+0x48u));fp.compare_pop64(read64(local,0x786610u));need((fp.status()&0x4000u)!=0u,"1476 zero pitch excludes rescale");
 // Actual three distinct trigonometric calls and their FP order are retained.
 for(U axis=0;axis<3u;++axis){
  local.w32(b+0x34u,leaf::sx16(local.r16(b+0x10u))-0x3fffu);
  fp.load_integer32(local.r32(b+0x34u));fp.multiply64(read64(local,0x786620u));write64(local,b-8u,fp.pop64());
  (void)invoke(local,fp,axis<2u?0xba140u:0xba0f0u,0u,b-12u,axis==0u?0x5907d7u:axis==1u?0x5907fcu:0x590822u);
  fp.multiply64(read64(local,axis<2u?velocity+8u*axis:b+0x38u));
  if(axis<2u)write64(local,velocity+8u*axis,fp.pop64());else write64(local,velocity+16u,fp.store64());
 }
 write64(local,b+0x68u,read64(local,velocity));write64(local,b+0x70u,read64(local,velocity+8u));
 fp.load64(read64(local,b+0x68u));const U dx=invoke(local,fp,0x36aa50u,0u,b-4u,0x590852u);
 fp.load64(read64(local,b+0x70u));const U dy=invoke(local,fp,0x36aa50u,0u,b-4u,0x59085du);local.w32(b+0x6cu,dy);
 const U dz=invoke(local,fp,0x36aa50u,0u,b-4u,0x590866u);
 const U output=coordinates(local,b+0x68u,local.r32(position)+dx,local.r32(position+4u)+local.r32(b+0x6cu),local.r32(position+8u)+dz);
 for(U k=0;k<3u;++k)local.w32(position+4u*k,local.r32(output+4u*k));
 // Root's final norm differs in instruction order from41B7C0. Preserve it;
 // the five stale physical registers form the independent literal oracle.
 fp.load64(read64(local,velocity+16u));fp.load64(read64(local,velocity+8u));fp.load64(read64(local,velocity));
 fp.load_st1();ext::multiply_st2(fp);fp.load_st1();ext::multiply_st2(fp);fp.add_pop();ext::load_st3(fp);ext::multiply_st4(fp);fp.add_pop();
 write64(local,b-8u,fp.pop64());fp.pop_st0();fp.pop_st0();fp.pop_st0();
 (void)invoke(local,fp,0xba080u,0u,b-12u,0x5908bfu);
 return invoke(local,fp,0x36aa50u,0u,b-4u,0x5908c7u);
}
}
