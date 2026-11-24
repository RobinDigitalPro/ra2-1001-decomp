#include "recovered/recovery_b777_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b777 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0029e380(Memory&,State&,Frame&,const Operations&);
void f_002a0410(Memory&,State&,Frame&,const Operations&);
void f_00075960(Memory&,State&,Frame&,const Operations&);
void f_00297fb0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00147f40(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
  L0069e383: { // 0x69e383: 8b742410 MOV ESI, dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0069e387: { // 0x69e387: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e388: { // 0x69e388: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e389: { // 0x69e389: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e38e: { // 0x69e38e: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0069e390: { // 0x69e390: 83cfff OR EDI, 0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L0069e393: { // 0x69e393: e86871eaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939544u); flags=s.arithmetic_flags;
  }
  L0069e398: { // 0x69e398: 8a4c2418 MOV CL, byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0069e39c: { // 0x69e39c: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e39e: { // 0x69e39e: 0f84d0010000 JZ 0x69e574
    if(integer::condition("JZ",flags)) goto L0069e574;
  }
  L0069e3a4: { // 0x69e3a4: 8b8040010000 MOV EAX, dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0069e3aa: { // 0x69e3aa: a803 TEST AL, 3
    (void)integer::logical(((s.ax & 0xffu))&(3u),8,flags);
  }
  L0069e3ac: { // 0x69e3ac: 7505 JNZ 0x69e3b3
    if(integer::condition("JNZ",flags)) goto L0069e3b3;
  }
  L0069e3ae: { // 0x69e3ae: bffeffffff MOV EDI, 0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e3b3: { // 0x69e3b3: bb02000000 MOV EBX, 2
    s.bx = 2u;
  }
  L0069e3b8: { // 0x69e3b8: 84c3 TEST BL, AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e3ba: { // 0x69e3ba: 0f8494030000 JZ 0x69e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e3c0: { // 0x69e3c0: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e3c3: { // 0x69e3c3: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0069e3c7: { // 0x69e3c7: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e3c9: { // 0x69e3c9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e3cb: { // 0x69e3cb: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e3d0: { // 0x69e3d0: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e3d5: { // 0x69e3d5: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e3d9: { // 0x69e3d9: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e3dd: { // 0x69e3dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e3de: { // 0x69e3de: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e3e3: { // 0x69e3e3: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e3e7: { // 0x69e3e7: e81471eaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939628u); flags=s.arithmetic_flags;
  }
  L0069e3ec: { // 0x69e3ec: 849840010000 TEST byte ptr [EAX + 0x140], BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e3f2: { // 0x69e3f2: 7505 JNZ 0x69e3f9
    if(integer::condition("JNZ",flags)) goto L0069e3f9;
  }
  L0069e3f4: { // 0x69e3f4: bd40000000 MOV EBP, 0x40
    s.bp = 0x00000040u;
  }
  L0069e3f9: { // 0x69e3f9: 668b0e MOV CX, word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e3fc: { // 0x69e3fc: 668b5602 MOV DX, word ptr [ESI + 2]
    s.dx = with_ax(s.dx, m.r16((s.si+2u)));
  }
  L0069e400: { // 0x69e400: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e405: { // 0x69e405: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e407: { // 0x69e407: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e40b: { // 0x69e40b: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e410: { // 0x69e410: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e414: { // 0x69e414: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e415: { // 0x69e415: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e41a: { // 0x69e41a: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e41e: { // 0x69e41e: e8dd70eaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939683u); flags=s.arithmetic_flags;
  }
  L0069e423: { // 0x69e423: 849840010000 TEST byte ptr [EAX + 0x140], BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e429: { // 0x69e429: 7506 JNZ 0x69e431
    if(integer::condition("JNZ",flags)) goto L0069e431;
  }
  L0069e42b: { // 0x69e42b: 81cd80000000 OR EBP, 0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e431: { // 0x69e431: 668b16 MOV DX, word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e434: { // 0x69e434: 668b4602 MOV AX, word ptr [ESI + 2]
    s.ax = with_ax(s.ax, m.r16((s.si+2u)));
  }
  L0069e438: { // 0x69e438: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e43a: { // 0x69e43a: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e43c: { // 0x69e43c: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e441: { // 0x69e441: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e446: { // 0x69e446: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e44a: { // 0x69e44a: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e44e: { // 0x69e44e: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e452: { // 0x69e452: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e453: { // 0x69e453: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e458: { // 0x69e458: e8a370eaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939741u); flags=s.arithmetic_flags;
  }
  L0069e45d: { // 0x69e45d: 849840010000 TEST byte ptr [EAX + 0x140], BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e463: { // 0x69e463: 7503 JNZ 0x69e468
    if(integer::condition("JNZ",flags)) goto L0069e468;
  }
  L0069e465: { // 0x69e465: 83cd01 OR EBP, 1
    s.bp = integer::logical((s.bp)|(1u),32,flags);
  }
  L0069e468: { // 0x69e468: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e46b: { // 0x69e46b: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0069e46f: { // 0x69e46f: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e471: { // 0x69e471: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e476: { // 0x69e476: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e47b: { // 0x69e47b: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e47f: { // 0x69e47f: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e483: { // 0x69e483: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e488: { // 0x69e488: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e489: { // 0x69e489: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e48d: { // 0x69e48d: e86e70eaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939794u); flags=s.arithmetic_flags;
  }
  L0069e492: { // 0x69e492: 849840010000 TEST byte ptr [EAX + 0x140], BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e498: { // 0x69e498: 7503 JNZ 0x69e49d
    if(integer::condition("JNZ",flags)) goto L0069e49d;
  }
  L0069e49a: { // 0x69e49a: 83cd20 OR EBP, 0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e49d: { // 0x69e49d: 668b0e MOV CX, word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e4a0: { // 0x69e4a0: 668b5602 MOV DX, word ptr [ESI + 2]
    s.dx = with_ax(s.dx, m.r16((s.si+2u)));
  }
  L0069e4a4: { // 0x69e4a4: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e4a6: { // 0x69e4a6: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e4ab: { // 0x69e4ab: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e4b0: { // 0x69e4b0: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e4b4: { // 0x69e4b4: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e4b8: { // 0x69e4b8: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069e4bc: { // 0x69e4bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e4bd: { // 0x69e4bd: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4c2: { // 0x69e4c2: e83970eaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939847u); flags=s.arithmetic_flags;
  }
  L0069e4c7: { // 0x69e4c7: 849840010000 TEST byte ptr [EAX + 0x140], BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e4cd: { // 0x69e4cd: 7502 JNZ 0x69e4d1
    if(integer::condition("JNZ",flags)) goto L0069e4d1;
  }
  L0069e4cf: { // 0x69e4cf: 0beb OR EBP, EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e4d1: { // 0x69e4d1: 668b16 MOV DX, word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e4d4: { // 0x69e4d4: 668b4602 MOV AX, word ptr [ESI + 2]
    s.ax = with_ax(s.ax, m.r16((s.si+2u)));
  }
  L0069e4d8: { // 0x69e4d8: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e4da: { // 0x69e4da: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e4dc: { // 0x69e4dc: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e4e1: { // 0x69e4e1: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e4e6: { // 0x69e4e6: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e4ea: { // 0x69e4ea: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e4ee: { // 0x69e4ee: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e4f2: { // 0x69e4f2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e4f3: { // 0x69e4f3: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e4f8: { // 0x69e4f8: e80370eaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939901u); flags=s.arithmetic_flags;
  }
  L0069e4fd: { // 0x69e4fd: 849840010000 TEST byte ptr [EAX + 0x140], BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e503: { // 0x69e503: 7503 JNZ 0x69e508
    if(integer::condition("JNZ",flags)) goto L0069e508;
  }
  L0069e505: { // 0x69e505: 83cd10 OR EBP, 0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e508: { // 0x69e508: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0069e50c: { // 0x69e50c: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e50f: { // 0x69e50f: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e511: { // 0x69e511: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e516: { // 0x69e516: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e51b: { // 0x69e51b: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e51f: { // 0x69e51f: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e523: { // 0x69e523: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e528: { // 0x69e528: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e529: { // 0x69e529: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e52d: { // 0x69e52d: e8ce6feaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6939954u); flags=s.arithmetic_flags;
  }
  L0069e532: { // 0x69e532: 849840010000 TEST byte ptr [EAX + 0x140], BL
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e538: { // 0x69e538: 7503 JNZ 0x69e53d
    if(integer::condition("JNZ",flags)) goto L0069e53d;
  }
  L0069e53a: { // 0x69e53a: 83cd08 OR EBP, 8
    s.bp = integer::logical((s.bp)|(8u),32,flags);
  }
  L0069e53d: { // 0x69e53d: 668b0e MOV CX, word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e540: { // 0x69e540: 668b5602 MOV DX, word ptr [ESI + 2]
    s.dx = with_ax(s.dx, m.r16((s.si+2u)));
  }
  L0069e544: { // 0x69e544: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e546: { // 0x69e546: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e548: { // 0x69e548: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e54d: { // 0x69e54d: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e551: { // 0x69e551: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e556: { // 0x69e556: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e55a: { // 0x69e55a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e55b: { // 0x69e55b: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e560: { // 0x69e560: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e564: { // 0x69e564: e8976feaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940009u); flags=s.arithmetic_flags;
  }
  L0069e569: { // 0x69e569: 8a8840010000 MOV CL, byte ptr [EAX + 0x140]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000140u)));
  }
  L0069e56f: { // 0x69e56f: e9cb010000 JMP 0x69e73f
    goto L0069e73f;
  }
  L0069e574: { // 0x69e574: 8b802c010000 MOV EAX, dword ptr [EAX + 0x12c]
    s.ax = m.r32((s.ax+0x0000012cu));
  }
  L0069e57a: { // 0x69e57a: a818 TEST AL, 0x18
    (void)integer::logical(((s.ax & 0xffu))&(0x00000018u),8,flags);
  }
  L0069e57c: { // 0x69e57c: 7505 JNZ 0x69e583
    if(integer::condition("JNZ",flags)) goto L0069e583;
  }
  L0069e57e: { // 0x69e57e: bffeffffff MOV EDI, 0xfffffffe
    s.di = 0xfffffffeu;
  }
  L0069e583: { // 0x69e583: bb08000000 MOV EBX, 8
    s.bx = 8u;
  }
  L0069e588: { // 0x69e588: 84c3 TEST BL, AL
    (void)integer::logical(((s.bx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069e58a: { // 0x69e58a: 0f84c4010000 JZ 0x69e754
    if(integer::condition("JZ",flags)) goto L0069e754;
  }
  L0069e590: { // 0x69e590: 668b16 MOV DX, word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e593: { // 0x69e593: 668b4602 MOV AX, word ptr [ESI + 2]
    s.ax = with_ax(s.ax, m.r16((s.si+2u)));
  }
  L0069e597: { // 0x69e597: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e599: { // 0x69e599: 6648 DEC AX
    s.ax = with_ax(s.ax, integer::decrement((s.ax & 0xffffu),16,flags));
  }
  L0069e59b: { // 0x69e59b: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e5a0: { // 0x69e5a0: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e5a5: { // 0x69e5a5: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e5a9: { // 0x69e5a9: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e5ad: { // 0x69e5ad: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e5b1: { // 0x69e5b1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e5b2: { // 0x69e5b2: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5b7: { // 0x69e5b7: e8446feaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940092u); flags=s.arithmetic_flags;
  }
  L0069e5bc: { // 0x69e5bc: 84982c010000 TEST byte ptr [EAX + 0x12c], BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5c2: { // 0x69e5c2: 7505 JNZ 0x69e5c9
    if(integer::condition("JNZ",flags)) goto L0069e5c9;
  }
  L0069e5c4: { // 0x69e5c4: bd40000000 MOV EBP, 0x40
    s.bp = 0x00000040u;
  }
  L0069e5c9: { // 0x69e5c9: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0069e5cd: { // 0x69e5cd: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e5d0: { // 0x69e5d0: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e5d2: { // 0x69e5d2: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e5d7: { // 0x69e5d7: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e5dc: { // 0x69e5dc: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e5e0: { // 0x69e5e0: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e5e4: { // 0x69e5e4: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e5e9: { // 0x69e5e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e5ea: { // 0x69e5ea: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e5ee: { // 0x69e5ee: e80d6feaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940147u); flags=s.arithmetic_flags;
  }
  L0069e5f3: { // 0x69e5f3: 84982c010000 TEST byte ptr [EAX + 0x12c], BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e5f9: { // 0x69e5f9: 7506 JNZ 0x69e601
    if(integer::condition("JNZ",flags)) goto L0069e601;
  }
  L0069e5fb: { // 0x69e5fb: 81cd80000000 OR EBP, 0x80
    s.bp = integer::logical((s.bp)|(0x00000080u),32,flags);
  }
  L0069e601: { // 0x69e601: 668b0e MOV CX, word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e604: { // 0x69e604: 668b5602 MOV DX, word ptr [ESI + 2]
    s.dx = with_ax(s.dx, m.r16((s.si+2u)));
  }
  L0069e608: { // 0x69e608: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e60a: { // 0x69e60a: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e60c: { // 0x69e60c: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e611: { // 0x69e611: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e615: { // 0x69e615: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e61a: { // 0x69e61a: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e61e: { // 0x69e61e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e61f: { // 0x69e61f: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e624: { // 0x69e624: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e628: { // 0x69e628: e8d36eeaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940205u); flags=s.arithmetic_flags;
  }
  L0069e62d: { // 0x69e62d: 84982c010000 TEST byte ptr [EAX + 0x12c], BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e633: { // 0x69e633: 7503 JNZ 0x69e638
    if(integer::condition("JNZ",flags)) goto L0069e638;
  }
  L0069e635: { // 0x69e635: 83cd01 OR EBP, 1
    s.bp = integer::logical((s.bp)|(1u),32,flags);
  }
  L0069e638: { // 0x69e638: 668b16 MOV DX, word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e63b: { // 0x69e63b: 668b4602 MOV AX, word ptr [ESI + 2]
    s.ax = with_ax(s.ax, m.r16((s.si+2u)));
  }
  L0069e63f: { // 0x69e63f: 664a DEC DX
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L0069e641: { // 0x69e641: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e646: { // 0x69e646: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e64b: { // 0x69e64b: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e64f: { // 0x69e64f: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e653: { // 0x69e653: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e657: { // 0x69e657: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e658: { // 0x69e658: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e65d: { // 0x69e65d: e89e6eeaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940258u); flags=s.arithmetic_flags;
  }
  L0069e662: { // 0x69e662: 84982c010000 TEST byte ptr [EAX + 0x12c], BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e668: { // 0x69e668: 7503 JNZ 0x69e66d
    if(integer::condition("JNZ",flags)) goto L0069e66d;
  }
  L0069e66a: { // 0x69e66a: 83cd20 OR EBP, 0x20
    s.bp = integer::logical((s.bp)|(0x00000020u),32,flags);
  }
  L0069e66d: { // 0x69e66d: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e670: { // 0x69e670: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0069e674: { // 0x69e674: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e676: { // 0x69e676: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e67b: { // 0x69e67b: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e680: { // 0x69e680: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e684: { // 0x69e684: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e688: { // 0x69e688: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e68d: { // 0x69e68d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e68e: { // 0x69e68e: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e692: { // 0x69e692: e8696eeaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940311u); flags=s.arithmetic_flags;
  }
  L0069e697: { // 0x69e697: 84982c010000 TEST byte ptr [EAX + 0x12c], BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e69d: { // 0x69e69d: 7503 JNZ 0x69e6a2
    if(integer::condition("JNZ",flags)) goto L0069e6a2;
  }
  L0069e69f: { // 0x69e69f: 83cd02 OR EBP, 2
    s.bp = integer::logical((s.bp)|(2u),32,flags);
  }
  L0069e6a2: { // 0x69e6a2: 668b0e MOV CX, word ptr [ESI]
    s.cx = with_ax(s.cx, m.r16((s.si)));
  }
  L0069e6a5: { // 0x69e6a5: 668b5602 MOV DX, word ptr [ESI + 2]
    s.dx = with_ax(s.dx, m.r16((s.si+2u)));
  }
  L0069e6a9: { // 0x69e6a9: 6649 DEC CX
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L0069e6ab: { // 0x69e6ab: 6642 INC DX
    s.dx = with_ax(s.dx, integer::increment((s.dx & 0xffffu),16,flags));
  }
  L0069e6ad: { // 0x69e6ad: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0069e6b2: { // 0x69e6b2: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0069e6b6: { // 0x69e6b6: 668954241a MOV word ptr [ESP + 0x1a], DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0069e6bb: { // 0x69e6bb: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069e6bf: { // 0x69e6bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069e6c0: { // 0x69e6c0: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6c5: { // 0x69e6c5: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e6c9: { // 0x69e6c9: e8326eeaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940366u); flags=s.arithmetic_flags;
  }
  L0069e6ce: { // 0x69e6ce: 84982c010000 TEST byte ptr [EAX + 0x12c], BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e6d4: { // 0x69e6d4: 7503 JNZ 0x69e6d9
    if(integer::condition("JNZ",flags)) goto L0069e6d9;
  }
  L0069e6d6: { // 0x69e6d6: 83cd10 OR EBP, 0x10
    s.bp = integer::logical((s.bp)|(0x00000010u),32,flags);
  }
  L0069e6d9: { // 0x69e6d9: 668b4602 MOV AX, word ptr [ESI + 2]
    s.ax = with_ax(s.ax, m.r16((s.si+2u)));
  }
  L0069e6dd: { // 0x69e6dd: 668b16 MOV DX, word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L0069e6e0: { // 0x69e6e0: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e6e2: { // 0x69e6e2: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0069e6e7: { // 0x69e6e7: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0069e6ec: { // 0x69e6ec: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069e6f0: { // 0x69e6f0: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0069e6f4: { // 0x69e6f4: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069e6f8: { // 0x69e6f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069e6f9: { // 0x69e6f9: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e6fe: { // 0x69e6fe: e8fd6deaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940419u); flags=s.arithmetic_flags;
  }
  L0069e703: { // 0x69e703: 84982c010000 TEST byte ptr [EAX + 0x12c], BL
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&((s.bx & 0xffu)),8,flags);
  }
  L0069e709: { // 0x69e709: 7502 JNZ 0x69e70d
    if(integer::condition("JNZ",flags)) goto L0069e70d;
  }
  L0069e70b: { // 0x69e70b: 0beb OR EBP, EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L0069e70d: { // 0x69e70d: 668b06 MOV AX, word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L0069e710: { // 0x69e710: 668b4e02 MOV CX, word ptr [ESI + 2]
    s.cx = with_ax(s.cx, m.r16((s.si+2u)));
  }
  L0069e714: { // 0x69e714: 6640 INC AX
    s.ax = with_ax(s.ax, integer::increment((s.ax & 0xffffu),16,flags));
  }
  L0069e716: { // 0x69e716: 6641 INC CX
    s.cx = with_ax(s.cx, integer::increment((s.cx & 0xffffu),16,flags));
  }
  L0069e718: { // 0x69e718: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0069e71d: { // 0x69e71d: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0069e722: { // 0x69e722: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0069e726: { // 0x69e726: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0069e72a: { // 0x69e72a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e72b: { // 0x69e72b: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0069e730: { // 0x69e730: 8954241c MOV dword ptr [ESP + 0x1c], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0069e734: { // 0x69e734: e8c76deaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6940473u); flags=s.arithmetic_flags;
  }
  L0069e739: { // 0x69e739: 8a882c010000 MOV CL, byte ptr [EAX + 0x12c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000012cu)));
  }
  L0069e73f: { // 0x69e73f: 84cb TEST BL, CL
    (void)integer::logical(((s.bx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069e741: { // 0x69e741: 7503 JNZ 0x69e746
    if(integer::condition("JNZ",flags)) goto L0069e746;
  }
  L0069e743: { // 0x69e743: 83cd04 OR EBP, 4
    s.bp = integer::logical((s.bp)|(4u),32,flags);
  }
  L0069e746: { // 0x69e746: 0fbe8564727900 MOVSX EAX, byte ptr [EBP + 0x797264]
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
  L0069e751: { // 0x69e751: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069e754: { // 0x69e754: 8bc7 MOV EAX, EDI
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
  L0069e75a: { // 0x69e75a: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002a0410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a0410: { // 0x6a0410: a12ca88100 MOV EAX, dword ptr [0x81a82c]
    s.ax = m.r32((0x0081a82cu));
  }
  L006a0415: { // 0x6a0415: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006a0418: { // 0x6a0418: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a041a: { // 0x6a041a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a041b: { // 0x6a041b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a041c: { // 0x6a041c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a041d: { // 0x6a041d: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L006a041f: { // 0x6a041f: 0f858a010000 JNZ 0x6a05af
    if(integer::condition("JNZ",flags)) goto L006a05af;
  }
  L006a0425: { // 0x6a0425: 8b7c241c MOV EDI, dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L006a0429: { // 0x6a0429: a16c89a200 MOV EAX, dword ptr [0xa2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006a042e: { // 0x6a042e: 39475c CMP dword ptr [EDI + 0x5c], EAX
    (void)integer::sub(m.r32((s.di+0x0000005cu)),s.ax,32,flags);
  }
  L006a0431: { // 0x6a0431: 0f8478010000 JZ 0x6a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a0437: { // 0x6a0437: f6872c01000008 TEST byte ptr [EDI + 0x12c], 8
    (void)integer::logical((m.r8((s.di+0x0000012cu)))&(8u),8,flags);
  }
  L006a043e: { // 0x6a043e: 750e JNZ 0x6a044e
    if(integer::condition("JNZ",flags)) goto L006a044e;
  }
  L006a0440: { // 0x6a0440: 8a8f38010000 MOV CL, byte ptr [EDI + 0x138]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000138u)));
  }
  L006a0446: { // 0x6a0446: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0448: { // 0x6a0448: 0f8461010000 JZ 0x6a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a044e: { // 0x6a044e: 89475c MOV dword ptr [EDI + 0x5c], EAX
    m.w32((s.di+0x0000005cu), s.ax);
  }
  L006a0451: { // 0x6a0451: 8d44240c LEA EAX, [ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L006a0455: { // 0x6a0455: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006a0456: { // 0x6a0456: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a0457: { // 0x6a0457: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006a0459: { // 0x6a0459: e80255ddff CALL 0x475960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475960u,6947934u); flags=s.arithmetic_flags;
  }
  L006a045e: { // 0x6a045e: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006a0460: { // 0x6a0460: 8b7004 MOV ESI, dword ptr [EAX + 4]
    s.si = m.r32((s.ax+4u));
  }
  L006a0463: { // 0x6a0463: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L006a0466: { // 0x6a0466: 8b872c010000 MOV EAX, dword ptr [EDI + 0x12c]
    s.ax = m.r32((s.di+0x0000012cu));
  }
  L006a046c: { // 0x6a046c: a808 TEST AL, 8
    (void)integer::logical(((s.ax & 0xffu))&(8u),8,flags);
  }
  L006a046e: { // 0x6a046e: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006a0472: { // 0x6a0472: 744b JZ 0x6a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0474: { // 0x6a0474: a810 TEST AL, 0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L006a0476: { // 0x6a0476: 7447 JZ 0x6a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0478: { // 0x6a0478: 8d0449 LEA EAX, [ECX + ECX*2]
    s.ax = (s.cx+(s.cx * 2u));
  }
  L006a047b: { // 0x6a047b: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L006a047e: { // 0x6a047e: c1e002 SHL EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::left);
  }
  L006a0481: { // 0x6a0481: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0482: { // 0x6a0482: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0484: { // 0x6a0484: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L006a0486: { // 0x6a0486: 8d0449 LEA EAX, [ECX + ECX*2]
    s.ax = (s.cx+(s.cx * 2u));
  }
  L006a0489: { // 0x6a0489: d1ff SAR EDI, 1
    s.di = integer::shift(s.di,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a048b: { // 0x6a048b: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L006a048e: { // 0x6a048e: d1e0 SHL EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::left);
  }
  L006a0490: { // 0x6a0490: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0491: { // 0x6a0491: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0493: { // 0x6a0493: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006a0495: { // 0x6a0495: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L006a0497: { // 0x6a0497: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L006a049a: { // 0x6a049a: 2bc6 SUB EAX, ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a049c: { // 0x6a049c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a049e: { // 0x6a049e: c1e002 SHL EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::left);
  }
  L006a04a1: { // 0x6a04a1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04a2: { // 0x6a04a2: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04a4: { // 0x6a04a4: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04a6: { // 0x6a04a6: 03f8 ADD EDI, EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04a8: { // 0x6a04a8: 8d0476 LEA EAX, [ESI + ESI*2]
    s.ax = (s.si+(s.si * 2u));
  }
  L006a04ab: { // 0x6a04ab: d1f9 SAR ECX, 1
    s.cx = integer::shift(s.cx,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ad: { // 0x6a04ad: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L006a04b0: { // 0x6a04b0: 897c2410 MOV dword ptr [ESP + 0x10], EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04b4: { // 0x6a04b4: d1e0 SHL EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::left);
  }
  L006a04b6: { // 0x6a04b6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04b7: { // 0x6a04b7: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04b9: { // 0x6a04b9: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04bb: { // 0x6a04bb: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a04bd: { // 0x6a04bd: eb45 JMP 0x6a0504
    goto L006a0504;
  }
  L006a04bf: { // 0x6a04bf: 8d0449 LEA EAX, [ECX + ECX*2]
    s.ax = (s.cx+(s.cx * 2u));
  }
  L006a04c2: { // 0x6a04c2: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L006a04c5: { // 0x6a04c5: c1e002 SHL EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::left);
  }
  L006a04c8: { // 0x6a04c8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04c9: { // 0x6a04c9: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04cb: { // 0x6a04cb: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L006a04cd: { // 0x6a04cd: 8d0449 LEA EAX, [ECX + ECX*2]
    s.ax = (s.cx+(s.cx * 2u));
  }
  L006a04d0: { // 0x6a04d0: d1ff SAR EDI, 1
    s.di = integer::shift(s.di,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04d2: { // 0x6a04d2: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L006a04d5: { // 0x6a04d5: d1e0 SHL EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::left);
  }
  L006a04d7: { // 0x6a04d7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04d8: { // 0x6a04d8: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04da: { // 0x6a04da: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006a04dc: { // 0x6a04dc: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L006a04de: { // 0x6a04de: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L006a04e1: { // 0x6a04e1: 2bc6 SUB EAX, ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a04e3: { // 0x6a04e3: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a04e5: { // 0x6a04e5: c1e002 SHL EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::left);
  }
  L006a04e8: { // 0x6a04e8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04e9: { // 0x6a04e9: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04eb: { // 0x6a04eb: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ed: { // 0x6a04ed: 03f8 ADD EDI, EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04ef: { // 0x6a04ef: 8d0476 LEA EAX, [ESI + ESI*2]
    s.ax = (s.si+(s.si * 2u));
  }
  L006a04f2: { // 0x6a04f2: d1f9 SAR ECX, 1
    s.cx = integer::shift(s.cx,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04f4: { // 0x6a04f4: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L006a04f7: { // 0x6a04f7: 897c2410 MOV dword ptr [ESP + 0x10], EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04fb: { // 0x6a04fb: d1e0 SHL EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::left);
  }
  L006a04fd: { // 0x6a04fd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04fe: { // 0x6a04fe: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0500: { // 0x6a0500: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0502: { // 0x6a0502: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a0504: { // 0x6a0504: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L006a0506: { // 0x6a0506: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L006a0508: { // 0x6a0508: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0509: { // 0x6a0509: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a050f: { // 0x6a050f: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006a0511: { // 0x6a0511: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a0513: { // 0x6a0513: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L006a0515: { // 0x6a0515: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0518: { // 0x6a0518: e8937affff CALL 0x697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6948125u); flags=s.arithmetic_flags;
  }
  L006a051d: { // 0x6a051d: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006a051f: { // 0x6a051f: 8bc5 MOV EAX, EBP
    s.ax = s.bp;
  }
  L006a0521: { // 0x6a0521: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0522: { // 0x6a0522: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a0528: { // 0x6a0528: 89742410 MOV dword ptr [ESP + 0x10], ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006a052c: { // 0x6a052c: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a052e: { // 0x6a052e: 8b93b4000000 MOV EDX, dword ptr [EBX + 0xb4]
    s.dx = m.r32((s.bx+0x000000b4u));
  }
  L006a0534: { // 0x6a0534: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0537: { // 0x6a0537: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006a0539: { // 0x6a0539: 8b8bb0000000 MOV ECX, dword ptr [EBX + 0xb0]
    s.cx = m.r32((s.bx+0x000000b0u));
  }
  L006a053f: { // 0x6a053f: 2bf1 SUB ESI, ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L006a0541: { // 0x6a0541: 8b0d70198200 MOV ECX, dword ptr [0x821970]
    s.cx = m.r32((0x00821970u));
  }
  L006a0547: { // 0x6a0547: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0549: { // 0x6a0549: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006a054a: { // 0x6a054a: 8d51e2 LEA EDX, [ECX - 0x1e]
    s.dx = (s.cx-0x0000001eu);
  }
  L006a054d: { // 0x6a054d: 3bf2 CMP ESI, EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L006a054f: { // 0x6a054f: 7c5e JL 0x6a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0551: { // 0x6a0551: 83f8e2 CMP EAX, -0x1e
    (void)integer::sub(s.ax,0xffffffe2u,32,flags);
  }
  L006a0554: { // 0x6a0554: 7c59 JL 0x6a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0556: { // 0x6a0556: 8b1578198200 MOV EDX, dword ptr [0x821978]
    s.dx = m.r32((0x00821978u));
  }
  L006a055c: { // 0x6a055c: 8d4c0a1e LEA ECX, [EDX + ECX + 0x1e]
    s.cx = (s.dx+s.cx+0x0000001eu);
  }
  L006a0560: { // 0x6a0560: 3bf1 CMP ESI, ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L006a0562: { // 0x6a0562: 7f4b JG 0x6a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0564: { // 0x6a0564: 8b1574198200 MOV EDX, dword ptr [0x821974]
    s.dx = m.r32((0x00821974u));
  }
  L006a056a: { // 0x6a056a: 8b0d7c198200 MOV ECX, dword ptr [0x82197c]
    s.cx = m.r32((0x0082197cu));
  }
  L006a0570: { // 0x6a0570: 8d54110f LEA EDX, [ECX + EDX + 0xf]
    s.dx = (s.cx+s.dx+0x0000000fu);
  }
  L006a0574: { // 0x6a0574: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0576: { // 0x6a0576: 7f37 JG 0x6a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0578: { // 0x6a0578: 8b83e0000000 MOV EAX, dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a057e: { // 0x6a057e: 3d1f030000 CMP EAX, 0x31f
    (void)integer::sub(s.ax,0x0000031fu,32,flags);
  }
  L006a0583: { // 0x6a0583: 7d18 JGE 0x6a059d
    if(integer::condition("JGE",flags)) goto L006a059d;
  }
  L006a0585: { // 0x6a0585: 8b4c241c MOV ECX, dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006a0589: { // 0x6a0589: 898c83e4000000 MOV dword ptr [EBX + EAX*4 + 0xe4], ECX
    m.w32((s.bx+(s.ax * 4u)+0x000000e4u), s.cx);
  }
  L006a0590: { // 0x6a0590: 8b83e0000000 MOV EAX, dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a0596: { // 0x6a0596: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006a0597: { // 0x6a0597: 8983e0000000 MOV dword ptr [EBX + 0xe0], EAX
    m.w32((s.bx+0x000000e0u), s.ax);
  }
  L006a059d: { // 0x6a059d: 8b54241c MOV EDX, dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L006a05a1: { // 0x6a05a1: c6823801000000 MOV byte ptr [EDX + 0x138], 0
    m.w8((s.dx+0x00000138u), 0u);
  }
  L006a05a8: { // 0x6a05a8: c6837d0d000001 MOV byte ptr [EBX + 0xd7d], 1
    m.w8((s.bx+0x00000d7du), 1u);
  }
  L006a05af: { // 0x6a05af: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a05b0: { // 0x6a05b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a05b1: { // 0x6a05b1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a05b2: { // 0x6a05b2: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006a05b5: { // 0x6a05b5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00075960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00475960: { // 0x475960: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00475963: { // 0x475963: 8b4124 MOV EAX, dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  L00475966: { // 0x475966: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00475967: { // 0x475967: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00475968: { // 0x475968: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L0047596c: { // 0x47596c: 0fbf7c240a MOVSX EDI, word ptr [ESP + 0xa]
    s.di = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000000au)),16));
  }
  L00475971: { // 0x475971: 0fbff0 MOVSX ESI, AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00475974: { // 0x475974: c1e608 SHL ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::left);
  }
  L00475977: { // 0x475977: b880000000 MOV EAX, 0x80
    s.ax = 0x00000080u;
  }
  L0047597c: { // 0x47597c: c1e708 SHL EDI, 8
    s.di = integer::shift(s.di,8u,32,flags,integer::Shift::left);
  }
  L0047597f: { // 0x47597f: 03f0 ADD ESI, EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00475981: { // 0x475981: 03f8 ADD EDI, EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00475983: { // 0x475983: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L00475987: { // 0x475987: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L0047598b: { // 0x47598b: 8d442408 LEA EAX, [ESP + 8]
    s.ax = (f.sp+8u);
  }
  L0047598f: { // 0x47598f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00475990: { // 0x475990: e82ba9ffff CALL 0x4702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,4675989u); flags=s.arithmetic_flags;
  }
  L00475995: { // 0x475995: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00475999: { // 0x475999: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0047599b: { // 0x47599b: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L0047599d: { // 0x47599d: 897a04 MOV dword ptr [EDX + 4], EDI
    m.w32((s.dx+4u), s.di);
  }
  L004759a0: { // 0x4759a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004759a1: { // 0x4759a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004759a2: { // 0x4759a2: 894208 MOV dword ptr [EDX + 8], EAX
    m.w32((s.dx+8u), s.ax);
  }
  L004759a5: { // 0x4759a5: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004759a7: { // 0x4759a7: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004759aa: { // 0x4759aa: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697fb0: { // 0x697fb0: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00697fb3: { // 0x697fb3: 81f9d8020000 CMP ECX, 0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  L00697fb9: { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L00697fbd: { // 0x697fbd: c744240000000000 MOV dword ptr [ESP], 0
    m.w32((f.sp), 0u);
  }
  L00697fc5: { // 0x697fc5: 7c08 JL 0x697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  L00697fc7: { // 0x697fc7: c744240001000000 MOV dword ptr [ESP], 1
    m.w32((f.sp), 1u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00697fd3: { // 0x697fd3: dc0d905faa00 FMUL qword ptr [0xaa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697fd9: { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697fdd: { // 0x697fdd: dc0528577800 FADD qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697fe3: { // 0x697fe3: e8682a0d00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914024u); flags=s.arithmetic_flags;
  }
  L00697fe8: { // 0x697fe8: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00697feb: { // 0x697feb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX, dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX, 0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX, dword ptr [0x7c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x76aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX, dword ptr [0x7c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP], EDX
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
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00147f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547f40: { // 0x547f40: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00547f44: { // 0x547f44: 8b91f0000000 MOV EDX, dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L00547f4a: { // 0x547f4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547f4b: { // 0x547f4b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547f4c: { // 0x547f4c: 0fbf30 MOVSX ESI, word ptr [EAX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00547f4f: { // 0x547f4f: 0fbf4002 MOVSX EAX, word ptr [EAX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+2u)),16));
  }
  L00547f53: { // 0x547f53: 8d3c30 LEA EDI, [EAX + ESI]
    s.di = (s.ax+s.si);
  }
  L00547f56: { // 0x547f56: 3bfa CMP EDI, EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00547f58: { // 0x547f58: 7e24 JLE 0x547f7e
    if(integer::condition("JLE",flags)) goto L00547f7e;
  }
  L00547f5a: { // 0x547f5a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547f5b: { // 0x547f5b: 8bde MOV EBX, ESI
    s.bx = s.si;
  }
  L00547f5d: { // 0x547f5d: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00547f5f: { // 0x547f5f: 3bda CMP EBX, EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547f61: { // 0x547f61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547f62: { // 0x547f62: 7d1a JGE 0x547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f64: { // 0x547f64: 2bc6 SUB EAX, ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00547f66: { // 0x547f66: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00547f68: { // 0x547f68: 7d14 JGE 0x547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f6a: { // 0x547f6a: 8b81f4000000 MOV EAX, dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L00547f70: { // 0x547f70: 8d0c42 LEA ECX, [EDX + EAX*2]
    s.cx = (s.dx+(s.ax * 2u));
  }
  L00547f73: { // 0x547f73: 3bf9 CMP EDI, ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00547f75: { // 0x547f75: 7f07 JG 0x547f7e
    if(integer::condition("JG",flags)) goto L00547f7e;
  }
  L00547f77: { // 0x547f77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f78: { // 0x547f78: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00547f7a: { // 0x547f7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f7b: { // 0x547f7b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00547f7e: { // 0x547f7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f7f: { // 0x547f7f: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00547f81: { // 0x547f81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f82: { // 0x547f82: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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



} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5526784u:f_00145500(m,s,child,{});break;
case 6939520u:f_0029e380(m,s,child,{});break;
case 6947856u:f_002a0410(m,s,child,{});break;
case 4675936u:f_00075960(m,s,child,{});break;
case 6913968u:f_00297fb0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5537600u:f_00147f40(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
default:throw std::domain_error("recovery777 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00499990(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00499990: { // 0x499990: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L00499993: { // 0x499993: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00499994: { // 0x499994: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00499995: { // 0x499995: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499996: { // 0x499996: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L0049999a: { // 0x49999a: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0049999c: { // 0x49999c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049999d: { // 0x49999d: e85ebb0a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4823458u); flags=s.arithmetic_flags;
  }
  L004999a2: { // 0x4999a2: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004999a4: { // 0x4999a4: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L004999a8: { // 0x4999a8: 8b8540010000 MOV EAX,dword ptr [EBP + 0x140]
    s.ax = m.r32((s.bp+0x00000140u));
  }
  L004999ae: { // 0x4999ae: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004999b0: { // 0x4999b0: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L004999b2: { // 0x4999b2: f6d1 NOT CL
    s.cx = with_al(s.cx, (~((s.cx & 0xffu))&integer::mask(8)));
  }
  L004999b4: { // 0x4999b4: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004999b7: { // 0x4999b7: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L004999b9: { // 0x4999b9: 884c240f MOV byte ptr [ESP + 0xf],CL
    m.w8((f.sp+0x0000000fu), (s.cx & 0xffu));
  }
  L004999bd: { // 0x4999bd: 7410 JZ 0x004999cf
    if(integer::condition("JZ",flags)) goto L004999cf;
  }
  L004999bf: { // 0x4999bf: 8a8d2c010000 MOV CL,byte ptr [EBP + 0x12c]
    s.cx = with_al(s.cx, m.r8((s.bp+0x0000012cu)));
  }
  L004999c5: { // 0x4999c5: c644240e00 MOV byte ptr [ESP + 0xe],0x0
    m.w8((f.sp+0x0000000eu), 0x00000000u);
  }
  L004999ca: { // 0x4999ca: f6c108 TEST CL,0x8
    (void)integer::logical(((s.cx & 0xffu))&(0x00000008u),8,flags);
  }
  L004999cd: { // 0x4999cd: 7505 JNZ 0x004999d4
    if(integer::condition("JNZ",flags)) goto L004999d4;
  }
  L004999cf: { // 0x4999cf: c644240e01 MOV byte ptr [ESP + 0xe],0x1
    m.w8((f.sp+0x0000000eu), 0x00000001u);
  }
  L004999d4: { // 0x4999d4: 8a4c240e MOV CL,byte ptr [ESP + 0xe]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000000eu)));
  }
  L004999d8: { // 0x4999d8: 24bf AND AL,0xbf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000bfu),8,flags));
  }
  L004999da: { // 0x4999da: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L004999dc: { // 0x4999dc: 884c242c MOV byte ptr [ESP + 0x2c],CL
    m.w8((f.sp+0x0000002cu), (s.cx & 0xffu));
  }
  L004999e0: { // 0x4999e0: 898540010000 MOV dword ptr [EBP + 0x140],EAX
    m.w32((s.bp+0x00000140u), s.ax);
  }
  L004999e6: { // 0x4999e6: 8b852c010000 MOV EAX,dword ptr [EBP + 0x12c]
    s.ax = m.r32((s.bp+0x0000012cu));
  }
  L004999ec: { // 0x4999ec: 0c08 OR AL,0x8
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000008u),8,flags));
  }
  L004999ee: { // 0x4999ee: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004999f0: { // 0x4999f0: 89852c010000 MOV dword ptr [EBP + 0x12c],EAX
    m.w32((s.bp+0x0000012cu), s.ax);
  }
  L004999f6: { // 0x4999f6: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L004999fc: { // 0x4999fc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004999fd: { // 0x4999fd: e87e492000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4823554u); flags=s.arithmetic_flags;
  }
  L00499a02: { // 0x499a02: 3a8520010000 CMP AL,byte ptr [EBP + 0x120]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.bp+0x00000120u)),8,flags);
  }
  L00499a08: { // 0x499a08: 740b JZ 0x00499a15
    if(integer::condition("JZ",flags)) goto L00499a15;
  }
  L00499a0a: { // 0x499a0a: c644240e01 MOV byte ptr [ESP + 0xe],0x1
    m.w8((f.sp+0x0000000eu), 0x00000001u);
  }
  L00499a0f: { // 0x499a0f: 888520010000 MOV byte ptr [EBP + 0x120],AL
    m.w8((s.bp+0x00000120u), (s.ax & 0xffu));
  }
  L00499a15: { // 0x499a15: 80bd20010000ff CMP byte ptr [EBP + 0x120],0xff
    (void)integer::sub(m.r8((s.bp+0x00000120u)),0x000000ffu,8,flags);
  }
  L00499a1c: { // 0x499a1c: 750e JNZ 0x00499a2c
    if(integer::condition("JNZ",flags)) goto L00499a2c;
  }
  L00499a1e: { // 0x499a1e: 8b852c010000 MOV EAX,dword ptr [EBP + 0x12c]
    s.ax = m.r32((s.bp+0x0000012cu));
  }
  L00499a24: { // 0x499a24: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00499a26: { // 0x499a26: 89852c010000 MOV dword ptr [EBP + 0x12c],EAX
    m.w32((s.bp+0x0000012cu), s.ax);
  }
  L00499a2c: { // 0x499a2c: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499a32: { // 0x499a32: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00499a34: { // 0x499a34: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499a35: { // 0x499a35: e846492000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4823610u); flags=s.arithmetic_flags;
  }
  L00499a3a: { // 0x499a3a: 3a8521010000 CMP AL,byte ptr [EBP + 0x121]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.bp+0x00000121u)),8,flags);
  }
  L00499a40: { // 0x499a40: 740b JZ 0x00499a4d
    if(integer::condition("JZ",flags)) goto L00499a4d;
  }
  L00499a42: { // 0x499a42: c644240e01 MOV byte ptr [ESP + 0xe],0x1
    m.w8((f.sp+0x0000000eu), 0x00000001u);
  }
  L00499a47: { // 0x499a47: 888521010000 MOV byte ptr [EBP + 0x121],AL
    m.w8((s.bp+0x00000121u), (s.ax & 0xffu));
  }
  L00499a4d: { // 0x499a4d: 80bd21010000ff CMP byte ptr [EBP + 0x121],0xff
    (void)integer::sub(m.r8((s.bp+0x00000121u)),0x000000ffu,8,flags);
  }
  L00499a54: { // 0x499a54: 750e JNZ 0x00499a64
    if(integer::condition("JNZ",flags)) goto L00499a64;
  }
  L00499a56: { // 0x499a56: 8b8540010000 MOV EAX,dword ptr [EBP + 0x140]
    s.ax = m.r32((s.bp+0x00000140u));
  }
  L00499a5c: { // 0x499a5c: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00499a5e: { // 0x499a5e: 898540010000 MOV dword ptr [EBP + 0x140],EAX
    m.w32((s.bp+0x00000140u), s.ax);
  }
  L00499a64: { // 0x499a64: 8a44240e MOV AL,byte ptr [ESP + 0xe]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000eu)));
  }
  L00499a68: { // 0x499a68: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499a6a: { // 0x499a6a: 740c JZ 0x00499a78
    if(integer::condition("JZ",flags)) goto L00499a78;
  }
  L00499a6c: { // 0x499a6c: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499a72: { // 0x499a72: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00499a73: { // 0x499a73: e898692000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4823672u); flags=s.arithmetic_flags;
  }
  L00499a78: { // 0x499a78: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499a79: { // 0x499a79: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00499a81: { // 0x499a81: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00499a85: { // 0x499a85: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00499a88: { // 0x499a88: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L00499a90: { // 0x499a90: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L00499a97: { // 0x499a97: 66030e ADD CX,word ptr [ESI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.si)),16,flags));
  }
  L00499a9a: { // 0x499a9a: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L00499a9e: { // 0x499a9e: 66035602 ADD DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags));
  }
  L00499aa2: { // 0x499aa2: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00499aa7: { // 0x499aa7: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499aab: { // 0x499aab: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00499ab0: { // 0x499ab0: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00499ab4: { // 0x499ab4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499ab5: { // 0x499ab5: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00499ab7: { // 0x499ab7: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00499abb: { // 0x499abb: e840ba0a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4823744u); flags=s.arithmetic_flags;
  }
  L00499ac0: { // 0x499ac0: 668b542414 MOV DX,word ptr [ESP + 0x14]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000014u)));
  }
  L00499ac5: { // 0x499ac5: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00499ac7: { // 0x499ac7: 663b16 CMP DX,word ptr [ESI]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.si)),16,flags);
  }
  L00499aca: { // 0x499aca: 750f JNZ 0x00499adb
    if(integer::condition("JNZ",flags)) goto L00499adb;
  }
  L00499acc: { // 0x499acc: 668b442416 MOV AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000016u)));
  }
  L00499ad1: { // 0x499ad1: 663b4602 CMP AX,word ptr [ESI + 0x2]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000002u)),16,flags);
  }
  L00499ad5: { // 0x499ad5: 0f8424010000 JZ 0x00499bff
    if(integer::condition("JZ",flags)) goto L00499bff;
  }
  L00499adb: { // 0x499adb: f6872c01000010 TEST byte ptr [EDI + 0x12c],0x10
    (void)integer::logical((m.r8((s.di+0x0000012cu)))&(0x00000010u),8,flags);
  }
  L00499ae2: { // 0x499ae2: 0f8517010000 JNZ 0x00499bff
    if(integer::condition("JNZ",flags)) goto L00499bff;
  }
  L00499ae8: { // 0x499ae8: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499aec: { // 0x499aec: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00499aee: { // 0x499aee: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499aef: { // 0x499aef: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499af5: { // 0x499af5: e886482000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4823802u); flags=s.arithmetic_flags;
  }
  L00499afa: { // 0x499afa: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00499afd: { // 0x499afd: 0f85b7000000 JNZ 0x00499bba
    if(integer::condition("JNZ",flags)) goto L00499bba;
  }
  L00499b03: { // 0x499b03: 8b872c010000 MOV EAX,dword ptr [EDI + 0x12c]
    s.ax = m.r32((s.di+0x0000012cu));
  }
  L00499b09: { // 0x499b09: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00499b0b: { // 0x499b0b: 7519 JNZ 0x00499b26
    if(integer::condition("JNZ",flags)) goto L00499b26;
  }
  L00499b0d: { // 0x499b0d: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00499b11: { // 0x499b11: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00499b13: { // 0x499b13: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499b17: { // 0x499b17: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00499b18: { // 0x499b18: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499b19: { // 0x499b19: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00499b1b: { // 0x499b1b: ff9290000000 CALL dword ptr [EDX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000090u)),4823841u); flags=s.arithmetic_flags;
  }
  L00499b21: { // 0x499b21: e9d9000000 JMP 0x00499bff
    goto L00499bff;
  }
  L00499b26: { // 0x499b26: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00499b28: { // 0x499b28: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499b29: { // 0x499b29: 89872c010000 MOV dword ptr [EDI + 0x12c],EAX
    m.w32((s.di+0x0000012cu), s.ax);
  }
  L00499b2f: { // 0x499b2f: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499b35: { // 0x499b35: e8d6682000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4823866u); flags=s.arithmetic_flags;
  }
  L00499b3a: { // 0x499b3a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00499b3c: { // 0x499b3c: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00499b3e: { // 0x499b3e: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00499b41: { // 0x499b41: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L00499b49: { // 0x499b49: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L00499b50: { // 0x499b50: 66034c2414 ADD CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000014u)),16,flags));
  }
  L00499b55: { // 0x499b55: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L00499b59: { // 0x499b59: 6603542416 ADD DX,word ptr [ESP + 0x16]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L00499b5e: { // 0x499b5e: 66894c2420 MOV word ptr [ESP + 0x20],CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L00499b63: { // 0x499b63: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00499b67: { // 0x499b67: 6689542422 MOV word ptr [ESP + 0x22],DX
    m.w16((f.sp+0x00000022u), (s.dx & 0xffffu));
  }
  L00499b6c: { // 0x499b6c: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00499b70: { // 0x499b70: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499b71: { // 0x499b71: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00499b73: { // 0x499b73: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00499b77: { // 0x499b77: e884b90a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4823932u); flags=s.arithmetic_flags;
  }
  L00499b7c: { // 0x499b7c: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499b82: { // 0x499b82: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00499b86: { // 0x499b86: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00499b88: { // 0x499b88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00499b89: { // 0x499b89: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00499b8b: { // 0x499b8b: e8f0472000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4823952u); flags=s.arithmetic_flags;
  }
  L00499b90: { // 0x499b90: 3a8620010000 CMP AL,byte ptr [ESI + 0x120]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.si+0x00000120u)),8,flags);
  }
  L00499b96: { // 0x499b96: 7412 JZ 0x00499baa
    if(integer::condition("JZ",flags)) goto L00499baa;
  }
  L00499b98: { // 0x499b98: 888620010000 MOV byte ptr [ESI + 0x120],AL
    m.w8((s.si+0x00000120u), (s.ax & 0xffu));
  }
  L00499b9e: { // 0x499b9e: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499ba4: { // 0x499ba4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499ba5: { // 0x499ba5: e866682000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4823978u); flags=s.arithmetic_flags;
  }
  L00499baa: { // 0x499baa: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00499bab: { // 0x499bab: 83fd08 CMP EBP,0x8
    (void)integer::sub(s.bp,0x00000008u,32,flags);
  }
  L00499bae: { // 0x499bae: 7c8c JL 0x00499b3c
    if(integer::condition("JL",flags)) goto L00499b3c;
  }
  L00499bb0: { // 0x499bb0: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L00499bb4: { // 0x499bb4: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L00499bb8: { // 0x499bb8: eb45 JMP 0x00499bff
    goto L00499bff;
  }
  L00499bba: { // 0x499bba: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L00499bbd: { // 0x499bbd: 741f JZ 0x00499bde
    if(integer::condition("JZ",flags)) goto L00499bde;
  }
  L00499bbf: { // 0x499bbf: f6872c01000008 TEST byte ptr [EDI + 0x12c],0x8
    (void)integer::logical((m.r8((s.di+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00499bc6: { // 0x499bc6: 7516 JNZ 0x00499bde
    if(integer::condition("JNZ",flags)) goto L00499bde;
  }
  L00499bc8: { // 0x499bc8: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00499bcc: { // 0x499bcc: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00499bce: { // 0x499bce: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00499bd2: { // 0x499bd2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499bd3: { // 0x499bd3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00499bd4: { // 0x499bd4: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00499bd6: { // 0x499bd6: ff9090000000 CALL dword ptr [EAX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000090u)),4824028u); flags=s.arithmetic_flags;
  }
  L00499bdc: { // 0x499bdc: eb21 JMP 0x00499bff
    goto L00499bff;
  }
  L00499bde: { // 0x499bde: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00499be0: { // 0x499be0: 7c1d JL 0x00499bff
    if(integer::condition("JL",flags)) goto L00499bff;
  }
  L00499be2: { // 0x499be2: 0fbe8f20010000 MOVSX ECX,byte ptr [EDI + 0x120]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x00000120u)),8));
  }
  L00499be9: { // 0x499be9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00499beb: { // 0x499beb: 7412 JZ 0x00499bff
    if(integer::condition("JZ",flags)) goto L00499bff;
  }
  L00499bed: { // 0x499bed: 888720010000 MOV byte ptr [EDI + 0x120],AL
    m.w8((s.di+0x00000120u), (s.ax & 0xffu));
  }
  L00499bf3: { // 0x499bf3: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499bf9: { // 0x499bf9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499bfa: { // 0x499bfa: e811682000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4824063u); flags=s.arithmetic_flags;
  }
  L00499bff: { // 0x499bff: 668b542414 MOV DX,word ptr [ESP + 0x14]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000014u)));
  }
  L00499c04: { // 0x499c04: 663b16 CMP DX,word ptr [ESI]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.si)),16,flags);
  }
  L00499c07: { // 0x499c07: 750f JNZ 0x00499c18
    if(integer::condition("JNZ",flags)) goto L00499c18;
  }
  L00499c09: { // 0x499c09: 668b442416 MOV AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000016u)));
  }
  L00499c0e: { // 0x499c0e: 663b4602 CMP AX,word ptr [ESI + 0x2]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000002u)),16,flags);
  }
  L00499c12: { // 0x499c12: 0f8424010000 JZ 0x00499d3c
    if(integer::condition("JZ",flags)) goto L00499d3c;
  }
  L00499c18: { // 0x499c18: f6874001000001 TEST byte ptr [EDI + 0x140],0x1
    (void)integer::logical((m.r8((s.di+0x00000140u)))&(0x00000001u),8,flags);
  }
  L00499c1f: { // 0x499c1f: 0f8517010000 JNZ 0x00499d3c
    if(integer::condition("JNZ",flags)) goto L00499d3c;
  }
  L00499c25: { // 0x499c25: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499c29: { // 0x499c29: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00499c2b: { // 0x499c2b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499c2c: { // 0x499c2c: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499c32: { // 0x499c32: e849472000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4824119u); flags=s.arithmetic_flags;
  }
  L00499c37: { // 0x499c37: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00499c3a: { // 0x499c3a: 0f85b7000000 JNZ 0x00499cf7
    if(integer::condition("JNZ",flags)) goto L00499cf7;
  }
  L00499c40: { // 0x499c40: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L00499c46: { // 0x499c46: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L00499c48: { // 0x499c48: 7519 JNZ 0x00499c63
    if(integer::condition("JNZ",flags)) goto L00499c63;
  }
  L00499c4a: { // 0x499c4a: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00499c4e: { // 0x499c4e: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00499c50: { // 0x499c50: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499c54: { // 0x499c54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00499c55: { // 0x499c55: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499c56: { // 0x499c56: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00499c58: { // 0x499c58: ff9290000000 CALL dword ptr [EDX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000090u)),4824158u); flags=s.arithmetic_flags;
  }
  L00499c5e: { // 0x499c5e: e9d9000000 JMP 0x00499d3c
    goto L00499d3c;
  }
  L00499c63: { // 0x499c63: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00499c65: { // 0x499c65: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499c66: { // 0x499c66: 898740010000 MOV dword ptr [EDI + 0x140],EAX
    m.w32((s.di+0x00000140u), s.ax);
  }
  L00499c6c: { // 0x499c6c: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499c72: { // 0x499c72: e899672000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4824183u); flags=s.arithmetic_flags;
  }
  L00499c77: { // 0x499c77: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00499c79: { // 0x499c79: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00499c7b: { // 0x499c7b: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00499c7e: { // 0x499c7e: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L00499c86: { // 0x499c86: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L00499c8d: { // 0x499c8d: 66034c2414 ADD CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000014u)),16,flags));
  }
  L00499c92: { // 0x499c92: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L00499c96: { // 0x499c96: 6603542416 ADD DX,word ptr [ESP + 0x16]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L00499c9b: { // 0x499c9b: 66894c2428 MOV word ptr [ESP + 0x28],CX
    m.w16((f.sp+0x00000028u), (s.cx & 0xffffu));
  }
  L00499ca0: { // 0x499ca0: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L00499ca4: { // 0x499ca4: 668954242a MOV word ptr [ESP + 0x2a],DX
    m.w16((f.sp+0x0000002au), (s.dx & 0xffffu));
  }
  L00499ca9: { // 0x499ca9: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00499cad: { // 0x499cad: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499cae: { // 0x499cae: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00499cb0: { // 0x499cb0: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00499cb4: { // 0x499cb4: e847b80a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4824249u); flags=s.arithmetic_flags;
  }
  L00499cb9: { // 0x499cb9: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499cbf: { // 0x499cbf: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00499cc3: { // 0x499cc3: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00499cc5: { // 0x499cc5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00499cc6: { // 0x499cc6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00499cc8: { // 0x499cc8: e8b3462000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4824269u); flags=s.arithmetic_flags;
  }
  L00499ccd: { // 0x499ccd: 3a8621010000 CMP AL,byte ptr [ESI + 0x121]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.si+0x00000121u)),8,flags);
  }
  L00499cd3: { // 0x499cd3: 7412 JZ 0x00499ce7
    if(integer::condition("JZ",flags)) goto L00499ce7;
  }
  L00499cd5: { // 0x499cd5: 888621010000 MOV byte ptr [ESI + 0x121],AL
    m.w8((s.si+0x00000121u), (s.ax & 0xffu));
  }
  L00499cdb: { // 0x499cdb: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499ce1: { // 0x499ce1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499ce2: { // 0x499ce2: e829672000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4824295u); flags=s.arithmetic_flags;
  }
  L00499ce7: { // 0x499ce7: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00499ce8: { // 0x499ce8: 83ff08 CMP EDI,0x8
    (void)integer::sub(s.di,0x00000008u,32,flags);
  }
  L00499ceb: { // 0x499ceb: 7c8c JL 0x00499c79
    if(integer::condition("JL",flags)) goto L00499c79;
  }
  L00499ced: { // 0x499ced: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L00499cf1: { // 0x499cf1: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L00499cf5: { // 0x499cf5: eb45 JMP 0x00499d3c
    goto L00499d3c;
  }
  L00499cf7: { // 0x499cf7: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L00499cfa: { // 0x499cfa: 741f JZ 0x00499d1b
    if(integer::condition("JZ",flags)) goto L00499d1b;
  }
  L00499cfc: { // 0x499cfc: f6874001000002 TEST byte ptr [EDI + 0x140],0x2
    (void)integer::logical((m.r8((s.di+0x00000140u)))&(0x00000002u),8,flags);
  }
  L00499d03: { // 0x499d03: 7516 JNZ 0x00499d1b
    if(integer::condition("JNZ",flags)) goto L00499d1b;
  }
  L00499d05: { // 0x499d05: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00499d09: { // 0x499d09: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00499d0b: { // 0x499d0b: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00499d0f: { // 0x499d0f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499d10: { // 0x499d10: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00499d11: { // 0x499d11: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00499d13: { // 0x499d13: ff9090000000 CALL dword ptr [EAX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000090u)),4824345u); flags=s.arithmetic_flags;
  }
  L00499d19: { // 0x499d19: eb21 JMP 0x00499d3c
    goto L00499d3c;
  }
  L00499d1b: { // 0x499d1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00499d1d: { // 0x499d1d: 7c1d JL 0x00499d3c
    if(integer::condition("JL",flags)) goto L00499d3c;
  }
  L00499d1f: { // 0x499d1f: 0fbe8f21010000 MOVSX ECX,byte ptr [EDI + 0x121]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x00000121u)),8));
  }
  L00499d26: { // 0x499d26: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00499d28: { // 0x499d28: 7412 JZ 0x00499d3c
    if(integer::condition("JZ",flags)) goto L00499d3c;
  }
  L00499d2a: { // 0x499d2a: 888721010000 MOV byte ptr [EDI + 0x121],AL
    m.w8((s.di+0x00000121u), (s.ax & 0xffu));
  }
  L00499d30: { // 0x499d30: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499d36: { // 0x499d36: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499d37: { // 0x499d37: e8d4662000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4824380u); flags=s.arithmetic_flags;
  }
  L00499d3c: { // 0x499d3c: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00499d40: { // 0x499d40: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00499d41: { // 0x499d41: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00499d44: { // 0x499d44: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00499d48: { // 0x499d48: 0f8c33fdffff JL 0x00499a81
    if(integer::condition("JL",flags)) goto L00499a81;
  }
  L00499d4e: { // 0x499d4e: 8a5c2412 MOV BL,byte ptr [ESP + 0x12]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000012u)));
  }
  L00499d52: { // 0x499d52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00499d53: { // 0x499d53: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00499d55: { // 0x499d55: 7415 JZ 0x00499d6c
    if(integer::condition("JZ",flags)) goto L00499d6c;
  }
  L00499d57: { // 0x499d57: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L00499d5b: { // 0x499d5b: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00499d5f: { // 0x499d5f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00499d60: { // 0x499d60: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00499d61: { // 0x499d61: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00499d62: { // 0x499d62: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00499d67: { // 0x499d67: e8a4b50c00 CALL 0x00565310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00565310u,4824428u); flags=s.arithmetic_flags;
  }
  L00499d6c: { // 0x499d6c: f6854001000002 TEST byte ptr [EBP + 0x140],0x2
    (void)integer::logical((m.r8((s.bp+0x00000140u)))&(0x00000002u),8,flags);
  }
  L00499d73: { // 0x499d73: 741c JZ 0x00499d91
    if(integer::condition("JZ",flags)) goto L00499d91;
  }
  L00499d75: { // 0x499d75: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L00499d79: { // 0x499d79: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499d7b: { // 0x499d7b: 7414 JZ 0x00499d91
    if(integer::condition("JZ",flags)) goto L00499d91;
  }
  L00499d7d: { // 0x499d7d: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00499d83: { // 0x499d83: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00499d85: { // 0x499d85: f6c410 TEST AH,0x10
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  L00499d88: { // 0x499d88: 7407 JZ 0x00499d91
    if(integer::condition("JZ",flags)) goto L00499d91;
  }
  L00499d8a: { // 0x499d8a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00499d8c: { // 0x499d8c: e86f1cfeff CALL 0x0047ba00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047ba00u,4824465u); flags=s.arithmetic_flags;
  }
  L00499d91: { // 0x499d91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00499d92: { // 0x499d92: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L00499d94: { // 0x499d94: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00499d95: { // 0x499d95: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00499d96: { // 0x499d96: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L00499d99: { // 0x499d99: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00499ed0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00499ed0: { // 0x499ed0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00499ed3: { // 0x499ed3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00499ed4: { // 0x499ed4: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L00499ed8: { // 0x499ed8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00499ed9: { // 0x499ed9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499eda: { // 0x499eda: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00499edc: { // 0x499edc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00499edd: { // 0x499edd: e81eb60a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4824802u); flags=s.arithmetic_flags;
  }
  L00499ee2: { // 0x499ee2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00499ee4: { // 0x499ee4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00499ee6: { // 0x499ee6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00499ee7: { // 0x499ee7: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L00499eeb: { // 0x499eeb: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L00499ef1: { // 0x499ef1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00499ef3: { // 0x499ef3: 24bf AND AL,0xbf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000bfu),8,flags));
  }
  L00499ef5: { // 0x499ef5: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L00499ef7: { // 0x499ef7: f6d1 NOT CL
    s.cx = with_al(s.cx, (~((s.cx & 0xffu))&integer::mask(8)));
  }
  L00499ef9: { // 0x499ef9: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L00499efc: { // 0x499efc: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L00499efe: { // 0x499efe: 884c2417 MOV byte ptr [ESP + 0x17],CL
    m.w8((f.sp+0x00000017u), (s.cx & 0xffu));
  }
  L00499f02: { // 0x499f02: 884c2438 MOV byte ptr [ESP + 0x38],CL
    m.w8((f.sp+0x00000038u), (s.cx & 0xffu));
  }
  L00499f06: { // 0x499f06: 884c2430 MOV byte ptr [ESP + 0x30],CL
    m.w8((f.sp+0x00000030u), (s.cx & 0xffu));
  }
  L00499f0a: { // 0x499f0a: 898740010000 MOV dword ptr [EDI + 0x140],EAX
    m.w32((s.di+0x00000140u), s.ax);
  }
  L00499f10: { // 0x499f10: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499f16: { // 0x499f16: e865442000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4824859u); flags=s.arithmetic_flags;
  }
  L00499f1b: { // 0x499f1b: 3a8721010000 CMP AL,byte ptr [EDI + 0x121]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.di+0x00000121u)),8,flags);
  }
  L00499f21: { // 0x499f21: 740b JZ 0x00499f2e
    if(integer::condition("JZ",flags)) goto L00499f2e;
  }
  L00499f23: { // 0x499f23: c644243001 MOV byte ptr [ESP + 0x30],0x1
    m.w8((f.sp+0x00000030u), 0x00000001u);
  }
  L00499f28: { // 0x499f28: 888721010000 MOV byte ptr [EDI + 0x121],AL
    m.w8((s.di+0x00000121u), (s.ax & 0xffu));
  }
  L00499f2e: { // 0x499f2e: 80bf21010000ff CMP byte ptr [EDI + 0x121],0xff
    (void)integer::sub(m.r8((s.di+0x00000121u)),0x000000ffu,8,flags);
  }
  L00499f35: { // 0x499f35: 750e JNZ 0x00499f45
    if(integer::condition("JNZ",flags)) goto L00499f45;
  }
  L00499f37: { // 0x499f37: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L00499f3d: { // 0x499f3d: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00499f3f: { // 0x499f3f: 898740010000 MOV dword ptr [EDI + 0x140],EAX
    m.w32((s.di+0x00000140u), s.ax);
  }
  L00499f45: { // 0x499f45: 8a442430 MOV AL,byte ptr [ESP + 0x30]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000030u)));
  }
  L00499f49: { // 0x499f49: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00499f4b: { // 0x499f4b: 740c JZ 0x00499f59
    if(integer::condition("JZ",flags)) goto L00499f59;
  }
  L00499f4d: { // 0x499f4d: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499f53: { // 0x499f53: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00499f54: { // 0x499f54: e8b7642000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4824921u); flags=s.arithmetic_flags;
  }
  L00499f59: { // 0x499f59: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00499f5a: { // 0x499f5a: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00499f62: { // 0x499f62: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00499f66: { // 0x499f66: 668b0b MOV CX,word ptr [EBX]
    s.cx = with_ax(s.cx, m.r16((s.bx)));
  }
  L00499f69: { // 0x499f69: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L00499f6c: { // 0x499f6c: 66030c85a09d8300 ADD CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.ax * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L00499f74: { // 0x499f74: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L00499f7c: { // 0x499f7c: 66035302 ADD DX,word ptr [EBX + 0x2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.bx+0x00000002u)),16,flags));
  }
  L00499f80: { // 0x499f80: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L00499f87: { // 0x499f87: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00499f8c: { // 0x499f8c: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499f90: { // 0x499f90: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L00499f95: { // 0x499f95: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00499f99: { // 0x499f99: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499f9a: { // 0x499f9a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00499f9c: { // 0x499f9c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00499fa0: { // 0x499fa0: e85bb50a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4824997u); flags=s.arithmetic_flags;
  }
  L00499fa5: { // 0x499fa5: 668b542414 MOV DX,word ptr [ESP + 0x14]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000014u)));
  }
  L00499faa: { // 0x499faa: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00499fac: { // 0x499fac: 663b13 CMP DX,word ptr [EBX]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.bx)),16,flags);
  }
  L00499faf: { // 0x499faf: 750f JNZ 0x00499fc0
    if(integer::condition("JNZ",flags)) goto L00499fc0;
  }
  L00499fb1: { // 0x499fb1: 668b442416 MOV AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000016u)));
  }
  L00499fb6: { // 0x499fb6: 663b4302 CMP AX,word ptr [EBX + 0x2]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.bx+0x00000002u)),16,flags);
  }
  L00499fba: { // 0x499fba: 0f8426010000 JZ 0x0049a0e6
    if(integer::condition("JZ",flags)) goto L0049a0e6;
  }
  L00499fc0: { // 0x499fc0: f6864001000001 TEST byte ptr [ESI + 0x140],0x1
    (void)integer::logical((m.r8((s.si+0x00000140u)))&(0x00000001u),8,flags);
  }
  L00499fc7: { // 0x499fc7: 0f8519010000 JNZ 0x0049a0e6
    if(integer::condition("JNZ",flags)) goto L0049a0e6;
  }
  L00499fcd: { // 0x499fcd: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499fd1: { // 0x499fd1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00499fd3: { // 0x499fd3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499fd4: { // 0x499fd4: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00499fda: { // 0x499fda: e8a1432000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4825055u); flags=s.arithmetic_flags;
  }
  L00499fdf: { // 0x499fdf: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00499fe2: { // 0x499fe2: 0f85b8000000 JNZ 0x0049a0a0
    if(integer::condition("JNZ",flags)) goto L0049a0a0;
  }
  L00499fe8: { // 0x499fe8: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L00499fee: { // 0x499fee: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L00499ff0: { // 0x499ff0: 751a JNZ 0x0049a00c
    if(integer::condition("JNZ",flags)) goto L0049a00c;
  }
  L00499ff2: { // 0x499ff2: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L00499ff6: { // 0x499ff6: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00499ff9: { // 0x499ff9: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00499ffd: { // 0x499ffd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00499ffe: { // 0x499ffe: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00499fff: { // 0x499fff: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049a001: { // 0x49a001: ff9298000000 CALL dword ptr [EDX + 0x98]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000098u)),4825095u); flags=s.arithmetic_flags;
  }
  L0049a007: { // 0x49a007: e9da000000 JMP 0x0049a0e6
    goto L0049a0e6;
  }
  L0049a00c: { // 0x49a00c: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L0049a00e: { // 0x49a00e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a00f: { // 0x49a00f: 898640010000 MOV dword ptr [ESI + 0x140],EAX
    m.w32((s.si+0x00000140u), s.ax);
  }
  L0049a015: { // 0x49a015: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a01b: { // 0x49a01b: e8f0632000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4825120u); flags=s.arithmetic_flags;
  }
  L0049a020: { // 0x49a020: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049a022: { // 0x49a022: 668b4c2414 MOV CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000014u)));
  }
  L0049a027: { // 0x49a027: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0049a029: { // 0x49a029: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0049a02c: { // 0x49a02c: 66030c95a09d8300 ADD CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.dx * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L0049a034: { // 0x49a034: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L0049a03b: { // 0x49a03b: 668b1495a29d8300 MOV DX,word ptr [EDX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da2u)));
  }
  L0049a043: { // 0x49a043: 66894c2420 MOV word ptr [ESP + 0x20],CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L0049a048: { // 0x49a048: 6603542416 ADD DX,word ptr [ESP + 0x16]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L0049a04d: { // 0x49a04d: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0049a051: { // 0x49a051: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a052: { // 0x49a052: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049a054: { // 0x49a054: 6689542426 MOV word ptr [ESP + 0x26],DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L0049a059: { // 0x49a059: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0049a05d: { // 0x49a05d: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0049a061: { // 0x49a061: e89ab40a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4825190u); flags=s.arithmetic_flags;
  }
  L0049a066: { // 0x49a066: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a06c: { // 0x49a06c: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0049a070: { // 0x49a070: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049a072: { // 0x49a072: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a073: { // 0x49a073: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049a075: { // 0x49a075: e806432000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4825210u); flags=s.arithmetic_flags;
  }
  L0049a07a: { // 0x49a07a: 3a8621010000 CMP AL,byte ptr [ESI + 0x121]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.si+0x00000121u)),8,flags);
  }
  L0049a080: { // 0x49a080: 7412 JZ 0x0049a094
    if(integer::condition("JZ",flags)) goto L0049a094;
  }
  L0049a082: { // 0x49a082: 888621010000 MOV byte ptr [ESI + 0x121],AL
    m.w8((s.si+0x00000121u), (s.ax & 0xffu));
  }
  L0049a088: { // 0x49a088: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a08e: { // 0x49a08e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a08f: { // 0x49a08f: e87c632000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4825236u); flags=s.arithmetic_flags;
  }
  L0049a094: { // 0x49a094: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0049a095: { // 0x49a095: 83ff08 CMP EDI,0x8
    (void)integer::sub(s.di,0x00000008u,32,flags);
  }
  L0049a098: { // 0x49a098: 7c88 JL 0x0049a022
    if(integer::condition("JL",flags)) goto L0049a022;
  }
  L0049a09a: { // 0x49a09a: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0049a09e: { // 0x49a09e: eb46 JMP 0x0049a0e6
    goto L0049a0e6;
  }
  L0049a0a0: { // 0x49a0a0: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L0049a0a3: { // 0x49a0a3: 7420 JZ 0x0049a0c5
    if(integer::condition("JZ",flags)) goto L0049a0c5;
  }
  L0049a0a5: { // 0x49a0a5: f6864001000002 TEST byte ptr [ESI + 0x140],0x2
    (void)integer::logical((m.r8((s.si+0x00000140u)))&(0x00000002u),8,flags);
  }
  L0049a0ac: { // 0x49a0ac: 7517 JNZ 0x0049a0c5
    if(integer::condition("JNZ",flags)) goto L0049a0c5;
  }
  L0049a0ae: { // 0x49a0ae: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0049a0b2: { // 0x49a0b2: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0049a0b5: { // 0x49a0b5: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0049a0b9: { // 0x49a0b9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a0ba: { // 0x49a0ba: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a0bb: { // 0x49a0bb: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049a0bd: { // 0x49a0bd: ff9098000000 CALL dword ptr [EAX + 0x98]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000098u)),4825283u); flags=s.arithmetic_flags;
  }
  L0049a0c3: { // 0x49a0c3: eb21 JMP 0x0049a0e6
    goto L0049a0e6;
  }
  L0049a0c5: { // 0x49a0c5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049a0c7: { // 0x49a0c7: 7c1d JL 0x0049a0e6
    if(integer::condition("JL",flags)) goto L0049a0e6;
  }
  L0049a0c9: { // 0x49a0c9: 0fbe8e21010000 MOVSX ECX,byte ptr [ESI + 0x121]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x00000121u)),8));
  }
  L0049a0d0: { // 0x49a0d0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049a0d2: { // 0x49a0d2: 7412 JZ 0x0049a0e6
    if(integer::condition("JZ",flags)) goto L0049a0e6;
  }
  L0049a0d4: { // 0x49a0d4: 888621010000 MOV byte ptr [ESI + 0x121],AL
    m.w8((s.si+0x00000121u), (s.ax & 0xffu));
  }
  L0049a0da: { // 0x49a0da: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a0e0: { // 0x49a0e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a0e1: { // 0x49a0e1: e82a632000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4825318u); flags=s.arithmetic_flags;
  }
  L0049a0e6: { // 0x49a0e6: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0049a0ea: { // 0x49a0ea: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0049a0eb: { // 0x49a0eb: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0049a0ee: { // 0x49a0ee: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0049a0f2: { // 0x49a0f2: 0f8c6afeffff JL 0x00499f62
    if(integer::condition("JL",flags)) goto L00499f62;
  }
  L0049a0f8: { // 0x49a0f8: 8a5c2434 MOV BL,byte ptr [ESP + 0x34]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000034u)));
  }
  L0049a0fc: { // 0x49a0fc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049a0fd: { // 0x49a0fd: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049a0ff: { // 0x49a0ff: 7415 JZ 0x0049a116
    if(integer::condition("JZ",flags)) goto L0049a116;
  }
  L0049a101: { // 0x49a101: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0049a105: { // 0x49a105: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0049a109: { // 0x49a109: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a10a: { // 0x49a10a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a10b: { // 0x49a10b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049a10c: { // 0x49a10c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049a111: { // 0x49a111: e8fab10c00 CALL 0x00565310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00565310u,4825366u); flags=s.arithmetic_flags;
  }
  L0049a116: { // 0x49a116: f6874001000002 TEST byte ptr [EDI + 0x140],0x2
    (void)integer::logical((m.r8((s.di+0x00000140u)))&(0x00000002u),8,flags);
  }
  L0049a11d: { // 0x49a11d: 741c JZ 0x0049a13b
    if(integer::condition("JZ",flags)) goto L0049a13b;
  }
  L0049a11f: { // 0x49a11f: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L0049a123: { // 0x49a123: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a125: { // 0x49a125: 7414 JZ 0x0049a13b
    if(integer::condition("JZ",flags)) goto L0049a13b;
  }
  L0049a127: { // 0x49a127: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0049a12d: { // 0x49a12d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049a12f: { // 0x49a12f: f6c410 TEST AH,0x10
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  L0049a132: { // 0x49a132: 7407 JZ 0x0049a13b
    if(integer::condition("JZ",flags)) goto L0049a13b;
  }
  L0049a134: { // 0x49a134: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0049a136: { // 0x49a136: e8c518feff CALL 0x0047ba00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047ba00u,4825403u); flags=s.arithmetic_flags;
  }
  L0049a13b: { // 0x49a13b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049a13c: { // 0x49a13c: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0049a13e: { // 0x49a13e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049a13f: { // 0x49a13f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049a140: { // 0x49a140: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0049a143: { // 0x49a143: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0049a150(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049a150: { // 0x49a150: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L0049a153: { // 0x49a153: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049a154: { // 0x49a154: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a155: { // 0x49a155: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a156: { // 0x49a156: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049a157: { // 0x49a157: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L0049a15b: { // 0x49a15b: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0049a15d: { // 0x49a15d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049a15e: { // 0x49a15e: e89db30a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4825443u); flags=s.arithmetic_flags;
  }
  L0049a163: { // 0x49a163: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049a165: { // 0x49a165: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049a167: { // 0x49a167: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049a168: { // 0x49a168: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L0049a16c: { // 0x49a16c: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L0049a172: { // 0x49a172: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0049a174: { // 0x49a174: 0c08 OR AL,0x8
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000008u),8,flags));
  }
  L0049a176: { // 0x49a176: c1eb03 SHR EBX,0x3
    s.bx = integer::shift(s.bx,0x00000003u,32,flags,integer::Shift::right);
  }
  L0049a179: { // 0x49a179: f6d3 NOT BL
    s.bx = with_al(s.bx, (~((s.bx & 0xffu))&integer::mask(8)));
  }
  L0049a17b: { // 0x49a17b: 80e301 AND BL,0x1
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags));
  }
  L0049a17e: { // 0x49a17e: 89862c010000 MOV dword ptr [ESI + 0x12c],EAX
    m.w32((s.si+0x0000012cu), s.ax);
  }
  L0049a184: { // 0x49a184: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a18a: { // 0x49a18a: 885c242c MOV byte ptr [ESP + 0x2c],BL
    m.w8((f.sp+0x0000002cu), (s.bx & 0xffu));
  }
  L0049a18e: { // 0x49a18e: e8ed412000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4825491u); flags=s.arithmetic_flags;
  }
  L0049a193: { // 0x49a193: 3a8620010000 CMP AL,byte ptr [ESI + 0x120]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.si+0x00000120u)),8,flags);
  }
  L0049a199: { // 0x49a199: 7408 JZ 0x0049a1a3
    if(integer::condition("JZ",flags)) goto L0049a1a3;
  }
  L0049a19b: { // 0x49a19b: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0049a19d: { // 0x49a19d: 888620010000 MOV byte ptr [ESI + 0x120],AL
    m.w8((s.si+0x00000120u), (s.ax & 0xffu));
  }
  L0049a1a3: { // 0x49a1a3: 80be20010000ff CMP byte ptr [ESI + 0x120],0xff
    (void)integer::sub(m.r8((s.si+0x00000120u)),0x000000ffu,8,flags);
  }
  L0049a1aa: { // 0x49a1aa: 750e JNZ 0x0049a1ba
    if(integer::condition("JNZ",flags)) goto L0049a1ba;
  }
  L0049a1ac: { // 0x49a1ac: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L0049a1b2: { // 0x49a1b2: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L0049a1b4: { // 0x49a1b4: 89862c010000 MOV dword ptr [ESI + 0x12c],EAX
    m.w32((s.si+0x0000012cu), s.ax);
  }
  L0049a1ba: { // 0x49a1ba: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049a1bc: { // 0x49a1bc: 740c JZ 0x0049a1ca
    if(integer::condition("JZ",flags)) goto L0049a1ca;
  }
  L0049a1be: { // 0x49a1be: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a1c4: { // 0x49a1c4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a1c5: { // 0x49a1c5: e846622000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4825546u); flags=s.arithmetic_flags;
  }
  L0049a1ca: { // 0x49a1ca: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L0049a1d2: { // 0x49a1d2: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0049a1d6: { // 0x49a1d6: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L0049a1d9: { // 0x49a1d9: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  L0049a1e1: { // 0x49a1e1: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L0049a1e9: { // 0x49a1e9: 66030f ADD CX,word ptr [EDI]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.di)),16,flags));
  }
  L0049a1ec: { // 0x49a1ec: 66035702 ADD DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L0049a1f0: { // 0x49a1f0: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L0049a1f7: { // 0x49a1f7: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L0049a1fc: { // 0x49a1fc: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0049a200: { // 0x49a200: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0049a205: { // 0x49a205: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0049a209: { // 0x49a209: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a20a: { // 0x49a20a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049a20c: { // 0x49a20c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0049a210: { // 0x49a210: e8ebb20a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4825621u); flags=s.arithmetic_flags;
  }
  L0049a215: { // 0x49a215: 668b542410 MOV DX,word ptr [ESP + 0x10]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000010u)));
  }
  L0049a21a: { // 0x49a21a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049a21c: { // 0x49a21c: 663b17 CMP DX,word ptr [EDI]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.di)),16,flags);
  }
  L0049a21f: { // 0x49a21f: 750f JNZ 0x0049a230
    if(integer::condition("JNZ",flags)) goto L0049a230;
  }
  L0049a221: { // 0x49a221: 668b442412 MOV AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000012u)));
  }
  L0049a226: { // 0x49a226: 663b4702 CMP AX,word ptr [EDI + 0x2]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.di+0x00000002u)),16,flags);
  }
  L0049a22a: { // 0x49a22a: 0f8422010000 JZ 0x0049a352
    if(integer::condition("JZ",flags)) goto L0049a352;
  }
  L0049a230: { // 0x49a230: f6862c01000010 TEST byte ptr [ESI + 0x12c],0x10
    (void)integer::logical((m.r8((s.si+0x0000012cu)))&(0x00000010u),8,flags);
  }
  L0049a237: { // 0x49a237: 0f8515010000 JNZ 0x0049a352
    if(integer::condition("JNZ",flags)) goto L0049a352;
  }
  L0049a23d: { // 0x49a23d: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0049a241: { // 0x49a241: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049a243: { // 0x49a243: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a244: { // 0x49a244: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a24a: { // 0x49a24a: e831412000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4825679u); flags=s.arithmetic_flags;
  }
  L0049a24f: { // 0x49a24f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0049a252: { // 0x49a252: 0f85b4000000 JNZ 0x0049a30c
    if(integer::condition("JNZ",flags)) goto L0049a30c;
  }
  L0049a258: { // 0x49a258: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L0049a25e: { // 0x49a25e: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0049a260: { // 0x49a260: 751a JNZ 0x0049a27c
    if(integer::condition("JNZ",flags)) goto L0049a27c;
  }
  L0049a262: { // 0x49a262: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0049a266: { // 0x49a266: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0049a269: { // 0x49a269: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0049a26d: { // 0x49a26d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a26e: { // 0x49a26e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a26f: { // 0x49a26f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049a271: { // 0x49a271: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4825719u); flags=s.arithmetic_flags;
  }
  L0049a277: { // 0x49a277: e9d6000000 JMP 0x0049a352
    goto L0049a352;
  }
  L0049a27c: { // 0x49a27c: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L0049a27e: { // 0x49a27e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a27f: { // 0x49a27f: 89862c010000 MOV dword ptr [ESI + 0x12c],EAX
    m.w32((s.si+0x0000012cu), s.ax);
  }
  L0049a285: { // 0x49a285: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a28b: { // 0x49a28b: e880612000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4825744u); flags=s.arithmetic_flags;
  }
  L0049a290: { // 0x49a290: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049a292: { // 0x49a292: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0049a294: { // 0x49a294: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0049a297: { // 0x49a297: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L0049a29f: { // 0x49a29f: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L0049a2a6: { // 0x49a2a6: 66034c2410 ADD CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  L0049a2ab: { // 0x49a2ab: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L0049a2af: { // 0x49a2af: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L0049a2b4: { // 0x49a2b4: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L0049a2b9: { // 0x49a2b9: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0049a2bd: { // 0x49a2bd: 668954241e MOV word ptr [ESP + 0x1e],DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  L0049a2c2: { // 0x49a2c2: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0049a2c6: { // 0x49a2c6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a2c7: { // 0x49a2c7: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049a2c9: { // 0x49a2c9: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0049a2cd: { // 0x49a2cd: e82eb20a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4825810u); flags=s.arithmetic_flags;
  }
  L0049a2d2: { // 0x49a2d2: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a2d8: { // 0x49a2d8: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0049a2dc: { // 0x49a2dc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049a2de: { // 0x49a2de: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a2df: { // 0x49a2df: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049a2e1: { // 0x49a2e1: e89a402000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4825830u); flags=s.arithmetic_flags;
  }
  L0049a2e6: { // 0x49a2e6: 3a8620010000 CMP AL,byte ptr [ESI + 0x120]
    (void)integer::sub((s.ax & 0xffu),m.r8((s.si+0x00000120u)),8,flags);
  }
  L0049a2ec: { // 0x49a2ec: 7412 JZ 0x0049a300
    if(integer::condition("JZ",flags)) goto L0049a300;
  }
  L0049a2ee: { // 0x49a2ee: 888620010000 MOV byte ptr [ESI + 0x120],AL
    m.w8((s.si+0x00000120u), (s.ax & 0xffu));
  }
  L0049a2f4: { // 0x49a2f4: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a2fa: { // 0x49a2fa: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a2fb: { // 0x49a2fb: e810612000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4825856u); flags=s.arithmetic_flags;
  }
  L0049a300: { // 0x49a300: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0049a301: { // 0x49a301: 83ff08 CMP EDI,0x8
    (void)integer::sub(s.di,0x00000008u,32,flags);
  }
  L0049a304: { // 0x49a304: 7c8c JL 0x0049a292
    if(integer::condition("JL",flags)) goto L0049a292;
  }
  L0049a306: { // 0x49a306: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L0049a30a: { // 0x49a30a: eb46 JMP 0x0049a352
    goto L0049a352;
  }
  L0049a30c: { // 0x49a30c: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L0049a30f: { // 0x49a30f: 7420 JZ 0x0049a331
    if(integer::condition("JZ",flags)) goto L0049a331;
  }
  L0049a311: { // 0x49a311: f6862c01000008 TEST byte ptr [ESI + 0x12c],0x8
    (void)integer::logical((m.r8((s.si+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L0049a318: { // 0x49a318: 7517 JNZ 0x0049a331
    if(integer::condition("JNZ",flags)) goto L0049a331;
  }
  L0049a31a: { // 0x49a31a: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0049a31e: { // 0x49a31e: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0049a321: { // 0x49a321: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0049a325: { // 0x49a325: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a326: { // 0x49a326: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a327: { // 0x49a327: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0049a329: { // 0x49a329: ff909c000000 CALL dword ptr [EAX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000009cu)),4825903u); flags=s.arithmetic_flags;
  }
  L0049a32f: { // 0x49a32f: eb21 JMP 0x0049a352
    goto L0049a352;
  }
  L0049a331: { // 0x49a331: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049a333: { // 0x49a333: 7c1d JL 0x0049a352
    if(integer::condition("JL",flags)) goto L0049a352;
  }
  L0049a335: { // 0x49a335: 0fbe8e20010000 MOVSX ECX,byte ptr [ESI + 0x120]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x00000120u)),8));
  }
  L0049a33c: { // 0x49a33c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0049a33e: { // 0x49a33e: 7412 JZ 0x0049a352
    if(integer::condition("JZ",flags)) goto L0049a352;
  }
  L0049a340: { // 0x49a340: 888620010000 MOV byte ptr [ESI + 0x120],AL
    m.w8((s.si+0x00000120u), (s.ax & 0xffu));
  }
  L0049a346: { // 0x49a346: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049a34c: { // 0x49a34c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a34d: { // 0x49a34d: e8be602000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4825938u); flags=s.arithmetic_flags;
  }
  L0049a352: { // 0x49a352: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0049a356: { // 0x49a356: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0049a357: { // 0x49a357: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0049a35a: { // 0x49a35a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0049a35e: { // 0x49a35e: 0f8c6efeffff JL 0x0049a1d2
    if(integer::condition("JL",flags)) goto L0049a1d2;
  }
  L0049a364: { // 0x49a364: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049a366: { // 0x49a366: 7419 JZ 0x0049a381
    if(integer::condition("JZ",flags)) goto L0049a381;
  }
  L0049a368: { // 0x49a368: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0049a36c: { // 0x49a36c: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0049a370: { // 0x49a370: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0049a374: { // 0x49a374: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049a375: { // 0x49a375: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049a376: { // 0x49a376: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a377: { // 0x49a377: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049a37c: { // 0x49a37c: e88faf0c00 CALL 0x00565310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00565310u,4825985u); flags=s.arithmetic_flags;
  }
  L0049a381: { // 0x49a381: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049a382: { // 0x49a382: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049a383: { // 0x49a383: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0049a385: { // 0x49a385: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049a386: { // 0x49a386: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049a387: { // 0x49a387: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L0049a38a: { // 0x49a38a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0049cb50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049cb50: { // 0x49cb50: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0049cb53: { // 0x49cb53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049cb54: { // 0x49cb54: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049cb55: { // 0x49cb55: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0049cb59: { // 0x49cb59: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0049cb5b: { // 0x49cb5b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049cb5c: { // 0x49cb5c: e8dfb30a00 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,4836193u); flags=s.arithmetic_flags;
  }
  L0049cb61: { // 0x49cb61: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049cb63: { // 0x49cb63: 0f8420010000 JZ 0x0049cc89
    if(integer::condition("JZ",flags)) goto L0049cc89;
  }
  L0049cb69: { // 0x49cb69: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049cb6a: { // 0x49cb6a: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0049cb6c: { // 0x49cb6c: e88f890a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4836209u); flags=s.arithmetic_flags;
  }
  L0049cb71: { // 0x49cb71: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049cb73: { // 0x49cb73: c644241c00 MOV byte ptr [ESP + 0x1c],0x0
    m.w8((f.sp+0x0000001cu), 0x00000000u);
  }
  L0049cb78: { // 0x49cb78: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0049cb7c: { // 0x49cb7c: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L0049cb82: { // 0x49cb82: a803 TEST AL,0x3
    (void)integer::logical(((s.ax & 0xffu))&(0x00000003u),8,flags);
  }
  L0049cb84: { // 0x49cb84: 7405 JZ 0x0049cb8b
    if(integer::condition("JZ",flags)) goto L0049cb8b;
  }
  L0049cb86: { // 0x49cb86: c644241c01 MOV byte ptr [ESP + 0x1c],0x1
    m.w8((f.sp+0x0000001cu), 0x00000001u);
  }
  L0049cb8b: { // 0x49cb8b: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
  L0049cb8d: { // 0x49cb8d: c68121010000fe MOV byte ptr [ECX + 0x121],0xfe
    m.w8((s.cx+0x00000121u), 0x000000feu);
  }
  L0049cb94: { // 0x49cb94: 898140010000 MOV dword ptr [ECX + 0x140],EAX
    m.w32((s.cx+0x00000140u), s.ax);
  }
  L0049cb9a: { // 0x49cb9a: 8a812c010000 MOV AL,byte ptr [ECX + 0x12c]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000012cu)));
  }
  L0049cba0: { // 0x49cba0: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0049cba2: { // 0x49cba2: 740c JZ 0x0049cbb0
    if(integer::condition("JZ",flags)) goto L0049cbb0;
  }
  L0049cba4: { // 0x49cba4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049cba5: { // 0x49cba5: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049cbab: { // 0x49cbab: e860382000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4836272u); flags=s.arithmetic_flags;
  }
  L0049cbb0: { // 0x49cbb0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049cbb1: { // 0x49cbb1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049cbb2: { // 0x49cbb2: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049cbb4: { // 0x49cbb4: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L0049cbb7: { // 0x49cbb7: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0049cbb9: { // 0x49cbb9: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L0049cbbc: { // 0x49cbbc: 66030c85a09d8300 ADD CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.ax * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L0049cbc4: { // 0x49cbc4: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  L0049cbcc: { // 0x49cbcc: 66035702 ADD DX,word ptr [EDI + 0x2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.di+0x00000002u)),16,flags));
  }
  L0049cbd0: { // 0x49cbd0: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L0049cbd7: { // 0x49cbd7: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0049cbdc: { // 0x49cbdc: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0049cbe0: { // 0x49cbe0: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0049cbe5: { // 0x49cbe5: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0049cbe9: { // 0x49cbe9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049cbea: { // 0x49cbea: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0049cbec: { // 0x49cbec: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0049cbf0: { // 0x49cbf0: e80b890a00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4836341u); flags=s.arithmetic_flags;
  }
  L0049cbf5: { // 0x49cbf5: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049cbfb: { // 0x49cbfb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049cbfd: { // 0x49cbfd: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0049cc01: { // 0x49cc01: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049cc03: { // 0x49cc03: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L0049cc06: { // 0x49cc06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049cc07: { // 0x49cc07: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0049cc0b: { // 0x49cc0b: e870172000 CALL 0x0069e380
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e380u,4836368u); flags=s.arithmetic_flags;
  }
  L0049cc10: { // 0x49cc10: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L0049cc13: { // 0x49cc13: 7516 JNZ 0x0049cc2b
    if(integer::condition("JNZ",flags)) goto L0049cc2b;
  }
  L0049cc15: { // 0x49cc15: 388621010000 CMP byte ptr [ESI + 0x121],AL
    (void)integer::sub(m.r8((s.si+0x00000121u)),(s.ax & 0xffu),8,flags);
  }
  L0049cc1b: { // 0x49cc1b: 740e JZ 0x0049cc2b
    if(integer::condition("JZ",flags)) goto L0049cc2b;
  }
  L0049cc1d: { // 0x49cc1d: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0049cc21: { // 0x49cc21: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049cc22: { // 0x49cc22: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0049cc24: { // 0x49cc24: e827ffffff CALL 0x0049cb50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049cb50u,4836393u); flags=s.arithmetic_flags;
  }
  L0049cc29: { // 0x49cc29: eb41 JMP 0x0049cc6c
    goto L0049cc6c;
  }
  L0049cc2b: { // 0x49cc2b: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  L0049cc31: { // 0x49cc31: f6c101 TEST CL,0x1
    (void)integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags);
  }
  L0049cc34: { // 0x49cc34: 750b JNZ 0x0049cc41
    if(integer::condition("JNZ",flags)) goto L0049cc41;
  }
  L0049cc36: { // 0x49cc36: 0fbe9621010000 MOVSX EDX,byte ptr [ESI + 0x121]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x00000121u)),8));
  }
  L0049cc3d: { // 0x49cc3d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049cc3f: { // 0x49cc3f: 742b JZ 0x0049cc6c
    if(integer::condition("JZ",flags)) goto L0049cc6c;
  }
  L0049cc41: { // 0x49cc41: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049cc43: { // 0x49cc43: 7c27 JL 0x0049cc6c
    if(integer::condition("JL",flags)) goto L0049cc6c;
  }
  L0049cc45: { // 0x49cc45: 80be21010000ff CMP byte ptr [ESI + 0x121],0xff
    (void)integer::sub(m.r8((s.si+0x00000121u)),0x000000ffu,8,flags);
  }
  L0049cc4c: { // 0x49cc4c: 7c1e JL 0x0049cc6c
    if(integer::condition("JL",flags)) goto L0049cc6c;
  }
  L0049cc4e: { // 0x49cc4e: 83e1fe AND ECX,0xfffffffe
    s.cx = integer::logical((s.cx)&(0xfffffffeu),32,flags);
  }
  L0049cc51: { // 0x49cc51: 888621010000 MOV byte ptr [ESI + 0x121],AL
    m.w8((s.si+0x00000121u), (s.ax & 0xffu));
  }
  L0049cc57: { // 0x49cc57: 83c902 OR ECX,0x2
    s.cx = integer::logical((s.cx)|(0x00000002u),32,flags);
  }
  L0049cc5a: { // 0x49cc5a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049cc5b: { // 0x49cc5b: 898e40010000 MOV dword ptr [ESI + 0x140],ECX
    m.w32((s.si+0x00000140u), s.cx);
  }
  L0049cc61: { // 0x49cc61: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049cc67: { // 0x49cc67: e8a4372000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4836460u); flags=s.arithmetic_flags;
  }
  L0049cc6c: { // 0x49cc6c: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0049cc6d: { // 0x49cc6d: 83fd08 CMP EBP,0x8
    (void)integer::sub(s.bp,0x00000008u,32,flags);
  }
  L0049cc70: { // 0x49cc70: 0f8c3effffff JL 0x0049cbb4
    if(integer::condition("JL",flags)) goto L0049cbb4;
  }
  L0049cc76: { // 0x49cc76: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L0049cc7a: { // 0x49cc7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049cc7b: { // 0x49cc7b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049cc7d: { // 0x49cc7d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049cc7e: { // 0x49cc7e: 7409 JZ 0x0049cc89
    if(integer::condition("JZ",flags)) goto L0049cc89;
  }
  L0049cc80: { // 0x49cc80: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0049cc84: { // 0x49cc84: e8f7ebfdff CALL 0x0047b880
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b880u,4836489u); flags=s.arithmetic_flags;
  }
  L0049cc89: { // 0x49cc89: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049cc8a: { // 0x49cc8a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049cc8b: { // 0x49cc8b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0049cc8e: { // 0x49cc8e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
