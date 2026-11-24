#include "recovery_b1710.hpp"
#include "recovered/recovery_b705_machine.hpp"
#include <cstring>
#include <stdexcept>
namespace ra2::delivery::query2ccac0 {
namespace old=ra2::recovered::recovery_b705;
using old::finish;using old::reverse_divide32;using old::reverse_divide64;
using old::string_instruction;using old::Kind;using old::Repeat;
using namespace ra2::recovered::floating_b61;
namespace floating_b61=ra2::recovered::floating_b61;
namespace integer=ra2::recovered::direct_b33::integer;
namespace numeric_b88=ra2::recovered::numeric_b88;
namespace {void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
void span(unsigned p,unsigned n){need(p&&std::uint64_t(p)+n<=0x100000000ull,"query live nonwrapping used span");}}
#include "recovery_b1710_methods.inc"
void invoke_candidate(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
 case 0x5ccbd0u:f_001ccbd0(m,s,child,op);break;
 case 0x4ba080u:f_000ba080(m,s,child,op);break;
 case 0x76aa50u:f_0036aa50(m,s,child,op);break;
 case 0x6b69d0u:f_002b69d0(m,s,child,op);break;
 case 0x6b6910u:f_002b6910(m,s,child,op);break;
 case 0x4538b0u:f_000538b0(m,s,child,op);break;
 case 0x6d4bf0u:f_002d4bf0(m,s,child,op);break;
 case 0x44d670u:f_0004d670(m,s,child,op);break;
 case 0x6d4b30u:f_002d4b30(m,s,child,op);break;
 case 0x453890u:f_00053890(m,s,child,op);break;
 case 0x443e10u:f_00043e10(m,s,child,op);break;
 case 0x4585b0u:f_000585b0(m,s,child,op);break;
 case 0x4585c0u:f_000585c0(m,s,child,op);break;
 default:throw std::domain_error("query unresolved authentic target; fail closed");
 }
 f.sp=child.sp;
}
Result run(Memory&m,unsigned entry,unsigned char*storage,unsigned size,const NativeState&in,const fp::Image&incoming){
 need(storage&&size==500&&entry>=0x1b0u&&!(entry&3u)&&std::uint64_t(entry)+68u<=0x100000000ull&&std::uint64_t(reinterpret_cast<std::uintptr_t>(storage))+0x1b0u==entry,"query actual aligned500B [R-1B0,R+44) storage");
 need(!(in.flags&0x400u),"query DF0");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool cw=false;for(auto c:controls)cw|=incoming.word(0)==c;
 need(cw&&incoming.word(8)==0xffff&&(incoming.word(4)&~0x3800u)==0,"query finite12CW/eightTOP/emptytags");for(unsigned k=28;k<108;++k)need(incoming.bytes[k]==static_cast<unsigned char>(k*7+11),"query fixedopaque80 input");
 std::array<unsigned,16>before{};unsigned ret;std::memcpy(before.data(),storage+0x1b4,64);std::memcpy(&ret,storage+0x1b0,4);need(m.r32(entry)==ret,"query preregistered entry");for(unsigned k=0;k<16;++k)need(m.r32(entry+4+4*k)==before[k],"query preregistered caller16");
 const unsigned self=in.cx,target=before[0],point=before[1];span(self,0x5c7);span(target,0x5c7);span(point,12);
 need(m.r32(self)==0x787bbc&&m.r32(target)==0x787bbc,"query actual normal Building addresspoints");
 const unsigned st=m.r32(self+0x418),tt=m.r32(target+0x418);span(st,0xc7c);span(tt,0xc7c);
 need(m.r32(st)==0x7881f8&&m.r32(tt)==0x7881f8&&m.r32(st+0x704)==1&&m.r32(tt+0x704)==1,"query borrowed actual Type roles");
 unsigned sw=0,tw=0;
 for(unsigned side=0;side<2;++side){const unsigned obj=side?target:self;need(m.r32(obj+0x10c)==0&&m.r8(obj+0x5c6)==1,"query finite selectedindex/alternate count");const unsigned alternate=m.r32(obj+0x4c0);span(alternate,0x750);const unsigned weapon=m.r32(alternate+0x74c);span(weapon,0xb8);need(m.r32(weapon+0xac)==0,"query optional modifier guard");if(side)tw=weapon;else sw=weapon;}
 (void)tw;need(m.r32(sw+0xb4)==1024,"query actual weapon range input");
 const unsigned owner=m.r32(self+0x1b4);span(owner,0x54f4);need(m.r8(owner+0x143)==1&&m.r32(owner+0x54f0)==0xffffffffu,"query selected owner fields");
 for(unsigned off=0x298;off<=0x2b8;off+=8)need(m.r32(st+off)==0&&m.r32(st+off+4)==0x3ff00000,"query literal five weights");
 need(m.r32(tt+0x290)==0&&m.r32(tt+0x294)==0x3ff00000&&m.r32(tt+0xa0)==100&&m.r32(tt+0xc78)==0&&m.r32(target+0x6c)==50,"query target ratio/type scalar");
 need(m.r32(target+0x88)==200&&m.r32(target+0x8c)==300&&m.r32(target+0x90)==400,"query targetXYZ");need(m.r32(point)==456&&m.r32(point+4)==300&&m.r32(point+8)==400&&m.r32(0xaa7c90)!=456,"query explicitpoint/directdistancebranch");
 constexpr unsigned slots[][2]={{0x80,0x6b6910},{0x84,0x4538b0},{0x2b8,0x6b69d0},{0x39c,0x44d670},{0x2c,0x453890},{0x48,0x443e10}};for(const auto&v:slots)need(m.r32(0x787bbc+v[0])==v[1],"query authentic Building targets");
 need(m.r32(0x7bac08)==1&&m.r32(0x7bac60)==1,"query actual1x1 footprint table");
 need(m.r32(0x7c3a04)==0xe7f&&m.r32(0x80013c)==0,"query cachedFTOL/tableapproximation input");need(m.r32(0x797ee0)==0&&m.r32(0x797ee4)==0x40f86a00,"query authentic100000double");
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=in.bx;s.bp=in.bp;s.si=in.si;s.di=in.di;s.arithmetic_flags=in.flags;s.fp.image=incoming;Frame f{entry,entry,ret};const Operations op{};f_002ccac0(m,s,f,op);
 need(f.sp==entry+12u&&s.ax==252&&s.cx==252&&s.dx==0,"query exact RET8/volatile results");need(s.bx==in.bx&&s.bp==in.bp&&s.si==in.si&&s.di==in.di&&!(s.arithmetic_flags&0x400u),"query nonvolatiles/DF");need((s.arithmetic_flags&0x8c5u)==4,"query final AND defined flags;AF unclaimed");
 Result result{s.ax,s,{}};std::memcpy(result.words.data(),storage+0x1b4,64);need(result.words==before,"query actual caller16 poststate");return result;
}
}
