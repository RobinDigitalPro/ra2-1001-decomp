#include "recovery_b1319.hpp"
#include "recovered/floating_composed_b43_memory.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <initializer_list>
#include <stdexcept>

namespace ra2::recovered::b1319 {
namespace {
using U=std::uint32_t;using S=floating_b39::State;
constexpr U scratch_base=0x7d500000u,root_frame=scratch_base+0x8000u,call_frame=scratch_base+0x4000u;
constexpr U return_word=0x13579bdfu,vptr=0x78612cu;
void need(bool yes,const char* why){if(!yes)throw std::domain_error(why);}
floating_b39::Function helper(U rva){
 for(const auto&e:floating_b39::entries_a())if(e.rva==rva)return e.function;
 for(const auto&e:floating_b39::entries_b())if(e.rva==rva)return e.function;
 for(const auto&e:floating_composed_b43::entries_a())if(e.rva==rva)return e.function;
 throw std::runtime_error("B1319 missing accepted numeric helper");
}
void call(Memory&m,S&s,U rva,std::initializer_list<U> args={}){
 m.w32(call_frame,return_word);U p=call_frame+4u;
 for(U x:args){m.w32(p,x);p+=4u;}
 floating_b39::Frame f{};f.entry_sp=call_frame;f.sp=call_frame;
 f.return_sp=call_frame;f.outer_return=return_word;
 helper(rva)(m,s,f,{});
 need(f.sp==call_frame+4u+4u*U(args.size()),"B1319 numeric helper actual RET cleanup");
}
U type_of(Memory&m,U self){
 need(m.r32(self)==vptr&&m.r32(vptr+0x80u)==0x6b6910u&&m.r32(vptr+0x84u)==0x41b600u,
      "B1319 original +80/+84 type dispatch");
 const U type=m.r32(self+0x5acu);need(type!=0u,"B1319 borrowed type");return type;
}
U selected_record(Memory&m,S&s,U self,U index){
 need(index<3u&&m.r32(vptr+0x39cu)==0x6cdab0u,"B1319 indexed actual +39C getter");
 // Original6CDAB0 calls707FE0, then genuine+80, then6D4B50. It returns
 // the strided record address, not the first DWORD pointee.
 s.cx=self+0x118u;call(m,s,0x307fe0u);
 need((s.ax&255u)!=0u,"B1319 original double predicate positive branch");
 const U record=type_of(m,self)+0x8f4u+0x1cu*index;
 need(m.r32(record)!=0u,"B1319 positive6D4B50 nonnull-item record");return record;
}
U direction(Memory&m,U self,U out){
 need(m.r32(vptr+0x288u)==0x41b5e0u,"B1319 original direction getter slot");
 // Exact stable4B8850 branch through41B5E0: WORD(self+2F8+14)==0
 // copies the stored DWORD into its temporary, then into caller output.
 need(m.r16(self+0x30cu)==0u,"B1319 stable original direction record");
 const U d=m.r32(self+0x2f8u);need(d==0x4000u,"B1319 finite zero-angle direction");
 m.w32(out,d);return out;
}
void identity(Memory&m,U matrix){
 // Complete original58CE60 stores; no numeric state or external reads.
 for(U k=0;k<12u;++k)m.w32(matrix+4u*k,(k==0u||k==5u||k==10u)?0x3f800000u:0u);
}
void xyz(Memory&m,U self,U out){
 need(m.r32(vptr+0xa8u)==0x41b270u&&m.r32(vptr+0x48u)==0x5cd4d0u,
      "B1319 actual +A8/+48 coordinate dispatch");
 // 41B270 uses a private12-byte temporary for5CD4D0, then copies to
 // root-local out. Input objects and caller output are disjoint by contract.
 m.w32(out,m.r32(self+0x88u));m.w32(out+4u,m.r32(self+0x8cu));m.w32(out+8u,m.r32(self+0x90u));
}
U convert(Memory&m,S&s,U address,bool negate){
 s.fp.load32(m.r32(address));if(negate)s.fp.change_sign();call(m,s,0x36aa50u);return s.ax;
}
U run(Memory&outer,const Inputs&i,bool indexed){
 const U self=i.cx,out=i.arg[0],type=type_of(outer,self);
 need(out!=0u&&(outer.r8(self+0x14u)&4u)==0u,"B1319 real non-COM matrix branch");
 need(static_cast<std::int32_t>(outer.r32(type+0x63cu))>=1&&outer.r32(type+0x63cu)<=31u,
      "B1319 positive bounded type height");
 std::array<std::uint8_t,0x10000> local{};
 leaf::Memory stack(local.data(),scratch_base,U(local.size()));Memory m=outer;m.add(stack);
 S s{};s.fp=i.fp;
 const U angle=root_frame+(indexed?0x18u:0x14u),matrix=root_frame+(indexed?0x48u:0x3cu);
 const U vector=root_frame+(indexed?0x2cu:0x20u),transformed=root_frame+(indexed?0x3cu:0x30u);
 U vx=0u,vy=0u,vz=0u;
 if(indexed){
   const U record=selected_record(m,s,self,i.arg[1]);
   vx=m.r32(record+4u);vy=m.r32(record+8u);vz=m.r32(record+12u);
   for(U v:{vx,vy,vz})need(static_cast<std::int32_t>(v)>=-31&&static_cast<std::int32_t>(v)<=31,
                        "B1319 bounded indexed vector");
   need(vx!=0u&&vy!=0u&&vz!=0u&&m.r32(self+0x310u)<=1u,"B1319 useful vector and both parity modes");
 }
 identity(m,matrix);
 const U dir=direction(m,self,angle),sector=(((m.r32(dir)>>10u)+1u)>>1u)&31u;
 s.fp.load_integer32(sector-8u);s.fp.multiply64(floating_b39::read64(m,0x788090u));
 floating_b39::write64(m,angle,s.fp.pop64());
 // Original FILD type63C then FSTP float into first stack argument.
 s.fp.load_integer32(m.r32(type+0x63cu));const U height=s.fp.pop32();
 s.cx=matrix;call(m,s,0x18ce90u,{height,0u,0u});
 s.fp.load64(floating_b39::read64(m,angle));const U radians=s.fp.pop32();
 s.cx=matrix;call(m,s,0x18d7a0u,{radians});
 if(indexed){
   // Root pushes Z, parity-adjusted Y, X in that exact x87 order.
   s.fp.load_integer32(vz);const U z=s.fp.pop32();
   const U signed_y=(m.r32(self+0x310u)&1u)?0u-vy:vy;
   s.fp.load_integer32(signed_y);const U y=s.fp.pop32();
   s.fp.load_integer32(vx);const U x=s.fp.pop32();
   s.cx=matrix;call(m,s,0x18ce90u,{x,y,z});
 }
 for(U k=0;k<3u;++k)m.w32(vector+4u*k,0u);
 s.dx=matrix;s.cx=transformed;call(m,s,0x18e180u,{vector});
 need(s.ax==transformed,"B1319 real58E180 returned output local");
 // Root copies transformed components to its scalar locals before converting.
 const U scalars=root_frame+(indexed?0x18u:0x14u);
 for(U k=0;k<3u;++k)m.w32(scalars+4u*k,m.r32(transformed+4u*k));
 const U x=convert(m,s,scalars,false),y=convert(m,s,scalars+4u,true),z=convert(m,s,scalars+8u,false);
 xyz(m,self,transformed);
 outer.w32(out,m.r32(transformed)+x);outer.w32(out+4u,m.r32(transformed+4u)+y);outer.w32(out+8u,m.r32(transformed+8u)+z);
 i.fp=s.fp;return out;
}
}
U fun_006b6e80(Memory&m,const Inputs&i){return run(m,i,true);}
U fun_006b70c0(Memory&m,const Inputs&i){return run(m,i,false);}
}
