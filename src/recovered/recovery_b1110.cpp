#include "recovered/recovery_b1110_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1110 {
namespace {
void f_00378aa5(Memory&,State&,Frame&,const Operations&);
void f_00378d91(Memory&,State&,Frame&,const Operations&);
void f_00378d44(Memory&,State&,Frame&,const Operations&);
void f_00378f95(Memory&,State&,Frame&,const Operations&);
void f_00378fb8(Memory&,State&,Frame&,const Operations&);
void f_0037524e(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);



void f_00378aa5(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778aa5: { // 0x778aa5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00778aa6: { // 0x778aa6: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L00778aa8: { // 0x778aa8: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00778aab: { // 0x778aab: 8b4508 MOV EAX, dword ptr [EBP + 8]
    s.ax = m.r32((s.bp+8u));
  }
  L00778aae: { // 0x778aae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00778aaf: { // 0x778aaf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00778ab0: { // 0x778ab0: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00778ab2: { // 0x778ab2: 83e71f AND EDI, 0x1f
    s.di = integer::logical((s.di)&(0x0000001fu),32,flags);
  }
  L00778ab5: { // 0x778ab5: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00778ab7: { // 0x778ab7: a808 TEST AL, 8
    (void)integer::logical(((s.ax & 0xffu))&(8u),8,flags);
  }
  L00778ab9: { // 0x778ab9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00778aba: { // 0x778aba: 7414 JZ 0x778ad0
    if(integer::condition("JZ",flags)) goto L00778ad0;
  }
  L00778abc: { // 0x778abc: 845d10 TEST byte ptr [EBP + 0x10], BL
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&((s.bx & 0xffu)),8,flags);
  }
  L00778abf: { // 0x778abf: 740f JZ 0x778ad0
    if(integer::condition("JZ",flags)) goto L00778ad0;
  }
  L00778ac1: { // 0x778ac1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00778ac2: { // 0x778ac2: e8f1040000 CALL 0x778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834311u); flags=s.arithmetic_flags;
  }
  L00778ac7: { // 0x778ac7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778ac8: { // 0x778ac8: 83e7f7 AND EDI, 0xfffffff7
    s.di = integer::logical((s.di)&(0xfffffff7u),32,flags);
  }
  L00778acb: { // 0x778acb: e9ca010000 JMP 0x778c9a
    goto L00778c9a;
  }
  L00778ad0: { // 0x778ad0: a804 TEST AL, 4
    (void)integer::logical(((s.ax & 0xffu))&(4u),8,flags);
  }
  L00778ad2: { // 0x778ad2: 7416 JZ 0x778aea
    if(integer::condition("JZ",flags)) goto L00778aea;
  }
  L00778ad4: { // 0x778ad4: f6451004 TEST byte ptr [EBP + 0x10], 4
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(4u),8,flags);
  }
  L00778ad8: { // 0x778ad8: 7410 JZ 0x778aea
    if(integer::condition("JZ",flags)) goto L00778aea;
  }
  L00778ada: { // 0x778ada: 6a04 PUSH 4
    f.push(m,4u);
  }
  L00778adc: { // 0x778adc: e8d7040000 CALL 0x778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834337u); flags=s.arithmetic_flags;
  }
  L00778ae1: { // 0x778ae1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778ae2: { // 0x778ae2: 83e7fb AND EDI, 0xfffffffb
    s.di = integer::logical((s.di)&(0xfffffffbu),32,flags);
  }
  L00778ae5: { // 0x778ae5: e9b0010000 JMP 0x778c9a
    goto L00778c9a;
  }
  L00778aea: { // 0x778aea: 84c3 TEST BL, AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00778aec: { // 0x778aec: 0f84d2000000 JZ 0x778bc4
    if(integer::condition("JZ",flags)) goto L00778bc4;
  }
  L00778af2: { // 0x778af2: f6451008 TEST byte ptr [EBP + 0x10], 8
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(8u),8,flags);
  }
  L00778af6: { // 0x778af6: 0f84c8000000 JZ 0x778bc4
    if(integer::condition("JZ",flags)) goto L00778bc4;
  }
  L00778afc: { // 0x778afc: 6a08 PUSH 8
    f.push(m,8u);
  }
  L00778afe: { // 0x778afe: e8b5040000 CALL 0x778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834371u); flags=s.arithmetic_flags;
  }
  L00778b03: { // 0x778b03: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778b04: { // 0x778b04: b8000c0000 MOV EAX, 0xc00
    s.ax = 0x00000c00u;
  }
  L00778b09: { // 0x778b09: 8b4d10 MOV ECX, dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L00778b0c: { // 0x778b0c: 23c8 AND ECX, EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L00778b0e: { // 0x778b0e: 0f8488000000 JZ 0x778b9c
    if(integer::condition("JZ",flags)) goto L00778b9c;
  }
  L00778b14: { // 0x778b14: 81f900040000 CMP ECX, 0x400
    (void)integer::sub(s.cx,0x00000400u,32,flags);
  }
  L00778b1a: { // 0x778b1a: 7458 JZ 0x778b74
    if(integer::condition("JZ",flags)) goto L00778b74;
  }
  L00778b1c: { // 0x778b1c: 81f900080000 CMP ECX, 0x800
    (void)integer::sub(s.cx,0x00000800u,32,flags);
  }
  L00778b22: { // 0x778b22: 7428 JZ 0x778b4c
    if(integer::condition("JZ",flags)) goto L00778b4c;
  }
  L00778b24: { // 0x778b24: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00778b26: { // 0x778b26: 0f8590000000 JNZ 0x778bbc
    if(integer::condition("JNZ",flags)) goto L00778bbc;
  }
  L00778b2c: { // 0x778b2c: 8b4d0c MOV ECX, dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b2f: { // 0x778b2f: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778b31: { // 0x778b31: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778b37: { // 0x778b37: dd05107b8100 FLD qword ptr [0x817b10]
    const auto address=(0x00817b10u);
    s.fp.load64(read64(m,address));
  }
  L00778b3d: { // 0x778b3d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778b3f: { // 0x778b3f: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778b40: { // 0x778b40: 7702 JA 0x778b44
    if(integer::condition("JA",flags)) goto L00778b44;
  }
  L00778b42: { // 0x778b42: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778b44: { // 0x778b44: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778b47: { // 0x778b47: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778b4a: { // 0x778b4a: eb6e JMP 0x778bba
    goto L00778bba;
  }
  L00778b4c: { // 0x778b4c: 8b4d0c MOV ECX, dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b4f: { // 0x778b4f: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778b51: { // 0x778b51: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778b57: { // 0x778b57: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778b59: { // 0x778b59: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778b5a: { // 0x778b5a: 7608 JBE 0x778b64
    if(integer::condition("JBE",flags)) goto L00778b64;
  }
  L00778b5c: { // 0x778b5c: dd05007b8100 FLD qword ptr [0x817b00]
    const auto address=(0x00817b00u);
    s.fp.load64(read64(m,address));
  }
  L00778b62: { // 0x778b62: eb08 JMP 0x778b6c
    goto L00778b6c;
  }
  L00778b64: { // 0x778b64: dd05107b8100 FLD qword ptr [0x817b10]
    const auto address=(0x00817b10u);
    s.fp.load64(read64(m,address));
  }
  L00778b6a: { // 0x778b6a: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778b6c: { // 0x778b6c: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778b6f: { // 0x778b6f: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778b72: { // 0x778b72: eb46 JMP 0x778bba
    goto L00778bba;
  }
  L00778b74: { // 0x778b74: 8b4d0c MOV ECX, dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b77: { // 0x778b77: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778b79: { // 0x778b79: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778b7f: { // 0x778b7f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778b81: { // 0x778b81: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778b82: { // 0x778b82: 7608 JBE 0x778b8c
    if(integer::condition("JBE",flags)) goto L00778b8c;
  }
  L00778b84: { // 0x778b84: dd05107b8100 FLD qword ptr [0x817b10]
    const auto address=(0x00817b10u);
    s.fp.load64(read64(m,address));
  }
  L00778b8a: { // 0x778b8a: eb08 JMP 0x778b94
    goto L00778b94;
  }
  L00778b8c: { // 0x778b8c: dd05007b8100 FLD qword ptr [0x817b00]
    const auto address=(0x00817b00u);
    s.fp.load64(read64(m,address));
  }
  L00778b92: { // 0x778b92: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778b94: { // 0x778b94: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778b97: { // 0x778b97: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778b9a: { // 0x778b9a: eb1e JMP 0x778bba
    goto L00778bba;
  }
  L00778b9c: { // 0x778b9c: 8b4d0c MOV ECX, dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L00778b9f: { // 0x778b9f: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00778ba1: { // 0x778ba1: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778ba7: { // 0x778ba7: dd05007b8100 FLD qword ptr [0x817b00]
    const auto address=(0x00817b00u);
    s.fp.load64(read64(m,address));
  }
  L00778bad: { // 0x778bad: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778baf: { // 0x778baf: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778bb0: { // 0x778bb0: 7702 JA 0x778bb4
    if(integer::condition("JA",flags)) goto L00778bb4;
  }
  L00778bb2: { // 0x778bb2: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778bb4: { // 0x778bb4: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778bb7: { // 0x778bb7: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778bba: { // 0x778bba: dd19 FSTP qword ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778bbc: { // 0x778bbc: 83e7fe AND EDI, 0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L00778bbf: { // 0x778bbf: e9d6000000 JMP 0x778c9a
    goto L00778c9a;
  }
  L00778bc4: { // 0x778bc4: a802 TEST AL, 2
    (void)integer::logical(((s.ax & 0xffu))&(2u),8,flags);
  }
  L00778bc6: { // 0x778bc6: 0f84ce000000 JZ 0x778c9a
    if(integer::condition("JZ",flags)) goto L00778c9a;
  }
  L00778bcc: { // 0x778bcc: f6451010 TEST byte ptr [EBP + 0x10], 0x10
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(0x00000010u),8,flags);
  }
  L00778bd0: { // 0x778bd0: 0f84c4000000 JZ 0x778c9a
    if(integer::condition("JZ",flags)) goto L00778c9a;
  }
  L00778bd6: { // 0x778bd6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00778bd7: { // 0x778bd7: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00778bd9: { // 0x778bd9: a810 TEST AL, 0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00778bdb: { // 0x778bdb: 7402 JZ 0x778bdf
    if(integer::condition("JZ",flags)) goto L00778bdf;
  }
  L00778bdd: { // 0x778bdd: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L00778bdf: { // 0x778bdf: 8b450c MOV EAX, dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00778be2: { // 0x778be2: dd00 FLD qword ptr [EAX]
    const auto address=(s.ax);
    s.fp.load64(read64(m,address));
  }
  L00778be4: { // 0x778be4: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778be7: { // 0x778be7: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778bea: { // 0x778bea: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778bf0: { // 0x778bf0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778bf2: { // 0x778bf2: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778bf3: { // 0x778bf3: 0f848f000000 JZ 0x778c88
    if(integer::condition("JZ",flags)) goto L00778c88;
  }
  L00778bf9: { // 0x778bf9: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778bfc: { // 0x778bfc: 8d45fc LEA EAX, [EBP - 4]
    s.ax = (s.bp-4u);
  }
  L00778bff: { // 0x778bff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00778c00: { // 0x778c00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778c01: { // 0x778c01: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778c02: { // 0x778c02: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c05: { // 0x778c05: e8ad020000 CALL 0x778eb7
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778eb7u,7834634u); flags=s.arithmetic_flags;
  }
  L00778c0a: { // 0x778c0a: 8b45fc MOV EAX, dword ptr [EBP - 4]
    s.ax = m.r32((s.bp-4u));
  }
  L00778c0d: { // 0x778c0d: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00778c10: { // 0x778c10: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c13: { // 0x778c13: 8d8800faffff LEA ECX, [EAX - 0x600]
    s.cx = (s.ax-0x00000600u);
  }
  L00778c19: { // 0x778c19: 81f9cefbffff CMP ECX, 0xfffffbce
    (void)integer::sub(s.cx,0xfffffbceu,32,flags);
  }
  L00778c1f: { // 0x778c1f: 7d09 JGE 0x778c2a
    if(integer::condition("JGE",flags)) goto L00778c2a;
  }
  L00778c21: { // 0x778c21: d9ee FLDZ
    numeric_b88::detail::reg<0xd9ee>(s.fp);
  }
  L00778c23: { // 0x778c23: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L00778c25: { // 0x778c25: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c28: { // 0x778c28: eb54 JMP 0x778c7e
    goto L00778c7e;
  }
  L00778c2a: { // 0x778c2a: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778c2d: { // 0x778c2d: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00778c33: { // 0x778c33: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778c35: { // 0x778c35: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00778c36: { // 0x778c36: 7304 JNC 0x778c3c
    if(integer::condition("JNC",flags)) goto L00778c3c;
  }
  L00778c38: { // 0x778c38: 8bd3 MOV EDX, EBX
    s.dx = s.bx;
  }
  L00778c3a: { // 0x778c3a: eb02 JMP 0x778c3e
    goto L00778c3e;
  }
  L00778c3c: { // 0x778c3c: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00778c3e: { // 0x778c3e: 8a45fa MOV AL, byte ptr [EBP - 6]
    s.ax = with_al(s.ax, m.r8((s.bp-6u)));
  }
  L00778c41: { // 0x778c41: 83e00f AND EAX, 0xf
    s.ax = integer::logical((s.ax)&(0x0000000fu),32,flags);
  }
  L00778c44: { // 0x778c44: 0c10 OR AL, 0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00778c46: { // 0x778c46: 668945fa MOV word ptr [EBP - 6], AX
    m.w16((s.bp-6u), (s.ax & 0xffffu));
  }
  L00778c4a: { // 0x778c4a: b803fcffff MOV EAX, 0xfffffc03
    s.ax = 0xfffffc03u;
  }
  L00778c4f: { // 0x778c4f: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00778c51: { // 0x778c51: 7d1f JGE 0x778c72
    if(integer::condition("JGE",flags)) goto L00778c72;
  }
  L00778c53: { // 0x778c53: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00778c55: { // 0x778c55: 845df4 TEST byte ptr [EBP - 0xc], BL
    (void)integer::logical((m.r8((s.bp-0x0000000cu)))&((s.bx & 0xffu)),8,flags);
  }
  L00778c58: { // 0x778c58: 7406 JZ 0x778c60
    if(integer::condition("JZ",flags)) goto L00778c60;
  }
  L00778c5a: { // 0x778c5a: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00778c5c: { // 0x778c5c: 7502 JNZ 0x778c60
    if(integer::condition("JNZ",flags)) goto L00778c60;
  }
  L00778c5e: { // 0x778c5e: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L00778c60: { // 0x778c60: d16df4 SHR dword ptr [EBP - 0xc], 1
    m.w32((s.bp-0x0000000cu), integer::shift(m.r32((s.bp-0x0000000cu)),1u,32,flags,integer::Shift::right));
  }
  L00778c63: { // 0x778c63: 845df8 TEST byte ptr [EBP - 8], BL
    (void)integer::logical((m.r8((s.bp-8u)))&((s.bx & 0xffu)),8,flags);
  }
  L00778c66: { // 0x778c66: 7404 JZ 0x778c6c
    if(integer::condition("JZ",flags)) goto L00778c6c;
  }
  L00778c68: { // 0x778c68: 804df780 OR byte ptr [EBP - 9], 0x80
    m.w8((s.bp-9u), integer::logical((m.r8((s.bp-9u)))|(0x00000080u),8,flags));
  }
  L00778c6c: { // 0x778c6c: d16df8 SHR dword ptr [EBP - 8], 1
    m.w32((s.bp-8u), integer::shift(m.r32((s.bp-8u)),1u,32,flags,integer::Shift::right));
  }
  L00778c6f: { // 0x778c6f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00778c70: { // 0x778c70: 75e3 JNZ 0x778c55
    if(integer::condition("JNZ",flags)) goto L00778c55;
  }
  L00778c72: { // 0x778c72: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00778c74: { // 0x778c74: 7408 JZ 0x778c7e
    if(integer::condition("JZ",flags)) goto L00778c7e;
  }
  L00778c76: { // 0x778c76: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778c79: { // 0x778c79: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00778c7b: { // 0x778c7b: dd5df4 FSTP qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c7e: { // 0x778c7e: dd45f4 FLD qword ptr [EBP - 0xc]
    const auto address=(s.bp-0x0000000cu);
    s.fp.load64(read64(m,address));
  }
  L00778c81: { // 0x778c81: 8b450c MOV EAX, dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00778c84: { // 0x778c84: dd18 FSTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778c86: { // 0x778c86: eb02 JMP 0x778c8a
    goto L00778c8a;
  }
  L00778c88: { // 0x778c88: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L00778c8a: { // 0x778c8a: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00778c8c: { // 0x778c8c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00778c8d: { // 0x778c8d: 7408 JZ 0x778c97
    if(integer::condition("JZ",flags)) goto L00778c97;
  }
  L00778c8f: { // 0x778c8f: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  L00778c91: { // 0x778c91: e822030000 CALL 0x778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834774u); flags=s.arithmetic_flags;
  }
  L00778c96: { // 0x778c96: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778c97: { // 0x778c97: 83e7fd AND EDI, 0xfffffffd
    s.di = integer::logical((s.di)&(0xfffffffdu),32,flags);
  }
  L00778c9a: { // 0x778c9a: f6450810 TEST byte ptr [EBP + 8], 0x10
    (void)integer::logical((m.r8((s.bp+8u)))&(0x00000010u),8,flags);
  }
  L00778c9e: { // 0x778c9e: 7411 JZ 0x778cb1
    if(integer::condition("JZ",flags)) goto L00778cb1;
  }
  L00778ca0: { // 0x778ca0: f6451020 TEST byte ptr [EBP + 0x10], 0x20
    (void)integer::logical((m.r8((s.bp+0x00000010u)))&(0x00000020u),8,flags);
  }
  L00778ca4: { // 0x778ca4: 740b JZ 0x778cb1
    if(integer::condition("JZ",flags)) goto L00778cb1;
  }
  L00778ca6: { // 0x778ca6: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  L00778ca8: { // 0x778ca8: e80b030000 CALL 0x778fb8
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778fb8u,7834797u); flags=s.arithmetic_flags;
  }
  L00778cad: { // 0x778cad: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778cae: { // 0x778cae: 83e7ef AND EDI, 0xffffffef
    s.di = integer::logical((s.di)&(0xffffffefu),32,flags);
  }
  L00778cb1: { // 0x778cb1: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00778cb3: { // 0x778cb3: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00778cb5: { // 0x778cb5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00778cb6: { // 0x778cb6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00778cb7: { // 0x778cb7: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00778cba: { // 0x778cba: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00778cbb: { // 0x778cbb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378d91(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778d91: { // 0x778d91: 8a442404 MOV AL, byte ptr [ESP + 4]
    s.ax = with_al(s.ax, m.r8((f.sp+4u)));
  }
  L00778d95: { // 0x778d95: a820 TEST AL, 0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L00778d97: { // 0x778d97: 7404 JZ 0x778d9d
    if(integer::condition("JZ",flags)) goto L00778d9d;
  }
  L00778d99: { // 0x778d99: 6a05 PUSH 5
    f.push(m,5u);
  }
  L00778d9b: { // 0x778d9b: eb16 JMP 0x778db3
    goto L00778db3;
  }
  L00778d9d: { // 0x778d9d: a808 TEST AL, 8
    (void)integer::logical(((s.ax & 0xffu))&(8u),8,flags);
  }
  L00778d9f: { // 0x778d9f: 7404 JZ 0x778da5
    if(integer::condition("JZ",flags)) goto L00778da5;
  }
  L00778da1: { // 0x778da1: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00778da3: { // 0x778da3: eb0e JMP 0x778db3
    goto L00778db3;
  }
  L00778da5: { // 0x778da5: a804 TEST AL, 4
    (void)integer::logical(((s.ax & 0xffu))&(4u),8,flags);
  }
  L00778da7: { // 0x778da7: 7404 JZ 0x778dad
    if(integer::condition("JZ",flags)) goto L00778dad;
  }
  L00778da9: { // 0x778da9: 6a02 PUSH 2
    f.push(m,2u);
  }
  L00778dab: { // 0x778dab: eb06 JMP 0x778db3
    goto L00778db3;
  }
  L00778dad: { // 0x778dad: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L00778daf: { // 0x778daf: 7404 JZ 0x778db5
    if(integer::condition("JZ",flags)) goto L00778db5;
  }
  L00778db1: { // 0x778db1: 6a03 PUSH 3
    f.push(m,3u);
  }
  L00778db3: { // 0x778db3: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L00778db4: { // 0x778db4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00778db5: { // 0x778db5: 0fb6c0 MOVZX EAX, AL
    s.ax = ((s.ax & 0xffu)&integer::mask(8));
  }
  L00778db8: { // 0x778db8: 83e002 AND EAX, 2
    s.ax = integer::logical((s.ax)&(2u),32,flags);
  }
  L00778dbb: { // 0x778dbb: d1e0 SHL EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::left);
  }
  L00778dbd: { // 0x778dbd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378d44(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778d44: { // 0x778d44: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00778d48: { // 0x778d48: 83f801 CMP EAX, 1
    (void)integer::sub(s.ax,1u,32,flags);
  }
  L00778d4b: { // 0x778d4b: 7413 JZ 0x778d60
    if(integer::condition("JZ",flags)) goto L00778d60;
  }
  L00778d4d: { // 0x778d4d: 7e1c JLE 0x778d6b
    if(integer::condition("JLE",flags)) goto L00778d6b;
  }
  L00778d4f: { // 0x778d4f: 83f803 CMP EAX, 3
    (void)integer::sub(s.ax,3u,32,flags);
  }
  L00778d52: { // 0x778d52: 7f17 JG 0x778d6b
    if(integer::condition("JG",flags)) goto L00778d6b;
  }
  L00778d54: { // 0x778d54: e8f5c4ffff CALL 0x77524e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077524eu,7834969u); flags=s.arithmetic_flags;
  }
  L00778d59: { // 0x778d59: c70022000000 MOV dword ptr [EAX], 0x22
    m.w32((s.ax), 0x00000022u);
  }
  L00778d5f: { // 0x778d5f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00778d60: { // 0x778d60: e8e9c4ffff CALL 0x77524e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077524eu,7834981u); flags=s.arithmetic_flags;
  }
  L00778d65: { // 0x778d65: c70021000000 MOV dword ptr [EAX], 0x21
    m.w32((s.ax), 0x00000021u);
  }
  L00778d6b: { // 0x778d6b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378f95(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778f95: { // 0x778f95: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00778f96: { // 0x778f96: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L00778f98: { // 0x778f98: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778f99: { // 0x778f99: 9b WAIT
    s.fp.wait();
  }
  L00778f9a: { // 0x778f9a: d97dfc FNSTCW word ptr [EBP - 4]
    const auto address=(s.bp-4u);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L00778f9d: { // 0x778f9d: 8b450c MOV EAX, dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00778fa0: { // 0x778fa0: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00778fa2: { // 0x778fa2: 234508 AND EAX, dword ptr [EBP + 8]
    s.ax = integer::logical((s.ax)&(m.r32((s.bp+8u))),32,flags);
  }
  L00778fa5: { // 0x778fa5: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L00778fa7: { // 0x778fa7: 234dfc AND ECX, dword ptr [EBP - 4]
    s.cx = integer::logical((s.cx)&(m.r32((s.bp-4u))),32,flags);
  }
  L00778faa: { // 0x778faa: 0bc8 OR ECX, EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  L00778fac: { // 0x778fac: 894d0c MOV dword ptr [EBP + 0xc], ECX
    m.w32((s.bp+0x0000000cu), s.cx);
  }
  L00778faf: { // 0x778faf: d96d0c FLDCW word ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.load_control(m.r16(address));
  }
  L00778fb2: { // 0x778fb2: 0fbf45fc MOVSX EAX, word ptr [EBP - 4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp-4u)),16));
  }
  L00778fb6: { // 0x778fb6: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00778fb7: { // 0x778fb7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378fb8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778fb8: { // 0x778fb8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00778fb9: { // 0x778fb9: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L00778fbb: { // 0x778fbb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778fbc: { // 0x778fbc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778fbd: { // 0x778fbd: 8a4d08 MOV CL, byte ptr [EBP + 8]
    s.cx = with_al(s.cx, m.r8((s.bp+8u)));
  }
  L00778fc0: { // 0x778fc0: f6c101 TEST CL, 1
    (void)integer::logical(((s.cx & 0xffu))&(1u),8,flags);
  }
  L00778fc3: { // 0x778fc3: 740a JZ 0x778fcf
    if(integer::condition("JZ",flags)) goto L00778fcf;
  }
  L00778fc5: { // 0x778fc5: db2d287b8100 FLD xword ptr [0x817b28]
    const auto address=(0x00817b28u);
    ra2::platform::x87::Raw80 v;for(unsigned k=0;k<10;++k)v.bytes[k]=m.r8(address+k);s.fp.load80(v);
  }
  L00778fcb: { // 0x778fcb: db5d08 FISTP dword ptr [EBP + 8]
    const auto address=(s.bp+8u);
    const auto value=s.fp.pop_integer32();
    m.w32(address,value);
  }
  L00778fce: { // 0x778fce: 9b WAIT
    s.fp.wait();
  }
  L00778fcf: { // 0x778fcf: f6c108 TEST CL, 8
    (void)integer::logical(((s.cx & 0xffu))&(8u),8,flags);
  }
  L00778fd2: { // 0x778fd2: 7410 JZ 0x778fe4
    if(integer::condition("JZ",flags)) goto L00778fe4;
  }
  L00778fd4: { // 0x778fd4: 9b WAIT
    s.fp.wait();
  }
  L00778fd5: { // 0x778fd5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778fd7: { // 0x778fd7: db2d287b8100 FLD xword ptr [0x817b28]
    const auto address=(0x00817b28u);
    ra2::platform::x87::Raw80 v;for(unsigned k=0;k<10;++k)v.bytes[k]=m.r8(address+k);s.fp.load80(v);
  }
  L00778fdd: { // 0x778fdd: dd5df8 FSTP qword ptr [EBP - 8]
    const auto address=(s.bp-8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778fe0: { // 0x778fe0: 9b WAIT
    s.fp.wait();
  }
  L00778fe1: { // 0x778fe1: 9b WAIT
    s.fp.wait();
  }
  L00778fe2: { // 0x778fe2: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00778fe4: { // 0x778fe4: f6c110 TEST CL, 0x10
    (void)integer::logical(((s.cx & 0xffu))&(0x00000010u),8,flags);
  }
  L00778fe7: { // 0x778fe7: 740a JZ 0x778ff3
    if(integer::condition("JZ",flags)) goto L00778ff3;
  }
  L00778fe9: { // 0x778fe9: db2d347b8100 FLD xword ptr [0x817b34]
    const auto address=(0x00817b34u);
    ra2::platform::x87::Raw80 v;for(unsigned k=0;k<10;++k)v.bytes[k]=m.r8(address+k);s.fp.load80(v);
  }
  L00778fef: { // 0x778fef: dd5df8 FSTP qword ptr [EBP - 8]
    const auto address=(s.bp-8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778ff2: { // 0x778ff2: 9b WAIT
    s.fp.wait();
  }
  L00778ff3: { // 0x778ff3: f6c104 TEST CL, 4
    (void)integer::logical(((s.cx & 0xffu))&(4u),8,flags);
  }
  L00778ff6: { // 0x778ff6: 7409 JZ 0x779001
    if(integer::condition("JZ",flags)) goto L00779001;
  }
  L00778ff8: { // 0x778ff8: d9ee FLDZ
    numeric_b88::detail::reg<0xd9ee>(s.fp);
  }
  L00778ffa: { // 0x778ffa: d9e8 FLD1
    numeric_b88::detail::reg<0xd9e8>(s.fp);
  }
  L00778ffc: { // 0x778ffc: def1 FDIVRP st(1)
    numeric_b88::detail::reg<0xdef1>(s.fp);
  }
  L00778ffe: { // 0x778ffe: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00779000: { // 0x779000: 9b WAIT
    s.fp.wait();
  }
  L00779001: { // 0x779001: f6c120 TEST CL, 0x20
    (void)integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags);
  }
  L00779004: { // 0x779004: 7406 JZ 0x77900c
    if(integer::condition("JZ",flags)) goto L0077900c;
  }
  L00779006: { // 0x779006: d9eb FLDPI
    numeric_b88::detail::reg<0xd9eb>(s.fp);
  }
  L00779008: { // 0x779008: dd5df8 FSTP qword ptr [EBP - 8]
    const auto address=(s.bp-8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0077900b: { // 0x77900b: 9b WAIT
    s.fp.wait();
  }
  L0077900c: { // 0x77900c: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077900d: { // 0x77900d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037524e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077524e: { // 0x77524e: e878fdffff CALL 0x774fcb
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774fcbu,7819859u); flags=s.arithmetic_flags;
  }
  L00775253: { // 0x775253: 83c008 ADD EAX, 8
    s.ax = integer::add(s.ax,8u,32,flags);
  }
  L00775256: { // 0x775256: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7834277u:f_00378aa5(m,s,child,{});break;
case 7835025u:f_00378d91(m,s,child,{});break;
case 7834948u:f_00378d44(m,s,child,{});break;
case 7835541u:f_00378f95(m,s,child,{});break;
case 7835576u:f_00378fb8(m,s,child,{});break;
case 7819854u:f_0037524e(m,s,child,{});break;
case 0x774fcbu:s.ax=s.os->current_thread(m.r32(0x817778u));finish(m,s,child,0u);break;
default:throw std::domain_error("recovery1110 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_007786b5(Memory& original,const Inputs& i,ThreadAPI& api){reviewed1110(original,i,0x3786b5u);
 if(original.r32(0x81868cu)!=9876u)throw std::domain_error("1110 initial-image matherr boundary only"); std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;s.os=&api;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);


  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007786b5: { // 0x7786b5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007786b6: { // 0x7786b6: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L007786b8: { // 0x7786b8: 83ec58 SUB ESP, 0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L007786bb: { // 0x7786bb: ff7520 PUSH dword ptr [EBP + 0x20]
    f.push(m,m.r32((s.bp+0x00000020u)));
  }
  L007786be: { // 0x7786be: 8d4518 LEA EAX, [EBP + 0x18]
    s.ax = (s.bp+0x00000018u);
  }
  L007786c1: { // 0x7786c1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007786c2: { // 0x7786c2: ff7508 PUSH dword ptr [EBP + 8]
    f.push(m,m.r32((s.bp+8u)));
  }
  L007786c5: { // 0x7786c5: e8db030000 CALL 0x778aa5
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778aa5u,7833290u); flags=s.arithmetic_flags;
  }
  L007786ca: { // 0x7786ca: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L007786cd: { // 0x7786cd: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007786cf: { // 0x7786cf: 7522 JNZ 0x7786f3
    if(integer::condition("JNZ",flags)) goto L007786f3;
  }
  L007786d1: { // 0x7786d1: 8d4518 LEA EAX, [EBP + 0x18]
    s.ax = (s.bp+0x00000018u);
  }
  L007786d4: { // 0x7786d4: 8365e0fe AND dword ptr [EBP - 0x20], 0xfffffffe
    m.w32((s.bp-0x00000020u), integer::logical((m.r32((s.bp-0x00000020u)))&(0xfffffffeu),32,flags));
  }
  L007786d8: { // 0x7786d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007786d9: { // 0x7786d9: 8d4510 LEA EAX, [EBP + 0x10]
    s.ax = (s.bp+0x00000010u);
  }
  L007786dc: { // 0x7786dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007786dd: { // 0x7786dd: 8d4520 LEA EAX, [EBP + 0x20]
    s.ax = (s.bp+0x00000020u);
  }
  L007786e0: { // 0x7786e0: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L007786e3: { // 0x7786e3: ff7508 PUSH dword ptr [EBP + 8]
    f.push(m,m.r32((s.bp+8u)));
  }
  L007786e6: { // 0x7786e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007786e7: { // 0x7786e7: 8d45a8 LEA EAX, [EBP - 0x58]
    s.ax = (s.bp-0x00000058u);
  }
  L007786ea: { // 0x7786ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007786eb: { // 0x7786eb: e802010000 CALL 0x7787f2
    s.arithmetic_flags=flags; invoke(m,s,f,0x007787f2u,7833328u); flags=s.arithmetic_flags;
  }
  L007786f0: { // 0x7786f0: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L007786f3: { // 0x7786f3: ff7508 PUSH dword ptr [EBP + 8]
    f.push(m,m.r32((s.bp+8u)));
  }
  L007786f6: { // 0x7786f6: e896060000 CALL 0x778d91
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778d91u,7833339u); flags=s.arithmetic_flags;
  }
  L007786fb: { // 0x7786fb: 833d8c86810000 CMP dword ptr [0x81868c], 0
    (void)integer::sub(m.r32((0x0081868cu)),0u,32,flags);
  }
  L00778702: { // 0x778702: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778703: { // 0x778703: 752c JNZ 0x778731
    if(integer::condition("JNZ",flags)) goto L00778731;
  }
  L00778705: { // 0x778705: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00778707: { // 0x778707: 7428 JZ 0x778731
    if(integer::condition("JZ",flags)) goto L00778731;
  }
  L00778709: { // 0x778709: ff7520 PUSH dword ptr [EBP + 0x20]
    f.push(m,m.r32((s.bp+0x00000020u)));
  }
  L0077870c: { // 0x77870c: dd4518 FLD qword ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L0077870f: { // 0x77870f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778710: { // 0x778710: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778711: { // 0x778711: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778714: { // 0x778714: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778715: { // 0x778715: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778716: { // 0x778716: d9ee FLDZ
    numeric_b88::detail::reg<0xd9ee>(s.fp);
  }
  L00778718: { // 0x778718: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0077871b: { // 0x77871b: dd4510 FLD qword ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0077871e: { // 0x77871e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077871f: { // 0x77871f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778720: { // 0x778720: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778723: { // 0x778723: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L00778726: { // 0x778726: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00778727: { // 0x778727: e890050000 CALL 0x778cbc
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778cbcu,7833388u); flags=s.arithmetic_flags;
  }
  L0077872c: { // 0x77872c: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L0077872f: { // 0x77872f: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00778730: { // 0x778730: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00778731: { // 0x778731: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00778732: { // 0x778732: e80d060000 CALL 0x778d44
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778d44u,7833399u); flags=s.arithmetic_flags;
  }
  L00778737: { // 0x778737: c70424ffff0000 MOV dword ptr [ESP], 0xffff
    m.w32((f.sp), 0x0000ffffu);
  }
  L0077873e: { // 0x77873e: ff7520 PUSH dword ptr [EBP + 0x20]
    f.push(m,m.r32((s.bp+0x00000020u)));
  }
  L00778741: { // 0x778741: e84f080000 CALL 0x778f95
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778f95u,7833414u); flags=s.arithmetic_flags;
  }
  L00778746: { // 0x778746: dd4518 FLD qword ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L00778749: { // 0x778749: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077874a: { // 0x77874a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077874b: { // 0x77874b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077874c: { // 0x77874c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0077874d(Memory& original,const Inputs& i,ThreadAPI& api){reviewed1110(original,i,0x37874du);
 if(original.r32(0x81868cu)!=9876u)throw std::domain_error("1110 initial-image matherr boundary only"); std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;s.os=&api;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);


  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077874d: { // 0x77874d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077874e: { // 0x77874e: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L00778750: { // 0x778750: 83ec58 SUB ESP, 0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L00778753: { // 0x778753: ff7528 PUSH dword ptr [EBP + 0x28]
    f.push(m,m.r32((s.bp+0x00000028u)));
  }
  L00778756: { // 0x778756: 8d4520 LEA EAX, [EBP + 0x20]
    s.ax = (s.bp+0x00000020u);
  }
  L00778759: { // 0x778759: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077875a: { // 0x77875a: ff7508 PUSH dword ptr [EBP + 8]
    f.push(m,m.r32((s.bp+8u)));
  }
  L0077875d: { // 0x77875d: e843030000 CALL 0x778aa5
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778aa5u,7833442u); flags=s.arithmetic_flags;
  }
  L00778762: { // 0x778762: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00778765: { // 0x778765: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00778767: { // 0x778767: 752e JNZ 0x778797
    if(integer::condition("JNZ",flags)) goto L00778797;
  }
  L00778769: { // 0x778769: 8b45e0 MOV EAX, dword ptr [EBP - 0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  L0077876c: { // 0x77876c: 24e3 AND AL, 0xe3
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000e3u),8,flags));
  }
  L0077876e: { // 0x77876e: 0c03 OR AL, 3
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(3u),8,flags));
  }
  L00778770: { // 0x778770: 8945e0 MOV dword ptr [EBP - 0x20], EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  L00778773: { // 0x778773: 8d4520 LEA EAX, [EBP + 0x20]
    s.ax = (s.bp+0x00000020u);
  }
  L00778776: { // 0x778776: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00778777: { // 0x778777: 8d4510 LEA EAX, [EBP + 0x10]
    s.ax = (s.bp+0x00000010u);
  }
  L0077877a: { // 0x77877a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077877b: { // 0x77877b: 8d4528 LEA EAX, [EBP + 0x28]
    s.ax = (s.bp+0x00000028u);
  }
  L0077877e: { // 0x77877e: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L00778781: { // 0x778781: dd4518 FLD qword ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L00778784: { // 0x778784: ff7508 PUSH dword ptr [EBP + 8]
    f.push(m,m.r32((s.bp+8u)));
  }
  L00778787: { // 0x778787: dd5dd0 FSTP qword ptr [EBP - 0x30]
    const auto address=(s.bp-0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0077878a: { // 0x77878a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077878b: { // 0x77878b: 8d45a8 LEA EAX, [EBP - 0x58]
    s.ax = (s.bp-0x00000058u);
  }
  L0077878e: { // 0x77878e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077878f: { // 0x77878f: e85e000000 CALL 0x7787f2
    s.arithmetic_flags=flags; invoke(m,s,f,0x007787f2u,7833492u); flags=s.arithmetic_flags;
  }
  L00778794: { // 0x778794: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00778797: { // 0x778797: ff7508 PUSH dword ptr [EBP + 8]
    f.push(m,m.r32((s.bp+8u)));
  }
  L0077879a: { // 0x77879a: e8f2050000 CALL 0x778d91
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778d91u,7833503u); flags=s.arithmetic_flags;
  }
  L0077879f: { // 0x77879f: 833d8c86810000 CMP dword ptr [0x81868c], 0
    (void)integer::sub(m.r32((0x0081868cu)),0u,32,flags);
  }
  L007787a6: { // 0x7787a6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007787a7: { // 0x7787a7: 752d JNZ 0x7787d6
    if(integer::condition("JNZ",flags)) goto L007787d6;
  }
  L007787a9: { // 0x7787a9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007787ab: { // 0x7787ab: 7429 JZ 0x7787d6
    if(integer::condition("JZ",flags)) goto L007787d6;
  }
  L007787ad: { // 0x7787ad: ff7528 PUSH dword ptr [EBP + 0x28]
    f.push(m,m.r32((s.bp+0x00000028u)));
  }
  L007787b0: { // 0x7787b0: dd4520 FLD qword ptr [EBP + 0x20]
    const auto address=(s.bp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L007787b3: { // 0x7787b3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007787b4: { // 0x7787b4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007787b5: { // 0x7787b5: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007787b8: { // 0x7787b8: dd4518 FLD qword ptr [EBP + 0x18]
    const auto address=(s.bp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L007787bb: { // 0x7787bb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007787bc: { // 0x7787bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007787bd: { // 0x7787bd: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007787c0: { // 0x7787c0: dd4510 FLD qword ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L007787c3: { // 0x7787c3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007787c4: { // 0x7787c4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007787c5: { // 0x7787c5: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007787c8: { // 0x7787c8: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  L007787cb: { // 0x7787cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007787cc: { // 0x7787cc: e8eb040000 CALL 0x778cbc
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778cbcu,7833553u); flags=s.arithmetic_flags;
  }
  L007787d1: { // 0x7787d1: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L007787d4: { // 0x7787d4: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L007787d5: { // 0x7787d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007787d6: { // 0x7787d6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007787d7: { // 0x7787d7: e868050000 CALL 0x778d44
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778d44u,7833564u); flags=s.arithmetic_flags;
  }
  L007787dc: { // 0x7787dc: c70424ffff0000 MOV dword ptr [ESP], 0xffff
    m.w32((f.sp), 0x0000ffffu);
  }
  L007787e3: { // 0x7787e3: ff7528 PUSH dword ptr [EBP + 0x28]
    f.push(m,m.r32((s.bp+0x00000028u)));
  }
  L007787e6: { // 0x7787e6: e8aa070000 CALL 0x778f95
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778f95u,7833579u); flags=s.arithmetic_flags;
  }
  L007787eb: { // 0x7787eb: dd4520 FLD qword ptr [EBP + 0x20]
    const auto address=(s.bp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L007787ee: { // 0x7787ee: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007787ef: { // 0x7787ef: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007787f0: { // 0x7787f0: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L007787f1: { // 0x7787f1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0077ccab(Memory& original,const Inputs& i,ThreadAPI& api){reviewed1110(original,i,0x37ccabu);
 if(original.r32(0x81868cu)!=9876u)throw std::domain_error("1110 initial-image matherr boundary only"); std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;s.os=&api;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);


  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077ccab: { // 0x77ccab: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077ccac: { // 0x77ccac: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L0077ccae: { // 0x77ccae: 83ec58 SUB ESP, 0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L0077ccb1: { // 0x77ccb1: 8b4510 MOV EAX, dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0077ccb4: { // 0x77ccb4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077ccb5: { // 0x77ccb5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077ccb6: { // 0x77ccb6: 8b750c MOV ESI, dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0077ccb9: { // 0x77ccb9: 0fb708 MOVZX ECX, word ptr [EAX]
    s.cx = (m.r16((s.ax))&integer::mask(16));
  }
  L0077ccbc: { // 0x77ccbc: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0077ccbe: { // 0x77ccbe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077ccbf: { // 0x77ccbf: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077ccc0: { // 0x77ccc0: 894d10 MOV dword ptr [EBP + 0x10], ECX
    m.w32((s.bp+0x00000010u), s.cx);
  }
  L0077ccc3: { // 0x77ccc3: 742b JZ 0x77ccf0
    if(integer::condition("JZ",flags)) goto L0077ccf0;
  }
  L0077ccc5: { // 0x77ccc5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077ccc6: { // 0x77ccc6: 7424 JZ 0x77ccec
    if(integer::condition("JZ",flags)) goto L0077ccec;
  }
  L0077ccc8: { // 0x77ccc8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077ccc9: { // 0x77ccc9: 741d JZ 0x77cce8
    if(integer::condition("JZ",flags)) goto L0077cce8;
  }
  L0077cccb: { // 0x77cccb: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077cccc: { // 0x77cccc: 7416 JZ 0x77cce4
    if(integer::condition("JZ",flags)) goto L0077cce4;
  }
  L0077ccce: { // 0x77ccce: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077cccf: { // 0x77cccf: 741f JZ 0x77ccf0
    if(integer::condition("JZ",flags)) goto L0077ccf0;
  }
  L0077ccd1: { // 0x77ccd1: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077ccd2: { // 0x77ccd2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077ccd3: { // 0x77ccd3: 7407 JZ 0x77ccdc
    if(integer::condition("JZ",flags)) goto L0077ccdc;
  }
  L0077ccd5: { // 0x77ccd5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0077ccd6: { // 0x77ccd6: 756e JNZ 0x77cd46
    if(integer::condition("JNZ",flags)) goto L0077cd46;
  }
  L0077ccd8: { // 0x77ccd8: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  L0077ccda: { // 0x77ccda: eb16 JMP 0x77ccf2
    goto L0077ccf2;
  }
  L0077ccdc: { // 0x77ccdc: c70601000000 MOV dword ptr [ESI], 1
    m.w32((s.si), 1u);
  }
  L0077cce2: { // 0x77cce2: eb62 JMP 0x77cd46
    goto L0077cd46;
  }
  L0077cce4: { // 0x77cce4: 6a12 PUSH 0x12
    f.push(m,0x00000012u);
  }
  L0077cce6: { // 0x77cce6: eb0a JMP 0x77ccf2
    goto L0077ccf2;
  }
  L0077cce8: { // 0x77cce8: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  L0077ccea: { // 0x77ccea: eb06 JMP 0x77ccf2
    goto L0077ccf2;
  }
  L0077ccec: { // 0x77ccec: 6a04 PUSH 4
    f.push(m,4u);
  }
  L0077ccee: { // 0x77ccee: eb02 JMP 0x77ccf2
    goto L0077ccf2;
  }
  L0077ccf0: { // 0x77ccf0: 6a08 PUSH 8
    f.push(m,8u);
  }
  L0077ccf2: { // 0x77ccf2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077ccf3: { // 0x77ccf3: 8d7e18 LEA EDI, [ESI + 0x18]
    s.di = (s.si+0x00000018u);
  }
  L0077ccf6: { // 0x77ccf6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077ccf7: { // 0x77ccf7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077ccf8: { // 0x77ccf8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077ccf9: { // 0x77ccf9: e8a7bdffff CALL 0x778aa5
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778aa5u,7851262u); flags=s.arithmetic_flags;
  }
  L0077ccfe: { // 0x77ccfe: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0077cd01: { // 0x77cd01: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077cd03: { // 0x77cd03: 7541 JNZ 0x77cd46
    if(integer::condition("JNZ",flags)) goto L0077cd46;
  }
  L0077cd05: { // 0x77cd05: 8b4508 MOV EAX, dword ptr [EBP + 8]
    s.ax = m.r32((s.bp+8u));
  }
  L0077cd08: { // 0x77cd08: 83f810 CMP EAX, 0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L0077cd0b: { // 0x77cd0b: 7410 JZ 0x77cd1d
    if(integer::condition("JZ",flags)) goto L0077cd1d;
  }
  L0077cd0d: { // 0x77cd0d: 83f816 CMP EAX, 0x16
    (void)integer::sub(s.ax,0x00000016u,32,flags);
  }
  L0077cd10: { // 0x77cd10: 740b JZ 0x77cd1d
    if(integer::condition("JZ",flags)) goto L0077cd1d;
  }
  L0077cd12: { // 0x77cd12: 83f81d CMP EAX, 0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L0077cd15: { // 0x77cd15: 7406 JZ 0x77cd1d
    if(integer::condition("JZ",flags)) goto L0077cd1d;
  }
  L0077cd17: { // 0x77cd17: 8365e0fe AND dword ptr [EBP - 0x20], 0xfffffffe
    m.w32((s.bp-0x00000020u), integer::logical((m.r32((s.bp-0x00000020u)))&(0xfffffffeu),32,flags));
  }
  L0077cd1b: { // 0x77cd1b: eb12 JMP 0x77cd2f
    goto L0077cd2f;
  }
  L0077cd1d: { // 0x77cd1d: 8b4de0 MOV ECX, dword ptr [EBP - 0x20]
    s.cx = m.r32((s.bp-0x00000020u));
  }
  L0077cd20: { // 0x77cd20: dd4610 FLD qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0077cd23: { // 0x77cd23: 83e1e3 AND ECX, 0xffffffe3
    s.cx = integer::logical((s.cx)&(0xffffffe3u),32,flags);
  }
  L0077cd26: { // 0x77cd26: dd5dd0 FSTP qword ptr [EBP - 0x30]
    const auto address=(s.bp-0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0077cd29: { // 0x77cd29: 83c903 OR ECX, 3
    s.cx = integer::logical((s.cx)|(3u),32,flags);
  }
  L0077cd2c: { // 0x77cd2c: 894de0 MOV dword ptr [EBP - 0x20], ECX
    m.w32((s.bp-0x00000020u), s.cx);
  }
  L0077cd2f: { // 0x77cd2f: 8d4e08 LEA ECX, [ESI + 8]
    s.cx = (s.si+8u);
  }
  L0077cd32: { // 0x77cd32: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077cd33: { // 0x77cd33: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077cd34: { // 0x77cd34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077cd35: { // 0x77cd35: 8d4510 LEA EAX, [EBP + 0x10]
    s.ax = (s.bp+0x00000010u);
  }
  L0077cd38: { // 0x77cd38: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077cd39: { // 0x77cd39: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077cd3a: { // 0x77cd3a: 8d45a8 LEA EAX, [EBP - 0x58]
    s.ax = (s.bp-0x00000058u);
  }
  L0077cd3d: { // 0x77cd3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077cd3e: { // 0x77cd3e: e8afbaffff CALL 0x7787f2
    s.arithmetic_flags=flags; invoke(m,s,f,0x007787f2u,7851331u); flags=s.arithmetic_flags;
  }
  L0077cd43: { // 0x77cd43: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0077cd46: { // 0x77cd46: 68ffff0000 PUSH 0xffff
    f.push(m,0x0000ffffu);
  }
  L0077cd4b: { // 0x77cd4b: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  L0077cd4e: { // 0x77cd4e: e842c2ffff CALL 0x778f95
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778f95u,7851347u); flags=s.arithmetic_flags;
  }
  L0077cd53: { // 0x77cd53: 833e08 CMP dword ptr [ESI], 8
    (void)integer::sub(m.r32((s.si)),8u,32,flags);
  }
  L0077cd56: { // 0x77cd56: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077cd57: { // 0x77cd57: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077cd58: { // 0x77cd58: 7414 JZ 0x77cd6e
    if(integer::condition("JZ",flags)) goto L0077cd6e;
  }
  L0077cd5a: { // 0x77cd5a: 833d8c86810000 CMP dword ptr [0x81868c], 0
    (void)integer::sub(m.r32((0x0081868cu)),0u,32,flags);
  }
  L0077cd61: { // 0x77cd61: 750b JNZ 0x77cd6e
    if(integer::condition("JNZ",flags)) goto L0077cd6e;
  }
  L0077cd63: { // 0x77cd63: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077cd64: { // 0x77cd64: e83d250000 CALL 0x77f2a6
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077f2a6u,7851369u); flags=s.arithmetic_flags;
  }
  L0077cd69: { // 0x77cd69: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077cd6b: { // 0x77cd6b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077cd6c: { // 0x77cd6c: 7508 JNZ 0x77cd76
    if(integer::condition("JNZ",flags)) goto L0077cd76;
  }
  L0077cd6e: { // 0x77cd6e: ff36 PUSH dword ptr [ESI]
    f.push(m,m.r32((s.si)));
  }
  L0077cd70: { // 0x77cd70: e8cfbfffff CALL 0x778d44
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778d44u,7851381u); flags=s.arithmetic_flags;
  }
  L0077cd75: { // 0x77cd75: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077cd76: { // 0x77cd76: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077cd77: { // 0x77cd77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077cd78: { // 0x77cd78: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077cd79: { // 0x77cd79: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077cd7a: { // 0x77cd7a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
