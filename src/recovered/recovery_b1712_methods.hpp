#pragma once
// PRIVATE PROVISIONAL (not promoted, no batch allocated): finite VoxelAnimClass placement route of 0x5CBF20.
// Domain D1: [A285A8]!=0, obj+0x76!=0, obj+0x74==0, [A283C4]!=0, obj+0x7D==0, vptr 7992B8, type null or vptr 7994D0.
#include "recovered/recovery_b1711_methods.hpp"
namespace ra2::delivery::placement1cbf20 {
using namespace ra2::delivery::query51090;
using namespace ra2::delivery::query51090::detail;
// Entry: ECX=object, [SP]=outer return, [SP+4]=coordinate pointer, [SP+8]=unused here. RET 8. Returns final flags.
inline U root(Memory&m,State&s,Frame&f,U flags){
    s.ax=(s.ax&~255u)|m.r8(0xa285a8u);f.sp=integer::sub(f.sp,0x2cu,32,flags);
    (void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)!=0);
    f.push(m,s.bx);f.push(m,s.bp);f.push(m,s.si);f.push(m,s.di);s.si=s.cx;
    s.ax=(s.ax&~255u)|m.r8(s.si+0x76u);(void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)!=0);
    s.ax=(s.ax&~255u)|m.r8(s.si+0x74u);(void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)==0);
    s.ax=m.r32(0xa283c4u);s.di=m.r32(f.sp+0x40u);(void)integer::logical(s.ax,32,flags);need(s.ax!=0);
    s.ax=m.r32(s.si);s.cx=s.si;m.w8(s.si+0x76u,0);m.w8(s.si+0x75u,0);
    need(m.r32(s.si)==0x7992b8u&&m.r32(s.ax+0x84u)==0x702b30u);f.push(m,0x5cbf91u);
    s.ax=m.r32(s.cx+0xecu);ret(m,f,0x5cbf91u,0);                       // 702B30
    s.cx=s.di;s.bx=s.ax;(void)integer::logical(s.bx&s.bx,32,flags);
    s.dx=m.r32(s.cx);m.w32(f.sp+0x18u,s.dx);s.ax=m.r32(s.cx+4u);m.w32(f.sp+0x1cu,s.ax);
    s.cx=m.r32(s.cx+8u);m.w32(f.sp+0x20u,s.cx);
    if(s.bx!=0){
        s.dx=m.r32(s.bx);s.ax=f.sp+0x24u;f.push(m,s.di);f.push(m,s.ax);s.cx=s.bx;
        need(m.r32(s.bx)==0x7994d0u&&m.r32(s.dx+0x6cu)==0x41c2e0u);f.push(m,0x5cbfbau);
        s.cx=m.r32(f.sp+8u);s.ax=m.r32(f.sp+4u);f.push(m,s.si);s.dx=s.ax;                // 41C2E0
        s.si=m.r32(s.cx);m.w32(s.dx,s.si);s.si=m.r32(s.cx+4u);m.w32(s.dx+4u,s.si);
        s.si=f.pop(m);s.cx=m.r32(s.cx+8u);m.w32(s.dx+8u,s.cx);ret(m,f,0x5cbfbau,8);
        s.cx=m.r32(s.ax);m.w32(f.sp+0x18u,s.cx);s.dx=m.r32(s.ax+4u);m.w32(f.sp+0x1cu,s.dx);
        s.ax=m.r32(s.ax+8u);m.w32(f.sp+0x20u,s.ax);
    }
    s.dx=m.r32(s.si);s.ax=f.sp+0x18u;f.push(m,s.ax);s.cx=s.si;
    need(m.r32(s.dx+0x19cu)==0x5cd850u);f.push(m,0x5cbfddu);
    s.ax=m.r32(f.sp+4u);s.cx=integer::add(s.cx,0x88u,32,flags);s.dx=m.r32(s.ax);m.w32(s.cx,s.dx);   // 5CD850
    s.dx=m.r32(s.ax+4u);m.w32(s.cx+4u,s.dx);s.ax=m.r32(s.ax+8u);m.w32(s.cx+8u,s.ax);ret(m,f,0x5cbfddu,4);
    s.dx=m.r32(s.si);f.push(m,1u);s.cx=s.si;need(m.r32(s.dx+0x11cu)==0x5cc7f0u);f.push(m,0x5cbfe9u);
    // 5CC7F0 operation 1 (new contract: byte76==0, byte74==0, VoxelAnim type id 0x29 -> 40DC20 null)
    f.push(m,s.bx);f.push(m,s.si);s.si=s.cx;s.ax=(s.ax&~255u)|m.r8(s.si+0x76u);
    (void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)==0);
    s.bx=m.r32(f.sp+0xcu);(void)integer::sub(s.bx,2u,32,flags);need(s.bx==1u);
    s.dx=m.r32(s.si);f.push(m,s.di);s.cx=s.si;need(m.r32(s.dx+0x2cu)==0x702b20u);f.push(m,0x5cc835u);
    s.ax=0x29u;ret(m,f,0x5cc835u,0);                                      // 702B20
    (void)integer::sub(s.ax,6u,32,flags);need(s.ax!=6u);
    s.cx=s.si;f.push(m,0x5cc855u);
    f.push(m,s.si);s.si=s.cx;(void)integer::logical(s.si&s.si,32,flags);need(s.si!=0);               // 40DC20
    s.ax=m.r32(s.si);need(m.r32(s.ax+0x2cu)==0x702b20u);f.push(m,0x40dc2cu);s.ax=0x29u;ret(m,f,0x40dc2cu,0);
    s.ax=integer::decrement(s.ax,32,flags);(void)integer::sub(s.ax,0xeu,32,flags);need(s.ax>0xeu);
    s.ax=integer::logical(s.ax^s.ax,32,flags);s.si=f.pop(m);ret(m,f,0x5cc855u,0);
    s.di=s.ax;(void)integer::logical(s.di&s.di,32,flags);need(s.di==0);
    (void)integer::sub(s.bx,1u,32,flags);s.di=f.pop(m);need(s.bx==1u);
    s.ax=(s.ax&~255u)|m.r8(s.si+0x74u);(void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)==0);
    s.dx=m.r32(s.si);s.cx=s.si;m.w8(s.si+0x74u,1);need(m.r32(s.dx+0x12cu)==0x5cbd70u);f.push(m,0x5cc89bu);
    s.ax=(s.ax&~255u)|m.r8(s.cx+0x75u);(void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)==0);  // 5CBD70
    m.w8(s.cx+0x75u,1);f.push(m,0u);s.cx=0x81a820u;f.push(m,0x5cbd87u);
    s.ax=m.r32(0x821cacu);(void)integer::logical(s.ax,32,flags);if(s.ax!=0)m.w8(s.ax+0xd7du,1);      // 4E0030(0)
    s.ax=m.r32(f.sp+4u);(void)integer::logical(s.ax,32,flags);need(s.ax==0);ret(m,f,0x5cbd87u,4);
    ret(m,f,0x5cc89bu,0);
    s.si=f.pop(m);s.ax=(s.ax&~255u)|1u;s.bx=f.pop(m);ret(m,f,0x5cbfe9u,4);
    (void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)!=0);
    s.ax=(s.ax&~255u)|m.r8(s.si+0x7du);(void)integer::logical(s.ax&255u,8,flags);need((s.ax&255u)==0);
    s.ax=(s.ax&~255u)|1u;s.di=f.pop(m);s.si=f.pop(m);s.bp=f.pop(m);s.bx=f.pop(m);
    f.sp=integer::add(f.sp,0x2cu,32,flags);need(f.pop(m)==f.outer_return);f.sp+=8u;
    return flags;
}
}
