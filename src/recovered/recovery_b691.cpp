#include "recovered/recovery_b691_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b691 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000ec700(Memory&,State&,Frame&,const Operations&);
void f_002cc360(Memory&,State&,Frame&,const Operations&);
void f_002cc370(Memory&,State&,Frame&,const Operations&);
void f_0001b380(Memory&,State&,Frame&,const Operations&);
void f_000f47b0(Memory&,State&,Frame&,const Operations&);
void f_0004a620(Memory&,State&,Frame&,const Operations&);
void f_002c2ba0(Memory&,State&,Frame&,const Operations&);
void f_002ce3f0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_002cdb10(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
void f_00164f30(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_002c2290(Memory&,State&,Frame&,const Operations&);

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
void f_000ec700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ec700: { // 0x4ec700: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ec701: { // 0x4ec701: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ec702: { // 0x4ec702: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004ec703: { // 0x4ec703: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L004ec707: { // 0x4ec707: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ec708: { // 0x4ec708: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004ec70a: { // 0x4ec70a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ec70b: { // 0x4ec70b: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004ec70f: { // 0x4ec70f: 8d9958010000 LEA EBX,[ECX + 0x158]
    s.bx = (s.cx+0x00000158u);
  }
  L004ec715: { // 0x4ec715: 833b00 CMP dword ptr [EBX],0x0
    (void)integer::sub(m.r32((s.bx)),0x00000000u,32,flags);
  }
  L004ec718: { // 0x4ec718: 751c JNZ 0x004ec736
    if(integer::condition("JNZ",flags)) goto L004ec736;
  }
  L004ec71a: { // 0x4ec71a: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L004ec71c: { // 0x4ec71c: e836122800 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5162785u); flags=s.arithmetic_flags;
  }
  L004ec721: { // 0x4ec721: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004ec724: { // 0x4ec724: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ec726: { // 0x4ec726: 740a JZ 0x004ec732
    if(integer::condition("JZ",flags)) goto L004ec732;
  }
  L004ec728: { // 0x4ec728: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ec729: { // 0x4ec729: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004ec72b: { // 0x4ec72b: e880d02200 CALL 0x007197b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007197b0u,5162800u); flags=s.arithmetic_flags;
  }
  L004ec730: { // 0x4ec730: eb02 JMP 0x004ec734
    goto L004ec734;
  }
  L004ec732: { // 0x4ec732: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ec734: { // 0x4ec734: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L004ec736: { // 0x4ec736: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L004ec738: { // 0x4ec738: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004ec73a: { // 0x4ec73a: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L004ec73d: { // 0x4ec73d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ec73f: { // 0x4ec73f: 7e3f JLE 0x004ec780
    if(integer::condition("JLE",flags)) goto L004ec780;
  }
  L004ec741: { // 0x4ec741: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ec742: { // 0x4ec742: e8d9d12200 CALL 0x00719920
    s.arithmetic_flags=flags; invoke(m,s,f,0x00719920u,5162823u); flags=s.arithmetic_flags;
  }
  L004ec747: { // 0x4ec747: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004ec749: { // 0x4ec749: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ec74b: { // 0x4ec74b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ec74c: { // 0x4ec74c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004ec752: { // 0x4ec752: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ec754: { // 0x4ec754: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004ec756: { // 0x4ec756: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L004ec759: { // 0x4ec759: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ec75a: { // 0x4ec75a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004ec760: { // 0x4ec760: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ec762: { // 0x4ec762: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ec765: { // 0x4ec765: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ec768: { // 0x4ec768: 663b4d00 CMP CX,word ptr [EBP]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.bp)),16,flags);
  }
  L004ec76c: { // 0x4ec76c: 7506 JNZ 0x004ec774
    if(integer::condition("JNZ",flags)) goto L004ec774;
  }
  L004ec76e: { // 0x4ec76e: 663b4502 CMP AX,word ptr [EBP + 0x2]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.bp+0x00000002u)),16,flags);
  }
  L004ec772: { // 0x4ec772: 741b JZ 0x004ec78f
    if(integer::condition("JZ",flags)) goto L004ec78f;
  }
  L004ec774: { // 0x4ec774: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L004ec776: { // 0x4ec776: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004ec777: { // 0x4ec777: 3b7938 CMP EDI,dword ptr [ECX + 0x38]
    (void)integer::sub(s.di,m.r32((s.cx+0x00000038u)),32,flags);
  }
  L004ec77a: { // 0x4ec77a: 7cc5 JL 0x004ec741
    if(integer::condition("JL",flags)) goto L004ec741;
  }
  L004ec77c: { // 0x4ec77c: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L004ec780: { // 0x4ec780: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004ec781: { // 0x4ec781: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L004ec784: { // 0x4ec784: 83fe0c CMP ESI,0xc
    (void)integer::sub(s.si,0x0000000cu,32,flags);
  }
  L004ec787: { // 0x4ec787: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004ec78b: { // 0x4ec78b: 7d0c JGE 0x004ec799
    if(integer::condition("JGE",flags)) goto L004ec799;
  }
  L004ec78d: { // 0x4ec78d: eb86 JMP 0x004ec715
    goto L004ec715;
  }
  L004ec78f: { // 0x4ec78f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ec791: { // 0x4ec791: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ec792: { // 0x4ec792: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ec793: { // 0x4ec793: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ec794: { // 0x4ec794: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ec795: { // 0x4ec795: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004ec796: { // 0x4ec796: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004ec799: { // 0x4ec799: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ec79a: { // 0x4ec79a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ec79b: { // 0x4ec79b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ec79c: { // 0x4ec79c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ec79e: { // 0x4ec79e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ec79f: { // 0x4ec79f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004ec7a0: { // 0x4ec7a0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002cc360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc360: { // 0x6cc360: 8a8104020000 MOV AL, byte ptr [ECX + 0x204]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000204u)));
  }
  L006cc366: { // 0x6cc366: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cc370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc370: { // 0x6cc370: 8a8105020000 MOV AL, byte ptr [ECX + 0x205]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000205u)));
  }
  L006cc376: { // 0x6cc376: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b380: { // 0x41b380: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0041b382: { // 0x41b382: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000f47b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f47b0: { // 0x4f47b0: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004f47b5: { // 0x4f47b5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f47b7: { // 0x4f47b7: 751d JNZ 0x4f47d6
    if(integer::condition("JNZ",flags)) goto L004f47d6;
  }
  L004f47b9: { // 0x4f47b9: 8a8134010000 MOV AL, byte ptr [ECX + 0x134]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000134u)));
  }
  L004f47bf: { // 0x4f47bf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47c1: { // 0x4f47c1: 750d JNZ 0x4f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47c3: { // 0x4f47c3: 8a8135010000 MOV AL, byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  L004f47c9: { // 0x4f47c9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47cb: { // 0x4f47cb: 7503 JNZ 0x4f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47cd: { // 0x4f47cd: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47cf: { // 0x4f47cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d0: { // 0x4f47d0: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004f47d5: { // 0x4f47d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d6: { // 0x4f47d6: 8b15e4e0a100 MOV EDX, dword ptr [0xa1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L004f47dc: { // 0x4f47dc: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47de: { // 0x4f47de: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f47e0: { // 0x4f47e0: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f47e3: { // 0x4f47e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0004a620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044a620: { // 0x44a620: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044a621: { // 0x44a621: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0044a623: { // 0x44a623: 8b86fc030000 MOV EAX, dword ptr [ESI + 0x3fc]
    s.ax = m.r32((s.si+0x000003fcu));
  }
  L0044a629: { // 0x44a629: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044a62b: { // 0x44a62b: 7e04 JLE 0x44a631
    if(integer::condition("JLE",flags)) goto L0044a631;
  }
  L0044a62d: { // 0x44a62d: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0044a62f: { // 0x44a62f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044a630: { // 0x44a630: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0044a631: { // 0x44a631: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044a637: { // 0x44a637: 8b88440c0000 MOV ECX, dword ptr [EAX + 0xc44]
    s.cx = m.r32((s.ax+0x00000c44u));
  }
  L0044a63d: { // 0x44a63d: 83f928 CMP ECX, 0x28
    (void)integer::sub(s.cx,0x00000028u,32,flags);
  }
  L0044a640: { // 0x44a640: 745a JZ 0x44a69c
    if(integer::condition("JZ",flags)) goto L0044a69c;
  }
  L0044a642: { // 0x44a642: 83f910 CMP ECX, 0x10
    (void)integer::sub(s.cx,0x00000010u,32,flags);
  }
  L0044a645: { // 0x44a645: 7455 JZ 0x44a69c
    if(integer::condition("JZ",flags)) goto L0044a69c;
  }
  L0044a647: { // 0x44a647: 83f903 CMP ECX, 3
    (void)integer::sub(s.cx,3u,32,flags);
  }
  L0044a64a: { // 0x44a64a: 7450 JZ 0x44a69c
    if(integer::condition("JZ",flags)) goto L0044a69c;
  }
  L0044a64c: { // 0x44a64c: 8a884b130000 MOV CL, byte ptr [EAX + 0x134b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000134bu)));
  }
  L0044a652: { // 0x44a652: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044a654: { // 0x44a654: 7546 JNZ 0x44a69c
    if(integer::condition("JNZ",flags)) goto L0044a69c;
  }
  L0044a656: { // 0x44a656: 8a8853130000 MOV CL, byte ptr [EAX + 0x1353]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001353u)));
  }
  L0044a65c: { // 0x44a65c: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044a65e: { // 0x44a65e: 7425 JZ 0x44a685
    if(integer::condition("JZ",flags)) goto L0044a685;
  }
  L0044a660: { // 0x44a660: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L0044a665: { // 0x44a665: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044a667: { // 0x44a667: 7418 JZ 0x44a681
    if(integer::condition("JZ",flags)) goto L0044a681;
  }
  L0044a669: { // 0x44a669: a07056a200 MOV AL, byte ptr [0xa25670]
    s.ax = with_al(s.ax, m.r8((0x00a25670u)));
  }
  L0044a66e: { // 0x44a66e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044a670: { // 0x44a670: 740f JZ 0x44a681
    if(integer::condition("JZ",flags)) goto L0044a681;
  }
  L0044a672: { // 0x44a672: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044a678: { // 0x44a678: e873a10a00 CALL 0x4f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,4499069u); flags=s.arithmetic_flags;
  }
  L0044a67d: { // 0x44a67d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044a67f: { // 0x44a67f: 7504 JNZ 0x44a685
    if(integer::condition("JNZ",flags)) goto L0044a685;
  }
  L0044a681: { // 0x44a681: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0044a683: { // 0x44a683: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044a684: { // 0x44a684: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0044a685: { // 0x44a685: 8b8618040000 MOV EAX, dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044a68b: { // 0x44a68b: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0044a68d: { // 0x44a68d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044a68e: { // 0x44a68e: 8b90cc030000 MOV EDX, dword ptr [EAX + 0x3cc]
    s.dx = m.r32((s.ax+0x000003ccu));
  }
  L0044a694: { // 0x44a694: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0044a696: { // 0x44a696: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L0044a699: { // 0x44a699: 8ac1 MOV AL, CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L0044a69b: { // 0x44a69b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0044a69c: { // 0x44a69c: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0044a69e: { // 0x44a69e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044a69f: { // 0x44a69f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002c2ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c2ba0: { // 0x6c2ba0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c2ba1: { // 0x6c2ba1: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006c2ba3: { // 0x6c2ba3: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c2ba9: { // 0x6c2ba9: e8021ce3ff CALL 0x4f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7089070u); flags=s.arithmetic_flags;
  }
  L006c2bae: { // 0x6c2bae: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2bb0: { // 0x6c2bb0: 7425 JZ 0x6c2bd7
    if(integer::condition("JZ",flags)) goto L006c2bd7;
  }
  L006c2bb2: { // 0x6c2bb2: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c2bb4: { // 0x6c2bb4: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006c2bb6: { // 0x6c2bb6: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7089084u); flags=s.arithmetic_flags;
  }
  L006c2bbc: { // 0x6c2bbc: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2bbe: { // 0x6c2bbe: 7417 JZ 0x6c2bd7
    if(integer::condition("JZ",flags)) goto L006c2bd7;
  }
  L006c2bc0: { // 0x6c2bc0: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L006c2bc3: { // 0x6c2bc3: 7412 JZ 0x6c2bd7
    if(integer::condition("JZ",flags)) goto L006c2bd7;
  }
  L006c2bc5: { // 0x6c2bc5: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c2bc7: { // 0x6c2bc7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006c2bc9: { // 0x6c2bc9: ff9224030000 CALL dword ptr [EDX + 0x324]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000324u)),7089103u); flags=s.arithmetic_flags;
  }
  L006c2bcf: { // 0x6c2bcf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2bd1: { // 0x6c2bd1: 7504 JNZ 0x6c2bd7
    if(integer::condition("JNZ",flags)) goto L006c2bd7;
  }
  L006c2bd3: { // 0x6c2bd3: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L006c2bd5: { // 0x6c2bd5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2bd6: { // 0x6c2bd6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c2bd7: { // 0x6c2bd7: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c2bd9: { // 0x6c2bd9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2bda: { // 0x6c2bda: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002ce3f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce3f0: { // 0x6ce3f0: 8b91fc030000 MOV EDX, dword ptr [ECX + 0x3fc]
    s.dx = m.r32((s.cx+0x000003fcu));
  }
  L006ce3f6: { // 0x6ce3f6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006ce3f8: { // 0x6ce3f8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006ce3fa: { // 0x6ce3fa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006ce3fd: { // 0x6ce3fd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("691 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdb10: { // 0x6cdb10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdb11: { // 0x6cdb11: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdb13: { // 0x6cdb13: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdb15: { // 0x6cdb15: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133979u); flags=s.arithmetic_flags;
  }
  L006cdb1b: { // 0x6cdb1b: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdb1d: { // 0x6cdb1d: e8ce700000 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7133986u); flags=s.arithmetic_flags;
  }
  L006cdb22: { // 0x6cdb22: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdb24: { // 0x6cdb24: 7413 JZ 0x6cdb39
    if(integer::condition("JZ",flags)) goto L006cdb39;
  }
  L006cdb26: { // 0x6cdb26: 8b860c010000 MOV EAX, dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006cdb2c: { // 0x6cdb2c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb2e: { // 0x6cdb2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb2f: { // 0x6cdb2f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb31: { // 0x6cdb31: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134007u); flags=s.arithmetic_flags;
  }
  L006cdb37: { // 0x6cdb37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb38: { // 0x6cdb38: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006cdb39: { // 0x6cdb39: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb3b: { // 0x6cdb3b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdb3d: { // 0x6cdb3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb3e: { // 0x6cdb3e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb40: { // 0x6cdb40: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134022u); flags=s.arithmetic_flags;
  }
  L006cdb46: { // 0x6cdb46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb47: { // 0x6cdb47: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0004d670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d670: { // 0x44d670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d671: { // 0x44d671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d672: { // 0x44d672: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d673: { // 0x44d673: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044d677: { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d678: { // 0x44d678: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044d67a: { // 0x44d67a: 8a87c6050000 MOV AL, byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0044d680: { // 0x44d680: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d682: { // 0x44d682: 742c JZ 0x44d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  L0044d684: { // 0x44d684: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d686: { // 0x44d686: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d688: { // 0x44d688: 7e26 JLE 0x44d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  L0044d68a: { // 0x44d68a: 8db7c0040000 LEA ESI, [EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0044d692: { // 0x44d692: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d694: { // 0x44d694: 740b JZ 0x44d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  L0044d696: { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d697: { // 0x44d697: e894742800 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4511388u); flags=s.arithmetic_flags;
  }
  L0044d69c: { // 0x44d69c: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L0044d69f: { // 0x44d69f: 7517 JNZ 0x44d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX, byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0044d6a8: { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d6a9: { // 0x44d6a9: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L0044d6ac: { // 0x44d6ac: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d6ae: { // 0x44d6ae: 7ce0 JL 0x44d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d6b1: { // 0x44d6b1: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d6b3: { // 0x44d6b3: e8f8032800 CALL 0x6cdab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cdab0u,4511416u); flags=s.arithmetic_flags;
  }
  L0044d6b8: { // 0x44d6b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d6b9: { // 0x44d6b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d6ba: { // 0x44d6ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d6bb: { // 0x44d6bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d6bc: { // 0x44d6bc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX, [ECX + EDX*4 + 0x74c]
    s.ax = (s.cx+(s.dx * 4u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4bf0: { // 0x6d4bf0: 8b9104070000 MOV EDX, dword ptr [ECX + 0x704]
    s.dx = m.r32((s.cx+0x00000704u));
  }
  L006d4bf6: { // 0x6d4bf6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d4bf8: { // 0x6d4bf8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d4bfa: { // 0x6d4bfa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006d4bfd: { // 0x6d4bfd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX, dword ptr [EDI + 4]
    s.ax = m.r32((s.di+4u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX, 9
    s.dx = integer::shift(s.dx,9u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x5454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX, dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x5454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX, dword ptr [ECX + EDX*4]
    s.dx = m.r32((s.cx+(s.dx * 4u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x5454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc], SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe], AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00164f30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00564f30: { // 0x564f30: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00564f33: { // 0x564f33: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00564f34: { // 0x564f34: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00564f38: { // 0x564f38: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00564f3b: { // 0x564f3b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f3c: { // 0x564f3c: f73d4878a500 IDIV dword ptr [0x00a57848]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((0x00a57848u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00564f42: { // 0x564f42: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00564f44: { // 0x564f44: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f45: { // 0x564f45: 0f848d000000 JZ 0x00564fd8
    if(integer::condition("JZ",flags)) goto L00564fd8;
  }
  L00564f4b: { // 0x564f4b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00564f4d: { // 0x564f4d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564f4f: { // 0x564f4f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00564f51: { // 0x564f51: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f52: { // 0x564f52: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564f58: { // 0x564f58: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564f5a: { // 0x564f5a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f5d: { // 0x564f5d: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L00564f62: { // 0x564f62: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00564f65: { // 0x564f65: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f66: { // 0x564f66: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564f6c: { // 0x564f6c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564f6e: { // 0x564f6e: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f71: { // 0x564f71: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f73: { // 0x564f73: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L00564f78: { // 0x564f78: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L00564f7c: { // 0x564f7c: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00564f80: { // 0x564f80: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00564f81: { // 0x564f81: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00564f83: { // 0x564f83: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00564f85: { // 0x564f85: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00564f8a: { // 0x564f8a: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L00564f8f: { // 0x564f8f: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00564f92: { // 0x564f92: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00564f95: { // 0x564f95: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00564f98: { // 0x564f98: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00564f9a: { // 0x564f9a: 7818 JS 0x00564fb4
    if(integer::condition("JS",flags)) goto L00564fb4;
  }
  L00564f9c: { // 0x564f9c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00564fa1: { // 0x564fa1: 7d11 JGE 0x00564fb4
    if(integer::condition("JGE",flags)) goto L00564fb4;
  }
  L00564fa3: { // 0x564fa3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00564fa9: { // 0x564fa9: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00564fac: { // 0x564fac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00564fae: { // 0x564fae: 7404 JZ 0x00564fb4
    if(integer::condition("JZ",flags)) goto L00564fb4;
  }
  L00564fb0: { // 0x564fb0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564fb2: { // 0x564fb2: eb0e JMP 0x00564fc2
    goto L00564fc2;
  }
  L00564fb4: { // 0x564fb4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00564fb8: { // 0x564fb8: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L00564fbd: { // 0x564fbd: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00564fc2: { // 0x564fc2: f6812c01000008 TEST byte ptr [ECX + 0x12c],0x8
    (void)integer::logical((m.r8((s.cx+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00564fc9: { // 0x564fc9: 0f858d000000 JNZ 0x0056505c
    if(integer::condition("JNZ",flags)) goto L0056505c;
  }
  L00564fcf: { // 0x564fcf: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L00564fd1: { // 0x564fd1: e8ea16f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5656534u); flags=s.arithmetic_flags;
  }
  L00564fd6: { // 0x564fd6: eb72 JMP 0x0056504a
    goto L0056504a;
  }
  L00564fd8: { // 0x564fd8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00564fda: { // 0x564fda: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564fdc: { // 0x564fdc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00564fde: { // 0x564fde: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564fdf: { // 0x564fdf: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564fe5: { // 0x564fe5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564fe7: { // 0x564fe7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564fea: { // 0x564fea: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L00564fef: { // 0x564fef: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00564ff2: { // 0x564ff2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564ff3: { // 0x564ff3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564ff9: { // 0x564ff9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564ffb: { // 0x564ffb: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564ffe: { // 0x564ffe: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L00565003: { // 0x565003: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L00565007: { // 0x565007: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0056500b: { // 0x56500b: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056500d: { // 0x56500d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0056500f: { // 0x56500f: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00565011: { // 0x565011: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00565016: { // 0x565016: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L0056501b: { // 0x56501b: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056501e: { // 0x56501e: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00565021: { // 0x565021: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00565024: { // 0x565024: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00565026: { // 0x565026: 7814 JS 0x0056503c
    if(integer::condition("JS",flags)) goto L0056503c;
  }
  L00565028: { // 0x565028: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056502d: { // 0x56502d: 7d0d JGE 0x0056503c
    if(integer::condition("JGE",flags)) goto L0056503c;
  }
  L0056502f: { // 0x56502f: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00565035: { // 0x565035: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00565038: { // 0x565038: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056503a: { // 0x56503a: 750e JNZ 0x0056504a
    if(integer::condition("JNZ",flags)) goto L0056504a;
  }
  L0056503c: { // 0x56503c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00565040: { // 0x565040: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00565045: { // 0x565045: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0056504a: { // 0x56504a: f6802c01000008 TEST byte ptr [EAX + 0x12c],0x8
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00565051: { // 0x565051: 7509 JNZ 0x0056505c
    if(integer::condition("JNZ",flags)) goto L0056505c;
  }
  L00565053: { // 0x565053: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00565055: { // 0x565055: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00565056: { // 0x565056: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565059: { // 0x565059: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0056505c: { // 0x56505c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056505e: { // 0x56505e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056505f: { // 0x56505f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565062: { // 0x565062: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

} // namespace
namespace {
void f_002c2290(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c2290: { // 0x6c2290: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L006c2293: { // 0x6c2293: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006c2297: { // 0x6c2297: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c2298: { // 0x6c2298: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c2299: { // 0x6c2299: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c229a: { // 0x6c229a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c229c: { // 0x6c229c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c229d: { // 0x6c229d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c229e: { // 0x6c229e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c22a3: { // 0x6c22a3: e85832e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7086760u); flags=s.arithmetic_flags;
  }
  L006c22a8: { // 0x6c22a8: 8a5c2438 MOV BL,byte ptr [ESP + 0x38]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000038u)));
  }
  L006c22ac: { // 0x6c22ac: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006c22ae: { // 0x6c22ae: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c22b0: { // 0x6c22b0: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L006c22b4: { // 0x6c22b4: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L006c22bc: { // 0x6c22bc: 7531 JNZ 0x006c22ef
    if(integer::condition("JNZ",flags)) goto L006c22ef;
  }
  L006c22be: { // 0x6c22be: a1ec87a200 MOV EAX,[0x00a287ec]
    s.ax = m.r32((0x00a287ecu));
  }
  L006c22c3: { // 0x6c22c3: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c22c9: { // 0x6c22c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c22ca: { // 0x6c22ca: e821e8e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086799u); flags=s.arithmetic_flags;
  }
  L006c22cf: { // 0x6c22cf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c22d1: { // 0x6c22d1: 7515 JNZ 0x006c22e8
    if(integer::condition("JNZ",flags)) goto L006c22e8;
  }
  L006c22d3: { // 0x6c22d3: a1f087a200 MOV EAX,[0x00a287f0]
    s.ax = m.r32((0x00a287f0u));
  }
  L006c22d8: { // 0x6c22d8: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c22de: { // 0x6c22de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c22df: { // 0x6c22df: e80ce8e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086820u); flags=s.arithmetic_flags;
  }
  L006c22e4: { // 0x6c22e4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c22e6: { // 0x6c22e6: 7407 JZ 0x006c22ef
    if(integer::condition("JZ",flags)) goto L006c22ef;
  }
  L006c22e8: { // 0x6c22e8: c644243801 MOV byte ptr [ESP + 0x38],0x1
    m.w8((f.sp+0x00000038u), 0x00000001u);
  }
  L006c22ed: { // 0x6c22ed: eb09 JMP 0x006c22f8
    goto L006c22f8;
  }
  L006c22ef: { // 0x6c22ef: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c22f1: { // 0x6c22f1: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L006c22f6: { // 0x6c22f6: 7531 JNZ 0x006c2329
    if(integer::condition("JNZ",flags)) goto L006c2329;
  }
  L006c22f8: { // 0x6c22f8: a1f487a200 MOV EAX,[0x00a287f4]
    s.ax = m.r32((0x00a287f4u));
  }
  L006c22fd: { // 0x6c22fd: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c2303: { // 0x6c2303: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2304: { // 0x6c2304: e8e7e7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086857u); flags=s.arithmetic_flags;
  }
  L006c2309: { // 0x6c2309: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c230b: { // 0x6c230b: 7515 JNZ 0x006c2322
    if(integer::condition("JNZ",flags)) goto L006c2322;
  }
  L006c230d: { // 0x6c230d: a1f887a200 MOV EAX,[0x00a287f8]
    s.ax = m.r32((0x00a287f8u));
  }
  L006c2312: { // 0x6c2312: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c2318: { // 0x6c2318: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2319: { // 0x6c2319: e8d2e7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086878u); flags=s.arithmetic_flags;
  }
  L006c231e: { // 0x6c231e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2320: { // 0x6c2320: 7407 JZ 0x006c2329
    if(integer::condition("JZ",flags)) goto L006c2329;
  }
  L006c2322: { // 0x6c2322: c644241101 MOV byte ptr [ESP + 0x11],0x1
    m.w8((f.sp+0x00000011u), 0x00000001u);
  }
  L006c2327: { // 0x6c2327: eb09 JMP 0x006c2332
    goto L006c2332;
  }
  L006c2329: { // 0x6c2329: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c232b: { // 0x6c232b: c644241100 MOV byte ptr [ESP + 0x11],0x0
    m.w8((f.sp+0x00000011u), 0x00000000u);
  }
  L006c2330: { // 0x6c2330: 7531 JNZ 0x006c2363
    if(integer::condition("JNZ",flags)) goto L006c2363;
  }
  L006c2332: { // 0x6c2332: a1e487a200 MOV EAX,[0x00a287e4]
    s.ax = m.r32((0x00a287e4u));
  }
  L006c2337: { // 0x6c2337: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c233d: { // 0x6c233d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c233e: { // 0x6c233e: e8ade7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086915u); flags=s.arithmetic_flags;
  }
  L006c2343: { // 0x6c2343: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2345: { // 0x6c2345: 7515 JNZ 0x006c235c
    if(integer::condition("JNZ",flags)) goto L006c235c;
  }
  L006c2347: { // 0x6c2347: a1e887a200 MOV EAX,[0x00a287e8]
    s.ax = m.r32((0x00a287e8u));
  }
  L006c234c: { // 0x6c234c: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c2352: { // 0x6c2352: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2353: { // 0x6c2353: e898e7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086936u); flags=s.arithmetic_flags;
  }
  L006c2358: { // 0x6c2358: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c235a: { // 0x6c235a: 7407 JZ 0x006c2363
    if(integer::condition("JZ",flags)) goto L006c2363;
  }
  L006c235c: { // 0x6c235c: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L006c2361: { // 0x6c2361: eb05 JMP 0x006c2368
    goto L006c2368;
  }
  L006c2363: { // 0x6c2363: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L006c2368: { // 0x6c2368: 8a442411 MOV AL,byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L006c236c: { // 0x6c236c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c236e: { // 0x6c236e: 7412 JZ 0x006c2382
    if(integer::condition("JZ",flags)) goto L006c2382;
  }
  L006c2370: { // 0x6c2370: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L006c2374: { // 0x6c2374: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2376: { // 0x6c2376: 740a JZ 0x006c2382
    if(integer::condition("JZ",flags)) goto L006c2382;
  }
  L006c2378: { // 0x6c2378: c644241100 MOV byte ptr [ESP + 0x11],0x0
    m.w8((f.sp+0x00000011u), 0x00000000u);
  }
  L006c237d: { // 0x6c237d: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L006c2382: { // 0x6c2382: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c2384: { // 0x6c2384: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2386: { // 0x6c2386: c7442418ffffffff MOV dword ptr [ESP + 0x18],0xffffffff
    m.w32((f.sp+0x00000018u), 0xffffffffu);
  }
  L006c238e: { // 0x6c238e: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L006c2393: { // 0x6c2393: ff92bc010000 CALL dword ptr [EDX + 0x1bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001bcu)),7087001u); flags=s.arithmetic_flags;
  }
  L006c2399: { // 0x6c2399: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c239b: { // 0x6c239b: 0f858e040000 JNZ 0x006c282f
    if(integer::condition("JNZ",flags)) goto L006c282f;
  }
  L006c23a1: { // 0x6c23a1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c23a3: { // 0x6c23a3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c23a5: { // 0x6c23a5: ff90c0010000 CALL dword ptr [EAX + 0x1c0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001c0u)),7087019u); flags=s.arithmetic_flags;
  }
  L006c23ab: { // 0x6c23ab: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c23ad: { // 0x6c23ad: 0f857c040000 JNZ 0x006c282f
    if(integer::condition("JNZ",flags)) goto L006c282f;
  }
  L006c23b3: { // 0x6c23b3: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006c23b9: { // 0x6c23b9: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006c23bb: { // 0x6c23bb: f6c410 TEST AH,0x10
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  L006c23be: { // 0x6c23be: 0f849e000000 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c23c4: { // 0x6c23c4: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L006c23c8: { // 0x6c23c8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c23ca: { // 0x6c23ca: 0f8492000000 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c23d0: { // 0x6c23d0: 8b4528 MOV EAX,dword ptr [EBP + 0x28]
    s.ax = m.r32((s.bp+0x00000028u));
  }
  L006c23d3: { // 0x6c23d3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c23d5: { // 0x6c23d5: 0f8487000000 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c23db: { // 0x6c23db: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L006c23de: { // 0x6c23de: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006c23e0: { // 0x6c23e0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c23e2: { // 0x6c23e2: 7e7e JLE 0x006c2462
    if(integer::condition("JLE",flags)) goto L006c2462;
  }
  L006c23e4: { // 0x6c23e4: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006c23e7: { // 0x6c23e7: 8b3c9a MOV EDI,dword ptr [EDX + EBX*0x4]
    s.di = m.r32((s.dx+(s.bx * 0x00000004u)));
  }
  L006c23ea: { // 0x6c23ea: 8a4774 MOV AL,byte ptr [EDI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000074u)));
  }
  L006c23ed: { // 0x6c23ed: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c23ef: { // 0x6c23ef: 744e JZ 0x006c243f
    if(integer::condition("JZ",flags)) goto L006c243f;
  }
  L006c23f1: { // 0x6c23f1: 8b4730 MOV EAX,dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  L006c23f4: { // 0x6c23f4: 83f814 CMP EAX,0x14
    (void)integer::sub(s.ax,0x00000014u,32,flags);
  }
  L006c23f7: { // 0x6c23f7: 7509 JNZ 0x006c2402
    if(integer::condition("JNZ",flags)) goto L006c2402;
  }
  L006c23f9: { // 0x6c23f9: 8b4724 MOV EAX,dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  L006c23fc: { // 0x6c23fc: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006c2400: { // 0x6c2400: eb3d JMP 0x006c243f
    goto L006c243f;
  }
  L006c2402: { // 0x6c2402: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006c2405: { // 0x6c2405: 7538 JNZ 0x006c243f
    if(integer::condition("JNZ",flags)) goto L006c243f;
  }
  L006c2407: { // 0x6c2407: 8b4728 MOV EAX,dword ptr [EDI + 0x28]
    s.ax = m.r32((s.di+0x00000028u));
  }
  L006c240a: { // 0x6c240a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c240c: { // 0x6c240c: 7410 JZ 0x006c241e
    if(integer::condition("JZ",flags)) goto L006c241e;
  }
  L006c240e: { // 0x6c240e: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006c2414: { // 0x6c2414: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2415: { // 0x6c2415: e8c627e2ff CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,7087130u); flags=s.arithmetic_flags;
  }
  L006c241a: { // 0x6c241a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c241c: { // 0x6c241c: 7521 JNZ 0x006c243f
    if(integer::condition("JNZ",flags)) goto L006c243f;
  }
  L006c241e: { // 0x6c241e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c2420: { // 0x6c2420: e87bf8dfff CALL 0x004c1ca0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004c1ca0u,7087141u); flags=s.arithmetic_flags;
  }
  L006c2425: { // 0x6c2425: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2427: { // 0x6c2427: 7411 JZ 0x006c243a
    if(integer::condition("JZ",flags)) goto L006c243a;
  }
  L006c2429: { // 0x6c2429: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c242b: { // 0x6c242b: e870f8dfff CALL 0x004c1ca0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004c1ca0u,7087152u); flags=s.arithmetic_flags;
  }
  L006c2430: { // 0x6c2430: 8a8801020000 MOV CL,byte ptr [EAX + 0x201]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000201u)));
  }
  L006c2436: { // 0x6c2436: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c2438: { // 0x6c2438: 7405 JZ 0x006c243f
    if(integer::condition("JZ",flags)) goto L006c243f;
  }
  L006c243a: { // 0x6c243a: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L006c243f: { // 0x6c243f: 8b4528 MOV EAX,dword ptr [EBP + 0x28]
    s.ax = m.r32((s.bp+0x00000028u));
  }
  L006c2442: { // 0x6c2442: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006c2443: { // 0x6c2443: 3b5810 CMP EBX,dword ptr [EAX + 0x10]
    (void)integer::sub(s.bx,m.r32((s.ax+0x00000010u)),32,flags);
  }
  L006c2446: { // 0x6c2446: 7c9c JL 0x006c23e4
    if(integer::condition("JL",flags)) goto L006c23e4;
  }
  L006c2448: { // 0x6c2448: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006c244c: { // 0x6c244c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006c244f: { // 0x6c244f: 7411 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c2451: { // 0x6c2451: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L006c2457: { // 0x6c2457: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006c2459: { // 0x6c2459: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L006c245c: { // 0x6c245c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006c2460: { // 0x6c2460: eb15 JMP 0x006c2477
    goto L006c2477;
  }
  L006c2462: { // 0x6c2462: 8b4544 MOV EAX,dword ptr [EBP + 0x44]
    s.ax = m.r32((s.bp+0x00000044u));
  }
  L006c2465: { // 0x6c2465: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006c2468: { // 0x6c2468: 740d JZ 0x006c2477
    if(integer::condition("JZ",flags)) goto L006c2477;
  }
  L006c246a: { // 0x6c246a: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L006c2470: { // 0x6c2470: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006c2473: { // 0x6c2473: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006c2477: { // 0x6c2477: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c2479: { // 0x6c2479: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c247b: { // 0x6c247b: ff9004030000 CALL dword ptr [EAX + 0x304]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000304u)),7087233u); flags=s.arithmetic_flags;
  }
  L006c2481: { // 0x6c2481: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c2487: { // 0x6c2487: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L006c2489: { // 0x6c2489: e82223e3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7087246u); flags=s.arithmetic_flags;
  }
  L006c248e: { // 0x6c248e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2490: { // 0x6c2490: 7476 JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c2492: { // 0x6c2492: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L006c2496: { // 0x6c2496: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2498: { // 0x6c2498: 7408 JZ 0x006c24a2
    if(integer::condition("JZ",flags)) goto L006c24a2;
  }
  L006c249a: { // 0x6c249a: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L006c249e: { // 0x6c249e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24a0: { // 0x6c24a0: 750a JNZ 0x006c24ac
    if(integer::condition("JNZ",flags)) goto L006c24ac;
  }
  L006c24a2: { // 0x6c24a2: 8a8688030000 MOV AL,byte ptr [ESI + 0x388]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000388u)));
  }
  L006c24a8: { // 0x6c24a8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24aa: { // 0x6c24aa: 745c JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c24ac: { // 0x6c24ac: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c24ae: { // 0x6c24ae: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c24b0: { // 0x6c24b0: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087286u); flags=s.arithmetic_flags;
  }
  L006c24b6: { // 0x6c24b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24b8: { // 0x6c24b8: 744e JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c24ba: { // 0x6c24ba: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c24bc: { // 0x6c24bc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c24be: { // 0x6c24be: ff9098000000 CALL dword ptr [EAX + 0x98]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000098u)),7087300u); flags=s.arithmetic_flags;
  }
  L006c24c4: { // 0x6c24c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24c6: { // 0x6c24c6: 7504 JNZ 0x006c24cc
    if(integer::condition("JNZ",flags)) goto L006c24cc;
  }
  L006c24c8: { // 0x6c24c8: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c24ca: { // 0x6c24ca: 743c JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c24cc: { // 0x6c24cc: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L006c24d0: { // 0x6c24d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c24d1: { // 0x6c24d1: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006c24d7: { // 0x6c24d7: e824a2e2ff CALL 0x004ec700
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ec700u,7087324u); flags=s.arithmetic_flags;
  }
  L006c24dc: { // 0x6c24dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c24de: { // 0x6c24de: 7519 JNZ 0x006c24f9
    if(integer::condition("JNZ",flags)) goto L006c24f9;
  }
  L006c24e0: { // 0x6c24e0: 8a8688030000 MOV AL,byte ptr [ESI + 0x388]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000388u)));
  }
  L006c24e6: { // 0x6c24e6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24e8: { // 0x6c24e8: 750f JNZ 0x006c24f9
    if(integer::condition("JNZ",flags)) goto L006c24f9;
  }
  L006c24ea: { // 0x6c24ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c24eb: { // 0x6c24eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c24ec: { // 0x6c24ec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c24ed: { // 0x6c24ed: b81a000000 MOV EAX,0x1a
    s.ax = 0x0000001au;
  }
  L006c24f2: { // 0x6c24f2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c24f3: { // 0x6c24f3: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c24f6: { // 0x6c24f6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006c24f9: { // 0x6c24f9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c24fa: { // 0x6c24fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c24fb: { // 0x6c24fb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c24fc: { // 0x6c24fc: b833000000 MOV EAX,0x33
    s.ax = 0x00000033u;
  }
  L006c2501: { // 0x6c2501: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2502: { // 0x6c2502: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2505: { // 0x6c2505: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006c2508: { // 0x6c2508: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c250e: { // 0x6c250e: e89d22e3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7087379u); flags=s.arithmetic_flags;
  }
  L006c2513: { // 0x6c2513: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2515: { // 0x6c2515: 0f84fe010000 JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c251b: { // 0x6c251b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c251d: { // 0x6c251d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c251f: { // 0x6c251f: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7087397u); flags=s.arithmetic_flags;
  }
  L006c2525: { // 0x6c2525: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2527: { // 0x6c2527: 0f84ec010000 JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c252d: { // 0x6c252d: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006c2530: { // 0x6c2530: 0f84e3010000 JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c2536: { // 0x6c2536: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L006c253a: { // 0x6c253a: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006c253c: { // 0x6c253c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c253d: { // 0x6c253d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c2542: { // 0x6c2542: e8b92fe8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7087431u); flags=s.arithmetic_flags;
  }
  L006c2547: { // 0x6c2547: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2548: { // 0x6c2548: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c254a: { // 0x6c254a: ff93b8020000 CALL dword ptr [EBX + 0x2b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x000002b8u)),7087440u); flags=s.arithmetic_flags;
  }
  L006c2550: { // 0x6c2550: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c2551: { // 0x6c2551: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c2556: { // 0x6c2556: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006c2558: { // 0x6c2558: e8a32fe8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7087453u); flags=s.arithmetic_flags;
  }
  L006c255d: { // 0x6c255d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006c255f: { // 0x6c255f: e8ac91dbff CALL 0x0047b710
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b710u,7087460u); flags=s.arithmetic_flags;
  }
  L006c2564: { // 0x6c2564: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L006c2566: { // 0x6c2566: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c2568: { // 0x6c2568: 741e JZ 0x006c2588
    if(integer::condition("JZ",flags)) goto L006c2588;
  }
  L006c256a: { // 0x6c256a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c256c: { // 0x6c256c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c256e: { // 0x6c256e: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7087476u); flags=s.arithmetic_flags;
  }
  L006c2574: { // 0x6c2574: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006c2576: { // 0x6c2576: 8b88ac000000 MOV ECX,dword ptr [EAX + 0xac]
    s.cx = m.r32((s.ax+0x000000acu));
  }
  L006c257c: { // 0x6c257c: 8a814b010000 MOV AL,byte ptr [ECX + 0x14b]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000014bu)));
  }
  L006c2582: { // 0x6c2582: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2584: { // 0x6c2584: 7402 JZ 0x006c2588
    if(integer::condition("JZ",flags)) goto L006c2588;
  }
  L006c2586: { // 0x6c2586: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006c2588: { // 0x6c2588: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L006c258c: { // 0x6c258c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c258e: { // 0x6c258e: 7522 JNZ 0x006c25b2
    if(integer::condition("JNZ",flags)) goto L006c25b2;
  }
  L006c2590: { // 0x6c2590: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006c2594: { // 0x6c2594: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2596: { // 0x6c2596: 740a JZ 0x006c25a2
    if(integer::condition("JZ",flags)) goto L006c25a2;
  }
  L006c2598: { // 0x6c2598: 8a8801020000 MOV CL,byte ptr [EAX + 0x201]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000201u)));
  }
  L006c259e: { // 0x6c259e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c25a0: { // 0x6c25a0: 7510 JNZ 0x006c25b2
    if(integer::condition("JNZ",flags)) goto L006c25b2;
  }
  L006c25a2: { // 0x6c25a2: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c25a4: { // 0x6c25a4: 750c JNZ 0x006c25b2
    if(integer::condition("JNZ",flags)) goto L006c25b2;
  }
  L006c25a6: { // 0x6c25a6: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L006c25aa: { // 0x6c25aa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c25ac: { // 0x6c25ac: 0f84f6000000 JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c25b2: { // 0x6c25b2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c25b4: { // 0x6c25b4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c25b6: { // 0x6c25b6: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7087548u); flags=s.arithmetic_flags;
  }
  L006c25bc: { // 0x6c25bc: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006c25be: { // 0x6c25be: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006c25c2: { // 0x6c25c2: 8bb8ac000000 MOV EDI,dword ptr [EAX + 0xac]
    s.di = m.r32((s.ax+0x000000acu));
  }
  L006c25c8: { // 0x6c25c8: 8b4150 MOV EAX,dword ptr [ECX + 0x50]
    s.ax = m.r32((s.cx+0x00000050u));
  }
  L006c25cb: { // 0x6c25cb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006c25ce: { // 0x6c25ce: 741c JZ 0x006c25ec
    if(integer::condition("JZ",flags)) goto L006c25ec;
  }
  L006c25d0: { // 0x6c25d0: 8b0dcca5a100 MOV ECX,dword ptr [0x00a1a5cc]
    s.cx = m.r32((0x00a1a5ccu));
  }
  L006c25d6: { // 0x6c25d6: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L006c25dc: { // 0x6c25dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c25dd: { // 0x6c25dd: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006c25e0: { // 0x6c25e0: e8fb25e2ff CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,7087589u); flags=s.arithmetic_flags;
  }
  L006c25e5: { // 0x6c25e5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c25e7: { // 0x6c25e7: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006c25ea: { // 0x6c25ea: eb02 JMP 0x006c25ee
    goto L006c25ee;
  }
  L006c25ec: { // 0x6c25ec: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006c25ee: { // 0x6c25ee: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L006c25f2: { // 0x6c25f2: e829270400 CALL 0x00704d20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00704d20u,7087607u); flags=s.arithmetic_flags;
  }
  L006c25f7: { // 0x6c25f7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c25f9: { // 0x6c25f9: 7415 JZ 0x006c2610
    if(integer::condition("JZ",flags)) goto L006c2610;
  }
  L006c25fb: { // 0x6c25fb: 8a88e8000000 MOV CL,byte ptr [EAX + 0xe8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000000e8u)));
  }
  L006c2601: { // 0x6c2601: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c2603: { // 0x6c2603: 750b JNZ 0x006c2610
    if(integer::condition("JNZ",flags)) goto L006c2610;
  }
  L006c2605: { // 0x6c2605: 8b486c MOV ECX,dword ptr [EAX + 0x6c]
    s.cx = m.r32((s.ax+0x0000006cu));
  }
  L006c2608: { // 0x6c2608: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c260a: { // 0x6c260a: 7e04 JLE 0x006c2610
    if(integer::condition("JLE",flags)) goto L006c2610;
  }
  L006c260c: { // 0x6c260c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006c260e: { // 0x6c260e: eb02 JMP 0x006c2612
    goto L006c2612;
  }
  L006c2610: { // 0x6c2610: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c2612: { // 0x6c2612: 8a4c2438 MOV CL,byte ptr [ESP + 0x38]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000038u)));
  }
  L006c2616: { // 0x6c2616: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c2618: { // 0x6c2618: 753b JNZ 0x006c2655
    if(integer::condition("JNZ",flags)) goto L006c2655;
  }
  L006c261a: { // 0x6c261a: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006c261e: { // 0x6c261e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c2620: { // 0x6c2620: 7433 JZ 0x006c2655
    if(integer::condition("JZ",flags)) goto L006c2655;
  }
  L006c2622: { // 0x6c2622: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2624: { // 0x6c2624: 752f JNZ 0x006c2655
    if(integer::condition("JNZ",flags)) goto L006c2655;
  }
  L006c2626: { // 0x6c2626: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c2628: { // 0x6c2628: 747e JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c262a: { // 0x6c262a: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006c262c: { // 0x6c262c: 8a8278020000 MOV AL,byte ptr [EDX + 0x278]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000278u)));
  }
  L006c2632: { // 0x6c2632: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2634: { // 0x6c2634: 7472 JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c2636: { // 0x6c2636: 8a8744010000 MOV AL,byte ptr [EDI + 0x144]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000144u)));
  }
  L006c263c: { // 0x6c263c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c263e: { // 0x6c263e: 7515 JNZ 0x006c2655
    if(integer::condition("JNZ",flags)) goto L006c2655;
  }
  L006c2640: { // 0x6c2640: 8a8746010000 MOV AL,byte ptr [EDI + 0x146]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000146u)));
  }
  L006c2646: { // 0x6c2646: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2648: { // 0x6c2648: 745e JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c264a: { // 0x6c264a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006c264c: { // 0x6c264c: 83b89c00000006 CMP dword ptr [EAX + 0x9c],0x6
    (void)integer::sub(m.r32((s.ax+0x0000009cu)),0x00000006u,32,flags);
  }
  L006c2653: { // 0x6c2653: 7553 JNZ 0x006c26a8
    if(integer::condition("JNZ",flags)) goto L006c26a8;
  }
  L006c2655: { // 0x6c2655: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c2657: { // 0x6c2657: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2659: { // 0x6c2659: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087711u); flags=s.arithmetic_flags;
  }
  L006c265f: { // 0x6c265f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2661: { // 0x6c2661: 0f85a3000000 JNZ 0x006c270a
    if(integer::condition("JNZ",flags)) goto L006c270a;
  }
  L006c2667: { // 0x6c2667: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L006c266b: { // 0x6c266b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c266c: { // 0x6c266c: c744242c00000000 MOV dword ptr [ESP + 0x2c],0x0
    m.w32((f.sp+0x0000002cu), 0x00000000u);
  }
  L006c2674: { // 0x6c2674: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L006c2677: { // 0x6c2677: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L006c267b: { // 0x6c267b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c267d: { // 0x6c267d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c2680: { // 0x6c2680: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006c2686: { // 0x6c2686: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006c268a: { // 0x6c268a: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006c268e: { // 0x6c268e: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c2691: { // 0x6c2691: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L006c2697: { // 0x6c2697: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c2698: { // 0x6c2698: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c269a: { // 0x6c269a: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L006c269e: { // 0x6c269e: ff9050010000 CALL dword ptr [EAX + 0x150]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000150u)),7087780u); flags=s.arithmetic_flags;
  }
  L006c26a4: { // 0x6c26a4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c26a6: { // 0x6c26a6: 7562 JNZ 0x006c270a
    if(integer::condition("JNZ",flags)) goto L006c270a;
  }
  L006c26a8: { // 0x6c26a8: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006c26ac: { // 0x6c26ac: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c26ae: { // 0x6c26ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c26af: { // 0x6c26af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c26b1: { // 0x6c26b1: ff9240030000 CALL dword ptr [EDX + 0x340]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000340u)),7087799u); flags=s.arithmetic_flags;
  }
  L006c26b7: { // 0x6c26b7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c26b9: { // 0x6c26b9: 745e JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c26bb: { // 0x6c26bb: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c26bd: { // 0x6c26bd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c26bf: { // 0x6c26bf: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087813u); flags=s.arithmetic_flags;
  }
  L006c26c5: { // 0x6c26c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c26c7: { // 0x6c26c7: 7541 JNZ 0x006c270a
    if(integer::condition("JNZ",flags)) goto L006c270a;
  }
  L006c26c9: { // 0x6c26c9: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L006c26cd: { // 0x6c26cd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c26ce: { // 0x6c26ce: c744242c00000000 MOV dword ptr [ESP + 0x2c],0x0
    m.w32((f.sp+0x0000002cu), 0x00000000u);
  }
  L006c26d6: { // 0x6c26d6: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L006c26d9: { // 0x6c26d9: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L006c26dd: { // 0x6c26dd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c26df: { // 0x6c26df: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c26e2: { // 0x6c26e2: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006c26e8: { // 0x6c26e8: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006c26ec: { // 0x6c26ec: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006c26f0: { // 0x6c26f0: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c26f3: { // 0x6c26f3: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L006c26f9: { // 0x6c26f9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c26fa: { // 0x6c26fa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c26fc: { // 0x6c26fc: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L006c2700: { // 0x6c2700: ff9050010000 CALL dword ptr [EAX + 0x150]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000150u)),7087878u); flags=s.arithmetic_flags;
  }
  L006c2706: { // 0x6c2706: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2708: { // 0x6c2708: 740f JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c270a: { // 0x6c270a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c270b: { // 0x6c270b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c270c: { // 0x6c270c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c270d: { // 0x6c270d: b805000000 MOV EAX,0x5
    s.ax = 0x00000005u;
  }
  L006c2712: { // 0x6c2712: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2713: { // 0x6c2713: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2716: { // 0x6c2716: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006c2719: { // 0x6c2719: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c271f: { // 0x6c271f: e88c20e3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7087908u); flags=s.arithmetic_flags;
  }
  L006c2724: { // 0x6c2724: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2726: { // 0x6c2726: 0f8403010000 JZ 0x006c282f
    if(integer::condition("JZ",flags)) goto L006c282f;
  }
  L006c272c: { // 0x6c272c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c272e: { // 0x6c272e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2730: { // 0x6c2730: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087926u); flags=s.arithmetic_flags;
  }
  L006c2736: { // 0x6c2736: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2738: { // 0x6c2738: 7512 JNZ 0x006c274c
    if(integer::condition("JNZ",flags)) goto L006c274c;
  }
  L006c273a: { // 0x6c273a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c273c: { // 0x6c273c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c273e: { // 0x6c273e: ff9064020000 CALL dword ptr [EAX + 0x264]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000264u)),7087940u); flags=s.arithmetic_flags;
  }
  L006c2744: { // 0x6c2744: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2746: { // 0x6c2746: 0f84e3000000 JZ 0x006c282f
    if(integer::condition("JZ",flags)) goto L006c282f;
  }
  L006c274c: { // 0x6c274c: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L006c2750: { // 0x6c2750: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006c2752: { // 0x6c2752: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c2753: { // 0x6c2753: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c2758: { // 0x6c2758: e8f34ce9ff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,7087965u); flags=s.arithmetic_flags;
  }
  L006c275d: { // 0x6c275d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c275f: { // 0x6c275f: 0f84bb000000 JZ 0x006c2820
    if(integer::condition("JZ",flags)) goto L006c2820;
  }
  L006c2765: { // 0x6c2765: 8a442411 MOV AL,byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L006c2769: { // 0x6c2769: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c276b: { // 0x6c276b: 740f JZ 0x006c277c
    if(integer::condition("JZ",flags)) goto L006c277c;
  }
  L006c276d: { // 0x6c276d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c276e: { // 0x6c276e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c276f: { // 0x6c276f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2770: { // 0x6c2770: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006c2775: { // 0x6c2775: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2776: { // 0x6c2776: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2779: { // 0x6c2779: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006c277c: { // 0x6c277c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c277e: { // 0x6c277e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2780: { // 0x6c2780: ff9264020000 CALL dword ptr [EDX + 0x264]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000264u)),7088006u); flags=s.arithmetic_flags;
  }
  L006c2786: { // 0x6c2786: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2788: { // 0x6c2788: 7417 JZ 0x006c27a1
    if(integer::condition("JZ",flags)) goto L006c27a1;
  }
  L006c278a: { // 0x6c278a: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L006c278e: { // 0x6c278e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2790: { // 0x6c2790: 740f JZ 0x006c27a1
    if(integer::condition("JZ",flags)) goto L006c27a1;
  }
  L006c2792: { // 0x6c2792: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2793: { // 0x6c2793: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2794: { // 0x6c2794: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2795: { // 0x6c2795: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006c279a: { // 0x6c279a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c279b: { // 0x6c279b: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c279e: { // 0x6c279e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006c27a1: { // 0x6c27a1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c27a3: { // 0x6c27a3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c27a5: { // 0x6c27a5: ff909c000000 CALL dword ptr [EAX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000009cu)),7088043u); flags=s.arithmetic_flags;
  }
  L006c27ab: { // 0x6c27ab: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c27ad: { // 0x6c27ad: 7471 JZ 0x006c2820
    if(integer::condition("JZ",flags)) goto L006c2820;
  }
  L006c27af: { // 0x6c27af: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006c27b1: { // 0x6c27b1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006c27b3: { // 0x6c27b3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c27b5: { // 0x6c27b5: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27b7: { // 0x6c27b7: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27b9: { // 0x6c27b9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c27ba: { // 0x6c27ba: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c27bf: { // 0x6c27bf: e83c2de8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7088068u); flags=s.arithmetic_flags;
  }
  L006c27c4: { // 0x6c27c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c27c5: { // 0x6c27c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c27c7: { // 0x6c27c7: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),7088077u); flags=s.arithmetic_flags;
  }
  L006c27cd: { // 0x6c27cd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006c27d0: { // 0x6c27d0: 7e3f JLE 0x006c2811
    if(integer::condition("JLE",flags)) goto L006c2811;
  }
  L006c27d2: { // 0x6c27d2: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L006c27d6: { // 0x6c27d6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c27d8: { // 0x6c27d8: 7537 JNZ 0x006c2811
    if(integer::condition("JNZ",flags)) goto L006c2811;
  }
  L006c27da: { // 0x6c27da: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c27dc: { // 0x6c27dc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c27de: { // 0x6c27de: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7088100u); flags=s.arithmetic_flags;
  }
  L006c27e4: { // 0x6c27e4: 8a88f50a0000 MOV CL,byte ptr [EAX + 0xaf5]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af5u)));
  }
  L006c27ea: { // 0x6c27ea: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c27ec: { // 0x6c27ec: 7432 JZ 0x006c2820
    if(integer::condition("JZ",flags)) goto L006c2820;
  }
  L006c27ee: { // 0x6c27ee: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006c27f0: { // 0x6c27f0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c27f2: { // 0x6c27f2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c27f4: { // 0x6c27f4: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27f6: { // 0x6c27f6: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27f8: { // 0x6c27f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c27f9: { // 0x6c27f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c27fe: { // 0x6c27fe: e8fd2ce8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7088131u); flags=s.arithmetic_flags;
  }
  L006c2803: { // 0x6c2803: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2804: { // 0x6c2804: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2806: { // 0x6c2806: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),7088140u); flags=s.arithmetic_flags;
  }
  L006c280c: { // 0x6c280c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006c280f: { // 0x6c280f: 7f0f JG 0x006c2820
    if(integer::condition("JG",flags)) goto L006c2820;
  }
  L006c2811: { // 0x6c2811: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2812: { // 0x6c2812: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2813: { // 0x6c2813: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2814: { // 0x6c2814: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006c2819: { // 0x6c2819: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c281a: { // 0x6c281a: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c281d: { // 0x6c281d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006c2820: { // 0x6c2820: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2821: { // 0x6c2821: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2822: { // 0x6c2822: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2823: { // 0x6c2823: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L006c2828: { // 0x6c2828: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2829: { // 0x6c2829: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c282c: { // 0x6c282c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006c282f: { // 0x6c282f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2830: { // 0x6c2830: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2831: { // 0x6c2831: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2832: { // 0x6c2832: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c2834: { // 0x6c2834: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2835: { // 0x6c2835: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2838: { // 0x6c2838: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x6c2290u:f_002c2290(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5162752u:f_000ec700(m,s,child,{});break;
case 7127904u:f_002cc360(m,s,child,{});break;
case 7127920u:f_002cc370(m,s,child,{});break;
case 4305792u:f_0001b380(m,s,child,{});break;
case 5195696u:f_000f47b0(m,s,child,{});break;
case 4498976u:f_0004a620(m,s,child,{});break;
case 7089056u:f_002c2ba0(m,s,child,{});break;
case 7136240u:f_002ce3f0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7133968u:f_002cdb10(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
case 5656368u:f_00164f30(m,s,child,{});break;
default:throw std::domain_error("recovery691 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004cc250(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cc250: { // 0x4cc250: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004cc253: { // 0x4cc253: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004cc257: { // 0x4cc257: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004cc258: { // 0x4cc258: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004cc259: { // 0x4cc259: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L004cc25d: { // 0x4cc25d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004cc25e: { // 0x4cc25e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004cc260: { // 0x4cc260: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004cc264: { // 0x4cc264: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004cc265: { // 0x4cc265: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004cc266: { // 0x4cc266: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004cc267: { // 0x4cc267: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004cc269: { // 0x4cc269: e822601f00 CALL 0x006c2290
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c2290u,5030510u); flags=s.arithmetic_flags;
  }
  L004cc26e: { // 0x4cc26e: 0fbf16 MOVSX EDX,word ptr [ESI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L004cc271: { // 0x4cc271: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004cc273: { // 0x4cc273: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L004cc277: { // 0x4cc277: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L004cc27b: { // 0x4cc27b: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L004cc27e: { // 0x4cc27e: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L004cc281: { // 0x4cc281: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L004cc287: { // 0x4cc287: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L004cc28c: { // 0x4cc28c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004cc28d: { // 0x4cc28d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004cc292: { // 0x4cc292: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004cc296: { // 0x4cc296: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004cc29a: { // 0x4cc29a: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L004cc2a2: { // 0x4cc2a2: e8c9ad0800 CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,5030567u); flags=s.arithmetic_flags;
  }
  L004cc2a7: { // 0x4cc2a7: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L004cc2ab: { // 0x4cc2ab: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004cc2b0: { // 0x4cc2b0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004cc2b1: { // 0x4cc2b1: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004cc2b5: { // 0x4cc2b5: e8d6910700 CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5030586u); flags=s.arithmetic_flags;
  }
  L004cc2ba: { // 0x4cc2ba: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L004cc2c0: { // 0x4cc2c0: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004cc2c3: { // 0x4cc2c3: 740f JZ 0x004cc2d4
    if(integer::condition("JZ",flags)) goto L004cc2d4;
  }
  L004cc2c5: { // 0x4cc2c5: a190e28400 MOV EAX,[0x0084e290]
    s.ax = m.r32((0x0084e290u));
  }
  L004cc2ca: { // 0x4cc2ca: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004cc2ce: { // 0x4cc2ce: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004cc2d0: { // 0x4cc2d0: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004cc2d4: { // 0x4cc2d4: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L004cc2d8: { // 0x4cc2d8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004cc2d9: { // 0x4cc2d9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004cc2de: { // 0x4cc2de: e84d8c0900 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5030627u); flags=s.arithmetic_flags;
  }
  L004cc2e3: { // 0x4cc2e3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004cc2e5: { // 0x4cc2e5: 744a JZ 0x004cc331
    if(integer::condition("JZ",flags)) goto L004cc331;
  }
  L004cc2e7: { // 0x4cc2e7: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004cc2e9: { // 0x4cc2e9: 7446 JZ 0x004cc331
    if(integer::condition("JZ",flags)) goto L004cc331;
  }
  L004cc2eb: { // 0x4cc2eb: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004cc2ed: { // 0x4cc2ed: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004cc2ef: { // 0x4cc2ef: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),5030645u); flags=s.arithmetic_flags;
  }
  L004cc2f5: { // 0x4cc2f5: 8a88990a0000 MOV CL,byte ptr [EAX + 0xa99]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000a99u)));
  }
  L004cc2fb: { // 0x4cc2fb: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004cc2fd: { // 0x4cc2fd: 7424 JZ 0x004cc323
    if(integer::condition("JZ",flags)) goto L004cc323;
  }
  L004cc2ff: { // 0x4cc2ff: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004cc301: { // 0x4cc301: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004cc302: { // 0x4cc302: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004cc307: { // 0x4cc307: e844b10800 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5030668u); flags=s.arithmetic_flags;
  }
  L004cc30c: { // 0x4cc30c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004cc30e: { // 0x4cc30e: 7413 JZ 0x004cc323
    if(integer::condition("JZ",flags)) goto L004cc323;
  }
  L004cc310: { // 0x4cc310: 83fb33 CMP EBX,0x33
    (void)integer::sub(s.bx,0x00000033u,32,flags);
  }
  L004cc313: { // 0x4cc313: 741c JZ 0x004cc331
    if(integer::condition("JZ",flags)) goto L004cc331;
  }
  L004cc315: { // 0x4cc315: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004cc316: { // 0x4cc316: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cc317: { // 0x4cc317: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004cc31c: { // 0x4cc31c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004cc31d: { // 0x4cc31d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004cc320: { // 0x4cc320: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004cc323: { // 0x4cc323: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004cc324: { // 0x4cc324: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cc325: { // 0x4cc325: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L004cc32a: { // 0x4cc32a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004cc32b: { // 0x4cc32b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004cc32e: { // 0x4cc32e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004cc331: { // 0x4cc331: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004cc332: { // 0x4cc332: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004cc334: { // 0x4cc334: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cc335: { // 0x4cc335: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004cc336: { // 0x4cc336: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004cc339: { // 0x4cc339: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006c2290(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c2290: { // 0x6c2290: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L006c2293: { // 0x6c2293: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006c2297: { // 0x6c2297: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c2298: { // 0x6c2298: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c2299: { // 0x6c2299: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c229a: { // 0x6c229a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c229c: { // 0x6c229c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c229d: { // 0x6c229d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c229e: { // 0x6c229e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c22a3: { // 0x6c22a3: e85832e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7086760u); flags=s.arithmetic_flags;
  }
  L006c22a8: { // 0x6c22a8: 8a5c2438 MOV BL,byte ptr [ESP + 0x38]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000038u)));
  }
  L006c22ac: { // 0x6c22ac: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006c22ae: { // 0x6c22ae: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c22b0: { // 0x6c22b0: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L006c22b4: { // 0x6c22b4: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L006c22bc: { // 0x6c22bc: 7531 JNZ 0x006c22ef
    if(integer::condition("JNZ",flags)) goto L006c22ef;
  }
  L006c22be: { // 0x6c22be: a1ec87a200 MOV EAX,[0x00a287ec]
    s.ax = m.r32((0x00a287ecu));
  }
  L006c22c3: { // 0x6c22c3: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c22c9: { // 0x6c22c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c22ca: { // 0x6c22ca: e821e8e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086799u); flags=s.arithmetic_flags;
  }
  L006c22cf: { // 0x6c22cf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c22d1: { // 0x6c22d1: 7515 JNZ 0x006c22e8
    if(integer::condition("JNZ",flags)) goto L006c22e8;
  }
  L006c22d3: { // 0x6c22d3: a1f087a200 MOV EAX,[0x00a287f0]
    s.ax = m.r32((0x00a287f0u));
  }
  L006c22d8: { // 0x6c22d8: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c22de: { // 0x6c22de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c22df: { // 0x6c22df: e80ce8e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086820u); flags=s.arithmetic_flags;
  }
  L006c22e4: { // 0x6c22e4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c22e6: { // 0x6c22e6: 7407 JZ 0x006c22ef
    if(integer::condition("JZ",flags)) goto L006c22ef;
  }
  L006c22e8: { // 0x6c22e8: c644243801 MOV byte ptr [ESP + 0x38],0x1
    m.w8((f.sp+0x00000038u), 0x00000001u);
  }
  L006c22ed: { // 0x6c22ed: eb09 JMP 0x006c22f8
    goto L006c22f8;
  }
  L006c22ef: { // 0x6c22ef: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c22f1: { // 0x6c22f1: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L006c22f6: { // 0x6c22f6: 7531 JNZ 0x006c2329
    if(integer::condition("JNZ",flags)) goto L006c2329;
  }
  L006c22f8: { // 0x6c22f8: a1f487a200 MOV EAX,[0x00a287f4]
    s.ax = m.r32((0x00a287f4u));
  }
  L006c22fd: { // 0x6c22fd: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c2303: { // 0x6c2303: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2304: { // 0x6c2304: e8e7e7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086857u); flags=s.arithmetic_flags;
  }
  L006c2309: { // 0x6c2309: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c230b: { // 0x6c230b: 7515 JNZ 0x006c2322
    if(integer::condition("JNZ",flags)) goto L006c2322;
  }
  L006c230d: { // 0x6c230d: a1f887a200 MOV EAX,[0x00a287f8]
    s.ax = m.r32((0x00a287f8u));
  }
  L006c2312: { // 0x6c2312: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c2318: { // 0x6c2318: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2319: { // 0x6c2319: e8d2e7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086878u); flags=s.arithmetic_flags;
  }
  L006c231e: { // 0x6c231e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2320: { // 0x6c2320: 7407 JZ 0x006c2329
    if(integer::condition("JZ",flags)) goto L006c2329;
  }
  L006c2322: { // 0x6c2322: c644241101 MOV byte ptr [ESP + 0x11],0x1
    m.w8((f.sp+0x00000011u), 0x00000001u);
  }
  L006c2327: { // 0x6c2327: eb09 JMP 0x006c2332
    goto L006c2332;
  }
  L006c2329: { // 0x6c2329: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c232b: { // 0x6c232b: c644241100 MOV byte ptr [ESP + 0x11],0x0
    m.w8((f.sp+0x00000011u), 0x00000000u);
  }
  L006c2330: { // 0x6c2330: 7531 JNZ 0x006c2363
    if(integer::condition("JNZ",flags)) goto L006c2363;
  }
  L006c2332: { // 0x6c2332: a1e487a200 MOV EAX,[0x00a287e4]
    s.ax = m.r32((0x00a287e4u));
  }
  L006c2337: { // 0x6c2337: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c233d: { // 0x6c233d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c233e: { // 0x6c233e: e8ade7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086915u); flags=s.arithmetic_flags;
  }
  L006c2343: { // 0x6c2343: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2345: { // 0x6c2345: 7515 JNZ 0x006c235c
    if(integer::condition("JNZ",flags)) goto L006c235c;
  }
  L006c2347: { // 0x6c2347: a1e887a200 MOV EAX,[0x00a287e8]
    s.ax = m.r32((0x00a287e8u));
  }
  L006c234c: { // 0x6c234c: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006c2352: { // 0x6c2352: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2353: { // 0x6c2353: e898e7e6ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7086936u); flags=s.arithmetic_flags;
  }
  L006c2358: { // 0x6c2358: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c235a: { // 0x6c235a: 7407 JZ 0x006c2363
    if(integer::condition("JZ",flags)) goto L006c2363;
  }
  L006c235c: { // 0x6c235c: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L006c2361: { // 0x6c2361: eb05 JMP 0x006c2368
    goto L006c2368;
  }
  L006c2363: { // 0x6c2363: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L006c2368: { // 0x6c2368: 8a442411 MOV AL,byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L006c236c: { // 0x6c236c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c236e: { // 0x6c236e: 7412 JZ 0x006c2382
    if(integer::condition("JZ",flags)) goto L006c2382;
  }
  L006c2370: { // 0x6c2370: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L006c2374: { // 0x6c2374: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2376: { // 0x6c2376: 740a JZ 0x006c2382
    if(integer::condition("JZ",flags)) goto L006c2382;
  }
  L006c2378: { // 0x6c2378: c644241100 MOV byte ptr [ESP + 0x11],0x0
    m.w8((f.sp+0x00000011u), 0x00000000u);
  }
  L006c237d: { // 0x6c237d: c644243800 MOV byte ptr [ESP + 0x38],0x0
    m.w8((f.sp+0x00000038u), 0x00000000u);
  }
  L006c2382: { // 0x6c2382: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c2384: { // 0x6c2384: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2386: { // 0x6c2386: c7442418ffffffff MOV dword ptr [ESP + 0x18],0xffffffff
    m.w32((f.sp+0x00000018u), 0xffffffffu);
  }
  L006c238e: { // 0x6c238e: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L006c2393: { // 0x6c2393: ff92bc010000 CALL dword ptr [EDX + 0x1bc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001bcu)),7087001u); flags=s.arithmetic_flags;
  }
  L006c2399: { // 0x6c2399: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c239b: { // 0x6c239b: 0f858e040000 JNZ 0x006c282f
    if(integer::condition("JNZ",flags)) goto L006c282f;
  }
  L006c23a1: { // 0x6c23a1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c23a3: { // 0x6c23a3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c23a5: { // 0x6c23a5: ff90c0010000 CALL dword ptr [EAX + 0x1c0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001c0u)),7087019u); flags=s.arithmetic_flags;
  }
  L006c23ab: { // 0x6c23ab: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c23ad: { // 0x6c23ad: 0f857c040000 JNZ 0x006c282f
    if(integer::condition("JNZ",flags)) goto L006c282f;
  }
  L006c23b3: { // 0x6c23b3: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006c23b9: { // 0x6c23b9: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006c23bb: { // 0x6c23bb: f6c410 TEST AH,0x10
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  L006c23be: { // 0x6c23be: 0f849e000000 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c23c4: { // 0x6c23c4: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L006c23c8: { // 0x6c23c8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c23ca: { // 0x6c23ca: 0f8492000000 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c23d0: { // 0x6c23d0: 8b4528 MOV EAX,dword ptr [EBP + 0x28]
    s.ax = m.r32((s.bp+0x00000028u));
  }
  L006c23d3: { // 0x6c23d3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c23d5: { // 0x6c23d5: 0f8487000000 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c23db: { // 0x6c23db: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L006c23de: { // 0x6c23de: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006c23e0: { // 0x6c23e0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c23e2: { // 0x6c23e2: 7e7e JLE 0x006c2462
    if(integer::condition("JLE",flags)) goto L006c2462;
  }
  L006c23e4: { // 0x6c23e4: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006c23e7: { // 0x6c23e7: 8b3c9a MOV EDI,dword ptr [EDX + EBX*0x4]
    s.di = m.r32((s.dx+(s.bx * 0x00000004u)));
  }
  L006c23ea: { // 0x6c23ea: 8a4774 MOV AL,byte ptr [EDI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000074u)));
  }
  L006c23ed: { // 0x6c23ed: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c23ef: { // 0x6c23ef: 744e JZ 0x006c243f
    if(integer::condition("JZ",flags)) goto L006c243f;
  }
  L006c23f1: { // 0x6c23f1: 8b4730 MOV EAX,dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  L006c23f4: { // 0x6c23f4: 83f814 CMP EAX,0x14
    (void)integer::sub(s.ax,0x00000014u,32,flags);
  }
  L006c23f7: { // 0x6c23f7: 7509 JNZ 0x006c2402
    if(integer::condition("JNZ",flags)) goto L006c2402;
  }
  L006c23f9: { // 0x6c23f9: 8b4724 MOV EAX,dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  L006c23fc: { // 0x6c23fc: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006c2400: { // 0x6c2400: eb3d JMP 0x006c243f
    goto L006c243f;
  }
  L006c2402: { // 0x6c2402: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006c2405: { // 0x6c2405: 7538 JNZ 0x006c243f
    if(integer::condition("JNZ",flags)) goto L006c243f;
  }
  L006c2407: { // 0x6c2407: 8b4728 MOV EAX,dword ptr [EDI + 0x28]
    s.ax = m.r32((s.di+0x00000028u));
  }
  L006c240a: { // 0x6c240a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c240c: { // 0x6c240c: 7410 JZ 0x006c241e
    if(integer::condition("JZ",flags)) goto L006c241e;
  }
  L006c240e: { // 0x6c240e: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006c2414: { // 0x6c2414: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2415: { // 0x6c2415: e8c627e2ff CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,7087130u); flags=s.arithmetic_flags;
  }
  L006c241a: { // 0x6c241a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c241c: { // 0x6c241c: 7521 JNZ 0x006c243f
    if(integer::condition("JNZ",flags)) goto L006c243f;
  }
  L006c241e: { // 0x6c241e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c2420: { // 0x6c2420: e87bf8dfff CALL 0x004c1ca0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004c1ca0u,7087141u); flags=s.arithmetic_flags;
  }
  L006c2425: { // 0x6c2425: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2427: { // 0x6c2427: 7411 JZ 0x006c243a
    if(integer::condition("JZ",flags)) goto L006c243a;
  }
  L006c2429: { // 0x6c2429: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c242b: { // 0x6c242b: e870f8dfff CALL 0x004c1ca0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004c1ca0u,7087152u); flags=s.arithmetic_flags;
  }
  L006c2430: { // 0x6c2430: 8a8801020000 MOV CL,byte ptr [EAX + 0x201]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000201u)));
  }
  L006c2436: { // 0x6c2436: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c2438: { // 0x6c2438: 7405 JZ 0x006c243f
    if(integer::condition("JZ",flags)) goto L006c243f;
  }
  L006c243a: { // 0x6c243a: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L006c243f: { // 0x6c243f: 8b4528 MOV EAX,dword ptr [EBP + 0x28]
    s.ax = m.r32((s.bp+0x00000028u));
  }
  L006c2442: { // 0x6c2442: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006c2443: { // 0x6c2443: 3b5810 CMP EBX,dword ptr [EAX + 0x10]
    (void)integer::sub(s.bx,m.r32((s.ax+0x00000010u)),32,flags);
  }
  L006c2446: { // 0x6c2446: 7c9c JL 0x006c23e4
    if(integer::condition("JL",flags)) goto L006c23e4;
  }
  L006c2448: { // 0x6c2448: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006c244c: { // 0x6c244c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006c244f: { // 0x6c244f: 7411 JZ 0x006c2462
    if(integer::condition("JZ",flags)) goto L006c2462;
  }
  L006c2451: { // 0x6c2451: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L006c2457: { // 0x6c2457: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006c2459: { // 0x6c2459: 8b0491 MOV EAX,dword ptr [ECX + EDX*0x4]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L006c245c: { // 0x6c245c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006c2460: { // 0x6c2460: eb15 JMP 0x006c2477
    goto L006c2477;
  }
  L006c2462: { // 0x6c2462: 8b4544 MOV EAX,dword ptr [EBP + 0x44]
    s.ax = m.r32((s.bp+0x00000044u));
  }
  L006c2465: { // 0x6c2465: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006c2468: { // 0x6c2468: 740d JZ 0x006c2477
    if(integer::condition("JZ",flags)) goto L006c2477;
  }
  L006c246a: { // 0x6c246a: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L006c2470: { // 0x6c2470: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006c2473: { // 0x6c2473: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006c2477: { // 0x6c2477: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c2479: { // 0x6c2479: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c247b: { // 0x6c247b: ff9004030000 CALL dword ptr [EAX + 0x304]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000304u)),7087233u); flags=s.arithmetic_flags;
  }
  L006c2481: { // 0x6c2481: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c2487: { // 0x6c2487: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L006c2489: { // 0x6c2489: e82223e3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7087246u); flags=s.arithmetic_flags;
  }
  L006c248e: { // 0x6c248e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2490: { // 0x6c2490: 7476 JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c2492: { // 0x6c2492: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L006c2496: { // 0x6c2496: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2498: { // 0x6c2498: 7408 JZ 0x006c24a2
    if(integer::condition("JZ",flags)) goto L006c24a2;
  }
  L006c249a: { // 0x6c249a: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L006c249e: { // 0x6c249e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24a0: { // 0x6c24a0: 750a JNZ 0x006c24ac
    if(integer::condition("JNZ",flags)) goto L006c24ac;
  }
  L006c24a2: { // 0x6c24a2: 8a8688030000 MOV AL,byte ptr [ESI + 0x388]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000388u)));
  }
  L006c24a8: { // 0x6c24a8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24aa: { // 0x6c24aa: 745c JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c24ac: { // 0x6c24ac: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c24ae: { // 0x6c24ae: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c24b0: { // 0x6c24b0: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087286u); flags=s.arithmetic_flags;
  }
  L006c24b6: { // 0x6c24b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24b8: { // 0x6c24b8: 744e JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c24ba: { // 0x6c24ba: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c24bc: { // 0x6c24bc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c24be: { // 0x6c24be: ff9098000000 CALL dword ptr [EAX + 0x98]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000098u)),7087300u); flags=s.arithmetic_flags;
  }
  L006c24c4: { // 0x6c24c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24c6: { // 0x6c24c6: 7504 JNZ 0x006c24cc
    if(integer::condition("JNZ",flags)) goto L006c24cc;
  }
  L006c24c8: { // 0x6c24c8: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c24ca: { // 0x6c24ca: 743c JZ 0x006c2508
    if(integer::condition("JZ",flags)) goto L006c2508;
  }
  L006c24cc: { // 0x6c24cc: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L006c24d0: { // 0x6c24d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c24d1: { // 0x6c24d1: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L006c24d7: { // 0x6c24d7: e824a2e2ff CALL 0x004ec700
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ec700u,7087324u); flags=s.arithmetic_flags;
  }
  L006c24dc: { // 0x6c24dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c24de: { // 0x6c24de: 7519 JNZ 0x006c24f9
    if(integer::condition("JNZ",flags)) goto L006c24f9;
  }
  L006c24e0: { // 0x6c24e0: 8a8688030000 MOV AL,byte ptr [ESI + 0x388]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000388u)));
  }
  L006c24e6: { // 0x6c24e6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c24e8: { // 0x6c24e8: 750f JNZ 0x006c24f9
    if(integer::condition("JNZ",flags)) goto L006c24f9;
  }
  L006c24ea: { // 0x6c24ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c24eb: { // 0x6c24eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c24ec: { // 0x6c24ec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c24ed: { // 0x6c24ed: b81a000000 MOV EAX,0x1a
    s.ax = 0x0000001au;
  }
  L006c24f2: { // 0x6c24f2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c24f3: { // 0x6c24f3: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c24f6: { // 0x6c24f6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c24f9: { // 0x6c24f9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c24fa: { // 0x6c24fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c24fb: { // 0x6c24fb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c24fc: { // 0x6c24fc: b833000000 MOV EAX,0x33
    s.ax = 0x00000033u;
  }
  L006c2501: { // 0x6c2501: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2502: { // 0x6c2502: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2505: { // 0x6c2505: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c2508: { // 0x6c2508: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c250e: { // 0x6c250e: e89d22e3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7087379u); flags=s.arithmetic_flags;
  }
  L006c2513: { // 0x6c2513: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2515: { // 0x6c2515: 0f84fe010000 JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c251b: { // 0x6c251b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c251d: { // 0x6c251d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c251f: { // 0x6c251f: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7087397u); flags=s.arithmetic_flags;
  }
  L006c2525: { // 0x6c2525: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2527: { // 0x6c2527: 0f84ec010000 JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c252d: { // 0x6c252d: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006c2530: { // 0x6c2530: 0f84e3010000 JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c2536: { // 0x6c2536: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L006c253a: { // 0x6c253a: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006c253c: { // 0x6c253c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c253d: { // 0x6c253d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c2542: { // 0x6c2542: e8b92fe8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7087431u); flags=s.arithmetic_flags;
  }
  L006c2547: { // 0x6c2547: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2548: { // 0x6c2548: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c254a: { // 0x6c254a: ff93b8020000 CALL dword ptr [EBX + 0x2b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x000002b8u)),7087440u); flags=s.arithmetic_flags;
  }
  L006c2550: { // 0x6c2550: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c2551: { // 0x6c2551: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c2556: { // 0x6c2556: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006c2558: { // 0x6c2558: e8a32fe8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7087453u); flags=s.arithmetic_flags;
  }
  L006c255d: { // 0x6c255d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006c255f: { // 0x6c255f: e8ac91dbff CALL 0x0047b710
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b710u,7087460u); flags=s.arithmetic_flags;
  }
  L006c2564: { // 0x6c2564: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L006c2566: { // 0x6c2566: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c2568: { // 0x6c2568: 741e JZ 0x006c2588
    if(integer::condition("JZ",flags)) goto L006c2588;
  }
  L006c256a: { // 0x6c256a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c256c: { // 0x6c256c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c256e: { // 0x6c256e: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7087476u); flags=s.arithmetic_flags;
  }
  L006c2574: { // 0x6c2574: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006c2576: { // 0x6c2576: 8b88ac000000 MOV ECX,dword ptr [EAX + 0xac]
    s.cx = m.r32((s.ax+0x000000acu));
  }
  L006c257c: { // 0x6c257c: 8a814b010000 MOV AL,byte ptr [ECX + 0x14b]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000014bu)));
  }
  L006c2582: { // 0x6c2582: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2584: { // 0x6c2584: 7402 JZ 0x006c2588
    if(integer::condition("JZ",flags)) goto L006c2588;
  }
  L006c2586: { // 0x6c2586: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006c2588: { // 0x6c2588: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L006c258c: { // 0x6c258c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c258e: { // 0x6c258e: 7522 JNZ 0x006c25b2
    if(integer::condition("JNZ",flags)) goto L006c25b2;
  }
  L006c2590: { // 0x6c2590: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006c2594: { // 0x6c2594: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2596: { // 0x6c2596: 740a JZ 0x006c25a2
    if(integer::condition("JZ",flags)) goto L006c25a2;
  }
  L006c2598: { // 0x6c2598: 8a8801020000 MOV CL,byte ptr [EAX + 0x201]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000201u)));
  }
  L006c259e: { // 0x6c259e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c25a0: { // 0x6c25a0: 7510 JNZ 0x006c25b2
    if(integer::condition("JNZ",flags)) goto L006c25b2;
  }
  L006c25a2: { // 0x6c25a2: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c25a4: { // 0x6c25a4: 750c JNZ 0x006c25b2
    if(integer::condition("JNZ",flags)) goto L006c25b2;
  }
  L006c25a6: { // 0x6c25a6: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L006c25aa: { // 0x6c25aa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c25ac: { // 0x6c25ac: 0f84f6000000 JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c25b2: { // 0x6c25b2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c25b4: { // 0x6c25b4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c25b6: { // 0x6c25b6: ff9298030000 CALL dword ptr [EDX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000398u)),7087548u); flags=s.arithmetic_flags;
  }
  L006c25bc: { // 0x6c25bc: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006c25be: { // 0x6c25be: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006c25c2: { // 0x6c25c2: 8bb8ac000000 MOV EDI,dword ptr [EAX + 0xac]
    s.di = m.r32((s.ax+0x000000acu));
  }
  L006c25c8: { // 0x6c25c8: 8b4150 MOV EAX,dword ptr [ECX + 0x50]
    s.ax = m.r32((s.cx+0x00000050u));
  }
  L006c25cb: { // 0x6c25cb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006c25ce: { // 0x6c25ce: 741c JZ 0x006c25ec
    if(integer::condition("JZ",flags)) goto L006c25ec;
  }
  L006c25d0: { // 0x6c25d0: 8b0dcca5a100 MOV ECX,dword ptr [0x00a1a5cc]
    s.cx = m.r32((0x00a1a5ccu));
  }
  L006c25d6: { // 0x6c25d6: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L006c25dc: { // 0x6c25dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c25dd: { // 0x6c25dd: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006c25e0: { // 0x6c25e0: e8fb25e2ff CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,7087589u); flags=s.arithmetic_flags;
  }
  L006c25e5: { // 0x6c25e5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c25e7: { // 0x6c25e7: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006c25ea: { // 0x6c25ea: eb02 JMP 0x006c25ee
    goto L006c25ee;
  }
  L006c25ec: { // 0x6c25ec: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006c25ee: { // 0x6c25ee: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L006c25f2: { // 0x6c25f2: e829270400 CALL 0x00704d20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00704d20u,7087607u); flags=s.arithmetic_flags;
  }
  L006c25f7: { // 0x6c25f7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c25f9: { // 0x6c25f9: 7415 JZ 0x006c2610
    if(integer::condition("JZ",flags)) goto L006c2610;
  }
  L006c25fb: { // 0x6c25fb: 8a88e8000000 MOV CL,byte ptr [EAX + 0xe8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000000e8u)));
  }
  L006c2601: { // 0x6c2601: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c2603: { // 0x6c2603: 750b JNZ 0x006c2610
    if(integer::condition("JNZ",flags)) goto L006c2610;
  }
  L006c2605: { // 0x6c2605: 8b486c MOV ECX,dword ptr [EAX + 0x6c]
    s.cx = m.r32((s.ax+0x0000006cu));
  }
  L006c2608: { // 0x6c2608: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c260a: { // 0x6c260a: 7e04 JLE 0x006c2610
    if(integer::condition("JLE",flags)) goto L006c2610;
  }
  L006c260c: { // 0x6c260c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006c260e: { // 0x6c260e: eb02 JMP 0x006c2612
    goto L006c2612;
  }
  L006c2610: { // 0x6c2610: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c2612: { // 0x6c2612: 8a4c2438 MOV CL,byte ptr [ESP + 0x38]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000038u)));
  }
  L006c2616: { // 0x6c2616: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c2618: { // 0x6c2618: 753b JNZ 0x006c2655
    if(integer::condition("JNZ",flags)) goto L006c2655;
  }
  L006c261a: { // 0x6c261a: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006c261e: { // 0x6c261e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c2620: { // 0x6c2620: 7433 JZ 0x006c2655
    if(integer::condition("JZ",flags)) goto L006c2655;
  }
  L006c2622: { // 0x6c2622: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2624: { // 0x6c2624: 752f JNZ 0x006c2655
    if(integer::condition("JNZ",flags)) goto L006c2655;
  }
  L006c2626: { // 0x6c2626: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c2628: { // 0x6c2628: 747e JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c262a: { // 0x6c262a: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006c262c: { // 0x6c262c: 8a8278020000 MOV AL,byte ptr [EDX + 0x278]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000278u)));
  }
  L006c2632: { // 0x6c2632: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2634: { // 0x6c2634: 7472 JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c2636: { // 0x6c2636: 8a8744010000 MOV AL,byte ptr [EDI + 0x144]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000144u)));
  }
  L006c263c: { // 0x6c263c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c263e: { // 0x6c263e: 7515 JNZ 0x006c2655
    if(integer::condition("JNZ",flags)) goto L006c2655;
  }
  L006c2640: { // 0x6c2640: 8a8746010000 MOV AL,byte ptr [EDI + 0x146]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000146u)));
  }
  L006c2646: { // 0x6c2646: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2648: { // 0x6c2648: 745e JZ 0x006c26a8
    if(integer::condition("JZ",flags)) goto L006c26a8;
  }
  L006c264a: { // 0x6c264a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006c264c: { // 0x6c264c: 83b89c00000006 CMP dword ptr [EAX + 0x9c],0x6
    (void)integer::sub(m.r32((s.ax+0x0000009cu)),0x00000006u,32,flags);
  }
  L006c2653: { // 0x6c2653: 7553 JNZ 0x006c26a8
    if(integer::condition("JNZ",flags)) goto L006c26a8;
  }
  L006c2655: { // 0x6c2655: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c2657: { // 0x6c2657: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2659: { // 0x6c2659: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087711u); flags=s.arithmetic_flags;
  }
  L006c265f: { // 0x6c265f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2661: { // 0x6c2661: 0f85a3000000 JNZ 0x006c270a
    if(integer::condition("JNZ",flags)) goto L006c270a;
  }
  L006c2667: { // 0x6c2667: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L006c266b: { // 0x6c266b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c266c: { // 0x6c266c: c744242c00000000 MOV dword ptr [ESP + 0x2c],0x0
    m.w32((f.sp+0x0000002cu), 0x00000000u);
  }
  L006c2674: { // 0x6c2674: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L006c2677: { // 0x6c2677: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L006c267b: { // 0x6c267b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c267d: { // 0x6c267d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c2680: { // 0x6c2680: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006c2686: { // 0x6c2686: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006c268a: { // 0x6c268a: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006c268e: { // 0x6c268e: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c2691: { // 0x6c2691: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L006c2697: { // 0x6c2697: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c2698: { // 0x6c2698: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c269a: { // 0x6c269a: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L006c269e: { // 0x6c269e: ff9050010000 CALL dword ptr [EAX + 0x150]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000150u)),7087780u); flags=s.arithmetic_flags;
  }
  L006c26a4: { // 0x6c26a4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c26a6: { // 0x6c26a6: 7562 JNZ 0x006c270a
    if(integer::condition("JNZ",flags)) goto L006c270a;
  }
  L006c26a8: { // 0x6c26a8: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006c26ac: { // 0x6c26ac: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c26ae: { // 0x6c26ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c26af: { // 0x6c26af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c26b1: { // 0x6c26b1: ff9240030000 CALL dword ptr [EDX + 0x340]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000340u)),7087799u); flags=s.arithmetic_flags;
  }
  L006c26b7: { // 0x6c26b7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c26b9: { // 0x6c26b9: 745e JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c26bb: { // 0x6c26bb: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c26bd: { // 0x6c26bd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c26bf: { // 0x6c26bf: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087813u); flags=s.arithmetic_flags;
  }
  L006c26c5: { // 0x6c26c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c26c7: { // 0x6c26c7: 7541 JNZ 0x006c270a
    if(integer::condition("JNZ",flags)) goto L006c270a;
  }
  L006c26c9: { // 0x6c26c9: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L006c26cd: { // 0x6c26cd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c26ce: { // 0x6c26ce: c744242c00000000 MOV dword ptr [ESP + 0x2c],0x0
    m.w32((f.sp+0x0000002cu), 0x00000000u);
  }
  L006c26d6: { // 0x6c26d6: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L006c26d9: { // 0x6c26d9: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L006c26dd: { // 0x6c26dd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c26df: { // 0x6c26df: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c26e2: { // 0x6c26e2: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006c26e8: { // 0x6c26e8: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006c26ec: { // 0x6c26ec: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006c26f0: { // 0x6c26f0: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006c26f3: { // 0x6c26f3: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L006c26f9: { // 0x6c26f9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c26fa: { // 0x6c26fa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c26fc: { // 0x6c26fc: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L006c2700: { // 0x6c2700: ff9050010000 CALL dword ptr [EAX + 0x150]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000150u)),7087878u); flags=s.arithmetic_flags;
  }
  L006c2706: { // 0x6c2706: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2708: { // 0x6c2708: 740f JZ 0x006c2719
    if(integer::condition("JZ",flags)) goto L006c2719;
  }
  L006c270a: { // 0x6c270a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c270b: { // 0x6c270b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c270c: { // 0x6c270c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c270d: { // 0x6c270d: b805000000 MOV EAX,0x5
    s.ax = 0x00000005u;
  }
  L006c2712: { // 0x6c2712: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2713: { // 0x6c2713: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2716: { // 0x6c2716: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c2719: { // 0x6c2719: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c271f: { // 0x6c271f: e88c20e3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7087908u); flags=s.arithmetic_flags;
  }
  L006c2724: { // 0x6c2724: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2726: { // 0x6c2726: 0f8403010000 JZ 0x006c282f
    if(integer::condition("JZ",flags)) goto L006c282f;
  }
  L006c272c: { // 0x6c272c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c272e: { // 0x6c272e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2730: { // 0x6c2730: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),7087926u); flags=s.arithmetic_flags;
  }
  L006c2736: { // 0x6c2736: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2738: { // 0x6c2738: 7512 JNZ 0x006c274c
    if(integer::condition("JNZ",flags)) goto L006c274c;
  }
  L006c273a: { // 0x6c273a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c273c: { // 0x6c273c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c273e: { // 0x6c273e: ff9064020000 CALL dword ptr [EAX + 0x264]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000264u)),7087940u); flags=s.arithmetic_flags;
  }
  L006c2744: { // 0x6c2744: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2746: { // 0x6c2746: 0f84e3000000 JZ 0x006c282f
    if(integer::condition("JZ",flags)) goto L006c282f;
  }
  L006c274c: { // 0x6c274c: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L006c2750: { // 0x6c2750: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006c2752: { // 0x6c2752: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c2753: { // 0x6c2753: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c2758: { // 0x6c2758: e8f34ce9ff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,7087965u); flags=s.arithmetic_flags;
  }
  L006c275d: { // 0x6c275d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c275f: { // 0x6c275f: 0f84bb000000 JZ 0x006c2820
    if(integer::condition("JZ",flags)) goto L006c2820;
  }
  L006c2765: { // 0x6c2765: 8a442411 MOV AL,byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L006c2769: { // 0x6c2769: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c276b: { // 0x6c276b: 740f JZ 0x006c277c
    if(integer::condition("JZ",flags)) goto L006c277c;
  }
  L006c276d: { // 0x6c276d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c276e: { // 0x6c276e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c276f: { // 0x6c276f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2770: { // 0x6c2770: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006c2775: { // 0x6c2775: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2776: { // 0x6c2776: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2779: { // 0x6c2779: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c277c: { // 0x6c277c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c277e: { // 0x6c277e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2780: { // 0x6c2780: ff9264020000 CALL dword ptr [EDX + 0x264]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000264u)),7088006u); flags=s.arithmetic_flags;
  }
  L006c2786: { // 0x6c2786: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2788: { // 0x6c2788: 7417 JZ 0x006c27a1
    if(integer::condition("JZ",flags)) goto L006c27a1;
  }
  L006c278a: { // 0x6c278a: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L006c278e: { // 0x6c278e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c2790: { // 0x6c2790: 740f JZ 0x006c27a1
    if(integer::condition("JZ",flags)) goto L006c27a1;
  }
  L006c2792: { // 0x6c2792: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2793: { // 0x6c2793: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2794: { // 0x6c2794: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2795: { // 0x6c2795: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006c279a: { // 0x6c279a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c279b: { // 0x6c279b: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c279e: { // 0x6c279e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c27a1: { // 0x6c27a1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c27a3: { // 0x6c27a3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c27a5: { // 0x6c27a5: ff909c000000 CALL dword ptr [EAX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000009cu)),7088043u); flags=s.arithmetic_flags;
  }
  L006c27ab: { // 0x6c27ab: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c27ad: { // 0x6c27ad: 7471 JZ 0x006c2820
    if(integer::condition("JZ",flags)) goto L006c2820;
  }
  L006c27af: { // 0x6c27af: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006c27b1: { // 0x6c27b1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006c27b3: { // 0x6c27b3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c27b5: { // 0x6c27b5: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27b7: { // 0x6c27b7: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27b9: { // 0x6c27b9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c27ba: { // 0x6c27ba: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c27bf: { // 0x6c27bf: e83c2de8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7088068u); flags=s.arithmetic_flags;
  }
  L006c27c4: { // 0x6c27c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c27c5: { // 0x6c27c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c27c7: { // 0x6c27c7: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),7088077u); flags=s.arithmetic_flags;
  }
  L006c27cd: { // 0x6c27cd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006c27d0: { // 0x6c27d0: 7e3f JLE 0x006c2811
    if(integer::condition("JLE",flags)) goto L006c2811;
  }
  L006c27d2: { // 0x6c27d2: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L006c27d6: { // 0x6c27d6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c27d8: { // 0x6c27d8: 7537 JNZ 0x006c2811
    if(integer::condition("JNZ",flags)) goto L006c2811;
  }
  L006c27da: { // 0x6c27da: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c27dc: { // 0x6c27dc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c27de: { // 0x6c27de: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7088100u); flags=s.arithmetic_flags;
  }
  L006c27e4: { // 0x6c27e4: 8a88f50a0000 MOV CL,byte ptr [EAX + 0xaf5]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af5u)));
  }
  L006c27ea: { // 0x6c27ea: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c27ec: { // 0x6c27ec: 7432 JZ 0x006c2820
    if(integer::condition("JZ",flags)) goto L006c2820;
  }
  L006c27ee: { // 0x6c27ee: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006c27f0: { // 0x6c27f0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c27f2: { // 0x6c27f2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c27f4: { // 0x6c27f4: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27f6: { // 0x6c27f6: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006c27f8: { // 0x6c27f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c27f9: { // 0x6c27f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c27fe: { // 0x6c27fe: e8fd2ce8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7088131u); flags=s.arithmetic_flags;
  }
  L006c2803: { // 0x6c2803: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c2804: { // 0x6c2804: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c2806: { // 0x6c2806: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),7088140u); flags=s.arithmetic_flags;
  }
  L006c280c: { // 0x6c280c: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006c280f: { // 0x6c280f: 7f0f JG 0x006c2820
    if(integer::condition("JG",flags)) goto L006c2820;
  }
  L006c2811: { // 0x6c2811: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2812: { // 0x6c2812: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2813: { // 0x6c2813: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2814: { // 0x6c2814: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006c2819: { // 0x6c2819: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c281a: { // 0x6c281a: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c281d: { // 0x6c281d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c2820: { // 0x6c2820: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2821: { // 0x6c2821: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2822: { // 0x6c2822: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2823: { // 0x6c2823: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L006c2828: { // 0x6c2828: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2829: { // 0x6c2829: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c282c: { // 0x6c282c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c282f: { // 0x6c282f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c2830: { // 0x6c2830: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c2831: { // 0x6c2831: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c2832: { // 0x6c2832: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c2834: { // 0x6c2834: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c2835: { // 0x6c2835: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L006c2838: { // 0x6c2838: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
