#include "recovered/recovery_b110_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b110 {
namespace {
void f_0014cd80(Memory&,State&,Frame&,const Operations&);
void f_0036ebd0(Memory&,State&,Frame&,const Operations&);
void f_002066d0(Memory&,State&,Frame&,const Operations&);
void f_002066f0(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_000713e0(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void f_00157380(Memory&,State&,Frame&,const Operations&);
void f_0029e2c0(Memory&,State&,Frame&,const Operations&);
void f_0025a130(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0029bcf0(Memory&,State&,Frame&,const Operations&);
void f_00297fb0(Memory&,State&,Frame&,const Operations&);
void f_0029e7b0(Memory&,State&,Frame&,const Operations&);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_002df4a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0014cd80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cd80: { // 0x54cd80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054cd81: { // 0x54cd81: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  L0054cd85: { // 0x54cd85: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cd86: { // 0x54cd86: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cd87: { // 0x54cd87: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cd88: { // 0x54cd88: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0054cd8c: { // 0x54cd8c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054cd8d: { // 0x54cd8d: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0054cd8f: { // 0x54cd8f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cd91: { // 0x54cd91: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0054cd95: { // 0x54cd95: 0f84f6000000 JZ 0x0054ce91
    if(integer::condition("JZ",flags)) goto L0054ce91;
  }
  L0054cd9b: { // 0x54cd9b: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cd9f: { // 0x54cd9f: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054cda2: { // 0x54cda2: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054cda5: { // 0x54cda5: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054cda7: { // 0x54cda7: 7814 JS 0x0054cdbd
    if(integer::condition("JS",flags)) goto L0054cdbd;
  }
  L0054cda9: { // 0x54cda9: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054cdae: { // 0x54cdae: 7d0d JGE 0x0054cdbd
    if(integer::condition("JGE",flags)) goto L0054cdbd;
  }
  L0054cdb0: { // 0x54cdb0: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054cdb6: { // 0x54cdb6: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054cdb9: { // 0x54cdb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054cdbb: { // 0x54cdbb: 750c JNZ 0x0054cdc9
    if(integer::condition("JNZ",flags)) goto L0054cdc9;
  }
  L0054cdbd: { // 0x54cdbd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0054cdbf: { // 0x54cdbf: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054cdc4: { // 0x54cdc4: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054cdc9: { // 0x54cdc9: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0054cdcf: { // 0x54cdcf: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054cdd2: { // 0x54cdd2: 0f84b9000000 JZ 0x0054ce91
    if(integer::condition("JZ",flags)) goto L0054ce91;
  }
  L0054cdd8: { // 0x54cdd8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054cdda: { // 0x54cdda: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054cddc: { // 0x54cddc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cddd: { // 0x54cddd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054cddf: { // 0x54cddf: e87c070000 CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5557732u); flags=s.arithmetic_flags;
  }
  L0054cde4: { // 0x54cde4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0054cde7: { // 0x54cde7: 0f84ca000000 JZ 0x0054ceb7
    if(integer::condition("JZ",flags)) goto L0054ceb7;
  }
  L0054cded: { // 0x54cded: 8b4f50 MOV ECX,dword ptr [EDI + 0x50]
    s.cx = m.r32((s.di+0x00000050u));
  }
  L0054cdf0: { // 0x54cdf0: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054cdf3: { // 0x54cdf3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054cdf5: { // 0x54cdf5: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0054cdf7: { // 0x54cdf7: 8a4308 MOV AL,byte ptr [EBX + 0x8]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000008u)));
  }
  L0054cdfa: { // 0x54cdfa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cdfc: { // 0x54cdfc: 7407 JZ 0x0054ce05
    if(integer::condition("JZ",flags)) goto L0054ce05;
  }
  L0054cdfe: { // 0x54cdfe: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0054ce00: { // 0x54ce00: e98c000000 JMP 0x0054ce91
    goto L0054ce91;
  }
  L0054ce05: { // 0x54ce05: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054ce09: { // 0x54ce09: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054ce0c: { // 0x54ce0c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054ce0f: { // 0x54ce0f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054ce11: { // 0x54ce11: 7818 JS 0x0054ce2b
    if(integer::condition("JS",flags)) goto L0054ce2b;
  }
  L0054ce13: { // 0x54ce13: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054ce18: { // 0x54ce18: 7d11 JGE 0x0054ce2b
    if(integer::condition("JGE",flags)) goto L0054ce2b;
  }
  L0054ce1a: { // 0x54ce1a: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054ce20: { // 0x54ce20: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054ce23: { // 0x54ce23: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054ce25: { // 0x54ce25: 7404 JZ 0x0054ce2b
    if(integer::condition("JZ",flags)) goto L0054ce2b;
  }
  L0054ce27: { // 0x54ce27: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054ce29: { // 0x54ce29: eb0c JMP 0x0054ce37
    goto L0054ce37;
  }
  L0054ce2b: { // 0x54ce2b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0054ce2d: { // 0x54ce2d: bf1076a500 MOV EDI,0xa57610
    s.di = 0x00a57610u;
  }
  L0054ce32: { // 0x54ce32: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054ce37: { // 0x54ce37: 668b33 MOV SI,word ptr [EBX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L0054ce3a: { // 0x54ce3a: 8d6b04 LEA EBP,[EBX + 0x4]
    s.bp = (s.bx+0x00000004u);
  }
  L0054ce3d: { // 0x54ce3d: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0054ce43: { // 0x54ce43: 662b7500 SUB SI,word ptr [EBP]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.bp)),16,flags)) & 0xffffu);
  }
  L0054ce47: { // 0x54ce47: 66f7de NEG SI
    s.si = (s.si & 0xffff0000u) | ((integer::sub(0u,(s.si & 0xffffu),16,flags)) & 0xffffu);
  }
  L0054ce4a: { // 0x54ce4a: 1bf6 SBB ESI,ESI
    s.si = integer::sub(s.si,s.si,32,flags,flags&integer::CF);
  }
  L0054ce4c: { // 0x54ce4c: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  L0054ce4f: { // 0x54ce4f: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0054ce52: { // 0x54ce52: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054ce55: { // 0x54ce55: 7415 JZ 0x0054ce6c
    if(integer::condition("JZ",flags)) goto L0054ce6c;
  }
  L0054ce57: { // 0x54ce57: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054ce58: { // 0x54ce58: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce5a: { // 0x54ce5a: e86198f2ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5557855u); flags=s.arithmetic_flags;
  }
  L0054ce5f: { // 0x54ce5f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054ce61: { // 0x54ce61: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0054ce67: { // 0x54ce67: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054ce6a: { // 0x54ce6a: 75eb JNZ 0x0054ce57
    if(integer::condition("JNZ",flags)) goto L0054ce57;
  }
  L0054ce6c: { // 0x54ce6c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce6e: { // 0x54ce6e: e8ede6f2ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5557875u); flags=s.arithmetic_flags;
  }
  L0054ce73: { // 0x54ce73: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ce75: { // 0x54ce75: 750b JNZ 0x0054ce82
    if(integer::condition("JNZ",flags)) goto L0054ce82;
  }
  L0054ce77: { // 0x54ce77: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce79: { // 0x54ce79: e802e7f2ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5557886u); flags=s.arithmetic_flags;
  }
  L0054ce7e: { // 0x54ce7e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ce80: { // 0x54ce80: 7431 JZ 0x0054ceb3
    if(integer::condition("JZ",flags)) goto L0054ceb3;
  }
  L0054ce82: { // 0x54ce82: 83bfec00000003 CMP dword ptr [EDI + 0xec],0x3
    (void)integer::sub(m.r32((s.di+0x000000ecu)),0x00000003u,32,flags);
  }
  L0054ce89: { // 0x54ce89: 7428 JZ 0x0054ceb3
    if(integer::condition("JZ",flags)) goto L0054ceb3;
  }
  L0054ce8b: { // 0x54ce8b: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0054ce8d: { // 0x54ce8d: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0054ce91: { // 0x54ce91: 8b8ff4000000 MOV ECX,dword ptr [EDI + 0xf4]
    s.cx = m.r32((s.di+0x000000f4u));
  }
  L0054ce97: { // 0x54ce97: 8b97f0000000 MOV EDX,dword ptr [EDI + 0xf0]
    s.dx = m.r32((s.di+0x000000f0u));
  }
  L0054ce9d: { // 0x54ce9d: 8d441101 LEA EAX,[ECX + EDX*0x1 + 0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0054cea1: { // 0x54cea1: 0fbf4e02 MOVSX ECX,word ptr [ESI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cea5: { // 0x54cea5: 0fbf16 MOVSX EDX,word ptr [ESI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054cea8: { // 0x54cea8: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L0054ceab: { // 0x54ceab: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054cead: { // 0x54cead: 7913 JNS 0x0054cec2
    if(integer::condition("JNS",flags)) goto L0054cec2;
  }
  L0054ceaf: { // 0x54ceaf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054ceb1: { // 0x54ceb1: eb19 JMP 0x0054cecc
    goto L0054cecc;
  }
  L0054ceb3: { // 0x54ceb3: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0054ceb5: { // 0x54ceb5: ebd6 JMP 0x0054ce8d
    goto L0054ce8d;
  }
  L0054ceb7: { // 0x54ceb7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054ceb8: { // 0x54ceb8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054ceb9: { // 0x54ceb9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054ceba: { // 0x54ceba: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0054cebd: { // 0x54cebd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cebe: { // 0x54cebe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cebf: { // 0x54cebf: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0054cec2: { // 0x54cec2: 8b4f68 MOV ECX,dword ptr [EDI + 0x68]
    s.cx = m.r32((s.di+0x00000068u));
  }
  L0054cec5: { // 0x54cec5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0054cec7: { // 0x54cec7: 7c03 JL 0x0054cecc
    if(integer::condition("JL",flags)) goto L0054cecc;
  }
  L0054cec9: { // 0x54cec9: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L0054cecc: { // 0x54cecc: 8b4f64 MOV ECX,dword ptr [EDI + 0x64]
    s.cx = m.r32((s.di+0x00000064u));
  }
  L0054cecf: { // 0x54cecf: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0054ced1: { // 0x54ced1: 668b548102 MOV DX,word ptr [ECX + EAX*0x4 + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+(s.ax * 0x00000004u)+0x00000002u)));
  }
  L0054ced6: { // 0x54ced6: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054ceda: { // 0x54ceda: 8b4c8718 MOV ECX,dword ptr [EDI + EAX*0x4 + 0x18]
    s.cx = m.r32((s.di+(s.ax * 0x00000004u)+0x00000018u));
  }
  L0054cede: { // 0x54cede: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cedf: { // 0x54cedf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054cee1: { // 0x54cee1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cee2: { // 0x54cee2: 668b0451 MOV AX,word ptr [ECX + EDX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.cx+(s.dx * 0x00000002u))));
  }
  L0054cee6: { // 0x54cee6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cee7: { // 0x54cee7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cee8: { // 0x54cee8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cee9: { // 0x54cee9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}


void f_0036ebd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076ebd0: { // 0x76ebd0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076ebd1: { // 0x76ebd1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076ebd3: { // 0x76ebd3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076ebd4: { // 0x76ebd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076ebd5: { // 0x76ebd5: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076ebd8: { // 0x76ebd8: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L0076ebdb: { // 0x76ebdb: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0076ebde: { // 0x76ebde: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076ebe0: { // 0x76ebe0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0076ebe2: { // 0x76ebe2: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0076ebe4: { // 0x76ebe4: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0076ebe6: { // 0x76ebe6: 7608 JBE 0x0076ebf0
    if(integer::condition("JBE",flags)) goto L0076ebf0;
  }
  L0076ebe8: { // 0x76ebe8: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0076ebea: { // 0x76ebea: 0f8278010000 JC 0x0076ed68
    if(integer::condition("JC",flags)) goto L0076ed68;
  }
  L0076ebf0: { // 0x76ebf0: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076ebf6: { // 0x76ebf6: 7514 JNZ 0x0076ec0c
    if(integer::condition("JNZ",flags)) goto L0076ec0c;
  }
  L0076ebf8: { // 0x76ebf8: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ebfb: { // 0x76ebfb: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0076ebfe: { // 0x76ebfe: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec01: { // 0x76ec01: 7229 JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec03: { // 0x76ec03: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec05: { // 0x76ec05: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ec0c: { // 0x76ec0c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0076ec0e: { // 0x76ec0e: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L0076ec13: { // 0x76ec13: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0076ec16: { // 0x76ec16: 720c JC 0x0076ec24
    if(integer::condition("JC",flags)) goto L0076ec24;
  }
  L0076ec18: { // 0x76ec18: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0076ec1b: { // 0x76ec1b: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0076ec1d: { // 0x76ec1d: ff248530ec7600 JMP dword ptr [EAX*0x4 + 0x76ec30]
    switch(m.r32(((s.ax * 0x00000004u)+0x0076ec30u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ec24: { // 0x76ec24: ff248d28ed7600 JMP dword ptr [ECX*0x4 + 0x76ed28]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ed28u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ec2c: { // 0x76ec2c: ff248dacec7600 JMP dword ptr [ECX*0x4 + 0x76ecac]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ecacu))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ec40: { // 0x76ec40: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec42: { // 0x76ec42: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec44: { // 0x76ec44: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec46: { // 0x76ec46: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ec49: { // 0x76ec49: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ec4c: { // 0x76ec4c: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ec4f: { // 0x76ec4f: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec52: { // 0x76ec52: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ec55: { // 0x76ec55: 83c603 ADD ESI,0x3
    s.si = integer::add(s.si,0x00000003u,32,flags);
  }
  L0076ec58: { // 0x76ec58: 83c703 ADD EDI,0x3
    s.di = integer::add(s.di,0x00000003u,32,flags);
  }
  L0076ec5b: { // 0x76ec5b: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec5e: { // 0x76ec5e: 72cc JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec60: { // 0x76ec60: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec62: { // 0x76ec62: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ec6c: { // 0x76ec6c: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec6e: { // 0x76ec6e: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec70: { // 0x76ec70: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec72: { // 0x76ec72: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ec75: { // 0x76ec75: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec78: { // 0x76ec78: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ec7b: { // 0x76ec7b: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0076ec7e: { // 0x76ec7e: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L0076ec81: { // 0x76ec81: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec84: { // 0x76ec84: 72a6 JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076ec86: { // 0x76ec86: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ec88: { // 0x76ec88: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ec90: { // 0x76ec90: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ec92: { // 0x76ec92: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ec94: { // 0x76ec94: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ec96: { // 0x76ec96: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076ec97: { // 0x76ec97: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ec9a: { // 0x76ec9a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076ec9b: { // 0x76ec9b: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ec9e: { // 0x76ec9e: 728c JC 0x0076ec2c
    if(integer::condition("JC",flags)) goto L0076ec2c;
  }
  L0076eca0: { // 0x76eca0: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076eca2: { // 0x76eca2: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076eccc: { // 0x76eccc: 8b448ee4 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x1c]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x0000001cu));
  }
  L0076ecd0: { // 0x76ecd0: 89448fe4 MOV dword ptr [EDI + ECX*0x4 + -0x1c],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x0000001cu), s.ax);
  }
  L0076ecd4: { // 0x76ecd4: 8b448ee8 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x18]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000018u));
  }
  L0076ecd8: { // 0x76ecd8: 89448fe8 MOV dword ptr [EDI + ECX*0x4 + -0x18],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000018u), s.ax);
  }
  L0076ecdc: { // 0x76ecdc: 8b448eec MOV EAX,dword ptr [ESI + ECX*0x4 + -0x14]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000014u));
  }
  L0076ece0: { // 0x76ece0: 89448fec MOV dword ptr [EDI + ECX*0x4 + -0x14],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000014u), s.ax);
  }
  L0076ece4: { // 0x76ece4: 8b448ef0 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x10]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000010u));
  }
  L0076ece8: { // 0x76ece8: 89448ff0 MOV dword ptr [EDI + ECX*0x4 + -0x10],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000010u), s.ax);
  }
  L0076ecec: { // 0x76ecec: 8b448ef4 MOV EAX,dword ptr [ESI + ECX*0x4 + -0xc]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x0000000cu));
  }
  L0076ecf0: { // 0x76ecf0: 89448ff4 MOV dword ptr [EDI + ECX*0x4 + -0xc],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x0000000cu), s.ax);
  }
  L0076ecf4: { // 0x76ecf4: 8b448ef8 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x8]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000008u));
  }
  L0076ecf8: { // 0x76ecf8: 89448ff8 MOV dword ptr [EDI + ECX*0x4 + -0x8],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000008u), s.ax);
  }
  L0076ecfc: { // 0x76ecfc: 8b448efc MOV EAX,dword ptr [ESI + ECX*0x4 + -0x4]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)-0x00000004u));
  }
  L0076ed00: { // 0x76ed00: 89448ffc MOV dword ptr [EDI + ECX*0x4 + -0x4],EAX
    m.w32((s.di+(s.cx * 0x00000004u)-0x00000004u), s.ax);
  }
  L0076ed04: { // 0x76ed04: 8d048d00000000 LEA EAX,[ECX*0x4 + 0x0]
    s.ax = ((s.cx * 0x00000004u)+0x00000000u);
  }
  L0076ed0b: { // 0x76ed0b: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0076ed0d: { // 0x76ed0d: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0076ed0f: { // 0x76ed0f: ff249518ed7600 JMP dword ptr [EDX*0x4 + 0x76ed18]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076ed18u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ed28: { // 0x76ed28: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed2b: { // 0x76ed2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed2c: { // 0x76ed2c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed2d: { // 0x76ed2d: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed2e: { // 0x76ed2e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed30: { // 0x76ed30: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed32: { // 0x76ed32: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed34: { // 0x76ed34: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed37: { // 0x76ed37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed38: { // 0x76ed38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed39: { // 0x76ed39: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed3a: { // 0x76ed3a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed3c: { // 0x76ed3c: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed3e: { // 0x76ed3e: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed40: { // 0x76ed40: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ed43: { // 0x76ed43: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ed46: { // 0x76ed46: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed49: { // 0x76ed49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed4a: { // 0x76ed4a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed4b: { // 0x76ed4b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed4c: { // 0x76ed4c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed50: { // 0x76ed50: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076ed52: { // 0x76ed52: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076ed54: { // 0x76ed54: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ed57: { // 0x76ed57: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ed5a: { // 0x76ed5a: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ed5d: { // 0x76ed5d: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ed60: { // 0x76ed60: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ed63: { // 0x76ed63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ed64: { // 0x76ed64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ed65: { // 0x76ed65: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ed66: { // 0x76ed66: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076ed68: { // 0x76ed68: 8d7431fc LEA ESI,[ECX + ESI*0x1 + -0x4]
    s.si = (s.cx+(s.si * 0x00000001u)-0x00000004u);
  }
  L0076ed6c: { // 0x76ed6c: 8d7c39fc LEA EDI,[ECX + EDI*0x1 + -0x4]
    s.di = (s.cx+(s.di * 0x00000001u)-0x00000004u);
  }
  L0076ed70: { // 0x76ed70: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076ed76: { // 0x76ed76: 7524 JNZ 0x0076ed9c
    if(integer::condition("JNZ",flags)) goto L0076ed9c;
  }
  L0076ed78: { // 0x76ed78: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ed7b: { // 0x76ed7b: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L0076ed7e: { // 0x76ed7e: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ed81: { // 0x76ed81: 720d JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ed83: { // 0x76ed83: fd STD
    flags |= 0x400u;
  }
  L0076ed84: { // 0x76ed84: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ed86: { // 0x76ed86: fc CLD
    flags &= ~0x400u;
  }
  L0076ed87: { // 0x76ed87: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ed90: { // 0x76ed90: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0076ed92: { // 0x76ed92: ff248d60ee7600 JMP dword ptr [ECX*0x4 + 0x76ee60]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076ee60u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ed9c: { // 0x76ed9c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0076ed9e: { // 0x76ed9e: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L0076eda3: { // 0x76eda3: 83f904 CMP ECX,0x4
    (void)integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0076eda6: { // 0x76eda6: 720c JC 0x0076edb4
    if(integer::condition("JC",flags)) goto L0076edb4;
  }
  L0076eda8: { // 0x76eda8: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0076edab: { // 0x76edab: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0076edad: { // 0x76edad: ff2485b8ed7600 JMP dword ptr [EAX*0x4 + 0x76edb8]
    switch(m.r32(((s.ax * 0x00000004u)+0x0076edb8u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076edb4: { // 0x76edb4: ff248db0ee7600 JMP dword ptr [ECX*0x4 + 0x76eeb0]
    switch(m.r32(((s.cx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076edc8: { // 0x76edc8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076edcb: { // 0x76edcb: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076edcd: { // 0x76edcd: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076edd0: { // 0x76edd0: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0076edd1: { // 0x76edd1: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076edd4: { // 0x76edd4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0076edd5: { // 0x76edd5: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076edd8: { // 0x76edd8: 72b6 JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076edda: { // 0x76edda: fd STD
    flags |= 0x400u;
  }
  L0076eddb: { // 0x76eddb: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076eddd: { // 0x76eddd: fc CLD
    flags &= ~0x400u;
  }
  L0076edde: { // 0x76edde: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ede8: { // 0x76ede8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076edeb: { // 0x76edeb: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076eded: { // 0x76eded: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076edf0: { // 0x76edf0: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076edf3: { // 0x76edf3: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076edf6: { // 0x76edf6: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076edf9: { // 0x76edf9: 83ee02 SUB ESI,0x2
    s.si = integer::sub(s.si,0x00000002u,32,flags);
  }
  L0076edfc: { // 0x76edfc: 83ef02 SUB EDI,0x2
    s.di = integer::sub(s.di,0x00000002u,32,flags);
  }
  L0076edff: { // 0x76edff: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ee02: { // 0x76ee02: 728c JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ee04: { // 0x76ee04: fd STD
    flags |= 0x400u;
  }
  L0076ee05: { // 0x76ee05: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ee07: { // 0x76ee07: fc CLD
    flags &= ~0x400u;
  }
  L0076ee08: { // 0x76ee08: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ee10: { // 0x76ee10: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076ee13: { // 0x76ee13: 23d1 AND EDX,ECX
    s.dx = integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076ee15: { // 0x76ee15: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076ee18: { // 0x76ee18: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076ee1b: { // 0x76ee1b: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076ee1e: { // 0x76ee1e: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076ee21: { // 0x76ee21: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076ee24: { // 0x76ee24: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076ee27: { // 0x76ee27: 83ee03 SUB ESI,0x3
    s.si = integer::sub(s.si,0x00000003u,32,flags);
  }
  L0076ee2a: { // 0x76ee2a: 83ef03 SUB EDI,0x3
    s.di = integer::sub(s.di,0x00000003u,32,flags);
  }
  L0076ee2d: { // 0x76ee2d: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0076ee30: { // 0x76ee30: 0f825affffff JC 0x0076ed90
    if(integer::condition("JC",flags)) goto L0076ed90;
  }
  L0076ee36: { // 0x76ee36: fd STD
    flags |= 0x400u;
  }
  L0076ee37: { // 0x76ee37: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076ee39: { // 0x76ee39: fc CLD
    flags &= ~0x400u;
  }
  L0076ee3a: { // 0x76ee3a: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076ee64: { // 0x76ee64: 8b448e1c MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1c]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x0000001cu));
  }
  L0076ee68: { // 0x76ee68: 89448f1c MOV dword ptr [EDI + ECX*0x4 + 0x1c],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x0000001cu), s.ax);
  }
  L0076ee6c: { // 0x76ee6c: 8b448e18 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x18]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000018u));
  }
  L0076ee70: { // 0x76ee70: 89448f18 MOV dword ptr [EDI + ECX*0x4 + 0x18],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000018u), s.ax);
  }
  L0076ee74: { // 0x76ee74: 8b448e14 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x14]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000014u));
  }
  L0076ee78: { // 0x76ee78: 89448f14 MOV dword ptr [EDI + ECX*0x4 + 0x14],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000014u), s.ax);
  }
  L0076ee7c: { // 0x76ee7c: 8b448e10 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x10]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000010u));
  }
  L0076ee80: { // 0x76ee80: 89448f10 MOV dword ptr [EDI + ECX*0x4 + 0x10],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000010u), s.ax);
  }
  L0076ee84: { // 0x76ee84: 8b448e0c MOV EAX,dword ptr [ESI + ECX*0x4 + 0xc]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0076ee88: { // 0x76ee88: 89448f0c MOV dword ptr [EDI + ECX*0x4 + 0xc],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x0000000cu), s.ax);
  }
  L0076ee8c: { // 0x76ee8c: 8b448e08 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x8]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000008u));
  }
  L0076ee90: { // 0x76ee90: 89448f08 MOV dword ptr [EDI + ECX*0x4 + 0x8],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000008u), s.ax);
  }
  L0076ee94: { // 0x76ee94: 8b448e04 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x4]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)+0x00000004u));
  }
  L0076ee98: { // 0x76ee98: 89448f04 MOV dword ptr [EDI + ECX*0x4 + 0x4],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x00000004u), s.ax);
  }
  L0076ee9c: { // 0x76ee9c: 8d048d00000000 LEA EAX,[ECX*0x4 + 0x0]
    s.ax = ((s.cx * 0x00000004u)+0x00000000u);
  }
  L0076eea3: { // 0x76eea3: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0076eea5: { // 0x76eea5: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0076eea7: { // 0x76eea7: ff2495b0ee7600 JMP dword ptr [EDX*0x4 + 0x76eeb0]
    switch(m.r32(((s.dx * 0x00000004u)+0x0076eeb0u))){
    case 0x0076ebd0u: goto L0076ebd0;
    case 0x0076ebd1u: goto L0076ebd1;
    case 0x0076ebd3u: goto L0076ebd3;
    case 0x0076ebd4u: goto L0076ebd4;
    case 0x0076ebd5u: goto L0076ebd5;
    case 0x0076ebd8u: goto L0076ebd8;
    case 0x0076ebdbu: goto L0076ebdb;
    case 0x0076ebdeu: goto L0076ebde;
    case 0x0076ebe0u: goto L0076ebe0;
    case 0x0076ebe2u: goto L0076ebe2;
    case 0x0076ebe4u: goto L0076ebe4;
    case 0x0076ebe6u: goto L0076ebe6;
    case 0x0076ebe8u: goto L0076ebe8;
    case 0x0076ebeau: goto L0076ebea;
    case 0x0076ebf0u: goto L0076ebf0;
    case 0x0076ebf6u: goto L0076ebf6;
    case 0x0076ebf8u: goto L0076ebf8;
    case 0x0076ebfbu: goto L0076ebfb;
    case 0x0076ebfeu: goto L0076ebfe;
    case 0x0076ec01u: goto L0076ec01;
    case 0x0076ec03u: goto L0076ec03;
    case 0x0076ec05u: goto L0076ec05;
    case 0x0076ec0cu: goto L0076ec0c;
    case 0x0076ec0eu: goto L0076ec0e;
    case 0x0076ec13u: goto L0076ec13;
    case 0x0076ec16u: goto L0076ec16;
    case 0x0076ec18u: goto L0076ec18;
    case 0x0076ec1bu: goto L0076ec1b;
    case 0x0076ec1du: goto L0076ec1d;
    case 0x0076ec24u: goto L0076ec24;
    case 0x0076ec2cu: goto L0076ec2c;
    case 0x0076ec40u: goto L0076ec40;
    case 0x0076ec42u: goto L0076ec42;
    case 0x0076ec44u: goto L0076ec44;
    case 0x0076ec46u: goto L0076ec46;
    case 0x0076ec49u: goto L0076ec49;
    case 0x0076ec4cu: goto L0076ec4c;
    case 0x0076ec4fu: goto L0076ec4f;
    case 0x0076ec52u: goto L0076ec52;
    case 0x0076ec55u: goto L0076ec55;
    case 0x0076ec58u: goto L0076ec58;
    case 0x0076ec5bu: goto L0076ec5b;
    case 0x0076ec5eu: goto L0076ec5e;
    case 0x0076ec60u: goto L0076ec60;
    case 0x0076ec62u: goto L0076ec62;
    case 0x0076ec6cu: goto L0076ec6c;
    case 0x0076ec6eu: goto L0076ec6e;
    case 0x0076ec70u: goto L0076ec70;
    case 0x0076ec72u: goto L0076ec72;
    case 0x0076ec75u: goto L0076ec75;
    case 0x0076ec78u: goto L0076ec78;
    case 0x0076ec7bu: goto L0076ec7b;
    case 0x0076ec7eu: goto L0076ec7e;
    case 0x0076ec81u: goto L0076ec81;
    case 0x0076ec84u: goto L0076ec84;
    case 0x0076ec86u: goto L0076ec86;
    case 0x0076ec88u: goto L0076ec88;
    case 0x0076ec90u: goto L0076ec90;
    case 0x0076ec92u: goto L0076ec92;
    case 0x0076ec94u: goto L0076ec94;
    case 0x0076ec96u: goto L0076ec96;
    case 0x0076ec97u: goto L0076ec97;
    case 0x0076ec9au: goto L0076ec9a;
    case 0x0076ec9bu: goto L0076ec9b;
    case 0x0076ec9eu: goto L0076ec9e;
    case 0x0076eca0u: goto L0076eca0;
    case 0x0076eca2u: goto L0076eca2;
    case 0x0076ecccu: goto L0076eccc;
    case 0x0076ecd0u: goto L0076ecd0;
    case 0x0076ecd4u: goto L0076ecd4;
    case 0x0076ecd8u: goto L0076ecd8;
    case 0x0076ecdcu: goto L0076ecdc;
    case 0x0076ece0u: goto L0076ece0;
    case 0x0076ece4u: goto L0076ece4;
    case 0x0076ece8u: goto L0076ece8;
    case 0x0076ececu: goto L0076ecec;
    case 0x0076ecf0u: goto L0076ecf0;
    case 0x0076ecf4u: goto L0076ecf4;
    case 0x0076ecf8u: goto L0076ecf8;
    case 0x0076ecfcu: goto L0076ecfc;
    case 0x0076ed00u: goto L0076ed00;
    case 0x0076ed04u: goto L0076ed04;
    case 0x0076ed0bu: goto L0076ed0b;
    case 0x0076ed0du: goto L0076ed0d;
    case 0x0076ed0fu: goto L0076ed0f;
    case 0x0076ed28u: goto L0076ed28;
    case 0x0076ed2bu: goto L0076ed2b;
    case 0x0076ed2cu: goto L0076ed2c;
    case 0x0076ed2du: goto L0076ed2d;
    case 0x0076ed2eu: goto L0076ed2e;
    case 0x0076ed30u: goto L0076ed30;
    case 0x0076ed32u: goto L0076ed32;
    case 0x0076ed34u: goto L0076ed34;
    case 0x0076ed37u: goto L0076ed37;
    case 0x0076ed38u: goto L0076ed38;
    case 0x0076ed39u: goto L0076ed39;
    case 0x0076ed3au: goto L0076ed3a;
    case 0x0076ed3cu: goto L0076ed3c;
    case 0x0076ed3eu: goto L0076ed3e;
    case 0x0076ed40u: goto L0076ed40;
    case 0x0076ed43u: goto L0076ed43;
    case 0x0076ed46u: goto L0076ed46;
    case 0x0076ed49u: goto L0076ed49;
    case 0x0076ed4au: goto L0076ed4a;
    case 0x0076ed4bu: goto L0076ed4b;
    case 0x0076ed4cu: goto L0076ed4c;
    case 0x0076ed50u: goto L0076ed50;
    case 0x0076ed52u: goto L0076ed52;
    case 0x0076ed54u: goto L0076ed54;
    case 0x0076ed57u: goto L0076ed57;
    case 0x0076ed5au: goto L0076ed5a;
    case 0x0076ed5du: goto L0076ed5d;
    case 0x0076ed60u: goto L0076ed60;
    case 0x0076ed63u: goto L0076ed63;
    case 0x0076ed64u: goto L0076ed64;
    case 0x0076ed65u: goto L0076ed65;
    case 0x0076ed66u: goto L0076ed66;
    case 0x0076ed68u: goto L0076ed68;
    case 0x0076ed6cu: goto L0076ed6c;
    case 0x0076ed70u: goto L0076ed70;
    case 0x0076ed76u: goto L0076ed76;
    case 0x0076ed78u: goto L0076ed78;
    case 0x0076ed7bu: goto L0076ed7b;
    case 0x0076ed7eu: goto L0076ed7e;
    case 0x0076ed81u: goto L0076ed81;
    case 0x0076ed83u: goto L0076ed83;
    case 0x0076ed84u: goto L0076ed84;
    case 0x0076ed86u: goto L0076ed86;
    case 0x0076ed87u: goto L0076ed87;
    case 0x0076ed90u: goto L0076ed90;
    case 0x0076ed92u: goto L0076ed92;
    case 0x0076ed9cu: goto L0076ed9c;
    case 0x0076ed9eu: goto L0076ed9e;
    case 0x0076eda3u: goto L0076eda3;
    case 0x0076eda6u: goto L0076eda6;
    case 0x0076eda8u: goto L0076eda8;
    case 0x0076edabu: goto L0076edab;
    case 0x0076edadu: goto L0076edad;
    case 0x0076edb4u: goto L0076edb4;
    case 0x0076edc8u: goto L0076edc8;
    case 0x0076edcbu: goto L0076edcb;
    case 0x0076edcdu: goto L0076edcd;
    case 0x0076edd0u: goto L0076edd0;
    case 0x0076edd1u: goto L0076edd1;
    case 0x0076edd4u: goto L0076edd4;
    case 0x0076edd5u: goto L0076edd5;
    case 0x0076edd8u: goto L0076edd8;
    case 0x0076eddau: goto L0076edda;
    case 0x0076eddbu: goto L0076eddb;
    case 0x0076edddu: goto L0076eddd;
    case 0x0076eddeu: goto L0076edde;
    case 0x0076ede8u: goto L0076ede8;
    case 0x0076edebu: goto L0076edeb;
    case 0x0076ededu: goto L0076eded;
    case 0x0076edf0u: goto L0076edf0;
    case 0x0076edf3u: goto L0076edf3;
    case 0x0076edf6u: goto L0076edf6;
    case 0x0076edf9u: goto L0076edf9;
    case 0x0076edfcu: goto L0076edfc;
    case 0x0076edffu: goto L0076edff;
    case 0x0076ee02u: goto L0076ee02;
    case 0x0076ee04u: goto L0076ee04;
    case 0x0076ee05u: goto L0076ee05;
    case 0x0076ee07u: goto L0076ee07;
    case 0x0076ee08u: goto L0076ee08;
    case 0x0076ee10u: goto L0076ee10;
    case 0x0076ee13u: goto L0076ee13;
    case 0x0076ee15u: goto L0076ee15;
    case 0x0076ee18u: goto L0076ee18;
    case 0x0076ee1bu: goto L0076ee1b;
    case 0x0076ee1eu: goto L0076ee1e;
    case 0x0076ee21u: goto L0076ee21;
    case 0x0076ee24u: goto L0076ee24;
    case 0x0076ee27u: goto L0076ee27;
    case 0x0076ee2au: goto L0076ee2a;
    case 0x0076ee2du: goto L0076ee2d;
    case 0x0076ee30u: goto L0076ee30;
    case 0x0076ee36u: goto L0076ee36;
    case 0x0076ee37u: goto L0076ee37;
    case 0x0076ee39u: goto L0076ee39;
    case 0x0076ee3au: goto L0076ee3a;
    case 0x0076ee64u: goto L0076ee64;
    case 0x0076ee68u: goto L0076ee68;
    case 0x0076ee6cu: goto L0076ee6c;
    case 0x0076ee70u: goto L0076ee70;
    case 0x0076ee74u: goto L0076ee74;
    case 0x0076ee78u: goto L0076ee78;
    case 0x0076ee7cu: goto L0076ee7c;
    case 0x0076ee80u: goto L0076ee80;
    case 0x0076ee84u: goto L0076ee84;
    case 0x0076ee88u: goto L0076ee88;
    case 0x0076ee8cu: goto L0076ee8c;
    case 0x0076ee90u: goto L0076ee90;
    case 0x0076ee94u: goto L0076ee94;
    case 0x0076ee98u: goto L0076ee98;
    case 0x0076ee9cu: goto L0076ee9c;
    case 0x0076eea3u: goto L0076eea3;
    case 0x0076eea5u: goto L0076eea5;
    case 0x0076eea7u: goto L0076eea7;
    case 0x0076eec0u: goto L0076eec0;
    case 0x0076eec3u: goto L0076eec3;
    case 0x0076eec4u: goto L0076eec4;
    case 0x0076eec5u: goto L0076eec5;
    case 0x0076eec6u: goto L0076eec6;
    case 0x0076eec8u: goto L0076eec8;
    case 0x0076eecbu: goto L0076eecb;
    case 0x0076eeceu: goto L0076eece;
    case 0x0076eed1u: goto L0076eed1;
    case 0x0076eed2u: goto L0076eed2;
    case 0x0076eed3u: goto L0076eed3;
    case 0x0076eed4u: goto L0076eed4;
    case 0x0076eed8u: goto L0076eed8;
    case 0x0076eedbu: goto L0076eedb;
    case 0x0076eedeu: goto L0076eede;
    case 0x0076eee1u: goto L0076eee1;
    case 0x0076eee4u: goto L0076eee4;
    case 0x0076eee7u: goto L0076eee7;
    case 0x0076eee8u: goto L0076eee8;
    case 0x0076eee9u: goto L0076eee9;
    case 0x0076eeeau: goto L0076eeea;
    case 0x0076eeecu: goto L0076eeec;
    case 0x0076eeefu: goto L0076eeef;
    case 0x0076eef2u: goto L0076eef2;
    case 0x0076eef5u: goto L0076eef5;
    case 0x0076eef8u: goto L0076eef8;
    case 0x0076eefbu: goto L0076eefb;
    case 0x0076eefeu: goto L0076eefe;
    case 0x0076ef01u: goto L0076ef01;
    case 0x0076ef02u: goto L0076ef02;
    case 0x0076ef03u: goto L0076ef03;
    case 0x0076ef04u: goto L0076ef04;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L0076eec0: { // 0x76eec0: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eec3: { // 0x76eec3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eec4: { // 0x76eec4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eec5: { // 0x76eec5: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eec6: { // 0x76eec6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eec8: { // 0x76eec8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eecb: { // 0x76eecb: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eece: { // 0x76eece: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eed1: { // 0x76eed1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eed2: { // 0x76eed2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eed3: { // 0x76eed3: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eed4: { // 0x76eed4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eed8: { // 0x76eed8: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eedb: { // 0x76eedb: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eede: { // 0x76eede: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076eee1: { // 0x76eee1: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076eee4: { // 0x76eee4: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076eee7: { // 0x76eee7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076eee8: { // 0x76eee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076eee9: { // 0x76eee9: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076eeea: { // 0x76eeea: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076eeec: { // 0x76eeec: 8a4603 MOV AL,byte ptr [ESI + 0x3]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000003u)));
  }
  L0076eeef: { // 0x76eeef: 884703 MOV byte ptr [EDI + 0x3],AL
    m.w8((s.di+0x00000003u), (s.ax & 0xffu));
  }
  L0076eef2: { // 0x76eef2: 8a4602 MOV AL,byte ptr [ESI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000002u)));
  }
  L0076eef5: { // 0x76eef5: 884702 MOV byte ptr [EDI + 0x2],AL
    m.w8((s.di+0x00000002u), (s.ax & 0xffu));
  }
  L0076eef8: { // 0x76eef8: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0076eefb: { // 0x76eefb: 884701 MOV byte ptr [EDI + 0x1],AL
    m.w8((s.di+0x00000001u), (s.ax & 0xffu));
  }
  L0076eefe: { // 0x76eefe: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076ef01: { // 0x76ef01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ef02: { // 0x76ef02: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ef03: { // 0x76ef03: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076ef04: { // 0x76ef04: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002066d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006066d0: { // 0x006066d0: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L006066d3: { // 0x006066d3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006066d5: { // 0x006066d5: 7412 JZ 0x006066e9
    if(integer::condition("JZ",flags)) goto L006066e9;
  }
  L006066d7: { // 0x006066d7: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L006066db: { // 0x006066db: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006066dd: { // 0x006066dd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006066de: { // 0x006066de: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L006066e2: { // 0x006066e2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006066e3: { // 0x006066e3: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6317798u); flags=s.arithmetic_flags;
  }
  L006066e6: { // 0x006066e6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L006066e9: { // 0x006066e9: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L006066ed: { // 0x006066ed: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002066f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006066f0: { // 0x6066f0: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L006066f3: { // 0x6066f3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006066f5: { // 0x6066f5: 7405 JZ 0x006066fc
    if(integer::condition("JZ",flags)) goto L006066fc;
  }
  L006066f7: { // 0x6066f7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006066f9: { // 0x6066f9: ff6004 JMP dword ptr [EAX + 0x4]
    switch(m.r32((s.ax+0x00000004u))){
    case 0x006066f0u: goto L006066f0;
    case 0x006066f3u: goto L006066f3;
    case 0x006066f5u: goto L006066f5;
    case 0x006066f7u: goto L006066f7;
    case 0x006066f9u: goto L006066f9;
    case 0x006066fcu: goto L006066fc;
    case 0x006066feu: goto L006066fe;
    default:throw std::domain_error("recovery110 unsupported switch destination");}
  }
  L006066fc: { // 0x6066fc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006066fe: { // 0x6066fe: c3 RET
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

void f_000713e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713e0: { // 0x004713e0: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713e5: { // 0x004713e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713e6: { // 0x004713e6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713e8: { // 0x004713e8: 742d JZ 0x00471417
    if(integer::condition("JZ",flags)) goto L00471417;
  }
  L004713ea: { // 0x004713ea: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L004713ee: { // 0x004713ee: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713f0: { // 0x004713f0: 7408 JZ 0x004713fa
    if(integer::condition("JZ",flags)) goto L004713fa;
  }
  L004713f2: { // 0x004713f2: 8bb1e8000000 MOV ESI,dword ptr [ECX + 0xe8]
    s.si = m.r32((s.cx+0x000000e8u));
  }
  L004713f8: { // 0x004713f8: eb06 JMP 0x00471400
    goto L00471400;
  }
  L004713fa: { // 0x004713fa: 8bb1e4000000 MOV ESI,dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L00471400: { // 0x00471400: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00471402: { // 0x00471402: 7413 JZ 0x00471417
    if(integer::condition("JZ",flags)) goto L00471417;
  }
  L00471404: { // 0x00471404: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00471406: { // 0x00471406: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00471408: { // 0x00471408: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658187u); flags=s.arithmetic_flags;
  }
  L0047140b: { // 0x0047140b: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L0047140e: { // 0x0047140e: 740d JZ 0x0047141d
    if(integer::condition("JZ",flags)) goto L0047141d;
  }
  L00471410: { // 0x00471410: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00471413: { // 0x00471413: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00471415: { // 0x00471415: 75ed JNZ 0x00471404
    if(integer::condition("JNZ",flags)) goto L00471404;
  }
  L00471417: { // 0x00471417: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00471419: { // 0x00471419: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047141a: { // 0x0047141a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0047141d: { // 0x0047141d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0047141f: { // 0x0047141f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471420: { // 0x00471420: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000713b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713b0: { // 0x004713b0: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713b5: { // 0x004713b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713b6: { // 0x004713b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713b8: { // 0x004713b8: 741d JZ 0x004713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713ba: { // 0x004713ba: 8bb1e4000000 MOV ESI,dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L004713c0: { // 0x004713c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713c2: { // 0x004713c2: 7413 JZ 0x004713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713c4: { // 0x004713c4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004713c6: { // 0x004713c6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004713c8: { // 0x004713c8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658123u); flags=s.arithmetic_flags;
  }
  L004713cb: { // 0x004713cb: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L004713ce: { // 0x004713ce: 740b JZ 0x004713db
    if(integer::condition("JZ",flags)) goto L004713db;
  }
  L004713d0: { // 0x004713d0: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004713d3: { // 0x004713d3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713d5: { // 0x004713d5: 75ed JNZ 0x004713c4
    if(integer::condition("JNZ",flags)) goto L004713c4;
  }
  L004713d7: { // 0x004713d7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004713d9: { // 0x004713d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713da: { // 0x004713da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004713db: { // 0x004713db: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004713dd: { // 0x004713dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713de: { // 0x004713de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557380: { // 0x557380: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00557383: { // 0x557383: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557384: { // 0x557384: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00557388: { // 0x557388: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557389: { // 0x557389: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0055738d: { // 0x55738d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0055738e: { // 0x55738e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00557390: { // 0x557390: 668b4e04 MOV CX,word ptr [ESI + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000004u)));
  }
  L00557394: { // 0x557394: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L00557397: { // 0x557397: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0055739b: { // 0x55739b: 66894c241a MOV word ptr [ESP + 0x1a],CX
    m.w16((f.sp+0x0000001au), (s.cx & 0xffffu));
  }
  L005573a0: { // 0x5573a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005573a1: { // 0x5573a1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005573a2: { // 0x5573a2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005573a4: { // 0x5573a4: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L005573a9: { // 0x5573a9: e8a2000000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5600174u); flags=s.arithmetic_flags;
  }
  L005573ae: { // 0x5573ae: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005573b0: { // 0x5573b0: 0f848c000000 JZ 0x00557442
    if(integer::condition("JZ",flags)) goto L00557442;
  }
  L005573b6: { // 0x5573b6: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L005573b9: { // 0x5573b9: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005573bb: { // 0x5573bb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005573bc: { // 0x5573bc: 8d5408ff LEA EDX,[EAX + ECX*0x1 + -0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u)-0x00000001u);
  }
  L005573c0: { // 0x5573c0: 668b4604 MOV AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000004u)));
  }
  L005573c4: { // 0x5573c4: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L005573c8: { // 0x5573c8: 6689542420 MOV word ptr [ESP + 0x20],DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  L005573cd: { // 0x5573cd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005573ce: { // 0x5573ce: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005573d0: { // 0x5573d0: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L005573d5: { // 0x5573d5: e876000000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5600218u); flags=s.arithmetic_flags;
  }
  L005573da: { // 0x5573da: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005573dc: { // 0x5573dc: 7464 JZ 0x00557442
    if(integer::condition("JZ",flags)) goto L00557442;
  }
  L005573de: { // 0x5573de: 668b16 MOV DX,word ptr [ESI]
    s.dx = with_ax(s.dx, m.r16((s.si)));
  }
  L005573e1: { // 0x5573e1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L005573e4: { // 0x5573e4: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L005573e7: { // 0x5573e7: 668954240c MOV word ptr [ESP + 0xc],DX
    m.w16((f.sp+0x0000000cu), (s.dx & 0xffffu));
  }
  L005573ec: { // 0x5573ec: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005573ed: { // 0x5573ed: 8d5408ff LEA EDX,[EAX + ECX*0x1 + -0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u)-0x00000001u);
  }
  L005573f1: { // 0x5573f1: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L005573f5: { // 0x5573f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005573f6: { // 0x5573f6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005573f8: { // 0x5573f8: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L005573fd: { // 0x5573fd: e84e000000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5600258u); flags=s.arithmetic_flags;
  }
  L00557402: { // 0x557402: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557404: { // 0x557404: 743c JZ 0x00557442
    if(integer::condition("JZ",flags)) goto L00557442;
  }
  L00557406: { // 0x557406: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00557409: { // 0x557409: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0055740b: { // 0x55740b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0055740c: { // 0x55740c: 8d4411ff LEA EAX,[ECX + EDX*0x1 + -0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L00557410: { // 0x557410: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00557413: { // 0x557413: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L00557416: { // 0x557416: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0055741b: { // 0x55741b: 8d4411ff LEA EAX,[ECX + EDX*0x1 + -0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)-0x00000001u);
  }
  L0055741f: { // 0x55741f: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00557423: { // 0x557423: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00557424: { // 0x557424: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00557426: { // 0x557426: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0055742b: { // 0x55742b: e820000000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5600304u); flags=s.arithmetic_flags;
  }
  L00557430: { // 0x557430: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557432: { // 0x557432: 740e JZ 0x00557442
    if(integer::condition("JZ",flags)) goto L00557442;
  }
  L00557434: { // 0x557434: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557435: { // 0x557435: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557436: { // 0x557436: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0055743b: { // 0x55743b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055743c: { // 0x55743c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0055743f: { // 0x55743f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00557442: { // 0x557442: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557443: { // 0x557443: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557444: { // 0x557444: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00557446: { // 0x557446: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557447: { // 0x557447: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0055744a: { // 0x55744a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}



void f_0029e2c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e2c0: { // 0x69e2c0: a118a98100 MOV EAX,[0x0081a918]
    s.ax = m.r32((0x0081a918u));
  }
  L0069e2c5: { // 0x69e2c5: 8b0d10a98100 MOV ECX,dword ptr [0x0081a910]
    s.cx = m.r32((0x0081a910u));
  }
  L0069e2cb: { // 0x69e2cb: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  L0069e2cd: { // 0x69e2cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069e2ce: { // 0x69e2ce: 8b1d78198200 MOV EBX,dword ptr [0x00821978]
    s.bx = m.r32((0x00821978u));
  }
  L0069e2d4: { // 0x69e2d4: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069e2d6: { // 0x69e2d6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069e2d7: { // 0x69e2d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e2d8: { // 0x69e2d8: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e2db: { // 0x69e2db: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e2dc: { // 0x69e2dc: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0069e2e0: { // 0x69e2e0: 8d3480 LEA ESI,[EAX + EAX*0x4]
    s.si = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e2e3: { // 0x69e2e3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069e2e5: { // 0x69e2e5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e2e6: { // 0x69e2e6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e2e8: { // 0x69e2e8: 8b151ca98100 MOV EDX,dword ptr [0x0081a91c]
    s.dx = m.r32((0x0081a91cu));
  }
  L0069e2ee: { // 0x69e2ee: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e2f0: { // 0x69e2f0: 8d3c70 LEA EDI,[EAX + ESI*0x2]
    s.di = (s.ax+(s.si * 0x00000002u));
  }
  L0069e2f3: { // 0x69e2f3: a120a98100 MOV EAX,[0x0081a920]
    s.ax = m.r32((0x0081a920u));
  }
  L0069e2f8: { // 0x69e2f8: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e2fb: { // 0x69e2fb: 8d3480 LEA ESI,[EAX + EAX*0x4]
    s.si = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e2fe: { // 0x69e2fe: 8d4451fb LEA EAX,[ECX + EDX*0x2 + -0x5]
    s.ax = (s.cx+(s.dx * 0x00000002u)-0x00000005u);
  }
  L0069e302: { // 0x69e302: c1e602 SHL ESI,0x2
    s.si = integer::shift(s.si,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069e305: { // 0x69e305: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e308: { // 0x69e308: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L0069e30a: { // 0x69e30a: 8b1d7c198200 MOV EBX,dword ptr [0x0082197c]
    s.bx = m.r32((0x0082197cu));
  }
  L0069e310: { // 0x69e310: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0069e312: { // 0x69e312: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e315: { // 0x69e315: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069e317: { // 0x69e317: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e318: { // 0x69e318: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e31a: { // 0x69e31a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e31c: { // 0x69e31c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069e31e: { // 0x69e31e: a124a98100 MOV EAX,[0x0081a924]
    s.ax = m.r32((0x0081a924u));
  }
  L0069e323: { // 0x69e323: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069e326: { // 0x69e326: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069e329: { // 0x69e329: 8d04850e010000 LEA EAX,[EAX*0x4 + 0x10e]
    s.ax = ((s.ax * 0x00000004u)+0x0000010eu);
  }
  L0069e330: { // 0x69e330: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e331: { // 0x69e331: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e333: { // 0x69e333: 8b5504 MOV EDX,dword ptr [EBP + 0x4]
    s.dx = m.r32((s.bp+0x00000004u));
  }
  L0069e336: { // 0x69e336: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e338: { // 0x69e338: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0069e33a: { // 0x69e33a: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0069e33c: { // 0x69e33c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0069e33e: { // 0x69e33e: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0069e340: { // 0x69e340: 7d07 JGE 0x0069e349
    if(integer::condition("JGE",flags)) goto L0069e349;
  }
  L0069e342: { // 0x69e342: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0069e344: { // 0x69e344: 894d04 MOV dword ptr [EBP + 0x4],ECX
    m.w32((s.bp+0x00000004u), s.cx);
  }
  L0069e347: { // 0x69e347: eb09 JMP 0x0069e352
    goto L0069e352;
  }
  L0069e349: { // 0x69e349: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0069e34b: { // 0x69e34b: 7e05 JLE 0x0069e352
    if(integer::condition("JLE",flags)) goto L0069e352;
  }
  L0069e34d: { // 0x69e34d: 894504 MOV dword ptr [EBP + 0x4],EAX
    m.w32((s.bp+0x00000004u), s.ax);
  }
  L0069e350: { // 0x69e350: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0069e352: { // 0x69e352: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0069e355: { // 0x69e355: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0069e357: { // 0x69e357: 7d0c JGE 0x0069e365
    if(integer::condition("JGE",flags)) goto L0069e365;
  }
  L0069e359: { // 0x69e359: 897d00 MOV dword ptr [EBP],EDI
    m.w32((s.bp), s.di);
  }
  L0069e35c: { // 0x69e35c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e35d: { // 0x69e35d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e35e: { // 0x69e35e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e35f: { // 0x69e35f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0069e361: { // 0x69e361: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e362: { // 0x69e362: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0069e365: { // 0x69e365: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0069e367: { // 0x69e367: 7e0c JLE 0x0069e375
    if(integer::condition("JLE",flags)) goto L0069e375;
  }
  L0069e369: { // 0x69e369: 897500 MOV dword ptr [EBP],ESI
    m.w32((s.bp), s.si);
  }
  L0069e36c: { // 0x69e36c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e36d: { // 0x69e36d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e36e: { // 0x69e36e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e36f: { // 0x69e36f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0069e371: { // 0x69e371: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e372: { // 0x69e372: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0069e375: { // 0x69e375: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e376: { // 0x69e376: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e377: { // 0x69e377: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L0069e379: { // 0x69e379: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069e37a: { // 0x69e37a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069e37b: { // 0x69e37b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0025a130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065a130: { // 0x65a130: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0065a134: { // 0x65a134: 8b8c8132060000 MOV ECX,dword ptr [ECX + EAX*0x4 + 0x632]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)+0x00000632u));
  }
  L0065a13b: { // 0x65a13b: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0065a13f: { // 0x65a13f: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0065a141: { // 0x65a141: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_0029bcf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069bcf0: { // 0x69bcf0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0069bcf3: { // 0x69bcf3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069bcf4: { // 0x69bcf4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069bcf5: { // 0x69bcf5: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0069bcf9: { // 0x69bcf9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069bcfa: { // 0x69bcfa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069bcfb: { // 0x69bcfb: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0069bcfd: { // 0x69bcfd: 8b7500 MOV ESI,dword ptr [EBP]
    s.si = m.r32((s.bp));
  }
  L0069bd00: { // 0x69bd00: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L0069bd03: { // 0x69bd03: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0069bd07: { // 0x69bd07: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069bd0b: { // 0x69bd0b: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L0069bd0e: { // 0x69bd0e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069bd11: { // 0x69bd11: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069bd14: { // 0x69bd14: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd15: { // 0x69bd15: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd17: { // 0x69bd17: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069bd19: { // 0x69bd19: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L0069bd1c: { // 0x69bd1c: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd1e: { // 0x69bd1e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069bd21: { // 0x69bd21: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069bd23: { // 0x69bd23: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd24: { // 0x69bd24: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd26: { // 0x69bd26: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069bd28: { // 0x69bd28: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069bd2a: { // 0x69bd2a: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0069bd2d: { // 0x69bd2d: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0069bd2f: { // 0x69bd2f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069bd31: { // 0x69bd31: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069bd34: { // 0x69bd34: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd35: { // 0x69bd35: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd37: { // 0x69bd37: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd39: { // 0x69bd39: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069bd3b: { // 0x69bd3b: 8d045b LEA EAX,[EBX + EBX*0x2]
    s.ax = (s.bx+(s.bx * 0x00000002u));
  }
  L0069bd3e: { // 0x69bd3e: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd40: { // 0x69bd40: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069bd43: { // 0x69bd43: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0069bd47: { // 0x69bd47: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069bd49: { // 0x69bd49: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd4a: { // 0x69bd4a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069bd4c: { // 0x69bd4c: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd4e: { // 0x69bd4e: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069bd50: { // 0x69bd50: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069bd52: { // 0x69bd52: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd53: { // 0x69bd53: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0069bd56: { // 0x69bd56: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069bd5c: { // 0x69bd5c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069bd5e: { // 0x69bd5e: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0069bd60: { // 0x69bd60: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069bd62: { // 0x69bd62: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd65: { // 0x69bd65: e846c2ffff CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6929770u); flags=s.arithmetic_flags;
  }
  L0069bd6a: { // 0x69bd6a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069bd6c: { // 0x69bd6c: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069bd6e: { // 0x69bd6e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069bd6f: { // 0x69bd6f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069bd75: { // 0x69bd75: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0069bd79: { // 0x69bd79: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069bd7b: { // 0x69bd7b: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0069bd7f: { // 0x69bd7f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069bd82: { // 0x69bd82: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069bd84: { // 0x69bd84: 8b8fb4000000 MOV ECX,dword ptr [EDI + 0xb4]
    s.cx = m.r32((s.di+0x000000b4u));
  }
  L0069bd8a: { // 0x69bd8a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0069bd8c: { // 0x69bd8c: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  L0069bd92: { // 0x69bd92: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0069bd94: { // 0x69bd94: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0069bd96: { // 0x69bd96: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069bd98: { // 0x69bd98: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  L0069bd9a: { // 0x69bd9a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069bd9b: { // 0x69bd9b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069bd9d: { // 0x69bd9d: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0069bda1: { // 0x69bda1: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0069bda5: { // 0x69bda5: e816250000 CALL 0x0069e2c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e2c0u,6929834u); flags=s.arithmetic_flags;
  }
  L0069bdaa: { // 0x69bdaa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069bdac: { // 0x69bdac: 7411 JZ 0x0069bdbf
    if(integer::condition("JZ",flags)) goto L0069bdbf;
  }
  L0069bdae: { // 0x69bdae: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L0069bdb3: { // 0x69bdb3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069bdb5: { // 0x69bdb5: 7508 JNZ 0x0069bdbf
    if(integer::condition("JNZ",flags)) goto L0069bdbf;
  }
  L0069bdb7: { // 0x69bdb7: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0069bdbb: { // 0x69bdbb: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069bdbf: { // 0x69bdbf: 89b7640d0000 MOV dword ptr [EDI + 0xd64],ESI
    m.w32((s.di+0x00000d64u), s.si);
  }
  L0069bdc5: { // 0x69bdc5: 89b7740d0000 MOV dword ptr [EDI + 0xd74],ESI
    m.w32((s.di+0x00000d74u), s.si);
  }
  L0069bdcb: { // 0x69bdcb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069bdcd: { // 0x69bdcd: 899f680d0000 MOV dword ptr [EDI + 0xd68],EBX
    m.w32((s.di+0x00000d68u), s.bx);
  }
  L0069bdd3: { // 0x69bdd3: 899f780d0000 MOV dword ptr [EDI + 0xd78],EBX
    m.w32((s.di+0x00000d78u), s.bx);
  }
  L0069bdd9: { // 0x69bdd9: e8d2290000 CALL 0x0069e7b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e7b0u,6929886u); flags=s.arithmetic_flags;
  }
  L0069bdde: { // 0x69bdde: c6877d0d000001 MOV byte ptr [EDI + 0xd7d],0x1
    m.w8((s.di+0x00000d7du), 0x00000001u);
  }
  L0069bde5: { // 0x69bde5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069bde6: { // 0x69bde6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069bde7: { // 0x69bde7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069bde8: { // 0x69bde8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069bde9: { // 0x69bde9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069bdec: { // 0x69bdec: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697fb0: { // 0x697fb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00697fb3: { // 0x697fb3: 81f9d8020000 CMP ECX,0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  L00697fb9: { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L00697fbd: { // 0x697fbd: c744240000000000 MOV dword ptr [ESP],0x0
    m.w32((f.sp), 0x00000000u);
  }
  L00697fc5: { // 0x697fc5: 7c08 JL 0x00697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  L00697fc7: { // 0x697fc7: c744240001000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00697fd3: { // 0x697fd3: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697fd9: { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697fdd: { // 0x697fdd: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697fe3: { // 0x697fe3: e8682a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914024u); flags=s.arithmetic_flags;
  }
  L00697fe8: { // 0x697fe8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00697feb: { // 0x697feb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0029e7b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069e7b0: { // 0x69e7b0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0069e7b3: { // 0x69e7b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069e7b4: { // 0x69e7b4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0069e7b6: { // 0x69e7b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069e7b7: { // 0x69e7b7: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069e7bf: { // 0x69e7bf: 8b8e640d0000 MOV ECX,dword ptr [ESI + 0xd64]
    s.cx = m.r32((s.si+0x00000d64u));
  }
  L0069e7c5: { // 0x69e7c5: 8bbe680d0000 MOV EDI,dword ptr [ESI + 0xd68]
    s.di = m.r32((s.si+0x00000d68u));
  }
  L0069e7cb: { // 0x69e7cb: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  L0069e7d1: { // 0x69e7d1: 89beb4000000 MOV dword ptr [ESI + 0xb4],EDI
    m.w32((s.si+0x000000b4u), s.di);
  }
  L0069e7d7: { // 0x69e7d7: a17060aa00 MOV EAX,[0x00aa6070]
    s.ax = m.r32((0x00aa6070u));
  }
  L0069e7dc: { // 0x69e7dc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e7dd: { // 0x69e7dd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e7df: { // 0x69e7df: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e7e1: { // 0x69e7e1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0069e7e3: { // 0x69e7e3: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  L0069e7e9: { // 0x69e7e9: a17460aa00 MOV EAX,[0x00aa6074]
    s.ax = m.r32((0x00aa6074u));
  }
  L0069e7ee: { // 0x69e7ee: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e7ef: { // 0x69e7ef: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069e7f1: { // 0x69e7f1: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L0069e7f7: { // 0x69e7f7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069e7f9: { // 0x69e7f9: 83ea3c SUB EDX,0x3c
    s.dx = integer::sub(s.dx,0x0000003cu,32,flags);
  }
  L0069e7fc: { // 0x69e7fc: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e7fe: { // 0x69e7fe: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e800: { // 0x69e800: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L0069e804: { // 0x69e804: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069e808: { // 0x69e808: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069e80a: { // 0x69e80a: 8d96e40d0000 LEA EDX,[ESI + 0xde4]
    s.dx = (s.si+0x00000de4u);
  }
  L0069e810: { // 0x69e810: 8986b4000000 MOV dword ptr [ESI + 0xb4],EAX
    m.w32((s.si+0x000000b4u), s.ax);
  }
  L0069e816: { // 0x69e816: 83c0e2 ADD EAX,-0x1e
    s.ax = integer::add(s.ax,0xffffffe2u,32,flags);
  }
  L0069e819: { // 0x69e819: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069e81d: { // 0x69e81d: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L0069e821: { // 0x69e821: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0069e825: { // 0x69e825: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0069e829: { // 0x69e829: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069e82a: { // 0x69e82a: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0069e82e: { // 0x69e82e: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069e832: { // 0x69e832: e849f9eeff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6940727u); flags=s.arithmetic_flags;
  }
  L0069e837: { // 0x69e837: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069e839: { // 0x69e839: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0069e83d: { // 0x69e83d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0069e840: { // 0x69e840: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0069e844: { // 0x69e844: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0069e848: { // 0x69e848: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0069e84b: { // 0x69e84b: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0069e84f: { // 0x69e84f: e8fcc10c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6940756u); flags=s.arithmetic_flags;
  }
  L0069e854: { // 0x69e854: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0069e858: { // 0x69e858: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069e85a: { // 0x69e85a: e8f1c10c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6940767u); flags=s.arithmetic_flags;
  }
  L0069e85f: { // 0x69e85f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069e861: { // 0x69e861: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069e863: { // 0x69e863: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e864: { // 0x69e864: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069e86a: { // 0x69e86a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069e86b: { // 0x69e86b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069e86d: { // 0x69e86d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e870: { // 0x69e870: 8986800d0000 MOV dword ptr [ESI + 0xd80],EAX
    m.w32((s.si+0x00000d80u), s.ax);
  }
  L0069e876: { // 0x69e876: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069e878: { // 0x69e878: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069e879: { // 0x69e879: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069e87f: { // 0x69e87f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069e881: { // 0x69e881: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e884: { // 0x69e884: 8986840d0000 MOV dword ptr [ESI + 0xd84],EAX
    m.w32((s.si+0x00000d84u), s.ax);
  }
  L0069e88a: { // 0x69e88a: 8b0d7060aa00 MOV ECX,dword ptr [0x00aa6070]
    s.cx = m.r32((0x00aa6070u));
  }
  L0069e890: { // 0x69e890: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  L0069e895: { // 0x69e895: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0069e897: { // 0x69e897: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0069e899: { // 0x69e899: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
  L0069e89e: { // 0x69e89e: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e8a1: { // 0x69e8a1: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0069e8a3: { // 0x69e8a3: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0069e8a6: { // 0x69e8a6: 8d540a02 LEA EDX,[EDX + ECX*0x1 + 0x2]
    s.dx = (s.dx+(s.cx * 0x00000001u)+0x00000002u);
  }
  L0069e8aa: { // 0x69e8aa: 8996880d0000 MOV dword ptr [ESI + 0xd88],EDX
    m.w32((s.si+0x00000d88u), s.dx);
  }
  L0069e8b0: { // 0x69e8b0: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L0069e8b6: { // 0x69e8b6: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0069e8b8: { // 0x69e8b8: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0069e8ba: { // 0x69e8ba: c1fa03 SAR EDX,0x3
    s.dx = integer::shift(s.dx,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069e8bd: { // 0x69e8bd: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0069e8bf: { // 0x69e8bf: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0069e8c2: { // 0x69e8c2: 8d4c0204 LEA ECX,[EDX + EAX*0x1 + 0x4]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000004u);
  }
  L0069e8c6: { // 0x69e8c6: 898e8c0d0000 MOV dword ptr [ESI + 0xd8c],ECX
    m.w32((s.si+0x00000d8cu), s.cx);
  }
  L0069e8cc: { // 0x69e8cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069e8cd: { // 0x69e8cd: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0069e8d0: { // 0x69e8d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018e180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058e180: { // 0x58e180: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0058e183: { // 0x58e183: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058e186: { // 0x58e186: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058e187: { // 0x58e187: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0058e18b: { // 0x58e18b: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e18e: { // 0x58e18e: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058e191: { // 0x58e191: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e194: { // 0x58e194: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0058e196: { // 0x58e196: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e198: { // 0x58e198: d902 FLD float ptr [EDX]
    const auto address=(s.dx);
    s.fp.load32(m.r32(address));
  }
  L0058e19a: { // 0x58e19a: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e19c: { // 0x58e19c: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e19e: { // 0x58e19e: d8420c FADD float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1a1: { // 0x58e1a1: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1a5: { // 0x58e1a5: d94210 FLD float ptr [EDX + 0x10]
    const auto address=(s.dx+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058e1a8: { // 0x58e1a8: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1aa: { // 0x58e1aa: d94218 FLD float ptr [EDX + 0x18]
    const auto address=(s.dx+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0058e1ad: { // 0x58e1ad: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b0: { // 0x58e1b0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1b2: { // 0x58e1b2: d94214 FLD float ptr [EDX + 0x14]
    const auto address=(s.dx+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058e1b5: { // 0x58e1b5: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b8: { // 0x58e1b8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ba: { // 0x58e1ba: d8421c FADD float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1bd: { // 0x58e1bd: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1c1: { // 0x58e1c1: d94220 FLD float ptr [EDX + 0x20]
    const auto address=(s.dx+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c4: { // 0x58e1c4: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1c6: { // 0x58e1c6: d94228 FLD float ptr [EDX + 0x28]
    const auto address=(s.dx+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c9: { // 0x58e1c9: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1cc: { // 0x58e1cc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ce: { // 0x58e1ce: d94224 FLD float ptr [EDX + 0x24]
    const auto address=(s.dx+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058e1d1: { // 0x58e1d1: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1d4: { // 0x58e1d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058e1d5: { // 0x58e1d5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1d7: { // 0x58e1d7: d8422c FADD float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1da: { // 0x58e1da: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0058e1de: { // 0x58e1de: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058e1e0: { // 0x58e1e0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0058e1e4: { // 0x58e1e4: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1e8: { // 0x58e1e8: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0058e1eb: { // 0x58e1eb: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0058e1ef: { // 0x58e1ef: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0058e1f2: { // 0x58e1f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0058e1f5: { // 0x58e1f5: c20400 RET 0x4
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

void f_002df4a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006df4a0: { // 0x6df4a0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006df4a3: { // 0x6df4a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006df4a4: { // 0x6df4a4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006df4a5: { // 0x6df4a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006df4a6: { // 0x6df4a6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006df4a8: { // 0x6df4a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006df4a9: { // 0x6df4a9: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    s.ax = m.r32((s.si+0x00000110u));
  }
  L006df4af: { // 0x6df4af: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006df4b1: { // 0x6df4b1: 0f8437030000 JZ 0x006df7ee
    if(integer::condition("JZ",flags)) goto L006df7ee;
  }
  L006df4b7: { // 0x6df4b7: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006df4b9: { // 0x6df4b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006df4bb: { // 0x6df4bb: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006df4bf: { // 0x6df4bf: 0f8429030000 JZ 0x006df7ee
    if(integer::condition("JZ",flags)) goto L006df7ee;
  }
  L006df4c5: { // 0x6df4c5: dd86b0000000 FLD double ptr [ESI + 0xb0]
    const auto address=(s.si+0x000000b0u);
    s.fp.load64(read64(m,address));
  }
  L006df4cb: { // 0x6df4cb: dc1d20757800 FCOMP double ptr [0x00787520]
    const auto address=(0x00787520u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006df4d1: { // 0x6df4d1: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006df4d3: { // 0x6df4d3: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006df4d6: { // 0x6df4d6: 0f8512030000 JNZ 0x006df7ee
    if(integer::condition("JNZ",flags)) goto L006df7ee;
  }
  L006df4dc: { // 0x6df4dc: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L006df4e0: { // 0x6df4e0: dc8eb0000000 FMUL double ptr [ESI + 0xb0]
    const auto address=(s.si+0x000000b0u);
    s.fp.multiply64(read64(m,address));
  }
  L006df4e6: { // 0x6df4e6: e865b50800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7206123u); flags=s.arithmetic_flags;
  }
  L006df4eb: { // 0x6df4eb: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L006df4ee: { // 0x6df4ee: 7c11 JL 0x006df501
    if(integer::condition("JL",flags)) goto L006df501;
  }
  L006df4f0: { // 0x6df4f0: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  L006df4f3: { // 0x6df4f3: 7e07 JLE 0x006df4fc
    if(integer::condition("JLE",flags)) goto L006df4fc;
  }
  L006df4f5: { // 0x6df4f5: bf32000000 MOV EDI,0x32
    s.di = 0x00000032u;
  }
  L006df4fa: { // 0x6df4fa: eb0e JMP 0x006df50a
    goto L006df50a;
  }
  L006df4fc: { // 0x6df4fc: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L006df4ff: { // 0x6df4ff: 7d07 JGE 0x006df508
    if(integer::condition("JGE",flags)) goto L006df508;
  }
  L006df501: { // 0x6df501: bf05000000 MOV EDI,0x5
    s.di = 0x00000005u;
  }
  L006df506: { // 0x6df506: eb02 JMP 0x006df50a
    goto L006df50a;
  }
  L006df508: { // 0x6df508: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006df50a: { // 0x6df50a: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006df50f: { // 0x6df50f: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L006df515: { // 0x6df515: e8c608f5ff CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,7206170u); flags=s.arithmetic_flags;
  }
  L006df51a: { // 0x6df51a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006df51b: { // 0x6df51b: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L006df51d: { // 0x6df51d: 8b8e10010000 MOV ECX,dword ptr [ESI + 0x110]
    s.cx = m.r32((s.si+0x00000110u));
  }
  L006df523: { // 0x6df523: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006df525: { // 0x6df525: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006df526: { // 0x6df526: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006df528: { // 0x6df528: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  L006df52a: { // 0x6df52a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006df52c: { // 0x6df52c: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006df52d: { // 0x6df52d: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L006df531: { // 0x6df531: e88a95d4ff CALL 0x00428ac0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428ac0u,7206198u); flags=s.arithmetic_flags;
  }
  L006df536: { // 0x6df536: 8d143f LEA EDX,[EDI + EDI*0x1]
    s.dx = (s.di+(s.di * 0x00000001u));
  }
  L006df539: { // 0x6df539: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006df53b: { // 0x6df53b: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006df53d: { // 0x6df53d: 7e07 JLE 0x006df546
    if(integer::condition("JLE",flags)) goto L006df546;
  }
  L006df53f: { // 0x6df53f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006df541: { // 0x6df541: e8fa030000 CALL 0x006df940
    s.arithmetic_flags=flags; invoke(m,s,f,0x006df940u,7206214u); flags=s.arithmetic_flags;
  }
  L006df546: { // 0x6df546: 8b8e10010000 MOV ECX,dword ptr [ESI + 0x110]
    s.cx = m.r32((s.si+0x00000110u));
  }
  L006df54c: { // 0x6df54c: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L006df554: { // 0x6df554: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006df556: { // 0x6df556: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006df558: { // 0x6df558: 7508 JNZ 0x006df562
    if(integer::condition("JNZ",flags)) goto L006df562;
  }
  L006df55a: { // 0x6df55a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006df55c: { // 0x6df55c: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L006df560: { // 0x6df560: eb28 JMP 0x006df58a
    goto L006df58a;
  }
  L006df562: { // 0x6df562: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df565: { // 0x6df565: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006df567: { // 0x6df567: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006df56a: { // 0x6df56a: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L006df56d: { // 0x6df56d: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L006df570: { // 0x6df570: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006df572: { // 0x6df572: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006df575: { // 0x6df575: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L006df57c: { // 0x6df57c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006df57e: { // 0x6df57e: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006df57f: { // 0x6df57f: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L006df581: { // 0x6df581: e80ac9eaff CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,7206278u); flags=s.arithmetic_flags;
  }
  L006df586: { // 0x6df586: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L006df58a: { // 0x6df58a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006df58c: { // 0x6df58c: 0f8e5c020000 JLE 0x006df7ee
    if(integer::condition("JLE",flags)) goto L006df7ee;
  }
  L006df592: { // 0x6df592: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006df594: { // 0x6df594: 0f8454020000 JZ 0x006df7ee
    if(integer::condition("JZ",flags)) goto L006df7ee;
  }
  L006df59a: { // 0x6df59a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006df59b: { // 0x6df59b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006df5a0: { // 0x6df5a0: e85b5fe6ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7206309u); flags=s.arithmetic_flags;
  }
  L006df5a5: { // 0x6df5a5: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006df5a7: { // 0x6df5a7: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006df5a9: { // 0x6df5a9: e872a8d9ff CALL 0x00479e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00479e20u,7206318u); flags=s.arithmetic_flags;
  }
  L006df5ae: { // 0x6df5ae: 3b8698000000 CMP EAX,dword ptr [ESI + 0x98]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000098u)),32,flags);
  }
  L006df5b4: { // 0x6df5b4: 0f8515010000 JNZ 0x006df6cf
    if(integer::condition("JNZ",flags)) goto L006df6cf;
  }
  L006df5ba: { // 0x6df5ba: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006df5bc: { // 0x6df5bc: e80f90d9ff CALL 0x004785d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004785d0u,7206337u); flags=s.arithmetic_flags;
  }
  L006df5c1: { // 0x6df5c1: 80bd1e0100000b CMP byte ptr [EBP + 0x11e],0xb
    (void)integer::sub(m.r8((s.bp+0x0000011eu)),0x0000000bu,8,flags);
  }
  L006df5c8: { // 0x6df5c8: 0f83f0000000 JNC 0x006df6be
    if(integer::condition("JNC",flags)) goto L006df6be;
  }
  L006df5ce: { // 0x6df5ce: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006df5d4: { // 0x6df5d4: 8b8e18010000 MOV ECX,dword ptr [ESI + 0x118]
    s.cx = m.r32((s.si+0x00000118u));
  }
  L006df5da: { // 0x6df5da: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L006df5dc: { // 0x6df5dc: 8914c1 MOV dword ptr [ECX + EAX*0x8],EDX
    m.w32((s.cx+(s.ax * 0x00000008u)), s.dx);
  }
  L006df5df: { // 0x6df5df: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006df5e4: { // 0x6df5e4: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L006df5ea: { // 0x6df5ea: e8f107f5ff CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,7206383u); flags=s.arithmetic_flags;
  }
  L006df5ef: { // 0x6df5ef: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006df5f0: { // 0x6df5f0: b932000000 MOV ECX,0x32
    s.cx = 0x00000032u;
  }
  L006df5f5: { // 0x6df5f5: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L006df5fb: { // 0x6df5fb: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006df5fd: { // 0x6df5fd: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006df5ff: { // 0x6df5ff: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006df601: { // 0x6df601: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006df602: { // 0x6df602: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L006df604: { // 0x6df604: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006df606: { // 0x6df606: 8b960c010000 MOV EDX,dword ptr [ESI + 0x10c]
    s.dx = m.r32((s.si+0x0000010cu));
  }
  L006df60c: { // 0x6df60c: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L006df60e: { // 0x6df60e: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006df612: { // 0x6df612: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  L006df618: { // 0x6df618: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006df61c: { // 0x6df61c: d95cd004 FSTP float ptr [EAX + EDX*0x8 + 0x4]
    const auto address=(s.ax+(s.dx * 0x00000008u)+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006df620: { // 0x6df620: e86b94d4ff CALL 0x00428a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428a90u,7206437u); flags=s.arithmetic_flags;
  }
  L006df625: { // 0x6df625: 8b8e14010000 MOV ECX,dword ptr [ESI + 0x114]
    s.cx = m.r32((s.si+0x00000114u));
  }
  L006df62b: { // 0x6df62b: c6040801 MOV byte ptr [EAX + ECX*0x1],0x1
    m.w8((s.ax+(s.cx * 0x00000001u)), 0x00000001u);
  }
  L006df62f: { // 0x6df62f: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006df635: { // 0x6df635: 8b9618010000 MOV EDX,dword ptr [ESI + 0x118]
    s.dx = m.r32((s.si+0x00000118u));
  }
  L006df63b: { // 0x6df63b: 8bbe10010000 MOV EDI,dword ptr [ESI + 0x110]
    s.di = m.r32((s.si+0x00000110u));
  }
  L006df641: { // 0x6df641: 8d2cc2 LEA EBP,[EDX + EAX*0x8]
    s.bp = (s.dx+(s.ax * 0x00000008u));
  }
  L006df644: { // 0x6df644: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006df645: { // 0x6df645: 89860c010000 MOV dword ptr [ESI + 0x10c],EAX
    m.w32((s.si+0x0000010cu), s.ax);
  }
  L006df64b: { // 0x6df64b: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L006df64d: { // 0x6df64d: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L006df650: { // 0x6df650: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006df651: { // 0x6df651: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006df653: { // 0x6df653: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006df657: { // 0x6df657: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L006df65a: { // 0x6df65a: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L006df65e: { // 0x6df65e: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L006df660: { // 0x6df660: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006df662: { // 0x6df662: 734c JNC 0x006df6b0
    if(integer::condition("JNC",flags)) goto L006df6b0;
  }
  L006df664: { // 0x6df664: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L006df667: { // 0x6df667: 762a JBE 0x006df693
    if(integer::condition("JBE",flags)) goto L006df693;
  }
  L006df669: { // 0x6df669: 8b6f08 MOV EBP,dword ptr [EDI + 0x8]
    s.bp = m.r32((s.di+0x00000008u));
  }
  L006df66c: { // 0x6df66c: 8b5c9500 MOV EBX,dword ptr [EBP + EDX*0x4]
    s.bx = m.r32((s.bp+(s.dx * 0x00000004u)));
  }
  L006df670: { // 0x6df670: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df673: { // 0x6df673: d85c2420 FCOMP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.compare_pop32(m.r32(address));
  }
  L006df677: { // 0x6df677: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006df679: { // 0x6df679: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006df67c: { // 0x6df67c: 750d JNZ 0x006df68b
    if(integer::condition("JNZ",flags)) goto L006df68b;
  }
  L006df67e: { // 0x6df67e: 895c8d00 MOV dword ptr [EBP + ECX*0x4],EBX
    m.w32((s.bp+(s.cx * 0x00000004u)), s.bx);
  }
  L006df682: { // 0x6df682: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L006df684: { // 0x6df684: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L006df686: { // 0x6df686: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L006df689: { // 0x6df689: 77de JA 0x006df669
    if(integer::condition("JA",flags)) goto L006df669;
  }
  L006df68b: { // 0x6df68b: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L006df68f: { // 0x6df68f: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L006df693: { // 0x6df693: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L006df696: { // 0x6df696: 892c8a MOV dword ptr [EDX + ECX*0x4],EBP
    m.w32((s.dx+(s.cx * 0x00000004u)), s.bp);
  }
  L006df699: { // 0x6df699: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L006df69b: { // 0x6df69b: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L006df69e: { // 0x6df69e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006df69f: { // 0x6df69f: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L006df6a1: { // 0x6df6a1: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L006df6a3: { // 0x6df6a3: 7603 JBE 0x006df6a8
    if(integer::condition("JBE",flags)) goto L006df6a8;
  }
  L006df6a5: { // 0x6df6a5: 896f0c MOV dword ptr [EDI + 0xc],EBP
    m.w32((s.di+0x0000000cu), s.bp);
  }
  L006df6a8: { // 0x6df6a8: 3b6f10 CMP EBP,dword ptr [EDI + 0x10]
    (void)integer::sub(s.bp,m.r32((s.di+0x00000010u)),32,flags);
  }
  L006df6ab: { // 0x6df6ab: 7303 JNC 0x006df6b0
    if(integer::condition("JNC",flags)) goto L006df6b0;
  }
  L006df6ad: { // 0x6df6ad: 896f10 MOV dword ptr [EDI + 0x10],EBP
    m.w32((s.di+0x00000010u), s.bp);
  }
  L006df6b0: { // 0x6df6b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006df6b1: { // 0x6df6b1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006df6b3: { // 0x6df6b3: e8d8f9ffff CALL 0x006df090
    s.arithmetic_flags=flags; invoke(m,s,f,0x006df090u,7206584u); flags=s.arithmetic_flags;
  }
  L006df6b8: { // 0x6df6b8: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L006df6bc: { // 0x6df6bc: eb11 JMP 0x006df6cf
    goto L006df6cf;
  }
  L006df6be: { // 0x6df6be: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006df6c0: { // 0x6df6c0: e8cb93d4ff CALL 0x00428a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428a90u,7206597u); flags=s.arithmetic_flags;
  }
  L006df6c5: { // 0x6df6c5: 8b8e14010000 MOV ECX,dword ptr [ESI + 0x114]
    s.cx = m.r32((s.si+0x00000114u));
  }
  L006df6cb: { // 0x6df6cb: c6040800 MOV byte ptr [EAX + ECX*0x1],0x0
    m.w8((s.ax+(s.cx * 0x00000001u)), 0x00000000u);
  }
  L006df6cf: { // 0x6df6cf: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006df6d3: { // 0x6df6d3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006df6d4: { // 0x6df6d4: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L006df6d6: { // 0x6df6d6: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006df6da: { // 0x6df6da: 0f8d0e010000 JGE 0x006df7ee
    if(integer::condition("JGE",flags)) goto L006df7ee;
  }
  L006df6e0: { // 0x6df6e0: 8b8e10010000 MOV ECX,dword ptr [ESI + 0x110]
    s.cx = m.r32((s.si+0x00000110u));
  }
  L006df6e6: { // 0x6df6e6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006df6e8: { // 0x6df6e8: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006df6ea: { // 0x6df6ea: 750b JNZ 0x006df6f7
    if(integer::condition("JNZ",flags)) goto L006df6f7;
  }
  L006df6ec: { // 0x6df6ec: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006df6f0: { // 0x6df6f0: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L006df6f2: { // 0x6df6f2: e99bfeffff JMP 0x006df592
    goto L006df592;
  }
  L006df6f7: { // 0x6df6f7: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df6fa: { // 0x6df6fa: bd01000000 MOV EBP,0x1
    s.bp = 0x00000001u;
  }
  L006df6ff: { // 0x6df6ff: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006df702: { // 0x6df702: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L006df705: { // 0x6df705: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L006df708: { // 0x6df708: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006df70a: { // 0x6df70a: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006df70d: { // 0x6df70d: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L006df711: { // 0x6df711: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L006df718: { // 0x6df718: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006df71a: { // 0x6df71a: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006df71b: { // 0x6df71b: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L006df71d: { // 0x6df71d: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L006df71f: { // 0x6df71f: 83fb02 CMP EBX,0x2
    (void)integer::sub(s.bx,0x00000002u,32,flags);
  }
  L006df722: { // 0x6df722: 7c1d JL 0x006df741
    if(integer::condition("JL",flags)) goto L006df741;
  }
  L006df724: { // 0x6df724: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df727: { // 0x6df727: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006df72a: { // 0x6df72a: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L006df72d: { // 0x6df72d: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df730: { // 0x6df730: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df733: { // 0x6df733: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006df735: { // 0x6df735: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L006df73a: { // 0x6df73a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006df73c: { // 0x6df73c: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006df73f: { // 0x6df73f: 7405 JZ 0x006df746
    if(integer::condition("JZ",flags)) goto L006df746;
  }
  L006df741: { // 0x6df741: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L006df746: { // 0x6df746: 83fb03 CMP EBX,0x3
    (void)integer::sub(s.bx,0x00000003u,32,flags);
  }
  L006df749: { // 0x6df749: 7c1f JL 0x006df76a
    if(integer::condition("JL",flags)) goto L006df76a;
  }
  L006df74b: { // 0x6df74b: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df74e: { // 0x6df74e: 8b580c MOV EBX,dword ptr [EAX + 0xc]
    s.bx = m.r32((s.ax+0x0000000cu));
  }
  L006df751: { // 0x6df751: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006df754: { // 0x6df754: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df757: { // 0x6df757: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df75a: { // 0x6df75a: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006df75c: { // 0x6df75c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006df75e: { // 0x6df75e: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006df761: { // 0x6df761: 7507 JNZ 0x006df76a
    if(integer::condition("JNZ",flags)) goto L006df76a;
  }
  L006df763: { // 0x6df763: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L006df768: { // 0x6df768: eb05 JMP 0x006df76f
    goto L006df76f;
  }
  L006df76a: { // 0x6df76a: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L006df76d: { // 0x6df76d: 7470 JZ 0x006df7df
    if(integer::condition("JZ",flags)) goto L006df7df;
  }
  L006df76f: { // 0x6df76f: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df772: { // 0x6df772: 8b1c90 MOV EBX,dword ptr [EAX + EDX*0x4]
    s.bx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006df775: { // 0x6df775: 8b3ca8 MOV EDI,dword ptr [EAX + EBP*0x4]
    s.di = m.r32((s.ax+(s.bp * 0x00000004u)));
  }
  L006df778: { // 0x6df778: 891ca8 MOV dword ptr [EAX + EBP*0x4],EBX
    m.w32((s.ax+(s.bp * 0x00000004u)), s.bx);
  }
  L006df77b: { // 0x6df77b: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df77e: { // 0x6df77e: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L006df780: { // 0x6df780: 893c90 MOV dword ptr [EAX + EDX*0x4],EDI
    m.w32((s.ax+(s.dx * 0x00000004u)), s.di);
  }
  L006df783: { // 0x6df783: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  L006df785: { // 0x6df785: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L006df788: { // 0x6df788: 8d441201 LEA EAX,[EDX + EDX*0x1 + 0x1]
    s.ax = (s.dx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L006df78c: { // 0x6df78c: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L006df78e: { // 0x6df78e: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006df792: { // 0x6df792: 7f1d JG 0x006df7b1
    if(integer::condition("JG",flags)) goto L006df7b1;
  }
  L006df794: { // 0x6df794: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df797: { // 0x6df797: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L006df79a: { // 0x6df79a: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df79d: { // 0x6df79d: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df7a0: { // 0x6df7a0: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006df7a3: { // 0x6df7a3: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df7a6: { // 0x6df7a6: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006df7a8: { // 0x6df7a8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006df7aa: { // 0x6df7aa: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006df7ad: { // 0x6df7ad: 7502 JNZ 0x006df7b1
    if(integer::condition("JNZ",flags)) goto L006df7b1;
  }
  L006df7af: { // 0x6df7af: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L006df7b1: { // 0x6df7b1: 395c2410 CMP dword ptr [ESP + 0x10],EBX
    (void)integer::sub(m.r32((f.sp+0x00000010u)),s.bx,32,flags);
  }
  L006df7b5: { // 0x6df7b5: 7f20 JG 0x006df7d7
    if(integer::condition("JG",flags)) goto L006df7d7;
  }
  L006df7b7: { // 0x6df7b7: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006df7ba: { // 0x6df7ba: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L006df7be: { // 0x6df7be: 8b3cb8 MOV EDI,dword ptr [EAX + EDI*0x4]
    s.di = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L006df7c1: { // 0x6df7c1: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006df7c4: { // 0x6df7c4: d94704 FLD float ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df7c7: { // 0x6df7c7: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006df7ca: { // 0x6df7ca: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006df7cc: { // 0x6df7cc: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006df7ce: { // 0x6df7ce: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006df7d1: { // 0x6df7d1: 7504 JNZ 0x006df7d7
    if(integer::condition("JNZ",flags)) goto L006df7d7;
  }
  L006df7d3: { // 0x6df7d3: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L006df7d7: { // 0x6df7d7: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L006df7d9: { // 0x6df7d9: 7594 JNZ 0x006df76f
    if(integer::condition("JNZ",flags)) goto L006df76f;
  }
  L006df7db: { // 0x6df7db: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L006df7df: { // 0x6df7df: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006df7e3: { // 0x6df7e3: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006df7e7: { // 0x6df7e7: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006df7e9: { // 0x6df7e9: e9a4fdffff JMP 0x006df592
    goto L006df592;
  }
  L006df7ee: { // 0x6df7ee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006df7ef: { // 0x6df7ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006df7f0: { // 0x6df7f0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006df7f1: { // 0x6df7f1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006df7f2: { // 0x6df7f2: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006df7f5: { // 0x6df7f5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5557632u:f_0014cd80(m,s,child,{});break;
case 7793616u:f_0036ebd0(m,s,child,{});break;
case 6317776u:f_002066d0(m,s,child,{});break;
case 6317808u:f_002066f0(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 4658144u:f_000713e0(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
case 5600128u:f_00157380(m,s,child,{});break;
case 6939328u:f_0029e2c0(m,s,child,{});break;
case 6660400u:f_0025a130(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 6929648u:f_0029bcf0(m,s,child,{});break;
case 6913968u:f_00297fb0(m,s,child,{});break;
case 6940592u:f_0029e7b0(m,s,child,{});break;
case 5824896u:f_0018e180(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 7206048u:f_002df4a0(m,s,child,{});break;
default:throw std::domain_error("recovery110 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0041e130(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041e130: { // 0x41e130: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041e131: { // 0x41e131: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041e132: { // 0x41e132: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0041e136: { // 0x41e136: 8a87e8000000 MOV AL,byte ptr [EDI + 0xe8]
    s.ax = with_al(s.ax, m.r8((s.di+0x000000e8u)));
  }
  L0041e13c: { // 0x41e13c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041e13e: { // 0x41e13e: 0f8416010000 JZ 0x0041e25a
    if(integer::condition("JZ",flags)) goto L0041e25a;
  }
  L0041e144: { // 0x41e144: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0041e148: { // 0x41e148: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0041e14a: { // 0x41e14a: 0f840a010000 JZ 0x0041e25a
    if(integer::condition("JZ",flags)) goto L0041e25a;
  }
  L0041e150: { // 0x41e150: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0041e154: { // 0x41e154: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041e156: { // 0x41e156: 8b86bc530000 MOV EAX,dword ptr [ESI + 0x53bc]
    s.ax = m.r32((s.si+0x000053bcu));
  }
  L0041e15c: { // 0x41e15c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041e15d: { // 0x41e15d: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041e163: { // 0x41e163: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041e165: { // 0x41e165: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041e168: { // 0x41e168: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L0041e16d: { // 0x41e16d: 8b86c0530000 MOV EAX,dword ptr [ESI + 0x53c0]
    s.ax = m.r32((s.si+0x000053c0u));
  }
  L0041e173: { // 0x41e173: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041e174: { // 0x41e174: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041e17a: { // 0x41e17a: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L0041e180: { // 0x41e180: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041e182: { // 0x41e182: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041e183: { // 0x41e183: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041e186: { // 0x41e186: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0041e18b: { // 0x41e18b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0041e18f: { // 0x41e18f: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0041e193: { // 0x41e193: 8b81bc530000 MOV EAX,dword ptr [ECX + 0x53bc]
    s.ax = m.r32((s.cx+0x000053bcu));
  }
  L0041e199: { // 0x41e199: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041e19a: { // 0x41e19a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041e1a0: { // 0x41e1a0: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041e1a2: { // 0x41e1a2: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041e1a5: { // 0x41e1a5: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0041e1aa: { // 0x41e1aa: 8b81c0530000 MOV EAX,dword ptr [ECX + 0x53c0]
    s.ax = m.r32((s.cx+0x000053c0u));
  }
  L0041e1b0: { // 0x41e1b0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041e1b1: { // 0x41e1b1: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041e1b7: { // 0x41e1b7: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041e1b9: { // 0x41e1b9: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041e1bc: { // 0x41e1bc: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0041e1c1: { // 0x41e1c1: 8a87e9000000 MOV AL,byte ptr [EDI + 0xe9]
    s.ax = with_al(s.ax, m.r8((s.di+0x000000e9u)));
  }
  L0041e1c7: { // 0x41e1c7: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0041e1cb: { // 0x41e1cb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041e1cd: { // 0x41e1cd: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0041e1d1: { // 0x41e1d1: 745a JZ 0x0041e22d
    if(integer::condition("JZ",flags)) goto L0041e22d;
  }
  L0041e1d3: { // 0x41e1d3: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0041e1d7: { // 0x41e1d7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0041e1dc: { // 0x41e1dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0041e1dd: { // 0x41e1dd: e89eeb1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4317666u); flags=s.arithmetic_flags;
  }
  L0041e1e2: { // 0x41e1e2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0041e1e4: { // 0x41e1e4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041e1e6: { // 0x41e1e6: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0041e1ea: { // 0x41e1ea: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041e1eb: { // 0x41e1eb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041e1ec: { // 0x41e1ec: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0041e1f1: { // 0x41e1f1: e88aeb1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4317686u); flags=s.arithmetic_flags;
  }
  L0041e1f6: { // 0x41e1f6: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0041e1f8: { // 0x41e1f8: 742c JZ 0x0041e226
    if(integer::condition("JZ",flags)) goto L0041e226;
  }
  L0041e1fa: { // 0x41e1fa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041e1fc: { // 0x41e1fc: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0041e200: { // 0x41e200: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0041e202: { // 0x41e202: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041e203: { // 0x41e203: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0041e208: { // 0x41e208: e873eb1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4317709u); flags=s.arithmetic_flags;
  }
  L0041e20d: { // 0x41e20d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041e20f: { // 0x41e20f: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0041e213: { // 0x41e213: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0041e215: { // 0x41e215: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0041e216: { // 0x41e216: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0041e21b: { // 0x41e21b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0041e21d: { // 0x41e21d: e85eeb1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4317730u); flags=s.arithmetic_flags;
  }
  L0041e222: { // 0x41e222: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0041e224: { // 0x41e224: 7434 JZ 0x0041e25a
    if(integer::condition("JZ",flags)) goto L0041e25a;
  }
  L0041e226: { // 0x41e226: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041e227: { // 0x41e227: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0041e229: { // 0x41e229: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041e22a: { // 0x41e22a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041e22d: { // 0x41e22d: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0041e231: { // 0x41e231: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0041e236: { // 0x41e236: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041e237: { // 0x41e237: e844eb1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4317756u); flags=s.arithmetic_flags;
  }
  L0041e23c: { // 0x41e23c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041e23e: { // 0x41e23e: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0041e242: { // 0x41e242: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041e243: { // 0x41e243: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041e244: { // 0x41e244: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0041e249: { // 0x41e249: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0041e24b: { // 0x41e24b: e830eb1200 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,4317776u); flags=s.arithmetic_flags;
  }
  L0041e250: { // 0x41e250: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0041e252: { // 0x41e252: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041e253: { // 0x41e253: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0041e256: { // 0x41e256: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041e257: { // 0x41e257: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041e25a: { // 0x41e25a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041e25b: { // 0x41e25b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0041e25d: { // 0x41e25d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041e25e: { // 0x41e25e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0042a840(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042a840: { // 0x42a840: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L0042a843: { // 0x42a843: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042a844: { // 0x42a844: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042a845: { // 0x42a845: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042a846: { // 0x42a846: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0042a84a: { // 0x42a84a: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0042a84c: { // 0x42a84c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042a84d: { // 0x42a84d: 8b94b5740c0000 MOV EDX,dword ptr [EBP + ESI*0x4 + 0xc74]
    s.dx = m.r32((s.bp+(s.si * 0x00000004u)+0x00000c74u));
  }
  L0042a854: { // 0x42a854: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L0042a857: { // 0x42a857: 7f0e JG 0x0042a867
    if(integer::condition("JG",flags)) goto L0042a867;
  }
  L0042a859: { // 0x42a859: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042a85a: { // 0x42a85a: c6453800 MOV byte ptr [EBP + 0x38],0x0
    m.w8((s.bp+0x00000038u), 0x00000000u);
  }
  L0042a85e: { // 0x42a85e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042a85f: { // 0x42a85f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042a860: { // 0x42a860: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042a861: { // 0x42a861: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0042a864: { // 0x42a864: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0042a867: { // 0x42a867: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042a869: { // 0x42a869: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0042a86b: { // 0x42a86b: 7e38 JLE 0x0042a8a5
    if(integer::condition("JLE",flags)) goto L0042a8a5;
  }
  L0042a86d: { // 0x42a86d: 8d0cb6 LEA ECX,[ESI + ESI*0x4]
    s.cx = (s.si+(s.si * 0x00000004u));
  }
  L0042a870: { // 0x42a870: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0042a874: { // 0x42a874: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0042a877: { // 0x42a877: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0042a87a: { // 0x42a87a: 8d8ccdbc000000 LEA ECX,[EBP + ECX*0x8 + 0xbc]
    s.cx = (s.bp+(s.cx * 0x00000008u)+0x000000bcu);
  }
  L0042a881: { // 0x42a881: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0042a883: { // 0x42a883: 668b19 MOV BX,word ptr [ECX]
    s.bx = with_ax(s.bx, m.r16((s.cx)));
  }
  L0042a886: { // 0x42a886: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0042a888: { // 0x42a888: 7416 JZ 0x0042a8a0
    if(integer::condition("JZ",flags)) goto L0042a8a0;
  }
  L0042a88a: { // 0x42a88a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0042a88b: { // 0x42a88b: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L0042a88e: { // 0x42a88e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0042a890: { // 0x42a890: 7cef JL 0x0042a881
    if(integer::condition("JL",flags)) goto L0042a881;
  }
  L0042a892: { // 0x42a892: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042a893: { // 0x42a893: c6453800 MOV byte ptr [EBP + 0x38],0x0
    m.w8((s.bp+0x00000038u), 0x00000000u);
  }
  L0042a897: { // 0x42a897: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042a898: { // 0x42a898: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042a899: { // 0x42a899: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042a89a: { // 0x42a89a: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0042a89d: { // 0x42a89d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0042a8a0: { // 0x42a8a0: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0042a8a3: { // 0x42a8a3: 750e JNZ 0x0042a8b3
    if(integer::condition("JNZ",flags)) goto L0042a8b3;
  }
  L0042a8a5: { // 0x42a8a5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042a8a6: { // 0x42a8a6: c6453800 MOV byte ptr [EBP + 0x38],0x0
    m.w8((s.bp+0x00000038u), 0x00000000u);
  }
  L0042a8aa: { // 0x42a8aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042a8ab: { // 0x42a8ab: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042a8ac: { // 0x42a8ac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042a8ad: { // 0x42a8ad: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0042a8b0: { // 0x42a8b0: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0042a8b3: { // 0x42a8b3: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0042a8b4: { // 0x42a8b4: 8d0cb6 LEA ECX,[ESI + ESI*0x4]
    s.cx = (s.si+(s.si * 0x00000004u));
  }
  L0042a8b7: { // 0x42a8b7: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0042a8b9: { // 0x42a8b9: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0042a8bc: { // 0x42a8bc: 751d JNZ 0x0042a8db
    if(integer::condition("JNZ",flags)) goto L0042a8db;
  }
  L0042a8be: { // 0x42a8be: 8d1489 LEA EDX,[ECX + ECX*0x4]
    s.dx = (s.cx+(s.cx * 0x00000004u));
  }
  L0042a8c1: { // 0x42a8c1: 8d0490 LEA EAX,[EAX + EDX*0x4]
    s.ax = (s.ax+(s.dx * 0x00000004u));
  }
  L0042a8c4: { // 0x42a8c4: 668bbc45bc000000 MOV DI,word ptr [EBP + EAX*0x2 + 0xbc]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bp+(s.ax * 0x00000002u)+0x000000bcu))) & 0xffffu);
  }
  L0042a8cc: { // 0x42a8cc: 668b8445ba000000 MOV AX,word ptr [EBP + EAX*0x2 + 0xba]
    s.ax = with_ax(s.ax, m.r16((s.bp+(s.ax * 0x00000002u)+0x000000bau)));
  }
  L0042a8d4: { // 0x42a8d4: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L0042a8d9: { // 0x42a8d9: eb1b JMP 0x0042a8f6
    goto L0042a8f6;
  }
  L0042a8db: { // 0x42a8db: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L0042a8de: { // 0x42a8de: 8d0488 LEA EAX,[EAX + ECX*0x4]
    s.ax = (s.ax+(s.cx * 0x00000004u));
  }
  L0042a8e1: { // 0x42a8e1: 668b9445bc000000 MOV DX,word ptr [EBP + EAX*0x2 + 0xbc]
    s.dx = with_ax(s.dx, m.r16((s.bp+(s.ax * 0x00000002u)+0x000000bcu)));
  }
  L0042a8e9: { // 0x42a8e9: 668bbc45be000000 MOV DI,word ptr [EBP + EAX*0x2 + 0xbe]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bp+(s.ax * 0x00000002u)+0x000000beu))) & 0xffffu);
  }
  L0042a8f1: { // 0x42a8f1: 668954242c MOV word ptr [ESP + 0x2c],DX
    m.w16((f.sp+0x0000002cu), (s.dx & 0xffffu));
  }
  L0042a8f6: { // 0x42a8f6: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0042a8fa: { // 0x42a8fa: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L0042a900: { // 0x42a900: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L0042a906: { // 0x42a906: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0042a908: { // 0x42a908: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0042a90a: { // 0x42a90a: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0042a90e: { // 0x42a90e: 7422 JZ 0x0042a932
    if(integer::condition("JZ",flags)) goto L0042a932;
  }
  L0042a910: { // 0x42a910: 7306 JNC 0x0042a918
    if(integer::condition("JNC",flags)) goto L0042a918;
  }
  L0042a912: { // 0x42a912: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0042a914: { // 0x42a914: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042a916: { // 0x42a916: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0042a918: { // 0x42a918: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0042a91b: { // 0x42a91b: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  L0042a91d: { // 0x42a91d: 8d0c76 LEA ECX,[ESI + ESI*0x2]
    s.cx = (s.si+(s.si * 0x00000002u));
  }
  L0042a920: { // 0x42a920: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0042a924: { // 0x42a924: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0042a928: { // 0x42a928: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042a929: { // 0x42a929: 8d4ccd74 LEA ECX,[EBP + ECX*0x8 + 0x74]
    s.cx = (s.bp+(s.cx * 0x00000008u)+0x00000074u);
  }
  L0042a92d: { // 0x42a92d: e8be070000 CALL 0x0042b0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042b0f0u,4368690u); flags=s.arithmetic_flags;
  }
  L0042a932: { // 0x42a932: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0042a936: { // 0x42a936: 8d1c76 LEA EBX,[ESI + ESI*0x2]
    s.bx = (s.si+(s.si * 0x00000002u));
  }
  L0042a939: { // 0x42a939: c1e303 SHL EBX,0x3
    s.bx = integer::shift(s.bx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0042a93c: { // 0x42a93c: 8d14ff LEA EDX,[EDI + EDI*0x8]
    s.dx = (s.di+(s.di * 0x00000008u));
  }
  L0042a93f: { // 0x42a93f: 8d0cc9 LEA ECX,[ECX + ECX*0x8]
    s.cx = (s.cx+(s.cx * 0x00000008u));
  }
  L0042a942: { // 0x42a942: 8b83aca88100 MOV EAX,dword ptr [EBX + 0x81a8ac]
    s.ax = m.r32((s.bx+0x0081a8acu));
  }
  L0042a948: { // 0x42a948: 8d1490 LEA EDX,[EAX + EDX*0x4]
    s.dx = (s.ax+(s.dx * 0x00000004u));
  }
  L0042a94b: { // 0x42a94b: 8d0488 LEA EAX,[EAX + ECX*0x4]
    s.ax = (s.ax+(s.cx * 0x00000004u));
  }
  L0042a94e: { // 0x42a94e: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0042a952: { // 0x42a952: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0042a956: { // 0x42a956: 8b4a10 MOV ECX,dword ptr [EDX + 0x10]
    s.cx = m.r32((s.dx+0x00000010u));
  }
  L0042a959: { // 0x42a959: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0042a95a: { // 0x42a95a: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0042a95e: { // 0x42a95e: 0f88b9000000 JS 0x0042aa1d
    if(integer::condition("JS",flags)) goto L0042aa1d;
  }
  L0042a964: { // 0x42a964: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0042a967: { // 0x42a967: 668b04c8 MOV AX,word ptr [EAX + ECX*0x8]
    s.ax = with_ax(s.ax, m.r16((s.ax+(s.cx * 0x00000008u))));
  }
  L0042a96b: { // 0x42a96b: 663b44242c CMP AX,word ptr [ESP + 0x2c]
    (void)integer::sub((s.ax & 0xffffu),m.r16((f.sp+0x0000002cu)),16,flags);
  }
  L0042a970: { // 0x42a970: 0f849c000000 JZ 0x0042aa12
    if(integer::condition("JZ",flags)) goto L0042aa12;
  }
  L0042a976: { // 0x42a976: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0042a97a: { // 0x42a97a: 8b7610 MOV ESI,dword ptr [ESI + 0x10]
    s.si = m.r32((s.si+0x00000010u));
  }
  L0042a97d: { // 0x42a97d: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0042a97e: { // 0x42a97e: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0042a982: { // 0x42a982: 0f888a000000 JS 0x0042aa12
    if(integer::condition("JS",flags)) goto L0042aa12;
  }
  L0042a988: { // 0x42a988: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L0042a98d: { // 0x42a98d: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0042a991: { // 0x42a991: eb04 JMP 0x0042a997
    goto L0042a997;
  }
  L0042a993: { // 0x42a993: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0042a997: { // 0x42a997: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0042a99b: { // 0x42a99b: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0042a99e: { // 0x42a99e: 3904f2 CMP dword ptr [EDX + ESI*0x8],EAX
    (void)integer::sub(m.r32((s.dx+(s.si * 0x00000008u))),s.ax,32,flags);
  }
  L0042a9a1: { // 0x42a9a1: 755c JNZ 0x0042a9ff
    if(integer::condition("JNZ",flags)) goto L0042a9ff;
  }
  L0042a9a3: { // 0x42a9a3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042a9a5: { // 0x42a9a5: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042a9a9: { // 0x42a9a9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0042a9ab: { // 0x42a9ab: 7452 JZ 0x0042a9ff
    if(integer::condition("JZ",flags)) goto L0042a9ff;
  }
  L0042a9ad: { // 0x42a9ad: 7306 JNC 0x0042a9b5
    if(integer::condition("JNC",flags)) goto L0042a9b5;
  }
  L0042a9af: { // 0x42a9af: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0042a9b1: { // 0x42a9b1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042a9b3: { // 0x42a9b3: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0042a9b5: { // 0x42a9b5: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0042a9b8: { // 0x42a9b8: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  L0042a9ba: { // 0x42a9ba: 8b8c2b84000000 MOV ECX,dword ptr [EBX + EBP*0x1 + 0x84]
    s.cx = m.r32((s.bx+(s.bp * 0x00000001u)+0x00000084u));
  }
  L0042a9c1: { // 0x42a9c1: 8d742b74 LEA ESI,[EBX + EBP*0x1 + 0x74]
    s.si = (s.bx+(s.bp * 0x00000001u)+0x00000074u);
  }
  L0042a9c5: { // 0x42a9c5: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0042a9c7: { // 0x42a9c7: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0042a9ca: { // 0x42a9ca: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0042a9cc: { // 0x42a9cc: 7c22 JL 0x0042a9f0
    if(integer::condition("JL",flags)) goto L0042a9f0;
  }
  L0042a9ce: { // 0x42a9ce: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  L0042a9d1: { // 0x42a9d1: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042a9d3: { // 0x42a9d3: 7504 JNZ 0x0042a9d9
    if(integer::condition("JNZ",flags)) goto L0042a9d9;
  }
  L0042a9d5: { // 0x42a9d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042a9d7: { // 0x42a9d7: 7526 JNZ 0x0042a9ff
    if(integer::condition("JNZ",flags)) goto L0042a9ff;
  }
  L0042a9d9: { // 0x42a9d9: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L0042a9dc: { // 0x42a9dc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0042a9de: { // 0x42a9de: 7e1f JLE 0x0042a9ff
    if(integer::condition("JLE",flags)) goto L0042a9ff;
  }
  L0042a9e0: { // 0x42a9e0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0042a9e2: { // 0x42a9e2: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0042a9e4: { // 0x42a9e4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042a9e6: { // 0x42a9e6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0042a9e7: { // 0x42a9e7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042a9e9: { // 0x42a9e9: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4368876u); flags=s.arithmetic_flags;
  }
  L0042a9ec: { // 0x42a9ec: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042a9ee: { // 0x42a9ee: 740f JZ 0x0042a9ff
    if(integer::condition("JZ",flags)) goto L0042a9ff;
  }
  L0042a9f0: { // 0x42a9f0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0042a9f3: { // 0x42a9f3: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0042a9f6: { // 0x42a9f6: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L0042a9f9: { // 0x42a9f9: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L0042a9fc: { // 0x42a9fc: 893c82 MOV dword ptr [EDX + EAX*0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000004u)), s.di);
  }
  L0042a9ff: { // 0x42a9ff: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0042aa03: { // 0x42aa03: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0042aa04: { // 0x42aa04: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0042aa08: { // 0x42aa08: 7989 JNS 0x0042a993
    if(integer::condition("JNS",flags)) goto L0042a993;
  }
  L0042aa0a: { // 0x42aa0a: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0042aa0e: { // 0x42aa0e: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0042aa12: { // 0x42aa12: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0042aa13: { // 0x42aa13: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0042aa17: { // 0x42aa17: 0f8947ffffff JNS 0x0042a964
    if(integer::condition("JNS",flags)) goto L0042a964;
  }
  L0042aa1d: { // 0x42aa1d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042aa1e: { // 0x42aa1e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042aa1f: { // 0x42aa1f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042aa20: { // 0x42aa20: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042aa21: { // 0x42aa21: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0042aa24: { // 0x42aa24: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00495f00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 std::array<std::uint8_t,16> table0{{236,118,0,144,64,236,118,0,108,236,118,0,144,236,118,0}};leaf::Memory tablemem0(table0.data(),7793712u,16u);m.add(tablemem0);
 std::array<std::uint8_t,32> table1{{15,237,118,0,252,236,118,0,244,236,118,0,236,236,118,0,228,236,118,0,220,236,118,0,212,236,118,0,204,236,118,0}};leaf::Memory tablemem1(table1.data(),7793836u,32u);m.add(tablemem1);
 std::array<std::uint8_t,16> table2{{40,237,118,0,48,237,118,0,60,237,118,0,80,237,118,0}};leaf::Memory tablemem2(table2.data(),7793944u,16u);m.add(tablemem2);
 std::array<std::uint8_t,16> table3{{238,118,0,144,200,237,118,0,232,237,118,0,16,238,118,0}};leaf::Memory tablemem3(table3.data(),7794104u,16u);m.add(tablemem3);
 std::array<std::uint8_t,32> table4{{100,238,118,0,108,238,118,0,116,238,118,0,124,238,118,0,132,238,118,0,140,238,118,0,148,238,118,0,167,238,118,0}};leaf::Memory tablemem4(table4.data(),7794244u,32u);m.add(tablemem4);
 std::array<std::uint8_t,16> table5{{192,238,118,0,200,238,118,0,216,238,118,0,236,238,118,0}};leaf::Memory tablemem5(table5.data(),7794352u,16u);m.add(tablemem5);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00495f00: { // 0x495f00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00495f01: { // 0x495f01: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00495f02: { // 0x495f02: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00495f04: { // 0x495f04: 81fef89f8300 CMP ESI,0x839ff8
    (void)integer::sub(s.si,0x00839ff8u,32,flags);
  }
  L00495f0a: { // 0x495f0a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00495f0b: { // 0x495f0b: 7413 JZ 0x00495f20
    if(integer::condition("JZ",flags)) goto L00495f20;
  }
  L00495f0d: { // 0x495f0d: 6800030000 PUSH 0x300
    f.push(m,0x00000300u);
  }
  L00495f12: { // 0x495f12: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00495f13: { // 0x495f13: 68f89f8300 PUSH 0x839ff8
    f.push(m,0x00839ff8u);
  }
  L00495f18: { // 0x495f18: e8b38c2d00 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,4808477u); flags=s.arithmetic_flags;
  }
  L00495f1d: { // 0x495f1d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00495f20: { // 0x495f20: a1fca68300 MOV EAX,[0x0083a6fc]
    s.ax = m.r32((0x0083a6fcu));
  }
  L00495f25: { // 0x495f25: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00495f27: { // 0x495f27: 7479 JZ 0x00495fa2
    if(integer::condition("JZ",flags)) goto L00495fa2;
  }
  L00495f29: { // 0x495f29: 8b3d08a78300 MOV EDI,dword ptr [0x0083a708]
    s.di = m.r32((0x0083a708u));
  }
  L00495f2f: { // 0x495f2f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00495f31: { // 0x495f31: 746f JZ 0x00495fa2
    if(integer::condition("JZ",flags)) goto L00495fa2;
  }
  L00495f33: { // 0x495f33: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00495f34: { // 0x495f34: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00495f36: { // 0x495f36: b9fda28300 MOV ECX,0x83a2fd
    s.cx = 0x0083a2fdu;
  }
  L00495f3b: { // 0x495f3b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00495f3d: { // 0x495f3d: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00495f3f: { // 0x495f3f: 8a10 MOV DL,byte ptr [EAX]
    s.dx = with_al(s.dx, m.r8((s.ax)));
  }
  L00495f41: { // 0x495f41: 8a5801 MOV BL,byte ptr [EAX + 0x1]
    s.bx = with_al(s.bx, m.r8((s.ax+0x00000001u)));
  }
  L00495f44: { // 0x495f44: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00495f45: { // 0x495f45: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00495f49: { // 0x495f49: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00495f4a: { // 0x495f4a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00495f4c: { // 0x495f4c: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L00495f4f: { // 0x495f4f: 8a18 MOV BL,byte ptr [EAX]
    s.bx = with_al(s.bx, m.r8((s.ax)));
  }
  L00495f51: { // 0x495f51: 8851fb MOV byte ptr [ECX + -0x5],DL
    m.w8((s.cx-0x00000005u), (s.dx & 0xffu));
  }
  L00495f54: { // 0x495f54: 8a54240c MOV DL,byte ptr [ESP + 0xc]
    s.dx = with_al(s.dx, m.r8((f.sp+0x0000000cu)));
  }
  L00495f58: { // 0x495f58: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00495f59: { // 0x495f59: 8851fc MOV byte ptr [ECX + -0x4],DL
    m.w8((s.cx-0x00000004u), (s.dx & 0xffu));
  }
  L00495f5c: { // 0x495f5c: 8859fd MOV byte ptr [ECX + -0x3],BL
    m.w8((s.cx-0x00000003u), (s.bx & 0xffu));
  }
  L00495f5f: { // 0x495f5f: 81f9fda68300 CMP ECX,0x83a6fd
    (void)integer::sub(s.cx,0x0083a6fdu,32,flags);
  }
  L00495f65: { // 0x495f65: 7cd4 JL 0x00495f3b
    if(integer::condition("JL",flags)) goto L00495f3b;
  }
  L00495f67: { // 0x495f67: a1f8a28300 MOV EAX,[0x0083a2f8]
    s.ax = m.r32((0x0083a2f8u));
  }
  L00495f6c: { // 0x495f6c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00495f6d: { // 0x495f6d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00495f6f: { // 0x495f6f: 7431 JZ 0x00495fa2
    if(integer::condition("JZ",flags)) goto L00495fa2;
  }
  L00495f71: { // 0x495f71: 8a0d04a78300 MOV CL,byte ptr [0x0083a704]
    s.cx = with_al(s.cx, m.r8((0x0083a704u)));
  }
  L00495f77: { // 0x495f77: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00495f79: { // 0x495f79: 7513 JNZ 0x00495f8e
    if(integer::condition("JNZ",flags)) goto L00495f8e;
  }
  L00495f7b: { // 0x495f7b: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00495f7d: { // 0x495f7d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00495f7e: { // 0x495f7e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00495f7f: { // 0x495f7f: ff517c CALL dword ptr [ECX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000007cu)),4808578u); flags=s.arithmetic_flags;
  }
  L00495f82: { // 0x495f82: a1f8a28300 MOV EAX,[0x0083a2f8]
    s.ax = m.r32((0x0083a2f8u));
  }
  L00495f87: { // 0x495f87: c60504a7830001 MOV byte ptr [0x0083a704],0x1
    m.w8((0x0083a704u), 0x00000001u);
  }
  L00495f8e: { // 0x495f8e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00495f90: { // 0x495f90: 68fca28300 PUSH 0x83a2fc
    f.push(m,0x0083a2fcu);
  }
  L00495f95: { // 0x495f95: 6800010000 PUSH 0x100
    f.push(m,0x00000100u);
  }
  L00495f9a: { // 0x495f9a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00495f9c: { // 0x495f9c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00495f9e: { // 0x495f9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00495f9f: { // 0x495f9f: ff5218 CALL dword ptr [EDX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000018u)),4808610u); flags=s.arithmetic_flags;
  }
  L00495fa2: { // 0x495fa2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00495fa3: { // 0x495fa3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00495fa4: { // 0x495fa4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00495fa5: { // 0x495fa5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00533420(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00533420: { // 0x533420: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00533421: { // 0x533421: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00533422: { // 0x533422: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00533424: { // 0x533424: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00533425: { // 0x533425: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00533427: { // 0x533427: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0053342a: { // 0x53342a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0053342c: { // 0x53342c: 0f8ea0000000 JLE 0x005334d2
    if(integer::condition("JLE",flags)) goto L005334d2;
  }
  L00533432: { // 0x533432: 837e0c01 CMP dword ptr [ESI + 0xc],0x1
    (void)integer::sub(m.r32((s.si+0x0000000cu)),0x00000001u,32,flags);
  }
  L00533436: { // 0x533436: 755d JNZ 0x00533495
    if(integer::condition("JNZ",flags)) goto L00533495;
  }
  L00533438: { // 0x533438: 66817e24ffff CMP word ptr [ESI + 0x24],0xffff
    (void)integer::sub(m.r16((s.si+0x00000024u)),0x0000ffffu,16,flags);
  }
  L0053343e: { // 0x53343e: 8d5e24 LEA EBX,[ESI + 0x24]
    s.bx = (s.si+0x00000024u);
  }
  L00533441: { // 0x533441: 7515 JNZ 0x00533458
    if(integer::condition("JNZ",flags)) goto L00533458;
  }
  L00533443: { // 0x533443: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00533444: { // 0x533444: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00533447: { // 0x533447: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00533448: { // 0x533448: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0053344a: { // 0x53344a: e881320d00 CALL 0x006066d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006066d0u,5452879u); flags=s.arithmetic_flags;
  }
  L0053344f: { // 0x53344f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00533451: { // 0x533451: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  L00533458: { // 0x533458: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0053345b: { // 0x53345b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0053345d: { // 0x53345d: 7e73 JLE 0x005334d2
    if(integer::condition("JLE",flags)) goto L005334d2;
  }
  L0053345f: { // 0x53345f: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00533461: { // 0x533461: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00533462: { // 0x533462: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00533464: { // 0x533464: e867320d00 CALL 0x006066d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006066d0u,5452905u); flags=s.arithmetic_flags;
  }
  L00533469: { // 0x533469: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0053346c: { // 0x53346c: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  L0053346f: { // 0x53346f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00533470: { // 0x533470: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00533471: { // 0x533471: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00533473: { // 0x533473: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00533475: { // 0x533475: e856320d00 CALL 0x006066d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006066d0u,5452922u); flags=s.arithmetic_flags;
  }
  L0053347a: { // 0x53347a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0053347c: { // 0x53347c: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0053347e: { // 0x53347e: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  L00533485: { // 0x533485: 66c703ffff MOV word ptr [EBX],0xffff
    m.w16((s.bx), 0x0000ffffu);
  }
  L0053348a: { // 0x53348a: e861320d00 CALL 0x006066f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006066f0u,5452943u); flags=s.arithmetic_flags;
  }
  L0053348f: { // 0x53348f: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00533491: { // 0x533491: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00533492: { // 0x533492: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00533493: { // 0x533493: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00533494: { // 0x533494: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00533495: { // 0x533495: 8b5618 MOV EDX,dword ptr [ESI + 0x18]
    s.dx = m.r32((s.si+0x00000018u));
  }
  L00533498: { // 0x533498: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L0053349b: { // 0x53349b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0053349c: { // 0x53349c: e8fffaffff CALL 0x00532fa0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00532fa0u,5452961u); flags=s.arithmetic_flags;
  }
  L005334a1: { // 0x5334a1: 668b4e10 MOV CX,word ptr [ESI + 0x10]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000010u)));
  }
  L005334a5: { // 0x5334a5: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005334a7: { // 0x5334a7: 8d4624 LEA EAX,[ESI + 0x24]
    s.ax = (s.si+0x00000024u);
  }
  L005334aa: { // 0x5334aa: 66894e26 MOV word ptr [ESI + 0x26],CX
    m.w16((s.si+0x00000026u), (s.cx & 0xffffu));
  }
  L005334ae: { // 0x5334ae: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L005334b0: { // 0x5334b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005334b1: { // 0x5334b1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005334b3: { // 0x5334b3: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L005334b6: { // 0x5334b6: e815320d00 CALL 0x006066d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006066d0u,5452987u); flags=s.arithmetic_flags;
  }
  L005334bb: { // 0x5334bb: 8b5618 MOV EDX,dword ptr [ESI + 0x18]
    s.dx = m.r32((s.si+0x00000018u));
  }
  L005334be: { // 0x5334be: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005334bf: { // 0x5334bf: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005334c0: { // 0x5334c0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005334c2: { // 0x5334c2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005334c4: { // 0x5334c4: e807320d00 CALL 0x006066d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006066d0u,5453001u); flags=s.arithmetic_flags;
  }
  L005334c9: { // 0x5334c9: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L005334cb: { // 0x5334cb: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  L005334d2: { // 0x5334d2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005334d4: { // 0x5334d4: e817320d00 CALL 0x006066f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006066f0u,5453017u); flags=s.arithmetic_flags;
  }
  L005334d9: { // 0x5334d9: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L005334db: { // 0x5334db: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005334dc: { // 0x5334dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005334dd: { // 0x5334dd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005334de: { // 0x5334de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0053b490(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0053b490: { // 0x53b490: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0053b494: { // 0x53b494: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0053b496: { // 0x53b496: 7508 JNZ 0x0053b4a0
    if(integer::condition("JNZ",flags)) goto L0053b4a0;
  }
  L0053b498: { // 0x53b498: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  L0053b49d: { // 0x53b49d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0053b4a0: { // 0x53b4a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0053b4a1: { // 0x53b4a1: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L0053b4a5: { // 0x53b4a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0053b4a6: { // 0x53b4a6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053b4a7: { // 0x53b4a7: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L0053b4ac: { // 0x53b4ac: bff8aa7900 MOV EDI,0x79aaf8
    s.di = 0x0079aaf8u;
  }
  L0053b4b1: { // 0x53b4b1: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0053b4b3: { // 0x53b4b3: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0053b4b5: { // 0x53b4b5: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0053b4b9: { // 0x53b4b9: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L0053b4bf: { // 0x53b4bf: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0053b4c1: { // 0x53b4c1: 750d JNZ 0x0053b4d0
    if(integer::condition("JNZ",flags)) goto L0053b4d0;
  }
  L0053b4c3: { // 0x53b4c3: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0053b4c5: { // 0x53b4c5: 7405 JZ 0x0053b4cc
    if(integer::condition("JZ",flags)) goto L0053b4cc;
  }
  L0053b4c7: { // 0x53b4c7: 8d4a04 LEA ECX,[EDX + 0x4]
    s.cx = (s.dx+0x00000004u);
  }
  L0053b4ca: { // 0x53b4ca: eb02 JMP 0x0053b4ce
    goto L0053b4ce;
  }
  L0053b4cc: { // 0x53b4cc: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0053b4ce: { // 0x53b4ce: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0053b4d0: { // 0x53b4d0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0053b4d1: { // 0x53b4d1: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L0053b4d6: { // 0x53b4d6: bfe8aa7900 MOV EDI,0x79aae8
    s.di = 0x0079aae8u;
  }
  L0053b4db: { // 0x53b4db: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0053b4dd: { // 0x53b4dd: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0053b4df: { // 0x53b4df: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0053b4e1: { // 0x53b4e1: 7502 JNZ 0x0053b4e5
    if(integer::condition("JNZ",flags)) goto L0053b4e5;
  }
  L0053b4e3: { // 0x53b4e3: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0053b4e5: { // 0x53b4e5: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L0053b4ea: { // 0x53b4ea: bf70087900 MOV EDI,0x790870
    s.di = 0x00790870u;
  }
  L0053b4ef: { // 0x53b4ef: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0053b4f1: { // 0x53b4f1: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0053b4f3: { // 0x53b4f3: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0053b4f5: { // 0x53b4f5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0053b4f6: { // 0x53b4f6: 750d JNZ 0x0053b505
    if(integer::condition("JNZ",flags)) goto L0053b505;
  }
  L0053b4f8: { // 0x53b4f8: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0053b4fa: { // 0x53b4fa: 7405 JZ 0x0053b501
    if(integer::condition("JZ",flags)) goto L0053b501;
  }
  L0053b4fc: { // 0x53b4fc: 8d4a04 LEA ECX,[EDX + 0x4]
    s.cx = (s.dx+0x00000004u);
  }
  L0053b4ff: { // 0x53b4ff: eb02 JMP 0x0053b503
    goto L0053b503;
  }
  L0053b501: { // 0x53b501: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0053b503: { // 0x53b503: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0053b505: { // 0x53b505: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0053b507: { // 0x53b507: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L0053b50c: { // 0x53b50c: bfd8aa7900 MOV EDI,0x79aad8
    s.di = 0x0079aad8u;
  }
  L0053b511: { // 0x53b511: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0053b513: { // 0x53b513: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0053b515: { // 0x53b515: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053b516: { // 0x53b516: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053b517: { // 0x53b517: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0053b518: { // 0x53b518: 7502 JNZ 0x0053b51c
    if(integer::condition("JNZ",flags)) goto L0053b51c;
  }
  L0053b51a: { // 0x53b51a: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0053b51c: { // 0x53b51c: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L0053b51f: { // 0x53b51f: 7508 JNZ 0x0053b529
    if(integer::condition("JNZ",flags)) goto L0053b529;
  }
  L0053b521: { // 0x53b521: b802400080 MOV EAX,0x80004002
    s.ax = 0x80004002u;
  }
  L0053b526: { // 0x53b526: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0053b529: { // 0x53b529: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0053b52b: { // 0x53b52b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0053b52c: { // 0x53b52c: ff5004 CALL dword ptr [EAX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000004u)),5485871u); flags=s.arithmetic_flags;
  }
  L0053b52f: { // 0x53b52f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0053b531: { // 0x53b531: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0054cc50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cc50: { // 0x54cc50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054cc51: { // 0x54cc51: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0054cc55: { // 0x54cc55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cc56: { // 0x54cc56: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cc57: { // 0x54cc57: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cc58: { // 0x54cc58: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0054cc5b: { // 0x54cc5b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054cc5c: { // 0x54cc5c: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0054cc60: { // 0x54cc60: 750a JNZ 0x0054cc6c
    if(integer::condition("JNZ",flags)) goto L0054cc6c;
  }
  L0054cc62: { // 0x54cc62: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cc63: { // 0x54cc63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cc64: { // 0x54cc64: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cc65: { // 0x54cc65: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054cc67: { // 0x54cc67: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cc68: { // 0x54cc68: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cc69: { // 0x54cc69: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0054cc6c: { // 0x54cc6c: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0054cc70: { // 0x54cc70: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054cc72: { // 0x54cc72: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cc73: { // 0x54cc73: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0054cc78: { // 0x54cc78: e8d3a70000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5557373u); flags=s.arithmetic_flags;
  }
  L0054cc7d: { // 0x54cc7d: 0fbf0b MOVSX ECX,word ptr [EBX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0054cc80: { // 0x54cc80: 8b3510a98100 MOV ESI,dword ptr [0x0081a910]
    s.si = m.r32((0x0081a910u));
  }
  L0054cc86: { // 0x54cc86: 88442418 MOV byte ptr [ESP + 0x18],AL
    m.w8((f.sp+0x00000018u), (s.ax & 0xffu));
  }
  L0054cc8a: { // 0x54cc8a: 0fbf4302 MOVSX EAX,word ptr [EBX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0054cc8e: { // 0x54cc8e: 8d1408 LEA EDX,[EAX + ECX*0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u));
  }
  L0054cc91: { // 0x54cc91: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0054cc93: { // 0x54cc93: 7e1e JLE 0x0054ccb3
    if(integer::condition("JLE",flags)) goto L0054ccb3;
  }
  L0054cc95: { // 0x54cc95: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0054cc97: { // 0x54cc97: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0054cc99: { // 0x54cc99: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0054cc9b: { // 0x54cc9b: 7d16 JGE 0x0054ccb3
    if(integer::condition("JGE",flags)) goto L0054ccb3;
  }
  L0054cc9d: { // 0x54cc9d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054cc9f: { // 0x54cc9f: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0054cca1: { // 0x54cca1: 7d10 JGE 0x0054ccb3
    if(integer::condition("JGE",flags)) goto L0054ccb3;
  }
  L0054cca3: { // 0x54cca3: a114a98100 MOV EAX,[0x0081a914]
    s.ax = m.r32((0x0081a914u));
  }
  L0054cca8: { // 0x54cca8: 8d0c46 LEA ECX,[ESI + EAX*0x2]
    s.cx = (s.si+(s.ax * 0x00000002u));
  }
  L0054ccab: { // 0x54ccab: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0054ccad: { // 0x54ccad: 7f04 JG 0x0054ccb3
    if(integer::condition("JG",flags)) goto L0054ccb3;
  }
  L0054ccaf: { // 0x54ccaf: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054ccb1: { // 0x54ccb1: eb02 JMP 0x0054ccb5
    goto L0054ccb5;
  }
  L0054ccb3: { // 0x54ccb3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054ccb5: { // 0x54ccb5: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0054ccb9: { // 0x54ccb9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054ccbb: { // 0x54ccbb: 750e JNZ 0x0054cccb
    if(integer::condition("JNZ",flags)) goto L0054cccb;
  }
  L0054ccbd: { // 0x54ccbd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ccbf: { // 0x54ccbf: 740a JZ 0x0054cccb
    if(integer::condition("JZ",flags)) goto L0054cccb;
  }
  L0054ccc1: { // 0x54ccc1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054ccc2: { // 0x54ccc2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054ccc3: { // 0x54ccc3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054ccc4: { // 0x54ccc4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054ccc6: { // 0x54ccc6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054ccc7: { // 0x54ccc7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054ccc8: { // 0x54ccc8: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0054cccb: { // 0x54cccb: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L0054cccf: { // 0x54cccf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054ccd1: { // 0x54ccd1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054ccd2: { // 0x54ccd2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0054ccd7: { // 0x54ccd7: e874a70000 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5557468u); flags=s.arithmetic_flags;
  }
  L0054ccdc: { // 0x54ccdc: 0fbf16 MOVSX EDX,word ptr [ESI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054ccdf: { // 0x54ccdf: 0fbf4e02 MOVSX ECX,word ptr [ESI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cce3: { // 0x54cce3: 8b3d10a98100 MOV EDI,dword ptr [0x0081a910]
    s.di = m.r32((0x0081a910u));
  }
  L0054cce9: { // 0x54cce9: 8844241c MOV byte ptr [ESP + 0x1c],AL
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L0054cced: { // 0x54cced: 8d2c11 LEA EBP,[ECX + EDX*0x1]
    s.bp = (s.cx+(s.dx * 0x00000001u));
  }
  L0054ccf0: { // 0x54ccf0: 3bef CMP EBP,EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L0054ccf2: { // 0x54ccf2: 7e1f JLE 0x0054cd13
    if(integer::condition("JLE",flags)) goto L0054cd13;
  }
  L0054ccf4: { // 0x54ccf4: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0054ccf6: { // 0x54ccf6: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054ccf8: { // 0x54ccf8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0054ccfa: { // 0x54ccfa: 7d17 JGE 0x0054cd13
    if(integer::condition("JGE",flags)) goto L0054cd13;
  }
  L0054ccfc: { // 0x54ccfc: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0054ccfe: { // 0x54ccfe: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0054cd00: { // 0x54cd00: 7d11 JGE 0x0054cd13
    if(integer::condition("JGE",flags)) goto L0054cd13;
  }
  L0054cd02: { // 0x54cd02: 8b0d14a98100 MOV ECX,dword ptr [0x0081a914]
    s.cx = m.r32((0x0081a914u));
  }
  L0054cd08: { // 0x54cd08: 8d144f LEA EDX,[EDI + ECX*0x2]
    s.dx = (s.di+(s.cx * 0x00000002u));
  }
  L0054cd0b: { // 0x54cd0b: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0054cd0d: { // 0x54cd0d: 7f04 JG 0x0054cd13
    if(integer::condition("JG",flags)) goto L0054cd13;
  }
  L0054cd0f: { // 0x54cd0f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054cd11: { // 0x54cd11: eb02 JMP 0x0054cd15
    goto L0054cd15;
  }
  L0054cd13: { // 0x54cd13: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054cd15: { // 0x54cd15: 8a4c242c MOV CL,byte ptr [ESP + 0x2c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000002cu)));
  }
  L0054cd19: { // 0x54cd19: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054cd1b: { // 0x54cd1b: 741e JZ 0x0054cd3b
    if(integer::condition("JZ",flags)) goto L0054cd3b;
  }
  L0054cd1d: { // 0x54cd1d: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  L0054cd21: { // 0x54cd21: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054cd23: { // 0x54cd23: 7416 JZ 0x0054cd3b
    if(integer::condition("JZ",flags)) goto L0054cd3b;
  }
  L0054cd25: { // 0x54cd25: 8a4c241c MOV CL,byte ptr [ESP + 0x1c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000001cu)));
  }
  L0054cd29: { // 0x54cd29: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0054cd2b: { // 0x54cd2b: 750e JNZ 0x0054cd3b
    if(integer::condition("JNZ",flags)) goto L0054cd3b;
  }
  L0054cd2d: { // 0x54cd2d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cd2f: { // 0x54cd2f: 740a JZ 0x0054cd3b
    if(integer::condition("JZ",flags)) goto L0054cd3b;
  }
  L0054cd31: { // 0x54cd31: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cd32: { // 0x54cd32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cd33: { // 0x54cd33: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cd34: { // 0x54cd34: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054cd36: { // 0x54cd36: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cd37: { // 0x54cd37: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cd38: { // 0x54cd38: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0054cd3b: { // 0x54cd3b: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054cd3f: { // 0x54cd3f: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0054cd43: { // 0x54cd43: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0054cd47: { // 0x54cd47: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054cd48: { // 0x54cd48: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cd49: { // 0x54cd49: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cd4a: { // 0x54cd4a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054cd4c: { // 0x54cd4c: e82f000000 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,5557585u); flags=s.arithmetic_flags;
  }
  L0054cd51: { // 0x54cd51: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0054cd55: { // 0x54cd55: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0054cd57: { // 0x54cd57: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054cd58: { // 0x54cd58: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cd59: { // 0x54cd59: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cd5a: { // 0x54cd5a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054cd5c: { // 0x54cd5c: e81f000000 CALL 0x0054cd80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054cd80u,5557601u); flags=s.arithmetic_flags;
  }
  L0054cd61: { // 0x54cd61: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0054cd63: { // 0x54cd63: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0054cd65: { // 0x54cd65: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cd66: { // 0x54cd66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cd67: { // 0x54cd67: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0054cd6a: { // 0x54cd6a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cd6b: { // 0x54cd6b: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L0054cd6d: { // 0x54cd6d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cd6e: { // 0x54cd6e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cd6f: { // 0x54cd6f: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005654a0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005654a0: { // 0x5654a0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L005654a3: { // 0x5654a3: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L005654a7: { // 0x5654a7: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L005654ac: { // 0x5654ac: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005654b0: { // 0x5654b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005654b1: { // 0x5654b1: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L005654b5: { // 0x5654b5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005654b6: { // 0x5654b6: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005654b8: { // 0x5654b8: 8b2b MOV EBP,dword ptr [EBX]
    s.bp = m.r32((s.bx));
  }
  L005654ba: { // 0x5654ba: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005654bb: { // 0x5654bb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005654bc: { // 0x5654bc: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005654c0: { // 0x5654c0: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L005654c3: { // 0x5654c3: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L005654c5: { // 0x5654c5: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L005654c7: { // 0x5654c7: 0f8dab000000 JGE 0x00565578
    if(integer::condition("JGE",flags)) goto L00565578;
  }
  L005654cd: { // 0x5654cd: 8b7b04 MOV EDI,dword ptr [EBX + 0x4]
    s.di = m.r32((s.bx+0x00000004u));
  }
  L005654d0: { // 0x5654d0: 8b4b0c MOV ECX,dword ptr [EBX + 0xc]
    s.cx = m.r32((s.bx+0x0000000cu));
  }
  L005654d3: { // 0x5654d3: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L005654d5: { // 0x5654d5: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L005654d7: { // 0x5654d7: 0f8d8b000000 JGE 0x00565568
    if(integer::condition("JGE",flags)) goto L00565568;
  }
  L005654dd: { // 0x5654dd: 66896c2420 MOV word ptr [ESP + 0x20],BP
    m.w16((f.sp+0x00000020u), (s.bp & 0xffffu));
  }
  L005654e2: { // 0x5654e2: 0fbfc7 MOVSX EAX,DI
    s.ax = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L005654e5: { // 0x5654e5: 0fbfcd MOVSX ECX,BP
    s.cx = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L005654e8: { // 0x5654e8: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L005654eb: { // 0x5654eb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005654ed: { // 0x5654ed: 66897c2422 MOV word ptr [ESP + 0x22],DI
    m.w16((f.sp+0x00000022u), (s.di & 0xffffu));
  }
  L005654f2: { // 0x5654f2: 7818 JS 0x0056550c
    if(integer::condition("JS",flags)) goto L0056550c;
  }
  L005654f4: { // 0x5654f4: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L005654f9: { // 0x5654f9: 7d11 JGE 0x0056550c
    if(integer::condition("JGE",flags)) goto L0056550c;
  }
  L005654fb: { // 0x5654fb: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00565501: { // 0x565501: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00565504: { // 0x565504: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00565506: { // 0x565506: 7404 JZ 0x0056550c
    if(integer::condition("JZ",flags)) goto L0056550c;
  }
  L00565508: { // 0x565508: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0056550a: { // 0x56550a: eb0e JMP 0x0056551a
    goto L0056551a;
  }
  L0056550c: { // 0x56550c: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00565510: { // 0x565510: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L00565515: { // 0x565515: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0056551a: { // 0x56551a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0056551c: { // 0x56551c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056551e: { // 0x56551e: e8bdbef0ff CALL 0x004713e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713e0u,5657891u); flags=s.arithmetic_flags;
  }
  L00565523: { // 0x565523: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00565525: { // 0x565525: 7567 JNZ 0x0056558e
    if(integer::condition("JNZ",flags)) goto L0056558e;
  }
  L00565527: { // 0x565527: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0056552b: { // 0x56552b: 8b86dc000000 MOV EAX,dword ptr [ESI + 0xdc]
    s.ax = m.r32((s.si+0x000000dcu));
  }
  L00565531: { // 0x565531: 85c1 TEST ECX,EAX
    (void)integer::logical((s.cx)&(s.ax),32,flags);
  }
  L00565533: { // 0x565533: 7559 JNZ 0x0056558e
    if(integer::condition("JNZ",flags)) goto L0056558e;
  }
  L00565535: { // 0x565535: 837e44ff CMP dword ptr [ESI + 0x44],-0x1
    (void)integer::sub(m.r32((s.si+0x00000044u)),0xffffffffu,32,flags);
  }
  L00565539: { // 0x565539: 7553 JNZ 0x0056558e
    if(integer::condition("JNZ",flags)) goto L0056558e;
  }
  L0056553b: { // 0x56553b: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  L0056553e: { // 0x56553e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00565540: { // 0x565540: 754c JNZ 0x0056558e
    if(integer::condition("JNZ",flags)) goto L0056558e;
  }
  L00565542: { // 0x565542: 8a861c010000 MOV AL,byte ptr [ESI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011cu)));
  }
  L00565548: { // 0x565548: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056554a: { // 0x56554a: 7542 JNZ 0x0056558e
    if(integer::condition("JNZ",flags)) goto L0056558e;
  }
  L0056554c: { // 0x56554c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056554e: { // 0x56554e: e85dbef0ff CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,5657939u); flags=s.arithmetic_flags;
  }
  L00565553: { // 0x565553: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00565555: { // 0x565555: 7537 JNZ 0x0056558e
    if(integer::condition("JNZ",flags)) goto L0056558e;
  }
  L00565557: { // 0x565557: 8b530c MOV EDX,dword ptr [EBX + 0xc]
    s.dx = m.r32((s.bx+0x0000000cu));
  }
  L0056555a: { // 0x56555a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L0056555d: { // 0x56555d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0056555e: { // 0x56555e: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00565560: { // 0x565560: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00565562: { // 0x565562: 0f8c7affffff JL 0x005654e2
    if(integer::condition("JL",flags)) goto L005654e2;
  }
  L00565568: { // 0x565568: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L0056556b: { // 0x56556b: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0056556d: { // 0x56556d: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0056556e: { // 0x56556e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00565570: { // 0x565570: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00565572: { // 0x565572: 0f8c55ffffff JL 0x005654cd
    if(integer::condition("JL",flags)) goto L005654cd;
  }
  L00565578: { // 0x565578: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0056557c: { // 0x56557c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0056557e: { // 0x56557e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056557f: { // 0x56557f: e8fc1dffff CALL 0x00557380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557380u,5657988u); flags=s.arithmetic_flags;
  }
  L00565584: { // 0x565584: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00565585: { // 0x565585: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00565586: { // 0x565586: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00565587: { // 0x565587: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00565588: { // 0x565588: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0056558b: { // 0x56558b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056558e: { // 0x56558e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056558f: { // 0x56558f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00565590: { // 0x565590: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00565591: { // 0x565591: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00565593: { // 0x565593: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00565594: { // 0x565594: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565597: { // 0x565597: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0056b580(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0056b580: { // 0x56b580: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0056b581: { // 0x56b581: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0056b586: { // 0x56b586: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0056b587: { // 0x56b587: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0056b589: { // 0x56b589: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056b58a: { // 0x56b58a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0056b58c: { // 0x56b58c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056b58d: { // 0x56b58d: 742c JZ 0x0056b5bb
    if(integer::condition("JZ",flags)) goto L0056b5bb;
  }
  L0056b58f: { // 0x56b58f: 8b0d4c6b8300 MOV ECX,dword ptr [0x00836b4c]
    s.cx = m.r32((0x00836b4cu));
  }
  L0056b595: { // 0x56b595: 0fafc9 IMUL ECX,ECX
    s.cx = integer::imul(s.cx,s.cx,32,flags);
  }
  L0056b598: { // 0x56b598: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0056b59a: { // 0x56b59a: 7e1f JLE 0x0056b5bb
    if(integer::condition("JLE",flags)) goto L0056b5bb;
  }
  L0056b59c: { // 0x56b59c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056b59e: { // 0x56b59e: 8b353c86a500 MOV ESI,dword ptr [0x00a5863c]
    s.si = m.r32((0x00a5863cu));
  }
  L0056b5a4: { // 0x56b5a4: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L0056b5a7: { // 0x56b5a7: 89543038 MOV dword ptr [EAX + ESI*0x1 + 0x38],EDX
    m.w32((s.ax+(s.si * 0x00000001u)+0x00000038u), s.dx);
  }
  L0056b5ab: { // 0x56b5ab: 8b353c86a500 MOV ESI,dword ptr [0x00a5863c]
    s.si = m.r32((0x00a5863cu));
  }
  L0056b5b1: { // 0x56b5b1: 8954303c MOV dword ptr [EAX + ESI*0x1 + 0x3c],EDX
    m.w32((s.ax+(s.si * 0x00000001u)+0x0000003cu), s.dx);
  }
  L0056b5b5: { // 0x56b5b5: 83c050 ADD EAX,0x50
    s.ax = integer::add(s.ax,0x00000050u,32,flags);
  }
  L0056b5b8: { // 0x56b5b8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0056b5b9: { // 0x56b5b9: 75e3 JNZ 0x0056b59e
    if(integer::condition("JNZ",flags)) goto L0056b59e;
  }
  L0056b5bb: { // 0x56b5bb: a15079a500 MOV EAX,[0x00a57950]
    s.ax = m.r32((0x00a57950u));
  }
  L0056b5c0: { // 0x56b5c0: 8d78ff LEA EDI,[EAX + -0x1]
    s.di = (s.ax-0x00000001u);
  }
  L0056b5c3: { // 0x56b5c3: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0056b5c5: { // 0x56b5c5: 0f8c9d000000 JL 0x0056b668
    if(integer::condition("JL",flags)) goto L0056b668;
  }
  L0056b5cb: { // 0x56b5cb: 8b0d4479a500 MOV ECX,dword ptr [0x00a57944]
    s.cx = m.r32((0x00a57944u));
  }
  L0056b5d1: { // 0x56b5d1: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L0056b5d4: { // 0x56b5d4: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0056b5d6: { // 0x56b5d6: 0f8485000000 JZ 0x0056b661
    if(integer::condition("JZ",flags)) goto L0056b661;
  }
  L0056b5dc: { // 0x56b5dc: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0056b5de: { // 0x56b5de: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0056b5e0: { // 0x56b5e0: 7408 JZ 0x0056b5ea
    if(integer::condition("JZ",flags)) goto L0056b5ea;
  }
  L0056b5e2: { // 0x56b5e2: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0056b5e4: { // 0x56b5e4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0056b5e6: { // 0x56b5e6: ff12 CALL dword ptr [EDX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx)),5682664u); flags=s.arithmetic_flags;
  }
  L0056b5e8: { // 0x56b5e8: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L0056b5ea: { // 0x56b5ea: 8b154079a500 MOV EDX,dword ptr [0x00a57940]
    s.dx = m.r32((0x00a57940u));
  }
  L0056b5f0: { // 0x56b5f0: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L0056b5f4: { // 0x56b5f4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056b5f5: { // 0x56b5f5: b94079a500 MOV ECX,0xa57940
    s.cx = 0x00a57940u;
  }
  L0056b5fa: { // 0x56b5fa: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0056b5fe: { // 0x56b5fe: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),5682689u); flags=s.arithmetic_flags;
  }
  L0056b601: { // 0x56b601: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0056b604: { // 0x56b604: 742d JZ 0x0056b633
    if(integer::condition("JZ",flags)) goto L0056b633;
  }
  L0056b606: { // 0x56b606: 8b0d5079a500 MOV ECX,dword ptr [0x00a57950]
    s.cx = m.r32((0x00a57950u));
  }
  L0056b60c: { // 0x56b60c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056b60e: { // 0x56b60e: 7d23 JGE 0x0056b633
    if(integer::condition("JGE",flags)) goto L0056b633;
  }
  L0056b610: { // 0x56b610: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0056b611: { // 0x56b611: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056b613: { // 0x56b613: 890d5079a500 MOV dword ptr [0x00a57950],ECX
    m.w32((0x00a57950u), s.cx);
  }
  L0056b619: { // 0x56b619: 7d18 JGE 0x0056b633
    if(integer::condition("JGE",flags)) goto L0056b633;
  }
  L0056b61b: { // 0x56b61b: 8b0d4479a500 MOV ECX,dword ptr [0x00a57944]
    s.cx = m.r32((0x00a57944u));
  }
  L0056b621: { // 0x56b621: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0056b622: { // 0x56b622: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0056b625: { // 0x56b625: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0056b629: { // 0x56b629: 8b0d5079a500 MOV ECX,dword ptr [0x00a57950]
    s.cx = m.r32((0x00a57950u));
  }
  L0056b62f: { // 0x56b62f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056b631: { // 0x56b631: 7ce8 JL 0x0056b61b
    if(integer::condition("JL",flags)) goto L0056b61b;
  }
  L0056b633: { // 0x56b633: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L0056b636: { // 0x56b636: c74628e0757800 MOV dword ptr [ESI + 0x28],0x7875e0
    m.w32((s.si+0x00000028u), 0x007875e0u);
  }
  L0056b63d: { // 0x56b63d: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0056b63f: { // 0x56b63f: 7411 JZ 0x0056b652
    if(integer::condition("JZ",flags)) goto L0056b652;
  }
  L0056b641: { // 0x56b641: 385e35 CMP byte ptr [ESI + 0x35],BL
    (void)integer::sub(m.r8((s.si+0x00000035u)),(s.bx & 0xffu),8,flags);
  }
  L0056b644: { // 0x56b644: 740c JZ 0x0056b652
    if(integer::condition("JZ",flags)) goto L0056b652;
  }
  L0056b646: { // 0x56b646: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056b647: { // 0x56b647: e82f202000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5682764u); flags=s.arithmetic_flags;
  }
  L0056b64c: { // 0x56b64c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0056b64f: { // 0x56b64f: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L0056b652: { // 0x56b652: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056b653: { // 0x56b653: 885e35 MOV byte ptr [ESI + 0x35],BL
    m.w8((s.si+0x00000035u), (s.bx & 0xffu));
  }
  L0056b656: { // 0x56b656: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  L0056b659: { // 0x56b659: e81d202000 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5682782u); flags=s.arithmetic_flags;
  }
  L0056b65e: { // 0x56b65e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0056b661: { // 0x56b661: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0056b662: { // 0x56b662: 0f8963ffffff JNS 0x0056b5cb
    if(integer::condition("JNS",flags)) goto L0056b5cb;
  }
  L0056b668: { // 0x56b668: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0056b669: { // 0x56b669: 891d4086a500 MOV dword ptr [0x00a58640],EBX
    m.w32((0x00a58640u), s.bx);
  }
  L0056b66f: { // 0x56b66f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056b670: { // 0x56b670: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0056b671: { // 0x56b671: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0056b672: { // 0x56b672: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0067fbb0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0067fbb0: { // 0x67fbb0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0067fbb3: { // 0x67fbb3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0067fbb4: { // 0x67fbb4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0067fbb6: { // 0x67fbb6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0067fbb7: { // 0x67fbb7: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0067fbb9: { // 0x67fbb9: 397e48 CMP dword ptr [ESI + 0x48],EDI
    (void)integer::sub(m.r32((s.si+0x00000048u)),s.di,32,flags);
  }
  L0067fbbc: { // 0x67fbbc: 7e68 JLE 0x0067fc26
    if(integer::condition("JLE",flags)) goto L0067fc26;
  }
  L0067fbbe: { // 0x67fbbe: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0067fbbf: { // 0x67fbbf: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0067fbc3: { // 0x67fbc3: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L0067fbc6: { // 0x67fbc6: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0067fbc9: { // 0x67fbc9: 83780402 CMP dword ptr [EAX + 0x4],0x2
    (void)integer::sub(m.r32((s.ax+0x00000004u)),0x00000002u,32,flags);
  }
  L0067fbcd: { // 0x67fbcd: 754c JNZ 0x0067fc1b
    if(integer::condition("JNZ",flags)) goto L0067fc1b;
  }
  L0067fbcf: { // 0x67fbcf: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0067fbd1: { // 0x67fbd1: 8b88ac050000 MOV ECX,dword ptr [EAX + 0x5ac]
    s.cx = m.r32((s.ax+0x000005acu));
  }
  L0067fbd7: { // 0x67fbd7: 8a91180b0000 MOV DL,byte ptr [ECX + 0xb18]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000b18u)));
  }
  L0067fbdd: { // 0x67fbdd: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0067fbdf: { // 0x67fbdf: 743a JZ 0x0067fc1b
    if(integer::condition("JZ",flags)) goto L0067fc1b;
  }
  L0067fbe1: { // 0x67fbe1: 8b5668 MOV EDX,dword ptr [ESI + 0x68]
    s.dx = m.r32((s.si+0x00000068u));
  }
  L0067fbe4: { // 0x67fbe4: b95860a500 MOV ECX,0xa56058
    s.cx = 0x00a56058u;
  }
  L0067fbe9: { // 0x67fbe9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0067fbea: { // 0x67fbea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0067fbeb: { // 0x67fbeb: e810fdeaff CALL 0x0052f900
    s.arithmetic_flags=flags; invoke(m,s,f,0x0052f900u,6814704u); flags=s.arithmetic_flags;
  }
  L0067fbf0: { // 0x67fbf0: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L0067fbf5: { // 0x67fbf5: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0067fbfa: { // 0x67fbfa: a35860a500 MOV [0x00a56058],EAX
    m.w32((0x00a56058u), s.ax);
  }
  L0067fbff: { // 0x67fbff: 892d5c60a500 MOV dword ptr [0x00a5605c],EBP
    m.w32((0x00a5605cu), s.bp);
  }
  L0067fc05: { // 0x67fc05: 890d6060a500 MOV dword ptr [0x00a56060],ECX
    m.w32((0x00a56060u), s.cx);
  }
  L0067fc0b: { // 0x67fc0b: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L0067fc0e: { // 0x67fc0e: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0067fc11: { // 0x67fc11: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0067fc13: { // 0x67fc13: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0067fc15: { // 0x67fc15: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0067fc16: { // 0x67fc16: e845000000 CALL 0x0067fc60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0067fc60u,6814747u); flags=s.arithmetic_flags;
  }
  L0067fc1b: { // 0x67fc1b: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L0067fc1e: { // 0x67fc1e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0067fc1f: { // 0x67fc1f: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0067fc21: { // 0x67fc21: 7ca0 JL 0x0067fbc3
    if(integer::condition("JL",flags)) goto L0067fbc3;
  }
  L0067fc23: { // 0x67fc23: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0067fc25: { // 0x67fc25: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0067fc26: { // 0x67fc26: 897e70 MOV dword ptr [ESI + 0x70],EDI
    m.w32((s.si+0x00000070u), s.di);
  }
  L0067fc29: { // 0x67fc29: 897e6c MOV dword ptr [ESI + 0x6c],EDI
    m.w32((s.si+0x0000006cu), s.di);
  }
  L0067fc2c: { // 0x67fc2c: 897e68 MOV dword ptr [ESI + 0x68],EDI
    m.w32((s.si+0x00000068u), s.di);
  }
  L0067fc2f: { // 0x67fc2f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067fc30: { // 0x67fc30: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067fc31: { // 0x67fc31: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0067fc34: { // 0x67fc34: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0069fe80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069fe80: { // 0x69fe80: a0d85faa00 MOV AL,[0x00aa5fd8]
    s.ax = with_al(s.ax, m.r8((0x00aa5fd8u)));
  }
  L0069fe85: { // 0x69fe85: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0069fe88: { // 0x69fe88: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0069fe8d: { // 0x69fe8d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069fe8e: { // 0x69fe8e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069fe8f: { // 0x69fe8f: 84c2 TEST DL,AL
    (void)integer::logical(((s.dx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069fe91: { // 0x69fe91: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069fe92: { // 0x69fe92: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0069fe94: { // 0x69fe94: 0f858a000000 JNZ 0x0069ff24
    if(integer::condition("JNZ",flags)) goto L0069ff24;
  }
  L0069fe9a: { // 0x69fe9a: 0ac2 OR AL,DL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.dx & 0xffu)),8,flags));
  }
  L0069fe9c: { // 0x69fe9c: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0069fe9f: { // 0x69fe9f: a2d85faa00 MOV [0x00aa5fd8],AL
    m.w8((0x00aa5fd8u), (s.ax & 0xffu));
  }
  L0069fea4: { // 0x69fea4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069fea6: { // 0x69fea6: a3e85faa00 MOV [0x00aa5fe8],EAX
    m.w32((0x00aa5fe8u), s.ax);
  }
  L0069feab: { // 0x69feab: 890dec5faa00 MOV dword ptr [0x00aa5fec],ECX
    m.w32((0x00aa5fecu), s.cx);
  }
  L0069feb1: { // 0x69feb1: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0069feb3: { // 0x69feb3: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0069feb6: { // 0x69feb6: a3f05faa00 MOV [0x00aa5ff0],EAX
    m.w32((0x00aa5ff0u), s.ax);
  }
  L0069febb: { // 0x69febb: 890df45faa00 MOV dword ptr [0x00aa5ff4],ECX
    m.w32((0x00aa5ff4u), s.cx);
  }
  L0069fec1: { // 0x69fec1: a3f85faa00 MOV [0x00aa5ff8],EAX
    m.w32((0x00aa5ff8u), s.ax);
  }
  L0069fec6: { // 0x69fec6: a30060aa00 MOV [0x00aa6000],EAX
    m.w32((0x00aa6000u), s.ax);
  }
  L0069fecb: { // 0x69fecb: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0069fecd: { // 0x69fecd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069fecf: { // 0x69fecf: 890dfc5faa00 MOV dword ptr [0x00aa5ffc],ECX
    m.w32((0x00aa5ffcu), s.cx);
  }
  L0069fed5: { // 0x69fed5: a30860aa00 MOV [0x00aa6008],EAX
    m.w32((0x00aa6008u), s.ax);
  }
  L0069feda: { // 0x69feda: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0069fedc: { // 0x69fedc: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0069fedf: { // 0x69fedf: 890d0460aa00 MOV dword ptr [0x00aa6004],ECX
    m.w32((0x00aa6004u), s.cx);
  }
  L0069fee5: { // 0x69fee5: 890d0c60aa00 MOV dword ptr [0x00aa600c],ECX
    m.w32((0x00aa600cu), s.cx);
  }
  L0069feeb: { // 0x69feeb: a31060aa00 MOV [0x00aa6010],EAX
    m.w32((0x00aa6010u), s.ax);
  }
  L0069fef0: { // 0x69fef0: 890d1460aa00 MOV dword ptr [0x00aa6014],ECX
    m.w32((0x00aa6014u), s.cx);
  }
  L0069fef6: { // 0x69fef6: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0069fef9: { // 0x69fef9: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0069fefb: { // 0x69fefb: a31860aa00 MOV [0x00aa6018],EAX
    m.w32((0x00aa6018u), s.ax);
  }
  L0069ff00: { // 0x69ff00: 890d1c60aa00 MOV dword ptr [0x00aa601c],ECX
    m.w32((0x00aa601cu), s.cx);
  }
  L0069ff06: { // 0x69ff06: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0069ff09: { // 0x69ff09: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0069ff0c: { // 0x69ff0c: 68a0ff6900 PUSH 0x69ffa0
    f.push(m,0x0069ffa0u);
  }
  L0069ff11: { // 0x69ff11: a32060aa00 MOV [0x00aa6020],EAX
    m.w32((0x00aa6020u), s.ax);
  }
  L0069ff16: { // 0x69ff16: 890d2460aa00 MOV dword ptr [0x00aa6024],ECX
    m.w32((0x00aa6024u), s.cx);
  }
  L0069ff1c: { // 0x69ff1c: e8a9e30c00 CALL 0x0076e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,6946593u); flags=s.arithmetic_flags;
  }
  L0069ff21: { // 0x69ff21: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0069ff24: { // 0x69ff24: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069ff28: { // 0x69ff28: 8b8b640d0000 MOV ECX,dword ptr [EBX + 0xd64]
    s.cx = m.r32((s.bx+0x00000d64u));
  }
  L0069ff2e: { // 0x69ff2e: 8b93680d0000 MOV EDX,dword ptr [EBX + 0xd68]
    s.dx = m.r32((s.bx+0x00000d68u));
  }
  L0069ff34: { // 0x69ff34: 8b34c5e85faa00 MOV ESI,dword ptr [EAX*0x8 + 0xaa5fe8]
    s.si = m.r32(((s.ax * 0x00000008u)+0x00aa5fe8u));
  }
  L0069ff3b: { // 0x69ff3b: 8b3cc5ec5faa00 MOV EDI,dword ptr [EAX*0x8 + 0xaa5fec]
    s.di = m.r32(((s.ax * 0x00000008u)+0x00aa5fecu));
  }
  L0069ff42: { // 0x69ff42: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0069ff44: { // 0x69ff44: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L0069ff46: { // 0x69ff46: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0069ff48: { // 0x69ff48: 7504 JNZ 0x0069ff4e
    if(integer::condition("JNZ",flags)) goto L0069ff4e;
  }
  L0069ff4a: { // 0x69ff4a: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0069ff4c: { // 0x69ff4c: 7445 JZ 0x0069ff93
    if(integer::condition("JZ",flags)) goto L0069ff93;
  }
  L0069ff4e: { // 0x69ff4e: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L0069ff52: { // 0x69ff52: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0069ff54: { // 0x69ff54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069ff55: { // 0x69ff55: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0069ff59: { // 0x69ff59: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0069ff5d: { // 0x69ff5d: e85ee3ffff CALL 0x0069e2c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069e2c0u,6946658u); flags=s.arithmetic_flags;
  }
  L0069ff62: { // 0x69ff62: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069ff64: { // 0x69ff64: 7411 JZ 0x0069ff77
    if(integer::condition("JZ",flags)) goto L0069ff77;
  }
  L0069ff66: { // 0x69ff66: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L0069ff6b: { // 0x69ff6b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069ff6d: { // 0x69ff6d: 7508 JNZ 0x0069ff77
    if(integer::condition("JNZ",flags)) goto L0069ff77;
  }
  L0069ff6f: { // 0x69ff6f: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L0069ff73: { // 0x69ff73: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0069ff77: { // 0x69ff77: 8b8b640d0000 MOV ECX,dword ptr [EBX + 0xd64]
    s.cx = m.r32((s.bx+0x00000d64u));
  }
  L0069ff7d: { // 0x69ff7d: 8b83680d0000 MOV EAX,dword ptr [EBX + 0xd68]
    s.ax = m.r32((s.bx+0x00000d68u));
  }
  L0069ff83: { // 0x69ff83: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0069ff85: { // 0x69ff85: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L0069ff87: { // 0x69ff87: 8d0c41 LEA ECX,[ECX + EAX*0x2]
    s.cx = (s.cx+(s.ax * 0x00000002u));
  }
  L0069ff8a: { // 0x69ff8a: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0069ff8c: { // 0x69ff8c: 8b0485d0017e00 MOV EAX,dword ptr [EAX*0x4 + 0x7e01d0]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007e01d0u));
  }
  L0069ff93: { // 0x69ff93: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069ff94: { // 0x69ff94: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069ff95: { // 0x69ff95: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069ff96: { // 0x69ff96: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069ff99: { // 0x69ff99: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006a7210(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a7210: { // 0x6a7210: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006a7213: { // 0x6a7213: 8b4144 MOV EAX,dword ptr [ECX + 0x44]
    s.ax = m.r32((s.cx+0x00000044u));
  }
  L006a7216: { // 0x6a7216: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L006a721a: { // 0x6a721a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a721b: { // 0x6a721b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a721c: { // 0x6a721c: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006a7222: { // 0x6a7222: e8092ffbff CALL 0x0065a130
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a130u,6976039u); flags=s.arithmetic_flags;
  }
  L006a7227: { // 0x6a7227: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006a7229: { // 0x6a7229: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006a722b: { // 0x6a722b: 89442400 MOV dword ptr [ESP],EAX
    m.w32((f.sp), s.ax);
  }
  L006a722f: { // 0x6a722f: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006a7233: { // 0x6a7233: 0fbf4c2402 MOVSX ECX,word ptr [ESP + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000002u)),16));
  }
  L006a7238: { // 0x6a7238: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006a723b: { // 0x6a723b: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a723e: { // 0x6a723e: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L006a7241: { // 0x6a7241: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006a7247: { // 0x6a7247: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L006a724b: { // 0x6a724b: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L006a7250: { // 0x6a7250: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006a7254: { // 0x6a7254: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006a7255: { // 0x6a7255: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a725a: { // 0x6a725a: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L006a725e: { // 0x6a725e: e80dfeeaff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6976099u); flags=s.arithmetic_flags;
  }
  L006a7263: { // 0x6a7263: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006a7267: { // 0x6a7267: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L006a726b: { // 0x6a726b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a726c: { // 0x6a726c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a7271: { // 0x6a7271: e88ae2e9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6976118u); flags=s.arithmetic_flags;
  }
  L006a7276: { // 0x6a7276: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006a727c: { // 0x6a727c: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006a727f: { // 0x6a727f: 751a JNZ 0x006a729b
    if(integer::condition("JNZ",flags)) goto L006a729b;
  }
  L006a7281: { // 0x6a7281: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  L006a7285: { // 0x6a7285: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006a7286: { // 0x6a7286: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006a728b: { // 0x6a728b: e870e2e9ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6976144u); flags=s.arithmetic_flags;
  }
  L006a7290: { // 0x6a7290: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L006a7296: { // 0x6a7296: f6c504 TEST CH,0x4
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  L006a7299: { // 0x6a7299: 7410 JZ 0x006a72ab
    if(integer::condition("JZ",flags)) goto L006a72ab;
  }
  L006a729b: { // 0x6a729b: 8b150079aa00 MOV EDX,dword ptr [0x00aa7900]
    s.dx = m.r32((0x00aa7900u));
  }
  L006a72a1: { // 0x6a72a1: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006a72a5: { // 0x6a72a5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a72a7: { // 0x6a72a7: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006a72ab: { // 0x6a72ab: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L006a72b1: { // 0x6a72b1: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L006a72b5: { // 0x6a72b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a72b6: { // 0x6a72b6: e8354affff CALL 0x0069bcf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069bcf0u,6976187u); flags=s.arithmetic_flags;
  }
  L006a72bb: { // 0x6a72bb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006a72bd: { // 0x6a72bd: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006a72c0: { // 0x6a72c0: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006df1e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006df1e0: { // 0x6df1e0: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006df1e5: { // 0x6df1e5: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006df1e8: { // 0x6df1e8: 8a882a220000 MOV CL,byte ptr [EAX + 0x222a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000222au)));
  }
  L006df1ee: { // 0x6df1ee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006df1ef: { // 0x6df1ef: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006df1f1: { // 0x6df1f1: 0f84a0000000 JZ 0x006df297
    if(integer::condition("JZ",flags)) goto L006df297;
  }
  L006df1f7: { // 0x6df1f7: a14886aa00 MOV EAX,[0x00aa8648]
    s.ax = m.r32((0x00aa8648u));
  }
  L006df1fc: { // 0x6df1fc: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006df1fe: { // 0x6df1fe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006df200: { // 0x6df200: 0f8e91000000 JLE 0x006df297
    if(integer::condition("JLE",flags)) goto L006df297;
  }
  L006df206: { // 0x6df206: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006df207: { // 0x6df207: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006df208: { // 0x6df208: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L006df20c: { // 0x6df20c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006df20d: { // 0x6df20d: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L006df213: { // 0x6df213: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L006df216: { // 0x6df216: 8bb91c010000 MOV EDI,dword ptr [ECX + 0x11c]
    s.di = m.r32((s.cx+0x0000011cu));
  }
  L006df21c: { // 0x6df21c: 8b8124010000 MOV EAX,dword ptr [ECX + 0x124]
    s.ax = m.r32((s.cx+0x00000124u));
  }
  L006df222: { // 0x6df222: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L006df225: { // 0x6df225: 740e JZ 0x006df235
    if(integer::condition("JZ",flags)) goto L006df235;
  }
  L006df227: { // 0x6df227: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L006df22d: { // 0x6df22d: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L006df22f: { // 0x6df22f: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006df231: { // 0x6df231: 7d06 JGE 0x006df239
    if(integer::condition("JGE",flags)) goto L006df239;
  }
  L006df233: { // 0x6df233: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006df235: { // 0x6df235: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006df237: { // 0x6df237: 754d JNZ 0x006df286
    if(integer::condition("JNZ",flags)) goto L006df286;
  }
  L006df239: { // 0x6df239: e862020000 CALL 0x006df4a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006df4a0u,7205438u); flags=s.arithmetic_flags;
  }
  L006df23e: { // 0x6df23e: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006df244: { // 0x6df244: f60240 TEST byte ptr [EDX],0x40
    (void)integer::logical((m.r8((s.dx)))&(0x00000040u),8,flags);
  }
  L006df247: { // 0x6df247: 7408 JZ 0x006df251
    if(integer::condition("JZ",flags)) goto L006df251;
  }
  L006df249: { // 0x6df249: dd05508d7800 FLD double ptr [0x00788d50]
    const auto address=(0x00788d50u);
    s.fp.load64(read64(m,address));
  }
  L006df24f: { // 0x6df24f: eb06 JMP 0x006df257
    goto L006df257;
  }
  L006df251: { // 0x6df251: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006df257: { // 0x6df257: 8b1d3c86aa00 MOV EBX,dword ptr [0x00aa863c]
    s.bx = m.r32((0x00aa863cu));
  }
  L006df25d: { // 0x6df25d: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L006df263: { // 0x6df263: 8b04b3 MOV EAX,dword ptr [EBX + ESI*0x4]
    s.ax = m.r32((s.bx+(s.si * 0x00000004u)));
  }
  L006df266: { // 0x6df266: db80a8000000 FILD dword ptr [EAX + 0xa8]
    const auto address=(s.ax+0x000000a8u);
    s.fp.load_integer32(m.r32(address));
  }
  L006df26c: { // 0x6df26c: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L006df26e: { // 0x6df26e: e8ddb70800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7205491u); flags=s.arithmetic_flags;
  }
  L006df273: { // 0x6df273: 8b0cb3 MOV ECX,dword ptr [EBX + ESI*0x4]
    s.cx = m.r32((s.bx+(s.si * 0x00000004u)));
  }
  L006df276: { // 0x6df276: 81c11c010000 ADD ECX,0x11c
    s.cx = integer::add(s.cx,0x0000011cu,32,flags);
  }
  L006df27c: { // 0x6df27c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006df27e: { // 0x6df27e: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L006df280: { // 0x6df280: 896904 MOV dword ptr [ECX + 0x4],EBP
    m.w32((s.cx+0x00000004u), s.bp);
  }
  L006df283: { // 0x6df283: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L006df286: { // 0x6df286: a14886aa00 MOV EAX,[0x00aa8648]
    s.ax = m.r32((0x00aa8648u));
  }
  L006df28b: { // 0x6df28b: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006df28c: { // 0x6df28c: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006df28e: { // 0x6df28e: 0f8c79ffffff JL 0x006df20d
    if(integer::condition("JL",flags)) goto L006df20d;
  }
  L006df294: { // 0x6df294: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006df295: { // 0x6df295: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006df296: { // 0x6df296: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006df297: { // 0x6df297: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006df298: { // 0x6df298: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006df29b: { // 0x6df29b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
