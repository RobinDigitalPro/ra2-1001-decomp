#include "recovered/recovery_b1531_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1531 {
namespace {
void f_0004d930(Memory&,State&,Frame&,const Operations&);
void f_0004df50(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void f_001cd4d0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0004d930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d930: { // 0x44d930: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L0044d935: { // 0x44d935: 83ec20 SUB ESP, 0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0044d938: { // 0x44d938: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044d93a: { // 0x44d93a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d93b: { // 0x44d93b: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0044d93d: { // 0x44d93d: 0f8550010000 JNZ 0x44da93
    if(integer::condition("JNZ",flags)) goto L0044da93;
  }
  L0044d943: { // 0x44d943: 8b8318040000 MOV EAX, dword ptr [EBX + 0x418]
    s.ax = m.r32((s.bx+0x00000418u));
  }
  L0044d949: { // 0x44d949: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044d94f: { // 0x44d94f: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d951: { // 0x44d951: 0f843c010000 JZ 0x44da93
    if(integer::condition("JZ",flags)) goto L0044da93;
  }
  L0044d957: { // 0x44d957: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0044d95b: { // 0x44d95b: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0044d960: { // 0x44d960: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0044d962: { // 0x44d962: c644240c00 MOV byte ptr [ESP + 0xc], 0
    m.w8((f.sp+0x0000000cu), 0u);
  }
  L0044d967: { // 0x44d967: 7504 JNZ 0x44d96d
    if(integer::condition("JNZ",flags)) goto L0044d96d;
  }
  L0044d969: { // 0x44d969: 8844240c MOV byte ptr [ESP + 0xc], AL
    m.w8((f.sp+0x0000000cu), (s.ax & 0xffu));
  }
  L0044d96d: { // 0x44d96d: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0044d96f: { // 0x44d96f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d970: { // 0x44d970: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d971: { // 0x44d971: 8d442420 LEA EAX, [ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0044d975: { // 0x44d975: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d976: { // 0x44d976: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044d977: { // 0x44d977: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044d979: { // 0x44d979: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0044d97b: { // 0x44d97b: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4512126u); flags=s.arithmetic_flags;
  }
  L0044d97e: { // 0x44d97e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044d980: { // 0x44d980: c7442410d8a57b00 MOV dword ptr [ESP + 0x10], 0x7ba5d8
    m.w32((f.sp+0x00000010u), 0x007ba5d8u);
  }
  L0044d988: { // 0x44d988: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0044d98a: { // 0x44d98a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044d98b: { // 0x44d98b: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044d991: { // 0x44d991: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044d993: { // 0x44d993: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0044d995: { // 0x44d995: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0044d998: { // 0x44d998: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044d999: { // 0x44d999: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044d99f: { // 0x44d99f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044d9a1: { // 0x44d9a1: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044d9a3: { // 0x44d9a3: c1ff08 SAR EDI, 8
    s.di = integer::shift(s.di,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044d9a6: { // 0x44d9a6: c1f908 SAR ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044d9a9: { // 0x44d9a9: 66897c2434 MOV word ptr [ESP + 0x34], DI
    m.w16((f.sp+0x00000034u), (s.di & 0xffffu));
  }
  L0044d9ae: { // 0x44d9ae: 66894c2436 MOV word ptr [ESP + 0x36], CX
    m.w16((f.sp+0x00000036u), (s.cx & 0xffffu));
  }
  L0044d9b3: { // 0x44d9b3: eb0a JMP 0x44d9bf
    goto L0044d9bf;
  }
  L0044d9b5: { // 0x44d9b5: 668b7c2434 MOV DI, word ptr [ESP + 0x34]
    s.di = (s.di & 0xffff0000u) | ((m.r16((f.sp+0x00000034u))) & 0xffffu);
  }
  L0044d9ba: { // 0x44d9ba: 668b4c2436 MOV CX, word ptr [ESP + 0x36]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000036u)));
  }
  L0044d9bf: { // 0x44d9bf: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L0044d9c1: { // 0x44d9c1: 83e207 AND EDX, 7
    s.dx = integer::logical((s.dx)&(7u),32,flags);
  }
  L0044d9c4: { // 0x44d9c4: 8d0495a09d8300 LEA EAX, [EDX*4 + 0x839da0]
    s.ax = ((s.dx * 4u)+0x00839da0u);
  }
  L0044d9cb: { // 0x44d9cb: 668b1495a09d8300 MOV DX, word ptr [EDX*4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 4u)+0x00839da0u)));
  }
  L0044d9d3: { // 0x44d9d3: 668b4002 MOV AX, word ptr [EAX + 2]
    s.ax = with_ax(s.ax, m.r16((s.ax+2u)));
  }
  L0044d9d7: { // 0x44d9d7: 6603d7 ADD DX, DI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L0044d9da: { // 0x44d9da: 6603c1 ADD AX, CX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L0044d9dd: { // 0x44d9dd: 6689542414 MOV word ptr [ESP + 0x14], DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L0044d9e2: { // 0x44d9e2: 6689442416 MOV word ptr [ESP + 0x16], AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0044d9e7: { // 0x44d9e7: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0044d9eb: { // 0x44d9eb: 8d54241c LEA EDX, [ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0044d9ef: { // 0x44d9ef: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0044d9f3: { // 0x44d9f3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0044d9f4: { // 0x44d9f4: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044d9f9: { // 0x44d9f9: e8027b0f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4512254u); flags=s.arithmetic_flags;
  }
  L0044d9fe: { // 0x44d9fe: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044da00: { // 0x44da00: e8ab390200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4512261u); flags=s.arithmetic_flags;
  }
  L0044da05: { // 0x44da05: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0044da07: { // 0x44da07: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0044da09: { // 0x44da09: 7469 JZ 0x44da74
    if(integer::condition("JZ",flags)) goto L0044da74;
  }
  L0044da0b: { // 0x44da0b: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044da11: { // 0x44da11: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0044da17: { // 0x44da17: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044da19: { // 0x44da19: 7459 JZ 0x44da74
    if(integer::condition("JZ",flags)) goto L0044da74;
  }
  L0044da1b: { // 0x44da1b: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044da1d: { // 0x44da1d: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044da1f: { // 0x44da1f: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4512290u); flags=s.arithmetic_flags;
  }
  L0044da22: { // 0x44da22: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0044da24: { // 0x44da24: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044da26: { // 0x44da26: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044da28: { // 0x44da28: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4512299u); flags=s.arithmetic_flags;
  }
  L0044da2b: { // 0x44da2b: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044da2d: { // 0x44da2d: 7545 JNZ 0x44da74
    if(integer::condition("JNZ",flags)) goto L0044da74;
  }
  L0044da2f: { // 0x44da2f: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0044da33: { // 0x44da33: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044da34: { // 0x44da34: 8d8fe0020000 LEA ECX, [EDI + 0x2e0]
    s.cx = (s.di+0x000002e0u);
  }
  L0044da3a: { // 0x44da3a: e811ae0600 CALL 0x4b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4512319u); flags=s.arithmetic_flags;
  }
  L0044da3f: { // 0x44da3f: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044da41: { // 0x44da41: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0044da43: { // 0x44da43: c1ea0c SHR EDX, 0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044da46: { // 0x44da46: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0044da47: { // 0x44da47: 83e003 AND EAX, 3
    s.ax = integer::logical((s.ax)&(3u),32,flags);
  }
  L0044da4a: { // 0x44da4a: d1ea SHR EDX, 1
    s.dx = integer::shift(s.dx,1u,32,flags,integer::Shift::right);
  }
  L0044da4c: { // 0x44da4c: 83e203 AND EDX, 3
    s.dx = integer::logical((s.dx)&(3u),32,flags);
  }
  L0044da4f: { // 0x44da4f: 33d0 XOR EDX, EAX
    s.dx = integer::logical((s.dx)^(s.ax),32,flags);
  }
  L0044da51: { // 0x44da51: 7521 JNZ 0x44da74
    if(integer::condition("JNZ",flags)) goto L0044da74;
  }
  L0044da53: { // 0x44da53: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0044da57: { // 0x44da57: 8bbbec040000 MOV EDI, dword ptr [EBX + 0x4ec]
    s.di = m.r32((s.bx+0x000004ecu));
  }
  L0044da5d: { // 0x44da5d: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0044da61: { // 0x44da61: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0044da63: { // 0x44da63: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044da64: { // 0x44da64: 0bfa OR EDI, EDX
    s.di = integer::logical((s.di)|(s.dx),32,flags);
  }
  L0044da66: { // 0x44da66: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044da67: { // 0x44da67: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044da69: { // 0x44da69: 89bbec040000 MOV dword ptr [EBX + 0x4ec], EDI
    m.w32((s.bx+0x000004ecu), s.di);
  }
  L0044da6f: { // 0x44da6f: e8dc040000 CALL 0x44df50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044df50u,4512372u); flags=s.arithmetic_flags;
  }
  L0044da74: { // 0x44da74: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044da78: { // 0x44da78: 83c602 ADD ESI, 2
    s.si = integer::add(s.si,2u,32,flags);
  }
  L0044da7b: { // 0x44da7b: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L0044da7e: { // 0x44da7e: 83e607 AND ESI, 7
    s.si = integer::logical((s.si)&(7u),32,flags);
  }
  L0044da81: { // 0x44da81: 3de8a57b00 CMP EAX, 0x7ba5e8
    (void)integer::sub(s.ax,0x007ba5e8u,32,flags);
  }
  L0044da86: { // 0x44da86: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0044da8a: { // 0x44da8a: 0f8c25ffffff JL 0x44d9b5
    if(integer::condition("JL",flags)) goto L0044d9b5;
  }
  L0044da90: { // 0x44da90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044da91: { // 0x44da91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044da92: { // 0x44da92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044da93: { // 0x44da93: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044da94: { // 0x44da94: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0044da97: { // 0x44da97: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0004df50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044df50: { // 0x44df50: 83ec28 SUB ESP, 0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L0044df53: { // 0x44df53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044df54: { // 0x44df54: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0044df56: { // 0x44df56: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044df57: { // 0x44df57: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044df58: { // 0x44df58: 8b8318040000 MOV EAX, dword ptr [EBX + 0x418]
    s.ax = m.r32((s.bx+0x00000418u));
  }
  L0044df5e: { // 0x44df5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044df5f: { // 0x44df5f: 895c2420 MOV dword ptr [ESP + 0x20], EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0044df63: { // 0x44df63: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044df69: { // 0x44df69: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044df6b: { // 0x44df6b: 0f84ae010000 JZ 0x44e11f
    if(integer::condition("JZ",flags)) goto L0044e11f;
  }
  L0044df71: { // 0x44df71: 8ba804050000 MOV EBP, dword ptr [EAX + 0x504]
    s.bp = m.r32((s.ax+0x00000504u));
  }
  L0044df77: { // 0x44df77: c1fd08 SAR EBP, 8
    s.bp = integer::shift(s.bp,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044df7a: { // 0x44df7a: 83fd01 CMP EBP, 1
    (void)integer::sub(s.bp,1u,32,flags);
  }
  L0044df7d: { // 0x44df7d: 896c2410 MOV dword ptr [ESP + 0x10], EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0044df81: { // 0x44df81: 7f09 JG 0x44df8c
    if(integer::condition("JG",flags)) goto L0044df8c;
  }
  L0044df83: { // 0x44df83: bd01000000 MOV EBP, 1
    s.bp = 1u;
  }
  L0044df88: { // 0x44df88: 896c2410 MOV dword ptr [ESP + 0x10], EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0044df8c: { // 0x44df8c: 8b74243c MOV ESI, dword ptr [ESP + 0x3c]
    s.si = m.r32((f.sp+0x0000003cu));
  }
  L0044df90: { // 0x44df90: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044df92: { // 0x44df92: 8bfe MOV EDI, ESI
    s.di = s.si;
  }
  L0044df94: { // 0x44df94: 8d4c242c LEA ECX, [ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0044df98: { // 0x44df98: 83e703 AND EDI, 3
    s.di = integer::logical((s.di)&(3u),32,flags);
  }
  L0044df9b: { // 0x44df9b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044df9c: { // 0x44df9c: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044df9e: { // 0x44df9e: 897c2428 MOV dword ptr [ESP + 0x28], EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L0044dfa2: { // 0x44dfa2: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4513701u); flags=s.arithmetic_flags;
  }
  L0044dfa5: { // 0x44dfa5: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044dfa7: { // 0x44dfa7: c744241800000000 MOV dword ptr [ESP + 0x18], 0
    m.w32((f.sp+0x00000018u), 0u);
  }
  L0044dfaf: { // 0x44dfaf: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0044dfb1: { // 0x44dfb1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044dfb2: { // 0x44dfb2: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044dfb8: { // 0x44dfb8: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044dfba: { // 0x44dfba: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044dfbd: { // 0x44dfbd: 6689442414 MOV word ptr [ESP + 0x14], AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0044dfc2: { // 0x44dfc2: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0044dfc5: { // 0x44dfc5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044dfc6: { // 0x44dfc6: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044dfcc: { // 0x44dfcc: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044dfce: { // 0x44dfce: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044dfd1: { // 0x44dfd1: 6689442416 MOV word ptr [ESP + 0x16], AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0044dfd6: { // 0x44dfd6: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0044dfda: { // 0x44dfda: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0044dfdc: { // 0x44dfdc: 8954243c MOV dword ptr [ESP + 0x3c], EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0044dfe0: { // 0x44dfe0: 0f8e39010000 JLE 0x44e11f
    if(integer::condition("JLE",flags)) goto L0044e11f;
  }
  L0044dfe6: { // 0x44dfe6: 83e607 AND ESI, 7
    s.si = integer::logical((s.si)&(7u),32,flags);
  }
  L0044dfe9: { // 0x44dfe9: 8d34b5a09d8300 LEA ESI, [ESI*4 + 0x839da0]
    s.si = ((s.si * 4u)+0x00839da0u);
  }
  L0044dff0: { // 0x44dff0: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0044dff4: { // 0x44dff4: eb04 JMP 0x44dffa
    goto L0044dffa;
  }
  L0044dff6: { // 0x44dff6: 8b74241c MOV ESI, dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L0044dffa: { // 0x44dffa: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0044dffd: { // 0x44dffd: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0044e001: { // 0x44e001: 660344243c ADD AX, word ptr [ESP + 0x3c]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000003cu)),16,flags));
  }
  L0044e006: { // 0x44e006: 66034c243e ADD CX, word ptr [ESP + 0x3e]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000003eu)),16,flags));
  }
  L0044e00b: { // 0x44e00b: 6689442414 MOV word ptr [ESP + 0x14], AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0044e010: { // 0x44e010: 66894c2416 MOV word ptr [ESP + 0x16], CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L0044e015: { // 0x44e015: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0044e019: { // 0x44e019: 8d44243c LEA EAX, [ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  L0044e01d: { // 0x44e01d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e01e: { // 0x44e01e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e023: { // 0x44e023: 89542440 MOV dword ptr [ESP + 0x40], EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0044e027: { // 0x44e027: e8d4740f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4513836u); flags=s.arithmetic_flags;
  }
  L0044e02c: { // 0x44e02c: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044e02e: { // 0x44e02e: e87d330200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4513843u); flags=s.arithmetic_flags;
  }
  L0044e033: { // 0x44e033: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L0044e035: { // 0x44e035: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0044e037: { // 0x44e037: 0f84d1000000 JZ 0x44e10e
    if(integer::condition("JZ",flags)) goto L0044e10e;
  }
  L0044e03d: { // 0x44e03d: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0044e043: { // 0x44e043: 8a8159130000 MOV AL, byte ptr [ECX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001359u)));
  }
  L0044e049: { // 0x44e049: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e04b: { // 0x44e04b: 0f84ce000000 JZ 0x44e11f
    if(integer::condition("JZ",flags)) goto L0044e11f;
  }
  L0044e051: { // 0x44e051: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e053: { // 0x44e053: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e055: { // 0x44e055: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4513880u); flags=s.arithmetic_flags;
  }
  L0044e058: { // 0x44e058: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0044e05a: { // 0x44e05a: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044e05c: { // 0x44e05c: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044e05e: { // 0x44e05e: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4513889u); flags=s.arithmetic_flags;
  }
  L0044e061: { // 0x44e061: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044e063: { // 0x44e063: 0f85b6000000 JNZ 0x44e11f
    if(integer::condition("JNZ",flags)) goto L0044e11f;
  }
  L0044e069: { // 0x44e069: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0044e06d: { // 0x44e06d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e06e: { // 0x44e06e: 8d8ee0020000 LEA ECX, [ESI + 0x2e0]
    s.cx = (s.si+0x000002e0u);
  }
  L0044e074: { // 0x44e074: e8d7a70600 CALL 0x4b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4513913u); flags=s.arithmetic_flags;
  }
  L0044e079: { // 0x44e079: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044e07b: { // 0x44e07b: c1ea0c SHR EDX, 0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044e07e: { // 0x44e07e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0044e07f: { // 0x44e07f: d1ea SHR EDX, 1
    s.dx = integer::shift(s.dx,1u,32,flags,integer::Shift::right);
  }
  L0044e081: { // 0x44e081: 83e203 AND EDX, 3
    s.dx = integer::logical((s.dx)&(3u),32,flags);
  }
  L0044e084: { // 0x44e084: 3bd7 CMP EDX, EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L0044e086: { // 0x44e086: 0f8593000000 JNZ 0x44e11f
    if(integer::condition("JNZ",flags)) goto L0044e11f;
  }
  L0044e08c: { // 0x44e08c: 8a442440 MOV AL, byte ptr [ESP + 0x40]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000040u)));
  }
  L0044e090: { // 0x44e090: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e092: { // 0x44e092: 746c JZ 0x44e100
    if(integer::condition("JZ",flags)) goto L0044e100;
  }
  L0044e094: { // 0x44e094: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0044e099: { // 0x44e099: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e09b: { // 0x44e09b: 8b6e6c MOV EBP, dword ptr [ESI + 0x6c]
    s.bp = m.r32((s.si+0x0000006cu));
  }
  L0044e09e: { // 0x44e09e: 8d7e6c LEA EDI, [ESI + 0x6c]
    s.di = (s.si+0x0000006cu);
  }
  L0044e0a1: { // 0x44e0a1: 8b98740c0000 MOV EBX, dword ptr [EAX + 0xc74]
    s.bx = m.r32((s.ax+0x00000c74u));
  }
  L0044e0a7: { // 0x44e0a7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0a9: { // 0x44e0a9: 8d442430 LEA EAX, [ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0044e0ad: { // 0x44e0ad: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0af: { // 0x44e0af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e0b0: { // 0x44e0b0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e0b2: { // 0x44e0b2: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4513973u); flags=s.arithmetic_flags;
  }
  L0044e0b5: { // 0x44e0b5: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044e0b7: { // 0x44e0b7: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0044e0ba: { // 0x44e0ba: 8bcc MOV ECX, ESP
    s.cx = f.sp;
  }
  L0044e0bc: { // 0x44e0bc: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L0044e0be: { // 0x44e0be: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0044e0c1: { // 0x44e0c1: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L0044e0c4: { // 0x44e0c4: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L0044e0c7: { // 0x44e0c7: 8bd3 MOV EDX, EBX
    s.dx = s.bx;
  }
  L0044e0c9: { // 0x44e0c9: 894108 MOV dword ptr [ECX + 8], EAX
    m.w32((s.cx+8u), s.ax);
  }
  L0044e0cc: { // 0x44e0cc: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L0044e0ce: { // 0x44e0ce: e84d110300 CALL 0x47f220
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047f220u,4514003u); flags=s.arithmetic_flags;
  }
  L0044e0d3: { // 0x44e0d3: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0044e0d8: { // 0x44e0d8: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e0da: { // 0x44e0da: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044e0dc: { // 0x44e0dc: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044e0de: { // 0x44e0de: 8b88740c0000 MOV ECX, dword ptr [EAX + 0xc74]
    s.cx = m.r32((s.ax+0x00000c74u));
  }
  L0044e0e4: { // 0x44e0e4: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0e6: { // 0x44e0e6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e0e7: { // 0x44e0e7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0e9: { // 0x44e0e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e0ea: { // 0x44e0ea: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e0ec: { // 0x44e0ec: ff9258010000 CALL dword ptr [EDX + 0x158]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000158u)),4514034u); flags=s.arithmetic_flags;
  }
  L0044e0f2: { // 0x44e0f2: 8b5c2420 MOV EBX, dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L0044e0f6: { // 0x44e0f6: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044e0fa: { // 0x44e0fa: 8b7c2424 MOV EDI, dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L0044e0fe: { // 0x44e0fe: eb0e JMP 0x44e10e
    goto L0044e10e;
  }
  L0044e100: { // 0x44e100: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e102: { // 0x44e102: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e104: { // 0x44e104: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),4514058u); flags=s.arithmetic_flags;
  }
  L0044e10a: { // 0x44e10a: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044e10e: { // 0x44e10e: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0044e112: { // 0x44e112: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0044e113: { // 0x44e113: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044e115: { // 0x44e115: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0044e119: { // 0x44e119: 0f8cd7feffff JL 0x44dff6
    if(integer::condition("JL",flags)) goto L0044dff6;
  }
  L0044e11f: { // 0x44e11f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044e120: { // 0x44e120: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044e121: { // 0x44e121: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044e122: { // 0x44e122: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044e123: { // 0x44e123: 83c428 ADD ESP, 0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L0044e126: { // 0x44e126: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX, word ptr [EDX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+2u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI, word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX, dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000713b0(Memory& m,State& s,Frame& f,const Operations& op) { if(m.r8(0xa285a8u)!=1u||m.r32(s.cx+0xe4u)!=0u)throw std::domain_error("B1531 actualenabledempty713B0");
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713b0: { // 0x4713b0: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713b5: { // 0x4713b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713b6: { // 0x4713b6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713b8: { // 0x4713b8: 741d JZ 0x4713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713ba: { // 0x4713ba: 8bb1e4000000 MOV ESI, dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L004713c0: { // 0x4713c0: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713c2: { // 0x4713c2: 7413 JZ 0x4713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713c4: { // 0x4713c4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004713c6: { // 0x4713c6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004713c8: { // 0x4713c8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658123u); flags=s.arithmetic_flags;
  }
  L004713cb: { // 0x4713cb: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L004713ce: { // 0x4713ce: 740b JZ 0x4713db
    if(integer::condition("JZ",flags)) goto L004713db;
  }
  L004713d0: { // 0x4713d0: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004713d3: { // 0x4713d3: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713d5: { // 0x4713d5: 75ed JNZ 0x4713c4
    if(integer::condition("JNZ",flags)) goto L004713c4;
  }
  L004713d7: { // 0x4713d7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004713d9: { // 0x4713d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713da: { // 0x4713da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004713db: { // 0x4713db: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L004713dd: { // 0x4713dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713de: { // 0x4713de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001cd4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd4d0: { // 0x5cd4d0: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L005cd4d4: { // 0x5cd4d4: 81c188000000 ADD ECX, 0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L005cd4da: { // 0x5cd4da: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cd4db: { // 0x5cd4db: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005cd4dd: { // 0x5cd4dd: 8b31 MOV ESI, dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L005cd4df: { // 0x5cd4df: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L005cd4e1: { // 0x5cd4e1: 8b7104 MOV ESI, dword ptr [ECX + 4]
    s.si = m.r32((s.cx+4u));
  }
  L005cd4e4: { // 0x5cd4e4: 897204 MOV dword ptr [EDX + 4], ESI
    m.w32((s.dx+4u), s.si);
  }
  L005cd4e7: { // 0x5cd4e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cd4e8: { // 0x5cd4e8: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L005cd4eb: { // 0x5cd4eb: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L005cd4ee: { // 0x5cd4ee: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4512048u:f_0004d930(m,s,child,{});break;
case 4513616u:f_0004df50(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
case 6083792u:f_001cd4d0(m,s,child,{});break;
default:throw std::domain_error("recovery1531 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1531 no reviewed tail"); } }

std::uint32_t fun_0044d930(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d930: { // 0x44d930: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L0044d935: { // 0x44d935: 83ec20 SUB ESP, 0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0044d938: { // 0x44d938: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044d93a: { // 0x44d93a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d93b: { // 0x44d93b: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0044d93d: { // 0x44d93d: 0f8550010000 JNZ 0x44da93
    if(integer::condition("JNZ",flags)) goto L0044da93;
  }
  L0044d943: { // 0x44d943: 8b8318040000 MOV EAX, dword ptr [EBX + 0x418]
    s.ax = m.r32((s.bx+0x00000418u));
  }
  L0044d949: { // 0x44d949: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044d94f: { // 0x44d94f: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d951: { // 0x44d951: 0f843c010000 JZ 0x44da93
    if(integer::condition("JZ",flags)) goto L0044da93;
  }
  L0044d957: { // 0x44d957: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0044d95b: { // 0x44d95b: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0044d960: { // 0x44d960: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0044d962: { // 0x44d962: c644240c00 MOV byte ptr [ESP + 0xc], 0
    m.w8((f.sp+0x0000000cu), 0u);
  }
  L0044d967: { // 0x44d967: 7504 JNZ 0x44d96d
    if(integer::condition("JNZ",flags)) goto L0044d96d;
  }
  L0044d969: { // 0x44d969: 8844240c MOV byte ptr [ESP + 0xc], AL
    m.w8((f.sp+0x0000000cu), (s.ax & 0xffu));
  }
  L0044d96d: { // 0x44d96d: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0044d96f: { // 0x44d96f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d970: { // 0x44d970: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d971: { // 0x44d971: 8d442420 LEA EAX, [ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0044d975: { // 0x44d975: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d976: { // 0x44d976: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044d977: { // 0x44d977: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044d979: { // 0x44d979: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0044d97b: { // 0x44d97b: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4512126u); flags=s.arithmetic_flags;
  }
  L0044d97e: { // 0x44d97e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044d980: { // 0x44d980: c7442410d8a57b00 MOV dword ptr [ESP + 0x10], 0x7ba5d8
    m.w32((f.sp+0x00000010u), 0x007ba5d8u);
  }
  L0044d988: { // 0x44d988: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0044d98a: { // 0x44d98a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044d98b: { // 0x44d98b: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044d991: { // 0x44d991: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044d993: { // 0x44d993: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0044d995: { // 0x44d995: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0044d998: { // 0x44d998: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044d999: { // 0x44d999: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044d99f: { // 0x44d99f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044d9a1: { // 0x44d9a1: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044d9a3: { // 0x44d9a3: c1ff08 SAR EDI, 8
    s.di = integer::shift(s.di,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044d9a6: { // 0x44d9a6: c1f908 SAR ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044d9a9: { // 0x44d9a9: 66897c2434 MOV word ptr [ESP + 0x34], DI
    m.w16((f.sp+0x00000034u), (s.di & 0xffffu));
  }
  L0044d9ae: { // 0x44d9ae: 66894c2436 MOV word ptr [ESP + 0x36], CX
    m.w16((f.sp+0x00000036u), (s.cx & 0xffffu));
  }
  L0044d9b3: { // 0x44d9b3: eb0a JMP 0x44d9bf
    goto L0044d9bf;
  }
  L0044d9b5: { // 0x44d9b5: 668b7c2434 MOV DI, word ptr [ESP + 0x34]
    s.di = (s.di & 0xffff0000u) | ((m.r16((f.sp+0x00000034u))) & 0xffffu);
  }
  L0044d9ba: { // 0x44d9ba: 668b4c2436 MOV CX, word ptr [ESP + 0x36]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000036u)));
  }
  L0044d9bf: { // 0x44d9bf: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L0044d9c1: { // 0x44d9c1: 83e207 AND EDX, 7
    s.dx = integer::logical((s.dx)&(7u),32,flags);
  }
  L0044d9c4: { // 0x44d9c4: 8d0495a09d8300 LEA EAX, [EDX*4 + 0x839da0]
    s.ax = ((s.dx * 4u)+0x00839da0u);
  }
  L0044d9cb: { // 0x44d9cb: 668b1495a09d8300 MOV DX, word ptr [EDX*4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 4u)+0x00839da0u)));
  }
  L0044d9d3: { // 0x44d9d3: 668b4002 MOV AX, word ptr [EAX + 2]
    s.ax = with_ax(s.ax, m.r16((s.ax+2u)));
  }
  L0044d9d7: { // 0x44d9d7: 6603d7 ADD DX, DI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L0044d9da: { // 0x44d9da: 6603c1 ADD AX, CX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L0044d9dd: { // 0x44d9dd: 6689542414 MOV word ptr [ESP + 0x14], DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L0044d9e2: { // 0x44d9e2: 6689442416 MOV word ptr [ESP + 0x16], AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0044d9e7: { // 0x44d9e7: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0044d9eb: { // 0x44d9eb: 8d54241c LEA EDX, [ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0044d9ef: { // 0x44d9ef: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0044d9f3: { // 0x44d9f3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0044d9f4: { // 0x44d9f4: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044d9f9: { // 0x44d9f9: e8027b0f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4512254u); flags=s.arithmetic_flags;
  }
  L0044d9fe: { // 0x44d9fe: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044da00: { // 0x44da00: e8ab390200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4512261u); flags=s.arithmetic_flags;
  }
  L0044da05: { // 0x44da05: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0044da07: { // 0x44da07: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0044da09: { // 0x44da09: 7469 JZ 0x44da74
    if(integer::condition("JZ",flags)) goto L0044da74;
  }
  L0044da0b: { // 0x44da0b: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044da11: { // 0x44da11: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0044da17: { // 0x44da17: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044da19: { // 0x44da19: 7459 JZ 0x44da74
    if(integer::condition("JZ",flags)) goto L0044da74;
  }
  L0044da1b: { // 0x44da1b: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044da1d: { // 0x44da1d: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044da1f: { // 0x44da1f: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4512290u); flags=s.arithmetic_flags;
  }
  L0044da22: { // 0x44da22: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0044da24: { // 0x44da24: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044da26: { // 0x44da26: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044da28: { // 0x44da28: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4512299u); flags=s.arithmetic_flags;
  }
  L0044da2b: { // 0x44da2b: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044da2d: { // 0x44da2d: 7545 JNZ 0x44da74
    if(integer::condition("JNZ",flags)) goto L0044da74;
  }
  L0044da2f: { // 0x44da2f: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0044da33: { // 0x44da33: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044da34: { // 0x44da34: 8d8fe0020000 LEA ECX, [EDI + 0x2e0]
    s.cx = (s.di+0x000002e0u);
  }
  L0044da3a: { // 0x44da3a: e811ae0600 CALL 0x4b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4512319u); flags=s.arithmetic_flags;
  }
  L0044da3f: { // 0x44da3f: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044da41: { // 0x44da41: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0044da43: { // 0x44da43: c1ea0c SHR EDX, 0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044da46: { // 0x44da46: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0044da47: { // 0x44da47: 83e003 AND EAX, 3
    s.ax = integer::logical((s.ax)&(3u),32,flags);
  }
  L0044da4a: { // 0x44da4a: d1ea SHR EDX, 1
    s.dx = integer::shift(s.dx,1u,32,flags,integer::Shift::right);
  }
  L0044da4c: { // 0x44da4c: 83e203 AND EDX, 3
    s.dx = integer::logical((s.dx)&(3u),32,flags);
  }
  L0044da4f: { // 0x44da4f: 33d0 XOR EDX, EAX
    s.dx = integer::logical((s.dx)^(s.ax),32,flags);
  }
  L0044da51: { // 0x44da51: 7521 JNZ 0x44da74
    if(integer::condition("JNZ",flags)) goto L0044da74;
  }
  L0044da53: { // 0x44da53: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0044da57: { // 0x44da57: 8bbbec040000 MOV EDI, dword ptr [EBX + 0x4ec]
    s.di = m.r32((s.bx+0x000004ecu));
  }
  L0044da5d: { // 0x44da5d: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0044da61: { // 0x44da61: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0044da63: { // 0x44da63: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044da64: { // 0x44da64: 0bfa OR EDI, EDX
    s.di = integer::logical((s.di)|(s.dx),32,flags);
  }
  L0044da66: { // 0x44da66: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044da67: { // 0x44da67: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044da69: { // 0x44da69: 89bbec040000 MOV dword ptr [EBX + 0x4ec], EDI
    m.w32((s.bx+0x000004ecu), s.di);
  }
  L0044da6f: { // 0x44da6f: e8dc040000 CALL 0x44df50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044df50u,4512372u); flags=s.arithmetic_flags;
  }
  L0044da74: { // 0x44da74: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044da78: { // 0x44da78: 83c602 ADD ESI, 2
    s.si = integer::add(s.si,2u,32,flags);
  }
  L0044da7b: { // 0x44da7b: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L0044da7e: { // 0x44da7e: 83e607 AND ESI, 7
    s.si = integer::logical((s.si)&(7u),32,flags);
  }
  L0044da81: { // 0x44da81: 3de8a57b00 CMP EAX, 0x7ba5e8
    (void)integer::sub(s.ax,0x007ba5e8u,32,flags);
  }
  L0044da86: { // 0x44da86: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0044da8a: { // 0x44da8a: 0f8c25ffffff JL 0x44d9b5
    if(integer::condition("JL",flags)) goto L0044d9b5;
  }
  L0044da90: { // 0x44da90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044da91: { // 0x44da91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044da92: { // 0x44da92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044da93: { // 0x44da93: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044da94: { // 0x44da94: 83c420 ADD ESP, 0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0044da97: { // 0x44da97: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0044df50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044df50: { // 0x44df50: 83ec28 SUB ESP, 0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L0044df53: { // 0x44df53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044df54: { // 0x44df54: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0044df56: { // 0x44df56: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044df57: { // 0x44df57: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044df58: { // 0x44df58: 8b8318040000 MOV EAX, dword ptr [EBX + 0x418]
    s.ax = m.r32((s.bx+0x00000418u));
  }
  L0044df5e: { // 0x44df5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044df5f: { // 0x44df5f: 895c2420 MOV dword ptr [ESP + 0x20], EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0044df63: { // 0x44df63: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044df69: { // 0x44df69: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044df6b: { // 0x44df6b: 0f84ae010000 JZ 0x44e11f
    if(integer::condition("JZ",flags)) goto L0044e11f;
  }
  L0044df71: { // 0x44df71: 8ba804050000 MOV EBP, dword ptr [EAX + 0x504]
    s.bp = m.r32((s.ax+0x00000504u));
  }
  L0044df77: { // 0x44df77: c1fd08 SAR EBP, 8
    s.bp = integer::shift(s.bp,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044df7a: { // 0x44df7a: 83fd01 CMP EBP, 1
    (void)integer::sub(s.bp,1u,32,flags);
  }
  L0044df7d: { // 0x44df7d: 896c2410 MOV dword ptr [ESP + 0x10], EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0044df81: { // 0x44df81: 7f09 JG 0x44df8c
    if(integer::condition("JG",flags)) goto L0044df8c;
  }
  L0044df83: { // 0x44df83: bd01000000 MOV EBP, 1
    s.bp = 1u;
  }
  L0044df88: { // 0x44df88: 896c2410 MOV dword ptr [ESP + 0x10], EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0044df8c: { // 0x44df8c: 8b74243c MOV ESI, dword ptr [ESP + 0x3c]
    s.si = m.r32((f.sp+0x0000003cu));
  }
  L0044df90: { // 0x44df90: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044df92: { // 0x44df92: 8bfe MOV EDI, ESI
    s.di = s.si;
  }
  L0044df94: { // 0x44df94: 8d4c242c LEA ECX, [ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0044df98: { // 0x44df98: 83e703 AND EDI, 3
    s.di = integer::logical((s.di)&(3u),32,flags);
  }
  L0044df9b: { // 0x44df9b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044df9c: { // 0x44df9c: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044df9e: { // 0x44df9e: 897c2428 MOV dword ptr [ESP + 0x28], EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L0044dfa2: { // 0x44dfa2: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4513701u); flags=s.arithmetic_flags;
  }
  L0044dfa5: { // 0x44dfa5: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044dfa7: { // 0x44dfa7: c744241800000000 MOV dword ptr [ESP + 0x18], 0
    m.w32((f.sp+0x00000018u), 0u);
  }
  L0044dfaf: { // 0x44dfaf: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0044dfb1: { // 0x44dfb1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044dfb2: { // 0x44dfb2: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044dfb8: { // 0x44dfb8: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044dfba: { // 0x44dfba: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044dfbd: { // 0x44dfbd: 6689442414 MOV word ptr [ESP + 0x14], AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0044dfc2: { // 0x44dfc2: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0044dfc5: { // 0x44dfc5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0044dfc6: { // 0x44dfc6: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0044dfcc: { // 0x44dfcc: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0044dfce: { // 0x44dfce: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0044dfd1: { // 0x44dfd1: 6689442416 MOV word ptr [ESP + 0x16], AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0044dfd6: { // 0x44dfd6: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0044dfda: { // 0x44dfda: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0044dfdc: { // 0x44dfdc: 8954243c MOV dword ptr [ESP + 0x3c], EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0044dfe0: { // 0x44dfe0: 0f8e39010000 JLE 0x44e11f
    if(integer::condition("JLE",flags)) goto L0044e11f;
  }
  L0044dfe6: { // 0x44dfe6: 83e607 AND ESI, 7
    s.si = integer::logical((s.si)&(7u),32,flags);
  }
  L0044dfe9: { // 0x44dfe9: 8d34b5a09d8300 LEA ESI, [ESI*4 + 0x839da0]
    s.si = ((s.si * 4u)+0x00839da0u);
  }
  L0044dff0: { // 0x44dff0: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0044dff4: { // 0x44dff4: eb04 JMP 0x44dffa
    goto L0044dffa;
  }
  L0044dff6: { // 0x44dff6: 8b74241c MOV ESI, dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L0044dffa: { // 0x44dffa: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0044dffd: { // 0x44dffd: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0044e001: { // 0x44e001: 660344243c ADD AX, word ptr [ESP + 0x3c]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000003cu)),16,flags));
  }
  L0044e006: { // 0x44e006: 66034c243e ADD CX, word ptr [ESP + 0x3e]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000003eu)),16,flags));
  }
  L0044e00b: { // 0x44e00b: 6689442414 MOV word ptr [ESP + 0x14], AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0044e010: { // 0x44e010: 66894c2416 MOV word ptr [ESP + 0x16], CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L0044e015: { // 0x44e015: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0044e019: { // 0x44e019: 8d44243c LEA EAX, [ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  L0044e01d: { // 0x44e01d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e01e: { // 0x44e01e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e023: { // 0x44e023: 89542440 MOV dword ptr [ESP + 0x40], EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0044e027: { // 0x44e027: e8d4740f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4513836u); flags=s.arithmetic_flags;
  }
  L0044e02c: { // 0x44e02c: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044e02e: { // 0x44e02e: e87d330200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4513843u); flags=s.arithmetic_flags;
  }
  L0044e033: { // 0x44e033: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L0044e035: { // 0x44e035: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0044e037: { // 0x44e037: 0f84d1000000 JZ 0x44e10e
    if(integer::condition("JZ",flags)) goto L0044e10e;
  }
  L0044e03d: { // 0x44e03d: 8b8e18040000 MOV ECX, dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0044e043: { // 0x44e043: 8a8159130000 MOV AL, byte ptr [ECX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001359u)));
  }
  L0044e049: { // 0x44e049: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e04b: { // 0x44e04b: 0f84ce000000 JZ 0x44e11f
    if(integer::condition("JZ",flags)) goto L0044e11f;
  }
  L0044e051: { // 0x44e051: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e053: { // 0x44e053: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e055: { // 0x44e055: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),4513880u); flags=s.arithmetic_flags;
  }
  L0044e058: { // 0x44e058: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0044e05a: { // 0x44e05a: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0044e05c: { // 0x44e05c: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044e05e: { // 0x44e05e: ff5038 CALL dword ptr [EAX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000038u)),4513889u); flags=s.arithmetic_flags;
  }
  L0044e061: { // 0x44e061: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044e063: { // 0x44e063: 0f85b6000000 JNZ 0x44e11f
    if(integer::condition("JNZ",flags)) goto L0044e11f;
  }
  L0044e069: { // 0x44e069: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0044e06d: { // 0x44e06d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e06e: { // 0x44e06e: 8d8ee0020000 LEA ECX, [ESI + 0x2e0]
    s.cx = (s.si+0x000002e0u);
  }
  L0044e074: { // 0x44e074: e8d7a70600 CALL 0x4b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4513913u); flags=s.arithmetic_flags;
  }
  L0044e079: { // 0x44e079: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044e07b: { // 0x44e07b: c1ea0c SHR EDX, 0xc
    s.dx = integer::shift(s.dx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044e07e: { // 0x44e07e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0044e07f: { // 0x44e07f: d1ea SHR EDX, 1
    s.dx = integer::shift(s.dx,1u,32,flags,integer::Shift::right);
  }
  L0044e081: { // 0x44e081: 83e203 AND EDX, 3
    s.dx = integer::logical((s.dx)&(3u),32,flags);
  }
  L0044e084: { // 0x44e084: 3bd7 CMP EDX, EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L0044e086: { // 0x44e086: 0f8593000000 JNZ 0x44e11f
    if(integer::condition("JNZ",flags)) goto L0044e11f;
  }
  L0044e08c: { // 0x44e08c: 8a442440 MOV AL, byte ptr [ESP + 0x40]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000040u)));
  }
  L0044e090: { // 0x44e090: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044e092: { // 0x44e092: 746c JZ 0x44e100
    if(integer::condition("JZ",flags)) goto L0044e100;
  }
  L0044e094: { // 0x44e094: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0044e099: { // 0x44e099: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e09b: { // 0x44e09b: 8b6e6c MOV EBP, dword ptr [ESI + 0x6c]
    s.bp = m.r32((s.si+0x0000006cu));
  }
  L0044e09e: { // 0x44e09e: 8d7e6c LEA EDI, [ESI + 0x6c]
    s.di = (s.si+0x0000006cu);
  }
  L0044e0a1: { // 0x44e0a1: 8b98740c0000 MOV EBX, dword ptr [EAX + 0xc74]
    s.bx = m.r32((s.ax+0x00000c74u));
  }
  L0044e0a7: { // 0x44e0a7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0a9: { // 0x44e0a9: 8d442430 LEA EAX, [ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0044e0ad: { // 0x44e0ad: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0af: { // 0x44e0af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044e0b0: { // 0x44e0b0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e0b2: { // 0x44e0b2: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4513973u); flags=s.arithmetic_flags;
  }
  L0044e0b5: { // 0x44e0b5: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044e0b7: { // 0x44e0b7: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0044e0ba: { // 0x44e0ba: 8bcc MOV ECX, ESP
    s.cx = f.sp;
  }
  L0044e0bc: { // 0x44e0bc: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L0044e0be: { // 0x44e0be: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0044e0c1: { // 0x44e0c1: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L0044e0c4: { // 0x44e0c4: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L0044e0c7: { // 0x44e0c7: 8bd3 MOV EDX, EBX
    s.dx = s.bx;
  }
  L0044e0c9: { // 0x44e0c9: 894108 MOV dword ptr [ECX + 8], EAX
    m.w32((s.cx+8u), s.ax);
  }
  L0044e0cc: { // 0x44e0cc: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L0044e0ce: { // 0x44e0ce: e84d110300 CALL 0x47f220
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047f220u,4514003u); flags=s.arithmetic_flags;
  }
  L0044e0d3: { // 0x44e0d3: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0044e0d8: { // 0x44e0d8: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e0da: { // 0x44e0da: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044e0dc: { // 0x44e0dc: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0044e0de: { // 0x44e0de: 8b88740c0000 MOV ECX, dword ptr [EAX + 0xc74]
    s.cx = m.r32((s.ax+0x00000c74u));
  }
  L0044e0e4: { // 0x44e0e4: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0e6: { // 0x44e0e6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e0e7: { // 0x44e0e7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e0e9: { // 0x44e0e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e0ea: { // 0x44e0ea: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e0ec: { // 0x44e0ec: ff9258010000 CALL dword ptr [EDX + 0x158]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000158u)),4514034u); flags=s.arithmetic_flags;
  }
  L0044e0f2: { // 0x44e0f2: 8b5c2420 MOV EBX, dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L0044e0f6: { // 0x44e0f6: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044e0fa: { // 0x44e0fa: 8b7c2424 MOV EDI, dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L0044e0fe: { // 0x44e0fe: eb0e JMP 0x44e10e
    goto L0044e10e;
  }
  L0044e100: { // 0x44e100: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0044e102: { // 0x44e102: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044e104: { // 0x44e104: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),4514058u); flags=s.arithmetic_flags;
  }
  L0044e10a: { // 0x44e10a: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044e10e: { // 0x44e10e: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0044e112: { // 0x44e112: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0044e113: { // 0x44e113: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0044e115: { // 0x44e115: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0044e119: { // 0x44e119: 0f8cd7feffff JL 0x44dff6
    if(integer::condition("JL",flags)) goto L0044dff6;
  }
  L0044e11f: { // 0x44e11f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044e120: { // 0x44e120: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044e121: { // 0x44e121: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044e122: { // 0x44e122: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044e123: { // 0x44e123: 83c428 ADD ESP, 0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L0044e126: { // 0x44e126: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
