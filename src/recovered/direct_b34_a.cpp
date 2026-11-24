#include "recovered/direct_b34_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::direct_b34 {
namespace {
void f_000019a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4019a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4019a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4019a3: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  { // 0x4019a6: c706a0567800 MOV dword ptr [ESI],0x7856a0
    m.w32((s.si), 0x007856a0u);
  }
  { // 0x4019ac: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  { // 0x4019b3: e8d8680300 CALL 0x00438290
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4019b8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4019ba: c70658567800 MOV dword ptr [ESI],0x785658
    m.w32((s.si), 0x00785658u);
  }
  { // 0x4019c0: e88bd80200 CALL 0x0042f250
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4019c5: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4019ca: 7409 JZ 0x004019d5
    if(integer::condition("JZ",flags)) goto L004019d5;
  }
  { // 0x4019cc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4019cd: e8a9bc3600 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4019d2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004019d5: { // 0x4019d5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4019d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4019d8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000028b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4028b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4028b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4028b2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4028b4: 8bb7ac000000 MOV ESI,dword ptr [EDI + 0xac]
    s.si = m.r32((s.di+0x000000acu));
  }
  { // 0x4028ba: e8c14a0000 CALL 0x00407380
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4028bf: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  { // 0x4028c5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4028c6: 8986f0000000 MOV dword ptr [ESI + 0xf0],EAX
    m.w32((s.si+0x000000f0u), s.ax);
  }
  { // 0x4028cc: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  { // 0x4028d2: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4028d3: 898604010000 MOV dword ptr [ESI + 0x104],EAX
    m.w32((s.si+0x00000104u), s.ax);
  }
  { // 0x4028d9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4028db: e8a04a0000 CALL 0x00407380
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4028e0: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  { // 0x4028e6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4028e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4028e9: 898604010000 MOV dword ptr [ESI + 0x104],EAX
    m.w32((s.si+0x00000104u), s.ax);
  }
  { // 0x4028ef: 7d0a JGE 0x004028fb
    if(integer::condition("JGE",flags)) goto L004028fb;
  }
  { // 0x4028f1: c7860401000000000000 MOV dword ptr [ESI + 0x104],0x0
    m.w32((s.si+0x00000104u), 0x00000000u);
  }
  L004028fb: { // 0x4028fb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4028fc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4028fd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402940: 8b0df8787b00 MOV ECX,dword ptr [0x007b78f8]
    s.cx = m.r32((0x007b78f8u));
  }
  { // 0x402946: e8a5480000 CALL 0x004071f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x40294b: a1f8787b00 MOV EAX,[0x007b78f8]
    s.ax = m.r32((0x007b78f8u));
  }
  { // 0x402950: 8d480c LEA ECX,[EAX + 0xc]
    s.cx = (s.ax+0x0000000cu);
  }
  { // 0x402953: e898480000 CALL 0x004071f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x402958: 8b0df8787b00 MOV ECX,dword ptr [0x007b78f8]
    s.cx = m.r32((0x007b78f8u));
  }
  { // 0x40295e: c7411800000000 MOV dword ptr [ECX + 0x18],0x0
    m.w32((s.cx+0x00000018u), 0x00000000u);
  }
  { // 0x402965: 8b15f8787b00 MOV EDX,dword ptr [0x007b78f8]
    s.dx = m.r32((0x007b78f8u));
  }
  { // 0x40296b: 8d4a20 LEA ECX,[EDX + 0x20]
    s.cx = (s.dx+0x00000020u);
  }
  { // 0x40296e: 890d908e8100 MOV dword ptr [0x00818e90],ECX
    m.w32((0x00818e90u), s.cx);
  }
  { // 0x402974: e887e6ffff CALL 0x00401000
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x402979: c7058c8e810001000000 MOV dword ptr [0x00818e8c],0x1
    m.w32((0x00818e8cu), 0x00000001u);
  }
  { // 0x402983: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x402985: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000034b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4034b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4034b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4034b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4034b4: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  { // 0x4034ba: 8b8ef4000000 MOV ECX,dword ptr [ESI + 0xf4]
    s.cx = m.r32((s.si+0x000000f4u));
  }
  { // 0x4034c0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4034c2: 7d0d JGE 0x004034d1
    if(integer::condition("JGE",flags)) goto L004034d1;
  }
  { // 0x4034c4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4034c6: e875ebffff CALL 0x00402040
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4034cb: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4034cd: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4034cf: 7505 JNZ 0x004034d6
    if(integer::condition("JNZ",flags)) goto L004034d6;
  }
  L004034d1: { // 0x4034d1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4034d2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4034d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4034d5: c3 RET
    finish(m,s,f,0u); return;
  }
  L004034d6: { // 0x4034d6: 89b7ac000000 MOV dword ptr [EDI + 0xac],ESI
    m.w32((s.di+0x000000acu), s.si);
  }
  { // 0x4034dc: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  { // 0x4034e2: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4034e3: 8986f0000000 MOV dword ptr [ESI + 0xf0],EAX
    m.w32((s.si+0x000000f0u), s.ax);
  }
  { // 0x4034e9: 8b8e04010000 MOV ECX,dword ptr [ESI + 0x104]
    s.cx = m.r32((s.si+0x00000104u));
  }
  { // 0x4034ef: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x4034f0: 898e04010000 MOV dword ptr [ESI + 0x104],ECX
    m.w32((s.si+0x00000104u), s.cx);
  }
  { // 0x4034f6: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x4034f8: 8d8ef8000000 LEA ECX,[ESI + 0xf8]
    s.cx = (s.si+0x000000f8u);
  }
  { // 0x4034fe: e84d3e0000 CALL 0x00407350
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x403503: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  { // 0x403509: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x40350a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40350c: 898604010000 MOV dword ptr [ESI + 0x104],EAX
    m.w32((s.si+0x00000104u), s.ax);
  }
  { // 0x403512: 7d0a JGE 0x0040351e
    if(integer::condition("JGE",flags)) goto L0040351e;
  }
  { // 0x403514: c7860401000000000000 MOV dword ptr [ESI + 0x104],0x0
    m.w32((s.si+0x00000104u), 0x00000000u);
  }
  L0040351e: { // 0x40351e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x403520: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x403521: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x403522: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000036c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4036c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4036c1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4036c2: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x4036c4: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x4036c9: e822ffffff CALL 0x004035f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4036ce: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4036d0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4036d2: 7409 JZ 0x004036dd
    if(integer::condition("JZ",flags)) goto L004036dd;
  }
  { // 0x4036d4: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x4036d6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4036d8: e863edffff CALL 0x00402440
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L004036dd: { // 0x4036dd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4036df: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4036e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4036e1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00004db0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x404db0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x404db1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x404db3: e8c8250000 CALL 0x00407380
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x404db8: c7863801000000000000 MOV dword ptr [ESI + 0x138],0x0
    m.w32((s.si+0x00000138u), 0x00000000u);
  }
  { // 0x404dc2: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
  { // 0x404dc5: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  { // 0x404dc7: 7416 JZ 0x00404ddf
    if(integer::condition("JZ",flags)) goto L00404ddf;
  }
  { // 0x404dc9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x404dca: e8ac883600 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x404dcf: a1e4928100 MOV EAX,[0x008192e4]
    s.ax = m.r32((0x008192e4u));
  }
  { // 0x404dd4: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x404dd7: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x404dd8: a3e4928100 MOV [0x008192e4],EAX
    m.w32((0x008192e4u), s.ax);
  }
  { // 0x404ddd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x404dde: c3 RET
    finish(m,s,f,0u); return;
  }
  L00404ddf: { // 0x404ddf: 8b0d00938100 MOV ECX,dword ptr [0x00819300]
    s.cx = m.r32((0x00819300u));
  }
  { // 0x404de5: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x404de7: e874260000 CALL 0x00407460
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x404dec: a1e4928100 MOV EAX,[0x008192e4]
    s.ax = m.r32((0x008192e4u));
  }
  { // 0x404df1: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x404df2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x404df3: a3e4928100 MOV [0x008192e4],EAX
    m.w32((0x008192e4u), s.ax);
  }
  { // 0x404df8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000064b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4064b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4064b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4064b2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4064b4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x4064b6: 83bf3401000020 CMP dword ptr [EDI + 0x134],0x20
    (void)integer::sub(m.r32((s.di+0x00000134u)),0x00000020u,32,flags);
  }
  { // 0x4064bd: 7505 JNZ 0x004064c4
    if(integer::condition("JNZ",flags)) goto L004064c4;
  }
  { // 0x4064bf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4064c0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4064c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4064c3: c3 RET
    finish(m,s,f,0u); return;
  }
  L004064c4: { // 0x4064c4: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  { // 0x4064c9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4064cb: 745a JZ 0x00406527
    if(integer::condition("JZ",flags)) goto L00406527;
  }
  { // 0x4064cd: 8b0dec928100 MOV ECX,dword ptr [0x008192ec]
    s.cx = m.r32((0x008192ecu));
  }
  { // 0x4064d3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4064d5: 7450 JZ 0x00406527
    if(integer::condition("JZ",flags)) goto L00406527;
  }
  L004064d7: { // 0x4064d7: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  { // 0x4064d9: 3c24 CMP AL,0x24
    (void)integer::sub((s.ax & 0xffu),0x00000024u,8,flags);
  }
  { // 0x4064db: 7404 JZ 0x004064e1
    if(integer::condition("JZ",flags)) goto L004064e1;
  }
  { // 0x4064dd: 3c23 CMP AL,0x23
    (void)integer::sub((s.ax & 0xffu),0x00000023u,8,flags);
  }
  { // 0x4064df: 7503 JNZ 0x004064e4
    if(integer::condition("JNZ",flags)) goto L004064e4;
  }
  L004064e1: { // 0x4064e1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4064e2: ebf3 JMP 0x004064d7
    goto L004064d7;
  }
  L004064e4: { // 0x4064e4: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x4064e6: e8d5b0ffff CALL 0x004015c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4064eb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4064ee: 7422 JZ 0x00406512
    if(integer::condition("JZ",flags)) goto L00406512;
  }
  { // 0x4064f0: 8b8f34010000 MOV ECX,dword ptr [EDI + 0x134]
    s.cx = m.r32((s.di+0x00000134u));
  }
  { // 0x4064f6: 89848fb4000000 MOV dword ptr [EDI + ECX*0x4 + 0xb4],EAX
    m.w32((s.di+(s.cx * 0x00000004u)+0x000000b4u), s.ax);
  }
  { // 0x4064fd: 8b8734010000 MOV EAX,dword ptr [EDI + 0x134]
    s.ax = m.r32((s.di+0x00000134u));
  }
  { // 0x406503: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x406504: 898734010000 MOV dword ptr [EDI + 0x134],EAX
    m.w32((s.di+0x00000134u), s.ax);
  }
  { // 0x40650a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40650b: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x406510: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x406511: c3 RET
    finish(m,s,f,0u); return;
  }
  L00406512: { // 0x406512: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x406513: 68787c7b00 PUSH 0x7b7c78
    f.push(m,0x007b7c78u);
  }
  { // 0x406518: e8d3030000 CALL 0x004068f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x40651d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x406520: c7470c00000000 MOV dword ptr [EDI + 0xc],0x0
    m.w32((s.di+0x0000000cu), 0x00000000u);
  }
  L00406527: { // 0x406527: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x406528: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x40652d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40652e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000078f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4078f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4078f1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4078f2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4078f4: 8bb7c0000000 MOV ESI,dword ptr [EDI + 0xc0]
    s.si = m.r32((s.di+0x000000c0u));
  }
  { // 0x4078fa: 8b9690000000 MOV EDX,dword ptr [ESI + 0x90]
    s.dx = m.r32((s.si+0x00000090u));
  }
  { // 0x407900: 8b4e38 MOV ECX,dword ptr [ESI + 0x38]
    s.cx = m.r32((s.si+0x00000038u));
  }
  { // 0x407903: e8d8170000 CALL 0x004090e0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x407908: 8b4e38 MOV ECX,dword ptr [ESI + 0x38]
    s.cx = m.r32((s.si+0x00000038u));
  }
  { // 0x40790b: e820190000 CALL 0x00409230
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x407910: 8b4e38 MOV ECX,dword ptr [ESI + 0x38]
    s.cx = m.r32((s.si+0x00000038u));
  }
  { // 0x407913: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  { // 0x407919: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  { // 0x40791c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x40791e: 7e08 JLE 0x00407928
    if(integer::condition("JLE",flags)) goto L00407928;
  }
  { // 0x407920: 898e90000000 MOV dword ptr [ESI + 0x90],ECX
    m.w32((s.si+0x00000090u), s.cx);
  }
  { // 0x407926: eb06 JMP 0x0040792e
    goto L0040792e;
  }
  L00407928: { // 0x407928: 898690000000 MOV dword ptr [ESI + 0x90],EAX
    m.w32((s.si+0x00000090u), s.ax);
  }
  L0040792e: { // 0x40792e: 8b8690000000 MOV EAX,dword ptr [ESI + 0x90]
    s.ax = m.r32((s.si+0x00000090u));
  }
  { // 0x407934: 898774010000 MOV dword ptr [EDI + 0x174],EAX
    m.w32((s.di+0x00000174u), s.ax);
  }
  { // 0x40793a: 898778010000 MOV dword ptr [EDI + 0x178],EAX
    m.w32((s.di+0x00000178u), s.ax);
  }
  { // 0x407940: 8b5638 MOV EDX,dword ptr [ESI + 0x38]
    s.dx = m.r32((s.si+0x00000038u));
  }
  { // 0x407943: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  { // 0x407946: 898770010000 MOV dword ptr [EDI + 0x170],EAX
    m.w32((s.di+0x00000170u), s.ax);
  }
  { // 0x40794c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40794d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40794f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x407950: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408480: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408481: 8b7114 MOV ESI,dword ptr [ECX + 0x14]
    s.si = m.r32((s.cx+0x00000014u));
  }
  { // 0x408484: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x408486: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x408488: 7423 JZ 0x004084ad
    if(integer::condition("JZ",flags)) goto L004084ad;
  }
  { // 0x40848a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x40848b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x40848d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x40848e: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x408493: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x408494: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x408495: e866553600 CALL 0x0076da00
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x40849a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x40849c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x40849e: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x4084a0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4084a1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4084a2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4084a3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4084a4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4084a5: e8165a3600 CALL 0x0076dec0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4084aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4084ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4084ac: c3 RET
    finish(m,s,f,0u); return;
  }
  L004084ad: { // 0x4084ad: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4084af: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4084b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4084b2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00009210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x409210: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x409211: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x409213: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x409215: e8c6feffff CALL 0x004090e0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x40921a: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x40921d: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x40921f: 7407 JZ 0x00409228
    if(integer::condition("JZ",flags)) goto L00409228;
  }
  { // 0x409221: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x409223: e8b8feffff CALL 0x004090e0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L00409228: { // 0x409228: b800000480 MOV EAX,0x80040000
    s.ax = 0x80040000u;
  }
  { // 0x40922d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40922e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000101b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4101b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4101b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4101b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4101b4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4101b8: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x4101bb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4101bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4101be: e84d3b0800 CALL 0x00493d10
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4101c3: 8a4e20 MOV CL,byte ptr [ESI + 0x20]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000020u)));
  }
  { // 0x4101c6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4101c7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4101c9: e8923a0800 CALL 0x00493c60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4101ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4101cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4101d0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000106e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4106e0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4106e4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4106e5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4106e7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4106e8: e873f8ffff CALL 0x0040ff60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4106ed: 8a463d MOV AL,byte ptr [ESI + 0x3d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000003du)));
  }
  { // 0x4106f0: 8d4e3d LEA ECX,[ESI + 0x3d]
    s.cx = (s.si+0x0000003du);
  }
  { // 0x4106f3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4106f5: c706885e7800 MOV dword ptr [ESI],0x785e88
    m.w32((s.si), 0x00785e88u);
  }
  { // 0x4106fb: c746046c5e7800 MOV dword ptr [ESI + 0x4],0x785e6c
    m.w32((s.si+0x00000004u), 0x00785e6cu);
  }
  { // 0x410702: c74608645e7800 MOV dword ptr [ESI + 0x8],0x785e64
    m.w32((s.si+0x00000008u), 0x00785e64u);
  }
  { // 0x410709: c7460c5c5e7800 MOV dword ptr [ESI + 0xc],0x785e5c
    m.w32((s.si+0x0000000cu), 0x00785e5cu);
  }
  { // 0x410710: 7417 JZ 0x00410729
    if(integer::condition("JZ",flags)) goto L00410729;
  }
  { // 0x410712: 6a7f PUSH 0x7f
    f.push(m,0x0000007fu);
  }
  { // 0x410714: 6818927b00 PUSH 0x7b9218
    f.push(m,0x007b9218u);
  }
  { // 0x410719: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x41071b: e840e42d00 CALL 0x006eeb60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x410720: 894660 MOV dword ptr [ESI + 0x60],EAX
    m.w32((s.si+0x00000060u), s.ax);
  }
  { // 0x410723: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x410725: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x410726: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00410729: { // 0x410729: c746608c208200 MOV dword ptr [ESI + 0x60],0x82208c
    m.w32((s.si+0x00000060u), 0x0082208cu);
  }
  { // 0x410730: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x410732: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x410733: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00010910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x410910: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x410911: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x410915: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x410916: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x410918: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x410919: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x41091b: 8d7e24 LEA EDI,[ESI + 0x24]
    s.di = (s.si+0x00000024u);
  }
  { // 0x41091e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x410920: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x410921: e8caa40f00 CALL 0x0050adf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x410926: 8d4664 LEA EAX,[ESI + 0x64]
    s.ax = (s.si+0x00000064u);
  }
  { // 0x410929: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x41092b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41092c: 6834927b00 PUSH 0x7b9234
    f.push(m,0x007b9234u);
  }
  { // 0x410931: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x410932: e809d10f00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x410937: 8a4e3d MOV CL,byte ptr [ESI + 0x3d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000003du)));
  }
  { // 0x41093a: 8d463d LEA EAX,[ESI + 0x3d]
    s.ax = (s.si+0x0000003du);
  }
  { // 0x41093d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x41093f: 740e JZ 0x0041094f
    if(integer::condition("JZ",flags)) goto L0041094f;
  }
  { // 0x410941: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x410942: 682c927b00 PUSH 0x7b922c
    f.push(m,0x007b922cu);
  }
  { // 0x410947: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x410948: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x41094a: e8f1d00f00 CALL 0x0050da40
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L0041094f: { // 0x41094f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x410950: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x410951: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x410953: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x410954: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00010960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x410960: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x410961: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x410962: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x410966: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x410968: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x410969: e842f8ffff CALL 0x004101b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x41096e: 8d4624 LEA EAX,[ESI + 0x24]
    s.ax = (s.si+0x00000024u);
  }
  { // 0x410971: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x410973: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x410974: e8f7330800 CALL 0x00493d70
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x410979: 8d4e64 LEA ECX,[ESI + 0x64]
    s.cx = (s.si+0x00000064u);
  }
  { // 0x41097c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41097d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x41097f: e8ec330800 CALL 0x00493d70
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x410984: 83c63d ADD ESI,0x3d
    s.si = integer::add(s.si,0x0000003du,32,flags);
  }
  { // 0x410987: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x410989: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41098a: e8e1330800 CALL 0x00493d70
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x41098f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x410990: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x410991: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000113d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4113d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4113d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4113d3: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x4113d6: e8b56e0200 CALL 0x00438290
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4113db: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x4113df: c70620607800 MOV dword ptr [ESI],0x786020
    m.w32((s.si), 0x00786020u);
  }
  { // 0x4113e5: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4113e7: 7409 JZ 0x004113f2
    if(integer::condition("JZ",flags)) goto L004113f2;
  }
  { // 0x4113e9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4113ea: e88cc23500 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4113ef: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004113f2: { // 0x4113f2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4113f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4113f5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0001beb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41beb0: b9c4997b00 MOV ECX,0x7b99c4
    s.cx = 0x007b99c4u;
  }
  { // 0x41beb5: e806661700 CALL 0x005924c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x41beba: b9b8997b00 MOV ECX,0x7b99b8
    s.cx = 0x007b99b8u;
  }
  { // 0x41bebf: a39c488200 MOV [0x0082489c],EAX
    m.w32((0x0082489cu), s.ax);
  }
  { // 0x41bec4: e8f7651700 CALL 0x005924c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x41bec9: a3a0488200 MOV [0x008248a0],EAX
    m.w32((0x008248a0u), s.ax);
  }
  { // 0x41bece: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0001bed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41bed0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41bed1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41bed3: 68c0050000 PUSH 0x5c0
    f.push(m,0x000005c0u);
  }
  { // 0x41bed8: e87a1a3500 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x41bedd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x41bee0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41bee2: 7411 JZ 0x0041bef5
    if(integer::condition("JZ",flags)) goto L0041bef5;
  }
  { // 0x41bee4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x41bee8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41bee9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41beea: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x41beec: e84f7bffff CALL 0x00413a40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x41bef1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41bef2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0041bef5: { // 0x41bef5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x41bef7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41bef8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00022ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x422ba0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x422ba3: 0fbf02 MOVSX EAX,word ptr [EDX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  { // 0x422ba6: 0fbf4a02 MOVSX ECX,word ptr [EDX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  { // 0x422baa: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x422bad: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  { // 0x422bb2: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  { // 0x422bba: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x422bbd: 89442400 MOV dword ptr [ESP],EAX
    m.w32((f.sp), s.ax);
  }
  { // 0x422bc1: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x422bc6: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  { // 0x422bcc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x422bce: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x422bd2: 8b90600c0000 MOV EDX,dword ptr [EAX + 0xc60]
    s.dx = m.r32((s.ax+0x00000c60u));
  }
  { // 0x422bd8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x422bd9: 8b9090110000 MOV EDX,dword ptr [EAX + 0x1190]
    s.dx = m.r32((s.ax+0x00001190u));
  }
  { // 0x422bdf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x422be1: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x422be5: e8d6b20500 CALL 0x0047dec0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x422bea: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x422bef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x422bf1: 7514 JNZ 0x00422c07
    if(integer::condition("JNZ",flags)) goto L00422c07;
  }
  { // 0x422bf3: 68e0214800 PUSH 0x4821e0
    f.push(m,0x004821e0u);
  }
  { // 0x422bf8: ba1e000000 MOV EDX,0x1e
    s.dx = 0x0000001eu;
  }
  { // 0x422bfd: b950018200 MOV ECX,0x820150
    s.cx = 0x00820150u;
  }
  { // 0x422c02: e8a9270700 CALL 0x004953b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L00422c07: { // 0x422c07: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x422c0a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00026700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x426700: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x426701: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x426703: 8a861a030000 MOV AL,byte ptr [ESI + 0x31a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000031au)));
  }
  { // 0x426709: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42670b: 7442 JZ 0x0042674f
    if(integer::condition("JZ",flags)) goto L0042674f;
  }
  { // 0x42670d: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x426713: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x426715: 7438 JZ 0x0042674f
    if(integer::condition("JZ",flags)) goto L0042674f;
  }
  { // 0x426717: 8a861b030000 MOV AL,byte ptr [ESI + 0x31b]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000031bu)));
  }
  { // 0x42671d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42671f: 742e JZ 0x0042674f
    if(integer::condition("JZ",flags)) goto L0042674f;
  }
  { // 0x426721: 8d4664 LEA EAX,[ESI + 0x64]
    s.ax = (s.si+0x00000064u);
  }
  { // 0x426724: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x426725: 68c49f7b00 PUSH 0x7b9fc4
    f.push(m,0x007b9fc4u);
  }
  { // 0x42672a: e8c101feff CALL 0x004068f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x42672f: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  { // 0x426735: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x426736: e8406f3400 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x42673b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x42673e: c786a400000000000000 MOV dword ptr [ESI + 0xa4],0x0
    m.w32((s.si+0x000000a4u), 0x00000000u);
  }
  { // 0x426748: c686a800000000 MOV byte ptr [ESI + 0xa8],0x0
    m.w8((s.si+0x000000a8u), 0x00000000u);
  }
  L0042674f: { // 0x42674f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x426750: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0002b800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42b800: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42b801: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42b803: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42b804: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x42b806: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  { // 0x42b809: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x42b80b: 7437 JZ 0x0042b844
    if(integer::condition("JZ",flags)) goto L0042b844;
  }
  { // 0x42b80d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x42b810: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42b812: 7510 JNZ 0x0042b824
    if(integer::condition("JNZ",flags)) goto L0042b824;
  }
  { // 0x42b814: 8d7e14 LEA EDI,[ESI + 0x14]
    s.di = (s.si+0x00000014u);
  }
  { // 0x42b817: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x42b819: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42b81a: 8d4e18 LEA ECX,[ESI + 0x18]
    s.cx = (s.si+0x00000018u);
  }
  { // 0x42b81d: e8fe1c0000 CALL 0x0042d520
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x42b822: eb0e JMP 0x0042b832
    goto L0042b832;
  }
  L0042b824: { // 0x42b824: 8d7e18 LEA EDI,[ESI + 0x18]
    s.di = (s.si+0x00000018u);
  }
  { // 0x42b827: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x42b829: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42b82a: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x42b82d: e80e1e0000 CALL 0x0042d640
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L0042b832: { // 0x42b832: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42b833: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42b834: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42b836: e895ae1d00 CALL 0x006066d0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x42b83b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x42b83d: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  L0042b844: { // 0x42b844: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42b846: e8a5ae1d00 CALL 0x006066f0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x42b84b: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x42b84d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42b84e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42b84f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0002c000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42c000: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42c001: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x42c005: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42c006: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x42c008: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42c009: e892000000 CALL 0x0042c0a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x42c00e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42c010: 7407 JZ 0x0042c019
    if(integer::condition("JZ",flags)) goto L0042c019;
  }
  { // 0x42c012: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42c013: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x42c015: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42c016: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0042c019: { // 0x42c019: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x42c01c: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x42c01f: 8d0c06 LEA ECX,[ESI + EAX*0x1]
    s.cx = (s.si+(s.ax * 0x00000001u));
  }
  { // 0x42c022: 8b0406 MOV EAX,dword ptr [ESI + EAX*0x1]
    s.ax = m.r32((s.si+(s.ax * 0x00000001u)));
  }
  { // 0x42c025: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42c027: 7c4b JL 0x0042c074
    if(integer::condition("JL",flags)) goto L0042c074;
  }
  { // 0x42c029: 8b150ce0a100 MOV EDX,dword ptr [0x00a1e00c]
    s.dx = m.r32((0x00a1e00cu));
  }
  { // 0x42c02f: 8b3482 MOV ESI,dword ptr [EDX + EAX*0x4]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x42c032: 8a8615120000 MOV AL,byte ptr [ESI + 0x1215]
    s.ax = with_al(s.ax, m.r8((s.si+0x00001215u)));
  }
  { // 0x42c038: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42c03a: 7438 JZ 0x0042c074
    if(integer::condition("JZ",flags)) goto L0042c074;
  }
  { // 0x42c03c: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x42c03f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x42c040: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x42c045: e8b6941100 CALL 0x00545500
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x42c04a: 8b8eec0b0000 MOV ECX,dword ptr [ESI + 0xbec]
    s.cx = m.r32((s.si+0x00000becu));
  }
  { // 0x42c050: 8b5044 MOV EDX,dword ptr [EAX + 0x44]
    s.dx = m.r32((s.ax+0x00000044u));
  }
  { // 0x42c053: 3b9164020000 CMP EDX,dword ptr [ECX + 0x264]
    (void)integer::sub(s.dx,m.r32((s.cx+0x00000264u)),32,flags);
  }
  { // 0x42c059: 7507 JNZ 0x0042c062
    if(integer::condition("JNZ",flags)) goto L0042c062;
  }
  { // 0x42c05b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42c05c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x42c05e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42c05f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0042c062: { // 0x42c062: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x42c064: e847530400 CALL 0x004713b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x42c069: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42c06b: 7407 JZ 0x0042c074
    if(integer::condition("JZ",flags)) goto L0042c074;
  }
  { // 0x42c06d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42c06e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x42c070: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42c071: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0042c074: { // 0x42c074: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42c075: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x42c077: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42c078: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0002ca50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42ca50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42ca51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42ca53: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42ca54: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x42ca56: 8d7e04 LEA EDI,[ESI + 0x4]
    s.di = (s.si+0x00000004u);
  }
  { // 0x42ca59: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x42ca5b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x42ca5d: e8ce090000 CALL 0x0042d430
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x42ca62: c707c0757800 MOV dword ptr [EDI],0x7875c0
    m.w32((s.di), 0x007875c0u);
  }
  { // 0x42ca68: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  { // 0x42ca6f: c7471000000000 MOV dword ptr [EDI + 0x10],0x0
    m.w32((s.di+0x00000010u), 0x00000000u);
  }
  { // 0x42ca76: 8d7e20 LEA EDI,[ESI + 0x20]
    s.di = (s.si+0x00000020u);
  }
  { // 0x42ca79: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x42ca7b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x42ca7d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x42ca7f: e81c0a0000 CALL 0x0042d4a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x42ca84: c707a0757800 MOV dword ptr [EDI],0x7875a0
    m.w32((s.di), 0x007875a0u);
  }
  { // 0x42ca8a: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  { // 0x42ca91: c7471000000000 MOV dword ptr [EDI + 0x10],0x0
    m.w32((s.di+0x00000010u), 0x00000000u);
  }
  { // 0x42ca98: 8d7e38 LEA EDI,[ESI + 0x38]
    s.di = (s.si+0x00000038u);
  }
  { // 0x42ca9b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x42ca9d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x42ca9f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x42caa1: e8fa090000 CALL 0x0042d4a0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x42caa6: c707a0757800 MOV dword ptr [EDI],0x7875a0
    m.w32((s.di), 0x007875a0u);
  }
  { // 0x42caac: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  { // 0x42cab3: c7471000000000 MOV dword ptr [EDI + 0x10],0x0
    m.w32((s.di+0x00000010u), 0x00000000u);
  }
  { // 0x42caba: c70690757800 MOV dword ptr [ESI],0x787590
    m.w32((s.si), 0x00787590u);
  }
  { // 0x42cac0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42cac2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42cac3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42cac4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0002e080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42e080: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42e081: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42e083: f6460c01 TEST byte ptr [ESI + 0xc],0x1
    (void)integer::logical((m.r8((s.si+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x42e087: 7438 JZ 0x0042e0c1
    if(integer::condition("JZ",flags)) goto L0042e0c1;
  }
  { // 0x42e089: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    s.ax = m.r32((s.si+0x00000110u));
  }
  { // 0x42e08f: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x42e095: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42e096: e8056b0b00 CALL 0x004e4ba0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x42e09b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42e09d: 7422 JZ 0x0042e0c1
    if(integer::condition("JZ",flags)) goto L0042e0c1;
  }
  { // 0x42e09f: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x42e0a5: 8b9610010000 MOV EDX,dword ptr [ESI + 0x110]
    s.dx = m.r32((s.si+0x00000110u));
  }
  { // 0x42e0ab: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  { // 0x42e0b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x42e0b1: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x42e0b4: e8276b0b00 CALL 0x004e4be0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x42e0b9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42e0bb: 7404 JZ 0x0042e0c1
    if(integer::condition("JZ",flags)) goto L0042e0c1;
  }
  { // 0x42e0bd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x42e0bf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42e0c0: c3 RET
    finish(m,s,f,0u); return;
  }
  L0042e0c1: { // 0x42e0c1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x42e0c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42e0c4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0002f250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42f250: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x42f251: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42f252: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42f254: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x42f256: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x42f259: c7063c777800 MOV dword ptr [ESI],0x78773c
    m.w32((s.si), 0x0078773cu);
  }
  { // 0x42f25f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x42f261: 7414 JZ 0x0042f277
    if(integer::condition("JZ",flags)) goto L0042f277;
  }
  { // 0x42f263: 385e20 CMP byte ptr [ESI + 0x20],BL
    (void)integer::sub(m.r8((s.si+0x00000020u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x42f266: 740c JZ 0x0042f274
    if(integer::condition("JZ",flags)) goto L0042f274;
  }
  { // 0x42f268: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42f269: e80de43300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x42f26e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x42f271: 885e20 MOV byte ptr [ESI + 0x20],BL
    m.w8((s.si+0x00000020u), (s.bx & 0xffu));
  }
  L0042f274: { // 0x42f274: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L0042f277: { // 0x42f277: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42f279: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  { // 0x42f27c: 885e21 MOV byte ptr [ESI + 0x21],BL
    m.w8((s.si+0x00000021u), (s.bx & 0xffu));
  }
  { // 0x42f27f: 885e23 MOV byte ptr [ESI + 0x23],BL
    m.w8((s.si+0x00000023u), (s.bx & 0xffu));
  }
  { // 0x42f282: 885e24 MOV byte ptr [ESI + 0x24],BL
    m.w8((s.si+0x00000024u), (s.bx & 0xffu));
  }
  { // 0x42f285: 885e25 MOV byte ptr [ESI + 0x25],BL
    m.w8((s.si+0x00000025u), (s.bx & 0xffu));
  }
  { // 0x42f288: e8d30d2000 CALL 0x00630060
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x42f28d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42f28e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x42f28f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0002fcf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42fcf0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x42fcf1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42fcf2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42fcf4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x42fcf6: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x42fcf9: c7063c777800 MOV dword ptr [ESI],0x78773c
    m.w32((s.si), 0x0078773cu);
  }
  { // 0x42fcff: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x42fd01: 7414 JZ 0x0042fd17
    if(integer::condition("JZ",flags)) goto L0042fd17;
  }
  { // 0x42fd03: 385e20 CMP byte ptr [ESI + 0x20],BL
    (void)integer::sub(m.r8((s.si+0x00000020u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x42fd06: 740c JZ 0x0042fd14
    if(integer::condition("JZ",flags)) goto L0042fd14;
  }
  { // 0x42fd08: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42fd09: e86dd93300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x42fd0e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x42fd11: 885e20 MOV byte ptr [ESI + 0x20],BL
    m.w8((s.si+0x00000020u), (s.bx & 0xffu));
  }
  L0042fd14: { // 0x42fd14: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  L0042fd17: { // 0x42fd17: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42fd19: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  { // 0x42fd1c: 885e21 MOV byte ptr [ESI + 0x21],BL
    m.w8((s.si+0x00000021u), (s.bx & 0xffu));
  }
  { // 0x42fd1f: 885e23 MOV byte ptr [ESI + 0x23],BL
    m.w8((s.si+0x00000023u), (s.bx & 0xffu));
  }
  { // 0x42fd22: 885e24 MOV byte ptr [ESI + 0x24],BL
    m.w8((s.si+0x00000024u), (s.bx & 0xffu));
  }
  { // 0x42fd25: 885e25 MOV byte ptr [ESI + 0x25],BL
    m.w8((s.si+0x00000025u), (s.bx & 0xffu));
  }
  { // 0x42fd28: e833032000 CALL 0x00630060
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x42fd2d: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x42fd32: 7409 JZ 0x0042fd3d
    if(integer::condition("JZ",flags)) goto L0042fd3d;
  }
  { // 0x42fd34: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42fd35: e841d93300 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x42fd3a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042fd3d: { // 0x42fd3d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42fd3f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42fd40: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x42fd41: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00030fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x430fc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x430fc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x430fc3: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x430fc6: c70688777800 MOV dword ptr [ESI],0x787788
    m.w32((s.si), 0x00787788u);
  }
  { // 0x430fcc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x430fce: 7409 JZ 0x00430fd9
    if(integer::condition("JZ",flags)) goto L00430fd9;
  }
  { // 0x430fd0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x430fd1: e852cf3300 CALL 0x0076df28
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x430fd6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00430fd9: { // 0x430fd9: 8b7604 MOV ESI,dword ptr [ESI + 0x4]
    s.si = m.r32((s.si+0x00000004u));
  }
  { // 0x430fdc: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x430fde: 7429 JZ 0x00431009
    if(integer::condition("JZ",flags)) goto L00431009;
  }
  { // 0x430fe0: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x430fe3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x430fe5: 7409 JZ 0x00430ff0
    if(integer::condition("JZ",flags)) goto L00430ff0;
  }
  { // 0x430fe7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x430fe8: e88ec63300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x430fed: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00430ff0: { // 0x430ff0: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x430ff3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x430ff5: 7409 JZ 0x00431000
    if(integer::condition("JZ",flags)) goto L00431000;
  }
  { // 0x430ff7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x430ff8: e87ec63300 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x430ffd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00431000: { // 0x431000: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x431001: e875c63300 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x431006: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00431009: { // 0x431009: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43100a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000312b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4312b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4312b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4312b3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4312b7: e854fdffff CALL 0x00431010
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4312bc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4312be: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x4312c1: 7419 JZ 0x004312dc
    if(integer::condition("JZ",flags)) goto L004312dc;
  }
  { // 0x4312c3: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x4312c6: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  { // 0x4312c9: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x4312cc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4312ce: 89561c MOV dword ptr [ESI + 0x1c],EDX
    m.w32((s.si+0x0000001cu), s.dx);
  }
  { // 0x4312d1: e8aa0a0000 CALL 0x00431d80
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4312d6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4312d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4312d9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004312dc: { // 0x4312dc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4312de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4312df: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00031570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x431570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x431571: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x431573: 8a4640 MOV AL,byte ptr [ESI + 0x40]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000040u)));
  }
  { // 0x431576: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x431578: 742e JZ 0x004315a8
    if(integer::condition("JZ",flags)) goto L004315a8;
  }
  { // 0x43157a: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x43157e: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x431582: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x431583: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x431587: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x431589: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x43158a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x43158b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x43158d: c7462c02000000 MOV dword ptr [ESI + 0x2c],0x2
    m.w32((s.si+0x0000002cu), 0x00000002u);
  }
  { // 0x431594: e8d7fdffff CALL 0x00431370
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x431599: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x43159d: c7462c01000000 MOV dword ptr [ESI + 0x2c],0x1
    m.w32((s.si+0x0000002cu), 0x00000001u);
  }
  { // 0x4315a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4315a5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004315a8: { // 0x4315a8: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4315ac: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4315b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4315b1: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x4315b5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4315b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4315b8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4315b9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4315bb: e8b0fdffff CALL 0x00431370
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4315c0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4315c4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4315c5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00031720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x431720: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x431721: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x431723: 8a4640 MOV AL,byte ptr [ESI + 0x40]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000040u)));
  }
  { // 0x431726: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x431728: 742d JZ 0x00431757
    if(integer::condition("JZ",flags)) goto L00431757;
  }
  { // 0x43172a: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x43172e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x431732: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x431736: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x431737: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x43173b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x43173c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x43173d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x43173e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x431740: c7462c02000000 MOV dword ptr [ESI + 0x2c],0x2
    m.w32((s.si+0x0000002cu), 0x00000002u);
  }
  { // 0x431747: e824fcffff CALL 0x00431370
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x43174c: c7462c01000000 MOV dword ptr [ESI + 0x2c],0x1
    m.w32((s.si+0x0000002cu), 0x00000001u);
  }
  { // 0x431753: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x431754: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L00431757: { // 0x431757: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x43175b: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x43175f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x431763: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x431764: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x431768: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x431769: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x43176a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x43176b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x43176d: e8fefbffff CALL 0x00431370
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x431772: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x431773: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_00032150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x432150: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x432151: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x432153: 6a44 PUSH 0x44
    f.push(m,0x00000044u);
  }
  { // 0x432155: c70690777800 MOV dword ptr [ESI],0x787790
    m.w32((s.si), 0x00787790u);
  }
  { // 0x43215b: e8f7b73300 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x432160: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x432163: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x432165: 7415 JZ 0x0043217c
    if(integer::condition("JZ",flags)) goto L0043217c;
  }
  { // 0x432167: 68d0a47b00 PUSH 0x7ba4d0
    f.push(m,0x007ba4d0u);
  }
  { // 0x43216c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x43216e: e88dedffff CALL 0x00430f00
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x432173: a3306d8300 MOV [0x00836d30],EAX
    m.w32((0x00836d30u), s.ax);
  }
  { // 0x432178: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x43217a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43217b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0043217c: { // 0x43217c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x43217e: c705306d830000000000 MOV dword ptr [0x00836d30],0x0
    m.w32((0x00836d30u), 0x00000000u);
  }
  { // 0x432188: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x432189: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00032210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x432210: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x432211: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x432215: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x432216: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x43221a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x43221c: 7443 JZ 0x00432261
    if(integer::condition("JZ",flags)) goto L00432261;
  }
  { // 0x43221e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x43221f: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x432223: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x432224: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x432226: e845fdffff CALL 0x00431f70
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x43222b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x43222c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x43222e: e85df5ffff CALL 0x00431790
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x432233: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x432237: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  { // 0x43223b: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x43223f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432240: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x432244: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x432245: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x432246: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x432247: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432248: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x43224a: e831f9ffff CALL 0x00431b80
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x43224f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x432250: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x432252: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x432254: e8b7fdffff CALL 0x00432010
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x432259: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x43225b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x43225c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x43225d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43225e: c21c00 RET 0x1c
    finish(m,s,f,28u); return;
  }
  L00432261: { // 0x432261: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x432263: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x432264: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x432265: c21c00 RET 0x1c
    finish(m,s,f,28u); return;
  }
}
void f_00034680(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x434680: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x434681: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x434683: e808771900 CALL 0x005cbd90
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x434688: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x43468a: 740f JZ 0x0043469b
    if(integer::condition("JZ",flags)) goto L0043469b;
  }
  { // 0x43468c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x43468d: b9b0a78100 MOV ECX,0x81a7b0
    s.cx = 0x0081a7b0u;
  }
  { // 0x434692: e8b97e1000 CALL 0x0053c550
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x434697: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x434699: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43469a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0043469b: { // 0x43469b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x43469d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43469e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00035550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x435550: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x435551: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x435553: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x435554: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x435556: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x435559: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x43555b: 7e15 JLE 0x00435572
    if(integer::condition("JLE",flags)) goto L00435572;
  }
  { // 0x43555d: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x435560: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x435562: 740e JZ 0x00435572
    if(integer::condition("JZ",flags)) goto L00435572;
  }
  { // 0x435564: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435565: 8d4610 LEA EAX,[ESI + 0x10]
    s.ax = (s.si+0x00000010u);
  }
  { // 0x435568: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435569: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x43556b: e860111d00 CALL 0x006066d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x435570: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00435572: { // 0x435572: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x435574: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x43557b: e870111d00 CALL 0x006066f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x435580: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x435582: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x435583: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x435584: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000356c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4356c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4356c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4356c3: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x4356c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4356c8: 751c JNZ 0x004356e6
    if(integer::condition("JNZ",flags)) goto L004356e6;
  }
  { // 0x4356ca: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4356cc: e886823300 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4356d1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4356d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4356d6: 7409 JZ 0x004356e1
    if(integer::condition("JZ",flags)) goto L004356e1;
  }
  { // 0x4356d8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4356da: e861fdffff CALL 0x00435440
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4356df: eb02 JMP 0x004356e3
    goto L004356e3;
  }
  L004356e1: { // 0x4356e1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004356e3: { // 0x4356e3: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L004356e6: { // 0x4356e6: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x4356e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4356ea: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4356ec: 740f JZ 0x004356fd
    if(integer::condition("JZ",flags)) goto L004356fd;
  }
  { // 0x4356ee: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4356f2: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4356f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4356f7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4356f8: e8c3fdffff CALL 0x004354c0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L004356fd: { // 0x4356fd: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000357f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4357f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4357f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4357f3: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x4357f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4357f8: 751c JNZ 0x00435816
    if(integer::condition("JNZ",flags)) goto L00435816;
  }
  { // 0x4357fa: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4357fc: e856813300 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x435801: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x435804: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x435806: 7409 JZ 0x00435811
    if(integer::condition("JZ",flags)) goto L00435811;
  }
  { // 0x435808: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x43580a: e831fcffff CALL 0x00435440
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x43580f: eb02 JMP 0x00435813
    goto L00435813;
  }
  L00435811: { // 0x435811: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00435813: { // 0x435813: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00435816: { // 0x435816: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x435819: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43581a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x43581c: 740f JZ 0x0043582d
    if(integer::condition("JZ",flags)) goto L0043582d;
  }
  { // 0x43581e: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x435822: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x435826: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435827: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x435828: e893fcffff CALL 0x004354c0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L0043582d: { // 0x43582d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00043e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x443e10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x443e11: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x443e12: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x443e14: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x443e16: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  { // 0x443e1c: e89f470100 CALL 0x004585c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x443e21: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  { // 0x443e27: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x443e29: c1e607 SHL ESI,0x7
    s.si = integer::shift(s.si,0x00000007u,32,flags,integer::Shift::left);
  }
  { // 0x443e2c: 81ee80000000 SUB ESI,0x80
    s.si = integer::sub(s.si,0x00000080u,32,flags);
  }
  { // 0x443e32: e879470100 CALL 0x004585b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x443e37: 81c788000000 ADD EDI,0x88
    s.di = integer::add(s.di,0x00000088u,32,flags);
  }
  { // 0x443e3d: c1e007 SHL EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::left);
  }
  { // 0x443e40: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x443e42: 2d80000000 SUB EAX,0x80
    s.ax = integer::sub(s.ax,0x00000080u,32,flags);
  }
  { // 0x443e47: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x443e49: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x443e4d: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x443e50: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  { // 0x443e52: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x443e54: 8b7f08 MOV EDI,dword ptr [EDI + 0x8]
    s.di = m.r32((s.di+0x00000008u));
  }
  { // 0x443e57: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  { // 0x443e59: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  { // 0x443e5c: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  { // 0x443e5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x443e60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x443e61: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00049ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x449ca0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x449ca1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x449ca3: 8a86b3050000 MOV AL,byte ptr [ESI + 0x5b3]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005b3u)));
  }
  { // 0x449ca9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x449cab: 7536 JNZ 0x00449ce3
    if(integer::condition("JNZ",flags)) goto L00449ce3;
  }
  { // 0x449cad: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x449cb2: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  { // 0x449cb4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x449cb6: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  { // 0x449cbc: e87f611e00 CALL 0x0062fe40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x449cc1: 83f819 CMP EAX,0x19
    (void)integer::sub(s.ax,0x00000019u,32,flags);
  }
  { // 0x449cc4: 7d1d JGE 0x00449ce3
    if(integer::condition("JGE",flags)) goto L00449ce3;
  }
  { // 0x449cc6: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  { // 0x449ccc: 83b9440c000007 CMP dword ptr [ECX + 0xc44],0x7
    (void)integer::sub(m.r32((s.cx+0x00000c44u)),0x00000007u,32,flags);
  }
  { // 0x449cd3: 750e JNZ 0x00449ce3
    if(integer::condition("JNZ",flags)) goto L00449ce3;
  }
  { // 0x449cd5: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  { // 0x449cdb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x449cdc: 8b82480c0000 MOV EAX,dword ptr [EDX + 0xc48]
    s.ax = m.r32((s.dx+0x00000c48u));
  }
  { // 0x449ce2: c3 RET
    finish(m,s,f,0u); return;
  }
  L00449ce3: { // 0x449ce3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x449ce5: e836e92700 CALL 0x006c8620
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x449cea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x449ceb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00053700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x453700: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x453701: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x453703: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x453704: 8dbe94020000 LEA EDI,[ESI + 0x294]
    s.di = (s.si+0x00000294u);
  }
  { // 0x45370a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x45370c: e89fcd2300 CALL 0x006904b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x453711: e83a733100 CALL 0x0076aa50
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x453716: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x453718: 7503 JNZ 0x0045371d
    if(integer::condition("JNZ",flags)) goto L0045371d;
  }
  { // 0x45371a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x45371b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45371c: c3 RET
    finish(m,s,f,0u); return;
  }
  L0045371d: { // 0x45371d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x45371f: e88ccd2300 CALL 0x006904b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x453724: e827733100 CALL 0x0076aa50
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x453729: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  { // 0x45372f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x453730: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x453733: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x453734: f7b9fc060000 IDIV dword ptr [ECX + 0x6fc]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.cx+0x000006fcu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x45373a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45373b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00058120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x458120: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x458121: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x458123: 68e0050000 PUSH 0x5e0
    f.push(m,0x000005e0u);
  }
  { // 0x458128: e82a583100 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x45812d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x458130: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x458132: 7411 JZ 0x00458145
    if(integer::condition("JZ",flags)) goto L00458145;
  }
  { // 0x458134: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x458138: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x458139: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x45813a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x45813c: e81f0afeff CALL 0x00438b60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x458141: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458142: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00458145: { // 0x458145: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x458147: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458148: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00068b70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468b70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468b71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468b73: e8186e0000 CALL 0x0046f990
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x468b78: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468b7a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468b7c: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  { // 0x468b7f: e8bcf5fcff CALL 0x00438140
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x468b84: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x468b88: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468b8a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x468b8b: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  { // 0x468b92: c706a0567800 MOV dword ptr [ESI],0x7856a0
    m.w32((s.si), 0x007856a0u);
  }
  { // 0x468b98: e8b3710000 CALL 0x0046fd50
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x468b9d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x468b9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468ba0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00068bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468bb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468bb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468bb3: e8d86d0000 CALL 0x0046f990
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x468bb8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468bba: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468bbc: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  { // 0x468bbf: e87cf5fcff CALL 0x00438140
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x468bc4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x468bc8: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  { // 0x468bcf: c706a0567800 MOV dword ptr [ESI],0x7856a0
    m.w32((s.si), 0x007856a0u);
  }
  { // 0x468bd5: e896142f00 CALL 0x0075a070
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x468bda: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x468bdb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468bdd: e86e710000 CALL 0x0046fd50
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x468be2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x468be4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468be5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00068bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468bf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468bf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468bf3: e8986d0000 CALL 0x0046f990
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x468bf8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468bfa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468bfc: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  { // 0x468bff: e83cf5fcff CALL 0x00438140
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x468c04: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  { // 0x468c0b: c706a0567800 MOV dword ptr [ESI],0x7856a0
    m.w32((s.si), 0x007856a0u);
  }
  { // 0x468c11: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x468c13: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468c14: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00068e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468e10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468e11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468e13: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  { // 0x468e16: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x468e18: 7409 JZ 0x00468e23
    if(integer::condition("JZ",flags)) goto L00468e23;
  }
  { // 0x468e1a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468e1c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468e1e: e81df3fcff CALL 0x00438140
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L00468e23: { // 0x468e23: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468e25: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  { // 0x468e2c: e86f6efcff CALL 0x0042fca0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x468e31: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468e32: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00069ac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469ac0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x469ac3: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x469ac7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x469ac8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x469aca: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  { // 0x469ace: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x469ad0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469ad1: e80af0ffff CALL 0x00468ae0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x469ad6: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  { // 0x469ada: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  { // 0x469ade: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469adf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x469ae0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469ae1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x469ae3: e808430a00 CALL 0x0050ddf0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x469ae8: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x469aec: e80ff0ffff CALL 0x00468b00
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x469af1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469af2: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469af5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00069b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469b00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x469b01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x469b03: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x469b07: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x469b09: 741b JZ 0x00469b26
    if(integer::condition("JZ",flags)) goto L00469b26;
  }
  { // 0x469b0b: e8d0efffff CALL 0x00468ae0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x469b10: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x469b14: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469b15: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x469b19: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469b1a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x469b1b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x469b1d: e81e3f0a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x469b22: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469b23: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00469b26: { // 0x469b26: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x469b28: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469b29: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a030: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a034: 83ec3c SUB ESP,0x3c
    f.sp = integer::sub(f.sp,0x0000003cu,32,flags);
  }
  { // 0x46a037: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x46a03a: 740e JZ 0x0046a04a
    if(integer::condition("JZ",flags)) goto L0046a04a;
  }
  { // 0x46a03c: 8b158c7fa200 MOV EDX,dword ptr [0x00a27f8c]
    s.dx = m.r32((0x00a27f8cu));
  }
  { // 0x46a042: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x46a045: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  { // 0x46a048: eb09 JMP 0x0046a053
    goto L0046a053;
  }
  L0046a04a: { // 0x46a04a: c644240000 MOV byte ptr [ESP],0x0
    m.w8((f.sp), 0x00000000u);
  }
  { // 0x46a04f: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L0046a053: { // 0x46a053: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  { // 0x46a057: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x46a059: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a05a: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  { // 0x46a05e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a05f: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  { // 0x46a063: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a064: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a065: e8863d0a00 CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a06a: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x46a06e: e86dad2200 CALL 0x00694de0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a073: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  { // 0x46a076: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a0d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a0d0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x46a0d3: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a0d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a0d8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a0da: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  { // 0x46a0de: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x46a0e0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a0e1: e87a3afaff CALL 0x0040db60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a0e6: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  { // 0x46a0ea: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  { // 0x46a0ee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a0ef: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a0f0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a0f1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a0f3: e8f83c0a00 CALL 0x0050ddf0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a0f8: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x46a0fc: e88f3afaff CALL 0x0040db90
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46a101: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a102: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x46a105: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a110: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a111: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a113: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46a117: e8443afaff CALL 0x0040db60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a11c: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a120: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a121: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x46a125: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a126: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a127: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a129: e812390a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a12e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a12f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a140: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x46a143: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a147: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a148: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a14a: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  { // 0x46a14e: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x46a150: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a151: e87ad5feff CALL 0x004576d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a156: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  { // 0x46a15a: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  { // 0x46a15e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a15f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a160: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a161: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a163: e8883c0a00 CALL 0x0050ddf0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a168: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x46a16c: e88fd5feff CALL 0x00457700
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46a171: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a172: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x46a175: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a180: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a181: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a183: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46a187: e844d5feff CALL 0x004576d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a18c: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a190: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a191: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x46a195: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a196: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a197: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a199: e8a2380a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a19e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a19f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a4d0: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a4d4: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a4da: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a4de: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a4e3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a4e4: 8b0495288e7800 MOV EAX,dword ptr [EDX*0x4 + 0x788e28]
    s.ax = m.r32(((s.dx * 0x00000004u)+0x00788e28u));
  }
  { // 0x46a4eb: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  { // 0x46a4f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a4f3: 8b842490000000 MOV EAX,dword ptr [ESP + 0x90]
    s.ax = m.r32((f.sp+0x00000090u));
  }
  { // 0x46a4fa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a4fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a4fc: e8ef380a00 CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a501: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x46a505: e8d6e02b00 CALL 0x007285e0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a50a: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a510: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a540: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a541: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a543: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46a547: 80f9ff CMP CL,0xff
    (void)integer::sub((s.cx & 0xffu),0x000000ffu,8,flags);
  }
  { // 0x46a54a: 751a JNZ 0x0046a566
    if(integer::condition("JNZ",flags)) goto L0046a566;
  }
  { // 0x46a54c: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a550: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a554: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x46a559: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a55a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a55b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a55d: e8de340a00 CALL 0x0050da40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a562: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a563: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a566: { // 0x46a566: e855f02900 CALL 0x007095c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a56b: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a56f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a570: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a574: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a575: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a576: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a578: e8c3340a00 CALL 0x0050da40
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46a57d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a57e: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a590: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a596: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a59a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a59b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46a59c: 8bbc2494000000 MOV EDI,dword ptr [ESP + 0x94]
    s.di = m.r32((f.sp+0x00000094u));
  }
  { // 0x46a5a3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a5a5: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a5aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a5ab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x46a5ad: e8ee860100 CALL 0x00482ca0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a5b2: 8b8c2498000000 MOV ECX,dword ptr [ESP + 0x98]
    s.cx = m.r32((f.sp+0x00000098u));
  }
  { // 0x46a5b9: 8b942494000000 MOV EDX,dword ptr [ESP + 0x94]
    s.dx = m.r32((f.sp+0x00000094u));
  }
  { // 0x46a5c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a5c1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a5c2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a5c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a5c5: e826380a00 CALL 0x0050ddf0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a5ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a5cc: 7414 JZ 0x0046a5e2
    if(integer::condition("JZ",flags)) goto L0046a5e2;
  }
  { // 0x46a5ce: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x46a5d2: e879860100 CALL 0x00482c50
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46a5d7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46a5d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a5d9: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a5df: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a5e2: { // 0x46a5e2: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x46a5e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46a5e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a5e6: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a5ec: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a5f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a5f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a5f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a5f3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46a5f7: e8a4860100 CALL 0x00482ca0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a5fc: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a600: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a601: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x46a605: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a606: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a607: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a609: e832340a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a60e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a60f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a6d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a6d0: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a6d4: b85c8e7b00 MOV EAX,0x7b8e5c
    s.ax = 0x007b8e5cu;
  }
  { // 0x46a6d9: 83fafe CMP EDX,-0x2
    (void)integer::sub(s.dx,0xfffffffeu,32,flags);
  }
  { // 0x46a6dc: 7518 JNZ 0x0046a6f6
    if(integer::condition("JNZ",flags)) goto L0046a6f6;
  }
  { // 0x46a6de: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a6e2: b8b0ce7b00 MOV EAX,0x7bceb0
    s.ax = 0x007bceb0u;
  }
  { // 0x46a6e7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a6e8: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a6ec: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a6ed: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a6ee: e84d330a00 CALL 0x0050da40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a6f3: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a6f6: { // 0x46a6f6: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x46a6f9: 741b JZ 0x0046a716
    if(integer::condition("JZ",flags)) goto L0046a716;
  }
  { // 0x46a6fb: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x46a6fd: 7c17 JL 0x0046a716
    if(integer::condition("JL",flags)) goto L0046a716;
  }
  { // 0x46a6ff: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a700: 8b3548e0a100 MOV ESI,dword ptr [0x00a1e048]
    s.si = m.r32((0x00a1e048u));
  }
  { // 0x46a706: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x46a708: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a709: 7d0b JGE 0x0046a716
    if(integer::condition("JGE",flags)) goto L0046a716;
  }
  { // 0x46a70b: a13ce0a100 MOV EAX,[0x00a1e03c]
    s.ax = m.r32((0x00a1e03cu));
  }
  { // 0x46a710: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x46a713: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L0046a716: { // 0x46a716: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a71a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a71b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a71f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a720: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a721: e81a330a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a726: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a810: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a814: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a81a: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a81e: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a823: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a824: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46a82b: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x46a830: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a831: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a832: e8b9350a00 CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a837: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a839: 740e JZ 0x0046a849
    if(integer::condition("JZ",flags)) goto L0046a849;
  }
  { // 0x46a83b: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x46a83f: e8bc830100 CALL 0x00482c00
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a844: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x46a847: 7507 JNZ 0x0046a850
    if(integer::condition("JNZ",flags)) goto L0046a850;
  }
  L0046a849: { // 0x46a849: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  L0046a850: { // 0x46a850: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a856: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a860: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a864: 8b15788ca500 MOV EDX,dword ptr [0x00a58c78]
    s.dx = m.r32((0x00a58c78u));
  }
  { // 0x46a86a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x46a86c: 7217 JC 0x0046a885
    if(integer::condition("JC",flags)) goto L0046a885;
  }
  { // 0x46a86e: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a872: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x46a876: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x46a87b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a87c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a87d: e8be310a00 CALL 0x0050da40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a882: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a885: { // 0x46a885: 8b156c8ca500 MOV EDX,dword ptr [0x00a58c6c]
    s.dx = m.r32((0x00a58c6cu));
  }
  { // 0x46a88b: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x46a88e: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a892: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a893: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a897: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a898: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a899: e8a2310a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a89e: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a8b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a8b0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a8b4: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a8ba: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a8be: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a8c3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a8c4: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46a8cb: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x46a8d0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a8d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a8d2: e819350a00 CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a8d7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a8d9: 7412 JZ 0x0046a8ed
    if(integer::condition("JZ",flags)) goto L0046a8ed;
  }
  { // 0x46a8db: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x46a8df: e8cc7f0100 CALL 0x004828b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a8e4: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a8ea: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a8ed: { // 0x46a8ed: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46a8f4: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a8fa: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a930: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a934: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a93a: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a93e: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a943: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a944: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46a94b: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x46a950: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a951: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a952: e899340a00 CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a957: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a959: 7418 JZ 0x0046a973
    if(integer::condition("JZ",flags)) goto L0046a973;
  }
  { // 0x46a95b: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x46a95f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a960: b9a8e0a100 MOV ECX,0xa1e0a8
    s.cx = 0x00a1e0a8u;
  }
  { // 0x46a965: e8662e2700 CALL 0x006dd7d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a96a: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a970: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a973: { // 0x46a973: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46a97a: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a980: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a990: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a994: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a995: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46a997: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a998: b9a8e0a100 MOV ECX,0xa1e0a8
    s.cx = 0x00a1e0a8u;
  }
  { // 0x46a99d: e85e252700 CALL 0x006dcf00
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a9a2: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a9a6: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a9aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a9ab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a9ac: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a9ad: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46a9af: e88c300a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a9b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a9b5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a9c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a9c0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a9c4: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a9ca: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a9ce: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a9d3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a9d4: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46a9db: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x46a9e0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a9e1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a9e2: e809340a00 CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46a9e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a9e9: 7412 JZ 0x0046a9fd
    if(integer::condition("JZ",flags)) goto L0046a9fd;
  }
  { // 0x46a9eb: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x46a9ef: e85c7e0100 CALL 0x00482850
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46a9f4: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a9fa: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a9fd: { // 0x46a9fd: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46aa04: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46aa0a: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006aa30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46aa30: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46aa34: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46aa3a: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46aa3e: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46aa43: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46aa44: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46aa4b: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x46aa50: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46aa51: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46aa52: e899330a00 CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46aa57: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46aa59: 7412 JZ 0x0046aa6d
    if(integer::condition("JZ",flags)) goto L0046aa6d;
  }
  { // 0x46aa5b: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x46aa5f: e8dc800100 CALL 0x00482b40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46aa64: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46aa6a: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046aa6d: { // 0x46aa6d: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x46aa74: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46aa7a: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006bfb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46bfb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46bfb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46bfb3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46bfb7: e8b4f32300 CALL 0x006ab370
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46bfbc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46bfbe: 7419 JZ 0x0046bfd9
    if(integer::condition("JZ",flags)) goto L0046bfd9;
  }
  { // 0x46bfc0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46bfc4: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  { // 0x46bfc7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46bfc8: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x46bfcc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46bfcd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46bfce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46bfd0: e86b1a0a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46bfd5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46bfd6: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046bfd9: { // 0x46bfd9: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46bfdd: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46bfe1: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x46bfe6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46bfe7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46bfe8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46bfea: e8511a0a00 CALL 0x0050da40
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46bfef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46bff0: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006c000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46c000: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46c006: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46c00a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46c00b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46c00c: 8bbc2494000000 MOV EDI,dword ptr [ESP + 0x94]
    s.di = m.r32((f.sp+0x00000094u));
  }
  { // 0x46c013: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46c015: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46c01a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c01b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x46c01d: e8de6c0100 CALL 0x00482d00
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46c022: 8b8c2498000000 MOV ECX,dword ptr [ESP + 0x98]
    s.cx = m.r32((f.sp+0x00000098u));
  }
  { // 0x46c029: 8b942494000000 MOV EDX,dword ptr [ESP + 0x94]
    s.dx = m.r32((f.sp+0x00000094u));
  }
  { // 0x46c030: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c031: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46c032: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46c033: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46c035: e8b61d0a00 CALL 0x0050ddf0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46c03a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46c03c: 7414 JZ 0x0046c052
    if(integer::condition("JZ",flags)) goto L0046c052;
  }
  { // 0x46c03e: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x46c042: e8796c0100 CALL 0x00482cc0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46c047: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46c048: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46c049: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46c04f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046c052: { // 0x46c052: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x46c054: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46c055: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46c056: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46c05c: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006c060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46c060: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46c061: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46c063: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46c067: e8946c0100 CALL 0x00482d00
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46c06c: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46c070: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c071: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x46c075: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c076: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46c077: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46c079: e8c2190a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46c07e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46c07f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006c090(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46c090: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46c096: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46c09a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46c09b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46c09c: 8bbc2494000000 MOV EDI,dword ptr [ESP + 0x94]
    s.di = m.r32((f.sp+0x00000094u));
  }
  { // 0x46c0a3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46c0a5: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46c0aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c0ab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x46c0ad: e8ae6c0100 CALL 0x00482d60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46c0b2: 8b8c2498000000 MOV ECX,dword ptr [ESP + 0x98]
    s.cx = m.r32((f.sp+0x00000098u));
  }
  { // 0x46c0b9: 8b942494000000 MOV EDX,dword ptr [ESP + 0x94]
    s.dx = m.r32((f.sp+0x00000094u));
  }
  { // 0x46c0c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c0c1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46c0c2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46c0c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46c0c5: e8261d0a00 CALL 0x0050ddf0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46c0ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46c0cc: 7414 JZ 0x0046c0e2
    if(integer::condition("JZ",flags)) goto L0046c0e2;
  }
  { // 0x46c0ce: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x46c0d2: e8496c0100 CALL 0x00482d20
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46c0d7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46c0d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46c0d9: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46c0df: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046c0e2: { // 0x46c0e2: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x46c0e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46c0e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46c0e6: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46c0ec: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006c0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46c0f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46c0f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46c0f3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46c0f7: e8646c0100 CALL 0x00482d60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46c0fc: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46c100: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c101: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x46c105: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c106: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46c107: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46c109: e832190a00 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46c10e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46c10f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006ddd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46ddd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46ddd1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46ddd2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x46ddd4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x46ddd6: 38057087a200 CMP byte ptr [0x00a28770],AL
    (void)integer::sub(m.r8((0x00a28770u)),(s.ax & 0xffu),8,flags);
  }
  { // 0x46dddc: 7518 JNZ 0x0046ddf6
    if(integer::condition("JNZ",flags)) goto L0046ddf6;
  }
  { // 0x46ddde: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  { // 0x46dde4: 8b1578198200 MOV EDX,dword ptr [0x00821978]
    s.dx = m.r32((0x00821978u));
  }
  { // 0x46ddea: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46ddee: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x46ddf0: 3916 CMP dword ptr [ESI],EDX
    (void)integer::sub(m.r32((s.si)),s.dx,32,flags);
  }
  { // 0x46ddf2: 7c22 JL 0x0046de16
    if(integer::condition("JL",flags)) goto L0046de16;
  }
  { // 0x46ddf4: eb16 JMP 0x0046de0c
    goto L0046de0c;
  }
  L0046ddf6: { // 0x46ddf6: 8b0d60198200 MOV ECX,dword ptr [0x00821960]
    s.cx = m.r32((0x00821960u));
  }
  { // 0x46ddfc: 8b1568198200 MOV EDX,dword ptr [0x00821968]
    s.dx = m.r32((0x00821968u));
  }
  { // 0x46de02: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46de06: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x46de08: 3916 CMP dword ptr [ESI],EDX
    (void)integer::sub(m.r32((s.si)),s.dx,32,flags);
  }
  { // 0x46de0a: 7f0a JG 0x0046de16
    if(integer::condition("JG",flags)) goto L0046de16;
  }
  L0046de0c: { // 0x46de0c: a202f78100 MOV [0x0081f702],AL
    m.w8((0x0081f702u), (s.ax & 0xffu));
  }
  { // 0x46de11: a203f78100 MOV [0x0081f703],AL
    m.w8((0x0081f703u), (s.ax & 0xffu));
  }
  L0046de16: { // 0x46de16: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x46de18: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x46de1d: e80e220700 CALL 0x004e0030
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46de22: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46de23: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x46de25: e826322700 CALL 0x006e1050
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46de2a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46de2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46de2c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006f930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46f930: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46f931: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46f933: e8b8f8fbff CALL 0x0042f1f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46f938: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46f93c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46f93e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46f93f: c6465000 MOV byte ptr [ESI + 0x50],0x0
    m.w8((s.si+0x00000050u), 0x00000000u);
  }
  { // 0x46f943: c70658567800 MOV dword ptr [ESI],0x785658
    m.w32((s.si), 0x00785658u);
  }
  { // 0x46f949: e802040000 CALL 0x0046fd50
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46f94e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46f950: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46f951: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006f960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46f960: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46f961: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46f963: e888f8fbff CALL 0x0042f1f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46f968: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46f96c: c6465000 MOV byte ptr [ESI + 0x50],0x0
    m.w8((s.si+0x00000050u), 0x00000000u);
  }
  { // 0x46f970: c70658567800 MOV dword ptr [ESI],0x785658
    m.w32((s.si), 0x00785658u);
  }
  { // 0x46f976: e8f5a62e00 CALL 0x0075a070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46f97b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46f97c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46f97e: e8cd030000 CALL 0x0046fd50
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x46f983: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46f985: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46f986: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006fc90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46fc90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46fc91: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46fc92: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x46fc94: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x46fc96: e8bcdc2f00 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x46fc9b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46fc9c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x46fc9e: e8a3943000 CALL 0x00779146
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x46fca3: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x46fca6: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x46fcac: 8b0de08b8300 MOV ECX,dword ptr [0x00838be0]
    s.cx = m.r32((0x00838be0u));
  }
  { // 0x46fcb2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x46fcb5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x46fcb7: 7509 JNZ 0x0046fcc2
    if(integer::condition("JNZ",flags)) goto L0046fcc2;
  }
  { // 0x46fcb9: 8935e08b8300 MOV dword ptr [0x00838be0],ESI
    m.w32((0x00838be0u), s.si);
  }
  { // 0x46fcbf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46fcc0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46fcc1: c3 RET
    finish(m,s,f,0u); return;
  }
  L0046fcc2: { // 0x46fcc2: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x46fcc4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46fcc6: 7408 JZ 0x0046fcd0
    if(integer::condition("JZ",flags)) goto L0046fcd0;
  }
  L0046fcc8: { // 0x46fcc8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x46fcca: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x46fccc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46fcce: 75f8 JNZ 0x0046fcc8
    if(integer::condition("JNZ",flags)) goto L0046fcc8;
  }
  L0046fcd0: { // 0x46fcd0: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x46fcd2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46fcd3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46fcd4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0007bc40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47bc40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47bc41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47bc43: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47bc44: 8d7e24 LEA EDI,[ESI + 0x24]
    s.di = (s.si+0x00000024u);
  }
  { // 0x47bc47: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x47bc49: e822912800 CALL 0x00704d70
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x47bc4e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47bc50: 740d JZ 0x0047bc5f
    if(integer::condition("JZ",flags)) goto L0047bc5f;
  }
  { // 0x47bc52: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47bc53: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x47bc55: e866b22800 CALL 0x00706ec0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x47bc5a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47bc5b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x47bc5d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47bc5e: c3 RET
    finish(m,s,f,0u); return;
  }
  L0047bc5f: { // 0x47bc5f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47bc60: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x47bc65: e896980c00 CALL 0x00545500
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x47bc6a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x47bc6c: e82fe7ffff CALL 0x0047a3a0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x47bc71: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47bc72: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x47bc74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47bc75: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0007c750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47c750: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  { // 0x47c753: 8b4124 MOV EAX,dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  { // 0x47c756: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47c757: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47c758: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x47c75c: 0fbf7c240a MOVSX EDI,word ptr [ESP + 0xa]
    s.di = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000000au)),16));
  }
  { // 0x47c761: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x47c764: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x47c767: b880000000 MOV EAX,0x80
    s.ax = 0x00000080u;
  }
  { // 0x47c76c: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x47c76f: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x47c771: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  { // 0x47c773: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x47c777: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x47c77b: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x47c77f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47c780: e83b3bffff CALL 0x004702c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x47c785: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x47c789: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  { // 0x47c78d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47c78e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x47c793: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  { // 0x47c797: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x47c79b: e890870e00 CALL 0x00564f30
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x47c7a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47c7a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47c7a2: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x47c7a5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0007cf70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47cf70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47cf71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47cf73: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x47cf75: e8dd092f00 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x47cf7a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x47cf7d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47cf7f: 7416 JZ 0x0047cf97
    if(integer::condition("JZ",flags)) goto L0047cf97;
  }
  { // 0x47cf81: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x47cf85: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47cf86: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x47cf88: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47cf8a: c6400400 MOV byte ptr [EAX + 0x4],0x0
    m.w8((s.ax+0x00000004u), 0x00000000u);
  }
  { // 0x47cf8e: e8adb20b00 CALL 0x00538240
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x47cf93: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47cf94: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0047cf97: { // 0x47cf97: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x47cf99: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47cf9b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47cf9c: e89fb20b00 CALL 0x00538240
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x47cfa1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47cfa2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000810c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4810c0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4810c4: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x4810c8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4810c9: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4810cb: 668b4c2414 MOV CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000014u)));
  }
  { // 0x4810d0: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  { // 0x4810d3: 66894e24 MOV word ptr [ESI + 0x24],CX
    m.w16((s.si+0x00000024u), (s.cx & 0xffffu));
  }
  { // 0x4810d7: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4810db: 895628 MOV dword ptr [ESI + 0x28],EDX
    m.w32((s.si+0x00000028u), s.dx);
  }
  { // 0x4810de: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x4810e2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4810e3: c706cc8d7800 MOV dword ptr [ESI],0x788dcc
    m.w32((s.si), 0x00788dccu);
  }
  { // 0x4810e9: 89461c MOV dword ptr [ESI + 0x1c],EAX
    m.w32((s.si+0x0000001cu), s.ax);
  }
  { // 0x4810ec: 894e2c MOV dword ptr [ESI + 0x2c],ECX
    m.w32((s.si+0x0000002cu), s.cx);
  }
  { // 0x4810ef: 895630 MOV dword ptr [ESI + 0x30],EDX
    m.w32((s.si+0x00000030u), s.dx);
  }
  { // 0x4810f2: e860c82e00 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4810f7: 6a58 PUSH 0x58
    f.push(m,0x00000058u);
  }
  { // 0x4810f9: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  { // 0x4810fc: e856c82e00 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x481101: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x481104: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x481106: 7423 JZ 0x0048112b
    if(integer::condition("JZ",flags)) goto L0048112b;
  }
  { // 0x481108: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  { // 0x48110c: 8b561c MOV EDX,dword ptr [ESI + 0x1c]
    s.dx = m.r32((s.si+0x0000001cu));
  }
  { // 0x48110f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x481110: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x481114: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x481115: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x481119: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x48111a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x48111b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x48111d: e8beebffff CALL 0x0047fce0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x481122: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x481125: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x481127: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x481128: c22000 RET 0x20
    finish(m,s,f,32u); return;
  }
  L0048112b: { // 0x48112b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x48112d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x481130: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x481132: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x481133: c22000 RET 0x20
    finish(m,s,f,32u); return;
  }
}
void f_00091660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x491660: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x491663: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x491665: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491666: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x491668: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x491669: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x49166d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49166e: 8b3ccdf09d8300 MOV EDI,dword ptr [ECX*0x8 + 0x839df0]
    s.di = m.r32(((s.cx * 0x00000008u)+0x00839df0u));
  }
  { // 0x491675: 8b0ccdf49d8300 MOV ECX,dword ptr [ECX*0x8 + 0x839df4]
    s.cx = m.r32(((s.cx * 0x00000008u)+0x00839df4u));
  }
  { // 0x49167c: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x49167e: 8b7a04 MOV EDI,dword ptr [EDX + 0x4]
    s.di = m.r32((s.dx+0x00000004u));
  }
  { // 0x491681: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  { // 0x491683: 8b7a08 MOV EDI,dword ptr [EDX + 0x8]
    s.di = m.r32((s.dx+0x00000008u));
  }
  { // 0x491686: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x49168a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49168f: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x491693: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  { // 0x491697: e8d4590c00 CALL 0x00557070
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x49169c: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x4916a0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x4916a5: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x4916a7: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x4916ab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4916ac: e8bf590c00 CALL 0x00557070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4916b1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4916b3: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x4916b5: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4916b9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4916ba: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  { // 0x4916bc: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4916c0: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x4916c3: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  { // 0x4916c6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4916c8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4916c9: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x4916cc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00099940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x499940: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x499944: 8a4c240c MOV CL,byte ptr [ESP + 0xc]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x499948: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x49994a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49994c: 7509 JNZ 0x00499957
    if(integer::condition("JNZ",flags)) goto L00499957;
  }
  { // 0x49994e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x499950: 7526 JNZ 0x00499978
    if(integer::condition("JNZ",flags)) goto L00499978;
  }
  { // 0x499952: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x499954: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00499957: { // 0x499957: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x499959: 751d JNZ 0x00499978
    if(integer::condition("JNZ",flags)) goto L00499978;
  }
  { // 0x49995b: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x49995f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x499960: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  { // 0x499966: e815652000 CALL 0x0069fe80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x49996b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x49996d: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x499970: 0f95c2 SETNZ DL
    s.dx = with_al(s.dx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x499973: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  { // 0x499975: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00499978: { // 0x499978: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  { // 0x49997e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49997f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x499983: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x499984: e827482000 CALL 0x0069e1b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x499989: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x49998b: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0009a390(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49a390: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x49a394: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x49a398: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x49a39a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49a39b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49a39c: e85fb10a00 CALL 0x00545500
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x49a3a1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x49a3a3: e88870fdff CALL 0x00471430
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x49a3a8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0009c910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49c910: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x49c913: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49c918: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49c919: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  { // 0x49c91d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49c91e: e86d8b0a00 CALL 0x00545490
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x49c923: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  { // 0x49c929: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x49c92c: 741f JZ 0x0049c94d
    if(integer::condition("JZ",flags)) goto L0049c94d;
  }
  { // 0x49c92e: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x49c935: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x49c938: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x49c93b: 0faf0d78ac8300 IMUL ECX,dword ptr [0x0083ac78]
    s.cx = integer::imul(s.cx,m.r32((0x0083ac78u)),32,flags);
  }
  { // 0x49c942: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x49c944: 7c07 JL 0x0049c94d
    if(integer::condition("JL",flags)) goto L0049c94d;
  }
  { // 0x49c946: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  { // 0x49c94b: eb02 JMP 0x0049c94f
    goto L0049c94f;
  }
  L0049c94d: { // 0x49c94d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049c94f: { // 0x49c94f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x49c953: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x49c954: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49c955: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x49c959: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49c95a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x49c95b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x49c95d: e84e97fdff CALL 0x004760b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x49c962: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x49c964: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x49c968: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x49c96a: 8b32 MOV ESI,dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  { // 0x49c96c: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x49c96e: 8b7204 MOV ESI,dword ptr [EDX + 0x4]
    s.si = m.r32((s.dx+0x00000004u));
  }
  { // 0x49c971: 897104 MOV dword ptr [ECX + 0x4],ESI
    m.w32((s.cx+0x00000004u), s.si);
  }
  { // 0x49c974: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49c975: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  { // 0x49c978: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  { // 0x49c97b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x49c97e: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0009ea90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49ea90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49ea91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x49ea93: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x49ea96: e8f597f9ff CALL 0x00438290
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x49ea9b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49ea9d: e80e1c1f00 CALL 0x006906b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x49eaa2: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x49eaa7: 7409 JZ 0x0049eab2
    if(integer::condition("JZ",flags)) goto L0049eab2;
  }
  { // 0x49eaa9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49eaaa: e8cceb2c00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x49eaaf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0049eab2: { // 0x49eab2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x49eab4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49eab5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0009eb00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49eb00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49eb01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x49eb03: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x49eb06: e88597f9ff CALL 0x00438290
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x49eb0b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49eb0d: e82e7b1600 CALL 0x00606640
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x49eb12: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x49eb17: 7409 JZ 0x0049eb22
    if(integer::condition("JZ",flags)) goto L0049eb22;
  }
  { // 0x49eb19: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49eb1a: e85ceb2c00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x49eb1f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0049eb22: { // 0x49eb22: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x49eb24: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49eb25: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a52b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a52b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a52b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a52b3: 8d8eb0000000 LEA ECX,[ESI + 0xb0]
    s.cx = (s.si+0x000000b0u);
  }
  { // 0x4a52b9: c706e4b57800 MOV dword ptr [ESI],0x78b5e4
    m.w32((s.si), 0x0078b5e4u);
  }
  { // 0x4a52bf: e8dc2e0900 CALL 0x005381a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4a52c4: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4a52c7: e8a4571c00 CALL 0x0066aa70
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4a52cc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a52ce: e89dd40000 CALL 0x004b2770
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4a52d3: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4a52d8: 7409 JZ 0x004a52e3
    if(integer::condition("JZ",flags)) goto L004a52e3;
  }
  { // 0x4a52da: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a52db: e89b832c00 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x4a52e0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004a52e3: { // 0x4a52e3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4a52e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a52e6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000b2770(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b2770: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b2771: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b2773: c706bcb77800 MOV dword ptr [ESI],0x78b7bc
    m.w32((s.si), 0x0078b7bcu);
  }
  { // 0x4b2779: e892ca0100 CALL 0x004cf210
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4b277e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4b2780: 7407 JZ 0x004b2789
    if(integer::condition("JZ",flags)) goto L004b2789;
  }
  { // 0x4b2782: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4b2784: e867ca0100 CALL 0x004cf1f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L004b2789: { // 0x4b2789: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4b278b: e8d0c40100 CALL 0x004cec60
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4b2790: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b2791: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000b2c30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b2c30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b2c31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b2c33: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4b2c36: c7463c00000000 MOV dword ptr [ESI + 0x3c],0x0
    m.w32((s.si+0x0000003cu), 0x00000000u);
  }
  { // 0x4b2c3d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b2c3f: 740c JZ 0x004b2c4d
    if(integer::condition("JZ",flags)) goto L004b2c4d;
  }
  { // 0x4b2c41: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b2c42: e8fec22b00 CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4b2c47: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4b2c4a: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  L004b2c4d: { // 0x4b2c4d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4b2c4f: e86cc50100 CALL 0x004cf1c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4b2c54: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b2c55: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000bb710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bb710: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bb711: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4bb715: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bb716: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4bb71a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bb71b: 8b87a0000000 MOV EAX,dword ptr [EDI + 0xa0]
    s.ax = m.r32((s.di+0x000000a0u));
  }
  { // 0x4bb721: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bb722: e8d9fdffff CALL 0x004bb500
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4bb727: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4bb729: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4bb72b: 7426 JZ 0x004bb753
    if(integer::condition("JZ",flags)) goto L004bb753;
  }
  { // 0x4bb72d: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x4bb72f: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x4bb731: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4bb733: e8089dfbff CALL 0x00475440
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4bb738: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4bb73a: 7417 JZ 0x004bb753
    if(integer::condition("JZ",flags)) goto L004bb753;
  }
  { // 0x4bb73c: 8b87ac000000 MOV EAX,dword ptr [EDI + 0xac]
    s.ax = m.r32((s.di+0x000000acu));
  }
  { // 0x4bb742: 8a8844010000 MOV CL,byte ptr [EAX + 0x144]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000144u)));
  }
  { // 0x4bb748: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4bb74a: 7407 JZ 0x004bb753
    if(integer::condition("JZ",flags)) goto L004bb753;
  }
  { // 0x4bb74c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bb74d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4bb74f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bb750: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004bb753: { // 0x4bb753: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4bb755: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bb756: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bb757: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000bba80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bba80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bba81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bba82: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bba84: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bba85: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x4bba87: e88410fcff CALL 0x0047cb10
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4bba8c: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x4bba90: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x4bba92: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4bba94: e87710fcff CALL 0x0047cb10
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4bba99: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x4bba9b: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  { // 0x4bba9e: 7c21 JL 0x004bbac1
    if(integer::condition("JL",flags)) goto L004bbac1;
  }
  { // 0x4bbaa0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4bbaa2: e86910fcff CALL 0x0047cb10
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4bbaa7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4bbaa9: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4bbaab: e86010fcff CALL 0x0047cb10
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x4bbab0: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x4bbab2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4bbab4: 7e0b JLE 0x004bbac1
    if(integer::condition("JLE",flags)) goto L004bbac1;
  }
  { // 0x4bbab6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bbab7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bbab8: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4bbabd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bbabe: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004bbac1: { // 0x4bbac1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bbac2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bbac3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4bbac5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bbac6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000bf1c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bf1c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf1c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bf1c3: 6a1e PUSH 0x1e
    f.push(m,0x0000001eu);
  }
  { // 0x4bf1c5: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  { // 0x4bf1c7: c6465301 MOV byte ptr [ESI + 0x53],0x1
    m.w8((s.si+0x00000053u), 0x00000001u);
  }
  { // 0x4bf1cb: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x4bf1d0: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  { // 0x4bf1d6: e8650c1700 CALL 0x0062fe40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4bf1db: 894654 MOV dword ptr [ESI + 0x54],EAX
    m.w32((s.si+0x00000054u), s.ax);
  }
  { // 0x4bf1de: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x4bf1e4: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  { // 0x4bf1e6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4bf1e8: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  { // 0x4bf1ee: e84d0c1700 CALL 0x0062fe40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4bf1f3: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  { // 0x4bf1f6: 7d08 JGE 0x004bf200
    if(integer::condition("JGE",flags)) goto L004bf200;
  }
  { // 0x4bf1f8: 8b5654 MOV EDX,dword ptr [ESI + 0x54]
    s.dx = m.r32((s.si+0x00000054u));
  }
  { // 0x4bf1fb: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  { // 0x4bf1fd: 895654 MOV dword ptr [ESI + 0x54],EDX
    m.w32((s.si+0x00000054u), s.dx);
  }
  L004bf200: { // 0x4bf200: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf201: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000bf770(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bf770: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf771: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bf773: c706ccc07800 MOV dword ptr [ESI],0x78c0cc
    m.w32((s.si), 0x0078c0ccu);
  }
  { // 0x4bf779: c7460404c07800 MOV dword ptr [ESI + 0x4],0x78c004
    m.w32((s.si+0x00000004u), 0x0078c004u);
  }
  { // 0x4bf780: e84bba0700 CALL 0x0053b1d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4bf785: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4bf78a: 7409 JZ 0x004bf795
    if(integer::condition("JZ",flags)) goto L004bf795;
  }
  { // 0x4bf78c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf78d: e8e9de2a00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4bf792: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004bf795: { // 0x4bf795: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4bf797: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf798: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000cc9f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cc9f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cc9f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4cc9f3: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x4cc9f9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4cc9fc: 743b JZ 0x004cca39
    if(integer::condition("JZ",flags)) goto L004cca39;
  }
  { // 0x4cc9fe: 0fbe8e76050000 MOVSX ECX,byte ptr [ESI + 0x576]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x00000576u)),8));
  }
  { // 0x4cca05: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  { // 0x4cca0b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4cca0c: 8b8c8258010000 MOV ECX,dword ptr [EDX + EAX*0x4 + 0x158]
    s.cx = m.r32((s.dx+(s.ax * 0x00000004u)+0x00000158u));
  }
  { // 0x4cca13: e808cf2400 CALL 0x00719920
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4cca18: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x4cca1e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4cca1f: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x4cca25: 8b8c8158010000 MOV ECX,dword ptr [ECX + EAX*0x4 + 0x158]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)+0x00000158u));
  }
  { // 0x4cca2c: e80fd12400 CALL 0x00719b40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4cca31: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4cca32: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cca34: e8d7e2ffff CALL 0x004cad10
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L004cca39: { // 0x4cca39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cca3a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000cca40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cca40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cca41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4cca43: 8b8e30020000 MOV ECX,dword ptr [ESI + 0x230]
    s.cx = m.r32((s.si+0x00000230u));
  }
  { // 0x4cca49: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4cca4b: 7405 JZ 0x004cca52
    if(integer::condition("JZ",flags)) goto L004cca52;
  }
  { // 0x4cca4d: e8aeb3f9ff CALL 0x00467e00
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L004cca52: { // 0x4cca52: 8b8ec4040000 MOV ECX,dword ptr [ESI + 0x4c4]
    s.cx = m.r32((s.si+0x000004c4u));
  }
  { // 0x4cca58: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4cca5a: 740a JZ 0x004cca66
    if(integer::condition("JZ",flags)) goto L004cca66;
  }
  { // 0x4cca5c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4cca5e: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x4cca60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cca61: e89a1b1e00 CALL 0x006ae600
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L004cca66: { // 0x4cca66: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cca68: e8b30a1000 CALL 0x005cd520
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4cca6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cca6e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000cf280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cf280: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cf281: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4cf283: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4cf285: c7062cc87800 MOV dword ptr [ESI],0x78c82c
    m.w32((s.si), 0x0078c82cu);
  }
  { // 0x4cf28b: a128e38400 MOV EAX,[0x0084e328]
    s.ax = m.r32((0x0084e328u));
  }
  { // 0x4cf290: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x4cf292: 7510 JNZ 0x004cf2a4
    if(integer::condition("JNZ",flags)) goto L004cf2a4;
  }
  { // 0x4cf294: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x4cf297: 80e4fe AND AH,0xfe
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000feu),8,flags)) & 0xffu) << 8);
  }
  { // 0x4cf29a: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  { // 0x4cf29d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4cf29f: a328e38400 MOV [0x0084e328],EAX
    m.w32((0x0084e328u), s.ax);
  }
  L004cf2a4: { // 0x4cf2a4: 3b3520e38400 CMP ESI,dword ptr [0x0084e320]
    (void)integer::sub(s.si,m.r32((0x0084e320u)),32,flags);
  }
  { // 0x4cf2aa: 7506 JNZ 0x004cf2b2
    if(integer::condition("JNZ",flags)) goto L004cf2b2;
  }
  { // 0x4cf2ac: 890d20e38400 MOV dword ptr [0x0084e320],ECX
    m.w32((0x0084e320u), s.cx);
  }
  L004cf2b2: { // 0x4cf2b2: 3b3524e38400 CMP ESI,dword ptr [0x0084e324]
    (void)integer::sub(s.si,m.r32((0x0084e324u)),32,flags);
  }
  { // 0x4cf2b8: 7506 JNZ 0x004cf2c0
    if(integer::condition("JNZ",flags)) goto L004cf2c0;
  }
  { // 0x4cf2ba: 890d24e38400 MOV dword ptr [0x0084e324],ECX
    m.w32((0x0084e324u), s.cx);
  }
  L004cf2c0: { // 0x4cf2c0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x4cf2c2: 7506 JNZ 0x004cf2ca
    if(integer::condition("JNZ",flags)) goto L004cf2ca;
  }
  { // 0x4cf2c4: 890d28e38400 MOV dword ptr [0x0084e328],ECX
    m.w32((0x0084e328u), s.cx);
  }
  L004cf2ca: { // 0x4cf2ca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cf2cc: e8af7e0600 CALL 0x00537180
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4cf2d1: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4cf2d6: 7409 JZ 0x004cf2e1
    if(integer::condition("JZ",flags)) goto L004cf2e1;
  }
  { // 0x4cf2d8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cf2d9: e89de32900 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4cf2de: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004cf2e1: { // 0x4cf2e1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4cf2e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cf2e4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000d20f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4d20f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d20f1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d20f2: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x4d20f4: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4d20f6: e892892900 CALL 0x0076aa8d
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4d20fb: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x4d20fd: e84d8a2900 CALL 0x0076ab4f
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4d2102: 0fbe05e3987e00 MOVSX EAX,byte ptr [0x007e98e3]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((0x007e98e3u)),8));
  }
  { // 0x4d2109: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  { // 0x4d210b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4d210f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4d2110: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4d2111: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4d2113: 7413 JZ 0x004d2128
    if(integer::condition("JZ",flags)) goto L004d2128;
  }
  { // 0x4d2115: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4d2119: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4d211a: 68e5987e00 PUSH 0x7e98e5
    f.push(m,0x007e98e5u);
  }
  { // 0x4d211f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4d2120: e8ebbb2900 CALL 0x0076dd10
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4d2125: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004d2128: { // 0x4d2128: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000ddeb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ddeb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ddeb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ddeb3: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x4ddeb6: e805190d00 CALL 0x005af7c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4ddebb: 68404e7c00 PUSH 0x7c4e40
    f.push(m,0x007c4e40u);
  }
  { // 0x4ddec0: 8d4e4c LEA ECX,[ESI + 0x4c]
    s.cx = (s.si+0x0000004cu);
  }
  { // 0x4ddec3: e898b32700 CALL 0x00759260
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4ddec8: 68384e7c00 PUSH 0x7c4e38
    f.push(m,0x007c4e38u);
  }
  { // 0x4ddecd: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4dded0: e88bb32700 CALL 0x00759260
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4dded5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4dded7: 894654 MOV dword ptr [ESI + 0x54],EAX
    m.w32((s.si+0x00000054u), s.ax);
  }
  { // 0x4ddeda: 89465c MOV dword ptr [ESI + 0x5c],EAX
    m.w32((s.si+0x0000005cu), s.ax);
  }
  { // 0x4ddedd: 894660 MOV dword ptr [ESI + 0x60],EAX
    m.w32((s.si+0x00000060u), s.ax);
  }
  { // 0x4ddee0: c6466401 MOV byte ptr [ESI + 0x64],0x1
    m.w8((s.si+0x00000064u), 0x00000001u);
  }
  { // 0x4ddee4: 884665 MOV byte ptr [ESI + 0x65],AL
    m.w8((s.si+0x00000065u), (s.ax & 0xffu));
  }
  { // 0x4ddee7: c7465844db7800 MOV dword ptr [ESI + 0x58],0x78db44
    m.w32((s.si+0x00000058u), 0x0078db44u);
  }
  { // 0x4ddeee: c7466c0a000000 MOV dword ptr [ESI + 0x6c],0xa
    m.w32((s.si+0x0000006cu), 0x0000000au);
  }
  { // 0x4ddef5: 894668 MOV dword ptr [ESI + 0x68],EAX
    m.w32((s.si+0x00000068u), s.ax);
  }
  { // 0x4ddef8: c7063cdb7800 MOV dword ptr [ESI],0x78db3c
    m.w32((s.si), 0x0078db3cu);
  }
  { // 0x4ddefe: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4ddf00: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ddf01: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000de3b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4de3b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4de3b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4de3b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4de3b4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4de3b8: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  { // 0x4de3bb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4de3bc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4de3be: 7411 JZ 0x004de3d1
    if(integer::condition("JZ",flags)) goto L004de3d1;
  }
  { // 0x4de3c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4de3c1: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x4de3c4: e8e7150d00 CALL 0x005af9b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4de3c9: 897e54 MOV dword ptr [ESI + 0x54],EDI
    m.w32((s.si+0x00000054u), s.di);
  }
  { // 0x4de3cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4de3cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4de3ce: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004de3d1: { // 0x4de3d1: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x4de3d4: e867150d00 CALL 0x005af940
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4de3d9: 897e54 MOV dword ptr [ESI + 0x54],EDI
    m.w32((s.si+0x00000054u), s.di);
  }
  { // 0x4de3dc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4de3dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4de3de: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000df360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4df360: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4df361: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4df363: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4df364: 8b7e30 MOV EDI,dword ptr [ESI + 0x30]
    s.di = m.r32((s.si+0x00000030u));
  }
  { // 0x4df367: c706b4db7800 MOV dword ptr [ESI],0x78dbb4
    m.w32((s.si), 0x0078dbb4u);
  }
  { // 0x4df36d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4df36f: 7410 JZ 0x004df381
    if(integer::condition("JZ",flags)) goto L004df381;
  }
  { // 0x4df371: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4df373: e828ef0c00 CALL 0x005ae2a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4df378: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4df379: e8fde22800 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4df37e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004df381: { // 0x4df381: 8d4e34 LEA ECX,[ESI + 0x34]
    s.cx = (s.si+0x00000034u);
  }
  { // 0x4df384: e8979f2700 CALL 0x00759320
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4df389: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4df38b: e840040000 CALL 0x004df7d0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x4df390: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4df391: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4df392: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000df5a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4df5a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4df5a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4df5a3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4df5a4: 8b7e30 MOV EDI,dword ptr [ESI + 0x30]
    s.di = m.r32((s.si+0x00000030u));
  }
  { // 0x4df5a7: c706b4db7800 MOV dword ptr [ESI],0x78dbb4
    m.w32((s.si), 0x0078dbb4u);
  }
  { // 0x4df5ad: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4df5af: 7410 JZ 0x004df5c1
    if(integer::condition("JZ",flags)) goto L004df5c1;
  }
  { // 0x4df5b1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4df5b3: e8e8ec0c00 CALL 0x005ae2a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4df5b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4df5b9: e8bde02800 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4df5be: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004df5c1: { // 0x4df5c1: 8d4e34 LEA ECX,[ESI + 0x34]
    s.cx = (s.si+0x00000034u);
  }
  { // 0x4df5c4: e8579d2700 CALL 0x00759320
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4df5c9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4df5cb: e800020000 CALL 0x004df7d0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x4df5d0: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x4df5d5: 7409 JZ 0x004df5e0
    if(integer::condition("JZ",flags)) goto L004df5e0;
  }
  { // 0x4df5d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4df5d8: e89ee02800 CALL 0x0076d67b
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x4df5dd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004df5e0: { // 0x4df5e0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4df5e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4df5e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4df5e4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000df7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4df7d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4df7d1: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  { // 0x4df7d4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4df7d6: c701d0db7800 MOV dword ptr [ECX],0x78dbd0
    m.w32((s.cx), 0x0078dbd0u);
  }
  { // 0x4df7dc: 7410 JZ 0x004df7ee
    if(integer::condition("JZ",flags)) goto L004df7ee;
  }
  { // 0x4df7de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4df7e0: e8bbea0c00 CALL 0x005ae2a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4df7e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4df7e6: e890de2800 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4df7eb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004df7ee: { // 0x4df7ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4df7ef: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000df880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4df880: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4df881: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4df883: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4df884: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  { // 0x4df887: c706d0db7800 MOV dword ptr [ESI],0x78dbd0
    m.w32((s.si), 0x0078dbd0u);
  }
  { // 0x4df88d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4df88f: 7410 JZ 0x004df8a1
    if(integer::condition("JZ",flags)) goto L004df8a1;
  }
  { // 0x4df891: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4df893: e808ea0c00 CALL 0x005ae2a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4df898: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4df899: e8dddd2800 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4df89e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004df8a1: { // 0x4df8a1: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x4df8a6: 7409 JZ 0x004df8b1
    if(integer::condition("JZ",flags)) goto L004df8b1;
  }
  { // 0x4df8a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4df8a9: e8cddd2800 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4df8ae: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004df8b1: { // 0x4df8b1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4df8b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4df8b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4df8b5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000dfbf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dfbf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dfbf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4dfbf3: c706ecdb7800 MOV dword ptr [ESI],0x78dbec
    m.w32((s.si), 0x0078dbecu);
  }
  { // 0x4dfbf9: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x4dfbfc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4dfbfe: c74610fc747800 MOV dword ptr [ESI + 0x10],0x7874fc
    m.w32((s.si+0x00000010u), 0x007874fcu);
  }
  { // 0x4dfc05: 7417 JZ 0x004dfc1e
    if(integer::condition("JZ",flags)) goto L004dfc1e;
  }
  { // 0x4dfc07: 8a4e1d MOV CL,byte ptr [ESI + 0x1d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000001du)));
  }
  { // 0x4dfc0a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4dfc0c: 7410 JZ 0x004dfc1e
    if(integer::condition("JZ",flags)) goto L004dfc1e;
  }
  { // 0x4dfc0e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4dfc0f: e867da2800 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4dfc14: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4dfc17: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  L004dfc1e: { // 0x4dfc1e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4dfc20: c6461d00 MOV byte ptr [ESI + 0x1d],0x0
    m.w8((s.si+0x0000001du), 0x00000000u);
  }
  { // 0x4dfc24: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x4dfc2b: e8a0fbffff CALL 0x004df7d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4dfc30: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dfc31: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000dfcc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dfcc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dfcc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4dfcc3: c706ecdb7800 MOV dword ptr [ESI],0x78dbec
    m.w32((s.si), 0x0078dbecu);
  }
  { // 0x4dfcc9: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x4dfccc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4dfcce: c74610fc747800 MOV dword ptr [ESI + 0x10],0x7874fc
    m.w32((s.si+0x00000010u), 0x007874fcu);
  }
  { // 0x4dfcd5: 7417 JZ 0x004dfcee
    if(integer::condition("JZ",flags)) goto L004dfcee;
  }
  { // 0x4dfcd7: 8a4e1d MOV CL,byte ptr [ESI + 0x1d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000001du)));
  }
  { // 0x4dfcda: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4dfcdc: 7410 JZ 0x004dfcee
    if(integer::condition("JZ",flags)) goto L004dfcee;
  }
  { // 0x4dfcde: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4dfcdf: e897d92800 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4dfce4: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4dfce7: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  L004dfcee: { // 0x4dfcee: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4dfcf0: c6461d00 MOV byte ptr [ESI + 0x1d],0x0
    m.w8((s.si+0x0000001du), 0x00000000u);
  }
  { // 0x4dfcf4: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x4dfcfb: e8d0faffff CALL 0x004df7d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4dfd00: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4dfd05: 7409 JZ 0x004dfd10
    if(integer::condition("JZ",flags)) goto L004dfd10;
  }
  { // 0x4dfd07: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dfd08: e86ed92800 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4dfd0d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004dfd10: { // 0x4dfd10: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4dfd12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dfd13: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e2200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e2200: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e2201: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4e2205: 8d8e18020000 LEA ECX,[ESI + 0x218]
    s.cx = (s.si+0x00000218u);
  }
  { // 0x4e220b: e8a0e21a00 CALL 0x006904b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4e2210: e83b882800 CALL 0x0076aa50
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4e2215: 8b8e2c020000 MOV ECX,dword ptr [ESI + 0x22c]
    s.cx = m.r32((s.si+0x0000022cu));
  }
  { // 0x4e221b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e221c: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4e221e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4e2220: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e5f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e5f70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4e5f71: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4e5f73: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4e5f77: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e5f78: 8b83a0010000 MOV EAX,dword ptr [EBX + 0x1a0]
    s.ax = m.r32((s.bx+0x000001a0u));
  }
  { // 0x4e5f7e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4e5f7f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x4e5f81: 8b3c88 MOV EDI,dword ptr [EAX + ECX*0x4]
    s.di = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x4e5f84: 8b4f24 MOV ECX,dword ptr [EDI + 0x24]
    s.cx = m.r32((s.di+0x00000024u));
  }
  { // 0x4e5f87: 8a91e1000000 MOV DL,byte ptr [ECX + 0xe1]
    s.dx = with_al(s.dx, m.r8((s.cx+0x000000e1u)));
  }
  { // 0x4e5f8d: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x4e5f8f: 7413 JZ 0x004e5fa4
    if(integer::condition("JZ",flags)) goto L004e5fa4;
  }
  { // 0x4e5f91: 8b91e4000000 MOV EDX,dword ptr [ECX + 0xe4]
    s.dx = m.r32((s.cx+0x000000e4u));
  }
  { // 0x4e5f97: 8b3490 MOV ESI,dword ptr [EAX + EDX*0x4]
    s.si = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x4e5f9a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4e5f9c: 7406 JZ 0x004e5fa4
    if(integer::condition("JZ",flags)) goto L004e5fa4;
  }
  { // 0x4e5f9e: 8b464a MOV EAX,dword ptr [ESI + 0x4a]
    s.ax = m.r32((s.si+0x0000004au));
  }
  { // 0x4e5fa1: 89474a MOV dword ptr [EDI + 0x4a],EAX
    m.w32((s.di+0x0000004au), s.ax);
  }
  L004e5fa4: { // 0x4e5fa4: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x4e5fa8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4e5fa9: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x4e5faf: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x4e5fb1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4e5fb3: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x4e5fb6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4e5fb7: e874c71a00 CALL 0x00692730
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4e5fbc: 8b4724 MOV EAX,dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  { // 0x4e5fbf: 8a88e1000000 MOV CL,byte ptr [EAX + 0xe1]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000000e1u)));
  }
  { // 0x4e5fc5: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4e5fc7: 741e JZ 0x004e5fe7
    if(integer::condition("JZ",flags)) goto L004e5fe7;
  }
  { // 0x4e5fc9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4e5fcb: 741a JZ 0x004e5fe7
    if(integer::condition("JZ",flags)) goto L004e5fe7;
  }
  { // 0x4e5fcd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4e5fcf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4e5fd1: e87ac61a00 CALL 0x00692650
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4e5fd6: 3b1de4e0a100 CMP EBX,dword ptr [0x00a1e0e4]
    (void)integer::sub(s.bx,m.r32((0x00a1e0e4u)),32,flags);
  }
  { // 0x4e5fdc: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x4e5fdf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4e5fe0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4e5fe2: e879c61a00 CALL 0x00692660
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L004e5fe7: { // 0x4e5fe7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e5fe8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e5fe9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4e5feb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4e5fec: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000e6d90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e6d90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e6d91: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4e6d92: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4e6d96: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4e6d98: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4e6d9a: 7438 JZ 0x004e6dd4
    if(integer::condition("JZ",flags)) goto L004e6dd4;
  }
  { // 0x4e6d9c: 8a4776 MOV AL,byte ptr [EDI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000076u)));
  }
  { // 0x4e6d9f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4e6da1: 7531 JNZ 0x004e6dd4
    if(integer::condition("JNZ",flags)) goto L004e6dd4;
  }
  { // 0x4e6da3: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x4e6da7: 8b8e08530000 MOV ECX,dword ptr [ESI + 0x5308]
    s.cx = m.r32((s.si+0x00005308u));
  }
  { // 0x4e6dad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4e6dae: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4e6daf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4e6db1: e8bafdffff CALL 0x004e6b70
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4e6db6: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4e6db9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4e6dbb: 8b82b8000000 MOV EAX,dword ptr [EDX + 0xb8]
    s.ax = m.r32((s.dx+0x000000b8u));
  }
  { // 0x4e6dc1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4e6dc2: e879282100 CALL 0x006f9640
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4e6dc7: 89be08530000 MOV dword ptr [ESI + 0x5308],EDI
    m.w32((s.si+0x00005308u), s.di);
  }
  { // 0x4e6dcd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e6dce: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4e6dd0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e6dd1: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004e6dd4: { // 0x4e6dd4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e6dd5: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4e6dd7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e6dd8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000ec5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ec5e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ec5e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ec5e3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4ec5e4: 8bbe54010000 MOV EDI,dword ptr [ESI + 0x154]
    s.di = m.r32((s.si+0x00000154u));
  }
  { // 0x4ec5ea: 8b84be58010000 MOV EAX,dword ptr [ESI + EDI*0x4 + 0x158]
    s.ax = m.r32((s.si+(s.di * 0x00000004u)+0x00000158u));
  }
  { // 0x4ec5f1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4ec5f3: 7521 JNZ 0x004ec616
    if(integer::condition("JNZ",flags)) goto L004ec616;
  }
  { // 0x4ec5f5: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x4ec5f7: e85b132800 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4ec5fc: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4ec5ff: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4ec601: 740a JZ 0x004ec60d
    if(integer::condition("JZ",flags)) goto L004ec60d;
  }
  { // 0x4ec603: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4ec604: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4ec606: e8a5d12200 CALL 0x007197b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4ec60b: eb02 JMP 0x004ec60f
    goto L004ec60f;
  }
  L004ec60d: { // 0x4ec60d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ec60f: { // 0x4ec60f: 8984be58010000 MOV dword ptr [ESI + EDI*0x4 + 0x158],EAX
    m.w32((s.si+(s.di * 0x00000004u)+0x00000158u), s.ax);
  }
  L004ec616: { // 0x4ec616: 8b8e54010000 MOV ECX,dword ptr [ESI + 0x154]
    s.cx = m.r32((s.si+0x00000154u));
  }
  { // 0x4ec61c: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4ec620: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ec621: 8b8c8e58010000 MOV ECX,dword ptr [ESI + ECX*0x4 + 0x158]
    s.cx = m.r32((s.si+(s.cx * 0x00000004u)+0x00000158u));
  }
  { // 0x4ec628: e8c3d32200 CALL 0x007199f0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x4ec62d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4ec62e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ec62f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000edda0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4edda0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4edda1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4edda5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4edda6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4edda8: 8b84b758010000 MOV EAX,dword ptr [EDI + ESI*0x4 + 0x158]
    s.ax = m.r32((s.di+(s.si * 0x00000004u)+0x00000158u));
  }
  { // 0x4eddaf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4eddb1: 752b JNZ 0x004eddde
    if(integer::condition("JNZ",flags)) goto L004eddde;
  }
  { // 0x4eddb3: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x4eddb5: e89dfb2700 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4eddba: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4eddbd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4eddbf: 7414 JZ 0x004eddd5
    if(integer::condition("JZ",flags)) goto L004eddd5;
  }
  { // 0x4eddc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4eddc2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4eddc4: e8e7b92200 CALL 0x007197b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4eddc9: 8984b758010000 MOV dword ptr [EDI + ESI*0x4 + 0x158],EAX
    m.w32((s.di+(s.si * 0x00000004u)+0x00000158u), s.ax);
  }
  { // 0x4eddd0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4eddd1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4eddd2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004eddd5: { // 0x4eddd5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4eddd7: 8984b758010000 MOV dword ptr [EDI + ESI*0x4 + 0x158],EAX
    m.w32((s.di+(s.si * 0x00000004u)+0x00000158u), s.ax);
  }
  L004eddde: { // 0x4eddde: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4edddf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4edde0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000eeaa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4eeaa0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4eeaa1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4eeaa3: 8b0dc855a200 MOV ECX,dword ptr [0x00a255c8]
    s.cx = m.r32((0x00a255c8u));
  }
  { // 0x4eeaa9: 8a8634010000 MOV AL,byte ptr [ESI + 0x134]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000134u)));
  }
  { // 0x4eeaaf: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4eeab1: 7514 JNZ 0x004eeac7
    if(integer::condition("JNZ",flags)) goto L004eeac7;
  }
  { // 0x4eeab3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4eeab5: 750e JNZ 0x004eeac5
    if(integer::condition("JNZ",flags)) goto L004eeac5;
  }
  { // 0x4eeab7: 8a8635010000 MOV AL,byte ptr [ESI + 0x135]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000135u)));
  }
  { // 0x4eeabd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4eeabf: 7504 JNZ 0x004eeac5
    if(integer::condition("JNZ",flags)) goto L004eeac5;
  }
  { // 0x4eeac1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4eeac3: eb02 JMP 0x004eeac7
    goto L004eeac7;
  }
  L004eeac5: { // 0x4eeac5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004eeac7: { // 0x4eeac7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4eeac9: 7509 JNZ 0x004eead4
    if(integer::condition("JNZ",flags)) goto L004eead4;
  }
  { // 0x4eeacb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4eeacd: 7405 JZ 0x004eead4
    if(integer::condition("JZ",flags)) goto L004eead4;
  }
  { // 0x4eeacf: e82cd0ffff CALL 0x004ebb00
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L004eead4: { // 0x4eead4: 8b8604560000 MOV EAX,dword ptr [ESI + 0x5604]
    s.ax = m.r32((s.si+0x00005604u));
  }
  { // 0x4eeada: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4eeadc: 751f JNZ 0x004eeafd
    if(integer::condition("JNZ",flags)) goto L004eeafd;
  }
  { // 0x4eeade: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4eeadf: 8b3dc483a200 MOV EDI,dword ptr [0x00a283c4]
    s.di = m.r32((0x00a283c4u));
  }
  { // 0x4eeae5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4eeae7: c705c483a20000000000 MOV dword ptr [0x00a283c4],0x0
    m.w32((0x00a283c4u), 0x00000000u);
  }
  { // 0x4eeaf1: e89a020000 CALL 0x004eed90
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4eeaf6: 893dc483a200 MOV dword ptr [0x00a283c4],EDI
    m.w32((0x00a283c4u), s.di);
  }
  { // 0x4eeafc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eeafd: { // 0x4eeafd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4eeafe: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000fe130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fe130: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fe131: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4fe133: 6a1e PUSH 0x1e
    f.push(m,0x0000001eu);
  }
  { // 0x4fe135: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  { // 0x4fe137: c6466801 MOV byte ptr [ESI + 0x68],0x1
    m.w8((s.si+0x00000068u), 0x00000001u);
  }
  { // 0x4fe13b: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x4fe140: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  { // 0x4fe146: e8f51c1300 CALL 0x0062fe40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4fe14b: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  { // 0x4fe14e: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x4fe154: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  { // 0x4fe156: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4fe158: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  { // 0x4fe15e: e8dd1c1300 CALL 0x0062fe40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4fe163: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  { // 0x4fe166: 7d08 JGE 0x004fe170
    if(integer::condition("JGE",flags)) goto L004fe170;
  }
  { // 0x4fe168: 8b566c MOV EDX,dword ptr [ESI + 0x6c]
    s.dx = m.r32((s.si+0x0000006cu));
  }
  { // 0x4fe16b: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  { // 0x4fe16d: 89566c MOV dword ptr [ESI + 0x6c],EDX
    m.w32((s.si+0x0000006cu), s.dx);
  }
  L004fe170: { // 0x4fe170: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fe171: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000fe3d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fe3d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fe3d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4fe3d3: c706b4e27800 MOV dword ptr [ESI],0x78e2b4
    m.w32((s.si), 0x0078e2b4u);
  }
  { // 0x4fe3d9: c74604ece17800 MOV dword ptr [ESI + 0x4],0x78e1ec
    m.w32((s.si+0x00000004u), 0x0078e1ecu);
  }
  { // 0x4fe3e0: e8ebcd0300 CALL 0x0053b1d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x4fe3e5: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4fe3ea: 7409 JZ 0x004fe3f5
    if(integer::condition("JZ",flags)) goto L004fe3f5;
  }
  { // 0x4fe3ec: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fe3ed: e889f22600 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x4fe3f2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004fe3f5: { // 0x4fe3f5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4fe3f7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fe3f8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001058c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5058c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5058c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5058c3: e8f81a0000 CALL 0x005073c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5058c8: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5058cb: 7507 JNZ 0x005058d4
    if(integer::condition("JNZ",flags)) goto L005058d4;
  }
  { // 0x5058cd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5058cf: e8fce9fbff CALL 0x004c42d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L005058d4: { // 0x5058d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5058d5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001058e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5058e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5058e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5058e3: e8d81a0000 CALL 0x005073c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5058e8: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5058eb: 7507 JNZ 0x005058f4
    if(integer::condition("JNZ",flags)) goto L005058f4;
  }
  { // 0x5058ed: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5058ef: e86cfcfbff CALL 0x004c5560
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L005058f4: { // 0x5058f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5058f5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00109340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x509340: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x509341: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x509343: 68d8050000 PUSH 0x5d8
    f.push(m,0x000005d8u);
  }
  { // 0x509348: e80a462600 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50934d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x509350: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x509352: 7411 JZ 0x00509365
    if(integer::condition("JZ",flags)) goto L00509365;
  }
  { // 0x509354: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x509358: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x509359: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50935a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x50935c: e8df57ffff CALL 0x004feb40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x509361: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x509362: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00509365: { // 0x509365: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x509367: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x509368: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0010b030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50b030: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  { // 0x50b033: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x50b037: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x50b039: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x50b03d: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x50b041: 88442410 MOV byte ptr [ESP + 0x10],AL
    m.w8((f.sp+0x00000010u), (s.ax & 0xffu));
  }
  { // 0x50b045: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x50b049: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  { // 0x50b04d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50b04e: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x50b052: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50b053: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50b054: c744240cac897800 MOV dword ptr [ESP + 0xc],0x7889ac
    m.w32((f.sp+0x0000000cu), 0x007889acu);
  }
  { // 0x50b05c: e81f000000 CALL 0x0050b080
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50b061: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x50b065: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x50b067: e8d4412500 CALL 0x0075f240
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50b06c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x50b06e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50b06f: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x50b072: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0010ba30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50ba30: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  { // 0x50ba33: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x50ba37: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x50ba39: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x50ba3d: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x50ba41: 88442410 MOV byte ptr [ESP + 0x10],AL
    m.w8((f.sp+0x00000010u), (s.ax & 0xffu));
  }
  { // 0x50ba45: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x50ba49: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50ba4a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50ba4b: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  { // 0x50ba4f: c7442408bc897800 MOV dword ptr [ESP + 0x8],0x7889bc
    m.w32((f.sp+0x00000008u), 0x007889bcu);
  }
  { // 0x50ba57: e814000000 CALL 0x0050ba70
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50ba5c: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x50ba60: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x50ba62: e869362500 CALL 0x0075f0d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50ba67: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x50ba69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50ba6a: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x50ba6d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0010cb30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50cb30: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x50cb34: 81ec00020000 SUB ESP,0x200
    f.sp = integer::sub(f.sp,0x00000200u,32,flags);
  }
  { // 0x50cb3a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x50cb3b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50cb3c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50cb3e: 742b JZ 0x0050cb6b
    if(integer::condition("JZ",flags)) goto L0050cb6b;
  }
  { // 0x50cb40: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x50cb41: 7414 JZ 0x0050cb57
    if(integer::condition("JZ",flags)) goto L0050cb57;
  }
  { // 0x50cb43: 8b842410020000 MOV EAX,dword ptr [ESP + 0x210]
    s.ax = m.r32((f.sp+0x00000210u));
  }
  { // 0x50cb4a: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x50cb4e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50cb4f: 684c997b00 PUSH 0x7b994c
    f.push(m,0x007b994cu);
  }
  { // 0x50cb54: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50cb55: eb26 JMP 0x0050cb7d
    goto L0050cb7d;
  }
  L0050cb57: { // 0x50cb57: 8b942410020000 MOV EDX,dword ptr [ESP + 0x210]
    s.dx = m.r32((f.sp+0x00000210u));
  }
  { // 0x50cb5e: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x50cb62: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50cb63: 6820657c00 PUSH 0x7c6520
    f.push(m,0x007c6520u);
  }
  { // 0x50cb68: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50cb69: eb12 JMP 0x0050cb7d
    goto L0050cb7d;
  }
  L0050cb6b: { // 0x50cb6b: 8b8c2410020000 MOV ECX,dword ptr [ESP + 0x210]
    s.cx = m.r32((f.sp+0x00000210u));
  }
  { // 0x50cb72: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x50cb76: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50cb77: 681c657c00 PUSH 0x7c651c
    f.push(m,0x007c651cu);
  }
  { // 0x50cb7c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0050cb7d: { // 0x50cb7d: e8b20e2600 CALL 0x0076da34
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50cb82: 8b8c2418020000 MOV ECX,dword ptr [ESP + 0x218]
    s.cx = m.r32((f.sp+0x00000218u));
  }
  { // 0x50cb89: 8b942414020000 MOV EDX,dword ptr [ESP + 0x214]
    s.dx = m.r32((f.sp+0x00000214u));
  }
  { // 0x50cb90: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x50cb93: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x50cb97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50cb98: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50cb99: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50cb9a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50cb9c: e89f0e0000 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50cba1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50cba2: 81c400020000 ADD ESP,0x200
    f.sp = integer::add(f.sp,0x00000200u,32,flags);
  }
  { // 0x50cba8: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_0010d0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50d0f0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x50d0f4: 83ec40 SUB ESP,0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  { // 0x50d0f7: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  { // 0x50d0fa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50d0fb: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50d0fd: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x50d100: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50d101: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x50d104: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50d105: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x50d107: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50d108: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50d109: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  { // 0x50d10d: 682c657c00 PUSH 0x7c652c
    f.push(m,0x007c652cu);
  }
  { // 0x50d112: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50d113: e81c092600 CALL 0x0076da34
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50d118: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  { // 0x50d11c: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  { // 0x50d120: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x50d123: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x50d127: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50d128: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50d129: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50d12a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50d12c: e80f090000 CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50d131: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50d132: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  { // 0x50d135: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0010ddc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50ddc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50ddc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50ddc3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x50ddc7: e8a4c22400 CALL 0x0075a070
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50ddcc: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x50ddd0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50ddd1: e89ac22400 CALL 0x0075a070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50ddd6: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x50ddda: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50dddb: e890c22400 CALL 0x0075a070
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x50dde0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50dde1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50dde3: e858fcffff CALL 0x0050da40
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x50dde8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50dde9: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0010e210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50e210: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50e211: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50e213: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x50e217: e854db2400 CALL 0x0075bd70
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50e21c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x50e220: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50e221: e84abe2400 CALL 0x0075a070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50e226: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x50e22a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50e22b: e840be2400 CALL 0x0075a070
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x50e230: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50e231: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50e233: e808ffffff CALL 0x0050e140
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x50e238: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50e239: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0010e7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50e7d0: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x50e7d4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x50e7d6: 7417 JZ 0x0050e7ef
    if(integer::condition("JZ",flags)) goto L0050e7ef;
  }
  { // 0x50e7d8: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x50e7dc: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x50e7e0: 6860657c00 PUSH 0x7c6560
    f.push(m,0x007c6560u);
  }
  { // 0x50e7e5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50e7e6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50e7e7: e854f2ffff CALL 0x0050da40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50e7ec: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0050e7ef: { // 0x50e7ef: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x50e7f3: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x50e7f7: 685c657c00 PUSH 0x7c655c
    f.push(m,0x007c655cu);
  }
  { // 0x50e7fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50e7fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50e7fe: e83df2ffff CALL 0x0050da40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50e803: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0010e810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50e810: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50e811: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50e813: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x50e817: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x50e818: e853b82400 CALL 0x0075a070
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50e81d: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x50e821: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x50e823: e848b82400 CALL 0x0075a070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50e828: 8a4c2414 MOV CL,byte ptr [ESP + 0x14]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000014u)));
  }
  { // 0x50e82c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x50e82e: 7413 JZ 0x0050e843
    if(integer::condition("JZ",flags)) goto L0050e843;
  }
  { // 0x50e830: 6860657c00 PUSH 0x7c6560
    f.push(m,0x007c6560u);
  }
  { // 0x50e835: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x50e836: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50e837: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50e839: e802f2ffff CALL 0x0050da40
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x50e83e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x50e83f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50e840: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0050e843: { // 0x50e843: 685c657c00 PUSH 0x7c655c
    f.push(m,0x007c655cu);
  }
  { // 0x50e848: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x50e849: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50e84a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50e84c: e8eff1ffff CALL 0x0050da40
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x50e851: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x50e852: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50e853: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0010ea60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50ea60: 83ec38 SUB ESP,0x38
    f.sp = integer::sub(f.sp,0x00000038u,32,flags);
  }
  { // 0x50ea63: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x50ea64: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50ea65: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50ea67: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x50ea68: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  { // 0x50ea6c: e8ffb52400 CALL 0x0075a070
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50ea71: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  { // 0x50ea75: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x50ea77: e8f4b52400 CALL 0x0075a070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50ea7c: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x50ea7e: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  { // 0x50ea82: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x50ea85: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x50ea87: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50ea88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50ea89: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  { // 0x50ea8d: 68a8ce7b00 PUSH 0x7bcea8
    f.push(m,0x007bcea8u);
  }
  { // 0x50ea92: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50ea93: e89cef2500 CALL 0x0076da34
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x50ea98: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x50ea9b: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x50ea9f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50eaa0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x50eaa1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x50eaa2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50eaa4: e897efffff CALL 0x0050da40
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x50eaa9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x50eaaa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50eaab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x50eaac: 83c438 ADD ESP,0x38
    f.sp = integer::add(f.sp,0x00000038u,32,flags);
  }
  { // 0x50eaaf: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0010ff20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50ff20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50ff21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50ff23: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x50ff26: e86583f2ff CALL 0x00438290
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x50ff2b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50ff2d: e87e071800 CALL 0x006906b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x50ff32: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x50ff37: 7409 JZ 0x0050ff42
    if(integer::condition("JZ",flags)) goto L0050ff42;
  }
  { // 0x50ff39: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50ff3a: e83cd72500 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x50ff3f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0050ff42: { // 0x50ff42: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x50ff44: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50ff45: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001168e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5168e0: a00ca78300 MOV AL,[0x0083a70c]
    s.ax = with_al(s.ax, m.r8((0x0083a70cu)));
  }
  { // 0x5168e5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5168e7: 7504 JNZ 0x005168ed
    if(integer::condition("JNZ",flags)) goto L005168ed;
  }
  { // 0x5168e9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x5168eb: 741f JZ 0x0051690c
    if(integer::condition("JZ",flags)) goto L0051690c;
  }
  L005168ed: { // 0x5168ed: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  { // 0x5168ef: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5168f1: c6050ca7830000 MOV byte ptr [0x0083a70c],0x0
    m.w8((0x0083a70cu), 0x00000000u);
  }
  { // 0x5168f8: e853e6ffff CALL 0x00514f50
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5168fd: 8b15941c8200 MOV EDX,dword ptr [0x00821c94]
    s.dx = m.r32((0x00821c94u));
  }
  { // 0x516903: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  { // 0x516905: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x516907: e8149afcff CALL 0x004e0320
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L0051690c: { // 0x51690c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0011a290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x51a290: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x51a291: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x51a293: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  { // 0x51a296: c706a0567800 MOV dword ptr [ESI],0x7856a0
    m.w32((s.si), 0x007856a0u);
  }
  { // 0x51a29c: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  { // 0x51a2a3: e8e8dff1ff CALL 0x00438290
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x51a2a8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x51a2aa: c70658567800 MOV dword ptr [ESI],0x785658
    m.w32((s.si), 0x00785658u);
  }
  { // 0x51a2b0: e89b4ff1ff CALL 0x0042f250
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x51a2b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x51a2b6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00120130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x520130: 6827040000 PUSH 0x427
    f.push(m,0x00000427u);
  }
  { // 0x520135: 68448c7c00 PUSH 0x7c8c44
    f.push(m,0x007c8c44u);
  }
  { // 0x52013a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x52013c: b9a48c7c00 MOV ECX,0x7c8ca4
    s.cx = 0x007c8ca4u;
  }
  { // 0x520141: e81aea1c00 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x520146: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  { // 0x52014c: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  { // 0x520151: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x520153: 7406 JZ 0x0052015b
    if(integer::condition("JZ",flags)) goto L0052015b;
  }
  { // 0x520155: 8b8a405f0100 MOV ECX,dword ptr [EDX + 0x15f40]
    s.cx = m.r32((s.dx+0x00015f40u));
  }
  L0052015b: { // 0x52015b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x52015d: 6896000000 PUSH 0x96
    f.push(m,0x00000096u);
  }
  { // 0x520162: 6846400000 PUSH 0x4046
    f.push(m,0x00004046u);
  }
  { // 0x520167: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x520168: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x520169: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x52016b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x52016d: b9a05fa200 MOV ECX,0xa25fa0
    s.cx = 0x00a25fa0u;
  }
  { // 0x520172: e809180900 CALL 0x005b1980
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x520177: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00123560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x523560: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x523561: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x523563: 8b86cc000000 MOV EAX,dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  { // 0x523569: c70684f67800 MOV dword ptr [ESI],0x78f684
    m.w32((s.si), 0x0078f684u);
  }
  { // 0x52356f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x523571: 7413 JZ 0x00523586
    if(integer::condition("JZ",flags)) goto L00523586;
  }
  { // 0x523573: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x523574: e802a12400 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x523579: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x52357c: c786cc00000000000000 MOV dword ptr [ESI + 0xcc],0x0
    m.w32((s.si+0x000000ccu), 0x00000000u);
  }
  L00523586: { // 0x523586: 8b86c8000000 MOV EAX,dword ptr [ESI + 0xc8]
    s.ax = m.r32((s.si+0x000000c8u));
  }
  { // 0x52358c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52358e: 7413 JZ 0x005235a3
    if(integer::condition("JZ",flags)) goto L005235a3;
  }
  { // 0x523590: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x523591: e8e5a02400 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x523596: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x523599: c786c800000000000000 MOV dword ptr [ESI + 0xc8],0x0
    m.w32((s.si+0x000000c8u), 0x00000000u);
  }
  L005235a3: { // 0x5235a3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5235a5: c70644f67800 MOV dword ptr [ESI],0x78f644
    m.w32((s.si), 0x0078f644u);
  }
  { // 0x5235ab: e890dbf5ff CALL 0x00481140
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5235b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5235b1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00123bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x523bc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x523bc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x523bc3: 8b86cc000000 MOV EAX,dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  { // 0x523bc9: c70684f67800 MOV dword ptr [ESI],0x78f684
    m.w32((s.si), 0x0078f684u);
  }
  { // 0x523bcf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x523bd1: 7413 JZ 0x00523be6
    if(integer::condition("JZ",flags)) goto L00523be6;
  }
  { // 0x523bd3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x523bd4: e8a29a2400 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x523bd9: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x523bdc: c786cc00000000000000 MOV dword ptr [ESI + 0xcc],0x0
    m.w32((s.si+0x000000ccu), 0x00000000u);
  }
  L00523be6: { // 0x523be6: 8b86c8000000 MOV EAX,dword ptr [ESI + 0xc8]
    s.ax = m.r32((s.si+0x000000c8u));
  }
  { // 0x523bec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x523bee: 7413 JZ 0x00523c03
    if(integer::condition("JZ",flags)) goto L00523c03;
  }
  { // 0x523bf0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x523bf1: e8859a2400 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x523bf6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x523bf9: c786c800000000000000 MOV dword ptr [ESI + 0xc8],0x0
    m.w32((s.si+0x000000c8u), 0x00000000u);
  }
  L00523c03: { // 0x523c03: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x523c05: c70644f67800 MOV dword ptr [ESI],0x78f644
    m.w32((s.si), 0x0078f644u);
  }
  { // 0x523c0b: e830d5f5ff CALL 0x00481140
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x523c10: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x523c15: 7409 JZ 0x00523c20
    if(integer::condition("JZ",flags)) goto L00523c20;
  }
  { // 0x523c17: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x523c18: e85e9a2400 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x523c1d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00523c20: { // 0x523c20: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x523c22: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x523c23: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0012c240(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x52c240: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52c241: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x52c243: 689c000000 PUSH 0x9c
    f.push(m,0x0000009cu);
  }
  { // 0x52c248: e80a172400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x52c24d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x52c250: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52c252: 741d JZ 0x0052c271
    if(integer::condition("JZ",flags)) goto L0052c271;
  }
  { // 0x52c254: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x52c258: 8b9664020000 MOV EDX,dword ptr [ESI + 0x264]
    s.dx = m.r32((s.si+0x00000264u));
  }
  { // 0x52c25e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x52c25f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x52c260: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x52c262: e8c99effff CALL 0x00526130
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x52c267: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52c269: 7406 JZ 0x0052c271
    if(integer::condition("JZ",flags)) goto L0052c271;
  }
  { // 0x52c26b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x52c26d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52c26e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0052c271: { // 0x52c271: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x52c273: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52c274: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0012c280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x52c280: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52c281: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x52c283: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x52c289: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52c28b: 750f JNZ 0x0052c29c
    if(integer::condition("JNZ",flags)) goto L0052c29c;
  }
  { // 0x52c28d: 8a86c4020000 MOV AL,byte ptr [ESI + 0x2c4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000002c4u)));
  }
  { // 0x52c293: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x52c295: 7405 JZ 0x0052c29c
    if(integer::condition("JZ",flags)) goto L0052c29c;
  }
  { // 0x52c297: e824d5ffff CALL 0x005297c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L0052c29c: { // 0x52c29c: 689c000000 PUSH 0x9c
    f.push(m,0x0000009cu);
  }
  { // 0x52c2a1: e8b1162400 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x52c2a6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x52c2a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52c2ab: 7417 JZ 0x0052c2c4
    if(integer::condition("JZ",flags)) goto L0052c2c4;
  }
  { // 0x52c2ad: 8b8e64020000 MOV ECX,dword ptr [ESI + 0x264]
    s.cx = m.r32((s.si+0x00000264u));
  }
  { // 0x52c2b3: 68e4aaa300 PUSH 0xa3aae4
    f.push(m,0x00a3aae4u);
  }
  { // 0x52c2b8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x52c2b9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x52c2bb: e8709effff CALL 0x00526130
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x52c2c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52c2c1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0052c2c4: { // 0x52c2c4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x52c2c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52c2c7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0012f590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x52f590: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52f591: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x52f593: c7064c037900 MOV dword ptr [ESI],0x79034c
    m.w32((s.si), 0x0079034cu);
  }
  { // 0x52f599: c7460484027900 MOV dword ptr [ESI + 0x4],0x790284
    m.w32((s.si+0x00000004u), 0x00790284u);
  }
  { // 0x52f5a0: e82bbc0000 CALL 0x0053b1d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x52f5a5: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x52f5aa: 7409 JZ 0x0052f5b5
    if(integer::condition("JZ",flags)) goto L0052f5b5;
  }
  { // 0x52f5ac: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52f5ad: e8c9e02300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x52f5b2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0052f5b5: { // 0x52f5b5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x52f5b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52f5b8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00130c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x530c50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x530c51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x530c53: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  { // 0x530c59: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x530c5a: 25ff000080 AND EAX,0x800000ff
    s.ax = integer::logical((s.ax)&(0x800000ffu),32,flags);
  }
  { // 0x530c5f: 7907 JNS 0x00530c68
    if(integer::condition("JNS",flags)) goto L00530c68;
  }
  { // 0x530c61: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x530c62: 0d00ffffff OR EAX,0xffffff00
    s.ax = integer::logical((s.ax)|(0xffffff00u),32,flags);
  }
  { // 0x530c67: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00530c68: { // 0x530c68: 3b8614030000 CMP EAX,dword ptr [ESI + 0x314]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000314u)),32,flags);
  }
  { // 0x530c6e: 7405 JZ 0x00530c75
    if(integer::condition("JZ",flags)) goto L00530c75;
  }
  { // 0x530c70: e87b1d0800 CALL 0x005b29f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L00530c75: { // 0x530c75: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  { // 0x530c7b: 898614030000 MOV dword ptr [ESI + 0x314],EAX
    m.w32((s.si+0x00000314u), s.ax);
  }
  { // 0x530c81: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x530c84: 81e1ff000080 AND ECX,0x800000ff
    s.cx = integer::logical((s.cx)&(0x800000ffu),32,flags);
  }
  { // 0x530c8a: 7908 JNS 0x00530c94
    if(integer::condition("JNS",flags)) goto L00530c94;
  }
  { // 0x530c8c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x530c8d: 81c900ffffff OR ECX,0xffffff00
    s.cx = integer::logical((s.cx)|(0xffffff00u),32,flags);
  }
  { // 0x530c93: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00530c94: { // 0x530c94: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x530c96: 7413 JZ 0x00530cab
    if(integer::condition("JZ",flags)) goto L00530cab;
  }
  { // 0x530c98: e8531d0800 CALL 0x005b29f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x530c9d: 8b9618030000 MOV EDX,dword ptr [ESI + 0x318]
    s.dx = m.r32((s.si+0x00000318u));
  }
  { // 0x530ca3: 899614030000 MOV dword ptr [ESI + 0x314],EDX
    m.w32((s.si+0x00000314u), s.dx);
  }
  { // 0x530ca9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530caa: c3 RET
    finish(m,s,f,0u); return;
  }
  L00530cab: { // 0x530cab: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  { // 0x530cb1: 898614030000 MOV dword ptr [ESI + 0x314],EAX
    m.w32((s.si+0x00000314u), s.ax);
  }
  { // 0x530cb7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530cb8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001331b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5331b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5331b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5331b3: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x5331b6: c70644047900 MOV dword ptr [ESI],0x790444
    m.w32((s.si), 0x00790444u);
  }
  { // 0x5331bc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5331bd: e8b9a42300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5331c2: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x5331c5: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x5331cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5331cd: e8a9a42300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5331d2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5331d5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5331d7: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x5331de: e85d340d00 CALL 0x00606640
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5331e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5331e4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001334e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5334e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5334e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5334e3: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x5334e6: c70644047900 MOV dword ptr [ESI],0x790444
    m.w32((s.si), 0x00790444u);
  }
  { // 0x5334ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5334ed: e889a12300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5334f2: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x5334f5: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x5334fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5334fd: e879a12300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x533502: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x533505: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x533507: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x53350e: e82d310d00 CALL 0x00606640
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x533513: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x533518: 7409 JZ 0x00533523
    if(integer::condition("JZ",flags)) goto L00533523;
  }
  { // 0x53351a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53351b: e85ba12300 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x533520: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00533523: { // 0x533523: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x533525: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x533526: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001335a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5335a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5335a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5335a3: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x5335a6: c7065c047900 MOV dword ptr [ESI],0x79045c
    m.w32((s.si), 0x0079045cu);
  }
  { // 0x5335ac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5335ad: e8c9a02300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5335b2: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x5335b5: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x5335bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5335bd: e8b9a02300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5335c2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5335c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5335c7: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x5335ce: e8ddd01500 CALL 0x006906b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5335d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5335d4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00133740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x533740: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x533741: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x533743: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x533746: c7065c047900 MOV dword ptr [ESI],0x79045c
    m.w32((s.si), 0x0079045cu);
  }
  { // 0x53374c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53374d: e8299f2300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x533752: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x533755: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x53375c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53375d: e8199f2300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x533762: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x533765: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x533767: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x53376e: e83dcf1500 CALL 0x006906b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x533773: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x533778: 7409 JZ 0x00533783
    if(integer::condition("JZ",flags)) goto L00533783;
  }
  { // 0x53377a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53377b: e8fb9e2300 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x533780: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00533783: { // 0x533783: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x533785: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x533786: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00133bd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x533bd0: 8b0df463a500 MOV ECX,dword ptr [0x00a563f4]
    s.cx = m.r32((0x00a563f4u));
  }
  { // 0x533bd6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x533bd8: 7413 JZ 0x00533bed
    if(integer::condition("JZ",flags)) goto L00533bed;
  }
  { // 0x533bda: e821140000 CALL 0x00535000
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x533bdf: a1f463a500 MOV EAX,[0x00a563f4]
    s.ax = m.r32((0x00a563f4u));
  }
  { // 0x533be4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x533be5: e8919a2300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x533bea: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00533bed: { // 0x533bed: c705f463a50000000000 MOV dword ptr [0x00a563f4],0x0
    m.w32((0x00a563f4u), 0x00000000u);
  }
  { // 0x533bf7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00139090(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x539090: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x539092: 7436 JZ 0x005390ca
    if(integer::condition("JZ",flags)) goto L005390ca;
  }
  { // 0x539094: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x539096: 7432 JZ 0x005390ca
    if(integer::condition("JZ",flags)) goto L005390ca;
  }
  { // 0x539098: 0fbe01 MOVSX EAX,byte ptr [ECX]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.cx)),8));
  }
  { // 0x53909b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53909c: 8b7102 MOV ESI,dword ptr [ECX + 0x2]
    s.si = m.r32((s.cx+0x00000002u));
  }
  { // 0x53909f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5390a0: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x5390a3: 0fbf7906 MOVSX EDI,word ptr [ECX + 0x6]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  { // 0x5390a7: 8d4c3908 LEA ECX,[ECX + EDI*0x1 + 0x8]
    s.cx = (s.cx+(s.di * 0x00000001u)+0x00000008u);
  }
  { // 0x5390ab: 7418 JZ 0x005390c5
    if(integer::condition("JZ",flags)) goto L005390c5;
  }
  { // 0x5390ad: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x5390ae: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5390af: 740f JZ 0x005390c0
    if(integer::condition("JZ",flags)) goto L005390c0;
  }
  { // 0x5390b1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5390b2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5390b3: e8185b2300 CALL 0x0076ebd0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5390b8: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5390bb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5390bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5390be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5390bf: c3 RET
    finish(m,s,f,0u); return;
  }
  L005390c0: { // 0x5390c0: e8eb9cffff CALL 0x00532db0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L005390c5: { // 0x5390c5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5390c7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5390c8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5390c9: c3 RET
    finish(m,s,f,0u); return;
  }
  L005390ca: { // 0x5390ca: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5390cc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0013cd80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53cd80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53cd81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x53cd83: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x53cd86: c70694087900 MOV dword ptr [ESI],0x790894
    m.w32((s.si), 0x00790894u);
  }
  { // 0x53cd8c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53cd8d: e8e9082300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x53cd92: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x53cd95: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x53cd9c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53cd9d: e8d9082300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x53cda2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x53cda5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53cda7: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x53cdae: e88d980c00 CALL 0x00606640
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x53cdb3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53cdb4: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,137>& entries_a() {
  static const std::array<Entry,137> entries{{
    {0x19a0u,f_000019a0},
    {0x28b0u,f_000028b0},
    {0x2940u,f_00002940},
    {0x34b0u,f_000034b0},
    {0x36c0u,f_000036c0},
    {0x4db0u,f_00004db0},
    {0x64b0u,f_000064b0},
    {0x78f0u,f_000078f0},
    {0x8480u,f_00008480},
    {0x9210u,f_00009210},
    {0x101b0u,f_000101b0},
    {0x106e0u,f_000106e0},
    {0x10910u,f_00010910},
    {0x10960u,f_00010960},
    {0x113d0u,f_000113d0},
    {0x1beb0u,f_0001beb0},
    {0x1bed0u,f_0001bed0},
    {0x22ba0u,f_00022ba0},
    {0x26700u,f_00026700},
    {0x2b800u,f_0002b800},
    {0x2c000u,f_0002c000},
    {0x2ca50u,f_0002ca50},
    {0x2e080u,f_0002e080},
    {0x2f250u,f_0002f250},
    {0x2fcf0u,f_0002fcf0},
    {0x30fc0u,f_00030fc0},
    {0x312b0u,f_000312b0},
    {0x31570u,f_00031570},
    {0x31720u,f_00031720},
    {0x32150u,f_00032150},
    {0x32210u,f_00032210},
    {0x34680u,f_00034680},
    {0x35550u,f_00035550},
    {0x356c0u,f_000356c0},
    {0x357f0u,f_000357f0},
    {0x43e10u,f_00043e10},
    {0x49ca0u,f_00049ca0},
    {0x53700u,f_00053700},
    {0x58120u,f_00058120},
    {0x68b70u,f_00068b70},
    {0x68bb0u,f_00068bb0},
    {0x68bf0u,f_00068bf0},
    {0x68e10u,f_00068e10},
    {0x69ac0u,f_00069ac0},
    {0x69b00u,f_00069b00},
    {0x6a030u,f_0006a030},
    {0x6a0d0u,f_0006a0d0},
    {0x6a110u,f_0006a110},
    {0x6a140u,f_0006a140},
    {0x6a180u,f_0006a180},
    {0x6a4d0u,f_0006a4d0},
    {0x6a540u,f_0006a540},
    {0x6a590u,f_0006a590},
    {0x6a5f0u,f_0006a5f0},
    {0x6a6d0u,f_0006a6d0},
    {0x6a810u,f_0006a810},
    {0x6a860u,f_0006a860},
    {0x6a8b0u,f_0006a8b0},
    {0x6a930u,f_0006a930},
    {0x6a990u,f_0006a990},
    {0x6a9c0u,f_0006a9c0},
    {0x6aa30u,f_0006aa30},
    {0x6bfb0u,f_0006bfb0},
    {0x6c000u,f_0006c000},
    {0x6c060u,f_0006c060},
    {0x6c090u,f_0006c090},
    {0x6c0f0u,f_0006c0f0},
    {0x6ddd0u,f_0006ddd0},
    {0x6f930u,f_0006f930},
    {0x6f960u,f_0006f960},
    {0x6fc90u,f_0006fc90},
    {0x7bc40u,f_0007bc40},
    {0x7c750u,f_0007c750},
    {0x7cf70u,f_0007cf70},
    {0x810c0u,f_000810c0},
    {0x91660u,f_00091660},
    {0x99940u,f_00099940},
    {0x9a390u,f_0009a390},
    {0x9c910u,f_0009c910},
    {0x9ea90u,f_0009ea90},
    {0x9eb00u,f_0009eb00},
    {0xa52b0u,f_000a52b0},
    {0xb2770u,f_000b2770},
    {0xb2c30u,f_000b2c30},
    {0xbb710u,f_000bb710},
    {0xbba80u,f_000bba80},
    {0xbf1c0u,f_000bf1c0},
    {0xbf770u,f_000bf770},
    {0xcc9f0u,f_000cc9f0},
    {0xcca40u,f_000cca40},
    {0xcf280u,f_000cf280},
    {0xd20f0u,f_000d20f0},
    {0xddeb0u,f_000ddeb0},
    {0xde3b0u,f_000de3b0},
    {0xdf360u,f_000df360},
    {0xdf5a0u,f_000df5a0},
    {0xdf7d0u,f_000df7d0},
    {0xdf880u,f_000df880},
    {0xdfbf0u,f_000dfbf0},
    {0xdfcc0u,f_000dfcc0},
    {0xe2200u,f_000e2200},
    {0xe5f70u,f_000e5f70},
    {0xe6d90u,f_000e6d90},
    {0xec5e0u,f_000ec5e0},
    {0xedda0u,f_000edda0},
    {0xeeaa0u,f_000eeaa0},
    {0xfe130u,f_000fe130},
    {0xfe3d0u,f_000fe3d0},
    {0x1058c0u,f_001058c0},
    {0x1058e0u,f_001058e0},
    {0x109340u,f_00109340},
    {0x10b030u,f_0010b030},
    {0x10ba30u,f_0010ba30},
    {0x10cb30u,f_0010cb30},
    {0x10d0f0u,f_0010d0f0},
    {0x10ddc0u,f_0010ddc0},
    {0x10e210u,f_0010e210},
    {0x10e7d0u,f_0010e7d0},
    {0x10e810u,f_0010e810},
    {0x10ea60u,f_0010ea60},
    {0x10ff20u,f_0010ff20},
    {0x1168e0u,f_001168e0},
    {0x11a290u,f_0011a290},
    {0x120130u,f_00120130},
    {0x123560u,f_00123560},
    {0x123bc0u,f_00123bc0},
    {0x12c240u,f_0012c240},
    {0x12c280u,f_0012c280},
    {0x12f590u,f_0012f590},
    {0x130c50u,f_00130c50},
    {0x1331b0u,f_001331b0},
    {0x1334e0u,f_001334e0},
    {0x1335a0u,f_001335a0},
    {0x133740u,f_00133740},
    {0x133bd0u,f_00133bd0},
    {0x139090u,f_00139090},
    {0x13cd80u,f_0013cd80},
  }}; return entries;
}
} // namespace ra2::recovered::direct_b34
