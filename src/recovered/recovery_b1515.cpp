#include "recovered/recovery_b1515_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1515 {
namespace {
void f_0004e130(Memory&,State&,Frame&,const Operations&);
void f_00167270(Memory&,State&,Frame&,const Operations&);
void f_00167450(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void f_000714b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0004e130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044e130: { // 0x44e130: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0044e133: { // 0x44e133: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044e134: { // 0x44e134: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044e135: { // 0x44e135: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044e136: { // 0x44e136: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e137: { // 0x44e137: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044e139: { // 0x44e139: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e13a: { // 0x44e13a: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e13f: { // 0x44e13f: e8bc730f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4514116u); flags=s.arithmetic_flags;
  }
  L0044e144: { // 0x44e144: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044e146: { // 0x44e146: 0f8404010000 JZ 0x44e250
    if(integer::condition("JZ",flags)) goto L0044e250;
  }
  L0044e14c: { // 0x44e14c: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044e14e: { // 0x44e14e: e85d320200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4514131u); flags=s.arithmetic_flags;
  }
  L0044e153: { // 0x44e153: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0044e155: { // 0x44e155: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0044e157: { // 0x44e157: 0f84f3000000 JZ 0x44e250
    if(integer::condition("JZ",flags)) goto L0044e250;
  }
  L0044e15d: { // 0x44e15d: 8b8518040000 MOV EAX, dword ptr [EBP + 0x418]
    s.ax = m.r32((s.bp+0x00000418u));
  }
  L0044e163: { // 0x44e163: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0044e169: { // 0x44e169: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e16b: { // 0x44e16b: 0f84df000000 JZ 0x44e250
    if(integer::condition("JZ",flags)) goto L0044e250;
  }
  L0044e171: { // 0x44e171: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0044e175: { // 0x44e175: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e176: { // 0x44e176: 8d8de0020000 LEA ECX, [EBP + 0x2e0]
    s.cx = (s.bp+0x000002e0u);
  }
  L0044e17c: { // 0x44e17c: e8cfa60600 CALL 0x4b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4514177u); flags=s.arithmetic_flags;
  }
  L0044e181: { // 0x44e181: 8b30 MOV ESI, dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0044e183: { // 0x44e183: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0044e185: { // 0x44e185: c1ee0c SHR ESI, 0xc
    s.si = integer::shift(s.si,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044e188: { // 0x44e188: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0044e189: { // 0x44e189: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044e18b: { // 0x44e18b: d1ee SHR ESI, 1
    s.si = integer::shift(s.si,1u,32,flags,integer::Shift::right);
  }
  L0044e18d: { // 0x44e18d: 83e603 AND ESI, 3
    s.si = integer::logical((s.si)&(3u),32,flags);
  }
  L0044e190: { // 0x44e190: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0044e194: { // 0x44e194: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L0044e196: { // 0x44e196: 83e207 AND EDX, 7
    s.dx = integer::logical((s.dx)&(7u),32,flags);
  }
  L0044e199: { // 0x44e199: 668b0c95a09d8300 MOV CX, word ptr [EDX*4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 4u)+0x00839da0u)));
  }
  L0044e1a1: { // 0x44e1a1: 8d3c95a09d8300 LEA EDI, [EDX*4 + 0x839da0]
    s.di = ((s.dx * 4u)+0x00839da0u);
  }
  L0044e1a8: { // 0x44e1a8: 6603c8 ADD CX, AX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0044e1ab: { // 0x44e1ab: 668b5702 MOV DX, word ptr [EDI + 2]
    s.dx = with_ax(s.dx, m.r16((s.di+2u)));
  }
  L0044e1af: { // 0x44e1af: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0044e1b4: { // 0x44e1b4: 6603542416 ADD DX, word ptr [ESP + 0x16]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0044e1b9: { // 0x44e1b9: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0044e1be: { // 0x44e1be: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0044e1c2: { // 0x44e1c2: 663bc8 CMP CX, AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0044e1c5: { // 0x44e1c5: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0044e1c9: { // 0x44e1c9: 750c JNZ 0x44e1d7
    if(integer::condition("JNZ",flags)) goto L0044e1d7;
  }
  L0044e1cb: { // 0x44e1cb: 668b442416 MOV AX, word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000016u)));
  }
  L0044e1d0: { // 0x44e1d0: 6639442412 CMP word ptr [ESP + 0x12], AX
    (void)integer::sub(m.r16((f.sp+0x00000012u)),(s.ax & 0xffffu),16,flags);
  }
  L0044e1d5: { // 0x44e1d5: 746a JZ 0x44e241
    if(integer::condition("JZ",flags)) goto L0044e241;
  }
  L0044e1d7: { // 0x44e1d7: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0044e1db: { // 0x44e1db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e1dc: { // 0x44e1dc: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e1e1: { // 0x44e1e1: e81a730f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4514278u); flags=s.arithmetic_flags;
  }
  L0044e1e6: { // 0x44e1e6: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044e1e8: { // 0x44e1e8: e8c3310200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4514285u); flags=s.arithmetic_flags;
  }
  L0044e1ed: { // 0x44e1ed: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0044e1ef: { // 0x44e1ef: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0044e1f1: { // 0x44e1f1: 7452 JZ 0x44e245
    if(integer::condition("JZ",flags)) goto L0044e245;
  }
  L0044e1f3: { // 0x44e1f3: 8b8318040000 MOV EAX, dword ptr [EBX + 0x418]
    s.ax = m.r32((s.bx+0x00000418u));
  }
  L0044e1f9: { // 0x44e1f9: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044e1ff: { // 0x44e1ff: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e201: { // 0x44e201: 7531 JNZ 0x44e234
    if(integer::condition("JNZ",flags)) goto L0044e234;
  }
  L0044e203: { // 0x44e203: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0044e209: { // 0x44e209: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e20b: { // 0x44e20b: 7438 JZ 0x44e245
    if(integer::condition("JZ",flags)) goto L0044e245;
  }
  L0044e20d: { // 0x44e20d: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044e211: { // 0x44e211: 668b17 MOV DX, word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0044e214: { // 0x44e214: 668b4f02 MOV CX, word ptr [EDI + 2]
    s.cx = with_ax(s.cx, m.r16((s.di+2u)));
  }
  L0044e218: { // 0x44e218: 6603d0 ADD DX, AX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0044e21b: { // 0x44e21b: 66034c2412 ADD CX, word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L0044e220: { // 0x44e220: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0044e225: { // 0x44e225: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0044e229: { // 0x44e229: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0044e22e: { // 0x44e22e: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0044e232: { // 0x44e232: eb8e JMP 0x44e1c2
    goto L0044e1c2;
  }
  L0044e234: { // 0x44e234: 83ce04 OR ESI, 4
    s.si = integer::logical((s.si)|(4u),32,flags);
  }
  L0044e237: { // 0x44e237: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e239: { // 0x44e239: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044e23a: { // 0x44e23a: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044e23c: { // 0x44e23c: e80ffdffff CALL 0x44df50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044df50u,4514369u); flags=s.arithmetic_flags;
  }
  L0044e241: { // 0x44e241: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0044e243: { // 0x44e243: 750b JNZ 0x44e250
    if(integer::condition("JNZ",flags)) goto L0044e250;
  }
  L0044e245: { // 0x44e245: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0044e248: { // 0x44e248: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L0044e24a: { // 0x44e24a: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),4514384u); flags=s.arithmetic_flags;
  }
  L0044e250: { // 0x44e250: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044e251: { // 0x44e251: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044e252: { // 0x44e252: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044e253: { // 0x44e253: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044e254: { // 0x44e254: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0044e257: { // 0x44e257: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00167270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00567270: { // 0x567270: 83ec28 SUB ESP, 0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00567273: { // 0x567273: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00567274: { // 0x567274: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00567275: { // 0x567275: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00567277: { // 0x567277: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00567278: { // 0x567278: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00567279: { // 0x567279: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056727d: { // 0x56727d: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00567281: { // 0x567281: 8b6c2444 MOV EBP, dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00567285: { // 0x567285: c744241400000000 MOV dword ptr [ESP + 0x14], 0
    m.w32((f.sp+0x00000014u), 0u);
  }
  L0056728d: { // 0x56728d: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0056728f: { // 0x56728f: 8b8504050000 MOV EAX, dword ptr [EBP + 0x504]
    s.ax = m.r32((s.bp+0x00000504u));
  }
  L00567295: { // 0x567295: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00567298: { // 0x567298: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056729a: { // 0x56729a: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0056729e: { // 0x56729e: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005672a2: { // 0x5672a2: 0f8e88010000 JLE 0x567430
    if(integer::condition("JLE",flags)) goto L00567430;
  }
  L005672a8: { // 0x5672a8: 83e107 AND ECX, 7
    s.cx = integer::logical((s.cx)&(7u),32,flags);
  }
  L005672ab: { // 0x5672ab: 8d3c8da09d8300 LEA EDI, [ECX*4 + 0x839da0]
    s.di = ((s.cx * 4u)+0x00839da0u);
  }
  L005672b2: { // 0x5672b2: 668b4f02 MOV CX, word ptr [EDI + 2]
    s.cx = with_ax(s.cx, m.r16((s.di+2u)));
  }
  L005672b6: { // 0x5672b6: 668b07 MOV AX, word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L005672b9: { // 0x5672b9: 66034c2412 ADD CX, word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L005672be: { // 0x5672be: 6603442410 ADD AX, word ptr [ESP + 0x10]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  L005672c3: { // 0x5672c3: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L005672c8: { // 0x5672c8: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L005672cd: { // 0x5672cd: 8b5c2418 MOV EBX, dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L005672d1: { // 0x5672d1: 0fbfc9 MOVSX ECX, CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005672d4: { // 0x5672d4: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005672d7: { // 0x5672d7: c1e109 SHL ECX, 9
    s.cx = integer::shift(s.cx,9u,32,flags,integer::Shift::left);
  }
  L005672da: { // 0x5672da: 895c2410 MOV dword ptr [ESP + 0x10], EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005672de: { // 0x5672de: 8d3411 LEA ESI, [ECX + EDX]
    s.si = (s.cx+s.dx);
  }
  L005672e1: { // 0x5672e1: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005672e3: { // 0x5672e3: 7c14 JL 0x5672f9
    if(integer::condition("JL",flags)) goto L005672f9;
  }
  L005672e5: { // 0x5672e5: 81fe00000400 CMP ESI, 0x40000
    (void)integer::sub(s.si,0x00040000u,32,flags);
  }
  L005672eb: { // 0x5672eb: 7d0c JGE 0x5672f9
    if(integer::condition("JGE",flags)) goto L005672f9;
  }
  L005672ed: { // 0x5672ed: a158a98100 MOV EAX, dword ptr [0x81a958]
    s.ax = m.r32((0x0081a958u));
  }
  L005672f2: { // 0x5672f2: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L005672f5: { // 0x5672f5: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005672f7: { // 0x5672f7: 750b JNZ 0x567304
    if(integer::condition("JNZ",flags)) goto L00567304;
  }
  L005672f9: { // 0x5672f9: 891d3476a500 MOV dword ptr [0xa57634], EBX
    m.w32((0x00a57634u), s.bx);
  }
  L005672ff: { // 0x5672ff: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L00567304: { // 0x567304: e8a7a0f0ff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,5665545u); flags=s.arithmetic_flags;
  }
  L00567309: { // 0x567309: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056730b: { // 0x56730b: 741e JZ 0x56732b
    if(integer::condition("JZ",flags)) goto L0056732b;
  }
  L0056730d: { // 0x56730d: 8b8818040000 MOV ECX, dword ptr [EAX + 0x418]
    s.cx = m.r32((s.ax+0x00000418u));
  }
  L00567313: { // 0x567313: 8a915a130000 MOV DL, byte ptr [ECX + 0x135a]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000135au)));
  }
  L00567319: { // 0x567319: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0056731b: { // 0x56731b: 740e JZ 0x56732b
    if(integer::condition("JZ",flags)) goto L0056732b;
  }
  L0056731d: { // 0x56731d: 8b90b4010000 MOV EDX, dword ptr [EAX + 0x1b4]
    s.dx = m.r32((s.ax+0x000001b4u));
  }
  L00567323: { // 0x567323: 8b442440 MOV EAX, dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00567327: { // 0x567327: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00567329: { // 0x567329: 745b JZ 0x567386
    if(integer::condition("JZ",flags)) goto L00567386;
  }
  L0056732b: { // 0x56732b: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0056732d: { // 0x56732d: 7c18 JL 0x567347
    if(integer::condition("JL",flags)) goto L00567347;
  }
  L0056732f: { // 0x56732f: 81fe00000400 CMP ESI, 0x40000
    (void)integer::sub(s.si,0x00040000u,32,flags);
  }
  L00567335: { // 0x567335: 7d10 JGE 0x567347
    if(integer::condition("JGE",flags)) goto L00567347;
  }
  L00567337: { // 0x567337: a158a98100 MOV EAX, dword ptr [0x81a958]
    s.ax = m.r32((0x0081a958u));
  }
  L0056733c: { // 0x56733c: 8b34b0 MOV ESI, dword ptr [EAX + ESI*4]
    s.si = m.r32((s.ax+(s.si * 4u)));
  }
  L0056733f: { // 0x56733f: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00567341: { // 0x567341: 7404 JZ 0x567347
    if(integer::condition("JZ",flags)) goto L00567347;
  }
  L00567343: { // 0x567343: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00567345: { // 0x567345: eb0b JMP 0x567352
    goto L00567352;
  }
  L00567347: { // 0x567347: 891d3476a500 MOV dword ptr [0xa57634], EBX
    m.w32((0x00a57634u), s.bx);
  }
  L0056734d: { // 0x56734d: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L00567352: { // 0x567352: 8b542440 MOV EDX, dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00567356: { // 0x567356: 8b85a4050000 MOV EAX, dword ptr [EBP + 0x5a4]
    s.ax = m.r32((s.bp+0x000005a4u));
  }
  L0056735c: { // 0x56735c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056735d: { // 0x56735d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056735e: { // 0x56735e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056735f: { // 0x56735f: e84ca1f0ff CALL 0x4714b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004714b0u,5665636u); flags=s.arithmetic_flags;
  }
  L00567364: { // 0x567364: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00567366: { // 0x567366: 0f84c4000000 JZ 0x567430
    if(integer::condition("JZ",flags)) goto L00567430;
  }
  L0056736c: { // 0x56736c: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00567370: { // 0x567370: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00567374: { // 0x567374: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00567375: { // 0x567375: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00567377: { // 0x567377: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0056737b: { // 0x56737b: 0f8c31ffffff JL 0x5672b2
    if(integer::condition("JL",flags)) goto L005672b2;
  }
  L00567381: { // 0x567381: e9aa000000 JMP 0x567430
    goto L00567430;
  }
  L00567386: { // 0x567386: 8b5c2414 MOV EBX, dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0056738a: { // 0x56738a: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0056738c: { // 0x56738c: 0f8e9e000000 JLE 0x567430
    if(integer::condition("JLE",flags)) goto L00567430;
  }
  L00567392: { // 0x567392: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00567396: { // 0x567396: 668b5702 MOV DX, word ptr [EDI + 2]
    s.dx = with_ax(s.dx, m.r16((s.di+2u)));
  }
  L0056739a: { // 0x56739a: 668b08 MOV CX, word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L0056739d: { // 0x56739d: 66035002 ADD DX, word ptr [EAX + 2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.ax+2u)),16,flags));
  }
  L005673a1: { // 0x5673a1: 66030f ADD CX, word ptr [EDI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.di)),16,flags));
  }
  L005673a4: { // 0x5673a4: 668954241e MOV word ptr [ESP + 0x1e], DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L005673a9: { // 0x5673a9: 66894c241c MOV word ptr [ESP + 0x1c], CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L005673ae: { // 0x5673ae: 8b74241c MOV ESI, dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L005673b2: { // 0x5673b2: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005673b4: { // 0x5673b4: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L005673b8: { // 0x5673b8: 7e76 JLE 0x567430
    if(integer::condition("JLE",flags)) goto L00567430;
  }
  L005673ba: { // 0x5673ba: eb04 JMP 0x5673c0
    goto L005673c0;
  }
  L005673bc: { // 0x5673bc: 8b6c2444 MOV EBP, dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L005673c0: { // 0x5673c0: 8b4c2440 MOV ECX, dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L005673c4: { // 0x5673c4: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005673c7: { // 0x5673c7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005673c8: { // 0x5673c8: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005673ca: { // 0x5673ca: ff908c000000 CALL dword ptr [EAX + 0x8c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000008cu)),5665744u); flags=s.arithmetic_flags;
  }
  L005673d0: { // 0x5673d0: 668b6c2416 MOV BP, word ptr [ESP + 0x16]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((f.sp+0x00000016u))) & 0xffffu);
  }
  L005673d5: { // 0x5673d5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005673d7: { // 0x5673d7: 0fbfcd MOVSX ECX, BP
    s.cx = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L005673da: { // 0x5673da: 0fbfd6 MOVSX EDX, SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005673dd: { // 0x5673dd: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L005673e0: { // 0x5673e0: c1e208 SHL EDX, 8
    s.dx = integer::shift(s.dx,8u,32,flags,integer::Shift::left);
  }
  L005673e3: { // 0x5673e3: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L005673e9: { // 0x5673e9: 81c280000000 ADD EDX, 0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L005673ef: { // 0x5673ef: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L005673f3: { // 0x5673f3: 8d4c2430 LEA ECX, [ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L005673f7: { // 0x5673f7: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L005673fb: { // 0x5673fb: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005673fd: { // 0x5673fd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005673fe: { // 0x5673fe: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00567400: { // 0x567400: c744243c00000000 MOV dword ptr [ESP + 0x3c], 0
    m.w32((f.sp+0x0000003cu), 0u);
  }
  L00567408: { // 0x567408: ff92d4000000 CALL dword ptr [EDX + 0xd4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d4u)),5665806u); flags=s.arithmetic_flags;
  }
  L0056740e: { // 0x56740e: 668b17 MOV DX, word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00567411: { // 0x567411: 668b4702 MOV AX, word ptr [EDI + 2]
    s.ax = with_ax(s.ax, m.r16((s.di+2u)));
  }
  L00567415: { // 0x567415: 6603d6 ADD DX, SI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L00567418: { // 0x567418: 6603c5 ADD AX, BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L0056741b: { // 0x56741b: 6689542420 MOV word ptr [ESP + 0x20], DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L00567420: { // 0x567420: 6689442422 MOV word ptr [ESP + 0x22], AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L00567425: { // 0x567425: 8b742420 MOV ESI, dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L00567429: { // 0x567429: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0056742a: { // 0x56742a: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0056742e: { // 0x56742e: 758c JNZ 0x5673bc
    if(integer::condition("JNZ",flags)) goto L005673bc;
  }
  L00567430: { // 0x567430: 8b4c2424 MOV ECX, dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00567434: { // 0x567434: 83c102 ADD ECX, 2
    s.cx = integer::add(s.cx,2u,32,flags);
  }
  L00567437: { // 0x567437: 83f908 CMP ECX, 8
    (void)integer::sub(s.cx,8u,32,flags);
  }
  L0056743a: { // 0x56743a: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056743e: { // 0x56743e: 0f8c39feffff JL 0x56727d
    if(integer::condition("JL",flags)) goto L0056727d;
  }
  L00567444: { // 0x567444: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00567445: { // 0x567445: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00567446: { // 0x567446: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00567447: { // 0x567447: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00567448: { // 0x567448: 83c428 ADD ESP, 0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L0056744b: { // 0x56744b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00167450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00567450: { // 0x567450: 83ec2c SUB ESP, 0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L00567453: { // 0x567453: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00567454: { // 0x567454: 8b7c243c MOV EDI, dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L00567458: { // 0x567458: 8b87ec0b0000 MOV EAX, dword ptr [EDI + 0xbec]
    s.ax = m.r32((s.di+0x00000becu));
  }
  L0056745e: { // 0x56745e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00567460: { // 0x567460: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00567464: { // 0x567464: 0f84e2010000 JZ 0x56764c
    if(integer::condition("JZ",flags)) goto L0056764c;
  }
  L0056746a: { // 0x56746a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056746b: { // 0x56746b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056746d: { // 0x56746d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056746e: { // 0x56746e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056746f: { // 0x56746f: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00567473: { // 0x567473: 8b4c2440 MOV ECX, dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00567477: { // 0x567477: 8baf04050000 MOV EBP, dword ptr [EDI + 0x504]
    s.bp = m.r32((s.di+0x00000504u));
  }
  L0056747d: { // 0x56747d: c1fd08 SAR EBP, 8
    s.bp = integer::shift(s.bp,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00567480: { // 0x567480: 8b31 MOV ESI, dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00567482: { // 0x567482: 896c241c MOV dword ptr [ESP + 0x1c], EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00567486: { // 0x567486: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00567488: { // 0x567488: 89742418 MOV dword ptr [ESP + 0x18], ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0056748c: { // 0x56748c: c744241000000000 MOV dword ptr [ESP + 0x10], 0
    m.w32((f.sp+0x00000010u), 0u);
  }
  L00567494: { // 0x567494: 0f8e9b010000 JLE 0x567635
    if(integer::condition("JLE",flags)) goto L00567635;
  }
  L0056749a: { // 0x56749a: 83e007 AND EAX, 7
    s.ax = integer::logical((s.ax)&(7u),32,flags);
  }
  L0056749d: { // 0x56749d: 8d1c85a09d8300 LEA EBX, [EAX*4 + 0x839da0]
    s.bx = ((s.ax * 4u)+0x00839da0u);
  }
  L005674a4: { // 0x5674a4: 668b4b02 MOV CX, word ptr [EBX + 2]
    s.cx = with_ax(s.cx, m.r16((s.bx+2u)));
  }
  L005674a8: { // 0x5674a8: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L005674ab: { // 0x5674ab: 66034c241a ADD CX, word ptr [ESP + 0x1a]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000001au)),16,flags));
  }
  L005674b0: { // 0x5674b0: 6603c6 ADD AX, SI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L005674b3: { // 0x5674b3: 6689442414 MOV word ptr [ESP + 0x14], AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L005674b8: { // 0x5674b8: 66894c2416 MOV word ptr [ESP + 0x16], CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L005674bd: { // 0x5674bd: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005674c1: { // 0x5674c1: 0fbfc9 MOVSX ECX, CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005674c4: { // 0x5674c4: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005674c7: { // 0x5674c7: c1e109 SHL ECX, 9
    s.cx = integer::shift(s.cx,9u,32,flags,integer::Shift::left);
  }
  L005674ca: { // 0x5674ca: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005674cc: { // 0x5674cc: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L005674ce: { // 0x5674ce: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005674d0: { // 0x5674d0: 89742418 MOV dword ptr [ESP + 0x18], ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L005674d4: { // 0x5674d4: 7c14 JL 0x5674ea
    if(integer::condition("JL",flags)) goto L005674ea;
  }
  L005674d6: { // 0x5674d6: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005674db: { // 0x5674db: 7d0d JGE 0x5674ea
    if(integer::condition("JGE",flags)) goto L005674ea;
  }
  L005674dd: { // 0x5674dd: 8b0d58a98100 MOV ECX, dword ptr [0x81a958]
    s.cx = m.r32((0x0081a958u));
  }
  L005674e3: { // 0x5674e3: 8b0c81 MOV ECX, dword ptr [ECX + EAX*4]
    s.cx = m.r32((s.cx+(s.ax * 4u)));
  }
  L005674e6: { // 0x5674e6: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005674e8: { // 0x5674e8: 750b JNZ 0x5674f5
    if(integer::condition("JNZ",flags)) goto L005674f5;
  }
  L005674ea: { // 0x5674ea: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005674f0: { // 0x5674f0: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L005674f5: { // 0x5674f5: 8b4944 MOV ECX, dword ptr [ECX + 0x44]
    s.cx = m.r32((s.cx+0x00000044u));
  }
  L005674f8: { // 0x5674f8: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L005674fb: { // 0x5674fb: 743f JZ 0x56753c
    if(integer::condition("JZ",flags)) goto L0056753c;
  }
  L005674fd: { // 0x5674fd: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L00567501: { // 0x567501: 398d64020000 CMP dword ptr [EBP + 0x264], ECX
    (void)integer::sub(m.r32((s.bp+0x00000264u)),s.cx,32,flags);
  }
  L00567507: { // 0x567507: 752f JNZ 0x567538
    if(integer::condition("JNZ",flags)) goto L00567538;
  }
  L00567509: { // 0x567509: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056750b: { // 0x56750b: 7c14 JL 0x567521
    if(integer::condition("JL",flags)) goto L00567521;
  }
  L0056750d: { // 0x56750d: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00567512: { // 0x567512: 7d0d JGE 0x567521
    if(integer::condition("JGE",flags)) goto L00567521;
  }
  L00567514: { // 0x567514: 8b0d58a98100 MOV ECX, dword ptr [0x81a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0056751a: { // 0x56751a: 8b0c81 MOV ECX, dword ptr [ECX + EAX*4]
    s.cx = m.r32((s.cx+(s.ax * 4u)));
  }
  L0056751d: { // 0x56751d: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0056751f: { // 0x56751f: 750b JNZ 0x56752c
    if(integer::condition("JNZ",flags)) goto L0056752c;
  }
  L00567521: { // 0x567521: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00567527: { // 0x567527: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L0056752c: { // 0x56752c: 8b6c2444 MOV EBP, dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00567530: { // 0x567530: 8b6d30 MOV EBP, dword ptr [EBP + 0x30]
    s.bp = m.r32((s.bp+0x00000030u));
  }
  L00567533: { // 0x567533: 3b6950 CMP EBP, dword ptr [ECX + 0x50]
    (void)integer::sub(s.bp,m.r32((s.cx+0x00000050u)),32,flags);
  }
  L00567536: { // 0x567536: 7459 JZ 0x567591
    if(integer::condition("JZ",flags)) goto L00567591;
  }
  L00567538: { // 0x567538: 8b6c241c MOV EBP, dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L0056753c: { // 0x56753c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056753e: { // 0x56753e: 7c14 JL 0x567554
    if(integer::condition("JL",flags)) goto L00567554;
  }
  L00567540: { // 0x567540: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00567545: { // 0x567545: 7d0d JGE 0x567554
    if(integer::condition("JGE",flags)) goto L00567554;
  }
  L00567547: { // 0x567547: 8b0d58a98100 MOV ECX, dword ptr [0x81a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0056754d: { // 0x56754d: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00567550: { // 0x567550: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00567552: { // 0x567552: 750b JNZ 0x56755f
    if(integer::condition("JNZ",flags)) goto L0056755f;
  }
  L00567554: { // 0x567554: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0056755a: { // 0x56755a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0056755f: { // 0x56755f: 8b542444 MOV EDX, dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00567563: { // 0x567563: 8b8fa4050000 MOV ECX, dword ptr [EDI + 0x5a4]
    s.cx = m.r32((s.di+0x000005a4u));
  }
  L00567569: { // 0x567569: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056756a: { // 0x56756a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056756b: { // 0x56756b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056756c: { // 0x56756c: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0056756e: { // 0x56756e: e83d9ff0ff CALL 0x4714b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004714b0u,5666163u); flags=s.arithmetic_flags;
  }
  L00567573: { // 0x567573: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00567575: { // 0x567575: 0f84ba000000 JZ 0x567635
    if(integer::condition("JZ",flags)) goto L00567635;
  }
  L0056757b: { // 0x56757b: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0056757f: { // 0x56757f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00567580: { // 0x567580: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00567582: { // 0x567582: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00567586: { // 0x567586: 0f8c18ffffff JL 0x5674a4
    if(integer::condition("JL",flags)) goto L005674a4;
  }
  L0056758c: { // 0x56758c: e9a4000000 JMP 0x567635
    goto L00567635;
  }
  L00567591: { // 0x567591: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00567595: { // 0x567595: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00567597: { // 0x567597: 0f8e98000000 JLE 0x567635
    if(integer::condition("JLE",flags)) goto L00567635;
  }
  L0056759d: { // 0x56759d: 8b442440 MOV EAX, dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L005675a1: { // 0x5675a1: 668b13 MOV DX, word ptr [EBX]
    s.dx = with_ax(s.dx, m.r16((s.bx)));
  }
  L005675a4: { // 0x5675a4: 668b4b02 MOV CX, word ptr [EBX + 2]
    s.cx = with_ax(s.cx, m.r16((s.bx+2u)));
  }
  L005675a8: { // 0x5675a8: 660310 ADD DX, word ptr [EAX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.ax)),16,flags));
  }
  L005675ab: { // 0x5675ab: 66034802 ADD CX, word ptr [EAX + 2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.ax+2u)),16,flags));
  }
  L005675af: { // 0x5675af: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L005675b1: { // 0x5675b1: 6689542420 MOV word ptr [ESP + 0x20], DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L005675b6: { // 0x5675b6: 66894c2422 MOV word ptr [ESP + 0x22], CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  L005675bb: { // 0x5675bb: 8b742420 MOV ESI, dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L005675bf: { // 0x5675bf: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L005675c3: { // 0x5675c3: 7e70 JLE 0x567635
    if(integer::condition("JLE",flags)) goto L00567635;
  }
  L005675c5: { // 0x5675c5: 8b442444 MOV EAX, dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005675c9: { // 0x5675c9: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005675cb: { // 0x5675cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005675cc: { // 0x5675cc: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005675ce: { // 0x5675ce: ff928c000000 CALL dword ptr [EDX + 0x8c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000008cu)),5666260u); flags=s.arithmetic_flags;
  }
  L005675d4: { // 0x5675d4: 668b7c241e MOV DI, word ptr [ESP + 0x1e]
    s.di = (s.di & 0xffff0000u) | ((m.r16((f.sp+0x0000001eu))) & 0xffffu);
  }
  L005675d9: { // 0x5675d9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005675db: { // 0x5675db: 0fbfce MOVSX ECX, SI
    s.cx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005675de: { // 0x5675de: 0fbfd7 MOVSX EDX, DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L005675e1: { // 0x5675e1: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L005675e4: { // 0x5675e4: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L005675ea: { // 0x5675ea: c744243c00000000 MOV dword ptr [ESP + 0x3c], 0
    m.w32((f.sp+0x0000003cu), 0u);
  }
  L005675f2: { // 0x5675f2: c1e208 SHL EDX, 8
    s.dx = integer::shift(s.dx,8u,32,flags,integer::Shift::left);
  }
  L005675f5: { // 0x5675f5: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L005675f9: { // 0x5675f9: 81c280000000 ADD EDX, 0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L005675ff: { // 0x5675ff: 8d4c2434 LEA ECX, [ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L00567603: { // 0x567603: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00567607: { // 0x567607: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00567609: { // 0x567609: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056760a: { // 0x56760a: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0056760c: { // 0x56760c: ff92d4000000 CALL dword ptr [EDX + 0xd4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d4u)),5666322u); flags=s.arithmetic_flags;
  }
  L00567612: { // 0x567612: 668b5302 MOV DX, word ptr [EBX + 2]
    s.dx = with_ax(s.dx, m.r16((s.bx+2u)));
  }
  L00567616: { // 0x567616: 660333 ADD SI, word ptr [EBX]
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),m.r16((s.bx)),16,flags)) & 0xffffu);
  }
  L00567619: { // 0x567619: 6603d7 ADD DX, DI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L0056761c: { // 0x56761c: 8b7c2448 MOV EDI, dword ptr [ESP + 0x48]
    s.di = m.r32((f.sp+0x00000048u));
  }
  L00567620: { // 0x567620: 6689742424 MOV word ptr [ESP + 0x24], SI
    m.w16((f.sp+0x00000024u), (s.si & 0xffffu));
  }
  L00567625: { // 0x567625: 6689542426 MOV word ptr [ESP + 0x26], DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L0056762a: { // 0x56762a: 8b742424 MOV ESI, dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0056762e: { // 0x56762e: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0056762f: { // 0x56762f: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L00567633: { // 0x567633: 7590 JNZ 0x5675c5
    if(integer::condition("JNZ",flags)) goto L005675c5;
  }
  L00567635: { // 0x567635: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00567639: { // 0x567639: 83c002 ADD EAX, 2
    s.ax = integer::add(s.ax,2u,32,flags);
  }
  L0056763c: { // 0x56763c: 83f808 CMP EAX, 8
    (void)integer::sub(s.ax,8u,32,flags);
  }
  L0056763f: { // 0x56763f: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00567643: { // 0x567643: 0f8c2afeffff JL 0x567473
    if(integer::condition("JL",flags)) goto L00567473;
  }
  L00567649: { // 0x567649: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056764a: { // 0x56764a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056764b: { // 0x56764b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056764c: { // 0x56764c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056764d: { // 0x56764d: 83c42c ADD ESP, 0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L00567650: { // 0x567650: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
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
void f_000713b0(Memory& m,State& s,Frame& f,const Operations& op) { if(m.r8(0xa285a8u)==0u||m.r32(s.cx+0xe4u)!=0u)throw std::domain_error("B1515 requires713B0 enabledemptylist");
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
void f_000714b0(Memory& m,State& s,Frame& f,const Operations& op) { if(m.r32(0xa283c4u)==0u)throw std::domain_error("B1515 requires714B0 genuineoverride");
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004714b0: { // 0x4714b0: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004714b5: { // 0x4714b5: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L004714b8: { // 0x4714b8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004714b9: { // 0x4714b9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004714ba: { // 0x4714ba: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004714bc: { // 0x4714bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004714bd: { // 0x4714bd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004714be: { // 0x4714be: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L004714c0: { // 0x4714c0: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L004714c2: { // 0x4714c2: 0f8538040000 JNZ 0x471900
    if(integer::condition("JNZ",flags)) goto L00471900;
  }
  L004714c8: { // 0x4714c8: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004714cc: { // 0x4714cc: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L004714ce: { // 0x4714ce: 7460 JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L004714d0: { // 0x4714d0: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L004714d6: { // 0x4714d6: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004714d8: { // 0x4714d8: 0f848f000000 JZ 0x47156d
    if(integer::condition("JZ",flags)) goto L0047156d;
  }
  L004714de: { // 0x4714de: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004714e3: { // 0x4714e3: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004714e5: { // 0x4714e5: 7449 JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L004714e7: { // 0x4714e7: 8bb7e4000000 MOV ESI, dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L004714ed: { // 0x4714ed: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L004714ef: { // 0x4714ef: 7419 JZ 0x47150a
    if(integer::condition("JZ",flags)) goto L0047150a;
  }
  L004714f1: { // 0x4714f1: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004714f3: { // 0x4714f3: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004714f5: { // 0x4714f5: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658424u); flags=s.arithmetic_flags;
  }
  L004714f8: { // 0x4714f8: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L004714fb: { // 0x4714fb: 7409 JZ 0x471506
    if(integer::condition("JZ",flags)) goto L00471506;
  }
  L004714fd: { // 0x4714fd: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00471500: { // 0x471500: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00471502: { // 0x471502: 75ed JNZ 0x4714f1
    if(integer::condition("JNZ",flags)) goto L004714f1;
  }
  L00471504: { // 0x471504: eb04 JMP 0x47150a
    goto L0047150a;
  }
  L00471506: { // 0x471506: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00471508: { // 0x471508: 7557 JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L0047150a: { // 0x47150a: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L0047150f: { // 0x47150f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471511: { // 0x471511: 741d JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L00471513: { // 0x471513: 8bb7e4000000 MOV ESI, dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L00471519: { // 0x471519: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0047151b: { // 0x47151b: 7413 JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L0047151d: { // 0x47151d: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0047151f: { // 0x47151f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00471521: { // 0x471521: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4658468u); flags=s.arithmetic_flags;
  }
  L00471524: { // 0x471524: 83f824 CMP EAX, 0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L00471527: { // 0x471527: 7434 JZ 0x47155d
    if(integer::condition("JZ",flags)) goto L0047155d;
  }
  L00471529: { // 0x471529: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047152c: { // 0x47152c: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0047152e: { // 0x47152e: 75ed JNZ 0x47151d
    if(integer::condition("JNZ",flags)) goto L0047151d;
  }
  L00471530: { // 0x471530: a05389a200 MOV AL, byte ptr [0xa28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L00471535: { // 0x471535: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471537: { // 0x471537: 0f84cb010000 JZ 0x471708
    if(integer::condition("JZ",flags)) goto L00471708;
  }
  L0047153d: { // 0x47153d: 8d4724 LEA EAX, [EDI + 0x24]
    s.ax = (s.di+0x00000024u);
  }
  L00471540: { // 0x471540: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00471545: { // 0x471545: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00471546: { // 0x471546: e8f5690d00 CALL 0x547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,4658507u); flags=s.arithmetic_flags;
  }
  L0047154b: { // 0x47154b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047154d: { // 0x47154d: 0f85ca010000 JNZ 0x47171d
    if(integer::condition("JNZ",flags)) goto L0047171d;
  }
  L00471553: { // 0x471553: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471554: { // 0x471554: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471555: { // 0x471555: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471556: { // 0x471556: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471557: { // 0x471557: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0047155a: { // 0x47155a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047155d: { // 0x47155d: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0047155f: { // 0x47155f: 74cf JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L00471561: { // 0x471561: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471562: { // 0x471562: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471563: { // 0x471563: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471564: { // 0x471564: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00471566: { // 0x471566: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471567: { // 0x471567: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0047156a: { // 0x47156a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047156d: { // 0x47156d: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L00471573: { // 0x471573: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00471575: { // 0x471575: 0f85dd000000 JNZ 0x471658
    if(integer::condition("JNZ",flags)) goto L00471658;
  }
  L0047157b: { // 0x47157b: 8a8851130000 MOV CL, byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L00471581: { // 0x471581: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00471583: { // 0x471583: 0f85cf000000 JNZ 0x471658
    if(integer::condition("JNZ",flags)) goto L00471658;
  }
  L00471589: { // 0x471589: 39a8f00b0000 CMP dword ptr [EAX + 0xbf0], EBP
    (void)integer::sub(m.r32((s.ax+0x00000bf0u)),s.bp,32,flags);
  }
  L0047158f: { // 0x47158f: 756a JNZ 0x4715fb
    if(integer::condition("JNZ",flags)) goto L004715fb;
  }
  L00471591: { // 0x471591: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L00471596: { // 0x471596: 896c2410 MOV dword ptr [ESP + 0x10], EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0047159a: { // 0x47159a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047159c: { // 0x47159c: 896c2414 MOV dword ptr [ESP + 0x14], EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L004715a0: { // 0x4715a0: 741d JZ 0x4715bf
    if(integer::condition("JZ",flags)) goto L004715bf;
  }
  L004715a2: { // 0x4715a2: 8bb7e4000000 MOV ESI, dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L004715a8: { // 0x4715a8: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L004715aa: { // 0x4715aa: 7413 JZ 0x4715bf
    if(integer::condition("JZ",flags)) goto L004715bf;
  }
  L004715ac: { // 0x4715ac: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004715ae: { // 0x4715ae: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004715b0: { // 0x4715b0: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658611u); flags=s.arithmetic_flags;
  }
  L004715b3: { // 0x4715b3: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L004715b6: { // 0x4715b6: 743b JZ 0x4715f3
    if(integer::condition("JZ",flags)) goto L004715f3;
  }
  L004715b8: { // 0x4715b8: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004715bb: { // 0x4715bb: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L004715bd: { // 0x4715bd: 75ed JNZ 0x4715ac
    if(integer::condition("JNZ",flags)) goto L004715ac;
  }
  L004715bf: { // 0x4715bf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004715c0: { // 0x4715c0: 8d4c2414 LEA ECX, [ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004715c4: { // 0x4715c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004715c5: { // 0x4715c5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004715c6: { // 0x4715c6: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004715c8: { // 0x4715c8: e893fcffff CALL 0x471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4658637u); flags=s.arithmetic_flags;
  }
  L004715cd: { // 0x4715cd: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L004715cf: { // 0x4715cf: 0f850e010000 JNZ 0x4716e3
    if(integer::condition("JNZ",flags)) goto L004716e3;
  }
  L004715d5: { // 0x4715d5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004715d6: { // 0x4715d6: 6a24 PUSH 0x24
    f.push(m,0x00000024u);
  }
  L004715d8: { // 0x4715d8: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004715da: { // 0x4715da: e881fdffff CALL 0x471360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471360u,4658655u); flags=s.arithmetic_flags;
  }
  L004715df: { // 0x4715df: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L004715e1: { // 0x4715e1: 0f8408010000 JZ 0x4716ef
    if(integer::condition("JZ",flags)) goto L004716ef;
  }
  L004715e7: { // 0x4715e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004715e8: { // 0x4715e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004715e9: { // 0x4715e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004715ea: { // 0x4715ea: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004715ec: { // 0x4715ec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004715ed: { // 0x4715ed: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004715f0: { // 0x4715f0: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004715f3: { // 0x4715f3: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L004715f5: { // 0x4715f5: 74c8 JZ 0x4715bf
    if(integer::condition("JZ",flags)) goto L004715bf;
  }
  L004715f7: { // 0x4715f7: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L004715f9: { // 0x4715f9: ebe4 JMP 0x4715df
    goto L004715df;
  }
  L004715fb: { // 0x4715fb: 8b4738 MOV EAX, dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L004715fe: { // 0x4715fe: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00471600: { // 0x471600: 7c1f JL 0x471621
    if(integer::condition("JL",flags)) goto L00471621;
  }
  L00471602: { // 0x471602: 3b052089a200 CMP EAX, dword ptr [0xa28920]
    (void)integer::sub(s.ax,m.r32((0x00a28920u)),32,flags);
  }
  L00471608: { // 0x471608: 7d17 JGE 0x471621
    if(integer::condition("JGE",flags)) goto L00471621;
  }
  L0047160a: { // 0x47160a: 8b151489a200 MOV EDX, dword ptr [0xa28914]
    s.dx = m.r32((0x00a28914u));
  }
  L00471610: { // 0x471610: 8b0482 MOV EAX, dword ptr [EDX + EAX*4]
    s.ax = m.r32((s.dx+(s.ax * 4u)));
  }
  L00471613: { // 0x471613: 8a88b0020000 MOV CL, byte ptr [EAX + 0x2b0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000002b0u)));
  }
  L00471619: { // 0x471619: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047161b: { // 0x47161b: 0f84db000000 JZ 0x4716fc
    if(integer::condition("JZ",flags)) goto L004716fc;
  }
  L00471621: { // 0x471621: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L00471626: { // 0x471626: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471628: { // 0x471628: 0f8402ffffff JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L0047162e: { // 0x47162e: 8bb7e4000000 MOV ESI, dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L00471634: { // 0x471634: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00471636: { // 0x471636: 0f84f4feffff JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L0047163c: { // 0x47163c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0047163e: { // 0x47163e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00471640: { // 0x471640: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4658755u); flags=s.arithmetic_flags;
  }
  L00471643: { // 0x471643: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L00471646: { // 0x471646: 0f8411ffffff JZ 0x47155d
    if(integer::condition("JZ",flags)) goto L0047155d;
  }
  L0047164c: { // 0x47164c: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047164f: { // 0x47164f: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00471651: { // 0x471651: 75e9 JNZ 0x47163c
    if(integer::condition("JNZ",flags)) goto L0047163c;
  }
  L00471653: { // 0x471653: e9d8feffff JMP 0x471530
    goto L00471530;
  }
  L00471658: { // 0x471658: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L0047165d: { // 0x47165d: 896c2410 MOV dword ptr [ESP + 0x10], EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00471661: { // 0x471661: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471663: { // 0x471663: 896c2414 MOV dword ptr [ESP + 0x14], EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00471667: { // 0x471667: 7423 JZ 0x47168c
    if(integer::condition("JZ",flags)) goto L0047168c;
  }
  L00471669: { // 0x471669: 8bb7e4000000 MOV ESI, dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L0047166f: { // 0x47166f: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00471671: { // 0x471671: 7419 JZ 0x47168c
    if(integer::condition("JZ",flags)) goto L0047168c;
  }
  L00471673: { // 0x471673: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00471675: { // 0x471675: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00471677: { // 0x471677: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658810u); flags=s.arithmetic_flags;
  }
  L0047167a: { // 0x47167a: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L0047167d: { // 0x47167d: 7409 JZ 0x471688
    if(integer::condition("JZ",flags)) goto L00471688;
  }
  L0047167f: { // 0x47167f: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00471682: { // 0x471682: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00471684: { // 0x471684: 75ed JNZ 0x471673
    if(integer::condition("JNZ",flags)) goto L00471673;
  }
  L00471686: { // 0x471686: eb04 JMP 0x47168c
    goto L0047168c;
  }
  L00471688: { // 0x471688: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L0047168a: { // 0x47168a: 7522 JNZ 0x4716ae
    if(integer::condition("JNZ",flags)) goto L004716ae;
  }
  L0047168c: { // 0x47168c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0047168d: { // 0x47168d: 8d4c2414 LEA ECX, [ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00471691: { // 0x471691: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00471692: { // 0x471692: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00471693: { // 0x471693: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00471695: { // 0x471695: e8c6fbffff CALL 0x471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4658842u); flags=s.arithmetic_flags;
  }
  L0047169a: { // 0x47169a: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0047169c: { // 0x47169c: 750a JNZ 0x4716a8
    if(integer::condition("JNZ",flags)) goto L004716a8;
  }
  L0047169e: { // 0x47169e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0047169f: { // 0x47169f: 6a24 PUSH 0x24
    f.push(m,0x00000024u);
  }
  L004716a1: { // 0x4716a1: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004716a3: { // 0x4716a3: e8b8fcffff CALL 0x471360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471360u,4658856u); flags=s.arithmetic_flags;
  }
  L004716a8: { // 0x4716a8: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L004716aa: { // 0x4716aa: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L004716ac: { // 0x4716ac: 7441 JZ 0x4716ef
    if(integer::condition("JZ",flags)) goto L004716ef;
  }
  L004716ae: { // 0x4716ae: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004716b0: { // 0x4716b0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004716b2: { // 0x4716b2: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4658869u); flags=s.arithmetic_flags;
  }
  L004716b5: { // 0x4716b5: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L004716b8: { // 0x4716b8: 740c JZ 0x4716c6
    if(integer::condition("JZ",flags)) goto L004716c6;
  }
  L004716ba: { // 0x4716ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004716bb: { // 0x4716bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004716bc: { // 0x4716bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004716bd: { // 0x4716bd: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004716bf: { // 0x4716bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004716c0: { // 0x4716c0: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004716c3: { // 0x4716c3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004716c6: { // 0x4716c6: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L004716cc: { // 0x4716cc: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L004716d2: { // 0x4716d2: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004716d4: { // 0x4716d4: 740d JZ 0x4716e3
    if(integer::condition("JZ",flags)) goto L004716e3;
  }
  L004716d6: { // 0x4716d6: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004716d8: { // 0x4716d8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004716da: { // 0x4716da: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),4658909u); flags=s.arithmetic_flags;
  }
  L004716dd: { // 0x4716dd: 3b442424 CMP EAX, dword ptr [ESP + 0x24]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L004716e1: { // 0x4716e1: 740c JZ 0x4716ef
    if(integer::condition("JZ",flags)) goto L004716ef;
  }
  L004716e3: { // 0x4716e3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004716e4: { // 0x4716e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004716e5: { // 0x4716e5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004716e6: { // 0x4716e6: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004716e8: { // 0x4716e8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004716e9: { // 0x4716e9: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004716ec: { // 0x4716ec: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004716ef: { // 0x4716ef: f687240100003f TEST byte ptr [EDI + 0x124], 0x3f
    (void)integer::logical((m.r8((s.di+0x00000124u)))&(0x0000003fu),8,flags);
  }
  L004716f6: { // 0x4716f6: 0f8434feffff JZ 0x471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L004716fc: { // 0x4716fc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004716fd: { // 0x4716fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004716fe: { // 0x4716fe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004716ff: { // 0x4716ff: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00471701: { // 0x471701: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471702: { // 0x471702: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00471705: { // 0x471705: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00471708: { // 0x471708: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0047170a: { // 0x47170a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047170b: { // 0x47170b: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00471710: { // 0x471710: e81b5e0e00 CALL 0x557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,4658965u); flags=s.arithmetic_flags;
  }
  L00471715: { // 0x471715: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471717: { // 0x471717: 0f8444feffff JZ 0x471561
    if(integer::condition("JZ",flags)) goto L00471561;
  }
  L0047171d: { // 0x47171d: 8b4f44 MOV ECX, dword ptr [EDI + 0x44]
    s.cx = m.r32((s.di+0x00000044u));
  }
  L00471720: { // 0x471720: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L00471723: { // 0x471723: 0f8434010000 JZ 0x47185d
    if(integer::condition("JZ",flags)) goto L0047185d;
  }
  L00471729: { // 0x471729: 8b4750 MOV EAX, dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L0047172c: { // 0x47172c: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0047172e: { // 0x47172e: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00471730: { // 0x471730: 7c09 JL 0x47173b
    if(integer::condition("JL",flags)) goto L0047173b;
  }
  L00471732: { // 0x471732: 8b15cca5a100 MOV EDX, dword ptr [0xa1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  L00471738: { // 0x471738: 8b3482 MOV ESI, dword ptr [EDX + EAX*4]
    s.si = m.r32((s.dx+(s.ax * 4u)));
  }
  L0047173b: { // 0x47173b: 8b15881b8200 MOV EDX, dword ptr [0x821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L00471741: { // 0x471741: 83f902 CMP ECX, 2
    (void)integer::sub(s.cx,2u,32,flags);
  }
  L00471744: { // 0x471744: 7404 JZ 0x47174a
    if(integer::condition("JZ",flags)) goto L0047174a;
  }
  L00471746: { // 0x471746: 3bcd CMP ECX, EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00471748: { // 0x471748: 7549 JNZ 0x471793
    if(integer::condition("JNZ",flags)) goto L00471793;
  }
  L0047174a: { // 0x47174a: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0047174e: { // 0x47174e: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00471750: { // 0x471750: 7441 JZ 0x471793
    if(integer::condition("JZ",flags)) goto L00471793;
  }
  L00471752: { // 0x471752: 8b80ec0b0000 MOV EAX, dword ptr [EAX + 0xbec]
    s.ax = m.r32((s.ax+0x00000becu));
  }
  L00471758: { // 0x471758: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0047175a: { // 0x47175a: 7411 JZ 0x47176d
    if(integer::condition("JZ",flags)) goto L0047176d;
  }
  L0047175c: { // 0x47175c: 398864020000 CMP dword ptr [EAX + 0x264], ECX
    (void)integer::sub(m.r32((s.ax+0x00000264u)),s.cx,32,flags);
  }
  L00471762: { // 0x471762: 7509 JNZ 0x47176d
    if(integer::condition("JNZ",flags)) goto L0047176d;
  }
  L00471764: { // 0x471764: 80bf1e01000010 CMP byte ptr [EDI + 0x11e], 0x10
    (void)integer::sub(m.r8((s.di+0x0000011eu)),0x00000010u,8,flags);
  }
  L0047176b: { // 0x47176b: 731c JNC 0x471789
    if(integer::condition("JNC",flags)) goto L00471789;
  }
  L0047176d: { // 0x47176d: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00471771: { // 0x471771: 3b828c070000 CMP EAX, dword ptr [EDX + 0x78c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000078cu)),32,flags);
  }
  L00471777: { // 0x471777: 7410 JZ 0x471789
    if(integer::condition("JZ",flags)) goto L00471789;
  }
  L00471779: { // 0x471779: 3b827c070000 CMP EAX, dword ptr [EDX + 0x77c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000077cu)),32,flags);
  }
  L0047177f: { // 0x47177f: 7408 JZ 0x471789
    if(integer::condition("JZ",flags)) goto L00471789;
  }
  L00471781: { // 0x471781: 3b8280070000 CMP EAX, dword ptr [EDX + 0x780]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000780u)),32,flags);
  }
  L00471787: { // 0x471787: 750a JNZ 0x471793
    if(integer::condition("JNZ",flags)) goto L00471793;
  }
  L00471789: { // 0x471789: 3b742424 CMP ESI, dword ptr [ESP + 0x24]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L0047178d: { // 0x47178d: 0f846d010000 JZ 0x471900
    if(integer::condition("JZ",flags)) goto L00471900;
  }
  L00471793: { // 0x471793: 83f91a CMP ECX, 0x1a
    (void)integer::sub(s.cx,0x0000001au,32,flags);
  }
  L00471796: { // 0x471796: 7547 JNZ 0x4717df
    if(integer::condition("JNZ",flags)) goto L004717df;
  }
  L00471798: { // 0x471798: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0047179c: { // 0x47179c: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0047179e: { // 0x47179e: 0f8493000000 JZ 0x471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  L004717a4: { // 0x4717a4: 8b80ec0b0000 MOV EAX, dword ptr [EAX + 0xbec]
    s.ax = m.r32((s.ax+0x00000becu));
  }
  L004717aa: { // 0x4717aa: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L004717ac: { // 0x4717ac: 7411 JZ 0x4717bf
    if(integer::condition("JZ",flags)) goto L004717bf;
  }
  L004717ae: { // 0x4717ae: 398864020000 CMP dword ptr [EAX + 0x264], ECX
    (void)integer::sub(m.r32((s.ax+0x00000264u)),s.cx,32,flags);
  }
  L004717b4: { // 0x4717b4: 7509 JNZ 0x4717bf
    if(integer::condition("JNZ",flags)) goto L004717bf;
  }
  L004717b6: { // 0x4717b6: 80bf1e01000010 CMP byte ptr [EDI + 0x11e], 0x10
    (void)integer::sub(m.r8((s.di+0x0000011eu)),0x00000010u,8,flags);
  }
  L004717bd: { // 0x4717bd: 7316 JNC 0x4717d5
    if(integer::condition("JNC",flags)) goto L004717d5;
  }
  L004717bf: { // 0x4717bf: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004717c3: { // 0x4717c3: 8b9a84070000 MOV EBX, dword ptr [EDX + 0x784]
    s.bx = m.r32((s.dx+0x00000784u));
  }
  L004717c9: { // 0x4717c9: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004717cb: { // 0x4717cb: 7408 JZ 0x4717d5
    if(integer::condition("JZ",flags)) goto L004717d5;
  }
  L004717cd: { // 0x4717cd: 3b8288070000 CMP EAX, dword ptr [EDX + 0x788]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000788u)),32,flags);
  }
  L004717d3: { // 0x4717d3: 750a JNZ 0x4717df
    if(integer::condition("JNZ",flags)) goto L004717df;
  }
  L004717d5: { // 0x4717d5: 3b742424 CMP ESI, dword ptr [ESP + 0x24]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L004717d9: { // 0x4717d9: 0f8421010000 JZ 0x471900
    if(integer::condition("JZ",flags)) goto L00471900;
  }
  L004717df: { // 0x4717df: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004717e3: { // 0x4717e3: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L004717e5: { // 0x4717e5: 7450 JZ 0x471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  L004717e7: { // 0x4717e7: 8a9059130000 MOV DL, byte ptr [EAX + 0x1359]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00001359u)));
  }
  L004717ed: { // 0x4717ed: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004717ef: { // 0x4717ef: 7446 JZ 0x471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  L004717f1: { // 0x4717f1: 83f97e CMP ECX, 0x7e
    (void)integer::sub(s.cx,0x0000007eu,32,flags);
  }
  L004717f4: { // 0x4717f4: 740a JZ 0x471800
    if(integer::condition("JZ",flags)) goto L00471800;
  }
  L004717f6: { // 0x4717f6: e8352f1600 CALL 0x5d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4659195u); flags=s.arithmetic_flags;
  }
  L004717fb: { // 0x4717fb: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L004717fe: { // 0x4717fe: 7437 JZ 0x471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  L00471800: { // 0x471800: 8b8740010000 MOV EAX, dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L00471806: { // 0x471806: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00471808: { // 0x471808: c1e908 SHR ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::right);
  }
  L0047180b: { // 0x47180b: f6c101 TEST CL, 1
    (void)integer::logical(((s.cx & 0xffu))&(1u),8,flags);
  }
  L0047180e: { // 0x47180e: 0f854dfdffff JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L00471814: { // 0x471814: f6c404 TEST AH, 4
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(4u),8,flags);
  }
  L00471817: { // 0x471817: 0f8544fdffff JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L0047181d: { // 0x47181d: 8a871c010000 MOV AL, byte ptr [EDI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  L00471823: { // 0x471823: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471825: { // 0x471825: 0f84d5000000 JZ 0x471900
    if(integer::condition("JZ",flags)) goto L00471900;
  }
  L0047182b: { // 0x47182b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047182c: { // 0x47182c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047182d: { // 0x47182d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047182e: { // 0x47182e: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00471830: { // 0x471830: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471831: { // 0x471831: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00471834: { // 0x471834: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00471837: { // 0x471837: a05389a200 MOV AL, byte ptr [0xa28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L0047183c: { // 0x47183c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047183e: { // 0x47183e: 0f841dfdffff JZ 0x471561
    if(integer::condition("JZ",flags)) goto L00471561;
  }
  L00471844: { // 0x471844: 8b5744 MOV EDX, dword ptr [EDI + 0x44]
    s.dx = m.r32((s.di+0x00000044u));
  }
  L00471847: { // 0x471847: a11ce1a100 MOV EAX, dword ptr [0xa1e11c]
    s.ax = m.r32((0x00a1e11cu));
  }
  L0047184c: { // 0x47184c: 8b0c90 MOV ECX, dword ptr [EAX + EDX*4]
    s.cx = m.r32((s.ax+(s.dx * 4u)));
  }
  L0047184f: { // 0x47184f: 8a8178020000 MOV AL, byte ptr [ECX + 0x278]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000278u)));
  }
  L00471855: { // 0x471855: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471857: { // 0x471857: 0f8504fdffff JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L0047185d: { // 0x47185d: 8b4c241c MOV ECX, dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00471861: { // 0x471861: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L00471864: { // 0x471864: 7577 JNZ 0x4718dd
    if(integer::condition("JNZ",flags)) goto L004718dd;
  }
  L00471866: { // 0x471866: 8b8740010000 MOV EAX, dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0047186c: { // 0x47186c: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047186e: { // 0x47186e: c1ea08 SHR EDX, 8
    s.dx = integer::shift(s.dx,8u,32,flags,integer::Shift::right);
  }
  L00471871: { // 0x471871: f6c201 TEST DL, 1
    (void)integer::logical(((s.dx & 0xffu))&(1u),8,flags);
  }
  L00471874: { // 0x471874: 0f85e7fcffff JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L0047187a: { // 0x47187a: f6c404 TEST AH, 4
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(4u),8,flags);
  }
  L0047187d: { // 0x47187d: 0f85defcffff JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L00471883: { // 0x471883: 8a871c010000 MOV AL, byte ptr [EDI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  L00471889: { // 0x471889: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047188b: { // 0x47188b: 0f85d0fcffff JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L00471891: { // 0x471891: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00471895: { // 0x471895: 8a88da0a0000 MOV CL, byte ptr [EAX + 0xada]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000adau)));
  }
  L0047189b: { // 0x47189b: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0047189d: { // 0x47189d: 7424 JZ 0x4718c3
    if(integer::condition("JZ",flags)) goto L004718c3;
  }
  L0047189f: { // 0x47189f: 8b4738 MOV EAX, dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L004718a2: { // 0x4718a2: 8b0db8a1a300 MOV ECX, dword ptr [0xa3a1b8]
    s.cx = m.r32((0x00a3a1b8u));
  }
  L004718a8: { // 0x4718a8: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004718aa: { // 0x4718aa: 0f8cb1fcffff JL 0x471561
    if(integer::condition("JL",flags)) goto L00471561;
  }
  L004718b0: { // 0x4718b0: 83c10e ADD ECX, 0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  L004718b3: { // 0x4718b3: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004718b5: { // 0x4718b5: 7c49 JL 0x471900
    if(integer::condition("JL",flags)) goto L00471900;
  }
  L004718b7: { // 0x4718b7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004718b8: { // 0x4718b8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004718b9: { // 0x4718b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004718ba: { // 0x4718ba: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004718bc: { // 0x4718bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004718bd: { // 0x4718bd: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004718c0: { // 0x4718c0: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004718c3: { // 0x4718c3: 8b87ec000000 MOV EAX, dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  L004718c9: { // 0x4718c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004718ca: { // 0x4718ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004718cb: { // 0x4718cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004718cc: { // 0x4718cc: 8d0cc0 LEA ECX, [EAX + EAX*8]
    s.cx = (s.ax+(s.ax * 8u));
  }
  L004718cf: { // 0x4718cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004718d0: { // 0x4718d0: 8a048df0918300 MOV AL, byte ptr [ECX*4 + 0x8391f0]
    s.ax = with_al(s.ax, m.r8(((s.cx * 4u)+0x008391f0u)));
  }
  L004718d7: { // 0x4718d7: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004718da: { // 0x4718da: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004718dd: { // 0x4718dd: 8b87ec000000 MOV EAX, dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  L004718e3: { // 0x4718e3: 8d14c1 LEA EDX, [ECX + EAX*8]
    s.dx = (s.cx+(s.ax * 8u));
  }
  L004718e6: { // 0x4718e6: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004718e8: { // 0x4718e8: d90485d0918300 FLD dword ptr [EAX*4 + 0x8391d0]
    const auto address=((s.ax * 4u)+0x008391d0u);
    s.fp.load32(m.r32(address));
  }
  L004718ef: { // 0x4718ef: d81d38577800 FCOMP dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004718f5: { // 0x4718f5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004718f7: { // 0x4718f7: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004718fa: { // 0x4718fa: 0f8561fcffff JNZ 0x471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L00471900: { // 0x471900: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471901: { // 0x471901: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471902: { // 0x471902: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471903: { // 0x471903: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00471905: { // 0x471905: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471906: { // 0x471906: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00471909: { // 0x471909: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4514096u:f_0004e130(m,s,child,{});break;
case 5665392u:f_00167270(m,s,child,{});break;
case 5665872u:f_00167450(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
case 4658352u:f_000714b0(m,s,child,{});break;
default:throw std::domain_error("recovery1515 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1515 no reviewed tail"); } }

std::uint32_t fun_0044e130(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044e130: { // 0x44e130: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0044e133: { // 0x44e133: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044e134: { // 0x44e134: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044e135: { // 0x44e135: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044e136: { // 0x44e136: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e137: { // 0x44e137: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044e139: { // 0x44e139: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044e13a: { // 0x44e13a: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e13f: { // 0x44e13f: e8bc730f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4514116u); flags=s.arithmetic_flags;
  }
  L0044e144: { // 0x44e144: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044e146: { // 0x44e146: 0f8404010000 JZ 0x44e250
    if(integer::condition("JZ",flags)) goto L0044e250;
  }
  L0044e14c: { // 0x44e14c: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044e14e: { // 0x44e14e: e85d320200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4514131u); flags=s.arithmetic_flags;
  }
  L0044e153: { // 0x44e153: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L0044e155: { // 0x44e155: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0044e157: { // 0x44e157: 0f84f3000000 JZ 0x44e250
    if(integer::condition("JZ",flags)) goto L0044e250;
  }
  L0044e15d: { // 0x44e15d: 8b8518040000 MOV EAX, dword ptr [EBP + 0x418]
    s.ax = m.r32((s.bp+0x00000418u));
  }
  L0044e163: { // 0x44e163: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0044e169: { // 0x44e169: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e16b: { // 0x44e16b: 0f84df000000 JZ 0x44e250
    if(integer::condition("JZ",flags)) goto L0044e250;
  }
  L0044e171: { // 0x44e171: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0044e175: { // 0x44e175: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e176: { // 0x44e176: 8d8de0020000 LEA ECX, [EBP + 0x2e0]
    s.cx = (s.bp+0x000002e0u);
  }
  L0044e17c: { // 0x44e17c: e8cfa60600 CALL 0x4b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4514177u); flags=s.arithmetic_flags;
  }
  L0044e181: { // 0x44e181: 8b30 MOV ESI, dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0044e183: { // 0x44e183: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0044e185: { // 0x44e185: c1ee0c SHR ESI, 0xc
    s.si = integer::shift(s.si,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0044e188: { // 0x44e188: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0044e189: { // 0x44e189: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044e18b: { // 0x44e18b: d1ee SHR ESI, 1
    s.si = integer::shift(s.si,1u,32,flags,integer::Shift::right);
  }
  L0044e18d: { // 0x44e18d: 83e603 AND ESI, 3
    s.si = integer::logical((s.si)&(3u),32,flags);
  }
  L0044e190: { // 0x44e190: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0044e194: { // 0x44e194: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L0044e196: { // 0x44e196: 83e207 AND EDX, 7
    s.dx = integer::logical((s.dx)&(7u),32,flags);
  }
  L0044e199: { // 0x44e199: 668b0c95a09d8300 MOV CX, word ptr [EDX*4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 4u)+0x00839da0u)));
  }
  L0044e1a1: { // 0x44e1a1: 8d3c95a09d8300 LEA EDI, [EDX*4 + 0x839da0]
    s.di = ((s.dx * 4u)+0x00839da0u);
  }
  L0044e1a8: { // 0x44e1a8: 6603c8 ADD CX, AX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0044e1ab: { // 0x44e1ab: 668b5702 MOV DX, word ptr [EDI + 2]
    s.dx = with_ax(s.dx, m.r16((s.di+2u)));
  }
  L0044e1af: { // 0x44e1af: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0044e1b4: { // 0x44e1b4: 6603542416 ADD DX, word ptr [ESP + 0x16]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0044e1b9: { // 0x44e1b9: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0044e1be: { // 0x44e1be: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0044e1c2: { // 0x44e1c2: 663bc8 CMP CX, AX
    (void)integer::sub((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  L0044e1c5: { // 0x44e1c5: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0044e1c9: { // 0x44e1c9: 750c JNZ 0x44e1d7
    if(integer::condition("JNZ",flags)) goto L0044e1d7;
  }
  L0044e1cb: { // 0x44e1cb: 668b442416 MOV AX, word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000016u)));
  }
  L0044e1d0: { // 0x44e1d0: 6639442412 CMP word ptr [ESP + 0x12], AX
    (void)integer::sub(m.r16((f.sp+0x00000012u)),(s.ax & 0xffffu),16,flags);
  }
  L0044e1d5: { // 0x44e1d5: 746a JZ 0x44e241
    if(integer::condition("JZ",flags)) goto L0044e241;
  }
  L0044e1d7: { // 0x44e1d7: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0044e1db: { // 0x44e1db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044e1dc: { // 0x44e1dc: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0044e1e1: { // 0x44e1e1: e81a730f00 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4514278u); flags=s.arithmetic_flags;
  }
  L0044e1e6: { // 0x44e1e6: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0044e1e8: { // 0x44e1e8: e8c3310200 CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4514285u); flags=s.arithmetic_flags;
  }
  L0044e1ed: { // 0x44e1ed: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0044e1ef: { // 0x44e1ef: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0044e1f1: { // 0x44e1f1: 7452 JZ 0x44e245
    if(integer::condition("JZ",flags)) goto L0044e245;
  }
  L0044e1f3: { // 0x44e1f3: 8b8318040000 MOV EAX, dword ptr [EBX + 0x418]
    s.ax = m.r32((s.bx+0x00000418u));
  }
  L0044e1f9: { // 0x44e1f9: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044e1ff: { // 0x44e1ff: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e201: { // 0x44e201: 7531 JNZ 0x44e234
    if(integer::condition("JNZ",flags)) goto L0044e234;
  }
  L0044e203: { // 0x44e203: 8a8859130000 MOV CL, byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0044e209: { // 0x44e209: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044e20b: { // 0x44e20b: 7438 JZ 0x44e245
    if(integer::condition("JZ",flags)) goto L0044e245;
  }
  L0044e20d: { // 0x44e20d: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044e211: { // 0x44e211: 668b17 MOV DX, word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L0044e214: { // 0x44e214: 668b4f02 MOV CX, word ptr [EDI + 2]
    s.cx = with_ax(s.cx, m.r16((s.di+2u)));
  }
  L0044e218: { // 0x44e218: 6603d0 ADD DX, AX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0044e21b: { // 0x44e21b: 66034c2412 ADD CX, word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L0044e220: { // 0x44e220: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0044e225: { // 0x44e225: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0044e229: { // 0x44e229: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0044e22e: { // 0x44e22e: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0044e232: { // 0x44e232: eb8e JMP 0x44e1c2
    goto L0044e1c2;
  }
  L0044e234: { // 0x44e234: 83ce04 OR ESI, 4
    s.si = integer::logical((s.si)|(4u),32,flags);
  }
  L0044e237: { // 0x44e237: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044e239: { // 0x44e239: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044e23a: { // 0x44e23a: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0044e23c: { // 0x44e23c: e80ffdffff CALL 0x44df50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044df50u,4514369u); flags=s.arithmetic_flags;
  }
  L0044e241: { // 0x44e241: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0044e243: { // 0x44e243: 750b JNZ 0x44e250
    if(integer::condition("JNZ",flags)) goto L0044e250;
  }
  L0044e245: { // 0x44e245: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0044e248: { // 0x44e248: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L0044e24a: { // 0x44e24a: ff92f0000000 CALL dword ptr [EDX + 0xf0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000f0u)),4514384u); flags=s.arithmetic_flags;
  }
  L0044e250: { // 0x44e250: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044e251: { // 0x44e251: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044e252: { // 0x44e252: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044e253: { // 0x44e253: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044e254: { // 0x44e254: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0044e257: { // 0x44e257: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00567270(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00567270: { // 0x567270: 83ec28 SUB ESP, 0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00567273: { // 0x567273: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00567274: { // 0x567274: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00567275: { // 0x567275: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00567277: { // 0x567277: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00567278: { // 0x567278: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00567279: { // 0x567279: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056727d: { // 0x56727d: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00567281: { // 0x567281: 8b6c2444 MOV EBP, dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00567285: { // 0x567285: c744241400000000 MOV dword ptr [ESP + 0x14], 0
    m.w32((f.sp+0x00000014u), 0u);
  }
  L0056728d: { // 0x56728d: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0056728f: { // 0x56728f: 8b8504050000 MOV EAX, dword ptr [EBP + 0x504]
    s.ax = m.r32((s.bp+0x00000504u));
  }
  L00567295: { // 0x567295: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00567298: { // 0x567298: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056729a: { // 0x56729a: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0056729e: { // 0x56729e: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005672a2: { // 0x5672a2: 0f8e88010000 JLE 0x567430
    if(integer::condition("JLE",flags)) goto L00567430;
  }
  L005672a8: { // 0x5672a8: 83e107 AND ECX, 7
    s.cx = integer::logical((s.cx)&(7u),32,flags);
  }
  L005672ab: { // 0x5672ab: 8d3c8da09d8300 LEA EDI, [ECX*4 + 0x839da0]
    s.di = ((s.cx * 4u)+0x00839da0u);
  }
  L005672b2: { // 0x5672b2: 668b4f02 MOV CX, word ptr [EDI + 2]
    s.cx = with_ax(s.cx, m.r16((s.di+2u)));
  }
  L005672b6: { // 0x5672b6: 668b07 MOV AX, word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L005672b9: { // 0x5672b9: 66034c2412 ADD CX, word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L005672be: { // 0x5672be: 6603442410 ADD AX, word ptr [ESP + 0x10]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  L005672c3: { // 0x5672c3: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L005672c8: { // 0x5672c8: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L005672cd: { // 0x5672cd: 8b5c2418 MOV EBX, dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L005672d1: { // 0x5672d1: 0fbfc9 MOVSX ECX, CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005672d4: { // 0x5672d4: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005672d7: { // 0x5672d7: c1e109 SHL ECX, 9
    s.cx = integer::shift(s.cx,9u,32,flags,integer::Shift::left);
  }
  L005672da: { // 0x5672da: 895c2410 MOV dword ptr [ESP + 0x10], EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005672de: { // 0x5672de: 8d3411 LEA ESI, [ECX + EDX]
    s.si = (s.cx+s.dx);
  }
  L005672e1: { // 0x5672e1: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005672e3: { // 0x5672e3: 7c14 JL 0x5672f9
    if(integer::condition("JL",flags)) goto L005672f9;
  }
  L005672e5: { // 0x5672e5: 81fe00000400 CMP ESI, 0x40000
    (void)integer::sub(s.si,0x00040000u,32,flags);
  }
  L005672eb: { // 0x5672eb: 7d0c JGE 0x5672f9
    if(integer::condition("JGE",flags)) goto L005672f9;
  }
  L005672ed: { // 0x5672ed: a158a98100 MOV EAX, dword ptr [0x81a958]
    s.ax = m.r32((0x0081a958u));
  }
  L005672f2: { // 0x5672f2: 8b0cb0 MOV ECX, dword ptr [EAX + ESI*4]
    s.cx = m.r32((s.ax+(s.si * 4u)));
  }
  L005672f5: { // 0x5672f5: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005672f7: { // 0x5672f7: 750b JNZ 0x567304
    if(integer::condition("JNZ",flags)) goto L00567304;
  }
  L005672f9: { // 0x5672f9: 891d3476a500 MOV dword ptr [0xa57634], EBX
    m.w32((0x00a57634u), s.bx);
  }
  L005672ff: { // 0x5672ff: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L00567304: { // 0x567304: e8a7a0f0ff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,5665545u); flags=s.arithmetic_flags;
  }
  L00567309: { // 0x567309: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056730b: { // 0x56730b: 741e JZ 0x56732b
    if(integer::condition("JZ",flags)) goto L0056732b;
  }
  L0056730d: { // 0x56730d: 8b8818040000 MOV ECX, dword ptr [EAX + 0x418]
    s.cx = m.r32((s.ax+0x00000418u));
  }
  L00567313: { // 0x567313: 8a915a130000 MOV DL, byte ptr [ECX + 0x135a]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000135au)));
  }
  L00567319: { // 0x567319: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0056731b: { // 0x56731b: 740e JZ 0x56732b
    if(integer::condition("JZ",flags)) goto L0056732b;
  }
  L0056731d: { // 0x56731d: 8b90b4010000 MOV EDX, dword ptr [EAX + 0x1b4]
    s.dx = m.r32((s.ax+0x000001b4u));
  }
  L00567323: { // 0x567323: 8b442440 MOV EAX, dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00567327: { // 0x567327: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00567329: { // 0x567329: 745b JZ 0x567386
    if(integer::condition("JZ",flags)) goto L00567386;
  }
  L0056732b: { // 0x56732b: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0056732d: { // 0x56732d: 7c18 JL 0x567347
    if(integer::condition("JL",flags)) goto L00567347;
  }
  L0056732f: { // 0x56732f: 81fe00000400 CMP ESI, 0x40000
    (void)integer::sub(s.si,0x00040000u,32,flags);
  }
  L00567335: { // 0x567335: 7d10 JGE 0x567347
    if(integer::condition("JGE",flags)) goto L00567347;
  }
  L00567337: { // 0x567337: a158a98100 MOV EAX, dword ptr [0x81a958]
    s.ax = m.r32((0x0081a958u));
  }
  L0056733c: { // 0x56733c: 8b34b0 MOV ESI, dword ptr [EAX + ESI*4]
    s.si = m.r32((s.ax+(s.si * 4u)));
  }
  L0056733f: { // 0x56733f: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00567341: { // 0x567341: 7404 JZ 0x567347
    if(integer::condition("JZ",flags)) goto L00567347;
  }
  L00567343: { // 0x567343: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00567345: { // 0x567345: eb0b JMP 0x567352
    goto L00567352;
  }
  L00567347: { // 0x567347: 891d3476a500 MOV dword ptr [0xa57634], EBX
    m.w32((0x00a57634u), s.bx);
  }
  L0056734d: { // 0x56734d: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L00567352: { // 0x567352: 8b542440 MOV EDX, dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00567356: { // 0x567356: 8b85a4050000 MOV EAX, dword ptr [EBP + 0x5a4]
    s.ax = m.r32((s.bp+0x000005a4u));
  }
  L0056735c: { // 0x56735c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056735d: { // 0x56735d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056735e: { // 0x56735e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056735f: { // 0x56735f: e84ca1f0ff CALL 0x4714b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004714b0u,5665636u); flags=s.arithmetic_flags;
  }
  L00567364: { // 0x567364: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00567366: { // 0x567366: 0f84c4000000 JZ 0x567430
    if(integer::condition("JZ",flags)) goto L00567430;
  }
  L0056736c: { // 0x56736c: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00567370: { // 0x567370: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00567374: { // 0x567374: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00567375: { // 0x567375: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00567377: { // 0x567377: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0056737b: { // 0x56737b: 0f8c31ffffff JL 0x5672b2
    if(integer::condition("JL",flags)) goto L005672b2;
  }
  L00567381: { // 0x567381: e9aa000000 JMP 0x567430
    goto L00567430;
  }
  L00567386: { // 0x567386: 8b5c2414 MOV EBX, dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0056738a: { // 0x56738a: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0056738c: { // 0x56738c: 0f8e9e000000 JLE 0x567430
    if(integer::condition("JLE",flags)) goto L00567430;
  }
  L00567392: { // 0x567392: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00567396: { // 0x567396: 668b5702 MOV DX, word ptr [EDI + 2]
    s.dx = with_ax(s.dx, m.r16((s.di+2u)));
  }
  L0056739a: { // 0x56739a: 668b08 MOV CX, word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L0056739d: { // 0x56739d: 66035002 ADD DX, word ptr [EAX + 2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.ax+2u)),16,flags));
  }
  L005673a1: { // 0x5673a1: 66030f ADD CX, word ptr [EDI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.di)),16,flags));
  }
  L005673a4: { // 0x5673a4: 668954241e MOV word ptr [ESP + 0x1e], DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L005673a9: { // 0x5673a9: 66894c241c MOV word ptr [ESP + 0x1c], CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L005673ae: { // 0x5673ae: 8b74241c MOV ESI, dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L005673b2: { // 0x5673b2: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005673b4: { // 0x5673b4: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L005673b8: { // 0x5673b8: 7e76 JLE 0x567430
    if(integer::condition("JLE",flags)) goto L00567430;
  }
  L005673ba: { // 0x5673ba: eb04 JMP 0x5673c0
    goto L005673c0;
  }
  L005673bc: { // 0x5673bc: 8b6c2444 MOV EBP, dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L005673c0: { // 0x5673c0: 8b4c2440 MOV ECX, dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L005673c4: { // 0x5673c4: 8b4500 MOV EAX, dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005673c7: { // 0x5673c7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005673c8: { // 0x5673c8: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005673ca: { // 0x5673ca: ff908c000000 CALL dword ptr [EAX + 0x8c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000008cu)),5665744u); flags=s.arithmetic_flags;
  }
  L005673d0: { // 0x5673d0: 668b6c2416 MOV BP, word ptr [ESP + 0x16]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((f.sp+0x00000016u))) & 0xffffu);
  }
  L005673d5: { // 0x5673d5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005673d7: { // 0x5673d7: 0fbfcd MOVSX ECX, BP
    s.cx = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L005673da: { // 0x5673da: 0fbfd6 MOVSX EDX, SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005673dd: { // 0x5673dd: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L005673e0: { // 0x5673e0: c1e208 SHL EDX, 8
    s.dx = integer::shift(s.dx,8u,32,flags,integer::Shift::left);
  }
  L005673e3: { // 0x5673e3: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L005673e9: { // 0x5673e9: 81c280000000 ADD EDX, 0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L005673ef: { // 0x5673ef: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L005673f3: { // 0x5673f3: 8d4c2430 LEA ECX, [ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L005673f7: { // 0x5673f7: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L005673fb: { // 0x5673fb: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005673fd: { // 0x5673fd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005673fe: { // 0x5673fe: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00567400: { // 0x567400: c744243c00000000 MOV dword ptr [ESP + 0x3c], 0
    m.w32((f.sp+0x0000003cu), 0u);
  }
  L00567408: { // 0x567408: ff92d4000000 CALL dword ptr [EDX + 0xd4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d4u)),5665806u); flags=s.arithmetic_flags;
  }
  L0056740e: { // 0x56740e: 668b17 MOV DX, word ptr [EDI]
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00567411: { // 0x567411: 668b4702 MOV AX, word ptr [EDI + 2]
    s.ax = with_ax(s.ax, m.r16((s.di+2u)));
  }
  L00567415: { // 0x567415: 6603d6 ADD DX, SI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L00567418: { // 0x567418: 6603c5 ADD AX, BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L0056741b: { // 0x56741b: 6689542420 MOV word ptr [ESP + 0x20], DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L00567420: { // 0x567420: 6689442422 MOV word ptr [ESP + 0x22], AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L00567425: { // 0x567425: 8b742420 MOV ESI, dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L00567429: { // 0x567429: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0056742a: { // 0x56742a: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0056742e: { // 0x56742e: 758c JNZ 0x5673bc
    if(integer::condition("JNZ",flags)) goto L005673bc;
  }
  L00567430: { // 0x567430: 8b4c2424 MOV ECX, dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00567434: { // 0x567434: 83c102 ADD ECX, 2
    s.cx = integer::add(s.cx,2u,32,flags);
  }
  L00567437: { // 0x567437: 83f908 CMP ECX, 8
    (void)integer::sub(s.cx,8u,32,flags);
  }
  L0056743a: { // 0x56743a: 894c2424 MOV dword ptr [ESP + 0x24], ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0056743e: { // 0x56743e: 0f8c39feffff JL 0x56727d
    if(integer::condition("JL",flags)) goto L0056727d;
  }
  L00567444: { // 0x567444: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00567445: { // 0x567445: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00567446: { // 0x567446: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00567447: { // 0x567447: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00567448: { // 0x567448: 83c428 ADD ESP, 0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L0056744b: { // 0x56744b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00567450(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00567450: { // 0x567450: 83ec2c SUB ESP, 0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L00567453: { // 0x567453: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00567454: { // 0x567454: 8b7c243c MOV EDI, dword ptr [ESP + 0x3c]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L00567458: { // 0x567458: 8b87ec0b0000 MOV EAX, dword ptr [EDI + 0xbec]
    s.ax = m.r32((s.di+0x00000becu));
  }
  L0056745e: { // 0x56745e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00567460: { // 0x567460: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00567464: { // 0x567464: 0f84e2010000 JZ 0x56764c
    if(integer::condition("JZ",flags)) goto L0056764c;
  }
  L0056746a: { // 0x56746a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056746b: { // 0x56746b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056746d: { // 0x56746d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056746e: { // 0x56746e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056746f: { // 0x56746f: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00567473: { // 0x567473: 8b4c2440 MOV ECX, dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00567477: { // 0x567477: 8baf04050000 MOV EBP, dword ptr [EDI + 0x504]
    s.bp = m.r32((s.di+0x00000504u));
  }
  L0056747d: { // 0x56747d: c1fd08 SAR EBP, 8
    s.bp = integer::shift(s.bp,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00567480: { // 0x567480: 8b31 MOV ESI, dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00567482: { // 0x567482: 896c241c MOV dword ptr [ESP + 0x1c], EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00567486: { // 0x567486: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00567488: { // 0x567488: 89742418 MOV dword ptr [ESP + 0x18], ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0056748c: { // 0x56748c: c744241000000000 MOV dword ptr [ESP + 0x10], 0
    m.w32((f.sp+0x00000010u), 0u);
  }
  L00567494: { // 0x567494: 0f8e9b010000 JLE 0x567635
    if(integer::condition("JLE",flags)) goto L00567635;
  }
  L0056749a: { // 0x56749a: 83e007 AND EAX, 7
    s.ax = integer::logical((s.ax)&(7u),32,flags);
  }
  L0056749d: { // 0x56749d: 8d1c85a09d8300 LEA EBX, [EAX*4 + 0x839da0]
    s.bx = ((s.ax * 4u)+0x00839da0u);
  }
  L005674a4: { // 0x5674a4: 668b4b02 MOV CX, word ptr [EBX + 2]
    s.cx = with_ax(s.cx, m.r16((s.bx+2u)));
  }
  L005674a8: { // 0x5674a8: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L005674ab: { // 0x5674ab: 66034c241a ADD CX, word ptr [ESP + 0x1a]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000001au)),16,flags));
  }
  L005674b0: { // 0x5674b0: 6603c6 ADD AX, SI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L005674b3: { // 0x5674b3: 6689442414 MOV word ptr [ESP + 0x14], AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L005674b8: { // 0x5674b8: 66894c2416 MOV word ptr [ESP + 0x16], CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L005674bd: { // 0x5674bd: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005674c1: { // 0x5674c1: 0fbfc9 MOVSX ECX, CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005674c4: { // 0x5674c4: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005674c7: { // 0x5674c7: c1e109 SHL ECX, 9
    s.cx = integer::shift(s.cx,9u,32,flags,integer::Shift::left);
  }
  L005674ca: { // 0x5674ca: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005674cc: { // 0x5674cc: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L005674ce: { // 0x5674ce: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005674d0: { // 0x5674d0: 89742418 MOV dword ptr [ESP + 0x18], ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L005674d4: { // 0x5674d4: 7c14 JL 0x5674ea
    if(integer::condition("JL",flags)) goto L005674ea;
  }
  L005674d6: { // 0x5674d6: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005674db: { // 0x5674db: 7d0d JGE 0x5674ea
    if(integer::condition("JGE",flags)) goto L005674ea;
  }
  L005674dd: { // 0x5674dd: 8b0d58a98100 MOV ECX, dword ptr [0x81a958]
    s.cx = m.r32((0x0081a958u));
  }
  L005674e3: { // 0x5674e3: 8b0c81 MOV ECX, dword ptr [ECX + EAX*4]
    s.cx = m.r32((s.cx+(s.ax * 4u)));
  }
  L005674e6: { // 0x5674e6: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005674e8: { // 0x5674e8: 750b JNZ 0x5674f5
    if(integer::condition("JNZ",flags)) goto L005674f5;
  }
  L005674ea: { // 0x5674ea: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005674f0: { // 0x5674f0: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L005674f5: { // 0x5674f5: 8b4944 MOV ECX, dword ptr [ECX + 0x44]
    s.cx = m.r32((s.cx+0x00000044u));
  }
  L005674f8: { // 0x5674f8: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L005674fb: { // 0x5674fb: 743f JZ 0x56753c
    if(integer::condition("JZ",flags)) goto L0056753c;
  }
  L005674fd: { // 0x5674fd: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L00567501: { // 0x567501: 398d64020000 CMP dword ptr [EBP + 0x264], ECX
    (void)integer::sub(m.r32((s.bp+0x00000264u)),s.cx,32,flags);
  }
  L00567507: { // 0x567507: 752f JNZ 0x567538
    if(integer::condition("JNZ",flags)) goto L00567538;
  }
  L00567509: { // 0x567509: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056750b: { // 0x56750b: 7c14 JL 0x567521
    if(integer::condition("JL",flags)) goto L00567521;
  }
  L0056750d: { // 0x56750d: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00567512: { // 0x567512: 7d0d JGE 0x567521
    if(integer::condition("JGE",flags)) goto L00567521;
  }
  L00567514: { // 0x567514: 8b0d58a98100 MOV ECX, dword ptr [0x81a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0056751a: { // 0x56751a: 8b0c81 MOV ECX, dword ptr [ECX + EAX*4]
    s.cx = m.r32((s.cx+(s.ax * 4u)));
  }
  L0056751d: { // 0x56751d: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0056751f: { // 0x56751f: 750b JNZ 0x56752c
    if(integer::condition("JNZ",flags)) goto L0056752c;
  }
  L00567521: { // 0x567521: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00567527: { // 0x567527: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L0056752c: { // 0x56752c: 8b6c2444 MOV EBP, dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00567530: { // 0x567530: 8b6d30 MOV EBP, dword ptr [EBP + 0x30]
    s.bp = m.r32((s.bp+0x00000030u));
  }
  L00567533: { // 0x567533: 3b6950 CMP EBP, dword ptr [ECX + 0x50]
    (void)integer::sub(s.bp,m.r32((s.cx+0x00000050u)),32,flags);
  }
  L00567536: { // 0x567536: 7459 JZ 0x567591
    if(integer::condition("JZ",flags)) goto L00567591;
  }
  L00567538: { // 0x567538: 8b6c241c MOV EBP, dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L0056753c: { // 0x56753c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056753e: { // 0x56753e: 7c14 JL 0x567554
    if(integer::condition("JL",flags)) goto L00567554;
  }
  L00567540: { // 0x567540: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00567545: { // 0x567545: 7d0d JGE 0x567554
    if(integer::condition("JGE",flags)) goto L00567554;
  }
  L00567547: { // 0x567547: 8b0d58a98100 MOV ECX, dword ptr [0x81a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0056754d: { // 0x56754d: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00567550: { // 0x567550: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00567552: { // 0x567552: 750b JNZ 0x56755f
    if(integer::condition("JNZ",flags)) goto L0056755f;
  }
  L00567554: { // 0x567554: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0056755a: { // 0x56755a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0056755f: { // 0x56755f: 8b542444 MOV EDX, dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00567563: { // 0x567563: 8b8fa4050000 MOV ECX, dword ptr [EDI + 0x5a4]
    s.cx = m.r32((s.di+0x000005a4u));
  }
  L00567569: { // 0x567569: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0056756a: { // 0x56756a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056756b: { // 0x56756b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056756c: { // 0x56756c: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0056756e: { // 0x56756e: e83d9ff0ff CALL 0x4714b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004714b0u,5666163u); flags=s.arithmetic_flags;
  }
  L00567573: { // 0x567573: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00567575: { // 0x567575: 0f84ba000000 JZ 0x567635
    if(integer::condition("JZ",flags)) goto L00567635;
  }
  L0056757b: { // 0x56757b: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0056757f: { // 0x56757f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00567580: { // 0x567580: 3bc5 CMP EAX, EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00567582: { // 0x567582: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00567586: { // 0x567586: 0f8c18ffffff JL 0x5674a4
    if(integer::condition("JL",flags)) goto L005674a4;
  }
  L0056758c: { // 0x56758c: e9a4000000 JMP 0x567635
    goto L00567635;
  }
  L00567591: { // 0x567591: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00567595: { // 0x567595: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00567597: { // 0x567597: 0f8e98000000 JLE 0x567635
    if(integer::condition("JLE",flags)) goto L00567635;
  }
  L0056759d: { // 0x56759d: 8b442440 MOV EAX, dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L005675a1: { // 0x5675a1: 668b13 MOV DX, word ptr [EBX]
    s.dx = with_ax(s.dx, m.r16((s.bx)));
  }
  L005675a4: { // 0x5675a4: 668b4b02 MOV CX, word ptr [EBX + 2]
    s.cx = with_ax(s.cx, m.r16((s.bx+2u)));
  }
  L005675a8: { // 0x5675a8: 660310 ADD DX, word ptr [EAX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.ax)),16,flags));
  }
  L005675ab: { // 0x5675ab: 66034802 ADD CX, word ptr [EAX + 2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.ax+2u)),16,flags));
  }
  L005675af: { // 0x5675af: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L005675b1: { // 0x5675b1: 6689542420 MOV word ptr [ESP + 0x20], DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L005675b6: { // 0x5675b6: 66894c2422 MOV word ptr [ESP + 0x22], CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  L005675bb: { // 0x5675bb: 8b742420 MOV ESI, dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L005675bf: { // 0x5675bf: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L005675c3: { // 0x5675c3: 7e70 JLE 0x567635
    if(integer::condition("JLE",flags)) goto L00567635;
  }
  L005675c5: { // 0x5675c5: 8b442444 MOV EAX, dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005675c9: { // 0x5675c9: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005675cb: { // 0x5675cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005675cc: { // 0x5675cc: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005675ce: { // 0x5675ce: ff928c000000 CALL dword ptr [EDX + 0x8c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000008cu)),5666260u); flags=s.arithmetic_flags;
  }
  L005675d4: { // 0x5675d4: 668b7c241e MOV DI, word ptr [ESP + 0x1e]
    s.di = (s.di & 0xffff0000u) | ((m.r16((f.sp+0x0000001eu))) & 0xffffu);
  }
  L005675d9: { // 0x5675d9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005675db: { // 0x5675db: 0fbfce MOVSX ECX, SI
    s.cx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L005675de: { // 0x5675de: 0fbfd7 MOVSX EDX, DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L005675e1: { // 0x5675e1: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L005675e4: { // 0x5675e4: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L005675ea: { // 0x5675ea: c744243c00000000 MOV dword ptr [ESP + 0x3c], 0
    m.w32((f.sp+0x0000003cu), 0u);
  }
  L005675f2: { // 0x5675f2: c1e208 SHL EDX, 8
    s.dx = integer::shift(s.dx,8u,32,flags,integer::Shift::left);
  }
  L005675f5: { // 0x5675f5: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L005675f9: { // 0x5675f9: 81c280000000 ADD EDX, 0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L005675ff: { // 0x5675ff: 8d4c2434 LEA ECX, [ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L00567603: { // 0x567603: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00567607: { // 0x567607: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00567609: { // 0x567609: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056760a: { // 0x56760a: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0056760c: { // 0x56760c: ff92d4000000 CALL dword ptr [EDX + 0xd4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d4u)),5666322u); flags=s.arithmetic_flags;
  }
  L00567612: { // 0x567612: 668b5302 MOV DX, word ptr [EBX + 2]
    s.dx = with_ax(s.dx, m.r16((s.bx+2u)));
  }
  L00567616: { // 0x567616: 660333 ADD SI, word ptr [EBX]
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),m.r16((s.bx)),16,flags)) & 0xffffu);
  }
  L00567619: { // 0x567619: 6603d7 ADD DX, DI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L0056761c: { // 0x56761c: 8b7c2448 MOV EDI, dword ptr [ESP + 0x48]
    s.di = m.r32((f.sp+0x00000048u));
  }
  L00567620: { // 0x567620: 6689742424 MOV word ptr [ESP + 0x24], SI
    m.w16((f.sp+0x00000024u), (s.si & 0xffffu));
  }
  L00567625: { // 0x567625: 6689542426 MOV word ptr [ESP + 0x26], DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L0056762a: { // 0x56762a: 8b742424 MOV ESI, dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0056762e: { // 0x56762e: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0056762f: { // 0x56762f: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L00567633: { // 0x567633: 7590 JNZ 0x5675c5
    if(integer::condition("JNZ",flags)) goto L005675c5;
  }
  L00567635: { // 0x567635: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00567639: { // 0x567639: 83c002 ADD EAX, 2
    s.ax = integer::add(s.ax,2u,32,flags);
  }
  L0056763c: { // 0x56763c: 83f808 CMP EAX, 8
    (void)integer::sub(s.ax,8u,32,flags);
  }
  L0056763f: { // 0x56763f: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00567643: { // 0x567643: 0f8c2afeffff JL 0x567473
    if(integer::condition("JL",flags)) goto L00567473;
  }
  L00567649: { // 0x567649: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056764a: { // 0x56764a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056764b: { // 0x56764b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056764c: { // 0x56764c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056764d: { // 0x56764d: 83c42c ADD ESP, 0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L00567650: { // 0x567650: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
