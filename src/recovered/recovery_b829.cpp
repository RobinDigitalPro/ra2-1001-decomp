#include "recovered/recovery_b829_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b829 {
namespace {
void f_00363ef0(Memory&,State&,Frame&,const Operations&);
void f_00366960(Memory&,State&,Frame&,const Operations&);
void f_00366a80(Memory&,State&,Frame&,const Operations&);
void f_003657d0(Memory&,State&,Frame&,const Operations&);
void f_00364290(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00363ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763ef0: { // 0x763ef0: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L00763ef4: { // 0x763ef4: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00763ef8: { // 0x763ef8: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763efa: { // 0x763efa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00763efb: { // 0x763efb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763efc: { // 0x763efc: 83f908 CMP ECX, 8
    (void)integer::sub(s.cx,8u,32,flags);
  }
  L00763eff: { // 0x763eff: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763f00: { // 0x763f00: 0f8790000000 JA 0x763f96
    if(integer::condition("JA",flags)) goto L00763f96;
  }
  L00763f06: { // 0x763f06: ff248d9c3f7600 JMP dword ptr [ECX*4 + 0x763f9c]
    switch((std::array<std::uint32_t,9>{0x763f73u,0x763f73u,0x763f73u,0x763f73u,0x763f0du,0x763f91u,0x763f55u,0x763f55u,0x763f73u}[s.cx])){
    case 0x00763ef0u: goto L00763ef0;
    case 0x00763ef4u: goto L00763ef4;
    case 0x00763ef8u: goto L00763ef8;
    case 0x00763efau: goto L00763efa;
    case 0x00763efbu: goto L00763efb;
    case 0x00763efcu: goto L00763efc;
    case 0x00763effu: goto L00763eff;
    case 0x00763f00u: goto L00763f00;
    case 0x00763f06u: goto L00763f06;
    case 0x00763f0du: goto L00763f0d;
    case 0x00763f13u: goto L00763f13;
    case 0x00763f17u: goto L00763f17;
    case 0x00763f1du: goto L00763f1d;
    case 0x00763f20u: goto L00763f20;
    case 0x00763f22u: goto L00763f22;
    case 0x00763f24u: goto L00763f24;
    case 0x00763f2au: goto L00763f2a;
    case 0x00763f2cu: goto L00763f2c;
    case 0x00763f2du: goto L00763f2d;
    case 0x00763f2fu: goto L00763f2f;
    case 0x00763f31u: goto L00763f31;
    case 0x00763f35u: goto L00763f35;
    case 0x00763f38u: goto L00763f38;
    case 0x00763f3au: goto L00763f3a;
    case 0x00763f3cu: goto L00763f3c;
    case 0x00763f3du: goto L00763f3d;
    case 0x00763f40u: goto L00763f40;
    case 0x00763f42u: goto L00763f42;
    case 0x00763f48u: goto L00763f48;
    case 0x00763f49u: goto L00763f49;
    case 0x00763f4bu: goto L00763f4b;
    case 0x00763f4du: goto L00763f4d;
    case 0x00763f53u: goto L00763f53;
    case 0x00763f54u: goto L00763f54;
    case 0x00763f55u: goto L00763f55;
    case 0x00763f59u: goto L00763f59;
    case 0x00763f5cu: goto L00763f5c;
    case 0x00763f5eu: goto L00763f5e;
    case 0x00763f5fu: goto L00763f5f;
    case 0x00763f61u: goto L00763f61;
    case 0x00763f65u: goto L00763f65;
    case 0x00763f6bu: goto L00763f6b;
    case 0x00763f6du: goto L00763f6d;
    case 0x00763f73u: goto L00763f73;
    case 0x00763f74u: goto L00763f74;
    case 0x00763f76u: goto L00763f76;
    case 0x00763f77u: goto L00763f77;
    case 0x00763f78u: goto L00763f78;
    case 0x00763f7eu: goto L00763f7e;
    case 0x00763f82u: goto L00763f82;
    case 0x00763f84u: goto L00763f84;
    case 0x00763f86u: goto L00763f86;
    case 0x00763f88u: goto L00763f88;
    case 0x00763f89u: goto L00763f89;
    case 0x00763f8fu: goto L00763f8f;
    case 0x00763f90u: goto L00763f90;
    case 0x00763f91u: goto L00763f91;
    case 0x00763f96u: goto L00763f96;
    case 0x00763f97u: goto L00763f97;
    case 0x00763f98u: goto L00763f98;
    default:throw std::domain_error("recovery829 unsupported switch destination");}
  }
  L00763f0d: { // 0x763f0d: 8bba04070000 MOV EDI, dword ptr [EDX + 0x704]
    s.di = m.r32((s.dx+0x00000704u));
  }
  L00763f13: { // 0x763f13: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00763f17: { // 0x763f17: 8bb200070000 MOV ESI, dword ptr [EDX + 0x700]
    s.si = m.r32((s.dx+0x00000700u));
  }
  L00763f1d: { // 0x763f1d: 8d0c07 LEA ECX, [EDI + EAX]
    s.cx = (s.di+s.ax);
  }
  L00763f20: { // 0x763f20: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00763f22: { // 0x763f22: 7f6d JG 0x763f91
    if(integer::condition("JG",flags)) goto L00763f91;
  }
  L00763f24: { // 0x763f24: 8bb2f4060000 MOV ESI, dword ptr [EDX + 0x6f4]
    s.si = m.r32((s.dx+0x000006f4u));
  }
  L00763f2a: { // 0x763f2a: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00763f2c: { // 0x763f2c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763f2d: { // 0x763f2d: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L00763f2f: { // 0x763f2f: 03f7 ADD ESI, EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00763f31: { // 0x763f31: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00763f35: { // 0x763f35: c1e902 SHR ECX, 2
    s.cx = integer::shift(s.cx,2u,32,flags,integer::Shift::right);
  }
  L00763f38: { // 0x763f38: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00763f3a: { // 0x763f3a: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L00763f3c: { // 0x763f3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763f3d: { // 0x763f3d: 83e103 AND ECX, 3
    s.cx = integer::logical((s.cx)&(3u),32,flags);
  }
  L00763f40: { // 0x763f40: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00763f42: { // 0x763f42: 8b8a04070000 MOV ECX, dword ptr [EDX + 0x704]
    s.cx = m.r32((s.dx+0x00000704u));
  }
  L00763f48: { // 0x763f48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f49: { // 0x763f49: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00763f4b: { // 0x763f4b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763f4d: { // 0x763f4d: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f53: { // 0x763f53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f54: { // 0x763f54: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f55: { // 0x763f55: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00763f59: { // 0x763f59: 83e900 SUB ECX, 0
    s.cx = integer::sub(s.cx,0u,32,flags);
  }
  L00763f5c: { // 0x763f5c: 741a JZ 0x763f78
    if(integer::condition("JZ",flags)) goto L00763f78;
  }
  L00763f5e: { // 0x763f5e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00763f5f: { // 0x763f5f: 7530 JNZ 0x763f91
    if(integer::condition("JNZ",flags)) goto L00763f91;
  }
  L00763f61: { // 0x763f61: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00763f65: { // 0x763f65: 8b8a04070000 MOV ECX, dword ptr [EDX + 0x704]
    s.cx = m.r32((s.dx+0x00000704u));
  }
  L00763f6b: { // 0x763f6b: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00763f6d: { // 0x763f6d: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f73: { // 0x763f73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f74: { // 0x763f74: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763f76: { // 0x763f76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f77: { // 0x763f77: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f78: { // 0x763f78: 8bb2fc060000 MOV ESI, dword ptr [EDX + 0x6fc]
    s.si = m.r32((s.dx+0x000006fcu));
  }
  L00763f7e: { // 0x763f7e: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00763f82: { // 0x763f82: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00763f84: { // 0x763f84: 7c0b JL 0x763f91
    if(integer::condition("JL",flags)) goto L00763f91;
  }
  L00763f86: { // 0x763f86: 2bce SUB ECX, ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L00763f88: { // 0x763f88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f89: { // 0x763f89: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f8f: { // 0x763f8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f90: { // 0x763f90: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f91: { // 0x763f91: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00763f96: { // 0x763f96: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f97: { // 0x763f97: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f98: { // 0x763f98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00366960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766960: { // 0x766960: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766961: { // 0x766961: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766962: { // 0x766962: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766963: { // 0x766963: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766964: { // 0x766964: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00766966: { // 0x766966: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00766968: { // 0x766968: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766969: { // 0x766969: 8a86f5000000 MOV AL,byte ptr [ESI + 0xf5]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000f5u)));
  }
  L0076696f: { // 0x76696f: 8bbe64010000 MOV EDI,dword ptr [ESI + 0x164]
    s.di = m.r32((s.si+0x00000164u));
  }
  L00766975: { // 0x766975: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00766977: { // 0x766977: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0076697b: { // 0x76697b: 7551 JNZ 0x007669ce
    if(integer::condition("JNZ",flags)) goto L007669ce;
  }
  L0076697d: { // 0x76697d: 8b8678010000 MOV EAX,dword ptr [ESI + 0x178]
    s.ax = m.r32((s.si+0x00000178u));
  }
  L00766983: { // 0x766983: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766985: { // 0x766985: 7547 JNZ 0x007669ce
    if(integer::condition("JNZ",flags)) goto L007669ce;
  }
  L00766987: { // 0x766987: 8b9654070000 MOV EDX,dword ptr [ESI + 0x754]
    s.dx = m.r32((s.si+0x00000754u));
  }
  L0076698d: { // 0x76698d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076698f: { // 0x76698f: 668b864c070000 MOV AX,word ptr [ESI + 0x74c]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000074cu)));
  }
  L00766996: { // 0x766996: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00766998: { // 0x766998: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076699a: { // 0x76699a: 7e17 JLE 0x007669b3
    if(integer::condition("JLE",flags)) goto L007669b3;
  }
  L0076699c: { // 0x76699c: 8b9e80010000 MOV EBX,dword ptr [ESI + 0x180]
    s.bx = m.r32((s.si+0x00000180u));
  }
  L007669a2: { // 0x7669a2: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L007669a4: { // 0x7669a4: 668b2a MOV BP,word ptr [EDX]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L007669a7: { // 0x7669a7: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L007669a9: { // 0x7669a9: 7f0c JG 0x007669b7
    if(integer::condition("JG",flags)) goto L007669b7;
  }
  L007669ab: { // 0x7669ab: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007669ac: { // 0x7669ac: 83c206 ADD EDX,0x6
    s.dx = integer::add(s.dx,0x00000006u,32,flags);
  }
  L007669af: { // 0x7669af: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007669b1: { // 0x7669b1: 7cef JL 0x007669a2
    if(integer::condition("JL",flags)) goto L007669a2;
  }
  L007669b3: { // 0x7669b3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007669b5: { // 0x7669b5: eb0d JMP 0x007669c4
    goto L007669c4;
  }
  L007669b7: { // 0x7669b7: 8b8654070000 MOV EAX,dword ptr [ESI + 0x754]
    s.ax = m.r32((s.si+0x00000754u));
  }
  L007669bd: { // 0x7669bd: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L007669c0: { // 0x7669c0: 8b444802 MOV EAX,dword ptr [EAX + ECX*0x2 + 0x2]
    s.ax = m.r32((s.ax+(s.cx * 0x00000002u)+0x00000002u));
  }
  L007669c4: { // 0x7669c4: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L007669c8: { // 0x7669c8: 89867c010000 MOV dword ptr [ESI + 0x17c],EAX
    m.w32((s.si+0x0000017cu), s.ax);
  }
  L007669ce: { // 0x7669ce: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L007669d0: { // 0x7669d0: 8b9678010000 MOV EDX,dword ptr [ESI + 0x178]
    s.dx = m.r32((s.si+0x00000178u));
  }
  L007669d6: { // 0x7669d6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L007669d8: { // 0x7669d8: 8d5301 LEA EDX,[EBX + 0x1]
    s.dx = (s.bx+0x00000001u);
  }
  L007669db: { // 0x7669db: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L007669de: { // 0x7669de: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007669df: { // 0x7669df: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007669e0: { // 0x7669e0: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007669e2: { // 0x7669e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007669e3: { // 0x7669e3: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7760358u); flags=s.arithmetic_flags;
  }
  L007669e6: { // 0x7669e6: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007669e9: { // 0x7669e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007669eb: { // 0x7669eb: 740b JZ 0x007669f8
    if(integer::condition("JZ",flags)) goto L007669f8;
  }
  L007669ed: { // 0x7669ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007669ee: { // 0x7669ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007669ef: { // 0x7669ef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007669f0: { // 0x7669f0: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007669f5: { // 0x7669f5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007669f6: { // 0x7669f6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007669f7: { // 0x7669f7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007669f8: { // 0x7669f8: 8bae78010000 MOV EBP,dword ptr [ESI + 0x178]
    s.bp = m.r32((s.si+0x00000178u));
  }
  L007669fe: { // 0x7669fe: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L00766a00: { // 0x766a00: 8b9e74010000 MOV EBX,dword ptr [ESI + 0x174]
    s.bx = m.r32((s.si+0x00000174u));
  }
  L00766a06: { // 0x766a06: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00766a07: { // 0x766a07: 89ae78010000 MOV dword ptr [ESI + 0x178],EBP
    m.w32((s.si+0x00000178u), s.bp);
  }
  L00766a0d: { // 0x766a0d: 899e74010000 MOV dword ptr [ESI + 0x174],EBX
    m.w32((s.si+0x00000174u), s.bx);
  }
  L00766a13: { // 0x766a13: 8a96f5000000 MOV DL,byte ptr [ESI + 0xf5]
    s.dx = with_al(s.dx, m.r8((s.si+0x000000f5u)));
  }
  L00766a19: { // 0x766a19: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00766a1b: { // 0x766a1b: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00766a1d: { // 0x766a1d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00766a1f: { // 0x766a1f: 743f JZ 0x00766a60
    if(integer::condition("JZ",flags)) goto L00766a60;
  }
  L00766a21: { // 0x766a21: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00766a23: { // 0x766a23: 8a96f5000000 MOV DL,byte ptr [ESI + 0xf5]
    s.dx = with_al(s.dx, m.r8((s.si+0x000000f5u)));
  }
  L00766a29: { // 0x766a29: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00766a2b: { // 0x766a2b: 752a JNZ 0x00766a57
    if(integer::condition("JNZ",flags)) goto L00766a57;
  }
  L00766a2d: { // 0x766a2d: 894714 MOV dword ptr [EDI + 0x14],EAX
    m.w32((s.di+0x00000014u), s.ax);
  }
  L00766a30: { // 0x766a30: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766a32: { // 0x766a32: 898674010000 MOV dword ptr [ESI + 0x174],EAX
    m.w32((s.si+0x00000174u), s.ax);
  }
  L00766a38: { // 0x766a38: 898678010000 MOV dword ptr [ESI + 0x178],EAX
    m.w32((s.si+0x00000178u), s.ax);
  }
  L00766a3e: { // 0x766a3e: 894710 MOV dword ptr [EDI + 0x10],EAX
    m.w32((s.di+0x00000010u), s.ax);
  }
  L00766a41: { // 0x766a41: c7470c08000000 MOV dword ptr [EDI + 0xc],0x8
    m.w32((s.di+0x0000000cu), 0x00000008u);
  }
  L00766a48: { // 0x766a48: 89be68010000 MOV dword ptr [ESI + 0x168],EDI
    m.w32((s.si+0x00000168u), s.di);
  }
  L00766a4e: { // 0x766a4e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00766a51: { // 0x766a51: 898664010000 MOV dword ptr [ESI + 0x164],EAX
    m.w32((s.si+0x00000164u), s.ax);
  }
  L00766a57: { // 0x766a57: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766a58: { // 0x766a58: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766a59: { // 0x766a59: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766a5a: { // 0x766a5a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766a5d: { // 0x766a5d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766a5e: { // 0x766a5e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766a5f: { // 0x766a5f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00766a60: { // 0x766a60: 8b8e7c010000 MOV ECX,dword ptr [ESI + 0x17c]
    s.cx = m.r32((s.si+0x0000017cu));
  }
  L00766a66: { // 0x766a66: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00766a68: { // 0x766a68: 74c3 JZ 0x00766a2d
    if(integer::condition("JZ",flags)) goto L00766a2d;
  }
  L00766a6a: { // 0x766a6a: 7eeb JLE 0x00766a57
    if(integer::condition("JLE",flags)) goto L00766a57;
  }
  L00766a6c: { // 0x766a6c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766a6d: { // 0x766a6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766a6e: { // 0x766a6e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766a6f: { // 0x766a6f: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766a74: { // 0x766a74: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766a75: { // 0x766a75: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766a76: { // 0x766a76: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00366a80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766a80: { // 0x766a80: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00766a83: { // 0x766a83: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766a84: { // 0x766a84: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766a85: { // 0x766a85: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766a86: { // 0x766a86: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00766a88: { // 0x766a88: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766a8a: { // 0x766a8a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766a8b: { // 0x766a8b: 8a86f5000000 MOV AL,byte ptr [ESI + 0xf5]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000f5u)));
  }
  L00766a91: { // 0x766a91: 8b9e64010000 MOV EBX,dword ptr [ESI + 0x164]
    s.bx = m.r32((s.si+0x00000164u));
  }
  L00766a97: { // 0x766a97: 8d7a01 LEA EDI,[EDX + 0x1]
    s.di = (s.dx+0x00000001u);
  }
  L00766a9a: { // 0x766a9a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00766a9c: { // 0x766a9c: 8b8678010000 MOV EAX,dword ptr [ESI + 0x178]
    s.ax = m.r32((s.si+0x00000178u));
  }
  L00766aa2: { // 0x766aa2: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L00766aa5: { // 0x766aa5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766aa7: { // 0x766aa7: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00766aab: { // 0x766aab: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00766aaf: { // 0x766aaf: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00766ab3: { // 0x766ab3: 0f858f000000 JNZ 0x00766b48
    if(integer::condition("JNZ",flags)) goto L00766b48;
  }
  L00766ab9: { // 0x766ab9: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00766abb: { // 0x766abb: 7415 JZ 0x00766ad2
    if(integer::condition("JZ",flags)) goto L00766ad2;
  }
  L00766abd: { // 0x766abd: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00766abf: { // 0x766abf: 8d5501 LEA EDX,[EBP + 0x1]
    s.dx = (s.bp+0x00000001u);
  }
  L00766ac2: { // 0x766ac2: 0fafcf IMUL ECX,EDI
    s.cx = integer::imul(s.cx,s.di,32,flags);
  }
  L00766ac5: { // 0x766ac5: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00766ac8: { // 0x766ac8: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00766aca: { // 0x766aca: 898e7c010000 MOV dword ptr [ESI + 0x17c],ECX
    m.w32((s.si+0x0000017cu), s.cx);
  }
  L00766ad0: { // 0x766ad0: eb53 JMP 0x00766b25
    goto L00766b25;
  }
  L00766ad2: { // 0x766ad2: 8b9654070000 MOV EDX,dword ptr [ESI + 0x754]
    s.dx = m.r32((s.si+0x00000754u));
  }
  L00766ad8: { // 0x766ad8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766ada: { // 0x766ada: 668b864c070000 MOV AX,word ptr [ESI + 0x74c]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000074cu)));
  }
  L00766ae1: { // 0x766ae1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00766ae3: { // 0x766ae3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766ae5: { // 0x766ae5: 7e1f JLE 0x00766b06
    if(integer::condition("JLE",flags)) goto L00766b06;
  }
  L00766ae7: { // 0x766ae7: 8b9e80010000 MOV EBX,dword ptr [ESI + 0x180]
    s.bx = m.r32((s.si+0x00000180u));
  }
  L00766aed: { // 0x766aed: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00766aef: { // 0x766aef: 668b2a MOV BP,word ptr [EDX]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00766af2: { // 0x766af2: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00766af4: { // 0x766af4: 7f14 JG 0x00766b0a
    if(integer::condition("JG",flags)) goto L00766b0a;
  }
  L00766af6: { // 0x766af6: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00766af7: { // 0x766af7: 83c206 ADD EDX,0x6
    s.dx = integer::add(s.dx,0x00000006u,32,flags);
  }
  L00766afa: { // 0x766afa: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00766afc: { // 0x766afc: 7cef JL 0x00766aed
    if(integer::condition("JL",flags)) goto L00766aed;
  }
  L00766afe: { // 0x766afe: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00766b02: { // 0x766b02: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00766b06: { // 0x766b06: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766b08: { // 0x766b08: eb15 JMP 0x00766b1f
    goto L00766b1f;
  }
  L00766b0a: { // 0x766b0a: 8b8654070000 MOV EAX,dword ptr [ESI + 0x754]
    s.ax = m.r32((s.si+0x00000754u));
  }
  L00766b10: { // 0x766b10: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00766b14: { // 0x766b14: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00766b18: { // 0x766b18: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L00766b1b: { // 0x766b1b: 8b444802 MOV EAX,dword ptr [EAX + ECX*0x2 + 0x2]
    s.ax = m.r32((s.ax+(s.cx * 0x00000002u)+0x00000002u));
  }
  L00766b1f: { // 0x766b1f: 89867c010000 MOV dword ptr [ESI + 0x17c],EAX
    m.w32((s.si+0x0000017cu), s.ax);
  }
  L00766b25: { // 0x766b25: f6865401000001 TEST byte ptr [ESI + 0x154],0x1
    (void)integer::logical((m.r8((s.si+0x00000154u)))&(0x00000001u),8,flags);
  }
  L00766b2c: { // 0x766b2c: 7513 JNZ 0x00766b41
    if(integer::condition("JNZ",flags)) goto L00766b41;
  }
  L00766b2e: { // 0x766b2e: 8b9668070000 MOV EDX,dword ptr [ESI + 0x768]
    s.dx = m.r32((s.si+0x00000768u));
  }
  L00766b34: { // 0x766b34: 8b867c010000 MOV EAX,dword ptr [ESI + 0x17c]
    s.ax = m.r32((s.si+0x0000017cu));
  }
  L00766b3a: { // 0x766b3a: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00766b3c: { // 0x766b3c: 895310 MOV dword ptr [EBX + 0x10],EDX
    m.w32((s.bx+0x00000010u), s.dx);
  }
  L00766b3f: { // 0x766b3f: eb07 JMP 0x00766b48
    goto L00766b48;
  }
  L00766b41: { // 0x766b41: c7431000000000 MOV dword ptr [EBX + 0x10],0x0
    m.w32((s.bx+0x00000010u), 0x00000000u);
  }
  L00766b48: { // 0x766b48: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  L00766b4b: { // 0x766b4b: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00766b4d: { // 0x766b4d: 8b8e78010000 MOV ECX,dword ptr [ESI + 0x178]
    s.cx = m.r32((s.si+0x00000178u));
  }
  L00766b53: { // 0x766b53: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00766b55: { // 0x766b55: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00766b57: { // 0x766b57: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766b58: { // 0x766b58: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766b59: { // 0x766b59: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766b5b: { // 0x766b5b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766b5c: { // 0x766b5c: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7760735u); flags=s.arithmetic_flags;
  }
  L00766b5f: { // 0x766b5f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766b62: { // 0x766b62: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766b64: { // 0x766b64: 740d JZ 0x00766b73
    if(integer::condition("JZ",flags)) goto L00766b73;
  }
  L00766b66: { // 0x766b66: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766b67: { // 0x766b67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766b68: { // 0x766b68: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766b69: { // 0x766b69: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766b6e: { // 0x766b6e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766b6f: { // 0x766b6f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766b72: { // 0x766b72: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00766b73: { // 0x766b73: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00766b77: { // 0x766b77: 8b9678010000 MOV EDX,dword ptr [ESI + 0x178]
    s.dx = m.r32((s.si+0x00000178u));
  }
  L00766b7d: { // 0x766b7d: 8b8e74010000 MOV ECX,dword ptr [ESI + 0x174]
    s.cx = m.r32((s.si+0x00000174u));
  }
  L00766b83: { // 0x766b83: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00766b85: { // 0x766b85: 899678010000 MOV dword ptr [ESI + 0x178],EDX
    m.w32((s.si+0x00000178u), s.dx);
  }
  L00766b8b: { // 0x766b8b: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00766b8d: { // 0x766b8d: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00766b8f: { // 0x766b8f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00766b90: { // 0x766b90: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00766b92: { // 0x766b92: 898e74010000 MOV dword ptr [ESI + 0x174],ECX
    m.w32((s.si+0x00000174u), s.cx);
  }
  L00766b98: { // 0x766b98: 744d JZ 0x00766be7
    if(integer::condition("JZ",flags)) goto L00766be7;
  }
  L00766b9a: { // 0x766b9a: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00766b9c: { // 0x766b9c: 753e JNZ 0x00766bdc
    if(integer::condition("JNZ",flags)) goto L00766bdc;
  }
  L00766b9e: { // 0x766b9e: 899674010000 MOV dword ptr [ESI + 0x174],EDX
    m.w32((s.si+0x00000174u), s.dx);
  }
  L00766ba4: { // 0x766ba4: 899678010000 MOV dword ptr [ESI + 0x178],EDX
    m.w32((s.si+0x00000178u), s.dx);
  }
  L00766baa: { // 0x766baa: c7430c0a000000 MOV dword ptr [EBX + 0xc],0xa
    m.w32((s.bx+0x0000000cu), 0x0000000au);
  }
  L00766bb1: { // 0x766bb1: 899e68010000 MOV dword ptr [ESI + 0x168],EBX
    m.w32((s.si+0x00000168u), s.bx);
  }
  L00766bb7: { // 0x766bb7: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00766bba: { // 0x766bba: 898e64010000 MOV dword ptr [ESI + 0x164],ECX
    m.w32((s.si+0x00000164u), s.cx);
  }
  L00766bc0: { // 0x766bc0: 6683bee800000003 CMP word ptr [ESI + 0xe8],0x3
    (void)integer::sub(m.r16((s.si+0x000000e8u)),0x00000003u,16,flags);
  }
  L00766bc8: { // 0x766bc8: 7312 JNC 0x00766bdc
    if(integer::condition("JNC",flags)) goto L00766bdc;
  }
  L00766bca: { // 0x766bca: 8b967c010000 MOV EDX,dword ptr [ESI + 0x17c]
    s.dx = m.r32((s.si+0x0000017cu));
  }
  L00766bd0: { // 0x766bd0: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  L00766bd3: { // 0x766bd3: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00766bd5: { // 0x766bd5: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00766bd7: { // 0x766bd7: c644020180 MOV byte ptr [EDX + EAX*0x1 + 0x1],0x80
    m.w8((s.dx+(s.ax * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00766bdc: { // 0x766bdc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766bdd: { // 0x766bdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766bde: { // 0x766bde: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766bdf: { // 0x766bdf: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766be2: { // 0x766be2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766be3: { // 0x766be3: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766be6: { // 0x766be6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00766be7: { // 0x766be7: 8b8e7c010000 MOV ECX,dword ptr [ESI + 0x17c]
    s.cx = m.r32((s.si+0x0000017cu));
  }
  L00766bed: { // 0x766bed: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00766bef: { // 0x766bef: 74ad JZ 0x00766b9e
    if(integer::condition("JZ",flags)) goto L00766b9e;
  }
  L00766bf1: { // 0x766bf1: 7ee9 JLE 0x00766bdc
    if(integer::condition("JLE",flags)) goto L00766bdc;
  }
  L00766bf3: { // 0x766bf3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766bf4: { // 0x766bf4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766bf5: { // 0x766bf5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766bf6: { // 0x766bf6: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766bfb: { // 0x766bfb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766bfc: { // 0x766bfc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766bff: { // 0x766bff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_003657d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007657d0: { // 0x7657d0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L007657d3: { // 0x7657d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007657d4: { // 0x7657d4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007657d5: { // 0x7657d5: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L007657d7: { // 0x7657d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007657d8: { // 0x7657d8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007657d9: { // 0x7657d9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L007657db: { // 0x7657db: 8b8570010000 MOV EAX,dword ptr [EBP + 0x170]
    s.ax = m.r32((s.bp+0x00000170u));
  }
  L007657e1: { // 0x7657e1: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L007657e5: { // 0x7657e5: 8d4201 LEA EAX,[EDX + 0x1]
    s.ax = (s.dx+0x00000001u);
  }
  L007657e8: { // 0x7657e8: 83e0fe AND EAX,0xfffffffe
    s.ax = integer::logical((s.ax)&(0xfffffffeu),32,flags);
  }
  L007657eb: { // 0x7657eb: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L007657ef: { // 0x7657ef: 0f867a040000 JBE 0x00765c6f
    if(integer::condition("JBE",flags)) goto L00765c6f;
  }
  L007657f5: { // 0x7657f5: 8d9d98010000 LEA EBX,[EBP + 0x198]
    s.bx = (s.bp+0x00000198u);
  }
  L007657fb: { // 0x7657fb: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L007657fd: { // 0x7657fd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007657fe: { // 0x7657fe: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765800: { // 0x765800: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765801: { // 0x765801: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7755780u); flags=s.arithmetic_flags;
  }
  L00765804: { // 0x765804: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765807: { // 0x765807: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765809: { // 0x765809: 0f8533040000 JNZ 0x00765c42
    if(integer::condition("JNZ",flags)) goto L00765c42;
  }
  L0076580f: { // 0x76580f: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00765812: { // 0x765812: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00765814: { // 0x765814: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00765816: { // 0x765816: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00765818: { // 0x765818: 81e60000ff00 AND ESI,0xff0000
    s.si = integer::logical((s.si)&(0x00ff0000u),32,flags);
  }
  L0076581e: { // 0x76581e: c1e910 SHR ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00765821: { // 0x765821: c1e210 SHL EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00765824: { // 0x765824: 2500ff0000 AND EAX,0xff00
    s.ax = integer::logical((s.ax)&(0x0000ff00u),32,flags);
  }
  L00765829: { // 0x765829: 0bf1 OR ESI,ECX
    s.si = integer::logical((s.si)|(s.cx),32,flags);
  }
  L0076582b: { // 0x76582b: 0bd0 OR EDX,EAX
    s.dx = integer::logical((s.dx)|(s.ax),32,flags);
  }
  L0076582d: { // 0x76582d: c1ee08 SHR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::right);
  }
  L00765830: { // 0x765830: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00765833: { // 0x765833: 0bf2 OR ESI,EDX
    s.si = integer::logical((s.si)|(s.dx),32,flags);
  }
  L00765835: { // 0x765835: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  L00765838: { // 0x765838: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0076583a: { // 0x76583a: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L0076583d: { // 0x76583d: 8d540f08 LEA EDX,[EDI + ECX*0x1 + 0x8]
    s.dx = (s.di+(s.cx * 0x00000001u)+0x00000008u);
  }
  L00765841: { // 0x765841: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00765845: { // 0x765845: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00765847: { // 0x765847: 81fa5650445a CMP EDX,0x5a445056
    (void)integer::sub(s.dx,0x5a445056u,32,flags);
  }
  L0076584d: { // 0x76584d: 0f870a020000 JA 0x00765a5d
    if(integer::condition("JA",flags)) goto L00765a5d;
  }
  L00765853: { // 0x765853: 0f841a030000 JZ 0x00765b73
    if(integer::condition("JZ",flags)) goto L00765b73;
  }
  L00765859: { // 0x765859: 81fa56505430 CMP EDX,0x30545056
    (void)integer::sub(s.dx,0x30545056u,32,flags);
  }
  L0076585f: { // 0x76585f: 0f871a010000 JA 0x0076597f
    if(integer::condition("JA",flags)) goto L0076597f;
  }
  L00765865: { // 0x765865: 0f84b6010000 JZ 0x00765a21
    if(integer::condition("JZ",flags)) goto L00765a21;
  }
  L0076586b: { // 0x76586b: 81fa43424630 CMP EDX,0x30464243
    (void)integer::sub(s.dx,0x30464243u,32,flags);
  }
  L00765871: { // 0x765871: 0f84b9000000 JZ 0x00765930
    if(integer::condition("JZ",flags)) goto L00765930;
  }
  L00765877: { // 0x765877: 81fa43504c30 CMP EDX,0x304c5043
    (void)integer::sub(s.dx,0x304c5043u,32,flags);
  }
  L0076587d: { // 0x76587d: 742e JZ 0x007658ad
    if(integer::condition("JZ",flags)) goto L007658ad;
  }
  L0076587f: { // 0x76587f: 81fa43425030 CMP EDX,0x30504243
    (void)integer::sub(s.dx,0x30504243u,32,flags);
  }
  L00765885: { // 0x765885: 0f85c6030000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L0076588b: { // 0x76588b: f644242408 TEST byte ptr [ESP + 0x24],0x8
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000008u),8,flags);
  }
  L00765890: { // 0x765890: 0f8587030000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765896: { // 0x765896: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765898: { // 0x765898: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0076589a: { // 0x76589a: e8c1100000 CALL 0x00766960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766960u,7755935u); flags=s.arithmetic_flags;
  }
  L0076589f: { // 0x76589f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007658a2: { // 0x7658a2: 0f85a9030000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L007658a8: { // 0x7658a8: e982030000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L007658ad: { // 0x7658ad: f644242401 TEST byte ptr [ESP + 0x24],0x1
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000001u),8,flags);
  }
  L007658b2: { // 0x7658b2: 0f8565030000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L007658b8: { // 0x7658b8: 8b9d70010000 MOV EBX,dword ptr [EBP + 0x170]
    s.bx = m.r32((s.bp+0x00000170u));
  }
  L007658be: { // 0x7658be: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007658c0: { // 0x7658c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007658c1: { // 0x7658c1: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L007658c4: { // 0x7658c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007658c5: { // 0x7658c5: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007658c7: { // 0x7658c7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007658c8: { // 0x7658c8: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7755979u); flags=s.arithmetic_flags;
  }
  L007658cb: { // 0x7658cb: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007658ce: { // 0x7658ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007658d0: { // 0x7658d0: 0f857b030000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L007658d6: { // 0x7658d6: 8b5314 MOV EDX,dword ptr [EBX + 0x14]
    s.dx = m.r32((s.bx+0x00000014u));
  }
  L007658d9: { // 0x7658d9: 894324 MOV dword ptr [EBX + 0x24],EAX
    m.w32((s.bx+0x00000024u), s.ax);
  }
  L007658dc: { // 0x7658dc: 83e2f7 AND EDX,0xfffffff7
    s.dx = integer::logical((s.dx)&(0xfffffff7u),32,flags);
  }
  L007658df: { // 0x7658df: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L007658e4: { // 0x7658e4: 895314 MOV dword ptr [EBX + 0x14],EDX
    m.w32((s.bx+0x00000014u), s.dx);
  }
  L007658e7: { // 0x7658e7: 897328 MOV dword ptr [EBX + 0x28],ESI
    m.w32((s.bx+0x00000028u), s.si);
  }
  L007658ea: { // 0x7658ea: 66398558070000 CMP word ptr [EBP + 0x758],AX
    (void)integer::sub(m.r16((s.bp+0x00000758u)),(s.ax & 0xffffu),16,flags);
  }
  L007658f1: { // 0x7658f1: 7530 JNZ 0x00765923
    if(integer::condition("JNZ",flags)) goto L00765923;
  }
  L007658f3: { // 0x7658f3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007658f5: { // 0x7658f5: 8b7308 MOV ESI,dword ptr [EBX + 0x8]
    s.si = m.r32((s.bx+0x00000008u));
  }
  L007658f8: { // 0x7658f8: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007658fa: { // 0x7658fa: 8dbdc4010000 LEA EDI,[EBP + 0x1c4]
    s.di = (s.bp+0x000001c4u);
  }
  L00765900: { // 0x765900: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L00765903: { // 0x765903: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00765905: { // 0x765905: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00765907: { // 0x765907: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0076590a: { // 0x76590a: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L0076590c: { // 0x76590c: 8b4b28 MOV ECX,dword ptr [EBX + 0x28]
    s.cx = m.r32((s.bx+0x00000028u));
  }
  L0076590f: { // 0x76590f: 898dc0010000 MOV dword ptr [EBP + 0x1c0],ECX
    m.w32((s.bp+0x000001c0u), s.cx);
  }
  L00765915: { // 0x765915: 8b8da4010000 MOV ECX,dword ptr [EBP + 0x1a4]
    s.cx = m.r32((s.bp+0x000001a4u));
  }
  L0076591b: { // 0x76591b: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  L0076591d: { // 0x76591d: 898da4010000 MOV dword ptr [EBP + 0x1a4],ECX
    m.w32((s.bp+0x000001a4u), s.cx);
  }
  L00765923: { // 0x765923: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765927: { // 0x765927: 83481404 OR dword ptr [EAX + 0x14],0x4
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000004u),32,flags));
  }
  L0076592b: { // 0x76592b: e9ff020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765930: { // 0x765930: f644242410 TEST byte ptr [ESP + 0x24],0x10
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000010u),8,flags);
  }
  L00765935: { // 0x765935: 0f85e2020000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L0076593b: { // 0x76593b: 8b9d64010000 MOV EBX,dword ptr [EBP + 0x164]
    s.bx = m.r32((s.bp+0x00000164u));
  }
  L00765941: { // 0x765941: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765943: { // 0x765943: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765944: { // 0x765944: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00765946: { // 0x765946: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00765947: { // 0x765947: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765949: { // 0x765949: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076594a: { // 0x76594a: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756109u); flags=s.arithmetic_flags;
  }
  L0076594d: { // 0x76594d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765950: { // 0x765950: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765952: { // 0x765952: 0f85f9020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765958: { // 0x765958: 898574010000 MOV dword ptr [EBP + 0x174],EAX
    m.w32((s.bp+0x00000174u), s.ax);
  }
  L0076595e: { // 0x76595e: 894310 MOV dword ptr [EBX + 0x10],EAX
    m.w32((s.bx+0x00000010u), s.ax);
  }
  L00765961: { // 0x765961: 897314 MOV dword ptr [EBX + 0x14],ESI
    m.w32((s.bx+0x00000014u), s.si);
  }
  L00765964: { // 0x765964: c7430c08000000 MOV dword ptr [EBX + 0xc],0x8
    m.w32((s.bx+0x0000000cu), 0x00000008u);
  }
  L0076596b: { // 0x76596b: 899d68010000 MOV dword ptr [EBP + 0x168],EBX
    m.w32((s.bp+0x00000168u), s.bx);
  }
  L00765971: { // 0x765971: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00765974: { // 0x765974: 898564010000 MOV dword ptr [EBP + 0x164],EAX
    m.w32((s.bp+0x00000164u), s.ax);
  }
  L0076597a: { // 0x76597a: e9b0020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L0076597f: { // 0x76597f: 81fa56505444 CMP EDX,0x44545056
    (void)integer::sub(s.dx,0x44545056u,32,flags);
  }
  L00765985: { // 0x765985: 0f8496000000 JZ 0x00765a21
    if(integer::condition("JZ",flags)) goto L00765a21;
  }
  L0076598b: { // 0x76598b: 81fa5650544b CMP EDX,0x4b545056
    (void)integer::sub(s.dx,0x4b545056u,32,flags);
  }
  L00765991: { // 0x765991: 744d JZ 0x007659e0
    if(integer::condition("JZ",flags)) goto L007659e0;
  }
  L00765993: { // 0x765993: 81fa56505452 CMP EDX,0x52545056
    (void)integer::sub(s.dx,0x52545056u,32,flags);
  }
  L00765999: { // 0x765999: 0f85b2020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L0076599f: { // 0x76599f: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L007659a4: { // 0x7659a4: 0f8573020000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L007659aa: { // 0x7659aa: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L007659b0: { // 0x7659b0: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007659b2: { // 0x7659b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007659b3: { // 0x7659b3: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L007659b5: { // 0x7659b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007659b6: { // 0x7659b6: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007659b8: { // 0x7659b8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007659b9: { // 0x7659b9: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756220u); flags=s.arithmetic_flags;
  }
  L007659bc: { // 0x7659bc: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007659bf: { // 0x7659bf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007659c1: { // 0x7659c1: 0f858a020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L007659c7: { // 0x7659c7: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  L007659ca: { // 0x7659ca: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  L007659cd: { // 0x7659cd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L007659d1: { // 0x7659d1: 83e2ef AND EDX,0xffffffef
    s.dx = integer::logical((s.dx)&(0xffffffefu),32,flags);
  }
  L007659d4: { // 0x7659d4: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L007659d7: { // 0x7659d7: 83481420 OR dword ptr [EAX + 0x14],0x20
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000020u),32,flags));
  }
  L007659db: { // 0x7659db: e94f020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L007659e0: { // 0x7659e0: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L007659e5: { // 0x7659e5: 0f8532020000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L007659eb: { // 0x7659eb: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L007659f1: { // 0x7659f1: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007659f3: { // 0x7659f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007659f4: { // 0x7659f4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L007659f6: { // 0x7659f6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007659f7: { // 0x7659f7: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007659f9: { // 0x7659f9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007659fa: { // 0x7659fa: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756285u); flags=s.arithmetic_flags;
  }
  L007659fd: { // 0x7659fd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765a00: { // 0x765a00: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765a02: { // 0x765a02: 0f8549020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765a08: { // 0x765a08: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  L00765a0b: { // 0x765a0b: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  L00765a0e: { // 0x765a0e: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765a12: { // 0x765a12: 83e2ef AND EDX,0xffffffef
    s.dx = integer::logical((s.dx)&(0xffffffefu),32,flags);
  }
  L00765a15: { // 0x765a15: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L00765a18: { // 0x765a18: 83481402 OR dword ptr [EAX + 0x14],0x2
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000002u),32,flags));
  }
  L00765a1c: { // 0x765a1c: e90e020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765a21: { // 0x765a21: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765a26: { // 0x765a26: 0f85f1010000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765a2c: { // 0x765a2c: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L00765a32: { // 0x765a32: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765a34: { // 0x765a34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765a35: { // 0x765a35: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00765a37: { // 0x765a37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765a38: { // 0x765a38: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765a3a: { // 0x765a3a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765a3b: { // 0x765a3b: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756350u); flags=s.arithmetic_flags;
  }
  L00765a3e: { // 0x765a3e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765a41: { // 0x765a41: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765a43: { // 0x765a43: 0f8508020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765a49: { // 0x765a49: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00765a4c: { // 0x765a4c: c7462000000000 MOV dword ptr [ESI + 0x20],0x0
    m.w32((s.si+0x00000020u), 0x00000000u);
  }
  L00765a53: { // 0x765a53: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L00765a55: { // 0x765a55: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  L00765a58: { // 0x765a58: e9d2010000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765a5d: { // 0x765a5d: 81fa4342505a CMP EDX,0x5a504243
    (void)integer::sub(s.dx,0x5a504243u,32,flags);
  }
  L00765a63: { // 0x765a63: 0f87f6000000 JA 0x00765b5f
    if(integer::condition("JA",flags)) goto L00765b5f;
  }
  L00765a69: { // 0x765a69: 0f84ce000000 JZ 0x00765b3d
    if(integer::condition("JZ",flags)) goto L00765b3d;
  }
  L00765a6f: { // 0x765a6f: 81fa4342465a CMP EDX,0x5a464243
    (void)integer::sub(s.dx,0x5a464243u,32,flags);
  }
  L00765a75: { // 0x765a75: 0f84a0000000 JZ 0x00765b1b
    if(integer::condition("JZ",flags)) goto L00765b1b;
  }
  L00765a7b: { // 0x765a7b: 81fa56504b5a CMP EDX,0x5a4b5056
    (void)integer::sub(s.dx,0x5a4b5056u,32,flags);
  }
  L00765a81: { // 0x765a81: 7436 JZ 0x00765ab9
    if(integer::condition("JZ",flags)) goto L00765ab9;
  }
  L00765a83: { // 0x765a83: 81fa43504c5a CMP EDX,0x5a4c5043
    (void)integer::sub(s.dx,0x5a4c5043u,32,flags);
  }
  L00765a89: { // 0x765a89: 0f85c2010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765a8f: { // 0x765a8f: f644242401 TEST byte ptr [ESP + 0x24],0x1
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000001u),8,flags);
  }
  L00765a94: { // 0x765a94: 0f8583010000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765a9a: { // 0x765a9a: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765a9c: { // 0x765a9c: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00765a9e: { // 0x765a9e: e85d110000 CALL 0x00766c00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766c00u,7756451u); flags=s.arithmetic_flags;
  }
  L00765aa3: { // 0x765aa3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00765aa6: { // 0x765aa6: 0f85a5010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765aac: { // 0x765aac: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765ab0: { // 0x765ab0: 83481404 OR dword ptr [EAX + 0x14],0x4
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000004u),32,flags));
  }
  L00765ab4: { // 0x765ab4: e976010000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765ab9: { // 0x765ab9: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765abe: { // 0x765abe: 0f8559010000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765ac4: { // 0x765ac4: 8b9d6c070000 MOV EBX,dword ptr [EBP + 0x76c]
    s.bx = m.r32((s.bp+0x0000076cu));
  }
  L00765aca: { // 0x765aca: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00765ad0: { // 0x765ad0: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00765ad2: { // 0x765ad2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765ad3: { // 0x765ad3: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00765ad5: { // 0x765ad5: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00765ad7: { // 0x765ad7: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00765ad9: { // 0x765ad9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765ada: { // 0x765ada: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765adc: { // 0x765adc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765add: { // 0x765add: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00765ae1: { // 0x765ae1: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756516u); flags=s.arithmetic_flags;
  }
  L00765ae4: { // 0x765ae4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765ae7: { // 0x765ae7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765ae9: { // 0x765ae9: 0f8562010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765aef: { // 0x765aef: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00765af2: { // 0x765af2: 895f20 MOV dword ptr [EDI + 0x20],EBX
    m.w32((s.di+0x00000020u), s.bx);
  }
  L00765af5: { // 0x765af5: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00765af8: { // 0x765af8: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00765afb: { // 0x765afb: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00765b03: { // 0x765b03: 7309 JNC 0x00765b0e
    if(integer::condition("JNC",flags)) goto L00765b0e;
  }
  L00765b05: { // 0x765b05: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00765b09: { // 0x765b09: c644310180 MOV byte ptr [ECX + ESI*0x1 + 0x1],0x80
    m.w8((s.cx+(s.si * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00765b0e: { // 0x765b0e: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765b12: { // 0x765b12: 83481402 OR dword ptr [EAX + 0x14],0x2
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000002u),32,flags));
  }
  L00765b16: { // 0x765b16: e914010000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765b1b: { // 0x765b1b: f644242410 TEST byte ptr [ESP + 0x24],0x10
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000010u),8,flags);
  }
  L00765b20: { // 0x765b20: 0f85f7000000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765b26: { // 0x765b26: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765b28: { // 0x765b28: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00765b2a: { // 0x765b2a: e8b10d0000 CALL 0x007668e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007668e0u,7756591u); flags=s.arithmetic_flags;
  }
  L00765b2f: { // 0x765b2f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00765b32: { // 0x765b32: 0f8519010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765b38: { // 0x765b38: e9f2000000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765b3d: { // 0x765b3d: f644242408 TEST byte ptr [ESP + 0x24],0x8
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000008u),8,flags);
  }
  L00765b42: { // 0x765b42: 0f85d5000000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765b48: { // 0x765b48: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765b4a: { // 0x765b4a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00765b4c: { // 0x765b4c: e82f0f0000 CALL 0x00766a80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766a80u,7756625u); flags=s.arithmetic_flags;
  }
  L00765b51: { // 0x765b51: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00765b54: { // 0x765b54: 0f85f7000000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765b5a: { // 0x765b5a: e9d0000000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765b5f: { // 0x765b5f: 81fa5650525a CMP EDX,0x5a525056
    (void)integer::sub(s.dx,0x5a525056u,32,flags);
  }
  L00765b65: { // 0x765b65: 7461 JZ 0x00765bc8
    if(integer::condition("JZ",flags)) goto L00765bc8;
  }
  L00765b67: { // 0x765b67: 81fa5650545a CMP EDX,0x5a545056
    (void)integer::sub(s.dx,0x5a545056u,32,flags);
  }
  L00765b6d: { // 0x765b6d: 0f85de000000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765b73: { // 0x765b73: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765b78: { // 0x765b78: 0f859f000000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765b7e: { // 0x765b7e: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00765b84: { // 0x765b84: 8b9d6c070000 MOV EBX,dword ptr [EBP + 0x76c]
    s.bx = m.r32((s.bp+0x0000076cu));
  }
  L00765b8a: { // 0x765b8a: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00765b8c: { // 0x765b8c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765b8d: { // 0x765b8d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00765b8f: { // 0x765b8f: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00765b91: { // 0x765b91: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765b92: { // 0x765b92: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765b94: { // 0x765b94: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765b95: { // 0x765b95: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00765b99: { // 0x765b99: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756700u); flags=s.arithmetic_flags;
  }
  L00765b9c: { // 0x765b9c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765b9f: { // 0x765b9f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765ba1: { // 0x765ba1: 0f85aa000000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765ba7: { // 0x765ba7: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00765baa: { // 0x765baa: 895f20 MOV dword ptr [EDI + 0x20],EBX
    m.w32((s.di+0x00000020u), s.bx);
  }
  L00765bad: { // 0x765bad: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00765bb0: { // 0x765bb0: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00765bb3: { // 0x765bb3: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00765bbb: { // 0x765bbb: 7372 JNC 0x00765c2f
    if(integer::condition("JNC",flags)) goto L00765c2f;
  }
  L00765bbd: { // 0x765bbd: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00765bc1: { // 0x765bc1: c644320180 MOV byte ptr [EDX + ESI*0x1 + 0x1],0x80
    m.w8((s.dx+(s.si * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00765bc6: { // 0x765bc6: eb67 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765bc8: { // 0x765bc8: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765bcd: { // 0x765bcd: 754e JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765bcf: { // 0x765bcf: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00765bd5: { // 0x765bd5: 8b9d6c070000 MOV EBX,dword ptr [EBP + 0x76c]
    s.bx = m.r32((s.bp+0x0000076cu));
  }
  L00765bdb: { // 0x765bdb: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00765bdd: { // 0x765bdd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765bde: { // 0x765bde: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00765be0: { // 0x765be0: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00765be2: { // 0x765be2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765be3: { // 0x765be3: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765be5: { // 0x765be5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765be6: { // 0x765be6: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00765bea: { // 0x765bea: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756781u); flags=s.arithmetic_flags;
  }
  L00765bed: { // 0x765bed: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765bf0: { // 0x765bf0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765bf2: { // 0x765bf2: 755d JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765bf4: { // 0x765bf4: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00765bf7: { // 0x765bf7: 895f20 MOV dword ptr [EDI + 0x20],EBX
    m.w32((s.di+0x00000020u), s.bx);
  }
  L00765bfa: { // 0x765bfa: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00765bfd: { // 0x765bfd: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00765c00: { // 0x765c00: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00765c08: { // 0x765c08: 7309 JNC 0x00765c13
    if(integer::condition("JNC",flags)) goto L00765c13;
  }
  L00765c0a: { // 0x765c0a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00765c0e: { // 0x765c0e: c644300180 MOV byte ptr [EAX + ESI*0x1 + 0x1],0x80
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00765c13: { // 0x765c13: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765c17: { // 0x765c17: 83481420 OR dword ptr [EAX + 0x14],0x20
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000020u),32,flags));
  }
  L00765c1b: { // 0x765c1b: eb12 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765c1d: { // 0x765c1d: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765c1f: { // 0x765c1f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765c20: { // 0x765c20: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00765c22: { // 0x765c22: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00765c24: { // 0x765c24: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765c25: { // 0x765c25: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756840u); flags=s.arithmetic_flags;
  }
  L00765c28: { // 0x765c28: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c2b: { // 0x765c2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765c2d: { // 0x765c2d: 7531 JNZ 0x00765c60
    if(integer::condition("JNZ",flags)) goto L00765c60;
  }
  L00765c2f: { // 0x765c2f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00765c33: { // 0x765c33: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00765c37: { // 0x765c37: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00765c39: { // 0x765c39: 7334 JNC 0x00765c6f
    if(integer::condition("JNC",flags)) goto L00765c6f;
  }
  L00765c3b: { // 0x765c3b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00765c3d: { // 0x765c3d: e9b3fbffff JMP 0x007657f5
    goto L007657f5;
  }
  L00765c42: { // 0x765c42: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c43: { // 0x765c43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c44: { // 0x765c44: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c45: { // 0x765c45: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00765c4a: { // 0x765c4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c4b: { // 0x765c4b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c4e: { // 0x765c4e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00765c51: { // 0x765c51: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c52: { // 0x765c52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c53: { // 0x765c53: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c54: { // 0x765c54: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765c59: { // 0x765c59: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c5a: { // 0x765c5a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c5d: { // 0x765c5d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00765c60: { // 0x765c60: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c61: { // 0x765c61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c62: { // 0x765c62: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c63: { // 0x765c63: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  L00765c68: { // 0x765c68: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c69: { // 0x765c69: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c6c: { // 0x765c6c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00765c6f: { // 0x765c6f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c70: { // 0x765c70: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c71: { // 0x765c71: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c72: { // 0x765c72: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00765c75: { // 0x765c75: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c76: { // 0x765c76: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c79: { // 0x765c79: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00364290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00764290: { // 0x764290: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00764293: { // 0x764293: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764294: { // 0x764294: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764295: { // 0x764295: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00764297: { // 0x764297: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764298: { // 0x764298: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0076429a: { // 0x76429a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076429b: { // 0x76429b: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007642a1: { // 0x7642a1: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L007642a7: { // 0x7642a7: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007642a9: { // 0x7642a9: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L007642ad: { // 0x7642ad: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L007642af: { // 0x7642af: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L007642b3: { // 0x7642b3: 88542413 MOV byte ptr [ESP + 0x13],DL
    m.w8((f.sp+0x00000013u), (s.dx & 0xffu));
  }
  L007642b7: { // 0x7642b7: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L007642bb: { // 0x7642bb: 0f8410020000 JZ 0x007644d1
    if(integer::condition("JZ",flags)) goto L007644d1;
  }
  L007642c1: { // 0x7642c1: 8b8d24010000 MOV ECX,dword ptr [EBP + 0x124]
    s.cx = m.r32((s.bp+0x00000124u));
  }
  L007642c7: { // 0x7642c7: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L007642c9: { // 0x7642c9: 7f09 JG 0x007642d4
    if(integer::condition("JG",flags)) goto L007642d4;
  }
  L007642cb: { // 0x7642cb: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L007642ce: { // 0x7642ce: 0f85fd010000 JNZ 0x007644d1
    if(integer::condition("JNZ",flags)) goto L007644d1;
  }
  L007642d4: { // 0x7642d4: 8b8d2c010000 MOV ECX,dword ptr [EBP + 0x12c]
    s.cx = m.r32((s.bp+0x0000012cu));
  }
  L007642da: { // 0x7642da: 8bb580010000 MOV ESI,dword ptr [EBP + 0x180]
    s.si = m.r32((s.bp+0x00000180u));
  }
  L007642e0: { // 0x7642e0: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L007642e2: { // 0x7642e2: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L007642e6: { // 0x7642e6: 0f8ee5010000 JLE 0x007644d1
    if(integer::condition("JLE",flags)) goto L007644d1;
  }
  L007642ec: { // 0x7642ec: 8b9d30010000 MOV EBX,dword ptr [EBP + 0x130]
    s.bx = m.r32((s.bp+0x00000130u));
  }
  L007642f2: { // 0x7642f2: 8b851c010000 MOV EAX,dword ptr [EBP + 0x11c]
    s.ax = m.r32((s.bp+0x0000011cu));
  }
  L007642f8: { // 0x7642f8: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L007642fb: { // 0x7642fb: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L007642ff: { // 0x7642ff: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00764303: { // 0x764303: 7416 JZ 0x0076431b
    if(integer::condition("JZ",flags)) goto L0076431b;
  }
  L00764305: { // 0x764305: 899d2c010000 MOV dword ptr [EBP + 0x12c],EBX
    m.w32((s.bp+0x0000012cu), s.bx);
  }
  L0076430b: { // 0x76430b: c78530010000ffffffff MOV dword ptr [EBP + 0x130],0xffffffff
    m.w32((s.bp+0x00000130u), 0xffffffffu);
  }
  L00764315: { // 0x764315: 899d1c010000 MOV dword ptr [EBP + 0x11c],EBX
    m.w32((s.bp+0x0000011cu), s.bx);
  }
  L0076431b: { // 0x76431b: 8b8528010000 MOV EAX,dword ptr [EBP + 0x128]
    s.ax = m.r32((s.bp+0x00000128u));
  }
  L00764321: { // 0x764321: 8b8d80010000 MOV ECX,dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L00764327: { // 0x764327: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00764329: { // 0x764329: 0f8422010000 JZ 0x00764451
    if(integer::condition("JZ",flags)) goto L00764451;
  }
  L0076432f: { // 0x76432f: 898580010000 MOV dword ptr [EBP + 0x180],EAX
    m.w32((s.bp+0x00000180u), s.ax);
  }
  L00764335: { // 0x764335: 8b8d70010000 MOV ECX,dword ptr [EBP + 0x170]
    s.cx = m.r32((s.bp+0x00000170u));
  }
  L0076433b: { // 0x76433b: 8bb528010000 MOV ESI,dword ptr [EBP + 0x128]
    s.si = m.r32((s.bp+0x00000128u));
  }
  L00764341: { // 0x764341: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00764346: { // 0x764346: f6411401 TEST byte ptr [ECX + 0x14],0x1
    (void)integer::logical((m.r8((s.cx+0x00000014u)))&(0x00000001u),8,flags);
  }
  L0076434a: { // 0x76434a: 740a JZ 0x00764356
    if(integer::condition("JZ",flags)) goto L00764356;
  }
  L0076434c: { // 0x76434c: b8f7ffffff MOV EAX,0xfffffff7
    s.ax = 0xfffffff7u;
  }
  L00764351: { // 0x764351: e9d2000000 JMP 0x00764428
    goto L00764428;
  }
  L00764356: { // 0x764356: 3bb51c010000 CMP ESI,dword ptr [EBP + 0x11c]
    (void)integer::sub(s.si,m.r32((s.bp+0x0000011cu)),32,flags);
  }
  L0076435c: { // 0x76435c: 7d1c JGE 0x0076437a
    if(integer::condition("JGE",flags)) goto L0076437a;
  }
  L0076435e: { // 0x76435e: 8b8564070000 MOV EAX,dword ptr [EBP + 0x764]
    s.ax = m.r32((s.bp+0x00000764u));
  }
  L00764364: { // 0x764364: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764366: { // 0x764366: 7412 JZ 0x0076437a
    if(integer::condition("JZ",flags)) goto L0076437a;
  }
  L00764368: { // 0x764368: f6858400000001 TEST byte ptr [EBP + 0x84],0x1
    (void)integer::logical((m.r8((s.bp+0x00000084u)))&(0x00000001u),8,flags);
  }
  L0076436f: { // 0x76436f: 7413 JZ 0x00764384
    if(integer::condition("JZ",flags)) goto L00764384;
  }
  L00764371: { // 0x764371: f685ea00000008 TEST byte ptr [EBP + 0xea],0x8
    (void)integer::logical((m.r8((s.bp+0x000000eau)))&(0x00000008u),8,flags);
  }
  L00764378: { // 0x764378: 750a JNZ 0x00764384
    if(integer::condition("JNZ",flags)) goto L00764384;
  }
  L0076437a: { // 0x76437a: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  L0076437f: { // 0x76437f: e9a4000000 JMP 0x00764428
    goto L00764428;
  }
  L00764384: { // 0x764384: 8a8508010000 MOV AL,byte ptr [EBP + 0x108]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000108u)));
  }
  L0076438a: { // 0x76438a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076438c: { // 0x76438c: 7551 JNZ 0x007643df
    if(integer::condition("JNZ",flags)) goto L007643df;
  }
  L0076438e: { // 0x76438e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00764390: { // 0x764390: 744d JZ 0x007643df
    if(integer::condition("JZ",flags)) goto L007643df;
  }
  L00764392: { // 0x764392: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764394: { // 0x764394: 668b8514070000 MOV AX,word ptr [EBP + 0x714]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000714u)));
  }
  L0076439b: { // 0x76439b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076439d: { // 0x76439d: 7e2a JLE 0x007643c9
    if(integer::condition("JLE",flags)) goto L007643c9;
  }
  L0076439f: { // 0x76439f: f6851607000003 TEST byte ptr [EBP + 0x716],0x3
    (void)integer::logical((m.r8((s.bp+0x00000716u)))&(0x00000003u),8,flags);
  }
  L007643a6: { // 0x7643a6: 7421 JZ 0x007643c9
    if(integer::condition("JZ",flags)) goto L007643c9;
  }
  L007643a8: { // 0x7643a8: 8b951c070000 MOV EDX,dword ptr [EBP + 0x71c]
    s.dx = m.r32((s.bp+0x0000071cu));
  }
  L007643ae: { // 0x7643ae: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L007643b0: { // 0x7643b0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007643b2: { // 0x7643b2: 7e15 JLE 0x007643c9
    if(integer::condition("JLE",flags)) goto L007643c9;
  }
  L007643b4: { // 0x7643b4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L007643b6: { // 0x7643b6: 668b1a MOV BX,word ptr [EDX]
    s.bx = with_ax(s.bx, m.r16((s.dx)));
  }
  L007643b9: { // 0x7643b9: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L007643bb: { // 0x7643bb: 741e JZ 0x007643db
    if(integer::condition("JZ",flags)) goto L007643db;
  }
  L007643bd: { // 0x7643bd: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007643be: { // 0x7643be: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L007643c1: { // 0x7643c1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007643c3: { // 0x7643c3: 7cef JL 0x007643b4
    if(integer::condition("JL",flags)) goto L007643b4;
  }
  L007643c5: { // 0x7643c5: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007643c9: { // 0x7643c9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L007643cb: { // 0x7643cb: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L007643cd: { // 0x7643cd: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007643cf: { // 0x7643cf: e8ac0c0000 CALL 0x00765080
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765080u,7750612u); flags=s.arithmetic_flags;
  }
  L007643d4: { // 0x7643d4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007643d7: { // 0x7643d7: 7521 JNZ 0x007643fa
    if(integer::condition("JNZ",flags)) goto L007643fa;
  }
  L007643d9: { // 0x7643d9: eb04 JMP 0x007643df
    goto L007643df;
  }
  L007643db: { // 0x7643db: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007643df: { // 0x7643df: 8d542413 LEA EDX,[ESP + 0x13]
    s.dx = (f.sp+0x00000013u);
  }
  L007643e3: { // 0x7643e3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007643e5: { // 0x7643e5: 8a85f5000000 MOV AL,byte ptr [EBP + 0xf5]
    s.ax = with_al(s.ax, m.r8((s.bp+0x000000f5u)));
  }
  L007643eb: { // 0x7643eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007643ec: { // 0x7643ec: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007643ee: { // 0x7643ee: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007643f0: { // 0x7643f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007643f1: { // 0x7643f1: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L007643f3: { // 0x7643f3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007643f5: { // 0x7643f5: e8960e0000 CALL 0x00765290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765290u,7750650u); flags=s.arithmetic_flags;
  }
  L007643fa: { // 0x7643fa: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007643fd: { // 0x7643fd: 89b580010000 MOV dword ptr [EBP + 0x180],ESI
    m.w32((s.bp+0x00000180u), s.si);
  }
  L00764403: { // 0x764403: 751e JNZ 0x00764423
    if(integer::condition("JNZ",flags)) goto L00764423;
  }
  L00764405: { // 0x764405: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00764409: { // 0x764409: ba20000000 MOV EDX,0x20
    s.dx = 0x00000020u;
  }
  L0076440e: { // 0x76440e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00764410: { // 0x764410: 7405 JZ 0x00764417
    if(integer::condition("JZ",flags)) goto L00764417;
  }
  L00764412: { // 0x764412: ba30000000 MOV EDX,0x30
    s.dx = 0x00000030u;
  }
  L00764417: { // 0x764417: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764419: { // 0x764419: e8a2fbffff CALL 0x00763fc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763fc0u,7750686u); flags=s.arithmetic_flags;
  }
  L0076441e: { // 0x76441e: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764421: { // 0x764421: 7431 JZ 0x00764454
    if(integer::condition("JZ",flags)) goto L00764454;
  }
  L00764423: { // 0x764423: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L00764426: { // 0x764426: 742c JZ 0x00764454
    if(integer::condition("JZ",flags)) goto L00764454;
  }
  L00764428: { // 0x764428: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0076442c: { // 0x76442c: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00764430: { // 0x764430: 898d2c010000 MOV dword ptr [EBP + 0x12c],ECX
    m.w32((s.bp+0x0000012cu), s.cx);
  }
  L00764436: { // 0x764436: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764437: { // 0x764437: 899d30010000 MOV dword ptr [EBP + 0x130],EBX
    m.w32((s.bp+0x00000130u), s.bx);
  }
  L0076443d: { // 0x76443d: 89951c010000 MOV dword ptr [EBP + 0x11c],EDX
    m.w32((s.bp+0x0000011cu), s.dx);
  }
  L00764443: { // 0x764443: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764444: { // 0x764444: 898d80010000 MOV dword ptr [EBP + 0x180],ECX
    m.w32((s.bp+0x00000180u), s.cx);
  }
  L0076444a: { // 0x76444a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076444b: { // 0x76444b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076444c: { // 0x76444c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076444d: { // 0x76444d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764450: { // 0x764450: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764451: { // 0x764451: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00764454: { // 0x764454: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L0076445a: { // 0x76445a: 80ca80 OR DL,0x80
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|(0x00000080u),8,flags));
  }
  L0076445d: { // 0x76445d: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L00764460: { // 0x764460: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L00764466: { // 0x764466: 7529 JNZ 0x00764491
    if(integer::condition("JNZ",flags)) goto L00764491;
  }
  L00764468: { // 0x764468: 8b7714 MOV ESI,dword ptr [EDI + 0x14]
    s.si = m.r32((s.di+0x00000014u));
  }
  L0076446b: { // 0x76446b: 81ce00010000 OR ESI,0x100
    s.si = integer::logical((s.si)|(0x00000100u),32,flags);
  }
  L00764471: { // 0x764471: 897714 MOV dword ptr [EDI + 0x14],ESI
    m.w32((s.di+0x00000014u), s.si);
  }
  L00764474: { // 0x764474: 8b8d24010000 MOV ECX,dword ptr [EBP + 0x124]
    s.cx = m.r32((s.bp+0x00000124u));
  }
  L0076447a: { // 0x76447a: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0076447c: { // 0x76447c: 0f844b0b0000 JZ 0x00764fcd
    if(integer::condition("JZ",flags)) goto L00764fcd;
  }
  L00764482: { // 0x764482: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00764483: { // 0x764483: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764484: { // 0x764484: 898d24010000 MOV dword ptr [EBP + 0x124],ECX
    m.w32((s.bp+0x00000124u), s.cx);
  }
  L0076448a: { // 0x76448a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076448b: { // 0x76448b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076448c: { // 0x76448c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076448d: { // 0x76448d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764490: { // 0x764490: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764491: { // 0x764491: 8b5714 MOV EDX,dword ptr [EDI + 0x14]
    s.dx = m.r32((s.di+0x00000014u));
  }
  L00764494: { // 0x764494: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00764498: { // 0x764498: 80ce02 OR DH,0x2
    s.dx = (s.dx & 0xffff00ffu) | (((integer::logical((((s.dx >> 8) & 0xffu))|(0x00000002u),8,flags)) & 0xffu) << 8);
  }
  L0076449b: { // 0x76449b: 895714 MOV dword ptr [EDI + 0x14],EDX
    m.w32((s.di+0x00000014u), s.dx);
  }
  L0076449e: { // 0x76449e: 8b9534010000 MOV EDX,dword ptr [EBP + 0x134]
    s.dx = m.r32((s.bp+0x00000134u));
  }
  L007644a4: { // 0x7644a4: 898d40010000 MOV dword ptr [EBP + 0x140],ECX
    m.w32((s.bp+0x00000140u), s.cx);
  }
  L007644aa: { // 0x7644aa: 8b8d50010000 MOV ECX,dword ptr [EBP + 0x150]
    s.cx = m.r32((s.bp+0x00000150u));
  }
  L007644b0: { // 0x7644b0: 80cd01 OR CH,0x1
    s.cx = (s.cx & 0xffff00ffu) | (((integer::logical((((s.cx >> 8) & 0xffu))|(0x00000001u),8,flags)) & 0xffu) << 8);
  }
  L007644b3: { // 0x7644b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007644b4: { // 0x7644b4: 899524010000 MOV dword ptr [EBP + 0x124],EDX
    m.w32((s.bp+0x00000124u), s.dx);
  }
  L007644ba: { // 0x7644ba: c78534010000ffffffff MOV dword ptr [EBP + 0x134],0xffffffff
    m.w32((s.bp+0x00000134u), 0xffffffffu);
  }
  L007644c4: { // 0x7644c4: 898d50010000 MOV dword ptr [EBP + 0x150],ECX
    m.w32((s.bp+0x00000150u), s.cx);
  }
  L007644ca: { // 0x7644ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007644cb: { // 0x7644cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007644cc: { // 0x7644cc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007644cd: { // 0x7644cd: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007644d0: { // 0x7644d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007644d1: { // 0x7644d1: 8b8d80010000 MOV ECX,dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L007644d7: { // 0x7644d7: 8bb51c010000 MOV ESI,dword ptr [EBP + 0x11c]
    s.si = m.r32((s.bp+0x0000011cu));
  }
  L007644dd: { // 0x7644dd: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L007644df: { // 0x7644df: 7e5f JLE 0x00764540
    if(integer::condition("JLE",flags)) goto L00764540;
  }
  L007644e1: { // 0x7644e1: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L007644e4: { // 0x7644e4: 754d JNZ 0x00764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007644e6: { // 0x7644e6: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007644e8: { // 0x7644e8: 7449 JZ 0x00764533
    if(integer::condition("JZ",flags)) goto L00764533;
  }
  L007644ea: { // 0x7644ea: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007644ec: { // 0x7644ec: 7545 JNZ 0x00764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007644ee: { // 0x7644ee: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007644f0: { // 0x7644f0: e82bd9ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7750901u); flags=s.arithmetic_flags;
  }
  L007644f5: { // 0x7644f5: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L007644f8: { // 0x7644f8: 751b JNZ 0x00764515
    if(integer::condition("JNZ",flags)) goto L00764515;
  }
  L007644fa: { // 0x7644fa: 8b8550010000 MOV EAX,dword ptr [EBP + 0x150]
    s.ax = m.r32((s.bp+0x00000150u));
  }
  L00764500: { // 0x764500: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764501: { // 0x764501: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00764503: { // 0x764503: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764504: { // 0x764504: 898550010000 MOV dword ptr [EBP + 0x150],EAX
    m.w32((s.bp+0x00000150u), s.ax);
  }
  L0076450a: { // 0x76450a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076450b: { // 0x76450b: b8f5ffffff MOV EAX,0xfffffff5
    s.ax = 0xfffffff5u;
  }
  L00764510: { // 0x764510: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764511: { // 0x764511: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764514: { // 0x764514: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764515: { // 0x764515: 8b8d50010000 MOV ECX,dword ptr [EBP + 0x150]
    s.cx = m.r32((s.bp+0x00000150u));
  }
  L0076451b: { // 0x76451b: 8b85bc070000 MOV EAX,dword ptr [EBP + 0x7bc]
    s.ax = m.r32((s.bp+0x000007bcu));
  }
  L00764521: { // 0x764521: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L00764524: { // 0x764524: 80cc01 OR AH,0x1
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000001u),8,flags)) & 0xffu) << 8);
  }
  L00764527: { // 0x764527: 898d50010000 MOV dword ptr [EBP + 0x150],ECX
    m.w32((s.bp+0x00000150u), s.cx);
  }
  L0076452d: { // 0x76452d: 8985bc070000 MOV dword ptr [EBP + 0x7bc],EAX
    m.w32((s.bp+0x000007bcu), s.ax);
  }
  L00764533: { // 0x764533: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764534: { // 0x764534: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764535: { // 0x764535: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764536: { // 0x764536: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L0076453b: { // 0x76453b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076453c: { // 0x76453c: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0076453f: { // 0x76453f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764540: { // 0x764540: 8b4714 MOV EAX,dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L00764543: { // 0x764543: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00764545: { // 0x764545: 741f JZ 0x00764566
    if(integer::condition("JZ",flags)) goto L00764566;
  }
  L00764547: { // 0x764547: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0076454a: { // 0x76454a: 751a JNZ 0x00764566
    if(integer::condition("JNZ",flags)) goto L00764566;
  }
  L0076454c: { // 0x76454c: 8b8588010000 MOV EAX,dword ptr [EBP + 0x188]
    s.ax = m.r32((s.bp+0x00000188u));
  }
  L00764552: { // 0x764552: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764553: { // 0x764553: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764554: { // 0x764554: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764555: { // 0x764555: 898588010000 MOV dword ptr [EBP + 0x188],EAX
    m.w32((s.bp+0x00000188u), s.ax);
  }
  L0076455b: { // 0x76455b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076455c: { // 0x76455c: b8f7ffffff MOV EAX,0xfffffff7
    s.ax = 0xfffffff7u;
  }
  L00764561: { // 0x764561: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764562: { // 0x764562: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764565: { // 0x764565: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764566: { // 0x764566: f6855001000001 TEST byte ptr [EBP + 0x150],0x1
    (void)integer::logical((m.r8((s.bp+0x00000150u)))&(0x00000001u),8,flags);
  }
  L0076456d: { // 0x76456d: 750f JNZ 0x0076457e
    if(integer::condition("JNZ",flags)) goto L0076457e;
  }
  L0076456f: { // 0x76456f: 899590010000 MOV dword ptr [EBP + 0x190],EDX
    m.w32((s.bp+0x00000190u), s.dx);
  }
  L00764575: { // 0x764575: 8b9568010000 MOV EDX,dword ptr [EBP + 0x168]
    s.dx = m.r32((s.bp+0x00000168u));
  }
  L0076457b: { // 0x76457b: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L0076457e: { // 0x76457e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00764582: { // 0x764582: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764587: { // 0x764587: f6855001000001 TEST byte ptr [EBP + 0x150],0x1
    (void)integer::logical((m.r8((s.bp+0x00000150u)))&(0x00000001u),8,flags);
  }
  L0076458e: { // 0x76458e: 7550 JNZ 0x007645e0
    if(integer::condition("JNZ",flags)) goto L007645e0;
  }
  L00764590: { // 0x764590: 8db598010000 LEA ESI,[EBP + 0x198]
    s.si = (s.bp+0x00000198u);
  }
  L00764596: { // 0x764596: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00764598: { // 0x764598: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764599: { // 0x764599: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0076459b: { // 0x76459b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076459c: { // 0x76459c: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7751071u); flags=s.arithmetic_flags;
  }
  L0076459f: { // 0x76459f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007645a2: { // 0x7645a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007645a4: { // 0x7645a4: 758d JNZ 0x00764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007645a6: { // 0x7645a6: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L007645a9: { // 0x7645a9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007645ab: { // 0x7645ab: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L007645ad: { // 0x7645ad: 81e10000ff00 AND ECX,0xff0000
    s.cx = integer::logical((s.cx)&(0x00ff0000u),32,flags);
  }
  L007645b3: { // 0x7645b3: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L007645b6: { // 0x7645b6: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L007645b8: { // 0x7645b8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L007645ba: { // 0x7645ba: c1e210 SHL EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::left);
  }
  L007645bd: { // 0x7645bd: 2500ff0000 AND EAX,0xff00
    s.ax = integer::logical((s.ax)&(0x0000ff00u),32,flags);
  }
  L007645c2: { // 0x7645c2: 0bd0 OR EDX,EAX
    s.dx = integer::logical((s.dx)|(s.ax),32,flags);
  }
  L007645c4: { // 0x7645c4: c1e908 SHR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::right);
  }
  L007645c7: { // 0x7645c7: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L007645ca: { // 0x7645ca: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L007645cc: { // 0x7645cc: 890d2804b100 MOV dword ptr [0x00b10428],ECX
    m.w32((0x00b10428u), s.cx);
  }
  L007645d2: { // 0x7645d2: 8b8590010000 MOV EAX,dword ptr [EBP + 0x190]
    s.ax = m.r32((s.bp+0x00000190u));
  }
  L007645d8: { // 0x7645d8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L007645da: { // 0x7645da: 898590010000 MOV dword ptr [EBP + 0x190],EAX
    m.w32((s.bp+0x00000190u), s.ax);
  }
  L007645e0: { // 0x7645e0: 8b8598010000 MOV EAX,dword ptr [EBP + 0x198]
    s.ax = m.r32((s.bp+0x00000198u));
  }
  L007645e6: { // 0x7645e6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L007645e8: { // 0x7645e8: 3d5651464b CMP EAX,0x4b465156
    (void)integer::sub(s.ax,0x4b465156u,32,flags);
  }
  L007645ed: { // 0x7645ed: 0f8728040000 JA 0x00764a1b
    if(integer::condition("JA",flags)) goto L00764a1b;
  }
  L007645f3: { // 0x7645f3: 0f84eb030000 JZ 0x007649e4
    if(integer::condition("JZ",flags)) goto L007649e4;
  }
  L007645f9: { // 0x7645f9: 3d534e4131 CMP EAX,0x31414e53
    (void)integer::sub(s.ax,0x31414e53u,32,flags);
  }
  L007645fe: { // 0x7645fe: 0f87f0010000 JA 0x007647f4
    if(integer::condition("JA",flags)) goto L007647f4;
  }
  L00764604: { // 0x764604: 0f84c7010000 JZ 0x007647d1
    if(integer::condition("JZ",flags)) goto L007647d1;
  }
  L0076460a: { // 0x76460a: 3d43504c30 CMP EAX,0x304c5043
    (void)integer::sub(s.ax,0x304c5043u,32,flags);
  }
  L0076460f: { // 0x76460f: 0f8788010000 JA 0x0076479d
    if(integer::condition("JA",flags)) goto L0076479d;
  }
  L00764615: { // 0x764615: 0f84f2000000 JZ 0x0076470d
    if(integer::condition("JZ",flags)) goto L0076470d;
  }
  L0076461b: { // 0x76461b: 3d534e4130 CMP EAX,0x30414e53
    (void)integer::sub(s.ax,0x30414e53u,32,flags);
  }
  L00764620: { // 0x764620: 0f84c4000000 JZ 0x007646ea
    if(integer::condition("JZ",flags)) goto L007646ea;
  }
  L00764626: { // 0x764626: 3d534e4430 CMP EAX,0x30444e53
    (void)integer::sub(s.ax,0x30444e53u,32,flags);
  }
  L0076462b: { // 0x76462b: 7462 JZ 0x0076468f
    if(integer::condition("JZ",flags)) goto L0076468f;
  }
  L0076462d: { // 0x76462d: 3d43424630 CMP EAX,0x30464243
    (void)integer::sub(s.ax,0x30464243u,32,flags);
  }
  L00764632: { // 0x764632: 0f854a060000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764638: { // 0x764638: f644241410 TEST byte ptr [ESP + 0x14],0x10
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000010u),8,flags);
  }
  L0076463d: { // 0x76463d: 0f8565080000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764643: { // 0x764643: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764648: { // 0x764648: 8bb564010000 MOV ESI,dword ptr [EBP + 0x164]
    s.si = m.r32((s.bp+0x00000164u));
  }
  L0076464e: { // 0x76464e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00764650: { // 0x764650: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764651: { // 0x764651: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764653: { // 0x764653: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764654: { // 0x764654: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00764656: { // 0x764656: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764657: { // 0x764657: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764659: { // 0x764659: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076465a: { // 0x76465a: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7751261u); flags=s.arithmetic_flags;
  }
  L0076465d: { // 0x76465d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764660: { // 0x764660: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764662: { // 0x764662: 0f8581080000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764668: { // 0x764668: 898574010000 MOV dword ptr [EBP + 0x174],EAX
    m.w32((s.bp+0x00000174u), s.ax);
  }
  L0076466e: { // 0x76466e: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00764671: { // 0x764671: 897e14 MOV dword ptr [ESI + 0x14],EDI
    m.w32((s.si+0x00000014u), s.di);
  }
  L00764674: { // 0x764674: c7460c08000000 MOV dword ptr [ESI + 0xc],0x8
    m.w32((s.si+0x0000000cu), 0x00000008u);
  }
  L0076467b: { // 0x76467b: 89b568010000 MOV dword ptr [EBP + 0x168],ESI
    m.w32((s.bp+0x00000168u), s.si);
  }
  L00764681: { // 0x764681: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00764684: { // 0x764684: 898d64010000 MOV dword ptr [EBP + 0x164],ECX
    m.w32((s.bp+0x00000164u), s.cx);
  }
  L0076468a: { // 0x76468a: e9f3feffff JMP 0x00764582
    goto L00764582;
  }
  L0076468f: { // 0x76468f: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L00764694: { // 0x764694: 0f850e080000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L0076469a: { // 0x76469a: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007646a0: { // 0x7646a0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007646a2: { // 0x7646a2: 0f8400080000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007646a8: { // 0x7646a8: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007646aa: { // 0x7646aa: 0f85f8070000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007646b0: { // 0x7646b0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007646b2: { // 0x7646b2: e869d7ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7751351u); flags=s.arithmetic_flags;
  }
  L007646b7: { // 0x7646b7: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L007646ba: { // 0x7646ba: 0f840e080000 JZ 0x00764ece
    if(integer::condition("JZ",flags)) goto L00764ece;
  }
  L007646c0: { // 0x7646c0: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L007646c6: { // 0x7646c6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007646c8: { // 0x7646c8: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L007646cb: { // 0x7646cb: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L007646d1: { // 0x7646d1: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007646d7: { // 0x7646d7: e8f4250000 CALL 0x00766cd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766cd0u,7751388u); flags=s.arithmetic_flags;
  }
  L007646dc: { // 0x7646dc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007646df: { // 0x7646df: 0f8504080000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L007646e5: { // 0x7646e5: e99dfeffff JMP 0x00764587
    goto L00764587;
  }
  L007646ea: { // 0x7646ea: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L007646ef: { // 0x7646ef: 0f85b3070000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007646f5: { // 0x7646f5: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007646fb: { // 0x7646fb: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007646fd: { // 0x7646fd: 0f84a5070000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764703: { // 0x764703: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00764705: { // 0x764705: 0f849d070000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L0076470b: { // 0x76470b: eba3 JMP 0x007646b0
    goto L007646b0;
  }
  L0076470d: { // 0x76470d: f644241401 TEST byte ptr [ESP + 0x14],0x1
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000001u),8,flags);
  }
  L00764712: { // 0x764712: 0f8590070000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764718: { // 0x764718: 8b352804b100 MOV ESI,dword ptr [0x00b10428]
    s.si = m.r32((0x00b10428u));
  }
  L0076471e: { // 0x76471e: 8b9d70010000 MOV EBX,dword ptr [EBP + 0x170]
    s.bx = m.r32((s.bp+0x00000170u));
  }
  L00764724: { // 0x764724: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L00764727: { // 0x764727: 8d5601 LEA EDX,[ESI + 0x1]
    s.dx = (s.si+0x00000001u);
  }
  L0076472a: { // 0x76472a: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L0076472d: { // 0x76472d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0076472e: { // 0x76472e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076472f: { // 0x76472f: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764731: { // 0x764731: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764732: { // 0x764732: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7751477u); flags=s.arithmetic_flags;
  }
  L00764735: { // 0x764735: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764738: { // 0x764738: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076473a: { // 0x76473a: 0f85a9070000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764740: { // 0x764740: 8b4b14 MOV ECX,dword ptr [EBX + 0x14]
    s.cx = m.r32((s.bx+0x00000014u));
  }
  L00764743: { // 0x764743: 894324 MOV dword ptr [EBX + 0x24],EAX
    m.w32((s.bx+0x00000024u), s.ax);
  }
  L00764746: { // 0x764746: 83e1f7 AND ECX,0xfffffff7
    s.cx = integer::logical((s.cx)&(0xfffffff7u),32,flags);
  }
  L00764749: { // 0x764749: 897328 MOV dword ptr [EBX + 0x28],ESI
    m.w32((s.bx+0x00000028u), s.si);
  }
  L0076474c: { // 0x76474c: 894b14 MOV dword ptr [EBX + 0x14],ECX
    m.w32((s.bx+0x00000014u), s.cx);
  }
  L0076474f: { // 0x76474f: 6683bd5807000001 CMP word ptr [EBP + 0x758],0x1
    (void)integer::sub(m.r16((s.bp+0x00000758u)),0x00000001u,16,flags);
  }
  L00764757: { // 0x764757: 7530 JNZ 0x00764789
    if(integer::condition("JNZ",flags)) goto L00764789;
  }
  L00764759: { // 0x764759: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0076475b: { // 0x76475b: 8b7308 MOV ESI,dword ptr [EBX + 0x8]
    s.si = m.r32((s.bx+0x00000008u));
  }
  L0076475e: { // 0x76475e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00764760: { // 0x764760: 8dbdc4010000 LEA EDI,[EBP + 0x1c4]
    s.di = (s.bp+0x000001c4u);
  }
  L00764766: { // 0x764766: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L00764769: { // 0x764769: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076476b: { // 0x76476b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0076476d: { // 0x76476d: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L00764770: { // 0x764770: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00764772: { // 0x764772: 8b4328 MOV EAX,dword ptr [EBX + 0x28]
    s.ax = m.r32((s.bx+0x00000028u));
  }
  L00764775: { // 0x764775: 8985c0010000 MOV dword ptr [EBP + 0x1c0],EAX
    m.w32((s.bp+0x000001c0u), s.ax);
  }
  L0076477b: { // 0x76477b: 8b85a4010000 MOV EAX,dword ptr [EBP + 0x1a4]
    s.ax = m.r32((s.bp+0x000001a4u));
  }
  L00764781: { // 0x764781: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00764783: { // 0x764783: 8985a4010000 MOV dword ptr [EBP + 0x1a4],EAX
    m.w32((s.bp+0x000001a4u), s.ax);
  }
  L00764789: { // 0x764789: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0076478d: { // 0x76478d: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764792: { // 0x764792: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00764794: { // 0x764794: 83481404 OR dword ptr [EAX + 0x14],0x4
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000004u),32,flags));
  }
  L00764798: { // 0x764798: e9eafdffff JMP 0x00764587
    goto L00764587;
  }
  L0076479d: { // 0x76479d: 3d43425030 CMP EAX,0x30504243
    (void)integer::sub(s.ax,0x30504243u,32,flags);
  }
  L007647a2: { // 0x7647a2: 7410 JZ 0x007647b4
    if(integer::condition("JZ",flags)) goto L007647b4;
  }
  L007647a4: { // 0x7647a4: 3d56505430 CMP EAX,0x30545056
    (void)integer::sub(s.ax,0x30545056u,32,flags);
  }
  L007647a9: { // 0x7647a9: 0f84f3010000 JZ 0x007649a2
    if(integer::condition("JZ",flags)) goto L007649a2;
  }
  L007647af: { // 0x7647af: e9ce040000 JMP 0x00764c82
    goto L00764c82;
  }
  L007647b4: { // 0x7647b4: f644241408 TEST byte ptr [ESP + 0x14],0x8
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000008u),8,flags);
  }
  L007647b9: { // 0x7647b9: 0f85e9060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007647bf: { // 0x7647bf: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007647c5: { // 0x7647c5: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007647c7: { // 0x7647c7: e894210000 CALL 0x00766960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766960u,7751628u); flags=s.arithmetic_flags;
  }
  L007647cc: { // 0x7647cc: e90bffffff JMP 0x007646dc
    goto L007646dc;
  }
  L007647d1: { // 0x7647d1: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L007647d6: { // 0x7647d6: 0f85cc060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007647dc: { // 0x7647dc: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007647e2: { // 0x7647e2: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007647e4: { // 0x7647e4: 0f84be060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007647ea: { // 0x7647ea: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007647ec: { // 0x7647ec: 0f84b6060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007647f2: { // 0x7647f2: eb67 JMP 0x0076485b
    goto L0076485b;
  }
  L007647f4: { // 0x7647f4: 3d534e4432 CMP EAX,0x32444e53
    (void)integer::sub(s.ax,0x32444e53u,32,flags);
  }
  L007647f9: { // 0x7647f9: 0f87df000000 JA 0x007648de
    if(integer::condition("JA",flags)) goto L007648de;
  }
  L007647ff: { // 0x7647ff: 0f8487000000 JZ 0x0076488c
    if(integer::condition("JZ",flags)) goto L0076488c;
  }
  L00764805: { // 0x764805: 3d534e4431 CMP EAX,0x31444e53
    (void)integer::sub(s.ax,0x31444e53u,32,flags);
  }
  L0076480a: { // 0x76480a: 742e JZ 0x0076483a
    if(integer::condition("JZ",flags)) goto L0076483a;
  }
  L0076480c: { // 0x76480c: 3d534e4132 CMP EAX,0x32414e53
    (void)integer::sub(s.ax,0x32414e53u,32,flags);
  }
  L00764811: { // 0x764811: 0f856b040000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764817: { // 0x764817: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L0076481c: { // 0x76481c: 0f8586060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764822: { // 0x764822: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L00764828: { // 0x764828: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0076482a: { // 0x76482a: 0f8478060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764830: { // 0x764830: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00764832: { // 0x764832: 0f8470060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764838: { // 0x764838: eb73 JMP 0x007648ad
    goto L007648ad;
  }
  L0076483a: { // 0x76483a: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L0076483f: { // 0x76483f: 0f8563060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764845: { // 0x764845: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L0076484b: { // 0x76484b: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0076484d: { // 0x76484d: 0f8455060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764853: { // 0x764853: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00764855: { // 0x764855: 0f854d060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L0076485b: { // 0x76485b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0076485d: { // 0x76485d: e8bed5ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7751778u); flags=s.arithmetic_flags;
  }
  L00764862: { // 0x764862: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L00764865: { // 0x764865: 0f8463060000 JZ 0x00764ece
    if(integer::condition("JZ",flags)) goto L00764ece;
  }
  L0076486b: { // 0x76486b: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L00764871: { // 0x764871: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764873: { // 0x764873: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00764876: { // 0x764876: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L0076487c: { // 0x76487c: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764882: { // 0x764882: e819250000 CALL 0x00766da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766da0u,7751815u); flags=s.arithmetic_flags;
  }
  L00764887: { // 0x764887: e950feffff JMP 0x007646dc
    goto L007646dc;
  }
  L0076488c: { // 0x76488c: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L00764891: { // 0x764891: 0f8511060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764897: { // 0x764897: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L0076489d: { // 0x76489d: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0076489f: { // 0x76489f: 0f8403060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007648a5: { // 0x7648a5: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007648a7: { // 0x7648a7: 0f85fb050000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007648ad: { // 0x7648ad: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007648af: { // 0x7648af: e86cd5ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7751860u); flags=s.arithmetic_flags;
  }
  L007648b4: { // 0x7648b4: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L007648b7: { // 0x7648b7: 0f8411060000 JZ 0x00764ece
    if(integer::condition("JZ",flags)) goto L00764ece;
  }
  L007648bd: { // 0x7648bd: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L007648c3: { // 0x7648c3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007648c5: { // 0x7648c5: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L007648c8: { // 0x7648c8: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L007648ce: { // 0x7648ce: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007648d4: { // 0x7648d4: e887260000 CALL 0x00766f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766f60u,7751897u); flags=s.arithmetic_flags;
  }
  L007648d9: { // 0x7648d9: e9fefdffff JMP 0x007646dc
    goto L007646dc;
  }
  L007648de: { // 0x7648de: 3d56505444 CMP EAX,0x44545056
    (void)integer::sub(s.ax,0x44545056u,32,flags);
  }
  L007648e3: { // 0x7648e3: 0f84b9000000 JZ 0x007649a2
    if(integer::condition("JZ",flags)) goto L007649a2;
  }
  L007648e9: { // 0x7648e9: 3d534e324a CMP EAX,0x4a324e53
    (void)integer::sub(s.ax,0x4a324e53u,32,flags);
  }
  L007648ee: { // 0x7648ee: 0f858e030000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L007648f4: { // 0x7648f4: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L007648f9: { // 0x7648f9: 0f85a9050000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007648ff: { // 0x7648ff: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L00764905: { // 0x764905: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00764907: { // 0x764907: 0f849b050000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L0076490d: { // 0x76490d: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L0076490f: { // 0x76490f: 0f8593050000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764915: { // 0x764915: 8b0d2804b100 MOV ECX,dword ptr [0x00b10428]
    s.cx = m.r32((0x00b10428u));
  }
  L0076491b: { // 0x76491b: 8d4101 LEA EAX,[ECX + 0x1]
    s.ax = (s.cx+0x00000001u);
  }
  L0076491e: { // 0x76491e: 8a8d84000000 MOV CL,byte ptr [EBP + 0x84]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000084u)));
  }
  L00764924: { // 0x764924: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764926: { // 0x764926: f6c101 TEST CL,0x1
    (void)integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags);
  }
  L00764929: { // 0x764929: 7465 JZ 0x00764990
    if(integer::condition("JZ",flags)) goto L00764990;
  }
  L0076492b: { // 0x76492b: 8b8d8c070000 MOV ECX,dword ptr [EBP + 0x78c]
    s.cx = m.r32((s.bp+0x0000078cu));
  }
  L00764931: { // 0x764931: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00764933: { // 0x764933: 745b JZ 0x00764990
    if(integer::condition("JZ",flags)) goto L00764990;
  }
  L00764935: { // 0x764935: 83f80c CMP EAX,0xc
    (void)integer::sub(s.ax,0x0000000cu,32,flags);
  }
  L00764938: { // 0x764938: 0f87ab050000 JA 0x00764ee9
    if(integer::condition("JA",flags)) goto L00764ee9;
  }
  L0076493e: { // 0x76493e: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00764942: { // 0x764942: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764943: { // 0x764943: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764944: { // 0x764944: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764946: { // 0x764946: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764947: { // 0x764947: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752010u); flags=s.arithmetic_flags;
  }
  L0076494a: { // 0x76494a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076494d: { // 0x76494d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076494f: { // 0x76494f: 0f8594050000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764955: { // 0x764955: 8b442426 MOV EAX,dword ptr [ESP + 0x26]
    s.ax = m.r32((f.sp+0x00000026u));
  }
  L00764959: { // 0x764959: 668b4c2424 MOV CX,word ptr [ESP + 0x24]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000024u)));
  }
  L0076495e: { // 0x76495e: 8985d0070000 MOV dword ptr [EBP + 0x7d0],EAX
    m.w32((s.bp+0x000007d0u), s.ax);
  }
  L00764964: { // 0x764964: 66898dd4070000 MOV word ptr [EBP + 0x7d4],CX
    m.w16((s.bp+0x000007d4u), (s.cx & 0xffffu));
  }
  L0076496b: { // 0x76496b: 807d3e02 CMP byte ptr [EBP + 0x3e],0x2
    (void)integer::sub(m.r8((s.bp+0x0000003eu)),0x00000002u,8,flags);
  }
  L0076496f: { // 0x76496f: 0f8512fcffff JNZ 0x00764587
    if(integer::condition("JNZ",flags)) goto L00764587;
  }
  L00764975: { // 0x764975: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L00764979: { // 0x764979: 668b44242a MOV AX,word ptr [ESP + 0x2a]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002au)));
  }
  L0076497e: { // 0x76497e: 8995d6070000 MOV dword ptr [EBP + 0x7d6],EDX
    m.w32((s.bp+0x000007d6u), s.dx);
  }
  L00764984: { // 0x764984: 668985da070000 MOV word ptr [EBP + 0x7da],AX
    m.w16((s.bp+0x000007dau), (s.ax & 0xffffu));
  }
  L0076498b: { // 0x76498b: e9f7fbffff JMP 0x00764587
    goto L00764587;
  }
  L00764990: { // 0x764990: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764991: { // 0x764991: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00764992: { // 0x764992: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00764994: { // 0x764994: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764995: { // 0x764995: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752088u); flags=s.arithmetic_flags;
  }
  L00764998: { // 0x764998: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076499b: { // 0x76499b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076499d: { // 0x76499d: e93dfdffff JMP 0x007646df
    goto L007646df;
  }
  L007649a2: { // 0x7649a2: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L007649a7: { // 0x7649a7: 0f85f3040000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L007649ad: { // 0x7649ad: 8b0d2804b100 MOV ECX,dword ptr [0x00b10428]
    s.cx = m.r32((0x00b10428u));
  }
  L007649b3: { // 0x7649b3: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L007649b9: { // 0x7649b9: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007649ba: { // 0x7649ba: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L007649bc: { // 0x7649bc: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L007649bf: { // 0x7649bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007649c0: { // 0x7649c0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007649c1: { // 0x7649c1: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007649c3: { // 0x7649c3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007649c4: { // 0x7649c4: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752135u); flags=s.arithmetic_flags;
  }
  L007649c7: { // 0x7649c7: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007649ca: { // 0x7649ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007649cc: { // 0x7649cc: 0f8517050000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L007649d2: { // 0x7649d2: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L007649d5: { // 0x7649d5: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L007649d7: { // 0x7649d7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L007649d9: { // 0x7649d9: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  L007649dc: { // 0x7649dc: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L007649df: { // 0x7649df: e9bc040000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L007649e4: { // 0x7649e4: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007649e8: { // 0x7649e8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L007649ea: { // 0x7649ea: 83e01d AND EAX,0x1d
    s.ax = integer::logical((s.ax)&(0x0000001du),32,flags);
  }
  L007649ed: { // 0x7649ed: 3c1d CMP AL,0x1d
    (void)integer::sub((s.ax & 0xffu),0x0000001du,8,flags);
  }
  L007649ef: { // 0x7649ef: 0f84ab040000 JZ 0x00764ea0
    if(integer::condition("JZ",flags)) goto L00764ea0;
  }
  L007649f5: { // 0x7649f5: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007649fb: { // 0x7649fb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007649fc: { // 0x7649fc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007649fe: { // 0x7649fe: e8cd0d0000 CALL 0x007657d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007657d0u,7752195u); flags=s.arithmetic_flags;
  }
  L00764a03: { // 0x764a03: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764a06: { // 0x764a06: 0f85dd040000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764a0c: { // 0x764a0c: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764a0f: { // 0x764a0f: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L00764a11: { // 0x764a11: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764a13: { // 0x764a13: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764a16: { // 0x764a16: e985040000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764a1b: { // 0x764a1b: 3d4342465a CMP EAX,0x5a464243
    (void)integer::sub(s.ax,0x5a464243u,32,flags);
  }
  L00764a20: { // 0x764a20: 0f876a010000 JA 0x00764b90
    if(integer::condition("JA",flags)) goto L00764b90;
  }
  L00764a26: { // 0x764a26: 0f8447010000 JZ 0x00764b73
    if(integer::condition("JZ",flags)) goto L00764b73;
  }
  L00764a2c: { // 0x764a2c: 3d56514652 CMP EAX,0x52465156
    (void)integer::sub(s.ax,0x52465156u,32,flags);
  }
  L00764a31: { // 0x764a31: 0f87dc000000 JA 0x00764b13
    if(integer::condition("JA",flags)) goto L00764b13;
  }
  L00764a37: { // 0x764a37: 0f84a6000000 JZ 0x00764ae3
    if(integer::condition("JZ",flags)) goto L00764ae3;
  }
  L00764a3d: { // 0x764a3d: 3d5650544b CMP EAX,0x4b545056
    (void)integer::sub(s.ax,0x4b545056u,32,flags);
  }
  L00764a42: { // 0x764a42: 7454 JZ 0x00764a98
    if(integer::condition("JZ",flags)) goto L00764a98;
  }
  L00764a44: { // 0x764a44: 3d5651464c CMP EAX,0x4c465156
    (void)integer::sub(s.ax,0x4c465156u,32,flags);
  }
  L00764a49: { // 0x764a49: 0f8533020000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764a4f: { // 0x764a4f: f644241420 TEST byte ptr [ESP + 0x14],0x20
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000020u),8,flags);
  }
  L00764a54: { // 0x764a54: 0f854e040000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764a5a: { // 0x764a5a: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00764a5e: { // 0x764a5e: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764a64: { // 0x764a64: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00764a65: { // 0x764a65: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764a67: { // 0x764a67: e8640d0000 CALL 0x007657d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007657d0u,7752300u); flags=s.arithmetic_flags;
  }
  L00764a6c: { // 0x764a6c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764a6f: { // 0x764a6f: 0f8574040000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764a75: { // 0x764a75: 8a85ea000000 MOV AL,byte ptr [EBP + 0xea]
    s.ax = with_al(s.ax, m.r8((s.bp+0x000000eau)));
  }
  L00764a7b: { // 0x764a7b: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L00764a80: { // 0x764a80: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00764a82: { // 0x764a82: 0f84fffaffff JZ 0x00764587
    if(integer::condition("JZ",flags)) goto L00764587;
  }
  L00764a88: { // 0x764a88: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764a8d: { // 0x764a8d: 0f8570040000 JNZ 0x00764f03
    if(integer::condition("JNZ",flags)) goto L00764f03;
  }
  L00764a93: { // 0x764a93: e9effaffff JMP 0x00764587
    goto L00764587;
  }
  L00764a98: { // 0x764a98: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764a9d: { // 0x764a9d: 0f85fd030000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764aa3: { // 0x764aa3: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764aa9: { // 0x764aa9: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L00764aaf: { // 0x764aaf: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00764ab0: { // 0x764ab0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00764ab2: { // 0x764ab2: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00764ab5: { // 0x764ab5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764ab6: { // 0x764ab6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764ab7: { // 0x764ab7: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764ab9: { // 0x764ab9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764aba: { // 0x764aba: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752381u); flags=s.arithmetic_flags;
  }
  L00764abd: { // 0x764abd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764ac0: { // 0x764ac0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764ac2: { // 0x764ac2: 0f8521040000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764ac8: { // 0x764ac8: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00764acb: { // 0x764acb: 83e1ef AND ECX,0xffffffef
    s.cx = integer::logical((s.cx)&(0xffffffefu),32,flags);
  }
  L00764ace: { // 0x764ace: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  L00764ad1: { // 0x764ad1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764ad3: { // 0x764ad3: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L00764ad6: { // 0x764ad6: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764ad9: { // 0x764ad9: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L00764adb: { // 0x764adb: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764ade: { // 0x764ade: e9bd030000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764ae3: { // 0x764ae3: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00764ae7: { // 0x764ae7: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00764ae9: { // 0x764ae9: 83e21d AND EDX,0x1d
    s.dx = integer::logical((s.dx)&(0x0000001du),32,flags);
  }
  L00764aec: { // 0x764aec: 80fa1d CMP DL,0x1d
    (void)integer::sub((s.dx & 0xffu),0x0000001du,8,flags);
  }
  L00764aef: { // 0x764aef: 0f84ab030000 JZ 0x00764ea0
    if(integer::condition("JZ",flags)) goto L00764ea0;
  }
  L00764af5: { // 0x764af5: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764afb: { // 0x764afb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764afc: { // 0x764afc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764afe: { // 0x764afe: e8cd0c0000 CALL 0x007657d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007657d0u,7752451u); flags=s.arithmetic_flags;
  }
  L00764b03: { // 0x764b03: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764b06: { // 0x764b06: 0f85dd030000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764b0c: { // 0x764b0c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764b0e: { // 0x764b0e: e98d030000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764b13: { // 0x764b13: 3d56505452 CMP EAX,0x52545056
    (void)integer::sub(s.ax,0x52545056u,32,flags);
  }
  L00764b18: { // 0x764b18: 7410 JZ 0x00764b2a
    if(integer::condition("JZ",flags)) goto L00764b2a;
  }
  L00764b1a: { // 0x764b1a: 3d5650445a CMP EAX,0x5a445056
    (void)integer::sub(s.ax,0x5a445056u,32,flags);
  }
  L00764b1f: { // 0x764b1f: 0f84ad020000 JZ 0x00764dd2
    if(integer::condition("JZ",flags)) goto L00764dd2;
  }
  L00764b25: { // 0x764b25: e958010000 JMP 0x00764c82
    goto L00764c82;
  }
  L00764b2a: { // 0x764b2a: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764b2f: { // 0x764b2f: 0f856b030000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764b35: { // 0x764b35: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764b3a: { // 0x764b3a: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L00764b40: { // 0x764b40: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764b41: { // 0x764b41: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00764b43: { // 0x764b43: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764b45: { // 0x764b45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764b46: { // 0x764b46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00764b47: { // 0x764b47: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764b49: { // 0x764b49: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764b4a: { // 0x764b4a: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752525u); flags=s.arithmetic_flags;
  }
  L00764b4d: { // 0x764b4d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764b50: { // 0x764b50: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764b52: { // 0x764b52: 0f8591030000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764b58: { // 0x764b58: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00764b5b: { // 0x764b5b: 83e1ef AND ECX,0xffffffef
    s.cx = integer::logical((s.cx)&(0xffffffefu),32,flags);
  }
  L00764b5e: { // 0x764b5e: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  L00764b61: { // 0x764b61: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764b63: { // 0x764b63: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L00764b66: { // 0x764b66: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764b69: { // 0x764b69: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  L00764b6b: { // 0x764b6b: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764b6e: { // 0x764b6e: e92d030000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764b73: { // 0x764b73: f644241410 TEST byte ptr [ESP + 0x14],0x10
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000010u),8,flags);
  }
  L00764b78: { // 0x764b78: 0f852a030000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764b7e: { // 0x764b7e: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764b84: { // 0x764b84: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764b86: { // 0x764b86: e8551d0000 CALL 0x007668e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007668e0u,7752587u); flags=s.arithmetic_flags;
  }
  L00764b8b: { // 0x764b8b: e94cfbffff JMP 0x007646dc
    goto L007646dc;
  }
  L00764b90: { // 0x764b90: 3d4342505a CMP EAX,0x5a504243
    (void)integer::sub(s.ax,0x5a504243u,32,flags);
  }
  L00764b95: { // 0x764b95: 0f87d1000000 JA 0x00764c6c
    if(integer::condition("JA",flags)) goto L00764c6c;
  }
  L00764b9b: { // 0x764b9b: 0f84ae000000 JZ 0x00764c4f
    if(integer::condition("JZ",flags)) goto L00764c4f;
  }
  L00764ba1: { // 0x764ba1: 3d56504b5a CMP EAX,0x5a4b5056
    (void)integer::sub(s.ax,0x5a4b5056u,32,flags);
  }
  L00764ba6: { // 0x764ba6: 7439 JZ 0x00764be1
    if(integer::condition("JZ",flags)) goto L00764be1;
  }
  L00764ba8: { // 0x764ba8: 3d43504c5a CMP EAX,0x5a4c5043
    (void)integer::sub(s.ax,0x5a4c5043u,32,flags);
  }
  L00764bad: { // 0x764bad: 0f85cf000000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764bb3: { // 0x764bb3: f644241401 TEST byte ptr [ESP + 0x14],0x1
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000001u),8,flags);
  }
  L00764bb8: { // 0x764bb8: 0f85ea020000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764bbe: { // 0x764bbe: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764bc4: { // 0x764bc4: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764bc6: { // 0x764bc6: e835200000 CALL 0x00766c00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766c00u,7752651u); flags=s.arithmetic_flags;
  }
  L00764bcb: { // 0x764bcb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764bce: { // 0x764bce: 0f8515030000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764bd4: { // 0x764bd4: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764bd7: { // 0x764bd7: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L00764bd9: { // 0x764bd9: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764bdc: { // 0x764bdc: e9a6f9ffff JMP 0x00764587
    goto L00764587;
  }
  L00764be1: { // 0x764be1: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764be6: { // 0x764be6: 0f85b4020000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764bec: { // 0x764bec: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764bf1: { // 0x764bf1: 8bb56c070000 MOV ESI,dword ptr [EBP + 0x76c]
    s.si = m.r32((s.bp+0x0000076cu));
  }
  L00764bf7: { // 0x764bf7: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00764bfd: { // 0x764bfd: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00764c01: { // 0x764c01: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764c02: { // 0x764c02: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00764c04: { // 0x764c04: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764c06: { // 0x764c06: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00764c08: { // 0x764c08: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764c09: { // 0x764c09: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00764c0b: { // 0x764c0b: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00764c0d: { // 0x764c0d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764c0e: { // 0x764c0e: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764c10: { // 0x764c10: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764c11: { // 0x764c11: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752724u); flags=s.arithmetic_flags;
  }
  L00764c14: { // 0x764c14: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764c17: { // 0x764c17: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764c19: { // 0x764c19: 0f85ca020000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764c1f: { // 0x764c1f: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00764c22: { // 0x764c22: 897720 MOV dword ptr [EDI + 0x20],ESI
    m.w32((s.di+0x00000020u), s.si);
  }
  L00764c25: { // 0x764c25: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00764c28: { // 0x764c28: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00764c2b: { // 0x764c2b: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00764c33: { // 0x764c33: 7309 JNC 0x00764c3e
    if(integer::condition("JNC",flags)) goto L00764c3e;
  }
  L00764c35: { // 0x764c35: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00764c39: { // 0x764c39: c644130180 MOV byte ptr [EBX + EDX*0x1 + 0x1],0x80
    m.w8((s.bx+(s.dx * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00764c3e: { // 0x764c3e: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00764c42: { // 0x764c42: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764c44: { // 0x764c44: 8b5014 MOV EDX,dword ptr [EAX + 0x14]
    s.dx = m.r32((s.ax+0x00000014u));
  }
  L00764c47: { // 0x764c47: 83ca02 OR EDX,0x2
    s.dx = integer::logical((s.dx)|(0x00000002u),32,flags);
  }
  L00764c4a: { // 0x764c4a: e945020000 JMP 0x00764e94
    goto L00764e94;
  }
  L00764c4f: { // 0x764c4f: f644241408 TEST byte ptr [ESP + 0x14],0x8
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000008u),8,flags);
  }
  L00764c54: { // 0x764c54: 0f854e020000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764c5a: { // 0x764c5a: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764c60: { // 0x764c60: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764c62: { // 0x764c62: e8191e0000 CALL 0x00766a80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766a80u,7752807u); flags=s.arithmetic_flags;
  }
  L00764c67: { // 0x764c67: e970faffff JMP 0x007646dc
    goto L007646dc;
  }
  L00764c6c: { // 0x764c6c: 3d5650525a CMP EAX,0x5a525056
    (void)integer::sub(s.ax,0x5a525056u,32,flags);
  }
  L00764c71: { // 0x764c71: 0f84ba010000 JZ 0x00764e31
    if(integer::condition("JZ",flags)) goto L00764e31;
  }
  L00764c77: { // 0x764c77: 3d5650545a CMP EAX,0x5a545056
    (void)integer::sub(s.ax,0x5a545056u,32,flags);
  }
  L00764c7c: { // 0x764c7c: 0f8450010000 JZ 0x00764dd2
    if(integer::condition("JZ",flags)) goto L00764dd2;
  }
  L00764c82: { // 0x764c82: 8b9524070000 MOV EDX,dword ptr [EBP + 0x724]
    s.dx = m.r32((s.bp+0x00000724u));
  }
  L00764c88: { // 0x764c88: 8bb534070000 MOV ESI,dword ptr [EBP + 0x734]
    s.si = m.r32((s.bp+0x00000734u));
  }
  L00764c8e: { // 0x764c8e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764c90: { // 0x764c90: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00764c92: { // 0x764c92: 760c JBE 0x00764ca0
    if(integer::condition("JBE",flags)) goto L00764ca0;
  }
  L00764c94: { // 0x764c94: 3b06 CMP EAX,dword ptr [ESI]
    (void)integer::sub(s.ax,m.r32((s.si)),32,flags);
  }
  L00764c96: { // 0x764c96: 7433 JZ 0x00764ccb
    if(integer::condition("JZ",flags)) goto L00764ccb;
  }
  L00764c98: { // 0x764c98: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764c99: { // 0x764c99: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L00764c9c: { // 0x764c9c: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00764c9e: { // 0x764c9e: 72f4 JC 0x00764c94
    if(integer::condition("JC",flags)) goto L00764c94;
  }
  L00764ca0: { // 0x764ca0: 8b953c070000 MOV EDX,dword ptr [EBP + 0x73c]
    s.dx = m.r32((s.bp+0x0000073cu));
  }
  L00764ca6: { // 0x764ca6: 8bb544070000 MOV ESI,dword ptr [EBP + 0x744]
    s.si = m.r32((s.bp+0x00000744u));
  }
  L00764cac: { // 0x764cac: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764cae: { // 0x764cae: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00764cb0: { // 0x764cb0: 0f86f2010000 JBE 0x00764ea8
    if(integer::condition("JBE",flags)) goto L00764ea8;
  }
  L00764cb6: { // 0x764cb6: 3b06 CMP EAX,dword ptr [ESI]
    (void)integer::sub(s.ax,m.r32((s.si)),32,flags);
  }
  L00764cb8: { // 0x764cb8: 0f8493000000 JZ 0x00764d51
    if(integer::condition("JZ",flags)) goto L00764d51;
  }
  L00764cbe: { // 0x764cbe: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764cbf: { // 0x764cbf: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L00764cc2: { // 0x764cc2: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00764cc4: { // 0x764cc4: 72f0 JC 0x00764cb6
    if(integer::condition("JC",flags)) goto L00764cb6;
  }
  L00764cc6: { // 0x764cc6: e9dd010000 JMP 0x00764ea8
    goto L00764ea8;
  }
  L00764ccb: { // 0x764ccb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00764ccd: { // 0x764ccd: 7cd1 JL 0x00764ca0
    if(integer::condition("JL",flags)) goto L00764ca0;
  }
  L00764ccf: { // 0x764ccf: 8b9538070000 MOV EDX,dword ptr [EBP + 0x738]
    s.dx = m.r32((s.bp+0x00000738u));
  }
  L00764cd5: { // 0x764cd5: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764cda: { // 0x764cda: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L00764cdd: { // 0x764cdd: 8d7001 LEA ESI,[EAX + 0x1]
    s.si = (s.ax+0x00000001u);
  }
  L00764ce0: { // 0x764ce0: 8b448a04 MOV EAX,dword ptr [EDX + ECX*0x4 + 0x4]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)+0x00000004u));
  }
  L00764ce4: { // 0x764ce4: 8d0c8a LEA ECX,[EDX + ECX*0x4]
    s.cx = (s.dx+(s.cx * 0x00000004u));
  }
  L00764ce7: { // 0x764ce7: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  L00764cea: { // 0x764cea: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764ced: { // 0x764ced: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L00764cf0: { // 0x764cf0: c1e202 SHL EDX,0x2
    s.dx = integer::shift(s.dx,0x00000002u,32,flags,integer::Shift::left);
  }
  L00764cf3: { // 0x764cf3: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00764cf5: { // 0x764cf5: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764cf6: { // 0x764cf6: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764cf8: { // 0x764cf8: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00764cfc: { // 0x764cfc: 8b1d2804b100 MOV EBX,dword ptr [0x00b10428]
    s.bx = m.r32((0x00b10428u));
  }
  L00764d02: { // 0x764d02: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00764d05: { // 0x764d05: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764d08: { // 0x764d08: 8b9d80010000 MOV EBX,dword ptr [EBP + 0x180]
    s.bx = m.r32((s.bp+0x00000180u));
  }
  L00764d0e: { // 0x764d0e: 895c1708 MOV dword ptr [EDI + EDX*0x1 + 0x8],EBX
    m.w32((s.di+(s.dx * 0x00000001u)+0x00000008u), s.bx);
  }
  L00764d12: { // 0x764d12: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00764d14: { // 0x764d14: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00764d16: { // 0x764d16: 7202 JC 0x00764d1a
    if(integer::condition("JC",flags)) goto L00764d1a;
  }
  L00764d18: { // 0x764d18: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764d1a: { // 0x764d1a: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00764d1d: { // 0x764d1d: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00764d21: { // 0x764d21: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764d22: { // 0x764d22: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764d23: { // 0x764d23: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764d25: { // 0x764d25: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764d26: { // 0x764d26: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753001u); flags=s.arithmetic_flags;
  }
  L00764d29: { // 0x764d29: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764d2c: { // 0x764d2c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764d2e: { // 0x764d2e: 0f85b5010000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764d34: { // 0x764d34: 8b8570010000 MOV EAX,dword ptr [EBP + 0x170]
    s.ax = m.r32((s.bp+0x00000170u));
  }
  L00764d3a: { // 0x764d3a: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00764d3e: { // 0x764d3e: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764d43: { // 0x764d43: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  L00764d46: { // 0x764d46: 80cd04 OR CH,0x4
    s.cx = (s.cx & 0xffff00ffu) | (((integer::logical((((s.cx >> 8) & 0xffu))|(0x00000004u),8,flags)) & 0xffu) << 8);
  }
  L00764d49: { // 0x764d49: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L00764d4c: { // 0x764d4c: e936f8ffff JMP 0x00764587
    goto L00764587;
  }
  L00764d51: { // 0x764d51: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00764d53: { // 0x764d53: 0f8c4f010000 JL 0x00764ea8
    if(integer::condition("JL",flags)) goto L00764ea8;
  }
  L00764d59: { // 0x764d59: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764d5f: { // 0x764d5f: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L00764d62: { // 0x764d62: 8b8d48070000 MOV ECX,dword ptr [EBP + 0x748]
    s.cx = m.r32((s.bp+0x00000748u));
  }
  L00764d68: { // 0x764d68: 8d7201 LEA ESI,[EDX + 0x1]
    s.si = (s.dx+0x00000001u);
  }
  L00764d6b: { // 0x764d6b: 8d0c81 LEA ECX,[ECX + EAX*0x4]
    s.cx = (s.cx+(s.ax * 0x00000004u));
  }
  L00764d6e: { // 0x764d6e: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  L00764d71: { // 0x764d71: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00764d74: { // 0x764d74: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764d77: { // 0x764d77: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L00764d7a: { // 0x764d7a: c1e202 SHL EDX,0x2
    s.dx = integer::shift(s.dx,0x00000002u,32,flags,integer::Shift::left);
  }
  L00764d7d: { // 0x764d7d: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00764d7f: { // 0x764d7f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764d80: { // 0x764d80: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764d82: { // 0x764d82: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00764d86: { // 0x764d86: 8b1d2804b100 MOV EBX,dword ptr [0x00b10428]
    s.bx = m.r32((0x00b10428u));
  }
  L00764d8c: { // 0x764d8c: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00764d8f: { // 0x764d8f: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764d92: { // 0x764d92: 8b9d80010000 MOV EBX,dword ptr [EBP + 0x180]
    s.bx = m.r32((s.bp+0x00000180u));
  }
  L00764d98: { // 0x764d98: 895c1708 MOV dword ptr [EDI + EDX*0x1 + 0x8],EBX
    m.w32((s.di+(s.dx * 0x00000001u)+0x00000008u), s.bx);
  }
  L00764d9c: { // 0x764d9c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00764d9e: { // 0x764d9e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00764da0: { // 0x764da0: 7202 JC 0x00764da4
    if(integer::condition("JC",flags)) goto L00764da4;
  }
  L00764da2: { // 0x764da2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764da4: { // 0x764da4: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00764da8: { // 0x764da8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764da9: { // 0x764da9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764daa: { // 0x764daa: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764dac: { // 0x764dac: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764dad: { // 0x764dad: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00764db0: { // 0x764db0: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753139u); flags=s.arithmetic_flags;
  }
  L00764db3: { // 0x764db3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764db6: { // 0x764db6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764db8: { // 0x764db8: 0f852b010000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764dbe: { // 0x764dbe: 8b8570010000 MOV EAX,dword ptr [EBP + 0x170]
    s.ax = m.r32((s.bp+0x00000170u));
  }
  L00764dc4: { // 0x764dc4: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  L00764dc7: { // 0x764dc7: 80cd04 OR CH,0x4
    s.cx = (s.cx & 0xffff00ffu) | (((integer::logical((((s.cx >> 8) & 0xffu))|(0x00000004u),8,flags)) & 0xffu) << 8);
  }
  L00764dca: { // 0x764dca: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L00764dcd: { // 0x764dcd: e9acf7ffff JMP 0x0076457e
    goto L0076457e;
  }
  L00764dd2: { // 0x764dd2: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764dd7: { // 0x764dd7: 0f85c3000000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764ddd: { // 0x764ddd: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764de2: { // 0x764de2: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00764de8: { // 0x764de8: 8bb56c070000 MOV ESI,dword ptr [EBP + 0x76c]
    s.si = m.r32((s.bp+0x0000076cu));
  }
  L00764dee: { // 0x764dee: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00764df2: { // 0x764df2: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764df4: { // 0x764df4: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764df5: { // 0x764df5: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764df7: { // 0x764df7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00764df9: { // 0x764df9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764dfa: { // 0x764dfa: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L00764dfc: { // 0x764dfc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764dfd: { // 0x764dfd: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764dff: { // 0x764dff: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764e00: { // 0x764e00: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753219u); flags=s.arithmetic_flags;
  }
  L00764e03: { // 0x764e03: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764e06: { // 0x764e06: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764e08: { // 0x764e08: 0f85db000000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764e0e: { // 0x764e0e: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00764e11: { // 0x764e11: 897720 MOV dword ptr [EDI + 0x20],ESI
    m.w32((s.di+0x00000020u), s.si);
  }
  L00764e14: { // 0x764e14: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00764e17: { // 0x764e17: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00764e1a: { // 0x764e1a: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00764e22: { // 0x764e22: 7309 JNC 0x00764e2d
    if(integer::condition("JNC",flags)) goto L00764e2d;
  }
  L00764e24: { // 0x764e24: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00764e28: { // 0x764e28: c644030180 MOV byte ptr [EBX + EAX*0x1 + 0x1],0x80
    m.w8((s.bx+(s.ax * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00764e2d: { // 0x764e2d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764e2f: { // 0x764e2f: eb66 JMP 0x00764e97
    goto L00764e97;
  }
  L00764e31: { // 0x764e31: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764e36: { // 0x764e36: 7568 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764e38: { // 0x764e38: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764e3d: { // 0x764e3d: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00764e43: { // 0x764e43: 8bb56c070000 MOV ESI,dword ptr [EBP + 0x76c]
    s.si = m.r32((s.bp+0x0000076cu));
  }
  L00764e49: { // 0x764e49: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00764e4d: { // 0x764e4d: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764e4f: { // 0x764e4f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764e50: { // 0x764e50: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764e52: { // 0x764e52: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00764e54: { // 0x764e54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764e55: { // 0x764e55: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L00764e57: { // 0x764e57: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764e58: { // 0x764e58: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764e5a: { // 0x764e5a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764e5b: { // 0x764e5b: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753310u); flags=s.arithmetic_flags;
  }
  L00764e5e: { // 0x764e5e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764e61: { // 0x764e61: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764e63: { // 0x764e63: 0f8580000000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764e69: { // 0x764e69: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00764e6c: { // 0x764e6c: 897720 MOV dword ptr [EDI + 0x20],ESI
    m.w32((s.di+0x00000020u), s.si);
  }
  L00764e6f: { // 0x764e6f: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00764e72: { // 0x764e72: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00764e75: { // 0x764e75: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00764e7d: { // 0x764e7d: 7309 JNC 0x00764e88
    if(integer::condition("JNC",flags)) goto L00764e88;
  }
  L00764e7f: { // 0x764e7f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00764e83: { // 0x764e83: c6440b0180 MOV byte ptr [EBX + ECX*0x1 + 0x1],0x80
    m.w8((s.bx+(s.cx * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00764e88: { // 0x764e88: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00764e8c: { // 0x764e8c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764e8e: { // 0x764e8e: 8b5014 MOV EDX,dword ptr [EAX + 0x14]
    s.dx = m.r32((s.ax+0x00000014u));
  }
  L00764e91: { // 0x764e91: 83ca20 OR EDX,0x20
    s.dx = integer::logical((s.dx)|(0x00000020u),32,flags);
  }
  L00764e94: { // 0x764e94: 895014 MOV dword ptr [EAX + 0x14],EDX
    m.w32((s.ax+0x00000014u), s.dx);
  }
  L00764e97: { // 0x764e97: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00764e9b: { // 0x764e9b: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764ea0: { // 0x764ea0: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00764ea2: { // 0x764ea2: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L00764ea6: { // 0x764ea6: 755b JNZ 0x00764f03
    if(integer::condition("JNZ",flags)) goto L00764f03;
  }
  L00764ea8: { // 0x764ea8: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764eae: { // 0x764eae: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00764eaf: { // 0x764eaf: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00764eb2: { // 0x764eb2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764eb3: { // 0x764eb3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00764eb4: { // 0x764eb4: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00764eb6: { // 0x764eb6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764eb7: { // 0x764eb7: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753402u); flags=s.arithmetic_flags;
  }
  L00764eba: { // 0x764eba: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764ebd: { // 0x764ebd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764ebf: { // 0x764ebf: 7535 JNZ 0x00764ef6
    if(integer::condition("JNZ",flags)) goto L00764ef6;
  }
  L00764ec1: { // 0x764ec1: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00764ec5: { // 0x764ec5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764ec7: { // 0x764ec7: 753a JNZ 0x00764f03
    if(integer::condition("JNZ",flags)) goto L00764f03;
  }
  L00764ec9: { // 0x764ec9: e9b9f6ffff JMP 0x00764587
    goto L00764587;
  }
  L00764ece: { // 0x764ece: 8b8550010000 MOV EAX,dword ptr [EBP + 0x150]
    s.ax = m.r32((s.bp+0x00000150u));
  }
  L00764ed4: { // 0x764ed4: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  L00764ed6: { // 0x764ed6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764ed7: { // 0x764ed7: 898550010000 MOV dword ptr [EBP + 0x150],EAX
    m.w32((s.bp+0x00000150u), s.ax);
  }
  L00764edd: { // 0x764edd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764ede: { // 0x764ede: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764edf: { // 0x764edf: b8f5ffffff MOV EAX,0xfffffff5
    s.ax = 0xfffffff5u;
  }
  L00764ee4: { // 0x764ee4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764ee5: { // 0x764ee5: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764ee8: { // 0x764ee8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764ee9: { // 0x764ee9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764eea: { // 0x764eea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764eeb: { // 0x764eeb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764eec: { // 0x764eec: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00764ef1: { // 0x764ef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764ef2: { // 0x764ef2: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764ef5: { // 0x764ef5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764ef6: { // 0x764ef6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764ef7: { // 0x764ef7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764ef8: { // 0x764ef8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764ef9: { // 0x764ef9: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  L00764efe: { // 0x764efe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764eff: { // 0x764eff: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764f02: { // 0x764f02: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764f03: { // 0x764f03: 8bb580010000 MOV ESI,dword ptr [EBP + 0x180]
    s.si = m.r32((s.bp+0x00000180u));
  }
  L00764f09: { // 0x764f09: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00764f0b: { // 0x764f0b: 7e18 JLE 0x00764f25
    if(integer::condition("JLE",flags)) goto L00764f25;
  }
  L00764f0d: { // 0x764f0d: 8b8590010000 MOV EAX,dword ptr [EBP + 0x190]
    s.ax = m.r32((s.bp+0x00000190u));
  }
  L00764f13: { // 0x764f13: 8b8d94010000 MOV ECX,dword ptr [EBP + 0x194]
    s.cx = m.r32((s.bp+0x00000194u));
  }
  L00764f19: { // 0x764f19: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00764f1b: { // 0x764f1b: 7e06 JLE 0x00764f23
    if(integer::condition("JLE",flags)) goto L00764f23;
  }
  L00764f1d: { // 0x764f1d: 898594010000 MOV dword ptr [EBP + 0x194],EAX
    m.w32((s.bp+0x00000194u), s.ax);
  }
  L00764f23: { // 0x764f23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00764f25: { // 0x764f25: 743f JZ 0x00764f66
    if(integer::condition("JZ",flags)) goto L00764f66;
  }
  L00764f27: { // 0x764f27: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764f29: { // 0x764f29: 668b8514070000 MOV AX,word ptr [EBP + 0x714]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000714u)));
  }
  L00764f30: { // 0x764f30: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764f32: { // 0x764f32: 7e53 JLE 0x00764f87
    if(integer::condition("JLE",flags)) goto L00764f87;
  }
  L00764f34: { // 0x764f34: f6851607000003 TEST byte ptr [EBP + 0x716],0x3
    (void)integer::logical((m.r8((s.bp+0x00000716u)))&(0x00000003u),8,flags);
  }
  L00764f3b: { // 0x764f3b: 744a JZ 0x00764f87
    if(integer::condition("JZ",flags)) goto L00764f87;
  }
  L00764f3d: { // 0x764f3d: 8b951c070000 MOV EDX,dword ptr [EBP + 0x71c]
    s.dx = m.r32((s.bp+0x0000071cu));
  }
  L00764f43: { // 0x764f43: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764f45: { // 0x764f45: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764f47: { // 0x764f47: 7e3e JLE 0x00764f87
    if(integer::condition("JLE",flags)) goto L00764f87;
  }
  L00764f49: { // 0x764f49: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00764f4b: { // 0x764f4b: 668b3a MOV DI,word ptr [EDX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00764f4e: { // 0x764f4e: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00764f50: { // 0x764f50: 740f JZ 0x00764f61
    if(integer::condition("JZ",flags)) goto L00764f61;
  }
  L00764f52: { // 0x764f52: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764f53: { // 0x764f53: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00764f56: { // 0x764f56: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00764f58: { // 0x764f58: 7cef JL 0x00764f49
    if(integer::condition("JL",flags)) goto L00764f49;
  }
  L00764f5a: { // 0x764f5a: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764f5f: { // 0x764f5f: eb26 JMP 0x00764f87
    goto L00764f87;
  }
  L00764f61: { // 0x764f61: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764f66: { // 0x764f66: f644241420 TEST byte ptr [ESP + 0x14],0x20
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000020u),8,flags);
  }
  L00764f6b: { // 0x764f6b: 751a JNZ 0x00764f87
    if(integer::condition("JNZ",flags)) goto L00764f87;
  }
  L00764f6d: { // 0x764f6d: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00764f71: { // 0x764f71: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00764f73: { // 0x764f73: 7512 JNZ 0x00764f87
    if(integer::condition("JNZ",flags)) goto L00764f87;
  }
  L00764f75: { // 0x764f75: 8b8564010000 MOV EAX,dword ptr [EBP + 0x164]
    s.ax = m.r32((s.bp+0x00000164u));
  }
  L00764f7b: { // 0x764f7b: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00764f7e: { // 0x764f7e: 898568010000 MOV dword ptr [EBP + 0x168],EAX
    m.w32((s.bp+0x00000168u), s.ax);
  }
  L00764f84: { // 0x764f84: 894304 MOV dword ptr [EBX + 0x4],EAX
    m.w32((s.bx+0x00000004u), s.ax);
  }
  L00764f87: { // 0x764f87: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764f8c: { // 0x764f8c: 752f JNZ 0x00764fbd
    if(integer::condition("JNZ",flags)) goto L00764fbd;
  }
  L00764f8e: { // 0x764f8e: 8b8d80010000 MOV ECX,dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L00764f94: { // 0x764f94: 894b1c MOV dword ptr [EBX + 0x1c],ECX
    m.w32((s.bx+0x0000001cu), s.cx);
  }
  L00764f97: { // 0x764f97: 8b9580010000 MOV EDX,dword ptr [EBP + 0x180]
    s.dx = m.r32((s.bp+0x00000180u));
  }
  L00764f9d: { // 0x764f9d: 899584010000 MOV dword ptr [EBP + 0x184],EDX
    m.w32((s.bp+0x00000184u), s.dx);
  }
  L00764fa3: { // 0x764fa3: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00764fa6: { // 0x764fa6: 89856c010000 MOV dword ptr [EBP + 0x16c],EAX
    m.w32((s.bp+0x0000016cu), s.ax);
  }
  L00764fac: { // 0x764fac: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764faf: { // 0x764faf: 8b4b0c MOV ECX,dword ptr [EBX + 0xc]
    s.cx = m.r32((s.bx+0x0000000cu));
  }
  L00764fb2: { // 0x764fb2: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  L00764fb4: { // 0x764fb4: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764fb7: { // 0x764fb7: 898d70010000 MOV dword ptr [EBP + 0x170],ECX
    m.w32((s.bp+0x00000170u), s.cx);
  }
  L00764fbd: { // 0x764fbd: 8b8580010000 MOV EAX,dword ptr [EBP + 0x180]
    s.ax = m.r32((s.bp+0x00000180u));
  }
  L00764fc3: { // 0x764fc3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764fc4: { // 0x764fc4: 898580010000 MOV dword ptr [EBP + 0x180],EAX
    m.w32((s.bp+0x00000180u), s.ax);
  }
  L00764fca: { // 0x764fca: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00764fcd: { // 0x764fcd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764fce: { // 0x764fce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764fcf: { // 0x764fcf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764fd0: { // 0x764fd0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764fd1: { // 0x764fd1: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764fd4: { // 0x764fd4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7749360u:f_00363ef0(m,s,child,{});break;
case 7760224u:f_00366960(m,s,child,{});break;
case 7760512u:f_00366a80(m,s,child,{});break;
case 7755728u:f_003657d0(m,s,child,{});break;
case 7750288u:f_00364290(m,s,child,{});break;
default:throw std::domain_error("recovery829 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00763fc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763fc0: { // 0x763fc0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00763fc3: { // 0x763fc3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763fc4: { // 0x763fc4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00763fc5: { // 0x763fc5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763fc6: { // 0x763fc6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00763fc8: { // 0x763fc8: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00763fcc: { // 0x763fcc: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00763fce: { // 0x763fce: 8a8684000000 MOV AL,byte ptr [ESI + 0x84]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000084u)));
  }
  L00763fd4: { // 0x763fd4: 8b8e64070000 MOV ECX,dword ptr [ESI + 0x764]
    s.cx = m.r32((s.si+0x00000764u));
  }
  L00763fda: { // 0x763fda: 8b9680010000 MOV EDX,dword ptr [ESI + 0x180]
    s.dx = m.r32((s.si+0x00000180u));
  }
  L00763fe0: { // 0x763fe0: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00763fe2: { // 0x763fe2: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L00763fe4: { // 0x763fe4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763fe5: { // 0x763fe5: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00763fe9: { // 0x763fe9: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00763fed: { // 0x763fed: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00763ff1: { // 0x763ff1: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00763ff6: { // 0x763ff6: 0f8418020000 JZ 0x00764214
    if(integer::condition("JZ",flags)) goto L00764214;
  }
  L00763ffc: { // 0x763ffc: f6865401000004 TEST byte ptr [ESI + 0x154],0x4
    (void)integer::logical((m.r8((s.si+0x00000154u)))&(0x00000004u),8,flags);
  }
  L00764003: { // 0x764003: 0f840b020000 JZ 0x00764214
    if(integer::condition("JZ",flags)) goto L00764214;
  }
  L00764009: { // 0x764009: 8b8620010000 MOV EAX,dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L0076400f: { // 0x76400f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00764011: { // 0x764011: 0f8cfd010000 JL 0x00764214
    if(integer::condition("JL",flags)) goto L00764214;
  }
  L00764017: { // 0x764017: 3b5610 CMP EDX,dword ptr [ESI + 0x10]
    (void)integer::sub(s.dx,m.r32((s.si+0x00000010u)),32,flags);
  }
  L0076401a: { // 0x76401a: 7d0b JGE 0x00764027
    if(integer::condition("JGE",flags)) goto L00764027;
  }
  L0076401c: { // 0x76401c: 8b2c91 MOV EBP,dword ptr [ECX + EDX*0x4]
    s.bp = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L0076401f: { // 0x76401f: 81e5ffffff0f AND EBP,0xfffffff
    s.bp = integer::logical((s.bp)&(0x0fffffffu),32,flags);
  }
  L00764025: { // 0x764025: d1e5 SHL EBP,0x1
    s.bp = integer::shift(s.bp,0x00000001u,32,flags,integer::Shift::left);
  }
  L00764027: { // 0x764027: 3b9628010000 CMP EDX,dword ptr [ESI + 0x128]
    (void)integer::sub(s.dx,m.r32((s.si+0x00000128u)),32,flags);
  }
  L0076402d: { // 0x76402d: 0f8503010000 JNZ 0x00764136
    if(integer::condition("JNZ",flags)) goto L00764136;
  }
  L00764033: { // 0x764033: 3b8610070000 CMP EAX,dword ptr [ESI + 0x710]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000710u)),32,flags);
  }
  L00764039: { // 0x764039: 0f84f7000000 JZ 0x00764136
    if(integer::condition("JZ",flags)) goto L00764136;
  }
  L0076403f: { // 0x76403f: 3b9608070000 CMP EDX,dword ptr [ESI + 0x708]
    (void)integer::sub(s.dx,m.r32((s.si+0x00000708u)),32,flags);
  }
  L00764045: { // 0x764045: 7412 JZ 0x00764059
    if(integer::condition("JZ",flags)) goto L00764059;
  }
  L00764047: { // 0x764047: 89aefc060000 MOV dword ptr [ESI + 0x6fc],EBP
    m.w32((s.si+0x000006fcu), s.bp);
  }
  L0076404d: { // 0x76404d: 899e00070000 MOV dword ptr [ESI + 0x700],EBX
    m.w32((s.si+0x00000700u), s.bx);
  }
  L00764053: { // 0x764053: 899e04070000 MOV dword ptr [ESI + 0x704],EBX
    m.w32((s.si+0x00000704u), s.bx);
  }
  L00764059: { // 0x764059: 8b8620010000 MOV EAX,dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L0076405f: { // 0x76405f: 898610070000 MOV dword ptr [ESI + 0x710],EAX
    m.w32((s.si+0x00000710u), s.ax);
  }
  L00764065: { // 0x764065: 8b8628010000 MOV EAX,dword ptr [ESI + 0x128]
    s.ax = m.r32((s.si+0x00000128u));
  }
  L0076406b: { // 0x76406b: 898608070000 MOV dword ptr [ESI + 0x708],EAX
    m.w32((s.si+0x00000708u), s.ax);
  }
  L00764071: { // 0x764071: c7860c070000ffffffff MOV dword ptr [ESI + 0x70c],0xffffffff
    m.w32((s.si+0x0000070cu), 0xffffffffu);
  }
  L0076407b: { // 0x76407b: 8bbe28010000 MOV EDI,dword ptr [ESI + 0x128]
    s.di = m.r32((s.si+0x00000128u));
  }
  L00764081: { // 0x764081: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L00764087: { // 0x764087: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00764089: { // 0x764089: 0f8f86000000 JG 0x00764115
    if(integer::condition("JG",flags)) goto L00764115;
  }
  L0076408f: { // 0x76408f: 8d0cb9 LEA ECX,[ECX + EDI*0x4]
    s.cx = (s.cx+(s.di * 0x00000004u));
  }
  L00764092: { // 0x764092: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00764096: { // 0x764096: eb04 JMP 0x0076409c
    goto L0076409c;
  }
  L00764098: { // 0x764098: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0076409c: { // 0x76409c: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  L0076409f: { // 0x76409f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L007640a0: { // 0x7640a0: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L007640a2: { // 0x7640a2: 7d1b JGE 0x007640bf
    if(integer::condition("JGE",flags)) goto L007640bf;
  }
  L007640a4: { // 0x7640a4: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L007640a7: { // 0x7640a7: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L007640a9: { // 0x7640a9: 81e2ffffff0f AND EDX,0xfffffff
    s.dx = integer::logical((s.dx)&(0x0fffffffu),32,flags);
  }
  L007640af: { // 0x7640af: 81e1ffffff0f AND ECX,0xfffffff
    s.cx = integer::logical((s.cx)&(0x0fffffffu),32,flags);
  }
  L007640b5: { // 0x7640b5: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L007640b7: { // 0x7640b7: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L007640b9: { // 0x7640b9: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L007640bb: { // 0x7640bb: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L007640bd: { // 0x7640bd: eb31 JMP 0x007640f0
    goto L007640f0;
  }
  L007640bf: { // 0x7640bf: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L007640c3: { // 0x7640c3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007640c5: { // 0x7640c5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007640c6: { // 0x7640c6: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  L007640c8: { // 0x7640c8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007640c9: { // 0x7640c9: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7749836u); flags=s.arithmetic_flags;
  }
  L007640cc: { // 0x7640cc: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007640cf: { // 0x7640cf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007640d1: { // 0x7640d1: 7537 JNZ 0x0076410a
    if(integer::condition("JNZ",flags)) goto L0076410a;
  }
  L007640d3: { // 0x7640d3: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L007640d9: { // 0x7640d9: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L007640dd: { // 0x7640dd: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L007640e0: { // 0x7640e0: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L007640e4: { // 0x7640e4: 81e2ffffff0f AND EDX,0xfffffff
    s.dx = integer::logical((s.dx)&(0x0fffffffu),32,flags);
  }
  L007640ea: { // 0x7640ea: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  L007640ec: { // 0x7640ec: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L007640ee: { // 0x7640ee: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  L007640f0: { // 0x7640f0: 3b9ef8060000 CMP EBX,dword ptr [ESI + 0x6f8]
    (void)integer::sub(s.bx,m.r32((s.si+0x000006f8u)),32,flags);
  }
  L007640f6: { // 0x7640f6: 7d12 JGE 0x0076410a
    if(integer::condition("JGE",flags)) goto L0076410a;
  }
  L007640f8: { // 0x7640f8: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L007640fc: { // 0x7640fc: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L007640fd: { // 0x7640fd: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00764100: { // 0x764100: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00764102: { // 0x764102: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00764106: { // 0x764106: 7e90 JLE 0x00764098
    if(integer::condition("JLE",flags)) goto L00764098;
  }
  L00764108: { // 0x764108: eb07 JMP 0x00764111
    goto L00764111;
  }
  L0076410a: { // 0x76410a: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0076410b: { // 0x76410b: 89be0c070000 MOV dword ptr [ESI + 0x70c],EDI
    m.w32((s.si+0x0000070cu), s.di);
  }
  L00764111: { // 0x764111: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00764115: { // 0x764115: 3b9ef8060000 CMP EBX,dword ptr [ESI + 0x6f8]
    (void)integer::sub(s.bx,m.r32((s.si+0x000006f8u)),32,flags);
  }
  L0076411b: { // 0x76411b: 7d15 JGE 0x00764132
    if(integer::condition("JGE",flags)) goto L00764132;
  }
  L0076411d: { // 0x76411d: 83be0c070000ff CMP dword ptr [ESI + 0x70c],-0x1
    (void)integer::sub(m.r32((s.si+0x0000070cu)),0xffffffffu,32,flags);
  }
  L00764124: { // 0x764124: 750c JNZ 0x00764132
    if(integer::condition("JNZ",flags)) goto L00764132;
  }
  L00764126: { // 0x764126: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L0076412c: { // 0x76412c: 89860c070000 MOV dword ptr [ESI + 0x70c],EAX
    m.w32((s.si+0x0000070cu), s.ax);
  }
  L00764132: { // 0x764132: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00764136: { // 0x764136: 3b9608070000 CMP EDX,dword ptr [ESI + 0x708]
    (void)integer::sub(s.dx,m.r32((s.si+0x00000708u)),32,flags);
  }
  L0076413c: { // 0x76413c: 0f8cd2000000 JL 0x00764214
    if(integer::condition("JL",flags)) goto L00764214;
  }
  L00764142: { // 0x764142: 3b960c070000 CMP EDX,dword ptr [ESI + 0x70c]
    (void)integer::sub(s.dx,m.r32((s.si+0x0000070cu)),32,flags);
  }
  L00764148: { // 0x764148: 0f8fc6000000 JG 0x00764214
    if(integer::condition("JG",flags)) goto L00764214;
  }
  L0076414e: { // 0x76414e: 8b8600070000 MOV EAX,dword ptr [ESI + 0x700]
    s.ax = m.r32((s.si+0x00000700u));
  }
  L00764154: { // 0x764154: 8b9efc060000 MOV EBX,dword ptr [ESI + 0x6fc]
    s.bx = m.r32((s.si+0x000006fcu));
  }
  L0076415a: { // 0x76415a: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0076415c: { // 0x76415c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0076415e: { // 0x76415e: 0f8583000000 JNZ 0x007641e7
    if(integer::condition("JNZ",flags)) goto L007641e7;
  }
  L00764164: { // 0x764164: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00764167: { // 0x764167: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00764168: { // 0x764168: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0076416a: { // 0x76416a: 7d10 JGE 0x0076417c
    if(integer::condition("JGE",flags)) goto L0076417c;
  }
  L0076416c: { // 0x76416c: 8b7c9104 MOV EDI,dword ptr [ECX + EDX*0x4 + 0x4]
    s.di = m.r32((s.cx+(s.dx * 0x00000004u)+0x00000004u));
  }
  L00764170: { // 0x764170: 81e7ffffff0f AND EDI,0xfffffff
    s.di = integer::logical((s.di)&(0x0fffffffu),32,flags);
  }
  L00764176: { // 0x764176: d1e7 SHL EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::left);
  }
  L00764178: { // 0x764178: 2bfd SUB EDI,EBP
    s.di = integer::sub(s.di,s.bp,32,flags);
  }
  L0076417a: { // 0x76417a: eb1e JMP 0x0076419a
    goto L0076419a;
  }
  L0076417c: { // 0x76417c: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00764180: { // 0x764180: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00764182: { // 0x764182: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00764183: { // 0x764183: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  L00764185: { // 0x764185: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764186: { // 0x764186: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7750025u); flags=s.arithmetic_flags;
  }
  L00764189: { // 0x764189: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076418c: { // 0x76418c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076418e: { // 0x76418e: 7553 JNZ 0x007641e3
    if(integer::condition("JNZ",flags)) goto L007641e3;
  }
  L00764190: { // 0x764190: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00764194: { // 0x764194: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00764198: { // 0x764198: 2bfd SUB EDI,EBP
    s.di = integer::sub(s.di,s.bp,32,flags);
  }
  L0076419a: { // 0x76419a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0076419c: { // 0x76419c: 7e49 JLE 0x007641e7
    if(integer::condition("JLE",flags)) goto L007641e7;
  }
  L0076419e: { // 0x76419e: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  L007641a1: { // 0x7641a1: 3df03e7600 CMP EAX,0x763ef0
    (void)integer::sub(s.ax,0x00763ef0u,32,flags);
  }
  L007641a6: { // 0x7641a6: 740b JZ 0x007641b3
    if(integer::condition("JZ",flags)) goto L007641b3;
  }
  L007641a8: { // 0x7641a8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007641a9: { // 0x7641a9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007641ab: { // 0x7641ab: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L007641ad: { // 0x7641ad: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007641ae: { // 0x7641ae: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7750064u); flags=s.arithmetic_flags;
  }
  L007641b0: { // 0x7641b0: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007641b3: { // 0x7641b3: 8b9604070000 MOV EDX,dword ptr [ESI + 0x704]
    s.dx = m.r32((s.si+0x00000704u));
  }
  L007641b9: { // 0x7641b9: 8b9ef4060000 MOV EBX,dword ptr [ESI + 0x6f4]
    s.bx = m.r32((s.si+0x000006f4u));
  }
  L007641bf: { // 0x7641bf: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L007641c1: { // 0x7641c1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007641c2: { // 0x7641c2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007641c3: { // 0x7641c3: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007641c5: { // 0x7641c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007641c6: { // 0x7641c6: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7750089u); flags=s.arithmetic_flags;
  }
  L007641c9: { // 0x7641c9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007641cc: { // 0x7641cc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007641ce: { // 0x7641ce: 740d JZ 0x007641dd
    if(integer::condition("JZ",flags)) goto L007641dd;
  }
  L007641d0: { // 0x7641d0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007641d1: { // 0x7641d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007641d2: { // 0x7641d2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007641d3: { // 0x7641d3: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007641d8: { // 0x7641d8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007641d9: { // 0x7641d9: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L007641dc: { // 0x7641dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007641dd: { // 0x7641dd: 01be00070000 ADD dword ptr [ESI + 0x700],EDI
    m.w32((s.si+0x00000700u), integer::add(m.r32((s.si+0x00000700u)),s.di,32,flags));
  }
  L007641e3: { // 0x7641e3: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L007641e7: { // 0x7641e7: 8b86fc060000 MOV EAX,dword ptr [ESI + 0x6fc]
    s.ax = m.r32((s.si+0x000006fcu));
  }
  L007641ed: { // 0x7641ed: 8b8e00070000 MOV ECX,dword ptr [ESI + 0x700]
    s.cx = m.r32((s.si+0x00000700u));
  }
  L007641f3: { // 0x7641f3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L007641f5: { // 0x7641f5: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L007641f7: { // 0x7641f7: 7d1b JGE 0x00764214
    if(integer::condition("JGE",flags)) goto L00764214;
  }
  L007641f9: { // 0x7641f9: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L007641fb: { // 0x7641fb: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L00764200: { // 0x764200: 89ae04070000 MOV dword ptr [ESI + 0x704],EBP
    m.w32((s.si+0x00000704u), s.bp);
  }
  L00764206: { // 0x764206: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  L00764209: { // 0x764209: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0076420d: { // 0x76420d: c74640f03e7600 MOV dword ptr [ESI + 0x40],0x763ef0
    m.w32((s.si+0x00000040u), 0x00763ef0u);
  }
  L00764214: { // 0x764214: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00764216: { // 0x764216: 7435 JZ 0x0076424d
    if(integer::condition("JZ",flags)) goto L0076424d;
  }
  L00764218: { // 0x764218: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076421a: { // 0x76421a: 668b8614070000 MOV AX,word ptr [ESI + 0x714]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000714u)));
  }
  L00764221: { // 0x764221: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764223: { // 0x764223: 7e3b JLE 0x00764260
    if(integer::condition("JLE",flags)) goto L00764260;
  }
  L00764225: { // 0x764225: f6861607000003 TEST byte ptr [ESI + 0x716],0x3
    (void)integer::logical((m.r8((s.si+0x00000716u)))&(0x00000003u),8,flags);
  }
  L0076422c: { // 0x76422c: 7432 JZ 0x00764260
    if(integer::condition("JZ",flags)) goto L00764260;
  }
  L0076422e: { // 0x76422e: 8bbe1c070000 MOV EDI,dword ptr [ESI + 0x71c]
    s.di = m.r32((s.si+0x0000071cu));
  }
  L00764234: { // 0x764234: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764236: { // 0x764236: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764238: { // 0x764238: 7e26 JLE 0x00764260
    if(integer::condition("JLE",flags)) goto L00764260;
  }
  L0076423a: { // 0x76423a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0076423c: { // 0x76423c: 668b1f MOV BX,word ptr [EDI]
    s.bx = with_ax(s.bx, m.r16((s.di)));
  }
  L0076423f: { // 0x76423f: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L00764241: { // 0x764241: 740a JZ 0x0076424d
    if(integer::condition("JZ",flags)) goto L0076424d;
  }
  L00764243: { // 0x764243: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764244: { // 0x764244: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00764247: { // 0x764247: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00764249: { // 0x764249: 7cef JL 0x0076423a
    if(integer::condition("JL",flags)) goto L0076423a;
  }
  L0076424b: { // 0x76424b: eb13 JMP 0x00764260
    goto L00764260;
  }
  L0076424d: { // 0x76424d: f644242420 TEST byte ptr [ESP + 0x24],0x20
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000020u),8,flags);
  }
  L00764252: { // 0x764252: 750c JNZ 0x00764260
    if(integer::condition("JNZ",flags)) goto L00764260;
  }
  L00764254: { // 0x764254: 8b8e64010000 MOV ECX,dword ptr [ESI + 0x164]
    s.cx = m.r32((s.si+0x00000164u));
  }
  L0076425a: { // 0x76425a: 898e68010000 MOV dword ptr [ESI + 0x168],ECX
    m.w32((s.si+0x00000168u), s.cx);
  }
  L00764260: { // 0x764260: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00764264: { // 0x764264: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00764266: { // 0x764266: e825000000 CALL 0x00764290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00764290u,7750251u); flags=s.arithmetic_flags;
  }
  L0076426b: { // 0x76426b: 8a4c2413 MOV CL,byte ptr [ESP + 0x13]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000013u)));
  }
  L0076426f: { // 0x76426f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00764271: { // 0x764271: 7407 JZ 0x0076427a
    if(integer::condition("JZ",flags)) goto L0076427a;
  }
  L00764273: { // 0x764273: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00764277: { // 0x764277: 895640 MOV dword ptr [ESI + 0x40],EDX
    m.w32((s.si+0x00000040u), s.dx);
  }
  L0076427a: { // 0x76427a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076427b: { // 0x76427b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076427c: { // 0x76427c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076427d: { // 0x76427d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076427e: { // 0x76427e: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00764281: { // 0x764281: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00764290(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00764290: { // 0x764290: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00764293: { // 0x764293: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764294: { // 0x764294: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764295: { // 0x764295: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00764297: { // 0x764297: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764298: { // 0x764298: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0076429a: { // 0x76429a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076429b: { // 0x76429b: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007642a1: { // 0x7642a1: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L007642a7: { // 0x7642a7: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007642a9: { // 0x7642a9: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L007642ad: { // 0x7642ad: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L007642af: { // 0x7642af: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L007642b3: { // 0x7642b3: 88542413 MOV byte ptr [ESP + 0x13],DL
    m.w8((f.sp+0x00000013u), (s.dx & 0xffu));
  }
  L007642b7: { // 0x7642b7: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L007642bb: { // 0x7642bb: 0f8410020000 JZ 0x007644d1
    if(integer::condition("JZ",flags)) goto L007644d1;
  }
  L007642c1: { // 0x7642c1: 8b8d24010000 MOV ECX,dword ptr [EBP + 0x124]
    s.cx = m.r32((s.bp+0x00000124u));
  }
  L007642c7: { // 0x7642c7: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L007642c9: { // 0x7642c9: 7f09 JG 0x007642d4
    if(integer::condition("JG",flags)) goto L007642d4;
  }
  L007642cb: { // 0x7642cb: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L007642ce: { // 0x7642ce: 0f85fd010000 JNZ 0x007644d1
    if(integer::condition("JNZ",flags)) goto L007644d1;
  }
  L007642d4: { // 0x7642d4: 8b8d2c010000 MOV ECX,dword ptr [EBP + 0x12c]
    s.cx = m.r32((s.bp+0x0000012cu));
  }
  L007642da: { // 0x7642da: 8bb580010000 MOV ESI,dword ptr [EBP + 0x180]
    s.si = m.r32((s.bp+0x00000180u));
  }
  L007642e0: { // 0x7642e0: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L007642e2: { // 0x7642e2: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L007642e6: { // 0x7642e6: 0f8ee5010000 JLE 0x007644d1
    if(integer::condition("JLE",flags)) goto L007644d1;
  }
  L007642ec: { // 0x7642ec: 8b9d30010000 MOV EBX,dword ptr [EBP + 0x130]
    s.bx = m.r32((s.bp+0x00000130u));
  }
  L007642f2: { // 0x7642f2: 8b851c010000 MOV EAX,dword ptr [EBP + 0x11c]
    s.ax = m.r32((s.bp+0x0000011cu));
  }
  L007642f8: { // 0x7642f8: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L007642fb: { // 0x7642fb: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L007642ff: { // 0x7642ff: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00764303: { // 0x764303: 7416 JZ 0x0076431b
    if(integer::condition("JZ",flags)) goto L0076431b;
  }
  L00764305: { // 0x764305: 899d2c010000 MOV dword ptr [EBP + 0x12c],EBX
    m.w32((s.bp+0x0000012cu), s.bx);
  }
  L0076430b: { // 0x76430b: c78530010000ffffffff MOV dword ptr [EBP + 0x130],0xffffffff
    m.w32((s.bp+0x00000130u), 0xffffffffu);
  }
  L00764315: { // 0x764315: 899d1c010000 MOV dword ptr [EBP + 0x11c],EBX
    m.w32((s.bp+0x0000011cu), s.bx);
  }
  L0076431b: { // 0x76431b: 8b8528010000 MOV EAX,dword ptr [EBP + 0x128]
    s.ax = m.r32((s.bp+0x00000128u));
  }
  L00764321: { // 0x764321: 8b8d80010000 MOV ECX,dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L00764327: { // 0x764327: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00764329: { // 0x764329: 0f8422010000 JZ 0x00764451
    if(integer::condition("JZ",flags)) goto L00764451;
  }
  L0076432f: { // 0x76432f: 898580010000 MOV dword ptr [EBP + 0x180],EAX
    m.w32((s.bp+0x00000180u), s.ax);
  }
  L00764335: { // 0x764335: 8b8d70010000 MOV ECX,dword ptr [EBP + 0x170]
    s.cx = m.r32((s.bp+0x00000170u));
  }
  L0076433b: { // 0x76433b: 8bb528010000 MOV ESI,dword ptr [EBP + 0x128]
    s.si = m.r32((s.bp+0x00000128u));
  }
  L00764341: { // 0x764341: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00764346: { // 0x764346: f6411401 TEST byte ptr [ECX + 0x14],0x1
    (void)integer::logical((m.r8((s.cx+0x00000014u)))&(0x00000001u),8,flags);
  }
  L0076434a: { // 0x76434a: 740a JZ 0x00764356
    if(integer::condition("JZ",flags)) goto L00764356;
  }
  L0076434c: { // 0x76434c: b8f7ffffff MOV EAX,0xfffffff7
    s.ax = 0xfffffff7u;
  }
  L00764351: { // 0x764351: e9d2000000 JMP 0x00764428
    goto L00764428;
  }
  L00764356: { // 0x764356: 3bb51c010000 CMP ESI,dword ptr [EBP + 0x11c]
    (void)integer::sub(s.si,m.r32((s.bp+0x0000011cu)),32,flags);
  }
  L0076435c: { // 0x76435c: 7d1c JGE 0x0076437a
    if(integer::condition("JGE",flags)) goto L0076437a;
  }
  L0076435e: { // 0x76435e: 8b8564070000 MOV EAX,dword ptr [EBP + 0x764]
    s.ax = m.r32((s.bp+0x00000764u));
  }
  L00764364: { // 0x764364: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764366: { // 0x764366: 7412 JZ 0x0076437a
    if(integer::condition("JZ",flags)) goto L0076437a;
  }
  L00764368: { // 0x764368: f6858400000001 TEST byte ptr [EBP + 0x84],0x1
    (void)integer::logical((m.r8((s.bp+0x00000084u)))&(0x00000001u),8,flags);
  }
  L0076436f: { // 0x76436f: 7413 JZ 0x00764384
    if(integer::condition("JZ",flags)) goto L00764384;
  }
  L00764371: { // 0x764371: f685ea00000008 TEST byte ptr [EBP + 0xea],0x8
    (void)integer::logical((m.r8((s.bp+0x000000eau)))&(0x00000008u),8,flags);
  }
  L00764378: { // 0x764378: 750a JNZ 0x00764384
    if(integer::condition("JNZ",flags)) goto L00764384;
  }
  L0076437a: { // 0x76437a: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  L0076437f: { // 0x76437f: e9a4000000 JMP 0x00764428
    goto L00764428;
  }
  L00764384: { // 0x764384: 8a8508010000 MOV AL,byte ptr [EBP + 0x108]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000108u)));
  }
  L0076438a: { // 0x76438a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076438c: { // 0x76438c: 7551 JNZ 0x007643df
    if(integer::condition("JNZ",flags)) goto L007643df;
  }
  L0076438e: { // 0x76438e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00764390: { // 0x764390: 744d JZ 0x007643df
    if(integer::condition("JZ",flags)) goto L007643df;
  }
  L00764392: { // 0x764392: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764394: { // 0x764394: 668b8514070000 MOV AX,word ptr [EBP + 0x714]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000714u)));
  }
  L0076439b: { // 0x76439b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076439d: { // 0x76439d: 7e2a JLE 0x007643c9
    if(integer::condition("JLE",flags)) goto L007643c9;
  }
  L0076439f: { // 0x76439f: f6851607000003 TEST byte ptr [EBP + 0x716],0x3
    (void)integer::logical((m.r8((s.bp+0x00000716u)))&(0x00000003u),8,flags);
  }
  L007643a6: { // 0x7643a6: 7421 JZ 0x007643c9
    if(integer::condition("JZ",flags)) goto L007643c9;
  }
  L007643a8: { // 0x7643a8: 8b951c070000 MOV EDX,dword ptr [EBP + 0x71c]
    s.dx = m.r32((s.bp+0x0000071cu));
  }
  L007643ae: { // 0x7643ae: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L007643b0: { // 0x7643b0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007643b2: { // 0x7643b2: 7e15 JLE 0x007643c9
    if(integer::condition("JLE",flags)) goto L007643c9;
  }
  L007643b4: { // 0x7643b4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L007643b6: { // 0x7643b6: 668b1a MOV BX,word ptr [EDX]
    s.bx = with_ax(s.bx, m.r16((s.dx)));
  }
  L007643b9: { // 0x7643b9: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L007643bb: { // 0x7643bb: 741e JZ 0x007643db
    if(integer::condition("JZ",flags)) goto L007643db;
  }
  L007643bd: { // 0x7643bd: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007643be: { // 0x7643be: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L007643c1: { // 0x7643c1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007643c3: { // 0x7643c3: 7cef JL 0x007643b4
    if(integer::condition("JL",flags)) goto L007643b4;
  }
  L007643c5: { // 0x7643c5: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007643c9: { // 0x7643c9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L007643cb: { // 0x7643cb: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L007643cd: { // 0x7643cd: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007643cf: { // 0x7643cf: e8ac0c0000 CALL 0x00765080
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765080u,7750612u); flags=s.arithmetic_flags;
  }
  L007643d4: { // 0x7643d4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007643d7: { // 0x7643d7: 7521 JNZ 0x007643fa
    if(integer::condition("JNZ",flags)) goto L007643fa;
  }
  L007643d9: { // 0x7643d9: eb04 JMP 0x007643df
    goto L007643df;
  }
  L007643db: { // 0x7643db: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007643df: { // 0x7643df: 8d542413 LEA EDX,[ESP + 0x13]
    s.dx = (f.sp+0x00000013u);
  }
  L007643e3: { // 0x7643e3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007643e5: { // 0x7643e5: 8a85f5000000 MOV AL,byte ptr [EBP + 0xf5]
    s.ax = with_al(s.ax, m.r8((s.bp+0x000000f5u)));
  }
  L007643eb: { // 0x7643eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007643ec: { // 0x7643ec: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007643ee: { // 0x7643ee: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007643f0: { // 0x7643f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007643f1: { // 0x7643f1: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L007643f3: { // 0x7643f3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007643f5: { // 0x7643f5: e8960e0000 CALL 0x00765290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765290u,7750650u); flags=s.arithmetic_flags;
  }
  L007643fa: { // 0x7643fa: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007643fd: { // 0x7643fd: 89b580010000 MOV dword ptr [EBP + 0x180],ESI
    m.w32((s.bp+0x00000180u), s.si);
  }
  L00764403: { // 0x764403: 751e JNZ 0x00764423
    if(integer::condition("JNZ",flags)) goto L00764423;
  }
  L00764405: { // 0x764405: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00764409: { // 0x764409: ba20000000 MOV EDX,0x20
    s.dx = 0x00000020u;
  }
  L0076440e: { // 0x76440e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00764410: { // 0x764410: 7405 JZ 0x00764417
    if(integer::condition("JZ",flags)) goto L00764417;
  }
  L00764412: { // 0x764412: ba30000000 MOV EDX,0x30
    s.dx = 0x00000030u;
  }
  L00764417: { // 0x764417: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764419: { // 0x764419: e8a2fbffff CALL 0x00763fc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763fc0u,7750686u); flags=s.arithmetic_flags;
  }
  L0076441e: { // 0x76441e: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764421: { // 0x764421: 7431 JZ 0x00764454
    if(integer::condition("JZ",flags)) goto L00764454;
  }
  L00764423: { // 0x764423: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L00764426: { // 0x764426: 742c JZ 0x00764454
    if(integer::condition("JZ",flags)) goto L00764454;
  }
  L00764428: { // 0x764428: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0076442c: { // 0x76442c: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00764430: { // 0x764430: 898d2c010000 MOV dword ptr [EBP + 0x12c],ECX
    m.w32((s.bp+0x0000012cu), s.cx);
  }
  L00764436: { // 0x764436: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764437: { // 0x764437: 899d30010000 MOV dword ptr [EBP + 0x130],EBX
    m.w32((s.bp+0x00000130u), s.bx);
  }
  L0076443d: { // 0x76443d: 89951c010000 MOV dword ptr [EBP + 0x11c],EDX
    m.w32((s.bp+0x0000011cu), s.dx);
  }
  L00764443: { // 0x764443: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764444: { // 0x764444: 898d80010000 MOV dword ptr [EBP + 0x180],ECX
    m.w32((s.bp+0x00000180u), s.cx);
  }
  L0076444a: { // 0x76444a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076444b: { // 0x76444b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076444c: { // 0x76444c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076444d: { // 0x76444d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764450: { // 0x764450: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764451: { // 0x764451: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00764454: { // 0x764454: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L0076445a: { // 0x76445a: 80ca80 OR DL,0x80
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|(0x00000080u),8,flags));
  }
  L0076445d: { // 0x76445d: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L00764460: { // 0x764460: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L00764466: { // 0x764466: 7529 JNZ 0x00764491
    if(integer::condition("JNZ",flags)) goto L00764491;
  }
  L00764468: { // 0x764468: 8b7714 MOV ESI,dword ptr [EDI + 0x14]
    s.si = m.r32((s.di+0x00000014u));
  }
  L0076446b: { // 0x76446b: 81ce00010000 OR ESI,0x100
    s.si = integer::logical((s.si)|(0x00000100u),32,flags);
  }
  L00764471: { // 0x764471: 897714 MOV dword ptr [EDI + 0x14],ESI
    m.w32((s.di+0x00000014u), s.si);
  }
  L00764474: { // 0x764474: 8b8d24010000 MOV ECX,dword ptr [EBP + 0x124]
    s.cx = m.r32((s.bp+0x00000124u));
  }
  L0076447a: { // 0x76447a: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0076447c: { // 0x76447c: 0f844b0b0000 JZ 0x00764fcd
    if(integer::condition("JZ",flags)) goto L00764fcd;
  }
  L00764482: { // 0x764482: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00764483: { // 0x764483: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764484: { // 0x764484: 898d24010000 MOV dword ptr [EBP + 0x124],ECX
    m.w32((s.bp+0x00000124u), s.cx);
  }
  L0076448a: { // 0x76448a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076448b: { // 0x76448b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076448c: { // 0x76448c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076448d: { // 0x76448d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764490: { // 0x764490: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764491: { // 0x764491: 8b5714 MOV EDX,dword ptr [EDI + 0x14]
    s.dx = m.r32((s.di+0x00000014u));
  }
  L00764494: { // 0x764494: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00764498: { // 0x764498: 80ce02 OR DH,0x2
    s.dx = (s.dx & 0xffff00ffu) | (((integer::logical((((s.dx >> 8) & 0xffu))|(0x00000002u),8,flags)) & 0xffu) << 8);
  }
  L0076449b: { // 0x76449b: 895714 MOV dword ptr [EDI + 0x14],EDX
    m.w32((s.di+0x00000014u), s.dx);
  }
  L0076449e: { // 0x76449e: 8b9534010000 MOV EDX,dword ptr [EBP + 0x134]
    s.dx = m.r32((s.bp+0x00000134u));
  }
  L007644a4: { // 0x7644a4: 898d40010000 MOV dword ptr [EBP + 0x140],ECX
    m.w32((s.bp+0x00000140u), s.cx);
  }
  L007644aa: { // 0x7644aa: 8b8d50010000 MOV ECX,dword ptr [EBP + 0x150]
    s.cx = m.r32((s.bp+0x00000150u));
  }
  L007644b0: { // 0x7644b0: 80cd01 OR CH,0x1
    s.cx = (s.cx & 0xffff00ffu) | (((integer::logical((((s.cx >> 8) & 0xffu))|(0x00000001u),8,flags)) & 0xffu) << 8);
  }
  L007644b3: { // 0x7644b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007644b4: { // 0x7644b4: 899524010000 MOV dword ptr [EBP + 0x124],EDX
    m.w32((s.bp+0x00000124u), s.dx);
  }
  L007644ba: { // 0x7644ba: c78534010000ffffffff MOV dword ptr [EBP + 0x134],0xffffffff
    m.w32((s.bp+0x00000134u), 0xffffffffu);
  }
  L007644c4: { // 0x7644c4: 898d50010000 MOV dword ptr [EBP + 0x150],ECX
    m.w32((s.bp+0x00000150u), s.cx);
  }
  L007644ca: { // 0x7644ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007644cb: { // 0x7644cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007644cc: { // 0x7644cc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007644cd: { // 0x7644cd: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007644d0: { // 0x7644d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007644d1: { // 0x7644d1: 8b8d80010000 MOV ECX,dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L007644d7: { // 0x7644d7: 8bb51c010000 MOV ESI,dword ptr [EBP + 0x11c]
    s.si = m.r32((s.bp+0x0000011cu));
  }
  L007644dd: { // 0x7644dd: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L007644df: { // 0x7644df: 7e5f JLE 0x00764540
    if(integer::condition("JLE",flags)) goto L00764540;
  }
  L007644e1: { // 0x7644e1: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  L007644e4: { // 0x7644e4: 754d JNZ 0x00764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007644e6: { // 0x7644e6: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007644e8: { // 0x7644e8: 7449 JZ 0x00764533
    if(integer::condition("JZ",flags)) goto L00764533;
  }
  L007644ea: { // 0x7644ea: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007644ec: { // 0x7644ec: 7545 JNZ 0x00764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007644ee: { // 0x7644ee: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007644f0: { // 0x7644f0: e82bd9ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7750901u); flags=s.arithmetic_flags;
  }
  L007644f5: { // 0x7644f5: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L007644f8: { // 0x7644f8: 751b JNZ 0x00764515
    if(integer::condition("JNZ",flags)) goto L00764515;
  }
  L007644fa: { // 0x7644fa: 8b8550010000 MOV EAX,dword ptr [EBP + 0x150]
    s.ax = m.r32((s.bp+0x00000150u));
  }
  L00764500: { // 0x764500: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764501: { // 0x764501: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00764503: { // 0x764503: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764504: { // 0x764504: 898550010000 MOV dword ptr [EBP + 0x150],EAX
    m.w32((s.bp+0x00000150u), s.ax);
  }
  L0076450a: { // 0x76450a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076450b: { // 0x76450b: b8f5ffffff MOV EAX,0xfffffff5
    s.ax = 0xfffffff5u;
  }
  L00764510: { // 0x764510: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764511: { // 0x764511: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764514: { // 0x764514: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764515: { // 0x764515: 8b8d50010000 MOV ECX,dword ptr [EBP + 0x150]
    s.cx = m.r32((s.bp+0x00000150u));
  }
  L0076451b: { // 0x76451b: 8b85bc070000 MOV EAX,dword ptr [EBP + 0x7bc]
    s.ax = m.r32((s.bp+0x000007bcu));
  }
  L00764521: { // 0x764521: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L00764524: { // 0x764524: 80cc01 OR AH,0x1
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000001u),8,flags)) & 0xffu) << 8);
  }
  L00764527: { // 0x764527: 898d50010000 MOV dword ptr [EBP + 0x150],ECX
    m.w32((s.bp+0x00000150u), s.cx);
  }
  L0076452d: { // 0x76452d: 8985bc070000 MOV dword ptr [EBP + 0x7bc],EAX
    m.w32((s.bp+0x000007bcu), s.ax);
  }
  L00764533: { // 0x764533: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764534: { // 0x764534: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764535: { // 0x764535: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764536: { // 0x764536: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L0076453b: { // 0x76453b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076453c: { // 0x76453c: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0076453f: { // 0x76453f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764540: { // 0x764540: 8b4714 MOV EAX,dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L00764543: { // 0x764543: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00764545: { // 0x764545: 741f JZ 0x00764566
    if(integer::condition("JZ",flags)) goto L00764566;
  }
  L00764547: { // 0x764547: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0076454a: { // 0x76454a: 751a JNZ 0x00764566
    if(integer::condition("JNZ",flags)) goto L00764566;
  }
  L0076454c: { // 0x76454c: 8b8588010000 MOV EAX,dword ptr [EBP + 0x188]
    s.ax = m.r32((s.bp+0x00000188u));
  }
  L00764552: { // 0x764552: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764553: { // 0x764553: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764554: { // 0x764554: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764555: { // 0x764555: 898588010000 MOV dword ptr [EBP + 0x188],EAX
    m.w32((s.bp+0x00000188u), s.ax);
  }
  L0076455b: { // 0x76455b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076455c: { // 0x76455c: b8f7ffffff MOV EAX,0xfffffff7
    s.ax = 0xfffffff7u;
  }
  L00764561: { // 0x764561: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764562: { // 0x764562: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764565: { // 0x764565: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764566: { // 0x764566: f6855001000001 TEST byte ptr [EBP + 0x150],0x1
    (void)integer::logical((m.r8((s.bp+0x00000150u)))&(0x00000001u),8,flags);
  }
  L0076456d: { // 0x76456d: 750f JNZ 0x0076457e
    if(integer::condition("JNZ",flags)) goto L0076457e;
  }
  L0076456f: { // 0x76456f: 899590010000 MOV dword ptr [EBP + 0x190],EDX
    m.w32((s.bp+0x00000190u), s.dx);
  }
  L00764575: { // 0x764575: 8b9568010000 MOV EDX,dword ptr [EBP + 0x168]
    s.dx = m.r32((s.bp+0x00000168u));
  }
  L0076457b: { // 0x76457b: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L0076457e: { // 0x76457e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00764582: { // 0x764582: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764587: { // 0x764587: f6855001000001 TEST byte ptr [EBP + 0x150],0x1
    (void)integer::logical((m.r8((s.bp+0x00000150u)))&(0x00000001u),8,flags);
  }
  L0076458e: { // 0x76458e: 7550 JNZ 0x007645e0
    if(integer::condition("JNZ",flags)) goto L007645e0;
  }
  L00764590: { // 0x764590: 8db598010000 LEA ESI,[EBP + 0x198]
    s.si = (s.bp+0x00000198u);
  }
  L00764596: { // 0x764596: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00764598: { // 0x764598: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764599: { // 0x764599: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0076459b: { // 0x76459b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076459c: { // 0x76459c: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7751071u); flags=s.arithmetic_flags;
  }
  L0076459f: { // 0x76459f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007645a2: { // 0x7645a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007645a4: { // 0x7645a4: 758d JNZ 0x00764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007645a6: { // 0x7645a6: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L007645a9: { // 0x7645a9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007645ab: { // 0x7645ab: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L007645ad: { // 0x7645ad: 81e10000ff00 AND ECX,0xff0000
    s.cx = integer::logical((s.cx)&(0x00ff0000u),32,flags);
  }
  L007645b3: { // 0x7645b3: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L007645b6: { // 0x7645b6: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L007645b8: { // 0x7645b8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L007645ba: { // 0x7645ba: c1e210 SHL EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::left);
  }
  L007645bd: { // 0x7645bd: 2500ff0000 AND EAX,0xff00
    s.ax = integer::logical((s.ax)&(0x0000ff00u),32,flags);
  }
  L007645c2: { // 0x7645c2: 0bd0 OR EDX,EAX
    s.dx = integer::logical((s.dx)|(s.ax),32,flags);
  }
  L007645c4: { // 0x7645c4: c1e908 SHR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::right);
  }
  L007645c7: { // 0x7645c7: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L007645ca: { // 0x7645ca: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L007645cc: { // 0x7645cc: 890d2804b100 MOV dword ptr [0x00b10428],ECX
    m.w32((0x00b10428u), s.cx);
  }
  L007645d2: { // 0x7645d2: 8b8590010000 MOV EAX,dword ptr [EBP + 0x190]
    s.ax = m.r32((s.bp+0x00000190u));
  }
  L007645d8: { // 0x7645d8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L007645da: { // 0x7645da: 898590010000 MOV dword ptr [EBP + 0x190],EAX
    m.w32((s.bp+0x00000190u), s.ax);
  }
  L007645e0: { // 0x7645e0: 8b8598010000 MOV EAX,dword ptr [EBP + 0x198]
    s.ax = m.r32((s.bp+0x00000198u));
  }
  L007645e6: { // 0x7645e6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L007645e8: { // 0x7645e8: 3d5651464b CMP EAX,0x4b465156
    (void)integer::sub(s.ax,0x4b465156u,32,flags);
  }
  L007645ed: { // 0x7645ed: 0f8728040000 JA 0x00764a1b
    if(integer::condition("JA",flags)) goto L00764a1b;
  }
  L007645f3: { // 0x7645f3: 0f84eb030000 JZ 0x007649e4
    if(integer::condition("JZ",flags)) goto L007649e4;
  }
  L007645f9: { // 0x7645f9: 3d534e4131 CMP EAX,0x31414e53
    (void)integer::sub(s.ax,0x31414e53u,32,flags);
  }
  L007645fe: { // 0x7645fe: 0f87f0010000 JA 0x007647f4
    if(integer::condition("JA",flags)) goto L007647f4;
  }
  L00764604: { // 0x764604: 0f84c7010000 JZ 0x007647d1
    if(integer::condition("JZ",flags)) goto L007647d1;
  }
  L0076460a: { // 0x76460a: 3d43504c30 CMP EAX,0x304c5043
    (void)integer::sub(s.ax,0x304c5043u,32,flags);
  }
  L0076460f: { // 0x76460f: 0f8788010000 JA 0x0076479d
    if(integer::condition("JA",flags)) goto L0076479d;
  }
  L00764615: { // 0x764615: 0f84f2000000 JZ 0x0076470d
    if(integer::condition("JZ",flags)) goto L0076470d;
  }
  L0076461b: { // 0x76461b: 3d534e4130 CMP EAX,0x30414e53
    (void)integer::sub(s.ax,0x30414e53u,32,flags);
  }
  L00764620: { // 0x764620: 0f84c4000000 JZ 0x007646ea
    if(integer::condition("JZ",flags)) goto L007646ea;
  }
  L00764626: { // 0x764626: 3d534e4430 CMP EAX,0x30444e53
    (void)integer::sub(s.ax,0x30444e53u,32,flags);
  }
  L0076462b: { // 0x76462b: 7462 JZ 0x0076468f
    if(integer::condition("JZ",flags)) goto L0076468f;
  }
  L0076462d: { // 0x76462d: 3d43424630 CMP EAX,0x30464243
    (void)integer::sub(s.ax,0x30464243u,32,flags);
  }
  L00764632: { // 0x764632: 0f854a060000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764638: { // 0x764638: f644241410 TEST byte ptr [ESP + 0x14],0x10
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000010u),8,flags);
  }
  L0076463d: { // 0x76463d: 0f8565080000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764643: { // 0x764643: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764648: { // 0x764648: 8bb564010000 MOV ESI,dword ptr [EBP + 0x164]
    s.si = m.r32((s.bp+0x00000164u));
  }
  L0076464e: { // 0x76464e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00764650: { // 0x764650: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764651: { // 0x764651: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764653: { // 0x764653: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764654: { // 0x764654: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00764656: { // 0x764656: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764657: { // 0x764657: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764659: { // 0x764659: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076465a: { // 0x76465a: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7751261u); flags=s.arithmetic_flags;
  }
  L0076465d: { // 0x76465d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764660: { // 0x764660: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764662: { // 0x764662: 0f8581080000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764668: { // 0x764668: 898574010000 MOV dword ptr [EBP + 0x174],EAX
    m.w32((s.bp+0x00000174u), s.ax);
  }
  L0076466e: { // 0x76466e: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00764671: { // 0x764671: 897e14 MOV dword ptr [ESI + 0x14],EDI
    m.w32((s.si+0x00000014u), s.di);
  }
  L00764674: { // 0x764674: c7460c08000000 MOV dword ptr [ESI + 0xc],0x8
    m.w32((s.si+0x0000000cu), 0x00000008u);
  }
  L0076467b: { // 0x76467b: 89b568010000 MOV dword ptr [EBP + 0x168],ESI
    m.w32((s.bp+0x00000168u), s.si);
  }
  L00764681: { // 0x764681: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00764684: { // 0x764684: 898d64010000 MOV dword ptr [EBP + 0x164],ECX
    m.w32((s.bp+0x00000164u), s.cx);
  }
  L0076468a: { // 0x76468a: e9f3feffff JMP 0x00764582
    goto L00764582;
  }
  L0076468f: { // 0x76468f: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L00764694: { // 0x764694: 0f850e080000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L0076469a: { // 0x76469a: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007646a0: { // 0x7646a0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007646a2: { // 0x7646a2: 0f8400080000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007646a8: { // 0x7646a8: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007646aa: { // 0x7646aa: 0f85f8070000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007646b0: { // 0x7646b0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007646b2: { // 0x7646b2: e869d7ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7751351u); flags=s.arithmetic_flags;
  }
  L007646b7: { // 0x7646b7: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L007646ba: { // 0x7646ba: 0f840e080000 JZ 0x00764ece
    if(integer::condition("JZ",flags)) goto L00764ece;
  }
  L007646c0: { // 0x7646c0: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L007646c6: { // 0x7646c6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007646c8: { // 0x7646c8: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L007646cb: { // 0x7646cb: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L007646d1: { // 0x7646d1: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007646d7: { // 0x7646d7: e8f4250000 CALL 0x00766cd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766cd0u,7751388u); flags=s.arithmetic_flags;
  }
  L007646dc: { // 0x7646dc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007646df: { // 0x7646df: 0f8504080000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L007646e5: { // 0x7646e5: e99dfeffff JMP 0x00764587
    goto L00764587;
  }
  L007646ea: { // 0x7646ea: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L007646ef: { // 0x7646ef: 0f85b3070000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007646f5: { // 0x7646f5: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007646fb: { // 0x7646fb: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007646fd: { // 0x7646fd: 0f84a5070000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764703: { // 0x764703: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00764705: { // 0x764705: 0f849d070000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L0076470b: { // 0x76470b: eba3 JMP 0x007646b0
    goto L007646b0;
  }
  L0076470d: { // 0x76470d: f644241401 TEST byte ptr [ESP + 0x14],0x1
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000001u),8,flags);
  }
  L00764712: { // 0x764712: 0f8590070000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764718: { // 0x764718: 8b352804b100 MOV ESI,dword ptr [0x00b10428]
    s.si = m.r32((0x00b10428u));
  }
  L0076471e: { // 0x76471e: 8b9d70010000 MOV EBX,dword ptr [EBP + 0x170]
    s.bx = m.r32((s.bp+0x00000170u));
  }
  L00764724: { // 0x764724: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L00764727: { // 0x764727: 8d5601 LEA EDX,[ESI + 0x1]
    s.dx = (s.si+0x00000001u);
  }
  L0076472a: { // 0x76472a: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L0076472d: { // 0x76472d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0076472e: { // 0x76472e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076472f: { // 0x76472f: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764731: { // 0x764731: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764732: { // 0x764732: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7751477u); flags=s.arithmetic_flags;
  }
  L00764735: { // 0x764735: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764738: { // 0x764738: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076473a: { // 0x76473a: 0f85a9070000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764740: { // 0x764740: 8b4b14 MOV ECX,dword ptr [EBX + 0x14]
    s.cx = m.r32((s.bx+0x00000014u));
  }
  L00764743: { // 0x764743: 894324 MOV dword ptr [EBX + 0x24],EAX
    m.w32((s.bx+0x00000024u), s.ax);
  }
  L00764746: { // 0x764746: 83e1f7 AND ECX,0xfffffff7
    s.cx = integer::logical((s.cx)&(0xfffffff7u),32,flags);
  }
  L00764749: { // 0x764749: 897328 MOV dword ptr [EBX + 0x28],ESI
    m.w32((s.bx+0x00000028u), s.si);
  }
  L0076474c: { // 0x76474c: 894b14 MOV dword ptr [EBX + 0x14],ECX
    m.w32((s.bx+0x00000014u), s.cx);
  }
  L0076474f: { // 0x76474f: 6683bd5807000001 CMP word ptr [EBP + 0x758],0x1
    (void)integer::sub(m.r16((s.bp+0x00000758u)),0x00000001u,16,flags);
  }
  L00764757: { // 0x764757: 7530 JNZ 0x00764789
    if(integer::condition("JNZ",flags)) goto L00764789;
  }
  L00764759: { // 0x764759: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0076475b: { // 0x76475b: 8b7308 MOV ESI,dword ptr [EBX + 0x8]
    s.si = m.r32((s.bx+0x00000008u));
  }
  L0076475e: { // 0x76475e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00764760: { // 0x764760: 8dbdc4010000 LEA EDI,[EBP + 0x1c4]
    s.di = (s.bp+0x000001c4u);
  }
  L00764766: { // 0x764766: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L00764769: { // 0x764769: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076476b: { // 0x76476b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0076476d: { // 0x76476d: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L00764770: { // 0x764770: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00764772: { // 0x764772: 8b4328 MOV EAX,dword ptr [EBX + 0x28]
    s.ax = m.r32((s.bx+0x00000028u));
  }
  L00764775: { // 0x764775: 8985c0010000 MOV dword ptr [EBP + 0x1c0],EAX
    m.w32((s.bp+0x000001c0u), s.ax);
  }
  L0076477b: { // 0x76477b: 8b85a4010000 MOV EAX,dword ptr [EBP + 0x1a4]
    s.ax = m.r32((s.bp+0x000001a4u));
  }
  L00764781: { // 0x764781: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00764783: { // 0x764783: 8985a4010000 MOV dword ptr [EBP + 0x1a4],EAX
    m.w32((s.bp+0x000001a4u), s.ax);
  }
  L00764789: { // 0x764789: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0076478d: { // 0x76478d: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764792: { // 0x764792: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00764794: { // 0x764794: 83481404 OR dword ptr [EAX + 0x14],0x4
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000004u),32,flags));
  }
  L00764798: { // 0x764798: e9eafdffff JMP 0x00764587
    goto L00764587;
  }
  L0076479d: { // 0x76479d: 3d43425030 CMP EAX,0x30504243
    (void)integer::sub(s.ax,0x30504243u,32,flags);
  }
  L007647a2: { // 0x7647a2: 7410 JZ 0x007647b4
    if(integer::condition("JZ",flags)) goto L007647b4;
  }
  L007647a4: { // 0x7647a4: 3d56505430 CMP EAX,0x30545056
    (void)integer::sub(s.ax,0x30545056u,32,flags);
  }
  L007647a9: { // 0x7647a9: 0f84f3010000 JZ 0x007649a2
    if(integer::condition("JZ",flags)) goto L007649a2;
  }
  L007647af: { // 0x7647af: e9ce040000 JMP 0x00764c82
    goto L00764c82;
  }
  L007647b4: { // 0x7647b4: f644241408 TEST byte ptr [ESP + 0x14],0x8
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000008u),8,flags);
  }
  L007647b9: { // 0x7647b9: 0f85e9060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007647bf: { // 0x7647bf: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007647c5: { // 0x7647c5: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007647c7: { // 0x7647c7: e894210000 CALL 0x00766960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766960u,7751628u); flags=s.arithmetic_flags;
  }
  L007647cc: { // 0x7647cc: e90bffffff JMP 0x007646dc
    goto L007646dc;
  }
  L007647d1: { // 0x7647d1: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L007647d6: { // 0x7647d6: 0f85cc060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007647dc: { // 0x7647dc: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007647e2: { // 0x7647e2: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007647e4: { // 0x7647e4: 0f84be060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007647ea: { // 0x7647ea: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007647ec: { // 0x7647ec: 0f84b6060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007647f2: { // 0x7647f2: eb67 JMP 0x0076485b
    goto L0076485b;
  }
  L007647f4: { // 0x7647f4: 3d534e4432 CMP EAX,0x32444e53
    (void)integer::sub(s.ax,0x32444e53u,32,flags);
  }
  L007647f9: { // 0x7647f9: 0f87df000000 JA 0x007648de
    if(integer::condition("JA",flags)) goto L007648de;
  }
  L007647ff: { // 0x7647ff: 0f8487000000 JZ 0x0076488c
    if(integer::condition("JZ",flags)) goto L0076488c;
  }
  L00764805: { // 0x764805: 3d534e4431 CMP EAX,0x31444e53
    (void)integer::sub(s.ax,0x31444e53u,32,flags);
  }
  L0076480a: { // 0x76480a: 742e JZ 0x0076483a
    if(integer::condition("JZ",flags)) goto L0076483a;
  }
  L0076480c: { // 0x76480c: 3d534e4132 CMP EAX,0x32414e53
    (void)integer::sub(s.ax,0x32414e53u,32,flags);
  }
  L00764811: { // 0x764811: 0f856b040000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764817: { // 0x764817: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L0076481c: { // 0x76481c: 0f8586060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764822: { // 0x764822: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L00764828: { // 0x764828: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0076482a: { // 0x76482a: 0f8478060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764830: { // 0x764830: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00764832: { // 0x764832: 0f8470060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764838: { // 0x764838: eb73 JMP 0x007648ad
    goto L007648ad;
  }
  L0076483a: { // 0x76483a: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L0076483f: { // 0x76483f: 0f8563060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764845: { // 0x764845: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L0076484b: { // 0x76484b: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0076484d: { // 0x76484d: 0f8455060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L00764853: { // 0x764853: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L00764855: { // 0x764855: 0f854d060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L0076485b: { // 0x76485b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0076485d: { // 0x76485d: e8bed5ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7751778u); flags=s.arithmetic_flags;
  }
  L00764862: { // 0x764862: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L00764865: { // 0x764865: 0f8463060000 JZ 0x00764ece
    if(integer::condition("JZ",flags)) goto L00764ece;
  }
  L0076486b: { // 0x76486b: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L00764871: { // 0x764871: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764873: { // 0x764873: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00764876: { // 0x764876: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L0076487c: { // 0x76487c: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764882: { // 0x764882: e819250000 CALL 0x00766da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766da0u,7751815u); flags=s.arithmetic_flags;
  }
  L00764887: { // 0x764887: e950feffff JMP 0x007646dc
    goto L007646dc;
  }
  L0076488c: { // 0x76488c: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L00764891: { // 0x764891: 0f8511060000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764897: { // 0x764897: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L0076489d: { // 0x76489d: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0076489f: { // 0x76489f: 0f8403060000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L007648a5: { // 0x7648a5: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007648a7: { // 0x7648a7: 0f85fb050000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007648ad: { // 0x7648ad: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007648af: { // 0x7648af: e86cd5ffff CALL 0x00761e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7751860u); flags=s.arithmetic_flags;
  }
  L007648b4: { // 0x7648b4: 83f8f5 CMP EAX,-0xb
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L007648b7: { // 0x7648b7: 0f8411060000 JZ 0x00764ece
    if(integer::condition("JZ",flags)) goto L00764ece;
  }
  L007648bd: { // 0x7648bd: 8b9550010000 MOV EDX,dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L007648c3: { // 0x7648c3: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007648c5: { // 0x7648c5: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L007648c8: { // 0x7648c8: 899550010000 MOV dword ptr [EBP + 0x150],EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L007648ce: { // 0x7648ce: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007648d4: { // 0x7648d4: e887260000 CALL 0x00766f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766f60u,7751897u); flags=s.arithmetic_flags;
  }
  L007648d9: { // 0x7648d9: e9fefdffff JMP 0x007646dc
    goto L007646dc;
  }
  L007648de: { // 0x7648de: 3d56505444 CMP EAX,0x44545056
    (void)integer::sub(s.ax,0x44545056u,32,flags);
  }
  L007648e3: { // 0x7648e3: 0f84b9000000 JZ 0x007649a2
    if(integer::condition("JZ",flags)) goto L007649a2;
  }
  L007648e9: { // 0x7648e9: 3d534e324a CMP EAX,0x4a324e53
    (void)integer::sub(s.ax,0x4a324e53u,32,flags);
  }
  L007648ee: { // 0x7648ee: 0f858e030000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L007648f4: { // 0x7648f4: f644241402 TEST byte ptr [ESP + 0x14],0x2
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L007648f9: { // 0x7648f9: 0f85a9050000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L007648ff: { // 0x7648ff: 8b8584000000 MOV EAX,dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L00764905: { // 0x764905: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00764907: { // 0x764907: 0f849b050000 JZ 0x00764ea8
    if(integer::condition("JZ",flags)) goto L00764ea8;
  }
  L0076490d: { // 0x76490d: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L0076490f: { // 0x76490f: 0f8593050000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764915: { // 0x764915: 8b0d2804b100 MOV ECX,dword ptr [0x00b10428]
    s.cx = m.r32((0x00b10428u));
  }
  L0076491b: { // 0x76491b: 8d4101 LEA EAX,[ECX + 0x1]
    s.ax = (s.cx+0x00000001u);
  }
  L0076491e: { // 0x76491e: 8a8d84000000 MOV CL,byte ptr [EBP + 0x84]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000084u)));
  }
  L00764924: { // 0x764924: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764926: { // 0x764926: f6c101 TEST CL,0x1
    (void)integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags);
  }
  L00764929: { // 0x764929: 7465 JZ 0x00764990
    if(integer::condition("JZ",flags)) goto L00764990;
  }
  L0076492b: { // 0x76492b: 8b8d8c070000 MOV ECX,dword ptr [EBP + 0x78c]
    s.cx = m.r32((s.bp+0x0000078cu));
  }
  L00764931: { // 0x764931: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00764933: { // 0x764933: 745b JZ 0x00764990
    if(integer::condition("JZ",flags)) goto L00764990;
  }
  L00764935: { // 0x764935: 83f80c CMP EAX,0xc
    (void)integer::sub(s.ax,0x0000000cu,32,flags);
  }
  L00764938: { // 0x764938: 0f87ab050000 JA 0x00764ee9
    if(integer::condition("JA",flags)) goto L00764ee9;
  }
  L0076493e: { // 0x76493e: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00764942: { // 0x764942: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764943: { // 0x764943: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764944: { // 0x764944: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764946: { // 0x764946: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764947: { // 0x764947: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752010u); flags=s.arithmetic_flags;
  }
  L0076494a: { // 0x76494a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076494d: { // 0x76494d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076494f: { // 0x76494f: 0f8594050000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764955: { // 0x764955: 8b442426 MOV EAX,dword ptr [ESP + 0x26]
    s.ax = m.r32((f.sp+0x00000026u));
  }
  L00764959: { // 0x764959: 668b4c2424 MOV CX,word ptr [ESP + 0x24]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000024u)));
  }
  L0076495e: { // 0x76495e: 8985d0070000 MOV dword ptr [EBP + 0x7d0],EAX
    m.w32((s.bp+0x000007d0u), s.ax);
  }
  L00764964: { // 0x764964: 66898dd4070000 MOV word ptr [EBP + 0x7d4],CX
    m.w16((s.bp+0x000007d4u), (s.cx & 0xffffu));
  }
  L0076496b: { // 0x76496b: 807d3e02 CMP byte ptr [EBP + 0x3e],0x2
    (void)integer::sub(m.r8((s.bp+0x0000003eu)),0x00000002u,8,flags);
  }
  L0076496f: { // 0x76496f: 0f8512fcffff JNZ 0x00764587
    if(integer::condition("JNZ",flags)) goto L00764587;
  }
  L00764975: { // 0x764975: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L00764979: { // 0x764979: 668b44242a MOV AX,word ptr [ESP + 0x2a]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002au)));
  }
  L0076497e: { // 0x76497e: 8995d6070000 MOV dword ptr [EBP + 0x7d6],EDX
    m.w32((s.bp+0x000007d6u), s.dx);
  }
  L00764984: { // 0x764984: 668985da070000 MOV word ptr [EBP + 0x7da],AX
    m.w16((s.bp+0x000007dau), (s.ax & 0xffffu));
  }
  L0076498b: { // 0x76498b: e9f7fbffff JMP 0x00764587
    goto L00764587;
  }
  L00764990: { // 0x764990: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764991: { // 0x764991: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00764992: { // 0x764992: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00764994: { // 0x764994: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764995: { // 0x764995: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752088u); flags=s.arithmetic_flags;
  }
  L00764998: { // 0x764998: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076499b: { // 0x76499b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076499d: { // 0x76499d: e93dfdffff JMP 0x007646df
    goto L007646df;
  }
  L007649a2: { // 0x7649a2: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L007649a7: { // 0x7649a7: 0f85f3040000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L007649ad: { // 0x7649ad: 8b0d2804b100 MOV ECX,dword ptr [0x00b10428]
    s.cx = m.r32((0x00b10428u));
  }
  L007649b3: { // 0x7649b3: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L007649b9: { // 0x7649b9: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007649ba: { // 0x7649ba: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L007649bc: { // 0x7649bc: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L007649bf: { // 0x7649bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007649c0: { // 0x7649c0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007649c1: { // 0x7649c1: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007649c3: { // 0x7649c3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007649c4: { // 0x7649c4: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752135u); flags=s.arithmetic_flags;
  }
  L007649c7: { // 0x7649c7: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007649ca: { // 0x7649ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007649cc: { // 0x7649cc: 0f8517050000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L007649d2: { // 0x7649d2: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L007649d5: { // 0x7649d5: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L007649d7: { // 0x7649d7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L007649d9: { // 0x7649d9: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  L007649dc: { // 0x7649dc: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L007649df: { // 0x7649df: e9bc040000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L007649e4: { // 0x7649e4: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007649e8: { // 0x7649e8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L007649ea: { // 0x7649ea: 83e01d AND EAX,0x1d
    s.ax = integer::logical((s.ax)&(0x0000001du),32,flags);
  }
  L007649ed: { // 0x7649ed: 3c1d CMP AL,0x1d
    (void)integer::sub((s.ax & 0xffu),0x0000001du,8,flags);
  }
  L007649ef: { // 0x7649ef: 0f84ab040000 JZ 0x00764ea0
    if(integer::condition("JZ",flags)) goto L00764ea0;
  }
  L007649f5: { // 0x7649f5: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L007649fb: { // 0x7649fb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007649fc: { // 0x7649fc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L007649fe: { // 0x7649fe: e8cd0d0000 CALL 0x007657d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007657d0u,7752195u); flags=s.arithmetic_flags;
  }
  L00764a03: { // 0x764a03: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764a06: { // 0x764a06: 0f85dd040000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764a0c: { // 0x764a0c: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764a0f: { // 0x764a0f: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L00764a11: { // 0x764a11: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764a13: { // 0x764a13: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764a16: { // 0x764a16: e985040000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764a1b: { // 0x764a1b: 3d4342465a CMP EAX,0x5a464243
    (void)integer::sub(s.ax,0x5a464243u,32,flags);
  }
  L00764a20: { // 0x764a20: 0f876a010000 JA 0x00764b90
    if(integer::condition("JA",flags)) goto L00764b90;
  }
  L00764a26: { // 0x764a26: 0f8447010000 JZ 0x00764b73
    if(integer::condition("JZ",flags)) goto L00764b73;
  }
  L00764a2c: { // 0x764a2c: 3d56514652 CMP EAX,0x52465156
    (void)integer::sub(s.ax,0x52465156u,32,flags);
  }
  L00764a31: { // 0x764a31: 0f87dc000000 JA 0x00764b13
    if(integer::condition("JA",flags)) goto L00764b13;
  }
  L00764a37: { // 0x764a37: 0f84a6000000 JZ 0x00764ae3
    if(integer::condition("JZ",flags)) goto L00764ae3;
  }
  L00764a3d: { // 0x764a3d: 3d5650544b CMP EAX,0x4b545056
    (void)integer::sub(s.ax,0x4b545056u,32,flags);
  }
  L00764a42: { // 0x764a42: 7454 JZ 0x00764a98
    if(integer::condition("JZ",flags)) goto L00764a98;
  }
  L00764a44: { // 0x764a44: 3d5651464c CMP EAX,0x4c465156
    (void)integer::sub(s.ax,0x4c465156u,32,flags);
  }
  L00764a49: { // 0x764a49: 0f8533020000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764a4f: { // 0x764a4f: f644241420 TEST byte ptr [ESP + 0x14],0x20
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000020u),8,flags);
  }
  L00764a54: { // 0x764a54: 0f854e040000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764a5a: { // 0x764a5a: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00764a5e: { // 0x764a5e: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764a64: { // 0x764a64: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00764a65: { // 0x764a65: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764a67: { // 0x764a67: e8640d0000 CALL 0x007657d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007657d0u,7752300u); flags=s.arithmetic_flags;
  }
  L00764a6c: { // 0x764a6c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764a6f: { // 0x764a6f: 0f8574040000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764a75: { // 0x764a75: 8a85ea000000 MOV AL,byte ptr [EBP + 0xea]
    s.ax = with_al(s.ax, m.r8((s.bp+0x000000eau)));
  }
  L00764a7b: { // 0x764a7b: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L00764a80: { // 0x764a80: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00764a82: { // 0x764a82: 0f84fffaffff JZ 0x00764587
    if(integer::condition("JZ",flags)) goto L00764587;
  }
  L00764a88: { // 0x764a88: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764a8d: { // 0x764a8d: 0f8570040000 JNZ 0x00764f03
    if(integer::condition("JNZ",flags)) goto L00764f03;
  }
  L00764a93: { // 0x764a93: e9effaffff JMP 0x00764587
    goto L00764587;
  }
  L00764a98: { // 0x764a98: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764a9d: { // 0x764a9d: 0f85fd030000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764aa3: { // 0x764aa3: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764aa9: { // 0x764aa9: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L00764aaf: { // 0x764aaf: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00764ab0: { // 0x764ab0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00764ab2: { // 0x764ab2: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00764ab5: { // 0x764ab5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764ab6: { // 0x764ab6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764ab7: { // 0x764ab7: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764ab9: { // 0x764ab9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764aba: { // 0x764aba: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752381u); flags=s.arithmetic_flags;
  }
  L00764abd: { // 0x764abd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764ac0: { // 0x764ac0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764ac2: { // 0x764ac2: 0f8521040000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764ac8: { // 0x764ac8: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00764acb: { // 0x764acb: 83e1ef AND ECX,0xffffffef
    s.cx = integer::logical((s.cx)&(0xffffffefu),32,flags);
  }
  L00764ace: { // 0x764ace: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  L00764ad1: { // 0x764ad1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764ad3: { // 0x764ad3: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L00764ad6: { // 0x764ad6: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764ad9: { // 0x764ad9: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L00764adb: { // 0x764adb: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764ade: { // 0x764ade: e9bd030000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764ae3: { // 0x764ae3: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00764ae7: { // 0x764ae7: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00764ae9: { // 0x764ae9: 83e21d AND EDX,0x1d
    s.dx = integer::logical((s.dx)&(0x0000001du),32,flags);
  }
  L00764aec: { // 0x764aec: 80fa1d CMP DL,0x1d
    (void)integer::sub((s.dx & 0xffu),0x0000001du,8,flags);
  }
  L00764aef: { // 0x764aef: 0f84ab030000 JZ 0x00764ea0
    if(integer::condition("JZ",flags)) goto L00764ea0;
  }
  L00764af5: { // 0x764af5: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764afb: { // 0x764afb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764afc: { // 0x764afc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764afe: { // 0x764afe: e8cd0c0000 CALL 0x007657d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007657d0u,7752451u); flags=s.arithmetic_flags;
  }
  L00764b03: { // 0x764b03: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764b06: { // 0x764b06: 0f85dd030000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764b0c: { // 0x764b0c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764b0e: { // 0x764b0e: e98d030000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764b13: { // 0x764b13: 3d56505452 CMP EAX,0x52545056
    (void)integer::sub(s.ax,0x52545056u,32,flags);
  }
  L00764b18: { // 0x764b18: 7410 JZ 0x00764b2a
    if(integer::condition("JZ",flags)) goto L00764b2a;
  }
  L00764b1a: { // 0x764b1a: 3d5650445a CMP EAX,0x5a445056
    (void)integer::sub(s.ax,0x5a445056u,32,flags);
  }
  L00764b1f: { // 0x764b1f: 0f84ad020000 JZ 0x00764dd2
    if(integer::condition("JZ",flags)) goto L00764dd2;
  }
  L00764b25: { // 0x764b25: e958010000 JMP 0x00764c82
    goto L00764c82;
  }
  L00764b2a: { // 0x764b2a: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764b2f: { // 0x764b2f: 0f856b030000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764b35: { // 0x764b35: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764b3a: { // 0x764b3a: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L00764b40: { // 0x764b40: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764b41: { // 0x764b41: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00764b43: { // 0x764b43: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764b45: { // 0x764b45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764b46: { // 0x764b46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00764b47: { // 0x764b47: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764b49: { // 0x764b49: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764b4a: { // 0x764b4a: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752525u); flags=s.arithmetic_flags;
  }
  L00764b4d: { // 0x764b4d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764b50: { // 0x764b50: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764b52: { // 0x764b52: 0f8591030000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764b58: { // 0x764b58: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00764b5b: { // 0x764b5b: 83e1ef AND ECX,0xffffffef
    s.cx = integer::logical((s.cx)&(0xffffffefu),32,flags);
  }
  L00764b5e: { // 0x764b5e: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  L00764b61: { // 0x764b61: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764b63: { // 0x764b63: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L00764b66: { // 0x764b66: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764b69: { // 0x764b69: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  L00764b6b: { // 0x764b6b: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764b6e: { // 0x764b6e: e92d030000 JMP 0x00764ea0
    goto L00764ea0;
  }
  L00764b73: { // 0x764b73: f644241410 TEST byte ptr [ESP + 0x14],0x10
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000010u),8,flags);
  }
  L00764b78: { // 0x764b78: 0f852a030000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764b7e: { // 0x764b7e: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764b84: { // 0x764b84: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764b86: { // 0x764b86: e8551d0000 CALL 0x007668e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007668e0u,7752587u); flags=s.arithmetic_flags;
  }
  L00764b8b: { // 0x764b8b: e94cfbffff JMP 0x007646dc
    goto L007646dc;
  }
  L00764b90: { // 0x764b90: 3d4342505a CMP EAX,0x5a504243
    (void)integer::sub(s.ax,0x5a504243u,32,flags);
  }
  L00764b95: { // 0x764b95: 0f87d1000000 JA 0x00764c6c
    if(integer::condition("JA",flags)) goto L00764c6c;
  }
  L00764b9b: { // 0x764b9b: 0f84ae000000 JZ 0x00764c4f
    if(integer::condition("JZ",flags)) goto L00764c4f;
  }
  L00764ba1: { // 0x764ba1: 3d56504b5a CMP EAX,0x5a4b5056
    (void)integer::sub(s.ax,0x5a4b5056u,32,flags);
  }
  L00764ba6: { // 0x764ba6: 7439 JZ 0x00764be1
    if(integer::condition("JZ",flags)) goto L00764be1;
  }
  L00764ba8: { // 0x764ba8: 3d43504c5a CMP EAX,0x5a4c5043
    (void)integer::sub(s.ax,0x5a4c5043u,32,flags);
  }
  L00764bad: { // 0x764bad: 0f85cf000000 JNZ 0x00764c82
    if(integer::condition("JNZ",flags)) goto L00764c82;
  }
  L00764bb3: { // 0x764bb3: f644241401 TEST byte ptr [ESP + 0x14],0x1
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000001u),8,flags);
  }
  L00764bb8: { // 0x764bb8: 0f85ea020000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764bbe: { // 0x764bbe: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764bc4: { // 0x764bc4: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764bc6: { // 0x764bc6: e835200000 CALL 0x00766c00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766c00u,7752651u); flags=s.arithmetic_flags;
  }
  L00764bcb: { // 0x764bcb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00764bce: { // 0x764bce: 0f8515030000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764bd4: { // 0x764bd4: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764bd7: { // 0x764bd7: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L00764bd9: { // 0x764bd9: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764bdc: { // 0x764bdc: e9a6f9ffff JMP 0x00764587
    goto L00764587;
  }
  L00764be1: { // 0x764be1: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764be6: { // 0x764be6: 0f85b4020000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764bec: { // 0x764bec: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764bf1: { // 0x764bf1: 8bb56c070000 MOV ESI,dword ptr [EBP + 0x76c]
    s.si = m.r32((s.bp+0x0000076cu));
  }
  L00764bf7: { // 0x764bf7: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00764bfd: { // 0x764bfd: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00764c01: { // 0x764c01: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764c02: { // 0x764c02: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00764c04: { // 0x764c04: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764c06: { // 0x764c06: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00764c08: { // 0x764c08: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764c09: { // 0x764c09: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00764c0b: { // 0x764c0b: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00764c0d: { // 0x764c0d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764c0e: { // 0x764c0e: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764c10: { // 0x764c10: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764c11: { // 0x764c11: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7752724u); flags=s.arithmetic_flags;
  }
  L00764c14: { // 0x764c14: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764c17: { // 0x764c17: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764c19: { // 0x764c19: 0f85ca020000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764c1f: { // 0x764c1f: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00764c22: { // 0x764c22: 897720 MOV dword ptr [EDI + 0x20],ESI
    m.w32((s.di+0x00000020u), s.si);
  }
  L00764c25: { // 0x764c25: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00764c28: { // 0x764c28: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00764c2b: { // 0x764c2b: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00764c33: { // 0x764c33: 7309 JNC 0x00764c3e
    if(integer::condition("JNC",flags)) goto L00764c3e;
  }
  L00764c35: { // 0x764c35: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00764c39: { // 0x764c39: c644130180 MOV byte ptr [EBX + EDX*0x1 + 0x1],0x80
    m.w8((s.bx+(s.dx * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00764c3e: { // 0x764c3e: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00764c42: { // 0x764c42: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764c44: { // 0x764c44: 8b5014 MOV EDX,dword ptr [EAX + 0x14]
    s.dx = m.r32((s.ax+0x00000014u));
  }
  L00764c47: { // 0x764c47: 83ca02 OR EDX,0x2
    s.dx = integer::logical((s.dx)|(0x00000002u),32,flags);
  }
  L00764c4a: { // 0x764c4a: e945020000 JMP 0x00764e94
    goto L00764e94;
  }
  L00764c4f: { // 0x764c4f: f644241408 TEST byte ptr [ESP + 0x14],0x8
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000008u),8,flags);
  }
  L00764c54: { // 0x764c54: 0f854e020000 JNZ 0x00764ea8
    if(integer::condition("JNZ",flags)) goto L00764ea8;
  }
  L00764c5a: { // 0x764c5a: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764c60: { // 0x764c60: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00764c62: { // 0x764c62: e8191e0000 CALL 0x00766a80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766a80u,7752807u); flags=s.arithmetic_flags;
  }
  L00764c67: { // 0x764c67: e970faffff JMP 0x007646dc
    goto L007646dc;
  }
  L00764c6c: { // 0x764c6c: 3d5650525a CMP EAX,0x5a525056
    (void)integer::sub(s.ax,0x5a525056u,32,flags);
  }
  L00764c71: { // 0x764c71: 0f84ba010000 JZ 0x00764e31
    if(integer::condition("JZ",flags)) goto L00764e31;
  }
  L00764c77: { // 0x764c77: 3d5650545a CMP EAX,0x5a545056
    (void)integer::sub(s.ax,0x5a545056u,32,flags);
  }
  L00764c7c: { // 0x764c7c: 0f8450010000 JZ 0x00764dd2
    if(integer::condition("JZ",flags)) goto L00764dd2;
  }
  L00764c82: { // 0x764c82: 8b9524070000 MOV EDX,dword ptr [EBP + 0x724]
    s.dx = m.r32((s.bp+0x00000724u));
  }
  L00764c88: { // 0x764c88: 8bb534070000 MOV ESI,dword ptr [EBP + 0x734]
    s.si = m.r32((s.bp+0x00000734u));
  }
  L00764c8e: { // 0x764c8e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764c90: { // 0x764c90: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00764c92: { // 0x764c92: 760c JBE 0x00764ca0
    if(integer::condition("JBE",flags)) goto L00764ca0;
  }
  L00764c94: { // 0x764c94: 3b06 CMP EAX,dword ptr [ESI]
    (void)integer::sub(s.ax,m.r32((s.si)),32,flags);
  }
  L00764c96: { // 0x764c96: 7433 JZ 0x00764ccb
    if(integer::condition("JZ",flags)) goto L00764ccb;
  }
  L00764c98: { // 0x764c98: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764c99: { // 0x764c99: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L00764c9c: { // 0x764c9c: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00764c9e: { // 0x764c9e: 72f4 JC 0x00764c94
    if(integer::condition("JC",flags)) goto L00764c94;
  }
  L00764ca0: { // 0x764ca0: 8b953c070000 MOV EDX,dword ptr [EBP + 0x73c]
    s.dx = m.r32((s.bp+0x0000073cu));
  }
  L00764ca6: { // 0x764ca6: 8bb544070000 MOV ESI,dword ptr [EBP + 0x744]
    s.si = m.r32((s.bp+0x00000744u));
  }
  L00764cac: { // 0x764cac: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764cae: { // 0x764cae: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00764cb0: { // 0x764cb0: 0f86f2010000 JBE 0x00764ea8
    if(integer::condition("JBE",flags)) goto L00764ea8;
  }
  L00764cb6: { // 0x764cb6: 3b06 CMP EAX,dword ptr [ESI]
    (void)integer::sub(s.ax,m.r32((s.si)),32,flags);
  }
  L00764cb8: { // 0x764cb8: 0f8493000000 JZ 0x00764d51
    if(integer::condition("JZ",flags)) goto L00764d51;
  }
  L00764cbe: { // 0x764cbe: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764cbf: { // 0x764cbf: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L00764cc2: { // 0x764cc2: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00764cc4: { // 0x764cc4: 72f0 JC 0x00764cb6
    if(integer::condition("JC",flags)) goto L00764cb6;
  }
  L00764cc6: { // 0x764cc6: e9dd010000 JMP 0x00764ea8
    goto L00764ea8;
  }
  L00764ccb: { // 0x764ccb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00764ccd: { // 0x764ccd: 7cd1 JL 0x00764ca0
    if(integer::condition("JL",flags)) goto L00764ca0;
  }
  L00764ccf: { // 0x764ccf: 8b9538070000 MOV EDX,dword ptr [EBP + 0x738]
    s.dx = m.r32((s.bp+0x00000738u));
  }
  L00764cd5: { // 0x764cd5: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764cda: { // 0x764cda: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L00764cdd: { // 0x764cdd: 8d7001 LEA ESI,[EAX + 0x1]
    s.si = (s.ax+0x00000001u);
  }
  L00764ce0: { // 0x764ce0: 8b448a04 MOV EAX,dword ptr [EDX + ECX*0x4 + 0x4]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)+0x00000004u));
  }
  L00764ce4: { // 0x764ce4: 8d0c8a LEA ECX,[EDX + ECX*0x4]
    s.cx = (s.dx+(s.cx * 0x00000004u));
  }
  L00764ce7: { // 0x764ce7: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  L00764cea: { // 0x764cea: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764ced: { // 0x764ced: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L00764cf0: { // 0x764cf0: c1e202 SHL EDX,0x2
    s.dx = integer::shift(s.dx,0x00000002u,32,flags,integer::Shift::left);
  }
  L00764cf3: { // 0x764cf3: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00764cf5: { // 0x764cf5: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764cf6: { // 0x764cf6: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764cf8: { // 0x764cf8: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00764cfc: { // 0x764cfc: 8b1d2804b100 MOV EBX,dword ptr [0x00b10428]
    s.bx = m.r32((0x00b10428u));
  }
  L00764d02: { // 0x764d02: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00764d05: { // 0x764d05: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764d08: { // 0x764d08: 8b9d80010000 MOV EBX,dword ptr [EBP + 0x180]
    s.bx = m.r32((s.bp+0x00000180u));
  }
  L00764d0e: { // 0x764d0e: 895c1708 MOV dword ptr [EDI + EDX*0x1 + 0x8],EBX
    m.w32((s.di+(s.dx * 0x00000001u)+0x00000008u), s.bx);
  }
  L00764d12: { // 0x764d12: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00764d14: { // 0x764d14: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00764d16: { // 0x764d16: 7202 JC 0x00764d1a
    if(integer::condition("JC",flags)) goto L00764d1a;
  }
  L00764d18: { // 0x764d18: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764d1a: { // 0x764d1a: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00764d1d: { // 0x764d1d: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00764d21: { // 0x764d21: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764d22: { // 0x764d22: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764d23: { // 0x764d23: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764d25: { // 0x764d25: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764d26: { // 0x764d26: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753001u); flags=s.arithmetic_flags;
  }
  L00764d29: { // 0x764d29: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764d2c: { // 0x764d2c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764d2e: { // 0x764d2e: 0f85b5010000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764d34: { // 0x764d34: 8b8570010000 MOV EAX,dword ptr [EBP + 0x170]
    s.ax = m.r32((s.bp+0x00000170u));
  }
  L00764d3a: { // 0x764d3a: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00764d3e: { // 0x764d3e: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764d43: { // 0x764d43: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  L00764d46: { // 0x764d46: 80cd04 OR CH,0x4
    s.cx = (s.cx & 0xffff00ffu) | (((integer::logical((((s.cx >> 8) & 0xffu))|(0x00000004u),8,flags)) & 0xffu) << 8);
  }
  L00764d49: { // 0x764d49: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L00764d4c: { // 0x764d4c: e936f8ffff JMP 0x00764587
    goto L00764587;
  }
  L00764d51: { // 0x764d51: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00764d53: { // 0x764d53: 0f8c4f010000 JL 0x00764ea8
    if(integer::condition("JL",flags)) goto L00764ea8;
  }
  L00764d59: { // 0x764d59: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764d5f: { // 0x764d5f: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L00764d62: { // 0x764d62: 8b8d48070000 MOV ECX,dword ptr [EBP + 0x748]
    s.cx = m.r32((s.bp+0x00000748u));
  }
  L00764d68: { // 0x764d68: 8d7201 LEA ESI,[EDX + 0x1]
    s.si = (s.dx+0x00000001u);
  }
  L00764d6b: { // 0x764d6b: 8d0c81 LEA ECX,[ECX + EAX*0x4]
    s.cx = (s.cx+(s.ax * 0x00000004u));
  }
  L00764d6e: { // 0x764d6e: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  L00764d71: { // 0x764d71: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00764d74: { // 0x764d74: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764d77: { // 0x764d77: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L00764d7a: { // 0x764d7a: c1e202 SHL EDX,0x2
    s.dx = integer::shift(s.dx,0x00000002u,32,flags,integer::Shift::left);
  }
  L00764d7d: { // 0x764d7d: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00764d7f: { // 0x764d7f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764d80: { // 0x764d80: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764d82: { // 0x764d82: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00764d86: { // 0x764d86: 8b1d2804b100 MOV EBX,dword ptr [0x00b10428]
    s.bx = m.r32((0x00b10428u));
  }
  L00764d8c: { // 0x764d8c: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00764d8f: { // 0x764d8f: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00764d92: { // 0x764d92: 8b9d80010000 MOV EBX,dword ptr [EBP + 0x180]
    s.bx = m.r32((s.bp+0x00000180u));
  }
  L00764d98: { // 0x764d98: 895c1708 MOV dword ptr [EDI + EDX*0x1 + 0x8],EBX
    m.w32((s.di+(s.dx * 0x00000001u)+0x00000008u), s.bx);
  }
  L00764d9c: { // 0x764d9c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00764d9e: { // 0x764d9e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00764da0: { // 0x764da0: 7202 JC 0x00764da4
    if(integer::condition("JC",flags)) goto L00764da4;
  }
  L00764da2: { // 0x764da2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764da4: { // 0x764da4: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00764da8: { // 0x764da8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764da9: { // 0x764da9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764daa: { // 0x764daa: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764dac: { // 0x764dac: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764dad: { // 0x764dad: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00764db0: { // 0x764db0: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753139u); flags=s.arithmetic_flags;
  }
  L00764db3: { // 0x764db3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764db6: { // 0x764db6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764db8: { // 0x764db8: 0f852b010000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764dbe: { // 0x764dbe: 8b8570010000 MOV EAX,dword ptr [EBP + 0x170]
    s.ax = m.r32((s.bp+0x00000170u));
  }
  L00764dc4: { // 0x764dc4: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  L00764dc7: { // 0x764dc7: 80cd04 OR CH,0x4
    s.cx = (s.cx & 0xffff00ffu) | (((integer::logical((((s.cx >> 8) & 0xffu))|(0x00000004u),8,flags)) & 0xffu) << 8);
  }
  L00764dca: { // 0x764dca: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L00764dcd: { // 0x764dcd: e9acf7ffff JMP 0x0076457e
    goto L0076457e;
  }
  L00764dd2: { // 0x764dd2: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764dd7: { // 0x764dd7: 0f85c3000000 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764ddd: { // 0x764ddd: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764de2: { // 0x764de2: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00764de8: { // 0x764de8: 8bb56c070000 MOV ESI,dword ptr [EBP + 0x76c]
    s.si = m.r32((s.bp+0x0000076cu));
  }
  L00764dee: { // 0x764dee: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00764df2: { // 0x764df2: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764df4: { // 0x764df4: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764df5: { // 0x764df5: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764df7: { // 0x764df7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00764df9: { // 0x764df9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764dfa: { // 0x764dfa: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L00764dfc: { // 0x764dfc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764dfd: { // 0x764dfd: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764dff: { // 0x764dff: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764e00: { // 0x764e00: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753219u); flags=s.arithmetic_flags;
  }
  L00764e03: { // 0x764e03: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764e06: { // 0x764e06: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764e08: { // 0x764e08: 0f85db000000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764e0e: { // 0x764e0e: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00764e11: { // 0x764e11: 897720 MOV dword ptr [EDI + 0x20],ESI
    m.w32((s.di+0x00000020u), s.si);
  }
  L00764e14: { // 0x764e14: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00764e17: { // 0x764e17: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00764e1a: { // 0x764e1a: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00764e22: { // 0x764e22: 7309 JNC 0x00764e2d
    if(integer::condition("JNC",flags)) goto L00764e2d;
  }
  L00764e24: { // 0x764e24: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00764e28: { // 0x764e28: c644030180 MOV byte ptr [EBX + EAX*0x1 + 0x1],0x80
    m.w8((s.bx+(s.ax * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00764e2d: { // 0x764e2d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764e2f: { // 0x764e2f: eb66 JMP 0x00764e97
    goto L00764e97;
  }
  L00764e31: { // 0x764e31: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764e36: { // 0x764e36: 7568 JNZ 0x00764ea0
    if(integer::condition("JNZ",flags)) goto L00764ea0;
  }
  L00764e38: { // 0x764e38: a12804b100 MOV EAX,[0x00b10428]
    s.ax = m.r32((0x00b10428u));
  }
  L00764e3d: { // 0x764e3d: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00764e43: { // 0x764e43: 8bb56c070000 MOV ESI,dword ptr [EBP + 0x76c]
    s.si = m.r32((s.bp+0x0000076cu));
  }
  L00764e49: { // 0x764e49: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00764e4d: { // 0x764e4d: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00764e4f: { // 0x764e4f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764e50: { // 0x764e50: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00764e52: { // 0x764e52: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00764e54: { // 0x764e54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00764e55: { // 0x764e55: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L00764e57: { // 0x764e57: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764e58: { // 0x764e58: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00764e5a: { // 0x764e5a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764e5b: { // 0x764e5b: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753310u); flags=s.arithmetic_flags;
  }
  L00764e5e: { // 0x764e5e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764e61: { // 0x764e61: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764e63: { // 0x764e63: 0f8580000000 JNZ 0x00764ee9
    if(integer::condition("JNZ",flags)) goto L00764ee9;
  }
  L00764e69: { // 0x764e69: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00764e6c: { // 0x764e6c: 897720 MOV dword ptr [EDI + 0x20],ESI
    m.w32((s.di+0x00000020u), s.si);
  }
  L00764e6f: { // 0x764e6f: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00764e72: { // 0x764e72: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00764e75: { // 0x764e75: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00764e7d: { // 0x764e7d: 7309 JNC 0x00764e88
    if(integer::condition("JNC",flags)) goto L00764e88;
  }
  L00764e7f: { // 0x764e7f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00764e83: { // 0x764e83: c6440b0180 MOV byte ptr [EBX + ECX*0x1 + 0x1],0x80
    m.w8((s.bx+(s.cx * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00764e88: { // 0x764e88: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00764e8c: { // 0x764e8c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764e8e: { // 0x764e8e: 8b5014 MOV EDX,dword ptr [EAX + 0x14]
    s.dx = m.r32((s.ax+0x00000014u));
  }
  L00764e91: { // 0x764e91: 83ca20 OR EDX,0x20
    s.dx = integer::logical((s.dx)|(0x00000020u),32,flags);
  }
  L00764e94: { // 0x764e94: 895014 MOV dword ptr [EAX + 0x14],EDX
    m.w32((s.ax+0x00000014u), s.dx);
  }
  L00764e97: { // 0x764e97: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00764e9b: { // 0x764e9b: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764ea0: { // 0x764ea0: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00764ea2: { // 0x764ea2: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L00764ea6: { // 0x764ea6: 755b JNZ 0x00764f03
    if(integer::condition("JNZ",flags)) goto L00764f03;
  }
  L00764ea8: { // 0x764ea8: 8b152804b100 MOV EDX,dword ptr [0x00b10428]
    s.dx = m.r32((0x00b10428u));
  }
  L00764eae: { // 0x764eae: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00764eaf: { // 0x764eaf: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00764eb2: { // 0x764eb2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00764eb3: { // 0x764eb3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00764eb4: { // 0x764eb4: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00764eb6: { // 0x764eb6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764eb7: { // 0x764eb7: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7753402u); flags=s.arithmetic_flags;
  }
  L00764eba: { // 0x764eba: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00764ebd: { // 0x764ebd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764ebf: { // 0x764ebf: 7535 JNZ 0x00764ef6
    if(integer::condition("JNZ",flags)) goto L00764ef6;
  }
  L00764ec1: { // 0x764ec1: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00764ec5: { // 0x764ec5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764ec7: { // 0x764ec7: 753a JNZ 0x00764f03
    if(integer::condition("JNZ",flags)) goto L00764f03;
  }
  L00764ec9: { // 0x764ec9: e9b9f6ffff JMP 0x00764587
    goto L00764587;
  }
  L00764ece: { // 0x764ece: 8b8550010000 MOV EAX,dword ptr [EBP + 0x150]
    s.ax = m.r32((s.bp+0x00000150u));
  }
  L00764ed4: { // 0x764ed4: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  L00764ed6: { // 0x764ed6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764ed7: { // 0x764ed7: 898550010000 MOV dword ptr [EBP + 0x150],EAX
    m.w32((s.bp+0x00000150u), s.ax);
  }
  L00764edd: { // 0x764edd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764ede: { // 0x764ede: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764edf: { // 0x764edf: b8f5ffffff MOV EAX,0xfffffff5
    s.ax = 0xfffffff5u;
  }
  L00764ee4: { // 0x764ee4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764ee5: { // 0x764ee5: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764ee8: { // 0x764ee8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764ee9: { // 0x764ee9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764eea: { // 0x764eea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764eeb: { // 0x764eeb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764eec: { // 0x764eec: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00764ef1: { // 0x764ef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764ef2: { // 0x764ef2: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764ef5: { // 0x764ef5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764ef6: { // 0x764ef6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764ef7: { // 0x764ef7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764ef8: { // 0x764ef8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764ef9: { // 0x764ef9: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  L00764efe: { // 0x764efe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764eff: { // 0x764eff: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764f02: { // 0x764f02: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00764f03: { // 0x764f03: 8bb580010000 MOV ESI,dword ptr [EBP + 0x180]
    s.si = m.r32((s.bp+0x00000180u));
  }
  L00764f09: { // 0x764f09: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00764f0b: { // 0x764f0b: 7e18 JLE 0x00764f25
    if(integer::condition("JLE",flags)) goto L00764f25;
  }
  L00764f0d: { // 0x764f0d: 8b8590010000 MOV EAX,dword ptr [EBP + 0x190]
    s.ax = m.r32((s.bp+0x00000190u));
  }
  L00764f13: { // 0x764f13: 8b8d94010000 MOV ECX,dword ptr [EBP + 0x194]
    s.cx = m.r32((s.bp+0x00000194u));
  }
  L00764f19: { // 0x764f19: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00764f1b: { // 0x764f1b: 7e06 JLE 0x00764f23
    if(integer::condition("JLE",flags)) goto L00764f23;
  }
  L00764f1d: { // 0x764f1d: 898594010000 MOV dword ptr [EBP + 0x194],EAX
    m.w32((s.bp+0x00000194u), s.ax);
  }
  L00764f23: { // 0x764f23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00764f25: { // 0x764f25: 743f JZ 0x00764f66
    if(integer::condition("JZ",flags)) goto L00764f66;
  }
  L00764f27: { // 0x764f27: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764f29: { // 0x764f29: 668b8514070000 MOV AX,word ptr [EBP + 0x714]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000714u)));
  }
  L00764f30: { // 0x764f30: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764f32: { // 0x764f32: 7e53 JLE 0x00764f87
    if(integer::condition("JLE",flags)) goto L00764f87;
  }
  L00764f34: { // 0x764f34: f6851607000003 TEST byte ptr [EBP + 0x716],0x3
    (void)integer::logical((m.r8((s.bp+0x00000716u)))&(0x00000003u),8,flags);
  }
  L00764f3b: { // 0x764f3b: 744a JZ 0x00764f87
    if(integer::condition("JZ",flags)) goto L00764f87;
  }
  L00764f3d: { // 0x764f3d: 8b951c070000 MOV EDX,dword ptr [EBP + 0x71c]
    s.dx = m.r32((s.bp+0x0000071cu));
  }
  L00764f43: { // 0x764f43: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00764f45: { // 0x764f45: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764f47: { // 0x764f47: 7e3e JLE 0x00764f87
    if(integer::condition("JLE",flags)) goto L00764f87;
  }
  L00764f49: { // 0x764f49: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00764f4b: { // 0x764f4b: 668b3a MOV DI,word ptr [EDX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00764f4e: { // 0x764f4e: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00764f50: { // 0x764f50: 740f JZ 0x00764f61
    if(integer::condition("JZ",flags)) goto L00764f61;
  }
  L00764f52: { // 0x764f52: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764f53: { // 0x764f53: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L00764f56: { // 0x764f56: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00764f58: { // 0x764f58: 7cef JL 0x00764f49
    if(integer::condition("JL",flags)) goto L00764f49;
  }
  L00764f5a: { // 0x764f5a: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764f5f: { // 0x764f5f: eb26 JMP 0x00764f87
    goto L00764f87;
  }
  L00764f61: { // 0x764f61: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00764f66: { // 0x764f66: f644241420 TEST byte ptr [ESP + 0x14],0x20
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000020u),8,flags);
  }
  L00764f6b: { // 0x764f6b: 751a JNZ 0x00764f87
    if(integer::condition("JNZ",flags)) goto L00764f87;
  }
  L00764f6d: { // 0x764f6d: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00764f71: { // 0x764f71: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00764f73: { // 0x764f73: 7512 JNZ 0x00764f87
    if(integer::condition("JNZ",flags)) goto L00764f87;
  }
  L00764f75: { // 0x764f75: 8b8564010000 MOV EAX,dword ptr [EBP + 0x164]
    s.ax = m.r32((s.bp+0x00000164u));
  }
  L00764f7b: { // 0x764f7b: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00764f7e: { // 0x764f7e: 898568010000 MOV dword ptr [EBP + 0x168],EAX
    m.w32((s.bp+0x00000168u), s.ax);
  }
  L00764f84: { // 0x764f84: 894304 MOV dword ptr [EBX + 0x4],EAX
    m.w32((s.bx+0x00000004u), s.ax);
  }
  L00764f87: { // 0x764f87: f644241404 TEST byte ptr [ESP + 0x14],0x4
    (void)integer::logical((m.r8((f.sp+0x00000014u)))&(0x00000004u),8,flags);
  }
  L00764f8c: { // 0x764f8c: 752f JNZ 0x00764fbd
    if(integer::condition("JNZ",flags)) goto L00764fbd;
  }
  L00764f8e: { // 0x764f8e: 8b8d80010000 MOV ECX,dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L00764f94: { // 0x764f94: 894b1c MOV dword ptr [EBX + 0x1c],ECX
    m.w32((s.bx+0x0000001cu), s.cx);
  }
  L00764f97: { // 0x764f97: 8b9580010000 MOV EDX,dword ptr [EBP + 0x180]
    s.dx = m.r32((s.bp+0x00000180u));
  }
  L00764f9d: { // 0x764f9d: 899584010000 MOV dword ptr [EBP + 0x184],EDX
    m.w32((s.bp+0x00000184u), s.dx);
  }
  L00764fa3: { // 0x764fa3: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00764fa6: { // 0x764fa6: 89856c010000 MOV dword ptr [EBP + 0x16c],EAX
    m.w32((s.bp+0x0000016cu), s.ax);
  }
  L00764fac: { // 0x764fac: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00764faf: { // 0x764faf: 8b4b0c MOV ECX,dword ptr [EBX + 0xc]
    s.cx = m.r32((s.bx+0x0000000cu));
  }
  L00764fb2: { // 0x764fb2: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  L00764fb4: { // 0x764fb4: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L00764fb7: { // 0x764fb7: 898d70010000 MOV dword ptr [EBP + 0x170],ECX
    m.w32((s.bp+0x00000170u), s.cx);
  }
  L00764fbd: { // 0x764fbd: 8b8580010000 MOV EAX,dword ptr [EBP + 0x180]
    s.ax = m.r32((s.bp+0x00000180u));
  }
  L00764fc3: { // 0x764fc3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00764fc4: { // 0x764fc4: 898580010000 MOV dword ptr [EBP + 0x180],EAX
    m.w32((s.bp+0x00000180u), s.ax);
  }
  L00764fca: { // 0x764fca: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00764fcd: { // 0x764fcd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764fce: { // 0x764fce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764fcf: { // 0x764fcf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00764fd0: { // 0x764fd0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764fd1: { // 0x764fd1: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764fd4: { // 0x764fd4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_007657d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007657d0: { // 0x7657d0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L007657d3: { // 0x7657d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007657d4: { // 0x7657d4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007657d5: { // 0x7657d5: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L007657d7: { // 0x7657d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007657d8: { // 0x7657d8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007657d9: { // 0x7657d9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L007657db: { // 0x7657db: 8b8570010000 MOV EAX,dword ptr [EBP + 0x170]
    s.ax = m.r32((s.bp+0x00000170u));
  }
  L007657e1: { // 0x7657e1: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L007657e5: { // 0x7657e5: 8d4201 LEA EAX,[EDX + 0x1]
    s.ax = (s.dx+0x00000001u);
  }
  L007657e8: { // 0x7657e8: 83e0fe AND EAX,0xfffffffe
    s.ax = integer::logical((s.ax)&(0xfffffffeu),32,flags);
  }
  L007657eb: { // 0x7657eb: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L007657ef: { // 0x7657ef: 0f867a040000 JBE 0x00765c6f
    if(integer::condition("JBE",flags)) goto L00765c6f;
  }
  L007657f5: { // 0x7657f5: 8d9d98010000 LEA EBX,[EBP + 0x198]
    s.bx = (s.bp+0x00000198u);
  }
  L007657fb: { // 0x7657fb: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L007657fd: { // 0x7657fd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007657fe: { // 0x7657fe: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765800: { // 0x765800: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765801: { // 0x765801: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7755780u); flags=s.arithmetic_flags;
  }
  L00765804: { // 0x765804: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765807: { // 0x765807: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765809: { // 0x765809: 0f8533040000 JNZ 0x00765c42
    if(integer::condition("JNZ",flags)) goto L00765c42;
  }
  L0076580f: { // 0x76580f: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00765812: { // 0x765812: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00765814: { // 0x765814: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00765816: { // 0x765816: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00765818: { // 0x765818: 81e60000ff00 AND ESI,0xff0000
    s.si = integer::logical((s.si)&(0x00ff0000u),32,flags);
  }
  L0076581e: { // 0x76581e: c1e910 SHR ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00765821: { // 0x765821: c1e210 SHL EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00765824: { // 0x765824: 2500ff0000 AND EAX,0xff00
    s.ax = integer::logical((s.ax)&(0x0000ff00u),32,flags);
  }
  L00765829: { // 0x765829: 0bf1 OR ESI,ECX
    s.si = integer::logical((s.si)|(s.cx),32,flags);
  }
  L0076582b: { // 0x76582b: 0bd0 OR EDX,EAX
    s.dx = integer::logical((s.dx)|(s.ax),32,flags);
  }
  L0076582d: { // 0x76582d: c1ee08 SHR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::right);
  }
  L00765830: { // 0x765830: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00765833: { // 0x765833: 0bf2 OR ESI,EDX
    s.si = integer::logical((s.si)|(s.dx),32,flags);
  }
  L00765835: { // 0x765835: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  L00765838: { // 0x765838: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0076583a: { // 0x76583a: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L0076583d: { // 0x76583d: 8d540f08 LEA EDX,[EDI + ECX*0x1 + 0x8]
    s.dx = (s.di+(s.cx * 0x00000001u)+0x00000008u);
  }
  L00765841: { // 0x765841: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00765845: { // 0x765845: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00765847: { // 0x765847: 81fa5650445a CMP EDX,0x5a445056
    (void)integer::sub(s.dx,0x5a445056u,32,flags);
  }
  L0076584d: { // 0x76584d: 0f870a020000 JA 0x00765a5d
    if(integer::condition("JA",flags)) goto L00765a5d;
  }
  L00765853: { // 0x765853: 0f841a030000 JZ 0x00765b73
    if(integer::condition("JZ",flags)) goto L00765b73;
  }
  L00765859: { // 0x765859: 81fa56505430 CMP EDX,0x30545056
    (void)integer::sub(s.dx,0x30545056u,32,flags);
  }
  L0076585f: { // 0x76585f: 0f871a010000 JA 0x0076597f
    if(integer::condition("JA",flags)) goto L0076597f;
  }
  L00765865: { // 0x765865: 0f84b6010000 JZ 0x00765a21
    if(integer::condition("JZ",flags)) goto L00765a21;
  }
  L0076586b: { // 0x76586b: 81fa43424630 CMP EDX,0x30464243
    (void)integer::sub(s.dx,0x30464243u,32,flags);
  }
  L00765871: { // 0x765871: 0f84b9000000 JZ 0x00765930
    if(integer::condition("JZ",flags)) goto L00765930;
  }
  L00765877: { // 0x765877: 81fa43504c30 CMP EDX,0x304c5043
    (void)integer::sub(s.dx,0x304c5043u,32,flags);
  }
  L0076587d: { // 0x76587d: 742e JZ 0x007658ad
    if(integer::condition("JZ",flags)) goto L007658ad;
  }
  L0076587f: { // 0x76587f: 81fa43425030 CMP EDX,0x30504243
    (void)integer::sub(s.dx,0x30504243u,32,flags);
  }
  L00765885: { // 0x765885: 0f85c6030000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L0076588b: { // 0x76588b: f644242408 TEST byte ptr [ESP + 0x24],0x8
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000008u),8,flags);
  }
  L00765890: { // 0x765890: 0f8587030000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765896: { // 0x765896: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765898: { // 0x765898: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0076589a: { // 0x76589a: e8c1100000 CALL 0x00766960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766960u,7755935u); flags=s.arithmetic_flags;
  }
  L0076589f: { // 0x76589f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L007658a2: { // 0x7658a2: 0f85a9030000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L007658a8: { // 0x7658a8: e982030000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L007658ad: { // 0x7658ad: f644242401 TEST byte ptr [ESP + 0x24],0x1
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000001u),8,flags);
  }
  L007658b2: { // 0x7658b2: 0f8565030000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L007658b8: { // 0x7658b8: 8b9d70010000 MOV EBX,dword ptr [EBP + 0x170]
    s.bx = m.r32((s.bp+0x00000170u));
  }
  L007658be: { // 0x7658be: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007658c0: { // 0x7658c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007658c1: { // 0x7658c1: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L007658c4: { // 0x7658c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007658c5: { // 0x7658c5: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007658c7: { // 0x7658c7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007658c8: { // 0x7658c8: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7755979u); flags=s.arithmetic_flags;
  }
  L007658cb: { // 0x7658cb: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007658ce: { // 0x7658ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007658d0: { // 0x7658d0: 0f857b030000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L007658d6: { // 0x7658d6: 8b5314 MOV EDX,dword ptr [EBX + 0x14]
    s.dx = m.r32((s.bx+0x00000014u));
  }
  L007658d9: { // 0x7658d9: 894324 MOV dword ptr [EBX + 0x24],EAX
    m.w32((s.bx+0x00000024u), s.ax);
  }
  L007658dc: { // 0x7658dc: 83e2f7 AND EDX,0xfffffff7
    s.dx = integer::logical((s.dx)&(0xfffffff7u),32,flags);
  }
  L007658df: { // 0x7658df: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L007658e4: { // 0x7658e4: 895314 MOV dword ptr [EBX + 0x14],EDX
    m.w32((s.bx+0x00000014u), s.dx);
  }
  L007658e7: { // 0x7658e7: 897328 MOV dword ptr [EBX + 0x28],ESI
    m.w32((s.bx+0x00000028u), s.si);
  }
  L007658ea: { // 0x7658ea: 66398558070000 CMP word ptr [EBP + 0x758],AX
    (void)integer::sub(m.r16((s.bp+0x00000758u)),(s.ax & 0xffffu),16,flags);
  }
  L007658f1: { // 0x7658f1: 7530 JNZ 0x00765923
    if(integer::condition("JNZ",flags)) goto L00765923;
  }
  L007658f3: { // 0x7658f3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007658f5: { // 0x7658f5: 8b7308 MOV ESI,dword ptr [EBX + 0x8]
    s.si = m.r32((s.bx+0x00000008u));
  }
  L007658f8: { // 0x7658f8: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007658fa: { // 0x7658fa: 8dbdc4010000 LEA EDI,[EBP + 0x1c4]
    s.di = (s.bp+0x000001c4u);
  }
  L00765900: { // 0x765900: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L00765903: { // 0x765903: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00765905: { // 0x765905: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00765907: { // 0x765907: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0076590a: { // 0x76590a: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L0076590c: { // 0x76590c: 8b4b28 MOV ECX,dword ptr [EBX + 0x28]
    s.cx = m.r32((s.bx+0x00000028u));
  }
  L0076590f: { // 0x76590f: 898dc0010000 MOV dword ptr [EBP + 0x1c0],ECX
    m.w32((s.bp+0x000001c0u), s.cx);
  }
  L00765915: { // 0x765915: 8b8da4010000 MOV ECX,dword ptr [EBP + 0x1a4]
    s.cx = m.r32((s.bp+0x000001a4u));
  }
  L0076591b: { // 0x76591b: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  L0076591d: { // 0x76591d: 898da4010000 MOV dword ptr [EBP + 0x1a4],ECX
    m.w32((s.bp+0x000001a4u), s.cx);
  }
  L00765923: { // 0x765923: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765927: { // 0x765927: 83481404 OR dword ptr [EAX + 0x14],0x4
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000004u),32,flags));
  }
  L0076592b: { // 0x76592b: e9ff020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765930: { // 0x765930: f644242410 TEST byte ptr [ESP + 0x24],0x10
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000010u),8,flags);
  }
  L00765935: { // 0x765935: 0f85e2020000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L0076593b: { // 0x76593b: 8b9d64010000 MOV EBX,dword ptr [EBP + 0x164]
    s.bx = m.r32((s.bp+0x00000164u));
  }
  L00765941: { // 0x765941: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765943: { // 0x765943: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765944: { // 0x765944: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00765946: { // 0x765946: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00765947: { // 0x765947: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765949: { // 0x765949: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076594a: { // 0x76594a: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756109u); flags=s.arithmetic_flags;
  }
  L0076594d: { // 0x76594d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765950: { // 0x765950: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765952: { // 0x765952: 0f85f9020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765958: { // 0x765958: 898574010000 MOV dword ptr [EBP + 0x174],EAX
    m.w32((s.bp+0x00000174u), s.ax);
  }
  L0076595e: { // 0x76595e: 894310 MOV dword ptr [EBX + 0x10],EAX
    m.w32((s.bx+0x00000010u), s.ax);
  }
  L00765961: { // 0x765961: 897314 MOV dword ptr [EBX + 0x14],ESI
    m.w32((s.bx+0x00000014u), s.si);
  }
  L00765964: { // 0x765964: c7430c08000000 MOV dword ptr [EBX + 0xc],0x8
    m.w32((s.bx+0x0000000cu), 0x00000008u);
  }
  L0076596b: { // 0x76596b: 899d68010000 MOV dword ptr [EBP + 0x168],EBX
    m.w32((s.bp+0x00000168u), s.bx);
  }
  L00765971: { // 0x765971: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00765974: { // 0x765974: 898564010000 MOV dword ptr [EBP + 0x164],EAX
    m.w32((s.bp+0x00000164u), s.ax);
  }
  L0076597a: { // 0x76597a: e9b0020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L0076597f: { // 0x76597f: 81fa56505444 CMP EDX,0x44545056
    (void)integer::sub(s.dx,0x44545056u,32,flags);
  }
  L00765985: { // 0x765985: 0f8496000000 JZ 0x00765a21
    if(integer::condition("JZ",flags)) goto L00765a21;
  }
  L0076598b: { // 0x76598b: 81fa5650544b CMP EDX,0x4b545056
    (void)integer::sub(s.dx,0x4b545056u,32,flags);
  }
  L00765991: { // 0x765991: 744d JZ 0x007659e0
    if(integer::condition("JZ",flags)) goto L007659e0;
  }
  L00765993: { // 0x765993: 81fa56505452 CMP EDX,0x52545056
    (void)integer::sub(s.dx,0x52545056u,32,flags);
  }
  L00765999: { // 0x765999: 0f85b2020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L0076599f: { // 0x76599f: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L007659a4: { // 0x7659a4: 0f8573020000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L007659aa: { // 0x7659aa: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L007659b0: { // 0x7659b0: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007659b2: { // 0x7659b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007659b3: { // 0x7659b3: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L007659b5: { // 0x7659b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007659b6: { // 0x7659b6: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007659b8: { // 0x7659b8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007659b9: { // 0x7659b9: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756220u); flags=s.arithmetic_flags;
  }
  L007659bc: { // 0x7659bc: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007659bf: { // 0x7659bf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007659c1: { // 0x7659c1: 0f858a020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L007659c7: { // 0x7659c7: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  L007659ca: { // 0x7659ca: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  L007659cd: { // 0x7659cd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L007659d1: { // 0x7659d1: 83e2ef AND EDX,0xffffffef
    s.dx = integer::logical((s.dx)&(0xffffffefu),32,flags);
  }
  L007659d4: { // 0x7659d4: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L007659d7: { // 0x7659d7: 83481420 OR dword ptr [EAX + 0x14],0x20
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000020u),32,flags));
  }
  L007659db: { // 0x7659db: e94f020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L007659e0: { // 0x7659e0: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L007659e5: { // 0x7659e5: 0f8532020000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L007659eb: { // 0x7659eb: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L007659f1: { // 0x7659f1: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007659f3: { // 0x7659f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007659f4: { // 0x7659f4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L007659f6: { // 0x7659f6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007659f7: { // 0x7659f7: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007659f9: { // 0x7659f9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007659fa: { // 0x7659fa: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756285u); flags=s.arithmetic_flags;
  }
  L007659fd: { // 0x7659fd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765a00: { // 0x765a00: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765a02: { // 0x765a02: 0f8549020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765a08: { // 0x765a08: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  L00765a0b: { // 0x765a0b: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  L00765a0e: { // 0x765a0e: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765a12: { // 0x765a12: 83e2ef AND EDX,0xffffffef
    s.dx = integer::logical((s.dx)&(0xffffffefu),32,flags);
  }
  L00765a15: { // 0x765a15: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L00765a18: { // 0x765a18: 83481402 OR dword ptr [EAX + 0x14],0x2
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000002u),32,flags));
  }
  L00765a1c: { // 0x765a1c: e90e020000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765a21: { // 0x765a21: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765a26: { // 0x765a26: 0f85f1010000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765a2c: { // 0x765a2c: 8bb570010000 MOV ESI,dword ptr [EBP + 0x170]
    s.si = m.r32((s.bp+0x00000170u));
  }
  L00765a32: { // 0x765a32: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765a34: { // 0x765a34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765a35: { // 0x765a35: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00765a37: { // 0x765a37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765a38: { // 0x765a38: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765a3a: { // 0x765a3a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765a3b: { // 0x765a3b: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756350u); flags=s.arithmetic_flags;
  }
  L00765a3e: { // 0x765a3e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765a41: { // 0x765a41: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765a43: { // 0x765a43: 0f8508020000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765a49: { // 0x765a49: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00765a4c: { // 0x765a4c: c7462000000000 MOV dword ptr [ESI + 0x20],0x0
    m.w32((s.si+0x00000020u), 0x00000000u);
  }
  L00765a53: { // 0x765a53: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L00765a55: { // 0x765a55: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  L00765a58: { // 0x765a58: e9d2010000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765a5d: { // 0x765a5d: 81fa4342505a CMP EDX,0x5a504243
    (void)integer::sub(s.dx,0x5a504243u,32,flags);
  }
  L00765a63: { // 0x765a63: 0f87f6000000 JA 0x00765b5f
    if(integer::condition("JA",flags)) goto L00765b5f;
  }
  L00765a69: { // 0x765a69: 0f84ce000000 JZ 0x00765b3d
    if(integer::condition("JZ",flags)) goto L00765b3d;
  }
  L00765a6f: { // 0x765a6f: 81fa4342465a CMP EDX,0x5a464243
    (void)integer::sub(s.dx,0x5a464243u,32,flags);
  }
  L00765a75: { // 0x765a75: 0f84a0000000 JZ 0x00765b1b
    if(integer::condition("JZ",flags)) goto L00765b1b;
  }
  L00765a7b: { // 0x765a7b: 81fa56504b5a CMP EDX,0x5a4b5056
    (void)integer::sub(s.dx,0x5a4b5056u,32,flags);
  }
  L00765a81: { // 0x765a81: 7436 JZ 0x00765ab9
    if(integer::condition("JZ",flags)) goto L00765ab9;
  }
  L00765a83: { // 0x765a83: 81fa43504c5a CMP EDX,0x5a4c5043
    (void)integer::sub(s.dx,0x5a4c5043u,32,flags);
  }
  L00765a89: { // 0x765a89: 0f85c2010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765a8f: { // 0x765a8f: f644242401 TEST byte ptr [ESP + 0x24],0x1
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000001u),8,flags);
  }
  L00765a94: { // 0x765a94: 0f8583010000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765a9a: { // 0x765a9a: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765a9c: { // 0x765a9c: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00765a9e: { // 0x765a9e: e85d110000 CALL 0x00766c00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766c00u,7756451u); flags=s.arithmetic_flags;
  }
  L00765aa3: { // 0x765aa3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00765aa6: { // 0x765aa6: 0f85a5010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765aac: { // 0x765aac: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765ab0: { // 0x765ab0: 83481404 OR dword ptr [EAX + 0x14],0x4
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000004u),32,flags));
  }
  L00765ab4: { // 0x765ab4: e976010000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765ab9: { // 0x765ab9: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765abe: { // 0x765abe: 0f8559010000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765ac4: { // 0x765ac4: 8b9d6c070000 MOV EBX,dword ptr [EBP + 0x76c]
    s.bx = m.r32((s.bp+0x0000076cu));
  }
  L00765aca: { // 0x765aca: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00765ad0: { // 0x765ad0: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00765ad2: { // 0x765ad2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765ad3: { // 0x765ad3: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00765ad5: { // 0x765ad5: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00765ad7: { // 0x765ad7: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00765ad9: { // 0x765ad9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765ada: { // 0x765ada: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765adc: { // 0x765adc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765add: { // 0x765add: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00765ae1: { // 0x765ae1: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756516u); flags=s.arithmetic_flags;
  }
  L00765ae4: { // 0x765ae4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765ae7: { // 0x765ae7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765ae9: { // 0x765ae9: 0f8562010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765aef: { // 0x765aef: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00765af2: { // 0x765af2: 895f20 MOV dword ptr [EDI + 0x20],EBX
    m.w32((s.di+0x00000020u), s.bx);
  }
  L00765af5: { // 0x765af5: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00765af8: { // 0x765af8: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00765afb: { // 0x765afb: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00765b03: { // 0x765b03: 7309 JNC 0x00765b0e
    if(integer::condition("JNC",flags)) goto L00765b0e;
  }
  L00765b05: { // 0x765b05: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00765b09: { // 0x765b09: c644310180 MOV byte ptr [ECX + ESI*0x1 + 0x1],0x80
    m.w8((s.cx+(s.si * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00765b0e: { // 0x765b0e: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765b12: { // 0x765b12: 83481402 OR dword ptr [EAX + 0x14],0x2
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000002u),32,flags));
  }
  L00765b16: { // 0x765b16: e914010000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765b1b: { // 0x765b1b: f644242410 TEST byte ptr [ESP + 0x24],0x10
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000010u),8,flags);
  }
  L00765b20: { // 0x765b20: 0f85f7000000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765b26: { // 0x765b26: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765b28: { // 0x765b28: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00765b2a: { // 0x765b2a: e8b10d0000 CALL 0x007668e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007668e0u,7756591u); flags=s.arithmetic_flags;
  }
  L00765b2f: { // 0x765b2f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00765b32: { // 0x765b32: 0f8519010000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765b38: { // 0x765b38: e9f2000000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765b3d: { // 0x765b3d: f644242408 TEST byte ptr [ESP + 0x24],0x8
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000008u),8,flags);
  }
  L00765b42: { // 0x765b42: 0f85d5000000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765b48: { // 0x765b48: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00765b4a: { // 0x765b4a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00765b4c: { // 0x765b4c: e82f0f0000 CALL 0x00766a80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00766a80u,7756625u); flags=s.arithmetic_flags;
  }
  L00765b51: { // 0x765b51: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00765b54: { // 0x765b54: 0f85f7000000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765b5a: { // 0x765b5a: e9d0000000 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765b5f: { // 0x765b5f: 81fa5650525a CMP EDX,0x5a525056
    (void)integer::sub(s.dx,0x5a525056u,32,flags);
  }
  L00765b65: { // 0x765b65: 7461 JZ 0x00765bc8
    if(integer::condition("JZ",flags)) goto L00765bc8;
  }
  L00765b67: { // 0x765b67: 81fa5650545a CMP EDX,0x5a545056
    (void)integer::sub(s.dx,0x5a545056u,32,flags);
  }
  L00765b6d: { // 0x765b6d: 0f85de000000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765b73: { // 0x765b73: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765b78: { // 0x765b78: 0f859f000000 JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765b7e: { // 0x765b7e: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00765b84: { // 0x765b84: 8b9d6c070000 MOV EBX,dword ptr [EBP + 0x76c]
    s.bx = m.r32((s.bp+0x0000076cu));
  }
  L00765b8a: { // 0x765b8a: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00765b8c: { // 0x765b8c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765b8d: { // 0x765b8d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00765b8f: { // 0x765b8f: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00765b91: { // 0x765b91: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765b92: { // 0x765b92: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765b94: { // 0x765b94: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765b95: { // 0x765b95: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00765b99: { // 0x765b99: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756700u); flags=s.arithmetic_flags;
  }
  L00765b9c: { // 0x765b9c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765b9f: { // 0x765b9f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765ba1: { // 0x765ba1: 0f85aa000000 JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765ba7: { // 0x765ba7: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00765baa: { // 0x765baa: 895f20 MOV dword ptr [EDI + 0x20],EBX
    m.w32((s.di+0x00000020u), s.bx);
  }
  L00765bad: { // 0x765bad: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00765bb0: { // 0x765bb0: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00765bb3: { // 0x765bb3: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00765bbb: { // 0x765bbb: 7372 JNC 0x00765c2f
    if(integer::condition("JNC",flags)) goto L00765c2f;
  }
  L00765bbd: { // 0x765bbd: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00765bc1: { // 0x765bc1: c644320180 MOV byte ptr [EDX + ESI*0x1 + 0x1],0x80
    m.w8((s.dx+(s.si * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00765bc6: { // 0x765bc6: eb67 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765bc8: { // 0x765bc8: f644242404 TEST byte ptr [ESP + 0x24],0x4
    (void)integer::logical((m.r8((f.sp+0x00000024u)))&(0x00000004u),8,flags);
  }
  L00765bcd: { // 0x765bcd: 754e JNZ 0x00765c1d
    if(integer::condition("JNZ",flags)) goto L00765c1d;
  }
  L00765bcf: { // 0x765bcf: 8bbd70010000 MOV EDI,dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L00765bd5: { // 0x765bd5: 8b9d6c070000 MOV EBX,dword ptr [EBP + 0x76c]
    s.bx = m.r32((s.bp+0x0000076cu));
  }
  L00765bdb: { // 0x765bdb: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00765bdd: { // 0x765bdd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765bde: { // 0x765bde: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00765be0: { // 0x765be0: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00765be2: { // 0x765be2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765be3: { // 0x765be3: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765be5: { // 0x765be5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765be6: { // 0x765be6: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00765bea: { // 0x765bea: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756781u); flags=s.arithmetic_flags;
  }
  L00765bed: { // 0x765bed: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765bf0: { // 0x765bf0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765bf2: { // 0x765bf2: 755d JNZ 0x00765c51
    if(integer::condition("JNZ",flags)) goto L00765c51;
  }
  L00765bf4: { // 0x765bf4: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  L00765bf7: { // 0x765bf7: 895f20 MOV dword ptr [EDI + 0x20],EBX
    m.w32((s.di+0x00000020u), s.bx);
  }
  L00765bfa: { // 0x765bfa: 83c910 OR ECX,0x10
    s.cx = integer::logical((s.cx)|(0x00000010u),32,flags);
  }
  L00765bfd: { // 0x765bfd: 894f14 MOV dword ptr [EDI + 0x14],ECX
    m.w32((s.di+0x00000014u), s.cx);
  }
  L00765c00: { // 0x765c00: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00765c08: { // 0x765c08: 7309 JNC 0x00765c13
    if(integer::condition("JNC",flags)) goto L00765c13;
  }
  L00765c0a: { // 0x765c0a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00765c0e: { // 0x765c0e: c644300180 MOV byte ptr [EAX + ESI*0x1 + 0x1],0x80
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00765c13: { // 0x765c13: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00765c17: { // 0x765c17: 83481420 OR dword ptr [EAX + 0x14],0x20
    m.w32((s.ax+0x00000014u), integer::logical((m.r32((s.ax+0x00000014u)))|(0x00000020u),32,flags));
  }
  L00765c1b: { // 0x765c1b: eb12 JMP 0x00765c2f
    goto L00765c2f;
  }
  L00765c1d: { // 0x765c1d: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765c1f: { // 0x765c1f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765c20: { // 0x765c20: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00765c22: { // 0x765c22: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00765c24: { // 0x765c24: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765c25: { // 0x765c25: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7756840u); flags=s.arithmetic_flags;
  }
  L00765c28: { // 0x765c28: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c2b: { // 0x765c2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765c2d: { // 0x765c2d: 7531 JNZ 0x00765c60
    if(integer::condition("JNZ",flags)) goto L00765c60;
  }
  L00765c2f: { // 0x765c2f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00765c33: { // 0x765c33: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00765c37: { // 0x765c37: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00765c39: { // 0x765c39: 7334 JNC 0x00765c6f
    if(integer::condition("JNC",flags)) goto L00765c6f;
  }
  L00765c3b: { // 0x765c3b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00765c3d: { // 0x765c3d: e9b3fbffff JMP 0x007657f5
    goto L007657f5;
  }
  L00765c42: { // 0x765c42: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c43: { // 0x765c43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c44: { // 0x765c44: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c45: { // 0x765c45: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00765c4a: { // 0x765c4a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c4b: { // 0x765c4b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c4e: { // 0x765c4e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765c51: { // 0x765c51: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c52: { // 0x765c52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c53: { // 0x765c53: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c54: { // 0x765c54: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765c59: { // 0x765c59: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c5a: { // 0x765c5a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c5d: { // 0x765c5d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765c60: { // 0x765c60: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c61: { // 0x765c61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c62: { // 0x765c62: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c63: { // 0x765c63: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  L00765c68: { // 0x765c68: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c69: { // 0x765c69: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c6c: { // 0x765c6c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765c6f: { // 0x765c6f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765c70: { // 0x765c70: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765c71: { // 0x765c71: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765c72: { // 0x765c72: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00765c75: { // 0x765c75: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765c76: { // 0x765c76: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765c79: { // 0x765c79: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
