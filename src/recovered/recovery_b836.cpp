#include "recovered/recovery_b836_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b836 {
namespace {
void f_00157340(Memory&,State&,Frame&,const Operations&);
void f_00157280(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0017f930(Memory&,State&,Frame&,const Operations&);
void f_001851f0(Memory&,State&,Frame&,const Operations&);
void f_0001c300(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_0017f930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057f930: { // 0x57f930: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0057f934: { // 0x57f934: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057f937: { // 0x57f937: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057f938: { // 0x57f938: 8b35a8aaa300 MOV ESI,dword ptr [0x00a3aaa8]
    s.si = m.r32((0x00a3aaa8u));
  }
  L0057f93e: { // 0x57f93e: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0057f940: { // 0x57f940: 8d48fc LEA ECX,[EAX + -0x4]
    s.cx = (s.ax-0x00000004u);
  }
  L0057f943: { // 0x57f943: 83f920 CMP ECX,0x20
    (void)integer::sub(s.cx,0x00000020u,32,flags);
  }
  L0057f946: { // 0x57f946: 0f87fa030000 JA 0x0057fd46
    if(integer::condition("JA",flags)) goto L0057fd46;
  }
  L0057f94c: { // 0x57f94c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0057f94e: { // 0x57f94e: 8a91acfd5700 MOV DL,byte ptr [ECX + 0x57fdac]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0057fdacu)));
  }
  L0057f954: { // 0x57f954: ff249558fd5700 JMP dword ptr [EDX*0x4 + 0x57fd58]
    switch(m.r32(((s.dx * 0x00000004u)+0x0057fd58u))){
    case 0x0057f930u: goto L0057f930;
    case 0x0057f934u: goto L0057f934;
    case 0x0057f937u: goto L0057f937;
    case 0x0057f938u: goto L0057f938;
    case 0x0057f93eu: goto L0057f93e;
    case 0x0057f940u: goto L0057f940;
    case 0x0057f943u: goto L0057f943;
    case 0x0057f946u: goto L0057f946;
    case 0x0057f94cu: goto L0057f94c;
    case 0x0057f94eu: goto L0057f94e;
    case 0x0057f954u: goto L0057f954;
    case 0x0057f95bu: goto L0057f95b;
    case 0x0057f95du: goto L0057f95d;
    case 0x0057f962u: goto L0057f962;
    case 0x0057f967u: goto L0057f967;
    case 0x0057f96bu: goto L0057f96b;
    case 0x0057f96fu: goto L0057f96f;
    case 0x0057f973u: goto L0057f973;
    case 0x0057f979u: goto L0057f979;
    case 0x0057f97fu: goto L0057f97f;
    case 0x0057f984u: goto L0057f984;
    case 0x0057f987u: goto L0057f987;
    case 0x0057f989u: goto L0057f989;
    case 0x0057f98fu: goto L0057f98f;
    case 0x0057f992u: goto L0057f992;
    case 0x0057f994u: goto L0057f994;
    case 0x0057f995u: goto L0057f995;
    case 0x0057f998u: goto L0057f998;
    case 0x0057f99bu: goto L0057f99b;
    case 0x0057f99du: goto L0057f99d;
    case 0x0057f9a2u: goto L0057f9a2;
    case 0x0057f9a7u: goto L0057f9a7;
    case 0x0057f9abu: goto L0057f9ab;
    case 0x0057f9afu: goto L0057f9af;
    case 0x0057f9b3u: goto L0057f9b3;
    case 0x0057f9b9u: goto L0057f9b9;
    case 0x0057f9beu: goto L0057f9be;
    case 0x0057f9c1u: goto L0057f9c1;
    case 0x0057f9c3u: goto L0057f9c3;
    case 0x0057f9c9u: goto L0057f9c9;
    case 0x0057f9cdu: goto L0057f9cd;
    case 0x0057f9cfu: goto L0057f9cf;
    case 0x0057f9d0u: goto L0057f9d0;
    case 0x0057f9d3u: goto L0057f9d3;
    case 0x0057f9d6u: goto L0057f9d6;
    case 0x0057f9d8u: goto L0057f9d8;
    case 0x0057f9ddu: goto L0057f9dd;
    case 0x0057f9e2u: goto L0057f9e2;
    case 0x0057f9e6u: goto L0057f9e6;
    case 0x0057f9eau: goto L0057f9ea;
    case 0x0057f9eeu: goto L0057f9ee;
    case 0x0057f9f4u: goto L0057f9f4;
    case 0x0057f9f9u: goto L0057f9f9;
    case 0x0057f9fcu: goto L0057f9fc;
    case 0x0057f9feu: goto L0057f9fe;
    case 0x0057fa04u: goto L0057fa04;
    case 0x0057fa07u: goto L0057fa07;
    case 0x0057fa09u: goto L0057fa09;
    case 0x0057fa0au: goto L0057fa0a;
    case 0x0057fa0du: goto L0057fa0d;
    case 0x0057fa10u: goto L0057fa10;
    case 0x0057fa12u: goto L0057fa12;
    case 0x0057fa17u: goto L0057fa17;
    case 0x0057fa1cu: goto L0057fa1c;
    case 0x0057fa20u: goto L0057fa20;
    case 0x0057fa24u: goto L0057fa24;
    case 0x0057fa28u: goto L0057fa28;
    case 0x0057fa2eu: goto L0057fa2e;
    case 0x0057fa34u: goto L0057fa34;
    case 0x0057fa39u: goto L0057fa39;
    case 0x0057fa3cu: goto L0057fa3c;
    case 0x0057fa3eu: goto L0057fa3e;
    case 0x0057fa44u: goto L0057fa44;
    case 0x0057fa47u: goto L0057fa47;
    case 0x0057fa49u: goto L0057fa49;
    case 0x0057fa4au: goto L0057fa4a;
    case 0x0057fa4du: goto L0057fa4d;
    case 0x0057fa50u: goto L0057fa50;
    case 0x0057fa52u: goto L0057fa52;
    case 0x0057fa57u: goto L0057fa57;
    case 0x0057fa5cu: goto L0057fa5c;
    case 0x0057fa60u: goto L0057fa60;
    case 0x0057fa64u: goto L0057fa64;
    case 0x0057fa68u: goto L0057fa68;
    case 0x0057fa6eu: goto L0057fa6e;
    case 0x0057fa73u: goto L0057fa73;
    case 0x0057fa76u: goto L0057fa76;
    case 0x0057fa78u: goto L0057fa78;
    case 0x0057fa7eu: goto L0057fa7e;
    case 0x0057fa82u: goto L0057fa82;
    case 0x0057fa84u: goto L0057fa84;
    case 0x0057fa85u: goto L0057fa85;
    case 0x0057fa88u: goto L0057fa88;
    case 0x0057fa8bu: goto L0057fa8b;
    case 0x0057fa8du: goto L0057fa8d;
    case 0x0057fa92u: goto L0057fa92;
    case 0x0057fa97u: goto L0057fa97;
    case 0x0057fa9bu: goto L0057fa9b;
    case 0x0057fa9fu: goto L0057fa9f;
    case 0x0057faa3u: goto L0057faa3;
    case 0x0057faa9u: goto L0057faa9;
    case 0x0057faaeu: goto L0057faae;
    case 0x0057fab1u: goto L0057fab1;
    case 0x0057fab3u: goto L0057fab3;
    case 0x0057fab9u: goto L0057fab9;
    case 0x0057fabcu: goto L0057fabc;
    case 0x0057fabeu: goto L0057fabe;
    case 0x0057fabfu: goto L0057fabf;
    case 0x0057fac2u: goto L0057fac2;
    case 0x0057fac5u: goto L0057fac5;
    case 0x0057fac7u: goto L0057fac7;
    case 0x0057faccu: goto L0057facc;
    case 0x0057fad1u: goto L0057fad1;
    case 0x0057fad5u: goto L0057fad5;
    case 0x0057fad9u: goto L0057fad9;
    case 0x0057faddu: goto L0057fadd;
    case 0x0057fae3u: goto L0057fae3;
    case 0x0057fae9u: goto L0057fae9;
    case 0x0057faeeu: goto L0057faee;
    case 0x0057faf1u: goto L0057faf1;
    case 0x0057faf3u: goto L0057faf3;
    case 0x0057faf9u: goto L0057faf9;
    case 0x0057fafcu: goto L0057fafc;
    case 0x0057fafeu: goto L0057fafe;
    case 0x0057faffu: goto L0057faff;
    case 0x0057fb02u: goto L0057fb02;
    case 0x0057fb05u: goto L0057fb05;
    case 0x0057fb07u: goto L0057fb07;
    case 0x0057fb0cu: goto L0057fb0c;
    case 0x0057fb11u: goto L0057fb11;
    case 0x0057fb15u: goto L0057fb15;
    case 0x0057fb19u: goto L0057fb19;
    case 0x0057fb1du: goto L0057fb1d;
    case 0x0057fb23u: goto L0057fb23;
    case 0x0057fb28u: goto L0057fb28;
    case 0x0057fb2bu: goto L0057fb2b;
    case 0x0057fb2du: goto L0057fb2d;
    case 0x0057fb33u: goto L0057fb33;
    case 0x0057fb37u: goto L0057fb37;
    case 0x0057fb39u: goto L0057fb39;
    case 0x0057fb3au: goto L0057fb3a;
    case 0x0057fb3du: goto L0057fb3d;
    case 0x0057fb40u: goto L0057fb40;
    case 0x0057fb42u: goto L0057fb42;
    case 0x0057fb47u: goto L0057fb47;
    case 0x0057fb4cu: goto L0057fb4c;
    case 0x0057fb50u: goto L0057fb50;
    case 0x0057fb54u: goto L0057fb54;
    case 0x0057fb58u: goto L0057fb58;
    case 0x0057fb5eu: goto L0057fb5e;
    case 0x0057fb63u: goto L0057fb63;
    case 0x0057fb66u: goto L0057fb66;
    case 0x0057fb68u: goto L0057fb68;
    case 0x0057fb6eu: goto L0057fb6e;
    case 0x0057fb71u: goto L0057fb71;
    case 0x0057fb73u: goto L0057fb73;
    case 0x0057fb74u: goto L0057fb74;
    case 0x0057fb77u: goto L0057fb77;
    case 0x0057fb7au: goto L0057fb7a;
    case 0x0057fb7cu: goto L0057fb7c;
    case 0x0057fb81u: goto L0057fb81;
    case 0x0057fb86u: goto L0057fb86;
    case 0x0057fb8au: goto L0057fb8a;
    case 0x0057fb8eu: goto L0057fb8e;
    case 0x0057fb92u: goto L0057fb92;
    case 0x0057fb98u: goto L0057fb98;
    case 0x0057fb9eu: goto L0057fb9e;
    case 0x0057fba3u: goto L0057fba3;
    case 0x0057fba6u: goto L0057fba6;
    case 0x0057fba8u: goto L0057fba8;
    case 0x0057fbaeu: goto L0057fbae;
    case 0x0057fbb1u: goto L0057fbb1;
    case 0x0057fbb3u: goto L0057fbb3;
    case 0x0057fbb4u: goto L0057fbb4;
    case 0x0057fbb7u: goto L0057fbb7;
    case 0x0057fbbau: goto L0057fbba;
    case 0x0057fbbcu: goto L0057fbbc;
    case 0x0057fbc1u: goto L0057fbc1;
    case 0x0057fbc6u: goto L0057fbc6;
    case 0x0057fbcau: goto L0057fbca;
    case 0x0057fbceu: goto L0057fbce;
    case 0x0057fbd2u: goto L0057fbd2;
    case 0x0057fbd8u: goto L0057fbd8;
    case 0x0057fbddu: goto L0057fbdd;
    case 0x0057fbe0u: goto L0057fbe0;
    case 0x0057fbe2u: goto L0057fbe2;
    case 0x0057fbe8u: goto L0057fbe8;
    case 0x0057fbecu: goto L0057fbec;
    case 0x0057fbeeu: goto L0057fbee;
    case 0x0057fbefu: goto L0057fbef;
    case 0x0057fbf2u: goto L0057fbf2;
    case 0x0057fbf5u: goto L0057fbf5;
    case 0x0057fbf7u: goto L0057fbf7;
    case 0x0057fbfcu: goto L0057fbfc;
    case 0x0057fc01u: goto L0057fc01;
    case 0x0057fc05u: goto L0057fc05;
    case 0x0057fc09u: goto L0057fc09;
    case 0x0057fc0du: goto L0057fc0d;
    case 0x0057fc13u: goto L0057fc13;
    case 0x0057fc18u: goto L0057fc18;
    case 0x0057fc1bu: goto L0057fc1b;
    case 0x0057fc1du: goto L0057fc1d;
    case 0x0057fc23u: goto L0057fc23;
    case 0x0057fc26u: goto L0057fc26;
    case 0x0057fc28u: goto L0057fc28;
    case 0x0057fc29u: goto L0057fc29;
    case 0x0057fc2cu: goto L0057fc2c;
    case 0x0057fc2fu: goto L0057fc2f;
    case 0x0057fc31u: goto L0057fc31;
    case 0x0057fc36u: goto L0057fc36;
    case 0x0057fc3bu: goto L0057fc3b;
    case 0x0057fc3fu: goto L0057fc3f;
    case 0x0057fc43u: goto L0057fc43;
    case 0x0057fc47u: goto L0057fc47;
    case 0x0057fc4du: goto L0057fc4d;
    case 0x0057fc53u: goto L0057fc53;
    case 0x0057fc58u: goto L0057fc58;
    case 0x0057fc5bu: goto L0057fc5b;
    case 0x0057fc5du: goto L0057fc5d;
    case 0x0057fc63u: goto L0057fc63;
    case 0x0057fc66u: goto L0057fc66;
    case 0x0057fc68u: goto L0057fc68;
    case 0x0057fc69u: goto L0057fc69;
    case 0x0057fc6cu: goto L0057fc6c;
    case 0x0057fc6fu: goto L0057fc6f;
    case 0x0057fc71u: goto L0057fc71;
    case 0x0057fc76u: goto L0057fc76;
    case 0x0057fc7bu: goto L0057fc7b;
    case 0x0057fc7fu: goto L0057fc7f;
    case 0x0057fc83u: goto L0057fc83;
    case 0x0057fc87u: goto L0057fc87;
    case 0x0057fc8du: goto L0057fc8d;
    case 0x0057fc92u: goto L0057fc92;
    case 0x0057fc95u: goto L0057fc95;
    case 0x0057fc97u: goto L0057fc97;
    case 0x0057fc9du: goto L0057fc9d;
    case 0x0057fca1u: goto L0057fca1;
    case 0x0057fca3u: goto L0057fca3;
    case 0x0057fca4u: goto L0057fca4;
    case 0x0057fca7u: goto L0057fca7;
    case 0x0057fcaau: goto L0057fcaa;
    case 0x0057fcacu: goto L0057fcac;
    case 0x0057fcb1u: goto L0057fcb1;
    case 0x0057fcb6u: goto L0057fcb6;
    case 0x0057fcbau: goto L0057fcba;
    case 0x0057fcbeu: goto L0057fcbe;
    case 0x0057fcc2u: goto L0057fcc2;
    case 0x0057fcc8u: goto L0057fcc8;
    case 0x0057fccdu: goto L0057fccd;
    case 0x0057fcd0u: goto L0057fcd0;
    case 0x0057fcd2u: goto L0057fcd2;
    case 0x0057fcd8u: goto L0057fcd8;
    case 0x0057fcdbu: goto L0057fcdb;
    case 0x0057fcddu: goto L0057fcdd;
    case 0x0057fcdeu: goto L0057fcde;
    case 0x0057fce1u: goto L0057fce1;
    case 0x0057fce4u: goto L0057fce4;
    case 0x0057fceau: goto L0057fcea;
    case 0x0057fcefu: goto L0057fcef;
    case 0x0057fcf1u: goto L0057fcf1;
    case 0x0057fcf2u: goto L0057fcf2;
    case 0x0057fcf5u: goto L0057fcf5;
    case 0x0057fcf8u: goto L0057fcf8;
    case 0x0057fcfeu: goto L0057fcfe;
    case 0x0057fd03u: goto L0057fd03;
    case 0x0057fd05u: goto L0057fd05;
    case 0x0057fd06u: goto L0057fd06;
    case 0x0057fd09u: goto L0057fd09;
    case 0x0057fd0cu: goto L0057fd0c;
    case 0x0057fd11u: goto L0057fd11;
    case 0x0057fd16u: goto L0057fd16;
    case 0x0057fd18u: goto L0057fd18;
    case 0x0057fd1du: goto L0057fd1d;
    case 0x0057fd1fu: goto L0057fd1f;
    case 0x0057fd24u: goto L0057fd24;
    case 0x0057fd2au: goto L0057fd2a;
    case 0x0057fd2eu: goto L0057fd2e;
    case 0x0057fd30u: goto L0057fd30;
    case 0x0057fd31u: goto L0057fd31;
    case 0x0057fd34u: goto L0057fd34;
    case 0x0057fd37u: goto L0057fd37;
    case 0x0057fd3cu: goto L0057fd3c;
    case 0x0057fd3eu: goto L0057fd3e;
    case 0x0057fd43u: goto L0057fd43;
    case 0x0057fd46u: goto L0057fd46;
    case 0x0057fd4cu: goto L0057fd4c;
    case 0x0057fd4du: goto L0057fd4d;
    case 0x0057fd4fu: goto L0057fd4f;
    case 0x0057fd52u: goto L0057fd52;
    default:throw std::domain_error("recovery836 unsupported switch destination");}
  }
  L0057f95b: { // 0x57f95b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057f95d: { // 0x57f95d: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f962: { // 0x57f962: e879040b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765479u); flags=s.arithmetic_flags;
  }
  L0057f967: { // 0x57f967: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057f96b: { // 0x57f96b: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057f96f: { // 0x57f96f: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f973: { // 0x57f973: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f979: { // 0x57f979: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057f97f: { // 0x57f97f: e8ccb01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765508u); flags=s.arithmetic_flags;
  }
  L0057f984: { // 0x57f984: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057f987: { // 0x57f987: 77d4 JA 0x0057f95d
    if(integer::condition("JA",flags)) goto L0057f95d;
  }
  L0057f989: { // 0x57f989: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057f98f: { // 0x57f98f: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0057f992: { // 0x57f992: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f994: { // 0x57f994: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057f995: { // 0x57f995: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057f998: { // 0x57f998: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057f99b: { // 0x57f99b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057f99d: { // 0x57f99d: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f9a2: { // 0x57f9a2: e839040b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765543u); flags=s.arithmetic_flags;
  }
  L0057f9a7: { // 0x57f9a7: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057f9ab: { // 0x57f9ab: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057f9af: { // 0x57f9af: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f9b3: { // 0x57f9b3: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f9b9: { // 0x57f9b9: e892b01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765566u); flags=s.arithmetic_flags;
  }
  L0057f9be: { // 0x57f9be: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057f9c1: { // 0x57f9c1: 77da JA 0x0057f99d
    if(integer::condition("JA",flags)) goto L0057f99d;
  }
  L0057f9c3: { // 0x57f9c3: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057f9c9: { // 0x57f9c9: 8d440004 LEA EAX,[EAX + EAX*0x1 + 0x4]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000004u);
  }
  L0057f9cd: { // 0x57f9cd: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f9cf: { // 0x57f9cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057f9d0: { // 0x57f9d0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057f9d3: { // 0x57f9d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057f9d6: { // 0x57f9d6: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057f9d8: { // 0x57f9d8: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f9dd: { // 0x57f9dd: e8fe030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765602u); flags=s.arithmetic_flags;
  }
  L0057f9e2: { // 0x57f9e2: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057f9e6: { // 0x57f9e6: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057f9ea: { // 0x57f9ea: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f9ee: { // 0x57f9ee: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f9f4: { // 0x57f9f4: e857b01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765625u); flags=s.arithmetic_flags;
  }
  L0057f9f9: { // 0x57f9f9: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057f9fc: { // 0x57f9fc: 77da JA 0x0057f9d8
    if(integer::condition("JA",flags)) goto L0057f9d8;
  }
  L0057f9fe: { // 0x57f9fe: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fa04: { // 0x57fa04: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0057fa07: { // 0x57fa07: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fa09: { // 0x57fa09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fa0a: { // 0x57fa0a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fa0d: { // 0x57fa0d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fa10: { // 0x57fa10: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fa12: { // 0x57fa12: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fa17: { // 0x57fa17: e8c4030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765660u); flags=s.arithmetic_flags;
  }
  L0057fa1c: { // 0x57fa1c: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fa20: { // 0x57fa20: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fa24: { // 0x57fa24: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fa28: { // 0x57fa28: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fa2e: { // 0x57fa2e: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fa34: { // 0x57fa34: e817b01e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765689u); flags=s.arithmetic_flags;
  }
  L0057fa39: { // 0x57fa39: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057fa3c: { // 0x57fa3c: 77d4 JA 0x0057fa12
    if(integer::condition("JA",flags)) goto L0057fa12;
  }
  L0057fa3e: { // 0x57fa3e: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fa44: { // 0x57fa44: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L0057fa47: { // 0x57fa47: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fa49: { // 0x57fa49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fa4a: { // 0x57fa4a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fa4d: { // 0x57fa4d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fa50: { // 0x57fa50: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fa52: { // 0x57fa52: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fa57: { // 0x57fa57: e884030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765724u); flags=s.arithmetic_flags;
  }
  L0057fa5c: { // 0x57fa5c: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fa60: { // 0x57fa60: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fa64: { // 0x57fa64: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fa68: { // 0x57fa68: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fa6e: { // 0x57fa6e: e8ddaf1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765747u); flags=s.arithmetic_flags;
  }
  L0057fa73: { // 0x57fa73: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fa76: { // 0x57fa76: 77da JA 0x0057fa52
    if(integer::condition("JA",flags)) goto L0057fa52;
  }
  L0057fa78: { // 0x57fa78: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fa7e: { // 0x57fa7e: 8d440008 LEA EAX,[EAX + EAX*0x1 + 0x8]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000008u);
  }
  L0057fa82: { // 0x57fa82: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fa84: { // 0x57fa84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fa85: { // 0x57fa85: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fa88: { // 0x57fa88: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fa8b: { // 0x57fa8b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fa8d: { // 0x57fa8d: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fa92: { // 0x57fa92: e849030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765783u); flags=s.arithmetic_flags;
  }
  L0057fa97: { // 0x57fa97: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fa9b: { // 0x57fa9b: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fa9f: { // 0x57fa9f: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057faa3: { // 0x57faa3: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057faa9: { // 0x57faa9: e8a2af1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765806u); flags=s.arithmetic_flags;
  }
  L0057faae: { // 0x57faae: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fab1: { // 0x57fab1: 77da JA 0x0057fa8d
    if(integer::condition("JA",flags)) goto L0057fa8d;
  }
  L0057fab3: { // 0x57fab3: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fab9: { // 0x57fab9: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L0057fabc: { // 0x57fabc: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fabe: { // 0x57fabe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fabf: { // 0x57fabf: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fac2: { // 0x57fac2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fac5: { // 0x57fac5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fac7: { // 0x57fac7: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057facc: { // 0x57facc: e80f030b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765841u); flags=s.arithmetic_flags;
  }
  L0057fad1: { // 0x57fad1: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fad5: { // 0x57fad5: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fad9: { // 0x57fad9: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fadd: { // 0x57fadd: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fae3: { // 0x57fae3: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fae9: { // 0x57fae9: e862af1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765870u); flags=s.arithmetic_flags;
  }
  L0057faee: { // 0x57faee: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057faf1: { // 0x57faf1: 77d4 JA 0x0057fac7
    if(integer::condition("JA",flags)) goto L0057fac7;
  }
  L0057faf3: { // 0x57faf3: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057faf9: { // 0x57faf9: 83c00b ADD EAX,0xb
    s.ax = integer::add(s.ax,0x0000000bu,32,flags);
  }
  L0057fafc: { // 0x57fafc: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fafe: { // 0x57fafe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057faff: { // 0x57faff: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fb02: { // 0x57fb02: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fb05: { // 0x57fb05: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fb07: { // 0x57fb07: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fb0c: { // 0x57fb0c: e8cf020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765905u); flags=s.arithmetic_flags;
  }
  L0057fb11: { // 0x57fb11: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fb15: { // 0x57fb15: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fb19: { // 0x57fb19: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fb1d: { // 0x57fb1d: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fb23: { // 0x57fb23: e828af1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765928u); flags=s.arithmetic_flags;
  }
  L0057fb28: { // 0x57fb28: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fb2b: { // 0x57fb2b: 77da JA 0x0057fb07
    if(integer::condition("JA",flags)) goto L0057fb07;
  }
  L0057fb2d: { // 0x57fb2d: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fb33: { // 0x57fb33: 8d44000b LEA EAX,[EAX + EAX*0x1 + 0xb]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x0000000bu);
  }
  L0057fb37: { // 0x57fb37: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fb39: { // 0x57fb39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fb3a: { // 0x57fb3a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fb3d: { // 0x57fb3d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fb40: { // 0x57fb40: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fb42: { // 0x57fb42: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fb47: { // 0x57fb47: e894020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5765964u); flags=s.arithmetic_flags;
  }
  L0057fb4c: { // 0x57fb4c: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fb50: { // 0x57fb50: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fb54: { // 0x57fb54: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fb58: { // 0x57fb58: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fb5e: { // 0x57fb5e: e8edae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5765987u); flags=s.arithmetic_flags;
  }
  L0057fb63: { // 0x57fb63: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fb66: { // 0x57fb66: 77da JA 0x0057fb42
    if(integer::condition("JA",flags)) goto L0057fb42;
  }
  L0057fb68: { // 0x57fb68: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fb6e: { // 0x57fb6e: 83c00b ADD EAX,0xb
    s.ax = integer::add(s.ax,0x0000000bu,32,flags);
  }
  L0057fb71: { // 0x57fb71: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fb73: { // 0x57fb73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fb74: { // 0x57fb74: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fb77: { // 0x57fb77: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fb7a: { // 0x57fb7a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fb7c: { // 0x57fb7c: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fb81: { // 0x57fb81: e85a020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766022u); flags=s.arithmetic_flags;
  }
  L0057fb86: { // 0x57fb86: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fb8a: { // 0x57fb8a: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fb8e: { // 0x57fb8e: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fb92: { // 0x57fb92: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fb98: { // 0x57fb98: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fb9e: { // 0x57fb9e: e8adae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766051u); flags=s.arithmetic_flags;
  }
  L0057fba3: { // 0x57fba3: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057fba6: { // 0x57fba6: 77d4 JA 0x0057fb7c
    if(integer::condition("JA",flags)) goto L0057fb7c;
  }
  L0057fba8: { // 0x57fba8: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fbae: { // 0x57fbae: 83c00e ADD EAX,0xe
    s.ax = integer::add(s.ax,0x0000000eu,32,flags);
  }
  L0057fbb1: { // 0x57fbb1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fbb3: { // 0x57fbb3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fbb4: { // 0x57fbb4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fbb7: { // 0x57fbb7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fbba: { // 0x57fbba: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fbbc: { // 0x57fbbc: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fbc1: { // 0x57fbc1: e81a020b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766086u); flags=s.arithmetic_flags;
  }
  L0057fbc6: { // 0x57fbc6: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fbca: { // 0x57fbca: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fbce: { // 0x57fbce: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fbd2: { // 0x57fbd2: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fbd8: { // 0x57fbd8: e873ae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766109u); flags=s.arithmetic_flags;
  }
  L0057fbdd: { // 0x57fbdd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fbe0: { // 0x57fbe0: 77da JA 0x0057fbbc
    if(integer::condition("JA",flags)) goto L0057fbbc;
  }
  L0057fbe2: { // 0x57fbe2: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fbe8: { // 0x57fbe8: 8d44000e LEA EAX,[EAX + EAX*0x1 + 0xe]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x0000000eu);
  }
  L0057fbec: { // 0x57fbec: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fbee: { // 0x57fbee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fbef: { // 0x57fbef: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fbf2: { // 0x57fbf2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fbf5: { // 0x57fbf5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fbf7: { // 0x57fbf7: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fbfc: { // 0x57fbfc: e8df010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766145u); flags=s.arithmetic_flags;
  }
  L0057fc01: { // 0x57fc01: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fc05: { // 0x57fc05: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fc09: { // 0x57fc09: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fc0d: { // 0x57fc0d: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fc13: { // 0x57fc13: e838ae1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766168u); flags=s.arithmetic_flags;
  }
  L0057fc18: { // 0x57fc18: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fc1b: { // 0x57fc1b: 77da JA 0x0057fbf7
    if(integer::condition("JA",flags)) goto L0057fbf7;
  }
  L0057fc1d: { // 0x57fc1d: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fc23: { // 0x57fc23: 83c00e ADD EAX,0xe
    s.ax = integer::add(s.ax,0x0000000eu,32,flags);
  }
  L0057fc26: { // 0x57fc26: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fc28: { // 0x57fc28: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fc29: { // 0x57fc29: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fc2c: { // 0x57fc2c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fc2f: { // 0x57fc2f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fc31: { // 0x57fc31: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fc36: { // 0x57fc36: e8a5010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766203u); flags=s.arithmetic_flags;
  }
  L0057fc3b: { // 0x57fc3b: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fc3f: { // 0x57fc3f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fc43: { // 0x57fc43: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fc47: { // 0x57fc47: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fc4d: { // 0x57fc4d: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L0057fc53: { // 0x57fc53: e8f8ad1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766232u); flags=s.arithmetic_flags;
  }
  L0057fc58: { // 0x57fc58: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0057fc5b: { // 0x57fc5b: 77d4 JA 0x0057fc31
    if(integer::condition("JA",flags)) goto L0057fc31;
  }
  L0057fc5d: { // 0x57fc5d: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fc63: { // 0x57fc63: 83c016 ADD EAX,0x16
    s.ax = integer::add(s.ax,0x00000016u,32,flags);
  }
  L0057fc66: { // 0x57fc66: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fc68: { // 0x57fc68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fc69: { // 0x57fc69: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fc6c: { // 0x57fc6c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fc6f: { // 0x57fc6f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fc71: { // 0x57fc71: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fc76: { // 0x57fc76: e865010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766267u); flags=s.arithmetic_flags;
  }
  L0057fc7b: { // 0x57fc7b: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fc7f: { // 0x57fc7f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fc83: { // 0x57fc83: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fc87: { // 0x57fc87: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fc8d: { // 0x57fc8d: e8bead1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766290u); flags=s.arithmetic_flags;
  }
  L0057fc92: { // 0x57fc92: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fc95: { // 0x57fc95: 77da JA 0x0057fc71
    if(integer::condition("JA",flags)) goto L0057fc71;
  }
  L0057fc97: { // 0x57fc97: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fc9d: { // 0x57fc9d: 8d440016 LEA EAX,[EAX + EAX*0x1 + 0x16]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000016u);
  }
  L0057fca1: { // 0x57fca1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fca3: { // 0x57fca3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fca4: { // 0x57fca4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fca7: { // 0x57fca7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fcaa: { // 0x57fcaa: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057fcac: { // 0x57fcac: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057fcb1: { // 0x57fcb1: e82a010b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5766326u); flags=s.arithmetic_flags;
  }
  L0057fcb6: { // 0x57fcb6: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L0057fcba: { // 0x57fcba: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0057fcbe: { // 0x57fcbe: df6c2404 FILD qword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057fcc2: { // 0x57fcc2: dc0dc80d7900 FMUL double ptr [0x00790dc8]
    const auto address=(0x00790dc8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057fcc8: { // 0x57fcc8: e883ad1e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5766349u); flags=s.arithmetic_flags;
  }
  L0057fccd: { // 0x57fccd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0057fcd0: { // 0x57fcd0: 77da JA 0x0057fcac
    if(integer::condition("JA",flags)) goto L0057fcac;
  }
  L0057fcd2: { // 0x57fcd2: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fcd8: { // 0x57fcd8: 83c016 ADD EAX,0x16
    s.ax = integer::add(s.ax,0x00000016u,32,flags);
  }
  L0057fcdb: { // 0x57fcdb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fcdd: { // 0x57fcdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fcde: { // 0x57fcde: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fce1: { // 0x57fce1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fce4: { // 0x57fce4: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fcea: { // 0x57fcea: b81d000000 MOV EAX,0x1d
    s.ax = 0x0000001du;
  }
  L0057fcef: { // 0x57fcef: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fcf1: { // 0x57fcf1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fcf2: { // 0x57fcf2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fcf5: { // 0x57fcf5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fcf8: { // 0x57fcf8: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fcfe: { // 0x57fcfe: b81c000000 MOV EAX,0x1c
    s.ax = 0x0000001cu;
  }
  L0057fd03: { // 0x57fd03: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fd05: { // 0x57fd05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fd06: { // 0x57fd06: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fd09: { // 0x57fd09: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fd0c: { // 0x57fd0c: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0057fd11: { // 0x57fd11: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0057fd16: { // 0x57fd16: eb26 JMP 0x0057fd3e
    goto L0057fd3e;
  }
  L0057fd18: { // 0x57fd18: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0057fd1d: { // 0x57fd1d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057fd1f: { // 0x57fd1f: e86c68ffff CALL 0x00576590
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576590u,5766436u); flags=s.arithmetic_flags;
  }
  L0057fd24: { // 0x57fd24: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fd2a: { // 0x57fd2a: 8d440022 LEA EAX,[EAX + EAX*0x1 + 0x22]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000022u);
  }
  L0057fd2e: { // 0x57fd2e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fd30: { // 0x57fd30: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fd31: { // 0x57fd31: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fd34: { // 0x57fd34: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057fd37: { // 0x57fd37: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0057fd3c: { // 0x57fd3c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057fd3e: { // 0x57fd3e: e84d68ffff CALL 0x00576590
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576590u,5766467u); flags=s.arithmetic_flags;
  }
  L0057fd43: { // 0x57fd43: 83c022 ADD EAX,0x22
    s.ax = integer::add(s.ax,0x00000022u,32,flags);
  }
  L0057fd46: { // 0x57fd46: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fd4c: { // 0x57fd4c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057fd4d: { // 0x57fd4d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057fd4f: { // 0x57fd4f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057fd52: { // 0x57fd52: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001851f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005851f0: { // 0x5851f0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005851f3: { // 0x5851f3: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  L005851f8: { // 0x5851f8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005851f9: { // 0x5851f9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005851fa: { // 0x5851fa: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005851fe: { // 0x5851fe: 8b2c88 MOV EBP,dword ptr [EAX + ECX*0x4]
    s.bp = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L00585201: { // 0x585201: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00585203: { // 0x585203: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00585206: { // 0x585206: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),5788172u); flags=s.arithmetic_flags;
  }
  L0058520c: { // 0x58520c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058520e: { // 0x58520e: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00585212: { // 0x585212: 0f8436010000 JZ 0x0058534e
    if(integer::condition("JZ",flags)) goto L0058534e;
  }
  L00585218: { // 0x585218: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058521e: { // 0x58521e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00585220: { // 0x585220: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00585222: { // 0x585222: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00585226: { // 0x585226: 0f8e22010000 JLE 0x0058534e
    if(integer::condition("JLE",flags)) goto L0058534e;
  }
  L0058522c: { // 0x58522c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058522d: { // 0x58522d: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585233: { // 0x585233: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00585234: { // 0x585234: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L0058523a: { // 0x58523a: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0058523c: { // 0x58523c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0058523e: { // 0x58523e: 0f8ef5000000 JLE 0x00585339
    if(integer::condition("JLE",flags)) goto L00585339;
  }
  L00585244: { // 0x585244: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00585248: { // 0x585248: 668bcb MOV CX,BX
    s.cx = with_ax(s.cx, (s.bx & 0xffffu));
  }
  L0058524b: { // 0x58524b: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L0058524e: { // 0x58524e: 66034a02 ADD CX,word ptr [EDX + 0x2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  L00585252: { // 0x585252: 6603c7 ADD AX,DI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L00585255: { // 0x585255: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L0058525a: { // 0x58525a: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L0058525f: { // 0x58525f: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00585263: { // 0x585263: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00585267: { // 0x585267: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0058526a: { // 0x58526a: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0058526d: { // 0x58526d: 8d0c10 LEA ECX,[EAX + EDX*0x1]
    s.cx = (s.ax+(s.dx * 0x00000001u));
  }
  L00585270: { // 0x585270: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00585272: { // 0x585272: 0f8eb2000000 JLE 0x0058532a
    if(integer::condition("JLE",flags)) goto L0058532a;
  }
  L00585278: { // 0x585278: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0058527a: { // 0x58527a: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0058527c: { // 0x58527c: 3bde CMP EBX,ESI
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L0058527e: { // 0x58527e: 0f8da2000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L00585284: { // 0x585284: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00585286: { // 0x585286: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00585288: { // 0x585288: 0f8d98000000 JGE 0x00585326
    if(integer::condition("JGE",flags)) goto L00585326;
  }
  L0058528e: { // 0x58528e: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L00585294: { // 0x585294: 0f8f8c000000 JG 0x00585326
    if(integer::condition("JG",flags)) goto L00585326;
  }
  L0058529a: { // 0x58529a: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0058529e: { // 0x58529e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005852a3: { // 0x5852a3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005852a4: { // 0x5852a4: e85702fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5788329u); flags=s.arithmetic_flags;
  }
  L005852a9: { // 0x5852a9: 8b8db4020000 MOV ECX,dword ptr [EBP + 0x2b4]
    s.cx = m.r32((s.bp+0x000002b4u));
  }
  L005852af: { // 0x5852af: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L005852b3: { // 0x5852b3: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L005852b7: { // 0x5852b7: 0fafcb IMUL ECX,EBX
    s.cx = integer::imul(s.cx,s.bx,32,flags);
  }
  L005852ba: { // 0x5852ba: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L005852bc: { // 0x5852bc: 8b748a10 MOV ESI,dword ptr [EDX + ECX*0x4 + 0x10]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x00000010u));
  }
  L005852c0: { // 0x5852c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005852c2: { // 0x5852c2: 745a JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852c4: { // 0x5852c4: 8b9564020000 MOV EDX,dword ptr [EBP + 0x264]
    s.dx = m.r32((s.bp+0x00000264u));
  }
  L005852ca: { // 0x5852ca: 88881a010000 MOV byte ptr [EAX + 0x11a],CL
    m.w8((s.ax+0x0000011au), (s.cx & 0xffu));
  }
  L005852d0: { // 0x5852d0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005852d4: { // 0x5852d4: 895038 MOV dword ptr [EAX + 0x38],EDX
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005852d7: { // 0x5852d7: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L005852da: { // 0x5852da: 740e JZ 0x005852ea
    if(integer::condition("JZ",flags)) goto L005852ea;
  }
  L005852dc: { // 0x5852dc: 8a5628 MOV DL,byte ptr [ESI + 0x28]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000028u)));
  }
  L005852df: { // 0x5852df: 02d1 ADD DL,CL
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L005852e1: { // 0x5852e1: 80ea04 SUB DL,0x4
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),0x00000004u,8,flags));
  }
  L005852e4: { // 0x5852e4: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L005852ea: { // 0x5852ea: 8a4e2a MOV CL,byte ptr [ESI + 0x2a]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000002au)));
  }
  L005852ed: { // 0x5852ed: 88881c010000 MOV byte ptr [EAX + 0x11c],CL
    m.w8((s.ax+0x0000011cu), (s.cx & 0xffu));
  }
  L005852f3: { // 0x5852f3: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005852f9: { // 0x5852f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005852fb: { // 0x5852fb: 7421 JZ 0x0058531e
    if(integer::condition("JZ",flags)) goto L0058531e;
  }
  L005852fd: { // 0x5852fd: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L00585302: { // 0x585302: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00585309: { // 0x585309: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0058530e: { // 0x58530e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00585310: { // 0x585310: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00585314: { // 0x585314: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00585317: { // 0x585317: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0058531a: { // 0x58531a: 89540838 MOV dword ptr [EAX + ECX*0x1 + 0x38],EDX
    m.w32((s.ax+(s.cx * 0x00000001u)+0x00000038u), s.dx);
  }
  L0058531e: { // 0x58531e: 8b353486a500 MOV ESI,dword ptr [0x00a58634]
    s.si = m.r32((0x00a58634u));
  }
  L00585324: { // 0x585324: eb04 JMP 0x0058532a
    goto L0058532a;
  }
  L00585326: { // 0x585326: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0058532a: { // 0x58532a: 8b85b4020000 MOV EAX,dword ptr [EBP + 0x2b4]
    s.ax = m.r32((s.bp+0x000002b4u));
  }
  L00585330: { // 0x585330: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00585331: { // 0x585331: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00585333: { // 0x585333: 0f8c0bffffff JL 0x00585244
    if(integer::condition("JL",flags)) goto L00585244;
  }
  L00585339: { // 0x585339: 8b85b8020000 MOV EAX,dword ptr [EBP + 0x2b8]
    s.ax = m.r32((s.bp+0x000002b8u));
  }
  L0058533f: { // 0x58533f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00585340: { // 0x585340: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00585342: { // 0x585342: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00585346: { // 0x585346: 0f8ce8feffff JL 0x00585234
    if(integer::condition("JL",flags)) goto L00585234;
  }
  L0058534c: { // 0x58534c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058534d: { // 0x58534d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058534e: { // 0x58534e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058534f: { // 0x58534f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00585350: { // 0x585350: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L00585353: { // 0x585353: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0001c300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041c300: { // 0x41c300: 8b81a4000000 MOV EAX,dword ptr [ECX + 0xa4]
    s.ax = m.r32((s.cx+0x000000a4u));
  }
  L0041c306: { // 0x41c306: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5600064u:f_00157340(m,s,child,{});break;
case 5599872u:f_00157280(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 5765424u:f_0017f930(m,s,child,{});break;
case 5788144u:f_001851f0(m,s,child,{});break;
case 4309760u:f_0001c300(m,s,child,{});break;
default:throw std::domain_error("recovery836 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0057fdd0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
std::array<std::uint8_t,117> table{91,249,87,0,155,249,87,0,214,249,87,0,16,250,87,0,80,250,87,0,139,250,87,0,197,250,87,0,5,251,87,0,64,251,87,0,122,251,87,0,186,251,87,0,245,251,87,0,47,252,87,0,111,252,87,0,170,252,87,0,228,252,87,0,248,252,87,0,12,253,87,0,24,253,87,0,55,253,87,0,70,253,87,0,0,1,2,20,3,4,5,6,7,8,9,10,11,20,20,20,20,20,12,13,14,20,20,20,15,16,20,20,20,20,17,18,19};leaf::Memory readonly_table(table.data(),0x57fd58u,117);m.add(readonly_table);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057fdd0: { // 0x57fdd0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L0057fdd3: { // 0x57fdd3: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L0057fdd7: { // 0x57fdd7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057fdd8: { // 0x57fdd8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057fddd: { // 0x57fddd: e85e75fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5766626u); flags=s.arithmetic_flags;
  }
  L0057fde2: { // 0x57fde2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057fde7: { // 0x57fde7: e89474fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5766636u); flags=s.arithmetic_flags;
  }
  L0057fdec: { // 0x57fdec: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0057fdee: { // 0x57fdee: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057fdf0: { // 0x57fdf0: 0f84b8010000 JZ 0x0057ffae
    if(integer::condition("JZ",flags)) goto L0057ffae;
  }
  L0057fdf6: { // 0x57fdf6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0057fdf7: { // 0x57fdf7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0057fdf8: { // 0x57fdf8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057fdf9: { // 0x57fdf9: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057fdfc: { // 0x57fdfc: 8b0da8aaa300 MOV ECX,dword ptr [0x00a3aaa8]
    s.cx = m.r32((0x00a3aaa8u));
  }
  L0057fe02: { // 0x57fe02: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057fe04: { // 0x57fe04: 0f8c8d010000 JL 0x0057ff97
    if(integer::condition("JL",flags)) goto L0057ff97;
  }
  L0057fe0a: { // 0x57fe0a: 83c128 ADD ECX,0x28
    s.cx = integer::add(s.cx,0x00000028u,32,flags);
  }
  L0057fe0d: { // 0x57fe0d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057fe0f: { // 0x57fe0f: 0f8d82010000 JGE 0x0057ff97
    if(integer::condition("JGE",flags)) goto L0057ff97;
  }
  L0057fe15: { // 0x57fe15: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0057fe17: { // 0x57fe17: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057fe19: { // 0x57fe19: e8a268efff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5766686u); flags=s.arithmetic_flags;
  }
  L0057fe1e: { // 0x57fe1e: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0057fe20: { // 0x57fe20: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057fe22: { // 0x57fe22: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0057fe24: { // 0x57fe24: e89768efff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5766697u); flags=s.arithmetic_flags;
  }
  L0057fe29: { // 0x57fe29: 8b4e38 MOV ECX,dword ptr [ESI + 0x38]
    s.cx = m.r32((s.si+0x00000038u));
  }
  L0057fe2c: { // 0x57fe2c: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0057fe2e: { // 0x57fe2e: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057fe31: { // 0x57fe31: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057fe33: { // 0x57fe33: 0f85ad000000 JNZ 0x0057fee6
    if(integer::condition("JNZ",flags)) goto L0057fee6;
  }
  L0057fe39: { // 0x57fe39: 8a8f1a010000 MOV CL,byte ptr [EDI + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000011au)));
  }
  L0057fe3f: { // 0x57fe3f: 8a961a010000 MOV DL,byte ptr [ESI + 0x11a]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000011au)));
  }
  L0057fe45: { // 0x57fe45: 3aca CMP CL,DL
    (void)integer::sub((s.cx & 0xffu),(s.dx & 0xffu),8,flags);
  }
  L0057fe47: { // 0x57fe47: 0f8699000000 JBE 0x0057fee6
    if(integer::condition("JBE",flags)) goto L0057fee6;
  }
  L0057fe4d: { // 0x57fe4d: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057fe51: { // 0x57fe51: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057fe52: { // 0x57fe52: e8d9faffff CALL 0x0057f930
    s.arithmetic_flags=flags; invoke(m,s,f,0x0057f930u,5766743u); flags=s.arithmetic_flags;
  }
  L0057fe57: { // 0x57fe57: 8b4f38 MOV ECX,dword ptr [EDI + 0x38]
    s.cx = m.r32((s.di+0x00000038u));
  }
  L0057fe5a: { // 0x57fe5a: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0057fe5e: { // 0x57fe5e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057fe60: { // 0x57fe60: 0f8480000000 JZ 0x0057fee6
    if(integer::condition("JZ",flags)) goto L0057fee6;
  }
  L0057fe66: { // 0x57fe66: 8b151489a200 MOV EDX,dword ptr [0x00a28914]
    s.dx = m.r32((0x00a28914u));
  }
  L0057fe6c: { // 0x57fe6c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057fe6e: { // 0x57fe6e: 8a9e1a010000 MOV BL,byte ptr [ESI + 0x11a]
    s.bx = with_al(s.bx, m.r8((s.si+0x0000011au)));
  }
  L0057fe74: { // 0x57fe74: 8b048a MOV EAX,dword ptr [EDX + ECX*0x4]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L0057fe77: { // 0x57fe77: 8b88b4020000 MOV ECX,dword ptr [EAX + 0x2b4]
    s.cx = m.r32((s.ax+0x000002b4u));
  }
  L0057fe7d: { // 0x57fe7d: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0057fe7f: { // 0x57fe7f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057fe80: { // 0x57fe80: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0057fe82: { // 0x57fe82: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0057fe84: { // 0x57fe84: 668954241c MOV word ptr [ESP + 0x1c],DX
    m.w16((f.sp+0x0000001cu), (s.dx & 0xffffu));
  }
  L0057fe89: { // 0x57fe89: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057fe8a: { // 0x57fe8a: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0057fe8c: { // 0x57fe8c: 668b5624 MOV DX,word ptr [ESI + 0x24]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000024u)));
  }
  L0057fe90: { // 0x57fe90: 668b7626 MOV SI,word ptr [ESI + 0x26]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.si+0x00000026u))) & 0xffffu);
  }
  L0057fe94: { // 0x57fe94: 662b54241c SUB DX,word ptr [ESP + 0x1c]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((f.sp+0x0000001cu)),16,flags));
  }
  L0057fe99: { // 0x57fe99: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057fe9f: { // 0x57fe9f: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L0057fea4: { // 0x57fea4: 662bf0 SUB SI,AX
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),(s.ax & 0xffffu),16,flags)) & 0xffffu);
  }
  L0057fea7: { // 0x57fea7: 6689742412 MOV word ptr [ESP + 0x12],SI
    m.w16((f.sp+0x00000012u), (s.si & 0xffffu));
  }
  L0057feac: { // 0x57feac: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0057feb0: { // 0x57feb0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057feb2: { // 0x57feb2: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0057feb6: { // 0x57feb6: 7505 JNZ 0x0057febd
    if(integer::condition("JNZ",flags)) goto L0057febd;
  }
  L0057feb8: { // 0x57feb8: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0057febb: { // 0x57febb: eb19 JMP 0x0057fed6
    goto L0057fed6;
  }
  L0057febd: { // 0x57febd: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0057fec0: { // 0x57fec0: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057fec7: { // 0x57fec7: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0057feca: { // 0x57feca: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057fecc: { // 0x57fecc: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057fecf: { // 0x57fecf: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057fed2: { // 0x57fed2: 8b4c0838 MOV ECX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.cx = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L0057fed6: { // 0x57fed6: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0057fed8: { // 0x57fed8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057fed9: { // 0x57fed9: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0057fedd: { // 0x57fedd: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L0057fee1: { // 0x57fee1: e80a530000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5766886u); flags=s.arithmetic_flags;
  }
  L0057fee6: { // 0x57fee6: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057fee9: { // 0x57fee9: 8b4d38 MOV ECX,dword ptr [EBP + 0x38]
    s.cx = m.r32((s.bp+0x00000038u));
  }
  L0057feec: { // 0x57feec: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057feee: { // 0x57feee: 0f85a3000000 JNZ 0x0057ff97
    if(integer::condition("JNZ",flags)) goto L0057ff97;
  }
  L0057fef4: { // 0x57fef4: 8a8f1a010000 MOV CL,byte ptr [EDI + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000011au)));
  }
  L0057fefa: { // 0x57fefa: 8a951a010000 MOV DL,byte ptr [EBP + 0x11a]
    s.dx = with_al(s.dx, m.r8((s.bp+0x0000011au)));
  }
  L0057ff00: { // 0x57ff00: 3aca CMP CL,DL
    (void)integer::sub((s.cx & 0xffu),(s.dx & 0xffu),8,flags);
  }
  L0057ff02: { // 0x57ff02: 0f868f000000 JBE 0x0057ff97
    if(integer::condition("JBE",flags)) goto L0057ff97;
  }
  L0057ff08: { // 0x57ff08: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057ff0c: { // 0x57ff0c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057ff0d: { // 0x57ff0d: e81efaffff CALL 0x0057f930
    s.arithmetic_flags=flags; invoke(m,s,f,0x0057f930u,5766930u); flags=s.arithmetic_flags;
  }
  L0057ff12: { // 0x57ff12: 8b7f38 MOV EDI,dword ptr [EDI + 0x38]
    s.di = m.r32((s.di+0x00000038u));
  }
  L0057ff15: { // 0x57ff15: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0057ff17: { // 0x57ff17: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0057ff19: { // 0x57ff19: 747c JZ 0x0057ff97
    if(integer::condition("JZ",flags)) goto L0057ff97;
  }
  L0057ff1b: { // 0x57ff1b: 8b151489a200 MOV EDX,dword ptr [0x00a28914]
    s.dx = m.r32((0x00a28914u));
  }
  L0057ff21: { // 0x57ff21: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057ff23: { // 0x57ff23: 8a8d1a010000 MOV CL,byte ptr [EBP + 0x11a]
    s.cx = with_al(s.cx, m.r8((s.bp+0x0000011au)));
  }
  L0057ff29: { // 0x57ff29: 8b04ba MOV EAX,dword ptr [EDX + EDI*0x4]
    s.ax = m.r32((s.dx+(s.di * 0x00000004u)));
  }
  L0057ff2c: { // 0x57ff2c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0057ff2e: { // 0x57ff2e: 8bb8b4020000 MOV EDI,dword ptr [EAX + 0x2b4]
    s.di = m.r32((s.ax+0x000002b4u));
  }
  L0057ff34: { // 0x57ff34: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0057ff36: { // 0x57ff36: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057ff37: { // 0x57ff37: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0057ff39: { // 0x57ff39: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0057ff3b: { // 0x57ff3b: 668b7526 MOV SI,word ptr [EBP + 0x26]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.bp+0x00000026u))) & 0xffffu);
  }
  L0057ff3f: { // 0x57ff3f: 668bca MOV CX,DX
    s.cx = with_ax(s.cx, (s.dx & 0xffffu));
  }
  L0057ff42: { // 0x57ff42: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057ff43: { // 0x57ff43: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0057ff45: { // 0x57ff45: 668b5524 MOV DX,word ptr [EBP + 0x24]
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000024u)));
  }
  L0057ff49: { // 0x57ff49: 662bd1 SUB DX,CX
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L0057ff4c: { // 0x57ff4c: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057ff52: { // 0x57ff52: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  L0057ff57: { // 0x57ff57: 662bf0 SUB SI,AX
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),(s.ax & 0xffffu),16,flags)) & 0xffffu);
  }
  L0057ff5a: { // 0x57ff5a: 668974241a MOV word ptr [ESP + 0x1a],SI
    m.w16((f.sp+0x0000001au), (s.si & 0xffffu));
  }
  L0057ff5f: { // 0x57ff5f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0057ff63: { // 0x57ff63: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057ff65: { // 0x57ff65: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0057ff69: { // 0x57ff69: 7505 JNZ 0x0057ff70
    if(integer::condition("JNZ",flags)) goto L0057ff70;
  }
  L0057ff6b: { // 0x57ff6b: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0057ff6e: { // 0x57ff6e: eb19 JMP 0x0057ff89
    goto L0057ff89;
  }
  L0057ff70: { // 0x57ff70: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0057ff73: { // 0x57ff73: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057ff7a: { // 0x57ff7a: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0057ff7d: { // 0x57ff7d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057ff7f: { // 0x57ff7f: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057ff82: { // 0x57ff82: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057ff85: { // 0x57ff85: 8b4c0838 MOV ECX,dword ptr [EAX + ECX*0x1 + 0x38]
    s.cx = m.r32((s.ax+(s.cx * 0x00000001u)+0x00000038u));
  }
  L0057ff89: { // 0x57ff89: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0057ff8b: { // 0x57ff8b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057ff8c: { // 0x57ff8c: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L0057ff90: { // 0x57ff90: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057ff92: { // 0x57ff92: e859520000 CALL 0x005851f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,5767063u); flags=s.arithmetic_flags;
  }
  L0057ff97: { // 0x57ff97: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057ff9c: { // 0x57ff9c: e8df72fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5767073u); flags=s.arithmetic_flags;
  }
  L0057ffa1: { // 0x57ffa1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0057ffa3: { // 0x57ffa3: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057ffa5: { // 0x57ffa5: 0f854efeffff JNZ 0x0057fdf9
    if(integer::condition("JNZ",flags)) goto L0057fdf9;
  }
  L0057ffab: { // 0x57ffab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057ffac: { // 0x57ffac: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057ffad: { // 0x57ffad: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057ffae: { // 0x57ffae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057ffaf: { // 0x57ffaf: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L0057ffb2: { // 0x57ffb2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
