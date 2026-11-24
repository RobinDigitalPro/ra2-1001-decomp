#include "recovered/recovery_b1696.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b1696 {
namespace {
void need(bool v){if(!v)throw std::domain_error("150E40 finite flag180 case4 joint domain");}
struct Range{U base,size;};
void valid(Range r){need(r.base&&r.size&&std::uint64_t(r.base)+r.size<=0x100000000ull);}
void separate(Range a,Range b){valid(a);valid(b);need(std::uint64_t(a.base)+a.size<=b.base||std::uint64_t(b.base)+b.size<=a.base);}
constexpr U packed(U x,U y){return x|(y<<16u);}
constexpr std::array<std::array<int,2>,8> offsets{{{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}}};
U cell(Memory&m,U table,U x,U y){return m.r32(table+(y*512u+x)*4u);}
}

Projection preflight(Memory&m,const Inputs&i){
 Projection p{};p.P=i.arg[0];p.caller=i.arg;
 need(i.cx==0x81a820u&&p.P&&m.r32(p.P)==packed(60u,64u));
 need(ra2::platform::x87::same_numeric(i.fp.image,ra2::platform::x87::Image::empty(0x037fu)));
 p.map=m.r32(0x81a958u);valid({p.map,0x100000u});
 p.C=cell(m,p.map,60u,64u);p.A=cell(m,p.map,60u,65u);p.B=cell(m,p.map,60u,63u);
 for(U n=0;n<8u;++n){
  need(m.r16(0x839da0u+4u*n)==U(std::uint16_t(offsets[n][0]))&&m.r16(0x839da2u+4u*n)==U(std::uint16_t(offsets[n][1])));
  const U x=U(60+offsets[n][0]),y=U(63+offsets[n][1]);
  p.neighbors[n]=cell(m,p.map,x,y);valid({p.neighbors[n],0x144u});
  need(m.r32(p.neighbors[n]+0x24u)==packed(x,y)&&m.r32(p.neighbors[n]+0x38u)==n+1u);
 }
 p.N7=p.neighbors[7];need(p.C==p.neighbors[4]);
 valid({p.A,0x144u});valid({p.B,0x144u});
 std::array<Range,10> cells{};cells[0]={p.B,0x144u};cells[1]={p.A,0x144u};
 for(U n=0;n<8u;++n)cells[n+2u]={p.neighbors[n],0x144u};
 for(U a=0;a<cells.size();++a){separate(cells[a],{p.P,4u});separate(cells[a],{p.map,0x100000u});for(U b=0;b<a;++b)separate(cells[a],cells[b]);}
 need(m.r32(p.C+0x24u)==packed(60u,64u)&&m.r32(p.C+0x38u)==5u&&m.r32(p.C+0x140u)==0x180u);
 p.initial_kind=m.r8(p.C+0x11eu);need(p.initial_kind>=9u&&p.initial_kind<=14u);
 need(m.r32(p.A+0x24u)==packed(60u,65u)&&m.r32(p.A+0x38u)==22u&&m.r32(p.A+0x140u)==0x80u&&m.r8(p.A+0x11eu)==13u);
 need(m.r32(p.B+0x24u)==packed(60u,63u)&&m.r32(p.B+0x38u)==0u&&m.r32(p.B+0x140u)==0x80u&&m.r8(p.B+0x11eu)==9u&&m.r8(p.B+0x11au)==0u&&m.r8(p.B+0x11bu)==0u);
 need(m.r32(0xa547a0u)==0u&&m.r32(0xa55c48u)==0u&&m.r32(0xa3afc8u)==0u&&m.r32(0xa3aab0u)==2u&&m.r32(0xa3afccu)==1u&&m.r32(0xa3a1c0u)==2u);
 const U table=m.r32(0xa28914u),object=m.r32(table),q=m.r32(object+0xa4u),row=m.r32(q+0x10u);
 need(table&&object&&q&&row&&m.r32(object)==0x790188u&&m.r32(0x790224u)==0x527630u);
 need(m.r32(q)==1u&&m.r32(q+4u)==1u&&(m.r32(row+0x24u)&4u));
 const U manager=m.r32(0x821cacu),record=m.r32(0xaa60bcu),queue=m.r32(0x81ba44u);
 need(manager&&record&&queue&&m.r32(manager+0xb0u)==0u&&m.r32(manager+0xb4u)==0u);
 need(m.r32(0xaa60c0u)==1u&&m.r32(0xaa60c8u)==0u&&m.r32(0x81ba48u)==1u&&m.r32(0x81ba50u)==0u&&m.r8(0x81bcf5u)==0u);
 need(floating_b61::read64(m,0xaa5f90u)==0x3fe0000000000000ull&&floating_b61::read64(m,0x785728u)==0x3fe0000000000000ull&&m.r32(0x7c3a04u)==0x0e7fu);
 const std::array<Range,6> provider{{{table,4u},{object,0xa8u},{q,0x14u},{row,0x28u},{manager,0xb8u},{record,20u}}};
 for(U a=0;a<provider.size();++a){separate(provider[a],{p.P,4u});separate(provider[a],{p.map,0x100000u});separate(provider[a],{queue,4u});for(const auto&r:cells)separate(provider[a],r);for(U b=0;b<a;++b)separate(provider[a],provider[b]);}
 separate({queue,4u},{p.P,4u});separate({queue,4u},{p.map,0x100000u});for(const auto&r:cells)separate({queue,4u},r);
 // Numeric span collision proof only. No private bytes are seeded or read.
 std::array<std::uint8_t,8> raw_points;
 std::array<std::uint8_t,4> raw_pair;std::array<std::uint8_t,24> raw_nested;
 leaf::Memory points(raw_points.data(),private_points,8u),pair(raw_pair.data(),0x7e210000u,4u),nested(raw_nested.data(),0x7e200000u,24u);
 Memory check=m;check.add(points);check.add(pair);check.add(nested);
 return p;
}

