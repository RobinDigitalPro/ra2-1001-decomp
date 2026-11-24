#include "recovered/recovery_b746_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b746 {
namespace {
void f_0009dd30(Memory&,State&,Frame&,const Operations&);
void f_0009dba0(Memory&,State&,Frame&,const Operations&);
void f_000ee0a0(Memory&,State&,Frame&,const Operations&);
void f_000eba00(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_000e5110(Memory&,State&,Frame&,const Operations&);
void f_000e4d00(Memory&,State&,Frame&,const Operations&);
void f_000f2920(Memory&,State&,Frame&,const Operations&);

void f_0009dd30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049dd30: { // 0x49dd30: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049dd31: { // 0x49dd31: 8b1d7088a200 MOV EBX, dword ptr [0xa28870]
    s.bx = m.r32((0x00a28870u));
  }
  L0049dd37: { // 0x49dd37: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049dd38: { // 0x49dd38: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049dd3a: { // 0x49dd3a: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0049dd3c: { // 0x49dd3c: 0f8ef5000000 JLE 0x49de37
    if(integer::condition("JLE",flags)) goto L0049de37;
  }
  L0049dd42: { // 0x49dd42: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049dd43: { // 0x49dd43: 8b6c2414 MOV EBP, dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0049dd47: { // 0x49dd47: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049dd48: { // 0x49dd48: a16488a200 MOV EAX, dword ptr [0xa28864]
    s.ax = m.r32((0x00a28864u));
  }
  L0049dd4d: { // 0x49dd4d: 8b34b8 MOV ESI, dword ptr [EAX + EDI*4]
    s.si = m.r32((s.ax+(s.di * 4u)));
  }
  L0049dd50: { // 0x49dd50: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049dd52: { // 0x49dd52: 0f84d4000000 JZ 0x49de2c
    if(integer::condition("JZ",flags)) goto L0049de2c;
  }
  L0049dd58: { // 0x49dd58: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L0049dd5b: { // 0x49dd5b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dd5d: { // 0x49dd5d: 0f85c9000000 JNZ 0x49de2c
    if(integer::condition("JNZ",flags)) goto L0049de2c;
  }
  L0049dd63: { // 0x49dd63: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049dd65: { // 0x49dd65: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dd67: { // 0x49dd67: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4840810u); flags=s.arithmetic_flags;
  }
  L0049dd6a: { // 0x49dd6a: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L0049dd6d: { // 0x49dd6d: 750c JNZ 0x49dd7b
    if(integer::condition("JNZ",flags)) goto L0049dd7b;
  }
  L0049dd6f: { // 0x49dd6f: 8a442414 MOV AL, byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L0049dd73: { // 0x49dd73: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dd75: { // 0x49dd75: 0f85b1000000 JNZ 0x49de2c
    if(integer::condition("JNZ",flags)) goto L0049de2c;
  }
  L0049dd7b: { // 0x49dd7b: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0049dd81: { // 0x49dd81: e82a6a0500 CALL 0x4f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,4840838u); flags=s.arithmetic_flags;
  }
  L0049dd86: { // 0x49dd86: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dd88: { // 0x49dd88: 7440 JZ 0x49ddca
    if(integer::condition("JZ",flags)) goto L0049ddca;
  }
  L0049dd8a: { // 0x49dd8a: 8a8673030000 MOV AL, byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  L0049dd90: { // 0x49dd90: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dd92: { // 0x49dd92: 0f8494000000 JZ 0x49de2c
    if(integer::condition("JZ",flags)) goto L0049de2c;
  }
  L0049dd98: { // 0x49dd98: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049dd9a: { // 0x49dd9a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dd9c: { // 0x49dd9c: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dd9e: { // 0x49dd9e: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dda0: { // 0x49dda0: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dda2: { // 0x49dda2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dda4: { // 0x49dda4: ff901c040000 CALL dword ptr [EAX + 0x41c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000041cu)),4840874u); flags=s.arithmetic_flags;
  }
  L0049ddaa: { // 0x49ddaa: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049ddac: { // 0x49ddac: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049ddae: { // 0x49ddae: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4840884u); flags=s.arithmetic_flags;
  }
  L0049ddb4: { // 0x49ddb4: 8a88dd0a0000 MOV CL, byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0049ddba: { // 0x49ddba: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049ddbc: { // 0x49ddbc: 746e JZ 0x49de2c
    if(integer::condition("JZ",flags)) goto L0049de2c;
  }
  L0049ddbe: { // 0x49ddbe: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049ddc0: { // 0x49ddc0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049ddc2: { // 0x49ddc2: ff90b0030000 CALL dword ptr [EAX + 0x3b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000003b0u)),4840904u); flags=s.arithmetic_flags;
  }
  L0049ddc8: { // 0x49ddc8: eb62 JMP 0x49de2c
    goto L0049de2c;
  }
  L0049ddca: { // 0x49ddca: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049ddcc: { // 0x49ddcc: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049ddce: { // 0x49ddce: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4840913u); flags=s.arithmetic_flags;
  }
  L0049ddd1: { // 0x49ddd1: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L0049ddd4: { // 0x49ddd4: 7538 JNZ 0x49de0e
    if(integer::condition("JNZ",flags)) goto L0049de0e;
  }
  L0049ddd6: { // 0x49ddd6: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0049dddb: { // 0x49dddb: 8a882b140000 MOV CL, byte ptr [EAX + 0x142b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000142bu)));
  }
  L0049dde1: { // 0x49dde1: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049dde3: { // 0x49dde3: 7429 JZ 0x49de0e
    if(integer::condition("JZ",flags)) goto L0049de0e;
  }
  L0049dde5: { // 0x49dde5: 8b0de4e0a100 MOV ECX, dword ptr [0xa1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049ddeb: { // 0x49ddeb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ddec: { // 0x49ddec: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0049ddf2: { // 0x49ddf2: e8e96d0400 CALL 0x4e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4840951u); flags=s.arithmetic_flags;
  }
  L0049ddf7: { // 0x49ddf7: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ddf9: { // 0x49ddf9: 7413 JZ 0x49de0e
    if(integer::condition("JZ",flags)) goto L0049de0e;
  }
  L0049ddfb: { // 0x49ddfb: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049ddfd: { // 0x49ddfd: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049ddff: { // 0x49ddff: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049de01: { // 0x49de01: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049de02: { // 0x49de02: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049de04: { // 0x49de04: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049de06: { // 0x49de06: ff921c040000 CALL dword ptr [EDX + 0x41c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000041cu)),4840972u); flags=s.arithmetic_flags;
  }
  L0049de0c: { // 0x49de0c: eb1e JMP 0x49de2c
    goto L0049de2c;
  }
  L0049de0e: { // 0x49de0e: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049de10: { // 0x49de10: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049de12: { // 0x49de12: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4840984u); flags=s.arithmetic_flags;
  }
  L0049de18: { // 0x49de18: 8a88dd0a0000 MOV CL, byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0049de1e: { // 0x49de1e: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049de20: { // 0x49de20: 740a JZ 0x49de2c
    if(integer::condition("JZ",flags)) goto L0049de2c;
  }
  L0049de22: { // 0x49de22: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049de24: { // 0x49de24: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049de26: { // 0x49de26: ff92b0030000 CALL dword ptr [EDX + 0x3b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003b0u)),4841004u); flags=s.arithmetic_flags;
  }
  L0049de2c: { // 0x49de2c: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0049de2d: { // 0x49de2d: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0049de2f: { // 0x49de2f: 0f8c13ffffff JL 0x49dd48
    if(integer::condition("JL",flags)) goto L0049dd48;
  }
  L0049de35: { // 0x49de35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049de36: { // 0x49de36: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049de37: { // 0x49de37: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049de38: { // 0x49de38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049de39: { // 0x49de39: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0009dba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049dba0: { // 0x49dba0: 83ec18 SUB ESP, 0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0049dba3: { // 0x49dba3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049dba4: { // 0x49dba4: 8b1d7088a200 MOV EBX, dword ptr [0xa28870]
    s.bx = m.r32((0x00a28870u));
  }
  L0049dbaa: { // 0x49dbaa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049dbab: { // 0x49dbab: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049dbad: { // 0x49dbad: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0049dbaf: { // 0x49dbaf: 0f8e6a010000 JLE 0x49dd1f
    if(integer::condition("JLE",flags)) goto L0049dd1f;
  }
  L0049dbb5: { // 0x49dbb5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049dbb6: { // 0x49dbb6: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0049dbba: { // 0x49dbba: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049dbbb: { // 0x49dbbb: a16488a200 MOV EAX, dword ptr [0xa28864]
    s.ax = m.r32((0x00a28864u));
  }
  L0049dbc0: { // 0x49dbc0: 8b34b8 MOV ESI, dword ptr [EAX + EDI*4]
    s.si = m.r32((s.ax+(s.di * 4u)));
  }
  L0049dbc3: { // 0x49dbc3: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049dbc5: { // 0x49dbc5: 0f8449010000 JZ 0x49dd14
    if(integer::condition("JZ",flags)) goto L0049dd14;
  }
  L0049dbcb: { // 0x49dbcb: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L0049dbce: { // 0x49dbce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dbd0: { // 0x49dbd0: 0f853e010000 JNZ 0x49dd14
    if(integer::condition("JNZ",flags)) goto L0049dd14;
  }
  L0049dbd6: { // 0x49dbd6: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049dbd8: { // 0x49dbd8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dbda: { // 0x49dbda: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4840413u); flags=s.arithmetic_flags;
  }
  L0049dbdd: { // 0x49dbdd: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L0049dbe0: { // 0x49dbe0: 750c JNZ 0x49dbee
    if(integer::condition("JNZ",flags)) goto L0049dbee;
  }
  L0049dbe2: { // 0x49dbe2: 8a44242c MOV AL, byte ptr [ESP + 0x2c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000002cu)));
  }
  L0049dbe6: { // 0x49dbe6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dbe8: { // 0x49dbe8: 0f8526010000 JNZ 0x49dd14
    if(integer::condition("JNZ",flags)) goto L0049dd14;
  }
  L0049dbee: { // 0x49dbee: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0049dbf4: { // 0x49dbf4: e8b76b0500 CALL 0x4f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,4840441u); flags=s.arithmetic_flags;
  }
  L0049dbf9: { // 0x49dbf9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dbfb: { // 0x49dbfb: 747e JZ 0x49dc7b
    if(integer::condition("JZ",flags)) goto L0049dc7b;
  }
  L0049dbfd: { // 0x49dbfd: 8a8673030000 MOV AL, byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  L0049dc03: { // 0x49dc03: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dc05: { // 0x49dc05: 0f8409010000 JZ 0x49dd14
    if(integer::condition("JZ",flags)) goto L0049dd14;
  }
  L0049dc0b: { // 0x49dc0b: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049dc0d: { // 0x49dc0d: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dc0f: { // 0x49dc0f: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dc11: { // 0x49dc11: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dc13: { // 0x49dc13: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dc15: { // 0x49dc15: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dc17: { // 0x49dc17: ff9018040000 CALL dword ptr [EAX + 0x418]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000418u)),4840477u); flags=s.arithmetic_flags;
  }
  L0049dc1d: { // 0x49dc1d: 8d8e88000000 LEA ECX, [ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L0049dc23: { // 0x49dc23: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dc25: { // 0x49dc25: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0049dc27: { // 0x49dc27: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0049dc2b: { // 0x49dc2b: 8b96f4010000 MOV EDX, dword ptr [ESI + 0x1f4]
    s.dx = m.r32((s.si+0x000001f4u));
  }
  L0049dc31: { // 0x49dc31: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0049dc34: { // 0x49dc34: 83c203 ADD EDX, 3
    s.dx = integer::add(s.dx,3u,32,flags);
  }
  L0049dc37: { // 0x49dc37: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0049dc3b: { // 0x49dc3b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049dc3c: { // 0x49dc3c: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L0049dc3f: { // 0x49dc3f: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0049dc43: { // 0x49dc43: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0049dc47: { // 0x49dc47: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dc49: { // 0x49dc49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049dc4a: { // 0x49dc4a: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0049dc4f: { // 0x49dc4f: e88c9d0a00 CALL 0x5479e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005479e0u,4840532u); flags=s.arithmetic_flags;
  }
  L0049dc54: { // 0x49dc54: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049dc56: { // 0x49dc56: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dc58: { // 0x49dc58: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),4840542u); flags=s.arithmetic_flags;
  }
  L0049dc5e: { // 0x49dc5e: 8a88dd0a0000 MOV CL, byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0049dc64: { // 0x49dc64: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049dc66: { // 0x49dc66: 0f84a8000000 JZ 0x49dd14
    if(integer::condition("JZ",flags)) goto L0049dd14;
  }
  L0049dc6c: { // 0x49dc6c: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049dc6e: { // 0x49dc6e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dc70: { // 0x49dc70: ff90ac030000 CALL dword ptr [EAX + 0x3ac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000003acu)),4840566u); flags=s.arithmetic_flags;
  }
  L0049dc76: { // 0x49dc76: e999000000 JMP 0x49dd14
    goto L0049dd14;
  }
  L0049dc7b: { // 0x49dc7b: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049dc7d: { // 0x49dc7d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dc7f: { // 0x49dc7f: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4840578u); flags=s.arithmetic_flags;
  }
  L0049dc82: { // 0x49dc82: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L0049dc85: { // 0x49dc85: 756f JNZ 0x49dcf6
    if(integer::condition("JNZ",flags)) goto L0049dcf6;
  }
  L0049dc87: { // 0x49dc87: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0049dc8c: { // 0x49dc8c: 8a882b140000 MOV CL, byte ptr [EAX + 0x142b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000142bu)));
  }
  L0049dc92: { // 0x49dc92: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049dc94: { // 0x49dc94: 7460 JZ 0x49dcf6
    if(integer::condition("JZ",flags)) goto L0049dcf6;
  }
  L0049dc96: { // 0x49dc96: 8b0de4e0a100 MOV ECX, dword ptr [0xa1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0049dc9c: { // 0x49dc9c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049dc9d: { // 0x49dc9d: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0049dca3: { // 0x49dca3: e8386f0400 CALL 0x4e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4840616u); flags=s.arithmetic_flags;
  }
  L0049dca8: { // 0x49dca8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049dcaa: { // 0x49dcaa: 744a JZ 0x49dcf6
    if(integer::condition("JZ",flags)) goto L0049dcf6;
  }
  L0049dcac: { // 0x49dcac: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049dcae: { // 0x49dcae: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dcb0: { // 0x49dcb0: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dcb2: { // 0x49dcb2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049dcb3: { // 0x49dcb3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dcb5: { // 0x49dcb5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dcb7: { // 0x49dcb7: ff9218040000 CALL dword ptr [EDX + 0x418]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000418u)),4840637u); flags=s.arithmetic_flags;
  }
  L0049dcbd: { // 0x49dcbd: 8d8688000000 LEA EAX, [ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L0049dcc3: { // 0x49dcc3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dcc5: { // 0x49dcc5: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049dcc7: { // 0x49dcc7: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0049dccb: { // 0x49dccb: 8b8ef4010000 MOV ECX, dword ptr [ESI + 0x1f4]
    s.cx = m.r32((s.si+0x000001f4u));
  }
  L0049dcd1: { // 0x49dcd1: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0049dcd4: { // 0x49dcd4: 83c103 ADD ECX, 3
    s.cx = integer::add(s.cx,3u,32,flags);
  }
  L0049dcd7: { // 0x49dcd7: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0049dcdb: { // 0x49dcdb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049dcdc: { // 0x49dcdc: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L0049dcdf: { // 0x49dcdf: 8d542424 LEA EDX, [ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0049dce3: { // 0x49dce3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0049dce5: { // 0x49dce5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049dce6: { // 0x49dce6: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L0049dceb: { // 0x49dceb: 89442434 MOV dword ptr [ESP + 0x34], EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0049dcef: { // 0x49dcef: e8ec9c0a00 CALL 0x5479e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005479e0u,4840692u); flags=s.arithmetic_flags;
  }
  L0049dcf4: { // 0x49dcf4: eb1e JMP 0x49dd14
    goto L0049dd14;
  }
  L0049dcf6: { // 0x49dcf6: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0049dcf8: { // 0x49dcf8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dcfa: { // 0x49dcfa: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4840704u); flags=s.arithmetic_flags;
  }
  L0049dd00: { // 0x49dd00: 8a88dd0a0000 MOV CL, byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0049dd06: { // 0x49dd06: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0049dd08: { // 0x49dd08: 740a JZ 0x49dd14
    if(integer::condition("JZ",flags)) goto L0049dd14;
  }
  L0049dd0a: { // 0x49dd0a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049dd0c: { // 0x49dd0c: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0049dd0e: { // 0x49dd0e: ff92ac030000 CALL dword ptr [EDX + 0x3ac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003acu)),4840724u); flags=s.arithmetic_flags;
  }
  L0049dd14: { // 0x49dd14: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0049dd15: { // 0x49dd15: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0049dd17: { // 0x49dd17: 0f8c9efeffff JL 0x49dbbb
    if(integer::condition("JL",flags)) goto L0049dbbb;
  }
  L0049dd1d: { // 0x49dd1d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049dd1e: { // 0x49dd1e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049dd1f: { // 0x49dd1f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049dd20: { // 0x49dd20: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049dd21: { // 0x49dd21: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0049dd24: { // 0x49dd24: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000ee0a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ee0a0: { // 0x4ee0a0: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004ee0a2: { // 0x4ee0a2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ee0a3: { // 0x4ee0a3: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004ee0a5: { // 0x4ee0a5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004ee0a6: { // 0x4ee0a6: 8b8804550000 MOV ECX, dword ptr [EAX + 0x5504]
    s.cx = m.r32((s.ax+0x00005504u));
  }
  L004ee0ac: { // 0x4ee0ac: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004ee0ae: { // 0x4ee0ae: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ee0af: { // 0x4ee0af: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004ee0b1: { // 0x4ee0b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ee0b2: { // 0x4ee0b2: 7e26 JLE 0x4ee0da
    if(integer::condition("JLE",flags)) goto L004ee0da;
  }
  L004ee0b4: { // 0x4ee0b4: 8b742418 MOV ESI, dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L004ee0b8: { // 0x4ee0b8: 8b7c2414 MOV EDI, dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L004ee0bc: { // 0x4ee0bc: 8b88f8540000 MOV ECX, dword ptr [EAX + 0x54f8]
    s.cx = m.r32((s.ax+0x000054f8u));
  }
  L004ee0c2: { // 0x4ee0c2: 8b2cd1 MOV EBP, dword ptr [ECX + EDX*8]
    s.bp = m.r32((s.cx+(s.dx * 8u)));
  }
  L004ee0c5: { // 0x4ee0c5: 8d0cd1 LEA ECX, [ECX + EDX*8]
    s.cx = (s.cx+(s.dx * 8u));
  }
  L004ee0c8: { // 0x4ee0c8: 3bee CMP EBP, ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L004ee0ca: { // 0x4ee0ca: 7503 JNZ 0x4ee0cf
    if(integer::condition("JNZ",flags)) goto L004ee0cf;
  }
  L004ee0cc: { // 0x4ee0cc: 017904 ADD dword ptr [ECX + 4], EDI
    m.w32((s.cx+4u), integer::add(m.r32((s.cx+4u)),s.di,32,flags));
  }
  L004ee0cf: { // 0x4ee0cf: 8b8804550000 MOV ECX, dword ptr [EAX + 0x5504]
    s.cx = m.r32((s.ax+0x00005504u));
  }
  L004ee0d5: { // 0x4ee0d5: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004ee0d6: { // 0x4ee0d6: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L004ee0d8: { // 0x4ee0d8: 7ce2 JL 0x4ee0bc
    if(integer::condition("JL",flags)) goto L004ee0bc;
  }
  L004ee0da: { // 0x4ee0da: 8b8804550000 MOV ECX, dword ptr [EAX + 0x5504]
    s.cx = m.r32((s.ax+0x00005504u));
  }
  L004ee0e0: { // 0x4ee0e0: 895c2414 MOV dword ptr [ESP + 0x14], EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L004ee0e4: { // 0x4ee0e4: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004ee0e6: { // 0x4ee0e6: 7e74 JLE 0x4ee15c
    if(integer::condition("JLE",flags)) goto L004ee15c;
  }
  L004ee0e8: { // 0x4ee0e8: 8bb8f8540000 MOV EDI, dword ptr [EAX + 0x54f8]
    s.di = m.r32((s.ax+0x000054f8u));
  }
  L004ee0ee: { // 0x4ee0ee: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004ee0f2: { // 0x4ee0f2: 8b7704 MOV ESI, dword ptr [EDI + 4]
    s.si = m.r32((s.di+4u));
  }
  L004ee0f5: { // 0x4ee0f5: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004ee0f7: { // 0x4ee0f7: 3bf3 CMP ESI, EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004ee0f9: { // 0x4ee0f9: 7e3b JLE 0x4ee136
    if(integer::condition("JLE",flags)) goto L004ee136;
  }
  L004ee0fb: { // 0x4ee0fb: 8a8a3d010000 MOV CL, byte ptr [EDX + 0x13d]
    s.cx = with_al(s.cx, m.r8((s.dx+0x0000013du)));
  }
  L004ee101: { // 0x4ee101: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ee103: { // 0x4ee103: 7531 JNZ 0x4ee136
    if(integer::condition("JNZ",flags)) goto L004ee136;
  }
  L004ee105: { // 0x4ee105: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004ee107: { // 0x4ee107: 7427 JZ 0x4ee130
    if(integer::condition("JZ",flags)) goto L004ee130;
  }
  L004ee109: { // 0x4ee109: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004ee10b: { // 0x4ee10b: 7429 JZ 0x4ee136
    if(integer::condition("JZ",flags)) goto L004ee136;
  }
  L004ee10d: { // 0x4ee10d: 8b4a30 MOV ECX, dword ptr [EDX + 0x30]
    s.cx = m.r32((s.dx+0x00000030u));
  }
  L004ee110: { // 0x4ee110: 8b6830 MOV EBP, dword ptr [EAX + 0x30]
    s.bp = m.r32((s.ax+0x00000030u));
  }
  L004ee113: { // 0x4ee113: 3bcd CMP ECX, EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L004ee115: { // 0x4ee115: 741f JZ 0x4ee136
    if(integer::condition("JZ",flags)) goto L004ee136;
  }
  L004ee117: { // 0x4ee117: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004ee11a: { // 0x4ee11a: 7414 JZ 0x4ee130
    if(integer::condition("JZ",flags)) goto L004ee130;
  }
  L004ee11c: { // 0x4ee11c: bd01000000 MOV EBP, 1
    s.bp = 1u;
  }
  L004ee121: { // 0x4ee121: d3e5 SHL EBP, CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004ee123: { // 0x4ee123: 85a874560000 TEST dword ptr [EAX + 0x5674], EBP
    (void)integer::logical((m.r32((s.ax+0x00005674u)))&(s.bp),32,flags);
  }
  L004ee129: { // 0x4ee129: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004ee12c: { // 0x4ee12c: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ee12e: { // 0x4ee12e: 7506 JNZ 0x4ee136
    if(integer::condition("JNZ",flags)) goto L004ee136;
  }
  L004ee130: { // 0x4ee130: 8bde MOV EBX, ESI
    s.bx = s.si;
  }
  L004ee132: { // 0x4ee132: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L004ee136: { // 0x4ee136: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004ee13a: { // 0x4ee13a: 83c708 ADD EDI, 8
    s.di = integer::add(s.di,8u,32,flags);
  }
  L004ee13d: { // 0x4ee13d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004ee13e: { // 0x4ee13e: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004ee142: { // 0x4ee142: 75ae JNZ 0x4ee0f2
    if(integer::condition("JNZ",flags)) goto L004ee0f2;
  }
  L004ee144: { // 0x4ee144: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004ee148: { // 0x4ee148: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ee14a: { // 0x4ee14a: 7410 JZ 0x4ee15c
    if(integer::condition("JZ",flags)) goto L004ee15c;
  }
  L004ee14c: { // 0x4ee14c: 8b5130 MOV EDX, dword ptr [ECX + 0x30]
    s.dx = m.r32((s.cx+0x00000030u));
  }
  L004ee14f: { // 0x4ee14f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ee150: { // 0x4ee150: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ee151: { // 0x4ee151: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ee152: { // 0x4ee152: 8990f0540000 MOV dword ptr [EAX + 0x54f0], EDX
    m.w32((s.ax+0x000054f0u), s.dx);
  }
  L004ee158: { // 0x4ee158: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ee159: { // 0x4ee159: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004ee15c: { // 0x4ee15c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ee15d: { // 0x4ee15d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ee15e: { // 0x4ee15e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ee15f: { // 0x4ee15f: c780f0540000ffffffff MOV dword ptr [EAX + 0x54f0], 0xffffffff
    m.w32((s.ax+0x000054f0u), 0xffffffffu);
  }
  L004ee169: { // 0x4ee169: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ee16a: { // 0x4ee16a: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000eba00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004eba00: { // 0x4eba00: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004eba01: { // 0x4eba01: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004eba02: { // 0x4eba02: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L004eba06: { // 0x4eba06: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004eba08: { // 0x4eba08: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004eba0a: { // 0x4eba0a: 7430 JZ 0x4eba3c
    if(integer::condition("JZ",flags)) goto L004eba3c;
  }
  L004eba0c: { // 0x4eba0c: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L004eba0e: { // 0x4eba0e: 7425 JZ 0x4eba35
    if(integer::condition("JZ",flags)) goto L004eba35;
  }
  L004eba10: { // 0x4eba10: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L004eba13: { // 0x4eba13: 8b4630 MOV EAX, dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004eba16: { // 0x4eba16: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004eba18: { // 0x4eba18: 741b JZ 0x4eba35
    if(integer::condition("JZ",flags)) goto L004eba35;
  }
  L004eba1a: { // 0x4eba1a: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004eba1d: { // 0x4eba1d: 741d JZ 0x4eba3c
    if(integer::condition("JZ",flags)) goto L004eba3c;
  }
  L004eba1f: { // 0x4eba1f: 8b9674560000 MOV EDX, dword ptr [ESI + 0x5674]
    s.dx = m.r32((s.si+0x00005674u));
  }
  L004eba25: { // 0x4eba25: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004eba2a: { // 0x4eba2a: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004eba2c: { // 0x4eba2c: 85d0 TEST EAX, EDX
    (void)integer::logical((s.ax)&(s.dx),32,flags);
  }
  L004eba2e: { // 0x4eba2e: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004eba31: { // 0x4eba31: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004eba33: { // 0x4eba33: 7407 JZ 0x4eba3c
    if(integer::condition("JZ",flags)) goto L004eba3c;
  }
  L004eba35: { // 0x4eba35: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eba36: { // 0x4eba36: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004eba38: { // 0x4eba38: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eba39: { // 0x4eba39: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004eba3c: { // 0x4eba3c: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004eba41: { // 0x4eba41: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eba43: { // 0x4eba43: 7407 JZ 0x4eba4c
    if(integer::condition("JZ",flags)) goto L004eba4c;
  }
  L004eba45: { // 0x4eba45: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eba46: { // 0x4eba46: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004eba48: { // 0x4eba48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eba49: { // 0x4eba49: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004eba4c: { // 0x4eba4c: 8a863d010000 MOV AL, byte ptr [ESI + 0x13d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000013du)));
  }
  L004eba52: { // 0x4eba52: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004eba54: { // 0x4eba54: 7407 JZ 0x4eba5d
    if(integer::condition("JZ",flags)) goto L004eba5d;
  }
  L004eba56: { // 0x4eba56: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eba57: { // 0x4eba57: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004eba59: { // 0x4eba59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eba5a: { // 0x4eba5a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004eba5d: { // 0x4eba5d: b9c09a7b00 MOV ECX, 0x7b9ac0
    s.cx = 0x007b9ac0u;
  }
  L004eba62: { // 0x4eba62: e8a94e1800 CALL 0x670910
    s.arithmetic_flags=flags; invoke(m,s,f,0x00670910u,5159527u); flags=s.arithmetic_flags;
  }
  L004eba67: { // 0x4eba67: 8b4f34 MOV ECX, dword ptr [EDI + 0x34]
    s.cx = m.r32((s.di+0x00000034u));
  }
  L004eba6a: { // 0x4eba6a: 3981bc000000 CMP dword ptr [ECX + 0xbc], EAX
    (void)integer::sub(m.r32((s.cx+0x000000bcu)),s.ax,32,flags);
  }
  L004eba70: { // 0x4eba70: 7510 JNZ 0x4eba82
    if(integer::condition("JNZ",flags)) goto L004eba82;
  }
  L004eba72: { // 0x4eba72: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004eba77: { // 0x4eba77: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eba79: { // 0x4eba79: 7407 JZ 0x4eba82
    if(integer::condition("JZ",flags)) goto L004eba82;
  }
  L004eba7b: { // 0x4eba7b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eba7c: { // 0x4eba7c: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004eba7e: { // 0x4eba7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eba7f: { // 0x4eba7f: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004eba82: { // 0x4eba82: a1d8a5a100 MOV EAX, dword ptr [0xa1a5d8]
    s.ax = m.r32((0x00a1a5d8u));
  }
  L004eba87: { // 0x4eba87: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004eba88: { // 0x4eba88: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004eba8a: { // 0x4eba8a: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004eba8c: { // 0x4eba8c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eba8e: { // 0x4eba8e: 7e5f JLE 0x4ebaef
    if(integer::condition("JLE",flags)) goto L004ebaef;
  }
  L004eba90: { // 0x4eba90: 8b15cca5a100 MOV EDX, dword ptr [0xa1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  L004eba96: { // 0x4eba96: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004eba97: { // 0x4eba97: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L004eba99: { // 0x4eba99: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004eba9b: { // 0x4eba9b: 8a883d010000 MOV CL, byte ptr [EAX + 0x13d]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000013du)));
  }
  L004ebaa1: { // 0x4ebaa1: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ebaa3: { // 0x4ebaa3: 7543 JNZ 0x4ebae8
    if(integer::condition("JNZ",flags)) goto L004ebae8;
  }
  L004ebaa5: { // 0x4ebaa5: 8b4834 MOV ECX, dword ptr [EAX + 0x34]
    s.cx = m.r32((s.ax+0x00000034u));
  }
  L004ebaa8: { // 0x4ebaa8: 80b9a601000000 CMP byte ptr [ECX + 0x1a6], 0
    (void)integer::sub(m.r8((s.cx+0x000001a6u)),0u,8,flags);
  }
  L004ebaaf: { // 0x4ebaaf: 7537 JNZ 0x4ebae8
    if(integer::condition("JNZ",flags)) goto L004ebae8;
  }
  L004ebab1: { // 0x4ebab1: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004ebab2: { // 0x4ebab2: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ebab4: { // 0x4ebab4: 7432 JZ 0x4ebae8
    if(integer::condition("JZ",flags)) goto L004ebae8;
  }
  L004ebab6: { // 0x4ebab6: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004ebab8: { // 0x4ebab8: 742d JZ 0x4ebae7
    if(integer::condition("JZ",flags)) goto L004ebae7;
  }
  L004ebaba: { // 0x4ebaba: 8b4030 MOV EAX, dword ptr [EAX + 0x30]
    s.ax = m.r32((s.ax+0x00000030u));
  }
  L004ebabd: { // 0x4ebabd: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004ebac0: { // 0x4ebac0: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004ebac2: { // 0x4ebac2: 7423 JZ 0x4ebae7
    if(integer::condition("JZ",flags)) goto L004ebae7;
  }
  L004ebac4: { // 0x4ebac4: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L004ebac7: { // 0x4ebac7: 741f JZ 0x4ebae8
    if(integer::condition("JZ",flags)) goto L004ebae8;
  }
  L004ebac9: { // 0x4ebac9: b901000000 MOV ECX, 1
    s.cx = 1u;
  }
  L004ebace: { // 0x4ebace: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004ebad2: { // 0x4ebad2: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004ebad4: { // 0x4ebad4: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004ebad8: { // 0x4ebad8: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004ebada: { // 0x4ebada: 858674560000 TEST dword ptr [ESI + 0x5674], EAX
    (void)integer::logical((m.r32((s.si+0x00005674u)))&(s.ax),32,flags);
  }
  L004ebae0: { // 0x4ebae0: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004ebae3: { // 0x4ebae3: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ebae5: { // 0x4ebae5: 7401 JZ 0x4ebae8
    if(integer::condition("JZ",flags)) goto L004ebae8;
  }
  L004ebae7: { // 0x4ebae7: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L004ebae8: { // 0x4ebae8: 83c204 ADD EDX, 4
    s.dx = integer::add(s.dx,4u,32,flags);
  }
  L004ebaeb: { // 0x4ebaeb: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L004ebaec: { // 0x4ebaec: 75ab JNZ 0x4eba99
    if(integer::condition("JNZ",flags)) goto L004eba99;
  }
  L004ebaee: { // 0x4ebaee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ebaef: { // 0x4ebaef: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L004ebaf0: { // 0x4ebaf0: 3bfd CMP EDI, EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L004ebaf2: { // 0x4ebaf2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ebaf3: { // 0x4ebaf3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ebaf4: { // 0x4ebaf4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ebaf5: { // 0x4ebaf5: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004ebaf8: { // 0x4ebaf8: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}



} // namespace
namespace {
void f_000f2920(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f2920: { // 0x4f2920: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004f2921: { // 0x4f2921: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f2922: { // 0x4f2922: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L004f2924: { // 0x4f2924: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f2925: { // 0x4f2925: b904420000 MOV ECX,0x4204
    s.cx = 0x00004204u;
  }
  L004f292a: { // 0x4f292a: 8dbbd0560000 LEA EDI,[EBX + 0x56d0]
    s.di = (s.bx+0x000056d0u);
  }
  L004f2930: { // 0x4f2930: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f2932: { // 0x4f2932: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L004f2934: { // 0x4f2934: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L004f2939: { // 0x4f2939: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004f293a: { // 0x4f293a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f293c: { // 0x4f293c: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004f2940: { // 0x4f2940: 0f8c9b010000 JL 0x004f2ae1
    if(integer::condition("JL",flags)) goto L004f2ae1;
  }
  L004f2946: { // 0x4f2946: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f2947: { // 0x4f2947: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f2948: { // 0x4f2948: 8b0d6488a200 MOV ECX,dword ptr [0x00a28864]
    s.cx = m.r32((0x00a28864u));
  }
  L004f294e: { // 0x4f294e: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004f2951: { // 0x4f2951: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L004f2954: { // 0x4f2954: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f2956: { // 0x4f2956: 0f8574010000 JNZ 0x004f2ad0
    if(integer::condition("JNZ",flags)) goto L004f2ad0;
  }
  L004f295c: { // 0x4f295c: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L004f295f: { // 0x4f295f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f2961: { // 0x4f2961: 0f8469010000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f2967: { // 0x4f2967: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f2969: { // 0x4f2969: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f296b: { // 0x4f296b: ff92a0020000 CALL dword ptr [EDX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002a0u)),5187953u); flags=s.arithmetic_flags;
  }
  L004f2971: { // 0x4f2971: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004f2973: { // 0x4f2973: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004f2975: { // 0x4f2975: 0f8e55010000 JLE 0x004f2ad0
    if(integer::condition("JLE",flags)) goto L004f2ad0;
  }
  L004f297b: { // 0x4f297b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004f297d: { // 0x4f297d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f297f: { // 0x4f297f: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5187970u); flags=s.arithmetic_flags;
  }
  L004f2982: { // 0x4f2982: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L004f2985: { // 0x4f2985: 741c JZ 0x004f29a3
    if(integer::condition("JZ",flags)) goto L004f29a3;
  }
  L004f2987: { // 0x4f2987: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f2989: { // 0x4f2989: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f298b: { // 0x4f298b: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5187982u); flags=s.arithmetic_flags;
  }
  L004f298e: { // 0x4f298e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L004f2991: { // 0x4f2991: 7410 JZ 0x004f29a3
    if(integer::condition("JZ",flags)) goto L004f29a3;
  }
  L004f2993: { // 0x4f2993: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004f2995: { // 0x4f2995: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f2997: { // 0x4f2997: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5187994u); flags=s.arithmetic_flags;
  }
  L004f299a: { // 0x4f299a: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L004f299d: { // 0x4f299d: 0f85e0000000 JNZ 0x004f2a83
    if(integer::condition("JNZ",flags)) goto L004f2a83;
  }
  L004f29a3: { // 0x4f29a3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f29a5: { // 0x4f29a5: 0f84d8000000 JZ 0x004f2a83
    if(integer::condition("JZ",flags)) goto L004f2a83;
  }
  L004f29ab: { // 0x4f29ab: 668b8e54040000 MOV CX,word ptr [ESI + 0x454]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000454u)));
  }
  L004f29b2: { // 0x4f29b2: 8d8654040000 LEA EAX,[ESI + 0x454]
    s.ax = (s.si+0x00000454u);
  }
  L004f29b8: { // 0x4f29b8: 663b0d5c8ba200 CMP CX,word ptr [0x00a28b5c]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a28b5cu)),16,flags);
  }
  L004f29bf: { // 0x4f29bf: 7511 JNZ 0x004f29d2
    if(integer::condition("JNZ",flags)) goto L004f29d2;
  }
  L004f29c1: { // 0x4f29c1: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L004f29c5: { // 0x4f29c5: 663b155e8ba200 CMP DX,word ptr [0x00a28b5e]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a28b5eu)),16,flags);
  }
  L004f29cc: { // 0x4f29cc: 0f84fe000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f29d2: { // 0x4f29d2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f29d3: { // 0x4f29d3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004f29d8: { // 0x4f29d8: e8238e0500 CALL 0x0054b800
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054b800u,5188061u); flags=s.arithmetic_flags;
  }
  L004f29dd: { // 0x4f29dd: 8bb6b4010000 MOV ESI,dword ptr [ESI + 0x1b4]
    s.si = m.r32((s.si+0x000001b4u));
  }
  L004f29e3: { // 0x4f29e3: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004f29e5: { // 0x4f29e5: 0f84e5000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f29eb: { // 0x4f29eb: 8b0dc855a200 MOV ECX,dword ptr [0x00a255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L004f29f1: { // 0x4f29f1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004f29f3: { // 0x4f29f3: 8a8b34010000 MOV CL,byte ptr [EBX + 0x134]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000134u)));
  }
  L004f29f9: { // 0x4f29f9: 7514 JNZ 0x004f2a0f
    if(integer::condition("JNZ",flags)) goto L004f2a0f;
  }
  L004f29fb: { // 0x4f29fb: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f29fd: { // 0x4f29fd: 750e JNZ 0x004f2a0d
    if(integer::condition("JNZ",flags)) goto L004f2a0d;
  }
  L004f29ff: { // 0x4f29ff: 8a8b35010000 MOV CL,byte ptr [EBX + 0x135]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000135u)));
  }
  L004f2a05: { // 0x4f2a05: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f2a07: { // 0x4f2a07: 7504 JNZ 0x004f2a0d
    if(integer::condition("JNZ",flags)) goto L004f2a0d;
  }
  L004f2a09: { // 0x4f2a09: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L004f2a0b: { // 0x4f2a0b: eb02 JMP 0x004f2a0f
    goto L004f2a0f;
  }
  L004f2a0d: { // 0x4f2a0d: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L004f2a0f: { // 0x4f2a0f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f2a11: { // 0x4f2a11: 7439 JZ 0x004f2a4c
    if(integer::condition("JZ",flags)) goto L004f2a4c;
  }
  L004f2a13: { // 0x4f2a13: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f2a15: { // 0x4f2a15: 7435 JZ 0x004f2a4c
    if(integer::condition("JZ",flags)) goto L004f2a4c;
  }
  L004f2a17: { // 0x4f2a17: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004f2a19: { // 0x4f2a19: 0f84b1000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f2a1f: { // 0x4f2a1f: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004f2a22: { // 0x4f2a22: 8b5330 MOV EDX,dword ptr [EBX + 0x30]
    s.dx = m.r32((s.bx+0x00000030u));
  }
  L004f2a25: { // 0x4f2a25: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f2a27: { // 0x4f2a27: 0f84a3000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f2a2d: { // 0x4f2a2d: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004f2a30: { // 0x4f2a30: 741a JZ 0x004f2a4c
    if(integer::condition("JZ",flags)) goto L004f2a4c;
  }
  L004f2a32: { // 0x4f2a32: 8bb374560000 MOV ESI,dword ptr [EBX + 0x5674]
    s.si = m.r32((s.bx+0x00005674u));
  }
  L004f2a38: { // 0x4f2a38: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004f2a3d: { // 0x4f2a3d: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004f2a3f: { // 0x4f2a3f: 85f2 TEST EDX,ESI
    (void)integer::logical((s.dx)&(s.si),32,flags);
  }
  L004f2a41: { // 0x4f2a41: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004f2a44: { // 0x4f2a44: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f2a46: { // 0x4f2a46: 0f8584000000 JNZ 0x004f2ad0
    if(integer::condition("JNZ",flags)) goto L004f2ad0;
  }
  L004f2a4c: { // 0x4f2a4c: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f2a4e: { // 0x4f2a4e: bf09000000 MOV EDI,0x9
    s.di = 0x00000009u;
  }
  L004f2a53: { // 0x4f2a53: 8b8e64507c00 MOV ECX,dword ptr [ESI + 0x7c5064]
    s.cx = m.r32((s.si+0x007c5064u));
  }
  L004f2a59: { // 0x4f2a59: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L004f2a5b: { // 0x4f2a5b: d3fa SAR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L004f2a5d: { // 0x4f2a5d: 8b8e40507c00 MOV ECX,dword ptr [ESI + 0x7c5040]
    s.cx = m.r32((s.si+0x007c5040u));
  }
  L004f2a63: { // 0x4f2a63: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004f2a65: { // 0x4f2a65: 01948bd0560000 ADD dword ptr [EBX + ECX*0x4 + 0x56d0],EDX
    m.w32((s.bx+(s.cx * 0x00000004u)+0x000056d0u), integer::add(m.r32((s.bx+(s.cx * 0x00000004u)+0x000056d0u)),s.dx,32,flags));
  }
  L004f2a6c: { // 0x4f2a6c: 8d8c8bd0560000 LEA ECX,[EBX + ECX*0x4 + 0x56d0]
    s.cx = (s.bx+(s.cx * 0x00000004u)+0x000056d0u);
  }
  L004f2a73: { // 0x4f2a73: 7906 JNS 0x004f2a7b
    if(integer::condition("JNS",flags)) goto L004f2a7b;
  }
  L004f2a75: { // 0x4f2a75: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L004f2a7b: { // 0x4f2a7b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004f2a7e: { // 0x4f2a7e: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L004f2a7f: { // 0x4f2a7f: 75d2 JNZ 0x004f2a53
    if(integer::condition("JNZ",flags)) goto L004f2a53;
  }
  L004f2a81: { // 0x4f2a81: eb4d JMP 0x004f2ad0
    goto L004f2ad0;
  }
  L004f2a83: { // 0x4f2a83: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f2a85: { // 0x4f2a85: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f2a87: { // 0x4f2a87: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),5188237u); flags=s.arithmetic_flags;
  }
  L004f2a8d: { // 0x4f2a8d: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L004f2a90: { // 0x4f2a90: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004f2a95: { // 0x4f2a95: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f2a96: { // 0x4f2a96: e8658d0500 CALL 0x0054b800
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054b800u,5188251u); flags=s.arithmetic_flags;
  }
  L004f2a9b: { // 0x4f2a9b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f2a9d: { // 0x4f2a9d: bf09000000 MOV EDI,0x9
    s.di = 0x00000009u;
  }
  L004f2aa2: { // 0x4f2aa2: 8b8e64507c00 MOV ECX,dword ptr [ESI + 0x7c5064]
    s.cx = m.r32((s.si+0x007c5064u));
  }
  L004f2aa8: { // 0x4f2aa8: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L004f2aaa: { // 0x4f2aaa: d3fa SAR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L004f2aac: { // 0x4f2aac: 8b8e40507c00 MOV ECX,dword ptr [ESI + 0x7c5040]
    s.cx = m.r32((s.si+0x007c5040u));
  }
  L004f2ab2: { // 0x4f2ab2: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004f2ab4: { // 0x4f2ab4: 01948bd0560000 ADD dword ptr [EBX + ECX*0x4 + 0x56d0],EDX
    m.w32((s.bx+(s.cx * 0x00000004u)+0x000056d0u), integer::add(m.r32((s.bx+(s.cx * 0x00000004u)+0x000056d0u)),s.dx,32,flags));
  }
  L004f2abb: { // 0x4f2abb: 8d8c8bd0560000 LEA ECX,[EBX + ECX*0x4 + 0x56d0]
    s.cx = (s.bx+(s.cx * 0x00000004u)+0x000056d0u);
  }
  L004f2ac2: { // 0x4f2ac2: 7906 JNS 0x004f2aca
    if(integer::condition("JNS",flags)) goto L004f2aca;
  }
  L004f2ac4: { // 0x4f2ac4: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L004f2aca: { // 0x4f2aca: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004f2acd: { // 0x4f2acd: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L004f2ace: { // 0x4f2ace: 75d2 JNZ 0x004f2aa2
    if(integer::condition("JNZ",flags)) goto L004f2aa2;
  }
  L004f2ad0: { // 0x4f2ad0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004f2ad4: { // 0x4f2ad4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004f2ad5: { // 0x4f2ad5: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004f2ad9: { // 0x4f2ad9: 0f8969feffff JNS 0x004f2948
    if(integer::condition("JNS",flags)) goto L004f2948;
  }
  L004f2adf: { // 0x4f2adf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f2ae0: { // 0x4f2ae0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f2ae1: { // 0x4f2ae1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f2ae2: { // 0x4f2ae2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f2ae3: { // 0x4f2ae3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004f2ae4: { // 0x4f2ae4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e4d00(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4d00: { // 0x4e4d00: 81eca8000000 SUB ESP, 0xa8
    f.sp = integer::sub(f.sp,0x000000a8u,32,flags);
  }
  L004e4d06: { // 0x4e4d06: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e4d07: { // 0x4e4d07: 8bac24b0000000 MOV EBP, dword ptr [ESP + 0xb0]
    s.bp = m.r32((f.sp+0x000000b0u));
  }
  L004e4d0e: { // 0x4e4d0e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e4d0f: { // 0x4e4d0f: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004e4d11: { // 0x4e4d11: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e4d12: { // 0x4e4d12: e8e96c0000 CALL 0x4eba00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eba00u,5131543u); flags=s.arithmetic_flags;
  }
  L004e4d17: { // 0x4e4d17: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4d19: { // 0x4e4d19: 0f84c4030000 JZ 0x4e50e3
    if(integer::condition("JZ",flags)) goto L004e50e3;
  }
  L004e4d1f: { // 0x4e4d1f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e4d20: { // 0x4e4d20: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e4d21: { // 0x4e4d21: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4d23: { // 0x4e4d23: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4d25: { // 0x4e4d25: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e4d2a: { // 0x4e4d2a: e80190fbff CALL 0x49dd30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dd30u,5131567u); flags=s.arithmetic_flags;
  }
  L004e4d2f: { // 0x4e4d2f: 8b4d30 MOV ECX, dword ptr [EBP + 0x30]
    s.cx = m.r32((s.bp+0x00000030u));
  }
  L004e4d32: { // 0x4e4d32: 8bbe74560000 MOV EDI, dword ptr [ESI + 0x5674]
    s.di = m.r32((s.si+0x00005674u));
  }
  L004e4d38: { // 0x4e4d38: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e4d3d: { // 0x4e4d3d: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4d3f: { // 0x4e4d3f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e4d41: { // 0x4e4d41: 0bf8 OR EDI, EAX
    s.di = integer::logical((s.di)|(s.ax),32,flags);
  }
  L004e4d43: { // 0x4e4d43: 89be74560000 MOV dword ptr [ESI + 0x5674], EDI
    m.w32((s.si+0x00005674u), s.di);
  }
  L004e4d49: { // 0x4e4d49: e8d2db0000 CALL 0x4f2920
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2920u,5131598u); flags=s.arithmetic_flags;
  }
  L004e4d4e: { // 0x4e4d4e: 8b8e04550000 MOV ECX, dword ptr [ESI + 0x5504]
    s.cx = m.r32((s.si+0x00005504u));
  }
  L004e4d54: { // 0x4e4d54: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e4d56: { // 0x4e4d56: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4d58: { // 0x4e4d58: 7e25 JLE 0x4e4d7f
    if(integer::condition("JLE",flags)) goto L004e4d7f;
  }
  L004e4d5a: { // 0x4e4d5a: 8bbef8540000 MOV EDI, dword ptr [ESI + 0x54f8]
    s.di = m.r32((s.si+0x000054f8u));
  }
  L004e4d60: { // 0x4e4d60: 8bd7 MOV EDX, EDI
    s.dx = s.di;
  }
  L004e4d62: { // 0x4e4d62: 392a CMP dword ptr [EDX], EBP
    (void)integer::sub(m.r32((s.dx)),s.bp,32,flags);
  }
  L004e4d64: { // 0x4e4d64: 740a JZ 0x4e4d70
    if(integer::condition("JZ",flags)) goto L004e4d70;
  }
  L004e4d66: { // 0x4e4d66: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004e4d67: { // 0x4e4d67: 83c208 ADD EDX, 8
    s.dx = integer::add(s.dx,8u,32,flags);
  }
  L004e4d6a: { // 0x4e4d6a: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004e4d6c: { // 0x4e4d6c: 7cf4 JL 0x4e4d62
    if(integer::condition("JL",flags)) goto L004e4d62;
  }
  L004e4d6e: { // 0x4e4d6e: eb0f JMP 0x4e4d7f
    goto L004e4d7f;
  }
  L004e4d70: { // 0x4e4d70: 8b4cc704 MOV ECX, dword ptr [EDI + EAX*8 + 4]
    s.cx = m.r32((s.di+(s.ax * 8u)+4u));
  }
  L004e4d74: { // 0x4e4d74: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e4d75: { // 0x4e4d75: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L004e4d77: { // 0x4e4d77: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e4d78: { // 0x4e4d78: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e4d7a: { // 0x4e4d7a: e821930000 CALL 0x4ee0a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ee0a0u,5131647u); flags=s.arithmetic_flags;
  }
  L004e4d7f: { // 0x4e4d7f: 8b96f0540000 MOV EDX, dword ptr [ESI + 0x54f0]
    s.dx = m.r32((s.si+0x000054f0u));
  }
  L004e4d85: { // 0x4e4d85: 8b4530 MOV EAX, dword ptr [EBP + 0x30]
    s.ax = m.r32((s.bp+0x00000030u));
  }
  L004e4d88: { // 0x4e4d88: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004e4d8a: { // 0x4e4d8a: 750a JNZ 0x4e4d96
    if(integer::condition("JNZ",flags)) goto L004e4d96;
  }
  L004e4d8c: { // 0x4e4d8c: c786f0540000ffffffff MOV dword ptr [ESI + 0x54f0], 0xffffffff
    m.w32((s.si+0x000054f0u), 0xffffffffu);
  }
  L004e4d96: { // 0x4e4d96: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e4d9b: { // 0x4e4d9b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4d9d: { // 0x4e4d9d: 7410 JZ 0x4e4daf
    if(integer::condition("JZ",flags)) goto L004e4daf;
  }
  L004e4d9f: { // 0x4e4d9f: 8b4d30 MOV ECX, dword ptr [EBP + 0x30]
    s.cx = m.r32((s.bp+0x00000030u));
  }
  L004e4da2: { // 0x4e4da2: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e4da7: { // 0x4e4da7: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4da9: { // 0x4e4da9: 098620010000 OR dword ptr [ESI + 0x120], EAX
    m.w32((s.si+0x00000120u), integer::logical((m.r32((s.si+0x00000120u)))|(s.ax),32,flags));
  }
  L004e4daf: { // 0x4e4daf: 8b0dc855a200 MOV ECX, dword ptr [0xa255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L004e4db5: { // 0x4e4db5: 83f904 CMP ECX, 4
    (void)integer::sub(s.cx,4u,32,flags);
  }
  L004e4db8: { // 0x4e4db8: 740d JZ 0x4e4dc7
    if(integer::condition("JZ",flags)) goto L004e4dc7;
  }
  L004e4dba: { // 0x4e4dba: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e4dbf: { // 0x4e4dbf: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4dc1: { // 0x4e4dc1: 0f850c030000 JNZ 0x4e50d3
    if(integer::condition("JNZ",flags)) goto L004e50d3;
  }
  L004e4dc7: { // 0x4e4dc7: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e4dcd: { // 0x4e4dcd: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4dcf: { // 0x4e4dcf: 7514 JNZ 0x4e4de5
    if(integer::condition("JNZ",flags)) goto L004e4de5;
  }
  L004e4dd1: { // 0x4e4dd1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4dd3: { // 0x4e4dd3: 750e JNZ 0x4e4de3
    if(integer::condition("JNZ",flags)) goto L004e4de3;
  }
  L004e4dd5: { // 0x4e4dd5: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e4ddb: { // 0x4e4ddb: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4ddd: { // 0x4e4ddd: 7504 JNZ 0x4e4de3
    if(integer::condition("JNZ",flags)) goto L004e4de3;
  }
  L004e4ddf: { // 0x4e4ddf: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4de1: { // 0x4e4de1: eb02 JMP 0x4e4de5
    goto L004e4de5;
  }
  L004e4de3: { // 0x4e4de3: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4de5: { // 0x4e4de5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4de7: { // 0x4e4de7: 7426 JZ 0x4e4e0f
    if(integer::condition("JZ",flags)) goto L004e4e0f;
  }
  L004e4de9: { // 0x4e4de9: 8b15881b8200 MOV EDX, dword ptr [0x821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L004e4def: { // 0x4e4def: 8a8224140000 MOV AL, byte ptr [EDX + 0x1424]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001424u)));
  }
  L004e4df5: { // 0x4e4df5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4df7: { // 0x4e4df7: 7416 JZ 0x4e4e0f
    if(integer::condition("JZ",flags)) goto L004e4e0f;
  }
  L004e4df9: { // 0x4e4df9: 8b4534 MOV EAX, dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L004e4dfc: { // 0x4e4dfc: 8a90a6010000 MOV DL, byte ptr [EAX + 0x1a6]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000001a6u)));
  }
  L004e4e02: { // 0x4e4e02: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004e4e04: { // 0x4e4e04: 7509 JNZ 0x4e4e0f
    if(integer::condition("JNZ",flags)) goto L004e4e0f;
  }
  L004e4e06: { // 0x4e4e06: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4e08: { // 0x4e4e08: 7405 JZ 0x4e4e0f
    if(integer::condition("JZ",flags)) goto L004e4e0f;
  }
  L004e4e0a: { // 0x4e4e0a: e8f16c0000 CALL 0x4ebb00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ebb00u,5131791u); flags=s.arithmetic_flags;
  }
  L004e4e0f: { // 0x4e4e0f: a1c0a78100 MOV EAX, dword ptr [0x81a7c0]
    s.ax = m.r32((0x0081a7c0u));
  }
  L004e4e14: { // 0x4e4e14: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004e4e16: { // 0x4e4e16: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e18: { // 0x4e4e18: 0f8ebd000000 JLE 0x4e4edb
    if(integer::condition("JLE",flags)) goto L004e4edb;
  }
  L004e4e1e: { // 0x4e4e1e: 8b0db4a78100 MOV ECX, dword ptr [0x81a7b4]
    s.cx = m.r32((0x0081a7b4u));
  }
  L004e4e24: { // 0x4e4e24: 8b3c99 MOV EDI, dword ptr [ECX + EBX*4]
    s.di = m.r32((s.cx+(s.bx * 4u)));
  }
  L004e4e27: { // 0x4e4e27: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e4e29: { // 0x4e4e29: 0f849e000000 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e2f: { // 0x4e4e2f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e4e31: { // 0x4e4e31: e8ea8df2ff CALL 0x40dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,5131830u); flags=s.arithmetic_flags;
  }
  L004e4e36: { // 0x4e4e36: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e38: { // 0x4e4e38: 0f848f000000 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e3e: { // 0x4e4e3e: 8a4776 MOV AL, byte ptr [EDI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000076u)));
  }
  L004e4e41: { // 0x4e4e41: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4e43: { // 0x4e4e43: 0f8584000000 JNZ 0x4e4ecd
    if(integer::condition("JNZ",flags)) goto L004e4ecd;
  }
  L004e4e49: { // 0x4e4e49: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004e4e4b: { // 0x4e4e4b: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e4e4d: { // 0x4e4e4d: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),5131856u); flags=s.arithmetic_flags;
  }
  L004e4e50: { // 0x4e4e50: 3b4630 CMP EAX, dword ptr [ESI + 0x30]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000030u)),32,flags);
  }
  L004e4e53: { // 0x4e4e53: 7578 JNZ 0x4e4ecd
    if(integer::condition("JNZ",flags)) goto L004e4ecd;
  }
  L004e4e55: { // 0x4e4e55: 8b8728020000 MOV EAX, dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L004e4e5b: { // 0x4e4e5b: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004e4e5f: { // 0x4e4e5f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4e60: { // 0x4e4e60: e88b5c1c00 CALL 0x6aaaf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaaf0u,5131877u); flags=s.arithmetic_flags;
  }
  L004e4e65: { // 0x4e4e65: 8a442414 MOV AL, byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L004e4e69: { // 0x4e4e69: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4e6b: { // 0x4e4e6b: 7460 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e6d: { // 0x4e4e6d: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004e4e71: { // 0x4e4e71: e8ea601c00 CALL 0x6aaf60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaf60u,5131894u); flags=s.arithmetic_flags;
  }
  L004e4e76: { // 0x4e4e76: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e78: { // 0x4e4e78: 7453 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e7a: { // 0x4e4e7a: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004e4e7e: { // 0x4e4e7e: e8dd601c00 CALL 0x6aaf60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaf60u,5131907u); flags=s.arithmetic_flags;
  }
  L004e4e83: { // 0x4e4e83: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e85: { // 0x4e4e85: 7446 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e87: { // 0x4e4e87: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004e4e89: { // 0x4e4e89: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004e4e8b: { // 0x4e4e8b: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),5131918u); flags=s.arithmetic_flags;
  }
  L004e4e8e: { // 0x4e4e8e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e90: { // 0x4e4e90: 743b JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e92: { // 0x4e4e92: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004e4e94: { // 0x4e4e94: 742b JZ 0x4e4ec1
    if(integer::condition("JZ",flags)) goto L004e4ec1;
  }
  L004e4e96: { // 0x4e4e96: 8b4830 MOV ECX, dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L004e4e99: { // 0x4e4e99: 8b4630 MOV EAX, dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004e4e9c: { // 0x4e4e9c: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e4e9e: { // 0x4e4e9e: 7504 JNZ 0x4e4ea4
    if(integer::condition("JNZ",flags)) goto L004e4ea4;
  }
  L004e4ea0: { // 0x4e4ea0: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4ea2: { // 0x4e4ea2: eb19 JMP 0x4e4ebd
    goto L004e4ebd;
  }
  L004e4ea4: { // 0x4e4ea4: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e4ea7: { // 0x4e4ea7: 7412 JZ 0x4e4ebb
    if(integer::condition("JZ",flags)) goto L004e4ebb;
  }
  L004e4ea9: { // 0x4e4ea9: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e4eae: { // 0x4e4eae: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4eb0: { // 0x4e4eb0: 858674560000 TEST dword ptr [ESI + 0x5674], EAX
    (void)integer::logical((m.r32((s.si+0x00005674u)))&(s.ax),32,flags);
  }
  L004e4eb6: { // 0x4e4eb6: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e4eb9: { // 0x4e4eb9: eb02 JMP 0x4e4ebd
    goto L004e4ebd;
  }
  L004e4ebb: { // 0x4e4ebb: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4ebd: { // 0x4e4ebd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4ebf: { // 0x4e4ebf: 740c JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4ec1: { // 0x4e4ec1: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004e4ec3: { // 0x4e4ec3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4ec5: { // 0x4e4ec5: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e4ec7: { // 0x4e4ec7: ff9270030000 CALL dword ptr [EDX + 0x370]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000370u)),5131981u); flags=s.arithmetic_flags;
  }
  L004e4ecd: { // 0x4e4ecd: a1c0a78100 MOV EAX, dword ptr [0x81a7c0]
    s.ax = m.r32((0x0081a7c0u));
  }
  L004e4ed2: { // 0x4e4ed2: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004e4ed3: { // 0x4e4ed3: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004e4ed5: { // 0x4e4ed5: 0f8c43ffffff JL 0x4e4e1e
    if(integer::condition("JL",flags)) goto L004e4e1e;
  }
  L004e4edb: { // 0x4e4edb: 8b0dc855a200 MOV ECX, dword ptr [0xa255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L004e4ee1: { // 0x4e4ee1: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e4ee7: { // 0x4e4ee7: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4ee9: { // 0x4e4ee9: 7514 JNZ 0x4e4eff
    if(integer::condition("JNZ",flags)) goto L004e4eff;
  }
  L004e4eeb: { // 0x4e4eeb: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4eed: { // 0x4e4eed: 750e JNZ 0x4e4efd
    if(integer::condition("JNZ",flags)) goto L004e4efd;
  }
  L004e4eef: { // 0x4e4eef: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e4ef5: { // 0x4e4ef5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4ef7: { // 0x4e4ef7: 7504 JNZ 0x4e4efd
    if(integer::condition("JNZ",flags)) goto L004e4efd;
  }
  L004e4ef9: { // 0x4e4ef9: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4efb: { // 0x4e4efb: eb02 JMP 0x4e4eff
    goto L004e4eff;
  }
  L004e4efd: { // 0x4e4efd: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4eff: { // 0x4e4eff: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4f01: { // 0x4e4f01: 0f84c0010000 JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e4f07: { // 0x4e4f07: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4f09: { // 0x4e4f09: 0f84b8010000 JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e4f0f: { // 0x4e4f0f: 8b4534 MOV EAX, dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L004e4f12: { // 0x4e4f12: 8a88a6010000 MOV CL, byte ptr [EAX + 0x1a6]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000001a6u)));
  }
  L004e4f18: { // 0x4e4f18: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e4f1a: { // 0x4e4f1a: 0f85a7010000 JNZ 0x4e50c7
    if(integer::condition("JNZ",flags)) goto L004e50c7;
  }
  L004e4f20: { // 0x4e4f20: 8d8d165f0100 LEA ECX, [EBP + 0x15f16]
    s.cx = (s.bp+0x00015f16u);
  }
  L004e4f26: { // 0x4e4f26: 8d96165f0100 LEA EDX, [ESI + 0x15f16]
    s.dx = (s.si+0x00015f16u);
  }
  L004e4f2c: { // 0x4e4f2c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e4f2d: { // 0x4e4f2d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e4f2e: { // 0x4e4f2e: 68250c0000 PUSH 0xc25
    f.push(m,0x00000c25u);
  }
  L004e4f33: { // 0x4e4f33: 6804537c00 PUSH 0x7c5304
    f.push(m,0x007c5304u);
  }
  L004e4f38: { // 0x4e4f38: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004e4f3a: { // 0x4e4f3a: b9bc537c00 MOV ECX, 0x7c53bc
    s.cx = 0x007c53bcu;
  }
  L004e4f3f: { // 0x4e4f3f: e81c9c2000 CALL 0x6eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,5132100u); flags=s.arithmetic_flags;
  }
  L004e4f44: { // 0x4e4f44: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f45: { // 0x4e4f45: 8d442424 LEA EAX, [ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L004e4f49: { // 0x4e4f49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f4a: { // 0x4e4f4a: e855a12800 CALL 0x76f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,5132111u); flags=s.arithmetic_flags;
  }
  L004e4f4f: { // 0x4e4f4f: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004e4f55: { // 0x4e4f55: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e4f58: { // 0x4e4f58: dd8128110000 FLD qword ptr [ECX + 0x1128]
    const auto address=(s.cx+0x00001128u);
    s.fp.load64(read64(m,address));
  }
  L004e4f5e: { // 0x4e4f5e: dc0d08667800 FMUL qword ptr [0x786608]
    const auto address=(0x00786608u);
    s.fp.multiply64(read64(m,address));
  }
  L004e4f64: { // 0x4e4f64: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4f66: { // 0x4e4f66: e8e55a2800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5132139u); flags=s.arithmetic_flags;
  }
  L004e4f6b: { // 0x4e4f6b: 8b5634 MOV EDX, dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004e4f6e: { // 0x4e4f6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f6f: { // 0x4e4f6f: 6846400000 PUSH 0x4046
    f.push(m,0x00004046u);
  }
  L004e4f74: { // 0x4e4f74: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L004e4f78: { // 0x4e4f78: 8b82c0000000 MOV EAX, dword ptr [EDX + 0xc0]
    s.ax = m.r32((s.dx+0x000000c0u));
  }
  L004e4f7e: { // 0x4e4f7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f7f: { // 0x4e4f7f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e4f80: { // 0x4e4f80: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4f82: { // 0x4e4f82: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4f84: { // 0x4e4f84: b9a05fa200 MOV ECX, 0xa25fa0
    s.cx = 0x00a25fa0u;
  }
  L004e4f89: { // 0x4e4f89: e8f2c90c00 CALL 0x5b1980
    s.arithmetic_flags=flags; invoke(m,s,f,0x005b1980u,5132174u); flags=s.arithmetic_flags;
  }
  L004e4f8e: { // 0x4e4f8e: 8a8424c0000000 MOV AL, byte ptr [ESP + 0xc0]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000000c0u)));
  }
  L004e4f95: { // 0x4e4f95: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4f97: { // 0x4e4f97: 0f842a010000 JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e4f9d: { // 0x4e4f9d: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004e4f9f: { // 0x4e4f9f: 0f84b1000000 JZ 0x4e5056
    if(integer::condition("JZ",flags)) goto L004e5056;
  }
  L004e4fa5: { // 0x4e4fa5: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L004e4fa7: { // 0x4e4fa7: 742d JZ 0x4e4fd6
    if(integer::condition("JZ",flags)) goto L004e4fd6;
  }
  L004e4fa9: { // 0x4e4fa9: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e4fac: { // 0x4e4fac: 8b4530 MOV EAX, dword ptr [EBP + 0x30]
    s.ax = m.r32((s.bp+0x00000030u));
  }
  L004e4faf: { // 0x4e4faf: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e4fb1: { // 0x4e4fb1: 7423 JZ 0x4e4fd6
    if(integer::condition("JZ",flags)) goto L004e4fd6;
  }
  L004e4fb3: { // 0x4e4fb3: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e4fb6: { // 0x4e4fb6: 0f849a000000 JZ 0x4e5056
    if(integer::condition("JZ",flags)) goto L004e5056;
  }
  L004e4fbc: { // 0x4e4fbc: 8bbd74560000 MOV EDI, dword ptr [EBP + 0x5674]
    s.di = m.r32((s.bp+0x00005674u));
  }
  L004e4fc2: { // 0x4e4fc2: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e4fc7: { // 0x4e4fc7: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4fc9: { // 0x4e4fc9: 85fa TEST EDX, EDI
    (void)integer::logical((s.dx)&(s.di),32,flags);
  }
  L004e4fcb: { // 0x4e4fcb: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e4fce: { // 0x4e4fce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4fd0: { // 0x4e4fd0: 0f8480000000 JZ 0x4e5056
    if(integer::condition("JZ",flags)) goto L004e5056;
  }
  L004e4fd6: { // 0x4e4fd6: a17858a200 MOV EAX, dword ptr [0xa25878]
    s.ax = m.r32((0x00a25878u));
  }
  L004e4fdb: { // 0x4e4fdb: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4fdd: { // 0x4e4fdd: 0f85e4000000 JNZ 0x4e50c7
    if(integer::condition("JNZ",flags)) goto L004e50c7;
  }
  L004e4fe3: { // 0x4e4fe3: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004e4fe5: { // 0x4e4fe5: 7463 JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e4fe7: { // 0x4e4fe7: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L004e4fec: { // 0x4e4fec: 3be8 CMP EBP, EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L004e4fee: { // 0x4e4fee: 7425 JZ 0x4e5015
    if(integer::condition("JZ",flags)) goto L004e5015;
  }
  L004e4ff0: { // 0x4e4ff0: 8b4d30 MOV ECX, dword ptr [EBP + 0x30]
    s.cx = m.r32((s.bp+0x00000030u));
  }
  L004e4ff3: { // 0x4e4ff3: 8b5030 MOV EDX, dword ptr [EAX + 0x30]
    s.dx = m.r32((s.ax+0x00000030u));
  }
  L004e4ff6: { // 0x4e4ff6: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004e4ff8: { // 0x4e4ff8: 741b JZ 0x4e5015
    if(integer::condition("JZ",flags)) goto L004e5015;
  }
  L004e4ffa: { // 0x4e4ffa: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e4ffd: { // 0x4e4ffd: 744b JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e4fff: { // 0x4e4fff: 8bb874560000 MOV EDI, dword ptr [EAX + 0x5674]
    s.di = m.r32((s.ax+0x00005674u));
  }
  L004e5005: { // 0x4e5005: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e500a: { // 0x4e500a: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e500c: { // 0x4e500c: 85fa TEST EDX, EDI
    (void)integer::logical((s.dx)&(s.di),32,flags);
  }
  L004e500e: { // 0x4e500e: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e5011: { // 0x4e5011: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e5013: { // 0x4e5013: 7435 JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e5015: { // 0x4e5015: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004e5017: { // 0x4e5017: 7425 JZ 0x4e503e
    if(integer::condition("JZ",flags)) goto L004e503e;
  }
  L004e5019: { // 0x4e5019: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e501c: { // 0x4e501c: 8b5030 MOV EDX, dword ptr [EAX + 0x30]
    s.dx = m.r32((s.ax+0x00000030u));
  }
  L004e501f: { // 0x4e501f: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004e5021: { // 0x4e5021: 741b JZ 0x4e503e
    if(integer::condition("JZ",flags)) goto L004e503e;
  }
  L004e5023: { // 0x4e5023: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e5026: { // 0x4e5026: 7422 JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e5028: { // 0x4e5028: 8bb074560000 MOV ESI, dword ptr [EAX + 0x5674]
    s.si = m.r32((s.ax+0x00005674u));
  }
  L004e502e: { // 0x4e502e: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e5033: { // 0x4e5033: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e5035: { // 0x4e5035: 85f2 TEST EDX, ESI
    (void)integer::logical((s.dx)&(s.si),32,flags);
  }
  L004e5037: { // 0x4e5037: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e503a: { // 0x4e503a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e503c: { // 0x4e503c: 740c JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e503e: { // 0x4e503e: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e5040: { // 0x4e5040: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5043: { // 0x4e5043: b9a8537c00 MOV ECX, 0x7c53a8
    s.cx = 0x007c53a8u;
  }
  L004e5048: { // 0x4e5048: eb78 JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e504a: { // 0x4e504a: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e504c: { // 0x4e504c: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e504f: { // 0x4e504f: b990537c00 MOV ECX, 0x7c5390
    s.cx = 0x007c5390u;
  }
  L004e5054: { // 0x4e5054: eb6c JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e5056: { // 0x4e5056: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e505b: { // 0x4e505b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e505d: { // 0x4e505d: 7520 JNZ 0x4e507f
    if(integer::condition("JNZ",flags)) goto L004e507f;
  }
  L004e505f: { // 0x4e505f: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e5065: { // 0x4e5065: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5067: { // 0x4e5067: 7524 JNZ 0x4e508d
    if(integer::condition("JNZ",flags)) goto L004e508d;
  }
  L004e5069: { // 0x4e5069: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e506f: { // 0x4e506f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5071: { // 0x4e5071: 7426 JZ 0x4e5099
    if(integer::condition("JZ",flags)) goto L004e5099;
  }
  L004e5073: { // 0x4e5073: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e5075: { // 0x4e5075: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5078: { // 0x4e5078: b978537c00 MOV ECX, 0x7c5378
    s.cx = 0x007c5378u;
  }
  L004e507d: { // 0x4e507d: eb43 JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e507f: { // 0x4e507f: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L004e5084: { // 0x4e5084: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004e5086: { // 0x4e5086: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e5089: { // 0x4e5089: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e508b: { // 0x4e508b: 7422 JZ 0x4e50af
    if(integer::condition("JZ",flags)) goto L004e50af;
  }
  L004e508d: { // 0x4e508d: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e508f: { // 0x4e508f: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5092: { // 0x4e5092: b978537c00 MOV ECX, 0x7c5378
    s.cx = 0x007c5378u;
  }
  L004e5097: { // 0x4e5097: eb29 JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e5099: { // 0x4e5099: 8a8534010000 MOV AL, byte ptr [EBP + 0x134]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000134u)));
  }
  L004e509f: { // 0x4e509f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e50a1: { // 0x4e50a1: 7515 JNZ 0x4e50b8
    if(integer::condition("JNZ",flags)) goto L004e50b8;
  }
  L004e50a3: { // 0x4e50a3: 8a8535010000 MOV AL, byte ptr [EBP + 0x135]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000135u)));
  }
  L004e50a9: { // 0x4e50a9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e50ab: { // 0x4e50ab: 741a JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e50ad: { // 0x4e50ad: eb09 JMP 0x4e50b8
    goto L004e50b8;
  }
  L004e50af: { // 0x4e50af: 3be8 CMP EBP, EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L004e50b1: { // 0x4e50b1: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e50b4: { // 0x4e50b4: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e50b6: { // 0x4e50b6: 740f JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e50b8: { // 0x4e50b8: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e50ba: { // 0x4e50ba: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e50bd: { // 0x4e50bd: b960537c00 MOV ECX, 0x7c5360
    s.cx = 0x007c5360u;
  }
  L004e50c2: { // 0x4e50c2: e839562200 CALL 0x70a700
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a700u,5132487u); flags=s.arithmetic_flags;
  }
  L004e50c7: { // 0x4e50c7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e50c9: { // 0x4e50c9: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e50ce: { // 0x4e50ce: e85dafffff CALL 0x4e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,5132499u); flags=s.arithmetic_flags;
  }
  L004e50d3: { // 0x4e50d3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e50d5: { // 0x4e50d5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e50d7: { // 0x4e50d7: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e50dc: { // 0x4e50dc: e8bf8afbff CALL 0x49dba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dba0u,5132513u); flags=s.arithmetic_flags;
  }
  L004e50e1: { // 0x4e50e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e50e2: { // 0x4e50e2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e50e3: { // 0x4e50e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e50e4: { // 0x4e50e4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e50e5: { // 0x4e50e5: 81c4a8000000 ADD ESP, 0xa8
    f.sp = integer::add(f.sp,0x000000a8u,32,flags);
  }
  L004e50eb: { // 0x4e50eb: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000e5110(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e5110: { // 0x4e5110: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e5115: { // 0x4e5115: 81eca0000000 SUB ESP, 0xa0
    f.sp = integer::sub(f.sp,0x000000a0u,32,flags);
  }
  L004e511b: { // 0x4e511b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e511c: { // 0x4e511c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e511d: { // 0x4e511d: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L004e511f: { // 0x4e511f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e5120: { // 0x4e5120: 8bbc24b0000000 MOV EDI, dword ptr [ESP + 0xb0]
    s.di = m.r32((f.sp+0x000000b0u));
  }
  L004e5127: { // 0x4e5127: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004e5129: { // 0x4e5129: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e512b: { // 0x4e512b: 7422 JZ 0x4e514f
    if(integer::condition("JZ",flags)) goto L004e514f;
  }
  L004e512d: { // 0x4e512d: 8b4734 MOV EAX, dword ptr [EDI + 0x34]
    s.ax = m.r32((s.di+0x00000034u));
  }
  L004e5130: { // 0x4e5130: 8a88a6010000 MOV CL, byte ptr [EAX + 0x1a6]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000001a6u)));
  }
  L004e5136: { // 0x4e5136: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e5138: { // 0x4e5138: 0f852a020000 JNZ 0x4e5368
    if(integer::condition("JNZ",flags)) goto L004e5368;
  }
  L004e513e: { // 0x4e513e: 8b4e34 MOV ECX, dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  L004e5141: { // 0x4e5141: 8a81a6010000 MOV AL, byte ptr [ECX + 0x1a6]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000001a6u)));
  }
  L004e5147: { // 0x4e5147: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5149: { // 0x4e5149: 0f8519020000 JNZ 0x4e5368
    if(integer::condition("JNZ",flags)) goto L004e5368;
  }
  L004e514f: { // 0x4e514f: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e5151: { // 0x4e5151: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e5153: { // 0x4e5153: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e5158: { // 0x4e5158: e8d38bfbff CALL 0x49dd30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dd30u,5132637u); flags=s.arithmetic_flags;
  }
  L004e515d: { // 0x4e515d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e515e: { // 0x4e515e: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004e5160: { // 0x4e5160: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e5162: { // 0x4e5162: e8398f0000 CALL 0x4ee0a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ee0a0u,5132647u); flags=s.arithmetic_flags;
  }
  L004e5167: { // 0x4e5167: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e5169: { // 0x4e5169: 0f84eb010000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e516f: { // 0x4e516f: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L004e5171: { // 0x4e5171: 742d JZ 0x4e51a0
    if(integer::condition("JZ",flags)) goto L004e51a0;
  }
  L004e5173: { // 0x4e5173: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L004e5176: { // 0x4e5176: 8b4630 MOV EAX, dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004e5179: { // 0x4e5179: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e517b: { // 0x4e517b: 7423 JZ 0x4e51a0
    if(integer::condition("JZ",flags)) goto L004e51a0;
  }
  L004e517d: { // 0x4e517d: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e5180: { // 0x4e5180: 0f84d4010000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5186: { // 0x4e5186: 8b8674560000 MOV EAX, dword ptr [ESI + 0x5674]
    s.ax = m.r32((s.si+0x00005674u));
  }
  L004e518c: { // 0x4e518c: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e5191: { // 0x4e5191: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e5193: { // 0x4e5193: 85c2 TEST EDX, EAX
    (void)integer::logical((s.dx)&(s.ax),32,flags);
  }
  L004e5195: { // 0x4e5195: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e5198: { // 0x4e5198: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e519a: { // 0x4e519a: 0f84ba010000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e51a0: { // 0x4e51a0: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L004e51a3: { // 0x4e51a3: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e51a8: { // 0x4e51a8: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e51aa: { // 0x4e51aa: 8b8e74560000 MOV ECX, dword ptr [ESI + 0x5674]
    s.cx = m.r32((s.si+0x00005674u));
  }
  L004e51b0: { // 0x4e51b0: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L004e51b2: { // 0x4e51b2: 23c8 AND ECX, EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L004e51b4: { // 0x4e51b4: 898e74560000 MOV dword ptr [ESI + 0x5674], ECX
    m.w32((s.si+0x00005674u), s.cx);
  }
  L004e51ba: { // 0x4e51ba: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e51bf: { // 0x4e51bf: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e51c1: { // 0x4e51c1: 741d JZ 0x4e51e0
    if(integer::condition("JZ",flags)) goto L004e51e0;
  }
  L004e51c3: { // 0x4e51c3: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L004e51c6: { // 0x4e51c6: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e51cb: { // 0x4e51cb: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e51cd: { // 0x4e51cd: 8b8620010000 MOV EAX, dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L004e51d3: { // 0x4e51d3: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L004e51d5: { // 0x4e51d5: 1bd2 SBB EDX, EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L004e51d7: { // 0x4e51d7: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004e51d8: { // 0x4e51d8: 23c2 AND EAX, EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  L004e51da: { // 0x4e51da: 898620010000 MOV dword ptr [ESI + 0x120], EAX
    m.w32((s.si+0x00000120u), s.ax);
  }
  L004e51e0: { // 0x4e51e0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e51e2: { // 0x4e51e2: e839d70000 CALL 0x4f2920
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2920u,5132775u); flags=s.arithmetic_flags;
  }
  L004e51e7: { // 0x4e51e7: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004e51e9: { // 0x4e51e9: 7479 JZ 0x4e5264
    if(integer::condition("JZ",flags)) goto L004e5264;
  }
  L004e51eb: { // 0x4e51eb: 3bf7 CMP ESI, EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L004e51ed: { // 0x4e51ed: 7425 JZ 0x4e5214
    if(integer::condition("JZ",flags)) goto L004e5214;
  }
  L004e51ef: { // 0x4e51ef: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e51f2: { // 0x4e51f2: 8b4730 MOV EAX, dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  L004e51f5: { // 0x4e51f5: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e51f7: { // 0x4e51f7: 741b JZ 0x4e5214
    if(integer::condition("JZ",flags)) goto L004e5214;
  }
  L004e51f9: { // 0x4e51f9: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e51fc: { // 0x4e51fc: 7466 JZ 0x4e5264
    if(integer::condition("JZ",flags)) goto L004e5264;
  }
  L004e51fe: { // 0x4e51fe: 8b9774560000 MOV EDX, dword ptr [EDI + 0x5674]
    s.dx = m.r32((s.di+0x00005674u));
  }
  L004e5204: { // 0x4e5204: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e5209: { // 0x4e5209: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e520b: { // 0x4e520b: 85d0 TEST EAX, EDX
    (void)integer::logical((s.ax)&(s.dx),32,flags);
  }
  L004e520d: { // 0x4e520d: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e5210: { // 0x4e5210: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5212: { // 0x4e5212: 7450 JZ 0x4e5264
    if(integer::condition("JZ",flags)) goto L004e5264;
  }
  L004e5214: { // 0x4e5214: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e5217: { // 0x4e5217: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e521c: { // 0x4e521c: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e521e: { // 0x4e521e: 8b8f74560000 MOV ECX, dword ptr [EDI + 0x5674]
    s.cx = m.r32((s.di+0x00005674u));
  }
  L004e5224: { // 0x4e5224: b301 MOV BL, 1
    s.bx = with_al(s.bx, 1u);
  }
  L004e5226: { // 0x4e5226: f7d2 NOT EDX
    s.dx = (~(s.dx)&integer::mask(32));
  }
  L004e5228: { // 0x4e5228: 23ca AND ECX, EDX
    s.cx = integer::logical((s.cx)&(s.dx),32,flags);
  }
  L004e522a: { // 0x4e522a: 898f74560000 MOV dword ptr [EDI + 0x5674], ECX
    m.w32((s.di+0x00005674u), s.cx);
  }
  L004e5230: { // 0x4e5230: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e5235: { // 0x4e5235: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e5237: { // 0x4e5237: 741a JZ 0x4e5253
    if(integer::condition("JZ",flags)) goto L004e5253;
  }
  L004e5239: { // 0x4e5239: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e523c: { // 0x4e523c: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e5241: { // 0x4e5241: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e5243: { // 0x4e5243: 8b8e20010000 MOV ECX, dword ptr [ESI + 0x120]
    s.cx = m.r32((s.si+0x00000120u));
  }
  L004e5249: { // 0x4e5249: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L004e524b: { // 0x4e524b: 23c8 AND ECX, EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L004e524d: { // 0x4e524d: 898e20010000 MOV dword ptr [ESI + 0x120], ECX
    m.w32((s.si+0x00000120u), s.cx);
  }
  L004e5253: { // 0x4e5253: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e5255: { // 0x4e5255: e8c6d60000 CALL 0x4f2920
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2920u,5132890u); flags=s.arithmetic_flags;
  }
  L004e525a: { // 0x4e525a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e525b: { // 0x4e525b: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004e525d: { // 0x4e525d: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e525f: { // 0x4e525f: e83c8e0000 CALL 0x4ee0a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ee0a0u,5132900u); flags=s.arithmetic_flags;
  }
  L004e5264: { // 0x4e5264: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e5269: { // 0x4e5269: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e526b: { // 0x4e526b: 0f84e9000000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5271: { // 0x4e5271: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e5276: { // 0x4e5276: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e5278: { // 0x4e5278: 0f85dc000000 JNZ 0x4e535a
    if(integer::condition("JNZ",flags)) goto L004e535a;
  }
  L004e527e: { // 0x4e527e: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e5284: { // 0x4e5284: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5286: { // 0x4e5286: 0f84ce000000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e528c: { // 0x4e528c: 8d8f165f0100 LEA ECX, [EDI + 0x15f16]
    s.cx = (s.di+0x00015f16u);
  }
  L004e5292: { // 0x4e5292: 8d96165f0100 LEA EDX, [ESI + 0x15f16]
    s.dx = (s.si+0x00015f16u);
  }
  L004e5298: { // 0x4e5298: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e5299: { // 0x4e5299: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e529a: { // 0x4e529a: 68a00c0000 PUSH 0xca0
    f.push(m,0x00000ca0u);
  }
  L004e529f: { // 0x4e529f: 6804537c00 PUSH 0x7c5304
    f.push(m,0x007c5304u);
  }
  L004e52a4: { // 0x4e52a4: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004e52a6: { // 0x4e52a6: b9e0537c00 MOV ECX, 0x7c53e0
    s.cx = 0x007c53e0u;
  }
  L004e52ab: { // 0x4e52ab: e8b0982000 CALL 0x6eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,5132976u); flags=s.arithmetic_flags;
  }
  L004e52b0: { // 0x4e52b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52b1: { // 0x4e52b1: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L004e52b5: { // 0x4e52b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52b6: { // 0x4e52b6: e8e99d2800 CALL 0x76f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,5132987u); flags=s.arithmetic_flags;
  }
  L004e52bb: { // 0x4e52bb: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004e52c1: { // 0x4e52c1: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e52c4: { // 0x4e52c4: dd8128110000 FLD qword ptr [ECX + 0x1128]
    const auto address=(s.cx+0x00001128u);
    s.fp.load64(read64(m,address));
  }
  L004e52ca: { // 0x4e52ca: dc0d08667800 FMUL qword ptr [0x786608]
    const auto address=(0x00786608u);
    s.fp.multiply64(read64(m,address));
  }
  L004e52d0: { // 0x4e52d0: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52d2: { // 0x4e52d2: e879572800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5133015u); flags=s.arithmetic_flags;
  }
  L004e52d7: { // 0x4e52d7: 8b5634 MOV EDX, dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004e52da: { // 0x4e52da: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52db: { // 0x4e52db: 6846400000 PUSH 0x4046
    f.push(m,0x00004046u);
  }
  L004e52e0: { // 0x4e52e0: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004e52e4: { // 0x4e52e4: 8b82c0000000 MOV EAX, dword ptr [EDX + 0xc0]
    s.ax = m.r32((s.dx+0x000000c0u));
  }
  L004e52ea: { // 0x4e52ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52eb: { // 0x4e52eb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e52ec: { // 0x4e52ec: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52ee: { // 0x4e52ee: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52f0: { // 0x4e52f0: b9a05fa200 MOV ECX, 0xa25fa0
    s.cx = 0x00a25fa0u;
  }
  L004e52f5: { // 0x4e52f5: e886c60c00 CALL 0x5b1980
    s.arithmetic_flags=flags; invoke(m,s,f,0x005b1980u,5133050u); flags=s.arithmetic_flags;
  }
  L004e52fa: { // 0x4e52fa: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52fc: { // 0x4e52fc: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e5301: { // 0x4e5301: e82aadffff CALL 0x4e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,5133062u); flags=s.arithmetic_flags;
  }
  L004e5306: { // 0x4e5306: 8a8424b4000000 MOV AL, byte ptr [ESP + 0xb4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000000b4u)));
  }
  L004e530d: { // 0x4e530d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e530f: { // 0x4e530f: 7449 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5311: { // 0x4e5311: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e5313: { // 0x4e5313: 7445 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5315: { // 0x4e5315: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e531a: { // 0x4e531a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e531c: { // 0x4e531c: 7516 JNZ 0x4e5334
    if(integer::condition("JNZ",flags)) goto L004e5334;
  }
  L004e531e: { // 0x4e531e: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e5324: { // 0x4e5324: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5326: { // 0x4e5326: 7523 JNZ 0x4e534b
    if(integer::condition("JNZ",flags)) goto L004e534b;
  }
  L004e5328: { // 0x4e5328: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e532e: { // 0x4e532e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5330: { // 0x4e5330: 7442 JZ 0x4e5374
    if(integer::condition("JZ",flags)) goto L004e5374;
  }
  L004e5332: { // 0x4e5332: eb17 JMP 0x4e534b
    goto L004e534b;
  }
  L004e5334: { // 0x4e5334: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L004e5339: { // 0x4e5339: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004e533b: { // 0x4e533b: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e533e: { // 0x4e533e: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e5340: { // 0x4e5340: 7509 JNZ 0x4e534b
    if(integer::condition("JNZ",flags)) goto L004e534b;
  }
  L004e5342: { // 0x4e5342: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004e5344: { // 0x4e5344: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e5347: { // 0x4e5347: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5349: { // 0x4e5349: 740f JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e534b: { // 0x4e534b: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e534d: { // 0x4e534d: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5350: { // 0x4e5350: b9cc537c00 MOV ECX, 0x7c53cc
    s.cx = 0x007c53ccu;
  }
  L004e5355: { // 0x4e5355: e8a6532200 CALL 0x70a700
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a700u,5133146u); flags=s.arithmetic_flags;
  }
  L004e535a: { // 0x4e535a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e535c: { // 0x4e535c: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e535e: { // 0x4e535e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e5363: { // 0x4e5363: e83888fbff CALL 0x49dba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dba0u,5133160u); flags=s.arithmetic_flags;
  }
  L004e5368: { // 0x4e5368: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e5369: { // 0x4e5369: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e536a: { // 0x4e536a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e536b: { // 0x4e536b: 81c4a0000000 ADD ESP, 0xa0
    f.sp = integer::add(f.sp,0x000000a0u,32,flags);
  }
  L004e5371: { // 0x4e5371: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004e5374: { // 0x4e5374: 8a8734010000 MOV AL, byte ptr [EDI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000134u)));
  }
  L004e537a: { // 0x4e537a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e537c: { // 0x4e537c: 75cd JNZ 0x4e534b
    if(integer::condition("JNZ",flags)) goto L004e534b;
  }
  L004e537e: { // 0x4e537e: 8a8735010000 MOV AL, byte ptr [EDI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000135u)));
  }
  L004e5384: { // 0x4e5384: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5386: { // 0x4e5386: 74d2 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5388: { // 0x4e5388: ebc1 JMP 0x4e534b
    goto L004e534b;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x4e5110u:f_000e5110(m,s,child,{});break;
case 0x4e4d00u:f_000e4d00(m,s,child,{});break;
case 0x4f2920u:f_000f2920(m,s,child,{});break;
case 4840752u:f_0009dd30(m,s,child,{});break;
case 4840352u:f_0009dba0(m,s,child,{});break;
case 5169312u:f_000ee0a0(m,s,child,{});break;
case 5159424u:f_000eba00(m,s,child,{});break;
default:throw std::domain_error("recovery746 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004e4d00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e4d00: { // 0x4e4d00: 81eca8000000 SUB ESP, 0xa8
    f.sp = integer::sub(f.sp,0x000000a8u,32,flags);
  }
  L004e4d06: { // 0x4e4d06: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e4d07: { // 0x4e4d07: 8bac24b0000000 MOV EBP, dword ptr [ESP + 0xb0]
    s.bp = m.r32((f.sp+0x000000b0u));
  }
  L004e4d0e: { // 0x4e4d0e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e4d0f: { // 0x4e4d0f: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004e4d11: { // 0x4e4d11: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e4d12: { // 0x4e4d12: e8e96c0000 CALL 0x4eba00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eba00u,5131543u); flags=s.arithmetic_flags;
  }
  L004e4d17: { // 0x4e4d17: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4d19: { // 0x4e4d19: 0f84c4030000 JZ 0x4e50e3
    if(integer::condition("JZ",flags)) goto L004e50e3;
  }
  L004e4d1f: { // 0x4e4d1f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e4d20: { // 0x4e4d20: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e4d21: { // 0x4e4d21: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4d23: { // 0x4e4d23: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4d25: { // 0x4e4d25: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e4d2a: { // 0x4e4d2a: e80190fbff CALL 0x49dd30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dd30u,5131567u); flags=s.arithmetic_flags;
  }
  L004e4d2f: { // 0x4e4d2f: 8b4d30 MOV ECX, dword ptr [EBP + 0x30]
    s.cx = m.r32((s.bp+0x00000030u));
  }
  L004e4d32: { // 0x4e4d32: 8bbe74560000 MOV EDI, dword ptr [ESI + 0x5674]
    s.di = m.r32((s.si+0x00005674u));
  }
  L004e4d38: { // 0x4e4d38: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e4d3d: { // 0x4e4d3d: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4d3f: { // 0x4e4d3f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e4d41: { // 0x4e4d41: 0bf8 OR EDI, EAX
    s.di = integer::logical((s.di)|(s.ax),32,flags);
  }
  L004e4d43: { // 0x4e4d43: 89be74560000 MOV dword ptr [ESI + 0x5674], EDI
    m.w32((s.si+0x00005674u), s.di);
  }
  L004e4d49: { // 0x4e4d49: e8d2db0000 CALL 0x4f2920
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2920u,5131598u); flags=s.arithmetic_flags;
  }
  L004e4d4e: { // 0x4e4d4e: 8b8e04550000 MOV ECX, dword ptr [ESI + 0x5504]
    s.cx = m.r32((s.si+0x00005504u));
  }
  L004e4d54: { // 0x4e4d54: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004e4d56: { // 0x4e4d56: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4d58: { // 0x4e4d58: 7e25 JLE 0x4e4d7f
    if(integer::condition("JLE",flags)) goto L004e4d7f;
  }
  L004e4d5a: { // 0x4e4d5a: 8bbef8540000 MOV EDI, dword ptr [ESI + 0x54f8]
    s.di = m.r32((s.si+0x000054f8u));
  }
  L004e4d60: { // 0x4e4d60: 8bd7 MOV EDX, EDI
    s.dx = s.di;
  }
  L004e4d62: { // 0x4e4d62: 392a CMP dword ptr [EDX], EBP
    (void)integer::sub(m.r32((s.dx)),s.bp,32,flags);
  }
  L004e4d64: { // 0x4e4d64: 740a JZ 0x4e4d70
    if(integer::condition("JZ",flags)) goto L004e4d70;
  }
  L004e4d66: { // 0x4e4d66: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004e4d67: { // 0x4e4d67: 83c208 ADD EDX, 8
    s.dx = integer::add(s.dx,8u,32,flags);
  }
  L004e4d6a: { // 0x4e4d6a: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004e4d6c: { // 0x4e4d6c: 7cf4 JL 0x4e4d62
    if(integer::condition("JL",flags)) goto L004e4d62;
  }
  L004e4d6e: { // 0x4e4d6e: eb0f JMP 0x4e4d7f
    goto L004e4d7f;
  }
  L004e4d70: { // 0x4e4d70: 8b4cc704 MOV ECX, dword ptr [EDI + EAX*8 + 4]
    s.cx = m.r32((s.di+(s.ax * 8u)+4u));
  }
  L004e4d74: { // 0x4e4d74: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e4d75: { // 0x4e4d75: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L004e4d77: { // 0x4e4d77: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e4d78: { // 0x4e4d78: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e4d7a: { // 0x4e4d7a: e821930000 CALL 0x4ee0a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ee0a0u,5131647u); flags=s.arithmetic_flags;
  }
  L004e4d7f: { // 0x4e4d7f: 8b96f0540000 MOV EDX, dword ptr [ESI + 0x54f0]
    s.dx = m.r32((s.si+0x000054f0u));
  }
  L004e4d85: { // 0x4e4d85: 8b4530 MOV EAX, dword ptr [EBP + 0x30]
    s.ax = m.r32((s.bp+0x00000030u));
  }
  L004e4d88: { // 0x4e4d88: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004e4d8a: { // 0x4e4d8a: 750a JNZ 0x4e4d96
    if(integer::condition("JNZ",flags)) goto L004e4d96;
  }
  L004e4d8c: { // 0x4e4d8c: c786f0540000ffffffff MOV dword ptr [ESI + 0x54f0], 0xffffffff
    m.w32((s.si+0x000054f0u), 0xffffffffu);
  }
  L004e4d96: { // 0x4e4d96: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e4d9b: { // 0x4e4d9b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4d9d: { // 0x4e4d9d: 7410 JZ 0x4e4daf
    if(integer::condition("JZ",flags)) goto L004e4daf;
  }
  L004e4d9f: { // 0x4e4d9f: 8b4d30 MOV ECX, dword ptr [EBP + 0x30]
    s.cx = m.r32((s.bp+0x00000030u));
  }
  L004e4da2: { // 0x4e4da2: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e4da7: { // 0x4e4da7: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4da9: { // 0x4e4da9: 098620010000 OR dword ptr [ESI + 0x120], EAX
    m.w32((s.si+0x00000120u), integer::logical((m.r32((s.si+0x00000120u)))|(s.ax),32,flags));
  }
  L004e4daf: { // 0x4e4daf: 8b0dc855a200 MOV ECX, dword ptr [0xa255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L004e4db5: { // 0x4e4db5: 83f904 CMP ECX, 4
    (void)integer::sub(s.cx,4u,32,flags);
  }
  L004e4db8: { // 0x4e4db8: 740d JZ 0x4e4dc7
    if(integer::condition("JZ",flags)) goto L004e4dc7;
  }
  L004e4dba: { // 0x4e4dba: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e4dbf: { // 0x4e4dbf: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4dc1: { // 0x4e4dc1: 0f850c030000 JNZ 0x4e50d3
    if(integer::condition("JNZ",flags)) goto L004e50d3;
  }
  L004e4dc7: { // 0x4e4dc7: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e4dcd: { // 0x4e4dcd: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4dcf: { // 0x4e4dcf: 7514 JNZ 0x4e4de5
    if(integer::condition("JNZ",flags)) goto L004e4de5;
  }
  L004e4dd1: { // 0x4e4dd1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4dd3: { // 0x4e4dd3: 750e JNZ 0x4e4de3
    if(integer::condition("JNZ",flags)) goto L004e4de3;
  }
  L004e4dd5: { // 0x4e4dd5: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e4ddb: { // 0x4e4ddb: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4ddd: { // 0x4e4ddd: 7504 JNZ 0x4e4de3
    if(integer::condition("JNZ",flags)) goto L004e4de3;
  }
  L004e4ddf: { // 0x4e4ddf: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4de1: { // 0x4e4de1: eb02 JMP 0x4e4de5
    goto L004e4de5;
  }
  L004e4de3: { // 0x4e4de3: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4de5: { // 0x4e4de5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4de7: { // 0x4e4de7: 7426 JZ 0x4e4e0f
    if(integer::condition("JZ",flags)) goto L004e4e0f;
  }
  L004e4de9: { // 0x4e4de9: 8b15881b8200 MOV EDX, dword ptr [0x821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L004e4def: { // 0x4e4def: 8a8224140000 MOV AL, byte ptr [EDX + 0x1424]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001424u)));
  }
  L004e4df5: { // 0x4e4df5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4df7: { // 0x4e4df7: 7416 JZ 0x4e4e0f
    if(integer::condition("JZ",flags)) goto L004e4e0f;
  }
  L004e4df9: { // 0x4e4df9: 8b4534 MOV EAX, dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L004e4dfc: { // 0x4e4dfc: 8a90a6010000 MOV DL, byte ptr [EAX + 0x1a6]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000001a6u)));
  }
  L004e4e02: { // 0x4e4e02: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004e4e04: { // 0x4e4e04: 7509 JNZ 0x4e4e0f
    if(integer::condition("JNZ",flags)) goto L004e4e0f;
  }
  L004e4e06: { // 0x4e4e06: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4e08: { // 0x4e4e08: 7405 JZ 0x4e4e0f
    if(integer::condition("JZ",flags)) goto L004e4e0f;
  }
  L004e4e0a: { // 0x4e4e0a: e8f16c0000 CALL 0x4ebb00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ebb00u,5131791u); flags=s.arithmetic_flags;
  }
  L004e4e0f: { // 0x4e4e0f: a1c0a78100 MOV EAX, dword ptr [0x81a7c0]
    s.ax = m.r32((0x0081a7c0u));
  }
  L004e4e14: { // 0x4e4e14: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004e4e16: { // 0x4e4e16: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e18: { // 0x4e4e18: 0f8ebd000000 JLE 0x4e4edb
    if(integer::condition("JLE",flags)) goto L004e4edb;
  }
  L004e4e1e: { // 0x4e4e1e: 8b0db4a78100 MOV ECX, dword ptr [0x81a7b4]
    s.cx = m.r32((0x0081a7b4u));
  }
  L004e4e24: { // 0x4e4e24: 8b3c99 MOV EDI, dword ptr [ECX + EBX*4]
    s.di = m.r32((s.cx+(s.bx * 4u)));
  }
  L004e4e27: { // 0x4e4e27: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e4e29: { // 0x4e4e29: 0f849e000000 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e2f: { // 0x4e4e2f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e4e31: { // 0x4e4e31: e8ea8df2ff CALL 0x40dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,5131830u); flags=s.arithmetic_flags;
  }
  L004e4e36: { // 0x4e4e36: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e38: { // 0x4e4e38: 0f848f000000 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e3e: { // 0x4e4e3e: 8a4776 MOV AL, byte ptr [EDI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000076u)));
  }
  L004e4e41: { // 0x4e4e41: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4e43: { // 0x4e4e43: 0f8584000000 JNZ 0x4e4ecd
    if(integer::condition("JNZ",flags)) goto L004e4ecd;
  }
  L004e4e49: { // 0x4e4e49: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004e4e4b: { // 0x4e4e4b: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e4e4d: { // 0x4e4e4d: ff5238 CALL dword ptr [EDX + 0x38]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000038u)),5131856u); flags=s.arithmetic_flags;
  }
  L004e4e50: { // 0x4e4e50: 3b4630 CMP EAX, dword ptr [ESI + 0x30]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000030u)),32,flags);
  }
  L004e4e53: { // 0x4e4e53: 7578 JNZ 0x4e4ecd
    if(integer::condition("JNZ",flags)) goto L004e4ecd;
  }
  L004e4e55: { // 0x4e4e55: 8b8728020000 MOV EAX, dword ptr [EDI + 0x228]
    s.ax = m.r32((s.di+0x00000228u));
  }
  L004e4e5b: { // 0x4e4e5b: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004e4e5f: { // 0x4e4e5f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4e60: { // 0x4e4e60: e88b5c1c00 CALL 0x6aaaf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaaf0u,5131877u); flags=s.arithmetic_flags;
  }
  L004e4e65: { // 0x4e4e65: 8a442414 MOV AL, byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L004e4e69: { // 0x4e4e69: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4e6b: { // 0x4e4e6b: 7460 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e6d: { // 0x4e4e6d: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004e4e71: { // 0x4e4e71: e8ea601c00 CALL 0x6aaf60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaf60u,5131894u); flags=s.arithmetic_flags;
  }
  L004e4e76: { // 0x4e4e76: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e78: { // 0x4e4e78: 7453 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e7a: { // 0x4e4e7a: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L004e4e7e: { // 0x4e4e7e: e8dd601c00 CALL 0x6aaf60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaf60u,5131907u); flags=s.arithmetic_flags;
  }
  L004e4e83: { // 0x4e4e83: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e85: { // 0x4e4e85: 7446 JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e87: { // 0x4e4e87: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004e4e89: { // 0x4e4e89: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004e4e8b: { // 0x4e4e8b: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),5131918u); flags=s.arithmetic_flags;
  }
  L004e4e8e: { // 0x4e4e8e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4e90: { // 0x4e4e90: 743b JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4e92: { // 0x4e4e92: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004e4e94: { // 0x4e4e94: 742b JZ 0x4e4ec1
    if(integer::condition("JZ",flags)) goto L004e4ec1;
  }
  L004e4e96: { // 0x4e4e96: 8b4830 MOV ECX, dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L004e4e99: { // 0x4e4e99: 8b4630 MOV EAX, dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004e4e9c: { // 0x4e4e9c: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e4e9e: { // 0x4e4e9e: 7504 JNZ 0x4e4ea4
    if(integer::condition("JNZ",flags)) goto L004e4ea4;
  }
  L004e4ea0: { // 0x4e4ea0: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4ea2: { // 0x4e4ea2: eb19 JMP 0x4e4ebd
    goto L004e4ebd;
  }
  L004e4ea4: { // 0x4e4ea4: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e4ea7: { // 0x4e4ea7: 7412 JZ 0x4e4ebb
    if(integer::condition("JZ",flags)) goto L004e4ebb;
  }
  L004e4ea9: { // 0x4e4ea9: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e4eae: { // 0x4e4eae: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4eb0: { // 0x4e4eb0: 858674560000 TEST dword ptr [ESI + 0x5674], EAX
    (void)integer::logical((m.r32((s.si+0x00005674u)))&(s.ax),32,flags);
  }
  L004e4eb6: { // 0x4e4eb6: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e4eb9: { // 0x4e4eb9: eb02 JMP 0x4e4ebd
    goto L004e4ebd;
  }
  L004e4ebb: { // 0x4e4ebb: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4ebd: { // 0x4e4ebd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4ebf: { // 0x4e4ebf: 740c JZ 0x4e4ecd
    if(integer::condition("JZ",flags)) goto L004e4ecd;
  }
  L004e4ec1: { // 0x4e4ec1: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004e4ec3: { // 0x4e4ec3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4ec5: { // 0x4e4ec5: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e4ec7: { // 0x4e4ec7: ff9270030000 CALL dword ptr [EDX + 0x370]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000370u)),5131981u); flags=s.arithmetic_flags;
  }
  L004e4ecd: { // 0x4e4ecd: a1c0a78100 MOV EAX, dword ptr [0x81a7c0]
    s.ax = m.r32((0x0081a7c0u));
  }
  L004e4ed2: { // 0x4e4ed2: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004e4ed3: { // 0x4e4ed3: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004e4ed5: { // 0x4e4ed5: 0f8c43ffffff JL 0x4e4e1e
    if(integer::condition("JL",flags)) goto L004e4e1e;
  }
  L004e4edb: { // 0x4e4edb: 8b0dc855a200 MOV ECX, dword ptr [0xa255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L004e4ee1: { // 0x4e4ee1: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e4ee7: { // 0x4e4ee7: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4ee9: { // 0x4e4ee9: 7514 JNZ 0x4e4eff
    if(integer::condition("JNZ",flags)) goto L004e4eff;
  }
  L004e4eeb: { // 0x4e4eeb: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4eed: { // 0x4e4eed: 750e JNZ 0x4e4efd
    if(integer::condition("JNZ",flags)) goto L004e4efd;
  }
  L004e4eef: { // 0x4e4eef: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e4ef5: { // 0x4e4ef5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4ef7: { // 0x4e4ef7: 7504 JNZ 0x4e4efd
    if(integer::condition("JNZ",flags)) goto L004e4efd;
  }
  L004e4ef9: { // 0x4e4ef9: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e4efb: { // 0x4e4efb: eb02 JMP 0x4e4eff
    goto L004e4eff;
  }
  L004e4efd: { // 0x4e4efd: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004e4eff: { // 0x4e4eff: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4f01: { // 0x4e4f01: 0f84c0010000 JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e4f07: { // 0x4e4f07: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004e4f09: { // 0x4e4f09: 0f84b8010000 JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e4f0f: { // 0x4e4f0f: 8b4534 MOV EAX, dword ptr [EBP + 0x34]
    s.ax = m.r32((s.bp+0x00000034u));
  }
  L004e4f12: { // 0x4e4f12: 8a88a6010000 MOV CL, byte ptr [EAX + 0x1a6]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000001a6u)));
  }
  L004e4f18: { // 0x4e4f18: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e4f1a: { // 0x4e4f1a: 0f85a7010000 JNZ 0x4e50c7
    if(integer::condition("JNZ",flags)) goto L004e50c7;
  }
  L004e4f20: { // 0x4e4f20: 8d8d165f0100 LEA ECX, [EBP + 0x15f16]
    s.cx = (s.bp+0x00015f16u);
  }
  L004e4f26: { // 0x4e4f26: 8d96165f0100 LEA EDX, [ESI + 0x15f16]
    s.dx = (s.si+0x00015f16u);
  }
  L004e4f2c: { // 0x4e4f2c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e4f2d: { // 0x4e4f2d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e4f2e: { // 0x4e4f2e: 68250c0000 PUSH 0xc25
    f.push(m,0x00000c25u);
  }
  L004e4f33: { // 0x4e4f33: 6804537c00 PUSH 0x7c5304
    f.push(m,0x007c5304u);
  }
  L004e4f38: { // 0x4e4f38: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004e4f3a: { // 0x4e4f3a: b9bc537c00 MOV ECX, 0x7c53bc
    s.cx = 0x007c53bcu;
  }
  L004e4f3f: { // 0x4e4f3f: e81c9c2000 CALL 0x6eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,5132100u); flags=s.arithmetic_flags;
  }
  L004e4f44: { // 0x4e4f44: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f45: { // 0x4e4f45: 8d442424 LEA EAX, [ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L004e4f49: { // 0x4e4f49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f4a: { // 0x4e4f4a: e855a12800 CALL 0x76f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,5132111u); flags=s.arithmetic_flags;
  }
  L004e4f4f: { // 0x4e4f4f: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004e4f55: { // 0x4e4f55: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e4f58: { // 0x4e4f58: dd8128110000 FLD qword ptr [ECX + 0x1128]
    const auto address=(s.cx+0x00001128u);
    s.fp.load64(read64(m,address));
  }
  L004e4f5e: { // 0x4e4f5e: dc0d08667800 FMUL qword ptr [0x786608]
    const auto address=(0x00786608u);
    s.fp.multiply64(read64(m,address));
  }
  L004e4f64: { // 0x4e4f64: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4f66: { // 0x4e4f66: e8e55a2800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5132139u); flags=s.arithmetic_flags;
  }
  L004e4f6b: { // 0x4e4f6b: 8b5634 MOV EDX, dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004e4f6e: { // 0x4e4f6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f6f: { // 0x4e4f6f: 6846400000 PUSH 0x4046
    f.push(m,0x00004046u);
  }
  L004e4f74: { // 0x4e4f74: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L004e4f78: { // 0x4e4f78: 8b82c0000000 MOV EAX, dword ptr [EDX + 0xc0]
    s.ax = m.r32((s.dx+0x000000c0u));
  }
  L004e4f7e: { // 0x4e4f7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e4f7f: { // 0x4e4f7f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e4f80: { // 0x4e4f80: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4f82: { // 0x4e4f82: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e4f84: { // 0x4e4f84: b9a05fa200 MOV ECX, 0xa25fa0
    s.cx = 0x00a25fa0u;
  }
  L004e4f89: { // 0x4e4f89: e8f2c90c00 CALL 0x5b1980
    s.arithmetic_flags=flags; invoke(m,s,f,0x005b1980u,5132174u); flags=s.arithmetic_flags;
  }
  L004e4f8e: { // 0x4e4f8e: 8a8424c0000000 MOV AL, byte ptr [ESP + 0xc0]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000000c0u)));
  }
  L004e4f95: { // 0x4e4f95: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4f97: { // 0x4e4f97: 0f842a010000 JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e4f9d: { // 0x4e4f9d: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004e4f9f: { // 0x4e4f9f: 0f84b1000000 JZ 0x4e5056
    if(integer::condition("JZ",flags)) goto L004e5056;
  }
  L004e4fa5: { // 0x4e4fa5: 3bf5 CMP ESI, EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L004e4fa7: { // 0x4e4fa7: 742d JZ 0x4e4fd6
    if(integer::condition("JZ",flags)) goto L004e4fd6;
  }
  L004e4fa9: { // 0x4e4fa9: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e4fac: { // 0x4e4fac: 8b4530 MOV EAX, dword ptr [EBP + 0x30]
    s.ax = m.r32((s.bp+0x00000030u));
  }
  L004e4faf: { // 0x4e4faf: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e4fb1: { // 0x4e4fb1: 7423 JZ 0x4e4fd6
    if(integer::condition("JZ",flags)) goto L004e4fd6;
  }
  L004e4fb3: { // 0x4e4fb3: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e4fb6: { // 0x4e4fb6: 0f849a000000 JZ 0x4e5056
    if(integer::condition("JZ",flags)) goto L004e5056;
  }
  L004e4fbc: { // 0x4e4fbc: 8bbd74560000 MOV EDI, dword ptr [EBP + 0x5674]
    s.di = m.r32((s.bp+0x00005674u));
  }
  L004e4fc2: { // 0x4e4fc2: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e4fc7: { // 0x4e4fc7: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e4fc9: { // 0x4e4fc9: 85fa TEST EDX, EDI
    (void)integer::logical((s.dx)&(s.di),32,flags);
  }
  L004e4fcb: { // 0x4e4fcb: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e4fce: { // 0x4e4fce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e4fd0: { // 0x4e4fd0: 0f8480000000 JZ 0x4e5056
    if(integer::condition("JZ",flags)) goto L004e5056;
  }
  L004e4fd6: { // 0x4e4fd6: a17858a200 MOV EAX, dword ptr [0xa25878]
    s.ax = m.r32((0x00a25878u));
  }
  L004e4fdb: { // 0x4e4fdb: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e4fdd: { // 0x4e4fdd: 0f85e4000000 JNZ 0x4e50c7
    if(integer::condition("JNZ",flags)) goto L004e50c7;
  }
  L004e4fe3: { // 0x4e4fe3: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004e4fe5: { // 0x4e4fe5: 7463 JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e4fe7: { // 0x4e4fe7: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L004e4fec: { // 0x4e4fec: 3be8 CMP EBP, EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L004e4fee: { // 0x4e4fee: 7425 JZ 0x4e5015
    if(integer::condition("JZ",flags)) goto L004e5015;
  }
  L004e4ff0: { // 0x4e4ff0: 8b4d30 MOV ECX, dword ptr [EBP + 0x30]
    s.cx = m.r32((s.bp+0x00000030u));
  }
  L004e4ff3: { // 0x4e4ff3: 8b5030 MOV EDX, dword ptr [EAX + 0x30]
    s.dx = m.r32((s.ax+0x00000030u));
  }
  L004e4ff6: { // 0x4e4ff6: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004e4ff8: { // 0x4e4ff8: 741b JZ 0x4e5015
    if(integer::condition("JZ",flags)) goto L004e5015;
  }
  L004e4ffa: { // 0x4e4ffa: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e4ffd: { // 0x4e4ffd: 744b JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e4fff: { // 0x4e4fff: 8bb874560000 MOV EDI, dword ptr [EAX + 0x5674]
    s.di = m.r32((s.ax+0x00005674u));
  }
  L004e5005: { // 0x4e5005: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e500a: { // 0x4e500a: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e500c: { // 0x4e500c: 85fa TEST EDX, EDI
    (void)integer::logical((s.dx)&(s.di),32,flags);
  }
  L004e500e: { // 0x4e500e: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e5011: { // 0x4e5011: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e5013: { // 0x4e5013: 7435 JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e5015: { // 0x4e5015: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004e5017: { // 0x4e5017: 7425 JZ 0x4e503e
    if(integer::condition("JZ",flags)) goto L004e503e;
  }
  L004e5019: { // 0x4e5019: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e501c: { // 0x4e501c: 8b5030 MOV EDX, dword ptr [EAX + 0x30]
    s.dx = m.r32((s.ax+0x00000030u));
  }
  L004e501f: { // 0x4e501f: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004e5021: { // 0x4e5021: 741b JZ 0x4e503e
    if(integer::condition("JZ",flags)) goto L004e503e;
  }
  L004e5023: { // 0x4e5023: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e5026: { // 0x4e5026: 7422 JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e5028: { // 0x4e5028: 8bb074560000 MOV ESI, dword ptr [EAX + 0x5674]
    s.si = m.r32((s.ax+0x00005674u));
  }
  L004e502e: { // 0x4e502e: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e5033: { // 0x4e5033: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e5035: { // 0x4e5035: 85f2 TEST EDX, ESI
    (void)integer::logical((s.dx)&(s.si),32,flags);
  }
  L004e5037: { // 0x4e5037: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e503a: { // 0x4e503a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e503c: { // 0x4e503c: 740c JZ 0x4e504a
    if(integer::condition("JZ",flags)) goto L004e504a;
  }
  L004e503e: { // 0x4e503e: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e5040: { // 0x4e5040: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5043: { // 0x4e5043: b9a8537c00 MOV ECX, 0x7c53a8
    s.cx = 0x007c53a8u;
  }
  L004e5048: { // 0x4e5048: eb78 JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e504a: { // 0x4e504a: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e504c: { // 0x4e504c: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e504f: { // 0x4e504f: b990537c00 MOV ECX, 0x7c5390
    s.cx = 0x007c5390u;
  }
  L004e5054: { // 0x4e5054: eb6c JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e5056: { // 0x4e5056: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e505b: { // 0x4e505b: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e505d: { // 0x4e505d: 7520 JNZ 0x4e507f
    if(integer::condition("JNZ",flags)) goto L004e507f;
  }
  L004e505f: { // 0x4e505f: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e5065: { // 0x4e5065: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5067: { // 0x4e5067: 7524 JNZ 0x4e508d
    if(integer::condition("JNZ",flags)) goto L004e508d;
  }
  L004e5069: { // 0x4e5069: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e506f: { // 0x4e506f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5071: { // 0x4e5071: 7426 JZ 0x4e5099
    if(integer::condition("JZ",flags)) goto L004e5099;
  }
  L004e5073: { // 0x4e5073: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e5075: { // 0x4e5075: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5078: { // 0x4e5078: b978537c00 MOV ECX, 0x7c5378
    s.cx = 0x007c5378u;
  }
  L004e507d: { // 0x4e507d: eb43 JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e507f: { // 0x4e507f: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L004e5084: { // 0x4e5084: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004e5086: { // 0x4e5086: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e5089: { // 0x4e5089: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e508b: { // 0x4e508b: 7422 JZ 0x4e50af
    if(integer::condition("JZ",flags)) goto L004e50af;
  }
  L004e508d: { // 0x4e508d: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e508f: { // 0x4e508f: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5092: { // 0x4e5092: b978537c00 MOV ECX, 0x7c5378
    s.cx = 0x007c5378u;
  }
  L004e5097: { // 0x4e5097: eb29 JMP 0x4e50c2
    goto L004e50c2;
  }
  L004e5099: { // 0x4e5099: 8a8534010000 MOV AL, byte ptr [EBP + 0x134]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000134u)));
  }
  L004e509f: { // 0x4e509f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e50a1: { // 0x4e50a1: 7515 JNZ 0x4e50b8
    if(integer::condition("JNZ",flags)) goto L004e50b8;
  }
  L004e50a3: { // 0x4e50a3: 8a8535010000 MOV AL, byte ptr [EBP + 0x135]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000135u)));
  }
  L004e50a9: { // 0x4e50a9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e50ab: { // 0x4e50ab: 741a JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e50ad: { // 0x4e50ad: eb09 JMP 0x4e50b8
    goto L004e50b8;
  }
  L004e50af: { // 0x4e50af: 3be8 CMP EBP, EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L004e50b1: { // 0x4e50b1: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e50b4: { // 0x4e50b4: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e50b6: { // 0x4e50b6: 740f JZ 0x4e50c7
    if(integer::condition("JZ",flags)) goto L004e50c7;
  }
  L004e50b8: { // 0x4e50b8: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e50ba: { // 0x4e50ba: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e50bd: { // 0x4e50bd: b960537c00 MOV ECX, 0x7c5360
    s.cx = 0x007c5360u;
  }
  L004e50c2: { // 0x4e50c2: e839562200 CALL 0x70a700
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a700u,5132487u); flags=s.arithmetic_flags;
  }
  L004e50c7: { // 0x4e50c7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e50c9: { // 0x4e50c9: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e50ce: { // 0x4e50ce: e85dafffff CALL 0x4e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,5132499u); flags=s.arithmetic_flags;
  }
  L004e50d3: { // 0x4e50d3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e50d5: { // 0x4e50d5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e50d7: { // 0x4e50d7: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e50dc: { // 0x4e50dc: e8bf8afbff CALL 0x49dba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dba0u,5132513u); flags=s.arithmetic_flags;
  }
  L004e50e1: { // 0x4e50e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e50e2: { // 0x4e50e2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e50e3: { // 0x4e50e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e50e4: { // 0x4e50e4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e50e5: { // 0x4e50e5: 81c4a8000000 ADD ESP, 0xa8
    f.sp = integer::add(f.sp,0x000000a8u,32,flags);
  }
  L004e50eb: { // 0x4e50eb: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004e5110(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e5110: { // 0x4e5110: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e5115: { // 0x4e5115: 81eca0000000 SUB ESP, 0xa0
    f.sp = integer::sub(f.sp,0x000000a0u,32,flags);
  }
  L004e511b: { // 0x4e511b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e511c: { // 0x4e511c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e511d: { // 0x4e511d: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L004e511f: { // 0x4e511f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e5120: { // 0x4e5120: 8bbc24b0000000 MOV EDI, dword ptr [ESP + 0xb0]
    s.di = m.r32((f.sp+0x000000b0u));
  }
  L004e5127: { // 0x4e5127: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004e5129: { // 0x4e5129: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e512b: { // 0x4e512b: 7422 JZ 0x4e514f
    if(integer::condition("JZ",flags)) goto L004e514f;
  }
  L004e512d: { // 0x4e512d: 8b4734 MOV EAX, dword ptr [EDI + 0x34]
    s.ax = m.r32((s.di+0x00000034u));
  }
  L004e5130: { // 0x4e5130: 8a88a6010000 MOV CL, byte ptr [EAX + 0x1a6]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000001a6u)));
  }
  L004e5136: { // 0x4e5136: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e5138: { // 0x4e5138: 0f852a020000 JNZ 0x4e5368
    if(integer::condition("JNZ",flags)) goto L004e5368;
  }
  L004e513e: { // 0x4e513e: 8b4e34 MOV ECX, dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  L004e5141: { // 0x4e5141: 8a81a6010000 MOV AL, byte ptr [ECX + 0x1a6]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000001a6u)));
  }
  L004e5147: { // 0x4e5147: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5149: { // 0x4e5149: 0f8519020000 JNZ 0x4e5368
    if(integer::condition("JNZ",flags)) goto L004e5368;
  }
  L004e514f: { // 0x4e514f: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e5151: { // 0x4e5151: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e5153: { // 0x4e5153: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e5158: { // 0x4e5158: e8d38bfbff CALL 0x49dd30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dd30u,5132637u); flags=s.arithmetic_flags;
  }
  L004e515d: { // 0x4e515d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e515e: { // 0x4e515e: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004e5160: { // 0x4e5160: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e5162: { // 0x4e5162: e8398f0000 CALL 0x4ee0a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ee0a0u,5132647u); flags=s.arithmetic_flags;
  }
  L004e5167: { // 0x4e5167: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004e5169: { // 0x4e5169: 0f84eb010000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e516f: { // 0x4e516f: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L004e5171: { // 0x4e5171: 742d JZ 0x4e51a0
    if(integer::condition("JZ",flags)) goto L004e51a0;
  }
  L004e5173: { // 0x4e5173: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L004e5176: { // 0x4e5176: 8b4630 MOV EAX, dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004e5179: { // 0x4e5179: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e517b: { // 0x4e517b: 7423 JZ 0x4e51a0
    if(integer::condition("JZ",flags)) goto L004e51a0;
  }
  L004e517d: { // 0x4e517d: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e5180: { // 0x4e5180: 0f84d4010000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5186: { // 0x4e5186: 8b8674560000 MOV EAX, dword ptr [ESI + 0x5674]
    s.ax = m.r32((s.si+0x00005674u));
  }
  L004e518c: { // 0x4e518c: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e5191: { // 0x4e5191: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e5193: { // 0x4e5193: 85c2 TEST EDX, EAX
    (void)integer::logical((s.dx)&(s.ax),32,flags);
  }
  L004e5195: { // 0x4e5195: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e5198: { // 0x4e5198: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e519a: { // 0x4e519a: 0f84ba010000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e51a0: { // 0x4e51a0: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L004e51a3: { // 0x4e51a3: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e51a8: { // 0x4e51a8: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e51aa: { // 0x4e51aa: 8b8e74560000 MOV ECX, dword ptr [ESI + 0x5674]
    s.cx = m.r32((s.si+0x00005674u));
  }
  L004e51b0: { // 0x4e51b0: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L004e51b2: { // 0x4e51b2: 23c8 AND ECX, EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L004e51b4: { // 0x4e51b4: 898e74560000 MOV dword ptr [ESI + 0x5674], ECX
    m.w32((s.si+0x00005674u), s.cx);
  }
  L004e51ba: { // 0x4e51ba: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e51bf: { // 0x4e51bf: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e51c1: { // 0x4e51c1: 741d JZ 0x4e51e0
    if(integer::condition("JZ",flags)) goto L004e51e0;
  }
  L004e51c3: { // 0x4e51c3: 8b4f30 MOV ECX, dword ptr [EDI + 0x30]
    s.cx = m.r32((s.di+0x00000030u));
  }
  L004e51c6: { // 0x4e51c6: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e51cb: { // 0x4e51cb: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e51cd: { // 0x4e51cd: 8b8620010000 MOV EAX, dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L004e51d3: { // 0x4e51d3: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L004e51d5: { // 0x4e51d5: 1bd2 SBB EDX, EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L004e51d7: { // 0x4e51d7: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004e51d8: { // 0x4e51d8: 23c2 AND EAX, EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  L004e51da: { // 0x4e51da: 898620010000 MOV dword ptr [ESI + 0x120], EAX
    m.w32((s.si+0x00000120u), s.ax);
  }
  L004e51e0: { // 0x4e51e0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004e51e2: { // 0x4e51e2: e839d70000 CALL 0x4f2920
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2920u,5132775u); flags=s.arithmetic_flags;
  }
  L004e51e7: { // 0x4e51e7: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004e51e9: { // 0x4e51e9: 7479 JZ 0x4e5264
    if(integer::condition("JZ",flags)) goto L004e5264;
  }
  L004e51eb: { // 0x4e51eb: 3bf7 CMP ESI, EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L004e51ed: { // 0x4e51ed: 7425 JZ 0x4e5214
    if(integer::condition("JZ",flags)) goto L004e5214;
  }
  L004e51ef: { // 0x4e51ef: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e51f2: { // 0x4e51f2: 8b4730 MOV EAX, dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  L004e51f5: { // 0x4e51f5: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004e51f7: { // 0x4e51f7: 741b JZ 0x4e5214
    if(integer::condition("JZ",flags)) goto L004e5214;
  }
  L004e51f9: { // 0x4e51f9: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004e51fc: { // 0x4e51fc: 7466 JZ 0x4e5264
    if(integer::condition("JZ",flags)) goto L004e5264;
  }
  L004e51fe: { // 0x4e51fe: 8b9774560000 MOV EDX, dword ptr [EDI + 0x5674]
    s.dx = m.r32((s.di+0x00005674u));
  }
  L004e5204: { // 0x4e5204: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e5209: { // 0x4e5209: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e520b: { // 0x4e520b: 85d0 TEST EAX, EDX
    (void)integer::logical((s.ax)&(s.dx),32,flags);
  }
  L004e520d: { // 0x4e520d: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004e5210: { // 0x4e5210: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5212: { // 0x4e5212: 7450 JZ 0x4e5264
    if(integer::condition("JZ",flags)) goto L004e5264;
  }
  L004e5214: { // 0x4e5214: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e5217: { // 0x4e5217: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004e521c: { // 0x4e521c: d3e2 SHL EDX, CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e521e: { // 0x4e521e: 8b8f74560000 MOV ECX, dword ptr [EDI + 0x5674]
    s.cx = m.r32((s.di+0x00005674u));
  }
  L004e5224: { // 0x4e5224: b301 MOV BL, 1
    s.bx = with_al(s.bx, 1u);
  }
  L004e5226: { // 0x4e5226: f7d2 NOT EDX
    s.dx = (~(s.dx)&integer::mask(32));
  }
  L004e5228: { // 0x4e5228: 23ca AND ECX, EDX
    s.cx = integer::logical((s.cx)&(s.dx),32,flags);
  }
  L004e522a: { // 0x4e522a: 898f74560000 MOV dword ptr [EDI + 0x5674], ECX
    m.w32((s.di+0x00005674u), s.cx);
  }
  L004e5230: { // 0x4e5230: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e5235: { // 0x4e5235: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e5237: { // 0x4e5237: 741a JZ 0x4e5253
    if(integer::condition("JZ",flags)) goto L004e5253;
  }
  L004e5239: { // 0x4e5239: 8b4e30 MOV ECX, dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004e523c: { // 0x4e523c: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004e5241: { // 0x4e5241: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004e5243: { // 0x4e5243: 8b8e20010000 MOV ECX, dword ptr [ESI + 0x120]
    s.cx = m.r32((s.si+0x00000120u));
  }
  L004e5249: { // 0x4e5249: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L004e524b: { // 0x4e524b: 23c8 AND ECX, EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L004e524d: { // 0x4e524d: 898e20010000 MOV dword ptr [ESI + 0x120], ECX
    m.w32((s.si+0x00000120u), s.cx);
  }
  L004e5253: { // 0x4e5253: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e5255: { // 0x4e5255: e8c6d60000 CALL 0x4f2920
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2920u,5132890u); flags=s.arithmetic_flags;
  }
  L004e525a: { // 0x4e525a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e525b: { // 0x4e525b: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004e525d: { // 0x4e525d: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004e525f: { // 0x4e525f: e83c8e0000 CALL 0x4ee0a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ee0a0u,5132900u); flags=s.arithmetic_flags;
  }
  L004e5264: { // 0x4e5264: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e5269: { // 0x4e5269: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e526b: { // 0x4e526b: 0f84e9000000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5271: { // 0x4e5271: a1c483a200 MOV EAX, dword ptr [0xa283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  L004e5276: { // 0x4e5276: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e5278: { // 0x4e5278: 0f85dc000000 JNZ 0x4e535a
    if(integer::condition("JNZ",flags)) goto L004e535a;
  }
  L004e527e: { // 0x4e527e: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e5284: { // 0x4e5284: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5286: { // 0x4e5286: 0f84ce000000 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e528c: { // 0x4e528c: 8d8f165f0100 LEA ECX, [EDI + 0x15f16]
    s.cx = (s.di+0x00015f16u);
  }
  L004e5292: { // 0x4e5292: 8d96165f0100 LEA EDX, [ESI + 0x15f16]
    s.dx = (s.si+0x00015f16u);
  }
  L004e5298: { // 0x4e5298: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e5299: { // 0x4e5299: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e529a: { // 0x4e529a: 68a00c0000 PUSH 0xca0
    f.push(m,0x00000ca0u);
  }
  L004e529f: { // 0x4e529f: 6804537c00 PUSH 0x7c5304
    f.push(m,0x007c5304u);
  }
  L004e52a4: { // 0x4e52a4: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004e52a6: { // 0x4e52a6: b9e0537c00 MOV ECX, 0x7c53e0
    s.cx = 0x007c53e0u;
  }
  L004e52ab: { // 0x4e52ab: e8b0982000 CALL 0x6eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,5132976u); flags=s.arithmetic_flags;
  }
  L004e52b0: { // 0x4e52b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52b1: { // 0x4e52b1: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L004e52b5: { // 0x4e52b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52b6: { // 0x4e52b6: e8e99d2800 CALL 0x76f0a4
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f0a4u,5132987u); flags=s.arithmetic_flags;
  }
  L004e52bb: { // 0x4e52bb: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004e52c1: { // 0x4e52c1: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e52c4: { // 0x4e52c4: dd8128110000 FLD qword ptr [ECX + 0x1128]
    const auto address=(s.cx+0x00001128u);
    s.fp.load64(read64(m,address));
  }
  L004e52ca: { // 0x4e52ca: dc0d08667800 FMUL qword ptr [0x786608]
    const auto address=(0x00786608u);
    s.fp.multiply64(read64(m,address));
  }
  L004e52d0: { // 0x4e52d0: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52d2: { // 0x4e52d2: e879572800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5133015u); flags=s.arithmetic_flags;
  }
  L004e52d7: { // 0x4e52d7: 8b5634 MOV EDX, dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004e52da: { // 0x4e52da: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52db: { // 0x4e52db: 6846400000 PUSH 0x4046
    f.push(m,0x00004046u);
  }
  L004e52e0: { // 0x4e52e0: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004e52e4: { // 0x4e52e4: 8b82c0000000 MOV EAX, dword ptr [EDX + 0xc0]
    s.ax = m.r32((s.dx+0x000000c0u));
  }
  L004e52ea: { // 0x4e52ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e52eb: { // 0x4e52eb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e52ec: { // 0x4e52ec: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52ee: { // 0x4e52ee: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52f0: { // 0x4e52f0: b9a05fa200 MOV ECX, 0xa25fa0
    s.cx = 0x00a25fa0u;
  }
  L004e52f5: { // 0x4e52f5: e886c60c00 CALL 0x5b1980
    s.arithmetic_flags=flags; invoke(m,s,f,0x005b1980u,5133050u); flags=s.arithmetic_flags;
  }
  L004e52fa: { // 0x4e52fa: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e52fc: { // 0x4e52fc: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e5301: { // 0x4e5301: e82aadffff CALL 0x4e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,5133062u); flags=s.arithmetic_flags;
  }
  L004e5306: { // 0x4e5306: 8a8424b4000000 MOV AL, byte ptr [ESP + 0xb4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x000000b4u)));
  }
  L004e530d: { // 0x4e530d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e530f: { // 0x4e530f: 7449 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5311: { // 0x4e5311: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e5313: { // 0x4e5313: 7445 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5315: { // 0x4e5315: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004e531a: { // 0x4e531a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004e531c: { // 0x4e531c: 7516 JNZ 0x4e5334
    if(integer::condition("JNZ",flags)) goto L004e5334;
  }
  L004e531e: { // 0x4e531e: 8a8634010000 MOV AL, byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004e5324: { // 0x4e5324: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5326: { // 0x4e5326: 7523 JNZ 0x4e534b
    if(integer::condition("JNZ",flags)) goto L004e534b;
  }
  L004e5328: { // 0x4e5328: 8a8635010000 MOV AL, byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004e532e: { // 0x4e532e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5330: { // 0x4e5330: 7442 JZ 0x4e5374
    if(integer::condition("JZ",flags)) goto L004e5374;
  }
  L004e5332: { // 0x4e5332: eb17 JMP 0x4e534b
    goto L004e534b;
  }
  L004e5334: { // 0x4e5334: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L004e5339: { // 0x4e5339: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L004e533b: { // 0x4e533b: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e533e: { // 0x4e533e: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004e5340: { // 0x4e5340: 7509 JNZ 0x4e534b
    if(integer::condition("JNZ",flags)) goto L004e534b;
  }
  L004e5342: { // 0x4e5342: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004e5344: { // 0x4e5344: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004e5347: { // 0x4e5347: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5349: { // 0x4e5349: 740f JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e534b: { // 0x4e534b: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L004e534d: { // 0x4e534d: 83caff OR EDX, 0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L004e5350: { // 0x4e5350: b9cc537c00 MOV ECX, 0x7c53cc
    s.cx = 0x007c53ccu;
  }
  L004e5355: { // 0x4e5355: e8a6532200 CALL 0x70a700
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a700u,5133146u); flags=s.arithmetic_flags;
  }
  L004e535a: { // 0x4e535a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e535c: { // 0x4e535c: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004e535e: { // 0x4e535e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004e5363: { // 0x4e5363: e83888fbff CALL 0x49dba0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049dba0u,5133160u); flags=s.arithmetic_flags;
  }
  L004e5368: { // 0x4e5368: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e5369: { // 0x4e5369: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e536a: { // 0x4e536a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e536b: { // 0x4e536b: 81c4a0000000 ADD ESP, 0xa0
    f.sp = integer::add(f.sp,0x000000a0u,32,flags);
  }
  L004e5371: { // 0x4e5371: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004e5374: { // 0x4e5374: 8a8734010000 MOV AL, byte ptr [EDI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000134u)));
  }
  L004e537a: { // 0x4e537a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e537c: { // 0x4e537c: 75cd JNZ 0x4e534b
    if(integer::condition("JNZ",flags)) goto L004e534b;
  }
  L004e537e: { // 0x4e537e: 8a8735010000 MOV AL, byte ptr [EDI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000135u)));
  }
  L004e5384: { // 0x4e5384: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e5386: { // 0x4e5386: 74d2 JZ 0x4e535a
    if(integer::condition("JZ",flags)) goto L004e535a;
  }
  L004e5388: { // 0x4e5388: ebc1 JMP 0x4e534b
    goto L004e534b;
  }

}

