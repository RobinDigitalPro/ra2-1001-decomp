#include "recovered/recovery_b219_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b219 {
namespace {
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00071260(Memory&,State&,Frame&,const Operations&);
void f_0001b320(Memory&,State&,Frame&,const Operations&);
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
void f_00071260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00471260: { // 0x471260: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00471261: { // 0x471261: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00471263: { // 0x471263: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00471266: { // 0x471266: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00471269: { // 0x471269: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0047126c: { // 0x47126c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047126d: { // 0x47126d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047126e: { // 0x47126e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047126f: { // 0x47126f: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00471271: { // 0x471271: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00471273: { // 0x471273: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471277: { // 0x471277: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0047127b: { // 0x47127b: 8d3cc500000000 LEA EDI,[EAX*0x8 + 0x0]
    s.di = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L00471282: { // 0x471282: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00471284: { // 0x471284: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00471287: { // 0x471287: 8d1cc500000000 LEA EBX,[EAX*0x8 + 0x0]
    s.bx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L0047128e: { // 0x47128e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00471290: { // 0x471290: 8a450c MOV AL,byte ptr [EBP + 0xc]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000000cu)));
  }
  L00471293: { // 0x471293: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471295: { // 0x471295: 7408 JZ 0x0047129f
    if(integer::condition("JZ",flags)) goto L0047129f;
  }
  L00471297: { // 0x471297: 8b89e8000000 MOV ECX,dword ptr [ECX + 0xe8]
    s.cx = m.r32((s.cx+0x000000e8u));
  }
  L0047129d: { // 0x47129d: eb06 JMP 0x004712a5
    goto L004712a5;
  }
  L0047129f: { // 0x47129f: 8b89e4000000 MOV ECX,dword ptr [ECX + 0xe4]
    s.cx = m.r32((s.cx+0x000000e4u));
  }
  L004712a5: { // 0x4712a5: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L004712a7: { // 0x4712a7: 0f84a2000000 JZ 0x0047134f
    if(integer::condition("JZ",flags)) goto L0047134f;
  }
  L004712ad: { // 0x4712ad: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004712af: { // 0x4712af: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004712b1: { // 0x4712b1: 0f8480000000 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712b7: { // 0x4712b7: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L004712ba: { // 0x4712ba: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L004712bc: { // 0x4712bc: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L004712c0: { // 0x4712c0: 7475 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c2: { // 0x4712c2: 3b7510 CMP ESI,dword ptr [EBP + 0x10]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  L004712c5: { // 0x4712c5: 7470 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c7: { // 0x4712c7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004712c9: { // 0x4712c9: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L004712cd: { // 0x4712cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004712ce: { // 0x4712ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004712d0: { // 0x4712d0: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4657875u); flags=s.arithmetic_flags;
  }
  L004712d3: { // 0x4712d3: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004712d5: { // 0x4712d5: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004712d8: { // 0x4712d8: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004712da: { // 0x4712da: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004712df: { // 0x4712df: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L004712e2: { // 0x4712e2: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004712e4: { // 0x4712e4: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004712ea: { // 0x4712ea: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004712ee: { // 0x4712ee: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L004712f0: { // 0x4712f0: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L004712f3: { // 0x4712f3: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L004712f7: { // 0x4712f7: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L004712fb: { // 0x4712fb: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L004712ff: { // 0x4712ff: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00471303: { // 0x471303: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00471305: { // 0x471305: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00471307: { // 0x471307: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00471309: { // 0x471309: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0047130b: { // 0x47130b: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0047130d: { // 0x47130d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00471310: { // 0x471310: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471312: { // 0x471312: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471314: { // 0x471314: e8678d0400 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4657945u); flags=s.arithmetic_flags;
  }
  L00471319: { // 0x471319: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047131c: { // 0x47131c: e82f972f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4657953u); flags=s.arithmetic_flags;
  }
  L00471321: { // 0x471321: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00471325: { // 0x471325: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00471327: { // 0x471327: 7406 JZ 0x0047132f
    if(integer::condition("JZ",flags)) goto L0047132f;
  }
  L00471329: { // 0x471329: 3b442418 CMP EAX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0047132d: { // 0x47132d: 7d08 JGE 0x00471337
    if(integer::condition("JGE",flags)) goto L00471337;
  }
  L0047132f: { // 0x47132f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471333: { // 0x471333: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00471337: { // 0x471337: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047133a: { // 0x47133a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047133c: { // 0x47133c: 0f8575ffffff JNZ 0x004712b7
    if(integer::condition("JNZ",flags)) goto L004712b7;
  }
  L00471342: { // 0x471342: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00471346: { // 0x471346: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471347: { // 0x471347: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471348: { // 0x471348: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471349: { // 0x471349: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0047134b: { // 0x47134b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047134c: { // 0x47134c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047134f: { // 0x47134f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00471351: { // 0x471351: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471352: { // 0x471352: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471353: { // 0x471353: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471354: { // 0x471354: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00471356: { // 0x471356: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471357: { // 0x471357: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0001b320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b320: { // 0x41b320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041b321: { // 0x41b321: 8b8188000000 MOV EAX,dword ptr [ECX + 0x88]
    s.ax = m.r32((s.cx+0x00000088u));
  }
  L0041b327: { // 0x41b327: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b328: { // 0x41b328: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b32e: { // 0x41b32e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b330: { // 0x41b330: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b333: { // 0x41b333: 6689442400 MOV word ptr [ESP],AX
    m.w16((f.sp), (s.ax & 0xffffu));
  }
  L0041b338: { // 0x41b338: 8b818c000000 MOV EAX,dword ptr [ECX + 0x8c]
    s.ax = m.r32((s.cx+0x0000008cu));
  }
  L0041b33e: { // 0x41b33e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b33f: { // 0x41b33f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b345: { // 0x41b345: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b347: { // 0x41b347: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b34a: { // 0x41b34a: 6689442402 MOV word ptr [ESP + 0x2],AX
    m.w16((f.sp+0x00000002u), (s.ax & 0xffffu));
  }
  L0041b34f: { // 0x41b34f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0041b353: { // 0x41b353: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0041b357: { // 0x41b357: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b359: { // 0x41b359: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041b35a: { // 0x41b35a: c20400 RET 0x4
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
case 4657760u:f_00071260(m,s,child,{});break;
case 4305696u:f_0001b320(m,s,child,{});break;
default:throw std::domain_error("recovery219 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00419250(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00419250: { // 0x419250: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00419253: { // 0x419253: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00419254: { // 0x419254: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00419258: { // 0x419258: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00419259: { // 0x419259: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041925a: { // 0x41925a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041925c: { // 0x41925c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0041925e: { // 0x41925e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041925f: { // 0x41925f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00419264: { // 0x419264: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00419268: { // 0x419268: e8e3e11300 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4297325u); flags=s.arithmetic_flags;
  }
  L0041926d: { // 0x41926d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041926f: { // 0x41926f: 0f8443010000 JZ 0x004193b8
    if(integer::condition("JZ",flags)) goto L004193b8;
  }
  L00419275: { // 0x419275: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L0041927b: { // 0x41927b: 8a88040b0000 MOV CL,byte ptr [EAX + 0xb04]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b04u)));
  }
  L00419281: { // 0x419281: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00419283: { // 0x419283: 7455 JZ 0x004192da
    if(integer::condition("JZ",flags)) goto L004192da;
  }
  L00419285: { // 0x419285: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00419287: { // 0x419287: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0041928b: { // 0x41928b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041928d: { // 0x41928d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041928e: { // 0x41928e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041928f: { // 0x41928f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00419294: { // 0x419294: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0041929c: { // 0x41929c: c744242800000000 MOV dword ptr [ESP + 0x28],0x0
    m.w32((f.sp+0x00000028u), 0x00000000u);
  }
  L004192a4: { // 0x4192a4: e857c21200 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4297385u); flags=s.arithmetic_flags;
  }
  L004192a9: { // 0x4192a9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004192ab: { // 0x4192ab: e8b07f0500 CALL 0x00471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4297392u); flags=s.arithmetic_flags;
  }
  L004192b0: { // 0x4192b0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004192b2: { // 0x4192b2: 7426 JZ 0x004192da
    if(integer::condition("JZ",flags)) goto L004192da;
  }
  L004192b4: { // 0x4192b4: 8b8838020000 MOV ECX,dword ptr [EAX + 0x238]
    s.cx = m.r32((s.ax+0x00000238u));
  }
  L004192ba: { // 0x4192ba: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004192bc: { // 0x4192bc: 0f85f6000000 JNZ 0x004193b8
    if(integer::condition("JNZ",flags)) goto L004193b8;
  }
  L004192c2: { // 0x4192c2: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004192c4: { // 0x4192c4: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004192c6: { // 0x4192c6: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4297420u); flags=s.arithmetic_flags;
  }
  L004192cc: { // 0x4192cc: 8a88040b0000 MOV CL,byte ptr [EAX + 0xb04]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b04u)));
  }
  L004192d2: { // 0x4192d2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004192d4: { // 0x4192d4: 0f85de000000 JNZ 0x004193b8
    if(integer::condition("JNZ",flags)) goto L004193b8;
  }
  L004192da: { // 0x4192da: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L004192e0: { // 0x4192e0: 8a88a30b0000 MOV CL,byte ptr [EAX + 0xba3]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ba3u)));
  }
  L004192e6: { // 0x4192e6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004192e8: { // 0x4192e8: 0f85ca000000 JNZ 0x004193b8
    if(integer::condition("JNZ",flags)) goto L004193b8;
  }
  L004192ee: { // 0x4192ee: 8a88940b0000 MOV CL,byte ptr [EAX + 0xb94]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b94u)));
  }
  L004192f4: { // 0x4192f4: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004192f6: { // 0x4192f6: 7419 JZ 0x00419311
    if(integer::condition("JZ",flags)) goto L00419311;
  }
  L004192f8: { // 0x4192f8: 8b8e94040000 MOV ECX,dword ptr [ESI + 0x494]
    s.cx = m.r32((s.si+0x00000494u));
  }
  L004192fe: { // 0x4192fe: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00419300: { // 0x419300: 740f JZ 0x00419311
    if(integer::condition("JZ",flags)) goto L00419311;
  }
  L00419302: { // 0x419302: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00419304: { // 0x419304: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4297479u); flags=s.arithmetic_flags;
  }
  L00419307: { // 0x419307: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0041930a: { // 0x41930a: c644242001 MOV byte ptr [ESP + 0x20],0x1
    m.w8((f.sp+0x00000020u), 0x00000001u);
  }
  L0041930f: { // 0x41930f: 7405 JZ 0x00419316
    if(integer::condition("JZ",flags)) goto L00419316;
  }
  L00419311: { // 0x419311: c644242000 MOV byte ptr [ESP + 0x20],0x0
    m.w8((f.sp+0x00000020u), 0x00000000u);
  }
  L00419316: { // 0x419316: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00419317: { // 0x419317: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0041931c: { // 0x41931c: e8dfc11200 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4297505u); flags=s.arithmetic_flags;
  }
  L00419321: { // 0x419321: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00419325: { // 0x419325: a178e28400 MOV EAX,[0x0084e278]
    s.ax = m.r32((0x0084e278u));
  }
  L0041932a: { // 0x41932a: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0041932c: { // 0x41932c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041932e: { // 0x41932e: 0f8e84000000 JLE 0x004193b8
    if(integer::condition("JLE",flags)) goto L004193b8;
  }
  L00419334: { // 0x419334: 8b0d6ce28400 MOV ECX,dword ptr [0x0084e26c]
    s.cx = m.r32((0x0084e26cu));
  }
  L0041933a: { // 0x41933a: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L0041933d: { // 0x41933d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041933f: { // 0x41933f: 7460 JZ 0x004193a1
    if(integer::condition("JZ",flags)) goto L004193a1;
  }
  L00419341: { // 0x419341: 8a442420 MOV AL,byte ptr [ESP + 0x20]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000020u)));
  }
  L00419345: { // 0x419345: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00419347: { // 0x419347: 740c JZ 0x00419355
    if(integer::condition("JZ",flags)) goto L00419355;
  }
  L00419349: { // 0x419349: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L0041934d: { // 0x41934d: 39b294040000 CMP dword ptr [EDX + 0x494],ESI
    (void)integer::sub(m.r32((s.dx+0x00000494u)),s.si,32,flags);
  }
  L00419353: { // 0x419353: 744c JZ 0x004193a1
    if(integer::condition("JZ",flags)) goto L004193a1;
  }
  L00419355: { // 0x419355: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L00419359: { // 0x419359: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041935b: { // 0x41935b: 7506 JNZ 0x00419363
    if(integer::condition("JNZ",flags)) goto L00419363;
  }
  L0041935d: { // 0x41935d: 3b74240c CMP ESI,dword ptr [ESP + 0xc]
    (void)integer::sub(s.si,m.r32((f.sp+0x0000000cu)),32,flags);
  }
  L00419361: { // 0x419361: 743e JZ 0x004193a1
    if(integer::condition("JZ",flags)) goto L004193a1;
  }
  L00419363: { // 0x419363: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L00419366: { // 0x419366: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00419368: { // 0x419368: 7537 JNZ 0x004193a1
    if(integer::condition("JNZ",flags)) goto L004193a1;
  }
  L0041936a: { // 0x41936a: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L0041936d: { // 0x41936d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041936f: { // 0x41936f: 7430 JZ 0x004193a1
    if(integer::condition("JZ",flags)) goto L004193a1;
  }
  L00419371: { // 0x419371: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00419373: { // 0x419373: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00419377: { // 0x419377: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00419378: { // 0x419378: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041937a: { // 0x41937a: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),4297600u); flags=s.arithmetic_flags;
  }
  L00419380: { // 0x419380: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L00419383: { // 0x419383: 663b5500 CMP DX,word ptr [EBP]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.bp)),16,flags);
  }
  L00419387: { // 0x419387: 750a JNZ 0x00419393
    if(integer::condition("JNZ",flags)) goto L00419393;
  }
  L00419389: { // 0x419389: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0041938d: { // 0x41938d: 663b4502 CMP AX,word ptr [EBP + 0x2]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.bp+0x00000002u)),16,flags);
  }
  L00419391: { // 0x419391: 741a JZ 0x004193ad
    if(integer::condition("JZ",flags)) goto L004193ad;
  }
  L00419393: { // 0x419393: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00419397: { // 0x419397: 8b8694040000 MOV EAX,dword ptr [ESI + 0x494]
    s.ax = m.r32((s.si+0x00000494u));
  }
  L0041939d: { // 0x41939d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041939f: { // 0x41939f: 740c JZ 0x004193ad
    if(integer::condition("JZ",flags)) goto L004193ad;
  }
  L004193a1: { // 0x4193a1: a178e28400 MOV EAX,[0x0084e278]
    s.ax = m.r32((0x0084e278u));
  }
  L004193a6: { // 0x4193a6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004193a7: { // 0x4193a7: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004193a9: { // 0x4193a9: 7d0d JGE 0x004193b8
    if(integer::condition("JGE",flags)) goto L004193b8;
  }
  L004193ab: { // 0x4193ab: eb87 JMP 0x00419334
    goto L00419334;
  }
  L004193ad: { // 0x4193ad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004193ae: { // 0x4193ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004193af: { // 0x4193af: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004193b1: { // 0x4193b1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004193b2: { // 0x4193b2: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004193b5: { // 0x4193b5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004193b8: { // 0x4193b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004193b9: { // 0x4193b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004193ba: { // 0x4193ba: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004193bc: { // 0x4193bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004193bd: { // 0x4193bd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004193c0: { // 0x4193c0: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
