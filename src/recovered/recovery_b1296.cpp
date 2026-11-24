#include "recovery_b1296.hpp"
#include "recovery_b1296_downstream.hpp"
#include "recovered/recovery_b220.hpp"
#include "recovered/recovery_b612.hpp"
#include "recovered/recovery_b728.hpp"
#include "recovered/floating_scalar_b46_memory.hpp"
#include "recovered/leaf_text_rng.hpp"
#include "recovered/leaf_b56_c.hpp"
#include "recovered/leaf_b15_a.hpp"
#include "recovered/leaf_math.hpp"
#include "recovered/global_b58_c.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::b1296 {
namespace {
void need(bool yes,const char* why){if(!yes)throw std::domain_error(why);}
unsigned packed(int x,int y){return (unsigned(std::uint16_t(y))<<16u)|unsigned(std::uint16_t(x));}
bool north(unsigned root){return root==0x15e390u||root==0x15ed50u;}
unsigned category(unsigned root){switch(root){case 0x15e390u:return 0x4eu;case 0x15e870u:return 0x57u;case 0x15ed50u:return 0xd1u;case 0x15f240u:return 0xdau;default:throw std::domain_error("1296 exact switch root");}}
unsigned base_category(unsigned root){return category(root)-4u;}

// The accepted 176590 instruction translation invokes the accepted 62FDE0
// RNG on its real 250-word state. An explicit leaf span permits its actual
// source to run while the global Memory still owns the full image span.
void rng_call(floating_scalar_b46::Memory& m,
              floating_scalar_b46::State& s,const floating_scalar_b46::Call& call,
              void*){
 need(call.target==0x62fde0u&&call.return_address==0x5765c8u&&
      call.cleanup==0u,"1296 exact RNG boundary");
 need(s.cx==0xa581d8u,"1296 real pinned RNG state");
 need(m.r8(s.cx)==0u&&m.r32(s.cx+4u)==0u&&
      m.r32(s.cx+8u)==0u&&m.r32(s.cx+12u)==0u,
      "1296 genuine first XOR RNG step");
 std::array<std::uint8_t,16> bytes{},before{};
 for(unsigned k=0;k<bytes.size();++k)bytes[k]=std::uint8_t(m.r8(s.cx+k));
 before=bytes;
 leaf::Memory view(bytes.data(),s.cx,unsigned(bytes.size()));
 leaf::Inputs in{};in.cx=s.cx;in.dx=s.dx;
 s.ax=leaf::fun_0062fde0(view,in);
 s.dx=1u; // Original 62FE09..62FE17 leaves its incremented j in EDX.
 for(unsigned k=0;k<bytes.size();++k)if(bytes[k]!=before[k])m.w8(s.cx+k,bytes[k]);
}
unsigned choose(Memory&m,ra2::platform::x87::State& fp){
 std::array<std::uint8_t,4096> stack{};constexpr unsigned b=0x7b000000u,e=b+2048u;
 leaf::Memory span(stack.data(),b,unsigned(stack.size()));Memory local=m;local.add(span);
 floating_scalar_b46::State s{};s.ax=0u;s.cx=0u;s.dx=3u;s.fp=fp;
 floating_scalar_b46::Frame f{};f.entry_sp=e;f.return_sp=e;f.sp=e;
 f.outer_return=0x76543210u;f.boundary_count=1u;
 f.boundaries[0]={0x62fde0u,0x5765c8u,0u,0u};
 local.w32(e,f.outer_return);
 floating_scalar_b46::Operations op{rng_call,nullptr};
 auto fn=floating_scalar_b46::entries_a().front().function;
 fn(local,s,f,op);fp=s.fp;
 need(f.sp==e+4u&&s.ax<=3u,"1296 bounded actual 176590 result");
 return s.ax;
}
void rectangle(Memory&m,unsigned cell,unsigned output,bool variant,
               ra2::platform::x87::State& fp){
 floating_b61::Inputs q{};q.cx=cell;q.arg[0]=output;q.fp=fp;
 if(variant)(void)recovery_b612::fun_00474ab0(m,q);
 else (void)recovery_b220::fun_00474d00(m,q);
 fp=q.fp;
}
unsigned lookup(Memory&m,int x,int y){
 const std::int64_t idx=std::int64_t(y)*512+x;
 if(idx>=0&&idx<0x40000){const auto table=m.r32(0x81a958u);
  need(table!=0u,"1296 real borrowed cell table");
  if(const auto p=m.r32(table+unsigned(idx)*4u))return p;}
 m.w32(0xa57634u,packed(x,y));return 0xa57610u;
}
void redraw_cell(Memory&m,unsigned cell,int x,int y){
 need(cell!=0xa57610u&&m.r32(cell+0x38u)==0xffffu,
      "1296 actual center 472140 no-art route");
 const auto table=m.r32(0xa1e11cu),ord=m.r32(cell+0x44u);
 const auto record=m.r32(table+4u*ord);
 need(record!=0u&&m.r8(record+0x27cu)==0u&&
      m.r32(0x821b88u)!=0u&&m.r8(m.r32(0x821b88u)+0x584u)==0u,
      "1296 original 47240B-472BC2 renderer branch");
 m.w32(cell+0xecu,m.r32(record+0x268u));
 m.w8(cell+0x11cu,0u);
 floating_b61::Inputs q{};q.cx=cell;q.arg[0]=0xffffffffu;
 (void)recovery_b728::fun_00478b40(m,q);
 need(m.r32(cell+0x4cu)==7u,"1296 genuine 478B40 AL0 cache write");
 // 54CF40 on the bounded 1x3/3x1 borrowed cells yields stride 19 index.
 // Original 472BC9..472BE5 writes both separate cache arrays.
 const auto idx=unsigned(19*y+x);
 need(m.r32(cell+0x24u)==packed(x,y)&&m.r32(0x81a884u)!=0u&&
      m.r32(0x81a88cu)!=0u&&m.r32(0x81a820u+0xf0u)==7u&&
      m.r32(0x81a820u+0xf4u)==11u,
      "1296 bounded original cell cache index");
 m.w8(m.r32(0x81a884u)+4u*idx,m.r8(cell+0x4cu));
 m.w8(m.r32(0x81a884u)+4u*idx+1u,m.r8(cell+0x11bu));
 m.w8(m.r32(0x81a88cu)+10u*idx+8u,m.r8(cell+0x11bu));
}
}

unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){
 const unsigned old=category(root);
 const unsigned inptr=i.arg[0];need(m.r32(inptr)==packed(1,1),"1296 borrowed center coordinate 1,1");
 need(m.r32(0xa57654u)==0u,"1296 original fallback category zero");
 // Initial axial neighbor is fallback; center and the two perpendicular
 // neighbors are three distinct borrowed cells. Their categories all change.
 need(lookup(m,north(root)?0:1,north(root)?1:0)==0xa57610u,
      "1296 initial axial fallback");
 const unsigned cell=lookup(m,1,1);
 need(cell!=0xa57610u&&m.r32(cell+0x44u)==old,"1296 positive real category");
 const int bx=north(root)?1:0,by=north(root)?0:1;
 const int ax=north(root)?1:2,ay=north(root)?2:1;
 const unsigned before=lookup(m,bx,by),after=lookup(m,ax,ay);
 need(before!=0xa57610u&&after!=0xa57610u&&before!=cell&&
      after!=cell&&after!=before&&m.r32(before+0x44u)==old&&
      m.r32(after+0x44u)==old,"1296 three authentic category cells");
 std::array<std::uint8_t,4096> stack{};constexpr unsigned sb=0x7c000000u;
 leaf::Memory scratch(stack.data(),sb,unsigned(stack.size()));Memory local=m;local.add(scratch);
 auto fp=i.fp;
 rectangle(local,cell,sb+0x100u,false,fp);
 rectangle(local,cell,sb+0x200u,true,fp);
 need(std::int32_t(local.r32(sb+0x200u+8u))<=0||
      std::int32_t(local.r32(sb+0x200u+12u))<=0,
      "1296 original minimum rectangle branch");
 const unsigned choice=choose(local,fp),next=base_category(root)+choice;
 need(next!=old,"1296 genuine category mutation");
 local.w32(cell+0x44u,next);local.w32(before+0x44u,next);
 local.w32(after+0x44u,next);
 // Accepted B220/B612 run again after the category change, as in the
 // mandatory projection/dirty-collector continuation.
 rectangle(local,cell,sb+0x300u,false,fp);
 rectangle(local,cell,sb+0x400u,true,fp);
 local.w32(sb+0x500u,north(root)?1u:0u);
 local.w32(sb+0x504u,north(root)?0u:1u);
 local.w32(sb+0x508u,north(root)?1u:3u);
 local.w32(sb+0x50cu,north(root)?3u:1u);
 // The original mandatory projection chain remains local to its stack.
 // Execute its four accepted integer helpers on the actual helper outputs;
 // the following original collector's pinned zero state retains no rect.
 leaf::Inputs geom{};geom.cx=sb+0x600u;geom.dx=sb+0x400u;
 geom.arg[0]=sb+0x300u;(void)leaf::fun_0045ec50(scratch,geom);
 geom.cx=sb+0x610u;geom.dx=sb+0x100u;geom.arg[0]=sb+0x600u;
 (void)leaf::fun_0045ec50(scratch,geom);
 geom.cx=sb+0x610u;geom.arg[0]=sb+0x730u;
 (void)leaf::fun_00435420(scratch,geom);
 scratch.w32(sb+0x700u,local.r32(0x821970u));
 scratch.w32(sb+0x704u,local.r32(0x821974u));
 geom.cx=sb+0x730u;geom.arg[0]=sb+0x740u;geom.arg[1]=sb+0x700u;
 (void)leaf::fun_0047cc40(scratch,geom);
 geom.cx=sb+0x750u;geom.arg[0]=sb+0x740u;
 geom.arg[1]=local.r32(sb+0x610u+8u);
 geom.arg[2]=local.r32(sb+0x610u+12u);
 (void)leaf::fun_00453ab0(scratch,geom);
 need(m.r32(0xaa60c0u)==0u&&m.r32(0xaa60c8u)==0u&&
      m.r8(0xaa60c5u)==0u&&m.r32(0xaa60ccu)==0u,
      "1296 authentic empty dirty collector state");
 redraw_cell(local,cell,1,1);
 redraw_cell(local,before,bx,by);
 redraw_cell(local,after,ax,ay);
 const unsigned next_cell=lookup(local,north(root)?2:1,north(root)?1:2);
 need(next_cell==0xa57610u,"1296 actual end-loop fallback");
 b1279::Inputs zone{};zone.cx=i.cx;
 (void)b1279::run(0x14c060u,m,zone,h);
 b1279::Inputs region{};region.cx=i.cx;region.arg[0]=sb+0x500u;
 const unsigned eax=region_scan(local,region,h);
 i.fp=fp;
 return eax; // Original 565681 CRT free BOOL is the final EAX; RET4.
}
}
