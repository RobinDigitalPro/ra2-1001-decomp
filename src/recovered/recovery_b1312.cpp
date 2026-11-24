#include "recovery_b1312.hpp"
#include "recovered/numeric_b105.hpp"
#include "recovered/floating_b39_memory.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/leaf_memory.hpp"
#include "platform/x87_extended_b40.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::b1312 {
namespace {
using U=std::uint32_t;
using M39=floating_b39::Memory;
constexpr U stack_base=0x7d400000u, ret=0x13579bdfu;
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}

floating_b39::Function b39(U rva){
 for(const auto&e:floating_b39::entries_a())if(e.rva==rva)return e.function;
 for(const auto&e:floating_b39::entries_b())if(e.rva==rva)return e.function;
 throw std::runtime_error("B1312 missing accepted B39 entry");
}
floating_callers_b40::Function b40(U rva){
 for(const auto&e:floating_callers_b40::entries_a())if(e.rva==rva)return e.function;
 throw std::runtime_error("B1312 missing accepted B40 entry");
}
void call_b39(M39&m,floating_b39::State&s,U rva,U entry,U arg0=0u,bool has_arg=false){
 m.w32(entry,ret);if(has_arg)m.w32(entry+4u,arg0);
 floating_b39::Frame f{};f.entry_sp=entry;f.sp=entry;f.return_sp=entry;f.outer_return=ret;
 b39(rva)(m,s,f,{});
 need(f.sp==entry+4u+(has_arg?4u:0u),"B1312 accepted B39 stack cleanup");
}
U getter(M39&m,floating_b39::State&s,U self,U index){
 const U vp=m.r32(self);need(vp==0x78612cu,"B1312 constructor-installed original vptr");
 need(m.r32(vp+0x39cu)==0x6cdab0u&&m.r32(vp+0x80u)==0x6b6910u&&m.r32(vp+0x84u)==0x41b600u,
      "B1312 original getter slots");
 // 6CDAB0 first calls the original double predicate at self+118.
 s.cx=self+0x118u;call_b39(m,s,0x307fe0u,stack_base+0x1000u);
 const U type=m.r32(self+0x5acu);need(type!=0u,"B1312 41B600 type getter result");
 U element=type+0x8f4u+index*0x1cu;
 if((s.ax&255u)==0u||m.r32(element)==0u)element=type+0x74cu+index*0x1cu;
 return element;
}
U convert(M39&m,floating_b39::State&s,U entry){
 call_b39(m,s,0x36aa50u,entry);return s.ax;
}
U project(M39&m,U context,ra2::platform::x87::State&fp,U input0,U input1,U frame){
 m.w32(frame,ret);m.w32(frame+4u,input0);m.w32(frame+8u,input1);
 floating_callers_b40::State s{};s.cx=context;s.fp=fp;
 floating_callers_b40::Frame f{};f.entry_sp=frame;f.sp=frame;f.return_sp=frame;f.outer_return=ret;
 b40(0x297f40u)(m,s,f,{});
 need(f.sp==frame+12u,"B1312 original projection RET 8");fp=s.fp;
 return s.ax;
}
}

