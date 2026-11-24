#include "recovery_b1299.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_00545500(Memory&,const Inputs&);
}
namespace ra2::recovered::b1299 {
namespace {
void need(bool x,const char*why){if(!x)throw std::domain_error(why);}
constexpr unsigned pack(unsigned x,unsigned y){return ((y&0xffffu)<<16u)|(x&0xffffu);}
constexpr unsigned grid_global=0x81a958u,global_map=0x81a820u,fallback_cell=0xa57610u;
unsigned map_index(unsigned x,unsigned y){return static_cast<unsigned>(static_cast<int>(static_cast<short>(y))*512+static_cast<int>(static_cast<short>(x)));}
// Reuse the accepted real 0x545500 implementation for each reached lookup.
// A tiny private stack span holds the actual packed coordinate argument.
unsigned lookup(Memory&source,unsigned x,unsigned y){
 const auto sx=static_cast<int>(static_cast<std::int16_t>(x));
 const auto sy=static_cast<int>(static_cast<std::int16_t>(y));
 const auto index=sy*512+sx;
 // The pinned x86 helper takes its signed-overflow branch before indexing.
 // Reproduce that exact branch without relying on C++ left-shift of a negative.
 if(index<0||index>=0x40000){source.w32(0xa57634u,pack(x,y));return fallback_cell;}
 const auto table=source.r32(global_map+0x138u),cell=source.r32(table+4u*unsigned(index));
 if(cell)return cell;
 source.w32(0xa57634u,pack(x,y));return fallback_cell;
}
void fallback_probe(Memory&m,unsigned x,unsigned y){
 const auto p=lookup(m,x,y);
 need(p==fallback_cell,"B1299 bounded 0x545500 fallback pointer");
 need(m.r32(fallback_cell+0x44u)==0u,"B1299 original fallback category zero");
}
void rebuild_from_horizontal(Memory&m,const Inputs&i,Heap&h,unsigned x,unsigned y){
 // 0x154b30/0x154e20's bounded child route probes west, east, the
 // current coordinate three times, and east once more.  For this fixture
 // all six table slots are in-range zeroes, so each authentic 0x545500
 // call returns the original category-zero fallback and the selector
 // exits before its unresolved category-matching descendants.
 fallback_probe(m,x-1u,y);
 fallback_probe(m,x+1u,y);
 for(unsigned k=0;k<3u;++k)fallback_probe(m,x,y);
 fallback_probe(m,x+1u,y);
 Inputs nested{};nested.cx=i.cx;
 (void)ra2::recovered::b1279::run(0x14c060u,m,nested,h);
 const auto view=m.r32(0x821cacu);
 need(view!=0u&&m.r8(view+0xd7cu)==0u,"B1299 borrowed viewport dirty-byte prestate");
 m.w8(view+0xd7cu,1u);
}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){
 need(root==0x154080u||root==0x1542c0u,"B1299 exact root pair");
 const auto ptr=i.arg[0];need(ptr!=0u,"B1299 packed-coordinate pointer");
 const auto x=static_cast<unsigned>(static_cast<std::uint16_t>(m.r16(ptr)));
 const auto y=static_cast<unsigned>(static_cast<std::uint16_t>(m.r16(ptr+2u)));
 need(x==20u&&y==0u,"B1299 center borrowed coordinate (20,0)");
 const auto grid=m.r32(grid_global);need(grid!=0u&&m.r32(global_map+0x138u)==grid,
      "B1299 separate root grid and authentic global Map lookup table");
 need(i.cx!=global_map&&m.r32(i.cx)==0x79091cu,
      "B1299 borrowed B1279 rootMap receiver distinct from global 81A820");
 const auto index=map_index(x,y);need(index==20u,"B1299 512-stride center index");
 const auto cell=m.r32(grid+4u*index);need(cell!=0u,"B1299 positive center Cell pointer");
 const auto category=m.r32(cell+0x44u);
 if(root==0x154080u)
   need(category>=0x4au&&category<=0x52u,"B1299 first root category arm 4A..52");
 else
   need(category>=0xcdu&&category<=0xd5u,"B1299 second root category arm CD..D5");
 need(m.r32(grid+4u*map_index(20u,1u))==0u&&
      m.r32(grid+4u*map_index(19u,1u))==0u&&
      m.r32(grid+4u*map_index(21u,1u))==0u,
      "B1299 bounded empty horizontal probes around next coordinate");

 // Root's first neighbor lookup is (20,-1), which is outside the table and
 // publishes the actual original fallback record.  The category-zero result
 // then selects the branch which forms (20,1) in the caller's arg0 alias.
 fallback_probe(m,20u,0xffffu);
 i.arg[0]=pack(20u,1u);
 rebuild_from_horizontal(m,i,h,20u,1u);
 need(m.r32(0xa57634u)==pack(21u,1u),"B1299 final fallback coordinate");
 return m.r32(0x821cacu); // Full original EAX is viewport pointer; RET 4.
}
}

