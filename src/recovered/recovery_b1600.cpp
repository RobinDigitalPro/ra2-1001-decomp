#include "recovered/recovery_b1600.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_00545490(Memory&,const Inputs&);std::uint32_t fun_00545500(Memory&,const Inputs&);}
namespace ra2::recovered::b1600{namespace{void need(bool v){if(!v)throw std::domain_error("B1600 finitefallback connectionmaskrefresh");}}
U fun_00450640(Memory&m,const Inputs&i){
 constexpr U sentinel=0xa57610,private_xyz=0x7d020000;const U self=i.cx;need(self);const U type=m.r32(self+0x418),house=m.r32(self+0x1b4),table=m.r32(0x81a958);
 need(m.r8(type+0x135a)!=0&&m.r8(house+0x142)==0&&m.r32(self+0x47c)==0&&m.r32(self+0x4f0)!=0&&m.r8(self+0x75)==0);
 const U x=m.r32(self+0x88),y=m.r32(self+0x8c),z=m.r32(self+0x90);need((x==768||x==1024)&&y==768&&z<1024&&m.r32(0x81a95c)==4096);
 need(m.r8(0xa285a8)!=0&&m.r32(sentinel+0xe4)==0);
 struct Span{U at,size;};const std::array<Span,9>spans{{{self,0x600},{type,0x1400},{house,0x200},{table,0x4000},{0x81a000,4096},{0xa28000,4096},{0xa57000,4096},{0x839000,4096},{private_xyz,4096}}};
 for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.at&&std::uint64_t(a.at)+a.size<=0x100000000ull);if(j<8){(void)m.r8(a.at);(void)m.r8(a.at+a.size-1);}for(U k=0;k<j;++k)need(std::uint64_t(a.at)+a.size<=spans[k].at||std::uint64_t(spans[k].at)+spans[k].size<=a.at);}
 std::array<std::uint8_t,4096>scratch{};leaf::Memory span(scratch.data(),private_xyz,U(scratch.size()));Memory local=m;local.add(span);
 auto own_query=[&](){local.w32(private_xyz,x);local.w32(private_xyz+4,y);local.w32(private_xyz+8,z);global_b26::Inputs q=i;q.cx=0x81a820;q.arg[0]=private_xyz;need(global_b26::fun_00545490(local,q)==sentinel);};
 own_query();
 // 4766C0 reads the fallback cell's current packedXY. Every545500 fallback
 // rewrites that very field atA57634, so each subsequent iteration reloads it.
 for(U direction=0;direction<8;direction+=2){const U packed=m.r32(sentinel+0x24);const U dx=m.r16(0x839da0+direction*4),dy=m.r16(0x839da2+direction*4);need(global_b26::s32(global_b26::sx16(dx))>=-1&&global_b26::s32(global_b26::sx16(dx))<=1&&global_b26::s32(global_b26::sx16(dy))>=-1&&global_b26::s32(global_b26::sx16(dy))<=1);const U nx=((packed&65535)+dx)&65535,ny=((packed>>16)+dy)&65535;need(nx<8&&ny<8);local.w32(private_xyz,nx|(ny<<16));global_b26::Inputs q=i;q.cx=0x81a820;q.arg[0]=private_xyz;need(global_b26::fun_00545500(local,q)==sentinel);need(m.r32(sentinel+0xe4)==0);}
 // Actual4713B0 sees its enabled global and an empty public actor list; EAX0
 // leaves the four connection bits zero. House142zero adds no ownershipbit.
 own_query();const U old=m.r32(self+0x4f0);m.w32(self+0x4f0,0);m.w8(self+0x75,1);
 // Actual72140sentinel guard jumps directly to its epilogue without changing
 // EAX. The root's two MOV AL,false operations retain the old mask's high24.
 return old&0xffffff00u;
}
}