std::uint32_t fun_004ebb00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ebb00: { // 0x4ebb00: 8b0dd8a5a100 MOV ECX,dword ptr [0x00a1a5d8]
    s.cx = m.r32((0x00a1a5d8u));
  }
  L004ebb06: { // 0x4ebb06: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004ebb07: { // 0x4ebb07: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004ebb09: { // 0x4ebb09: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ebb0b: { // 0x4ebb0b: 0f8ec0000000 JLE 0x004ebbd1
    if(integer::condition("JLE",flags)) goto L004ebbd1;
  }
  L004ebb11: { // 0x4ebb11: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ebb12: { // 0x4ebb12: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ebb13: { // 0x4ebb13: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L004ebb18: { // 0x4ebb18: 8b34a8 MOV ESI,dword ptr [EAX + EBP*0x4]
    s.si = m.r32((s.ax+(s.bp * 0x00000004u)));
  }
  L004ebb1b: { // 0x4ebb1b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004ebb1d: { // 0x4ebb1d: 0f84a3000000 JZ 0x004ebbc6
    if(integer::condition("JZ",flags)) goto L004ebbc6;
  }
  L004ebb23: { // 0x4ebb23: 8a863d010000 MOV AL,byte ptr [ESI + 0x13d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000013du)));
  }
  L004ebb29: { // 0x4ebb29: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ebb2b: { // 0x4ebb2b: 0f8595000000 JNZ 0x004ebbc6
    if(integer::condition("JNZ",flags)) goto L004ebbc6;
  }
  L004ebb31: { // 0x4ebb31: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004ebb36: { // 0x4ebb36: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ebb38: { // 0x4ebb38: 8a8634010000 MOV AL,byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  L004ebb3e: { // 0x4ebb3e: 7514 JNZ 0x004ebb54
    if(integer::condition("JNZ",flags)) goto L004ebb54;
  }
  L004ebb40: { // 0x4ebb40: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ebb42: { // 0x4ebb42: 750e JNZ 0x004ebb52
    if(integer::condition("JNZ",flags)) goto L004ebb52;
  }
  L004ebb44: { // 0x4ebb44: 8a8635010000 MOV AL,byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  L004ebb4a: { // 0x4ebb4a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ebb4c: { // 0x4ebb4c: 7504 JNZ 0x004ebb52
    if(integer::condition("JNZ",flags)) goto L004ebb52;
  }
  L004ebb4e: { // 0x4ebb4e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004ebb50: { // 0x4ebb50: eb02 JMP 0x004ebb54
    goto L004ebb54;
  }
  L004ebb52: { // 0x4ebb52: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004ebb54: { // 0x4ebb54: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ebb56: { // 0x4ebb56: 756e JNZ 0x004ebbc6
    if(integer::condition("JNZ",flags)) goto L004ebbc6;
  }
  L004ebb58: { // 0x4ebb58: c6869101000001 MOV byte ptr [ESI + 0x191],0x1
    m.w8((s.si+0x00000191u), 0x00000001u);
  }
  L004ebb5f: { // 0x4ebb5f: 8b0dd8a5a100 MOV ECX,dword ptr [0x00a1a5d8]
    s.cx = m.r32((0x00a1a5d8u));
  }
  L004ebb65: { // 0x4ebb65: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L004ebb67: { // 0x4ebb67: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ebb69: { // 0x4ebb69: 7e5b JLE 0x004ebbc6
    if(integer::condition("JLE",flags)) goto L004ebbc6;
  }
  L004ebb6b: { // 0x4ebb6b: 8b0dcca5a100 MOV ECX,dword ptr [0x00a1a5cc]
    s.cx = m.r32((0x00a1a5ccu));
  }
  L004ebb71: { // 0x4ebb71: 8b04b9 MOV EAX,dword ptr [ECX + EDI*0x4]
    s.ax = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L004ebb74: { // 0x4ebb74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ebb76: { // 0x4ebb76: 7443 JZ 0x004ebbbb
    if(integer::condition("JZ",flags)) goto L004ebbbb;
  }
  L004ebb78: { // 0x4ebb78: 8a883d010000 MOV CL,byte ptr [EAX + 0x13d]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000013du)));
  }
  L004ebb7e: { // 0x4ebb7e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ebb80: { // 0x4ebb80: 7539 JNZ 0x004ebbbb
    if(integer::condition("JNZ",flags)) goto L004ebbbb;
  }
  L004ebb82: { // 0x4ebb82: 8b0dc855a200 MOV ECX,dword ptr [0x00a255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L004ebb88: { // 0x4ebb88: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004ebb8a: { // 0x4ebb8a: 8a8834010000 MOV CL,byte ptr [EAX + 0x134]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000134u)));
  }
  L004ebb90: { // 0x4ebb90: 7514 JNZ 0x004ebba6
    if(integer::condition("JNZ",flags)) goto L004ebba6;
  }
  L004ebb92: { // 0x4ebb92: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ebb94: { // 0x4ebb94: 750e JNZ 0x004ebba4
    if(integer::condition("JNZ",flags)) goto L004ebba4;
  }
  L004ebb96: { // 0x4ebb96: 8a8835010000 MOV CL,byte ptr [EAX + 0x135]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000135u)));
  }
  L004ebb9c: { // 0x4ebb9c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ebb9e: { // 0x4ebb9e: 7504 JNZ 0x004ebba4
    if(integer::condition("JNZ",flags)) goto L004ebba4;
  }
  L004ebba0: { // 0x4ebba0: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L004ebba2: { // 0x4ebba2: eb02 JMP 0x004ebba6
    goto L004ebba6;
  }
  L004ebba4: { // 0x4ebba4: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L004ebba6: { // 0x4ebba6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ebba8: { // 0x4ebba8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ebbaa: { // 0x4ebbaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ebbab: { // 0x4ebbab: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ebbad: { // 0x4ebbad: 7407 JZ 0x004ebbb6
    if(integer::condition("JZ",flags)) goto L004ebbb6;
  }
  L004ebbaf: { // 0x4ebbaf: e85c95ffff CALL 0x004e5110
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e5110u,5159860u); flags=s.arithmetic_flags;
  }
  L004ebbb4: { // 0x4ebbb4: eb05 JMP 0x004ebbbb
    goto L004ebbbb;
  }
  L004ebbb6: { // 0x4ebbb6: e84591ffff CALL 0x004e4d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4d00u,5159867u); flags=s.arithmetic_flags;
  }
  L004ebbbb: { // 0x4ebbbb: 8b0dd8a5a100 MOV ECX,dword ptr [0x00a1a5d8]
    s.cx = m.r32((0x00a1a5d8u));
  }
  L004ebbc1: { // 0x4ebbc1: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L004ebbc2: { // 0x4ebbc2: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L004ebbc4: { // 0x4ebbc4: 7ca5 JL 0x004ebb6b
    if(integer::condition("JL",flags)) goto L004ebb6b;
  }
  L004ebbc6: { // 0x4ebbc6: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L004ebbc7: { // 0x4ebbc7: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L004ebbc9: { // 0x4ebbc9: 0f8c44ffffff JL 0x004ebb13
    if(integer::condition("JL",flags)) goto L004ebb13;
  }
  L004ebbcf: { // 0x4ebbcf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ebbd0: { // 0x4ebbd0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ebbd1: { // 0x4ebbd1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004ebbd2: { // 0x4ebbd2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004f2920(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f2920: { // 0x4f2920: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004f2921: { // 0x4f2921: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f2922: { // 0x4f2922: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L004f2924: { // 0x4f2924: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f2925: { // 0x4f2925: b904420000 MOV ECX,0x4204
    s.cx = 0x00004204u;
  }
  L004f292a: { // 0x4f292a: 8dbbd0560000 LEA EDI,[EBX + 0x56d0]
    s.di = (s.bx+0x000056d0u);
  }
  L004f2930: { // 0x4f2930: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f2932: { // 0x4f2932: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L004f2934: { // 0x4f2934: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L004f2939: { // 0x4f2939: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004f293a: { // 0x4f293a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f293c: { // 0x4f293c: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004f2940: { // 0x4f2940: 0f8c9b010000 JL 0x004f2ae1
    if(integer::condition("JL",flags)) goto L004f2ae1;
  }
  L004f2946: { // 0x4f2946: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f2947: { // 0x4f2947: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f2948: { // 0x4f2948: 8b0d6488a200 MOV ECX,dword ptr [0x00a28864]
    s.cx = m.r32((0x00a28864u));
  }
  L004f294e: { // 0x4f294e: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004f2951: { // 0x4f2951: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L004f2954: { // 0x4f2954: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f2956: { // 0x4f2956: 0f8574010000 JNZ 0x004f2ad0
    if(integer::condition("JNZ",flags)) goto L004f2ad0;
  }
  L004f295c: { // 0x4f295c: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L004f295f: { // 0x4f295f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f2961: { // 0x4f2961: 0f8469010000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f2967: { // 0x4f2967: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f2969: { // 0x4f2969: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f296b: { // 0x4f296b: ff92a0020000 CALL dword ptr [EDX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002a0u)),5187953u); flags=s.arithmetic_flags;
  }
  L004f2971: { // 0x4f2971: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004f2973: { // 0x4f2973: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004f2975: { // 0x4f2975: 0f8e55010000 JLE 0x004f2ad0
    if(integer::condition("JLE",flags)) goto L004f2ad0;
  }
  L004f297b: { // 0x4f297b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004f297d: { // 0x4f297d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f297f: { // 0x4f297f: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5187970u); flags=s.arithmetic_flags;
  }
  L004f2982: { // 0x4f2982: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L004f2985: { // 0x4f2985: 741c JZ 0x004f29a3
    if(integer::condition("JZ",flags)) goto L004f29a3;
  }
  L004f2987: { // 0x4f2987: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f2989: { // 0x4f2989: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f298b: { // 0x4f298b: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5187982u); flags=s.arithmetic_flags;
  }
  L004f298e: { // 0x4f298e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L004f2991: { // 0x4f2991: 7410 JZ 0x004f29a3
    if(integer::condition("JZ",flags)) goto L004f29a3;
  }
  L004f2993: { // 0x4f2993: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004f2995: { // 0x4f2995: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f2997: { // 0x4f2997: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5187994u); flags=s.arithmetic_flags;
  }
  L004f299a: { // 0x4f299a: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L004f299d: { // 0x4f299d: 0f85e0000000 JNZ 0x004f2a83
    if(integer::condition("JNZ",flags)) goto L004f2a83;
  }
  L004f29a3: { // 0x4f29a3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f29a5: { // 0x4f29a5: 0f84d8000000 JZ 0x004f2a83
    if(integer::condition("JZ",flags)) goto L004f2a83;
  }
  L004f29ab: { // 0x4f29ab: 668b8e54040000 MOV CX,word ptr [ESI + 0x454]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000454u)));
  }
  L004f29b2: { // 0x4f29b2: 8d8654040000 LEA EAX,[ESI + 0x454]
    s.ax = (s.si+0x00000454u);
  }
  L004f29b8: { // 0x4f29b8: 663b0d5c8ba200 CMP CX,word ptr [0x00a28b5c]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a28b5cu)),16,flags);
  }
  L004f29bf: { // 0x4f29bf: 7511 JNZ 0x004f29d2
    if(integer::condition("JNZ",flags)) goto L004f29d2;
  }
  L004f29c1: { // 0x4f29c1: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L004f29c5: { // 0x4f29c5: 663b155e8ba200 CMP DX,word ptr [0x00a28b5e]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a28b5eu)),16,flags);
  }
  L004f29cc: { // 0x4f29cc: 0f84fe000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f29d2: { // 0x4f29d2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f29d3: { // 0x4f29d3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004f29d8: { // 0x4f29d8: e8238e0500 CALL 0x0054b800
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054b800u,5188061u); flags=s.arithmetic_flags;
  }
  L004f29dd: { // 0x4f29dd: 8bb6b4010000 MOV ESI,dword ptr [ESI + 0x1b4]
    s.si = m.r32((s.si+0x000001b4u));
  }
  L004f29e3: { // 0x4f29e3: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004f29e5: { // 0x4f29e5: 0f84e5000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f29eb: { // 0x4f29eb: 8b0dc855a200 MOV ECX,dword ptr [0x00a255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  L004f29f1: { // 0x4f29f1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004f29f3: { // 0x4f29f3: 8a8b34010000 MOV CL,byte ptr [EBX + 0x134]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000134u)));
  }
  L004f29f9: { // 0x4f29f9: 7514 JNZ 0x004f2a0f
    if(integer::condition("JNZ",flags)) goto L004f2a0f;
  }
  L004f29fb: { // 0x4f29fb: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f29fd: { // 0x4f29fd: 750e JNZ 0x004f2a0d
    if(integer::condition("JNZ",flags)) goto L004f2a0d;
  }
  L004f29ff: { // 0x4f29ff: 8a8b35010000 MOV CL,byte ptr [EBX + 0x135]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000135u)));
  }
  L004f2a05: { // 0x4f2a05: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f2a07: { // 0x4f2a07: 7504 JNZ 0x004f2a0d
    if(integer::condition("JNZ",flags)) goto L004f2a0d;
  }
  L004f2a09: { // 0x4f2a09: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L004f2a0b: { // 0x4f2a0b: eb02 JMP 0x004f2a0f
    goto L004f2a0f;
  }
  L004f2a0d: { // 0x4f2a0d: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L004f2a0f: { // 0x4f2a0f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f2a11: { // 0x4f2a11: 7439 JZ 0x004f2a4c
    if(integer::condition("JZ",flags)) goto L004f2a4c;
  }
  L004f2a13: { // 0x4f2a13: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f2a15: { // 0x4f2a15: 7435 JZ 0x004f2a4c
    if(integer::condition("JZ",flags)) goto L004f2a4c;
  }
  L004f2a17: { // 0x4f2a17: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004f2a19: { // 0x4f2a19: 0f84b1000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f2a1f: { // 0x4f2a1f: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L004f2a22: { // 0x4f2a22: 8b5330 MOV EDX,dword ptr [EBX + 0x30]
    s.dx = m.r32((s.bx+0x00000030u));
  }
  L004f2a25: { // 0x4f2a25: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f2a27: { // 0x4f2a27: 0f84a3000000 JZ 0x004f2ad0
    if(integer::condition("JZ",flags)) goto L004f2ad0;
  }
  L004f2a2d: { // 0x4f2a2d: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004f2a30: { // 0x4f2a30: 741a JZ 0x004f2a4c
    if(integer::condition("JZ",flags)) goto L004f2a4c;
  }
  L004f2a32: { // 0x4f2a32: 8bb374560000 MOV ESI,dword ptr [EBX + 0x5674]
    s.si = m.r32((s.bx+0x00005674u));
  }
  L004f2a38: { // 0x4f2a38: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004f2a3d: { // 0x4f2a3d: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004f2a3f: { // 0x4f2a3f: 85f2 TEST EDX,ESI
    (void)integer::logical((s.dx)&(s.si),32,flags);
  }
  L004f2a41: { // 0x4f2a41: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004f2a44: { // 0x4f2a44: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f2a46: { // 0x4f2a46: 0f8584000000 JNZ 0x004f2ad0
    if(integer::condition("JNZ",flags)) goto L004f2ad0;
  }
  L004f2a4c: { // 0x4f2a4c: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f2a4e: { // 0x4f2a4e: bf09000000 MOV EDI,0x9
    s.di = 0x00000009u;
  }
  L004f2a53: { // 0x4f2a53: 8b8e64507c00 MOV ECX,dword ptr [ESI + 0x7c5064]
    s.cx = m.r32((s.si+0x007c5064u));
  }
  L004f2a59: { // 0x4f2a59: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L004f2a5b: { // 0x4f2a5b: d3fa SAR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L004f2a5d: { // 0x4f2a5d: 8b8e40507c00 MOV ECX,dword ptr [ESI + 0x7c5040]
    s.cx = m.r32((s.si+0x007c5040u));
  }
  L004f2a63: { // 0x4f2a63: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004f2a65: { // 0x4f2a65: 01948bd0560000 ADD dword ptr [EBX + ECX*0x4 + 0x56d0],EDX
    m.w32((s.bx+(s.cx * 0x00000004u)+0x000056d0u), integer::add(m.r32((s.bx+(s.cx * 0x00000004u)+0x000056d0u)),s.dx,32,flags));
  }
  L004f2a6c: { // 0x4f2a6c: 8d8c8bd0560000 LEA ECX,[EBX + ECX*0x4 + 0x56d0]
    s.cx = (s.bx+(s.cx * 0x00000004u)+0x000056d0u);
  }
  L004f2a73: { // 0x4f2a73: 7906 JNS 0x004f2a7b
    if(integer::condition("JNS",flags)) goto L004f2a7b;
  }
  L004f2a75: { // 0x4f2a75: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L004f2a7b: { // 0x4f2a7b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004f2a7e: { // 0x4f2a7e: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L004f2a7f: { // 0x4f2a7f: 75d2 JNZ 0x004f2a53
    if(integer::condition("JNZ",flags)) goto L004f2a53;
  }
  L004f2a81: { // 0x4f2a81: eb4d JMP 0x004f2ad0
    goto L004f2ad0;
  }
  L004f2a83: { // 0x4f2a83: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004f2a85: { // 0x4f2a85: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004f2a87: { // 0x4f2a87: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),5188237u); flags=s.arithmetic_flags;
  }
  L004f2a8d: { // 0x4f2a8d: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L004f2a90: { // 0x4f2a90: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004f2a95: { // 0x4f2a95: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f2a96: { // 0x4f2a96: e8658d0500 CALL 0x0054b800
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054b800u,5188251u); flags=s.arithmetic_flags;
  }
  L004f2a9b: { // 0x4f2a9b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004f2a9d: { // 0x4f2a9d: bf09000000 MOV EDI,0x9
    s.di = 0x00000009u;
  }
  L004f2aa2: { // 0x4f2aa2: 8b8e64507c00 MOV ECX,dword ptr [ESI + 0x7c5064]
    s.cx = m.r32((s.si+0x007c5064u));
  }
  L004f2aa8: { // 0x4f2aa8: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L004f2aaa: { // 0x4f2aaa: d3fa SAR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L004f2aac: { // 0x4f2aac: 8b8e40507c00 MOV ECX,dword ptr [ESI + 0x7c5040]
    s.cx = m.r32((s.si+0x007c5040u));
  }
  L004f2ab2: { // 0x4f2ab2: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004f2ab4: { // 0x4f2ab4: 01948bd0560000 ADD dword ptr [EBX + ECX*0x4 + 0x56d0],EDX
    m.w32((s.bx+(s.cx * 0x00000004u)+0x000056d0u), integer::add(m.r32((s.bx+(s.cx * 0x00000004u)+0x000056d0u)),s.dx,32,flags));
  }
  L004f2abb: { // 0x4f2abb: 8d8c8bd0560000 LEA ECX,[EBX + ECX*0x4 + 0x56d0]
    s.cx = (s.bx+(s.cx * 0x00000004u)+0x000056d0u);
  }
  L004f2ac2: { // 0x4f2ac2: 7906 JNS 0x004f2aca
    if(integer::condition("JNS",flags)) goto L004f2aca;
  }
  L004f2ac4: { // 0x4f2ac4: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L004f2aca: { // 0x4f2aca: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004f2acd: { // 0x4f2acd: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L004f2ace: { // 0x4f2ace: 75d2 JNZ 0x004f2aa2
    if(integer::condition("JNZ",flags)) goto L004f2aa2;
  }
  L004f2ad0: { // 0x4f2ad0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004f2ad4: { // 0x4f2ad4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004f2ad5: { // 0x4f2ad5: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004f2ad9: { // 0x4f2ad9: 0f8969feffff JNS 0x004f2948
    if(integer::condition("JNS",flags)) goto L004f2948;
  }
  L004f2adf: { // 0x4f2adf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f2ae0: { // 0x4f2ae0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f2ae1: { // 0x4f2ae1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f2ae2: { // 0x4f2ae2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f2ae3: { // 0x4f2ae3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004f2ae4: { // 0x4f2ae4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
