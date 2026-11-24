#include "recovered/recovery_b237_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b237 {
namespace {
void f_00363ef0(Memory&,State&,Frame&,const Operations&);
void f_00364290(Memory&,State&,Frame&,const Operations&);
void f_00363fc0(Memory&,State&,Frame&,const Operations&);
void f_00365200(Memory&,State&,Frame&,const Operations&);
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
  L00763f00: { // 0x763f00: 0f8790000000 JA 0x763F96
    if(integer::condition("JA",flags)) goto L00763f96;
  }
  L00763f06: { // 0x763f06: ff248d9c3f7600 JMP dword ptr [ECX*4 + 0x763F9C]
    switch(m.r32(((s.cx * 4u)+0x00763f9cu))){
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
    default:throw std::domain_error("recovery237 unsupported switch destination");}
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
  L00763f22: { // 0x763f22: 7f6d JG 0x763F91
    if(integer::condition("JG",flags)) goto L00763f91;
  }
  L00763f24: { // 0x763f24: 8bb2f4060000 MOV ESI, dword ptr [EDX + 0x6F4]
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
  L00763f5c: { // 0x763f5c: 741a JZ 0x763F78
    if(integer::condition("JZ",flags)) goto L00763f78;
  }
  L00763f5e: { // 0x763f5e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00763f5f: { // 0x763f5f: 7530 JNZ 0x763F91
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
  L00763f78: { // 0x763f78: 8bb2fc060000 MOV ESI, dword ptr [EDX + 0x6FC]
    s.si = m.r32((s.dx+0x000006fcu));
  }
  L00763f7e: { // 0x763f7e: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00763f82: { // 0x763f82: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00763f84: { // 0x763f84: 7c0b JL 0x763F91
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
void f_00364290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00764290: { // 0x764290: 83ec20 SUB ESP, 0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00764293: { // 0x764293: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00764294: { // 0x764294: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00764295: { // 0x764295: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L00764297: { // 0x764297: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00764298: { // 0x764298: 8bda MOV EBX, EDX
    s.bx = s.dx;
  }
  L0076429a: { // 0x76429a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076429b: { // 0x76429b: 8b8584000000 MOV EAX, dword ptr [EBP + 0x84]
    s.ax = m.r32((s.bp+0x00000084u));
  }
  L007642a1: { // 0x7642a1: 8bbd70010000 MOV EDI, dword ptr [EBP + 0x170]
    s.di = m.r32((s.bp+0x00000170u));
  }
  L007642a7: { // 0x7642a7: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007642a9: { // 0x7642a9: 895c2414 MOV dword ptr [ESP + 0x14], EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L007642ad: { // 0x7642ad: a820 TEST AL, 0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L007642af: { // 0x7642af: 8954241c MOV dword ptr [ESP + 0x1C], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L007642b3: { // 0x7642b3: 88542413 MOV byte ptr [ESP + 0x13], DL
    m.w8((f.sp+0x00000013u), (s.dx & 0xffu));
  }
  L007642b7: { // 0x7642b7: 897c2418 MOV dword ptr [ESP + 0x18], EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L007642bb: { // 0x7642bb: 0f8410020000 JZ 0x7644D1
    if(integer::condition("JZ",flags)) goto L007644d1;
  }
  L007642c1: { // 0x7642c1: 8b8d24010000 MOV ECX, dword ptr [EBP + 0x124]
    s.cx = m.r32((s.bp+0x00000124u));
  }
  L007642c7: { // 0x7642c7: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L007642c9: { // 0x7642c9: 7f09 JG 0x7642D4
    if(integer::condition("JG",flags)) goto L007642d4;
  }
  L007642cb: { // 0x7642cb: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L007642ce: { // 0x7642ce: 0f85fd010000 JNZ 0x7644D1
    if(integer::condition("JNZ",flags)) goto L007644d1;
  }
  L007642d4: { // 0x7642d4: 8b8d2c010000 MOV ECX, dword ptr [EBP + 0x12C]
    s.cx = m.r32((s.bp+0x0000012cu));
  }
  L007642da: { // 0x7642da: 8bb580010000 MOV ESI, dword ptr [EBP + 0x180]
    s.si = m.r32((s.bp+0x00000180u));
  }
  L007642e0: { // 0x7642e0: 3bf1 CMP ESI, ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L007642e2: { // 0x7642e2: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L007642e6: { // 0x7642e6: 0f8ee5010000 JLE 0x7644D1
    if(integer::condition("JLE",flags)) goto L007644d1;
  }
  L007642ec: { // 0x7642ec: 8b9d30010000 MOV EBX, dword ptr [EBP + 0x130]
    s.bx = m.r32((s.bp+0x00000130u));
  }
  L007642f2: { // 0x7642f2: 8b851c010000 MOV EAX, dword ptr [EBP + 0x11C]
    s.ax = m.r32((s.bp+0x0000011cu));
  }
  L007642f8: { // 0x7642f8: 83fbff CMP EBX, -1
    (void)integer::sub(s.bx,4294967295u,32,flags);
  }
  L007642fb: { // 0x7642fb: 895c241c MOV dword ptr [ESP + 0x1C], EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L007642ff: { // 0x7642ff: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00764303: { // 0x764303: 7416 JZ 0x76431B
    if(integer::condition("JZ",flags)) goto L0076431b;
  }
  L00764305: { // 0x764305: 899d2c010000 MOV dword ptr [EBP + 0x12C], EBX
    m.w32((s.bp+0x0000012cu), s.bx);
  }
  L0076430b: { // 0x76430b: c78530010000ffffffff MOV dword ptr [EBP + 0x130], 0xFFFFFFFF
    m.w32((s.bp+0x00000130u), 0xffffffffu);
  }
  L00764315: { // 0x764315: 899d1c010000 MOV dword ptr [EBP + 0x11C], EBX
    m.w32((s.bp+0x0000011cu), s.bx);
  }
  L0076431b: { // 0x76431b: 8b8528010000 MOV EAX, dword ptr [EBP + 0x128]
    s.ax = m.r32((s.bp+0x00000128u));
  }
  L00764321: { // 0x764321: 8b8d80010000 MOV ECX, dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L00764327: { // 0x764327: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00764329: { // 0x764329: 0f8422010000 JZ 0x764451
    if(integer::condition("JZ",flags)) goto L00764451;
  }
  L0076432f: { // 0x76432f: 898580010000 MOV dword ptr [EBP + 0x180], EAX
    m.w32((s.bp+0x00000180u), s.ax);
  }
  L00764335: { // 0x764335: 8b8d70010000 MOV ECX, dword ptr [EBP + 0x170]
    s.cx = m.r32((s.bp+0x00000170u));
  }
  L0076433b: { // 0x76433b: 8bb528010000 MOV ESI, dword ptr [EBP + 0x128]
    s.si = m.r32((s.bp+0x00000128u));
  }
  L00764341: { // 0x764341: c644241300 MOV byte ptr [ESP + 0x13], 0
    m.w8((f.sp+0x00000013u), 0u);
  }
  L00764346: { // 0x764346: f6411401 TEST byte ptr [ECX + 0x14], 1
    (void)integer::logical((m.r8((s.cx+0x00000014u)))&(1u),8,flags);
  }
  L0076434a: { // 0x76434a: 740a JZ 0x764356
    if(integer::condition("JZ",flags)) goto L00764356;
  }
  L0076434c: { // 0x76434c: b8f7ffffff MOV EAX, 0xFFFFFFF7
    s.ax = 0xfffffff7u;
  }
  L00764351: { // 0x764351: e9d2000000 JMP 0x764428
    goto L00764428;
  }
  L00764356: { // 0x764356: 3bb51c010000 CMP ESI, dword ptr [EBP + 0x11C]
    (void)integer::sub(s.si,m.r32((s.bp+0x0000011cu)),32,flags);
  }
  L0076435c: { // 0x76435c: 7d1c JGE 0x76437A
    if(integer::condition("JGE",flags)) goto L0076437a;
  }
  L0076435e: { // 0x76435e: 8b8564070000 MOV EAX, dword ptr [EBP + 0x764]
    s.ax = m.r32((s.bp+0x00000764u));
  }
  L00764364: { // 0x764364: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00764366: { // 0x764366: 7412 JZ 0x76437A
    if(integer::condition("JZ",flags)) goto L0076437a;
  }
  L00764368: { // 0x764368: f6858400000001 TEST byte ptr [EBP + 0x84], 1
    (void)integer::logical((m.r8((s.bp+0x00000084u)))&(1u),8,flags);
  }
  L0076436f: { // 0x76436f: 7413 JZ 0x764384
    if(integer::condition("JZ",flags)) goto L00764384;
  }
  L00764371: { // 0x764371: f685ea00000008 TEST byte ptr [EBP + 0xEA], 8
    (void)integer::logical((m.r8((s.bp+0x000000eau)))&(8u),8,flags);
  }
  L00764378: { // 0x764378: 750a JNZ 0x764384
    if(integer::condition("JNZ",flags)) goto L00764384;
  }
  L0076437a: { // 0x76437a: b8faffffff MOV EAX, 0xFFFFFFFA
    s.ax = 0xfffffffau;
  }
  L0076437f: { // 0x76437f: e9a4000000 JMP 0x764428
    goto L00764428;
  }
  L00764384: { // 0x764384: 8a8508010000 MOV AL, byte ptr [EBP + 0x108]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000108u)));
  }
  L0076438a: { // 0x76438a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076438c: { // 0x76438c: 7551 JNZ 0x7643DF
    if(integer::condition("JNZ",flags)) goto L007643df;
  }
  L0076438e: { // 0x76438e: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00764390: { // 0x764390: 744d JZ 0x7643DF
    if(integer::condition("JZ",flags)) goto L007643df;
  }
  L00764392: { // 0x764392: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00764394: { // 0x764394: 668b8514070000 MOV AX, word ptr [EBP + 0x714]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000714u)));
  }
  L0076439b: { // 0x76439b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076439d: { // 0x76439d: 7e2a JLE 0x7643C9
    if(integer::condition("JLE",flags)) goto L007643c9;
  }
  L0076439f: { // 0x76439f: f6851607000003 TEST byte ptr [EBP + 0x716], 3
    (void)integer::logical((m.r8((s.bp+0x00000716u)))&(3u),8,flags);
  }
  L007643a6: { // 0x7643a6: 7421 JZ 0x7643C9
    if(integer::condition("JZ",flags)) goto L007643c9;
  }
  L007643a8: { // 0x7643a8: 8b951c070000 MOV EDX, dword ptr [EBP + 0x71C]
    s.dx = m.r32((s.bp+0x0000071cu));
  }
  L007643ae: { // 0x7643ae: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L007643b0: { // 0x7643b0: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007643b2: { // 0x7643b2: 7e15 JLE 0x7643C9
    if(integer::condition("JLE",flags)) goto L007643c9;
  }
  L007643b4: { // 0x7643b4: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L007643b6: { // 0x7643b6: 668b1a MOV BX, word ptr [EDX]
    s.bx = with_ax(s.bx, m.r16((s.dx)));
  }
  L007643b9: { // 0x7643b9: 3bf3 CMP ESI, EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L007643bb: { // 0x7643bb: 741e JZ 0x7643DB
    if(integer::condition("JZ",flags)) goto L007643db;
  }
  L007643bd: { // 0x7643bd: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007643be: { // 0x7643be: 83c204 ADD EDX, 4
    s.dx = integer::add(s.dx,4u,32,flags);
  }
  L007643c1: { // 0x7643c1: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007643c3: { // 0x7643c3: 7cef JL 0x7643B4
    if(integer::condition("JL",flags)) goto L007643b4;
  }
  L007643c5: { // 0x7643c5: 8b5c241c MOV EBX, dword ptr [ESP + 0x1C]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007643c9: { // 0x7643c9: 6a01 PUSH 1
    f.push(m,1u);
  }
  L007643cb: { // 0x7643cb: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L007643cd: { // 0x7643cd: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L007643cf: { // 0x7643cf: e8ac0c0000 CALL 0x765080
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765080u,7750612u); flags=s.arithmetic_flags;
  }
  L007643d4: { // 0x7643d4: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L007643d7: { // 0x7643d7: 7521 JNZ 0x7643FA
    if(integer::condition("JNZ",flags)) goto L007643fa;
  }
  L007643d9: { // 0x7643d9: eb04 JMP 0x7643DF
    goto L007643df;
  }
  L007643db: { // 0x7643db: 8b5c241c MOV EBX, dword ptr [ESP + 0x1C]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007643df: { // 0x7643df: 8d542413 LEA EDX, [ESP + 0x13]
    s.dx = (f.sp+0x00000013u);
  }
  L007643e3: { // 0x7643e3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007643e5: { // 0x7643e5: 8a85f5000000 MOV AL, byte ptr [EBP + 0xF5]
    s.ax = with_al(s.ax, m.r8((s.bp+0x000000f5u)));
  }
  L007643eb: { // 0x7643eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007643ec: { // 0x7643ec: 6a00 PUSH 0
    f.push(m,0u);
  }
  L007643ee: { // 0x7643ee: 6a00 PUSH 0
    f.push(m,0u);
  }
  L007643f0: { // 0x7643f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007643f1: { // 0x7643f1: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L007643f3: { // 0x7643f3: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L007643f5: { // 0x7643f5: e8960e0000 CALL 0x765290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765290u,7750650u); flags=s.arithmetic_flags;
  }
  L007643fa: { // 0x7643fa: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L007643fd: { // 0x7643fd: 89b580010000 MOV dword ptr [EBP + 0x180], ESI
    m.w32((s.bp+0x00000180u), s.si);
  }
  L00764403: { // 0x764403: 751e JNZ 0x764423
    if(integer::condition("JNZ",flags)) goto L00764423;
  }
  L00764405: { // 0x764405: 8a442413 MOV AL, byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00764409: { // 0x764409: ba20000000 MOV EDX, 0x20
    s.dx = 0x00000020u;
  }
  L0076440e: { // 0x76440e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00764410: { // 0x764410: 7405 JZ 0x764417
    if(integer::condition("JZ",flags)) goto L00764417;
  }
  L00764412: { // 0x764412: ba30000000 MOV EDX, 0x30
    s.dx = 0x00000030u;
  }
  L00764417: { // 0x764417: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00764419: { // 0x764419: e8a2fbffff CALL 0x763FC0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763fc0u,7750686u); flags=s.arithmetic_flags;
  }
  L0076441e: { // 0x76441e: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00764421: { // 0x764421: 7431 JZ 0x764454
    if(integer::condition("JZ",flags)) goto L00764454;
  }
  L00764423: { // 0x764423: 83f8f5 CMP EAX, -0xB
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L00764426: { // 0x764426: 742c JZ 0x764454
    if(integer::condition("JZ",flags)) goto L00764454;
  }
  L00764428: { // 0x764428: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0076442c: { // 0x76442c: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00764430: { // 0x764430: 898d2c010000 MOV dword ptr [EBP + 0x12C], ECX
    m.w32((s.bp+0x0000012cu), s.cx);
  }
  L00764436: { // 0x764436: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00764437: { // 0x764437: 899d30010000 MOV dword ptr [EBP + 0x130], EBX
    m.w32((s.bp+0x00000130u), s.bx);
  }
  L0076443d: { // 0x76443d: 89951c010000 MOV dword ptr [EBP + 0x11C], EDX
    m.w32((s.bp+0x0000011cu), s.dx);
  }
  L00764443: { // 0x764443: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764444: { // 0x764444: 898d80010000 MOV dword ptr [EBP + 0x180], ECX
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
  L0076444d: { // 0x76444d: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764450: { // 0x764450: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764451: { // 0x764451: 83c8ff OR EAX, 0xFFFFFFFF
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00764454: { // 0x764454: 8b9550010000 MOV EDX, dword ptr [EBP + 0x150]
    s.dx = m.r32((s.bp+0x00000150u));
  }
  L0076445a: { // 0x76445a: 80ca80 OR DL, 0x80
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|(0x00000080u),8,flags));
  }
  L0076445d: { // 0x76445d: 83fbff CMP EBX, -1
    (void)integer::sub(s.bx,4294967295u,32,flags);
  }
  L00764460: { // 0x764460: 899550010000 MOV dword ptr [EBP + 0x150], EDX
    m.w32((s.bp+0x00000150u), s.dx);
  }
  L00764466: { // 0x764466: 7529 JNZ 0x764491
    if(integer::condition("JNZ",flags)) goto L00764491;
  }
  L00764468: { // 0x764468: 8b7714 MOV ESI, dword ptr [EDI + 0x14]
    s.si = m.r32((s.di+0x00000014u));
  }
  L0076446b: { // 0x76446b: 81ce00010000 OR ESI, 0x100
    s.si = integer::logical((s.si)|(0x00000100u),32,flags);
  }
  L00764471: { // 0x764471: 897714 MOV dword ptr [EDI + 0x14], ESI
    m.w32((s.di+0x00000014u), s.si);
  }
  L00764474: { // 0x764474: 8b8d24010000 MOV ECX, dword ptr [EBP + 0x124]
    s.cx = m.r32((s.bp+0x00000124u));
  }
  L0076447a: { // 0x76447a: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0076447c: { // 0x76447c: 0f844b0b0000 JZ 0x764FCD
    if(integer::condition("JZ",flags)) goto L00764fcd;
  }
  L00764482: { // 0x764482: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00764483: { // 0x764483: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764484: { // 0x764484: 898d24010000 MOV dword ptr [EBP + 0x124], ECX
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
  L0076448d: { // 0x76448d: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764490: { // 0x764490: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764491: { // 0x764491: 8b5714 MOV EDX, dword ptr [EDI + 0x14]
    s.dx = m.r32((s.di+0x00000014u));
  }
  L00764494: { // 0x764494: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00764498: { // 0x764498: 80ce02 OR DH, 2
    s.dx = (s.dx & 0xffff00ffu) | (((integer::logical((((s.dx >> 8) & 0xffu))|(2u),8,flags)) & 0xffu) << 8);
  }
  L0076449b: { // 0x76449b: 895714 MOV dword ptr [EDI + 0x14], EDX
    m.w32((s.di+0x00000014u), s.dx);
  }
  L0076449e: { // 0x76449e: 8b9534010000 MOV EDX, dword ptr [EBP + 0x134]
    s.dx = m.r32((s.bp+0x00000134u));
  }
  L007644a4: { // 0x7644a4: 898d40010000 MOV dword ptr [EBP + 0x140], ECX
    m.w32((s.bp+0x00000140u), s.cx);
  }
  L007644aa: { // 0x7644aa: 8b8d50010000 MOV ECX, dword ptr [EBP + 0x150]
    s.cx = m.r32((s.bp+0x00000150u));
  }
  L007644b0: { // 0x7644b0: 80cd01 OR CH, 1
    s.cx = (s.cx & 0xffff00ffu) | (((integer::logical((((s.cx >> 8) & 0xffu))|(1u),8,flags)) & 0xffu) << 8);
  }
  L007644b3: { // 0x7644b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007644b4: { // 0x7644b4: 899524010000 MOV dword ptr [EBP + 0x124], EDX
    m.w32((s.bp+0x00000124u), s.dx);
  }
  L007644ba: { // 0x7644ba: c78534010000ffffffff MOV dword ptr [EBP + 0x134], 0xFFFFFFFF
    m.w32((s.bp+0x00000134u), 0xffffffffu);
  }
  L007644c4: { // 0x7644c4: 898d50010000 MOV dword ptr [EBP + 0x150], ECX
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
  L007644cd: { // 0x7644cd: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007644d0: { // 0x7644d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007644d1: { // 0x7644d1: 8b8d80010000 MOV ECX, dword ptr [EBP + 0x180]
    s.cx = m.r32((s.bp+0x00000180u));
  }
  L007644d7: { // 0x7644d7: 8bb51c010000 MOV ESI, dword ptr [EBP + 0x11C]
    s.si = m.r32((s.bp+0x0000011cu));
  }
  L007644dd: { // 0x7644dd: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L007644df: { // 0x7644df: 7e5f JLE 0x764540
    if(integer::condition("JLE",flags)) goto L00764540;
  }
  L007644e1: { // 0x7644e1: f6c302 TEST BL, 2
    (void)integer::logical(((s.bx & 0xffu))&(2u),8,flags);
  }
  L007644e4: { // 0x7644e4: 754d JNZ 0x764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007644e6: { // 0x7644e6: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L007644e8: { // 0x7644e8: 7449 JZ 0x764533
    if(integer::condition("JZ",flags)) goto L00764533;
  }
  L007644ea: { // 0x7644ea: a840 TEST AL, 0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L007644ec: { // 0x7644ec: 7545 JNZ 0x764533
    if(integer::condition("JNZ",flags)) goto L00764533;
  }
  L007644ee: { // 0x7644ee: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L007644f0: { // 0x7644f0: e82bd9ffff CALL 0x761E20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761e20u,7750901u); flags=s.arithmetic_flags;
  }
  L007644f5: { // 0x7644f5: 83f8f5 CMP EAX, -0xB
    (void)integer::sub(s.ax,0xfffffff5u,32,flags);
  }
  L007644f8: { // 0x7644f8: 751b JNZ 0x764515
    if(integer::condition("JNZ",flags)) goto L00764515;
  }
  L007644fa: { // 0x7644fa: 8b8550010000 MOV EAX, dword ptr [EBP + 0x150]
    s.ax = m.r32((s.bp+0x00000150u));
  }
  L00764500: { // 0x764500: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00764501: { // 0x764501: 0c01 OR AL, 1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(1u),8,flags));
  }
  L00764503: { // 0x764503: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00764504: { // 0x764504: 898550010000 MOV dword ptr [EBP + 0x150], EAX
    m.w32((s.bp+0x00000150u), s.ax);
  }
  L0076450a: { // 0x76450a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076450b: { // 0x76450b: b8f5ffffff MOV EAX, 0xFFFFFFF5
    s.ax = 0xfffffff5u;
  }
  L00764510: { // 0x764510: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764511: { // 0x764511: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764514: { // 0x764514: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764515: { // 0x764515: 8b8d50010000 MOV ECX, dword ptr [EBP + 0x150]
    s.cx = m.r32((s.bp+0x00000150u));
  }
  L0076451b: { // 0x76451b: 8b85bc070000 MOV EAX, dword ptr [EBP + 0x7BC]
    s.ax = m.r32((s.bp+0x000007bcu));
  }
  L00764521: { // 0x764521: 83e1fe AND ECX, 0xFFFFFFFE
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L00764524: { // 0x764524: 80cc01 OR AH, 1
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(1u),8,flags)) & 0xffu) << 8);
  }
  L00764527: { // 0x764527: 898d50010000 MOV dword ptr [EBP + 0x150], ECX
    m.w32((s.bp+0x00000150u), s.cx);
  }
  L0076452d: { // 0x76452d: 8985bc070000 MOV dword ptr [EBP + 0x7BC], EAX
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
  L00764536: { // 0x764536: b8feffffff MOV EAX, 0xFFFFFFFE
    s.ax = 0xfffffffeu;
  }
  L0076453b: { // 0x76453b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076453c: { // 0x76453c: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0076453f: { // 0x76453f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00764540: { // 0x764540: 8b4714 MOV EAX, dword ptr [EDI + 0x14]
    s.ax = m.r32((s.di+0x00000014u));
  }
  L00764543: { // 0x764543: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L00764545: { // 0x764545: 741f JZ 0x764566
    if(integer::condition("JZ",flags)) goto L00764566;
  }
  L00764547: { // 0x764547: f6c408 TEST AH, 8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(8u),8,flags);
  }
  L0076454a: { // 0x76454a: 751a JNZ 0x764566
    if(integer::condition("JNZ",flags)) goto L00764566;
  }
  L0076454c: { // 0x76454c: 8b8588010000 MOV EAX, dword ptr [EBP + 0x188]
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
  L00764555: { // 0x764555: 898588010000 MOV dword ptr [EBP + 0x188], EAX
    m.w32((s.bp+0x00000188u), s.ax);
  }
  L0076455b: { // 0x76455b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076455c: { // 0x76455c: b8f7ffffff MOV EAX, 0xFFFFFFF7
    s.ax = 0xfffffff7u;
  }
  L00764561: { // 0x764561: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00764562: { // 0x764562: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00764565: { // 0x764565: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
L00764566:throw std::domain_error("237 excluded decoder branch");
L00764fcd:throw std::domain_error("237 excluded decoder branch");
}
void f_00363fc0(Memory& m,State& s,Frame& f,const Operations& op) {
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
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00365200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00765200: { // 0x765200: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765201: { // 0x765201: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00765202: { // 0x765202: 8b9960070000 MOV EBX,dword ptr [ECX + 0x760]
    s.bx = m.r32((s.cx+0x00000760u));
  }
  L00765208: { // 0x765208: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765209: { // 0x765209: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076520a: { // 0x76520a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0076520c: { // 0x76520c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076520d: { // 0x76520d: 668bb158070000 MOV SI,word ptr [ECX + 0x758]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.cx+0x00000758u))) & 0xffffu);
  }
  L00765214: { // 0x765214: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00765219: { // 0x765219: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076521b: { // 0x76521b: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L0076521d: { // 0x76521d: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00765221: { // 0x765221: 7e23 JLE 0x00765246
    if(integer::condition("JLE",flags)) goto L00765246;
  }
  L00765223: { // 0x765223: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L00765226: { // 0x765226: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00765228: { // 0x765228: 668b6bfe MOV BP,word ptr [EBX + -0x2]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.bx-0x00000002u))) & 0xffffu);
  }
  L0076522c: { // 0x76522c: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L0076522e: { // 0x76522e: 7c09 JL 0x00765239
    if(integer::condition("JL",flags)) goto L00765239;
  }
  L00765230: { // 0x765230: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00765232: { // 0x765232: 668b2b MOV BP,word ptr [EBX]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L00765235: { // 0x765235: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L00765237: { // 0x765237: 7c12 JL 0x0076524b
    if(integer::condition("JL",flags)) goto L0076524b;
  }
  L00765239: { // 0x765239: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0076523a: { // 0x76523a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076523b: { // 0x76523b: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L0076523e: { // 0x76523e: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00765240: { // 0x765240: 7ce4 JL 0x00765226
    if(integer::condition("JL",flags)) goto L00765226;
  }
  L00765242: { // 0x765242: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00765246: { // 0x765246: 8d46ff LEA EAX,[ESI + -0x1]
    s.ax = (s.si-0x00000001u);
  }
  L00765249: { // 0x765249: eb04 JMP 0x0076524f
    goto L0076524f;
  }
  L0076524b: { // 0x76524b: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0076524f: { // 0x76524f: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00765253: { // 0x765253: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00765255: { // 0x765255: 7408 JZ 0x0076525f
    if(integer::condition("JZ",flags)) goto L0076525f;
  }
  L00765257: { // 0x765257: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00765259: { // 0x765259: 668b3c43 MOV DI,word ptr [EBX + EAX*0x2]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx+(s.ax * 0x00000002u)))) & 0xffffu);
  }
  L0076525d: { // 0x76525d: 893a MOV dword ptr [EDX],EDI
    m.w32((s.dx), s.di);
  }
  L0076525f: { // 0x76525f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00765263: { // 0x765263: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00765265: { // 0x765265: 741c JZ 0x00765283
    if(integer::condition("JZ",flags)) goto L00765283;
  }
  L00765267: { // 0x765267: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00765268: { // 0x765268: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0076526a: { // 0x76526a: 7d12 JGE 0x0076527e
    if(integer::condition("JGE",flags)) goto L0076527e;
  }
  L0076526c: { // 0x76526c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076526e: { // 0x76526e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076526f: { // 0x76526f: 668b4c4302 MOV CX,word ptr [EBX + EAX*0x2 + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.bx+(s.ax * 0x00000002u)+0x00000002u)));
  }
  L00765274: { // 0x765274: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765275: { // 0x765275: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00765276: { // 0x765276: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765277: { // 0x765277: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00765279: { // 0x765279: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076527a: { // 0x76527a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076527b: { // 0x76527b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0076527e: { // 0x76527e: 8b4910 MOV ECX,dword ptr [ECX + 0x10]
    s.cx = m.r32((s.cx+0x00000010u));
  }
  L00765281: { // 0x765281: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00765283: { // 0x765283: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765284: { // 0x765284: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765285: { // 0x765285: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765286: { // 0x765286: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765287: { // 0x765287: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00765288: { // 0x765288: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7749360u:f_00363ef0(m,s,child,{});break;
case 7750288u:f_00364290(m,s,child,{});break;
case 7749568u:f_00363fc0(m,s,child,{});break;
case 7754240u:f_00365200(m,s,child,{});break;
default:throw std::domain_error("recovery237 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00765080(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 std::array<std::uint8_t,36> table0{{115,63,118,0,115,63,118,0,115,63,118,0,115,63,118,0,13,63,118,0,145,63,118,0,85,63,118,0,85,63,118,0,115,63,118,0}};leaf::Memory tablemem0(table0.data(),7749532u,36u);m.add(tablemem0);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00765080: { // 0x765080: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00765083: { // 0x765083: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00765084: { // 0x765084: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765085: { // 0x765085: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765086: { // 0x765086: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00765088: { // 0x765088: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765089: { // 0x765089: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L0076508c: { // 0x76508c: 8b8670010000 MOV EAX,dword ptr [ESI + 0x170]
    s.ax = m.r32((s.si+0x00000170u));
  }
  L00765092: { // 0x765092: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L00765096: { // 0x765096: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0076509a: { // 0x76509a: 8b861c010000 MOV EAX,dword ptr [ESI + 0x11c]
    s.ax = m.r32((s.si+0x0000011cu));
  }
  L007650a0: { // 0x7650a0: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L007650a2: { // 0x7650a2: 0f8f42010000 JG 0x007651ea
    if(integer::condition("JG",flags)) goto L007651ea;
  }
  L007650a8: { // 0x7650a8: 8b9e64070000 MOV EBX,dword ptr [ESI + 0x764]
    s.bx = m.r32((s.si+0x00000764u));
  }
  L007650ae: { // 0x7650ae: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L007650b0: { // 0x7650b0: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L007650b2: { // 0x7650b2: 0f8432010000 JZ 0x007651ea
    if(integer::condition("JZ",flags)) goto L007651ea;
  }
  L007650b8: { // 0x7650b8: 39ae60070000 CMP dword ptr [ESI + 0x760],EBP
    (void)integer::sub(m.r32((s.si+0x00000760u)),s.bp,32,flags);
  }
  L007650be: { // 0x7650be: 743a JZ 0x007650fa
    if(integer::condition("JZ",flags)) goto L007650fa;
  }
  L007650c0: { // 0x7650c0: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L007650c4: { // 0x7650c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007650c5: { // 0x7650c5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007650c6: { // 0x7650c6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007650c8: { // 0x7650c8: e833010000 CALL 0x00765200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765200u,7753933u); flags=s.arithmetic_flags;
  }
  L007650cd: { // 0x7650cd: 396c2424 CMP dword ptr [ESP + 0x24],EBP
    (void)integer::sub(m.r32((f.sp+0x00000024u)),s.bp,32,flags);
  }
  L007650d1: { // 0x7650d1: 0f8584000000 JNZ 0x0076515b
    if(integer::condition("JNZ",flags)) goto L0076515b;
  }
  L007650d7: { // 0x7650d7: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L007650db: { // 0x7650db: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007650dc: { // 0x7650dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007650dd: { // 0x7650dd: 8b9684010000 MOV EDX,dword ptr [ESI + 0x184]
    s.dx = m.r32((s.si+0x00000184u));
  }
  L007650e3: { // 0x7650e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007650e5: { // 0x7650e5: e816010000 CALL 0x00765200
    s.arithmetic_flags=flags; invoke(m,s,f,0x00765200u,7753962u); flags=s.arithmetic_flags;
  }
  L007650ea: { // 0x7650ea: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L007650ee: { // 0x7650ee: 3b7c2414 CMP EDI,dword ptr [ESP + 0x14]
    (void)integer::sub(s.di,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L007650f2: { // 0x7650f2: 0f84e4000000 JZ 0x007651dc
    if(integer::condition("JZ",flags)) goto L007651dc;
  }
  L007650f8: { // 0x7650f8: eb65 JMP 0x0076515f
    goto L0076515f;
  }
  L007650fa: { // 0x7650fa: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L007650fc: { // 0x7650fc: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00765100: { // 0x765100: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00765102: { // 0x765102: 7c1b JL 0x0076511f
    if(integer::condition("JL",flags)) goto L0076511f;
  }
  L00765104: { // 0x765104: 8d0c93 LEA ECX,[EBX + EDX*0x4]
    s.cx = (s.bx+(s.dx * 0x00000004u));
  }
  L00765107: { // 0x765107: f70100000040 TEST dword ptr [ECX],0x40000000
    (void)integer::logical((m.r32((s.cx)))&(0x40000000u),32,flags);
  }
  L0076510d: { // 0x76510d: 750a JNZ 0x00765119
    if(integer::condition("JNZ",flags)) goto L00765119;
  }
  L0076510f: { // 0x76510f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00765110: { // 0x765110: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L00765113: { // 0x765113: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00765115: { // 0x765115: 7df0 JGE 0x00765107
    if(integer::condition("JGE",flags)) goto L00765107;
  }
  L00765117: { // 0x765117: eb06 JMP 0x0076511f
    goto L0076511f;
  }
  L00765119: { // 0x765119: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0076511b: { // 0x76511b: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0076511f: { // 0x76511f: 396c2424 CMP dword ptr [ESP + 0x24],EBP
    (void)integer::sub(m.r32((f.sp+0x00000024u)),s.bp,32,flags);
  }
  L00765123: { // 0x765123: 753a JNZ 0x0076515f
    if(integer::condition("JNZ",flags)) goto L0076515f;
  }
  L00765125: { // 0x765125: 8b8684010000 MOV EAX,dword ptr [ESI + 0x184]
    s.ax = m.r32((s.si+0x00000184u));
  }
  L0076512b: { // 0x76512b: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L0076512e: { // 0x76512e: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00765130: { // 0x765130: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00765134: { // 0x765134: 7c1b JL 0x00765151
    if(integer::condition("JL",flags)) goto L00765151;
  }
  L00765136: { // 0x765136: 8d0c83 LEA ECX,[EBX + EAX*0x4]
    s.cx = (s.bx+(s.ax * 0x00000004u));
  }
  L00765139: { // 0x765139: f70100000040 TEST dword ptr [ECX],0x40000000
    (void)integer::logical((m.r32((s.cx)))&(0x40000000u),32,flags);
  }
  L0076513f: { // 0x76513f: 750a JNZ 0x0076514b
    if(integer::condition("JNZ",flags)) goto L0076514b;
  }
  L00765141: { // 0x765141: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00765142: { // 0x765142: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L00765145: { // 0x765145: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00765147: { // 0x765147: 7df0 JGE 0x00765139
    if(integer::condition("JGE",flags)) goto L00765139;
  }
  L00765149: { // 0x765149: eb06 JMP 0x00765151
    goto L00765151;
  }
  L0076514b: { // 0x76514b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0076514d: { // 0x76514d: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00765151: { // 0x765151: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00765153: { // 0x765153: 0f8483000000 JZ 0x007651dc
    if(integer::condition("JZ",flags)) goto L007651dc;
  }
  L00765159: { // 0x765159: eb04 JMP 0x0076515f
    goto L0076515f;
  }
  L0076515b: { // 0x76515b: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0076515f: { // 0x76515f: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L00765161: { // 0x765161: 7c79 JL 0x007651dc
    if(integer::condition("JL",flags)) goto L007651dc;
  }
  L00765163: { // 0x765163: 8b8664070000 MOV EAX,dword ptr [ESI + 0x764]
    s.ax = m.r32((s.si+0x00000764u));
  }
  L00765169: { // 0x765169: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0076516c: { // 0x76516c: 81e1ffffff0f AND ECX,0xfffffff
    s.cx = integer::logical((s.cx)&(0x0fffffffu),32,flags);
  }
  L00765172: { // 0x765172: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00765174: { // 0x765174: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765175: { // 0x765175: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765176: { // 0x765176: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00765178: { // 0x765178: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765179: { // 0x765179: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7754108u); flags=s.arithmetic_flags;
  }
  L0076517c: { // 0x76517c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076517f: { // 0x76517f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765181: { // 0x765181: 7551 JNZ 0x007651d4
    if(integer::condition("JNZ",flags)) goto L007651d4;
  }
  L00765183: { // 0x765183: 396c2424 CMP dword ptr [ESP + 0x24],EBP
    (void)integer::sub(m.r32((f.sp+0x00000024u)),s.bp,32,flags);
  }
  L00765187: { // 0x765187: 7431 JZ 0x007651ba
    if(integer::condition("JZ",flags)) goto L007651ba;
  }
  L00765189: { // 0x765189: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0076518d: { // 0x76518d: 89ae74010000 MOV dword ptr [ESI + 0x174],EBP
    m.w32((s.si+0x00000174u), s.bp);
  }
  L00765193: { // 0x765193: 89ae78010000 MOV dword ptr [ESI + 0x178],EBP
    m.w32((s.si+0x00000178u), s.bp);
  }
  L00765199: { // 0x765199: 8b96ec060000 MOV EDX,dword ptr [ESI + 0x6ec]
    s.dx = m.r32((s.si+0x000006ecu));
  }
  L0076519f: { // 0x76519f: 899668010000 MOV dword ptr [ESI + 0x168],EDX
    m.w32((s.si+0x00000168u), s.dx);
  }
  L007651a5: { // 0x7651a5: 8b86ec060000 MOV EAX,dword ptr [ESI + 0x6ec]
    s.ax = m.r32((s.si+0x000006ecu));
  }
  L007651ab: { // 0x7651ab: 898664010000 MOV dword ptr [ESI + 0x164],EAX
    m.w32((s.si+0x00000164u), s.ax);
  }
  L007651b1: { // 0x7651b1: 89ae80010000 MOV dword ptr [ESI + 0x180],EBP
    m.w32((s.si+0x00000180u), s.bp);
  }
  L007651b7: { // 0x7651b7: 896914 MOV dword ptr [ECX + 0x14],EBP
    m.w32((s.cx+0x00000014u), s.bp);
  }
  L007651ba: { // 0x7651ba: ba1e000000 MOV EDX,0x1e
    s.dx = 0x0000001eu;
  }
  L007651bf: { // 0x7651bf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007651c1: { // 0x7651c1: e8faedffff CALL 0x00763fc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763fc0u,7754182u); flags=s.arithmetic_flags;
  }
  L007651c6: { // 0x7651c6: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L007651ca: { // 0x7651ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007651cb: { // 0x7651cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007651cc: { // 0x7651cc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007651cd: { // 0x7651cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007651ce: { // 0x7651ce: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007651d1: { // 0x7651d1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007651d4: { // 0x7651d4: c7442418faffffff MOV dword ptr [ESP + 0x18],0xfffffffa
    m.w32((f.sp+0x00000018u), 0xfffffffau);
  }
  L007651dc: { // 0x7651dc: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L007651e0: { // 0x7651e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007651e1: { // 0x7651e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007651e2: { // 0x7651e2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007651e3: { // 0x7651e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007651e4: { // 0x7651e4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007651e7: { // 0x7651e7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007651ea: { // 0x7651ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007651eb: { // 0x7651eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007651ec: { // 0x7651ec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007651ed: { // 0x7651ed: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  L007651f2: { // 0x7651f2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007651f3: { // 0x7651f3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007651f6: { // 0x7651f6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
