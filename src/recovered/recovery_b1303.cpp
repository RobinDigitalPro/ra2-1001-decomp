#include "recovery_b1303.hpp"
#include "recovery_b1303_ctor.hpp"
#include "recovered/recovery_b220.hpp"
#include "recovered/recovery_b612.hpp"
#include "recovered/global_b58_c.hpp"
#include "recovered/map_b106.hpp"
#include "recovered/direct_b33_memory.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/rng_b70.hpp"
#include "recovered/leaf_memory.hpp"
#include "platform/x87_b61.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <utility>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&,const Inputs&);
}
namespace ra2::recovered::b1303 {
namespace {
#include "recovery_b1303_projection.inc"
void need(bool yes,const char* why){if(!yes)throw std::domain_error(why);}
std::uint64_t q64(Memory&m,U a){return U(m.r32(a))|(std::uint64_t(m.r32(a+4u))<<32u);}

// The B361 helper excerpt above is the already accepted nonzero projection
// adapter. This route differs only in its finite (5,5) cell and viewport.
U queue_cell(Memory&m,U receiver,U entity,const Inputs&i){
 const U epoch=m.r32(0xa2896cu),bits=m.r8(entity+0x12cu);
 need(m.r32(0x81a82cu)==0u&&m.r32(entity+0x5cu)!=epoch&&
      !(bits&0x10u)&&((bits&8u)||m.r8(entity+0x138u))&&
      static_cast<std::int8_t>(m.r8(entity+0x11bu))>=-4&&
      static_cast<std::int8_t>(m.r8(entity+0x11bu))<=4&&
      m.r8(entity+0x11cu)==0u&&m.r32(entity+0x24u)==0x00050005u,
      "1303 actual 6A0410 positive (5,5) queue prestate");
 need(m.r8(0x838f70u)==7u&&m.r32(0x838f80u)==60u&&
      m.r32(0x838ef0u)==0u&&m.r32(0x838ef4u)==0x404e0000u&&
      m.r32(0x838f10u)==0u&&m.r32(0x838f14u)==0x3fce0000u,
      "1303 borrowed initialized 702C0 cache read-set");
 m.w32(entity+0x5cu,epoch);auto height=call_height(m,entity,0xdecafbadu,i.fp);
 const U converted=call_converter(m,0u,i.fp);
 need(converted==0u,"1303 accepted 697FB0 zero conversion");
 const auto screen=project(height,converted);
 const I rx=screen.first-I(m.r32(receiver+0xb0u));
 const I ry=screen.second-I(m.r32(receiver+0xb4u));
 const I minx=I(m.r32(0x821970u))-30;
 const I maxx=I(m.r32(0x821970u))+I(m.r32(0x821978u))+30;
 const I maxy=I(m.r32(0x821974u))+I(m.r32(0x82197cu))+15;
 need(rx>=minx&&rx<=maxx&&ry>=-30&&ry<=maxy,
      "1303 genuine projected (5,5) lies within supplied viewport");
 const U count=m.r32(receiver+0xe0u);need(count<0x31fu,"1303 real queue capacity");
 m.w32(receiver+0xe4u+count*4u,entity);m.w32(receiver+0xe0u,count+1u);
 m.w8(entity+0x138u,0u);m.w8(receiver+0xd7du,1u);
 return count+1u;
}

U lookup(Memory&m,U coord){global_b26::Inputs q{};q.cx=0x81a820u;q.arg[0]=coord;
 return global_b26::fun_00545500(m,q);}
void empty_rectangles(Memory&m,U cell,ra2::platform::x87::State&fp){
 std::array<std::uint8_t,4096> raw{};constexpr U base=0x7c000000u;
 leaf::Memory scratch(raw.data(),base,unsigned(raw.size()));auto local=m;local.add(scratch);
 floating_b61::Inputs p{};p.cx=cell;p.fp=fp;p.arg[0]=base+0x100u;
 (void)recovery_b220::fun_00474d00(local,p);fp=p.fp;
 p.arg[0]=base+0x200u;(void)recovery_b612::fun_00474ab0(local,p);fp=p.fp;
 need(local.r32(base+0x100u+8u)==0u&&local.r32(base+0x100u+12u)==0u&&
      local.r32(base+0x200u+8u)==0u&&local.r32(base+0x200u+12u)==0u,
      "1303 exact category -1 empty B220/B612 rectangles");
 need(m.r32(0xaa60c0u)==0u&&m.r32(0xaa60c8u)==0u&&
      m.r8(0xaa60c5u)==0u&&m.r32(0xaa60ccu)==0u,
      "1303 original 698660 pre-collector-init empty route");
}

U inner(Memory&m,U coord,ra2::platform::x87::State&fp,Heap&h){
 global_b26::Inputs predicate{};predicate.cx=0x81a820u;
 predicate.arg[0]=coord;predicate.arg[1]=1u;
 need(global_b26::fun_00557450(m,predicate)==1u,
      "1303 positive accepted 157450 Map diamond predicate");
 const U cell=lookup(m,coord);
 need(cell!=0xa57610u&&m.r32(cell+0x44u)==0xffffffffu&&
      m.r32(cell+0xecu)==0u,"1303 actual ordinary category -1 cell");
 need(lookup(m,coord)==cell,"1303 second original lookup identity");
 const U owner=h.allocate(0x9cu);need(owner!=0u,"1303 genuine 0xA0 CRT owner");
 leaf::Memory owner_span(reinterpret_cast<std::uint8_t*>(std::uintptr_t(owner)),owner,0xa0u);
 auto local=m;local.add(owner_span);
 recovery_b1303_ctor::Inputs ctor{};ctor.cx=owner;
 ctor.arg[0]=local.r32(local.r32(0x821b88u)+0xf0u);
 ctor.arg[1]=coord;ctor.arg[2]=0xffffffffu;ctor.fp=fp;
 need(recovery_b1303_ctor::fun_005d2e50(local,ctor)==owner,
      "1303 accepted B626 constructor with real 65A120 branch");
 fp=ctor.fp;
 empty_rectangles(local,cell,fp);
 // 698660's pinned zero count exits before its fifth dword argument.
 // 493A3D restores A283C4 from its own earlier stack producer.
 return 1u;
}

U convert(Memory&m,ra2::platform::x87::State&fp){
 std::array<std::uint8_t,0x1000> raw{};constexpr U base=0x7c020000u,entry=base+0x804u;
 leaf::Memory stack(raw.data(),base,unsigned(raw.size()));auto local=m;local.add(stack);
 floating_b39::State s{};s.fp=fp;
 floating_b39::Frame f{};f.entry_sp=entry;f.return_sp=entry;
 f.sp=entry;f.outer_return=0x65432100u;local.w32(entry,f.outer_return);
 bool found=false;for(const auto&e:floating_b39::entries_b())if(e.rva==0x36aa50u){
  e.function(local,s,f,{});found=true;break;}
 need(found&&f.sp==entry+4u,"1303 accepted 76AA50 conversion boundary");
 fp=s.fp;return s.ax;
}

U outer(Memory&m,const Inputs&i,Heap&h){
 const U self=i.cx,coord=i.arg[0],view=m.r32(0x821b88u);
 need(m.r32(self+0xcu)==m.r32(0x839f00u),
      "1303 original 4937A3 guard skips 493A60 on produced coordinate");
 need(m.r32(coord)==0x00050005u&&m.r32(0x839f00u)==0u,
      "1303 actual borrowed packed coordinate");
 std::array<std::uint8_t,64> words{};constexpr U base=0x7c030000u;
 leaf::Memory scratch(words.data(),base,unsigned(words.size()));auto local=m;local.add(scratch);
 local.w32(base,local.r32(coord));
 auto fp=i.fp;const U saved=local.r32(0xa283c4u);
 local.w32(0xa283c4u,0u);
 need(inner(local,base,fp,h)==1u,"1303 nested 938B0 success");
 local.w32(0xa283c4u,saved);
 global_b26::Inputs q{};q.cx=0x81a820u;q.arg[0]=coord;
 const U entity=global_b26::fun_00545500(local,q);
 need(entity!=0xa57610u,"1303 root lookup after nested construction");
 Inputs queue_input=i;queue_input.fp=fp;
 (void)queue_cell(local,local.r32(0x821cacu),entity,queue_input);
 fp=queue_input.fp;
 m.w32(self+0xcu,local.r32(base));
 need(q64(m,view+0x12d8u)==0u,"1303 bounded zero-duration timer route");
 const U config=m.r32(0xa255c0u);need(config!=0u,"1303 real RNG owner");
 fp.load64(q64(m,view+0x12d8u));fp.multiply64(q64(m,0x788140u));
 const auto first=fp.pop64();
 fp.load64(q64(m,view+0x12d8u));fp.multiply64(q64(m,0x7896d0u));
 const auto second=fp.pop64();
 rng_b70::B70Inputs rng{};rng.cx=config+0x218u;
 rng.arg[0]=0u;rng.arg[1]=0x7ffffffeu;
 const U sample=rng_b70::fun_0062fe40(m,rng);
 i.arg[0]=sample; // 49385B overwrites caller arg0 before FILD consumes it.
 // 62FE40 RET8 moves ESP up: [ESP+18] is the first saved double,
 // [ESP+10] the second saved double at 493853..493871.
 fp.load64(first);fp.subtract64(second);
 fp.load_integer32(sample);fp.multiply64(q64(m,0x787280u));
 ra2::platform::x87_b61::reg<0xdec9>(fp);fp.add64(second);
 const U timer=convert(m,fp),epoch=m.r32(0xa2896cu);
 m.w32(self,epoch);m.w32(self+4u,U(first>>32u));m.w32(self+8u,timer);
 i.fp=fp;
 return (epoch&0xffffff00u)|1u;
}
}

std::uint32_t run(std::uint32_t rva,Memory&m,const Inputs&i,Heap&h){
 if(rva==0x938b0u){const U saved=m.r32(0xa283c4u);m.w32(0xa283c4u,0u);
  const U result=inner(m,i.cx,i.fp,h);m.w32(0xa283c4u,saved);return result;}
 if(rva==0x93780u){return outer(m,i,h);}
 throw std::domain_error("1303 exact two-root switch");
}
}
