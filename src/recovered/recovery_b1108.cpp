#include "recovered/recovery_b1108_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1108 {
namespace {
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_001862e0(Memory&,State&,Frame&,const Operations&);
void f_00127630(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX], 0
    (void)integer::sub(m.r8((s.cx)),0u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x62fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX, dword ptr [ECX + 8]
    s.dx = m.r32((s.cx+8u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX, dword ptr [ECX + EDX*4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 4u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI, dword ptr [ECX + EAX*4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 4u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX, [ECX + EAX*4 + 0xc]
    s.ax = (s.cx+(s.ax * 4u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI, EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX], ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI, dword ptr [ECX + 8]
    s.si = m.r32((s.cx+8u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX, dword ptr [ECX + EDX*4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 4u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX, 0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 8], ESI
    m.w32((s.cx+8u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x62fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 4], 0
    m.w32((s.cx+4u), 0u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI, 0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x62fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 8], 0
    m.w32((s.cx+8u), 0u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
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
void f_001862e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005862e0: { // 0x5862e0: 83ec14 SUB ESP, 0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005862e3: { // 0x5862e3: a11489a200 MOV EAX, dword ptr [0xa28914]
    s.ax = m.r32((0x00a28914u));
  }
  L005862e8: { // 0x5862e8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005862e9: { // 0x5862e9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005862ea: { // 0x5862ea: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005862eb: { // 0x5862eb: 8b3488 MOV ESI, dword ptr [EAX + ECX*4]
    s.si = m.r32((s.ax+(s.cx * 4u)));
  }
  L005862ee: { // 0x5862ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005862ef: { // 0x5862ef: 8bfa MOV EDI, EDX
    s.di = s.dx;
  }
  L005862f1: { // 0x5862f1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005862f3: { // 0x5862f3: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005862f5: { // 0x5862f5: 897c241c MOV dword ptr [ESP + 0x1c], EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L005862f9: { // 0x5862f9: 89742410 MOV dword ptr [ESP + 0x10], ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L005862fd: { // 0x5862fd: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5792515u); flags=s.arithmetic_flags;
  }
  L00586303: { // 0x586303: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00586305: { // 0x586305: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00586309: { // 0x586309: 0f844e010000 JZ 0x58645d
    if(integer::condition("JZ",flags)) goto L0058645d;
  }
  L0058630f: { // 0x58630f: 8b86b8020000 MOV EAX, dword ptr [ESI + 0x2b8]
    s.ax = m.r32((s.si+0x000002b8u));
  }
  L00586315: { // 0x586315: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00586317: { // 0x586317: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00586319: { // 0x586319: 0f8e3e010000 JLE 0x58645d
    if(integer::condition("JLE",flags)) goto L0058645d;
  }
  L0058631f: { // 0x58631f: 8b353486a500 MOV ESI, dword ptr [0xa58634]
    s.si = m.r32((0x00a58634u));
  }
  L00586325: { // 0x586325: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00586329: { // 0x586329: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0058632b: { // 0x58632b: 8b88b4020000 MOV ECX, dword ptr [EAX + 0x2b4]
    s.cx = m.r32((s.ax+0x000002b4u));
  }
  L00586331: { // 0x586331: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00586333: { // 0x586333: 0f8ef1000000 JLE 0x58642a
    if(integer::condition("JLE",flags)) goto L0058642a;
  }
  L00586339: { // 0x586339: 668b07 MOV AX, word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L0058633c: { // 0x58633c: 668bcb MOV CX, BX
    s.cx = with_ax(s.cx, (s.bx & 0xffffu));
  }
  L0058633f: { // 0x58633f: 66034f02 ADD CX, word ptr [EDI + 2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.di+2u)),16,flags));
  }
  L00586343: { // 0x586343: 6603c5 ADD AX, BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L00586346: { // 0x586346: 6689442418 MOV word ptr [ESP + 0x18], AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0058634b: { // 0x58634b: 66894c241a MOV word ptr [ESP + 0x1a], CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L00586350: { // 0x586350: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00586354: { // 0x586354: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00586358: { // 0x586358: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058635b: { // 0x58635b: 0fbfc1 MOVSX EAX, CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058635e: { // 0x58635e: 8d0c10 LEA ECX, [EAX + EDX]
    s.cx = (s.ax+s.dx);
  }
  L00586361: { // 0x586361: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00586363: { // 0x586363: 0f8ede000000 JLE 0x586447
    if(integer::condition("JLE",flags)) goto L00586447;
  }
  L00586369: { // 0x586369: 8bfa MOV EDI, EDX
    s.di = s.dx;
  }
  L0058636b: { // 0x58636b: 2bf8 SUB EDI, EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0058636d: { // 0x58636d: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0058636f: { // 0x58636f: 0f8dd2000000 JGE 0x586447
    if(integer::condition("JGE",flags)) goto L00586447;
  }
  L00586375: { // 0x586375: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00586377: { // 0x586377: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00586379: { // 0x586379: 0f8dc8000000 JGE 0x586447
    if(integer::condition("JGE",flags)) goto L00586447;
  }
  L0058637f: { // 0x58637f: 3b0d3886a500 CMP ECX, dword ptr [0xa58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00586385: { // 0x586385: 0f8fbc000000 JG 0x586447
    if(integer::condition("JG",flags)) goto L00586447;
  }
  L0058638b: { // 0x58638b: 8d442414 LEA EAX, [ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0058638f: { // 0x58638f: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L00586394: { // 0x586394: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00586395: { // 0x586395: e866f1fbff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5792666u); flags=s.arithmetic_flags;
  }
  L0058639a: { // 0x58639a: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0058639c: { // 0x58639c: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005863a0: { // 0x5863a0: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L005863a4: { // 0x5863a4: 8b91b4020000 MOV EDX, dword ptr [ECX + 0x2b4]
    s.dx = m.r32((s.cx+0x000002b4u));
  }
  L005863aa: { // 0x5863aa: 0fafd3 IMUL EDX, EBX
    s.dx = integer::imul(s.dx,s.bx,32,flags);
  }
  L005863ad: { // 0x5863ad: 03d5 ADD EDX, EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L005863af: { // 0x5863af: 8b749010 MOV ESI, dword ptr [EAX + EDX*4 + 0x10]
    s.si = m.r32((s.ax+(s.dx * 4u)+0x00000010u));
  }
  L005863b3: { // 0x5863b3: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005863b5: { // 0x5863b5: 7458 JZ 0x58640f
    if(integer::condition("JZ",flags)) goto L0058640f;
  }
  L005863b7: { // 0x5863b7: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005863b9: { // 0x5863b9: e8d24defff CALL 0x47b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5792702u); flags=s.arithmetic_flags;
  }
  L005863be: { // 0x5863be: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005863c0: { // 0x5863c0: 750f JNZ 0x5863d1
    if(integer::condition("JNZ",flags)) goto L005863d1;
  }
  L005863c2: { // 0x5863c2: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005863c4: { // 0x5863c4: e8e74defff CALL 0x47b1b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b1b0u,5792713u); flags=s.arithmetic_flags;
  }
  L005863c9: { // 0x5863c9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005863cb: { // 0x5863cb: 0f8480000000 JZ 0x586451
    if(integer::condition("JZ",flags)) goto L00586451;
  }
  L005863d1: { // 0x5863d1: 0fbe562a MOVSX EDX, byte ptr [ESI + 0x2a]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000002au)),8));
  }
  L005863d5: { // 0x5863d5: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005863d7: { // 0x5863d7: 8a8f1c010000 MOV CL, byte ptr [EDI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000011cu)));
  }
  L005863dd: { // 0x5863dd: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005863df: { // 0x5863df: 7570 JNZ 0x586451
    if(integer::condition("JNZ",flags)) goto L00586451;
  }
  L005863e1: { // 0x5863e1: 8a442428 MOV AL, byte ptr [ESP + 0x28]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000028u)));
  }
  L005863e5: { // 0x5863e5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005863e7: { // 0x5863e7: 7426 JZ 0x58640f
    if(integer::condition("JZ",flags)) goto L0058640f;
  }
  L005863e9: { // 0x5863e9: 0fbf442416 MOVSX EAX, word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L005863ee: { // 0x5863ee: 0faf054c6b8300 IMUL EAX, dword ptr [0x836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L005863f5: { // 0x5863f5: 0fbf4c2414 MOVSX ECX, word ptr [ESP + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L005863fa: { // 0x5863fa: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005863fc: { // 0x5863fc: 8d1480 LEA EDX, [EAX + EAX*4]
    s.dx = (s.ax+(s.ax * 4u));
  }
  L005863ff: { // 0x5863ff: a13c86a500 MOV EAX, dword ptr [0xa5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L00586404: { // 0x586404: c1e204 SHL EDX, 4
    s.dx = integer::shift(s.dx,4u,32,flags,integer::Shift::left);
  }
  L00586407: { // 0x586407: 8a4c0246 MOV CL, byte ptr [EDX + EAX + 0x46]
    s.cx = with_al(s.cx, m.r8((s.dx+s.ax+0x00000046u)));
  }
  L0058640b: { // 0x58640b: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0058640d: { // 0x58640d: 7542 JNZ 0x586451
    if(integer::condition("JNZ",flags)) goto L00586451;
  }
  L0058640f: { // 0x58640f: 8b353486a500 MOV ESI, dword ptr [0xa58634]
    s.si = m.r32((0x00a58634u));
  }
  L00586415: { // 0x586415: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00586419: { // 0x586419: 8b7c241c MOV EDI, dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0058641d: { // 0x58641d: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0058641e: { // 0x58641e: 3ba9b4020000 CMP EBP, dword ptr [ECX + 0x2b4]
    (void)integer::sub(s.bp,m.r32((s.cx+0x000002b4u)),32,flags);
  }
  L00586424: { // 0x586424: 0f8c0fffffff JL 0x586339
    if(integer::condition("JL",flags)) goto L00586339;
  }
  L0058642a: { // 0x58642a: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0058642e: { // 0x58642e: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0058642f: { // 0x58642f: 3b9ab8020000 CMP EBX, dword ptr [EDX + 0x2b8]
    (void)integer::sub(s.bx,m.r32((s.dx+0x000002b8u)),32,flags);
  }
  L00586435: { // 0x586435: 0f8ceafeffff JL 0x586325
    if(integer::condition("JL",flags)) goto L00586325;
  }
  L0058643b: { // 0x58643b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058643c: { // 0x58643c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058643d: { // 0x58643d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058643e: { // 0x58643e: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00586440: { // 0x586440: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00586441: { // 0x586441: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00586444: { // 0x586444: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00586447: { // 0x586447: 8a44242c MOV AL, byte ptr [ESP + 0x2c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000002cu)));
  }
  L0058644b: { // 0x58644b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058644d: { // 0x58644d: 7502 JNZ 0x586451
    if(integer::condition("JNZ",flags)) goto L00586451;
  }
  L0058644f: { // 0x58644f: ebc4 JMP 0x586415
    goto L00586415;
  }
  L00586451: { // 0x586451: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00586452: { // 0x586452: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00586453: { // 0x586453: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00586454: { // 0x586454: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00586456: { // 0x586456: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00586457: { // 0x586457: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0058645a: { // 0x58645a: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0058645d: { // 0x58645d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058645e: { // 0x58645e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058645f: { // 0x58645f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00586460: { // 0x586460: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00586462: { // 0x586462: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00586463: { // 0x586463: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00586466: { // 0x586466: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00127630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00527630: { // 0x527630: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00527631: { // 0x527631: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00527633: { // 0x527633: 8b86a4000000 MOV EAX, dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00527639: { // 0x527639: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0052763b: { // 0x52763b: 7517 JNZ 0x527654
    if(integer::condition("JNZ",flags)) goto L00527654;
  }
  L0052763d: { // 0x52763d: 8a8ec4020000 MOV CL, byte ptr [ESI + 0x2c4]
    s.cx = with_al(s.cx, m.r8((s.si+0x000002c4u)));
  }
  L00527643: { // 0x527643: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00527645: { // 0x527645: 740d JZ 0x527654
    if(integer::condition("JZ",flags)) goto L00527654;
  }
  L00527647: { // 0x527647: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00527649: { // 0x527649: e872210000 CALL 0x5297c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005297c0u,5404238u); flags=s.arithmetic_flags;
  }
  L0052764e: { // 0x52764e: 8b86a4000000 MOV EAX, dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00527654: { // 0x527654: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00527655: { // 0x527655: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { // 0x47b190: 8b4138 MOV EAX, dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { // 0x47b193: 3dffff0000 CMP EAX, 0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { // 0x47b198: 7407 JZ 0x47b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { // 0x47b19a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { // 0x47b19c: 7403 JZ 0x47b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { // 0x47b19e: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0047b1a3: { // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6487520u:f_0022fde0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5792480u:f_001862e0(m,s,child,{});break;
case 5404208u:f_00127630(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
default:throw std::domain_error("recovery1108 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005874e0(Memory& original,const Inputs& i){
 const auto ri=original.r32(0xa581dcu),rj=original.r32(0xa581e0u);const auto cw=i.fp.image.word(0);
 if(i.arg[0]!=1u||i.cx!=0u||original.r32(0x836b4cu)!=7u||original.r32(0xa58634u)!=3u||original.r32(0xa58638u)!=9u||original.r8(0xa581d8u)!=0u||ri>=250u||rj!=(ri+103u)%250u||(cw!=0x37fu&&cw!=0x27fu&&cw!=0xe7fu))throw std::domain_error("recovery1108 outside reviewed class1 cached-resource positive domain");

 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);


  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005874e0: { // 0x5874e0: 83ec60 SUB ESP, 0x60
    f.sp = integer::sub(f.sp,0x00000060u,32,flags);
  }
  L005874e3: { // 0x5874e3: 8b442464 MOV EAX, dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L005874e7: { // 0x5874e7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005874e8: { // 0x5874e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005874e9: { // 0x5874e9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005874ea: { // 0x5874ea: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005874eb: { // 0x5874eb: bf01000000 MOV EDI, 1
    s.di = 1u;
  }
  L005874f0: { // 0x5874f0: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L005874f2: { // 0x5874f2: 8954242c MOV dword ptr [ESP + 0x2c], EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005874f6: { // 0x5874f6: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005874fa: { // 0x5874fa: 897c2410 MOV dword ptr [ESP + 0x10], EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L005874fe: { // 0x5874fe: 897c2424 MOV dword ptr [ESP + 0x24], EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L00587502: { // 0x587502: 0f8e96000000 JLE 0x58759e
    if(integer::condition("JLE",flags)) goto L0058759e;
  }
  L00587508: { // 0x587508: db442474 FILD dword ptr [ESP + 0x74]
    const auto address=(f.sp+0x00000074u);
    s.fp.load_integer32(m.r32(address));
  }
  L0058750c: { // 0x58750c: c744243800000000 MOV dword ptr [ESP + 0x38], 0
    m.w32((f.sp+0x00000038u), 0u);
  }
  L00587514: { // 0x587514: c744243c0000e03f MOV dword ptr [ESP + 0x3c], 0x3fe00000
    m.w32((f.sp+0x0000003cu), 0x3fe00000u);
  }
  L0058751c: { // 0x58751c: c744243000000000 MOV dword ptr [ESP + 0x30], 0
    m.w32((f.sp+0x00000030u), 0u);
  }
  L00587524: { // 0x587524: c744243400000040 MOV dword ptr [ESP + 0x34], 0x40000000
    m.w32((f.sp+0x00000034u), 0x40000000u);
  }
  L0058752c: { // 0x58752c: dd5c2424 FSTP qword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00587530: { // 0x587530: dd0568857800 FLD qword ptr [0x788568]
    const auto address=(0x00788568u);
    s.fp.load64(read64(m,address));
  }
  L00587536: { // 0x587536: dc5c2424 FCOMP qword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0058753a: { // 0x58753a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058753c: { // 0x58753c: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058753f: { // 0x58753f: 7522 JNZ 0x587563
    if(integer::condition("JNZ",flags)) goto L00587563;
  }
  L00587541: { // 0x587541: dd442424 FLD qword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load64(read64(m,address));
  }
  L00587545: { // 0x587545: dc25f8567800 FSUB qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.subtract64(read64(m,address));
  }
  L0058754b: { // 0x58754b: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L00587551: { // 0x587551: dd542438 FST qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00587555: { // 0x587555: dc05f8567800 FADD qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.add64(read64(m,address));
  }
  L0058755b: { // 0x58755b: dd5c2430 FSTP qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058755f: { // 0x58755f: eb02 JMP 0x587563
    goto L00587563;
  }
  L00587561: { // 0x587561: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00587563: { // 0x587563: b96879a500 MOV ECX, 0xa57968
    s.cx = 0x00a57968u;
  }
  L00587568: { // 0x587568: e8b3f0feff CALL 0x576620
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576620u,5797229u); flags=s.arithmetic_flags;
  }
  L0058756d: { // 0x58756d: dc4c2438 FMUL qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.multiply64(read64(m,address));
  }
  L00587571: { // 0x587571: dc442430 FADD qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.add64(read64(m,address));
  }
  L00587575: { // 0x587575: dc15f8567800 FCOM qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0058757b: { // 0x58757b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058757d: { // 0x58757d: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00587580: { // 0x587580: 75df JNZ 0x587561
    if(integer::condition("JNZ",flags)) goto L00587561;
  }
  L00587582: { // 0x587582: dc542424 FCOM qword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00587586: { // 0x587586: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00587588: { // 0x587588: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058758b: { // 0x58758b: 74d4 JZ 0x587561
    if(integer::condition("JZ",flags)) goto L00587561;
  }
  L0058758d: { // 0x58758d: e8be341e00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5797266u); flags=s.arithmetic_flags;
  }
  L00587592: { // 0x587592: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00587596: { // 0x587596: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0058759a: { // 0x58759a: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0058759e: { // 0x58759e: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005875a2: { // 0x5875a2: 8d0487 LEA EAX, [EDI + EAX*4]
    s.ax = (s.di+(s.ax * 4u));
  }
  L005875a5: { // 0x5875a5: c1e002 SHL EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::left);
  }
  L005875a8: { // 0x5875a8: 83ff02 CMP EDI, 2
    (void)integer::sub(s.di,2u,32,flags);
  }
  L005875ab: { // 0x5875ab: 8b88b8ba7c00 MOV ECX, dword ptr [EAX + 0x7cbab8]
    s.cx = m.r32((s.ax+0x007cbab8u));
  }
  L005875b1: { // 0x5875b1: 8ba838bb7c00 MOV EBP, dword ptr [EAX + 0x7cbb38]
    s.bp = m.r32((s.ax+0x007cbb38u));
  }
  L005875b7: { // 0x5875b7: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L005875bb: { // 0x5875bb: 7572 JNZ 0x58762f
    if(integer::condition("JNZ",flags)) goto L0058762f;
  }
  L005875bd: { // 0x5875bd: b9d881a500 MOV ECX, 0xa581d8
    s.cx = 0x00a581d8u;
  }
  L005875c2: { // 0x5875c2: e819880a00 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5797319u); flags=s.arithmetic_flags;
  }
  L005875c7: { // 0x5875c7: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005875c9: { // 0x5875c9: 89442440 MOV dword ptr [ESP + 0x40], EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L005875cd: { // 0x5875cd: 895c2444 MOV dword ptr [ESP + 0x44], EBX
    m.w32((f.sp+0x00000044u), s.bx);
  }
  L005875d1: { // 0x5875d1: df6c2440 FILD qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005875d5: { // 0x5875d5: dc0db00d7900 FMUL qword ptr [0x790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L005875db: { // 0x5875db: dc1d500d7900 FCOMP qword ptr [0x790d50]
    const auto address=(0x00790d50u);
    s.fp.compare_pop64(read64(m,address));
  }
  L005875e1: { // 0x5875e1: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L005875e3: { // 0x5875e3: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L005875e6: { // 0x5875e6: 7449 JZ 0x587631
    if(integer::condition("JZ",flags)) goto L00587631;
  }
  L005875e8: { // 0x5875e8: 8d75ff LEA ESI, [EBP - 1]
    s.si = (s.bp-1u);
  }
  L005875eb: { // 0x5875eb: 895c244c MOV dword ptr [ESP + 0x4c], EBX
    m.w32((f.sp+0x0000004cu), s.bx);
  }
  L005875ef: { // 0x5875ef: 8d56fa LEA EDX, [ESI - 6]
    s.dx = (s.si-6u);
  }
  L005875f2: { // 0x5875f2: 89542448 MOV dword ptr [ESP + 0x48], EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L005875f6: { // 0x5875f6: df6c2448 FILD qword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L005875fa: { // 0x5875fa: dd5c2414 FSTP qword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005875fe: { // 0x5875fe: b9d881a500 MOV ECX, 0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00587603: { // 0x587603: e8d8870a00 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5797384u); flags=s.arithmetic_flags;
  }
  L00587608: { // 0x587608: 89442450 MOV dword ptr [ESP + 0x50], EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0058760c: { // 0x58760c: 895c2454 MOV dword ptr [ESP + 0x54], EBX
    m.w32((f.sp+0x00000054u), s.bx);
  }
  L00587610: { // 0x587610: df6c2450 FILD qword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00587614: { // 0x587614: dc4c2414 FMUL qword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply64(read64(m,address));
  }
  L00587618: { // 0x587618: dc0db00d7900 FMUL qword ptr [0x790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0058761e: { // 0x58761e: dc05c8b57800 FADD qword ptr [0x78b5c8]
    const auto address=(0x0078b5c8u);
    s.fp.add64(read64(m,address));
  }
  L00587624: { // 0x587624: e827341e00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5797417u); flags=s.arithmetic_flags;
  }
  L00587629: { // 0x587629: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0058762b: { // 0x58762b: 77d1 JA 0x5875fe
    if(integer::condition("JA",flags)) goto L005875fe;
  }
  L0058762d: { // 0x58762d: eb41 JMP 0x587670
    goto L00587670;
  }
  L0058762f: { // 0x58762f: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00587631: { // 0x587631: 8d75ff LEA ESI, [EBP - 1]
    s.si = (s.bp-1u);
  }
  L00587634: { // 0x587634: 895c245c MOV dword ptr [ESP + 0x5c], EBX
    m.w32((f.sp+0x0000005cu), s.bx);
  }
  L00587638: { // 0x587638: 8d4601 LEA EAX, [ESI + 1]
    s.ax = (s.si+1u);
  }
  L0058763b: { // 0x58763b: 89442458 MOV dword ptr [ESP + 0x58], EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0058763f: { // 0x58763f: df6c2458 FILD qword ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L00587643: { // 0x587643: dd5c2414 FSTP qword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00587647: { // 0x587647: b9d881a500 MOV ECX, 0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0058764c: { // 0x58764c: e88f870a00 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5797457u); flags=s.arithmetic_flags;
  }
  L00587651: { // 0x587651: 89442460 MOV dword ptr [ESP + 0x60], EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L00587655: { // 0x587655: 895c2464 MOV dword ptr [ESP + 0x64], EBX
    m.w32((f.sp+0x00000064u), s.bx);
  }
  L00587659: { // 0x587659: df6c2460 FILD qword ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0058765d: { // 0x58765d: dc4c2414 FMUL qword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply64(read64(m,address));
  }
  L00587661: { // 0x587661: dc0db00d7900 FMUL qword ptr [0x790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L00587667: { // 0x587667: e8e4331e00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5797484u); flags=s.arithmetic_flags;
  }
  L0058766c: { // 0x58766c: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0058766e: { // 0x58766e: 77d7 JA 0x587647
    if(integer::condition("JA",flags)) goto L00587647;
  }
  L00587670: { // 0x587670: 3beb CMP EBP, EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00587672: { // 0x587672: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00587676: { // 0x587676: 0f8e90000000 JLE 0x58770c
    if(integer::condition("JLE",flags)) goto L0058770c;
  }
  L0058767c: { // 0x58767c: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00587680: { // 0x587680: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00587682: { // 0x587682: 8d040b LEA EAX, [EBX + ECX]
    s.ax = (s.bx+s.cx);
  }
  L00587685: { // 0x587685: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00587686: { // 0x587686: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00587688: { // 0x587688: 8b442430 MOV EAX, dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0058768c: { // 0x58768c: 8b1490 MOV EDX, dword ptr [EAX + EDX*4]
    s.dx = m.r32((s.ax+(s.dx * 4u)));
  }
  L0058768f: { // 0x58768f: 8d0c52 LEA ECX, [EDX + EDX*2]
    s.cx = (s.dx+(s.dx * 2u));
  }
  L00587692: { // 0x587692: 8d3c8db87ca500 LEA EDI, [ECX*4 + 0xa57cb8]
    s.di = ((s.cx * 4u)+0x00a57cb8u);
  }
  L00587699: { // 0x587699: 8b0c8db87ca500 MOV ECX, dword ptr [ECX*4 + 0xa57cb8]
    s.cx = m.r32(((s.cx * 4u)+0x00a57cb8u));
  }
  L005876a0: { // 0x5876a0: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005876a2: { // 0x5876a2: 7e16 JLE 0x5876ba
    if(integer::condition("JLE",flags)) goto L005876ba;
  }
  L005876a4: { // 0x5876a4: 8b4704 MOV EAX, dword ptr [EDI + 4]
    s.ax = m.r32((s.di+4u));
  }
  L005876a7: { // 0x5876a7: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L005876aa: { // 0x5876aa: 8b54241c MOV EDX, dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005876ae: { // 0x5876ae: 3910 CMP dword ptr [EAX], EDX
    (void)integer::sub(m.r32((s.ax)),s.dx,32,flags);
  }
  L005876b0: { // 0x5876b0: 7408 JZ 0x5876ba
    if(integer::condition("JZ",flags)) goto L005876ba;
  }
  L005876b2: { // 0x5876b2: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005876b3: { // 0x5876b3: 83c008 ADD EAX, 8
    s.ax = integer::add(s.ax,8u,32,flags);
  }
  L005876b6: { // 0x5876b6: 3bf1 CMP ESI, ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L005876b8: { // 0x5876b8: 7cf0 JL 0x5876aa
    if(integer::condition("JL",flags)) goto L005876aa;
  }
  L005876ba: { // 0x5876ba: 8b4704 MOV EAX, dword ptr [EDI + 4]
    s.ax = m.r32((s.di+4u));
  }
  L005876bd: { // 0x5876bd: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005876c1: { // 0x5876c1: 6a01 PUSH 1
    f.push(m,1u);
  }
  L005876c3: { // 0x5876c3: 6a01 PUSH 1
    f.push(m,1u);
  }
  L005876c5: { // 0x5876c5: 8b04f0 MOV EAX, dword ptr [EAX + ESI*8]
    s.ax = m.r32((s.ax+(s.si * 8u)));
  }
  L005876c8: { // 0x5876c8: 668b11 MOV DX, word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005876cb: { // 0x5876cb: 89442470 MOV dword ptr [ESP + 0x70], EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L005876cf: { // 0x5876cf: 662bd0 SUB DX, AX
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L005876d2: { // 0x5876d2: 668b4102 MOV AX, word ptr [ECX + 2]
    s.ax = with_ax(s.ax, m.r16((s.cx+2u)));
  }
  L005876d6: { // 0x5876d6: 6689542428 MOV word ptr [ESP + 0x28], DX
    m.w16((f.sp+0x00000028u), (s.dx & 0xffffu));
  }
  L005876db: { // 0x5876db: 662b442472 SUB AX, word ptr [ESP + 0x72]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x00000072u)),16,flags));
  }
  L005876e0: { // 0x5876e0: 8d542440 LEA EDX, [ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L005876e4: { // 0x5876e4: 668944242a MOV word ptr [ESP + 0x2a], AX
    m.w16((f.sp+0x0000002au), (s.ax & 0xffffu));
  }
  L005876e9: { // 0x5876e9: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L005876ed: { // 0x5876ed: 894c2440 MOV dword ptr [ESP + 0x40], ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L005876f1: { // 0x5876f1: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L005876f4: { // 0x5876f4: e8e7ebffff CALL 0x5862e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005862e0u,5797625u); flags=s.arithmetic_flags;
  }
  L005876f9: { // 0x5876f9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005876fb: { // 0x5876fb: 753b JNZ 0x587738
    if(integer::condition("JNZ",flags)) goto L00587738;
  }
  L005876fd: { // 0x5876fd: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005876fe: { // 0x5876fe: 3bdd CMP EBX, EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L00587700: { // 0x587700: 0f8c76ffffff JL 0x58767c
    if(integer::condition("JL",flags)) goto L0058767c;
  }
  L00587706: { // 0x587706: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0058770a: { // 0x58770a: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0058770c: { // 0x58770c: 8b542474 MOV EDX, dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00587710: { // 0x587710: 8d4701 LEA EAX, [EDI + 1]
    s.ax = (s.di+1u);
  }
  L00587713: { // 0x587713: 8d4a01 LEA ECX, [EDX + 1]
    s.cx = (s.dx+1u);
  }
  L00587716: { // 0x587716: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00587717: { // 0x587717: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00587719: { // 0x587719: 3bd3 CMP EDX, EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0058771b: { // 0x58771b: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0058771f: { // 0x58771f: 750c JNZ 0x58772d
    if(integer::condition("JNZ",flags)) goto L0058772d;
  }
  L00587721: { // 0x587721: c744241001000000 MOV dword ptr [ESP + 0x10], 1
    m.w32((f.sp+0x00000010u), 1u);
  }
  L00587729: { // 0x587729: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0058772d: { // 0x58772d: 3b542424 CMP EDX, dword ptr [ESP + 0x24]
    (void)integer::sub(s.dx,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L00587731: { // 0x587731: 7454 JZ 0x587787
    if(integer::condition("JZ",flags)) goto L00587787;
  }
  L00587733: { // 0x587733: e962feffff JMP 0x58759a
    goto L0058759a;
  }
  L00587738: { // 0x587738: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L0058773b: { // 0x58773b: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0058773f: { // 0x58773f: 8b04f2 MOV EAX, dword ptr [EDX + ESI*8]
    s.ax = m.r32((s.dx+(s.si * 8u)));
  }
  L00587742: { // 0x587742: 668b11 MOV DX, word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L00587745: { // 0x587745: 89442468 MOV dword ptr [ESP + 0x68], EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L00587749: { // 0x587749: 662bd0 SUB DX, AX
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0058774c: { // 0x58774c: 668b4102 MOV AX, word ptr [ECX + 2]
    s.ax = with_ax(s.ax, m.r16((s.cx+2u)));
  }
  L00587750: { // 0x587750: 8b4c247c MOV ECX, dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L00587754: { // 0x587754: 662b44246a SUB AX, word ptr [ESP + 0x6a]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000006au)),16,flags));
  }
  L00587759: { // 0x587759: 6689542474 MOV word ptr [ESP + 0x74], DX
    m.w16((f.sp+0x00000074u), (s.dx & 0xffffu));
  }
  L0058775e: { // 0x58775e: 6689442476 MOV word ptr [ESP + 0x76], AX
    m.w16((f.sp+0x00000076u), (s.ax & 0xffffu));
  }
  L00587763: { // 0x587763: 8b542474 MOV EDX, dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00587767: { // 0x587767: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L00587769: { // 0x587769: 8b4c2478 MOV ECX, dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0058776d: { // 0x58776d: 8b4708 MOV EAX, dword ptr [EDI + 8]
    s.ax = m.r32((s.di+8u));
  }
  L00587770: { // 0x587770: 8b942480000000 MOV EDX, dword ptr [ESP + 0x80]
    s.dx = m.r32((f.sp+0x00000080u));
  }
  L00587777: { // 0x587777: 8901 MOV dword ptr [ECX], EAX
    m.w32((s.cx), s.ax);
  }
  L00587779: { // 0x587779: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058777a: { // 0x58777a: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L0058777c: { // 0x58777c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058777d: { // 0x58777d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058777e: { // 0x58777e: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00587780: { // 0x587780: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00587781: { // 0x587781: 83c460 ADD ESP, 0x60
    f.sp = integer::add(f.sp,0x00000060u,32,flags);
  }
  L00587784: { // 0x587784: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00587787: { // 0x587787: 8b442478 MOV EAX, dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L0058778b: { // 0x58778b: 8b4c247c MOV ECX, dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L0058778f: { // 0x58778f: 66895c2474 MOV word ptr [ESP + 0x74], BX
    m.w16((f.sp+0x00000074u), (s.bx & 0xffffu));
  }
  L00587794: { // 0x587794: 66895c2476 MOV word ptr [ESP + 0x76], BX
    m.w16((f.sp+0x00000076u), (s.bx & 0xffffu));
  }
  L00587799: { // 0x587799: 8b542474 MOV EDX, dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L0058779d: { // 0x58779d: c700ffff0000 MOV dword ptr [EAX], 0xffff
    m.w32((s.ax), 0x0000ffffu);
  }
  L005877a3: { // 0x5877a3: 8b842480000000 MOV EAX, dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L005877aa: { // 0x5877aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005877ab: { // 0x5877ab: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L005877ad: { // 0x5877ad: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005877ae: { // 0x5877ae: c700ffffffff MOV dword ptr [EAX], 0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  L005877b4: { // 0x5877b4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005877b5: { // 0x5877b5: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005877b7: { // 0x5877b7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005877b8: { // 0x5877b8: 83c460 ADD ESP, 0x60
    f.sp = integer::add(f.sp,0x00000060u,32,flags);
  }
  L005877bb: { // 0x5877bb: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
