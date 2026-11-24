#include "recovered/recovery_b1721_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1721 {
namespace {
void f_000068f0(Memory&,State&,Frame&,const Operations&);
void f_00027e90(Memory&,State&,Frame&,const Operations&);
void f_00028a90(Memory&,State&,Frame&,const Operations&);
void f_00028ac0(Memory&,State&,Frame&,const Operations&);
void f_00029b60(Memory&,State&,Frame&,const Operations&);
void f_0002ad30(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_0002ae00(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_00075fd0(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_000767a0(Memory&,State&,Frame&,const Operations&);
void f_00079e70(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_0007b1e0(Memory&,State&,Frame&,const Operations&);
void f_0007b3c0(Memory&,State&,Frame&,const Operations&);
void f_0007b560(Memory&,State&,Frame&,const Operations&);
void f_0007b580(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_001078f0(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00147bb0(Memory&,State&,Frame&,const Operations&);
void f_00147f40(Memory&,State&,Frame&,const Operations&);
void f_0014cf40(Memory&,State&,Frame&,const Operations&);
void f_0014d560(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_00157280(Memory&,State&,Frame&,const Operations&);
void f_00157340(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_00158b60(Memory&,State&,Frame&,const Operations&);
void f_0015a200(Memory&,State&,Frame&,const Operations&);
void f_00161d60(Memory&,State&,Frame&,const Operations&);
void f_001621b0(Memory&,State&,Frame&,const Operations&);
void f_0016a990(Memory&,State&,Frame&,const Operations&);
void f_001819d0(Memory&,State&,Frame&,const Operations&);
void f_00181ea0(Memory&,State&,Frame&,const Operations&);
void f_001d4730(Memory&,State&,Frame&,const Operations&);
void f_00297fb0(Memory&,State&,Frame&,const Operations&);
void f_0029c090(Memory&,State&,Frame&,const Operations&);
void f_0029e380(Memory&,State&,Frame&,const Operations&);
void f_00306660(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000068f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004068f0: { // 0x4068f0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00027e90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00427e90: { // 0x427e90: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00427e93: { // 0x427e93: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00427e96: { // 0x427e96: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00427e97: { // 0x427e97: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00427e99: { // 0x427e99: 89b000001800 MOV dword ptr [EAX + 0x180000],ESI
    m.w32((s.ax+0x00180000u), s.si);
  }
  L00427e9f: { // 0x427e9f: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L00427ea2: { // 0x427ea2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00427ea3: { // 0x427ea3: 89b200001000 MOV dword ptr [EDX + 0x100000],ESI
    m.w32((s.dx+0x00100000u), s.si);
  }
  L00427ea9: { // 0x427ea9: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L00427eac: { // 0x427eac: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00427eae: { // 0x427eae: 3930 CMP dword ptr [EAX],ESI
    (void)integer::sub(m.r32((s.ax)),s.si,32,flags);
  }
  L00427eb0: { // 0x427eb0: 7c0e JL 0x00427ec0
    if(integer::condition("JL",flags)) goto L00427ec0;
  }
  L00427eb2: { // 0x427eb2: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00427eb5: { // 0x427eb5: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00427eb6: { // 0x427eb6: 897497fc MOV dword ptr [EDI + EDX*0x4 + -0x4],ESI
    m.w32((s.di+(s.dx * 0x00000004u)-0x00000004u), s.si);
  }
  L00427eba: { // 0x427eba: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L00427ebc: { // 0x427ebc: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00427ebe: { // 0x427ebe: 7ef2 JLE 0x00427eb2
    if(integer::condition("JLE",flags)) goto L00427eb2;
  }
  L00427ec0: { // 0x427ec0: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L00427ec2: { // 0x427ec2: 8b4168 MOV EAX,dword ptr [ECX + 0x68]
    s.ax = m.r32((s.cx+0x00000068u));
  }
  L00427ec5: { // 0x427ec5: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00427ec7: { // 0x427ec7: 3930 CMP dword ptr [EAX],ESI
    (void)integer::sub(m.r32((s.ax)),s.si,32,flags);
  }
  L00427ec9: { // 0x427ec9: 7c0e JL 0x00427ed9
    if(integer::condition("JL",flags)) goto L00427ed9;
  }
  L00427ecb: { // 0x427ecb: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00427ece: { // 0x427ece: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00427ecf: { // 0x427ecf: 897497fc MOV dword ptr [EDI + EDX*0x4 + -0x4],ESI
    m.w32((s.di+(s.dx * 0x00000004u)-0x00000004u), s.si);
  }
  L00427ed3: { // 0x427ed3: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L00427ed5: { // 0x427ed5: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00427ed7: { // 0x427ed7: 7ef2 JLE 0x00427ecb
    if(integer::condition("JLE",flags)) goto L00427ecb;
  }
  L00427ed9: { // 0x427ed9: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L00427edb: { // 0x427edb: 8b4128 MOV EAX,dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  L00427ede: { // 0x427ede: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00427edf: { // 0x427edf: 894128 MOV dword ptr [ECX + 0x28],EAX
    m.w32((s.cx+0x00000028u), s.ax);
  }
  L00427ee2: { // 0x427ee2: 0f8580000000 JNZ 0x00427f68
    if(integer::condition("JNZ",flags)) goto L00427f68;
  }
  L00427ee8: { // 0x427ee8: a14c6b8300 MOV EAX,[0x00836b4c]
    s.ax = m.r32((0x00836b4cu));
  }
  L00427eed: { // 0x427eed: 0fafc0 IMUL EAX,EAX
    s.ax = integer::imul(s.ax,s.ax,32,flags);
  }
  L00427ef0: { // 0x427ef0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00427ef1: { // 0x427ef1: 7811 JS 0x00427f04
    if(integer::condition("JS",flags)) goto L00427f04;
  }
  L00427ef3: { // 0x427ef3: 8b5118 MOV EDX,dword ptr [ECX + 0x18]
    s.dx = m.r32((s.cx+0x00000018u));
  }
  L00427ef6: { // 0x427ef6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00427ef7: { // 0x427ef7: 89748204 MOV dword ptr [EDX + EAX*0x4 + 0x4],ESI
    m.w32((s.dx+(s.ax * 0x00000004u)+0x00000004u), s.si);
  }
  L00427efb: { // 0x427efb: 8b511c MOV EDX,dword ptr [ECX + 0x1c]
    s.dx = m.r32((s.cx+0x0000001cu));
  }
  L00427efe: { // 0x427efe: 89748204 MOV dword ptr [EDX + EAX*0x4 + 0x4],ESI
    m.w32((s.dx+(s.ax * 0x00000004u)+0x00000004u), s.si);
  }
  L00427f02: { // 0x427f02: 79ef JNS 0x00427ef3
    if(integer::condition("JNS",flags)) goto L00427ef3;
  }
  L00427f04: { // 0x427f04: b844a88100 MOV EAX,0x81a844
    s.ax = 0x0081a844u;
  }
  L00427f09: { // 0x427f09: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00427f0a: { // 0x427f0a: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00427f0c: { // 0x427f0c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00427f0d: { // 0x427f0d: 8d694c LEA EBP,[ECX + 0x4c]
    s.bp = (s.cx+0x0000004cu);
  }
  L00427f10: { // 0x427f10: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00427f14: { // 0x427f14: c744241003000000 MOV dword ptr [ESP + 0x10],0x3
    m.w32((f.sp+0x00000010u), 0x00000003u);
  }
  L00427f1c: { // 0x427f1c: 8b1428 MOV EDX,dword ptr [EAX + EBP*0x1]
    s.dx = m.r32((s.ax+(s.bp * 0x00000001u)));
  }
  L00427f1f: { // 0x427f1f: 8b7df4 MOV EDI,dword ptr [EBP + -0xc]
    s.di = m.r32((s.bp-0x0000000cu));
  }
  L00427f22: { // 0x427f22: 8b7500 MOV ESI,dword ptr [EBP]
    s.si = m.r32((s.bp));
  }
  L00427f25: { // 0x427f25: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L00427f28: { // 0x427f28: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00427f29: { // 0x427f29: 7826 JS 0x00427f51
    if(integer::condition("JS",flags)) goto L00427f51;
  }
  L00427f2b: { // 0x427f2b: 8d0496 LEA EAX,[ESI + EDX*0x4]
    s.ax = (s.si+(s.dx * 0x00000004u));
  }
  L00427f2e: { // 0x427f2e: 2bfe SUB EDI,ESI
    s.di = integer::sub(s.di,s.si,32,flags);
  }
  L00427f30: { // 0x427f30: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L00427f32: { // 0x427f32: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00427f33: { // 0x427f33: c7040700000000 MOV dword ptr [EDI + EAX*0x1],0x0
    m.w32((s.di+(s.ax * 0x00000001u)), 0x00000000u);
  }
  L00427f3a: { // 0x427f3a: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00427f40: { // 0x427f40: c7040300000000 MOV dword ptr [EBX + EAX*0x1],0x0
    m.w32((s.bx+(s.ax * 0x00000001u)), 0x00000000u);
  }
  L00427f47: { // 0x427f47: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00427f4a: { // 0x427f4a: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00427f4b: { // 0x427f4b: 75e6 JNZ 0x00427f33
    if(integer::condition("JNZ",flags)) goto L00427f33;
  }
  L00427f4d: { // 0x427f4d: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00427f51: { // 0x427f51: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00427f55: { // 0x427f55: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L00427f58: { // 0x427f58: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00427f59: { // 0x427f59: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00427f5d: { // 0x427f5d: 75bd JNZ 0x00427f1c
    if(integer::condition("JNZ",flags)) goto L00427f1c;
  }
  L00427f5f: { // 0x427f5f: 8b4128 MOV EAX,dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  L00427f62: { // 0x427f62: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00427f63: { // 0x427f63: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00427f64: { // 0x427f64: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00427f65: { // 0x427f65: 894128 MOV dword ptr [ECX + 0x28],EAX
    m.w32((s.cx+0x00000028u), s.ax);
  }
  L00427f68: { // 0x427f68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00427f69: { // 0x427f69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00427f6a: { // 0x427f6a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00427f6d: { // 0x427f6d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00028a90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00428a90: { // 0x428a90: 0fbf5102 MOVSX EDX,word ptr [ECX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L00428a94: { // 0x428a94: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L00428a97: { // 0x428a97: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00428a98: { // 0x428a98: 8b3510a98100 MOV ESI,dword ptr [0x0081a910]
    s.si = m.r32((0x0081a910u));
  }
  L00428a9e: { // 0x428a9e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00428aa0: { // 0x428aa0: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00428aa2: { // 0x428aa2: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00428aa4: { // 0x428aa4: 8d4c31ff LEA ECX,[ECX + ESI*0x1 + -0x1]
    s.cx = (s.cx+(s.si * 0x00000001u)-0x00000001u);
  }
  L00428aa8: { // 0x428aa8: 8d4410ff LEA EAX,[EAX + EDX*0x1 + -0x1]
    s.ax = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  L00428aac: { // 0x428aac: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00428aaf: { // 0x428aaf: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00428ab1: { // 0x428ab1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00428ab3: { // 0x428ab3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00428ab4: { // 0x428ab4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00028ac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00428ac0: { // 0x428ac0: a114a98100 MOV EAX,[0x0081a914]
    s.ax = m.r32((0x0081a914u));
  }
  L00428ac5: { // 0x428ac5: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00428ac8: { // 0x428ac8: 0faf0510a98100 IMUL EAX,dword ptr [0x0081a910]
    s.ax = integer::imul(s.ax,m.r32((0x0081a910u)),32,flags);
  }
  L00428acf: { // 0x428acf: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00428ad1: { // 0x428ad1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00029b60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00429b60: { // 0x429b60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00429b61: { // 0x429b61: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00429b63: { // 0x429b63: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00429b66: { // 0x429b66: 83ec5c SUB ESP,0x5c
    f.sp = integer::sub(f.sp,0x0000005cu,32,flags);
  }
  L00429b69: { // 0x429b69: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L00429b6c: { // 0x429b6c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00429b6d: { // 0x429b6d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00429b6e: { // 0x429b6e: 8b7514 MOV ESI,dword ptr [EBP + 0x14]
    s.si = m.r32((s.bp+0x00000014u));
  }
  L00429b71: { // 0x429b71: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L00429b74: { // 0x429b74: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00429b75: { // 0x429b75: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00429b77: { // 0x429b77: 059cab7c00 ADD EAX,0x7cab9c
    s.ax = integer::add(s.ax,0x007cab9cu,32,flags);
  }
  L00429b7c: { // 0x429b7c: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L00429b80: { // 0x429b80: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00429b82: { // 0x429b82: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L00429b86: { // 0x429b86: 7417 JZ 0x00429b9f
    if(integer::condition("JZ",flags)) goto L00429b9f;
  }
  L00429b88: { // 0x429b88: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00429b8a: { // 0x429b8a: e821100a00 CALL 0x004cabb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004cabb0u,4365199u); flags=s.arithmetic_flags;
  }
  L00429b8f: { // 0x429b8f: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00429b95: { // 0x429b95: dd542460 FST double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00429b99: { // 0x429b99: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00429b9d: { // 0x429b9d: eb1a JMP 0x00429bb9
    goto L00429bb9;
  }
  L00429b9f: { // 0x429b9f: c744246000000000 MOV dword ptr [ESP + 0x60],0x0
    m.w32((f.sp+0x00000060u), 0x00000000u);
  }
  L00429ba7: { // 0x429ba7: c744246400000000 MOV dword ptr [ESP + 0x64],0x0
    m.w32((f.sp+0x00000064u), 0x00000000u);
  }
  L00429baf: { // 0x429baf: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L00429bb7: { // 0x429bb7: eb12 JMP 0x00429bcb
    goto L00429bcb;
  }
  L00429bb9: { // 0x429bb9: dc1d20757800 FCOMP double ptr [0x00787520]
    const auto address=(0x00787520u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00429bbf: { // 0x429bbf: c644241001 MOV byte ptr [ESP + 0x10],0x1
    m.w8((f.sp+0x00000010u), 0x00000001u);
  }
  L00429bc4: { // 0x429bc4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00429bc6: { // 0x429bc6: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00429bc9: { // 0x429bc9: 7405 JZ 0x00429bd0
    if(integer::condition("JZ",flags)) goto L00429bd0;
  }
  L00429bcb: { // 0x429bcb: c644241000 MOV byte ptr [ESP + 0x10],0x0
    m.w8((f.sp+0x00000010u), 0x00000000u);
  }
  L00429bd0: { // 0x429bd0: be02000000 MOV ESI,0x2
    s.si = 0x00000002u;
  }
  L00429bd5: { // 0x429bd5: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L00429bd9: { // 0x429bd9: 8b4768 MOV EAX,dword ptr [EDI + 0x68]
    s.ax = m.r32((s.di+0x00000068u));
  }
  L00429bdc: { // 0x429bdc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00429bde: { // 0x429bde: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L00429be1: { // 0x429be1: 7c12 JL 0x00429bf5
    if(integer::condition("JL",flags)) goto L00429bf5;
  }
  L00429be3: { // 0x429be3: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00429be6: { // 0x429be6: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00429be7: { // 0x429be7: c7448afc00000000 MOV dword ptr [EDX + ECX*0x4 + -0x4],0x0
    m.w32((s.dx+(s.cx * 0x00000004u)-0x00000004u), 0x00000000u);
  }
  L00429bef: { // 0x429bef: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00429bf1: { // 0x429bf1: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00429bf3: { // 0x429bf3: 7eee JLE 0x00429be3
    if(integer::condition("JLE",flags)) goto L00429be3;
  }
  L00429bf5: { // 0x429bf5: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00429bfb: { // 0x429bfb: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00429bfe: { // 0x429bfe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429bff: { // 0x429bff: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00429c04: { // 0x429c04: e837331200 CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,4365321u); flags=s.arithmetic_flags;
  }
  L00429c09: { // 0x429c09: 8b158ca88100 MOV EDX,dword ptr [0x0081a88c]
    s.dx = m.r32((0x0081a88cu));
  }
  L00429c0f: { // 0x429c0f: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L00429c12: { // 0x429c12: 8d044a LEA EAX,[EDX + ECX*0x2]
    s.ax = (s.dx+(s.cx * 0x00000002u));
  }
  L00429c15: { // 0x429c15: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00429c1a: { // 0x429c1a: 0fbf1c70 MOVSX EBX,word ptr [EAX + ESI*0x2]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.si * 0x00000002u))),16));
  }
  L00429c1e: { // 0x429c1e: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00429c21: { // 0x429c21: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L00429c25: { // 0x429c25: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429c26: { // 0x429c26: e815331200 CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,4365355u); flags=s.arithmetic_flags;
  }
  L00429c2b: { // 0x429c2b: 8b158ca88100 MOV EDX,dword ptr [0x0081a88c]
    s.dx = m.r32((0x0081a88cu));
  }
  L00429c31: { // 0x429c31: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L00429c34: { // 0x429c34: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  L00429c37: { // 0x429c37: 8d044a LEA EAX,[EDX + ECX*0x2]
    s.ax = (s.dx+(s.cx * 0x00000002u));
  }
  L00429c3a: { // 0x429c3a: 0fbf0470 MOVSX EAX,word ptr [EAX + ESI*0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.si * 0x00000002u))),16));
  }
  L00429c3e: { // 0x429c3e: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00429c42: { // 0x429c42: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L00429c45: { // 0x429c45: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00429c47: { // 0x429c47: 88442412 MOV byte ptr [ESP + 0x12],AL
    m.w8((f.sp+0x00000012u), (s.ax & 0xffu));
  }
  L00429c4b: { // 0x429c4b: 750a JNZ 0x00429c57
    if(integer::condition("JNZ",flags)) goto L00429c57;
  }
  L00429c4d: { // 0x429c4d: 8b4cb744 MOV ECX,dword ptr [EDI + ESI*0x4 + 0x44]
    s.cx = m.r32((s.di+(s.si * 0x00000004u)+0x00000044u));
  }
  L00429c51: { // 0x429c51: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00429c55: { // 0x429c55: eb08 JMP 0x00429c5f
    goto L00429c5f;
  }
  L00429c57: { // 0x429c57: c744244400000000 MOV dword ptr [ESP + 0x44],0x0
    m.w32((f.sp+0x00000044u), 0x00000000u);
  }
  L00429c5f: { // 0x429c5f: 8b54b74c MOV EDX,dword ptr [EDI + ESI*0x4 + 0x4c]
    s.dx = m.r32((s.di+(s.si * 0x00000004u)+0x0000004cu));
  }
  L00429c63: { // 0x429c63: 8b44b740 MOV EAX,dword ptr [EDI + ESI*0x4 + 0x40]
    s.ax = m.r32((s.di+(s.si * 0x00000004u)+0x00000040u));
  }
  L00429c67: { // 0x429c67: 8b4cb758 MOV ECX,dword ptr [EDI + ESI*0x4 + 0x58]
    s.cx = m.r32((s.di+(s.si * 0x00000004u)+0x00000058u));
  }
  L00429c6b: { // 0x429c6b: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00429c6f: { // 0x429c6f: 8b5728 MOV EDX,dword ptr [EDI + 0x28]
    s.dx = m.r32((s.di+0x00000028u));
  }
  L00429c72: { // 0x429c72: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00429c76: { // 0x429c76: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00429c7a: { // 0x429c7a: 891498 MOV dword ptr [EAX + EBX*0x4],EDX
    m.w32((s.ax+(s.bx * 0x00000004u)), s.dx);
  }
  L00429c7d: { // 0x429c7d: 8b5728 MOV EDX,dword ptr [EDI + 0x28]
    s.dx = m.r32((s.di+0x00000028u));
  }
  L00429c80: { // 0x429c80: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00429c82: { // 0x429c82: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L00429c86: { // 0x429c86: 891488 MOV dword ptr [EAX + ECX*0x4],EDX
    m.w32((s.ax+(s.cx * 0x00000004u)), s.dx);
  }
  L00429c89: { // 0x429c89: 752e JNZ 0x00429cb9
    if(integer::condition("JNZ",flags)) goto L00429cb9;
  }
  L00429c8b: { // 0x429c8b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00429c8d: { // 0x429c8d: 7509 JNZ 0x00429c98
    if(integer::condition("JNZ",flags)) goto L00429c98;
  }
  L00429c8f: { // 0x429c8f: 8b4764 MOV EAX,dword ptr [EDI + 0x64]
    s.ax = m.r32((s.di+0x00000064u));
  }
  L00429c92: { // 0x429c92: 89700c MOV dword ptr [EAX + 0xc],ESI
    m.w32((s.ax+0x0000000cu), s.si);
  }
  L00429c95: { // 0x429c95: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L00429c98: { // 0x429c98: 8d04b6 LEA EAX,[ESI + ESI*0x4]
    s.ax = (s.si+(s.si * 0x00000004u));
  }
  L00429c9b: { // 0x429c9b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00429c9e: { // 0x429c9e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00429ca1: { // 0x429ca1: 66899cc7bc000000 MOV word ptr [EDI + EAX*0x8 + 0xbc],BX
    m.w16((s.di+(s.ax * 0x00000008u)+0x000000bcu), (s.bx & 0xffffu));
  }
  L00429ca9: { // 0x429ca9: c784b7740c000001000000 MOV dword ptr [EDI + ESI*0x4 + 0xc74],0x1
    m.w32((s.di+(s.si * 0x00000004u)+0x00000c74u), 0x00000001u);
  }
  L00429cb4: { // 0x429cb4: e9ed040000 JMP 0x0042a1a6
    goto L0042a1a6;
  }
  L00429cb9: { // 0x429cb9: 8b4764 MOV EAX,dword ptr [EDI + 0x64]
    s.ax = m.r32((s.di+0x00000064u));
  }
  L00429cbc: { // 0x429cbc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00429cbe: { // 0x429cbe: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00429cc2: { // 0x429cc2: c700ffffffff MOV dword ptr [EAX],0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  L00429cc8: { // 0x429cc8: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L00429ccb: { // 0x429ccb: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00429cce: { // 0x429cce: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00429cd1: { // 0x429cd1: 8b4768 MOV EAX,dword ptr [EDI + 0x68]
    s.ax = m.r32((s.di+0x00000068u));
  }
  L00429cd4: { // 0x429cd4: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00429cd8: { // 0x429cd8: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00429cda: { // 0x429cda: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00429cdb: { // 0x429cdb: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00429cdd: { // 0x429cdd: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00429cdf: { // 0x429cdf: 3b4804 CMP ECX,dword ptr [EAX + 0x4]
    (void)integer::sub(s.cx,m.r32((s.ax+0x00000004u)),32,flags);
  }
  L00429ce2: { // 0x429ce2: 7363 JNC 0x00429d47
    if(integer::condition("JNC",flags)) goto L00429d47;
  }
  L00429ce4: { // 0x429ce4: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00429ce7: { // 0x429ce7: 7635 JBE 0x00429d1e
    if(integer::condition("JBE",flags)) goto L00429d1e;
  }
  L00429ce9: { // 0x429ce9: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00429ced: { // 0x429ced: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00429cf0: { // 0x429cf0: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L00429cf4: { // 0x429cf4: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00429cf7: { // 0x429cf7: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00429cfa: { // 0x429cfa: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00429d00: { // 0x429d00: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00429d02: { // 0x429d02: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00429d05: { // 0x429d05: 7517 JNZ 0x00429d1e
    if(integer::condition("JNZ",flags)) goto L00429d1e;
  }
  L00429d07: { // 0x429d07: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00429d0b: { // 0x429d0b: 8b1c90 MOV EBX,dword ptr [EAX + EDX*0x4]
    s.bx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00429d0e: { // 0x429d0e: 891c88 MOV dword ptr [EAX + ECX*0x4],EBX
    m.w32((s.ax+(s.cx * 0x00000004u)), s.bx);
  }
  L00429d11: { // 0x429d11: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L00429d15: { // 0x429d15: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00429d17: { // 0x429d17: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00429d19: { // 0x429d19: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00429d1c: { // 0x429d1c: 77cb JA 0x00429ce9
    if(integer::condition("JA",flags)) goto L00429ce9;
  }
  L00429d1e: { // 0x429d1e: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00429d22: { // 0x429d22: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00429d25: { // 0x429d25: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00429d29: { // 0x429d29: 891488 MOV dword ptr [EAX + ECX*0x4],EDX
    m.w32((s.ax+(s.cx * 0x00000004u)), s.dx);
  }
  L00429d2c: { // 0x429d2c: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00429d30: { // 0x429d30: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00429d32: { // 0x429d32: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00429d33: { // 0x429d33: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00429d35: { // 0x429d35: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00429d38: { // 0x429d38: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00429d3a: { // 0x429d3a: 7603 JBE 0x00429d3f
    if(integer::condition("JBE",flags)) goto L00429d3f;
  }
  L00429d3c: { // 0x429d3c: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L00429d3f: { // 0x429d3f: 3b5010 CMP EDX,dword ptr [EAX + 0x10]
    (void)integer::sub(s.dx,m.r32((s.ax+0x00000010u)),32,flags);
  }
  L00429d42: { // 0x429d42: 7303 JNC 0x00429d47
    if(integer::condition("JNC",flags)) goto L00429d47;
  }
  L00429d44: { // 0x429d44: 895010 MOV dword ptr [EAX + 0x10],EDX
    m.w32((s.ax+0x00000010u), s.dx);
  }
  L00429d47: { // 0x429d47: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00429d4b: { // 0x429d4b: 8b4f28 MOV ECX,dword ptr [EDI + 0x28]
    s.cx = m.r32((s.di+0x00000028u));
  }
  L00429d4e: { // 0x429d4e: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00429d52: { // 0x429d52: c744242c01000000 MOV dword ptr [ESP + 0x2c],0x1
    m.w32((f.sp+0x0000002cu), 0x00000001u);
  }
  L00429d5a: { // 0x429d5a: 890c9a MOV dword ptr [EDX + EBX*0x4],ECX
    m.w32((s.dx+(s.bx * 0x00000004u)), s.cx);
  }
  L00429d5d: { // 0x429d5d: c7049800000000 MOV dword ptr [EAX + EBX*0x4],0x0
    m.w32((s.ax+(s.bx * 0x00000004u)), 0x00000000u);
  }
  L00429d64: { // 0x429d64: 8b4f68 MOV ECX,dword ptr [EDI + 0x68]
    s.cx = m.r32((s.di+0x00000068u));
  }
  L00429d67: { // 0x429d67: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00429d69: { // 0x429d69: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00429d6b: { // 0x429d6b: 7504 JNZ 0x00429d71
    if(integer::condition("JNZ",flags)) goto L00429d71;
  }
  L00429d6d: { // 0x429d6d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00429d6f: { // 0x429d6f: eb26 JMP 0x00429d97
    goto L00429d97;
  }
  L00429d71: { // 0x429d71: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L00429d74: { // 0x429d74: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00429d76: { // 0x429d76: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00429d79: { // 0x429d79: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L00429d7c: { // 0x429d7c: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00429d7f: { // 0x429d7f: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00429d81: { // 0x429d81: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L00429d84: { // 0x429d84: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L00429d8b: { // 0x429d8b: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00429d8d: { // 0x429d8d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00429d8e: { // 0x429d8e: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00429d90: { // 0x429d90: e8cb170000 CALL 0x0042b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042b560u,4365717u); flags=s.arithmetic_flags;
  }
  L00429d95: { // 0x429d95: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00429d97: { // 0x429d97: 8d1476 LEA EDX,[ESI + ESI*0x2]
    s.dx = (s.si+(s.si * 0x00000002u));
  }
  L00429d9a: { // 0x429d9a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00429d9e: { // 0x429d9e: c1e203 SHL EDX,0x3
    s.dx = integer::shift(s.dx,0x00000003u,32,flags,integer::Shift::left);
  }
  L00429da1: { // 0x429da1: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00429da5: { // 0x429da5: 8b9c3a84000000 MOV EBX,dword ptr [EDX + EDI*0x1 + 0x84]
    s.bx = m.r32((s.dx+(s.di * 0x00000001u)+0x00000084u));
  }
  L00429dac: { // 0x429dac: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00429dae: { // 0x429dae: 0f94442413 SETZ byte ptr [ESP + 0x13]
    m.w8((f.sp+0x00000013u), (integer::condition("SETZ",flags)?1u:0u));
  }
  L00429db3: { // 0x429db3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00429db5: { // 0x429db5: 0f84f7030000 JZ 0x0042a1b2
    if(integer::condition("JZ",flags)) goto L0042a1b2;
  }
  L00429dbb: { // 0x429dbb: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00429dbe: { // 0x429dbe: 8b5c243c MOV EBX,dword ptr [ESP + 0x3c]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L00429dc2: { // 0x429dc2: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00429dc4: { // 0x429dc4: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L00429dc8: { // 0x429dc8: 0f8454030000 JZ 0x0042a122
    if(integer::condition("JZ",flags)) goto L0042a122;
  }
  L00429dce: { // 0x429dce: 8d04c9 LEA EAX,[ECX + ECX*0x8]
    s.ax = (s.cx+(s.cx * 0x00000008u));
  }
  L00429dd1: { // 0x429dd1: 8b8aaca88100 MOV ECX,dword ptr [EDX + 0x81a8ac]
    s.cx = m.r32((s.dx+0x0081a8acu));
  }
  L00429dd7: { // 0x429dd7: 8b548104 MOV EDX,dword ptr [ECX + EAX*0x4 + 0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)+0x00000004u));
  }
  L00429ddb: { // 0x429ddb: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  L00429dde: { // 0x429dde: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00429de1: { // 0x429de1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00429de3: { // 0x429de3: 0f8e27020000 JLE 0x0042a010
    if(integer::condition("JLE",flags)) goto L0042a010;
  }
  L00429de9: { // 0x429de9: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00429ded: { // 0x429ded: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L00429df1: { // 0x429df1: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00429df4: { // 0x429df4: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00429df8: { // 0x429df8: 894c2450 MOV dword ptr [ESP + 0x50],ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L00429dfc: { // 0x429dfc: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00429e00: { // 0x429e00: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00429e04: { // 0x429e04: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00429e06: { // 0x429e06: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00429e0e: { // 0x429e0e: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00429e10: { // 0x429e10: 8a5004 MOV DL,byte ptr [EAX + 0x4]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000004u)));
  }
  L00429e13: { // 0x429e13: 88542411 MOV byte ptr [ESP + 0x11],DL
    m.w8((f.sp+0x00000011u), (s.dx & 0xffu));
  }
  L00429e17: { // 0x429e17: 8b91aca88100 MOV EDX,dword ptr [ECX + 0x81a8ac]
    s.dx = m.r32((s.cx+0x0081a8acu));
  }
  L00429e1d: { // 0x429e1d: 8d04db LEA EAX,[EBX + EBX*0x8]
    s.ax = (s.bx+(s.bx * 0x00000008u));
  }
  L00429e20: { // 0x429e20: 895c244c MOV dword ptr [ESP + 0x4c],EBX
    m.w32((f.sp+0x0000004cu), s.bx);
  }
  L00429e24: { // 0x429e24: 668b748218 MOV SI,word ptr [EDX + EAX*0x4 + 0x18]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx+(s.ax * 0x00000004u)+0x00000018u))) & 0xffffu);
  }
  L00429e29: { // 0x429e29: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L00429e2c: { // 0x429e2c: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L00429e2f: { // 0x429e2f: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  L00429e33: { // 0x429e33: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00429e35: { // 0x429e35: 89542454 MOV dword ptr [ESP + 0x54],EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L00429e39: { // 0x429e39: 7433 JZ 0x00429e6e
    if(integer::condition("JZ",flags)) goto L00429e6e;
  }
  L00429e3b: { // 0x429e3b: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00429e3f: { // 0x429e3f: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00429e43: { // 0x429e43: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00429e47: { // 0x429e47: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00429e48: { // 0x429e48: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429e49: { // 0x429e49: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00429e4a: { // 0x429e4a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00429e4b: { // 0x429e4b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00429e50: { // 0x429e50: e8bbac1300 CALL 0x00564b10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564b10u,4365909u); flags=s.arithmetic_flags;
  }
  L00429e55: { // 0x429e55: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00429e59: { // 0x429e59: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L00429e5d: { // 0x429e5d: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L00429e61: { // 0x429e61: e8ea0b3400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4365926u); flags=s.arithmetic_flags;
  }
  L00429e66: { // 0x429e66: 8b542454 MOV EDX,dword ptr [ESP + 0x54]
    s.dx = m.r32((f.sp+0x00000054u));
  }
  L00429e6a: { // 0x429e6a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00429e6e: { // 0x429e6e: 8a442411 MOV AL,byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L00429e72: { // 0x429e72: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00429e74: { // 0x429e74: 7408 JZ 0x00429e7e
    if(integer::condition("JZ",flags)) goto L00429e7e;
  }
  L00429e76: { // 0x429e76: dd0528757800 FLD double ptr [0x00787528]
    const auto address=(0x00787528u);
    s.fp.load64(read64(m,address));
  }
  L00429e7c: { // 0x429e7c: eb06 JMP 0x00429e84
    goto L00429e84;
  }
  L00429e7e: { // 0x429e7e: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L00429e84: { // 0x429e84: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00429e88: { // 0x429e88: 8b4f28 MOV ECX,dword ptr [EDI + 0x28]
    s.cx = m.r32((s.di+0x00000028u));
  }
  L00429e8b: { // 0x429e8b: d90495a4747800 FLD float ptr [EDX*0x4 + 0x7874a4]
    const auto address=((s.dx * 0x00000004u)+0x007874a4u);
    s.fp.load32(m.r32(address));
  }
  L00429e92: { // 0x429e92: d84008 FADD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.add32(m.r32(address));
  }
  L00429e95: { // 0x429e95: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00429e99: { // 0x429e99: da442418 FIADD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00429e9d: { // 0x429e9d: 390c98 CMP dword ptr [EAX + EBX*0x4],ECX
    (void)integer::sub(m.r32((s.ax+(s.bx * 0x00000004u))),s.cx,32,flags);
  }
  L00429ea0: { // 0x429ea0: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00429ea2: { // 0x429ea2: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00429ea6: { // 0x429ea6: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00429ea8: { // 0x429ea8: 7516 JNZ 0x00429ec0
    if(integer::condition("JNZ",flags)) goto L00429ec0;
  }
  L00429eaa: { // 0x429eaa: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00429eae: { // 0x429eae: d90498 FLD float ptr [EAX + EBX*0x4]
    const auto address=(s.ax+(s.bx * 0x00000004u));
    s.fp.load32(m.r32(address));
  }
  L00429eb1: { // 0x429eb1: d85c2418 FCOMP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00429eb5: { // 0x429eb5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00429eb7: { // 0x429eb7: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00429eba: { // 0x429eba: 0f8536010000 JNZ 0x00429ff6
    if(integer::condition("JNZ",flags)) goto L00429ff6;
  }
  L00429ec0: { // 0x429ec0: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L00429ec4: { // 0x429ec4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00429ec6: { // 0x429ec6: 7512 JNZ 0x00429eda
    if(integer::condition("JNZ",flags)) goto L00429eda;
  }
  L00429ec8: { // 0x429ec8: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00429ecc: { // 0x429ecc: 390cb0 CMP dword ptr [EAX + ESI*0x4],ECX
    (void)integer::sub(m.r32((s.ax+(s.si * 0x00000004u))),s.cx,32,flags);
  }
  L00429ecf: { // 0x429ecf: 7409 JZ 0x00429eda
    if(integer::condition("JZ",flags)) goto L00429eda;
  }
  L00429ed1: { // 0x429ed1: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L00429ed4: { // 0x429ed4: 0f851c010000 JNZ 0x00429ff6
    if(integer::condition("JNZ",flags)) goto L00429ff6;
  }
  L00429eda: { // 0x429eda: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L00429ede: { // 0x429ede: 833c9101 CMP dword ptr [ECX + EDX*0x4],0x1
    (void)integer::sub(m.r32((s.cx+(s.dx * 0x00000004u))),0x00000001u,32,flags);
  }
  L00429ee2: { // 0x429ee2: 0f850e010000 JNZ 0x00429ff6
    if(integer::condition("JNZ",flags)) goto L00429ff6;
  }
  L00429ee8: { // 0x429ee8: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00429eec: { // 0x429eec: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00429eee: { // 0x429eee: 7546 JNZ 0x00429f36
    if(integer::condition("JNZ",flags)) goto L00429f36;
  }
  L00429ef0: { // 0x429ef0: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00429ef4: { // 0x429ef4: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00429ef6: { // 0x429ef6: 663bda CMP BX,DX
    (void)integer::sub((s.bx & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L00429ef9: { // 0x429ef9: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00429efb: { // 0x429efb: 7304 JNC 0x00429f01
    if(integer::condition("JNC",flags)) goto L00429f01;
  }
  L00429efd: { // 0x429efd: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00429eff: { // 0x429eff: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00429f01: { // 0x429f01: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00429f05: { // 0x429f05: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00429f0a: { // 0x429f0a: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L00429f0d: { // 0x429f0d: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L00429f13: { // 0x429f13: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  L00429f15: { // 0x429f15: 8b8c3a84000000 MOV ECX,dword ptr [EDX + EDI*0x1 + 0x84]
    s.cx = m.r32((s.dx+(s.di * 0x00000001u)+0x00000084u));
  }
  L00429f1c: { // 0x429f1c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00429f1d: { // 0x429f1d: 7817 JS 0x00429f36
    if(integer::condition("JS",flags)) goto L00429f36;
  }
  L00429f1f: { // 0x429f1f: 8b543a78 MOV EDX,dword ptr [EDX + EDI*0x1 + 0x78]
    s.dx = m.r32((s.dx+(s.di * 0x00000001u)+0x00000078u));
  }
  L00429f23: { // 0x429f23: 8d148a LEA EDX,[EDX + ECX*0x4]
    s.dx = (s.dx+(s.cx * 0x00000004u));
  }
  L00429f26: { // 0x429f26: 3902 CMP dword ptr [EDX],EAX
    (void)integer::sub(m.r32((s.dx)),s.ax,32,flags);
  }
  L00429f28: { // 0x429f28: 0f84c8000000 JZ 0x00429ff6
    if(integer::condition("JZ",flags)) goto L00429ff6;
  }
  L00429f2e: { // 0x429f2e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00429f2f: { // 0x429f2f: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
  L00429f32: { // 0x429f32: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00429f34: { // 0x429f34: 7df0 JGE 0x00429f26
    if(integer::condition("JGE",flags)) goto L00429f26;
  }
  L00429f36: { // 0x429f36: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00429f3a: { // 0x429f3a: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00429f3e: { // 0x429f3e: 8b4264 MOV EAX,dword ptr [EDX + 0x64]
    s.ax = m.r32((s.dx+0x00000064u));
  }
  L00429f41: { // 0x429f41: 895c0804 MOV dword ptr [EAX + ECX*0x1 + 0x4],EBX
    m.w32((s.ax+(s.cx * 0x00000001u)+0x00000004u), s.bx);
  }
  L00429f45: { // 0x429f45: 8d3408 LEA ESI,[EAX + ECX*0x1]
    s.si = (s.ax+(s.cx * 0x00000001u));
  }
  L00429f48: { // 0x429f48: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00429f4c: { // 0x429f4c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00429f4e: { // 0x429f4e: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00429f50: { // 0x429f50: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00429f54: { // 0x429f54: c1ff04 SAR EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00429f57: { // 0x429f57: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L00429f59: { // 0x429f59: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00429f5c: { // 0x429f5c: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00429f5f: { // 0x429f5f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00429f60: { // 0x429f60: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00429f63: { // 0x429f63: 8b7a68 MOV EDI,dword ptr [EDX + 0x68]
    s.di = m.r32((s.dx+0x00000068u));
  }
  L00429f66: { // 0x429f66: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00429f68: { // 0x429f68: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00429f6b: { // 0x429f6b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00429f6c: { // 0x429f6c: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00429f6e: { // 0x429f6e: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00429f70: { // 0x429f70: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00429f72: { // 0x429f72: 7351 JNC 0x00429fc5
    if(integer::condition("JNC",flags)) goto L00429fc5;
  }
  L00429f74: { // 0x429f74: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00429f77: { // 0x429f77: 762f JBE 0x00429fa8
    if(integer::condition("JBE",flags)) goto L00429fa8;
  }
  L00429f79: { // 0x429f79: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00429f7c: { // 0x429f7c: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L00429f7f: { // 0x429f7f: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00429f83: { // 0x429f83: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00429f86: { // 0x429f86: d85c2418 FCOMP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00429f8a: { // 0x429f8a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00429f8c: { // 0x429f8c: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00429f8f: { // 0x429f8f: 7517 JNZ 0x00429fa8
    if(integer::condition("JNZ",flags)) goto L00429fa8;
  }
  L00429f91: { // 0x429f91: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00429f94: { // 0x429f94: 8b5c2454 MOV EBX,dword ptr [ESP + 0x54]
    s.bx = m.r32((f.sp+0x00000054u));
  }
  L00429f98: { // 0x429f98: 891c88 MOV dword ptr [EAX + ECX*0x4],EBX
    m.w32((s.ax+(s.cx * 0x00000004u)), s.bx);
  }
  L00429f9b: { // 0x429f9b: 8b5c244c MOV EBX,dword ptr [ESP + 0x4c]
    s.bx = m.r32((f.sp+0x0000004cu));
  }
  L00429f9f: { // 0x429f9f: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00429fa1: { // 0x429fa1: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00429fa3: { // 0x429fa3: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L00429fa6: { // 0x429fa6: 77d1 JA 0x00429f79
    if(integer::condition("JA",flags)) goto L00429f79;
  }
  L00429fa8: { // 0x429fa8: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00429fab: { // 0x429fab: 89348a MOV dword ptr [EDX + ECX*0x4],ESI
    m.w32((s.dx+(s.cx * 0x00000004u)), s.si);
  }
  L00429fae: { // 0x429fae: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00429fb0: { // 0x429fb0: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00429fb3: { // 0x429fb3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00429fb4: { // 0x429fb4: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00429fb6: { // 0x429fb6: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L00429fb8: { // 0x429fb8: 7603 JBE 0x00429fbd
    if(integer::condition("JBE",flags)) goto L00429fbd;
  }
  L00429fba: { // 0x429fba: 89770c MOV dword ptr [EDI + 0xc],ESI
    m.w32((s.di+0x0000000cu), s.si);
  }
  L00429fbd: { // 0x429fbd: 3b7710 CMP ESI,dword ptr [EDI + 0x10]
    (void)integer::sub(s.si,m.r32((s.di+0x00000010u)),32,flags);
  }
  L00429fc0: { // 0x429fc0: 7303 JNC 0x00429fc5
    if(integer::condition("JNC",flags)) goto L00429fc5;
  }
  L00429fc2: { // 0x429fc2: 897710 MOV dword ptr [EDI + 0x10],ESI
    m.w32((s.di+0x00000010u), s.si);
  }
  L00429fc5: { // 0x429fc5: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00429fc9: { // 0x429fc9: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00429fcd: { // 0x429fcd: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L00429fd1: { // 0x429fd1: 8b4828 MOV ECX,dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L00429fd4: { // 0x429fd4: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00429fd8: { // 0x429fd8: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L00429fdc: { // 0x429fdc: 890c9a MOV dword ptr [EDX + EBX*0x4],ECX
    m.w32((s.dx+(s.bx * 0x00000004u)), s.cx);
  }
  L00429fdf: { // 0x429fdf: d91c98 FSTP float ptr [EAX + EBX*0x4]
    const auto address=(s.ax+(s.bx * 0x00000004u));
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00429fe2: { // 0x429fe2: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00429fe6: { // 0x429fe6: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00429fea: { // 0x429fea: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00429feb: { // 0x429feb: 83c010 ADD EAX,0x10
    s.ax = integer::add(s.ax,0x00000010u,32,flags);
  }
  L00429fee: { // 0x429fee: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00429ff2: { // 0x429ff2: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00429ff6: { // 0x429ff6: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00429ffa: { // 0x429ffa: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00429ffe: { // 0x429ffe: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L0042a001: { // 0x42a001: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0042a002: { // 0x42a002: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0042a006: { // 0x42a006: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0042a00a: { // 0x42a00a: 0f85ecfdffff JNZ 0x00429dfc
    if(integer::condition("JNZ",flags)) goto L00429dfc;
  }
  L0042a010: { // 0x42a010: 8b4f68 MOV ECX,dword ptr [EDI + 0x68]
    s.cx = m.r32((s.di+0x00000068u));
  }
  L0042a013: { // 0x42a013: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0042a015: { // 0x42a015: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0042a017: { // 0x42a017: 0f8495010000 JZ 0x0042a1b2
    if(integer::condition("JZ",flags)) goto L0042a1b2;
  }
  L0042a01d: { // 0x42a01d: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a020: { // 0x42a020: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L0042a025: { // 0x42a025: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0042a028: { // 0x42a028: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0042a02b: { // 0x42a02b: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0042a02e: { // 0x42a02e: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0042a030: { // 0x42a030: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0042a033: { // 0x42a033: 89742454 MOV dword ptr [ESP + 0x54],ESI
    m.w32((f.sp+0x00000054u), s.si);
  }
  L0042a037: { // 0x42a037: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L0042a03e: { // 0x42a03e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0042a040: { // 0x42a040: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0042a041: { // 0x42a041: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0042a043: { // 0x42a043: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0042a045: { // 0x42a045: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  L0042a048: { // 0x42a048: 7c1d JL 0x0042a067
    if(integer::condition("JL",flags)) goto L0042a067;
  }
  L0042a04a: { // 0x42a04a: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a04d: { // 0x42a04d: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0042a050: { // 0x42a050: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L0042a053: { // 0x42a053: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a056: { // 0x42a056: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a059: { // 0x42a059: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0042a05b: { // 0x42a05b: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0042a060: { // 0x42a060: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0042a062: { // 0x42a062: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0042a065: { // 0x42a065: 7405 JZ 0x0042a06c
    if(integer::condition("JZ",flags)) goto L0042a06c;
  }
  L0042a067: { // 0x42a067: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0042a06c: { // 0x42a06c: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L0042a06f: { // 0x42a06f: 7c1f JL 0x0042a090
    if(integer::condition("JL",flags)) goto L0042a090;
  }
  L0042a071: { // 0x42a071: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a074: { // 0x42a074: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  L0042a077: { // 0x42a077: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0042a07a: { // 0x42a07a: d94608 FLD float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a07d: { // 0x42a07d: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a080: { // 0x42a080: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0042a082: { // 0x42a082: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0042a084: { // 0x42a084: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0042a087: { // 0x42a087: 7507 JNZ 0x0042a090
    if(integer::condition("JNZ",flags)) goto L0042a090;
  }
  L0042a089: { // 0x42a089: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L0042a08e: { // 0x42a08e: eb05 JMP 0x0042a095
    goto L0042a095;
  }
  L0042a090: { // 0x42a090: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L0042a093: { // 0x42a093: 7470 JZ 0x0042a105
    if(integer::condition("JZ",flags)) goto L0042a105;
  }
  L0042a095: { // 0x42a095: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a098: { // 0x42a098: 8b3c90 MOV EDI,dword ptr [EAX + EDX*0x4]
    s.di = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0042a09b: { // 0x42a09b: 8b3498 MOV ESI,dword ptr [EAX + EBX*0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L0042a09e: { // 0x42a09e: 893c98 MOV dword ptr [EAX + EBX*0x4],EDI
    m.w32((s.ax+(s.bx * 0x00000004u)), s.di);
  }
  L0042a0a1: { // 0x42a0a1: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a0a4: { // 0x42a0a4: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0042a0a6: { // 0x42a0a6: 893490 MOV dword ptr [EAX + EDX*0x4],ESI
    m.w32((s.ax+(s.dx * 0x00000004u)), s.si);
  }
  L0042a0a9: { // 0x42a0a9: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L0042a0ab: { // 0x42a0ab: 8d3412 LEA ESI,[EDX + EDX*0x1]
    s.si = (s.dx+(s.dx * 0x00000001u));
  }
  L0042a0ae: { // 0x42a0ae: 8d441201 LEA EAX,[EDX + EDX*0x1 + 0x1]
    s.ax = (s.dx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0042a0b2: { // 0x42a0b2: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L0042a0b4: { // 0x42a0b4: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0042a0b8: { // 0x42a0b8: 7f1d JG 0x0042a0d7
    if(integer::condition("JG",flags)) goto L0042a0d7;
  }
  L0042a0ba: { // 0x42a0ba: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a0bd: { // 0x42a0bd: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0042a0c0: { // 0x42a0c0: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a0c3: { // 0x42a0c3: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a0c6: { // 0x42a0c6: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0042a0c9: { // 0x42a0c9: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a0cc: { // 0x42a0cc: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0042a0ce: { // 0x42a0ce: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0042a0d0: { // 0x42a0d0: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0042a0d3: { // 0x42a0d3: 7502 JNZ 0x0042a0d7
    if(integer::condition("JNZ",flags)) goto L0042a0d7;
  }
  L0042a0d5: { // 0x42a0d5: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0042a0d7: { // 0x42a0d7: 397c2434 CMP dword ptr [ESP + 0x34],EDI
    (void)integer::sub(m.r32((f.sp+0x00000034u)),s.di,32,flags);
  }
  L0042a0db: { // 0x42a0db: 7f20 JG 0x0042a0fd
    if(integer::condition("JG",flags)) goto L0042a0fd;
  }
  L0042a0dd: { // 0x42a0dd: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0042a0e0: { // 0x42a0e0: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L0042a0e4: { // 0x42a0e4: 8b34b0 MOV ESI,dword ptr [EAX + ESI*0x4]
    s.si = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0042a0e7: { // 0x42a0e7: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0042a0ea: { // 0x42a0ea: d94608 FLD float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a0ed: { // 0x42a0ed: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0042a0f0: { // 0x42a0f0: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0042a0f2: { // 0x42a0f2: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0042a0f4: { // 0x42a0f4: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0042a0f7: { // 0x42a0f7: 7504 JNZ 0x0042a0fd
    if(integer::condition("JNZ",flags)) goto L0042a0fd;
  }
  L0042a0f9: { // 0x42a0f9: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0042a0fd: { // 0x42a0fd: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0042a0ff: { // 0x42a0ff: 7594 JNZ 0x0042a095
    if(integer::condition("JNZ",flags)) goto L0042a095;
  }
  L0042a101: { // 0x42a101: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0042a105: { // 0x42a105: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L0042a109: { // 0x42a109: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a10b: { // 0x42a10b: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0042a10f: { // 0x42a10f: 0f849d000000 JZ 0x0042a1b2
    if(integer::condition("JZ",flags)) goto L0042a1b2;
  }
  L0042a115: { // 0x42a115: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L0042a119: { // 0x42a119: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0042a11d: { // 0x42a11d: e999fcffff JMP 0x00429dbb
    goto L00429dbb;
  }
  L0042a122: { // 0x42a122: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a124: { // 0x42a124: 0f8488000000 JZ 0x0042a1b2
    if(integer::condition("JZ",flags)) goto L0042a1b2;
  }
  L0042a12a: { // 0x42a12a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0042a12c: { // 0x42a12c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042a12e: { // 0x42a12e: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0042a131: { // 0x42a131: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0042a135: { // 0x42a135: 7420 JZ 0x0042a157
    if(integer::condition("JZ",flags)) goto L0042a157;
  }
  L0042a137: { // 0x42a137: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0042a13a: { // 0x42a13a: 8b5c245c MOV EBX,dword ptr [ESP + 0x5c]
    s.bx = m.r32((f.sp+0x0000005cu));
  }
  L0042a13e: { // 0x42a13e: 8b5728 MOV EDX,dword ptr [EDI + 0x28]
    s.dx = m.r32((s.di+0x00000028u));
  }
  L0042a141: { // 0x42a141: 89148b MOV dword ptr [EBX + ECX*0x4],EDX
    m.w32((s.bx+(s.cx * 0x00000004u)), s.dx);
  }
  L0042a144: { // 0x42a144: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0042a146: { // 0x42a146: 8b5764 MOV EDX,dword ptr [EDI + 0x64]
    s.dx = m.r32((s.di+0x00000064u));
  }
  L0042a149: { // 0x42a149: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0042a14c: { // 0x42a14c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0042a14e: { // 0x42a14e: 8338ff CMP dword ptr [EAX],-0x1
    (void)integer::sub(m.r32((s.ax)),0xffffffffu,32,flags);
  }
  L0042a151: { // 0x42a151: 75e4 JNZ 0x0042a137
    if(integer::condition("JNZ",flags)) goto L0042a137;
  }
  L0042a153: { // 0x42a153: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L0042a157: { // 0x42a157: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0042a15a: { // 0x42a15a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0042a15b: { // 0x42a15b: 8984b7740c0000 MOV dword ptr [EDI + ESI*0x4 + 0xc74],EAX
    m.w32((s.di+(s.si * 0x00000004u)+0x00000c74u), s.ax);
  }
  L0042a162: { // 0x42a162: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0042a163: { // 0x42a163: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a165: { // 0x42a165: 7e2a JLE 0x0042a191
    if(integer::condition("JLE",flags)) goto L0042a191;
  }
  L0042a167: { // 0x42a167: 8d14b6 LEA EDX,[ESI + ESI*0x4]
    s.dx = (s.si+(s.si * 0x00000004u));
  }
  L0042a16a: { // 0x42a16a: 8d1492 LEA EDX,[EDX + EDX*0x4]
    s.dx = (s.dx+(s.dx * 0x00000004u));
  }
  L0042a16d: { // 0x42a16d: 8d1492 LEA EDX,[EDX + EDX*0x4]
    s.dx = (s.dx+(s.dx * 0x00000004u));
  }
  L0042a170: { // 0x42a170: 8d1490 LEA EDX,[EAX + EDX*0x4]
    s.dx = (s.ax+(s.dx * 0x00000004u));
  }
  L0042a173: { // 0x42a173: 8d9457bc000000 LEA EDX,[EDI + EDX*0x2 + 0xbc]
    s.dx = (s.di+(s.dx * 0x00000002u)+0x000000bcu);
  }
  L0042a17a: { // 0x42a17a: 668b5904 MOV BX,word ptr [ECX + 0x4]
    s.bx = with_ax(s.bx, m.r16((s.cx+0x00000004u)));
  }
  L0042a17e: { // 0x42a17e: 66891a MOV word ptr [EDX],BX
    m.w16((s.dx), (s.bx & 0xffffu));
  }
  L0042a181: { // 0x42a181: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L0042a183: { // 0x42a183: 8b5f64 MOV EBX,dword ptr [EDI + 0x64]
    s.bx = m.r32((s.di+0x00000064u));
  }
  L0042a186: { // 0x42a186: 83ea02 SUB EDX,0x2
    s.dx = integer::sub(s.dx,0x00000002u,32,flags);
  }
  L0042a189: { // 0x42a189: c1e104 SHL ECX,0x4
    s.cx = integer::shift(s.cx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0042a18c: { // 0x42a18c: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0042a18e: { // 0x42a18e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0042a18f: { // 0x42a18f: 75e9 JNZ 0x0042a17a
    if(integer::condition("JNZ",flags)) goto L0042a17a;
  }
  L0042a191: { // 0x42a191: 668b4904 MOV CX,word ptr [ECX + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000004u)));
  }
  L0042a195: { // 0x42a195: 8d04b6 LEA EAX,[ESI + ESI*0x4]
    s.ax = (s.si+(s.si * 0x00000004u));
  }
  L0042a198: { // 0x42a198: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0042a19b: { // 0x42a19b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0042a19e: { // 0x42a19e: 66898cc7bc000000 MOV word ptr [EDI + EAX*0x8 + 0xbc],CX
    m.w16((s.di+(s.ax * 0x00000008u)+0x000000bcu), (s.cx & 0xffffu));
  }
  L0042a1a6: { // 0x42a1a6: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0042a1a7: { // 0x42a1a7: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L0042a1ab: { // 0x42a1ab: 7810 JS 0x0042a1bd
    if(integer::condition("JS",flags)) goto L0042a1bd;
  }
  L0042a1ad: { // 0x42a1ad: e927faffff JMP 0x00429bd9
    goto L00429bd9;
  }
  L0042a1b2: { // 0x42a1b2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0042a1b4: { // 0x42a1b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042a1b5: { // 0x42a1b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042a1b6: { // 0x42a1b6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042a1b7: { // 0x42a1b7: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0042a1b9: { // 0x42a1b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042a1ba: { // 0x42a1ba: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0042a1bd: { // 0x42a1bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042a1be: { // 0x42a1be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042a1bf: { // 0x42a1bf: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0042a1c1: { // 0x42a1c1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042a1c2: { // 0x42a1c2: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0042a1c4: { // 0x42a1c4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042a1c5: { // 0x42a1c5: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_0002ad30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ad30: { // 0x42ad30: 668b542408 MOV DX,word ptr [ESP + 0x8]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000008u)));
  }
  L0042ad35: { // 0x42ad35: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042ad37: { // 0x42ad37: 668b4c2404 MOV CX,word ptr [ESP + 0x4]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000004u)));
  }
  L0042ad3c: { // 0x42ad3c: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L0042ad3f: { // 0x42ad3f: 66895002 MOV word ptr [EAX + 0x2],DX
    m.w16((s.ax+0x00000002u), (s.dx & 0xffffu));
  }
  L0042ad43: { // 0x42ad43: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0002add0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042add0: { // 0x42add0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0042add4: { // 0x42add4: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0042add7: { // 0x42add7: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0042addb: { // 0x42addb: 66034102 ADD AX,word ptr [ECX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+0x00000002u)),16,flags));
  }
  L0042addf: { // 0x42addf: 660311 ADD DX,word ptr [ECX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.cx)),16,flags));
  }
  L0042ade2: { // 0x42ade2: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L0042ade7: { // 0x42ade7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0042adeb: { // 0x42adeb: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L0042adf0: { // 0x42adf0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0042adf4: { // 0x42adf4: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042adf6: { // 0x42adf6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0002ae00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ae00: { // 0x42ae00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042ae01: { // 0x42ae01: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ae02: { // 0x42ae02: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042ae04: { // 0x42ae04: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0042ae06: { // 0x42ae06: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0042ae09: { // 0x42ae09: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  L0042ae0c: { // 0x42ae0c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0042ae0e: { // 0x42ae0e: 7411 JZ 0x0042ae21
    if(integer::condition("JZ",flags)) goto L0042ae21;
  }
  L0042ae10: { // 0x42ae10: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  L0042ae13: { // 0x42ae13: 740c JZ 0x0042ae21
    if(integer::condition("JZ",flags)) goto L0042ae21;
  }
  L0042ae15: { // 0x42ae15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042ae16: { // 0x42ae16: e860283400 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4369947u); flags=s.arithmetic_flags;
  }
  L0042ae1b: { // 0x42ae1b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042ae1e: { // 0x42ae1e: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0042ae21: { // 0x42ae21: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L0042ae24: { // 0x42ae24: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L0042ae27: { // 0x42ae27: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042ae28: { // 0x42ae28: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042ae29: { // 0x42ae29: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000702c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004702c0: { // 0x4702c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004702c1: { // 0x4702c1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L004702c3: { // 0x4702c3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004702c6: { // 0x4702c6: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004702c9: { // 0x4702c9: a0708f8300 MOV AL,[0x00838f70]
    s.ax = with_al(s.ax, m.r8((0x00838f70u)));
  }
  L004702ce: { // 0x4702ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004702cf: { // 0x4702cf: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004702d1: { // 0x4702d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004702d3: { // 0x4702d3: 7513 JNZ 0x004702e8
    if(integer::condition("JNZ",flags)) goto L004702e8;
  }
  L004702d5: { // 0x4702d5: db05808f8300 FILD dword ptr [0x00838f80]
    const auto address=(0x00838f80u);
    s.fp.load_integer32(m.r32(address));
  }
  L004702db: { // 0x4702db: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L004702dd: { // 0x4702dd: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702e2: { // 0x4702e2: dd1df08e8300 FSTP double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004702e8: { // 0x4702e8: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L004702ea: { // 0x4702ea: 7519 JNZ 0x00470305
    if(integer::condition("JNZ",flags)) goto L00470305;
  }
  L004702ec: { // 0x4702ec: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004702f2: { // 0x4702f2: dc0d30577800 FMUL double ptr [0x00785730]
    const auto address=(0x00785730u);
    s.fp.multiply64(read64(m,address));
  }
  L004702f8: { // 0x4702f8: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L004702fa: { // 0x4702fa: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702ff: { // 0x4702ff: dd1d108f8300 FSTP double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00470305: { // 0x470305: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00470307: { // 0x470307: 0f85a7060000 JNZ 0x004709b4
    if(integer::condition("JNZ",flags)) goto L004709b4;
  }
  L0047030d: { // 0x47030d: 8b0df48e8300 MOV ECX,dword ptr [0x00838ef4]
    s.cx = m.r32((0x00838ef4u));
  }
  L00470313: { // 0x470313: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L00470315: { // 0x470315: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L0047031a: { // 0x47031a: a1f08e8300 MOV EAX,[0x00838ef0]
    s.ax = m.r32((0x00838ef0u));
  }
  L0047031f: { // 0x47031f: a398d77b00 MOV [0x007bd798],EAX
    m.w32((0x007bd798u), s.ax);
  }
  L00470324: { // 0x470324: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470326: { // 0x470326: 890d9cd77b00 MOV dword ptr [0x007bd79c],ECX
    m.w32((0x007bd79cu), s.cx);
  }
  L0047032c: { // 0x47032c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047032e: { // 0x47032e: 8915c0d77b00 MOV dword ptr [0x007bd7c0],EDX
    m.w32((0x007bd7c0u), s.dx);
  }
  L00470334: { // 0x470334: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470336: { // 0x470336: a3c4d77b00 MOV [0x007bd7c4],EAX
    m.w32((0x007bd7c4u), s.ax);
  }
  L0047033b: { // 0x47033b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047033d: { // 0x47033d: 890de0d77b00 MOV dword ptr [0x007bd7e0],ECX
    m.w32((0x007bd7e0u), s.cx);
  }
  L00470343: { // 0x470343: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470345: { // 0x470345: 8915e4d77b00 MOV dword ptr [0x007bd7e4],EDX
    m.w32((0x007bd7e4u), s.dx);
  }
  L0047034b: { // 0x47034b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047034d: { // 0x47034d: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470353: { // 0x470353: a3e8d77b00 MOV [0x007bd7e8],EAX
    m.w32((0x007bd7e8u), s.ax);
  }
  L00470358: { // 0x470358: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047035a: { // 0x47035a: 890decd77b00 MOV dword ptr [0x007bd7ec],ECX
    m.w32((0x007bd7ecu), s.cx);
  }
  L00470360: { // 0x470360: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470362: { // 0x470362: 891508d87b00 MOV dword ptr [0x007bd808],EDX
    m.w32((0x007bd808u), s.dx);
  }
  L00470368: { // 0x470368: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047036a: { // 0x47036a: a30cd87b00 MOV [0x007bd80c],EAX
    m.w32((0x007bd80cu), s.ax);
  }
  L0047036f: { // 0x47036f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470371: { // 0x470371: 890d10d87b00 MOV dword ptr [0x007bd810],ECX
    m.w32((0x007bd810u), s.cx);
  }
  L00470377: { // 0x470377: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470379: { // 0x470379: 891514d87b00 MOV dword ptr [0x007bd814],EDX
    m.w32((0x007bd814u), s.dx);
  }
  L0047037f: { // 0x47037f: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470381: { // 0x470381: a338d87b00 MOV [0x007bd838],EAX
    m.w32((0x007bd838u), s.ax);
  }
  L00470386: { // 0x470386: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470388: { // 0x470388: 890d3cd87b00 MOV dword ptr [0x007bd83c],ECX
    m.w32((0x007bd83cu), s.cx);
  }
  L0047038e: { // 0x47038e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470390: { // 0x470390: 891560d87b00 MOV dword ptr [0x007bd860],EDX
    m.w32((0x007bd860u), s.dx);
  }
  L00470396: { // 0x470396: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470398: { // 0x470398: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0047039a: { // 0x47039a: dd1d30d87b00 FSTP double ptr [0x007bd830]
    const auto address=(0x007bd830u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004703a0: { // 0x4703a0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004703a2: { // 0x4703a2: c705a0d77b0000000000 MOV dword ptr [0x007bd7a0],0x0
    m.w32((0x007bd7a0u), 0x00000000u);
  }
  L004703ac: { // 0x4703ac: c705a4d77b0000000000 MOV dword ptr [0x007bd7a4],0x0
    m.w32((0x007bd7a4u), 0x00000000u);
  }
  L004703b6: { // 0x4703b6: c705a8d77b0000000000 MOV dword ptr [0x007bd7a8],0x0
    m.w32((0x007bd7a8u), 0x00000000u);
  }
  L004703c0: { // 0x4703c0: c705acd77b0000000000 MOV dword ptr [0x007bd7ac],0x0
    m.w32((0x007bd7acu), 0x00000000u);
  }
  L004703ca: { // 0x4703ca: c705b0d77b0000000000 MOV dword ptr [0x007bd7b0],0x0
    m.w32((0x007bd7b0u), 0x00000000u);
  }
  L004703d4: { // 0x4703d4: c705b4d77b000000f03f MOV dword ptr [0x007bd7b4],0x3ff00000
    m.w32((0x007bd7b4u), 0x3ff00000u);
  }
  L004703de: { // 0x4703de: c705b8d77b0000000000 MOV dword ptr [0x007bd7b8],0x0
    m.w32((0x007bd7b8u), 0x00000000u);
  }
  L004703e8: { // 0x4703e8: c705bcd77b0000000000 MOV dword ptr [0x007bd7bc],0x0
    m.w32((0x007bd7bcu), 0x00000000u);
  }
  L004703f2: { // 0x4703f2: c705c8d77b0000000000 MOV dword ptr [0x007bd7c8],0x0
    m.w32((0x007bd7c8u), 0x00000000u);
  }
  L004703fc: { // 0x4703fc: c705ccd77b0000000000 MOV dword ptr [0x007bd7cc],0x0
    m.w32((0x007bd7ccu), 0x00000000u);
  }
  L00470406: { // 0x470406: c705d0d77b0000000000 MOV dword ptr [0x007bd7d0],0x0
    m.w32((0x007bd7d0u), 0x00000000u);
  }
  L00470410: { // 0x470410: c705d4d77b000000f0bf MOV dword ptr [0x007bd7d4],0xbff00000
    m.w32((0x007bd7d4u), 0xbff00000u);
  }
  L0047041a: { // 0x47041a: c705d8d77b0000000000 MOV dword ptr [0x007bd7d8],0x0
    m.w32((0x007bd7d8u), 0x00000000u);
  }
  L00470424: { // 0x470424: c705dcd77b0000000000 MOV dword ptr [0x007bd7dc],0x0
    m.w32((0x007bd7dcu), 0x00000000u);
  }
  L0047042e: { // 0x47042e: c705f0d77b0000000000 MOV dword ptr [0x007bd7f0],0x0
    m.w32((0x007bd7f0u), 0x00000000u);
  }
  L00470438: { // 0x470438: c705f4d77b0000000000 MOV dword ptr [0x007bd7f4],0x0
    m.w32((0x007bd7f4u), 0x00000000u);
  }
  L00470442: { // 0x470442: c705f8d77b0000000000 MOV dword ptr [0x007bd7f8],0x0
    m.w32((0x007bd7f8u), 0x00000000u);
  }
  L0047044c: { // 0x47044c: c705fcd77b0000000000 MOV dword ptr [0x007bd7fc],0x0
    m.w32((0x007bd7fcu), 0x00000000u);
  }
  L00470456: { // 0x470456: c70500d87b0000000000 MOV dword ptr [0x007bd800],0x0
    m.w32((0x007bd800u), 0x00000000u);
  }
  L00470460: { // 0x470460: c70504d87b000000f0bf MOV dword ptr [0x007bd804],0xbff00000
    m.w32((0x007bd804u), 0xbff00000u);
  }
  L0047046a: { // 0x47046a: c70518d87b0000000000 MOV dword ptr [0x007bd818],0x0
    m.w32((0x007bd818u), 0x00000000u);
  }
  L00470474: { // 0x470474: c7051cd87b0000000000 MOV dword ptr [0x007bd81c],0x0
    m.w32((0x007bd81cu), 0x00000000u);
  }
  L0047047e: { // 0x47047e: c70520d87b0000000000 MOV dword ptr [0x007bd820],0x0
    m.w32((0x007bd820u), 0x00000000u);
  }
  L00470488: { // 0x470488: c70524d87b000000f03f MOV dword ptr [0x007bd824],0x3ff00000
    m.w32((0x007bd824u), 0x3ff00000u);
  }
  L00470492: { // 0x470492: c70528d87b0000000000 MOV dword ptr [0x007bd828],0x0
    m.w32((0x007bd828u), 0x00000000u);
  }
  L0047049c: { // 0x47049c: c7052cd87b000000f03f MOV dword ptr [0x007bd82c],0x3ff00000
    m.w32((0x007bd82cu), 0x3ff00000u);
  }
  L004704a6: { // 0x4704a6: c70540d87b0000000000 MOV dword ptr [0x007bd840],0x0
    m.w32((0x007bd840u), 0x00000000u);
  }
  L004704b0: { // 0x4704b0: c70544d87b0000000000 MOV dword ptr [0x007bd844],0x0
    m.w32((0x007bd844u), 0x00000000u);
  }
  L004704ba: { // 0x4704ba: c70548d87b0000000000 MOV dword ptr [0x007bd848],0x0
    m.w32((0x007bd848u), 0x00000000u);
  }
  L004704c4: { // 0x4704c4: c7054cd87b000000f0bf MOV dword ptr [0x007bd84c],0xbff00000
    m.w32((0x007bd84cu), 0xbff00000u);
  }
  L004704ce: { // 0x4704ce: c70550d87b0000000000 MOV dword ptr [0x007bd850],0x0
    m.w32((0x007bd850u), 0x00000000u);
  }
  L004704d8: { // 0x4704d8: c70554d87b000000f03f MOV dword ptr [0x007bd854],0x3ff00000
    m.w32((0x007bd854u), 0x3ff00000u);
  }
  L004704e2: { // 0x4704e2: c70558d87b0000000000 MOV dword ptr [0x007bd858],0x0
    m.w32((0x007bd858u), 0x00000000u);
  }
  L004704ec: { // 0x4704ec: c7055cd87b0000000000 MOV dword ptr [0x007bd85c],0x0
    m.w32((0x007bd85cu), 0x00000000u);
  }
  L004704f6: { // 0x4704f6: a364d87b00 MOV [0x007bd864],EAX
    m.w32((0x007bd864u), s.ax);
  }
  L004704fb: { // 0x4704fb: c70568d87b0000000000 MOV dword ptr [0x007bd868],0x0
    m.w32((0x007bd868u), 0x00000000u);
  }
  L00470505: { // 0x470505: c7056cd87b0000000000 MOV dword ptr [0x007bd86c],0x0
    m.w32((0x007bd86cu), 0x00000000u);
  }
  L0047050f: { // 0x47050f: c70570d87b0000000000 MOV dword ptr [0x007bd870],0x0
    m.w32((0x007bd870u), 0x00000000u);
  }
  L00470519: { // 0x470519: c70574d87b000000f0bf MOV dword ptr [0x007bd874],0xbff00000
    m.w32((0x007bd874u), 0xbff00000u);
  }
  L00470523: { // 0x470523: c70578d87b0000000000 MOV dword ptr [0x007bd878],0x0
    m.w32((0x007bd878u), 0x00000000u);
  }
  L0047052d: { // 0x47052d: c7057cd87b000000f0bf MOV dword ptr [0x007bd87c],0xbff00000
    m.w32((0x007bd87cu), 0xbff00000u);
  }
  L00470537: { // 0x470537: 890d80d87b00 MOV dword ptr [0x007bd880],ECX
    m.w32((0x007bd880u), s.cx);
  }
  L0047053d: { // 0x47053d: 891584d87b00 MOV dword ptr [0x007bd884],EDX
    m.w32((0x007bd884u), s.dx);
  }
  L00470543: { // 0x470543: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470545: { // 0x470545: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470547: { // 0x470547: a388d87b00 MOV [0x007bd888],EAX
    m.w32((0x007bd888u), s.ax);
  }
  L0047054c: { // 0x47054c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047054e: { // 0x47054e: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470554: { // 0x470554: 890d8cd87b00 MOV dword ptr [0x007bd88c],ECX
    m.w32((0x007bd88cu), s.cx);
  }
  L0047055a: { // 0x47055a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047055c: { // 0x47055c: 8915b0d87b00 MOV dword ptr [0x007bd8b0],EDX
    m.w32((0x007bd8b0u), s.dx);
  }
  L00470562: { // 0x470562: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470564: { // 0x470564: a3b4d87b00 MOV [0x007bd8b4],EAX
    m.w32((0x007bd8b4u), s.ax);
  }
  L00470569: { // 0x470569: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047056b: { // 0x47056b: 890dd8d87b00 MOV dword ptr [0x007bd8d8],ECX
    m.w32((0x007bd8d8u), s.cx);
  }
  L00470571: { // 0x470571: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470573: { // 0x470573: 8915dcd87b00 MOV dword ptr [0x007bd8dc],EDX
    m.w32((0x007bd8dcu), s.dx);
  }
  L00470579: { // 0x470579: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047057b: { // 0x47057b: a3f8d87b00 MOV [0x007bd8f8],EAX
    m.w32((0x007bd8f8u), s.ax);
  }
  L00470580: { // 0x470580: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470582: { // 0x470582: 890dfcd87b00 MOV dword ptr [0x007bd8fc],ECX
    m.w32((0x007bd8fcu), s.cx);
  }
  L00470588: { // 0x470588: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047058a: { // 0x47058a: 891500d97b00 MOV dword ptr [0x007bd900],EDX
    m.w32((0x007bd900u), s.dx);
  }
  L00470590: { // 0x470590: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470592: { // 0x470592: a304d97b00 MOV [0x007bd904],EAX
    m.w32((0x007bd904u), s.ax);
  }
  L00470597: { // 0x470597: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470599: { // 0x470599: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047059b: { // 0x47059b: 890d28d97b00 MOV dword ptr [0x007bd928],ECX
    m.w32((0x007bd928u), s.cx);
  }
  L004705a1: { // 0x4705a1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705a3: { // 0x4705a3: 89152cd97b00 MOV dword ptr [0x007bd92c],EDX
    m.w32((0x007bd92cu), s.dx);
  }
  L004705a9: { // 0x4705a9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004705ab: { // 0x4705ab: a348d97b00 MOV [0x007bd948],EAX
    m.w32((0x007bd948u), s.ax);
  }
  L004705b0: { // 0x4705b0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004705b2: { // 0x4705b2: dd1520d97b00 FST double ptr [0x007bd920]
    const auto address=(0x007bd920u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705b8: { // 0x4705b8: dd1578d97b00 FST double ptr [0x007bd978]
    const auto address=(0x007bd978u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705be: { // 0x4705be: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705c0: { // 0x4705c0: c70590d87b0000000000 MOV dword ptr [0x007bd890],0x0
    m.w32((0x007bd890u), 0x00000000u);
  }
  L004705ca: { // 0x4705ca: c70594d87b0000000000 MOV dword ptr [0x007bd894],0x0
    m.w32((0x007bd894u), 0x00000000u);
  }
  L004705d4: { // 0x4705d4: c70598d87b0000000000 MOV dword ptr [0x007bd898],0x0
    m.w32((0x007bd898u), 0x00000000u);
  }
  L004705de: { // 0x4705de: c7059cd87b000000f03f MOV dword ptr [0x007bd89c],0x3ff00000
    m.w32((0x007bd89cu), 0x3ff00000u);
  }
  L004705e8: { // 0x4705e8: c705a0d87b0000000000 MOV dword ptr [0x007bd8a0],0x0
    m.w32((0x007bd8a0u), 0x00000000u);
  }
  L004705f2: { // 0x4705f2: c705a4d87b000000f0bf MOV dword ptr [0x007bd8a4],0xbff00000
    m.w32((0x007bd8a4u), 0xbff00000u);
  }
  L004705fc: { // 0x4705fc: c705a8d87b0000000000 MOV dword ptr [0x007bd8a8],0x0
    m.w32((0x007bd8a8u), 0x00000000u);
  }
  L00470606: { // 0x470606: c705acd87b0000000000 MOV dword ptr [0x007bd8ac],0x0
    m.w32((0x007bd8acu), 0x00000000u);
  }
  L00470610: { // 0x470610: c705b8d87b0000000000 MOV dword ptr [0x007bd8b8],0x0
    m.w32((0x007bd8b8u), 0x00000000u);
  }
  L0047061a: { // 0x47061a: c705bcd87b0000000000 MOV dword ptr [0x007bd8bc],0x0
    m.w32((0x007bd8bcu), 0x00000000u);
  }
  L00470624: { // 0x470624: c705c0d87b0000000000 MOV dword ptr [0x007bd8c0],0x0
    m.w32((0x007bd8c0u), 0x00000000u);
  }
  L0047062e: { // 0x47062e: c705c4d87b000000f03f MOV dword ptr [0x007bd8c4],0x3ff00000
    m.w32((0x007bd8c4u), 0x3ff00000u);
  }
  L00470638: { // 0x470638: c705c8d87b0000000000 MOV dword ptr [0x007bd8c8],0x0
    m.w32((0x007bd8c8u), 0x00000000u);
  }
  L00470642: { // 0x470642: c705ccd87b000000f03f MOV dword ptr [0x007bd8cc],0x3ff00000
    m.w32((0x007bd8ccu), 0x3ff00000u);
  }
  L0047064c: { // 0x47064c: c705d0d87b0000000000 MOV dword ptr [0x007bd8d0],0x0
    m.w32((0x007bd8d0u), 0x00000000u);
  }
  L00470656: { // 0x470656: c705d4d87b0000000000 MOV dword ptr [0x007bd8d4],0x0
    m.w32((0x007bd8d4u), 0x00000000u);
  }
  L00470660: { // 0x470660: c705e0d87b0000000000 MOV dword ptr [0x007bd8e0],0x0
    m.w32((0x007bd8e0u), 0x00000000u);
  }
  L0047066a: { // 0x47066a: c705e4d87b0000000000 MOV dword ptr [0x007bd8e4],0x0
    m.w32((0x007bd8e4u), 0x00000000u);
  }
  L00470674: { // 0x470674: c705e8d87b0000000000 MOV dword ptr [0x007bd8e8],0x0
    m.w32((0x007bd8e8u), 0x00000000u);
  }
  L0047067e: { // 0x47067e: c705ecd87b000000f0bf MOV dword ptr [0x007bd8ec],0xbff00000
    m.w32((0x007bd8ecu), 0xbff00000u);
  }
  L00470688: { // 0x470688: c705f0d87b0000000000 MOV dword ptr [0x007bd8f0],0x0
    m.w32((0x007bd8f0u), 0x00000000u);
  }
  L00470692: { // 0x470692: c705f4d87b000000f03f MOV dword ptr [0x007bd8f4],0x3ff00000
    m.w32((0x007bd8f4u), 0x3ff00000u);
  }
  L0047069c: { // 0x47069c: c70508d97b0000000000 MOV dword ptr [0x007bd908],0x0
    m.w32((0x007bd908u), 0x00000000u);
  }
  L004706a6: { // 0x4706a6: c7050cd97b0000000000 MOV dword ptr [0x007bd90c],0x0
    m.w32((0x007bd90cu), 0x00000000u);
  }
  L004706b0: { // 0x4706b0: c70510d97b0000000000 MOV dword ptr [0x007bd910],0x0
    m.w32((0x007bd910u), 0x00000000u);
  }
  L004706ba: { // 0x4706ba: c70514d97b000000f0bf MOV dword ptr [0x007bd914],0xbff00000
    m.w32((0x007bd914u), 0xbff00000u);
  }
  L004706c4: { // 0x4706c4: c70518d97b0000000000 MOV dword ptr [0x007bd918],0x0
    m.w32((0x007bd918u), 0x00000000u);
  }
  L004706ce: { // 0x4706ce: c7051cd97b000000f0bf MOV dword ptr [0x007bd91c],0xbff00000
    m.w32((0x007bd91cu), 0xbff00000u);
  }
  L004706d8: { // 0x4706d8: c70530d97b0000000000 MOV dword ptr [0x007bd930],0x0
    m.w32((0x007bd930u), 0x00000000u);
  }
  L004706e2: { // 0x4706e2: c70534d97b0000000000 MOV dword ptr [0x007bd934],0x0
    m.w32((0x007bd934u), 0x00000000u);
  }
  L004706ec: { // 0x4706ec: c70538d97b0000000000 MOV dword ptr [0x007bd938],0x0
    m.w32((0x007bd938u), 0x00000000u);
  }
  L004706f6: { // 0x4706f6: c7053cd97b000000f03f MOV dword ptr [0x007bd93c],0x3ff00000
    m.w32((0x007bd93cu), 0x3ff00000u);
  }
  L00470700: { // 0x470700: c70540d97b0000000000 MOV dword ptr [0x007bd940],0x0
    m.w32((0x007bd940u), 0x00000000u);
  }
  L0047070a: { // 0x47070a: c70544d97b000000f0bf MOV dword ptr [0x007bd944],0xbff00000
    m.w32((0x007bd944u), 0xbff00000u);
  }
  L00470714: { // 0x470714: 890d4cd97b00 MOV dword ptr [0x007bd94c],ECX
    m.w32((0x007bd94cu), s.cx);
  }
  L0047071a: { // 0x47071a: 891550d97b00 MOV dword ptr [0x007bd950],EDX
    m.w32((0x007bd950u), s.dx);
  }
  L00470720: { // 0x470720: a354d97b00 MOV [0x007bd954],EAX
    m.w32((0x007bd954u), s.ax);
  }
  L00470725: { // 0x470725: c70558d97b0000000000 MOV dword ptr [0x007bd958],0x0
    m.w32((0x007bd958u), 0x00000000u);
  }
  L0047072f: { // 0x47072f: c7055cd97b0000000000 MOV dword ptr [0x007bd95c],0x0
    m.w32((0x007bd95cu), 0x00000000u);
  }
  L00470739: { // 0x470739: c70560d97b0000000000 MOV dword ptr [0x007bd960],0x0
    m.w32((0x007bd960u), 0x00000000u);
  }
  L00470743: { // 0x470743: c70564d97b000000f03f MOV dword ptr [0x007bd964],0x3ff00000
    m.w32((0x007bd964u), 0x3ff00000u);
  }
  L0047074d: { // 0x47074d: c70568d97b0000000000 MOV dword ptr [0x007bd968],0x0
    m.w32((0x007bd968u), 0x00000000u);
  }
  L00470757: { // 0x470757: c7056cd97b000000f03f MOV dword ptr [0x007bd96c],0x3ff00000
    m.w32((0x007bd96cu), 0x3ff00000u);
  }
  L00470761: { // 0x470761: c70570d97b0000000000 MOV dword ptr [0x007bd970],0x0
    m.w32((0x007bd970u), 0x00000000u);
  }
  L0047076b: { // 0x47076b: c70574d97b0000000000 MOV dword ptr [0x007bd974],0x0
    m.w32((0x007bd974u), 0x00000000u);
  }
  L00470775: { // 0x470775: c70580d97b0000000000 MOV dword ptr [0x007bd980],0x0
    m.w32((0x007bd980u), 0x00000000u);
  }
  L0047077f: { // 0x47077f: c70584d97b0000000000 MOV dword ptr [0x007bd984],0x0
    m.w32((0x007bd984u), 0x00000000u);
  }
  L00470789: { // 0x470789: c70588d97b0000000000 MOV dword ptr [0x007bd988],0x0
    m.w32((0x007bd988u), 0x00000000u);
  }
  L00470793: { // 0x470793: dd15a0d97b00 FST double ptr [0x007bd9a0]
    const auto address=(0x007bd9a0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470799: { // 0x470799: dd15c0d97b00 FST double ptr [0x007bd9c0]
    const auto address=(0x007bd9c0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047079f: { // 0x47079f: dd15c8d97b00 FST double ptr [0x007bd9c8]
    const auto address=(0x007bd9c8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707a5: { // 0x4707a5: dd1df0d97b00 FSTP double ptr [0x007bd9f0]
    const auto address=(0x007bd9f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004707ab: { // 0x4707ab: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707b1: { // 0x4707b1: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L004707b7: { // 0x4707b7: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707b9: { // 0x4707b9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707bb: { // 0x4707bb: 890d98d97b00 MOV dword ptr [0x007bd998],ECX
    m.w32((0x007bd998u), s.cx);
  }
  L004707c1: { // 0x4707c1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707c3: { // 0x4707c3: 89159cd97b00 MOV dword ptr [0x007bd99c],EDX
    m.w32((0x007bd99cu), s.dx);
  }
  L004707c9: { // 0x4707c9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707cb: { // 0x4707cb: dd1518da7b00 FST double ptr [0x007bda18]
    const auto address=(0x007bda18u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d1: { // 0x4707d1: dd1520da7b00 FST double ptr [0x007bda20]
    const auto address=(0x007bda20u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d7: { // 0x4707d7: dd1540da7b00 FST double ptr [0x007bda40]
    const auto address=(0x007bda40u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707dd: { // 0x4707dd: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707e3: { // 0x4707e3: dc0db0797800 FMUL double ptr [0x007879b0]
    const auto address=(0x007879b0u);
    s.fp.multiply64(read64(m,address));
  }
  L004707e9: { // 0x4707e9: a3e8d97b00 MOV [0x007bd9e8],EAX
    m.w32((0x007bd9e8u), s.ax);
  }
  L004707ee: { // 0x4707ee: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707f0: { // 0x4707f0: 890decd97b00 MOV dword ptr [0x007bd9ec],ECX
    m.w32((0x007bd9ecu), s.cx);
  }
  L004707f6: { // 0x4707f6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707f8: { // 0x4707f8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707fa: { // 0x4707fa: 891538da7b00 MOV dword ptr [0x007bda38],EDX
    m.w32((0x007bda38u), s.dx);
  }
  L00470800: { // 0x470800: dd542408 FST double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470804: { // 0x470804: dd1d48da7b00 FSTP double ptr [0x007bda48]
    const auto address=(0x007bda48u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047080a: { // 0x47080a: a33cda7b00 MOV [0x007bda3c],EAX
    m.w32((0x007bda3cu), s.ax);
  }
  L0047080f: { // 0x47080f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470811: { // 0x470811: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00470815: { // 0x470815: 890d88da7b00 MOV dword ptr [0x007bda88],ECX
    m.w32((0x007bda88u), s.cx);
  }
  L0047081b: { // 0x47081b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0047081f: { // 0x47081f: c7058cd97b000000f0bf MOV dword ptr [0x007bd98c],0xbff00000
    m.w32((0x007bd98cu), 0xbff00000u);
  }
  L00470829: { // 0x470829: dd1568da7b00 FST double ptr [0x007bda68]
    const auto address=(0x007bda68u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047082f: { // 0x47082f: dd1570da7b00 FST double ptr [0x007bda70]
    const auto address=(0x007bda70u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470835: { // 0x470835: dd1d90da7b00 FSTP double ptr [0x007bda90]
    const auto address=(0x007bda90u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047083b: { // 0x47083b: c70590d97b0000000000 MOV dword ptr [0x007bd990],0x0
    m.w32((0x007bd990u), 0x00000000u);
  }
  L00470845: { // 0x470845: c70594d97b000000f03f MOV dword ptr [0x007bd994],0x3ff00000
    m.w32((0x007bd994u), 0x3ff00000u);
  }
  L0047084f: { // 0x47084f: c705a8d97b0000000000 MOV dword ptr [0x007bd9a8],0x0
    m.w32((0x007bd9a8u), 0x00000000u);
  }
  L00470859: { // 0x470859: c705acd97b0000000000 MOV dword ptr [0x007bd9ac],0x0
    m.w32((0x007bd9acu), 0x00000000u);
  }
  L00470863: { // 0x470863: c705b0d97b0000000000 MOV dword ptr [0x007bd9b0],0x0
    m.w32((0x007bd9b0u), 0x00000000u);
  }
  L0047086d: { // 0x47086d: c705b4d97b000000f0bf MOV dword ptr [0x007bd9b4],0xbff00000
    m.w32((0x007bd9b4u), 0xbff00000u);
  }
  L00470877: { // 0x470877: c705b8d97b0000000000 MOV dword ptr [0x007bd9b8],0x0
    m.w32((0x007bd9b8u), 0x00000000u);
  }
  L00470881: { // 0x470881: c705bcd97b000000f0bf MOV dword ptr [0x007bd9bc],0xbff00000
    m.w32((0x007bd9bcu), 0xbff00000u);
  }
  L0047088b: { // 0x47088b: c705d0d97b0000000000 MOV dword ptr [0x007bd9d0],0x0
    m.w32((0x007bd9d0u), 0x00000000u);
  }
  L00470895: { // 0x470895: c705d4d97b0000000000 MOV dword ptr [0x007bd9d4],0x0
    m.w32((0x007bd9d4u), 0x00000000u);
  }
  L0047089f: { // 0x47089f: c705d8d97b0000000000 MOV dword ptr [0x007bd9d8],0x0
    m.w32((0x007bd9d8u), 0x00000000u);
  }
  L004708a9: { // 0x4708a9: c705dcd97b000000f03f MOV dword ptr [0x007bd9dc],0x3ff00000
    m.w32((0x007bd9dcu), 0x3ff00000u);
  }
  L004708b3: { // 0x4708b3: c705e0d97b0000000000 MOV dword ptr [0x007bd9e0],0x0
    m.w32((0x007bd9e0u), 0x00000000u);
  }
  L004708bd: { // 0x4708bd: c705e4d97b000000f0bf MOV dword ptr [0x007bd9e4],0xbff00000
    m.w32((0x007bd9e4u), 0xbff00000u);
  }
  L004708c7: { // 0x4708c7: c705f8d97b0000000000 MOV dword ptr [0x007bd9f8],0x0
    m.w32((0x007bd9f8u), 0x00000000u);
  }
  L004708d1: { // 0x4708d1: c705fcd97b0000000000 MOV dword ptr [0x007bd9fc],0x0
    m.w32((0x007bd9fcu), 0x00000000u);
  }
  L004708db: { // 0x4708db: c70500da7b0000000000 MOV dword ptr [0x007bda00],0x0
    m.w32((0x007bda00u), 0x00000000u);
  }
  L004708e5: { // 0x4708e5: c70504da7b0000000000 MOV dword ptr [0x007bda04],0x0
    m.w32((0x007bda04u), 0x00000000u);
  }
  L004708ef: { // 0x4708ef: c70508da7b0000000000 MOV dword ptr [0x007bda08],0x0
    m.w32((0x007bda08u), 0x00000000u);
  }
  L004708f9: { // 0x4708f9: c7050cda7b0000000000 MOV dword ptr [0x007bda0c],0x0
    m.w32((0x007bda0cu), 0x00000000u);
  }
  L00470903: { // 0x470903: c70510da7b0000000000 MOV dword ptr [0x007bda10],0x0
    m.w32((0x007bda10u), 0x00000000u);
  }
  L0047090d: { // 0x47090d: c70514da7b0000000000 MOV dword ptr [0x007bda14],0x0
    m.w32((0x007bda14u), 0x00000000u);
  }
  L00470917: { // 0x470917: c70528da7b0000000000 MOV dword ptr [0x007bda28],0x0
    m.w32((0x007bda28u), 0x00000000u);
  }
  L00470921: { // 0x470921: c7052cda7b0000000000 MOV dword ptr [0x007bda2c],0x0
    m.w32((0x007bda2cu), 0x00000000u);
  }
  L0047092b: { // 0x47092b: c70530da7b0000000000 MOV dword ptr [0x007bda30],0x0
    m.w32((0x007bda30u), 0x00000000u);
  }
  L00470935: { // 0x470935: c70534da7b0000000000 MOV dword ptr [0x007bda34],0x0
    m.w32((0x007bda34u), 0x00000000u);
  }
  L0047093f: { // 0x47093f: c70550da7b0000000000 MOV dword ptr [0x007bda50],0x0
    m.w32((0x007bda50u), 0x00000000u);
  }
  L00470949: { // 0x470949: c70554da7b0000000000 MOV dword ptr [0x007bda54],0x0
    m.w32((0x007bda54u), 0x00000000u);
  }
  L00470953: { // 0x470953: c70558da7b0000000000 MOV dword ptr [0x007bda58],0x0
    m.w32((0x007bda58u), 0x00000000u);
  }
  L0047095d: { // 0x47095d: c7055cda7b0000000000 MOV dword ptr [0x007bda5c],0x0
    m.w32((0x007bda5cu), 0x00000000u);
  }
  L00470967: { // 0x470967: c70560da7b0000000000 MOV dword ptr [0x007bda60],0x0
    m.w32((0x007bda60u), 0x00000000u);
  }
  L00470971: { // 0x470971: c70564da7b0000000000 MOV dword ptr [0x007bda64],0x0
    m.w32((0x007bda64u), 0x00000000u);
  }
  L0047097b: { // 0x47097b: c70578da7b0000000000 MOV dword ptr [0x007bda78],0x0
    m.w32((0x007bda78u), 0x00000000u);
  }
  L00470985: { // 0x470985: c7057cda7b0000000000 MOV dword ptr [0x007bda7c],0x0
    m.w32((0x007bda7cu), 0x00000000u);
  }
  L0047098f: { // 0x47098f: c70580da7b0000000000 MOV dword ptr [0x007bda80],0x0
    m.w32((0x007bda80u), 0x00000000u);
  }
  L00470999: { // 0x470999: c70584da7b0000000000 MOV dword ptr [0x007bda84],0x0
    m.w32((0x007bda84u), 0x00000000u);
  }
  L004709a3: { // 0x4709a3: 89158cda7b00 MOV dword ptr [0x007bda8c],EDX
    m.w32((0x007bda8cu), s.dx);
  }
  L004709a9: { // 0x4709a9: a398da7b00 MOV [0x007bda98],EAX
    m.w32((0x007bda98u), s.ax);
  }
  L004709ae: { // 0x4709ae: 890d9cda7b00 MOV dword ptr [0x007bda9c],ECX
    m.w32((0x007bda9cu), s.cx);
  }
  L004709b4: { // 0x4709b4: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004709bb: { // 0x4709bb: 0faf15808f8300 IMUL EDX,dword ptr [0x00838f80]
    s.dx = integer::imul(s.dx,m.r32((0x00838f80u)),32,flags);
  }
  L004709c2: { // 0x4709c2: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L004709c6: { // 0x4709c6: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L004709ca: { // 0x4709ca: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004709d0: { // 0x4709d0: e87ba02f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655573u); flags=s.arithmetic_flags;
  }
  L004709d5: { // 0x4709d5: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L004709db: { // 0x4709db: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004709df: { // 0x4709df: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004709e1: { // 0x4709e1: 0f868d000000 JBE 0x00470a74
    if(integer::condition("JBE",flags)) goto L00470a74;
  }
  L004709e7: { // 0x4709e7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L004709ea: { // 0x4709ea: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004709f0: { // 0x4709f0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004709f1: { // 0x4709f1: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004709f4: { // 0x4709f4: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004709f6: { // 0x4709f6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004709fc: { // 0x4709fc: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L004709ff: { // 0x4709ff: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L00470a03: { // 0x470a03: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00470a08: { // 0x470a08: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a0c: { // 0x470a0c: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L00470a0f: { // 0x470a0f: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00470a13: { // 0x470a13: dc8988d77b00 FMUL double ptr [ECX + 0x7bd788]
    const auto address=(s.cx+0x007bd788u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a19: { // 0x470a19: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a1f: { // 0x470a1f: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a23: { // 0x470a23: dc8980d77b00 FMUL double ptr [ECX + 0x7bd780]
    const auto address=(s.cx+0x007bd780u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a29: { // 0x470a29: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a2f: { // 0x470a2f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00470a31: { // 0x470a31: dc8190d77b00 FADD double ptr [ECX + 0x7bd790]
    const auto address=(s.cx+0x007bd790u);
    s.fp.add64(read64(m,address));
  }
  L00470a37: { // 0x470a37: dc81a0d77b00 FADD double ptr [ECX + 0x7bd7a0]
    const auto address=(s.cx+0x007bd7a0u);
    s.fp.add64(read64(m,address));
  }
  L00470a3d: { // 0x470a3d: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a43: { // 0x470a43: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a45: { // 0x470a45: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00470a48: { // 0x470a48: 7408 JZ 0x00470a52
    if(integer::condition("JZ",flags)) goto L00470a52;
  }
  L00470a4a: { // 0x470a4a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a4c: { // 0x470a4c: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L00470a52: { // 0x470a52: dc9198d77b00 FCOM double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a58: { // 0x470a58: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a5a: { // 0x470a5a: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00470a5d: { // 0x470a5d: 7508 JNZ 0x00470a67
    if(integer::condition("JNZ",flags)) goto L00470a67;
  }
  L00470a5f: { // 0x470a5f: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a61: { // 0x470a61: dd8198d77b00 FLD double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    s.fp.load64(read64(m,address));
  }
  L00470a67: { // 0x470a67: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a6b: { // 0x470a6b: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00470a6d: { // 0x470a6d: e8de9f2f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655730u); flags=s.arithmetic_flags;
  }
  L00470a72: { // 0x470a72: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a74: { // 0x470a74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00470a75: { // 0x470a75: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00470a77: { // 0x470a77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00470a78: { // 0x470a78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00075fd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00475fd0: { // 0x475fd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00475fd3: { // 0x475fd3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00475fd4: { // 0x475fd4: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00475fd6: { // 0x475fd6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00475fd7: { // 0x475fd7: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L00475fda: { // 0x475fda: 81e7ff000000 AND EDI,0xff
    s.di = integer::logical((s.di)&(0x000000ffu),32,flags);
  }
  L00475fe0: { // 0x475fe0: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L00475fe6: { // 0x475fe6: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00475fe9: { // 0x475fe9: 8d4f80 LEA ECX,[EDI + -0x80]
    s.cx = (s.di-0x00000080u);
  }
  L00475fec: { // 0x475fec: 8d4680 LEA EAX,[ESI + -0x80]
    s.ax = (s.si-0x00000080u);
  }
  L00475fef: { // 0x475fef: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00475ff3: { // 0x475ff3: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00475ff7: { // 0x475ff7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00475ffb: { // 0x475ffb: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00475fff: { // 0x475fff: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00476001: { // 0x476001: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00476003: { // 0x476003: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00476005: { // 0x476005: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00476007: { // 0x476007: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00476009: { // 0x476009: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047600c: { // 0x47600c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0047600e: { // 0x47600e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00476010: { // 0x476010: e86b400400 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4677653u); flags=s.arithmetic_flags;
  }
  L00476015: { // 0x476015: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00476018: { // 0x476018: e8334a2f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4677661u); flags=s.arithmetic_flags;
  }
  L0047601d: { // 0x47601d: 83f83c CMP EAX,0x3c
    (void)integer::sub(s.ax,0x0000003cu,32,flags);
  }
  L00476020: { // 0x476020: 7d08 JGE 0x0047602a
    if(integer::condition("JGE",flags)) goto L0047602a;
  }
  L00476022: { // 0x476022: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00476023: { // 0x476023: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00476025: { // 0x476025: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00476026: { // 0x476026: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00476029: { // 0x476029: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047602a: { // 0x47602a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0047602c: { // 0x47602c: 81fe80000000 CMP ESI,0x80
    (void)integer::sub(s.si,0x00000080u,32,flags);
  }
  L00476032: { // 0x476032: 7e05 JLE 0x00476039
    if(integer::condition("JLE",flags)) goto L00476039;
  }
  L00476034: { // 0x476034: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00476039: { // 0x476039: 81ff80000000 CMP EDI,0x80
    (void)integer::sub(s.di,0x00000080u,32,flags);
  }
  L0047603f: { // 0x47603f: 7e02 JLE 0x00476043
    if(integer::condition("JLE",flags)) goto L00476043;
  }
  L00476041: { // 0x476041: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L00476043: { // 0x476043: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00476045: { // 0x476045: 7506 JNZ 0x0047604d
    if(integer::condition("JNZ",flags)) goto L0047604d;
  }
  L00476047: { // 0x476047: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00476048: { // 0x476048: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00476049: { // 0x476049: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047604c: { // 0x47604c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047604d: { // 0x47604d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047604e: { // 0x47604e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0047604f: { // 0x47604f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00476050: { // 0x476050: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00476053: { // 0x476053: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000766c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004766c0: { // 0x004766c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004766c1: { // 0x004766c1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L004766c5: { // 0x004766c5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004766c7: { // 0x004766c7: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  L004766ca: { // 0x004766ca: 7346 JNC 0x00476712
    if(integer::condition("JNC",flags)) goto L00476712;
  }
  L004766cc: { // 0x004766cc: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L004766cf: { // 0x004766cf: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L004766d2: { // 0x004766d2: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L004766d6: { // 0x004766d6: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L004766dd: { // 0x004766dd: 668b1495a09d8300 MOV DX,word ptr [EDX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L004766e5: { // 0x004766e5: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L004766e9: { // 0x004766e9: 6603442402 ADD AX,word ptr [ESP + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000002u)),16,flags));
  }
  L004766ee: { // 0x004766ee: 6603d1 ADD DX,CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L004766f1: { // 0x004766f1: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L004766f6: { // 0x004766f6: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L004766fa: { // 0x004766fa: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L004766ff: { // 0x004766ff: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00476703: { // 0x00476703: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L00476707: { // 0x00476707: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00476708: { // 0x00476708: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047670d: { // 0x0047670d: e8eeed0c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4679442u); flags=s.arithmetic_flags;
  }
  L00476712: { // 0x00476712: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00476713: { // 0x00476713: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000767a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004767a0: { // 0x4767a0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004767a3: { // 0x4767a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004767a4: { // 0x4767a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004767a5: { // 0x4767a5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004767a7: { // 0x4767a7: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  L004767aa: { // 0x4767aa: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004767ad: { // 0x4767ad: 0f84f5000000 JZ 0x004768a8
    if(integer::condition("JZ",flags)) goto L004768a8;
  }
  L004767b3: { // 0x4767b3: e878df1500 CALL 0x005d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4679608u); flags=s.arithmetic_flags;
  }
  L004767b8: { // 0x4767b8: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004767ba: { // 0x4767ba: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L004767bd: { // 0x4767bd: 0f84e5000000 JZ 0x004768a8
    if(integer::condition("JZ",flags)) goto L004768a8;
  }
  L004767c3: { // 0x4767c3: a13c86aa00 MOV EAX,[0x00aa863c]
    s.ax = m.r32((0x00aa863cu));
  }
  L004767c8: { // 0x4767c8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004767c9: { // 0x4767c9: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004767cb: { // 0x4767cb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004767cc: { // 0x4767cc: 8b0498 MOV EAX,dword ptr [EAX + EBX*0x4]
    s.ax = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L004767cf: { // 0x4767cf: 8b88b8000000 MOV ECX,dword ptr [EAX + 0xb8]
    s.cx = m.r32((s.ax+0x000000b8u));
  }
  L004767d5: { // 0x4767d5: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004767d9: { // 0x4767d9: 8a4c241c MOV CL,byte ptr [ESP + 0x1c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000001cu)));
  }
  L004767dd: { // 0x4767dd: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004767df: { // 0x4767df: 742e JZ 0x0047680f
    if(integer::condition("JZ",flags)) goto L0047680f;
  }
  L004767e1: { // 0x4767e1: 8b88e0000000 MOV ECX,dword ptr [EAX + 0xe0]
    s.cx = m.r32((s.ax+0x000000e0u));
  }
  L004767e7: { // 0x4767e7: 8b80e8000000 MOV EAX,dword ptr [EAX + 0xe8]
    s.ax = m.r32((s.ax+0x000000e8u));
  }
  L004767ed: { // 0x4767ed: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L004767f0: { // 0x4767f0: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L004767f3: { // 0x4767f3: 8d84d178fdffff LEA EAX,[ECX + EDX*0x8 + 0xfffffd78]
    s.ax = (s.cx+(s.dx * 0x00000008u)+0xfffffd78u);
  }
  L004767fa: { // 0x4767fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004767fb: { // 0x4767fb: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00476800: { // 0x476800: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00476801: { // 0x476801: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00476807: { // 0x476807: e834961b00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4679692u); flags=s.arithmetic_flags;
  }
  L0047680c: { // 0x47680c: 894644 MOV dword ptr [ESI + 0x44],EAX
    m.w32((s.si+0x00000044u), s.ax);
  }
  L0047680f: { // 0x47680f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00476811: { // 0x476811: 83ff08 CMP EDI,0x8
    (void)integer::sub(s.di,0x00000008u,32,flags);
  }
  L00476814: { // 0x476814: 7204 JC 0x0047681a
    if(integer::condition("JC",flags)) goto L0047681a;
  }
  L00476816: { // 0x476816: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00476818: { // 0x476818: eb48 JMP 0x00476862
    goto L00476862;
  }
  L0047681a: { // 0x47681a: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L0047681d: { // 0x47681d: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0047681f: { // 0x47681f: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00476822: { // 0x476822: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00476826: { // 0x476826: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L0047682d: { // 0x47682d: 668b1495a09d8300 MOV DX,word ptr [EDX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L00476835: { // 0x476835: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L00476839: { // 0x476839: 6603442412 ADD AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L0047683e: { // 0x47683e: 6603d1 ADD DX,CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L00476841: { // 0x476841: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L00476846: { // 0x476846: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0047684a: { // 0x47684a: 668944241e MOV word ptr [ESP + 0x1e],AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L0047684f: { // 0x47684f: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00476853: { // 0x476853: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00476857: { // 0x476857: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00476858: { // 0x476858: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047685d: { // 0x47685d: e89eec0c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4679778u); flags=s.arithmetic_flags;
  }
  L00476862: { // 0x476862: 8b4844 MOV ECX,dword ptr [EAX + 0x44]
    s.cx = m.r32((s.ax+0x00000044u));
  }
  L00476865: { // 0x476865: e8c6de1500 CALL 0x005d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4679786u); flags=s.arithmetic_flags;
  }
  L0047686a: { // 0x47686a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0047686c: { // 0x47686c: 7501 JNZ 0x0047686f
    if(integer::condition("JNZ",flags)) goto L0047686f;
  }
  L0047686e: { // 0x47686e: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0047686f: { // 0x47686f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00476870: { // 0x476870: 83ff08 CMP EDI,0x8
    (void)integer::sub(s.di,0x00000008u,32,flags);
  }
  L00476873: { // 0x476873: 7c9f JL 0x00476814
    if(integer::condition("JL",flags)) goto L00476814;
  }
  L00476875: { // 0x476875: a13c86aa00 MOV EAX,[0x00aa863c]
    s.ax = m.r32((0x00aa863cu));
  }
  L0047687a: { // 0x47687a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047687b: { // 0x47687b: 8b0c98 MOV ECX,dword ptr [EAX + EBX*0x4]
    s.cx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L0047687e: { // 0x47687e: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00476880: { // 0x476880: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00476881: { // 0x476881: f7b9e4000000 IDIV dword ptr [ECX + 0xe4]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.cx+0x000000e4u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00476887: { // 0x476887: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00476888: { // 0x476888: 8a0495a8db7b00 MOV AL,byte ptr [EDX*0x4 + 0x7bdba8]
    s.ax = with_al(s.ax, m.r8(((s.dx * 0x00000004u)+0x007bdba8u)));
  }
  L0047688f: { // 0x47688f: 88861e010000 MOV byte ptr [ESI + 0x11e],AL
    m.w8((s.si+0x0000011eu), (s.ax & 0xffu));
  }
  L00476895: { // 0x476895: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L0047689a: { // 0x47689a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0047689b: { // 0x47689b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047689c: { // 0x47689c: 0faf442408 IMUL EAX,dword ptr [ESP + 0x8]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000008u)),32,flags);
  }
  L004768a1: { // 0x4768a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004768a2: { // 0x4768a2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004768a5: { // 0x4768a5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004768a8: { // 0x4768a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004768a9: { // 0x4768a9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004768ab: { // 0x4768ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004768ac: { // 0x4768ac: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004768af: { // 0x4768af: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00079e70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00479e70: { // 0x479e70: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L00479e73: { // 0x479e73: 8b0db8a1a300 MOV ECX,dword ptr [0x00a3a1b8]
    s.cx = m.r32((0x00a3a1b8u));
  }
  L00479e79: { // 0x479e79: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00479e7b: { // 0x479e7b: 7c0d JL 0x00479e8a
    if(integer::condition("JL",flags)) goto L00479e8a;
  }
  L00479e7d: { // 0x479e7d: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  L00479e80: { // 0x479e80: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00479e82: { // 0x479e82: 7d06 JGE 0x00479e8a
    if(integer::condition("JGE",flags)) goto L00479e8a;
  }
  L00479e84: { // 0x479e84: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00479e89: { // 0x479e89: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00479e8a: { // 0x479e8a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00479e8c: { // 0x479e8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { // 0x47b190: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { // 0x47b193: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { // 0x47b198: 7407 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { // 0x47b19a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { // 0x47b19c: 7403 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { // 0x47b19e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1a3: { // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b1e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b1e0: { // 0x47b1e0: 8b15a8aaa300 MOV EDX,dword ptr [0x00a3aaa8]
    s.dx = m.r32((0x00a3aaa8u));
  }
  L0047b1e6: { // 0x47b1e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047b1e7: { // 0x47b1e7: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b1ea: { // 0x47b1ea: 7412 JZ 0x0047b1fe
    if(integer::condition("JZ",flags)) goto L0047b1fe;
  }
  L0047b1ec: { // 0x47b1ec: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b1ef: { // 0x47b1ef: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b1f1: { // 0x47b1f1: 7c0b JL 0x0047b1fe
    if(integer::condition("JL",flags)) goto L0047b1fe;
  }
  L0047b1f3: { // 0x47b1f3: 83c228 ADD EDX,0x28
    s.dx = integer::add(s.dx,0x00000028u,32,flags);
  }
  L0047b1f6: { // 0x47b1f6: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b1f8: { // 0x47b1f8: 7d04 JGE 0x0047b1fe
    if(integer::condition("JGE",flags)) goto L0047b1fe;
  }
  L0047b1fa: { // 0x47b1fa: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1fc: { // 0x47b1fc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b1fd: { // 0x47b1fd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1fe: { // 0x47b1fe: 8b15bca1a300 MOV EDX,dword ptr [0x00a3a1bc]
    s.dx = m.r32((0x00a3a1bcu));
  }
  L0047b204: { // 0x47b204: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b207: { // 0x47b207: 7438 JZ 0x0047b241
    if(integer::condition("JZ",flags)) goto L0047b241;
  }
  L0047b209: { // 0x47b209: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b20c: { // 0x47b20c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b20e: { // 0x47b20e: 7c31 JL 0x0047b241
    if(integer::condition("JL",flags)) goto L0047b241;
  }
  L0047b210: { // 0x47b210: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b213: { // 0x47b213: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b215: { // 0x47b215: 7d2a JGE 0x0047b241
    if(integer::condition("JGE",flags)) goto L0047b241;
  }
  L0047b217: { // 0x47b217: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b219: { // 0x47b219: 740b JZ 0x0047b226
    if(integer::condition("JZ",flags)) goto L0047b226;
  }
  L0047b21b: { // 0x47b21b: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b21e: { // 0x47b21e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b220: { // 0x47b220: 0f858f010000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b226: { // 0x47b226: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b22c: { // 0x47b22c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047b22e: { // 0x47b22e: 0f8485010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b234: { // 0x47b234: 80f904 CMP CL,0x4
    (void)integer::sub((s.cx & 0xffu),0x00000004u,8,flags);
  }
  L0047b237: { // 0x47b237: 0f847c010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b23d: { // 0x47b23d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b23f: { // 0x47b23f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b240: { // 0x47b240: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b241: { // 0x47b241: 8b15904ba500 MOV EDX,dword ptr [0x00a54b90]
    s.dx = m.r32((0x00a54b90u));
  }
  L0047b247: { // 0x47b247: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b24a: { // 0x47b24a: 7439 JZ 0x0047b285
    if(integer::condition("JZ",flags)) goto L0047b285;
  }
  L0047b24c: { // 0x47b24c: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b24f: { // 0x47b24f: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b251: { // 0x47b251: 7c32 JL 0x0047b285
    if(integer::condition("JL",flags)) goto L0047b285;
  }
  L0047b253: { // 0x47b253: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b256: { // 0x47b256: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b258: { // 0x47b258: 7d2b JGE 0x0047b285
    if(integer::condition("JGE",flags)) goto L0047b285;
  }
  L0047b25a: { // 0x47b25a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b25c: { // 0x47b25c: 740b JZ 0x0047b269
    if(integer::condition("JZ",flags)) goto L0047b269;
  }
  L0047b25e: { // 0x47b25e: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b261: { // 0x47b261: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b263: { // 0x47b263: 0f854c010000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b269: { // 0x47b269: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b26f: { // 0x47b26f: 80f901 CMP CL,0x1
    (void)integer::sub((s.cx & 0xffu),0x00000001u,8,flags);
  }
  L0047b272: { // 0x47b272: 0f8441010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b278: { // 0x47b278: 80f903 CMP CL,0x3
    (void)integer::sub((s.cx & 0xffu),0x00000003u,8,flags);
  }
  L0047b27b: { // 0x47b27b: 0f8438010000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b281: { // 0x47b281: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b283: { // 0x47b283: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b284: { // 0x47b284: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b285: { // 0x47b285: 8b15d8aaa300 MOV EDX,dword ptr [0x00a3aad8]
    s.dx = m.r32((0x00a3aad8u));
  }
  L0047b28b: { // 0x47b28b: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b28e: { // 0x47b28e: 7438 JZ 0x0047b2c8
    if(integer::condition("JZ",flags)) goto L0047b2c8;
  }
  L0047b290: { // 0x47b290: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b293: { // 0x47b293: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b295: { // 0x47b295: 7c31 JL 0x0047b2c8
    if(integer::condition("JL",flags)) goto L0047b2c8;
  }
  L0047b297: { // 0x47b297: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b29a: { // 0x47b29a: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b29c: { // 0x47b29c: 7d2a JGE 0x0047b2c8
    if(integer::condition("JGE",flags)) goto L0047b2c8;
  }
  L0047b29e: { // 0x47b29e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2a0: { // 0x47b2a0: 740b JZ 0x0047b2ad
    if(integer::condition("JZ",flags)) goto L0047b2ad;
  }
  L0047b2a2: { // 0x47b2a2: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b2a5: { // 0x47b2a5: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2a7: { // 0x47b2a7: 0f8508010000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b2ad: { // 0x47b2ad: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b2b3: { // 0x47b2b3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047b2b5: { // 0x47b2b5: 0f84fe000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b2bb: { // 0x47b2bb: 80f901 CMP CL,0x1
    (void)integer::sub((s.cx & 0xffu),0x00000001u,8,flags);
  }
  L0047b2be: { // 0x47b2be: 0f84f5000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b2c4: { // 0x47b2c4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b2c6: { // 0x47b2c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b2c7: { // 0x47b2c7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b2c8: { // 0x47b2c8: 8b1528aba300 MOV EDX,dword ptr [0x00a3ab28]
    s.dx = m.r32((0x00a3ab28u));
  }
  L0047b2ce: { // 0x47b2ce: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b2d1: { // 0x47b2d1: 7439 JZ 0x0047b30c
    if(integer::condition("JZ",flags)) goto L0047b30c;
  }
  L0047b2d3: { // 0x47b2d3: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b2d6: { // 0x47b2d6: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2d8: { // 0x47b2d8: 7c32 JL 0x0047b30c
    if(integer::condition("JL",flags)) goto L0047b30c;
  }
  L0047b2da: { // 0x47b2da: 8d7204 LEA ESI,[EDX + 0x4]
    s.si = (s.dx+0x00000004u);
  }
  L0047b2dd: { // 0x47b2dd: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0047b2df: { // 0x47b2df: 7d2b JGE 0x0047b30c
    if(integer::condition("JGE",flags)) goto L0047b30c;
  }
  L0047b2e1: { // 0x47b2e1: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2e3: { // 0x47b2e3: 740b JZ 0x0047b2f0
    if(integer::condition("JZ",flags)) goto L0047b2f0;
  }
  L0047b2e5: { // 0x47b2e5: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  L0047b2e8: { // 0x47b2e8: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b2ea: { // 0x47b2ea: 0f85c5000000 JNZ 0x0047b3b5
    if(integer::condition("JNZ",flags)) goto L0047b3b5;
  }
  L0047b2f0: { // 0x47b2f0: 8a891a010000 MOV CL,byte ptr [ECX + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.cx+0x0000011au)));
  }
  L0047b2f6: { // 0x47b2f6: 80f902 CMP CL,0x2
    (void)integer::sub((s.cx & 0xffu),0x00000002u,8,flags);
  }
  L0047b2f9: { // 0x47b2f9: 0f84ba000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b2ff: { // 0x47b2ff: 80f903 CMP CL,0x3
    (void)integer::sub((s.cx & 0xffu),0x00000003u,8,flags);
  }
  L0047b302: { // 0x47b302: 0f84b1000000 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b308: { // 0x47b308: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b30a: { // 0x47b30a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b30b: { // 0x47b30b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b30c: { // 0x47b30c: 8b153859a500 MOV EDX,dword ptr [0x00a55938]
    s.dx = m.r32((0x00a55938u));
  }
  L0047b312: { // 0x47b312: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b315: { // 0x47b315: 7412 JZ 0x0047b329
    if(integer::condition("JZ",flags)) goto L0047b329;
  }
  L0047b317: { // 0x47b317: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b31a: { // 0x47b31a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b31c: { // 0x47b31c: 7c0b JL 0x0047b329
    if(integer::condition("JL",flags)) goto L0047b329;
  }
  L0047b31e: { // 0x47b31e: 83c214 ADD EDX,0x14
    s.dx = integer::add(s.dx,0x00000014u,32,flags);
  }
  L0047b321: { // 0x47b321: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b323: { // 0x47b323: 7d04 JGE 0x0047b329
    if(integer::condition("JGE",flags)) goto L0047b329;
  }
  L0047b325: { // 0x47b325: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b327: { // 0x47b327: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b328: { // 0x47b328: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b329: { // 0x47b329: 8b15a847a500 MOV EDX,dword ptr [0x00a547a8]
    s.dx = m.r32((0x00a547a8u));
  }
  L0047b32f: { // 0x47b32f: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b332: { // 0x47b332: 7412 JZ 0x0047b346
    if(integer::condition("JZ",flags)) goto L0047b346;
  }
  L0047b334: { // 0x47b334: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b337: { // 0x47b337: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b339: { // 0x47b339: 7c0b JL 0x0047b346
    if(integer::condition("JL",flags)) goto L0047b346;
  }
  L0047b33b: { // 0x47b33b: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L0047b33e: { // 0x47b33e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b340: { // 0x47b340: 7d04 JGE 0x0047b346
    if(integer::condition("JGE",flags)) goto L0047b346;
  }
  L0047b342: { // 0x47b342: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b344: { // 0x47b344: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b345: { // 0x47b345: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b346: { // 0x47b346: 8b15b0a8a300 MOV EDX,dword ptr [0x00a3a8b0]
    s.dx = m.r32((0x00a3a8b0u));
  }
  L0047b34c: { // 0x47b34c: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b34f: { // 0x47b34f: 7412 JZ 0x0047b363
    if(integer::condition("JZ",flags)) goto L0047b363;
  }
  L0047b351: { // 0x47b351: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b354: { // 0x47b354: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b356: { // 0x47b356: 7c0b JL 0x0047b363
    if(integer::condition("JL",flags)) goto L0047b363;
  }
  L0047b358: { // 0x47b358: 83c210 ADD EDX,0x10
    s.dx = integer::add(s.dx,0x00000010u,32,flags);
  }
  L0047b35b: { // 0x47b35b: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b35d: { // 0x47b35d: 7d04 JGE 0x0047b363
    if(integer::condition("JGE",flags)) goto L0047b363;
  }
  L0047b35f: { // 0x47b35f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b361: { // 0x47b361: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b362: { // 0x47b362: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b363: { // 0x47b363: 8b15a047a500 MOV EDX,dword ptr [0x00a547a0]
    s.dx = m.r32((0x00a547a0u));
  }
  L0047b369: { // 0x47b369: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b36c: { // 0x47b36c: 7412 JZ 0x0047b380
    if(integer::condition("JZ",flags)) goto L0047b380;
  }
  L0047b36e: { // 0x47b36e: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b371: { // 0x47b371: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b373: { // 0x47b373: 7c0b JL 0x0047b380
    if(integer::condition("JL",flags)) goto L0047b380;
  }
  L0047b375: { // 0x47b375: 83c210 ADD EDX,0x10
    s.dx = integer::add(s.dx,0x00000010u,32,flags);
  }
  L0047b378: { // 0x47b378: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b37a: { // 0x47b37a: 7d04 JGE 0x0047b380
    if(integer::condition("JGE",flags)) goto L0047b380;
  }
  L0047b37c: { // 0x47b37c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b37e: { // 0x47b37e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b37f: { // 0x47b37f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b380: { // 0x47b380: 8b15305da500 MOV EDX,dword ptr [0x00a55d30]
    s.dx = m.r32((0x00a55d30u));
  }
  L0047b386: { // 0x47b386: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L0047b389: { // 0x47b389: 7412 JZ 0x0047b39d
    if(integer::condition("JZ",flags)) goto L0047b39d;
  }
  L0047b38b: { // 0x47b38b: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b38e: { // 0x47b38e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b390: { // 0x47b390: 7c0b JL 0x0047b39d
    if(integer::condition("JL",flags)) goto L0047b39d;
  }
  L0047b392: { // 0x47b392: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L0047b395: { // 0x47b395: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047b397: { // 0x47b397: 7d04 JGE 0x0047b39d
    if(integer::condition("JGE",flags)) goto L0047b39d;
  }
  L0047b399: { // 0x47b399: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b39b: { // 0x47b39b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b39c: { // 0x47b39c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b39d: { // 0x47b39d: a1a4aaa300 MOV EAX,[0x00a3aaa4]
    s.ax = m.r32((0x00a3aaa4u));
  }
  L0047b3a2: { // 0x47b3a2: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0047b3a5: { // 0x47b3a5: 7412 JZ 0x0047b3b9
    if(integer::condition("JZ",flags)) goto L0047b3b9;
  }
  L0047b3a7: { // 0x47b3a7: 8b4938 MOV ECX,dword ptr [ECX + 0x38]
    s.cx = m.r32((s.cx+0x00000038u));
  }
  L0047b3aa: { // 0x47b3aa: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0047b3ac: { // 0x47b3ac: 7c0b JL 0x0047b3b9
    if(integer::condition("JL",flags)) goto L0047b3b9;
  }
  L0047b3ae: { // 0x47b3ae: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  L0047b3b1: { // 0x47b3b1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0047b3b3: { // 0x47b3b3: 7d04 JGE 0x0047b3b9
    if(integer::condition("JGE",flags)) goto L0047b3b9;
  }
  L0047b3b5: { // 0x47b3b5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b3b7: { // 0x47b3b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b3b8: { // 0x47b3b8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b3b9: { // 0x47b3b9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b3bb: { // 0x47b3bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b3bc: { // 0x47b3bc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b3c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b3c0: { // 0x47b3c0: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b3c3: { // 0x47b3c3: 8b0dac47a500 MOV ECX,dword ptr [0x00a547ac]
    s.cx = m.r32((0x00a547acu));
  }
  L0047b3c9: { // 0x47b3c9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b3cb: { // 0x47b3cb: 7c0a JL 0x0047b3d7
    if(integer::condition("JL",flags)) goto L0047b3d7;
  }
  L0047b3cd: { // 0x47b3cd: 83c12a ADD ECX,0x2a
    s.cx = integer::add(s.cx,0x0000002au,32,flags);
  }
  L0047b3d0: { // 0x47b3d0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b3d2: { // 0x47b3d2: 7d03 JGE 0x0047b3d7
    if(integer::condition("JGE",flags)) goto L0047b3d7;
  }
  L0047b3d4: { // 0x47b3d4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b3d6: { // 0x47b3d6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b3d7: { // 0x47b3d7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b3d9: { // 0x47b3d9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b560: { // 0x47b560: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b563: { // 0x47b563: 8b0db0a8a300 MOV ECX,dword ptr [0x00a3a8b0]
    s.cx = m.r32((0x00a3a8b0u));
  }
  L0047b569: { // 0x47b569: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b56b: { // 0x47b56b: 7c0a JL 0x0047b577
    if(integer::condition("JL",flags)) goto L0047b577;
  }
  L0047b56d: { // 0x47b56d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b570: { // 0x47b570: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b572: { // 0x47b572: 7d03 JGE 0x0047b577
    if(integer::condition("JGE",flags)) goto L0047b577;
  }
  L0047b574: { // 0x47b574: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b576: { // 0x47b576: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b577: { // 0x47b577: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b579: { // 0x47b579: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b580: { // 0x47b580: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b583: { // 0x47b583: 8b0da047a500 MOV ECX,dword ptr [0x00a547a0]
    s.cx = m.r32((0x00a547a0u));
  }
  L0047b589: { // 0x47b589: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b58b: { // 0x47b58b: 7c0a JL 0x0047b597
    if(integer::condition("JL",flags)) goto L0047b597;
  }
  L0047b58d: { // 0x47b58d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b590: { // 0x47b590: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b592: { // 0x47b592: 7d03 JGE 0x0047b597
    if(integer::condition("JGE",flags)) goto L0047b597;
  }
  L0047b594: { // 0x47b594: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b596: { // 0x47b596: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b597: { // 0x47b597: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b599: { // 0x47b599: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001078f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005078f0: { // 0x5078f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005078f1: { // 0x5078f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005078f2: { // 0x5078f2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005078f3: { // 0x5078f3: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L005078f7: { // 0x5078f7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005078f9: { // 0x5078f9: e8d2e6f6ff CALL 0x00475fd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475fd0u,5273854u); flags=s.arithmetic_flags;
  }
  L005078fe: { // 0x5078fe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005078ff: { // 0x5078ff: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00507904: { // 0x507904: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00507906: { // 0x507906: e885db0300 CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5273867u); flags=s.arithmetic_flags;
  }
  L0050790b: { // 0x50790b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0050790c: { // 0x50790c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00507911: { // 0x507911: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00507913: { // 0x507913: e858f70400 CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,5273880u); flags=s.arithmetic_flags;
  }
  L00507918: { // 0x507918: 8b0d608da200 MOV ECX,dword ptr [0x00a28d60]
    s.cx = m.r32((0x00a28d60u));
  }
  L0050791e: { // 0x50791e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00507920: { // 0x507920: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00507923: { // 0x507923: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00507925: { // 0x507925: 7f29 JG 0x00507950
    if(integer::condition("JG",flags)) goto L00507950;
  }
  L00507927: { // 0x507927: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  L00507929: { // 0x507929: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0050792b: { // 0x50792b: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L0050792d: { // 0x50792d: 8a8e28010000 MOV CL,byte ptr [ESI + 0x128]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000128u)));
  }
  L00507933: { // 0x507933: f6d2 NOT DL
    s.dx = with_al(s.dx, (~((s.dx & 0xffu))&integer::mask(8)));
  }
  L00507935: { // 0x507935: 22ca AND CL,DL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&((s.dx & 0xffu)),8,flags));
  }
  L00507937: { // 0x507937: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00507939: { // 0x507939: 888e28010000 MOV byte ptr [ESI + 0x128],CL
    m.w8((s.si+0x00000128u), (s.cx & 0xffu));
  }
  L0050793f: { // 0x50793f: a81c TEST AL,0x1c
    (void)integer::logical(((s.ax & 0xffu))&(0x0000001cu),8,flags);
  }
  L00507941: { // 0x507941: 7530 JNZ 0x00507973
    if(integer::condition("JNZ",flags)) goto L00507973;
  }
  L00507943: { // 0x507943: c74658ffffffff MOV dword ptr [ESI + 0x58],0xffffffff
    m.w32((s.si+0x00000058u), 0xffffffffu);
  }
  L0050794a: { // 0x50794a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050794b: { // 0x50794b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050794c: { // 0x50794c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0050794d: { // 0x50794d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00507950: { // 0x507950: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00507952: { // 0x507952: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00507954: { // 0x507954: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00507956: { // 0x507956: 8a8e24010000 MOV CL,byte ptr [ESI + 0x124]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000124u)));
  }
  L0050795c: { // 0x50795c: f6d0 NOT AL
    s.ax = with_al(s.ax, (~((s.ax & 0xffu))&integer::mask(8)));
  }
  L0050795e: { // 0x50795e: 22c8 AND CL,AL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&((s.ax & 0xffu)),8,flags));
  }
  L00507960: { // 0x507960: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00507962: { // 0x507962: 888e24010000 MOV byte ptr [ESI + 0x124],CL
    m.w8((s.si+0x00000124u), (s.cx & 0xffu));
  }
  L00507968: { // 0x507968: a81c TEST AL,0x1c
    (void)integer::logical(((s.ax & 0xffu))&(0x0000001cu),8,flags);
  }
  L0050796a: { // 0x50796a: 7507 JNZ 0x00507973
    if(integer::condition("JNZ",flags)) goto L00507973;
  }
  L0050796c: { // 0x50796c: c74654ffffffff MOV dword ptr [ESI + 0x54],0xffffffff
    m.w32((s.si+0x00000054u), 0xffffffffu);
  }
  L00507973: { // 0x507973: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00507974: { // 0x507974: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00507975: { // 0x507975: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00507976: { // 0x507976: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX,0x9
    s.dx = integer::shift(s.dx,0x00000009u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x005454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX,dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x005454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX,dword ptr [ECX + EDX*0x4]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x005454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc],SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe],AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00147bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547bb0: { // 0x547bb0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00547bb3: { // 0x547bb3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00547bb7: { // 0x547bb7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547bb8: { // 0x547bb8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547bb9: { // 0x547bb9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547bba: { // 0x547bba: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00547bbc: { // 0x547bbc: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00547bbf: { // 0x547bbf: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L00547bc2: { // 0x547bc2: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00547bc4: { // 0x547bc4: e8e7031500 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5536713u); flags=s.arithmetic_flags;
  }
  L00547bc9: { // 0x547bc9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00547bcb: { // 0x547bcb: b877777777 MOV EAX,0x77777777
    s.ax = 0x77777777u;
  }
  L00547bd0: { // 0x547bd0: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00547bd2: { // 0x547bd2: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00547bd4: { // 0x547bd4: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547bd7: { // 0x547bd7: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00547bd9: { // 0x547bd9: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00547bdc: { // 0x547bdc: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00547bde: { // 0x547bde: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00547be0: { // 0x547be0: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00547be3: { // 0x547be3: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00547be5: { // 0x547be5: e8c6031500 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,5536746u); flags=s.arithmetic_flags;
  }
  L00547bea: { // 0x547bea: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00547bec: { // 0x547bec: b877777777 MOV EAX,0x77777777
    s.ax = 0x77777777u;
  }
  L00547bf1: { // 0x547bf1: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00547bf3: { // 0x547bf3: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00547bf5: { // 0x547bf5: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00547bf9: { // 0x547bf9: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547bfc: { // 0x547bfc: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00547bfe: { // 0x547bfe: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00547c01: { // 0x547c01: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00547c03: { // 0x547c03: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00547c05: { // 0x547c05: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00547c08: { // 0x547c08: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00547c0a: { // 0x547c0a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547c0b: { // 0x547c0b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547c11: { // 0x547c11: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547c13: { // 0x547c13: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547c16: { // 0x547c16: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L00547c1b: { // 0x547c1b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00547c1d: { // 0x547c1d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00547c1e: { // 0x547c1e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00547c24: { // 0x547c24: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00547c26: { // 0x547c26: bafeffffff MOV EDX,0xfffffffe
    s.dx = 0xfffffffeu;
  }
  L00547c2b: { // 0x547c2b: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00547c2e: { // 0x547c2e: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00547c30: { // 0x547c30: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L00547c35: { // 0x547c35: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00547c37: { // 0x547c37: 8d4102 LEA EAX,[ECX + 0x2]
    s.ax = (s.cx+0x00000002u);
  }
  L00547c3a: { // 0x547c3a: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00547c3c: { // 0x547c3c: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00547c40: { // 0x547c40: 0f8d31010000 JGE 0x00547d77
    if(integer::condition("JGE",flags)) goto L00547d77;
  }
  L00547c46: { // 0x547c46: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L00547c4c: { // 0x547c4c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00547c4d: { // 0x547c4d: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00547c4f: { // 0x547c4f: 0f8d18010000 JGE 0x00547d6d
    if(integer::condition("JGE",flags)) goto L00547d6d;
  }
  L00547c55: { // 0x547c55: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00547c57: { // 0x547c57: 8d6901 LEA EBP,[ECX + 0x1]
    s.bp = (s.cx+0x00000001u);
  }
  L00547c5a: { // 0x547c5a: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  L00547c5d: { // 0x547c5d: 0fafed IMUL EBP,EBP
    s.bp = integer::imul(s.bp,s.bp,32,flags);
  }
  L00547c60: { // 0x547c60: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00547c64: { // 0x547c64: eb04 JMP 0x00547c6a
    goto L00547c6a;
  }
  L00547c66: { // 0x547c66: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00547c6a: { // 0x547c6a: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00547c6c: { // 0x547c6c: 0fafca IMUL ECX,EDX
    s.cx = integer::imul(s.cx,s.dx,32,flags);
  }
  L00547c6f: { // 0x547c6f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00547c71: { // 0x547c71: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00547c73: { // 0x547c73: 0f8de0000000 JGE 0x00547d59
    if(integer::condition("JGE",flags)) goto L00547d59;
  }
  L00547c79: { // 0x547c79: 8b4c241a MOV ECX,dword ptr [ESP + 0x1a]
    s.cx = m.r32((f.sp+0x0000001au));
  }
  L00547c7d: { // 0x547c7d: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00547c81: { // 0x547c81: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00547c83: { // 0x547c83: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00547c85: { // 0x547c85: 66894c2426 MOV word ptr [ESP + 0x26],CX
    m.w16((f.sp+0x00000026u), (s.cx & 0xffffu));
  }
  L00547c8a: { // 0x547c8a: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L00547c8f: { // 0x547c8f: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00547c92: { // 0x547c92: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L00547c96: { // 0x547c96: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00547c99: { // 0x547c99: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L00547c9c: { // 0x547c9c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00547c9e: { // 0x547c9e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547ca0: { // 0x547ca0: 7c0e JL 0x00547cb0
    if(integer::condition("JL",flags)) goto L00547cb0;
  }
  L00547ca2: { // 0x547ca2: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00547ca7: { // 0x547ca7: 7d07 JGE 0x00547cb0
    if(integer::condition("JGE",flags)) goto L00547cb0;
  }
  L00547ca9: { // 0x547ca9: 8b0c86 MOV ECX,dword ptr [ESI + EAX*0x4]
    s.cx = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L00547cac: { // 0x547cac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00547cae: { // 0x547cae: 750b JNZ 0x00547cbb
    if(integer::condition("JNZ",flags)) goto L00547cbb;
  }
  L00547cb0: { // 0x547cb0: 893d3476a500 MOV dword ptr [0x00a57634],EDI
    m.w32((0x00a57634u), s.di);
  }
  L00547cb6: { // 0x547cb6: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L00547cbb: { // 0x547cbb: 83b93001000000 CMP dword ptr [ECX + 0x130],0x0
    (void)integer::sub(m.r32((s.cx+0x00000130u)),0x00000000u,32,flags);
  }
  L00547cc2: { // 0x547cc2: 0f8591000000 JNZ 0x00547d59
    if(integer::condition("JNZ",flags)) goto L00547d59;
  }
  L00547cc8: { // 0x547cc8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547cca: { // 0x547cca: 7c0e JL 0x00547cda
    if(integer::condition("JL",flags)) goto L00547cda;
  }
  L00547ccc: { // 0x547ccc: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00547cd1: { // 0x547cd1: 7d07 JGE 0x00547cda
    if(integer::condition("JGE",flags)) goto L00547cda;
  }
  L00547cd3: { // 0x547cd3: 8b0c86 MOV ECX,dword ptr [ESI + EAX*0x4]
    s.cx = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L00547cd6: { // 0x547cd6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00547cd8: { // 0x547cd8: 750b JNZ 0x00547ce5
    if(integer::condition("JNZ",flags)) goto L00547ce5;
  }
  L00547cda: { // 0x547cda: 893d3476a500 MOV dword ptr [0x00a57634],EDI
    m.w32((0x00a57634u), s.di);
  }
  L00547ce0: { // 0x547ce0: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L00547ce5: { // 0x547ce5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547ce7: { // 0x547ce7: c7813001000001000000 MOV dword ptr [ECX + 0x130],0x1
    m.w32((s.cx+0x00000130u), 0x00000001u);
  }
  L00547cf1: { // 0x547cf1: 7c14 JL 0x00547d07
    if(integer::condition("JL",flags)) goto L00547d07;
  }
  L00547cf3: { // 0x547cf3: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00547cf8: { // 0x547cf8: 7d0d JGE 0x00547d07
    if(integer::condition("JGE",flags)) goto L00547d07;
  }
  L00547cfa: { // 0x547cfa: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L00547d00: { // 0x547d00: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00547d03: { // 0x547d03: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00547d05: { // 0x547d05: 750b JNZ 0x00547d12
    if(integer::condition("JNZ",flags)) goto L00547d12;
  }
  L00547d07: { // 0x547d07: 893d3476a500 MOV dword ptr [0x00a57634],EDI
    m.w32((0x00a57634u), s.di);
  }
  L00547d0d: { // 0x547d0d: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L00547d12: { // 0x547d12: 8bb12c010000 MOV ESI,dword ptr [ECX + 0x12c]
    s.si = m.r32((s.cx+0x0000012cu));
  }
  L00547d18: { // 0x547d18: 83e6f7 AND ESI,0xfffffff7
    s.si = integer::logical((s.si)&(0xfffffff7u),32,flags);
  }
  L00547d1b: { // 0x547d1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547d1d: { // 0x547d1d: 89b12c010000 MOV dword ptr [ECX + 0x12c],ESI
    m.w32((s.cx+0x0000012cu), s.si);
  }
  L00547d23: { // 0x547d23: 7c14 JL 0x00547d39
    if(integer::condition("JL",flags)) goto L00547d39;
  }
  L00547d25: { // 0x547d25: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00547d2a: { // 0x547d2a: 7d0d JGE 0x00547d39
    if(integer::condition("JGE",flags)) goto L00547d39;
  }
  L00547d2c: { // 0x547d2c: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L00547d32: { // 0x547d32: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00547d35: { // 0x547d35: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00547d37: { // 0x547d37: 750b JNZ 0x00547d44
    if(integer::condition("JNZ",flags)) goto L00547d44;
  }
  L00547d39: { // 0x547d39: 893d3476a500 MOV dword ptr [0x00a57634],EDI
    m.w32((0x00a57634u), s.di);
  }
  L00547d3f: { // 0x547d3f: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00547d44: { // 0x547d44: 8b882c010000 MOV ECX,dword ptr [EAX + 0x12c]
    s.cx = m.r32((s.ax+0x0000012cu));
  }
  L00547d4a: { // 0x547d4a: 83e1ef AND ECX,0xffffffef
    s.cx = integer::logical((s.cx)&(0xffffffefu),32,flags);
  }
  L00547d4d: { // 0x547d4d: 89882c010000 MOV dword ptr [EAX + 0x12c],ECX
    m.w32((s.ax+0x0000012cu), s.cx);
  }
  L00547d53: { // 0x547d53: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L00547d59: { // 0x547d59: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00547d5d: { // 0x547d5d: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00547d5e: { // 0x547d5e: 8d4102 LEA EAX,[ECX + 0x2]
    s.ax = (s.cx+0x00000002u);
  }
  L00547d61: { // 0x547d61: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00547d63: { // 0x547d63: 0f8cfdfeffff JL 0x00547c66
    if(integer::condition("JL",flags)) goto L00547c66;
  }
  L00547d69: { // 0x547d69: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00547d6d: { // 0x547d6d: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00547d6e: { // 0x547d6e: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00547d70: { // 0x547d70: 0f8cd7feffff JL 0x00547c4d
    if(integer::condition("JL",flags)) goto L00547c4d;
  }
  L00547d76: { // 0x547d76: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00547d77: { // 0x547d77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547d78: { // 0x547d78: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547d79: { // 0x547d79: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547d7a: { // 0x547d7a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00547d7d: { // 0x547d7d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00147f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547f40: { // 0x547f40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00547f44: { // 0x547f44: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L00547f4a: { // 0x547f4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547f4b: { // 0x547f4b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547f4c: { // 0x547f4c: 0fbf30 MOVSX ESI,word ptr [EAX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00547f4f: { // 0x547f4f: 0fbf4002 MOVSX EAX,word ptr [EAX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00547f53: { // 0x547f53: 8d3c30 LEA EDI,[EAX + ESI*0x1]
    s.di = (s.ax+(s.si * 0x00000001u));
  }
  L00547f56: { // 0x547f56: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00547f58: { // 0x547f58: 7e24 JLE 0x00547f7e
    if(integer::condition("JLE",flags)) goto L00547f7e;
  }
  L00547f5a: { // 0x547f5a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547f5b: { // 0x547f5b: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00547f5d: { // 0x547f5d: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00547f5f: { // 0x547f5f: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547f61: { // 0x547f61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547f62: { // 0x547f62: 7d1a JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f64: { // 0x547f64: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00547f66: { // 0x547f66: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00547f68: { // 0x547f68: 7d14 JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f6a: { // 0x547f6a: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L00547f70: { // 0x547f70: 8d0c42 LEA ECX,[EDX + EAX*0x2]
    s.cx = (s.dx+(s.ax * 0x00000002u));
  }
  L00547f73: { // 0x547f73: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00547f75: { // 0x547f75: 7f07 JG 0x00547f7e
    if(integer::condition("JG",flags)) goto L00547f7e;
  }
  L00547f77: { // 0x547f77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f78: { // 0x547f78: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00547f7a: { // 0x547f7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f7b: { // 0x547f7b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00547f7e: { // 0x547f7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f7f: { // 0x547f7f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00547f81: { // 0x547f81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f82: { // 0x547f82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0014cf40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cf40: { // 0x54cf40: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L0054cf46: { // 0x54cf46: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L0054cf4c: { // 0x54cf4c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cf4d: { // 0x54cf4d: 8d441001 LEA EAX,[EAX + EDX*0x1 + 0x1]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0054cf51: { // 0x54cf51: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0054cf55: { // 0x54cf55: 0fbf7202 MOVSX ESI,word ptr [EDX + 0x2]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L0054cf59: { // 0x54cf59: 0fbf12 MOVSX EDX,word ptr [EDX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054cf5c: { // 0x54cf5c: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L0054cf5f: { // 0x54cf5f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054cf61: { // 0x54cf61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cf62: { // 0x54cf62: 7905 JNS 0x0054cf69
    if(integer::condition("JNS",flags)) goto L0054cf69;
  }
  L0054cf64: { // 0x54cf64: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054cf66: { // 0x54cf66: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0054cf69: { // 0x54cf69: 8b4968 MOV ECX,dword ptr [ECX + 0x68]
    s.cx = m.r32((s.cx+0x00000068u));
  }
  L0054cf6c: { // 0x54cf6c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0054cf6e: { // 0x54cf6e: 7c03 JL 0x0054cf73
    if(integer::condition("JL",flags)) goto L0054cf73;
  }
  L0054cf70: { // 0x54cf70: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L0054cf73: { // 0x54cf73: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0014d560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054d560: { // 0x54d560: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0054d563: { // 0x54d563: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0054d567: { // 0x54d567: 8b515c MOV EDX,dword ptr [ECX + 0x5c]
    s.dx = m.r32((s.cx+0x0000005cu));
  }
  L0054d56a: { // 0x54d56a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d56b: { // 0x54d56b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054d56c: { // 0x54d56c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054d56d: { // 0x54d56d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d56f: { // 0x54d56f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054d570: { // 0x54d570: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0054d574: { // 0x54d574: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0054d578: { // 0x54d578: 0f8d8b000000 JGE 0x0054d609
    if(integer::condition("JGE",flags)) goto L0054d609;
  }
  L0054d57e: { // 0x54d57e: 8b4950 MOV ECX,dword ptr [ECX + 0x50]
    s.cx = m.r32((s.cx+0x00000050u));
  }
  L0054d581: { // 0x54d581: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0054d585: { // 0x54d585: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054d588: { // 0x54d588: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0054d58a: { // 0x54d58a: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0054d58d: { // 0x54d58d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054d58f: { // 0x54d58f: 7564 JNZ 0x0054d5f5
    if(integer::condition("JNZ",flags)) goto L0054d5f5;
  }
  L0054d591: { // 0x54d591: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L0054d593: { // 0x54d593: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0054d596: { // 0x54d596: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0054d599: { // 0x54d599: 0fbfd8 MOVSX EBX,AX
    s.bx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054d59c: { // 0x54d59c: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L0054d59e: { // 0x54d59e: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0054d5a2: { // 0x54d5a2: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0054d5a4: { // 0x54d5a4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0054d5a8: { // 0x54d5a8: 7526 JNZ 0x0054d5d0
    if(integer::condition("JNZ",flags)) goto L0054d5d0;
  }
  L0054d5aa: { // 0x54d5aa: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L0054d5ae: { // 0x54d5ae: 663b44241e CMP AX,word ptr [ESP + 0x1e]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags);
  }
  L0054d5b3: { // 0x54d5b3: 7c40 JL 0x0054d5f5
    if(integer::condition("JL",flags)) goto L0054d5f5;
  }
  L0054d5b5: { // 0x54d5b5: 663b442412 CMP AX,word ptr [ESP + 0x12]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags);
  }
  L0054d5ba: { // 0x54d5ba: 7f39 JG 0x0054d5f5
    if(integer::condition("JG",flags)) goto L0054d5f5;
  }
  L0054d5bc: { // 0x54d5bc: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0054d5bf: { // 0x54d5bf: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5c1: { // 0x54d5c1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054d5c2: { // 0x54d5c2: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054d5c4: { // 0x54d5c4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5c6: { // 0x54d5c6: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0054d5ca: { // 0x54d5ca: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5cc: { // 0x54d5cc: 7e48 JLE 0x0054d616
    if(integer::condition("JLE",flags)) goto L0054d616;
  }
  L0054d5ce: { // 0x54d5ce: eb25 JMP 0x0054d5f5
    goto L0054d5f5;
  }
  L0054d5d0: { // 0x54d5d0: 668b17 MOV DX,word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0054d5d3: { // 0x54d5d3: 663bd0 CMP DX,AX
    (void)integer::sub((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0054d5d6: { // 0x54d5d6: 7f1d JG 0x0054d5f5
    if(integer::condition("JG",flags)) goto L0054d5f5;
  }
  L0054d5d8: { // 0x54d5d8: 663bd6 CMP DX,SI
    (void)integer::sub((s.dx & 0xffffu),(s.si & 0xffffu),16,flags);
  }
  L0054d5db: { // 0x54d5db: 7c18 JL 0x0054d5f5
    if(integer::condition("JL",flags)) goto L0054d5f5;
  }
  L0054d5dd: { // 0x54d5dd: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0054d5e1: { // 0x54d5e1: 0fbf54241e MOVSX EDX,word ptr [ESP + 0x1e]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001eu)),16));
  }
  L0054d5e6: { // 0x54d5e6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5e8: { // 0x54d5e8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054d5e9: { // 0x54d5e9: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054d5eb: { // 0x54d5eb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5ed: { // 0x54d5ed: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0054d5f1: { // 0x54d5f1: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d5f3: { // 0x54d5f3: 7e21 JLE 0x0054d616
    if(integer::condition("JLE",flags)) goto L0054d616;
  }
  L0054d5f5: { // 0x54d5f5: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054d5f9: { // 0x54d5f9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0054d5fd: { // 0x54d5fd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0054d5fe: { // 0x54d5fe: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0054d601: { // 0x54d601: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d603: { // 0x54d603: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0054d607: { // 0x54d607: 7c81 JL 0x0054d58a
    if(integer::condition("JL",flags)) goto L0054d58a;
  }
  L0054d609: { // 0x54d609: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d60a: { // 0x54d60a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d60b: { // 0x54d60b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d60c: { // 0x54d60c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0054d60f: { // 0x54d60f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d610: { // 0x54d610: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054d613: { // 0x54d613: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0054d616: { // 0x54d616: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054d61a: { // 0x54d61a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d61b: { // 0x54d61b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d61c: { // 0x54d61c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d61d: { // 0x54d61d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d61e: { // 0x54d61e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054d621: { // 0x54d621: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00157070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557070: { // 0x00557070: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00557073: { // 0x00557073: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00557077: { // 0x00557077: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557078: { // 0x00557078: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055707a: { // 0x0055707a: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0055707d: { // 0x0055707d: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00557081: { // 0x00557081: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L00557085: { // 0x00557085: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557086: { // 0x00557086: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055708c: { // 0x0055708c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055708e: { // 0x0055708e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00557090: { // 0x00557090: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00557093: { // 0x00557093: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557094: { // 0x00557094: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055709a: { // 0x0055709a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055709c: { // 0x0055709c: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055709f: { // 0x0055709f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005570a1: { // 0x005570a1: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005570a4: { // 0x005570a4: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L005570a7: { // 0x005570a7: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005570a9: { // 0x005570a9: 7815 JS 0x005570c0
    if(integer::condition("JS",flags)) goto L005570c0;
  }
  L005570ab: { // 0x005570ab: 3b0d5ca98100 CMP ECX,dword ptr [0x0081a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  L005570b1: { // 0x005570b1: 7d0d JGE 0x005570c0
    if(integer::condition("JGE",flags)) goto L005570c0;
  }
  L005570b3: { // 0x005570b3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005570b9: { // 0x005570b9: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L005570bc: { // 0x005570bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005570be: { // 0x005570be: 7518 JNZ 0x005570d8
    if(integer::condition("JNZ",flags)) goto L005570d8;
  }
  L005570c0: { // 0x005570c0: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L005570c5: { // 0x005570c5: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L005570ca: { // 0x005570ca: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005570ce: { // 0x005570ce: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L005570d3: { // 0x005570d3: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005570d8: { // 0x005570d8: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  L005570dc: { // 0x005570dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005570dd: { // 0x005570dd: e8de91f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5599458u); flags=s.arithmetic_flags;
  }
  L005570e2: { // 0x005570e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005570e3: { // 0x005570e3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005570e6: { // 0x005570e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557280: { // 0x557280: 8b8110010000 MOV EAX,dword ptr [ECX + 0x110]
    s.ax = m.r32((s.cx+0x00000110u));
  }
  L00557286: { // 0x557286: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00557287: { // 0x557287: 8ba914010000 MOV EBP,dword ptr [ECX + 0x114]
    s.bp = m.r32((s.cx+0x00000114u));
  }
  L0055728d: { // 0x55728d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055728e: { // 0x55728e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557290: { // 0x557290: 7433 JZ 0x005572c5
    if(integer::condition("JZ",flags)) goto L005572c5;
  }
  L00557292: { // 0x557292: 8bb108010000 MOV ESI,dword ptr [ECX + 0x108]
    s.si = m.r32((s.cx+0x00000108u));
  }
  L00557298: { // 0x557298: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L0055729e: { // 0x55729e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0055729f: { // 0x55729f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005572a0: { // 0x5572a0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005572a1: { // 0x5572a1: 89b108010000 MOV dword ptr [ECX + 0x108],ESI
    m.w32((s.cx+0x00000108u), s.si);
  }
  L005572a7: { // 0x5572a7: 898110010000 MOV dword ptr [ECX + 0x110],EAX
    m.w32((s.cx+0x00000110u), s.ax);
  }
  L005572ad: { // 0x5572ad: 8d8504f8ffff LEA EAX,[EBP + 0xfffff804]
    s.ax = (s.bp+0xfffff804u);
  }
  L005572b3: { // 0x5572b3: 89910c010000 MOV dword ptr [ECX + 0x10c],EDX
    m.w32((s.cx+0x0000010cu), s.dx);
  }
  L005572b9: { // 0x5572b9: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L005572bf: { // 0x5572bf: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005572c2: { // 0x5572c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005572c3: { // 0x5572c3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005572c4: { // 0x5572c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005572c5: { // 0x5572c5: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L005572cb: { // 0x5572cb: 8b8108010000 MOV EAX,dword ptr [ECX + 0x108]
    s.ax = m.r32((s.cx+0x00000108u));
  }
  L005572d1: { // 0x5572d1: 8bb1f0000000 MOV ESI,dword ptr [ECX + 0xf0]
    s.si = m.r32((s.cx+0x000000f0u));
  }
  L005572d7: { // 0x5572d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005572d8: { // 0x5572d8: 899108010000 MOV dword ptr [ECX + 0x108],EDX
    m.w32((s.cx+0x00000108u), s.dx);
  }
  L005572de: { // 0x5572de: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005572e0: { // 0x5572e0: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L005572e2: { // 0x5572e2: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572e8: { // 0x5572e8: 8d5402ff LEA EDX,[EDX + EAX*0x1 + -0x1]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L005572ec: { // 0x5572ec: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L005572ef: { // 0x5572ef: 740a JZ 0x005572fb
    if(integer::condition("JZ",flags)) goto L005572fb;
  }
  L005572f1: { // 0x5572f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005572f2: { // 0x5572f2: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005572f3: { // 0x5572f3: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572f9: { // 0x5572f9: eb0a JMP 0x00557305
    goto L00557305;
  }
  L005572fb: { // 0x5572fb: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005572fc: { // 0x5572fc: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L005572ff: { // 0x5572ff: 89b908010000 MOV dword ptr [ECX + 0x108],EDI
    m.w32((s.cx+0x00000108u), s.di);
  }
  L00557305: { // 0x557305: 8b810c010000 MOV EAX,dword ptr [ECX + 0x10c]
    s.ax = m.r32((s.cx+0x0000010cu));
  }
  L0055730b: { // 0x55730b: 8b9108010000 MOV EDX,dword ptr [ECX + 0x108]
    s.dx = m.r32((s.cx+0x00000108u));
  }
  L00557311: { // 0x557311: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00557314: { // 0x557314: 89b110010000 MOV dword ptr [ECX + 0x110],ESI
    m.w32((s.cx+0x00000110u), s.si);
  }
  L0055731a: { // 0x55731a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055731c: { // 0x55731c: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557322: { // 0x557322: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557323: { // 0x557323: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557324: { // 0x557324: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L00557327: { // 0x557327: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L0055732d: { // 0x55732d: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00557330: { // 0x557330: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557331: { // 0x557331: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557340: { // 0x557340: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L00557346: { // 0x557346: c7810801000001000000 MOV dword ptr [ECX + 0x108],0x1
    m.w32((s.cx+0x00000108u), 0x00000001u);
  }
  L00557350: { // 0x557350: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L00557356: { // 0x557356: 8d50ff LEA EDX,[EAX + -0x1]
    s.dx = (s.ax-0x00000001u);
  }
  L00557359: { // 0x557359: 899110010000 MOV dword ptr [ECX + 0x110],EDX
    m.w32((s.cx+0x00000110u), s.dx);
  }
  L0055735f: { // 0x55735f: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557365: { // 0x557365: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  L00557368: { // 0x557368: 8d441004 LEA EAX,[EAX + EDX*0x1 + 0x4]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000004u);
  }
  L0055736c: { // 0x55736c: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L00557372: { // 0x557372: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557450: { // 0x557450: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L00557454: { // 0x557454: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557455: { // 0x557455: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00557459: { // 0x557459: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055745a: { // 0x55745a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055745b: { // 0x55745b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0055745d: { // 0x55745d: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00557461: { // 0x557461: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557462: { // 0x557462: 0fbf3b MOVSX EDI,word ptr [EBX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00557465: { // 0x557465: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557467: { // 0x557467: 7454 JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L00557469: { // 0x557469: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0055746b: { // 0x55746b: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055746e: { // 0x55746e: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00557470: { // 0x557470: 7814 JS 0x00557486
    if(integer::condition("JS",flags)) goto L00557486;
  }
  L00557472: { // 0x557472: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00557477: { // 0x557477: 7d0d JGE 0x00557486
    if(integer::condition("JGE",flags)) goto L00557486;
  }
  L00557479: { // 0x557479: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055747f: { // 0x55747f: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L00557482: { // 0x557482: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557484: { // 0x557484: 750c JNZ 0x00557492
    if(integer::condition("JNZ",flags)) goto L00557492;
  }
  L00557486: { // 0x557486: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00557488: { // 0x557488: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055748d: { // 0x55748d: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00557492: { // 0x557492: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L00557498: { // 0x557498: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0055749f: { // 0x55749f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005574a1: { // 0x5574a1: 741a JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L005574a3: { // 0x5574a3: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L005574a9: { // 0x5574a9: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L005574af: { // 0x5574af: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  L005574b3: { // 0x5574b3: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  L005574b6: { // 0x5574b6: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005574b8: { // 0x5574b8: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005574ba: { // 0x5574ba: 7d01 JGE 0x005574bd
    if(integer::condition("JGE",flags)) goto L005574bd;
  }
  L005574bc: { // 0x5574bc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005574bd: { // 0x5574bd: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  L005574c3: { // 0x5574c3: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L005574c9: { // 0x5574c9: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  L005574cc: { // 0x5574cc: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  L005574cf: { // 0x5574cf: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574d1: { // 0x5574d1: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L005574d3: { // 0x5574d3: 7e49 JLE 0x0055751e
    if(integer::condition("JLE",flags)) goto L0055751e;
  }
  L005574d5: { // 0x5574d5: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  L005574db: { // 0x5574db: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  L005574e1: { // 0x5574e1: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L005574e3: { // 0x5574e3: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  L005574e7: { // 0x5574e7: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574e9: { // 0x5574e9: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  L005574ec: { // 0x5574ec: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005574ee: { // 0x5574ee: 7f2e JG 0x0055751e
    if(integer::condition("JG",flags)) goto L0055751e;
  }
  L005574f0: { // 0x5574f0: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  L005574f6: { // 0x5574f6: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  L005574fc: { // 0x5574fc: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005574fe: { // 0x5574fe: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00557500: { // 0x557500: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00557502: { // 0x557502: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00557504: { // 0x557504: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00557506: { // 0x557506: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00557508: { // 0x557508: 7d14 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L0055750a: { // 0x55750a: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  L0055750d: { // 0x55750d: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0055750f: { // 0x55750f: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00557511: { // 0x557511: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00557513: { // 0x557513: 7d09 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L00557515: { // 0x557515: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557516: { // 0x557516: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557517: { // 0x557517: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557518: { // 0x557518: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0055751a: { // 0x55751a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055751b: { // 0x55751b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055751e: { // 0x55751e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055751f: { // 0x55751f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557520: { // 0x557520: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557521: { // 0x557521: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00557523: { // 0x557523: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557524: { // 0x557524: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00158b60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00558b60: { // 0x558b60: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L00558b63: { // 0x558b63: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00558b67: { // 0x558b67: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00558b68: { // 0x558b68: 8b3510a98100 MOV ESI,dword ptr [0x0081a910]
    s.si = m.r32((0x0081a910u));
  }
  L00558b6e: { // 0x558b6e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00558b6f: { // 0x558b6f: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L00558b76: { // 0x558b76: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L00558b79: { // 0x558b79: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00558b7d: { // 0x558b7d: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00558b81: { // 0x558b81: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00558b85: { // 0x558b85: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558b88: { // 0x558b88: 0fbf44243e MOVSX EAX,word ptr [ESP + 0x3e]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000003eu)),16));
  }
  L00558b8d: { // 0x558b8d: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L00558b95: { // 0x558b95: 8d1408 LEA EDX,[EAX + ECX*0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u));
  }
  L00558b98: { // 0x558b98: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00558b9a: { // 0x558b9a: 0f8eff040000 JLE 0x0055909f
    if(integer::condition("JLE",flags)) goto L0055909f;
  }
  L00558ba0: { // 0x558ba0: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00558ba2: { // 0x558ba2: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00558ba4: { // 0x558ba4: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00558ba6: { // 0x558ba6: 0f8df3040000 JGE 0x0055909f
    if(integer::condition("JGE",flags)) goto L0055909f;
  }
  L00558bac: { // 0x558bac: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00558bae: { // 0x558bae: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00558bb0: { // 0x558bb0: 0f8de9040000 JGE 0x0055909f
    if(integer::condition("JGE",flags)) goto L0055909f;
  }
  L00558bb6: { // 0x558bb6: a114a98100 MOV EAX,[0x0081a914]
    s.ax = m.r32((0x0081a914u));
  }
  L00558bbb: { // 0x558bbb: 8d0c46 LEA ECX,[ESI + EAX*0x2]
    s.cx = (s.si+(s.ax * 0x00000002u));
  }
  L00558bbe: { // 0x558bbe: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00558bc0: { // 0x558bc0: 0f8fd9040000 JG 0x0055909f
    if(integer::condition("JG",flags)) goto L0055909f;
  }
  L00558bc6: { // 0x558bc6: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558bca: { // 0x558bca: e8c11d0100 CALL 0x0056a990
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056a990u,5606351u); flags=s.arithmetic_flags;
  }
  L00558bcf: { // 0x558bcf: 8a484a MOV CL,byte ptr [EAX + 0x4a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000004au)));
  }
  L00558bd2: { // 0x558bd2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00558bd4: { // 0x558bd4: 0f84c5040000 JZ 0x0055909f
    if(integer::condition("JZ",flags)) goto L0055909f;
  }
  L00558bda: { // 0x558bda: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00558bdb: { // 0x558bdb: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L00558bdf: { // 0x558bdf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00558be0: { // 0x558be0: 8b6c243a MOV EBP,dword ptr [ESP + 0x3a]
    s.bp = m.r32((f.sp+0x0000003au));
  }
  L00558be4: { // 0x558be4: 8b3d58a98100 MOV EDI,dword ptr [0x0081a958]
    s.di = m.r32((0x0081a958u));
  }
  L00558bea: { // 0x558bea: 8d4b01 LEA ECX,[EBX + 0x1]
    s.cx = (s.bx+0x00000001u);
  }
  L00558bed: { // 0x558bed: 8d45ff LEA EAX,[EBP + -0x1]
    s.ax = (s.bp-0x00000001u);
  }
  L00558bf0: { // 0x558bf0: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558bf5: { // 0x558bf5: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00558bf9: { // 0x558bf9: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558bfe: { // 0x558bfe: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558c01: { // 0x558c01: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558c04: { // 0x558c04: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558c07: { // 0x558c07: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558c09: { // 0x558c09: 7814 JS 0x00558c1f
    if(integer::condition("JS",flags)) goto L00558c1f;
  }
  L00558c0b: { // 0x558c0b: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558c10: { // 0x558c10: 7d0d JGE 0x00558c1f
    if(integer::condition("JGE",flags)) goto L00558c1f;
  }
  L00558c12: { // 0x558c12: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558c15: { // 0x558c15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558c17: { // 0x558c17: 7406 JZ 0x00558c1f
    if(integer::condition("JZ",flags)) goto L00558c1f;
  }
  L00558c19: { // 0x558c19: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00558c1d: { // 0x558c1d: eb11 JMP 0x00558c30
    goto L00558c30;
  }
  L00558c1f: { // 0x558c1f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558c23: { // 0x558c23: c74424181076a500 MOV dword ptr [ESP + 0x18],0xa57610
    m.w32((f.sp+0x00000018u), 0x00a57610u);
  }
  L00558c2b: { // 0x558c2b: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558c30: { // 0x558c30: 0fbff5 MOVSX ESI,BP
    s.si = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00558c33: { // 0x558c33: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00558c35: { // 0x558c35: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558c3a: { // 0x558c3a: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558c3d: { // 0x558c3d: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558c40: { // 0x558c40: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558c42: { // 0x558c42: 66896c2446 MOV word ptr [ESP + 0x46],BP
    m.w16((f.sp+0x00000046u), (s.bp & 0xffffu));
  }
  L00558c47: { // 0x558c47: 7814 JS 0x00558c5d
    if(integer::condition("JS",flags)) goto L00558c5d;
  }
  L00558c49: { // 0x558c49: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558c4e: { // 0x558c4e: 7d0d JGE 0x00558c5d
    if(integer::condition("JGE",flags)) goto L00558c5d;
  }
  L00558c50: { // 0x558c50: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558c53: { // 0x558c53: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558c55: { // 0x558c55: 7406 JZ 0x00558c5d
    if(integer::condition("JZ",flags)) goto L00558c5d;
  }
  L00558c57: { // 0x558c57: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00558c5b: { // 0x558c5b: eb11 JMP 0x00558c6e
    goto L00558c6e;
  }
  L00558c5d: { // 0x558c5d: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558c61: { // 0x558c61: c74424201076a500 MOV dword ptr [ESP + 0x20],0xa57610
    m.w32((f.sp+0x00000020u), 0x00a57610u);
  }
  L00558c69: { // 0x558c69: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558c6e: { // 0x558c6e: 8d5501 LEA EDX,[EBP + 0x1]
    s.dx = (s.bp+0x00000001u);
  }
  L00558c71: { // 0x558c71: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558c76: { // 0x558c76: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L00558c79: { // 0x558c79: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558c7e: { // 0x558c7e: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558c81: { // 0x558c81: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558c84: { // 0x558c84: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558c87: { // 0x558c87: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00558c89: { // 0x558c89: 7814 JS 0x00558c9f
    if(integer::condition("JS",flags)) goto L00558c9f;
  }
  L00558c8b: { // 0x558c8b: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558c90: { // 0x558c90: 7d0d JGE 0x00558c9f
    if(integer::condition("JGE",flags)) goto L00558c9f;
  }
  L00558c92: { // 0x558c92: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558c95: { // 0x558c95: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558c97: { // 0x558c97: 7406 JZ 0x00558c9f
    if(integer::condition("JZ",flags)) goto L00558c9f;
  }
  L00558c99: { // 0x558c99: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00558c9d: { // 0x558c9d: eb11 JMP 0x00558cb0
    goto L00558cb0;
  }
  L00558c9f: { // 0x558c9f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558ca3: { // 0x558ca3: c744242c1076a500 MOV dword ptr [ESP + 0x2c],0xa57610
    m.w32((f.sp+0x0000002cu), 0x00a57610u);
  }
  L00558cab: { // 0x558cab: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558cb0: { // 0x558cb0: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L00558cb3: { // 0x558cb3: 66895c2444 MOV word ptr [ESP + 0x44],BX
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00558cb8: { // 0x558cb8: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558cbd: { // 0x558cbd: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558cc0: { // 0x558cc0: 0fbfcb MOVSX ECX,BX
    s.cx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00558cc3: { // 0x558cc3: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558cc6: { // 0x558cc6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00558cc8: { // 0x558cc8: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L00558ccc: { // 0x558ccc: 7814 JS 0x00558ce2
    if(integer::condition("JS",flags)) goto L00558ce2;
  }
  L00558cce: { // 0x558cce: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558cd3: { // 0x558cd3: 7d0d JGE 0x00558ce2
    if(integer::condition("JGE",flags)) goto L00558ce2;
  }
  L00558cd5: { // 0x558cd5: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558cd8: { // 0x558cd8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558cda: { // 0x558cda: 7406 JZ 0x00558ce2
    if(integer::condition("JZ",flags)) goto L00558ce2;
  }
  L00558cdc: { // 0x558cdc: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00558ce0: { // 0x558ce0: eb12 JMP 0x00558cf4
    goto L00558cf4;
  }
  L00558ce2: { // 0x558ce2: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00558ce6: { // 0x558ce6: c74424281076a500 MOV dword ptr [ESP + 0x28],0xa57610
    m.w32((f.sp+0x00000028u), 0x00a57610u);
  }
  L00558cee: { // 0x558cee: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L00558cf4: { // 0x558cf4: 8d4bff LEA ECX,[EBX + -0x1]
    s.cx = (s.bx-0x00000001u);
  }
  L00558cf7: { // 0x558cf7: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L00558cfc: { // 0x558cfc: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00558cff: { // 0x558cff: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558d02: { // 0x558d02: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558d05: { // 0x558d05: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558d07: { // 0x558d07: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558d0c: { // 0x558d0c: 7814 JS 0x00558d22
    if(integer::condition("JS",flags)) goto L00558d22;
  }
  L00558d0e: { // 0x558d0e: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558d13: { // 0x558d13: 7d0d JGE 0x00558d22
    if(integer::condition("JGE",flags)) goto L00558d22;
  }
  L00558d15: { // 0x558d15: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558d18: { // 0x558d18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558d1a: { // 0x558d1a: 7406 JZ 0x00558d22
    if(integer::condition("JZ",flags)) goto L00558d22;
  }
  L00558d1c: { // 0x558d1c: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00558d20: { // 0x558d20: eb11 JMP 0x00558d33
    goto L00558d33;
  }
  L00558d22: { // 0x558d22: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558d26: { // 0x558d26: c74424241076a500 MOV dword ptr [ESP + 0x24],0xa57610
    m.w32((f.sp+0x00000024u), 0x00a57610u);
  }
  L00558d2e: { // 0x558d2e: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558d33: { // 0x558d33: 668bc1 MOV AX,CX
    s.ax = with_ax(s.ax, (s.cx & 0xffffu));
  }
  L00558d36: { // 0x558d36: 66896c2446 MOV word ptr [ESP + 0x46],BP
    m.w16((f.sp+0x00000046u), (s.bp & 0xffffu));
  }
  L00558d3b: { // 0x558d3b: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558d3e: { // 0x558d3e: c1e609 SHL ESI,0x9
    s.si = integer::shift(s.si,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558d41: { // 0x558d41: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00558d43: { // 0x558d43: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L00558d48: { // 0x558d48: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00558d4a: { // 0x558d4a: 7814 JS 0x00558d60
    if(integer::condition("JS",flags)) goto L00558d60;
  }
  L00558d4c: { // 0x558d4c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558d51: { // 0x558d51: 7d0d JGE 0x00558d60
    if(integer::condition("JGE",flags)) goto L00558d60;
  }
  L00558d53: { // 0x558d53: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558d56: { // 0x558d56: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558d58: { // 0x558d58: 7406 JZ 0x00558d60
    if(integer::condition("JZ",flags)) goto L00558d60;
  }
  L00558d5a: { // 0x558d5a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00558d5e: { // 0x558d5e: eb11 JMP 0x00558d71
    goto L00558d71;
  }
  L00558d60: { // 0x558d60: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558d64: { // 0x558d64: c744241c1076a500 MOV dword ptr [ESP + 0x1c],0xa57610
    m.w32((f.sp+0x0000001cu), 0x00a57610u);
  }
  L00558d6c: { // 0x558d6c: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558d71: { // 0x558d71: 8b742430 MOV ESI,dword ptr [ESP + 0x30]
    s.si = m.r32((f.sp+0x00000030u));
  }
  L00558d75: { // 0x558d75: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  L00558d7a: { // 0x558d7a: 668bc6 MOV AX,SI
    s.ax = with_ax(s.ax, (s.si & 0xffffu));
  }
  L00558d7d: { // 0x558d7d: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558d82: { // 0x558d82: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558d85: { // 0x558d85: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558d88: { // 0x558d88: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558d8b: { // 0x558d8b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558d8d: { // 0x558d8d: 7812 JS 0x00558da1
    if(integer::condition("JS",flags)) goto L00558da1;
  }
  L00558d8f: { // 0x558d8f: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558d94: { // 0x558d94: 7d0b JGE 0x00558da1
    if(integer::condition("JGE",flags)) goto L00558da1;
  }
  L00558d96: { // 0x558d96: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558d99: { // 0x558d99: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558d9b: { // 0x558d9b: 7404 JZ 0x00558da1
    if(integer::condition("JZ",flags)) goto L00558da1;
  }
  L00558d9d: { // 0x558d9d: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00558d9f: { // 0x558d9f: eb0e JMP 0x00558daf
    goto L00558daf;
  }
  L00558da1: { // 0x558da1: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L00558da5: { // 0x558da5: bd1076a500 MOV EBP,0xa57610
    s.bp = 0x00a57610u;
  }
  L00558daa: { // 0x558daa: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00558daf: { // 0x558daf: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00558db3: { // 0x558db3: 668bc6 MOV AX,SI
    s.ax = with_ax(s.ax, (s.si & 0xffffu));
  }
  L00558db6: { // 0x558db6: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00558dbb: { // 0x558dbb: 66895c2444 MOV word ptr [ESP + 0x44],BX
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00558dc0: { // 0x558dc0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00558dc3: { // 0x558dc3: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00558dc6: { // 0x558dc6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00558dc8: { // 0x558dc8: 7812 JS 0x00558ddc
    if(integer::condition("JS",flags)) goto L00558ddc;
  }
  L00558dca: { // 0x558dca: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00558dcf: { // 0x558dcf: 7d0b JGE 0x00558ddc
    if(integer::condition("JGE",flags)) goto L00558ddc;
  }
  L00558dd1: { // 0x558dd1: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  L00558dd4: { // 0x558dd4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00558dd6: { // 0x558dd6: 7404 JZ 0x00558ddc
    if(integer::condition("JZ",flags)) goto L00558ddc;
  }
  L00558dd8: { // 0x558dd8: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00558dda: { // 0x558dda: eb0f JMP 0x00558deb
    goto L00558deb;
  }
  L00558ddc: { // 0x558ddc: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00558de0: { // 0x558de0: bb1076a500 MOV EBX,0xa57610
    s.bx = 0x00a57610u;
  }
  L00558de5: { // 0x558de5: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00558deb: { // 0x558deb: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00558dee: { // 0x558dee: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L00558df1: { // 0x558df1: 8b3510a98100 MOV ESI,dword ptr [0x0081a910]
    s.si = m.r32((0x0081a910u));
  }
  L00558df7: { // 0x558df7: 8d3c02 LEA EDI,[EDX + EAX*0x1]
    s.di = (s.dx+(s.ax * 0x00000001u));
  }
  L00558dfa: { // 0x558dfa: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L00558dfc: { // 0x558dfc: 7e45 JLE 0x00558e43
    if(integer::condition("JLE",flags)) goto L00558e43;
  }
  L00558dfe: { // 0x558dfe: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00558e00: { // 0x558e00: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00558e02: { // 0x558e02: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00558e04: { // 0x558e04: 7d3d JGE 0x00558e43
    if(integer::condition("JGE",flags)) goto L00558e43;
  }
  L00558e06: { // 0x558e06: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00558e08: { // 0x558e08: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00558e0a: { // 0x558e0a: 7d37 JGE 0x00558e43
    if(integer::condition("JGE",flags)) goto L00558e43;
  }
  L00558e0c: { // 0x558e0c: 8b1514a98100 MOV EDX,dword ptr [0x0081a914]
    s.dx = m.r32((0x0081a914u));
  }
  L00558e12: { // 0x558e12: 8d0456 LEA EAX,[ESI + EDX*0x2]
    s.ax = (s.si+(s.dx * 0x00000002u));
  }
  L00558e15: { // 0x558e15: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00558e17: { // 0x558e17: 7f2a JG 0x00558e43
    if(integer::condition("JG",flags)) goto L00558e43;
  }
  L00558e19: { // 0x558e19: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00558e1d: { // 0x558e1d: 0fbe8d1b010000 MOVSX ECX,byte ptr [EBP + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x0000011bu)),8));
  }
  L00558e24: { // 0x558e24: 8d5704 LEA EDX,[EDI + 0x4]
    s.dx = (s.di+0x00000004u);
  }
  L00558e27: { // 0x558e27: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00558e29: { // 0x558e29: 7512 JNZ 0x00558e3d
    if(integer::condition("JNZ",flags)) goto L00558e3d;
  }
  L00558e2b: { // 0x558e2b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00558e2d: { // 0x558e2d: e8ae23f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5606962u); flags=s.arithmetic_flags;
  }
  L00558e32: { // 0x558e32: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558e34: { // 0x558e34: 7507 JNZ 0x00558e3d
    if(integer::condition("JNZ",flags)) goto L00558e3d;
  }
  L00558e36: { // 0x558e36: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L00558e3b: { // 0x558e3b: eb0e JMP 0x00558e4b
    goto L00558e4b;
  }
  L00558e3d: { // 0x558e3d: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00558e41: { // 0x558e41: eb08 JMP 0x00558e4b
    goto L00558e4b;
  }
  L00558e43: { // 0x558e43: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00558e47: { // 0x558e47: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00558e4b: { // 0x558e4b: 8b4c243a MOV ECX,dword ptr [ESP + 0x3a]
    s.cx = m.r32((f.sp+0x0000003au));
  }
  L00558e4f: { // 0x558e4f: 668b442438 MOV AX,word ptr [ESP + 0x38]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000038u)));
  }
  L00558e54: { // 0x558e54: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00558e55: { // 0x558e55: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L00558e5a: { // 0x558e5a: 66894c2446 MOV word ptr [ESP + 0x46],CX
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L00558e5f: { // 0x558e5f: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00558e63: { // 0x558e63: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558e67: { // 0x558e67: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558e6c: { // 0x558e6c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558e6d: { // 0x558e6d: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00558e71: { // 0x558e71: e8caf0feff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607030u); flags=s.arithmetic_flags;
  }
  L00558e76: { // 0x558e76: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558e78: { // 0x558e78: 741f JZ 0x00558e99
    if(integer::condition("JZ",flags)) goto L00558e99;
  }
  L00558e7a: { // 0x558e7a: 0fbe8b1b010000 MOVSX ECX,byte ptr [EBX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.bx+0x0000011bu)),8));
  }
  L00558e81: { // 0x558e81: 8d5704 LEA EDX,[EDI + 0x4]
    s.dx = (s.di+0x00000004u);
  }
  L00558e84: { // 0x558e84: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00558e86: { // 0x558e86: 7511 JNZ 0x00558e99
    if(integer::condition("JNZ",flags)) goto L00558e99;
  }
  L00558e88: { // 0x558e88: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00558e8a: { // 0x558e8a: e85123f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607055u); flags=s.arithmetic_flags;
  }
  L00558e8f: { // 0x558e8f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558e91: { // 0x558e91: 7506 JNZ 0x00558e99
    if(integer::condition("JNZ",flags)) goto L00558e99;
  }
  L00558e93: { // 0x558e93: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L00558e99: { // 0x558e99: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558e9d: { // 0x558e9d: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558ea1: { // 0x558ea1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558ea2: { // 0x558ea2: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L00558ea5: { // 0x558ea5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558ea6: { // 0x558ea6: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558eaa: { // 0x558eaa: 66c744244c0100 MOV word ptr [ESP + 0x4c],0x1
    m.w16((f.sp+0x0000004cu), 0x00000001u);
  }
  L00558eb1: { // 0x558eb1: 668974244e MOV word ptr [ESP + 0x4e],SI
    m.w16((f.sp+0x0000004eu), (s.si & 0xffffu));
  }
  L00558eb6: { // 0x558eb6: e8151fedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607099u); flags=s.arithmetic_flags;
  }
  L00558ebb: { // 0x558ebb: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00558ebd: { // 0x558ebd: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L00558ec1: { // 0x558ec1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558ec2: { // 0x558ec2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558ec7: { // 0x558ec7: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00558ecb: { // 0x558ecb: e870f0feff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607120u); flags=s.arithmetic_flags;
  }
  L00558ed0: { // 0x558ed0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558ed2: { // 0x558ed2: 741e JZ 0x00558ef2
    if(integer::condition("JZ",flags)) goto L00558ef2;
  }
  L00558ed4: { // 0x558ed4: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00558ed8: { // 0x558ed8: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558edb: { // 0x558edb: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558ee2: { // 0x558ee2: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558ee4: { // 0x558ee4: 750c JNZ 0x00558ef2
    if(integer::condition("JNZ",flags)) goto L00558ef2;
  }
  L00558ee6: { // 0x558ee6: e8f522f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607147u); flags=s.arithmetic_flags;
  }
  L00558eeb: { // 0x558eeb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558eed: { // 0x558eed: 7503 JNZ 0x00558ef2
    if(integer::condition("JNZ",flags)) goto L00558ef2;
  }
  L00558eef: { // 0x558eef: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L00558ef2: { // 0x558ef2: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L00558ef6: { // 0x558ef6: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00558efa: { // 0x558efa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558efb: { // 0x558efb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00558efc: { // 0x558efc: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558f00: { // 0x558f00: 668974244c MOV word ptr [ESP + 0x4c],SI
    m.w16((f.sp+0x0000004cu), (s.si & 0xffffu));
  }
  L00558f05: { // 0x558f05: 66c744244e0000 MOV word ptr [ESP + 0x4e],0x0
    m.w16((f.sp+0x0000004eu), 0x00000000u);
  }
  L00558f0c: { // 0x558f0c: e8bf1eedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607185u); flags=s.arithmetic_flags;
  }
  L00558f11: { // 0x558f11: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00558f13: { // 0x558f13: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L00558f17: { // 0x558f17: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558f18: { // 0x558f18: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558f1d: { // 0x558f1d: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00558f21: { // 0x558f21: e81af0feff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607206u); flags=s.arithmetic_flags;
  }
  L00558f26: { // 0x558f26: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f28: { // 0x558f28: 741e JZ 0x00558f48
    if(integer::condition("JZ",flags)) goto L00558f48;
  }
  L00558f2a: { // 0x558f2a: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00558f2e: { // 0x558f2e: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558f31: { // 0x558f31: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558f38: { // 0x558f38: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558f3a: { // 0x558f3a: 750c JNZ 0x00558f48
    if(integer::condition("JNZ",flags)) goto L00558f48;
  }
  L00558f3c: { // 0x558f3c: e89f22f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607233u); flags=s.arithmetic_flags;
  }
  L00558f41: { // 0x558f41: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f43: { // 0x558f43: 7503 JNZ 0x00558f48
    if(integer::condition("JNZ",flags)) goto L00558f48;
  }
  L00558f45: { // 0x558f45: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L00558f48: { // 0x558f48: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00558f4a: { // 0x558f4a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00558f4c: { // 0x558f4c: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00558f50: { // 0x558f50: e8db1dedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607253u); flags=s.arithmetic_flags;
  }
  L00558f55: { // 0x558f55: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558f59: { // 0x558f59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558f5a: { // 0x558f5a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558f5b: { // 0x558f5b: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558f5f: { // 0x558f5f: e86c1eedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607268u); flags=s.arithmetic_flags;
  }
  L00558f64: { // 0x558f64: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00558f66: { // 0x558f66: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558f6a: { // 0x558f6a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558f6b: { // 0x558f6b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558f70: { // 0x558f70: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00558f74: { // 0x558f74: e8c7effeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607289u); flags=s.arithmetic_flags;
  }
  L00558f79: { // 0x558f79: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f7b: { // 0x558f7b: 741e JZ 0x00558f9b
    if(integer::condition("JZ",flags)) goto L00558f9b;
  }
  L00558f7d: { // 0x558f7d: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00558f81: { // 0x558f81: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558f84: { // 0x558f84: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558f8b: { // 0x558f8b: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558f8d: { // 0x558f8d: 750c JNZ 0x00558f9b
    if(integer::condition("JNZ",flags)) goto L00558f9b;
  }
  L00558f8f: { // 0x558f8f: e84c22f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607316u); flags=s.arithmetic_flags;
  }
  L00558f94: { // 0x558f94: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558f96: { // 0x558f96: 7503 JNZ 0x00558f9b
    if(integer::condition("JNZ",flags)) goto L00558f9b;
  }
  L00558f98: { // 0x558f98: 83cd02 OR EBP,0x2
    s.bp = integer::logical((s.bp)|(0x00000002u),32,flags);
  }
  L00558f9b: { // 0x558f9b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00558f9d: { // 0x558f9d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00558f9e: { // 0x558f9e: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00558fa2: { // 0x558fa2: e8891dedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607335u); flags=s.arithmetic_flags;
  }
  L00558fa7: { // 0x558fa7: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558fab: { // 0x558fab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558fac: { // 0x558fac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00558fad: { // 0x558fad: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00558fb1: { // 0x558fb1: e81a1eedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607350u); flags=s.arithmetic_flags;
  }
  L00558fb6: { // 0x558fb6: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00558fb8: { // 0x558fb8: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00558fbc: { // 0x558fbc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558fbd: { // 0x558fbd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00558fc2: { // 0x558fc2: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00558fc6: { // 0x558fc6: e875effeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607371u); flags=s.arithmetic_flags;
  }
  L00558fcb: { // 0x558fcb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558fcd: { // 0x558fcd: 741e JZ 0x00558fed
    if(integer::condition("JZ",flags)) goto L00558fed;
  }
  L00558fcf: { // 0x558fcf: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00558fd3: { // 0x558fd3: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00558fd6: { // 0x558fd6: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00558fdd: { // 0x558fdd: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00558fdf: { // 0x558fdf: 750c JNZ 0x00558fed
    if(integer::condition("JNZ",flags)) goto L00558fed;
  }
  L00558fe1: { // 0x558fe1: e8fa21f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607398u); flags=s.arithmetic_flags;
  }
  L00558fe6: { // 0x558fe6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00558fe8: { // 0x558fe8: 7503 JNZ 0x00558fed
    if(integer::condition("JNZ",flags)) goto L00558fed;
  }
  L00558fea: { // 0x558fea: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L00558fed: { // 0x558fed: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00558fef: { // 0x558fef: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00558ff1: { // 0x558ff1: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00558ff5: { // 0x558ff5: e8361dedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607418u); flags=s.arithmetic_flags;
  }
  L00558ffa: { // 0x558ffa: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00558ffe: { // 0x558ffe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00558fff: { // 0x558fff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00559000: { // 0x559000: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00559004: { // 0x559004: e8c71dedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607433u); flags=s.arithmetic_flags;
  }
  L00559009: { // 0x559009: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0055900b: { // 0x55900b: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L0055900f: { // 0x55900f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00559010: { // 0x559010: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00559015: { // 0x559015: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00559019: { // 0x559019: e822effeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607454u); flags=s.arithmetic_flags;
  }
  L0055901e: { // 0x55901e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00559020: { // 0x559020: 741e JZ 0x00559040
    if(integer::condition("JZ",flags)) goto L00559040;
  }
  L00559022: { // 0x559022: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00559026: { // 0x559026: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  L00559029: { // 0x559029: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00559030: { // 0x559030: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00559032: { // 0x559032: 750c JNZ 0x00559040
    if(integer::condition("JNZ",flags)) goto L00559040;
  }
  L00559034: { // 0x559034: e8a721f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607481u); flags=s.arithmetic_flags;
  }
  L00559039: { // 0x559039: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055903b: { // 0x55903b: 7503 JNZ 0x00559040
    if(integer::condition("JNZ",flags)) goto L00559040;
  }
  L0055903d: { // 0x55903d: 83cd08 OR EBP,0x8
    s.bp = integer::logical((s.bp)|(0x00000008u),32,flags);
  }
  L00559040: { // 0x559040: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00559042: { // 0x559042: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00559044: { // 0x559044: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00559048: { // 0x559048: e8e31cedff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5607501u); flags=s.arithmetic_flags;
  }
  L0055904d: { // 0x55904d: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00559051: { // 0x559051: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00559052: { // 0x559052: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00559053: { // 0x559053: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00559057: { // 0x559057: e8741dedff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5607516u); flags=s.arithmetic_flags;
  }
  L0055905c: { // 0x55905c: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0055905e: { // 0x55905e: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00559062: { // 0x559062: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00559063: { // 0x559063: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00559068: { // 0x559068: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L0055906c: { // 0x55906c: e8cfeefeff CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5607537u); flags=s.arithmetic_flags;
  }
  L00559071: { // 0x559071: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00559073: { // 0x559073: 741e JZ 0x00559093
    if(integer::condition("JZ",flags)) goto L00559093;
  }
  L00559075: { // 0x559075: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00559079: { // 0x559079: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0055907c: { // 0x55907c: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L00559083: { // 0x559083: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00559085: { // 0x559085: 750c JNZ 0x00559093
    if(integer::condition("JNZ",flags)) goto L00559093;
  }
  L00559087: { // 0x559087: e85421f2ff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5607564u); flags=s.arithmetic_flags;
  }
  L0055908c: { // 0x55908c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055908e: { // 0x55908e: 7503 JNZ 0x00559093
    if(integer::condition("JNZ",flags)) goto L00559093;
  }
  L00559090: { // 0x559090: 83cd04 OR EBP,0x4
    s.bp = integer::logical((s.bp)|(0x00000004u),32,flags);
  }
  L00559093: { // 0x559093: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00559095: { // 0x559095: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00559096: { // 0x559096: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00559097: { // 0x559097: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00559098: { // 0x559098: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00559099: { // 0x559099: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0055909c: { // 0x55909c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0055909f: { // 0x55909f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005590a0: { // 0x5590a0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005590a2: { // 0x5590a2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005590a3: { // 0x5590a3: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L005590a6: { // 0x5590a6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0015a200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0055a200: { // 0x55a200: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0055a203: { // 0x55a203: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0055a204: { // 0x55a204: 8b1db8a1a300 MOV EBX,dword ptr [0x00a3a1b8]
    s.bx = m.r32((0x00a3a1b8u));
  }
  L0055a20a: { // 0x55a20a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055a20b: { // 0x55a20b: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L0055a20f: { // 0x55a20f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055a210: { // 0x55a210: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0055a214: { // 0x55a214: 8b7524 MOV ESI,dword ptr [EBP + 0x24]
    s.si = m.r32((s.bp+0x00000024u));
  }
  L0055a217: { // 0x55a217: 8d430e LEA EAX,[EBX + 0xe]
    s.ax = (s.bx+0x0000000eu);
  }
  L0055a21a: { // 0x55a21a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0055a21b: { // 0x55a21b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0055a21d: { // 0x55a21d: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L0055a225: { // 0x55a225: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0055a229: { // 0x55a229: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0055a22d: { // 0x55a22d: e83efcf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612082u); flags=s.arithmetic_flags;
  }
  L0055a232: { // 0x55a232: 8b0d3486a500 MOV ECX,dword ptr [0x00a58634]
    s.cx = m.r32((0x00a58634u));
  }
  L0055a238: { // 0x55a238: 88442424 MOV byte ptr [ESP + 0x24],AL
    m.w8((f.sp+0x00000024u), (s.ax & 0xffu));
  }
  L0055a23c: { // 0x55a23c: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0055a23f: { // 0x55a23f: 0fbf742416 MOVSX ESI,word ptr [ESP + 0x16]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0055a244: { // 0x55a244: 8d043e LEA EAX,[ESI + EDI*0x1]
    s.ax = (s.si+(s.di * 0x00000001u));
  }
  L0055a247: { // 0x55a247: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0055a249: { // 0x55a249: 7e18 JLE 0x0055a263
    if(integer::condition("JLE",flags)) goto L0055a263;
  }
  L0055a24b: { // 0x55a24b: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0055a24d: { // 0x55a24d: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0055a24f: { // 0x55a24f: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0055a251: { // 0x55a251: 7d10 JGE 0x0055a263
    if(integer::condition("JGE",flags)) goto L0055a263;
  }
  L0055a253: { // 0x55a253: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0055a255: { // 0x55a255: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0055a257: { // 0x55a257: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0055a259: { // 0x55a259: 7d08 JGE 0x0055a263
    if(integer::condition("JGE",flags)) goto L0055a263;
  }
  L0055a25b: { // 0x55a25b: 3b053886a500 CMP EAX,dword ptr [0x00a58638]
    (void)integer::sub(s.ax,m.r32((0x00a58638u)),32,flags);
  }
  L0055a261: { // 0x55a261: 7e0c JLE 0x0055a26f
    if(integer::condition("JLE",flags)) goto L0055a26f;
  }
  L0055a263: { // 0x55a263: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055a264: { // 0x55a264: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055a265: { // 0x55a265: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055a266: { // 0x55a266: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0055a268: { // 0x55a268: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055a269: { // 0x55a269: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0055a26c: { // 0x55a26c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055a26f: { // 0x55a26f: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0055a273: { // 0x55a273: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055a275: { // 0x55a275: 7517 JNZ 0x0055a28e
    if(integer::condition("JNZ",flags)) goto L0055a28e;
  }
  L0055a277: { // 0x55a277: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0055a279: { // 0x55a279: e8120ff2ff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5612158u); flags=s.arithmetic_flags;
  }
  L0055a27e: { // 0x55a27e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a280: { // 0x55a280: 752a JNZ 0x0055a2ac
    if(integer::condition("JNZ",flags)) goto L0055a2ac;
  }
  L0055a282: { // 0x55a282: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055a283: { // 0x55a283: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055a284: { // 0x55a284: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055a285: { // 0x55a285: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0055a287: { // 0x55a287: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055a288: { // 0x55a288: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0055a28b: { // 0x55a28b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055a28e: { // 0x55a28e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0055a291: { // 0x55a291: 7519 JNZ 0x0055a2ac
    if(integer::condition("JNZ",flags)) goto L0055a2ac;
  }
  L0055a293: { // 0x55a293: 8b4538 MOV EAX,dword ptr [EBP + 0x38]
    s.ax = m.r32((s.bp+0x00000038u));
  }
  L0055a296: { // 0x55a296: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0055a298: { // 0x55a298: 7c12 JL 0x0055a2ac
    if(integer::condition("JL",flags)) goto L0055a2ac;
  }
  L0055a29a: { // 0x55a29a: 3b442418 CMP EAX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0055a29e: { // 0x55a29e: 7d0c JGE 0x0055a2ac
    if(integer::condition("JGE",flags)) goto L0055a2ac;
  }
  L0055a2a0: { // 0x55a2a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055a2a1: { // 0x55a2a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055a2a2: { // 0x55a2a2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055a2a3: { // 0x55a2a3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0055a2a5: { // 0x55a2a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055a2a6: { // 0x55a2a6: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0055a2a9: { // 0x55a2a9: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055a2ac: { // 0x55a2ac: 8b4524 MOV EAX,dword ptr [EBP + 0x24]
    s.ax = m.r32((s.bp+0x00000024u));
  }
  L0055a2af: { // 0x55a2af: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0055a2b3: { // 0x55a2b3: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0055a2b7: { // 0x55a2b7: e8d4060100 CALL 0x0056a990
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056a990u,5612220u); flags=s.arithmetic_flags;
  }
  L0055a2bc: { // 0x55a2bc: 8a484a MOV CL,byte ptr [EAX + 0x4a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000004au)));
  }
  L0055a2bf: { // 0x55a2bf: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0055a2c1: { // 0x55a2c1: 750c JNZ 0x0055a2cf
    if(integer::condition("JNZ",flags)) goto L0055a2cf;
  }
  L0055a2c3: { // 0x55a2c3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055a2c4: { // 0x55a2c4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055a2c5: { // 0x55a2c5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055a2c6: { // 0x55a2c6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0055a2c8: { // 0x55a2c8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055a2c9: { // 0x55a2c9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0055a2cc: { // 0x55a2cc: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055a2cf: { // 0x55a2cf: 8b4040 MOV EAX,dword ptr [EAX + 0x40]
    s.ax = m.r32((s.ax+0x00000040u));
  }
  L0055a2d2: { // 0x55a2d2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055a2d4: { // 0x55a2d4: 0f8d41010000 JGE 0x0055a41b
    if(integer::condition("JGE",flags)) goto L0055a41b;
  }
  L0055a2da: { // 0x55a2da: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0055a2de: { // 0x55a2de: c1e609 SHL ESI,0x9
    s.si = integer::shift(s.si,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055a2e1: { // 0x55a2e1: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L0055a2e7: { // 0x55a2e7: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0055a2e9: { // 0x55a2e9: 8b8cb2fcf7ffff MOV ECX,dword ptr [EDX + ESI*0x4 + 0xfffff7fc]
    s.cx = m.r32((s.dx+(s.si * 0x00000004u)+0xfffff7fcu));
  }
  L0055a2f0: { // 0x55a2f0: 8db4b2fcf7ffff LEA ESI,[EDX + ESI*0x4 + 0xfffff7fc]
    s.si = (s.dx+(s.si * 0x00000004u)+0xfffff7fcu);
  }
  L0055a2f7: { // 0x55a2f7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a2f9: { // 0x55a2f9: 7409 JZ 0x0055a304
    if(integer::condition("JZ",flags)) goto L0055a304;
  }
  L0055a2fb: { // 0x55a2fb: e870fbf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612288u); flags=s.arithmetic_flags;
  }
  L0055a300: { // 0x55a300: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a302: { // 0x55a302: 7514 JNZ 0x0055a318
    if(integer::condition("JNZ",flags)) goto L0055a318;
  }
  L0055a304: { // 0x55a304: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a307: { // 0x55a307: 751a JNZ 0x0055a323
    if(integer::condition("JNZ",flags)) goto L0055a323;
  }
  L0055a309: { // 0x55a309: 8a5c2424 MOV BL,byte ptr [ESP + 0x24]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000024u)));
  }
  L0055a30d: { // 0x55a30d: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a30f: { // 0x55a30f: 741c JZ 0x0055a32d
    if(integer::condition("JZ",flags)) goto L0055a32d;
  }
  L0055a311: { // 0x55a311: bf40000000 MOV EDI,0x40
    s.di = 0x00000040u;
  }
  L0055a316: { // 0x55a316: eb19 JMP 0x0055a331
    goto L0055a331;
  }
  L0055a318: { // 0x55a318: 8a5c2424 MOV BL,byte ptr [ESP + 0x24]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000024u)));
  }
  L0055a31c: { // 0x55a31c: bf40000000 MOV EDI,0x40
    s.di = 0x00000040u;
  }
  L0055a321: { // 0x55a321: eb0e JMP 0x0055a331
    goto L0055a331;
  }
  L0055a323: { // 0x55a323: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0055a327: { // 0x55a327: 8a5c2424 MOV BL,byte ptr [ESP + 0x24]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000024u)));
  }
  L0055a32b: { // 0x55a32b: eb04 JMP 0x0055a331
    goto L0055a331;
  }
  L0055a32d: { // 0x55a32d: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0055a331: { // 0x55a331: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0055a334: { // 0x55a334: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0055a337: { // 0x55a337: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a339: { // 0x55a339: 7409 JZ 0x0055a344
    if(integer::condition("JZ",flags)) goto L0055a344;
  }
  L0055a33b: { // 0x55a33b: e830fbf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612352u); flags=s.arithmetic_flags;
  }
  L0055a340: { // 0x55a340: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a342: { // 0x55a342: 7509 JNZ 0x0055a34d
    if(integer::condition("JNZ",flags)) goto L0055a34d;
  }
  L0055a344: { // 0x55a344: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a347: { // 0x55a347: 750a JNZ 0x0055a353
    if(integer::condition("JNZ",flags)) goto L0055a353;
  }
  L0055a349: { // 0x55a349: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a34b: { // 0x55a34b: 7406 JZ 0x0055a353
    if(integer::condition("JZ",flags)) goto L0055a353;
  }
  L0055a34d: { // 0x55a34d: 81cf80000000 OR EDI,0x80
    s.di = integer::logical((s.di)|(0x00000080u),32,flags);
  }
  L0055a353: { // 0x55a353: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0055a356: { // 0x55a356: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0055a359: { // 0x55a359: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a35b: { // 0x55a35b: 7409 JZ 0x0055a366
    if(integer::condition("JZ",flags)) goto L0055a366;
  }
  L0055a35d: { // 0x55a35d: e80efbf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612386u); flags=s.arithmetic_flags;
  }
  L0055a362: { // 0x55a362: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a364: { // 0x55a364: 7509 JNZ 0x0055a36f
    if(integer::condition("JNZ",flags)) goto L0055a36f;
  }
  L0055a366: { // 0x55a366: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a369: { // 0x55a369: 7507 JNZ 0x0055a372
    if(integer::condition("JNZ",flags)) goto L0055a372;
  }
  L0055a36b: { // 0x55a36b: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a36d: { // 0x55a36d: 7403 JZ 0x0055a372
    if(integer::condition("JZ",flags)) goto L0055a372;
  }
  L0055a36f: { // 0x55a36f: 83cf01 OR EDI,0x1
    s.di = integer::logical((s.di)|(0x00000001u),32,flags);
  }
  L0055a372: { // 0x55a372: 8b8ef8070000 MOV ECX,dword ptr [ESI + 0x7f8]
    s.cx = m.r32((s.si+0x000007f8u));
  }
  L0055a378: { // 0x55a378: 81c6f8070000 ADD ESI,0x7f8
    s.si = integer::add(s.si,0x000007f8u,32,flags);
  }
  L0055a37e: { // 0x55a37e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a380: { // 0x55a380: 7409 JZ 0x0055a38b
    if(integer::condition("JZ",flags)) goto L0055a38b;
  }
  L0055a382: { // 0x55a382: e8e9faf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612423u); flags=s.arithmetic_flags;
  }
  L0055a387: { // 0x55a387: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a389: { // 0x55a389: 7509 JNZ 0x0055a394
    if(integer::condition("JNZ",flags)) goto L0055a394;
  }
  L0055a38b: { // 0x55a38b: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a38e: { // 0x55a38e: 7507 JNZ 0x0055a397
    if(integer::condition("JNZ",flags)) goto L0055a397;
  }
  L0055a390: { // 0x55a390: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a392: { // 0x55a392: 7403 JZ 0x0055a397
    if(integer::condition("JZ",flags)) goto L0055a397;
  }
  L0055a394: { // 0x55a394: 83cf20 OR EDI,0x20
    s.di = integer::logical((s.di)|(0x00000020u),32,flags);
  }
  L0055a397: { // 0x55a397: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0055a39a: { // 0x55a39a: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  L0055a39d: { // 0x55a39d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a39f: { // 0x55a39f: 7409 JZ 0x0055a3aa
    if(integer::condition("JZ",flags)) goto L0055a3aa;
  }
  L0055a3a1: { // 0x55a3a1: e8cafaf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612454u); flags=s.arithmetic_flags;
  }
  L0055a3a6: { // 0x55a3a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a3a8: { // 0x55a3a8: 7509 JNZ 0x0055a3b3
    if(integer::condition("JNZ",flags)) goto L0055a3b3;
  }
  L0055a3aa: { // 0x55a3aa: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a3ad: { // 0x55a3ad: 7507 JNZ 0x0055a3b6
    if(integer::condition("JNZ",flags)) goto L0055a3b6;
  }
  L0055a3af: { // 0x55a3af: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a3b1: { // 0x55a3b1: 7403 JZ 0x0055a3b6
    if(integer::condition("JZ",flags)) goto L0055a3b6;
  }
  L0055a3b3: { // 0x55a3b3: 83cf02 OR EDI,0x2
    s.di = integer::logical((s.di)|(0x00000002u),32,flags);
  }
  L0055a3b6: { // 0x55a3b6: 8b8ef8070000 MOV ECX,dword ptr [ESI + 0x7f8]
    s.cx = m.r32((s.si+0x000007f8u));
  }
  L0055a3bc: { // 0x55a3bc: 81c6f8070000 ADD ESI,0x7f8
    s.si = integer::add(s.si,0x000007f8u,32,flags);
  }
  L0055a3c2: { // 0x55a3c2: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a3c4: { // 0x55a3c4: 7409 JZ 0x0055a3cf
    if(integer::condition("JZ",flags)) goto L0055a3cf;
  }
  L0055a3c6: { // 0x55a3c6: e8a5faf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612491u); flags=s.arithmetic_flags;
  }
  L0055a3cb: { // 0x55a3cb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a3cd: { // 0x55a3cd: 7509 JNZ 0x0055a3d8
    if(integer::condition("JNZ",flags)) goto L0055a3d8;
  }
  L0055a3cf: { // 0x55a3cf: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a3d2: { // 0x55a3d2: 7507 JNZ 0x0055a3db
    if(integer::condition("JNZ",flags)) goto L0055a3db;
  }
  L0055a3d4: { // 0x55a3d4: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a3d6: { // 0x55a3d6: 7403 JZ 0x0055a3db
    if(integer::condition("JZ",flags)) goto L0055a3db;
  }
  L0055a3d8: { // 0x55a3d8: 83cf10 OR EDI,0x10
    s.di = integer::logical((s.di)|(0x00000010u),32,flags);
  }
  L0055a3db: { // 0x55a3db: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0055a3de: { // 0x55a3de: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0055a3e1: { // 0x55a3e1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a3e3: { // 0x55a3e3: 7409 JZ 0x0055a3ee
    if(integer::condition("JZ",flags)) goto L0055a3ee;
  }
  L0055a3e5: { // 0x55a3e5: e886faf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612522u); flags=s.arithmetic_flags;
  }
  L0055a3ea: { // 0x55a3ea: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a3ec: { // 0x55a3ec: 7509 JNZ 0x0055a3f7
    if(integer::condition("JNZ",flags)) goto L0055a3f7;
  }
  L0055a3ee: { // 0x55a3ee: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a3f1: { // 0x55a3f1: 7507 JNZ 0x0055a3fa
    if(integer::condition("JNZ",flags)) goto L0055a3fa;
  }
  L0055a3f3: { // 0x55a3f3: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a3f5: { // 0x55a3f5: 7403 JZ 0x0055a3fa
    if(integer::condition("JZ",flags)) goto L0055a3fa;
  }
  L0055a3f7: { // 0x55a3f7: 83cf08 OR EDI,0x8
    s.di = integer::logical((s.di)|(0x00000008u),32,flags);
  }
  L0055a3fa: { // 0x55a3fa: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0055a3fd: { // 0x55a3fd: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0055a400: { // 0x55a400: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055a402: { // 0x55a402: 7409 JZ 0x0055a40d
    if(integer::condition("JZ",flags)) goto L0055a40d;
  }
  L0055a404: { // 0x55a404: e867faf1ff CALL 0x00479e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e70u,5612553u); flags=s.arithmetic_flags;
  }
  L0055a409: { // 0x55a409: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055a40b: { // 0x55a40b: 7509 JNZ 0x0055a416
    if(integer::condition("JNZ",flags)) goto L0055a416;
  }
  L0055a40d: { // 0x55a40d: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  L0055a410: { // 0x55a410: 7507 JNZ 0x0055a419
    if(integer::condition("JNZ",flags)) goto L0055a419;
  }
  L0055a412: { // 0x55a412: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0055a414: { // 0x55a414: 7403 JZ 0x0055a419
    if(integer::condition("JZ",flags)) goto L0055a419;
  }
  L0055a416: { // 0x55a416: 83cf04 OR EDI,0x4
    s.di = integer::logical((s.di)|(0x00000004u),32,flags);
  }
  L0055a419: { // 0x55a419: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0055a41b: { // 0x55a41b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055a41c: { // 0x55a41c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055a41d: { // 0x55a41d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055a41e: { // 0x55a41e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055a41f: { // 0x55a41f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0055a422: { // 0x55a422: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00161d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00561d60: { // 0x561d60: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  L00561d64: { // 0x561d64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00561d65: { // 0x561d65: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L00561d69: { // 0x561d69: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00561d6a: { // 0x561d6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00561d6b: { // 0x561d6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561d6c: { // 0x561d6c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00561d6e: { // 0x561d6e: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00561d70: { // 0x561d70: 0f8446020000 JZ 0x00561fbc
    if(integer::condition("JZ",flags)) goto L00561fbc;
  }
  L00561d76: { // 0x561d76: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00561d7c: { // 0x561d7c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00561d7f: { // 0x561d7f: 0f8437020000 JZ 0x00561fbc
    if(integer::condition("JZ",flags)) goto L00561fbc;
  }
  L00561d85: { // 0x561d85: 8d7b24 LEA EDI,[EBX + 0x24]
    s.di = (s.bx+0x00000024u);
  }
  L00561d88: { // 0x561d88: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00561d8a: { // 0x561d8a: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00561d8c: { // 0x561d8c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561d8d: { // 0x561d8d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00561d92: { // 0x561d92: e8c9b7feff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5643671u); flags=s.arithmetic_flags;
  }
  L00561d97: { // 0x561d97: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00561d99: { // 0x561d99: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L00561d9c: { // 0x561d9c: 753a JNZ 0x00561dd8
    if(integer::condition("JNZ",flags)) goto L00561dd8;
  }
  L00561d9e: { // 0x561d9e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561d9f: { // 0x561d9f: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00561da3: { // 0x561da3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561da4: { // 0x561da4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00561da5: { // 0x561da5: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00561da7: { // 0x561da7: e804040000 CALL 0x005621b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005621b0u,5643692u); flags=s.arithmetic_flags;
  }
  L00561dac: { // 0x561dac: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00561dae: { // 0x561dae: 663b055c6ea500 CMP AX,word ptr [0x00a56e5c]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a56e5cu)),16,flags);
  }
  L00561db5: { // 0x561db5: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00561db9: { // 0x561db9: 750e JNZ 0x00561dc9
    if(integer::condition("JNZ",flags)) goto L00561dc9;
  }
  L00561dbb: { // 0x561dbb: 668b4c241e MOV CX,word ptr [ESP + 0x1e]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000001eu)));
  }
  L00561dc0: { // 0x561dc0: 663b0d5e6ea500 CMP CX,word ptr [0x00a56e5e]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a56e5eu)),16,flags);
  }
  L00561dc7: { // 0x561dc7: 740f JZ 0x00561dd8
    if(integer::condition("JZ",flags)) goto L00561dd8;
  }
  L00561dc9: { // 0x561dc9: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00561dcd: { // 0x561dcd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561dce: { // 0x561dce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561dcf: { // 0x561dcf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561dd0: { // 0x561dd0: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00561dd2: { // 0x561dd2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00561dd4: { // 0x561dd4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561dd5: { // 0x561dd5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00561dd8: { // 0x561dd8: 8b1570a88100 MOV EDX,dword ptr [0x0081a870]
    s.dx = m.r32((0x0081a870u));
  }
  L00561dde: { // 0x561dde: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00561de4: { // 0x561de4: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  L00561de7: { // 0x561de7: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00561de9: { // 0x561de9: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00561dec: { // 0x561dec: 741a JZ 0x00561e08
    if(integer::condition("JZ",flags)) goto L00561e08;
  }
  L00561dee: { // 0x561dee: 668b5326 MOV DX,word ptr [EBX + 0x26]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000026u)));
  }
  L00561df2: { // 0x561df2: 66c744241c0000 MOV word ptr [ESP + 0x1c],0x0
    m.w16((f.sp+0x0000001cu), 0x00000000u);
  }
  L00561df9: { // 0x561df9: 662b5602 SUB DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L00561dfd: { // 0x561dfd: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00561e02: { // 0x561e02: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L00561e06: { // 0x561e06: eb16 JMP 0x00561e1e
    goto L00561e1e;
  }
  L00561e08: { // 0x561e08: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L00561e0b: { // 0x561e0b: 66c744241e0000 MOV word ptr [ESP + 0x1e],0x0
    m.w16((f.sp+0x0000001eu), 0x00000000u);
  }
  L00561e12: { // 0x561e12: 662b0e SUB CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00561e15: { // 0x561e15: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00561e1a: { // 0x561e1a: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L00561e1e: { // 0x561e1e: 8a4e08 MOV CL,byte ptr [ESI + 0x8]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000008u)));
  }
  L00561e21: { // 0x561e21: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00561e25: { // 0x561e25: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00561e27: { // 0x561e27: 0f84ef000000 JZ 0x00561f1c
    if(integer::condition("JZ",flags)) goto L00561f1c;
  }
  L00561e2d: { // 0x561e2d: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L00561e31: { // 0x561e31: 668b5c241e MOV BX,word ptr [ESP + 0x1e]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x0000001eu)));
  }
  L00561e36: { // 0x561e36: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L00561e39: { // 0x561e39: 6603cb ADD CX,BX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561e3c: { // 0x561e3c: 662b4f02 SUB CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00561e40: { // 0x561e40: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561e43: { // 0x561e43: 662b07 SUB AX,word ptr [EDI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.di)),16,flags));
  }
  L00561e46: { // 0x561e46: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00561e49: { // 0x561e49: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00561e4c: { // 0x561e4c: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00561e4f: { // 0x561e4f: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00561e53: { // 0x561e53: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561e57: { // 0x561e57: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00561e5b: { // 0x561e5b: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561e5f: { // 0x561e5f: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00561e61: { // 0x561e61: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00561e63: { // 0x561e63: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00561e65: { // 0x561e65: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00561e67: { // 0x561e67: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00561e69: { // 0x561e69: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00561e6c: { // 0x561e6c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561e6e: { // 0x561e6e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561e70: { // 0x561e70: e80b82f5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5643893u); flags=s.arithmetic_flags;
  }
  L00561e75: { // 0x561e75: e8d68b2000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5643898u); flags=s.arithmetic_flags;
  }
  L00561e7a: { // 0x561e7a: 668b4e06 MOV CX,word ptr [ESI + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000006u)));
  }
  L00561e7e: { // 0x561e7e: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00561e82: { // 0x561e82: 668b4604 MOV AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000004u)));
  }
  L00561e86: { // 0x561e86: 6603cb ADD CX,BX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561e89: { // 0x561e89: 662b4f02 SUB CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L00561e8d: { // 0x561e8d: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561e90: { // 0x561e90: 662b07 SUB AX,word ptr [EDI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.di)),16,flags));
  }
  L00561e93: { // 0x561e93: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00561e96: { // 0x561e96: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00561e99: { // 0x561e99: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00561e9d: { // 0x561e9d: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561ea1: { // 0x561ea1: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00561ea5: { // 0x561ea5: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00561ea9: { // 0x561ea9: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00561eab: { // 0x561eab: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00561ead: { // 0x561ead: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00561eaf: { // 0x561eaf: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00561eb1: { // 0x561eb1: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00561eb3: { // 0x561eb3: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00561eb6: { // 0x561eb6: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561eb8: { // 0x561eb8: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00561eba: { // 0x561eba: e8c181f5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5643967u); flags=s.arithmetic_flags;
  }
  L00561ebf: { // 0x561ebf: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00561ec2: { // 0x561ec2: e8898b2000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5643975u); flags=s.arithmetic_flags;
  }
  L00561ec7: { // 0x561ec7: 6639442418 CMP word ptr [ESP + 0x18],AX
    (void)integer::sub(m.r16((f.sp+0x00000018u)),(s.ax & 0xffffu),16,flags);
  }
  L00561ecc: { // 0x561ecc: 7d28 JGE 0x00561ef6
    if(integer::condition("JGE",flags)) goto L00561ef6;
  }
  L00561ece: { // 0x561ece: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L00561ed1: { // 0x561ed1: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L00561ed5: { // 0x561ed5: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561ed8: { // 0x561ed8: 6603cb ADD CX,BX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561edb: { // 0x561edb: 668944241c MOV word ptr [ESP + 0x1c],AX
    m.w16((f.sp+0x0000001cu), (s.ax & 0xffffu));
  }
  L00561ee0: { // 0x561ee0: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00561ee4: { // 0x561ee4: 66894c241e MOV word ptr [ESP + 0x1e],CX
    m.w16((f.sp+0x0000001eu), (s.cx & 0xffffu));
  }
  L00561ee9: { // 0x561ee9: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00561eed: { // 0x561eed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561eee: { // 0x561eee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561eef: { // 0x561eef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561ef0: { // 0x561ef0: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00561ef2: { // 0x561ef2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561ef3: { // 0x561ef3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00561ef6: { // 0x561ef6: 668b4606 MOV AX,word ptr [ESI + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000006u)));
  }
  L00561efa: { // 0x561efa: 66036e04 ADD BP,word ptr [ESI + 0x4]
    s.bp = (s.bp & 0xffff0000u) | ((integer::add((s.bp & 0xffffu),m.r16((s.si+0x00000004u)),16,flags)) & 0xffffu);
  }
  L00561efe: { // 0x561efe: 6603c3 ADD AX,BX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00561f01: { // 0x561f01: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561f02: { // 0x561f02: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L00561f07: { // 0x561f07: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00561f0b: { // 0x561f0b: 66896c2418 MOV word ptr [ESP + 0x18],BP
    m.w16((f.sp+0x00000018u), (s.bp & 0xffffu));
  }
  L00561f10: { // 0x561f10: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00561f14: { // 0x561f14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561f15: { // 0x561f15: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561f16: { // 0x561f16: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00561f18: { // 0x561f18: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561f19: { // 0x561f19: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00561f1c: { // 0x561f1c: 668b3e MOV DI,word ptr [ESI]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.si))) & 0xffffu);
  }
  L00561f1f: { // 0x561f1f: 662b7e04 SUB DI,word ptr [ESI + 0x4]
    s.di = (s.di & 0xffff0000u) | ((integer::sub((s.di & 0xffffu),m.r16((s.si+0x00000004u)),16,flags)) & 0xffffu);
  }
  L00561f23: { // 0x561f23: 66f7df NEG DI
    s.di = (s.di & 0xffff0000u) | ((integer::sub(0u,(s.di & 0xffffu),16,flags)) & 0xffffu);
  }
  L00561f26: { // 0x561f26: 1bff SBB EDI,EDI
    s.di = integer::sub(s.di,s.di,32,flags,flags&integer::CF);
  }
  L00561f28: { // 0x561f28: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L00561f2b: { // 0x561f2b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00561f2e: { // 0x561f2e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00561f31: { // 0x561f31: 7415 JZ 0x00561f48
    if(integer::condition("JZ",flags)) goto L00561f48;
  }
  L00561f33: { // 0x561f33: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00561f34: { // 0x561f34: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00561f36: { // 0x561f36: e88547f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5644091u); flags=s.arithmetic_flags;
  }
  L00561f3b: { // 0x561f3b: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00561f3d: { // 0x561f3d: 8b8340010000 MOV EAX,dword ptr [EBX + 0x140]
    s.ax = m.r32((s.bx+0x00000140u));
  }
  L00561f43: { // 0x561f43: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00561f46: { // 0x561f46: 75eb JNZ 0x00561f33
    if(integer::condition("JNZ",flags)) goto L00561f33;
  }
  L00561f48: { // 0x561f48: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00561f4a: { // 0x561f4a: e81196f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5644111u); flags=s.arithmetic_flags;
  }
  L00561f4f: { // 0x561f4f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00561f51: { // 0x561f51: 750b JNZ 0x00561f5e
    if(integer::condition("JNZ",flags)) goto L00561f5e;
  }
  L00561f53: { // 0x561f53: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00561f55: { // 0x561f55: e82696f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5644122u); flags=s.arithmetic_flags;
  }
  L00561f5a: { // 0x561f5a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00561f5c: { // 0x561f5c: 7434 JZ 0x00561f92
    if(integer::condition("JZ",flags)) goto L00561f92;
  }
  L00561f5e: { // 0x561f5e: 83bbec00000003 CMP dword ptr [EBX + 0xec],0x3
    (void)integer::sub(m.r32((s.bx+0x000000ecu)),0x00000003u,32,flags);
  }
  L00561f65: { // 0x561f65: 742b JZ 0x00561f92
    if(integer::condition("JZ",flags)) goto L00561f92;
  }
  L00561f67: { // 0x561f67: 668b5604 MOV DX,word ptr [ESI + 0x4]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000004u)));
  }
  L00561f6b: { // 0x561f6b: 668b4606 MOV AX,word ptr [ESI + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000006u)));
  }
  L00561f6f: { // 0x561f6f: 6603d5 ADD DX,BP
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561f72: { // 0x561f72: 660344241e ADD AX,word ptr [ESP + 0x1e]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags));
  }
  L00561f77: { // 0x561f77: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L00561f7c: { // 0x561f7c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561f7d: { // 0x561f7d: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L00561f82: { // 0x561f82: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00561f86: { // 0x561f86: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00561f8a: { // 0x561f8a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561f8b: { // 0x561f8b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561f8c: { // 0x561f8c: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00561f8e: { // 0x561f8e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561f8f: { // 0x561f8f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00561f92: { // 0x561f92: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L00561f95: { // 0x561f95: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L00561f99: { // 0x561f99: 6603d5 ADD DX,BP
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00561f9c: { // 0x561f9c: 660344241e ADD AX,word ptr [ESP + 0x1e]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000001eu)),16,flags));
  }
  L00561fa1: { // 0x561fa1: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L00561fa6: { // 0x561fa6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561fa7: { // 0x561fa7: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L00561fac: { // 0x561fac: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00561fb0: { // 0x561fb0: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00561fb4: { // 0x561fb4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561fb5: { // 0x561fb5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561fb6: { // 0x561fb6: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00561fb8: { // 0x561fb8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561fb9: { // 0x561fb9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00561fbc: { // 0x561fbc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00561fc0: { // 0x561fc0: 8b5324 MOV EDX,dword ptr [EBX + 0x24]
    s.dx = m.r32((s.bx+0x00000024u));
  }
  L00561fc3: { // 0x561fc3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00561fc4: { // 0x561fc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00561fc5: { // 0x561fc5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561fc6: { // 0x561fc6: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00561fc8: { // 0x561fc8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00561fc9: { // 0x561fc9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_001621b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005621b0: { // 0x5621b0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005621b4: { // 0x5621b4: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005621b7: { // 0x5621b7: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L005621bb: { // 0x5621bb: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L005621be: { // 0x5621be: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005621c1: { // 0x5621c1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005621c3: { // 0x5621c3: 7818 JS 0x005621dd
    if(integer::condition("JS",flags)) goto L005621dd;
  }
  L005621c5: { // 0x5621c5: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005621ca: { // 0x5621ca: 7d11 JGE 0x005621dd
    if(integer::condition("JGE",flags)) goto L005621dd;
  }
  L005621cc: { // 0x5621cc: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005621d2: { // 0x5621d2: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L005621d5: { // 0x5621d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005621d7: { // 0x5621d7: 7404 JZ 0x005621dd
    if(integer::condition("JZ",flags)) goto L005621dd;
  }
  L005621d9: { // 0x5621d9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005621db: { // 0x5621db: eb0c JMP 0x005621e9
    goto L005621e9;
  }
  L005621dd: { // 0x5621dd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005621df: { // 0x5621df: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L005621e4: { // 0x5621e4: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005621e9: { // 0x5621e9: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L005621ef: { // 0x5621ef: 8d9140010000 LEA EDX,[ECX + 0x140]
    s.dx = (s.cx+0x00000140u);
  }
  L005621f5: { // 0x5621f5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005621f8: { // 0x5621f8: 750f JNZ 0x00562209
    if(integer::condition("JNZ",flags)) goto L00562209;
  }
  L005621fa: { // 0x5621fa: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005621fe: { // 0x5621fe: 8b4924 MOV ECX,dword ptr [ECX + 0x24]
    s.cx = m.r32((s.cx+0x00000024u));
  }
  L00562201: { // 0x562201: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00562203: { // 0x562203: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00562206: { // 0x562206: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00562209: { // 0x562209: 2500080000 AND EAX,0x800
    s.ax = integer::logical((s.ax)&(0x00000800u),32,flags);
  }
  L0056220e: { // 0x56220e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056220f: { // 0x56220f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00562211: { // 0x562211: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00562213: { // 0x562213: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00562214: { // 0x562214: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00562216: { // 0x562216: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00562217: { // 0x562217: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0056221a: { // 0x56221a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056221b: { // 0x56221b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0056221d: { // 0x56221d: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00562221: { // 0x562221: 8d70fc LEA ESI,[EAX + -0x4]
    s.si = (s.ax-0x00000004u);
  }
  L00562224: { // 0x562224: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00562226: { // 0x562226: 83e607 AND ESI,0x7
    s.si = integer::logical((s.si)&(0x00000007u),32,flags);
  }
  L00562229: { // 0x562229: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0056222b: { // 0x56222b: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0056222f: { // 0x56222f: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00562231: { // 0x562231: 8b0d5c6ea500 MOV ECX,dword ptr [0x00a56e5c]
    s.cx = m.r32((0x00a56e5cu));
  }
  L00562237: { // 0x562237: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056223b: { // 0x56223b: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0056223f: { // 0x56223f: eb04 JMP 0x00562245
    goto L00562245;
  }
  L00562241: { // 0x562241: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00562245: { // 0x562245: 8b4d00 MOV ECX,dword ptr [EBP]
    s.cx = m.r32((s.bp));
  }
  L00562248: { // 0x562248: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0056224b: { // 0x56224b: 7441 JZ 0x0056228e
    if(integer::condition("JZ",flags)) goto L0056228e;
  }
  L0056224d: { // 0x56224d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056224e: { // 0x56224e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00562250: { // 0x562250: e86b44f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5644885u); flags=s.arithmetic_flags;
  }
  L00562255: { // 0x562255: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00562257: { // 0x562257: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0056225d: { // 0x56225d: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00562260: { // 0x562260: 8daf40010000 LEA EBP,[EDI + 0x140]
    s.bp = (s.di+0x00000140u);
  }
  L00562266: { // 0x562266: 7526 JNZ 0x0056228e
    if(integer::condition("JNZ",flags)) goto L0056228e;
  }
  L00562268: { // 0x562268: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0056226a: { // 0x56226a: e8f192f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5644911u); flags=s.arithmetic_flags;
  }
  L0056226f: { // 0x56226f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00562271: { // 0x562271: 750b JNZ 0x0056227e
    if(integer::condition("JNZ",flags)) goto L0056227e;
  }
  L00562273: { // 0x562273: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00562275: { // 0x562275: e80693f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5644922u); flags=s.arithmetic_flags;
  }
  L0056227a: { // 0x56227a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056227c: { // 0x56227c: 7410 JZ 0x0056228e
    if(integer::condition("JZ",flags)) goto L0056228e;
  }
  L0056227e: { // 0x56227e: 83bfec00000003 CMP dword ptr [EDI + 0xec],0x3
    (void)integer::sub(m.r32((s.di+0x000000ecu)),0x00000003u,32,flags);
  }
  L00562285: { // 0x562285: 7407 JZ 0x0056228e
    if(integer::condition("JZ",flags)) goto L0056228e;
  }
  L00562287: { // 0x562287: 8b5724 MOV EDX,dword ptr [EDI + 0x24]
    s.dx = m.r32((s.di+0x00000024u));
  }
  L0056228a: { // 0x56228a: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0056228e: { // 0x56228e: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00562290: { // 0x562290: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00562293: { // 0x562293: 7450 JZ 0x005622e5
    if(integer::condition("JZ",flags)) goto L005622e5;
  }
  L00562295: { // 0x562295: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00562299: { // 0x562299: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056229b: { // 0x56229b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056229c: { // 0x56229c: e81f44f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5644961u); flags=s.arithmetic_flags;
  }
  L005622a1: { // 0x5622a1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005622a3: { // 0x5622a3: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L005622a9: { // 0x5622a9: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005622ac: { // 0x5622ac: 8d9e40010000 LEA EBX,[ESI + 0x140]
    s.bx = (s.si+0x00000140u);
  }
  L005622b2: { // 0x5622b2: 758d JNZ 0x00562241
    if(integer::condition("JNZ",flags)) goto L00562241;
  }
  L005622b4: { // 0x5622b4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005622b6: { // 0x5622b6: e8a592f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5644987u); flags=s.arithmetic_flags;
  }
  L005622bb: { // 0x5622bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005622bd: { // 0x5622bd: 750b JNZ 0x005622ca
    if(integer::condition("JNZ",flags)) goto L005622ca;
  }
  L005622bf: { // 0x5622bf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005622c1: { // 0x5622c1: e8ba92f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5644998u); flags=s.arithmetic_flags;
  }
  L005622c6: { // 0x5622c6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005622c8: { // 0x5622c8: 7410 JZ 0x005622da
    if(integer::condition("JZ",flags)) goto L005622da;
  }
  L005622ca: { // 0x5622ca: 83beec00000003 CMP dword ptr [ESI + 0xec],0x3
    (void)integer::sub(m.r32((s.si+0x000000ecu)),0x00000003u,32,flags);
  }
  L005622d1: { // 0x5622d1: 7407 JZ 0x005622da
    if(integer::condition("JZ",flags)) goto L005622da;
  }
  L005622d3: { // 0x5622d3: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L005622d6: { // 0x5622d6: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005622da: { // 0x5622da: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L005622dc: { // 0x5622dc: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005622df: { // 0x5622df: 0f855cffffff JNZ 0x00562241
    if(integer::condition("JNZ",flags)) goto L00562241;
  }
  L005622e5: { // 0x5622e5: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005622e8: { // 0x5622e8: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005622eb: { // 0x5622eb: 0f8550ffffff JNZ 0x00562241
    if(integer::condition("JNZ",flags)) goto L00562241;
  }
  L005622f1: { // 0x5622f1: 8b1d5c6ea500 MOV EBX,dword ptr [0x00a56e5c]
    s.bx = m.r32((0x00a56e5cu));
  }
  L005622f7: { // 0x5622f7: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005622fb: { // 0x5622fb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005622fd: { // 0x5622fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005622fe: { // 0x5622fe: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00562303: { // 0x562303: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L00562307: { // 0x562307: e84451ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5645068u); flags=s.arithmetic_flags;
  }
  L0056230c: { // 0x56230c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056230e: { // 0x56230e: 7408 JZ 0x00562318
    if(integer::condition("JZ",flags)) goto L00562318;
  }
  L00562310: { // 0x562310: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L00562314: { // 0x562314: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00562318: { // 0x562318: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0056231c: { // 0x56231c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0056231e: { // 0x56231e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056231f: { // 0x56231f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00562324: { // 0x562324: e82751ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5645097u); flags=s.arithmetic_flags;
  }
  L00562329: { // 0x562329: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056232b: { // 0x56232b: 0f84b4000000 JZ 0x005623e5
    if(integer::condition("JZ",flags)) goto L005623e5;
  }
  L00562331: { // 0x562331: 663b1d5c6ea500 CMP BX,word ptr [0x00a56e5c]
    (void)integer::sub((s.bx & 0xffffu),m.r16((0x00a56e5cu)),16,flags);
  }
  L00562338: { // 0x562338: 7512 JNZ 0x0056234c
    if(integer::condition("JNZ",flags)) goto L0056234c;
  }
  L0056233a: { // 0x56233a: 668b4c2416 MOV CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000016u)));
  }
  L0056233f: { // 0x56233f: 663b0d5e6ea500 CMP CX,word ptr [0x00a56e5e]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a56e5eu)),16,flags);
  }
  L00562346: { // 0x562346: 0f8495000000 JZ 0x005623e1
    if(integer::condition("JZ",flags)) goto L005623e1;
  }
  L0056234c: { // 0x56234c: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L00562350: { // 0x562350: 668b4c2412 MOV CX,word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000012u)));
  }
  L00562355: { // 0x562355: 668b442410 MOV AX,word ptr [ESP + 0x10]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000010u)));
  }
  L0056235a: { // 0x56235a: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0056235d: { // 0x56235d: 662b4e02 SUB CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L00562361: { // 0x562361: 662b06 SUB AX,word ptr [ESI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00562364: { // 0x562364: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00562367: { // 0x562367: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056236a: { // 0x56236a: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0056236e: { // 0x56236e: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L00562372: { // 0x562372: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00562376: { // 0x562376: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L0056237a: { // 0x56237a: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0056237c: { // 0x56237c: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0056237e: { // 0x56237e: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00562380: { // 0x562380: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00562382: { // 0x562382: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00562384: { // 0x562384: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00562387: { // 0x562387: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00562389: { // 0x562389: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0056238b: { // 0x56238b: e8f07cf5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5645200u); flags=s.arithmetic_flags;
  }
  L00562390: { // 0x562390: e8bb862000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5645205u); flags=s.arithmetic_flags;
  }
  L00562395: { // 0x562395: 668b4c242e MOV CX,word ptr [ESP + 0x2e]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000002eu)));
  }
  L0056239a: { // 0x56239a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0056239c: { // 0x56239c: 662b4e02 SUB CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L005623a0: { // 0x5623a0: 668b44242c MOV AX,word ptr [ESP + 0x2c]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002cu)));
  }
  L005623a5: { // 0x5623a5: 662b06 SUB AX,word ptr [ESI]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si)),16,flags));
  }
  L005623a8: { // 0x5623a8: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005623ab: { // 0x5623ab: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005623ae: { // 0x5623ae: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L005623b2: { // 0x5623b2: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L005623b6: { // 0x5623b6: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L005623ba: { // 0x5623ba: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L005623be: { // 0x5623be: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L005623c0: { // 0x5623c0: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L005623c2: { // 0x5623c2: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L005623c4: { // 0x5623c4: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L005623c6: { // 0x5623c6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L005623c8: { // 0x5623c8: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005623cb: { // 0x5623cb: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005623cd: { // 0x5623cd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005623cf: { // 0x5623cf: e8ac7cf5ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5645268u); flags=s.arithmetic_flags;
  }
  L005623d4: { // 0x5623d4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005623d7: { // 0x5623d7: e874862000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5645276u); flags=s.arithmetic_flags;
  }
  L005623dc: { // 0x5623dc: 663bf8 CMP DI,AX
    (void)integer::sub((s.di & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L005623df: { // 0x5623df: 7d04 JGE 0x005623e5
    if(integer::condition("JGE",flags)) goto L005623e5;
  }
  L005623e1: { // 0x5623e1: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L005623e5: { // 0x5623e5: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L005623e9: { // 0x5623e9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005623ea: { // 0x5623ea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005623eb: { // 0x5623eb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005623ec: { // 0x5623ec: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005623ee: { // 0x5623ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005623ef: { // 0x5623ef: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005623f2: { // 0x5623f2: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0016a990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056a990: { // 0x56a990: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0056a994: { // 0x56a994: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0056a99b: { // 0x56a99b: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0056a99e: { // 0x56a99e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056a9a0: { // 0x56a9a0: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0056a9a6: { // 0x56a9a6: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0056a9a9: { // 0x56a9a9: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0056a9ac: { // 0x56a9ac: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0056a9ae: { // 0x56a9ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001819d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005819d0: { // 0x5819d0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005819d3: { // 0x5819d3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005819d8: { // 0x5819d8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005819d9: { // 0x5819d9: e86259fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5773790u); flags=s.arithmetic_flags;
  }
  L005819de: { // 0x5819de: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005819e3: { // 0x5819e3: e89858fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5773800u); flags=s.arithmetic_flags;
  }
  L005819e8: { // 0x5819e8: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005819ea: { // 0x5819ea: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005819ec: { // 0x5819ec: 0f84d4010000 JZ 0x00581bc6
    if(integer::condition("JZ",flags)) goto L00581bc6;
  }
  L005819f2: { // 0x5819f2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005819f3: { // 0x5819f3: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005819f4: { // 0x5819f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005819f5: { // 0x5819f5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005819f7: { // 0x5819f7: e8c499efff CALL 0x0047b3c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b3c0u,5773820u); flags=s.arithmetic_flags;
  }
  L005819fc: { // 0x5819fc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005819fe: { // 0x5819fe: 0f84e9000000 JZ 0x00581aed
    if(integer::condition("JZ",flags)) goto L00581aed;
  }
  L00581a04: { // 0x581a04: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00581a0a: { // 0x581a0a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00581a0c: { // 0x581a0c: 8b4724 MOV EAX,dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  L00581a0f: { // 0x581a0f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00581a11: { // 0x581a11: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L00581a14: { // 0x581a14: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00581a18: { // 0x581a18: 6603048da09d8300 ADD AX,word ptr [ECX*0x4 + 0x839da0]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16(((s.cx * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L00581a20: { // 0x581a20: 8d0c8da09d8300 LEA ECX,[ECX*0x4 + 0x839da0]
    s.cx = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  L00581a27: { // 0x581a27: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L00581a2b: { // 0x581a2b: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L00581a30: { // 0x581a30: 66034c2412 ADD CX,word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L00581a35: { // 0x581a35: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L00581a3a: { // 0x581a3a: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00581a3e: { // 0x581a3e: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00581a42: { // 0x581a42: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00581a45: { // 0x581a45: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00581a48: { // 0x581a48: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L00581a4b: { // 0x581a4b: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00581a4d: { // 0x581a4d: 7e36 JLE 0x00581a85
    if(integer::condition("JLE",flags)) goto L00581a85;
  }
  L00581a4f: { // 0x581a4f: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00581a51: { // 0x581a51: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L00581a53: { // 0x581a53: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L00581a55: { // 0x581a55: 7d2e JGE 0x00581a85
    if(integer::condition("JGE",flags)) goto L00581a85;
  }
  L00581a57: { // 0x581a57: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00581a59: { // 0x581a59: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00581a5b: { // 0x581a5b: 7d28 JGE 0x00581a85
    if(integer::condition("JGE",flags)) goto L00581a85;
  }
  L00581a5d: { // 0x581a5d: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00581a63: { // 0x581a63: 7f20 JG 0x00581a85
    if(integer::condition("JG",flags)) goto L00581a85;
  }
  L00581a65: { // 0x581a65: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00581a69: { // 0x581a69: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00581a6e: { // 0x581a6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00581a6f: { // 0x581a6f: e88c3afcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5773940u); flags=s.arithmetic_flags;
  }
  L00581a74: { // 0x581a74: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00581a76: { // 0x581a76: e81597efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5773947u); flags=s.arithmetic_flags;
  }
  L00581a7b: { // 0x581a7b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00581a7d: { // 0x581a7d: 7511 JNZ 0x00581a90
    if(integer::condition("JNZ",flags)) goto L00581a90;
  }
  L00581a7f: { // 0x581a7f: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00581a85: { // 0x581a85: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00581a86: { // 0x581a86: 83fb08 CMP EBX,0x8
    (void)integer::sub(s.bx,0x00000008u,32,flags);
  }
  L00581a89: { // 0x581a89: 7c81 JL 0x00581a0c
    if(integer::condition("JL",flags)) goto L00581a0c;
  }
  L00581a8b: { // 0x581a8b: e91f010000 JMP 0x00581baf
    goto L00581baf;
  }
  L00581a90: { // 0x581a90: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00581a95: { // 0x581a95: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00581a9c: { // 0x581a9c: 0fbf4c2410 MOVSX ECX,word ptr [ESP + 0x10]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L00581aa1: { // 0x581aa1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00581aa3: { // 0x581aa3: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L00581aa6: { // 0x581aa6: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L00581aab: { // 0x581aab: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L00581aae: { // 0x581aae: c744020800000000 MOV dword ptr [EDX + EAX*0x1 + 0x8],0x0
    m.w32((s.dx+(s.ax * 0x00000001u)+0x00000008u), 0x00000000u);
  }
  L00581ab6: { // 0x581ab6: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L00581abc: { // 0x581abc: c7440a0c0000e03f MOV dword ptr [EDX + ECX*0x1 + 0xc],0x3fe00000
    m.w32((s.dx+(s.cx * 0x00000001u)+0x0000000cu), 0x3fe00000u);
  }
  L00581ac4: { // 0x581ac4: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L00581aca: { // 0x581aca: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00581acf: { // 0x581acf: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00581ad6: { // 0x581ad6: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L00581adb: { // 0x581adb: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00581add: { // 0x581add: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00581ae0: { // 0x581ae0: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00581ae3: { // 0x581ae3: c644084501 MOV byte ptr [EAX + ECX*0x1 + 0x45],0x1
    m.w8((s.ax+(s.cx * 0x00000001u)+0x00000045u), 0x00000001u);
  }
  L00581ae8: { // 0x581ae8: e9c2000000 JMP 0x00581baf
    goto L00581baf;
  }
  L00581aed: { // 0x581aed: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00581aef: { // 0x581aef: e8ec96efff CALL 0x0047b1e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1e0u,5774068u); flags=s.arithmetic_flags;
  }
  L00581af4: { // 0x581af4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00581af6: { // 0x581af6: 0f84b3000000 JZ 0x00581baf
    if(integer::condition("JZ",flags)) goto L00581baf;
  }
  L00581afc: { // 0x581afc: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00581b02: { // 0x581b02: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00581b04: { // 0x581b04: 8b5724 MOV EDX,dword ptr [EDI + 0x24]
    s.dx = m.r32((s.di+0x00000024u));
  }
  L00581b07: { // 0x581b07: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00581b09: { // 0x581b09: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L00581b0c: { // 0x581b0c: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00581b10: { // 0x581b10: 8d0c85a09d8300 LEA ECX,[EAX*0x4 + 0x839da0]
    s.cx = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00581b17: { // 0x581b17: 668b0485a09d8300 MOV AX,word ptr [EAX*0x4 + 0x839da0]
    s.ax = with_ax(s.ax, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L00581b1f: { // 0x581b1f: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L00581b23: { // 0x581b23: 66034c2412 ADD CX,word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L00581b28: { // 0x581b28: 6603c2 ADD AX,DX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.dx & 0xffffu),16,flags));
  }
  L00581b2b: { // 0x581b2b: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L00581b30: { // 0x581b30: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L00581b35: { // 0x581b35: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00581b39: { // 0x581b39: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00581b3d: { // 0x581b3d: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00581b40: { // 0x581b40: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00581b43: { // 0x581b43: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L00581b46: { // 0x581b46: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00581b48: { // 0x581b48: 7e36 JLE 0x00581b80
    if(integer::condition("JLE",flags)) goto L00581b80;
  }
  L00581b4a: { // 0x581b4a: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00581b4c: { // 0x581b4c: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00581b4e: { // 0x581b4e: 3bde CMP EBX,ESI
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L00581b50: { // 0x581b50: 7d2e JGE 0x00581b80
    if(integer::condition("JGE",flags)) goto L00581b80;
  }
  L00581b52: { // 0x581b52: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00581b54: { // 0x581b54: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00581b56: { // 0x581b56: 7d28 JGE 0x00581b80
    if(integer::condition("JGE",flags)) goto L00581b80;
  }
  L00581b58: { // 0x581b58: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00581b5e: { // 0x581b5e: 7f20 JG 0x00581b80
    if(integer::condition("JG",flags)) goto L00581b80;
  }
  L00581b60: { // 0x581b60: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00581b64: { // 0x581b64: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00581b69: { // 0x581b69: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00581b6a: { // 0x581b6a: e89139fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5774191u); flags=s.arithmetic_flags;
  }
  L00581b6f: { // 0x581b6f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00581b71: { // 0x581b71: e81a96efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5774198u); flags=s.arithmetic_flags;
  }
  L00581b76: { // 0x581b76: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00581b78: { // 0x581b78: 7512 JNZ 0x00581b8c
    if(integer::condition("JNZ",flags)) goto L00581b8c;
  }
  L00581b7a: { // 0x581b7a: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00581b80: { // 0x581b80: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00581b81: { // 0x581b81: 83fd08 CMP EBP,0x8
    (void)integer::sub(s.bp,0x00000008u,32,flags);
  }
  L00581b84: { // 0x581b84: 0f8c7affffff JL 0x00581b04
    if(integer::condition("JL",flags)) goto L00581b04;
  }
  L00581b8a: { // 0x581b8a: eb23 JMP 0x00581baf
    goto L00581baf;
  }
  L00581b8c: { // 0x581b8c: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00581b91: { // 0x581b91: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00581b98: { // 0x581b98: 0fbf4c2410 MOVSX ECX,word ptr [ESP + 0x10]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L00581b9d: { // 0x581b9d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00581b9f: { // 0x581b9f: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L00581ba2: { // 0x581ba2: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L00581ba7: { // 0x581ba7: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L00581baa: { // 0x581baa: c644024501 MOV byte ptr [EDX + EAX*0x1 + 0x45],0x1
    m.w8((s.dx+(s.ax * 0x00000001u)+0x00000045u), 0x00000001u);
  }
  L00581baf: { // 0x581baf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00581bb4: { // 0x581bb4: e8c756fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5774265u); flags=s.arithmetic_flags;
  }
  L00581bb9: { // 0x581bb9: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00581bbb: { // 0x581bbb: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00581bbd: { // 0x581bbd: 0f8532feffff JNZ 0x005819f5
    if(integer::condition("JNZ",flags)) goto L005819f5;
  }
  L00581bc3: { // 0x581bc3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00581bc4: { // 0x581bc4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00581bc5: { // 0x581bc5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00581bc6: { // 0x581bc6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00581bc7: { // 0x581bc7: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00581bca: { // 0x581bca: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00181ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00581ea0: { // 0x581ea0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00581ea1: { // 0x581ea1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00581ea3: { // 0x581ea3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00581ea6: { // 0x581ea6: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00581ea9: { // 0x581ea9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00581eaa: { // 0x581eaa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00581eab: { // 0x581eab: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00581eac: { // 0x581eac: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00581eae: { // 0x581eae: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00581eaf: { // 0x581eaf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00581eb4: { // 0x581eb4: e88754fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5775033u); flags=s.arithmetic_flags;
  }
  L00581eb9: { // 0x581eb9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00581ebe: { // 0x581ebe: e8bd53fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5775043u); flags=s.arithmetic_flags;
  }
  L00581ec3: { // 0x581ec3: db465c FILD dword ptr [ESI + 0x5c]
    const auto address=(s.si+0x0000005cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00581ec6: { // 0x581ec6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00581ec8: { // 0x581ec8: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00581eca: { // 0x581eca: dc0d18757800 FMUL double ptr [0x00787518]
    const auto address=(0x00787518u);
    s.fp.multiply64(read64(m,address));
  }
  L00581ed0: { // 0x581ed0: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581ed4: { // 0x581ed4: 0f844f010000 JZ 0x00582029
    if(integer::condition("JZ",flags)) goto L00582029;
  }
  L00581eda: { // 0x581eda: 8b4324 MOV EAX,dword ptr [EBX + 0x24]
    s.ax = m.r32((s.bx+0x00000024u));
  }
  L00581edd: { // 0x581edd: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L00581ee3: { // 0x581ee3: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00581ee7: { // 0x581ee7: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00581ee9: { // 0x581ee9: 0fbf742416 MOVSX ESI,word ptr [ESP + 0x16]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L00581eee: { // 0x581eee: 0faf354c6b8300 IMUL ESI,dword ptr [0x00836b4c]
    s.si = integer::imul(s.si,m.r32((0x00836b4cu)),32,flags);
  }
  L00581ef5: { // 0x581ef5: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00581ef8: { // 0x581ef8: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00581efa: { // 0x581efa: 8d34b6 LEA ESI,[ESI + ESI*0x4]
    s.si = (s.si+(s.si * 0x00000004u));
  }
  L00581efd: { // 0x581efd: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  L00581f00: { // 0x581f00: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00581f02: { // 0x581f02: e8b994efff CALL 0x0047b3c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b3c0u,5775111u); flags=s.arithmetic_flags;
  }
  L00581f07: { // 0x581f07: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00581f09: { // 0x581f09: 0f84c6000000 JZ 0x00581fd5
    if(integer::condition("JZ",flags)) goto L00581fd5;
  }
  L00581f0f: { // 0x581f0f: 8b4324 MOV EAX,dword ptr [EBX + 0x24]
    s.ax = m.r32((s.bx+0x00000024u));
  }
  L00581f12: { // 0x581f12: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00581f15: { // 0x581f15: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00581f18: { // 0x581f18: 83ea02 SUB EDX,0x2
    s.dx = integer::sub(s.dx,0x00000002u,32,flags);
  }
  L00581f1b: { // 0x581f1b: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L00581f1e: { // 0x581f1e: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00581f20: { // 0x581f20: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00581f24: { // 0x581f24: 0f8deb000000 JGE 0x00582015
    if(integer::condition("JGE",flags)) goto L00582015;
  }
  L00581f2a: { // 0x581f2a: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00581f2e: { // 0x581f2e: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00581f33: { // 0x581f33: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00581f37: { // 0x581f37: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00581f3a: { // 0x581f3a: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00581f3f: { // 0x581f3f: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  L00581f42: { // 0x581f42: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00581f44: { // 0x581f44: 7d77 JGE 0x00581fbd
    if(integer::condition("JGE",flags)) goto L00581fbd;
  }
  L00581f46: { // 0x581f46: 0fbffa MOVSX EDI,DX
    s.di = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00581f49: { // 0x581f49: 8b2d3486a500 MOV EBP,dword ptr [0x00a58634]
    s.bp = m.r32((0x00a58634u));
  }
  L00581f4f: { // 0x581f4f: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00581f52: { // 0x581f52: 8d1438 LEA EDX,[EAX + EDI*0x1]
    s.dx = (s.ax+(s.di * 0x00000001u));
  }
  L00581f55: { // 0x581f55: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L00581f57: { // 0x581f57: 7e4c JLE 0x00581fa5
    if(integer::condition("JLE",flags)) goto L00581fa5;
  }
  L00581f59: { // 0x581f59: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L00581f5b: { // 0x581f5b: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L00581f5d: { // 0x581f5d: 3b2d3486a500 CMP EBP,dword ptr [0x00a58634]
    (void)integer::sub(s.bp,m.r32((0x00a58634u)),32,flags);
  }
  L00581f63: { // 0x581f63: 7d40 JGE 0x00581fa5
    if(integer::condition("JGE",flags)) goto L00581fa5;
  }
  L00581f65: { // 0x581f65: 8b2d3486a500 MOV EBP,dword ptr [0x00a58634]
    s.bp = m.r32((0x00a58634u));
  }
  L00581f6b: { // 0x581f6b: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00581f6d: { // 0x581f6d: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00581f6f: { // 0x581f6f: 7d34 JGE 0x00581fa5
    if(integer::condition("JGE",flags)) goto L00581fa5;
  }
  L00581f71: { // 0x581f71: 3b153886a500 CMP EDX,dword ptr [0x00a58638]
    (void)integer::sub(s.dx,m.r32((0x00a58638u)),32,flags);
  }
  L00581f77: { // 0x581f77: 7f2c JG 0x00581fa5
    if(integer::condition("JG",flags)) goto L00581fa5;
  }
  L00581f79: { // 0x581f79: 8b15f00c7900 MOV EDX,dword ptr [0x00790cf0]
    s.dx = m.r32((0x00790cf0u));
  }
  L00581f7f: { // 0x581f7f: a1f40c7900 MOV EAX,[0x00790cf4]
    s.ax = m.r32((0x00790cf4u));
  }
  L00581f84: { // 0x581f84: 895628 MOV dword ptr [ESI + 0x28],EDX
    m.w32((s.si+0x00000028u), s.dx);
  }
  L00581f87: { // 0x581f87: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  L00581f8a: { // 0x581f8a: dd05f80c7900 FLD double ptr [0x00790cf8]
    const auto address=(0x00790cf8u);
    s.fp.load64(read64(m,address));
  }
  L00581f90: { // 0x581f90: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L00581f94: { // 0x581f94: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00581f96: { // 0x581f96: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  L00581f99: { // 0x581f99: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  L00581f9c: { // 0x581f9c: dc0d30817800 FMUL double ptr [0x00788130]
    const auto address=(0x00788130u);
    s.fp.multiply64(read64(m,address));
  }
  L00581fa2: { // 0x581fa2: dd5e18 FSTP double ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581fa5: { // 0x581fa5: 8b5324 MOV EDX,dword ptr [EBX + 0x24]
    s.dx = m.r32((s.bx+0x00000024u));
  }
  L00581fa8: { // 0x581fa8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00581fa9: { // 0x581fa9: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00581fad: { // 0x581fad: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00581fb2: { // 0x581fb2: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  L00581fb5: { // 0x581fb5: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00581fb7: { // 0x581fb7: 7c90 JL 0x00581f49
    if(integer::condition("JL",flags)) goto L00581f49;
  }
  L00581fb9: { // 0x581fb9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00581fbd: { // 0x581fbd: 8b4324 MOV EAX,dword ptr [EBX + 0x24]
    s.ax = m.r32((s.bx+0x00000024u));
  }
  L00581fc0: { // 0x581fc0: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00581fc1: { // 0x581fc1: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00581fc4: { // 0x581fc4: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  L00581fc7: { // 0x581fc7: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00581fcb: { // 0x581fcb: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00581fcd: { // 0x581fcd: 0f8c57ffffff JL 0x00581f2a
    if(integer::condition("JL",flags)) goto L00581f2a;
  }
  L00581fd3: { // 0x581fd3: eb40 JMP 0x00582015
    goto L00582015;
  }
  L00581fd5: { // 0x581fd5: dd4628 FLD double ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L00581fd8: { // 0x581fd8: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581fde: { // 0x581fde: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581fe0: { // 0x581fe0: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00581fe3: { // 0x581fe3: 7430 JZ 0x00582015
    if(integer::condition("JZ",flags)) goto L00582015;
  }
  L00581fe5: { // 0x581fe5: 8b15f00c7900 MOV EDX,dword ptr [0x00790cf0]
    s.dx = m.r32((0x00790cf0u));
  }
  L00581feb: { // 0x581feb: a1f40c7900 MOV EAX,[0x00790cf4]
    s.ax = m.r32((0x00790cf4u));
  }
  L00581ff0: { // 0x581ff0: 895628 MOV dword ptr [ESI + 0x28],EDX
    m.w32((s.si+0x00000028u), s.dx);
  }
  L00581ff3: { // 0x581ff3: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  L00581ff6: { // 0x581ff6: dd05f80c7900 FLD double ptr [0x00790cf8]
    const auto address=(0x00790cf8u);
    s.fp.load64(read64(m,address));
  }
  L00581ffc: { // 0x581ffc: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L00582000: { // 0x582000: dd5e18 FSTP double ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00582003: { // 0x582003: 8b0d000d7900 MOV ECX,dword ptr [0x00790d00]
    s.cx = m.r32((0x00790d00u));
  }
  L00582009: { // 0x582009: 8b15040d7900 MOV EDX,dword ptr [0x00790d04]
    s.dx = m.r32((0x00790d04u));
  }
  L0058200f: { // 0x58200f: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L00582012: { // 0x582012: 895624 MOV dword ptr [ESI + 0x24],EDX
    m.w32((s.si+0x00000024u), s.dx);
  }
  L00582015: { // 0x582015: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0058201a: { // 0x58201a: e86152fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5775391u); flags=s.arithmetic_flags;
  }
  L0058201f: { // 0x58201f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00582021: { // 0x582021: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00582023: { // 0x582023: 0f85b1feffff JNZ 0x00581eda
    if(integer::condition("JNZ",flags)) goto L00581eda;
  }
  L00582029: { // 0x582029: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058202a: { // 0x58202a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058202b: { // 0x58202b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058202c: { // 0x58202c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058202d: { // 0x58202d: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0058202f: { // 0x58202f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00582030: { // 0x582030: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001d4730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d4730: { // 0x5d4730: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d4731: { // 0x5d4731: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d4732: { // 0x5d4732: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005d4733: { // 0x5d4733: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d4734: { // 0x5d4734: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L005d4737: { // 0x5d4737: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d4738: { // 0x5d4738: 0f84a7000000 JZ 0x005d47e5
    if(integer::condition("JZ",flags)) goto L005d47e5;
  }
  L005d473e: { // 0x5d473e: a11ce1a100 MOV EAX,[0x00a1e11c]
    s.ax = m.r32((0x00a1e11cu));
  }
  L005d4743: { // 0x5d4743: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L005d4746: { // 0x5d4746: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005d474a: { // 0x5d474a: 8a9079020000 MOV DL,byte ptr [EAX + 0x279]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000279u)));
  }
  L005d4750: { // 0x5d4750: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005d4752: { // 0x5d4752: 0f848d000000 JZ 0x005d47e5
    if(integer::condition("JZ",flags)) goto L005d47e5;
  }
  L005d4758: { // 0x5d4758: 8b154886aa00 MOV EDX,dword ptr [0x00aa8648]
    s.dx = m.r32((0x00aa8648u));
  }
  L005d475e: { // 0x5d475e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005d4760: { // 0x5d4760: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005d4762: { // 0x5d4762: 7e50 JLE 0x005d47b4
    if(integer::condition("JLE",flags)) goto L005d47b4;
  }
  L005d4764: { // 0x5d4764: 8b3d3c86aa00 MOV EDI,dword ptr [0x00aa863c]
    s.di = m.r32((0x00aa863cu));
  }
  L005d476a: { // 0x5d476a: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005d476c: { // 0x5d476c: 8b90e0000000 MOV EDX,dword ptr [EAX + 0xe0]
    s.dx = m.r32((s.ax+0x000000e0u));
  }
  L005d4772: { // 0x5d4772: 8b9264020000 MOV EDX,dword ptr [EDX + 0x264]
    s.dx = m.r32((s.dx+0x00000264u));
  }
  L005d4778: { // 0x5d4778: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005d477a: { // 0x5d477a: 7c0c JL 0x005d4788
    if(integer::condition("JL",flags)) goto L005d4788;
  }
  L005d477c: { // 0x5d477c: 8bb0e8000000 MOV ESI,dword ptr [EAX + 0xe8]
    s.si = m.r32((s.ax+0x000000e8u));
  }
  L005d4782: { // 0x5d4782: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L005d4784: { // 0x5d4784: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L005d4786: { // 0x5d4786: 7c51 JL 0x005d47d9
    if(integer::condition("JL",flags)) goto L005d47d9;
  }
  L005d4788: { // 0x5d4788: 8bb0e8000000 MOV ESI,dword ptr [EAX + 0xe8]
    s.si = m.r32((s.ax+0x000000e8u));
  }
  L005d478e: { // 0x5d478e: 8d2c16 LEA EBP,[ESI + EDX*0x1]
    s.bp = (s.si+(s.dx * 0x00000001u));
  }
  L005d4791: { // 0x5d4791: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L005d4793: { // 0x5d4793: 7c0e JL 0x005d47a3
    if(integer::condition("JL",flags)) goto L005d47a3;
  }
  L005d4795: { // 0x5d4795: 8ba8ec000000 MOV EBP,dword ptr [EAX + 0xec]
    s.bp = m.r32((s.ax+0x000000ecu));
  }
  L005d479b: { // 0x5d479b: 03ee ADD EBP,ESI
    s.bp = integer::add(s.bp,s.si,32,flags);
  }
  L005d479d: { // 0x5d479d: 03ea ADD EBP,EDX
    s.bp = integer::add(s.bp,s.dx,32,flags);
  }
  L005d479f: { // 0x5d479f: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L005d47a1: { // 0x5d47a1: 7c36 JL 0x005d47d9
    if(integer::condition("JL",flags)) goto L005d47d9;
  }
  L005d47a3: { // 0x5d47a3: a14886aa00 MOV EAX,[0x00aa8648]
    s.ax = m.r32((0x00aa8648u));
  }
  L005d47a8: { // 0x5d47a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005d47a9: { // 0x5d47a9: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L005d47ac: { // 0x5d47ac: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005d47ae: { // 0x5d47ae: 7cba JL 0x005d476a
    if(integer::condition("JL",flags)) goto L005d476a;
  }
  L005d47b0: { // 0x5d47b0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005d47b4: { // 0x5d47b4: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L005d47b7: { // 0x5d47b7: 8d7064 LEA ESI,[EAX + 0x64]
    s.si = (s.ax+0x00000064u);
  }
  L005d47ba: { // 0x5d47ba: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L005d47bf: { // 0x5d47bf: 8bfc MOV EDI,ESP
    s.di = f.sp;
  }
  L005d47c1: { // 0x5d47c1: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L005d47c3: { // 0x5d47c3: 68c82c7d00 PUSH 0x7d2cc8
    f.push(m,0x007d2cc8u);
  }
  L005d47c8: { // 0x5d47c8: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L005d47c9: { // 0x5d47c9: e82221e3ff CALL 0x004068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,6113230u); flags=s.arithmetic_flags;
  }
  L005d47ce: { // 0x5d47ce: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  L005d47d1: { // 0x5d47d1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005d47d3: { // 0x5d47d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d47d4: { // 0x5d47d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d47d5: { // 0x5d47d5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005d47d6: { // 0x5d47d6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d47d7: { // 0x5d47d7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d47d8: { // 0x5d47d8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005d47d9: { // 0x5d47d9: 8b8098000000 MOV EAX,dword ptr [EAX + 0x98]
    s.ax = m.r32((s.ax+0x00000098u));
  }
  L005d47df: { // 0x5d47df: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d47e0: { // 0x5d47e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d47e1: { // 0x5d47e1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005d47e2: { // 0x5d47e2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d47e3: { // 0x5d47e3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d47e4: { // 0x5d47e4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005d47e5: { // 0x5d47e5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d47e6: { // 0x5d47e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d47e7: { // 0x5d47e7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005d47e8: { // 0x5d47e8: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005d47eb: { // 0x5d47eb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d47ec: { // 0x5d47ec: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d47ed: { // 0x5d47ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697fb0: { // 0x697fb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00697fb3: { // 0x697fb3: 81f9d8020000 CMP ECX,0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  L00697fb9: { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L00697fbd: { // 0x697fbd: c744240000000000 MOV dword ptr [ESP],0x0
    m.w32((f.sp), 0x00000000u);
  }
  L00697fc5: { // 0x697fc5: 7c08 JL 0x00697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  L00697fc7: { // 0x697fc7: c744240001000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00697fd3: { // 0x697fd3: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697fd9: { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697fdd: { // 0x697fdd: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697fe3: { // 0x697fe3: e8682a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914024u); flags=s.arithmetic_flags;
  }
  L00697fe8: { // 0x697fe8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00697feb: { // 0x697feb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0029c090(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069c090: { // 0x69c090: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0069c093: { // 0x69c093: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069c094: { // 0x69c094: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069c095: { // 0x69c095: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069c096: { // 0x69c096: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L0069c09a: { // 0x69c09a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069c09b: { // 0x69c09b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0069c09d: { // 0x69c09d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c09e: { // 0x69c09e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c0a4: { // 0x69c0a4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c0a6: { // 0x69c0a6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c0a8: { // 0x69c0a8: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0069c0ab: { // 0x69c0ab: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c0ac: { // 0x69c0ac: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c0b2: { // 0x69c0b2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c0b4: { // 0x69c0b4: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c0b7: { // 0x69c0b7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c0ba: { // 0x69c0ba: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0069c0bd: { // 0x69c0bd: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0069c0c0: { // 0x69c0c0: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0069c0c5: { // 0x69c0c5: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L0069c0ca: { // 0x69c0ca: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069c0ce: { // 0x69c0ce: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0069c0d2: { // 0x69c0d2: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c0d5: { // 0x69c0d5: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c0d8: { // 0x69c0d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069c0d9: { // 0x69c0d9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c0de: { // 0x69c0de: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0069c0e2: { // 0x69c0e2: 81c680000000 ADD ESI,0x80
    s.si = integer::add(s.si,0x00000080u,32,flags);
  }
  L0069c0e8: { // 0x69c0e8: 81c780000000 ADD EDI,0x80
    s.di = integer::add(s.di,0x00000080u,32,flags);
  }
  L0069c0ee: { // 0x69c0ee: e80d94eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6930675u); flags=s.arithmetic_flags;
  }
  L0069c0f3: { // 0x69c0f3: 8b9840010000 MOV EBX,dword ptr [EAX + 0x140]
    s.bx = m.r32((s.ax+0x00000140u));
  }
  L0069c0f9: { // 0x69c0f9: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0069c0fd: { // 0x69c0fd: c1eb0c SHR EBX,0xc
    s.bx = integer::shift(s.bx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0069c100: { // 0x69c100: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c101: { // 0x69c101: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c106: { // 0x69c106: 80e301 AND BL,0x1
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags));
  }
  L0069c109: { // 0x69c109: e8f293eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6930702u); flags=s.arithmetic_flags;
  }
  L0069c10e: { // 0x69c10e: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0069c115: { // 0x69c115: 81c600060000 ADD ESI,0x600
    s.si = integer::add(s.si,0x00000600u,32,flags);
  }
  L0069c11b: { // 0x69c11b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069c11d: { // 0x69c11d: 8daf00060000 LEA EBP,[EDI + 0x600]
    s.bp = (s.di+0x00000600u);
  }
  L0069c123: { // 0x69c123: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0069c127: { // 0x69c127: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0069c129: { // 0x69c129: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0069c12d: { // 0x69c12d: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0069c131: { // 0x69c131: 83ef08 SUB EDI,0x8
    s.di = integer::sub(s.di,0x00000008u,32,flags);
  }
  L0069c134: { // 0x69c134: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0069c138: { // 0x69c138: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069c13a: { // 0x69c13a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c13b: { // 0x69c13b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c141: { // 0x69c141: 83ed08 SUB EBP,0x8
    s.bp = integer::sub(s.bp,0x00000008u,32,flags);
  }
  L0069c144: { // 0x69c144: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c146: { // 0x69c146: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c149: { // 0x69c149: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0069c14e: { // 0x69c14e: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0069c150: { // 0x69c150: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c151: { // 0x69c151: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c157: { // 0x69c157: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c159: { // 0x69c159: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0069c15d: { // 0x69c15d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c160: { // 0x69c160: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0069c165: { // 0x69c165: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0069c169: { // 0x69c169: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0069c16d: { // 0x69c16d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069c16e: { // 0x69c16e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c173: { // 0x69c173: e88893eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6930808u); flags=s.arithmetic_flags;
  }
  L0069c178: { // 0x69c178: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0069c17f: { // 0x69c17f: 2b4c2418 SUB ECX,dword ptr [ESP + 0x18]
    s.cx = integer::sub(s.cx,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0069c183: { // 0x69c183: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0069c185: { // 0x69c185: 740f JZ 0x0069c196
    if(integer::condition("JZ",flags)) goto L0069c196;
  }
  L0069c187: { // 0x69c187: 8b8040010000 MOV EAX,dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0069c18d: { // 0x69c18d: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L0069c190: { // 0x69c190: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  L0069c193: { // 0x69c193: 8d0c81 LEA ECX,[ECX + EAX*0x4]
    s.cx = (s.cx+(s.ax * 0x00000004u));
  }
  L0069c196: { // 0x69c196: c1e107 SHL ECX,0x7
    s.cx = integer::shift(s.cx,0x00000007u,32,flags,integer::Shift::left);
  }
  L0069c199: { // 0x69c199: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069c19b: { // 0x69c19b: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0069c19d: { // 0x69c19d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069c19f: { // 0x69c19f: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0069c1a1: { // 0x69c1a1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c1a2: { // 0x69c1a2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c1a8: { // 0x69c1a8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c1aa: { // 0x69c1aa: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c1ac: { // 0x69c1ac: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069c1ae: { // 0x69c1ae: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c1af: { // 0x69c1af: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c1b5: { // 0x69c1b5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c1b7: { // 0x69c1b7: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069c1bb: { // 0x69c1bb: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c1be: { // 0x69c1be: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c1c1: { // 0x69c1c1: 663bca CMP CX,DX
    (void)integer::sub((s.cx & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0069c1c4: { // 0x69c1c4: 668b4c2432 MOV CX,word ptr [ESP + 0x32]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000032u)));
  }
  L0069c1c9: { // 0x69c1c9: 7f05 JG 0x0069c1d0
    if(integer::condition("JG",flags)) goto L0069c1d0;
  }
  L0069c1cb: { // 0x69c1cb: 663bc1 CMP AX,CX
    (void)integer::sub((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags);
  }
  L0069c1ce: { // 0x69c1ce: 7e17 JLE 0x0069c1e7
    if(integer::condition("JLE",flags)) goto L0069c1e7;
  }
  L0069c1d0: { // 0x69c1d0: 6639542410 CMP word ptr [ESP + 0x10],DX
    (void)integer::sub(m.r16((f.sp+0x00000010u)),(s.dx & 0xffffu),16,flags);
  }
  L0069c1d5: { // 0x69c1d5: 0f8552ffffff JNZ 0x0069c12d
    if(integer::condition("JNZ",flags)) goto L0069c12d;
  }
  L0069c1db: { // 0x69c1db: 66394c2412 CMP word ptr [ESP + 0x12],CX
    (void)integer::sub(m.r16((f.sp+0x00000012u)),(s.cx & 0xffffu),16,flags);
  }
  L0069c1e0: { // 0x69c1e0: 7419 JZ 0x0069c1fb
    if(integer::condition("JZ",flags)) goto L0069c1fb;
  }
  L0069c1e2: { // 0x69c1e2: e946ffffff JMP 0x0069c12d
    goto L0069c12d;
  }
  L0069c1e7: { // 0x69c1e7: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0069c1eb: { // 0x69c1eb: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0069c1ef: { // 0x69c1ef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c1f0: { // 0x69c1f0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c1f1: { // 0x69c1f1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c1f2: { // 0x69c1f2: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c1f4: { // 0x69c1f4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c1f5: { // 0x69c1f5: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0069c1f8: { // 0x69c1f8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069c1fb: { // 0x69c1fb: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0069c1ff: { // 0x69c1ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c200: { // 0x69c200: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c201: { // 0x69c201: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c202: { // 0x69c202: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0069c204: { // 0x69c204: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c205: { // 0x69c205: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0069c208: { // 0x69c208: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0029e380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e380: { // 0x69e380: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069e381: { // 0x69e381: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069e382: { // 0x69e382: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e383: { // 0x69e383: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0069e387: { // 0x69e387: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e388: { // 0x69e388: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e389: { // 0x69e389: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e38e: { // 0x69e38e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0069e390: { // 0x69e390: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L0069e393: { // 0x69e393: e86871eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939544u); flags=s.arithmetic_flags;
  }
  L0069e398: { // 0x69e398: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0069e39c: { // 0x69e39c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e39e: { // 0x69e39e: 0f84d0010000 JZ 0x0069e574
    if(integer::condition("JZ",flags)) goto L0069e574;
  }
  L0069e3a4: { // 0x69e3a4: 8b8040010000 MOV EAX,dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0069e3aa: { // 0x69e3aa: a803 TEST AL,0x3
    (void)integer::logical(((s.ax & 0xffu))&(0x00000003u),8,flags);
  }
  L0069e3ac: { // 0x69e3ac: 7505 JNZ 0x0069e3b3
    if(integer::condition("JNZ",flags)) goto L0069e3b3;
  }
  L0069e3ae: { // 0x69e3ae: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e3b3: { // 0x69e3b3: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L0069e3b8: { // 0x69e3b8: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e3ba: { // 0x69e3ba: 0f8494030000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e3c0: { // 0x69e3c0: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e3c3: { // 0x69e3c3: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e3c7: { // 0x69e3c7: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e3c9: { // 0x69e3c9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e3cb: { // 0x69e3cb: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e3d0: { // 0x69e3d0: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e3d5: { // 0x69e3d5: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e3d9: { // 0x69e3d9: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e3dd: { // 0x69e3dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e3de: { // 0x69e3de: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e3e3: { // 0x69e3e3: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e3e7: { // 0x69e3e7: e81471eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939628u); flags=s.arithmetic_flags;
  }
  L0069e3ec: { // 0x69e3ec: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e3f2: { // 0x69e3f2: 7505 JNZ 0x0069e3f9
    if(integer::condition("JNZ",flags)) goto L0069e3f9;
  }
  L0069e3f4: { // 0x69e3f4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e3f9: { // 0x69e3f9: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e3fc: { // 0x69e3fc: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e400: { // 0x69e400: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e405: { // 0x69e405: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e407: { // 0x69e407: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e40b: { // 0x69e40b: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e410: { // 0x69e410: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e414: { // 0x69e414: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e415: { // 0x69e415: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e41a: { // 0x69e41a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e41e: { // 0x69e41e: e8dd70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939683u); flags=s.arithmetic_flags;
  }
  L0069e423: { // 0x69e423: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e429: { // 0x69e429: 7506 JNZ 0x0069e431
    if(integer::condition("JNZ",flags)) goto L0069e431;
  }
  L0069e42b: { // 0x69e42b: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e431: { // 0x69e431: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e434: { // 0x69e434: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e438: { // 0x69e438: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e43a: { // 0x69e43a: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e43c: { // 0x69e43c: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e441: { // 0x69e441: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e446: { // 0x69e446: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e44a: { // 0x69e44a: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e44e: { // 0x69e44e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e452: { // 0x69e452: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e453: { // 0x69e453: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e458: { // 0x69e458: e8a370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939741u); flags=s.arithmetic_flags;
  }
  L0069e45d: { // 0x69e45d: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e463: { // 0x69e463: 7503 JNZ 0x0069e468
    if(integer::condition("JNZ",flags)) goto L0069e468;
  }
  L0069e465: { // 0x69e465: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e468: { // 0x69e468: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e46b: { // 0x69e46b: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e46f: { // 0x69e46f: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e471: { // 0x69e471: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e476: { // 0x69e476: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e47b: { // 0x69e47b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e47f: { // 0x69e47f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e483: { // 0x69e483: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e488: { // 0x69e488: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e489: { // 0x69e489: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e48d: { // 0x69e48d: e86e70eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939794u); flags=s.arithmetic_flags;
  }
  L0069e492: { // 0x69e492: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e498: { // 0x69e498: 7503 JNZ 0x0069e49d
    if(integer::condition("JNZ",flags)) goto L0069e49d;
  }
  L0069e49a: { // 0x69e49a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e49d: { // 0x69e49d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e4a0: { // 0x69e4a0: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e4a4: { // 0x69e4a4: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e4a6: { // 0x69e4a6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e4ab: { // 0x69e4ab: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e4b0: { // 0x69e4b0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e4b4: { // 0x69e4b4: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e4b8: { // 0x69e4b8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069e4bc: { // 0x69e4bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e4bd: { // 0x69e4bd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4c2: { // 0x69e4c2: e83970eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939847u); flags=s.arithmetic_flags;
  }
  L0069e4c7: { // 0x69e4c7: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e4cd: { // 0x69e4cd: 7502 JNZ 0x0069e4d1
    if(integer::condition("JNZ",flags)) goto L0069e4d1;
  }
  L0069e4cf: { // 0x69e4cf: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e4d1: { // 0x69e4d1: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e4d4: { // 0x69e4d4: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e4d8: { // 0x69e4d8: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e4da: { // 0x69e4da: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e4dc: { // 0x69e4dc: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e4e1: { // 0x69e4e1: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e4e6: { // 0x69e4e6: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e4ea: { // 0x69e4ea: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e4ee: { // 0x69e4ee: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e4f2: { // 0x69e4f2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e4f3: { // 0x69e4f3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4f8: { // 0x69e4f8: e80370eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939901u); flags=s.arithmetic_flags;
  }
  L0069e4fd: { // 0x69e4fd: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e503: { // 0x69e503: 7503 JNZ 0x0069e508
    if(integer::condition("JNZ",flags)) goto L0069e508;
  }
  L0069e505: { // 0x69e505: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e508: { // 0x69e508: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e50c: { // 0x69e50c: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e50f: { // 0x69e50f: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e511: { // 0x69e511: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e516: { // 0x69e516: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e51b: { // 0x69e51b: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e51f: { // 0x69e51f: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e523: { // 0x69e523: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e528: { // 0x69e528: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e529: { // 0x69e529: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e52d: { // 0x69e52d: e8ce6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939954u); flags=s.arithmetic_flags;
  }
  L0069e532: { // 0x69e532: 849840010000 TEST byte ptr [EAX + 0x140],BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e538: { // 0x69e538: 7503 JNZ 0x0069e53d
    if(integer::condition("JNZ",flags)) goto L0069e53d;
  }
  L0069e53a: { // 0x69e53a: 83cd08 OR EBP,0x8
    s.bp = integer::logical((s.bp)|(0x00000008u),32,flags);
  }
  L0069e53d: { // 0x69e53d: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e540: { // 0x69e540: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e544: { // 0x69e544: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e546: { // 0x69e546: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e548: { // 0x69e548: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e54d: { // 0x69e54d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e551: { // 0x69e551: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e556: { // 0x69e556: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e55a: { // 0x69e55a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e55b: { // 0x69e55b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e560: { // 0x69e560: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e564: { // 0x69e564: e8976feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940009u); flags=s.arithmetic_flags;
  }
  L0069e569: { // 0x69e569: 8a8840010000 MOV CL,byte ptr [EAX + 0x140]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000140u)));
  }
  L0069e56f: { // 0x69e56f: e9cb010000 JMP 0x0069e73f
    goto L0069e73f;
  }
  L0069e574: { // 0x69e574: 8b802c010000 MOV EAX,dword ptr [EAX + 0x12c]
    s.ax = m.r32((s.ax+0x0000012cu));
  }
  L0069e57a: { // 0x69e57a: a818 TEST AL,0x18
    (void)integer::logical(((s.ax & 0xffu))&(0x00000018u),8,flags);
  }
  L0069e57c: { // 0x69e57c: 7505 JNZ 0x0069e583
    if(integer::condition("JNZ",flags)) goto L0069e583;
  }
  L0069e57e: { // 0x69e57e: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e583: { // 0x69e583: bb08000000 MOV EBX,0x8
    s.bx = 0x00000008u;
  }
  L0069e588: { // 0x69e588: 84c3 TEST BL,AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e58a: { // 0x69e58a: 0f84c4010000 JZ 0x0069e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e590: { // 0x69e590: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e593: { // 0x69e593: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e597: { // 0x69e597: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e599: { // 0x69e599: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e59b: { // 0x69e59b: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e5a0: { // 0x69e5a0: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e5a5: { // 0x69e5a5: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e5a9: { // 0x69e5a9: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e5ad: { // 0x69e5ad: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e5b1: { // 0x69e5b1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e5b2: { // 0x69e5b2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5b7: { // 0x69e5b7: e8446feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940092u); flags=s.arithmetic_flags;
  }
  L0069e5bc: { // 0x69e5bc: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5c2: { // 0x69e5c2: 7505 JNZ 0x0069e5c9
    if(integer::condition("JNZ",flags)) goto L0069e5c9;
  }
  L0069e5c4: { // 0x69e5c4: bd40000000 MOV EBP,0x40
    s.bp = 0x00000040u;
  }
  L0069e5c9: { // 0x69e5c9: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e5cd: { // 0x69e5cd: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e5d0: { // 0x69e5d0: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e5d2: { // 0x69e5d2: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e5d7: { // 0x69e5d7: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e5dc: { // 0x69e5dc: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e5e0: { // 0x69e5e0: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e5e4: { // 0x69e5e4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5e9: { // 0x69e5e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e5ea: { // 0x69e5ea: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e5ee: { // 0x69e5ee: e80d6feaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940147u); flags=s.arithmetic_flags;
  }
  L0069e5f3: { // 0x69e5f3: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5f9: { // 0x69e5f9: 7506 JNZ 0x0069e601
    if(integer::condition("JNZ",flags)) goto L0069e601;
  }
  L0069e5fb: { // 0x69e5fb: 81cd80000000 OR EBP,0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e601: { // 0x69e601: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e604: { // 0x69e604: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e608: { // 0x69e608: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e60a: { // 0x69e60a: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e60c: { // 0x69e60c: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e611: { // 0x69e611: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e615: { // 0x69e615: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e61a: { // 0x69e61a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e61e: { // 0x69e61e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e61f: { // 0x69e61f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e624: { // 0x69e624: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e628: { // 0x69e628: e8d36eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940205u); flags=s.arithmetic_flags;
  }
  L0069e62d: { // 0x69e62d: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e633: { // 0x69e633: 7503 JNZ 0x0069e638
    if(integer::condition("JNZ",flags)) goto L0069e638;
  }
  L0069e635: { // 0x69e635: 83cd01 OR EBP,0x1
    s.bp = integer::logical((s.bp)|(0x00000001u),32,flags);
  }
  L0069e638: { // 0x69e638: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e63b: { // 0x69e63b: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e63f: { // 0x69e63f: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e641: { // 0x69e641: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e646: { // 0x69e646: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e64b: { // 0x69e64b: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e64f: { // 0x69e64f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e653: { // 0x69e653: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e657: { // 0x69e657: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e658: { // 0x69e658: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e65d: { // 0x69e65d: e89e6eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940258u); flags=s.arithmetic_flags;
  }
  L0069e662: { // 0x69e662: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e668: { // 0x69e668: 7503 JNZ 0x0069e66d
    if(integer::condition("JNZ",flags)) goto L0069e66d;
  }
  L0069e66a: { // 0x69e66a: 83cd20 OR EBP,0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e66d: { // 0x69e66d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e670: { // 0x69e670: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e674: { // 0x69e674: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e676: { // 0x69e676: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e67b: { // 0x69e67b: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e680: { // 0x69e680: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e684: { // 0x69e684: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e688: { // 0x69e688: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e68d: { // 0x69e68d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e68e: { // 0x69e68e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e692: { // 0x69e692: e8696eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940311u); flags=s.arithmetic_flags;
  }
  L0069e697: { // 0x69e697: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e69d: { // 0x69e69d: 7503 JNZ 0x0069e6a2
    if(integer::condition("JNZ",flags)) goto L0069e6a2;
  }
  L0069e69f: { // 0x69e69f: 83cd02 OR EBP,0x2
    s.bp = integer::logical((s.bp)|(0x00000002u),32,flags);
  }
  L0069e6a2: { // 0x69e6a2: 668b0e MOV CX,word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e6a5: { // 0x69e6a5: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L0069e6a9: { // 0x69e6a9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e6ab: { // 0x69e6ab: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e6ad: { // 0x69e6ad: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e6b2: { // 0x69e6b2: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e6b6: { // 0x69e6b6: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e6bb: { // 0x69e6bb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e6bf: { // 0x69e6bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e6c0: { // 0x69e6c0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6c5: { // 0x69e6c5: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e6c9: { // 0x69e6c9: e8326eeaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940366u); flags=s.arithmetic_flags;
  }
  L0069e6ce: { // 0x69e6ce: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e6d4: { // 0x69e6d4: 7503 JNZ 0x0069e6d9
    if(integer::condition("JNZ",flags)) goto L0069e6d9;
  }
  L0069e6d6: { // 0x69e6d6: 83cd10 OR EBP,0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e6d9: { // 0x69e6d9: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L0069e6dd: { // 0x69e6dd: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e6e0: { // 0x69e6e0: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e6e2: { // 0x69e6e2: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e6e7: { // 0x69e6e7: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e6ec: { // 0x69e6ec: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e6f0: { // 0x69e6f0: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e6f4: { // 0x69e6f4: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e6f8: { // 0x69e6f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e6f9: { // 0x69e6f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6fe: { // 0x69e6fe: e8fd6deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940419u); flags=s.arithmetic_flags;
  }
  L0069e703: { // 0x69e703: 84982c010000 TEST byte ptr [EAX + 0x12c],BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e709: { // 0x69e709: 7502 JNZ 0x0069e70d
    if(integer::condition("JNZ",flags)) goto L0069e70d;
  }
  L0069e70b: { // 0x69e70b: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e70d: { // 0x69e70d: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e710: { // 0x69e710: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  L0069e714: { // 0x69e714: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e716: { // 0x69e716: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e718: { // 0x69e718: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e71d: { // 0x69e71d: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e722: { // 0x69e722: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e726: { // 0x69e726: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e72a: { // 0x69e72a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e72b: { // 0x69e72b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e730: { // 0x69e730: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e734: { // 0x69e734: e8c76deaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940473u); flags=s.arithmetic_flags;
  }
  L0069e739: { // 0x69e739: 8a882c010000 MOV CL,byte ptr [EAX + 0x12c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000012cu)));
  }
  L0069e73f: { // 0x69e73f: 84cb TEST BL,CL
    (void)integer::logical(((s.bx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e741: { // 0x69e741: 7503 JNZ 0x0069e746
    if(integer::condition("JNZ",flags)) goto L0069e746;
  }
  L0069e743: { // 0x69e743: 83cd04 OR EBP,0x4
    s.bp = integer::logical((s.bp)|(0x00000004u),32,flags);
  }
  L0069e746: { // 0x69e746: 0fbe8564727900 MOVSX EAX,byte ptr [EBP + 0x797264]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x00797264u)),8));
  }
  L0069e74d: { // 0x69e74d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e74e: { // 0x69e74e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e74f: { // 0x69e74f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e750: { // 0x69e750: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e751: { // 0x69e751: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069e754: { // 0x69e754: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e756: { // 0x69e756: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e757: { // 0x69e757: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e758: { // 0x69e758: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e759: { // 0x69e759: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e75a: { // 0x69e75a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00306660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00706660: { // 0x706660: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00706661: { // 0x706661: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00706663: { // 0x706663: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00706666: { // 0x706666: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00706669: { // 0x706669: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0070666a: { // 0x70666a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0070666b: { // 0x70666b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0070666c: { // 0x70666c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0070666e: { // 0x70666e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0070666f: { // 0x70666f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00706671: { // 0x706671: 8b869c000000 MOV EAX,dword ptr [ESI + 0x9c]
    s.ax = m.r32((s.si+0x0000009cu));
  }
  L00706677: { // 0x706677: 89be98000000 MOV dword ptr [ESI + 0x98],EDI
    m.w32((s.si+0x00000098u), s.di);
  }
  L0070667d: { // 0x70667d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0070667f: { // 0x70667f: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L00706681: { // 0x706681: 7c0e JL 0x00706691
    if(integer::condition("JL",flags)) goto L00706691;
  }
  L00706683: { // 0x706683: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00706686: { // 0x706686: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00706687: { // 0x706687: 897c8afc MOV dword ptr [EDX + ECX*0x4 + -0x4],EDI
    m.w32((s.dx+(s.cx * 0x00000004u)-0x00000004u), s.di);
  }
  L0070668b: { // 0x70668b: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0070668d: { // 0x70668d: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0070668f: { // 0x70668f: 7ef2 JLE 0x00706683
    if(integer::condition("JLE",flags)) goto L00706683;
  }
  L00706691: { // 0x706691: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L00706693: { // 0x706693: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00706698: { // 0x706698: 89beec000000 MOV dword ptr [ESI + 0xec],EDI
    m.w32((s.si+0x000000ecu), s.di);
  }
  L0070669e: { // 0x70669e: e89d0ce5ff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,7366307u); flags=s.arithmetic_flags;
  }
  L007066a3: { // 0x7066a3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L007066a8: { // 0x7066a8: e8d30be5ff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,7366317u); flags=s.arithmetic_flags;
  }
  L007066ad: { // 0x7066ad: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L007066af: { // 0x7066af: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L007066b1: { // 0x7066b1: 0f8464010000 JZ 0x0070681b
    if(integer::condition("JZ",flags)) goto L0070681b;
  }
  L007066b7: { // 0x7066b7: 837b447e CMP dword ptr [EBX + 0x44],0x7e
    (void)integer::sub(m.r32((s.bx+0x00000044u)),0x0000007eu,32,flags);
  }
  L007066bb: { // 0x7066bb: 0f8546010000 JNZ 0x00706807
    if(integer::condition("JNZ",flags)) goto L00706807;
  }
  L007066c1: { // 0x7066c1: 80bb1e01000030 CMP byte ptr [EBX + 0x11e],0x30
    (void)integer::sub(m.r8((s.bx+0x0000011eu)),0x00000030u,8,flags);
  }
  L007066c8: { // 0x7066c8: 0f8239010000 JC 0x00706807
    if(integer::condition("JC",flags)) goto L00706807;
  }
  L007066ce: { // 0x7066ce: 8d7b24 LEA EDI,[EBX + 0x24]
    s.di = (s.bx+0x00000024u);
  }
  L007066d1: { // 0x7066d1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L007066d3: { // 0x7066d3: e8b823d2ff CALL 0x00428a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428a90u,7366360u); flags=s.arithmetic_flags;
  }
  L007066d8: { // 0x7066d8: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L007066da: { // 0x7066da: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L007066dc: { // 0x7066dc: 0f8c25010000 JL 0x00706807
    if(integer::condition("JL",flags)) goto L00706807;
  }
  L007066e2: { // 0x7066e2: e8d923d2ff CALL 0x00428ac0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428ac0u,7366375u); flags=s.arithmetic_flags;
  }
  L007066e7: { // 0x7066e7: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L007066e9: { // 0x7066e9: 0f8d18010000 JGE 0x00706807
    if(integer::condition("JGE",flags)) goto L00706807;
  }
  L007066ef: { // 0x7066ef: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L007066f5: { // 0x7066f5: 803c2800 CMP byte ptr [EAX + EBP*0x1],0x0
    (void)integer::sub(m.r8((s.ax+(s.bp * 0x00000001u))),0x00000000u,8,flags);
  }
  L007066f9: { // 0x7066f9: 0f8408010000 JZ 0x00706807
    if(integer::condition("JZ",flags)) goto L00706807;
  }
  L007066ff: { // 0x7066ff: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00706705: { // 0x706705: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L0070670b: { // 0x70670b: 3b81d4000000 CMP EAX,dword ptr [ECX + 0xd4]
    (void)integer::sub(s.ax,m.r32((s.cx+0x000000d4u)),32,flags);
  }
  L00706711: { // 0x706711: 0f8df0000000 JGE 0x00706807
    if(integer::condition("JGE",flags)) goto L00706807;
  }
  L00706717: { // 0x706717: 8b96a0000000 MOV EDX,dword ptr [ESI + 0xa0]
    s.dx = m.r32((s.si+0x000000a0u));
  }
  L0070671d: { // 0x70671d: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L0070671f: { // 0x70671f: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00706722: { // 0x706722: 890cc2 MOV dword ptr [EDX + EAX*0x8],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.cx);
  }
  L00706725: { // 0x706725: 0fbfaee2000000 MOVSX EBP,word ptr [ESI + 0xe2]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.si+0x000000e2u)),16));
  }
  L0070672c: { // 0x70672c: 0fbf4b26 MOVSX ECX,word ptr [EBX + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000026u)),16));
  }
  L00706730: { // 0x706730: 0fbf96e0000000 MOVSX EDX,word ptr [ESI + 0xe0]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x000000e0u)),16));
  }
  L00706737: { // 0x706737: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0070673a: { // 0x70673a: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  L0070673c: { // 0x70673c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0070673e: { // 0x70673e: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00706742: { // 0x706742: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00706746: { // 0x706746: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0070674a: { // 0x70674a: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L0070674e: { // 0x70674e: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00706750: { // 0x706750: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00706752: { // 0x706752: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00706754: { // 0x706754: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L00706756: { // 0x706756: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00706758: { // 0x706758: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0070675b: { // 0x70675b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0070675d: { // 0x70675d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0070675f: { // 0x70675f: e81c39dbff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,7366500u); flags=s.arithmetic_flags;
  }
  L00706764: { // 0x706764: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00706767: { // 0x706767: e8e4420600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7366508u); flags=s.arithmetic_flags;
  }
  L0070676c: { // 0x70676c: 8b8ea0000000 MOV ECX,dword ptr [ESI + 0xa0]
    s.cx = m.r32((s.si+0x000000a0u));
  }
  L00706772: { // 0x706772: bae8030000 MOV EDX,0x3e8
    s.dx = 0x000003e8u;
  }
  L00706777: { // 0x706777: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00706779: { // 0x706779: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L0070677f: { // 0x70677f: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00706783: { // 0x706783: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00706787: { // 0x706787: d95cc104 FSTP float ptr [ECX + EAX*0x8 + 0x4]
    const auto address=(s.cx+(s.ax * 0x00000008u)+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0070678b: { // 0x70678b: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00706791: { // 0x706791: 8b96a0000000 MOV EDX,dword ptr [ESI + 0xa0]
    s.dx = m.r32((s.si+0x000000a0u));
  }
  L00706797: { // 0x706797: 8bbe9c000000 MOV EDI,dword ptr [ESI + 0x9c]
    s.di = m.r32((s.si+0x0000009cu));
  }
  L0070679d: { // 0x70679d: 8d2cc2 LEA EBP,[EDX + EAX*0x8]
    s.bp = (s.dx+(s.ax * 0x00000008u));
  }
  L007067a0: { // 0x7067a0: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L007067a1: { // 0x7067a1: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
  L007067a7: { // 0x7067a7: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L007067a9: { // 0x7067a9: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L007067ac: { // 0x7067ac: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007067ad: { // 0x7067ad: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007067af: { // 0x7067af: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L007067b3: { // 0x7067b3: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L007067b6: { // 0x7067b6: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L007067b8: { // 0x7067b8: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007067ba: { // 0x7067ba: 7345 JNC 0x00706801
    if(integer::condition("JNC",flags)) goto L00706801;
  }
  L007067bc: { // 0x7067bc: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L007067bf: { // 0x7067bf: 7623 JBE 0x007067e4
    if(integer::condition("JBE",flags)) goto L007067e4;
  }
  L007067c1: { // 0x7067c1: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L007067c4: { // 0x7067c4: 8b0493 MOV EAX,dword ptr [EBX + EDX*0x4]
    s.ax = m.r32((s.bx+(s.dx * 0x00000004u)));
  }
  L007067c7: { // 0x7067c7: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L007067ca: { // 0x7067ca: d85c2414 FCOMP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.compare_pop32(m.r32(address));
  }
  L007067ce: { // 0x7067ce: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007067d0: { // 0x7067d0: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L007067d3: { // 0x7067d3: 750f JNZ 0x007067e4
    if(integer::condition("JNZ",flags)) goto L007067e4;
  }
  L007067d5: { // 0x7067d5: 8b0493 MOV EAX,dword ptr [EBX + EDX*0x4]
    s.ax = m.r32((s.bx+(s.dx * 0x00000004u)));
  }
  L007067d8: { // 0x7067d8: 89048b MOV dword ptr [EBX + ECX*0x4],EAX
    m.w32((s.bx+(s.cx * 0x00000004u)), s.ax);
  }
  L007067db: { // 0x7067db: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L007067dd: { // 0x7067dd: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L007067df: { // 0x7067df: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L007067e2: { // 0x7067e2: 77dd JA 0x007067c1
    if(integer::condition("JA",flags)) goto L007067c1;
  }
  L007067e4: { // 0x7067e4: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L007067e7: { // 0x7067e7: 892c8a MOV dword ptr [EDX + ECX*0x4],EBP
    m.w32((s.dx+(s.cx * 0x00000004u)), s.bp);
  }
  L007067ea: { // 0x7067ea: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L007067ec: { // 0x7067ec: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L007067ef: { // 0x7067ef: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007067f0: { // 0x7067f0: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L007067f2: { // 0x7067f2: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L007067f4: { // 0x7067f4: 7603 JBE 0x007067f9
    if(integer::condition("JBE",flags)) goto L007067f9;
  }
  L007067f6: { // 0x7067f6: 896f0c MOV dword ptr [EDI + 0xc],EBP
    m.w32((s.di+0x0000000cu), s.bp);
  }
  L007067f9: { // 0x7067f9: 3b6f10 CMP EBP,dword ptr [EDI + 0x10]
    (void)integer::sub(s.bp,m.r32((s.di+0x00000010u)),32,flags);
  }
  L007067fc: { // 0x7067fc: 7303 JNC 0x00706801
    if(integer::condition("JNC",flags)) goto L00706801;
  }
  L007067fe: { // 0x7067fe: 896f10 MOV dword ptr [EDI + 0x10],EBP
    m.w32((s.di+0x00000010u), s.bp);
  }
  L00706801: { // 0x706801: ff86ec000000 INC dword ptr [ESI + 0xec]
    m.w32((s.si+0x000000ecu), integer::increment(m.r32((s.si+0x000000ecu)),32,flags));
  }
  L00706807: { // 0x706807: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0070680c: { // 0x70680c: e86f0ae5ff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,7366673u); flags=s.arithmetic_flags;
  }
  L00706811: { // 0x706811: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00706813: { // 0x706813: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00706815: { // 0x706815: 0f859cfeffff JNZ 0x007066b7
    if(integer::condition("JNZ",flags)) goto L007066b7;
  }
  L0070681b: { // 0x70681b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0070681c: { // 0x70681c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0070681d: { // 0x70681d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0070681e: { // 0x70681e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0070681f: { // 0x70681f: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00706821: { // 0x706821: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00706822: { // 0x706822: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4221168u:f_000068f0(m,s,child,{});break;
case 4357776u:f_00027e90(m,s,child,{});break;
case 4360848u:f_00028a90(m,s,child,{});break;
case 4360896u:f_00028ac0(m,s,child,{});break;
case 4365152u:f_00029b60(m,s,child,{});break;
case 4369712u:f_0002ad30(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
case 4369920u:f_0002ae00(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 4677584u:f_00075fd0(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 4679584u:f_000767a0(m,s,child,{});break;
case 4693616u:f_00079e70(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
case 4698592u:f_0007b1e0(m,s,child,{});break;
case 4699072u:f_0007b3c0(m,s,child,{});break;
case 4699488u:f_0007b560(m,s,child,{});break;
case 4699520u:f_0007b580(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 5273840u:f_001078f0(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5536688u:f_00147bb0(m,s,child,{});break;
case 5537600u:f_00147f40(m,s,child,{});break;
case 5558080u:f_0014cf40(m,s,child,{});break;
case 5559648u:f_0014d560(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 5599872u:f_00157280(m,s,child,{});break;
case 5600064u:f_00157340(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 5606240u:f_00158b60(m,s,child,{});break;
case 5612032u:f_0015a200(m,s,child,{});break;
case 5643616u:f_00161d60(m,s,child,{});break;
case 5644720u:f_001621b0(m,s,child,{});break;
case 5679504u:f_0016a990(m,s,child,{});break;
case 5773776u:f_001819d0(m,s,child,{});break;
case 5775008u:f_00181ea0(m,s,child,{});break;
case 6113072u:f_001d4730(m,s,child,{});break;
case 6913968u:f_00297fb0(m,s,child,{});break;
case 6930576u:f_0029c090(m,s,child,{});break;
case 6939520u:f_0029e380(m,s,child,{});break;
case 7366240u:f_00306660(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery1721 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0042aa30(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042aa30: { // 0x42aa30: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0042aa33: { // 0x42aa33: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042aa34: { // 0x42aa34: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042aa35: { // 0x42aa35: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0042aa37: { // 0x42aa37: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042aa38: { // 0x42aa38: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042aa39: { // 0x42aa39: c6433801 MOV byte ptr [EBX + 0x38],0x1
    m.w8((s.bx+0x00000038u), 0x00000001u);
  }
  L0042aa3d: { // 0x42aa3d: e84ed4ffff CALL 0x00427e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00427e90u,4368962u); flags=s.arithmetic_flags;
  }
  L0042aa42: { // 0x42aa42: 8d7374 LEA ESI,[EBX + 0x74]
    s.si = (s.bx+0x00000074u);
  }
  L0042aa45: { // 0x42aa45: bf03000000 MOV EDI,0x3
    s.di = 0x00000003u;
  }
  L0042aa4a: { // 0x42aa4a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0042aa4c: { // 0x42aa4c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042aa4e: { // 0x42aa4e: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),4368977u); flags=s.arithmetic_flags;
  }
  L0042aa51: { // 0x42aa51: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  L0042aa54: { // 0x42aa54: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042aa55: { // 0x42aa55: 75f3 JNZ 0x0042aa4a
    if(integer::condition("JNZ",flags)) goto L0042aa4a;
  }
  L0042aa57: { // 0x42aa57: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0042aa5b: { // 0x42aa5b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042aa5c: { // 0x42aa5c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042aa61: { // 0x42aa61: e89aaa1100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4368998u); flags=s.arithmetic_flags;
  }
  L0042aa66: { // 0x42aa66: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0042aa6a: { // 0x42aa6a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042aa6f: { // 0x42aa6f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042aa70: { // 0x42aa70: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0042aa72: { // 0x42aa72: e889aa1100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4369015u); flags=s.arithmetic_flags;
  }
  L0042aa77: { // 0x42aa77: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0042aa7b: { // 0x42aa7b: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0042aa7d: { // 0x42aa7d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042aa7e: { // 0x42aa7e: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0042aa82: { // 0x42aa82: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042aa83: { // 0x42aa83: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042aa84: { // 0x42aa84: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042aa89: { // 0x42aa89: e8d2721300 CALL 0x00561d60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00561d60u,4369038u); flags=s.arithmetic_flags;
  }
  L0042aa8e: { // 0x42aa8e: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0042aa92: { // 0x42aa92: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042aa94: { // 0x42aa94: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042aa95: { // 0x42aa95: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0042aa99: { // 0x42aa99: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0042aa9d: { // 0x42aa9d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042aa9e: { // 0x42aa9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042aa9f: { // 0x42aa9f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042aaa4: { // 0x42aaa4: e8b7721300 CALL 0x00561d60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00561d60u,4369065u); flags=s.arithmetic_flags;
  }
  L0042aaa9: { // 0x42aaa9: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042aaab: { // 0x42aaab: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0042aaaf: { // 0x42aaaf: 8b7c2424 MOV EDI,dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L0042aab3: { // 0x42aab3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0042aab6: { // 0x42aab6: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0042aaba: { // 0x42aaba: 7518 JNZ 0x0042aad4
    if(integer::condition("JNZ",flags)) goto L0042aad4;
  }
  L0042aabc: { // 0x42aabc: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042aabe: { // 0x42aabe: 7412 JZ 0x0042aad2
    if(integer::condition("JZ",flags)) goto L0042aad2;
  }
  L0042aac0: { // 0x42aac0: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0042aac2: { // 0x42aac2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0042aac4: { // 0x42aac4: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4369098u); flags=s.arithmetic_flags;
  }
  L0042aaca: { // 0x42aaca: 8b8000050000 MOV EAX,dword ptr [EAX + 0x500]
    s.ax = m.r32((s.ax+0x00000500u));
  }
  L0042aad0: { // 0x42aad0: eb02 JMP 0x0042aad4
    goto L0042aad4;
  }
  L0042aad2: { // 0x42aad2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042aad4: { // 0x42aad4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042aad5: { // 0x42aad5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042aad6: { // 0x42aad6: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0042aada: { // 0x42aada: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0042aade: { // 0x42aade: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042aadf: { // 0x42aadf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042aae0: { // 0x42aae0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0042aae2: { // 0x42aae2: e879f0ffff CALL 0x00429b60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00429b60u,4369127u); flags=s.arithmetic_flags;
  }
  L0042aae7: { // 0x42aae7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042aae9: { // 0x42aae9: 0f8423020000 JZ 0x0042ad12
    if(integer::condition("JZ",flags)) goto L0042ad12;
  }
  L0042aaef: { // 0x42aaef: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0042aaf3: { // 0x42aaf3: 0fbf5602 MOVSX EDX,word ptr [ESI + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0042aaf7: { // 0x42aaf7: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0042aafb: { // 0x42aafb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042aafd: { // 0x42aafd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042aafe: { // 0x42aafe: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042ab00: { // 0x42ab00: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0042ab03: { // 0x42ab03: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L0042ab05: { // 0x42ab05: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042ab07: { // 0x42ab07: 0fbf16 MOVSX EDX,word ptr [ESI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0042ab0a: { // 0x42ab0a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042ab0c: { // 0x42ab0c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042ab0d: { // 0x42ab0d: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042ab0f: { // 0x42ab0f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042ab11: { // 0x42ab11: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042ab13: { // 0x42ab13: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0042ab17: { // 0x42ab17: 7f04 JG 0x0042ab1d
    if(integer::condition("JG",flags)) goto L0042ab1d;
  }
  L0042ab19: { // 0x42ab19: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0042ab1d: { // 0x42ab1d: 8bab740c0000 MOV EBP,dword ptr [EBX + 0xc74]
    s.bp = m.r32((s.bx+0x00000c74u));
  }
  L0042ab23: { // 0x42ab23: 8d442dfe LEA EAX,[EBP + EBP*0x1 + -0x2]
    s.ax = (s.bp+(s.bp * 0x00000001u)-0x00000002u);
  }
  L0042ab27: { // 0x42ab27: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0042ab2b: { // 0x42ab2b: 8a44242c MOV AL,byte ptr [ESP + 0x2c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000002cu)));
  }
  L0042ab2f: { // 0x42ab2f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042ab31: { // 0x42ab31: 0f84ff000000 JZ 0x0042ac36
    if(integer::condition("JZ",flags)) goto L0042ac36;
  }
  L0042ab37: { // 0x42ab37: 8a442428 MOV AL,byte ptr [ESP + 0x28]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000028u)));
  }
  L0042ab3b: { // 0x42ab3b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042ab3d: { // 0x42ab3d: 7435 JZ 0x0042ab74
    if(integer::condition("JZ",flags)) goto L0042ab74;
  }
  L0042ab3f: { // 0x42ab3f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ab41: { // 0x42ab41: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0042ab43: { // 0x42ab43: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ab44: { // 0x42ab44: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042ab49: { // 0x42ab49: e8122a1200 CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,4369230u); flags=s.arithmetic_flags;
  }
  L0042ab4e: { // 0x42ab4e: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0042ab52: { // 0x42ab52: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ab54: { // 0x42ab54: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0042ab56: { // 0x42ab56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042ab57: { // 0x42ab57: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042ab5c: { // 0x42ab5c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0042ab5e: { // 0x42ab5e: e8fd291200 CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,4369251u); flags=s.arithmetic_flags;
  }
  L0042ab63: { // 0x42ab63: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0042ab65: { // 0x42ab65: 7509 JNZ 0x0042ab70
    if(integer::condition("JNZ",flags)) goto L0042ab70;
  }
  L0042ab67: { // 0x42ab67: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0042ab6a: { // 0x42ab6a: 0f8594010000 JNZ 0x0042ad04
    if(integer::condition("JNZ",flags)) goto L0042ad04;
  }
  L0042ab70: { // 0x42ab70: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0042ab74: { // 0x42ab74: 83fd04 CMP EBP,0x4
    (void)integer::sub(s.bp,0x00000004u,32,flags);
  }
  L0042ab77: { // 0x42ab77: 7c3b JL 0x0042abb4
    if(integer::condition("JL",flags)) goto L0042abb4;
  }
  L0042ab79: { // 0x42ab79: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0042ab7b: { // 0x42ab7b: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L0042ab7f: { // 0x42ab7f: 668b946bb8000000 MOV DX,word ptr [EBX + EBP*0x2 + 0xb8]
    s.dx = with_ax(s.dx, m.r16((s.bx+(s.bp * 0x00000002u)+0x000000b8u)));
  }
  L0042ab87: { // 0x42ab87: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042ab8c: { // 0x42ab8c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042ab8d: { // 0x42ab8d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ab8f: { // 0x42ab8f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ab90: { // 0x42ab90: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042ab91: { // 0x42ab91: e86a781300 CALL 0x00562400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00562400u,4369302u); flags=s.arithmetic_flags;
  }
  L0042ab96: { // 0x42ab96: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042ab98: { // 0x42ab98: a1e86a8300 MOV EAX,[0x00836ae8]
    s.ax = m.r32((0x00836ae8u));
  }
  L0042ab9d: { // 0x42ab9d: 663bc8 CMP CX,AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0042aba0: { // 0x42aba0: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0042aba4: { // 0x42aba4: 755d JNZ 0x0042ac03
    if(integer::condition("JNZ",flags)) goto L0042ac03;
  }
  L0042aba6: { // 0x42aba6: 668b15ea6a8300 MOV DX,word ptr [0x00836aea]
    s.dx = with_ax(s.dx, m.r16((0x00836aeau)));
  }
  L0042abad: { // 0x42abad: 663954242e CMP word ptr [ESP + 0x2e],DX
    (void)integer::sub(m.r16((f.sp+0x0000002eu)),(s.dx & 0xffffu),16,flags);
  }
  L0042abb2: { // 0x42abb2: 752f JNZ 0x0042abe3
    if(integer::condition("JNZ",flags)) goto L0042abe3;
  }
  L0042abb4: { // 0x42abb4: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0042abb6: { // 0x42abb6: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0042abba: { // 0x42abba: 668b8c6bba000000 MOV CX,word ptr [EBX + EBP*0x2 + 0xba]
    s.cx = with_ax(s.cx, m.r16((s.bx+(s.bp * 0x00000002u)+0x000000bau)));
  }
  L0042abc2: { // 0x42abc2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042abc3: { // 0x42abc3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042abc5: { // 0x42abc5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042abc6: { // 0x42abc6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042abc7: { // 0x42abc7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042abcc: { // 0x42abcc: e82f781300 CALL 0x00562400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00562400u,4369361u); flags=s.arithmetic_flags;
  }
  L0042abd1: { // 0x42abd1: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042abd3: { // 0x42abd3: a1e86a8300 MOV EAX,[0x00836ae8]
    s.ax = m.r32((0x00836ae8u));
  }
  L0042abd8: { // 0x42abd8: 668b15ea6a8300 MOV DX,word ptr [0x00836aea]
    s.dx = with_ax(s.dx, m.r16((0x00836aeau)));
  }
  L0042abdf: { // 0x42abdf: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0042abe3: { // 0x42abe3: 663bc8 CMP CX,AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0042abe6: { // 0x42abe6: 751b JNZ 0x0042ac03
    if(integer::condition("JNZ",flags)) goto L0042ac03;
  }
  L0042abe8: { // 0x42abe8: 663954242e CMP word ptr [ESP + 0x2e],DX
    (void)integer::sub(m.r16((f.sp+0x0000002eu)),(s.dx & 0xffffu),16,flags);
  }
  L0042abed: { // 0x42abed: 7508 JNZ 0x0042abf7
    if(integer::condition("JNZ",flags)) goto L0042abf7;
  }
  L0042abef: { // 0x42abef: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0042abf3: { // 0x42abf3: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0042abf7: { // 0x42abf7: 663bc8 CMP CX,AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0042abfa: { // 0x42abfa: 7507 JNZ 0x0042ac03
    if(integer::condition("JNZ",flags)) goto L0042ac03;
  }
  L0042abfc: { // 0x42abfc: 663954242e CMP word ptr [ESP + 0x2e],DX
    (void)integer::sub(m.r16((f.sp+0x0000002eu)),(s.dx & 0xffffu),16,flags);
  }
  L0042ac01: { // 0x42ac01: 7433 JZ 0x0042ac36
    if(integer::condition("JZ",flags)) goto L0042ac36;
  }
  L0042ac03: { // 0x42ac03: 0fbf54242e MOVSX EDX,word ptr [ESP + 0x2e]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002eu)),16));
  }
  L0042ac08: { // 0x42ac08: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0042ac0c: { // 0x42ac0c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042ac0e: { // 0x42ac0e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042ac0f: { // 0x42ac0f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0042ac11: { // 0x42ac11: 0fbf06 MOVSX EAX,word ptr [ESI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0042ac14: { // 0x42ac14: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0042ac17: { // 0x42ac17: 33fa XOR EDI,EDX
    s.di = integer::logical((s.di)^(s.dx),32,flags);
  }
  L0042ac19: { // 0x42ac19: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0042ac1b: { // 0x42ac1b: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0042ac1d: { // 0x42ac1d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042ac1e: { // 0x42ac1e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042ac20: { // 0x42ac20: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042ac22: { // 0x42ac22: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0042ac24: { // 0x42ac24: 7f02 JG 0x0042ac28
    if(integer::condition("JG",flags)) goto L0042ac28;
  }
  L0042ac26: { // 0x42ac26: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0042ac28: { // 0x42ac28: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0042ac2c: { // 0x42ac2c: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0042ac30: { // 0x42ac30: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0042ac32: { // 0x42ac32: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0042ac36: { // 0x42ac36: 8a442428 MOV AL,byte ptr [ESP + 0x28]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000028u)));
  }
  L0042ac3a: { // 0x42ac3a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042ac3c: { // 0x42ac3c: 0f84b6000000 JZ 0x0042acf8
    if(integer::condition("JZ",flags)) goto L0042acf8;
  }
  L0042ac42: { // 0x42ac42: 83fd04 CMP EBP,0x4
    (void)integer::sub(s.bp,0x00000004u,32,flags);
  }
  L0042ac45: { // 0x42ac45: 7c3a JL 0x0042ac81
    if(integer::condition("JL",flags)) goto L0042ac81;
  }
  L0042ac47: { // 0x42ac47: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0042ac49: { // 0x42ac49: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0042ac4d: { // 0x42ac4d: 668b93be000000 MOV DX,word ptr [EBX + 0xbe]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x000000beu)));
  }
  L0042ac54: { // 0x42ac54: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042ac59: { // 0x42ac59: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042ac5a: { // 0x42ac5a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ac5c: { // 0x42ac5c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042ac5d: { // 0x42ac5d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042ac5e: { // 0x42ac5e: e89d771300 CALL 0x00562400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00562400u,4369507u); flags=s.arithmetic_flags;
  }
  L0042ac63: { // 0x42ac63: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042ac65: { // 0x42ac65: a1e86a8300 MOV EAX,[0x00836ae8]
    s.ax = m.r32((0x00836ae8u));
  }
  L0042ac6a: { // 0x42ac6a: 663bc8 CMP CX,AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0042ac6d: { // 0x42ac6d: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0042ac71: { // 0x42ac71: 755c JNZ 0x0042accf
    if(integer::condition("JNZ",flags)) goto L0042accf;
  }
  L0042ac73: { // 0x42ac73: 668b15ea6a8300 MOV DX,word ptr [0x00836aea]
    s.dx = with_ax(s.dx, m.r16((0x00836aeau)));
  }
  L0042ac7a: { // 0x42ac7a: 663954241e CMP word ptr [ESP + 0x1e],DX
    (void)integer::sub(m.r16((f.sp+0x0000001eu)),(s.dx & 0xffffu),16,flags);
  }
  L0042ac7f: { // 0x42ac7f: 752e JNZ 0x0042acaf
    if(integer::condition("JNZ",flags)) goto L0042acaf;
  }
  L0042ac81: { // 0x42ac81: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0042ac83: { // 0x42ac83: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0042ac87: { // 0x42ac87: 668b8bbc000000 MOV CX,word ptr [EBX + 0xbc]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x000000bcu)));
  }
  L0042ac8e: { // 0x42ac8e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042ac8f: { // 0x42ac8f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ac91: { // 0x42ac91: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042ac92: { // 0x42ac92: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042ac93: { // 0x42ac93: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042ac98: { // 0x42ac98: e863771300 CALL 0x00562400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00562400u,4369565u); flags=s.arithmetic_flags;
  }
  L0042ac9d: { // 0x42ac9d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0042ac9f: { // 0x42ac9f: a1e86a8300 MOV EAX,[0x00836ae8]
    s.ax = m.r32((0x00836ae8u));
  }
  L0042aca4: { // 0x42aca4: 668b15ea6a8300 MOV DX,word ptr [0x00836aea]
    s.dx = with_ax(s.dx, m.r16((0x00836aeau)));
  }
  L0042acab: { // 0x42acab: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0042acaf: { // 0x42acaf: 663bc8 CMP CX,AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0042acb2: { // 0x42acb2: 751b JNZ 0x0042accf
    if(integer::condition("JNZ",flags)) goto L0042accf;
  }
  L0042acb4: { // 0x42acb4: 663954241e CMP word ptr [ESP + 0x1e],DX
    (void)integer::sub(m.r16((f.sp+0x0000001eu)),(s.dx & 0xffffu),16,flags);
  }
  L0042acb9: { // 0x42acb9: 7508 JNZ 0x0042acc3
    if(integer::condition("JNZ",flags)) goto L0042acc3;
  }
  L0042acbb: { // 0x42acbb: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0042acbf: { // 0x42acbf: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0042acc3: { // 0x42acc3: 663bc8 CMP CX,AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0042acc6: { // 0x42acc6: 7507 JNZ 0x0042accf
    if(integer::condition("JNZ",flags)) goto L0042accf;
  }
  L0042acc8: { // 0x42acc8: 663954241e CMP word ptr [ESP + 0x1e],DX
    (void)integer::sub(m.r16((f.sp+0x0000001eu)),(s.dx & 0xffffu),16,flags);
  }
  L0042accd: { // 0x42accd: 7429 JZ 0x0042acf8
    if(integer::condition("JZ",flags)) goto L0042acf8;
  }
  L0042accf: { // 0x42accf: 0fbf54241e MOVSX EDX,word ptr [ESP + 0x1e]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001eu)),16));
  }
  L0042acd4: { // 0x42acd4: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L0042acd8: { // 0x42acd8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042acda: { // 0x42acda: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042acdb: { // 0x42acdb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0042acdd: { // 0x42acdd: 0fbf07 MOVSX EAX,word ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L0042ace0: { // 0x42ace0: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0042ace3: { // 0x42ace3: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0042ace5: { // 0x42ace5: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0042ace7: { // 0x42ace7: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0042ace9: { // 0x42ace9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042acea: { // 0x42acea: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0042acec: { // 0x42acec: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0042acee: { // 0x42acee: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0042acf0: { // 0x42acf0: 7f02 JG 0x0042acf4
    if(integer::condition("JG",flags)) goto L0042acf4;
  }
  L0042acf2: { // 0x42acf2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042acf4: { // 0x42acf4: 01442420 ADD dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), integer::add(m.r32((f.sp+0x00000020u)),s.ax,32,flags));
  }
  L0042acf8: { // 0x42acf8: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0042acfc: { // 0x42acfc: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0042ad00: { // 0x42ad00: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042ad02: { // 0x42ad02: 7f13 JG 0x0042ad17
    if(integer::condition("JG",flags)) goto L0042ad17;
  }
  L0042ad04: { // 0x42ad04: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0042ad08: { // 0x42ad08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042ad09: { // 0x42ad09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042ad0a: { // 0x42ad0a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042ad0b: { // 0x42ad0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042ad0c: { // 0x42ad0c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0042ad0f: { // 0x42ad0f: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0042ad12: { // 0x42ad12: b8ffffff7f MOV EAX,0x7fffffff
    s.ax = 0x7fffffffu;
  }
  L0042ad17: { // 0x42ad17: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042ad18: { // 0x42ad18: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042ad19: { // 0x42ad19: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042ad1a: { // 0x42ad1a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042ad1b: { // 0x42ad1b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0042ad1e: { // 0x42ad1e: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
