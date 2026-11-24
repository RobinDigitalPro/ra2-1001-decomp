#include "recovered/recovery_b588_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b588 {
namespace {
void f_00147f40(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000782d0(Memory&,State&,Frame&,const Operations&);
void f_00078360(Memory&,State&,Frame&,const Operations&);
void f_000e6b70(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00147f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547f40: { // 0x547f40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00547f44: { // 0x547f44: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L00547f4a: { // 0x547f4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547f4b: { // 0x547f4b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547f4c: { // 0x547f4c: 0fbf30 MOVSX ESI,word ptr [EAX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00547f4f: { // 0x547f4f: 0fbf4002 MOVSX EAX,word ptr [EAX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00547f53: { // 0x547f53: 8d3c30 LEA EDI,[EAX + ESI*0x1]
    s.di = (s.ax+(s.si * 0x00000001u));
  }
  L00547f56: { // 0x547f56: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00547f58: { // 0x547f58: 7e24 JLE 0x00547f7e
    if(integer::condition("JLE",flags)) goto L00547f7e;
  }
  L00547f5a: { // 0x547f5a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547f5b: { // 0x547f5b: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00547f5d: { // 0x547f5d: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00547f5f: { // 0x547f5f: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547f61: { // 0x547f61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547f62: { // 0x547f62: 7d1a JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f64: { // 0x547f64: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00547f66: { // 0x547f66: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00547f68: { // 0x547f68: 7d14 JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f6a: { // 0x547f6a: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L00547f70: { // 0x547f70: 8d0c42 LEA ECX,[EDX + EAX*0x2]
    s.cx = (s.dx+(s.ax * 0x00000002u));
  }
  L00547f73: { // 0x547f73: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00547f75: { // 0x547f75: 7f07 JG 0x00547f7e
    if(integer::condition("JG",flags)) goto L00547f7e;
  }
  L00547f77: { // 0x547f77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f78: { // 0x547f78: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00547f7a: { // 0x547f7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f7b: { // 0x547f7b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00547f7e: { // 0x547f7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f7f: { // 0x547f7f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00547f81: { // 0x547f81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f82: { // 0x547f82: c20400 RET 0x4
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
void f_000782d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004782d0: { // 0x004782d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004782d1: { // 0x004782d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004782d3: { // 0x004782d3: f6864001000010 TEST byte ptr [ESI + 0x140],0x10
    (void)integer::logical((m.r8((s.si+0x00000140u)))&(0x00000010u),8,flags);
  }
  L004782da: { // 0x004782da: 7532 JNZ 0x0047830e
    if(integer::condition("JNZ",flags)) goto L0047830e;
  }
  L004782dc: { // 0x004782dc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004782de: { // 0x004782de: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L004782e0: { // 0x004782e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004782e2: { // 0x004782e2: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L004782e4: { // 0x004782e4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004782e6: { // 0x004782e6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004782e8: { // 0x004782e8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004782ea: { // 0x004782ea: e871000000 CALL 0x00478360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00478360u,4686575u); flags=s.arithmetic_flags;
  }
  L004782ef: { // 0x004782ef: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004782f1: { // 0x004782f1: 741b JZ 0x0047830e
    if(integer::condition("JZ",flags)) goto L0047830e;
  }
  L004782f3: { // 0x004782f3: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L004782f9: { // 0x004782f9: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L004782fb: { // 0x004782fb: 898640010000 MOV dword ptr [ESI + 0x140],EAX
    m.w32((s.si+0x00000140u), s.ax);
  }
  L00478301: { // 0x00478301: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00478305: { // 0x00478305: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  L00478308: { // 0x00478308: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047830a: { // 0x0047830a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047830b: { // 0x0047830b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0047830e: { // 0x0047830e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00478310: { // 0x00478310: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478311: { // 0x00478311: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00078360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00478360: { // 0x478360: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00478364: { // 0x478364: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00478365: { // 0x478365: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00478366: { // 0x478366: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00478367: { // 0x478367: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L0047836a: { // 0x47836a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047836b: { // 0x47836b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0047836d: { // 0x47836d: 0f8447010000 JZ 0x004784ba
    if(integer::condition("JZ",flags)) goto L004784ba;
  }
  L00478373: { // 0x478373: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00478377: { // 0x478377: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0047837b: { // 0x47837b: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0047837f: { // 0x47837f: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L00478382: { // 0x478382: 741d JZ 0x004783a1
    if(integer::condition("JZ",flags)) goto L004783a1;
  }
  L00478384: { // 0x478384: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00478385: { // 0x478385: 8d4624 LEA EAX,[ESI + 0x24]
    s.ax = (s.si+0x00000024u);
  }
  L00478388: { // 0x478388: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00478389: { // 0x478389: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047838a: { // 0x47838a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047838f: { // 0x47838f: e8ec490d00 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4686740u); flags=s.arithmetic_flags;
  }
  L00478394: { // 0x478394: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00478396: { // 0x478396: 7409 JZ 0x004783a1
    if(integer::condition("JZ",flags)) goto L004783a1;
  }
  L00478398: { // 0x478398: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478399: { // 0x478399: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047839a: { // 0x47839a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047839b: { // 0x47839b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047839d: { // 0x47839d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047839e: { // 0x47839e: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004783a1: { // 0x4783a1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004783a5: { // 0x4783a5: ba00010000 MOV EDX,0x100
    s.dx = 0x00000100u;
  }
  L004783aa: { // 0x4783aa: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004783ad: { // 0x4783ad: 7438 JZ 0x004783e7
    if(integer::condition("JZ",flags)) goto L004783e7;
  }
  L004783af: { // 0x4783af: 0fbe8e1b010000 MOVSX ECX,byte ptr [ESI + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004783b6: { // 0x4783b6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004783b8: { // 0x4783b8: 7418 JZ 0x004783d2
    if(integer::condition("JZ",flags)) goto L004783d2;
  }
  L004783ba: { // 0x4783ba: 859640010000 TEST dword ptr [ESI + 0x140],EDX
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.dx),32,flags);
  }
  L004783c0: { // 0x4783c0: 7407 JZ 0x004783c9
    if(integer::condition("JZ",flags)) goto L004783c9;
  }
  L004783c2: { // 0x4783c2: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L004783c5: { // 0x4783c5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004783c7: { // 0x4783c7: 741e JZ 0x004783e7
    if(integer::condition("JZ",flags)) goto L004783e7;
  }
  L004783c9: { // 0x4783c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004783ca: { // 0x4783ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004783cb: { // 0x4783cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004783cc: { // 0x4783cc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004783ce: { // 0x4783ce: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004783cf: { // 0x4783cf: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004783d2: { // 0x4783d2: 859640010000 TEST dword ptr [ESI + 0x140],EDX
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.dx),32,flags);
  }
  L004783d8: { // 0x4783d8: 740d JZ 0x004783e7
    if(integer::condition("JZ",flags)) goto L004783e7;
  }
  L004783da: { // 0x4783da: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004783dc: { // 0x4783dc: 7509 JNZ 0x004783e7
    if(integer::condition("JNZ",flags)) goto L004783e7;
  }
  L004783de: { // 0x4783de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004783df: { // 0x4783df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004783e0: { // 0x4783e0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004783e1: { // 0x4783e1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004783e3: { // 0x4783e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004783e4: { // 0x4783e4: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004783e7: { // 0x4783e7: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L004783e9: { // 0x4783e9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004783ec: { // 0x4783ec: 740e JZ 0x004783fc
    if(integer::condition("JZ",flags)) goto L004783fc;
  }
  L004783ee: { // 0x4783ee: 0fbebe1b010000 MOVSX EDI,byte ptr [ESI + 0x11b]
    s.di = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004783f5: { // 0x4783f5: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L004783f8: { // 0x4783f8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004783fa: { // 0x4783fa: 7514 JNZ 0x00478410
    if(integer::condition("JNZ",flags)) goto L00478410;
  }
  L004783fc: { // 0x4783fc: 859640010000 TEST dword ptr [ESI + 0x140],EDX
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.dx),32,flags);
  }
  L00478402: { // 0x478402: 740c JZ 0x00478410
    if(integer::condition("JZ",flags)) goto L00478410;
  }
  L00478404: { // 0x478404: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00478406: { // 0x478406: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L00478408: { // 0x478408: 8a8628010000 MOV AL,byte ptr [ESI + 0x128]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000128u)));
  }
  L0047840e: { // 0x47840e: eb08 JMP 0x00478418
    goto L00478418;
  }
  L00478410: { // 0x478410: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00478412: { // 0x478412: 8a8624010000 MOV AL,byte ptr [ESI + 0x124]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000124u)));
  }
  L00478418: { // 0x478418: 8a542418 MOV DL,byte ptr [ESP + 0x18]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000018u)));
  }
  L0047841c: { // 0x47841c: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0047841e: { // 0x47841e: 7405 JZ 0x00478425
    if(integer::condition("JZ",flags)) goto L00478425;
  }
  L00478420: { // 0x478420: 25e0000000 AND EAX,0xe0
    s.ax = integer::logical((s.ax)&(0x000000e0u),32,flags);
  }
  L00478425: { // 0x478425: 8a54241c MOV DL,byte ptr [ESP + 0x1c]
    s.dx = with_al(s.dx, m.r8((f.sp+0x0000001cu)));
  }
  L00478429: { // 0x478429: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0047842b: { // 0x47842b: 7403 JZ 0x00478430
    if(integer::condition("JZ",flags)) goto L00478430;
  }
  L0047842d: { // 0x47842d: 83e05f AND EAX,0x5f
    s.ax = integer::logical((s.ax)&(0x0000005fu),32,flags);
  }
  L00478430: { // 0x478430: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00478432: { // 0x478432: 7409 JZ 0x0047843d
    if(integer::condition("JZ",flags)) goto L0047843d;
  }
  L00478434: { // 0x478434: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478435: { // 0x478435: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478436: { // 0x478436: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478437: { // 0x478437: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00478439: { // 0x478439: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047843a: { // 0x47843a: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0047843d: { // 0x47843d: 8b86ec000000 MOV EAX,dword ptr [ESI + 0xec]
    s.ax = m.r32((s.si+0x000000ecu));
  }
  L00478443: { // 0x478443: 8b7644 MOV ESI,dword ptr [ESI + 0x44]
    s.si = m.r32((s.si+0x00000044u));
  }
  L00478446: { // 0x478446: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L00478449: { // 0x478449: 7445 JZ 0x00478490
    if(integer::condition("JZ",flags)) goto L00478490;
  }
  L0047844b: { // 0x47844b: 8b151ce1a100 MOV EDX,dword ptr [0x00a1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00478451: { // 0x478451: 8b34b2 MOV ESI,dword ptr [EDX + ESI*0x4]
    s.si = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  L00478454: { // 0x478454: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00478456: { // 0x478456: 7438 JZ 0x00478490
    if(integer::condition("JZ",flags)) goto L00478490;
  }
  L00478458: { // 0x478458: 8a9678020000 MOV DL,byte ptr [ESI + 0x278]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000278u)));
  }
  L0047845e: { // 0x47845e: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00478460: { // 0x478460: 742e JZ 0x00478490
    if(integer::condition("JZ",flags)) goto L00478490;
  }
  L00478462: { // 0x478462: 83fd02 CMP EBP,0x2
    (void)integer::sub(s.bp,0x00000002u,32,flags);
  }
  L00478465: { // 0x478465: 7427 JZ 0x0047848e
    if(integer::condition("JZ",flags)) goto L0047848e;
  }
  L00478467: { // 0x478467: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L0047846a: { // 0x47846a: 7422 JZ 0x0047848e
    if(integer::condition("JZ",flags)) goto L0047848e;
  }
  L0047846c: { // 0x47846c: 83fd08 CMP EBP,0x8
    (void)integer::sub(s.bp,0x00000008u,32,flags);
  }
  L0047846f: { // 0x47846f: 741d JZ 0x0047848e
    if(integer::condition("JZ",flags)) goto L0047848e;
  }
  L00478471: { // 0x478471: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00478474: { // 0x478474: 7405 JZ 0x0047847b
    if(integer::condition("JZ",flags)) goto L0047847b;
  }
  L00478476: { // 0x478476: 83fd04 CMP EBP,0x4
    (void)integer::sub(s.bp,0x00000004u,32,flags);
  }
  L00478479: { // 0x478479: 750a JNZ 0x00478485
    if(integer::condition("JNZ",flags)) goto L00478485;
  }
  L0047847b: { // 0x47847b: 8a86fd010000 MOV AL,byte ptr [ESI + 0x1fd]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fdu)));
  }
  L00478481: { // 0x478481: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00478483: { // 0x478483: 7509 JNZ 0x0047848e
    if(integer::condition("JNZ",flags)) goto L0047848e;
  }
  L00478485: { // 0x478485: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00478486: { // 0x478486: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00478487: { // 0x478487: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00478488: { // 0x478488: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047848a: { // 0x47848a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047848b: { // 0x47848b: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L0047848e: { // 0x47848e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00478490: { // 0x478490: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00478494: { // 0x478494: 8d14c2 LEA EDX,[EDX + EAX*0x8]
    s.dx = (s.dx+(s.ax * 0x00000008u));
  }
  L00478497: { // 0x478497: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00478499: { // 0x478499: d90485d0918300 FLD float ptr [EAX*0x4 + 0x8391d0]
    const auto address=((s.ax * 0x00000004u)+0x008391d0u);
    s.fp.load32(m.r32(address));
  }
  L004784a0: { // 0x4784a0: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004784a6: { // 0x4784a6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004784a8: { // 0x4784a8: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004784ab: { // 0x4784ab: 740d JZ 0x004784ba
    if(integer::condition("JZ",flags)) goto L004784ba;
  }
  L004784ad: { // 0x4784ad: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004784af: { // 0x4784af: 7509 JNZ 0x004784ba
    if(integer::condition("JNZ",flags)) goto L004784ba;
  }
  L004784b1: { // 0x4784b1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004784b2: { // 0x4784b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004784b3: { // 0x4784b3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004784b4: { // 0x4784b4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004784b6: { // 0x4784b6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004784b7: { // 0x4784b7: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L004784ba: { // 0x4784ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004784bb: { // 0x4784bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004784bc: { // 0x4784bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004784bd: { // 0x4784bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004784bf: { // 0x4784bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004784c0: { // 0x4784c0: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}
void f_000e6b70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e6b70: { // 0x4e6b70: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004e6b73: { // 0x4e6b73: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e6b74: { // 0x4e6b74: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e6b75: { // 0x4e6b75: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L004e6b79: { // 0x4e6b79: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L004e6b7b: { // 0x4e6b7b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e6b7c: { // 0x4e6b7c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004e6b7e: { // 0x4e6b7e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004e6b80: { // 0x4e6b80: 0f84f8000000 JZ 0x004e6c7e
    if(integer::condition("JZ",flags)) goto L004e6c7e;
  }
  L004e6b86: { // 0x4e6b86: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004e6b88: { // 0x4e6b88: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e6b8a: { // 0x4e6b8a: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5139341u); flags=s.arithmetic_flags;
  }
  L004e6b8d: { // 0x4e6b8d: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L004e6b90: { // 0x4e6b90: 751f JNZ 0x004e6bb1
    if(integer::condition("JNZ",flags)) goto L004e6bb1;
  }
  L004e6b92: { // 0x4e6b92: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e6b94: { // 0x4e6b94: e8d72a2100 CALL 0x006f9670
    s.arithmetic_flags=flags; invoke(m,s,f,0x006f9670u,5139353u); flags=s.arithmetic_flags;
  }
  L004e6b99: { // 0x4e6b99: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L004e6b9b: { // 0x4e6b9b: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e6b9d: { // 0x4e6b9d: 0f848c000000 JZ 0x004e6c2f
    if(integer::condition("JZ",flags)) goto L004e6c2f;
  }
  L004e6ba3: { // 0x4e6ba3: 39b708530000 CMP dword ptr [EDI + 0x5308],ESI
    (void)integer::sub(m.r32((s.di+0x00005308u)),s.si,32,flags);
  }
  L004e6ba9: { // 0x4e6ba9: 0f8580000000 JNZ 0x004e6c2f
    if(integer::condition("JNZ",flags)) goto L004e6c2f;
  }
  L004e6baf: { // 0x4e6baf: eb74 JMP 0x004e6c25
    goto L004e6c25;
  }
  L004e6bb1: { // 0x4e6bb1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004e6bb3: { // 0x4e6bb3: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L004e6bb7: { // 0x4e6bb7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6bb8: { // 0x4e6bb8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e6bba: { // 0x4e6bba: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),5139389u); flags=s.arithmetic_flags;
  }
  L004e6bbd: { // 0x4e6bbd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004e6bbf: { // 0x4e6bbf: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004e6bc1: { // 0x4e6bc1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004e6bc2: { // 0x4e6bc2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004e6bc8: { // 0x4e6bc8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004e6bca: { // 0x4e6bca: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004e6bcd: { // 0x4e6bcd: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L004e6bd2: { // 0x4e6bd2: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004e6bd5: { // 0x4e6bd5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004e6bd6: { // 0x4e6bd6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004e6bdc: { // 0x4e6bdc: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004e6bde: { // 0x4e6bde: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L004e6be2: { // 0x4e6be2: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004e6be5: { // 0x4e6be5: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L004e6bea: { // 0x4e6bea: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004e6bee: { // 0x4e6bee: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L004e6bf2: { // 0x4e6bf2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6bf3: { // 0x4e6bf3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6bf8: { // 0x4e6bf8: e843130600 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5139453u); flags=s.arithmetic_flags;
  }
  L004e6bfd: { // 0x4e6bfd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e6bff: { // 0x4e6bff: 742e JZ 0x004e6c2f
    if(integer::condition("JZ",flags)) goto L004e6c2f;
  }
  L004e6c01: { // 0x4e6c01: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L004e6c05: { // 0x4e6c05: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6c0a: { // 0x4e6c0a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6c0b: { // 0x4e6c0b: e8f0e80500 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5139472u); flags=s.arithmetic_flags;
  }
  L004e6c10: { // 0x4e6c10: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004e6c12: { // 0x4e6c12: e80917f9ff CALL 0x00478320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00478320u,5139479u); flags=s.arithmetic_flags;
  }
  L004e6c17: { // 0x4e6c17: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L004e6c19: { // 0x4e6c19: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e6c1b: { // 0x4e6c1b: 7412 JZ 0x004e6c2f
    if(integer::condition("JZ",flags)) goto L004e6c2f;
  }
  L004e6c1d: { // 0x4e6c1d: 39b708530000 CMP dword ptr [EDI + 0x5308],ESI
    (void)integer::sub(m.r32((s.di+0x00005308u)),s.si,32,flags);
  }
  L004e6c23: { // 0x4e6c23: 750a JNZ 0x004e6c2f
    if(integer::condition("JNZ",flags)) goto L004e6c2f;
  }
  L004e6c25: { // 0x4e6c25: c7870853000000000000 MOV dword ptr [EDI + 0x5308],0x0
    m.w32((s.di+0x00005308u), 0x00000000u);
  }
  L004e6c2f: { // 0x4e6c2f: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L004e6c33: { // 0x4e6c33: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e6c35: { // 0x4e6c35: 743c JZ 0x004e6c73
    if(integer::condition("JZ",flags)) goto L004e6c73;
  }
  L004e6c37: { // 0x4e6c37: 668b8f0c530000 MOV CX,word ptr [EDI + 0x530c]
    s.cx = with_ax(s.cx, m.r16((s.di+0x0000530cu)));
  }
  L004e6c3e: { // 0x4e6c3e: 8db70c530000 LEA ESI,[EDI + 0x530c]
    s.si = (s.di+0x0000530cu);
  }
  L004e6c44: { // 0x4e6c44: 663b0d5c8ba200 CMP CX,word ptr [0x00a28b5c]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a28b5cu)),16,flags);
  }
  L004e6c4b: { // 0x4e6c4b: 750d JNZ 0x004e6c5a
    if(integer::condition("JNZ",flags)) goto L004e6c5a;
  }
  L004e6c4d: { // 0x4e6c4d: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L004e6c51: { // 0x4e6c51: 663b155e8ba200 CMP DX,word ptr [0x00a28b5e]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a28b5eu)),16,flags);
  }
  L004e6c58: { // 0x4e6c58: 7419 JZ 0x004e6c73
    if(integer::condition("JZ",flags)) goto L004e6c73;
  }
  L004e6c5a: { // 0x4e6c5a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e6c5b: { // 0x4e6c5b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6c60: { // 0x4e6c60: e89be80500 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5139557u); flags=s.arithmetic_flags;
  }
  L004e6c65: { // 0x4e6c65: c74044ffffffff MOV dword ptr [EAX + 0x44],0xffffffff
    m.w32((s.ax+0x00000044u), 0xffffffffu);
  }
  L004e6c6c: { // 0x4e6c6c: a15c8ba200 MOV EAX,[0x00a28b5c]
    s.ax = m.r32((0x00a28b5cu));
  }
  L004e6c71: { // 0x4e6c71: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L004e6c73: { // 0x4e6c73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e6c74: { // 0x4e6c74: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L004e6c76: { // 0x4e6c76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e6c77: { // 0x4e6c77: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e6c78: { // 0x4e6c78: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e6c7b: { // 0x4e6c7b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004e6c7e: { // 0x4e6c7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e6c7f: { // 0x4e6c7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e6c80: { // 0x4e6c80: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e6c82: { // 0x4e6c82: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e6c83: { // 0x4e6c83: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e6c86: { // 0x4e6c86: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5537600u:f_00147f40(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4686544u:f_000782d0(m,s,child,{});break;
case 4686688u:f_00078360(m,s,child,{});break;
case 5139312u:f_000e6b70(m,s,child,{});break;
default:throw std::domain_error("recovery588 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004e6c90(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e6c90: { // 0x4e6c90: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e6c91: { // 0x4e6c91: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e6c92: { // 0x4e6c92: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e6c93: { // 0x4e6c93: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L004e6c97: { // 0x4e6c97: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004e6c99: { // 0x4e6c99: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e6c9a: { // 0x4e6c9a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6c9f: { // 0x4e6c9f: e89c120600 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5139620u); flags=s.arithmetic_flags;
  }
  L004e6ca4: { // 0x4e6ca4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e6ca6: { // 0x4e6ca6: 0f84d7000000 JZ 0x004e6d83
    if(integer::condition("JZ",flags)) goto L004e6d83;
  }
  L004e6cac: { // 0x4e6cac: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004e6cb0: { // 0x4e6cb0: 8b8e08530000 MOV ECX,dword ptr [ESI + 0x5308]
    s.cx = m.r32((s.si+0x00005308u));
  }
  L004e6cb6: { // 0x4e6cb6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e6cb7: { // 0x4e6cb7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6cb8: { // 0x4e6cb8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e6cb9: { // 0x4e6cb9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e6cbb: { // 0x4e6cbb: e8b0feffff CALL 0x004e6b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e6b70u,5139648u); flags=s.arithmetic_flags;
  }
  L004e6cc0: { // 0x4e6cc0: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004e6cc2: { // 0x4e6cc2: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L004e6cc5: { // 0x4e6cc5: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L004e6cc9: { // 0x4e6cc9: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L004e6ccd: { // 0x4e6ccd: 8b88b8000000 MOV ECX,dword ptr [EAX + 0xb8]
    s.cx = m.r32((s.ax+0x000000b8u));
  }
  L004e6cd3: { // 0x4e6cd3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e6cd4: { // 0x4e6cd4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6cd5: { // 0x4e6cd5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6cda: { // 0x4e6cda: e821e80500 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5139679u); flags=s.arithmetic_flags;
  }
  L004e6cdf: { // 0x4e6cdf: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004e6ce1: { // 0x4e6ce1: e8ea15f9ff CALL 0x004782d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004782d0u,5139686u); flags=s.arithmetic_flags;
  }
  L004e6ce6: { // 0x4e6ce6: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L004e6ce8: { // 0x4e6ce8: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e6cea: { // 0x4e6cea: 7579 JNZ 0x004e6d65
    if(integer::condition("JNZ",flags)) goto L004e6d65;
  }
  L004e6cec: { // 0x4e6cec: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e6ced: { // 0x4e6ced: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004e6cef: { // 0x4e6cef: 8d6c241c LEA EBP,[ESP + 0x1c]
    s.bp = (f.sp+0x0000001cu);
  }
  L004e6cf3: { // 0x4e6cf3: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004e6cf8: { // 0x4e6cf8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6cf9: { // 0x4e6cf9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e6cfa: { // 0x4e6cfa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6cfb: { // 0x4e6cfb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6cfc: { // 0x4e6cfc: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004e6cfe: { // 0x4e6cfe: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6cff: { // 0x4e6cff: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6d00: { // 0x4e6d00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e6d01: { // 0x4e6d01: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6d02: { // 0x4e6d02: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6d03: { // 0x4e6d03: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6d04: { // 0x4e6d04: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L004e6d06: { // 0x4e6d06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6d07: { // 0x4e6d07: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L004e6d0b: { // 0x4e6d0b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e6d0c: { // 0x4e6d0c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6d0d: { // 0x4e6d0d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6d12: { // 0x4e6d12: 6689542454 MOV word ptr [ESP + 0x54],DX
    m.w16((f.sp+0x00000054u), (s.dx & 0xffffu));
  }
  L004e6d17: { // 0x4e6d17: 6689542456 MOV word ptr [ESP + 0x56],DX
    m.w16((f.sp+0x00000056u), (s.dx & 0xffffu));
  }
  L004e6d1c: { // 0x4e6d1c: e84f6a0600 CALL 0x0054d770
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d770u,5139745u); flags=s.arithmetic_flags;
  }
  L004e6d21: { // 0x4e6d21: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004e6d23: { // 0x4e6d23: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e6d24: { // 0x4e6d24: 663b055c8ba200 CMP AX,word ptr [0x00a28b5c]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a28b5cu)),16,flags);
  }
  L004e6d2b: { // 0x4e6d2b: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004e6d2f: { // 0x4e6d2f: 750e JNZ 0x004e6d3f
    if(integer::condition("JNZ",flags)) goto L004e6d3f;
  }
  L004e6d31: { // 0x4e6d31: 668b4c2416 MOV CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000016u)));
  }
  L004e6d36: { // 0x4e6d36: 663b0d5e8ba200 CMP CX,word ptr [0x00a28b5e]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a28b5eu)),16,flags);
  }
  L004e6d3d: { // 0x4e6d3d: 743b JZ 0x004e6d7a
    if(integer::condition("JZ",flags)) goto L004e6d7a;
  }
  L004e6d3f: { // 0x4e6d3f: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004e6d42: { // 0x4e6d42: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L004e6d46: { // 0x4e6d46: 8b82b8000000 MOV EAX,dword ptr [EDX + 0xb8]
    s.ax = m.r32((s.dx+0x000000b8u));
  }
  L004e6d4c: { // 0x4e6d4c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6d4d: { // 0x4e6d4d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e6d4e: { // 0x4e6d4e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6d53: { // 0x4e6d53: e8a8e70500 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5139800u); flags=s.arithmetic_flags;
  }
  L004e6d58: { // 0x4e6d58: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004e6d5a: { // 0x4e6d5a: e87115f9ff CALL 0x004782d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004782d0u,5139807u); flags=s.arithmetic_flags;
  }
  L004e6d5f: { // 0x4e6d5f: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L004e6d61: { // 0x4e6d61: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e6d63: { // 0x4e6d63: 7415 JZ 0x004e6d7a
    if(integer::condition("JZ",flags)) goto L004e6d7a;
  }
  L004e6d65: { // 0x4e6d65: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L004e6d69: { // 0x4e6d69: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6d6e: { // 0x4e6d6e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6d6f: { // 0x4e6d6f: e88ce70500 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5139828u); flags=s.arithmetic_flags;
  }
  L004e6d74: { // 0x4e6d74: 898608530000 MOV dword ptr [ESI + 0x5308],EAX
    m.w32((s.si+0x00005308u), s.ax);
  }
  L004e6d7a: { // 0x4e6d7a: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L004e6d7c: { // 0x4e6d7c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e6d7d: { // 0x4e6d7d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e6d7e: { // 0x4e6d7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e6d7f: { // 0x4e6d7f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004e6d80: { // 0x4e6d80: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004e6d83: { // 0x4e6d83: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e6d84: { // 0x4e6d84: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e6d86: { // 0x4e6d86: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e6d87: { // 0x4e6d87: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004e6d88: { // 0x4e6d88: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