U fun_0044ea50(floating_b61::Memory&m,const floating_b61::Inputs&i){
 const U self=i.cx,out=i.arg[0],index=i.arg[1];
 need(self&&out,"B1312 explicit self/output inputs");
 need(index<3u&&(i.arg[2]&255u)==1u&&m.r32(self+0x310u)==0u,
      "B1312 finite index/flag/mode route");
 std::array<std::uint8_t,0x10000> root_stack_bytes{};
 leaf::Memory root_stack(root_stack_bytes.data(),stack_base,U(root_stack_bytes.size()));
 // B39 and B61 both expose the same declared-span Memory type.
 // Copying the adapter preserves the caller's spans without any arena-base assumption.
 auto root39=m;root39.add(root_stack);
 // Read/call the actual 6CDAB0 getter route before the branch uses self+310.
 floating_b39::State state{};state.fp=i.fp;state.cx=self;
 U selected=0u;try{selected=getter(root39,state,self,index);}catch(const std::exception&e){throw std::runtime_error(std::string("B1312 getter stage: ")+e.what());}
 need(selected!=0u&&root39.r32(selected)!=0u,"B1312 original nonnull indexed getter item");
 const U flag=i.arg[2]&255u; // original arg2 stack word; TEST CL,CL reads its low byte.
 U mode;
 if(flag){
   mode=m.r32(self+0x310u);
   if(mode==0u)mode=m.r32(m.r32(selected)+0x9cu)-1u;
   else --mode;
 }else mode=m.r32(self+0x310u);
 const U inner=m.r32(self+0x418u);need(inner!=0u,"B1312 borrowed inner numeric state");
 need(mode==0u&&m.r32(inner+0x13d4u)==0u&&m.r32(inner+0x13d8u)==0u&&m.r32(inner+0x13dcu)==0u,
      "B1312 finite zero local-vector route");
 U offset=0u;
 if(mode==0u)offset=m.r32(inner+0x13d8u);
 else if(mode==1u)offset=0u-m.r32(inner+0x13d8u);
 i.arg[2]=offset;

 // Root's 453550 output buffer is the local 3x4 matrix at +3c; its input
 // vector is at +24. The source fields are FILD'd in exact instruction order.
 constexpr U local=stack_base+0x20000u;
 std::array<std::uint8_t,0x10000> raw{};leaf::Memory scratch(raw.data(),local,U(raw.size()));
 auto mm=m;mm.add(scratch);auto mm39=root39;mm39.add(scratch);
 // 453550 removes only its matrix argument. The still-pushed vector argument
 // makes LEA [ESP+34] at 44EAFF point to root-frame +30, not +34.
 const U vin=local+0x24u,matrix=local+0x3cu,vout=local+0x30u;
 state.fp.load_integer32(m.r32(inner+0x13dcu));
 state.fp.load_integer32(m.r32(inner+0x13d4u));
 mm.w32(vin,state.fp.pop32());
 state.fp.load_integer32(offset);
 mm.w32(vin+4u,state.fp.pop32());mm.w32(vin+8u,state.fp.pop32());
 floating_b61::Inputs transform{};transform.cx=self;transform.fp=state.fp;
 transform.arg[0]=matrix;transform.arg[1]=vin;
 U matrix_result=0u;try{matrix_result=numeric_b105::fun_00453550(mm,transform);}catch(const std::exception&e){throw std::runtime_error(std::string("B1312 453550 stage: ")+e.what());}
 state.fp=transform.fp;
 need(matrix_result==matrix,"B1312 accepted 453550 returned local matrix");
 state.dx=matrix_result;state.cx=vout;
 try{call_b39(mm39,state,0x18e180u,local+0x3000u,vin,true);}catch(const std::exception&e){throw std::runtime_error(std::string("B1312 58e180 stage: ")+e.what());}
 // Three exact 76AA50 conversions with root's unary negation of component one.
 U x=0u,y=0u,z=0u;
 try{state.fp.load32(mm39.r32(vout));x=convert(mm39,state,local+0x4000u);
 state.fp.load32(mm39.r32(vout+4u));state.fp.change_sign();
 y=convert(mm39,state,local+0x5000u);
 state.fp.load32(mm39.r32(vout+8u));z=convert(mm39,state,local+0x7000u);}catch(const std::exception&e){throw std::runtime_error(std::string("B1312 76aa50 stage: ")+e.what());}
 need(x==0u&&y==0u&&z==0u,"B1312 zero vector remains zero through accepted transform and 76AA50");

 // Vtable +A8 -> 41B270 -> +48 -> 5CD4D0 copies this exact borrowed XYZ.
 const U vp=m.r32(self);need(m.r32(vp+0xa8u)==0x41b270u&&m.r32(vp+0x48u)==0x5cd4d0u,
   "B1312 original triple getter targets");
 // Exact 5CD4D0 three-DWORD read/write order through the shared adapter.
 // The original +A8 wrapper receives a root-local buffer, not caller arg0.
 const U xyz=local+0x30u;
 mm39.w32(xyz,m.r32(self+0x88u));
 mm39.w32(xyz+4u,m.r32(self+0x8cu));
 mm39.w32(xyz+8u,m.r32(self+0x90u));
 const U proj_context=m.r32(0x821cacu);need(proj_context!=0u,"B1312 borrowed original projection context");
 const U proj_out=local+0x18u,proj_in=local+0x10u;
 mm39.w32(proj_out,0u);mm39.w32(proj_out+4u,0u);
 mm39.w32(proj_in,m.r32(inner+0xf68u));mm39.w32(proj_in+4u,m.r32(inner+0xf6cu));
 U projected=0u;try{projected=project(mm39,proj_context,state.fp,proj_out,proj_in,local+0x9000u);}catch(const std::exception&e){throw std::runtime_error(std::string("B1312 697f40 stage: ")+e.what());}
 need(projected>=local&&projected+8u<local+0x10000u,"B1312 697F40 returned local projection vector");
 m.w32(out,mm39.r32(xyz)+x+mm39.r32(projected));
 m.w32(out+4u,mm39.r32(xyz+4u)+y+mm39.r32(projected+4u));
 m.w32(out+8u,mm39.r32(xyz+8u)+z);
 i.fp=state.fp;
 return out;
}
}


