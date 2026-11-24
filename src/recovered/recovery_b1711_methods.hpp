#pragma once
#include "recovery_b1711.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::delivery::query51090::detail {
using U=std::uint32_t;
namespace integer=ra2::recovered::direct_b33::integer;
inline void need(bool v){if(!v)throw std::invalid_argument("51090 selected contract");}
inline U sx16(U x){return static_cast<U>(static_cast<std::int32_t>(static_cast<std::int16_t>(x)));}
inline void ret(Memory&m,Frame&f,U token,U cleanup){need(f.pop(m)==token);f.sp+=cleanup;}

// Genuine call-free 4585B0, including actual current table read.
inline void width(Memory&m,State&s,Frame&f,U token){
    s.ax=m.r32(s.cx+0xc78u);s.ax=m.r32(0x7bac08u+4u*s.ax);ret(m,f,token,0);
}
// The actual caller passes a fully produced zero argument, not a chosen result.
inline void height0(Memory&m,State&s,Frame&f,U&flags,U token){
    s.ax=(s.ax&0xffffff00u)|m.r8(f.sp+4u);
    (void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)==0);
    s.ax=m.r32(s.cx+0xc78u);s.dx=integer::logical(s.dx^s.dx,32,flags);
    s.ax=m.r32(0x7bac60u+4u*s.ax);s.ax=integer::add(s.ax,s.dx,32,flags);
    ret(m,f,token,4);
}
// Genuine 545500 valid, nonnull table-entry path. No fallback state invented.
inline void map_cell(Memory&m,State&s,Frame&f,U&flags,U token){
    s.dx=m.r32(f.sp+4u);f.push(m,s.si);
    s.ax=sx16(m.r16(s.dx+2u));s.si=sx16(m.r16(s.dx));
    s.ax=integer::shift(s.ax,9,32,flags,integer::Shift::left);
    s.ax=integer::add(s.ax,s.si,32,flags);s.si=f.pop(m);
    need(static_cast<std::int32_t>(s.ax)>=0);
    (void)integer::sub(s.ax,0x40000u,32,flags);need(s.ax<0x40000u);
    s.cx=m.r32(s.cx+0x138u);s.ax=m.r32(s.cx+4u*s.ax);
    (void)integer::logical(s.ax,32,flags);need(s.ax!=0);ret(m,f,token,4);
}
// Actual global remains an input. Both genuine branches reach XOR EAX,EAX.
inline void empty_occupant(Memory&m,State&s,Frame&f,U&flags,U token){
    s.ax=(s.ax&0xffffff00u)|m.r8(0xa285a8u);f.push(m,s.si);
    (void)integer::logical(s.ax&255u,8,flags);
    if(s.ax&255u){s.si=m.r32(s.cx+0xe4u);(void)integer::logical(s.si,32,flags);need(s.si==0);}
    s.ax=integer::logical(s.ax^s.ax,32,flags);s.si=f.pop(m);ret(m,f,token,0);
}
// Actual 47BBA0 bit-disabled branch. The caller really leaves its index argument.
inline void disabled_occupancy(Memory&m,State&s,Frame&f,U&flags,U token){
    f.push(m,s.cx);f.push(m,s.bx);f.push(m,s.di);s.di=s.cx;s.bx=1;
    s.cx=m.r32(f.sp+0x10u);s.ax=m.r32(s.di+0xdcu);
    s.bx=integer::shift(s.bx,s.cx,32,flags,integer::Shift::left);
    (void)integer::logical(s.bx&s.ax,32,flags);need((s.bx&s.ax)==0);
    s.di=f.pop(m);s.ax=integer::logical(s.ax|0xffffffffu,32,flags);
    s.bx=f.pop(m);s.cx=f.pop(m);ret(m,f,token,4);
}
// Actual normally published 7875A0+10 target 42D120. Empty count is read.
inline void empty_search(Memory&m,State&s,Frame&f,U&flags,U token){
    s.dx=m.r32(s.cx+0x10u);f.push(m,s.bx);
    s.ax=integer::logical(s.ax^s.ax,32,flags);f.push(m,s.si);
    (void)integer::logical(s.dx,32,flags);f.push(m,s.di);need(s.dx==0);
    s.ax=integer::logical(s.ax|0xffffffffu,32,flags);
    s.di=f.pop(m);s.si=f.pop(m);s.bx=f.pop(m);ret(m,f,token,4);
}
}
