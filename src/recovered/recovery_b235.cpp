#include "recovered/recovery_b235_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b235 {
namespace {
void f_00028cf0(Memory&,State&,Frame&,const Operations&);
void f_00079d30(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0014b830(Memory&,State&,Frame&,const Operations&);
void f_000cabb0(Memory&,State&,Frame&,const Operations&);
void f_0002ad30(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_0002ad50(Memory&,State&,Frame&,const Operations&);
void f_00102650(Memory&,State&,Frame&,const Operations&);
void f_000c8330(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00028cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00428cf0: { // 0x428cf0: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00428cf3: { // 0x428cf3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00428cf4: { // 0x428cf4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00428cf5: { // 0x428cf5: 8b6c2444 MOV EBP,dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00428cf9: { // 0x428cf9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00428cfa: { // 0x428cfa: 8b742450 MOV ESI,dword ptr [ESP + 0x50]
    s.si = m.r32((f.sp+0x00000050u));
  }
  L00428cfe: { // 0x428cfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00428cff: { // 0x428cff: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00428d02: { // 0x428d02: 8b44b500 MOV EAX,dword ptr [EBP + ESI*0x4]
    s.ax = m.r32((s.bp+(s.si * 0x00000004u)));
  }
  L00428d06: { // 0x428d06: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00428d0a: { // 0x428d0a: 8d3c02 LEA EDI,[EDX + EAX*0x1]
    s.di = (s.dx+(s.ax * 0x00000001u));
  }
  L00428d0d: { // 0x428d0d: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00428d0f: { // 0x428d0f: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L00428d13: { // 0x428d13: 8d4f01 LEA ECX,[EDI + 0x1]
    s.cx = (s.di+0x00000001u);
  }
  L00428d16: { // 0x428d16: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00428d18: { // 0x428d18: 7410 JZ 0x00428d2a
    if(integer::condition("JZ",flags)) goto L00428d2a;
  }
  L00428d1a: { // 0x428d1a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00428d1c: { // 0x428d1c: 740c JZ 0x00428d2a
    if(integer::condition("JZ",flags)) goto L00428d2a;
  }
  L00428d1e: { // 0x428d1e: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00428d26: { // 0x428d26: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00428d2a: { // 0x428d2a: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  L00428d2d: { // 0x428d2d: 0f8441030000 JZ 0x00429074
    if(integer::condition("JZ",flags)) goto L00429074;
  }
  L00428d33: { // 0x428d33: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00428d36: { // 0x428d36: 0f8438030000 JZ 0x00429074
    if(integer::condition("JZ",flags)) goto L00429074;
  }
  L00428d3c: { // 0x428d3c: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L00428d40: { // 0x428d40: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L00428d44: { // 0x428d44: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00428d46: { // 0x428d46: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00428d48: { // 0x428d48: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428d4c: { // 0x428d4c: 7d09 JGE 0x00428d57
    if(integer::condition("JGE",flags)) goto L00428d57;
  }
  L00428d4e: { // 0x428d4e: 89742458 MOV dword ptr [ESP + 0x58],ESI
    m.w32((f.sp+0x00000058u), s.si);
  }
  L00428d52: { // 0x428d52: e981000000 JMP 0x00428dd8
    goto L00428dd8;
  }
  L00428d57: { // 0x428d57: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00428d59: { // 0x428d59: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L00428d5d: { // 0x428d5d: 7d79 JGE 0x00428dd8
    if(integer::condition("JGE",flags)) goto L00428dd8;
  }
  L00428d5f: { // 0x428d5f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00428d61: { // 0x428d61: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00428d65: { // 0x428d65: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00428d67: { // 0x428d67: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00428d69: { // 0x428d69: 7e69 JLE 0x00428dd4
    if(integer::condition("JLE",flags)) goto L00428dd4;
  }
  L00428d6b: { // 0x428d6b: 8bdd MOV EBX,EBP
    s.bx = s.bp;
  }
  L00428d6d: { // 0x428d6d: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00428d6f: { // 0x428d6f: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00428d71: { // 0x428d71: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00428d74: { // 0x428d74: 7538 JNZ 0x00428dae
    if(integer::condition("JNZ",flags)) goto L00428dae;
  }
  L00428d76: { // 0x428d76: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00428d7a: { // 0x428d7a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00428d7b: { // 0x428d7b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00428d80: { // 0x428d80: e87bc71100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4361605u); flags=s.arithmetic_flags;
  }
  L00428d85: { // 0x428d85: 0fbf8016010000 MOVSX EAX,word ptr [EAX + 0x116]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000116u)),16));
  }
  L00428d8c: { // 0x428d8c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00428d8f: { // 0x428d8f: 740e JZ 0x00428d9f
    if(integer::condition("JZ",flags)) goto L00428d9f;
  }
  L00428d91: { // 0x428d91: 8b15fce48400 MOV EDX,dword ptr [0x0084e4fc]
    s.dx = m.r32((0x0084e4fcu));
  }
  L00428d97: { // 0x428d97: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00428d9a: { // 0x428d9a: 8b4028 MOV EAX,dword ptr [EAX + 0x28]
    s.ax = m.r32((s.ax+0x00000028u));
  }
  L00428d9d: { // 0x428d9d: eb27 JMP 0x00428dc6
    goto L00428dc6;
  }
  L00428d9f: { // 0x428d9f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00428da1: { // 0x428da1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00428da3: { // 0x428da3: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00428da7: { // 0x428da7: e8841f0000 CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,4361644u); flags=s.arithmetic_flags;
  }
  L00428dac: { // 0x428dac: eb16 JMP 0x00428dc4
    goto L00428dc4;
  }
  L00428dae: { // 0x428dae: 8d0c85a09d8300 LEA ECX,[EAX*0x4 + 0x839da0]
    s.cx = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00428db5: { // 0x428db5: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00428db9: { // 0x428db9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00428dba: { // 0x428dba: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00428dbb: { // 0x428dbb: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00428dbf: { // 0x428dbf: e80c200000 CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,4361668u); flags=s.arithmetic_flags;
  }
  L00428dc4: { // 0x428dc4: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00428dc6: { // 0x428dc6: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L00428dc9: { // 0x428dc9: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L00428dca: { // 0x428dca: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00428dce: { // 0x428dce: 759f JNZ 0x00428d6f
    if(integer::condition("JNZ",flags)) goto L00428d6f;
  }
  L00428dd0: { // 0x428dd0: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L00428dd4: { // 0x428dd4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428dd8: { // 0x428dd8: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L00428ddc: { // 0x428ddc: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00428dde: { // 0x428dde: e8cd1d0a00 CALL 0x004cabb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004cabb0u,4361699u); flags=s.arithmetic_flags;
  }
  L00428de3: { // 0x428de3: 8b83b4010000 MOV EAX,dword ptr [EBX + 0x1b4]
    s.ax = m.r32((s.bx+0x000001b4u));
  }
  L00428de9: { // 0x428de9: dd5c243c FSTP double ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00428ded: { // 0x428ded: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00428df1: { // 0x428df1: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00428df5: { // 0x428df5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00428df7: { // 0x428df7: 0f8e96010000 JLE 0x00428f93
    if(integer::condition("JLE",flags)) goto L00428f93;
  }
  L00428dfd: { // 0x428dfd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00428dff: { // 0x428dff: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00428e03: { // 0x428e03: 83e707 AND EDI,0x7
    s.di = integer::logical((s.di)&(0x00000007u),32,flags);
  }
  L00428e06: { // 0x428e06: 03c9 ADD ECX,ECX
    s.cx = integer::add(s.cx,s.cx,32,flags);
  }
  L00428e08: { // 0x428e08: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00428e0c: { // 0x428e0c: 8d2cbda09d8300 LEA EBP,[EDI*0x4 + 0x839da0]
    s.bp = ((s.di * 0x00000004u)+0x00839da0u);
  }
  L00428e13: { // 0x428e13: eb04 JMP 0x00428e19
    goto L00428e19;
  }
  L00428e15: { // 0x428e15: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00428e19: { // 0x428e19: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L00428e1d: { // 0x428e1d: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00428e21: { // 0x428e21: 6603d0 ADD DX,AX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L00428e24: { // 0x428e24: 668b4502 MOV AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L00428e28: { // 0x428e28: 6603442412 ADD AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L00428e2d: { // 0x428e2d: 6689542424 MOV word ptr [ESP + 0x24],DX
    m.w16((f.sp+0x00000024u), (s.dx & 0xffffu));
  }
  L00428e32: { // 0x428e32: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L00428e34: { // 0x428e34: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L00428e39: { // 0x428e39: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00428e3d: { // 0x428e3d: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00428e41: { // 0x428e41: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00428e43: { // 0x428e43: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L00428e47: { // 0x428e47: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00428e49: { // 0x428e49: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00428e4d: { // 0x428e4d: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00428e51: { // 0x428e51: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00428e54: { // 0x428e54: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00428e55: { // 0x428e55: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00428e5a: { // 0x428e5a: e8a1c61100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4361823u); flags=s.arithmetic_flags;
  }
  L00428e5f: { // 0x428e5f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00428e61: { // 0x428e61: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00428e65: { // 0x428e65: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00428e67: { // 0x428e67: 0f8ec0000000 JLE 0x00428f2d
    if(integer::condition("JLE",flags)) goto L00428f2d;
  }
  L00428e6d: { // 0x428e6d: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00428e71: { // 0x428e71: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00428e75: { // 0x428e75: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00428e77: { // 0x428e77: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00428e79: { // 0x428e79: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00428e7b: { // 0x428e7b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00428e7c: { // 0x428e7c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00428e7d: { // 0x428e7d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00428e7e: { // 0x428e7e: ff9094010000 CALL dword ptr [EAX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000194u)),4361860u); flags=s.arithmetic_flags;
  }
  L00428e84: { // 0x428e84: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00428e86: { // 0x428e86: 753d JNZ 0x00428ec5
    if(integer::condition("JNZ",flags)) goto L00428ec5;
  }
  L00428e88: { // 0x428e88: f7874001000000000400 TEST dword ptr [EDI + 0x140],0x40000
    (void)integer::logical((m.r32((s.di+0x00000140u)))&(0x00040000u),32,flags);
  }
  L00428e92: { // 0x428e92: 7531 JNZ 0x00428ec5
    if(integer::condition("JNZ",flags)) goto L00428ec5;
  }
  L00428e94: { // 0x428e94: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00428e98: { // 0x428e98: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00428e9c: { // 0x428e9c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00428e9d: { // 0x428e9d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00428e9e: { // 0x428e9e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00428ea3: { // 0x428ea3: e888291200 CALL 0x0054b830
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054b830u,4361896u); flags=s.arithmetic_flags;
  }
  L00428ea8: { // 0x428ea8: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00428eac: { // 0x428eac: db442434 FILD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L00428eb0: { // 0x428eb0: dc4c243c FMUL double ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.multiply64(read64(m,address));
  }
  L00428eb4: { // 0x428eb4: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00428eba: { // 0x428eba: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00428ebc: { // 0x428ebc: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00428ebf: { // 0x428ebf: 7404 JZ 0x00428ec5
    if(integer::condition("JZ",flags)) goto L00428ec5;
  }
  L00428ec1: { // 0x428ec1: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L00428ec3: { // 0x428ec3: eb02 JMP 0x00428ec7
    goto L00428ec7;
  }
  L00428ec5: { // 0x428ec5: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L00428ec7: { // 0x428ec7: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00428ecb: { // 0x428ecb: 668b5500 MOV DX,word ptr [EBP]
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L00428ecf: { // 0x428ecf: 6603542414 ADD DX,word ptr [ESP + 0x14]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000014u)),16,flags));
  }
  L00428ed4: { // 0x428ed4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00428ed5: { // 0x428ed5: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00428ed9: { // 0x428ed9: 668b4502 MOV AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L00428edd: { // 0x428edd: 6603442416 ADD AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L00428ee2: { // 0x428ee2: 6689542428 MOV word ptr [ESP + 0x28],DX
    m.w16((f.sp+0x00000028u), (s.dx & 0xffffu));
  }
  L00428ee7: { // 0x428ee7: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00428eeb: { // 0x428eeb: 668944242a MOV word ptr [ESP + 0x2a],AX
    m.w16((f.sp+0x0000002au), (s.ax & 0xffffu));
  }
  L00428ef0: { // 0x428ef0: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00428ef4: { // 0x428ef4: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00428ef8: { // 0x428ef8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00428ef9: { // 0x428ef9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00428efe: { // 0x428efe: e8fdc51100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4361987u); flags=s.arithmetic_flags;
  }
  L00428f03: { // 0x428f03: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00428f05: { // 0x428f05: 0fbe871b010000 MOVSX EAX,byte ptr [EDI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L00428f0c: { // 0x428f0c: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00428f0e: { // 0x428f0e: 83fe04 CMP ESI,0x4
    (void)integer::sub(s.si,0x00000004u,32,flags);
  }
  L00428f11: { // 0x428f11: 750e JNZ 0x00428f21
    if(integer::condition("JNZ",flags)) goto L00428f21;
  }
  L00428f13: { // 0x428f13: 8b8f40010000 MOV ECX,dword ptr [EDI + 0x140]
    s.cx = m.r32((s.di+0x00000140u));
  }
  L00428f19: { // 0x428f19: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L00428f1c: { // 0x428f1c: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00428f1f: { // 0x428f1f: 7502 JNZ 0x00428f23
    if(integer::condition("JNZ",flags)) goto L00428f23;
  }
  L00428f21: { // 0x428f21: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00428f23: { // 0x428f23: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00428f25: { // 0x428f25: 0f8436ffffff JZ 0x00428e61
    if(integer::condition("JZ",flags)) goto L00428e61;
  }
  L00428f2b: { // 0x428f2b: eb08 JMP 0x00428f35
    goto L00428f35;
  }
  L00428f2d: { // 0x428f2d: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00428f2f: { // 0x428f2f: 0f849e000000 JZ 0x00428fd3
    if(integer::condition("JZ",flags)) goto L00428fd3;
  }
  L00428f35: { // 0x428f35: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00428f39: { // 0x428f39: 668b4c2410 MOV CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000010u)));
  }
  L00428f3e: { // 0x428f3e: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L00428f41: { // 0x428f41: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L00428f45: { // 0x428f45: 83ee02 SUB ESI,0x2
    s.si = integer::sub(s.si,0x00000002u,32,flags);
  }
  L00428f48: { // 0x428f48: 66030c85a09d8300 ADD CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.ax * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L00428f50: { // 0x428f50: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L00428f58: { // 0x428f58: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L00428f5d: { // 0x428f5d: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00428f64: { // 0x428f64: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L00428f69: { // 0x428f69: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L00428f6d: { // 0x428f6d: 668954242e MOV word ptr [ESP + 0x2e],DX
    m.w16((f.sp+0x0000002eu), (s.dx & 0xffffu));
  }
  L00428f72: { // 0x428f72: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00428f76: { // 0x428f76: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00428f77: { // 0x428f77: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L00428f7b: { // 0x428f7b: 8b742454 MOV ESI,dword ptr [ESP + 0x54]
    s.si = m.r32((f.sp+0x00000054u));
  }
  L00428f7f: { // 0x428f7f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428f83: { // 0x428f83: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00428f85: { // 0x428f85: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L00428f89: { // 0x428f89: 0f8f86feffff JG 0x00428e15
    if(integer::condition("JG",flags)) goto L00428e15;
  }
  L00428f8f: { // 0x428f8f: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L00428f93: { // 0x428f93: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00428f97: { // 0x428f97: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00428f99: { // 0x428f99: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00428f9b: { // 0x428f9b: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00428f9f: { // 0x428f9f: 7e20 JLE 0x00428fc1
    if(integer::condition("JLE",flags)) goto L00428fc1;
  }
  L00428fa1: { // 0x428fa1: 8bfd MOV EDI,EBP
    s.di = s.bp;
  }
  L00428fa3: { // 0x428fa3: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00428fa5: { // 0x428fa5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00428fa7: { // 0x428fa7: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L00428fab: { // 0x428fab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00428fac: { // 0x428fac: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L00428fb0: { // 0x428fb0: e89b1d0000 CALL 0x0042ad50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad50u,4362165u); flags=s.arithmetic_flags;
  }
  L00428fb5: { // 0x428fb5: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00428fb7: { // 0x428fb7: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00428fba: { // 0x428fba: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00428fbb: { // 0x428fbb: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00428fbf: { // 0x428fbf: 75e4 JNZ 0x00428fa5
    if(integer::condition("JNZ",flags)) goto L00428fa5;
  }
  L00428fc1: { // 0x428fc1: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00428fc5: { // 0x428fc5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00428fc6: { // 0x428fc6: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00428fc8: { // 0x428fc8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00428fca: { // 0x428fca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00428fcb: { // 0x428fcb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00428fcc: { // 0x428fcc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00428fcd: { // 0x428fcd: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L00428fd0: { // 0x428fd0: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L00428fd3: { // 0x428fd3: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00428fd7: { // 0x428fd7: 8b742454 MOV ESI,dword ptr [ESP + 0x54]
    s.si = m.r32((f.sp+0x00000054u));
  }
  L00428fdb: { // 0x428fdb: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00428fdf: { // 0x428fdf: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00428fe1: { // 0x428fe1: 8d0c00 LEA ECX,[EAX + EAX*0x1]
    s.cx = (s.ax+(s.ax * 0x00000001u));
  }
  L00428fe4: { // 0x428fe4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00428fe6: { // 0x428fe6: 8d3cb2 LEA EDI,[EDX + ESI*0x4]
    s.di = (s.dx+(s.si * 0x00000004u));
  }
  L00428fe9: { // 0x428fe9: 7e06 JLE 0x00428ff1
    if(integer::condition("JLE",flags)) goto L00428ff1;
  }
  L00428feb: { // 0x428feb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00428fef: { // 0x428fef: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L00428ff1: { // 0x428ff1: 8b6c245c MOV EBP,dword ptr [ESP + 0x5c]
    s.bp = m.r32((f.sp+0x0000005cu));
  }
  L00428ff5: { // 0x428ff5: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00428ff7: { // 0x428ff7: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00428ffa: { // 0x428ffa: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L00428ffe: { // 0x428ffe: 7e65 JLE 0x00429065
    if(integer::condition("JLE",flags)) goto L00429065;
  }
  L00429000: { // 0x429000: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00429002: { // 0x429002: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00429004: { // 0x429004: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00429006: { // 0x429006: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00429009: { // 0x429009: 7538 JNZ 0x00429043
    if(integer::condition("JNZ",flags)) goto L00429043;
  }
  L0042900b: { // 0x42900b: 8d44245c LEA EAX,[ESP + 0x5c]
    s.ax = (f.sp+0x0000005cu);
  }
  L0042900f: { // 0x42900f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00429014: { // 0x429014: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429015: { // 0x429015: e8e6c41100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4362266u); flags=s.arithmetic_flags;
  }
  L0042901a: { // 0x42901a: 0fbf8016010000 MOVSX EAX,word ptr [EAX + 0x116]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000116u)),16));
  }
  L00429021: { // 0x429021: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00429024: { // 0x429024: 740e JZ 0x00429034
    if(integer::condition("JZ",flags)) goto L00429034;
  }
  L00429026: { // 0x429026: 8b0dfce48400 MOV ECX,dword ptr [0x0084e4fc]
    s.cx = m.r32((0x0084e4fcu));
  }
  L0042902c: { // 0x42902c: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0042902f: { // 0x42902f: 8b4228 MOV EAX,dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  L00429032: { // 0x429032: eb27 JMP 0x0042905b
    goto L0042905b;
  }
  L00429034: { // 0x429034: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00429036: { // 0x429036: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00429038: { // 0x429038: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L0042903c: { // 0x42903c: e8ef1c0000 CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,4362305u); flags=s.arithmetic_flags;
  }
  L00429041: { // 0x429041: eb16 JMP 0x00429059
    goto L00429059;
  }
  L00429043: { // 0x429043: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L0042904a: { // 0x42904a: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L0042904e: { // 0x42904e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042904f: { // 0x42904f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00429050: { // 0x429050: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L00429054: { // 0x429054: e8771d0000 CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,4362329u); flags=s.arithmetic_flags;
  }
  L00429059: { // 0x429059: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0042905b: { // 0x42905b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0042905e: { // 0x42905e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0042905f: { // 0x42905f: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L00429063: { // 0x429063: 759f JNZ 0x00429004
    if(integer::condition("JNZ",flags)) goto L00429004;
  }
  L00429065: { // 0x429065: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  L00429068: { // 0x429068: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042906a: { // 0x42906a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042906b: { // 0x42906b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042906c: { // 0x42906c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042906d: { // 0x42906d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042906e: { // 0x42906e: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L00429071: { // 0x429071: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L00429074: { // 0x429074: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L00429078: { // 0x429078: 8b6c245c MOV EBP,dword ptr [ESP + 0x5c]
    s.bp = m.r32((f.sp+0x0000005cu));
  }
  L0042907c: { // 0x42907c: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0042907f: { // 0x42907f: 8d1c16 LEA EBX,[ESI + EDX*0x1]
    s.bx = (s.si+(s.dx * 0x00000001u));
  }
  L00429082: { // 0x429082: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00429084: { // 0x429084: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L00429088: { // 0x429088: 7e22 JLE 0x004290ac
    if(integer::condition("JLE",flags)) goto L004290ac;
  }
  L0042908a: { // 0x42908a: 8b74244c MOV ESI,dword ptr [ESP + 0x4c]
    s.si = m.r32((f.sp+0x0000004cu));
  }
  L0042908e: { // 0x42908e: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L00429090: { // 0x429090: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00429092: { // 0x429092: 8d54245c LEA EDX,[ESP + 0x5c]
    s.dx = (f.sp+0x0000005cu);
  }
  L00429096: { // 0x429096: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00429097: { // 0x429097: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0042909b: { // 0x42909b: e8b01c0000 CALL 0x0042ad50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad50u,4362400u); flags=s.arithmetic_flags;
  }
  L004290a0: { // 0x4290a0: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004290a2: { // 0x4290a2: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004290a5: { // 0x4290a5: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L004290a6: { // 0x4290a6: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L004290aa: { // 0x4290aa: 75e4 JNZ 0x00429090
    if(integer::condition("JNZ",flags)) goto L00429090;
  }
  L004290ac: { // 0x4290ac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004290ad: { // 0x4290ad: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  L004290b0: { // 0x4290b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004290b1: { // 0x4290b1: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004290b3: { // 0x4290b3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004290b4: { // 0x4290b4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004290b5: { // 0x4290b5: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L004290b8: { // 0x4290b8: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
}
void f_00079d30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00479d30: { // 0x479d30: 668b8116010000 MOV AX,word ptr [ECX + 0x116]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x00000116u)));
  }
  L00479d37: { // 0x479d37: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L00479d3a: { // 0x479d3a: 7c17 JL 0x00479d53
    if(integer::condition("JL",flags)) goto L00479d53;
  }
  L00479d3c: { // 0x479d3c: 8b0d08e58400 MOV ECX,dword ptr [0x0084e508]
    s.cx = m.r32((0x0084e508u));
  }
  L00479d42: { // 0x479d42: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00479d45: { // 0x479d45: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00479d47: { // 0x479d47: 7d0a JGE 0x00479d53
    if(integer::condition("JGE",flags)) goto L00479d53;
  }
  L00479d49: { // 0x479d49: 8b0dfce48400 MOV ECX,dword ptr [0x0084e4fc]
    s.cx = m.r32((0x0084e4fcu));
  }
  L00479d4f: { // 0x479d4f: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00479d52: { // 0x479d52: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00479d53: { // 0x479d53: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00479d55: { // 0x479d55: c3 RET
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
void f_0014b830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054b830: { // 0x54b830: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0054b834: { // 0x54b834: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0054b838: { // 0x54b838: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0054b83b: { // 0x54b83b: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054b83e: { // 0x54b83e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054b840: { // 0x54b840: 7814 JS 0x0054b856
    if(integer::condition("JS",flags)) goto L0054b856;
  }
  L0054b842: { // 0x54b842: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054b847: { // 0x54b847: 7d0d JGE 0x0054b856
    if(integer::condition("JGE",flags)) goto L0054b856;
  }
  L0054b849: { // 0x54b849: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054b84f: { // 0x54b84f: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054b852: { // 0x54b852: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054b854: { // 0x54b854: 750c JNZ 0x0054b862
    if(integer::condition("JNZ",flags)) goto L0054b862;
  }
  L0054b856: { // 0x54b856: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0054b858: { // 0x54b858: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054b85d: { // 0x54b85d: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054b862: { // 0x54b862: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L0054b865: { // 0x54b865: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054b866: { // 0x54b866: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L0054b86a: { // 0x54b86a: 0fbf44240a MOVSX EAX,word ptr [ESP + 0xa]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000000au)),16));
  }
  L0054b86f: { // 0x54b86f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054b870: { // 0x54b870: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0054b873: { // 0x54b873: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054b875: { // 0x54b875: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L0054b878: { // 0x54b878: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0054b87a: { // 0x54b87a: c1e606 SHL ESI,0x6
    s.si = integer::shift(s.si,0x00000006u,32,flags,integer::Shift::left);
  }
  L0054b87d: { // 0x54b87d: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0054b87f: { // 0x54b87f: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054b882: { // 0x54b882: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054b883: { // 0x54b883: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0054b886: { // 0x54b886: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054b888: { // 0x54b888: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L0054b88c: { // 0x54b88c: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L0054b88f: { // 0x54b88f: 8d0c70 LEA ECX,[EAX + ESI*0x2]
    s.cx = (s.ax+(s.si * 0x00000002u));
  }
  L0054b892: { // 0x54b892: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054b893: { // 0x54b893: 8b848adc580000 MOV EAX,dword ptr [EDX + ECX*0x4 + 0x58dc]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)+0x000058dcu));
  }
  L0054b89a: { // 0x54b89a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000cabb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cabb0: { // 0x4cabb0: 8b81c4040000 MOV EAX,dword ptr [ECX + 0x4c4]
    s.ax = m.r32((s.cx+0x000004c4u));
  }
  L004cabb6: { // 0x4cabb6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004cabb8: { // 0x4cabb8: 7414 JZ 0x004cabce
    if(integer::condition("JZ",flags)) goto L004cabce;
  }
  L004cabba: { // 0x4cabba: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L004cabbd: { // 0x4cabbd: 8a90ea000000 MOV DL,byte ptr [EAX + 0xea]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000000eau)));
  }
  L004cabc3: { // 0x4cabc3: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004cabc5: { // 0x4cabc5: 7407 JZ 0x004cabce
    if(integer::condition("JZ",flags)) goto L004cabce;
  }
  L004cabc7: { // 0x4cabc7: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L004cabcd: { // 0x4cabcd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004cabce: { // 0x4cabce: dd8128040000 FLD double ptr [ECX + 0x428]
    const auto address=(s.cx+0x00000428u);
    s.fp.load64(read64(m,address));
  }
  L004cabd4: { // 0x4cabd4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_0002ad50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ad50: { // 0x0042ad50: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0042ad54: { // 0x0042ad54: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ad55: { // 0x0042ad55: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0042ad58: { // 0x0042ad58: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042ad5a: { // 0x0042ad5a: 7543 JNZ 0x0042ad9f
    if(integer::condition("JNZ",flags)) goto L0042ad9f;
  }
  L0042ad5c: { // 0x0042ad5c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042ad5d: { // 0x0042ad5d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042ad62: { // 0x0042ad62: e899a71100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4369767u); flags=s.arithmetic_flags;
  }
  L0042ad67: { // 0x0042ad67: 0fbf8016010000 MOVSX EAX,word ptr [EAX + 0x116]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000116u)),16));
  }
  L0042ad6e: { // 0x0042ad6e: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0042ad71: { // 0x0042ad71: 7414 JZ 0x0042ad87
    if(integer::condition("JZ",flags)) goto L0042ad87;
  }
  L0042ad73: { // 0x0042ad73: 8b0dfce48400 MOV ECX,dword ptr [0x0084e4fc]
    s.cx = m.r32((0x0084e4fcu));
  }
  L0042ad79: { // 0x0042ad79: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0042ad7c: { // 0x0042ad7c: 8b4228 MOV EAX,dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  L0042ad7f: { // 0x0042ad7f: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0042ad81: { // 0x0042ad81: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042ad83: { // 0x0042ad83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042ad84: { // 0x0042ad84: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0042ad87: { // 0x0042ad87: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042ad89: { // 0x0042ad89: 6689442408 MOV word ptr [ESP + 0x8],AX
    m.w16((f.sp+0x00000008u), (s.ax & 0xffffu));
  }
  L0042ad8e: { // 0x0042ad8e: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L0042ad93: { // 0x0042ad93: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0042ad97: { // 0x0042ad97: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0042ad99: { // 0x0042ad99: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042ad9b: { // 0x0042ad9b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042ad9c: { // 0x0042ad9c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0042ad9f: { // 0x0042ad9f: 668b0a MOV CX,word ptr [EDX]
    s.cx = with_ax(s.cx, m.r16((s.dx)));
  }
  L0042ada2: { // 0x0042ada2: 66030c85a09d8300 ADD CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.ax * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L0042adaa: { // 0x0042adaa: 668b0485a29d8300 MOV AX,word ptr [EAX*0x4 + 0x839da2]
    s.ax = with_ax(s.ax, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L0042adb2: { // 0x0042adb2: 66034202 ADD AX,word ptr [EDX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L0042adb6: { // 0x0042adb6: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L0042adbb: { // 0x0042adbb: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L0042adc0: { // 0x0042adc0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0042adc4: { // 0x0042adc4: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0042adc6: { // 0x0042adc6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042adc8: { // 0x0042adc8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042adc9: { // 0x0042adc9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00102650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00502650: { // 0x502650: 83ec24 SUB ESP, 0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L00502653: { // 0x502653: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00502654: { // 0x502654: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00502655: { // 0x502655: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L00502657: { // 0x502657: bb00010000 MOV EBX, 0x100
    s.bx = 0x00000100u;
  }
  L0050265c: { // 0x50265c: 8b4c2430 MOV ECX, dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00502660: { // 0x502660: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00502661: { // 0x502661: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00502662: { // 0x502662: 859940010000 TEST dword ptr [ECX + 0x140], EBX
    (void)integer::logical((m.r32((s.cx+0x00000140u)))&(s.bx),32,flags);
  }
  L00502668: { // 0x502668: 7423 JZ 0x50268D
    if(integer::condition("JZ",flags)) goto L0050268d;
  }
  L0050266a: { // 0x50266a: 8b442440 MOV EAX, dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L0050266e: { // 0x50266e: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00502671: { // 0x502671: 7413 JZ 0x502686
    if(integer::condition("JZ",flags)) goto L00502686;
  }
  L00502673: { // 0x502673: 0fbe911b010000 MOVSX EDX, byte ptr [ECX + 0x11B]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L0050267a: { // 0x50267a: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0050267c: { // 0x50267c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0050267d: { // 0x50267d: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0050267f: { // 0x50267f: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00502681: { // 0x502681: 83f801 CMP EAX, 1
    (void)integer::sub(s.ax,1u,32,flags);
  }
  L00502684: { // 0x502684: 7e07 JLE 0x50268D
    if(integer::condition("JLE",flags)) goto L0050268d;
  }
  L00502686: { // 0x502686: c644241101 MOV byte ptr [ESP + 0x11], 1
    m.w8((f.sp+0x00000011u), 1u);
  }
  L0050268b: { // 0x50268b: eb05 JMP 0x502692
    goto L00502692;
  }
  L0050268d: { // 0x50268d: c644241100 MOV byte ptr [ESP + 0x11], 0
    m.w8((f.sp+0x00000011u), 0u);
  }
  L00502692: { // 0x502692: 8a8124010000 MOV AL, byte ptr [ECX + 0x124]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000124u)));
  }
  L00502698: { // 0x502698: 8b5154 MOV EDX, dword ptr [ECX + 0x54]
    s.dx = m.r32((s.cx+0x00000054u));
  }
  L0050269b: { // 0x50269b: 88442412 MOV byte ptr [ESP + 0x12], AL
    m.w8((f.sp+0x00000012u), (s.ax & 0xffu));
  }
  L0050269f: { // 0x50269f: 8b8124010000 MOV EAX, dword ptr [ECX + 0x124]
    s.ax = m.r32((s.cx+0x00000124u));
  }
  L005026a5: { // 0x5026a5: c1e805 SHR EAX, 5
    s.ax = integer::shift(s.ax,5u,32,flags,integer::Shift::right);
  }
  L005026a8: { // 0x5026a8: 2401 AND AL, 1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(1u),8,flags));
  }
  L005026aa: { // 0x5026aa: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005026ae: { // 0x5026ae: 88442413 MOV byte ptr [ESP + 0x13], AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L005026b2: { // 0x5026b2: e87976f7ff CALL 0x479D30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479d30u,5252791u); flags=s.arithmetic_flags;
  }
  L005026b7: { // 0x5026b7: 8b7c243c MOV EDI, dword ptr [ESP + 0x3C]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L005026bb: { // 0x5026bb: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L005026bd: { // 0x5026bd: 83ff08 CMP EDI, 8
    (void)integer::sub(s.di,8u,32,flags);
  }
  L005026c0: { // 0x5026c0: 7537 JNZ 0x5026F9
    if(integer::condition("JNZ",flags)) goto L005026f9;
  }
  L005026c2: { // 0x5026c2: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005026c4: { // 0x5026c4: 0f846a070000 JZ 0x502E34
    if(integer::condition("JZ",flags)) goto L00502e34;
  }
  L005026ca: { // 0x5026ca: 8b4124 MOV EAX, dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  L005026cd: { // 0x5026cd: 8b4928 MOV ECX, dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  L005026d0: { // 0x5026d0: 663bc8 CMP CX, AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L005026d3: { // 0x5026d3: 8944243c MOV dword ptr [ESP + 0x3C], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L005026d7: { // 0x5026d7: 894c2438 MOV dword ptr [ESP + 0x38], ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L005026db: { // 0x5026db: 7510 JNZ 0x5026ED
    if(integer::condition("JNZ",flags)) goto L005026ed;
  }
  L005026dd: { // 0x5026dd: 668b44243a MOV AX, word ptr [ESP + 0x3A]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000003au)));
  }
  L005026e2: { // 0x5026e2: 663b44243e CMP AX, word ptr [ESP + 0x3E]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000003eu)),16,flags);
  }
  L005026e7: { // 0x5026e7: 0f8447070000 JZ 0x502E34
    if(integer::condition("JZ",flags)) goto L00502e34;
  }
  L005026ed: { // 0x5026ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005026ee: { // 0x5026ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005026ef: { // 0x5026ef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005026f0: { // 0x5026f0: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005026f2: { // 0x5026f2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005026f3: { // 0x5026f3: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L005026f6: { // 0x5026f6: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L005026f9: { // 0x5026f9: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005026fb: { // 0x5026fb: 742a JZ 0x502727
    if(integer::condition("JZ",flags)) goto L00502727;
  }
  L005026fd: { // 0x5026fd: 8b512c MOV EDX, dword ptr [ECX + 0x2C]
    s.dx = m.r32((s.cx+0x0000002cu));
  }
  L00502700: { // 0x502700: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00502702: { // 0x502702: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00502704: { // 0x502704: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00502705: { // 0x502705: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00502707: { // 0x502707: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00502709: { // 0x502709: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L0050270c: { // 0x50270c: 7e19 JLE 0x502727
    if(integer::condition("JLE",flags)) goto L00502727;
  }
  L0050270e: { // 0x50270e: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L00502711: { // 0x502711: 7d14 JGE 0x502727
    if(integer::condition("JGE",flags)) goto L00502727;
  }
  L00502713: { // 0x502713: 83ffff CMP EDI, -1
    (void)integer::sub(s.di,4294967295u,32,flags);
  }
  L00502716: { // 0x502716: 740f JZ 0x502727
    if(integer::condition("JZ",flags)) goto L00502727;
  }
  L00502718: { // 0x502718: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502719: { // 0x502719: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050271a: { // 0x50271a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0050271b: { // 0x50271b: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L00502720: { // 0x502720: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502721: { // 0x502721: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502724: { // 0x502724: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502727: { // 0x502727: 8b4c2438 MOV ECX, dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0050272b: { // 0x50272b: 8d77fc LEA ESI, [EDI - 4]
    s.si = (s.di-4u);
  }
  L0050272e: { // 0x50272e: 83e607 AND ESI, 7
    s.si = integer::logical((s.si)&(7u),32,flags);
  }
  L00502731: { // 0x502731: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00502732: { // 0x502732: e8893ff7ff CALL 0x4766C0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5252919u); flags=s.arithmetic_flags;
  }
  L00502737: { // 0x502737: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00502739: { // 0x502739: e8f275f7ff CALL 0x479D30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479d30u,5252926u); flags=s.arithmetic_flags;
  }
  L0050273e: { // 0x50273e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00502740: { // 0x502740: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00502742: { // 0x502742: 742a JZ 0x50276E
    if(integer::condition("JZ",flags)) goto L0050276e;
  }
  L00502744: { // 0x502744: 8b512c MOV EDX, dword ptr [ECX + 0x2C]
    s.dx = m.r32((s.cx+0x0000002cu));
  }
  L00502747: { // 0x502747: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L00502749: { // 0x502749: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0050274b: { // 0x50274b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0050274c: { // 0x50274c: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0050274e: { // 0x50274e: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00502750: { // 0x502750: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L00502753: { // 0x502753: 7e19 JLE 0x50276E
    if(integer::condition("JLE",flags)) goto L0050276e;
  }
  L00502755: { // 0x502755: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L00502758: { // 0x502758: 7d14 JGE 0x50276E
    if(integer::condition("JGE",flags)) goto L0050276e;
  }
  L0050275a: { // 0x50275a: 83ffff CMP EDI, -1
    (void)integer::sub(s.di,4294967295u,32,flags);
  }
  L0050275d: { // 0x50275d: 740f JZ 0x50276E
    if(integer::condition("JZ",flags)) goto L0050276e;
  }
  L0050275f: { // 0x50275f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502760: { // 0x502760: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502761: { // 0x502761: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502762: { // 0x502762: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L00502767: { // 0x502767: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502768: { // 0x502768: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L0050276b: { // 0x50276b: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0050276e: { // 0x50276e: 8b742438 MOV ESI, dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L00502772: { // 0x502772: 8b542440 MOV EDX, dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00502776: { // 0x502776: 0fbe8e1b010000 MOVSX ECX, byte ptr [ESI + 0x11B]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0050277d: { // 0x50277d: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L0050277f: { // 0x50277f: 83fa04 CMP EDX, 4
    (void)integer::sub(s.dx,4u,32,flags);
  }
  L00502782: { // 0x502782: 7e0c JLE 0x502790
    if(integer::condition("JLE",flags)) goto L00502790;
  }
  L00502784: { // 0x502784: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502785: { // 0x502785: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502786: { // 0x502786: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502787: { // 0x502787: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00502789: { // 0x502789: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0050278a: { // 0x50278a: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L0050278d: { // 0x50278d: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502790: { // 0x502790: 8b4c2444 MOV ECX, dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00502794: { // 0x502794: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00502797: { // 0x502797: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00502798: { // 0x502798: 8d542415 LEA EDX, [ESP + 0x15]
    s.dx = (f.sp+0x00000015u);
  }
  L0050279c: { // 0x50279c: 8d4c2444 LEA ECX, [ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L005027a0: { // 0x5027a0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005027a1: { // 0x5027a1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005027a2: { // 0x5027a2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005027a3: { // 0x5027a3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005027a4: { // 0x5027a4: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005027a6: { // 0x5027a6: ff9098010000 CALL dword ptr [EAX + 0x198]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000198u)),5253036u); flags=s.arithmetic_flags;
  }
  L005027ac: { // 0x5027ac: 83f807 CMP EAX, 7
    (void)integer::sub(s.ax,7u,32,flags);
  }
  L005027af: { // 0x5027af: 750a JNZ 0x5027BB
    if(integer::condition("JNZ",flags)) goto L005027bb;
  }
  L005027b1: { // 0x5027b1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005027b2: { // 0x5027b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005027b3: { // 0x5027b3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005027b4: { // 0x5027b4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005027b5: { // 0x5027b5: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L005027b8: { // 0x5027b8: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L005027bb: { // 0x5027bb: 8b442440 MOV EAX, dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L005027bf: { // 0x5027bf: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L005027c2: { // 0x5027c2: 7436 JZ 0x5027FA
    if(integer::condition("JZ",flags)) goto L005027fa;
  }
  L005027c4: { // 0x5027c4: 859e40010000 TEST dword ptr [ESI + 0x140], EBX
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.bx),32,flags);
  }
  L005027ca: { // 0x5027ca: 742e JZ 0x5027FA
    if(integer::condition("JZ",flags)) goto L005027fa;
  }
  L005027cc: { // 0x5027cc: 0fbe961b010000 MOVSX EDX, byte ptr [ESI + 0x11B]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L005027d3: { // 0x5027d3: 83c204 ADD EDX, 4
    s.dx = integer::add(s.dx,4u,32,flags);
  }
  L005027d6: { // 0x5027d6: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L005027d8: { // 0x5027d8: 7520 JNZ 0x5027FA
    if(integer::condition("JNZ",flags)) goto L005027fa;
  }
  L005027da: { // 0x5027da: 8a8628010000 MOV AL, byte ptr [ESI + 0x128]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000128u)));
  }
  L005027e0: { // 0x5027e0: 8b4e58 MOV ECX, dword ptr [ESI + 0x58]
    s.cx = m.r32((s.si+0x00000058u));
  }
  L005027e3: { // 0x5027e3: 88442412 MOV byte ptr [ESP + 0x12], AL
    m.w8((f.sp+0x00000012u), (s.ax & 0xffu));
  }
  L005027e7: { // 0x5027e7: 8b8628010000 MOV EAX, dword ptr [ESI + 0x128]
    s.ax = m.r32((s.si+0x00000128u));
  }
  L005027ed: { // 0x5027ed: c1e805 SHR EAX, 5
    s.ax = integer::shift(s.ax,5u,32,flags,integer::Shift::right);
  }
  L005027f0: { // 0x5027f0: 2401 AND AL, 1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(1u),8,flags));
  }
  L005027f2: { // 0x5027f2: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005027f6: { // 0x5027f6: 88442413 MOV byte ptr [ESP + 0x13], AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L005027fa: { // 0x5027fa: 8a852d030000 MOV AL, byte ptr [EBP + 0x32D]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000032du)));
  }
  L00502800: { // 0x502800: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502802: { // 0x502802: 7438 JZ 0x50283C
    if(integer::condition("JZ",flags)) goto L0050283c;
  }
  L00502804: { // 0x502804: a1c483a200 MOV EAX, dword ptr [0xA283C4]
    s.ax = m.r32((0x00a283c4u));
  }
  L00502809: { // 0x502809: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050280b: { // 0x50280b: 752f JNZ 0x50283C
    if(integer::condition("JNZ",flags)) goto L0050283c;
  }
  L0050280d: { // 0x50280d: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0050280f: { // 0x50280f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00502810: { // 0x502810: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00502815: { // 0x502815: e8164d0500 CALL 0x557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,5253146u); flags=s.arithmetic_flags;
  }
  L0050281a: { // 0x50281a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050281c: { // 0x50281c: 751e JNZ 0x50283C
    if(integer::condition("JNZ",flags)) goto L0050283c;
  }
  L0050281e: { // 0x50281e: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00502821: { // 0x502821: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502823: { // 0x502823: ff92f4020000 CALL dword ptr [EDX + 0x2F4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002f4u)),5253161u); flags=s.arithmetic_flags;
  }
  L00502829: { // 0x502829: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050282b: { // 0x50282b: 750f JNZ 0x50283C
    if(integer::condition("JNZ",flags)) goto L0050283c;
  }
  L0050282d: { // 0x50282d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050282e: { // 0x50282e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050282f: { // 0x50282f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502830: { // 0x502830: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L00502835: { // 0x502835: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502836: { // 0x502836: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502839: { // 0x502839: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0050283c: { // 0x50283c: 8b4644 MOV EAX, dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L0050283f: { // 0x50283f: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00502841: { // 0x502841: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00502844: { // 0x502844: 0f849b000000 JZ 0x5028E5
    if(integer::condition("JZ",flags)) goto L005028e5;
  }
  L0050284a: { // 0x50284a: 8b0d1ce1a100 MOV ECX, dword ptr [0xA1E11C]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00502850: { // 0x502850: 8b3481 MOV ESI, dword ptr [ECX + EAX*4]
    s.si = m.r32((s.cx+(s.ax * 4u)));
  }
  L00502853: { // 0x502853: 8a867a020000 MOV AL, byte ptr [ESI + 0x27A]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000027au)));
  }
  L00502859: { // 0x502859: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050285b: { // 0x50285b: 741e JZ 0x50287B
    if(integer::condition("JZ",flags)) goto L0050287b;
  }
  L0050285d: { // 0x50285d: 8b8db4010000 MOV ECX, dword ptr [EBP + 0x1B4]
    s.cx = m.r32((s.bp+0x000001b4u));
  }
  L00502863: { // 0x502863: e8881fffff CALL 0x4F47F0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,5253224u); flags=s.arithmetic_flags;
  }
  L00502868: { // 0x502868: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050286a: { // 0x50286a: 750f JNZ 0x50287B
    if(integer::condition("JNZ",flags)) goto L0050287b;
  }
  L0050286c: { // 0x50286c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050286d: { // 0x50286d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050286e: { // 0x50286e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0050286f: { // 0x50286f: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L00502874: { // 0x502874: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502875: { // 0x502875: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502878: { // 0x502878: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0050287b: { // 0x50287b: 8a8678020000 MOV AL, byte ptr [ESI + 0x278]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000278u)));
  }
  L00502881: { // 0x502881: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502883: { // 0x502883: 7460 JZ 0x5028E5
    if(integer::condition("JZ",flags)) goto L005028e5;
  }
  L00502885: { // 0x502885: 8b7c2438 MOV EDI, dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00502889: { // 0x502889: 8b8670020000 MOV EAX, dword ptr [ESI + 0x270]
    s.ax = m.r32((s.si+0x00000270u));
  }
  L0050288f: { // 0x50288f: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00502891: { // 0x502891: 8a971e010000 MOV DL, byte ptr [EDI + 0x11E]
    s.dx = with_al(s.dx, m.r8((s.di+0x0000011eu)));
  }
  L00502897: { // 0x502897: c1ea04 SHR EDX, 4
    s.dx = integer::shift(s.dx,4u,32,flags,integer::Shift::right);
  }
  L0050289a: { // 0x50289a: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0050289c: { // 0x50289c: 7447 JZ 0x5028E5
    if(integer::condition("JZ",flags)) goto L005028e5;
  }
  L0050289e: { // 0x50289e: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005028a1: { // 0x5028a1: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005028a3: { // 0x5028a3: ff908c020000 CALL dword ptr [EAX + 0x28C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000028cu)),5253289u); flags=s.arithmetic_flags;
  }
  L005028a9: { // 0x5028a9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005028ab: { // 0x5028ab: 0f8483050000 JZ 0x502E34
    if(integer::condition("JZ",flags)) goto L00502e34;
  }
  L005028b1: { // 0x5028b1: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005028b4: { // 0x5028b4: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005028b6: { // 0x5028b6: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005028b8: { // 0x5028b8: ff929c030000 CALL dword ptr [EDX + 0x39C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),5253310u); flags=s.arithmetic_flags;
  }
  L005028be: { // 0x5028be: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005028c0: { // 0x5028c0: e88b5d2200 CALL 0x728650
    s.arithmetic_flags=flags; invoke(m,s,f,0x00728650u,5253317u); flags=s.arithmetic_flags;
  }
  L005028c5: { // 0x5028c5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005028c7: { // 0x5028c7: 0f8467050000 JZ 0x502E34
    if(integer::condition("JZ",flags)) goto L00502e34;
  }
  L005028cd: { // 0x5028cd: 8b4750 MOV EAX, dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L005028d0: { // 0x5028d0: 8b8db4010000 MOV ECX, dword ptr [EBP + 0x1B4]
    s.cx = m.r32((s.bp+0x000001b4u));
  }
  L005028d6: { // 0x5028d6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005028d7: { // 0x5028d7: e8c422feff CALL 0x4E4BA0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4ba0u,5253340u); flags=s.arithmetic_flags;
  }
  L005028dc: { // 0x5028dc: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  L005028de: { // 0x5028de: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L005028e0: { // 0x5028e0: 83c005 ADD EAX, 5
    s.ax = integer::add(s.ax,5u,32,flags);
  }
  L005028e3: { // 0x5028e3: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L005028e5: { // 0x5028e5: 8a442411 MOV AL, byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L005028e9: { // 0x5028e9: c744243c00000000 MOV dword ptr [ESP + 0x3C], 0
    m.w32((f.sp+0x0000003cu), 0u);
  }
  L005028f1: { // 0x5028f1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005028f3: { // 0x5028f3: 740c JZ 0x502901
    if(integer::condition("JZ",flags)) goto L00502901;
  }
  L005028f5: { // 0x5028f5: 8b4c2438 MOV ECX, dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L005028f9: { // 0x5028f9: 8bb1e8000000 MOV ESI, dword ptr [ECX + 0xE8]
    s.si = m.r32((s.cx+0x000000e8u));
  }
  L005028ff: { // 0x5028ff: eb0a JMP 0x50290B
    goto L0050290b;
  }
  L00502901: { // 0x502901: 8b542438 MOV EDX, dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00502905: { // 0x502905: 8bb2e4000000 MOV ESI, dword ptr [EDX + 0xE4]
    s.si = m.r32((s.dx+0x000000e4u));
  }
  L0050290b: { // 0x50290b: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0050290d: { // 0x50290d: 0f84e0040000 JZ 0x502DF3
    if(integer::condition("JZ",flags)) goto L00502df3;
  }
  L00502913: { // 0x502913: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00502915: { // 0x502915: 0f845c040000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L0050291b: { // 0x50291b: 8b8588050000 MOV EAX, dword ptr [EBP + 0x588]
    s.ax = m.r32((s.bp+0x00000588u));
  }
  L00502921: { // 0x502921: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502923: { // 0x502923: 743b JZ 0x502960
    if(integer::condition("JZ",flags)) goto L00502960;
  }
  L00502925: { // 0x502925: 8b4828 MOV ECX, dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L00502928: { // 0x502928: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0050292a: { // 0x50292a: 7434 JZ 0x502960
    if(integer::condition("JZ",flags)) goto L00502960;
  }
  L0050292c: { // 0x50292c: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0050292e: { // 0x50292e: 8d542444 LEA EDX, [ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L00502932: { // 0x502932: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00502933: { // 0x502933: ff90a0010000 CALL dword ptr [EAX + 0x1A0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),5253433u); flags=s.arithmetic_flags;
  }
  L00502939: { // 0x502939: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0050293d: { // 0x50293d: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0050293f: { // 0x50293f: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00502941: { // 0x502941: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00502942: { // 0x502942: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502944: { // 0x502944: ff90a0010000 CALL dword ptr [EAX + 0x1A0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),5253450u); flags=s.arithmetic_flags;
  }
  L0050294a: { // 0x50294a: 668b10 MOV DX, word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0050294d: { // 0x50294d: 663b17 CMP DX, word ptr [EDI]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.di)),16,flags);
  }
  L00502950: { // 0x502950: 750e JNZ 0x502960
    if(integer::condition("JNZ",flags)) goto L00502960;
  }
  L00502952: { // 0x502952: 668b4002 MOV AX, word ptr [EAX + 2]
    s.ax = with_ax(s.ax, m.r16((s.ax+2u)));
  }
  L00502956: { // 0x502956: 663b4702 CMP AX, word ptr [EDI + 2]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.di+2u)),16,flags);
  }
  L0050295a: { // 0x50295a: 0f8487040000 JZ 0x502DE7
    if(integer::condition("JZ",flags)) goto L00502de7;
  }
  L00502960: { // 0x502960: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00502963: { // 0x502963: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502965: { // 0x502965: ff926c010000 CALL dword ptr [EDX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),5253483u); flags=s.arithmetic_flags;
  }
  L0050296b: { // 0x50296b: 83f807 CMP EAX, 7
    (void)integer::sub(s.ax,7u,32,flags);
  }
  L0050296e: { // 0x50296e: 7478 JZ 0x5029E8
    if(integer::condition("JZ",flags)) goto L005029e8;
  }
  L00502970: { // 0x502970: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00502973: { // 0x502973: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502975: { // 0x502975: ff906c010000 CALL dword ptr [EAX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),5253499u); flags=s.arithmetic_flags;
  }
  L0050297b: { // 0x50297b: 83f808 CMP EAX, 8
    (void)integer::sub(s.ax,8u,32,flags);
  }
  L0050297e: { // 0x50297e: 7468 JZ 0x5029E8
    if(integer::condition("JZ",flags)) goto L005029e8;
  }
  L00502980: { // 0x502980: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00502983: { // 0x502983: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502985: { // 0x502985: ff926c010000 CALL dword ptr [EDX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),5253515u); flags=s.arithmetic_flags;
  }
  L0050298b: { // 0x50298b: 83f809 CMP EAX, 9
    (void)integer::sub(s.ax,9u,32,flags);
  }
  L0050298e: { // 0x50298e: 7458 JZ 0x5029E8
    if(integer::condition("JZ",flags)) goto L005029e8;
  }
  L00502990: { // 0x502990: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00502993: { // 0x502993: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502995: { // 0x502995: ff906c010000 CALL dword ptr [EAX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),5253531u); flags=s.arithmetic_flags;
  }
  L0050299b: { // 0x50299b: 83f811 CMP EAX, 0x11
    (void)integer::sub(s.ax,0x00000011u,32,flags);
  }
  L0050299e: { // 0x50299e: 7448 JZ 0x5029E8
    if(integer::condition("JZ",flags)) goto L005029e8;
  }
  L005029a0: { // 0x5029a0: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005029a3: { // 0x5029a3: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005029a5: { // 0x5029a5: ff926c010000 CALL dword ptr [EDX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),5253547u); flags=s.arithmetic_flags;
  }
  L005029ab: { // 0x5029ab: 83f80b CMP EAX, 0xB
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L005029ae: { // 0x5029ae: 7424 JZ 0x5029D4
    if(integer::condition("JZ",flags)) goto L005029d4;
  }
  L005029b0: { // 0x5029b0: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005029b3: { // 0x5029b3: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005029b5: { // 0x5029b5: ff906c010000 CALL dword ptr [EAX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),5253563u); flags=s.arithmetic_flags;
  }
  L005029bb: { // 0x5029bb: 83f819 CMP EAX, 0x19
    (void)integer::sub(s.ax,0x00000019u,32,flags);
  }
  L005029be: { // 0x5029be: 7414 JZ 0x5029D4
    if(integer::condition("JZ",flags)) goto L005029d4;
  }
  L005029c0: { // 0x5029c0: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L005029c3: { // 0x5029c3: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005029c5: { // 0x5029c5: ff926c010000 CALL dword ptr [EDX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),5253579u); flags=s.arithmetic_flags;
  }
  L005029cb: { // 0x5029cb: 83f805 CMP EAX, 5
    (void)integer::sub(s.ax,5u,32,flags);
  }
  L005029ce: { // 0x5029ce: 0f85b3000000 JNZ 0x502A87
    if(integer::condition("JNZ",flags)) goto L00502a87;
  }
  L005029d4: { // 0x5029d4: 8b85a8050000 MOV EAX, dword ptr [EBP + 0x5A8]
    s.ax = m.r32((s.bp+0x000005a8u));
  }
  L005029da: { // 0x5029da: 8a88110c0000 MOV CL, byte ptr [EAX + 0xC11]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000c11u)));
  }
  L005029e0: { // 0x5029e0: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005029e2: { // 0x5029e2: 0f849f000000 JZ 0x502A87
    if(integer::condition("JZ",flags)) goto L00502a87;
  }
  L005029e8: { // 0x5029e8: 3bb594040000 CMP ESI, dword ptr [EBP + 0x494]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000494u)),32,flags);
  }
  L005029ee: { // 0x5029ee: 0f848f030000 JZ 0x502D83
    if(integer::condition("JZ",flags)) goto L00502d83;
  }
  L005029f4: { // 0x5029f4: 8d8e88000000 LEA ECX, [ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L005029fa: { // 0x5029fa: 8b9688000000 MOV EDX, dword ptr [ESI + 0x88]
    s.dx = m.r32((s.si+0x00000088u));
  }
  L00502a00: { // 0x502a00: 8954241c MOV dword ptr [ESP + 0x1C], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00502a04: { // 0x502a04: 8d54241c LEA EDX, [ESP + 0x1C]
    s.dx = (f.sp+0x0000001cu);
  }
  L00502a08: { // 0x502a08: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00502a0b: { // 0x502a0b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00502a0c: { // 0x502a0c: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00502a10: { // 0x502a10: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L00502a13: { // 0x502a13: 894c2428 MOV dword ptr [ESP + 0x28], ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00502a17: { // 0x502a17: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00502a1c: { // 0x502a1c: e86f2a0400 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5253665u); flags=s.arithmetic_flags;
  }
  L00502a21: { // 0x502a21: 3b8594040000 CMP EAX, dword ptr [EBP + 0x494]
    (void)integer::sub(s.ax,m.r32((s.bp+0x00000494u)),32,flags);
  }
  L00502a27: { // 0x502a27: 0f8456030000 JZ 0x502D83
    if(integer::condition("JZ",flags)) goto L00502d83;
  }
  L00502a2d: { // 0x502a2d: 3bb528020000 CMP ESI, dword ptr [EBP + 0x228]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000228u)),32,flags);
  }
  L00502a33: { // 0x502a33: 0f844a030000 JZ 0x502D83
    if(integer::condition("JZ",flags)) goto L00502d83;
  }
  L00502a39: { // 0x502a39: 8b4c2438 MOV ECX, dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00502a3d: { // 0x502a3d: e86ee9f6ff CALL 0x4713B0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,5253698u); flags=s.arithmetic_flags;
  }
  L00502a42: { // 0x502a42: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00502a44: { // 0x502a44: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00502a46: { // 0x502a46: 743f JZ 0x502A87
    if(integer::condition("JZ",flags)) goto L00502a87;
  }
  L00502a48: { // 0x502a48: 3bf7 CMP ESI, EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00502a4a: { // 0x502a4a: 743b JZ 0x502A87
    if(integer::condition("JZ",flags)) goto L00502a87;
  }
  L00502a4c: { // 0x502a4c: 3bbd94040000 CMP EDI, dword ptr [EBP + 0x494]
    (void)integer::sub(s.di,m.r32((s.bp+0x00000494u)),32,flags);
  }
  L00502a52: { // 0x502a52: 0f841f030000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502a58: { // 0x502a58: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00502a5a: { // 0x502a5a: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L00502a5e: { // 0x502a5e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00502a5f: { // 0x502a5f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00502a61: { // 0x502a61: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5253732u); flags=s.arithmetic_flags;
  }
  L00502a64: { // 0x502a64: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00502a65: { // 0x502a65: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00502a6a: { // 0x502a6a: e8212a0400 CALL 0x545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5253743u); flags=s.arithmetic_flags;
  }
  L00502a6f: { // 0x502a6f: 3b8594040000 CMP EAX, dword ptr [EBP + 0x494]
    (void)integer::sub(s.ax,m.r32((s.bp+0x00000494u)),32,flags);
  }
  L00502a75: { // 0x502a75: 0f84fc020000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502a7b: { // 0x502a7b: 3bbd28020000 CMP EDI, dword ptr [EBP + 0x228]
    (void)integer::sub(s.di,m.r32((s.bp+0x00000228u)),32,flags);
  }
  L00502a81: { // 0x502a81: 0f84f0020000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502a87: { // 0x502a87: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00502a8a: { // 0x502a8a: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502a8c: { // 0x502a8c: ff926c010000 CALL dword ptr [EDX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),5253778u); flags=s.arithmetic_flags;
  }
  L00502a92: { // 0x502a92: 83f80b CMP EAX, 0xB
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L00502a95: { // 0x502a95: 7518 JNZ 0x502AAF
    if(integer::condition("JNZ",flags)) goto L00502aaf;
  }
  L00502a97: { // 0x502a97: 8b8db0010000 MOV ECX, dword ptr [EBP + 0x1B0]
    s.cx = m.r32((s.bp+0x000001b0u));
  }
  L00502a9d: { // 0x502a9d: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00502a9f: { // 0x502a9f: 750e JNZ 0x502AAF
    if(integer::condition("JNZ",flags)) goto L00502aaf;
  }
  L00502aa1: { // 0x502aa1: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00502aa3: { // 0x502aa3: ff502c CALL dword ptr [EAX + 0x2C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5253798u); flags=s.arithmetic_flags;
  }
  L00502aa6: { // 0x502aa6: 83f801 CMP EAX, 1
    (void)integer::sub(s.ax,1u,32,flags);
  }
  L00502aa9: { // 0x502aa9: 0f8485030000 JZ 0x502E34
    if(integer::condition("JZ",flags)) goto L00502e34;
  }
  L00502aaf: { // 0x502aaf: 8b8da8050000 MOV ECX, dword ptr [EBP + 0x5A8]
    s.cx = m.r32((s.bp+0x000005a8u));
  }
  L00502ab5: { // 0x502ab5: 8a81140c0000 MOV AL, byte ptr [ECX + 0xC14]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000c14u)));
  }
  L00502abb: { // 0x502abb: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502abd: { // 0x502abd: 742b JZ 0x502AEA
    if(integer::condition("JZ",flags)) goto L00502aea;
  }
  L00502abf: { // 0x502abf: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00502ac1: { // 0x502ac1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502ac3: { // 0x502ac3: ff527c CALL dword ptr [EDX + 0x7C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),5253830u); flags=s.arithmetic_flags;
  }
  L00502ac6: { // 0x502ac6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502ac8: { // 0x502ac8: 7420 JZ 0x502AEA
    if(integer::condition("JZ",flags)) goto L00502aea;
  }
  L00502aca: { // 0x502aca: 39b594040000 CMP dword ptr [EBP + 0x494], ESI
    (void)integer::sub(m.r32((s.bp+0x00000494u)),s.si,32,flags);
  }
  L00502ad0: { // 0x502ad0: 7518 JNZ 0x502AEA
    if(integer::condition("JNZ",flags)) goto L00502aea;
  }
  L00502ad2: { // 0x502ad2: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00502ad4: { // 0x502ad4: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502ad6: { // 0x502ad6: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),5253852u); flags=s.arithmetic_flags;
  }
  L00502adc: { // 0x502adc: 8a88a00a0000 MOV CL, byte ptr [EAX + 0xAA0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa0u)));
  }
  L00502ae2: { // 0x502ae2: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00502ae4: { // 0x502ae4: 0f84fd020000 JZ 0x502DE7
    if(integer::condition("JZ",flags)) goto L00502de7;
  }
  L00502aea: { // 0x502aea: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00502aec: { // 0x502aec: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502aee: { // 0x502aee: ff522c CALL dword ptr [EDX + 0x2C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5253873u); flags=s.arithmetic_flags;
  }
  L00502af1: { // 0x502af1: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L00502af4: { // 0x502af4: 0f85c1000000 JNZ 0x502BBB
    if(integer::condition("JNZ",flags)) goto L00502bbb;
  }
  L00502afa: { // 0x502afa: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L00502b00: { // 0x502b00: 8a8885130000 MOV CL, byte ptr [EAX + 0x1385]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001385u)));
  }
  L00502b06: { // 0x502b06: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00502b08: { // 0x502b08: 0f8569020000 JNZ 0x502D77
    if(integer::condition("JNZ",flags)) goto L00502d77;
  }
  L00502b0e: { // 0x502b0e: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L00502b14: { // 0x502b14: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00502b16: { // 0x502b16: 7418 JZ 0x502B30
    if(integer::condition("JZ",flags)) goto L00502b30;
  }
  L00502b18: { // 0x502b18: 8b8eec040000 MOV ECX, dword ptr [ESI + 0x4EC]
    s.cx = m.r32((s.si+0x000004ecu));
  }
  L00502b1e: { // 0x502b1e: 83f90c CMP ECX, 0xC
    (void)integer::sub(s.cx,0x0000000cu,32,flags);
  }
  L00502b21: { // 0x502b21: 0f8450020000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502b27: { // 0x502b27: 83f908 CMP ECX, 8
    (void)integer::sub(s.cx,8u,32,flags);
  }
  L00502b2a: { // 0x502b2a: 0f8447020000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502b30: { // 0x502b30: 8a885a130000 MOV CL, byte ptr [EAX + 0x135A]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000135au)));
  }
  L00502b36: { // 0x502b36: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00502b38: { // 0x502b38: 7419 JZ 0x502B53
    if(integer::condition("JZ",flags)) goto L00502b53;
  }
  L00502b3a: { // 0x502b3a: 8b86b4010000 MOV EAX, dword ptr [ESI + 0x1B4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00502b40: { // 0x502b40: 8a8842010000 MOV CL, byte ptr [EAX + 0x142]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000142u)));
  }
  L00502b46: { // 0x502b46: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00502b48: { // 0x502b48: 0f85e6020000 JNZ 0x502E34
    if(integer::condition("JNZ",flags)) goto L00502e34;
  }
  L00502b4e: { // 0x502b4e: e924020000 JMP 0x502D77
    goto L00502d77;
  }
  L00502b53: { // 0x502b53: 8a8851130000 MOV CL, byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L00502b59: { // 0x502b59: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00502b5b: { // 0x502b5b: 745e JZ 0x502BBB
    if(integer::condition("JZ",flags)) goto L00502bbb;
  }
  L00502b5d: { // 0x502b5d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502b5f: { // 0x502b5f: e80caaf4ff CALL 0x44D570
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044d570u,5253988u); flags=s.arithmetic_flags;
  }
  L00502b64: { // 0x502b64: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502b66: { // 0x502b66: 0f850b020000 JNZ 0x502D77
    if(integer::condition("JNZ",flags)) goto L00502d77;
  }
  L00502b6c: { // 0x502b6c: 8b8db4010000 MOV ECX, dword ptr [EBP + 0x1B4]
    s.cx = m.r32((s.bp+0x000001b4u));
  }
  L00502b72: { // 0x502b72: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00502b73: { // 0x502b73: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1B4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L00502b79: { // 0x502b79: e86220feff CALL 0x4E4BE0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,5254014u); flags=s.arithmetic_flags;
  }
  L00502b7e: { // 0x502b7e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502b80: { // 0x502b80: 7413 JZ 0x502B95
    if(integer::condition("JZ",flags)) goto L00502b95;
  }
  L00502b82: { // 0x502b82: 83fb03 CMP EBX, 3
    (void)integer::sub(s.bx,3u,32,flags);
  }
  L00502b85: { // 0x502b85: 0f8dec010000 JGE 0x502D77
    if(integer::condition("JGE",flags)) goto L00502d77;
  }
  L00502b8b: { // 0x502b8b: bb03000000 MOV EBX, 3
    s.bx = 3u;
  }
  L00502b90: { // 0x502b90: e9e2010000 JMP 0x502D77
    goto L00502d77;
  }
  L00502b95: { // 0x502b95: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00502b98: { // 0x502b98: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502b9a: { // 0x502b9a: ff928c020000 CALL dword ptr [EDX + 0x28C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000028cu)),5254048u); flags=s.arithmetic_flags;
  }
  L00502ba0: { // 0x502ba0: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502ba2: { // 0x502ba2: 0f848c020000 JZ 0x502E34
    if(integer::condition("JZ",flags)) goto L00502e34;
  }
  L00502ba8: { // 0x502ba8: 83fb05 CMP EBX, 5
    (void)integer::sub(s.bx,5u,32,flags);
  }
  L00502bab: { // 0x502bab: 0f8dc6010000 JGE 0x502D77
    if(integer::condition("JGE",flags)) goto L00502d77;
  }
  L00502bb1: { // 0x502bb1: bb05000000 MOV EBX, 5
    s.bx = 5u;
  }
  L00502bb6: { // 0x502bb6: e9bc010000 JMP 0x502D77
    goto L00502d77;
  }
  L00502bbb: { // 0x502bbb: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00502bbe: { // 0x502bbe: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502bc0: { // 0x502bc0: ff906c010000 CALL dword ptr [EAX + 0x16C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000016cu)),5254086u); flags=s.arithmetic_flags;
  }
  L00502bc6: { // 0x502bc6: 83f807 CMP EAX, 7
    (void)integer::sub(s.ax,7u,32,flags);
  }
  L00502bc9: { // 0x502bc9: 7516 JNZ 0x502BE1
    if(integer::condition("JNZ",flags)) goto L00502be1;
  }
  L00502bcb: { // 0x502bcb: 3bb594040000 CMP ESI, dword ptr [EBP + 0x494]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000494u)),32,flags);
  }
  L00502bd1: { // 0x502bd1: 750e JNZ 0x502BE1
    if(integer::condition("JNZ",flags)) goto L00502be1;
  }
  L00502bd3: { // 0x502bd3: 8a8570030000 MOV AL, byte ptr [EBP + 0x370]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000370u)));
  }
  L00502bd9: { // 0x502bd9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502bdb: { // 0x502bdb: 0f8506020000 JNZ 0x502DE7
    if(integer::condition("JNZ",flags)) goto L00502de7;
  }
  L00502be1: { // 0x502be1: 8b8db4010000 MOV ECX, dword ptr [EBP + 0x1B4]
    s.cx = m.r32((s.bp+0x000001b4u));
  }
  L00502be7: { // 0x502be7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00502be8: { // 0x502be8: e83320feff CALL 0x4E4C20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,5254125u); flags=s.arithmetic_flags;
  }
  L00502bed: { // 0x502bed: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502bef: { // 0x502bef: 0f85c3000000 JNZ 0x502CB8
    if(integer::condition("JNZ",flags)) goto L00502cb8;
  }
  L00502bf5: { // 0x502bf5: a1c483a200 MOV EAX, dword ptr [0xA283C4]
    s.ax = m.r32((0x00a283c4u));
  }
  L00502bfa: { // 0x502bfa: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502bfc: { // 0x502bfc: 0f85b6000000 JNZ 0x502CB8
    if(integer::condition("JNZ",flags)) goto L00502cb8;
  }
  L00502c02: { // 0x502c02: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502c04: { // 0x502c04: e817b0f0ff CALL 0x40DC20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,5254153u); flags=s.arithmetic_flags;
  }
  L00502c09: { // 0x502c09: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502c0b: { // 0x502c0b: 741c JZ 0x502C29
    if(integer::condition("JZ",flags)) goto L00502c29;
  }
  L00502c0d: { // 0x502c0d: 83b8b801000002 CMP dword ptr [EAX + 0x1B8], 2
    (void)integer::sub(m.r32((s.ax+0x000001b8u)),2u,32,flags);
  }
  L00502c14: { // 0x502c14: 7513 JNZ 0x502C29
    if(integer::condition("JNZ",flags)) goto L00502c29;
  }
  L00502c16: { // 0x502c16: 83fb01 CMP EBX, 1
    (void)integer::sub(s.bx,1u,32,flags);
  }
  L00502c19: { // 0x502c19: 0f8d58010000 JGE 0x502D77
    if(integer::condition("JGE",flags)) goto L00502d77;
  }
  L00502c1f: { // 0x502c1f: bb01000000 MOV EBX, 1
    s.bx = 1u;
  }
  L00502c24: { // 0x502c24: e94e010000 JMP 0x502D77
    goto L00502d77;
  }
  L00502c29: { // 0x502c29: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00502c2b: { // 0x502c2b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502c2d: { // 0x502c2d: ff522c CALL dword ptr [EDX + 0x2C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5254192u); flags=s.arithmetic_flags;
  }
  L00502c30: { // 0x502c30: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L00502c32: { // 0x502c32: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502c34: { // 0x502c34: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L00502c36: { // 0x502c36: e805411b00 CALL 0x6B6D40
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b6d40u,5254203u); flags=s.arithmetic_flags;
  }
  L00502c3b: { // 0x502c3b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502c3d: { // 0x502c3d: 7f09 JG 0x502C48
    if(integer::condition("JG",flags)) goto L00502c48;
  }
  L00502c3f: { // 0x502c3f: 83ff24 CMP EDI, 0x24
    (void)integer::sub(s.di,0x00000024u,32,flags);
  }
  L00502c42: { // 0x502c42: 0f85ec010000 JNZ 0x502E34
    if(integer::condition("JNZ",flags)) goto L00502e34;
  }
  L00502c48: { // 0x502c48: 83ff06 CMP EDI, 6
    (void)integer::sub(s.di,6u,32,flags);
  }
  L00502c4b: { // 0x502c4b: 7444 JZ 0x502C91
    if(integer::condition("JZ",flags)) goto L00502c91;
  }
  L00502c4d: { // 0x502c4d: 83ff0f CMP EDI, 0xF
    (void)integer::sub(s.di,0x0000000fu,32,flags);
  }
  L00502c50: { // 0x502c50: 741c JZ 0x502C6E
    if(integer::condition("JZ",flags)) goto L00502c6e;
  }
  L00502c52: { // 0x502c52: 83ff24 CMP EDI, 0x24
    (void)integer::sub(s.di,0x00000024u,32,flags);
  }
  L00502c55: { // 0x502c55: 0f841c010000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502c5b: { // 0x502c5b: 83fb05 CMP EBX, 5
    (void)integer::sub(s.bx,5u,32,flags);
  }
  L00502c5e: { // 0x502c5e: 0f8d13010000 JGE 0x502D77
    if(integer::condition("JGE",flags)) goto L00502d77;
  }
  L00502c64: { // 0x502c64: bb05000000 MOV EBX, 5
    s.bx = 5u;
  }
  L00502c69: { // 0x502c69: e909010000 JMP 0x502D77
    goto L00502d77;
  }
  L00502c6e: { // 0x502c6e: 8b8db4010000 MOV ECX, dword ptr [EBP + 0x1B4]
    s.cx = m.r32((s.bp+0x000001b4u));
  }
  L00502c74: { // 0x502c74: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00502c76: { // 0x502c76: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00502c77: { // 0x502c77: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502c79: { // 0x502c79: ff90c4000000 CALL dword ptr [EAX + 0xC4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000c4u)),5254271u); flags=s.arithmetic_flags;
  }
  L00502c7f: { // 0x502c7f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502c81: { // 0x502c81: 0f84f0000000 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502c87: { // 0x502c87: bb06000000 MOV EBX, 6
    s.bx = 6u;
  }
  L00502c8c: { // 0x502c8c: e9e6000000 JMP 0x502D77
    goto L00502d77;
  }
  L00502c91: { // 0x502c91: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L00502c97: { // 0x502c97: 8a8250130000 MOV AL, byte ptr [EDX + 0x1350]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001350u)));
  }
  L00502c9d: { // 0x502c9d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502c9f: { // 0x502c9f: 0f858f010000 JNZ 0x502E34
    if(integer::condition("JNZ",flags)) goto L00502e34;
  }
  L00502ca5: { // 0x502ca5: 83fb05 CMP EBX, 5
    (void)integer::sub(s.bx,5u,32,flags);
  }
  L00502ca8: { // 0x502ca8: 0f8dc9000000 JGE 0x502D77
    if(integer::condition("JGE",flags)) goto L00502d77;
  }
  L00502cae: { // 0x502cae: bb05000000 MOV EBX, 5
    s.bx = 5u;
  }
  L00502cb3: { // 0x502cb3: e9bf000000 JMP 0x502D77
    goto L00502d77;
  }
  L00502cb8: { // 0x502cb8: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00502cba: { // 0x502cba: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502cbc: { // 0x502cbc: ff502c CALL dword ptr [EAX + 0x2C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5254335u); flags=s.arithmetic_flags;
  }
  L00502cbf: { // 0x502cbf: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00502cc0: { // 0x502cc0: 83f80e CMP EAX, 0xE
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  L00502cc3: { // 0x502cc3: 0f87ae000000 JA 0x502D77
    if(integer::condition("JA",flags)) goto L00502d77;
  }
  L00502cc9: { // 0x502cc9: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00502ccb: { // 0x502ccb: 8a88fc2e5000 MOV CL, byte ptr [EAX + 0x502EFC]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00502efcu)));
  }
  L00502cd1: { // 0x502cd1: ff248dec2e5000 JMP dword ptr [ECX*4 + 0x502EEC]
    switch(m.r32(((s.cx * 4u)+0x00502eecu))){
    case 0x00502650u: goto L00502650;
    case 0x00502653u: goto L00502653;
    case 0x00502654u: goto L00502654;
    case 0x00502655u: goto L00502655;
    case 0x00502657u: goto L00502657;
    case 0x0050265cu: goto L0050265c;
    case 0x00502660u: goto L00502660;
    case 0x00502661u: goto L00502661;
    case 0x00502662u: goto L00502662;
    case 0x00502668u: goto L00502668;
    case 0x0050266au: goto L0050266a;
    case 0x0050266eu: goto L0050266e;
    case 0x00502671u: goto L00502671;
    case 0x00502673u: goto L00502673;
    case 0x0050267au: goto L0050267a;
    case 0x0050267cu: goto L0050267c;
    case 0x0050267du: goto L0050267d;
    case 0x0050267fu: goto L0050267f;
    case 0x00502681u: goto L00502681;
    case 0x00502684u: goto L00502684;
    case 0x00502686u: goto L00502686;
    case 0x0050268bu: goto L0050268b;
    case 0x0050268du: goto L0050268d;
    case 0x00502692u: goto L00502692;
    case 0x00502698u: goto L00502698;
    case 0x0050269bu: goto L0050269b;
    case 0x0050269fu: goto L0050269f;
    case 0x005026a5u: goto L005026a5;
    case 0x005026a8u: goto L005026a8;
    case 0x005026aau: goto L005026aa;
    case 0x005026aeu: goto L005026ae;
    case 0x005026b2u: goto L005026b2;
    case 0x005026b7u: goto L005026b7;
    case 0x005026bbu: goto L005026bb;
    case 0x005026bdu: goto L005026bd;
    case 0x005026c0u: goto L005026c0;
    case 0x005026c2u: goto L005026c2;
    case 0x005026c4u: goto L005026c4;
    case 0x005026cau: goto L005026ca;
    case 0x005026cdu: goto L005026cd;
    case 0x005026d0u: goto L005026d0;
    case 0x005026d3u: goto L005026d3;
    case 0x005026d7u: goto L005026d7;
    case 0x005026dbu: goto L005026db;
    case 0x005026ddu: goto L005026dd;
    case 0x005026e2u: goto L005026e2;
    case 0x005026e7u: goto L005026e7;
    case 0x005026edu: goto L005026ed;
    case 0x005026eeu: goto L005026ee;
    case 0x005026efu: goto L005026ef;
    case 0x005026f0u: goto L005026f0;
    case 0x005026f2u: goto L005026f2;
    case 0x005026f3u: goto L005026f3;
    case 0x005026f6u: goto L005026f6;
    case 0x005026f9u: goto L005026f9;
    case 0x005026fbu: goto L005026fb;
    case 0x005026fdu: goto L005026fd;
    case 0x00502700u: goto L00502700;
    case 0x00502702u: goto L00502702;
    case 0x00502704u: goto L00502704;
    case 0x00502705u: goto L00502705;
    case 0x00502707u: goto L00502707;
    case 0x00502709u: goto L00502709;
    case 0x0050270cu: goto L0050270c;
    case 0x0050270eu: goto L0050270e;
    case 0x00502711u: goto L00502711;
    case 0x00502713u: goto L00502713;
    case 0x00502716u: goto L00502716;
    case 0x00502718u: goto L00502718;
    case 0x00502719u: goto L00502719;
    case 0x0050271au: goto L0050271a;
    case 0x0050271bu: goto L0050271b;
    case 0x00502720u: goto L00502720;
    case 0x00502721u: goto L00502721;
    case 0x00502724u: goto L00502724;
    case 0x00502727u: goto L00502727;
    case 0x0050272bu: goto L0050272b;
    case 0x0050272eu: goto L0050272e;
    case 0x00502731u: goto L00502731;
    case 0x00502732u: goto L00502732;
    case 0x00502737u: goto L00502737;
    case 0x00502739u: goto L00502739;
    case 0x0050273eu: goto L0050273e;
    case 0x00502740u: goto L00502740;
    case 0x00502742u: goto L00502742;
    case 0x00502744u: goto L00502744;
    case 0x00502747u: goto L00502747;
    case 0x00502749u: goto L00502749;
    case 0x0050274bu: goto L0050274b;
    case 0x0050274cu: goto L0050274c;
    case 0x0050274eu: goto L0050274e;
    case 0x00502750u: goto L00502750;
    case 0x00502753u: goto L00502753;
    case 0x00502755u: goto L00502755;
    case 0x00502758u: goto L00502758;
    case 0x0050275au: goto L0050275a;
    case 0x0050275du: goto L0050275d;
    case 0x0050275fu: goto L0050275f;
    case 0x00502760u: goto L00502760;
    case 0x00502761u: goto L00502761;
    case 0x00502762u: goto L00502762;
    case 0x00502767u: goto L00502767;
    case 0x00502768u: goto L00502768;
    case 0x0050276bu: goto L0050276b;
    case 0x0050276eu: goto L0050276e;
    case 0x00502772u: goto L00502772;
    case 0x00502776u: goto L00502776;
    case 0x0050277du: goto L0050277d;
    case 0x0050277fu: goto L0050277f;
    case 0x00502782u: goto L00502782;
    case 0x00502784u: goto L00502784;
    case 0x00502785u: goto L00502785;
    case 0x00502786u: goto L00502786;
    case 0x00502787u: goto L00502787;
    case 0x00502789u: goto L00502789;
    case 0x0050278au: goto L0050278a;
    case 0x0050278du: goto L0050278d;
    case 0x00502790u: goto L00502790;
    case 0x00502794u: goto L00502794;
    case 0x00502797u: goto L00502797;
    case 0x00502798u: goto L00502798;
    case 0x0050279cu: goto L0050279c;
    case 0x005027a0u: goto L005027a0;
    case 0x005027a1u: goto L005027a1;
    case 0x005027a2u: goto L005027a2;
    case 0x005027a3u: goto L005027a3;
    case 0x005027a4u: goto L005027a4;
    case 0x005027a6u: goto L005027a6;
    case 0x005027acu: goto L005027ac;
    case 0x005027afu: goto L005027af;
    case 0x005027b1u: goto L005027b1;
    case 0x005027b2u: goto L005027b2;
    case 0x005027b3u: goto L005027b3;
    case 0x005027b4u: goto L005027b4;
    case 0x005027b5u: goto L005027b5;
    case 0x005027b8u: goto L005027b8;
    case 0x005027bbu: goto L005027bb;
    case 0x005027bfu: goto L005027bf;
    case 0x005027c2u: goto L005027c2;
    case 0x005027c4u: goto L005027c4;
    case 0x005027cau: goto L005027ca;
    case 0x005027ccu: goto L005027cc;
    case 0x005027d3u: goto L005027d3;
    case 0x005027d6u: goto L005027d6;
    case 0x005027d8u: goto L005027d8;
    case 0x005027dau: goto L005027da;
    case 0x005027e0u: goto L005027e0;
    case 0x005027e3u: goto L005027e3;
    case 0x005027e7u: goto L005027e7;
    case 0x005027edu: goto L005027ed;
    case 0x005027f0u: goto L005027f0;
    case 0x005027f2u: goto L005027f2;
    case 0x005027f6u: goto L005027f6;
    case 0x005027fau: goto L005027fa;
    case 0x00502800u: goto L00502800;
    case 0x00502802u: goto L00502802;
    case 0x00502804u: goto L00502804;
    case 0x00502809u: goto L00502809;
    case 0x0050280bu: goto L0050280b;
    case 0x0050280du: goto L0050280d;
    case 0x0050280fu: goto L0050280f;
    case 0x00502810u: goto L00502810;
    case 0x00502815u: goto L00502815;
    case 0x0050281au: goto L0050281a;
    case 0x0050281cu: goto L0050281c;
    case 0x0050281eu: goto L0050281e;
    case 0x00502821u: goto L00502821;
    case 0x00502823u: goto L00502823;
    case 0x00502829u: goto L00502829;
    case 0x0050282bu: goto L0050282b;
    case 0x0050282du: goto L0050282d;
    case 0x0050282eu: goto L0050282e;
    case 0x0050282fu: goto L0050282f;
    case 0x00502830u: goto L00502830;
    case 0x00502835u: goto L00502835;
    case 0x00502836u: goto L00502836;
    case 0x00502839u: goto L00502839;
    case 0x0050283cu: goto L0050283c;
    case 0x0050283fu: goto L0050283f;
    case 0x00502841u: goto L00502841;
    case 0x00502844u: goto L00502844;
    case 0x0050284au: goto L0050284a;
    case 0x00502850u: goto L00502850;
    case 0x00502853u: goto L00502853;
    case 0x00502859u: goto L00502859;
    case 0x0050285bu: goto L0050285b;
    case 0x0050285du: goto L0050285d;
    case 0x00502863u: goto L00502863;
    case 0x00502868u: goto L00502868;
    case 0x0050286au: goto L0050286a;
    case 0x0050286cu: goto L0050286c;
    case 0x0050286du: goto L0050286d;
    case 0x0050286eu: goto L0050286e;
    case 0x0050286fu: goto L0050286f;
    case 0x00502874u: goto L00502874;
    case 0x00502875u: goto L00502875;
    case 0x00502878u: goto L00502878;
    case 0x0050287bu: goto L0050287b;
    case 0x00502881u: goto L00502881;
    case 0x00502883u: goto L00502883;
    case 0x00502885u: goto L00502885;
    case 0x00502889u: goto L00502889;
    case 0x0050288fu: goto L0050288f;
    case 0x00502891u: goto L00502891;
    case 0x00502897u: goto L00502897;
    case 0x0050289au: goto L0050289a;
    case 0x0050289cu: goto L0050289c;
    case 0x0050289eu: goto L0050289e;
    case 0x005028a1u: goto L005028a1;
    case 0x005028a3u: goto L005028a3;
    case 0x005028a9u: goto L005028a9;
    case 0x005028abu: goto L005028ab;
    case 0x005028b1u: goto L005028b1;
    case 0x005028b4u: goto L005028b4;
    case 0x005028b6u: goto L005028b6;
    case 0x005028b8u: goto L005028b8;
    case 0x005028beu: goto L005028be;
    case 0x005028c0u: goto L005028c0;
    case 0x005028c5u: goto L005028c5;
    case 0x005028c7u: goto L005028c7;
    case 0x005028cdu: goto L005028cd;
    case 0x005028d0u: goto L005028d0;
    case 0x005028d6u: goto L005028d6;
    case 0x005028d7u: goto L005028d7;
    case 0x005028dcu: goto L005028dc;
    case 0x005028deu: goto L005028de;
    case 0x005028e0u: goto L005028e0;
    case 0x005028e3u: goto L005028e3;
    case 0x005028e5u: goto L005028e5;
    case 0x005028e9u: goto L005028e9;
    case 0x005028f1u: goto L005028f1;
    case 0x005028f3u: goto L005028f3;
    case 0x005028f5u: goto L005028f5;
    case 0x005028f9u: goto L005028f9;
    case 0x005028ffu: goto L005028ff;
    case 0x00502901u: goto L00502901;
    case 0x00502905u: goto L00502905;
    case 0x0050290bu: goto L0050290b;
    case 0x0050290du: goto L0050290d;
    case 0x00502913u: goto L00502913;
    case 0x00502915u: goto L00502915;
    case 0x0050291bu: goto L0050291b;
    case 0x00502921u: goto L00502921;
    case 0x00502923u: goto L00502923;
    case 0x00502925u: goto L00502925;
    case 0x00502928u: goto L00502928;
    case 0x0050292au: goto L0050292a;
    case 0x0050292cu: goto L0050292c;
    case 0x0050292eu: goto L0050292e;
    case 0x00502932u: goto L00502932;
    case 0x00502933u: goto L00502933;
    case 0x00502939u: goto L00502939;
    case 0x0050293du: goto L0050293d;
    case 0x0050293fu: goto L0050293f;
    case 0x00502941u: goto L00502941;
    case 0x00502942u: goto L00502942;
    case 0x00502944u: goto L00502944;
    case 0x0050294au: goto L0050294a;
    case 0x0050294du: goto L0050294d;
    case 0x00502950u: goto L00502950;
    case 0x00502952u: goto L00502952;
    case 0x00502956u: goto L00502956;
    case 0x0050295au: goto L0050295a;
    case 0x00502960u: goto L00502960;
    case 0x00502963u: goto L00502963;
    case 0x00502965u: goto L00502965;
    case 0x0050296bu: goto L0050296b;
    case 0x0050296eu: goto L0050296e;
    case 0x00502970u: goto L00502970;
    case 0x00502973u: goto L00502973;
    case 0x00502975u: goto L00502975;
    case 0x0050297bu: goto L0050297b;
    case 0x0050297eu: goto L0050297e;
    case 0x00502980u: goto L00502980;
    case 0x00502983u: goto L00502983;
    case 0x00502985u: goto L00502985;
    case 0x0050298bu: goto L0050298b;
    case 0x0050298eu: goto L0050298e;
    case 0x00502990u: goto L00502990;
    case 0x00502993u: goto L00502993;
    case 0x00502995u: goto L00502995;
    case 0x0050299bu: goto L0050299b;
    case 0x0050299eu: goto L0050299e;
    case 0x005029a0u: goto L005029a0;
    case 0x005029a3u: goto L005029a3;
    case 0x005029a5u: goto L005029a5;
    case 0x005029abu: goto L005029ab;
    case 0x005029aeu: goto L005029ae;
    case 0x005029b0u: goto L005029b0;
    case 0x005029b3u: goto L005029b3;
    case 0x005029b5u: goto L005029b5;
    case 0x005029bbu: goto L005029bb;
    case 0x005029beu: goto L005029be;
    case 0x005029c0u: goto L005029c0;
    case 0x005029c3u: goto L005029c3;
    case 0x005029c5u: goto L005029c5;
    case 0x005029cbu: goto L005029cb;
    case 0x005029ceu: goto L005029ce;
    case 0x005029d4u: goto L005029d4;
    case 0x005029dau: goto L005029da;
    case 0x005029e0u: goto L005029e0;
    case 0x005029e2u: goto L005029e2;
    case 0x005029e8u: goto L005029e8;
    case 0x005029eeu: goto L005029ee;
    case 0x005029f4u: goto L005029f4;
    case 0x005029fau: goto L005029fa;
    case 0x00502a00u: goto L00502a00;
    case 0x00502a04u: goto L00502a04;
    case 0x00502a08u: goto L00502a08;
    case 0x00502a0bu: goto L00502a0b;
    case 0x00502a0cu: goto L00502a0c;
    case 0x00502a10u: goto L00502a10;
    case 0x00502a13u: goto L00502a13;
    case 0x00502a17u: goto L00502a17;
    case 0x00502a1cu: goto L00502a1c;
    case 0x00502a21u: goto L00502a21;
    case 0x00502a27u: goto L00502a27;
    case 0x00502a2du: goto L00502a2d;
    case 0x00502a33u: goto L00502a33;
    case 0x00502a39u: goto L00502a39;
    case 0x00502a3du: goto L00502a3d;
    case 0x00502a42u: goto L00502a42;
    case 0x00502a44u: goto L00502a44;
    case 0x00502a46u: goto L00502a46;
    case 0x00502a48u: goto L00502a48;
    case 0x00502a4au: goto L00502a4a;
    case 0x00502a4cu: goto L00502a4c;
    case 0x00502a52u: goto L00502a52;
    case 0x00502a58u: goto L00502a58;
    case 0x00502a5au: goto L00502a5a;
    case 0x00502a5eu: goto L00502a5e;
    case 0x00502a5fu: goto L00502a5f;
    case 0x00502a61u: goto L00502a61;
    case 0x00502a64u: goto L00502a64;
    case 0x00502a65u: goto L00502a65;
    case 0x00502a6au: goto L00502a6a;
    case 0x00502a6fu: goto L00502a6f;
    case 0x00502a75u: goto L00502a75;
    case 0x00502a7bu: goto L00502a7b;
    case 0x00502a81u: goto L00502a81;
    case 0x00502a87u: goto L00502a87;
    case 0x00502a8au: goto L00502a8a;
    case 0x00502a8cu: goto L00502a8c;
    case 0x00502a92u: goto L00502a92;
    case 0x00502a95u: goto L00502a95;
    case 0x00502a97u: goto L00502a97;
    case 0x00502a9du: goto L00502a9d;
    case 0x00502a9fu: goto L00502a9f;
    case 0x00502aa1u: goto L00502aa1;
    case 0x00502aa3u: goto L00502aa3;
    case 0x00502aa6u: goto L00502aa6;
    case 0x00502aa9u: goto L00502aa9;
    case 0x00502aafu: goto L00502aaf;
    case 0x00502ab5u: goto L00502ab5;
    case 0x00502abbu: goto L00502abb;
    case 0x00502abdu: goto L00502abd;
    case 0x00502abfu: goto L00502abf;
    case 0x00502ac1u: goto L00502ac1;
    case 0x00502ac3u: goto L00502ac3;
    case 0x00502ac6u: goto L00502ac6;
    case 0x00502ac8u: goto L00502ac8;
    case 0x00502acau: goto L00502aca;
    case 0x00502ad0u: goto L00502ad0;
    case 0x00502ad2u: goto L00502ad2;
    case 0x00502ad4u: goto L00502ad4;
    case 0x00502ad6u: goto L00502ad6;
    case 0x00502adcu: goto L00502adc;
    case 0x00502ae2u: goto L00502ae2;
    case 0x00502ae4u: goto L00502ae4;
    case 0x00502aeau: goto L00502aea;
    case 0x00502aecu: goto L00502aec;
    case 0x00502aeeu: goto L00502aee;
    case 0x00502af1u: goto L00502af1;
    case 0x00502af4u: goto L00502af4;
    case 0x00502afau: goto L00502afa;
    case 0x00502b00u: goto L00502b00;
    case 0x00502b06u: goto L00502b06;
    case 0x00502b08u: goto L00502b08;
    case 0x00502b0eu: goto L00502b0e;
    case 0x00502b14u: goto L00502b14;
    case 0x00502b16u: goto L00502b16;
    case 0x00502b18u: goto L00502b18;
    case 0x00502b1eu: goto L00502b1e;
    case 0x00502b21u: goto L00502b21;
    case 0x00502b27u: goto L00502b27;
    case 0x00502b2au: goto L00502b2a;
    case 0x00502b30u: goto L00502b30;
    case 0x00502b36u: goto L00502b36;
    case 0x00502b38u: goto L00502b38;
    case 0x00502b3au: goto L00502b3a;
    case 0x00502b40u: goto L00502b40;
    case 0x00502b46u: goto L00502b46;
    case 0x00502b48u: goto L00502b48;
    case 0x00502b4eu: goto L00502b4e;
    case 0x00502b53u: goto L00502b53;
    case 0x00502b59u: goto L00502b59;
    case 0x00502b5bu: goto L00502b5b;
    case 0x00502b5du: goto L00502b5d;
    case 0x00502b5fu: goto L00502b5f;
    case 0x00502b64u: goto L00502b64;
    case 0x00502b66u: goto L00502b66;
    case 0x00502b6cu: goto L00502b6c;
    case 0x00502b72u: goto L00502b72;
    case 0x00502b73u: goto L00502b73;
    case 0x00502b79u: goto L00502b79;
    case 0x00502b7eu: goto L00502b7e;
    case 0x00502b80u: goto L00502b80;
    case 0x00502b82u: goto L00502b82;
    case 0x00502b85u: goto L00502b85;
    case 0x00502b8bu: goto L00502b8b;
    case 0x00502b90u: goto L00502b90;
    case 0x00502b95u: goto L00502b95;
    case 0x00502b98u: goto L00502b98;
    case 0x00502b9au: goto L00502b9a;
    case 0x00502ba0u: goto L00502ba0;
    case 0x00502ba2u: goto L00502ba2;
    case 0x00502ba8u: goto L00502ba8;
    case 0x00502babu: goto L00502bab;
    case 0x00502bb1u: goto L00502bb1;
    case 0x00502bb6u: goto L00502bb6;
    case 0x00502bbbu: goto L00502bbb;
    case 0x00502bbeu: goto L00502bbe;
    case 0x00502bc0u: goto L00502bc0;
    case 0x00502bc6u: goto L00502bc6;
    case 0x00502bc9u: goto L00502bc9;
    case 0x00502bcbu: goto L00502bcb;
    case 0x00502bd1u: goto L00502bd1;
    case 0x00502bd3u: goto L00502bd3;
    case 0x00502bd9u: goto L00502bd9;
    case 0x00502bdbu: goto L00502bdb;
    case 0x00502be1u: goto L00502be1;
    case 0x00502be7u: goto L00502be7;
    case 0x00502be8u: goto L00502be8;
    case 0x00502bedu: goto L00502bed;
    case 0x00502befu: goto L00502bef;
    case 0x00502bf5u: goto L00502bf5;
    case 0x00502bfau: goto L00502bfa;
    case 0x00502bfcu: goto L00502bfc;
    case 0x00502c02u: goto L00502c02;
    case 0x00502c04u: goto L00502c04;
    case 0x00502c09u: goto L00502c09;
    case 0x00502c0bu: goto L00502c0b;
    case 0x00502c0du: goto L00502c0d;
    case 0x00502c14u: goto L00502c14;
    case 0x00502c16u: goto L00502c16;
    case 0x00502c19u: goto L00502c19;
    case 0x00502c1fu: goto L00502c1f;
    case 0x00502c24u: goto L00502c24;
    case 0x00502c29u: goto L00502c29;
    case 0x00502c2bu: goto L00502c2b;
    case 0x00502c2du: goto L00502c2d;
    case 0x00502c30u: goto L00502c30;
    case 0x00502c32u: goto L00502c32;
    case 0x00502c34u: goto L00502c34;
    case 0x00502c36u: goto L00502c36;
    case 0x00502c3bu: goto L00502c3b;
    case 0x00502c3du: goto L00502c3d;
    case 0x00502c3fu: goto L00502c3f;
    case 0x00502c42u: goto L00502c42;
    case 0x00502c48u: goto L00502c48;
    case 0x00502c4bu: goto L00502c4b;
    case 0x00502c4du: goto L00502c4d;
    case 0x00502c50u: goto L00502c50;
    case 0x00502c52u: goto L00502c52;
    case 0x00502c55u: goto L00502c55;
    case 0x00502c5bu: goto L00502c5b;
    case 0x00502c5eu: goto L00502c5e;
    case 0x00502c64u: goto L00502c64;
    case 0x00502c69u: goto L00502c69;
    case 0x00502c6eu: goto L00502c6e;
    case 0x00502c74u: goto L00502c74;
    case 0x00502c76u: goto L00502c76;
    case 0x00502c77u: goto L00502c77;
    case 0x00502c79u: goto L00502c79;
    case 0x00502c7fu: goto L00502c7f;
    case 0x00502c81u: goto L00502c81;
    case 0x00502c87u: goto L00502c87;
    case 0x00502c8cu: goto L00502c8c;
    case 0x00502c91u: goto L00502c91;
    case 0x00502c97u: goto L00502c97;
    case 0x00502c9du: goto L00502c9d;
    case 0x00502c9fu: goto L00502c9f;
    case 0x00502ca5u: goto L00502ca5;
    case 0x00502ca8u: goto L00502ca8;
    case 0x00502caeu: goto L00502cae;
    case 0x00502cb3u: goto L00502cb3;
    case 0x00502cb8u: goto L00502cb8;
    case 0x00502cbau: goto L00502cba;
    case 0x00502cbcu: goto L00502cbc;
    case 0x00502cbfu: goto L00502cbf;
    case 0x00502cc0u: goto L00502cc0;
    case 0x00502cc3u: goto L00502cc3;
    case 0x00502cc9u: goto L00502cc9;
    case 0x00502ccbu: goto L00502ccb;
    case 0x00502cd1u: goto L00502cd1;
    case 0x00502cd8u: goto L00502cd8;
    case 0x00502cdeu: goto L00502cde;
    case 0x00502ce0u: goto L00502ce0;
    case 0x00502ce2u: goto L00502ce2;
    case 0x00502ce7u: goto L00502ce7;
    case 0x00502cecu: goto L00502cec;
    case 0x00502cf2u: goto L00502cf2;
    case 0x00502cf3u: goto L00502cf3;
    case 0x00502cf5u: goto L00502cf5;
    case 0x00502cf8u: goto L00502cf8;
    case 0x00502cfau: goto L00502cfa;
    case 0x00502cfcu: goto L00502cfc;
    case 0x00502d02u: goto L00502d02;
    case 0x00502d04u: goto L00502d04;
    case 0x00502d06u: goto L00502d06;
    case 0x00502d09u: goto L00502d09;
    case 0x00502d0bu: goto L00502d0b;
    case 0x00502d10u: goto L00502d10;
    case 0x00502d12u: goto L00502d12;
    case 0x00502d18u: goto L00502d18;
    case 0x00502d1au: goto L00502d1a;
    case 0x00502d1cu: goto L00502d1c;
    case 0x00502d22u: goto L00502d22;
    case 0x00502d24u: goto L00502d24;
    case 0x00502d26u: goto L00502d26;
    case 0x00502d2bu: goto L00502d2b;
    case 0x00502d30u: goto L00502d30;
    case 0x00502d36u: goto L00502d36;
    case 0x00502d37u: goto L00502d37;
    case 0x00502d39u: goto L00502d39;
    case 0x00502d3fu: goto L00502d3f;
    case 0x00502d41u: goto L00502d41;
    case 0x00502d43u: goto L00502d43;
    case 0x00502d46u: goto L00502d46;
    case 0x00502d48u: goto L00502d48;
    case 0x00502d4du: goto L00502d4d;
    case 0x00502d4fu: goto L00502d4f;
    case 0x00502d55u: goto L00502d55;
    case 0x00502d57u: goto L00502d57;
    case 0x00502d59u: goto L00502d59;
    case 0x00502d5eu: goto L00502d5e;
    case 0x00502d63u: goto L00502d63;
    case 0x00502d69u: goto L00502d69;
    case 0x00502d6au: goto L00502d6a;
    case 0x00502d6cu: goto L00502d6c;
    case 0x00502d6fu: goto L00502d6f;
    case 0x00502d71u: goto L00502d71;
    case 0x00502d73u: goto L00502d73;
    case 0x00502d77u: goto L00502d77;
    case 0x00502d7au: goto L00502d7a;
    case 0x00502d7cu: goto L00502d7c;
    case 0x00502d7eu: goto L00502d7e;
    case 0x00502d83u: goto L00502d83;
    case 0x00502d85u: goto L00502d85;
    case 0x00502d87u: goto L00502d87;
    case 0x00502d8du: goto L00502d8d;
    case 0x00502d8fu: goto L00502d8f;
    case 0x00502d95u: goto L00502d95;
    case 0x00502d99u: goto L00502d99;
    case 0x00502d9fu: goto L00502d9f;
    case 0x00502da5u: goto L00502da5;
    case 0x00502dabu: goto L00502dab;
    case 0x00502daeu: goto L00502dae;
    case 0x00502db0u: goto L00502db0;
    case 0x00502db6u: goto L00502db6;
    case 0x00502db8u: goto L00502db8;
    case 0x00502dbfu: goto L00502dbf;
    case 0x00502dc1u: goto L00502dc1;
    case 0x00502dc5u: goto L00502dc5;
    case 0x00502dc7u: goto L00502dc7;
    case 0x00502dc9u: goto L00502dc9;
    case 0x00502dcfu: goto L00502dcf;
    case 0x00502dd1u: goto L00502dd1;
    case 0x00502dd4u: goto L00502dd4;
    case 0x00502dd6u: goto L00502dd6;
    case 0x00502dd7u: goto L00502dd7;
    case 0x00502dd8u: goto L00502dd8;
    case 0x00502dd9u: goto L00502dd9;
    case 0x00502ddeu: goto L00502dde;
    case 0x00502ddfu: goto L00502ddf;
    case 0x00502de2u: goto L00502de2;
    case 0x00502de5u: goto L00502de5;
    case 0x00502de7u: goto L00502de7;
    case 0x00502de8u: goto L00502de8;
    case 0x00502de9u: goto L00502de9;
    case 0x00502deau: goto L00502dea;
    case 0x00502decu: goto L00502dec;
    case 0x00502dedu: goto L00502ded;
    case 0x00502df0u: goto L00502df0;
    case 0x00502df3u: goto L00502df3;
    case 0x00502df9u: goto L00502df9;
    case 0x00502dfbu: goto L00502dfb;
    case 0x00502dfdu: goto L00502dfd;
    case 0x00502e01u: goto L00502e01;
    case 0x00502e03u: goto L00502e03;
    case 0x00502e05u: goto L00502e05;
    case 0x00502e09u: goto L00502e09;
    case 0x00502e0fu: goto L00502e0f;
    case 0x00502e15u: goto L00502e15;
    case 0x00502e1bu: goto L00502e1b;
    case 0x00502e1eu: goto L00502e1e;
    case 0x00502e20u: goto L00502e20;
    case 0x00502e27u: goto L00502e27;
    case 0x00502e2du: goto L00502e2d;
    case 0x00502e2fu: goto L00502e2f;
    case 0x00502e32u: goto L00502e32;
    case 0x00502e34u: goto L00502e34;
    case 0x00502e35u: goto L00502e35;
    case 0x00502e36u: goto L00502e36;
    case 0x00502e37u: goto L00502e37;
    case 0x00502e3cu: goto L00502e3c;
    case 0x00502e3du: goto L00502e3d;
    case 0x00502e40u: goto L00502e40;
    case 0x00502e43u: goto L00502e43;
    case 0x00502e45u: goto L00502e45;
    case 0x00502e47u: goto L00502e47;
    case 0x00502e4bu: goto L00502e4b;
    case 0x00502e4du: goto L00502e4d;
    case 0x00502e4fu: goto L00502e4f;
    case 0x00502e50u: goto L00502e50;
    case 0x00502e51u: goto L00502e51;
    case 0x00502e52u: goto L00502e52;
    case 0x00502e57u: goto L00502e57;
    case 0x00502e58u: goto L00502e58;
    case 0x00502e5bu: goto L00502e5b;
    case 0x00502e5eu: goto L00502e5e;
    case 0x00502e62u: goto L00502e62;
    case 0x00502e65u: goto L00502e65;
    case 0x00502e67u: goto L00502e67;
    case 0x00502e6du: goto L00502e6d;
    case 0x00502e6eu: goto L00502e6e;
    case 0x00502e73u: goto L00502e73;
    case 0x00502e75u: goto L00502e75;
    case 0x00502e77u: goto L00502e77;
    case 0x00502e7bu: goto L00502e7b;
    case 0x00502e7du: goto L00502e7d;
    case 0x00502e80u: goto L00502e80;
    case 0x00502e83u: goto L00502e83;
    case 0x00502e85u: goto L00502e85;
    case 0x00502e88u: goto L00502e88;
    case 0x00502e8au: goto L00502e8a;
    case 0x00502e8eu: goto L00502e8e;
    case 0x00502e8fu: goto L00502e8f;
    case 0x00502e92u: goto L00502e92;
    case 0x00502e93u: goto L00502e93;
    case 0x00502e95u: goto L00502e95;
    case 0x00502e97u: goto L00502e97;
    case 0x00502e98u: goto L00502e98;
    case 0x00502e9bu: goto L00502e9b;
    case 0x00502e9eu: goto L00502e9e;
    case 0x00502ea0u: goto L00502ea0;
    case 0x00502ea1u: goto L00502ea1;
    case 0x00502ea4u: goto L00502ea4;
    case 0x00502ea7u: goto L00502ea7;
    case 0x00502ea9u: goto L00502ea9;
    case 0x00502eabu: goto L00502eab;
    case 0x00502eb0u: goto L00502eb0;
    case 0x00502eb2u: goto L00502eb2;
    case 0x00502eb4u: goto L00502eb4;
    case 0x00502eb7u: goto L00502eb7;
    case 0x00502eb9u: goto L00502eb9;
    case 0x00502ebeu: goto L00502ebe;
    case 0x00502ebfu: goto L00502ebf;
    case 0x00502ec0u: goto L00502ec0;
    case 0x00502ec2u: goto L00502ec2;
    case 0x00502ec3u: goto L00502ec3;
    case 0x00502ec4u: goto L00502ec4;
    case 0x00502ec7u: goto L00502ec7;
    case 0x00502ecau: goto L00502eca;
    case 0x00502eceu: goto L00502ece;
    case 0x00502ed0u: goto L00502ed0;
    case 0x00502ed2u: goto L00502ed2;
    case 0x00502ed4u: goto L00502ed4;
    case 0x00502ed6u: goto L00502ed6;
    case 0x00502edbu: goto L00502edb;
    case 0x00502eddu: goto L00502edd;
    case 0x00502edfu: goto L00502edf;
    case 0x00502ee0u: goto L00502ee0;
    case 0x00502ee1u: goto L00502ee1;
    case 0x00502ee2u: goto L00502ee2;
    case 0x00502ee3u: goto L00502ee3;
    case 0x00502ee6u: goto L00502ee6;
    default:throw std::domain_error("recovery235 unsupported switch destination");}
  }
  L00502cd8: { // 0x502cd8: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00502cde: { // 0x502cde: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502ce0: { // 0x502ce0: 750a JNZ 0x502CEC
    if(integer::condition("JNZ",flags)) goto L00502cec;
  }
  L00502ce2: { // 0x502ce2: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L00502ce7: { // 0x502ce7: e884e52700 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5254380u); flags=s.arithmetic_flags;
  }
  L00502cec: { // 0x502cec: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00502cf2: { // 0x502cf2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00502cf3: { // 0x502cf3: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00502cf5: { // 0x502cf5: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5254392u); flags=s.arithmetic_flags;
  }
  L00502cf8: { // 0x502cf8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502cfa: { // 0x502cfa: 7516 JNZ 0x502D12
    if(integer::condition("JNZ",flags)) goto L00502d12;
  }
  L00502cfc: { // 0x502cfc: 8b8694040000 MOV EAX, dword ptr [ESI + 0x494]
    s.ax = m.r32((s.si+0x00000494u));
  }
  L00502d02: { // 0x502d02: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502d04: { // 0x502d04: 750c JNZ 0x502D12
    if(integer::condition("JNZ",flags)) goto L00502d12;
  }
  L00502d06: { // 0x502d06: 83fb06 CMP EBX, 6
    (void)integer::sub(s.bx,6u,32,flags);
  }
  L00502d09: { // 0x502d09: 7d6c JGE 0x502D77
    if(integer::condition("JGE",flags)) goto L00502d77;
  }
  L00502d0b: { // 0x502d0b: bb06000000 MOV EBX, 6
    s.bx = 6u;
  }
  L00502d10: { // 0x502d10: eb65 JMP 0x502D77
    goto L00502d77;
  }
  L00502d12: { // 0x502d12: 8a86a0050000 MOV AL, byte ptr [ESI + 0x5A0]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005a0u)));
  }
  L00502d18: { // 0x502d18: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502d1a: { // 0x502d1a: 7527 JNZ 0x502D43
    if(integer::condition("JNZ",flags)) goto L00502d43;
  }
  L00502d1c: { // 0x502d1c: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00502d22: { // 0x502d22: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502d24: { // 0x502d24: 750a JNZ 0x502D30
    if(integer::condition("JNZ",flags)) goto L00502d30;
  }
  L00502d26: { // 0x502d26: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L00502d2b: { // 0x502d2b: e840e52700 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5254448u); flags=s.arithmetic_flags;
  }
  L00502d30: { // 0x502d30: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00502d36: { // 0x502d36: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00502d37: { // 0x502d37: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00502d39: { // 0x502d39: ff91a4000000 CALL dword ptr [ECX + 0xA4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x000000a4u)),5254463u); flags=s.arithmetic_flags;
  }
  L00502d3f: { // 0x502d3f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502d41: { // 0x502d41: 7434 JZ 0x502D77
    if(integer::condition("JZ",flags)) goto L00502d77;
  }
  L00502d43: { // 0x502d43: 83fb02 CMP EBX, 2
    (void)integer::sub(s.bx,2u,32,flags);
  }
  L00502d46: { // 0x502d46: 7d2f JGE 0x502D77
    if(integer::condition("JGE",flags)) goto L00502d77;
  }
  L00502d48: { // 0x502d48: bb02000000 MOV EBX, 2
    s.bx = 2u;
  }
  L00502d4d: { // 0x502d4d: eb28 JMP 0x502D77
    goto L00502d77;
  }
  L00502d4f: { // 0x502d4f: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00502d55: { // 0x502d55: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502d57: { // 0x502d57: 750a JNZ 0x502D63
    if(integer::condition("JNZ",flags)) goto L00502d63;
  }
  L00502d59: { // 0x502d59: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L00502d5e: { // 0x502d5e: e80de52700 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5254499u); flags=s.arithmetic_flags;
  }
  L00502d63: { // 0x502d63: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00502d69: { // 0x502d69: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00502d6a: { // 0x502d6a: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00502d6c: { // 0x502d6c: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5254511u); flags=s.arithmetic_flags;
  }
  L00502d6f: { // 0x502d6f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502d71: { // 0x502d71: 7504 JNZ 0x502D77
    if(integer::condition("JNZ",flags)) goto L00502d77;
  }
  L00502d73: { // 0x502d73: ff44243c INC dword ptr [ESP + 0x3C]
    m.w32((f.sp+0x0000003cu), integer::increment(m.r32((f.sp+0x0000003cu)),32,flags));
  }
  L00502d77: { // 0x502d77: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00502d7a: { // 0x502d7a: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00502d7c: { // 0x502d7c: 7475 JZ 0x502DF3
    if(integer::condition("JZ",flags)) goto L00502df3;
  }
  L00502d7e: { // 0x502d7e: e990fbffff JMP 0x502913
    goto L00502913;
  }
  L00502d83: { // 0x502d83: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00502d85: { // 0x502d85: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00502d87: { // 0x502d87: ff904c010000 CALL dword ptr [EAX + 0x14C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000014cu)),5254541u); flags=s.arithmetic_flags;
  }
  L00502d8d: { // 0x502d8d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502d8f: { // 0x502d8f: 0f859f000000 JNZ 0x502E34
    if(integer::condition("JNZ",flags)) goto L00502e34;
  }
  L00502d95: { // 0x502d95: 8b542438 MOV EDX, dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00502d99: { // 0x502d99: 8b8da8050000 MOV ECX, dword ptr [EBP + 0x5A8]
    s.cx = m.r32((s.bp+0x000005a8u));
  }
  L00502d9f: { // 0x502d9f: 8b82ec000000 MOV EAX, dword ptr [EDX + 0xEC]
    s.ax = m.r32((s.dx+0x000000ecu));
  }
  L00502da5: { // 0x502da5: 8b89a4050000 MOV ECX, dword ptr [ECX + 0x5A4]
    s.cx = m.r32((s.cx+0x000005a4u));
  }
  L00502dab: { // 0x502dab: 8d04c0 LEA EAX, [EAX + EAX*8]
    s.ax = (s.ax+(s.ax * 8u));
  }
  L00502dae: { // 0x502dae: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00502db0: { // 0x502db0: 8a8570030000 MOV AL, byte ptr [EBP + 0x370]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000370u)));
  }
  L00502db6: { // 0x502db6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502db8: { // 0x502db8: d9048dd0918300 FLD dword ptr [ECX*4 + 0x8391D0]
    const auto address=((s.cx * 4u)+0x008391d0u);
    s.fp.load32(m.r32(address));
  }
  L00502dbf: { // 0x502dbf: 7524 JNZ 0x502DE5
    if(integer::condition("JNZ",flags)) goto L00502de5;
  }
  L00502dc1: { // 0x502dc1: 8a442411 MOV AL, byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L00502dc5: { // 0x502dc5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502dc7: { // 0x502dc7: 751c JNZ 0x502DE5
    if(integer::condition("JNZ",flags)) goto L00502de5;
  }
  L00502dc9: { // 0x502dc9: d81d38577800 FCOMP dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00502dcf: { // 0x502dcf: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00502dd1: { // 0x502dd1: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00502dd4: { // 0x502dd4: 7411 JZ 0x502DE7
    if(integer::condition("JZ",flags)) goto L00502de7;
  }
  L00502dd6: { // 0x502dd6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502dd7: { // 0x502dd7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502dd8: { // 0x502dd8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502dd9: { // 0x502dd9: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L00502dde: { // 0x502dde: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502ddf: { // 0x502ddf: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502de2: { // 0x502de2: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502de5: { // 0x502de5: ddd8 FSTP ST(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00502de7: { // 0x502de7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502de8: { // 0x502de8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502de9: { // 0x502de9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502dea: { // 0x502dea: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00502dec: { // 0x502dec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502ded: { // 0x502ded: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502df0: { // 0x502df0: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502df3: { // 0x502df3: 8a8570030000 MOV AL, byte ptr [EBP + 0x370]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000370u)));
  }
  L00502df9: { // 0x502df9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502dfb: { // 0x502dfb: 7546 JNZ 0x502E43
    if(integer::condition("JNZ",flags)) goto L00502e43;
  }
  L00502dfd: { // 0x502dfd: 8a442411 MOV AL, byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L00502e01: { // 0x502e01: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502e03: { // 0x502e03: 753e JNZ 0x502E43
    if(integer::condition("JNZ",flags)) goto L00502e43;
  }
  L00502e05: { // 0x502e05: 8b442438 MOV EAX, dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00502e09: { // 0x502e09: 8b95a8050000 MOV EDX, dword ptr [EBP + 0x5A8]
    s.dx = m.r32((s.bp+0x000005a8u));
  }
  L00502e0f: { // 0x502e0f: 8b80ec000000 MOV EAX, dword ptr [EAX + 0xEC]
    s.ax = m.r32((s.ax+0x000000ecu));
  }
  L00502e15: { // 0x502e15: 8b92a4050000 MOV EDX, dword ptr [EDX + 0x5A4]
    s.dx = m.r32((s.dx+0x000005a4u));
  }
  L00502e1b: { // 0x502e1b: 8d0cc0 LEA ECX, [EAX + EAX*8]
    s.cx = (s.ax+(s.ax * 8u));
  }
  L00502e1e: { // 0x502e1e: 03d1 ADD EDX, ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00502e20: { // 0x502e20: d90495d0918300 FLD dword ptr [EDX*4 + 0x8391D0]
    const auto address=((s.dx * 4u)+0x008391d0u);
    s.fp.load32(m.r32(address));
  }
  L00502e27: { // 0x502e27: d81d38577800 FCOMP dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00502e2d: { // 0x502e2d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00502e2f: { // 0x502e2f: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00502e32: { // 0x502e32: 740f JZ 0x502E43
    if(integer::condition("JZ",flags)) goto L00502e43;
  }
  L00502e34: { // 0x502e34: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502e35: { // 0x502e35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502e36: { // 0x502e36: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502e37: { // 0x502e37: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L00502e3c: { // 0x502e3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502e3d: { // 0x502e3d: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502e40: { // 0x502e40: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502e43: { // 0x502e43: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00502e45: { // 0x502e45: 7517 JNZ 0x502E5E
    if(integer::condition("JNZ",flags)) goto L00502e5e;
  }
  L00502e47: { // 0x502e47: 8a442413 MOV AL, byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00502e4b: { // 0x502e4b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502e4d: { // 0x502e4d: 740f JZ 0x502E5E
    if(integer::condition("JZ",flags)) goto L00502e5e;
  }
  L00502e4f: { // 0x502e4f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502e50: { // 0x502e50: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502e51: { // 0x502e51: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502e52: { // 0x502e52: b802000000 MOV EAX, 2
    s.ax = 2u;
  }
  L00502e57: { // 0x502e57: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502e58: { // 0x502e58: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502e5b: { // 0x502e5b: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502e5e: { // 0x502e5e: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00502e62: { // 0x502e62: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00502e65: { // 0x502e65: 7463 JZ 0x502ECA
    if(integer::condition("JZ",flags)) goto L00502eca;
  }
  L00502e67: { // 0x502e67: 8b8db4010000 MOV ECX, dword ptr [EBP + 0x1B4]
    s.cx = m.r32((s.bp+0x000001b4u));
  }
  L00502e6d: { // 0x502e6d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00502e6e: { // 0x502e6e: e82d1dfeff CALL 0x4E4BA0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4ba0u,5254771u); flags=s.arithmetic_flags;
  }
  L00502e73: { // 0x502e73: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00502e75: { // 0x502e75: 7430 JZ 0x502EA7
    if(integer::condition("JZ",flags)) goto L00502ea7;
  }
  L00502e77: { // 0x502e77: 8a442412 MOV AL, byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L00502e7b: { // 0x502e7b: 8ac8 MOV CL, AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L00502e7d: { // 0x502e7d: 80e11c AND CL, 0x1C
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x0000001cu),8,flags));
  }
  L00502e80: { // 0x502e80: 80f91c CMP CL, 0x1C
    (void)integer::sub((s.cx & 0xffu),0x0000001cu,8,flags);
  }
  L00502e83: { // 0x502e83: 7549 JNZ 0x502ECE
    if(integer::condition("JNZ",flags)) goto L00502ece;
  }
  L00502e85: { // 0x502e85: 83fb02 CMP EBX, 2
    (void)integer::sub(s.bx,2u,32,flags);
  }
  L00502e88: { // 0x502e88: 7d44 JGE 0x502ECE
    if(integer::condition("JGE",flags)) goto L00502ece;
  }
  L00502e8a: { // 0x502e8a: 8b5c243c MOV EBX, dword ptr [ESP + 0x3C]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L00502e8e: { // 0x502e8e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502e8f: { // 0x502e8f: 83eb03 SUB EBX, 3
    s.bx = integer::sub(s.bx,3u,32,flags);
  }
  L00502e92: { // 0x502e92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502e93: { // 0x502e93: f7db NEG EBX
    s.bx = integer::sub(0u,s.bx,32,flags);
  }
  L00502e95: { // 0x502e95: 1bdb SBB EBX, EBX
    s.bx = integer::sub(s.bx,s.bx,32,flags,flags&integer::CF);
  }
  L00502e97: { // 0x502e97: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502e98: { // 0x502e98: 83e3fc AND EBX, 0xFFFFFFFC
    s.bx = integer::logical((s.bx)&(0xfffffffcu),32,flags);
  }
  L00502e9b: { // 0x502e9b: 83c306 ADD EBX, 6
    s.bx = integer::add(s.bx,6u,32,flags);
  }
  L00502e9e: { // 0x502e9e: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L00502ea0: { // 0x502ea0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502ea1: { // 0x502ea1: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502ea4: { // 0x502ea4: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502ea7: { // 0x502ea7: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L00502ea9: { // 0x502ea9: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00502eab: { // 0x502eab: e8903e1b00 CALL 0x6B6D40
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b6d40u,5254832u); flags=s.arithmetic_flags;
  }
  L00502eb0: { // 0x502eb0: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00502eb2: { // 0x502eb2: 7e80 JLE 0x502E34
    if(integer::condition("JLE",flags)) goto L00502e34;
  }
  L00502eb4: { // 0x502eb4: 83fb05 CMP EBX, 5
    (void)integer::sub(s.bx,5u,32,flags);
  }
  L00502eb7: { // 0x502eb7: 7d11 JGE 0x502ECA
    if(integer::condition("JGE",flags)) goto L00502eca;
  }
  L00502eb9: { // 0x502eb9: bb05000000 MOV EBX, 5
    s.bx = 5u;
  }
  L00502ebe: { // 0x502ebe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502ebf: { // 0x502ebf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502ec0: { // 0x502ec0: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L00502ec2: { // 0x502ec2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502ec3: { // 0x502ec3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502ec4: { // 0x502ec4: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502ec7: { // 0x502ec7: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00502eca: { // 0x502eca: 8a442412 MOV AL, byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L00502ece: { // 0x502ece: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00502ed0: { // 0x502ed0: 750b JNZ 0x502EDD
    if(integer::condition("JNZ",flags)) goto L00502edd;
  }
  L00502ed2: { // 0x502ed2: 241c AND AL, 0x1C
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x0000001cu),8,flags));
  }
  L00502ed4: { // 0x502ed4: 3c1c CMP AL, 0x1C
    (void)integer::sub((s.ax & 0xffu),0x0000001cu,8,flags);
  }
  L00502ed6: { // 0x502ed6: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L00502edb: { // 0x502edb: 7402 JZ 0x502EDF
    if(integer::condition("JZ",flags)) goto L00502edf;
  }
  L00502edd: { // 0x502edd: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L00502edf: { // 0x502edf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00502ee0: { // 0x502ee0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00502ee1: { // 0x502ee1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00502ee2: { // 0x502ee2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00502ee3: { // 0x502ee3: 83c424 ADD ESP, 0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00502ee6: { // 0x502ee6: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_000c8330(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004c8330: { // 0x4c8330: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004c8331: { // 0x4c8331: 8b5c240c MOV EBX, dword ptr [ESP + 0xC]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L004c8335: { // 0x4c8335: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004c8336: { // 0x4c8336: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004c8337: { // 0x4c8337: 8b742420 MOV ESI, dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L004c833b: { // 0x4c833b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004c833c: { // 0x4c833c: 8b7c2414 MOV EDI, dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L004c8340: { // 0x4c8340: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004c8342: { // 0x4c8342: 7548 JNZ 0x4C838C
    if(integer::condition("JNZ",flags)) goto L004c838c;
  }
  L004c8344: { // 0x4c8344: 8d43fc LEA EAX, [EBX - 4]
    s.ax = (s.bx-4u);
  }
  L004c8347: { // 0x4c8347: 83e007 AND EAX, 7
    s.ax = integer::logical((s.ax)&(7u),32,flags);
  }
  L004c834a: { // 0x4c834a: 668b0c85a09d8300 MOV CX, word ptr [EAX*4 + 0x839DA0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 4u)+0x00839da0u)));
  }
  L004c8352: { // 0x4c8352: 668b1485a29d8300 MOV DX, word ptr [EAX*4 + 0x839DA2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 4u)+0x00839da2u)));
  }
  L004c835a: { // 0x4c835a: 66034f24 ADD CX, word ptr [EDI + 0x24]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.di+0x00000024u)),16,flags));
  }
  L004c835e: { // 0x4c835e: 66035726 ADD DX, word ptr [EDI + 0x26]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.di+0x00000026u)),16,flags));
  }
  L004c8362: { // 0x4c8362: 8d0485a09d8300 LEA EAX, [EAX*4 + 0x839DA0]
    s.ax = ((s.ax * 4u)+0x00839da0u);
  }
  L004c8369: { // 0x4c8369: 66894c2424 MOV word ptr [ESP + 0x24], CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L004c836e: { // 0x4c836e: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L004c8372: { // 0x4c8372: 6689542426 MOV word ptr [ESP + 0x26], DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L004c8377: { // 0x4c8377: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L004c837b: { // 0x4c837b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004c837c: { // 0x4c837c: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L004c8381: { // 0x4c8381: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004c8385: { // 0x4c8385: e876d10700 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5014410u); flags=s.arithmetic_flags;
  }
  L004c838a: { // 0x4c838a: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L004c838c: { // 0x4c838c: 83fbff CMP EBX, -1
    (void)integer::sub(s.bx,4294967295u,32,flags);
  }
  L004c838f: { // 0x4c838f: 0f8479010000 JZ 0x4C850E
    if(integer::condition("JZ",flags)) goto L004c850e;
  }
  L004c8395: { // 0x4c8395: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004c8397: { // 0x4c8397: 0f8491010000 JZ 0x4C852E
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  L004c839d: { // 0x4c839d: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004c839f: { // 0x4c839f: 0f8489010000 JZ 0x4C852E
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  L004c83a5: { // 0x4c83a5: 8b6c241c MOV EBP, dword ptr [ESP + 0x1C]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L004c83a9: { // 0x4c83a9: 837d00ff CMP dword ptr [EBP], -1
    (void)integer::sub(m.r32((s.bp)),4294967295u,32,flags);
  }
  L004c83ad: { // 0x4c83ad: 752f JNZ 0x4C83DE
    if(integer::condition("JNZ",flags)) goto L004c83de;
  }
  L004c83af: { // 0x4c83af: 8b8640010000 MOV EAX, dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L004c83b5: { // 0x4c83b5: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L004c83b8: { // 0x4c83b8: 7424 JZ 0x4C83DE
    if(integer::condition("JZ",flags)) goto L004c83de;
  }
  L004c83ba: { // 0x4c83ba: 0fbe961b010000 MOVSX EDX, byte ptr [ESI + 0x11B]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004c83c1: { // 0x4c83c1: 83c204 ADD EDX, 4
    s.dx = integer::add(s.dx,4u,32,flags);
  }
  L004c83c4: { // 0x4c83c4: 895500 MOV dword ptr [EBP], EDX
    m.w32((s.bp), s.dx);
  }
  L004c83c7: { // 0x4c83c7: 8b8740010000 MOV EAX, dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L004c83cd: { // 0x4c83cd: f6c402 TEST AH, 2
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(2u),8,flags);
  }
  L004c83d0: { // 0x4c83d0: 750c JNZ 0x4C83DE
    if(integer::condition("JNZ",flags)) goto L004c83de;
  }
  L004c83d2: { // 0x4c83d2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c83d3: { // 0x4c83d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c83d4: { // 0x4c83d4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c83d5: { // 0x4c83d5: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c83da: { // 0x4c83da: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c83db: { // 0x4c83db: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c83de: { // 0x4c83de: 8b8640010000 MOV EAX, dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L004c83e4: { // 0x4c83e4: 0fbe9f1b010000 MOVSX EBX, byte ptr [EDI + 0x11B]
    s.bx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L004c83eb: { // 0x4c83eb: 2500010000 AND EAX, 0x100
    s.ax = integer::logical((s.ax)&(0x00000100u),32,flags);
  }
  L004c83f0: { // 0x4c83f0: 8944241c MOV dword ptr [ESP + 0x1C], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004c83f4: { // 0x4c83f4: 7409 JZ 0x4C83FF
    if(integer::condition("JZ",flags)) goto L004c83ff;
  }
  L004c83f6: { // 0x4c83f6: 0fbe8e1b010000 MOVSX ECX, byte ptr [ESI + 0x11B]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004c83fd: { // 0x4c83fd: eb03 JMP 0x4C8402
    goto L004c8402;
  }
  L004c83ff: { // 0x4c83ff: 8b4d00 MOV ECX, dword ptr [EBP]
    s.cx = m.r32((s.bp));
  }
  L004c8402: { // 0x4c8402: 2bcb SUB ECX, EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L004c8404: { // 0x4c8404: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004c8406: { // 0x4c8406: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004c8407: { // 0x4c8407: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004c8409: { // 0x4c8409: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004c840b: { // 0x4c840b: 83e800 SUB EAX, 0
    s.ax = integer::sub(s.ax,0u,32,flags);
  }
  L004c840e: { // 0x4c840e: 0f84c4000000 JZ 0x4C84D8
    if(integer::condition("JZ",flags)) goto L004c84d8;
  }
  L004c8414: { // 0x4c8414: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004c8415: { // 0x4c8415: 0f848d000000 JZ 0x4C84A8
    if(integer::condition("JZ",flags)) goto L004c84a8;
  }
  L004c841b: { // 0x4c841b: 83e803 SUB EAX, 3
    s.ax = integer::sub(s.ax,3u,32,flags);
  }
  L004c841e: { // 0x4c841e: 740c JZ 0x4C842C
    if(integer::condition("JZ",flags)) goto L004c842c;
  }
  L004c8420: { // 0x4c8420: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c8421: { // 0x4c8421: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c8422: { // 0x4c8422: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c8423: { // 0x4c8423: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c8428: { // 0x4c8428: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c8429: { // 0x4c8429: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c842c: { // 0x4c842c: 0fbe861b010000 MOVSX EAX, byte ptr [ESI + 0x11B]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004c8433: { // 0x4c8433: 8d4bfc LEA ECX, [EBX - 4]
    s.cx = (s.bx-4u);
  }
  L004c8436: { // 0x4c8436: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004c8438: { // 0x4c8438: 7525 JNZ 0x4C845F
    if(integer::condition("JNZ",flags)) goto L004c845f;
  }
  L004c843a: { // 0x4c843a: 395d00 CMP dword ptr [EBP], EBX
    (void)integer::sub(m.r32((s.bp)),s.bx,32,flags);
  }
  L004c843d: { // 0x4c843d: 740c JZ 0x4C844B
    if(integer::condition("JZ",flags)) goto L004c844b;
  }
  L004c843f: { // 0x4c843f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c8440: { // 0x4c8440: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c8441: { // 0x4c8441: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c8442: { // 0x4c8442: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c8447: { // 0x4c8447: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c8448: { // 0x4c8448: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c844b: { // 0x4c844b: 8b4c241c MOV ECX, dword ptr [ESP + 0x1C]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L004c844f: { // 0x4c844f: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004c8451: { // 0x4c8451: 750c JNZ 0x4C845F
    if(integer::condition("JNZ",flags)) goto L004c845f;
  }
  L004c8453: { // 0x4c8453: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c8454: { // 0x4c8454: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c8455: { // 0x4c8455: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c8456: { // 0x4c8456: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c845b: { // 0x4c845b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c845c: { // 0x4c845c: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c845f: { // 0x4c845f: 83c0fc ADD EAX, -4
    s.ax = integer::add(s.ax,4294967292u,32,flags);
  }
  L004c8462: { // 0x4c8462: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004c8464: { // 0x4c8464: 0f85c4000000 JNZ 0x4C852E
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  L004c846a: { // 0x4c846a: 8bbf40010000 MOV EDI, dword ptr [EDI + 0x140]
    s.di = m.r32((s.di+0x00000140u));
  }
  L004c8470: { // 0x4c8470: f7c700010000 TEST EDI, 0x100
    (void)integer::logical((s.di)&(0x00000100u),32,flags);
  }
  L004c8476: { // 0x4c8476: 750c JNZ 0x4C8484
    if(integer::condition("JNZ",flags)) goto L004c8484;
  }
  L004c8478: { // 0x4c8478: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c8479: { // 0x4c8479: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c847a: { // 0x4c847a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c847b: { // 0x4c847b: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c8480: { // 0x4c8480: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c8481: { // 0x4c8481: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c8484: { // 0x4c8484: f7c700020000 TEST EDI, 0x200
    (void)integer::logical((s.di)&(0x00000200u),32,flags);
  }
  L004c848a: { // 0x4c848a: 750c JNZ 0x4C8498
    if(integer::condition("JNZ",flags)) goto L004c8498;
  }
  L004c848c: { // 0x4c848c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c848d: { // 0x4c848d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c848e: { // 0x4c848e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c848f: { // 0x4c848f: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c8494: { // 0x4c8494: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c8495: { // 0x4c8495: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c8498: { // 0x4c8498: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L004c849c: { // 0x4c849c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c849d: { // 0x4c849d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c849e: { // 0x4c849e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c849f: { // 0x4c849f: c60201 MOV byte ptr [EDX], 1
    m.w8((s.dx), 1u);
  }
  L004c84a2: { // 0x4c84a2: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004c84a4: { // 0x4c84a4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c84a5: { // 0x4c84a5: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c84a8: { // 0x4c84a8: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004c84aa: { // 0x4c84aa: 7e16 JLE 0x4C84C2
    if(integer::condition("JLE",flags)) goto L004c84c2;
  }
  L004c84ac: { // 0x4c84ac: 8a871c010000 MOV AL, byte ptr [EDI + 0x11C]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  L004c84b2: { // 0x4c84b2: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004c84b4: { // 0x4c84b4: 7578 JNZ 0x4C852E
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  L004c84b6: { // 0x4c84b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c84b7: { // 0x4c84b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c84b8: { // 0x4c84b8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c84b9: { // 0x4c84b9: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c84be: { // 0x4c84be: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c84bf: { // 0x4c84bf: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c84c2: { // 0x4c84c2: 8a861c010000 MOV AL, byte ptr [ESI + 0x11C]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011cu)));
  }
  L004c84c8: { // 0x4c84c8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004c84ca: { // 0x4c84ca: 7562 JNZ 0x4C852E
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  L004c84cc: { // 0x4c84cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c84cd: { // 0x4c84cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c84ce: { // 0x4c84ce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c84cf: { // 0x4c84cf: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c84d4: { // 0x4c84d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c84d5: { // 0x4c84d5: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c84d8: { // 0x4c84d8: 8bbf40010000 MOV EDI, dword ptr [EDI + 0x140]
    s.di = m.r32((s.di+0x00000140u));
  }
  L004c84de: { // 0x4c84de: f7c700010000 TEST EDI, 0x100
    (void)integer::logical((s.di)&(0x00000100u),32,flags);
  }
  L004c84e4: { // 0x4c84e4: 7410 JZ 0x4C84F6
    if(integer::condition("JZ",flags)) goto L004c84f6;
  }
  L004c84e6: { // 0x4c84e6: f7c700020000 TEST EDI, 0x200
    (void)integer::logical((s.di)&(0x00000200u),32,flags);
  }
  L004c84ec: { // 0x4c84ec: 7408 JZ 0x4C84F6
    if(integer::condition("JZ",flags)) goto L004c84f6;
  }
  L004c84ee: { // 0x4c84ee: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004c84f2: { // 0x4c84f2: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004c84f4: { // 0x4c84f4: 7538 JNZ 0x4C852E
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  L004c84f6: { // 0x4c84f6: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L004c84f9: { // 0x4c84f9: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L004c84fc: { // 0x4c84fc: 7430 JZ 0x4C852E
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  L004c84fe: { // 0x4c84fe: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004c8500: { // 0x4c8500: 742c JZ 0x4C852E
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  L004c8502: { // 0x4c8502: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c8503: { // 0x4c8503: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c8504: { // 0x4c8504: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c8505: { // 0x4c8505: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L004c850a: { // 0x4c850a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c850b: { // 0x4c850b: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L004c850e: { // 0x4c850e: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004c8512: { // 0x4c8512: 8338ff CMP dword ptr [EAX], -1
    (void)integer::sub(m.r32((s.ax)),4294967295u,32,flags);
  }
  L004c8515: { // 0x4c8515: 7517 JNZ 0x4C852E
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  L004c8517: { // 0x4c8517: 8b8f40010000 MOV ECX, dword ptr [EDI + 0x140]
    s.cx = m.r32((s.di+0x00000140u));
  }
  L004c851d: { // 0x4c851d: f6c501 TEST CH, 1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(1u),8,flags);
  }
  L004c8520: { // 0x4c8520: 740c JZ 0x4C852E
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  L004c8522: { // 0x4c8522: 0fbe8f1b010000 MOVSX ECX, byte ptr [EDI + 0x11B]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L004c8529: { // 0x4c8529: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L004c852c: { // 0x4c852c: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L004c852e: { // 0x4c852e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c852f: { // 0x4c852f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c8530: { // 0x4c8530: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c8531: { // 0x4c8531: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004c8533: { // 0x4c8533: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c8534: { // 0x4c8534: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4361456u:f_00028cf0(m,s,child,{});break;
case 4693296u:f_00079d30(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5552176u:f_0014b830(m,s,child,{});break;
case 5024688u:f_000cabb0(m,s,child,{});break;
case 4369712u:f_0002ad30(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
case 4369744u:f_0002ad50(m,s,child,{});break;
case 5252688u:f_00102650(m,s,child,{});break;
case 5014320u:f_000c8330(m,s,child,{});break;
default:throw std::domain_error("recovery235 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00428ae0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00428ae0: { // 0x428ae0: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L00428ae3: { // 0x428ae3: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00428ae7: { // 0x428ae7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00428ae8: { // 0x428ae8: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00428aec: { // 0x428aec: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00428aed: { // 0x428aed: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00428af0: { // 0x428af0: 8b5014 MOV EDX,dword ptr [EAX + 0x14]
    s.dx = m.r32((s.ax+0x00000014u));
  }
  L00428af3: { // 0x428af3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00428af4: { // 0x428af4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00428af5: { // 0x428af5: 8b780c MOV EDI,dword ptr [EAX + 0xc]
    s.di = m.r32((s.ax+0x0000000cu));
  }
  L00428af8: { // 0x428af8: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00428afa: { // 0x428afa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00428afb: { // 0x428afb: 83cbff OR EBX,0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  L00428afe: { // 0x428afe: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00428b00: { // 0x428b00: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00428b02: { // 0x428b02: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00428b04: { // 0x428b04: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00428b08: { // 0x428b08: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L00428b0c: { // 0x428b0c: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L00428b10: { // 0x428b10: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00428b14: { // 0x428b14: c644244000 MOV byte ptr [ESP + 0x40],0x0
    m.w8((f.sp+0x00000040u), 0x00000000u);
  }
  L00428b19: { // 0x428b19: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00428b1d: { // 0x428b1d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00428b21: { // 0x428b21: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428b25: { // 0x428b25: 0f8eb0010000 JLE 0x00428cdb
    if(integer::condition("JLE",flags)) goto L00428cdb;
  }
  L00428b2b: { // 0x428b2b: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00428b2f: { // 0x428b2f: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00428b33: { // 0x428b33: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00428b35: { // 0x428b35: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00428b37: { // 0x428b37: 0f8d71010000 JGE 0x00428cae
    if(integer::condition("JGE",flags)) goto L00428cae;
  }
  L00428b3d: { // 0x428b3d: 8a542440 MOV DL,byte ptr [ESP + 0x40]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000040u)));
  }
  L00428b41: { // 0x428b41: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00428b43: { // 0x428b43: 0f85da000000 JNZ 0x00428c23
    if(integer::condition("JNZ",flags)) goto L00428c23;
  }
  L00428b49: { // 0x428b49: 8d142e LEA EDX,[ESI + EBP*0x1]
    s.dx = (s.si+(s.bp * 0x00000001u));
  }
  L00428b4c: { // 0x428b4c: 8b0497 MOV EAX,dword ptr [EDI + EDX*0x4]
    s.ax = m.r32((s.di+(s.dx * 0x00000004u)));
  }
  L00428b4f: { // 0x428b4f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00428b51: { // 0x428b51: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00428b53: { // 0x428b53: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L00428b56: { // 0x428b56: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00428b58: { // 0x428b58: 7503 JNZ 0x00428b5d
    if(integer::condition("JNZ",flags)) goto L00428b5d;
  }
  L00428b5a: { // 0x428b5a: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00428b5b: { // 0x428b5b: eb4a JMP 0x00428ba7
    goto L00428ba7;
  }
  L00428b5d: { // 0x428b5d: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00428b60: { // 0x428b60: 7405 JZ 0x00428b67
    if(integer::condition("JZ",flags)) goto L00428b67;
  }
  L00428b62: { // 0x428b62: 83f906 CMP ECX,0x6
    (void)integer::sub(s.cx,0x00000006u,32,flags);
  }
  L00428b65: { // 0x428b65: 7526 JNZ 0x00428b8d
    if(integer::condition("JNZ",flags)) goto L00428b8d;
  }
  L00428b67: { // 0x428b67: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L00428b6a: { // 0x428b6a: 7421 JZ 0x00428b8d
    if(integer::condition("JZ",flags)) goto L00428b8d;
  }
  L00428b6c: { // 0x428b6c: 83fb08 CMP EBX,0x8
    (void)integer::sub(s.bx,0x00000008u,32,flags);
  }
  L00428b6f: { // 0x428b6f: 741c JZ 0x00428b8d
    if(integer::condition("JZ",flags)) goto L00428b8d;
  }
  L00428b71: { // 0x428b71: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00428b74: { // 0x428b74: 7417 JZ 0x00428b8d
    if(integer::condition("JZ",flags)) goto L00428b8d;
  }
  L00428b76: { // 0x428b76: c644244001 MOV byte ptr [ESP + 0x40],0x1
    m.w8((f.sp+0x00000040u), 0x00000001u);
  }
  L00428b7b: { // 0x428b7b: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00428b7f: { // 0x428b7f: c744241401000000 MOV dword ptr [ESP + 0x14],0x1
    m.w32((f.sp+0x00000014u), 0x00000001u);
  }
  L00428b87: { // 0x428b87: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00428b8b: { // 0x428b8b: eb1a JMP 0x00428ba7
    goto L00428ba7;
  }
  L00428b8d: { // 0x428b8d: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00428b8f: { // 0x428b8f: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00428b91: { // 0x428b91: bd01000000 MOV EBP,0x1
    s.bp = 0x00000001u;
  }
  L00428b96: { // 0x428b96: 7404 JZ 0x00428b9c
    if(integer::condition("JZ",flags)) goto L00428b9c;
  }
  L00428b98: { // 0x428b98: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00428b9a: { // 0x428b9a: eb03 JMP 0x00428b9f
    goto L00428b9f;
  }
  L00428b9c: { // 0x428b9c: 83cbff OR EBX,0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  L00428b9f: { // 0x428b9f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00428ba3: { // 0x428ba3: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00428ba7: { // 0x428ba7: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00428baa: { // 0x428baa: 7549 JNZ 0x00428bf5
    if(integer::condition("JNZ",flags)) goto L00428bf5;
  }
  L00428bac: { // 0x428bac: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L00428bb0: { // 0x428bb0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00428bb5: { // 0x428bb5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00428bb6: { // 0x428bb6: e845c91100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4361147u); flags=s.arithmetic_flags;
  }
  L00428bbb: { // 0x428bbb: 0fbf8016010000 MOVSX EAX,word ptr [EAX + 0x116]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000116u)),16));
  }
  L00428bc2: { // 0x428bc2: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00428bc5: { // 0x428bc5: 7415 JZ 0x00428bdc
    if(integer::condition("JZ",flags)) goto L00428bdc;
  }
  L00428bc7: { // 0x428bc7: 8b0dfce48400 MOV ECX,dword ptr [0x0084e4fc]
    s.cx = m.r32((0x0084e4fcu));
  }
  L00428bcd: { // 0x428bcd: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00428bd0: { // 0x428bd0: 8b4228 MOV EAX,dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  L00428bd3: { // 0x428bd3: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428bd7: { // 0x428bd7: e9c3000000 JMP 0x00428c9f
    goto L00428c9f;
  }
  L00428bdc: { // 0x428bdc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00428bde: { // 0x428bde: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L00428be3: { // 0x428be3: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L00428be8: { // 0x428be8: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00428bec: { // 0x428bec: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428bf0: { // 0x428bf0: e9aa000000 JMP 0x00428c9f
    goto L00428c9f;
  }
  L00428bf5: { // 0x428bf5: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L00428bfd: { // 0x428bfd: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L00428c05: { // 0x428c05: 66034c2410 ADD CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  L00428c0a: { // 0x428c0a: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L00428c0f: { // 0x428c0f: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L00428c14: { // 0x428c14: 6689542426 MOV word ptr [ESP + 0x26],DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L00428c19: { // 0x428c19: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00428c1d: { // 0x428c1d: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428c21: { // 0x428c21: eb7c JMP 0x00428c9f
    goto L00428c9f;
  }
  L00428c23: { // 0x428c23: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00428c27: { // 0x428c27: 391487 CMP dword ptr [EDI + EAX*0x4],EDX
    (void)integer::sub(m.r32((s.di+(s.ax * 0x00000004u))),s.dx,32,flags);
  }
  L00428c2a: { // 0x428c2a: 7506 JNZ 0x00428c32
    if(integer::condition("JNZ",flags)) goto L00428c32;
  }
  L00428c2c: { // 0x428c2c: ff442414 INC dword ptr [ESP + 0x14]
    m.w32((f.sp+0x00000014u), integer::increment(m.r32((f.sp+0x00000014u)),32,flags));
  }
  L00428c30: { // 0x428c30: eb71 JMP 0x00428ca3
    goto L00428ca3;
  }
  L00428c32: { // 0x428c32: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00428c36: { // 0x428c36: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00428c3a: { // 0x428c3a: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00428c3e: { // 0x428c3e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00428c3f: { // 0x428c3f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00428c40: { // 0x428c40: 8d04b2 LEA EAX,[EDX + ESI*0x4]
    s.ax = (s.dx+(s.si * 0x00000004u));
  }
  L00428c43: { // 0x428c43: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00428c47: { // 0x428c47: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00428c48: { // 0x428c48: 8d0cb7 LEA ECX,[EDI + ESI*0x4]
    s.cx = (s.di+(s.si * 0x00000004u));
  }
  L00428c4b: { // 0x428c4b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00428c4c: { // 0x428c4c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00428c4d: { // 0x428c4d: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L00428c51: { // 0x428c51: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00428c52: { // 0x428c52: e899000000 CALL 0x00428cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428cf0u,4361303u); flags=s.arithmetic_flags;
  }
  L00428c57: { // 0x428c57: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00428c59: { // 0x428c59: 668b4c2418 MOV CX,word ptr [ESP + 0x18]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000018u)));
  }
  L00428c5e: { // 0x428c5e: bd01000000 MOV EBP,0x1
    s.bp = 0x00000001u;
  }
  L00428c63: { // 0x428c63: c644244000 MOV byte ptr [ESP + 0x40],0x0
    m.w8((f.sp+0x00000040u), 0x00000000u);
  }
  L00428c68: { // 0x428c68: 8b04b7 MOV EAX,dword ptr [EDI + ESI*0x4]
    s.ax = m.r32((s.di+(s.si * 0x00000004u)));
  }
  L00428c6b: { // 0x428c6b: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L00428c6e: { // 0x428c6e: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L00428c76: { // 0x428c76: 66030c85a09d8300 ADD CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.ax * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L00428c7e: { // 0x428c7e: 660354241a ADD DX,word ptr [ESP + 0x1a]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x0000001au)),16,flags));
  }
  L00428c83: { // 0x428c83: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00428c8a: { // 0x428c8a: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L00428c8f: { // 0x428c8f: 668954242e MOV word ptr [ESP + 0x2e],DX
    m.w16((f.sp+0x0000002eu), (s.dx & 0xffffu));
  }
  L00428c94: { // 0x428c94: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00428c98: { // 0x428c98: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428c9c: { // 0x428c9c: 8b1cb7 MOV EBX,dword ptr [EDI + ESI*0x4]
    s.bx = m.r32((s.di+(s.si * 0x00000004u)));
  }
  L00428c9f: { // 0x428c9f: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00428ca3: { // 0x428ca3: 8d142e LEA EDX,[ESI + EBP*0x1]
    s.dx = (s.si+(s.bp * 0x00000001u));
  }
  L00428ca6: { // 0x428ca6: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00428ca8: { // 0x428ca8: 0f8c7dfeffff JL 0x00428b2b
    if(integer::condition("JL",flags)) goto L00428b2b;
  }
  L00428cae: { // 0x428cae: 8a442440 MOV AL,byte ptr [ESP + 0x40]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000040u)));
  }
  L00428cb2: { // 0x428cb2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00428cb4: { // 0x428cb4: 7425 JZ 0x00428cdb
    if(integer::condition("JZ",flags)) goto L00428cdb;
  }
  L00428cb6: { // 0x428cb6: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00428cba: { // 0x428cba: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00428cbe: { // 0x428cbe: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00428cc2: { // 0x428cc2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00428cc3: { // 0x428cc3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00428cc4: { // 0x428cc4: 8d04b2 LEA EAX,[EDX + ESI*0x4]
    s.ax = (s.dx+(s.si * 0x00000004u));
  }
  L00428cc7: { // 0x428cc7: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L00428ccb: { // 0x428ccb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00428ccc: { // 0x428ccc: 8d0cb7 LEA ECX,[EDI + ESI*0x4]
    s.cx = (s.di+(s.si * 0x00000004u));
  }
  L00428ccf: { // 0x428ccf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00428cd0: { // 0x428cd0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00428cd1: { // 0x428cd1: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L00428cd5: { // 0x428cd5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00428cd6: { // 0x428cd6: e815000000 CALL 0x00428cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428cf0u,4361435u); flags=s.arithmetic_flags;
  }
  L00428cdb: { // 0x428cdb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00428cdc: { // 0x428cdc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00428cdd: { // 0x428cdd: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00428cde: { // 0x428cde: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00428cdf: { // 0x428cdf: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L00428ce2: { // 0x428ce2: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
