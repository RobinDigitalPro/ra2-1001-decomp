#include "recovered/recovery_b555_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b555 {
namespace {
void f_0009c560(Memory&,State&,Frame&,const Operations&);
void f_0019be50(Memory&,State&,Frame&,const Operations&);
void f_0019be70(Memory&,State&,Frame&,const Operations&);
void f_000f25d0(Memory&,State&,Frame&,const Operations&);
void f_0019c040(Memory&,State&,Frame&,const Operations&);
void f_0009c600(Memory&,State&,Frame&,const Operations&);
void f_0009c720(Memory&,State&,Frame&,const Operations&);
void f_0009c7c0(Memory&,State&,Frame&,const Operations&);
void f_0009c860(Memory&,State&,Frame&,const Operations&);
void f_001cb500(Memory&,State&,Frame&,const Operations&);
void f_0000dc20(Memory&,State&,Frame&,const Operations&);
void f_002eb5e0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_002be7a0(Memory&,State&,Frame&,const Operations&);
void f_000f47b0(Memory&,State&,Frame&,const Operations&);
void f_0020c1c0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_002c9510(Memory&,State&,Frame&,const Operations&);
void f_0009e0e0(Memory&,State&,Frame&,const Operations&);
void f_0029bcf0(Memory&,State&,Frame&,const Operations&);
void f_00297fb0(Memory&,State&,Frame&,const Operations&);
void f_0029e2c0(Memory&,State&,Frame&,const Operations&);
void f_0029e7b0(Memory&,State&,Frame&,const Operations&);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0001b630(Memory&,State&,Frame&,const Operations&);
void f_0001b780(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_000e0030(Memory&,State&,Frame&,const Operations&);
void f_00157ab0(Memory&,State&,Frame&,const Operations&);
void tail(Memory&,State&,Frame&,std::uint32_t);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0009c560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049c560: { // 0x49c560: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049c561: { // 0x49c561: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049c562: { // 0x49c562: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049c564: { // 0x49c564: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0049c568: { // 0x49c568: 8a86ad110000 MOV AL,byte ptr [ESI + 0x11ad]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011adu)));
  }
  L0049c56e: { // 0x49c56e: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L0049c571: { // 0x49c571: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0049c573: { // 0x49c573: 7411 JZ 0x0049c586
    if(integer::condition("JZ",flags)) goto L0049c586;
  }
  L0049c575: { // 0x49c575: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049c577: { // 0x49c577: 7409 JZ 0x0049c582
    if(integer::condition("JZ",flags)) goto L0049c582;
  }
  L0049c579: { // 0x49c579: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0049c57c: { // 0x49c57c: 750d JNZ 0x0049c58b
    if(integer::condition("JNZ",flags)) goto L0049c58b;
  }
  L0049c57e: { // 0x49c57e: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  L0049c580: { // 0x49c580: eb09 JMP 0x0049c58b
    goto L0049c58b;
  }
  L0049c582: { // 0x49c582: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0049c584: { // 0x49c584: eb05 JMP 0x0049c58b
    goto L0049c58b;
  }
  L0049c586: { // 0x49c586: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c588: { // 0x49c588: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0049c58b: { // 0x49c58b: 3ad8 CMP BL,AL
    (void)integer::sub((s.bx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0049c58d: { // 0x49c58d: 7464 JZ 0x0049c5f3
    if(integer::condition("JZ",flags)) goto L0049c5f3;
  }
  L0049c58f: { // 0x49c58f: 8b86a4110000 MOV EAX,dword ptr [ESI + 0x11a4]
    s.ax = m.r32((s.si+0x000011a4u));
  }
  L0049c595: { // 0x49c595: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c597: { // 0x49c597: 755a JNZ 0x0049c5f3
    if(integer::condition("JNZ",flags)) goto L0049c5f3;
  }
  L0049c599: { // 0x49c599: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049c59b: { // 0x49c59b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c59d: { // 0x49c59d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c59f: { // 0x49c59f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c5a1: { // 0x49c5a1: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4834724u); flags=s.arithmetic_flags;
  }
  L0049c5a4: { // 0x49c5a4: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c5a6: { // 0x49c5a6: c686ac11000000 MOV byte ptr [ESI + 0x11ac],0x0
    m.w8((s.si+0x000011acu), 0x00000000u);
  }
  L0049c5ad: { // 0x49c5ad: c686ae11000000 MOV byte ptr [ESI + 0x11ae],0x0
    m.w8((s.si+0x000011aeu), 0x00000000u);
  }
  L0049c5b4: { // 0x49c5b4: c686af11000000 MOV byte ptr [ESI + 0x11af],0x0
    m.w8((s.si+0x000011afu), 0x00000000u);
  }
  L0049c5bb: { // 0x49c5bb: c686b011000000 MOV byte ptr [ESI + 0x11b0],0x0
    m.w8((s.si+0x000011b0u), 0x00000000u);
  }
  L0049c5c2: { // 0x49c5c2: 7421 JZ 0x0049c5e5
    if(integer::condition("JZ",flags)) goto L0049c5e5;
  }
  L0049c5c4: { // 0x49c5c4: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049c5ca: { // 0x49c5ca: 8b8130020000 MOV EAX,dword ptr [ECX + 0x230]
    s.ax = m.r32((s.cx+0x00000230u));
  }
  L0049c5d0: { // 0x49c5d0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c5d2: { // 0x49c5d2: 7e11 JLE 0x0049c5e5
    if(integer::condition("JLE",flags)) goto L0049c5e5;
  }
  L0049c5d4: { // 0x49c5d4: c686ad11000001 MOV byte ptr [ESI + 0x11ad],0x1
    m.w8((s.si+0x000011adu), 0x00000001u);
  }
  L0049c5db: { // 0x49c5db: e88063feff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,4834784u); flags=s.arithmetic_flags;
  }
  L0049c5e0: { // 0x49c5e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c5e1: { // 0x49c5e1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c5e2: { // 0x49c5e2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0049c5e5: { // 0x49c5e5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049c5e7: { // 0x49c5e7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c5e9: { // 0x49c5e9: c686ad11000000 MOV byte ptr [ESI + 0x11ad],0x0
    m.w8((s.si+0x000011adu), 0x00000000u);
  }
  L0049c5f0: { // 0x49c5f0: ff5250 CALL dword ptr [EDX + 0x50]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000050u)),4834803u); flags=s.arithmetic_flags;
  }
  L0049c5f3: { // 0x49c5f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c5f4: { // 0x49c5f4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c5f5: { // 0x49c5f5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0019be50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0059be50: { // 0x0059be50: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0059be54: { // 0x0059be54: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0059be56: { // 0x0059be56: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0059be57: { // 0x0059be57: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L0059be5b: { // 0x0059be5b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0059be5c: { // 0x0059be5c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0059be5d: { // 0x0059be5d: 8981344f0000 MOV dword ptr [ECX + 0x4f34],EAX
    m.w32((s.cx+0x00004f34u), s.ax);
  }
  L0059be63: { // 0x0059be63: ff524c CALL dword ptr [EDX + 0x4c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000004cu)),5881446u); flags=s.arithmetic_flags;
  }
  L0059be66: { // 0x0059be66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0059be67: { // 0x0059be67: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0019be70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0059be70: { // 0x0059be70: 8b91344f0000 MOV EDX,dword ptr [ECX + 0x4f34]
    s.dx = m.r32((s.cx+0x00004f34u));
  }
  L0059be76: { // 0x0059be76: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0059be78: { // 0x0059be78: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0059be7a: { // 0x0059be7a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0059be7b: { // 0x0059be7b: ff504c CALL dword ptr [EAX + 0x4c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000004cu)),5881470u); flags=s.arithmetic_flags;
  }
  L0059be7e: { // 0x0059be7e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000f25d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f25d0: { // 0x4f25d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f25d1: { // 0x4f25d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f25d2: { // 0x4f25d2: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f25d4: { // 0x4f25d4: 8db958010000 LEA EDI,[ECX + 0x158]
    s.di = (s.cx+0x00000158u);
  }
  L004f25da: { // 0x4f25da: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L004f25dc: { // 0x4f25dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f25de: { // 0x4f25de: 7519 JNZ 0x004f25f9
    if(integer::condition("JNZ",flags)) goto L004f25f9;
  }
  L004f25e0: { // 0x4f25e0: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  L004f25e2: { // 0x4f25e2: e870b32700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5187047u); flags=s.arithmetic_flags;
  }
  L004f25e7: { // 0x4f25e7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f25ea: { // 0x4f25ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f25ec: { // 0x4f25ec: 7409 JZ 0x004f25f7
    if(integer::condition("JZ",flags)) goto L004f25f7;
  }
  L004f25ee: { // 0x4f25ee: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004f25f0: { // 0x4f25f0: e8db702200 CALL 0x007196d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007196d0u,5187061u); flags=s.arithmetic_flags;
  }
  L004f25f5: { // 0x4f25f5: eb02 JMP 0x004f25f9
    goto L004f25f9;
  }
  L004f25f7: { // 0x4f25f7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f25f9: { // 0x4f25f9: 8b4838 MOV ECX,dword ptr [EAX + 0x38]
    s.cx = m.r32((s.ax+0x00000038u));
  }
  L004f25fc: { // 0x4f25fc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004f25fe: { // 0x4f25fe: 740f JZ 0x004f260f
    if(integer::condition("JZ",flags)) goto L004f260f;
  }
  L004f2600: { // 0x4f2600: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004f2601: { // 0x4f2601: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L004f2604: { // 0x4f2604: 83fe0c CMP ESI,0xc
    (void)integer::sub(s.si,0x0000000cu,32,flags);
  }
  L004f2607: { // 0x4f2607: 7cd1 JL 0x004f25da
    if(integer::condition("JL",flags)) goto L004f25da;
  }
  L004f2609: { // 0x4f2609: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f260a: { // 0x4f260a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004f260d: { // 0x4f260d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f260e: { // 0x4f260e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f260f: { // 0x4f260f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f2611: { // 0x4f2611: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f2612: { // 0x4f2612: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f2613: { // 0x4f2613: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0019c040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0059c040: { // 0x59c040: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0059c044: { // 0x59c044: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0059c047: { // 0x59c047: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0059c048: { // 0x59c048: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0059c049: { // 0x59c049: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0059c04a: { // 0x59c04a: 8d3440 LEA ESI,[EAX + EAX*0x2]
    s.si = (s.ax+(s.ax * 0x00000002u));
  }
  L0059c04d: { // 0x59c04d: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0059c04f: { // 0x59c04f: 833cf5dcd57c00ff CMP dword ptr [ESI*0x8 + 0x7cd5dc],-0x1
    (void)integer::sub(m.r32(((s.si * 0x00000008u)+0x007cd5dcu)),0xffffffffu,32,flags);
  }
  L0059c057: { // 0x59c057: 7508 JNZ 0x0059c061
    if(integer::condition("JNZ",flags)) goto L0059c061;
  }
  L0059c059: { // 0x59c059: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0059c05b: { // 0x59c05b: 885c2424 MOV byte ptr [ESP + 0x24],BL
    m.w8((f.sp+0x00000024u), (s.bx & 0xffu));
  }
  L0059c05f: { // 0x59c05f: eb04 JMP 0x0059c065
    goto L0059c065;
  }
  L0059c061: { // 0x59c061: 8a5c2424 MOV BL,byte ptr [ESP + 0x24]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000024u)));
  }
  L0059c065: { // 0x59c065: 8a0dbd8ba500 MOV CL,byte ptr [0x00a58bbd]
    s.cx = with_al(s.cx, m.r8((0x00a58bbdu)));
  }
  L0059c06b: { // 0x59c06b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0059c06d: { // 0x59c06d: 7425 JZ 0x0059c094
    if(integer::condition("JZ",flags)) goto L0059c094;
  }
  L0059c06f: { // 0x59c06f: 8b0d7c8ba500 MOV ECX,dword ptr [0x00a58b7c]
    s.cx = m.r32((0x00a58b7cu));
  }
  L0059c075: { // 0x59c075: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0059c077: { // 0x59c077: 7410 JZ 0x0059c089
    if(integer::condition("JZ",flags)) goto L0059c089;
  }
  L0059c079: { // 0x59c079: 3b85304f0000 CMP EAX,dword ptr [EBP + 0x4f30]
    (void)integer::sub(s.ax,m.r32((s.bp+0x00004f30u)),32,flags);
  }
  L0059c07f: { // 0x59c07f: 7513 JNZ 0x0059c094
    if(integer::condition("JNZ",flags)) goto L0059c094;
  }
  L0059c081: { // 0x59c081: 3a9d2c4f0000 CMP BL,byte ptr [EBP + 0x4f2c]
    (void)integer::sub((s.bx & 0xffu),m.r8((s.bp+0x00004f2cu)),8,flags);
  }
  L0059c087: { // 0x59c087: 750b JNZ 0x0059c094
    if(integer::condition("JNZ",flags)) goto L0059c094;
  }
  L0059c089: { // 0x59c089: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0059c08a: { // 0x59c08a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0059c08b: { // 0x59c08b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0059c08d: { // 0x59c08d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0059c08e: { // 0x59c08e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0059c091: { // 0x59c091: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0059c094: { // 0x59c094: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0059c095: { // 0x59c095: c605bd8ba50001 MOV byte ptr [0x00a58bbd],0x1
    m.w8((0x00a58bbdu), 0x00000001u);
  }
  L0059c09c: { // 0x59c09c: 8b3cf5d8d57c00 MOV EDI,dword ptr [ESI*0x8 + 0x7cd5d8]
    s.di = m.r32(((s.si * 0x00000008u)+0x007cd5d8u));
  }
  L0059c0a3: { // 0x59c0a3: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0059c0a7: { // 0x59c0a7: e8243a0f00 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,5882028u); flags=s.arithmetic_flags;
  }
  L0059c0ac: { // 0x59c0ac: a3888ba500 MOV [0x00a58b88],EAX
    m.w32((0x00a58b88u), s.ax);
  }
  L0059c0b1: { // 0x59c0b1: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0059c0b5: { // 0x59c0b5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0059c0b7: { // 0x59c0b7: a38c8ba500 MOV [0x00a58b8c],EAX
    m.w32((0x00a58b8cu), s.ax);
  }
  L0059c0bc: { // 0x59c0bc: 893d908ba500 MOV dword ptr [0x00a58b90],EDI
    m.w32((0x00a58b90u), s.di);
  }
  L0059c0c2: { // 0x59c0c2: 898d384f0000 MOV dword ptr [EBP + 0x4f38],ECX
    m.w32((s.bp+0x00004f38u), s.cx);
  }
  L0059c0c8: { // 0x59c0c8: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0059c0ca: { // 0x59c0ca: 7412 JZ 0x0059c0de
    if(integer::condition("JZ",flags)) goto L0059c0de;
  }
  L0059c0cc: { // 0x59c0cc: 8b04f5dcd57c00 MOV EAX,dword ptr [ESI*0x8 + 0x7cd5dc]
    s.ax = m.r32(((s.si * 0x00000008u)+0x007cd5dcu));
  }
  L0059c0d3: { // 0x59c0d3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0059c0d6: { // 0x59c0d6: 7406 JZ 0x0059c0de
    if(integer::condition("JZ",flags)) goto L0059c0de;
  }
  L0059c0d8: { // 0x59c0d8: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0059c0dc: { // 0x59c0dc: eb0b JMP 0x0059c0e9
    goto L0059c0e9;
  }
  L0059c0de: { // 0x59c0de: 8b14f5d0d57c00 MOV EDX,dword ptr [ESI*0x8 + 0x7cd5d0]
    s.dx = m.r32(((s.si * 0x00000008u)+0x007cd5d0u));
  }
  L0059c0e5: { // 0x59c0e5: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0059c0e9: { // 0x59c0e9: 8b1cf5e0d57c00 MOV EBX,dword ptr [ESI*0x8 + 0x7cd5e0]
    s.bx = m.r32(((s.si * 0x00000008u)+0x007cd5e0u));
  }
  L0059c0f0: { // 0x59c0f0: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0059c0f2: { // 0x59c0f2: 81fb39300000 CMP EBX,0x3039
    (void)integer::sub(s.bx,0x00003039u,32,flags);
  }
  L0059c0f8: { // 0x59c0f8: 7510 JNZ 0x0059c10a
    if(integer::condition("JNZ",flags)) goto L0059c10a;
  }
  L0059c0fa: { // 0x59c0fa: a17c8ba500 MOV EAX,[0x00a58b7c]
    s.ax = m.r32((0x00a58b7cu));
  }
  L0059c0ff: { // 0x59c0ff: 0fbf4002 MOVSX EAX,word ptr [EAX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L0059c103: { // 0x59c103: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0059c104: { // 0x59c104: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0059c106: { // 0x59c106: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0059c108: { // 0x59c108: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0059c10a: { // 0x59c10a: 81fb31d40000 CMP EBX,0xd431
    (void)integer::sub(s.bx,0x0000d431u,32,flags);
  }
  L0059c110: { // 0x59c110: 8b1d7c8ba500 MOV EBX,dword ptr [0x00a58b7c]
    s.bx = m.r32((0x00a58b7cu));
  }
  L0059c116: { // 0x59c116: 7504 JNZ 0x0059c11c
    if(integer::condition("JNZ",flags)) goto L0059c11c;
  }
  L0059c118: { // 0x59c118: 0fbf7b02 MOVSX EDI,word ptr [EBX + 0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0059c11c: { // 0x59c11c: 8b34f5e4d57c00 MOV ESI,dword ptr [ESI*0x8 + 0x7cd5e4]
    s.si = m.r32(((s.si * 0x00000008u)+0x007cd5e4u));
  }
  L0059c123: { // 0x59c123: 81fe39300000 CMP ESI,0x3039
    (void)integer::sub(s.si,0x00003039u,32,flags);
  }
  L0059c129: { // 0x59c129: 750b JNZ 0x0059c136
    if(integer::condition("JNZ",flags)) goto L0059c136;
  }
  L0059c12b: { // 0x59c12b: 0fbf4304 MOVSX EAX,word ptr [EBX + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000004u)),16));
  }
  L0059c12f: { // 0x59c12f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0059c130: { // 0x59c130: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0059c132: { // 0x59c132: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0059c134: { // 0x59c134: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0059c136: { // 0x59c136: 81fe31d40000 CMP ESI,0xd431
    (void)integer::sub(s.si,0x0000d431u,32,flags);
  }
  L0059c13c: { // 0x59c13c: 7504 JNZ 0x0059c142
    if(integer::condition("JNZ",flags)) goto L0059c142;
  }
  L0059c13e: { // 0x59c13e: 0fbf4b04 MOVSX ECX,word ptr [EBX + 0x4]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000004u)),16));
  }
  L0059c142: { // 0x59c142: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0059c146: { // 0x59c146: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0059c14a: { // 0x59c14a: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L0059c150: { // 0x59c150: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0059c151: { // 0x59c151: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0059c155: { // 0x59c155: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0059c159: { // 0x59c159: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0059c15b: { // 0x59c15b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0059c15c: { // 0x59c15c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0059c15d: { // 0x59c15d: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),5882208u); flags=s.arithmetic_flags;
  }
  L0059c160: { // 0x59c160: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0059c164: { // 0x59c164: 8a542428 MOV DL,byte ptr [ESP + 0x28]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000028u)));
  }
  L0059c168: { // 0x59c168: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0059c169: { // 0x59c169: 898d304f0000 MOV dword ptr [EBP + 0x4f30],ECX
    m.w32((s.bp+0x00004f30u), s.cx);
  }
  L0059c16f: { // 0x59c16f: 88952c4f0000 MOV byte ptr [EBP + 0x4f2c],DL
    m.w8((s.bp+0x00004f2cu), (s.dx & 0xffu));
  }
  L0059c175: { // 0x59c175: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0059c176: { // 0x59c176: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0059c177: { // 0x59c177: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0059c179: { // 0x59c179: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0059c17a: { // 0x59c17a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0059c17d: { // 0x59c17d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0009c600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049c600: { // 0x49c600: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0049c604: { // 0x49c604: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049c605: { // 0x49c605: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049c606: { // 0x49c606: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049c608: { // 0x49c608: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0049c60b: { // 0x49c60b: 8a8eaf110000 MOV CL,byte ptr [ESI + 0x11af]
    s.cx = with_al(s.cx, m.r8((s.si+0x000011afu)));
  }
  L0049c611: { // 0x49c611: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  L0049c613: { // 0x49c613: 7411 JZ 0x0049c626
    if(integer::condition("JZ",flags)) goto L0049c626;
  }
  L0049c615: { // 0x49c615: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c617: { // 0x49c617: 7409 JZ 0x0049c622
    if(integer::condition("JZ",flags)) goto L0049c622;
  }
  L0049c619: { // 0x49c619: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0049c61c: { // 0x49c61c: 750d JNZ 0x0049c62b
    if(integer::condition("JNZ",flags)) goto L0049c62b;
  }
  L0049c61e: { // 0x49c61e: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0049c620: { // 0x49c620: eb09 JMP 0x0049c62b
    goto L0049c62b;
  }
  L0049c622: { // 0x49c622: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0049c624: { // 0x49c624: eb05 JMP 0x0049c62b
    goto L0049c62b;
  }
  L0049c626: { // 0x49c626: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c628: { // 0x49c628: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0049c62b: { // 0x49c62b: 3ad9 CMP BL,CL
    (void)integer::sub((s.bx & 0xffu),(s.cx & 0xffu),8,flags);
  }
  L0049c62d: { // 0x49c62d: 0f84da000000 JZ 0x0049c70d
    if(integer::condition("JZ",flags)) goto L0049c70d;
  }
  L0049c633: { // 0x49c633: 8b86a4110000 MOV EAX,dword ptr [ESI + 0x11a4]
    s.ax = m.r32((s.si+0x000011a4u));
  }
  L0049c639: { // 0x49c639: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c63b: { // 0x49c63b: 0f85cc000000 JNZ 0x0049c70d
    if(integer::condition("JNZ",flags)) goto L0049c70d;
  }
  L0049c641: { // 0x49c641: c686ac11000000 MOV byte ptr [ESI + 0x11ac],0x0
    m.w8((s.si+0x000011acu), 0x00000000u);
  }
  L0049c648: { // 0x49c648: c686ad11000000 MOV byte ptr [ESI + 0x11ad],0x0
    m.w8((s.si+0x000011adu), 0x00000000u);
  }
  L0049c64f: { // 0x49c64f: c686ae11000000 MOV byte ptr [ESI + 0x11ae],0x0
    m.w8((s.si+0x000011aeu), 0x00000000u);
  }
  L0049c656: { // 0x49c656: c686b011000000 MOV byte ptr [ESI + 0x11b0],0x0
    m.w8((s.si+0x000011b0u), 0x00000000u);
  }
  L0049c65d: { // 0x49c65d: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049c663: { // 0x49c663: e8685f0500 CALL 0x004f25d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f25d0u,4834920u); flags=s.arithmetic_flags;
  }
  L0049c668: { // 0x49c668: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c66a: { // 0x49c66a: 745a JZ 0x0049c6c6
    if(integer::condition("JZ",flags)) goto L0049c6c6;
  }
  L0049c66c: { // 0x49c66c: 8a4c2410 MOV CL,byte ptr [ESP + 0x10]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000010u)));
  }
  L0049c670: { // 0x49c670: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0049c673: { // 0x49c673: 7530 JNZ 0x0049c6a5
    if(integer::condition("JNZ",flags)) goto L0049c6a5;
  }
  L0049c675: { // 0x49c675: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049c677: { // 0x49c677: 740f JZ 0x0049c688
    if(integer::condition("JZ",flags)) goto L0049c688;
  }
  L0049c679: { // 0x49c679: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L0049c67f: { // 0x49c67f: 83ba54010000ff CMP dword ptr [EDX + 0x154],-0x1
    (void)integer::sub(m.r32((s.dx+0x00000154u)),0xffffffffu,32,flags);
  }
  L0049c686: { // 0x49c686: 751d JNZ 0x0049c6a5
    if(integer::condition("JNZ",flags)) goto L0049c6a5;
  }
  L0049c688: { // 0x49c688: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049c68a: { // 0x49c68a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c68c: { // 0x49c68c: c686af11000000 MOV byte ptr [ESI + 0x11af],0x0
    m.w8((s.si+0x000011afu), 0x00000000u);
  }
  L0049c693: { // 0x49c693: ff5050 CALL dword ptr [EAX + 0x50]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000050u)),4834966u); flags=s.arithmetic_flags;
  }
  L0049c696: { // 0x49c696: c786b811000000000000 MOV dword ptr [ESI + 0x11b8],0x0
    m.w32((s.si+0x000011b8u), 0x00000000u);
  }
  L0049c6a0: { // 0x49c6a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c6a1: { // 0x49c6a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c6a2: { // 0x49c6a2: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0049c6a5: { // 0x49c6a5: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049c6a7: { // 0x49c6a7: c686af11000001 MOV byte ptr [ESI + 0x11af],0x1
    m.w8((s.si+0x000011afu), 0x00000001u);
  }
  L0049c6ae: { // 0x49c6ae: 750c JNZ 0x0049c6bc
    if(integer::condition("JNZ",flags)) goto L0049c6bc;
  }
  L0049c6b0: { // 0x49c6b0: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049c6b6: { // 0x49c6b6: 898154010000 MOV dword ptr [ECX + 0x154],EAX
    m.w32((s.cx+0x00000154u), s.ax);
  }
  L0049c6bc: { // 0x49c6bc: e89f62feff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,4835009u); flags=s.arithmetic_flags;
  }
  L0049c6c1: { // 0x49c6c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c6c2: { // 0x49c6c2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c6c3: { // 0x49c6c3: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0049c6c6: { // 0x49c6c6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049c6c8: { // 0x49c6c8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c6ca: { // 0x49c6ca: c686af11000000 MOV byte ptr [ESI + 0x11af],0x0
    m.w8((s.si+0x000011afu), 0x00000000u);
  }
  L0049c6d1: { // 0x49c6d1: ff5250 CALL dword ptr [EDX + 0x50]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000050u)),4835028u); flags=s.arithmetic_flags;
  }
  L0049c6d4: { // 0x49c6d4: 8b86b8110000 MOV EAX,dword ptr [ESI + 0x11b8]
    s.ax = m.r32((s.si+0x000011b8u));
  }
  L0049c6da: { // 0x49c6da: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c6dc: { // 0x49c6dc: 742f JZ 0x0049c70d
    if(integer::condition("JZ",flags)) goto L0049c70d;
  }
  L0049c6de: { // 0x49c6de: 8d8ebc110000 LEA ECX,[ESI + 0x11bc]
    s.cx = (s.si+0x000011bcu);
  }
  L0049c6e4: { // 0x49c6e4: 8b96bc110000 MOV EDX,dword ptr [ESI + 0x11bc]
    s.dx = m.r32((s.si+0x000011bcu));
  }
  L0049c6ea: { // 0x49c6ea: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0049c6ec: { // 0x49c6ec: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0049c6ef: { // 0x49c6ef: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0049c6f2: { // 0x49c6f2: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L0049c6f5: { // 0x49c6f5: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0049c6f8: { // 0x49c6f8: c786b811000000000000 MOV dword ptr [ESI + 0x11b8],0x0
    m.w32((s.si+0x000011b8u), 0x00000000u);
  }
  L0049c702: { // 0x49c702: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L0049c708: { // 0x49c708: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0049c70a: { // 0x49c70a: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),4835085u); flags=s.arithmetic_flags;
  }
  L0049c70d: { // 0x49c70d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c70e: { // 0x49c70e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c70f: { // 0x49c70f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0009c720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049c720: { // 0x49c720: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049c721: { // 0x49c721: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049c722: { // 0x49c722: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049c724: { // 0x49c724: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0049c728: { // 0x49c728: 8a86ae110000 MOV AL,byte ptr [ESI + 0x11ae]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011aeu)));
  }
  L0049c72e: { // 0x49c72e: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L0049c731: { // 0x49c731: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0049c733: { // 0x49c733: 7411 JZ 0x0049c746
    if(integer::condition("JZ",flags)) goto L0049c746;
  }
  L0049c735: { // 0x49c735: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049c737: { // 0x49c737: 7409 JZ 0x0049c742
    if(integer::condition("JZ",flags)) goto L0049c742;
  }
  L0049c739: { // 0x49c739: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0049c73c: { // 0x49c73c: 750d JNZ 0x0049c74b
    if(integer::condition("JNZ",flags)) goto L0049c74b;
  }
  L0049c73e: { // 0x49c73e: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  L0049c740: { // 0x49c740: eb09 JMP 0x0049c74b
    goto L0049c74b;
  }
  L0049c742: { // 0x49c742: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0049c744: { // 0x49c744: eb05 JMP 0x0049c74b
    goto L0049c74b;
  }
  L0049c746: { // 0x49c746: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c748: { // 0x49c748: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0049c74b: { // 0x49c74b: 3ad8 CMP BL,AL
    (void)integer::sub((s.bx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0049c74d: { // 0x49c74d: 7464 JZ 0x0049c7b3
    if(integer::condition("JZ",flags)) goto L0049c7b3;
  }
  L0049c74f: { // 0x49c74f: 8b86a4110000 MOV EAX,dword ptr [ESI + 0x11a4]
    s.ax = m.r32((s.si+0x000011a4u));
  }
  L0049c755: { // 0x49c755: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c757: { // 0x49c757: 755a JNZ 0x0049c7b3
    if(integer::condition("JNZ",flags)) goto L0049c7b3;
  }
  L0049c759: { // 0x49c759: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049c75b: { // 0x49c75b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c75d: { // 0x49c75d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c75f: { // 0x49c75f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c761: { // 0x49c761: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4835172u); flags=s.arithmetic_flags;
  }
  L0049c764: { // 0x49c764: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c766: { // 0x49c766: c686ac11000000 MOV byte ptr [ESI + 0x11ac],0x0
    m.w8((s.si+0x000011acu), 0x00000000u);
  }
  L0049c76d: { // 0x49c76d: c686ad11000000 MOV byte ptr [ESI + 0x11ad],0x0
    m.w8((s.si+0x000011adu), 0x00000000u);
  }
  L0049c774: { // 0x49c774: c686af11000000 MOV byte ptr [ESI + 0x11af],0x0
    m.w8((s.si+0x000011afu), 0x00000000u);
  }
  L0049c77b: { // 0x49c77b: c686b011000000 MOV byte ptr [ESI + 0x11b0],0x0
    m.w8((s.si+0x000011b0u), 0x00000000u);
  }
  L0049c782: { // 0x49c782: 7421 JZ 0x0049c7a5
    if(integer::condition("JZ",flags)) goto L0049c7a5;
  }
  L0049c784: { // 0x49c784: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049c78a: { // 0x49c78a: 8b8130020000 MOV EAX,dword ptr [ECX + 0x230]
    s.ax = m.r32((s.cx+0x00000230u));
  }
  L0049c790: { // 0x49c790: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c792: { // 0x49c792: 7e11 JLE 0x0049c7a5
    if(integer::condition("JLE",flags)) goto L0049c7a5;
  }
  L0049c794: { // 0x49c794: c686ae11000001 MOV byte ptr [ESI + 0x11ae],0x1
    m.w8((s.si+0x000011aeu), 0x00000001u);
  }
  L0049c79b: { // 0x49c79b: e8c061feff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,4835232u); flags=s.arithmetic_flags;
  }
  L0049c7a0: { // 0x49c7a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c7a1: { // 0x49c7a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c7a2: { // 0x49c7a2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0049c7a5: { // 0x49c7a5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049c7a7: { // 0x49c7a7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c7a9: { // 0x49c7a9: c686ae11000000 MOV byte ptr [ESI + 0x11ae],0x0
    m.w8((s.si+0x000011aeu), 0x00000000u);
  }
  L0049c7b0: { // 0x49c7b0: ff5250 CALL dword ptr [EDX + 0x50]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000050u)),4835251u); flags=s.arithmetic_flags;
  }
  L0049c7b3: { // 0x49c7b3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c7b4: { // 0x49c7b4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c7b5: { // 0x49c7b5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0009c7c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049c7c0: { // 0x49c7c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049c7c1: { // 0x49c7c1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049c7c2: { // 0x49c7c2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049c7c4: { // 0x49c7c4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0049c7c8: { // 0x49c7c8: 8a86ac110000 MOV AL,byte ptr [ESI + 0x11ac]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011acu)));
  }
  L0049c7ce: { // 0x49c7ce: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L0049c7d1: { // 0x49c7d1: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0049c7d3: { // 0x49c7d3: 7411 JZ 0x0049c7e6
    if(integer::condition("JZ",flags)) goto L0049c7e6;
  }
  L0049c7d5: { // 0x49c7d5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049c7d7: { // 0x49c7d7: 7409 JZ 0x0049c7e2
    if(integer::condition("JZ",flags)) goto L0049c7e2;
  }
  L0049c7d9: { // 0x49c7d9: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0049c7dc: { // 0x49c7dc: 750d JNZ 0x0049c7eb
    if(integer::condition("JNZ",flags)) goto L0049c7eb;
  }
  L0049c7de: { // 0x49c7de: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  L0049c7e0: { // 0x49c7e0: eb09 JMP 0x0049c7eb
    goto L0049c7eb;
  }
  L0049c7e2: { // 0x49c7e2: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0049c7e4: { // 0x49c7e4: eb05 JMP 0x0049c7eb
    goto L0049c7eb;
  }
  L0049c7e6: { // 0x49c7e6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c7e8: { // 0x49c7e8: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0049c7eb: { // 0x49c7eb: 3ad8 CMP BL,AL
    (void)integer::sub((s.bx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0049c7ed: { // 0x49c7ed: 7464 JZ 0x0049c853
    if(integer::condition("JZ",flags)) goto L0049c853;
  }
  L0049c7ef: { // 0x49c7ef: 8b86a4110000 MOV EAX,dword ptr [ESI + 0x11a4]
    s.ax = m.r32((s.si+0x000011a4u));
  }
  L0049c7f5: { // 0x49c7f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c7f7: { // 0x49c7f7: 755a JNZ 0x0049c853
    if(integer::condition("JNZ",flags)) goto L0049c853;
  }
  L0049c7f9: { // 0x49c7f9: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049c7fb: { // 0x49c7fb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c7fd: { // 0x49c7fd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c7ff: { // 0x49c7ff: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c801: { // 0x49c801: c686ad11000000 MOV byte ptr [ESI + 0x11ad],0x0
    m.w8((s.si+0x000011adu), 0x00000000u);
  }
  L0049c808: { // 0x49c808: c686ae11000000 MOV byte ptr [ESI + 0x11ae],0x0
    m.w8((s.si+0x000011aeu), 0x00000000u);
  }
  L0049c80f: { // 0x49c80f: c686af11000000 MOV byte ptr [ESI + 0x11af],0x0
    m.w8((s.si+0x000011afu), 0x00000000u);
  }
  L0049c816: { // 0x49c816: c686b011000000 MOV byte ptr [ESI + 0x11b0],0x0
    m.w8((s.si+0x000011b0u), 0x00000000u);
  }
  L0049c81d: { // 0x49c81d: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4835360u); flags=s.arithmetic_flags;
  }
  L0049c820: { // 0x49c820: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c822: { // 0x49c822: 7421 JZ 0x0049c845
    if(integer::condition("JZ",flags)) goto L0049c845;
  }
  L0049c824: { // 0x49c824: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049c82a: { // 0x49c82a: 8b8130020000 MOV EAX,dword ptr [ECX + 0x230]
    s.ax = m.r32((s.cx+0x00000230u));
  }
  L0049c830: { // 0x49c830: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c832: { // 0x49c832: 7e11 JLE 0x0049c845
    if(integer::condition("JLE",flags)) goto L0049c845;
  }
  L0049c834: { // 0x49c834: c686ac11000001 MOV byte ptr [ESI + 0x11ac],0x1
    m.w8((s.si+0x000011acu), 0x00000001u);
  }
  L0049c83b: { // 0x49c83b: e82061feff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,4835392u); flags=s.arithmetic_flags;
  }
  L0049c840: { // 0x49c840: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c841: { // 0x49c841: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c842: { // 0x49c842: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0049c845: { // 0x49c845: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049c847: { // 0x49c847: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c849: { // 0x49c849: c686ac11000000 MOV byte ptr [ESI + 0x11ac],0x0
    m.w8((s.si+0x000011acu), 0x00000000u);
  }
  L0049c850: { // 0x49c850: ff5250 CALL dword ptr [EDX + 0x50]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000050u)),4835411u); flags=s.arithmetic_flags;
  }
  L0049c853: { // 0x49c853: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c854: { // 0x49c854: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c855: { // 0x49c855: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0009c860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049c860: { // 0x49c860: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0049c864: { // 0x49c864: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049c865: { // 0x49c865: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049c866: { // 0x49c866: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049c868: { // 0x49c868: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0049c86b: { // 0x49c86b: 8a9eac110000 MOV BL,byte ptr [ESI + 0x11ac]
    s.bx = with_al(s.bx, m.r8((s.si+0x000011acu)));
  }
  L0049c871: { // 0x49c871: 7411 JZ 0x0049c884
    if(integer::condition("JZ",flags)) goto L0049c884;
  }
  L0049c873: { // 0x49c873: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c875: { // 0x49c875: 7409 JZ 0x0049c880
    if(integer::condition("JZ",flags)) goto L0049c880;
  }
  L0049c877: { // 0x49c877: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0049c87a: { // 0x49c87a: 750d JNZ 0x0049c889
    if(integer::condition("JNZ",flags)) goto L0049c889;
  }
  L0049c87c: { // 0x49c87c: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0049c87e: { // 0x49c87e: eb09 JMP 0x0049c889
    goto L0049c889;
  }
  L0049c880: { // 0x49c880: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0049c882: { // 0x49c882: eb05 JMP 0x0049c889
    goto L0049c889;
  }
  L0049c884: { // 0x49c884: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c886: { // 0x49c886: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0049c889: { // 0x49c889: 3a9eb0110000 CMP BL,byte ptr [ESI + 0x11b0]
    (void)integer::sub((s.bx & 0xffu),m.r8((s.si+0x000011b0u)),8,flags);
  }
  L0049c88f: { // 0x49c88f: 7471 JZ 0x0049c902
    if(integer::condition("JZ",flags)) goto L0049c902;
  }
  L0049c891: { // 0x49c891: 8b86a4110000 MOV EAX,dword ptr [ESI + 0x11a4]
    s.ax = m.r32((s.si+0x000011a4u));
  }
  L0049c897: { // 0x49c897: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049c899: { // 0x49c899: 7567 JNZ 0x0049c902
    if(integer::condition("JNZ",flags)) goto L0049c902;
  }
  L0049c89b: { // 0x49c89b: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c89d: { // 0x49c89d: 7419 JZ 0x0049c8b8
    if(integer::condition("JZ",flags)) goto L0049c8b8;
  }
  L0049c89f: { // 0x49c89f: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0049c8a4: { // 0x49c8a4: 8b4830 MOV ECX,dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L0049c8a7: { // 0x49c8a7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049c8a8: { // 0x49c8a8: b9186c8300 MOV ECX,0x836c18
    s.cx = 0x00836c18u;
  }
  L0049c8ad: { // 0x49c8ad: e8fe1df9ff CALL 0x0042e6b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042e6b0u,4835506u); flags=s.arithmetic_flags;
  }
  L0049c8b2: { // 0x49c8b2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049c8b4: { // 0x49c8b4: 7502 JNZ 0x0049c8b8
    if(integer::condition("JNZ",flags)) goto L0049c8b8;
  }
  L0049c8b6: { // 0x49c8b6: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0049c8b8: { // 0x49c8b8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049c8ba: { // 0x49c8ba: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c8bc: { // 0x49c8bc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049c8be: { // 0x49c8be: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c8c0: { // 0x49c8c0: c686ad11000000 MOV byte ptr [ESI + 0x11ad],0x0
    m.w8((s.si+0x000011adu), 0x00000000u);
  }
  L0049c8c7: { // 0x49c8c7: c686ae11000000 MOV byte ptr [ESI + 0x11ae],0x0
    m.w8((s.si+0x000011aeu), 0x00000000u);
  }
  L0049c8ce: { // 0x49c8ce: c686af11000000 MOV byte ptr [ESI + 0x11af],0x0
    m.w8((s.si+0x000011afu), 0x00000000u);
  }
  L0049c8d5: { // 0x49c8d5: c686ac11000000 MOV byte ptr [ESI + 0x11ac],0x0
    m.w8((s.si+0x000011acu), 0x00000000u);
  }
  L0049c8dc: { // 0x49c8dc: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4835551u); flags=s.arithmetic_flags;
  }
  L0049c8df: { // 0x49c8df: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049c8e1: { // 0x49c8e1: 7411 JZ 0x0049c8f4
    if(integer::condition("JZ",flags)) goto L0049c8f4;
  }
  L0049c8e3: { // 0x49c8e3: c686b011000001 MOV byte ptr [ESI + 0x11b0],0x1
    m.w8((s.si+0x000011b0u), 0x00000001u);
  }
  L0049c8ea: { // 0x49c8ea: e87160feff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,4835567u); flags=s.arithmetic_flags;
  }
  L0049c8ef: { // 0x49c8ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c8f0: { // 0x49c8f0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c8f1: { // 0x49c8f1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0049c8f4: { // 0x49c8f4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049c8f6: { // 0x49c8f6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049c8f8: { // 0x49c8f8: c686b011000000 MOV byte ptr [ESI + 0x11b0],0x0
    m.w8((s.si+0x000011b0u), 0x00000000u);
  }
  L0049c8ff: { // 0x49c8ff: ff5050 CALL dword ptr [EAX + 0x50]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000050u)),4835586u); flags=s.arithmetic_flags;
  }
  L0049c902: { // 0x49c902: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049c903: { // 0x49c903: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049c904: { // 0x49c904: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cb500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cb500: { // 0x5cb500: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cb501: { // 0x5cb501: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L005cb506: { // 0x5cb506: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cb507: { // 0x5cb507: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb509: { // 0x5cb509: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cb50a: { // 0x5cb50a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cb50c: { // 0x5cb50c: 7520 JNZ 0x005cb52e
    if(integer::condition("JNZ",flags)) goto L005cb52e;
  }
  L005cb50e: { // 0x5cb50e: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cb511: { // 0x5cb511: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb513: { // 0x5cb513: 7513 JNZ 0x005cb528
    if(integer::condition("JNZ",flags)) goto L005cb528;
  }
  L005cb515: { // 0x5cb515: 8a4677 MOV AL,byte ptr [ESI + 0x77]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000077u)));
  }
  L005cb518: { // 0x5cb518: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb51a: { // 0x5cb51a: 750c JNZ 0x005cb528
    if(integer::condition("JNZ",flags)) goto L005cb528;
  }
  L005cb51c: { // 0x5cb51c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cb51e: { // 0x5cb51e: ff9030010000 CALL dword ptr [EAX + 0x130]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000130u)),6075684u); flags=s.arithmetic_flags;
  }
  L005cb524: { // 0x5cb524: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb526: { // 0x5cb526: 7506 JNZ 0x005cb52e
    if(integer::condition("JNZ",flags)) goto L005cb52e;
  }
  L005cb528: { // 0x5cb528: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb529: { // 0x5cb529: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cb52b: { // 0x5cb52b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb52c: { // 0x5cb52c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb52d: { // 0x5cb52d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cb52e: { // 0x5cb52e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb530: { // 0x5cb530: e8eb26e4ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,6075701u); flags=s.arithmetic_flags;
  }
  L005cb535: { // 0x5cb535: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005cb537: { // 0x5cb537: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L005cb53c: { // 0x5cb53c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb53e: { // 0x5cb53e: 7522 JNZ 0x005cb562
    if(integer::condition("JNZ",flags)) goto L005cb562;
  }
  L005cb540: { // 0x5cb540: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cb542: { // 0x5cb542: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb544: { // 0x5cb544: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),6075722u); flags=s.arithmetic_flags;
  }
  L005cb54a: { // 0x5cb54a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb54c: { // 0x5cb54c: 7414 JZ 0x005cb562
    if(integer::condition("JZ",flags)) goto L005cb562;
  }
  L005cb54e: { // 0x5cb54e: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005cb550: { // 0x5cb550: 7410 JZ 0x005cb562
    if(integer::condition("JZ",flags)) goto L005cb562;
  }
  L005cb552: { // 0x5cb552: 8a872c030000 MOV AL,byte ptr [EDI + 0x32c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000032cu)));
  }
  L005cb558: { // 0x5cb558: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb55a: { // 0x5cb55a: 7406 JZ 0x005cb562
    if(integer::condition("JZ",flags)) goto L005cb562;
  }
  L005cb55c: { // 0x5cb55c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb55d: { // 0x5cb55d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cb55f: { // 0x5cb55f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb560: { // 0x5cb560: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb561: { // 0x5cb561: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cb562: { // 0x5cb562: a1c4b98100 MOV EAX,[0x0081b9c4]
    s.ax = m.r32((0x0081b9c4u));
  }
  L005cb567: { // 0x5cb567: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb569: { // 0x5cb569: 7406 JZ 0x005cb571
    if(integer::condition("JZ",flags)) goto L005cb571;
  }
  L005cb56b: { // 0x5cb56b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb56c: { // 0x5cb56c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cb56e: { // 0x5cb56e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb56f: { // 0x5cb56f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb570: { // 0x5cb570: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cb571: { // 0x5cb571: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb576: { // 0x5cb576: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb578: { // 0x5cb578: 7e46 JLE 0x005cb5c0
    if(integer::condition("JLE",flags)) goto L005cb5c0;
  }
  L005cb57a: { // 0x5cb57a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cb57c: { // 0x5cb57c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cb57d: { // 0x5cb57d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb57f: { // 0x5cb57f: ff503c CALL dword ptr [EAX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000003cu)),6075778u); flags=s.arithmetic_flags;
  }
  L005cb582: { // 0x5cb582: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L005cb588: { // 0x5cb588: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005cb58a: { // 0x5cb58a: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L005cb58c: { // 0x5cb58c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005cb58e: { // 0x5cb58e: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),6075793u); flags=s.arithmetic_flags;
  }
  L005cb591: { // 0x5cb591: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005cb593: { // 0x5cb593: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cb595: { // 0x5cb595: e81692f2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6075802u); flags=s.arithmetic_flags;
  }
  L005cb59a: { // 0x5cb59a: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L005cb59c: { // 0x5cb59c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005cb59e: { // 0x5cb59e: 8854240f MOV byte ptr [ESP + 0xf],DL
    m.w8((f.sp+0x0000000fu), (s.dx & 0xffu));
  }
  L005cb5a2: { // 0x5cb5a2: e80992f2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6075815u); flags=s.arithmetic_flags;
  }
  L005cb5a7: { // 0x5cb5a7: 8a4c240f MOV CL,byte ptr [ESP + 0xf]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000000fu)));
  }
  L005cb5ab: { // 0x5cb5ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cb5ac: { // 0x5cb5ac: 3ac8 CMP CL,AL
    (void)integer::sub((s.cx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L005cb5ae: { // 0x5cb5ae: 750b JNZ 0x005cb5bb
    if(integer::condition("JNZ",flags)) goto L005cb5bb;
  }
  L005cb5b0: { // 0x5cb5b0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cb5b2: { // 0x5cb5b2: e8f991f2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6075831u); flags=s.arithmetic_flags;
  }
  L005cb5b7: { // 0x5cb5b7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb5b9: { // 0x5cb5b9: 7505 JNZ 0x005cb5c0
    if(integer::condition("JNZ",flags)) goto L005cb5c0;
  }
  L005cb5bb: { // 0x5cb5bb: e8a073ebff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,6075840u); flags=s.arithmetic_flags;
  }
  L005cb5c0: { // 0x5cb5c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005cb5c2: { // 0x5cb5c2: 0f84b3000000 JZ 0x005cb67b
    if(integer::condition("JZ",flags)) goto L005cb67b;
  }
  L005cb5c8: { // 0x5cb5c8: 8a5614 MOV DL,byte ptr [ESI + 0x14]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000014u)));
  }
  L005cb5cb: { // 0x5cb5cb: 80e201 AND DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags));
  }
  L005cb5ce: { // 0x5cb5ce: 8854240b MOV byte ptr [ESP + 0xb],DL
    m.w8((f.sp+0x0000000bu), (s.dx & 0xffu));
  }
  L005cb5d2: { // 0x5cb5d2: 0f84a3000000 JZ 0x005cb67b
    if(integer::condition("JZ",flags)) goto L005cb67b;
  }
  L005cb5d8: { // 0x5cb5d8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cb5da: { // 0x5cb5da: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb5dc: { // 0x5cb5dc: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6075874u); flags=s.arithmetic_flags;
  }
  L005cb5e2: { // 0x5cb5e2: 8a88a80a0000 MOV CL,byte ptr [EAX + 0xaa8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa8u)));
  }
  L005cb5e8: { // 0x5cb5e8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cb5ea: { // 0x5cb5ea: 0f848b000000 JZ 0x005cb67b
    if(integer::condition("JZ",flags)) goto L005cb67b;
  }
  L005cb5f0: { // 0x5cb5f0: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb5f5: { // 0x5cb5f5: 8b0da888a200 MOV ECX,dword ptr [0x00a288a8]
    s.cx = m.r32((0x00a288a8u));
  }
  L005cb5fb: { // 0x5cb5fb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cb5fd: { // 0x5cb5fd: 7c3e JL 0x005cb63d
    if(integer::condition("JL",flags)) goto L005cb63d;
  }
  L005cb5ff: { // 0x5cb5ff: a0ad88a200 MOV AL,[0x00a288ad]
    s.ax = with_al(s.ax, m.r8((0x00a288adu)));
  }
  L005cb604: { // 0x5cb604: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb606: { // 0x5cb606: 7508 JNZ 0x005cb610
    if(integer::condition("JNZ",flags)) goto L005cb610;
  }
  L005cb608: { // 0x5cb608: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cb60a: { // 0x5cb60a: 0f85c1000000 JNZ 0x005cb6d1
    if(integer::condition("JNZ",flags)) goto L005cb6d1;
  }
  L005cb610: { // 0x5cb610: a1b488a200 MOV EAX,[0x00a288b4]
    s.ax = m.r32((0x00a288b4u));
  }
  L005cb615: { // 0x5cb615: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb617: { // 0x5cb617: 0f8eb4000000 JLE 0x005cb6d1
    if(integer::condition("JLE",flags)) goto L005cb6d1;
  }
  L005cb61d: { // 0x5cb61d: 8b15a088a200 MOV EDX,dword ptr [0x00a288a0]
    s.dx = m.r32((0x00a288a0u));
  }
  L005cb623: { // 0x5cb623: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005cb625: { // 0x5cb625: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cb627: { // 0x5cb627: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb628: { // 0x5cb628: b9a088a200 MOV ECX,0xa288a0
    s.cx = 0x00a288a0u;
  }
  L005cb62d: { // 0x5cb62d: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6075952u); flags=s.arithmetic_flags;
  }
  L005cb630: { // 0x5cb630: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb632: { // 0x5cb632: 0f8499000000 JZ 0x005cb6d1
    if(integer::condition("JZ",flags)) goto L005cb6d1;
  }
  L005cb638: { // 0x5cb638: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb63d: { // 0x5cb63d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb63f: { // 0x5cb63f: 7416 JZ 0x005cb657
    if(integer::condition("JZ",flags)) goto L005cb657;
  }
  L005cb641: { // 0x5cb641: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L005cb644: { // 0x5cb644: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb645: { // 0x5cb645: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L005cb64a: { // 0x5cb64a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb64b: { // 0x5cb64b: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005cb64e: { // 0x5cb64e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb64f: { // 0x5cb64f: e87c351a00 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,6075988u); flags=s.arithmetic_flags;
  }
  L005cb654: { // 0x5cb654: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005cb657: { // 0x5cb657: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L005cb65d: { // 0x5cb65d: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  L005cb65f: { // 0x5cb65f: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb664: { // 0x5cb664: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005cb665: { // 0x5cb665: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005cb667: { // 0x5cb667: a3b088a200 MOV [0x00a288b0],EAX
    m.w32((0x00a288b0u), s.ax);
  }
  L005cb66c: { // 0x5cb66c: e86fff1100 CALL 0x006eb5e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eb5e0u,6076017u); flags=s.arithmetic_flags;
  }
  L005cb671: { // 0x5cb671: c6467701 MOV byte ptr [ESI + 0x77],0x1
    m.w8((s.si+0x00000077u), 0x00000001u);
  }
  L005cb675: { // 0x5cb675: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb676: { // 0x5cb676: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cb678: { // 0x5cb678: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb679: { // 0x5cb679: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb67a: { // 0x5cb67a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cb67b: { // 0x5cb67b: a1a888a200 MOV EAX,[0x00a288a8]
    s.ax = m.r32((0x00a288a8u));
  }
  L005cb680: { // 0x5cb680: 8b0db088a200 MOV ECX,dword ptr [0x00a288b0]
    s.cx = m.r32((0x00a288b0u));
  }
  L005cb686: { // 0x5cb686: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005cb688: { // 0x5cb688: 7c2f JL 0x005cb6b9
    if(integer::condition("JL",flags)) goto L005cb6b9;
  }
  L005cb68a: { // 0x5cb68a: 8a0dad88a200 MOV CL,byte ptr [0x00a288ad]
    s.cx = with_al(s.cx, m.r8((0x00a288adu)));
  }
  L005cb690: { // 0x5cb690: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cb692: { // 0x5cb692: 7504 JNZ 0x005cb698
    if(integer::condition("JNZ",flags)) goto L005cb698;
  }
  L005cb694: { // 0x5cb694: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb696: { // 0x5cb696: 7539 JNZ 0x005cb6d1
    if(integer::condition("JNZ",flags)) goto L005cb6d1;
  }
  L005cb698: { // 0x5cb698: 8b0db488a200 MOV ECX,dword ptr [0x00a288b4]
    s.cx = m.r32((0x00a288b4u));
  }
  L005cb69e: { // 0x5cb69e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cb6a0: { // 0x5cb6a0: 7e2f JLE 0x005cb6d1
    if(integer::condition("JLE",flags)) goto L005cb6d1;
  }
  L005cb6a2: { // 0x5cb6a2: 8b15a088a200 MOV EDX,dword ptr [0x00a288a0]
    s.dx = m.r32((0x00a288a0u));
  }
  L005cb6a8: { // 0x5cb6a8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005cb6aa: { // 0x5cb6aa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cb6ac: { // 0x5cb6ac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cb6ad: { // 0x5cb6ad: b9a088a200 MOV ECX,0xa288a0
    s.cx = 0x00a288a0u;
  }
  L005cb6b2: { // 0x5cb6b2: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6076085u); flags=s.arithmetic_flags;
  }
  L005cb6b5: { // 0x5cb6b5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb6b7: { // 0x5cb6b7: 7418 JZ 0x005cb6d1
    if(integer::condition("JZ",flags)) goto L005cb6d1;
  }
  L005cb6b9: { // 0x5cb6b9: 8b0db088a200 MOV ECX,dword ptr [0x00a288b0]
    s.cx = m.r32((0x00a288b0u));
  }
  L005cb6bf: { // 0x5cb6bf: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cb6c1: { // 0x5cb6c1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cb6c2: { // 0x5cb6c2: 890db088a200 MOV dword ptr [0x00a288b0],ECX
    m.w32((0x00a288b0u), s.cx);
  }
  L005cb6c8: { // 0x5cb6c8: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L005cb6ce: { // 0x5cb6ce: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cb6d1: { // 0x5cb6d1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005cb6d3: { // 0x5cb6d3: e808ff1100 CALL 0x006eb5e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eb5e0u,6076120u); flags=s.arithmetic_flags;
  }
  L005cb6d8: { // 0x5cb6d8: c6467701 MOV byte ptr [ESI + 0x77],0x1
    m.w8((s.si+0x00000077u), 0x00000001u);
  }
  L005cb6dc: { // 0x5cb6dc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb6dd: { // 0x5cb6dd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cb6df: { // 0x5cb6df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb6e0: { // 0x5cb6e0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb6e1: { // 0x5cb6e1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000dc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040dc20: { // 0x40dc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040dc21: { // 0x40dc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0040dc23: { // 0x40dc23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0040dc25: { // 0x40dc25: 741e JZ 0x0040dc45
    if(integer::condition("JZ",flags)) goto L0040dc45;
  }
  L0040dc27: { // 0x40dc27: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0040dc29: { // 0x40dc29: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4250668u); flags=s.arithmetic_flags;
  }
  L0040dc2c: { // 0x40dc2c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0040dc2d: { // 0x40dc2d: 83f80e CMP EAX,0xe
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  L0040dc30: { // 0x40dc30: 7713 JA 0x0040dc45
    if(integer::condition("JA",flags)) goto L0040dc45;
  }
  L0040dc32: { // 0x40dc32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040dc34: { // 0x40dc34: 8a8854dc4000 MOV CL,byte ptr [EAX + 0x40dc54]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0040dc54u)));
  }
  L0040dc3a: { // 0x40dc3a: ff248d4cdc4000 JMP dword ptr [ECX*0x4 + 0x40dc4c]
    switch(m.r32(((s.cx * 0x00000004u)+0x0040dc4cu))){
    case 0x0040dc20u: goto L0040dc20;
    case 0x0040dc21u: goto L0040dc21;
    case 0x0040dc23u: goto L0040dc23;
    case 0x0040dc25u: goto L0040dc25;
    case 0x0040dc27u: goto L0040dc27;
    case 0x0040dc29u: goto L0040dc29;
    case 0x0040dc2cu: goto L0040dc2c;
    case 0x0040dc2du: goto L0040dc2d;
    case 0x0040dc30u: goto L0040dc30;
    case 0x0040dc32u: goto L0040dc32;
    case 0x0040dc34u: goto L0040dc34;
    case 0x0040dc3au: goto L0040dc3a;
    case 0x0040dc41u: goto L0040dc41;
    case 0x0040dc43u: goto L0040dc43;
    case 0x0040dc44u: goto L0040dc44;
    case 0x0040dc45u: goto L0040dc45;
    case 0x0040dc47u: goto L0040dc47;
    case 0x0040dc48u: goto L0040dc48;
    default:throw std::domain_error("555 unexpected switch");}
  }
  L0040dc41: { // 0x40dc41: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0040dc43: { // 0x40dc43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc44: { // 0x40dc44: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0040dc45: { // 0x40dc45: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040dc47: { // 0x40dc47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc48: { // 0x40dc48: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002eb5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006eb5e0: { // 0x6eb5e0: 890db48daa00 MOV dword ptr [0x00aa8db4],ECX
    m.w32((0x00aa8db4u), s.cx);
  }
  L006eb5e6: { // 0x6eb5e6: c605b88daa0000 MOV byte ptr [0x00aa8db8],0x0
    m.w8((0x00aa8db8u), 0x00000000u);
  }
  L006eb5ed: { // 0x6eb5ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX,0x6
    s.ax = 0x00000006u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002be7a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006be7a0: { // 0x6be7a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006be7a1: { // 0x6be7a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006be7a3: { // 0x6be7a3: 8a8673030000 MOV AL,byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  L006be7a9: { // 0x6be7a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be7ab: { // 0x6be7ab: 7518 JNZ 0x006be7c5
    if(integer::condition("JNZ",flags)) goto L006be7c5;
  }
  L006be7ad: { // 0x6be7ad: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006be7b3: { // 0x6be7b3: e8f85fe3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7071672u); flags=s.arithmetic_flags;
  }
  L006be7b8: { // 0x6be7b8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be7ba: { // 0x6be7ba: 7509 JNZ 0x006be7c5
    if(integer::condition("JNZ",flags)) goto L006be7c5;
  }
  L006be7bc: { // 0x6be7bc: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  L006be7c1: { // 0x6be7c1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006be7c3: { // 0x6be7c3: 7551 JNZ 0x006be816
    if(integer::condition("JNZ",flags)) goto L006be816;
  }
  L006be7c5: { // 0x6be7c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be7c7: { // 0x6be7c7: e834cdf0ff CALL 0x005cb500
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cb500u,7071692u); flags=s.arithmetic_flags;
  }
  L006be7cc: { // 0x6be7cc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be7ce: { // 0x6be7ce: 7446 JZ 0x006be816
    if(integer::condition("JZ",flags)) goto L006be816;
  }
  L006be7d0: { // 0x6be7d0: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  L006be7d3: { // 0x6be7d3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006be7d5: { // 0x6be7d5: 7412 JZ 0x006be7e9
    if(integer::condition("JZ",flags)) goto L006be7e9;
  }
  L006be7d7: { // 0x6be7d7: a1507caa00 MOV EAX,[0x00aa7c50]
    s.ax = m.r32((0x00aa7c50u));
  }
  L006be7dc: { // 0x6be7dc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006be7de: { // 0x6be7de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006be7e0: { // 0x6be7e0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006be7e1: { // 0x6be7e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006be7e2: { // 0x6be7e2: 6a21 PUSH 0x21
    f.push(m,0x00000021u);
  }
  L006be7e4: { // 0x6be7e4: e857acfeff CALL 0x006a9440
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a9440u,7071721u); flags=s.arithmetic_flags;
  }
  L006be7e9: { // 0x6be7e9: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006be7ef: { // 0x6be7ef: e8bc5fe3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7071732u); flags=s.arithmetic_flags;
  }
  L006be7f4: { // 0x6be7f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be7f6: { // 0x6be7f6: 7413 JZ 0x006be80b
    if(integer::condition("JZ",flags)) goto L006be80b;
  }
  L006be7f8: { // 0x6be7f8: a076397c00 MOV AL,[0x007c3976]
    s.ax = with_al(s.ax, m.r8((0x007c3976u)));
  }
  L006be7fd: { // 0x6be7fd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be7ff: { // 0x6be7ff: 740a JZ 0x006be80b
    if(integer::condition("JZ",flags)) goto L006be80b;
  }
  L006be801: { // 0x6be801: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006be803: { // 0x6be803: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be805: { // 0x6be805: ff9210030000 CALL dword ptr [EDX + 0x310]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000310u)),7071755u); flags=s.arithmetic_flags;
  }
  L006be80b: { // 0x6be80b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be80d: { // 0x6be80d: e8aed9f4ff CALL 0x0060c1c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060c1c0u,7071762u); flags=s.arithmetic_flags;
  }
  L006be812: { // 0x6be812: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006be814: { // 0x6be814: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be815: { // 0x6be815: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006be816: { // 0x6be816: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be818: { // 0x6be818: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be819: { // 0x6be819: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000f47b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f47b0: { // 0x4f47b0: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004f47b5: { // 0x4f47b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f47b7: { // 0x4f47b7: 751d JNZ 0x004f47d6
    if(integer::condition("JNZ",flags)) goto L004f47d6;
  }
  L004f47b9: { // 0x4f47b9: 8a8134010000 MOV AL,byte ptr [ECX + 0x134]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000134u)));
  }
  L004f47bf: { // 0x4f47bf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47c1: { // 0x4f47c1: 750d JNZ 0x004f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47c3: { // 0x4f47c3: 8a8135010000 MOV AL,byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  L004f47c9: { // 0x4f47c9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47cb: { // 0x4f47cb: 7503 JNZ 0x004f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47cd: { // 0x4f47cd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47cf: { // 0x4f47cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d0: { // 0x4f47d0: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004f47d5: { // 0x4f47d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d6: { // 0x4f47d6: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L004f47dc: { // 0x4f47dc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47de: { // 0x4f47de: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f47e0: { // 0x4f47e0: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f47e3: { // 0x4f47e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0020c1c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060c1c0: { // 0x60c1c0: a0fee2a500 MOV AL,[0x00a5e2fe]
    s.ax = with_al(s.ax, m.r8((0x00a5e2feu)));
  }
  L0060c1c5: { // 0x60c1c5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060c1c7: { // 0x60c1c7: 755b JNZ 0x0060c224
    if(integer::condition("JNZ",flags)) goto L0060c224;
  }
  L0060c1c9: { // 0x60c1c9: a0fce2a500 MOV AL,[0x00a5e2fc]
    s.ax = with_al(s.ax, m.r8((0x00a5e2fcu)));
  }
  L0060c1ce: { // 0x60c1ce: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060c1cf: { // 0x60c1cf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060c1d0: { // 0x60c1d0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060c1d1: { // 0x60c1d1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060c1d3: { // 0x60c1d3: c605fee2a50001 MOV byte ptr [0x00a5e2fe],0x1
    m.w8((0x00a5e2feu), 0x00000001u);
  }
  L0060c1da: { // 0x60c1da: 743e JZ 0x0060c21a
    if(integer::condition("JZ",flags)) goto L0060c21a;
  }
  L0060c1dc: { // 0x60c1dc: e8bfa70b00 CALL 0x006c69a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c69a0u,6341089u); flags=s.arithmetic_flags;
  }
  L0060c1e1: { // 0x60c1e1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060c1e3: { // 0x60c1e3: 7435 JZ 0x0060c21a
    if(integer::condition("JZ",flags)) goto L0060c21a;
  }
  L0060c1e5: { // 0x60c1e5: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  L0060c1e8: { // 0x60c1e8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0060c1e9: { // 0x60c1e9: 782f JS 0x0060c21a
    if(integer::condition("JS",flags)) goto L0060c21a;
  }
  L0060c1eb: { // 0x60c1eb: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0060c1ee: { // 0x60c1ee: 8b3c88 MOV EDI,dword ptr [EAX + ECX*0x4]
    s.di = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0060c1f1: { // 0x60c1f1: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0060c1f3: { // 0x60c1f3: 7425 JZ 0x0060c21a
    if(integer::condition("JZ",flags)) goto L0060c21a;
  }
  L0060c1f5: { // 0x60c1f5: 8b5f10 MOV EBX,dword ptr [EDI + 0x10]
    s.bx = m.r32((s.di+0x00000010u));
  }
  L0060c1f8: { // 0x60c1f8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0060c1fa: { // 0x60c1fa: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0060c1fc: { // 0x60c1fc: 7e1c JLE 0x0060c21a
    if(integer::condition("JLE",flags)) goto L0060c21a;
  }
  L0060c1fe: { // 0x60c1fe: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0060c201: { // 0x60c201: 8b14b1 MOV EDX,dword ptr [ECX + ESI*0x4]
    s.dx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L0060c204: { // 0x60c204: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0060c206: { // 0x60c206: 8a4177 MOV AL,byte ptr [ECX + 0x77]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000077u)));
  }
  L0060c209: { // 0x60c209: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060c20b: { // 0x60c20b: 7508 JNZ 0x0060c215
    if(integer::condition("JNZ",flags)) goto L0060c215;
  }
  L0060c20d: { // 0x60c20d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0060c20f: { // 0x60c20f: ff9040010000 CALL dword ptr [EAX + 0x140]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000140u)),6341141u); flags=s.arithmetic_flags;
  }
  L0060c215: { // 0x60c215: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0060c216: { // 0x60c216: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0060c218: { // 0x60c218: 7ce4 JL 0x0060c1fe
    if(integer::condition("JL",flags)) goto L0060c1fe;
  }
  L0060c21a: { // 0x60c21a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060c21b: { // 0x60c21b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060c21c: { // 0x60c21c: c605fee2a50000 MOV byte ptr [0x00a5e2fe],0x0
    m.w8((0x00a5e2feu), 0x00000000u);
  }
  L0060c223: { // 0x60c223: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060c224: { // 0x60c224: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // 0x6b6912: ffa084000000 JMP dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.ax+0x00000084u))); return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX,dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002c9510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c9510: { // 0x6c9510: a076397c00 MOV AL,byte ptr [0x7c3976]
    s.ax = with_al(s.ax, m.r8((0x007c3976u)));
  }
  L006c9515: { // 0x6c9515: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c9516: { // 0x6c9516: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c9518: { // 0x6c9518: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c951a: { // 0x6c951a: 744f JZ 0x6c956b
    if(integer::condition("JZ",flags)) goto L006c956b;
  }
  L006c951c: { // 0x6c951c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c951e: { // 0x6c951e: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7116068u); flags=s.arithmetic_flags;
  }
  L006c9524: { // 0x6c9524: 8b88e0030000 MOV ECX,dword ptr [EAX + 0x3e0]
    s.cx = m.r32((s.ax+0x000003e0u));
  }
  L006c952a: { // 0x6c952a: 05d0030000 ADD EAX,0x3d0
    s.ax = integer::add(s.ax,0x000003d0u,32,flags);
  }
  L006c952f: { // 0x6c952f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c9531: { // 0x6c9531: 7438 JZ 0x6c956b
    if(integer::condition("JZ",flags)) goto L006c956b;
  }
  L006c9533: { // 0x6c9533: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c9535: { // 0x6c9535: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9537: { // 0x6c9537: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7116093u); flags=s.arithmetic_flags;
  }
  L006c953d: { // 0x6c953d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c953f: { // 0x6c953f: b958158200 MOV ECX,0x821558
    s.cx = 0x00821558u;
  }
  L006c9544: { // 0x6c9544: 81c6d0030000 ADD ESI,0x3d0
    s.si = integer::add(s.si,0x000003d0u,32,flags);
  }
  L006c954a: { // 0x6c954a: e89168f6ff CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,7116111u); flags=s.arithmetic_flags;
  }
  L006c954f: { // 0x6c954f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L006c9551: { // 0x6c9551: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c9553: { // 0x6c9553: f77610 DIV dword ptr [ESI + 0x10]
    const auto numerator=(std::uint64_t(s.dx)<<32)|s.ax;
    const auto divisor=m.r32((s.si+0x00000010u));
    if(!divisor||numerator/divisor>0xffffffffull)throw std::domain_error("555 unsigned divide fault");
    s.ax=std::uint32_t(numerator/divisor);s.dx=std::uint32_t(numerator%divisor);
  }
  L006c9556: { // 0x6c9556: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L006c9559: { // 0x6c9559: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L006c955e: { // 0x6c955e: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006c9561: { // 0x6c9561: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  L006c9566: { // 0x6c9566: e805f40300 CALL 0x708970
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708970u,7116139u); flags=s.arithmetic_flags;
  }
  L006c956b: { // 0x6c956b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c956c: { // 0x6c956c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0009e0e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049e0e0: { // 0x49e0e0: 83ec40 SUB ESP,0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L0049e0e3: { // 0x49e0e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049e0e4: { // 0x49e0e4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049e0e5: { // 0x49e0e5: 8b2db088a200 MOV EBP,dword ptr [0x00a288b0]
    s.bp = m.r32((0x00a288b0u));
  }
  L0049e0eb: { // 0x49e0eb: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0049e0ed: { // 0x49e0ed: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0049e0ef: { // 0x49e0ef: 0f8e99010000 JLE 0x0049e28e
    if(integer::condition("JLE",flags)) goto L0049e28e;
  }
  L0049e0f5: { // 0x49e0f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049e0f6: { // 0x49e0f6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049e0f7: { // 0x49e0f7: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049e0f9: { // 0x49e0f9: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049e0fb: { // 0x49e0fb: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0049e0fd: { // 0x49e0fd: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0049e0ff: { // 0x49e0ff: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0049e103: { // 0x49e103: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0049e107: { // 0x49e107: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0049e10b: { // 0x49e10b: 7e43 JLE 0x0049e150
    if(integer::condition("JLE",flags)) goto L0049e150;
  }
  L0049e10d: { // 0x49e10d: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L0049e112: { // 0x49e112: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0049e116: { // 0x49e116: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0049e118: { // 0x49e118: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0049e11b: { // 0x49e11b: 81c288000000 ADD EDX,0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L0049e121: { // 0x49e121: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0049e123: { // 0x49e123: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0049e125: { // 0x49e125: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0049e129: { // 0x49e129: 037c2438 ADD EDI,dword ptr [ESP + 0x38]
    s.di = integer::add(s.di,m.r32((f.sp+0x00000038u)),32,flags);
  }
  L0049e12d: { // 0x49e12d: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L0049e130: { // 0x49e130: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0049e132: { // 0x49e132: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049e136: { // 0x49e136: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L0049e139: { // 0x49e139: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0049e13d: { // 0x49e13d: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L0049e13f: { // 0x49e13f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0049e140: { // 0x49e140: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0049e144: { // 0x49e144: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0049e148: { // 0x49e148: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049e14c: { // 0x49e14c: 75c8 JNZ 0x0049e116
    if(integer::condition("JNZ",flags)) goto L0049e116;
  }
  L0049e14e: { // 0x49e14e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0049e150: { // 0x49e150: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0049e152: { // 0x49e152: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L0049e156: { // 0x49e156: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0049e15a: { // 0x49e15a: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0049e15e: { // 0x49e15e: 7421 JZ 0x0049e181
    if(integer::condition("JZ",flags)) goto L0049e181;
  }
  L0049e160: { // 0x49e160: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0049e162: { // 0x49e162: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049e163: { // 0x49e163: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049e165: { // 0x49e165: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0049e167: { // 0x49e167: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049e169: { // 0x49e169: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049e16a: { // 0x49e16a: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049e16c: { // 0x49e16c: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0049e170: { // 0x49e170: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049e172: { // 0x49e172: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0049e174: { // 0x49e174: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049e175: { // 0x49e175: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049e177: { // 0x49e177: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0049e17b: { // 0x49e17b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049e17d: { // 0x49e17d: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0049e181: { // 0x49e181: 83fd02 CMP EBP,0x2
    (void)integer::sub(s.bp,0x00000002u,32,flags);
  }
  L0049e184: { // 0x49e184: 0f8ef2000000 JLE 0x0049e27c
    if(integer::condition("JLE",flags)) goto L0049e27c;
  }
  L0049e18a: { // 0x49e18a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0049e18c: { // 0x49e18c: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0049e190: { // 0x49e190: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049e194: { // 0x49e194: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L0049e198: { // 0x49e198: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0049e19c: { // 0x49e19c: 0f8e90000000 JLE 0x0049e232
    if(integer::condition("JLE",flags)) goto L0049e232;
  }
  L0049e1a2: { // 0x49e1a2: eb0c JMP 0x0049e1b0
    goto L0049e1b0;
  }
  L0049e1a4: { // 0x49e1a4: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0049e1a8: { // 0x49e1a8: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L0049e1ac: { // 0x49e1ac: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0049e1b0: { // 0x49e1b0: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L0049e1b5: { // 0x49e1b5: 8b1498 MOV EDX,dword ptr [EAX + EBX*0x4]
    s.dx = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L0049e1b8: { // 0x49e1b8: 81c288000000 ADD EDX,0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L0049e1be: { // 0x49e1be: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L0049e1c0: { // 0x49e1c0: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0049e1c3: { // 0x49e1c3: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0049e1c5: { // 0x49e1c5: 8b5504 MOV EDX,dword ptr [EBP + 0x4]
    s.dx = m.r32((s.bp+0x00000004u));
  }
  L0049e1c8: { // 0x49e1c8: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0049e1ca: { // 0x49e1ca: 2b7508 SUB ESI,dword ptr [EBP + 0x8]
    s.si = integer::sub(s.si,m.r32((s.bp+0x00000008u)),32,flags);
  }
  L0049e1cd: { // 0x49e1cd: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049e1ce: { // 0x49e1ce: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049e1cf: { // 0x49e1cf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049e1d0: { // 0x49e1d0: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0049e1d4: { // 0x49e1d4: e857d4f7ff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,4841945u); flags=s.arithmetic_flags;
  }
  L0049e1d9: { // 0x49e1d9: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049e1db: { // 0x49e1db: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0049e1df: { // 0x49e1df: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L0049e1e3: { // 0x49e1e3: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0049e1e6: { // 0x49e1e6: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0049e1ea: { // 0x49e1ea: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0049e1ed: { // 0x49e1ed: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0049e1f1: { // 0x49e1f1: e88ad5f7ff CALL 0x0041b780
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b780u,4841974u); flags=s.arithmetic_flags;
  }
  L0049e1f6: { // 0x49e1f6: 3b442410 CMP EAX,dword ptr [ESP + 0x10]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0049e1fa: { // 0x49e1fa: 7e27 JLE 0x0049e223
    if(integer::condition("JLE",flags)) goto L0049e223;
  }
  L0049e1fc: { // 0x49e1fc: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L0049e202: { // 0x49e202: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0049e206: { // 0x49e206: 8b1499 MOV EDX,dword ptr [ECX + EBX*0x4]
    s.dx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L0049e209: { // 0x49e209: 81c288000000 ADD EDX,0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L0049e20f: { // 0x49e20f: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0049e211: { // 0x49e211: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0049e215: { // 0x49e215: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0049e218: { // 0x49e218: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0049e21c: { // 0x49e21c: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0049e21f: { // 0x49e21f: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0049e223: { // 0x49e223: 8b2db088a200 MOV EBP,dword ptr [0x00a288b0]
    s.bp = m.r32((0x00a288b0u));
  }
  L0049e229: { // 0x49e229: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0049e22a: { // 0x49e22a: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0049e22c: { // 0x49e22c: 0f8c72ffffff JL 0x0049e1a4
    if(integer::condition("JL",flags)) goto L0049e1a4;
  }
  L0049e232: { // 0x49e232: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  L0049e236: { // 0x49e236: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L0049e23a: { // 0x49e23a: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0049e23e: { // 0x49e23e: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0049e242: { // 0x49e242: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0049e246: { // 0x49e246: 2bfb SUB EDI,EBX
    s.di = integer::sub(s.di,s.bx,32,flags);
  }
  L0049e248: { // 0x49e248: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L0049e24c: { // 0x49e24c: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0049e24e: { // 0x49e24e: 8d4dff LEA ECX,[EBP + -0x1]
    s.cx = (s.bp-0x00000001u);
  }
  L0049e251: { // 0x49e251: 2bde SUB EBX,ESI
    s.bx = integer::sub(s.bx,s.si,32,flags);
  }
  L0049e253: { // 0x49e253: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049e255: { // 0x49e255: 7508 JNZ 0x0049e25f
    if(integer::condition("JNZ",flags)) goto L0049e25f;
  }
  L0049e257: { // 0x49e257: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0049e259: { // 0x49e259: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049e25b: { // 0x49e25b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0049e25d: { // 0x49e25d: eb11 JMP 0x0049e270
    goto L0049e270;
  }
  L0049e25f: { // 0x49e25f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049e260: { // 0x49e260: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049e262: { // 0x49e262: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049e264: { // 0x49e264: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0049e266: { // 0x49e266: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049e267: { // 0x49e267: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049e269: { // 0x49e269: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0049e26b: { // 0x49e26b: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0049e26d: { // 0x49e26d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049e26e: { // 0x49e26e: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0049e270: { // 0x49e270: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0049e274: { // 0x49e274: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0049e278: { // 0x49e278: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0049e27c: { // 0x49e27c: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0049e282: { // 0x49e282: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0049e286: { // 0x49e286: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049e287: { // 0x49e287: e864da1f00 CALL 0x0069bcf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069bcf0u,4842124u); flags=s.arithmetic_flags;
  }
  L0049e28c: { // 0x49e28c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049e28d: { // 0x49e28d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049e28e: { // 0x49e28e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049e28f: { // 0x49e28f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049e290: { // 0x49e290: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L0049e293: { // 0x49e293: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_0001b630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b630: { // 0x41b630: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0041b634: { // 0x41b634: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041b636: { // 0x41b636: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0041b63a: { // 0x41b63a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b63c: { // 0x41b63c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0041b640: { // 0x41b640: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0041b643: { // 0x41b643: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0041b646: { // 0x41b646: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0001b780(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b780: { // 0x41b780: db4108 FILD dword ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L0041b783: { // 0x41b783: db4104 FILD dword ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L0041b786: { // 0x41b786: db01 FILD dword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load_integer32(m.r32(address));
  }
  L0041b788: { // 0x41b788: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0041b78b: { // 0x41b78b: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0041b78d: { // 0x41b78d: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0041b78f: { // 0x41b78f: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0041b791: { // 0x41b791: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0041b793: { // 0x41b793: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0041b795: { // 0x41b795: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L0041b797: { // 0x41b797: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L0041b799: { // 0x41b799: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0041b79b: { // 0x41b79b: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0041b79e: { // 0x41b79e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0041b7a0: { // 0x41b7a0: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0041b7a2: { // 0x41b7a2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0041b7a4: { // 0x41b7a4: e8d7e80900 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4306857u); flags=s.arithmetic_flags;
  }
  L0041b7a9: { // 0x41b7a9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0041b7ac: { // 0x41b7ac: e99ff23400 JMP 0x0076aa50
    s.arithmetic_flags=flags; tail(m,s,f,0x0076aa50u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e0030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0030: { // 0x004e0030: a1ac1c8200 MOV EAX,[0x00821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L004e0035: { // 0x004e0035: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0037: { // 0x004e0037: 7407 JZ 0x004e0040
    if(integer::condition("JZ",flags)) goto L004e0040;
  }
  L004e0039: { // 0x004e0039: c6807d0d000001 MOV byte ptr [EAX + 0xd7d],0x1
    m.w8((s.ax+0x00000d7du), 0x00000001u);
  }
  L004e0040: { // 0x004e0040: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004e0044: { // 0x004e0044: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e0046: { // 0x004e0046: 7413 JZ 0x004e005b
    if(integer::condition("JZ",flags)) goto L004e005b;
  }
  L004e0048: { // 0x004e0048: 83790c02 CMP dword ptr [ECX + 0xc],0x2
    (void)integer::sub(m.r32((s.cx+0x0000000cu)),0x00000002u,32,flags);
  }
  L004e004c: { // 0x004e004c: 7403 JZ 0x004e0051
    if(integer::condition("JZ",flags)) goto L004e0051;
  }
  L004e004e: { // 0x004e004e: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004e0051: { // 0x004e0051: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e0056: { // 0x004e0056: e8557a0700 CALL 0x00557ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557ab0u,5111899u); flags=s.arithmetic_flags;
  }
  L004e005b: { // 0x004e005b: c20400 RET 0x4
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
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4834656u:f_0009c560(m,s,child,{});break;
case 5881424u:f_0019be50(m,s,child,{});break;
case 5881456u:f_0019be70(m,s,child,{});break;
case 5187024u:f_000f25d0(m,s,child,{});break;
case 5881920u:f_0019c040(m,s,child,{});break;
case 4834816u:f_0009c600(m,s,child,{});break;
case 4835104u:f_0009c720(m,s,child,{});break;
case 4835264u:f_0009c7c0(m,s,child,{});break;
case 4835424u:f_0009c860(m,s,child,{});break;
case 6075648u:f_001cb500(m,s,child,{});break;
case 4250656u:f_0000dc20(m,s,child,{});break;
case 7255520u:f_002eb5e0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 7071648u:f_002be7a0(m,s,child,{});break;
case 5195696u:f_000f47b0(m,s,child,{});break;
case 6341056u:f_0020c1c0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 7116048u:f_002c9510(m,s,child,{});break;
case 4841696u:f_0009e0e0(m,s,child,{});break;
case 6929648u:f_0029bcf0(m,s,child,{});break;
case 6913968u:f_00297fb0(m,s,child,{});break;
case 6939328u:f_0029e2c0(m,s,child,{});break;
case 6940592u:f_0029e7b0(m,s,child,{});break;
case 5824896u:f_0018e180(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4306480u:f_0001b630(m,s,child,{});break;
case 4306816u:f_0001b780(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 5111856u:f_000e0030(m,s,child,{});break;
case 5601968u:f_00157ab0(m,s,child,{});break;
default:throw std::domain_error("recovery555 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){switch(target){case 4834656u:f_0009c560(m,s,f,{});return;case 5881424u:f_0019be50(m,s,f,{});return;case 5881456u:f_0019be70(m,s,f,{});return;case 5187024u:f_000f25d0(m,s,f,{});return;case 5881920u:f_0019c040(m,s,f,{});return;case 4834816u:f_0009c600(m,s,f,{});return;case 4835104u:f_0009c720(m,s,f,{});return;case 4835264u:f_0009c7c0(m,s,f,{});return;case 4835424u:f_0009c860(m,s,f,{});return;case 6075648u:f_001cb500(m,s,f,{});return;case 4250656u:f_0000dc20(m,s,f,{});return;case 7255520u:f_002eb5e0(m,s,f,{});return;case 4536464u:f_00053890(m,s,f,{});return;case 7071648u:f_002be7a0(m,s,f,{});return;case 5195696u:f_000f47b0(m,s,f,{});return;case 6341056u:f_0020c1c0(m,s,f,{});return;case 7039248u:f_002b6910(m,s,f,{});return;case 4536496u:f_000538b0(m,s,f,{});return;case 7116048u:f_002c9510(m,s,f,{});return;case 4841696u:f_0009e0e0(m,s,f,{});return;case 6929648u:f_0029bcf0(m,s,f,{});return;case 6913968u:f_00297fb0(m,s,f,{});return;case 6939328u:f_0029e2c0(m,s,f,{});return;case 6940592u:f_0029e7b0(m,s,f,{});return;case 5824896u:f_0018e180(m,s,f,{});return;case 7776848u:f_0036aa50(m,s,f,{});return;case 4306480u:f_0001b630(m,s,f,{});return;case 4306816u:f_0001b780(m,s,f,{});return;case 4956288u:f_000ba080(m,s,f,{});return;case 5111856u:f_000e0030(m,s,f,{});return;case 5601968u:f_00157ab0(m,s,f,{});return;default:throw std::domain_error("555 unexpected tail");}}}

std::uint32_t fun_006eaf40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,23> table{0x41,0xdc,0x40,0x0,0x45,0xdc,0x40,0x0,0x0,0x0,0x1,0x1,0x1,0x0,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x0};leaf::Memory ro(table.data(),0x40dc4c,23);m.add(ro);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006eaf40: { // 0x6eaf40: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006eaf41: { // 0x6eaf41: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006eaf42: { // 0x6eaf42: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006eaf44: { // 0x6eaf44: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006eaf45: { // 0x6eaf45: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eaf47: { // 0x6eaf47: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eaf4c: { // 0x6eaf4c: e8cf17dbff CALL 0x0049c720
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c720u,7253841u); flags=s.arithmetic_flags;
  }
  L006eaf51: { // 0x6eaf51: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eaf56: { // 0x6eaf56: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eaf58: { // 0x6eaf58: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eaf5a: { // 0x6eaf5a: e8a116dbff CALL 0x0049c600
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c600u,7253855u); flags=s.arithmetic_flags;
  }
  L006eaf5f: { // 0x6eaf5f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eaf64: { // 0x6eaf64: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eaf66: { // 0x6eaf66: e85518dbff CALL 0x0049c7c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c7c0u,7253867u); flags=s.arithmetic_flags;
  }
  L006eaf6b: { // 0x6eaf6b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eaf70: { // 0x6eaf70: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eaf72: { // 0x6eaf72: e8e915dbff CALL 0x0049c560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c560u,7253879u); flags=s.arithmetic_flags;
  }
  L006eaf77: { // 0x6eaf77: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eaf7c: { // 0x6eaf7c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eaf7e: { // 0x6eaf7e: e8dd18dbff CALL 0x0049c860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c860u,7253891u); flags=s.arithmetic_flags;
  }
  L006eaf83: { // 0x6eaf83: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L006eaf88: { // 0x6eaf88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eaf8a: { // 0x6eaf8a: 7432 JZ 0x006eafbe
    if(integer::condition("JZ",flags)) goto L006eafbe;
  }
  L006eaf8c: { // 0x6eaf8c: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L006eaf92: { // 0x6eaf92: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006eaf94: { // 0x6eaf94: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eaf96: { // 0x6eaf96: 741b JZ 0x006eafb3
    if(integer::condition("JZ",flags)) goto L006eafb3;
  }
  L006eaf98: { // 0x6eaf98: 8a4014 MOV AL,byte ptr [EAX + 0x14]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000014u)));
  }
  L006eaf9b: { // 0x6eaf9b: c0e802 SHR AL,0x2
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L006eaf9e: { // 0x6eaf9e: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L006eafa0: { // 0x6eafa0: 8844240b MOV byte ptr [ESP + 0xb],AL
    m.w8((f.sp+0x0000000bu), (s.ax & 0xffu));
  }
  L006eafa4: { // 0x6eafa4: 740d JZ 0x006eafb3
    if(integer::condition("JZ",flags)) goto L006eafb3;
  }
  L006eafa6: { // 0x6eafa6: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L006eafa8: { // 0x6eafa8: 8d55ff LEA EDX,[EBP + -0x1]
    s.dx = (s.bp-0x00000001u);
  }
  L006eafab: { // 0x6eafab: 3991ac010000 CMP dword ptr [ECX + 0x1ac],EDX
    (void)integer::sub(m.r32((s.cx+0x000001acu)),s.dx,32,flags);
  }
  L006eafb1: { // 0x6eafb1: 740b JZ 0x006eafbe
    if(integer::condition("JZ",flags)) goto L006eafbe;
  }
  L006eafb3: { // 0x6eafb3: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L006eafb9: { // 0x6eafb9: e8c253fbff CALL 0x006a0380
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0380u,7253950u); flags=s.arithmetic_flags;
  }
  L006eafbe: { // 0x6eafbe: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L006eafc3: { // 0x6eafc3: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006eafc5: { // 0x6eafc5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eafc7: { // 0x6eafc7: 7e6a JLE 0x006eb033
    if(integer::condition("JLE",flags)) goto L006eb033;
  }
  L006eafc9: { // 0x6eafc9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006eafca: { // 0x6eafca: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  L006eafcf: { // 0x6eafcf: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L006eafd2: { // 0x6eafd2: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006eafd4: { // 0x6eafd4: 7452 JZ 0x006eb028
    if(integer::condition("JZ",flags)) goto L006eb028;
  }
  L006eafd6: { // 0x6eafd6: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L006eafd9: { // 0x6eafd9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eafdb: { // 0x6eafdb: 754b JNZ 0x006eb028
    if(integer::condition("JNZ",flags)) goto L006eb028;
  }
  L006eafdd: { // 0x6eafdd: 8b86ac010000 MOV EAX,dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  L006eafe3: { // 0x6eafe3: 8d4dff LEA ECX,[EBP + -0x1]
    s.cx = (s.bp-0x00000001u);
  }
  L006eafe6: { // 0x6eafe6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006eafe8: { // 0x6eafe8: 753e JNZ 0x006eb028
    if(integer::condition("JNZ",flags)) goto L006eb028;
  }
  L006eafea: { // 0x6eafea: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L006eafef: { // 0x6eafef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eaff1: { // 0x6eaff1: 750e JNZ 0x006eb001
    if(integer::condition("JNZ",flags)) goto L006eb001;
  }
  L006eaff3: { // 0x6eaff3: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L006eaff9: { // 0x6eaff9: 8a8235010000 MOV AL,byte ptr [EDX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000135u)));
  }
  L006eafff: { // 0x6eafff: eb0b JMP 0x006eb00c
    goto L006eb00c;
  }
  L006eb001: { // 0x6eb001: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006eb007: { // 0x6eb007: e8a497e0ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7254028u); flags=s.arithmetic_flags;
  }
  L006eb00c: { // 0x6eb00c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb00e: { // 0x6eb00e: 7418 JZ 0x006eb028
    if(integer::condition("JZ",flags)) goto L006eb028;
  }
  L006eb010: { // 0x6eb010: 8a4677 MOV AL,byte ptr [ESI + 0x77]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000077u)));
  }
  L006eb013: { // 0x6eb013: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb015: { // 0x6eb015: 7511 JNZ 0x006eb028
    if(integer::condition("JNZ",flags)) goto L006eb028;
  }
  L006eb017: { // 0x6eb017: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006eb019: { // 0x6eb019: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006eb01b: { // 0x6eb01b: ff9040010000 CALL dword ptr [EAX + 0x140]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000140u)),7254049u); flags=s.arithmetic_flags;
  }
  L006eb021: { // 0x6eb021: c60576397c0000 MOV byte ptr [0x007c3976],0x0
    m.w8((0x007c3976u), 0x00000000u);
  }
  L006eb028: { // 0x6eb028: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L006eb02d: { // 0x6eb02d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006eb02e: { // 0x6eb02e: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L006eb030: { // 0x6eb030: 7c98 JL 0x006eafca
    if(integer::condition("JL",flags)) goto L006eafca;
  }
  L006eb032: { // 0x6eb032: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eb033: { // 0x6eb033: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eb038: { // 0x6eb038: e8a330dbff CALL 0x0049e0e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049e0e0u,7254077u); flags=s.arithmetic_flags;
  }
  L006eb03d: { // 0x6eb03d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eb042: { // 0x6eb042: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006eb044: { // 0x6eb044: e8e74fdfff CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,7254089u); flags=s.arithmetic_flags;
  }
  L006eb049: { // 0x6eb049: c60576397c0001 MOV byte ptr [0x007c3976],0x1
    m.w8((0x007c3976u), 0x00000001u);
  }
  L006eb050: { // 0x6eb050: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006eb051: { // 0x6eb051: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006eb052: { // 0x6eb052: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006eb053: { // 0x6eb053: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
