#include "recovered/recovery_b1601.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_00545490(Memory&,const Inputs&);std::uint32_t fun_00545500(Memory&,const Inputs&);}
namespace ra2::recovered::b1601{namespace{void need(bool v){if(!v)throw std::domain_error("B1601 finitefallback neighborcleanup");}}
U fun_006d93e0(Memory&m,const Inputs&i){
 constexpr U sentinel=0xa57610,private_xyz=0x7d020000;const U self=i.cx;need(self&&m.r32(self)==0x78612c&&m.r32(0x78612c+0x1a0)==0x41b320&&m.r8(self+0x76)==0);
 const U x=m.r32(self+0x88),y=m.r32(self+0x8c),z=m.r32(self+0x90),table=m.r32(0x81a958),guard=m.r32(0xa283c4);need((x==768||x==1024)&&y==768&&z<1024&&m.r32(0x81a95c)==4096&&m.r8(0xa285a8)==0&&guard!=0&&(m.r32(sentinel+0x124)&0x40));
 struct Span{U at,size;};const std::array<Span,8>spans{{{self,0x5b0},{table,0x4000},{0x786000,4096},{0x81a000,4096},{0x839000,4096},{0xa28000,4096},{0xa57000,4096},{private_xyz,4096}}};for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.at&&std::uint64_t(a.at)+a.size<=0x100000000ull);if(j<7){(void)m.r8(a.at);(void)m.r8(a.at+a.size-1);}for(U k=0;k<j;++k)need(std::uint64_t(a.at)+a.size<=spans[k].at||std::uint64_t(spans[k].at)+spans[k].size<=a.at);}
 std::array<std::uint8_t,4096>scratch{};leaf::Memory span(scratch.data(),private_xyz,U(scratch.size()));Memory local=m;local.add(span);
 // ActualAir1A0=41B320 truncates both positive coordinates into the caller's
 // fully produced private packed pair. BX/BP retain this base through all8iterations.
 const U base_x=x/256,base_y=y/256;
 for(U direction=0;direction<8;++direction){const U dx=m.r16(0x839da0+direction*4),dy=m.r16(0x839da2+direction*4);need(global_b26::s32(global_b26::sx16(dx))>=-1&&global_b26::s32(global_b26::sx16(dx))<=1&&global_b26::s32(global_b26::sx16(dy))>=-1&&global_b26::s32(global_b26::sx16(dy))<=1);const U nx=(base_x+dx)&65535,ny=(base_y+dy)&65535;need(nx<8&&ny<8);local.w32(private_xyz,nx|(ny<<16));global_b26::Inputs q=i;q.cx=0x81a820;q.arg[0]=private_xyz;need(global_b26::fun_00545500(local,q)==sentinel);m.w8(sentinel+0x122,m.r8(sentinel+0x122)-1u);}
 local.w32(private_xyz,x);local.w32(private_xyz+4,y);local.w32(private_xyz+8,z);global_b26::Inputs q=i;q.cx=0x81a820;q.arg[0]=private_xyz;need(global_b26::fun_00545490(local,q)==sentinel);m.w32(sentinel+0x124,m.r32(sentinel+0x124)&~0x40u);
 // The second authentic1A0 call produces the same private pair. Actual5CBD90
 // observes globalA285A8zero and returnsAL0 without virtual/provider actions.
 local.w32(private_xyz,base_x|(base_y<<16));q.arg[0]=private_xyz;need(global_b26::fun_00545500(local,q)==sentinel);
 // Actual72140A57610guard is a no-effect child of this useful outer cleanup.
 // NonzeroA283C4 takes6D94E3JNZ, so the heldworld/hash refresh is not invoked.
 return guard&0xffffff00u;
}
}
