#include "recovered/recovery_b542_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b542 {
namespace {
void f_00208d60(Memory&,State&,Frame&,const Operations&);
void f_00208380(Memory&,State&,Frame&,const Operations&);
void f_0002bcd0(Memory&,State&,Frame&,const Operations&);
void f_0019be50(Memory&,State&,Frame&,const Operations&);
void f_0019c040(Memory&,State&,Frame&,const Operations&);
void f_00298010(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00208d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00608d60: { // 0x00608d60: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00608d63: { // 0x00608d63: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00608d66: { // 0x00608d66: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00608d68: { // 0x00608d68: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00608d69: { // 0x00608d69: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00608d6a: { // 0x00608d6a: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00608d6d: { // 0x00608d6d: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L00608d71: { // 0x00608d71: e8eaf7ffff CALL 0x00608560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608560u,6327670u); flags=s.arithmetic_flags;
  }
  L00608d76: { // 0x00608d76: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00608d78: { // 0x00608d78: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00608d7b: { // 0x00608d7b: 8b7008 MOV ESI,dword ptr [EAX + 0x8]
    s.si = m.r32((s.ax+0x00000008u));
  }
  L00608d7e: { // 0x00608d7e: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00608d82: { // 0x00608d82: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00608d84: { // 0x00608d84: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L00608d86: { // 0x00608d86: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L00608d89: { // 0x00608d89: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  L00608d8c: { // 0x00608d8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00608d8d: { // 0x00608d8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00608d8e: { // 0x00608d8e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00608d91: { // 0x00608d91: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00208380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00608380: { // 0x00608380: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00608383: { // 0x00608383: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L00608387: { // 0x00608387: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00608388: { // 0x00608388: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0060838a: { // 0x0060838a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00608390: { // 0x00608390: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00608391: { // 0x00608391: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00608392: { // 0x00608392: e879fc0800 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6325143u); flags=s.arithmetic_flags;
  }
  L00608397: { // 0x00608397: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L0060839d: { // 0x0060839d: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L006083a3: { // 0x006083a3: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006083a7: { // 0x006083a7: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006083a9: { // 0x006083a9: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L006083ad: { // 0x006083ad: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006083af: { // 0x006083af: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L006083b1: { // 0x006083b1: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L006083b4: { // 0x006083b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006083b6: { // 0x006083b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006083b7: { // 0x006083b7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006083ba: { // 0x006083ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0002bcd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042bcd0: { // 0x42bcd0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0042bcd4: { // 0x42bcd4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042bcd6: { // 0x42bcd6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0042bcda: { // 0x42bcda: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042bcdc: { // 0x42bcdc: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0042bce0: { // 0x42bce0: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0042bce3: { // 0x42bce3: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0042bce7: { // 0x42bce7: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0042bcea: { // 0x42bcea: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0042bced: { // 0x42bced: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
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
void f_00298010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698010: { // 0x698010: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00698013: { // 0x698013: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00698014: { // 0x698014: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00698018: { // 0x698018: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00698019: { // 0x698019: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069801a: { // 0x69801a: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L0069801c: { // 0x69801c: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L0069801f: { // 0x69801f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00698023: { // 0x698023: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00698025: { // 0x698025: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698028: { // 0x698028: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698029: { // 0x698029: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0069802d: { // 0x69802d: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00698030: { // 0x698030: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698033: { // 0x698033: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069803b: { // 0x69803b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069803e: { // 0x69803e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069803f: { // 0x69803f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698041: { // 0x698041: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698043: { // 0x698043: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698046: { // 0x698046: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698048: { // 0x698048: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069804b: { // 0x69804b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069804d: { // 0x69804d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069804e: { // 0x69804e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698050: { // 0x698050: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698052: { // 0x698052: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698054: { // 0x698054: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00698057: { // 0x698057: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00698059: { // 0x698059: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069805b: { // 0x69805b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069805e: { // 0x69805e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069805f: { // 0x69805f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698061: { // 0x698061: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698063: { // 0x698063: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00698065: { // 0x698065: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00698068: { // 0x698068: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069806a: { // 0x69806a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069806d: { // 0x69806d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00698071: { // 0x698071: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00698073: { // 0x698073: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698074: { // 0x698074: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698076: { // 0x698076: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0069807a: { // 0x69807a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069807c: { // 0x69807c: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069807e: { // 0x69807e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698080: { // 0x698080: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698081: { // 0x698081: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698087: { // 0x698087: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698089: { // 0x698089: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069808b: { // 0x69808b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069808d: { // 0x69808d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069808e: { // 0x69808e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698094: { // 0x698094: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698096: { // 0x698096: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698098: { // 0x698098: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809b: { // 0x69809b: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809e: { // 0x69809e: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L006980a4: { // 0x6980a4: 7c08 JL 0x006980ae
    if(integer::condition("JL",flags)) goto L006980ae;
  }
  L006980a6: { // 0x6980a6: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L006980ae: { // 0x6980ae: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006980b2: { // 0x6980b2: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L006980b8: { // 0x6980b8: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006980bc: { // 0x6980bc: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L006980c2: { // 0x6980c2: e889290d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914247u); flags=s.arithmetic_flags;
  }
  L006980c7: { // 0x6980c7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006980c9: { // 0x6980c9: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006980cd: { // 0x6980cd: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980cf: { // 0x6980cf: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980d2: { // 0x6980d2: 8b8db0000000 MOV ECX,dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L006980d8: { // 0x6980d8: 8badb4000000 MOV EBP,dword ptr [EBP + 0xb4]
    s.bp = m.r32((s.bp+0x000000b4u));
  }
  L006980de: { // 0x6980de: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L006980e0: { // 0x6980e0: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006980e3: { // 0x6980e3: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006980e5: { // 0x6980e5: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L006980e7: { // 0x6980e7: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980e9: { // 0x6980e9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006980eb: { // 0x6980eb: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980ee: { // 0x6980ee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006980f0: { // 0x6980f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006980f1: { // 0x6980f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006980f2: { // 0x6980f2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006980f3: { // 0x6980f3: 81f998feffff CMP ECX,0xfffffe98
    (void)integer::sub(s.cx,0xfffffe98u,32,flags);
  }
  L006980f9: { // 0x6980f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006980fa: { // 0x6980fa: 7d08 JGE 0x00698104
    if(integer::condition("JGE",flags)) goto L00698104;
  }
  L006980fc: { // 0x6980fc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006980fe: { // 0x6980fe: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698101: { // 0x698101: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00698104: { // 0x698104: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
  L0069810a: { // 0x69810a: 81c268010000 ADD EDX,0x168
    s.dx = integer::add(s.dx,0x00000168u,32,flags);
  }
  L00698110: { // 0x698110: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00698112: { // 0x698112: 7e08 JLE 0x0069811c
    if(integer::condition("JLE",flags)) goto L0069811c;
  }
  L00698114: { // 0x698114: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698116: { // 0x698116: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698119: { // 0x698119: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069811c: { // 0x69811c: 3d4cffffff CMP EAX,0xffffff4c
    (void)integer::sub(s.ax,0xffffff4cu,32,flags);
  }
  L00698121: { // 0x698121: 7d08 JGE 0x0069812b
    if(integer::condition("JGE",flags)) goto L0069812b;
  }
  L00698123: { // 0x698123: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698125: { // 0x698125: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698128: { // 0x698128: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069812b: { // 0x69812b: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L00698131: { // 0x698131: 81c1b4000000 ADD ECX,0xb4
    s.cx = integer::add(s.cx,0x000000b4u,32,flags);
  }
  L00698137: { // 0x698137: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00698139: { // 0x698139: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0069813c: { // 0x69813c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069813f: { // 0x69813f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
case 0x608560u:{Inputs i;i.cx=s.cx;i.dx=s.dx;i.fp=s.fp;s.ax=ra2::recovered::recovery_b338::fun_00608560(m,i);s.fp=i.fp;finish(m,s,child,0);break;}
case 6327648u:f_00208d60(m,s,child,{});break;
case 6325120u:f_00208380(m,s,child,{});break;
case 4373712u:f_0002bcd0(m,s,child,{});break;
case 5881424u:f_0019be50(m,s,child,{});break;
case 5881920u:f_0019c040(m,s,child,{});break;
case 6914064u:f_00298010(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery542 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0060f4e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060f4e0: { // 0x60f4e0: a0fce2a500 MOV AL,[0x00a5e2fc]
    s.ax = with_al(s.ax, m.r8((0x00a5e2fcu)));
  }
  L0060f4e5: { // 0x60f4e5: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L0060f4e8: { // 0x60f4e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060f4ea: { // 0x60f4ea: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060f4eb: { // 0x60f4eb: 7509 JNZ 0x0060f4f6
    if(integer::condition("JNZ",flags)) goto L0060f4f6;
  }
  L0060f4ed: { // 0x60f4ed: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0060f4ef: { // 0x60f4ef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f4f0: { // 0x60f4f0: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0060f4f3: { // 0x60f4f3: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f4f6: { // 0x60f4f6: a0c8e2a500 MOV AL,[0x00a5e2c8]
    s.ax = with_al(s.ax, m.r8((0x00a5e2c8u)));
  }
  L0060f4fb: { // 0x60f4fb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060f4fd: { // 0x60f4fd: 7409 JZ 0x0060f508
    if(integer::condition("JZ",flags)) goto L0060f508;
  }
  L0060f4ff: { // 0x60f4ff: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0060f501: { // 0x60f501: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f502: { // 0x60f502: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0060f505: { // 0x60f505: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f508: { // 0x60f508: 8b0de4e2a500 MOV ECX,dword ptr [0x00a5e2e4]
    s.cx = m.r32((0x00a5e2e4u));
  }
  L0060f50e: { // 0x60f50e: 8b1d50e2a500 MOV EBX,dword ptr [0x00a5e250]
    s.bx = m.r32((0x00a5e250u));
  }
  L0060f514: { // 0x60f514: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060f515: { // 0x60f515: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060f516: { // 0x60f516: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0060f518: { // 0x60f518: 0f848a000000 JZ 0x0060f5a8
    if(integer::condition("JZ",flags)) goto L0060f5a8;
  }
  L0060f51e: { // 0x60f51e: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0060f522: { // 0x60f522: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060f523: { // 0x60f523: e83898ffff CALL 0x00608d60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608d60u,6354216u); flags=s.arithmetic_flags;
  }
  L0060f528: { // 0x60f528: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0060f52a: { // 0x60f52a: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0060f52e: { // 0x60f52e: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0060f532: { // 0x60f532: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060f535: { // 0x60f535: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0060f539: { // 0x60f539: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0060f53d: { // 0x60f53d: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0060f540: { // 0x60f540: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0060f544: { // 0x60f544: e8378effff CALL 0x00608380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608380u,6354249u); flags=s.arithmetic_flags;
  }
  L0060f549: { // 0x60f549: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0060f54b: { // 0x60f54b: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0060f54d: { // 0x60f54d: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0060f54f: { // 0x60f54f: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0060f551: { // 0x60f551: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L0060f554: { // 0x60f554: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0060f557: { // 0x60f557: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L0060f55a: { // 0x60f55a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060f55b: { // 0x60f55b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060f55c: { // 0x60f55c: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L0060f560: { // 0x60f560: e86bc7e1ff CALL 0x0042bcd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042bcd0u,6354277u); flags=s.arithmetic_flags;
  }
  L0060f565: { // 0x60f565: 8b74243c MOV ESI,dword ptr [ESP + 0x3c]
    s.si = m.r32((f.sp+0x0000003cu));
  }
  L0060f569: { // 0x60f569: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0060f56d: { // 0x60f56d: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0060f571: { // 0x60f571: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0060f575: { // 0x60f575: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L0060f579: { // 0x60f579: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0060f57d: { // 0x60f57d: 83c2fc ADD EDX,-0x4
    s.dx = integer::add(s.dx,0xfffffffcu,32,flags);
  }
  L0060f580: { // 0x60f580: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L0060f583: { // 0x60f583: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L0060f586: { // 0x60f586: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  L0060f589: { // 0x60f589: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0060f58b: { // 0x60f58b: 7c1b JL 0x0060f5a8
    if(integer::condition("JL",flags)) goto L0060f5a8;
  }
  L0060f58d: { // 0x60f58d: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0060f58f: { // 0x60f58f: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0060f591: { // 0x60f591: 7d15 JGE 0x0060f5a8
    if(integer::condition("JGE",flags)) goto L0060f5a8;
  }
  L0060f593: { // 0x60f593: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0060f597: { // 0x60f597: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0060f599: { // 0x60f599: 7c0d JL 0x0060f5a8
    if(integer::condition("JL",flags)) goto L0060f5a8;
  }
  L0060f59b: { // 0x60f59b: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0060f59d: { // 0x60f59d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0060f59f: { // 0x60f59f: 7d07 JGE 0x0060f5a8
    if(integer::condition("JGE",flags)) goto L0060f5a8;
  }
  L0060f5a1: { // 0x60f5a1: a1e4e2a500 MOV EAX,[0x00a5e2e4]
    s.ax = m.r32((0x00a5e2e4u));
  }
  L0060f5a6: { // 0x60f5a6: eb02 JMP 0x0060f5aa
    goto L0060f5aa;
  }
  L0060f5a8: { // 0x60f5a8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0060f5aa: { // 0x60f5aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f5ab: { // 0x60f5ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f5ac: { // 0x60f5ac: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0060f5ae: { // 0x60f5ae: 750d JNZ 0x0060f5bd
    if(integer::condition("JNZ",flags)) goto L0060f5bd;
  }
  L0060f5b0: { // 0x60f5b0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060f5b2: { // 0x60f5b2: 7511 JNZ 0x0060f5c5
    if(integer::condition("JNZ",flags)) goto L0060f5c5;
  }
  L0060f5b4: { // 0x60f5b4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0060f5b6: { // 0x60f5b6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f5b7: { // 0x60f5b7: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0060f5ba: { // 0x60f5ba: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f5bd: { // 0x60f5bd: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0060f5bf: { // 0x60f5bf: 7404 JZ 0x0060f5c5
    if(integer::condition("JZ",flags)) goto L0060f5c5;
  }
  L0060f5c1: { // 0x60f5c1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0060f5c3: { // 0x60f5c3: eb02 JMP 0x0060f5c7
    goto L0060f5c7;
  }
  L0060f5c5: { // 0x60f5c5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0060f5c7: { // 0x60f5c7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0060f5c9: { // 0x60f5c9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0060f5ce: { // 0x60f5ce: e87dc8f8ff CALL 0x0059be50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0059be50u,6354387u); flags=s.arithmetic_flags;
  }
  L0060f5d3: { // 0x60f5d3: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0060f5d5: { // 0x60f5d5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f5d6: { // 0x60f5d6: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0060f5d9: { // 0x60f5d9: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
