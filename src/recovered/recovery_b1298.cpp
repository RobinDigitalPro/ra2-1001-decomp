#include "recovery_b1298.hpp"
#include "map_b106.hpp"
#include "recovery_b110.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b1298 {
std::uint32_t fun_00508220(Memory&m,const Inputs&i){
 auto need=[](bool q,const char*s){if(!q)throw std::domain_error(s);};
 need(m.r32(i.cx)==0x787bbcu&&m.r32(0x787d6cu)==0x5ccea0u,"1298 original height dispatch");
 need(m.r32(i.cx+0x88u)==0u&&m.r32(i.cx+0x8cu)==0u&&m.r32(i.cx+0x90u)==0u&&m.r8(i.cx+0x79u)==0u,"1298 zero world point");
 const auto owner=m.r32(i.cx+0x1b4u);need(owner&&m.r8(owner+0x134u)==0u&&m.r8(owner+0x135u)==0u&&m.r32(0xa255c8u)==0u,"1298 original owner flags");
 std::array<std::uint8_t,12> raw{};leaf::Memory point(raw.data(),0x7d100000u,12u);Memory view=m;view.add(point);
 Inputs h{};h.ax=0;h.cx=m.r32(m.r32(0x81a958u));h.dx=h.arg[0]=0x7d100000u;h.arithmetic_flags=0x202u;h.fp=i.fp;
 need(h.cx&&m.r8(h.cx+0x11bu)==0u&&m.r8(h.cx+0x11cu)==0u,"1298 borrowed zero height cell");
 need(map_b106::fun_004702c0(view,h)==0u,"1298 first real height");
 //51F1C0 only clears AL. Root repeats its original getter; cache7 is retained.
 h.ax=0;h.dx=h.arg[0]=0x7d100000u;h.arithmetic_flags=0x202u;
 need(map_b106::fun_004702c0(view,h)==0u,"1298 second real height");i.fp=h.fp;
 const int bx=std::int16_t(m.r16(i.arg[1])),by=std::int16_t(m.r16(i.arg[1]+2u));const int index=512*by+bx;
 need(index>=0&&index<0x40000,"1298 real table index");const auto cell=m.r32(m.r32(0x81a958u)+4u*unsigned(index));
 need(cell&&!(m.r32(cell+0x140u)&0x100u),"1298 nonnull cell,ordinary zone");
 Inputs q{};q.cx=0x81a820u;q.arg[0]=i.arg[0];q.arg[1]=i.arg[1];q.arg[2]=7u;q.fp=i.fp;
 const auto query=recovery_b110::fun_0054cc50(m,q);i.fp=q.fp;need((query&255u)==1u,"1298 equal actual region query");
 const int ax=std::int16_t(m.r16(i.arg[0])),ay=std::int16_t(m.r16(i.arg[0]+2u));
 const auto abs=[](int v){return unsigned(v<0?-v:v);};const auto dx=abs(bx-ax),dy=abs(by-ay),d=dx>dy?dx:dy;
 need(d==1u||d>=4u,"1298 finite useful distance routes");return d==1u?(d&0xffffff00u):((d&0xffffff00u)|1u);
}
}
