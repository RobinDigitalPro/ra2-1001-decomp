#include "platform/observed_com243.hpp"
#include "recovered/recovery_b243_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b243 {
namespace {
void f_000c7c10(Memory&,State&,Frame&,const Operations&);
void f_00054870(Memory&,State&,Frame&,const Operations&);
void f_000a63d0(Memory&,State&,Frame&,const Operations&);
void f_000a6100(Memory&,State&,Frame&,const Operations&);
void f_0013b490(Memory&,State&,Frame&,const Operations&);
void f_000a6330(Memory&,State&,Frame&,const Operations&);
void f_000a6340(Memory&,State&,Frame&,const Operations&);
void f_0013b430(Memory&,State&,Frame&,const Operations&);
void f_0013b450(Memory&,State&,Frame&,const Operations&);
void f_000ca2f0(Memory&,State&,Frame&,const Operations&);
void f_0013b780(Memory&,State&,Frame&,const Operations&);
void f_000a5cd0(Memory&,State&,Frame&,const Operations&);
void f_000a5e90(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000c7c10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004c7c10: { // 0x4c7c10: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004c7c14: { // 0x4c7c14: 83ec1c SUB ESP, 0x1C
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L004c7c17: { // 0x4c7c17: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004c7c18: { // 0x4c7c18: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004c7c19: { // 0x4c7c19: 8be9 MOV EBP, ECX
    s.bp = s.cx;
  }
  L004c7c1b: { // 0x4c7c1b: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004c7c1d: { // 0x4c7c1d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004c7c1e: { // 0x4c7c1e: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004c7c20: { // 0x4c7c20: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004c7c21: { // 0x4c7c21: 899d90040000 MOV dword ptr [EBP + 0x490], EBX
    m.w32((s.bp+0x00000490u), s.bx);
  }
  L004c7c27: { // 0x4c7c27: 898594040000 MOV dword ptr [EBP + 0x494], EAX
    m.w32((s.bp+0x00000494u), s.ax);
  }
  L004c7c2d: { // 0x4c7c2d: 0f8427010000 JZ 0x4C7D5A
    if(integer::condition("JZ",flags)) goto L004c7d5a;
  }
  L004c7c33: { // 0x4c7c33: 8b8d5c020000 MOV ECX, dword ptr [EBP + 0x25C]
    s.cx = m.r32((s.bp+0x0000025cu));
  }
  L004c7c39: { // 0x4c7c39: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004c7c3b: { // 0x4c7c3b: 740e JZ 0x4C7C4B
    if(integer::condition("JZ",flags)) goto L004c7c4b;
  }
  L004c7c3d: { // 0x4c7c3d: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004c7c3f: { // 0x4c7c3f: ff90f0000000 CALL dword ptr [EAX + 0xF0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000f0u)),5012549u); flags=s.arithmetic_flags;
  }
  L004c7c45: { // 0x4c7c45: 899d5c020000 MOV dword ptr [EBP + 0x25C], EBX
    m.w32((s.bp+0x0000025cu), s.bx);
  }
  L004c7c4b: { // 0x4c7c4b: 8b8d64050000 MOV ECX, dword ptr [EBP + 0x564]
    s.cx = m.r32((s.bp+0x00000564u));
  }
  L004c7c51: { // 0x4c7c51: 8d8564050000 LEA EAX, [EBP + 0x564]
    s.ax = (s.bp+0x00000564u);
  }
  L004c7c57: { // 0x4c7c57: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004c7c59: { // 0x4c7c59: 895c2430 MOV dword ptr [ESP + 0x30], EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L004c7c5d: { // 0x4c7c5d: 7423 JZ 0x4C7C82
    if(integer::condition("JZ",flags)) goto L004c7c82;
  }
  L004c7c5f: { // 0x4c7c5f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c7c60: { // 0x4c7c60: 8d4c2434 LEA ECX, [ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L004c7c64: { // 0x4c7c64: e807ccf8ff CALL 0x454870
    s.arithmetic_flags=flags; invoke(m,s,f,0x00454870u,5012585u); flags=s.arithmetic_flags;
  }
  L004c7c69: { // 0x4c7c69: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004c7c6b: { // 0x4c7c6b: 7d0d JGE 0x4C7C7A
    if(integer::condition("JGE",flags)) goto L004c7c7a;
  }
  L004c7c6d: { // 0x4c7c6d: 3d02400080 CMP EAX, 0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L004c7c72: { // 0x4c7c72: 7406 JZ 0x4C7C7A
    if(integer::condition("JZ",flags)) goto L004c7c7a;
  }
  L004c7c74: { // 0x4c7c74: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c7c75: { // 0x4c7c75: e8f6952b00 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5012602u); flags=s.arithmetic_flags;
  }
  L004c7c7a: { // 0x4c7c7a: 8b442430 MOV EAX, dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L004c7c7e: { // 0x4c7c7e: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004c7c80: { // 0x4c7c80: 750e JNZ 0x4C7C90
    if(integer::condition("JNZ",flags)) goto L004c7c90;
  }
  L004c7c82: { // 0x4c7c82: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L004c7c87: { // 0x4c7c87: e8e4952b00 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5012620u); flags=s.arithmetic_flags;
  }
  L004c7c8c: { // 0x4c7c8c: 8b442430 MOV EAX, dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L004c7c90: { // 0x4c7c90: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004c7c92: { // 0x4c7c92: 8d54241c LEA EDX, [ESP + 0x1C]
    s.dx = (f.sp+0x0000001cu);
  }
  L004c7c96: { // 0x4c7c96: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004c7c97: { // 0x4c7c97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c7c98: { // 0x4c7c98: ff510c CALL dword ptr [ECX + 0xC]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000000cu)),5012635u); flags=s.arithmetic_flags;
  }
  L004c7c9b: { // 0x4c7c9b: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L004c7ca0: { // 0x4c7ca0: bf80cf7800 MOV EDI, 0x78CF80
    s.di = 0x0078cf80u;
  }
  L004c7ca5: { // 0x4c7ca5: 8d74241c LEA ESI, [ESP + 0x1C]
    s.si = (f.sp+0x0000001cu);
  }
  L004c7ca9: { // 0x4c7ca9: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004c7cab: { // 0x4c7cab: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004c7cad: { // 0x4c7cad: 7540 JNZ 0x4C7CEF
    if(integer::condition("JNZ",flags)) goto L004c7cef;
  }
  L004c7caf: { // 0x4c7caf: 8b9530050000 MOV EDX, dword ptr [EBP + 0x530]
    s.dx = m.r32((s.bp+0x00000530u));
  }
  L004c7cb5: { // 0x4c7cb5: 8b8538050000 MOV EAX, dword ptr [EBP + 0x538]
    s.ax = m.r32((s.bp+0x00000538u));
  }
  L004c7cbb: { // 0x4c7cbb: 8b356c89a200 MOV ESI, dword ptr [0xA2896C]
    s.si = m.r32((0x00a2896cu));
  }
  L004c7cc1: { // 0x4c7cc1: 83faff CMP EDX, -1
    (void)integer::sub(s.dx,4294967295u,32,flags);
  }
  L004c7cc4: { // 0x4c7cc4: 740a JZ 0x4C7CD0
    if(integer::condition("JZ",flags)) goto L004c7cd0;
  }
  L004c7cc6: { // 0x4c7cc6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004c7cc8: { // 0x4c7cc8: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004c7cca: { // 0x4c7cca: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004c7ccc: { // 0x4c7ccc: 7d06 JGE 0x4C7CD4
    if(integer::condition("JGE",flags)) goto L004c7cd4;
  }
  L004c7cce: { // 0x4c7cce: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L004c7cd0: { // 0x4c7cd0: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004c7cd2: { // 0x4c7cd2: 751b JNZ 0x4C7CEF
    if(integer::condition("JNZ",flags)) goto L004c7cef;
  }
  L004c7cd4: { // 0x4c7cd4: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004c7cd8: { // 0x4c7cd8: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004c7cdd: { // 0x4c7cdd: 89b530050000 MOV dword ptr [EBP + 0x530], ESI
    m.w32((s.bp+0x00000530u), s.si);
  }
  L004c7ce3: { // 0x4c7ce3: 898d34050000 MOV dword ptr [EBP + 0x534], ECX
    m.w32((s.bp+0x00000534u), s.cx);
  }
  L004c7ce9: { // 0x4c7ce9: 898538050000 MOV dword ptr [EBP + 0x538], EAX
    m.w32((s.bp+0x00000538u), s.ax);
  }
  L004c7cef: { // 0x4c7cef: 8a8598050000 MOV AL, byte ptr [EBP + 0x598]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000598u)));
  }
  L004c7cf5: { // 0x4c7cf5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004c7cf7: { // 0x4c7cf7: 7409 JZ 0x4C7D02
    if(integer::condition("JZ",flags)) goto L004c7d02;
  }
  L004c7cf9: { // 0x4c7cf9: c6859805000000 MOV byte ptr [EBP + 0x598], 0
    m.w8((s.bp+0x00000598u), 0u);
  }
  L004c7d00: { // 0x4c7d00: eb48 JMP 0x4C7D4A
    goto L004c7d4a;
  }
  L004c7d02: { // 0x4c7d02: 8b8d94040000 MOV ECX, dword ptr [EBP + 0x494]
    s.cx = m.r32((s.bp+0x00000494u));
  }
  L004c7d08: { // 0x4c7d08: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L004c7d0c: { // 0x4c7d0c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004c7d0d: { // 0x4c7d0d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c7d0e: { // 0x4c7d0e: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004c7d10: { // 0x4c7d10: ff524c CALL dword ptr [EDX + 0x4C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000004cu)),5012755u); flags=s.arithmetic_flags;
  }
  L004c7d13: { // 0x4c7d13: 8b30 MOV ESI, dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L004c7d15: { // 0x4c7d15: 8b7804 MOV EDI, dword ptr [EAX + 4]
    s.di = m.r32((s.ax+4u));
  }
  L004c7d18: { // 0x4c7d18: 8b5808 MOV EBX, dword ptr [EAX + 8]
    s.bx = m.r32((s.ax+8u));
  }
  L004c7d1b: { // 0x4c7d1b: 8b8564050000 MOV EAX, dword ptr [EBP + 0x564]
    s.ax = m.r32((s.bp+0x00000564u));
  }
  L004c7d21: { // 0x4c7d21: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004c7d23: { // 0x4c7d23: 750a JNZ 0x4C7D2F
    if(integer::condition("JNZ",flags)) goto L004c7d2f;
  }
  L004c7d25: { // 0x4c7d25: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L004c7d2a: { // 0x4c7d2a: e841952b00 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5012783u); flags=s.arithmetic_flags;
  }
  L004c7d2f: { // 0x4c7d2f: 8b8564050000 MOV EAX, dword ptr [EBP + 0x564]
    s.ax = m.r32((s.bp+0x00000564u));
  }
  L004c7d35: { // 0x4c7d35: 83ec0c SUB ESP, 0xC
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004c7d38: { // 0x4c7d38: 8bd4 MOV EDX, ESP
    s.dx = f.sp;
  }
  L004c7d3a: { // 0x4c7d3a: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004c7d3c: { // 0x4c7d3c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c7d3d: { // 0x4c7d3d: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L004c7d3f: { // 0x4c7d3f: 897a04 MOV dword ptr [EDX + 4], EDI
    m.w32((s.dx+4u), s.di);
  }
  L004c7d42: { // 0x4c7d42: 895a08 MOV dword ptr [EDX + 8], EBX
    m.w32((s.dx+8u), s.bx);
  }
  L004c7d45: { // 0x4c7d45: ff5144 CALL dword ptr [ECX + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000044u)),5012808u); flags=s.arithmetic_flags;
  }
  L004c7d48: { // 0x4c7d48: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004c7d4a: { // 0x4c7d4a: 8b442430 MOV EAX, dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L004c7d4e: { // 0x4c7d4e: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004c7d50: { // 0x4c7d50: 7458 JZ 0x4C7DAA
    if(integer::condition("JZ",flags)) goto L004c7daa;
  }
  L004c7d52: { // 0x4c7d52: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004c7d54: { // 0x4c7d54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c7d55: { // 0x4c7d55: ff5108 CALL dword ptr [ECX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+8u)),5012824u); flags=s.arithmetic_flags;
  }
  L004c7d58: { // 0x4c7d58: eb50 JMP 0x4C7DAA
    goto L004c7daa;
  }
  L004c7d5a: { // 0x4c7d5a: 8b5500 MOV EDX, dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L004c7d5d: { // 0x4c7d5d: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L004c7d5f: { // 0x4c7d5f: ff522c CALL dword ptr [EDX + 0x2C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),5012834u); flags=s.arithmetic_flags;
  }
  L004c7d62: { // 0x4c7d62: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L004c7d65: { // 0x4c7d65: 751f JNZ 0x4C7D86
    if(integer::condition("JNZ",flags)) goto L004c7d86;
  }
  L004c7d67: { // 0x4c7d67: 8b8d98000000 MOV ECX, dword ptr [EBP + 0x98]
    s.cx = m.r32((s.bp+0x00000098u));
  }
  L004c7d6d: { // 0x4c7d6d: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004c7d72: { // 0x4c7d72: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004c7d74: { // 0x4c7d74: 7408 JZ 0x4C7D7E
    if(integer::condition("JZ",flags)) goto L004c7d7e;
  }
  L004c7d76: { // 0x4c7d76: 3985a0000000 CMP dword ptr [EBP + 0xA0], EAX
    (void)integer::sub(m.r32((s.bp+0x000000a0u)),s.ax,32,flags);
  }
  L004c7d7c: { // 0x4c7d7c: 7508 JNZ 0x4C7D86
    if(integer::condition("JNZ",flags)) goto L004c7d86;
  }
  L004c7d7e: { // 0x4c7d7e: 399d28020000 CMP dword ptr [EBP + 0x228], EBX
    (void)integer::sub(m.r32((s.bp+0x00000228u)),s.bx,32,flags);
  }
  L004c7d84: { // 0x4c7d84: 7524 JNZ 0x4C7DAA
    if(integer::condition("JNZ",flags)) goto L004c7daa;
  }
  L004c7d86: { // 0x4c7d86: 399d64050000 CMP dword ptr [EBP + 0x564], EBX
    (void)integer::sub(m.r32((s.bp+0x00000564u)),s.bx,32,flags);
  }
  L004c7d8c: { // 0x4c7d8c: 750a JNZ 0x4C7D98
    if(integer::condition("JNZ",flags)) goto L004c7d98;
  }
  L004c7d8e: { // 0x4c7d8e: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L004c7d93: { // 0x4c7d93: e8d8942b00 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5012888u); flags=s.arithmetic_flags;
  }
  L004c7d98: { // 0x4c7d98: 8b8564050000 MOV EAX, dword ptr [EBP + 0x564]
    s.ax = m.r32((s.bp+0x00000564u));
  }
  L004c7d9e: { // 0x4c7d9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c7d9f: { // 0x4c7d9f: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004c7da1: { // 0x4c7da1: ff5148 CALL dword ptr [ECX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000048u)),5012900u); flags=s.arithmetic_flags;
  }
  L004c7da4: { // 0x4c7da4: 899d94040000 MOV dword ptr [EBP + 0x494], EBX
    m.w32((s.bp+0x00000494u), s.bx);
  }
  L004c7daa: { // 0x4c7daa: c685a105000000 MOV byte ptr [EBP + 0x5A1], 0
    m.w8((s.bp+0x000005a1u), 0u);
  }
  L004c7db1: { // 0x4c7db1: 8b15881b8200 MOV EDX, dword ptr [0x821B88]
    s.dx = m.r32((0x00821b88u));
  }
  L004c7db7: { // 0x4c7db7: a16c89a200 MOV EAX, dword ptr [0xA2896C]
    s.ax = m.r32((0x00a2896cu));
  }
  L004c7dbc: { // 0x4c7dbc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c7dbd: { // 0x4c7dbd: 8b8ad0130000 MOV ECX, dword ptr [EDX + 0x13D0]
    s.cx = m.r32((s.dx+0x000013d0u));
  }
  L004c7dc3: { // 0x4c7dc3: 8d9558050000 LEA EDX, [EBP + 0x558]
    s.dx = (s.bp+0x00000558u);
  }
  L004c7dc9: { // 0x4c7dc9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c7dca: { // 0x4c7dca: 8902 MOV dword ptr [EDX], EAX
    m.w32((s.dx), s.ax);
  }
  L004c7dcc: { // 0x4c7dcc: 8b44240c MOV EAX, dword ptr [ESP + 0xC]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L004c7dd0: { // 0x4c7dd0: 894204 MOV dword ptr [EDX + 4], EAX
    m.w32((s.dx+4u), s.ax);
  }
  L004c7dd3: { // 0x4c7dd3: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L004c7dd6: { // 0x4c7dd6: a16c89a200 MOV EAX, dword ptr [0xA2896C]
    s.ax = m.r32((0x00a2896cu));
  }
  L004c7ddb: { // 0x4c7ddb: 8b54240c MOV EDX, dword ptr [ESP + 0xC]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L004c7ddf: { // 0x4c7ddf: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004c7de1: { // 0x4c7de1: 81c530050000 ADD EBP, 0x530
    s.bp = integer::add(s.bp,0x00000530u,32,flags);
  }
  L004c7de7: { // 0x4c7de7: 894500 MOV dword ptr [EBP], EAX
    m.w32((s.bp), s.ax);
  }
  L004c7dea: { // 0x4c7dea: 895504 MOV dword ptr [EBP + 4], EDX
    m.w32((s.bp+4u), s.dx);
  }
  L004c7ded: { // 0x4c7ded: 894d08 MOV dword ptr [EBP + 8], ECX
    m.w32((s.bp+8u), s.cx);
  }
  L004c7df0: { // 0x4c7df0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004c7df1: { // 0x4c7df1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c7df2: { // 0x4c7df2: 83c41c ADD ESP, 0x1C
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L004c7df5: { // 0x4c7df5: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00054870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00454870: { // 0x454870: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00454874: { // 0x454874: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00454875: { // 0x454875: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00454876: { // 0x454876: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00454878: { // 0x454878: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0045487a: { // 0x45487a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045487c: { // 0x45487c: 7449 JZ 0x4548C7
    if(integer::condition("JZ",flags)) goto L004548c7;
  }
  L0045487e: { // 0x45487e: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00454880: { // 0x454880: 8d54240c LEA EDX, [ESP + 0xC]
    s.dx = (f.sp+0x0000000cu);
  }
  L00454884: { // 0x454884: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00454885: { // 0x454885: 6898a17b00 PUSH 0x7BA198
    f.push(m,0x007ba198u);
  }
  L0045488a: { // 0x45488a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045488b: { // 0x45488b: ff11 CALL dword ptr [ECX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx)),4540557u); flags=s.arithmetic_flags;
  }
  L0045488d: { // 0x45488d: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0045488f: { // 0x45488f: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00454891: { // 0x454891: 7d19 JGE 0x4548AC
    if(integer::condition("JGE",flags)) goto L004548ac;
  }
  L00454893: { // 0x454893: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00454895: { // 0x454895: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00454897: { // 0x454897: 7406 JZ 0x45489F
    if(integer::condition("JZ",flags)) goto L0045489f;
  }
  L00454899: { // 0x454899: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0045489b: { // 0x45489b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0045489c: { // 0x45489c: ff5108 CALL dword ptr [ECX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+8u)),4540575u); flags=s.arithmetic_flags;
  }
  L0045489f: { // 0x45489f: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004548a1: { // 0x4548a1: c70600000000 MOV dword ptr [ESI], 0
    m.w32((s.si), 0u);
  }
  L004548a7: { // 0x4548a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004548a8: { // 0x4548a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004548a9: { // 0x4548a9: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004548ac: { // 0x4548ac: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004548ae: { // 0x4548ae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004548af: { // 0x4548af: 8b5c2410 MOV EBX, dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L004548b3: { // 0x4548b3: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004548b5: { // 0x4548b5: 7406 JZ 0x4548BD
    if(integer::condition("JZ",flags)) goto L004548bd;
  }
  L004548b7: { // 0x4548b7: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004548b9: { // 0x4548b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004548ba: { // 0x4548ba: ff5208 CALL dword ptr [EDX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+8u)),4540605u); flags=s.arithmetic_flags;
  }
  L004548bd: { // 0x4548bd: 891e MOV dword ptr [ESI], EBX
    m.w32((s.si), s.bx);
  }
  L004548bf: { // 0x4548bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004548c0: { // 0x4548c0: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004548c2: { // 0x4548c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004548c3: { // 0x4548c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004548c4: { // 0x4548c4: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004548c7: { // 0x4548c7: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004548c9: { // 0x4548c9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004548cb: { // 0x4548cb: 740c JZ 0x4548D9
    if(integer::condition("JZ",flags)) goto L004548d9;
  }
  L004548cd: { // 0x4548cd: c70600000000 MOV dword ptr [ESI], 0
    m.w32((s.si), 0u);
  }
  L004548d3: { // 0x4548d3: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004548d5: { // 0x4548d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004548d6: { // 0x4548d6: ff5108 CALL dword ptr [ECX + 8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+8u)),4540633u); flags=s.arithmetic_flags;
  }
  L004548d9: { // 0x4548d9: bf02400080 MOV EDI, 0x80004002
    s.di = 0x80004002u;
  }
  L004548de: { // 0x4548de: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L004548e0: { // 0x4548e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004548e1: { // 0x4548e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004548e2: { // 0x4548e2: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000a63d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a63d0: { // 0x4a63d0: 836c240404 SUB dword ptr [ESP + 4], 4
    m.w32((f.sp+4u), integer::sub(m.r32((f.sp+4u)),4u,32,flags));
  }
  L004a63d5: { // 0x4a63d5: e926fdffff JMP 0x4A6100
    f_000a6100(m,s,f,op);return;
  }
}
void f_000a6100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a6100: { // 0x4a6100: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a6101: { // 0x4a6101: 8b5c2408 MOV EBX, dword ptr [ESP + 8]
    s.bx = m.r32((f.sp+8u));
  }
  L004a6105: { // 0x4a6105: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004a6106: { // 0x4a6106: 8b6c2414 MOV EBP, dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L004a610a: { // 0x4a610a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a610b: { // 0x4a610b: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L004a610f: { // 0x4a610f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004a6110: { // 0x4a6110: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a6111: { // 0x4a6111: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a6112: { // 0x4a6112: e879530900 CALL 0x53B490
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053b490u,4874519u); flags=s.arithmetic_flags;
  }
  L004a6117: { // 0x4a6117: 3d02400080 CMP EAX, 0x80004002
    (void)integer::sub(s.ax,0x80004002u,32,flags);
  }
  L004a611c: { // 0x4a611c: 7539 JNZ 0x4A6157
    if(integer::condition("JNZ",flags)) goto L004a6157;
  }
  L004a611e: { // 0x4a611e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004a611f: { // 0x4a611f: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L004a6124: { // 0x4a6124: bf50d07800 MOV EDI, 0x78D050
    s.di = 0x0078d050u;
  }
  L004a6129: { // 0x4a6129: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004a612b: { // 0x4a612b: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L004a612d: { // 0x4a612d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004a612e: { // 0x4a612e: 750e JNZ 0x4A613E
    if(integer::condition("JNZ",flags)) goto L004a613e;
  }
  L004a6130: { // 0x4a6130: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004a6132: { // 0x4a6132: 7405 JZ 0x4A6139
    if(integer::condition("JZ",flags)) goto L004a6139;
  }
  L004a6134: { // 0x4a6134: 8d4318 LEA EAX, [EBX + 0x18]
    s.ax = (s.bx+0x00000018u);
  }
  L004a6137: { // 0x4a6137: eb02 JMP 0x4A613B
    goto L004a613b;
  }
  L004a6139: { // 0x4a6139: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004a613b: { // 0x4a613b: 894500 MOV dword ptr [EBP], EAX
    m.w32((s.bp), s.ax);
  }
  L004a613e: { // 0x4a613e: 837d0000 CMP dword ptr [EBP], 0
    (void)integer::sub(m.r32((s.bp)),0u,32,flags);
  }
  L004a6142: { // 0x4a6142: 750b JNZ 0x4A614F
    if(integer::condition("JNZ",flags)) goto L004a614f;
  }
  L004a6144: { // 0x4a6144: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a6145: { // 0x4a6145: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a6146: { // 0x4a6146: b802400080 MOV EAX, 0x80004002
    s.ax = 0x80004002u;
  }
  L004a614b: { // 0x4a614b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004a614c: { // 0x4a614c: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004a614f: { // 0x4a614f: 8b0b MOV ECX, dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L004a6151: { // 0x4a6151: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a6152: { // 0x4a6152: ff5104 CALL dword ptr [ECX + 4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+4u)),4874581u); flags=s.arithmetic_flags;
  }
  L004a6155: { // 0x4a6155: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004a6157: { // 0x4a6157: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a6158: { // 0x4a6158: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004a6159: { // 0x4a6159: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004a615a: { // 0x4a615a: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0013b490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0053b490: { // 0x53b490: 8b44240c MOV EAX, dword ptr [ESP + 0xC]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0053b494: { // 0x53b494: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0053b496: { // 0x53b496: 7508 JNZ 0x53B4A0
    if(integer::condition("JNZ",flags)) goto L0053b4a0;
  }
  L0053b498: { // 0x53b498: b803400080 MOV EAX, 0x80004003
    s.ax = 0x80004003u;
  }
  L0053b49d: { // 0x53b49d: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0053b4a0: { // 0x53b4a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0053b4a1: { // 0x53b4a1: 8b5c240c MOV EBX, dword ptr [ESP + 0xC]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L0053b4a5: { // 0x53b4a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0053b4a6: { // 0x53b4a6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053b4a7: { // 0x53b4a7: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L0053b4ac: { // 0x53b4ac: bff8aa7900 MOV EDI, 0x79AAF8
    s.di = 0x0079aaf8u;
  }
  L0053b4b1: { // 0x53b4b1: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L0053b4b3: { // 0x53b4b3: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0053b4b5: { // 0x53b4b5: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0053b4b9: { // 0x53b4b9: c70000000000 MOV dword ptr [EAX], 0
    m.w32((s.ax), 0u);
  }
  L0053b4bf: { // 0x53b4bf: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0053b4c1: { // 0x53b4c1: 750d JNZ 0x53B4D0
    if(integer::condition("JNZ",flags)) goto L0053b4d0;
  }
  L0053b4c3: { // 0x53b4c3: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0053b4c5: { // 0x53b4c5: 7405 JZ 0x53B4CC
    if(integer::condition("JZ",flags)) goto L0053b4cc;
  }
  L0053b4c7: { // 0x53b4c7: 8d4a04 LEA ECX, [EDX + 4]
    s.cx = (s.dx+4u);
  }
  L0053b4ca: { // 0x53b4ca: eb02 JMP 0x53B4CE
    goto L0053b4ce;
  }
  L0053b4cc: { // 0x53b4cc: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0053b4ce: { // 0x53b4ce: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L0053b4d0: { // 0x53b4d0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0053b4d1: { // 0x53b4d1: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L0053b4d6: { // 0x53b4d6: bfe8aa7900 MOV EDI, 0x79AAE8
    s.di = 0x0079aae8u;
  }
  L0053b4db: { // 0x53b4db: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L0053b4dd: { // 0x53b4dd: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0053b4df: { // 0x53b4df: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0053b4e1: { // 0x53b4e1: 7502 JNZ 0x53B4E5
    if(integer::condition("JNZ",flags)) goto L0053b4e5;
  }
  L0053b4e3: { // 0x53b4e3: 8910 MOV dword ptr [EAX], EDX
    m.w32((s.ax), s.dx);
  }
  L0053b4e5: { // 0x53b4e5: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L0053b4ea: { // 0x53b4ea: bf70087900 MOV EDI, 0x790870
    s.di = 0x00790870u;
  }
  L0053b4ef: { // 0x53b4ef: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L0053b4f1: { // 0x53b4f1: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0053b4f3: { // 0x53b4f3: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  L0053b4f5: { // 0x53b4f5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0053b4f6: { // 0x53b4f6: 750d JNZ 0x53B505
    if(integer::condition("JNZ",flags)) goto L0053b505;
  }
  L0053b4f8: { // 0x53b4f8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0053b4fa: { // 0x53b4fa: 7405 JZ 0x53B501
    if(integer::condition("JZ",flags)) goto L0053b501;
  }
  L0053b4fc: { // 0x53b4fc: 8d4a04 LEA ECX, [EDX + 4]
    s.cx = (s.dx+4u);
  }
  L0053b4ff: { // 0x53b4ff: eb02 JMP 0x53B503
    goto L0053b503;
  }
  L0053b501: { // 0x53b501: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0053b503: { // 0x53b503: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L0053b505: { // 0x53b505: 8bf3 MOV ESI, EBX
    s.si = s.bx;
  }
  L0053b507: { // 0x53b507: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L0053b50c: { // 0x53b50c: bfd8aa7900 MOV EDI, 0x79AAD8
    s.di = 0x0079aad8u;
  }
  L0053b511: { // 0x53b511: 33db XOR EBX, EBX
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
  L0053b518: { // 0x53b518: 7502 JNZ 0x53B51C
    if(integer::condition("JNZ",flags)) goto L0053b51c;
  }
  L0053b51a: { // 0x53b51a: 8910 MOV dword ptr [EAX], EDX
    m.w32((s.ax), s.dx);
  }
  L0053b51c: { // 0x53b51c: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L0053b51f: { // 0x53b51f: 7508 JNZ 0x53B529
    if(integer::condition("JNZ",flags)) goto L0053b529;
  }
  L0053b521: { // 0x53b521: b802400080 MOV EAX, 0x80004002
    s.ax = 0x80004002u;
  }
  L0053b526: { // 0x53b526: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0053b529: { // 0x53b529: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0053b52b: { // 0x53b52b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0053b52c: { // 0x53b52c: ff5004 CALL dword ptr [EAX + 4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+4u)),5485871u); flags=s.arithmetic_flags;
  }
  L0053b52f: { // 0x53b52f: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0053b531: { // 0x53b531: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_000a6330(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a6330: { // 0x4a6330: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004a6334: { // 0x4a6334: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a6335: { // 0x4a6335: e8f6500900 CALL 0x53B430
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053b430u,4875066u); flags=s.arithmetic_flags;
  }
  L004a633a: { // 0x4a633a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000a6340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a6340: { // 0x4a6340: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L004a6344: { // 0x4a6344: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a6345: { // 0x4a6345: e806510900 CALL 0x53B450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0053b450u,4875082u); flags=s.arithmetic_flags;
  }
  L004a634a: { // 0x4a634a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0013b430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0053b430: { // 0x53b430: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L0053b434: { // 0x53b434: 8b154467a500 MOV EDX, dword ptr [0xA56744]
    s.dx = m.r32((0x00a56744u));
  }
  L0053b43a: { // 0x53b43a: 83c014 ADD EAX, 0x14
    s.ax = integer::add(s.ax,0x00000014u,32,flags);
  }
  L0053b43d: { // 0x53b43d: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0053b43e: { // 0x53b43e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0053b43f: { // 0x53b43f: 89154467a500 MOV dword ptr [0xA56744], EDX
    m.w32((0x00a56744u), s.dx);
  }
  L0053b445: { // 0x53b445: ff15bc517800 CALL dword ptr [0x7851BC]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007851bcu)),5485643u); flags=s.arithmetic_flags;
  }
  L0053b44b: { // 0x53b44b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0013b450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0053b450: { // 0x53b450: 8b154467a500 MOV EDX, dword ptr [0xA56744]
    s.dx = m.r32((0x00a56744u));
  }
  L0053b456: { // 0x53b456: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0053b457: { // 0x53b457: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053b458: { // 0x53b458: 8b7c240c MOV EDI, dword ptr [ESP + 0xC]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0053b45c: { // 0x53b45c: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0053b45d: { // 0x53b45d: 8d4714 LEA EAX, [EDI + 0x14]
    s.ax = (s.di+0x00000014u);
  }
  L0053b460: { // 0x53b460: 89154467a500 MOV dword ptr [0xA56744], EDX
    m.w32((0x00a56744u), s.dx);
  }
  L0053b466: { // 0x53b466: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0053b467: { // 0x53b467: ff15c0517800 CALL dword ptr [0x7851C0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007851c0u)),5485677u); flags=s.arithmetic_flags;
  }
  L0053b46d: { // 0x53b46d: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L0053b46f: { // 0x53b46f: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0053b471: { // 0x53b471: 750d JNZ 0x53B480
    if(integer::condition("JNZ",flags)) goto L0053b480;
  }
  L0053b473: { // 0x53b473: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0053b475: { // 0x53b475: 7409 JZ 0x53B480
    if(integer::condition("JZ",flags)) goto L0053b480;
  }
  L0053b477: { // 0x53b477: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0053b479: { // 0x53b479: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0053b47b: { // 0x53b47b: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0053b47d: { // 0x53b47d: ff5220 CALL dword ptr [EDX + 0x20]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000020u)),5485696u); flags=s.arithmetic_flags;
  }
  L0053b480: { // 0x53b480: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0053b482: { // 0x53b482: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053b483: { // 0x53b483: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053b484: { // 0x53b484: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000ca2f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ca2f0: { // 0x4ca2f0: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004ca2f3: { // 0x4ca2f3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ca2f4: { // 0x4ca2f4: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004ca2f6: { // 0x4ca2f6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ca2f7: { // 0x4ca2f7: 8a8674050000 MOV AL, byte ptr [ESI + 0x574]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000574u)));
  }
  L004ca2fd: { // 0x4ca2fd: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ca2ff: { // 0x4ca2ff: 7c45 JL 0x4CA346
    if(integer::condition("JL",flags)) goto L004ca346;
  }
  L004ca301: { // 0x4ca301: 8b0dfce48400 MOV ECX, dword ptr [0x84E4FC]
    s.cx = m.r32((0x0084e4fcu));
  }
  L004ca307: { // 0x4ca307: 0fbec0 MOVSX EAX, AL
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffu),8));
  }
  L004ca30a: { // 0x4ca30a: 8b1481 MOV EDX, dword ptr [ECX + EAX*4]
    s.dx = m.r32((s.cx+(s.ax * 4u)));
  }
  L004ca30d: { // 0x4ca30d: 8b4228 MOV EAX, dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  L004ca310: { // 0x4ca310: 0fbfc8 MOVSX ECX, AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ca313: { // 0x4ca313: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L004ca317: { // 0x4ca317: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004ca31b: { // 0x4ca31b: 0fbf54240a MOVSX EDX, word ptr [ESP + 0xA]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000000au)),16));
  }
  L004ca320: { // 0x4ca320: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L004ca323: { // 0x4ca323: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004ca325: { // 0x4ca325: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L004ca32b: { // 0x4ca32b: c1e208 SHL EDX, 8
    s.dx = integer::shift(s.dx,8u,32,flags,integer::Shift::left);
  }
  L004ca32e: { // 0x4ca32e: 890f MOV dword ptr [EDI], ECX
    m.w32((s.di), s.cx);
  }
  L004ca330: { // 0x4ca330: 81c280000000 ADD EDX, 0x80
    s.dx = integer::add(s.dx,0x00000080u,32,flags);
  }
  L004ca336: { // 0x4ca336: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004ca338: { // 0x4ca338: 895704 MOV dword ptr [EDI + 4], EDX
    m.w32((s.di+4u), s.dx);
  }
  L004ca33b: { // 0x4ca33b: 897708 MOV dword ptr [EDI + 8], ESI
    m.w32((s.di+8u), s.si);
  }
  L004ca33e: { // 0x4ca33e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ca33f: { // 0x4ca33f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ca340: { // 0x4ca340: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004ca343: { // 0x4ca343: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004ca346: { // 0x4ca346: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004ca34c: { // 0x4ca34c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ca34e: { // 0x4ca34e: 750a JNZ 0x4CA35A
    if(integer::condition("JNZ",flags)) goto L004ca35a;
  }
  L004ca350: { // 0x4ca350: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L004ca355: { // 0x4ca355: e8166f2b00 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5022554u); flags=s.arithmetic_flags;
  }
  L004ca35a: { // 0x4ca35a: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L004ca360: { // 0x4ca360: 8d54240c LEA EDX, [ESP + 0xC]
    s.dx = (f.sp+0x0000000cu);
  }
  L004ca364: { // 0x4ca364: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004ca365: { // 0x4ca365: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ca366: { // 0x4ca366: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ca368: { // 0x4ca368: ff5118 CALL dword ptr [ECX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000018u)),5022571u); flags=s.arithmetic_flags;
  }
  L004ca36b: { // 0x4ca36b: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ca36d: { // 0x4ca36d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L004ca370: { // 0x4ca370: 8b7808 MOV EDI, dword ptr [EAX + 8]
    s.di = m.r32((s.ax+8u));
  }
  L004ca373: { // 0x4ca373: a150e28400 MOV EAX, dword ptr [0x84E250]
    s.ax = m.r32((0x0084e250u));
  }
  L004ca378: { // 0x4ca378: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004ca37a: { // 0x4ca37a: 7510 JNZ 0x4CA38C
    if(integer::condition("JNZ",flags)) goto L004ca38c;
  }
  L004ca37c: { // 0x4ca37c: 3b1554e28400 CMP EDX, dword ptr [0x84E254]
    (void)integer::sub(s.dx,m.r32((0x0084e254u)),32,flags);
  }
  L004ca382: { // 0x4ca382: 7508 JNZ 0x4CA38C
    if(integer::condition("JNZ",flags)) goto L004ca38c;
  }
  L004ca384: { // 0x4ca384: 3b3d58e28400 CMP EDI, dword ptr [0x84E258]
    (void)integer::sub(s.di,m.r32((0x0084e258u)),32,flags);
  }
  L004ca38a: { // 0x4ca38a: 7416 JZ 0x4CA3A2
    if(integer::condition("JZ",flags)) goto L004ca3a2;
  }
  L004ca38c: { // 0x4ca38c: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004ca390: { // 0x4ca390: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L004ca392: { // 0x4ca392: 890e MOV dword ptr [ESI], ECX
    m.w32((s.si), s.cx);
  }
  L004ca394: { // 0x4ca394: 895604 MOV dword ptr [ESI + 4], EDX
    m.w32((s.si+4u), s.dx);
  }
  L004ca397: { // 0x4ca397: 897e08 MOV dword ptr [ESI + 8], EDI
    m.w32((s.si+8u), s.di);
  }
  L004ca39a: { // 0x4ca39a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ca39b: { // 0x4ca39b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ca39c: { // 0x4ca39c: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004ca39f: { // 0x4ca39f: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004ca3a2: { // 0x4ca3a2: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ca3a4: { // 0x4ca3a4: 8d4c240c LEA ECX, [ESP + 0xC]
    s.cx = (f.sp+0x0000000cu);
  }
  L004ca3a8: { // 0x4ca3a8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ca3a9: { // 0x4ca3a9: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ca3ab: { // 0x4ca3ab: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5022638u); flags=s.arithmetic_flags;
  }
  L004ca3ae: { // 0x4ca3ae: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004ca3b0: { // 0x4ca3b0: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004ca3b4: { // 0x4ca3b4: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004ca3b6: { // 0x4ca3b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ca3b7: { // 0x4ca3b7: 8b32 MOV ESI, dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  L004ca3b9: { // 0x4ca3b9: 8931 MOV dword ptr [ECX], ESI
    m.w32((s.cx), s.si);
  }
  L004ca3bb: { // 0x4ca3bb: 8b7204 MOV ESI, dword ptr [EDX + 4]
    s.si = m.r32((s.dx+4u));
  }
  L004ca3be: { // 0x4ca3be: 897104 MOV dword ptr [ECX + 4], ESI
    m.w32((s.cx+4u), s.si);
  }
  L004ca3c1: { // 0x4ca3c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ca3c2: { // 0x4ca3c2: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L004ca3c5: { // 0x4ca3c5: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L004ca3c8: { // 0x4ca3c8: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004ca3cb: { // 0x4ca3cb: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0013b780(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0053b780: { // 0x53b780: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L0053b784: { // 0x53b784: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0053b785: { // 0x53b785: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0053b786: { // 0x53b786: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L0053b789: { // 0x53b789: 81c188000000 ADD ECX, 0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L0053b78f: { // 0x53b78f: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0053b791: { // 0x53b791: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0053b793: { // 0x53b793: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0053b796: { // 0x53b796: 8b7008 MOV ESI, dword ptr [EAX + 8]
    s.si = m.r32((s.ax+8u));
  }
  L0053b799: { // 0x53b799: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0053b79d: { // 0x53b79d: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0053b79f: { // 0x53b79f: 890f MOV dword ptr [EDI], ECX
    m.w32((s.di), s.cx);
  }
  L0053b7a1: { // 0x53b7a1: 895704 MOV dword ptr [EDI + 4], EDX
    m.w32((s.di+4u), s.dx);
  }
  L0053b7a4: { // 0x53b7a4: 897708 MOV dword ptr [EDI + 8], ESI
    m.w32((s.di+8u), s.si);
  }
  L0053b7a7: { // 0x53b7a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0053b7a8: { // 0x53b7a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0053b7a9: { // 0x53b7a9: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000a5cd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a5cd0: { // 0x4a5cd0: 83ec14 SUB ESP, 0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L004a5cd3: { // 0x4a5cd3: 8b0d50ad8300 MOV ECX, dword ptr [0x83AD50]
    s.cx = m.r32((0x0083ad50u));
  }
  L004a5cd9: { // 0x4a5cd9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a5cda: { // 0x4a5cda: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004a5cdb: { // 0x4a5cdb: 8b7c2420 MOV EDI, dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L004a5cdf: { // 0x4a5cdf: 8b471c MOV EAX, dword ptr [EDI + 0x1C]
    s.ax = m.r32((s.di+0x0000001cu));
  }
  L004a5ce2: { // 0x4a5ce2: 8d771c LEA ESI, [EDI + 0x1C]
    s.si = (s.di+0x0000001cu);
  }
  L004a5ce5: { // 0x4a5ce5: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004a5ce7: { // 0x4a5ce7: 0f8591010000 JNZ 0x4A5E7E
    if(integer::condition("JNZ",flags)) goto L004a5e7e;
  }
  L004a5ced: { // 0x4a5ced: 8b4e04 MOV ECX, dword ptr [ESI + 4]
    s.cx = m.r32((s.si+4u));
  }
  L004a5cf0: { // 0x4a5cf0: a154ad8300 MOV EAX, dword ptr [0x83AD54]
    s.ax = m.r32((0x0083ad54u));
  }
  L004a5cf5: { // 0x4a5cf5: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004a5cf7: { // 0x4a5cf7: 0f8581010000 JNZ 0x4A5E7E
    if(integer::condition("JNZ",flags)) goto L004a5e7e;
  }
  L004a5cfd: { // 0x4a5cfd: 8b5608 MOV EDX, dword ptr [ESI + 8]
    s.dx = m.r32((s.si+8u));
  }
  L004a5d00: { // 0x4a5d00: a158ad8300 MOV EAX, dword ptr [0x83AD58]
    s.ax = m.r32((0x0083ad58u));
  }
  L004a5d05: { // 0x4a5d05: 3bd0 CMP EDX, EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004a5d07: { // 0x4a5d07: 0f8571010000 JNZ 0x4A5E7E
    if(integer::condition("JNZ",flags)) goto L004a5e7e;
  }
  L004a5d0d: { // 0x4a5d0d: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L004a5d11: { // 0x4a5d11: 8b4c2428 MOV ECX, dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L004a5d15: { // 0x4a5d15: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004a5d16: { // 0x4a5d16: 8b542430 MOV EDX, dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L004a5d1a: { // 0x4a5d1a: 8bde MOV EBX, ESI
    s.bx = s.si;
  }
  L004a5d1c: { // 0x4a5d1c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004a5d1d: { // 0x4a5d1d: 8903 MOV dword ptr [EBX], EAX
    m.w32((s.bx), s.ax);
  }
  L004a5d1f: { // 0x4a5d1f: 894b04 MOV dword ptr [EBX + 4], ECX
    m.w32((s.bx+4u), s.cx);
  }
  L004a5d22: { // 0x4a5d22: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L004a5d27: { // 0x4a5d27: 895308 MOV dword ptr [EBX + 8], EDX
    m.w32((s.bx+8u), s.dx);
  }
  L004a5d2a: { // 0x4a5d2a: e841130b00 CALL 0x557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,4873519u); flags=s.arithmetic_flags;
  }
  L004a5d2f: { // 0x4a5d2f: 894724 MOV dword ptr [EDI + 0x24], EAX
    m.w32((s.di+0x00000024u), s.ax);
  }
  L004a5d32: { // 0x4a5d32: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L004a5d34: { // 0x4a5d34: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004a5d36: { // 0x4a5d36: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004a5d3a: { // 0x4a5d3a: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L004a5d3d: { // 0x4a5d3d: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004a5d41: { // 0x4a5d41: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L004a5d44: { // 0x4a5d44: a1881b8200 MOV EAX, dword ptr [0x821B88]
    s.ax = m.r32((0x00821b88u));
  }
  L004a5d49: { // 0x4a5d49: 894c241c MOV dword ptr [ESP + 0x1C], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L004a5d4d: { // 0x4a5d4d: 0388c8040000 ADD ECX, dword ptr [EAX + 0x4C8]
    s.cx = integer::add(s.cx,m.r32((s.ax+0x000004c8u)),32,flags);
  }
  L004a5d53: { // 0x4a5d53: 894c241c MOV dword ptr [ESP + 0x1C], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L004a5d57: { // 0x4a5d57: 8b88d4040000 MOV ECX, dword ptr [EAX + 0x4D4]
    s.cx = m.r32((s.ax+0x000004d4u));
  }
  L004a5d5d: { // 0x4a5d5d: db80c8040000 FILD dword ptr [EAX + 0x4C8]
    const auto address=(s.ax+0x000004c8u);
    s.fp.load_integer32(m.r32(address));
  }
  L004a5d63: { // 0x4a5d63: 8b90d0040000 MOV EDX, dword ptr [EAX + 0x4D0]
    s.dx = m.r32((s.ax+0x000004d0u));
  }
  L004a5d69: { // 0x4a5d69: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a5d6a: { // 0x4a5d6a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a5d6b: { // 0x4a5d6b: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004a5d6f: { // 0x4a5d6f: e81c440100 CALL 0x4BA190
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba190u,4873588u); flags=s.arithmetic_flags;
  }
  L004a5d74: { // 0x4a5d74: dc7c2430 FDIVR double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    reverse_divide64(s.fp,read64(m,address));
  }
  L004a5d78: { // 0x4a5d78: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004a5d7b: { // 0x4a5d7b: da442414 FIADD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L004a5d7f: { // 0x4a5d7f: e8cc4c2c00 CALL 0x76AA50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4873604u); flags=s.arithmetic_flags;
  }
  L004a5d84: { // 0x4a5d84: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004a5d88: { // 0x4a5d88: 8d442414 LEA EAX, [ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L004a5d8c: { // 0x4a5d8c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a5d8d: { // 0x4a5d8d: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L004a5d92: { // 0x4a5d92: e849180b00 CALL 0x5575E0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005575e0u,4873623u); flags=s.arithmetic_flags;
  }
  L004a5d97: { // 0x4a5d97: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004a5d99: { // 0x4a5d99: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004a5d9a: { // 0x4a5d9a: 7540 JNZ 0x4A5DDC
    if(integer::condition("JNZ",flags)) goto L004a5ddc;
  }
  L004a5d9c: { // 0x4a5d9c: c6471801 MOV byte ptr [EDI + 0x18], 1
    m.w8((s.di+0x00000018u), 1u);
  }
  L004a5da0: { // 0x4a5da0: a1881b8200 MOV EAX, dword ptr [0x821B88]
    s.ax = m.r32((0x00821b88u));
  }
  L004a5da5: { // 0x4a5da5: db06 FILD dword ptr [ESI]
    const auto address=(s.si);
    s.fp.load_integer32(m.r32(address));
  }
  L004a5da7: { // 0x4a5da7: 8b88d4040000 MOV ECX, dword ptr [EAX + 0x4D4]
    s.cx = m.r32((s.ax+0x000004d4u));
  }
  L004a5dad: { // 0x4a5dad: 8b90d0040000 MOV EDX, dword ptr [EAX + 0x4D0]
    s.dx = m.r32((s.ax+0x000004d0u));
  }
  L004a5db3: { // 0x4a5db3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a5db4: { // 0x4a5db4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a5db5: { // 0x4a5db5: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004a5db9: { // 0x4a5db9: db80c8040000 FILD dword ptr [EAX + 0x4C8]
    const auto address=(s.ax+0x000004c8u);
    s.fp.load_integer32(m.r32(address));
  }
  L004a5dbf: { // 0x4a5dbf: dd5c242c FSTP double ptr [ESP + 0x2C]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004a5dc3: { // 0x4a5dc3: e8c8430100 CALL 0x4BA190
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba190u,4873672u); flags=s.arithmetic_flags;
  }
  L004a5dc8: { // 0x4a5dc8: dc7c242c FDIVR double ptr [ESP + 0x2C]
    const auto address=(f.sp+0x0000002cu);
    reverse_divide64(s.fp,read64(m,address));
  }
  L004a5dcc: { // 0x4a5dcc: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004a5dcf: { // 0x4a5dcf: dc6c2408 FSUBR double ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L004a5dd3: { // 0x4a5dd3: e8784c2c00 CALL 0x76AA50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4873688u); flags=s.arithmetic_flags;
  }
  L004a5dd8: { // 0x4a5dd8: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004a5ddc: { // 0x4a5ddc: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L004a5ddf: { // 0x4a5ddf: 8d542410 LEA EDX, [ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L004a5de3: { // 0x4a5de3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a5de4: { // 0x4a5de4: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004a5de6: { // 0x4a5de6: ff909c010000 CALL dword ptr [EAX + 0x19C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),4873708u); flags=s.arithmetic_flags;
  }
  L004a5dec: { // 0x4a5dec: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L004a5def: { // 0x4a5def: 8d542410 LEA EDX, [ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L004a5df3: { // 0x4a5df3: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  L004a5df8: { // 0x4a5df8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a5df9: { // 0x4a5df9: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004a5dfb: { // 0x4a5dfb: ff90d4000000 CALL dword ptr [EAX + 0xD4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000d4u)),4873729u); flags=s.arithmetic_flags;
  }
  L004a5e01: { // 0x4a5e01: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L004a5e04: { // 0x4a5e04: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004a5e06: { // 0x4a5e06: 7464 JZ 0x4A5E6C
    if(integer::condition("JZ",flags)) goto L004a5e6c;
  }
  L004a5e08: { // 0x4a5e08: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004a5e0a: { // 0x4a5e0a: 8d542410 LEA EDX, [ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L004a5e0e: { // 0x4a5e0e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004a5e0f: { // 0x4a5e0f: ff909c010000 CALL dword ptr [EAX + 0x19C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),4873749u); flags=s.arithmetic_flags;
  }
  L004a5e15: { // 0x4a5e15: 8b4f08 MOV ECX, dword ptr [EDI + 8]
    s.cx = m.r32((s.di+8u));
  }
  L004a5e18: { // 0x4a5e18: 8d442420 LEA EAX, [ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L004a5e1c: { // 0x4a5e1c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a5e1d: { // 0x4a5e1d: 81c1e0020000 ADD ECX, 0x2E0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  L004a5e23: { // 0x4a5e23: 66c74424240080 MOV word ptr [ESP + 0x24], 0x8000
    m.w16((f.sp+0x00000024u), 0x00008000u);
  }
  L004a5e2a: { // 0x4a5e2a: e851290100 CALL 0x4B8780
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8780u,4873775u); flags=s.arithmetic_flags;
  }
  L004a5e2f: { // 0x4a5e2f: 68a8010000 PUSH 0x1A8
    f.push(m,0x000001a8u);
  }
  L004a5e34: { // 0x4a5e34: e81e7b2c00 CALL 0x76D957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4873785u); flags=s.arithmetic_flags;
  }
  L004a5e39: { // 0x4a5e39: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L004a5e3c: { // 0x4a5e3c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a5e3e: { // 0x4a5e3e: 743e JZ 0x4A5E7E
    if(integer::condition("JZ",flags)) goto L004a5e7e;
  }
  L004a5e40: { // 0x4a5e40: 8b15881b8200 MOV EDX, dword ptr [0x821B88]
    s.dx = m.r32((0x00821b88u));
  }
  L004a5e46: { // 0x4a5e46: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004a5e48: { // 0x4a5e48: 6800060000 PUSH 0x600
    f.push(m,0x00000600u);
  }
  L004a5e4d: { // 0x4a5e4d: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004a5e4f: { // 0x4a5e4f: 8d4c241c LEA ECX, [ESP + 0x1C]
    s.cx = (f.sp+0x0000001cu);
  }
  L004a5e53: { // 0x4a5e53: 6a00 PUSH 0
    f.push(m,0u);
  }
  L004a5e55: { // 0x4a5e55: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a5e56: { // 0x4a5e56: 8b8ab4020000 MOV ECX, dword ptr [EDX + 0x2B4]
    s.cx = m.r32((s.dx+0x000002b4u));
  }
  L004a5e5c: { // 0x4a5e5c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004a5e5d: { // 0x4a5e5d: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004a5e5f: { // 0x4a5e5f: e8aca2f7ff CALL 0x420110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00420110u,4873828u); flags=s.arithmetic_flags;
  }
  L004a5e64: { // 0x4a5e64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004a5e65: { // 0x4a5e65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a5e66: { // 0x4a5e66: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L004a5e69: { // 0x4a5e69: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004a5e6c: { // 0x4a5e6c: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004a5e6e: { // 0x4a5e6e: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L004a5e72: { // 0x4a5e72: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  L004a5e77: { // 0x4a5e77: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004a5e78: { // 0x4a5e78: ff92d4000000 CALL dword ptr [EDX + 0xD4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000d4u)),4873854u); flags=s.arithmetic_flags;
  }
  L004a5e7e: { // 0x4a5e7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004a5e7f: { // 0x4a5e7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004a5e80: { // 0x4a5e80: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L004a5e83: { // 0x4a5e83: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_000a5e90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a5e90: { // 0x4a5e90: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L004a5e94: { // 0x4a5e94: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004a5e96: { // 0x4a5e96: 7508 JNZ 0x4A5EA0
    if(integer::condition("JNZ",flags)) goto L004a5ea0;
  }
  L004a5e98: { // 0x4a5e98: b803400080 MOV EAX, 0x80004003
    s.ax = 0x80004003u;
  }
  L004a5e9d: { // 0x4a5e9d: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004a5ea0: { // 0x4a5ea0: 8b0db0cf7800 MOV ECX, dword ptr [0x78CFB0]
    s.cx = m.r32((0x0078cfb0u));
  }
  L004a5ea6: { // 0x4a5ea6: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L004a5ea8: { // 0x4a5ea8: 8b15b4cf7800 MOV EDX, dword ptr [0x78CFB4]
    s.dx = m.r32((0x0078cfb4u));
  }
  L004a5eae: { // 0x4a5eae: 895004 MOV dword ptr [EAX + 4], EDX
    m.w32((s.ax+4u), s.dx);
  }
  L004a5eb1: { // 0x4a5eb1: 8b0db8cf7800 MOV ECX, dword ptr [0x78CFB8]
    s.cx = m.r32((0x0078cfb8u));
  }
  L004a5eb7: { // 0x4a5eb7: 894808 MOV dword ptr [EAX + 8], ECX
    m.w32((s.ax+8u), s.cx);
  }
  L004a5eba: { // 0x4a5eba: 8b15bccf7800 MOV EDX, dword ptr [0x78CFBC]
    s.dx = m.r32((0x0078cfbcu));
  }
  L004a5ec0: { // 0x4a5ec0: 89500c MOV dword ptr [EAX + 0xC], EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L004a5ec3: { // 0x4a5ec3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004a5ec5: { // 0x4a5ec5: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 if(target==m.r32(0x7851bc)||target==m.r32(0x7851c0)){
  s.ax=ra2::platform::com243::Counter::guest_call(m.r32(f.sp+4),target==m.r32(0x7851bc));finish(m,s,child,4);f.sp=child.sp;return;
 }

 switch(target){
case 5012496u:f_000c7c10(m,s,child,{});break;
case 4540528u:f_00054870(m,s,child,{});break;
case 4875216u:f_000a63d0(m,s,child,{});break;
case 4874496u:f_000a6100(m,s,child,{});break;
case 5485712u:f_0013b490(m,s,child,{});break;
case 4875056u:f_000a6330(m,s,child,{});break;
case 4875072u:f_000a6340(m,s,child,{});break;
case 5485616u:f_0013b430(m,s,child,{});break;
case 5485648u:f_0013b450(m,s,child,{});break;
case 5022448u:f_000ca2f0(m,s,child,{});break;
case 5486464u:f_0013b780(m,s,child,{});break;
case 4873424u:f_000a5cd0(m,s,child,{});break;
case 4873872u:f_000a5e90(m,s,child,{});break;
default:throw std::domain_error("recovery243 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004c8700(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004c8700: { // 0x4c8700: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004c8701: { // 0x4c8701: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004c8702: { // 0x4c8702: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004c8703: { // 0x4c8703: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004c8705: { // 0x4c8705: 8b8794040000 MOV EAX,dword ptr [EDI + 0x494]
    s.ax = m.r32((s.di+0x00000494u));
  }
  L004c870b: { // 0x4c870b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004c870d: { // 0x4c870d: 0f8598000000 JNZ 0x004c87ab
    if(integer::condition("JNZ",flags)) goto L004c87ab;
  }
  L004c8713: { // 0x4c8713: 8b87ac040000 MOV EAX,dword ptr [EDI + 0x4ac]
    s.ax = m.r32((s.di+0x000004acu));
  }
  L004c8719: { // 0x4c8719: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004c871b: { // 0x4c871b: 0f848a000000 JZ 0x004c87ab
    if(integer::condition("JZ",flags)) goto L004c87ab;
  }
  L004c8721: { // 0x4c8721: 8b87a0040000 MOV EAX,dword ptr [EDI + 0x4a0]
    s.ax = m.r32((s.di+0x000004a0u));
  }
  L004c8727: { // 0x4c8727: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L004c8729: { // 0x4c8729: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004c872b: { // 0x4c872b: 747e JZ 0x004c87ab
    if(integer::condition("JZ",flags)) goto L004c87ab;
  }
  L004c872d: { // 0x4c872d: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L004c872f: { // 0x4c872f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004c8731: { // 0x4c8731: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004c8732: { // 0x4c8732: ff9210040000 CALL dword ptr [EDX + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000410u)),5015352u); flags=s.arithmetic_flags;
  }
  L004c8738: { // 0x4c8738: 8b87ac040000 MOV EAX,dword ptr [EDI + 0x4ac]
    s.ax = m.r32((s.di+0x000004acu));
  }
  L004c873e: { // 0x4c873e: 8db79c040000 LEA ESI,[EDI + 0x49c]
    s.si = (s.di+0x0000049cu);
  }
  L004c8744: { // 0x4c8744: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004c8746: { // 0x4c8746: 7e1e JLE 0x004c8766
    if(integer::condition("JLE",flags)) goto L004c8766;
  }
  L004c8748: { // 0x4c8748: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L004c874b: { // 0x4c874b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004c874d: { // 0x4c874d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004c874f: { // 0x4c874f: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L004c8752: { // 0x4c8752: 7e12 JLE 0x004c8766
    if(integer::condition("JLE",flags)) goto L004c8766;
  }
  L004c8754: { // 0x4c8754: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L004c8757: { // 0x4c8757: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004c8758: { // 0x4c8758: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004c875b: { // 0x4c875b: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L004c875f: { // 0x4c875f: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L004c8762: { // 0x4c8762: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004c8764: { // 0x4c8764: 7cee JL 0x004c8754
    if(integer::condition("JL",flags)) goto L004c8754;
  }
  L004c8766: { // 0x4c8766: 8a879b050000 MOV AL,byte ptr [EDI + 0x59b]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000059bu)));
  }
  L004c876c: { // 0x4c876c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004c876e: { // 0x4c876e: 743b JZ 0x004c87ab
    if(integer::condition("JZ",flags)) goto L004c87ab;
  }
  L004c8770: { // 0x4c8770: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L004c8773: { // 0x4c8773: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004c8776: { // 0x4c8776: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004c8778: { // 0x4c8778: 7c22 JL 0x004c879c
    if(integer::condition("JL",flags)) goto L004c879c;
  }
  L004c877a: { // 0x4c877a: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L004c877d: { // 0x4c877d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004c877f: { // 0x4c877f: 7504 JNZ 0x004c8785
    if(integer::condition("JNZ",flags)) goto L004c8785;
  }
  L004c8781: { // 0x4c8781: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004c8783: { // 0x4c8783: 7526 JNZ 0x004c87ab
    if(integer::condition("JNZ",flags)) goto L004c87ab;
  }
  L004c8785: { // 0x4c8785: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L004c8788: { // 0x4c8788: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004c878a: { // 0x4c878a: 7e1f JLE 0x004c87ab
    if(integer::condition("JLE",flags)) goto L004c87ab;
  }
  L004c878c: { // 0x4c878c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004c878e: { // 0x4c878e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004c8790: { // 0x4c8790: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004c8792: { // 0x4c8792: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004c8793: { // 0x4c8793: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004c8795: { // 0x4c8795: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5015448u); flags=s.arithmetic_flags;
  }
  L004c8798: { // 0x4c8798: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004c879a: { // 0x4c879a: 740f JZ 0x004c87ab
    if(integer::condition("JZ",flags)) goto L004c87ab;
  }
  L004c879c: { // 0x4c879c: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004c879f: { // 0x4c879f: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L004c87a2: { // 0x4c87a2: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L004c87a5: { // 0x4c87a5: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L004c87a8: { // 0x4c87a8: 891c82 MOV dword ptr [EDX + EAX*0x4],EBX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.bx);
  }
  L004c87ab: { // 0x4c87ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004c87ac: { // 0x4c87ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004c87ad: { // 0x4c87ad: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004c87ae: { // 0x4c87ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
