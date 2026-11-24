#include "recovered/recovery_b1606.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/map_b87.hpp"
#include "recovered/map_b106.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_00545500(Memory&,const Inputs&);}
namespace ra2::recovered::b1606 {
namespace {void need(bool b){if(!b)throw std::domain_error("B1606 finite nonresident region reset");}}
U run(U root,Memory& original,const Inputs&i,ra2::platform::ordinary_heap::Heap&heap){
 need(root==0x3068e0&&i.cx!=0x81a820&&original.r32(i.cx+0xe0)==0x00070007);
 const U manager=i.cx,map=0x81a820,sentinel=0xa57610;
 need(original.r32(sentinel+0xec)==2&&original.r8(sentinel+0x11c)==0&&original.r32(map+0xf0)==7);
 // The declared direction table is exactly its authenticated zero image.
 // This finite aliasing domain does not claim initialized compass directions.
 for(U k=0;k<8;++k)need(original.r32(0x839da0+4*k)==0);
 const U header=original.r32(manager+0x9c);need(original.r32(header)==0&&original.r32(header+8));
 const U grid=original.r32(map+0x138);need(original.r32(grid+0x3804)==0);for(U y=5;y<=9;++y)for(U x=5;x<=9;++x)need(original.r32(grid+4*(512*y+x))==0);
 std::array<std::uint8_t,4> bytes{};leaf::Memory point(bytes.data(),0x7d040000u,4);Memory m=original;m.add(point);
 const auto lookup=[&](U packed){point.w32(point.base(),packed);global_b26::Inputs q{};q.cx=map;q.arg[0]=point.base();const U cell=global_b26::fun_00545500(m,q);need(cell==sentinel);return cell;};
 const U packed=m.r32(manager+0xe0);U cell=lookup(packed);m.w32(cell+0x44,0x7e);m.w8(cell+0x11e,0);
 // Actual72140 first sentinel guard returns before any body-side work.
 for(U k=0;k<8;++k){const U old=m.r32(cell+0x24),delta=m.r32(0x839da0+4*k);const U xy=U(std::uint16_t(old+delta))|(U(std::uint16_t((old>>16)+(delta>>16)))<<16);cell=lookup(xy);m.w32(cell+0x44,(k&1)?0xffffffffu:0x7e);m.w8(cell+0x11e,0);}
 for(int y=-2;y<=2;++y)for(int x=-2;x<=2;++x){const U xy=U(std::uint16_t(7+x))|(U(std::uint16_t(7+y))<<16);cell=lookup(xy);Inputs q=i;q.cx=cell;need((map_b87::fun_0047a270(m,q)&255)==0);}
 // Every reached7A900 uses the real7A270 EC=2 guard, so its render body
 // is unreachable. Actual72140 uses its independent sentinel guard.
 Inputs q=i;q.cx=manager;map_b106::fun_00706660(m,q);
 q.cx=map;q.arg[0]=manager+0xe0;map_b87::fun_0054cfb0(m,q);
 // Base class7 leaves the cache unchanged before the material old-label reset.
 q.arg[0]=manager+0xe0; // ActualRoot pushes EBP again at7069BA.
 const U result=b1605::run(0x163130,m,q,heap);m.w8(manager+0xe8,1);i.fp=q.fp;return result;
}
}
