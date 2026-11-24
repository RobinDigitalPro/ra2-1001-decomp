#include "recovered/recovery_b1599.hpp"
#include "recovered/map_b106.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_00545490(Memory&,const Inputs&);}
namespace ra2::recovered::b1599 {namespace{void need(bool v){if(!v)throw std::domain_error("B1599 old-cell and destination cleanup");}}
U fun_0058fd70(Memory&m,const Inputs&i){
 const U self=i.cx,xyz=i.arg[0];need(self&&xyz);const U owner=m.r32(self+12),table=m.r32(0x81a958),oldcell=m.r32(table+1539u*4u),newcell=m.r32(table);
 need(m.r32(0x81a95c)==1540&&oldcell&&newcell&&oldcell!=newcell);
 need(m.r32(owner)==0x78612c&&m.r32(0x78612c+0xec)==0x5cd070&&m.r8(owner+0x76)!=0&&m.r8(owner+0x7d)==0);
 need(m.r32(xyz)==0&&m.r32(xyz+4)==0&&m.r32(xyz+8)==0&&m.r32(0xa58730)==0&&m.r32(0xa58734)==0&&m.r32(0xa58738)==0);
 need(m.r32(self+0x24)==768&&m.r32(self+0x28)==768&&m.r32(self+0x2c)==0&&m.r32(0xa5aa98)==0);
 need(m.r8(oldcell+0x11b)==0&&m.r8(oldcell+0x11c)==0&&(m.r32(oldcell+0x140)&0x100)==0&&(m.r32(oldcell+0x124)&0x40));
 need(m.r32(newcell+0x44)==0xffffffffu&&m.r8(0x838f70)==7&&m.r32(0x838f80)==256&&m.r32(0x7c3a04)==0xe7f&&floating_b61::read64(m,0x785728)==0x3fe0000000000000ull);
 need(i.fp.image.word(8)==0xffff&&(i.fp.image.word(4)&~0x3800u)==0);
 constexpr U scratch_base=0x7d020000u;struct Span{U at,size;};const std::array<Span,15>spans{{{self,0x40},{owner,0x5b0},{xyz,12},{table,1540u*4u},{oldcell,0x200},{newcell,0x200},{0x785000,4096},{0x786000,4096},{0x7c3000,4096},{0x81a000,4096},{0x838000,4096},{0xa58000,4096},{0xa5a000,4096},{scratch_base,4096},{0x7d000000,0x8000}}};
 for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.at&&std::uint64_t(a.at)+a.size<=0x100000000ull);if(j<13){(void)m.r8(a.at);(void)m.r8(a.at+a.size-1);}for(U k=0;k<j;++k)need(std::uint64_t(a.at)+a.size<=spans[k].at||std::uint64_t(spans[k].at)+spans[k].size<=a.at);}
 // The root's non-sentinel old destination invokes actualAirEC. Its selected
 // 557070 route is the identical byte-bound flat4702C0 composition used in B1593.
 std::array<std::uint8_t,4096>scratch{};leaf::Memory span(scratch.data(),scratch_base,U(scratch.size()));Memory local=m;local.add(span);local.w32(scratch_base,768);local.w32(scratch_base+4,768);
 Inputs height{};height.cx=oldcell;height.arg[0]=scratch_base;height.fp=i.fp;
 const U h=map_b106::fun_004702c0(local,height);i.fp=height.fp;need(h==0);
 // RealEC's height+bias<=oldZ and clear140bit100 select original5CD0C4.
 m.w32(oldcell+0x124,m.r32(oldcell+0x124)&~0x40u);
 // The root independently produces its incoming sentinel triple for545490.
 local.w32(scratch_base,0);local.w32(scratch_base+4,0);local.w32(scratch_base+8,0);
 global_b26::Inputs query=i;query.cx=0x81a820;query.arg[0]=scratch_base;need(global_b26::fun_00545490(local,query)==newcell);
 // Actual4768C0 reads newcell44=-1 and returns through478246 before every
 // action/provider/constructor. Owner76 is nonzero; the outer root clears its
 // destination and owner7Dzero selects the epilogue. The old action hold remains.
 m.w32(self+0x24,0);m.w32(self+0x28,0);m.w32(self+0x2c,0);return 0;
}
}
