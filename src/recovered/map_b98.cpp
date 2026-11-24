#include "recovered/map_b98_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::map_b98 {
namespace {
void f_002c69a0(Memory&,State&,Frame&,const Operations&);
void f_000f47b0(Memory&,State&,Frame&,const Operations&);
void f_00234310(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b540(Memory&,State&,Frame&,const Operations&);
void f_0007b480(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_0007b460(Memory&,State&,Frame&,const Operations&);
void f_00185830(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0007b4e0(Memory&,State&,Frame&,const Operations&);
void f_0007b500(Memory&,State&,Frame&,const Operations&);
void f_0007b3e0(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);










void f_002c69a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c69a0: 8b8108040000 MOV EAX,dword ptr [ECX + 0x408]
    s.ax = m.r32((s.cx+0x00000408u));
  }
  { // 0x6c69a6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000f47b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f47b0: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x4f47b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f47b7: 751d JNZ 0x004f47d6
    if(integer::condition("JNZ",flags)) goto L004f47d6;
  }
  { // 0x4f47b9: 8a8134010000 MOV AL,byte ptr [ECX + 0x134]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000134u)));
  }
  { // 0x4f47bf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4f47c1: 750d JNZ 0x004f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  { // 0x4f47c3: 8a8135010000 MOV AL,byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  { // 0x4f47c9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4f47cb: 7503 JNZ 0x004f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  { // 0x4f47cd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4f47cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d0: { // 0x4f47d0: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4f47d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d6: { // 0x4f47d6: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  { // 0x4f47dc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4f47de: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x4f47e0: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x4f47e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00234310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x634310: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x634311: 8a19 MOV BL,byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  { // 0x634313: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x634314: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x634318: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x634319: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x63431d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x63431f: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  { // 0x634321: 8a07 MOV AL,byte ptr [EDI]
    s.ax = with_al(s.ax, m.r8((s.di)));
  }
  { // 0x634323: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x634329: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  { // 0x63432f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x634331: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  { // 0x634334: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x634335: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x63433b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x63433d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x634340: 02c3 ADD AL,BL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  { // 0x634342: 8a5901 MOV BL,byte ptr [ECX + 0x1]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000001u)));
  }
  { // 0x634345: 8801 MOV byte ptr [ECX],AL
    m.w8((s.cx), (s.ax & 0xffu));
  }
  { // 0x634347: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x634349: 8a4701 MOV AL,byte ptr [EDI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000001u)));
  }
  { // 0x63434c: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  { // 0x63434e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x634354: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x634356: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  { // 0x634359: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x63435a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x634360: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x634362: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x634365: 02c3 ADD AL,BL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  { // 0x634367: 8a5902 MOV BL,byte ptr [ECX + 0x2]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000002u)));
  }
  { // 0x63436a: 884101 MOV byte ptr [ECX + 0x1],AL
    m.w8((s.cx+0x00000001u), (s.ax & 0xffu));
  }
  { // 0x63436d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x63436f: 8a4702 MOV AL,byte ptr [EDI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000002u)));
  }
  { // 0x634372: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  { // 0x634374: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x63437a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63437b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x63437d: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  { // 0x634380: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x634381: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x634387: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x634388: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x63438a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x63438d: 02c3 ADD AL,BL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  { // 0x63438f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x634390: 884102 MOV byte ptr [ECX + 0x2],AL
    m.w8((s.cx+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x634393: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007b540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b540: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x47b543: 8b0da4a8a300 MOV ECX,dword ptr [0x00a3a8a4]
    s.cx = m.r32((0x00a3a8a4u));
  }
  { // 0x47b549: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b54b: 7c0a JL 0x0047b557
    if(integer::condition("JL",flags)) goto L0047b557;
  }
  { // 0x47b54d: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  { // 0x47b550: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b552: 7d03 JGE 0x0047b557
    if(integer::condition("JGE",flags)) goto L0047b557;
  }
  { // 0x47b554: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b556: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b557: { // 0x47b557: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47b559: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b480: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x47b483: 8b0d185da500 MOV ECX,dword ptr [0x00a55d18]
    s.cx = m.r32((0x00a55d18u));
  }
  { // 0x47b489: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b48b: 7c0a JL 0x0047b497
    if(integer::condition("JL",flags)) goto L0047b497;
  }
  { // 0x47b48d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  { // 0x47b490: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b492: 7d03 JGE 0x0047b497
    if(integer::condition("JGE",flags)) goto L0047b497;
  }
  { // 0x47b494: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b496: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b497: { // 0x47b497: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47b499: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b190: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x47b193: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  { // 0x47b198: 7407 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  { // 0x47b19a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47b19c: 7403 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  { // 0x47b19e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b460: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x47b463: 8b0d2caba300 MOV ECX,dword ptr [0x00a3ab2c]
    s.cx = m.r32((0x00a3ab2cu));
  }
  { // 0x47b469: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b46b: 7c0a JL 0x0047b477
    if(integer::condition("JL",flags)) goto L0047b477;
  }
  { // 0x47b46d: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  { // 0x47b470: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b472: 7d03 JGE 0x0047b477
    if(integer::condition("JGE",flags)) goto L0047b477;
  }
  { // 0x47b474: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b476: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b477: { // 0x47b477: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47b479: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00185830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x585830: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x585833: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x585834: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x585835: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x585837: 8854240b MOV byte ptr [ESP + 0xb],DL
    m.w8((f.sp+0x0000000bu), (s.dx & 0xffu));
  }
  { // 0x58583b: 8b0d3486a500 MOV ECX,dword ptr [0x00a58634]
    s.cx = m.r32((0x00a58634u));
  }
  { // 0x585841: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x585842: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  { // 0x585845: 8b5d04 MOV EBX,dword ptr [EBP + 0x4]
    s.bx = m.r32((s.bp+0x00000004u));
  }
  { // 0x585848: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x58584b: 0fbfd3 MOVSX EDX,BX
    s.dx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  { // 0x58584e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58584f: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  { // 0x585853: 8d3c32 LEA EDI,[EDX + ESI*0x1]
    s.di = (s.dx+(s.si * 0x00000001u));
  }
  { // 0x585856: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x585858: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  { // 0x58585c: 0f8ea8010000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  { // 0x585862: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x585864: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  { // 0x585866: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x585868: 0f8d9c010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x58586e: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585870: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x585872: 0f8d92010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x585878: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x58587c: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  { // 0x585882: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585884: 0f8f80010000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  { // 0x58588a: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  { // 0x58588d: 8d7410ff LEA ESI,[EAX + EDX*0x1 + -0x1]
    s.si = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  { // 0x585891: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x585894: 0fbff3 MOVSX ESI,BX
    s.si = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  { // 0x585897: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  { // 0x58589a: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x58589c: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  { // 0x5858a0: 0f8e64010000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  { // 0x5858a6: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  { // 0x5858a8: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  { // 0x5858aa: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x5858ac: 0f8d58010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x5858b2: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  { // 0x5858b4: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x5858b6: 0f8d4e010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x5858bc: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  { // 0x5858c2: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x5858c6: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  { // 0x5858c8: 0f8f3c010000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  { // 0x5858ce: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  { // 0x5858d1: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x5858d5: 8d743eff LEA ESI,[ESI + EDI*0x1 + -0x1]
    s.si = (s.si+(s.di * 0x00000001u)-0x00000001u);
  }
  { // 0x5858d9: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  { // 0x5858dd: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x5858e0: 0fbff6 MOVSX ESI,SI
    s.si = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x5858e3: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  { // 0x5858e6: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x5858e8: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  { // 0x5858ec: 0f8e18010000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  { // 0x5858f2: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  { // 0x5858f4: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  { // 0x5858f6: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x5858f8: 0f8d0c010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x5858fe: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  { // 0x585900: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x585902: 0f8d02010000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x585908: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  { // 0x58590c: 8b3d3886a500 MOV EDI,dword ptr [0x00a58638]
    s.di = m.r32((0x00a58638u));
  }
  { // 0x585912: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x585914: 0f8ff0000000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  { // 0x58591a: 8d7410ff LEA ESI,[EAX + EDX*0x1 + -0x1]
    s.si = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  { // 0x58591e: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x585921: 0fbf74241c MOVSX ESI,word ptr [ESP + 0x1c]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001cu)),16));
  }
  { // 0x585926: 8d1c3e LEA EBX,[ESI + EDI*0x1]
    s.bx = (s.si+(s.di * 0x00000001u));
  }
  { // 0x585929: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x58592b: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  { // 0x58592f: 0f8ed5000000 JLE 0x00585a0a
    if(integer::condition("JLE",flags)) goto L00585a0a;
  }
  { // 0x585935: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  { // 0x585937: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  { // 0x585939: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x58593b: 0f8dc9000000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x585941: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  { // 0x585943: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x585945: 0f8dbf000000 JGE 0x00585a0a
    if(integer::condition("JGE",flags)) goto L00585a0a;
  }
  { // 0x58594b: 8b0d3886a500 MOV ECX,dword ptr [0x00a58638]
    s.cx = m.r32((0x00a58638u));
  }
  { // 0x585951: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  { // 0x585955: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x585957: 0f8fad000000 JG 0x00585a0a
    if(integer::condition("JG",flags)) goto L00585a0a;
  }
  { // 0x58595d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x585961: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  { // 0x585964: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  { // 0x585966: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  { // 0x585968: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x58596a: 0f8d8e000000 JGE 0x005859fe
    if(integer::condition("JGE",flags)) goto L005859fe;
  }
  L00585970: { // 0x585970: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x585972: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  { // 0x585975: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x585977: 7d74 JGE 0x005859ed
    if(integer::condition("JGE",flags)) goto L005859ed;
  }
  L00585979: { // 0x585979: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x58597d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x585982: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x585983: 66897c2418 MOV word ptr [ESP + 0x18],DI
    m.w16((f.sp+0x00000018u), (s.di & 0xffffu));
  }
  { // 0x585988: 66895c241a MOV word ptr [ESP + 0x1a],BX
    m.w16((f.sp+0x0000001au), (s.bx & 0xffffu));
  }
  { // 0x58598d: e86efbfbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5790098u); flags=s.arithmetic_flags;
  }
  { // 0x585992: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x585994: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x585996: e8455befff CALL 0x0047b4e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b4e0u,5790107u); flags=s.arithmetic_flags;
  }
  { // 0x58599b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x58599d: 740a JZ 0x005859a9
    if(integer::condition("JZ",flags)) goto L005859a9;
  }
  { // 0x58599f: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  { // 0x5859a3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5859a5: 7463 JZ 0x00585a0a
    if(integer::condition("JZ",flags)) goto L00585a0a;
  }
  { // 0x5859a7: eb36 JMP 0x005859df
    goto L005859df;
  }
  L005859a9: { // 0x5859a9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5859ab: e8505befff CALL 0x0047b500
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b500u,5790128u); flags=s.arithmetic_flags;
  }
  { // 0x5859b0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5859b2: 740a JZ 0x005859be
    if(integer::condition("JZ",flags)) goto L005859be;
  }
  { // 0x5859b4: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  { // 0x5859b8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5859ba: 744e JZ 0x00585a0a
    if(integer::condition("JZ",flags)) goto L00585a0a;
  }
  { // 0x5859bc: eb21 JMP 0x005859df
    goto L005859df;
  }
  L005859be: { // 0x5859be: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5859c0: e8cb57efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5790149u); flags=s.arithmetic_flags;
  }
  { // 0x5859c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5859c7: 7516 JNZ 0x005859df
    if(integer::condition("JNZ",flags)) goto L005859df;
  }
  { // 0x5859c9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5859cb: e8905aefff CALL 0x0047b460
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b460u,5790160u); flags=s.arithmetic_flags;
  }
  { // 0x5859d0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5859d2: 750b JNZ 0x005859df
    if(integer::condition("JNZ",flags)) goto L005859df;
  }
  { // 0x5859d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5859d6: e8a55aefff CALL 0x0047b480
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b480u,5790171u); flags=s.arithmetic_flags;
  }
  { // 0x5859db: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5859dd: 742b JZ 0x00585a0a
    if(integer::condition("JZ",flags)) goto L00585a0a;
  }
  L005859df: { // 0x5859df: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  { // 0x5859e2: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  { // 0x5859e5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5859e6: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  { // 0x5859e9: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x5859eb: 7c8c JL 0x00585979
    if(integer::condition("JL",flags)) goto L00585979;
  }
  L005859ed: { // 0x5859ed: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    s.cx = m.r32((s.bp+0x00000004u));
  }
  { // 0x5859f0: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  { // 0x5859f3: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x5859f4: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  { // 0x5859f6: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x5859f8: 0f8c72ffffff JL 0x00585970
    if(integer::condition("JL",flags)) goto L00585970;
  }
  L005859fe: { // 0x5859fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5859ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x585a00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x585a01: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x585a03: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x585a04: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x585a07: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00585a0a: { // 0x585a0a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x585a0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x585a0c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x585a0d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x585a0f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x585a10: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x585a13: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b4e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b4e0: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x47b4e3: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  { // 0x47b4e9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b4eb: 7c0a JL 0x0047b4f7
    if(integer::condition("JL",flags)) goto L0047b4f7;
  }
  { // 0x47b4ed: 83c10f ADD ECX,0xf
    s.cx = integer::add(s.cx,0x0000000fu,32,flags);
  }
  { // 0x47b4f0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b4f2: 7d03 JGE 0x0047b4f7
    if(integer::condition("JGE",flags)) goto L0047b4f7;
  }
  { // 0x47b4f4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b4f6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b4f7: { // 0x47b4f7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47b4f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b500: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x47b503: 8b0d4059a500 MOV ECX,dword ptr [0x00a55940]
    s.cx = m.r32((0x00a55940u));
  }
  { // 0x47b509: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b50b: 7c0a JL 0x0047b517
    if(integer::condition("JL",flags)) goto L0047b517;
  }
  { // 0x47b50d: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x47b510: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b512: 7d03 JGE 0x0047b517
    if(integer::condition("JGE",flags)) goto L0047b517;
  }
  { // 0x47b514: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b516: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b517: { // 0x47b517: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47b519: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b3e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47b3e0: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x47b3e3: 8b0dac47a500 MOV ECX,dword ptr [0x00a547ac]
    s.cx = m.r32((0x00a547acu));
  }
  { // 0x47b3e9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b3eb: 7c0a JL 0x0047b3f7
    if(integer::condition("JL",flags)) goto L0047b3f7;
  }
  { // 0x47b3ed: 83c12a ADD ECX,0x2a
    s.cx = integer::add(s.cx,0x0000002au,32,flags);
  }
  { // 0x47b3f0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b3f2: 7d03 JGE 0x0047b3f7
    if(integer::condition("JGE",flags)) goto L0047b3f7;
  }
  { // 0x47b3f4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b3f6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b3f7: { // 0x47b3f7: 8b0db8a1a300 MOV ECX,dword ptr [0x00a3a1b8]
    s.cx = m.r32((0x00a3a1b8u));
  }
  { // 0x47b3fd: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b3ff: 7c07 JL 0x0047b408
    if(integer::condition("JL",flags)) goto L0047b408;
  }
  { // 0x47b401: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  { // 0x47b404: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b406: 7c44 JL 0x0047b44c
    if(integer::condition("JL",flags)) goto L0047b44c;
  }
  L0047b408: { // 0x47b408: 8b0dbca1a300 MOV ECX,dword ptr [0x00a3a1bc]
    s.cx = m.r32((0x00a3a1bcu));
  }
  { // 0x47b40e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b410: 7c07 JL 0x0047b419
    if(integer::condition("JL",flags)) goto L0047b419;
  }
  { // 0x47b412: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x47b415: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b417: 7c33 JL 0x0047b44c
    if(integer::condition("JL",flags)) goto L0047b44c;
  }
  L0047b419: { // 0x47b419: 8b0d904ba500 MOV ECX,dword ptr [0x00a54b90]
    s.cx = m.r32((0x00a54b90u));
  }
  { // 0x47b41f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b421: 7c07 JL 0x0047b42a
    if(integer::condition("JL",flags)) goto L0047b42a;
  }
  { // 0x47b423: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x47b426: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b428: 7c22 JL 0x0047b44c
    if(integer::condition("JL",flags)) goto L0047b44c;
  }
  L0047b42a: { // 0x47b42a: 8b0dd8aaa300 MOV ECX,dword ptr [0x00a3aad8]
    s.cx = m.r32((0x00a3aad8u));
  }
  { // 0x47b430: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b432: 7c07 JL 0x0047b43b
    if(integer::condition("JL",flags)) goto L0047b43b;
  }
  { // 0x47b434: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x47b437: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b439: 7c11 JL 0x0047b44c
    if(integer::condition("JL",flags)) goto L0047b44c;
  }
  L0047b43b: { // 0x47b43b: 8b0d28aba300 MOV ECX,dword ptr [0x00a3ab28]
    s.cx = m.r32((0x00a3ab28u));
  }
  { // 0x47b441: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b443: 7c0a JL 0x0047b44f
    if(integer::condition("JL",flags)) goto L0047b44f;
  }
  { // 0x47b445: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x47b448: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47b44a: 7d03 JGE 0x0047b44f
    if(integer::condition("JGE",flags)) goto L0047b44f;
  }
  L0047b44c: { // 0x47b44c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47b44e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b44f: { // 0x47b44f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47b451: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x557450: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x557454: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x557455: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x557459: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x55745a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x55745b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x55745d: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  { // 0x557461: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x557462: 0fbf3b MOVSX EDI,word ptr [EBX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  { // 0x557465: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x557467: 7454 JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  { // 0x557469: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x55746b: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x55746e: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x557470: 7814 JS 0x00557486
    if(integer::condition("JS",flags)) goto L00557486;
  }
  { // 0x557472: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x557477: 7d0d JGE 0x00557486
    if(integer::condition("JGE",flags)) goto L00557486;
  }
  { // 0x557479: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  { // 0x55747f: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  { // 0x557482: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x557484: 750c JNZ 0x00557492
    if(integer::condition("JNZ",flags)) goto L00557492;
  }
  L00557486: { // 0x557486: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x557488: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  { // 0x55748d: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00557492: { // 0x557492: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  { // 0x557498: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x55749f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x5574a1: 741a JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  { // 0x5574a3: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  { // 0x5574a9: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  { // 0x5574af: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  { // 0x5574b3: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  { // 0x5574b6: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x5574b8: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x5574ba: 7d01 JGE 0x005574bd
    if(integer::condition("JGE",flags)) goto L005574bd;
  }
  { // 0x5574bc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005574bd: { // 0x5574bd: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  { // 0x5574c3: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  { // 0x5574c9: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  { // 0x5574cc: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  { // 0x5574cf: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  { // 0x5574d1: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  { // 0x5574d3: 7e49 JLE 0x0055751e
    if(integer::condition("JLE",flags)) goto L0055751e;
  }
  { // 0x5574d5: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  { // 0x5574db: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  { // 0x5574e1: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  { // 0x5574e3: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  { // 0x5574e7: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  { // 0x5574e9: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  { // 0x5574ec: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x5574ee: 7f2e JG 0x0055751e
    if(integer::condition("JG",flags)) goto L0055751e;
  }
  { // 0x5574f0: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  { // 0x5574f6: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  { // 0x5574fc: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  { // 0x5574fe: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  { // 0x557500: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x557502: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x557504: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  { // 0x557506: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x557508: 7d14 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  { // 0x55750a: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  { // 0x55750d: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x55750f: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x557511: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x557513: 7d09 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  { // 0x557515: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x557516: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x557517: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x557518: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x55751a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x55751b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055751e: { // 0x55751e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x55751f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x557520: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x557521: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x557523: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x557524: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0002add0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42add0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x42add4: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  { // 0x42add7: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  { // 0x42addb: 66034102 ADD AX,word ptr [ECX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+0x00000002u)),16,flags));
  }
  { // 0x42addf: 660311 ADD DX,word ptr [ECX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.cx)),16,flags));
  }
  { // 0x42ade2: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  { // 0x42ade7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x42adeb: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  { // 0x42adf0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x42adf4: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x42adf6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  { // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7104928u:f_002c69a0(m,s,child,{});break;
case 5195696u:f_000f47b0(m,s,child,{});break;
case 6505232u:f_00234310(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4699456u:f_0007b540(m,s,child,{});break;
case 4699264u:f_0007b480(m,s,child,{});break;
case 4698512u:f_0007b190(m,s,child,{});break;
case 4699232u:f_0007b460(m,s,child,{});break;
case 5789744u:f_00185830(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4699360u:f_0007b4e0(m,s,child,{});break;
case 4699392u:f_0007b500(m,s,child,{});break;
case 4699104u:f_0007b3e0(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 4369872u:f_0002add0(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
default:throw std::domain_error("map98 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00427d40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x427d40: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  { // 0x427d43: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x427d44: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x427d45: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x427d46: 8b9000001000 MOV EDX,dword ptr [EAX + 0x100000]
    s.dx = m.r32((s.ax+0x00100000u));
  }
  { // 0x427d4c: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x427d50: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x427d52: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x427d53: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x427d56: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x427d58: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x427d59: 899000001000 MOV dword ptr [EAX + 0x100000],EDX
    m.w32((s.ax+0x00100000u), s.dx);
  }
  { // 0x427d5f: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  { // 0x427d62: 8b9000001800 MOV EDX,dword ptr [EAX + 0x180000]
    s.dx = m.r32((s.ax+0x00180000u));
  }
  { // 0x427d68: 8d3c52 LEA EDI,[EDX + EDX*0x2]
    s.di = (s.dx+(s.dx * 0x00000002u));
  }
  { // 0x427d6b: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x427d6c: 899000001800 MOV dword ptr [EAX + 0x180000],EDX
    m.w32((s.ax+0x00180000u), s.dx);
  }
  { // 0x427d72: 8d3cb8 LEA EDI,[EAX + EDI*0x4]
    s.di = (s.ax+(s.di * 0x00000004u));
  }
  { // 0x427d75: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x427d79: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x427d7b: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  { // 0x427d7d: 7477 JZ 0x00427df6
    if(integer::condition("JZ",flags)) goto L00427df6;
  }
  { // 0x427d7f: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x427d81: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  { // 0x427d84: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x427d86: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x427d88: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  { // 0x427d8a: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x427d91: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  { // 0x427d93: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  { // 0x427d96: f7804001000000010000 TEST dword ptr [EAX + 0x140],0x100
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(0x00000100u),32,flags);
  }
  { // 0x427da0: 7461 JZ 0x00427e03
    if(integer::condition("JZ",flags)) goto L00427e03;
  }
  { // 0x427da2: 8ba940010000 MOV EBP,dword ptr [ECX + 0x140]
    s.bp = m.r32((s.cx+0x00000140u));
  }
  { // 0x427da8: 81e500010000 AND EBP,0x100
    s.bp = integer::logical((s.bp)&(0x00000100u),32,flags);
  }
  { // 0x427dae: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  { // 0x427db2: 741d JZ 0x00427dd1
    if(integer::condition("JZ",flags)) goto L00427dd1;
  }
  { // 0x427db4: 0fbe891b010000 MOVSX ECX,byte ptr [ECX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  { // 0x427dbb: 8b2b MOV EBP,dword ptr [EBX]
    s.bp = m.r32((s.bx));
  }
  { // 0x427dbd: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x427dc0: 394d04 CMP dword ptr [EBP + 0x4],ECX
    (void)integer::sub(m.r32((s.bp+0x00000004u)),s.cx,32,flags);
  }
  { // 0x427dc3: 7508 JNZ 0x00427dcd
    if(integer::condition("JNZ",flags)) goto L00427dcd;
  }
  { // 0x427dc5: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  { // 0x427dc8: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  { // 0x427dcb: eb36 JMP 0x00427e03
    goto L00427e03;
  }
  L00427dcd: { // 0x427dcd: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00427dd1: { // 0x427dd1: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x427dd3: 752e JNZ 0x00427e03
    if(integer::condition("JNZ",flags)) goto L00427e03;
  }
  { // 0x427dd5: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x427dd7: 0fbe801b010000 MOVSX EAX,byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x427dde: 2b4204 SUB EAX,dword ptr [EDX + 0x4]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000004u)),32,flags);
  }
  { // 0x427de1: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  { // 0x427de4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x427de5: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  { // 0x427de7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x427de9: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x427dec: 7f15 JG 0x00427e03
    if(integer::condition("JG",flags)) goto L00427e03;
  }
  { // 0x427dee: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x427df1: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  { // 0x427df4: eb0a JMP 0x00427e00
    goto L00427e00;
  }
  L00427df6: { // 0x427df6: c7470800000000 MOV dword ptr [EDI + 0x8],0x0
    m.w32((s.di+0x00000008u), 0x00000000u);
  }
  { // 0x427dfd: 8b4130 MOV EAX,dword ptr [ECX + 0x30]
    s.ax = m.r32((s.cx+0x00000030u));
  }
  L00427e00: { // 0x427e00: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00427e03: { // 0x427e03: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x427e05: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  { // 0x427e07: 7413 JZ 0x00427e1c
    if(integer::condition("JZ",flags)) goto L00427e1c;
  }
  { // 0x427e09: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  { // 0x427e0d: d84304 FADD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.add32(m.r32(address));
  }
  { // 0x427e10: d95e04 FSTP float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x427e13: 8b4b0c MOV ECX,dword ptr [EBX + 0xc]
    s.cx = m.r32((s.bx+0x0000000cu));
  }
  { // 0x427e16: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x427e17: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  { // 0x427e1a: eb0e JMP 0x00427e2a
    goto L00427e2a;
  }
  L00427e1c: { // 0x427e1c: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x427e23: c7460c01000000 MOV dword ptr [ESI + 0xc],0x1
    m.w32((s.si+0x0000000cu), 0x00000001u);
  }
  L00427e2a: { // 0x427e2a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x427e2e: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x427e32: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x427e35: 8b3a MOV EDI,dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
  { // 0x427e37: 0fbf0b MOVSX ECX,word ptr [EBX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  { // 0x427e3a: 0fbf4724 MOVSX EAX,word ptr [EDI + 0x24]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000024u)),16));
  }
  { // 0x427e3e: 83c724 ADD EDI,0x24
    s.di = integer::add(s.di,0x00000024u,32,flags);
  }
  { // 0x427e41: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x427e43: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x427e44: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x427e46: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  { // 0x427e4a: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  { // 0x427e4c: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x427e4e: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  { // 0x427e52: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x427e54: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x427e55: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  { // 0x427e57: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x427e59: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x427e5b: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
  { // 0x427e5e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x427e60: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  { // 0x427e63: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x427e65: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  { // 0x427e69: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  { // 0x427e6d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x427e70: e80b220900 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4357749u); flags=s.arithmetic_flags;
  }
  { // 0x427e75: d84604 FADD float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.add32(m.r32(address));
  }
  { // 0x427e78: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x427e7b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x427e7d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x427e7e: d95e08 FSTP float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x427e81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x427e82: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x427e83: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x427e84: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00479b70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x479b70: 668b8116010000 MOV AX,word ptr [ECX + 0x116]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x00000116u)));
  }
  { // 0x479b77: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  { // 0x479b7a: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  { // 0x479b7d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x479b7e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x479b7f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x479b80: bb0a000000 MOV EBX,0xa
    s.bx = 0x0000000au;
  }
  { // 0x479b85: 7c1e JL 0x00479ba5
    if(integer::condition("JL",flags)) goto L00479ba5;
  }
  { // 0x479b87: 8b1508e58400 MOV EDX,dword ptr [0x0084e508]
    s.dx = m.r32((0x0084e508u));
  }
  { // 0x479b8d: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x479b90: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x479b92: 7d11 JGE 0x00479ba5
    if(integer::condition("JGE",flags)) goto L00479ba5;
  }
  { // 0x479b94: 3999ec000000 CMP dword ptr [ECX + 0xec],EBX
    (void)integer::sub(m.r32((s.cx+0x000000ecu)),s.bx,32,flags);
  }
  { // 0x479b9a: 7509 JNZ 0x00479ba5
    if(integer::condition("JNZ",flags)) goto L00479ba5;
  }
  { // 0x479b9c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x479b9d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x479b9e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x479ba0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x479ba1: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x479ba4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00479ba5: { // 0x479ba5: 8b4924 MOV ECX,dword ptr [ECX + 0x24]
    s.cx = m.r32((s.cx+0x00000024u));
  }
  { // 0x479ba8: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x479bac: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  { // 0x479bb0: 68ac9d8300 PUSH 0x839dac
    f.push(m,0x00839dacu);
  }
  { // 0x479bb5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x479bb6: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x479bba: e81112fbff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,4692927u); flags=s.arithmetic_flags;
  }
  { // 0x479bbf: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x479bc1: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x479bc6: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x479bca: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x479bce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x479bcf: e82cb90c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4692948u); flags=s.arithmetic_flags;
  }
  { // 0x479bd4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x479bd6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x479bd8: 0f8434010000 JZ 0x00479d12
    if(integer::condition("JZ",flags)) goto L00479d12;
  }
  { // 0x479bde: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x479be1: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x479be5: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  { // 0x479be9: 68ac9d8300 PUSH 0x839dac
    f.push(m,0x00839dacu);
  }
  { // 0x479bee: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x479bef: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x479bf3: e8d811fbff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,4692984u); flags=s.arithmetic_flags;
  }
  { // 0x479bf8: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x479bfa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x479bff: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x479c03: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  { // 0x479c07: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x479c08: e8f3b80c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4693005u); flags=s.arithmetic_flags;
  }
  { // 0x479c0d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x479c0f: 0f84fd000000 JZ 0x00479d12
    if(integer::condition("JZ",flags)) goto L00479d12;
  }
  { // 0x479c15: 668b8e16010000 MOV CX,word ptr [ESI + 0x116]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000116u)));
  }
  { // 0x479c1c: 8b1508e58400 MOV EDX,dword ptr [0x0084e508]
    s.dx = m.r32((0x0084e508u));
  }
  { // 0x479c22: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  { // 0x479c25: 7c13 JL 0x00479c3a
    if(integer::condition("JL",flags)) goto L00479c3a;
  }
  { // 0x479c27: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x479c2a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x479c2c: 7d0c JGE 0x00479c3a
    if(integer::condition("JGE",flags)) goto L00479c3a;
  }
  { // 0x479c2e: 399eec000000 CMP dword ptr [ESI + 0xec],EBX
    (void)integer::sub(m.r32((s.si+0x000000ecu)),s.bx,32,flags);
  }
  { // 0x479c34: 0f84cf000000 JZ 0x00479d09
    if(integer::condition("JZ",flags)) goto L00479d09;
  }
  L00479c3a: { // 0x479c3a: 668b8816010000 MOV CX,word ptr [EAX + 0x116]
    s.cx = with_ax(s.cx, m.r16((s.ax+0x00000116u)));
  }
  { // 0x479c41: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  { // 0x479c44: 7c13 JL 0x00479c59
    if(integer::condition("JL",flags)) goto L00479c59;
  }
  { // 0x479c46: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x479c49: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x479c4b: 7d0c JGE 0x00479c59
    if(integer::condition("JGE",flags)) goto L00479c59;
  }
  { // 0x479c4d: 3998ec000000 CMP dword ptr [EAX + 0xec],EBX
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),s.bx,32,flags);
  }
  { // 0x479c53: 0f84b0000000 JZ 0x00479d09
    if(integer::condition("JZ",flags)) goto L00479d09;
  }
  L00479c59: { // 0x479c59: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x479c5c: 8b15b09d8300 MOV EDX,dword ptr [0x00839db0]
    s.dx = m.r32((0x00839db0u));
  }
  { // 0x479c62: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x479c66: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x479c68: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  { // 0x479c6d: 66a1b29d8300 MOV AX,[0x00839db2]
    s.ax = with_ax(s.ax, m.r16((0x00839db2u)));
  }
  { // 0x479c73: 6603442416 ADD AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  { // 0x479c78: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x479c7c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x479c7d: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  { // 0x479c82: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x479c86: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  { // 0x479c8a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x479c8f: e86cb80c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4693140u); flags=s.arithmetic_flags;
  }
  { // 0x479c94: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x479c98: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x479c9a: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x479c9d: 68a89d8300 PUSH 0x839da8
    f.push(m,0x00839da8u);
  }
  { // 0x479ca2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x479ca3: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x479ca7: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x479cab: e82011fbff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,4693168u); flags=s.arithmetic_flags;
  }
  { // 0x479cb0: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x479cb2: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x479cb6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x479cb7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x479cbc: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x479cc0: e83bb80c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4693189u); flags=s.arithmetic_flags;
  }
  { // 0x479cc5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x479cc7: 7449 JZ 0x00479d12
    if(integer::condition("JZ",flags)) goto L00479d12;
  }
  { // 0x479cc9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x479ccb: 7445 JZ 0x00479d12
    if(integer::condition("JZ",flags)) goto L00479d12;
  }
  { // 0x479ccd: 668b8f16010000 MOV CX,word ptr [EDI + 0x116]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000116u)));
  }
  { // 0x479cd4: 8b1508e58400 MOV EDX,dword ptr [0x0084e508]
    s.dx = m.r32((0x0084e508u));
  }
  { // 0x479cda: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  { // 0x479cdd: 7c0f JL 0x00479cee
    if(integer::condition("JL",flags)) goto L00479cee;
  }
  { // 0x479cdf: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x479ce2: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x479ce4: 7d08 JGE 0x00479cee
    if(integer::condition("JGE",flags)) goto L00479cee;
  }
  { // 0x479ce6: 399fec000000 CMP dword ptr [EDI + 0xec],EBX
    (void)integer::sub(m.r32((s.di+0x000000ecu)),s.bx,32,flags);
  }
  { // 0x479cec: 741b JZ 0x00479d09
    if(integer::condition("JZ",flags)) goto L00479d09;
  }
  L00479cee: { // 0x479cee: 668b8816010000 MOV CX,word ptr [EAX + 0x116]
    s.cx = with_ax(s.cx, m.r16((s.ax+0x00000116u)));
  }
  { // 0x479cf5: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  { // 0x479cf8: 7c18 JL 0x00479d12
    if(integer::condition("JL",flags)) goto L00479d12;
  }
  { // 0x479cfa: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x479cfd: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x479cff: 7d11 JGE 0x00479d12
    if(integer::condition("JGE",flags)) goto L00479d12;
  }
  { // 0x479d01: 3998ec000000 CMP dword ptr [EAX + 0xec],EBX
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),s.bx,32,flags);
  }
  { // 0x479d07: 7509 JNZ 0x00479d12
    if(integer::condition("JNZ",flags)) goto L00479d12;
  }
  L00479d09: { // 0x479d09: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x479d0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x479d0b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x479d0d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x479d0e: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x479d11: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00479d12: { // 0x479d12: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x479d13: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x479d14: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x479d16: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x479d17: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x479d1a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004c8330(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c8330: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4c8331: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4c8335: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4c8336: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c8337: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  { // 0x4c833b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c833c: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x4c8340: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4c8342: 7548 JNZ 0x004c838c
    if(integer::condition("JNZ",flags)) goto L004c838c;
  }
  { // 0x4c8344: 8d43fc LEA EAX,[EBX + -0x4]
    s.ax = (s.bx-0x00000004u);
  }
  { // 0x4c8347: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  { // 0x4c834a: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  { // 0x4c8352: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  { // 0x4c835a: 66034f24 ADD CX,word ptr [EDI + 0x24]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.di+0x00000024u)),16,flags));
  }
  { // 0x4c835e: 66035726 ADD DX,word ptr [EDI + 0x26]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.di+0x00000026u)),16,flags));
  }
  { // 0x4c8362: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  { // 0x4c8369: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  { // 0x4c836e: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  { // 0x4c8372: 6689542426 MOV word ptr [ESP + 0x26],DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  { // 0x4c8377: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  { // 0x4c837b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4c837c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x4c8381: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  { // 0x4c8385: e876d10700 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5014410u); flags=s.arithmetic_flags;
  }
  { // 0x4c838a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004c838c: { // 0x4c838c: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  { // 0x4c838f: 0f8479010000 JZ 0x004c850e
    if(integer::condition("JZ",flags)) goto L004c850e;
  }
  { // 0x4c8395: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4c8397: 0f8491010000 JZ 0x004c852e
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  { // 0x4c839d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4c839f: 0f8489010000 JZ 0x004c852e
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  { // 0x4c83a5: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4c83a9: 837d00ff CMP dword ptr [EBP],-0x1
    (void)integer::sub(m.r32((s.bp)),0xffffffffu,32,flags);
  }
  { // 0x4c83ad: 752f JNZ 0x004c83de
    if(integer::condition("JNZ",flags)) goto L004c83de;
  }
  { // 0x4c83af: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  { // 0x4c83b5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4c83b8: 7424 JZ 0x004c83de
    if(integer::condition("JZ",flags)) goto L004c83de;
  }
  { // 0x4c83ba: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  { // 0x4c83c1: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  { // 0x4c83c4: 895500 MOV dword ptr [EBP],EDX
    m.w32((s.bp), s.dx);
  }
  { // 0x4c83c7: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  { // 0x4c83cd: f6c402 TEST AH,0x2
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x4c83d0: 750c JNZ 0x004c83de
    if(integer::condition("JNZ",flags)) goto L004c83de;
  }
  { // 0x4c83d2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c83d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c83d4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c83d5: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c83da: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c83db: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c83de: { // 0x4c83de: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  { // 0x4c83e4: 0fbe9f1b010000 MOVSX EBX,byte ptr [EDI + 0x11b]
    s.bx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  { // 0x4c83eb: 2500010000 AND EAX,0x100
    s.ax = integer::logical((s.ax)&(0x00000100u),32,flags);
  }
  { // 0x4c83f0: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x4c83f4: 7409 JZ 0x004c83ff
    if(integer::condition("JZ",flags)) goto L004c83ff;
  }
  { // 0x4c83f6: 0fbe8e1b010000 MOVSX ECX,byte ptr [ESI + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  { // 0x4c83fd: eb03 JMP 0x004c8402
    goto L004c8402;
  }
  L004c83ff: { // 0x4c83ff: 8b4d00 MOV ECX,dword ptr [EBP]
    s.cx = m.r32((s.bp));
  }
  L004c8402: { // 0x4c8402: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x4c8404: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4c8406: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4c8407: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  { // 0x4c8409: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x4c840b: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  { // 0x4c840e: 0f84c4000000 JZ 0x004c84d8
    if(integer::condition("JZ",flags)) goto L004c84d8;
  }
  { // 0x4c8414: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4c8415: 0f848d000000 JZ 0x004c84a8
    if(integer::condition("JZ",flags)) goto L004c84a8;
  }
  { // 0x4c841b: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x4c841e: 740c JZ 0x004c842c
    if(integer::condition("JZ",flags)) goto L004c842c;
  }
  { // 0x4c8420: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c8421: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8422: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c8423: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c8428: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c8429: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c842c: { // 0x4c842c: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  { // 0x4c8433: 8d4bfc LEA ECX,[EBX + -0x4]
    s.cx = (s.bx-0x00000004u);
  }
  { // 0x4c8436: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4c8438: 7525 JNZ 0x004c845f
    if(integer::condition("JNZ",flags)) goto L004c845f;
  }
  { // 0x4c843a: 395d00 CMP dword ptr [EBP],EBX
    (void)integer::sub(m.r32((s.bp)),s.bx,32,flags);
  }
  { // 0x4c843d: 740c JZ 0x004c844b
    if(integer::condition("JZ",flags)) goto L004c844b;
  }
  { // 0x4c843f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c8440: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8441: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c8442: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c8447: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c8448: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c844b: { // 0x4c844b: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4c844f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4c8451: 750c JNZ 0x004c845f
    if(integer::condition("JNZ",flags)) goto L004c845f;
  }
  { // 0x4c8453: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c8454: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8455: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c8456: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c845b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c845c: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c845f: { // 0x4c845f: 83c0fc ADD EAX,-0x4
    s.ax = integer::add(s.ax,0xfffffffcu,32,flags);
  }
  { // 0x4c8462: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x4c8464: 0f85c4000000 JNZ 0x004c852e
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  { // 0x4c846a: 8bbf40010000 MOV EDI,dword ptr [EDI + 0x140]
    s.di = m.r32((s.di+0x00000140u));
  }
  { // 0x4c8470: f7c700010000 TEST EDI,0x100
    (void)integer::logical((s.di)&(0x00000100u),32,flags);
  }
  { // 0x4c8476: 750c JNZ 0x004c8484
    if(integer::condition("JNZ",flags)) goto L004c8484;
  }
  { // 0x4c8478: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c8479: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c847a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c847b: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c8480: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c8481: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c8484: { // 0x4c8484: f7c700020000 TEST EDI,0x200
    (void)integer::logical((s.di)&(0x00000200u),32,flags);
  }
  { // 0x4c848a: 750c JNZ 0x004c8498
    if(integer::condition("JNZ",flags)) goto L004c8498;
  }
  { // 0x4c848c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c848d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c848e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c848f: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c8494: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c8495: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c8498: { // 0x4c8498: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x4c849c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c849d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c849e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c849f: c60201 MOV byte ptr [EDX],0x1
    m.w8((s.dx), 0x00000001u);
  }
  { // 0x4c84a2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4c84a4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c84a5: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c84a8: { // 0x4c84a8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4c84aa: 7e16 JLE 0x004c84c2
    if(integer::condition("JLE",flags)) goto L004c84c2;
  }
  { // 0x4c84ac: 8a871c010000 MOV AL,byte ptr [EDI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  { // 0x4c84b2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c84b4: 7578 JNZ 0x004c852e
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  { // 0x4c84b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c84b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c84b8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c84b9: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c84be: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c84bf: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c84c2: { // 0x4c84c2: 8a861c010000 MOV AL,byte ptr [ESI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011cu)));
  }
  { // 0x4c84c8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c84ca: 7562 JNZ 0x004c852e
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  { // 0x4c84cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c84cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c84ce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c84cf: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c84d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c84d5: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c84d8: { // 0x4c84d8: 8bbf40010000 MOV EDI,dword ptr [EDI + 0x140]
    s.di = m.r32((s.di+0x00000140u));
  }
  { // 0x4c84de: f7c700010000 TEST EDI,0x100
    (void)integer::logical((s.di)&(0x00000100u),32,flags);
  }
  { // 0x4c84e4: 7410 JZ 0x004c84f6
    if(integer::condition("JZ",flags)) goto L004c84f6;
  }
  { // 0x4c84e6: f7c700020000 TEST EDI,0x200
    (void)integer::logical((s.di)&(0x00000200u),32,flags);
  }
  { // 0x4c84ec: 7408 JZ 0x004c84f6
    if(integer::condition("JZ",flags)) goto L004c84f6;
  }
  { // 0x4c84ee: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4c84f2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c84f4: 7538 JNZ 0x004c852e
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  L004c84f6: { // 0x4c84f6: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  { // 0x4c84f9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4c84fc: 7430 JZ 0x004c852e
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  { // 0x4c84fe: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x4c8500: 742c JZ 0x004c852e
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  { // 0x4c8502: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c8503: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8504: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c8505: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  { // 0x4c850a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c850b: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004c850e: { // 0x4c850e: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4c8512: 8338ff CMP dword ptr [EAX],-0x1
    (void)integer::sub(m.r32((s.ax)),0xffffffffu,32,flags);
  }
  { // 0x4c8515: 7517 JNZ 0x004c852e
    if(integer::condition("JNZ",flags)) goto L004c852e;
  }
  { // 0x4c8517: 8b8f40010000 MOV ECX,dword ptr [EDI + 0x140]
    s.cx = m.r32((s.di+0x00000140u));
  }
  { // 0x4c851d: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4c8520: 740c JZ 0x004c852e
    if(integer::condition("JZ",flags)) goto L004c852e;
  }
  { // 0x4c8522: 0fbe8f1b010000 MOVSX ECX,byte ptr [EDI + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  { // 0x4c8529: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x4c852c: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004c852e: { // 0x4c852e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c852f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8530: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c8531: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4c8533: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c8534: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00557700(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x557700: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x557701: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x557702: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x557703: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x557704: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x557706: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x557707: 8b8efc000000 MOV ECX,dword ptr [ESI + 0xfc]
    s.cx = m.r32((s.si+0x000000fcu));
  }
  { // 0x55770d: 8b9e04010000 MOV EBX,dword ptr [ESI + 0x104]
    s.bx = m.r32((s.si+0x00000104u));
  }
  { // 0x557713: 8bbef0000000 MOV EDI,dword ptr [ESI + 0xf0]
    s.di = m.r32((s.si+0x000000f0u));
  }
  { // 0x557719: 8b961c010000 MOV EDX,dword ptr [ESI + 0x11c]
    s.dx = m.r32((s.si+0x0000011cu));
  }
  { // 0x55771f: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  { // 0x557725: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  { // 0x557727: 8d4c4f0c LEA ECX,[EDI + ECX*0x2 + 0xc]
    s.cx = (s.di+(s.cx * 0x00000002u)+0x0000000cu);
  }
  { // 0x55772b: 8d1c10 LEA EBX,[EAX + EDX*0x1]
    s.bx = (s.ax+(s.dx * 0x00000001u));
  }
  { // 0x55772e: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x557730: 0f8fc5000000 JG 0x005577fb
    if(integer::condition("JG",flags)) goto L005577fb;
  }
  L00557736: { // 0x557736: 8b8e00010000 MOV ECX,dword ptr [ESI + 0x100]
    s.cx = m.r32((s.si+0x00000100u));
  }
  { // 0x55773c: 8b9ef8000000 MOV EBX,dword ptr [ESI + 0xf8]
    s.bx = m.r32((s.si+0x000000f8u));
  }
  { // 0x557742: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  { // 0x557744: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x557746: d1e3 SHL EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x557748: 2bdf SUB EBX,EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  { // 0x55774a: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x55774c: 83eb02 SUB EBX,0x2
    s.bx = integer::sub(s.bx,0x00000002u,32,flags);
  }
  { // 0x55774f: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  { // 0x557754: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  { // 0x557756: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  { // 0x55775b: 7c4f JL 0x005577ac
    if(integer::condition("JL",flags)) goto L005577ac;
  }
  { // 0x55775d: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x55775f: 8bae18010000 MOV EBP,dword ptr [ESI + 0x118]
    s.bp = m.r32((s.si+0x00000118u));
  }
  { // 0x557765: 8b9e1c010000 MOV EBX,dword ptr [ESI + 0x11c]
    s.bx = m.r32((s.si+0x0000011cu));
  }
  { // 0x55776b: 8d5410ff LEA EDX,[EAX + EDX*0x1 + -0x1]
    s.dx = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  { // 0x55776f: 83e201 AND EDX,0x1
    s.dx = integer::logical((s.dx)&(0x00000001u),32,flags);
  }
  { // 0x557772: 80fa01 CMP DL,0x1
    (void)integer::sub((s.dx & 0xffu),0x00000001u,8,flags);
  }
  { // 0x557775: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x557778: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x55777a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x55777c: 0f95c2 SETNZ DL
    s.dx = with_al(s.dx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x55777f: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x557780: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x557782: 2be9 SUB EBP,ECX
    s.bp = integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x557784: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  { // 0x557786: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x557788: 89ae18010000 MOV dword ptr [ESI + 0x118],EBP
    m.w32((s.si+0x00000118u), s.bp);
  }
  { // 0x55778e: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x557790: 899e1c010000 MOV dword ptr [ESI + 0x11c],EBX
    m.w32((s.si+0x0000011cu), s.bx);
  }
  { // 0x557796: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x557798: 7409 JZ 0x005577a3
    if(integer::condition("JZ",flags)) goto L005577a3;
  }
  { // 0x55779a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x55779b: 898e1c010000 MOV dword ptr [ESI + 0x11c],ECX
    m.w32((s.si+0x0000011cu), s.cx);
  }
  { // 0x5577a1: eb17 JMP 0x005577ba
    goto L005577ba;
  }
  L005577a3: { // 0x5577a3: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x5577a4: 899618010000 MOV dword ptr [ESI + 0x118],EDX
    m.w32((s.si+0x00000118u), s.dx);
  }
  { // 0x5577aa: eb0e JMP 0x005577ba
    goto L005577ba;
  }
  L005577ac: { // 0x5577ac: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5577ad: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x5577ae: 898618010000 MOV dword ptr [ESI + 0x118],EAX
    m.w32((s.si+0x00000118u), s.ax);
  }
  { // 0x5577b4: 89961c010000 MOV dword ptr [ESI + 0x11c],EDX
    m.w32((s.si+0x0000011cu), s.dx);
  }
  L005577ba: { // 0x5577ba: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x5577be: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5577c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5577c1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5577c3: e888fcffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5601224u); flags=s.arithmetic_flags;
  }
  { // 0x5577c8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5577ca: 7537 JNZ 0x00557803
    if(integer::condition("JNZ",flags)) goto L00557803;
  }
  { // 0x5577cc: 8b8efc000000 MOV ECX,dword ptr [ESI + 0xfc]
    s.cx = m.r32((s.si+0x000000fcu));
  }
  { // 0x5577d2: 8b9e04010000 MOV EBX,dword ptr [ESI + 0x104]
    s.bx = m.r32((s.si+0x00000104u));
  }
  { // 0x5577d8: 8bbef0000000 MOV EDI,dword ptr [ESI + 0xf0]
    s.di = m.r32((s.si+0x000000f0u));
  }
  { // 0x5577de: 8b961c010000 MOV EDX,dword ptr [ESI + 0x11c]
    s.dx = m.r32((s.si+0x0000011cu));
  }
  { // 0x5577e4: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  { // 0x5577ea: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  { // 0x5577ec: 8d4c4f0c LEA ECX,[EDI + ECX*0x2 + 0xc]
    s.cx = (s.di+(s.cx * 0x00000002u)+0x0000000cu);
  }
  { // 0x5577f0: 8d1c10 LEA EBX,[EAX + EDX*0x1]
    s.bx = (s.ax+(s.dx * 0x00000001u));
  }
  { // 0x5577f3: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x5577f5: 0f8e3bffffff JLE 0x00557736
    if(integer::condition("JLE",flags)) goto L00557736;
  }
  L005577fb: { // 0x5577fb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005577fd: { // 0x5577fd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5577fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5577ff: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x557800: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x557801: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x557802: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00557803: { // 0x557803: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  { // 0x557808: 0fbf542410 MOVSX EDX,word ptr [ESP + 0x10]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  { // 0x55780d: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x557810: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x557812: 7814 JS 0x00557828
    if(integer::condition("JS",flags)) goto L00557828;
  }
  { // 0x557814: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x557819: 7d0d JGE 0x00557828
    if(integer::condition("JGE",flags)) goto L00557828;
  }
  { // 0x55781b: 8b8e38010000 MOV ECX,dword ptr [ESI + 0x138]
    s.cx = m.r32((s.si+0x00000138u));
  }
  { // 0x557821: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x557824: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x557826: 75d5 JNZ 0x005577fd
    if(integer::condition("JNZ",flags)) goto L005577fd;
  }
  L00557828: { // 0x557828: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x55782c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x55782d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x55782e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x55782f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  { // 0x557835: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  { // 0x55783a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x55783b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x55783c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005658f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5658f0: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  { // 0x5658f3: 8b415c MOV EAX,dword ptr [ECX + 0x5c]
    s.ax = m.r32((s.cx+0x0000005cu));
  }
  { // 0x5658f6: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  { // 0x5658fa: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x5658fb: 0f8847020000 JS 0x00565b48
    if(integer::condition("JS",flags)) goto L00565b48;
  }
  { // 0x565901: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x565902: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x565903: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x565905: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x565906: c1e504 SHL EBP,0x4
    s.bp = integer::shift(s.bp,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x565909: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x56590a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x56590b: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  { // 0x56590f: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  { // 0x565913: eb04 JMP 0x00565919
    goto L00565919;
  }
  L00565915: { // 0x565915: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00565919: { // 0x565919: 036950 ADD EBP,dword ptr [ECX + 0x50]
    s.bp = integer::add(s.bp,m.r32((s.cx+0x00000050u)),32,flags);
  }
  { // 0x56591c: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x565920: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x565923: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x565925: 0f85ff010000 JNZ 0x00565b2a
    if(integer::condition("JNZ",flags)) goto L00565b2a;
  }
  { // 0x56592b: 8a4508 MOV AL,byte ptr [EBP + 0x8]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000008u)));
  }
  { // 0x56592e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x565930: 0f85f4010000 JNZ 0x00565b2a
    if(integer::condition("JNZ",flags)) goto L00565b2a;
  }
  { // 0x565936: 668b4500 MOV AX,word ptr [EBP]
    s.ax = with_ax(s.ax, m.r16((s.bp)));
  }
  { // 0x56593a: 668b4d04 MOV CX,word ptr [EBP + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.bp+0x00000004u)));
  }
  { // 0x56593e: 663bc1 CMP AX,CX
    (void)integer::sub((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags);
  }
  { // 0x565941: 0f85fa000000 JNZ 0x00565a41
    if(integer::condition("JNZ",flags)) goto L00565a41;
  }
  { // 0x565947: 668b4502 MOV AX,word ptr [EBP + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  { // 0x56594b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x56594d: 663b4506 CMP AX,word ptr [EBP + 0x6]
    (void)integer::sub((s.ax & 0xffffu),m.r16((s.bp+0x00000006u)),16,flags);
  }
  { // 0x565951: 8d542434 LEA EDX,[ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  { // 0x565955: 0f9dc1 SETGE CL
    s.cx = with_al(s.cx, (integer::condition("JGE",flags)?1u:0u));
  }
  { // 0x565958: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x565959: 83e104 AND ECX,0x4
    s.cx = integer::logical((s.cx)&(0x00000004u),32,flags);
  }
  { // 0x56595c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x56595e: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x565960: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  { // 0x565963: 8d1c85a09d8300 LEA EBX,[EAX*0x4 + 0x839da0]
    s.bx = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  { // 0x56596a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x56596b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x56596c: e85f54ecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5658993u); flags=s.arithmetic_flags;
  }
  { // 0x565971: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00565973: { // 0x565973: 663b5504 CMP DX,word ptr [EBP + 0x4]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.bp+0x00000004u)),16,flags);
  }
  { // 0x565977: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  { // 0x56597b: 668b7c241e MOV DI,word ptr [ESP + 0x1e]
    s.di = (s.di & 0xffff0000u) | ((m.r16((f.sp+0x0000001eu))) & 0xffffu);
  }
  { // 0x565980: 750a JNZ 0x0056598c
    if(integer::condition("JNZ",flags)) goto L0056598c;
  }
  { // 0x565982: 663b7d06 CMP DI,word ptr [EBP + 0x6]
    (void)integer::sub((s.di & 0xffffu),m.r16((s.bp+0x00000006u)),16,flags);
  }
  { // 0x565986: 0f849e010000 JZ 0x00565b2a
    if(integer::condition("JZ",flags)) goto L00565b2a;
  }
  L0056598c: { // 0x56598c: 0fbff7 MOVSX ESI,DI
    s.si = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  { // 0x56598f: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  { // 0x565992: c1e609 SHL ESI,0x9
    s.si = integer::shift(s.si,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x565995: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x565997: 7814 JS 0x005659ad
    if(integer::condition("JS",flags)) goto L005659ad;
  }
  { // 0x565999: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x56599e: 7d0d JGE 0x005659ad
    if(integer::condition("JGE",flags)) goto L005659ad;
  }
  { // 0x5659a0: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  { // 0x5659a6: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x5659a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5659ab: 750b JNZ 0x005659b8
    if(integer::condition("JNZ",flags)) goto L005659b8;
  }
  L005659ad: { // 0x5659ad: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  { // 0x5659b3: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005659b8: { // 0x5659b8: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  { // 0x5659be: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5659c1: 755e JNZ 0x00565a21
    if(integer::condition("JNZ",flags)) goto L00565a21;
  }
  { // 0x5659c3: b9feffffff MOV ECX,0xfffffffe
    s.cx = 0xfffffffeu;
  }
  { // 0x5659c8: 66897c2416 MOV word ptr [ESP + 0x16],DI
    m.w16((f.sp+0x00000016u), (s.di & 0xffffu));
  }
  L005659cd: { // 0x5659cd: 8d0411 LEA EAX,[ECX + EDX*0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u));
  }
  { // 0x5659d0: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  { // 0x5659d5: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x5659d8: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x5659da: 7815 JS 0x005659f1
    if(integer::condition("JS",flags)) goto L005659f1;
  }
  { // 0x5659dc: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x5659e1: 7d0e JGE 0x005659f1
    if(integer::condition("JGE",flags)) goto L005659f1;
  }
  { // 0x5659e3: 8b2d58a98100 MOV EBP,dword ptr [0x0081a958]
    s.bp = m.r32((0x0081a958u));
  }
  { // 0x5659e9: 8b448500 MOV EAX,dword ptr [EBP + EAX*0x4]
    s.ax = m.r32((s.bp+(s.ax * 0x00000004u)));
  }
  { // 0x5659ed: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5659ef: 750e JNZ 0x005659ff
    if(integer::condition("JNZ",flags)) goto L005659ff;
  }
  L005659f1: { // 0x5659f1: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x5659f5: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  { // 0x5659fa: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005659ff: { // 0x5659ff: 8ba840010000 MOV EBP,dword ptr [EAX + 0x140]
    s.bp = m.r32((s.ax+0x00000140u));
  }
  { // 0x565a05: 81e5fff7ffff AND EBP,0xfffff7ff
    s.bp = integer::logical((s.bp)&(0xfffff7ffu),32,flags);
  }
  { // 0x565a0b: 81cd00040000 OR EBP,0x400
    s.bp = integer::logical((s.bp)|(0x00000400u),32,flags);
  }
  { // 0x565a11: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x565a12: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  { // 0x565a15: 89a840010000 MOV dword ptr [EAX + 0x140],EBP
    m.w32((s.ax+0x00000140u), s.bp);
  }
  { // 0x565a1b: 7eb0 JLE 0x005659cd
    if(integer::condition("JLE",flags)) goto L005659cd;
  }
  { // 0x565a1d: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00565a21: { // 0x565a21: 668b0b MOV CX,word ptr [EBX]
    s.cx = with_ax(s.cx, m.r16((s.bx)));
  }
  { // 0x565a24: 6603ca ADD CX,DX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.dx & 0xffffu),16,flags));
  }
  { // 0x565a27: 668b5302 MOV DX,word ptr [EBX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000002u)));
  }
  { // 0x565a2b: 6603d7 ADD DX,DI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  { // 0x565a2e: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  { // 0x565a33: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  { // 0x565a38: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x565a3c: e932ffffff JMP 0x00565973
    goto L00565973;
  }
  L00565a41: { // 0x565a41: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x565a43: 663bc1 CMP AX,CX
    (void)integer::sub((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags);
  }
  { // 0x565a46: 0f9dc2 SETGE DL
    s.dx = with_al(s.dx, (integer::condition("JGE",flags)?1u:0u));
  }
  { // 0x565a49: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x565a4a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x565a4c: 83e2fc AND EDX,0xfffffffc
    s.dx = integer::logical((s.dx)&(0xfffffffcu),32,flags);
  }
  { // 0x565a4f: 83c206 ADD EDX,0x6
    s.dx = integer::add(s.dx,0x00000006u,32,flags);
  }
  { // 0x565a52: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x565a54: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  { // 0x565a57: 8d1c85a09d8300 LEA EBX,[EAX*0x4 + 0x839da0]
    s.bx = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  { // 0x565a5e: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  { // 0x565a62: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x565a63: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x565a64: e86753ecff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5659241u); flags=s.arithmetic_flags;
  }
  { // 0x565a69: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00565a6b: { // 0x565a6b: 663b5504 CMP DX,word ptr [EBP + 0x4]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.bp+0x00000004u)),16,flags);
  }
  { // 0x565a6f: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  { // 0x565a73: 8b74243e MOV ESI,dword ptr [ESP + 0x3e]
    s.si = m.r32((f.sp+0x0000003eu));
  }
  { // 0x565a77: 750a JNZ 0x00565a83
    if(integer::condition("JNZ",flags)) goto L00565a83;
  }
  { // 0x565a79: 663b7506 CMP SI,word ptr [EBP + 0x6]
    (void)integer::sub((s.si & 0xffffu),m.r16((s.bp+0x00000006u)),16,flags);
  }
  { // 0x565a7d: 0f84a7000000 JZ 0x00565b2a
    if(integer::condition("JZ",flags)) goto L00565b2a;
  }
  L00565a83: { // 0x565a83: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x565a86: 0fbffa MOVSX EDI,DX
    s.di = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  { // 0x565a89: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x565a8c: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x565a8e: 7814 JS 0x00565aa4
    if(integer::condition("JS",flags)) goto L00565aa4;
  }
  { // 0x565a90: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x565a95: 7d0d JGE 0x00565aa4
    if(integer::condition("JGE",flags)) goto L00565aa4;
  }
  { // 0x565a97: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  { // 0x565a9d: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x565aa0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x565aa2: 750b JNZ 0x00565aaf
    if(integer::condition("JNZ",flags)) goto L00565aaf;
  }
  L00565aa4: { // 0x565aa4: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  { // 0x565aaa: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00565aaf: { // 0x565aaf: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  { // 0x565ab5: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x565ab8: 7550 JNZ 0x00565b0a
    if(integer::condition("JNZ",flags)) goto L00565b0a;
  }
  { // 0x565aba: b9feffffff MOV ECX,0xfffffffe
    s.cx = 0xfffffffeu;
  }
  { // 0x565abf: 6689542420 MOV word ptr [ESP + 0x20],DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L00565ac4: { // 0x565ac4: 8d040e LEA EAX,[ESI + ECX*0x1]
    s.ax = (s.si+(s.cx * 0x00000001u));
  }
  { // 0x565ac7: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  { // 0x565acc: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x565acf: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x565ad2: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x565ad4: 7819 JS 0x00565aef
    if(integer::condition("JS",flags)) goto L00565aef;
  }
  { // 0x565ad6: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x565adb: 7d12 JGE 0x00565aef
    if(integer::condition("JGE",flags)) goto L00565aef;
  }
  { // 0x565add: 8b2d58a98100 MOV EBP,dword ptr [0x0081a958]
    s.bp = m.r32((0x0081a958u));
  }
  { // 0x565ae3: 8b448500 MOV EAX,dword ptr [EBP + EAX*0x4]
    s.ax = m.r32((s.bp+(s.ax * 0x00000004u)));
  }
  { // 0x565ae7: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  { // 0x565aeb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x565aed: 750e JNZ 0x00565afd
    if(integer::condition("JNZ",flags)) goto L00565afd;
  }
  L00565aef: { // 0x565aef: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x565af3: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  { // 0x565af8: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00565afd: { // 0x565afd: 8088410100000c OR byte ptr [EAX + 0x141],0xc
    m.w8((s.ax+0x00000141u), integer::logical((m.r8((s.ax+0x00000141u)))|(0x0000000cu),8,flags));
  }
  { // 0x565b04: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x565b05: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  { // 0x565b08: 7eba JLE 0x00565ac4
    if(integer::condition("JLE",flags)) goto L00565ac4;
  }
  L00565b0a: { // 0x565b0a: 668b0b MOV CX,word ptr [EBX]
    s.cx = with_ax(s.cx, m.r16((s.bx)));
  }
  { // 0x565b0d: 6603ca ADD CX,DX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.dx & 0xffffu),16,flags));
  }
  { // 0x565b10: 668b5302 MOV DX,word ptr [EBX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+0x00000002u)));
  }
  { // 0x565b14: 6603d6 ADD DX,SI
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  { // 0x565b17: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  { // 0x565b1c: 6689542426 MOV word ptr [ESP + 0x26],DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  { // 0x565b21: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  { // 0x565b25: e941ffffff JMP 0x00565a6b
    goto L00565a6b;
  }
  L00565b2a: { // 0x565b2a: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
  { // 0x565b2e: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  { // 0x565b32: 83ed10 SUB EBP,0x10
    s.bp = integer::sub(s.bp,0x00000010u,32,flags);
  }
  { // 0x565b35: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x565b36: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  { // 0x565b3a: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  { // 0x565b3e: 0f85d1fdffff JNZ 0x00565915
    if(integer::condition("JNZ",flags)) goto L00565915;
  }
  { // 0x565b44: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x565b45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x565b46: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x565b47: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00565b48: { // 0x565b48: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  { // 0x565b4b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00565b50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x565b50: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x565b54: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x565b55: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x565b56: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x565b57: 0fbf30 MOVSX ESI,word ptr [EAX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  { // 0x565b5a: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x565b5c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x565b5d: 0fbf7802 MOVSX EDI,word ptr [EAX + 0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  { // 0x565b61: 8b9300010000 MOV EDX,dword ptr [EBX + 0x100]
    s.dx = m.r32((s.bx+0x00000100u));
  }
  { // 0x565b67: 8b83f8000000 MOV EAX,dword ptr [EBX + 0xf8]
    s.ax = m.r32((s.bx+0x000000f8u));
  }
  { // 0x565b6d: 8b8bf0000000 MOV ECX,dword ptr [EBX + 0xf0]
    s.cx = m.r32((s.bx+0x000000f0u));
  }
  { // 0x565b73: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x565b75: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x565b77: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x565b79: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x565b7b: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  { // 0x565b7d: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x565b7f: 7c24 JL 0x00565ba5
    if(integer::condition("JL",flags)) goto L00565ba5;
  }
  { // 0x565b81: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x565b86: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x565b88: 8b8300010000 MOV EAX,dword ptr [EBX + 0x100]
    s.ax = m.r32((s.bx+0x00000100u));
  }
  { // 0x565b8e: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x565b90: d1e2 SHL EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x565b92: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x565b94: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x565b96: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x565b98: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x565b9a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x565b9b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x565b9d: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x565b9f: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x565ba1: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  { // 0x565ba3: eb22 JMP 0x00565bc7
    goto L00565bc7;
  }
  L00565ba5: { // 0x565ba5: 8d1400 LEA EDX,[EAX + EAX*0x1]
    s.dx = (s.ax+(s.ax * 0x00000001u));
  }
  { // 0x565ba8: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x565baa: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x565bac: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x565bae: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x565bb0: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  { // 0x565bb2: 7c13 JL 0x00565bc7
    if(integer::condition("JL",flags)) goto L00565bc7;
  }
  { // 0x565bb4: 8d440002 LEA EAX,[EAX + EAX*0x1 + 0x2]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000002u);
  }
  { // 0x565bb8: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x565bba: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x565bbc: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x565bbe: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x565bbf: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x565bc1: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x565bc3: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x565bc5: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00565bc7: { // 0x565bc7: 0fbfc7 MOVSX EAX,DI
    s.ax = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  { // 0x565bca: 0fbfce MOVSX ECX,SI
    s.cx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x565bcd: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x565bd0: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x565bd2: 6689742418 MOV word ptr [ESP + 0x18],SI
    m.w16((f.sp+0x00000018u), (s.si & 0xffffu));
  }
  { // 0x565bd7: 66897c241a MOV word ptr [ESP + 0x1a],DI
    m.w16((f.sp+0x0000001au), (s.di & 0xffffu));
  }
  { // 0x565bdc: 7818 JS 0x00565bf6
    if(integer::condition("JS",flags)) goto L00565bf6;
  }
  { // 0x565bde: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  { // 0x565be3: 7d11 JGE 0x00565bf6
    if(integer::condition("JGE",flags)) goto L00565bf6;
  }
  { // 0x565be5: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  { // 0x565beb: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x565bee: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x565bf0: 7404 JZ 0x00565bf6
    if(integer::condition("JZ",flags)) goto L00565bf6;
  }
  { // 0x565bf2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x565bf4: eb0e JMP 0x00565c04
    goto L00565c04;
  }
  L00565bf6: { // 0x565bf6: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x565bfa: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  { // 0x565bff: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00565c04: { // 0x565c04: 8a911c010000 MOV DL,byte ptr [ECX + 0x11c]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000011cu)));
  }
  { // 0x565c0a: 0fbe811b010000 MOVSX EAX,byte ptr [ECX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  { // 0x565c11: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x565c13: 741a JZ 0x00565c2f
    if(integer::condition("JZ",flags)) goto L00565c2f;
  }
  { // 0x565c15: 8b8bfc000000 MOV ECX,dword ptr [EBX + 0xfc]
    s.cx = m.r32((s.bx+0x000000fcu));
  }
  { // 0x565c1b: 8b93f0000000 MOV EDX,dword ptr [EBX + 0xf0]
    s.dx = m.r32((s.bx+0x000000f0u));
  }
  { // 0x565c21: 8d4c4a04 LEA ECX,[EDX + ECX*0x2 + 0x4]
    s.cx = (s.dx+(s.cx * 0x00000002u)+0x00000004u);
  }
  { // 0x565c25: 8d1437 LEA EDX,[EDI + ESI*0x1]
    s.dx = (s.di+(s.si * 0x00000001u));
  }
  { // 0x565c28: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x565c2a: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x565c2c: 7d01 JGE 0x00565c2f
    if(integer::condition("JGE",flags)) goto L00565c2f;
  }
  { // 0x565c2e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00565c2f: { // 0x565c2f: 8b8bfc000000 MOV ECX,dword ptr [EBX + 0xfc]
    s.cx = m.r32((s.bx+0x000000fcu));
  }
  { // 0x565c35: 8babf0000000 MOV EBP,dword ptr [EBX + 0xf0]
    s.bp = m.r32((s.bx+0x000000f0u));
  }
  { // 0x565c3b: 8d1437 LEA EDX,[EDI + ESI*0x1]
    s.dx = (s.di+(s.si * 0x00000001u));
  }
  { // 0x565c3e: 8d6c4d00 LEA EBP,[EBP + ECX*0x2]
    s.bp = (s.bp+(s.cx * 0x00000002u));
  }
  { // 0x565c42: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  { // 0x565c44: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  { // 0x565c46: 7f20 JG 0x00565c68
    if(integer::condition("JG",flags)) goto L00565c68;
  }
  L00565c48: { // 0x565c48: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x565c49: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  { // 0x565c4d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x565c4e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x565c50: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x565c51: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x565c53: 6689742420 MOV word ptr [ESP + 0x20],SI
    m.w16((f.sp+0x00000020u), (s.si & 0xffffu));
  }
  { // 0x565c58: 66897c2422 MOV word ptr [ESP + 0x22],DI
    m.w16((f.sp+0x00000022u), (s.di & 0xffffu));
  }
  { // 0x565c5d: e8ee17ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5659746u); flags=s.arithmetic_flags;
  }
  { // 0x565c62: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x565c64: 74e2 JZ 0x00565c48
    if(integer::condition("JZ",flags)) goto L00565c48;
  }
  { // 0x565c66: eb36 JMP 0x00565c9e
    goto L00565c9e;
  }
  L00565c68: { // 0x565c68: 8bab04010000 MOV EBP,dword ptr [EBX + 0x104]
    s.bp = m.r32((s.bx+0x00000104u));
  }
  { // 0x565c6e: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  { // 0x565c70: 8b8bf0000000 MOV ECX,dword ptr [EBX + 0xf0]
    s.cx = m.r32((s.bx+0x000000f0u));
  }
  { // 0x565c76: 8d4c6902 LEA ECX,[ECX + EBP*0x2 + 0x2]
    s.cx = (s.cx+(s.bp * 0x00000002u)+0x00000002u);
  }
  { // 0x565c7a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x565c7c: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x565c7e: 7e1e JLE 0x00565c9e
    if(integer::condition("JLE",flags)) goto L00565c9e;
  }
  L00565c80: { // 0x565c80: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x565c81: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x565c85: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x565c86: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x565c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x565c89: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x565c8b: 6689742420 MOV word ptr [ESP + 0x20],SI
    m.w16((f.sp+0x00000020u), (s.si & 0xffffu));
  }
  { // 0x565c90: 66897c2422 MOV word ptr [ESP + 0x22],DI
    m.w16((f.sp+0x00000022u), (s.di & 0xffffu));
  }
  { // 0x565c95: e8b617ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5659802u); flags=s.arithmetic_flags;
  }
  { // 0x565c9a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x565c9c: 74e2 JZ 0x00565c80
    if(integer::condition("JZ",flags)) goto L00565c80;
  }
  L00565c9e: { // 0x565c9e: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x565ca2: 66897c241a MOV word ptr [ESP + 0x1a],DI
    m.w16((f.sp+0x0000001au), (s.di & 0xffffu));
  }
  { // 0x565ca7: 6689742418 MOV word ptr [ESP + 0x18],SI
    m.w16((f.sp+0x00000018u), (s.si & 0xffffu));
  }
  { // 0x565cac: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x565cb0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x565cb1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x565cb2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x565cb3: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x565cb5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x565cb6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0056e9b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x56e9b0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x56e9b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x56e9b4: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x56e9b8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x56e9b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x56e9ba: 668b4b04 MOV CX,word ptr [EBX + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000004u)));
  }
  { // 0x56e9be: 668b03 MOV AX,word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  { // 0x56e9c1: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  { // 0x56e9c5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x56e9c6: 66894c2422 MOV word ptr [ESP + 0x22],CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  { // 0x56e9cb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x56e9cc: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x56e9d1: 6689442424 MOV word ptr [ESP + 0x24],AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  { // 0x56e9d6: e8256bfdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5695963u); flags=s.arithmetic_flags;
  }
  { // 0x56e9db: 0fbe801b010000 MOVSX EAX,byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x56e9e2: 8b7b04 MOV EDI,dword ptr [EBX + 0x4]
    s.di = m.r32((s.bx+0x00000004u));
  }
  { // 0x56e9e5: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  { // 0x56e9e9: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x56e9eb: 8b0d3486a500 MOV ECX,dword ptr [0x00a58634]
    s.cx = m.r32((0x00a58634u));
  }
  { // 0x56e9f1: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x56e9f4: 0fbfd7 MOVSX EDX,DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  { // 0x56e9f7: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  { // 0x56e9fb: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  { // 0x56e9fe: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56ea00: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  { // 0x56ea04: 0f8e84010000 JLE 0x0056eb8e
    if(integer::condition("JLE",flags)) goto L0056eb8e;
  }
  { // 0x56ea0a: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x56ea0c: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x56ea0e: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56ea10: 0f8d78010000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56ea16: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x56ea18: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x56ea1a: 0f8d6e010000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56ea20: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x56ea24: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  { // 0x56ea2a: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x56ea2c: 0f8f5c010000 JG 0x0056eb8e
    if(integer::condition("JG",flags)) goto L0056eb8e;
  }
  { // 0x56ea32: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  { // 0x56ea35: 8d7410ff LEA ESI,[EAX + EDX*0x1 + -0x1]
    s.si = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  { // 0x56ea39: 0fbfee MOVSX EBP,SI
    s.bp = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x56ea3c: 0fbff7 MOVSX ESI,DI
    s.si = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  { // 0x56ea3f: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  { // 0x56ea43: 03ee ADD EBP,ESI
    s.bp = integer::add(s.bp,s.si,32,flags);
  }
  { // 0x56ea45: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56ea47: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x56ea4b: 0f8e3d010000 JLE 0x0056eb8e
    if(integer::condition("JLE",flags)) goto L0056eb8e;
  }
  { // 0x56ea51: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  { // 0x56ea55: 2bee SUB EBP,ESI
    s.bp = integer::sub(s.bp,s.si,32,flags);
  }
  { // 0x56ea57: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56ea59: 0f8d2f010000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56ea5f: 2b742420 SUB ESI,dword ptr [ESP + 0x20]
    s.si = integer::sub(s.si,m.r32((f.sp+0x00000020u)),32,flags);
  }
  { // 0x56ea63: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x56ea65: 0f8d23010000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56ea6b: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  { // 0x56ea71: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  { // 0x56ea75: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  { // 0x56ea77: 0f8f11010000 JG 0x0056eb8e
    if(integer::condition("JG",flags)) goto L0056eb8e;
  }
  { // 0x56ea7d: 8b730c MOV ESI,dword ptr [EBX + 0xc]
    s.si = m.r32((s.bx+0x0000000cu));
  }
  { // 0x56ea80: 8d743eff LEA ESI,[ESI + EDI*0x1 + -0x1]
    s.si = (s.si+(s.di * 0x00000001u)-0x00000001u);
  }
  { // 0x56ea84: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  { // 0x56ea88: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x56ea8b: 0fbff6 MOVSX ESI,SI
    s.si = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x56ea8e: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  { // 0x56ea91: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56ea93: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  { // 0x56ea97: 0f8ef1000000 JLE 0x0056eb8e
    if(integer::condition("JLE",flags)) goto L0056eb8e;
  }
  { // 0x56ea9d: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  { // 0x56ea9f: 2bee SUB EBP,ESI
    s.bp = integer::sub(s.bp,s.si,32,flags);
  }
  { // 0x56eaa1: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56eaa3: 0f8de5000000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56eaa9: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  { // 0x56eaab: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x56eaad: 0f8ddb000000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56eab3: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  { // 0x56eab7: 8b3d3886a500 MOV EDI,dword ptr [0x00a58638]
    s.di = m.r32((0x00a58638u));
  }
  { // 0x56eabd: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x56eabf: 0f8fc9000000 JG 0x0056eb8e
    if(integer::condition("JG",flags)) goto L0056eb8e;
  }
  { // 0x56eac5: 8d7410ff LEA ESI,[EAX + EDX*0x1 + -0x1]
    s.si = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  { // 0x56eac9: 0fbffe MOVSX EDI,SI
    s.di = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  { // 0x56eacc: 0fbf742410 MOVSX ESI,word ptr [ESP + 0x10]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  { // 0x56ead1: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  { // 0x56ead4: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56ead6: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  { // 0x56eada: 0f8eae000000 JLE 0x0056eb8e
    if(integer::condition("JLE",flags)) goto L0056eb8e;
  }
  { // 0x56eae0: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  { // 0x56eae2: 2bee SUB EBP,ESI
    s.bp = integer::sub(s.bp,s.si,32,flags);
  }
  { // 0x56eae4: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56eae6: 0f8da2000000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56eaec: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  { // 0x56eaee: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x56eaf0: 0f8d98000000 JGE 0x0056eb8e
    if(integer::condition("JGE",flags)) goto L0056eb8e;
  }
  { // 0x56eaf6: 8b0d3886a500 MOV ECX,dword ptr [0x00a58638]
    s.cx = m.r32((0x00a58638u));
  }
  { // 0x56eafc: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  { // 0x56eb00: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x56eb02: 0f8f86000000 JG 0x0056eb8e
    if(integer::condition("JG",flags)) goto L0056eb8e;
  }
  { // 0x56eb08: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x56eb0c: 8b4b0c MOV ECX,dword ptr [EBX + 0xc]
    s.cx = m.r32((s.bx+0x0000000cu));
  }
  { // 0x56eb0f: 8d4c2901 LEA ECX,[ECX + EBP*0x1 + 0x1]
    s.cx = (s.cx+(s.bp * 0x00000001u)+0x00000001u);
  }
  { // 0x56eb13: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56eb15: 7d6b JGE 0x0056eb82
    if(integer::condition("JGE",flags)) goto L0056eb82;
  }
  L0056eb17: { // 0x56eb17: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x56eb19: 8d4c0201 LEA ECX,[EDX + EAX*0x1 + 0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000001u);
  }
  { // 0x56eb1d: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x56eb1f: 7d52 JGE 0x0056eb73
    if(integer::condition("JGE",flags)) goto L0056eb73;
  }
  L0056eb21: { // 0x56eb21: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  { // 0x56eb25: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x56eb2a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x56eb2b: 6689742424 MOV word ptr [ESP + 0x24],SI
    m.w16((f.sp+0x00000024u), (s.si & 0xffffu));
  }
  { // 0x56eb30: 66896c2426 MOV word ptr [ESP + 0x26],BP
    m.w16((f.sp+0x00000026u), (s.bp & 0xffffu));
  }
  { // 0x56eb35: e8c669fdff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5696314u); flags=s.arithmetic_flags;
  }
  { // 0x56eb3a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x56eb3c: 837f44ff CMP dword ptr [EDI + 0x44],-0x1
    (void)integer::sub(m.r32((s.di+0x00000044u)),0xffffffffu,32,flags);
  }
  { // 0x56eb40: 754c JNZ 0x0056eb8e
    if(integer::condition("JNZ",flags)) goto L0056eb8e;
  }
  { // 0x56eb42: 0fbe871b010000 MOVSX EAX,byte ptr [EDI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  { // 0x56eb49: 3b442418 CMP EAX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  { // 0x56eb4d: 753f JNZ 0x0056eb8e
    if(integer::condition("JNZ",flags)) goto L0056eb8e;
  }
  { // 0x56eb4f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x56eb51: e83ac6f0ff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5696342u); flags=s.arithmetic_flags;
  }
  { // 0x56eb56: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x56eb58: 750b JNZ 0x0056eb65
    if(integer::condition("JNZ",flags)) goto L0056eb65;
  }
  { // 0x56eb5a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x56eb5c: e87fc8f0ff CALL 0x0047b3e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b3e0u,5696353u); flags=s.arithmetic_flags;
  }
  { // 0x56eb61: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x56eb63: 7429 JZ 0x0056eb8e
    if(integer::condition("JZ",flags)) goto L0056eb8e;
  }
  L0056eb65: { // 0x56eb65: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  { // 0x56eb68: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x56eb6a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x56eb6b: 8d4c0201 LEA ECX,[EDX + EAX*0x1 + 0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000001u);
  }
  { // 0x56eb6f: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x56eb71: 7cae JL 0x0056eb21
    if(integer::condition("JL",flags)) goto L0056eb21;
  }
  L0056eb73: { // 0x56eb73: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x56eb76: 8b730c MOV ESI,dword ptr [EBX + 0xc]
    s.si = m.r32((s.bx+0x0000000cu));
  }
  { // 0x56eb79: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  { // 0x56eb7a: 8d4c3101 LEA ECX,[ECX + ESI*0x1 + 0x1]
    s.cx = (s.cx+(s.si * 0x00000001u)+0x00000001u);
  }
  { // 0x56eb7e: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  { // 0x56eb80: 7c95 JL 0x0056eb17
    if(integer::condition("JL",flags)) goto L0056eb17;
  }
  L0056eb82: { // 0x56eb82: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x56eb83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x56eb84: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x56eb85: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x56eb87: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x56eb88: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x56eb8b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056eb8e: { // 0x56eb8e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x56eb8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x56eb90: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x56eb91: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x56eb93: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x56eb94: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x56eb97: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00585360(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x585360: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  { // 0x585363: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  { // 0x585367: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  { // 0x58536b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58536c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x58536d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x58536f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x585371: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x585373: 83fa04 CMP EDX,0x4
    (void)integer::sub(s.dx,0x00000004u,32,flags);
  }
  { // 0x585376: 0f94442418 SETZ byte ptr [ESP + 0x18]
    m.w8((f.sp+0x00000018u), (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x58537b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58537c: 83fa02 CMP EDX,0x2
    (void)integer::sub(s.dx,0x00000002u,32,flags);
  }
  { // 0x58537f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x585380: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x585384: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x585388: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x58538c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  { // 0x585390: 752a JNZ 0x005853bc
    if(integer::condition("JNZ",flags)) goto L005853bc;
  }
  { // 0x585392: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x585394: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x585399: be03000000 MOV ESI,0x3
    s.si = 0x00000003u;
  }
  { // 0x58539e: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  { // 0x5853a2: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  { // 0x5853a6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5853a8: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  { // 0x5853aa: c744241cfdffffff MOV dword ptr [ESP + 0x1c],0xfffffffd
    m.w32((f.sp+0x0000001cu), 0xfffffffdu);
  }
  { // 0x5853b2: c744241806000000 MOV dword ptr [ESP + 0x18],0x6
    m.w32((f.sp+0x00000018u), 0x00000006u);
  }
  { // 0x5853ba: eb25 JMP 0x005853e1
    goto L005853e1;
  }
  L005853bc: { // 0x5853bc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5853be: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  { // 0x5853c3: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  { // 0x5853c8: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  { // 0x5853cc: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  { // 0x5853d0: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5853d2: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  { // 0x5853d4: bdfdffffff MOV EBP,0xfffffffd
    s.bp = 0xfffffffdu;
  }
  { // 0x5853d9: c744241406000000 MOV dword ptr [ESP + 0x14],0x6
    m.w32((f.sp+0x00000014u), 0x00000006u);
  }
  L005853e1: { // 0x5853e1: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L005853e5: { // 0x5853e5: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x5853e8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5853ea: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x5853ec: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  { // 0x5853f1: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x5853f3: 7d64 JGE 0x00585459
    if(integer::condition("JGE",flags)) goto L00585459;
  }
  { // 0x5853f5: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x5853f8: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x5853fb: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x5853fd: 0fbf542412 MOVSX EDX,word ptr [ESP + 0x12]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  { // 0x585402: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x585404: 7d53 JGE 0x00585459
    if(integer::condition("JGE",flags)) goto L00585459;
  }
  { // 0x585406: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x58540a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x58540f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x585410: e8eb00fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5788693u); flags=s.arithmetic_flags;
  }
  { // 0x585415: 8b4838 MOV ECX,dword ptr [EAX + 0x38]
    s.cx = m.r32((s.ax+0x00000038u));
  }
  { // 0x585418: a1185da500 MOV EAX,[0x00a55d18]
    s.ax = m.r32((0x00a55d18u));
  }
  { // 0x58541d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x58541f: 7458 JZ 0x00585479
    if(integer::condition("JZ",flags)) goto L00585479;
  }
  { // 0x585421: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  { // 0x585425: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  { // 0x585428: 668b0c95a09d8300 MOV CX,word ptr [EDX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  { // 0x585430: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  { // 0x585437: 66034c2410 ADD CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  { // 0x58543c: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  { // 0x585440: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  { // 0x585445: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  { // 0x58544a: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  { // 0x58544f: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  { // 0x585453: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x585457: eb8c JMP 0x005853e5
    goto L005853e5;
  }
  L00585459: { // 0x585459: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x58545b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x58545c: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  { // 0x585461: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  { // 0x585466: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  { // 0x58546a: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x58546e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58546f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x585470: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x585472: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x585473: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  { // 0x585476: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00585479: { // 0x585479: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0058547d: { // 0x58547d: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x585480: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x585482: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x585485: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x585487: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x585489: 0f8d86000000 JGE 0x00585515
    if(integer::condition("JGE",flags)) goto L00585515;
  }
  { // 0x58548f: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  { // 0x585492: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  { // 0x585497: 035604 ADD EDX,dword ptr [ESI + 0x4]
    s.dx = integer::add(s.dx,m.r32((s.si+0x00000004u)),32,flags);
  }
  { // 0x58549a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x58549c: 7d77 JGE 0x00585515
    if(integer::condition("JGE",flags)) goto L00585515;
  }
  { // 0x58549e: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  { // 0x5854a0: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  { // 0x5854a4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x5854a8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x5854aa: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x5854ae: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  { // 0x5854b2: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5854b6: 8d140f LEA EDX,[EDI + ECX*0x1]
    s.dx = (s.di+(s.cx * 0x00000001u));
  }
  { // 0x5854b9: 8d0c03 LEA ECX,[EBX + EAX*0x1]
    s.cx = (s.bx+(s.ax * 0x00000001u));
  }
  { // 0x5854bc: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  { // 0x5854c0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x5854c4: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  { // 0x5854c8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5854c9: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  { // 0x5854cd: e85e030000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5788882u); flags=s.arithmetic_flags;
  }
  { // 0x5854d2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5854d4: 755f JNZ 0x00585535
    if(integer::condition("JNZ",flags)) goto L00585535;
  }
  { // 0x5854d6: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  { // 0x5854da: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  { // 0x5854dd: 668b0c85a09d8300 MOV CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, m.r16(((s.ax * 0x00000004u)+0x00839da0u)));
  }
  { // 0x5854e5: 668b1485a29d8300 MOV DX,word ptr [EAX*0x4 + 0x839da2]
    s.dx = with_ax(s.dx, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  { // 0x5854ed: 66034c2410 ADD CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  { // 0x5854f2: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  { // 0x5854f7: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  { // 0x5854fe: 66894c2444 MOV word ptr [ESP + 0x44],CX
    m.w16((f.sp+0x00000044u), (s.cx & 0xffffu));
  }
  { // 0x585503: 6689542446 MOV word ptr [ESP + 0x46],DX
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  { // 0x585508: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  { // 0x58550c: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x585510: e968ffffff JMP 0x0058547d
    goto L0058547d;
  }
  L00585515: { // 0x585515: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x585517: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x585518: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  { // 0x58551d: 6689442446 MOV word ptr [ESP + 0x46],AX
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  { // 0x585522: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  { // 0x585526: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x58552a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58552b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x58552c: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x58552e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x58552f: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  { // 0x585532: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00585535: { // 0x585535: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  { // 0x585539: 0fbf442412 MOVSX EAX,word ptr [ESP + 0x12]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  { // 0x58553e: 0fbf5102 MOVSX EDX,word ptr [ECX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  { // 0x585542: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x585544: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  { // 0x585547: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x58554b: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x58554e: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  { // 0x585550: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x585552: 7e02 JLE 0x00585556
    if(integer::condition("JLE",flags)) goto L00585556;
  }
  { // 0x585554: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00585556: { // 0x585556: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x585558: 0f8ee2000000 JLE 0x00585640
    if(integer::condition("JLE",flags)) goto L00585640;
  }
  { // 0x58555e: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  { // 0x585561: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  { // 0x585569: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x58556d: df6c2420 FILD qword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  { // 0x585571: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00585575: { // 0x585575: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  { // 0x58557a: e861a80a00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5789055u); flags=s.arithmetic_flags;
  }
  { // 0x58557f: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x585583: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  { // 0x58558b: df6c2420 FILD qword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  { // 0x58558f: dc4c2428 FMUL double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply64(read64(m,address));
  }
  { // 0x585593: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  { // 0x585599: e8b2541e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5789086u); flags=s.arithmetic_flags;
  }
  { // 0x58559e: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5855a0: 77d3 JA 0x00585575
    if(integer::condition("JA",flags)) goto L00585575;
  }
  { // 0x5855a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5855a4: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  { // 0x5855a8: 0f8e8e000000 JLE 0x0058563c
    if(integer::condition("JLE",flags)) goto L0058563c;
  }
  { // 0x5855ae: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  { // 0x5855b2: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5855b6: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x5855ba: 83c1fc ADD ECX,-0x4
    s.cx = integer::add(s.cx,0xfffffffcu,32,flags);
  }
  { // 0x5855bd: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  { // 0x5855c0: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  { // 0x5855c2: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  { // 0x5855c4: 8d348da09d8300 LEA ESI,[ECX*0x4 + 0x839da0]
    s.si = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  { // 0x5855cb: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005855cf: { // 0x5855cf: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  { // 0x5855d2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5855d4: 6603c1 ADD AX,CX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  { // 0x5855d7: 668b4e02 MOV CX,word ptr [ESI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000002u)));
  }
  { // 0x5855db: 66034c2416 ADD CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  { // 0x5855e0: 668944244c MOV word ptr [ESP + 0x4c],AX
    m.w16((f.sp+0x0000004cu), (s.ax & 0xffffu));
  }
  { // 0x5855e5: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x5855e8: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x5855eb: 66894c244e MOV word ptr [ESP + 0x4e],CX
    m.w16((f.sp+0x0000004eu), (s.cx & 0xffffu));
  }
  { // 0x5855f0: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  { // 0x5855f4: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  { // 0x5855f6: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x5855f8: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  { // 0x5855fc: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  { // 0x5855fe: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  { // 0x585602: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  { // 0x585606: 897c2434 MOV dword ptr [ESP + 0x34],EDI
    m.w32((f.sp+0x00000034u), s.di);
  }
  { // 0x58560a: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  { // 0x58560e: e81d020000 CALL 0x00585830
    s.arithmetic_flags=flags; invoke(m,s,f,0x00585830u,5789203u); flags=s.arithmetic_flags;
  }
  { // 0x585613: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x585615: 7425 JZ 0x0058563c
    if(integer::condition("JZ",flags)) goto L0058563c;
  }
  { // 0x585617: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  { // 0x58561b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  { // 0x58561f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x585620: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x585624: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x585626: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  { // 0x58562a: 7fa3 JG 0x005855cf
    if(integer::condition("JG",flags)) goto L005855cf;
  }
  { // 0x58562c: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  { // 0x585630: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x585631: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x585632: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x585633: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x585635: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x585636: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  { // 0x585639: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0058563c: { // 0x58563c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00585640: { // 0x585640: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  { // 0x585644: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x585645: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x585646: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x585647: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x585649: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x58564a: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  { // 0x58564d: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00585cc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x585cc0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x585cc3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x585cc4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x585cc5: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x585cc7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x585cc8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x585cc9: a13486a500 MOV EAX,[0x00a58634]
    s.ax = m.r32((0x00a58634u));
  }
  { // 0x585cce: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x585cd0: 8b7b04 MOV EDI,dword ptr [EBX + 0x4]
    s.di = m.r32((s.bx+0x00000004u));
  }
  { // 0x585cd3: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x585cd6: 0fbfd7 MOVSX EDX,DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  { // 0x585cd9: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  { // 0x585cdc: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585cde: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x585ce2: 0f8eb2010000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  { // 0x585ce8: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x585cea: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x585cec: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585cee: 0f8da6010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585cf4: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585cf6: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x585cf8: 0f8d9c010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585cfe: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x585d02: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  { // 0x585d08: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585d0a: 0f8f8a010000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  { // 0x585d10: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  { // 0x585d13: 8d540aff LEA EDX,[EDX + ECX*0x1 + -0x1]
    s.dx = (s.dx+(s.cx * 0x00000001u)-0x00000001u);
  }
  { // 0x585d17: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  { // 0x585d1b: 0fbff2 MOVSX ESI,DX
    s.si = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  { // 0x585d1e: 0fbfd7 MOVSX EDX,DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  { // 0x585d21: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  { // 0x585d24: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585d26: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x585d2a: 0f8e6a010000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  { // 0x585d30: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x585d32: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x585d34: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585d36: 0f8d5e010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585d3c: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585d3e: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x585d40: 0f8d54010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585d46: 8b153886a500 MOV EDX,dword ptr [0x00a58638]
    s.dx = m.r32((0x00a58638u));
  }
  { // 0x585d4c: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x585d50: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  { // 0x585d52: 0f8f42010000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  { // 0x585d58: 8b530c MOV EDX,dword ptr [EBX + 0xc]
    s.dx = m.r32((s.bx+0x0000000cu));
  }
  { // 0x585d5b: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  { // 0x585d5e: 8d543aff LEA EDX,[EDX + EDI*0x1 + -0x1]
    s.dx = (s.dx+(s.di * 0x00000001u)-0x00000001u);
  }
  { // 0x585d62: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  { // 0x585d66: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  { // 0x585d69: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  { // 0x585d6c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585d6e: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x585d72: 0f8e22010000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  { // 0x585d78: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x585d7a: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x585d7c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585d7e: 0f8d16010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585d84: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585d86: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x585d88: 0f8d0c010000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585d8e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x585d92: 8b353886a500 MOV ESI,dword ptr [0x00a58638]
    s.si = m.r32((0x00a58638u));
  }
  { // 0x585d98: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585d9a: 0f8ffa000000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  { // 0x585da0: 0fbf742414 MOVSX ESI,word ptr [ESP + 0x14]
    s.si = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  { // 0x585da5: 0fbf542418 MOVSX EDX,word ptr [ESP + 0x18]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000018u)),16));
  }
  { // 0x585daa: 8d2c32 LEA EBP,[EDX + ESI*0x1]
    s.bp = (s.dx+(s.si * 0x00000001u));
  }
  { // 0x585dad: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585daf: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  { // 0x585db3: 0f8ee1000000 JLE 0x00585e9a
    if(integer::condition("JLE",flags)) goto L00585e9a;
  }
  { // 0x585db9: 8bee MOV EBP,ESI
    s.bp = s.si;
  }
  { // 0x585dbb: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  { // 0x585dbd: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x585dbf: 0f8dd5000000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585dc5: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x585dc7: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x585dc9: 0f8dcb000000 JGE 0x00585e9a
    if(integer::condition("JGE",flags)) goto L00585e9a;
  }
  { // 0x585dcf: a13886a500 MOV EAX,[0x00a58638]
    s.ax = m.r32((0x00a58638u));
  }
  { // 0x585dd4: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x585dd8: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x585dda: 0f8fba000000 JG 0x00585e9a
    if(integer::condition("JG",flags)) goto L00585e9a;
  }
  { // 0x585de0: 8d5703 LEA EDX,[EDI + 0x3]
    s.dx = (s.di+0x00000003u);
  }
  { // 0x585de3: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  { // 0x585de5: 7d54 JGE 0x00585e3b
    if(integer::condition("JGE",flags)) goto L00585e3b;
  }
  L00585de7: { // 0x585de7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x585de9: 8d4103 LEA EAX,[ECX + 0x3]
    s.ax = (s.cx+0x00000003u);
  }
  { // 0x585dec: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x585dee: 7d40 JGE 0x00585e30
    if(integer::condition("JGE",flags)) goto L00585e30;
  }
  L00585df0: { // 0x585df0: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x585df4: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  { // 0x585df9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x585dfa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x585dff: 66897c2416 MOV word ptr [ESP + 0x16],DI
    m.w16((f.sp+0x00000016u), (s.di & 0xffffu));
  }
  { // 0x585e04: e8f7f6fbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5791241u); flags=s.arithmetic_flags;
  }
  { // 0x585e09: 8b5038 MOV EDX,dword ptr [EAX + 0x38]
    s.dx = m.r32((s.ax+0x00000038u));
  }
  { // 0x585e0c: 8b0d4459a500 MOV ECX,dword ptr [0x00a55944]
    s.cx = m.r32((0x00a55944u));
  }
  { // 0x585e12: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x585e14: 7c05 JL 0x00585e1b
    if(integer::condition("JL",flags)) goto L00585e1b;
  }
  { // 0x585e16: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x585e17: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x585e19: 7e0b JLE 0x00585e26
    if(integer::condition("JLE",flags)) goto L00585e26;
  }
  L00585e1b: { // 0x585e1b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x585e1d: e81e57efff CALL 0x0047b540
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b540u,5791266u); flags=s.arithmetic_flags;
  }
  { // 0x585e22: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x585e24: 7474 JZ 0x00585e9a
    if(integer::condition("JZ",flags)) goto L00585e9a;
  }
  L00585e26: { // 0x585e26: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x585e28: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x585e29: 8d5103 LEA EDX,[ECX + 0x3]
    s.dx = (s.cx+0x00000003u);
  }
  { // 0x585e2c: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  { // 0x585e2e: 7cc0 JL 0x00585df0
    if(integer::condition("JL",flags)) goto L00585df0;
  }
  L00585e30: { // 0x585e30: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  { // 0x585e33: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x585e34: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  { // 0x585e37: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x585e39: 7cac JL 0x00585de7
    if(integer::condition("JL",flags)) goto L00585de7;
  }
  L00585e3b: { // 0x585e3b: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  { // 0x585e3d: 8d4e03 LEA ECX,[ESI + 0x3]
    s.cx = (s.si+0x00000003u);
  }
  { // 0x585e40: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x585e42: 7d4c JGE 0x00585e90
    if(integer::condition("JGE",flags)) goto L00585e90;
  }
  L00585e44: { // 0x585e44: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  { // 0x585e47: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x585e4b: 83c203 ADD EDX,0x3
    s.dx = integer::add(s.dx,0x00000003u,32,flags);
  }
  { // 0x585e4e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x585e4f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x585e54: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  { // 0x585e59: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  { // 0x585e5e: e89df6fbff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5791331u); flags=s.arithmetic_flags;
  }
  { // 0x585e63: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x585e65: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x585e67: e81456efff CALL 0x0047b480
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b480u,5791340u); flags=s.arithmetic_flags;
  }
  { // 0x585e6c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x585e6e: 7516 JNZ 0x00585e86
    if(integer::condition("JNZ",flags)) goto L00585e86;
  }
  { // 0x585e70: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x585e72: e81953efff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5791351u); flags=s.arithmetic_flags;
  }
  { // 0x585e77: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x585e79: 750b JNZ 0x00585e86
    if(integer::condition("JNZ",flags)) goto L00585e86;
  }
  { // 0x585e7b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x585e7d: e8de55efff CALL 0x0047b460
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b460u,5791362u); flags=s.arithmetic_flags;
  }
  { // 0x585e82: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x585e84: 7414 JZ 0x00585e9a
    if(integer::condition("JZ",flags)) goto L00585e9a;
  }
  L00585e86: { // 0x585e86: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x585e88: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x585e89: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  { // 0x585e8c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x585e8e: 7cb4 JL 0x00585e44
    if(integer::condition("JL",flags)) goto L00585e44;
  }
  L00585e90: { // 0x585e90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x585e91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x585e92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x585e93: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x585e95: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x585e96: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x585e99: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00585e9a: { // 0x585e9a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x585e9b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x585e9c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x585e9d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x585e9f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x585ea0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x585ea3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0060a590(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60a590: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x60a593: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x60a594: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x60a596: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x60a597: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60a598: 8b83ac000000 MOV EAX,dword ptr [EBX + 0xac]
    s.ax = m.r32((s.bx+0x000000acu));
  }
  { // 0x60a59e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x60a59f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x60a5a2: 0f8571010000 JNZ 0x0060a719
    if(integer::condition("JNZ",flags)) goto L0060a719;
  }
  { // 0x60a5a8: 8b6b10 MOV EBP,dword ptr [EBX + 0x10]
    s.bp = m.r32((s.bx+0x00000010u));
  }
  { // 0x60a5ab: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x60a5ad: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x60a5af: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x60a5b1: 7e2d JLE 0x0060a5e0
    if(integer::condition("JLE",flags)) goto L0060a5e0;
  }
  L0060a5b3: { // 0x60a5b3: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  { // 0x60a5b6: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x60a5b9: 8a480c MOV CL,byte ptr [EAX + 0xc]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000000cu)));
  }
  { // 0x60a5bc: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x60a5be: 7413 JZ 0x0060a5d3
    if(integer::condition("JZ",flags)) goto L0060a5d3;
  }
  { // 0x60a5c0: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  { // 0x60a5c2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x60a5c4: e8d7c30b00 CALL 0x006c69a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c69a0u,6333897u); flags=s.arithmetic_flags;
  }
  { // 0x60a5c9: 8a8898000000 MOV CL,byte ptr [EAX + 0x98]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000098u)));
  }
  { // 0x60a5cf: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x60a5d1: 7418 JZ 0x0060a5eb
    if(integer::condition("JZ",flags)) goto L0060a5eb;
  }
  L0060a5d3: { // 0x60a5d3: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x60a5d4: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  { // 0x60a5d6: 7cdb JL 0x0060a5b3
    if(integer::condition("JL",flags)) goto L0060a5b3;
  }
  { // 0x60a5d8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x60a5da: 0f8597000000 JNZ 0x0060a677
    if(integer::condition("JNZ",flags)) goto L0060a677;
  }
  L0060a5e0: { // 0x60a5e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x60a5e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60a5e2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x60a5e3: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x60a5e6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x60a5e7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x60a5ea: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060a5eb: { // 0x60a5eb: 8bb6b4010000 MOV ESI,dword ptr [ESI + 0x1b4]
    s.si = m.r32((s.si+0x000001b4u));
  }
  { // 0x60a5f1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x60a5f3: 8b7e30 MOV EDI,dword ptr [ESI + 0x30]
    s.di = m.r32((s.si+0x00000030u));
  }
  { // 0x60a5f6: e8b5a1eeff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6333947u); flags=s.arithmetic_flags;
  }
  { // 0x60a5fb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60a5fd: 740c JZ 0x0060a60b
    if(integer::condition("JZ",flags)) goto L0060a60b;
  }
  { // 0x60a5ff: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  { // 0x60a604: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x60a606: 7403 JZ 0x0060a60b
    if(integer::condition("JZ",flags)) goto L0060a60b;
  }
  { // 0x60a608: 8b7830 MOV EDI,dword ptr [EAX + 0x30]
    s.di = m.r32((s.ax+0x00000030u));
  }
  L0060a60b: { // 0x60a60b: 8b0dcca5a100 MOV ECX,dword ptr [0x00a1a5cc]
    s.cx = m.r32((0x00a1a5ccu));
  }
  { // 0x60a611: 6861e3a900 PUSH 0xa9e361
    f.push(m,0x00a9e361u);
  }
  { // 0x60a616: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  { // 0x60a618: 8b14b9 MOV EDX,dword ptr [ECX + EDI*0x4]
    s.dx = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  { // 0x60a61b: 81c2e9550000 ADD EDX,0x55e9
    s.dx = integer::add(s.dx,0x000055e9u,32,flags);
  }
  { // 0x60a621: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  { // 0x60a624: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  { // 0x60a629: 8a4a02 MOV CL,byte ptr [EDX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000002u)));
  }
  { // 0x60a62c: 884c241a MOV byte ptr [ESP + 0x1a],CL
    m.w8((f.sp+0x0000001au), (s.cx & 0xffu));
  }
  { // 0x60a630: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  { // 0x60a634: e8d79c0200 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,6334009u); flags=s.arithmetic_flags;
  }
  { // 0x60a639: 8b442412 MOV EAX,dword ptr [ESP + 0x12]
    s.ax = m.r32((f.sp+0x00000012u));
  }
  { // 0x60a63d: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x60a643: 8b542411 MOV EDX,dword ptr [ESP + 0x11]
    s.dx = m.r32((f.sp+0x00000011u));
  }
  { // 0x60a647: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x60a64c: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x60a64e: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x60a654: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x60a65a: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x60a65c: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x60a662: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x60a664: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x60a66a: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x60a66c: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x60a66e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x60a672: e984000000 JMP 0x0060a6fb
    goto L0060a6fb;
  }
  L0060a677: { // 0x60a677: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x60a67d: 8b7130 MOV ESI,dword ptr [ECX + 0x30]
    s.si = m.r32((s.cx+0x00000030u));
  }
  { // 0x60a680: e82ba1eeff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6334085u); flags=s.arithmetic_flags;
  }
  { // 0x60a685: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60a687: 740c JZ 0x0060a695
    if(integer::condition("JZ",flags)) goto L0060a695;
  }
  { // 0x60a689: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  { // 0x60a68e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x60a690: 7403 JZ 0x0060a695
    if(integer::condition("JZ",flags)) goto L0060a695;
  }
  { // 0x60a692: 8b7030 MOV ESI,dword ptr [EAX + 0x30]
    s.si = m.r32((s.ax+0x00000030u));
  }
  L0060a695: { // 0x60a695: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  { // 0x60a69a: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  { // 0x60a69f: 6a64 PUSH 0x64
    f.push(m,0x00000064u);
  }
  { // 0x60a6a1: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x60a6a4: 81c1e9550000 ADD ECX,0x55e9
    s.cx = integer::add(s.cx,0x000055e9u,32,flags);
  }
  { // 0x60a6aa: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  { // 0x60a6ad: 6689542418 MOV word ptr [ESP + 0x18],DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  { // 0x60a6b2: 8a4102 MOV AL,byte ptr [ECX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000002u)));
  }
  { // 0x60a6b5: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  { // 0x60a6b9: 8844241a MOV byte ptr [ESP + 0x1a],AL
    m.w8((f.sp+0x0000001au), (s.ax & 0xffu));
  }
  { // 0x60a6bd: e84e9c0200 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,6334146u); flags=s.arithmetic_flags;
  }
  { // 0x60a6c2: 8b442412 MOV EAX,dword ptr [ESP + 0x12]
    s.ax = m.r32((f.sp+0x00000012u));
  }
  { // 0x60a6c6: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x60a6cc: 8b542411 MOV EDX,dword ptr [ESP + 0x11]
    s.dx = m.r32((f.sp+0x00000011u));
  }
  { // 0x60a6d0: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x60a6d5: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x60a6d7: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x60a6dd: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x60a6e3: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x60a6e5: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x60a6eb: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x60a6ed: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x60a6f3: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x60a6f5: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x60a6f7: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0060a6fb: { // 0x60a6fb: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  { // 0x60a701: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x60a707: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x60a709: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  { // 0x60a70f: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x60a711: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x60a713: 8983ac000000 MOV dword ptr [EBX + 0xac],EAX
    m.w32((s.bx+0x000000acu), s.ax);
  }
  L0060a719: { // 0x60a719: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x60a71a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60a71b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x60a71c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x60a71d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x60a720: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
