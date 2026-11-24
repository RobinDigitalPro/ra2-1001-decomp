#include "recovered/recovery_b721_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b721 {
namespace {
void f_001fb220(Memory&,State&,Frame&,const Operations&);
void f_000794f0(Memory&,State&,Frame&,const Operations&);
void f_000e0840(Memory&,State&,Frame&,const Operations&);
void f_0009e310(Memory&,State&,Frame&,const Operations&);
void f_00157340(Memory&,State&,Frame&,const Operations&);
void f_00157280(Memory&,State&,Frame&,const Operations&);
void f_0011f190(Memory&,State&,Frame&,const Operations&);
void f_0011f1a0(Memory&,State&,Frame&,const Operations&);
void f_000e0030(Memory&,State&,Frame&,const Operations&);
void f_00157ab0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00120040(Memory&,State&,Frame&,const Operations&);


void f_001fb220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005fb220: { // 0x5fb220: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005fb221: { // 0x5fb221: a168dfa500 MOV EAX,[0x00a5df68]
    s.ax = m.r32((0x00a5df68u));
  }
  L005fb226: { // 0x5fb226: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005fb227: { // 0x5fb227: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005fb228: { // 0x5fb228: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005fb229: { // 0x5fb229: 8b580c MOV EBX,dword ptr [EAX + 0xc]
    s.bx = m.r32((s.ax+0x0000000cu));
  }
  L005fb22c: { // 0x5fb22c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005fb22e: { // 0x5fb22e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005fb22f: { // 0x5fb22f: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000008u)));
  }
  L005fb232: { // 0x5fb232: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005fb234: { // 0x5fb234: 7569 JNZ 0x005fb29f
    if(integer::condition("JNZ",flags)) goto L005fb29f;
  }
  L005fb236: { // 0x5fb236: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005fb238: { // 0x5fb238: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L005fb23b: { // 0x5fb23b: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005fb23d: { // 0x5fb23d: 7d50 JGE 0x005fb28f
    if(integer::condition("JGE",flags)) goto L005fb28f;
  }
  L005fb23f: { // 0x5fb23f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005fb241: { // 0x5fb241: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L005fb244: { // 0x5fb244: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L005fb246: { // 0x5fb246: 8b4cd010 MOV ECX,dword ptr [EAX + EDX*0x8 + 0x10]
    s.cx = m.r32((s.ax+(s.dx * 0x00000008u)+0x00000010u));
  }
  L005fb24a: { // 0x5fb24a: 8d3cd0 LEA EDI,[EAX + EDX*0x8]
    s.di = (s.ax+(s.dx * 0x00000008u));
  }
  L005fb24d: { // 0x5fb24d: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L005fb250: { // 0x5fb250: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005fb252: { // 0x5fb252: 7d26 JGE 0x005fb27a
    if(integer::condition("JGE",flags)) goto L005fb27a;
  }
  L005fb254: { // 0x5fb254: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L005fb257: { // 0x5fb257: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005fb259: { // 0x5fb259: c1e106 SHL ECX,0x6
    s.cx = integer::shift(s.cx,0x00000006u,32,flags,integer::Shift::left);
  }
  L005fb25c: { // 0x5fb25c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005fb25e: { // 0x5fb25e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005fb25f: { // 0x5fb25f: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L005fb262: { // 0x5fb262: 8d2c8a LEA EBP,[EDX + ECX*0x4]
    s.bp = (s.dx+(s.cx * 0x00000004u));
  }
  L005fb265: { // 0x5fb265: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005fb267: { // 0x5fb267: e8d455eeff CALL 0x004e0840
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0840u,6271596u); flags=s.arithmetic_flags;
  }
  L005fb26c: { // 0x5fb26c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005fb26e: { // 0x5fb26e: 742b JZ 0x005fb29b
    if(integer::condition("JZ",flags)) goto L005fb29b;
  }
  L005fb270: { // 0x5fb270: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L005fb273: { // 0x5fb273: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L005fb276: { // 0x5fb276: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005fb278: { // 0x5fb278: 7cda JL 0x005fb254
    if(integer::condition("JL",flags)) goto L005fb254;
  }
  L005fb27a: { // 0x5fb27a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005fb27c: { // 0x5fb27c: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L005fb283: { // 0x5fb283: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005fb284: { // 0x5fb284: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L005fb286: { // 0x5fb286: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  L005fb289: { // 0x5fb289: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005fb28b: { // 0x5fb28b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005fb28d: { // 0x5fb28d: 7cb0 JL 0x005fb23f
    if(integer::condition("JL",flags)) goto L005fb23f;
  }
  L005fb28f: { // 0x5fb28f: c6460801 MOV byte ptr [ESI + 0x8],0x1
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L005fb293: { // 0x5fb293: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005fb294: { // 0x5fb294: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005fb295: { // 0x5fb295: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005fb296: { // 0x5fb296: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005fb298: { // 0x5fb298: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005fb299: { // 0x5fb299: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005fb29a: { // 0x5fb29a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005fb29b: { // 0x5fb29b: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L005fb29d: { // 0x5fb29d: 7508 JNZ 0x005fb2a7
    if(integer::condition("JNZ",flags)) goto L005fb2a7;
  }
  L005fb29f: { // 0x5fb29f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005fb2a0: { // 0x5fb2a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005fb2a1: { // 0x5fb2a1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005fb2a2: { // 0x5fb2a2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005fb2a4: { // 0x5fb2a4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005fb2a5: { // 0x5fb2a5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005fb2a6: { // 0x5fb2a6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005fb2a7: { // 0x5fb2a7: a168dfa500 MOV EAX,[0x00a5df68]
    s.ax = m.r32((0x00a5df68u));
  }
  L005fb2ac: { // 0x5fb2ac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005fb2ae: { // 0x5fb2ae: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  L005fb2b1: { // 0x5fb2b1: ff5604 CALL dword ptr [ESI + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000004u)),6271668u); flags=s.arithmetic_flags;
  }
  L005fb2b4: { // 0x5fb2b4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005fb2b5: { // 0x5fb2b5: f77e08 IDIV dword ptr [ESI + 0x8]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.si+0x00000008u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L005fb2b8: { // 0x5fb2b8: 8d0c52 LEA ECX,[EDX + EDX*0x2]
    s.cx = (s.dx+(s.dx * 0x00000002u));
  }
  L005fb2bb: { // 0x5fb2bb: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005fb2bd: { // 0x5fb2bd: 8b7cca10 MOV EDI,dword ptr [EDX + ECX*0x8 + 0x10]
    s.di = m.r32((s.dx+(s.cx * 0x00000008u)+0x00000010u));
  }
  L005fb2c1: { // 0x5fb2c1: 8d04ca LEA EAX,[EDX + ECX*0x8]
    s.ax = (s.dx+(s.cx * 0x00000008u));
  }
  L005fb2c4: { // 0x5fb2c4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005fb2c5: { // 0x5fb2c5: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005fb2c9: { // 0x5fb2c9: 7840 JS 0x005fb30b
    if(integer::condition("JS",flags)) goto L005fb30b;
  }
  L005fb2cb: { // 0x5fb2cb: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L005fb2cd: { // 0x5fb2cd: c1e306 SHL EBX,0x6
    s.bx = integer::shift(s.bx,0x00000006u,32,flags,integer::Shift::left);
  }
  L005fb2d0: { // 0x5fb2d0: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L005fb2d2: { // 0x5fb2d2: c1e302 SHL EBX,0x2
    s.bx = integer::shift(s.bx,0x00000002u,32,flags,integer::Shift::left);
  }
  L005fb2d5: { // 0x5fb2d5: eb04 JMP 0x005fb2db
    goto L005fb2db;
  }
  L005fb2d7: { // 0x5fb2d7: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005fb2db: { // 0x5fb2db: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L005fb2de: { // 0x5fb2de: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L005fb2e0: { // 0x5fb2e0: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L005fb2e2: { // 0x5fb2e2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005fb2e3: { // 0x5fb2e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005fb2e5: { // 0x5fb2e5: e89655eeff CALL 0x004e0880
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0880u,6271722u); flags=s.arithmetic_flags;
  }
  L005fb2ea: { // 0x5fb2ea: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005fb2ec: { // 0x5fb2ec: 7513 JNZ 0x005fb301
    if(integer::condition("JNZ",flags)) goto L005fb301;
  }
  L005fb2ee: { // 0x5fb2ee: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005fb2ef: { // 0x5fb2ef: 81eb04010000 SUB EBX,0x104
    s.bx = integer::sub(s.bx,0x00000104u,32,flags);
  }
  L005fb2f5: { // 0x5fb2f5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005fb2f7: { // 0x5fb2f7: 7dde JGE 0x005fb2d7
    if(integer::condition("JGE",flags)) goto L005fb2d7;
  }
  L005fb2f9: { // 0x5fb2f9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005fb2fa: { // 0x5fb2fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005fb2fb: { // 0x5fb2fb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005fb2fc: { // 0x5fb2fc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005fb2fe: { // 0x5fb2fe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005fb2ff: { // 0x5fb2ff: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005fb300: { // 0x5fb300: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005fb301: { // 0x5fb301: 8d8600010000 LEA EAX,[ESI + 0x100]
    s.ax = (s.si+0x00000100u);
  }
  L005fb307: { // 0x5fb307: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005fb309: { // 0x5fb309: 7508 JNZ 0x005fb313
    if(integer::condition("JNZ",flags)) goto L005fb313;
  }
  L005fb30b: { // 0x5fb30b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005fb30c: { // 0x5fb30c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005fb30d: { // 0x5fb30d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005fb30e: { // 0x5fb30e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005fb310: { // 0x5fb310: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005fb311: { // 0x5fb311: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005fb312: { // 0x5fb312: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005fb313: { // 0x5fb313: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005fb315: { // 0x5fb315: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005fb316: { // 0x5fb316: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005fb317: { // 0x5fb317: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005fb318: { // 0x5fb318: 8b8000010000 MOV EAX,dword ptr [EAX + 0x100]
    s.ax = m.r32((s.ax+0x00000100u));
  }
  L005fb31e: { // 0x5fb31e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005fb31f: { // 0x5fb31f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005fb320: { // 0x5fb320: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000794f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004794f0: { // 0x4794f0: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004794f5: { // 0x4794f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004794f6: { // 0x4794f6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004794f8: { // 0x4794f8: 8b80ac220000 MOV EAX,dword ptr [EAX + 0x22ac]
    s.ax = m.r32((s.ax+0x000022acu));
  }
  L004794fe: { // 0x4794fe: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00479501: { // 0x479501: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00479504: { // 0x479504: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L00479507: { // 0x479507: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0047950c: { // 0x47950c: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0047950f: { // 0x47950f: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00479511: { // 0x479511: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L00479514: { // 0x479514: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00479516: { // 0x479516: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00479519: { // 0x479519: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0047951b: { // 0x47951b: 66039608010000 ADD DX,word ptr [ESI + 0x108]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.si+0x00000108u)),16,flags));
  }
  L00479522: { // 0x479522: 6689960a010000 MOV word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), (s.dx & 0xffffu));
  }
  L00479529: { // 0x479529: 6689960e010000 MOV word ptr [ESI + 0x10e],DX
    m.w16((s.si+0x0000010eu), (s.dx & 0xffffu));
  }
  L00479530: { // 0x479530: e85b5c0a00 CALL 0x0051f190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0051f190u,4691253u); flags=s.arithmetic_flags;
  }
  L00479535: { // 0x479535: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00479537: { // 0x479537: 7440 JZ 0x00479579
    if(integer::condition("JZ",flags)) goto L00479579;
  }
  L00479539: { // 0x479539: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0047953f: { // 0x47953f: 660fbe861b010000 MOVSX AX,byte ptr [ESI + 0x11b]
    s.ax = with_ax(s.ax, std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8)));
  }
  L00479547: { // 0x479547: 668b91dc220000 MOV DX,word ptr [ECX + 0x22dc]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x000022dcu)));
  }
  L0047954e: { // 0x47954e: 660fafd0 IMUL DX,AX
    s.dx = with_ax(s.dx, integer::imul((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L00479552: { // 0x479552: 662b91d8220000 SUB DX,word ptr [ECX + 0x22d8]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.cx+0x000022d8u)),16,flags));
  }
  L00479559: { // 0x479559: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
  L0047955c: { // 0x47955c: 6601960a010000 ADD word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), integer::add(m.r16((s.si+0x0000010au)),(s.dx & 0xffffu),16,flags));
  }
  L00479563: { // 0x479563: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00479568: { // 0x479568: 660faf88dc220000 IMUL CX,word ptr [EAX + 0x22dc]
    s.cx = with_ax(s.cx, integer::imul((s.cx & 0xffffu),m.r16((s.ax+0x000022dcu)),16,flags));
  }
  L00479570: { // 0x479570: 662b88d8220000 SUB CX,word ptr [EAX + 0x22d8]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.ax+0x000022d8u)),16,flags));
  }
  L00479577: { // 0x479577: eb79 JMP 0x004795f2
    goto L004795f2;
  }
  L00479579: { // 0x479579: e8225c0a00 CALL 0x0051f1a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0051f1a0u,4691326u); flags=s.arithmetic_flags;
  }
  L0047957e: { // 0x47957e: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00479584: { // 0x479584: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00479586: { // 0x479586: 660fbe861b010000 MOVSX AX,byte ptr [ESI + 0x11b]
    s.ax = with_ax(s.ax, std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8)));
  }
  L0047958e: { // 0x47958e: 7432 JZ 0x004795c2
    if(integer::condition("JZ",flags)) goto L004795c2;
  }
  L00479590: { // 0x479590: 668b91f4220000 MOV DX,word ptr [ECX + 0x22f4]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x000022f4u)));
  }
  L00479597: { // 0x479597: 660fafd0 IMUL DX,AX
    s.dx = with_ax(s.dx, integer::imul((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L0047959b: { // 0x47959b: 662b91f0220000 SUB DX,word ptr [ECX + 0x22f0]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.cx+0x000022f0u)),16,flags));
  }
  L004795a2: { // 0x4795a2: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
  L004795a5: { // 0x4795a5: 6601960a010000 ADD word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), integer::add(m.r16((s.si+0x0000010au)),(s.dx & 0xffffu),16,flags));
  }
  L004795ac: { // 0x4795ac: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004795b1: { // 0x4795b1: 660faf88f4220000 IMUL CX,word ptr [EAX + 0x22f4]
    s.cx = with_ax(s.cx, integer::imul((s.cx & 0xffffu),m.r16((s.ax+0x000022f4u)),16,flags));
  }
  L004795b9: { // 0x4795b9: 662b88f0220000 SUB CX,word ptr [EAX + 0x22f0]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.ax+0x000022f0u)),16,flags));
  }
  L004795c0: { // 0x4795c0: eb30 JMP 0x004795f2
    goto L004795f2;
  }
  L004795c2: { // 0x4795c2: 668b91c4220000 MOV DX,word ptr [ECX + 0x22c4]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x000022c4u)));
  }
  L004795c9: { // 0x4795c9: 660fafd0 IMUL DX,AX
    s.dx = with_ax(s.dx, integer::imul((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
  L004795cd: { // 0x4795cd: 662b91c0220000 SUB DX,word ptr [ECX + 0x22c0]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.cx+0x000022c0u)),16,flags));
  }
  L004795d4: { // 0x4795d4: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
  L004795d7: { // 0x4795d7: 6601960a010000 ADD word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), integer::add(m.r16((s.si+0x0000010au)),(s.dx & 0xffffu),16,flags));
  }
  L004795de: { // 0x4795de: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L004795e3: { // 0x4795e3: 660faf88c4220000 IMUL CX,word ptr [EAX + 0x22c4]
    s.cx = with_ax(s.cx, integer::imul((s.cx & 0xffffu),m.r16((s.ax+0x000022c4u)),16,flags));
  }
  L004795eb: { // 0x4795eb: 662b88c0220000 SUB CX,word ptr [EAX + 0x22c0]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.ax+0x000022c0u)),16,flags));
  }
  L004795f2: { // 0x4795f2: 66018e0e010000 ADD word ptr [ESI + 0x10e],CX
    m.w16((s.si+0x0000010eu), integer::add(m.r16((s.si+0x0000010eu)),(s.cx & 0xffffu),16,flags));
  }
  L004795f9: { // 0x4795f9: 8b8e04010000 MOV ECX,dword ptr [ESI + 0x104]
    s.cx = m.r32((s.si+0x00000104u));
  }
  L004795ff: { // 0x4795ff: 0fbf960a010000 MOVSX EDX,word ptr [ESI + 0x10a]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x0000010au)),16));
  }
  L00479606: { // 0x479606: 0fbf860e010000 MOVSX EAX,word ptr [ESI + 0x10e]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x0000010eu)),16));
  }
  L0047960d: { // 0x47960d: 0fafd1 IMUL EDX,ECX
    s.dx = integer::imul(s.dx,s.cx,32,flags);
  }
  L00479610: { // 0x479610: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00479613: { // 0x479613: 668b8e0a010000 MOV CX,word ptr [ESI + 0x10a]
    s.cx = with_ax(s.cx, m.r16((s.si+0x0000010au)));
  }
  L0047961a: { // 0x47961a: c1fa10 SAR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
  L0047961d: { // 0x47961d: c1f810 SAR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
  L00479620: { // 0x479620: 6681f9d007 CMP CX,0x7d0
    (void)integer::sub((s.cx & 0xffffu),0x000007d0u,16,flags);
  }
  L00479625: { // 0x479625: 6689960c010000 MOV word ptr [ESI + 0x10c],DX
    m.w16((s.si+0x0000010cu), (s.dx & 0xffffu));
  }
  L0047962c: { // 0x47962c: 6689860e010000 MOV word ptr [ESI + 0x10e],AX
    m.w16((s.si+0x0000010eu), (s.ax & 0xffffu));
  }
  L00479633: { // 0x479633: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00479636: { // 0x479636: 7c05 JL 0x0047963d
    if(integer::condition("JL",flags)) goto L0047963d;
  }
  L00479638: { // 0x479638: b9d0070000 MOV ECX,0x7d0
    s.cx = 0x000007d0u;
  }
  L0047963d: { // 0x47963d: 66898e0a010000 MOV word ptr [ESI + 0x10a],CX
    m.w16((s.si+0x0000010au), (s.cx & 0xffffu));
  }
  L00479644: { // 0x479644: 668b8e0c010000 MOV CX,word ptr [ESI + 0x10c]
    s.cx = with_ax(s.cx, m.r16((s.si+0x0000010cu)));
  }
  L0047964b: { // 0x47964b: 6681f9d007 CMP CX,0x7d0
    (void)integer::sub((s.cx & 0xffffu),0x000007d0u,16,flags);
  }
  L00479650: { // 0x479650: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00479653: { // 0x479653: 7c05 JL 0x0047965a
    if(integer::condition("JL",flags)) goto L0047965a;
  }
  L00479655: { // 0x479655: bad0070000 MOV EDX,0x7d0
    s.dx = 0x000007d0u;
  }
  L0047965a: { // 0x47965a: 663dd007 CMP AX,0x7d0
    (void)integer::sub((s.ax & 0xffffu),0x000007d0u,16,flags);
  }
  L0047965e: { // 0x47965e: 6689960c010000 MOV word ptr [ESI + 0x10c],DX
    m.w16((s.si+0x0000010cu), (s.dx & 0xffffu));
  }
  L00479665: { // 0x479665: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00479668: { // 0x479668: 7c05 JL 0x0047966f
    if(integer::condition("JL",flags)) goto L0047966f;
  }
  L0047966a: { // 0x47966a: b9d0070000 MOV ECX,0x7d0
    s.cx = 0x000007d0u;
  }
  L0047966f: { // 0x47966f: 668b860a010000 MOV AX,word ptr [ESI + 0x10a]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000010au)));
  }
  L00479676: { // 0x479676: 66898e0e010000 MOV word ptr [ESI + 0x10e],CX
    m.w16((s.si+0x0000010eu), (s.cx & 0xffffu));
  }
  L0047967d: { // 0x47967d: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L00479680: { // 0x479680: 7e05 JLE 0x00479687
    if(integer::condition("JLE",flags)) goto L00479687;
  }
  L00479682: { // 0x479682: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00479685: { // 0x479685: eb02 JMP 0x00479689
    goto L00479689;
  }
  L00479687: { // 0x479687: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00479689: { // 0x479689: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L0047968c: { // 0x47968c: 6689860a010000 MOV word ptr [ESI + 0x10a],AX
    m.w16((s.si+0x0000010au), (s.ax & 0xffffu));
  }
  L00479693: { // 0x479693: 7e05 JLE 0x0047969a
    if(integer::condition("JLE",flags)) goto L0047969a;
  }
  L00479695: { // 0x479695: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00479698: { // 0x479698: eb02 JMP 0x0047969c
    goto L0047969c;
  }
  L0047969a: { // 0x47969a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0047969c: { // 0x47969c: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L0047969f: { // 0x47969f: 6689860c010000 MOV word ptr [ESI + 0x10c],AX
    m.w16((s.si+0x0000010cu), (s.ax & 0xffffu));
  }
  L004796a6: { // 0x4796a6: 7e0c JLE 0x004796b4
    if(integer::condition("JLE",flags)) goto L004796b4;
  }
  L004796a8: { // 0x4796a8: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L004796ab: { // 0x4796ab: 6689860e010000 MOV word ptr [ESI + 0x10e],AX
    m.w16((s.si+0x0000010eu), (s.ax & 0xffffu));
  }
  L004796b2: { // 0x4796b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004796b3: { // 0x4796b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004796b4: { // 0x4796b4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004796b6: { // 0x4796b6: 6689860e010000 MOV word ptr [ESI + 0x10e],AX
    m.w16((s.si+0x0000010eu), (s.ax & 0xffffu));
  }
  L004796bd: { // 0x4796bd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004796be: { // 0x4796be: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e0840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0840: { // 0x4e0840: 8a11 MOV DL,byte ptr [ECX]
    s.dx = with_al(s.dx, m.r8((s.cx)));
  }
  L004e0842: { // 0x4e0842: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e0844: { // 0x4e0844: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004e0846: { // 0x4e0846: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e0849: { // 0x4e0849: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0009e310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049e310: { // 0x49e310: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049e315: { // 0x49e315: e826900b00 CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,4842266u); flags=s.arithmetic_flags;
  }
  L0049e31a: { // 0x49e31a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049e31f: { // 0x49e31f: e85c8f0b00 CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,4842276u); flags=s.arithmetic_flags;
  }
  L0049e324: { // 0x49e324: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049e326: { // 0x49e326: 7415 JZ 0x0049e33d
    if(integer::condition("JZ",flags)) goto L0049e33d;
  }
  L0049e328: { // 0x49e328: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049e32a: { // 0x49e32a: e8c1b1fdff CALL 0x004794f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004794f0u,4842287u); flags=s.arithmetic_flags;
  }
  L0049e32f: { // 0x49e32f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0049e334: { // 0x49e334: e8478f0b00 CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,4842297u); flags=s.arithmetic_flags;
  }
  L0049e339: { // 0x49e339: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049e33b: { // 0x49e33b: 75eb JNZ 0x0049e328
    if(integer::condition("JNZ",flags)) goto L0049e328;
  }
  L0049e33d: { // 0x49e33d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
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
void f_0011f190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0051f190: { // 0x51f190: a07495a300 MOV AL,[0x00a39574]
    s.ax = with_al(s.ax, m.r8((0x00a39574u)));
  }
  L0051f195: { // 0x51f195: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0011f1a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0051f1a0: { // 0x51f1a0: 8b0d7c95a300 MOV ECX,dword ptr [0x00a3957c]
    s.cx = m.r32((0x00a3957cu));
  }
  L0051f1a6: { // 0x51f1a6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0051f1a8: { // 0x51f1a8: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0051f1ab: { // 0x51f1ab: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0051f1ae: { // 0x51f1ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e0030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0030: { // 0x4e0030: a1ac1c8200 MOV EAX, dword ptr [0x821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L004e0035: { // 0x4e0035: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0037: { // 0x4e0037: 7407 JZ 0x4e0040
    if(integer::condition("JZ",flags)) goto L004e0040;
  }
  L004e0039: { // 0x4e0039: c6807d0d000001 MOV byte ptr [EAX + 0xd7d], 1
    m.w8((s.ax+0x00000d7du), 1u);
  }
  L004e0040: { // 0x4e0040: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004e0044: { // 0x4e0044: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0046: { // 0x4e0046: 7413 JZ 0x4e005b
    if(integer::condition("JZ",flags)) goto L004e005b;
  }
  L004e0048: { // 0x4e0048: 83790c02 CMP dword ptr [ECX + 0xc], 2
    (void)integer::sub(m.r32((s.cx+0x0000000cu)),2u,32,flags);
  }
  L004e004c: { // 0x4e004c: 7403 JZ 0x4e0051
    if(integer::condition("JZ",flags)) goto L004e0051;
  }
  L004e004e: { // 0x4e004e: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004e0051: { // 0x4e0051: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e0056: { // 0x4e0056: e8557a0700 CALL 0x557ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557ab0u,5111899u); flags=s.arithmetic_flags;
  }
  L004e005b: { // 0x4e005b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557ab0: { // 0x557ab0: fe8154110000 INC byte ptr [ECX + 0x1154]
    m.w8((s.cx+0x00001154u), integer::increment(m.r8((s.cx+0x00001154u)),8,flags));
  }
  L00557ab6: { // 0x557ab6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void f_00120040(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00520040: { // 0x520040: a1e8a68100 MOV EAX,[0x0081a6e8]
    s.ax = m.r32((0x0081a6e8u));
  }
  L00520045: { // 0x520045: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00520048: { // 0x520048: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00520049: { // 0x520049: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0052004d: { // 0x52004d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0052004e: { // 0x52004e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0052004f: { // 0x52004f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00520051: { // 0x520051: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00520052: { // 0x520052: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00520054: { // 0x520054: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00520056: { // 0x520056: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00520058: { // 0x520058: 7e1f JLE 0x00520079
    if(integer::condition("JLE",flags)) goto L00520079;
  }
  L0052005a: { // 0x52005a: a1dca68100 MOV EAX,[0x0081a6dc]
    s.ax = m.r32((0x0081a6dcu));
  }
  L0052005f: { // 0x52005f: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L00520062: { // 0x520062: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00520066: { // 0x520066: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00520067: { // 0x520067: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00520068: { // 0x520068: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0052006a: { // 0x52006a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0052006b: { // 0x52006b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0052006c: { // 0x52006c: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),5374063u); flags=s.arithmetic_flags;
  }
  L0052006f: { // 0x52006f: a1e8a68100 MOV EAX,[0x0081a6e8]
    s.ax = m.r32((0x0081a6e8u));
  }
  L00520074: { // 0x520074: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00520075: { // 0x520075: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00520077: { // 0x520077: 7ce1 JL 0x0052005a
    if(integer::condition("JL",flags)) goto L0052005a;
  }
  L00520079: { // 0x520079: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  L0052007e: { // 0x52007e: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00520080: { // 0x520080: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00520082: { // 0x520082: 7e2f JLE 0x005200b3
    if(integer::condition("JLE",flags)) goto L005200b3;
  }
  L00520084: { // 0x520084: 8b0d04eaa900 MOV ECX,dword ptr [0x00a9ea04]
    s.cx = m.r32((0x00a9ea04u));
  }
  L0052008a: { // 0x52008a: 8b04b1 MOV EAX,dword ptr [ECX + ESI*0x4]
    s.ax = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L0052008d: { // 0x52008d: 83b81003000001 CMP dword ptr [EAX + 0x310],0x1
    (void)integer::sub(m.r32((s.ax+0x00000310u)),0x00000001u,32,flags);
  }
  L00520094: { // 0x520094: 7e13 JLE 0x005200a9
    if(integer::condition("JLE",flags)) goto L005200a9;
  }
  L00520096: { // 0x520096: 8b880c030000 MOV ECX,dword ptr [EAX + 0x30c]
    s.cx = m.r32((s.ax+0x0000030cu));
  }
  L0052009c: { // 0x52009c: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005200a0: { // 0x5200a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005200a1: { // 0x5200a1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005200a2: { // 0x5200a2: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005200a4: { // 0x5200a4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005200a5: { // 0x5200a5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005200a6: { // 0x5200a6: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),5374121u); flags=s.arithmetic_flags;
  }
  L005200a9: { // 0x5200a9: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  L005200ae: { // 0x5200ae: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005200af: { // 0x5200af: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005200b1: { // 0x5200b1: 7cd1 JL 0x00520084
    if(integer::condition("JL",flags)) goto L00520084;
  }
  L005200b3: { // 0x5200b3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005200b5: { // 0x5200b5: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L005200b9: { // 0x5200b9: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005200bd: { // 0x5200bd: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005200c1: { // 0x5200c1: 8844241c MOV byte ptr [ESP + 0x1c],AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L005200c5: { // 0x5200c5: e856b10d00 CALL 0x005fb220
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fb220u,5374154u); flags=s.arithmetic_flags;
  }
  L005200ca: { // 0x5200ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005200cc: { // 0x5200cc: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005200d0: { // 0x5200d0: 7444 JZ 0x00520116
    if(integer::condition("JZ",flags)) goto L00520116;
  }
  L005200d2: { // 0x5200d2: e819b70d00 CALL 0x005fb7f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fb7f0u,5374167u); flags=s.arithmetic_flags;
  }
  L005200d7: { // 0x5200d7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005200d9: { // 0x5200d9: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005200dd: { // 0x5200dd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005200df: { // 0x5200df: 7e24 JLE 0x00520105
    if(integer::condition("JLE",flags)) goto L00520105;
  }
  L005200e1: { // 0x5200e1: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L005200e5: { // 0x5200e5: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L005200e8: { // 0x5200e8: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  L005200eb: { // 0x5200eb: 8b880c030000 MOV ECX,dword ptr [EAX + 0x30c]
    s.cx = m.r32((s.ax+0x0000030cu));
  }
  L005200f1: { // 0x5200f1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005200f5: { // 0x5200f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005200f6: { // 0x5200f6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005200f7: { // 0x5200f7: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005200f9: { // 0x5200f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005200fa: { // 0x5200fa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005200fb: { // 0x5200fb: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),5374206u); flags=s.arithmetic_flags;
  }
  L005200fe: { // 0x5200fe: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005200ff: { // 0x5200ff: 3b742410 CMP ESI,dword ptr [ESP + 0x10]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L00520103: { // 0x520103: 7cdc JL 0x005200e1
    if(integer::condition("JL",flags)) goto L005200e1;
  }
  L00520105: { // 0x520105: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00520109: { // 0x520109: e812b10d00 CALL 0x005fb220
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fb220u,5374222u); flags=s.arithmetic_flags;
  }
  L0052010e: { // 0x52010e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00520110: { // 0x520110: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00520114: { // 0x520114: 75bc JNZ 0x005200d2
    if(integer::condition("JNZ",flags)) goto L005200d2;
  }
  L00520116: { // 0x520116: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0052011b: { // 0x52011b: e8f0e1f7ff CALL 0x0049e310
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049e310u,5374240u); flags=s.arithmetic_flags;
  }
  L00520120: { // 0x520120: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00520121: { // 0x520121: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00520122: { // 0x520122: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00520123: { // 0x520123: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00520124: { // 0x520124: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00520127: { // 0x520127: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x520040u:f_00120040(m,s,child,{});break;
case 6271520u:f_001fb220(m,s,child,{});break;
case 4691184u:f_000794f0(m,s,child,{});break;
case 5113920u:f_000e0840(m,s,child,{});break;
case 4842256u:f_0009e310(m,s,child,{});break;
case 5600064u:f_00157340(m,s,child,{});break;
case 5599872u:f_00157280(m,s,child,{});break;
case 5370256u:f_0011f190(m,s,child,{});break;
case 5370272u:f_0011f1a0(m,s,child,{});break;
case 5111856u:f_000e0030(m,s,child,{});break;
case 5601968u:f_00157ab0(m,s,child,{});break;
default:throw std::domain_error("recovery721 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0051fde0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0051fde0: { // 0x51fde0: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L0051fde6: { // 0x51fde6: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L0051fdeb: { // 0x51fdeb: 81c228080000 ADD EDX,0x828
    s.dx = integer::add(s.dx,0x00000828u,32,flags);
  }
  L0051fdf1: { // 0x51fdf1: c7057c95a30001000000 MOV dword ptr [0x00a3957c],0x1
    m.w32((0x00a3957cu), 0x00000001u);
  }
  L0051fdfb: { // 0x51fdfb: c705dc8b7c001e000000 MOV dword ptr [0x007c8bdc],0x1e
    m.w32((0x007c8bdcu), 0x0000001eu);
  }
  L0051fe05: { // 0x51fe05: a3d88b7c00 MOV [0x007c8bd8],EAX
    m.w32((0x007c8bd8u), s.ax);
  }
  L0051fe0a: { // 0x51fe0a: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L0051fe0c: { // 0x51fe0c: 8b4424f8 MOV EAX,dword ptr [ESP + -0x8]
    s.ax = m.r32((f.sp-0x00000008u));
  }
  L0051fe10: { // 0x51fe10: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0051fe15: { // 0x51fe15: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0051fe18: { // 0x51fe18: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0051fe1b: { // 0x51fe1b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0051fe1c: { // 0x51fe1c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0051fe1d: { // 0x51fe1d: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0051fe20: { // 0x51fe20: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0051fe25: { // 0x51fe25: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0051fe27: { // 0x51fe27: 8b88e0220000 MOV ECX,dword ptr [EAX + 0x22e0]
    s.cx = m.r32((s.ax+0x000022e0u));
  }
  L0051fe2d: { // 0x51fe2d: 8988b0220000 MOV dword ptr [EAX + 0x22b0],ECX
    m.w32((s.ax+0x000022b0u), s.cx);
  }
  L0051fe33: { // 0x51fe33: 8b3dc055a200 MOV EDI,dword ptr [0x00a255c0]
    s.di = m.r32((0x00a255c0u));
  }
  L0051fe39: { // 0x51fe39: 8b87ec220000 MOV EAX,dword ptr [EDI + 0x22ec]
    s.ax = m.r32((s.di+0x000022ecu));
  }
  L0051fe3f: { // 0x51fe3f: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe42: { // 0x51fe42: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe45: { // 0x51fe45: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe48: { // 0x51fe48: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0051fe4d: { // 0x51fe4d: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0051fe50: { // 0x51fe50: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0051fe52: { // 0x51fe52: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0051fe55: { // 0x51fe55: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0051fe57: { // 0x51fe57: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0051fe5a: { // 0x51fe5a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0051fe5c: { // 0x51fe5c: 8b87e8220000 MOV EAX,dword ptr [EDI + 0x22e8]
    s.ax = m.r32((s.di+0x000022e8u));
  }
  L0051fe62: { // 0x51fe62: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0051fe63: { // 0x51fe63: 8bbfe4220000 MOV EDI,dword ptr [EDI + 0x22e4]
    s.di = m.r32((s.di+0x000022e4u));
  }
  L0051fe69: { // 0x51fe69: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe6c: { // 0x51fe6c: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe6f: { // 0x51fe6f: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe72: { // 0x51fe72: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0051fe77: { // 0x51fe77: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0051fe7a: { // 0x51fe7a: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0051fe7c: { // 0x51fe7c: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0051fe7e: { // 0x51fe7e: 8d04bf LEA EAX,[EDI + EDI*0x4]
    s.ax = (s.di+(s.di * 0x00000004u));
  }
  L0051fe81: { // 0x51fe81: c1fe05 SAR ESI,0x5
    s.si = integer::shift(s.si,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0051fe84: { // 0x51fe84: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0051fe86: { // 0x51fe86: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe89: { // 0x51fe89: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0051fe8c: { // 0x51fe8c: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0051fe8e: { // 0x51fe8e: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0051fe91: { // 0x51fe91: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0051fe94: { // 0x51fe94: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0051fe99: { // 0x51fe99: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0051fe9b: { // 0x51fe9b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0051fe9d: { // 0x51fe9d: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0051fea0: { // 0x51fea0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0051fea2: { // 0x51fea2: c1ea1f SHR EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0051fea5: { // 0x51fea5: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0051fea7: { // 0x51fea7: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0051fea9: { // 0x51fea9: e892010000 CALL 0x00520040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00520040u,5373614u); flags=s.arithmetic_flags;
  }
  L0051feae: { // 0x51feae: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0051feb3: { // 0x51feb3: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0051feb5: { // 0x51feb5: e87601fcff CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,5373626u); flags=s.arithmetic_flags;
  }
  L0051feba: { // 0x51feba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0051febb: { // 0x51febb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0051febc: { // 0x51febc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0051febf: { // 0x51febf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00520040(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00520040: { // 0x520040: a1e8a68100 MOV EAX,[0x0081a6e8]
    s.ax = m.r32((0x0081a6e8u));
  }
  L00520045: { // 0x520045: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00520048: { // 0x520048: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00520049: { // 0x520049: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0052004d: { // 0x52004d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0052004e: { // 0x52004e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0052004f: { // 0x52004f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00520051: { // 0x520051: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00520052: { // 0x520052: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00520054: { // 0x520054: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00520056: { // 0x520056: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00520058: { // 0x520058: 7e1f JLE 0x00520079
    if(integer::condition("JLE",flags)) goto L00520079;
  }
  L0052005a: { // 0x52005a: a1dca68100 MOV EAX,[0x0081a6dc]
    s.ax = m.r32((0x0081a6dcu));
  }
  L0052005f: { // 0x52005f: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L00520062: { // 0x520062: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00520066: { // 0x520066: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00520067: { // 0x520067: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00520068: { // 0x520068: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0052006a: { // 0x52006a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0052006b: { // 0x52006b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0052006c: { // 0x52006c: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),5374063u); flags=s.arithmetic_flags;
  }
  L0052006f: { // 0x52006f: a1e8a68100 MOV EAX,[0x0081a6e8]
    s.ax = m.r32((0x0081a6e8u));
  }
  L00520074: { // 0x520074: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00520075: { // 0x520075: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00520077: { // 0x520077: 7ce1 JL 0x0052005a
    if(integer::condition("JL",flags)) goto L0052005a;
  }
  L00520079: { // 0x520079: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  L0052007e: { // 0x52007e: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00520080: { // 0x520080: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00520082: { // 0x520082: 7e2f JLE 0x005200b3
    if(integer::condition("JLE",flags)) goto L005200b3;
  }
  L00520084: { // 0x520084: 8b0d04eaa900 MOV ECX,dword ptr [0x00a9ea04]
    s.cx = m.r32((0x00a9ea04u));
  }
  L0052008a: { // 0x52008a: 8b04b1 MOV EAX,dword ptr [ECX + ESI*0x4]
    s.ax = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L0052008d: { // 0x52008d: 83b81003000001 CMP dword ptr [EAX + 0x310],0x1
    (void)integer::sub(m.r32((s.ax+0x00000310u)),0x00000001u,32,flags);
  }
  L00520094: { // 0x520094: 7e13 JLE 0x005200a9
    if(integer::condition("JLE",flags)) goto L005200a9;
  }
  L00520096: { // 0x520096: 8b880c030000 MOV ECX,dword ptr [EAX + 0x30c]
    s.cx = m.r32((s.ax+0x0000030cu));
  }
  L0052009c: { // 0x52009c: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005200a0: { // 0x5200a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005200a1: { // 0x5200a1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005200a2: { // 0x5200a2: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005200a4: { // 0x5200a4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005200a5: { // 0x5200a5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005200a6: { // 0x5200a6: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),5374121u); flags=s.arithmetic_flags;
  }
  L005200a9: { // 0x5200a9: a110eaa900 MOV EAX,[0x00a9ea10]
    s.ax = m.r32((0x00a9ea10u));
  }
  L005200ae: { // 0x5200ae: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005200af: { // 0x5200af: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L005200b1: { // 0x5200b1: 7cd1 JL 0x00520084
    if(integer::condition("JL",flags)) goto L00520084;
  }
  L005200b3: { // 0x5200b3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005200b5: { // 0x5200b5: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L005200b9: { // 0x5200b9: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005200bd: { // 0x5200bd: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005200c1: { // 0x5200c1: 8844241c MOV byte ptr [ESP + 0x1c],AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L005200c5: { // 0x5200c5: e856b10d00 CALL 0x005fb220
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fb220u,5374154u); flags=s.arithmetic_flags;
  }
  L005200ca: { // 0x5200ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005200cc: { // 0x5200cc: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005200d0: { // 0x5200d0: 7444 JZ 0x00520116
    if(integer::condition("JZ",flags)) goto L00520116;
  }
  L005200d2: { // 0x5200d2: e819b70d00 CALL 0x005fb7f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fb7f0u,5374167u); flags=s.arithmetic_flags;
  }
  L005200d7: { // 0x5200d7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005200d9: { // 0x5200d9: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005200dd: { // 0x5200dd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005200df: { // 0x5200df: 7e24 JLE 0x00520105
    if(integer::condition("JLE",flags)) goto L00520105;
  }
  L005200e1: { // 0x5200e1: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L005200e5: { // 0x5200e5: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L005200e8: { // 0x5200e8: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  L005200eb: { // 0x5200eb: 8b880c030000 MOV ECX,dword ptr [EAX + 0x30c]
    s.cx = m.r32((s.ax+0x0000030cu));
  }
  L005200f1: { // 0x5200f1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005200f5: { // 0x5200f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005200f6: { // 0x5200f6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005200f7: { // 0x5200f7: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005200f9: { // 0x5200f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005200fa: { // 0x5200fa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005200fb: { // 0x5200fb: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),5374206u); flags=s.arithmetic_flags;
  }
  L005200fe: { // 0x5200fe: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005200ff: { // 0x5200ff: 3b742410 CMP ESI,dword ptr [ESP + 0x10]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L00520103: { // 0x520103: 7cdc JL 0x005200e1
    if(integer::condition("JL",flags)) goto L005200e1;
  }
  L00520105: { // 0x520105: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00520109: { // 0x520109: e812b10d00 CALL 0x005fb220
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fb220u,5374222u); flags=s.arithmetic_flags;
  }
  L0052010e: { // 0x52010e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00520110: { // 0x520110: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00520114: { // 0x520114: 75bc JNZ 0x005200d2
    if(integer::condition("JNZ",flags)) goto L005200d2;
  }
  L00520116: { // 0x520116: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0052011b: { // 0x52011b: e8f0e1f7ff CALL 0x0049e310
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049e310u,5374240u); flags=s.arithmetic_flags;
  }
  L00520120: { // 0x520120: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00520121: { // 0x520121: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00520122: { // 0x520122: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00520123: { // 0x520123: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00520124: { // 0x520124: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00520127: { // 0x520127: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
