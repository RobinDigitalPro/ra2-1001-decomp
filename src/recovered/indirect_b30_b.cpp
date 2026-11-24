#include "recovered/indirect_b30_memory.hpp"

namespace ra2::recovered::indirect_b30 {
namespace {
std::uint32_t arg(const Memory& m, const Frame& f, unsigned i) {
    return m.r32(f.entry_sp + 4u + 4u * i);
}
void absolute_call(Memory& m, State& s, Frame& f, const Operations& o, std::uint32_t slot) {
    invoke(m, s, f, o, m.r32(slot));
}
void vtable_call(Memory& m, State& s, Frame& f, const Operations& o,
                 std::uint32_t table, std::uint32_t offset) {
    invoke(m, s, f, o, m.r32(table + offset));
}
}

void fun_005da4c0(Memory&m,State&s,Frame&f,const Operations&o){
    s.dx &= 0xffu; f.push(m,s.dx); f.push(m,0); f.push(m,0x4e5); f.push(m,s.cx);
    absolute_call(m,s,f,o,0x007854a0u); finish(m,s,f,0);
}
void fun_005da4e0(Memory&m,State&s,Frame&f,const Operations&o){
    s.dx &= 0xffu; f.push(m,s.dx); f.push(m,0); f.push(m,0x4e6); f.push(m,s.cx);
    absolute_call(m,s,f,o,0x007854a0u); finish(m,s,f,0);
}
void fun_005e0a50(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,0); f.push(m,0x005e0a10u); f.push(m,s.cx);
    absolute_call(m,s,f,o,0x007854dcu); finish(m,s,f,0);
}
void mask_helper(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); s.si=s.cx;
    s.cx=m.r32(f.sp+8u);
    invoke(m,s,f,o,m.r32(s.si+0x18u));
    s.cx=m.r32(s.si+0xcu); s.dx=s.ax;
    s.ax=1u << (s.cx & 31u); s.ax-=1u; s.ax &= s.dx;
    s.si=f.pop(m); finish(m,s,f,4);
}
void fun_005f98e0(Memory&m,State&s,Frame&f,const Operations&o){mask_helper(m,s,f,o);}
void fun_005f9cd0(Memory&m,State&s,Frame&f,const Operations&o){mask_helper(m,s,f,o);}
void fun_00753a40(Memory&m,State&s,Frame&f,const Operations&o){mask_helper(m,s,f,o);}
void fun_00753e10(Memory&m,State&s,Frame&f,const Operations&o){mask_helper(m,s,f,o);}
void fun_0061ae90(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); s.si=s.cx; absolute_call(m,s,f,o,0x00785524u);
    s.cx=s.si+s.si*2u; s.si=f.pop(m); m.w32(0x00a93944u+s.cx*8u,s.ax); finish(m,s,f,0);
}
void fun_0068fad0(Memory&m,State&s,Frame&f,const Operations&o){
    absolute_call(m,s,f,o,0x00785524u); s.ax >>= 4; finish(m,s,f,0);
}
void fun_00696df0(Memory&m,State&s,Frame&f,const Operations&o){
    s.ax=m.r32(s.cx); f.push(m,0); m.w8(s.cx+0x4f15u,1);
    invoke(m,s,f,o,m.r32(s.ax+0x38u)); finish(m,s,f,0);
}
void fun_006c94f0(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.cx); s.ax=m.r32(s.cx); s.dx=f.sp; f.push(m,s.dx);
    invoke(m,s,f,o,m.r32(s.ax+0x288u));
    s.cx=m.r32(s.ax); s.ax=arg(m,f,0); m.w32(s.ax,s.cx);
    s.cx=f.pop(m); finish(m,s,f,4);
}
void fun_006cd940(Memory&m,State&s,Frame&f,const Operations&o){
    s.ax=m.r32(s.cx); invoke(m,s,f,o,m.r32(s.ax+0x80u));
    s.ax=with_al(s.ax,m.r8(s.ax+0x702u)); finish(m,s,f,0);
}
void fun_00719b80(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); s.si=s.cx; s.ax=m.r32(s.si+0x28u); s.cx=s.si+0x28u;
    invoke(m,s,f,o,m.r32(s.ax+0xcu)); m.w32(s.si+0x24u,0xffffffffu);
    s.si=f.pop(m); finish(m,s,f,0);
}
void fun_0074a9c0(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); s.si=s.cx; s.ax=s.si+8u; m.w32(s.si+4u,0); f.push(m,s.ax);
    absolute_call(m,s,f,o,0x007851e8u); m.w32(s.si,0x0079a6c4u); s.ax=s.si;
    s.si=f.pop(m); finish(m,s,f,0);
}
void fun_0074b760(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); s.si=s.cx; s.ax=s.si+8u; m.w32(s.si+4u,0); f.push(m,s.ax);
    absolute_call(m,s,f,o,0x007851e8u); m.w32(s.si,0x0079a6ecu); s.ax=s.si;
    s.si=f.pop(m); finish(m,s,f,0);
}
void fun_00761dc0(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); f.push(m,0); s.si=s.cx; f.push(m,0); f.push(m,4); f.push(m,s.si);
    vtable_call(m,s,f,o,s.si,0x58u); s.ax=m.r32(s.si+0x7bcu); f.sp+=0x10u;
    s.ax|=0x40u; m.w32(s.si+0x7bcu,s.ax); s.si=f.pop(m); finish(m,s,f,0);
}
void fun_00761de0(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); f.push(m,0); s.si=s.cx; f.push(m,0); f.push(m,6); f.push(m,s.si);
    vtable_call(m,s,f,o,s.si,0x58u); s.ax=m.r32(s.si+0x7bcu); f.sp+=0x10u;
    s.ax=(s.ax&0xffffff00u)|((s.ax&0xffu)&0xbfu); m.w32(s.si+0x7bcu,s.ax);
    s.si=f.pop(m); finish(m,s,f,0);
}
void fun_00761e00(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.si); f.push(m,0); s.si=s.cx; f.push(m,0); f.push(m,7); f.push(m,s.si);
    vtable_call(m,s,f,o,s.si,0x58u); s.ax=m.r32(s.si+0x7bcu); f.sp+=0x10u;
    s.ax=(s.ax&0xffffff00u)|((s.ax&0xffu)&0xbfu); m.w32(s.si+0x7bcu,s.ax);
    s.si=f.pop(m); finish(m,s,f,0);
}
void fun_00765c80(Memory&m,State&s,Frame&f,const Operations&o){
    s.dx+=1u; s.ax=s.cx+0x112u; s.dx &= 0xfffffffeu;
    f.push(m,s.dx); f.push(m,s.ax); f.push(m,5); f.push(m,s.cx);
    vtable_call(m,s,f,o,s.cx,0x40u); f.sp+=0x10u;
    const std::uint32_t carry=(s.ax!=0u)?1u:0u; s.ax=0u-carry;
    s.ax=(s.ax&0xffffff00u)|((s.ax&0xffu)&0xfdu); s.ax-=1u; finish(m,s,f,0);
}
void fun_00771617(Memory&m,State&s,Frame&f,const Operations&o){
    f.push(m,s.bp); s.bp=f.sp; s.ax=m.r32(s.bp+8u); f.push(m,m.r32(0x00817278u+s.ax*4u));
    absolute_call(m,s,f,o,0x007851e0u); s.bp=f.pop(m); finish(m,s,f,0);
}
void fun_0077b39a(Memory&m,State&s,Frame&f,const Operations&o){
    m.w16(0x00b10708u,m.r16(0x00b10708u)|0x104u); absolute_call(m,s,f,o,0x0078530cu);
    m.w32(0x00b1070cu,s.ax); m.w32(0x00b106f0u,s.ax); finish(m,s,f,0);
}
void fun_00782c41(Memory&m,State&s,Frame&f,const Operations&o){
    s.ax=0; f.push(m,s.ax);f.push(m,s.ax);f.push(m,3);f.push(m,s.ax);f.push(m,3);f.push(m,0xc0000000u);f.push(m,0x0079d4dcu);
    absolute_call(m,s,f,o,0x007851b0u);m.w32(0x00818de0u,s.ax);finish(m,s,f,0);
}
void fun_00782c60(Memory&m,State&s,Frame&f,const Operations&o){
    s.ax=0; f.push(m,s.ax);f.push(m,s.ax);f.push(m,3);f.push(m,s.ax);f.push(m,3);f.push(m,0x40000000u);f.push(m,0x0079d4e4u);
    absolute_call(m,s,f,o,0x007851b0u);m.w32(0x00818de4u,s.ax);finish(m,s,f,0);
}

const std::array<Entry,23>& entries_b(){
    static constexpr std::array<Entry,23> e{{
      {0x1da4c0,fun_005da4c0},{0x1da4e0,fun_005da4e0},{0x1e0a50,fun_005e0a50},
      {0x1f98e0,fun_005f98e0},{0x1f9cd0,fun_005f9cd0},{0x21ae90,fun_0061ae90},
      {0x28fad0,fun_0068fad0},{0x296df0,fun_00696df0},{0x2c94f0,fun_006c94f0},
      {0x2cd940,fun_006cd940},{0x319b80,fun_00719b80},{0x34a9c0,fun_0074a9c0},
      {0x34b760,fun_0074b760},{0x353a40,fun_00753a40},{0x353e10,fun_00753e10},
      {0x361dc0,fun_00761dc0},{0x361de0,fun_00761de0},{0x361e00,fun_00761e00},
      {0x365c80,fun_00765c80},{0x371617,fun_00771617},{0x37b39a,fun_0077b39a},
      {0x382c41,fun_00782c41},{0x382c60,fun_00782c60}}}; return e;
}
} // namespace ra2::recovered::indirect_b30