U run(Memory&m,const Inputs&i,const Projection&p,Trace* trace){
 need(i.cx==0x81a820u&&i.arg==p.caller&&i.arg[0]==p.P);
 need(m.r32(0x81a958u)==p.map&&cell(m,p.map,60u,64u)==p.C&&m.r32(p.C+0x140u)==0x180u&&m.r8(p.C+0x11eu)==p.initial_kind);
 Trace local_trace{};Trace&t=trace?*trace:local_trace;t={};t.logical_ebp=p.P;
 t.private_coord1=private_points;t.private_coord2=private_points+4u;
 std::array<std::uint8_t,8> raw_points; // Fully Root-produced before either read.
 leaf::Memory points(raw_points.data(),private_points,8u);
 Memory local=m;local.add(points); // SAME public backings; private view not published.
 // 550E54..550E70/550E84..550EAD/550F17/55199B..5519C9:
 // preflight binds the real selected nonfallback cell, flags and case4 table.
 // 551AA6..551ABC: actual C+24 copy, kind15 store, B161 direction4.
 t.value1=m.r32(p.C+0x24u);points.w32(private_points,t.value1);
 m.w8(p.C+0x11eu,15u);
 Inputs first=i;first.ax=t.value1;first.cx=i.cx;first.dx=4u;
 first.arg[0]=private_points;first.arg[1]=4u;first.stack_minus8=p.P;
 ++t.first_calls;t.first_eax=recovery_b161::fun_0054f040(local,first);
 i.fp=first.fp; // Entire actual FP image, no reset or expected-output publication.
 // 551AC1..551AD6: genuine C+24 reread, distinct second private point, dir0.
 t.value2=m.r32(p.C+0x24u);points.w32(private_points+4u,t.value2);
 Inputs second=i;second.ax=private_points+4u;second.cx=i.cx;second.dx=t.value2;
 second.arg[0]=private_points+4u;second.arg[1]=0u;second.stack_minus8=p.P;
 ++t.second_calls;t.second_eax=recovery_b642::fun_0054f150(local,second);
 i.fp=second.fp;
 need(i.arg==p.caller);
 // 551ADB..551AE4: XOR AL,AL preserves the actual helper's upper24 EAX.
 // Physical EFLAGS/nonvolatiles/RET4 are not modeled as a fabricated constant.
 return floating_b61::with_al(t.second_eax,0u);
}
}
