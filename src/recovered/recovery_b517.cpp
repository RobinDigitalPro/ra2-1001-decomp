#include "recovered/recovery_b250_machine.hpp"
#include "recovery_b517.hpp"
#include <array>
namespace ra2::recovered::recovery_b517 {
using namespace recovery_b250;
namespace {
void f_0014d770(Memory&,State&,Frame&,const Operations&);
void f_00157530(Memory&,State&,Frame&,const Operations&);
void f_0014e180(Memory&,State&,Frame&,const Operations&);
void f_00078360(Memory&,State&,Frame&,const Operations&);
void f_0007be00(Memory&,State&,Frame&,const Operations&);
void f_0029c090(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_0014d770(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054d770: { // 0x54d770: 81ec9c010000 SUB ESP,0x19c
    f.sp = integer::sub(f.sp,0x0000019cu,32,flags);
  }
  L0054d776: { // 0x54d776: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d777: { // 0x54d777: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054d778: { // 0x54d778: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054d779: { // 0x54d779: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0054d77b: { // 0x54d77b: 8b8c24b0010000 MOV ECX,dword ptr [ESP + 0x1b0]
    s.cx = m.r32((f.sp+0x000001b0u));
  }
  L0054d782: { // 0x54d782: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054d783: { // 0x54d783: 8bbc24bc010000 MOV EDI,dword ptr [ESP + 0x1bc]
    s.di = m.r32((f.sp+0x000001bcu));
  }
  L0054d78a: { // 0x54d78a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0054d78c: { // 0x54d78c: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0054d78f: { // 0x54d78f: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0054d793: { // 0x54d793: 81ffffff0000 CMP EDI,0xffff
    (void)integer::sub(s.di,0x0000ffffu,32,flags);
  }
  L0054d799: { // 0x54d799: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L0054d79d: { // 0x54d79d: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0054d7a1: { // 0x54d7a1: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0054d7a5: { // 0x54d7a5: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0054d7a9: { // 0x54d7a9: c644241700 MOV byte ptr [ESP + 0x17],0x0
    m.w8((f.sp+0x00000017u), 0x00000000u);
  }
  L0054d7ae: { // 0x54d7ae: 750b JNZ 0x0054d7bb
    if(integer::condition("JNZ",flags)) goto L0054d7bb;
  }
  L0054d7b0: { // 0x54d7b0: c78424bc010000ffffffff MOV dword ptr [ESP + 0x1bc],0xffffffff
    m.w32((f.sp+0x000001bcu), 0xffffffffu);
  }
  L0054d7bb: { // 0x54d7bb: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054d7be: { // 0x54d7be: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054d7c0: { // 0x54d7c0: 7814 JS 0x0054d7d6
    if(integer::condition("JS",flags)) goto L0054d7d6;
  }
  L0054d7c2: { // 0x54d7c2: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054d7c7: { // 0x54d7c7: 7d0d JGE 0x0054d7d6
    if(integer::condition("JGE",flags)) goto L0054d7d6;
  }
  L0054d7c9: { // 0x54d7c9: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054d7cf: { // 0x54d7cf: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054d7d2: { // 0x54d7d2: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0054d7d4: { // 0x54d7d4: 750c JNZ 0x0054d7e2
    if(integer::condition("JNZ",flags)) goto L0054d7e2;
  }
  L0054d7d6: { // 0x54d7d6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0054d7d8: { // 0x54d7d8: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054d7dd: { // 0x54d7dd: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054d7e2: { // 0x54d7e2: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0054d7e9: { // 0x54d7e9: 8b9c24c4010000 MOV EBX,dword ptr [ESP + 0x1c4]
    s.bx = m.r32((f.sp+0x000001c4u));
  }
  L0054d7f0: { // 0x54d7f0: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0054d7f4: { // 0x54d7f4: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0054d7f6: { // 0x54d7f6: 743e JZ 0x0054d836
    if(integer::condition("JZ",flags)) goto L0054d836;
  }
  L0054d7f8: { // 0x54d7f8: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0054d7fc: { // 0x54d7fc: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0054d7ff: { // 0x54d7ff: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054d802: { // 0x54d802: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054d804: { // 0x54d804: 7814 JS 0x0054d81a
    if(integer::condition("JS",flags)) goto L0054d81a;
  }
  L0054d806: { // 0x54d806: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054d80b: { // 0x54d80b: 7d0d JGE 0x0054d81a
    if(integer::condition("JGE",flags)) goto L0054d81a;
  }
  L0054d80d: { // 0x54d80d: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054d813: { // 0x54d813: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054d816: { // 0x54d816: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0054d818: { // 0x54d818: 750c JNZ 0x0054d826
    if(integer::condition("JNZ",flags)) goto L0054d826;
  }
  L0054d81a: { // 0x54d81a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0054d81c: { // 0x54d81c: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054d821: { // 0x54d821: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054d826: { // 0x54d826: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0054d82c: { // 0x54d82c: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054d82f: { // 0x54d82f: 7405 JZ 0x0054d836
    if(integer::condition("JZ",flags)) goto L0054d836;
  }
  L0054d831: { // 0x54d831: 8344243404 ADD dword ptr [ESP + 0x34],0x4
    m.w32((f.sp+0x00000034u), integer::add(m.r32((f.sp+0x00000034u)),0x00000004u,32,flags));
  }
  L0054d836: { // 0x54d836: 8b8ef4000000 MOV ECX,dword ptr [ESI + 0xf4]
    s.cx = m.r32((s.si+0x000000f4u));
  }
  L0054d83c: { // 0x54d83c: 8b96f0000000 MOV EDX,dword ptr [ESI + 0xf0]
    s.dx = m.r32((s.si+0x000000f0u));
  }
  L0054d842: { // 0x54d842: 8d0411 LEA EAX,[ECX + EDX*0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u));
  }
  L0054d845: { // 0x54d845: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  L0054d848: { // 0x54d848: 7e05 JLE 0x0054d84f
    if(integer::condition("JLE",flags)) goto L0054d84f;
  }
  L0054d84a: { // 0x54d84a: b820000000 MOV EAX,0x20
    s.ax = 0x00000020u;
  }
  L0054d84f: { // 0x54d84f: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0054d851: { // 0x54d851: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0054d855: { // 0x54d855: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L0054d859: { // 0x54d859: 0f8eff080000 JLE 0x0054e15e
    if(integer::condition("JLE",flags)) goto L0054e15e;
  }
  L0054d85f: { // 0x54d85f: 896c2438 MOV dword ptr [ESP + 0x38],EBP
    m.w32((f.sp+0x00000038u), s.bp);
  }
  L0054d863: { // 0x54d863: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L0054d867: { // 0x54d867: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054d86b: { // 0x54d86b: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0054d86d: { // 0x54d86d: 0f8f6c030000 JG 0x0054dbdf
    if(integer::condition("JG",flags)) goto L0054dbdf;
  }
  L0054d873: { // 0x54d873: 8dacac8c000000 LEA EBP,[ESP + EBP*0x4 + 0x8c]
    s.bp = (f.sp+(s.bp * 0x00000004u)+0x0000008cu);
  }
  L0054d87a: { // 0x54d87a: 8a8424e4010000 MOV AL,byte ptr [ESP + 0x1e4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001e4u)));
  }
  L0054d881: { // 0x54d881: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d883: { // 0x54d883: 0f858b010000 JNZ 0x0054da14
    if(integer::condition("JNZ",flags)) goto L0054da14;
  }
  L0054d889: { // 0x54d889: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0054d88d: { // 0x54d88d: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0054d891: { // 0x54d891: 8d0c38 LEA ECX,[EAX + EDI*0x1]
    s.cx = (s.ax+(s.di * 0x00000001u));
  }
  L0054d894: { // 0x54d894: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054d898: { // 0x54d898: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d89a: { // 0x54d89a: 66894c2448 MOV word ptr [ESP + 0x48],CX
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L0054d89f: { // 0x54d89f: 668944244a MOV word ptr [ESP + 0x4a],AX
    m.w16((f.sp+0x0000004au), (s.ax & 0xffffu));
  }
  L0054d8a4: { // 0x54d8a4: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L0054d8a8: { // 0x54d8a8: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054d8ab: { // 0x54d8ab: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054d8ae: { // 0x54d8ae: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054d8b1: { // 0x54d8b1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054d8b3: { // 0x54d8b3: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0054d8b7: { // 0x54d8b7: 7818 JS 0x0054d8d1
    if(integer::condition("JS",flags)) goto L0054d8d1;
  }
  L0054d8b9: { // 0x54d8b9: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054d8be: { // 0x54d8be: 7d11 JGE 0x0054d8d1
    if(integer::condition("JGE",flags)) goto L0054d8d1;
  }
  L0054d8c0: { // 0x54d8c0: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0054d8c6: { // 0x54d8c6: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0054d8c9: { // 0x54d8c9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054d8cb: { // 0x54d8cb: 7404 JZ 0x0054d8d1
    if(integer::condition("JZ",flags)) goto L0054d8d1;
  }
  L0054d8cd: { // 0x54d8cd: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0054d8cf: { // 0x54d8cf: eb0b JMP 0x0054d8dc
    goto L0054d8dc;
  }
  L0054d8d1: { // 0x54d8d1: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0054d8d7: { // 0x54d8d7: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L0054d8dc: { // 0x54d8dc: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0054d8e0: { // 0x54d8e0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054d8e2: { // 0x54d8e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054d8e3: { // 0x54d8e3: e8489c0000 CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,5560552u); flags=s.arithmetic_flags;
  }
  L0054d8e8: { // 0x54d8e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d8ea: { // 0x54d8ea: 0f8424010000 JZ 0x0054da14
    if(integer::condition("JZ",flags)) goto L0054da14;
  }
  L0054d8f0: { // 0x54d8f0: 8b9424d0010000 MOV EDX,dword ptr [ESP + 0x1d0]
    s.dx = m.r32((f.sp+0x000001d0u));
  }
  L0054d8f7: { // 0x54d8f7: 8b8424c0010000 MOV EAX,dword ptr [ESP + 0x1c0]
    s.ax = m.r32((f.sp+0x000001c0u));
  }
  L0054d8fe: { // 0x54d8fe: 8b8c24bc010000 MOV ECX,dword ptr [ESP + 0x1bc]
    s.cx = m.r32((f.sp+0x000001bcu));
  }
  L0054d905: { // 0x54d905: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054d906: { // 0x54d906: 8b9424bc010000 MOV EDX,dword ptr [ESP + 0x1bc]
    s.dx = m.r32((f.sp+0x000001bcu));
  }
  L0054d90d: { // 0x54d90d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054d90e: { // 0x54d90e: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0054d910: { // 0x54d910: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054d911: { // 0x54d911: 8b8424dc010000 MOV EAX,dword ptr [ESP + 0x1dc]
    s.ax = m.r32((f.sp+0x000001dcu));
  }
  L0054d918: { // 0x54d918: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054d919: { // 0x54d919: 8b8c24dc010000 MOV ECX,dword ptr [ESP + 0x1dc]
    s.cx = m.r32((f.sp+0x000001dcu));
  }
  L0054d920: { // 0x54d920: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054d921: { // 0x54d921: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054d922: { // 0x54d922: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0054d926: { // 0x54d926: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054d927: { // 0x54d927: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0054d92b: { // 0x54d92b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054d92c: { // 0x54d92c: e84f080000 CALL 0x0054e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054e180u,5560625u); flags=s.arithmetic_flags;
  }
  L0054d931: { // 0x54d931: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d933: { // 0x54d933: 0f84db000000 JZ 0x0054da14
    if(integer::condition("JZ",flags)) goto L0054da14;
  }
  L0054d939: { // 0x54d939: 8a8424d4010000 MOV AL,byte ptr [ESP + 0x1d4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d4u)));
  }
  L0054d940: { // 0x54d940: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d942: { // 0x54d942: 742e JZ 0x0054d972
    if(integer::condition("JZ",flags)) goto L0054d972;
  }
  L0054d944: { // 0x54d944: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054d94a: { // 0x54d94a: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0054d951: { // 0x54d951: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L0054d954: { // 0x54d954: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  L0054d957: { // 0x54d957: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0054d95a: { // 0x54d95a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054d95c: { // 0x54d95c: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0054d960: { // 0x54d960: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054d962: { // 0x54d962: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d964: { // 0x54d964: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054d965: { // 0x54d965: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054d967: { // 0x54d967: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054d969: { // 0x54d969: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0054d96c: { // 0x54d96c: 0f8da2000000 JGE 0x0054da14
    if(integer::condition("JGE",flags)) goto L0054da14;
  }
  L0054d972: { // 0x54d972: 8a8424d8010000 MOV AL,byte ptr [ESP + 0x1d8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d8u)));
  }
  L0054d979: { // 0x54d979: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d97b: { // 0x54d97b: 740f JZ 0x0054d98c
    if(integer::condition("JZ",flags)) goto L0054d98c;
  }
  L0054d97d: { // 0x54d97d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054d97f: { // 0x54d97f: e87ce4f2ff CALL 0x0047be00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047be00u,5560708u); flags=s.arithmetic_flags;
  }
  L0054d984: { // 0x54d984: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d986: { // 0x54d986: 0f8488000000 JZ 0x0054da14
    if(integer::condition("JZ",flags)) goto L0054da14;
  }
  L0054d98c: { // 0x54d98c: 8a8424dc010000 MOV AL,byte ptr [ESP + 0x1dc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001dcu)));
  }
  L0054d993: { // 0x54d993: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054d995: { // 0x54d995: 750b JNZ 0x0054d9a2
    if(integer::condition("JNZ",flags)) goto L0054d9a2;
  }
  L0054d997: { // 0x54d997: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054d99d: { // 0x54d99d: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054d9a0: { // 0x54d9a0: 7572 JNZ 0x0054da14
    if(integer::condition("JNZ",flags)) goto L0054da14;
  }
  L0054d9a2: { // 0x54d9a2: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0054d9a6: { // 0x54d9a6: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0054d9aa: { // 0x54d9aa: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  L0054d9ad: { // 0x54d9ad: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0054d9ae: { // 0x54d9ae: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0054d9b1: { // 0x54d9b1: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0054d9b5: { // 0x54d9b5: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0054d9b7: { // 0x54d9b7: 7556 JNZ 0x0054da0f
    if(integer::condition("JNZ",flags)) goto L0054da0f;
  }
  L0054d9b9: { // 0x54d9b9: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0054d9be: { // 0x54d9be: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054d9c1: { // 0x54d9c1: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054d9c4: { // 0x54d9c4: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0054d9c9: { // 0x54d9c9: 8d54245c LEA EDX,[ESP + 0x5c]
    s.dx = (f.sp+0x0000005cu);
  }
  L0054d9cd: { // 0x54d9cd: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054d9d0: { // 0x54d9d0: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0054d9d4: { // 0x54d9d4: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0054d9da: { // 0x54d9da: 8d842480000000 LEA EAX,[ESP + 0x80]
    s.ax = (f.sp+0x00000080u);
  }
  L0054d9e1: { // 0x54d9e1: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0054d9e5: { // 0x54d9e5: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0054d9eb: { // 0x54d9eb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054d9ec: { // 0x54d9ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054d9ed: { // 0x54d9ed: c744246c00000000 MOV dword ptr [ESP + 0x6c],0x0
    m.w32((f.sp+0x0000006cu), 0x00000000u);
  }
  L0054d9f5: { // 0x54d9f5: e896e61400 CALL 0x0069c090
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c090u,5560826u); flags=s.arithmetic_flags;
  }
  L0054d9fa: { // 0x54d9fa: 668b4c2410 MOV CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000010u)));
  }
  L0054d9ff: { // 0x54d9ff: 663b08 CMP CX,word ptr [EAX]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.ax)),16,flags);
  }
  L0054da02: { // 0x54da02: 7510 JNZ 0x0054da14
    if(integer::condition("JNZ",flags)) goto L0054da14;
  }
  L0054da04: { // 0x54da04: 668b542412 MOV DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000012u)));
  }
  L0054da09: { // 0x54da09: 663b5002 CMP DX,word ptr [EAX + 0x2]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.ax+0x00000002u)),16,flags);
  }
  L0054da0d: { // 0x54da0d: 7505 JNZ 0x0054da14
    if(integer::condition("JNZ",flags)) goto L0054da14;
  }
  L0054da0f: { // 0x54da0f: c644241701 MOV byte ptr [ESP + 0x17],0x1
    m.w8((f.sp+0x00000017u), 0x00000001u);
  }
  L0054da14: { // 0x54da14: 837c241818 CMP dword ptr [ESP + 0x18],0x18
    (void)integer::sub(m.r32((f.sp+0x00000018u)),0x00000018u,32,flags);
  }
  L0054da19: { // 0x54da19: 0f8454050000 JZ 0x0054df73
    if(integer::condition("JZ",flags)) goto L0054df73;
  }
  L0054da1f: { // 0x54da1f: 8a8424e4010000 MOV AL,byte ptr [ESP + 0x1e4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001e4u)));
  }
  L0054da26: { // 0x54da26: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054da28: { // 0x54da28: 740a JZ 0x0054da34
    if(integer::condition("JZ",flags)) goto L0054da34;
  }
  L0054da2a: { // 0x54da2a: 3b7c2438 CMP EDI,dword ptr [ESP + 0x38]
    (void)integer::sub(s.di,m.r32((f.sp+0x00000038u)),32,flags);
  }
  L0054da2e: { // 0x54da2e: 0f8e8b010000 JLE 0x0054dbbf
    if(integer::condition("JLE",flags)) goto L0054dbbf;
  }
  L0054da34: { // 0x54da34: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0054da38: { // 0x54da38: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0054da3c: { // 0x54da3c: 8d0c38 LEA ECX,[EAX + EDI*0x1]
    s.cx = (s.ax+(s.di * 0x00000001u));
  }
  L0054da3f: { // 0x54da3f: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054da43: { // 0x54da43: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054da45: { // 0x54da45: 66894c244c MOV word ptr [ESP + 0x4c],CX
    m.w16((f.sp+0x0000004cu), (s.cx & 0xffffu));
  }
  L0054da4a: { // 0x54da4a: 668944244e MOV word ptr [ESP + 0x4e],AX
    m.w16((f.sp+0x0000004eu), (s.ax & 0xffffu));
  }
  L0054da4f: { // 0x54da4f: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L0054da53: { // 0x54da53: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054da56: { // 0x54da56: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054da59: { // 0x54da59: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054da5c: { // 0x54da5c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054da5e: { // 0x54da5e: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0054da62: { // 0x54da62: 7818 JS 0x0054da7c
    if(integer::condition("JS",flags)) goto L0054da7c;
  }
  L0054da64: { // 0x54da64: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054da69: { // 0x54da69: 7d11 JGE 0x0054da7c
    if(integer::condition("JGE",flags)) goto L0054da7c;
  }
  L0054da6b: { // 0x54da6b: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0054da71: { // 0x54da71: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0054da74: { // 0x54da74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054da76: { // 0x54da76: 7404 JZ 0x0054da7c
    if(integer::condition("JZ",flags)) goto L0054da7c;
  }
  L0054da78: { // 0x54da78: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0054da7a: { // 0x54da7a: eb0b JMP 0x0054da87
    goto L0054da87;
  }
  L0054da7c: { // 0x54da7c: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0054da82: { // 0x54da82: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L0054da87: { // 0x54da87: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0054da8b: { // 0x54da8b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054da8d: { // 0x54da8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054da8e: { // 0x54da8e: e89d9a0000 CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,5560979u); flags=s.arithmetic_flags;
  }
  L0054da93: { // 0x54da93: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054da95: { // 0x54da95: 0f8424010000 JZ 0x0054dbbf
    if(integer::condition("JZ",flags)) goto L0054dbbf;
  }
  L0054da9b: { // 0x54da9b: 8b9424d0010000 MOV EDX,dword ptr [ESP + 0x1d0]
    s.dx = m.r32((f.sp+0x000001d0u));
  }
  L0054daa2: { // 0x54daa2: 8b8424c0010000 MOV EAX,dword ptr [ESP + 0x1c0]
    s.ax = m.r32((f.sp+0x000001c0u));
  }
  L0054daa9: { // 0x54daa9: 8b8c24bc010000 MOV ECX,dword ptr [ESP + 0x1bc]
    s.cx = m.r32((f.sp+0x000001bcu));
  }
  L0054dab0: { // 0x54dab0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dab1: { // 0x54dab1: 8b9424bc010000 MOV EDX,dword ptr [ESP + 0x1bc]
    s.dx = m.r32((f.sp+0x000001bcu));
  }
  L0054dab8: { // 0x54dab8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054dab9: { // 0x54dab9: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0054dabb: { // 0x54dabb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054dabc: { // 0x54dabc: 8b8424dc010000 MOV EAX,dword ptr [ESP + 0x1dc]
    s.ax = m.r32((f.sp+0x000001dcu));
  }
  L0054dac3: { // 0x54dac3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054dac4: { // 0x54dac4: 8b8c24dc010000 MOV ECX,dword ptr [ESP + 0x1dc]
    s.cx = m.r32((f.sp+0x000001dcu));
  }
  L0054dacb: { // 0x54dacb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dacc: { // 0x54dacc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054dacd: { // 0x54dacd: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0054dad1: { // 0x54dad1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054dad2: { // 0x54dad2: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0054dad6: { // 0x54dad6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dad7: { // 0x54dad7: e8a4060000 CALL 0x0054e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054e180u,5561052u); flags=s.arithmetic_flags;
  }
  L0054dadc: { // 0x54dadc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dade: { // 0x54dade: 0f84db000000 JZ 0x0054dbbf
    if(integer::condition("JZ",flags)) goto L0054dbbf;
  }
  L0054dae4: { // 0x54dae4: 8a8424d4010000 MOV AL,byte ptr [ESP + 0x1d4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d4u)));
  }
  L0054daeb: { // 0x54daeb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054daed: { // 0x54daed: 742e JZ 0x0054db1d
    if(integer::condition("JZ",flags)) goto L0054db1d;
  }
  L0054daef: { // 0x54daef: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054daf5: { // 0x54daf5: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0054dafc: { // 0x54dafc: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L0054daff: { // 0x54daff: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  L0054db02: { // 0x54db02: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0054db05: { // 0x54db05: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054db07: { // 0x54db07: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0054db0b: { // 0x54db0b: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054db0d: { // 0x54db0d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054db0f: { // 0x54db0f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054db10: { // 0x54db10: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054db12: { // 0x54db12: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054db14: { // 0x54db14: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0054db17: { // 0x54db17: 0f8da2000000 JGE 0x0054dbbf
    if(integer::condition("JGE",flags)) goto L0054dbbf;
  }
  L0054db1d: { // 0x54db1d: 8a8424d8010000 MOV AL,byte ptr [ESP + 0x1d8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d8u)));
  }
  L0054db24: { // 0x54db24: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054db26: { // 0x54db26: 740f JZ 0x0054db37
    if(integer::condition("JZ",flags)) goto L0054db37;
  }
  L0054db28: { // 0x54db28: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054db2a: { // 0x54db2a: e8d1e2f2ff CALL 0x0047be00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047be00u,5561135u); flags=s.arithmetic_flags;
  }
  L0054db2f: { // 0x54db2f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054db31: { // 0x54db31: 0f8488000000 JZ 0x0054dbbf
    if(integer::condition("JZ",flags)) goto L0054dbbf;
  }
  L0054db37: { // 0x54db37: 8a8424dc010000 MOV AL,byte ptr [ESP + 0x1dc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001dcu)));
  }
  L0054db3e: { // 0x54db3e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054db40: { // 0x54db40: 750b JNZ 0x0054db4d
    if(integer::condition("JNZ",flags)) goto L0054db4d;
  }
  L0054db42: { // 0x54db42: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054db48: { // 0x54db48: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054db4b: { // 0x54db4b: 7572 JNZ 0x0054dbbf
    if(integer::condition("JNZ",flags)) goto L0054dbbf;
  }
  L0054db4d: { // 0x54db4d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0054db51: { // 0x54db51: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0054db55: { // 0x54db55: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  L0054db58: { // 0x54db58: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0054db59: { // 0x54db59: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0054db5c: { // 0x54db5c: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0054db60: { // 0x54db60: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0054db62: { // 0x54db62: 7556 JNZ 0x0054dbba
    if(integer::condition("JNZ",flags)) goto L0054dbba;
  }
  L0054db64: { // 0x54db64: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0054db69: { // 0x54db69: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054db6c: { // 0x54db6c: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054db6f: { // 0x54db6f: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0054db74: { // 0x54db74: 8d542468 LEA EDX,[ESP + 0x68]
    s.dx = (f.sp+0x00000068u);
  }
  L0054db78: { // 0x54db78: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054db7b: { // 0x54db7b: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L0054db7f: { // 0x54db7f: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0054db85: { // 0x54db85: 8d842488000000 LEA EAX,[ESP + 0x88]
    s.ax = (f.sp+0x00000088u);
  }
  L0054db8c: { // 0x54db8c: 894c246c MOV dword ptr [ESP + 0x6c],ECX
    m.w32((f.sp+0x0000006cu), s.cx);
  }
  L0054db90: { // 0x54db90: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0054db96: { // 0x54db96: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054db97: { // 0x54db97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054db98: { // 0x54db98: c744247800000000 MOV dword ptr [ESP + 0x78],0x0
    m.w32((f.sp+0x00000078u), 0x00000000u);
  }
  L0054dba0: { // 0x54dba0: e8ebe41400 CALL 0x0069c090
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c090u,5561253u); flags=s.arithmetic_flags;
  }
  L0054dba5: { // 0x54dba5: 668b4c2410 MOV CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000010u)));
  }
  L0054dbaa: { // 0x54dbaa: 663b08 CMP CX,word ptr [EAX]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.ax)),16,flags);
  }
  L0054dbad: { // 0x54dbad: 7510 JNZ 0x0054dbbf
    if(integer::condition("JNZ",flags)) goto L0054dbbf;
  }
  L0054dbaf: { // 0x54dbaf: 668b542412 MOV DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000012u)));
  }
  L0054dbb4: { // 0x54dbb4: 663b5002 CMP DX,word ptr [EAX + 0x2]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.ax+0x00000002u)),16,flags);
  }
  L0054dbb8: { // 0x54dbb8: 7505 JNZ 0x0054dbbf
    if(integer::condition("JNZ",flags)) goto L0054dbbf;
  }
  L0054dbba: { // 0x54dbba: c644241701 MOV byte ptr [ESP + 0x17],0x1
    m.w8((f.sp+0x00000017u), 0x00000001u);
  }
  L0054dbbf: { // 0x54dbbf: 837c241818 CMP dword ptr [ESP + 0x18],0x18
    (void)integer::sub(m.r32((f.sp+0x00000018u)),0x00000018u,32,flags);
  }
  L0054dbc4: { // 0x54dbc4: 0f84a9030000 JZ 0x0054df73
    if(integer::condition("JZ",flags)) goto L0054df73;
  }
  L0054dbca: { // 0x54dbca: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054dbce: { // 0x54dbce: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0054dbcf: { // 0x54dbcf: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0054dbd1: { // 0x54dbd1: 0f8ea3fcffff JLE 0x0054d87a
    if(integer::condition("JLE",flags)) goto L0054d87a;
  }
  L0054dbd7: { // 0x54dbd7: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L0054dbdb: { // 0x54dbdb: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L0054dbdf: { // 0x54dbdf: 83fd18 CMP EBP,0x18
    (void)integer::sub(s.bp,0x00000018u,32,flags);
  }
  L0054dbe2: { // 0x54dbe2: 0f848f030000 JZ 0x0054df77
    if(integer::condition("JZ",flags)) goto L0054df77;
  }
  L0054dbe8: { // 0x54dbe8: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054dbec: { // 0x54dbec: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0054dbed: { // 0x54dbed: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0054dbee: { // 0x54dbee: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0054dbf0: { // 0x54dbf0: 0f8f50030000 JG 0x0054df46
    if(integer::condition("JG",flags)) goto L0054df46;
  }
  L0054dbf6: { // 0x54dbf6: 8dacac8c000000 LEA EBP,[ESP + EBP*0x4 + 0x8c]
    s.bp = (f.sp+(s.bp * 0x00000004u)+0x0000008cu);
  }
  L0054dbfd: { // 0x54dbfd: 8a8424e4010000 MOV AL,byte ptr [ESP + 0x1e4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001e4u)));
  }
  L0054dc04: { // 0x54dc04: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dc06: { // 0x54dc06: 0f858e010000 JNZ 0x0054dd9a
    if(integer::condition("JNZ",flags)) goto L0054dd9a;
  }
  L0054dc0c: { // 0x54dc0c: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0054dc10: { // 0x54dc10: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054dc14: { // 0x54dc14: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0054dc18: { // 0x54dc18: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0054dc1a: { // 0x54dc1a: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  L0054dc1f: { // 0x54dc1f: 8d0417 LEA EAX,[EDI + EDX*0x1]
    s.ax = (s.di+(s.dx * 0x00000001u));
  }
  L0054dc22: { // 0x54dc22: 668944243e MOV word ptr [ESP + 0x3e],AX
    m.w16((f.sp+0x0000003eu), (s.ax & 0xffffu));
  }
  L0054dc27: { // 0x54dc27: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0054dc2b: { // 0x54dc2b: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054dc2e: { // 0x54dc2e: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054dc31: { // 0x54dc31: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054dc34: { // 0x54dc34: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054dc36: { // 0x54dc36: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0054dc3a: { // 0x54dc3a: 7818 JS 0x0054dc54
    if(integer::condition("JS",flags)) goto L0054dc54;
  }
  L0054dc3c: { // 0x54dc3c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054dc41: { // 0x54dc41: 7d11 JGE 0x0054dc54
    if(integer::condition("JGE",flags)) goto L0054dc54;
  }
  L0054dc43: { // 0x54dc43: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0054dc49: { // 0x54dc49: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0054dc4c: { // 0x54dc4c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054dc4e: { // 0x54dc4e: 7404 JZ 0x0054dc54
    if(integer::condition("JZ",flags)) goto L0054dc54;
  }
  L0054dc50: { // 0x54dc50: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0054dc52: { // 0x54dc52: eb0b JMP 0x0054dc5f
    goto L0054dc5f;
  }
  L0054dc54: { // 0x54dc54: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0054dc5a: { // 0x54dc5a: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L0054dc5f: { // 0x54dc5f: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0054dc63: { // 0x54dc63: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054dc65: { // 0x54dc65: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054dc66: { // 0x54dc66: e8c5980000 CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,5561451u); flags=s.arithmetic_flags;
  }
  L0054dc6b: { // 0x54dc6b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dc6d: { // 0x54dc6d: 0f8427010000 JZ 0x0054dd9a
    if(integer::condition("JZ",flags)) goto L0054dd9a;
  }
  L0054dc73: { // 0x54dc73: 8b9424d0010000 MOV EDX,dword ptr [ESP + 0x1d0]
    s.dx = m.r32((f.sp+0x000001d0u));
  }
  L0054dc7a: { // 0x54dc7a: 8b8424c0010000 MOV EAX,dword ptr [ESP + 0x1c0]
    s.ax = m.r32((f.sp+0x000001c0u));
  }
  L0054dc81: { // 0x54dc81: 8b8c24bc010000 MOV ECX,dword ptr [ESP + 0x1bc]
    s.cx = m.r32((f.sp+0x000001bcu));
  }
  L0054dc88: { // 0x54dc88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dc89: { // 0x54dc89: 8b9424bc010000 MOV EDX,dword ptr [ESP + 0x1bc]
    s.dx = m.r32((f.sp+0x000001bcu));
  }
  L0054dc90: { // 0x54dc90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054dc91: { // 0x54dc91: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0054dc93: { // 0x54dc93: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054dc94: { // 0x54dc94: 8b8424dc010000 MOV EAX,dword ptr [ESP + 0x1dc]
    s.ax = m.r32((f.sp+0x000001dcu));
  }
  L0054dc9b: { // 0x54dc9b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054dc9c: { // 0x54dc9c: 8b8c24dc010000 MOV ECX,dword ptr [ESP + 0x1dc]
    s.cx = m.r32((f.sp+0x000001dcu));
  }
  L0054dca3: { // 0x54dca3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dca4: { // 0x54dca4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054dca5: { // 0x54dca5: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0054dca9: { // 0x54dca9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054dcaa: { // 0x54dcaa: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0054dcae: { // 0x54dcae: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dcaf: { // 0x54dcaf: e8cc040000 CALL 0x0054e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054e180u,5561524u); flags=s.arithmetic_flags;
  }
  L0054dcb4: { // 0x54dcb4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dcb6: { // 0x54dcb6: 0f84de000000 JZ 0x0054dd9a
    if(integer::condition("JZ",flags)) goto L0054dd9a;
  }
  L0054dcbc: { // 0x54dcbc: 8a8424d4010000 MOV AL,byte ptr [ESP + 0x1d4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d4u)));
  }
  L0054dcc3: { // 0x54dcc3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dcc5: { // 0x54dcc5: 742e JZ 0x0054dcf5
    if(integer::condition("JZ",flags)) goto L0054dcf5;
  }
  L0054dcc7: { // 0x54dcc7: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054dccd: { // 0x54dccd: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0054dcd4: { // 0x54dcd4: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L0054dcd7: { // 0x54dcd7: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  L0054dcda: { // 0x54dcda: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0054dcdd: { // 0x54dcdd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054dcdf: { // 0x54dcdf: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0054dce3: { // 0x54dce3: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054dce5: { // 0x54dce5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054dce7: { // 0x54dce7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054dce8: { // 0x54dce8: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054dcea: { // 0x54dcea: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054dcec: { // 0x54dcec: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0054dcef: { // 0x54dcef: 0f8da5000000 JGE 0x0054dd9a
    if(integer::condition("JGE",flags)) goto L0054dd9a;
  }
  L0054dcf5: { // 0x54dcf5: 8a8424d8010000 MOV AL,byte ptr [ESP + 0x1d8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d8u)));
  }
  L0054dcfc: { // 0x54dcfc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dcfe: { // 0x54dcfe: 740f JZ 0x0054dd0f
    if(integer::condition("JZ",flags)) goto L0054dd0f;
  }
  L0054dd00: { // 0x54dd00: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054dd02: { // 0x54dd02: e8f9e0f2ff CALL 0x0047be00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047be00u,5561607u); flags=s.arithmetic_flags;
  }
  L0054dd07: { // 0x54dd07: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dd09: { // 0x54dd09: 0f848b000000 JZ 0x0054dd9a
    if(integer::condition("JZ",flags)) goto L0054dd9a;
  }
  L0054dd0f: { // 0x54dd0f: 8a8424dc010000 MOV AL,byte ptr [ESP + 0x1dc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001dcu)));
  }
  L0054dd16: { // 0x54dd16: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dd18: { // 0x54dd18: 750b JNZ 0x0054dd25
    if(integer::condition("JNZ",flags)) goto L0054dd25;
  }
  L0054dd1a: { // 0x54dd1a: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054dd20: { // 0x54dd20: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054dd23: { // 0x54dd23: 7575 JNZ 0x0054dd9a
    if(integer::condition("JNZ",flags)) goto L0054dd9a;
  }
  L0054dd25: { // 0x54dd25: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0054dd29: { // 0x54dd29: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0054dd2d: { // 0x54dd2d: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  L0054dd30: { // 0x54dd30: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0054dd31: { // 0x54dd31: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0054dd34: { // 0x54dd34: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0054dd38: { // 0x54dd38: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0054dd3a: { // 0x54dd3a: 7559 JNZ 0x0054dd95
    if(integer::condition("JNZ",flags)) goto L0054dd95;
  }
  L0054dd3c: { // 0x54dd3c: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0054dd41: { // 0x54dd41: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054dd44: { // 0x54dd44: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054dd47: { // 0x54dd47: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0054dd4c: { // 0x54dd4c: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L0054dd50: { // 0x54dd50: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054dd53: { // 0x54dd53: 89442474 MOV dword ptr [ESP + 0x74],EAX
    m.w32((f.sp+0x00000074u), s.ax);
  }
  L0054dd57: { // 0x54dd57: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0054dd5d: { // 0x54dd5d: 8d842484000000 LEA EAX,[ESP + 0x84]
    s.ax = (f.sp+0x00000084u);
  }
  L0054dd64: { // 0x54dd64: 894c2478 MOV dword ptr [ESP + 0x78],ECX
    m.w32((f.sp+0x00000078u), s.cx);
  }
  L0054dd68: { // 0x54dd68: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0054dd6e: { // 0x54dd6e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dd6f: { // 0x54dd6f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054dd70: { // 0x54dd70: c784248400000000000000 MOV dword ptr [ESP + 0x84],0x0
    m.w32((f.sp+0x00000084u), 0x00000000u);
  }
  L0054dd7b: { // 0x54dd7b: e810e31400 CALL 0x0069c090
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c090u,5561728u); flags=s.arithmetic_flags;
  }
  L0054dd80: { // 0x54dd80: 668b4c2410 MOV CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000010u)));
  }
  L0054dd85: { // 0x54dd85: 663b08 CMP CX,word ptr [EAX]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.ax)),16,flags);
  }
  L0054dd88: { // 0x54dd88: 7510 JNZ 0x0054dd9a
    if(integer::condition("JNZ",flags)) goto L0054dd9a;
  }
  L0054dd8a: { // 0x54dd8a: 668b542412 MOV DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000012u)));
  }
  L0054dd8f: { // 0x54dd8f: 663b5002 CMP DX,word ptr [EAX + 0x2]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.ax+0x00000002u)),16,flags);
  }
  L0054dd93: { // 0x54dd93: 7505 JNZ 0x0054dd9a
    if(integer::condition("JNZ",flags)) goto L0054dd9a;
  }
  L0054dd95: { // 0x54dd95: c644241701 MOV byte ptr [ESP + 0x17],0x1
    m.w8((f.sp+0x00000017u), 0x00000001u);
  }
  L0054dd9a: { // 0x54dd9a: 837c241818 CMP dword ptr [ESP + 0x18],0x18
    (void)integer::sub(m.r32((f.sp+0x00000018u)),0x00000018u,32,flags);
  }
  L0054dd9f: { // 0x54dd9f: 0f84ce010000 JZ 0x0054df73
    if(integer::condition("JZ",flags)) goto L0054df73;
  }
  L0054dda5: { // 0x54dda5: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054dda9: { // 0x54dda9: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0054ddad: { // 0x54ddad: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0054ddb1: { // 0x54ddb1: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0054ddb3: { // 0x54ddb3: 66894c2420 MOV word ptr [ESP + 0x20],CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L0054ddb8: { // 0x54ddb8: 8d0417 LEA EAX,[EDI + EDX*0x1]
    s.ax = (s.di+(s.dx * 0x00000001u));
  }
  L0054ddbb: { // 0x54ddbb: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L0054ddc0: { // 0x54ddc0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0054ddc4: { // 0x54ddc4: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054ddc7: { // 0x54ddc7: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054ddca: { // 0x54ddca: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054ddcd: { // 0x54ddcd: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054ddcf: { // 0x54ddcf: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0054ddd3: { // 0x54ddd3: 7818 JS 0x0054dded
    if(integer::condition("JS",flags)) goto L0054dded;
  }
  L0054ddd5: { // 0x54ddd5: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054ddda: { // 0x54ddda: 7d11 JGE 0x0054dded
    if(integer::condition("JGE",flags)) goto L0054dded;
  }
  L0054dddc: { // 0x54dddc: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0054dde2: { // 0x54dde2: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0054dde5: { // 0x54dde5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054dde7: { // 0x54dde7: 7404 JZ 0x0054dded
    if(integer::condition("JZ",flags)) goto L0054dded;
  }
  L0054dde9: { // 0x54dde9: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0054ddeb: { // 0x54ddeb: eb0b JMP 0x0054ddf8
    goto L0054ddf8;
  }
  L0054dded: { // 0x54dded: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0054ddf3: { // 0x54ddf3: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L0054ddf8: { // 0x54ddf8: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0054ddfc: { // 0x54ddfc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054ddfe: { // 0x54ddfe: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054ddff: { // 0x54ddff: e82c970000 CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,5561860u); flags=s.arithmetic_flags;
  }
  L0054de04: { // 0x54de04: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054de06: { // 0x54de06: 0f8421010000 JZ 0x0054df2d
    if(integer::condition("JZ",flags)) goto L0054df2d;
  }
  L0054de0c: { // 0x54de0c: 8b9424d0010000 MOV EDX,dword ptr [ESP + 0x1d0]
    s.dx = m.r32((f.sp+0x000001d0u));
  }
  L0054de13: { // 0x54de13: 8b8424c0010000 MOV EAX,dword ptr [ESP + 0x1c0]
    s.ax = m.r32((f.sp+0x000001c0u));
  }
  L0054de1a: { // 0x54de1a: 8b8c24bc010000 MOV ECX,dword ptr [ESP + 0x1bc]
    s.cx = m.r32((f.sp+0x000001bcu));
  }
  L0054de21: { // 0x54de21: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054de22: { // 0x54de22: 8b9424bc010000 MOV EDX,dword ptr [ESP + 0x1bc]
    s.dx = m.r32((f.sp+0x000001bcu));
  }
  L0054de29: { // 0x54de29: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054de2a: { // 0x54de2a: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0054de2c: { // 0x54de2c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054de2d: { // 0x54de2d: 8b8424dc010000 MOV EAX,dword ptr [ESP + 0x1dc]
    s.ax = m.r32((f.sp+0x000001dcu));
  }
  L0054de34: { // 0x54de34: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054de35: { // 0x54de35: 8b8c24dc010000 MOV ECX,dword ptr [ESP + 0x1dc]
    s.cx = m.r32((f.sp+0x000001dcu));
  }
  L0054de3c: { // 0x54de3c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054de3d: { // 0x54de3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054de3e: { // 0x54de3e: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0054de42: { // 0x54de42: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054de43: { // 0x54de43: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0054de47: { // 0x54de47: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054de48: { // 0x54de48: e833030000 CALL 0x0054e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054e180u,5561933u); flags=s.arithmetic_flags;
  }
  L0054de4d: { // 0x54de4d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054de4f: { // 0x54de4f: 0f84d8000000 JZ 0x0054df2d
    if(integer::condition("JZ",flags)) goto L0054df2d;
  }
  L0054de55: { // 0x54de55: 8a8424d4010000 MOV AL,byte ptr [ESP + 0x1d4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d4u)));
  }
  L0054de5c: { // 0x54de5c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054de5e: { // 0x54de5e: 742e JZ 0x0054de8e
    if(integer::condition("JZ",flags)) goto L0054de8e;
  }
  L0054de60: { // 0x54de60: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054de66: { // 0x54de66: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0054de6d: { // 0x54de6d: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L0054de70: { // 0x54de70: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  L0054de73: { // 0x54de73: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0054de76: { // 0x54de76: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054de78: { // 0x54de78: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0054de7c: { // 0x54de7c: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054de7e: { // 0x54de7e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054de80: { // 0x54de80: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054de81: { // 0x54de81: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0054de83: { // 0x54de83: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0054de85: { // 0x54de85: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0054de88: { // 0x54de88: 0f8d9f000000 JGE 0x0054df2d
    if(integer::condition("JGE",flags)) goto L0054df2d;
  }
  L0054de8e: { // 0x54de8e: 8a8424d8010000 MOV AL,byte ptr [ESP + 0x1d8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001d8u)));
  }
  L0054de95: { // 0x54de95: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054de97: { // 0x54de97: 740f JZ 0x0054dea8
    if(integer::condition("JZ",flags)) goto L0054dea8;
  }
  L0054de99: { // 0x54de99: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0054de9b: { // 0x54de9b: e860dff2ff CALL 0x0047be00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047be00u,5562016u); flags=s.arithmetic_flags;
  }
  L0054dea0: { // 0x54dea0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054dea2: { // 0x54dea2: 0f8485000000 JZ 0x0054df2d
    if(integer::condition("JZ",flags)) goto L0054df2d;
  }
  L0054dea8: { // 0x54dea8: 8a8424dc010000 MOV AL,byte ptr [ESP + 0x1dc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000001dcu)));
  }
  L0054deaf: { // 0x54deaf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054deb1: { // 0x54deb1: 750b JNZ 0x0054debe
    if(integer::condition("JNZ",flags)) goto L0054debe;
  }
  L0054deb3: { // 0x54deb3: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0054deb9: { // 0x54deb9: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054debc: { // 0x54debc: 756f JNZ 0x0054df2d
    if(integer::condition("JNZ",flags)) goto L0054df2d;
  }
  L0054debe: { // 0x54debe: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0054dec2: { // 0x54dec2: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0054dec6: { // 0x54dec6: 894500 MOV dword ptr [EBP],EAX
    m.w32((s.bp), s.ax);
  }
  L0054dec9: { // 0x54dec9: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0054deca: { // 0x54deca: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0054decd: { // 0x54decd: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0054ded1: { // 0x54ded1: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0054ded3: { // 0x54ded3: 7553 JNZ 0x0054df28
    if(integer::condition("JNZ",flags)) goto L0054df28;
  }
  L0054ded5: { // 0x54ded5: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0054deda: { // 0x54deda: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054dedd: { // 0x54dedd: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054dee0: { // 0x54dee0: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0054dee5: { // 0x54dee5: 8d542450 LEA EDX,[ESP + 0x50]
    s.dx = (f.sp+0x00000050u);
  }
  L0054dee9: { // 0x54dee9: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054deec: { // 0x54deec: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0054def0: { // 0x54def0: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0054def6: { // 0x54def6: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L0054defa: { // 0x54defa: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0054defe: { // 0x54defe: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0054df04: { // 0x54df04: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054df05: { // 0x54df05: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054df06: { // 0x54df06: c744246000000000 MOV dword ptr [ESP + 0x60],0x0
    m.w32((f.sp+0x00000060u), 0x00000000u);
  }
  L0054df0e: { // 0x54df0e: e87de11400 CALL 0x0069c090
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c090u,5562131u); flags=s.arithmetic_flags;
  }
  L0054df13: { // 0x54df13: 668b4c2410 MOV CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000010u)));
  }
  L0054df18: { // 0x54df18: 663b08 CMP CX,word ptr [EAX]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.ax)),16,flags);
  }
  L0054df1b: { // 0x54df1b: 7510 JNZ 0x0054df2d
    if(integer::condition("JNZ",flags)) goto L0054df2d;
  }
  L0054df1d: { // 0x54df1d: 668b542412 MOV DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000012u)));
  }
  L0054df22: { // 0x54df22: 663b5002 CMP DX,word ptr [EAX + 0x2]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.ax+0x00000002u)),16,flags);
  }
  L0054df26: { // 0x54df26: 7505 JNZ 0x0054df2d
    if(integer::condition("JNZ",flags)) goto L0054df2d;
  }
  L0054df28: { // 0x54df28: c644241701 MOV byte ptr [ESP + 0x17],0x1
    m.w8((f.sp+0x00000017u), 0x00000001u);
  }
  L0054df2d: { // 0x54df2d: 837c241818 CMP dword ptr [ESP + 0x18],0x18
    (void)integer::sub(m.r32((f.sp+0x00000018u)),0x00000018u,32,flags);
  }
  L0054df32: { // 0x54df32: 743f JZ 0x0054df73
    if(integer::condition("JZ",flags)) goto L0054df73;
  }
  L0054df34: { // 0x54df34: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054df38: { // 0x54df38: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0054df39: { // 0x54df39: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0054df3a: { // 0x54df3a: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0054df3c: { // 0x54df3c: 0f8ebbfcffff JLE 0x0054dbfd
    if(integer::condition("JLE",flags)) goto L0054dbfd;
  }
  L0054df42: { // 0x54df42: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L0054df46: { // 0x54df46: 83fd18 CMP EBP,0x18
    (void)integer::sub(s.bp,0x00000018u,32,flags);
  }
  L0054df49: { // 0x54df49: 742c JZ 0x0054df77
    if(integer::condition("JZ",flags)) goto L0054df77;
  }
  L0054df4b: { // 0x54df4b: 8a442417 MOV AL,byte ptr [ESP + 0x17]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000017u)));
  }
  L0054df4f: { // 0x54df4f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054df51: { // 0x54df51: 7524 JNZ 0x0054df77
    if(integer::condition("JNZ",flags)) goto L0054df77;
  }
  L0054df53: { // 0x54df53: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054df57: { // 0x54df57: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0054df5b: { // 0x54df5b: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0054df5f: { // 0x54df5f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0054df60: { // 0x54df60: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0054df61: { // 0x54df61: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0054df63: { // 0x54df63: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0054df67: { // 0x54df67: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0054df6b: { // 0x54df6b: 0f8cf2f8ffff JL 0x0054d863
    if(integer::condition("JL",flags)) goto L0054d863;
  }
  L0054df71: { // 0x54df71: eb04 JMP 0x0054df77
    goto L0054df77;
  }
  L0054df73: { // 0x54df73: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L0054df77: { // 0x54df77: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0054df79: { // 0x54df79: 0f8edf010000 JLE 0x0054e15e
    if(integer::condition("JLE",flags)) goto L0054e15e;
  }
  L0054df7f: { // 0x54df7f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0054df83: { // 0x54df83: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0054df85: { // 0x54df85: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0054df87: { // 0x54df87: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0054df8b: { // 0x54df8b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054df8d: { // 0x54df8d: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0054df91: { // 0x54df91: 0f8eb6000000 JLE 0x0054e04d
    if(integer::condition("JLE",flags)) goto L0054e04d;
  }
  L0054df97: { // 0x54df97: 8d8c24ec000000 LEA ECX,[ESP + 0xec]
    s.cx = (f.sp+0x000000ecu);
  }
  L0054df9e: { // 0x54df9e: 8d9c244c010000 LEA EBX,[ESP + 0x14c]
    s.bx = (f.sp+0x0000014cu);
  }
  L0054dfa5: { // 0x54dfa5: 8db4248c000000 LEA ESI,[ESP + 0x8c]
    s.si = (f.sp+0x0000008cu);
  }
  L0054dfac: { // 0x54dfac: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0054dfb0: { // 0x54dfb0: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0054dfb4: { // 0x54dfb4: 668b3e MOV DI,word ptr [ESI]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.si))) & 0xffffu);
  }
  L0054dfb7: { // 0x54dfb7: 668b6e02 MOV BP,word ptr [ESI + 0x2]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.si+0x00000002u))) & 0xffffu);
  }
  L0054dfbb: { // 0x54dfbb: 0fbfd7 MOVSX EDX,DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L0054dfbe: { // 0x54dfbe: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054dfc1: { // 0x54dfc1: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L0054dfc4: { // 0x54dfc4: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L0054dfca: { // 0x54dfca: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0054dfce: { // 0x54dfce: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0054dfd2: { // 0x54dfd2: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L0054dfd6: { // 0x54dfd6: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0054dfd9: { // 0x54dfd9: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0054dfde: { // 0x54dfde: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054dfdf: { // 0x54dfdf: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0054dfe5: { // 0x54dfe5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054dfe6: { // 0x54dfe6: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0054dfea: { // 0x54dfea: c744246000000000 MOV dword ptr [ESP + 0x60],0x0
    m.w32((f.sp+0x00000060u), 0x00000000u);
  }
  L0054dff2: { // 0x54dff2: e899e01400 CALL 0x0069c090
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c090u,5562359u); flags=s.arithmetic_flags;
  }
  L0054dff7: { // 0x54dff7: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0054dff9: { // 0x54dff9: 663bc7 CMP AX,DI
    (void)integer::sub((s.ax & 0xffffu),(s.di & 0xffffu),16,flags);
  }
  L0054dffc: { // 0x54dffc: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0054e000: { // 0x54e000: 7521 JNZ 0x0054e023
    if(integer::condition("JNZ",flags)) goto L0054e023;
  }
  L0054e002: { // 0x54e002: 66396c243e CMP word ptr [ESP + 0x3e],BP
    (void)integer::sub(m.r16((f.sp+0x0000003eu)),(s.bp & 0xffffu),16,flags);
  }
  L0054e007: { // 0x54e007: 751a JNZ 0x0054e023
    if(integer::condition("JNZ",flags)) goto L0054e023;
  }
  L0054e009: { // 0x54e009: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0054e00d: { // 0x54e00d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0054e00f: { // 0x54e00f: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0054e013: { // 0x54e013: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0054e015: { // 0x54e015: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0054e016: { // 0x54e016: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0054e019: { // 0x54e019: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0054e01d: { // 0x54e01d: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0054e021: { // 0x54e021: eb10 JMP 0x0054e033
    goto L0054e033;
  }
  L0054e023: { // 0x54e023: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0054e027: { // 0x54e027: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0054e029: { // 0x54e029: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0054e02a: { // 0x54e02a: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L0054e02c: { // 0x54e02c: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0054e030: { // 0x54e030: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L0054e033: { // 0x54e033: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0054e037: { // 0x54e037: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0054e03a: { // 0x54e03a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0054e03b: { // 0x54e03b: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0054e03f: { // 0x54e03f: 0f856fffffff JNZ 0x0054dfb4
    if(integer::condition("JNZ",flags)) goto L0054dfb4;
  }
  L0054e045: { // 0x54e045: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0054e049: { // 0x54e049: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0054e04d: { // 0x54e04d: 8bac24e0010000 MOV EBP,dword ptr [ESP + 0x1e0]
    s.bp = m.r32((f.sp+0x000001e0u));
  }
  L0054e054: { // 0x54e054: a15c6ea500 MOV EAX,[0x00a56e5c]
    s.ax = m.r32((0x00a56e5cu));
  }
  L0054e059: { // 0x54e059: 66394500 CMP word ptr [EBP],AX
    (void)integer::sub(m.r16((s.bp)),(s.ax & 0xffffu),16,flags);
  }
  L0054e05d: { // 0x54e05d: 7555 JNZ 0x0054e0b4
    if(integer::condition("JNZ",flags)) goto L0054e0b4;
  }
  L0054e05f: { // 0x54e05f: 668b5502 MOV DX,word ptr [EBP + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L0054e063: { // 0x54e063: 663b155e6ea500 CMP DX,word ptr [0x00a56e5e]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a56e5eu)),16,flags);
  }
  L0054e06a: { // 0x54e06a: 7548 JNZ 0x0054e0b4
    if(integer::condition("JNZ",flags)) goto L0054e0b4;
  }
  L0054e06c: { // 0x54e06c: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L0054e071: { // 0x54e071: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0054e073: { // 0x54e073: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0054e074: { // 0x54e074: 741f JZ 0x0054e095
    if(integer::condition("JZ",flags)) goto L0054e095;
  }
  L0054e076: { // 0x54e076: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0054e078: { // 0x54e078: 8b8424b0010000 MOV EAX,dword ptr [ESP + 0x1b0]
    s.ax = m.r32((f.sp+0x000001b0u));
  }
  L0054e07f: { // 0x54e07f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054e080: { // 0x54e080: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054e081: { // 0x54e081: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054e082: { // 0x54e082: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054e083: { // 0x54e083: 8b8c94dc000000 MOV ECX,dword ptr [ESP + EDX*0x4 + 0xdc]
    s.cx = m.r32((f.sp+(s.dx * 0x00000004u)+0x000000dcu));
  }
  L0054e08a: { // 0x54e08a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0054e08c: { // 0x54e08c: 81c49c010000 ADD ESP,0x19c
    f.sp = integer::add(f.sp,0x0000019cu,32,flags);
  }
  L0054e092: { // 0x54e092: c23800 RET 0x38
    s.arithmetic_flags=flags; finish(m,s,f,56u); return;
  }
  L0054e095: { // 0x54e095: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0054e097: { // 0x54e097: 8b8424b0010000 MOV EAX,dword ptr [ESP + 0x1b0]
    s.ax = m.r32((f.sp+0x000001b0u));
  }
  L0054e09e: { // 0x54e09e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054e09f: { // 0x54e09f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054e0a0: { // 0x54e0a0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054e0a1: { // 0x54e0a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054e0a2: { // 0x54e0a2: 8b94943c010000 MOV EDX,dword ptr [ESP + EDX*0x4 + 0x13c]
    s.dx = m.r32((f.sp+(s.dx * 0x00000004u)+0x0000013cu));
  }
  L0054e0a9: { // 0x54e0a9: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0054e0ab: { // 0x54e0ab: 81c49c010000 ADD ESP,0x19c
    f.sp = integer::add(f.sp,0x0000019cu,32,flags);
  }
  L0054e0b1: { // 0x54e0b1: c23800 RET 0x38
    s.arithmetic_flags=flags; finish(m,s,f,56u); return;
  }
  L0054e0b4: { // 0x54e0b4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0054e0b6: { // 0x54e0b6: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0054e0b8: { // 0x54e0b8: 7502 JNZ 0x0054e0bc
    if(integer::condition("JNZ",flags)) goto L0054e0bc;
  }
  L0054e0ba: { // 0x54e0ba: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0054e0bc: { // 0x54e0bc: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0054e0be: { // 0x54e0be: c744244000000000 MOV dword ptr [ESP + 0x40],0x0
    m.w32((f.sp+0x00000040u), 0x00000000u);
  }
  L0054e0c6: { // 0x54e0c6: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0054e0c8: { // 0x54e0c8: c7442444006af840 MOV dword ptr [ESP + 0x44],0x40f86a00
    m.w32((f.sp+0x00000044u), 0x40f86a00u);
  }
  L0054e0d0: { // 0x54e0d0: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0054e0d4: { // 0x54e0d4: 7e6e JLE 0x0054e144
    if(integer::condition("JLE",flags)) goto L0054e144;
  }
  L0054e0d6: { // 0x54e0d6: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0054e0da: { // 0x54e0da: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054e0dc: { // 0x54e0dc: 8d84bcec000000 LEA EAX,[ESP + EDI*0x4 + 0xec]
    s.ax = (f.sp+(s.di * 0x00000004u)+0x000000ecu);
  }
  L0054e0e3: { // 0x54e0e3: 7507 JNZ 0x0054e0ec
    if(integer::condition("JNZ",flags)) goto L0054e0ec;
  }
  L0054e0e5: { // 0x54e0e5: 8d84bc4c010000 LEA EAX,[ESP + EDI*0x4 + 0x14c]
    s.ax = (f.sp+(s.di * 0x00000004u)+0x0000014cu);
  }
  L0054e0ec: { // 0x54e0ec: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0054e0ee: { // 0x54e0ee: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0054e0f1: { // 0x54e0f1: 0fbf4d00 MOVSX ECX,word ptr [EBP]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L0054e0f5: { // 0x54e0f5: 0fbf5502 MOVSX EDX,word ptr [EBP + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L0054e0f9: { // 0x54e0f9: 0fbfc6 MOVSX EAX,SI
    s.ax = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0054e0fc: { // 0x54e0fc: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0054e100: { // 0x54e100: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0054e102: { // 0x54e102: 0fbf4c242a MOVSX ECX,word ptr [ESP + 0x2a]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002au)),16));
  }
  L0054e107: { // 0x54e107: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0054e109: { // 0x54e109: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0054e10b: { // 0x54e10b: 0fafd1 IMUL EDX,ECX
    s.dx = integer::imul(s.dx,s.cx,32,flags);
  }
  L0054e10e: { // 0x54e10e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054e110: { // 0x54e110: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  L0054e113: { // 0x54e113: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0054e115: { // 0x54e115: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0054e119: { // 0x54e119: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L0054e11d: { // 0x54e11d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0054e120: { // 0x54e120: e85bbff6ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5562661u); flags=s.arithmetic_flags;
  }
  L0054e125: { // 0x54e125: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0054e129: { // 0x54e129: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0054e12c: { // 0x54e12c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0054e12e: { // 0x54e12e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054e131: { // 0x54e131: 740a JZ 0x0054e13d
    if(integer::condition("JZ",flags)) goto L0054e13d;
  }
  L0054e133: { // 0x54e133: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0054e137: { // 0x54e137: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L0054e13b: { // 0x54e13b: eb02 JMP 0x0054e13f
    goto L0054e13f;
  }
  L0054e13d: { // 0x54e13d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0054e13f: { // 0x54e13f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0054e140: { // 0x54e140: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0054e142: { // 0x54e142: 7c92 JL 0x0054e0d6
    if(integer::condition("JL",flags)) goto L0054e0d6;
  }
  L0054e144: { // 0x54e144: 8b8424b0010000 MOV EAX,dword ptr [ESP + 0x1b0]
    s.ax = m.r32((f.sp+0x000001b0u));
  }
  L0054e14b: { // 0x54e14b: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0054e14f: { // 0x54e14f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054e150: { // 0x54e150: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054e151: { // 0x54e151: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054e152: { // 0x54e152: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0054e154: { // 0x54e154: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054e155: { // 0x54e155: 81c49c010000 ADD ESP,0x19c
    f.sp = integer::add(f.sp,0x0000019cu,32,flags);
  }
  L0054e15b: { // 0x54e15b: c23800 RET 0x38
    s.arithmetic_flags=flags; finish(m,s,f,56u); return;
  }
  L0054e15e: { // 0x54e15e: 8b8424b0010000 MOV EAX,dword ptr [ESP + 0x1b0]
    s.ax = m.r32((f.sp+0x000001b0u));
  }
  L0054e165: { // 0x54e165: 8b0d5c6ea500 MOV ECX,dword ptr [0x00a56e5c]
    s.cx = m.r32((0x00a56e5cu));
  }
  L0054e16b: { // 0x54e16b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054e16c: { // 0x54e16c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054e16d: { // 0x54e16d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054e16e: { // 0x54e16e: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0054e170: { // 0x54e170: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054e171: { // 0x54e171: 81c49c010000 ADD ESP,0x19c
    f.sp = integer::add(f.sp,0x0000019cu,32,flags);
  }
  L0054e177: { // 0x54e177: c23800 RET 0x38
    s.arithmetic_flags=flags; finish(m,s,f,56u); return;
  }
}
void f_00157530(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557530: { // 0x557530: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00557534: { // 0x557534: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557535: { // 0x557535: 8a5c240c MOV BL,byte ptr [ESP + 0xc]
    s.bx = with_al(s.bx, m.r8((f.sp+0x0000000cu)));
  }
  L00557539: { // 0x557539: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055753a: { // 0x55753a: 0fbf5026 MOVSX EDX,word ptr [EAX + 0x26]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000026u)),16));
  }
  L0055753e: { // 0x55753e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055753f: { // 0x55753f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00557541: { // 0x557541: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557542: { // 0x557542: 0fbf7824 MOVSX EDI,word ptr [EAX + 0x24]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000024u)),16));
  }
  L00557546: { // 0x557546: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00557548: { // 0x557548: 742b JZ 0x00557575
    if(integer::condition("JZ",flags)) goto L00557575;
  }
  L0055754a: { // 0x55754a: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L00557550: { // 0x557550: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L00557557: { // 0x557557: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00557559: { // 0x557559: 741a JZ 0x00557575
    if(integer::condition("JZ",flags)) goto L00557575;
  }
  L0055755b: { // 0x55755b: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L00557561: { // 0x557561: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L00557567: { // 0x557567: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  L0055756b: { // 0x55756b: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  L0055756e: { // 0x55756e: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00557570: { // 0x557570: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00557572: { // 0x557572: 7d01 JGE 0x00557575
    if(integer::condition("JGE",flags)) goto L00557575;
  }
  L00557574: { // 0x557574: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00557575: { // 0x557575: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  L0055757b: { // 0x55757b: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L00557581: { // 0x557581: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  L00557584: { // 0x557584: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  L00557587: { // 0x557587: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L00557589: { // 0x557589: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0055758b: { // 0x55758b: 7e49 JLE 0x005575d6
    if(integer::condition("JLE",flags)) goto L005575d6;
  }
  L0055758d: { // 0x55758d: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  L00557593: { // 0x557593: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  L00557599: { // 0x557599: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0055759b: { // 0x55759b: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  L0055759f: { // 0x55759f: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005575a1: { // 0x5575a1: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  L005575a4: { // 0x5575a4: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005575a6: { // 0x5575a6: 7f2e JG 0x005575d6
    if(integer::condition("JG",flags)) goto L005575d6;
  }
  L005575a8: { // 0x5575a8: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  L005575ae: { // 0x5575ae: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  L005575b4: { // 0x5575b4: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005575b6: { // 0x5575b6: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L005575b8: { // 0x5575b8: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L005575ba: { // 0x5575ba: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005575bc: { // 0x5575bc: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L005575be: { // 0x5575be: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L005575c0: { // 0x5575c0: 7d14 JGE 0x005575d6
    if(integer::condition("JGE",flags)) goto L005575d6;
  }
  L005575c2: { // 0x5575c2: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  L005575c5: { // 0x5575c5: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L005575c7: { // 0x5575c7: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005575c9: { // 0x5575c9: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L005575cb: { // 0x5575cb: 7d09 JGE 0x005575d6
    if(integer::condition("JGE",flags)) goto L005575d6;
  }
  L005575cd: { // 0x5575cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005575ce: { // 0x5575ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005575cf: { // 0x5575cf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005575d0: { // 0x5575d0: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005575d2: { // 0x5575d2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005575d3: { // 0x5575d3: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005575d6: { // 0x5575d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005575d7: { // 0x5575d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005575d8: { // 0x5575d8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005575d9: { // 0x5575d9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005575db: { // 0x5575db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005575dc: { // 0x5575dc: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0014e180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054e180: { // 0x54e180: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0054e184: { // 0x54e184: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054e185: { // 0x54e185: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054e186: { // 0x54e186: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0054e188: { // 0x54e188: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054e189: { // 0x54e189: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054e18a: { // 0x54e18a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054e18c: { // 0x54e18c: 0f8eaa000000 JLE 0x0054e23c
    if(integer::condition("JLE",flags)) goto L0054e23c;
  }
  L0054e192: { // 0x54e192: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0054e196: { // 0x54e196: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0054e19a: { // 0x54e19a: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054e19e: { // 0x54e19e: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0054e1a0: { // 0x54e1a0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054e1a2: { // 0x54e1a2: 0f8e87000000 JLE 0x0054e22f
    if(integer::condition("JLE",flags)) goto L0054e22f;
  }
  L0054e1a8: { // 0x54e1a8: 668b4702 MOV AX,word ptr [EDI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L0054e1ac: { // 0x54e1ac: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L0054e1af: { // 0x54e1af: 6603c6 ADD AX,SI
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L0054e1b2: { // 0x54e1b2: 6603cd ADD CX,BP
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L0054e1b5: { // 0x54e1b5: 668944242e MOV word ptr [ESP + 0x2e],AX
    m.w16((f.sp+0x0000002eu), (s.ax & 0xffffu));
  }
  L0054e1ba: { // 0x54e1ba: 66894c242c MOV word ptr [ESP + 0x2c],CX
    m.w16((f.sp+0x0000002cu), (s.cx & 0xffffu));
  }
  L0054e1bf: { // 0x54e1bf: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054e1c2: { // 0x54e1c2: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0054e1c5: { // 0x54e1c5: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054e1c8: { // 0x54e1c8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054e1ca: { // 0x54e1ca: 7818 JS 0x0054e1e4
    if(integer::condition("JS",flags)) goto L0054e1e4;
  }
  L0054e1cc: { // 0x54e1cc: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054e1d1: { // 0x54e1d1: 7d11 JGE 0x0054e1e4
    if(integer::condition("JGE",flags)) goto L0054e1e4;
  }
  L0054e1d3: { // 0x54e1d3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054e1d9: { // 0x54e1d9: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054e1dc: { // 0x54e1dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054e1de: { // 0x54e1de: 7404 JZ 0x0054e1e4
    if(integer::condition("JZ",flags)) goto L0054e1e4;
  }
  L0054e1e0: { // 0x54e1e0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054e1e2: { // 0x54e1e2: eb0e JMP 0x0054e1f2
    goto L0054e1f2;
  }
  L0054e1e4: { // 0x54e1e4: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0054e1e8: { // 0x54e1e8: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L0054e1ed: { // 0x54e1ed: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054e1f2: { // 0x54e1f2: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L0054e1f6: { // 0x54e1f6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054e1f8: { // 0x54e1f8: 7406 JZ 0x0054e200
    if(integer::condition("JZ",flags)) goto L0054e200;
  }
  L0054e1fa: { // 0x54e1fa: 837944ff CMP dword ptr [ECX + 0x44],-0x1
    (void)integer::sub(m.r32((s.cx+0x00000044u)),0xffffffffu,32,flags);
  }
  L0054e1fe: { // 0x54e1fe: 7545 JNZ 0x0054e245
    if(integer::condition("JNZ",flags)) goto L0054e245;
  }
  L0054e200: { // 0x54e200: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0054e204: { // 0x54e204: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0054e208: { // 0x54e208: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054e209: { // 0x54e209: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0054e20d: { // 0x54e20d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054e20e: { // 0x54e20e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054e20f: { // 0x54e20f: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0054e213: { // 0x54e213: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054e214: { // 0x54e214: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054e216: { // 0x54e216: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054e218: { // 0x54e218: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054e219: { // 0x54e219: e842a1f2ff CALL 0x00478360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00478360u,5562910u); flags=s.arithmetic_flags;
  }
  L0054e21e: { // 0x54e21e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054e220: { // 0x54e220: 7423 JZ 0x0054e245
    if(integer::condition("JZ",flags)) goto L0054e245;
  }
  L0054e222: { // 0x54e222: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054e226: { // 0x54e226: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0054e227: { // 0x54e227: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0054e229: { // 0x54e229: 0f8c79ffffff JL 0x0054e1a8
    if(integer::condition("JL",flags)) goto L0054e1a8;
  }
  L0054e22f: { // 0x54e22f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0054e233: { // 0x54e233: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0054e234: { // 0x54e234: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0054e236: { // 0x54e236: 0f8c5effffff JL 0x0054e19a
    if(integer::condition("JL",flags)) goto L0054e19a;
  }
  L0054e23c: { // 0x54e23c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054e23d: { // 0x54e23d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054e23e: { // 0x54e23e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054e23f: { // 0x54e23f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054e241: { // 0x54e241: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054e242: { // 0x54e242: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
  L0054e245: { // 0x54e245: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054e246: { // 0x54e246: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054e247: { // 0x54e247: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054e248: { // 0x54e248: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054e24a: { // 0x54e24a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054e24b: { // 0x54e24b: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
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
void f_0007be00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047be00: { // 0x47be00: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047be01: { // 0x47be01: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047be02: { // 0x47be02: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0047be04: { // 0x47be04: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0047be06: { // 0x47be06: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047be07: { // 0x47be07: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047be0c: { // 0x47be0c: e81fb70d00 CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,4701713u); flags=s.arithmetic_flags;
  }
  L0047be11: { // 0x47be11: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047be13: { // 0x47be13: 7505 JNZ 0x0047be1a
    if(integer::condition("JNZ",flags)) goto L0047be1a;
  }
  L0047be15: { // 0x47be15: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047be16: { // 0x47be16: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047be18: { // 0x47be18: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047be19: { // 0x47be19: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047be1a: { // 0x47be1a: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0047be1d: { // 0x47be1d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047be1f: { // 0x47be1f: 7c1b JL 0x0047be3c
    if(integer::condition("JL",flags)) goto L0047be3c;
  }
  L0047be21: { // 0x47be21: 3b052089a200 CMP EAX,dword ptr [0x00a28920]
    (void)integer::sub(s.ax,m.r32((0x00a28920u)),32,flags);
  }
  L0047be27: { // 0x47be27: 7d13 JGE 0x0047be3c
    if(integer::condition("JGE",flags)) goto L0047be3c;
  }
  L0047be29: { // 0x47be29: 8b0d1489a200 MOV ECX,dword ptr [0x00a28914]
    s.cx = m.r32((0x00a28914u));
  }
  L0047be2f: { // 0x47be2f: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0047be32: { // 0x47be32: 8a82d5020000 MOV AL,byte ptr [EDX + 0x2d5]
    s.ax = with_al(s.ax, m.r8((s.dx+0x000002d5u)));
  }
  L0047be38: { // 0x47be38: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047be3a: { // 0x47be3a: 7475 JZ 0x0047beb1
    if(integer::condition("JZ",flags)) goto L0047beb1;
  }
  L0047be3c: { // 0x47be3c: 8a871c010000 MOV AL,byte ptr [EDI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  L0047be42: { // 0x47be42: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047be44: { // 0x47be44: 756b JNZ 0x0047beb1
    if(integer::condition("JNZ",flags)) goto L0047beb1;
  }
  L0047be46: { // 0x47be46: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0047be4c: { // 0x47be4c: f6c405 TEST AH,0x5
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000005u),8,flags);
  }
  L0047be4f: { // 0x47be4f: 7560 JNZ 0x0047beb1
    if(integer::condition("JNZ",flags)) goto L0047beb1;
  }
  L0047be51: { // 0x47be51: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L0047be56: { // 0x47be56: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047be58: { // 0x47be58: 7452 JZ 0x0047beac
    if(integer::condition("JZ",flags)) goto L0047beac;
  }
  L0047be5a: { // 0x47be5a: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L0047be60: { // 0x47be60: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047be62: { // 0x47be62: 7419 JZ 0x0047be7d
    if(integer::condition("JZ",flags)) goto L0047be7d;
  }
  L0047be64: { // 0x47be64: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0047be66: { // 0x47be66: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0047be68: { // 0x47be68: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4701803u); flags=s.arithmetic_flags;
  }
  L0047be6b: { // 0x47be6b: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L0047be6e: { // 0x47be6e: 7409 JZ 0x0047be79
    if(integer::condition("JZ",flags)) goto L0047be79;
  }
  L0047be70: { // 0x47be70: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047be73: { // 0x47be73: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047be75: { // 0x47be75: 75ed JNZ 0x0047be64
    if(integer::condition("JNZ",flags)) goto L0047be64;
  }
  L0047be77: { // 0x47be77: eb04 JMP 0x0047be7d
    goto L0047be7d;
  }
  L0047be79: { // 0x47be79: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047be7b: { // 0x47be7b: 7534 JNZ 0x0047beb1
    if(integer::condition("JNZ",flags)) goto L0047beb1;
  }
  L0047be7d: { // 0x47be7d: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L0047be82: { // 0x47be82: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047be84: { // 0x47be84: 7426 JZ 0x0047beac
    if(integer::condition("JZ",flags)) goto L0047beac;
  }
  L0047be86: { // 0x47be86: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L0047be8c: { // 0x47be8c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047be8e: { // 0x47be8e: 741c JZ 0x0047beac
    if(integer::condition("JZ",flags)) goto L0047beac;
  }
  L0047be90: { // 0x47be90: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0047be92: { // 0x47be92: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0047be94: { // 0x47be94: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4701847u); flags=s.arithmetic_flags;
  }
  L0047be97: { // 0x47be97: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L0047be9a: { // 0x47be9a: 740c JZ 0x0047bea8
    if(integer::condition("JZ",flags)) goto L0047bea8;
  }
  L0047be9c: { // 0x47be9c: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047be9f: { // 0x47be9f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047bea1: { // 0x47bea1: 75ed JNZ 0x0047be90
    if(integer::condition("JNZ",flags)) goto L0047be90;
  }
  L0047bea3: { // 0x47bea3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047bea4: { // 0x47bea4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047bea6: { // 0x47bea6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047bea7: { // 0x47bea7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047bea8: { // 0x47bea8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047beaa: { // 0x47beaa: 7505 JNZ 0x0047beb1
    if(integer::condition("JNZ",flags)) goto L0047beb1;
  }
  L0047beac: { // 0x47beac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047bead: { // 0x47bead: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047beaf: { // 0x47beaf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047beb0: { // 0x47beb0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047beb1: { // 0x47beb1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047beb2: { // 0x47beb2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047beb4: { // 0x47beb4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047beb5: { // 0x47beb5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0029c090(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069c090: { // 0x69c090: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0069c093: { // 0x69c093: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069c094: { // 0x69c094: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069c095: { // 0x69c095: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069c096: { // 0x69c096: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L0069c09a: { // 0x69c09a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069c09b: { // 0x69c09b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0069c09d: { // 0x69c09d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c09e: { // 0x69c09e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c0a4: { // 0x69c0a4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c0a6: { // 0x69c0a6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c0a8: { // 0x69c0a8: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0069c0ab: { // 0x69c0ab: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c0ac: { // 0x69c0ac: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c0b2: { // 0x69c0b2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c0b4: { // 0x69c0b4: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c0b7: { // 0x69c0b7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c0ba: { // 0x69c0ba: 0fbff1 MOVSX ESI,CX
    s.si = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0069c0bd: { // 0x69c0bd: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0069c0c0: { // 0x69c0c0: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0069c0c5: { // 0x69c0c5: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L0069c0ca: { // 0x69c0ca: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069c0ce: { // 0x69c0ce: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0069c0d2: { // 0x69c0d2: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c0d5: { // 0x69c0d5: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c0d8: { // 0x69c0d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069c0d9: { // 0x69c0d9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c0de: { // 0x69c0de: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0069c0e2: { // 0x69c0e2: 81c680000000 ADD ESI,0x80
    s.si = integer::add(s.si,0x00000080u,32,flags);
  }
  L0069c0e8: { // 0x69c0e8: 81c780000000 ADD EDI,0x80
    s.di = integer::add(s.di,0x00000080u,32,flags);
  }
  L0069c0ee: { // 0x69c0ee: e80d94eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6930675u); flags=s.arithmetic_flags;
  }
  L0069c0f3: { // 0x69c0f3: 8b9840010000 MOV EBX,dword ptr [EAX + 0x140]
    s.bx = m.r32((s.ax+0x00000140u));
  }
  L0069c0f9: { // 0x69c0f9: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0069c0fd: { // 0x69c0fd: c1eb0c SHR EBX,0xc
    s.bx = integer::shift(s.bx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L0069c100: { // 0x69c100: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c101: { // 0x69c101: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c106: { // 0x69c106: 80e301 AND BL,0x1
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags));
  }
  L0069c109: { // 0x69c109: e8f293eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6930702u); flags=s.arithmetic_flags;
  }
  L0069c10e: { // 0x69c10e: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0069c115: { // 0x69c115: 81c600060000 ADD ESI,0x600
    s.si = integer::add(s.si,0x00000600u,32,flags);
  }
  L0069c11b: { // 0x69c11b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069c11d: { // 0x69c11d: 8daf00060000 LEA EBP,[EDI + 0x600]
    s.bp = (s.di+0x00000600u);
  }
  L0069c123: { // 0x69c123: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0069c127: { // 0x69c127: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0069c129: { // 0x69c129: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0069c12d: { // 0x69c12d: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0069c131: { // 0x69c131: 83ef08 SUB EDI,0x8
    s.di = integer::sub(s.di,0x00000008u,32,flags);
  }
  L0069c134: { // 0x69c134: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0069c138: { // 0x69c138: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069c13a: { // 0x69c13a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c13b: { // 0x69c13b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c141: { // 0x69c141: 83ed08 SUB EBP,0x8
    s.bp = integer::sub(s.bp,0x00000008u,32,flags);
  }
  L0069c144: { // 0x69c144: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c146: { // 0x69c146: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c149: { // 0x69c149: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0069c14e: { // 0x69c14e: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0069c150: { // 0x69c150: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c151: { // 0x69c151: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c157: { // 0x69c157: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c159: { // 0x69c159: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0069c15d: { // 0x69c15d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c160: { // 0x69c160: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0069c165: { // 0x69c165: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0069c169: { // 0x69c169: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0069c16d: { // 0x69c16d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069c16e: { // 0x69c16e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c173: { // 0x69c173: e88893eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6930808u); flags=s.arithmetic_flags;
  }
  L0069c178: { // 0x69c178: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0069c17f: { // 0x69c17f: 2b4c2418 SUB ECX,dword ptr [ESP + 0x18]
    s.cx = integer::sub(s.cx,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0069c183: { // 0x69c183: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0069c185: { // 0x69c185: 740f JZ 0x0069c196
    if(integer::condition("JZ",flags)) goto L0069c196;
  }
  L0069c187: { // 0x69c187: 8b8040010000 MOV EAX,dword ptr [EAX + 0x140]
    s.ax = m.r32((s.ax+0x00000140u));
  }
  L0069c18d: { // 0x69c18d: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L0069c190: { // 0x69c190: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  L0069c193: { // 0x69c193: 8d0c81 LEA ECX,[ECX + EAX*0x4]
    s.cx = (s.cx+(s.ax * 0x00000004u));
  }
  L0069c196: { // 0x69c196: c1e107 SHL ECX,0x7
    s.cx = integer::shift(s.cx,0x00000007u,32,flags,integer::Shift::left);
  }
  L0069c199: { // 0x69c199: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069c19b: { // 0x69c19b: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0069c19d: { // 0x69c19d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069c19f: { // 0x69c19f: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0069c1a1: { // 0x69c1a1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c1a2: { // 0x69c1a2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c1a8: { // 0x69c1a8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c1aa: { // 0x69c1aa: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c1ac: { // 0x69c1ac: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069c1ae: { // 0x69c1ae: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c1af: { // 0x69c1af: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c1b5: { // 0x69c1b5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c1b7: { // 0x69c1b7: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069c1bb: { // 0x69c1bb: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c1be: { // 0x69c1be: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c1c1: { // 0x69c1c1: 663bca CMP CX,DX
    (void)integer::sub((s.cx & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  L0069c1c4: { // 0x69c1c4: 668b4c2432 MOV CX,word ptr [ESP + 0x32]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000032u)));
  }
  L0069c1c9: { // 0x69c1c9: 7f05 JG 0x0069c1d0
    if(integer::condition("JG",flags)) goto L0069c1d0;
  }
  L0069c1cb: { // 0x69c1cb: 663bc1 CMP AX,CX
    (void)integer::sub((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags);
  }
  L0069c1ce: { // 0x69c1ce: 7e17 JLE 0x0069c1e7
    if(integer::condition("JLE",flags)) goto L0069c1e7;
  }
  L0069c1d0: { // 0x69c1d0: 6639542410 CMP word ptr [ESP + 0x10],DX
    (void)integer::sub(m.r16((f.sp+0x00000010u)),(s.dx & 0xffffu),16,flags);
  }
  L0069c1d5: { // 0x69c1d5: 0f8552ffffff JNZ 0x0069c12d
    if(integer::condition("JNZ",flags)) goto L0069c12d;
  }
  L0069c1db: { // 0x69c1db: 66394c2412 CMP word ptr [ESP + 0x12],CX
    (void)integer::sub(m.r16((f.sp+0x00000012u)),(s.cx & 0xffffu),16,flags);
  }
  L0069c1e0: { // 0x69c1e0: 7419 JZ 0x0069c1fb
    if(integer::condition("JZ",flags)) goto L0069c1fb;
  }
  L0069c1e2: { // 0x69c1e2: e946ffffff JMP 0x0069c12d
    goto L0069c12d;
  }
  L0069c1e7: { // 0x69c1e7: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0069c1eb: { // 0x69c1eb: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0069c1ef: { // 0x69c1ef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c1f0: { // 0x69c1f0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c1f1: { // 0x69c1f1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c1f2: { // 0x69c1f2: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c1f4: { // 0x69c1f4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c1f5: { // 0x69c1f5: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0069c1f8: { // 0x69c1f8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069c1fb: { // 0x69c1fb: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0069c1ff: { // 0x69c1ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c200: { // 0x69c200: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c201: { // 0x69c201: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c202: { // 0x69c202: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0069c204: { // 0x69c204: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c205: { // 0x69c205: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0069c208: { // 0x69c208: c20800 RET 0x8
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
void invoke(Memory& m,State& s,Frame& f,std::uint32_t target,std::uint32_t continuation) {
  f.push(m,continuation);
  Frame child{f.sp,f.sp,continuation};
  switch(target) {
    case 0x00557530u: f_00157530(m,s,child,{}); break;
    case 0x0054e180u: f_0014e180(m,s,child,{}); break;
    case 0x00478360u: f_00078360(m,s,child,{}); break;
    case 0x0047be00u: f_0007be00(m,s,child,{}); break;
    case 0x0069c090u: f_0029c090(m,s,child,{}); break;
    case 0x00545500u: f_00145500(m,s,child,{}); break;
    default: throw std::domain_error("B517 reached an unclosed 14d770 helper");
  }
  f.sp=child.sp;
}
}
std::uint32_t fun_0054d770(Memory& original,const Inputs& i) {
  std::array<std::uint8_t,0x8000> stack{};
  constexpr std::uint32_t base=0x7d100000u,entry=base+0x6004u,ret=0x76543210u;
  leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));
  Memory m=original; m.add(local);
  State s{}; s.ax=i.ax; s.cx=i.cx; s.dx=i.dx; s.arithmetic_flags=i.arithmetic_flags; s.fp=i.fp;
  Frame f{entry,entry,ret}; m.w32(entry,ret);
  for(unsigned k=0;k<i.arg.size();++k)m.w32(entry+4u+4u*k,i.arg[k]);
  m.w32(entry-8u,i.stack_minus8);m.w32(((entry-4u)&~7u)-8u,i.stack_minus8);
  f_0014d770(m,s,f,Operations{});
  i.fp=s.fp; for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(entry+4u+4u*k);
  return s.ax;
}
}
