#include "recovered/recovery_b587_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b587 {
namespace {
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_00023b90(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_00023b90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00423b90: { // 0x423b90: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00423b94: { // 0x423b94: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00423b97: { // 0x423b97: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00423b98: { // 0x423b98: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00423b9a: { // 0x423b9a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00423b9b: { // 0x423b9b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00423b9c: { // 0x423b9c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00423ba1: { // 0x423ba1: e85a191200 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4340646u); flags=s.arithmetic_flags;
  }
  L00423ba6: { // 0x423ba6: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L00423bac: { // 0x423bac: 8b15484a8300 MOV EDX,dword ptr [0x00834a48]
    s.dx = m.r32((0x00834a48u));
  }
  L00423bb2: { // 0x423bb2: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00423bb5: { // 0x423bb5: 7440 JZ 0x00423bf7
    if(integer::condition("JZ",flags)) goto L00423bf7;
  }
  L00423bb7: { // 0x423bb7: 8d8e88000000 LEA ECX,[ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L00423bbd: { // 0x423bbd: 8bbe88000000 MOV EDI,dword ptr [ESI + 0x88]
    s.di = m.r32((s.si+0x00000088u));
  }
  L00423bc3: { // 0x423bc3: 897c2408 MOV dword ptr [ESP + 0x8],EDI
    m.w32((f.sp+0x00000008u), s.di);
  }
  L00423bc7: { // 0x423bc7: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L00423bca: { // 0x423bca: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L00423bce: { // 0x423bce: 0fbeb81b010000 MOVSX EDI,byte ptr [EAX + 0x11b]
    s.di = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L00423bd5: { // 0x423bd5: 0faffa IMUL EDI,EDX
    s.di = integer::imul(s.di,s.dx,32,flags);
  }
  L00423bd8: { // 0x423bd8: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L00423bdb: { // 0x423bdb: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00423bdd: { // 0x423bdd: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L00423be0: { // 0x423be0: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L00423be2: { // 0x423be2: 7e13 JLE 0x00423bf7
    if(integer::condition("JLE",flags)) goto L00423bf7;
  }
  L00423be4: { // 0x423be4: f68028010000e0 TEST byte ptr [EAX + 0x128],0xe0
    (void)integer::logical((m.r8((s.ax+0x00000128u)))&(0x000000e0u),8,flags);
  }
  L00423beb: { // 0x423beb: 746e JZ 0x00423c5b
    if(integer::condition("JZ",flags)) goto L00423c5b;
  }
  L00423bed: { // 0x423bed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00423bee: { // 0x423bee: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00423bf0: { // 0x423bf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00423bf1: { // 0x423bf1: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00423bf4: { // 0x423bf4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00423bf7: { // 0x423bf7: 8b88ec000000 MOV ECX,dword ptr [EAX + 0xec]
    s.cx = m.r32((s.ax+0x000000ecu));
  }
  L00423bfd: { // 0x423bfd: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00423c00: { // 0x423c00: 74eb JZ 0x00423bed
    if(integer::condition("JZ",flags)) goto L00423bed;
  }
  L00423c02: { // 0x423c02: 83f90a CMP ECX,0xa
    (void)integer::sub(s.cx,0x0000000au,32,flags);
  }
  L00423c05: { // 0x423c05: 74e6 JZ 0x00423bed
    if(integer::condition("JZ",flags)) goto L00423bed;
  }
  L00423c07: { // 0x423c07: 83f904 CMP ECX,0x4
    (void)integer::sub(s.cx,0x00000004u,32,flags);
  }
  L00423c0a: { // 0x423c0a: 74e1 JZ 0x00423bed
    if(integer::condition("JZ",flags)) goto L00423bed;
  }
  L00423c0c: { // 0x423c0c: 8b4844 MOV ECX,dword ptr [EAX + 0x44]
    s.cx = m.r32((s.ax+0x00000044u));
  }
  L00423c0f: { // 0x423c0f: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L00423c12: { // 0x423c12: 7415 JZ 0x00423c29
    if(integer::condition("JZ",flags)) goto L00423c29;
  }
  L00423c14: { // 0x423c14: 8b3d1ce1a100 MOV EDI,dword ptr [0x00a1e11c]
    s.di = m.r32((0x00a1e11cu));
  }
  L00423c1a: { // 0x423c1a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00423c1b: { // 0x423c1b: 8b0c8f MOV ECX,dword ptr [EDI + ECX*0x4]
    s.cx = m.r32((s.di+(s.cx * 0x00000004u)));
  }
  L00423c1e: { // 0x423c1e: 8a9978020000 MOV BL,byte ptr [ECX + 0x278]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000278u)));
  }
  L00423c24: { // 0x423c24: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00423c26: { // 0x423c26: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00423c27: { // 0x423c27: 75c4 JNZ 0x00423bed
    if(integer::condition("JNZ",flags)) goto L00423bed;
  }
  L00423c29: { // 0x423c29: f68024010000e0 TEST byte ptr [EAX + 0x124],0xe0
    (void)integer::logical((m.r8((s.ax+0x00000124u)))&(0x000000e0u),8,flags);
  }
  L00423c30: { // 0x423c30: 75bb JNZ 0x00423bed
    if(integer::condition("JNZ",flags)) goto L00423bed;
  }
  L00423c32: { // 0x423c32: 0fbe801b010000 MOVSX EAX,byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L00423c39: { // 0x423c39: 81c688000000 ADD ESI,0x88
    s.si = integer::add(s.si,0x00000088u,32,flags);
  }
  L00423c3f: { // 0x423c3f: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00423c42: { // 0x423c42: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00423c44: { // 0x423c44: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L00423c48: { // 0x423c48: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00423c4b: { // 0x423c4b: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00423c4f: { // 0x423c4f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00423c52: { // 0x423c52: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00423c54: { // 0x423c54: 8d0c12 LEA ECX,[EDX + EDX*0x1]
    s.cx = (s.dx+(s.dx * 0x00000001u));
  }
  L00423c57: { // 0x423c57: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00423c59: { // 0x423c59: 7f92 JG 0x00423bed
    if(integer::condition("JG",flags)) goto L00423bed;
  }
  L00423c5b: { // 0x423c5b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00423c5c: { // 0x423c5c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00423c5e: { // 0x423c5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00423c5f: { // 0x423c5f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00423c62: { // 0x423c62: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5600336u:f_00157450(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 4340624u:f_00023b90(m,s,child,{});break;
default:throw std::domain_error("recovery587 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004237b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004237b0: { // 0x4237b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004237b1: { // 0x4237b1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L004237b3: { // 0x4237b3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004237b6: { // 0x4237b6: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L004237b9: { // 0x4237b9: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L004237bd: { // 0x4237bd: 81c188000000 ADD ECX,0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L004237c3: { // 0x4237c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004237c4: { // 0x4237c4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004237c5: { // 0x4237c5: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004237c7: { // 0x4237c7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004237c8: { // 0x4237c8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004237c9: { // 0x4237c9: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L004237cc: { // 0x4237cc: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004237d2: { // 0x4237d2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004237d4: { // 0x4237d4: c744242410270000 MOV dword ptr [ESP + 0x24],0x2710
    m.w32((f.sp+0x00000024u), 0x00002710u);
  }
  L004237dc: { // 0x4237dc: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L004237df: { // 0x4237df: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L004237e3: { // 0x4237e3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004237e5: { // 0x4237e5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004237e7: { // 0x4237e7: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004237ea: { // 0x4237ea: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004237eb: { // 0x4237eb: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L004237ee: { // 0x4237ee: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004237f4: { // 0x4237f4: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L004237f9: { // 0x4237f9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004237fb: { // 0x4237fb: 8b15ec498300 MOV EDX,dword ptr [0x008349ec]
    s.dx = m.r32((0x008349ecu));
  }
  L00423801: { // 0x423801: 8d7efb LEA EDI,[ESI + -0x5]
    s.di = (s.si-0x00000005u);
  }
  L00423804: { // 0x423804: 8d4e05 LEA ECX,[ESI + 0x5]
    s.cx = (s.si+0x00000005u);
  }
  L00423807: { // 0x423807: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0042380a: { // 0x42380a: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0042380c: { // 0x42380c: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L00423811: { // 0x423811: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00423815: { // 0x423815: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L00423819: { // 0x423819: 0f8d8a020000 JGE 0x00423aa9
    if(integer::condition("JGE",flags)) goto L00423aa9;
  }
  L0042381f: { // 0x42381f: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00423822: { // 0x423822: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L00423826: { // 0x423826: 8d4205 LEA EAX,[EDX + 0x5]
    s.ax = (s.dx+0x00000005u);
  }
  L00423829: { // 0x423829: 8d5afb LEA EBX,[EDX + -0x5]
    s.bx = (s.dx-0x00000005u);
  }
  L0042382c: { // 0x42382c: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0042382e: { // 0x42382e: 0f8d26010000 JGE 0x0042395a
    if(integer::condition("JGE",flags)) goto L0042395a;
  }
  L00423834: { // 0x423834: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00423838: { // 0x423838: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0042383a: { // 0x42383a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042383b: { // 0x42383b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00423840: { // 0x423840: 66897c2424 MOV word ptr [ESP + 0x24],DI
    m.w16((f.sp+0x00000024u), (s.di & 0xffffu));
  }
  L00423845: { // 0x423845: 66895c2426 MOV word ptr [ESP + 0x26],BX
    m.w16((f.sp+0x00000026u), (s.bx & 0xffffu));
  }
  L0042384a: { // 0x42384a: e8013c1300 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4339791u); flags=s.arithmetic_flags;
  }
  L0042384f: { // 0x42384f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00423851: { // 0x423851: 0f84f1000000 JZ 0x00423948
    if(integer::condition("JZ",flags)) goto L00423948;
  }
  L00423857: { // 0x423857: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0042385b: { // 0x42385b: 66897c2420 MOV word ptr [ESP + 0x20],DI
    m.w16((f.sp+0x00000020u), (s.di & 0xffffu));
  }
  L00423860: { // 0x423860: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00423861: { // 0x423861: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00423866: { // 0x423866: 66895c2426 MOV word ptr [ESP + 0x26],BX
    m.w16((f.sp+0x00000026u), (s.bx & 0xffffu));
  }
  L0042386b: { // 0x42386b: e8901c1200 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4339824u); flags=s.arithmetic_flags;
  }
  L00423870: { // 0x423870: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00423872: { // 0x423872: 83beec00000002 CMP dword ptr [ESI + 0xec],0x2
    (void)integer::sub(m.r32((s.si+0x000000ecu)),0x00000002u,32,flags);
  }
  L00423879: { // 0x423879: 0f85c5000000 JNZ 0x00423944
    if(integer::condition("JNZ",flags)) goto L00423944;
  }
  L0042387f: { // 0x42387f: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L00423885: { // 0x423885: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00423888: { // 0x423888: 0f85b6000000 JNZ 0x00423944
    if(integer::condition("JNZ",flags)) goto L00423944;
  }
  L0042388e: { // 0x42388e: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  L00423890: { // 0x423890: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00423892: { // 0x423892: e8292e0500 CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,4339863u); flags=s.arithmetic_flags;
  }
  L00423897: { // 0x423897: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0042389d: { // 0x42389d: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004238a0: { // 0x4238a0: 0f859e000000 JNZ 0x00423944
    if(integer::condition("JNZ",flags)) goto L00423944;
  }
  L004238a6: { // 0x4238a6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004238a8: { // 0x4238a8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004238aa: { // 0x4238aa: e8112e0500 CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,4339887u); flags=s.arithmetic_flags;
  }
  L004238af: { // 0x4238af: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L004238b5: { // 0x4238b5: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004238b8: { // 0x4238b8: 0f8586000000 JNZ 0x00423944
    if(integer::condition("JNZ",flags)) goto L00423944;
  }
  L004238be: { // 0x4238be: 668b54242c MOV DX,word ptr [ESP + 0x2c]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000002cu)));
  }
  L004238c3: { // 0x4238c3: 66395624 CMP word ptr [ESI + 0x24],DX
    (void)integer::sub(m.r16((s.si+0x00000024u)),(s.dx & 0xffffu),16,flags);
  }
  L004238c7: { // 0x4238c7: 750b JNZ 0x004238d4
    if(integer::condition("JNZ",flags)) goto L004238d4;
  }
  L004238c9: { // 0x4238c9: 668b44242e MOV AX,word ptr [ESP + 0x2e]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002eu)));
  }
  L004238ce: { // 0x4238ce: 66394626 CMP word ptr [ESI + 0x26],AX
    (void)integer::sub(m.r16((s.si+0x00000026u)),(s.ax & 0xffffu),16,flags);
  }
  L004238d2: { // 0x4238d2: 7443 JZ 0x00423917
    if(integer::condition("JZ",flags)) goto L00423917;
  }
  L004238d4: { // 0x4238d4: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L004238d8: { // 0x4238d8: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004238dc: { // 0x4238dc: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L004238de: { // 0x4238de: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004238e0: { // 0x4238e0: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L004238e2: { // 0x4238e2: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L004238e4: { // 0x4238e4: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L004238e8: { // 0x4238e8: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L004238ec: { // 0x4238ec: db442438 FILD dword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load_integer32(m.r32(address));
  }
  L004238f0: { // 0x4238f0: db442434 FILD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L004238f4: { // 0x4238f4: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004238f7: { // 0x4238f7: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004238f9: { // 0x4238f9: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004238fb: { // 0x4238fb: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004238fd: { // 0x4238fd: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004238ff: { // 0x4238ff: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00423901: { // 0x423901: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00423904: { // 0x423904: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00423906: { // 0x423906: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00423908: { // 0x423908: e873670900 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4339981u); flags=s.arithmetic_flags;
  }
  L0042390d: { // 0x42390d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00423910: { // 0x423910: e83b713400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4339989u); flags=s.arithmetic_flags;
  }
  L00423915: { // 0x423915: eb02 JMP 0x00423919
    goto L00423919;
  }
  L00423917: { // 0x423917: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00423919: { // 0x423919: 3b7c2410 CMP EDI,dword ptr [ESP + 0x10]
    (void)integer::sub(s.di,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0042391d: { // 0x42391d: 7f06 JG 0x00423925
    if(integer::condition("JG",flags)) goto L00423925;
  }
  L0042391f: { // 0x42391f: 3b5c240c CMP EBX,dword ptr [ESP + 0xc]
    (void)integer::sub(s.bx,m.r32((f.sp+0x0000000cu)),32,flags);
  }
  L00423923: { // 0x423923: 7e03 JLE 0x00423928
    if(integer::condition("JLE",flags)) goto L00423928;
  }
  L00423925: { // 0x423925: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00423928: { // 0x423928: 3b442424 CMP EAX,dword ptr [ESP + 0x24]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L0042392c: { // 0x42392c: 7d16 JGE 0x00423944
    if(integer::condition("JGE",flags)) goto L00423944;
  }
  L0042392e: { // 0x42392e: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00423932: { // 0x423932: 66897c2428 MOV word ptr [ESP + 0x28],DI
    m.w16((f.sp+0x00000028u), (s.di & 0xffffu));
  }
  L00423937: { // 0x423937: 66895c242a MOV word ptr [ESP + 0x2a],BX
    m.w16((f.sp+0x0000002au), (s.bx & 0xffffu));
  }
  L0042393c: { // 0x42393c: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00423940: { // 0x423940: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00423944: { // 0x423944: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00423948: { // 0x423948: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0042394c: { // 0x42394c: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0042394d: { // 0x42394d: 8d4105 LEA EAX,[ECX + 0x5]
    s.ax = (s.cx+0x00000005u);
  }
  L00423950: { // 0x423950: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00423952: { // 0x423952: 0f8cdcfeffff JL 0x00423834
    if(integer::condition("JL",flags)) goto L00423834;
  }
  L00423958: { // 0x423958: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0042395a: { // 0x42395a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0042395b: { // 0x42395b: 8d4e05 LEA ECX,[ESI + 0x5]
    s.cx = (s.si+0x00000005u);
  }
  L0042395e: { // 0x42395e: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00423960: { // 0x423960: 0f8cc3feffff JL 0x00423829
    if(integer::condition("JL",flags)) goto L00423829;
  }
  L00423966: { // 0x423966: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0042396a: { // 0x42396a: 668b4c241a MOV CX,word ptr [ESP + 0x1a]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000001au)));
  }
  L0042396f: { // 0x42396f: 663b05ec498300 CMP AX,word ptr [0x008349ec]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x008349ecu)),16,flags);
  }
  L00423976: { // 0x423976: 750d JNZ 0x00423985
    if(integer::condition("JNZ",flags)) goto L00423985;
  }
  L00423978: { // 0x423978: 663b0dee498300 CMP CX,word ptr [0x008349ee]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x008349eeu)),16,flags);
  }
  L0042397f: { // 0x42397f: 0f8424010000 JZ 0x00423aa9
    if(integer::condition("JZ",flags)) goto L00423aa9;
  }
  L00423985: { // 0x423985: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00423988: { // 0x423988: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0042398b: { // 0x42398b: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0042398d: { // 0x42398d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0042398f: { // 0x42398f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00423991: { // 0x423991: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00423993: { // 0x423993: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00423995: { // 0x423995: 7d05 JGE 0x0042399c
    if(integer::condition("JGE",flags)) goto L0042399c;
  }
  L00423997: { // 0x423997: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L0042399a: { // 0x42399a: eb07 JMP 0x004239a3
    goto L004239a3;
  }
  L0042399c: { // 0x42399c: 7e05 JLE 0x004239a3
    if(integer::condition("JLE",flags)) goto L004239a3;
  }
  L0042399e: { // 0x42399e: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L004239a3: { // 0x4239a3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004239a5: { // 0x4239a5: 7d05 JGE 0x004239ac
    if(integer::condition("JGE",flags)) goto L004239ac;
  }
  L004239a7: { // 0x4239a7: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004239aa: { // 0x4239aa: eb07 JMP 0x004239b3
    goto L004239b3;
  }
  L004239ac: { // 0x4239ac: 7e05 JLE 0x004239b3
    if(integer::condition("JLE",flags)) goto L004239b3;
  }
  L004239ae: { // 0x4239ae: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004239b3: { // 0x4239b3: 8b4c242e MOV ECX,dword ptr [ESP + 0x2e]
    s.cx = m.r32((f.sp+0x0000002eu));
  }
  L004239b7: { // 0x4239b7: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L004239bb: { // 0x4239bb: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L004239bd: { // 0x4239bd: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L004239c1: { // 0x4239c1: 8d1c0a LEA EBX,[EDX + ECX*0x1]
    s.bx = (s.dx+(s.cx * 0x00000001u));
  }
  L004239c4: { // 0x4239c4: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004239c8: { // 0x4239c8: 66897c2428 MOV word ptr [ESP + 0x28],DI
    m.w16((f.sp+0x00000028u), (s.di & 0xffffu));
  }
  L004239cd: { // 0x4239cd: 66895c242a MOV word ptr [ESP + 0x2a],BX
    m.w16((f.sp+0x0000002au), (s.bx & 0xffffu));
  }
  L004239d2: { // 0x4239d2: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L004239d6: { // 0x4239d6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004239d7: { // 0x4239d7: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L004239db: { // 0x4239db: e8b0010000 CALL 0x00423b90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00423b90u,4340192u); flags=s.arithmetic_flags;
  }
  L004239e0: { // 0x4239e0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004239e2: { // 0x4239e2: 7414 JZ 0x004239f8
    if(integer::condition("JZ",flags)) goto L004239f8;
  }
  L004239e4: { // 0x4239e4: 0fbfcf MOVSX ECX,DI
    s.cx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L004239e7: { // 0x4239e7: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L004239ea: { // 0x4239ea: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L004239f0: { // 0x4239f0: 0fbfd3 MOVSX EDX,BX
    s.dx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L004239f3: { // 0x4239f3: e973010000 JMP 0x00423b6b
    goto L00423b6b;
  }
  L004239f8: { // 0x4239f8: 668b4c242e MOV CX,word ptr [ESP + 0x2e]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000002eu)));
  }
  L004239fd: { // 0x4239fd: 66897c2428 MOV word ptr [ESP + 0x28],DI
    m.w16((f.sp+0x00000028u), (s.di & 0xffffu));
  }
  L00423a02: { // 0x423a02: 66894c242a MOV word ptr [ESP + 0x2a],CX
    m.w16((f.sp+0x0000002au), (s.cx & 0xffffu));
  }
  L00423a07: { // 0x423a07: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00423a0b: { // 0x423a0b: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00423a0f: { // 0x423a0f: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00423a13: { // 0x423a13: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00423a14: { // 0x423a14: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00423a18: { // 0x423a18: e873010000 CALL 0x00423b90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00423b90u,4340253u); flags=s.arithmetic_flags;
  }
  L00423a1d: { // 0x423a1d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00423a1f: { // 0x423a1f: 7432 JZ 0x00423a53
    if(integer::condition("JZ",flags)) goto L00423a53;
  }
  L00423a21: { // 0x423a21: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L00423a24: { // 0x423a24: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00423a28: { // 0x423a28: 0fbfcf MOVSX ECX,DI
    s.cx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L00423a2b: { // 0x423a2b: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00423a2e: { // 0x423a2e: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L00423a30: { // 0x423a30: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00423a36: { // 0x423a36: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00423a39: { // 0x423a39: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L00423a3b: { // 0x423a3b: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00423a40: { // 0x423a40: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00423a42: { // 0x423a42: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00423a45: { // 0x423a45: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00423a47: { // 0x423a47: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00423a4a: { // 0x423a4a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00423a4b: { // 0x423a4b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00423a4c: { // 0x423a4c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00423a4d: { // 0x423a4d: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00423a4f: { // 0x423a4f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00423a50: { // 0x423a50: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00423a53: { // 0x423a53: 668b4c242c MOV CX,word ptr [ESP + 0x2c]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000002cu)));
  }
  L00423a58: { // 0x423a58: 66895c242a MOV word ptr [ESP + 0x2a],BX
    m.w16((f.sp+0x0000002au), (s.bx & 0xffffu));
  }
  L00423a5d: { // 0x423a5d: 66894c2428 MOV word ptr [ESP + 0x28],CX
    m.w16((f.sp+0x00000028u), (s.cx & 0xffffu));
  }
  L00423a62: { // 0x423a62: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00423a66: { // 0x423a66: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00423a6a: { // 0x423a6a: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00423a6e: { // 0x423a6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00423a6f: { // 0x423a6f: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00423a73: { // 0x423a73: e818010000 CALL 0x00423b90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00423b90u,4340344u); flags=s.arithmetic_flags;
  }
  L00423a78: { // 0x423a78: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00423a7a: { // 0x423a7a: 742d JZ 0x00423aa9
    if(integer::condition("JZ",flags)) goto L00423aa9;
  }
  L00423a7c: { // 0x423a7c: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00423a7f: { // 0x423a7f: 0fbfcb MOVSX ECX,BX
    s.cx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00423a82: { // 0x423a82: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  L00423a85: { // 0x423a85: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00423a87: { // 0x423a87: 81c680000000 ADD ESI,0x80
    s.si = integer::add(s.si,0x00000080u,32,flags);
  }
  L00423a8d: { // 0x423a8d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00423a90: { // 0x423a90: 8937 MOV dword ptr [EDI],ESI
    m.w32((s.di), s.si);
  }
  L00423a92: { // 0x423a92: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00423a98: { // 0x423a98: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00423a9a: { // 0x423a9a: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
  L00423a9d: { // 0x423a9d: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00423aa0: { // 0x423aa0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00423aa1: { // 0x423aa1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00423aa2: { // 0x423aa2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00423aa3: { // 0x423aa3: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00423aa5: { // 0x423aa5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00423aa6: { // 0x423aa6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00423aa9: { // 0x423aa9: 66833dec49830000 CMP word ptr [0x008349ec],0x0
    (void)integer::sub(m.r16((0x008349ecu)),0x00000000u,16,flags);
  }
  L00423ab1: { // 0x423ab1: 757d JNZ 0x00423b30
    if(integer::condition("JNZ",flags)) goto L00423b30;
  }
  L00423ab3: { // 0x423ab3: 66833dee49830000 CMP word ptr [0x008349ee],0x0
    (void)integer::sub(m.r16((0x008349eeu)),0x00000000u,16,flags);
  }
  L00423abb: { // 0x423abb: 7573 JNZ 0x00423b30
    if(integer::condition("JNZ",flags)) goto L00423b30;
  }
  L00423abd: { // 0x423abd: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00423ac3: { // 0x423ac3: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00423ac5: { // 0x423ac5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00423ac7: { // 0x423ac7: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00423acd: { // 0x423acd: e86ec32000 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4340434u); flags=s.arithmetic_flags;
  }
  L00423ad2: { // 0x423ad2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00423ad4: { // 0x423ad4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00423ad6: { // 0x423ad6: 8d143e LEA EDX,[ESI + EDI*0x1]
    s.dx = (s.si+(s.di * 0x00000001u));
  }
  L00423ad9: { // 0x423ad9: 81e207000080 AND EDX,0x80000007
    s.dx = integer::logical((s.dx)&(0x80000007u),32,flags);
  }
  L00423adf: { // 0x423adf: 7905 JNS 0x00423ae6
    if(integer::condition("JNS",flags)) goto L00423ae6;
  }
  L00423ae1: { // 0x423ae1: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00423ae2: { // 0x423ae2: 83caf8 OR EDX,0xfffffff8
    s.dx = integer::logical((s.dx)|(0xfffffff8u),32,flags);
  }
  L00423ae5: { // 0x423ae5: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00423ae6: { // 0x423ae6: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L00423ae9: { // 0x423ae9: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L00423af1: { // 0x423af1: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L00423af8: { // 0x423af8: 66034c242c ADD CX,word ptr [ESP + 0x2c]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000002cu)),16,flags));
  }
  L00423afd: { // 0x423afd: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L00423b01: { // 0x423b01: 660354242e ADD DX,word ptr [ESP + 0x2e]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x0000002eu)),16,flags));
  }
  L00423b06: { // 0x423b06: 66894c2428 MOV word ptr [ESP + 0x28],CX
    m.w16((f.sp+0x00000028u), (s.cx & 0xffffu));
  }
  L00423b0b: { // 0x423b0b: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00423b0f: { // 0x423b0f: 668954242a MOV word ptr [ESP + 0x2a],DX
    m.w16((f.sp+0x0000002au), (s.dx & 0xffffu));
  }
  L00423b14: { // 0x423b14: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00423b18: { // 0x423b18: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00423b19: { // 0x423b19: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00423b1d: { // 0x423b1d: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00423b21: { // 0x423b21: e86a000000 CALL 0x00423b90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00423b90u,4340518u); flags=s.arithmetic_flags;
  }
  L00423b26: { // 0x423b26: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00423b28: { // 0x423b28: 752e JNZ 0x00423b58
    if(integer::condition("JNZ",flags)) goto L00423b58;
  }
  L00423b2a: { // 0x423b2a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00423b2b: { // 0x423b2b: 83fe08 CMP ESI,0x8
    (void)integer::sub(s.si,0x00000008u,32,flags);
  }
  L00423b2e: { // 0x423b2e: 7ca6 JL 0x00423ad6
    if(integer::condition("JL",flags)) goto L00423ad6;
  }
  L00423b30: { // 0x423b30: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00423b33: { // 0x423b33: 8b0d104a8300 MOV ECX,dword ptr [0x00834a10]
    s.cx = m.r32((0x00834a10u));
  }
  L00423b39: { // 0x423b39: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00423b3b: { // 0x423b3b: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00423b3d: { // 0x423b3d: 8b0d144a8300 MOV ECX,dword ptr [0x00834a14]
    s.cx = m.r32((0x00834a14u));
  }
  L00423b43: { // 0x423b43: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00423b46: { // 0x423b46: 8b0d184a8300 MOV ECX,dword ptr [0x00834a18]
    s.cx = m.r32((0x00834a18u));
  }
  L00423b4c: { // 0x423b4c: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00423b4f: { // 0x423b4f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00423b50: { // 0x423b50: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00423b51: { // 0x423b51: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00423b52: { // 0x423b52: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00423b54: { // 0x423b54: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00423b55: { // 0x423b55: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00423b58: { // 0x423b58: 0fbf4c2418 MOVSX ECX,word ptr [ESP + 0x18]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  L00423b5d: { // 0x423b5d: 0fbf54241a MOVSX EDX,word ptr [ESP + 0x1a]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001au)),16));
  }
  L00423b62: { // 0x423b62: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00423b65: { // 0x423b65: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00423b6b: { // 0x423b6b: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00423b6e: { // 0x423b6e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00423b70: { // 0x423b70: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00423b73: { // 0x423b73: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L00423b75: { // 0x423b75: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L00423b7b: { // 0x423b7b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00423b7d: { // 0x423b7d: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L00423b80: { // 0x423b80: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  L00423b83: { // 0x423b83: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00423b84: { // 0x423b84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00423b85: { // 0x423b85: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00423b86: { // 0x423b86: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00423b88: { // 0x423b88: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00423b89: { // 0x423b89: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
