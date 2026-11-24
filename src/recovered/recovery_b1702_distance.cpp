#include "recovered/recovery_b1702.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1702::calls {
namespace ix=direct_b33::integer;
void distance_4ba080(Memory& m,State& s,Frame& caller,U continuation,U actual_target){
    if(actual_target!=0x4ba080u)
        throw std::domain_error("FD5F0 distance actual target outside exact4BA080 contract");
    caller.push(m,continuation); // Actual CALL pushes one return word.
    Frame f{caller.sp,caller.sp,continuation};
L4ba080: //fld qword ptr [esp+4] [dd442404]
    s.fp.load64(floating_b61::read64(m,f.sp+4u));
L4ba084: //fcom dword ptr [785738] [d81538577800]
    s.fp.compare32(m.r32(0x785738u));
L4ba08a: //fnstsw ax [dfe0]
    s.ax=(s.ax&0xffff0000u)|s.fp.status();
L4ba08c: //test ah,40 [f6c440]
    (void)ix::logical(((s.ax>>8u)&255u)&0x40u,8,s.arithmetic_flags);
L4ba08f: //je4BA09A [7409]
    if(ix::condition("JZ",s.arithmetic_flags))goto L4ba09a;
L4ba091: //fstp st(0) [ddd8]
    s.fp.pop_st0();
L4ba093: //fld dword ptr [785738] [d90538577800]
    s.fp.load32(m.r32(0x785738u));
L4ba099: //ret [c3]
    recovery_b566::finish(m,s,f,0u);caller.sp=f.sp;return;
L4ba09a: //fcom dword ptr [785738] [d81538577800]
    s.fp.compare32(m.r32(0x785738u));
L4ba0a0: //fnstsw ax [dfe0]
    s.ax=(s.ax&0xffff0000u)|s.fp.status();
L4ba0a2: //test ah,41 [f6c441]
    (void)ix::logical(((s.ax>>8u)&255u)&0x41u,8,s.arithmetic_flags);
L4ba0a5: //je4BA0AD [7406]
    if(ix::condition("JZ",s.arithmetic_flags))goto L4ba0ad;
L4ba0a7: //fmul qword ptr [788578] [dc0d78857800]
    s.fp.multiply64(floating_b61::read64(m,0x788578u));
L4ba0ad: //fstp dword ptr [esp+4] [d95c2404]
    m.w32(f.sp+4u,s.fp.pop32());
L4ba0b1: //mov ecx,[esp+4] [8b4c2404]
    s.cx=m.r32(f.sp+4u);
L4ba0b5: //mov eax,ecx [8bc1]
    s.ax=s.cx;
L4ba0b7: //and ecx,7FFFFF [81e1ffff7f00]
    s.cx=ix::logical(s.cx&0x7fffffu,32,s.arithmetic_flags);
L4ba0bd: //shr eax,17 [c1e817]
    s.ax=ix::shift(s.ax,0x17u,32,s.arithmetic_flags,ix::Shift::right);
L4ba0c0: //sub eax,7F [83e87f]
    s.ax=ix::sub(s.ax,0x7fu,32,s.arithmetic_flags);
L4ba0c3: //test al,1 [a801]
    (void)ix::logical((s.ax&255u)&1u,8,s.arithmetic_flags);
L4ba0c5: //je4BA0CD [7406]
    if(ix::condition("JZ",s.arithmetic_flags))goto L4ba0cd;
L4ba0c7: //or ecx,800000 [81c900008000]
    s.cx=ix::logical(s.cx|0x800000u,32,s.arithmetic_flags);
L4ba0cd: //sar ax,1 [66d1f8]
    s.ax=(s.ax&0xffff0000u)|ix::shift(s.ax&0xffffu,1u,16,s.arithmetic_flags,ix::Shift::arithmetic_right);
L4ba0d0: //movsx eax,ax [0fbfc0]
    s.ax=U(ix::sign_extend(s.ax,16));
L4ba0d3: //shr ecx,A [c1e90a]
    s.cx=ix::shift(s.cx,0xau,32,s.arithmetic_flags,ix::Shift::right);
L4ba0d6: //add eax,7F [83c07f]
    s.ax=ix::add(s.ax,0x7fu,32,s.arithmetic_flags);
L4ba0d9: //mov ecx,[ecx*4+80013C] [8b0c8d3c018000]
    s.cx=m.r32(0x80013cu+4u*s.cx);
L4ba0e0: //shl eax,17 [c1e017]
    s.ax=ix::shift(s.ax,0x17u,32,s.arithmetic_flags,ix::Shift::left);
L4ba0e3: //add ecx,eax [03c8]
    s.cx=ix::add(s.cx,s.ax,32,s.arithmetic_flags);
L4ba0e5: //mov [esp+4],ecx [894c2404]
    m.w32(f.sp+4u,s.cx);
L4ba0e9: //fld dword ptr [esp+4] [d9442404]
    s.fp.load32(m.r32(f.sp+4u));
L4ba0ed: //ret [c3]
    recovery_b566::finish(m,s,f,0u);caller.sp=f.sp;
}
}
