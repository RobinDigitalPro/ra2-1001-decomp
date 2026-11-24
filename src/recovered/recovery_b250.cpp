#include "recovered/recovery_b250_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b250 {
namespace {
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_0014d770(Memory&,State&,Frame&,const Operations&);
void f_00157530(Memory&,State&,Frame&,const Operations&);
void f_0014e180(Memory&,State&,Frame&,const Operations&);
void f_00078360(Memory&,State&,Frame&,const Operations&);
void f_0007be00(Memory&,State&,Frame&,const Operations&);
void f_0029c090(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00093780(Memory&,State&,Frame&,const Operations&);
void f_000938b0(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_001d2e50(Memory&,State&,Frame&,const Operations&);
void f_001ca970(Memory&,State&,Frame&,const Operations&);
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_0000ffd0(Memory&,State&,Frame&,const Operations&);
void f_0025a120(Memory&,State&,Frame&,const Operations&);
void f_001cbf20(Memory&,State&,Frame&,const Operations&);
void f_00074d00(Memory&,State&,Frame&,const Operations&);
void f_00074ab0(Memory&,State&,Frame&,const Operations&);
void f_00298660(Memory&,State&,Frame&,const Operations&);
void f_002a0410(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x0062fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x0062fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI,0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX,0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x0062fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x0062fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI,EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x0062fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x0062fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x0062fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x0062fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI,dword ptr [EDX + ECX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX,[EDX + ECX*0x4 + 0xc]
    s.ax = (s.dx+(s.cx * 0x00000004u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX,dword ptr [EDX + ECX*0x4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI,dword ptr [EDX + EAX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX,0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x0062fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 0x4],0x0
    m.w32((s.dx+0x00000004u), 0x00000000u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX,0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x0062fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 0x8],0x0
    m.w32((s.dx+0x00000008u), 0x00000000u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX,EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x0062fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
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
void f_00093780(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493780: { // 0x493780: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00493783: { // 0x493783: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493784: { // 0x493784: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493785: { // 0x493785: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00493787: { // 0x493787: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493788: { // 0x493788: 668b460c MOV AX,word ptr [ESI + 0xc]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000000cu)));
  }
  L0049378c: { // 0x49378c: 8d7e0c LEA EDI,[ESI + 0xc]
    s.di = (s.si+0x0000000cu);
  }
  L0049378f: { // 0x49378f: 663b05009f8300 CMP AX,word ptr [0x00839f00]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00839f00u)),16,flags);
  }
  L00493796: { // 0x493796: 750d JNZ 0x004937a5
    if(integer::condition("JNZ",flags)) goto L004937a5;
  }
  L00493798: { // 0x493798: 668b4f02 MOV CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000002u)));
  }
  L0049379c: { // 0x49379c: 663b0d029f8300 CMP CX,word ptr [0x00839f02]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00839f02u)),16,flags);
  }
  L004937a3: { // 0x4937a3: 7439 JZ 0x004937de
    if(integer::condition("JZ",flags)) goto L004937de;
  }
  L004937a5: { // 0x4937a5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004937a7: { // 0x4937a7: e8b4020000 CALL 0x00493a60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493a60u,4798380u); flags=s.arithmetic_flags;
  }
  L004937ac: { // 0x4937ac: 8b15009f8300 MOV EDX,dword ptr [0x00839f00]
    s.dx = m.r32((0x00839f00u));
  }
  L004937b2: { // 0x4937b2: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L004937b4: { // 0x4937b4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004937b6: { // 0x4937b6: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L004937b9: { // 0x4937b9: 7423 JZ 0x004937de
    if(integer::condition("JZ",flags)) goto L004937de;
  }
  L004937bb: { // 0x4937bb: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L004937be: { // 0x4937be: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L004937c1: { // 0x4937c1: 7412 JZ 0x004937d5
    if(integer::condition("JZ",flags)) goto L004937d5;
  }
  L004937c3: { // 0x4937c3: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L004937c9: { // 0x4937c9: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004937cb: { // 0x4937cb: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004937cd: { // 0x4937cd: 7d04 JGE 0x004937d3
    if(integer::condition("JGE",flags)) goto L004937d3;
  }
  L004937cf: { // 0x4937cf: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L004937d1: { // 0x4937d1: eb02 JMP 0x004937d5
    goto L004937d5;
  }
  L004937d3: { // 0x4937d3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004937d5: { // 0x4937d5: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004937d8: { // 0x4937d8: c706ffffffff MOV dword ptr [ESI],0xffffffff
    m.w32((s.si), 0xffffffffu);
  }
  L004937de: { // 0x4937de: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L004937e2: { // 0x4937e2: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L004937e6: { // 0x4937e6: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L004937e8: { // 0x4937e8: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L004937ec: { // 0x4937ec: e8bf000000 CALL 0x004938b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004938b0u,4798449u); flags=s.arithmetic_flags;
  }
  L004937f1: { // 0x4937f1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004937f3: { // 0x4937f3: 0f84a8000000 JZ 0x004938a1
    if(integer::condition("JZ",flags)) goto L004938a1;
  }
  L004937f9: { // 0x4937f9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004937fa: { // 0x4937fa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004937ff: { // 0x4937ff: e8fc1c0b00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4798468u); flags=s.arithmetic_flags;
  }
  L00493804: { // 0x493804: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049380a: { // 0x49380a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049380b: { // 0x49380b: e800cc2000 CALL 0x006a0410
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0410u,4798480u); flags=s.arithmetic_flags;
  }
  L00493810: { // 0x493810: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00493814: { // 0x493814: 68feffff7f PUSH 0x7ffffffe
    f.push(m,0x7ffffffeu);
  }
  L00493819: { // 0x493819: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L0049381b: { // 0x49381b: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00493820: { // 0x493820: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00493826: { // 0x493826: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00493828: { // 0x493828: dd80d8120000 FLD double ptr [EAX + 0x12d8]
    const auto address=(s.ax+0x000012d8u);
    s.fp.load64(read64(m,address));
  }
  L0049382e: { // 0x49382e: dc0d40817800 FMUL double ptr [0x00788140]
    const auto address=(0x00788140u);
    s.fp.multiply64(read64(m,address));
  }
  L00493834: { // 0x493834: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L0049383a: { // 0x49383a: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0049383e: { // 0x49383e: dd80d8120000 FLD double ptr [EAX + 0x12d8]
    const auto address=(s.ax+0x000012d8u);
    s.fp.load64(read64(m,address));
  }
  L00493844: { // 0x493844: dc0dd0967800 FMUL double ptr [0x007896d0]
    const auto address=(0x007896d0u);
    s.fp.multiply64(read64(m,address));
  }
  L0049384a: { // 0x49384a: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0049384e: { // 0x49384e: e8edc51900 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,4798547u); flags=s.arithmetic_flags;
  }
  L00493853: { // 0x493853: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L00493857: { // 0x493857: dc642410 FSUB double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.subtract64(read64(m,address));
  }
  L0049385b: { // 0x49385b: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0049385f: { // 0x49385f: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L00493865: { // 0x493865: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L00493869: { // 0x493869: dc0d80727800 FMUL double ptr [0x00787280]
    const auto address=(0x00787280u);
    s.fp.multiply64(read64(m,address));
  }
  L0049386f: { // 0x49386f: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L00493871: { // 0x493871: dc442410 FADD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L00493875: { // 0x493875: e8d6712d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4798586u); flags=s.arithmetic_flags;
  }
  L0049387a: { // 0x49387a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0049387e: { // 0x49387e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00493880: { // 0x493880: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L00493882: { // 0x493882: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00493885: { // 0x493885: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00493888: { // 0x493888: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049388a: { // 0x49388a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0049388d: { // 0x49388d: 7507 JNZ 0x00493896
    if(integer::condition("JNZ",flags)) goto L00493896;
  }
  L0049388f: { // 0x49388f: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00493894: { // 0x493894: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00493896: { // 0x493896: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493897: { // 0x493897: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493898: { // 0x493898: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0049389a: { // 0x49389a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049389b: { // 0x49389b: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0049389e: { // 0x49389e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004938a1: { // 0x4938a1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004938a2: { // 0x4938a2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004938a3: { // 0x4938a3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004938a5: { // 0x4938a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004938a6: { // 0x4938a6: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L004938a9: { // 0x4938a9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000938b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004938b0: { // 0x4938b0: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L004938b3: { // 0x4938b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004938b4: { // 0x4938b4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004938b5: { // 0x4938b5: 8b2dc483a200 MOV EBP,dword ptr [0x00a283c4]
    s.bp = m.r32((0x00a283c4u));
  }
  L004938bb: { // 0x4938bb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004938bc: { // 0x4938bc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004938bd: { // 0x4938bd: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004938bf: { // 0x4938bf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004938c1: { // 0x4938c1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004938c2: { // 0x4938c2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004938c7: { // 0x4938c7: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L004938cb: { // 0x4938cb: c705c483a20000000000 MOV dword ptr [0x00a283c4],0x0
    m.w32((0x00a283c4u), 0x00000000u);
  }
  L004938d5: { // 0x4938d5: e8763b0c00 CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,4798682u); flags=s.arithmetic_flags;
  }
  L004938da: { // 0x4938da: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004938dc: { // 0x4938dc: 0f846b010000 JZ 0x00493a4d
    if(integer::condition("JZ",flags)) goto L00493a4d;
  }
  L004938e2: { // 0x4938e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004938e3: { // 0x4938e3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004938e8: { // 0x4938e8: e8131c0b00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4798701u); flags=s.arithmetic_flags;
  }
  L004938ed: { // 0x4938ed: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004938ef: { // 0x4938ef: 837f44ff CMP dword ptr [EDI + 0x44],-0x1
    (void)integer::sub(m.r32((s.di+0x00000044u)),0xffffffffu,32,flags);
  }
  L004938f3: { // 0x4938f3: 0f8554010000 JNZ 0x00493a4d
    if(integer::condition("JNZ",flags)) goto L00493a4d;
  }
  L004938f9: { // 0x4938f9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004938fa: { // 0x4938fa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004938ff: { // 0x4938ff: e8fc1b0b00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4798724u); flags=s.arithmetic_flags;
  }
  L00493904: { // 0x493904: 8b88ec000000 MOV ECX,dword ptr [EAX + 0xec]
    s.cx = m.r32((s.ax+0x000000ecu));
  }
  L0049390a: { // 0x49390a: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  L0049390d: { // 0x49390d: 689c000000 PUSH 0x9c
    f.push(m,0x0000009cu);
  }
  L00493912: { // 0x493912: 751d JNZ 0x00493931
    if(integer::condition("JNZ",flags)) goto L00493931;
  }
  L00493914: { // 0x493914: e83ea02d00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4798745u); flags=s.arithmetic_flags;
  }
  L00493919: { // 0x493919: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0049391c: { // 0x49391c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049391e: { // 0x49391e: 7434 JZ 0x00493954
    if(integer::condition("JZ",flags)) goto L00493954;
  }
  L00493920: { // 0x493920: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00493926: { // 0x493926: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00493928: { // 0x493928: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493929: { // 0x493929: 8b91f8000000 MOV EDX,dword ptr [ECX + 0xf8]
    s.dx = m.r32((s.cx+0x000000f8u));
  }
  L0049392f: { // 0x49392f: eb1b JMP 0x0049394c
    goto L0049394c;
  }
  L00493931: { // 0x493931: e821a02d00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4798774u); flags=s.arithmetic_flags;
  }
  L00493936: { // 0x493936: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00493939: { // 0x493939: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049393b: { // 0x49393b: 7417 JZ 0x00493954
    if(integer::condition("JZ",flags)) goto L00493954;
  }
  L0049393d: { // 0x49393d: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00493943: { // 0x493943: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00493945: { // 0x493945: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493946: { // 0x493946: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L0049394c: { // 0x49394c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049394d: { // 0x49394d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049394f: { // 0x49394f: e8fcf41300 CALL 0x005d2e50
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d2e50u,4798804u); flags=s.arithmetic_flags;
  }
  L00493954: { // 0x493954: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00493958: { // 0x493958: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0049395a: { // 0x49395a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049395b: { // 0x49395b: e8a013feff CALL 0x00474d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474d00u,4798816u); flags=s.arithmetic_flags;
  }
  L00493960: { // 0x493960: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L00493964: { // 0x493964: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00493966: { // 0x493966: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00493967: { // 0x493967: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00493969: { // 0x493969: e84211feff CALL 0x00474ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474ab0u,4798830u); flags=s.arithmetic_flags;
  }
  L0049396e: { // 0x49396e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00493971: { // 0x493971: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00493973: { // 0x493973: 0f8e8c000000 JLE 0x00493a05
    if(integer::condition("JLE",flags)) goto L00493a05;
  }
  L00493979: { // 0x493979: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L0049397c: { // 0x49397c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049397e: { // 0x49397e: 0f8e81000000 JLE 0x00493a05
    if(integer::condition("JLE",flags)) goto L00493a05;
  }
  L00493984: { // 0x493984: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L00493987: { // 0x493987: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00493989: { // 0x493989: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0049398d: { // 0x49398d: 7e65 JLE 0x004939f4
    if(integer::condition("JLE",flags)) goto L004939f4;
  }
  L0049398f: { // 0x49398f: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00493992: { // 0x493992: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00493994: { // 0x493994: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00493998: { // 0x493998: 7e5a JLE 0x004939f4
    if(integer::condition("JLE",flags)) goto L004939f4;
  }
  L0049399a: { // 0x49399a: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049399c: { // 0x49399c: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L0049399e: { // 0x49399e: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004939a1: { // 0x4939a1: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L004939a4: { // 0x4939a4: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L004939a7: { // 0x4939a7: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L004939a9: { // 0x4939a9: 7e06 JLE 0x004939b1
    if(integer::condition("JLE",flags)) goto L004939b1;
  }
  L004939ab: { // 0x4939ab: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L004939ad: { // 0x4939ad: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  L004939af: { // 0x4939af: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004939b1: { // 0x4939b1: 8b7604 MOV ESI,dword ptr [ESI + 0x4]
    s.si = m.r32((s.si+0x00000004u));
  }
  L004939b4: { // 0x4939b4: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L004939b6: { // 0x4939b6: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L004939ba: { // 0x4939ba: 7e06 JLE 0x004939c2
    if(integer::condition("JLE",flags)) goto L004939c2;
  }
  L004939bc: { // 0x4939bc: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L004939be: { // 0x4939be: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004939c0: { // 0x4939c0: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L004939c2: { // 0x4939c2: 8d342f LEA ESI,[EDI + EBP*0x1]
    s.si = (s.di+(s.bp * 0x00000001u));
  }
  L004939c5: { // 0x4939c5: 8d2c0b LEA EBP,[EBX + ECX*0x1]
    s.bp = (s.bx+(s.cx * 0x00000001u));
  }
  L004939c8: { // 0x4939c8: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L004939ca: { // 0x4939ca: 7d0a JGE 0x004939d6
    if(integer::condition("JGE",flags)) goto L004939d6;
  }
  L004939cc: { // 0x4939cc: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L004939d0: { // 0x4939d0: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004939d2: { // 0x4939d2: 8d5c3701 LEA EBX,[EDI + ESI*0x1 + 0x1]
    s.bx = (s.di+(s.si * 0x00000001u)+0x00000001u);
  }
  L004939d6: { // 0x4939d6: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L004939da: { // 0x4939da: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L004939de: { // 0x4939de: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L004939e0: { // 0x4939e0: 8d3c10 LEA EDI,[EAX + EDX*0x1]
    s.di = (s.ax+(s.dx * 0x00000001u));
  }
  L004939e3: { // 0x4939e3: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L004939e5: { // 0x4939e5: 7d05 JGE 0x004939ec
    if(integer::condition("JGE",flags)) goto L004939ec;
  }
  L004939e7: { // 0x4939e7: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L004939e9: { // 0x4939e9: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004939ea: { // 0x4939ea: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004939ec: { // 0x4939ec: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L004939f0: { // 0x4939f0: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L004939f2: { // 0x4939f2: eb1c JMP 0x00493a10
    goto L00493a10;
  }
  L004939f4: { // 0x4939f4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004939f6: { // 0x4939f6: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004939f9: { // 0x4939f9: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L004939fc: { // 0x4939fc: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L004939ff: { // 0x4939ff: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00493a03: { // 0x493a03: eb0b JMP 0x00493a10
    goto L00493a10;
  }
  L00493a05: { // 0x493a05: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00493a07: { // 0x493a07: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00493a0a: { // 0x493a0a: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  L00493a0d: { // 0x493a0d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00493a10: { // 0x493a10: 8b3570198200 MOV ESI,dword ptr [0x00821970]
    s.si = m.r32((0x00821970u));
  }
  L00493a16: { // 0x493a16: 8b1d74198200 MOV EBX,dword ptr [0x00821974]
    s.bx = m.r32((0x00821974u));
  }
  L00493a1c: { // 0x493a1c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00493a1e: { // 0x493a1e: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L00493a20: { // 0x493a20: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00493a23: { // 0x493a23: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00493a25: { // 0x493a25: 8bf4 MOV ESI,ESP
    s.si = f.sp;
  }
  L00493a27: { // 0x493a27: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L00493a29: { // 0x493a29: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00493a2f: { // 0x493a2f: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L00493a32: { // 0x493a32: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00493a35: { // 0x493a35: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00493a38: { // 0x493a38: e8234c2000 CALL 0x00698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,4799037u); flags=s.arithmetic_flags;
  }
  L00493a3d: { // 0x493a3d: 892dc483a200 MOV dword ptr [0x00a283c4],EBP
    m.w32((0x00a283c4u), s.bp);
  }
  L00493a43: { // 0x493a43: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00493a45: { // 0x493a45: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493a46: { // 0x493a46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493a47: { // 0x493a47: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493a48: { // 0x493a48: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493a49: { // 0x493a49: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00493a4c: { // 0x493a4c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00493a4d: { // 0x493a4d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493a4e: { // 0x493a4e: 892dc483a200 MOV dword ptr [0x00a283c4],EBP
    m.w32((0x00a283c4u), s.bp);
  }
  L00493a54: { // 0x493a54: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493a55: { // 0x493a55: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493a56: { // 0x493a56: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00493a58: { // 0x493a58: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493a59: { // 0x493a59: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00493a5c: { // 0x493a5c: c3 RET
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
void f_001d2e50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d2e50: { // 0x5d2e50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005d2e53: { // 0x5d2e53: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d2e54: { // 0x5d2e54: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005d2e56: { // 0x5d2e56: e8157bffff CALL 0x005ca970
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ca970u,6106715u); flags=s.arithmetic_flags;
  }
  L005d2e5b: { // 0x5d2e5b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005d2e5f: { // 0x5d2e5f: c706b4277900 MOV dword ptr [ESI],0x7927b4
    m.w32((s.si), 0x007927b4u);
  }
  L005d2e65: { // 0x5d2e65: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
  L005d2e6b: { // 0x5d2e6b: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L005d2e6e: { // 0x5d2e6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d2e6f: { // 0x5d2e6f: c74608ac277900 MOV dword ptr [ESI + 0x8],0x7927ac
    m.w32((s.si+0x00000008u), 0x007927acu);
  }
  L005d2e76: { // 0x5d2e76: c70090277900 MOV dword ptr [EAX],0x792790
    m.w32((s.ax), 0x00792790u);
  }
  L005d2e7c: { // 0x5d2e7c: c7460c88277900 MOV dword ptr [ESI + 0xc],0x792788
    m.w32((s.si+0x0000000cu), 0x00792788u);
  }
  L005d2e83: { // 0x5d2e83: e848d1e3ff CALL 0x0040ffd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ffd0u,6106760u); flags=s.arithmetic_flags;
  }
  L005d2e88: { // 0x5d2e88: a14888a200 MOV EAX,[0x00a28848]
    s.ax = m.r32((0x00a28848u));
  }
  L005d2e8d: { // 0x5d2e8d: 8b0d5088a200 MOV ECX,dword ptr [0x00a28850]
    s.cx = m.r32((0x00a28850u));
  }
  L005d2e93: { // 0x5d2e93: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005d2e95: { // 0x5d2e95: 7c2f JL 0x005d2ec6
    if(integer::condition("JL",flags)) goto L005d2ec6;
  }
  L005d2e97: { // 0x5d2e97: 8a0d4d88a200 MOV CL,byte ptr [0x00a2884d]
    s.cx = with_al(s.cx, m.r8((0x00a2884du)));
  }
  L005d2e9d: { // 0x5d2e9d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005d2e9f: { // 0x5d2e9f: 7504 JNZ 0x005d2ea5
    if(integer::condition("JNZ",flags)) goto L005d2ea5;
  }
  L005d2ea1: { // 0x5d2ea1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d2ea3: { // 0x5d2ea3: 7539 JNZ 0x005d2ede
    if(integer::condition("JNZ",flags)) goto L005d2ede;
  }
  L005d2ea5: { // 0x5d2ea5: 8b0d5488a200 MOV ECX,dword ptr [0x00a28854]
    s.cx = m.r32((0x00a28854u));
  }
  L005d2eab: { // 0x5d2eab: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005d2ead: { // 0x5d2ead: 7e2f JLE 0x005d2ede
    if(integer::condition("JLE",flags)) goto L005d2ede;
  }
  L005d2eaf: { // 0x5d2eaf: 8b154088a200 MOV EDX,dword ptr [0x00a28840]
    s.dx = m.r32((0x00a28840u));
  }
  L005d2eb5: { // 0x5d2eb5: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005d2eb7: { // 0x5d2eb7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005d2eb9: { // 0x5d2eb9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d2eba: { // 0x5d2eba: b94088a200 MOV ECX,0xa28840
    s.cx = 0x00a28840u;
  }
  L005d2ebf: { // 0x5d2ebf: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6106818u); flags=s.arithmetic_flags;
  }
  L005d2ec2: { // 0x5d2ec2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d2ec4: { // 0x5d2ec4: 7418 JZ 0x005d2ede
    if(integer::condition("JZ",flags)) goto L005d2ede;
  }
  L005d2ec6: { // 0x5d2ec6: 8b0d5088a200 MOV ECX,dword ptr [0x00a28850]
    s.cx = m.r32((0x00a28850u));
  }
  L005d2ecc: { // 0x5d2ecc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005d2ece: { // 0x5d2ece: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005d2ecf: { // 0x5d2ecf: 890d5088a200 MOV dword ptr [0x00a28850],ECX
    m.w32((0x00a28850u), s.cx);
  }
  L005d2ed5: { // 0x5d2ed5: 8b0d4488a200 MOV ECX,dword ptr [0x00a28844]
    s.cx = m.r32((0x00a28844u));
  }
  L005d2edb: { // 0x5d2edb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005d2ede: { // 0x5d2ede: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005d2ee2: { // 0x5d2ee2: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L005d2ee5: { // 0x5d2ee5: 663b15f0aba500 CMP DX,word ptr [0x00a5abf0]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a5abf0u)),16,flags);
  }
  L005d2eec: { // 0x5d2eec: 750d JNZ 0x005d2efb
    if(integer::condition("JNZ",flags)) goto L005d2efb;
  }
  L005d2eee: { // 0x5d2eee: 668b4802 MOV CX,word ptr [EAX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.ax+0x00000002u)));
  }
  L005d2ef2: { // 0x5d2ef2: 663b0df2aba500 CMP CX,word ptr [0x00a5abf2]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a5abf2u)),16,flags);
  }
  L005d2ef9: { // 0x5d2ef9: 744b JZ 0x005d2f46
    if(integer::condition("JZ",flags)) goto L005d2f46;
  }
  L005d2efb: { // 0x5d2efb: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005d2eff: { // 0x5d2eff: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005d2f01: { // 0x5d2f01: 8915f42b7d00 MOV dword ptr [0x007d2bf4],EDX
    m.w32((0x007d2bf4u), s.dx);
  }
  L005d2f07: { // 0x5d2f07: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L005d2f0f: { // 0x5d2f0f: 0fbf08 MOVSX ECX,word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L005d2f12: { // 0x5d2f12: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L005d2f16: { // 0x5d2f16: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L005d2f19: { // 0x5d2f19: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L005d2f1f: { // 0x5d2f1f: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L005d2f23: { // 0x5d2f23: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L005d2f26: { // 0x5d2f26: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L005d2f2a: { // 0x5d2f2a: 81c280000000 ADD EDX,0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L005d2f30: { // 0x5d2f30: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d2f31: { // 0x5d2f31: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005d2f33: { // 0x5d2f33: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005d2f37: { // 0x5d2f37: e8e48fffff CALL 0x005cbf20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cbf20u,6106940u); flags=s.arithmetic_flags;
  }
  L005d2f3c: { // 0x5d2f3c: c705f42b7d00ffffffff MOV dword ptr [0x007d2bf4],0xffffffff
    m.w32((0x007d2bf4u), 0xffffffffu);
  }
  L005d2f46: { // 0x5d2f46: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005d2f48: { // 0x5d2f48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d2f49: { // 0x5d2f49: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005d2f4c: { // 0x5d2f4c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_001ca970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ca970: { // 0x5ca970: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005ca971: { // 0x5ca971: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ca972: { // 0x5ca972: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005ca974: { // 0x5ca974: e89755e4ff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,6072697u); flags=s.arithmetic_flags;
  }
  L005ca979: { // 0x5ca979: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005ca97b: { // 0x5ca97b: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L005ca980: { // 0x5ca980: 895e24 MOV dword ptr [ESI + 0x24],EBX
    m.w32((s.si+0x00000024u), s.bx);
  }
  L005ca983: { // 0x5ca983: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  L005ca986: { // 0x5ca986: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L005ca989: { // 0x5ca989: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L005ca98c: { // 0x5ca98c: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  L005ca98f: { // 0x5ca98f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005ca991: { // 0x5ca991: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L005ca994: { // 0x5ca994: 884676 MOV byte ptr [ESI + 0x76],AL
    m.w8((s.si+0x00000076u), (s.ax & 0xffu));
  }
  L005ca997: { // 0x5ca997: 88467d MOV byte ptr [ESI + 0x7d],AL
    m.w8((s.si+0x0000007du), (s.ax & 0xffu));
  }
  L005ca99a: { // 0x5ca99a: 888685000000 MOV byte ptr [ESI + 0x85],AL
    m.w8((s.si+0x00000085u), (s.ax & 0xffu));
  }
  L005ca9a0: { // 0x5ca9a0: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  L005ca9a3: { // 0x5ca9a3: 895e34 MOV dword ptr [ESI + 0x34],EBX
    m.w32((s.si+0x00000034u), s.bx);
  }
  L005ca9a6: { // 0x5ca9a6: 895e38 MOV dword ptr [ESI + 0x38],EBX
    m.w32((s.si+0x00000038u), s.bx);
  }
  L005ca9a9: { // 0x5ca9a9: 894e64 MOV dword ptr [ESI + 0x64],ECX
    m.w32((s.si+0x00000064u), s.cx);
  }
  L005ca9ac: { // 0x5ca9ac: 885e68 MOV byte ptr [ESI + 0x68],BL
    m.w8((s.si+0x00000068u), (s.bx & 0xffu));
  }
  L005ca9af: { // 0x5ca9af: 885e74 MOV byte ptr [ESI + 0x74],BL
    m.w8((s.si+0x00000074u), (s.bx & 0xffu));
  }
  L005ca9b2: { // 0x5ca9b2: 885e75 MOV byte ptr [ESI + 0x75],BL
    m.w8((s.si+0x00000075u), (s.bx & 0xffu));
  }
  L005ca9b5: { // 0x5ca9b5: 885e77 MOV byte ptr [ESI + 0x77],BL
    m.w8((s.si+0x00000077u), (s.bx & 0xffu));
  }
  L005ca9b8: { // 0x5ca9b8: 885e78 MOV byte ptr [ESI + 0x78],BL
    m.w8((s.si+0x00000078u), (s.bx & 0xffu));
  }
  L005ca9bb: { // 0x5ca9bb: 885e79 MOV byte ptr [ESI + 0x79],BL
    m.w8((s.si+0x00000079u), (s.bx & 0xffu));
  }
  L005ca9be: { // 0x5ca9be: 885e7a MOV byte ptr [ESI + 0x7a],BL
    m.w8((s.si+0x0000007au), (s.bx & 0xffu));
  }
  L005ca9c1: { // 0x5ca9c1: 885e7b MOV byte ptr [ESI + 0x7b],BL
    m.w8((s.si+0x0000007bu), (s.bx & 0xffu));
  }
  L005ca9c4: { // 0x5ca9c4: 885e7c MOV byte ptr [ESI + 0x7c],BL
    m.w8((s.si+0x0000007cu), (s.bx & 0xffu));
  }
  L005ca9c7: { // 0x5ca9c7: 898e80000000 MOV dword ptr [ESI + 0x80],ECX
    m.w32((s.si+0x00000080u), s.cx);
  }
  L005ca9cd: { // 0x5ca9cd: 889e84000000 MOV byte ptr [ESI + 0x84],BL
    m.w8((s.si+0x00000084u), (s.bx & 0xffu));
  }
  L005ca9d3: { // 0x5ca9d3: 8b0d68aaa500 MOV ECX,dword ptr [0x00a5aa68]
    s.cx = m.r32((0x00a5aa68u));
  }
  L005ca9d9: { // 0x5ca9d9: 8d8688000000 LEA EAX,[ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L005ca9df: { // 0x5ca9df: 898e88000000 MOV dword ptr [ESI + 0x88],ECX
    m.w32((s.si+0x00000088u), s.cx);
  }
  L005ca9e5: { // 0x5ca9e5: 8b156caaa500 MOV EDX,dword ptr [0x00a5aa6c]
    s.dx = m.r32((0x00a5aa6cu));
  }
  L005ca9eb: { // 0x5ca9eb: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L005ca9ee: { // 0x5ca9ee: 8b0d70aaa500 MOV ECX,dword ptr [0x00a5aa70]
    s.cx = m.r32((0x00a5aa70u));
  }
  L005ca9f4: { // 0x5ca9f4: 899e94000000 MOV dword ptr [ESI + 0x94],EBX
    m.w32((s.si+0x00000094u), s.bx);
  }
  L005ca9fa: { // 0x5ca9fa: c70658247900 MOV dword ptr [ESI],0x792458
    m.w32((s.si), 0x00792458u);
  }
  L005caa00: { // 0x5caa00: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L005caa03: { // 0x5caa03: 8d4e3c LEA ECX,[ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  L005caa06: { // 0x5caa06: c746043c247900 MOV dword ptr [ESI + 0x4],0x79243c
    m.w32((s.si+0x00000004u), 0x0079243cu);
  }
  L005caa0d: { // 0x5caa0d: c7460834247900 MOV dword ptr [ESI + 0x8],0x792434
    m.w32((s.si+0x00000008u), 0x00792434u);
  }
  L005caa14: { // 0x5caa14: c7460c2c247900 MOV dword ptr [ESI + 0xc],0x79242c
    m.w32((s.si+0x0000000cu), 0x0079242cu);
  }
  L005caa1b: { // 0x5caa1b: e8d0b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072864u); flags=s.arithmetic_flags;
  }
  L005caa20: { // 0x5caa20: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  L005caa23: { // 0x5caa23: e8c8b1e3ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,6072872u); flags=s.arithmetic_flags;
  }
  L005caa28: { // 0x5caa28: a1c07fa200 MOV EAX,[0x00a27fc0]
    s.ax = m.r32((0x00a27fc0u));
  }
  L005caa2d: { // 0x5caa2d: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa33: { // 0x5caa33: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa35: { // 0x5caa35: 7c2c JL 0x005caa63
    if(integer::condition("JL",flags)) goto L005caa63;
  }
  L005caa37: { // 0x5caa37: 381dc57fa200 CMP byte ptr [0x00a27fc5],BL
    (void)integer::sub(m.r8((0x00a27fc5u)),(s.bx & 0xffu),8,flags);
  }
  L005caa3d: { // 0x5caa3d: 7504 JNZ 0x005caa43
    if(integer::condition("JNZ",flags)) goto L005caa43;
  }
  L005caa3f: { // 0x5caa3f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa41: { // 0x5caa41: 7538 JNZ 0x005caa7b
    if(integer::condition("JNZ",flags)) goto L005caa7b;
  }
  L005caa43: { // 0x5caa43: 8b0dcc7fa200 MOV ECX,dword ptr [0x00a27fcc]
    s.cx = m.r32((0x00a27fccu));
  }
  L005caa49: { // 0x5caa49: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa4b: { // 0x5caa4b: 7e2e JLE 0x005caa7b
    if(integer::condition("JLE",flags)) goto L005caa7b;
  }
  L005caa4d: { // 0x5caa4d: 8b15b87fa200 MOV EDX,dword ptr [0x00a27fb8]
    s.dx = m.r32((0x00a27fb8u));
  }
  L005caa53: { // 0x5caa53: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caa55: { // 0x5caa55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caa56: { // 0x5caa56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caa57: { // 0x5caa57: b9b87fa200 MOV ECX,0xa27fb8
    s.cx = 0x00a27fb8u;
  }
  L005caa5c: { // 0x5caa5c: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6072927u); flags=s.arithmetic_flags;
  }
  L005caa5f: { // 0x5caa5f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caa61: { // 0x5caa61: 7418 JZ 0x005caa7b
    if(integer::condition("JZ",flags)) goto L005caa7b;
  }
  L005caa63: { // 0x5caa63: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005caa69: { // 0x5caa69: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caa6b: { // 0x5caa6b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caa6c: { // 0x5caa6c: 890dc87fa200 MOV dword ptr [0x00a27fc8],ECX
    m.w32((0x00a27fc8u), s.cx);
  }
  L005caa72: { // 0x5caa72: 8b0dbc7fa200 MOV ECX,dword ptr [0x00a27fbc]
    s.cx = m.r32((0x00a27fbcu));
  }
  L005caa78: { // 0x5caa78: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caa7b: { // 0x5caa7b: a17088aa00 MOV EAX,[0x00aa8870]
    s.ax = m.r32((0x00aa8870u));
  }
  L005caa80: { // 0x5caa80: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caa86: { // 0x5caa86: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caa88: { // 0x5caa88: 7c2c JL 0x005caab6
    if(integer::condition("JL",flags)) goto L005caab6;
  }
  L005caa8a: { // 0x5caa8a: 381d7588aa00 CMP byte ptr [0x00aa8875],BL
    (void)integer::sub(m.r8((0x00aa8875u)),(s.bx & 0xffu),8,flags);
  }
  L005caa90: { // 0x5caa90: 7504 JNZ 0x005caa96
    if(integer::condition("JNZ",flags)) goto L005caa96;
  }
  L005caa92: { // 0x5caa92: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caa94: { // 0x5caa94: 7538 JNZ 0x005caace
    if(integer::condition("JNZ",flags)) goto L005caace;
  }
  L005caa96: { // 0x5caa96: 8b0d7c88aa00 MOV ECX,dword ptr [0x00aa887c]
    s.cx = m.r32((0x00aa887cu));
  }
  L005caa9c: { // 0x5caa9c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caa9e: { // 0x5caa9e: 7e2e JLE 0x005caace
    if(integer::condition("JLE",flags)) goto L005caace;
  }
  L005caaa0: { // 0x5caaa0: 8b156888aa00 MOV EDX,dword ptr [0x00aa8868]
    s.dx = m.r32((0x00aa8868u));
  }
  L005caaa6: { // 0x5caaa6: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caaa8: { // 0x5caaa8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caaa9: { // 0x5caaa9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caaaa: { // 0x5caaaa: b96888aa00 MOV ECX,0xaa8868
    s.cx = 0x00aa8868u;
  }
  L005caaaf: { // 0x5caaaf: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073010u); flags=s.arithmetic_flags;
  }
  L005caab2: { // 0x5caab2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005caab4: { // 0x5caab4: 7418 JZ 0x005caace
    if(integer::condition("JZ",flags)) goto L005caace;
  }
  L005caab6: { // 0x5caab6: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005caabc: { // 0x5caabc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005caabe: { // 0x5caabe: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005caabf: { // 0x5caabf: 890d7888aa00 MOV dword ptr [0x00aa8878],ECX
    m.w32((0x00aa8878u), s.cx);
  }
  L005caac5: { // 0x5caac5: 8b0d6c88aa00 MOV ECX,dword ptr [0x00aa886c]
    s.cx = m.r32((0x00aa886cu));
  }
  L005caacb: { // 0x5caacb: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005caace: { // 0x5caace: a1c087aa00 MOV EAX,[0x00aa87c0]
    s.ax = m.r32((0x00aa87c0u));
  }
  L005caad3: { // 0x5caad3: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005caad9: { // 0x5caad9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005caadb: { // 0x5caadb: 7c2c JL 0x005cab09
    if(integer::condition("JL",flags)) goto L005cab09;
  }
  L005caadd: { // 0x5caadd: 381dc587aa00 CMP byte ptr [0x00aa87c5],BL
    (void)integer::sub(m.r8((0x00aa87c5u)),(s.bx & 0xffu),8,flags);
  }
  L005caae3: { // 0x5caae3: 7504 JNZ 0x005caae9
    if(integer::condition("JNZ",flags)) goto L005caae9;
  }
  L005caae5: { // 0x5caae5: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005caae7: { // 0x5caae7: 7538 JNZ 0x005cab21
    if(integer::condition("JNZ",flags)) goto L005cab21;
  }
  L005caae9: { // 0x5caae9: 8b0dcc87aa00 MOV ECX,dword ptr [0x00aa87cc]
    s.cx = m.r32((0x00aa87ccu));
  }
  L005caaef: { // 0x5caaef: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005caaf1: { // 0x5caaf1: 7e2e JLE 0x005cab21
    if(integer::condition("JLE",flags)) goto L005cab21;
  }
  L005caaf3: { // 0x5caaf3: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L005caaf9: { // 0x5caaf9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005caafb: { // 0x5caafb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005caafc: { // 0x5caafc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005caafd: { // 0x5caafd: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L005cab02: { // 0x5cab02: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073093u); flags=s.arithmetic_flags;
  }
  L005cab05: { // 0x5cab05: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab07: { // 0x5cab07: 7418 JZ 0x005cab21
    if(integer::condition("JZ",flags)) goto L005cab21;
  }
  L005cab09: { // 0x5cab09: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005cab0f: { // 0x5cab0f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab11: { // 0x5cab11: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab12: { // 0x5cab12: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L005cab18: { // 0x5cab18: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L005cab1e: { // 0x5cab1e: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab21: { // 0x5cab21: a16887aa00 MOV EAX,[0x00aa8768]
    s.ax = m.r32((0x00aa8768u));
  }
  L005cab26: { // 0x5cab26: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab2c: { // 0x5cab2c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005cab2e: { // 0x5cab2e: 7c2c JL 0x005cab5c
    if(integer::condition("JL",flags)) goto L005cab5c;
  }
  L005cab30: { // 0x5cab30: 381d6d87aa00 CMP byte ptr [0x00aa876d],BL
    (void)integer::sub(m.r8((0x00aa876du)),(s.bx & 0xffu),8,flags);
  }
  L005cab36: { // 0x5cab36: 7504 JNZ 0x005cab3c
    if(integer::condition("JNZ",flags)) goto L005cab3c;
  }
  L005cab38: { // 0x5cab38: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005cab3a: { // 0x5cab3a: 7538 JNZ 0x005cab74
    if(integer::condition("JNZ",flags)) goto L005cab74;
  }
  L005cab3c: { // 0x5cab3c: 8b0d7487aa00 MOV ECX,dword ptr [0x00aa8774]
    s.cx = m.r32((0x00aa8774u));
  }
  L005cab42: { // 0x5cab42: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005cab44: { // 0x5cab44: 7e2e JLE 0x005cab74
    if(integer::condition("JLE",flags)) goto L005cab74;
  }
  L005cab46: { // 0x5cab46: 8b156087aa00 MOV EDX,dword ptr [0x00aa8760]
    s.dx = m.r32((0x00aa8760u));
  }
  L005cab4c: { // 0x5cab4c: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005cab4e: { // 0x5cab4e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cab4f: { // 0x5cab4f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cab50: { // 0x5cab50: b96087aa00 MOV ECX,0xaa8760
    s.cx = 0x00aa8760u;
  }
  L005cab55: { // 0x5cab55: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6073176u); flags=s.arithmetic_flags;
  }
  L005cab58: { // 0x5cab58: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cab5a: { // 0x5cab5a: 7418 JZ 0x005cab74
    if(integer::condition("JZ",flags)) goto L005cab74;
  }
  L005cab5c: { // 0x5cab5c: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cab62: { // 0x5cab62: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cab64: { // 0x5cab64: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cab65: { // 0x5cab65: 890d7087aa00 MOV dword ptr [0x00aa8770],ECX
    m.w32((0x00aa8770u), s.cx);
  }
  L005cab6b: { // 0x5cab6b: 8b0d6487aa00 MOV ECX,dword ptr [0x00aa8764]
    s.cx = m.r32((0x00aa8764u));
  }
  L005cab71: { // 0x5cab71: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cab74: { // 0x5cab74: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L005cab77: { // 0x5cab77: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L005cab79: { // 0x5cab79: 884614 MOV byte ptr [ESI + 0x14],AL
    m.w8((s.si+0x00000014u), (s.ax & 0xffu));
  }
  L005cab7c: { // 0x5cab7c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005cab7e: { // 0x5cab7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cab7f: { // 0x5cab7f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cab80: { // 0x5cab80: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ff10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff10: { // 0x40ff10: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0040ff12: { // 0x40ff12: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040ff14: { // 0x40ff14: c74008445e7800 MOV dword ptr [EAX + 0x8],0x785e44
    m.w32((s.ax+0x00000008u), 0x00785e44u);
  }
  L0040ff1b: { // 0x40ff1b: c7400c3c5e7800 MOV dword ptr [EAX + 0xc],0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff22: { // 0x40ff22: 894818 MOV dword ptr [EAX + 0x18],ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L0040ff25: { // 0x40ff25: 89481c MOV dword ptr [EAX + 0x1c],ECX
    m.w32((s.ax+0x0000001cu), s.cx);
  }
  L0040ff28: { // 0x40ff28: 884820 MOV byte ptr [EAX + 0x20],CL
    m.w8((s.ax+0x00000020u), (s.cx & 0xffu));
  }
  L0040ff2b: { // 0x40ff2b: 8a4814 MOV CL,byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0040ff2e: { // 0x40ff2e: 80e1f8 AND CL,0xf8
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x000000f8u),8,flags));
  }
  L0040ff31: { // 0x40ff31: c74010ffffffff MOV dword ptr [EAX + 0x10],0xffffffff
    m.w32((s.ax+0x00000010u), 0xffffffffu);
  }
  L0040ff38: { // 0x40ff38: c700d85d7800 MOV dword ptr [EAX],0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff3e: { // 0x40ff3e: c74004bc5d7800 MOV dword ptr [EAX + 0x4],0x785dbc
    m.w32((s.ax+0x00000004u), 0x00785dbcu);
  }
  L0040ff45: { // 0x40ff45: c74008b45d7800 MOV dword ptr [EAX + 0x8],0x785db4
    m.w32((s.ax+0x00000008u), 0x00785db4u);
  }
  L0040ff4c: { // 0x40ff4c: c7400cac5d7800 MOV dword ptr [EAX + 0xc],0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff53: { // 0x40ff53: 884814 MOV byte ptr [EAX + 0x14],CL
    m.w8((s.ax+0x00000014u), (s.cx & 0xffu));
  }
  L0040ff56: { // 0x40ff56: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00005bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405bf0: { // 0x405bf0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00405bf2: { // 0x405bf2: c7410cec928100 MOV dword ptr [ECX + 0xc],0x8192ec
    m.w32((s.cx+0x0000000cu), 0x008192ecu);
  }
  L00405bf9: { // 0x405bf9: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00405bfb: { // 0x405bfb: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00405bfe: { // 0x405bfe: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00405c01: { // 0x405c01: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffd0: { // 0x0040ffd0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0040ffd6: { // 0x0040ffd6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0040ffd8: { // 0x0040ffd8: 750c JNZ 0x0040ffe6
    if(integer::condition("JNZ",flags)) goto L0040ffe6;
  }
  L0040ffda: { // 0x0040ffda: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0040ffde: { // 0x0040ffde: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040ffe0: { // 0x0040ffe0: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0040ffe3: { // 0x0040ffe3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0040ffe6: { // 0x0040ffe6: e835a12400 CALL 0x0065a120
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065a120u,4259819u); flags=s.arithmetic_flags;
  }
  L0040ffeb: { // 0x0040ffeb: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0040ffef: { // 0x0040ffef: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0040fff2: { // 0x0040fff2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0025a120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065a120: { // 0x65a120: 8b8114020000 MOV EAX,dword ptr [ECX + 0x214]
    s.ax = m.r32((s.cx+0x00000214u));
  }
  L0065a126: { // 0x65a126: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0065a127: { // 0x65a127: 898114020000 MOV dword ptr [ECX + 0x214],EAX
    m.w32((s.cx+0x00000214u), s.ax);
  }
  L0065a12d: { // 0x65a12d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001cbf20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cbf20: { // 0x5cbf20: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L005cbf25: { // 0x5cbf25: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L005cbf28: { // 0x5cbf28: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf2a: { // 0x5cbf2a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cbf2b: { // 0x5cbf2b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005cbf2c: { // 0x5cbf2c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cbf2d: { // 0x5cbf2d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbf2e: { // 0x5cbf2e: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cbf30: { // 0x5cbf30: 0f8416030000 JZ 0x005cc24c
    if(integer::condition("JZ",flags)) goto L005cc24c;
  }
  L005cbf36: { // 0x5cbf36: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cbf39: { // 0x5cbf39: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf3b: { // 0x5cbf3b: 0f840b030000 JZ 0x005cc24c
    if(integer::condition("JZ",flags)) goto L005cc24c;
  }
  L005cbf41: { // 0x5cbf41: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005cbf44: { // 0x5cbf44: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbf46: { // 0x5cbf46: 0f8500030000 JNZ 0x005cc24c
    if(integer::condition("JNZ",flags)) goto L005cc24c;
  }
  L005cbf4c: { // 0x5cbf4c: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L005cbf51: { // 0x5cbf51: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L005cbf55: { // 0x5cbf55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbf57: { // 0x5cbf57: 7526 JNZ 0x005cbf7f
    if(integer::condition("JNZ",flags)) goto L005cbf7f;
  }
  L005cbf59: { // 0x5cbf59: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L005cbf5b: { // 0x5cbf5b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cbf5d: { // 0x5cbf5d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cbf5f: { // 0x5cbf5f: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005cbf61: { // 0x5cbf61: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005cbf63: { // 0x5cbf63: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbf64: { // 0x5cbf64: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005cbf69: { // 0x5cbf69: e82295f7ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6078318u); flags=s.arithmetic_flags;
  }
  L005cbf6e: { // 0x5cbf6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbf6f: { // 0x5cbf6f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbf71: { // 0x5cbf71: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),6078327u); flags=s.arithmetic_flags;
  }
  L005cbf77: { // 0x5cbf77: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cbf79: { // 0x5cbf79: 0f85cd020000 JNZ 0x005cc24c
    if(integer::condition("JNZ",flags)) goto L005cc24c;
  }
  L005cbf7f: { // 0x5cbf7f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbf81: { // 0x5cbf81: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbf83: { // 0x5cbf83: c6467600 MOV byte ptr [ESI + 0x76],0x0
    m.w8((s.si+0x00000076u), 0x00000000u);
  }
  L005cbf87: { // 0x5cbf87: c6467500 MOV byte ptr [ESI + 0x75],0x0
    m.w8((s.si+0x00000075u), 0x00000000u);
  }
  L005cbf8b: { // 0x5cbf8b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078353u); flags=s.arithmetic_flags;
  }
  L005cbf91: { // 0x5cbf91: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cbf93: { // 0x5cbf93: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005cbf95: { // 0x5cbf95: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cbf97: { // 0x5cbf97: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005cbf99: { // 0x5cbf99: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005cbf9d: { // 0x5cbf9d: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L005cbfa0: { // 0x5cbfa0: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005cbfa4: { // 0x5cbfa4: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L005cbfa7: { // 0x5cbfa7: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L005cbfab: { // 0x5cbfab: 7421 JZ 0x005cbfce
    if(integer::condition("JZ",flags)) goto L005cbfce;
  }
  L005cbfad: { // 0x5cbfad: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L005cbfaf: { // 0x5cbfaf: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L005cbfb3: { // 0x5cbfb3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cbfb4: { // 0x5cbfb4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbfb5: { // 0x5cbfb5: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005cbfb7: { // 0x5cbfb7: ff526c CALL dword ptr [EDX + 0x6c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000006cu)),6078394u); flags=s.arithmetic_flags;
  }
  L005cbfba: { // 0x5cbfba: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cbfbc: { // 0x5cbfbc: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005cbfc0: { // 0x5cbfc0: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cbfc3: { // 0x5cbfc3: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L005cbfc7: { // 0x5cbfc7: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cbfca: { // 0x5cbfca: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005cbfce: { // 0x5cbfce: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbfd0: { // 0x5cbfd0: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L005cbfd4: { // 0x5cbfd4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cbfd5: { // 0x5cbfd5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbfd7: { // 0x5cbfd7: ff929c010000 CALL dword ptr [EDX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000019cu)),6078429u); flags=s.arithmetic_flags;
  }
  L005cbfdd: { // 0x5cbfdd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cbfdf: { // 0x5cbfdf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005cbfe1: { // 0x5cbfe1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cbfe3: { // 0x5cbfe3: ff921c010000 CALL dword ptr [EDX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000011cu)),6078441u); flags=s.arithmetic_flags;
  }
  L005cbfe9: { // 0x5cbfe9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbfeb: { // 0x5cbfeb: 0f8457020000 JZ 0x005cc248
    if(integer::condition("JZ",flags)) goto L005cc248;
  }
  L005cbff1: { // 0x5cbff1: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L005cbff4: { // 0x5cbff4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cbff6: { // 0x5cbff6: 0f8440020000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cbffc: { // 0x5cbffc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cbffe: { // 0x5cbffe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc000: { // 0x5cc000: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6078467u); flags=s.arithmetic_flags;
  }
  L005cc003: { // 0x5cc003: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cc006: { // 0x5cc006: 740b JZ 0x005cc013
    if(integer::condition("JZ",flags)) goto L005cc013;
  }
  L005cc008: { // 0x5cc008: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc009: { // 0x5cc009: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L005cc00e: { // 0x5cc00e: e80dd8ecff CALL 0x00499820
    s.arithmetic_flags=flags; invoke(m,s,f,0x00499820u,6078483u); flags=s.arithmetic_flags;
  }
  L005cc013: { // 0x5cc013: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005cc015: { // 0x5cc015: 0f845c010000 JZ 0x005cc177
    if(integer::condition("JZ",flags)) goto L005cc177;
  }
  L005cc01b: { // 0x5cc01b: 8a8304020000 MOV AL,byte ptr [EBX + 0x204]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000204u)));
  }
  L005cc021: { // 0x5cc021: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc023: { // 0x5cc023: 744c JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc025: { // 0x5cc025: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc027: { // 0x5cc027: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc029: { // 0x5cc029: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6078508u); flags=s.arithmetic_flags;
  }
  L005cc02c: { // 0x5cc02c: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L005cc02f: { // 0x5cc02f: 7516 JNZ 0x005cc047
    if(integer::condition("JNZ",flags)) goto L005cc047;
  }
  L005cc031: { // 0x5cc031: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc033: { // 0x5cc033: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc035: { // 0x5cc035: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6078520u); flags=s.arithmetic_flags;
  }
  L005cc038: { // 0x5cc038: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L005cc03b: { // 0x5cc03b: 7534 JNZ 0x005cc071
    if(integer::condition("JNZ",flags)) goto L005cc071;
  }
  L005cc03d: { // 0x5cc03d: 8a8381020000 MOV AL,byte ptr [EBX + 0x281]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000281u)));
  }
  L005cc043: { // 0x5cc043: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cc045: { // 0x5cc045: 742a JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc047: { // 0x5cc047: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L005cc04c: { // 0x5cc04c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc04e: { // 0x5cc04e: 7414 JZ 0x005cc064
    if(integer::condition("JZ",flags)) goto L005cc064;
  }
  L005cc050: { // 0x5cc050: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L005cc053: { // 0x5cc053: 740f JZ 0x005cc064
    if(integer::condition("JZ",flags)) goto L005cc064;
  }
  L005cc055: { // 0x5cc055: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L005cc058: { // 0x5cc058: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L005cc05b: { // 0x5cc05b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc05c: { // 0x5cc05c: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6078559u); flags=s.arithmetic_flags;
  }
  L005cc05f: { // 0x5cc05f: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  L005cc062: { // 0x5cc062: 740d JZ 0x005cc071
    if(integer::condition("JZ",flags)) goto L005cc071;
  }
  L005cc064: { // 0x5cc064: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cc066: { // 0x5cc066: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc067: { // 0x5cc067: b9b0a78100 MOV ECX,0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  L005cc06c: { // 0x5cc06c: e89f04f7ff CALL 0x0053c510
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053c510u,6078577u); flags=s.arithmetic_flags;
  }
  L005cc071: { // 0x5cc071: 8b83ac000000 MOV EAX,dword ptr [EBX + 0xac]
    s.ax = m.r32((s.bx+0x000000acu));
  }
  L005cc077: { // 0x5cc077: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc079: { // 0x5cc079: 0f84f8000000 JZ 0x005cc177
    if(integer::condition("JZ",flags)) goto L005cc177;
  }
  L005cc07f: { // 0x5cc07f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cc081: { // 0x5cc081: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L005cc085: { // 0x5cc085: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cc086: { // 0x5cc086: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc088: { // 0x5cc088: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6078603u); flags=s.arithmetic_flags;
  }
  L005cc08b: { // 0x5cc08b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L005cc08d: { // 0x5cc08d: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L005cc091: { // 0x5cc091: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L005cc095: { // 0x5cc095: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cc098: { // 0x5cc098: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc099: { // 0x5cc099: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cc09f: { // 0x5cc09f: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005cc0a3: { // 0x5cc0a3: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cc0a6: { // 0x5cc0a6: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L005cc0aa: { // 0x5cc0aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cc0ab: { // 0x5cc0ab: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L005cc0af: { // 0x5cc0af: e85cbf0c00 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6078644u); flags=s.arithmetic_flags;
  }
  L005cc0b4: { // 0x5cc0b4: a1ac1c8200 MOV EAX,[0x00821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L005cc0b9: { // 0x5cc0b9: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005cc0bd: { // 0x5cc0bd: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L005cc0c1: { // 0x5cc0c1: 8b88b0000000 MOV ECX,dword ptr [EAX + 0xb0]
    s.cx = m.r32((s.ax+0x000000b0u));
  }
  L005cc0c7: { // 0x5cc0c7: 8b80b4000000 MOV EAX,dword ptr [EAX + 0xb4]
    s.ax = m.r32((s.ax+0x000000b4u));
  }
  L005cc0cd: { // 0x5cc0cd: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005cc0cf: { // 0x5cc0cf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc0d1: { // 0x5cc0d1: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L005cc0d3: { // 0x5cc0d3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc0d5: { // 0x5cc0d5: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L005cc0d9: { // 0x5cc0d9: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005cc0dd: { // 0x5cc0dd: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078691u); flags=s.arithmetic_flags;
  }
  L005cc0e3: { // 0x5cc0e3: 8bb8ac000000 MOV EDI,dword ptr [EAX + 0xac]
    s.di = m.r32((s.ax+0x000000acu));
  }
  L005cc0e9: { // 0x5cc0e9: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L005cc0ed: { // 0x5cc0ed: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L005cc0ef: { // 0x5cc0ef: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005cc0f3: { // 0x5cc0f3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cc0f4: { // 0x5cc0f4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc0f6: { // 0x5cc0f6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc0f8: { // 0x5cc0f8: 0fbf4704 MOVSX EAX,word ptr [EDI + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L005cc0fc: { // 0x5cc0fc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005cc0fd: { // 0x5cc0fd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc0ff: { // 0x5cc0ff: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005cc103: { // 0x5cc103: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cc105: { // 0x5cc105: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005cc107: { // 0x5cc107: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005cc109: { // 0x5cc109: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L005cc10b: { // 0x5cc10b: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005cc10f: { // 0x5cc10f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L005cc113: { // 0x5cc113: e83f181a00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6078744u); flags=s.arithmetic_flags;
  }
  L005cc118: { // 0x5cc118: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cc11b: { // 0x5cc11b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc11d: { // 0x5cc11d: 7412 JZ 0x005cc131
    if(integer::condition("JZ",flags)) goto L005cc131;
  }
  L005cc11f: { // 0x5cc11f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005cc123: { // 0x5cc123: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005cc127: { // 0x5cc127: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc128: { // 0x5cc128: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cc129: { // 0x5cc129: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cc12a: { // 0x5cc12a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc12c: { // 0x5cc12c: e8af2ae5ff CALL 0x0041ebe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041ebe0u,6078769u); flags=s.arithmetic_flags;
  }
  L005cc131: { // 0x5cc131: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L005cc136: { // 0x5cc136: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc138: { // 0x5cc138: 753d JNZ 0x005cc177
    if(integer::condition("JNZ",flags)) goto L005cc177;
  }
  L005cc13a: { // 0x5cc13a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L005cc140: { // 0x5cc140: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005cc144: { // 0x5cc144: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005cc146: { // 0x5cc146: 8b91b0000000 MOV EDX,dword ptr [ECX + 0xb0]
    s.dx = m.r32((s.cx+0x000000b0u));
  }
  L005cc14c: { // 0x5cc14c: 8ba9b4000000 MOV EBP,dword ptr [ECX + 0xb4]
    s.bp = m.r32((s.cx+0x000000b4u));
  }
  L005cc152: { // 0x5cc152: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L005cc155: { // 0x5cc155: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005cc157: { // 0x5cc157: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L005cc15b: { // 0x5cc15b: 8bdc MOV EBX,ESP
    s.bx = f.sp;
  }
  L005cc15d: { // 0x5cc15d: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L005cc15f: { // 0x5cc15f: 0fbf6f02 MOVSX EBP,word ptr [EDI + 0x2]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005cc163: { // 0x5cc163: 0fbf7f04 MOVSX EDI,word ptr [EDI + 0x4]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L005cc167: { // 0x5cc167: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L005cc169: { // 0x5cc169: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L005cc16c: { // 0x5cc16c: 896b08 MOV dword ptr [EBX + 0x8],EBP
    m.w32((s.bx+0x00000008u), s.bp);
  }
  L005cc16f: { // 0x5cc16f: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L005cc172: { // 0x5cc172: e8e9c40c00 CALL 0x00698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,6078839u); flags=s.arithmetic_flags;
  }
  L005cc177: { // 0x5cc177: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc179: { // 0x5cc179: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc17b: { // 0x5cc17b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078849u); flags=s.arithmetic_flags;
  }
  L005cc181: { // 0x5cc181: 8a880a020000 MOV CL,byte ptr [EAX + 0x20a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000020au)));
  }
  L005cc187: { // 0x5cc187: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cc189: { // 0x5cc189: 0f84ad000000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cc18f: { // 0x5cc18f: 6810020000 PUSH 0x210
    f.push(m,0x00000210u);
  }
  L005cc194: { // 0x5cc194: e8be171a00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6078873u); flags=s.arithmetic_flags;
  }
  L005cc199: { // 0x5cc199: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cc19c: { // 0x5cc19c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc19e: { // 0x5cc19e: 7409 JZ 0x005cc1a9
    if(integer::condition("JZ",flags)) goto L005cc1a9;
  }
  L005cc1a0: { // 0x5cc1a0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc1a2: { // 0x5cc1a2: e819b4f6ff CALL 0x005375c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005375c0u,6078887u); flags=s.arithmetic_flags;
  }
  L005cc1a7: { // 0x5cc1a7: eb02 JMP 0x005cc1ab
    goto L005cc1ab;
  }
  L005cc1a9: { // 0x5cc1a9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005cc1ab: { // 0x5cc1ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cc1ad: { // 0x5cc1ad: 898694000000 MOV dword ptr [ESI + 0x94],EAX
    m.w32((s.si+0x00000094u), s.ax);
  }
  L005cc1b3: { // 0x5cc1b3: 0f8483000000 JZ 0x005cc23c
    if(integer::condition("JZ",flags)) goto L005cc23c;
  }
  L005cc1b9: { // 0x5cc1b9: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L005cc1bf: { // 0x5cc1bf: 81c1ab140000 ADD ECX,0x14ab
    s.cx = integer::add(s.cx,0x000014abu,32,flags);
  }
  L005cc1c5: { // 0x5cc1c5: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L005cc1c7: { // 0x5cc1c7: 668b3a MOV DI,word ptr [EDX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L005cc1ca: { // 0x5cc1ca: 66897c2440 MOV word ptr [ESP + 0x40],DI
    m.w16((f.sp+0x00000040u), (s.di & 0xffffu));
  }
  L005cc1cf: { // 0x5cc1cf: 8a5c2440 MOV BL,byte ptr [ESP + 0x40]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000040u)));
  }
  L005cc1d3: { // 0x5cc1d3: 8a5202 MOV DL,byte ptr [EDX + 0x2]
    s.dx = with_al(s.dx, m.r8((s.dx+0x00000002u)));
  }
  L005cc1d6: { // 0x5cc1d6: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005cc1d8: { // 0x5cc1d8: 7531 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1da: { // 0x5cc1da: 8a5c2441 MOV BL,byte ptr [ESP + 0x41]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000041u)));
  }
  L005cc1de: { // 0x5cc1de: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005cc1e0: { // 0x5cc1e0: 7529 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1e2: { // 0x5cc1e2: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005cc1e4: { // 0x5cc1e4: 7525 JNZ 0x005cc20b
    if(integer::condition("JNZ",flags)) goto L005cc20b;
  }
  L005cc1e6: { // 0x5cc1e6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc1e8: { // 0x5cc1e8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc1ea: { // 0x5cc1ea: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6078960u); flags=s.arithmetic_flags;
  }
  L005cc1f0: { // 0x5cc1f0: 8b9694000000 MOV EDX,dword ptr [ESI + 0x94]
    s.dx = m.r32((s.si+0x00000094u));
  }
  L005cc1f6: { // 0x5cc1f6: 050b020000 ADD EAX,0x20b
    s.ax = integer::add(s.ax,0x0000020bu,32,flags);
  }
  L005cc1fb: { // 0x5cc1fb: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005cc1fd: { // 0x5cc1fd: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L005cc200: { // 0x5cc200: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  L005cc203: { // 0x5cc203: 668902 MOV word ptr [EDX],AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  L005cc206: { // 0x5cc206: 884a02 MOV byte ptr [EDX + 0x2],CL
    m.w8((s.dx+0x00000002u), (s.cx & 0xffu));
  }
  L005cc209: { // 0x5cc209: eb0c JMP 0x005cc217
    goto L005cc217;
  }
  L005cc20b: { // 0x5cc20b: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005cc20e: { // 0x5cc20e: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  L005cc211: { // 0x5cc211: 668910 MOV word ptr [EAX],DX
    m.w16((s.ax), (s.dx & 0xffffu));
  }
  L005cc214: { // 0x5cc214: 884802 MOV byte ptr [EAX + 0x2],CL
    m.w8((s.ax+0x00000002u), (s.cx & 0xffu));
  }
  L005cc217: { // 0x5cc217: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cc219: { // 0x5cc219: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cc21b: { // 0x5cc21b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6079009u); flags=s.arithmetic_flags;
  }
  L005cc221: { // 0x5cc221: 8b8810020000 MOV ECX,dword ptr [EAX + 0x210]
    s.cx = m.r32((s.ax+0x00000210u));
  }
  L005cc227: { // 0x5cc227: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cc228: { // 0x5cc228: 8b8e94000000 MOV ECX,dword ptr [ESI + 0x94]
    s.cx = m.r32((s.si+0x00000094u));
  }
  L005cc22e: { // 0x5cc22e: e8bdb4f6ff CALL 0x005376f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005376f0u,6079027u); flags=s.arithmetic_flags;
  }
  L005cc233: { // 0x5cc233: 8b9694000000 MOV EDX,dword ptr [ESI + 0x94]
    s.dx = m.r32((s.si+0x00000094u));
  }
  L005cc239: { // 0x5cc239: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L005cc23c: { // 0x5cc23c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cc23e: { // 0x5cc23e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc23f: { // 0x5cc23f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc240: { // 0x5cc240: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005cc241: { // 0x5cc241: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc242: { // 0x5cc242: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005cc245: { // 0x5cc245: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005cc248: { // 0x5cc248: c6467601 MOV byte ptr [ESI + 0x76],0x1
    m.w8((s.si+0x00000076u), 0x00000001u);
  }
  L005cc24c: { // 0x5cc24c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cc24d: { // 0x5cc24d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cc24e: { // 0x5cc24e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005cc24f: { // 0x5cc24f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cc251: { // 0x5cc251: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cc252: { // 0x5cc252: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005cc255: { // 0x5cc255: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00074d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00474d00: { // 0x474d00: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00474d03: { // 0x474d03: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00474d04: { // 0x474d04: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00474d05: { // 0x474d05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00474d06: { // 0x474d06: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00474d07: { // 0x474d07: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00474d09: { // 0x474d09: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L00474d0c: { // 0x474d0c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00474d0f: { // 0x474d0f: 750d JNZ 0x00474d1e
    if(integer::condition("JNZ",flags)) goto L00474d1e;
  }
  L00474d11: { // 0x474d11: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474d13: { // 0x474d13: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474d15: { // 0x474d15: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474d17: { // 0x474d17: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474d19: { // 0x474d19: e974010000 JMP 0x00474e92
    goto L00474e92;
  }
  L00474d1e: { // 0x474d1e: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00474d24: { // 0x474d24: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00474d27: { // 0x474d27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00474d29: { // 0x474d29: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00474d2b: { // 0x474d2b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4672817u); flags=s.arithmetic_flags;
  }
  L00474d31: { // 0x474d31: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00474d33: { // 0x474d33: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00474d35: { // 0x474d35: 750d JNZ 0x00474d44
    if(integer::condition("JNZ",flags)) goto L00474d44;
  }
  L00474d37: { // 0x474d37: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474d39: { // 0x474d39: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474d3b: { // 0x474d3b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474d3d: { // 0x474d3d: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474d3f: { // 0x474d3f: e94e010000 JMP 0x00474e92
    goto L00474e92;
  }
  L00474d44: { // 0x474d44: 8a871e010000 MOV AL,byte ptr [EDI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011eu)));
  }
  L00474d4a: { // 0x474d4a: 88442410 MOV byte ptr [ESP + 0x10],AL
    m.w8((f.sp+0x00000010u), (s.ax & 0xffu));
  }
  L00474d4e: { // 0x474d4e: 8a867a020000 MOV AL,byte ptr [ESI + 0x27a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000027au)));
  }
  L00474d54: { // 0x474d54: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00474d56: { // 0x474d56: 7405 JZ 0x00474d5d
    if(integer::condition("JZ",flags)) goto L00474d5d;
  }
  L00474d58: { // 0x474d58: c644241000 MOV byte ptr [ESP + 0x10],0x0
    m.w8((f.sp+0x00000010u), 0x00000000u);
  }
  L00474d5d: { // 0x474d5d: 0fbf4506 MOVSX EAX,word ptr [EBP + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000006u)),16));
  }
  L00474d61: { // 0x474d61: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474d62: { // 0x474d62: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474d64: { // 0x474d64: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00474d68: { // 0x474d68: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00474d6a: { // 0x474d6a: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00474d70: { // 0x474d70: 0fbf4726 MOVSX EAX,word ptr [EDI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000026u)),16));
  }
  L00474d74: { // 0x474d74: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d77: { // 0x474d77: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00474d7c: { // 0x474d7c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00474d7e: { // 0x474d7e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474d7f: { // 0x474d7f: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474d81: { // 0x474d81: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00474d83: { // 0x474d83: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474d89: { // 0x474d89: 0fbf4f24 MOVSX ECX,word ptr [EDI + 0x24]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000024u)),16));
  }
  L00474d8d: { // 0x474d8d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474d8f: { // 0x474d8f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474d92: { // 0x474d92: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d95: { // 0x474d95: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d98: { // 0x474d98: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00474d9e: { // 0x474d9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474d9f: { // 0x474d9f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00474da1: { // 0x474da1: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00474da5: { // 0x474da5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474da6: { // 0x474da6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474dac: { // 0x474dac: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474dae: { // 0x474dae: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474db1: { // 0x474db1: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474db4: { // 0x474db4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474db5: { // 0x474db5: e87668faff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,4672954u); flags=s.arithmetic_flags;
  }
  L00474dba: { // 0x474dba: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00474dbe: { // 0x474dbe: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00474dc2: { // 0x474dc2: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00474dc6: { // 0x474dc6: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00474dca: { // 0x474dca: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00474dce: { // 0x474dce: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L00474dd2: { // 0x474dd2: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L00474dd6: { // 0x474dd6: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00474dda: { // 0x474dda: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00474de0: { // 0x474de0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474de1: { // 0x474de1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474de2: { // 0x474de2: e829322200 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,4672999u); flags=s.arithmetic_flags;
  }
  L00474de7: { // 0x474de7: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00474deb: { // 0x474deb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00474dec: { // 0x474dec: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00474dee: { // 0x474dee: e84d020000 CALL 0x00475040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475040u,4673011u); flags=s.arithmetic_flags;
  }
  L00474df3: { // 0x474df3: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00474df7: { // 0x474df7: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00474df9: { // 0x474df9: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00474dfb: { // 0x474dfb: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L00474dff: { // 0x474dff: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e03: { // 0x474e03: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00474e06: { // 0x474e06: 8a8740010000 MOV AL,byte ptr [EDI + 0x140]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000140u)));
  }
  L00474e0c: { // 0x474e0c: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00474e0e: { // 0x474e0e: 83e91e SUB ECX,0x1e
    s.cx = integer::sub(s.cx,0x0000001eu,32,flags);
  }
  L00474e11: { // 0x474e11: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00474e15: { // 0x474e15: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  L00474e17: { // 0x474e17: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e1b: { // 0x474e1b: 741c JZ 0x00474e39
    if(integer::condition("JZ",flags)) goto L00474e39;
  }
  L00474e1d: { // 0x474e1d: 8a871e010000 MOV AL,byte ptr [EDI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011eu)));
  }
  L00474e23: { // 0x474e23: 3c09 CMP AL,0x9
    (void)integer::sub((s.ax & 0xffu),0x00000009u,8,flags);
  }
  L00474e25: { // 0x474e25: 7212 JC 0x00474e39
    if(integer::condition("JC",flags)) goto L00474e39;
  }
  L00474e27: { // 0x474e27: 3c11 CMP AL,0x11
    (void)integer::sub((s.ax & 0xffu),0x00000011u,8,flags);
  }
  L00474e29: { // 0x474e29: 770e JA 0x00474e39
    if(integer::condition("JA",flags)) goto L00474e39;
  }
  L00474e2b: { // 0x474e2b: 83e90f SUB ECX,0xf
    s.cx = integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L00474e2e: { // 0x474e2e: 83c307 ADD EBX,0x7
    s.bx = integer::add(s.bx,0x00000007u,32,flags);
  }
  L00474e31: { // 0x474e31: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e35: { // 0x474e35: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00474e39: { // 0x474e39: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00474e3d: { // 0x474e3d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474e3e: { // 0x474e3e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474e40: { // 0x474e40: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474e42: { // 0x474e42: 0fbf4504 MOVSX EAX,word ptr [EBP + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000004u)),16));
  }
  L00474e46: { // 0x474e46: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474e47: { // 0x474e47: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474e49: { // 0x474e49: 0fbf5506 MOVSX EDX,word ptr [EBP + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000006u)),16));
  }
  L00474e4d: { // 0x474e4d: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474e4f: { // 0x474e4f: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474e51: { // 0x474e51: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00474e53: { // 0x474e53: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00474e55: { // 0x474e55: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00474e57: { // 0x474e57: 731e JNC 0x00474e77
    if(integer::condition("JNC",flags)) goto L00474e77;
  }
  L00474e59: { // 0x474e59: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00474e5c: { // 0x474e5c: 8d44c508 LEA EAX,[EBP + EAX*0x8 + 0x8]
    s.ax = (s.bp+(s.ax * 0x00000008u)+0x00000008u);
  }
  L00474e60: { // 0x474e60: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474e62: { // 0x474e62: 7413 JZ 0x00474e77
    if(integer::condition("JZ",flags)) goto L00474e77;
  }
  L00474e64: { // 0x474e64: 0fbf28 MOVSX EBP,word ptr [EAX]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00474e67: { // 0x474e67: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00474e6b: { // 0x474e6b: 0fbf7004 MOVSX ESI,word ptr [EAX + 0x4]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L00474e6f: { // 0x474e6f: 0fbf7806 MOVSX EDI,word ptr [EAX + 0x6]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L00474e73: { // 0x474e73: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00474e75: { // 0x474e75: eb17 JMP 0x00474e8e
    goto L00474e8e;
  }
  L00474e77: { // 0x474e77: a1008f8300 MOV EAX,[0x00838f00]
    s.ax = m.r32((0x00838f00u));
  }
  L00474e7c: { // 0x474e7c: 8b15048f8300 MOV EDX,dword ptr [0x00838f04]
    s.dx = m.r32((0x00838f04u));
  }
  L00474e82: { // 0x474e82: 8b35088f8300 MOV ESI,dword ptr [0x00838f08]
    s.si = m.r32((0x00838f08u));
  }
  L00474e88: { // 0x474e88: 8b3d0c8f8300 MOV EDI,dword ptr [0x00838f0c]
    s.di = m.r32((0x00838f0cu));
  }
  L00474e8e: { // 0x474e8e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00474e90: { // 0x474e90: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L00474e92: { // 0x474e92: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00474e96: { // 0x474e96: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474e98: { // 0x474e98: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L00474e9a: { // 0x474e9a: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00474e9d: { // 0x474e9d: 897308 MOV dword ptr [EBX + 0x8],ESI
    m.w32((s.bx+0x00000008u), s.si);
  }
  L00474ea0: { // 0x474ea0: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L00474ea3: { // 0x474ea3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474ea4: { // 0x474ea4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474ea5: { // 0x474ea5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474ea6: { // 0x474ea6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474ea7: { // 0x474ea7: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00474eaa: { // 0x474eaa: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00074ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00474ab0: { // 0x474ab0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00474ab3: { // 0x474ab3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00474ab4: { // 0x474ab4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00474ab5: { // 0x474ab5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00474ab6: { // 0x474ab6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00474ab8: { // 0x474ab8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00474ab9: { // 0x474ab9: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  L00474abc: { // 0x474abc: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L00474abf: { // 0x474abf: 0f8485010000 JZ 0x00474c4a
    if(integer::condition("JZ",flags)) goto L00474c4a;
  }
  L00474ac5: { // 0x474ac5: 8b151ce1a100 MOV EDX,dword ptr [0x00a1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00474acb: { // 0x474acb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00474acd: { // 0x474acd: 8a861e010000 MOV AL,byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00474ad3: { // 0x474ad3: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00474ad7: { // 0x474ad7: 8b2c8a MOV EBP,dword ptr [EDX + ECX*0x4]
    s.bp = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L00474ada: { // 0x474ada: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00474adc: { // 0x474adc: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474ae0: { // 0x474ae0: 8a9579020000 MOV DL,byte ptr [EBP + 0x279]
    s.dx = with_al(s.dx, m.r8((s.bp+0x00000279u)));
  }
  L00474ae6: { // 0x474ae6: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00474ae8: { // 0x474ae8: 0f8495000000 JZ 0x00474b83
    if(integer::condition("JZ",flags)) goto L00474b83;
  }
  L00474aee: { // 0x474aee: e83dfc1500 CALL 0x005d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4672243u); flags=s.arithmetic_flags;
  }
  L00474af3: { // 0x474af3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00474af6: { // 0x474af6: 0f84bc000000 JZ 0x00474bb8
    if(integer::condition("JZ",flags)) goto L00474bb8;
  }
  L00474afc: { // 0x474afc: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L00474b02: { // 0x474b02: 8b3c81 MOV EDI,dword ptr [ECX + EAX*0x4]
    s.di = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00474b05: { // 0x474b05: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L00474b0b: { // 0x474b0b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00474b0d: { // 0x474b0d: 7443 JZ 0x00474b52
    if(integer::condition("JZ",flags)) goto L00474b52;
  }
  L00474b0f: { // 0x474b0f: 8b87ec000000 MOV EAX,dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  L00474b15: { // 0x474b15: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00474b1b: { // 0x474b1b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b1c: { // 0x474b1c: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L00474b1f: { // 0x474b1f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474b21: { // 0x474b21: 0fbf5624 MOVSX EDX,word ptr [ESI + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474b25: { // 0x474b25: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474b27: { // 0x474b27: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474b2b: { // 0x474b2b: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00474b2e: { // 0x474b2e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b2f: { // 0x474b2f: c1fb02 SAR EBX,0x2
    s.bx = integer::shift(s.bx,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474b32: { // 0x474b32: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00474b34: { // 0x474b34: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00474b35: { // 0x474b35: 8b87e0000000 MOV EAX,dword ptr [EDI + 0xe0]
    s.ax = m.r32((s.di+0x000000e0u));
  }
  L00474b3b: { // 0x474b3b: 0fafcb IMUL ECX,EBX
    s.cx = integer::imul(s.cx,s.bx,32,flags);
  }
  L00474b3e: { // 0x474b3e: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00474b40: { // 0x474b40: 8b8864020000 MOV ECX,dword ptr [EAX + 0x264]
    s.cx = m.r32((s.ax+0x00000264u));
  }
  L00474b46: { // 0x474b46: 8b87e8000000 MOV EAX,dword ptr [EDI + 0xe8]
    s.ax = m.r32((s.di+0x000000e8u));
  }
  L00474b4c: { // 0x474b4c: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00474b4e: { // 0x474b4e: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00474b50: { // 0x474b50: eb1e JMP 0x00474b70
    goto L00474b70;
  }
  L00474b52: { // 0x474b52: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474b56: { // 0x474b56: 0fbf4e24 MOVSX ECX,word ptr [ESI + 0x24]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474b5a: { // 0x474b5a: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00474b5d: { // 0x474b5d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b5e: { // 0x474b5e: f7bfe8000000 IDIV dword ptr [EDI + 0xe8]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.di+0x000000e8u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00474b64: { // 0x474b64: 8b87e0000000 MOV EAX,dword ptr [EDI + 0xe0]
    s.ax = m.r32((s.di+0x000000e0u));
  }
  L00474b6a: { // 0x474b6a: 039064020000 ADD EDX,dword ptr [EAX + 0x264]
    s.dx = integer::add(s.dx,m.r32((s.ax+0x00000264u)),32,flags);
  }
  L00474b70: { // 0x474b70: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00474b76: { // 0x474b76: 8b0c91 MOV ECX,dword ptr [ECX + EDX*0x4]
    s.cx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L00474b79: { // 0x474b79: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00474b7b: { // 0x474b7b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4672385u); flags=s.arithmetic_flags;
  }
  L00474b81: { // 0x474b81: eb31 JMP 0x00474bb4
    goto L00474bb4;
  }
  L00474b83: { // 0x474b83: 8a8d84020000 MOV CL,byte ptr [EBP + 0x284]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000284u)));
  }
  L00474b89: { // 0x474b89: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00474b8b: { // 0x474b8b: 741c JZ 0x00474ba9
    if(integer::condition("JZ",flags)) goto L00474ba9;
  }
  L00474b8d: { // 0x474b8d: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  L00474b90: { // 0x474b90: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474b94: { // 0x474b94: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00474b96: { // 0x474b96: 7420 JZ 0x00474bb8
    if(integer::condition("JZ",flags)) goto L00474bb8;
  }
  L00474b98: { // 0x474b98: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00474b9c: { // 0x474b9c: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L00474ba0: { // 0x474ba0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474ba1: { // 0x474ba1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474ba2: { // 0x474ba2: e8d93efeff CALL 0x00458a80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00458a80u,4672423u); flags=s.arithmetic_flags;
  }
  L00474ba7: { // 0x474ba7: eb0f JMP 0x00474bb8
    goto L00474bb8;
  }
  L00474ba9: { // 0x474ba9: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00474bac: { // 0x474bac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00474bae: { // 0x474bae: ff909c000000 CALL dword ptr [EAX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000009cu)),4672436u); flags=s.arithmetic_flags;
  }
  L00474bb4: { // 0x474bb4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474bb8: { // 0x474bb8: 0fbf4624 MOVSX EAX,word ptr [ESI + 0x24]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474bbc: { // 0x474bbc: 0fbf4e26 MOVSX ECX,word ptr [ESI + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474bc0: { // 0x474bc0: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bc3: { // 0x474bc3: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00474bc8: { // 0x474bc8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474bc9: { // 0x474bc9: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474bcf: { // 0x474bcf: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bd2: { // 0x474bd2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474bd4: { // 0x474bd4: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00474bda: { // 0x474bda: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474bdc: { // 0x474bdc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00474bde: { // 0x474bde: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474bdf: { // 0x474bdf: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474be5: { // 0x474be5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474be7: { // 0x474be7: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474be9: { // 0x474be9: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00474bed: { // 0x474bed: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474bf0: { // 0x474bf0: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474bf3: { // 0x474bf3: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00474bf7: { // 0x474bf7: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00474bfb: { // 0x474bfb: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bfe: { // 0x474bfe: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474c01: { // 0x474c01: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00474c02: { // 0x474c02: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00474c08: { // 0x474c08: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474c09: { // 0x474c09: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L00474c0d: { // 0x474c0d: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00474c11: { // 0x474c11: e8fa332200 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,4672534u); flags=s.arithmetic_flags;
  }
  L00474c16: { // 0x474c16: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00474c1a: { // 0x474c1a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00474c1c: { // 0x474c1c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474c1d: { // 0x474c1d: e81e040000 CALL 0x00475040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475040u,4672546u); flags=s.arithmetic_flags;
  }
  L00474c22: { // 0x474c22: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00474c26: { // 0x474c26: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00474c28: { // 0x474c28: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00474c2c: { // 0x474c2c: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00474c2e: { // 0x474c2e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00474c32: { // 0x474c32: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00474c35: { // 0x474c35: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00474c37: { // 0x474c37: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00474c3b: { // 0x474c3b: 83e91e SUB ECX,0x1e
    s.cx = integer::sub(s.cx,0x0000001eu,32,flags);
  }
  L00474c3e: { // 0x474c3e: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L00474c42: { // 0x474c42: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00474c44: { // 0x474c44: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00474c48: { // 0x474c48: 7523 JNZ 0x00474c6d
    if(integer::condition("JNZ",flags)) goto L00474c6d;
  }
  L00474c4a: { // 0x474c4a: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00474c4e: { // 0x474c4e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474c50: { // 0x474c50: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474c52: { // 0x474c52: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474c54: { // 0x474c54: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474c56: { // 0x474c56: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474c58: { // 0x474c58: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L00474c5a: { // 0x474c5a: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00474c5d: { // 0x474c5d: 897308 MOV dword ptr [EBX + 0x8],ESI
    m.w32((s.bx+0x00000008u), s.si);
  }
  L00474c60: { // 0x474c60: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L00474c63: { // 0x474c63: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474c64: { // 0x474c64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474c65: { // 0x474c65: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474c66: { // 0x474c66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474c67: { // 0x474c67: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00474c6a: { // 0x474c6a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00474c6d: { // 0x474c6d: 8a857a020000 MOV AL,byte ptr [EBP + 0x27a]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000027au)));
  }
  L00474c73: { // 0x474c73: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00474c75: { // 0x474c75: 7408 JZ 0x00474c7f
    if(integer::condition("JZ",flags)) goto L00474c7f;
  }
  L00474c77: { // 0x474c77: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00474c79: { // 0x474c79: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00474c7d: { // 0x474c7d: eb04 JMP 0x00474c83
    goto L00474c83;
  }
  L00474c7f: { // 0x474c7f: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00474c83: { // 0x474c83: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00474c87: { // 0x474c87: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474c88: { // 0x474c88: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474c8a: { // 0x474c8a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474c8c: { // 0x474c8c: 0fbf4704 MOVSX EAX,word ptr [EDI + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L00474c90: { // 0x474c90: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474c91: { // 0x474c91: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474c93: { // 0x474c93: 0fbf5706 MOVSX EDX,word ptr [EDI + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000006u)),16));
  }
  L00474c97: { // 0x474c97: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474c99: { // 0x474c99: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474c9b: { // 0x474c9b: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00474c9d: { // 0x474c9d: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00474c9f: { // 0x474c9f: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00474ca1: { // 0x474ca1: 731f JNC 0x00474cc2
    if(integer::condition("JNC",flags)) goto L00474cc2;
  }
  L00474ca3: { // 0x474ca3: 8d446d00 LEA EAX,[EBP + EBP*0x2]
    s.ax = (s.bp+(s.bp * 0x00000002u));
  }
  L00474ca7: { // 0x474ca7: 8d44c708 LEA EAX,[EDI + EAX*0x8 + 0x8]
    s.ax = (s.di+(s.ax * 0x00000008u)+0x00000008u);
  }
  L00474cab: { // 0x474cab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474cad: { // 0x474cad: 7413 JZ 0x00474cc2
    if(integer::condition("JZ",flags)) goto L00474cc2;
  }
  L00474caf: { // 0x474caf: 0fbf28 MOVSX EBP,word ptr [EAX]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00474cb2: { // 0x474cb2: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00474cb6: { // 0x474cb6: 0fbf7804 MOVSX EDI,word ptr [EAX + 0x4]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L00474cba: { // 0x474cba: 0fbf5806 MOVSX EBX,word ptr [EAX + 0x6]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L00474cbe: { // 0x474cbe: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00474cc0: { // 0x474cc0: eb17 JMP 0x00474cd9
    goto L00474cd9;
  }
  L00474cc2: { // 0x474cc2: a1008f8300 MOV EAX,[0x00838f00]
    s.ax = m.r32((0x00838f00u));
  }
  L00474cc7: { // 0x474cc7: 8b15048f8300 MOV EDX,dword ptr [0x00838f04]
    s.dx = m.r32((0x00838f04u));
  }
  L00474ccd: { // 0x474ccd: 8b3d088f8300 MOV EDI,dword ptr [0x00838f08]
    s.di = m.r32((0x00838f08u));
  }
  L00474cd3: { // 0x474cd3: 8b1d0c8f8300 MOV EBX,dword ptr [0x00838f0c]
    s.bx = m.r32((0x00838f0cu));
  }
  L00474cd9: { // 0x474cd9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00474cdb: { // 0x474cdb: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00474cdf: { // 0x474cdf: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00474ce1: { // 0x474ce1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00474ce3: { // 0x474ce3: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L00474ce5: { // 0x474ce5: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L00474ce8: { // 0x474ce8: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00474ceb: { // 0x474ceb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474cec: { // 0x474cec: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  L00474cef: { // 0x474cef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474cf0: { // 0x474cf0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474cf1: { // 0x474cf1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474cf2: { // 0x474cf2: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00474cf5: { // 0x474cf5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00298660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698660: { // 0x698660: 83ec58 SUB ESP,0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L00698663: { // 0x698663: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L00698669: { // 0x698669: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069866a: { // 0x69866a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069866c: { // 0x69866c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069866d: { // 0x69866d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069866e: { // 0x69866e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00698670: { // 0x698670: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698671: { // 0x698671: c7442418ffffffff MOV dword ptr [ESP + 0x18],0xffffffff
    m.w32((f.sp+0x00000018u), 0xffffffffu);
  }
  L00698679: { // 0x698679: c744241cffffff7f MOV dword ptr [ESP + 0x1c],0x7fffffff
    m.w32((f.sp+0x0000001cu), 0x7fffffffu);
  }
  L00698681: { // 0x698681: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00698685: { // 0x698685: 0f8e6d020000 JLE 0x006988f8
    if(integer::condition("JLE",flags)) goto L006988f8;
  }
  L0069868b: { // 0x69868b: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0069868f: { // 0x69868f: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L00698694: { // 0x698694: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00698698: { // 0x698698: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069869a: { // 0x69869a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069869c: { // 0x69869c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069869e: { // 0x69869e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006986a0: { // 0x6986a0: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L006986a4: { // 0x6986a4: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006986a7: { // 0x6986a7: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L006986ab: { // 0x6986ab: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006986ae: { // 0x6986ae: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L006986b2: { // 0x6986b2: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L006986b6: { // 0x6986b6: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L006986b9: { // 0x6986b9: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L006986bd: { // 0x6986bd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006986be: { // 0x6986be: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L006986c2: { // 0x6986c2: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L006986c6: { // 0x6986c6: e82577d8ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6915787u); flags=s.arithmetic_flags;
  }
  L006986cb: { // 0x6986cb: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006986cd: { // 0x6986cd: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L006986d1: { // 0x6986d1: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L006986d5: { // 0x6986d5: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L006986d9: { // 0x6986d9: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L006986dc: { // 0x6986dc: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006986e0: { // 0x6986e0: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L006986e4: { // 0x6986e4: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006986e7: { // 0x6986e7: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L006986eb: { // 0x6986eb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L006986ef: { // 0x6986ef: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L006986f2: { // 0x6986f2: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006986f4: { // 0x6986f4: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L006986f8: { // 0x6986f8: 0f8e92000000 JLE 0x00698790
    if(integer::condition("JLE",flags)) goto L00698790;
  }
  L006986fe: { // 0x6986fe: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00698700: { // 0x698700: 0f8e8a000000 JLE 0x00698790
    if(integer::condition("JLE",flags)) goto L00698790;
  }
  L00698706: { // 0x698706: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L0069870a: { // 0x69870a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0069870c: { // 0x69870c: 7e74 JLE 0x00698782
    if(integer::condition("JLE",flags)) goto L00698782;
  }
  L0069870e: { // 0x69870e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00698712: { // 0x698712: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698714: { // 0x698714: 7e6c JLE 0x00698782
    if(integer::condition("JLE",flags)) goto L00698782;
  }
  L00698716: { // 0x698716: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L00698718: { // 0x698718: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    s.bp = m.r32((f.sp+0x0000006cu));
  }
  L0069871c: { // 0x69871c: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L0069871e: { // 0x69871e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698720: { // 0x698720: 7e06 JLE 0x00698728
    if(integer::condition("JLE",flags)) goto L00698728;
  }
  L00698722: { // 0x698722: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00698724: { // 0x698724: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698726: { // 0x698726: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00698728: { // 0x698728: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L0069872c: { // 0x69872c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069872e: { // 0x69872e: 7e06 JLE 0x00698736
    if(integer::condition("JLE",flags)) goto L00698736;
  }
  L00698730: { // 0x698730: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00698732: { // 0x698732: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00698734: { // 0x698734: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00698736: { // 0x698736: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0069873a: { // 0x69873a: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069873c: { // 0x69873c: 8d2c10 LEA EBP,[EAX + EDX*0x1]
    s.bp = (s.ax+(s.dx * 0x00000001u));
  }
  L0069873f: { // 0x69873f: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00698741: { // 0x698741: 7d0e JGE 0x00698751
    if(integer::condition("JGE",flags)) goto L00698751;
  }
  L00698743: { // 0x698743: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00698747: { // 0x698747: 8b5c246c MOV EBX,dword ptr [ESP + 0x6c]
    s.bx = m.r32((f.sp+0x0000006cu));
  }
  L0069874b: { // 0x69874b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069874d: { // 0x69874d: 8d441801 LEA EAX,[EAX + EBX*0x1 + 0x1]
    s.ax = (s.ax+(s.bx * 0x00000001u)+0x00000001u);
  }
  L00698751: { // 0x698751: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L00698755: { // 0x698755: 8b6c2478 MOV EBP,dword ptr [ESP + 0x78]
    s.bp = m.r32((f.sp+0x00000078u));
  }
  L00698759: { // 0x698759: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069875b: { // 0x69875b: 8d2c0e LEA EBP,[ESI + ECX*0x1]
    s.bp = (s.si+(s.cx * 0x00000001u));
  }
  L0069875e: { // 0x69875e: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00698760: { // 0x698760: 7d0e JGE 0x00698770
    if(integer::condition("JGE",flags)) goto L00698770;
  }
  L00698762: { // 0x698762: 8b742470 MOV ESI,dword ptr [ESP + 0x70]
    s.si = m.r32((f.sp+0x00000070u));
  }
  L00698766: { // 0x698766: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L0069876a: { // 0x69876a: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0069876c: { // 0x69876c: 8d741e01 LEA ESI,[ESI + EBX*0x1 + 0x1]
    s.si = (s.si+(s.bx * 0x00000001u)+0x00000001u);
  }
  L00698770: { // 0x698770: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L00698774: { // 0x698774: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00698778: { // 0x698778: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069877c: { // 0x69877c: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00698780: { // 0x698780: eb26 JMP 0x006987a8
    goto L006987a8;
  }
  L00698782: { // 0x698782: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00698786: { // 0x698786: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0069878a: { // 0x69878a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069878c: { // 0x69878c: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0069878e: { // 0x69878e: eb18 JMP 0x006987a8
    goto L006987a8;
  }
  L00698790: { // 0x698790: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00698794: { // 0x698794: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00698798: { // 0x698798: 8b742478 MOV ESI,dword ptr [ESP + 0x78]
    s.si = m.r32((f.sp+0x00000078u));
  }
  L0069879c: { // 0x69879c: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L006987a0: { // 0x6987a0: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L006987a4: { // 0x6987a4: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006987a8: { // 0x6987a8: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006987ac: { // 0x6987ac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006987ae: { // 0x6987ae: 0f8e15010000 JLE 0x006988c9
    if(integer::condition("JLE",flags)) goto L006988c9;
  }
  L006987b4: { // 0x6987b4: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006987b8: { // 0x6987b8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006987ba: { // 0x6987ba: 0f8e09010000 JLE 0x006988c9
    if(integer::condition("JLE",flags)) goto L006988c9;
  }
  L006987c0: { // 0x6987c0: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L006987c4: { // 0x6987c4: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L006987c8: { // 0x6987c8: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L006987ca: { // 0x6987ca: 754b JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987cc: { // 0x6987cc: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L006987d0: { // 0x6987d0: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L006987d4: { // 0x6987d4: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987d6: { // 0x6987d6: 753f JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987d8: { // 0x6987d8: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006987dc: { // 0x6987dc: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L006987e0: { // 0x6987e0: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987e2: { // 0x6987e2: 7533 JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987e4: { // 0x6987e4: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006987e8: { // 0x6987e8: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L006987ec: { // 0x6987ec: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987ee: { // 0x6987ee: 7527 JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987f0: { // 0x6987f0: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L006987f4: { // 0x6987f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006987f6: { // 0x6987f6: 0f840c020000 JZ 0x00698a08
    if(integer::condition("JZ",flags)) goto L00698a08;
  }
  L006987fc: { // 0x6987fc: 8b15bc60aa00 MOV EDX,dword ptr [0x00aa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00698802: { // 0x698802: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698806: { // 0x698806: 8a4c1010 MOV CL,byte ptr [EAX + EDX*0x1 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000001u)+0x00000010u)));
  }
  L0069880a: { // 0x69880a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069880c: { // 0x69880c: 0f85f6010000 JNZ 0x00698a08
    if(integer::condition("JNZ",flags)) goto L00698a08;
  }
  L00698812: { // 0x698812: e9b2000000 JMP 0x006988c9
    goto L006988c9;
  }
  L00698817: { // 0x698817: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  L0069881b: { // 0x69881b: 0f8581000000 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698821: { // 0x698821: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00698825: { // 0x698825: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00698829: { // 0x698829: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0069882b: { // 0x69882b: 7575 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L0069882d: { // 0x69882d: 397c2428 CMP dword ptr [ESP + 0x28],EDI
    (void)integer::sub(m.r32((f.sp+0x00000028u)),s.di,32,flags);
  }
  L00698831: { // 0x698831: 756f JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698833: { // 0x698833: 396c242c CMP dword ptr [ESP + 0x2c],EBP
    (void)integer::sub(m.r32((f.sp+0x0000002cu)),s.bp,32,flags);
  }
  L00698837: { // 0x698837: 7569 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698839: { // 0x698839: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L0069883d: { // 0x69883d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069883f: { // 0x69883f: 7512 JNZ 0x00698853
    if(integer::condition("JNZ",flags)) goto L00698853;
  }
  L00698841: { // 0x698841: 8b15bc60aa00 MOV EDX,dword ptr [0x00aa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00698847: { // 0x698847: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0069884b: { // 0x69884b: 8a4c1010 MOV CL,byte ptr [EAX + EDX*0x1 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000001u)+0x00000010u)));
  }
  L0069884f: { // 0x69884f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00698851: { // 0x698851: 7576 JNZ 0x006988c9
    if(integer::condition("JNZ",flags)) goto L006988c9;
  }
  L00698853: { // 0x698853: a1c860aa00 MOV EAX,[0x00aa60c8]
    s.ax = m.r32((0x00aa60c8u));
  }
  L00698858: { // 0x698858: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069885c: { // 0x69885c: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0069885e: { // 0x69885e: 7d30 JGE 0x00698890
    if(integer::condition("JGE",flags)) goto L00698890;
  }
  L00698860: { // 0x698860: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00698861: { // 0x698861: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00698863: { // 0x698863: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00698865: { // 0x698865: a3c860aa00 MOV [0x00aa60c8],EAX
    m.w32((0x00aa60c8u), s.ax);
  }
  L0069886a: { // 0x69886a: 7d24 JGE 0x00698890
    if(integer::condition("JGE",flags)) goto L00698890;
  }
  L0069886c: { // 0x69886c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698870: { // 0x698870: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L00698876: { // 0x698876: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00698877: { // 0x698877: 8d740814 LEA ESI,[EAX + ECX*0x1 + 0x14]
    s.si = (s.ax+(s.cx * 0x00000001u)+0x00000014u);
  }
  L0069887b: { // 0x69887b: 8d3c08 LEA EDI,[EAX + ECX*0x1]
    s.di = (s.ax+(s.cx * 0x00000001u));
  }
  L0069887e: { // 0x69887e: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L00698883: { // 0x698883: 83c014 ADD EAX,0x14
    s.ax = integer::add(s.ax,0x00000014u,32,flags);
  }
  L00698886: { // 0x698886: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00698888: { // 0x698888: 3b15c860aa00 CMP EDX,dword ptr [0x00aa60c8]
    (void)integer::sub(s.dx,m.r32((0x00aa60c8u)),32,flags);
  }
  L0069888e: { // 0x69888e: 7ce0 JL 0x00698870
    if(integer::condition("JL",flags)) goto L00698870;
  }
  L00698890: { // 0x698890: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698894: { // 0x698894: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00698895: { // 0x698895: 83e814 SUB EAX,0x14
    s.ax = integer::sub(s.ax,0x00000014u,32,flags);
  }
  L00698898: { // 0x698898: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0069889c: { // 0x69889c: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006988a0: { // 0x6988a0: eb27 JMP 0x006988c9
    goto L006988c9;
  }
  L006988a2: { // 0x6988a2: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L006988a6: { // 0x6988a6: 0fafef IMUL EBP,EDI
    s.bp = integer::imul(s.bp,s.di,32,flags);
  }
  L006988a9: { // 0x6988a9: 0faf4c2474 IMUL ECX,dword ptr [ESP + 0x74]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x00000074u)),32,flags);
  }
  L006988ae: { // 0x6988ae: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L006988b1: { // 0x6988b1: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L006988b3: { // 0x6988b3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006988b5: { // 0x6988b5: 7d12 JGE 0x006988c9
    if(integer::condition("JGE",flags)) goto L006988c9;
  }
  L006988b7: { // 0x6988b7: 3b44241c CMP EAX,dword ptr [ESP + 0x1c]
    (void)integer::sub(s.ax,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L006988bb: { // 0x6988bb: 7d0c JGE 0x006988c9
    if(integer::condition("JGE",flags)) goto L006988c9;
  }
  L006988bd: { // 0x6988bd: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L006988c1: { // 0x6988c1: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006988c5: { // 0x6988c5: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006988c9: { // 0x6988c9: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006988cd: { // 0x6988cd: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L006988d1: { // 0x6988d1: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L006988d7: { // 0x6988d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006988d8: { // 0x6988d8: 83c614 ADD ESI,0x14
    s.si = integer::add(s.si,0x00000014u,32,flags);
  }
  L006988db: { // 0x6988db: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006988dd: { // 0x6988dd: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006988e1: { // 0x6988e1: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006988e5: { // 0x6988e5: 0f8ca4fdffff JL 0x0069868f
    if(integer::condition("JL",flags)) goto L0069868f;
  }
  L006988eb: { // 0x6988eb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006988ef: { // 0x6988ef: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006988f2: { // 0x6988f2: 0f859c000000 JNZ 0x00698994
    if(integer::condition("JNZ",flags)) goto L00698994;
  }
  L006988f8: { // 0x6988f8: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    s.ax = m.r32((f.sp+0x0000006cu));
  }
  L006988fc: { // 0x6988fc: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00698900: { // 0x698900: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00698904: { // 0x698904: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00698908: { // 0x698908: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0069890c: { // 0x69890c: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L00698910: { // 0x698910: 88442464 MOV byte ptr [ESP + 0x64],AL
    m.w8((f.sp+0x00000064u), (s.ax & 0xffu));
  }
  L00698914: { // 0x698914: a1c060aa00 MOV EAX,[0x00aa60c0]
    s.ax = m.r32((0x00aa60c0u));
  }
  L00698919: { // 0x698919: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0069891d: { // 0x69891d: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L00698921: { // 0x698921: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00698923: { // 0x698923: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00698927: { // 0x698927: 7c3b JL 0x00698964
    if(integer::condition("JL",flags)) goto L00698964;
  }
  L00698929: { // 0x698929: 8a0dc560aa00 MOV CL,byte ptr [0x00aa60c5]
    s.cx = with_al(s.cx, m.r8((0x00aa60c5u)));
  }
  L0069892f: { // 0x69892f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00698931: { // 0x698931: 7508 JNZ 0x0069893b
    if(integer::condition("JNZ",flags)) goto L0069893b;
  }
  L00698933: { // 0x698933: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698935: { // 0x698935: 0f85cd000000 JNZ 0x00698a08
    if(integer::condition("JNZ",flags)) goto L00698a08;
  }
  L0069893b: { // 0x69893b: 8b0dcc60aa00 MOV ECX,dword ptr [0x00aa60cc]
    s.cx = m.r32((0x00aa60ccu));
  }
  L00698941: { // 0x698941: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00698943: { // 0x698943: 0f8ebf000000 JLE 0x00698a08
    if(integer::condition("JLE",flags)) goto L00698a08;
  }
  L00698949: { // 0x698949: 8b15b860aa00 MOV EDX,dword ptr [0x00aa60b8]
    s.dx = m.r32((0x00aa60b8u));
  }
  L0069894f: { // 0x69894f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00698951: { // 0x698951: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00698953: { // 0x698953: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698954: { // 0x698954: b9b860aa00 MOV ECX,0xaa60b8
    s.cx = 0x00aa60b8u;
  }
  L00698959: { // 0x698959: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6916444u); flags=s.arithmetic_flags;
  }
  L0069895c: { // 0x69895c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069895e: { // 0x69895e: 0f84a4000000 JZ 0x00698a08
    if(integer::condition("JZ",flags)) goto L00698a08;
  }
  L00698964: { // 0x698964: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L0069896a: { // 0x69896a: 8d742454 LEA ESI,[ESP + 0x54]
    s.si = (f.sp+0x00000054u);
  }
  L0069896e: { // 0x69896e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698970: { // 0x698970: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00698971: { // 0x698971: 890dc860aa00 MOV dword ptr [0x00aa60c8],ECX
    m.w32((0x00aa60c8u), s.cx);
  }
  L00698977: { // 0x698977: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L0069897d: { // 0x69897d: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698980: { // 0x698980: 8d3c81 LEA EDI,[ECX + EAX*0x4]
    s.di = (s.cx+(s.ax * 0x00000004u));
  }
  L00698983: { // 0x698983: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L00698988: { // 0x698988: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0069898a: { // 0x69898a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069898b: { // 0x69898b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069898c: { // 0x69898c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069898d: { // 0x69898d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069898e: { // 0x69898e: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00698991: { // 0x698991: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00698994: { // 0x698994: 8a4c247c MOV CL,byte ptr [ESP + 0x7c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000007cu)));
  }
  L00698998: { // 0x698998: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069899a: { // 0x69899a: 7514 JNZ 0x006989b0
    if(integer::condition("JNZ",flags)) goto L006989b0;
  }
  L0069899c: { // 0x69899c: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0069899f: { // 0x69899f: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L006989a4: { // 0x6989a4: 8a4c9010 MOV CL,byte ptr [EAX + EDX*0x4 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000004u)+0x00000010u)));
  }
  L006989a8: { // 0x6989a8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006989aa: { // 0x6989aa: 7504 JNZ 0x006989b0
    if(integer::condition("JNZ",flags)) goto L006989b0;
  }
  L006989ac: { // 0x6989ac: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006989ae: { // 0x6989ae: eb05 JMP 0x006989b5
    goto L006989b5;
  }
  L006989b0: { // 0x6989b0: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006989b5: { // 0x6989b5: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L006989b9: { // 0x6989b9: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L006989bf: { // 0x6989bf: 8d34b6 LEA ESI,[ESI + ESI*0x4]
    s.si = (s.si+(s.si * 0x00000004u));
  }
  L006989c2: { // 0x6989c2: c1e602 SHL ESI,0x2
    s.si = integer::shift(s.si,0x00000002u,32,flags,integer::Shift::left);
  }
  L006989c5: { // 0x6989c5: 8d140e LEA EDX,[ESI + ECX*0x1]
    s.dx = (s.si+(s.cx * 0x00000001u));
  }
  L006989c8: { // 0x6989c8: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L006989cc: { // 0x6989cc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006989cd: { // 0x6989cd: 8d542470 LEA EDX,[ESP + 0x70]
    s.dx = (f.sp+0x00000070u);
  }
  L006989d1: { // 0x6989d1: e87a62dcff CALL 0x0045ec50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0045ec50u,6916566u); flags=s.arithmetic_flags;
  }
  L006989d6: { // 0x6989d6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006989d8: { // 0x6989d8: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006989db: { // 0x6989db: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006989df: { // 0x6989df: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006989e2: { // 0x6989e2: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L006989e6: { // 0x6989e6: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006989e9: { // 0x6989e9: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L006989ee: { // 0x6989ee: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L006989f2: { // 0x6989f2: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L006989f7: { // 0x6989f7: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L006989fb: { // 0x6989fb: 8d3c06 LEA EDI,[ESI + EAX*0x1]
    s.di = (s.si+(s.ax * 0x00000001u));
  }
  L006989fe: { // 0x6989fe: 8d742440 LEA ESI,[ESP + 0x40]
    s.si = (f.sp+0x00000040u);
  }
  L00698a02: { // 0x698a02: 885c2450 MOV byte ptr [ESP + 0x50],BL
    m.w8((f.sp+0x00000050u), (s.bx & 0xffu));
  }
  L00698a06: { // 0x698a06: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00698a08: { // 0x698a08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00698a09: { // 0x698a09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00698a0a: { // 0x698a0a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00698a0b: { // 0x698a0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00698a0c: { // 0x698a0c: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00698a0f: { // 0x698a0f: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_002a0410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a0410: { // 0x6a0410: a12ca88100 MOV EAX,[0x0081a82c]
    s.ax = m.r32((0x0081a82cu));
  }
  L006a0415: { // 0x6a0415: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006a0418: { // 0x6a0418: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a041a: { // 0x6a041a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006a041b: { // 0x6a041b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006a041c: { // 0x6a041c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006a041d: { // 0x6a041d: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006a041f: { // 0x6a041f: 0f858a010000 JNZ 0x006a05af
    if(integer::condition("JNZ",flags)) goto L006a05af;
  }
  L006a0425: { // 0x6a0425: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L006a0429: { // 0x6a0429: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006a042e: { // 0x6a042e: 39475c CMP dword ptr [EDI + 0x5c],EAX
    (void)integer::sub(m.r32((s.di+0x0000005cu)),s.ax,32,flags);
  }
  L006a0431: { // 0x6a0431: 0f8478010000 JZ 0x006a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a0437: { // 0x6a0437: f6872c01000008 TEST byte ptr [EDI + 0x12c],0x8
    (void)integer::logical((m.r8((s.di+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L006a043e: { // 0x6a043e: 750e JNZ 0x006a044e
    if(integer::condition("JNZ",flags)) goto L006a044e;
  }
  L006a0440: { // 0x6a0440: 8a8f38010000 MOV CL,byte ptr [EDI + 0x138]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000138u)));
  }
  L006a0446: { // 0x6a0446: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006a0448: { // 0x6a0448: 0f8461010000 JZ 0x006a05af
    if(integer::condition("JZ",flags)) goto L006a05af;
  }
  L006a044e: { // 0x6a044e: 89475c MOV dword ptr [EDI + 0x5c],EAX
    m.w32((s.di+0x0000005cu), s.ax);
  }
  L006a0451: { // 0x6a0451: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L006a0455: { // 0x6a0455: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006a0456: { // 0x6a0456: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006a0457: { // 0x6a0457: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006a0459: { // 0x6a0459: e80255ddff CALL 0x00475960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475960u,6947934u); flags=s.arithmetic_flags;
  }
  L006a045e: { // 0x6a045e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006a0460: { // 0x6a0460: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006a0463: { // 0x6a0463: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006a0466: { // 0x6a0466: 8b872c010000 MOV EAX,dword ptr [EDI + 0x12c]
    s.ax = m.r32((s.di+0x0000012cu));
  }
  L006a046c: { // 0x6a046c: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L006a046e: { // 0x6a046e: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006a0472: { // 0x6a0472: 744b JZ 0x006a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0474: { // 0x6a0474: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L006a0476: { // 0x6a0476: 7447 JZ 0x006a04bf
    if(integer::condition("JZ",flags)) goto L006a04bf;
  }
  L006a0478: { // 0x6a0478: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a047b: { // 0x6a047b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a047e: { // 0x6a047e: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a0481: { // 0x6a0481: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0482: { // 0x6a0482: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0484: { // 0x6a0484: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006a0486: { // 0x6a0486: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a0489: { // 0x6a0489: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a048b: { // 0x6a048b: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a048e: { // 0x6a048e: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a0490: { // 0x6a0490: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0491: { // 0x6a0491: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0493: { // 0x6a0493: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a0495: { // 0x6a0495: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a0497: { // 0x6a0497: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006a049a: { // 0x6a049a: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a049c: { // 0x6a049c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a049e: { // 0x6a049e: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04a1: { // 0x6a04a1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04a2: { // 0x6a04a2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04a4: { // 0x6a04a4: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04a6: { // 0x6a04a6: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04a8: { // 0x6a04a8: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L006a04ab: { // 0x6a04ab: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ad: { // 0x6a04ad: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04b0: { // 0x6a04b0: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04b4: { // 0x6a04b4: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04b6: { // 0x6a04b6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04b7: { // 0x6a04b7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04b9: { // 0x6a04b9: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04bb: { // 0x6a04bb: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a04bd: { // 0x6a04bd: eb45 JMP 0x006a0504
    goto L006a0504;
  }
  L006a04bf: { // 0x6a04bf: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a04c2: { // 0x6a04c2: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04c5: { // 0x6a04c5: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04c8: { // 0x6a04c8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04c9: { // 0x6a04c9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04cb: { // 0x6a04cb: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006a04cd: { // 0x6a04cd: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  L006a04d0: { // 0x6a04d0: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04d2: { // 0x6a04d2: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04d5: { // 0x6a04d5: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04d7: { // 0x6a04d7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04d8: { // 0x6a04d8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04da: { // 0x6a04da: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a04dc: { // 0x6a04dc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006a04de: { // 0x6a04de: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006a04e1: { // 0x6a04e1: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006a04e3: { // 0x6a04e3: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006a04e5: { // 0x6a04e5: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006a04e8: { // 0x6a04e8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04e9: { // 0x6a04e9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a04eb: { // 0x6a04eb: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04ed: { // 0x6a04ed: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L006a04ef: { // 0x6a04ef: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L006a04f2: { // 0x6a04f2: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a04f4: { // 0x6a04f4: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L006a04f7: { // 0x6a04f7: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L006a04fb: { // 0x6a04fb: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L006a04fd: { // 0x6a04fd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a04fe: { // 0x6a04fe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0500: { // 0x6a0500: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0502: { // 0x6a0502: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006a0504: { // 0x6a0504: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L006a0506: { // 0x6a0506: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006a0508: { // 0x6a0508: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0509: { // 0x6a0509: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a050f: { // 0x6a050f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006a0511: { // 0x6a0511: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a0513: { // 0x6a0513: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006a0515: { // 0x6a0515: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0518: { // 0x6a0518: e8937affff CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6948125u); flags=s.arithmetic_flags;
  }
  L006a051d: { // 0x6a051d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006a051f: { // 0x6a051f: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L006a0521: { // 0x6a0521: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006a0522: { // 0x6a0522: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006a0528: { // 0x6a0528: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006a052c: { // 0x6a052c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006a052e: { // 0x6a052e: 8b93b4000000 MOV EDX,dword ptr [EBX + 0xb4]
    s.dx = m.r32((s.bx+0x000000b4u));
  }
  L006a0534: { // 0x6a0534: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006a0537: { // 0x6a0537: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006a0539: { // 0x6a0539: 8b8bb0000000 MOV ECX,dword ptr [EBX + 0xb0]
    s.cx = m.r32((s.bx+0x000000b0u));
  }
  L006a053f: { // 0x6a053f: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L006a0541: { // 0x6a0541: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L006a0547: { // 0x6a0547: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0549: { // 0x6a0549: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006a054a: { // 0x6a054a: 8d51e2 LEA EDX,[ECX + -0x1e]
    s.dx = (s.cx-0x0000001eu);
  }
  L006a054d: { // 0x6a054d: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L006a054f: { // 0x6a054f: 7c5e JL 0x006a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0551: { // 0x6a0551: 83f8e2 CMP EAX,-0x1e
    (void)integer::sub(s.ax,0xffffffe2u,32,flags);
  }
  L006a0554: { // 0x6a0554: 7c59 JL 0x006a05af
    if(integer::condition("JL",flags)) goto L006a05af;
  }
  L006a0556: { // 0x6a0556: 8b1578198200 MOV EDX,dword ptr [0x00821978]
    s.dx = m.r32((0x00821978u));
  }
  L006a055c: { // 0x6a055c: 8d4c0a1e LEA ECX,[EDX + ECX*0x1 + 0x1e]
    s.cx = (s.dx+(s.cx * 0x00000001u)+0x0000001eu);
  }
  L006a0560: { // 0x6a0560: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L006a0562: { // 0x6a0562: 7f4b JG 0x006a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0564: { // 0x6a0564: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L006a056a: { // 0x6a056a: 8b0d7c198200 MOV ECX,dword ptr [0x0082197c]
    s.cx = m.r32((0x0082197cu));
  }
  L006a0570: { // 0x6a0570: 8d54110f LEA EDX,[ECX + EDX*0x1 + 0xf]
    s.dx = (s.cx+(s.dx * 0x00000001u)+0x0000000fu);
  }
  L006a0574: { // 0x6a0574: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006a0576: { // 0x6a0576: 7f37 JG 0x006a05af
    if(integer::condition("JG",flags)) goto L006a05af;
  }
  L006a0578: { // 0x6a0578: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a057e: { // 0x6a057e: 3d1f030000 CMP EAX,0x31f
    (void)integer::sub(s.ax,0x0000031fu,32,flags);
  }
  L006a0583: { // 0x6a0583: 7d18 JGE 0x006a059d
    if(integer::condition("JGE",flags)) goto L006a059d;
  }
  L006a0585: { // 0x6a0585: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006a0589: { // 0x6a0589: 898c83e4000000 MOV dword ptr [EBX + EAX*0x4 + 0xe4],ECX
    m.w32((s.bx+(s.ax * 0x00000004u)+0x000000e4u), s.cx);
  }
  L006a0590: { // 0x6a0590: 8b83e0000000 MOV EAX,dword ptr [EBX + 0xe0]
    s.ax = m.r32((s.bx+0x000000e0u));
  }
  L006a0596: { // 0x6a0596: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006a0597: { // 0x6a0597: 8983e0000000 MOV dword ptr [EBX + 0xe0],EAX
    m.w32((s.bx+0x000000e0u), s.ax);
  }
  L006a059d: { // 0x6a059d: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L006a05a1: { // 0x6a05a1: c6823801000000 MOV byte ptr [EDX + 0x138],0x0
    m.w8((s.dx+0x00000138u), 0x00000000u);
  }
  L006a05a8: { // 0x6a05a8: c6837d0d000001 MOV byte ptr [EBX + 0xd7d],0x1
    m.w8((s.bx+0x00000d7du), 0x00000001u);
  }
  L006a05af: { // 0x6a05af: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006a05b0: { // 0x6a05b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006a05b1: { // 0x6a05b1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006a05b2: { // 0x6a05b2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006a05b5: { // 0x6a05b5: c20400 RET 0x4
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

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6487616u:f_0022fe40(m,s,child,{});break;
case 5560176u:f_0014d770(m,s,child,{});break;
case 5600560u:f_00157530(m,s,child,{});break;
case 5562752u:f_0014e180(m,s,child,{});break;
case 4686688u:f_00078360(m,s,child,{});break;
case 4701696u:f_0007be00(m,s,child,{});break;
case 6930576u:f_0029c090(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4798336u:f_00093780(m,s,child,{});break;
case 4798640u:f_000938b0(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 6106704u:f_001d2e50(m,s,child,{});break;
case 6072688u:f_001ca970(m,s,child,{});break;
case 4259600u:f_0000ff10(m,s,child,{});break;
case 4217840u:f_00005bf0(m,s,child,{});break;
case 4259792u:f_0000ffd0(m,s,child,{});break;
case 6660384u:f_0025a120(m,s,child,{});break;
case 6078240u:f_001cbf20(m,s,child,{});break;
case 4672768u:f_00074d00(m,s,child,{});break;
case 4672176u:f_00074ab0(m,s,child,{});break;
case 6915680u:f_00298660(m,s,child,{});break;
case 6947856u:f_002a0410(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 0x76d957u:{const auto request=m.r32(child.entry_sp+4);if(request!=156)throw std::domain_error("250 exact allocation");s.ax=s.heap->allocate(request);s.allocation.reset(new leaf::Memory(reinterpret_cast<unsigned char*>(std::uintptr_t(s.ax)),s.ax,156));m.add(*s.allocation);finish(m,s,child,0);break;}
default:throw std::domain_error("recovery250 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0054b8a0(Memory& original,const Inputs& i,Heap& heap){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.heap=&heap;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054b8a0: { // 0x54b8a0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0054b8a3: { // 0x54b8a3: 8d9160010000 LEA EDX,[ECX + 0x160]
    s.dx = (s.cx+0x00000160u);
  }
  L0054b8a9: { // 0x54b8a9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054b8aa: { // 0x54b8aa: 668b1d5e6ea500 MOV BX,word ptr [0x00a56e5e]
    s.bx = with_ax(s.bx, m.r16((0x00a56e5eu)));
  }
  L0054b8b1: { // 0x54b8b1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054b8b2: { // 0x54b8b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054b8b3: { // 0x54b8b3: 8b355c6ea500 MOV ESI,dword ptr [0x00a56e5c]
    s.si = m.r32((0x00a56e5cu));
  }
  L0054b8b9: { // 0x54b8b9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b8ba: { // 0x54b8ba: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0054b8bc: { // 0x54b8bc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054b8be: { // 0x54b8be: 663932 CMP word ptr [EDX],SI
    (void)integer::sub(m.r16((s.dx)),(s.si & 0xffffu),16,flags);
  }
  L0054b8c1: { // 0x54b8c1: 7506 JNZ 0x0054b8c9
    if(integer::condition("JNZ",flags)) goto L0054b8c9;
  }
  L0054b8c3: { // 0x54b8c3: 66395a02 CMP word ptr [EDX + 0x2],BX
    (void)integer::sub(m.r16((s.dx+0x00000002u)),(s.bx & 0xffffu),16,flags);
  }
  L0054b8c7: { // 0x54b8c7: 740b JZ 0x0054b8d4
    if(integer::condition("JZ",flags)) goto L0054b8d4;
  }
  L0054b8c9: { // 0x54b8c9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0054b8ca: { // 0x54b8ca: 83c210 ADD EDX,0x10
    s.dx = integer::add(s.dx,0x00000010u,32,flags);
  }
  L0054b8cd: { // 0x54b8cd: 3d00010000 CMP EAX,0x100
    (void)integer::sub(s.ax,0x00000100u,32,flags);
  }
  L0054b8d2: { // 0x54b8d2: 7cea JL 0x0054b8be
    if(integer::condition("JL",flags)) goto L0054b8be;
  }
  L0054b8d4: { // 0x54b8d4: 3d00010000 CMP EAX,0x100
    (void)integer::sub(s.ax,0x00000100u,32,flags);
  }
  L0054b8d9: { // 0x54b8d9: 0f841d010000 JZ 0x0054b9fc
    if(integer::condition("JZ",flags)) goto L0054b9fc;
  }
  L0054b8df: { // 0x54b8df: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0054b8e1: { // 0x54b8e1: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054b8e4: { // 0x54b8e4: 8dac0854010000 LEA EBP,[EAX + ECX*0x1 + 0x154]
    s.bp = (s.ax+(s.cx * 0x00000001u)+0x00000154u);
  }
  L0054b8eb: { // 0x54b8eb: a148a98100 MOV EAX,[0x0081a948]
    s.ax = m.r32((0x0081a948u));
  }
  L0054b8f0: { // 0x54b8f0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0054b8f6: { // 0x54b8f6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0054b8f7: { // 0x54b8f7: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L0054b8fd: { // 0x54b8fd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b8fe: { // 0x54b8fe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b8ff: { // 0x54b8ff: e83c450e00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5552388u); flags=s.arithmetic_flags;
  }
  L0054b904: { // 0x54b904: 8b1540a98100 MOV EDX,dword ptr [0x0081a940]
    s.dx = m.r32((0x0081a940u));
  }
  L0054b90a: { // 0x54b90a: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0054b910: { // 0x54b910: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L0054b916: { // 0x54b916: 8d3402 LEA ESI,[EDX + EAX*0x1]
    s.si = (s.dx+(s.ax * 0x00000001u));
  }
  L0054b919: { // 0x54b919: a14ca98100 MOV EAX,[0x0081a94c]
    s.ax = m.r32((0x0081a94cu));
  }
  L0054b91e: { // 0x54b91e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0054b91f: { // 0x54b91f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b920: { // 0x54b920: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b921: { // 0x54b921: e81a450e00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5552422u); flags=s.arithmetic_flags;
  }
  L0054b926: { // 0x54b926: 8b1544a98100 MOV EDX,dword ptr [0x0081a944]
    s.dx = m.r32((0x0081a944u));
  }
  L0054b92c: { // 0x54b92c: 6689742414 MOV word ptr [ESP + 0x14],SI
    m.w16((f.sp+0x00000014u), (s.si & 0xffffu));
  }
  L0054b931: { // 0x54b931: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054b933: { // 0x54b933: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L0054b938: { // 0x54b938: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0054b93c: { // 0x54b93c: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0054b93f: { // 0x54b93f: 0fbfd6 MOVSX EDX,SI
    s.dx = std::uint32_t(integer::sign_extend((s.si & 0xffffu),16));
  }
  L0054b942: { // 0x54b942: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054b945: { // 0x54b945: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054b947: { // 0x54b947: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0054b94b: { // 0x54b94b: 7814 JS 0x0054b961
    if(integer::condition("JS",flags)) goto L0054b961;
  }
  L0054b94d: { // 0x54b94d: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054b952: { // 0x54b952: 7d0d JGE 0x0054b961
    if(integer::condition("JGE",flags)) goto L0054b961;
  }
  L0054b954: { // 0x54b954: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054b95a: { // 0x54b95a: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054b95d: { // 0x54b95d: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0054b95f: { // 0x54b95f: 750b JNZ 0x0054b96c
    if(integer::condition("JNZ",flags)) goto L0054b96c;
  }
  L0054b961: { // 0x54b961: 890d3476a500 MOV dword ptr [0x00a57634],ECX
    m.w32((0x00a57634u), s.cx);
  }
  L0054b967: { // 0x54b967: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054b96c: { // 0x54b96c: 83b8ec00000002 CMP dword ptr [EAX + 0xec],0x2
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),0x00000002u,32,flags);
  }
  L0054b973: { // 0x54b973: 752e JNZ 0x0054b9a3
    if(integer::condition("JNZ",flags)) goto L0054b9a3;
  }
  L0054b975: { // 0x54b975: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0054b979: { // 0x54b979: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0054b97e: { // 0x54b97e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b97f: { // 0x54b97f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054b980: { // 0x54b980: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b981: { // 0x54b981: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b982: { // 0x54b982: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054b984: { // 0x54b984: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b985: { // 0x54b985: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b986: { // 0x54b986: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054b987: { // 0x54b987: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b988: { // 0x54b988: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b989: { // 0x54b989: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b98a: { // 0x54b98a: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0054b98c: { // 0x54b98c: 8d44243c LEA EAX,[ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  L0054b990: { // 0x54b990: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L0054b992: { // 0x54b992: 66897c2448 MOV word ptr [ESP + 0x48],DI
    m.w16((f.sp+0x00000048u), (s.di & 0xffffu));
  }
  L0054b997: { // 0x54b997: 66897c244a MOV word ptr [ESP + 0x4a],DI
    m.w16((f.sp+0x0000004au), (s.di & 0xffffu));
  }
  L0054b99c: { // 0x54b99c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b99d: { // 0x54b99d: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L0054b9a1: { // 0x54b9a1: eb2b JMP 0x0054b9ce
    goto L0054b9ce;
  }
  L0054b9a3: { // 0x54b9a3: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0054b9a7: { // 0x54b9a7: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0054b9ac: { // 0x54b9ac: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b9ad: { // 0x54b9ad: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0054b9ae: { // 0x54b9ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b9af: { // 0x54b9af: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b9b0: { // 0x54b9b0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0054b9b2: { // 0x54b9b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b9b3: { // 0x54b9b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b9b4: { // 0x54b9b4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054b9b5: { // 0x54b9b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b9b6: { // 0x54b9b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b9b7: { // 0x54b9b7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054b9b8: { // 0x54b9b8: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0054b9ba: { // 0x54b9ba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b9bb: { // 0x54b9bb: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L0054b9bf: { // 0x54b9bf: 66897c244c MOV word ptr [ESP + 0x4c],DI
    m.w16((f.sp+0x0000004cu), (s.di & 0xffffu));
  }
  L0054b9c4: { // 0x54b9c4: 66897c244e MOV word ptr [ESP + 0x4e],DI
    m.w16((f.sp+0x0000004eu), (s.di & 0xffffu));
  }
  L0054b9c9: { // 0x54b9c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b9ca: { // 0x54b9ca: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L0054b9ce: { // 0x54b9ce: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054b9cf: { // 0x54b9cf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0054b9d4: { // 0x54b9d4: e8971d0000 CALL 0x0054d770
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d770u,5552601u); flags=s.arithmetic_flags;
  }
  L0054b9d9: { // 0x54b9d9: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0054b9db: { // 0x54b9db: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0054b9df: { // 0x54b9df: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0054b9e0: { // 0x54b9e0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0054b9e2: { // 0x54b9e2: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0054b9e6: { // 0x54b9e6: e8957df4ff CALL 0x00493780
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493780u,5552619u); flags=s.arithmetic_flags;
  }
  L0054b9eb: { // 0x54b9eb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054b9ed: { // 0x54b9ed: 7517 JNZ 0x0054ba06
    if(integer::condition("JNZ",flags)) goto L0054ba06;
  }
  L0054b9ef: { // 0x54b9ef: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0054b9f0: { // 0x54b9f0: 81fbe8030000 CMP EBX,0x3e8
    (void)integer::sub(s.bx,0x000003e8u,32,flags);
  }
  L0054b9f6: { // 0x54b9f6: 0f8ceffeffff JL 0x0054b8eb
    if(integer::condition("JL",flags)) goto L0054b8eb;
  }
  L0054b9fc: { // 0x54b9fc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054b9fd: { // 0x54b9fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054b9fe: { // 0x54b9fe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054b9ff: { // 0x54b9ff: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0054ba01: { // 0x54ba01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054ba02: { // 0x54ba02: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0054ba05: { // 0x54ba05: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0054ba06: { // 0x54ba06: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054ba07: { // 0x54ba07: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054ba08: { // 0x54ba08: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054ba09: { // 0x54ba09: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0054ba0b: { // 0x54ba0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054ba0c: { // 0x54ba0c: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0054ba0f: { // 0x54ba0f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
