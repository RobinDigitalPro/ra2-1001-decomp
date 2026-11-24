#include "recovered/recovery_b554_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b554 {
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
void f_002a0380(Memory&,State&,Frame&,const Operations&);
void f_002ccf00(Memory&,State&,Frame&,const Operations&);
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
    default:throw std::domain_error("554 unexpected switch");}
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
    if(!divisor||numerator/divisor>0xffffffffull)throw std::domain_error("554 unsigned divide fault");
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
void f_002a0380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006a0380: { // 0x6a0380: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L006a0385: { // 0x6a0385: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a0387: { // 0x6a0387: 7418 JZ 0x006a03a1
    if(integer::condition("JZ",flags)) goto L006a03a1;
  }
  L006a0389: { // 0x6a0389: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L006a038e: { // 0x6a038e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006a0390: { // 0x6a0390: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006a0392: { // 0x6a0392: ff9244010000 CALL dword ptr [EDX + 0x144]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000144u)),6947736u); flags=s.arithmetic_flags;
  }
  L006a0398: { // 0x6a0398: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L006a039d: { // 0x6a039d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006a039f: { // 0x6a039f: 75e8 JNZ 0x006a0389
    if(integer::condition("JNZ",flags)) goto L006a0389;
  }
  L006a03a1: { // 0x6a03a1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006a03a3: { // 0x6a03a3: e938b20400 JMP 0x006eb5e0
    s.arithmetic_flags=flags; tail(m,s,f,0x006eb5e0u); return;
  }
}
void f_002ccf00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ccf00: { // 0x6ccf00: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006ccf05: { // 0x6ccf05: b919000000 MOV ECX,0x19
    s.cx = 0x00000019u;
  }
  L006ccf0a: { // 0x6ccf0a: a3807caa00 MOV [0x00aa7c80],EAX
    m.w32((0x00aa7c80u), s.ax);
  }
  L006ccf0f: { // 0x6ccf0f: 8b4424f8 MOV EAX,dword ptr [ESP + -0x8]
    s.ax = m.r32((f.sp-0x00000008u));
  }
  L006ccf13: { // 0x6ccf13: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006ccf16: { // 0x6ccf16: a3847caa00 MOV [0x00aa7c84],EAX
    m.w32((0x00aa7c84u), s.ax);
  }
  L006ccf1b: { // 0x6ccf1b: 890d887caa00 MOV dword ptr [0x00aa7c88],ECX
    m.w32((0x00aa7c88u), s.cx);
  }
  L006ccf21: { // 0x6ccf21: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006ccf24: { // 0x6ccf24: c3 RET
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
case 6947712u:f_002a0380(m,s,child,{});break;
case 7130880u:f_002ccf00(m,s,child,{});break;
default:throw std::domain_error("recovery554 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){switch(target){case 4834656u:f_0009c560(m,s,f,{});return;case 5881424u:f_0019be50(m,s,f,{});return;case 5881456u:f_0019be70(m,s,f,{});return;case 5187024u:f_000f25d0(m,s,f,{});return;case 5881920u:f_0019c040(m,s,f,{});return;case 4834816u:f_0009c600(m,s,f,{});return;case 4835104u:f_0009c720(m,s,f,{});return;case 4835264u:f_0009c7c0(m,s,f,{});return;case 4835424u:f_0009c860(m,s,f,{});return;case 6075648u:f_001cb500(m,s,f,{});return;case 4250656u:f_0000dc20(m,s,f,{});return;case 7255520u:f_002eb5e0(m,s,f,{});return;case 4536464u:f_00053890(m,s,f,{});return;case 7071648u:f_002be7a0(m,s,f,{});return;case 5195696u:f_000f47b0(m,s,f,{});return;case 6341056u:f_0020c1c0(m,s,f,{});return;case 7039248u:f_002b6910(m,s,f,{});return;case 4536496u:f_000538b0(m,s,f,{});return;case 7116048u:f_002c9510(m,s,f,{});return;case 6947712u:f_002a0380(m,s,f,{});return;case 7130880u:f_002ccf00(m,s,f,{});return;default:throw std::domain_error("554 unexpected tail");}}}

std::uint32_t fun_006eae60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,23> table{0x41,0xdc,0x40,0x0,0x45,0xdc,0x40,0x0,0x0,0x0,0x1,0x1,0x1,0x0,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x0};leaf::Memory ro(table.data(),0x40dc4c,23);m.add(ro);
 State s{};s.di=0x789abcdeu;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006eae60: { // 0x6eae60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006eae61: { // 0x6eae61: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006eae63: { // 0x6eae63: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006eae64: { // 0x6eae64: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eae66: { // 0x6eae66: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eae6b: { // 0x6eae6b: e8b018dbff CALL 0x0049c720
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c720u,7253616u); flags=s.arithmetic_flags;
  }
  L006eae70: { // 0x6eae70: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eae75: { // 0x6eae75: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eae77: { // 0x6eae77: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eae79: { // 0x6eae79: e88217dbff CALL 0x0049c600
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c600u,7253630u); flags=s.arithmetic_flags;
  }
  L006eae7e: { // 0x6eae7e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eae83: { // 0x6eae83: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eae85: { // 0x6eae85: e83619dbff CALL 0x0049c7c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c7c0u,7253642u); flags=s.arithmetic_flags;
  }
  L006eae8a: { // 0x6eae8a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eae8f: { // 0x6eae8f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eae91: { // 0x6eae91: e8ca16dbff CALL 0x0049c560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c560u,7253654u); flags=s.arithmetic_flags;
  }
  L006eae96: { // 0x6eae96: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006eae9b: { // 0x6eae9b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006eae9d: { // 0x6eae9d: e8be19dbff CALL 0x0049c860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c860u,7253666u); flags=s.arithmetic_flags;
  }
  L006eaea2: { // 0x6eaea2: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L006eaea8: { // 0x6eaea8: e8d354fbff CALL 0x006a0380
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a0380u,7253677u); flags=s.arithmetic_flags;
  }
  L006eaead: { // 0x6eaead: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L006eaeb2: { // 0x6eaeb2: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006eaeb4: { // 0x6eaeb4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eaeb6: { // 0x6eaeb6: c60576397c0001 MOV byte ptr [0x007c3976],0x1
    m.w8((0x007c3976u), 0x00000001u);
  }
  L006eaebd: { // 0x6eaebd: 7e6a JLE 0x006eaf29
    if(integer::condition("JLE",flags)) goto L006eaf29;
  }
  L006eaebf: { // 0x6eaebf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006eaec0: { // 0x6eaec0: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  L006eaec5: { // 0x6eaec5: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L006eaec8: { // 0x6eaec8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006eaeca: { // 0x6eaeca: 7452 JZ 0x006eaf1e
    if(integer::condition("JZ",flags)) goto L006eaf1e;
  }
  L006eaecc: { // 0x6eaecc: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L006eaecf: { // 0x6eaecf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eaed1: { // 0x6eaed1: 754b JNZ 0x006eaf1e
    if(integer::condition("JNZ",flags)) goto L006eaf1e;
  }
  L006eaed3: { // 0x6eaed3: 8b86ac010000 MOV EAX,dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  L006eaed9: { // 0x6eaed9: 8d4dff LEA ECX,[EBP + -0x1]
    s.cx = (s.bp-0x00000001u);
  }
  L006eaedc: { // 0x6eaedc: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006eaede: { // 0x6eaede: 753e JNZ 0x006eaf1e
    if(integer::condition("JNZ",flags)) goto L006eaf1e;
  }
  L006eaee0: { // 0x6eaee0: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L006eaee5: { // 0x6eaee5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006eaee7: { // 0x6eaee7: 750e JNZ 0x006eaef7
    if(integer::condition("JNZ",flags)) goto L006eaef7;
  }
  L006eaee9: { // 0x6eaee9: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L006eaeef: { // 0x6eaeef: 8a8235010000 MOV AL,byte ptr [EDX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000135u)));
  }
  L006eaef5: { // 0x6eaef5: eb0b JMP 0x006eaf02
    goto L006eaf02;
  }
  L006eaef7: { // 0x6eaef7: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006eaefd: { // 0x6eaefd: e8ae98e0ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7253762u); flags=s.arithmetic_flags;
  }
  L006eaf02: { // 0x6eaf02: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eaf04: { // 0x6eaf04: 7418 JZ 0x006eaf1e
    if(integer::condition("JZ",flags)) goto L006eaf1e;
  }
  L006eaf06: { // 0x6eaf06: 8a4677 MOV AL,byte ptr [ESI + 0x77]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000077u)));
  }
  L006eaf09: { // 0x6eaf09: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eaf0b: { // 0x6eaf0b: 7511 JNZ 0x006eaf1e
    if(integer::condition("JNZ",flags)) goto L006eaf1e;
  }
  L006eaf0d: { // 0x6eaf0d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006eaf0f: { // 0x6eaf0f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006eaf11: { // 0x6eaf11: ff9040010000 CALL dword ptr [EAX + 0x140]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000140u)),7253783u); flags=s.arithmetic_flags;
  }
  L006eaf17: { // 0x6eaf17: c60576397c0000 MOV byte ptr [0x007c3976],0x0
    m.w8((0x007c3976u), 0x00000000u);
  }
  L006eaf1e: { // 0x6eaf1e: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L006eaf23: { // 0x6eaf23: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006eaf24: { // 0x6eaf24: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L006eaf26: { // 0x6eaf26: 7c98 JL 0x006eaec0
    if(integer::condition("JL",flags)) goto L006eaec0;
  }
  L006eaf28: { // 0x6eaf28: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eaf29: { // 0x6eaf29: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006eaf2a: { // 0x6eaf2a: c60576397c0001 MOV byte ptr [0x007c3976],0x1
    m.w8((0x007c3976u), 0x00000001u);
  }
  L006eaf31: { // 0x6eaf31: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006eaf32: { // 0x6eaf32: e9c91ffeff JMP 0x006ccf00
    s.arithmetic_flags=flags; tail(m,s,f,0x006ccf00u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
