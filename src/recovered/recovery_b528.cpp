#include "recovered/recovery_b528_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b528 {
namespace {
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b560(Memory&,State&,Frame&,const Operations&);
void f_0007b580(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4679360u:f_000766c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4699488u:f_0007b560(m,s,child,{});break;
case 4699520u:f_0007b580(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
default:throw std::domain_error("recovery528 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00562400(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00562400: { // 0x562400: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00562403: { // 0x562403: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00562407: { // 0x562407: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0056240b: { // 0x56240b: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0056240f: { // 0x56240f: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L00562412: { // 0x562412: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00562415: { // 0x562415: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00562417: { // 0x562417: 7818 JS 0x00562431
    if(integer::condition("JS",flags)) goto L00562431;
  }
  L00562419: { // 0x562419: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056241e: { // 0x56241e: 7d11 JGE 0x00562431
    if(integer::condition("JGE",flags)) goto L00562431;
  }
  L00562420: { // 0x562420: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00562426: { // 0x562426: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00562429: { // 0x562429: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056242b: { // 0x56242b: 7404 JZ 0x00562431
    if(integer::condition("JZ",flags)) goto L00562431;
  }
  L0056242d: { // 0x56242d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0056242f: { // 0x56242f: eb0c JMP 0x0056243d
    goto L0056243d;
  }
  L00562431: { // 0x562431: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00562433: { // 0x562433: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L00562438: { // 0x562438: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0056243d: { // 0x56243d: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L00562443: { // 0x562443: 8d9140010000 LEA EDX,[ECX + 0x140]
    s.dx = (s.cx+0x00000140u);
  }
  L00562449: { // 0x562449: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056244a: { // 0x56244a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0056244b: { // 0x56244b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056244c: { // 0x56244c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056244d: { // 0x56244d: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00562450: { // 0x562450: 7513 JNZ 0x00562465
    if(integer::condition("JNZ",flags)) goto L00562465;
  }
  L00562452: { // 0x562452: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00562456: { // 0x562456: 8b4924 MOV ECX,dword ptr [ECX + 0x24]
    s.cx = m.r32((s.cx+0x00000024u));
  }
  L00562459: { // 0x562459: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056245a: { // 0x56245a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056245b: { // 0x56245b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056245c: { // 0x56245c: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0056245e: { // 0x56245e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056245f: { // 0x56245f: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00562462: { // 0x562462: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00562465: { // 0x562465: 2500080000 AND EAX,0x800
    s.ax = integer::logical((s.ax)&(0x00000800u),32,flags);
  }
  L0056246a: { // 0x56246a: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0056246c: { // 0x56246c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0056246e: { // 0x56246e: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00562470: { // 0x562470: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00562472: { // 0x562472: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00562474: { // 0x562474: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00562478: { // 0x562478: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0056247b: { // 0x56247b: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0056247f: { // 0x56247f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00562481: { // 0x562481: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L00562486: { // 0x562486: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0056248a: { // 0x56248a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0056248e: { // 0x56248e: 8d6efc LEA EBP,[ESI + -0x4]
    s.bp = (s.si-0x00000004u);
  }
  L00562491: { // 0x562491: 83e507 AND EBP,0x7
    s.bp = integer::logical((s.bp)&(0x00000007u),32,flags);
  }
  L00562494: { // 0x562494: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00562498: { // 0x562498: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0056249a: { // 0x56249a: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0056249d: { // 0x56249d: 7445 JZ 0x005624e4
    if(integer::condition("JZ",flags)) goto L005624e4;
  }
  L0056249f: { // 0x56249f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005624a0: { // 0x5624a0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005624a2: { // 0x5624a2: e81942f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5645479u); flags=s.arithmetic_flags;
  }
  L005624a7: { // 0x5624a7: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005624a9: { // 0x5624a9: 8b8b40010000 MOV ECX,dword ptr [EBX + 0x140]
    s.cx = m.r32((s.bx+0x00000140u));
  }
  L005624af: { // 0x5624af: 8d8340010000 LEA EAX,[EBX + 0x140]
    s.ax = (s.bx+0x00000140u);
  }
  L005624b5: { // 0x5624b5: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005624b8: { // 0x5624b8: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005624bc: { // 0x5624bc: 7526 JNZ 0x005624e4
    if(integer::condition("JNZ",flags)) goto L005624e4;
  }
  L005624be: { // 0x5624be: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005624c0: { // 0x5624c0: e89b90f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5645509u); flags=s.arithmetic_flags;
  }
  L005624c5: { // 0x5624c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005624c7: { // 0x5624c7: 750b JNZ 0x005624d4
    if(integer::condition("JNZ",flags)) goto L005624d4;
  }
  L005624c9: { // 0x5624c9: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005624cb: { // 0x5624cb: e8b090f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5645520u); flags=s.arithmetic_flags;
  }
  L005624d0: { // 0x5624d0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005624d2: { // 0x5624d2: 7410 JZ 0x005624e4
    if(integer::condition("JZ",flags)) goto L005624e4;
  }
  L005624d4: { // 0x5624d4: 83bbec00000003 CMP dword ptr [EBX + 0xec],0x3
    (void)integer::sub(m.r32((s.bx+0x000000ecu)),0x00000003u,32,flags);
  }
  L005624db: { // 0x5624db: 7407 JZ 0x005624e4
    if(integer::condition("JZ",flags)) goto L005624e4;
  }
  L005624dd: { // 0x5624dd: 8b4324 MOV EAX,dword ptr [EBX + 0x24]
    s.ax = m.r32((s.bx+0x00000024u));
  }
  L005624e0: { // 0x5624e0: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L005624e4: { // 0x5624e4: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005624e8: { // 0x5624e8: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005624ea: { // 0x5624ea: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L005624ed: { // 0x5624ed: 7445 JZ 0x00562534
    if(integer::condition("JZ",flags)) goto L00562534;
  }
  L005624ef: { // 0x5624ef: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005624f0: { // 0x5624f0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005624f2: { // 0x5624f2: e8c941f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5645559u); flags=s.arithmetic_flags;
  }
  L005624f7: { // 0x5624f7: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005624f9: { // 0x5624f9: 8b8f40010000 MOV ECX,dword ptr [EDI + 0x140]
    s.cx = m.r32((s.di+0x00000140u));
  }
  L005624ff: { // 0x5624ff: 8d8740010000 LEA EAX,[EDI + 0x140]
    s.ax = (s.di+0x00000140u);
  }
  L00562505: { // 0x562505: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00562508: { // 0x562508: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0056250c: { // 0x56250c: 7526 JNZ 0x00562534
    if(integer::condition("JNZ",flags)) goto L00562534;
  }
  L0056250e: { // 0x56250e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00562510: { // 0x562510: e84b90f1ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5645589u); flags=s.arithmetic_flags;
  }
  L00562515: { // 0x562515: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00562517: { // 0x562517: 750b JNZ 0x00562524
    if(integer::condition("JNZ",flags)) goto L00562524;
  }
  L00562519: { // 0x562519: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0056251b: { // 0x56251b: e86090f1ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5645600u); flags=s.arithmetic_flags;
  }
  L00562520: { // 0x562520: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00562522: { // 0x562522: 7410 JZ 0x00562534
    if(integer::condition("JZ",flags)) goto L00562534;
  }
  L00562524: { // 0x562524: 83bfec00000003 CMP dword ptr [EDI + 0xec],0x3
    (void)integer::sub(m.r32((s.di+0x000000ecu)),0x00000003u,32,flags);
  }
  L0056252b: { // 0x56252b: 7407 JZ 0x00562534
    if(integer::condition("JZ",flags)) goto L00562534;
  }
  L0056252d: { // 0x56252d: 8b5724 MOV EDX,dword ptr [EDI + 0x24]
    s.dx = m.r32((s.di+0x00000024u));
  }
  L00562530: { // 0x562530: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00562534: { // 0x562534: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00562538: { // 0x562538: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0056253a: { // 0x56253a: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0056253d: { // 0x56253d: 0f8551ffffff JNZ 0x00562494
    if(integer::condition("JNZ",flags)) goto L00562494;
  }
  L00562543: { // 0x562543: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00562547: { // 0x562547: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00562549: { // 0x562549: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0056254c: { // 0x56254c: 0f8542ffffff JNZ 0x00562494
    if(integer::condition("JNZ",flags)) goto L00562494;
  }
  L00562552: { // 0x562552: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00562556: { // 0x562556: 8d5602 LEA EDX,[ESI + 0x2]
    s.dx = (s.si+0x00000002u);
  }
  L00562559: { // 0x562559: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0056255c: { // 0x56255c: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00562560: { // 0x562560: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L00562563: { // 0x562563: 8b6c2448 MOV EBP,dword ptr [ESP + 0x48]
    s.bp = m.r32((f.sp+0x00000048u));
  }
  L00562567: { // 0x562567: 66030c95a09d8300 ADD CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.dx * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L0056256f: { // 0x56256f: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L00562576: { // 0x562576: 668b542442 MOV DX,word ptr [ESP + 0x42]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000042u)));
  }
  L0056257b: { // 0x56257b: 83e607 AND ESI,0x7
    s.si = integer::logical((s.si)&(0x00000007u),32,flags);
  }
  L0056257e: { // 0x56257e: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L00562583: { // 0x562583: 668b4802 MOV CX,word ptr [EAX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.ax+0x00000002u)));
  }
  L00562587: { // 0x562587: 6603ca ADD CX,DX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.dx & 0xffffu),16,flags));
  }
  L0056258a: { // 0x56258a: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L0056258f: { // 0x56258f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00562593: { // 0x562593: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00562597: { // 0x562597: 8d0cb5a09d8300 LEA ECX,[ESI*0x4 + 0x839da0]
    s.cx = ((s.si * 0x00000004u)+0x00839da0u);
  }
  L0056259e: { // 0x56259e: 668b34b5a09d8300 MOV SI,word ptr [ESI*0x4 + 0x839da0]
    s.si = (s.si & 0xffff0000u) | ((m.r16(((s.si * 0x00000004u)+0x00839da0u))) & 0xffffu);
  }
  L005625a6: { // 0x5625a6: 6603742440 ADD SI,word ptr [ESP + 0x40]
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),m.r16((f.sp+0x00000040u)),16,flags)) & 0xffffu);
  }
  L005625ab: { // 0x5625ab: 6689742440 MOV word ptr [ESP + 0x40],SI
    m.w16((f.sp+0x00000040u), (s.si & 0xffffu));
  }
  L005625b0: { // 0x5625b0: 668b7102 MOV SI,word ptr [ECX + 0x2]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.cx+0x00000002u))) & 0xffffu);
  }
  L005625b4: { // 0x5625b4: 6603f2 ADD SI,DX
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),(s.dx & 0xffffu),16,flags)) & 0xffffu);
  }
  L005625b7: { // 0x5625b7: 6689742442 MOV word ptr [ESP + 0x42],SI
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L005625bc: { // 0x5625bc: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L005625c0: { // 0x5625c0: 668b30 MOV SI,word ptr [EAX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.ax))) & 0xffffu);
  }
  L005625c3: { // 0x5625c3: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L005625c7: { // 0x5625c7: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005625cb: { // 0x5625cb: 6603f2 ADD SI,DX
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),(s.dx & 0xffffu),16,flags)) & 0xffffu);
  }
  L005625ce: { // 0x5625ce: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005625d2: { // 0x5625d2: 6689742440 MOV word ptr [ESP + 0x40],SI
    m.w16((f.sp+0x00000040u), (s.si & 0xffffu));
  }
  L005625d7: { // 0x5625d7: 668b7002 MOV SI,word ptr [EAX + 0x2]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.ax+0x00000002u))) & 0xffffu);
  }
  L005625db: { // 0x5625db: 668b44241a MOV AX,word ptr [ESP + 0x1a]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000001au)));
  }
  L005625e0: { // 0x5625e0: 6603f0 ADD SI,AX
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),(s.ax & 0xffffu),16,flags)) & 0xffffu);
  }
  L005625e3: { // 0x5625e3: 6689742442 MOV word ptr [ESP + 0x42],SI
    m.w16((f.sp+0x00000042u), (s.si & 0xffffu));
  }
  L005625e8: { // 0x5625e8: 8b742440 MOV ESI,dword ptr [ESP + 0x40]
    s.si = m.r32((f.sp+0x00000040u));
  }
  L005625ec: { // 0x5625ec: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L005625f0: { // 0x5625f0: 668b31 MOV SI,word ptr [ECX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.cx))) & 0xffffu);
  }
  L005625f3: { // 0x5625f3: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L005625f7: { // 0x5625f7: 6603f2 ADD SI,DX
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),(s.dx & 0xffffu),16,flags)) & 0xffffu);
  }
  L005625fa: { // 0x5625fa: 6603c8 ADD CX,AX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L005625fd: { // 0x5625fd: 6689742440 MOV word ptr [ESP + 0x40],SI
    m.w16((f.sp+0x00000040u), (s.si & 0xffffu));
  }
  L00562602: { // 0x562602: 66894c2442 MOV word ptr [ESP + 0x42],CX
    m.w16((f.sp+0x00000042u), (s.cx & 0xffffu));
  }
  L00562607: { // 0x562607: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L0056260b: { // 0x56260b: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0056260f: { // 0x56260f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00562611: { // 0x562611: 8d742420 LEA ESI,[ESP + 0x20]
    s.si = (f.sp+0x00000020u);
  }
  L00562615: { // 0x562615: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00562617: { // 0x562617: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L0056261b: { // 0x56261b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0056261d: { // 0x56261d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056261e: { // 0x56261e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00562623: { // 0x562623: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L00562627: { // 0x562627: e8244effff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5645868u); flags=s.arithmetic_flags;
  }
  L0056262c: { // 0x56262c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056262e: { // 0x56262e: 7449 JZ 0x00562679
    if(integer::condition("JZ",flags)) goto L00562679;
  }
  L00562630: { // 0x562630: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00562634: { // 0x562634: 8b5c2440 MOV EBX,dword ptr [ESP + 0x40]
    s.bx = m.r32((f.sp+0x00000040u));
  }
  L00562638: { // 0x562638: 8b91f4000000 MOV EDX,dword ptr [ECX + 0xf4]
    s.dx = m.r32((s.cx+0x000000f4u));
  }
  L0056263e: { // 0x56263e: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L00562644: { // 0x562644: 8d440201 LEA EAX,[EDX + EAX*0x1 + 0x1]
    s.ax = (s.dx+(s.ax * 0x00000001u)+0x00000001u);
  }
  L00562648: { // 0x562648: 0fbf542442 MOVSX EDX,word ptr [ESP + 0x42]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000042u)),16));
  }
  L0056264d: { // 0x56264d: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00562650: { // 0x562650: 0fbfd3 MOVSX EDX,BX
    s.dx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00562653: { // 0x562653: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00562655: { // 0x562655: 7904 JNS 0x0056265b
    if(integer::condition("JNS",flags)) goto L0056265b;
  }
  L00562657: { // 0x562657: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00562659: { // 0x562659: eb0a JMP 0x00562665
    goto L00562665;
  }
  L0056265b: { // 0x56265b: 8b5168 MOV EDX,dword ptr [ECX + 0x68]
    s.dx = m.r32((s.cx+0x00000068u));
  }
  L0056265e: { // 0x56265e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00562660: { // 0x562660: 7c03 JL 0x00562665
    if(integer::condition("JL",flags)) goto L00562665;
  }
  L00562662: { // 0x562662: 8d42ff LEA EAX,[EDX + -0x1]
    s.ax = (s.dx-0x00000001u);
  }
  L00562665: { // 0x562665: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00562669: { // 0x562669: 8b496c MOV ECX,dword ptr [ECX + 0x6c]
    s.cx = m.r32((s.cx+0x0000006cu));
  }
  L0056266c: { // 0x56266c: 8d1482 LEA EDX,[EDX + EAX*0x4]
    s.dx = (s.dx+(s.ax * 0x00000004u));
  }
  L0056266f: { // 0x56266f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00562671: { // 0x562671: 0fbf1441 MOVSX EDX,word ptr [ECX + EAX*0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+(s.ax * 0x00000002u))),16));
  }
  L00562675: { // 0x562675: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L00562677: { // 0x562677: 741f JZ 0x00562698
    if(integer::condition("JZ",flags)) goto L00562698;
  }
  L00562679: { // 0x562679: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0056267a: { // 0x56267a: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0056267d: { // 0x56267d: 83ff06 CMP EDI,0x6
    (void)integer::sub(s.di,0x00000006u,32,flags);
  }
  L00562680: { // 0x562680: 7c93 JL 0x00562615
    if(integer::condition("JL",flags)) goto L00562615;
  }
  L00562682: { // 0x562682: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00562686: { // 0x562686: 8b0d5c6ea500 MOV ECX,dword ptr [0x00a56e5c]
    s.cx = m.r32((0x00a56e5cu));
  }
  L0056268c: { // 0x56268c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056268d: { // 0x56268d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056268e: { // 0x56268e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056268f: { // 0x56268f: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00562691: { // 0x562691: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00562692: { // 0x562692: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00562695: { // 0x562695: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00562698: { // 0x562698: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0056269c: { // 0x56269c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056269d: { // 0x56269d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056269e: { // 0x56269e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0056269f: { // 0x56269f: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L005626a1: { // 0x5626a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005626a2: { // 0x5626a2: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L005626a5: { // 0x5626a5: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
