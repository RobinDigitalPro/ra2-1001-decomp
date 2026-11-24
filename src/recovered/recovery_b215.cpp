#include "recovered/recovery_b215_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b215 {
namespace {
void f_00163a20(Memory&,State&,Frame&,const Operations&);
void f_00167ea0(Memory&,State&,Frame&,const Operations&);
void f_0014d560(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_0014cf40(Memory&,State&,Frame&,const Operations&);
void f_0014cf80(Memory&,State&,Frame&,const Operations&);
void f_0007b560(Memory&,State&,Frame&,const Operations&);
void f_0007b580(Memory&,State&,Frame&,const Operations&);
void f_00167e60(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00163a20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00563a20: { // 0x563a20: 83ec4c SUB ESP,0x4c
    f.sp = integer::sub(f.sp,0x0000004cu,32,flags);
  }
  L00563a23: { // 0x563a23: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00563a27: { // 0x563a27: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00563a28: { // 0x563a28: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00563a29: { // 0x563a29: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00563a2a: { // 0x563a2a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00563a2c: { // 0x563a2c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00563a2d: { // 0x563a2d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00563a2f: { // 0x563a2f: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00563a32: { // 0x563a32: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00563a36: { // 0x563a36: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00563a3a: { // 0x563a3a: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00563a3f: { // 0x563a3f: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00563a42: { // 0x563a42: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00563a45: { // 0x563a45: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00563a47: { // 0x563a47: 7818 JS 0x00563a61
    if(integer::condition("JS",flags)) goto L00563a61;
  }
  L00563a49: { // 0x563a49: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00563a4e: { // 0x563a4e: 7d11 JGE 0x00563a61
    if(integer::condition("JGE",flags)) goto L00563a61;
  }
  L00563a50: { // 0x563a50: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00563a56: { // 0x563a56: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00563a59: { // 0x563a59: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00563a5b: { // 0x563a5b: 7404 JZ 0x00563a61
    if(integer::condition("JZ",flags)) goto L00563a61;
  }
  L00563a5d: { // 0x563a5d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00563a5f: { // 0x563a5f: eb0b JMP 0x00563a6c
    goto L00563a6c;
  }
  L00563a61: { // 0x563a61: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L00563a67: { // 0x563a67: bf1076a500 MOV EDI,0xa57610
    s.di = 0x00a57610u;
  }
  L00563a6c: { // 0x563a6c: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L00563a71: { // 0x563a71: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563a73: { // 0x563a73: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00563a77: { // 0x563a77: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00563a7b: { // 0x563a7b: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00563a7f: { // 0x563a7f: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00563a83: { // 0x563a83: e8d87af1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5651080u); flags=s.arithmetic_flags;
  }
  L00563a88: { // 0x563a88: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563a8a: { // 0x563a8a: 750f JNZ 0x00563a9b
    if(integer::condition("JNZ",flags)) goto L00563a9b;
  }
  L00563a8c: { // 0x563a8c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563a8e: { // 0x563a8e: e8ed7af1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5651091u); flags=s.arithmetic_flags;
  }
  L00563a93: { // 0x563a93: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563a95: { // 0x563a95: 0f8490000000 JZ 0x00563b2b
    if(integer::condition("JZ",flags)) goto L00563b2b;
  }
  L00563a9b: { // 0x563a9b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563a9d: { // 0x563a9d: e8be7af1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5651106u); flags=s.arithmetic_flags;
  }
  L00563aa2: { // 0x563aa2: 8b0db0a8a300 MOV ECX,dword ptr [0x00a3a8b0]
    s.cx = m.r32((0x00a3a8b0u));
  }
  L00563aa8: { // 0x563aa8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00563aaa: { // 0x563aaa: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L00563aad: { // 0x563aad: 7506 JNZ 0x00563ab5
    if(integer::condition("JNZ",flags)) goto L00563ab5;
  }
  L00563aaf: { // 0x563aaf: 8b0da047a500 MOV ECX,dword ptr [0x00a547a0]
    s.cx = m.r32((0x00a547a0u));
  }
  L00563ab5: { // 0x563ab5: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00563ab7: { // 0x563ab7: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L00563abb: { // 0x563abb: 8b3c852caf7c00 MOV EDI,dword ptr [EAX*0x4 + 0x7caf2c]
    s.di = m.r32(((s.ax * 0x00000004u)+0x007caf2cu));
  }
  L00563ac2: { // 0x563ac2: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00563ac4: { // 0x563ac4: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L00563ac7: { // 0x563ac7: 8d1c85a09d8300 LEA EBX,[EAX*0x4 + 0x839da0]
    s.bx = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00563ace: { // 0x563ace: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00563acf: { // 0x563acf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563ad0: { // 0x563ad0: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00563ad4: { // 0x563ad4: e8f772ecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5651161u); flags=s.arithmetic_flags;
  }
  L00563ad9: { // 0x563ad9: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563adb: { // 0x563adb: 83c7fc ADD EDI,-0x4
    s.di = integer::add(s.di,0xfffffffcu,32,flags);
  }
  L00563ade: { // 0x563ade: 83e707 AND EDI,0x7
    s.di = integer::logical((s.di)&(0x00000007u),32,flags);
  }
  L00563ae1: { // 0x563ae1: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L00563ae5: { // 0x563ae5: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00563ae9: { // 0x563ae9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00563aed: { // 0x563aed: 8d3cbda09d8300 LEA EDI,[EDI*0x4 + 0x839da0]
    s.di = ((s.di * 0x00000004u)+0x00839da0u);
  }
  L00563af4: { // 0x563af4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00563af5: { // 0x563af5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563af6: { // 0x563af6: e8d572ecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5651195u); flags=s.arithmetic_flags;
  }
  L00563afb: { // 0x563afb: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563afd: { // 0x563afd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00563afe: { // 0x563afe: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00563b02: { // 0x563b02: 8d442464 LEA EAX,[ESP + 0x64]
    s.ax = (f.sp+0x00000064u);
  }
  L00563b06: { // 0x563b06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563b07: { // 0x563b07: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00563b0b: { // 0x563b0b: e8c072ecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5651216u); flags=s.arithmetic_flags;
  }
  L00563b10: { // 0x563b10: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563b12: { // 0x563b12: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L00563b16: { // 0x563b16: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00563b17: { // 0x563b17: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563b18: { // 0x563b18: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00563b1c: { // 0x563b1c: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00563b20: { // 0x563b20: e8ab72ecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5651237u); flags=s.arithmetic_flags;
  }
  L00563b25: { // 0x563b25: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L00563b27: { // 0x563b27: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00563b2b: { // 0x563b2b: 8d968c000000 LEA EDX,[ESI + 0x8c]
    s.dx = (s.si+0x0000008cu);
  }
  L00563b31: { // 0x563b31: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00563b33: { // 0x563b33: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00563b37: { // 0x563b37: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00563b3b: { // 0x563b3b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563b3d: { // 0x563b3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563b3e: { // 0x563b3e: e8fd93feff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5651267u); flags=s.arithmetic_flags;
  }
  L00563b43: { // 0x563b43: 8b566c MOV EDX,dword ptr [ESI + 0x6c]
    s.dx = m.r32((s.si+0x0000006cu));
  }
  L00563b46: { // 0x563b46: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L00563b49: { // 0x563b49: 8d044a LEA EAX,[EDX + ECX*0x2]
    s.ax = (s.dx+(s.cx * 0x00000002u));
  }
  L00563b4c: { // 0x563b4c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563b4e: { // 0x563b4e: 0fbf3c58 MOVSX EDI,word ptr [EAX + EBX*0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bx * 0x00000002u))),16));
  }
  L00563b52: { // 0x563b52: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00563b56: { // 0x563b56: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563b57: { // 0x563b57: e8e493feff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5651292u); flags=s.arithmetic_flags;
  }
  L00563b5c: { // 0x563b5c: 8b566c MOV EDX,dword ptr [ESI + 0x6c]
    s.dx = m.r32((s.si+0x0000006cu));
  }
  L00563b5f: { // 0x563b5f: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L00563b62: { // 0x563b62: c644243000 MOV byte ptr [ESP + 0x30],0x0
    m.w8((f.sp+0x00000030u), 0x00000000u);
  }
  L00563b67: { // 0x563b67: 8d044a LEA EAX,[EDX + ECX*0x2]
    s.ax = (s.dx+(s.cx * 0x00000002u));
  }
  L00563b6a: { // 0x563b6a: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00563b6e: { // 0x563b6e: 0fbf0458 MOVSX EAX,word ptr [EAX + EBX*0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bx * 0x00000002u))),16));
  }
  L00563b72: { // 0x563b72: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00563b74: { // 0x563b74: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00563b78: { // 0x563b78: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00563b7c: { // 0x563b7c: 8d04ff LEA EAX,[EDI + EDI*0x8]
    s.ax = (s.di+(s.di * 0x00000008u));
  }
  L00563b7f: { // 0x563b7f: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00563b83: { // 0x563b83: 8d2c82 LEA EBP,[EDX + EAX*0x4]
    s.bp = (s.dx+(s.ax * 0x00000004u));
  }
  L00563b86: { // 0x563b86: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563b87: { // 0x563b87: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00563b89: { // 0x563b89: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00563b8c: { // 0x563b8c: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),5651343u); flags=s.arithmetic_flags;
  }
  L00563b8f: { // 0x563b8f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00563b92: { // 0x563b92: 7408 JZ 0x00563b9c
    if(integer::condition("JZ",flags)) goto L00563b9c;
  }
  L00563b94: { // 0x563b94: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563b95: { // 0x563b95: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00563b97: { // 0x563b97: e8c4420000 CALL 0x00567e60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00567e60u,5651356u); flags=s.arithmetic_flags;
  }
  L00563b9c: { // 0x563b9c: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00563ba0: { // 0x563ba0: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L00563ba4: { // 0x563ba4: 897c2434 MOV dword ptr [ESP + 0x34],EDI
    m.w32((f.sp+0x00000034u), s.di);
  }
  L00563ba8: { // 0x563ba8: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L00563bad: { // 0x563bad: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L00563bb0: { // 0x563bb0: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00563bb3: { // 0x563bb3: 8d3c90 LEA EDI,[EAX + EDX*0x4]
    s.di = (s.ax+(s.dx * 0x00000004u));
  }
  L00563bb6: { // 0x563bb6: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L00563bba: { // 0x563bba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563bbb: { // 0x563bbb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563bbd: { // 0x563bbd: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00563bbf: { // 0x563bbf: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5651394u); flags=s.arithmetic_flags;
  }
  L00563bc2: { // 0x563bc2: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00563bc5: { // 0x563bc5: 7408 JZ 0x00563bcf
    if(integer::condition("JZ",flags)) goto L00563bcf;
  }
  L00563bc7: { // 0x563bc7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563bc8: { // 0x563bc8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563bca: { // 0x563bca: e891420000 CALL 0x00567e60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00567e60u,5651407u); flags=s.arithmetic_flags;
  }
  L00563bcf: { // 0x563bcf: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00563bd3: { // 0x563bd3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563bd4: { // 0x563bd4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563bd6: { // 0x563bd6: e86593feff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5651419u); flags=s.arithmetic_flags;
  }
  L00563bdb: { // 0x563bdb: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L00563bde: { // 0x563bde: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00563be1: { // 0x563be1: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00563be5: { // 0x563be5: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00563be8: { // 0x563be8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563be9: { // 0x563be9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563beb: { // 0x563beb: 0fbf3c58 MOVSX EDI,word ptr [EAX + EBX*0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bx * 0x00000002u))),16));
  }
  L00563bef: { // 0x563bef: e84c93feff CALL 0x0054cf40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf40u,5651444u); flags=s.arithmetic_flags;
  }
  L00563bf4: { // 0x563bf4: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L00563bf7: { // 0x563bf7: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00563bfa: { // 0x563bfa: 8d0cff LEA ECX,[EDI + EDI*0x8]
    s.cx = (s.di+(s.di * 0x00000008u));
  }
  L00563bfd: { // 0x563bfd: c644244000 MOV byte ptr [ESP + 0x40],0x0
    m.w8((f.sp+0x00000040u), 0x00000000u);
  }
  L00563c02: { // 0x563c02: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00563c05: { // 0x563c05: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00563c08: { // 0x563c08: 0fbf0458 MOVSX EAX,word ptr [EAX + EBX*0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+(s.bx * 0x00000002u))),16));
  }
  L00563c0c: { // 0x563c0c: 8d2c8a LEA EBP,[EDX + ECX*0x4]
    s.bp = (s.dx+(s.cx * 0x00000004u));
  }
  L00563c0f: { // 0x563c0f: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00563c13: { // 0x563c13: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00563c17: { // 0x563c17: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00563c1b: { // 0x563c1b: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00563c1e: { // 0x563c1e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563c1f: { // 0x563c1f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00563c21: { // 0x563c21: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),5651492u); flags=s.arithmetic_flags;
  }
  L00563c24: { // 0x563c24: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00563c27: { // 0x563c27: 7408 JZ 0x00563c31
    if(integer::condition("JZ",flags)) goto L00563c31;
  }
  L00563c29: { // 0x563c29: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563c2a: { // 0x563c2a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00563c2c: { // 0x563c2c: e82f420000 CALL 0x00567e60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00567e60u,5651505u); flags=s.arithmetic_flags;
  }
  L00563c31: { // 0x563c31: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00563c35: { // 0x563c35: 897c2444 MOV dword ptr [ESP + 0x44],EDI
    m.w32((f.sp+0x00000044u), s.di);
  }
  L00563c39: { // 0x563c39: c644244800 MOV byte ptr [ESP + 0x48],0x0
    m.w8((f.sp+0x00000048u), 0x00000000u);
  }
  L00563c3e: { // 0x563c3e: 8d14c0 LEA EDX,[EAX + EAX*0x8]
    s.dx = (s.ax+(s.ax * 0x00000008u));
  }
  L00563c41: { // 0x563c41: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L00563c45: { // 0x563c45: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00563c47: { // 0x563c47: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00563c4b: { // 0x563c4b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563c4c: { // 0x563c4c: 8d2c91 LEA EBP,[ECX + EDX*0x4]
    s.bp = (s.cx+(s.dx * 0x00000004u));
  }
  L00563c4f: { // 0x563c4f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00563c51: { // 0x563c51: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00563c54: { // 0x563c54: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5651543u); flags=s.arithmetic_flags;
  }
  L00563c57: { // 0x563c57: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00563c5a: { // 0x563c5a: 7408 JZ 0x00563c64
    if(integer::condition("JZ",flags)) goto L00563c64;
  }
  L00563c5c: { // 0x563c5c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563c5d: { // 0x563c5d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00563c5f: { // 0x563c5f: e8fc410000 CALL 0x00567e60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00567e60u,5651556u); flags=s.arithmetic_flags;
  }
  L00563c64: { // 0x563c64: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00563c68: { // 0x563c68: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563c69: { // 0x563c69: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563c6b: { // 0x563c6b: e81093feff CALL 0x0054cf80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf80u,5651568u); flags=s.arithmetic_flags;
  }
  L00563c70: { // 0x563c70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00563c72: { // 0x563c72: 7d04 JGE 0x00563c78
    if(integer::condition("JGE",flags)) goto L00563c78;
  }
  L00563c74: { // 0x563c74: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00563c76: { // 0x563c76: eb0a JMP 0x00563c82
    goto L00563c82;
  }
  L00563c78: { // 0x563c78: 8b4e68 MOV ECX,dword ptr [ESI + 0x68]
    s.cx = m.r32((s.si+0x00000068u));
  }
  L00563c7b: { // 0x563c7b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563c7d: { // 0x563c7d: 7c03 JL 0x00563c82
    if(integer::condition("JL",flags)) goto L00563c82;
  }
  L00563c7f: { // 0x563c7f: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L00563c82: { // 0x563c82: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  L00563c85: { // 0x563c85: 8d1483 LEA EDX,[EBX + EAX*0x4]
    s.dx = (s.bx+(s.ax * 0x00000004u));
  }
  L00563c88: { // 0x563c88: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00563c8a: { // 0x563c8a: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L00563c8e: { // 0x563c8e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00563c8f: { // 0x563c8f: 0fbf3c41 MOVSX EDI,word ptr [ECX + EAX*0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+(s.ax * 0x00000002u))),16));
  }
  L00563c93: { // 0x563c93: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00563c95: { // 0x563c95: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L00563c99: { // 0x563c99: e8e292feff CALL 0x0054cf80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cf80u,5651614u); flags=s.arithmetic_flags;
  }
  L00563c9e: { // 0x563c9e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00563ca0: { // 0x563ca0: 7d04 JGE 0x00563ca6
    if(integer::condition("JGE",flags)) goto L00563ca6;
  }
  L00563ca2: { // 0x563ca2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00563ca4: { // 0x563ca4: eb0a JMP 0x00563cb0
    goto L00563cb0;
  }
  L00563ca6: { // 0x563ca6: 8b4e68 MOV ECX,dword ptr [ESI + 0x68]
    s.cx = m.r32((s.si+0x00000068u));
  }
  L00563ca9: { // 0x563ca9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563cab: { // 0x563cab: 7c03 JL 0x00563cb0
    if(integer::condition("JL",flags)) goto L00563cb0;
  }
  L00563cad: { // 0x563cad: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L00563cb0: { // 0x563cb0: 8b566c MOV EDX,dword ptr [ESI + 0x6c]
    s.dx = m.r32((s.si+0x0000006cu));
  }
  L00563cb3: { // 0x563cb3: 8d0c83 LEA ECX,[EBX + EAX*0x4]
    s.cx = (s.bx+(s.ax * 0x00000004u));
  }
  L00563cb6: { // 0x563cb6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00563cb8: { // 0x563cb8: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00563cbc: { // 0x563cbc: c644245000 MOV byte ptr [ESP + 0x50],0x0
    m.w8((f.sp+0x00000050u), 0x00000000u);
  }
  L00563cc1: { // 0x563cc1: 0fbf2c42 MOVSX EBP,word ptr [EDX + EAX*0x2]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.dx+(s.ax * 0x00000002u))),16));
  }
  L00563cc5: { // 0x563cc5: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00563cc7: { // 0x563cc7: 8d04ff LEA EAX,[EDI + EDI*0x8]
    s.ax = (s.di+(s.di * 0x00000008u));
  }
  L00563cca: { // 0x563cca: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L00563cce: { // 0x563cce: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00563cd2: { // 0x563cd2: 8d3c82 LEA EDI,[EDX + EAX*0x4]
    s.di = (s.dx+(s.ax * 0x00000004u));
  }
  L00563cd5: { // 0x563cd5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00563cd6: { // 0x563cd6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563cd8: { // 0x563cd8: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00563cda: { // 0x563cda: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),5651677u); flags=s.arithmetic_flags;
  }
  L00563cdd: { // 0x563cdd: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00563ce0: { // 0x563ce0: 7429 JZ 0x00563d0b
    if(integer::condition("JZ",flags)) goto L00563d0b;
  }
  L00563ce2: { // 0x563ce2: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L00563ce5: { // 0x563ce5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563ce7: { // 0x563ce7: 7d22 JGE 0x00563d0b
    if(integer::condition("JGE",flags)) goto L00563d0b;
  }
  L00563ce9: { // 0x563ce9: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00563cea: { // 0x563cea: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563cec: { // 0x563cec: 894f10 MOV dword ptr [EDI + 0x10],ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L00563cef: { // 0x563cef: 7d1a JGE 0x00563d0b
    if(integer::condition("JGE",flags)) goto L00563d0b;
  }
  L00563cf1: { // 0x563cf1: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00563cf4: { // 0x563cf4: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00563cf5: { // 0x563cf5: 8b14c1 MOV EDX,dword ptr [ECX + EAX*0x8]
    s.dx = m.r32((s.cx+(s.ax * 0x00000008u)));
  }
  L00563cf8: { // 0x563cf8: 8954c1f8 MOV dword ptr [ECX + EAX*0x8 + -0x8],EDX
    m.w32((s.cx+(s.ax * 0x00000008u)-0x00000008u), s.dx);
  }
  L00563cfc: { // 0x563cfc: 8b54c104 MOV EDX,dword ptr [ECX + EAX*0x8 + 0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000008u)+0x00000004u));
  }
  L00563d00: { // 0x563d00: 8954c1fc MOV dword ptr [ECX + EAX*0x8 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000008u)-0x00000004u), s.dx);
  }
  L00563d04: { // 0x563d04: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L00563d07: { // 0x563d07: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563d09: { // 0x563d09: 7ce6 JL 0x00563cf1
    if(integer::condition("JL",flags)) goto L00563cf1;
  }
  L00563d0b: { // 0x563d0b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00563d0f: { // 0x563d0f: 8b542460 MOV EDX,dword ptr [ESP + 0x60]
    s.dx = m.r32((f.sp+0x00000060u));
  }
  L00563d13: { // 0x563d13: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00563d17: { // 0x563d17: 8d4ced00 LEA ECX,[EBP + EBP*0x8]
    s.cx = (s.bp+(s.bp * 0x00000008u));
  }
  L00563d1b: { // 0x563d1b: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00563d1d: { // 0x563d1d: c644245800 MOV byte ptr [ESP + 0x58],0x0
    m.w8((f.sp+0x00000058u), 0x00000000u);
  }
  L00563d22: { // 0x563d22: 8b1488 MOV EDX,dword ptr [EAX + ECX*0x4]
    s.dx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00563d25: { // 0x563d25: 8d3c88 LEA EDI,[EAX + ECX*0x4]
    s.di = (s.ax+(s.cx * 0x00000004u));
  }
  L00563d28: { // 0x563d28: 8d442454 LEA EAX,[ESP + 0x54]
    s.ax = (f.sp+0x00000054u);
  }
  L00563d2c: { // 0x563d2c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00563d2d: { // 0x563d2d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00563d2f: { // 0x563d2f: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5651762u); flags=s.arithmetic_flags;
  }
  L00563d32: { // 0x563d32: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00563d35: { // 0x563d35: 7429 JZ 0x00563d60
    if(integer::condition("JZ",flags)) goto L00563d60;
  }
  L00563d37: { // 0x563d37: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L00563d3a: { // 0x563d3a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563d3c: { // 0x563d3c: 7d22 JGE 0x00563d60
    if(integer::condition("JGE",flags)) goto L00563d60;
  }
  L00563d3e: { // 0x563d3e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00563d3f: { // 0x563d3f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563d41: { // 0x563d41: 894f10 MOV dword ptr [EDI + 0x10],ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L00563d44: { // 0x563d44: 7d1a JGE 0x00563d60
    if(integer::condition("JGE",flags)) goto L00563d60;
  }
  L00563d46: { // 0x563d46: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00563d49: { // 0x563d49: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00563d4a: { // 0x563d4a: 8b14c1 MOV EDX,dword ptr [ECX + EAX*0x8]
    s.dx = m.r32((s.cx+(s.ax * 0x00000008u)));
  }
  L00563d4d: { // 0x563d4d: 8954c1f8 MOV dword ptr [ECX + EAX*0x8 + -0x8],EDX
    m.w32((s.cx+(s.ax * 0x00000008u)-0x00000008u), s.dx);
  }
  L00563d51: { // 0x563d51: 8b54c104 MOV EDX,dword ptr [ECX + EAX*0x8 + 0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000008u)+0x00000004u));
  }
  L00563d55: { // 0x563d55: 8954c1fc MOV dword ptr [ECX + EAX*0x8 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000008u)-0x00000004u), s.dx);
  }
  L00563d59: { // 0x563d59: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L00563d5c: { // 0x563d5c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00563d5e: { // 0x563d5e: 7ce6 JL 0x00563d46
    if(integer::condition("JL",flags)) goto L00563d46;
  }
  L00563d60: { // 0x563d60: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00563d64: { // 0x563d64: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00563d65: { // 0x563d65: 83c118 ADD ECX,0x18
    s.cx = integer::add(s.cx,0x00000018u,32,flags);
  }
  L00563d68: { // 0x563d68: 83fb03 CMP EBX,0x3
    (void)integer::sub(s.bx,0x00000003u,32,flags);
  }
  L00563d6b: { // 0x563d6b: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L00563d6f: { // 0x563d6f: 0f8cc2fdffff JL 0x00563b37
    if(integer::condition("JL",flags)) goto L00563b37;
  }
  L00563d75: { // 0x563d75: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00563d76: { // 0x563d76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00563d77: { // 0x563d77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00563d78: { // 0x563d78: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00563d79: { // 0x563d79: 83c44c ADD ESP,0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L00563d7c: { // 0x563d7c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00167ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00567ea0: { // 0x567ea0: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L00567ea3: { // 0x567ea3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00567ea5: { // 0x567ea5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00567ea6: { // 0x567ea6: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00567ea8: { // 0x567ea8: 7e15 JLE 0x567ebf
    if(integer::condition("JLE",flags)) goto L00567ebf;
  }
  L00567eaa: { // 0x567eaa: 8b742408 MOV ESI, dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00567eae: { // 0x567eae: 8b4904 MOV ECX, dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00567eb1: { // 0x567eb1: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L00567eb3: { // 0x567eb3: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L00567eb5: { // 0x567eb5: 740b JZ 0x567ec2
    if(integer::condition("JZ",flags)) goto L00567ec2;
  }
  L00567eb7: { // 0x567eb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00567eb8: { // 0x567eb8: 83c108 ADD ECX, 0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L00567ebb: { // 0x567ebb: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00567ebd: { // 0x567ebd: 7cf4 JL 0x567eb3
    if(integer::condition("JL",flags)) goto L00567eb3;
  }
  L00567ebf: { // 0x567ebf: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00567ec2: { // 0x567ec2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00567ec3: { // 0x567ec3: c20400 RET 0x4
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
void f_0014cf80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cf80: { // 0x54cf80: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L0054cf86: { // 0x54cf86: 8b89f0000000 MOV ECX,dword ptr [ECX + 0xf0]
    s.cx = m.r32((s.cx+0x000000f0u));
  }
  L0054cf8c: { // 0x54cf8c: 8d440801 LEA EAX,[EAX + ECX*0x1 + 0x1]
    s.ax = (s.ax+(s.cx * 0x00000001u)+0x00000001u);
  }
  L0054cf90: { // 0x54cf90: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0054cf94: { // 0x54cf94: 0fbf5102 MOVSX EDX,word ptr [ECX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0054cf98: { // 0x54cf98: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0054cf9b: { // 0x54cf9b: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L0054cf9e: { // 0x54cf9e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054cfa0: { // 0x54cfa0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
void f_00167e60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00567e60: { // 0x567e60: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L00567e63: { // 0x567e63: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00567e67: { // 0x567e67: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00567e69: { // 0x567e69: 7d29 JGE 0x00567e94
    if(integer::condition("JGE",flags)) goto L00567e94;
  }
  L00567e6b: { // 0x567e6b: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00567e6c: { // 0x567e6c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00567e6e: { // 0x567e6e: 895110 MOV dword ptr [ECX + 0x10],EDX
    m.w32((s.cx+0x00000010u), s.dx);
  }
  L00567e71: { // 0x567e71: 7d1c JGE 0x00567e8f
    if(integer::condition("JGE",flags)) goto L00567e8f;
  }
  L00567e73: { // 0x567e73: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00567e74: { // 0x567e74: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00567e77: { // 0x567e77: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00567e78: { // 0x567e78: 8b34c2 MOV ESI,dword ptr [EDX + EAX*0x8]
    s.si = m.r32((s.dx+(s.ax * 0x00000008u)));
  }
  L00567e7b: { // 0x567e7b: 8974c2f8 MOV dword ptr [EDX + EAX*0x8 + -0x8],ESI
    m.w32((s.dx+(s.ax * 0x00000008u)-0x00000008u), s.si);
  }
  L00567e7f: { // 0x567e7f: 8b74c204 MOV ESI,dword ptr [EDX + EAX*0x8 + 0x4]
    s.si = m.r32((s.dx+(s.ax * 0x00000008u)+0x00000004u));
  }
  L00567e83: { // 0x567e83: 8974c2fc MOV dword ptr [EDX + EAX*0x8 + -0x4],ESI
    m.w32((s.dx+(s.ax * 0x00000008u)-0x00000004u), s.si);
  }
  L00567e87: { // 0x567e87: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L00567e8a: { // 0x567e8a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00567e8c: { // 0x567e8c: 7ce6 JL 0x00567e74
    if(integer::condition("JL",flags)) goto L00567e74;
  }
  L00567e8e: { // 0x567e8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00567e8f: { // 0x567e8f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00567e91: { // 0x567e91: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00567e94: { // 0x567e94: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00567e96: { // 0x567e96: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5650976u:f_00163a20(m,s,child,{});break;
case 5668512u:f_00167ea0(m,s,child,{});break;
case 5559648u:f_0014d560(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
case 5558080u:f_0014cf40(m,s,child,{});break;
case 5558144u:f_0014cf80(m,s,child,{});break;
case 4699488u:f_0007b560(m,s,child,{});break;
case 4699520u:f_0007b580(m,s,child,{});break;
case 5668448u:f_00167e60(m,s,child,{});break;
default:throw std::domain_error("recovery215 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0054d630(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054d630: { // 0x54d630: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d631: { // 0x54d631: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L0054d635: { // 0x54d635: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054d636: { // 0x54d636: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054d637: { // 0x54d637: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d639: { // 0x54d639: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0054d63b: { // 0x54d63b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0054d63d: { // 0x54d63d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d63e: { // 0x54d63e: e81dffffff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5559875u); flags=s.arithmetic_flags;
  }
  L0054d643: { // 0x54d643: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054d645: { // 0x54d645: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0054d648: { // 0x54d648: 7522 JNZ 0x0054d66c
    if(integer::condition("JNZ",flags)) goto L0054d66c;
  }
  L0054d64a: { // 0x54d64a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d64c: { // 0x54d64c: e8dffbffff CALL 0x0054d230
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d230u,5559889u); flags=s.arithmetic_flags;
  }
  L0054d651: { // 0x54d651: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054d653: { // 0x54d653: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0054d655: { // 0x54d655: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d656: { // 0x54d656: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d658: { // 0x54d658: e803ffffff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5559901u); flags=s.arithmetic_flags;
  }
  L0054d65d: { // 0x54d65d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054d65f: { // 0x54d65f: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0054d662: { // 0x54d662: 7508 JNZ 0x0054d66c
    if(integer::condition("JNZ",flags)) goto L0054d66c;
  }
  L0054d664: { // 0x54d664: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d665: { // 0x54d665: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d666: { // 0x54d666: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054d668: { // 0x54d668: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d669: { // 0x54d669: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0054d66c: { // 0x54d66c: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0054d66f: { // 0x54d66f: c644241000 MOV byte ptr [ESP + 0x10],0x0
    m.w8((f.sp+0x00000010u), 0x00000000u);
  }
  L0054d674: { // 0x54d674: 743b JZ 0x0054d6b1
    if(integer::condition("JZ",flags)) goto L0054d6b1;
  }
  L0054d676: { // 0x54d676: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054d677: { // 0x54d677: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  L0054d67a: { // 0x54d67a: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L0054d67c: { // 0x54d67c: c1e504 SHL EBP,0x4
    s.bp = integer::shift(s.bp,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054d67f: { // 0x54d67f: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0054d681: { // 0x54d681: 8a4808 MOV CL,byte ptr [EAX + 0x8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000008u)));
  }
  L0054d684: { // 0x54d684: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054d686: { // 0x54d686: 7415 JZ 0x0054d69d
    if(integer::condition("JZ",flags)) goto L0054d69d;
  }
  L0054d688: { // 0x54d688: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054d689: { // 0x54d689: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d68b: { // 0x54d68b: e890630100 CALL 0x00563a20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00563a20u,5559952u); flags=s.arithmetic_flags;
  }
  L0054d690: { // 0x54d690: 8b4e50 MOV ECX,dword ptr [ESI + 0x50]
    s.cx = m.r32((s.si+0x00000050u));
  }
  L0054d693: { // 0x54d693: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  L0054d698: { // 0x54d698: c644290800 MOV byte ptr [ECX + EBP*0x1 + 0x8],0x0
    m.w8((s.cx+(s.bp * 0x00000001u)+0x00000008u), 0x00000000u);
  }
  L0054d69d: { // 0x54d69d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0054d69e: { // 0x54d69e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d6a0: { // 0x54d6a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054d6a1: { // 0x54d6a1: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0054d6a3: { // 0x54d6a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d6a4: { // 0x54d6a4: e8b7feffff CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5559977u); flags=s.arithmetic_flags;
  }
  L0054d6a9: { // 0x54d6a9: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054d6ab: { // 0x54d6ab: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L0054d6ae: { // 0x54d6ae: 75c7 JNZ 0x0054d677
    if(integer::condition("JNZ",flags)) goto L0054d677;
  }
  L0054d6b0: { // 0x54d6b0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054d6b1: { // 0x54d6b1: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  L0054d6b5: { // 0x54d6b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054d6b6: { // 0x54d6b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054d6b7: { // 0x54d6b7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054d6b8: { // 0x54d6b8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
