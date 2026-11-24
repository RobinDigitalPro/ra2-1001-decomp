#include "recovered/recovery_b539_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b539 {
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
default:throw std::domain_error("recovery539 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0049ad70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049ad70: { // 0x49ad70: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ad71: { // 0x49ad71: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ad72: { // 0x49ad72: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0049ad74: { // 0x49ad74: 8b86a0110000 MOV EAX,dword ptr [ESI + 0x11a0]
    s.ax = m.r32((s.si+0x000011a0u));
  }
  L0049ad7a: { // 0x49ad7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ad7c: { // 0x49ad7c: 7444 JZ 0x0049adc2
    if(integer::condition("JZ",flags)) goto L0049adc2;
  }
  L0049ad7e: { // 0x49ad7e: 8a4014 MOV AL,byte ptr [EAX + 0x14]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000014u)));
  }
  L0049ad81: { // 0x49ad81: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L0049ad83: { // 0x49ad83: 88442407 MOV byte ptr [ESP + 0x7],AL
    m.w8((f.sp+0x00000007u), (s.ax & 0xffu));
  }
  L0049ad87: { // 0x49ad87: 7439 JZ 0x0049adc2
    if(integer::condition("JZ",flags)) goto L0049adc2;
  }
  L0049ad89: { // 0x49ad89: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ad8b: { // 0x49ad8b: c786a011000000000000 MOV dword ptr [ESI + 0x11a0],0x0
    m.w32((s.si+0x000011a0u), 0x00000000u);
  }
  L0049ad95: { // 0x49ad95: c786a411000000000000 MOV dword ptr [ESI + 0x11a4],0x0
    m.w32((s.si+0x000011a4u), 0x00000000u);
  }
  L0049ad9f: { // 0x49ad9f: c786a8110000ffffffff MOV dword ptr [ESI + 0x11a8],0xffffffff
    m.w32((s.si+0x000011a8u), 0xffffffffu);
  }
  L0049ada9: { // 0x49ada9: e842dfffff CALL 0x00498cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00498cf0u,4828590u); flags=s.arithmetic_flags;
  }
  L0049adae: { // 0x49adae: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049adb3: { // 0x49adb3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049adb5: { // 0x49adb5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049adb6: { // 0x49adb6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049adb8: { // 0x49adb8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049adba: { // 0x49adba: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828605u); flags=s.arithmetic_flags;
  }
  L0049adbd: { // 0x49adbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049adbe: { // 0x49adbe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049adbf: { // 0x49adbf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049adc2: { // 0x49adc2: 8a86ac110000 MOV AL,byte ptr [ESI + 0x11ac]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011acu)));
  }
  L0049adc8: { // 0x49adc8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049adca: { // 0x49adca: 741d JZ 0x0049ade9
    if(integer::condition("JZ",flags)) goto L0049ade9;
  }
  L0049adcc: { // 0x49adcc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049adce: { // 0x49adce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049add0: { // 0x49add0: e8eb190000 CALL 0x0049c7c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c7c0u,4828629u); flags=s.arithmetic_flags;
  }
  L0049add5: { // 0x49add5: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049adda: { // 0x49adda: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049addc: { // 0x49addc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049addd: { // 0x49addd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049addf: { // 0x49addf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ade1: { // 0x49ade1: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828644u); flags=s.arithmetic_flags;
  }
  L0049ade4: { // 0x49ade4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ade5: { // 0x49ade5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049ade6: { // 0x49ade6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049ade9: { // 0x49ade9: 8a86ad110000 MOV AL,byte ptr [ESI + 0x11ad]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011adu)));
  }
  L0049adef: { // 0x49adef: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049adf1: { // 0x49adf1: 741d JZ 0x0049ae10
    if(integer::condition("JZ",flags)) goto L0049ae10;
  }
  L0049adf3: { // 0x49adf3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049adf5: { // 0x49adf5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049adf7: { // 0x49adf7: e864170000 CALL 0x0049c560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c560u,4828668u); flags=s.arithmetic_flags;
  }
  L0049adfc: { // 0x49adfc: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049ae01: { // 0x49ae01: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049ae03: { // 0x49ae03: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ae04: { // 0x49ae04: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae06: { // 0x49ae06: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ae08: { // 0x49ae08: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828683u); flags=s.arithmetic_flags;
  }
  L0049ae0b: { // 0x49ae0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ae0c: { // 0x49ae0c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049ae0d: { // 0x49ae0d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049ae10: { // 0x49ae10: 8a86ae110000 MOV AL,byte ptr [ESI + 0x11ae]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011aeu)));
  }
  L0049ae16: { // 0x49ae16: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ae18: { // 0x49ae18: 741d JZ 0x0049ae37
    if(integer::condition("JZ",flags)) goto L0049ae37;
  }
  L0049ae1a: { // 0x49ae1a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae1c: { // 0x49ae1c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ae1e: { // 0x49ae1e: e8fd180000 CALL 0x0049c720
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c720u,4828707u); flags=s.arithmetic_flags;
  }
  L0049ae23: { // 0x49ae23: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049ae28: { // 0x49ae28: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049ae2a: { // 0x49ae2a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ae2b: { // 0x49ae2b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae2d: { // 0x49ae2d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ae2f: { // 0x49ae2f: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828722u); flags=s.arithmetic_flags;
  }
  L0049ae32: { // 0x49ae32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ae33: { // 0x49ae33: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049ae34: { // 0x49ae34: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049ae37: { // 0x49ae37: 8b8eb4110000 MOV ECX,dword ptr [ESI + 0x11b4]
    s.cx = m.r32((s.si+0x000011b4u));
  }
  L0049ae3d: { // 0x49ae3d: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0049ae40: { // 0x49ae40: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0049ae42: { // 0x49ae42: 741a JZ 0x0049ae5e
    if(integer::condition("JZ",flags)) goto L0049ae5e;
  }
  L0049ae44: { // 0x49ae44: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049ae46: { // 0x49ae46: 8986b4110000 MOV dword ptr [ESI + 0x11b4],EAX
    m.w32((s.si+0x000011b4u), s.ax);
  }
  L0049ae4c: { // 0x49ae4c: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049ae51: { // 0x49ae51: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ae53: { // 0x49ae53: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ae54: { // 0x49ae54: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae56: { // 0x49ae56: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828761u); flags=s.arithmetic_flags;
  }
  L0049ae59: { // 0x49ae59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ae5a: { // 0x49ae5a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049ae5b: { // 0x49ae5b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049ae5e: { // 0x49ae5e: 8a86af110000 MOV AL,byte ptr [ESI + 0x11af]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011afu)));
  }
  L0049ae64: { // 0x49ae64: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ae66: { // 0x49ae66: 741f JZ 0x0049ae87
    if(integer::condition("JZ",flags)) goto L0049ae87;
  }
  L0049ae68: { // 0x49ae68: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae6a: { // 0x49ae6a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae6c: { // 0x49ae6c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ae6e: { // 0x49ae6e: e88d170000 CALL 0x0049c600
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c600u,4828787u); flags=s.arithmetic_flags;
  }
  L0049ae73: { // 0x49ae73: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049ae78: { // 0x49ae78: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049ae7a: { // 0x49ae7a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ae7b: { // 0x49ae7b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae7d: { // 0x49ae7d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ae7f: { // 0x49ae7f: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828802u); flags=s.arithmetic_flags;
  }
  L0049ae82: { // 0x49ae82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049ae83: { // 0x49ae83: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049ae84: { // 0x49ae84: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049ae87: { // 0x49ae87: 8a86b0110000 MOV AL,byte ptr [ESI + 0x11b0]
    s.ax = with_al(s.ax, m.r8((s.si+0x000011b0u)));
  }
  L0049ae8d: { // 0x49ae8d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ae8f: { // 0x49ae8f: 741d JZ 0x0049aeae
    if(integer::condition("JZ",flags)) goto L0049aeae;
  }
  L0049ae91: { // 0x49ae91: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049ae93: { // 0x49ae93: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049ae95: { // 0x49ae95: e8c6190000 CALL 0x0049c860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049c860u,4828826u); flags=s.arithmetic_flags;
  }
  L0049ae9a: { // 0x49ae9a: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049ae9f: { // 0x49ae9f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049aea1: { // 0x49aea1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049aea2: { // 0x49aea2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049aea4: { // 0x49aea4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049aea6: { // 0x49aea6: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828841u); flags=s.arithmetic_flags;
  }
  L0049aea9: { // 0x49aea9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049aeaa: { // 0x49aeaa: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049aeab: { // 0x49aeab: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049aeae: { // 0x49aeae: e8ad7afeff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,4828851u); flags=s.arithmetic_flags;
  }
  L0049aeb3: { // 0x49aeb3: a04cf78100 MOV AL,[0x0081f74c]
    s.ax = with_al(s.ax, m.r8((0x0081f74cu)));
  }
  L0049aeb8: { // 0x49aeb8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049aeba: { // 0x49aeba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049aebb: { // 0x49aebb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049aebd: { // 0x49aebd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049aebf: { // 0x49aebf: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4828866u); flags=s.arithmetic_flags;
  }
  L0049aec2: { // 0x49aec2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049aec3: { // 0x49aec3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049aec4: { // 0x49aec4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
