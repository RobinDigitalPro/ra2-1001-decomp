#include "recovered/recovery_b1572.hpp"
#include "recovered/recovery_b1572_child.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_00545500(Memory&,const Inputs&);}
namespace ra2::recovered::recovery_b1572 {
std::uint32_t run(Memory&m,const Inputs&i){using U=std::uint32_t;using namespace floating_b61;auto need=[](bool v){if(!v)throw std::domain_error("1572 fixedpositive numeric/query composition");};auto&s=i.fp;need(s.image.word(0)==0x0e7f&&s.image.word(4)==0&&s.image.word(8)==0xffff);need(m.r32(i.cx)==0x787bbcu&&m.r32(m.r32(i.cx+0x418u)+0x3ccu)==0);need(m.r32(i.arg[1])==0x000f0010u&&m.r32(i.arg[2])==0x000f0010u&&i.arg[3]==1&&i.arg[4]==2);
 const U from=m.r32(i.arg[1]),to=m.r32(i.arg[2]);i.arg[1]=global_b26::sx16(to);s.load_integer32(i.arg[1]);i.arg[1]=global_b26::sx16(from);s.load_integer32(i.arg[1]);s.subtract_pop();const auto dx=s.pop64();i.arg[1]=global_b26::sx16(from>>16);s.load_integer32(i.arg[1]);i.arg[1]=global_b26::sx16(to>>16);s.load_integer32(i.arg[1]);s.subtract_pop();const auto dy=s.pop64();
 // ActualBA270 zero-delta branch, including all physicalFLD/FSTP/FCOMP effects.
 s.load64(dx);const U fx=s.pop32();s.load64(dy);const U fy=s.pop32();s.load32(fx);s.compare_pop32(0);s.load32(fy);(void)s.status();s.compare_pop32(0);(void)s.status();need(fx==0&&fy==0);s.load32(0);
 s.subtract64(read64(m,0x786630u));s.multiply64(read64(m,0x786628u));const auto cw=s.control();const auto cached=std::uint16_t(m.r32(0x7c3a04u));if(cw!=cached)s.load_control_masked(cached);const U angle=U(s.pop_integer64());i.arg[1]=(i.arg[1]&0xffff0000u)|(angle&0xffffu);U sector=i.arg[1]>>12u;++sector;sector>>=1u;sector^=0xfffffffcu;--sector;sector&=7u;need(sector==5);
 auto step=[&](U packed,U dir){const U delta=m.r32(0x839da0u+4u*dir);return U(std::uint16_t(packed+delta))|(U(std::uint16_t((packed>>16)+(delta>>16)))<<16);};i.arg[1]=to;U point=step(to,sector);i.arg[1]=point;i.arg[3]=0u;point=step(point,(sector+3u)&7u);i.arg[1]=point;
 std::array<std::uint8_t,4>bytes{};leaf::Memory local(bytes.data(),0x10010u,4);local.w32(0x10010u,point);Memory childmem=m;childmem.add(local);global_b26::Inputs lookup{};lookup.cx=0x81a820u;lookup.arg[0]=0x10010u;const U cell=global_b26::fun_00545500(childmem,lookup);need(cell!=0xa57610u);
 const U type=m.r32(i.cx+0x418u);need(m.r32(type)==0x7881f8u&&m.r32(0x7882a0u)==0x45d4f0u&&m.r8(type+0x1387u)==0);Inputs child=i;child.cx=type;child.arg[0]=0x10010u;child.arg[1]=m.r32(i.cx+0x1b4u);const U pass=b1572_child::fun_006d3650(childmem,child);i.fp=child.fp;const U query=(pass&255u)?0u:7u;need(query==0);m.w32(i.arg[0],point);return i.arg[0];
}
}
